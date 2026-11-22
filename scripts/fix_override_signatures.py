"""Align override signatures with the prototypes the export just produced.

An earlier experiment swept `far_t *` -> `far_t far *` across the whole tree,
which also hit the committed override bodies.  The model's own prototype is the
authority, so for every override whose function the header declares with
`far_t *`, rewrite the override's signature the same way.
"""
import glob
import io
import re

hdr = io.open("src/decompiled/st_functions.h", encoding="utf-8",
              errors="ignore").read()
# a function the header declares as returning `far_t *`
near = set()
for line in hdr.split("\n"):
    m = re.match(r"^far_t \*.*?\b([A-Za-z_]\w*)\s*\(", line)
    if m:
        near.add(m.group(1))
print("header says far_t * for", len(near), "functions")

fixed = 0
for path in sorted(glob.glob("overrides/*.c")) + sorted(glob.glob("src/decompiled/*.c")):
    t = io.open(path, encoding="utf-8", errors="ignore").read()
    lines = t.split("\n")
    out = []
    changed = 0
    for i, line in enumerate(lines):
        if "far_t far *" in line:
            # the function name is on this line or the next one
            window = " ".join(lines[i:i + 2])
            m = re.search(r"\b([A-Za-z_]\w*)\s*\(", window)
            name = m.group(1) if m else None
            if name in near:
                line = line.replace("far_t far *", "far_t *")
                changed += 1
        out.append(line)
    if changed:
        io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(out))
        fixed += changed
        print("  %-46s %d" % (path, changed))
print("override signature lines aligned:", fixed)
