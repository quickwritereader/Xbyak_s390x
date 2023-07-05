#pragma once

#include <bitset>
#include <cstdint> 
#include <sys/auxv.h>

namespace Xbyak_s390x
{

#if __s390x__ 

class FacilityInfo {

public:
	static constexpr int ZARCHY = 1;  // z architecture mode is active
	static constexpr int STFLEF = 2;  // store-facility-list-extended
	static constexpr int LDISP = 3; // long-displacement
	static constexpr int EIMM = 4; // extended-immediate

	// miscellaneous facilities
	static constexpr int DFP = 5; // decimal-floating-point
	static constexpr int ETF3EH = 6; // extended-translation 3 enhancement

	// cryptography facilities
	static constexpr int MSA = 7;  // message-security-assist
	// static constexpr int MSA3 = 8;  // message-security-assist extension 3
	// static constexpr int MSA4 = 9;  // message-security-assist extension 4
	// static constexpr int MSA5 = 10;  // message-security-assist extension 5
	// static constexpr int MSA8 = 11; // message-security-assist extension 8
	// static constexpr int MSA9 = 12; // message-security-assist extension 9

	// vector facilities
    static constexpr int VX = 13;
	static constexpr int VXE = 14; // vector-enhancements 1
    static constexpr int VXE2 = 15;

    FacilityInfo(){
        init();
    }


    bool has(int Facility){
        return internal_flags.test(Facility);
    }


    private:
    std::bitset<64> internal_flags;

    void init(){ 
        auxCall(); 
    }

    void auxCall(){
        auto hwcaps = getauxval(AT_HWCAP);
        auto check = [hwcaps]( uint32_t mask){
		         return hwcaps & mask == mask;
	    };
        internal_flags.set(ZARCHY, check(HWCAP_S390_ZARCH));
        internal_flags.set(STFLEF, check(HWCAP_S390_STFLE));
        internal_flags.set(LDISP, check(HWCAP_S390_LDISP));
        internal_flags.set(EIMM, check(HWCAP_S390_EIMM));
        internal_flags.set(DFP, check(HWCAP_S390_DFP));
        internal_flags.set(ETF3EH, check(HWCAP_S390_ETF3EH));
        internal_flags.set(MSA, check(HWCAP_S390_MSA));
        internal_flags.set(VX, check(HWCAP_S390_VX));
        internal_flags.set(VXE, check(HWCAP_S390_VXE));
        internal_flags.set(VXE2, check(HWCAP_S390_VXRS_EXT2));
    }

};

#endif 

}
