"""Split the game's resident helpers out of the recovered CRT.

doc/step6_crt_experiments.md section 6 measured the exact set: linking without
CRTL.OBJ leaves 29 symbols, all of them defined in crtl.c.  The EMS/XMS/audio/
rand8/i-o-error helpers are game support code (they sit in the original's CRT
segment 1000:026c..1000:07e7), the rest are long-math/sprintf/atol helpers the
original also had in that segment.  This script copies their definitions into a
resident module of their own, so the build no longer needs all of crtl.c.

Usage: python scripts/split_rthelp.py            (recreate rthelp.c)
       then build with crtl.c in build_skip.txt and link.
"""
import io
import os
import re

SRC = "src/decompiled/crtl.c"
OUT = "src/decompiled/rthelp.c"

# the 29 names the link reports, plus the in-file helpers they call
NAMES = [
    "audio_init", "audio_done",
    "xms_init", "xms_usesXmsHandle", "xms_usesXmsHandle2", "xmsFree",
    "stshInit_scan",
    "ems_init", "ems_memmove1", "ems_memmove2", "emsFree", "ems_realloc",
    "rand8", "srand8",
    "ioErrorHndlrInstall", "ioErrorHndlrUninstall",
    "LXMUL_at_", "F_SCOPY", "LDIV_at_", "LUDIV_at_", "LMOD_at_",
    "LXLSH_at_", "LXRSH_at_", "LXURSH_at_", "PADD_at_",
    "_FakRealCvt", "__fstrncpy",
    # helpers those functions call (all defined in crtl.c as well)
    "N_LDIV_at_", "N_LUDIV_at_", "N_LMOD_at_", "N_LXLSH_at_",
    "N_LXRSH_at_", "N_LXURSH_at_", "N_PADD_at_", "N_LXMUL_at_", "sub1_at__at_",
]


def find_def(lines, name):
    # a definition's name may sit on its own continuation line:
    #   void __cdecl16far
    #   ems_memmove1(...)
    for i, l in enumerate(lines):
        if re.match(r"^[A-Za-z_].*\b" + re.escape(name) + r"\s*\(", l):
            return i
    for i, l in enumerate(lines):
        if re.match(r"^\s*" + re.escape(name) + r"\s*\(", l):
            return i
    return None


def fn_end(lines, start):
    depth = 0
    started = False
    for k in range(start, len(lines)):
        depth += lines[k].count("{") - lines[k].count("}")
        if "{" in lines[k]:
            started = True
        if started and depth == 0:
            return k
    return None


lines = io.open(SRC, encoding="latin-1").read().split("\n")
blocks = []
missing = []
for name in NAMES:
    s = find_def(lines, name)
    if s is None:
        missing.append(name)
        continue
    e = fn_end(lines, s)
    # include a leading comment block and a return type that sits on its own
    # line (the export wraps long signatures as "void __cdecl16far\nname(...)")
    first = s
    while first > 0:
        prev = lines[first - 1].strip()
        if prev.startswith("/*") or prev.startswith("*"):
            first -= 1
            continue
        if re.match(r"^[A-Za-z_][\w \*]*__cdecl16(near|far)$", prev):
            first -= 1
            continue
        break
    blocks.append("\n".join(lines[first:e + 1]).rstrip())

hdr = """/* Resident helpers split out of the recovered CRT (see
   doc/step6_crt_experiments.md section 6).

   These functions were part of the original's CRT segment (1000:026c ..
   1000:07e7) but they are not Borland runtime: the EMS/XMS/audio/sound-driver
   helpers, the rand8 generator, the i-o error handler and the long-math /
   sprintf / atol helpers the game used.  Keeping them here means the build no
   longer needs the whole recovered crtl.c, so CM.LIB can own the runtime.

   Bodies are copied verbatim from crtl.c, which is the recovered original. */

#include "recovered.h"

"""
body = hdr + "\n\n".join(blocks) + "\n"
# the floating-point trap handler aborts; CM.LIB provides abort()
body = body.replace("_abort();", "abort();")
io.open(OUT, "w", encoding="latin-1", newline="\n").write(body)
print("rthelp.c: %d functions, %d lines" % (len(blocks),
                                             len((hdr + "\n\n".join(blocks)).split("\n"))))
if missing:
    print("not found in crtl.c:", ", ".join(missing))

# crtl.c leaves the build; OVL.OBJ is already excluded by the linker
skip = io.open("scripts/model/build_skip.txt", encoding="utf-8").read()
if "crtl.c" not in skip:
    skip = skip.rstrip("\n") + ("\n# crtl.c is the Borland runtime, recovered from the original image.\n"
                                "# Its game-side helpers now live in rthelp.c; the runtime itself is\n"
                                "# CM.LIB's (the toolchain's own), so crtl.c is not built.\ncrtl.c\n")
    io.open("scripts/model/build_skip.txt", "w", encoding="utf-8", newline="\n").write(skip)
    print("build_skip: crtl.c excluded")
