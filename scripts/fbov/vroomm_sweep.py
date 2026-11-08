#!/usr/bin/env python3
"""Verify every recovered overlay module and refresh the accepted manifest.

Discovers `src/ov_XXXX.c`, runs the linked verifier for each module, writes a
log and updates `doc/vroomm_accepted.md`.

Usage:
  python scripts/fbov/vroomm_sweep.py [--wait 20] [SEG:MODULE ...]
"""
import argparse
import glob
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("modules", nargs="*", metavar="SEG:MODULE")
    ap.add_argument("--wait", type=int, default=20)
    ap.add_argument("--log", default=os.path.join(ROOT, "tmp", "verify_all.log"))
    ap.add_argument("--all", action="store_true",
                    help="verify every function, including raw asm/pad bodies")
    a = ap.parse_args()

    specs = list(a.modules)
    if not specs:
        for path in sorted(glob.glob(os.path.join(ROOT, "src", "ov_*.c"))):
            module = os.path.splitext(os.path.basename(path))[0]
            specs.append(module[3:] + ":" + module)
    if not specs:
        raise SystemExit("no overlay modules found")

    print("verifying %d module(s)" % len(specs))
    with open(a.log, "w", encoding="ascii", errors="replace") as log:
        subprocess.run(
            [sys.executable, os.path.join(ROOT, "scripts", "fbov", "vroomm_verify_linked.py"),
             *specs, "--wait", str(a.wait)] + (["--all"] if a.all else []),
            stdout=log, stderr=subprocess.STDOUT, cwd=ROOT)

    subprocess.run(
        [sys.executable, os.path.join(ROOT, "scripts", "fbov", "vroomm_manifest.py"),
         "--log", a.log], cwd=ROOT, check=True)


if __name__ == "__main__":
    main()
