#include "k2d63.h"

void __cdecl16far f_2d63_075f(unsigned x)
{
  ENTER_INT66;
  asm mov ax, 0x702
  asm mov bx, x
  asm int 0x66
  LEAVE_INT66;
}

void __cdecl16far f_2d63_0774(unsigned x, unsigned y)
{
  ENTER_INT66;
  asm mov ax, 0x703
  asm mov bx, x
  asm mov cx, y
  asm int 0x66
  LEAVE_INT66;
}

void __cdecl16far f_2d63_078c(unsigned a, unsigned b, unsigned c, unsigned d)
{
  ENTER_INT66;
  asm mov ax, 0x704
  asm mov bx, a
  asm mov cx, b
  asm db 8Bh, 76h, 0Ah        /* mov si, [bp+0ah] */
  asm db 8Bh, 7Eh, 0Ch        /* mov di, [bp+0ch] */
  asm int 0x66
  LEAVE_INT66;
}

void __cdecl16far f_2d63_07aa(void)
{
  ENTER_INT66;
  asm mov ax, 0x705
  asm int 0x66
  LEAVE_INT66;
}

void __cdecl16far f_2d63_07bc(void)
{
  ENTER_INT66;
  asm mov ax, 0x70c
  asm int 0x66
  LEAVE_INT66;
}
