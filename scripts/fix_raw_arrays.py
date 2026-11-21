"""General sweep for raw array indexing: <expr> * STRIDE + CONST.

Ghidra folds the array's own offset into the constant, so
    bldType * 0x27 + 0x133
is &BuildingTypes[bldType] + 0x25  (base 195d:010e, element size 39 = 0x27).

Matching uses two independent facts from the symbol dump:
  * element size == STRIDE        (length / count from `T[N]` + symbol length)
  * 0 <= CONST - symbol_offset < STRIDE
and only rewrites when exactly one array satisfies both, so a base is never
guessed.  Dry run unless --apply is given.
"""
import io
import os
import re
import sys

PAT = re.compile(r"\*\((\w+) \*\)\((\w+) \* (0x[0-9a-fA-F]+|\d+) \+ (0x[0-9a-fA-F]+|\d+)\)")
TYPED = re.compile(r"^(.*?)\[(\d+)\]$")

arrays = []          # (name, offset, element_size, count)
for line in list(io.open("tmp/dg12.tsv", encoding="utf-8", errors="replace"))[1:]:
    p = line.rstrip("\n").split("\t")
    if len(p) < 4 or ":" not in p[0]:
        continue
    m = TYPED.match(p[2])
    if not m:
        continue
    cnt = int(m.group(2))
    try:
        length = int(p[3])
    except ValueError:
        continue
    if cnt <= 0 or length <= 0 or length % cnt:
        continue
    seg, off = p[0].split(":")
    if seg.upper() in ("0", "0000"):
        continue
    arrays.append((p[1], int(off, 16), length // cnt, cnt))

print("arrays with a computable element size:", len(arrays))


def find_base(const, stride):
    hits = [(n, const - o) for n, o, es, c in arrays
            if es == stride and 0 <= const - o < stride]
    return hits[0] if len(hits) == 1 else None


apply = "--apply" in sys.argv
total = fixed = skipped = 0
samples = []
for name in sorted(os.listdir("src/decompiled")):
    if not name.endswith(".c"):
        continue
    path = os.path.join("src/decompiled", name)
    text = io.open(path, encoding="utf-8", errors="ignore").read()
    out, pos = [], 0
    for m in PAT.finditer(text):
        total += 1
        cast, var, stride_s, const_s = m.groups()
        stride = int(stride_s, 0)
        const = int(const_s, 0)
        hit = find_base(const, stride)
        if hit is None:
            skipped += 1
            continue
        arr, delta = hit
        repl = ("*(%s *)(&%s[%s])" % (cast, arr, var) if delta == 0 else
                "*(%s *)((uint8_t *)&%s[%s] + %d)" % (cast, arr, var, delta))
        out.append(text[pos:m.start()])
        out.append(repl)
        pos = m.end()
        fixed += 1
        if len(samples) < 8:
            samples.append((name, m.group(0)[:56], repl[:64]))
    if out:
        out.append(text[pos:])
        if apply:
            io.open(path, "w", encoding="utf-8", newline="\n").write("".join(out))

print("candidates:", total, "rewritten:", fixed, "skipped:", skipped)
print("mode:", "APPLY" if apply else "dry run")
for n, a, b in samples:
    print("   %-20s %-52s -> %s" % (n, a, b))
