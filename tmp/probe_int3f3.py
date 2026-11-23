"""INT 3Fh probe with a non-static handler (so it is not eliminated).

usage: python tmp/probe_int3f3.py [--revert]
"""
import io
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"

if "--revert" in sys.argv:
    subprocess.run(["git", "checkout", "--", "src/decompiled/crtl.c",
                    "src/decompiled/st_globals5.c", "src/decompiled/st_globals.h"],
                   cwd=ROOT, check=False)
    print("reverted")
    raise SystemExit

p = ROOT + r"\src\decompiled\st_globals5.c"
t = io.open(p, encoding="latin-1").read()
if 'st_traceCh' not in t:
    t = t.replace('uint16_t GRecordCount = 0x0000;',
                  'uint16_t GRecordCount = 0x0000;\nvolatile char st_traceCh;', 1)
    io.open(p, "w", encoding="latin-1", newline="").write(t)

p = ROOT + r"\src\decompiled\st_globals.h"
t = io.open(p, encoding="latin-1").read()
if 'st_traceCh' not in t:
    t = t.replace('extern uint16_t GRecordCount;',
                  'extern uint16_t GRecordCount;\nextern volatile char st_traceCh;', 1)
    io.open(p, "w", encoding="latin-1", newline="").write(t)

p = ROOT + r"\src\decompiled\crtl.c"
t = io.open(p, encoding="latin-1").read()

helper = '''
/* Probe handler for the VROOMM stub interrupt: reports that it fired.
   Non-static so the compiler keeps it and its address is real. */
void st_int3f_probe(void)
{
  st_traceCh = 'H';
  asm {
    mov bx,1;
    mov dx,offset st_traceCh;
    mov cx,1;
    mov ah,0x40;
    int 21h;
    mov ax,0x4c3f;
    int 21h;
  }
}

'''
t = t.replace('void startx(void)', helper + 'void startx(void)', 1)

install = '''  {
    uint16_t hofs = (uint16_t)st_int3f_probe;

    asm {
      cli;
      xor ax,ax;
      mov es,ax;
      mov ax,hofs;
      mov word ptr es:[0xfc],ax;
      mov word ptr es:[0xfe],cs;
      sti;
    }
  }

'''
i = t.index('  asm { mov ax, seg DosVersion; mov ds, ax };', t.index('void startx(void)'))
end = i + len('  asm { mov ax, seg DosVersion; mov ds, ax };')
t = t[:end] + "\n" + install + t[end:]
io.open(p, "w", encoding="latin-1", newline="\n").write(t)
print("probe installed with a non-static handler")
