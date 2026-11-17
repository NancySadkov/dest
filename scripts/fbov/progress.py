#!/usr/bin/env python3
"""Report how much of the stub tree has been replaced by recovered code.

A function is a stub when its body is empty or is the generated
`<return type> r; return r;` placeholder.  Everything else is recovered.

Usage:
  python scripts/fbov/progress.py [--src src] [--list]
"""
import argparse
import glob
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

FUNC = re.compile(
    r"/\* ([0-9a-f]{4}:[0-9a-f]{4}) \*/\s*\n"      # address comment
    r"(?P<sig>[^\n{]+?)\s*\n\{\n(?P<body>.*?)\}", re.S)


def return_type(sig):
    m = re.search(r"^(.*?)\b__(?:cdecl|stdcall|pascal)16(?:near|far)\b", sig)
    if m:
        return m.group(1).strip()
    return sig.rsplit(None, 1)[0].strip()


def is_stub(sig, body):
    text = " ".join(body.split())
    if not text:
        return True
    return re.fullmatch(r"[\w \t\*]+ r; return r;", text) is not None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--src", default=os.path.join(ROOT, "src"))
    ap.add_argument("--list", action="store_true")
    a = ap.parse_args()

    total = 0
    recovered = []
    stubs_by_mod = {}
    for path in sorted(glob.glob(os.path.join(a.src, "*.c"))):
        mod = os.path.basename(path)
        s = io.open(path, encoding="latin1").read()
        for m in FUNC.finditer(s):
            total += 1
            if is_stub(m.group("sig"), m.group("body")):
                stubs_by_mod[mod] = stubs_by_mod.get(mod, 0) + 1
            else:
                name = re.search(r"(\w+)\s*\(", m.group("sig"))
                recovered.append((mod, name.group(1) if name else "?"))

    print("functions: %d  recovered: %d  stubs: %d  (%.1f%%)"
          % (total, len(recovered), total - len(recovered),
             100.0 * len(recovered) / max(total, 1)))
    if a.list:
        for mod, name in recovered:
            print("  %-12s %s" % (mod, name))
    else:
        busy = sorted(stubs_by_mod.items(), key=lambda kv: -kv[1])[:10]
        print("largest remaining modules: " +
              ", ".join("%s(%d)" % kv for kv in busy))
    return 0


if __name__ == "__main__":
    sys.exit(main())
