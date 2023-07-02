#pragma once

#if !defined(XBYAK_S390X_USE_MMAP_ALLOCATOR) && !defined(XBYAK_S390X_DONT_USE_MMAP_ALLOCATOR)
#define XBYAK_S390X_USE_MMAP_ALLOCATOR
#endif

#ifdef __GNUC__
#define XBYAK_S390X_GNUC_PREREQ(major, minor) ((__GNUC__)*100 + (__GNUC_MINOR__) >= (major)*100 + (minor))
#else
#define XBYAK_S390X_GNUC_PREREQ(major, minor) 0
#endif

// This covers -std=(gnu|c)++(0x|11|1y), -stdlib=libc++
#if XBYAK_S390X_GNUC_PREREQ(4, 5) || (XBYAK_S390X_GNUC_PREREQ(4, 2) && __GLIBCXX__ >= 20070719) || defined(__llvm__)
#include <tr1/unordered_set>
#define XBYAK_S390X_STD_UNORDERED_SET std::tr1::unordered_set
#include <tr1/unordered_map>
#define XBYAK_S390X_STD_UNORDERED_MAP std::tr1::unordered_map
#define XBYAK_S390X_STD_UNORDERED_MULTIMAP std::tr1::unordered_multimap

#else
#include <set>
#define XBYAK_S390X_STD_UNORDERED_SET std::set
#include <map>
#define XBYAK_S390X_STD_UNORDERED_MAP std::map
#define XBYAK_S390X_STD_UNORDERED_MULTIMAP std::multimap
#endif

#if defined(__GNUC__)
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#define XBYAK_S390X_TLS __thread
#endif

#include <cassert>
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <list>
#include <string>

// MFD_CLOEXEC defined only linux 3.17 or later.
// Android wraps the memfd_create syscall from API version 30.
#if !defined(MFD_CLOEXEC)
#undef XBYAK_S390X_USE_MEMFD
#endif

#if (__cplusplus >= 201103)
#undef XBYAK_S390X_TLS
#define XBYAK_S390X_TLS thread_local
#define XBYAK_S390X_VARIADIC_TEMPLATE
#define XBYAK_S390X_NOEXCEPT noexcept
#else
#define XBYAK_S390X_NOEXCEPT throw()
#endif

// require c++14 or later
// g++-6 or later
#if ((__cplusplus >= 201402L) && !(!defined(__clang__) && defined(__GNUC__) && (__GNUC__ <= 5)))
#define XBYAK_S390X_CONSTEXPR constexpr
#else
#define XBYAK_S390X_CONSTEXPR
#endif

#ifdef NDEBUG
#define XBYAK_S390X_ASSERT(x)
#else
#define XBYAK_S390X_ASSERT(x) assert(x)
#endif

// disable -Warray-bounds because it may be a bug of gcc. https://gcc.gnu.org/bugzilla/show_bug.cgi?id=104603
#if defined(__GNUC__) && !defined(__clang__)
#define XBYAK_S390X_DISABLE_WARNING_ARRAY_BOUNDS
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
#endif

#define XBYAK_S390X_NO_OP_NAMES 1

namespace Xbyak_s390x
{

    enum
    {
        DEFAULT_MAX_CODE_SIZE = 4096,
        VERSION = 0x6691 /* 0xABCD = A.BC(.D) */
    };

    enum
    {
        ERR_NONE = 0,
        ERR_BAD_PARAMETER,
        ERR_CANT_ALLOC,
        ERR_CANT_PROTECT,
        ERR_CODE_IS_TOO_BIG,
        ERR_LABEL_IS_ALREADY_SET_BY_L,
        ERR_LABEL_IS_NOT_FOUND,
        ERR_LABEL_IS_REDEFINED,
        ERR_LABEL_IS_TOO_FAR,
        ERR_LABEL_ISNOT_SET_BY_L,
        ERR_MUNMAP,
        ERR_OFFSET_IS_TOO_BIG,
        ERR_INTERNAL
    };

    inline const char *ConvertErrorToString(int err)
    {
        static const char *errTbl[] = {
            "none",
            "bad parameter",
            "can't alloc",
            "can't protect",
            "code is too big",
            "label is already set by L()",
            "label is not found",
            "label is redefined",
            "label is too far",
            "label is not set by L()",
            "err munmap",
            "offset is too big",
            "internal error"
            };
        assert(ERR_INTERNAL + 1 == sizeof(errTbl) / sizeof(*errTbl));
        return err <= ERR_INTERNAL ? errTbl[err] : "unknown err";
    }

#ifdef XBYAK_S390X_NO_EXCEPTION
    namespace local
    {

        inline int &GetErrorRef()
        {
            static XBYAK_S390X_TLS int err = 0;
            return err;
        }

        inline void SetError(int err)
        {
            if (local::GetErrorRef())
                return; // keep the first err code
            local::GetErrorRef() = err;
        }

    } // local

    inline void ClearError()
    {
        local::GetErrorRef() = 0;
    }
    inline int GetError()
    {
        return Xbyak_s390x::local::GetErrorRef();
    }

#define XBYAK_S390X_THROW(err)             \
    {                                      \
        Xbyak_s390x::local::SetError(err); \
        return;                            \
    }
#define XBYAK_S390X_THROW_RET(err, r)      \
    {                                      \
        Xbyak_s390x::local::SetError(err); \
        return r;                          \
    }

#else
    class Error : public std::exception
    {
        int err_;

    public:
        explicit Error(int err) : err_(err)
        {
            if (err_ < 0 || err_ > ERR_INTERNAL)
            {
                err_ = ERR_INTERNAL;
            }
        }
        operator int() const { return err_; }
        const char *what() const XBYAK_S390X_NOEXCEPT
        {
            return ConvertErrorToString(err_);
        }
    };

    // dummy functions
    inline void ClearError() {}
    inline int GetError() { return 0; }

    inline const char *ConvertErrorToString(const Error &err)
    {
        return err.what();
    }

#define XBYAK_S390X_THROW(err) \
    {                          \
        throw Error(err);      \
    }
#define XBYAK_S390X_THROW_RET(err, r) \
    {                                 \
        throw Error(err);             \
    }

#endif

    namespace local
    {

        inline XBYAK_S390X_CONSTEXPR uint32_t mask(size_t n)
        {
            XBYAK_S390X_ASSERT(n <= 32);
            return n == 32 ? 0xffffffff : (1u << n) - 1;
        }
        // is x <= mask(n) ?
        template <typename Type>
        inline XBYAK_S390X_CONSTEXPR bool inBit(Type x, size_t n)
        {
            return x <= mask(n);
        }

        template <typename Type>
        inline XBYAK_S390X_CONSTEXPR bool inSignedRange(Type x, size_t bitWidth)
        {
            auto t = 2 << (bitWidth - 1);
            return x >= -t && x < t; // the same as z <= t - 1;
        }

        template <typename Type>
        inline XBYAK_S390X_CONSTEXPR uint32_t shift_right_mask(Type numb, size_t n, size_t m)
        {
            return (numb >> n) & mask(m);
        }

        template <typename Type>
        inline XBYAK_S390X_CONSTEXPR uint32_t mask(Type numb, size_t n)
        {
            return numb & mask(n);
        }

        inline XBYAK_S390X_CONSTEXPR uint32_t mask_rxb(int v1, int v2, int v3, int v4 = 0)
        {
            return (v1 >> 1) || (v2 >> 2) || (v3 >> 2) || (v4 >> 2);
        }

        inline XBYAK_S390X_CONSTEXPR uint32_t mask_rxb(int v1, int v2)
        {
            return (v1 >> 1) || (v2 >> 2);
        }

        inline XBYAK_S390X_CONSTEXPR uint32_t mask_rxb(int v1)
        {
            return (v1 >> 1);
        }

    };

}
