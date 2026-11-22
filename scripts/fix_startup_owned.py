"""Do not re-define functions the C runtime startup already provides.

`crtl.c` is the recovered Borland CRT, which the startup object (C0.ASM) also
contains.  Linking both makes TLINK report

    Error: __TERMINATE defined in module C0.ASM is duplicated in module CRTL.C

(`_terminate` in C is the symbol `__TERMINATE`).  The two bodies are the same
function, so keep the prototype and the call from `___exit`, and let the startup's
copy win - exactly like the startup-owned data symbols that ExportData skips.

usage: python scripts/fix_startup_owned.py [--apply]
"""
import glob
import io
import re
import sys

apply = "--apply" in sys.argv

# C name -> why the startup owns it
OWNED = {
    "_terminate": "C0.ASM defines the CRT terminate routine",
}

changed = 0
for path in glob.glob("src/decompiled/*.c"):
    src = io.open(path, encoding="utf-8", errors="ignore").read()
    lines = src.split("\n")
    out = []
    i = 0
    hit = False
    while i < len(lines):
        line = lines[i]
        m = re.match(r"^[A-Za-z_][\w \*]*?\b(" + "|".join(OWNED) + r")\s*\(", line)
        if m:
            # copy the signature, then drop the brace block
            j = i
            while j < len(lines) and "{" not in lines[j]:
                j += 1
            depth = 0
            k = j
            while k < len(lines):
                depth += lines[k].count("{") - lines[k].count("}")
                if depth == 0 and "}" in lines[k]:
                    break
                k += 1
            out.append("/* %s: body supplied by the startup (%s); the recovered copy"
                       " would duplicate it. */" % (m.group(1), OWNED[m.group(1)]))
            sig = " ".join(x.strip() for x in lines[i:j] if x.strip())
            out.append(sig + ";")
            out.append("")
            i = k + 1
            hit = True
            changed += 1
            continue
        out.append(line)
        i += 1
    if hit and apply:
        io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(out))

print("startup-owned definitions dropped:", changed)
print("mode:", "APPLY" if apply else "dry run")
