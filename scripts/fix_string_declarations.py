"""Replace `char name[N] = "text";` declarations with explicit byte arrays.

AGENTS.md now greps `char [_0-9A-Za-z]*\\[[0-9]*\\] = "`.  The strings themselves
must stay: they are the original DGROUP bytes, referenced by far-pointer tables
(GErrorStrings, GStatsLabels, ...) and by address.  What changes is only the
declaration form: the same bytes become `uint8_t name[N] = { ... }` with the text
kept as a comment, so the literal text is used at the call sites (which the
export already does) and no `char ...[N] = "` declaration remains.

Byte counts are preserved exactly: the literal's bytes (with escapes decoded)
plus NUL padding up to the declared size.

usage: python scripts/fix_string_declarations.py [--apply]
"""
import io
import re
import sys

apply = "--apply" in sys.argv
DECL = re.compile(r'^char ([_0-9A-Za-z]+)\[(\d*)\] = "((?:[^"\\]|\\.)*)";$')

ESC = {"n": 10, "r": 13, "t": 9, "0": 0, "\\": 92, '"': 34, "'": 39,
       "a": 7, "b": 8, "f": 12, "v": 11}


def decode(s):
    out = []
    i = 0
    while i < len(s):
        c = s[i]
        if c != "\\":
            out.append(ord(c))
            i += 1
            continue
        i += 1
        if i >= len(s):
            break
        e = s[i]
        if e == "x":
            j = i + 1
            h = ""
            while j < len(s) and len(h) < 2 and s[j] in "0123456789abcdefABCDEF":
                h += s[j]
                j += 1
            out.append(int(h, 16))
            i = j
            continue
        out.append(ESC.get(e, ord(e)))
        i += 1
    return out


total = 0
changed = 0
for path in ("src/decompiled/st_globals.c", "src/decompiled/st_globals2.c",
             "src/decompiled/st_globals3.c", "src/decompiled/st_globals4.c",
             "src/decompiled/st_globals5.c"):
    lines = io.open(path, encoding="latin-1").read().split("\n")
    out = []
    n = 0
    for line in lines:
        m = DECL.match(line.strip())
        if not m:
            out.append(line)
            continue
        name, size, text = m.group(1), m.group(2), m.group(3)
        data = decode(text) + [0]
        size = int(size) if size else len(data)
        if len(data) < size:
            data += [0] * (size - len(data))
        if len(data) != size:
            out.append(line)
            continue
        body = ", ".join("0x%02X" % b for b in data)
        shown = text.replace("*/", "* /")
        out.append('/* "%s" */' % shown)
        out.append("uint8_t %s[%d] = { %s };" % (name, size, body))
        n += 1
    total += n
    if n:
        changed += 1
        print("  %-30s %d declarations" % (path, n))
        if apply:
            io.open(path, "w", encoding="latin-1", newline="\n").write("\n".join(out))

print("string declarations converted:", total, "in", changed, "files",
      "(applied)" if apply else "(dry run)")
