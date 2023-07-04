#pragma once
#include "xbyak_s390x_common.h"
#include "xbyak_s390x_operands.h"

namespace Xbyak_s390x {

    class AddrDB {

    public:
        XBYAK_S390X_CONSTEXPR AddrDB() :disp(0), regb(GPReg(0)) {}
        XBYAK_S390X_CONSTEXPR AddrDB(const int32_t& dispArg) :disp(dispArg), regb(GPReg(0)) {}
        XBYAK_S390X_CONSTEXPR AddrDB(const int32_t& dispArg, const GPReg& baseReg) :disp(dispArg), regb(baseReg) {}

        int32_t disp;
        GPReg regb;

        XBYAK_S390X_CONSTEXPR AddrDB operator-() const { return AddrDB(-disp, regb); }

    };

    class AddrDXB {
 
    public:
        XBYAK_S390X_CONSTEXPR AddrDXB() :disp(0), regx(0), regb(0) {}
        XBYAK_S390X_CONSTEXPR AddrDXB(const int32_t& dispArg, const GPReg& indexReg, const GPReg& baseReg) :disp(dispArg), regx(indexReg), regb(baseReg) {}
        XBYAK_S390X_CONSTEXPR AddrDXB(const int32_t& dispArg, const GPReg& baseReg) : disp(dispArg), regb(baseReg) {}
        XBYAK_S390X_CONSTEXPR explicit AddrDXB(const int32_t& dispArg) :disp(dispArg) {}
        XBYAK_S390X_CONSTEXPR AddrDXB(const AddrDB& dbAddr) : disp(dbAddr.disp),regb(dbAddr.regb) {}

        int32_t disp;
        GPReg regx;
        GPReg regb;

        XBYAK_S390X_CONSTEXPR AddrDXB operator-() const { return AddrDXB(-disp, regx, regb); }

    };

    XBYAK_S390X_CONSTEXPR uint32_t length_set(uint32_t l) {
        return l > 0u ? l - 1 : 0u;
    }

    class AddrDLB {

    public:
        XBYAK_S390X_CONSTEXPR AddrDLB(const int32_t& dispArg, const uint32_t& length, const GPReg& baseReg = GPReg{}) :disp(dispArg), l(length_set(length)), regb(baseReg) {}

        int32_t disp;
        uint32_t l;
        GPReg regb; 

        XBYAK_S390X_CONSTEXPR AddrDLB operator-() const { return AddrDLB(-disp, l, regb); }

    };



    using AddrDRB = AddrDXB;
    class AddrDVB {
    public:
        XBYAK_S390X_CONSTEXPR AddrDVB(const int32_t& dispArg, const VReg& indexVreg, const GPReg& baseReg) :disp(dispArg), regv(indexVreg), regb(baseReg) {}
        XBYAK_S390X_CONSTEXPR AddrDVB(const int32_t& dispArg, const GPReg& baseReg) : disp(dispArg), regb(baseReg) {}
        XBYAK_S390X_CONSTEXPR explicit AddrDVB(const int32_t& dispArg) :disp(dispArg) {}
        XBYAK_S390X_CONSTEXPR explicit AddrDVB(const AddrDB& dbAddr) :disp(dbAddr.disp), regb(dbAddr.regb) {}

        int32_t disp;
        VReg regv;
        GPReg regb;

        XBYAK_S390X_CONSTEXPR AddrDVB operator-() const { return AddrDVB(-disp, regv, regb); }
    };

    class Disp {
    public:

        XBYAK_S390X_CONSTEXPR explicit Disp(const int32_t& disp) :d(disp) {}

        XBYAK_S390X_CONSTEXPR AddrDXB operator ()(const GPReg& Xn, const GPReg& Bn) {
            return AddrDXB(d, Xn, Bn);
        }

        XBYAK_S390X_CONSTEXPR AddrDVB operator ()(const VReg& Vn, const GPReg& Bn) {
            return AddrDVB(d, Vn, Bn);
        }

        XBYAK_S390X_CONSTEXPR AddrDB operator ()(const GPReg& Bn) {
            return AddrDB(d, Bn);
        }

        XBYAK_S390X_CONSTEXPR AddrDLB operator ()(uint32_t length) const {
            return AddrDLB(d, length);
        }

        Disp& operator +=(const int32_t& r) {
            d += r;
            return *this;
        }

        Disp& operator -=(const int32_t& r) {
            d -= r;
            return *this;
        }

        Disp& operator &=(const int32_t& r) {
            d &= r;
            return *this;
        }

        Disp& operator |=(const int32_t& r) {
            d |= r;
            return *this;
        }

    private:
        int32_t d;

    };

    XBYAK_S390X_CONSTEXPR inline Disp operator""_dp(unsigned long long int displacement) {
        return Disp{ static_cast<int32_t>(displacement) };
    }

}


/*
AddrDB
AddrDLB

*/
