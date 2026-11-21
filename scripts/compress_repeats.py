"""Compress runs of identical consecutive statements into a counted loop.

The decompiler occasionally unrolls a loop into thousands of copies of the same
statement (o02's draw_textTalkwin9Lbm has 3182 copies of
`pcVar33[(int)unaff_SI] = pcVar33[(int)unaff_SI] + bVar29;`), which pushes the
function past Turbo C's table limit.

Executing the same statement N times in a row is exactly a loop of N iterations,
so the run is replaced by one.  Order and side effects are unchanged.

usage: python scripts/compress_repeats.py <source.c> [min_run] [--apply]
"""
import io
import re
import sys

path = sys.argv[1]
min_run = int(sys.argv[2]) if len(sys.argv) > 2 and sys.argv[2].isdigit() else 8
apply = "--apply" in sys.argv

lines = io.open(path, encoding="utf-8", errors="ignore").read().split("\n")

out = []
i = 0
compressed = 0
while i < len(lines):
    s = lines[i].strip()
    if not s or s in ("{", "}", "};") or s.startswith(("if", "for", "while", "switch", "else", "case", "default")):
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
                   % (indent, compressed, compressed, compressed, n, compressed))
        out.append("%s    %s" % (indent, s))
        out.append("%s}" % indent)
        compressed += 1
        i = j
        continue
    out.append(lines[i])
    i += 1

print("runs compressed:", compressed)
if apply:
    io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(out))
    print("mode: APPLY")
else:
    print("mode: dry run")
