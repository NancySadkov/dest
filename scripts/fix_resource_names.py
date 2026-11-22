"""Restore the resource filename table at 0x2a87..0x4228.

diff_dgroup reports -6060 at s_build_clebath2_lbm (0x4228): between 0x26f7 and
0x4228 the rebuilt DGROUP is missing ~6060 bytes, and the image there is one
contiguous table of resource filenames ("bigcomp.lbm", "bighous1.lbm",
"ping.xmi", "zound007.voc", ...).

The original symbol table labels each entry `s_<path>_2410_<address>`, and
PeekBytes confirms the label body is the string itself (0x2a87 ->
"bigcomp.lbm\\0").  This script regenerates the declarations in address order
with their exact sizes taken from the next symbol's address.

usage: python scripts/fix_resource_names.py [--apply]
"""
import io
import re
import sys

LO, HI = 0x2A87, 0x4228
P = "src/decompiled/st_globals5.c"
apply = "--apply" in sys.argv

rows = []
for line in io.open("audit/symbols.tsv", encoding="utf-8"):
    f = line.rstrip("\n").split("\t")
    if len(f) < 4 or f[1] != "2410_DATA_DGROUP":
        continue
    off = int(f[0].split(":")[1], 16)
    if LO <= off < HI:
        rows.append((off, f[2]))
rows.sort()
# drop duplicate addresses (aliases) and fragment labels ("s_x_2410_1234+6"),
# which mark a position inside the preceding string
uniq = []
for off, name in rows:
    if "+" in name:
        continue
    if uniq and uniq[-1][0] == off:
        continue
    uniq.append((off, name))
uniq.append((HI, ""))

src = io.open(P, encoding="latin-1").read()
existing = set(re.findall(r"\b([A-Za-z_]\w*)\s*(\[|=)", src))

entries = []
skipped = []
for i, (off, name) in enumerate(uniq[:-1]):
    size = uniq[i + 1][0] - off
    m = re.match(r"^s_(.+)_2410_[0-9a-f]+$", name)
    if not m:
        skipped.append((off, name, size, "label"))
        continue
    content = m.group(1)
    if not re.match(r"^[\\A-Za-z0-9_.]+$", content):
        skipped.append((off, name, size, "chars"))
        continue
    if size != len(content) + 1:
        skipped.append((off, name, size, "size %d vs %d" % (size, len(content) + 1)))
        continue
    ident = "s_" + re.sub(r"[^A-Za-z0-9_]", "_", content) + "_2410_%04x" % off
    if len(ident) > 32:
        ident = ident[:27] + "_%04x" % off
    if ident in existing:
        skipped.append((off, name, size, "exists"))
        continue
    cstr = content.replace("\\", "\\\\")
    entries.append((off, 'char %s[%d] = "%s";' % (ident, size, cstr)))

print("regenerable entries: %d, skipped: %d" % (len(entries), len(skipped)))
for off, name, size, why in skipped[:10]:
    print("  skip %04x %-42s size=%-3d %s" % (off, name[:42], size, why))

if not apply:
    print("dry run; pass --apply to write")
    raise SystemExit(0)

anchor = "undefined s_build_clebath2_lbm_2410_4228 = 0x62;\n"
if anchor not in src:
    raise SystemExit("anchor not found")
block = ("/* 2a87..4228: the resource filename table (generated from the original\n"
         "   symbol table; each label body is the string and the next symbol's\n"
         "   address gives the size).  s_build_clebath2_lbm at 0x4228 is 12 bytes\n"
         "   with no NUL and stays as the scalar the export made it. */\n"
         + "\n".join(e[1] for e in entries) + "\n" + anchor)
src = src.replace(anchor, block, 1)
io.open(P, "w", encoding="latin-1", newline="\n").write(src)
print("st_globals5.c: %d declarations inserted" % len(entries))

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
decls = "".join("extern char %s[];\n" % re.match(r"char (\w+)\[", e[1]).group(1)
                for e in entries)
if entries and "extern char %s[];" % re.match(r"char (\w+)\[", entries[0][1]).group(1) not in h:
    h = h.replace("extern undefined s_build_clebath2_lbm_2410_4228;",
                  decls + "extern undefined s_build_clebath2_lbm_2410_4228;", 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: %d declarations added" % len(entries))
