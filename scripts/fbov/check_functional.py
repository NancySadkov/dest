#!/usr/bin/env python3
"""Build the functional C EXE and verify it deterministically against the original."""
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def main():
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov",
                                 "build_functional_exe.py")], check=True)
    func = os.path.join(ROOT, "out", "STRONG_FUNC.EXE")
    orig = os.path.join(ROOT, "out", "STRONG.EXE")
    r = subprocess.run([sys.executable,
                        os.path.join(ROOT, "scripts", "fbov",
                                     "boot_game_det.py"),
                        "--compare", orig, func],
                       capture_output=True, text=True)
    print(r.stdout.rstrip())
    if r.returncode != 0:
        print(r.stderr.rstrip())
        raise SystemExit(1)
    print("FUNCTIONAL C EXE: deterministic match")


if __name__ == "__main__":
    main()
