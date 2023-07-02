#pragma once
#include "xbyak_s390x_common.h"
#include "xbyak_s390x_code_array.h"
#include "xbyak_s390x_instr_formats.h"

namespace Xbyak_s390x {

	struct JmpLabel {
		size_t offset;
		int offsetBit;
		int encodeBitWidth;
		explicit JmpLabel(size_t startOfJmp, int offsetInBits, int encodeSizeInBits = 16)
			: offset(startOfJmp), offsetBit(offsetInBits), encodeBitWidth(encodeSizeInBits)
		{
		}

		static inline int relativeEncoded(size_t jmpOffset, size_t labelOffset) {
			return int(labelOffset - jmpOffset) >> 1;
		}

		void update(CodeArray* base, size_t lblOffset) {
			int32_t encoded = relativeEncoded(offset, lblOffset);
			if (local::inSignedRange(encoded, encodeBitWidth)) {
				//startbit 
				auto bytes = offsetBit / 8;
				if ((offsetBit % 8) == 0 && (offsetBit % 8) == 0) {

					//to avoid bit check and also assuming our encoded is always in 32 bit, so we have to shift it , then swap to make it par with big endian 32bit
					//the other option is swapping based on bit width check
					encoded = XBYAK_S390X_BIGENDIAN_32(encoded << (32 - encodeBitWidth));
					base->writeInto(offset + bytes, encoded, bytes);
				}
				else {
					//error should not happen for ibmz
					XBYAK_S390X_THROW(ERR_INTERNAL);
				}

			}
		}
	};

	class LabelManager;

	class Label {
		mutable LabelManager* mgr;
		mutable int id;
		friend class LabelManager;
	public:
		Label() : mgr(nullptr), id(0) {}
		Label(const Label& rhs);
		Label& operator=(const Label& rhs);
		~Label();
		void clear() { mgr = nullptr; id = 0; }
		int getId() const { return id; }
		const uint8_t* getAddress() const;
	};

	class LabelManager {
		// for Label class
		struct ClabelVal {
			ClabelVal(const size_t off = 0) : offset(off), refCount(1) {}
			const size_t offset;
			int refCount;
		};
		typedef XBYAK_S390X_STD_UNORDERED_MAP<int, ClabelVal> ClabelDefList;
		typedef XBYAK_S390X_STD_UNORDERED_MULTIMAP<int, JmpLabel> ClabelUndefList;
		typedef XBYAK_S390X_STD_UNORDERED_SET<Label*> LabelPtrList;

		CodeArray* base_;
		mutable int labelId_;
		ClabelDefList clabelDefList_;
		ClabelUndefList clabelUndefList_;
		LabelPtrList labelPtrList_;

		int getId(const Label& label) const
		{
			if (label.id == 0) label.id = labelId_++;
			return label.id;
		}
		void define_inner(ClabelDefList& defList, ClabelUndefList& undefList, int labelId, const size_t offset)
		{
			// add label
			ClabelDefList::value_type item(labelId, offset);
			std::pair<ClabelDefList::iterator, bool> ret = defList.insert(item);
			if (!ret.second) XBYAK_S390X_THROW(ERR_LABEL_IS_REDEFINED)
				// search undefined label
				for (;;) {
					ClabelUndefList::iterator itr = undefList.find(labelId);
					if (itr == undefList.end()) break;
					JmpLabel& jmp = itr->second;
					jmp.update(base_, offset);
					undefList.erase(itr);
				}
		}
		friend class Label;
		void incRefCount(int id, Label* label)
		{
			clabelDefList_[id].refCount++;
			labelPtrList_.insert(label);
		}
		void decRefCount(int id, Label* label)
		{
			labelPtrList_.erase(label);
			ClabelDefList::iterator i = clabelDefList_.find(id);
			if (i == clabelDefList_.end()) return;
			if (i->second.refCount == 1) {
				clabelDefList_.erase(id);
			}
			else {
				--i->second.refCount;
			}
		}
		template<class T>
		bool hasUndefinedLabel_inner(const T& list) const
		{
			return !list.empty();
		}
		// detach all labels linked to LabelManager
		void resetLabelPtrList()
		{
			for (LabelPtrList::iterator i = labelPtrList_.begin(), ie = labelPtrList_.end(); i != ie; ++i) {
				(*i)->clear();
			}
			labelPtrList_.clear();
		}
	public:
		LabelManager()
		{
			reset();
		}
		~LabelManager()
		{
			resetLabelPtrList();
		}
		void reset()
		{
			base_ = 0;
			labelId_ = 1;
			clabelDefList_.clear();
			clabelUndefList_.clear();
			resetLabelPtrList();
		}
		void set(CodeArray* base) { base_ = base; }
		void defineClabel(Label& label)
		{
			define_inner(clabelDefList_, clabelUndefList_, getId(label), base_->getSize());
			label.mgr = this;
			labelPtrList_.insert(&label);
		}
		void assign(Label& dst, const Label& src)
		{
			ClabelDefList::const_iterator i = clabelDefList_.find(src.id);
			if (i == clabelDefList_.end()) XBYAK_S390X_THROW(ERR_LABEL_ISNOT_SET_BY_L)
				define_inner(clabelDefList_, clabelUndefList_, dst.id, i->second.offset);
			dst.mgr = this;
			labelPtrList_.insert(&dst);
		}

		const bool getOffset(const Label& label, size_t* offset) const
		{
			auto i = clabelDefList_.find(getId(label));
			if (i == clabelDefList_.end()) return false;
			*offset = i->second.offset;
			return true;
		}

		void addUndefinedLabel(const Label& label, const JmpLabel& jmp)
		{
			clabelUndefList_.insert(ClabelUndefList::value_type(label.id, jmp));
		}
		bool hasUndefClabel() const { return hasUndefinedLabel_inner(clabelUndefList_); }
		const uint8_t* getCode() const { return base_->getCode(); }

		void enterLocal() {}
		void leaveLocal() {}


	};

	inline Label::Label(const Label& rhs)
	{
		id = rhs.id;
		mgr = rhs.mgr;
		if (mgr) mgr->incRefCount(id, this);
	}
	inline Label& Label::operator=(const Label& rhs)
	{
		if (id) XBYAK_S390X_THROW_RET(ERR_LABEL_IS_ALREADY_SET_BY_L, *this)
			id = rhs.id;
		mgr = rhs.mgr;
		if (mgr) mgr->incRefCount(id, this);
		return *this;
	}
	inline Label::~Label()
	{
		if (id && mgr) mgr->decRefCount(id, this);
	}


}
