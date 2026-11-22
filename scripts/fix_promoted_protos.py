"""Promoted functions were decompiled with parameters their callers do not pass.

"Too few parameters in call to 'SUB_5b66_1d94'" comes from the *prototype* in the
shared header; the definitions stay as they are (their bodies use the parameters).
Declaring the promoted functions with an empty parameter list - C's "unspecified
arguments" - lets every call site through, which is the honest signature for a
call whose arguments the decompiler lost.

usage: python scripts/fix_promoted_protos.py [--apply]
"""
import glob
import io
import re
import sys

apply = "--apply" in sys.argv

PROMOTED = [
    "sub_OVC04_0001", "sub_OVC21_manage_c_22DD", "sub_OVC21_manage_c_23C2",
    "sub_OVC21_manage_c_24B1", "manage_usesLitoa103", "manage_usesCurSfxType32",
    "SUB_5b66_1d94", "ovc27_textCharmed", "audio_init_data", "fp_audio_done",
    "L_OVC21_manage_c_224C", "L_manage_4d05_2543_263F", "L_manage_4d05_2543_26E5",
    "manage_usesLitoa102", "L_OVC44_strong_dat_166E", "L_OVC47_constrct_c_1820",
]
name_alt = "|".join(PROMOTED)
HDR = re.compile(r"^(?P<ret>[^\n;(]*?\b)(" + name_alt + r")\s*\([^;]*\)\s*;", re.M)

changed = 0
for path in sorted(glob.glob("src/decompiled/*.h")):
    t = io.open(path, encoding="utf-8", errors="ignore").read()
    new, n = HDR.subn(lambda m: m.group("ret") + m.group(2) + "();", t)
    if n:
        changed += n
        if apply:
            io.open(path, "w", encoding="utf-8", newline="\n").write(new)

print("header declarations relaxed:", changed)
print("mode:", "APPLY" if apply else "dry run")
