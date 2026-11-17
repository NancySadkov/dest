#!/usr/bin/env python3
"""Update one recovered function's parameter list across the tree.

The call sites are the evidence for a function's real parameters; when the
Ghidra prototype disagrees, this script rewrites the declaration in funcs.h and
the definition in its module so the tree keeps compiling.  Calls are left
alone: only lines carrying a calling convention or a definition body are
touched.

Usage:
  python scripts/fbov/set_proto.py NAME "void"
  python scripts/fbov/set_proto.py NAME "int mode,char *path"
  python scripts/fbov/set_proto.py NAME "void" --return int
"""
import argparse
import glob
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC = os.path.join(ROOT, "src")
CC = re.compile(r"__(?:cdecl|stdcall|pascal)16(?:near|far)")


def params_decl(text):
    """Turn a parameter list into named declarations, numbering unnamed ones."""
    text = text.strip()
    if text in ("", "void"):
        return "void"
    out = []
    for i, part in enumerate([p.strip() for p in text.split(",") if p.strip()]):
        words = part.split()
        if len(words) == 1:
            out.append("%s param_%d" % (part, i + 1))
        else:
            out.append(part)
    return ",".join(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("name")
    ap.add_argument("params", help='"void" or a C parameter list')
    ap.add_argument("--return", dest="ret", default=None)
    ap.add_argument("--dir", default=SRC)
    a = ap.parse_args()
    params = params_decl(a.params)

    pat = re.compile(r"\b(%s)\s*\(([^()]*)\)" % re.escape(a.name))
    hits = 0
    for path in [os.path.join(a.dir, "funcs.h")] + \
            sorted(glob.glob(os.path.join(a.dir, "*.c"))):
        s = io.open(path, encoding="latin1").read()
        lines = s.splitlines(True)
        changed = False
        for i, line in enumerate(lines):
            if not CC.search(line):
                continue
            m = pat.search(line)
            if not m:
                continue
            new = line[:m.start()] + m.group(1) + "(" + params + ")" + line[m.end():]
            if a.ret:
                head = new[:new.index(m.group(1))]
                head = re.sub(r"[A-Za-z_][\w \t\*]*\s*$", "", head, count=1)
                new = head + a.ret + " " + new[new.index(m.group(1)):]
            if new != line:
                lines[i] = new
                changed = True
                hits += 1
        if changed:
            io.open(path, "w", encoding="latin1", newline="\n").write("".join(lines))
            print("updated", os.path.relpath(path, ROOT))
    if not hits:
        print("no prototype for", a.name)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
