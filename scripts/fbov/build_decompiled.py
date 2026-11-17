#!/usr/bin/env python3
"""Compile every staged module of the exported source tree with TC30.

Stages src/decompiled into tmp/buildsrc (8.3 names), writes a batch that
compiles every .c with Turbo C++ 3.0, runs it in DOSBox and summarises the
result.  This is the "whole tree compiles" gate for the behavioural recovery.

Usage:
  python scripts/fbov/build_decompiled.py [--wait 240] [--keep]
"""
import argparse
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
WORK = os.path.join(ROOT, "tmp", "buildsrc")
LOG = "buildall.log"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--wait", type=int, default=240)
    ap.add_argument("--keep", action="store_true")
    a = ap.parse_args()

    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "stage_build.py")],
                   check=True)
    mods = sorted(f for f in os.listdir(WORK) if f.endswith(".c"))
    lines = ["@echo off", "mode con lines=50",
             "del %s >nul 2>nul" % LOG,
             "echo === TC30 full tree === > %s" % LOG]
    for m in mods:
        obj = os.path.splitext(m)[0].upper() + ".OBJ"
        lines.append("D:\\BIN\\TCC.EXE -ml -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- "
                     "-c %s > %s.log" % (m, os.path.splitext(m)[0]))
        lines.append("if exist %s echo OK   %s>>%s"
                     % (obj, m, " buildall.log"))
        lines.append("if not exist %s echo FAIL %s>>%s"
                     % (obj, m, " buildall.log"))
    lines += ["echo done> buildall.done", "pause"]
    open(os.path.join(WORK, "buildall.bat"), "w", newline="").write(
        "\r\n".join(lines) + "\r\n")

    for m in mods:
        p = os.path.join(WORK, os.path.splitext(m)[0].upper() + ".OBJ")
        if os.path.exists(p):
            os.remove(p)
    conf = (
        "[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + WORK.replace("\\", "\\\\") + "\n"
        "mount d " + os.path.join(ROOT, "tools", "TC30").replace("\\", "\\\\") + "\n"
        "c:\ncall buildall.bat\n"
    )
    conf_path = os.path.join(ROOT, "tmp", "buildall.conf")
    open(conf_path, "w").write(conf)
    sentinel = os.path.join(WORK, "buildall.done")
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", conf_path, "--wait", str(a.wait),
                    "--until", sentinel], check=True)

    log = os.path.join(WORK, LOG)
    if not os.path.exists(log):
        raise SystemExit("no build log")
    text = open(log, encoding="latin1", errors="replace").read()
    ok = re.findall(r"^OK\s+(\S+)", text, re.M)
    bad = re.findall(r"^FAIL\s+(\S+)", text, re.M)
    for m in sorted(bad):
        print("FAIL", m)
    print("compiled %d/%d modules" % (len(ok), len(ok) + len(bad)))
    if bad:
        # Summarise the first error line of each failing module.
        for m in sorted(bad):
            base = os.path.splitext(m)[0]
            p = os.path.join(WORK, base + ".log")
            msg = ""
            if os.path.exists(p):
                for line in open(p, encoding="latin1", errors="replace"):
                    if "rror" in line and line.strip():
                        msg = line.strip()
                        break
            print("  %-12s %s" % (m, msg[:110]))
    if bad and not a.keep:
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
