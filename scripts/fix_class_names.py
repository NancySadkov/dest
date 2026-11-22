"""Restore the five duplicate singular class names at 0x1d5..0x1f9.

The original DGROUP has two singular class-name tables:

  0169 "Fighter" ... 01c3 "halflings"      capitalised table
  01cd "fighter" 01d5 "mage" 01da "cleric" 01e1 "thief" 01e7 "dwarf"
       01ed "elf" 01f1 "halfling"           lower-case singular table

Ghidra gave the lower-case duplicates the same names as the capitalised ones
(`s_mage` appears at both 0x171 and 0x1d5), so the export kept only the first of
each and dropped 5+7+6+4+9 = 31 bytes.  They are re-added under address-suffixed
names, which is the convention already used for `s_Fighter_2410_0169`.
"""
import io

P = "src/decompiled/st_globals4.c"
t = io.open(P, encoding="latin-1").read()

old = 'char s_fighter[] = "fighter";\nchar s_thief[] = "thief";\n'
new = ('char s_fighter[] = "fighter";\n'
       '/* 01d5/01da: the lower-case table repeats mage/cleric, which the export\n'
       '   dropped because the names collided with 0x171/0x176. */\n'
       'char s_mage_2410_01d5[] = "mage";\n'
       'char s_cleric_2410_01da[] = "cleric";\n'
       'char s_thief[] = "thief";\n'
       '/* 01e7/01ed/01f1: same for dwarf/elf/halfling. */\n'
       'char s_dwarf_2410_01e7[] = "dwarf";\n'
       'char s_elf_2410_01ed[] = "elf";\n'
       'char s_halfling_2410_01f1[] = "halfling";\n')
if old not in t:
    raise SystemExit("class-name anchor not found")
t = t.replace(old, new, 1)
io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals4.c: 5 lower-case class names restored (31 bytes)")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
add = ("extern char s_mage_2410_01d5[];\n"
       "extern char s_cleric_2410_01da[];\n"
       "extern char s_dwarf_2410_01e7[];\n"
       "extern char s_elf_2410_01ed[];\n"
       "extern char s_halfling_2410_01f1[];\n")
if "s_mage_2410_01d5" not in h:
    h = h.replace("extern char s_fighter[];", "extern char s_fighter[];\n" + add, 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: declarations added")
