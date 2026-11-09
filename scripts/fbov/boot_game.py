#!/usr/bin/env python3
"""Boot the built EXE into the in-game map screen.

The startup flow is text-mode: pick sound (6 = off), then press Enter through
the intro until the map screen.  The map screen is detected from the VGA
frame (minimap and bottom text bands).
"""
import argparse
import os
import shutil
import socket
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
WORK = os.path.join(ROOT, "tmp", "boot_game")
EMU = os.path.join(ROOT, "emulator", "dosbox-x-mod.exe")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--wait", type=int, default=4)
    ap.add_argument("--steps", type=int, default=12)
    a = ap.parse_args()

    os.makedirs(WORK, exist_ok=True)
    shutil.copyfile(os.path.join(ROOT, "out", "STRONG.EXE"),
                    os.path.join(WORK, "STRONG.EXE"))
    for name in ("STRONG.DAT", "STRONG.FLI"):
        src = os.path.join(ROOT, "game", name)
        if os.path.exists(src):
            shutil.copyfile(src, os.path.join(WORK, name))
    conf = (
        "[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + WORK.replace("\\", "\\\\") + "\n"
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
        s = socket.create_connection(("127.0.0.1", 23946), timeout=5)
        s.settimeout(2)
        try:
            s.recv(65536)
        except Exception:
            pass

        def send(cmd):
            s.sendall((cmd + "\n").encode())
            time.sleep(0.5)
            try:
                s.recv(65536)
            except Exception:
                pass

        send("key 6")            # sound off
        for step in range(1, a.steps + 1):
            time.sleep(1.2)
            send("key enter")
            time.sleep(1.5)
            dump = os.path.join(WORK, "frame.bin")
            send("dump A0000 10000 " + dump.replace("\\", "\\\\"))
            time.sleep(0.6)
            if not os.path.exists(dump):
                continue
            d = open(dump, "rb").read()
            mini = sum(d[y * 320 + x] for y in range(5, 70)
                       for x in range(250, 318))
            text = sum(d[y * 320 + x] for y in range(160, 198)
                       for x in range(5, 315))
            if mini > 800000 and text > 1500000:
                from PIL import Image
                img = Image.frombytes("P", (320, 200), d[:64000])
                pal = []
                for i in range(256):
                    pal += [i, i, i]
                img.putpalette(pal)
                img.convert("RGB").resize((640, 400)).save(
                    os.path.join(ROOT, "tmp", "boot_game.png"))
                print("IN GAME at step %d (mini=%d text=%d)"
                      % (step, mini, text))
                print("saved tmp/boot_game.png")
                return
        raise SystemExit("did not reach the map screen")
    finally:
        p.terminate()
        try:
            p.wait(timeout=5)
        except Exception:
            p.kill()


if __name__ == "__main__":
    main()
