#!/usr/bin/env python3
"""Post-process the Ghidra export in src/decompiled.

- Rewrites namespace-qualified function names such as
  ``switchD_4000:6835::caseD_0`` into valid C identifiers.
- Generates ``st_artifacts.h`` declaring Ghidra's RAM/register pseudo-variables
  (``uRam000100f8``, ``in_AX``, ``extraout_DH``, ``stack0xfff0``, ...).
- Adds the small compatibility aliases used by the recovered code.
"""
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "src", "decompiled")

NS_RE = re.compile(r"switchD_[0-9a-fA-F]+:[0-9a-fA-F]+::(caseD_[0-9]+)")

def rewrite_names():
    changed = 0
    for name in os.listdir(OUT):
        if not name.endswith((".c", ".h")):
            continue
        path = os.path.join(OUT, name)
        with open(path, "r", encoding="utf-8", errors="replace") as f:
            s = f.read()
        # switchD_SEG:OFF::caseD_N -> switchD_SEG_OFF_caseD_N
        new = re.sub(r"switchD_([0-9a-fA-F]+):([0-9a-fA-F]+)::(caseD_[0-9]+)",
                     r"switchD_\1_\2_\3", s)
        if new != s:
            with open(path, "w", encoding="utf-8") as f:
                f.write(new)
            changed += 1
    return changed

def ident_type(name):
    if name.startswith("stack0x"):
        return "undefined1"
    if name.startswith("puRam"):
        return "undefined2 *"
    if name.startswith("pcRam"):
        return "char *"
    if name.startswith("pRam"):
        return "undefined1 *"
    if name.startswith("uRam"):
        return "undefined2"
    if name.startswith("iRam"):
        return "int16_t"
    if name.startswith("cRam"):
        return "char"
    if name.startswith(("in_", "unaff_", "extraout_", "out_")):
        suf = name.split("_", 1)[1]
        if suf in ("CF", "ZF", "SF", "OF", "AF", "PF", "IF", "TF", "DF", "NT"):
            return "uint8_t"
        if suf in ("AL", "AH", "BL", "BH", "CL", "CH", "DL", "DH", "AX8", "BX8", "CX8", "DX8"):
            return "uint8_t"
        if suf.startswith(("E",)):
            return "uint32_t"
        return "uint16_t"
    return None

def generate_artifacts():
    ids = set()
    pat = re.compile(r"\b((?:p?[uic]?Ram[0-9a-fA-F]{5,8})|(?:stack0x[0-9a-fA-F]+)|(?:in_[A-Za-z0-9_]+)|(?:unaff_[A-Za-z0-9_]+)|(?:extraout_[A-Za-z0-9_]+)|(?:out_[A-Za-z0-9_]+))\b")
    for name in os.listdir(OUT):
        if not name.endswith(".c"):
            continue
        with open(os.path.join(OUT, name), "r", encoding="utf-8", errors="replace") as f:
            ids.update(pat.findall(f.read()))
    path = os.path.join(OUT, "st_artifacts.h")
    with open(path, "w", encoding="utf-8") as f:
        f.write("/* Declarations for Ghidra decompiler RAM/register pseudo-variables. */\n")
        f.write("#ifndef ST_ARTIFACTS_H\n#define ST_ARTIFACTS_H\n")
        for i in sorted(ids):
            t = ident_type(i)
            if t:
                f.write("extern %s %s;\n" % (t, i))
        f.write("#endif\n")
    return len(ids)

def patch_headers():
    rec = os.path.join(OUT, "recovered.h")
    with open(rec, "r", encoding="utf-8") as f:
        s = f.read()
    if "st_artifacts.h" not in s:
        s = s.replace('#include "st_globals.h"',
                      '#include "st_globals.h"\n#include "st_artifacts.h"')
        with open(rec, "w", encoding="utf-8") as f:
            f.write(s)

    compat = os.path.join(OUT, "st_compat.h")
    with open(compat, "r", encoding="utf-8") as f:
        s = f.read()
    extra = []
    if "#define true" not in s:
        extra.append("#ifndef true\n#define true 1\n#define false 0\n#endif")
    if "#define _argv" not in s:
        extra.append("/* Borland's @-suffixed startup symbols. */")
        extra.append("#define _argv ((str_t *)_argv_at_)")
        extra.append("#define _argc ((int)_argc_at_)")
        extra.append("#define _envseg _envseg_at_")
        extra.append("#define _envSize _envSize_at_")
        extra.append("#define bdata bdata_at_")
        extra.append("#define DGROUP_ DGROUP_at__at_")
    if extra:
        # insert before the final #endif
        idx = s.rfind("#endif")
        s = s[:idx] + "\n".join(extra) + "\n" + s[idx:]
        with open(compat, "w", encoding="utf-8") as f:
            f.write(s)

if __name__ == "__main__":
    if not os.path.isdir(OUT):
        print("missing", OUT)
        sys.exit(1)
    n = rewrite_names()
    a = generate_artifacts()
    patch_headers()
    print("rewrote files:", n, "artifact declarations:", a)
