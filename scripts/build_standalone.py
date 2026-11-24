#!/usr/bin/env python3
"""Compile the recovered tree (src/decompiled) with Turbo C++ 3.0, one module
at a time, and report a per-module result.

This is the compile ratchet for AGENTS.md step 3: it never claims more than the
compiler accepts.  Each module is compiled in its own TCC invocation so one
failure cannot hide another, and the log for each is kept.

Pipeline
  scripts/stage_build.py      -> tmp/buildsrc (8.3 names, st.h aggregate)
  DOSBox + TCC.EXE            -> tmp/buildsrc/<mod>.obj and <mod>.log
  tmp/build_report.tsv        -> module, status, errors, first diagnostic

Usage
  python scripts/build_standalone.py                 # every module
  python scripts/build_standalone.py --only main     # one module
  python scripts/build_standalone.py --keep-stage    # reuse tmp/buildsrc
  python scripts/build_standalone.py --wait 900

Exit status is 0 only when every module compiled.
"""
import argparse
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BUILDSRC = os.path.join(ROOT, "tmp", "buildsrc")
TC = os.path.join(ROOT, "tools", "BC30")   # BCC 3.0: the VROOMM compiler
REPORT = os.path.join(ROOT, "tmp", "build_report.tsv")

# TC 3.0 flags: large model (all pointers far, matching the original), 80186
# instructions, and the same optimisation level recorded in doc/flat_build.md.
# -w- : warnings are not errors.  TC caps messages per function, so a function
# with many harmless warnings hits "Too many error or warning messages" before
# its real errors are printed; suppressing warnings makes the report accurate.
CFLAGS = "-mm -1 -G -O -Z -d -c -w- -a- -I. -ID:\\INCLUDE"   # no -V; -Z/-d shrink the image


def stage():
    subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "stage_build.py")],
                   check=True, stdout=subprocess.DEVNULL)


def modules():
    return sorted(n for n in os.listdir(BUILDSRC) if n.lower().endswith(".c"))


def write_batch(mods):
    bat = ["@echo off", "set INCLUDE=D:\\INCLUDE", "set PATH=D:\\BIN"]
    for m in mods:
        stem = m[:-2]
        bat.append('D:\\BIN\\BCC.EXE %s %s > %s.log' % (CFLAGS, m, stem))
    # overlay thunks are assembly (jmp far to the resident routine)
    if os.path.isfile(os.path.join(BUILDSRC, "ovr.asm")):
        bat.append('E:\\BIN\\TASM.EXE /zi /m2 ovr.asm > ovr.log')
    bat.append("echo done > DONE.FLG")
    with open(os.path.join(BUILDSRC, "BUILD.BAT"), "w", encoding="ascii",
              newline="\r\n") as f:
        f.write("\n".join(bat) + "\n")
    conf = [
        "[sdl]", "output = surface",
        "[dosbox]", "machine = svga_s3", "memsize = 16",
        "[cpu]", "core = normal", "cputype = 386", "cycles = max",
        "[mixer]", "nosound = true",
        "[autoexec]",
        "mount c " + BUILDSRC,
        "mount d " + os.path.join(TC),
        "mount e " + os.path.join(ROOT, "tools", "BC30"),
        "c:",
        "call BUILD.BAT",
    ]
    path = os.path.join(ROOT, "tmp", "build_tcc.conf")
    with open(path, "w", encoding="ascii", newline="\r\n") as f:
        f.write("\n".join(conf) + "\n")
    return path


def parse_log(path):
    """Return (errors, warnings, first message)."""
    if not os.path.exists(path):
        return (0, 0, "no log")
    text = open(path, "r", encoding="ascii", errors="replace").read()
    errs = len(re.findall(r"Error", text, re.I))
    warns = len(re.findall(r"Warning", text, re.I))
    first = ""
    for line in text.splitlines():
        s = line.strip()
        if not s:
            continue
        if re.search(r"(Error|Warning)", s, re.I):
            first = s
            break
    return (errs, warns, first)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", help="compile a single staged module (e.g. main)")
    ap.add_argument("--keep-stage", action="store_true")
    ap.add_argument("--wait", type=int, default=1200)
    a = ap.parse_args()

    if not a.keep_stage or not os.path.isdir(BUILDSRC):
        stage()
    mods = modules()
    if a.only:
        want = a.only if a.only.endswith(".c") else a.only + ".c"
        mods = [m for m in mods if m.lower() == want.lower()]
        if not mods:
            raise SystemExit("no staged module named " + want)
    for m in mods:
        for ext in (".obj", ".log"):
            try:
                os.remove(os.path.join(BUILDSRC, m[:-2] + ext))
            except FileNotFoundError:
                pass
    try:
        os.remove(os.path.join(BUILDSRC, "DONE.FLG"))
    except FileNotFoundError:
        pass

    conf = write_batch(mods)
    subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", conf, "--wait", str(a.wait),
                    "--until", os.path.join(BUILDSRC, "DONE.FLG")], check=True)

    rows = []
    for m in mods:
        stem = m[:-2]
        obj = os.path.join(BUILDSRC, stem + ".obj")
        errs, warns, first = parse_log(os.path.join(BUILDSRC, stem + ".log"))
        ok = os.path.exists(obj)
        status = "ok" if ok else "FAIL"
        rows.append((m, status, errs, warns, first))

    with open(REPORT, "w", encoding="utf-8", newline="\n") as f:
        f.write("module\tstatus\terrors\twarnings\tfirst\n")
        for r in rows:
            f.write("%s\t%s\t%d\t%d\t%s\n" % r)

    good = sum(1 for r in rows if r[1] == "ok")
    print("compiled %d/%d modules" % (good, len(rows)))
    for m, st, e, w, first in rows:
        if st != "ok":
            print("  FAIL %-10s errors=%d  %s" % (m, e, first[:110]))
    print("report: " + REPORT)
    return 0 if good == len(rows) else 1


if __name__ == "__main__":
    sys.exit(main())
