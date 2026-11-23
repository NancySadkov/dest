"""Did the O09 overlay actually load and take control?

Patch-probing inside the manager gave inconsistent results, so observe the effect
instead: put an exit stub at the *entry of the overlay code* (the blob the
manager reads from the EXE) and see whether the program exits with that code.

  thunk  -> O09_SEG stub  CD 3F <id> <ofs>
  manager loads the block from the EXE at the CSV's file offset
  manager far-jumps to code_seg:<ofs>

Patching the blob in the file therefore patches the loaded copy.  An exit stub
has no segment operands, so relocations cannot corrupt it, and a normal exit
flushes RUN.LOG (unlike the DBG cursor channel).

usage: python tmp/ovr_blob.py [--revert]
"""
import io
import os
import re
import struct
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
EXE = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.EXE")
MAP = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.MAP")
SRC = os.path.join(ROOT, "src", "decompiled", "crtl.c")
MAIN = os.path.join(ROOT, "src", "decompiled", "main.c")
GLOB = os.path.join(ROOT, "src", "decompiled", "st_globals5.c")
HDR = os.path.join(ROOT, "src", "decompiled", "st_globals.h")

if "--revert" in sys.argv:
    subprocess.run(["git", "checkout", "--", SRC, MAIN, GLOB, HDR], cwd=ROOT, check=False)
    print("reverted")
    raise SystemExit

spec = io.open(os.path.join(ROOT, "tmp", "ovr_dbg.py"), encoding="utf-8").read()
HELPER = spec.split("HELPER = '''")[1].split("'''")[0]

t = io.open(SRC, encoding="latin-1").read()
if "st_dbg" not in t:
    t = t.replace("void startx(void)", HELPER + "\nvoid startx(void)", 1)
    t = t.replace('#include "recovered.h"',
                  '#include "recovered.h"\n\n'
                  'int __cdecl16far _OVRINIT(char far *exename, uint16_t bufend, uint16_t bufbeg);',
                  1)
    a = "  /* __setargv is not recovered yet"
    block = (
        "  {\n"
        "    uint16_t bufseg = 0;\n"
        "    int rc;\n\n"
        "    asm { mov ah,48h; mov bx,2000h; int 21h; mov bufseg,ax }\n"
        "    rc = _OVRINIT((char far *)\"STRONG.EXE\",\n"
        "                  (uint16_t)(bufseg + 0x2000), bufseg);\n"
        "    st_dbg((char)('0' + (rc & 7)));\n"
        "  }\n\n")
    t = t.replace(a, block + a, 1)
    io.open(SRC, "w", encoding="latin-1", newline="\n").write(t)

s = io.open(HDR, encoding="latin-1").read()
if "st_dbg" not in s:
    s = s.replace("extern uint16_t GRecordCount;",
                  "extern uint16_t GRecordCount;\nvoid st_dbg(char c);", 1)
    io.open(HDR, "w", encoding="latin-1", newline="").write(s)

subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "build_standalone.py"),
                "--wait", "3000"], stdout=subprocess.DEVNULL)
rows = [l.rstrip("\n").split("\t")
        for l in io.open(os.path.join(ROOT, "tmp", "build_report.tsv"), encoding="utf-8")][1:]
print("clean %d errors %d" % (sum(1 for r in rows if r[1] == "ok"),
                              sum(int(r[2]) for r in rows)))
for r in rows:
    if r[1] != "ok":
        print(" ", r[0], r[4][:120])
subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "link_standalone.py")],
               stdout=subprocess.DEVNULL)

base_exe = open(EXE, "rb").read()
img = struct.unpack("<H", base_exe[8:10])[0] * 16

# O09 :OVY block from the regenerated table
rows_csv = [l.rstrip("\n").split("\t")
            for l in io.open(os.path.join(ROOT, "audit", "overlay_blocks.csv"),
                             encoding="utf-8")][1:]
code_off = None
for f in rows_csv:
    if f[0] == "9" and f[4] == ":OVY":
        code_off = int(f[2], 16)
print("O09 :OVY image offset 0x%x" % code_off)

# the stub at O09_SEG:0048 says which offset inside the block to enter
mm = re.search(r"^\s*([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+O09_SEG\s+STUBSEG",
               io.open(MAP, encoding="latin-1", errors="replace").read(), re.M)
stub = int(mm.group(1), 16) + 0x48
print("O09 stub bytes:", base_exe[img + stub:img + stub + 5].hex(" "))
enter = base_exe[img + stub + 3] | (base_exe[img + stub + 4] << 8)
print("entry offset inside the block: 0x%x" % enter)

for label, off in (("block start", 0), ("entry offset", enter)):
    b = bytearray(base_exe)
    at = img + code_off + off
    b[at:at + 5] = bytes.fromhex("b8554ccd21")
    open(EXE, "wb").write(b)
    subprocess.run([sys.executable, os.path.join(ROOT, "tmp", "exact_code.py")],
                   stdout=subprocess.DEVNULL)
    d = open(os.path.join(ROOT, "tmp", "runcode", "RUN.LOG"), "rb").read()
    first = [l for l in d.splitlines() if l.startswith(b"CODE=")]
    print("%-12s +0x%-4X -> %s" % (label, off, first[0].decode() if first else "no code"))

open(EXE, "wb").write(base_exe)
