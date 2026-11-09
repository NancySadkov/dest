#!/usr/bin/env python3
"""Deterministic in-game boot and DGROUP capture.

Two runs are made deterministic by:
  * synthesizing the DOS clock/date,
  * fixed CPU cycles,
  * halting at the sound prompt and resetting all start/timer fields,
  * advancing an exact instruction count with the harness `step` command.

Usage:
  python scripts/fbov/boot_game_det.py --exe out/STRONG.EXE --mem-out tmp/a.bin
  python scripts/fbov/boot_game_det.py --compare out/STRONG.EXE out/STRONG_FUNC.EXE
"""
import argparse
import os
import re
import shutil
import socket
import struct
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
WORK = os.path.join(ROOT, "tmp", "det_game")


def start(exe):
    os.makedirs(WORK, exist_ok=True)
    subprocess.run(["powershell", "-NoProfile", "-Command",
                    "Get-Process | Where-Object {$_.ProcessName -match 'dosbox'} | "
                    "Stop-Process -Force -ErrorAction SilentlyContinue"],
                   capture_output=True)
    for _ in range(10):
        try:
            shutil.copyfile(exe, os.path.join(WORK, "STRONG.EXE"))
            break
        except PermissionError:
            time.sleep(1)
    else:
        raise SystemExit("cannot replace " + os.path.join(WORK, "STRONG.EXE"))
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
    path = os.path.join(WORK, "run.conf")
    open(path, "w").write(conf)
    subprocess.run(["powershell", "-NoProfile", "-Command",
                    "Get-Process | Where-Object {$_.ProcessName -match 'dosbox'} | "
                    "Stop-Process -Force -ErrorAction SilentlyContinue"],
                   capture_output=True)
    time.sleep(0.4)
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", path, "--wait", "4", "--keep"], check=True)
    return socket.create_connection(("127.0.0.1", 23946), timeout=10)


def send(s, cmd, wait=0.3):
    s.sendall((cmd + "\n").encode())
    time.sleep(wait)
    out = b""
    try:
        while True:
            out += s.recv(65536)
    except Exception:
        pass
    return out


def capture(exe, mem_out):
    s = start(exe)
    s.settimeout(2)
    try:
        s.recv(65536)
    except Exception:
        pass
    send(s, "halt", 0.4)
    d = send(s, "regs")
    m = re.search(rb"DS=([0-9A-Fa-f]+)", d)
    if not m:
        raise SystemExit("DS missing")
    ds = int(m.group(1), 16)

    # Reset the start clock and every timer field that differed between runs.
    send(s, "poked %X 0" % (ds * 16 + 0x81))       # _StartTime
    send(s, "poked %X 0" % (0x40 * 16 + 0x6C))     # BIOS tick counter
    for off in (0x8986, 0x898A, 0x9070):
        send(s, "poked %X 0" % (ds * 16 + off))
    send(s, "pokeb %X 0" % (ds * 16 + 0x8934))
    send(s, "poked %X 0" % (ds * 16 + 0x9001))
    send(s, "pokeb %X 0" % (ds * 16 + 0x7144))

    send(s, "run", 0.2)
    send(s, "key 6", 0.2)
    frame = os.path.join(WORK, "frame.bin")
    at_map = False
    for step in range(12):
        if step:
            send(s, "key enter", 0.2)
        send(s, "step 20000000", 0.1)
        out = send(s, "run", 0.2)
        t0 = time.time()
        while b"STEPS done" not in out and time.time() - t0 < 15:
            try:
                out += s.recv(65536)
            except Exception:
                pass
        s.sendall(("dump A0000 10000 " +
                   frame.replace("\\", "\\\\") + "\n").encode())
        time.sleep(0.8)
        try:
            s.recv(65536)
        except Exception:
            pass
        v = open(frame, "rb").read()
        mini = sum(v[y * 320 + x] for y in range(5, 70)
                   for x in range(250, 318))
        text = sum(v[y * 320 + x] for y in range(160, 198)
                   for x in range(5, 315))
        if mini > 800000 and text > 1500000:
            at_map = True
            break
    if not at_map:
        raise SystemExit("not at the map screen (mini=%d text=%d)"
                         % (mini, text))
    print("map after %d step(s)" % (step + 1))

    s.sendall(("dump %X 949A " % (ds * 16) +
               mem_out.replace("\\", "\\\\") + "\n").encode())
    time.sleep(1.2)
    try:
        s.recv(65536)
    except Exception:
        pass
    s.close()
    subprocess.run(["powershell", "-NoProfile", "-Command",
                    "Get-Process | Where-Object {$_.ProcessName -match 'dosbox'} | "
                    "Stop-Process -Force -ErrorAction SilentlyContinue"],
                   capture_output=True)
    return open(mem_out, "rb").read()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--exe")
    ap.add_argument("--mem-out", default=os.path.join(ROOT, "tmp",
                                                      "det_mem.bin"))
    ap.add_argument("--compare", nargs=2, metavar=("EXE_A", "EXE_B"))
    a = ap.parse_args()

    if a.compare:
        outa = os.path.join(ROOT, "tmp", "det_a.bin")
        outb = os.path.join(ROOT, "tmp", "det_b.bin")
        ca = capture(a.compare[0], outa)
        cb = capture(a.compare[1], outb)
        d = [i for i in range(len(ca)) if ca[i] != cb[i]]
        print("DGROUP differing bytes:", len(d))
        for i in d[:20]:
            print("  %04X %02X %02X" % (i, ca[i], cb[i]))
        if d:
            raise SystemExit(1)
        return
    if not a.exe:
        raise SystemExit("--exe or --compare required")
    capture(a.exe, a.mem_out)
    print("saved", a.mem_out)


if __name__ == "__main__":
    main()
