/* UI helper functions recovered from OVC21 (4D05).
 *
 * These four functions recompile byte-for-byte to the original code
 * (checked with scripts/fbov/verify_ui_bytes.py), so they can replace the
 * original overlay functions without any relocation.
 */
#include "dgroup.h"

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
