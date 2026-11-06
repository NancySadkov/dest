#!/usr/bin/env python3
"""Compare a standalone TC30 object function with original overlay code bytes.

Usage:
  python scripts/fbov/ov_compare.py --obj tmp/ovbuild/OV_3381.OBJ \
      --name f_3381_0132 --overlay-seg 3381 --ofs 0x132 --size 0x3A
"""
import argparse
import csv
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "scripts", "fbov"))
from byte_match import parse_omf


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--obj", required=True)
    ap.add_argument("--name", required=True)
    ap.add_argument("--overlay-seg", required=True)
    ap.add_argument("--ofs", required=True, type=lambda x: int(x, 0))
    ap.add_argument("--size", required=True, type=lambda x: int(x, 0))
    ap.add_argument("--show", type=lambda x: int(x, 0), default=0x40)
    a = ap.parse_args()

    seg = int(a.overlay_seg, 16)
    row = None
    for r in csv.DictReader(open(os.path.join(ROOT, "doc", "fbov_overlays.csv"))):
        if int(r["code_seg"], 16) == seg:
            row = r
            break
    if row is None:
        raise SystemExit("overlay code segment not found")
    code_off = int(row["code_file_offset"], 0)
    disp = int(row["code_disp"], 16)
    orig_off = code_off + (a.ofs - disp)
    exe = open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()
    orig = exe[orig_off:orig_off + a.size]

    segdata, pub = parse_omf(a.obj)
    if a.name not in pub:
        raise SystemExit("symbol not found: " + a.name + " have " + str(sorted(pub)))
    sseg, soff = pub[a.name]
    code = bytes(segdata.get(sseg, b"")[soff:soff + a.size])

    print("orig ", orig[:a.show].hex(" "))
    print("obj  ", code[:a.show].hex(" "))
    mask = set()
    try:
        import capstone
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)
        for ins in md.disasm(orig, 0):
            if ins.mnemonic in ("call", "lcall"):
                if ins.bytes[0] == 0xE8:
                    mask.update(ins.address + 1 + i for i in range(2))
                elif ins.bytes[0] == 0x9A:
                    mask.update(ins.address + 1 + i for i in range(4))
    except ImportError:
        pass
    diffs = [i for i in range(min(len(orig), len(code)))
             if orig[i] != code[i] and i not in mask]
    if not diffs:
        print("MATCH %d bytes (%d call bytes masked)" % (len(orig), len(mask)))
        return 0
    print("DIFF %d of %d" % (len(diffs), len(orig)))
    for i in diffs[:30]:
        print("  %04X obj=%02X orig=%02X" % (i, code[i], orig[i]))
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
