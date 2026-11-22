#!/usr/bin/env python3
"""Create a DOS/TC30-friendly staging tree with 8.3 filenames.

src/decompiled uses long, descriptive filenames; DOS 3.0's compiler only sees
8.3 names.  This script copies the tree to tmp/buildsrc with short names and
rewrites the single local include (recovered.h -> st.h).
"""
import os
import re
import shutil

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "src", "decompiled")
OUT = os.path.join(ROOT, "tmp", "buildsrc")

HEADERS = {
    "st_compat.h": "compat.h",
    "st_types.h": "types.h",
    "st_globals.h": "glob.h",
    "st_artifacts.h": "art.h",
    "st_functions.h": "func.h",
    "st_intrinsics.h": "intrin.h",
}

def short_module(name):
    m = re.match(r"st_globals(\d*)\.c$", name)
    if m:
        return "glob%s.c" % (m.group(1) or "")
    if name == "ovr_stubs.c":
        return "ovrstub.c"
    if name == "st_intrinsics.c":
        return "intrins.c"
    if name in ("crtl.c", "main.c", "mouse.c", "video.c", "ovl.c"):
        return name
    m = re.match(r"ovc(\d+).*\.c$", name)
    if m:
        return "o%s.c" % m.group(1)
    return re.sub(r"[^A-Za-z0-9_.]", "_", name)

def main():
    if os.path.isdir(OUT):
        shutil.rmtree(OUT)
    os.makedirs(OUT)
    mapping = {}
    for src, dst in HEADERS.items():
        shutil.copyfile(os.path.join(SRC, src), os.path.join(OUT, dst))
    asm = os.path.join(SRC, "ovr_thunks.asm")
    if os.path.isfile(asm):
        shutil.copyfile(asm, os.path.join(OUT, "ovr.asm"))
    with open(os.path.join(OUT, "st.h"), "w", encoding="ascii") as f:
        f.write("/* DOS/TC30 staging aggregate header. */\n")
        f.write("#ifndef ST_AGGREGATE_H\n#define ST_AGGREGATE_H\n")
        for dst in ("compat.h", "types.h", "intrin.h", "glob.h", "art.h", "func.h"):
            f.write('#include "%s"\n' % dst)
        f.write("#endif\n")
    for name in sorted(os.listdir(SRC)):
        if not name.endswith(".c"):
            continue
        short = short_module(name)
        mapping[short] = name
        with open(os.path.join(SRC, name), "r", encoding="utf-8", errors="replace") as f:
            s = f.read()
        s = s.replace('#include "recovered.h"', '#include "st.h"')
        # each module gets its own code segment (far code model): the recovered
        # program is ~250 KB of code, far more than one 64 KB segment can hold
        seg = re.sub(r"[^A-Za-z0-9_]", "_", short.rsplit(".", 1)[0]).upper()
        s = s.replace('#include "st.h"', '#include "st.h"\n#pragma codeseg %s_SEG' % seg, 1)
        with open(os.path.join(OUT, short), "w", encoding="ascii", errors="replace") as f:
            f.write(s)
    with open(os.path.join(OUT, "MAP.TXT"), "w", encoding="ascii") as f:
        for s in sorted(mapping, key=lambda x: (len(x), x)):
            f.write("%-12s %s\n" % (s, mapping[s]))
    print("staged %d modules in %s" % (len(mapping), OUT))
    for s in sorted(mapping, key=lambda x: (len(x), x)):
        print("  %-12s %s" % (s, mapping[s]))

if __name__ == "__main__":
    main()
