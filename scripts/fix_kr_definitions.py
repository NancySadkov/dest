"""Convert the promoted functions to K&R definitions.

A C definition with a parameter list is a prototype, and it applies to calls that
come later in the same translation unit - `manage_usesLitoa103` is defined and then
called in ovc21_manage.c, so relaxing only the header is not enough.  A K&R
definition declares no prototype for its name, so every call is accepted:

    undefined2 __cdecl16far manage_usesLitoa103(p1,p2)
    undefined2 p1;
    int p2;
    { ... }

The parameters keep their recovered types, so the body is unchanged.

usage: python scripts/fix_kr_definitions.py [--apply]
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
name_alt = "|".join(PROMOTED)
SIG = re.compile(r"^(?P<ret>[A-Za-z_][\w \*]*?(?:__cdecl16far)?)\s*(?P<name>" +
                 name_alt + r")\s*\((?P<args>[^;{)]*)\)\s*$", re.M)

converted = 0
for path in sorted(glob.glob("src/decompiled/*.c")):
    lines = io.open(path, encoding="utf-8", errors="ignore").read().split("\n")
    out = []
    i = 0
    while i < len(lines):
        m = SIG.match(lines[i])
        if m and "..." not in m.group("args") and m.group("args").strip():
            args = [a.strip() for a in m.group("args").split(",")]
            parts, decls = [], []
            ok = True
            for a in args:
                toks = a.rsplit(None, 1)
                if len(toks) != 2:
                    ok = False
                    break
                parts.append(toks[1])
                decls.append("%s %s;" % (toks[0].strip(), toks[1]))
            if ok:
                head = "%s %s(%s)" % (m.group("ret").strip(), m.group("name"),
                                      ",".join(parts))
                out.append(head)
                out.extend(decls)
                converted += 1
                i += 1
                continue
        out.append(lines[i])
        i += 1
    if apply and converted:
        io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(out))

print("definitions converted to K&R:", converted)
print("mode:", "APPLY" if apply else "dry run")
