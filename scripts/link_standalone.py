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
TC = os.path.join(ROOT, "tools", "BC30")   # TLINK + libs from BC++ 3.0


def main():
    skip = set(a.upper() for a in sys.argv[1:] if a.startswith("--skip=") is False)
    objs = sorted(n for n in os.listdir(BUILDSRC) if n.lower().endswith(".obj"))
    # EXCLUDE_OBJS=OVL.OBJ,OVR.OBJ lets the overlay experiments drop modules
    # compiler machinery is provided by the toolchain, not by our recovery
    DEFAULT_EXCLUDE = "OVL.OBJ"
    _excl = [x.strip().upper() for x in
             (os.environ.get("EXCLUDE_OBJS", DEFAULT_EXCLUDE)).split(",")
             if x.strip()]
    if _excl:
        objs = [o for o in objs if o.upper() not in _excl]
        print("excluding:", ", ".join(_excl))
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
    # Resident: the startup, the recovered CRT, the drivers, the globals and the
    # overlay thunks.  Everything else (the recovered game modules O01..O50) becomes
    # an overlay - TLINK's /o applies to the modules that follow it.
    RESIDENT = ("CRTL.OBJ", "MAIN.OBJ", "MOUSE.OBJ", "VIDEO.OBJ", "OVL.OBJ",
                "STUBS.OBJ", "INTRINS.OBJ", "OVR.OBJ")
    def is_resident(n):
        u = n.upper()
        return u in RESIDENT or u.startswith("GLOB")

    res = [o for o in objs if is_resident(o)]
    ovl = [o for o in objs if not is_resident(o)]
    rsp = ("D:\\LIB\\C0M.OBJ " + " ".join(res) + " /o " + " ".join(ovl) +
           " /m /s" + ",REBUILT.EXE,REBUILT.MAP,D:\\LIB\\OVERLAY.LIB D:\\LIB\\CM.LIB")
    with open(os.path.join(BUILDSRC, "LINK.RSP"), "w", encoding="ascii",
              newline="\r\n") as f:
        f.write(rsp + "\n")
    bat.append("D:\\BIN\\TLINK.EXE @LINK.RSP > LINK.LOG")
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
