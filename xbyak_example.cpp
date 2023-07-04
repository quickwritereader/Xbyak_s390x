#include <xbyak.h>
#include <iostream>
#include <iomanip>
using namespace std;
using namespace Xbyak_s390x;

typedef int (*calc)(int);

struct Code : public Xbyak_s390x::CodeGenerator
{
	Code()
	{
		// ldgr% f2, % r11
		//	ldgr% f0, % r15
		//	lay% r15, 168(% r15)
		//	cg % r0, 160(% r15)
		//	lgr % r11, % r15
		//	lgr% r1, % r2
		//	st% r1, 164(% r11)
		//	l % r1, 164(% r11)
		//	ahi % r1, 5
		//	lgfr % r1, % r1
		//	lgr% r2, % r1
		//	lgdr% r15, % f0
		//	lgdr% r11, % f2
		//	br% r14
		//	nopr% r7
		//	nopr% r7
		//	nopr% r7
		ldgr(f2, r11);
		ldgr(f0, r15);
		lay(r15, -168_dp(r15));
		cg(r0, 160_dp(r15));
		lgr(r11, r15);
		lgr(r1, r2);
		st(r1, 164_dp(r11));
		l(r1, 164_dp(r11));
		ahi(r1, 5);
		lgfr(r1, r1);
		lgr(r2, r1);
		lgdr(r15, f0);
		lgdr(r11, f2);
		br(r14);
		nopr(r7);
		nopr(r7);
	}
};

struct Code_Branch : public Xbyak_s390x::CodeGenerator
{
	Code_Branch()
	{
		// ldgr	%f2,%r11
		// ldgr	%f0,%r15
		// lay	%r15,-176(%r15)
		// cg	%r0,168(%r15)
		// lgr	%r11,%r15
		// lgr	%r1,%r2
		// st	%r1,164(%r11)
		// mvhi	172(%r11),0
		// j	3c <(int)+0x3c>
		// l	%r1,164(%r11)
		// a	%r1,172(%r11)
		// st	%r1,164(%r11)
		// asi	172(%r11),1
		// l	%r1,172(%r11)
		// chi	%r1,3
		// jle	2a <(int)+0x2a>
		// l	%r1,164(%r11)
		// lgfr	%r1,%r1
		// lgr	%r2,%r1
		// lgdr	%r15,%f0
		// lgdr	%r11,%f2
		// br	%r14
		// nopr	%r7
		Xbyak_s390x::Label lbl_loop, label_jmp;
		ldgr(f2, r11);
		ldgr(f0, r15);
		lay(r15, -176_dp(r15));
		cg(r0, 168_dp(r15));
		lgr(r11, r15);
		lgr(r1, r2);
		st(r1, 164_dp(r11));
		mvhi(172_dp(r11), 0);
		// j(3c <(int) + 0x3c>);
		// junk

		brc(15, label_jmp);
		L(lbl_loop);
		l(r1, 164_dp(r11));
		a(r1, 172_dp(r11));
		st(r1, 164_dp(r11));
		asi(172_dp(r11), 1);
		L(label_jmp);
		l(r1, 172_dp(r11));
		chi(r1, 3);
		brc(12, lbl_loop);
		l(r1, 164_dp(r11));
		lgfr(r1, r1);
		lgr(r2, r1);
		lgdr(r15, f0);
		lgdr(r11, f2);
		// br(r14);
		// nopr(r7);
		br(r14);
		nopr(r7);
	}
};


struct SDOT_KERNEL_32 : public Xbyak_s390x::CodeGenerator{

	SDOT_KERNEL_32(){
 
		Xbyak_s390x::Label lbl_loop;
        // float sdot_kernel_32_dp(int, float*, float*)
        stmg (r6,r15,48_dp(r15));
		lgr (r1,r15);
		lay (r15,-232_dp(r15));
		aghi (r1,-8);
		std (f8,0_dp(r1));
		lgr (r11,r15);
		stg (r3,184_dp(r11));
		stg (r4,176_dp(r11));
		st (r2,196_dp(r11));
		l (r2,196_dp(r11));
		lgfr (r3,r2);
		aghi (r3,-1);
		stg (r3,208_dp(r11));
		lgfr (r2,r2);
		lgr (r9,r2);
		lghi (r8,0);
		srlg (r2,r9,59);
		sllg (r3,r8,5);
		stg (r3,160_dp(r11));
		og (r2,160_dp(r11));
		stg (r2,160_dp(r11));
		sllg (r2,r9,5);
		stg (r2,168_dp(r11));
		l (r2,196_dp(r11));
		lgfr (r3,r2);
		aghi (r3,-1);
		stg (r3,216_dp(r11));
		lgfr (r2,r2);
		lgr (r1,r2);
		lghi (r0,0);
		srlg (r2,r1,59);
		sllg (r6,r0,5);
		ogr (r6,r2);
		sllg (r7,r1,5);
		lg (r3,184_dp(r11));
		lg (r4,184_dp(r11));
		lg (r5,176_dp(r11));
		lg (r10,176_dp(r11));
		l (r1,196_dp(r11));
		lr (r2,r1);
        vzero (v0);
        vzero (v1);
        vzero (v2);
        vzero (v3);
        vzero (v4);
        vzero (v5);
        vzero (v6);
        vzero (v7);
        srlg (r2, r2, 5_dp(r0));
        xgr (r1, r1);
        L(lbl_loop);
        pfd (1,1024_dp( r1, r4));
        pfd (1,1024_dp( r1, r10));
        vl (v16,0_dp( r1, r4));
        vl (v17,16_dp( r1, r4));
        vl (v18,32_dp( r1, r4));
        vl (v19,48_dp( r1, r4));
        vl (v20,64_dp( r1, r4));
        vl (v21,80_dp( r1, r4));
        vl (v22,96_dp( r1, r4));
        vl (v23,112_dp( r1, r4));
        vl (v24,0_dp( r1, r10));
        vl (v25,16_dp( r1, r10));
        vl (v26,32_dp( r1, r10));
        vl (v27,48_dp( r1, r10));
        vl (v28,64_dp( r1, r10));
        vl (v29,80_dp( r1, r10));
        vl (v30,96_dp( r1, r10));
        vl (v31,112_dp( r1, r10));
        vfmasb (v0, v16, v24, v0);
        vfmasb (v1, v17, v25, v1);
        vfmasb (v2, v18, v26, v2);
        vfmasb (v3, v19, v27, v3);
        vfmasb (v4, v20, v28, v4);
        vfmasb (v5, v21, v29, v5);
        vfmasb (v6, v22, v30, v6);
        vfmasb (v7, v23, v31, v7);
        agfi (r1,128);
        brctg (r2, lbl_loop);
        vfasb (v0, v0, v1);
        vfasb (v0, v0, v2);
        vfasb (v0, v0, v3);
        vfasb (v0, v0, v4);
        vfasb (v0, v0, v5);
        vfasb (v0, v0, v6);
        vfasb (v0, v0, v7);
        vrepf (v1, v0,1);
        vrepf (v2, v0,2);
        vrepf (v3, v0,3);
        aebr (f0, f1);
        aebr (f0, f2);
        aebr (f0, f3);
        ler (f8, f0);
        ste (f8,204_dp( r11));
        st (r2,196_dp( r11));
        l (r1,204_dp( r11));
        vlvgf (v0, r1, 0);
        ld (f8,224_dp( r11));
        lmg (r6, r15,280_dp( r11));
        br (r14);
	}

};
template <typename T, int N>
void local_dump(const T (&arr)[N])
{
	int ii = 0;
	for (auto &cc : arr)
	{
		if (ii > 0 && ii % 12 == 0)
		{
			printf("%s\n", "");
		}
		printf("%02X", (unsigned int)(cc & 0xFF));
		++ii;
	}
}

int main()
{
	/*
	int num5(int num) {
	return num + 5;
    }
	*/
	const char num5[] = "\xb3\xc1\x00\x2b\xb3\xc1\x00\x0f\xe3\xf0\xff\x58\xff\x71\xe3\x00\xf0\xa0\x00\x20\xb9\x04\x00\xbf\xb9\x04\x00\x12\x50\x10\xb0\xa4\x58\x10\xb0\xa4\xa7\x1a\x00\x05\xb9\x14\x00\x11\xb9\x04\x00\x21\xb3\xcd\x00\xf0\xb3\xcd\x00\xb2\x07\xfe\x07\x07\x07\x07";
	CodeArray c(4096);
	local_dump(num5);

	printf("\n%s\n", "-------------------");
	Code hh;
	hh.dump_full();

#if __s390__
	calc h = (calc)hh.getCode();
	int resh = h(88);
	cout << "hello hhh. " << (int)resh << endl;
#endif

	printf("\n%s\n", "--------Code_Branch-----------");

	const char branch_[] = "\xb3\xc1\x00\x2b\xb3\xc1\x00\x0f\xe3\xf0\xff\x50\xff\x71\xe3\x00\xf0\xa8\x00\x20\xb9\x04\x00\xbf\xb9\x04\x00\x12\x50\x10\xb0\xa4\xe5\x4c\xb0\xac\x00\x00\xa7\xf4\x00\x0b\x58\x10\xb0\xa4\x5a\x10\xb0\xac\x50\x10\xb0\xa4\xeb\x01\xb0\xac\x00\x6a\x58\x10\xb0\xac\xa7\x1e\x00\x03\xa7\xc4\xff\xf3\x58\x10\xb0\xa4\xb9\x14\x00\x11\xb9\x04\x00\x21\xb3\xcd\x00\xf0\xb3\xcd\x00\xb2\x07\xfe\x07\x07";
	local_dump(branch_);
	printf("\n%s\n", "---------Code_Branch----------");
	Code_Branch branch;
	branch.dump_full();

	printf("\n%s\n", "--------SDOT-----------");
	const char sdot_bin[]="\xeb\x6f\xf0\x30\x00\x24\xb9\x04\x00\x1f\xe3\xf0\xff\x18\xff\x71\xa7\x1b\xff\xf8\x60\x80\x10\x00\xb9\x04\x00\xbf\xe3\x30\xb0\xb8\x00\x24\xe3\x40\xb0\xb0\x00\x24\x50\x20\xb0\xc4\x58\x20\xb0\xc4\xb9\x14\x00\x32\xa7\x3b\xff\xff\xe3\x30\xb0\xd0\x00\x24\xb9\x14\x00\x22\xb9\x04\x00\x92\xa7\x89\x00\x00\xeb\x29\x00\x3b\x00\x0c\xeb\x38\x00\x05\x00\x0d\xe3\x30\xb0\xa0\x00\x24\xe3\x20\xb0\xa0\x00\x81\xe3\x20\xb0\xa0\x00\x24\xeb\x29\x00\x05\x00\x0d\xe3\x20\xb0\xa8\x00\x24\x58\x20\xb0\xc4\xb9\x14\x00\x32\xa7\x3b\xff\xff\xe3\x30\xb0\xd8\x00\x24\xb9\x14\x00\x22\xb9\x04\x00\x12\xa7\x09\x00\x00\xeb\x21\x00\x3b\x00\x0c\xeb\x60\x00\x05\x00\x0d\xb9\x81\x00\x62\xeb\x71\x00\x05\x00\x0d\xe3\x30\xb0\xb8\x00\x04\xe3\x40\xb0\xb8\x00\x04\xe3\x50\xb0\xb0\x00\x04\xe3\xa0\xb0\xb0\x00\x04\x58\x10\xb0\xc4\x18\x21\xe7\x00\x00\x00\x00\x44\xe7\x10\x00\x00\x00\x44\xe7\x20\x00\x00\x00\x44\xe7\x30\x00\x00\x00\x44\xe7\x40\x00\x00\x00\x44\xe7\x50\x00\x00\x00\x44\xe7\x60\x00\x00\x00\x44\xe7\x70\x00\x00\x00\x44\xeb\x22\x00\x05\x00\x0c\xb9\x82\x00\x11\xe3\x11\x44\x00\x00\x36\xe3\x11\xa4\x00\x00\x36\xe7\x01\x40\x00\x08\x06\xe7\x11\x40\x10\x08\x06\xe7\x21\x40\x20\x08\x06\xe7\x31\x40\x30\x08\x06\xe7\x41\x40\x40\x08\x06\xe7\x51\x40\x50\x08\x06\xe7\x61\x40\x60\x08\x06\xe7\x71\x40\x70\x08\x06\xe7\x81\xa0\x00\x08\x06\xe7\x91\xa0\x10\x08\x06\xe7\xa1\xa0\x20\x08\x06\xe7\xb1\xa0\x30\x08\x06\xe7\xc1\xa0\x40\x08\x06\xe7\xd1\xa0\x50\x08\x06\xe7\xe1\xa0\x60\x08\x06\xe7\xf1\xa0\x70\x08\x06\xe7\x00\x82\x00\x06\x8f\xe7\x11\x92\x00\x16\x8f\xe7\x22\xa2\x00\x26\x8f\xe7\x33\xb2\x00\x36\x8f\xe7\x44\xc2\x00\x46\x8f\xe7\x55\xd2\x00\x56\x8f\xe7\x66\xe2\x00\x66\x8f\xe7\x77\xf2\x00\x76\x8f\xc2\x18\x00\x00\x00\x80\xa7\x27\xff\xaf\xe7\x00\x10\x00\x20\xe3\xe7\x00\x20\x00\x20\xe3\xe7\x00\x30\x00\x20\xe3\xe7\x00\x40\x00\x20\xe3\xe7\x00\x50\x00\x20\xe3\xe7\x00\x60\x00\x20\xe3\xe7\x00\x70\x00\x20\xe3\xe7\x10\x00\x01\x20\x4d\xe7\x20\x00\x02\x20\x4d\xe7\x30\x00\x03\x20\x4d\xb3\x0a\x00\x01\xb3\x0a\x00\x02\xb3\x0a\x00\x03\x38\x80\x70\x80\xb0\xcc\x50\x20\xb0\xc4\x58\x10\xb0\xcc\xe7\x01\x00\x00\x20\x22\x68\x80\xb0\xe0\xeb\x6f\xb1\x18\x00\x04\x07\xfe";
    local_dump(sdot_bin);
	printf("\n%s\n", "--------SDOT-----------");
	SDOT_KERNEL_32 sdot;

	sdot.dump_full();
	printf("\n");
	return 0;
}
