
## Xbyak_s390x ; JIT assembler for IBM Z s390x

### Abstract

Xbyak_s390x is a C++ library which enables run-time assemble coding with the s390x instruction set.
Xbyak_s390x is based on Xbyak developed for x86_64 CPUs by MITSUNARI Shigeo.

### Features

* Gnu C++ inline assembly like syntax
* General instructions, Vector instructions, Extensions
* As endianness is handled correctly, it is fine to test it under x86 without execution

##### Missing:

* Facility checks are not supported for now
* For now, it does not check for the correct Register pairs thats used by some instructions

### Syntax

Similar to GNU C++ inline assembly

| Assembly  | Xbyak s390x  |
|--|--|
| ldgr %f2, %r11       |  ldgr(f2, r11); |
| ldgr %f0, %r15       |  ldgr(f0, r15);  |
| lay %r15, -168(%r15) |  lay(r15, -168_dp(r15));  |
| cg %r0, 160(%r15)   |  cg(r0, 160_dp(r15));  |
| lgr %r11, %r15      |  lgr(r11, r15); |
| lgr %r1, %r2         |  lgr(r1, r2); |
| st %r1, 164(%r11)    |  st(r1, 164_dp(r11)); |
| l %r1, 164(%r11)    |  l(r1, 164_dp(r11)); |
| ahi %r1, 5           |  ahi(r1, 5); |
| lgfr %r1, %r1       |  lgfr(r1, r1); |
| lgr %r2, % r1         |  lgr(r2, r1); |
| lgdr %r15, % f0       |  lgdr(r15, f0); |
| lgdr %r11, % f2       |  lgdr(r11, f2); |
| br %r14               |  br(r14); |
| nopr %r7              |  nopr(r7) |


#### Authors

Abdelrauf Gurbanov (xbyak s390x port)    
MITSUNARI Shigeo (author of the original xbyak)

