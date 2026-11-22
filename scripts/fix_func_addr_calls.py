"""Bind `func_0x<linear>` call sites to the symbol the model has there.

Ghidra renders a call to an address it does not treat as a function entry as
`func_0x<linear address>`, even when the target has been promoted to a function.
The mapping is proven (scripts/model/func_addr_names.tsv: linear address ->
segment:offset -> model symbol), so the call site can be rewritten to the symbol
name.  Only targets that the tree actually defines are rewritten; the rest are
reported so the missing ones stay visible instead of being silently stubbed.

usage: python scripts/fix_func_addr_calls.py [--apply]
"""
import glob
import io
import os
import re
import sys

apply = "--apply" in sys.argv
HERE = os.path.dirname(os.path.abspath(__file__))
TSV = os.path.join(HERE, "model", "func_addr_names.tsv")

# linear address -> symbol
mapping = {}
for line in io.open(TSV, encoding="utf-8"):
    line = line.strip()
    if not line or line.startswith("#"):
        continue
    p = line.split("\t")
    if len(p) < 3 or p[1] == "-":
        continue
    mapping[p[0].lower()] = p[2]

# which targets does the tree define?
defined = set()
for path in glob.glob("src/decompiled/*.c"):
    t = io.open(path, encoding="utf-8", errors="ignore").read()
    for m in re.finditer(r"^[A-Za-z_][\w \*]*?\b([A-Za-z_]\w*)\s*\([^;]*$", t, re.M):
        defined.add(m.group(1))

usable = {k: v for k, v in mapping.items() if v in defined}
missing = {k: v for k, v in mapping.items() if v not in defined}
print("call targets bound:", len(usable))
for k, v in sorted(usable.items()):
    print("   func_%s -> %s" % (k, v))
print("targets not in the tree:", len(missing))
for k, v in sorted(missing.items()):
    print("   func_%s -> %s (still undefined)" % (k, v))

subs = {("func_" + k.lower()): v for k, v in usable.items()}
total = 0
for path in sorted(glob.glob("src/decompiled/*.c")) + sorted(glob.glob("overrides/*.c")):
    t = io.open(path, encoding="utf-8", errors="ignore").read()
    orig = t
    for old, new in subs.items():
        t = re.sub(r"\b" + old + r"\b", new, t)
    if t != orig:
        total += 1
        if apply:
            io.open(path, "w", encoding="utf-8", newline="\n").write(t)
print("files rewritten:", total)
print("mode:", "APPLY" if apply else "dry run")
