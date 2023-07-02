#pragma once

#include <cstdint>
#include <cstddef>

template<int N>
struct packed_type{
    using typeX = int64_t;
};

template<>
struct packed_type<32>{
    using typeX = int32_t;
};

template<>
struct packed_type<16>{
    using typeX = int16_t;
};

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define XBYAK_S390X_BIGENDIAN_64(x) __builtin_bswap64(x)
#define XBYAK_S390X_BIGENDIAN_32(x) __builtin_bswap32(x)
#define XBYAK_S390X_BIGENDIAN_16(x) __builtin_bswap16(x)
#else
#define XBYAK_S390X_BIGENDIAN_64(x) (x)
#define XBYAK_S390X_BIGENDIAN_32(x) (x)
#define XBYAK_S390X_BIGENDIAN_16(x) (x)
#endif

struct Format_E {
  packed_type<16>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 2; }
  Format_E(int64_t opcode){
    instr = XBYAK_S390X_BIGENDIAN_16( 0 | opcode);
  }
};

struct Format_I {
  packed_type<16>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 2; }
  Format_I(int64_t opcode, int64_t i){
    instr = XBYAK_S390X_BIGENDIAN_16( 0 | (opcode<<8) | i);
  }
};

struct Format_IE {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_IE(int64_t opcode, int64_t i1, int64_t i2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode<<16) | (i1<<4) | i2);
  }
};

struct Format_MII {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_MII(int64_t opcode, int64_t m1, int64_t ri2, int64_t ri3){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode<<56) | (m1<<52) | (ri2<<40) | (ri3<<16) );
  }
};

struct Format_RI_A {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_RI_A(int64_t opcode1, int64_t r1, int64_t opcode2, int64_t i2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode1<<24) | (r1<<20) | (opcode2<<16) | i2);
  }
};

struct Format_RI_B {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_RI_B(int64_t opcode1, int64_t r1, int64_t opcode2, int64_t ri2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode1<<24) | (r1<<20) | (opcode2<<16) | ri2);
  }
};

struct Format_RI_C {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_RI_C(int64_t opcode1, int64_t m1, int64_t opcode2, int64_t ri2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode1<<24) | (m1<<20) | (opcode2<<16) | ri2);
  }
};

struct Format_RIE_A {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RIE_A(int64_t opcode1, int64_t r1, int64_t unk1, int64_t i2, int64_t m3, int64_t unk2, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (unk1<<48) | (i2<<32) | (m3<<28) | (unk2<<24) | (opcode2<<16) );
  }
};

struct Format_RIE_B {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RIE_B(int64_t opcode1, int64_t r1, int64_t r2, int64_t ri4, int64_t m3, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (r2<<48) | (ri4<<32) | (m3<<28) | (opcode2<<16) );
  }
};

struct Format_RIE_C {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RIE_C(int64_t opcode1, int64_t r1, int64_t m3, int64_t ri4, int64_t i2, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (m3<<48) | (ri4<<32) | (i2<<24) | (opcode2<<16) );
  }
};

struct Format_RIE_D {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RIE_D(int64_t opcode1, int64_t r1, int64_t r3, int64_t i2, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (r3<<48) | (i2<<32) | (opcode2<<16) );
  }
};

struct Format_RIE_E {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RIE_E(int64_t opcode1, int64_t r1, int64_t r3, int64_t ri2, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (r3<<48) | (ri2<<32) | (opcode2<<16) );
  }
};

struct Format_RIE_F {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RIE_F(int64_t opcode1, int64_t r1, int64_t r2, int64_t i3, int64_t i4, int64_t i5, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (r2<<48) | (i3<<40) | (i4<<32) | (i5<<24) | (opcode2<<16) );
  }
};

struct Format_RIE_G {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RIE_G(int64_t opcode1, int64_t r1, int64_t m3, int64_t i2, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (m3<<48) | (i2<<32) | (opcode2<<16) );
  }
};

struct Format_RIL_A {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RIL_A(int64_t opcode1, int64_t r1, int64_t opcode2, int64_t i2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (opcode2<<48) | (i2<<16) );
  }
};

struct Format_RIL_B {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RIL_B(int64_t opcode1, int64_t r1, int64_t opcode2, int64_t ri2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (opcode2<<48) | (ri2<<16) );
  }
};

struct Format_RIL_C {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RIL_C(int64_t opcode1, int64_t m1, int64_t opcode2, int64_t ri2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (m1<<52) | (opcode2<<48) | (ri2<<16) );
  }
};

struct Format_RIS {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RIS(int64_t opcode1, int64_t r1, int64_t m3, int64_t b4, int64_t d4, int64_t i2, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (m3<<48) | (b4<<44) | (d4<<32) | (i2<<24) | (opcode2<<16) );
  }
};

struct Format_RR {
  packed_type<16>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 2; }
  Format_RR(int64_t opcode, int64_t r1_m1, int64_t r2){
    instr = XBYAK_S390X_BIGENDIAN_16( 0 | (opcode<<8) | (r1_m1<<4) | r2);
  }
};

struct Format_RRD {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_RRD(int64_t opcode, int64_t r1, int64_t r3, int64_t r2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode<<16) | (r1<<12) | (r3<<4) | r2);
  }
};

struct Format_RRE {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_RRE(int64_t opcode, int64_t r1, int64_t r2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode<<16) | (r1<<4) | r2);
  }
};

struct Format_RRF_A_B {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_RRF_A_B(int64_t opcode, int64_t r3, int64_t m4, int64_t r1, int64_t r2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode<<16) | (r3<<12) | (m4<<8) | (r1<<4) | r2);
  }
};

struct Format_RRF_C_E {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_RRF_C_E(int64_t opcode, int64_t m3, int64_t m4, int64_t r1, int64_t r2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode<<16) | (m3<<12) | (m4<<8) | (r1<<4) | r2);
  }
};

struct Format_RRS {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RRS(int64_t opcode1, int64_t r1, int64_t r2, int64_t b4, int64_t d4, int64_t m3, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (r2<<48) | (b4<<44) | (d4<<32) | (m3<<28) | (opcode2<<16) );
  }
};

struct Format_RS_A {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_RS_A(int64_t opcode, int64_t r1, int64_t r3, int64_t b2, int64_t d2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode<<24) | (r1<<20) | (r3<<16) | (b2<<12) | d2);
  }
};

struct Format_RS_B {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_RS_B(int64_t opcode, int64_t r1, int64_t m3, int64_t b2, int64_t d2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode<<24) | (r1<<20) | (m3<<16) | (b2<<12) | d2);
  }
};

struct Format_RSI {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_RSI(int64_t opcode, int64_t r1, int64_t r3, int64_t ri2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode<<24) | (r1<<20) | (r3<<16) | ri2);
  }
};

struct Format_RSL_A {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RSL_A(int64_t opcode1, int64_t l1, int64_t b1, int64_t d1, int64_t unk2, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (l1<<52) | (b1<<44) | (d1<<32) | (unk2<<24) | (opcode2<<16) );
  }
};

struct Format_RSL_B {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RSL_B(int64_t opcode1, int64_t l2, int64_t b2, int64_t d2, int64_t r1, int64_t m3, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (l2<<48) | (b2<<44) | (d2<<32) | (r1<<28) | (m3<<24) | (opcode2<<16) );
  }
};

struct Format_RSY_A {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RSY_A(int64_t opcode1, int64_t r1, int64_t r3, int64_t b2, int64_t dl2, int64_t dh2, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (r3<<48) | (b2<<44) | (dl2<<32) | (dh2<<24) | (opcode2<<16) );
  }
};

struct Format_RSY_B {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RSY_B(int64_t opcode1, int64_t r1, int64_t m3, int64_t b2, int64_t dl2, int64_t dh2, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (m3<<48) | (b2<<44) | (dl2<<32) | (dh2<<24) | (opcode2<<16) );
  }
};

struct Format_RX_A {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_RX_A(int64_t opcode, int64_t r1, int64_t x2, int64_t b2, int64_t d2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode<<24) | (r1<<20) | (x2<<16) | (b2<<12) | d2);
  }
};

struct Format_RX_B {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_RX_B(int64_t opcode, int64_t m1, int64_t x2, int64_t b2, int64_t d2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode<<24) | (m1<<20) | (x2<<16) | (b2<<12) | d2);
  }
};

struct Format_RXE {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RXE(int64_t opcode1, int64_t r1, int64_t x2, int64_t b2, int64_t d2, int64_t m3, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (x2<<48) | (b2<<44) | (d2<<32) | (m3<<28) | (opcode2<<16) );
  }
};

struct Format_RXF {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RXF(int64_t opcode1, int64_t r3, int64_t x2, int64_t b2, int64_t d2, int64_t r1, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r3<<52) | (x2<<48) | (b2<<44) | (d2<<32) | (r1<<28) | (opcode2<<16) );
  }
};

struct Format_RXY_A {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RXY_A(int64_t opcode1, int64_t r1, int64_t x2, int64_t b2, int64_t dl2, int64_t dh2, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (x2<<48) | (b2<<44) | (dl2<<32) | (dh2<<24) | (opcode2<<16) );
  }
};

struct Format_RXY_B {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_RXY_B(int64_t opcode1, int64_t m1, int64_t x2, int64_t b2, int64_t dl2, int64_t dh2, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (m1<<52) | (x2<<48) | (b2<<44) | (dl2<<32) | (dh2<<24) | (opcode2<<16) );
  }
};

struct Format_S {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_S(int64_t opcode, int64_t b2, int64_t d2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode<<16) | (b2<<12) | d2);
  }
};

struct Format_SI {
  packed_type<32>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 4; }
  Format_SI(int64_t opcode, int64_t i2, int64_t b1_b2, int64_t d1_d2){
    instr = XBYAK_S390X_BIGENDIAN_32( 0 | (opcode<<24) | (i2<<16) | (b1_b2<<12) | d1_d2);
  }
};

struct Format_SIL {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_SIL(int64_t opcode, int64_t b1, int64_t d1, int64_t i2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode<<48) | (b1<<44) | (d1<<32) | (i2<<16) );
  }
};

struct Format_SIY {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_SIY(int64_t opcode1, int64_t i2, int64_t b1, int64_t dl1, int64_t dh1, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (i2<<48) | (b1<<44) | (dl1<<32) | (dh1<<24) | (opcode2<<16) );
  }
};

struct Format_SMI {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_SMI(int64_t opcode, int64_t m1, int64_t b3, int64_t d3, int64_t ri2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode<<56) | (m1<<52) | (b3<<44) | (d3<<32) | (ri2<<16) );
  }
};

struct Format_SS_A {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_SS_A(int64_t opcode, int64_t l1, int64_t b1, int64_t d1, int64_t b2, int64_t d2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode<<56) | (l1<<48) | (b1<<44) | (d1<<32) | (b2<<28) | (d2<<16) );
  }
};

struct Format_SS_B {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_SS_B(int64_t opcode, int64_t l1, int64_t l2, int64_t b1, int64_t d1, int64_t b2, int64_t d2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode<<56) | (l1<<52) | (l2<<48) | (b1<<44) | (d1<<32) | (b2<<28) | (d2<<16) );
  }
};

struct Format_SS_C {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_SS_C(int64_t opcode, int64_t l1, int64_t i3, int64_t b1, int64_t d1, int64_t b2, int64_t d2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode<<56) | (l1<<52) | (i3<<48) | (b1<<44) | (d1<<32) | (b2<<28) | (d2<<16) );
  }
};

struct Format_SS_D {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_SS_D(int64_t opcode, int64_t r1, int64_t r3, int64_t b1, int64_t d1, int64_t b2, int64_t d2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode<<56) | (r1<<52) | (r3<<48) | (b1<<44) | (d1<<32) | (b2<<28) | (d2<<16) );
  }
};

struct Format_SS_E {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_SS_E(int64_t opcode, int64_t r1, int64_t r3, int64_t b2, int64_t d2, int64_t b4, int64_t d4){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode<<56) | (r1<<52) | (r3<<48) | (b2<<44) | (d2<<32) | (b4<<28) | (d4<<16) );
  }
};

struct Format_SS_F {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_SS_F(int64_t opcode, int64_t l2, int64_t b1, int64_t d1, int64_t b2, int64_t d2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode<<56) | (l2<<48) | (b1<<44) | (d1<<32) | (b2<<28) | (d2<<16) );
  }
};

struct Format_SSE {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_SSE(int64_t opcode, int64_t b1, int64_t d1, int64_t b2, int64_t d2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode<<48) | (b1<<44) | (d1<<32) | (b2<<28) | (d2<<16) );
  }
};

struct Format_SSF {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_SSF(int64_t opcode1, int64_t r3, int64_t opcode2, int64_t b1, int64_t d1, int64_t b2, int64_t d2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r3<<52) | (opcode2<<48) | (b1<<44) | (d1<<32) | (b2<<28) | (d2<<16) );
  }
};

struct Format_VRI_A {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRI_A(int64_t opcode1, int64_t v1, int64_t i2, int64_t m3, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (i2<<32) | (m3<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRI_B {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRI_B(int64_t opcode1, int64_t v1, int64_t i2, int64_t i3, int64_t m4, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (i2<<40) | (i3<<32) | (m4<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRI_C {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRI_C(int64_t opcode1, int64_t v1, int64_t v3, int64_t i2, int64_t m4, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (v3<<48) | (i2<<32) | (m4<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRI_D {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRI_D(int64_t opcode1, int64_t v1, int64_t v2, int64_t v3, int64_t i4, int64_t m5, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (v2<<48) | (v3<<44) | (i4<<32) | (m5<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRI_E {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRI_E(int64_t opcode1, int64_t v1, int64_t v2, int64_t i3, int64_t m5, int64_t m4, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (v2<<48) | (i3<<36) | (m5<<32) | (m4<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRI_F {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRI_F(int64_t opcode1, int64_t v1, int64_t v2, int64_t v3, int64_t m5, int64_t i4, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (v2<<48) | (v3<<44) | (m5<<36) | (i4<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRI_G {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRI_G(int64_t opcode1, int64_t v1, int64_t v2, int64_t i4, int64_t m5, int64_t i3, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (v2<<48) | (i4<<40) | (m5<<36) | (i3<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRI_H {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRI_H(int64_t opcode1, int64_t v1, int64_t i2, int64_t i3, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (i2<<32) | (i3<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRI_I {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRI_I(int64_t opcode1, int64_t v1, int64_t r2, int64_t m4, int64_t i3, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (r2<<48) | (m4<<36) | (i3<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRR_A {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRR_A(int64_t opcode1, int64_t v1, int64_t v2, int64_t m5, int64_t m4, int64_t m3, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (v2<<48) | (m5<<36) | (m4<<32) | (m3<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRR_B {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRR_B(int64_t opcode1, int64_t v1, int64_t v2, int64_t v3, int64_t unk1, int64_t m5, int64_t unk2, int64_t m4, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (v2<<48) | (v3<<44) | (unk1<<40) | (m5<<36) | (unk2<<32) | (m4<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRR_C {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRR_C(int64_t opcode1, int64_t v1, int64_t v2, int64_t v3, int64_t unk1, int64_t m6, int64_t m5, int64_t m4, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (v2<<48) | (v3<<44) | (unk1<<40) | (m6<<36) | (m5<<32) | (m4<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRR_D {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRR_D(int64_t opcode1, int64_t v1, int64_t v2, int64_t v3, int64_t m5, int64_t m6, int64_t v4, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (v2<<48) | (v3<<44) | (m5<<40) | (m6<<36) | (v4<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRR_E {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRR_E(int64_t opcode1, int64_t v1, int64_t v2, int64_t v3, int64_t m6, int64_t m5, int64_t v4, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (v2<<48) | (v3<<44) | (m6<<40) | (m5<<32) | (v4<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRR_F {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRR_F(int64_t opcode1, int64_t v1, int64_t r2, int64_t r3, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (r2<<48) | (r3<<44) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRR_G {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRR_G(int64_t opcode1, int64_t unk1, int64_t v1, int64_t unk2, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (unk1<<52) | (v1<<48) | (unk2<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRR_H {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRR_H(int64_t opcode1, int64_t unk1, int64_t v1, int64_t v2, int64_t unk2, int64_t m3, int64_t unk3, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (unk1<<52) | (v1<<48) | (v2<<44) | (unk2<<40) | (m3<<36) | (unk3<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRR_I {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRR_I(int64_t opcode1, int64_t r1, int64_t v2, int64_t unk1, int64_t m3, int64_t m4, int64_t unk2, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (v2<<48) | (unk1<<40) | (m3<<36) | (m4<<32) | (unk2<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRS_A {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRS_A(int64_t opcode1, int64_t v1, int64_t v3, int64_t b2, int64_t d2, int64_t m4, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (v3<<48) | (b2<<44) | (d2<<32) | (m4<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRS_B {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRS_B(int64_t opcode1, int64_t v1, int64_t r3, int64_t b2, int64_t d2, int64_t m4, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (r3<<48) | (b2<<44) | (d2<<32) | (m4<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRS_C {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRS_C(int64_t opcode1, int64_t r1, int64_t v3, int64_t b2, int64_t d2, int64_t m4, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r1<<52) | (v3<<48) | (b2<<44) | (d2<<32) | (m4<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRS_D {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRS_D(int64_t opcode1, int64_t r3, int64_t b2, int64_t d2, int64_t v1, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (r3<<48) | (b2<<44) | (d2<<32) | (v1<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRV {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRV(int64_t opcode1, int64_t v1, int64_t v2, int64_t b2, int64_t d2, int64_t m3, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (v2<<48) | (b2<<44) | (d2<<32) | (m3<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VRX {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VRX(int64_t opcode1, int64_t v1, int64_t x2, int64_t b2, int64_t d2, int64_t m3, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (v1<<52) | (x2<<48) | (b2<<44) | (d2<<32) | (m3<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

struct Format_VSI {
  packed_type<48>::typeX instr = 0;
  constexpr static size_t sizeOf(){ return 6; }
  Format_VSI(int64_t opcode1, int64_t i3, int64_t b2, int64_t d2, int64_t v1, int64_t rxb, int64_t opcode2){
    instr = XBYAK_S390X_BIGENDIAN_64( 0 | (opcode1<<56) | (i3<<48) | (b2<<44) | (d2<<32) | (v1<<28) | (rxb<<24) | (opcode2<<16) );
  }
};

using Format_RRF_A = Format_RRF_A_B;
using Format_RRF_B = Format_RRF_A_B;
using Format_RRF_C = Format_RRF_C_E;
using Format_RRF_D = Format_RRF_C_E;
using Format_RRF_E = Format_RRF_C_E;
