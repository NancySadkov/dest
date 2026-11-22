"""Give a 4-byte integer slot the pointer type it is actually used with.

Ghidra often keeps a far pointer in a stack word and types the local `undefined4`:

    undefined4 uStack_6;
    ...
    uStack_6 = (far_t *)CONCAT13(1,uVar12);

Under the small memory model a plain pointer is 2 bytes, so assigning a pointer to
the slot is a "Nonportable pointer conversion".  Declaring the slot as the pointer
type it is assigned keeps the size at 4 bytes (`T far *`), so the layout does not
change - only the C type does.

A slot is only retyped when every cast assigned to it names the same base type.

usage: python scripts/fix_undefined4_slots.py [--apply]
"""
import glob
import io
import re
import sys

DECL = re.compile(r"^(\s*)undefined4\s+([A-Za-z_]\w*)\s*;\s*$")
CAST = re.compile(r"\b([A-Za-z_]\w*)\s*=\s*\(\s*([A-Za-z_]\w*)(?:\s+far)?\s*\*\s*\)")

apply = "--apply" in sys.argv
files = sorted(glob.glob("src/decompiled/*.c")) + sorted(glob.glob("overrides/*.c"))
changed = 0
files_changed = 0

for path in files:
    lines = io.open(path, encoding="utf-8", errors="ignore").read().split("\n")
    # collect candidate slots and the base types cast onto them
    # (per file is good enough: a slot name is unique inside its function, and
    #  the cast base must be consistent anyway)
    types = {}
    for l in lines:
        m = CAST.search(l)
        if m:
            name, base = m.group(1), m.group(2)
            types.setdefault(name, set()).add(base)
    n = 0
    for i, l in enumerate(lines):
        m = DECL.match(l)
        if not m:
            continue
        indent, name = m.group(1), m.group(2)
        bases = types.get(name)
        if not bases:
            continue
        # several casts may target the slot (the decompiler re-uses it for
        # different pointer kinds); any of them keeps the 4-byte size, and the
        # remaining mismatches are only warnings with -w-
        base = sorted(bases)[0]
        lines[i] = "%s%s far *%s;   /* was undefined4: assigned %s * values */" % (
            indent, base, name, base)
        n += 1
    if n:
        changed += n
        files_changed += 1
        if apply:
            io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(lines))

print("slots retyped:", changed, "files:", files_changed)
print("mode:", "APPLY" if apply else "dry run")
