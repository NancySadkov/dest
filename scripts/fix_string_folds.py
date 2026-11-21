"""De-symbolize `(char *)"literal" + N`.

Ghidra renders a 16-bit constant by picking the nearest string symbol, so a
segment value such as 0x2410 prints as `(char *)"puppetmaker" + 3` because the
building-name table entry "puppetmaker" sits at DGROUP 0x240d.

The symbol dump (tmp/dg12.tsv) names these symbols s_<text>_<seg>_<ofs>, so the
address is recoverable exactly:  address = ofs, and the literal's value is
ofs + N.  Rewriting to that number keeps the value identical and removes the
false string reference.

Dry run unless --apply.
"""
import io
import os
import re
import sys

LIT = re.compile(r'\(char \*\)"([^"]*)" \+ (\d+)')
NAME = re.compile(r"^s_(.+)_([0-9a-fA-F]{4})_([0-9a-fA-F]{4})$")

addr = {}
for line in list(io.open("tmp/dg12.tsv", encoding="utf-8", errors="replace"))[1:]:
    p = line.rstrip("\n").split("\t")
    if len(p) < 4:
        continue
    m = NAME.match(p[1])
    if not m:
        continue
    text = m.group(1).replace("_", " ")
    addr.setdefault(text, (int(m.group(2), 16), int(m.group(3), 16)))

print("string symbols with an encoded address:", len(addr))

apply = "--apply" in sys.argv
total = fixed = miss = 0
samples = []
for name in sorted(os.listdir("src/decompiled")):
    if not name.endswith(".c"):
        continue
    path = os.path.join("src/decompiled", name)
    text = io.open(path, encoding="utf-8", errors="ignore").read()
    out, pos = [], 0
    for m in LIT.finditer(text):
        total += 1
        lit, delta = m.group(1), int(m.group(2))
        if delta == 0:
            miss += 1
            continue          # zero delta is a genuine string reference
        hit = addr.get(lit)
        if hit is None:
            miss += 1
            continue
        seg, ofs = hit
        value = ofs + delta
        repl = "(char *)0x%x" % value
        out.append(text[pos:m.start()])
        out.append(repl)
        pos = m.end()
        fixed += 1
        if len(samples) < 6:
            samples.append((name, m.group(0)[:46], repl))
    if out:
        out.append(text[pos:])
        if apply:
            io.open(path, "w", encoding="utf-8", newline="\n").write("".join(out))

print("folds:", total, "rewritten:", fixed, "unresolved:", miss)
print("mode:", "APPLY" if apply else "dry run")
for n, a, b in samples:
    print("   %-22s %-46s -> %s" % (n, a, b))
