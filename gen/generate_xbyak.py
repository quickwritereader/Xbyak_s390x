#!/usr/bin/env python3
# coding: utf-8
import sys
import ast
import re
from parse_signature import Signature, get_merged_signature, ARG_MAX_NUMB

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
    sys.exit(-1)

FILE_TXT = sys.argv[1]
T_MATCH = re.compile(r"^(d[lh]?|ri|r|v|m|x|b|i|l)(\d?)$")
FORMATS = ""
with open("instruction_formats.txt", "r",  encoding="utf-8") as f:
    FORMATS = f.read()

FMT_SIGNATURES = None
with open(f"{FILE_TXT}_signatures.txt", "r",  encoding="utf-8") as f:
    strX = f.read()
    FMT_SIGNATURES = ast.literal_eval(strX)

INSTR_EXTENDED = None
with open(f"{FILE_TXT}_extended.txt", "r",  encoding="utf-8") as f:
    strX = f.read()
    INSTR_EXTENDED = ast.literal_eval(strX)


def struct_name(name, prefix="Format_"):
    """struct/op naming"""
    name = prefix + name.replace("-", "_").strip().upper()
    return name


def parse_instr_formats(formats):
    """Parse instruction formats"""
    fmt_dict = {}
    fmt_aliases = {}
    format_lines = formats.split("\n")
    # print(len(format_lines))
    for line in format_lines:
        line_array = line.lower().split(",")
        # print(ss)
        if len(line_array) <= 1:
            continue
        name = ""
        arr = line_array[0].split("-")
        arr_size = len(arr)
        if arr_size <= 2:
            # it means simple
            name = struct_name(line_array[0], "")
        elif arr_size == 3:
            # underline is aliased
            name = struct_name(line_array[0], "")
            if arr[1] >= arr[2]:
                print(
                    f"error in format, name letters should be ranged {line_array}",
                    file=sys.stderr,
                )
                return None
            for v in range(ord(arr[1]), ord(arr[2]) + 1):
                fmt_aliases[(arr[0] + "_" + chr(v)).upper()] = name
        else:
            print(f"error in format {line_array}", file=sys.stderr)
            return None
        if name in fmt_dict:
            print(
                f"warning, duplicate in format {line_array}", file=sys.stderr)
            continue
        fmt_list = []
        for element in line_array[1:]:
            # name_field:bit_width
            el_arr = element.split(":")
            if len(el_arr) != 2:
                print(f"error, in field format {line_array}", file=sys.stderr)
                return None

            name_field = el_arr[0].strip()
            bit_width = int(el_arr[1].strip()
                            ) if el_arr[1].strip().isdigit() else None
            if len(name_field) < 1 or bit_width is None:
                print(f"error, in field format {line_array}", file=sys.stderr)
                return None
            fmt_list.append((name_field, bit_width))
        fmt_dict[name] = fmt_list

    return (fmt_dict, fmt_aliases)


fmt, aliases = parse_instr_formats(FORMATS)


def write_format_structs(fmt_dict, fmt_aliases, out=sys.stdout):
    """Write instruction format structs"""
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
    for key, val in fmt_dict.items():
        print(f"struct {struct_name(key)} {{", file=out)
        lenx = 0
        argx = []
        for name, bit_width in val:
            lenx += bit_width
            if name != "unk":
                argx.append(f"int64_t {name}")
        print(f"  packed_type<{lenx}>::typeX instr = 0;", file=out)
        print(
            f"  constexpr static size_t sizeOf(){{ return {lenx//8}; }}", file=out)
        underline_len = (lenx + 15) & -16
        if underline_len >= 48:
            underline_len = 64

        # constructor without unk
        print(f"  {struct_name(key)}({', '.join(argx)}){{", file=out)
        left = 0
        print(
            f"    instr = XBYAK_S390X_BIGENDIAN_{underline_len}( 0 ", end="", file=out
        )
        for name, bit_width in val:
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

    for key, val in fmt_aliases.items():
        print(f"using {struct_name(key)} = {struct_name(val)};", file=out)


with open("xbyak_s390x_instr_formats.h", "w", encoding="utf-8") as f:
    write_format_structs(fmt, aliases, out=f)


explicit_map = {}


def get_arg_call(signature, prefix="", length=ARG_MAX_NUMB):
    """Gets arg call string"""
    length = min(len(signature.arg_list), length)
    string = ""
    end_index = length - 1
    if len(prefix) > 0 and end_index > 0:
        string = prefix
    add_comma = True
    for i in range(0, length):
        toks = signature.arg_list[i]
        arg_name = toks.get_arg_name()
        if len(arg_name) < 1:
            continue
        if arg_name == ")":
            add_comma = True
        elif arg_name == "(":
            add_comma = False
        else:
            string += arg_name
        if i < end_index and add_comma:
            string += ", "
    return string


def get_arg_decl(signature, prefix="int opCode", callback_modifier=None):
    """Get argument declaration"""
    str_list = []
    if len(prefix) > 0:
        str_list.append(prefix)
    for ind, toks in enumerate(signature.arg_list):
        arg_type = toks.get_arg_type()
        if len(arg_type) < 1:
            continue
        arg_name = toks.get_arg_name()
        if callback_modifier:
            arg_type, arg_name = callback_modifier(arg_type, arg_name)
        defaulted = "= {} " if ind >= signature.optional_start else ""
        str_list.append(f"const {arg_type}& {arg_name}{defaulted}")
    return ", ".join(str_list)


def branch_label(arg_list):
    """Modifies branch ri into Label types"""
    def modifier(arg_type, arg_name):
        if arg_name.startswith("ri") and len(arg_list) < 1:
            arg_list.append(arg_name)
            return ("Label", f"lbl_{arg_name}")
        else:
            return (arg_type, arg_name)

    return modifier


def change_register_type(reg_type, r_digit=-1):
    """Changes register types if necessary"""
    # -1 means change all
    # otherwise the one with r_digit will be changed
    def modifier(arg_type, arg_name):
        digit = "" if r_digit == -1 else str(r_digit)
        if arg_type == "Operand" and arg_name.startswith("r" + digit):
            return (reg_type, arg_name)
        elif arg_type == "Operand" and r_digit != -1:
            # return GPReg
            return ("GPReg", arg_name)

        return (arg_type, arg_name)

    return modifier


def get_arg_decl_for_mnemomics(signature, isa_table_def, call_op_key):
    """
    Gets arg declarations for mnemonics
    Returns (parameters, optional mapping)
    Optional mapping should be used inside body before calling core functins
    """
    modifier = change_register_type("GPReg")
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
        modifier = change_register_type("FReg")
        if "to 64" in instr_info or "to 32" in instr_info:
            # this conversion from float type to general type, there for 1st should be GPReg, 2nd Freg
            modifier = change_register_type("FReg", 2)
        elif "64 to" in instr_info or "32 to" in instr_info:
            # it means the first one should be Freg
            modifier = change_register_type("FReg", 1)
    elif "ACCESS" in instr_info:
        modifier = change_register_type("AReg")
        if "EXTRACT" in instr_info:
            # only second part
            modifier = change_register_type("AReg", 2)
        elif "TEST" in instr_info or "SET" in instr_info:
            # second is GPReg
            modifier = change_register_type("AReg", 1)
        elif not "ACCESS INTENT" in instr_info:
            modifier = change_register_type("AReg")
    elif "LOAD CONTROL" in instr_info or "STORE CONTROL" in instr_info:
        modifier = change_register_type("CReg")
    if "BRANCH RELATIVE" in instr_info:
        arg_list = []
        params = get_arg_decl(
            signature, prefix="", callback_modifier=branch_label(arg_list))
        map_call = ""
        if len(arg_list) > 0:
            fmt_entries = fmt[call_op_key]
            entry_match = arg_list[0]
            start_bit = 0
            bit_width = 0
            for entry, bit in fmt_entries:
                if entry == entry_match:
                    bit_width = bit
                    break
                start_bit += bit

            map_call = f"auto {arg_list[0]} = encodeJmp(lbl_{arg_list[0]}, {start_bit}, {bit_width}); "

        return (params, map_call)

    params = get_arg_decl(signature, prefix="", callback_modifier=modifier)
    return (params, "")


def get_accessor(fmt_fields):
    """Gets access assignments"""
    return_data = {"": {}}  # { arg_index_if_exist :{typex : list}}
    # print(f"---   {fmt_fields} ----")
    # group op codes
    for name, bit_width in fmt_fields:
        if name.startswith("opcode"):
            if "opcode" not in return_data[""]:
                return_data[""]["opcode"] = []
            return_data[""]["opcode"].append((name, bit_width))
        # split if one field can be assigned by two different
        name_arr = name.split("_")
        for name_i in name_arr:
            match_result = T_MATCH.match(name_i)
            if match_result:
                val = match_result.group(2)
                arg_type = match_result.group(1)
                if not val in return_data:
                    return_data[val] = {}
                if arg_type in ("dl", "dh"):
                    arg_type = "d"
                if not arg_type in return_data[val]:
                    return_data[val][arg_type] = [(name, bit_width)]
                else:
                    return_data[val][arg_type].append((name, bit_width))
                if arg_type == "v":
                    if "rxb" not in return_data[""]:
                        return_data[""]["rxb"] = []
                    return_data[""]["rxb"].append(name)

    return return_data


def write_assignments(
    field_name_entry, entry, entry_name, assign_list, out=sys.stdout
):
    """Writes assignments"""
    space = "    "
    if entry in field_name_entry:
        tmp = field_name_entry[entry]
        if len(tmp) == 1:
            name, bit_field = tmp[0]
            print(
                f"{space}auto instr_{name} = local::mask({entry_name},{bit_field});",
                file=out,
            )
            assign_list.append(name)
            return True
        if len(tmp) == 2:
            name_high, bit_field_high = tmp[0]
            name_low, bit_field_low = tmp[1]
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


def gen_core_operations(fmt_signatures, fmt_dict, fmt_aliases, out=sys.stdout):
    """Generate core instruction operations"""
    for key, val in fmt_signatures.items():
        # remove [, ] while sorting to make it possible to merge unnecessary method declarations

        list_clear = []
        # if k=="VRR-a":
        #     ggg=""
        for sgn_string in val.keys():
            added = False
            # merge signatures if possible, and also add descp
            for idx, item in enumerate(list_clear):
                param = Signature(sgn_string)
                merged, amibiguity_index = get_merged_signature(item[0], param)
                if merged is not None:
                    list_clear[idx][0] = merged
                    list_clear[idx][1] = min(
                        list_clear[idx][1], amibiguity_index)
                    list_clear[idx][2].append(sgn_string)
                    added = True
                    break

            if not added:
                param = Signature(sgn_string)
                list_clear.append([param, ARG_MAX_NUMB, [sgn_string]])
        entry = struct_name(key, "")
        if entry in fmt_aliases:
            entry = fmt_aliases[entry]
        format_fields = fmt_dict[entry]
        alist = get_accessor(format_fields)
        for signature, amibiguity_index, ss_list in list_clear:
            print(f"//{key}: {' | '.join(ss_list)}", file=out)
            space = "    "
            op_name = struct_name(key, "op")
            if amibiguity_index != ARG_MAX_NUMB:
                # add this to our explicitly map list
                explicit_map[op_name] = (amibiguity_index, ss_list, signature)

            print(f"void {op_name}({get_arg_decl(signature)} ){{", file=out)
            print(f"{space}//bit_fields: {format_fields}", file=out)
            assign_list = []
            write_assignments(alist[""], "opcode", "opCode", assign_list, out)

            for args in signature.arg_list:
                field_name_entry = None
                arg_val = f"{args.val}" if args.val is not None and args.val >= 0 else ""
                if arg_val in alist:
                    field_name_entry = alist[arg_val]
                else:
                    print(
                        f"//warning in arg gen: {args.get_arg_name()}", file=out)
                    continue
                if "d" in args.kind:
                    ok = True
                    for addr_kind in args.kind:
                        entry_name = f"{args.get_arg_name()}."
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
                        ok = ok and write_assignments(
                            field_name_entry, addr_kind, entry_name, assign_list, out
                        )
                    continue

                entry_name = (
                    f"{args.get_arg_name()}.getIdx()"
                    if args.kind in ["r", "v"]
                    else args.get_arg_name()
                )
                write_assignments(
                    field_name_entry, args.kind, entry_name, assign_list, out
                )
            if "rxb" in alist[""]:
                tmp = [f"{jj}.getIdx()" for jj in alist[""]["rxb"]]
                # write code for deducing rxb
                print(
                    f"{space}auto instr_rxb = local::mask_rxb({', '.join(tmp)});",
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
                f"{space}{struct_name(key)} instr_fmt = {{ {', '.join(ctor_list)} }};",
                file=out,
            )
            print(f"{space}appendInto(instr_fmt);", file=out)

            print("}\n", file=out)


with open("xbyak_s390x_instr_core.h", "w", encoding="utf-8") as f:
    gen_core_operations(FMT_SIGNATURES, fmt, aliases, out=f)


hex_str = re.compile(r"[ABCDEF0-9]+")


def underscored_overlapped_op_names(instr):
    """Add underscore into Operation names that overlaps with CXX builtins operations"""
    name = instr.lower()
    if name in ["or", "not", "xor", "and"]:
        return (f"{name}_", True)
    return (name, False)


def hex_extend_args(g):
    """Hexadecimal values in mnemonics args"""
    g = g.replace("X'", "0x").replace("'", "").lower()
    return get_arg_call(Signature(g))


def gen_extended_and_mark(instr_extended, extended):
    """
    Generate extended and also mark in extended_entries_set  to avoid regeneration
    """
    modifier = change_register_type("GPReg")
    ret_list = ["// Extensiones 1: "]
    for tmp in instr_extended:
        if len(tmp) < 4:
            continue
        params = get_arg_decl(
            Signature(tmp[1]), prefix="", callback_modifier=modifier)
        extended.add(tmp[0])
        op_name = tmp[0].lower()
        outx = f"void {op_name}({params} ){{"
        outx += f" {tmp[2].lower()}({hex_extend_args(tmp[3])}); }}"
        ret_list.append(outx)
    return ret_list


def write_mnemonics(fmt_signatures, isa_table, extended, out=sys.stdout):
    """Write mnemonics"""
    space = " "
    for key, val in fmt_signatures.items():
        core_op_name = struct_name(key, "op")
        explicit_map_list = None
        ambiguity_index = ARG_MAX_NUMB
        if core_op_name in explicit_map:
            ambiguity_index, explicit_map_list, ssignature = explicit_map[core_op_name]
        for signature_string, instructions in val.items():
            signature = Signature(signature_string)
            special_map = len(signature.arg_list) > ambiguity_index and (
                signature_string in explicit_map_list
            )

            arg_call = ""
            if special_map:
                # solve ambiguity by mapping args to the called function explicitly
                # instead of doing it for all, we just do it for the ambiguous ones
                # otherwise default cases and optionals are sufficient
                arg_call = get_arg_call(
                    signature, prefix="", length=ambiguity_index)
                aaa = ssignature.arg_list[ambiguity_index:]
                for j in aaa:
                    if len(arg_call) > 0:
                        arg_call += ", "

                    arg_call += (
                        f"{j.get_arg_name()}"
                        if j in signature.arg_list
                        else j.get_arg_default()
                    )

            else:
                arg_call = get_arg_call(signature, prefix="").strip()
            if len(arg_call) > 0:
                arg_call = ", " + arg_call

            for instr in sorted(instructions):
                # mark in the table that we generated it
                if instr in isa_table:
                    isa_table[instr][1] = True
                    entry_info = isa_table[instr][0]
                    if instr in extended:
                        print(
                            f"we will write {instr} as extended", file=sys.stderr)
                        continue
                    params, optional_mapping = get_arg_decl_for_mnemomics(
                        signature, entry_info, struct_name(key, "")
                    )
                    hex_code = entry_info[-2]
                    if hex_str.match(hex_code):
                        name, no_op_names = underscored_overlapped_op_names(
                            instr)
                        outx = f"void {name}"
                        outy = f"({params} ){{{space}{optional_mapping}{core_op_name}(0x{hex_code}{arg_call}); }}"
                        if no_op_names:
                            out_no_op = f"#if !defined(XBYAK_S390X_NO_OP_NAMES)\n {instr.lower()}"
                            print(f"{out_no_op}{outy}\n#endif", file=out)
                        print(f"{outx}{outy}", file=out)


ISA_TABLE = None
ISA_TABLE_ENTRIES = {}
with open(f"{FILE_TXT}_table.txt", "r", encoding="utf-8") as f:
    strX = f.read()
    ISA_TABLE = ast.literal_eval(strX)
for l in ISA_TABLE:
    ISA_TABLE_ENTRIES[l[1].strip()] = [l, False]
del ISA_TABLE

extended_entries = set()


def gen_other_extensions(out):
    """Generate Other Extensions"""
    branch_entries = [
        ("B_", "D2(X2,B2)", "BC", "M1,D2(X2,B2)"),
        ("B_R", "R1", "BCR", "M1,R1"),
        ("J_", "RI1", "BRC", "M1,RI1"),
        ("JG_", "RI1", "BRCL", "M1,RI1"),
    ]
    extension_jump = [
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
    modifier = change_register_type("GPReg")
    for op1, arg1, op2, arg2 in branch_entries:
        params = get_arg_decl(Signature(arg1), "", modifier).replace(
            "int& ri", "Label lbl"
        )
        arg_call = get_arg_call(Signature(arg2)).replace("ri", "lbl")

        for entry, mask, comment in extension_jump:
            func1 = op1.replace("_", entry).lower()
            func2_args = arg_call.replace("m1", mask)
            op2 = op2.lower()
            print(comment, file=out)
            print(f"void {func1}({params} ){{{op2}({func2_args}); }}", file=out)
    print("//NOPs", file=out)
    print("void nop(const AddrDXB& dxb2 = {} ){ bc(0, dxb2); }", file=out)
    print("void nopr(const GPReg& r1 = {} ){ bcr(0, r1); }", file=out)
    print("void jnop(){ brc(0, {}); }", file=out)
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
    for entry, arg in alternatives:
        params = get_arg_decl(Signature(arg), "", modifier).replace(
            "int& ri", "Label lbl"
        )
        arg_call = get_arg_call(Signature(arg)).replace("ri", "lbl")
        entry = entry.lower()
        func = "j" + entry[1:]
        print(f"void {func}({params} ){{{entry}({arg_call}); }}", file=out)


with open("xbyak_s390x_mnemonics.h", "w", encoding="utf-8") as f:
    listx = gen_extended_and_mark(INSTR_EXTENDED, extended_entries)
    write_mnemonics(FMT_SIGNATURES, ISA_TABLE_ENTRIES, extended_entries, out=f)
    # write extended after mnemonics
    for sentence in listx:
        print(sentence, file=f)
    gen_other_extensions(out=f)
    print("\n// Missed ones: ", file=f)
    for key, val in ISA_TABLE_ENTRIES.items():
        if not val[1]:
            print(f"// {val[0]} ", file=f)
