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
import re

ORIG = "tmp/dgrun2_orig/DGR.BIN"
OURS = "tmp/dgrun2_ours/DGR.BIN"
MAP = "tmp/buildsrc/REBUILT.MAP"
SYMS = "audit/symbols.tsv"

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


def key(name):
    k = name.upper().lstrip("_")
    k = re.sub(r"\[[0-9]+\]$", "", k)
    return re.sub(r"_[0-9]$", "", k)


dgroup_seg = None
for name, (seg, ofs) in ours.items():
    if key(name) == "DATA" and ofs == 0:
        dgroup_seg = seg
if dgroup_seg is None:
    dgroup_seg = ours.get("_ANIMSEQCOUNTS", (None, None))[0]

ours_by_key = {}
for name, (seg, ofs) in ours.items():
    if seg == dgroup_seg:
        ours_by_key.setdefault(key(name), []).append((ofs, name))
for k in ours_by_key:
    ours_by_key[k].sort()

matched = []
last = -1
used = set()
for off, name in orig:
    cands = ours_by_key.get(key(name))
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

same = differ = skipped = 0
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
    else:
        differ += 1
        if len(diffs) < 20:
            diffs.append((off, name, oofs, ln, a, b))

print("runtime DGROUP comparison at main entry")
print("  original dump: %d bytes, rebuilt dump: %d bytes"
      % (len(orig_img), len(ours_img)))
print("  symbols matched: %d" % len(matched))
print("  identical state: %d" % same)
print("  DIFFERENT state: %d" % differ)
print("  skipped (outside a dump): %d" % skipped)
for off, name, oofs, ln, a, b in diffs:
    print("  %04x %-32s -> %04x len=%-3d want=%s got=%s"
          % (off, name, oofs, ln, a.hex()[:24], b.hex()[:24]))
