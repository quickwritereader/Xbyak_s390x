void adr(const FReg& r1, const FReg& r2 ){ opRR(0x2A, r1, r2); }
void aer(const FReg& r1, const FReg& r2 ){ opRR(0x3A, r1, r2); }
void alr(const GPReg& r1, const GPReg& r2 ){ opRR(0x1E, r1, r2); }
void ar(const GPReg& r1, const GPReg& r2 ){ opRR(0x1A, r1, r2); }
void aur(const FReg& r1, const FReg& r2 ){ opRR(0x3E, r1, r2); }
void awr(const FReg& r1, const FReg& r2 ){ opRR(0x2E, r1, r2); }
void axr(const FReg& r1, const FReg& r2 ){ opRR(0x36, r1, r2); }
void balr(const GPReg& r1, const GPReg& r2 ){ opRR(0x05, r1, r2); }
void basr(const GPReg& r1, const GPReg& r2 ){ opRR(0x0D, r1, r2); }
void bassm(const GPReg& r1, const GPReg& r2 ){ opRR(0x0C, r1, r2); }
void bctr(const GPReg& r1, const GPReg& r2 ){ opRR(0x06, r1, r2); }
void bsm(const GPReg& r1, const GPReg& r2 ){ opRR(0x0B, r1, r2); }
void cdr(const FReg& r1, const FReg& r2 ){ opRR(0x29, r1, r2); }
void cer(const FReg& r1, const FReg& r2 ){ opRR(0x39, r1, r2); }
void clcl(const GPReg& r1, const GPReg& r2 ){ opRR(0x0F, r1, r2); }
void clr(const GPReg& r1, const GPReg& r2 ){ opRR(0x15, r1, r2); }
void cr(const GPReg& r1, const GPReg& r2 ){ opRR(0x19, r1, r2); }
void ddr(const FReg& r1, const FReg& r2 ){ opRR(0x2D, r1, r2); }
void der(const FReg& r1, const FReg& r2 ){ opRR(0x3D, r1, r2); }
void dr(const GPReg& r1, const GPReg& r2 ){ opRR(0x1D, r1, r2); }
void hdr(const FReg& r1, const FReg& r2 ){ opRR(0x24, r1, r2); }
void her(const FReg& r1, const FReg& r2 ){ opRR(0x34, r1, r2); }
void lcdr(const FReg& r1, const FReg& r2 ){ opRR(0x23, r1, r2); }
void lcer(const FReg& r1, const FReg& r2 ){ opRR(0x33, r1, r2); }
void lcr(const GPReg& r1, const GPReg& r2 ){ opRR(0x13, r1, r2); }
void ldr(const FReg& r1, const FReg& r2 ){ opRR(0x28, r1, r2); }
void ldxr(const FReg& r1, const FReg& r2 ){ opRR(0x25, r1, r2); }
void ledr(const FReg& r1, const FReg& r2 ){ opRR(0x35, r1, r2); }
void ler(const FReg& r1, const FReg& r2 ){ opRR(0x38, r1, r2); }
void lndr(const FReg& r1, const FReg& r2 ){ opRR(0x21, r1, r2); }
void lner(const FReg& r1, const FReg& r2 ){ opRR(0x31, r1, r2); }
void lnr(const GPReg& r1, const GPReg& r2 ){ opRR(0x11, r1, r2); }
void lpdr(const FReg& r1, const FReg& r2 ){ opRR(0x20, r1, r2); }
void lper(const FReg& r1, const FReg& r2 ){ opRR(0x30, r1, r2); }
void lpr(const GPReg& r1, const GPReg& r2 ){ opRR(0x10, r1, r2); }
void lr(const GPReg& r1, const GPReg& r2 ){ opRR(0x18, r1, r2); }
void lrdr(const FReg& r1, const FReg& r2 ){ opRR(0x25, r1, r2); }
void lrer(const FReg& r1, const FReg& r2 ){ opRR(0x35, r1, r2); }
void ltdr(const FReg& r1, const FReg& r2 ){ opRR(0x22, r1, r2); }
void lter(const FReg& r1, const FReg& r2 ){ opRR(0x32, r1, r2); }
void ltr(const GPReg& r1, const GPReg& r2 ){ opRR(0x12, r1, r2); }
void mder(const FReg& r1, const FReg& r2 ){ opRR(0x3C, r1, r2); }
void mdr(const FReg& r1, const FReg& r2 ){ opRR(0x2C, r1, r2); }
void mer(const FReg& r1, const FReg& r2 ){ opRR(0x3C, r1, r2); }
void mr(const GPReg& r1, const GPReg& r2 ){ opRR(0x1C, r1, r2); }
void mvcl(const GPReg& r1, const GPReg& r2 ){ opRR(0x0E, r1, r2); }
void mxdr(const FReg& r1, const FReg& r2 ){ opRR(0x27, r1, r2); }
void mxr(const FReg& r1, const FReg& r2 ){ opRR(0x26, r1, r2); }
void nr(const GPReg& r1, const GPReg& r2 ){ opRR(0x14, r1, r2); }
#if !defined(XBYAK_S390X_NO_OP_NAMES)
 or(const GPReg& r1, const GPReg& r2 ){ opRR(0x16, r1, r2); }
#endif
void or_(const GPReg& r1, const GPReg& r2 ){ opRR(0x16, r1, r2); }
void sdr(const FReg& r1, const FReg& r2 ){ opRR(0x2B, r1, r2); }
void ser(const FReg& r1, const FReg& r2 ){ opRR(0x3B, r1, r2); }
void slr(const GPReg& r1, const GPReg& r2 ){ opRR(0x1F, r1, r2); }
void sr(const GPReg& r1, const GPReg& r2 ){ opRR(0x1B, r1, r2); }
void sur(const FReg& r1, const FReg& r2 ){ opRR(0x3F, r1, r2); }
void swr(const FReg& r1, const FReg& r2 ){ opRR(0x2F, r1, r2); }
void sxr(const FReg& r1, const FReg& r2 ){ opRR(0x37, r1, r2); }
void xr(const GPReg& r1, const GPReg& r2 ){ opRR(0x17, r1, r2); }
void bcr(const int& m1, const GPReg& r2 ){ opRR(0x07, m1, r2); }
void spm(const GPReg& r1 ){ opRR(0x04, r1); }
void adbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB31A, r1, r2); }
void aebr(const FReg& r1, const FReg& r2 ){ opRRE(0xB30A, r1, r2); }
void agfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB918, r1, r2); }
void agr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB908, r1, r2); }
void alcgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB988, r1, r2); }
void alcr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB998, r1, r2); }
void algfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB91A, r1, r2); }
void algr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB90A, r1, r2); }
void axbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB34A, r1, r2); }
void bakr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB240, r1, r2); }
void bctgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB946, r1, r2); }
void bsa(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB25A, r1, r2); }
void bsg(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB258, r1, r2); }
void cdbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB319, r1, r2); }
void cdfbr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB395, r1, r2); }
void cdfr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3B5, r1, r2); }
void cdgbr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3A5, r1, r2); }
void cdgr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3C5, r1, r2); }
void cdgtr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3F1, r1, r2); }
void cdstr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3F3, r1, r2); }
void cdtr(const FReg& r1, const FReg& r2 ){ opRRE(0xB3E4, r1, r2); }
void cdutr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3F2, r1, r2); }
void cebr(const FReg& r1, const FReg& r2 ){ opRRE(0xB309, r1, r2); }
void cedtr(const FReg& r1, const FReg& r2 ){ opRRE(0xB3F4, r1, r2); }
void cefbr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB394, r1, r2); }
void cefr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3B4, r1, r2); }
void cegbr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3A4, r1, r2); }
void cegr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3C4, r1, r2); }
void cextr(const FReg& r1, const FReg& r2 ){ opRRE(0xB3FC, r1, r2); }
void cgfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB930, r1, r2); }
void cgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB920, r1, r2); }
void chhr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB9CD, r1, r2); }
void chlr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB9DD, r1, r2); }
void cksm(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB241, r1, r2); }
void clgfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB931, r1, r2); }
void clgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB921, r1, r2); }
void clhhr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB9CF, r1, r2); }
void clhlr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB9DF, r1, r2); }
void clst(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB25D, r1, r2); }
void cmpsc(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB263, r1, r2); }
void cpya(const AReg& r1, const AReg& r2 ){ opRRE(0xB24D, r1, r2); }
void csp(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB250, r1, r2); }
void cspg(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB98A, r1, r2); }
void cu41(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB9B2, r1, r2); }
void cu42(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB9B3, r1, r2); }
void cudtr(const FReg& r1, const FReg& r2 ){ opRRE(0xB3E2, r1, r2); }
void cuse(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB257, r1, r2); }
void cuxtr(const FReg& r1, const FReg& r2 ){ opRRE(0xB3EA, r1, r2); }
void cxbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB349, r1, r2); }
void cxfbr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB396, r1, r2); }
void cxfr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3B6, r1, r2); }
void cxgbr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3A6, r1, r2); }
void cxgr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3C6, r1, r2); }
void cxgtr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3F9, r1, r2); }
void cxr(const FReg& r1, const FReg& r2 ){ opRRE(0xB369, r1, r2); }
void cxstr(const FReg& r1, const FReg& r2 ){ opRRE(0xB3FB, r1, r2); }
void cxtr(const FReg& r1, const FReg& r2 ){ opRRE(0xB3EC, r1, r2); }
void cxutr(const FReg& r1, const FReg& r2 ){ opRRE(0xB3FA, r1, r2); }
void ddbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB31D, r1, r2); }
void debr(const FReg& r1, const FReg& r2 ){ opRRE(0xB30D, r1, r2); }
void dlgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB987, r1, r2); }
void dlr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB997, r1, r2); }
void dsgfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB91D, r1, r2); }
void dsgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB90D, r1, r2); }
void dxbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB34D, r1, r2); }
void dxr(const FReg& r1, const FReg& r2 ){ opRRE(0xB22D, r1, r2); }
void ear(const GPReg& r1, const AReg& r2 ){ opRRE(0xB24F, r1, r2); }
void eedtr(const GPReg& r1, const FReg& r2 ){ opRRE(0xB3E5, r1, r2); }
void eextr(const FReg& r1, const FReg& r2 ){ opRRE(0xB3ED, r1, r2); }
void epsw(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB98D, r1, r2); }
void ereg(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB249, r1, r2); }
void eregg(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB90E, r1, r2); }
void esdtr(const GPReg& r1, const FReg& r2 ){ opRRE(0xB3E7, r1, r2); }
void esta(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB24A, r1, r2); }
void esxtr(const GPReg& r1, const FReg& r2 ){ opRRE(0xB3EF, r1, r2); }
void fidr(const FReg& r1, const FReg& r2 ){ opRRE(0xB37F, r1, r2); }
void fier(const FReg& r1, const FReg& r2 ){ opRRE(0xB377, r1, r2); }
void fixr(const FReg& r1, const FReg& r2 ){ opRRE(0xB367, r1, r2); }
void flogr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB983, r1, r2); }
void irbm(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB9AC, r1, r2); }
void iske(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB229, r1, r2); }
void ivsk(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB223, r1, r2); }
void kdbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB318, r1, r2); }
void kdsa(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB93A, r1, r2); }
void kdtr(const FReg& r1, const FReg& r2 ){ opRRE(0xB3E0, r1, r2); }
void kebr(const FReg& r1, const FReg& r2 ){ opRRE(0xB308, r1, r2); }
void kimd(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB93E, r1, r2); }
void klmd(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB93F, r1, r2); }
void km(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB92E, r1, r2); }
void kmac(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB91E, r1, r2); }
void kmc(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB92F, r1, r2); }
void kmf(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB92A, r1, r2); }
void kmo(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB92B, r1, r2); }
void kxbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB348, r1, r2); }
void kxtr(const FReg& r1, const FReg& r2 ){ opRRE(0xB3E8, r1, r2); }
void lbr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB926, r1, r2); }
void lcdbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB313, r1, r2); }
void lcdfr(const FReg& r1, const FReg& r2 ){ opRRE(0xB373, r1, r2); }
void lcebr(const FReg& r1, const FReg& r2 ){ opRRE(0xB303, r1, r2); }
void lcgfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB913, r1, r2); }
void lcgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB903, r1, r2); }
void lcxbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB343, r1, r2); }
void lcxr(const FReg& r1, const FReg& r2 ){ opRRE(0xB363, r1, r2); }
void ldebr(const FReg& r1, const FReg& r2 ){ opRRE(0xB304, r1, r2); }
void lder(const FReg& r1, const FReg& r2 ){ opRRE(0xB324, r1, r2); }
void ldgr(const FReg& r1, const GPReg& r2 ){ opRRE(0xB3C1, r1, r2); }
void ldxbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB345, r1, r2); }
void ledbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB344, r1, r2); }
void lexbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB346, r1, r2); }
void lexr(const FReg& r1, const FReg& r2 ){ opRRE(0xB366, r1, r2); }
void lgbr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB906, r1, r2); }
void lgdr(const GPReg& r1, const FReg& r2 ){ opRRE(0xB3CD, r1, r2); }
void lgfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB914, r1, r2); }
void lghr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB907, r1, r2); }
void lgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB904, r1, r2); }
void lhr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB927, r1, r2); }
void llcr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB994, r1, r2); }
void llgcr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB984, r1, r2); }
void llgfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB916, r1, r2); }
void llghr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB985, r1, r2); }
void llgtr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB917, r1, r2); }
void llhr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB995, r1, r2); }
void lndbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB311, r1, r2); }
void lndfr(const FReg& r1, const FReg& r2 ){ opRRE(0xB371, r1, r2); }
void lnebr(const FReg& r1, const FReg& r2 ){ opRRE(0xB301, r1, r2); }
void lngfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB911, r1, r2); }
void lngr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB901, r1, r2); }
void lnxbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB341, r1, r2); }
void lnxr(const FReg& r1, const FReg& r2 ){ opRRE(0xB361, r1, r2); }
void lpdbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB310, r1, r2); }
void lpdfr(const FReg& r1, const FReg& r2 ){ opRRE(0xB370, r1, r2); }
void lpebr(const FReg& r1, const FReg& r2 ){ opRRE(0xB300, r1, r2); }
void lpgfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB910, r1, r2); }
void lpgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB900, r1, r2); }
void lpxbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB340, r1, r2); }
void lpxr(const FReg& r1, const FReg& r2 ){ opRRE(0xB360, r1, r2); }
void lrvgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB90F, r1, r2); }
void lrvr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB91F, r1, r2); }
void ltdbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB312, r1, r2); }
void ltdtr(const FReg& r1, const FReg& r2 ){ opRRE(0xB3D6, r1, r2); }
void ltebr(const FReg& r1, const FReg& r2 ){ opRRE(0xB302, r1, r2); }
void ltgfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB912, r1, r2); }
void ltgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB902, r1, r2); }
void ltxbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB342, r1, r2); }
void ltxr(const FReg& r1, const FReg& r2 ){ opRRE(0xB362, r1, r2); }
void ltxtr(const FReg& r1, const FReg& r2 ){ opRRE(0xB3DE, r1, r2); }
void lura(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB24B, r1, r2); }
void lurag(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB905, r1, r2); }
void lxdbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB305, r1, r2); }
void lxdr(const FReg& r1, const FReg& r2 ){ opRRE(0xB325, r1, r2); }
void lxebr(const FReg& r1, const FReg& r2 ){ opRRE(0xB306, r1, r2); }
void lxer(const FReg& r1, const FReg& r2 ){ opRRE(0xB326, r1, r2); }
void lxr(const FReg& r1, const FReg& r2 ){ opRRE(0xB365, r1, r2); }
void mdbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB31C, r1, r2); }
void mdebr(const FReg& r1, const FReg& r2 ){ opRRE(0xB30C, r1, r2); }
void meebr(const FReg& r1, const FReg& r2 ){ opRRE(0xB317, r1, r2); }
void meer(const FReg& r1, const FReg& r2 ){ opRRE(0xB337, r1, r2); }
void mlgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB986, r1, r2); }
void mlr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB996, r1, r2); }
void msgfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB91C, r1, r2); }
void msgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB90C, r1, r2); }
void msr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB252, r1, r2); }
void mvpg(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB254, r1, r2); }
void mvst(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB255, r1, r2); }
void mxbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB34C, r1, r2); }
void mxdbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB307, r1, r2); }
void ngr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB980, r1, r2); }
void ogr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB981, r1, r2); }
void pfmf(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB9AF, r1, r2); }
void pgin(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB22E, r1, r2); }
void pgout(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB22F, r1, r2); }
void prno(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB93C, r1, r2); }
void pt(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB228, r1, r2); }
void pti(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB99E, r1, r2); }
void rrbe(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB22A, r1, r2); }
void rrbm(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB9AE, r1, r2); }
void sar(const AReg& r1, const GPReg& r2 ){ opRRE(0xB24E, r1, r2); }
void sdbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB31B, r1, r2); }
void sebr(const FReg& r1, const FReg& r2 ){ opRRE(0xB30B, r1, r2); }
void sgfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB919, r1, r2); }
void sgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB909, r1, r2); }
void slbgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB989, r1, r2); }
void slbr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB999, r1, r2); }
void slgfr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB91B, r1, r2); }
void slgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB90B, r1, r2); }
void sqdbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB315, r1, r2); }
void sqdr(const FReg& r1, const FReg& r2 ){ opRRE(0xB244, r1, r2); }
void sqebr(const FReg& r1, const FReg& r2 ){ opRRE(0xB314, r1, r2); }
void sqer(const FReg& r1, const FReg& r2 ){ opRRE(0xB245, r1, r2); }
void sqxbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB316, r1, r2); }
void sqxr(const FReg& r1, const FReg& r2 ){ opRRE(0xB336, r1, r2); }
void srst(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB25E, r1, r2); }
void srstu(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB9BE, r1, r2); }
void stura(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB246, r1, r2); }
void sturg(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB925, r1, r2); }
void sxbr(const FReg& r1, const FReg& r2 ){ opRRE(0xB34B, r1, r2); }
void tar(const AReg& r1, const GPReg& r2 ){ opRRE(0xB24C, r1, r2); }
void tb(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB22C, r1, r2); }
void thder(const FReg& r1, const FReg& r2 ){ opRRE(0xB358, r1, r2); }
void thdr(const FReg& r1, const FReg& r2 ){ opRRE(0xB359, r1, r2); }
void tpei(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB9A1, r1, r2); }
void tre(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB2A5, r1, r2); }
void xgr(const GPReg& r1, const GPReg& r2 ){ opRRE(0xB982, r1, r2); }
void efpc(const GPReg& r1 ){ opRRE(0xB38C, r1); }
void epair(const GPReg& r1 ){ opRRE(0xB99A, r1); }
void epar(const GPReg& r1 ){ opRRE(0xB226, r1); }
void esair(const GPReg& r1 ){ opRRE(0xB99B, r1); }
void esar(const GPReg& r1 ){ opRRE(0xB227, r1); }
void esea(const GPReg& r1 ){ opRRE(0xB99D, r1); }
void etnd(const GPReg& r1 ){ opRRE(0xB2EC, r1); }
void iac(const GPReg& r1 ){ opRRE(0xB224, r1); }
void ipm(const GPReg& r1 ){ opRRE(0xB222, r1); }
void lzdr(const FReg& r1 ){ opRRE(0xB375, r1); }
void lzer(const FReg& r1 ){ opRRE(0xB374, r1); }
void lzxr(const FReg& r1 ){ opRRE(0xB376, r1); }
void msta(const GPReg& r1 ){ opRRE(0xB247, r1); }
void ptf(const GPReg& r1 ){ opRRE(0xB9A2, r1); }
void sfasr(const GPReg& r1 ){ opRRE(0xB385, r1); }
void sfpc(const GPReg& r1 ){ opRRE(0xB384, r1); }
void ssair(const GPReg& r1 ){ opRRE(0xB99F, r1); }
void ssar(const GPReg& r1 ){ opRRE(0xB225, r1); }
void palb( ){ opRRE(0xB248); }
void pcc( ){ opRRE(0xB92C); }
void pckmo( ){ opRRE(0xB928); }
void adtr(const FReg& r1, const FReg& r2, const FReg& r3 ){ opRRF_A(0xB3D2, r1, r2, r3); }
void agrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9E8, r1, r2, r3); }
void ahhhr(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9C8, r1, r2, r3); }
void ahhlr(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9D8, r1, r2, r3); }
void algrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9EA, r1, r2, r3); }
void alhhhr(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9CA, r1, r2, r3); }
void alhhlr(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9DA, r1, r2, r3); }
void alrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9FA, r1, r2, r3); }
void ark(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9F8, r1, r2, r3); }
void axtr(const FReg& r1, const FReg& r2, const FReg& r3 ){ opRRF_A(0xB3DA, r1, r2, r3); }
void ddtr(const FReg& r1, const FReg& r2, const FReg& r3 ){ opRRF_A(0xB3D1, r1, r2, r3); }
void dfltcc(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB939, r1, r2, r3); }
void dxtr(const FReg& r1, const FReg& r2, const FReg& r3 ){ opRRF_A(0xB3D9, r1, r2, r3); }
void mdtr(const FReg& r1, const FReg& r2, const FReg& r3 ){ opRRF_A(0xB3D0, r1, r2, r3); }
void mgrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9EC, r1, r2, r3); }
void msgrkc(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9ED, r1, r2, r3); }
void msrkc(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9FD, r1, r2, r3); }
void mxtr(const FReg& r1, const FReg& r2, const FReg& r3 ){ opRRF_A(0xB3D8, r1, r2, r3); }
void ncgrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9E5, r1, r2, r3); }
void ncrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9F5, r1, r2, r3); }
void ngrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9E4, r1, r2, r3); }
void nngrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB964, r1, r2, r3); }
void nnrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB974, r1, r2, r3); }
void nogrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB966, r1, r2, r3); }
void nork(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB976, r1, r2, r3); }
void nrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9F4, r1, r2, r3); }
void nxgrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB967, r1, r2, r3); }
void nxrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB977, r1, r2, r3); }
void ocgrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB965, r1, r2, r3); }
void ocrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB975, r1, r2, r3); }
void ogrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9E6, r1, r2, r3); }
void ork(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9F6, r1, r2, r3); }
void sdtr(const FReg& r1, const FReg& r2, const FReg& r3 ){ opRRF_A(0xB3D3, r1, r2, r3); }
void sgrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9E9, r1, r2, r3); }
void shhhr(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9C9, r1, r2, r3); }
void shhlr(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9D9, r1, r2, r3); }
void slgrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9EB, r1, r2, r3); }
void slhhhr(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9CB, r1, r2, r3); }
void slhhlr(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9DB, r1, r2, r3); }
void slrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9FB, r1, r2, r3); }
void srk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9F9, r1, r2, r3); }
void sxtr(const FReg& r1, const FReg& r2, const FReg& r3 ){ opRRF_A(0xB3DB, r1, r2, r3); }
void xgrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9E7, r1, r2, r3); }
void xrk(const GPReg& r1, const GPReg& r2, const GPReg& r3 ){ opRRF_A(0xB9F7, r1, r2, r3); }
void adtra(const FReg& r1, const FReg& r2, const FReg& r3, const int& m4 ){ opRRF_A(0xB3D2, r1, r2, r3, m4); }
void axtra(const FReg& r1, const FReg& r2, const FReg& r3, const int& m4 ){ opRRF_A(0xB3DA, r1, r2, r3, m4); }
void ddtra(const FReg& r1, const FReg& r2, const FReg& r3, const int& m4 ){ opRRF_A(0xB3D1, r1, r2, r3, m4); }
void dxtra(const FReg& r1, const FReg& r2, const FReg& r3, const int& m4 ){ opRRF_A(0xB3D9, r1, r2, r3, m4); }
void mdtra(const FReg& r1, const FReg& r2, const FReg& r3, const int& m4 ){ opRRF_A(0xB3D0, r1, r2, r3, m4); }
void mxtra(const FReg& r1, const FReg& r2, const FReg& r3, const int& m4 ){ opRRF_A(0xB3D8, r1, r2, r3, m4); }
void sdtra(const FReg& r1, const FReg& r2, const FReg& r3, const int& m4 ){ opRRF_A(0xB3D3, r1, r2, r3, m4); }
void selfhr(const GPReg& r1, const GPReg& r2, const GPReg& r3, const int& m4 ){ opRRF_A(0xB9C0, r1, r2, r3, m4); }
void selgr(const GPReg& r1, const GPReg& r2, const GPReg& r3, const int& m4 ){ opRRF_A(0xB9E3, r1, r2, r3, m4); }
void selr(const GPReg& r1, const GPReg& r2, const GPReg& r3, const int& m4 ){ opRRF_A(0xB9F0, r1, r2, r3, m4); }
void sxtra(const FReg& r1, const FReg& r2, const FReg& r3, const int& m4 ){ opRRF_A(0xB3DB, r1, r2, r3, m4); }
void ipte(const GPReg& r1, const GPReg& r2, const GPReg& r3= {} , const int& m4= {}  ){ opRRF_A(0xB221, r1, r2, r3, m4); }
void a(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x5A, r1, dxb2); }
void ad(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x6A, r1, dxb2); }
void ae(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x7A, r1, dxb2); }
void ah(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x4A, r1, dxb2); }
void al(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x5E, r1, dxb2); }
void au(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x7E, r1, dxb2); }
void aw(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x6E, r1, dxb2); }
void bal(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x45, r1, dxb2); }
void bas(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x4D, r1, dxb2); }
void bct(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x46, r1, dxb2); }
void c(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x59, r1, dxb2); }
void cd(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x69, r1, dxb2); }
void ce(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x79, r1, dxb2); }
void ch(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x49, r1, dxb2); }
void cl(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x55, r1, dxb2); }
void cvb(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x4F, r1, dxb2); }
void cvd(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x4E, r1, dxb2); }
void d(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x5D, r1, dxb2); }
void dd(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x6D, r1, dxb2); }
void de(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x7D, r1, dxb2); }
void ex(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x44, r1, dxb2); }
void ic(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x43, r1, dxb2); }
void l(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x58, r1, dxb2); }
void la(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x41, r1, dxb2); }
void lae(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x51, r1, dxb2); }
void ld(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x68, r1, dxb2); }
void le(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x78, r1, dxb2); }
void lh(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x48, r1, dxb2); }
void lra(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0xB1, r1, dxb2); }
void m(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x5C, r1, dxb2); }
void md(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x6C, r1, dxb2); }
void mde(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x7C, r1, dxb2); }
void me(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x7C, r1, dxb2); }
void mh(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x4C, r1, dxb2); }
void ms(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x71, r1, dxb2); }
void mxd(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x67, r1, dxb2); }
void n(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x54, r1, dxb2); }
void o(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x56, r1, dxb2); }
void s(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x5B, r1, dxb2); }
void sd(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x6B, r1, dxb2); }
void se(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x7B, r1, dxb2); }
void sh(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x4B, r1, dxb2); }
void sl(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x5F, r1, dxb2); }
void st(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x50, r1, dxb2); }
void stc(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x42, r1, dxb2); }
void std(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x60, r1, dxb2); }
void ste(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x70, r1, dxb2); }
void sth(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x40, r1, dxb2); }
void su(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x7F, r1, dxb2); }
void sw(const FReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x6F, r1, dxb2); }
void x(const GPReg& r1, const AddrDXB& dxb2 ){ opRX_A(0x57, r1, dxb2); }
void ag(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE308, r1, dxb2); }
void agf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE318, r1, dxb2); }
void agh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE338, r1, dxb2); }
void ahy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE37A, r1, dxb2); }
void alc(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE398, r1, dxb2); }
void alcg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE388, r1, dxb2); }
void alg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE30A, r1, dxb2); }
void algf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE31A, r1, dxb2); }
void aly(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE35E, r1, dxb2); }
void ay(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE35A, r1, dxb2); }
void bctg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE346, r1, dxb2); }
void cg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE320, r1, dxb2); }
void cgf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE330, r1, dxb2); }
void cgh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE334, r1, dxb2); }
void chf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE3CD, r1, dxb2); }
void chy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE379, r1, dxb2); }
void clg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE321, r1, dxb2); }
void clgf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE331, r1, dxb2); }
void clhf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE3CF, r1, dxb2); }
void cly(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE355, r1, dxb2); }
void cvbg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE30E, r1, dxb2); }
void cvby(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE306, r1, dxb2); }
void cvdg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE32E, r1, dxb2); }
void cvdy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE326, r1, dxb2); }
void cy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE359, r1, dxb2); }
void dl(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE397, r1, dxb2); }
void dlg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE387, r1, dxb2); }
void dsg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE30D, r1, dxb2); }
void dsgf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE31D, r1, dxb2); }
void icy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE373, r1, dxb2); }
void laey(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE375, r1, dxb2); }
void lat(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE39F, r1, dxb2); }
void lay(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE371, r1, dxb2); }
void lb(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE376, r1, dxb2); }
void lbh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE3C0, r1, dxb2); }
void ldy(const FReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xED65, r1, dxb2); }
void ley(const FReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xED64, r1, dxb2); }
void lfh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE3CA, r1, dxb2); }
void lfhat(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE3C8, r1, dxb2); }
void lg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE304, r1, dxb2); }
void lgat(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE385, r1, dxb2); }
void lgb(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE377, r1, dxb2); }
void lgf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE314, r1, dxb2); }
void lgg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE34C, r1, dxb2); }
void lgh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE315, r1, dxb2); }
void lgsc(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE34D, r1, dxb2); }
void lhh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE3C4, r1, dxb2); }
void lhy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE378, r1, dxb2); }
void llc(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE394, r1, dxb2); }
void llch(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE3C2, r1, dxb2); }
void llgc(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE390, r1, dxb2); }
void llgf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE316, r1, dxb2); }
void llgfat(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE39D, r1, dxb2); }
void llgfsg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE348, r1, dxb2); }
void llgh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE391, r1, dxb2); }
void llgt(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE317, r1, dxb2); }
void llgtat(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE39C, r1, dxb2); }
void llh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE395, r1, dxb2); }
void llhh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE3C6, r1, dxb2); }
void llzrgf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE33A, r1, dxb2); }
void lpq(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE38F, r1, dxb2); }
void lrag(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE303, r1, dxb2); }
void lray(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE313, r1, dxb2); }
void lrv(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE31E, r1, dxb2); }
void lrvg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE30F, r1, dxb2); }
void lrvh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE31F, r1, dxb2); }
void lt(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE312, r1, dxb2); }
void ltg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE302, r1, dxb2); }
void ltgf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE332, r1, dxb2); }
void ly(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE358, r1, dxb2); }
void lzrf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE33B, r1, dxb2); }
void lzrg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE32A, r1, dxb2); }
void mfy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE35C, r1, dxb2); }
void mg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE384, r1, dxb2); }
void mgh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE33C, r1, dxb2); }
void mhy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE37C, r1, dxb2); }
void ml(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE396, r1, dxb2); }
void mlg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE386, r1, dxb2); }
void msc(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE353, r1, dxb2); }
void msg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE30C, r1, dxb2); }
void msgc(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE383, r1, dxb2); }
void msgf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE31C, r1, dxb2); }
void msy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE351, r1, dxb2); }
void ng(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE380, r1, dxb2); }
void ntstg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE325, r1, dxb2); }
void ny(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE354, r1, dxb2); }
void og(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE381, r1, dxb2); }
void oy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE356, r1, dxb2); }
void sg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE309, r1, dxb2); }
void sgf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE319, r1, dxb2); }
void sgh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE339, r1, dxb2); }
void shy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE37B, r1, dxb2); }
void slb(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE399, r1, dxb2); }
void slbg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE389, r1, dxb2); }
void slg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE30B, r1, dxb2); }
void slgf(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE31B, r1, dxb2); }
void sly(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE35F, r1, dxb2); }
void stch(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE3C3, r1, dxb2); }
void stcy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE372, r1, dxb2); }
void stdy(const FReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xED67, r1, dxb2); }
void stey(const FReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xED66, r1, dxb2); }
void stfh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE3CB, r1, dxb2); }
void stg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE324, r1, dxb2); }
void stgsc(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE349, r1, dxb2); }
void sthh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE3C7, r1, dxb2); }
void sthy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE370, r1, dxb2); }
void stpq(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE38E, r1, dxb2); }
void strv(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE33E, r1, dxb2); }
void strvg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE32F, r1, dxb2); }
void strvh(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE33F, r1, dxb2); }
void sty(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE350, r1, dxb2); }
void sy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE35B, r1, dxb2); }
void xg(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE382, r1, dxb2); }
void xy(const GPReg& r1, const AddrDXB& dxb2 ){ opRXY_A(0xE357, r1, dxb2); }
void afi(const GPReg& r1, const int& i2 ){ opRIL_A(0xC29, r1, i2); }
void agfi(const GPReg& r1, const int& i2 ){ opRIL_A(0xC28, r1, i2); }
void aih(const GPReg& r1, const int& i2 ){ opRIL_A(0xCC8, r1, i2); }
void alfi(const GPReg& r1, const int& i2 ){ opRIL_A(0xC2B, r1, i2); }
void algfi(const GPReg& r1, const int& i2 ){ opRIL_A(0xC2A, r1, i2); }
void alsih(const GPReg& r1, const int& i2 ){ opRIL_A(0xCCA, r1, i2); }
void alsihn(const GPReg& r1, const int& i2 ){ opRIL_A(0xCCB, r1, i2); }
void cfi(const GPReg& r1, const int& i2 ){ opRIL_A(0xC2D, r1, i2); }
void cgfi(const GPReg& r1, const int& i2 ){ opRIL_A(0xC2C, r1, i2); }
void cih(const GPReg& r1, const int& i2 ){ opRIL_A(0xCCD, r1, i2); }
void clfi(const GPReg& r1, const int& i2 ){ opRIL_A(0xC2F, r1, i2); }
void clgfi(const GPReg& r1, const int& i2 ){ opRIL_A(0xC2E, r1, i2); }
void clih(const GPReg& r1, const int& i2 ){ opRIL_A(0xCCF, r1, i2); }
void iihf(const GPReg& r1, const int& i2 ){ opRIL_A(0xC08, r1, i2); }
void iilf(const GPReg& r1, const int& i2 ){ opRIL_A(0xC09, r1, i2); }
void lgfi(const GPReg& r1, const int& i2 ){ opRIL_A(0xC01, r1, i2); }
void llihf(const GPReg& r1, const int& i2 ){ opRIL_A(0xC0E, r1, i2); }
void llilf(const GPReg& r1, const int& i2 ){ opRIL_A(0xC0F, r1, i2); }
void msfi(const GPReg& r1, const int& i2 ){ opRIL_A(0xC21, r1, i2); }
void msgfi(const GPReg& r1, const int& i2 ){ opRIL_A(0xC20, r1, i2); }
void nihf(const GPReg& r1, const int& i2 ){ opRIL_A(0xC0A, r1, i2); }
void nilf(const GPReg& r1, const int& i2 ){ opRIL_A(0xC0B, r1, i2); }
void oihf(const GPReg& r1, const int& i2 ){ opRIL_A(0xC0C, r1, i2); }
void oilf(const GPReg& r1, const int& i2 ){ opRIL_A(0xC0D, r1, i2); }
void slfi(const GPReg& r1, const int& i2 ){ opRIL_A(0xC25, r1, i2); }
void slgfi(const GPReg& r1, const int& i2 ){ opRIL_A(0xC24, r1, i2); }
void xihf(const GPReg& r1, const int& i2 ){ opRIL_A(0xC06, r1, i2); }
void xilf(const GPReg& r1, const int& i2 ){ opRIL_A(0xC07, r1, i2); }
void aghik(const GPReg& r1, const GPReg& r3, const int& i2 ){ opRIE_D(0xECD9, r1, r3, i2); }
void ahik(const GPReg& r1, const GPReg& r3, const int& i2 ){ opRIE_D(0xECD8, r1, r3, i2); }
void alghsik(const GPReg& r1, const GPReg& r3, const int& i2 ){ opRIE_D(0xECDB, r1, r3, i2); }
void alhsik(const GPReg& r1, const GPReg& r3, const int& i2 ){ opRIE_D(0xECDA, r1, r3, i2); }
void agsi(const AddrDB& db1, const int& i2 ){ opSIY(0xEB7A, db1, i2); }
void algsi(const AddrDB& db1, const int& i2 ){ opSIY(0xEB7E, db1, i2); }
void alsi(const AddrDB& db1, const int& i2 ){ opSIY(0xEB6E, db1, i2); }
void asi(const AddrDB& db1, const int& i2 ){ opSIY(0xEB6A, db1, i2); }
void cliy(const AddrDB& db1, const int& i2 ){ opSIY(0xEB55, db1, i2); }
void mviy(const AddrDB& db1, const int& i2 ){ opSIY(0xEB52, db1, i2); }
void niy(const AddrDB& db1, const int& i2 ){ opSIY(0xEB54, db1, i2); }
void oiy(const AddrDB& db1, const int& i2 ){ opSIY(0xEB56, db1, i2); }
void tmy(const AddrDB& db1, const int& i2 ){ opSIY(0xEB51, db1, i2); }
void xiy(const AddrDB& db1, const int& i2 ){ opSIY(0xEB57, db1, i2); }
void aghi(const GPReg& r1, const int& i2 ){ opRI_A(0xA7B, r1, i2); }
void ahi(const GPReg& r1, const int& i2 ){ opRI_A(0xA7A, r1, i2); }
void cghi(const GPReg& r1, const int& i2 ){ opRI_A(0xA7F, r1, i2); }
void chi(const GPReg& r1, const int& i2 ){ opRI_A(0xA7E, r1, i2); }
void iihh(const GPReg& r1, const int& i2 ){ opRI_A(0xA50, r1, i2); }
void iihl(const GPReg& r1, const int& i2 ){ opRI_A(0xA51, r1, i2); }
void iilh(const GPReg& r1, const int& i2 ){ opRI_A(0xA52, r1, i2); }
void iill(const GPReg& r1, const int& i2 ){ opRI_A(0xA53, r1, i2); }
void lghi(const GPReg& r1, const int& i2 ){ opRI_A(0xA79, r1, i2); }
void lhi(const GPReg& r1, const int& i2 ){ opRI_A(0xA78, r1, i2); }
void llihh(const GPReg& r1, const int& i2 ){ opRI_A(0xA5C, r1, i2); }
void llihl(const GPReg& r1, const int& i2 ){ opRI_A(0xA5D, r1, i2); }
void llilh(const GPReg& r1, const int& i2 ){ opRI_A(0xA5E, r1, i2); }
void llill(const GPReg& r1, const int& i2 ){ opRI_A(0xA5F, r1, i2); }
void mghi(const GPReg& r1, const int& i2 ){ opRI_A(0xA7D, r1, i2); }
void mhi(const GPReg& r1, const int& i2 ){ opRI_A(0xA7C, r1, i2); }
void nihh(const GPReg& r1, const int& i2 ){ opRI_A(0xA54, r1, i2); }
void nihl(const GPReg& r1, const int& i2 ){ opRI_A(0xA55, r1, i2); }
void nilh(const GPReg& r1, const int& i2 ){ opRI_A(0xA56, r1, i2); }
void nill(const GPReg& r1, const int& i2 ){ opRI_A(0xA57, r1, i2); }
void oihh(const GPReg& r1, const int& i2 ){ opRI_A(0xA58, r1, i2); }
void oihl(const GPReg& r1, const int& i2 ){ opRI_A(0xA59, r1, i2); }
void oilh(const GPReg& r1, const int& i2 ){ opRI_A(0xA5A, r1, i2); }
void oill(const GPReg& r1, const int& i2 ){ opRI_A(0xA5B, r1, i2); }
void tmh(const GPReg& r1, const int& i2 ){ opRI_A(0xA70, r1, i2); }
void tmhh(const GPReg& r1, const int& i2 ){ opRI_A(0xA72, r1, i2); }
void tmhl(const GPReg& r1, const int& i2 ){ opRI_A(0xA73, r1, i2); }
void tml(const GPReg& r1, const int& i2 ){ opRI_A(0xA71, r1, i2); }
void tmlh(const GPReg& r1, const int& i2 ){ opRI_A(0xA70, r1, i2); }
void tmll(const GPReg& r1, const int& i2 ){ opRI_A(0xA71, r1, i2); }
void cli(const AddrDB& db1, const int& i2 ){ opSI(0x95, db1, i2); }
void mc(const AddrDB& db1, const int& i2 ){ opSI(0xAF, db1, i2); }
void mvi(const AddrDB& db1, const int& i2 ){ opSI(0x92, db1, i2); }
void ni(const AddrDB& db1, const int& i2 ){ opSI(0x94, db1, i2); }
void oi(const AddrDB& db1, const int& i2 ){ opSI(0x96, db1, i2); }
void stnsm(const AddrDB& db1, const int& i2 ){ opSI(0xAC, db1, i2); }
void stosm(const AddrDB& db1, const int& i2 ){ opSI(0xAD, db1, i2); }
void tm(const AddrDB& db1, const int& i2 ){ opSI(0x91, db1, i2); }
void xi(const AddrDB& db1, const int& i2 ){ opSI(0x97, db1, i2); }
void lpsw(const AddrDB& db2 ){ opSI(0x82, db2); }
void ssm(const AddrDB& db2 ){ opSI(0x80, db2); }
void ts(const AddrDB& db2 ){ opSI(0x93, db2); }
void clc(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xD5, dlb1, db2); }
void ed(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xDE, dlb1, db2); }
void edmk(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xDF, dlb1, db2); }
void mvc(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xD2, dlb1, db2); }
void mvcin(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xE8, dlb1, db2); }
void mvn(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xD1, dlb1, db2); }
void mvz(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xD3, dlb1, db2); }
void nc(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xD4, dlb1, db2); }
void oc(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xD6, dlb1, db2); }
void tr(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xDC, dlb1, db2); }
void trt(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xDD, dlb1, db2); }
void trtr(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xD0, dlb1, db2); }
void xc(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xD7, dlb1, db2); }
void unpka(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xEA, dlb1, db2); }
void unpku(const AddrDLB& dlb1, const AddrDB& db2 ){ opSS_A(0xE2, dlb1, db2); }
void bic(const int& m1, const AddrDXB& dxb2 ){ opRXY_B(0xE347, m1, dxb2); }
void pfd(const int& m1, const AddrDXB& dxb2 ){ opRXY_B(0xE336, m1, dxb2); }
void bc(const int& m1, const AddrDXB& dxb2 ){ opRX_B(0x47, m1, dxb2); }
void bxh(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRS_A(0x86, r1, r3, db2); }
void bxle(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRS_A(0x87, r1, r3, db2); }
void cds(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRS_A(0xBB, r1, r3, db2); }
void clcle(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRS_A(0xA9, r1, r3, db2); }
void cs(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRS_A(0xBA, r1, r3, db2); }
void lam(const AReg& r1, const AReg& r3, const AddrDB& db2 ){ opRS_A(0x9A, r1, r3, db2); }
void lctl(const CReg& r1, const CReg& r3, const AddrDB& db2 ){ opRS_A(0xB7, r1, r3, db2); }
void lm(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRS_A(0x98, r1, r3, db2); }
void mvcle(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRS_A(0xA8, r1, r3, db2); }
void sigp(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRS_A(0xAE, r1, r3, db2); }
void stam(const AReg& r1, const AReg& r3, const AddrDB& db2 ){ opRS_A(0x9B, r1, r3, db2); }
void stctl(const CReg& r1, const CReg& r3, const AddrDB& db2 ){ opRS_A(0xB6, r1, r3, db2); }
void stm(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRS_A(0x90, r1, r3, db2); }
void trace(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRS_A(0x99, r1, r3, db2); }
void sla(const GPReg& r1, const AddrDB& db2 ){ opRS_A(0x8B, r1, db2); }
void slda(const GPReg& r1, const AddrDB& db2 ){ opRS_A(0x8F, r1, db2); }
void sldl(const GPReg& r1, const AddrDB& db2 ){ opRS_A(0x8D, r1, db2); }
void sll(const GPReg& r1, const AddrDB& db2 ){ opRS_A(0x89, r1, db2); }
void sra(const GPReg& r1, const AddrDB& db2 ){ opRS_A(0x8A, r1, db2); }
void srda(const GPReg& r1, const AddrDB& db2 ){ opRS_A(0x8E, r1, db2); }
void srdl(const GPReg& r1, const AddrDB& db2 ){ opRS_A(0x8C, r1, db2); }
void srl(const GPReg& r1, const AddrDB& db2 ){ opRS_A(0x88, r1, db2); }
void bxhg(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB44, r1, r3, db2); }
void bxleg(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB45, r1, r3, db2); }
void cdsg(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB3E, r1, r3, db2); }
void cdsy(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB31, r1, r3, db2); }
void clclu(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB8F, r1, r3, db2); }
void csg(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB30, r1, r3, db2); }
void csy(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB14, r1, r3, db2); }
void ecag(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB4C, r1, r3, db2); }
void laa(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBF8, r1, r3, db2); }
void laag(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBE8, r1, r3, db2); }
void laal(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBFA, r1, r3, db2); }
void laalg(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBEA, r1, r3, db2); }
void lamy(const AReg& r1, const AReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB9A, r1, r3, db2); }
void lan(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBF4, r1, r3, db2); }
void lang(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBE4, r1, r3, db2); }
void lao(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBF6, r1, r3, db2); }
void laog(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBE6, r1, r3, db2); }
void lax(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBF7, r1, r3, db2); }
void laxg(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBE7, r1, r3, db2); }
void lctlg(const CReg& r1, const CReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB2F, r1, r3, db2); }
void lmg(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB04, r1, r3, db2); }
void lmh(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB96, r1, r3, db2); }
void lmy(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB98, r1, r3, db2); }
void mvclu(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB8E, r1, r3, db2); }
void rll(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB1D, r1, r3, db2); }
void rllg(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB1C, r1, r3, db2); }
void slag(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB0B, r1, r3, db2); }
void slak(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBDD, r1, r3, db2); }
void sllg(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB0D, r1, r3, db2); }
void sllk(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBDF, r1, r3, db2); }
void srag(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB0A, r1, r3, db2); }
void srak(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBDC, r1, r3, db2); }
void srlg(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB0C, r1, r3, db2); }
void srlk(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEBDE, r1, r3, db2); }
void stamy(const AReg& r1, const AReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB9B, r1, r3, db2); }
void stctg(const CReg& r1, const CReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB25, r1, r3, db2); }
void stmg(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB24, r1, r3, db2); }
void stmh(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB26, r1, r3, db2); }
void stmy(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB90, r1, r3, db2); }
void tracg(const GPReg& r1, const GPReg& r3, const AddrDB& db2 ){ opRSY_A(0xEB0F, r1, r3, db2); }
void bpp(const int& m1, const int& ri2, const AddrDB& db3 ){ opSMI(0xC7, m1, ri2, db3); }
void bprp(const int& m1, const int& ri2, const int& ri3 ){ opMII(0xC5, m1, ri2, ri3); }
void bras(const Operand& r1, const Label& lbl_ri2 ){ auto ri2 = encodeJmp(lbl_ri2, 16, 16); opRI_B(0xA75, r1, ri2); }
void brct(const Operand& r1, const Label& lbl_ri2 ){ auto ri2 = encodeJmp(lbl_ri2, 16, 16); opRI_B(0xA76, r1, ri2); }
void brctg(const Operand& r1, const Label& lbl_ri2 ){ auto ri2 = encodeJmp(lbl_ri2, 16, 16); opRI_B(0xA77, r1, ri2); }
void brasl(const Operand& r1, const Label& lbl_ri2 ){ auto ri2 = encodeJmp(lbl_ri2, 16, 32); opRIL_B(0xC05, r1, ri2); }
void brcth(const Operand& r1, const Label& lbl_ri2 ){ auto ri2 = encodeJmp(lbl_ri2, 16, 32); opRIL_B(0xCC6, r1, ri2); }
void cgfrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC6C, r1, ri2); }
void cghrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC64, r1, ri2); }
void cgrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC68, r1, ri2); }
void chrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC65, r1, ri2); }
void clgfrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC6E, r1, ri2); }
void clghrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC66, r1, ri2); }
void clgrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC6A, r1, ri2); }
void clhrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC67, r1, ri2); }
void clrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC6F, r1, ri2); }
void crl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC6D, r1, ri2); }
void exrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC60, r1, ri2); }
void larl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC00, r1, ri2); }
void lgfrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC4C, r1, ri2); }
void lghrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC44, r1, ri2); }
void lgrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC48, r1, ri2); }
void lhrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC45, r1, ri2); }
void llgfrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC4E, r1, ri2); }
void llghrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC46, r1, ri2); }
void llhrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC42, r1, ri2); }
void lrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC4D, r1, ri2); }
void stgrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC4B, r1, ri2); }
void sthrl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC47, r1, ri2); }
void strl(const GPReg& r1, const int& ri2 ){ opRIL_B(0xC4F, r1, ri2); }
void brc(const int& m1, const Label& lbl_ri2 ){ auto ri2 = encodeJmp(lbl_ri2, 16, 16); opRI_C(0xA74, m1, ri2); }
void brcl(const int& m1, const Label& lbl_ri2 ){ auto ri2 = encodeJmp(lbl_ri2, 16, 32); opRIL_C(0xC04, m1, ri2); }
void pfdrl(const int& m1, const int& ri2 ){ opRIL_C(0xC62, m1, ri2); }
void brxh(const Operand& r1, const Operand& r3, const Label& lbl_ri2 ){ auto ri2 = encodeJmp(lbl_ri2, 16, 16); opRSI(0x84, r1, r3, ri2); }
void brxle(const Operand& r1, const Operand& r3, const Label& lbl_ri2 ){ auto ri2 = encodeJmp(lbl_ri2, 16, 16); opRSI(0x85, r1, r3, ri2); }
void brxhg(const Operand& r1, const Operand& r3, const Label& lbl_ri2 ){ auto ri2 = encodeJmp(lbl_ri2, 16, 16); opRIE_E(0xEC44, r1, r3, ri2); }
void brxlg(const Operand& r1, const Operand& r3, const Label& lbl_ri2 ){ auto ri2 = encodeJmp(lbl_ri2, 16, 16); opRIE_E(0xEC45, r1, r3, ri2); }
void cpsdr(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRF_B(0xB372, r1, r3, r2); }
void iedtr(const FReg& r1, const GPReg& r3, const GPReg& r2 ){ opRRF_B(0xB3F6, r1, r3, r2); }
void iextr(const FReg& r1, const GPReg& r3, const GPReg& r2 ){ opRRF_B(0xB3FE, r1, r3, r2); }
void kma(const GPReg& r1, const GPReg& r3, const GPReg& r2 ){ opRRF_B(0xB929, r1, r3, r2); }
void kmctr(const GPReg& r1, const GPReg& r3, const GPReg& r2 ){ opRRF_B(0xB92D, r1, r3, r2); }
void crdte(const GPReg& r1, const GPReg& r3, const GPReg& r2, const int& m4= {}  ){ opRRF_B(0xB98F, r1, r3, r2, m4); }
void idte(const GPReg& r1, const GPReg& r3, const GPReg& r2, const int& m4= {}  ){ opRRF_B(0xB98E, r1, r3, r2, m4); }
void didbr(const FReg& r1, const FReg& r3, const FReg& r2, const int& m4 ){ opRRF_B(0xB35B, r1, r3, r2, m4); }
void diebr(const FReg& r1, const FReg& r3, const FReg& r2, const int& m4 ){ opRRF_B(0xB353, r1, r3, r2, m4); }
void lptea(const GPReg& r1, const GPReg& r3, const GPReg& r2, const int& m4 ){ opRRF_B(0xB9AA, r1, r3, r2, m4); }
void qadtr(const FReg& r1, const FReg& r3, const FReg& r2, const int& m4 ){ opRRF_B(0xB3F5, r1, r3, r2, m4); }
void qaxtr(const FReg& r1, const FReg& r3, const FReg& r2, const int& m4 ){ opRRF_B(0xB3FD, r1, r3, r2, m4); }
void rrdtr(const FReg& r1, const FReg& r3, const FReg& r2, const int& m4 ){ opRRF_B(0xB3F7, r1, r3, r2, m4); }
void rrxtr(const FReg& r1, const FReg& r3, const FReg& r2, const int& m4 ){ opRRF_B(0xB3FF, r1, r3, r2, m4); }
void cgrb(const GPReg& r1, const GPReg& r2, const int& m3, const AddrDB& db4 ){ opRRS(0xECE4, r1, r2, m3, db4); }
void clgrb(const GPReg& r1, const GPReg& r2, const int& m3, const AddrDB& db4 ){ opRRS(0xECE5, r1, r2, m3, db4); }
void clrb(const GPReg& r1, const GPReg& r2, const int& m3, const AddrDB& db4 ){ opRRS(0xECF7, r1, r2, m3, db4); }
void crb(const GPReg& r1, const GPReg& r2, const int& m3, const AddrDB& db4 ){ opRRS(0xECF6, r1, r2, m3, db4); }
void cgrj(const Operand& r1, const Operand& r2, const int& m3, const Label& lbl_ri4 ){ auto ri4 = encodeJmp(lbl_ri4, 16, 16); opRIE_B(0xEC64, r1, r2, m3, ri4); }
void clgrj(const Operand& r1, const Operand& r2, const int& m3, const Label& lbl_ri4 ){ auto ri4 = encodeJmp(lbl_ri4, 16, 16); opRIE_B(0xEC65, r1, r2, m3, ri4); }
void clrj(const Operand& r1, const Operand& r2, const int& m3, const Label& lbl_ri4 ){ auto ri4 = encodeJmp(lbl_ri4, 16, 16); opRIE_B(0xEC77, r1, r2, m3, ri4); }
void crj(const Operand& r1, const Operand& r2, const int& m3, const Label& lbl_ri4 ){ auto ri4 = encodeJmp(lbl_ri4, 16, 16); opRIE_B(0xEC76, r1, r2, m3, ri4); }
void cgib(const GPReg& r1, const int& i2, const int& m3, const AddrDB& db4 ){ opRIS(0xECFC, r1, i2, m3, db4); }
void cib(const GPReg& r1, const int& i2, const int& m3, const AddrDB& db4 ){ opRIS(0xECFE, r1, i2, m3, db4); }
void clgib(const GPReg& r1, const int& i2, const int& m3, const AddrDB& db4 ){ opRIS(0xECFD, r1, i2, m3, db4); }
void clib(const GPReg& r1, const int& i2, const int& m3, const AddrDB& db4 ){ opRIS(0xECFF, r1, i2, m3, db4); }
void cgij(const Operand& r1, const int& i2, const int& m3, const Label& lbl_ri4 ){ auto ri4 = encodeJmp(lbl_ri4, 16, 16); opRIE_C(0xEC7C, r1, i2, m3, ri4); }
void cij(const Operand& r1, const int& i2, const int& m3, const Label& lbl_ri4 ){ auto ri4 = encodeJmp(lbl_ri4, 16, 16); opRIE_C(0xEC7E, r1, i2, m3, ri4); }
void clgij(const GPReg& r1, const int& i2, const int& m3, const int& ri4 ){ opRIE_C(0xEC7D, r1, i2, m3, ri4); }
void clij(const GPReg& r1, const int& i2, const int& m3, const int& ri4 ){ opRIE_C(0xEC7F, r1, i2, m3, ri4); }
void cfc(const AddrDB& db2 ){ opS(0xB21A, db2); }
void lfas(const AddrDB& db2 ){ opS(0xB2BD, db2); }
void lfpc(const AddrDB& db2 ){ opS(0xB29D, db2); }
void lpswe(const AddrDB& db2 ){ opS(0xB2B2, db2); }
void msch(const AddrDB& db2 ){ opS(0xB232, db2); }
void pc(const AddrDB& db2 ){ opS(0xB218, db2); }
void rp(const AddrDB& db2 ){ opS(0xB277, db2); }
void sac(const AddrDB& db2 ){ opS(0xB219, db2); }
void sacf(const AddrDB& db2 ){ opS(0xB279, db2); }
void sck(const AddrDB& db2 ){ opS(0xB204, db2); }
void sckc(const AddrDB& db2 ){ opS(0xB206, db2); }
void spka(const AddrDB& db2 ){ opS(0xB20A, db2); }
void spt(const AddrDB& db2 ){ opS(0xB208, db2); }
void spx(const AddrDB& db2 ){ opS(0xB210, db2); }
void srnm(const AddrDB& db2 ){ opS(0xB299, db2); }
void srnmb(const AddrDB& db2 ){ opS(0xB2B8, db2); }
void srnmt(const AddrDB& db2 ){ opS(0xB2B9, db2); }
void ssch(const AddrDB& db2 ){ opS(0xB233, db2); }
void stap(const AddrDB& db2 ){ opS(0xB212, db2); }
void stck(const AddrDB& db2 ){ opS(0xB205, db2); }
void stckc(const AddrDB& db2 ){ opS(0xB207, db2); }
void stcke(const AddrDB& db2 ){ opS(0xB278, db2); }
void stckf(const AddrDB& db2 ){ opS(0xB27C, db2); }
void stcps(const AddrDB& db2 ){ opS(0xB23A, db2); }
void stcrw(const AddrDB& db2 ){ opS(0xB239, db2); }
void stfl(const AddrDB& db2 ){ opS(0xB2B1, db2); }
void stfle(const AddrDB& db2 ){ opS(0xB2B0, db2); }
void stfpc(const AddrDB& db2 ){ opS(0xB29C, db2); }
void stidp(const AddrDB& db2 ){ opS(0xB202, db2); }
void stpt(const AddrDB& db2 ){ opS(0xB209, db2); }
void stpx(const AddrDB& db2 ){ opS(0xB211, db2); }
void stsch(const AddrDB& db2 ){ opS(0xB234, db2); }
void stsi(const AddrDB& db2 ){ opS(0xB27D, db2); }
void tabort(const AddrDB& db2 ){ opS(0xB2FC, db2); }
void tpi(const AddrDB& db2 ){ opS(0xB236, db2); }
void tsch(const AddrDB& db2 ){ opS(0xB235, db2); }
void csch( ){ opS(0xB230); }
void hsch( ){ opS(0xB231); }
void ipk( ){ opS(0xB20B); }
void ptlb( ){ opS(0xB20D); }
void rchp( ){ opS(0xB23B); }
void rsch( ){ opS(0xB238); }
void sal( ){ opS(0xB237); }
void schm( ){ opS(0xB23C); }
void tend( ){ opS(0xB2F8); }
void xsch( ){ opS(0xB276); }
void csst(const AddrDB& db1, const AddrDB& db2, const GPReg& r3 ){ opSSF(0xC82, db1, db2, r3); }
void ectg(const AddrDB& db1, const AddrDB& db2, const GPReg& r3 ){ opSSF(0xC81, db1, db2, r3); }
void mvcos(const AddrDB& db1, const AddrDB& db2, const GPReg& r3 ){ opSSF(0xC80, db1, db2, r3); }
void lpd(const GPReg& r3, const AddrDB& db1, const AddrDB& db2 ){ opSSF(0xC84, r3, db1, db2); }
void lpdg(const GPReg& r3, const AddrDB& db1, const AddrDB& db2 ){ opSSF(0xC85, r3, db1, db2); }
void cgrt(const GPReg& r1, const GPReg& r2, const int& m3 ){ opRRF_C(0xB960, r1, r2, m3); }
void clgrt(const GPReg& r1, const GPReg& r2, const int& m3 ){ opRRF_C(0xB961, r1, r2, m3); }
void clrt(const GPReg& r1, const GPReg& r2, const int& m3 ){ opRRF_C(0xB973, r1, r2, m3); }
void crt(const GPReg& r1, const GPReg& r2, const int& m3 ){ opRRF_C(0xB972, r1, r2, m3); }
void locfhr(const GPReg& r1, const GPReg& r2, const int& m3 ){ opRRF_C(0xB9E0, r1, r2, m3); }
void locgr(const GPReg& r1, const GPReg& r2, const int& m3 ){ opRRF_C(0xB9E2, r1, r2, m3); }
void locr(const GPReg& r1, const GPReg& r2, const int& m3 ){ opRRF_C(0xB9F2, r1, r2, m3); }
void ppa(const GPReg& r1, const GPReg& r2, const int& m3 ){ opRRF_C(0xB2E8, r1, r2, m3); }
void cu12(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB2A7, r1, r2, m3); }
void cu14(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB9B0, r1, r2, m3); }
void cu21(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB2A6, r1, r2, m3); }
void cu24(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB9B1, r1, r2, m3); }
void cutfu(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB2A7, r1, r2, m3); }
void cuutf(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB2A6, r1, r2, m3); }
void popcnt(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB9E1, r1, r2, m3); }
void sske(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB22B, r1, r2, m3); }
void troo(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB993, r1, r2, m3); }
void trot(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB992, r1, r2, m3); }
void trte(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB9BF, r1, r2, m3); }
void trto(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB991, r1, r2, m3); }
void trtre(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB9BD, r1, r2, m3); }
void trtt(const GPReg& r1, const GPReg& r2, const int& m3= {}  ){ opRRF_C(0xB990, r1, r2, m3); }
void cgit(const GPReg& r1, const int& i2, const int& m3 ){ opRIE_A(0xEC70, r1, i2, m3); }
void cit(const GPReg& r1, const int& i2, const int& m3 ){ opRIE_A(0xEC72, r1, i2, m3); }
void clfit(const GPReg& r1, const int& i2, const int& m3 ){ opRIE_A(0xEC73, r1, i2, m3); }
void clgit(const GPReg& r1, const int& i2, const int& m3 ){ opRIE_A(0xEC71, r1, i2, m3); }
void cghsi(const AddrDB& db1, const int& i2 ){ opSIL(0xE558, db1, i2); }
void chhsi(const AddrDB& db1, const int& i2 ){ opSIL(0xE554, db1, i2); }
void chsi(const AddrDB& db1, const int& i2 ){ opSIL(0xE55C, db1, i2); }
void clfhsi(const AddrDB& db1, const int& i2 ){ opSIL(0xE55D, db1, i2); }
void clghsi(const AddrDB& db1, const int& i2 ){ opSIL(0xE559, db1, i2); }
void clhhsi(const AddrDB& db1, const int& i2 ){ opSIL(0xE555, db1, i2); }
void mvghi(const AddrDB& db1, const int& i2 ){ opSIL(0xE548, db1, i2); }
void mvhhi(const AddrDB& db1, const int& i2 ){ opSIL(0xE544, db1, i2); }
void mvhi(const AddrDB& db1, const int& i2 ){ opSIL(0xE54C, db1, i2); }
void tbegin(const AddrDB& db1, const int& i2 ){ opSIL(0xE560, db1, i2); }
void tbeginc(const AddrDB& db1, const int& i2 ){ opSIL(0xE561, db1, i2); }
void clgt(const GPReg& r1, const int& m3, const AddrDB& db2 ){ opRSY_B(0xEB2B, r1, m3, db2); }
void clmh(const GPReg& r1, const int& m3, const AddrDB& db2 ){ opRSY_B(0xEB20, r1, m3, db2); }
void clmy(const GPReg& r1, const int& m3, const AddrDB& db2 ){ opRSY_B(0xEB21, r1, m3, db2); }
void clt(const GPReg& r1, const int& m3, const AddrDB& db2 ){ opRSY_B(0xEB23, r1, m3, db2); }
void icmh(const GPReg& r1, const int& m3, const AddrDB& db2 ){ opRSY_B(0xEB80, r1, m3, db2); }
void icmy(const GPReg& r1, const int& m3, const AddrDB& db2 ){ opRSY_B(0xEB81, r1, m3, db2); }
void stcmh(const GPReg& r1, const int& m3, const AddrDB& db2 ){ opRSY_B(0xEB2C, r1, m3, db2); }
void stcmy(const GPReg& r1, const int& m3, const AddrDB& db2 ){ opRSY_B(0xEB2D, r1, m3, db2); }
void loc(const GPReg& r1, const AddrDB& db2, const int& m3 ){ opRSY_B(0xEBF2, r1, db2, m3); }
void locfh(const GPReg& r1, const AddrDB& db2, const int& m3 ){ opRSY_B(0xEBE0, r1, db2, m3); }
void locg(const GPReg& r1, const AddrDB& db2, const int& m3 ){ opRSY_B(0xEBE2, r1, db2, m3); }
void stoc(const GPReg& r1, const AddrDB& db2, const int& m3 ){ opRSY_B(0xEBF3, r1, db2, m3); }
void stocfh(const GPReg& r1, const AddrDB& db2, const int& m3 ){ opRSY_B(0xEBE1, r1, db2, m3); }
void stocg(const GPReg& r1, const AddrDB& db2, const int& m3 ){ opRSY_B(0xEBE3, r1, db2, m3); }
void clm(const GPReg& r1, const int& m3, const AddrDB& db2 ){ opRS_B(0xBD, r1, m3, db2); }
void icm(const GPReg& r1, const int& m3, const AddrDB& db2 ){ opRS_B(0xBF, r1, m3, db2); }
void stcm(const GPReg& r1, const int& m3, const AddrDB& db2 ){ opRS_B(0xBE, r1, m3, db2); }
void lcbb(const GPReg& r1, const AddrDXB& dxb2, const int& m3 ){ opRXE(0xE727, r1, dxb2, m3); }
void adb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED1A, r1, dxb2); }
void aeb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED0A, r1, dxb2); }
void cdb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED19, r1, dxb2); }
void ceb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED09, r1, dxb2); }
void ddb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED1D, r1, dxb2); }
void deb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED0D, r1, dxb2); }
void kdb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED18, r1, dxb2); }
void keb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED08, r1, dxb2); }
void lde(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED24, r1, dxb2); }
void ldeb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED04, r1, dxb2); }
void lxd(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED25, r1, dxb2); }
void lxdb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED05, r1, dxb2); }
void lxe(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED26, r1, dxb2); }
void lxeb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED06, r1, dxb2); }
void mdb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED1C, r1, dxb2); }
void mdeb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED0C, r1, dxb2); }
void mee(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED37, r1, dxb2); }
void meeb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED17, r1, dxb2); }
void mxdb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED07, r1, dxb2); }
void sdb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED1B, r1, dxb2); }
void seb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED0B, r1, dxb2); }
void sqd(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED35, r1, dxb2); }
void sqdb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED15, r1, dxb2); }
void sqe(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED34, r1, dxb2); }
void sqeb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED14, r1, dxb2); }
void tcdb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED11, r1, dxb2); }
void tceb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED10, r1, dxb2); }
void tcxb(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED12, r1, dxb2); }
void tdcdt(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED54, r1, dxb2); }
void tdcet(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED50, r1, dxb2); }
void tdcxt(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED58, r1, dxb2); }
void tdgdt(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED55, r1, dxb2); }
void tdget(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED51, r1, dxb2); }
void tdgxt(const FReg& r1, const AddrDXB& dxb2 ){ opRXE(0xED59, r1, dxb2); }
void locghi(const GPReg& r1, const int& i2, const int& m3 ){ opRIE_G(0xEC46, r1, i2, m3); }
void lochhi(const GPReg& r1, const int& i2, const int& m3 ){ opRIE_G(0xEC4E, r1, i2, m3); }
void lochi(const GPReg& r1, const int& i2, const int& m3 ){ opRIE_G(0xEC42, r1, i2, m3); }
void lmd(const GPReg& r1, const GPReg& r3, const AddrDB& db2, const AddrDB& db4 ){ opSS_E(0xEF, r1, r3, db2, db4); }
void plo(const GPReg& r1, const AddrDB& db2, const GPReg& r3, const AddrDB& db4 ){ opSS_E(0xEE, r1, db2, r3, db4); }
void lasp(const AddrDB& db1, const AddrDB& db2 ){ opSSE(0xE500, db1, db2); }
void mvcdk(const AddrDB& db1, const AddrDB& db2 ){ opSSE(0xE50F, db1, db2); }
void mvcrl(const AddrDB& db1, const AddrDB& db2 ){ opSSE(0xE50A, db1, db2); }
void mvcsk(const AddrDB& db1, const AddrDB& db2 ){ opSSE(0xE50E, db1, db2); }
void strag(const AddrDB& db1, const AddrDB& db2 ){ opSSE(0xE502, db1, db2); }
void tprot(const AddrDB& db1, const AddrDB& db2 ){ opSSE(0xE501, db1, db2); }
void ap(const AddrDLB& dlb1, const AddrDLB& dlb2 ){ opSS_B(0xFA, dlb1, dlb2); }
void cp(const AddrDLB& dlb1, const AddrDLB& dlb2 ){ opSS_B(0xF9, dlb1, dlb2); }
void dp(const AddrDLB& dlb1, const AddrDLB& dlb2 ){ opSS_B(0xFD, dlb1, dlb2); }
void mp(const AddrDLB& dlb1, const AddrDLB& dlb2 ){ opSS_B(0xFC, dlb1, dlb2); }
void mvo(const AddrDLB& dlb1, const AddrDLB& dlb2 ){ opSS_B(0xF1, dlb1, dlb2); }
void pack(const AddrDLB& dlb1, const AddrDLB& dlb2 ){ opSS_B(0xF2, dlb1, dlb2); }
void sp(const AddrDLB& dlb1, const AddrDLB& dlb2 ){ opSS_B(0xFB, dlb1, dlb2); }
void unpk(const AddrDLB& dlb1, const AddrDLB& dlb2 ){ opSS_B(0xF3, dlb1, dlb2); }
void zap(const AddrDLB& dlb1, const AddrDLB& dlb2 ){ opSS_B(0xF8, dlb1, dlb2); }
void niai(const int& i1, const int& i2 ){ opIE(0xB2FA, i1, i2); }
void pka(const AddrDB& db1, const AddrDLB& dlb2 ){ opSS_F(0xE9, db1, dlb2); }
void pku(const AddrDB& db1, const AddrDLB& dlb2 ){ opSS_F(0xE1, db1, dlb2); }
void risbg(const GPReg& r1, const GPReg& r2, const int& i3, const int& i4, const int& i5= {}  ){ opRIE_F(0xEC55, r1, r2, i3, i4, i5); }
void risbgn(const GPReg& r1, const GPReg& r2, const int& i3, const int& i4, const int& i5= {}  ){ opRIE_F(0xEC59, r1, r2, i3, i4, i5); }
void risbhg(const GPReg& r1, const GPReg& r2, const int& i3, const int& i4, const int& i5= {}  ){ opRIE_F(0xEC5D, r1, r2, i3, i4, i5); }
void risblg(const GPReg& r1, const GPReg& r2, const int& i3, const int& i4, const int& i5= {}  ){ opRIE_F(0xEC51, r1, r2, i3, i4, i5); }
void rnsbg(const GPReg& r1, const GPReg& r2, const int& i3, const int& i4, const int& i5= {}  ){ opRIE_F(0xEC54, r1, r2, i3, i4, i5); }
void rosbg(const GPReg& r1, const GPReg& r2, const int& i3, const int& i4, const int& i5= {}  ){ opRIE_F(0xEC56, r1, r2, i3, i4, i5); }
void rxsbg(const GPReg& r1, const GPReg& r2, const int& i3, const int& i4, const int& i5= {}  ){ opRIE_F(0xEC57, r1, r2, i3, i4, i5); }
void pfpo( ){ opE(0x010A); }
void pr( ){ opE(0x0101); }
void ptff( ){ opE(0x0104); }
void sam24( ){ opE(0x010C); }
void sam31( ){ opE(0x010D); }
void sam64( ){ opE(0x010E); }
void sckpf( ){ opE(0x0107); }
void tam( ){ opE(0x010B); }
void trap2( ){ opE(0x01FF); }
void svc(const int& i ){ opI(0x0A, i); }
void srp(const AddrDLB& dlb1, const AddrDB& db2, const int& i3 ){ opSS_C(0xF0, dlb1, db2, i3); }
void tp(const AddrDLB& dlb1 ){ opRSL_A(0xEBC0, dlb1); }
void cfdbr(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB399, r1, m3, r2); }
void cfdr(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB3B9, r1, m3, r2); }
void cfebr(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB398, r1, m3, r2); }
void cfer(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB3B8, r1, m3, r2); }
void cfxbr(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB39A, r1, m3, r2); }
void cfxr(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB3BA, r1, m3, r2); }
void cgdbr(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB3A9, r1, m3, r2); }
void cgdr(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB3C9, r1, m3, r2); }
void cgdtr(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB3E1, r1, m3, r2); }
void cgebr(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB3A8, r1, m3, r2); }
void cger(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB3C8, r1, m3, r2); }
void cgxbr(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB3AA, r1, m3, r2); }
void cgxr(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB3CA, r1, m3, r2); }
void cgxtr(const GPReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB3E9, r1, m3, r2); }
void fidbr(const FReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB35F, r1, m3, r2); }
void fiebr(const FReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB357, r1, m3, r2); }
void fixbr(const FReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB347, r1, m3, r2); }
void tbdr(const FReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB351, r1, m3, r2); }
void tbedr(const FReg& r1, const int& m3, const FReg& r2 ){ opRRF_E(0xB350, r1, m3, r2); }
void cdfbra(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB395, r1, m3, r2, m4); }
void cdftr(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB951, r1, m3, r2, m4); }
void cdgbra(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB3A5, r1, m3, r2, m4); }
void cdgtra(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB3F1, r1, m3, r2, m4); }
void cdlfbr(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB391, r1, m3, r2, m4); }
void cdlftr(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB953, r1, m3, r2, m4); }
void cdlgbr(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB3A1, r1, m3, r2, m4); }
void cdlgtr(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB952, r1, m3, r2, m4); }
void cefbra(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB394, r1, m3, r2, m4); }
void cegbra(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB3A4, r1, m3, r2, m4); }
void celfbr(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB390, r1, m3, r2, m4); }
void celgbr(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB3A0, r1, m3, r2, m4); }
void cfdbra(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB399, r1, m3, r2, m4); }
void cfdtr(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB941, r1, m3, r2, m4); }
void cfebra(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB398, r1, m3, r2, m4); }
void cfxbra(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB39A, r1, m3, r2, m4); }
void cfxtr(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB949, r1, m3, r2, m4); }
void cgdbra(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB3A9, r1, m3, r2, m4); }
void cgdtra(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB3E1, r1, m3, r2, m4); }
void cgebra(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB3A8, r1, m3, r2, m4); }
void cgxbra(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB3AA, r1, m3, r2, m4); }
void cgxtra(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB3E9, r1, m3, r2, m4); }
void clfdbr(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB39D, r1, m3, r2, m4); }
void clfdtr(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB943, r1, m3, r2, m4); }
void clfebr(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB39C, r1, m3, r2, m4); }
void clfxbr(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB39E, r1, m3, r2, m4); }
void clfxtr(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB94B, r1, m3, r2, m4); }
void clgdbr(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB3AD, r1, m3, r2, m4); }
void clgdtr(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB942, r1, m3, r2, m4); }
void clgebr(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB3AC, r1, m3, r2, m4); }
void clgxbr(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB3AE, r1, m3, r2, m4); }
void clgxtr(const GPReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB94A, r1, m3, r2, m4); }
void cxfbra(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB396, r1, m3, r2, m4); }
void cxftr(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB959, r1, m3, r2, m4); }
void cxgbra(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB3A6, r1, m3, r2, m4); }
void cxgtra(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB3F9, r1, m3, r2, m4); }
void cxlfbr(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB392, r1, m3, r2, m4); }
void cxlftr(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB95B, r1, m3, r2, m4); }
void cxlgbr(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB3A2, r1, m3, r2, m4); }
void cxlgtr(const FReg& r1, const int& m3, const GPReg& r2, const int& m4 ){ opRRF_E(0xB95A, r1, m3, r2, m4); }
void fidbra(const FReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB35F, r1, m3, r2, m4); }
void fidtr(const FReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB3D7, r1, m3, r2, m4); }
void fiebra(const FReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB357, r1, m3, r2, m4); }
void fixbra(const FReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB347, r1, m3, r2, m4); }
void fixtr(const FReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB3DF, r1, m3, r2, m4); }
void ldxbra(const FReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB345, r1, m3, r2, m4); }
void ldxtr(const FReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB3DD, r1, m3, r2, m4); }
void ledbra(const FReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB344, r1, m3, r2, m4); }
void ledtr(const FReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB3D5, r1, m3, r2, m4); }
void lexbra(const FReg& r1, const int& m3, const FReg& r2, const int& m4 ){ opRRF_E(0xB346, r1, m3, r2, m4); }
void mvck(const AddrDRB& drb1, const AddrDB& db2, const GPReg& r3 ){ opSS_D(0xD9, drb1, db2, r3); }
void mvcp(const AddrDRB& drb1, const AddrDB& db2, const GPReg& r3 ){ opSS_D(0xDA, drb1, db2, r3); }
void mvcs(const AddrDRB& drb1, const AddrDB& db2, const GPReg& r3 ){ opSS_D(0xDB, drb1, db2, r3); }
void madbr(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB31E, r1, r3, r2); }
void madr(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB33E, r1, r3, r2); }
void maebr(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB30E, r1, r3, r2); }
void maer(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB32E, r1, r3, r2); }
void mayhr(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB33C, r1, r3, r2); }
void maylr(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB338, r1, r3, r2); }
void mayr(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB33A, r1, r3, r2); }
void msdbr(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB31F, r1, r3, r2); }
void msdr(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB33F, r1, r3, r2); }
void msebr(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB30F, r1, r3, r2); }
void mser(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB32F, r1, r3, r2); }
void myhr(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB33D, r1, r3, r2); }
void mylr(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB339, r1, r3, r2); }
void myr(const FReg& r1, const FReg& r3, const FReg& r2 ){ opRRD(0xB33B, r1, r3, r2); }
void mad(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED3E, r1, r3, dxb2); }
void madb(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED1E, r1, r3, dxb2); }
void mae(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED2E, r1, r3, dxb2); }
void maeb(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED0E, r1, r3, dxb2); }
void may(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED3A, r1, r3, dxb2); }
void mayh(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED3C, r1, r3, dxb2); }
void mayl(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED38, r1, r3, dxb2); }
void msd(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED3F, r1, r3, dxb2); }
void msdb(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED1F, r1, r3, dxb2); }
void mse(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED2F, r1, r3, dxb2); }
void mseb(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED0F, r1, r3, dxb2); }
void my(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED3B, r1, r3, dxb2); }
void myh(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED3D, r1, r3, dxb2); }
void myl(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED39, r1, r3, dxb2); }
void sldt(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED40, r1, r3, dxb2); }
void slxt(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED48, r1, r3, dxb2); }
void srdt(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED41, r1, r3, dxb2); }
void srxt(const FReg& r1, const FReg& r3, const AddrDXB& dxb2 ){ opRXF(0xED49, r1, r3, dxb2); }
void cdpt(const FReg& r1, const AddrDLB& dlb2, const int& m3 ){ opRSL_B(0xEDAE, r1, dlb2, m3); }
void cdzt(const FReg& r1, const AddrDLB& dlb2, const int& m3 ){ opRSL_B(0xEDAA, r1, dlb2, m3); }
void cpdt(const FReg& r1, const AddrDLB& dlb2, const int& m3 ){ opRSL_B(0xEDAC, r1, dlb2, m3); }
void cpxt(const FReg& r1, const AddrDLB& dlb2, const int& m3 ){ opRSL_B(0xEDAD, r1, dlb2, m3); }
void cxpt(const FReg& r1, const AddrDLB& dlb2, const int& m3 ){ opRSL_B(0xEDAF, r1, dlb2, m3); }
void cxzt(const FReg& r1, const AddrDLB& dlb2, const int& m3 ){ opRSL_B(0xEDAB, r1, dlb2, m3); }
void czdt(const FReg& r1, const AddrDLB& dlb2, const int& m3 ){ opRSL_B(0xEDA8, r1, dlb2, m3); }
void czxt(const FReg& r1, const AddrDLB& dlb2, const int& m3 ){ opRSL_B(0xEDA9, r1, dlb2, m3); }
void csdtr(const GPReg& r1, const FReg& r2, const int& m4 ){ opRRF_D(0xB3E3, r1, r2, m4); }
void csxtr(const FReg& r1, const FReg& r2, const int& m4 ){ opRRF_D(0xB3EB, r1, r2, m4); }
void ldetr(const FReg& r1, const FReg& r2, const int& m4 ){ opRRF_D(0xB3D4, r1, r2, m4); }
void lxdtr(const FReg& r1, const FReg& r2, const int& m4 ){ opRRF_D(0xB3DC, r1, r2, m4); }
void vbperm(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE785, v1, v2, v3); }
void vcksm(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE766, v1, v2, v3); }
void vn(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE768, v1, v2, v3); }
void vnc(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE769, v1, v2, v3); }
void vnn(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE76E, v1, v2, v3); }
void vno(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE76B, v1, v2, v3); }
void vnx(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE76C, v1, v2, v3); }
void vo(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE76A, v1, v2, v3); }
void voc(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE76F, v1, v2, v3); }
void vsl(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE774, v1, v2, v3); }
void vslb(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE775, v1, v2, v3); }
void vsra(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE77E, v1, v2, v3); }
void vsrab(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE77F, v1, v2, v3); }
void vsrl(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE77C, v1, v2, v3); }
void vsrlb(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE77D, v1, v2, v3); }
void vx(const VReg& v1, const VReg& v2, const VReg& v3 ){ opVRR_C(0xE76D, v1, v2, v3); }
void va(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7F3, v1, v2, v3, m4); }
void vacc(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7F1, v1, v2, v3, m4); }
void vavg(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7F2, v1, v2, v3, m4); }
void vavgl(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7F0, v1, v2, v3, m4); }
void verllv(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE773, v1, v2, v3, m4); }
void veslv(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE770, v1, v2, v3, m4); }
void vesrav(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE77A, v1, v2, v3, m4); }
void vesrlv(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE778, v1, v2, v3, m4); }
void vgfm(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7B4, v1, v2, v3, m4); }
void vme(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7A6, v1, v2, v3, m4); }
void vmh(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7A3, v1, v2, v3, m4); }
void vml(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7A2, v1, v2, v3, m4); }
void vmle(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7A4, v1, v2, v3, m4); }
void vmlh(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7A1, v1, v2, v3, m4); }
void vmlo(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7A5, v1, v2, v3, m4); }
void vmn(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7FE, v1, v2, v3, m4); }
void vmnl(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7FC, v1, v2, v3, m4); }
void vmo(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7A7, v1, v2, v3, m4); }
void vmrh(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE761, v1, v2, v3, m4); }
void vmrl(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE760, v1, v2, v3, m4); }
void vmx(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7FF, v1, v2, v3, m4); }
void vmxl(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7FD, v1, v2, v3, m4); }
void vpdi(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE784, v1, v2, v3, m4); }
void vpk(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE794, v1, v2, v3, m4); }
void vs(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7F7, v1, v2, v3, m4); }
void vscbi(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE7F5, v1, v2, v3, m4); }
void vsum(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE764, v1, v2, v3, m4); }
void vsumg(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE765, v1, v2, v3, m4); }
void vsumq(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){ opVRR_C(0xE767, v1, v2, v3, m4); }
void vfa(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5 ){ opVRR_C(0xE7E3, v1, v2, v3, m4, m5); }
void vfd(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5 ){ opVRR_C(0xE7E5, v1, v2, v3, m4, m5); }
void vfm(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5 ){ opVRR_C(0xE7E7, v1, v2, v3, m4, m5); }
void vfs(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5 ){ opVRR_C(0xE7E2, v1, v2, v3, m4, m5); }
void vfce(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5, const int& m6 ){ opVRR_C(0xE7E8, v1, v2, v3, m4, m5, m6); }
void vfch(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5, const int& m6 ){ opVRR_C(0xE7EB, v1, v2, v3, m4, m5, m6); }
void vfche(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5, const int& m6 ){ opVRR_C(0xE7EA, v1, v2, v3, m4, m5, m6); }
void vfmax(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5, const int& m6 ){ opVRR_C(0xE7EF, v1, v2, v3, m4, m5, m6); }
void vfmin(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5, const int& m6 ){ opVRR_C(0xE7EE, v1, v2, v3, m4, m5, m6); }
void vgef(const VReg& v1, const AddrDVB& dvb2, const int& m3 ){ opVRV(0xE713, v1, dvb2, m3); }
void vgeg(const VReg& v1, const AddrDVB& dvb2, const int& m3 ){ opVRV(0xE712, v1, dvb2, m3); }
void vscef(const VReg& v1, const AddrDVB& dvb2, const int& m3 ){ opVRV(0xE71B, v1, dvb2, m3); }
void vsceg(const VReg& v1, const AddrDVB& dvb2, const int& m3 ){ opVRV(0xE71A, v1, dvb2, m3); }
void vgbm(const VReg& v1, const int& i2 ){ opVRI_A(0xE744, v1, i2); }
void vleib(const VReg& v1, const int& i2, const int& m3 ){ opVRI_A(0xE740, v1, i2, m3); }
void vleif(const VReg& v1, const int& i2, const int& m3 ){ opVRI_A(0xE743, v1, i2, m3); }
void vleig(const VReg& v1, const int& i2, const int& m3 ){ opVRI_A(0xE742, v1, i2, m3); }
void vleih(const VReg& v1, const int& i2, const int& m3 ){ opVRI_A(0xE741, v1, i2, m3); }
void vrepi(const VReg& v1, const int& i2, const int& m3 ){ opVRI_A(0xE745, v1, i2, m3); }
void vgm(const VReg& v1, const int& i2, const int& i3, const int& m4 ){ opVRI_B(0xE746, v1, i2, i3, m4); }
void vl(const VReg& v1, const AddrDXB& dxb2, const int& m3= {}  ){ opVRX(0xE706, v1, dxb2, m3); }
void vst(const VReg& v1, const AddrDXB& dxb2, const int& m3= {}  ){ opVRX(0xE70E, v1, dxb2, m3); }
void vlbb(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE707, v1, dxb2, m3); }
void vlbr(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE606, v1, dxb2, m3); }
void vlbrrep(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE605, v1, dxb2, m3); }
void vleb(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE700, v1, dxb2, m3); }
void vlebrf(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE603, v1, dxb2, m3); }
void vlebrg(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE602, v1, dxb2, m3); }
void vlebrh(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE601, v1, dxb2, m3); }
void vlef(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE703, v1, dxb2, m3); }
void vleg(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE702, v1, dxb2, m3); }
void vleh(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE701, v1, dxb2, m3); }
void vler(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE607, v1, dxb2, m3); }
void vllebrz(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE604, v1, dxb2, m3); }
void vllez(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE704, v1, dxb2, m3); }
void vlrep(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE705, v1, dxb2, m3); }
void vstbr(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE60E, v1, dxb2, m3); }
void vsteb(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE708, v1, dxb2, m3); }
void vstebrf(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE60B, v1, dxb2, m3); }
void vstebrg(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE60A, v1, dxb2, m3); }
void vstebrh(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE609, v1, dxb2, m3); }
void vstef(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE70B, v1, dxb2, m3); }
void vsteg(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE70A, v1, dxb2, m3); }
void vsteh(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE709, v1, dxb2, m3); }
void vster(const VReg& v1, const AddrDXB& dxb2, const int& m3 ){ opVRX(0xE60F, v1, dxb2, m3); }
void vlr(const VReg& v1, const VReg& v2 ){ opVRR_A(0xE756, v1, v2); }
void vtm(const VReg& v1, const VReg& v2 ){ opVRR_A(0xE7D8, v1, v2); }
void vclz(const VReg& v1, const VReg& v2, const int& m3 ){ opVRR_A(0xE753, v1, v2, m3); }
void vctz(const VReg& v1, const VReg& v2, const int& m3 ){ opVRR_A(0xE752, v1, v2, m3); }
void vec(const VReg& v1, const VReg& v2, const int& m3 ){ opVRR_A(0xE7DB, v1, v2, m3); }
void vecl(const VReg& v1, const VReg& v2, const int& m3 ){ opVRR_A(0xE7D9, v1, v2, m3); }
void vlc(const VReg& v1, const VReg& v2, const int& m3 ){ opVRR_A(0xE7DE, v1, v2, m3); }
void vlp(const VReg& v1, const VReg& v2, const int& m3 ){ opVRR_A(0xE7DF, v1, v2, m3); }
void vpopct(const VReg& v1, const VReg& v2, const int& m3 ){ opVRR_A(0xE750, v1, v2, m3); }
void vseg(const VReg& v1, const VReg& v2, const int& m3 ){ opVRR_A(0xE75F, v1, v2, m3); }
void vuph(const VReg& v1, const VReg& v2, const int& m3 ){ opVRR_A(0xE7D7, v1, v2, m3); }
void vupl(const VReg& v1, const VReg& v2, const int& m3 ){ opVRR_A(0xE7D6, v1, v2, m3); }
void vuplh(const VReg& v1, const VReg& v2, const int& m3 ){ opVRR_A(0xE7D5, v1, v2, m3); }
void vupll(const VReg& v1, const VReg& v2, const int& m3 ){ opVRR_A(0xE7D4, v1, v2, m3); }
void vistr(const VReg& v1, const VReg& v2, const int& m3, const int& m5= {}  ){ opVRR_A(0xE75C, v1, v2, m3, 0, m5); }
void vfll(const VReg& v1, const VReg& v2, const int& m3, const int& m4 ){ opVRR_A(0xE7C4, v1, v2, m3, m4, 0); }
void vfsq(const VReg& v1, const VReg& v2, const int& m3, const int& m4 ){ opVRR_A(0xE7CE, v1, v2, m3, m4, 0); }
void wfc(const VReg& v1, const VReg& v2, const int& m3, const int& m4 ){ opVRR_A(0xE7CB, v1, v2, m3, m4, 0); }
void wfk(const VReg& v1, const VReg& v2, const int& m3, const int& m4 ){ opVRR_A(0xE7CA, v1, v2, m3, m4, 0); }
void vcfpl(const VReg& v1, const VReg& v2, const int& m3, const int& m4, const int& m5 ){ opVRR_A(0xE7C1, v1, v2, m3, m4, m5); }
void vcfps(const VReg& v1, const VReg& v2, const int& m3, const int& m4, const int& m5 ){ opVRR_A(0xE7C3, v1, v2, m3, m4, m5); }
void vclfp(const VReg& v1, const VReg& v2, const int& m3, const int& m4, const int& m5 ){ opVRR_A(0xE7C0, v1, v2, m3, m4, m5); }
void vcsfp(const VReg& v1, const VReg& v2, const int& m3, const int& m4, const int& m5 ){ opVRR_A(0xE7C2, v1, v2, m3, m4, m5); }
void vfi(const VReg& v1, const VReg& v2, const int& m3, const int& m4, const int& m5 ){ opVRR_A(0xE7C7, v1, v2, m3, m4, m5); }
void vflr(const VReg& v1, const VReg& v2, const int& m3, const int& m4, const int& m5 ){ opVRR_A(0xE7C5, v1, v2, m3, m4, m5); }
void vfpso(const VReg& v1, const VReg& v2, const int& m3, const int& m4, const int& m5 ){ opVRR_A(0xE7CC, v1, v2, m3, m4, m5); }
void vlgv(const GPReg& r1, const VReg& v3, const AddrDB& db2, const int& m4 ){ opVRS_C(0xE721, r1, v3, db2, m4); }
void vlm(const VReg& v1, const VReg& v3, const AddrDB& db2, const int& m4= {}  ){ opVRS_A(0xE736, v1, v3, db2, m4); }
void vstm(const VReg& v1, const VReg& v3, const AddrDB& db2, const int& m4= {}  ){ opVRS_A(0xE73E, v1, v3, db2, m4); }
void verll(const VReg& v1, const VReg& v3, const AddrDB& db2, const int& m4 ){ opVRS_A(0xE733, v1, v3, db2, m4); }
void vesl(const VReg& v1, const VReg& v3, const AddrDB& db2, const int& m4 ){ opVRS_A(0xE730, v1, v3, db2, m4); }
void vesra(const VReg& v1, const VReg& v3, const AddrDB& db2, const int& m4 ){ opVRS_A(0xE73A, v1, v3, db2, m4); }
void vesrl(const VReg& v1, const VReg& v3, const AddrDB& db2, const int& m4 ){ opVRS_A(0xE738, v1, v3, db2, m4); }
void vlrlr(const VReg& v1, const GPReg& r3, const AddrDB& db2 ){ opVRS_D(0xE637, v1, r3, db2); }
void vstrlr(const VReg& v1, const GPReg& r3, const AddrDB& db2 ){ opVRS_D(0xE63F, v1, r3, db2); }
void vlrl(const VReg& v1, const AddrDB& db2, const int& i3 ){ opVSI(0xE635, v1, db2, i3); }
void vpkz(const VReg& v1, const AddrDB& db2, const int& i3 ){ opVSI(0xE634, v1, db2, i3); }
void vstrl(const VReg& v1, const AddrDB& db2, const int& i3 ){ opVSI(0xE63D, v1, db2, i3); }
void vupkz(const VReg& v1, const AddrDB& db2, const int& i3 ){ opVSI(0xE63C, v1, db2, i3); }
void vlvg(const VReg& v1, const GPReg& r3, const AddrDB& db2, const int& m4 ){ opVRS_B(0xE722, v1, r3, db2, m4); }
void vll(const VReg& v1, const GPReg& r3, const AddrDB& db2 ){ opVRS_B(0xE737, v1, r3, db2); }
void vstl(const VReg& v1, const GPReg& r3, const AddrDB& db2 ){ opVRS_B(0xE73F, v1, r3, db2); }
void vlvgp(const VReg& v1, const GPReg& r2, const GPReg& r3 ){ opVRR_F(0xE762, v1, r2, r3); }
void vceq(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5 ){ opVRR_B(0xE7F8, v1, v2, v3, m4, m5); }
void vch(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5 ){ opVRR_B(0xE7FB, v1, v2, v3, m4, m5); }
void vchl(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5 ){ opVRR_B(0xE7F9, v1, v2, v3, m4, m5); }
void vpkls(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5 ){ opVRR_B(0xE795, v1, v2, v3, m4, m5); }
void vpks(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5 ){ opVRR_B(0xE797, v1, v2, v3, m4, m5); }
void vfae(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5= {}  ){ opVRR_B(0xE782, v1, v2, v3, m4, m5); }
void vfee(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5= {}  ){ opVRR_B(0xE780, v1, v2, v3, m4, m5); }
void vfene(const VReg& v1, const VReg& v2, const VReg& v3, const int& m4, const int& m5= {}  ){ opVRR_B(0xE781, v1, v2, v3, m4, m5); }
void vperm(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ opVRR_E(0xE78C, v1, v2, v3, v4); }
void vsel(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ opVRR_E(0xE78D, v1, v2, v3, v4); }
void vfma(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5, const int& m6 ){ opVRR_E(0xE78F, v1, v2, v3, v4, m5, m6); }
void vfms(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5, const int& m6 ){ opVRR_E(0xE78E, v1, v2, v3, v4, m5, m6); }
void vfnma(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5, const int& m6 ){ opVRR_E(0xE79F, v1, v2, v3, v4, m5, m6); }
void vfnms(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5, const int& m6 ){ opVRR_E(0xE79E, v1, v2, v3, v4, m5, m6); }
void vrep(const VReg& v1, const VReg& v3, const int& i2, const int& m4 ){ opVRI_C(0xE74D, v1, v3, i2, m4); }
void vac(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5 ){ opVRR_D(0xE7BB, v1, v2, v3, v4, m5); }
void vaccc(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5 ){ opVRR_D(0xE7B9, v1, v2, v3, v4, m5); }
void vgfma(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5 ){ opVRR_D(0xE7BC, v1, v2, v3, v4, m5); }
void vmae(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5 ){ opVRR_D(0xE7AE, v1, v2, v3, v4, m5); }
void vmah(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5 ){ opVRR_D(0xE7AB, v1, v2, v3, v4, m5); }
void vmal(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5 ){ opVRR_D(0xE7AA, v1, v2, v3, v4, m5); }
void vmale(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5 ){ opVRR_D(0xE7AC, v1, v2, v3, v4, m5); }
void vmalh(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5 ){ opVRR_D(0xE7A9, v1, v2, v3, v4, m5); }
void vmalo(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5 ){ opVRR_D(0xE7AD, v1, v2, v3, v4, m5); }
void vmao(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5 ){ opVRR_D(0xE7AF, v1, v2, v3, v4, m5); }
void vsbcbi(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5 ){ opVRR_D(0xE7BD, v1, v2, v3, v4, m5); }
void vsbi(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5 ){ opVRR_D(0xE7BF, v1, v2, v3, v4, m5); }
void vmsl(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5, const int& m6 ){ opVRR_D(0xE7B8, v1, v2, v3, v4, m5, m6); }
void vstrc(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5, const int& m6= {}  ){ opVRR_D(0xE78A, v1, v2, v3, v4, m5, m6); }
void vstrs(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5, const int& m6= {}  ){ opVRR_D(0xE78B, v1, v2, v3, v4, m5, m6); }
void verim(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4, const int& m5 ){ opVRI_D(0xE772, v1, v2, v3, i4, m5); }
void vsld(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4 ){ opVRI_D(0xE786, v1, v2, v3, i4); }
void vsldb(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4 ){ opVRI_D(0xE777, v1, v2, v3, i4); }
void vsrd(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4 ){ opVRI_D(0xE787, v1, v2, v3, i4); }
void vftci(const VReg& v1, const VReg& v2, const int& i3, const int& m4, const int& m5 ){ opVRI_E(0xE74A, v1, v2, i3, m4, m5); }
void vap(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4, const int& m5 ){ opVRI_F(0xE671, v1, v2, v3, i4, m5); }
void vdp(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4, const int& m5 ){ opVRI_F(0xE67A, v1, v2, v3, i4, m5); }
void vmp(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4, const int& m5 ){ opVRI_F(0xE678, v1, v2, v3, i4, m5); }
void vmsp(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4, const int& m5 ){ opVRI_F(0xE679, v1, v2, v3, i4, m5); }
void vrp(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4, const int& m5 ){ opVRI_F(0xE67B, v1, v2, v3, i4, m5); }
void vsdp(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4, const int& m5 ){ opVRI_F(0xE67E, v1, v2, v3, i4, m5); }
void vsp(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4, const int& m5 ){ opVRI_F(0xE673, v1, v2, v3, i4, m5); }
void vcp(const VReg& v1, const VReg& v2, const int& m3 ){ opVRR_H(0xE677, v1, v2, m3); }
void vcvb(const GPReg& r1, const VReg& v2, const int& m3, const int& m4= {}  ){ opVRR_I(0xE650, r1, v2, m3, m4); }
void vcvbg(const GPReg& r1, const VReg& v2, const int& m3, const int& m4= {}  ){ opVRR_I(0xE652, r1, v2, m3, m4); }
void vcvd(const VReg& v1, const GPReg& r2, const int& i3, const int& m4 ){ opVRI_I(0xE658, v1, r2, i3, m4); }
void vcvdg(const VReg& v1, const GPReg& r2, const int& i3, const int& m4 ){ opVRI_I(0xE65A, v1, r2, i3, m4); }
void vlip(const VReg& v1, const int& i2, const int& i3 ){ opVRI_H(0xE649, v1, i2, i3); }
void vpsop(const VReg& v1, const VReg& v2, const int& i3, const int& i4, const int& m5 ){ opVRI_G(0xE65B, v1, v2, i3, i4, m5); }
void vsrp(const VReg& v1, const VReg& v2, const int& i3, const int& i4, const int& m5 ){ opVRI_G(0xE659, v1, v2, i3, i4, m5); }
void vtp(const VReg& v1 ){ opVRR_G(0xE65F, v1); }
// Extensiones 1: 
void notr(const GPReg& r1, const GPReg& r2 ){ nork(r1, r2, r2); }
void notgr(const GPReg& r1, const GPReg& r2 ){ nogrk(r1, r2, r2); }
void vzero(const VReg& v1 ){ vgbm(v1, 0); }
void vone(const VReg& v1 ){ vgbm(v1, 0xffff); }
void vgmb(const VReg& v1, const int& i2, const int& i3 ){ vgm(v1, i2, i3, 0); }
void vgmh(const VReg& v1, const int& i2, const int& i3 ){ vgm(v1, i2, i3, 1); }
void vgmf(const VReg& v1, const int& i2, const int& i3 ){ vgm(v1, i2, i3, 2); }
void vgmg(const VReg& v1, const int& i2, const int& i3 ){ vgm(v1, i2, i3, 3); }
void vlrepb(const VReg& v1, const AddrDXB& dxb2 ){ vlrep(v1, dxb2, 0); }
void vlreph(const VReg& v1, const AddrDXB& dxb2 ){ vlrep(v1, dxb2, 1); }
void vlrepf(const VReg& v1, const AddrDXB& dxb2 ){ vlrep(v1, dxb2, 2); }
void vlrepg(const VReg& v1, const AddrDXB& dxb2 ){ vlrep(v1, dxb2, 3); }
void vlbrreph(const VReg& v1, const AddrDXB& dxb2 ){ vlbrrep(v1, dxb2, 1); }
void vlbrrepf(const VReg& v1, const AddrDXB& dxb2 ){ vlbrrep(v1, dxb2, 2); }
void vlbrrepg(const VReg& v1, const AddrDXB& dxb2 ){ vlbrrep(v1, dxb2, 3); }
void vllebrzh(const VReg& v1, const AddrDXB& dxb2 ){ vllebrz(v1, dxb2, 1); }
void vllebrzf(const VReg& v1, const AddrDXB& dxb2 ){ vllebrz(v1, dxb2, 2); }
void vllebrzg(const VReg& v1, const AddrDXB& dxb2 ){ vllebrz(v1, dxb2, 3); }
void vllebrze(const VReg& v1, const AddrDXB& dxb2 ){ vllebrz(v1, dxb2, 6); }
void ldrv(const VReg& v1, const AddrDXB& dxb2 ){ vllebrz(v1, dxb2, 3); }
void lerv(const VReg& v1, const AddrDXB& dxb2 ){ vllebrz(v1, dxb2, 6); }
void vlbrh(const VReg& v1, const AddrDXB& dxb2 ){ vlbr(v1, dxb2, 1); }
void vlbrf(const VReg& v1, const AddrDXB& dxb2 ){ vlbr(v1, dxb2, 2); }
void vlbrg(const VReg& v1, const AddrDXB& dxb2 ){ vlbr(v1, dxb2, 3); }
void vlbrq(const VReg& v1, const AddrDXB& dxb2 ){ vlbr(v1, dxb2, 4); }
void vlerh(const VReg& v1, const AddrDXB& dxb2 ){ vler(v1, dxb2, 1); }
void vlerf(const VReg& v1, const AddrDXB& dxb2 ){ vler(v1, dxb2, 2); }
void vlerg(const VReg& v1, const AddrDXB& dxb2 ){ vler(v1, dxb2, 3); }
void vlgvb(const GPReg& r1, const VReg& v3, const AddrDB& db2 ){ vlgv(r1, v3, db2, 0); }
void vlgvh(const GPReg& r1, const VReg& v3, const AddrDB& db2 ){ vlgv(r1, v3, db2, 1); }
void vlgvf(const GPReg& r1, const VReg& v3, const AddrDB& db2 ){ vlgv(r1, v3, db2, 2); }
void vlgvg(const GPReg& r1, const VReg& v3, const AddrDB& db2 ){ vlgv(r1, v3, db2, 3); }
void vllezb(const VReg& v1, const AddrDXB& dxb2 ){ vllez(v1, dxb2, 0); }
void vllezh(const VReg& v1, const AddrDXB& dxb2 ){ vllez(v1, dxb2, 1); }
void vllezf(const VReg& v1, const AddrDXB& dxb2 ){ vllez(v1, dxb2, 2); }
void vllezg(const VReg& v1, const AddrDXB& dxb2 ){ vllez(v1, dxb2, 3); }
void vllezlf(const VReg& v1, const AddrDXB& dxb2 ){ vllez(v1, dxb2, 6); }
void vlvgb(const VReg& v1, const GPReg& r3, const AddrDB& db2 ){ vlvg(v1, r3, db2, 0); }
void vlvgh(const VReg& v1, const GPReg& r3, const AddrDB& db2 ){ vlvg(v1, r3, db2, 1); }
void vlvgf(const VReg& v1, const GPReg& r3, const AddrDB& db2 ){ vlvg(v1, r3, db2, 2); }
void vlvgg(const VReg& v1, const GPReg& r3, const AddrDB& db2 ){ vlvg(v1, r3, db2, 3); }
void vmrhb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmrh(v1, v2, v3, 0); }
void vmrhh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmrh(v1, v2, v3, 1); }
void vmrhf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmrh(v1, v2, v3, 2); }
void vmrhg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmrh(v1, v2, v3, 3); }
void vmrlb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmrl(v1, v2, v3, 0); }
void vmrlh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmrl(v1, v2, v3, 1); }
void vmrlf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmrl(v1, v2, v3, 2); }
void vmrlg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmrl(v1, v2, v3, 3); }
void vpkh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vpk(v1, v2, v3, 1); }
void vpkf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vpk(v1, v2, v3, 2); }
void vpkg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vpk(v1, v2, v3, 3); }
void vpksg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vpks(v1, v2, v3, 3, 0); }
void vpkshs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vpks(v1, v2, v3, 1, 1); }
void vpksfs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vpks(v1, v2, v3, 2, 1); }
void vpksgs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vpks(v1, v2, v3, 3, 1); }
void vpklsh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vpkls(v1, v2, v3, 1, 0); }
void vpklsf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vpkls(v1, v2, v3, 2, 0); }
void vpklsg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vpkls(v1, v2, v3, 3, 0); }
void vpklshs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vpkls(v1, v2, v3, 1, 1); }
void vpklsfs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vpkls(v1, v2, v3, 2, 1); }
void vpklsgs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vpkls(v1, v2, v3, 3, 1); }
void vrepb(const VReg& v1, const VReg& v3, const int& i2 ){ vrep(v1, v3, i2, 0); }
void vreph(const VReg& v1, const VReg& v3, const int& i2 ){ vrep(v1, v3, i2, 1); }
void vrepf(const VReg& v1, const VReg& v3, const int& i2 ){ vrep(v1, v3, i2, 2); }
void vrepg(const VReg& v1, const VReg& v3, const int& i2 ){ vrep(v1, v3, i2, 3); }
void vrepib(const VReg& v1, const int& i2 ){ vrepi(v1, i2, 0); }
void vrepih(const VReg& v1, const int& i2 ){ vrepi(v1, i2, 1); }
void vrepif(const VReg& v1, const int& i2 ){ vrepi(v1, i2, 2); }
void vrepig(const VReg& v1, const int& i2 ){ vrepi(v1, i2, 3); }
void vsegb(const VReg& v1, const VReg& v2 ){ vseg(v1, v2, 0); }
void vsegh(const VReg& v1, const VReg& v2 ){ vseg(v1, v2, 1); }
void vsegf(const VReg& v1, const VReg& v2 ){ vseg(v1, v2, 2); }
void sterv(const VReg& v1, const AddrDXB& dxb2 ){ vstebrf(v1, dxb2, 0); }
void stdrv(const VReg& v1, const AddrDXB& dxb2 ){ vstebrg(v1, dxb2, 0); }
void vstbrh(const VReg& v1, const AddrDXB& dxb2 ){ vstbr(v1, dxb2, 1); }
void vstbrf(const VReg& v1, const AddrDXB& dxb2 ){ vstbr(v1, dxb2, 2); }
void vstbrg(const VReg& v1, const AddrDXB& dxb2 ){ vstbr(v1, dxb2, 3); }
void vstbrq(const VReg& v1, const AddrDXB& dxb2 ){ vstbr(v1, dxb2, 4); }
void vsterh(const VReg& v1, const AddrDXB& dxb2 ){ vster(v1, dxb2, 1); }
void vsterf(const VReg& v1, const AddrDXB& dxb2 ){ vster(v1, dxb2, 2); }
void vsterg(const VReg& v1, const AddrDXB& dxb2 ){ vster(v1, dxb2, 3); }
void vuphb(const VReg& v1, const VReg& v2 ){ vuph(v1, v2, 0); }
void vuphh(const VReg& v1, const VReg& v2 ){ vuph(v1, v2, 1); }
void vuphf(const VReg& v1, const VReg& v2 ){ vuph(v1, v2, 2); }
void vuplhb(const VReg& v1, const VReg& v2 ){ vuplh(v1, v2, 0); }
void vuplhh(const VReg& v1, const VReg& v2 ){ vuplh(v1, v2, 1); }
void vuplhf(const VReg& v1, const VReg& v2 ){ vuplh(v1, v2, 2); }
void vuplb(const VReg& v1, const VReg& v2 ){ vupl(v1, v2, 0); }
void vuplhw(const VReg& v1, const VReg& v2 ){ vupl(v1, v2, 1); }
void vuplf(const VReg& v1, const VReg& v2 ){ vupl(v1, v2, 2); }
void vupllb(const VReg& v1, const VReg& v2 ){ vupll(v1, v2, 0); }
void vupllh(const VReg& v1, const VReg& v2 ){ vupll(v1, v2, 1); }
void vupllf(const VReg& v1, const VReg& v2 ){ vupll(v1, v2, 2); }
void vab(const VReg& v1, const VReg& v2, const VReg& v3 ){ va(v1, v2, v3, 0); }
void vah(const VReg& v1, const VReg& v2, const VReg& v3 ){ va(v1, v2, v3, 1); }
void vaf(const VReg& v1, const VReg& v2, const VReg& v3 ){ va(v1, v2, v3, 2); }
void vag(const VReg& v1, const VReg& v2, const VReg& v3 ){ va(v1, v2, v3, 3); }
void vaq(const VReg& v1, const VReg& v2, const VReg& v3 ){ va(v1, v2, v3, 4); }
void vaccb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vacc(v1, v2, v3, 0); }
void vacch(const VReg& v1, const VReg& v2, const VReg& v3 ){ vacc(v1, v2, v3, 1); }
void vaccf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vacc(v1, v2, v3, 2); }
void vaccg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vacc(v1, v2, v3, 3); }
void vaccq(const VReg& v1, const VReg& v2, const VReg& v3 ){ vacc(v1, v2, v3, 4); }
void vacq(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vac(v1, v2, v3, v4, 4); }
void vacccq(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vaccc(v1, v2, v3, v4, 4); }
void vavgb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vavg(v1, v2, v3, 0); }
void vavgh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vavg(v1, v2, v3, 1); }
void vavgf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vavg(v1, v2, v3, 2); }
void vavgg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vavg(v1, v2, v3, 3); }
void vavglb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vavgl(v1, v2, v3, 0); }
void vavglh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vavgl(v1, v2, v3, 1); }
void vavglf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vavgl(v1, v2, v3, 2); }
void vavglg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vavgl(v1, v2, v3, 3); }
void vecb(const VReg& v1, const VReg& v2 ){ vec(v1, v2, 0); }
void vech(const VReg& v1, const VReg& v2 ){ vec(v1, v2, 1); }
void vecf(const VReg& v1, const VReg& v2 ){ vec(v1, v2, 2); }
void vecg(const VReg& v1, const VReg& v2 ){ vec(v1, v2, 3); }
void veclb(const VReg& v1, const VReg& v2 ){ vecl(v1, v2, 0); }
void veclh(const VReg& v1, const VReg& v2 ){ vecl(v1, v2, 1); }
void veclf(const VReg& v1, const VReg& v2 ){ vecl(v1, v2, 2); }
void veclg(const VReg& v1, const VReg& v2 ){ vecl(v1, v2, 3); }
void vceqb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vceq(v1, v2, v3, 0, 0); }
void vceqh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vceq(v1, v2, v3, 1, 0); }
void vceqf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vceq(v1, v2, v3, 2, 0); }
void vceqg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vceq(v1, v2, v3, 3, 0); }
void vceqbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vceq(v1, v2, v3, 0, 1); }
void vceqhs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vceq(v1, v2, v3, 1, 1); }
void vceqfs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vceq(v1, v2, v3, 2, 1); }
void vceqgs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vceq(v1, v2, v3, 3, 1); }
void vchb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vch(v1, v2, v3, 0, 0); }
void vchh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vch(v1, v2, v3, 1, 0); }
void vchf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vch(v1, v2, v3, 2, 0); }
void vchg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vch(v1, v2, v3, 3, 0); }
void vchbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vch(v1, v2, v3, 0, 1); }
void vchhs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vch(v1, v2, v3, 1, 1); }
void vchfs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vch(v1, v2, v3, 2, 1); }
void vchgs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vch(v1, v2, v3, 3, 1); }
void vchlb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vchl(v1, v2, v3, 0, 0); }
void vchlh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vchl(v1, v2, v3, 1, 0); }
void vchlf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vchl(v1, v2, v3, 2, 0); }
void vchlg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vchl(v1, v2, v3, 3, 0); }
void vchlbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vchl(v1, v2, v3, 0, 1); }
void vchlhs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vchl(v1, v2, v3, 1, 1); }
void vchlfs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vchl(v1, v2, v3, 2, 1); }
void vchlgs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vchl(v1, v2, v3, 3, 1); }
void vclzb(const VReg& v1, const VReg& v2 ){ vclz(v1, v2, 0); }
void vclzh(const VReg& v1, const VReg& v2 ){ vclz(v1, v2, 1); }
void vclzf(const VReg& v1, const VReg& v2 ){ vclz(v1, v2, 2); }
void vclzg(const VReg& v1, const VReg& v2 ){ vclz(v1, v2, 3); }
void vctzb(const VReg& v1, const VReg& v2 ){ vctz(v1, v2, 0); }
void vctzh(const VReg& v1, const VReg& v2 ){ vctz(v1, v2, 1); }
void vctzf(const VReg& v1, const VReg& v2 ){ vctz(v1, v2, 2); }
void vctzg(const VReg& v1, const VReg& v2 ){ vctz(v1, v2, 3); }
void vgfmb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vgfm(v1, v2, v3, 0); }
void vgfmh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vgfm(v1, v2, v3, 1); }
void vgfmf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vgfm(v1, v2, v3, 2); }
void vgfmg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vgfm(v1, v2, v3, 3); }
void vgfmab(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vgfma(v1, v2, v3, v4, 0); }
void vgfmah(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vgfma(v1, v2, v3, v4, 1); }
void vgfmaf(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vgfma(v1, v2, v3, v4, 2); }
void vgfmag(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vgfma(v1, v2, v3, v4, 3); }
void vlcb(const VReg& v1, const VReg& v2 ){ vlc(v1, v2, 0); }
void vlch(const VReg& v1, const VReg& v2 ){ vlc(v1, v2, 1); }
void vlcf(const VReg& v1, const VReg& v2 ){ vlc(v1, v2, 2); }
void vlcg(const VReg& v1, const VReg& v2 ){ vlc(v1, v2, 3); }
void vlpb(const VReg& v1, const VReg& v2 ){ vlp(v1, v2, 0); }
void vlph(const VReg& v1, const VReg& v2 ){ vlp(v1, v2, 1); }
void vlpf(const VReg& v1, const VReg& v2 ){ vlp(v1, v2, 2); }
void vlpg(const VReg& v1, const VReg& v2 ){ vlp(v1, v2, 3); }
void vmxb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmx(v1, v2, v3, 0); }
void vmxh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmx(v1, v2, v3, 1); }
void vmxf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmx(v1, v2, v3, 2); }
void vmxg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmx(v1, v2, v3, 3); }
void vmxlb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmxl(v1, v2, v3, 0); }
void vmxlh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmxl(v1, v2, v3, 1); }
void vmxlf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmxl(v1, v2, v3, 2); }
void vmxlg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmxl(v1, v2, v3, 3); }
void vmnb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmn(v1, v2, v3, 0); }
void vmnh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmn(v1, v2, v3, 1); }
void vmnf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmn(v1, v2, v3, 2); }
void vmng(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmn(v1, v2, v3, 3); }
void vmnlb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmnl(v1, v2, v3, 0); }
void vmnlh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmnl(v1, v2, v3, 1); }
void vmnlf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmnl(v1, v2, v3, 2); }
void vmnlg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmnl(v1, v2, v3, 3); }
void vmalb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmal(v1, v2, v3, v4, 0); }
void vmalhw(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmal(v1, v2, v3, v4, 1); }
void vmalf(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmal(v1, v2, v3, v4, 2); }
void vmahb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmah(v1, v2, v3, v4, 0); }
void vmahh(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmah(v1, v2, v3, v4, 1); }
void vmahf(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmah(v1, v2, v3, v4, 2); }
void vmalhb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmalh(v1, v2, v3, v4, 0); }
void vmalhh(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmalh(v1, v2, v3, v4, 1); }
void vmalhf(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmalh(v1, v2, v3, v4, 2); }
void vmaeb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmae(v1, v2, v3, v4, 0); }
void vmaeh(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmae(v1, v2, v3, v4, 1); }
void vmaef(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmae(v1, v2, v3, v4, 2); }
void vmaleb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmale(v1, v2, v3, v4, 0); }
void vmaleh(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmale(v1, v2, v3, v4, 1); }
void vmalef(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmale(v1, v2, v3, v4, 2); }
void vmaob(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmao(v1, v2, v3, v4, 0); }
void vmaoh(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmao(v1, v2, v3, v4, 1); }
void vmaof(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmao(v1, v2, v3, v4, 2); }
void vmalob(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmalo(v1, v2, v3, v4, 0); }
void vmaloh(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmalo(v1, v2, v3, v4, 1); }
void vmalof(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vmalo(v1, v2, v3, v4, 2); }
void vmhb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmh(v1, v2, v3, 0); }
void vmhh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmh(v1, v2, v3, 1); }
void vmhf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmh(v1, v2, v3, 2); }
void vmlhb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmlh(v1, v2, v3, 0); }
void vmlhh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmlh(v1, v2, v3, 1); }
void vmlhf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmlh(v1, v2, v3, 2); }
void vmlb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vml(v1, v2, v3, 0); }
void vmlhw(const VReg& v1, const VReg& v2, const VReg& v3 ){ vml(v1, v2, v3, 1); }
void vmlf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vml(v1, v2, v3, 2); }
void vmeb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vme(v1, v2, v3, 0); }
void vmeh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vme(v1, v2, v3, 1); }
void vmef(const VReg& v1, const VReg& v2, const VReg& v3 ){ vme(v1, v2, v3, 2); }
void vmleb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmle(v1, v2, v3, 0); }
void vmleh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmle(v1, v2, v3, 1); }
void vmlef(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmle(v1, v2, v3, 2); }
void vmob(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmo(v1, v2, v3, 0); }
void vmoh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmo(v1, v2, v3, 1); }
void vmof(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmo(v1, v2, v3, 2); }
void vmlob(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmlo(v1, v2, v3, 0); }
void vmloh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmlo(v1, v2, v3, 1); }
void vmlof(const VReg& v1, const VReg& v2, const VReg& v3 ){ vmlo(v1, v2, v3, 2); }
void vmslg(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6 ){ vmsl(v1, v2, v3, v4, 3, m6); }
void vnot(const VReg& v1, const VReg& v2 ){ vno(v1, v2, v2); }
void vpopctb(const VReg& v1, const VReg& v2 ){ vpopct(v1, v2, 0); }
void vpopcth(const VReg& v1, const VReg& v2 ){ vpopct(v1, v2, 1); }
void vpopctf(const VReg& v1, const VReg& v2 ){ vpopct(v1, v2, 2); }
void vpopctg(const VReg& v1, const VReg& v2 ){ vpopct(v1, v2, 3); }
void verllvb(const VReg& v1, const VReg& v2, const VReg& v3 ){ verllv(v1, v2, v3, 0); }
void verllvh(const VReg& v1, const VReg& v2, const VReg& v3 ){ verllv(v1, v2, v3, 1); }
void verllvf(const VReg& v1, const VReg& v2, const VReg& v3 ){ verllv(v1, v2, v3, 2); }
void verllvg(const VReg& v1, const VReg& v2, const VReg& v3 ){ verllv(v1, v2, v3, 3); }
void verllb(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ verll(v1, v3, db2, 0); }
void verllh(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ verll(v1, v3, db2, 1); }
void verllf(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ verll(v1, v3, db2, 2); }
void verllg(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ verll(v1, v3, db2, 3); }
void verimb(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4 ){ verim(v1, v2, v3, i4, 0); }
void verimh(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4 ){ verim(v1, v2, v3, i4, 1); }
void verimf(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4 ){ verim(v1, v2, v3, i4, 2); }
void verimg(const VReg& v1, const VReg& v2, const VReg& v3, const int& i4 ){ verim(v1, v2, v3, i4, 3); }
void veslvb(const VReg& v1, const VReg& v2, const VReg& v3 ){ veslv(v1, v2, v3, 0); }
void veslvh(const VReg& v1, const VReg& v2, const VReg& v3 ){ veslv(v1, v2, v3, 1); }
void veslvf(const VReg& v1, const VReg& v2, const VReg& v3 ){ veslv(v1, v2, v3, 2); }
void veslvg(const VReg& v1, const VReg& v2, const VReg& v3 ){ veslv(v1, v2, v3, 3); }
void veslb(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ vesl(v1, v3, db2, 0); }
void veslh(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ vesl(v1, v3, db2, 1); }
void veslf(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ vesl(v1, v3, db2, 2); }
void veslg(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ vesl(v1, v3, db2, 3); }
void vesravb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vesrav(v1, v2, v3, 0); }
void vesravh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vesrav(v1, v2, v3, 1); }
void vesravf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vesrav(v1, v2, v3, 2); }
void vesravg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vesrav(v1, v2, v3, 3); }
void vesrab(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ vesra(v1, v3, db2, 0); }
void vesrah(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ vesra(v1, v3, db2, 1); }
void vesraf(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ vesra(v1, v3, db2, 2); }
void vesrag(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ vesra(v1, v3, db2, 3); }
void vesrlvb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vesrlv(v1, v2, v3, 0); }
void vesrlvh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vesrlv(v1, v2, v3, 1); }
void vesrlvf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vesrlv(v1, v2, v3, 2); }
void vesrlvg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vesrlv(v1, v2, v3, 3); }
void vesrlb(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ vesrl(v1, v3, db2, 0); }
void vesrlh(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ vesrl(v1, v3, db2, 1); }
void vesrlf(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ vesrl(v1, v3, db2, 2); }
void vesrlg(const VReg& v1, const VReg& v3, const AddrDB& db2 ){ vesrl(v1, v3, db2, 3); }
void vsb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vs(v1, v2, v3, 0); }
void vsh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vs(v1, v2, v3, 1); }
void vsf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vs(v1, v2, v3, 2); }
void vsg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vs(v1, v2, v3, 3); }
void vsq(const VReg& v1, const VReg& v2, const VReg& v3 ){ vs(v1, v2, v3, 4); }
void vscbib(const VReg& v1, const VReg& v2, const VReg& v3 ){ vscbi(v1, v2, v3, 0); }
void vscbih(const VReg& v1, const VReg& v2, const VReg& v3 ){ vscbi(v1, v2, v3, 1); }
void vscbif(const VReg& v1, const VReg& v2, const VReg& v3 ){ vscbi(v1, v2, v3, 2); }
void vscbig(const VReg& v1, const VReg& v2, const VReg& v3 ){ vscbi(v1, v2, v3, 3); }
void vscbiq(const VReg& v1, const VReg& v2, const VReg& v3 ){ vscbi(v1, v2, v3, 4); }
void vsbiq(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vsbi(v1, v2, v3, v4, 4); }
void vsbcbiq(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vsbcbi(v1, v2, v3, v4, 4); }
void vsumgh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vsumg(v1, v2, v3, 1); }
void vsumgf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vsumg(v1, v2, v3, 2); }
void vsumqf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vsumq(v1, v2, v3, 2); }
void vsumqg(const VReg& v1, const VReg& v2, const VReg& v3 ){ vsumq(v1, v2, v3, 3); }
void vsumb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vsum(v1, v2, v3, 0); }
void vsumh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vsum(v1, v2, v3, 1); }
void vfaeb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfae(v1, v2, v3, 0, m5); }
void vfaeh(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfae(v1, v2, v3, 1, m5); }
void vfaef(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfae(v1, v2, v3, 2, m5); }
void vfaebs(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfae(v1, v2, v3, 0, m5|0x1); }
void vfaehs(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfae(v1, v2, v3, 1, m5|0x1); }
void vfaefs(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfae(v1, v2, v3, 2, m5|0x1); }
void vfaezb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfae(v1, v2, v3, 0, m5|0x2); }
void vfaezh(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfae(v1, v2, v3, 1, m5|0x2); }
void vfaezf(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfae(v1, v2, v3, 2, m5|0x2); }
void vfaezbs(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfae(v1, v2, v3, 0, m5|0x3); }
void vfaezhs(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfae(v1, v2, v3, 1, m5|0x3); }
void vfaezfs(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfae(v1, v2, v3, 2, m5|0x3); }
void vfeeb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfee(v1, v2, v3, 0, m5); }
void vfeeh(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfee(v1, v2, v3, 1, m5); }
void vfeef(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfee(v1, v2, v3, 2, m5); }
void vfeebs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfee(v1, v2, v3, 0, 1); }
void vfeehs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfee(v1, v2, v3, 1, 1); }
void vfeefs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfee(v1, v2, v3, 2, 1); }
void vfeezb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfee(v1, v2, v3, 0, 2); }
void vfeezh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfee(v1, v2, v3, 1, 2); }
void vfeezf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfee(v1, v2, v3, 2, 2); }
void vfeezbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfee(v1, v2, v3, 0, 3); }
void vfeezhs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfee(v1, v2, v3, 1, 3); }
void vfeezfs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfee(v1, v2, v3, 2, 3); }
void vfeneb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfene(v1, v2, v3, 0, m5); }
void vfeneh(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfene(v1, v2, v3, 1, m5); }
void vfenef(const VReg& v1, const VReg& v2, const VReg& v3, const int& m5= {}  ){ vfene(v1, v2, v3, 2, m5); }
void vfenebs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfene(v1, v2, v3, 0, 1); }
void vfenehs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfene(v1, v2, v3, 1, 1); }
void vfenefs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfene(v1, v2, v3, 2, 1); }
void vfenezb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfene(v1, v2, v3, 0, 2); }
void vfenezh(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfene(v1, v2, v3, 1, 2); }
void vfenezf(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfene(v1, v2, v3, 2, 2); }
void vfenezbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfene(v1, v2, v3, 0, 3); }
void vfenezhs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfene(v1, v2, v3, 1, 3); }
void vfenezfs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfene(v1, v2, v3, 2, 3); }
void vistrb(const VReg& v1, const VReg& v2, const int& m5= {}  ){ vistr(v1, v2, 0, m5); }
void vistrh(const VReg& v1, const VReg& v2, const int& m5= {}  ){ vistr(v1, v2, 1, m5); }
void vistrf(const VReg& v1, const VReg& v2, const int& m5= {}  ){ vistr(v1, v2, 2, m5); }
void vistrbs(const VReg& v1, const VReg& v2 ){ vistr(v1, v2, 0, 1); }
void vistrhs(const VReg& v1, const VReg& v2 ){ vistr(v1, v2, 1, 1); }
void vistrfs(const VReg& v1, const VReg& v2 ){ vistr(v1, v2, 2, 1); }
void vstrcb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrc(v1, v2, v3, v4, 0, m6); }
void vstrch(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrc(v1, v2, v3, v4, 1, m6); }
void vstrcf(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrc(v1, v2, v3, v4, 2, m6); }
void vstrcbs(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrc(v1, v2, v3, v4, 0, m6|0x1); }
void vstrchs(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrc(v1, v2, v3, v4, 1, m6|0x1); }
void vstrcfs(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrc(v1, v2, v3, v4, 2, m6|0x1); }
void vstrczb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrc(v1, v2, v3, v4, 0, m6|0x2); }
void vstrczh(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrc(v1, v2, v3, v4, 1, m6|0x2); }
void vstrczf(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrc(v1, v2, v3, v4, 2, m6|0x2); }
void vstrczbs(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrc(v1, v2, v3, v4, 0, m6|0x3); }
void vstrczhs(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrc(v1, v2, v3, v4, 1, m6|0x3); }
void vstrczfs(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrc(v1, v2, v3, v4, 2, m6|0x3); }
void vstrsb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrs(v1, v2, v3, v4, 0, m6); }
void vstrsh(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrs(v1, v2, v3, v4, 1, m6); }
void vstrsf(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m6= {}  ){ vstrs(v1, v2, v3, v4, 2, m6); }
void vstrszb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vstrs(v1, v2, v3, v4, 0, 2); }
void vstrszh(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vstrs(v1, v2, v3, v4, 1, 2); }
void vstrszf(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vstrs(v1, v2, v3, v4, 2, 2); }
void vfasb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfa(v1, v2, v3, 2, 0); }
void vfadb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfa(v1, v2, v3, 3, 0); }
void wfasb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfa(v1, v2, v3, 2, 8); }
void wfadb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfa(v1, v2, v3, 3, 8); }
void wfaxb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfa(v1, v2, v3, 4, 8); }
void wfcsb(const VReg& v1, const VReg& v2 ){ wfc(v1, v2, 2, 0); }
void wfcdb(const VReg& v1, const VReg& v2 ){ wfc(v1, v2, 3, 0); }
void wfcxb(const VReg& v1, const VReg& v2 ){ wfc(v1, v2, 4, 0); }
void wfksb(const VReg& v1, const VReg& v2 ){ wfk(v1, v2, 2, 0); }
void wfkdb(const VReg& v1, const VReg& v2 ){ wfk(v1, v2, 3, 0); }
void wfkxb(const VReg& v1, const VReg& v2 ){ wfk(v1, v2, 4, 0); }
void vfcesb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 2, 0, 0); }
void vfcesbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 2, 0, 1); }
void vfcedb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 3, 0, 0); }
void vfcedbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 3, 0, 1); }
void wfcesb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 2, 8, 0); }
void wfcesbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 2, 8, 1); }
void wfcedb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 3, 8, 0); }
void wfcedbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 3, 8, 1); }
void wfcexb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 4, 8, 0); }
void wfcexbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 4, 8, 1); }
void vfkesb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 2, 4, 0); }
void vfkesbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 2, 4, 1); }
void vfkedb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 3, 4, 0); }
void vfkedbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 3, 4, 1); }
void wfkesb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 2, 12, 0); }
void wfkesbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 2, 12, 1); }
void wfkedb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 3, 12, 0); }
void wfkedbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 3, 12, 1); }
void wfkexb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 4, 12, 0); }
void wfkexbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfce(v1, v2, v3, 4, 12, 1); }
void vfchsb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 2, 0, 0); }
void vfchsbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 2, 0, 1); }
void vfchdb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 3, 0, 0); }
void vfchdbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 3, 0, 1); }
void wfchsb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 2, 8, 0); }
void wfchsbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 2, 8, 1); }
void wfchdb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 3, 8, 0); }
void wfchdbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 3, 8, 1); }
void wfchxb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 4, 8, 0); }
void wfchxbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 4, 8, 1); }
void vfkhsb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 2, 4, 0); }
void vfkhsbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 2, 4, 1); }
void vfkhdb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 3, 4, 0); }
void vfkhdbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 3, 4, 1); }
void wfkhsb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 2, 12, 0); }
void wfkhsbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 2, 12, 1); }
void wfkhdb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 3, 12, 0); }
void wfkhdbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 3, 12, 1); }
void wfkhxb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 4, 12, 0); }
void wfkhxbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfch(v1, v2, v3, 4, 12, 1); }
void vfchesb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 2, 0, 0); }
void vfchesbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 2, 0, 1); }
void vfchedb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 3, 0, 0); }
void vfchedbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 3, 0, 1); }
void wfchesb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 2, 8, 0); }
void wfchesbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 2, 8, 1); }
void wfchedb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 3, 8, 0); }
void wfchedbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 3, 8, 1); }
void wfchexb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 4, 8, 0); }
void wfchexbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 4, 8, 1); }
void vfkhesb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 2, 4, 0); }
void vfkhesbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 2, 4, 1); }
void vfkhedb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 3, 4, 0); }
void vfkhedbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 3, 4, 1); }
void wfkhesb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 2, 12, 0); }
void wfkhesbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 2, 12, 1); }
void wfkhedb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 3, 12, 0); }
void wfkhedbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 3, 12, 1); }
void wfkhexb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 4, 12, 0); }
void wfkhexbs(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfche(v1, v2, v3, 4, 12, 1); }
void vcdg(const VReg& v1, const VReg& v2, const int& m3, const int& m4, const int& m5 ){ vcfps(v1, v2, m3, m4, m5); }
void vcefb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vcfps(v1, v2, 2, m4, m5); }
void vcdgb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vcfps(v1, v2, 3, m4, m5); }
void wcefb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vcfps(v1, v2, 2, 8|m4, m5); }
void wcdgb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vcfps(v1, v2, 3, 8|m4, m5); }
void vcdlg(const VReg& v1, const VReg& v2, const int& m3, const int& m4, const int& m5 ){ vcfpl(v1, v2, m3, m4, m5); }
void vcelfb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vcfpl(v1, v2, 2, m4, m5); }
void vcdlgb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vcfpl(v1, v2, 3, m4, m5); }
void wcelfb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vcfpl(v1, v2, 2, 8|m4, m5); }
void wcdlgb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vcfpl(v1, v2, 3, 8|m4, m5); }
void vcgd(const VReg& v1, const VReg& v2, const int& m3, const int& m4, const int& m5 ){ vcsfp(v1, v2, m3, m4, m5); }
void vcfeb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vcsfp(v1, v2, 2, m4, m5); }
void vcgdb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vcsfp(v1, v2, 3, m4, m5); }
void wcfeb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vcsfp(v1, v2, 2, 8|m4, m5); }
void wcgdb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vcsfp(v1, v2, 3, 8|m4, m5); }
void vclgd(const VReg& v1, const VReg& v2, const int& m3, const int& m4, const int& m5 ){ vclfp(v1, v2, m3, m4, m5); }
void vclfeb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vclfp(v1, v2, 2, m4, m5); }
void vclgdb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vclfp(v1, v2, 3, m4, m5); }
void wclfeb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vclfp(v1, v2, 2, 8|m4, m5); }
void wclgdb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vclfp(v1, v2, 3, 8|m4, m5); }
void vfdsb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfd(v1, v2, v3, 2, 0); }
void wfdsb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfd(v1, v2, v3, 2, 8); }
void vfddb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfd(v1, v2, v3, 3, 0); }
void wfddb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfd(v1, v2, v3, 3, 8); }
void wfdxb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfd(v1, v2, v3, 4, 8); }
void vfisb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vfi(v1, v2, 2, m4, m5); }
void wfisb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vfi(v1, v2, 2, 8|m4, m5); }
void vfidb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vfi(v1, v2, 3, m4, m5); }
void wfidb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vfi(v1, v2, 3, 8|m4, m5); }
void wfixb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vfi(v1, v2, 4, 8|m4, m5); }
void vlde(const VReg& v1, const VReg& v2, const int& m3, const int& m4 ){ vfll(v1, v2, m3, m4); }
void vldeb(const VReg& v1, const VReg& v2 ){ vfll(v1, v2, 2, 0); }
void wldeb(const VReg& v1, const VReg& v2 ){ vfll(v1, v2, 2, 8); }
void wflld(const VReg& v1, const VReg& v2 ){ vfll(v1, v2, 3, 8); }
void vled(const VReg& v1, const VReg& v2, const int& m3, const int& m4, const int& m5 ){ vflr(v1, v2, m4, m4, m5); }
void vledb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vflr(v1, v2, 3, m4, m5); }
void wledb(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vflr(v1, v2, 3, 8|m4, m5); }
void vflrd(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vflr(v1, v2, 3, m4, m5); }
void wflrd(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vflr(v1, v2, 3, 8|m4, m5); }
void wflrx(const VReg& v1, const VReg& v2, const int& m4, const int& m5 ){ vflr(v1, v2, 4, 8|m4, m5); }
void vfmaxsb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m6 ){ vfmax(v1, v2, v3, 2, 0, m6); }
void vfmaxdb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m6 ){ vfmax(v1, v2, v3, 3, 0, m6); }
void wfmaxsb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m6 ){ vfmax(v1, v2, v3, 2, 8, m6); }
void wfmaxdb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m6 ){ vfmax(v1, v2, v3, 3, 8, m6); }
void wfmaxxb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m6 ){ vfmax(v1, v2, v3, 4, 8, m6); }
void vfminsb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m6 ){ vfmin(v1, v2, v3, 2, 0, m6); }
void vfmindb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m6 ){ vfmin(v1, v2, v3, 3, 0, m6); }
void wfminsb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m6 ){ vfmin(v1, v2, v3, 2, 8, m6); }
void wfmindb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m6 ){ vfmin(v1, v2, v3, 3, 8, m6); }
void wfminxb(const VReg& v1, const VReg& v2, const VReg& v3, const int& m6 ){ vfmin(v1, v2, v3, 4, 8, m6); }
void vfmsb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfm(v1, v2, v3, 2, 0); }
void vfmdb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfm(v1, v2, v3, 3, 0); }
void wfmsb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfm(v1, v2, v3, 2, 8); }
void wfmdb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfm(v1, v2, v3, 3, 8); }
void wfmxb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfm(v1, v2, v3, 4, 8); }
void vfmasb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfma(v1, v2, v3, v4, 0, 2); }
void vfmadb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfma(v1, v2, v3, v4, 0, 3); }
void wfmasb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfma(v1, v2, v3, v4, 8, 2); }
void wfmadb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfma(v1, v2, v3, v4, 8, 3); }
void wfmaxb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfma(v1, v2, v3, v4, 8, 4); }
void vfmssb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfms(v1, v2, v3, v4, 0, 2); }
void vfmsdb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfms(v1, v2, v3, v4, 0, 3); }
void wfmssb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfms(v1, v2, v3, v4, 8, 2); }
void wfmsdb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfms(v1, v2, v3, v4, 8, 3); }
void wfmsxb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfms(v1, v2, v3, v4, 8, 4); }
void vfnmasb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfnma(v1, v2, v3, v4, 0, 2); }
void vfnmadb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfnma(v1, v2, v3, v4, 0, 3); }
void wfnmasb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfnma(v1, v2, v3, v4, 8, 2); }
void wfnmadb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfnma(v1, v2, v3, v4, 8, 3); }
void wfnmaxb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfnma(v1, v2, v3, v4, 8, 4); }
void vfnmssb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfnms(v1, v2, v3, v4, 0, 2); }
void vfnmsdb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfnms(v1, v2, v3, v4, 0, 3); }
void wfnmssb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfnms(v1, v2, v3, v4, 8, 2); }
void wfnmsdb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfnms(v1, v2, v3, v4, 8, 3); }
void wfnmsxb(const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4 ){ vfnms(v1, v2, v3, v4, 8, 4); }
void vfpsosb(const VReg& v1, const VReg& v2, const int& m5 ){ vfpso(v1, v2, 2, 0, m5); }
void wfpsosb(const VReg& v1, const VReg& v2, const int& m5 ){ vfpso(v1, v2, 2, 8, m5); }
void vflcsb(const VReg& v1, const VReg& v2 ){ vfpso(v1, v2, 2, 0, 0); }
void wflcsb(const VReg& v1, const VReg& v2 ){ vfpso(v1, v2, 2, 8, 0); }
void vflnsb(const VReg& v1, const VReg& v2 ){ vfpso(v1, v2, 2, 0, 1); }
void wflpsb(const VReg& v1, const VReg& v2 ){ vfpso(v1, v2, 2, 8, 2); }
void vfpsodb(const VReg& v1, const VReg& v2, const int& m5 ){ vfpso(v1, v2, 3, 0, m5); }
void wfpsodb(const VReg& v1, const VReg& v2, const int& m5 ){ vfpso(v1, v2, 3, 8, m5); }
void vflcdb(const VReg& v1, const VReg& v2 ){ vfpso(v1, v2, 3, 0, 0); }
void wflcdb(const VReg& v1, const VReg& v2 ){ vfpso(v1, v2, 3, 8, 0); }
void vflndb(const VReg& v1, const VReg& v2 ){ vfpso(v1, v2, 3, 0, 1); }
void wflndb(const VReg& v1, const VReg& v2 ){ vfpso(v1, v2, 3, 8, 1); }
void vflpdb(const VReg& v1, const VReg& v2 ){ vfpso(v1, v2, 3, 0, 2); }
void wflpdb(const VReg& v1, const VReg& v2 ){ vfpso(v1, v2, 3, 8, 2); }
void wfpsoxb(const VReg& v1, const VReg& v2, const int& m5 ){ vfpso(v1, v2, 4, 8, m5); }
void wflcxb(const VReg& v1, const VReg& v2 ){ vfpso(v1, v2, 4, 8, 0); }
void wflnxb(const VReg& v1, const VReg& v2 ){ vfpso(v1, v2, 4, 8, 1); }
void wflpxb(const VReg& v1, const VReg& v2 ){ vfpso(v1, v2, 4, 8, 2); }
void vfsqsb(const VReg& v1, const VReg& v2 ){ vfsq(v1, v2, 2, 0); }
void vfsqdb(const VReg& v1, const VReg& v2 ){ vfsq(v1, v2, 3, 0); }
void wfsqsb(const VReg& v1, const VReg& v2 ){ vfsq(v1, v2, 2, 8); }
void wfsqdb(const VReg& v1, const VReg& v2 ){ vfsq(v1, v2, 3, 8); }
void wfsqxb(const VReg& v1, const VReg& v2 ){ vfsq(v1, v2, 4, 8); }
void vfssb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfs(v1, v2, v3, 2, 0); }
void vfsdb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfs(v1, v2, v3, 3, 0); }
void wfssb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfs(v1, v2, v3, 2, 8); }
void wfsdb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfs(v1, v2, v3, 3, 8); }
void wfsxb(const VReg& v1, const VReg& v2, const VReg& v3 ){ vfs(v1, v2, v3, 4, 8); }
void vftcisb(const VReg& v1, const VReg& v2, const int& i3 ){ vftci(v1, v2, i3, 2, 0); }
void vftcidb(const VReg& v1, const VReg& v2, const int& i3 ){ vftci(v1, v2, i3, 3, 0); }
void wftcisb(const VReg& v1, const VReg& v2, const int& i3 ){ vftci(v1, v2, i3, 2, 8); }
void wftcidb(const VReg& v1, const VReg& v2, const int& i3 ){ vftci(v1, v2, i3, 3, 8); }
void wftcixb(const VReg& v1, const VReg& v2, const int& i3 ){ vftci(v1, v2, i3, 4, 8); }
// Extensiones 2: 
//jump on overflow / if ones
void bo(const AddrDXB& dxb2 ){bc(1, dxb2); }
//jump on A high
void bh(const AddrDXB& dxb2 ){bc(2, dxb2); }
//jump on plus
void bp(const AddrDXB& dxb2 ){bc(2, dxb2); }
//jump on not low or equal
void bnle(const AddrDXB& dxb2 ){bc(3, dxb2); }
//jump on A low
void bl(const AddrDXB& dxb2 ){bc(4, dxb2); }
//jump on minus
void bm(const AddrDXB& dxb2 ){bc(4, dxb2); }
//jump on not high or equal
void bnhe(const AddrDXB& dxb2 ){bc(5, dxb2); }
//jump on low or high
void blh(const AddrDXB& dxb2 ){bc(6, dxb2); }
//jump on A not equal B
void bne(const AddrDXB& dxb2 ){bc(7, dxb2); }
//jump on not zero / if not zeros
void bnz(const AddrDXB& dxb2 ){bc(7, dxb2); }
//jump on A equal B
void be(const AddrDXB& dxb2 ){bc(8, dxb2); }
//jump on zero / if zeroes
void bz(const AddrDXB& dxb2 ){bc(8, dxb2); }
//jump on not low or high
void bnlh(const AddrDXB& dxb2 ){bc(9, dxb2); }
//jump on high or equal
void bhe(const AddrDXB& dxb2 ){bc(10, dxb2); }
//jump on A not low
void bnl(const AddrDXB& dxb2 ){bc(11, dxb2); }
//jump on not minus / if not mixed
void bnm(const AddrDXB& dxb2 ){bc(11, dxb2); }
//jump on low or equal
void ble(const AddrDXB& dxb2 ){bc(12, dxb2); }
//jump on A not high
void bnh(const AddrDXB& dxb2 ){bc(13, dxb2); }
//jump on not plus
void bnp(const AddrDXB& dxb2 ){bc(13, dxb2); }
//jump on not overflow / if not ones
void bno(const AddrDXB& dxb2 ){bc(14, dxb2); }
//unconditional
void b(const AddrDXB& dxb2 ){bc(15, dxb2); }
//jump on overflow / if ones
void bor(const GPReg& r1 ){bcr(1, r1); }
//jump on A high
void bhr(const GPReg& r1 ){bcr(2, r1); }
//jump on plus
void bpr(const GPReg& r1 ){bcr(2, r1); }
//jump on not low or equal
void bnler(const GPReg& r1 ){bcr(3, r1); }
//jump on A low
void blr(const GPReg& r1 ){bcr(4, r1); }
//jump on minus
void bmr(const GPReg& r1 ){bcr(4, r1); }
//jump on not high or equal
void bnher(const GPReg& r1 ){bcr(5, r1); }
//jump on low or high
void blhr(const GPReg& r1 ){bcr(6, r1); }
//jump on A not equal B
void bner(const GPReg& r1 ){bcr(7, r1); }
//jump on not zero / if not zeros
void bnzr(const GPReg& r1 ){bcr(7, r1); }
//jump on A equal B
void ber(const GPReg& r1 ){bcr(8, r1); }
//jump on zero / if zeroes
void bzr(const GPReg& r1 ){bcr(8, r1); }
//jump on not low or high
void bnlhr(const GPReg& r1 ){bcr(9, r1); }
//jump on high or equal
void bher(const GPReg& r1 ){bcr(10, r1); }
//jump on A not low
void bnlr(const GPReg& r1 ){bcr(11, r1); }
//jump on not minus / if not mixed
void bnmr(const GPReg& r1 ){bcr(11, r1); }
//jump on low or equal
void bler(const GPReg& r1 ){bcr(12, r1); }
//jump on A not high
void bnhr(const GPReg& r1 ){bcr(13, r1); }
//jump on not plus
void bnpr(const GPReg& r1 ){bcr(13, r1); }
//jump on not overflow / if not ones
void bnor(const GPReg& r1 ){bcr(14, r1); }
//unconditional
void br(const GPReg& r1 ){bcr(15, r1); }
//jump on overflow / if ones
void jo(const Label lbl1 ){brc(1, lbl1); }
//jump on A high
void jh(const Label lbl1 ){brc(2, lbl1); }
//jump on plus
void jp(const Label lbl1 ){brc(2, lbl1); }
//jump on not low or equal
void jnle(const Label lbl1 ){brc(3, lbl1); }
//jump on A low
void jl(const Label lbl1 ){brc(4, lbl1); }
//jump on minus
void jm(const Label lbl1 ){brc(4, lbl1); }
//jump on not high or equal
void jnhe(const Label lbl1 ){brc(5, lbl1); }
//jump on low or high
void jlh(const Label lbl1 ){brc(6, lbl1); }
//jump on A not equal B
void jne(const Label lbl1 ){brc(7, lbl1); }
//jump on not zero / if not zeros
void jnz(const Label lbl1 ){brc(7, lbl1); }
//jump on A equal B
void je(const Label lbl1 ){brc(8, lbl1); }
//jump on zero / if zeroes
void jz(const Label lbl1 ){brc(8, lbl1); }
//jump on not low or high
void jnlh(const Label lbl1 ){brc(9, lbl1); }
//jump on high or equal
void jhe(const Label lbl1 ){brc(10, lbl1); }
//jump on A not low
void jnl(const Label lbl1 ){brc(11, lbl1); }
//jump on not minus / if not mixed
void jnm(const Label lbl1 ){brc(11, lbl1); }
//jump on low or equal
void jle(const Label lbl1 ){brc(12, lbl1); }
//jump on A not high
void jnh(const Label lbl1 ){brc(13, lbl1); }
//jump on not plus
void jnp(const Label lbl1 ){brc(13, lbl1); }
//jump on not overflow / if not ones
void jno(const Label lbl1 ){brc(14, lbl1); }
//unconditional
void j(const Label lbl1 ){brc(15, lbl1); }
//jump on overflow / if ones
void jgo(const Label lbl1 ){brcl(1, lbl1); }
//jump on A high
void jgh(const Label lbl1 ){brcl(2, lbl1); }
//jump on plus
void jgp(const Label lbl1 ){brcl(2, lbl1); }
//jump on not low or equal
void jgnle(const Label lbl1 ){brcl(3, lbl1); }
//jump on A low
void jgl(const Label lbl1 ){brcl(4, lbl1); }
//jump on minus
void jgm(const Label lbl1 ){brcl(4, lbl1); }
//jump on not high or equal
void jgnhe(const Label lbl1 ){brcl(5, lbl1); }
//jump on low or high
void jglh(const Label lbl1 ){brcl(6, lbl1); }
//jump on A not equal B
void jgne(const Label lbl1 ){brcl(7, lbl1); }
//jump on not zero / if not zeros
void jgnz(const Label lbl1 ){brcl(7, lbl1); }
//jump on A equal B
void jge(const Label lbl1 ){brcl(8, lbl1); }
//jump on zero / if zeroes
void jgz(const Label lbl1 ){brcl(8, lbl1); }
//jump on not low or high
void jgnlh(const Label lbl1 ){brcl(9, lbl1); }
//jump on high or equal
void jghe(const Label lbl1 ){brcl(10, lbl1); }
//jump on A not low
void jgnl(const Label lbl1 ){brcl(11, lbl1); }
//jump on not minus / if not mixed
void jgnm(const Label lbl1 ){brcl(11, lbl1); }
//jump on low or equal
void jgle(const Label lbl1 ){brcl(12, lbl1); }
//jump on A not high
void jgnh(const Label lbl1 ){brcl(13, lbl1); }
//jump on not plus
void jgnp(const Label lbl1 ){brcl(13, lbl1); }
//jump on not overflow / if not ones
void jgno(const Label lbl1 ){brcl(14, lbl1); }
//unconditional
void jg(const Label lbl1 ){brcl(15, lbl1); }
//NOPs
void nop(const AddrDXB& dxb2 = {} ){ bc(0, dxb2); }
void nopr(const GPReg& r1 = {} ){ bcr(0, r1); }
void jnop(){ brc(0, {}); }
//ALTERNATIVE NAMES
void jras(const GPReg& r1, const Label lbl2 ){bras(r1, lbl2); }
void jrasl(const GPReg& r1, const Label lbl2 ){brasl(r1, lbl2); }
void jrc(const int& m1, const Label lbl2 ){brc(m1, lbl2); }
void jrcl(const int& m1, const Label lbl2 ){brcl(m1, lbl2); }
void jrct(const GPReg& r1, const Label lbl2 ){brct(r1, lbl2); }
void jrctg(const GPReg& r1, const Label lbl2 ){brctg(r1, lbl2); }
void jrcth(const GPReg& r1, const Label lbl2 ){brcth(r1, lbl2); }
void jrxh(const GPReg& r1, const GPReg& r3, const Label lbl2 ){brxh(r1, r3, lbl2); }
void jrxhg(const GPReg& r1, const GPReg& r3, const Label lbl2 ){brxhg(r1, r3, lbl2); }
void jrxle(const GPReg& r1, const GPReg& r3, const Label lbl2 ){brxle(r1, r3, lbl2); }
void jrxlg(const GPReg& r1, const GPReg& r3, const Label lbl2 ){brxlg(r1, r3, lbl2); }

// Missed ones: 
// ['DIAGNOSE', '—', 'DM', 'P DM', '', '', 'MD', '83', '10-23'] 
// ['TRAP', 'TRAP4', 'S', '¤1 A*', 'SO T', 'B ST', '', 'B2FF', '10-177'] 
// ['UPDATE TREE', 'UPT', 'E C', '¤ A SP', 'II GM I4', 'ST', '', '0102', '7-425'] 
