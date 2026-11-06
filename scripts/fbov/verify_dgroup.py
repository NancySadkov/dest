#!/usr/bin/env python3
"""Verify the recovered DGROUP against the original executable.

Reconstructs the DGROUP data from a TC30 OMF object, compares every byte with
the original EXE, and checks every exported symbol offset against
doc/dgroup_map.csv.

Usage:
  python scripts/fbov/verify_dgroup.py \
      --obj tmp/dgbuild/DGROUP.OBJ \
      --exe game/STRONG.EXE \
      --map doc/dgroup_map.csv
"""
import argparse
import csv
import os
import sys

FILE_OFF = 0x15F00
SIZE = 0x949A


def parse_omf(obj):
    d = open(obj, "rb").read()
    buf = bytearray(SIZE)
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
            data = pl[3:-1]  # drop checksum
            if seg == 2:
                end = min(off + len(data), SIZE)
                buf[off:end] = data[:end - off]
        elif t == 0x90:  # PUBDEF
            seg = pl[1]
            j = 2
            while j < len(pl) - 1:
                n = pl[j]
                name = pl[j + 1:j + 1 + n].decode("ascii", "replace")
                j += 1 + n
                off = pl[j] | (pl[j + 1] << 8)
                j += 2
                j += 2  # type index
                if seg == 2:
                    pub[name.lstrip("_")] = off
        elif t == 0x8A:
            break
    return buf, pub


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--obj", required=True)
    ap.add_argument("--exe", default=os.path.join("game", "STRONG.EXE"))
    ap.add_argument("--map", default=os.path.join("doc", "dgroup_map.csv"))
    a = ap.parse_args()

    buf, pub = parse_omf(a.obj)
    orig = open(a.exe, "rb").read()[FILE_OFF:FILE_OFF + SIZE]
    diffs = [i for i in range(SIZE) if buf[i] != orig[i]]

    rows = []
    for r in csv.DictReader(open(a.map)):
        rows.append((int(r["offset"], 16), r["name"]))
    rows.sort()

    matched = 0
    mismatched = 0
    for off, name in rows:
        if name in pub:
            matched += 1
            if pub[name] != off:
                mismatched += 1
                print("offset mismatch: %04X -> %04X %s" %
                      (off, pub[name], name))

    print("symbols matched=%d mismatched=%d" % (matched, mismatched))
    print("bytes compared=%d differences=%d" % (SIZE, len(diffs)))
    for i in diffs[:20]:
        print("  %04X obj=%02X orig=%02X" % (i, buf[i], orig[i]))
    return 1 if (diffs or mismatched) else 0


if __name__ == "__main__":
    sys.exit(main())
