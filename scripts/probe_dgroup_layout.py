"""Measure the recovered DGROUP layout against the original's addresses.

The original (audit/symbols.tsv) places these at fixed DGROUP offsets:

    AnimSeqCounts    2410:5dc8
    lowIntelEnemies  2410:5dcf   (7 bytes after AnimSeqCounts)
    medIntelEnemies  2410:5dd7   (15)
    highIntelEnemies 2410:5ddf   (23)
    secondWaveSize   2410:5de7   (31)

ovc30_nextWave reads the four difficulty-indexed count tables at 0x5dcb,
0x5dd3, 0x5ddb and 0x5de3, i.e. in the 4-byte gaps before each spread table.
Those tables have no symbol in the Ghidra project and the exported C declares
the spread globals as single bytes, so the rebuilt DGROUP is dense unless
something fills the gaps.  The probe prints each measured delta as one digit
(no printf: CM.LIB's vprinter needs __REALCVT, which overflows in this link).
"""
import io
import os
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
B = os.path.join(ROOT, "tmp", "buildsrc")
BC = os.path.join(ROOT, "tools", "BC30")

PROBE = r'''extern unsigned char AnimSeqCounts[3];
extern unsigned char lowIntelEnemies;
extern unsigned char medIntelEnemies;
extern unsigned char highIntelEnemies;
extern unsigned char secondWaveSize;
void digit(unsigned v)
{
  asm { mov ah,2; mov dl,byte ptr v; add dl,'0'; int 21h };
}
void nl(void)
{
  asm { mov ah,2; mov dl,10; int 21h };
}
int main(void)
{
  digit((unsigned)((char *)&lowIntelEnemies - (char *)&AnimSeqCounts));
  nl();
  digit((unsigned)((char *)&medIntelEnemies - (char *)&lowIntelEnemies));
  nl();
  digit((unsigned)((char *)&highIntelEnemies - (char *)&medIntelEnemies));
  nl();
  digit((unsigned)((char *)&secondWaveSize - (char *)&highIntelEnemies));
  nl();
  return 0;
}
'''
io.open(os.path.join(B, "PB.C"), "w", encoding="ascii", newline="\r\n").write(PROBE)

globs = sorted(n for n in os.listdir(B)
               if n.upper().startswith("GLOB") and n.lower().endswith(".obj"))
rsp = ("D:\\LIB\\C0M.OBJ PB.OBJ " + " ".join(globs) +
       "\r\nPB.EXE\r\nPB.MAP\r\nD:\\LIB\\CM.LIB")
io.open(os.path.join(B, "PB.RSP"), "w", encoding="ascii", newline="").write(rsp + "\r\n")

for n in ("PB.OBJ", "PB.EXE", "PB.MAP", "PB.LNK", "PB.OUT", "PB.LOG"):
    p = os.path.join(B, n)
    if os.path.exists(p):
        os.remove(p)

io.open(os.path.join(B, "PB.BAT"), "w", encoding="ascii", newline="\r\n").write(
    "@echo off\r\nset PATH=D:\\BIN\r\nset INCLUDE=D:\\INCLUDE\r\n"
    "D:\\BIN\\BCC.EXE -mm -1 -G -O -c -w- -a- -I. PB.C > PB.LOG\r\n"
    "D:\\BIN\\TLINK.EXE @PB.RSP > PB.LNK\r\n"
    "PB.EXE > PB.OUT\r\n"
    "echo DONE >> PB.OUT\r\n")

conf = ["[sdl]", "output = surface", "[dosbox]", "machine = svga_s3", "memsize = 16",
        "[cpu]", "core = normal", "cputype = 386", "cycles = max",
        "[mixer]", "nosound = true", "[autoexec]",
        "mount c " + B, "mount d " + BC, "c:", "call PB.BAT", "exit"]
path = os.path.join(ROOT, "tmp", "probe_layout.conf")
io.open(path, "w", encoding="ascii", newline="\r\n").write("\n".join(conf) + "\n")
subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                "--conf", path, "--wait", "60"], check=False)

out = os.path.join(B, "PB.OUT")
txt = io.open(out, "rb").read().decode("latin-1", "replace") if os.path.exists(out) else "(no output)"
print("deltas (want 7, 8, 8, 8):")
print(txt)
lnk = os.path.join(B, "PB.LNK")
if os.path.exists(lnk):
    errs = [l.strip() for l in io.open(lnk, encoding="latin-1",
                                       errors="replace").read().splitlines() if "rror" in l]
    print("link errors:", errs[:3] if errs else "none")
