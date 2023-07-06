//RR: R1,R2 | R1
void opRR(int opCode, const Operand& r1, const Operand& r2= {}  ){
    //bit_fields: [('opcode', 8), ('r1_m1', 4), ('r2', 4)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_r1_m1 = local::mask(r1.getIdx(),4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    Format_RR instr_fmt = { instr_opcode, instr_r1_m1, instr_r2 };
    appendInto(instr_fmt);
}

//RR: M1,R2
void opRR(int opCode, const int& m1, const Operand& r2 ){
    //bit_fields: [('opcode', 8), ('r1_m1', 4), ('r2', 4)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_r1_m1 = local::mask(m1,4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    Format_RR instr_fmt = { instr_opcode, instr_r1_m1, instr_r2 };
    appendInto(instr_fmt);
}

//RRE: R1,R2 | R1 | 
void opRRE(int opCode, const Operand& r1= {} , const Operand& r2= {}  ){
    //bit_fields: [('opcode', 16), ('unk', 8), ('r1', 4), ('r2', 4)]
    auto instr_opcode = local::mask(opCode,16);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    Format_RRE instr_fmt = { instr_opcode, instr_r1, instr_r2 };
    appendInto(instr_fmt);
}

//RRF-a: R1,R2,R3 | R1,R2,R3,M4 | R1,R2[,R3[,M4]]
void opRRF_A(int opCode, const Operand& r1, const Operand& r2, const Operand& r3= {} , const int& m4= {}  ){
    //bit_fields: [('opcode', 16), ('r3', 4), ('m4', 4), ('r1', 4), ('r2', 4)]
    auto instr_opcode = local::mask(opCode,16);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_m4 = local::mask(m4,4);
    Format_RRF_A instr_fmt = { instr_opcode, instr_r3, instr_m4, instr_r1, instr_r2 };
    appendInto(instr_fmt);
}

//RX-a: R1,D2(X2,B2)
void opRX_A(int opCode, const Operand& r1, const AddrDXB& dxb2 ){
    //bit_fields: [('opcode', 8), ('r1', 4), ('x2', 4), ('b2', 4), ('d2', 12)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_d2 = local::mask(dxb2.disp,12);
    auto instr_x2 = local::mask(dxb2.regx.getIdx(),4);
    auto instr_b2 = local::mask(dxb2.regb.getIdx(),4);
    Format_RX_A instr_fmt = { instr_opcode, instr_r1, instr_x2, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//RXY-a: R1,D2(X2,B2)
void opRXY_A(int opCode, const Operand& r1, const AddrDXB& dxb2 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('x2', 4), ('b2', 4), ('dl2', 12), ('dh2', 8), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_dh2 = local::shift_right_mask(dxb2.disp, 12, 8);
    auto instr_dl2 = local::mask(dxb2.disp, 12);
    auto instr_x2 = local::mask(dxb2.regx.getIdx(),4);
    auto instr_b2 = local::mask(dxb2.regb.getIdx(),4);
    Format_RXY_A instr_fmt = { instr_opcode1, instr_r1, instr_x2, instr_b2, instr_dl2, instr_dh2, instr_opcode2 };
    appendInto(instr_fmt);
}

//RIL-a: R1,I2
void opRIL_A(int opCode, const Operand& r1, const int& i2 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('opcode2', 4), ('i2', 32)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 4, 8);
    auto instr_opcode2 = local::mask(opCode, 4);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_i2 = local::mask(i2,32);
    Format_RIL_A instr_fmt = { instr_opcode1, instr_r1, instr_opcode2, instr_i2 };
    appendInto(instr_fmt);
}

//RIE-d: R1,R3,I2
void opRIE_D(int opCode, const Operand& r1, const Operand& r3, const int& i2 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('r3', 4), ('i2', 16), ('unk', 8), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_i2 = local::mask(i2,16);
    Format_RIE_D instr_fmt = { instr_opcode1, instr_r1, instr_r3, instr_i2, instr_opcode2 };
    appendInto(instr_fmt);
}

//SIY: D1(B1),I2 | D1(B1)
void opSIY(int opCode, const AddrDB& db1, const int& i2= {}  ){
    //bit_fields: [('opcode1', 8), ('i2', 8), ('b1', 4), ('dl1', 12), ('dh1', 8), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_dh1 = local::shift_right_mask(db1.disp, 12, 8);
    auto instr_dl1 = local::mask(db1.disp, 12);
    auto instr_b1 = local::mask(db1.regb.getIdx(),4);
    auto instr_i2 = local::mask(i2,8);
    Format_SIY instr_fmt = { instr_opcode1, instr_i2, instr_b1, instr_dl1, instr_dh1, instr_opcode2 };
    appendInto(instr_fmt);
}

//RI-a: R1,I2
void opRI_A(int opCode, const Operand& r1, const int& i2 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('opcode2', 4), ('i2', 16)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 4, 8);
    auto instr_opcode2 = local::mask(opCode, 4);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_i2 = local::mask(i2,16);
    Format_RI_A instr_fmt = { instr_opcode1, instr_r1, instr_opcode2, instr_i2 };
    appendInto(instr_fmt);
}

//SI: D1(B1),I2 | D2(B2)
void opSI(int opCode, const AddrDB& db1, const int& i2= {}  ){
    //bit_fields: [('opcode', 8), ('i2', 8), ('b1_b2', 4), ('d1_d2', 12)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_d1_d2 = local::mask(db1.disp,12);
    auto instr_b1_b2 = local::mask(db1.regb.getIdx(),4);
    auto instr_i2 = local::mask(i2,8);
    Format_SI instr_fmt = { instr_opcode, instr_i2, instr_b1_b2, instr_d1_d2 };
    appendInto(instr_fmt);
}

//SS-a: D1(L,B1),D2(B2) | D1(L1,B1),D2(B2)
void opSS_A(int opCode, const AddrDLB& dlb1, const AddrDB& db2 ){
    //bit_fields: [('opcode', 8), ('l1', 8), ('b1', 4), ('d1', 12), ('b2', 4), ('d2', 12)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_d1 = local::mask(dlb1.disp,12);
    auto instr_l1 = local::mask(dlb1.l,8);
    auto instr_b1 = local::mask(dlb1.regb.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    Format_SS_A instr_fmt = { instr_opcode, instr_l1, instr_b1, instr_d1, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//RXY-b: M1,D2(X2,B2)
void opRXY_B(int opCode, const int& m1, const AddrDXB& dxb2 ){
    //bit_fields: [('opcode1', 8), ('m1', 4), ('x2', 4), ('b2', 4), ('dl2', 12), ('dh2', 8), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_m1 = local::mask(m1,4);
    auto instr_dh2 = local::shift_right_mask(dxb2.disp, 12, 8);
    auto instr_dl2 = local::mask(dxb2.disp, 12);
    auto instr_x2 = local::mask(dxb2.regx.getIdx(),4);
    auto instr_b2 = local::mask(dxb2.regb.getIdx(),4);
    Format_RXY_B instr_fmt = { instr_opcode1, instr_m1, instr_x2, instr_b2, instr_dl2, instr_dh2, instr_opcode2 };
    appendInto(instr_fmt);
}

//RX-b: M1,D2(X2,B2)
void opRX_B(int opCode, const int& m1, const AddrDXB& dxb2 ){
    //bit_fields: [('opcode', 8), ('m1', 4), ('x2', 4), ('b2', 4), ('d2', 12)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_m1 = local::mask(m1,4);
    auto instr_d2 = local::mask(dxb2.disp,12);
    auto instr_x2 = local::mask(dxb2.regx.getIdx(),4);
    auto instr_b2 = local::mask(dxb2.regb.getIdx(),4);
    Format_RX_B instr_fmt = { instr_opcode, instr_m1, instr_x2, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//RS-a: R1,R3,D2(B2)
void opRS_A(int opCode, const Operand& r1, const Operand& r3, const AddrDB& db2 ){
    //bit_fields: [('opcode', 8), ('r1', 4), ('r3', 4), ('b2', 4), ('d2', 12)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    Format_RS_A instr_fmt = { instr_opcode, instr_r1, instr_r3, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//RS-a: R1,D2(B2)
void opRS_A(int opCode, const Operand& r1, const AddrDB& db2 ){
    //bit_fields: [('opcode', 8), ('r1', 4), ('r3', 4), ('b2', 4), ('d2', 12)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    Format_RS_A instr_fmt = { instr_opcode, instr_r1, 0, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//RSY-a: R1,R3,D2(B2)
void opRSY_A(int opCode, const Operand& r1, const Operand& r3, const AddrDB& db2 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('r3', 4), ('b2', 4), ('dl2', 12), ('dh2', 8), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_dh2 = local::shift_right_mask(db2.disp, 12, 8);
    auto instr_dl2 = local::mask(db2.disp, 12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    Format_RSY_A instr_fmt = { instr_opcode1, instr_r1, instr_r3, instr_b2, instr_dl2, instr_dh2, instr_opcode2 };
    appendInto(instr_fmt);
}

//SMI: M1,RI2,D3(B3)
void opSMI(int opCode, const int& m1, const int& ri2, const AddrDB& db3 ){
    //bit_fields: [('opcode', 8), ('m1', 4), ('unk', 4), ('b3', 4), ('d3', 12), ('ri2', 16)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_m1 = local::mask(m1,4);
    auto instr_ri2 = local::mask(ri2,16);
    auto instr_d3 = local::mask(db3.disp,12);
    auto instr_b3 = local::mask(db3.regb.getIdx(),4);
    Format_SMI instr_fmt = { instr_opcode, instr_m1, instr_b3, instr_d3, instr_ri2 };
    appendInto(instr_fmt);
}

//MII: M1,RI2,RI3
void opMII(int opCode, const int& m1, const int& ri2, const int& ri3 ){
    //bit_fields: [('opcode', 8), ('m1', 4), ('ri2', 12), ('ri3', 24)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_m1 = local::mask(m1,4);
    auto instr_ri2 = local::mask(ri2,12);
    auto instr_ri3 = local::mask(ri3,24);
    Format_MII instr_fmt = { instr_opcode, instr_m1, instr_ri2, instr_ri3 };
    appendInto(instr_fmt);
}

//RI-b: R1,RI2
void opRI_B(int opCode, const Operand& r1, const int& ri2 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('opcode2', 4), ('ri2', 16)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 4, 8);
    auto instr_opcode2 = local::mask(opCode, 4);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_ri2 = local::mask(ri2,16);
    Format_RI_B instr_fmt = { instr_opcode1, instr_r1, instr_opcode2, instr_ri2 };
    appendInto(instr_fmt);
}

//RIL-b: R1,RI2
void opRIL_B(int opCode, const Operand& r1, const int& ri2 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('opcode2', 4), ('ri2', 32)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 4, 8);
    auto instr_opcode2 = local::mask(opCode, 4);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_ri2 = local::mask(ri2,32);
    Format_RIL_B instr_fmt = { instr_opcode1, instr_r1, instr_opcode2, instr_ri2 };
    appendInto(instr_fmt);
}

//RI-c: M1,RI2
void opRI_C(int opCode, const int& m1, const int& ri2 ){
    //bit_fields: [('opcode1', 8), ('m1', 4), ('opcode2', 4), ('ri2', 16)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 4, 8);
    auto instr_opcode2 = local::mask(opCode, 4);
    auto instr_m1 = local::mask(m1,4);
    auto instr_ri2 = local::mask(ri2,16);
    Format_RI_C instr_fmt = { instr_opcode1, instr_m1, instr_opcode2, instr_ri2 };
    appendInto(instr_fmt);
}

//RIL-c: M1,RI2
void opRIL_C(int opCode, const int& m1, const int& ri2 ){
    //bit_fields: [('opcode1', 8), ('m1', 4), ('opcode2', 4), ('ri2', 32)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 4, 8);
    auto instr_opcode2 = local::mask(opCode, 4);
    auto instr_m1 = local::mask(m1,4);
    auto instr_ri2 = local::mask(ri2,32);
    Format_RIL_C instr_fmt = { instr_opcode1, instr_m1, instr_opcode2, instr_ri2 };
    appendInto(instr_fmt);
}

//RSI: R1,R3,RI2
void opRSI(int opCode, const Operand& r1, const Operand& r3, const int& ri2 ){
    //bit_fields: [('opcode', 8), ('r1', 4), ('r3', 4), ('ri2', 16)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_ri2 = local::mask(ri2,16);
    Format_RSI instr_fmt = { instr_opcode, instr_r1, instr_r3, instr_ri2 };
    appendInto(instr_fmt);
}

//RIE-e: R1,R3,RI2
void opRIE_E(int opCode, const Operand& r1, const Operand& r3, const int& ri2 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('r3', 4), ('ri2', 16), ('unk', 8), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_ri2 = local::mask(ri2,16);
    Format_RIE_E instr_fmt = { instr_opcode1, instr_r1, instr_r3, instr_ri2, instr_opcode2 };
    appendInto(instr_fmt);
}

//RRF-b: R1,R3,R2 | R1,R3,R2[,M4] | R1,R3,R2,M4
void opRRF_B(int opCode, const Operand& r1, const Operand& r3, const Operand& r2, const int& m4= {}  ){
    //bit_fields: [('opcode', 16), ('r3', 4), ('m4', 4), ('r1', 4), ('r2', 4)]
    auto instr_opcode = local::mask(opCode,16);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    auto instr_m4 = local::mask(m4,4);
    Format_RRF_B instr_fmt = { instr_opcode, instr_r3, instr_m4, instr_r1, instr_r2 };
    appendInto(instr_fmt);
}

//RRS: R1,R2,M3,D4(B4)
void opRRS(int opCode, const Operand& r1, const Operand& r2, const int& m3, const AddrDB& db4 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('r2', 4), ('b4', 4), ('d4', 12), ('m3', 4), ('unk', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    auto instr_d4 = local::mask(db4.disp,12);
    auto instr_b4 = local::mask(db4.regb.getIdx(),4);
    Format_RRS instr_fmt = { instr_opcode1, instr_r1, instr_r2, instr_b4, instr_d4, instr_m3, instr_opcode2 };
    appendInto(instr_fmt);
}

//RIE-b: R1,R2,M3,RI4
void opRIE_B(int opCode, const Operand& r1, const Operand& r2, const int& m3, const int& ri4 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('r2', 4), ('ri4', 16), ('m3', 4), ('unk', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    auto instr_ri4 = local::mask(ri4,16);
    Format_RIE_B instr_fmt = { instr_opcode1, instr_r1, instr_r2, instr_ri4, instr_m3, instr_opcode2 };
    appendInto(instr_fmt);
}

//RIS: R1,I2,M3,D4(B4)
void opRIS(int opCode, const Operand& r1, const int& i2, const int& m3, const AddrDB& db4 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('m3', 4), ('b4', 4), ('d4', 12), ('i2', 8), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_i2 = local::mask(i2,8);
    auto instr_m3 = local::mask(m3,4);
    auto instr_d4 = local::mask(db4.disp,12);
    auto instr_b4 = local::mask(db4.regb.getIdx(),4);
    Format_RIS instr_fmt = { instr_opcode1, instr_r1, instr_m3, instr_b4, instr_d4, instr_i2, instr_opcode2 };
    appendInto(instr_fmt);
}

//RIE-c: R1,I2,M3,RI4
void opRIE_C(int opCode, const Operand& r1, const int& i2, const int& m3, const int& ri4 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('m3', 4), ('ri4', 16), ('i2', 8), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_i2 = local::mask(i2,8);
    auto instr_m3 = local::mask(m3,4);
    auto instr_ri4 = local::mask(ri4,16);
    Format_RIE_C instr_fmt = { instr_opcode1, instr_r1, instr_m3, instr_ri4, instr_i2, instr_opcode2 };
    appendInto(instr_fmt);
}

//S: D2(B2) | 
void opS(int opCode, const AddrDB& db2= {}  ){
    //bit_fields: [('opcode', 16), ('b2', 4), ('d2', 12)]
    auto instr_opcode = local::mask(opCode,16);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    Format_S instr_fmt = { instr_opcode, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//SSF: D1(B1),D2(B2),R3
void opSSF(int opCode, const AddrDB& db1, const AddrDB& db2, const Operand& r3 ){
    //bit_fields: [('opcode1', 8), ('r3', 4), ('opcode2', 4), ('b1', 4), ('d1', 12), ('b2', 4), ('d2', 12)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 4, 8);
    auto instr_opcode2 = local::mask(opCode, 4);
    auto instr_d1 = local::mask(db1.disp,12);
    auto instr_b1 = local::mask(db1.regb.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    Format_SSF instr_fmt = { instr_opcode1, instr_r3, instr_opcode2, instr_b1, instr_d1, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//SSF: R3,D1(B1),D2(B2)
void opSSF(int opCode, const Operand& r3, const AddrDB& db1, const AddrDB& db2 ){
    //bit_fields: [('opcode1', 8), ('r3', 4), ('opcode2', 4), ('b1', 4), ('d1', 12), ('b2', 4), ('d2', 12)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 4, 8);
    auto instr_opcode2 = local::mask(opCode, 4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_d1 = local::mask(db1.disp,12);
    auto instr_b1 = local::mask(db1.regb.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    Format_SSF instr_fmt = { instr_opcode1, instr_r3, instr_opcode2, instr_b1, instr_d1, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//RRF-c: R1,R2,M3 | R1,R2[,M3]
void opRRF_C(int opCode, const Operand& r1, const Operand& r2, const int& m3= {}  ){
    //bit_fields: [('opcode', 16), ('m3', 4), ('m4', 4), ('r1', 4), ('r2', 4)]
    auto instr_opcode = local::mask(opCode,16);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    Format_RRF_C instr_fmt = { instr_opcode, instr_m3, 0, instr_r1, instr_r2 };
    appendInto(instr_fmt);
}

//RIE-a: R1,I2,M3
void opRIE_A(int opCode, const Operand& r1, const int& i2, const int& m3 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('unk1', 4), ('i2', 16), ('m3', 4), ('unk2', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_i2 = local::mask(i2,16);
    auto instr_m3 = local::mask(m3,4);
    Format_RIE_A instr_fmt = { instr_opcode1, instr_r1, 0, instr_i2, instr_m3, 0, instr_opcode2 };
    appendInto(instr_fmt);
}

//SIL: D1(B1),I2
void opSIL(int opCode, const AddrDB& db1, const int& i2 ){
    //bit_fields: [('opcode', 16), ('b1', 4), ('d1', 12), ('i2', 16)]
    auto instr_opcode = local::mask(opCode,16);
    auto instr_d1 = local::mask(db1.disp,12);
    auto instr_b1 = local::mask(db1.regb.getIdx(),4);
    auto instr_i2 = local::mask(i2,16);
    Format_SIL instr_fmt = { instr_opcode, instr_b1, instr_d1, instr_i2 };
    appendInto(instr_fmt);
}

//RSY-b: R1,M3,D2(B2)
void opRSY_B(int opCode, const Operand& r1, const int& m3, const AddrDB& db2 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('m3', 4), ('b2', 4), ('dl2', 12), ('dh2', 8), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    auto instr_dh2 = local::shift_right_mask(db2.disp, 12, 8);
    auto instr_dl2 = local::mask(db2.disp, 12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    Format_RSY_B instr_fmt = { instr_opcode1, instr_r1, instr_m3, instr_b2, instr_dl2, instr_dh2, instr_opcode2 };
    appendInto(instr_fmt);
}

//RSY-b: R1,D2(B2),M3
void opRSY_B(int opCode, const Operand& r1, const AddrDB& db2, const int& m3 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('m3', 4), ('b2', 4), ('dl2', 12), ('dh2', 8), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_dh2 = local::shift_right_mask(db2.disp, 12, 8);
    auto instr_dl2 = local::mask(db2.disp, 12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    Format_RSY_B instr_fmt = { instr_opcode1, instr_r1, instr_m3, instr_b2, instr_dl2, instr_dh2, instr_opcode2 };
    appendInto(instr_fmt);
}

//RS-b: R1,M3,D2(B2)
void opRS_B(int opCode, const Operand& r1, const int& m3, const AddrDB& db2 ){
    //bit_fields: [('opcode', 8), ('r1', 4), ('m3', 4), ('b2', 4), ('d2', 12)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    Format_RS_B instr_fmt = { instr_opcode, instr_r1, instr_m3, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//RXE: R1,D2(X2,B2),M3 | R1,D2(X2,B2)
void opRXE(int opCode, const Operand& r1, const AddrDXB& dxb2, const int& m3= {}  ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('x2', 4), ('b2', 4), ('d2', 12), ('m3', 4), ('unk', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_d2 = local::mask(dxb2.disp,12);
    auto instr_x2 = local::mask(dxb2.regx.getIdx(),4);
    auto instr_b2 = local::mask(dxb2.regb.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    Format_RXE instr_fmt = { instr_opcode1, instr_r1, instr_x2, instr_b2, instr_d2, instr_m3, instr_opcode2 };
    appendInto(instr_fmt);
}

//RIE-g: R1,I2,M3
void opRIE_G(int opCode, const Operand& r1, const int& i2, const int& m3 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('m3', 4), ('i2', 16), ('unk', 8), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_i2 = local::mask(i2,16);
    auto instr_m3 = local::mask(m3,4);
    Format_RIE_G instr_fmt = { instr_opcode1, instr_r1, instr_m3, instr_i2, instr_opcode2 };
    appendInto(instr_fmt);
}

//SS-e: R1,R3,D2(B2),D4(B4)
void opSS_E(int opCode, const Operand& r1, const Operand& r3, const AddrDB& db2, const AddrDB& db4 ){
    //bit_fields: [('opcode', 8), ('r1', 4), ('r3', 4), ('b2', 4), ('d2', 12), ('b4', 4), ('d4', 12)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    auto instr_d4 = local::mask(db4.disp,12);
    auto instr_b4 = local::mask(db4.regb.getIdx(),4);
    Format_SS_E instr_fmt = { instr_opcode, instr_r1, instr_r3, instr_b2, instr_d2, instr_b4, instr_d4 };
    appendInto(instr_fmt);
}

//SS-e: R1,D2(B2),R3,D4(B4)
void opSS_E(int opCode, const Operand& r1, const AddrDB& db2, const Operand& r3, const AddrDB& db4 ){
    //bit_fields: [('opcode', 8), ('r1', 4), ('r3', 4), ('b2', 4), ('d2', 12), ('b4', 4), ('d4', 12)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_d4 = local::mask(db4.disp,12);
    auto instr_b4 = local::mask(db4.regb.getIdx(),4);
    Format_SS_E instr_fmt = { instr_opcode, instr_r1, instr_r3, instr_b2, instr_d2, instr_b4, instr_d4 };
    appendInto(instr_fmt);
}

//SSE: D1(B1),D2(B2)
void opSSE(int opCode, const AddrDB& db1, const AddrDB& db2 ){
    //bit_fields: [('opcode', 16), ('b1', 4), ('d1', 12), ('b2', 4), ('d2', 12)]
    auto instr_opcode = local::mask(opCode,16);
    auto instr_d1 = local::mask(db1.disp,12);
    auto instr_b1 = local::mask(db1.regb.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    Format_SSE instr_fmt = { instr_opcode, instr_b1, instr_d1, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//SS-b: D1(L1,B1),D2(L2,B2)
void opSS_B(int opCode, const AddrDLB& dlb1, const AddrDLB& dlb2 ){
    //bit_fields: [('opcode', 8), ('l1', 4), ('l2', 4), ('b1', 4), ('d1', 12), ('b2', 4), ('d2', 12)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_d1 = local::mask(dlb1.disp,12);
    auto instr_l1 = local::mask(dlb1.l,4);
    auto instr_b1 = local::mask(dlb1.regb.getIdx(),4);
    auto instr_d2 = local::mask(dlb2.disp,12);
    auto instr_l2 = local::mask(dlb2.l,4);
    auto instr_b2 = local::mask(dlb2.regb.getIdx(),4);
    Format_SS_B instr_fmt = { instr_opcode, instr_l1, instr_l2, instr_b1, instr_d1, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//IE: I1,I2
void opIE(int opCode, const int& i1, const int& i2 ){
    //bit_fields: [('opcode', 16), ('unk', 8), ('i1', 4), ('i2', 4)]
    auto instr_opcode = local::mask(opCode,16);
    auto instr_i1 = local::mask(i1,4);
    auto instr_i2 = local::mask(i2,4);
    Format_IE instr_fmt = { instr_opcode, instr_i1, instr_i2 };
    appendInto(instr_fmt);
}

//SS-f: D1(B1),D2(L2,B2)
void opSS_F(int opCode, const AddrDB& db1, const AddrDLB& dlb2 ){
    //bit_fields: [('opcode', 8), ('l2', 8), ('b1', 4), ('d1', 12), ('b2', 4), ('d2', 12)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_d1 = local::mask(db1.disp,12);
    auto instr_b1 = local::mask(db1.regb.getIdx(),4);
    auto instr_d2 = local::mask(dlb2.disp,12);
    auto instr_l2 = local::mask(dlb2.l,8);
    auto instr_b2 = local::mask(dlb2.regb.getIdx(),4);
    Format_SS_F instr_fmt = { instr_opcode, instr_l2, instr_b1, instr_d1, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//RIE-f: R1,R2,I3,I4[,I5]
void opRIE_F(int opCode, const Operand& r1, const Operand& r2, const int& i3, const int& i4, const int& i5= {}  ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('r2', 4), ('i3', 8), ('i4', 8), ('i5', 8), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    auto instr_i3 = local::mask(i3,8);
    auto instr_i4 = local::mask(i4,8);
    auto instr_i5 = local::mask(i5,8);
    Format_RIE_F instr_fmt = { instr_opcode1, instr_r1, instr_r2, instr_i3, instr_i4, instr_i5, instr_opcode2 };
    appendInto(instr_fmt);
}

//E: 
void opE(int opCode ){
    //bit_fields: [('opcode', 16)]
    auto instr_opcode = local::mask(opCode,16);
    Format_E instr_fmt = { instr_opcode };
    appendInto(instr_fmt);
}

//I: I
void opI(int opCode, const int& i ){
    //bit_fields: [('opcode', 8), ('i', 8)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_i = local::mask(i,8);
    Format_I instr_fmt = { instr_opcode, instr_i };
    appendInto(instr_fmt);
}

//SS-c: D1(L1,B1),D2(B2),I3
void opSS_C(int opCode, const AddrDLB& dlb1, const AddrDB& db2, const int& i3 ){
    //bit_fields: [('opcode', 8), ('l1', 4), ('i3', 4), ('b1', 4), ('d1', 12), ('b2', 4), ('d2', 12)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_d1 = local::mask(dlb1.disp,12);
    auto instr_l1 = local::mask(dlb1.l,4);
    auto instr_b1 = local::mask(dlb1.regb.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    auto instr_i3 = local::mask(i3,4);
    Format_SS_C instr_fmt = { instr_opcode, instr_l1, instr_i3, instr_b1, instr_d1, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//RSL-a: D1(L1,B1)
void opRSL_A(int opCode, const AddrDLB& dlb1 ){
    //bit_fields: [('opcode1', 8), ('l1', 4), ('unk', 4), ('b1', 4), ('d1', 12), ('unk2', 8), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_d1 = local::mask(dlb1.disp,12);
    auto instr_l1 = local::mask(dlb1.l,4);
    auto instr_b1 = local::mask(dlb1.regb.getIdx(),4);
    Format_RSL_A instr_fmt = { instr_opcode1, instr_l1, instr_b1, instr_d1, 0, instr_opcode2 };
    appendInto(instr_fmt);
}

//RRF-e: R1,M3,R2 | R1,M3,R2,M4
void opRRF_E(int opCode, const Operand& r1, const int& m3, const Operand& r2, const int& m4= {}  ){
    //bit_fields: [('opcode', 16), ('m3', 4), ('m4', 4), ('r1', 4), ('r2', 4)]
    auto instr_opcode = local::mask(opCode,16);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    auto instr_m4 = local::mask(m4,4);
    Format_RRF_E instr_fmt = { instr_opcode, instr_m3, instr_m4, instr_r1, instr_r2 };
    appendInto(instr_fmt);
}

//SS-d: D1(R1,B1),D2(B2),R3
void opSS_D(int opCode, const AddrDRB& drb1, const AddrDB& db2, const Operand& r3 ){
    //bit_fields: [('opcode', 8), ('r1', 4), ('r3', 4), ('b1', 4), ('d1', 12), ('b2', 4), ('d2', 12)]
    auto instr_opcode = local::mask(opCode,8);
    auto instr_d1 = local::mask(drb1.disp,12);
    auto instr_r1 = local::mask(drb1.regx.getIdx(),4);
    auto instr_b1 = local::mask(drb1.regb.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    Format_SS_D instr_fmt = { instr_opcode, instr_r1, instr_r3, instr_b1, instr_d1, instr_b2, instr_d2 };
    appendInto(instr_fmt);
}

//RRD: R1,R3,R2
void opRRD(int opCode, const Operand& r1, const Operand& r3, const Operand& r2 ){
    //bit_fields: [('opcode', 16), ('r1', 4), ('unk', 4), ('r3', 4), ('r2', 4)]
    auto instr_opcode = local::mask(opCode,16);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    Format_RRD instr_fmt = { instr_opcode, instr_r1, instr_r3, instr_r2 };
    appendInto(instr_fmt);
}

//RXF: R1,R3,D2(X2,B2)
void opRXF(int opCode, const Operand& r1, const Operand& r3, const AddrDXB& dxb2 ){
    //bit_fields: [('opcode1', 8), ('r3', 4), ('x2', 4), ('b2', 4), ('d2', 12), ('r1', 4), ('unk', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_d2 = local::mask(dxb2.disp,12);
    auto instr_x2 = local::mask(dxb2.regx.getIdx(),4);
    auto instr_b2 = local::mask(dxb2.regb.getIdx(),4);
    Format_RXF instr_fmt = { instr_opcode1, instr_r3, instr_x2, instr_b2, instr_d2, instr_r1, instr_opcode2 };
    appendInto(instr_fmt);
}

//RSL-b: R1,D2(L2,B2),M3
void opRSL_B(int opCode, const Operand& r1, const AddrDLB& dlb2, const int& m3 ){
    //bit_fields: [('opcode1', 8), ('l2', 8), ('b2', 4), ('d2', 12), ('r1', 4), ('m3', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_d2 = local::mask(dlb2.disp,12);
    auto instr_l2 = local::mask(dlb2.l,8);
    auto instr_b2 = local::mask(dlb2.regb.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    Format_RSL_B instr_fmt = { instr_opcode1, instr_l2, instr_b2, instr_d2, instr_r1, instr_m3, instr_opcode2 };
    appendInto(instr_fmt);
}

//RRF-d: R1,R2,M4
void opRRF_D(int opCode, const Operand& r1, const Operand& r2, const int& m4 ){
    //bit_fields: [('opcode', 16), ('m3', 4), ('m4', 4), ('r1', 4), ('r2', 4)]
    auto instr_opcode = local::mask(opCode,16);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    auto instr_m4 = local::mask(m4,4);
    Format_RRF_D instr_fmt = { instr_opcode, 0, instr_m4, instr_r1, instr_r2 };
    appendInto(instr_fmt);
}

//VRR-c: V1,V2,V3 | V1,V2,V3,M4 | V1,V2,V3,M4,M5 | V1,V2,V3,M4,M5,M6
void opVRR_C(int opCode, const VReg& v1, const VReg& v2, const VReg& v3, const int& m4= {} , const int& m5= {} , const int& m6= {}  ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v2', 4), ('v3', 4), ('unk1', 4), ('m6', 4), ('m5', 4), ('m4', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_v3 = local::mask(v3.getIdx(),4);
    auto instr_m4 = local::mask(m4,4);
    auto instr_m5 = local::mask(m5,4);
    auto instr_m6 = local::mask(m6,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v2.getIdx(), v3.getIdx());
    Format_VRR_C instr_fmt = { instr_opcode1, instr_v1, instr_v2, instr_v3, 0, instr_m6, instr_m5, instr_m4, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRV: V1,D2(V2,B2),M3
void opVRV(int opCode, const VReg& v1, const AddrDVB& dvb2, const int& m3 ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v2', 4), ('b2', 4), ('d2', 12), ('m3', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_d2 = local::mask(dvb2.disp,12);
    auto v2 = dvb2.regv;
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_b2 = local::mask(dvb2.regb.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v2.getIdx());
    Format_VRV instr_fmt = { instr_opcode1, instr_v1, instr_v2, instr_b2, instr_d2, instr_m3, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRI-a: V1,I2 | V1,I2,M3
void opVRI_A(int opCode, const VReg& v1, const int& i2, const int& m3= {}  ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('unk', 4), ('i2', 16), ('m3', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_i2 = local::mask(i2,16);
    auto instr_m3 = local::mask(m3,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx());
    Format_VRI_A instr_fmt = { instr_opcode1, instr_v1, instr_i2, instr_m3, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRI-b: V1,I2,I3,M4
void opVRI_B(int opCode, const VReg& v1, const int& i2, const int& i3, const int& m4 ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('unk', 4), ('i2', 8), ('i3', 8), ('m4', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_i2 = local::mask(i2,8);
    auto instr_i3 = local::mask(i3,8);
    auto instr_m4 = local::mask(m4,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx());
    Format_VRI_B instr_fmt = { instr_opcode1, instr_v1, instr_i2, instr_i3, instr_m4, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRX: V1,D2(X2,B2)[,M3] | V1,D2(X2,B2),M3
void opVRX(int opCode, const VReg& v1, const AddrDXB& dxb2, const int& m3= {}  ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('x2', 4), ('b2', 4), ('d2', 12), ('m3', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_d2 = local::mask(dxb2.disp,12);
    auto instr_x2 = local::mask(dxb2.regx.getIdx(),4);
    auto instr_b2 = local::mask(dxb2.regb.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx());
    Format_VRX instr_fmt = { instr_opcode1, instr_v1, instr_x2, instr_b2, instr_d2, instr_m3, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRR-a: V1,V2 | V1,V2,M3 | V1,V2,M3[,M5] | V1,V2,M3,M4 | V1,V2,M3,M4,M5
void opVRR_A(int opCode, const VReg& v1, const VReg& v2, const int& m3= {} , const int& m4= {} , const int& m5= {}  ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v2', 4), ('unk', 8), ('m5', 4), ('m4', 4), ('m3', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    auto instr_m4 = local::mask(m4,4);
    auto instr_m5 = local::mask(m5,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v2.getIdx());
    Format_VRR_A instr_fmt = { instr_opcode1, instr_v1, instr_v2, instr_m5, instr_m4, instr_m3, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRS-c: R1,V3,D2(B2),M4
void opVRS_C(int opCode, const Operand& r1, const VReg& v3, const AddrDB& db2, const int& m4 ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('v3', 4), ('b2', 4), ('d2', 12), ('m4', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_v3 = local::mask(v3.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    auto instr_m4 = local::mask(m4,4);
    auto instr_rxb = local::mask_rxb(v3.getIdx());
    Format_VRS_C instr_fmt = { instr_opcode1, instr_r1, instr_v3, instr_b2, instr_d2, instr_m4, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRS-a: V1,V3,D2(B2)[,M4] | V1,V3,D2(B2),M4
void opVRS_A(int opCode, const VReg& v1, const VReg& v3, const AddrDB& db2, const int& m4= {}  ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v3', 4), ('b2', 4), ('d2', 12), ('m4', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v3 = local::mask(v3.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    auto instr_m4 = local::mask(m4,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v3.getIdx());
    Format_VRS_A instr_fmt = { instr_opcode1, instr_v1, instr_v3, instr_b2, instr_d2, instr_m4, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRS-d: V1,R3,D2(B2)
void opVRS_D(int opCode, const VReg& v1, const Operand& r3, const AddrDB& db2 ){
    //bit_fields: [('opcode1', 8), ('unk', 4), ('r3', 4), ('b2', 4), ('d2', 12), ('v1', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    auto instr_rxb = local::mask_rxb(v1.getIdx());
    Format_VRS_D instr_fmt = { instr_opcode1, instr_r3, instr_b2, instr_d2, instr_v1, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VSI: V1,D2(B2),I3
void opVSI(int opCode, const VReg& v1, const AddrDB& db2, const int& i3 ){
    //bit_fields: [('opcode1', 8), ('i3', 8), ('b2', 4), ('d2', 12), ('v1', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    auto instr_i3 = local::mask(i3,8);
    auto instr_rxb = local::mask_rxb(v1.getIdx());
    Format_VSI instr_fmt = { instr_opcode1, instr_i3, instr_b2, instr_d2, instr_v1, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRS-b: V1,R3,D2(B2),M4 | V1,R3,D2(B2)
void opVRS_B(int opCode, const VReg& v1, const Operand& r3, const AddrDB& db2, const int& m4= {}  ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('r3', 4), ('b2', 4), ('d2', 12), ('m4', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_d2 = local::mask(db2.disp,12);
    auto instr_b2 = local::mask(db2.regb.getIdx(),4);
    auto instr_m4 = local::mask(m4,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx());
    Format_VRS_B instr_fmt = { instr_opcode1, instr_v1, instr_r3, instr_b2, instr_d2, instr_m4, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRR-f: V1,R2,R3
void opVRR_F(int opCode, const VReg& v1, const Operand& r2, const Operand& r3 ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('r2', 4), ('r3', 4), ('unk', 16), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    auto instr_r3 = local::mask(r3.getIdx(),4);
    auto instr_rxb = local::mask_rxb(v1.getIdx());
    Format_VRR_F instr_fmt = { instr_opcode1, instr_v1, instr_r2, instr_r3, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRR-b: V1,V2,V3,M4,M5 | V1,V2,V3,M4[,M5] | V1,V2,V3
void opVRR_B(int opCode, const VReg& v1, const VReg& v2, const VReg& v3, const int& m4= {} , const int& m5= {}  ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v2', 4), ('v3', 4), ('unk1', 4), ('m5', 4), ('unk2', 4), ('m4', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_v3 = local::mask(v3.getIdx(),4);
    auto instr_m4 = local::mask(m4,4);
    auto instr_m5 = local::mask(m5,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v2.getIdx(), v3.getIdx());
    Format_VRR_B instr_fmt = { instr_opcode1, instr_v1, instr_v2, instr_v3, 0, instr_m5, 0, instr_m4, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRR-e: V1,V2,V3,V4 | V1,V2,V3,V4,M5,M6
void opVRR_E(int opCode, const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5= {} , const int& m6= {}  ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v2', 4), ('v3', 4), ('m6', 4), ('unk', 4), ('m5', 4), ('v4', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_v3 = local::mask(v3.getIdx(),4);
    auto instr_v4 = local::mask(v4.getIdx(),4);
    auto instr_m5 = local::mask(m5,4);
    auto instr_m6 = local::mask(m6,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v2.getIdx(), v3.getIdx(), v4.getIdx());
    Format_VRR_E instr_fmt = { instr_opcode1, instr_v1, instr_v2, instr_v3, instr_m6, instr_m5, instr_v4, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRI-c: V1,V3,I2,M4
void opVRI_C(int opCode, const VReg& v1, const VReg& v3, const int& i2, const int& m4 ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v3', 4), ('i2', 16), ('m4', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v3 = local::mask(v3.getIdx(),4);
    auto instr_i2 = local::mask(i2,16);
    auto instr_m4 = local::mask(m4,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v3.getIdx());
    Format_VRI_C instr_fmt = { instr_opcode1, instr_v1, instr_v3, instr_i2, instr_m4, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRR-d: V1,V2,V3,V4,M5 | V1,V2,V3,V4,M5,M6 | V1,V2,V3,V4,M5[,M6] | V1,V2,V3,V4,M5,[M6]
void opVRR_D(int opCode, const VReg& v1, const VReg& v2, const VReg& v3, const VReg& v4, const int& m5, const int& m6= {}  ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v2', 4), ('v3', 4), ('m5', 4), ('m6', 4), ('unk', 4), ('v4', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_v3 = local::mask(v3.getIdx(),4);
    auto instr_v4 = local::mask(v4.getIdx(),4);
    auto instr_m5 = local::mask(m5,4);
    auto instr_m6 = local::mask(m6,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v2.getIdx(), v3.getIdx(), v4.getIdx());
    Format_VRR_D instr_fmt = { instr_opcode1, instr_v1, instr_v2, instr_v3, instr_m5, instr_m6, instr_v4, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRI-d: V1,V2,V3,I4,M5 | V1,V2,V3,I4
void opVRI_D(int opCode, const VReg& v1, const VReg& v2, const VReg& v3, const int& i4, const int& m5= {}  ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v2', 4), ('v3', 4), ('unk', 4), ('i4', 8), ('m5', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_v3 = local::mask(v3.getIdx(),4);
    auto instr_i4 = local::mask(i4,8);
    auto instr_m5 = local::mask(m5,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v2.getIdx(), v3.getIdx());
    Format_VRI_D instr_fmt = { instr_opcode1, instr_v1, instr_v2, instr_v3, instr_i4, instr_m5, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRI-e: V1,V2,I3,M4,M5
void opVRI_E(int opCode, const VReg& v1, const VReg& v2, const int& i3, const int& m4, const int& m5 ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v2', 4), ('i3', 12), ('m5', 4), ('m4', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_i3 = local::mask(i3,12);
    auto instr_m4 = local::mask(m4,4);
    auto instr_m5 = local::mask(m5,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v2.getIdx());
    Format_VRI_E instr_fmt = { instr_opcode1, instr_v1, instr_v2, instr_i3, instr_m5, instr_m4, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRI-f: V1,V2,V3,I4,M5
void opVRI_F(int opCode, const VReg& v1, const VReg& v2, const VReg& v3, const int& i4, const int& m5 ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v2', 4), ('v3', 4), ('unk', 4), ('m5', 4), ('i4', 8), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_v3 = local::mask(v3.getIdx(),4);
    auto instr_i4 = local::mask(i4,8);
    auto instr_m5 = local::mask(m5,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v2.getIdx(), v3.getIdx());
    Format_VRI_F instr_fmt = { instr_opcode1, instr_v1, instr_v2, instr_v3, instr_m5, instr_i4, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRR-h: V1,V2,M3
void opVRR_H(int opCode, const VReg& v1, const VReg& v2, const int& m3 ){
    //bit_fields: [('opcode1', 8), ('unk1', 4), ('v1', 4), ('v2', 4), ('unk2', 4), ('m3', 4), ('unk3', 8), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v2.getIdx());
    Format_VRR_H instr_fmt = { instr_opcode1, 0, instr_v1, instr_v2, 0, instr_m3, 0, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRR-i: R1,V2,M3[,M4]
void opVRR_I(int opCode, const Operand& r1, const VReg& v2, const int& m3, const int& m4= {}  ){
    //bit_fields: [('opcode1', 8), ('r1', 4), ('v2', 4), ('unk1', 8), ('m3', 4), ('m4', 4), ('unk2', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_r1 = local::mask(r1.getIdx(),4);
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    auto instr_m4 = local::mask(m4,4);
    auto instr_rxb = local::mask_rxb(v2.getIdx());
    Format_VRR_I instr_fmt = { instr_opcode1, instr_r1, instr_v2, 0, instr_m3, instr_m4, 0, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRI-i: V1,R2,I3,M4
void opVRI_I(int opCode, const VReg& v1, const Operand& r2, const int& i3, const int& m4 ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('r2', 4), ('unk', 8), ('m4', 4), ('i3', 8), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_r2 = local::mask(r2.getIdx(),4);
    auto instr_i3 = local::mask(i3,8);
    auto instr_m4 = local::mask(m4,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx());
    Format_VRI_I instr_fmt = { instr_opcode1, instr_v1, instr_r2, instr_m4, instr_i3, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRR-j: V1,V2,V3,M4
void opVRR_J(int opCode, const VReg& v1, const VReg& v2, const VReg& v3, const int& m4 ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v2', 4), ('v3', 4), ('unk', 4), ('m4', 4), ('unk', 8), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_v3 = local::mask(v3.getIdx(),4);
    auto instr_m4 = local::mask(m4,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v2.getIdx(), v3.getIdx());
    Format_VRR_J instr_fmt = { instr_opcode1, instr_v1, instr_v2, instr_v3, instr_m4, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRR-k: V1,V2,M3
void opVRR_K(int opCode, const VReg& v1, const VReg& v2, const int& m3 ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v2', 4), ('unk', 8), ('m3', 4), ('unk', 8), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_m3 = local::mask(m3,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v2.getIdx());
    Format_VRR_K instr_fmt = { instr_opcode1, instr_v1, instr_v2, instr_m3, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRI-h: V1,I2,I3
void opVRI_H(int opCode, const VReg& v1, const int& i2, const int& i3 ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('unk', 4), ('i2', 16), ('i3', 4), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_i2 = local::mask(i2,16);
    auto instr_i3 = local::mask(i3,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx());
    Format_VRI_H instr_fmt = { instr_opcode1, instr_v1, instr_i2, instr_i3, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRI-g: V1,V2,I3,I4,M5
void opVRI_G(int opCode, const VReg& v1, const VReg& v2, const int& i3, const int& i4, const int& m5 ){
    //bit_fields: [('opcode1', 8), ('v1', 4), ('v2', 4), ('i4', 8), ('m5', 4), ('i3', 8), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_v2 = local::mask(v2.getIdx(),4);
    auto instr_i3 = local::mask(i3,8);
    auto instr_i4 = local::mask(i4,8);
    auto instr_m5 = local::mask(m5,4);
    auto instr_rxb = local::mask_rxb(v1.getIdx(), v2.getIdx());
    Format_VRI_G instr_fmt = { instr_opcode1, instr_v1, instr_v2, instr_i4, instr_m5, instr_i3, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

//VRR-g: V1
void opVRR_G(int opCode, const VReg& v1 ){
    //bit_fields: [('opcode1', 8), ('unk1', 4), ('v1', 4), ('unk2', 20), ('rxb', 4), ('opcode2', 8)]
    auto instr_opcode1 = local::shift_right_mask(opCode, 8, 8);
    auto instr_opcode2 = local::mask(opCode, 8);
    auto instr_v1 = local::mask(v1.getIdx(),4);
    auto instr_rxb = local::mask_rxb(v1.getIdx());
    Format_VRR_G instr_fmt = { instr_opcode1, 0, instr_v1, 0, instr_rxb, instr_opcode2 };
    appendInto(instr_fmt);
}

