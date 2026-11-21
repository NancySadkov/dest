"""Convert quoted runs that sit inside a numeric brace group into char constants.

Ghidra renders a char array that mixes bytes as

    { ..., 0x0, "$", 0x04, 0x02, '\\t', ... }

A string literal is not a valid sibling of scalar elements in a char array, so
Turbo C reports "Too many initializers"/"Nonportable pointer conversion".  A
quoted run is converted only when its innermost brace group also contains
numeric elements, so ordinary `{ ..., "text" }` struct initialisers (pointer
members) are untouched.

usage: python scripts/fix_mixed_bytes.py [--apply]
"""
import io
import re
import sys

SRC = "src/decompiled/st_globals.c"


def parse(text):
    """Return (strings, groups): string spans and brace groups with flags."""
    strings = []          # (start, end, group_index)
    groups = []           # dict(start, end, has_num, has_str, parent)
    stack = []
    i = 0
    while i < len(text):
        c = text[i]
        if c == "{":
            g = {"start": i, "end": None, "has_num": False, "has_str": False,
                 "parent": stack[-1] if stack else None, "idx": len(groups)}
            groups.append(g)
            stack.append(g)
            i += 1
            continue
        if c == "}":
            if stack:
                g = stack.pop()
                g["end"] = i
            i += 1
            continue
        if c == '"':
            j = i + 1
            while j < len(text):
                if text[j] == "\\":
                    j += 2
                    continue
                if text[j] == '"':
                    break
                j += 1
            strings.append((i, j + 1, stack[-1]["idx"] if stack else None))
            for g in stack:
                g["has_str"] = True
            i = j + 1
            continue
        if c.isdigit():
            # a number token (0x.. or plain), not part of an identifier
            prev = text[i - 1] if i else " "
            if not (prev.isalnum() or prev == "_"):
                for g in stack:
                    g["has_num"] = True
                while i < len(text) and (text[i].isalnum() or text[i] in "xX._"):
                    i += 1
                continue
        i += 1
    return strings, groups


def to_chars(body):
    """Split a literal body into C character constants."""
    parts = []
    k = 0
    while k < len(body):
        if body[k] == "\\":
            parts.append(body[k:k + 2])
            k += 2
        else:
            parts.append(body[k])
            k += 1
    out = []
    for p in parts:
        if p.startswith("\\"):
            out.append("'%s'" % p)
        elif p == "'":
            out.append("'\\''")
        else:
            out.append("'%s'" % p)
    return ", ".join(out)


def convert(text):
    strings, groups = parse(text)
    # smallest containing group for each string
    repl = []
    for s, e, gi in strings:
        if gi is None:
            continue
        g = groups[gi]
        if not (g["has_num"] and g["has_str"]):
            continue
        body = text[s + 1:e - 1]
        if not body:
            continue
        repl.append((s, e, to_chars(body)))
    if not repl:
        return text, 0
    out = []
    pos = 0
    for s, e, new in sorted(repl):
        out.append(text[pos:s])
        out.append(new)
        pos = e
    out.append(text[pos:])
    return "".join(out), len(repl)


apply = "--apply" in sys.argv
text = io.open(SRC, encoding="utf-8", errors="ignore").read()
# work per declaration to keep the parser state small
lines = text.split("\n")
total = 0
for i, ln in enumerate(lines):
    if '"' in ln and "{" in ln:
        new, n = convert(ln)
        if n:
            lines[i] = new
            total += n
print("quoted runs converted to char constants:", total)
if apply:
    io.open(SRC, "w", encoding="utf-8", newline="\n").write("\n".join(lines))
    print("mode: APPLY")
else:
    print("mode: dry run")
