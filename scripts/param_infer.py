"""Infer the real parameter lists behind Ghidra's `...`.

For every recovered function whose prototype/definition ends in `...`, look at
every call site (`name(...)` and the overlay thunk `ovr_name(...)`) and decide:

  variadic   the function is genuinely variadic (printf, stExit, ...) - keep `...`
  no-extra   no call site passes more than the named parameters, so `...` is
             unjustified and can be dropped
  extra      calls pass N more arguments; their types are inferred from the
             argument expressions (text, segment, far pointer, integer)

Output: scripts/model/param_infer.tsv

usage: python scripts/param_infer.py
"""
import glob
import io
import os
import re
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "src", "decompiled")


def read(p):
    return io.open(p, encoding="latin-1", errors="ignore").read()


def split_args(s):
    """Split a parameter/argument list at top-level commas."""
    out, cur, depth = [], "", 0
    i = 0
    in_str = False
    while i < len(s):
        c = s[i]
        if in_str:
            cur += c
            if c == "\\":
                if i + 1 < len(s):
                    cur += s[i + 1]
                    i += 2
                    continue
            elif c == '"':
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


def strip_comments(t):
    t = re.sub(r"/\*.*?\*/", " ", t, flags=re.S)
    return re.sub(r"//[^\n]*", " ", t)


# ---- definitions -----------------------------------------------------------
DEF = re.compile(r"^([A-Za-z_][\w \*]*?)\b(\w+)\s*\(([^;{]*)\)\s*$", re.M)
defs = {}
for path in glob.glob(os.path.join(SRC, "*.c")):
    t = strip_comments(read(path))
    for m in DEF.finditer(t):
        ret, name, params = m.group(1).strip(), m.group(2), m.group(3).strip()
        if name in ("if", "for", "while", "switch", "return", "sizeof"):
            continue
        defs[name] = (os.path.basename(path), ret, params)

# ---- prototypes ------------------------------------------------------------
PROTO = re.compile(r"^[A-Za-z_][\w \*]*?\b(\w+)\s*\(([^;{]*)\)\s*;", re.M)
protos = {}
for m in PROTO.finditer(strip_comments(read(os.path.join(SRC, "st_functions.h")))):
    protos[m.group(1)] = m.group(2).strip()

# ---- call sites ------------------------------------------------------------
CALL = re.compile(r"\b(ovr_)?(\w+)\s*\(")
calls = defaultdict(list)
for path in glob.glob(os.path.join(SRC, "*.c")):
    t = strip_comments(read(path))
    for m in CALL.finditer(t):
        name = m.group(2)
        if name not in defs:
            continue
        # find the matching close paren
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
        calls[name].append(t[start:i])

VARIADIC = {"printf", "_sprintf", "sprintf", "stExit", "stsprintf", "mkp"}


def arg_kind(a):
    a = a.strip()
    if a.startswith('"'):
        return "char *"
    if a.startswith("(char *)"):
        return "char *"
    if "MK_FP(" in a or "far *" in a or a.startswith("far_t"):
        return "far_t"
    if a.startswith("&"):
        return "void *"
    if re.match(r"^-?(0x[0-9A-Fa-f]+|\d+)$", a):
        return "uint16_t"
    return "uint16_t"


rows = []
for name, (path, ret, params) in sorted(defs.items()):
    if "..." not in params:
        continue
    named = [p for p in split_args(params.replace("...", "")) if p]
    # The call regex also matches the definition line, and a bare "..." is a
    # top-level item there.  Keep only real call sites and real arguments.
    sites = [c for c in calls.get(name, [])
             if c.strip() != params.strip()
             and c.strip() != params.replace("...", "").strip()]
    arities = [len([a for a in split_args(c) if a != "..."]) for c in sites]
    amax = max(arities) if arities else 0
    if name in VARIADIC:
        cls, extra = "variadic", []
    elif amax <= len(named):
        cls, extra = "no-extra", []
    else:
        cls = "extra"
        widths = [[] for _ in range(amax - len(named))]
        for c in sites:
            args = [a for a in split_args(c) if a != "..."]
            for k in range(len(named), len(args)):
                widths[k - len(named)].append(arg_kind(args[k]))
        extra = [Counter(w).most_common(1)[0][0] if w else "uint16_t"
                 for w in widths]
    rows.append((name, path, len(named), amax, cls, ",".join(extra),
                 sum(1 for a in arities if a > len(named)), len(arities)))

out = os.path.join(ROOT, "scripts", "model", "param_infer.tsv")
with io.open(out, "w", encoding="utf-8", newline="\n") as f:
    f.write("# Functions whose recovered signature ends in '...'.\n")
    f.write("# name\tfile\tnamed\tmax_call_arity\tclass\textra_types\t"
            "calls_with_extra\tcalls\n")
    for r in rows:
        f.write("\t".join(str(x) for x in r) + "\n")

cls_count = Counter(r[4] for r in rows)
print("functions with '...': %d" % len(rows))
for k, v in cls_count.most_common():
    print("  %-10s %d" % (k, v))
print("wrote", out)
