"""Run the AGENTS.md section-5 grep checks over the exported tree.

One row per grep in AGENTS.md, in the same order, plus one extra row that the list
does not cover (`bStack_` is not in the `[iusc]` character class).  Run after every
export: this table is the progress ratchet for "properly decompiled code".
"""
import glob
import io
import os
import re
import sys

TREE = sys.argv[1] if len(sys.argv) > 1 else "src/decompiled"

CHECKS = [
    ('" + [0-9a-bA-Z]', r'" \+ [0-9a-bA-Z]'),
    ("argN_", r"arg[0-9]_"),
    ("arg_", r"arg_[a-za-z]"),
    ("ram0x", r"ram0x"),
    ("in_REG", r"in_(?:AX|BX|CX|DX|EAX|EBX|ECX|EDX|CF|ECF)\b"),
    ("[iusbc]Var", r"[iusbc]Var[_0-9]"),
    ("p[iusbc]Var", r"p[iusbc]Var[_0-9]"),
    ("p[iusc]Stack_", r"p[iusc]Stack_"),
    ("[iusc]Stack_", r"[iusc]Stack_"),
    ("bStack_ (not in list)", r"bStack_"),
    ("in_stack_", r"in_stack_[_0-9A-Za-z+]"),
    ("unaff_SS", r"unaff_SS"),
    ("unaff_ES", r"unaff_ES"),
    ("unaff_DI", r"unaff_DI"),
    ("unaff_SI", r"unaff_SI"),
    ("param_", r"param_[_0-9]"),
    ("valueN", r"value[0-9]"),
    ("numN", r"num[_0-9]"),
    ("ptrN", r"ptr[_0-9]"),
    ("(A) idx*stride", r"\(\([_0-9A-Za-z]*\)[0-9A-Za-z]* \+ [_0-9A-Za-z]* \* 0x[0-9A-Za-z]\)"),
    ("(B) idx*stride", r"\([0-9A-Za-z]* \+ [_0-9A-Za-z]* \* 0x[0-9A-Za-z]\)"),
    ("(C) idx*stride", r"\([_0-9A-Za-z]*\)[0-9A-Za-z]* \+ [_0-9A-Za-z]* \* 0x[0-9A-Za-z]"),
    ("(D) far const", r"[0-9a-b] \* 0x[0-9a-b]....[0-9a-b]"),
    ("LAB_", r"LAB_"),
]


def main():
    files = sorted(glob.glob(os.path.join(TREE, "*.c")))
    print("tree:", TREE, " files:", len(files))
    total = 0
    for label, pat in CHECKS:
        rx = re.compile(pat)
        n = 0
        worst = []
        for p in files:
            t = io.open(p, encoding="utf-8", errors="ignore").read()
            c = len(rx.findall(t))
            if c:
                n += c
                worst.append((c, os.path.basename(p)))
        worst.sort(reverse=True)
        total += n
        print("%-22s %7d   %s" % (label, n,
              ", ".join("%s=%d" % (f, c) for c, f in worst[:3])))
    print("TOTAL %d" % total)


main()
