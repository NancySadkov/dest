"""Is the INT 3Fh vector installed, and is it entered by the first overlay call?

After `_OVRINIT` succeeds the manager should have installed its INT 3Fh handler.
This reads the IVT entry, then replaces it with a probe that appends 'H' to
DBG.TXT and spins, so the marker survives the inevitable hang.

Expected DBG.TXT if everything upstream is right:  A0IVH...

usage: python tmp/ovr_vec.py [--revert]
"""
import io
import os
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
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

PROBE = '''
/* Probe INT 3Fh handler: mark and spin, so the marker survives the hang. */
void st_probe3f(void)
{
  st_dbg('H');
  for (;;) {
  }
}
'''

t = io.open(SRC, encoding="latin-1").read()
if "st_dbg" not in t:
    t = t.replace("void startx(void)", HELPER + PROBE + "\nvoid startx(void)", 1)
    t = t.replace('#include "recovered.h"',
                  '#include "recovered.h"\n\n'
                  'int __cdecl16far _OVRINIT(char far *exename, uint16_t bufend, uint16_t bufbeg);',
                  1)
    a = "  /* __setargv is not recovered yet"
    block = (
        "  {\n"
        "    uint16_t bufseg = 0;\n"
        "    uint16_t fl = 0;\n"
        "    uint16_t vecOfs = 0, vecSeg = 0;\n"
        "    int rc;\n\n"
        "    asm {\n"
        "      mov ah,48h;\n"
        "      mov bx,2000h;\n"
        "      int 21h;\n"
        "      mov bufseg,ax;\n"
        "      pushf;\n"
        "      pop ax;\n"
        "      mov fl,ax;\n"
        "    }\n"
        "    st_dbg((char)('A' + (fl & 1)));\n"
        "    rc = _OVRINIT((char far *)\"STRONG.EXE\",\n"
        "                  (uint16_t)(bufseg + 0x2000), bufseg);\n"
        "    st_dbg((char)('0' + (rc & 7)));\n"
        "    asm {\n"
        "      mov ax,0;\n"
        "      mov es,ax;\n"
        "      mov ax,es:[0FCh];\n"
        "      mov vecOfs,ax;\n"
        "      mov ax,es:[0FEh];\n"
        "      mov vecSeg,ax;\n"
        "    }\n"
        "    st_dbg(vecSeg ? 'V' : 'v');\n"
        "    st_dbg(vecOfs ? 'O' : 'o');\n"
        "    {\n"
        "      uint16_t pofs = (uint16_t)st_probe3f;\n"
        "      asm {\n"
        "        cli;\n"
        "        xor ax,ax;\n"
        "        mov es,ax;\n"
        "        mov ax,pofs;\n"
        "        mov word ptr es:[0FCh],ax;\n"
        "        mov word ptr es:[0FEh],cs;\n"
        "        sti;\n"
        "      }\n"
        "    }\n"
        "    st_dbg('P');\n"
        "  }\n\n")
    t = t.replace(a, block + a, 1)
    io.open(SRC, "w", encoding="latin-1", newline="\n").write(t)

s = io.open(HDR, encoding="latin-1").read()
if "st_dbg" not in s:
    s = s.replace("extern uint16_t GRecordCount;",
                  "extern uint16_t GRecordCount;\nvoid st_dbg(char c);", 1)
    io.open(HDR, "w", encoding="latin-1", newline="").write(s)

m = io.open(MAIN, encoding="latin-1").read()
if "st_dbg" not in m:
    i = m.index("  ovr_init_game();")
    m = m[:i] + "  st_dbg('I');\n" + m[i:]
    i = m.index("  ovr_init_game();") + len("  ovr_init_game();")
    m = m[:i] + "\n  st_dbg('J');" + m[i:]
    io.open(MAIN, "w", encoding="latin-1", newline="\n").write(m)
print("vector probe inserted")

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
subprocess.run([sys.executable, os.path.join(ROOT, "tmp", "exact_code.py")],
               stdout=subprocess.DEVNULL)
d = open(os.path.join(ROOT, "tmp", "runcode", "RUN.LOG"), "rb").read()
first = [l for l in d.splitlines() if l.startswith(b"CODE=")]
print("result ->", first[0].decode() if first else "no code (hang)")
dbg = os.path.join(ROOT, "tmp", "runcode", "DBG.TXT")
print("DBG.TXT:", open(dbg, "rb").read() if os.path.exists(dbg) else "missing")
print("STRONG.SAV", os.path.exists(os.path.join(ROOT, "tmp", "runcode", "STRONG.SAV")))
