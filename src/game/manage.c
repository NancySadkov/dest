#include "dgroup.h"

struct unit4d2 {
  char pad0[0x3D];
  unsigned char f3d;
  char pad1[0x4B];
  unsigned char f89;
};

void __cdecl16far f_4d05_0000(void)
{
  register int i;
  register int j;
  struct unit4d2 far *p;
  for (i = 0; i < 5; i++)
    ((unsigned char far *)MK_FP(0x0280, 0x90DE))[i] = 0xFF;
  for (j = 0; j < *(unsigned char far *)MK_FP(0x0280, 0x90E6); j++) {
    p = *(struct unit4d2 far * far *)MK_FP(0x0070, j * 4);
    if (p->f3d != 0 && p->f89 != 0xFF)
      ((unsigned char far *)MK_FP(0x0280, 0x90DE))[p->f89] =
          (unsigned char)j;
  }
}
