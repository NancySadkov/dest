"""Hoist C89-illegal declarations to the top of their block.

Turbo C 2.0 requires every declaration of a block to precede its statements, so
Ghidra's habit of declaring a temporary where it is first needed produces
"Declaration is not allowed here".  A declaration with an initializer is split:

    stmt;
    int x = f();        ->     int x;          (at the top of the block)
    stmt;
                               x = f();        (in place, same order)

which preserves evaluation order and scope exactly.

usage: python scripts/hoist_decls.py <mod> <sourcefile.c> [dry]
"""
import io
import os
import re
import sys

mod = sys.argv[1]
srcname = sys.argv[2]
dry = "dry" in sys.argv[3:]
SRC = "src/decompiled/" + srcname

log_path = "tmp/buildsrc/%s.log" % mod
if not os.path.isfile(log_path):
    for f in os.listdir("tmp/buildsrc"):
        if f.lower() == mod.lower() + ".log":
            log_path = "tmp/buildsrc/" + f
            break
log = io.open(log_path, encoding="ascii", errors="replace").read()

targets = []
for e in log.splitlines():
    m = re.search(r"Error \w+\.c (\d+): (.*?) in function (\w+)", e.strip())
    if m and m.group(2) == "Declaration is not allowed here":
        targets.append((int(m.group(1)), m.group(3)))
print("declaration errors:", len(targets))

lines = io.open(SRC, encoding="utf-8", errors="ignore").read().split("\n")


def no_strings(line):
    out = []
    q = None
    i = 0
    while i < len(line):
        ch = line[i]
        if q:
            if ch == "\\":
                i += 2
                continue
            if ch == q:
                q = None
            i += 1
            continue
        if ch in "\"'":
            q = ch
            i += 1
            continue
        out.append(ch)
        i += 1
    return "".join(out)


def depths(text_lines):
    d = 0
    out = []
    for l in text_lines:
        out.append(d)
        for ch in no_strings(l):
            if ch == "{":
                d += 1
            elif ch == "}":
                d -= 1
    return out


DECL = re.compile(r"^(\s+)([A-Za-z_][\w \t\*]*?)\s+(\*?[A-Za-z_]\w*)"
                  r"(\s*=\s*(.+))?;\s*$")

hoisted = 0
skipped = 0
# walk bottom-up so earlier line numbers stay valid
for n, fn in sorted(targets, reverse=True):
    line = lines[n - 1]
    m = DECL.match(line)
    if not m:
        skipped += 1
        print("  SKIP not a simple declaration:", line.strip()[:60])
        continue
    indent, ty, name, init = m.group(1), m.group(2), m.group(3), m.group(4)
    bare = "%s%s %s;" % (indent, ty, name)
    if init:
        # split: declare at the top, assign in place
        rhs = m.group(5)
        lines[n - 1] = "%s%s = %s;" % (indent, name, rhs)
        decl = bare
    else:
        decl = bare
        lines[n - 1] = ""
    # find the enclosing block: the nearest line above whose depth is one less
    d = depths(lines)
    target_depth = d[n - 1]
    ins = None
    for k in range(n - 1, -1, -1):
        if d[k] < target_depth:
            ins = k
            break
    if ins is None:
        skipped += 1
        print("  SKIP no enclosing block at", n)
        continue
    lines.insert(ins + 1, decl)
    hoisted += 1

print("hoisted:", hoisted, "skipped:", skipped)
if dry:
    raise SystemExit(0)

text = "\n".join(lines)
io.open(SRC, "w", encoding="utf-8", newline="\n").write(text)
print("wrote", SRC)
