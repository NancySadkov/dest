#!/usr/bin/env python3
"""Compare a compiled TC30 function against the original bytes.

Usage:
  python scripts/fbov/byte_match.py --obj tmp/fnbuild/OVC01.OBJ \
      --name mkp --overlay-seg 2D63 --ofs 0 --size 22
"""
import argparse
import csv
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def parse_omf(path):
    d = open(path, "rb").read()
    segdata = {}
    pub = {}
    i = 0
    while i + 3 <= len(d):
        t = d[i]
        ln = d[i + 1] | (d[i + 2] << 8)
        pl = d[i + 3:i + 3 + ln]
        i += 3 + ln
        if t == 0xA0:  # LEDATA
            seg = pl[0] & 0x7F
            off = pl[1] | (pl[2] << 8)
            data = pl[3:-1]
            buf = segdata.setdefault(seg, bytearray())
            if len(buf) < off + len(data):
                buf.extend(b"\0" * (off + len(data) - len(buf)))
            buf[off:off + len(data)] = data
        elif t == 0x90:  # PUBDEF
            seg = pl[1]
            j = 2
            while j < len(pl) - 1:
                n = pl[j]
                name = pl[j + 1:j + 1 + n].decode("ascii", "replace")
                j += 1 + n
                off = pl[j] | (pl[j + 1] << 8)
                j += 2
                j += 2
                pub[name.lstrip("_")] = (seg, off)
        elif t == 0x8A:
            break
    return segdata, pub


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--obj", required=True)
    ap.add_argument("--exe", default=os.path.join(ROOT, "game", "STRONG.EXE"))
    ap.add_argument("--name", required=True)
    ap.add_argument("--overlay-seg", default=None)
    ap.add_argument("--seg", default=None, help="normal static segment")
    ap.add_argument("--ofs", required=True, help="function offset in segment")
    ap.add_argument("--size", required=True, type=lambda x: int(x, 0))
    a = ap.parse_args()

    exe = open(a.exe, "rb").read()
    ofs = int(a.ofs, 0)
    if a.overlay_seg:
        seg = int(a.overlay_seg, 16)
        row = None
        for r in csv.DictReader(open(os.path.join(ROOT, "doc", "fbov_overlays.csv"))):
            if int(r["code_seg"], 16) == seg:
                row = r
                break
        if row is None:
            raise SystemExit("overlay segment not found")
        code_off = int(row["code_file_offset"], 0)
        disp = int(row["code_disp"], 16)
        orig_off = code_off + (ofs - disp)
    else:
        seg = int(a.seg, 16)
        start_ofs = 0x1E00
        orig_off = start_ofs + (seg - 0x1000) * 16 + ofs

    orig = exe[orig_off:orig_off + a.size]
    segdata, pub = parse_omf(a.obj)
    if a.name not in pub:
        raise SystemExit("symbol not found: " + a.name)
    sseg, soff = pub[a.name]
    code = bytes(segdata.get(sseg, b"")[soff:soff + a.size])
    print("symbol %-20s seg=%d off=%04X size=%d" % (a.name, sseg, soff, a.size))
    print("orig", orig.hex(" "))
    print("obj ", code.hex(" "))
    if code == orig:
        print("MATCH")
        return 0
    diffs = [i for i in range(min(len(orig), len(code))) if orig[i] != code[i]]
    print("DIFF", len(diffs))
    for i in diffs[:30]:
        print("  %04X obj=%02X orig=%02X" % (i, code[i], orig[i]))
    return 1


if __name__ == "__main__":
    sys.exit(main())
