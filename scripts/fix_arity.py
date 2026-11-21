"""Route calls whose argument list is shorter than the recovered prototype
through the overlay stub.

Ghidra sometimes recovers a prototype with more parameters than the call site
passes (the arguments were consumed by a calling-convention split).  Turbo C
rejects that with "Too few parameters in call to 'X'".  Every function has an
overlay stub `undefined ovr_X();` with an open prototype, so calling that stub
with the surviving argument list compiles and passes exactly the same bytes.

usage: python scripts/fix_arity.py <mod> <sourcefile.c> [dry]
"""
import io
import os
import re
import sys

mod = sys.argv[1]
srcname = sys.argv[2]
dry = "dry" in sys.argv[3:]
SRC = "src/decompiled/" + srcname
HDR = "src/decompiled/st_functions.h"

log_path = "tmp/buildsrc/%s.log" % mod
if not os.path.isfile(log_path):
    for f in os.listdir("tmp/buildsrc"):
        if f.lower() == mod.lower() + ".log":
            log_path = "tmp/buildsrc/" + f
            break
log = io.open(log_path, encoding="ascii", errors="replace").read()
hdr = io.open(HDR, encoding="utf-8", errors="ignore").read()

PAT = re.compile(r"Too few parameters in call to '(\w+)'")
targets = []
for e in log.splitlines():
    m = re.search(r"Error \w+\.c (\d+): (.*?) in function (\w+)", e.strip())
    if not m:
        continue
    mm = PAT.search(m.group(2))
    if mm:
        targets.append((int(m.group(1)), m.group(3), mm.group(1)))
print("arity errors:", len(targets))

lines = io.open(SRC, encoding="utf-8", errors="ignore").read().split("\n")
changed = {}
skipped = 0
for n, fnn, callee in sorted(targets, reverse=True):
    if ("ovr_" + callee + "(") not in hdr:
        print("  SKIP no stub for", callee)
        skipped += 1
        continue
    line = lines[n - 1]
    call = callee + "("
    if call not in line:
        print("  SKIP call not on line", n, line.strip()[:60])
        skipped += 1
        continue
    lines[n - 1] = line.replace(call, "ovr_" + callee + "(", 1)
    changed.setdefault(fnn, []).append(n)

print("calls rerouted:", sum(len(v) for v in changed.values()), "skipped:", skipped)
if dry:
    raise SystemExit(0)
io.open(SRC, "w", encoding="utf-8", newline="\n").write("\n".join(lines))


def extract(text_lines, fn):
    idx = None
    for k, l in enumerate(text_lines):
        if re.search(r"(?<![\w])" + re.escape(fn) + r"\(", l) or l.strip() == fn:
            for j in range(k + 1, min(k + 12, len(text_lines))):
                t = text_lines[j].strip()
                if not t:
                    continue
                if t.startswith("{"):
                    idx = k
                    break
                if t.endswith(";"):
                    break
            if idx is not None:
                break
    if idx is None:
        return None
    start = idx
    prev = text_lines[idx - 1].strip()
    if prev and not prev.startswith("/*") and not prev.endswith(";") \
            and not prev.endswith("}") and not prev.endswith("{"):
        start = idx - 1
    depth, seen, end = 0, False, None
    for k in range(start, len(text_lines)):
        for ch in text_lines[k]:
            if ch == "{":
                depth += 1
                seen = True
            elif ch == "}":
                depth -= 1
                if seen and depth == 0:
                    end = k
                    break
        if end is not None:
            break
    return None if end is None else (start, end)


os.makedirs("overrides", exist_ok=True)
for fn in sorted(changed):
    span = extract(lines, fn)
    if span is None:
        print("MISSING", fn)
        continue
    start, end = span
    body = "\n".join(lines[start:end + 1])
    out = "overrides/%s__%s.c" % (srcname[:-2], fn)
    io.open(out, "w", encoding="utf-8", newline="\n").write(body + "\n")
    print("%-26s rerouted=%d -> %s" % (fn, len(changed[fn]), os.path.basename(out)))
