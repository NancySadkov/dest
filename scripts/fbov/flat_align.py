#!/usr/bin/env python3
"""Force every OMF segment in the given object files to paragraph alignment.

Turbo C emits code segments with byte alignment, which makes Turbo Link pack
them into the EXE image.  The original overlay code was loaded at paragraph
boundaries at run time, so every code offset is paragraph-relative.  The flat
build has to reproduce that: aligning all segments removes the byte bias.
"""
import glob
import os
import sys

TWO_BYTE = set([0x80, 0x82, 0x88, 0x8A, 0x8B, 0x8C, 0x8E, 0x90, 0x91,
                0x92, 0x94, 0x95, 0x96, 0x98, 0x99, 0x9A, 0x9C, 0x9D,
                0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA6, 0xA8, 0xAA, 0xAC,
                0xAD, 0xB0, 0xB2, 0xB4, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA,
                0xBB, 0xBC, 0xC0, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xE0,
                0xE2])


def patch(path):
    d = bytearray(open(path, 'rb').read())
    i = 0
    n = 0
    while i < len(d):
        t = d[i]
        i += 1
        if t == 0x00:
            break
        if t not in TWO_BYTE:
            # one-byte-length record types (rare); bail out conservatively
            break
        ln = int.from_bytes(d[i:i + 2], 'little')
        i += 2
        if t in (0x98, 0x99):
            acbp = d[i]
            align = (acbp >> 5) & 7
            if align < 4:
                d[i] = (acbp & 0x1F) | (4 << 5)
                n += 1
        i += ln
    if n:
        open(path, 'wb').write(d)
    return n


if __name__ == "__main__":
    pats = sys.argv[1:] or [os.path.join(r'C:\Users\nangl\d\code\dest',
                                         'tmp', 'flat', '*.obj')]
    total = 0
    for pat in pats:
        for p in sorted(glob.glob(pat)):
            n = patch(p)
            if n:
                print("aligned %2d segment(s) in %s" % (n, os.path.basename(p)))
                total += n
    print("total", total)
