#!/usr/bin/env python3
"""Verify and substitute every pure-C function of a recovered overlay module.

Compiles are expected in the OMF object given by --obj.  Functions whose body
in --src contains no `asm db` are checked against the original overlay bytes
with the VROOMM substitution tool; call/jump operands are taken from the
original image.  Prints PASS or the reason a function was skipped.
"""
import argparse
import csv
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "scripts", "fbov"))
from byte_match import parse_omf


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--obj", required=True)
    ap.add_argument("--seg", required=True, help="overlay code segment, e.g. 3381")
    ap.add_argument("--src", required=True)
    a = ap.parse_args()
    seg = int(a.seg, 16)

    segdata, pub = parse_omf(a.obj)
    prefix = "f_%04x_" % seg
    byseg = {}
    for name, (s, ofs) in pub.items():
        if name.startswith(prefix):
            byseg.setdefault(s, []).append((ofs, name))
    sseg = max(byseg, key=lambda s: len(byseg[s]))

    # The object may not lay functions out at the original offsets (an earlier
    # recovered function can be a different size).  The recovered name encodes
    # the authoritative original offset, so derive sizes from the names.
    orig_at = {}
    for _, name in byseg[sseg]:
        m = re.match(r"^%s([0-9a-f]+)$" % re.escape(prefix), name)
        if m:
            orig_at[name] = int(m.group(1), 16)
    funcs = sorted((ofs, name) for name, ofs in orig_at.items())

    src = open(a.src, encoding="ascii").read()
    pure = {}
    for m in re.finditer(r"__cdecl16far\s+(%s[0-9a-f]+)\s*\([^)]*\)\s*\{" % prefix, src):
        name = m.group(1)
        i = m.end() - 1
        depth = 0
        for j in range(i, len(src)):
            if src[j] == "{":
                depth += 1
            elif src[j] == "}":
                depth -= 1
                if depth == 0:
                    pure[name] = "asm db" not in src[i:j + 1]
                    break

    codesz = 0
    for r in csv.DictReader(open(os.path.join(ROOT, "doc", "fbov_overlays.csv"))):
        if int(r["code_seg"], 16) == seg:
            codesz = int(r["codesz"], 16)
            break

    passed = 0
    for idx, (ofs, name) in enumerate(funcs):
        if not pure.get(name, False):
            continue
        nxt = funcs[idx + 1][0] if idx + 1 < len(funcs) else codesz
        size = nxt - ofs
        if size <= 0:
            continue
        r = subprocess.run(
            [sys.executable, os.path.join(ROOT, "scripts", "fbov", "vroomm_subst.py"),
             "--obj", a.obj, "--name", name, "--overlay-seg", a.seg,
             "--ofs", "0x%X" % ofs, "--len", str(size)],
            capture_output=True, text=True)
        if r.returncode == 0:
            passed += 1
            print("PASS %s ofs=%04X size=%d" % (name, ofs, size))
        else:
            msg = (r.stderr or r.stdout).strip().splitlines()
            print("skip %s ofs=%04X size=%d: %s" % (name, ofs, size, msg[-1] if msg else ""))
    print("passed", passed)


if __name__ == "__main__":
    main()
