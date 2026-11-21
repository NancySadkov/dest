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

def norm(t):
    """Collapse escapes and punctuation so a literal matches its symbol text."""
    t = t.replace("\\r", " ").replace("\\n", " ").replace("\\t", " ")
    t = t.replace("\\'", "'").replace('\\"', '"')
    out = []
    for ch in t:
        out.append(ch if (ch.isalnum() or ch == " ") else " ")
    t = "".join(out)
    while "  " in t:
        t = t.replace("  ", " ")
    return t.strip().lower()


addr = {}
for line in list(io.open("tmp/dg12.tsv", encoding="utf-8", errors="replace"))[1:]:
    p = line.rstrip("\n").split("\t")
    if len(p) < 4:
        continue
    m = NAME.match(p[1])
    if not m:
        continue
    text = norm(m.group(1))
    addr.setdefault(text, (int(m.group(2), 16), int(m.group(3), 16)))

for line in list(io.open("tmp/dg12.tsv", encoding="utf-8", errors="replace"))[1:]:
    q = line.rstrip("\n").split("\t")
    if len(q) < 4 or ":" not in q[0] or not q[1].startswith("s_"):
        continue
    if NAME.match(q[1]):
        continue
    seg, off = q[0].split(":")
    addr.setdefault(norm(q[1][2:]), (int(seg, 16), int(off, 16)))

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
        hit = addr.get(norm(lit))
        if hit is None:
            # the printed literal can be truncated; accept the shortest symbol
            # whose text starts with it
            key = norm(lit)
            cands = [v for k, v in addr.items() if k.startswith(key) and len(k) > len(key)]
            if len(cands) == 1:
                hit = cands[0]
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
