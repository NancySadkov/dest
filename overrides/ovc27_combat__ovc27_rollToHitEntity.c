int __cdecl16far ovc27_rollToHitEntity(uint32_t agnt,byte column,...)

{
  undefined4 uVar1;
  char cVar2;
  uint16_t uVar3;
  int iVar4;
  undefined2 uVar5;
  byte bStack_9;
  byte bStack_8;
  byte bStack_7;
  undefined1 *uStack_6;   /* hand fix: dereferenced as *uStack_6, compared with 0xff */
  
  uVar5 = (undefined2)(agnt >> 0x10);
  iVar4 = (int)agnt;
  bStack_7 = *(byte *)((int)*(undefined4 *)(iVar4 + 0x17) + 0xf);
  bStack_8 = *(byte *)((int)*(undefined4 *)(iVar4 + 0x1d) + 0x46);
  if ((bStack_8 == 0xff) && (bStack_8 = 0, *(byte *)((int)*(undefined4 *)(iVar4 + 0x1d) + 0x53) < 4)
     ) {
    bStack_7 = bStack_7 >> 1;
  }
  uStack_6 = (byte *)CONCAT22(*(undefined2 *)((int)&RampTables[0].seg + (uint)bStack_8 * 4),
                              (byte *)((far_t far *)RampTables + bStack_8)->ofs);
  while ((*uStack_6 != 0xff && (*uStack_6 < bStack_7))) {
    uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + 6);
  }
  bStack_9 = ((byte *)uStack_6)[column + 1];
  if ((column == 3) && (*(char *)((int)*(undefined4 *)(iVar4 + 0x17) + 0x1a) != -1)) {
    uVar1 = *(undefined4 *)((uint)*(byte *)((int)*(undefined4 *)(iVar4 + 0x17) + 0x1a) << 2);
    cVar2 = ovr_manage_abilityModifier(*(byte *)((int)uVar1 + 0x2b));
    bStack_9 = bStack_9 - cVar2;
  }
  uVar3 = ovr_randBelow(0x14);
  if ((int)((uVar3 & 0xff) + 1) < (int)(char)bStack_9) {
    iVar4 = (uint)(byte)((char)bStack_9 >> 7) << 8;
  }
  else {
    iVar4 = CONCAT11((char)bStack_9 >> 7,1);
  }
  return iVar4;
}
