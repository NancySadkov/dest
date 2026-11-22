"""Turn Ghidra's absolute-address pseudo-variables into real memory accesses.

Ghidra renders a reference it cannot symbolise as an absolute linear address and
the pipeline declared the result `extern <type> iRam00000066;` - a DGROUP global,
i.e. the wrong memory.  The address is encoded in the name, so each one becomes an
accessor:

    iRam00000066   ->  (*(int16_t far *)MK_FP(0x0000, 0x0066))      IVT entry
    uRam000000fa   ->  (*(undefined2 far *)MK_FP(0x0000, 0x00fa))
    ram0x00024180  ->  (*(undefined1 far *)MK_FP(ST_DGROUP_SEG, 0x0080))
    cRam00005e2c   ->  (*(char far *)MK_FP(0x05e2, 0x000c))

The 0x24100..0x34100 window is the original DGROUP (base 0x2410), so those are
expressed relative to *our* DGROUP, which lands wherever the linker puts it:
checking the window against the model shows 0x24180 is `errno` (DGROUP+0x80),
0x24186 is `__brklvl` and 0x2c9bb is `directvideo`, i.e. ordinary variables.

Everything else keeps its physical address, which is what the original used.
"""
import io
import os
import re

OUT = "src/decompiled"
ST_DGROUP = 0x2410

RAM = re.compile(r"^p?[uic]?Ram(?:0x)?[0-9a-fA-F]{5,8}$", re.I)


def ram_accessor(name, ty):
    m = re.search(r"([0-9a-fA-F]{5,8})$", name)
    if not m:
        return None
    a = int(m.group(1), 16)
    base = ty.replace("  ", " ").strip()
    if a < 0x400:                                  # interrupt vector table
        return "(*(%s far *)MK_FP(0x0000, 0x%04x))" % (base, a)
    if ST_DGROUP * 16 <= a < ST_DGROUP * 16 + 0x10000:
        return "(*(%s far *)MK_FP(ST_DGROUP_SEG, 0x%04x))" % (
            base, a - ST_DGROUP * 16)
    return "(*(%s far *)MK_FP(0x%04x, 0x%04x))" % (base, a >> 4, a & 0xF)


def main(ids, ident_type):
    path = os.path.join(OUT, "st_artifacts.h")
    lines = ["/* Ghidra pseudo-variables: register shadows, and absolute addresses. */",
             "#ifndef ST_ARTIFACTS_H",
             "#define ST_ARTIFACTS_H",
             "",
             "/* Our DGROUP segment, taken from a variable the linker places there.",
             "   Used for addresses that were DGROUP-relative in the original. */",
             "extern int errno;",
             "#define ST_DGROUP_SEG ((uint16_t)((uint32_t)(void far *)&errno >> 16))",
             ""]
    converted = 0
    for i in sorted(ids):
        t = ident_type(i)
        if RAM.match(i) and not t:
            # Ghidra's own spelling of an absolute address; the type is the same
            # one the original declarations carried, keyed by the prefix.
            pref = i[:2].lower()
            t = {"pu": "undefined2 *", "c": "char", "i": "int16_t",
                 "u": "undefined2"}.get(pref, "undefined1")
        if not t:
            continue
        if RAM.match(i):
            acc = ram_accessor(i, t)
            if acc:
                lines.append("#define %s %s" % (i, acc))
                converted += 1
                continue
        if i.startswith("far_t_ARRAY_"):
            lines.append("extern %s %s[];" % (t, i))
        else:
            lines.append("extern %s %s;" % (t, i))
    lines += ["#endif", ""]
    io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(lines))
    return converted


if __name__ == "__main__":
    # Regenerate in isolation from the current tree, for testing without a full
    # fix_recovered run.
    src = io.open("scripts/fix_recovered.py", encoding="utf-8").read()
    start = src.index("def ident_type(")
    end = src.index("def patch_headers(")
    ns = {"re": re, "os": os}
    exec(src[start:end].replace("def generate_artifacts(", "def _unused("), ns)
    ids = set()
    pat = re.compile(r"\b((?:p?[uic]?Ram(?:0x)?[0-9a-fA-F]{5,8})|(?:stack0x[0-9a-fA-F]+)"
                     r"|(?:in_[A-Za-z0-9_]+)|(?:unaff_[A-Za-z0-9_]+))", re.I)
    for name in os.listdir(OUT):
        if name.endswith(".c"):
            ids.update(pat.findall(io.open(os.path.join(OUT, name), encoding="utf-8",
                                           errors="replace").read()))
    print("ram accessors generated:", main(ids, ns["ident_type"]))
    print("artifacts total:", len(ids))
