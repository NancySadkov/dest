"""Name struct fields that the decompiler printed as raw offsets.

Ghidra lost the base type of many tables, so a field read comes out as

    *(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d)

which is a far-pointer table entry plus a field offset.  When exactly one
recovered struct has a field at that offset whose size matches the access width,
the expression is rewritten to a named field access:

    ((char_sheet_t *)(int)*(undefined4 *)((uint)partyIndex << 2))->population

Same address, same width, no guess: the offset and the size are the evidence.
Ambiguous offsets (more than one struct with a matching field) are left alone.

usage: python scripts/fix_field_access.py [--apply]
"""
import glob
import io
import os
import re
import sys

HEADER = "src/decompiled/st_types.h"

SIZES = {
    "uint8_t": 1, "int8_t": 1, "byte": 1, "char": 1, "sbyte": 1, "uchar": 1,
    "undefined1": 1, "bool": 1,
    "uint16_t": 2, "int16_t": 2, "uint16": 2, "undefined2": 2, "word": 2,
    "ushort": 2, "short": 2, "int": 2, "uint": 2,
    "uint32_t": 4, "int32_t": 4, "uint32": 4, "undefined4": 4, "dword": 4,
    "ulong": 4, "long": 4, "float": 4,
}

text = io.open(HEADER, encoding="utf-8", errors="ignore").read()
structs = {}
for m in re.finditer(r"struct\s+(\w+)\s*\{(.*?)\n\};", text, re.S):
    structs[m.group(1)] = m.group(2)


def size_of(ty):
    ty = ty.strip()
    if ty.endswith("*32") or " far *" in ty:
        return 4
    if ty.endswith("*"):
        return 2
    m = re.match(r"^(.*?)\s*((?:\[\s*\d+\s*\])+)$", ty)
    if m:
        b = size_of(m.group(1))
        n = 1
        for d in re.findall(r"\[\s*(\d+)\s*\]", m.group(2)):
            n *= int(d)
        return None if b is None else b * n
    name = ty.replace("struct ", "").strip()
    if name in SIZES:
        return SIZES[name]
    if name in structs:
        return struct_size(name)
    return None


def fields(name):
    out = []
    off = 0
    for line in structs[name].split("\n"):
        line = re.sub(r"/\*.*?\*/", "", line).strip().rstrip(";").strip()
        if not line:
            continue
        mm = re.match(r"^(.*?[\s\*])\s*(\w+)\s*((?:\[\s*\d+\s*\])*)$", line)
        if not mm:
            return []
        s = size_of(mm.group(1))
        n = 1
        for d in re.findall(r"\[\s*(\d+)\s*\]", mm.group(3) or ""):
            n *= int(d)
        if s is None:
            return []
        out.append((off, s * n, mm.group(2), s, n, bool(mm.group(3).strip()),
                    mm.group(1).strip()))
        off += s * n
    return out


def struct_size(name):
    return sum(sz for _, sz, *_ in fields(name))


by_off = {}
for s in structs:
    for off, sz, fname, elem, cnt, is_arr, _ty in fields(s):
        # pad_NN / unk_NN components are auto-generated filler, never a name
        if fname.startswith(("pad_", "unk_", "UNK")):
            continue
        by_off.setdefault(off, []).append((s, fname, sz, elem, cnt, is_arr))

# *(TYPE *)((int)*(undefined4 *)(EXPR) + 0xNN)
pat = re.compile(r"\*\(\s*(u?int\d+_t|undefined\d|byte|char|uint|int|ushort|word|dword)"
                 r"\s*\*\s*\)\s*\(\s*\(int\)\s*\*\s*\(\s*undefined4\s*\*\s*\)\s*"
                 r"((?:\([^()]*(?:\([^()]*\)[^()]*)*\)|[^()])*?)\s*\+\s*"
                 r"(0x[0-9a-fA-F]+)\s*\)")

apply = "--apply" in sys.argv
files = sorted(glob.glob("src/decompiled/*.c"))
total = done = 0
samples = []
skipped = 0
for p in files:
    src = io.open(p, encoding="utf-8", errors="ignore").read()
    orig = src

    def repl(m):
        global done, skipped, total
        total += 1
        ty, expr, offs = m.group(1), m.group(2).strip(), int(m.group(3), 16)
        width = SIZES.get(ty)
        cands = [c for c in by_off.get(offs, []) if c[3] == width]
        if len(cands) != 1:
            skipped += 1
            return m.group(0)
        sname, fname = cands[0][0], cands[0][1]
        if cands[0][5]:
            fname = fname + "[0]"
        done += 1
        if len(samples) < 8:
            samples.append((p.split("\\")[-1], m.group(0)[:70],
                            "((%s *)(%s))->%s" % (sname, expr, fname)))
        return "((%s *)(%s))->%s" % (sname, expr, fname)

    src = pat.sub(repl, src)
    if src != orig and apply:
        io.open(p, "w", encoding="utf-8", newline="\n").write(src)

# a struct field declared as an array must never be used bare: `->buildType`
# where buildType is `byte[1]` is neither assignable nor a scalar argument, so
# every bare use becomes `->buildType[0]`.
# A field name is only normalised when it is an array in *every* struct that
# declares it: `dir` is `byte[4]` in one record but a plain `byte` in entity_t,
# and a blanket `->dir[0]` made the entity field unassignable.
decl = {}
for sname in structs:
    for off, sz, fname, elem, cnt, is_arr, _ty in fields(sname):
        if fname.startswith(("pad_", "unk_", "UNK")):
            continue
        decl.setdefault(fname, []).append(is_arr)
arr_fields = {n: True for n, v in decl.items() if v and all(v)}

bare = 0
if arr_fields:
    names = "|".join(sorted(arr_fields, key=len, reverse=True))
    BAREPAT = re.compile(r"->\\s*(" + names + r")(?![\\[\\w])")
    for p in files:
        t = io.open(p, encoding="utf-8", errors="ignore").read()
        new, k = BAREPAT.subn(lambda m: "->%s[0]" % m.group(1), t)
        if k:
            bare += k
            if apply:
                io.open(p, "w", encoding="utf-8", newline="\n").write(new)

print("array fields used bare:", bare)

# `*(T *)(BASE + IDX * STRIDE + OFF)` is a field of an array element: the stride
# identifies the record type and OFF the field.  Both must match exactly once.
STRIDE_FIELD = re.compile(
    r"\*\s*\(\s*([A-Za-z_]\w*)\s*\*\s*\)\s*\(\s*([A-Za-z_]\w*)\s*\+\s*"
    r"([A-Za-z_]\w*)\s*\*\s*(0x[0-9a-fA-F]+)\s*\+\s*(0x[0-9a-fA-F]+|\d+)\s*\)")

def resolve_field(sname, off, width, depth=0):
    """Dotted field path of `width` at `off` in struct `sname`, nested structs included."""
    if depth > 4:
        return None
    for foff, fsz, fname, elem, cnt, is_arr, fty in fields(sname):
        if is_arr or fname.startswith(("pad_", "unk_", "UNK")):
            continue
        if foff == off and elem == width:
            return fname
        if foff <= off < foff + fsz:
            base = fty.replace("struct ", "").strip()
            if base in structs:
                rest = resolve_field(base, off - foff, width, depth + 1)
                if rest:
                    return fname + "." + rest
    return None


stride_hits = 0


def stride_repl(m):
    global stride_hits
    ty, base, idx = m.group(1), m.group(2), m.group(3)
    stride, off = int(m.group(4), 16), int(m.group(5), 0)
    width = SIZES.get(ty)
    owners = [sname for sname in structs if struct_size(sname) == stride]
    if len(owners) != 1:
        return m.group(0)
    owner = owners[0]
    fname = resolve_field(owner, off, width)
    if fname is None:
        return m.group(0)
    stride_hits += 1
    return "((%s *)%s)[%s].%s" % (owner, base, idx, fname)


for p in files:
    t = io.open(p, encoding="utf-8", errors="ignore").read()
    new = STRIDE_FIELD.sub(stride_repl, t)
    if new != t and apply:
        io.open(p, "w", encoding="utf-8", newline="\n").write(new)

print("stride+offset field accesses:", stride_hits)

print("offset accesses found:", total, "named:", done, "ambiguous/skipped:", skipped)
print("mode:", "APPLY" if apply else "dry run")
for f, a, b in samples:
    print("   %-22s %-70s -> %s" % (f, a, b))
