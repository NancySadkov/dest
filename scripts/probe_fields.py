"""Can the runtime checkpoints observe the state that the rewritten routines read?

`scripts/compare_runtime.py` compares every matched DGROUP symbol and prints only differences,
which leaves this question unanswered.  For each table that `ovc15_textError` and
`ovc23_usesAlignUp43` consume, this reports one of three states:

  not in DGROUP   the table is not part of the 64 KB at DS:0 at all, so a DGROUP dump can never
                  see it regardless of when the dump is taken;
  unpopulated     the DGROUP slot exists but still holds zero at this checkpoint, i.e. the table
                  has not been built yet;
  populated       the slot holds data; the bytes are then compared against the original's.

Note that GMapCells / GMapFlags / GUnitGrid / GUnits are *far-pointer slots* in DGROUP (the code
reaches them as `les bx, ptr es:[0x8a0d]`), so their 4 bytes are a pointer word, not the table.
The table itself lives wherever that pointer points.
"""

import csv
import io
import os
import re
import struct

ROOT = r"C:\Users\nangl\d\code\dest"

FIELDS = [
    ("AgntGs", 0x95 * 42),
    ("Agnts", 0x34 * 64),
    ("GLeaderSheets", 4 * 80),
    ("GUnitGrid", 2 * 148 * 60),
    ("GUnits", 9 * 256),
    ("BuildingTypes", 0x27 * 64),
    ("GMapFlags", 2 * 60 * 148),
    ("GMapCells", 59 * 148),
    ("EntityCount", 2),
    ("GUnitCount", 2),
    ("GRecordCount", 2),
    ("PlayerCount", 2),
    ("GLeaderCount", 1),
]
POINTER_SLOTS = {"GUnitGrid", "GUnits", "GMapFlags", "GMapCells", "GLeaderSheets", "AgntGs",
                 "Agnts", "BuildingTypes"}

orig_off = {}
for row in csv.DictReader(io.open(os.path.join(ROOT, "audit", "dgroup_data.csv"),
                                  encoding="utf-8", errors="replace")):
    try:
        orig_off[row["name"]] = int(row["offset"], 16)
    except (KeyError, ValueError):
        pass

pat = re.compile(r"^\s*([0-9A-Fa-f]{4}):([0-9A-Fa-f]{4})\s+(?:idle\s+)?(\S+)\s*$")
ours_all = {}
for line in io.open(os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.MAP"),
                    encoding="latin-1", errors="replace"):
    m = pat.match(line.rstrip("\n"))
    if m:
        ours_all.setdefault(m.group(3).upper().lstrip("_"), []).append(
            (int(m.group(1), 16), int(m.group(2), 16)))

tally = {}
for lst in ours_all.values():
    for seg, ofs in lst:
        tally[seg] = tally.get(seg, 0) + 1
DG = max(tally, key=tally.get)
ours_off = {}
for name, lst in ours_all.items():
    for seg, ofs in lst:
        if seg == DG:
            ours_off[name] = ofs
            break

orig = io.open(os.path.join(ROOT, "tmp", "dgrun2_orig", "DGR.BIN"), "rb").read()
ours = io.open(os.path.join(ROOT, "tmp", "dgrun2_ours", "DGR.BIN"), "rb").read()


def ptr(img, off):
    return struct.unpack("<HH", img[off:off + 4])


print("rebuilt DGROUP segment %04x, dumps %d / %d bytes" % (DG, len(orig), len(ours)))
print("%-18s %-6s %-6s %s" % ("field", "orig", "ours", "state at this checkpoint"))
print("-" * 78)

states = {}
for name, ln in FIELDS:
    o = orig_off.get(name)
    u = ours_off.get(name.upper())
    if o is None or u is None:
        states.setdefault("not in DGROUP", []).append(name)
        print("%-18s %-6s %-6s not in DGROUP  (%-6s)" %
              (name, "-" if o is None else "%04x" % o, "-" if u is None else "%04x" % u,
               "original" if o is None else "rebuilt"))
        continue
    if name in POINTER_SLOTS:
        oo, os_ = ptr(orig, o)
        uo, us_ = ptr(ours, u)
        if oo == 0 and os_ == 0 and uo == 0 and us_ == 0:
            states.setdefault("unpopulated", []).append(name)
            print("%-18s %04x   %04x   unpopulated: pointer slot %04x:%04x (both)"
                  % (name, o, u, os_, oo))
        else:
            print("%-18s %04x   %04x   pointer orig %04x:%04x  ours %04x:%04x"
                  % (name, o, u, os_, oo, us_, uo))
            states.setdefault("populated", []).append(name)
        continue
    a = orig[o:o + ln]
    b = ours[u:u + ln]
    if a == b:
        states.setdefault("populated", []).append(name)
        print("%-18s %04x   %04x   identical (%d bytes)" % (name, o, u, ln))
    else:
        states.setdefault("populated", []).append(name)
        print("%-18s %04x   %04x   DIFFER" % (name, o, u))

print()
for k in ("not in DGROUP", "unpopulated", "populated"):
    if k in states:
        print("%-14s %d: %s" % (k, len(states[k]), ", ".join(states[k])))
print()
print("So a DGROUP-only dump at this checkpoint can observe none of the tables that")
print("ovc15_textError and ovc23_usesAlignUp43 read: they are behind far pointers or in")
print("segments outside DS.  The instrument has to resolve those pointers, and it has to be")
print("taken after the game has populated them.")
