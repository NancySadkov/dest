"""Drop the spurious `...` from functions whose call sites never pass more
arguments than the named parameters.

Exact, because the call-site analysis (scripts/param_infer.py) shows every call
supplies at most the named parameters; a cdecl callee cannot be relying on more.

usage: python scripts/drop_ellipsis.py [--apply]
"""
import glob
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "src", "decompiled")
TSV = os.path.join(ROOT, "scripts", "model", "param_infer.tsv")

apply = "--apply" in sys.argv

rows = [l.rstrip("\n").split("\t") for l in io.open(TSV, encoding="utf-8")
        if not l.startswith("#")]
no_extra = {r[0] for r in rows if len(r) > 4 and r[4] == "no-extra"}

pat = re.compile(r",\s*\.\.\.\s*\)")

changed_files = 0
changed_funcs = 0
for path in glob.glob(os.path.join(SRC, "*.c")) + [os.path.join(SRC, "st_functions.h")]:
    t = io.open(path, encoding="latin-1").read()
    out = []
    pos = 0
    hit = 0
    for m in re.finditer(r"([A-Za-z_]\w*)\s*\([^;{]*\.\.\.[^;{]*\)", t):
        name = m.group(1)
        if name not in no_extra:
            continue
        seg = m.group(0)
        new = pat.sub(")", seg)
        if new == seg:
            continue
        out.append((m.start(), m.end(), new))
        hit += 1
    if not hit:
        continue
    for s, e, new in reversed(out):
        t = t[:s] + new + t[e:]
    changed_files += 1
    changed_funcs += hit
    if apply:
        io.open(path, "w", encoding="latin-1", newline="").write(t)

print("%s: %d functions in %d files" %
      ("changed" if apply else "would change (dry run)", changed_funcs, changed_files))
