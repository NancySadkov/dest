/* UI helper functions recovered from OVC21 (4D05).
 *
 * Every function recompiles byte-for-byte to the original code (checked with
 * scripts/fbov/verify_ui_bytes.py), so it can replace the original overlay
 * function without any relocation.
 */
#include "dgroup.h"
#include "bss.h"
#include <string.h>

uint8_t __cdecl16far f_474a_0b26(uint16_t n);
uint16_t __cdecl16far f_302d_06ea(char *text, uint8_t *widths);
uint __cdecl16far f_302d_0634(char *text, uint8_t *widths,
                              int16_t max_width, uint8_t term);
uint8_t __cdecl16far manage_4d05_01a3(uint8_t count, uint8_t sides);
void __cdecl16far manage_4d05_01d4(char_sheet_t *sheet);
char * __cdecl16far manage_4d05_03a4(char_sheet_t *sheet);
void __cdecl16far f_6386_24c2(char *text);
uint8_t __cdecl16far uiInputText(far_t *entries, int count, char *hint,
                                 uint8_t flags);
char __cdecl16far manage_4d05_118b(uint8_t race);
void __cdecl16far manage_4d05_11cb(char_sheet_t *sheet);
void __cdecl16far f_6386_232d(void);
void __cdecl16far f_3d16_1558(void);
char * __cdecl16far f_5087_0119(char index);
char * __cdecl16far f_474a_09df(char *buf, char *fmt, ...);
void __cdecl16far f_302d_0a1b(char *msg);

/* Roll `count` dice with `sides` faces and return the total. */
uint8_t __cdecl16far manage_4d05_01a3(uint8_t count, uint8_t sides)
{
    uint8_t total;

    total = 0;
    while (count--)
        total += (uint8_t)f_474a_0b26(sides) + 1;
    return total;
}

/* Roll the six ability scores of a new character and mark them enabled. */
void __cdecl16far manage_4d05_01d4(char_sheet_t *sheet)
{
    uint8_t i;

    for (i = 0; i < 6; i++)
    {
        sheet->stats[i] = manage_4d05_01a3(3, 6) + f_474a_0b26(4);
        if (sheet->stats[i] >= 0x12)
            sheet->stats[i] = 0x12;
    }
    sheet->statMask |= 0x20;
}

/* Render a long as a comma-separated decimal string. */
char * __cdecl16far manage_4d05_217a(char *buf, long value)
{
    char neg;

    if (value < 0) {
        neg = 1;
        value = -value;
    }
    else {
        neg = 0;
    }
    *buf = (char)(value % 10) + '0';
    buf[1] = 0;
    while (value / 10 != 0) {
        if ((strlen(buf) & 3) == 3) {
            memmove(buf + 1, buf, strlen(buf) + 1);
            *buf = ',';
        }
        memmove(buf + 1, buf, strlen(buf) + 1);
        value /= 10;
        *buf = (char)(value % 10) + '0';
    }
    if (neg) {
        memmove(buf + 1, buf, strlen(buf) + 1);
        *buf = '-';
    }
    return buf;
}

/* English ordinal suffix ("st", "nd", "rd", "th"). */
char * __cdecl16far manage_4d05_023a(int n)
{
    int r;
    char *suffix;

    r = n % 10;
    if (r == 1 && n != 11)
        suffix = "st";
    else if (r == 2 && n != 12)
        suffix = "nd";
    else if (r == 3 && n != 13)
        suffix = "rd";
    else
        suffix = "th";
    return suffix;
}

uint8_t __cdecl16far manage_4d05_029d(char_sheet_t *sheet)
{
    if ((sheet->cls == 4) && (0xc < sheet->race))
        return 0xc;
    if ((sheet->cls == 5) && (10 < sheet->race))
        return 10;
    if ((sheet->cls == 6) && (8 < sheet->race))
        return 8;
    return sheet->race;
}

uint8_t __cdecl16far manage_4d05_02f1(char_sheet_t *sheet)
{
    if ((sheet->cls == 4) && (sheet->race >= 0xc))
        return 1;
    if ((sheet->cls == 5) && (sheet->race >= 0xa))
        return 1;
    if ((sheet->cls == 6) && (sheet->race >= 8))
        return 1;
    return 0;
}

uint8_t __cdecl16far manage_4d05_0340(char_sheet_t *sheet)
{
    if ((sheet->cls == 4) && (sheet->race >= 0xc))
        return sheet->race + 0x37;
    if ((sheet->cls == 5) && (sheet->race >= 0xa))
        return sheet->race + 0x39;
    if ((sheet->cls == 6) && (sheet->race >= 8))
        return sheet->race + 0x39;
    return '0';
}

uint8_t __cdecl16far manage_4d05_0d7b(uint8_t statIndex, char_sheet_t *sheet)
{
    uint8_t i;

    if (sheet->stats[statIndex] >= 0x12)
        return 0;
    i = 0;
    while (i <= 2) {
        if (10 < sheet->stats[i] && statIndex != i)
            return 1;
        i++;
    }
    return 0;
}

/* Character table: array of far pointers at offset 0 of the load-time
 * segment 0x0070.  `&_DATA` gives the original zero-offset relocation. */
#define CHARSHEET(i) \
    (*(char_sheet_t far * far *)MK_FP(0x0070, (uint)&_DATA + (i) * 4))

/* Two titles (male/female) per row.  The original build laid the class rows
 * directly after the four stat labels, and the copied title set at
 * GPlayerTitles[18] (DGROUP 0x49A5). */
struct title_set {
    char *t[7][2];
};
#define TITLES ((char *(*)[2])((char **)GStatsLabels + 4))

/* Character title: class/level table, with a fallback for unclassed records. */
char * __cdecl16far manage_4d05_03a4(char_sheet_t *sheet)
{
    struct title_set local;

    local = *(struct title_set far *)&GPlayerTitles[18];
    if (sheet->cls == 0xff)
        return "";
    if (sheet->level != 0)
        return TITLES[sheet->level][sheet->gender];
    if (sheet->race >= 9 || (sheet->cls == 6 && sheet->race >= 8))
        return local.t[sheet->cls][sheet->gender];
    return "";
}

/* DGROUP objects reached through the loader-patched data segment 0x0280. */
#define DG_TEXTBLITX (*(uint16_t far *)MK_FP(0x0280, 0x042c))
#define DG_FONT02 (*(char far * far *)MK_FP(0x0280, 0x8a21))

/* Average popularity of the active, non-excluded character records. */
int __cdecl16far manage_4d05_044e(void)
{
    unsigned sum;
    uint8_t count;
    int i;

    sum = 0;
    count = 0;
    for (i = 0; i < GLeaderCount; i++) {
        if (CHARSHEET(i)->active != 0 && !CHARSHEET(i)->excluded) {
            sum += CHARSHEET(i)->popularity;
            count++;
        }
    }
    if (count != 0)
        sum /= count;
    return sum;
}

/* Right-align a text run against the current text position. */
void __cdecl16far manage_4d05_04c6(char *text, int x)
{
    DG_TEXTBLITX = x - f_302d_06ea(text, DG_FONT02);
    f_302d_0634(text, DG_FONT02, 0xde, 0x50);
}

/* Right-align a text run at an explicit vertical offset. */
void __cdecl16far manage_4d05_0519(char *text, int x, char y)
{
    DG_TEXTBLITX = x - f_302d_06ea(text, DG_FONT02);
    f_302d_0634(text, DG_FONT02, 0xde, y);
}

/* Index of the first character record with a level, or -1. */
char __cdecl16far manage_4d05_1b1d(void)
{
    uint8_t i;

    for (i = 0; i < GLeaderCount; i++)
        if (CHARSHEET(i)->level != 0)
            return i;
    return -1;
}

/* Describe the current unit filter, save the RNG seeds around the
 * refresh, then print the composed line. */
void __cdecl16far manage_4d05_330c(uint8_t index, int mode, char *text)
{
    int savedSeed;
    int savedSeed2;
    char buf[0x100];

    DAT_2410_4b6d = mode;
    DAT_2410_4b6e = index;
    if (*(uint8_t far *)MK_FP(0x0280, 0x26a8) != 0)
        f_6386_232d();
    savedSeed = *(uint16_t far *)MK_FP(0x0280, 0x899f);
    savedSeed2 = *(uint16_t far *)MK_FP(0x0280, 0x899d);
    *(uint16_t far *)MK_FP(0x0280, 0x899f) = Seed_2000_d1da;
    *(uint16_t far *)MK_FP(0x0280, 0x899d) = Seed_2000_d1d8;
    f_3d16_1558();
    *(uint16_t far *)MK_FP(0x0280, 0x899f) = savedSeed;
    *(uint16_t far *)MK_FP(0x0280, 0x899d) = savedSeed2;
    DAT_2410_4b6d = 0xff;
    DAT_2410_4b6e = 0xff;
    if (mode == 0xfe) {
        if (index != 0xff) {
            f_302d_0a1b(f_474a_09df(buf,
                        "All units loyal to %s the %s are displayed.",
                        CHARSHEET(index), f_5087_0119(index)));
        }
        else {
            f_302d_0a1b("All units are displayed.");
        }
    }
    else {
        if (index != 0xff) {
            f_302d_0a1b(f_474a_09df(buf,
                        "Only units of %s loyal to %s the %s are displayed.",
                        text, CHARSHEET(index), f_5087_0119(index)));
        }
        else {
            f_302d_0a1b(f_474a_09df(buf, "Only units of %s are displayed.",
                                    text));
        }
    }
}

/* Next record with the same excluded status, starting at `start`. */
char __cdecl16far manage_4d05_1b51(uint8_t start)
{
    uint8_t first;
    uint8_t i;

    first = manage_4d05_1b1d();
    i = start;
    do {
        if (i < GLeaderCount && i != first && i != start &&
            CHARSHEET(i)->active != 0 &&
            CHARSHEET(i)->excluded == CHARSHEET(start)->excluded)
            return i;
        i++;
        if (i >= GLeaderCount)
            i = 0;
    } while (i != start);
    return -1;
}

/* Hit-point roll table (one die size per class). */
struct hp_table {
    uint8_t die[7];
};

/* Alignment slider stop for a race value. */
char __cdecl16far manage_4d05_118b(uint8_t race)
{
    if (race <= 3)
        return -3;
    if (race <= 5)
        return -2;
    if (race <= 8)
        return -1;
    if (race <= 0xc)
        return 0;
    if (race <= 0xf)
        return 1;
    if (race <= 0x11)
        return 2;
    return 3;
}

/* Roll starting hit points from the class die table. */
void __cdecl16far manage_4d05_11cb(char_sheet_t *sheet)
{
    int hp;
    struct hp_table local;
    int i;

    local = *(struct hp_table far *)&DAT_2410_4a0b;
    hp = 0;
    for (i = 0; i < sheet->race; i++) {
        int v = f_474a_0b26(local.die[sheet->cls]) +
                manage_4d05_118b(sheet->stats[4]) + 1;
        if (v <= 0)
            v = 1;
        hp += v;
    }
    sheet->pad_31[0] = hp;
    sheet->pad_31[1] = hp;
    sheet->statMask |= 0x10;
}

/* Two-entry menu (OK / Try Again) assembled from the static DGROUP table. */
struct menu_pair {
    far_t item[2];
};

/* Alignment picker: prompt, alignment menu, then a retry menu. */
uint8_t __cdecl16far manage_4d05_1095(char_sheet_t *sheet)
{
    struct menu_pair local;
    int sel;

    local = *(struct menu_pair far *)((char **)&GAlignmentString + 7);
    for (;;) {
        f_6386_24c2((char *)gap_2410_4F9C);
        sel = uiInputText(GAlignmentsNames, 3, 0, 0);
        if (sel == 0)
            return 0;
        sheet->alignment = sel - 1;
        sheet->statMask |= 4;
        if (DAT_2000_d1e5 != 0)
            return 1;
        f_6386_24c2(((char **)&GAlignmentString)[sel]);
        sel = uiInputText(&local.item[0], 2, 0, 0);
        if (sel == 0)
            return 0;
        if (sel == 1)
            return 1;
    }
}

/* Gender picker: show the prompt, then a two-entry menu. */
uint8_t __cdecl16far manage_4d05_1146(char_sheet_t *sheet)
{
    int sel;

    f_6386_24c2((char *)gap_2410_4F9C + 0x15);
    sel = uiInputText(far_t_ARRAY_2410_4933, 2, 0, 0);
    if (sel == 0)
        return 0;
    sheet->gender = sel - 1;
    return 1;
}

/* Default class for a race in the character generator. */
uint8_t __cdecl16far manage_4d05_125c(uint8_t race)
{
    switch (race) {
    case 0:
    case 1:
    case 2:
    case 3:
        return race;
    case 4:
        return 10;
    case 5:
        return 8;
    case 6:
        return 0xb;
    }
    return 0;
}
