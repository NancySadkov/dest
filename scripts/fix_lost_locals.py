"""Make the "no symbol exists" externs real locals.

The exporter sometimes loses a local and the tree compensates with

    extern undefined1 _driveCount;   /* hand fix: no symbol exists for it */

which turns a stack variable into an undefined global.  Each of these is assigned
and read inside exactly one function, so the correct scope is that function:

    _driveCount          setdisk(int drive)
    _resetTextBlitCycle  draw_textTalkwin9Lbm(...)
    _backdropIndex       ovc41_usesBiosKeyAvail(...)

This deletes the extern and declares the variable at the top of its function.  A
name used in more than one function is left alone and reported.

usage: python scripts/fix_lost_locals.py [--apply]
"""
import glob
import io
import re
import sys

apply = "--apply" in sys.argv

DECL = re.compile(r"^\s*extern\s+([A-Za-z_]\w*)\s+([A-Za-z_]\w*)\s*;\s*"
                  r"/\* hand fix: no symbol exists")

converted = 0
skipped = []
for path in sorted(glob.glob("src/decompiled/*.c")):
    lines = io.open(path, encoding="utf-8", errors="ignore").read().split("\n")
    targets = {}
    for i, line in enumerate(lines):
        m = DECL.match(line)
        if m:
            targets[m.group(2)] = (i, m.group(1))
    if not targets:
        continue
    drop = set()
    insert = {}          # anchor line index -> declaration text
    for name, (decl, ty) in targets.items():
        uses = [i for i, l in enumerate(lines)
                if re.search(r"\b" + re.escape(name) + r"\b", l) and i != decl]
        owners = set()
        for u in uses:
            anchor = None
            for k in range(u, 0, -1):
                if re.match(r"^[A-Za-z_].*\)\s*$", lines[k]) and \
                        not lines[k].rstrip().endswith(";"):
                    anchor = k
                    break
            owners.add(anchor)
        if len(owners) != 1 or None in owners:
            skipped.append((path, name, len(owners)))
            continue
        anchor = owners.pop()
        brace = anchor
        while brace < len(lines) and "{" not in lines[brace]:
            brace += 1
        insert.setdefault(brace, []).append(
            "  %s %s;   /* local lost by the decompiler */" % (ty, name))
        drop.add(decl)
        converted += 1
    if not drop:
        continue
    out = []
    for i, line in enumerate(lines):
        if i in drop:
            continue
        out.append(line)
        for extra in insert.get(i, []):
            out.append(extra)
    if apply:
        io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(out))

print("lost locals materialised:", converted)
if skipped:
    print("left alone (multiple functions):", skipped)
print("mode:", "APPLY" if apply else "dry run")
