"""Deref a `far_t` global through the segment it actually carries.

Ghidra prints a dereference of a far pointer it modelled as `far_t` (a {seg,ofs}
struct) as

    *(uint16_t *)BDA_DailyTimeCounter

which C reads as "cast the struct itself to a pointer", i.e. it uses DS and the
struct's address instead of the pointer value 0040:006c.  Turbo C then rejects
the struct->scalar cast outright, so this is both a compile error and the exact
"references wrong data segment" defect.

The faithful form uses the pointer the global holds:

    *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)

and for byte offsets

    *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2)
    -> *(uint16_t far *)((uint8_t far *)MK_FP(...seg, ...ofs) + 2)

Only globals declared `far_t NAME = { ofs, seg }` in st_globals.c are touched.

Dry run unless --apply.
"""
import io
import glob
import os
import re
import sys

GLOBALS = "src/decompiled/st_globals.c"

far = set()
if os.path.isfile(GLOBALS):
    for line in io.open(GLOBALS, encoding="utf-8", errors="ignore"):
        m = re.match(r"far_t\s+([A-Za-z_]\w*)\s*=", line)
        if m:
            far.add(m.group(1))
print("far_t globals:", len(far))

TYPES = (r"(u?int\d+_t|undefined\d|byte|char|ulong|uint|int|ushort|word|dword"
         r"|long|short)")
NAME = r"([A-Za-z_]\w*)"

# *(T *)(NAME.ofs + ...
P_OFFSET = re.compile(r"\*\(\s*" + TYPES + r"\s*\*\s*\)\s*\(\s*" + NAME + r"\.ofs\s*\+")
# *(T *)NAME  and  *(T *)NAME.ofs
P_DIRECT = re.compile(r"\*\(\s*" + TYPES + r"\s*\*\s*\)\s*" + NAME + r"(\.ofs)?\b")

apply = "--apply" in sys.argv
files = sorted(glob.glob("src/decompiled/*.c")) + sorted(glob.glob("overrides/*.c"))
counts = {"direct": 0, "offset": 0}
samples = []

for path in files:
    text = io.open(path, encoding="utf-8", errors="ignore").read()
    orig = text

    def repl_offset(m):
        ty, name = m.group(1), m.group(2)
        if name not in far:
            return m.group(0)
        counts["offset"] += 1
        return ("*(%s far *)((uint8_t far *)MK_FP(%s.seg, %s.ofs) + "
                % (ty, name, name))

    def repl_direct(m):
        ty, name = m.group(1), m.group(2)
        if name not in far:
            return m.group(0)
        counts["direct"] += 1
        if len(samples) < 8:
            samples.append((path.split("\\")[-1], m.group(0), name))
        return "*(%s far *)MK_FP(%s.seg, %s.ofs)" % (ty, name, name)

    text = P_OFFSET.sub(repl_offset, text)
    text = P_DIRECT.sub(repl_direct, text)
    if text != orig and apply:
        io.open(path, "w", encoding="utf-8", newline="\n").write(text)

print("direct derefs:", counts["direct"], "offset derefs:", counts["offset"])
print("mode:", "APPLY" if apply else "dry run")
for f, a, n in samples:
    print("   %-24s %-40s %s" % (f, a, n))
