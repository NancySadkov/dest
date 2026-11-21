"""Shorten string-symbol identifiers that exceed Turbo C's 32 significant chars.

Two different long strings can share their first 32 characters:

    s_Strongholds_cannot_be_placed_on_r_2410_461f
    s_Strongholds_cannot_be_placed_ove_2410_4647

Turbo C only compares the first 32, so the second definition is "initialized more
than once".

Only `s_*` data symbols are renamed: renaming function identifiers would break
the override files, which are keyed by function name (overrides/<mod>__<fn>.c).

usage: python scripts/fix_long_identifiers.py [--apply]
"""
import glob
import hashlib
import io
import re
import sys

CAND = re.compile(r"\bs_[A-Za-z0-9_]{28,}\b")

apply = "--apply" in sys.argv
files = sorted(glob.glob("src/decompiled/*.c") + glob.glob("src/decompiled/*.h")
               + glob.glob("overrides/*.c"))

long_names = set()
for p in files:
    t = io.open(p, encoding="utf-8", errors="ignore").read()
    for m in CAND.finditer(t):
        n = m.group(0)
        if len(n) > 31:
            long_names.add(n)

mapping = {}
for n in long_names:
    h = hashlib.md5(n.encode()).hexdigest()[:4]
    mapping[n] = n[:26] + "_" + h

print("string identifiers longer than 31 chars:", len(mapping))

order = sorted(mapping, key=len, reverse=True)
pat = re.compile(r"\b(" + "|".join(re.escape(n) for n in order) + r")\b") if order else None
changed = 0
for p in files:
    if not order:
        break
    t = io.open(p, encoding="utf-8", errors="ignore").read()
    new, k = pat.subn(lambda m: mapping[m.group(1)], t)
    if k:
        changed += k
        if apply:
            io.open(p, "w", encoding="utf-8", newline="\n").write(new)

print("renames:", changed, "files:", len(files))
print("mode:", "APPLY" if apply else "dry run")
for a, b in list(mapping.items())[:4]:
    print("   %-44s -> %s" % (a[:44], b))
