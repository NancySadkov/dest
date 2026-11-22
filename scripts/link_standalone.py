"""Attempt a first link of the recovered tree and report what is missing.

Runs TLINK in DOSBox over every staged .obj with Turbo C's large-model startup
(c0l) and libraries, then prints the linker's error list.  This is the step that
turns "58/58 modules compile" into a concrete list of what still separates us
from a runnable REBUILT.EXE.
"""
import os
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
BUILDSRC = os.path.join(ROOT, "tmp", "buildsrc")
TC = os.path.join(ROOT, "tools", "TC30")


def main():
    skip = set(a.upper() for a in sys.argv[1:] if a.startswith("--skip=") is False)
    objs = sorted(n for n in os.listdir(BUILDSRC) if n.lower().endswith(".obj"))
    # Our tree contains a recovered CRT (crtl.c).  Linking Turbo C's C0L startup
    # and CL.LIB as well duplicates it, so the first link excludes the recovered
    # CRT object and lets the library provide those symbols.
    # The recovered CRT (crtl.c) is the program's own runtime, so it is linked by
    # default; --without-crtl reproduces the older, startup-only link.
    if "--without-crtl" in sys.argv:
        objs = [o for o in objs if o.upper() != "CRTL.OBJ"]
    print("objects:", len(objs), "(crtl excluded)" if "--without-crtl" in sys.argv else "")
    bat = ["@echo off", "set PATH=D:\\BIN", "set LIB=D:\\LIB"]
    # TLINK syntax: <objs>,<exe>,<map>,<libs>  -- the comma after the last object
    # is what separates inputs from outputs
    # printf("%f") pulls in the floating-point printer, which needs the emulator
    # library; without it TLINK reports a fixup overflow on __REALCVT.
    # C0M is the medium-model startup and must match -mm on the objects
    # (C0L is the large-model one).
    rsp = ("D:\\LIB\\C0M.OBJ " + " ".join(objs) +
           ",REBUILT.EXE,REBUILT.MAP,D:\\LIB\\OVERLAY.LIB E:\\LIB\\CM.LIB")
    with open(os.path.join(BUILDSRC, "LINK.RSP"), "w", encoding="ascii",
              newline="\r\n") as f:
        f.write(rsp + "\n")
    bat.append("D:\\BIN\\TLINK.EXE /o @LINK.RSP > LINK.LOG")   # /o: VROOMM overlays
    if os.path.exists(os.path.join(BUILDSRC, "LINK.LOG")):
        os.remove(os.path.join(BUILDSRC, "LINK.LOG"))
    for name in ("REBUILT.EXE", "REBUILT.MAP", "DONE.FLG"):
        p = os.path.join(BUILDSRC, name)
        if os.path.exists(p):
            os.remove(p)
    bat.append("echo done > DONE.FLG")
    with open(os.path.join(BUILDSRC, "LINK.BAT"), "w", encoding="ascii",
              newline="\r\n") as f:
        f.write("\n".join(bat) + "\n")

    conf = [
        "[sdl]", "output = surface",
        "[dosbox]", "machine = svga_s3", "memsize = 16",
        "[cpu]", "core = normal", "cputype = 386", "cycles = max",
        "[mixer]", "nosound = true",
        "[autoexec]",
        "mount c " + BUILDSRC,
        "mount d " + TC,
        "mount e " + os.path.join(ROOT, "tools", "BC30"),
        "c:",
        "call LINK.BAT",
        "exit",
    ]
    path = os.path.join(ROOT, "tmp", "link.conf")
    with open(path, "w", encoding="ascii", newline="\r\n") as f:
        f.write("\n".join(conf) + "\n")

    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", path, "--until",
                    os.path.join(BUILDSRC, "DONE.FLG"), "--wait", "180"],
                   check=False)

    log = os.path.join(BUILDSRC, "LINK.LOG")
    if os.path.exists(log):
        text = open(log, encoding="ascii", errors="replace").read()
        errors = [l for l in text.splitlines() if "rror" in l or "ndefined" in l]
        print("--- LINK.LOG:", len(errors), "error/undefined lines")
        for line in errors[:20]:
            print("   ", line.strip()[:110])
        for line in text.splitlines()[-6:]:
            print("   ", line.strip()[:110])
    exe = os.path.join(BUILDSRC, "REBUILT.EXE")
    print("REBUILT.EXE exists:", os.path.exists(exe),
          os.path.getsize(exe) if os.path.exists(exe) else "")


main()
