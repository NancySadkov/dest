"""Use the ORIGINAL STRONG.EXE as the oracle for the probe method.

The rebuilt binary's call site refuses to respond to an exit stub while earlier
instructions do.  Before concluding anything about the rebuild, run the identical
technique on the original, whose call path is known to work (it creates
STRONG.SAV):

  control   main's entry        1301:000C  -> file 0x4E1C
  probe     lcall init_game     1301:005C  -> file 0x4E60   (9A 25 00 E3 12)
  probe     lcall run_demo      1301:0061  -> file 0x4E65   (9A 20 00 E3 13)

If the original answers CODE=N at those addresses, the technique is sound and a
"no code" answer from the rebuild is a real result.  If the original also answers
"no code", the technique itself is what is broken.

usage: python tmp/oracle_probe.py [entry|init|demo]
"""
import io
import os
import shutil
import struct
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
ORIG = os.path.join(ROOT, "game", "STRONG.EXE")
RUN = os.path.join(ROOT, "tmp", "oracle")

SITES = {"entry": 0x4E1C, "init": 0x4E60, "demo": 0x4E65}


def drop_relocs(b, lo, hi):
    n = struct.unpack("<H", b[6:8])[0]
    off = struct.unpack("<H", b[0x18:0x1a])[0]
    keep = []
    for k in range(n):
        o, s = struct.unpack("<HH", b[off + 4 * k:off + 4 * k + 4])
        if lo <= o < hi:
            continue
        keep.append((o, s))
    b[off:off + 4 * n] = b"\0" * (4 * n)
    for k, (o, s) in enumerate(keep):
        struct.pack_into("<HH", b, off + 4 * k, o, s)
    struct.pack_into("<H", b, 6, len(keep))
    return n - len(keep)


def run(which, code):
    if os.path.isdir(RUN):
        shutil.rmtree(RUN)
    os.makedirs(RUN)
    b = bytearray(open(ORIG, "rb").read())
    img = struct.unpack("<H", b[8:10])[0] * 16
    at = SITES[which]
    print("site %s: file 0x%x  bytes %s" % (which, at, b[at:at + 6].hex(" ")))
    removed = drop_relocs(b, at - img, at - img + 5)
    b[at:at + 5] = bytes([0xB8, code, 0x4C, 0xCD, 0x21])
    open(os.path.join(RUN, "STRONG.EXE"), "wb").write(b)
    for n in ("STRONG.DAT", "STRONG.FLI"):
        p = os.path.join(ROOT, "game", n)
        if os.path.exists(p):
            shutil.copyfile(p, os.path.join(RUN, n))
    bat = ["@echo off", "c:", "cd \\", "STRONG.EXE > RUN.LOG"]
    bat += ["if errorlevel %d echo CODE=%d >> RUN.LOG" % (n, n) for n in range(255, 0, -1)]
    bat += ["if not errorlevel 1 echo CODE=0 >> RUN.LOG", "echo DONE >> RUN.LOG"]
    io.open(os.path.join(RUN, "GO.BAT"), "w", encoding="ascii",
            newline="\r\n").write("\n".join(bat) + "\n")
    conf = ["[sdl]", "output = surface", "[dosbox]", "machine = svga_s3",
            "memsize = 16", "[cpu]", "core = normal", "cputype = 386",
            "cycles = max", "[mixer]", "nosound = true", "[autoexec]",
            "mount c " + RUN, "c:", "call GO.BAT"]
    path = os.path.join(ROOT, "tmp", "oracle.conf")
    io.open(path, "w", encoding="ascii", newline="\r\n").write("\n".join(conf) + "\n")
    subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", path, "--wait", "45"], stdout=subprocess.DEVNULL)
    log = os.path.join(RUN, "RUN.LOG")
    d = open(log, "rb").read() if os.path.exists(log) else b""
    first = [l for l in d.splitlines() if l.startswith(b"CODE=")]
    sav = os.path.exists(os.path.join(RUN, "STRONG.SAV"))
    print("%-6s -> %s   STRONG.SAV=%s  (dropped %d reloc)"
          % (which, first[0].decode() if first else "no code", sav, removed))


for which in (sys.argv[1:] or ["entry", "init", "demo"]):
    run(which, 0x51)
