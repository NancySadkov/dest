"""Type `ptr + index * struct_size` as a struct pointer.

Ghidra often keeps an address in an integer variable and indexes a record table
by hand:

    *(int *)(iVar4 + entityIndex * 0x37)

With stride 0x37 = sizeof(entity_t) this is simply `((entity_t *)iVar4)[entityIndex]`.
The rewrite keeps the arithmetic exact (pointer addition scales by sizeof(T)) and
makes the record type explicit, which is what a later `->field` rewrite needs.

A stride is only rewritten when exactly one recovered struct has that size, so
nothing is guessed.  Screen-row strides (0x140) match no struct and are left
alone.

usage: python scripts/fix_struct_stride.py [--apply]
"""
import glob
import io
import re
import sys

HDR = "src/decompiled/st_types.h"

SIZES = {
    "uint8_t": 1, "int8_t": 1, "byte": 1, "char": 1, "sbyte": 1, "uchar": 1,
    "undefined1": 1, "bool": 1, "undefined": 1,
    "uint16_t": 2, "int16_t": 2, "uint16": 2, "undefined2": 2, "word": 2,
    "ushort": 2, "short": 2, "int": 2, "uint": 2,
    "uint32_t": 4, "int32_t": 4, "uint32": 4, "undefined4": 4, "dword": 4,
    "ulong": 4, "long": 4, "float": 4,
}

text = io.open(HDR, encoding="utf-8", errors="ignore").read()
structs = dict(re.findall(r"struct\s+(\w+)\s*\{(.*?)\n\};", text, re.S))


def size_of(ty, depth=0):
    ty = ty.strip().replace("struct ", "")
    if ty.endswith("*32") or "far *" in ty:
        return 4
    if ty.endswith("*"):
        return 2
    m = re.match(r"^(.*?)\s*((?:\[\s*\d+\s*\])+)$", ty)
    if m:
        b = size_of(m.group(1), depth)
        n = 1
        for d in re.findall(r"\[\s*(\d+)\s*\]", m.group(2)):
            n *= int(d)
        return None if b is None else b * n
    if ty in SIZES:
        return SIZES[ty]
    if ty in structs and depth < 4:
        return struct_size(ty, depth + 1)
    return None


def struct_size(name, depth=0):
    total = 0
    for line in structs[name].split("\n"):
        line = re.sub(r"/\*.*?\*/", "", line).strip().rstrip(";").strip()
        if not line:
            continue
        mm = re.match(r"^(.*?[\s\*])\s*(\w+)\s*((?:\[\s*\d+\s*\])*)$", line)
        if not mm:
            return None
        s = size_of(mm.group(1), depth)
        if s is None:
            return None
        n = 1
        for d in re.findall(r"\[\s*(\d+)\s*\]", mm.group(3) or ""):
            n *= int(d)
        total += s * n
    return total


by_size = {}
for name in structs:
    s = struct_size(name)
    if s:
        by_size.setdefault(s, []).append(name)

PAT = re.compile(r"\((\s*[A-Za-z_]\w*\s*) \+ (\s*[A-Za-z_]\w*\s*) \* (0x[0-9a-fA-F]+)\)")

apply = "--apply" in sys.argv
files = sorted(glob.glob("src/decompiled/*.c")) + sorted(glob.glob("overrides/*.c"))
done = skipped = total = 0
samples = []


def repl(m):
    global done, skipped, total
    total += 1
    base, idx, stride = m.group(1).strip(), m.group(2).strip(), int(m.group(3), 16)
    cands = by_size.get(stride, [])
    if len(cands) != 1:
        skipped += 1
        return m.group(0)
    done += 1
    new = "((%s *)%s + %s)" % (cands[0], base, idx)
    if len(samples) < 8:
        samples.append((m.group(0), new))
    return new


for p in files:
    t = io.open(p, encoding="utf-8", errors="ignore").read()
    new = PAT.sub(repl, t)
    if new != t and apply:
        io.open(p, "w", encoding="utf-8", newline="\n").write(new)

print("ptr+index*stride expressions:", total, "typed:", done, "skipped(ambiguous/none):", skipped)
print("mode:", "APPLY" if apply else "dry run")
for a, b in samples:
    print("   %-34s -> %s" % (a, b))
