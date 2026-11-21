uint16_t __stdcall16far __INITEMSPAGE(uint16_t pageCount,uint16_t frameSeg,uint16_t handle)

{
  code *pcVar1;
  undefined2 uVar2;
  char extraout_AH;
  char extraout_AH_00;
  undefined1 extraout_AH_01;
  uint16_t extraout_DX;
  
  uVar2 = (uint)startx;   /* hand fix: startx is a function */
  if ((((char *)"Divide error\r\n")[9] & 1U) != 0) {
    if ((((char *)"Divide error\r\n")[9] & 2U) != 0) {
      return 0;
    }
    ((char *)"Divide error\r\n")[9] = ((char *)"Divide error\r\n")[9] | 2;
    *(uint16_t *)((char *)"Divide error\r\n" + 5) = frameSeg;
    *(uint16_t *)((char *)"Divide error\r\n" + 7) = pageCount;
    if (handle == 0) {
      pcVar1 = (code *)swi(0x67);
      (*pcVar1)();
      if (extraout_AH != '\0') {
        return 0xffff;
      }
      ((char *)"Divide error\r\n")[9] = ((char *)"Divide error\r\n")[9] | 4;
      handle = extraout_DX;
    }
    *(uint16_t *)((char *)"Divide error\r\n" + 3) = handle;
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    if (extraout_AH_00 == '\0') {
      pcVar1 = (code *)swi(0x67);
      (*pcVar1)();
      return CONCAT11(extraout_AH_01,extraout_AH_01);
    }
  }
  return 0xffff;
}
