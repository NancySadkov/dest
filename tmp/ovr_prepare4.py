"""Call the VROOMM prepare routine by its public symbol.

C0 runs `__OvrPrepare` before the C library init (tools/devroomm/src/ovrman.c).
The public symbol is `__OVRPREPARE`, so the C name is `_OVRPREPARE` - the earlier
attempts used a hand-computed address inside _OVRTEXT_ that was not the routine.

usage: python tmp/ovr_prepare4.py [--revert]
"""
import io
import os
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
SRC = os.path.join(ROOT, "src", "decompiled", "crtl.c")

if "--revert" in sys.argv:
    subprocess.run(["git", "checkout", "--", SRC], cwd=ROOT, check=False)
    print("reverted")
    raise SystemExit

t = io.open(SRC, encoding="latin-1").read()
if "_OVRPREPARE" not in t:
    t = t.replace('#include "recovered.h"',
                  '#include "recovered.h"\n\nvoid _OVRPREPARE(void);', 1)
    a = "  /* __setargv is not recovered yet"
    call = ("  /* VROOMM: C0 runs __OvrPrepare before the C library init.  The public\n"
            "     symbol is __OVRPREPARE, so the C name is _OVRPREPARE. */\n"
            "  _OVRPREPARE();\n\n")
    t = t.replace(a, call + a, 1)
    io.open(SRC, "w", encoding="latin-1", newline="\n").write(t)
    print("prepare call inserted")

subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "build_standalone.py"),
                "--wait", "3000"], stdout=subprocess.DEVNULL)
rows = [l.rstrip("\n").split("\t")
        for l in io.open(os.path.join(ROOT, "tmp", "build_report.tsv"), encoding="utf-8")][1:]
print("clean %d errors %d" % (sum(1 for r in rows if r[1] == "ok"),
                              sum(int(r[2]) for r in rows)))
for r in rows:
    if r[1] != "ok":
        print(" ", r[0], r[4][:110])
subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "link_standalone.py")],
               stdout=subprocess.DEVNULL)
subprocess.run([sys.executable, os.path.join(ROOT, "tmp", "exact_code.py")],
               stdout=subprocess.DEVNULL)
d = open(os.path.join(ROOT, "tmp", "runcode", "RUN.LOG"), "rb").read()
first = [l for l in d.splitlines() if l.startswith(b"CODE=")]
print("_OVRPREPARE() ->", first[0].decode() if first else "no code (hang)")
print("STRONG.SAV", os.path.exists(os.path.join(ROOT, "tmp", "runcode", "STRONG.SAV")))
