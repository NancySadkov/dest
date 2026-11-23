"""Probe: does our INT 3Fh handler intercept the overlay stub?

Installs a handler that writes 'H' to stdout and exits with 0x3F, then runs the
default (overlay) link.  If OUT.BIN receives 'H', the overlay stub path is
reachable and the block loader can be built on it.

usage: python tmp/probe_int3f.py [--revert]
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
/* Probe handler for the VROOMM stub interrupt: reports that it fired. */
static void int3f_probe(void)
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
anchor = 'void startx(void)'
t = t.replace(anchor, helper + anchor, 1)

install = '''  /* install the INT 3Fh probe: overlay stubs use it */
  {
    uint16_t cseg;

    asm { mov ax,cs; mov cseg,ax }
    asm {
      mov ax,0x253f;
      mov dx,offset int3f_probe;
      mov ds,cseg;
      int 21h;
    }
    asm { mov ax,seg DosVersion; mov ds,ax }
  }

'''
i = t.index('  asm { mov ax, seg DosVersion; mov ds, ax };', t.index('void startx(void)'))
end = i + len('  asm { mov ax, seg DosVersion; mov ds, ax };')
t = t[:end] + "\n" + install + t[end:]
io.open(p, "w", encoding="latin-1", newline="\n").write(t)
print("INT 3Fh probe installed")
