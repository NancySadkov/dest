int __cdecl16far _OvrInitEms(uint16_t emsHandle,uint16_t firstPage,uint16_t pages)

{
  long lVar1;
  long lVar2;
  uint16_t uVar3;
  uint uVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  
  uVar3 = (uint)startx;   /* hand fix: startx is a function */
  if ((((byte *)__C0_ASM_CopyRight)[0xc] & 1) == 0) {
    if (emsHandle == 0) {
      uVar4 = __INITEMS();
      if (uVar4 == 0) {
        return -1;
      }
      if (uVar4 <= firstPage) {
        return -1;
      }
      if ((pages == 0) || (uVar4 - firstPage <= pages)) {
        pages = uVar4 - firstPage;
      }
    }
    else {
      if (pages == 0) {
        return -1;
      }
      if (pages <= firstPage) {
        return -1;
      }
      ((char *)"Divide error\r\n")[9] = ((char *)"Divide error\r\n")[9] | 1;
    }
    uVar4 = (uint)(CONCAT22(*(int *)0x8514 + (uint)(0xc000 < *(uint *)&__OvrSize),
                            *(uint *)&__OvrSize + 0x3fff) / 0x4000);
    if (uVar4 < pages) {
      pages = uVar4;
    }
    if ((3 < pages) || (*(uint *)((int)&GUnitDescriptions[0xb].seg + 1) <= pages * 0x400)) {
      uVar5 = __INITEMSPAGE(pages,firstPage,emsHandle);
      if (uVar5 == 0) {
        lVar1 = (ulong)firstPage * 0x4000;
        uVar6 = (uint16_t)((ulong)lVar1 >> 0x10);
        *(uint16_t *)((int)&GUnitDescriptions[0x15].ofs + 1) = (int)lVar1;
        *(uint16_t *)((int)&GUnitDescriptions[0x15].seg + 1) = uVar6;
        lVar2 = (ulong)pages * 0x4000 + lVar1;
        *(uint16_t *)((int)&GUnitDescriptions[0x16].ofs + 1) = (int)lVar2;
        *(uint16_t *)((int)&GUnitDescriptions[0x16].seg + 1) = (int)((ulong)lVar2 >> 0x10);
        *(uint16_t *)((int)&GUnitDescriptions[0x17].ofs + 1) = (int)lVar1;
        *(uint16_t *)((int)&GUnitDescriptions[0x17].seg + 1) = uVar6;
        *(uint16_t *)((int)&GUnitDescriptions[0x18].ofs + 1) = 0xa48;
        *(uint16_t *)((int)&GUnitDescriptions[0x18].seg + 1) = 0;
        *(uint16_t *)((int)&GUnitDescriptions[9].seg + 1) = 1;
        ((byte *)__C0_ASM_CopyRight)[0xc] = ((byte *)__C0_ASM_CopyRight)[0xc] | 2;
        *(uint16_t *)((int)(uint32_t *)&_StartTime + 3) = 0xe9f;
        *(uint16_t *)((int)(int *)&errno + 1) = 0xd0e;
        return 0;
      }
      return uVar5;
    }
  }
  return -1;
}
