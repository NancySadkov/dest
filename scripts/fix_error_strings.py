"""Recover the five missing error strings at DGROUP 0352..042c.

scripts/diff_dgroup.py reported the layout 148 bytes short before TextBlitX
(0x42c).  The original image has five string literals in that gap that the
export dropped, and GErrorStrings already points at their addresses:

    0352  41  "Bad 'game.cfg' file. Please reconfigure."
    037b  24  "Cannot find sound card."
    0393  24  "Cannot find music card."
    03e2  13  "Mouse error."
    03ff  45  "Error %d %d.  (Give Cathryn BOTH numbers.)\n" + pad

Bytes come from PeekBytes 2410:0352/03e2/03ff.  The last message is declared
[45] because the image has one padding NUL after the literal's own terminator
(43 chars + NUL = 44, then one 0x00), which also accounts for the extra byte
between the 147 bytes of text and the measured 148.

Insertion order follows the addresses, so GErrorStrings' hard-coded far
pointers land on the right strings.
"""
import io

P = "src/decompiled/st_globals4.c"
t = io.open(P, encoding="latin-1").read()

anchor = ('far_t GErrorStrings[5] = { { 0x352, 0x2410 }, { 0x37B, 0x2410 }, { 0x393, 0x2410 }, { 0x3AB, 0x2410 },\n'
          '     { 0x3E2, 0x2410 } };\n')
if anchor not in t:
    raise SystemExit("GErrorStrings anchor not found")

bad = ('/* 0352: "Bad \'game.cfg\' file. Please reconfigure." (41 bytes) */\n'
       'char s_Bad_game_cfg_2410_0352[] = "Bad \'game.cfg\' file. Please reconfigure.";\n'
       '/* 037b: "Cannot find sound card." (24 bytes) */\n'
       'char s_Cannot_find_sound_2410_037b[] = "Cannot find sound card.";\n'
       '/* 0393: "Cannot find music card." (24 bytes) */\n'
       'char s_Cannot_find_music_2410_0393[] = "Cannot find music card.";\n')
t = t.replace(anchor, anchor + bad, 1)

anchor2 = 'char s_Cannot_create_confi_2410_03ab[] = "Cannot create configuration file.  Stronghold aborted.";\n'
if anchor2 not in t:
    raise SystemExit("Cannot_create anchor not found")
mouse = '/* 03e2: "Mouse error." (13 bytes) */\nchar s_Mouse_error_2410_03e2[] = "Mouse error.";\n'
t = t.replace(anchor2, anchor2 + mouse, 1)

anchor3 = 'char s_s[] = "%s\\n";\n'
if anchor3 not in t:
    raise SystemExit("s_s anchor not found")
last = ('/* 03ff: "Error %d %d.  (Give Cathryn BOTH numbers.)\\n" plus the\n'
        '   padding NUL the image carries (45 bytes) */\n'
        'char s_Error_d_d_Give_2410_03ff[45] = "Error %d %d.  (Give Cathryn BOTH numbers.)\\n";\n')
t = t.replace(anchor3, anchor3 + last, 1)

io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals4.c: 5 error strings inserted (41+24+24+13+45 = 147 bytes, +1 pad = 148)")

# declarations for anything that may reference them by name
H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
add = """extern char s_Bad_game_cfg_2410_0352[];
extern char s_Cannot_find_sound_2410_037b[];
extern char s_Cannot_find_music_2410_0393[];
extern char s_Mouse_error_2410_03e2[];
extern char s_Error_d_d_Give_2410_03ff[45];
"""
if "s_Bad_game_cfg_2410_0352" not in h:
    h = h.replace("extern far_t GErrorStrings[5];",
                  "extern far_t GErrorStrings[5];\n" + add, 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: declarations added")
