/* UI helper functions recovered from OVC21 (4D05).
 *
 * These four functions recompile byte-for-byte to the original code
 * (checked with scripts/fbov/verify_ui_bytes.py), so they can replace the
 * original overlay functions without any relocation.
 */
#include "dgroup.h"
#include "bss.h"

uint16_t __cdecl16far f_474a_0b26(uint16_t n);
uint16_t __cdecl16far f_302d_06ea(char *text, uint8_t *widths);
uint __cdecl16far f_302d_0634(char *text, uint8_t *widths,
                              int16_t max_width, uint8_t term);
uint8_t __cdecl16far manage_4d05_01a3(uint8_t count, uint8_t sides);
void __cdecl16far manage_4d05_01d4(char_sheet_t *sheet);

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
