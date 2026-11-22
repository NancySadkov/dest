"""Replace Ghidra's placeholder integer types with the concrete C types.

`undefined2` and `undefined4` are the decompiler's "unknown 2/4-byte integer"
placeholders.  st_types.h already defines them as `unsigned int` and
`unsigned long`, so renaming them to `uint16_t` / `uint32_t` changes nothing in
size, signedness or code generation - it only removes the placeholder from the
recovered source (AGENTS.md section 5 greps `undefined[24]`).

The typedefs themselves live in st_types.h, which is not touched.

usage: python scripts/fix_undefined_types.py [--apply]
"""
import glob
import io
import sys

apply = "--apply" in sys.argv
files = sorted(glob.glob("src/decompiled/*.c")) + sorted(glob.glob("src/decompiled/*.h"))
files += sorted(glob.glob("overrides/*.c"))
files = [f for f in files if not f.endswith(("st_types.h", "st_compat.h"))]

total = 0
for path in files:
    t = io.open(path, encoding="latin-1").read()
    n = t.count("undefined2") + t.count("undefined4")
    if not n:
        continue
    t = t.replace("undefined2", "uint16_t").replace("undefined4", "uint32_t")
    total += n
    print("  %-46s %d" % (path, n))
    if apply:
        io.open(path, "w", encoding="latin-1", newline="\n").write(t)
print("undefined2/undefined4 occurrences:", total, "(applied)" if apply else "(dry run)")
