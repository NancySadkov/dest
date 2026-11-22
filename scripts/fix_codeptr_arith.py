"""Pointer arithmetic on a function type is not allowed.

The decompiler emits

    *(int *)((code *)init_textFilename + unaff_BP) = iVar2;

`code` is `unsigned short code()` - a function type, so `sizeof` is unknown and
Turbo C stops with "Size of the type is unknown or zero".  The original adds a
byte offset to an address, so the cast must be `char *`.

Only the arithmetic form is rewritten; `(code *)x` casts that are later *called*
must stay, and a blanket replacement breaks them (that mistake produced 32
compile errors once).

usage: python scripts/fix_codeptr_arith.py [--apply]
"""
import glob
import io
import re
import sys

apply = "--apply" in sys.argv
PAT = re.compile(r"\(\s*code\s*\*\s*\)(\s*[A-Za-z_]\w*\s*)\+")

total = 0
files = 0
for path in sorted(glob.glob("src/decompiled/*.c")):
    t = io.open(path, encoding="utf-8", errors="ignore").read()
    new, n = PAT.subn(lambda m: "(char *)" + m.group(1) + "+", t)
    if n:
        total += n
        files += 1
        if apply:
            io.open(path, "w", encoding="utf-8", newline="\n").write(new)

print("(code *)name + arithmetic rewritten:", total, "in", files, "files")
print("mode:", "APPLY" if apply else "dry run")
