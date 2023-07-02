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

	printf("\n%s\n", "-------------------");

	const char branch_[] = "\xb3\xc1\x00\x2b\xb3\xc1\x00\x0f\xe3\xf0\xff\x50\xff\x71\xe3\x00\xf0\xa8\x00\x20\xb9\x04\x00\xbf\xb9\x04\x00\x12\x50\x10\xb0\xa4\xe5\x4c\xb0\xac\x00\x00\xa7\xf4\x00\x0b\x58\x10\xb0\xa4\x5a\x10\xb0\xac\x50\x10\xb0\xa4\xeb\x01\xb0\xac\x00\x6a\x58\x10\xb0\xac\xa7\x1e\x00\x03\xa7\xc4\xff\xf3\x58\x10\xb0\xa4\xb9\x14\x00\x11\xb9\x04\x00\x21\xb3\xcd\x00\xf0\xb3\xcd\x00\xb2\x07\xfe\x07\x07";
	local_dump(branch_);
	printf("\n%s\n", "-------------------");
	Code_Branch branch;
	branch.dump_full();

	printf("\n");
	return 0;
}
