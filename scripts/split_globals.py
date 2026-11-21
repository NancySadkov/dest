"""Split the generated globals into TUs that each stay under Turbo C's 64 KB limit.

Turbo C stops with "Too much global data defined in file" once a translation unit
holds more than 64 KB of *data*, so the split budgets data size: each definition's
size is estimated from its declared type and array dimensions, and the files are
filled to ~45 KB of data each.

The split is idempotent -- any existing st_globalsN.c parts are merged back first,
so repeated runs cannot keep shrinking part 1.
"""
import glob
import io
import os
import re
import sys

BASE = "src/decompiled/st_globals"
LIMIT = int(sys.argv[1]) if len(sys.argv) > 1 else 45000

SIZES = {
    "uint8_t": 1, "int8_t": 1, "byte": 1, "char": 1, "sbyte": 1, "uchar": 1,
    "undefined1": 1, "bool": 1, "undefined": 1,
    "uint16_t": 2, "int16_t": 2, "uint16": 2, "undefined2": 2, "word": 2,
    "ushort": 2, "short": 2, "int": 2, "uint": 2,
    "uint32_t": 4, "int32_t": 4, "uint32": 4, "undefined4": 4, "dword": 4,
    "ulong": 4, "long": 4, "float": 4,
}


def decl_size(line):
    s = line.split("=")[0].strip()
    m = re.match(r"^(.*?)([A-Za-z_]\w*)\s*((?:\[[^\]]*\])*)\s*$", s)
    if not m:
        m2 = re.search(r"\(\s*(?:far\s*)?\*\s*[A-Za-z_]\w*\s*\)", s)
        return 4 if m2 else 2
    ty = m.group(1).strip()
    n = 1
    for d in re.findall(r"\[([^\]]*)\]", m.group(3)):
        d = d.strip()
        n *= int(d) if d.isdigit() else 1
    ty = ty.replace("struct ", "").strip()
    if ty.endswith("*32"):
        return 4 * n
    if ty.endswith("*"):
        return 2 * n
    return max(1, SIZES.get(ty, 16) * n)


def head_body(text):
    lines = text.split("\n")
    head = [l for l in lines if l.startswith("#include") or l.startswith("/*")]
    body = [l for l in lines if not (l.startswith("#include") or l.startswith("/*"))]
    return head, body


head, body = head_body(io.open(BASE + ".c", encoding="utf-8", errors="ignore").read())
for p in sorted(glob.glob(BASE + "[0-9]*.c")):
    _, b = head_body(io.open(p, encoding="utf-8", errors="ignore").read())
    body += b
    os.remove(p)
    print("merged back", os.path.basename(p))

starts = [i for i, l in enumerate(body) if l and l[0] not in " \t"]
if not starts:
    print("no definitions found")
    raise SystemExit(0)
starts.append(len(body))

chunks = [[]]
data = 0
for k in range(len(starts) - 1):
    seg = body[starts[k]:starts[k + 1]]
    sz = decl_size(seg[0])
    if chunks[-1] and data + sz > LIMIT:
        chunks.append([])
        data = 0
    chunks[-1].extend(seg)
    data += sz

base = "\n".join(head) + "\n"
out = []
for i, ch in enumerate(chunks):
    name = BASE + (".c" if i == 0 else "%d.c" % (i + 1))
    io.open(name, "w", encoding="utf-8", newline="\n").write(base + "\n".join(ch))
    out.append((os.path.basename(name), len(ch)))
print("split into", len(chunks), "TUs:", out)
