"""Close the DGROUP gaps at 0x864, 0x897 and 0x8da.

diff_dgroup.py: -1 at SquareRecX (0x86e) and -14 at s_d_d_d (0x8df).

Image:
  0864 10  "(%d, %d)" + NUL + padding NUL      (the tree declared 9 bytes)
  0897 10  mouseSaveRect2 = {208,157,226,196,0xA000}   (declared as one byte)
  08da  5  a third "%d \\r" copy                (missing)
  08df  9  "%d %d %d " - a fragment of the longer "%d %d %d \\r" string whose
           NUL lives past the next symbol, so s_d_d_d itself needs no change
"""
import io

P = "src/decompiled/st_globals4.c"
t = io.open(P, encoding="latin-1").read()

subs = [
    ('char s_d_d_2410_0864[] = "(%d, %d)";',
     '/* 0864: 10 bytes - "(%d, %d)" plus a padding NUL */\n'
     'char s_d_d_2410_0864[10] = "(%d, %d)";'),
    ("undefined mouseSaveRect2 = 0xD0;",
     "/* 0897: a mouse save rectangle (10-byte brect_t) */\n"
     "brect_t mouseSaveRect2 = { 208, 157, 226, 196, 0xA000 };"),
    ('char s_d_d_d[] = "%d %d %d \\r";',
     '/* 08da: a third "%d \\\\r" copy */\n'
     'char s_d_2410_08da[] = "%d \\r";\n'
     'char s_d_d_d[] = "%d %d %d \\r";'),
]
for a, b in subs:
    if a not in t:
        raise SystemExit("anchor not found: " + a)
    t = t.replace(a, b, 1)

io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals4.c: s_d_d_2410_0864[10], mouseSaveRect2, s_d_2410_08da")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
if "s_d_2410_08da" not in h:
    h = h.replace("extern char s_d_d_2410_0864[];",
                  "extern char s_d_d_2410_0864[10];", 1)
    h = h.replace("extern undefined mouseSaveRect2;", "extern brect_t mouseSaveRect2;", 1)
    h = h.replace("extern char s_d_d_d[];",
                  "extern char s_d_2410_08da[];\nextern char s_d_d_d[];", 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: declarations updated")
