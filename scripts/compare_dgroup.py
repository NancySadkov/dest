"""Compare the recovered DGROUP data against the original image's map.

audit/dgroup.csv is the original's DGROUP map, produced from the Ghidra project
by scripts/ghidra/ExportDgroup.java: one row per data item with
offset,length,type,pointer,components,repr,refs.

This script compares it with what the recovered source declares, by address
(names carrying the `_2410_XXXX` suffix) and by text:

  * every original string item should have a declaration with the same bytes;
  * every declaration with an address suffix should hit an original item.

Output: counts plus the first mismatches in each class.
"""
import csv
import glob
import io
import re

MAP = "audit/dgroup.csv"

# ---- original ----------------------------------------------------------------
orig = {}
for row in csv.DictReader(io.open(MAP, encoding="utf-8", errors="replace")):
    off = int(row["offset"], 16)
    orig[off] = (int(row["length"]), row["type"], row["repr"], int(row["refs"]))

# ---- ours --------------------------------------------------------------------
# name -> (text or None, size)
ours = {}
for path in sorted(glob.glob("src/decompiled/st_globals*.c")):
    t = io.open(path, encoding="latin-1", errors="ignore").read()
    for m in re.finditer(r'^char ([_0-9A-Za-z]+)\[(\d*)\] = "((?:[^"\\]|\\.)*)";', t, re.M):
        ours[m.group(1)] = (m.group(3), int(m.group(2)) if m.group(2) else len(m.group(3)) + 1)

# address-suffixed declarations: name ends with _2410_XXXX
by_addr = {}
for name, (text, size) in ours.items():
    m = re.search(r"_2410_([0-9a-f]{4})$", name, re.I)
    if m:
        by_addr[int(m.group(1), 16)] = (name, text, size)

missing = []
size_bad = []
text_bad = []
checked = 0
for off, (length, ty, reprv, refs) in sorted(orig.items()):
    if ty != "string" or not reprv.startswith('"'):
        continue
    text = reprv[1:-1] if reprv.endswith('"') else reprv[1:]
    hit = by_addr.get(off)
    if hit is None:
        missing.append((off, length, refs, text[:40]))
        continue
    name, otext, osize = hit
    checked += 1
    if osize != length:
        size_bad.append((off, name, length, osize, text[:30]))
    elif otext != text:
        text_bad.append((off, name, text[:30], otext[:30]))

print("original string items:      %d" % sum(1 for v in orig.values() if v[1] == "string"))
print("matched by address:         %d" % checked)
print("missing from the source:    %d" % len(missing))
print("size mismatches:            %d" % len(size_bad))
print("text mismatches:            %d" % len(text_bad))
print("\nmissing (first 10):")
for off, length, refs, text in missing[:10]:
    print("  %04x len=%-3d refs=%-2d %s" % (off, length, refs, text))
print("\nsize mismatches (first 10):")
for off, name, want, got, text in size_bad[:10]:
    print("  %04x %-38s want %-3d got %-3d %s" % (off, name, want, got, text))
print("\ntext mismatches (first 10):")
for off, name, want, got in text_bad[:10]:
    print("  %04x %-38s want %r got %r" % (off, name, want, got))
