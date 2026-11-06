#!/usr/bin/env python3
"""Compare a linked harness function against the original EXE bytes.

Usage:
  python scripts/fbov/link_compare.py --symbol _MAIN --seg 1301 --ofs 0x0C --size 2215

The linked EXE is tmp/linkbuild/OUT.EXE; the map is tmp/linkbuild/OUT.MAP.
"""
import argparse
import os
import re
import struct

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def map_segments(text):
    segs = {}
    for m in re.finditer(r"^\s*([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+(\S+)",
                         text, re.M):
        segs[m.group(4)] = int(m.group(1), 16)
    return segs


def load_image(path, segname, symbol):
    text = open(path, encoding="ascii", errors="replace").read()
    segs = map_segments(text)
    if segname not in segs:
        raise SystemExit("segment not in map: " + segname)
    start = segs[segname]
    m = None
    for m2 in re.finditer(r"^\s*([0-9A-F]{4}):([0-9A-F]{4})\s+(\S+)\s*$", text, re.M):
        if m2.group(3) == symbol:
            m = m2
    if m is None:
        raise SystemExit("symbol not in map: " + symbol)
    real = int(m.group(1), 16) * 16 + int(m.group(2), 16)
    return start, real


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--symbol", default="_MAIN")
    ap.add_argument("--segname", default="MAIN_TEXT")
    ap.add_argument("--seg", default=None, help="original static segment (hex)")
    ap.add_argument("--overlay-seg", default=None)
    ap.add_argument("--ofs", required=True, type=lambda x: int(x, 0))
    ap.add_argument("--size", required=True, type=lambda x: int(x, 0))
    ap.add_argument("--show", type=lambda x: int(x, 0), default=0x60)
    ap.add_argument("--linkdir", default=os.path.join(ROOT, "tmp", "linkbuild"))
    a = ap.parse_args()

    exe_path = os.path.join(a.linkdir, "OUT.EXE")
    map_path = os.path.join(a.linkdir, "OUT.MAP")
    start, real = load_image(map_path, a.segname, a.symbol)
    exe = open(exe_path, "rb").read()
    base = struct.unpack_from("<H", exe, 8)[0] * 16
    linked = exe[base + real: base + real + a.size]

    orig_exe = open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()
    if a.overlay_seg:
        import csv
        seg = int(a.overlay_seg, 16)
        row = None
        for r in csv.DictReader(open(os.path.join(ROOT, "doc", "fbov_overlays.csv"))):
            if int(r["code_seg"], 16) == seg:
                row = r
                break
        code_off = int(row["code_file_offset"], 0)
        disp = int(row["code_disp"], 16)
        orig_off = code_off + (a.ofs - disp)
    else:
        seg = int(a.seg, 16)
        orig_off = 0x1E00 + (seg - 0x1000) * 16 + a.ofs
    orig = orig_exe[orig_off:orig_off + a.size]

    print("linked %s @ %04X:%04X -> %02X" % (a.symbol, start, real, real))
    print("orig  ", orig[:a.show].hex(" "))
    print("link  ", linked[:a.show].hex(" "))
    diffs = [i for i in range(min(len(orig), len(linked))) if orig[i] != linked[i]]
    if not diffs:
        print("MATCH %d bytes" % len(orig))
        return 0
    print("DIFF %d of %d" % (len(diffs), len(orig)))
    for i in diffs[:30]:
        print("  %04X link=%02X orig=%02X" % (i, linked[i], orig[i]))
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
