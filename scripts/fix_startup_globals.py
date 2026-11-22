"""Withhold the data definitions the C runtime startup already provides.

TLINK reports

    Error: ___BRKLVL defined in module C0.ASM is duplicated in module GLOB4.C
    Error: __PSP    defined in module C0.ASM is duplicated in module GLOB4.C

because the recovered globals define variables that C0.ASM owns.  The startup's
copies are the ones the runtime initialises, so ours must go - but the CRT still
*references* them, so the declarations stay (as externs).

usage: python scripts/fix_startup_globals.py [--apply]
"""
import glob
import io
import re
import sys

apply = "--apply" in sys.argv
HEADER = "src/decompiled/st_globals.h"

# C names the startup owns (C0.ASM: ___BRKLVL, __PSP, __HEAPBASE, __HEAPTOP,
# __STARTTIME, _ERRNO, _MUSHANDLE ...).
OWNED = {
    "__brklvl", "_brklvl", "brklvl", "_psp", "psp", "_pspseg",
    "_heapbase", "_heaptop", "_brklvl", "errno", "_doserrno", "_StartTime",
    "MUSHandle", "_MUSHandle", "__heapbase", "__heaptop", "__brklvl",
}

decl = re.compile(r"^([A-Za-z_][\w ]*?)[\s\*]([A-Za-z_]\w*)\s*((?:\[[^\]]*\])*)\s*(=|;)")

need = {}          # name -> "type name dims"
removed = 0
for path in sorted(glob.glob("src/decompiled/st_globals*.c")):
    lines = io.open(path, encoding="utf-8", errors="ignore").read().split("\n")
    keep = []
    n = 0
    for line in lines:
        m = decl.match(line)
        if m and m.group(2) in OWNED:
            need[m.group(2)] = "%s %s%s" % (m.group(1).strip(), m.group(2), m.group(3))
            keep.append("/* %s: supplied by the C runtime startup. */" % m.group(2))
            n += 1
            continue
        keep.append(line)
    if n:
        removed += n
        if apply:
            io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(keep))
    if n:
        print("  %-34s %d definitions withheld" % (path.split("/")[-1], n))

print("definitions withheld:", removed)

# make sure the header declares the ones the CRT uses
hdr = io.open(HEADER, encoding="utf-8", errors="ignore").read().split("\n")
present = set(re.findall(r"^extern\s+[A-Za-z_][\w ]*?[\s\*]([A-Za-z_]\w*)\s*(?:\[|;)", "\n".join(hdr), re.M))
# variables the CRT uses that were never defined in the recovered globals at all
EXTERN_ONLY = {"_brklvl": "far_t", "_heaptop": "far_t", "_heapbase": "far_t"}
want = [n for n in need if n in ("_psp", "__brklvl", "brklvl", "psp")]
for name, ty in EXTERN_ONLY.items():
    if name not in present and name not in want:
        need[name] = "%s %s" % (ty, name)
        want.append(name)
added = 0
for name in sorted(want):
    if name in present:
        continue
    hdr.append("extern %s;   /* supplied by the startup */" % need[name])
    added += 1
if apply and added:
    io.open(HEADER, "w", encoding="utf-8", newline="\n").write("\n".join(hdr))
print("externs (re)added:", added)
print("mode:", "APPLY" if apply else "dry run")
