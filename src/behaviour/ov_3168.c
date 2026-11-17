#include "dgroup.h"

/* Recovered C for overlay 0x3168: the fatal error report and shutdown path.
 *
 * Behavioural reconstruction: it produces the same data/IO effects as the
 * original but is not instruction-identical (the original slot is 288 bytes,
 * this body is smaller).  Console output goes through the resident runtime
 * entries used by the original code.
 */
int __cdecl16far f_0000_2747(char *fmt, ...);
void __cdecl16far f_0000_08fd(int code);

void __cdecl16far f_2d63_0030(void);
void __cdecl16far f_2d63_0016(int a);
void __cdecl16far f_2d63_0034(void);
void __cdecl16far f_2d63_07aa(void);
void __cdecl16far f_474a_004e(int a);
void __cdecl16far f_69c8_0000(char *a);
void __cdecl16far f_0000_0295(uint16_t a);
void __cdecl16far f_0000_044f(void);
void __cdecl16far f_0000_069f(void);

void __cdecl16far f_3168_0000(int code)
{
    if (code != 0 && code < 0x80) {
        f_0000_2747("\n\rError %d\n", code);
        f_2d63_0030();
    }
    f_2d63_0016(3);
    if (code >= 0x80)
        f_0000_2747("%s\n",
                    *(char * far *)((char *)MK_FP(0x0280, 0x13e) + code * 4));
    else if (code != 0)
        f_0000_2747("Error %d %d.  (Give Cathryn BOTH numbers.)\n",
                    GGameState, code);
    if (CFG_Mice)
        f_2d63_0034();
    if (MusRunning)
        f_2d63_07aa();
    if (*(uint32_t far *)MK_FP(0x0280, 0x7c2) != 0)
        f_0000_0295(*(uint16_t far *)MK_FP(0x0280, 0x7c4));
    if (*(uint32_t far *)MK_FP(0x0280, 0x7ba) != 0)
        f_0000_0295(*(uint16_t far *)MK_FP(0x0280, 0x7bc));
    if (StshStrongDatHnd >= 0)
        f_474a_004e(StshStrongDatHnd);
    f_0000_044f();
    f_0000_069f();
    f_69c8_0000(MK_FP(0x0280, 0x8c28));
    f_0000_08fd(code != 0 ? 0x80 : 0);
}
