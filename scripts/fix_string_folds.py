"""De-symbolize `"literal" + N` (with or without a `(char *)` cast).

Ghidra renders a 16-bit constant by picking the nearest string symbol, so a
segment value such as 0x2410 prints as `(char *)"puppetmaker" + 3` (or, when the
target is already char *, as a bare `"puppetmaker" + 3`) because the building-name
table entry "puppetmaker" sits at DGROUP 0x240d.  The delta may be printed in
decimal or in hex (`+ 0xd`).

The symbol dump (tmp/dg12.tsv) names these symbols s_<text>_<seg>_<ofs>, so the
address is recoverable exactly:  address = ofs, and the literal's value is
ofs + N.  Rewriting to that number keeps the value identical and removes the
false string reference.

A zero delta is left as the literal itself, only the noise ` + 0` is dropped
(`"lit" + 0` -> `"lit"`), which is the same address and type.

Both the exported tree and the committed overrides (overrides/) are swept, otherwise a
hard override would reintroduce the folds on every export.

Dry run unless --apply.
"""
import io
import os
import re
import sys

LIT = re.compile(r'(?P<cast>\(char \*\))?(?P<q>"(?:[^"\\\n]|\\.)*")'
                 r'(?P<ws>\s*\+\s*)(?P<delta>0[xX][0-9a-fA-F]+|\d+)\b')
# a constant base with a variable offset keeps the variable: Ghidra prints
# `"lit" + i` for `CONST + i`, where the literal is only standing in for CONST
VAR = re.compile(r'(?P<cast>\(char \*\))?(?P<q>"(?:[^"\\\n]|\\.)*")'
                 r'\s*\+\s*(?P<var>[A-Za-z_]\w*)\b')
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
dup = set()
for line in list(io.open("tmp/dg12.tsv", encoding="utf-8", errors="replace"))[1:]:
    p = line.rstrip("\n").split("\t")
    if len(p) < 4:
        continue
    m = NAME.match(p[1])
    if not m:
        continue
    text = norm(m.group(1))
    val = (int(m.group(2), 16), int(m.group(3), 16))
    if text in addr and addr[text] != val:
        dup.add(text)          # same text at two addresses: ambiguous
    else:
        addr[text] = val
for k in dup:
    addr.pop(k, None)
print("ambiguous (same text, two addresses) skipped:", len(dup))

# Manual overrides: when the same text exists twice, the address has to come
# from the instruction that uses it.  scripts/fold_addresses.tsv records those
# with their evidence.
forced = 0
try:
    for line in io.open("scripts/fold_addresses.tsv", encoding="utf-8"):
        if line.startswith("#") or not line.strip():
            continue
        f = line.rstrip("\n").split("\t")
        if len(f) < 3:
            continue
        addr[norm(f[0])] = (int(f[1], 16), int(f[2], 16))
        dup.discard(norm(f[0]))
        forced += 1
except FileNotFoundError:
    pass
print("manual fold addresses:", forced)

for line in list(io.open("tmp/dg12.tsv", encoding="utf-8", errors="replace"))[1:]:
    q = line.rstrip("\n").split("\t")
    if len(q) < 4 or ":" not in q[0] or not q[1].startswith("s_"):
        continue
    if NAME.match(q[1]):
        continue
    seg, off = q[0].split(":")
    text = norm(q[1][2:])
    val = (int(seg, 16), int(off, 16))
    if text in addr and addr[text] != val:
        continue
    addr.setdefault(text, val)

print("string symbols with an encoded address:", len(addr))

SYMARR = re.compile(r"\bs_[A-Za-z0-9_]*?_([0-9a-fA-F]{4})_([0-9a-fA-F]{4})\b(?=\[[^\]]+\])")

apply = "--apply" in sys.argv
total = fixed = zero = miss = symdone = 0
samples = []
unres = []

files = []
for name in sorted(os.listdir("src/decompiled")):
    if name.endswith(".c"):
        files.append(os.path.join("src/decompiled", name))
hard = "overrides"   # hand-corrected bodies, outside the generated tree
if os.path.isdir(hard):
    for name in sorted(os.listdir(hard)):
        if name.endswith(".c"):
            files.append(os.path.join(hard, name))

def resolve(lit):
    """Address of a string symbol by its printed text, tolerating truncation."""
    key = norm(lit)
    hit = addr.get(key)
    if hit is None and len(key) >= 8:
        # the printed literal can be truncated; accept the symbol whose text
        # extends it, when every such candidate has the same address
        cands = {v for k, v in addr.items()
                 if k.startswith(key) and len(k) > len(key)}
        if len(cands) == 1:
            hit = next(iter(cands))
    if hit is None and len(key) >= 8:
        # ... or the symbol text is truncated in the dump.  Take the longest
        # matching symbol text, which is the most specific one
        hits = [(k, v) for k, v in addr.items()
                if len(k) >= 8 and key.startswith(k)]
        if hits:
            best = max(len(k) for k, _ in hits)
            cands = {v for k, v in hits if len(k) == best}
            if len(cands) == 1:
                hit = next(iter(cands))
    return hit


for path in files:
    rel = path.replace("\\", "/")
    orig = io.open(path, encoding="utf-8", errors="ignore").read()
    text = orig

    # pass 1: constant delta
    out, pos = [], 0
    for m in LIT.finditer(text):
        total += 1
        lit = m.group("q")[1:-1]
        delta = int(m.group("delta"), 0)
        if delta == 0:
            # same address and same type, just drop the "+ 0" noise
            out.append(text[pos:m.start()])
            out.append((m.group("cast") or "") + m.group("q"))
            pos = m.end()
            zero += 1
            continue
        hit = resolve(lit)
        if hit is None:
            miss += 1
            if len(unres) < 12:
                unres.append((rel, m.group(0)[:60].replace("\n", " ")))
            continue
        seg, ofs = hit
        repl = "(char *)0x%x" % (ofs + delta)
        out.append(text[pos:m.start()])
        out.append(repl)
        pos = m.end()
        fixed += 1
        if len(samples) < 6:
            samples.append((rel, m.group(0)[:46].replace("\n", " "), repl))
    if out:
        out.append(text[pos:])
        text = "".join(out)

    # pass 2: variable offset -- keep the offset, replace the false base
    out, pos = [], 0
    for m in VAR.finditer(text):
        total += 1
        hit = resolve(m.group("q")[1:-1])
        if hit is None:
            miss += 1
            if len(unres) < 12:
                unres.append((rel, m.group(0)[:60].replace("\n", " ")))
            continue
        seg, ofs = hit
        repl = "(char *)0x%x + %s" % (ofs, m.group("var"))
        out.append(text[pos:m.start()])
        out.append(repl)
        pos = m.end()
        fixed += 1
        if len(samples) < 8:
            samples.append((rel, m.group(0)[:46].replace("\n", " "), repl))
    if out:
        out.append(text[pos:])
        text = "".join(out)

    # pass 3: a string symbol used as an array.  Ghidra prints `s_<text>_<seg>_<ofs>[i]`
    # for a byte access at that address, but string symbols are not declared as
    # variables, so the name does not compile.  The address is in the name.
    def repl_sym(m):
        global symdone
        symdone += 1
        return "((char *)0x%s)" % m.group(2)

    text = SYMARR.sub(repl_sym, text)

    if text != orig and apply:
        io.open(path, "w", encoding="utf-8", newline="\n").write(text)

print("files:", len(files))
print("folds:", total, "rewritten:", fixed, "simplified(+0):", zero,
      "unresolved:", miss)
print("symbol-as-array rewrites:", symdone)
print("mode:", "APPLY" if apply else "dry run")
for n, a, b in samples:
    print("   %-40s %-46s -> %s" % (n[-40:], a, b))
for n, a in unres:
    print("   UNRESOLVED %-34s %s" % (n[-34:], a))
