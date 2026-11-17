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


def _index(pl, j):
    """Read an OMF variable-length index; return (value, next_pos)."""
    v = pl[j]
    if v & 0x80:
        return ((v & 0x7F) << 8) | pl[j + 1], j + 2
    return v, j + 1


def parse_relocs(path):
    """Return {segment: [(offset, size, target)]} for every FIXUP.

    ``offset`` is relative to the segment start.  ``size`` is the number of
    bytes the linker overwrites.  ``target`` describes the referenced symbol
    (external name, segment or group) when the fixup names one.
    """
    d = open(path, "rb").read()
    extdef = []
    out = {}
    i = 0
    last_ledata = {}
    while i + 3 <= len(d):
        t = d[i]
        ln = d[i + 1] | (d[i + 2] << 8)
        pl = d[i + 3:i + 3 + ln - 1]  # drop checksum
        i += 3 + ln
        if t == 0x8C:  # EXTDEF
            j = 0
            while j < len(pl):
                n = pl[j]
                name = pl[j + 1:j + 1 + (n & 0x7F)].decode("ascii", "replace")
                j += 1 + (n & 0x7F)
                # TCC always emits a (zero) type index byte.
                j += 1
                extdef.append(name)
        elif t == 0xA0:  # LEDATA
            seg = pl[0] & 0x7F
            last_ledata[seg] = pl[1] | (pl[2] << 8)
        elif t == 0x9C:  # FIXUPP
            j = 0
            while j < len(pl):
                b = pl[j]
                if not (b & 0x80):  # THREAD subrecord
                    j += 1
                    if b & 0x08:
                        _, j = _index(pl, j)
                    continue
                locat = (b << 8) | pl[j + 1]
                j += 2
                dro = locat & 0x3FF
                loc = (locat >> 10) & 0xF
                fixdat = pl[j]
                j += 1
                frame = (fixdat >> 4) & 7
                f_thread = fixdat >> 7
                target = fixdat & 3
                t_thread = (fixdat >> 3) & 1
                p = (fixdat >> 2) & 1
                if frame not in (4, 5) and not f_thread:
                    idx, j = _index(pl, j)
                if target != 6 and not t_thread:
                    idx, j = _index(pl, j)
                    kind = {0: "seg", 1: "grp", 2: "ext"}.get(target)
                    if kind == "ext" and 0 < idx <= len(extdef):
                        name = extdef[idx - 1]
                    else:
                        name = "%s%d" % (kind or "m%d" % target, idx)
                elif target == 6:
                    name = "frame"
                else:
                    name = "thread"
                if not p:
                    j += 2
                size = {0: 1, 1: 2, 2: 2, 3: 4, 4: 1, 5: 2,
                        9: 4, 11: 6, 13: 4}.get(loc, 1)
                # FIXUPs apply to the preceding LEDATA record.
                seg = None
                for s, off in last_ledata.items():
                    seg = s
                off = last_ledata[seg] + dro
                out.setdefault(seg, []).append((off, size, name))
    return out


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
