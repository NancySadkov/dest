"""Add the missing trailing parameters behind Ghidra's `...`.

For every function classified `extra` by scripts/param_infer.py, append
`uint16_t argN` parameters up to the maximum arity seen at any call site, in both
the definition and st_functions.h.  Because cdecl pushes arguments right to left,
appending parameters leaves the offsets of the existing ones unchanged, so the
body's `in_stack_0000XXXX` references keep pointing at the same words.

Call sites that pass fewer arguments than the new signature are padded with `0`
for the missing trailing slots (cdecl-safe, and it is the value the callee would
have read anyway).

usage: python scripts/add_ellipsis_params.py [--dry]
"""
import glob
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "src", "decompiled")
TSV = os.path.join(ROOT, "scripts", "model", "param_infer.tsv")

dry = "--dry" in sys.argv

rows = [l.rstrip("\n").split("\t") for l in io.open(TSV, encoding="utf-8")
        if not l.startswith("#")]
# Call sites disagree on the type of the extra argument (a pointer at some
# sites, a stack word at others), so no single parameter type is evidenced.
# They keep `...` and are recorded in the TSV for a manual pass.
SKIP = {"agnt_usesAnimFrame", "manage_playerTitle", "ovc41_compute3",
        "ovc45_compute9", "ovc41_pluralSuffix"}

extra = {}
no_extra = set()
for r in rows:
    if len(r) > 4 and r[4] == "no-extra":
        no_extra.add(r[0])
for r in rows:
    if len(r) > 5 and r[4] == "extra" and r[0] not in SKIP:
        named, amax = int(r[2]), int(r[3])
        types = r[5].split(",") if r[5] else []
        extra[r[0]] = (named, amax, types)


def split_args(s):
    out, cur, depth = [], "", 0
    i, in_str = 0, False
    while i < len(s):
        c = s[i]
        if in_str:
            cur += c
            if c == "\\" and i + 1 < len(s):
                cur += s[i + 1]
                i += 2
                continue
            if c == '"':
                in_str = False
            i += 1
            continue
        if c == '"':
            in_str = True
            cur += c
        elif c in "([{":
            depth += 1
            cur += c
        elif c in ")]}":
            depth -= 1
            cur += c
        elif c == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += c
        i += 1
    if cur.strip():
        out.append(cur.strip())
    return out


def mask_comments(t):
    def repl(m):
        return "".join("\n" if c == "\n" else " " for c in m.group(0))
    return re.sub(r"/\*.*?\*/", repl, t, flags=re.S)


def matches(t, name):
    """Yield (start, argstart, argend, args-text) for name( ... )."""
    pat = re.compile(r"\b((?:ovr_)?)" + re.escape(name) + r"\s*\(")
    for m in pat.finditer(t):
        i = m.end() - 1
        depth = 0
        start = i + 1
        while i < len(t):
            c = t[i]
            if c == '"':
                i += 1
                while i < len(t) and t[i] != '"':
                    if t[i] == "\\":
                        i += 1
                    i += 1
            elif c == "(":
                depth += 1
            elif c == ")":
                depth -= 1
                if depth == 0:
                    break
            i += 1
        yield m.group(1), start, i, t[start:i]


STR = re.compile(r'"(?:\\.|[^"\\])*"')


def is_signature(args):
    return "..." in STR.sub('""', args)


def drop_ellipsis(args):
    """Remove a trailing `...` from a parameter list."""
    items = [a for a in split_args(args) if a and a != "..."]
    return ",".join(items)


def add_params(args, info):
    """Replace the trailing `...` with typed parameter names."""
    named, amax, types = info
    items = [a for a in split_args(args) if a and a != "..."]
    have = len(items)
    if have >= amax:
        return args
    new = items[:]
    for k in range(have, amax):
        ty = types[k - named] if k - named < len(types) else "uint16_t"
        new.append("%s arg%d" % (ty, k + 1))
    return ",".join(new)


def pad_call(args, info, name):
    named, amax, types = info
    items = split_args(args)
    if items == [""]:
        items = []
    if len(items) >= amax:
        return args
    items += ["0"] * (amax - len(items))
    return ",".join(items)


changed = 0
files = 0
for path in glob.glob(os.path.join(SRC, "*.c")) + [os.path.join(SRC, "st_functions.h")]:
    t = io.open(path, encoding="latin-1").read()
    masked = mask_comments(t)
    edits = []
    for name, info in extra.items():
        for prefix, a0, a1, _masked_args in matches(masked, name):
            args = t[a0:a1]
            # `undefined ovr_name();` declarations in st_functions.h have an
            # empty parameter list; they are not call sites
            if prefix and not split_args(args):
                continue
            if is_signature(args):
                new = add_params(args, info)
            else:
                new = pad_call(args, info, name)
            if new != args:
                edits.append((a0, a1, new))
    for name in no_extra:
        for prefix, a0, a1, _masked_args in matches(masked, name):
            args = t[a0:a1]
            if not is_signature(args):
                continue
            new = drop_ellipsis(args)
            if new != args:
                edits.append((a0, a1, new))
    if not edits:
        continue
    edits.sort()
    # drop overlapping edits (nested matches)
    clean = []
    last = -1
    for a0, a1, new in edits:
        if a0 < last:
            continue
        clean.append((a0, a1, new))
        last = a1
    for a0, a1, new in reversed(clean):
        t = t[:a0] + new + t[a1:]
    if not dry:
        io.open(path, "w", encoding="latin-1", newline="").write(t)
    files += 1
    changed += len(clean)

print("%s: %d edits in %d files" %
      ("padded+extended" if not dry else "would edit", changed, files))
