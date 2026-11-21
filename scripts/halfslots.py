"""Cast the right-hand side of statements Turbo C reports as
"Nonportable pointer conversion", i.e. a pointer stored into a 16-bit half-slot.

Handles statements that span several lines.  Patches the exported file in place
and writes one function-level override per affected function so a re-export
keeps the fix.

usage: python tmp/halfslots.py <mod> <sourcefile.c> [dry]
"""
import io
import os
import re
import sys

mod = sys.argv[1]
srcname = sys.argv[2]
dry = "dry" in sys.argv[3:]

log_path = "tmp/buildsrc/%s.log" % mod
if not os.path.isfile(log_path):
    for f in os.listdir("tmp/buildsrc"):
        if f.lower() == mod.lower() + ".log":
            log_path = "tmp/buildsrc/" + f
            break
log = io.open(log_path, encoding="ascii", errors="replace").read()

targets = {}
for e in log.splitlines():
    m = re.search(r"Error \w+\.c (\d+): (.*?) in function (\w+)", e.strip())
    if m and m.group(2) == "Nonportable pointer conversion":
        targets[int(m.group(1))] = m.group(3)
print("target lines:", len(targets))

SRC = "src/decompiled/" + srcname
lines = io.open(SRC, encoding="utf-8", errors="ignore").read().split("\n")
ASSIGN = re.compile(r"(?<![=!<>+\-*/%&|^])=(?!=)")


def statement_end(lines, ln):
    """Index of the line holding the ';' that ends the statement at ln."""
    depth = 0
    for k in range(ln, min(ln + 12, len(lines))):
        for ch in lines[k]:
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
            elif ch == ";" and depth <= 0:
                return k
    return None


changed = {}
skipped = 0
for n, fnn in sorted(targets.items()):
    line = lines[n - 1]
    ms = [m.start() for m in ASSIGN.finditer(line)]
    if not ms:
        skipped += 1
        continue
    i = ms[-1]
    if line[i + 1:].lstrip().startswith("(uint16_t)"):
        continue
    end = statement_end(lines, n - 1)
    if end is None:
        print("  SKIP no ; line", n)
        skipped += 1
        continue
    # rebuild the statement with the cast inserted / closed
    head = line[:i + 1] + "(uint16_t)("
    tail = line[i + 1:]
    if end == n - 1:
        semi = tail.rfind(";")
        lines[n - 1] = head + tail[:semi] + ")" + tail[semi:]
        changed.setdefault(fnn, []).append(n)
    else:
        lines[n - 1] = head + tail
        semi = lines[end].rfind(";")
        lines[end] = lines[end][:semi] + ")" + lines[end][semi:]
        changed.setdefault(fnn, []).append(n)

print("statements wrapped:", sum(len(v) for v in changed.values()),
      "skipped:", skipped)
if dry:
    raise SystemExit(0)

io.open(SRC, "w", encoding="utf-8", newline="\n").write("\n".join(lines))


def extract(text_lines, fn):
    idx = None
    for k, l in enumerate(text_lines):
        if re.search(r"(?<![\w])" + re.escape(fn) + r"\(", l):
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
for fn, items in changed.items():
    span = extract(lines, fn)
    if span is None:
        print("MISSING", fn)
        continue
    start, end = span
    body = "\n".join(lines[start:end + 1])
    out = "overrides/%s__%s.c" % (srcname[:-2], fn)
    io.open(out, "w", encoding="utf-8", newline="\n").write(body + "\n")
    print("%-24s cast=%d -> %s" % (fn, len(items), os.path.basename(out)))
