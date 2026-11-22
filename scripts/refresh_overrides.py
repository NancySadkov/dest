"""Refresh every override body from the current tree.

The overrides in overrides/ are durable copies of recovered function bodies.  The
tree is the source of truth: later pipeline sweeps (fix_stack_slots, the typed
field rewrites, the name passes) change the tree, and an override written before
such a sweep keeps the old text - which is why 20 overrides still contain
`stack0x...` addresses that the tree no longer has.

For each overrides/<mod>__<fn>.c this copies the function body out of
src/decompiled/<mod>.c, keeping the override's leading /* ... */ comment.

usage: python scripts/refresh_overrides.py [--apply]
"""
import glob
import io
import os
import re
import sys

apply = "--apply" in sys.argv
changed = 0
stale = []

for ovr in sorted(glob.glob("overrides/*.c")):
    base = os.path.basename(ovr)[:-2]            # <mod>__<fn>
    if "__" not in base:
        continue
    mod, fn = base.split("__", 1)
    src = os.path.join("src/decompiled", mod + ".c")
    if not os.path.isfile(src):
        continue
    text = io.open(src, encoding="latin-1", errors="ignore").read()
    lines = text.split("\n")
    # find the definition (skip prototypes)
    start = None
    for i, l in enumerate(lines):
        if re.match(r"^[A-Za-z_].*\b" + re.escape(fn) + r"\s*\(", l) and not l.rstrip().endswith(";"):
            start = i
            break
    if start is None:
        # the export sometimes writes "type\nname\n        (args)"
        for i, l in enumerate(lines):
            if re.match(r"^\s*" + re.escape(fn) + r"\s*$", l):
                start = i
                break
    if start is None:
        continue
    depth = 0
    started = False
    end = len(lines) - 1
    for k in range(start, len(lines)):
        depth += lines[k].count("{") - lines[k].count("}")
        if "{" in lines[k]:
            started = True
        if started and depth == 0:
            end = k
            break
    body = "\n".join(lines[start:end + 1]).rstrip()

    old = io.open(ovr, encoding="latin-1", errors="ignore").read()
    # keep the leading comment block of the override, if any
    m = re.match(r"^\s*/\*.*?\*/\s*", old, re.S)
    head = m.group(0).rstrip() + "\n" if m else ""
    new = head + body + "\n"
    if new == old:
        continue
    if "stack0x" in old and "stack0x" not in new:
        stale.append(ovr)
    changed += 1
    print("  refresh %-46s %s" % (os.path.basename(ovr),
                                  "(drops stack0x)" if ovr in stale else ""))
    if apply:
        io.open(ovr, "w", encoding="latin-1", newline="\n").write(new)

print("overrides refreshed:", changed, "of which drop stack0x:", len(stale))
if not apply:
    print("dry run; pass --apply to write")
