"""Build the INT 16h key TSR with a delayed DGROUP dump.

Same installer and residency as tmp/make_keytsr.py, but the AH=00 path now counts its own calls and, on
the Nth one, writes the caller's 64 KB at DS:0 (the game's DGROUP) to handle 1 - which the batch file has
redirected to DGR.BIN.  Because the sample point is inside the BIOS keyboard interrupt, the state is that
of whatever the game was doing when it asked for a key: i.e. after `_INIT_CFG`, in the menu, deep in play.

Why a TSR rather than patching code: the original's `biosReadKey` is reached through a VROOMM thunk, so the
executed code cannot be patched on disk (the overlay manager loads and relocates it).  The interrupt is
the one place both images necessarily pass through.

Layout (all offsets are .COM offsets; the image loads at CS:0100):

    0100  installer: get vector, set vector, jump over the handler
    0117  handler: count AH=00 calls; on the Nth, dump DS:0..FFFF to handle 1
    01xx  saved INT 16h vector (4 bytes) and the counter byte (both in the resident area)
    01yy  residency call (INT 21h AH=31h)
"""

import io
import sys

N = int(sys.argv[1]) if len(sys.argv) > 1 else 2
OUT = sys.argv[2] if len(sys.argv) > 2 else "tmp/DUMPTSR.COM"

BASE = 0x100
code = bytearray()
labels = {}
patches = []          # (position, kind, target)


def b(hexstr):
    code.extend(bytes.fromhex(hexstr))


def label(name):
    labels[name] = BASE + len(code)


def rel8(name, at):
    """Patch a one-byte displacement at `at` (the byte after the opcode) to reach `name`."""
    patches.append((at, "rel8", name))


# ---- installer --------------------------------------------------------------------------
b("B81635")                       # mov ax,3516h
b("CD21")                         # int 21h              ES:BX = old INT 16h
b("891E")                         # mov [vec],bx
rel16 = len(code); b("0000")      # placeholder for vec
b("8C06")                         # mov [vec+2],es
rel16b = len(code); b("0000")
b("B81625")                       # mov ax,2516h
b("BA")                           # mov dx,handler
rel16c = len(code); b("0000")
b("CD21")                         # int 21h
b("EB")                           # jmp short residency
rel8("residency", len(code)); b("00")

# ---- handler ----------------------------------------------------------------------------
label("handler")
b("80FC00")                       # cmp ah,0
b("75"); rel8("not00", len(code)); b("00")
b("2EA0")                         # mov al,cs:[counter]
rel16d = len(code); b("0000")
b("84C0")                         # test al,al
b("74"); rel8("nodump", len(code)); b("00")
b("2EFE0E")                       # dec byte ptr cs:[counter]
rel16e = len(code); b("0000")
b("75"); rel8("nodump", len(code)); b("00")

# dump the caller's DGROUP: DS must still be the game's at this point
b("1E")                           # push ds
b("50")                           # push ax
b("53")                           # push bx
b("51")                           # push cx
b("52")                           # push dx
b("BB0100")                       # mov bx,1            stdout
b("B9FFFF")                       # mov cx,0FFFFh
b("BA0000")                       # mov dx,0
b("B440")                         # mov ah,40h
b("CD21")                         # int 21h
b("5A")                           # pop dx
b("59")                           # pop cx
b("5B")                           # pop bx
b("58")                           # pop ax
b("1F")                           # pop ds

label("nodump")
b("B80D0D")                       # mov ax,0D0Dh        ENTER
b("CF")                           # iret

label("not00")
b("80FC01")                       # cmp ah,1
b("75"); rel8("chain", len(code)); b("00")
b("31C0")                         # xor ax,ax           no key waiting (ZF=1 from xor)
b("CF")                           # iret

label("chain")
b("2EFF2E")                       # jmp far cs:[vec]
rel16f = len(code); b("0000")

# ---- resident data ----------------------------------------------------------------------
label("vec")
b("00000000")                     # saved INT 16h vector
label("counter")
code.append(N)                    # AH=00 calls still to count down

label("residency")
b("B80031")                       # mov ax,3100h
b("BA")                           # mov dx,paragraphs
rel16g = len(code); b("0000")
b("CD21")                         # int 21h

# ---- fixups -----------------------------------------------------------------------------
image = bytearray(code)


def put16(pos, value):
    image[pos] = value & 0xFF
    image[pos + 1] = (value >> 8) & 0xFF


put16(rel16, labels["vec"])
put16(rel16b, labels["vec"] + 2)
put16(rel16c, labels["handler"])
put16(rel16d, labels["counter"])
put16(rel16e, labels["counter"])
put16(rel16f, labels["vec"])

for pos, _kind, target in patches:
    disp = labels[target] - (BASE + pos + 1)
    assert -128 <= disp <= 127, (target, disp)
    image[pos] = disp & 0xFF

total = len(image) + BASE
paras = (total + 15) // 16 + 0x10          # include the PSP
put16(rel16g, paras)

print("handler at %04x, vec at %04x, counter at %04x, residency at %04x, %d bytes, %d paragraphs, N=%d"
      % (labels["handler"], labels["vec"], labels["counter"], labels["residency"],
         len(image), paras, N))
io.open(OUT, "wb").write(bytes(image))
print("%s: %d bytes" % (OUT, len(image)))
