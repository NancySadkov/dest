"""List every remaining param_N with the evidence needed to name it.

For each function that still uses `param_N`, print the prototype, each param_N
with up to three sample uses, and the function's address (so the prototype can be
added to scripts/model/param_protos.tsv for ApplyProto).
"""
import glob
import io
import re

syms = {}
for line in io.open("tmp/syms4.tsv", encoding="utf-8", errors="replace"):
    p = line.rstrip().split("\t")
    if len(p) >= 3 and ":" in p[0]:
        syms[p[1]] = p[0]

SIG = re.compile(r"^[A-Za-z_][\w \*]*?\b([A-Za-z_]\w*)\s*\([^;]*$")
PARAM = re.compile(r"\bparam_([0-9]+)\b")

total = 0
for path in sorted(glob.glob("src/decompiled/*.c")):
    lines = io.open(path, encoding="utf-8", errors="ignore").read().split("\n")
    i = 0
    while i < len(lines):
        m = SIG.match(lines[i])
        if not m:
            i += 1
            continue
        j = i
        while j < len(lines) and j < i + 4 and "{" not in lines[j]:
            j += 1
        if j >= len(lines) or "{" not in lines[j]:
            i += 1
            continue
        depth = 0
        k = j
        started = False
        body = []
        while k < len(lines):
            depth += lines[k].count("{") - lines[k].count("}")
            if "{" in lines[k]:
                started = True
            body.append(lines[k])
            if started and depth == 0:
                break
            k += 1
        text = "\n".join(body)
        found = sorted(set(PARAM.findall(text)))
        if found:
            name = m.group(1)
            sig = " ".join(x.strip() for x in lines[i:j] if x.strip())
            print("=== %s  (%s:%d)  addr=%s" % (name, path.split("/")[-1].split("\\")[-1],
                                                i + 1, syms.get(name, "?")))
            print("    %s" % sig[:150])
            for pn in found:
                uses = [l.strip()[:78] for l in text.split("\n")
                        if re.search(r"\bparam_%s\b" % pn, l)][:3]
                print("    param_%s: %s" % (pn, " | ".join(uses)))
                total += 1
            print()
        i = k + 1

print("param_N occurrences:", total)
