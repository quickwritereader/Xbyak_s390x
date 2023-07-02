#pragma once
#include "xbyak_s390x_common.h"

namespace Xbyak_s390x {

    inline void* AlignedMalloc(size_t size, size_t alignment)
    {
        void* p;
        int ret = posix_memalign(&p, alignment, size);
        return (ret == 0) ? p : 0;
    }

    inline void AlignedFree(void* p)
    { 
        free(p);
    }

    namespace inner {

        static const size_t ALIGN_PAGE_SIZE = 4096;
        inline bool IsInDisp8(uint32_t x) { return 0xFFFFFF80 <= x || x <= 0x7F; }
        inline bool IsInInt32(uint64_t x) { return ~uint64_t(0x7fffffffu) <= x || x <= 0x7FFFFFFFU; }

        inline uint32_t VerifyInInt32(uint64_t x)
        {
#if defined(XBYAK64) && !defined(__ILP32__)
            if (!IsInInt32(x)) XBYAK_THROW_RET(ERR_OFFSET_IS_TOO_BIG, 0)
#endif
                return static_cast<uint32_t>(x);
        }

        enum LabelMode {
            LasIs, // as is
            Labs, // absolute
            LaddTop // (addr + top) for mov(reg, label) with AutoGrow
        };

    } // inner
    /*
        custom allocator
    */
    struct Allocator {
        explicit Allocator(const std::string & = "") {} // same interface with MmapAllocator
        virtual uint8_t* alloc(size_t size) { return reinterpret_cast<uint8_t*>(AlignedMalloc(size, inner::ALIGN_PAGE_SIZE)); }
        virtual void free(uint8_t* p) { AlignedFree(p); }
        virtual ~Allocator() {}
        /* override to return false if you call protect() manually */
        virtual bool useProtect() const { return true; }
    };

#ifdef XBYAK_S390X_USE_MMAP_ALLOCATOR

    class MmapAllocator : public Allocator {
        struct Allocation {
            size_t size;
#if defined(XBYAK_S390X_USE_MEMFD)
            // fd_ is only used with XBYAK_S390X_USE_MEMFD. We keep the file open
            // during the lifetime of each allocation in order to support
            // checkpoint/restore by unprivileged users.
            int fd;
#endif
        };
        const std::string name_; // only used with XBYAK_S390X_USE_MEMFD
        using AllocationList = XBYAK_S390X_STD_UNORDERED_MAP<uintptr_t, Allocation>;
        AllocationList allocList_;
    public:
        explicit MmapAllocator(const std::string& name = "xbyak") : name_(name) {}
        uint8_t* alloc(size_t size)
        {
            const size_t alignedSizeM1 = inner::ALIGN_PAGE_SIZE - 1;
            size = (size + alignedSizeM1) & ~alignedSizeM1;
#if defined(MAP_ANONYMOUS)
            int mode = MAP_PRIVATE | MAP_ANONYMOUS;
#elif defined(MAP_ANON)
            int mode = MAP_PRIVATE | MAP_ANON;
#else
#error "not supported"
#endif
#if defined(XBYAK_S390X_USE_MAP_JIT)
            mode |= MAP_JIT;
#endif
            int fd = -1;
#if defined(XBYAK_S390X_USE_MEMFD)
            fd = memfd_create(name_.c_str(), MFD_CLOEXEC);
            if (fd != -1) {
                mode = MAP_SHARED;
                if (ftruncate(fd, size) != 0) {
                    close(fd);
                    XBYAK_S390X_THROW_RET(ERR_CANT_ALLOC, 0)
                }
            }
#endif
            void* p = mmap(NULL, size, PROT_READ | PROT_WRITE, mode, fd, 0);
            if (p == MAP_FAILED) {
                if (fd != -1) close(fd);
                XBYAK_S390X_THROW_RET(ERR_CANT_ALLOC, 0)
            }
            assert(p);
            Allocation& alloc = allocList_[(uintptr_t)p];
            alloc.size = size;
#if defined(XBYAK_S390X_USE_MEMFD)
            alloc.fd = fd;
#endif
            return (uint8_t*)p;
        }
        void free(uint8_t* p)
        {
            if (p == 0) return;
            AllocationList::iterator i = allocList_.find((uintptr_t)p);
            if (i == allocList_.end()) XBYAK_S390X_THROW(ERR_BAD_PARAMETER)
                if (munmap((void*)i->first, i->second.size) < 0) XBYAK_S390X_THROW(ERR_MUNMAP)
#if defined(XBYAK_S390X_USE_MEMFD)
                    if (i->second.fd != -1) close(i->second.fd);
#endif
            allocList_.erase(i);
        }
    };
#else
    using MmapAllocator = Allocator;
#endif

    void* const AutoGrow = (void*)1; //-V566
    void* const DontSetProtectRWE = (void*)2; //-V566

    class CodeArray {
        enum Type {
            USER_BUF = 1, // use userPtr(non alignment, non protect)
            ALLOC_BUF, // use new(alignment, protect)
            AUTO_GROW // automatically move and grow memory if necessary
        };
        CodeArray(const CodeArray& rhs);
        void operator=(const CodeArray&);
        bool isAllocType() const { return type_ == ALLOC_BUF || type_ == AUTO_GROW; }
        const Type type_;
#ifdef XBYAK_S390X_USE_MMAP_ALLOCATOR
        MmapAllocator defaultAllocator_;
#else
        Allocator defaultAllocator_;
#endif
        Allocator* alloc_;
    protected:
        size_t maxSize_;
        uint8_t* top_;
        size_t size_;

        bool useProtect() const { return alloc_->useProtect(); }
        /*
            allocate new memory and copy old data to the new area
        */
        void growMemory()
        {
            const size_t newSize = (std::max<size_t>)(DEFAULT_MAX_CODE_SIZE, maxSize_ * 2);
            uint8_t* newTop = alloc_->alloc(newSize);
            if (newTop == 0) XBYAK_S390X_THROW(ERR_CANT_ALLOC)
                for (size_t i = 0; i < size_; i++) newTop[i] = top_[i];
            alloc_->free(top_);
            top_ = newTop;
            maxSize_ = newSize;
        }

    public:
        enum ProtectMode {
            PROTECT_RW = 0, // read/write
            PROTECT_RWE = 1, // read/write/exec
            PROTECT_RE = 2 // read/exec
        };
        explicit CodeArray(size_t maxSize, void* userPtr = 0, Allocator* allocator = 0)
            : type_(userPtr == AutoGrow ? AUTO_GROW : (userPtr == 0 || userPtr == DontSetProtectRWE) ? ALLOC_BUF : USER_BUF)
            , alloc_(allocator ? allocator : (Allocator*)&defaultAllocator_)
            , maxSize_(maxSize)
            , top_(type_ == USER_BUF ? reinterpret_cast<uint8_t*>(userPtr) : alloc_->alloc((std::max<size_t>)(maxSize, 1)))
            , size_(0)
        {
            if (maxSize_ > 0 && top_ == 0) XBYAK_S390X_THROW(ERR_CANT_ALLOC)
                if ((type_ == ALLOC_BUF && userPtr != DontSetProtectRWE && useProtect()) && !setProtectMode(PROTECT_RWE, false)) {
                    alloc_->free(top_);
                    XBYAK_S390X_THROW(ERR_CANT_PROTECT)
                }
        }
        virtual ~CodeArray()
        {
            if (isAllocType()) {
                if (useProtect()) setProtectModeRW(false);
                alloc_->free(top_);
            }
        }
        bool setProtectMode(ProtectMode mode, bool throwException = true)
        {
            bool isOK = protect(top_, maxSize_, mode);
            if (isOK) return true;
            if (throwException) XBYAK_S390X_THROW_RET(ERR_CANT_PROTECT, false)
                return false;
        }
        bool setProtectModeRE(bool throwException = true) { return setProtectMode(PROTECT_RE, throwException); }
        bool setProtectModeRW(bool throwException = true) { return setProtectMode(PROTECT_RW, throwException); }
        void resetSize()
        {
            size_ = 0;
        }
        void db(int code)
        {
            if (size_ >= maxSize_) {
                if (type_ == AUTO_GROW) {
                    growMemory();
                }
                else {
                    XBYAK_S390X_THROW(ERR_CODE_IS_TOO_BIG)
                }
            }
            top_[size_++] = static_cast<uint8_t>(code);
        }
        void db(const uint8_t* code, size_t codeSize)
        {
            for (size_t i = 0; i < codeSize; i++) db(code[i]);
        }

        template<typename T>
        void appendInto(const T& data) {
            constexpr int data_size = T::sizeOf();
            if (size_ + data_size >= maxSize_) {
                if (type_ == AUTO_GROW) {
                    growMemory();
                }
                else {
                    XBYAK_S390X_THROW(ERR_CODE_IS_TOO_BIG)
                }
            }
            memcpy(&top_[size_], &data, data_size);
            size_ += data_size;
        }


        void writeInto(size_t offsetFromTop, const int32_t& data, const int countInBytes) {
            if (countInBytes > sizeof(int32_t)) {
                XBYAK_S390X_THROW(ERR_INTERNAL);
            }
            memcpy(&top_[offsetFromTop], &data, countInBytes);
        }

        const uint8_t* getCode() const { return top_; }
        template<class F>
        const F getCode() const { return reinterpret_cast<F>(top_); }
        const uint8_t* getCurr() const { return &top_[size_]; }
        template<class F>
        const F getCurr() const { return reinterpret_cast<F>(&top_[size_]); }

        size_t getSize() const { return size_; }
        void setSize(size_t size)
        {
            if (size > maxSize_) XBYAK_S390X_THROW(ERR_OFFSET_IS_TOO_BIG)
                size_ = size;
        }
        void dump() const
        {
            const uint8_t* p = getCode();
            size_t bufSize = getSize();
            size_t remain = bufSize;
            for (int i = 0; i < 4; i++) {
                size_t disp = 16;
                if (remain < 16) {
                    disp = remain;
                }
                for (size_t j = 0; j < 16; j++) {
                    if (j < disp) {
                        printf("%02X", p[i * 16 + j]);
                    }
                }
                putchar('\n');
                remain -= disp;
                if (remain == 0) {
                    break;
                }
            }
        }

        void dump_full() const {
            const uint8_t* p = getCode();
            size_t bufSize = getSize();
            int ii = 0;
            for (int ii = 0; ii < bufSize; ii++) {
                auto cc = p[ii];
                if (ii > 0 && ii % 12 == 0) {
                    putchar('\n');
                }
                printf("%02X", (unsigned int)(cc & 0xFF));
            }
        }

        bool isAutoGrow() const { return type_ == AUTO_GROW; }
        /**
            change exec permission of memory
            @param addr [in] buffer address
            @param size [in] buffer size
            @param protectMode [in] mode(RW/RWE/RE)
            @return true(success), false(failure)
        */
        static inline bool protect(const void* addr, size_t size, int protectMode)
        {

            const int c_rw = PROT_READ | PROT_WRITE;
            const int c_rwe = PROT_READ | PROT_WRITE | PROT_EXEC;
            const int c_re = PROT_READ | PROT_EXEC;
            int mode;

            switch (protectMode) {
            case PROTECT_RW: mode = c_rw; break;
            case PROTECT_RWE: mode = c_rwe; break;
            case PROTECT_RE: mode = c_re; break;
            default:
                return false;
            }
#if defined(__GNUC__)
                size_t pageSize = sysconf(_SC_PAGESIZE);
            size_t iaddr = reinterpret_cast<size_t>(addr);
            size_t roundAddr = iaddr & ~(pageSize - static_cast<size_t>(1));
#ifndef NDEBUG
            if (pageSize != 4096) fprintf(stderr, "large page(%zd) is used. not tested enough.\n", pageSize);
#endif
            return mprotect(reinterpret_cast<void*>(roundAddr), size + (iaddr - roundAddr), mode) == 0;
#else
return true;
#endif
        }
        /**
            get aligned memory pointer
            @param addr [in] address
            @param alignedSize [in] power of two
            @return aligned addr by alingedSize
        */
        static inline uint8_t* getAlignedAddress(uint8_t* addr, size_t alignedSize = 16)
        {
            return reinterpret_cast<uint8_t*>((reinterpret_cast<size_t>(addr) + alignedSize - 1) & ~(alignedSize - static_cast<size_t>(1)));
        }
    };

}
