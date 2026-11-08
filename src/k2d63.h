#include "dgroup.h"

#define ENTER_INT66 asm db 06h, 1Eh, 56h, 57h
#define LEAVE_INT66 asm db 5Fh, 5Eh, 1Fh, 07h

/* 2D63:0000  linear address -> far pointer (result in DX:AX) */
#pragma codeseg OV_2D63_TEXT

void __cdecl16far f_2d63_0000(unsigned offv, unsigned segv);
void __cdecl16far f_2d63_0016(unsigned v);
void __cdecl16far f_2d63_0030(void);
void __cdecl16far f_2d63_0039(void);
void __cdecl16far f_2d63_004a(void);
void __cdecl16far f_2d63_005d(void);
void __cdecl16far f_2d63_00aa(void);
void __cdecl16far f_2d63_00eb(unsigned segv, unsigned offv);
void __cdecl16far f_2d63_00fc(unsigned x);
void __cdecl16far f_2d63_0107(void);
void __cdecl16far f_2d63_014b(void);
void __cdecl16far f_2d63_017a(void);
void __cdecl16far f_2d63_0190(void);
void __cdecl16far f_2d63_01a7(unsigned x, unsigned y);
void __cdecl16far f_2d63_01bf(void);
void __cdecl16far f_2d63_01df(void);
void __cdecl16far f_2d63_0203(void);
void __cdecl16far f_2d63_0241(void);
void __cdecl16far f_2d63_0292(void);
void __cdecl16far f_2d63_02b5(void);
void __cdecl16far f_2d63_02fe(void);
void __cdecl16far f_2d63_032d(void);
void __cdecl16far f_2d63_03b6(void);
void __cdecl16far f_2d63_03fc(void);
void __cdecl16far f_2d63_044f(void);
void __cdecl16far f_2d63_04b7(void);
void __cdecl16far f_2d63_05a9(void);
void __cdecl16far f_2d63_05e5(void);
void __cdecl16far f_2d63_06bf(void);
void __cdecl16far f_2d63_06d1(char far *p);
void __cdecl16far f_2d63_06e6(char far *p);
void __cdecl16far f_2d63_06fb(void);
void __cdecl16far f_2d63_070d(void);
void __cdecl16far f_2d63_075f(unsigned x);
void __cdecl16far f_2d63_0774(unsigned x, unsigned y);
void __cdecl16far f_2d63_078c(unsigned a, unsigned b, unsigned c, unsigned d);
void __cdecl16far f_2d63_07aa(void);
void __cdecl16far f_2d63_07bc(void);
void __cdecl16far f_2d63_07ce(void);
void __cdecl16far f_2d63_07fb(unsigned a, unsigned b, unsigned c, unsigned d);
void __cdecl16far f_2d63_0819(unsigned x);
void __cdecl16far f_2d63_082e(unsigned a, unsigned b);
void __cdecl16far f_2d63_0846(void);
void __cdecl16far f_2d63_09c9(void);
void __cdecl16far f_2d63_0a18(void);
void __cdecl16far f_2d63_0a24(void);
void __cdecl16far f_2d63_0a67(void);
void __cdecl16far f_2d63_0aac(void);
void __cdecl16far f_2d63_0af7(void);
void __cdecl16far f_2d63_0b4d(void);
void __cdecl16far f_2d63_0b94(unsigned offv, unsigned segv);
void __cdecl16far f_2d63_0bad(char far *src, char far *dst, unsigned words);
void __cdecl16far f_2d63_0bc8(char far *dst, unsigned words);
void __cdecl16far f_2d63_0bde(void);
