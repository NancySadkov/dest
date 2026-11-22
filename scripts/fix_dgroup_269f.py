"""Close the gaps at 0x269f, 0x26ad, 0x26b7 and 0x26d7.

diff_dgroup: -1 at ScreenMode (0x26a8) and -9 at GMenuStrings (0x26b7).

Image (PeekBytes 2410:26a0):

  269f  9  "Mindark\\0\\0"      (the tree had 8: no padding NUL)
  26a8  1  ScreenMode
  26a9  4  GSPEmpty (far)
  26ad 10  promptRect = {0x16,0x1D,0xDE,0x27,0xA000}   (declared as one byte)
  26b7 32  GMenuStrings - EIGHT 4-byte far pointers, but the tree declares
           `char *GMenuStrings[8]`, which is 2 bytes each in medium model (16)
  26d7  8  GYesNo - two far pointers (the tree declares 2-byte `char *`)
"""
import io

P = "src/decompiled/st_globals5.c"
t = io.open(P, encoding="latin-1").read()

subs = [
    ('char s_Mindark_2410_269f[] = "Mindark";',
     '/* 269f: 9 bytes - "Mindark" plus a padding NUL */\n'
     'char s_Mindark_2410_269f[9] = "Mindark";'),
    ("undefined promptRect = 0x16;",
     "/* 26ad: a prompt rectangle (10-byte brect_t) */\n"
     "brect_t promptRect = { 0x16, 0x1D, 0xDE, 0x27, 0xA000 };"),
    ("char *GMenuStrings[8] = { (void far *)(0x24100000UL + 0x27ebUL), (void far *)(0x24100000UL + 0x27f4UL),",
     "/* 26b7: eight FAR pointers (4 bytes each) */\n"
     "char far *GMenuStrings[8] = { (char far *)(0x24100000UL + 0x27ebUL), (char far *)(0x24100000UL + 0x27f4UL),"),
    ("     (void far *)(0x24100000UL + 0x27feUL), (void far *)(0x24100000UL + 0x2808UL), (void far *)(0x24100000UL + 0x2814UL),",
     "     (char far *)(0x24100000UL + 0x27feUL), (char far *)(0x24100000UL + 0x2808UL), (char far *)(0x24100000UL + 0x2814UL),"),
    ("     (void far *)(0x24100000UL + 0x281eUL), (void far *)(0x24100000UL + 0x282cUL), (void far *)(0x24100000UL + 0x283fUL) };",
     "     (char far *)(0x24100000UL + 0x281eUL), (char far *)(0x24100000UL + 0x282cUL), (char far *)(0x24100000UL + 0x283fUL) };"),
    ("char *GYesNo[2] = { (void far *)(0x24100000UL + 0x284aUL), (void far *)(0x24100000UL + 0x284eUL) };",
     "/* 26d7: two FAR pointers */\n"
     "char far *GYesNo[2] = { (char far *)(0x24100000UL + 0x284aUL), (char far *)(0x24100000UL + 0x284eUL) };"),
]
for a, b in subs:
    if a not in t:
        raise SystemExit("anchor not found: " + a[:60])
    t = t.replace(a, b, 1)

io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals5.c: s_Mindark[9], promptRect, GMenuStrings, GYesNo")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
h = h.replace("extern char s_Mindark_2410_269f[];", "extern char s_Mindark_2410_269f[9];")
h = h.replace("extern undefined promptRect;", "extern brect_t promptRect;")
h = h.replace("extern char *GMenuStrings[8];", "extern char far *GMenuStrings[8];")
h = h.replace("extern char *GYesNo[2];", "extern char far *GYesNo[2];")
io.open(H, "w", encoding="latin-1", newline="\n").write(h)
print("st_globals.h: declarations updated")
