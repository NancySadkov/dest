#include "dgroup.h"

/* Recovered C for overlay 0x6190 (animation frame advance).
 *
 * Byte-identical to the original when assembled with TCC 3.0; the two far
 * call operands are overlay trampoline slots restored by src/ov_patch.csv.
 */
typedef char *charp;

extern charp __cdecl16far f_474a_075a(unsigned long a);
void __cdecl16far f_317e_0bf2(char *a, int b, int c, char *d, int e, int f);

void __cdecl16far f_6190_0000(void)
{
    int i;

    for (i = 0; i < 3; i++)
        ((charp far *)MK_FP(0x0280, 0x9203))[i] =
            f_474a_075a((unsigned)AnimSeqCounts[i] * 4);
}

void __cdecl16far f_6190_0039(int seq, uint8_t frame, int x, int y, char *text)
{
    uint8_t step;

    step = ((uint8_t *)&GfxPlaySteps)[seq];
    if (((uint8_t *)&GfxFrameCounts)[frame] <= step)
        step = 0;
    f_317e_0bf2(((charp far * far *)MK_FP(0x0280, 0x91ff))[frame][step],
                x, y, text, 0x10, 0);
    step++;
    ((uint8_t *)&GfxPlaySteps)[seq] = step;
    GAnimPlaying = 1;
}
