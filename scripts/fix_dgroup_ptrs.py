"""Name the DGROUP far pointers that Ghidra folds into 32-bit literals.

This program addresses data with far pointers whose segment is the DGROUP segment
0x2410.  The decompiler sometimes folds such a pointer into a single number with
the shape `<offset><2410>`, e.g.

    0xe62410   ->  0x2410:0x00e6  = MouseY
    0xff2410   ->  0x2410:0x00ff  = GUnitDescriptions[5].ofs
    0x12410    ->  0x2410:0x0001  (no symbol)

Every such literal in the tree is used inside a pointer cast.  When the target
address has a symbol the cast becomes a reference to that symbol, so the code
reads as data access instead of a magic number; otherwise it becomes
MK_FP(0x2410, offset), which states the segment explicitly.

Both forms keep the pointer width of the original cast, so no type changes.

usage: python scripts/fix_dgroup_ptrs.py [--apply]
"""
import glob
import io
import re
import sys

TSV = "tmp/dg12.tsv"

sym = {}
for line in io.open(TSV, encoding="utf-8", errors="replace"):
    p = line.rstrip("\n").split("\t")
    if len(p) < 2 or ":" not in p[0]:
        continue
    seg, off = p[0].split(":")
    if seg.lower() == "2410":
        sym.setdefault(int(off, 16), p[1])
print("symbols in DGROUP:", len(sym))

# already-symbolised forms produced by earlier runs of this script
OLD = re.compile(r"\(\s*([A-Za-z_]\w*)\s*\*\s*\)\s*\(\s*uint16_t\s*\)\s*&")
# `(void *)&_DATA+2` parses as `((void *)&_DATA) + 2`; rebuild it as address arithmetic
OLDP = re.compile(r"\(\s*([A-Za-z_]\w*)\s*\*\s*\)\s*&(\w+)\+([0-9A-Za-z]+)\b")
PAT = re.compile(r"\(\s*([A-Za-z_]\w*(?:\s+[A-Za-z_]\w*)*)\s*\*\s*\)\s*"
                 r"0x([0-9a-fA-F]{5,8})\b")

apply = "--apply" in sys.argv
files = sorted(glob.glob("src/decompiled/*.c")) + sorted(glob.glob("overrides/*.c"))
total = named = raw = norm = 0
samples = []


def repl(m):
    global total, named, raw
    ty, hexv = m.group(1).strip(), m.group(2)
    val = int(hexv, 16)
    if (val & 0xFFFF) != 0x2410:
        return m.group(0)
    off = val >> 16
    if off == 0:
        return m.group(0)
    total += 1
    name = sym.get(off)
    if name:
        named += 1
        m2 = re.match(r"^(\w+)\+(\w+)$", name)
        if m2:
            # a composite symbol name such as `_DATA+2` is an address, not an
            # lvalue; `&_DATA+2` would parse as `(&_DATA) + 2`
            new = "(%s *)((char *)&%s + %s)" % (ty, m2.group(1), m2.group(2))
        else:
            new = "(%s *)&%s" % (ty, name)
    else:
        raw += 1
        new = "(%s *)MK_FP(0x2410, 0x%x)" % (ty, off)
    if len(samples) < 8:
        samples.append((m.group(0), new))
    return new


def norm_repl(m):
    global norm
    norm += 1
    return "(%s *)&" % m.group(1)


def norm_plus(m):
    global norm
    norm += 1
    return "(%s *)((char *)&%s + %s)" % (m.group(1), m.group(2), m.group(3))


for p in files:
    t = io.open(p, encoding="utf-8", errors="ignore").read()
    new = OLDP.sub(norm_plus, t)
    new = OLD.sub(norm_repl, new)
    new = PAT.sub(repl, new)
    if new != t and apply:
        io.open(p, "w", encoding="utf-8", newline="\n").write(new)

print("DGROUP pointer literals:", total, "named via symbol:", named,
      "kept explicit via MK_FP:", raw, "normalised:", norm)
print("mode:", "APPLY" if apply else "dry run")
for a, b in samples:
    print("   %-18s -> %s" % (a, b))
