int __cdecl16far ovc45_compute9(char *dest,char *src,char *font,uint maxWidth,char mode,...)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char in_stack_00000012;
  int iStack_4;
  
  uVar2 = ovr_font_textWidth((*(uint16_t *)((uint8_t *)&(src) + 2)),font,maxWidth);
  if (mode < uVar2) {
    if (in_stack_00000012 == '\x02') {
      iStack_4 = ovr_font_textWidth((char *)"..",
                                    (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(font) + 2)),(char *)0x2410),maxWidth)
      ;
    }
    else {
      iStack_4 = ovr_font_textWidth((char *)"...",
                                    (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(font) + 2)),(char *)0x2410),maxWidth)
      ;
    }
    iVar3 = 0;
    for (iVar4 = 0;
        (((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   iVar3] != '\0' &&
        ((int)(iStack_4 + iVar4 + (uint)*(byte *)((*(uint16_t *)((uint8_t *)&(font) + 2)) + ((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   iVar3] + 0xa1)) <=
         (int)mode)); iVar4 = iVar4 + (uint)bVar1) {
      bVar1 = *(byte *)((*(uint16_t *)((uint8_t *)&(font) + 2)) + ((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   iVar3] + 0xa1);
      dest[iVar3] = ((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   iVar3];
      iVar3 = iVar3 + 1;
    }
    dest[iVar3] = '.';
    dest[iVar3 + 1] = '.';
    iVar4 = iVar3 + 2;
    if (in_stack_00000012 != '\x02') {
      dest[iVar4] = '.';
      iVar4 = iVar3 + 3;
    }
    dest[iVar4] = '\0';
    (*(uint16_t *)((uint8_t *)&(src) + 2)) = (uint16_t)dest;   /* hand fix: 2-byte segment half */
  }
  return (int)(*(uint16_t *)((uint8_t *)&(src) + 2));
}
