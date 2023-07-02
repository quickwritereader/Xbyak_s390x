#pragma once
#include "xbyak_s390x_common.h"

namespace Xbyak_s390x
{

	class Operand
	{
	public:
		enum Kind
		{
			RN = 1,		 // General purpose register N 0..15
			FN = 1 << 1, // Floating-point register N 0..15
			AN = 1 << 2, // Access register N 0..15
			CN = 1 << 3, // Control register N 0..15
			VRN = 1 << 6 // Vector registers N 0..31 , 0..15 overlapped with FN
		};

	public:
		XBYAK_S390X_CONSTEXPR Operand() : idx_(0), kind_(RN)
		{
		}
		XBYAK_S390X_CONSTEXPR Operand(uint32_t idx, Kind kind) : idx_(idx), kind_(kind)
		{
			XBYAK_S390X_ASSERT(local::inBit(idx, kind_ == VRN ? 5 : 4));
		}
		// uint32_t getBit() const { return bit_; }
		XBYAK_S390X_CONSTEXPR bool isGPR() const { return is(RN); }
		XBYAK_S390X_CONSTEXPR bool isFPR() const { return is(FN); }
		XBYAK_S390X_CONSTEXPR bool isVEC() const { return is(VRN); }
		XBYAK_S390X_CONSTEXPR bool isAR() const { return is(AN); }
		XBYAK_S390X_CONSTEXPR bool isCR() const { return is(CN); }

		constexpr int getIdx() const { return idx_; }
		const char *toString() const
		{
			if (kind_ == RN)
			{
				static const char *tbl[] = {
					"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",
					"r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
				};
				return tbl[idx_];
			}
			else if (kind_ == FN)
			{
				static const char *tbl[] = {
					"f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7",
					"f8", "f9", "f10", "f11", "f12", "f13", "f14", "f15"};
				return tbl[idx_];
			}
			if (kind_ == AN)
			{
				static const char *tbl[] = {
					"a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7",
					"a8", "a9", "a10", "a11", "a12", "a13", "a14", "a15"
				};
				return tbl[idx_];
			}
			else if (kind_ == CN)
			{
				static const char *tbl[] = {
					"c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7",
					"c8", "c9", "c10", "c11", "c12", "c13", "c14", "c15"
				};
				return tbl[idx_];
			}
			else if (kind_ == VRN)
			{
				static const char *tbl[] = {
					"v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7",
					"v8", "v9", "v10", "v11", "v12", "v13", "v14", "v15",
					"v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23",
					"v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31"
				};
				return tbl[idx_];
			}
			XBYAK_S390X_THROW_RET(ERR_INTERNAL, 0);
		}
		bool operator==(const Operand &rhs) const
		{
			return idx_ == rhs.idx_ && kind_ == rhs.kind_;
		}
		bool operator!=(const Operand &rhs) const { return !operator==(rhs); }

	private:
		XBYAK_S390X_CONSTEXPR bool is(Kind kind) const { return (kind_ == kind); }
		uint32_t idx_;
		Kind kind_;
	};

	struct GPReg : public Operand
	{
		XBYAK_S390X_CONSTEXPR GPReg() : Operand(0, Operand::Kind::RN) {}
		explicit XBYAK_S390X_CONSTEXPR GPReg(int idx, Kind kind = Operand::Kind::RN) : Operand(idx, kind) {}
	};
	struct FReg : public Operand
	{
		explicit XBYAK_S390X_CONSTEXPR FReg(int idx = 0, Kind kind = Operand::Kind::FN) : Operand(idx, kind) {}
	};
	struct VReg : public Operand
	{
		explicit XBYAK_S390X_CONSTEXPR VReg(int idx = 0, Kind kind = Operand::Kind::VRN) : Operand(idx, kind) {}
	};
	struct AReg : public Operand
	{
		explicit XBYAK_S390X_CONSTEXPR AReg(int idx = 0, Kind kind = Operand::Kind::AN) : Operand(idx, kind) {}
	};
	struct CReg : public Operand
	{
		explicit XBYAK_S390X_CONSTEXPR CReg(int idx = 0, Kind kind = Operand::Kind::CN) : Operand(idx, kind) {}
	};

	static XBYAK_S390X_CONSTEXPR GPReg r0(0), r1(1), r2(2), r3(3), r4(4), r5(5), r6(6), r7(7);
	static XBYAK_S390X_CONSTEXPR GPReg r8(8), r9(9), r10(10), r11(11), r12(12), r13(13), r14(14), r15(15);
	static XBYAK_S390X_CONSTEXPR GPReg lit(13), sp(15);
	static XBYAK_S390X_CONSTEXPR FReg f0(0), f1(1), f2(2), f3(3), f4(4), f5(5), f6(6), f7(7);
	static XBYAK_S390X_CONSTEXPR FReg f8(8), f9(9), f10(10), f11(11), f12(12), f13(13), f14(14), f15(15);
	static XBYAK_S390X_CONSTEXPR AReg a0(0), a1(1), a2(2), a3(3), a4(4), a5(5), a6(6), a7(7);
	static XBYAK_S390X_CONSTEXPR AReg a8(8), a9(9), a10(10), a11(11), a12(12), a13(13), a14(14), a15(15);
	static XBYAK_S390X_CONSTEXPR CReg c0(0), c1(1), c2(2), c3(3), c4(4), c5(5), c6(6), c7(7);
	static XBYAK_S390X_CONSTEXPR CReg c8(8), c9(9), c10(10), c11(11), c12(12), c13(13), c14(14), c15(15);
	static XBYAK_S390X_CONSTEXPR VReg v0(0), v1(1), v2(2), v3(3), v4(4), v5(5), v6(6), v7(7);
	static XBYAK_S390X_CONSTEXPR VReg v8(8), v9(9), v10(10), v11(11), v12(12), v13(13), v14(14), v15(15);
	static XBYAK_S390X_CONSTEXPR VReg v16(16), v17(17), v18(18), v19(19), v20(20), v21(21), v22(22), v23(23);
	static XBYAK_S390X_CONSTEXPR VReg v24(24), v25(25), v26(26), v27(27), v28(28), v29(29), v30(30), v31(31);

}