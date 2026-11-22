"""Undo Ghidra's 31-character truncation of overlay-entry names.

Ghidra truncates long C identifiers to 31 characters and appends `_<hex>`, so a
call site can read

    ovr_attact_usesBDADailyTim_8bbe(...)

while the header declares

    undefined ovr_attact_usesBDADailyTimeCounter();

They are the same overlay entry, and only the full name has a thunk, so the
truncated spelling stays undefined at link time.  Resolve each truncated spelling
to the unique declared name it prefixes.  Ambiguous prefixes are reported and left
alone rather than guessed.
"""
import glob
import io
import re
import sys

apply = "--apply" in sys.argv
HDR = "src/decompiled/st_functions.h"

declared = set(re.findall(r"\b(ovr_\w+)\s*\(", io.open(HDR, encoding="utf-8",
                                                       errors="ignore").read()))
print("declared overlay entries:", len(declared))

# identifiers ending in _<4 hex digits> are the truncated ones
pat = re.compile(r"\b(ovr_\w+?_[0-9a-f]{4})\b")

files = sorted(glob.glob("src/decompiled/*.c")) + sorted(glob.glob("overrides/*.c"))
resolved, ambiguous = {}, {}
for path in files:
    t = io.open(path, encoding="utf-8", errors="ignore").read()
    for m in pat.finditer(t):
        name = m.group(1)
        if name in declared:
            continue
        stem = name.rsplit("_", 1)[0]
        cands = [d for d in declared if d.startswith(stem)]
        if len(cands) == 1:
            resolved[name] = cands[0]
        else:
            ambiguous[name] = sorted(cands)

# A second form has no hex suffix: the identifier is simply cut at 31 characters,
# e.g. ovr_ovc28_usesBDADailyTimeCounte for ...TimeCounter.
for path in files:
    t = io.open(path, encoding="utf-8", errors="ignore").read()
    for m in re.finditer(r"\b(ovr_\w+)\b", t):
        name = m.group(1)
        if name in declared or name in resolved:
            continue
        cands = [d for d in declared if d.startswith(name)]
        if len(cands) == 1:
            resolved[name] = cands[0]
        elif len(cands) > 1:
            ambiguous[name] = sorted(cands)

print("truncated spellings resolved:", len(resolved))
for k, v in sorted(resolved.items()):
    print("   %-40s -> %s" % (k, v))
print("ambiguous (left alone):", len(ambiguous))
for k, v in sorted(ambiguous.items()):
    print("   %-40s candidates: %s" % (k, ", ".join(v)))

if apply and resolved:
    n = 0
    for path in files:
        t = io.open(path, encoding="utf-8", errors="ignore").read()
        orig = t
        for old, new in resolved.items():
            t = re.sub(r"\b" + re.escape(old) + r"\b", new, t)
        if t != orig:
            io.open(path, "w", encoding="utf-8", newline="\n").write(t)
            n += 1
    print("files rewritten:", n)
print("mode:", "APPLY" if apply else "dry run")
