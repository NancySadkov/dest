"""Bind the 12-byte building-graphics table to its recovered symbol.

The model now has `bldgfx_inst_t` and `GBldGfxInstances[248]` at DGROUP:0x8ed0
(see scripts/ghidra/AddBldGfxTable.java).  The decompiler still prints a few
indexed accesses as a flat address because the segment was lost:

    *(uint16_t *)((char *)0x28ed4 + i * 0xc)   -> GBldGfxInstances[i].gfx.ofs
    *(uint16_t *)((char *)0x28ed6 + i * 0xc)   -> GBldGfxInstances[i].gfx.seg

Field offsets within the 12-byte record: +0/+2 unknown0, +4 gfx.ofs, +6 gfx.seg,
+8/+10 unknown1.

usage: python scripts/fix_bldgfx_table.py [--apply]
"""
import glob
import io
import re
import sys

PAT = re.compile(r"\*\s*\(\s*([A-Za-z_]\w*)\s*\*\s*\)\s*"
                 r"\(\s*\(char \*\)\s*0x28ed([0-9a-fA-F])\s*\+\s*"
                 r"([^()]+?)\s*\*\s*0xc\s*\)")

MEMBER = {
    0x0: "unknown0[0]",
    0x2: "unknown0[2]",
    0x4: "gfx.ofs",
    0x6: "gfx.seg",
    0x8: "unknown1[0]",
    0xa: "unknown1[2]",
}

# Already-scaled form: `(char *)0x28ed8 + iVar2` where iVar2 is the byte offset
# into the table.  Bind it to the array symbol and keep the offset explicit.
PAT2 = re.compile(r"\(\s*char \*\s*\)\s*0x28ed([0-9a-fA-F])\s*\+\s*"
                  r"([^()\s]+)")

apply = "--apply" in sys.argv
files = sorted(glob.glob("src/decompiled/*.c")) + sorted(glob.glob("overrides/*.c"))
total = 0
samples = []


def repl(m):
    global total
    ty, low, idx = m.group(1), int(m.group(2), 16), m.group(3).strip()
    off = 0x28ed0 + low
    mem = MEMBER.get(off - 0x28ed0)
    if mem is None:
        return m.group(0)
    total += 1
    new = "*(%s *)&GBldGfxInstances[%s].%s" % (ty, idx, mem)
    if len(samples) < 6:
        samples.append((m.group(0), new))
    return new


def repl2(m):
    global total
    low, idx = int(m.group(1), 16), m.group(2).strip()
    total += 1
    if low:
        return "((char *)&GBldGfxInstances[0] + %s + 0x%x)" % (idx, low)
    return "((char *)&GBldGfxInstances[0] + %s)" % idx


for p in files:
    t = io.open(p, encoding="utf-8", errors="ignore").read()
    new = PAT.sub(repl, t)
    new = PAT2.sub(repl2, new)
    if new != t and apply:
        io.open(p, "w", encoding="utf-8", newline="\n").write(new)

print("building-graphics accesses bound:", total)
print("mode:", "APPLY" if apply else "dry run")
for a, b in samples:
    print("   %-46s -> %s" % (a, b))
