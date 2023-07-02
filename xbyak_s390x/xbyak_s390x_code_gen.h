#pragma once
#include "xbyak_s390x_common.h"
#include "xbyak_s390x_code_array.h"
#include "xbyak_s390x_instr_formats.h"
#include "xbyak_s390x_operands.h"
#include "xbyak_s390x_address.h"
#include "xbyak_s390x_label.h"

namespace Xbyak_s390x {

	class CodeGenerator : public CodeArray {

#include "xbyak_s390x_instr_core.h"
#include "xbyak_s390x_label.h"
	protected:
		LabelManager labelMgr_;
	public:

		CodeGenerator(size_t maxSize = DEFAULT_MAX_CODE_SIZE, void* userPtr = 0, Allocator* allocator = 0)
			: CodeArray(maxSize, userPtr, allocator) {
			labelMgr_.set(this);
		}

		void L(Label& label) { labelMgr_.defineClabel(label); }
		Label L() { Label label; L(label); return label; }



		int encodeJmp(const Label &l, int startBit, int bitWidth) {
			size_t offset = 0;
			auto ok = labelMgr_.getOffset(l, &offset);
			if (ok) {
				int32_t encoded = JmpLabel::relativeEncoded(getSize(), offset);
				if (!local::inSignedRange(encoded, bitWidth)) {
					XBYAK_S390X_THROW_RET(ERR_LABEL_IS_TOO_FAR, 0);
				}
				return encoded;
			}
			else {
				// add to undefined list
				labelMgr_.addUndefinedLabel(l, JmpLabel(size_, startBit, bitWidth));
				return 0;
			}

		}

		void inLocalLabel() { labelMgr_.enterLocal(); }
		void outLocalLabel() { labelMgr_.leaveLocal(); }
		/*
			assign src to dst
			require
			dst : does not used by L()
			src : used by L()
		*/
		void assignL(Label& dst, const Label& src) { labelMgr_.assign(dst, src); }

		void putL(const Label& label) {  }
		void reset()
		{
			ClearError();
			resetSize();
			labelMgr_.reset();
			labelMgr_.set(this);
		}
		bool hasUndefinedLabel() const { return labelMgr_.hasUndefClabel(); }
		/*
			MUST call ready() to complete generating code if you use AutoGrow mode.
			It is not necessary for the other mode if hasUndefinedLabel() is true.
		*/
		void ready(ProtectMode mode = PROTECT_RWE)
		{
			if (hasUndefinedLabel()) XBYAK_S390X_THROW(ERR_LABEL_IS_NOT_FOUND)
				if (isAutoGrow()) {
					if (useProtect()) setProtectMode(mode);
				}
		}
		// set read/exec
		void readyRE() { return ready(PROTECT_RE); }



#include "xbyak_s390x_mnemonics.h"

	};
}