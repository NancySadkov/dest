"""Rank functions by section-5 artifact count, so recovery effort goes where it counts.

Reads the exported tree and, for each top-level function body, counts the
decompiler artefacts that AGENTS.md section 5 lists.  Prints the worst offenders
with their file and line span.
"""
import glob
import io
import os
import re

PATTERNS = {
    "uVar": r"\buVar[_0-9]",
    "iVar": r"\biVar[_0-9]",
    "bVar": r"\bbVar[_0-9]",
    "cVar": r"\bcVar[_0-9]",
    "pVar": r"\bp[iusbc]Var[_0-9]",
    "stack": r"\b[piusc]Stack_|in_stack_|\bstack0x",
    "unaff": r"\bunaff_[A-Za-z]",
    "param": r"\bparam_[_0-9]",
    "ptrN": r"\bptr[_0-9]",
    "stride": r"\([0-9A-Za-z]* \+ [_0-9A-Za-z]* \* 0x[0-9A-Za-z]",
}
RX = {k: re.compile(v) for k, v in PATTERNS.items()}

SIG = re.compile(r"^[A-Za-z_][\w \*]*?\b([A-Za-z_]\w*)\s*\([^;]*$")

rows = []
for path in sorted(glob.glob("src/decompiled/*.c")):
    lines = io.open(path, encoding="utf-8", errors="ignore").read().split("\n")
    i = 0
    while i < len(lines):
        m = SIG.match(lines[i])
        # a definition starts at a signature line followed (within 3 lines) by '{'
        if m:
            j = i
            while j < len(lines) and j < i + 4 and "{" not in lines[j]:
                j += 1
            if j < len(lines) and "{" in lines[j]:
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
                counts = {n: len(rx.findall(text)) for n, rx in RX.items()}
                total = sum(counts.values())
                if total:
                    rows.append((total, os.path.basename(path), m.group(1),
                                 i + 1, counts))
                i = k + 1
                continue
        i += 1

rows.sort(reverse=True)
print("%6s %-22s %-38s %s" % ("total", "file", "function", "breakdown"))
for total, f, fn, line, c in rows[:15]:
    hot = ",".join("%s=%d" % (k, v) for k, v in sorted(c.items(), key=lambda x: -x[1]) if v)
    print("%6d %-22s %-38s %s" % (total, f, fn[:38], hot))
print()
print("functions with artefacts:", len(rows), " total:", sum(r[0] for r in rows))
