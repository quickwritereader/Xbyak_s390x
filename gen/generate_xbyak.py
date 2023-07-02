#!/usr/bin/env python3
# coding: utf-8
import sys
import ast
from parse_signature import *
import re

print(
    """


       _                 _             ____   ___   ___        
      | |               | |           |___ \ / _ \ / _ \       
 __  _| |__  _   _  __ _| | __     ___  __) | (_) | | | |_  __ 
 \ \/ / '_ \| | | |/ _` | |/ /    / __||__ < \__, | | | \ \/ / 
  >  <| |_) | |_| | (_| |   <     \__ \___) |  / /| |_| |>  <  
 /_/\_\_.__/ \__, |\__,_|_|\_\    |___/____/  /_/  \___//_/\_\ 
   _____      __/ |                                         
  / ____|    |___/ |                                        
 | |     ___   __| | ___    __ _  ___ _ __                  
 | |    / _ \ / _` |/ _ \  / _` |/ _ \ '_ \                 
 | |___| (_) | (_| |  __/ | (_| |  __/ | | |                
  \_____\___/ \__,_|\___|  \__, |\___|_| |_|                
                            __/ |                           
                           |___/                            
"""
)

if len(sys.argv) < 2:
    print("python3 generate_xbyak.py filename")
    exit(-1)
file_txt = sys.argv[1]

formats = ""
with open("instruction_formats.txt", "r") as f:
    formats = f.read()
fmt_signatures = None
with open(f"{file_txt}_signatures.txt", "r") as f:
    strX = f.read()
    fmt_signatures = ast.literal_eval(strX)
instr_extended = None
with open(f"{file_txt}_extended.txt", "r") as f:
    strX = f.read()
    instr_extended = ast.literal_eval(strX)


def struct_name(name, prefix="Format_"):
    name = prefix + name.replace("-", "_").strip().upper()
    return name


def pgen_formats(formats):
    fmt_dict = {}
    aliases = {}
    format_lines = formats.split("\n")
    # print(len(format_lines))
    for line in format_lines:
        ss = line.lower().split(",")
        # print(ss)
        if len(ss) <= 1:
            continue
        name = ""
        arr = ss[0].split("-")
        arr_size = len(arr)
        if arr_size <= 2:
            # it means simple
            name = struct_name(ss[0], "")
        elif arr_size == 3:
            # underline is aliased
            name = struct_name(ss[0], "")
            if arr[1] >= arr[2]:
                print(
                    f"error in format, name letters should be ranged {ss}",
                    file=sys.stderr,
                )
                return None
            for v in range(ord(arr[1]), ord(arr[2]) + 1):
                aliases[(arr[0] + "_" + chr(v)).upper()] = name
        else:
            print(f"error in format {ss}", file=sys.stderr)
            return None
        if name in fmt_dict:
            print(f"warning, duplicate in format {ss}", file=sys.stderr)
            continue
        listx = []
        for t in ss[1:]:
            # name_field:bit_width
            tr = t.split(":")
            if len(tr) != 2:
                print(f"error, in field format {ss}", file=sys.stderr)
                return None

            name_field = tr[0].strip()
            bit_width = int(tr[1].strip()) if tr[1].strip().isdigit() else None
            if len(name_field) < 1 or bit_width is None:
                print(f"error, in field format {ss}", file=sys.stderr)
                return None
            listx.append((name_field, bit_width))
        fmt_dict[name] = listx

    return (fmt_dict, aliases)


fmt, aliases = pgen_formats(formats)


def gen_struct(fmt_dict, aliasses, out=sys.stdout):
    instruction_format_header = """#pragma once

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
"""
    print(instruction_format_header, file=out)
    for k, v in fmt_dict.items():
        print(f"struct {struct_name(k)} {{", file=out)
        lenx = 0
        argx = []
        for name, bit_width in v:
            lenx += bit_width
            if name != "unk":
                argx.append(f"int64_t {name}")
        print(f"  packed_type<{lenx}>::typeX instr = 0;", file=out)
        print(f"  constexpr static size_t sizeOf(){{ return {lenx//8}; }}", file=out)
        underline_len = (lenx + 15) & -16
        if underline_len >= 48:
            underline_len = 64

        # constructor without unk
        print(f"  {struct_name(k)}({', '.join(argx)}){{", file=out)
        left = 0
        print(
            f"    instr = XBYAK_S390X_BIGENDIAN_{underline_len}( 0 ", end="", file=out
        )
        for name, bit_width in v:
            left += bit_width
            shift_left = underline_len - left
            if name == "unk":
                continue
            if shift_left < 1:
                print(f"| {name}", end="", file=out)
            else:
                print(
                    f"| ({name}<<{shift_left}) ",
                    end="",
                    file=out,
                )
        print(");\n  }\n};\n", file=out)

    for k, v in aliases.items():
        print(f"using {struct_name(k)} = {struct_name(v)};", file=out)


with open("xbyak_s390x_instr_formats.h", "w") as f:
    gen_struct(fmt, aliases, out=f)


import re

t_match = re.compile(r"^(d[lh]?|ri|r|v|m|x|b|i|l)(\d?)$")
explicit_map = {}


def getCppArgCall(signature, prefix="", length=ARG_MAX_NUMB):
    length = min(len(signature.argList), length)
    strX = ""
    if len(prefix) > 0 and endInd > 0:
        strX = prefix
    add_comma = True
    endInd = length - 1
    for i in range(0, length):
        toks = signature.argList[i]
        r = toks.getCppArgName()
        if len(r) < 1:
            continue

        if r == ")":
            add_comma = True
        elif r == "(":
            add_comma = False
        else:
            strX += r
        if i < endInd and add_comma:
            strX += ", "
    return strX


def getCppArgDecl(sn, prefix="int opCode", callback_modifier=None):
    listx = []
    if len(prefix):
        listx.append(prefix)
    for ind, toks in enumerate(sn.argList):
        typeX = toks.getCppArgType()
        if len(typeX) < 1:
            continue
        arg_name = toks.getCppArgName()
        if callback_modifier:
            typeX, arg_name = callback_modifier(typeX, arg_name)
        defaulted = "= {} " if ind >= sn.optionalStart else ""
        listx.append(f"const {typeX}& {arg_name}{defaulted}")
    return ", ".join(listx)


def branch_label(listx):
    def modifier(typeX, arg_name):
        if arg_name.startswith("ri") and len(listx) < 1:
            listx.append(arg_name)
            return ("Label", f"lbl_{arg_name}")
        else:
            return (typeX, arg_name)

    return modifier


def reg_change(regType, r_digit=-1):
    # -1 means change all
    # otherwise the one with r_digit will be changed
    def modifier(typeX, arg_name):
        digit = "" if r_digit == -1 else str(r_digit)
        if typeX == "Operand" and arg_name.startswith("r" + digit):
            return (regType, arg_name)
        elif typeX == "Operand" and r_digit != -1:
            # return GPReg
            return ("GPReg", arg_name)

        return (typeX, arg_name)

    return modifier


def getCppArgDeclMnemomic(sn, isa_table_def, call_op_key):
    """
    Returns (parameters, optional mapping)
    Optional mapping should be used inside body before calling core functins
    """
    global fmt
    modifier = reg_change("GPReg")
    instr_info = isa_table_def[0]
    # D-long E-SHORT X-extended
    if (
        "BFP" in instr_info
        or "HFP" in instr_info
        or "DFP" in instr_info
        or "short" in instr_info
        or "long" in instr_info
        or "extended" in instr_info
    ):
        # floating point
        # check if there is mixed register
        modifier = reg_change("FReg")
        if "to 64" in instr_info or "to 32" in instr_info:
            # this conversion from float type to general type, there for 1st should be GPReg, 2nd Freg
            modifier = reg_change("FReg", 2)
        elif "64 to" in instr_info or "32 to" in instr_info:
            # it means the first one should be Freg
            modifier = reg_change("FReg", 1)
    elif "ACCESS" in instr_info:
        modifier = reg_change("AReg")
        if "EXTRACT" in instr_info:
            # only second part
            modifier = reg_change("AReg", 2)
        elif "TEST" in instr_info or "SET" in instr_info:
            # second is GPReg
            modifier = reg_change("AReg", 1)
        elif not "ACCESS INTENT" in instr_info:
            modifier = reg_change("AReg")
    elif "LOAD CONTROL" in instr_info or "STORE CONTROL" in instr_info:
        modifier = reg_change("CReg")
    if "BRANCH RELATIVE" in instr_info:
        listx = []
        params = getCppArgDecl(sn, prefix="", callback_modifier=branch_label(listx))
        map_call = ""
        if len(listx) > 0:
            fmt_entry = fmt[call_op_key]
            entry = listx[0]
            start_bit = 0
            bit_width = 0
            for s, bit in fmt_entry:
                if s == entry:
                    bit_width = bit
                    break
                start_bit += bit

            map_call = f"auto {listx[0]} = encodeJmp(lbl_{listx[0]}, {start_bit}, {bit_width}); "

        return (params, map_call)

    params = getCppArgDecl(sn, prefix="", callback_modifier=modifier)
    return (params, "")


def get_accessor(fmt_fields):
    return_data = {"": {}}  # { arg_index_if_exist :{typex : list}}
    # print(f"---   {fmt_fields} ----")
    # group op codes
    for x, b in fmt_fields:
        if x.startswith("opcode"):
            if not "opcode" in return_data[""]:
                return_data[""]["opcode"] = []
            return_data[""]["opcode"].append((x, b))
        # split if one field can be assigned by two different
        g = x.split("_")
        for i in range(0, len(g)):
            z = t_match.match(g[i])
            if z:
                val = z.group(2)
                typex = z.group(1)
                if not val in return_data:
                    return_data[val] = {}
                if typex == "dl" or typex == "dh":
                    typex = "d"
                if not typex in return_data[val]:
                    return_data[val][typex] = [(x, b)]
                else:
                    return_data[val][typex].append((x, b))
                if typex == "v":
                    if not "rxb" in return_data[""]:
                        return_data[""]["rxb"] = []
                    return_data[""]["rxb"].append(x)

    return return_data


def write_assign_entry(
    field_name_entry, entry, entry_name, assign_list, out=sys.stdout
):
    space = "    "
    if entry in field_name_entry:
        t = field_name_entry[entry]
        if len(t) == 1:
            name, bit_field = t[0]
            print(
                f"{space}auto instr_{name} = local::mask({entry_name},{bit_field});",
                file=out,
            )
            assign_list.append(name)
            return True
        elif len(t) == 2:
            name_high, bit_field_high = t[0]
            name_low, bit_field_low = t[1]
            if name_low.startswith("dh"):
                # swap fix for dl, dh pairs when order is wrong
                name_high, name_low = name_low, name_high
                bit_field_high, bit_field_low = bit_field_low, bit_field_high
            print(
                f"{space}auto instr_{name_high} = local::shift_right_mask({entry_name}, {bit_field_low}, {bit_field_high});",
                file=out,
            )
            print(
                f"{space}auto instr_{name_low} = local::mask({entry_name}, {bit_field_low});",
                file=out,
            )
            assign_list.append(name_high)
            assign_list.append(name_low)
            return True
    print(f"{space}// error in assignment of the {entry_name}", file=out)
    return False


def gen_core_operations(fmt_signatures, fmt_dict, aliases, out=sys.stdout):
    global explicit_map
    for k, v in fmt_signatures.items():
        # remove [, ] while sorting to make it possible to merge unnecessary method declarations

        list_clear = []
        # if k=="VRR-a":
        #     ggg=""
        for ss in v.keys():
            added = False
            # merge signatures if possible, and also add descp
            for idx in range(0, len(list_clear)):
                p = list_clear[idx]
                param = Signature(ss)
                pp, amibiguity_index = getMergedSignature(p[0], param)
                if pp is not None:
                    list_clear[idx][0] = pp
                    list_clear[idx][1] = min(list_clear[idx][1], amibiguity_index)
                    list_clear[idx][2].append(ss)
                    added = True
                    break

            if not added:
                param = Signature(ss)
                list_clear.append([param, ARG_MAX_NUMB, [ss]])
        entry = struct_name(k, "")
        if entry in aliases:
            entry = aliases[entry]
        format_fields = fmt_dict[entry]
        alist = get_accessor(format_fields)
        for sn, amibiguity_index, ss_list in list_clear:
            print(f"//{k}: {' | '.join(ss_list)}", file=out)
            space = "    "
            op_name = struct_name(k, "op")
            if amibiguity_index != ARG_MAX_NUMB:
                # add this to our explicitly map list
                explicit_map[op_name] = (amibiguity_index, ss_list, sn)

            print(f"void {op_name}({getCppArgDecl(sn)} ){{", file=out)
            print(f"{space}//bit_fields: {format_fields}", file=out)
            assign_list = []
            write_assign_entry(alist[""], "opcode", "opCode", assign_list, out)

            for args in sn.argList:
                field_name_entry = None
                arg_val = f"{args.val}" if args.val != None and args.val >= 0 else ""
                if arg_val in alist:
                    field_name_entry = alist[arg_val]
                else:
                    print(f"//warning in arg gen: {args.getCppArgName()}", file=out)
                    continue
                if "d" in args.kind:
                    ok = True
                    for addr_kind in args.kind:
                        entry_name = f"{args.getCppArgName()}."
                        if addr_kind == "l":
                            entry_name += "l"
                        elif addr_kind == "d":
                            entry_name += "disp"
                        else:
                            # fix exception for "r" making it regx
                            entry_name += (
                                f"reg{addr_kind}" if addr_kind != "r" else "regx"
                            )
                            if addr_kind == "v":
                                print(
                                    f"{space}auto {addr_kind}{args.val} = {entry_name};",
                                    file=out,
                                )
                                entry_name = f"{addr_kind}{args.val}"
                            entry_name += ".getIdx()"
                        ok = ok and write_assign_entry(
                            field_name_entry, addr_kind, entry_name, assign_list, out
                        )
                    continue

                entry_name = (
                    f"{args.getCppArgName()}.getIdx()"
                    if args.kind in ["r", "v"]
                    else args.getCppArgName()
                )
                write_assign_entry(
                    field_name_entry, args.kind, entry_name, assign_list, out
                )
            if "rxb" in alist[""]:
                t = alist[""]["rxb"]
                ll = [f"{jj}.getIdx()" for jj in t]
                # write code for deducing rxb
                print(
                    f"{space}auto instr_rxb = local::mask_rxb({', '.join(ll)});",
                    file=out,
                )
                assign_list.append("rxb")
            # construct our struct with fields
            ctor_list = []
            for name, _ in format_fields:
                if name != "unk":
                    if name in assign_list:
                        ctor_list.append(f"instr_{name}")
                    else:
                        ctor_list.append("0")
            print(
                f"{space}{struct_name(k)} instr_fmt = {{ {', '.join(ctor_list)} }};",
                file=out,
            )
            print(f"{space}appendInto(instr_fmt);", file=out)

            print("}\n", file=out)


with open("xbyak_s390x_instr_core.h", "w") as f:
    gen_core_operations(fmt_signatures, fmt, aliases, out=f)


hex_str = re.compile(r"[ABCDEF0-9]+")


def op_name(instr):
    name = instr.lower()
    if name in ["or", "not", "xor", "and"]:
        return (f"{name}_", True)
    return (name, False)


def xtend_args(g):
    g = g.replace("X'", "0x").replace("'", "").lower()
    sn = Signature(g)
    return getCppArgCall(sn)


def gen_extended_and_mark(instr_extended, extended_entries):
    """
    Generate extended and also mark in extended_entries_set  to avoid regeneration
    """
    modifier = reg_change("GPReg")
    listx = ["// Extensiones 1: "]
    for ll in instr_extended:
        if len(ll) < 4:
            continue
        sn = Signature(ll[1])
        params = getCppArgDecl(sn, prefix="", callback_modifier=modifier)
        extended_entries.add(ll[0])
        op_name = ll[0].lower()
        outx = f"void {op_name}({params} ){{"
        outx += f" {ll[2].lower()}({xtend_args(ll[3])}); }}"
        listx.append(outx)
    return listx


def gen_mnemonics(fmt_signatures, isa_table, extended_entries, out=sys.stdout):
    global explicit_map
    space = " "
    for k, v in fmt_signatures.items():
        core_op_name = struct_name(k, "op")
        explicit_map_list = None
        ambiguity_index = ARG_MAX_NUMB
        if core_op_name in explicit_map:
            ambiguity_index, explicit_map_list, ssignature = explicit_map[core_op_name]
        for ss, instructions in v.items():
            sn = Signature(ss)
            special_map = len(sn.argList) > ambiguity_index and (
                ss in explicit_map_list
            )

            arg_call = ""
            if special_map == True:
                # solve ambiguity by mapping args to the called function explicitly
                # instead of doing it for all, we just do it for the ambiguous ones
                # otherwise default cases and optionals are sufficient
                arg_call = getCppArgCall(sn, prefix="", length=ambiguity_index)
                aaa = ssignature.argList[ambiguity_index:]
                for j in aaa:
                    if len(arg_call) > 0:
                        arg_call += ", "

                    arg_call += (
                        f"{j.getCppArgName()}"
                        if j in sn.argList
                        else j.getCppArgDefault()
                    )

            else:
                arg_call = getCppArgCall(sn, prefix="").strip()
            if len(arg_call) > 0:
                arg_call = ", " + arg_call

            for instr in sorted(instructions):
                # mark in the table that we generated it
                if instr in isa_table:
                    isa_table[instr][1] = True
                    entry_info = isa_table[instr][0]
                    if instr in extended_entries:
                        print(f"we will write {instr} as extended", file=sys.stderr)
                        continue
                    params, optional_mapping = getCppArgDeclMnemomic(
                        sn, entry_info, struct_name(k, "")
                    )
                    hex_code = entry_info[-2]
                    if hex_str.match(hex_code):
                        name, no_op_names = op_name(instr)
                        outx = f"void {name}"
                        outy = f"({params} ){{{space}{optional_mapping}{core_op_name}(0x{hex_code}{arg_call}); }}"
                        if no_op_names:
                            out_no_op = f"#if !defined(XBYAK_S390X_NO_OP_NAMES)\n {instr.lower()}"
                            print(f"{out_no_op}{outy}\n#endif", file=out)
                        print(f"{outx}{outy}", file=out)


isa_table = None
isa_table_entries = {}
with open(f"{file_txt}_table.txt", "r") as f:
    strX = f.read()
    isa_table = ast.literal_eval(strX)
for l in isa_table:
    isa_table_entries[l[1].strip()] = [l, False]
del isa_table

extended_entries = set()


def gen_other_extensions(out):
    branch_entries = [
        ("B_", "D2(X2,B2)", "BC", "M1,D2(X2,B2)"),
        ("B_R", "R1", "BCR", "M1,R1"),
        ("J_", "RI1", "BRC", "M1,RI1"),
        ("JG_", "RI1", "BRCL", "M1,RI1"),
    ]
    extensionA = [
        ("o", "1", "//jump on overflow / if ones"),
        ("h", "2", "//jump on A high"),
        ("p", "2", "//jump on plus"),
        ("nle", "3", "//jump on not low or equal"),
        ("l", "4", "//jump on A low"),
        ("m", "4", "//jump on minus"),
        ("nhe", "5", "//jump on not high or equal"),
        ("lh", "6", "//jump on low or high"),
        ("ne", "7", "//jump on A not equal B"),
        ("nz", "7", "//jump on not zero / if not zeros"),
        ("e", "8", "//jump on A equal B"),
        ("z", "8", "//jump on zero / if zeroes"),
        ("nlh", "9", "//jump on not low or high"),
        ("he", "10", "//jump on high or equal"),
        ("nl", "11", "//jump on A not low"),
        ("nm", "11", "//jump on not minus / if not mixed"),
        ("le", "12", "//jump on low or equal"),
        ("nh", "13", "//jump on A not high"),
        ("np", "13", "//jump on not plus"),
        ("no", "14", "//jump on not overflow / if not ones"),
        ("", "15", "//unconditional"),
    ]
    print("// Extensiones 2: ", file=out)
    modifier = reg_change("GPReg")
    for op1, arg1, op2, arg2 in branch_entries:
        params = getCppArgDecl(Signature(arg1), "", modifier).replace(
            "int& ri", "Label lbl"
        )
        arg_call = getCppArgCall(Signature(arg2)).replace("ri", "lbl")

        for cc, mask, comment in extensionA:
            func1 = op1.replace("_", cc).lower()
            func2_args = arg_call.replace("m1", mask)
            op2 = op2.lower()
            print(comment, file=out)
            print(f"void {func1}({params} ){{{op2}({func2_args}); }}", file=out)
    print("//NOPs", file=out)
    print(f"void nop(const AddrDXB& dxb2 = {{}} ){{ bc(0, dxb2); }}", file=out)
    print(f"void nopr(const GPReg& r1 = {{}} ){{ bcr(0, r1); }}", file=out)
    print(f"void jnop(){{ brc(0, {{}}); }}", file=out)
    print("//ALTERNATIVE NAMES", file=out)
    alternatives = [
        ("BRAS", "R1,RI2"),
        ("BRASL", "R1,RI2"),
        ("BRC", "M1,RI2"),
        ("BRCL", "M1,RI2"),
        ("BRCT", "R1,RI2"),
        ("BRCTG", "R1,RI2"),
        ("BRCTH", "R1,RI2"),
        ("BRXH", "R1,R3,RI2"),
        ("BRXHG", "R1,R3,RI2"),
        ("BRXLE", "R1,R3,RI2"),
        ("BRXLG", "R1,R3,RI2"),
    ]
    for c, arg in alternatives:
        params = getCppArgDecl(Signature(arg), "", modifier).replace(
            "int& ri", "Label lbl"
        )
        arg_call = getCppArgCall(Signature(arg)).replace("ri", "lbl")
        c = c.lower()
        func = "j" + c[1:]
        print(f"void {func}({params} ){{{c}({arg_call}); }}", file=out)


with open("xbyak_s390x_mnemonics.h", "w") as f:
    listx = gen_extended_and_mark(instr_extended, extended_entries)
    gen_mnemonics(fmt_signatures, isa_table_entries, extended_entries, out=f)
    # write extended after mnemonics
    for sentence in listx:
        print(sentence, file=f)
    gen_other_extensions(out=f)
    print("\n// Missed ones: ", file=f)
    for k, v in isa_table_entries.items():
        if v[1] == False:
            print(f"// {v[0]} ", file=f)
