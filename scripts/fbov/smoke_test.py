#!/usr/bin/env python3
"""Smoke-test the built EXE under DOSBox and check the text screen.

Stages out/STRONG.EXE with the game data, boots it, dumps the BIOS text
screen through the debug server and looks for the expected startup prompt.
"""
import argparse
import os
import shutil
import socket
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
WORK = os.path.join(ROOT, "tmp", "smoke")
EMU = os.path.join(ROOT, "emulator", "dosbox-x-mod.exe")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--wait", type=int, default=8)
    ap.add_argument("--expect", default="Sound")
    a = ap.parse_args()

    os.makedirs(WORK, exist_ok=True)
    built = os.path.join(ROOT, "out", "STRONG.EXE")
    if not os.path.exists(built):
        raise SystemExit("missing " + built)
    shutil.copyfile(built, os.path.join(WORK, "STRONG.EXE"))
    for name in ("STRONG.DAT", "STRONG.FLI"):
        src = os.path.join(ROOT, "game", name)
        if os.path.exists(src):
            shutil.copyfile(src, os.path.join(WORK, name))
    conf = (
        "[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[dos]\nsynchronize time = false\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = fixed 20000\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + WORK.replace("\\", "\\\\") + "\n"
        "date 01-01-1993\ntime 00:00:00\n"
        "c:\nSTRONG.EXE\n"
    )
    conf_path = os.path.join(WORK, "run.conf")
    open(conf_path, "w").write(conf)

    subprocess.run(["powershell", "-NoProfile", "-Command",
                    "Get-Process | Where-Object {$_.ProcessName -match 'dosbox'} | "
                    "Stop-Process -Force -ErrorAction SilentlyContinue"],
                   capture_output=True)
    env = os.environ.copy()
    env["SDL_VIDEODRIVER"] = "dummy"
    env["SDL_AUDIODRIVER"] = "dummy"
    flags = 0x08000000 if os.name == "nt" else 0
    p = subprocess.Popen([EMU, "-noconsole", "-conf", conf_path],
                         cwd=os.path.join(ROOT, "emulator"), env=env,
                         creationflags=flags, stdout=subprocess.DEVNULL,
                         stderr=subprocess.DEVNULL)
    try:
        time.sleep(a.wait)
        dump = os.path.join(WORK, "screen.bin")
        s = socket.create_connection(("127.0.0.1", 23946), timeout=5)
        try:
            s.recv(65536)
        except Exception:
            pass
        path = dump.replace("\\", "\\\\").encode()
        s.sendall(b"dump B8000 4000 " + path + b"\n")
        time.sleep(1)
        try:
            s.recv(65536)
        except Exception:
            pass
        s.close()
        data = open(dump, "rb").read()
        rows = []
        for r in range(25):
            line = "".join(chr(data[(r * 80 + c) * 2])
                           if data[(r * 80 + c) * 2] >= 32 else " "
                           for c in range(80))
            rows.append(line.rstrip())
        text = "\n".join(rows)
        print(text)
        if a.expect not in text:
            raise SystemExit("expected %r not found on screen" % a.expect)
        print("SMOKE PASS: %r" % a.expect)
    finally:
        p.terminate()
        try:
            p.wait(timeout=5)
        except Exception:
            p.kill()


if __name__ == "__main__":
    main()
