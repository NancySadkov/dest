"""Ask DOS for the largest free conventional block (INT 21h, AH=48h, BX=FFFFh).

That is the real ceiling for a non-overlay EXE, measured instead of assumed.
Prints the paragraph count in hex, then a decimal KB figure would need division, so
hex is reported and converted here.
"""
import io
import os
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
B = os.path.join(ROOT, "tmp", "memprobe")
BC = os.path.join(ROOT, "tools", "BC30")
os.makedirs(B, exist_ok=True)

io.open(os.path.join(B, "M.C"), "w", encoding="ascii", newline="\r\n").write(
    "void puthex(unsigned v)\n"
    "{\n"
    "  int i;\n"
    "  unsigned char c;\n"
    "  for (i = 12; i >= 0; i -= 4) {\n"
    "    c = (unsigned char)((v >> i) & 0xF);\n"
    "    c = (unsigned char)(c < 10 ? '0' + c : 'A' + c - 10);\n"
    "    asm { mov ah,2; mov dl,byte ptr c; int 21h };\n"
    "  }\n"
    "}\n"
    "int main(void)\n"
    "{\n"
    "  unsigned paras = 0;\n"
    "  asm { mov ah,0x48; mov bx,0xffff; int 0x21; mov paras,bx };\n"
    "  puthex(paras);\n"
    "  asm { mov ah,2; mov dl,10; int 21h };\n"
    "  return 0;\n"
    "}\n")

io.open(os.path.join(B, "GO.BAT"), "w", encoding="ascii", newline="\r\n").write(
    "@echo off\r\nc:\r\ncd \\\r\n"
    "D:\\BIN\\BCC.EXE -ms -1 -G -O -c -w- M.C > M.LOG\r\n"
    "D:\\BIN\\TLINK.EXE D:\\LIB\\C0S.OBJ M.OBJ,M.EXE,,D:\\LIB\\CS.LIB > LK.LOG\r\n"
    "M.EXE > RUN.LOG\r\n"
    "echo DONE >> RUN.LOG\r\n")
for n in ("M.OBJ", "M.EXE", "M.LOG", "LK.LOG", "RUN.LOG"):
    p = os.path.join(B, n)
    if os.path.exists(p):
        os.remove(p)

conf = ["[sdl]", "output = surface", "[dosbox]", "machine = svga_s3", "memsize = 16",
        "[cpu]", "core = normal", "cputype = 386", "cycles = max",
        "[mixer]", "nosound = true", "[autoexec]",
        "mount c " + B, "mount d " + BC, "c:", "call GO.BAT", "exit"]
path = os.path.join(ROOT, "tmp", "memprobe.conf")
io.open(path, "w", encoding="ascii", newline="\r\n").write("\n".join(conf) + "\n")
subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                "--conf", path, "--wait", "30"], check=False)

log = os.path.join(B, "RUN.LOG")
txt = io.open(log, "rb").read().decode("latin-1", "replace") if os.path.exists(log) else ""
print("probe output:", repr(txt))
hexpart = ""
for ch in txt:
    if ch in "0123456789ABCDEF":
        hexpart += ch
    else:
        break
if len(hexpart) == 4:
    paras = int(hexpart, 16)
    print("largest free block: %d paragraphs = %d KB" % (paras, paras * 16 // 1024))
else:
    print("could not read the value")
