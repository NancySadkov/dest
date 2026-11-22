"""How many `...` functions actually read extra arguments from the stack?

A `...` is only"real" if the body uses an argument beyond the named ones.  The
recovered bodies express that as `in_stack_0000XXXX` (or an `unaff_` register
param).  If the body never touches a stack argument, the `...` is spurious and
dropping it is exact: cdecl callers may still pass extra words and the callee
ignores them.

usage: python scripts/param_body.py
"""
import glob
import io
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "src", "decompiled")


def read(p):
    return io.open(p, encoding="latin-1", errors="ignore").read()


DEF = re.compile(r"^([A-Za-z_][\w \*]*?)\b(\w+)\s*\(([^;{]*)\)\s*$", re.M)

clean, uses_stack, total = [], [], 0
for path in glob.glob(os.path.join(SRC, "*.c")):
    t = read(path)
    for m in DEF.finditer(t):
        params = m.group(3)
        if "..." not in params:
            continue
        total += 1
        # body: from the next '{' to its matching '}'
        i = t.find("{", m.end())
        if i < 0:
            continue
        depth = 0
        j = i
        while j < len(t):
            if t[j] == "{":
                depth += 1
            elif t[j] == "}":
                depth -= 1
                if depth == 0:
                    break
            j += 1
        body = t[i:j]
        n_stack = len(re.findall(r"in_stack_[_0-9A-Za-z+]", body))
        n_unaff = len(re.findall(r"\bunaff_[A-Z]{2}\b", body))
        rec = (os.path.basename(path), m.group(2), params.strip(), n_stack, n_unaff)
        (uses_stack if (n_stack or n_unaff) else clean).append(rec)

print("functions with '...': %d" % total)
print("  body never reads an extra argument: %d" % len(clean))
print("  body reads stack/register arguments: %d" % len(uses_stack))
print("\nfirst clean examples:")
for r in clean[:10]:
    print("  %-18s %-32s %s" % (r[0], r[1], r[2][:48]))
print("\nfirst stack-using examples:")
for r in uses_stack[:8]:
    print("  %-18s %-32s stack=%d unaff=%d" % (r[0], r[1], r[3], r[4]))
