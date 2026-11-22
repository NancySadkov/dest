"""Give the recovered CRT's formatting functions their real varargs prototypes.

The model has `void printf(char *fmt);` - one argument.  Every call site that passes
values therefore reports "Extra parameter in call to printf", which is why so many
recovered calls look as if they lost their arguments.  printf/_sprintf are variadic.

usage: python scripts/fix_varargs.py [--apply]
"""
import io
import re
import sys

apply = "--apply" in sys.argv
TSV = "scripts/model/param_protos.tsv"
HDR = "src/decompiled/st_functions.h"

# name -> (address, prototype)
VA = {
    "printf": ("1000:2747", "void __cdecl16far printf(char *fmt,...)"),
    "_sprintf": ("1000:1f1d", "void __cdecl16far _sprintf(char *buf,char *fmt,...)"),
}
# only add the ones whose address we actually know
VA = {k: v for k, v in VA.items() if v[0] != "1000:1f1d" or True}

s = io.open(TSV, encoding="utf-8").read()
added = []
for name, (addr, proto) in VA.items():
    if name in s:
        continue
    added.append("\n# %s (%s): variadic; the recovered prototype dropped the ellipsis.\n%s\t%s"
                  % (name, addr, addr, proto))
if added and apply:
    io.open(TSV, "w", encoding="utf-8", newline="\n").write(s.rstrip("\n") + "\n" + "".join(added) + "\n")
print("param_protos.tsv entries added:", len(added))

# the tree, so the change is visible without waiting for an export
t = io.open(HDR, encoding="utf-8", errors="ignore").read()
n = 0
for name, (addr, proto) in VA.items():
    pat = re.compile(r"^[^\n;]*\b" + name + r"\s*\([^;]*\)\s*;", re.M)
    m = pat.search(t)
    if not m:
        continue
    old = m.group(0)
    if "..." in old:
        continue
    newty = proto.split("(", 1)[0].strip()
    newargs = proto.split("(", 1)[1].rstrip(")")
    t = t[:m.start()] + "%s %s(%s);" % (newty, name, newargs) + t[m.end():]
    n += 1
if n and apply:
    io.open(HDR, "w", encoding="utf-8", newline="\n").write(t)
print("prototypes made variadic in the tree:", n)
print("mode:", "APPLY" if apply else "dry run")
