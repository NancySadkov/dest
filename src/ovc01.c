/* Recovered OVC01 driver helpers. */
#include "st_compat.h"
#include "st_types.h"

/* 2D63:0000, 22 bytes.
 * Original is an assembly helper.  It normalizes an ofs:seg pair:
 *   seg += ofs >> 4; ofs &= 0x0f; result in DX:AX.
 */
uint32_t __cdecl16far mkp(uint16_t ofs, uint16_t seg)
{
  asm mov dx,[bp+8]
  asm mov ax,[bp+6]
  asm db 8Bh, 0D8h
  asm mov cl,4
  asm shr bx,cl
  asm db 03h, 0D3h
  asm and ax,0xf
}
