#!/usr/bin/env python3
# coding: utf-8
"""
Extracts ISA and its format from IBM Z Principles of Operation
From the Entire book
"""
from inspect import signature
import pdfplumber
import re
import sys

if len(sys.argv) < 2:
    print("python3 xtract_isa.py filename")
    exit(-1)
file_txt = sys.argv[1]


# fix error in pdf V1V2 -> V1,V2
replace_err = re.compile(r"([VRIM]\d)(?=([VRIM]\d))")
# due to error in VCLFP inside pdf, we will mark ] as optional
# and also not to confuse with M\d we will separate MII
pattern = re.compile(
    r"([A-Za-z]+|Mnemonic[0-9]?|CU[1-4]+)\s+([VRIXBDLM][LH]?\d.*?)\[([EIRSV][A-Za-z-]*|MII)\]?"
)
pattern_one_or_no_arg = re.compile(r"([A-Z][A-Z0-9]+)\s+([A-Z]?\s+)\[(I|E|S|RRE)\]")
pattern_xt = re.compile(
    r"[A-Z]+\s+([VRIMDBLX][LH]?\d)[ ,\(\)XMDBLHVR0-6]+?[A-Z\[\]0-9, ]+?\1.*"
)
# the case where insted of instruction Mnemonic[0-9] is used
#beside ' we will add ‘ ’ to fix errors in pdf
pattern_noted_as_mnemonic = re.compile(r"([A-Z]+)\s+['‘][A-F0-9]+[’']\s+[A-Z0-9a-z-]+")
pattern_split = re.compile(r"\s+")


instruction_file = open(file_txt + "_ins.txt", "w")
signatures = {}
instr_set = set()
xtensions = []


def add_into(formatx, signature, instr):
    global signatures
    global instruction_file
    if not formatx in signatures:
        signatures[formatx] = {}
    if not signature in signatures[formatx]:
        signatures[formatx][signature] = set()

    signatures[formatx][signature].add(instr)
    instr_set.add(instr)
    print(f"{formatx}:\t{instr}\t{signature} ", file=instruction_file)


def add_xtension(t):
    global instr_set
    global xtensions
    global pattern_split
    r = pattern_split.split(t)
    # see if the main part is already in sginatures
    missed = True
    # print(r)
    if len(r) >= 4:
        # ins args ins_main args ...
        ins_main = r[2]
        if ins_main in instr_set:
            # we can add
            xtensions.append((r[0], r[1], ins_main, "".join(r[3:])))
            missed = False
    if missed:
        print(f"parsed as xtension but was not added {t}", file=sys.stderr)


last_mnem = None
last_mnem_page_count = 0


def xtract(t):
    # global pattern
    global pattern_noted_as_mnemonic
    global last_mnem
    global last_mnem_page_count
    match_extendeds = "Base Mnemonic" in t
    # some instructions ar noted as Mnemonic[0-9]
    # but provided differently
    if last_mnem is not None:
        last_mnem_page_count += 1
    if last_mnem_page_count > 2:
        last_mnem = None

    for h in t.split("\n"):
        h = h.strip()
        ins = pattern.search(h)
        if ins is None:
            ins = pattern_one_or_no_arg.match(h)
        if ins:
            groups = ins.groups()
            formatx = groups[2].strip()
            signature = groups[1].strip().replace(" ", "")
            signature = re.sub(replace_err, r"\1,", signature)
            instr = groups[0].strip()
            # to make it robust we will add all possible ones even mistakenly parsed ones
            if instr.startswith("Mnemonic"):
                # do not add but search also for instructions till it finds another
                last_mnem = (formatx, signature)
                last_mnem_page_count = 0
                # print(f"~~~~~~~~{last_mnem}")
                continue
            else:
                last_mnem = None
                last_mnem_page_count = 0
                add_into(formatx, signature, instr)
        if last_mnem is not None:
            # try to match
            z = pattern_noted_as_mnemonic.search(h)
            if z:
                add_into(*last_mnem, z.group(1))

        if match_extendeds:
            z = re.search(pattern_xt, h)
            if z:
                spans = z.span()
                add_xtension(h[spans[0] : spans[1]])
        


with pdfplumber.open(file_txt) as pdf:
    for p in pdf.pages:
        # two columns split in the middle
        left = p.crop((0.09 * float(p.width), 0, 0.47 * float(p.width), p.height))
        right = p.crop((0.5 * float(p.width), 0, 0.91 * p.width, p.height))
        t = left.extract_text(return_chars=False, y_tolerance=5.5, layout=True)
        # print(t)
        xtract(t)
        t1 = right.extract_text(return_chars=False, y_tolerance=5.5, layout=True)
        xtract(t1)
        # print(t1)
        # delete explicitly
        left.flush_cache()
        del left
        del t
        right.flush_cache()
        del right
        p.flush_cache()
        del p
        del t1

instruction_file.close()

with open(file_txt + "_signatures.txt", "w") as f:
    print(signatures, file=f)
with open(file_txt + "_extended.txt", "w") as f:
    print(xtensions, file=f)
