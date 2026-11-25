"""Compare DGROUP state at `main`'s entry between the original and the rebuild.

Both images are patched so that `main`'s first instruction writes the 64 KB at
DS:0 to stdout, which the batch redirects to DGR.BIN (tmp/dump_dgroup_stdout.py).

This script maps each original DGROUP symbol (name + length from
audit/dgroup_data.csv) to its own address in the rebuilt image (REBUILT.MAP,
same matching rules as diff_dgroup.py) and compares the runtime bytes.

usage: python scripts/compare_runtime.py
"""
import csv
import io
import os
import re
import sys

ORIG = os.environ.get("RUNTIME_ORIG", "tmp/dgrun2_orig/DGR.BIN")
OURS = os.environ.get("RUNTIME_OURS", "tmp/dgrun2_ours/DGR.BIN")
MAP = "tmp/buildsrc/REBUILT.MAP"
SYMS = "audit/symbols.tsv"

DEBUG = "--debug" in sys.argv
orig_img = open(ORIG, "rb").read()
ours_img = open(OURS, "rb").read()

# ---- original symbols + lengths --------------------------------------------
length = {}
for row in csv.DictReader(io.open("audit/dgroup_data.csv", encoding="utf-8",
                                   errors="replace")):
    length[(int(row["offset"], 16), row["name"])] = int(row["length"])

orig = []
for line in io.open(SYMS, encoding="utf-8"):
    f = line.rstrip("\n").split("\t")
    if len(f) < 4 or f[1] != "2410_DATA_DGROUP" or f[3] != "Label":
        continue
    name = f[2]
    if "[" in name or ":" not in f[0]:
        continue
    if name.startswith(("__C0", "_argc", "_argv", "_environ", "_env", "_psp",
                        "DosVersion", "errno", "__brklvl", "_heapbase",
                        "__stklen", "__ovr")):
        continue
    orig.append((int(f[0].split(":")[1], 16), name))
orig.sort()

# ---- our publics ------------------------------------------------------------
pat = re.compile(r"^\s*([0-9A-Fa-f]{4}):([0-9A-Fa-f]{4})\s+(?:\S+\s+)?(\S+)\s*$")
ours = {}
for line in io.open(MAP, encoding="latin-1", errors="replace"):
    m = pat.match(line.rstrip("\n"))
    if m:
        ours.setdefault(m.group(3).upper(),
                        (int(m.group(1), 16), int(m.group(2), 16)))


def key(name, loose=False):
    # The export names long symbols with a _2410_XXXX address suffix; the
    # original and the rebuilt image spell the descriptive part differently
    # (quotes, truncation), so the suffix is the reliable identity.
    #
    # The trailing `_N` is only stripped in the loose pass: stripping it in the
    # primary key collapsed s_kill_2/3/4 (and similar families) into one key, and
    # the monotonic picker then compared the original's s_kill_3 against our
    # s_kill_4 - a mis-pairing reported as a data difference.
    k = name.upper().lstrip("_")
    m = re.search(r"_2410_([0-9A-F]{4})$", k)
    if m:
        return "OFS_" + m.group(1)
    k = re.sub(r"\[[0-9]+\]$", "", k)
    if loose:
        k = re.sub(r"_[0-9]$", "", k)
    return k


dgroup_seg = None
for name, (seg, ofs) in ours.items():
    if key(name) == "DATA" and ofs == 0:
        dgroup_seg = seg
if dgroup_seg is None:
    dgroup_seg = ours.get("_ANIMSEQCOUNTS", (None, None))[0]

ours_by_key = {}
ours_by_loose = {}
for name, (seg, ofs) in ours.items():
    if seg == dgroup_seg:
        ours_by_key.setdefault(key(name), []).append((ofs, name))
        ours_by_loose.setdefault(key(name, True), []).append((ofs, name))
for k in ours_by_key:
    ours_by_key[k].sort()
for k in ours_by_loose:
    ours_by_loose[k].sort()

matched = []
last = -1
used = set()
for off, name in orig:
    # the export's address suffix is the exact identity: prefer the twin whose
    # _2410_XXXX names this very original offset
    cands = [c for c in ours_by_key.get("OFS_%04X" % off, []) if c[1].upper().endswith("_2410_%04X" % off)]
    if not cands:
        cands = ours_by_key.get(key(name))
    if not cands:
        cands = ours_by_loose.get(key(name, True))
    if not cands:
        continue
    pick = None
    for oofs, oname in cands:
        if oofs not in used and oofs > last:
            pick = (oofs, oname)
            break
    if pick is None:
        for oofs, oname in cands:
            if oofs not in used:
                pick = (oofs, oname)
                break
    if pick is None:
        continue
    used.add(pick[0])
    last = pick[0]
    matched.append((off, name, pick[0]))

# ---- normalisation -----------------------------------------------------------
# Two runs load the image at different segments, and our DGROUP layout differs
# from the original's, so raw bytes cannot be compared for pointer data.
# A word matches if:
#   * it is the original's DGROUP segment -> ours must be our DGROUP segment;
#   * it is an original symbol offset       -> ours must be that symbol's offset;
#   * otherwise the bytes must be equal.
# GYesNo is a far-pointer table in both images: element 0's segment half is
# each run's own DGROUP segment.
gyn = next((m for m in matched if m[1] == "GYesNo"), None)
if gyn:
    orig_seg = int.from_bytes(orig_img[gyn[0] + 2:gyn[0] + 4], "little")
    ours_seg = int.from_bytes(ours_img[gyn[2] + 2:gyn[2] + 4], "little")
else:
    orig_seg, ours_seg = 0, dgroup_seg
# Cross-check the rebuilt DGROUP segment: every original word that holds the
# original's runtime DGROUP segment must hold whichever segment the rebuild uses for
# the same data.  Take the most frequent such value, so one odd table cannot skew the
# whole comparison.
from collections import Counter
_tally = Counter()
for off, name, oofs in matched:
    ln = min(length.get((off, name), 8), 64)
    if off + ln > len(orig_img) or oofs + ln > len(ours_img):
        continue
    a = orig_img[off:off + ln]
    b = ours_img[oofs:oofs + ln]
    for i in range(0, len(a) - 1, 2):
        if int.from_bytes(a[i:i + 2], "little") == orig_seg:
            _tally[int.from_bytes(b[i:i + 2], "little")] += 1
alt_seg = None
if _tally:
    learned, count = _tally.most_common(1)[0]
    if learned != ours_seg:
        alt_seg = learned
        print("  pointer words also encode DGROUP as %04x (%d words; the runtime "
              "segment is %04x)" % (learned, count, ours_seg or 0))
        if learned == 0x2410:
            print("  NOTE: 0x2410 is the ORIGINAL image's link-time DGROUP; the "
                  "original's own dump never contains it (its loader relocates those "
                  "initialisers).  Words using it are a data defect, counted below.")
print("  original DGROUP segment %04x, rebuilt %04x" % (orig_seg, ours_seg or 0))

off_map = {}
for off, name, oofs in matched:
    name_ln = length.get((off, name), 1)
    off_map[off] = (oofs, name_ln)

# every symbol as an interval, so an interior pointer offset can be mapped
containers = sorted((off, off + max(length.get((off, name), 1), 1), oofs)
                    for off, name, oofs in matched)


def map_off(w):
    for a, b, o in containers:
        if a <= w < b:
            return o + (w - a)
    return None


linktime_seg_hits = []


def word_matches(a, b, i):
    if a == b:
        return True
    want = int.from_bytes(a, "little")
    got = int.from_bytes(b, "little")
    if want == 0 and got == 0:
        return True
    if want == orig_seg and got in (ours_seg, alt_seg):
        if alt_seg is not None and got == alt_seg:
            linktime_seg_hits.append(1)
        return True
    m = map_off(want)
    if m is not None and m == got:
        return True
    # Anonymous strings have no symbol to map: accept the pair when both offsets reach
    # the same NUL-terminated text.
    if want < len(orig_img) and got < len(ours_img):
        eo = orig_img.find(b"\x00", want)
        eu = ours_img.find(b"\x00", got)
        if eo > want and eu > got and (eo - want) == (eu - got):
            if orig_img[want:eo] == ours_img[got:eu]:
                return True
    return False


def symbol_matches(a, b):
    if len(a) != len(b):
        return False
    for i in range(0, len(a) - 1, 2):
        if not word_matches(a[i:i + 2], b[i:i + 2], i):
            return False
    return True


if DEBUG:
    print("debug: matched", len(matched))
    print("debug: map_off(0x352) =", map_off(0x352))
    print("debug: near 0x352:",
          [c for c in containers if 0x340 <= c[0] <= 0x360][:5])
    print("debug: names near:", [(o, n) for o, n, _ in matched
                                 if 0x340 <= o <= 0x360][:5])

same = differ = skipped = 0
semantic = 0
diffs = []
for off, name, oofs in matched:
    ln = length.get((off, name))
    if ln is None:
        ln = 8
    ln = min(ln, 64)
    if off + ln > len(orig_img) or oofs + ln > len(ours_img):
        skipped += 1
        continue
    a = orig_img[off:off + ln]
    b = ours_img[oofs:oofs + ln]
    if a == b:
        same += 1
    elif symbol_matches(a, b):
        same += 1
        semantic += 1
    else:
        differ += 1
        if len(diffs) < 20:
            diffs.append((off, name, oofs, ln, a, b))

print("runtime DGROUP comparison (paths from RUNTIME_ORIG/RUNTIME_OURS; default: main entry)")
print("  original dump: %d bytes, rebuilt dump: %d bytes"
      % (len(orig_img), len(ours_img)))
print("  symbols matched: %d" % len(matched))
print("  identical state: %d" % same)
print("  DIFFERENT state: %d" % differ)
print("  skipped (outside a dump): %d" % skipped)
print("  words using the original link-time segment 0x2410: %d"
      % len(linktime_seg_hits))
print("  of the identical ones, %d match after segment/offset normalisation"
      % semantic)
for off, name, oofs, ln, a, b in diffs:
    print("  %04x %-32s -> %04x len=%-3d want=%s got=%s"
          % (off, name, oofs, ln, a.hex()[:24], b.hex()[:24]))
