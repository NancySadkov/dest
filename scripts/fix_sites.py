"""Add a (uint16_t) cast to statements Turbo C rejects as nonportable pointer
conversions, i.e. a pointer stored into a 16-bit half-slot.

    (*(uint16_t *)((uint8_t *)&(h))) = ems_init(x);
 -> (*(uint16_t *)((uint8_t *)&(h))) = (uint16_t)ems_init(x);

Reads the line numbers from tmp/buildsrc/<mod>.log, patches the exported file in
place and writes one function-level override per affected function so a
re-export keeps the fix.

usage: python tmp/fix_sites.py <mod> <sourcefile.c> [<error class>]
"""
import io
import os
import re
import sys

mod = sys.argv[1]
srcname = sys.argv[2]
want = sys.argv[3] if len(sys.argv) > 3 else "Nonportable pointer conversion"
SRC = "src/decompiled/" + srcname

log = io.open("tmp/buildsrc/%s.log" % mod, encoding="ascii", errors="replace").read()
targets = {}
for e in log.splitlines():
    m = re.search(r"Error \w+\.c (\d+): (.*?) in function (\w+)", e.strip())
    if m and m.group(2) == want:
        targets[int(m.group(1))] = m.group(3)
print("target lines:", len(targets))

lines = io.open(SRC, encoding="utf-8", errors="ignore").read().split("\n")

ASSIGN = re.compile(r"(?<![=!<>+\-*/%&|^])=(?!=)")


def wrap(line):
    """Wrap the assignment RHS in (uint16_t) when it is not already cast."""
    idx = [m.start() for m in ASSIGN.finditer(line)]
    if not idx:
        return None
    i = idx[-1]
    end = line.rfind(";")
    if end < i:
        return None
    rhs = line[i + 1:end]
    if rhs.strip().startswith("(uint16_t)"):
        return None
    return line[:i + 1] + "(uint16_t)" + rhs + line[end:]


fns = sorted(set(targets.values()))
changed = {}
for n, fnn in targets.items():
    new = wrap(lines[n - 1])
    if new is None:
        print("  SKIP line", n, lines[n - 1].strip()[:70])
        continue
    changed.setdefault(fnn, []).append((n, new))
    lines[n - 1] = new

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
    print("%-24s cast=%d  -> %s" % (fn, len(items), out))
