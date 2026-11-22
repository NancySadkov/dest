"""Give the promoted functions an empty parameter list.

CreateFunctions created these from labels, so they have no parameters and the
exporter writes `(void)` - but their callers pass arguments, and Turbo C rejects
that ("Extra parameter in call").  An empty parameter list accepts any arguments,
which is the honest signature for a body whose arguments were not recovered.

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
    "SUB_5b66_1d94", "ovc27_textCharmed",
]
PAT = re.compile(r"\b(" + "|".join(PROMOTED) + r")\s*\(\s*void\s*\)")

# Their callers also *use* the result (`iVar1 = manage_usesLitoa103(...)`), and
# assigning a void expression is "Not an allowed type" in Turbo C.  The bodies were
# created without a return type too, so give them the word return the callers
# expect; a caller that ignores it is unaffected.
RETPAT = re.compile(r"\bvoid(\s+__cdecl16far\s+)(" + "|".join(PROMOTED) + r")\s*\(")

total = 0
for path in sorted(glob.glob("src/decompiled/*.c")) + ["src/decompiled/st_functions.h"]:
    t = io.open(path, encoding="utf-8", errors="ignore").read()
    new, n = PAT.subn(lambda m: m.group(1) + "()", t)
    new, k = RETPAT.subn(lambda m: "undefined2" + m.group(1) + m.group(2) + "(", new)
    n += k
    if n:
        total += n
        if apply:
            io.open(path, "w", encoding="utf-8", newline="\n").write(new)

print("promoted prototypes relaxed:", total)
print("mode:", "APPLY" if apply else "dry run")
