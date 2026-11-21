"""Compress runs of identical consecutive statements into a counted loop.

The decompiler occasionally unrolls a loop into thousands of copies of the same
statement (o02's draw_textTalkwin9Lbm has 3182 copies of
`pcVar33[(int)unaff_SI] = pcVar33[(int)unaff_SI] + bVar29;`), which pushes the
function past Turbo C's table limit.

Executing the same statement N times in a row is exactly a loop of N iterations,
so the run is replaced by one.  Order and side effects are unchanged.

usage: python scripts/compress_repeats.py <file-or-dir> [min_run] [--apply]
"""
import glob
import io
import os
import sys

target = sys.argv[1]
min_run = 8
apply = "--apply" in sys.argv
for a in sys.argv[2:]:
    if a.isdigit():
        min_run = int(a)

if os.path.isdir(target):
    files = sorted(glob.glob(os.path.join(target, "*.c")))
else:
    files = [target]

CONTROL = ("if", "for", "while", "switch", "else", "case", "default", "do")

total = 0
for path in files:
    lines = io.open(path, encoding="utf-8", errors="ignore").read().split("\n")
    out = []
    i = 0
    nrun = 0
    while i < len(lines):
        s = lines[i].strip()
        # only complete statements: continuation lines of a global initialiser are
        # indented and can repeat verbatim, and wrapping those in a loop breaks the
        # initialiser
        if (not s or not s.endswith(";") or s in ("{", "};") or s == "}"
                or s.split(" ")[0].rstrip("(") in CONTROL):
            out.append(lines[i])
            i += 1
            continue
        j = i + 1
        while j < len(lines) and lines[j].strip() == s:
            j += 1
        n = j - i
        if n >= min_run:
            indent = lines[i][:len(lines[i]) - len(lines[i].lstrip())]
            out.append("%s{ int _rep%d; for (_rep%d = 0; _rep%d < %d; _rep%d++)"
                       % (indent, nrun, nrun, nrun, n, nrun))
            out.append("%s    %s" % (indent, s))
            out.append("%s}" % indent)
            nrun += 1
            total += 1
            i = j
            continue
        out.append(lines[i])
        i += 1
    if nrun and apply:
        io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(out))

print("runs compressed:", total)
print("mode:", "APPLY" if apply else "dry run")
