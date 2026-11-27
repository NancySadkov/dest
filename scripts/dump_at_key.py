"""Sample DGROUP at the Nth BIOS key read - a third runtime point, past `_INIT_CFG`.

`tmp/dump_at.py` patches a function's entry, which only reaches resident code; the original's interactive
paths go through VROOMM thunks that are packed and relocated at load.  This harness patches nothing: it
installs the INT 16h TSR from tmp/make_dump_tsr.py, which counts AH=00 calls and writes the caller's
64 KB (DS:0) to handle 1 on the Nth one.  The batch file redirects stdout to DGR.BIN, so the dump lands in
a file exactly as with the other harnesses.

Usage: python tmp/dump_at_key.py [N]      (default 2)
Writes tmp/dgrun2_orig/DGR.BIN and tmp/dgrun2_ours/DGR.BIN, so scripts/compare_runtime.py runs unchanged.
"""

import importlib
import os
import shutil
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
N = sys.argv[1] if len(sys.argv) > 1 else "2"

sys.path.insert(0, os.path.join(ROOT, "scripts"))
tsr = importlib.import_module("make_dump_tsr")


def build_tsr(n):
    """Re-run make_dump_tsr with this N and return its image bytes."""
    saved = sys.argv
    sys.argv = ["make_dump_tsr.py", str(n), os.path.join(ROOT, "tmp", "DUMPTSR.COM")]
    try:
        importlib.reload(tsr)
        return open(os.path.join(ROOT, "tmp", "DUMPTSR.COM"), "rb").read()
    finally:
        sys.argv = saved


def run(tag, exe_path):
    d = os.path.join(ROOT, "tmp", "dgrun2_" + tag)
    if os.path.isdir(d):
        shutil.rmtree(d)
    os.makedirs(d)
    shutil.copyfile(exe_path, os.path.join(d, "STRONG.EXE"))
    for n in ("STRONG.DAT", "STRONG.FLI"):
        p = os.path.join(ROOT, "game", n)
        if os.path.exists(p):
            shutil.copyfile(p, os.path.join(d, n))
    open(os.path.join(d, "KEY.COM"), "wb").write(build_tsr(N))
    os.makedirs(os.path.join(d, "strong.sav"), exist_ok=True)
    open(os.path.join(d, "strong.sav", "game.cfg"), "wb").write(b"111")
    bat = ["@echo off", "c:", "cd \\", "KEY.COM", "STRONG.EXE > DGR.BIN", "echo DONE > DONE.FLG"]
    open(os.path.join(d, "GO.BAT"), "w", encoding="ascii", newline="\r\n").write("\n".join(bat) + "\n")
    conf = ["[sdl]", "output = surface", "[dosbox]", "machine = svga_s3", "memsize = 16",
            "[cpu]", "core = normal", "cputype = 386", "cycles = max",
            "[mixer]", "nosound = true", "[autoexec]",
            "mount c " + d, "c:", "call GO.BAT"]
    path = os.path.join(ROOT, "tmp", "dgrun2_%s.conf" % tag)
    open(path, "w", encoding="ascii", newline="\r\n").write("\n".join(conf) + "\n")
    subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", path, "--wait", "40"], check=False)
    out = os.path.join(d, "DGR.BIN")
    data = open(out, "rb").read() if os.path.exists(out) else None
    print("%s: %s" % (tag, ("%d bytes" % len(data)) if data else "no dump"))
    return data


o = run("orig", os.path.join(ROOT, "game", "STRONG.EXE"))
u = run("ours", os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.EXE"))
if not o or not u:
    raise SystemExit("a dump is missing - try a different N")
