"""Split the generated globals TU so each file fits Turbo C's 64 KB limit.

Definitions in st_globals.c start at column 0; everything else (wrapped
initialiser continuations) is indented.  Splitting at column-0 lines therefore
never cuts a definition in half, which brace tracking cannot guarantee here
because char initialisers contain brace characters in literals.
"""
import io
import os
import sys

SRC = "src/decompiled/st_globals.c"
LIMIT = int(sys.argv[1]) if len(sys.argv) > 1 else 45000

text = io.open(SRC, encoding="utf-8", errors="ignore").read()
lines = text.split("\n")

head = [l for l in lines if l.startswith("#include") or l.startswith("/*")]
body = [l for l in lines if not (l.startswith("#include") or l.startswith("/*"))]

starts = [i for i, l in enumerate(body) if l and l[0] not in " \t"]
if not starts:
    print("no definitions found")
    raise SystemExit(0)

chunks = [[], []]
idx = 0
size = 0
for i, l in enumerate(body):
    if i in starts and size + len(l) > LIMIT and idx == 0:
        idx = 1
        size = 0
    chunks[idx].append(l)
    size += len(l) + 1

if not chunks[1]:
    print("globals fit in one TU, nothing to split")
    raise SystemExit(0)

base = "\n".join(head) + "\n"
io.open(SRC, "w", encoding="utf-8", newline="\n").write(base + "\n".join(chunks[0]) + "\n")
out2 = os.path.join(os.path.dirname(SRC), "st_globals2.c")
io.open(out2, "w", encoding="utf-8", newline="\n").write(base + "\n".join(chunks[1]) + "\n")
print("split globals: part1 %d bytes, part2 %d bytes"
      % (len("\n".join(chunks[0])), len("\n".join(chunks[1]))))
