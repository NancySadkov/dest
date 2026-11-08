#include "k2d63.h"

void __cdecl16far f_2d63_07fb(unsigned a, unsigned b, unsigned c, unsigned d)
{
  ENTER_INT66;
  asm mov bx, b
  asm mov cx, a
  asm mov dx, d
  asm db 8Bh, 76h, 0Ah        /* mov si, [bp+0ah] */
  asm mov ax, 0x710
  asm int 0x66
  LEAVE_INT66;
}

void __cdecl16far f_2d63_0819(unsigned x)
{
  ENTER_INT66;
  asm mov dx, x
  asm mov ax, 0x697
  asm int 0x66
  LEAVE_INT66;
}

void __cdecl16far f_2d63_082e(unsigned a, unsigned b)
{
  ENTER_INT66;
  asm mov ax, 0x70f
  asm mov bx, a
  asm mov cx, b
  asm int 0x66
  LEAVE_INT66;
}
