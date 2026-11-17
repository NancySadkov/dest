#!/usr/bin/env python3
"""Compile every module of a clean source tree with TC30.

Stages a source directory with 8.3 filenames, compiles every .c with Turbo
C++ 3.0 in one DOSBox pass and reports which modules fail.

Usage:
  python scripts/fbov/build_tree.py [--src src/rebuild] [--wait 300]
"""
import argparse
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
LOG = "buildall.log"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--src", default=os.path.join(ROOT, "src", "rebuild"))
    ap.add_argument("--work", default=os.path.join(ROOT, "tmp", "buildtree"))
    ap.add_argument("--wait", type=int, default=300)
    a = ap.parse_args()

    work = os.path.abspath(a.work)
    src = os.path.abspath(a.src)
    shutil.rmtree(work, ignore_errors=True)
    os.makedirs(work)
    for f in sorted(os.listdir(src)):
        p = os.path.join(src, f)
        if os.path.isfile(p) and f.endswith((".c", ".h")):
            shutil.copyfile(p, os.path.join(work, f))
    mods = sorted(f for f in os.listdir(work) if f.endswith(".c"))

    lines = ["@echo off", "mode con lines=50",
             "del %s >nul 2>nul" % LOG,
             "echo === TC30 tree === > %s" % LOG]
    for m in mods:
        obj = os.path.splitext(m)[0].upper() + ".OBJ"
        base = os.path.splitext(m)[0]
        lines.append("D:\\BIN\\TCC.EXE -ml -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- "
                     "-c %s > %s.log" % (m, base))
        lines.append("if exist %s echo OK   %s>>%s" % (obj, m, LOG))
        lines.append("if not exist %s echo FAIL %s>>%s" % (obj, m, LOG))
    lines += ["echo done> buildall.done", "pause"]
    open(os.path.join(work, "buildall.bat"), "w", newline="").write(
        "\r\n".join(lines) + "\r\n")

    conf = (
        "[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + work.replace("\\", "\\\\") + "\n"
        "mount d " + os.path.join(ROOT, "tools", "TC30").replace("\\", "\\\\") + "\n"
        "c:\ncall buildall.bat\n"
    )
    conf_path = os.path.join(ROOT, "tmp", "buildtree.conf")
    open(conf_path, "w").write(conf)
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", conf_path, "--wait", str(a.wait),
                    "--until", os.path.join(work, "buildall.done")], check=True)

    t = open(os.path.join(work, LOG), encoding="latin1").read()
    ok = [l.split()[1] for l in t.splitlines() if l.startswith("OK")]
    bad = [l.split()[1] for l in t.splitlines() if l.startswith("FAIL")]
    for m in sorted(bad):
        base = os.path.splitext(m)[0]
        msg = ""
        p = os.path.join(work, base + ".log")
        if os.path.exists(p):
            for line in open(p, encoding="latin1", errors="replace"):
                if "rror" in line and line.strip():
                    msg = line.strip()
                    break
        print("FAIL %-10s %s" % (m, msg[:100]))
    print("compiled %d/%d modules" % (len(ok), len(ok) + len(bad)))
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main())
