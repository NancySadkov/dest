"""Build the INT 16h key TSR with a delayed DGROUP dump to a file it opens itself.

Same installer and residency as tmp/make_keytsr.py.  The AH=00 path counts its own calls and, on the Nth
one, writes the caller's 64 KB at DS:0 (the game's DGROUP) to DGR.BIN.

The dump goes to a file the handler *creates* (INT 21h AH=3Ch with the name in its own segment), not to
stdout: our recovered printf writes to handle 1 directly, so a stdout redirect would put the game's text
in front of the dump and shift every offset.  Creating the file also means the harness needs no redirection
at all.

Layout (all offsets are .COM offsets; the image loads at CS:0100):

    0100  installer: get vector, set vector, jump over the handler
    0117  handler: count AH=00 calls; on the Nth, create+write+close DGR.BIN
    01xx  saved INT 16h vector (4 bytes), the counter byte, and the file name
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
    patches.append((at, "rel8", name))


# ---- installer --------------------------------------------------------------------------
b("B81635")                       # mov ax,3516h
b("CD21")                         # int 21h              ES:BX = old INT 16h
b("891E"); rv = len(code); b("0000")
b("8C06"); rv2 = len(code); b("0000")
b("B81625")                       # mov ax,2516h
b("BA"); rh = len(code); b("0000")
b("CD21")                         # int 21h
b("EB"); rel8("residency", len(code)); b("00")

# ---- handler ----------------------------------------------------------------------------
label("handler")
b("80FC00")                       # cmp ah,0
b("75"); rel8("not00", len(code)); b("00")
b("2EA0"); rc = len(code); b("0000")     # mov al,cs:[counter]
b("84C0")                         # test al,al
b("74"); rel8("nodump", len(code)); b("00")
b("2EFE0E"); rc2 = len(code); b("0000")  # dec byte ptr cs:[counter]
b("75"); rel8("nodump", len(code)); b("00")

# create DGR.BIN (name lives in our own segment), then write the caller's DGROUP into it
b("50")                           # push ax
b("53")                           # push bx
b("51")                           # push cx
b("52")                           # push dx
b("56")                           # push si
b("8CDE")                         # mov si,ds   (save the caller's DS)
b("0E")                           # push cs
b("1F")                           # pop ds
b("BA"); rn = len(code); b("0000")       # mov dx,offset name
b("31C9")                         # xor cx,cx
b("B43C")                         # mov ah,3Ch  create/truncate
b("CD21")                         # int 21h     AX = handle
b("89C3")                         # mov bx,ax
b("89F2")                         # mov dx,si   (restore DGROUP into DS)
b("8EDA")                         # mov ds,dx
b("B9FFFF")                       # mov cx,0FFFFh
b("31D2")                         # xor dx,dx   -> DS:0
b("B440")                         # mov ah,40h
b("CD21")                         # int 21h
b("B43E")                         # mov ah,3Eh  close
b("CD21")                         # int 21h
b("5E")                           # pop si
b("5A")                           # pop dx
b("59")                           # pop cx
b("5B")                           # pop bx
b("58")                           # pop ax

label("nodump")
b("B80D0D")                       # mov ax,0D0Dh        ENTER
b("CF")                           # iret

label("not00")
b("80FC01")                       # cmp ah,1
b("75"); rel8("chain", len(code)); b("00")
b("31C0")                         # xor ax,ax           no key waiting (ZF=1)
b("CF")                           # iret

label("chain")
b("2EFF2E"); rv3 = len(code); b("0000")

# ---- resident data ----------------------------------------------------------------------
label("vec")
b("00000000")
label("counter")
code.append(N)
label("name")
b("44 47 52 2E 42 49 4E 00".replace(" ", ""))   # "DGR.BIN",0

label("residency")
b("B80031")                       # mov ax,3100h
b("BA"); rp = len(code); b("0000")
b("CD21")                         # int 21h

image = bytearray(code)


def put16(pos, value):
    image[pos] = value & 0xFF
    image[pos + 1] = (value >> 8) & 0xFF


put16(rv, labels["vec"])
put16(rv2, labels["vec"] + 2)
put16(rh, labels["handler"])
put16(rc, labels["counter"])
put16(rc2, labels["counter"])
put16(rv3, labels["vec"])
put16(rn, labels["name"])

for pos, _kind, target in patches:
    disp = labels[target] - (BASE + pos + 1)
    assert -128 <= disp <= 127, (target, disp)
    image[pos] = disp & 0xFF

total = len(image) + BASE
paras = (total + 15) // 16 + 0x10
put16(rp, paras)

print("handler %04x vec %04x counter %04x name %04x residency %04x, %d bytes, %d paragraphs, N=%d"
      % (labels["handler"], labels["vec"], labels["counter"], labels["name"],
         labels["residency"], len(image), paras, N))
io.open(OUT, "wb").write(bytes(image))
