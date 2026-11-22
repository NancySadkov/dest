"""Restore the two missing copy-protection strings at 0x6b1 and 0x6cd.

diff_dgroup.py: -60 at s_enter_the_first_word (0x712).  The image shows two
strings the export dropped (28 + 32 = 60 bytes), and that the labelled
`s_ng` at 0x6ae is not a string of its own but the tail of "constructing":

  06a4 "constructing\\0"                    (13, s_ng labels offset 10 inside it)
  06b1 "Stronghold copy protection.\\0"     (28)
  06cd "Turn to page #%d of the manual.\\0" (32)
  06ed "Including titles, count to line #%d.\\0" (37, already present)
  0712 "Enter the first word.\\0" + pad     (22)
"""
import io

P = "src/decompiled/st_globals4.c"
t = io.open(P, encoding="latin-1").read()

anchor = 'char s_constructing_2410_06a4[] = "constructing";\n'
if anchor not in t:
    raise SystemExit("constructing anchor not found")
add = ('/* 06b1: "Stronghold copy protection." (28 bytes) */\n'
       'char s_Stronghold_copy_pro_2410_06b1[] = "Stronghold copy protection.";\n'
       '/* 06cd: "Turn to page #%d of the manual." (32 bytes) */\n'
       'char s_Turn_to_page_d_of_th_2410_06cd[] = "Turn to page #%d of the manual.";\n')
t = t.replace(anchor, anchor + add, 1)

# s_enter_the_first_word is 22 bytes in the image (21 + padding NUL)
old = 'char s_enter_the_first_word[] = "Enter the first word.";'
new = ('/* 0712: 22 bytes - the image carries one padding NUL */\n'
       'char s_enter_the_first_word[22] = "Enter the first word.";')
if old in t:
    t = t.replace(old, new, 1)
    print("s_enter_the_first_word: 22 bytes")
else:
    print("s_enter_the_first_word: anchor not found (skipped)")

io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals4.c: 2 copy-protection strings restored (60 bytes)")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
add2 = ("extern char s_Stronghold_copy_pro_2410_06b1[];\n"
        "extern char s_Turn_to_page_d_of_th_2410_06cd[];\n")
if "s_Stronghold_copy_pro_2410_06b1" not in h:
    h = h.replace("extern char s_constructing_2410_06a4[];",
                  "extern char s_constructing_2410_06a4[];\n" + add2, 1)
    h = h.replace("extern char s_enter_the_first_word[];",
                  "extern char s_enter_the_first_word[22];", 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: declarations updated")
