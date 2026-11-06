#!/usr/bin/env python3
"""Launch the modded DOSBox-X headlessly (no window, no console, no focus).

Usage:
  python scripts/fbov/run_dosbox.py --conf tmp/fn_build.conf --wait 20
  python scripts/fbov/run_dosbox.py --conf ... --wait 20 --keep

With --keep the emulator keeps running and its PID is printed; kill it with
taskkill /PID <pid> /F.
"""
import argparse
import os
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
EMU = os.path.join(ROOT, "emulator", "dosbox-x-mod.exe")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--conf", required=True)
    ap.add_argument("--wait", type=int, default=20)
    ap.add_argument("--keep", action="store_true")
    a = ap.parse_args()

    env = os.environ.copy()
    env["SDL_VIDEODRIVER"] = "dummy"
    env["SDL_AUDIODRIVER"] = "dummy"
    flags = 0x08000000 if os.name == "nt" else 0  # CREATE_NO_WINDOW
    p = subprocess.Popen(
        [EMU, "-noconsole", "-conf", a.conf],
        cwd=os.path.join(ROOT, "emulator"),
        env=env,
        creationflags=flags,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )
    time.sleep(a.wait)
    if a.keep:
        print(p.pid)
    else:
        p.terminate()
        try:
            p.wait(timeout=5)
        except Exception:
            p.kill()
    return 0


if __name__ == "__main__":
    sys.exit(main())
