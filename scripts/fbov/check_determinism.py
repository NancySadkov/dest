#!/usr/bin/env python3
"""Assert that two runs of an EXE produce identical DGROUP state."""
import argparse
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--exe", required=True)
    a = ap.parse_args()
    r = subprocess.run(
        [sys.executable,
         os.path.join(ROOT, "scripts", "fbov", "boot_game_det.py"),
         "--compare", a.exe, a.exe],
        capture_output=True, text=True)
    print(r.stdout.rstrip())
    if r.returncode != 0:
        print(r.stderr.rstrip())
        raise SystemExit(1)
    print("DETERMINISTIC: two runs matched")


if __name__ == "__main__":
    main()
