#!/bin/env python3
"""
Extracts ISA tables from IBM Z Principles of Operation
Its good source to get the text representation of the faicilities, exceptions
"""
import pdfplumber
import sys

if len(sys.argv) < 2:
    print(
        "python3 xtract_isa_tables.py filename [page_start] [page_end]\n [ ] optional ", file=sys.stderr
    )
    exit(-1)
file_txt = sys.argv[1]
page_start = int(sys.argv[2]) if len(sys.argv) > 2 else 1823
page_end = int(sys.argv[3]) if len(sys.argv) > 3 else 1847
table_list = []

i = 0
with pdfplumber.open(file_txt) as pdf:
    for page in pdf.pages:
        # due to error we have to skip this way
        i += 1
        if i < page_start:
            print(f"skip page: {i}\r", end="")
            page.flush_cache()
            continue
        if i >= page_end:
            break
        tables = page.extract_tables(
            {
                "vertical_strategy": "lines",
                "horizontal_strategy": "text",
                "text_y_tolerance": 4.5,
                "intersection_x_tolerance":8,
                "snap_y_tolerance":4,
            }
        )
        for table in tables:
            if table is None:
                continue
            prev = None
            # print(f"{i}")
            # print(table)
            for h in table:
                if prev is None:
                    prev = h
                    continue
                if len(h) > 1 and (h[-1] == "Page" or h[1] == "Mne-"):
                    prev = None
                    continue
                if len(h[-1]) < 1 and len(prev[-1]) > 0:
                    prev[0] += h[0]
                    prev[1] += h[1]
                    table_list.append(prev)
                elif len(prev[-1]) > 0:
                    table_list.append(prev)
                prev = h
            if prev is not None and len(prev[-1]) > 0:
                table_list.append(prev)
            del table
        page.flush_cache()



with open(file_txt + "_table.txt", "w") as f:
    print("[", file=f)
    for list in table_list:
        print(str(list) +",", file=f)
    print("]", file=f)
