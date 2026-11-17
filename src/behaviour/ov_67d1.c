#include "dgroup.h"

/* Recovered C for overlay 0x67D1: summarise a town record's food, housing and
 * income as a single 0..100 status value.
 *
 * Behavioural reconstruction (the original is 311 bytes); the arithmetic is
 * written as ordinary 32-bit division instead of the resident LXMUL/LDIV
 * helper calls.
 */
#define CHARSHEET(i) (*(char_sheet_t far * far *)MK_FP(0x0070, (i) * 4))

uint16_t __cdecl16far f_67d1_0000(uint8_t index)
{
    char_sheet_t far *p;
    int food, housing, income;

    p = CHARSHEET(index);
    if (p->population == 0)
        return 0;
    food = (int)(100L * p->foodProd / p->population);
    if (food > 200)
        food = 200;
    housing = (int)(100L * p->housing / p->population);
    if (housing > 200)
        housing = 200;
    income = (int)(100L * p->income / p->population);
    if (income < 0)
        income = 0;
    if (income > 200)
        income = 200;
    return (food + housing + income) / 6;
}
