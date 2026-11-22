"""Close the DGROUP gaps at 0x755, 0x7a2 and 0x7ba.

diff_dgroup.py: -5 at s_bad_house_d (0x75a), +32 at MUSHandle (0x7a2),
-36/-4 at CurMusicType (0x7a6) and MidGfxOfs (0x7be).

Image (PeekBytes 2410:0755 and 2410:0790):

  0755  5  "%d \\r"                    (a second copy; the tree has one elsewhere)
  075a 17  "Bad House # %d \\r"
  076b  9  "(%d, %d)"
  0774 42  "x:%d y:%d  %x %x %x %x   %x %x %x %x    \\r"
  079e  4  DIGHandle  + .seg
  07a2  4  MUSHandle  + .seg          (missing from the tree)
  07a6  1  CurMusicType  ...
  07ba  4  a SECOND DIGHandle + .seg  (missing from the tree)
  07be  2  MidGfxOfs
  ...

The export dropped the second "%d \\r", the MUSHandle pair and the second
DIGHandle pair, and placed CurMusicType before MUSHandle.  The two DIGHandle
pairs need distinct C names (the originals share the symbol name), so the later
one is address-suffixed as `DIGHandle_07ba`.
"""
import io

P = "src/decompiled/st_globals4.c"
t = io.open(P, encoding="latin-1").read()

# 1. the second "%d \r" at 0x755, before "Bad House"
old = 'char s_bad_house_d[] = "Bad House # %d \\r";'
new = ('/* 0755: second "%d \\\\r" copy (the tree has another one elsewhere) */\n'
       'char s_d_2410_0755[] = "%d \\r";\n' + old)
if old not in t:
    raise SystemExit("s_bad_house anchor not found")
t = t.replace(old, new, 1)

# 2. MUSHandle right after DIGHandle
old = "far_t DIGHandle = { 0x0, 0x0 };\n"
new = ("far_t DIGHandle = { 0x0, 0x0 };\n"
       "far_t MUSHandle = { 0x0, 0x0 };\n")
if old not in t:
    raise SystemExit("DIGHandle anchor not found")
t = t.replace(old, new, 1)

# 3. the second DIGHandle pair before MidGfxOfs
old = "uint16_t MidGfxOfs = 0x0000;\n"
new = ("/* 07ba: a second DIGHandle pair; address-suffixed because the original\n"
       "   symbols share the name. */\n"
       "uint16_t DIGHandle_07ba = 0x0000;\n"
       "uint16_t DIGHandle_seg_07bc = 0x0000;\n" + old)
if old not in t:
    raise SystemExit("MidGfxOfs anchor not found")
t = t.replace(old, new, 1)

io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals4.c: s_d_2410_0755, MUSHandle, DIGHandle_07ba pair added")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
add = ("extern char s_d_2410_0755[];\n"
       "extern far_t MUSHandle;\n"
       "extern uint16_t DIGHandle_07ba;\n"
       "extern uint16_t DIGHandle_seg_07bc;\n")
if "s_d_2410_0755" not in h:
    h = h.replace("extern char s_bad_house_d[];", add + "extern char s_bad_house_d[];", 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: declarations added")
