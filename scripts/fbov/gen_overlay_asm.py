#!/usr/bin/env python3
"""Generate whole-body assembly functions for an overlay's code region.

Usage: python scripts/fbov/gen_overlay_asm.py --header 13D5

Emits src/recovered/ov_<code_seg>.c.  The region is walked sequentially:
every function starts with `push bp; mov bp, sp` and ends at its `retf`.
Each function reproduces the original bytes exactly; prologue/epilogue are
supplied by TC30.  Functions with a local frame use a dummy array plus
`(void)pad;` so the frame is allocated without extra code.
"""
import argparse
import capstone
import json
import os

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def parse_prologue(b, p):
    """Return (frame_size, body_start) or None if not a standard prologue."""
    if b[p:p + 2] != b"\x55\x8b" or b[p + 2] != 0xEC:
        return None
    p += 3
    frame = 0
    if b[p] == 0x83 and b[p + 1] == 0xEC:
        frame = b[p + 2]
        p += 3
    elif b[p] == 0x81 and b[p + 1] == 0xEC:
        frame = b[p + 2] | (b[p + 3] << 8)
        p += 4
    return frame, p


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--header", required=True)
    a = ap.parse_args()
    hdr = int(a.header, 16)
    m = json.load(open(os.path.join(ROOT, "doc", "fbov_manifest.json")))
    ovs = [x for x in m["overlays"] if x["header_seg"] == hdr]
    if not ovs:
        raise SystemExit("overlay not found")
    ov = ovs[0]
    seg = ov["code_seg"]
    base = ov["code_file_offset"]
    code_size = ov["codesz"]
    exe = open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()
    code = exe[base:base + code_size]
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)

    out = ['#include "dgroup.h"', ""]
    skipped = []
    gaps = []
    p = 0
    count = 0
    while p < code_size:
        pro = parse_prologue(code, p)
        if pro is None:
            q = p
            while q + 2 < code_size and code[q:q + 3] != b"\x55\x8b\xec":
                q += 1
            if q + 2 >= code_size:
                skipped.append((p, "prologue " + code[p:p + 6].hex(" ")))
                break
            gaps.append((p, q))
            p = q
            continue
        frame, body_start = pro
        end = None
        for ins in md.disasm(code[p:], p):
            if ins.mnemonic == "retf":
                end = ins.address + len(ins.bytes)
                break
        if end is None:
            skipped.append((p, "no retf"))
            break
        b = code[p:end]
        leave = b[-2] == 0xC9 and b[-1] == 0xCB
        popbp = b[-2] == 0x5D and b[-1] == 0xCB
        if not (leave or popbp):
            skipped.append((p, "epilogue " + b[-4:].hex(" ")))
            break
        if frame > 0 and leave:
            body = b[body_start - p:-2]
            pad = True
        elif frame == 0 and popbp:
            body = b[3:-2]
            pad = False
        else:
            skipped.append((p, "mismatch frame=%x epi=%s" %
                            (frame, b[-2:].hex(" "))))
            break
        name = "f_%04x_%04x" % (seg, p)

        def db(x):
            return ["  asm db " + ",".join("0%02Xh" % v for v in x[j:j + 16])
                    for j in range(0, len(x), 16)]

        out.append("void __cdecl16far %s(void)" % name)
        out.append("{")
        if pad:
            out.append("  unsigned char pad[0x%x];" % frame)
        out += db(body)
        if pad:
            out.append("  (void)pad;")
        out.append("}")
        out.append("")
        count += 1
        p = end
    path = os.path.join(ROOT, "src", "recovered", "ov_%04x.c" % seg)
    open(path, "w", encoding="ascii", newline="").write("\n".join(out))
    print("wrote", path, "functions", count, "bytes", p, "of", code_size)
    for s in skipped:
        print("  skip %04X %s" % s)
    for a, b in gaps:
        print("  table %04X..%04X (%d bytes)" % (a, b, b - a))


if __name__ == "__main__":
    main()
