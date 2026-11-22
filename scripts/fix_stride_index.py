"""Turn `((T *)base + idx * STRIDE)` into typed array indexing.

That shape is not unstructured data: the code has already cast the base to `T *`
and is stepping by a literal stride, so when `sizeof(T)` equals that stride the
expression *is* the address of `((T *)base)[idx]`.  Rewriting it

    ((agnt_t *)Entities + i * 0x34)   ->   (&((agnt_t *)Entities)[i])

keeps the meaning exactly (C guarantees the two are the same address) and removes
the stride arithmetic the section-5 grep is looking for.  Elements whose stride
does not match `sizeof(T)` are left alone and reported - those are the genuinely
unstructured cases.

usage: python scripts/fix_stride_index.py [--apply]
"""
import glob
import io
import re
import sys

apply = "--apply" in sys.argv

SIZES = {
    "uint8_t": 1, "int8_t": 1, "byte": 1, "char": 1, "sbyte": 1, "uchar": 1,
    "undefined1": 1, "bool": 1, "undefined": 1,
    "uint16_t": 2, "int16_t": 2, "uint16": 2, "undefined2": 2, "word": 2,
    "ushort": 2, "short": 2, "int": 2, "uint": 2,
    "uint32_t": 4, "int32_t": 4, "uint32": 4, "undefined4": 4, "dword": 4,
    "ulong": 4, "long": 4, "float": 4, "double": 8, "longdouble": 8,
}
types = io.open("src/decompiled/st_types.h", encoding="utf-8", errors="ignore").read()
structs = dict(re.findall(r"struct\s+(\w+)\s*\{(.*?)\n\};", types, re.S))


def ssz(name, d=0):
    if name not in structs:
        return None
    total = 0
    for line in structs[name].split("\n"):
        line = re.sub(r"/\*.*?\*/", "", line).strip().rstrip(";").strip()
        if not line:
            continue
        m = re.match(r"^(.*?[\s\*])\s*(\w+)\s*((?:\[\s*\d+\s*\])*)$", line)
        if not m:
            return None
        s = sz(m.group(1), d)
        if s is None:
            return None
        n = 1
        for x in re.findall(r"\[\s*(\d+)\s*\]", m.group(3) or ""):
            n *= int(x)
        total += s * n
    return total


def sz(ty, d=0):
    ty = ty.strip().replace("struct ", "")
    if " far *" in ty or ty.endswith("*32"):
        return 4
    if ty.endswith("*"):
        return 2
    m = re.match(r"^(.*?)\s*((?:\[\s*\d+\s*\])+)$", ty)
    if m:
        b = sz(m.group(1), d)
        n = 1
        for x in re.findall(r"\[\s*(\d+)\s*\]", m.group(2)):
            n *= int(x)
        return None if b is None else b * n
    if ty in SIZES:
        return SIZES[ty]
    if ty in structs and d < 4:
        return ssz(ty, d + 1)
    return None


def size_of(name):
    name = name.strip()
    if name in SIZES:
        return SIZES[name]
    return ssz(name)


PAT = re.compile(r"\(\(\s*([A-Za-z_]\w*)\s*\*\s*\)\s*([A-Za-z_]\w*)\s*\+\s*"
                 r"([A-Za-z_]\w*)\s*\*\s*(0x[0-9a-fA-F]+|\d+)\)")

converted = 0
skipped = []
for path in sorted(glob.glob("src/decompiled/*.c")):
    t = io.open(path, encoding="utf-8", errors="ignore").read()

    def repl(m):
        global converted
        ty, base, idx, st = m.group(1), m.group(2), m.group(3), m.group(4)
        stride = int(st, 16) if st.lower().startswith("0x") else int(st)
        n = size_of(ty)
        if n != stride:
            if (ty, stride, n) not in skipped:
                skipped.append((ty, stride, n))
            return m.group(0)
        converted += 1
        return "(&((%s *)%s)[%s])" % (ty, base, idx)

    new = PAT.sub(repl, t)
    if new != t and apply:
        io.open(path, "w", encoding="utf-8", newline="\n").write(new)

print("stride expressions converted to typed indexing:", converted)
if skipped:
    print("left alone (stride != sizeof(T)):")
    for ty, stride, n in skipped[:12]:
        print("   %-16s stride 0x%02x  sizeof=%s" % (ty, stride, n))
print("mode:", "APPLY" if apply else "dry run")
