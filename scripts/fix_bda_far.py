"""Deref a `far_t` global through the segment it actually carries.

A far_t is a {seg,ofs} struct, so `*(uint16_t *)BDA_DailyTimeCounter` casts the
struct instead of the pointer it holds: DS-relative, wrong segment, and rejected
by Turbo C.  The faithful form uses the pointer the global holds:

    *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)

and for byte offsets

    *(uint16_t far *)((uint8_t far *)MK_FP(...seg, ...ofs) + 2)

Only globals declared `far_t NAME = ...` in the generated globals TU are touched.
The target type may itself be a pointer (`*(ulong **)BDA_x`).

Dry run unless --apply.
"""
import glob
import io
import os
import re
import sys

GLOBALS = ["src/decompiled/st_globals.c", "src/decompiled/st_globals2.c"]

far = set()
for g in GLOBALS:
    if not os.path.isfile(g):
        continue
    for line in io.open(g, encoding="utf-8", errors="ignore"):
        m = re.match(r"far_t\s+([A-Za-z_]\w*)\s*=", line)
        if m:
            far.add(m.group(1))
print("far_t globals:", len(far))

TYPES = (r"([A-Za-z_]\w*\s*\*+|u?int\d+_t|undefined\d|byte|char|ulong|uint|int"
         r"|ushort|word|dword|long|short)")
NAME = r"([A-Za-z_]\w*)"

P_OFFSET = re.compile(r"\*\(\s*" + TYPES + r"\s*\*\s*\)\s*\(\s*" + NAME + r"\.ofs\s*\+")
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
        return "*(%s far *)((uint8_t far *)MK_FP(%s.seg, %s.ofs) + " % (ty.strip(), name, name)

    def repl_direct(m):
        ty, name = m.group(1), m.group(2)
        if name not in far:
            return m.group(0)
        counts["direct"] += 1
        if len(samples) < 6:
            samples.append((path.split("\\")[-1], m.group(0), name))
        return "*(%s far *)MK_FP(%s.seg, %s.ofs)" % (ty.strip(), name, name)

    text = P_OFFSET.sub(repl_offset, text)
    text = P_DIRECT.sub(repl_direct, text)
    if text != orig and apply:
        io.open(path, "w", encoding="utf-8", newline="\n").write(text)

print("direct derefs:", counts["direct"], "offset derefs:", counts["offset"],
      "files:", len(files))
print("mode:", "APPLY" if apply else "dry run")
for f, a, n in samples:
    print("   %-24s %-40s %s" % (f, a, n))
