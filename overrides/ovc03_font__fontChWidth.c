/* 302d:04eb */

uint8_t __cdecl16far fontChWidth(uint8_t far *widths,char ch)

{
  uint8_t width;

  if ((byte)ch < 0x20) {
    width = 0x0;
  }
  else {
    width = widths[(byte)ch + 0xa1];
  }
  return width;
}
