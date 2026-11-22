void bldng_selectBuildingType(byte partyIndex)

{
  uint16_t uVar1;
  far_t entries;
  far_t entries_00;
  far_t hint;
  uint uVar2;
  uint16_t uVar3;
  int iVar4;
  char *pcVar5;
  uint8_t *puVar6;
  uint16_t uVar7;
  uint16_t count;
  char *unaff_SS;
  byte in_stack_00000004;
  undefined1 uVar8;
  uint8_t buildTypes;
  uint8_t menuEntries;
  uint16_t auStack_190 [97];
  char acStack_ce [200];
  int iStack_6;
  char cStack_4;
  byte bStack_3;
  
  bStack_3 = '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 +
                                 (uint)((char_sheet_t *)(((uint)in_stack_00000004 << 2)))->classStr * 0x95) & 0x1f);
  buildTypes = bldng_getClass(in_stack_00000004);
  buildTypes = buildTypes & 0xff;
  auStack_190[0] = *(uint16_t *)((int)&GStrangeTable[0x31].seg + buildTypes * 4);
  menuEntries = ((far_t far *)(GStrangeTable + 0x31) + buildTypes)->ofs;
  count = 1;
  iStack_6 = 7;
  while( true ) {
    if (0x30 < iStack_6) break;
    uVar2 = bldng_usesGStrangeTable((byte)iStack_6);
    if ((*(byte *)((uVar2 & 0xff) * 0x27 + 0x11f) & bStack_3) != 0) {
      uVar2 = bldng_usesGStrangeTable((byte)iStack_6);
      if (*(char *)((uVar2 & 0xff) * 0x27 + 0x12d) == '\0') {
        uVar3 = bldng_compute2((uint8_t)iStack_6,in_stack_00000004);
        if ((char)uVar3 != '\0') {
          *(int *)(&buildTypes + count * 2) = iStack_6;
          uVar1 = ((far_t far *)(GStrangeTable + 0x31) + iStack_6)->ofs;
          auStack_190[count * 2] = *(uint16_t *)((int)&GStrangeTable[0x31].seg + iStack_6 * 4);
          *(uint16_t *)(&menuEntries + count * 4) = uVar1;
          count = count + 1;
        }
      }
    }
    iStack_6 = iStack_6 + 1;
  }
  entries_00.seg = (uint16_t)unaff_SS;
  entries_00.ofs = (uint16_t)&menuEntries;
  bldng_buildMenuEntries
            ((uint32_t)CONCAT22(unaff_SS,&buildTypes),entries_00,count,in_stack_00000004);
  uVar2 = bldng_usesGStrangeTable
                    (((char_sheet_t *)(((uint)in_stack_00000004 << 2)))->buildType[0]);
  iVar4 = (uVar2 & 0xff) * 0x27;
  uVar7 = 0x195d;
  uVar3 = *(uint16_t *)(iVar4 + 0x10e);
  uVar8 = (undefined1)uVar3;
  pcVar5 = ovr_stsprintf(acStack_ce,(char *)CONCAT22(0x690b,unaff_SS),
                         (char *)CONCAT13((char)((uint)uVar3 >> 8),CONCAT12(uVar8,0x2410)),uVar8,
                         (char)*(uint16_t *)(iVar4 + 0x110));
  puVar6 = &menuEntries;
  entries.seg = (uint16_t)unaff_SS;
  entries.ofs = (uint16_t)puVar6;
  (*(uint8_t *)((uint8_t *)&(hint.seg))) = (char)uVar7;
  hint.ofs = (uint16_t)pcVar5;
  (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = (char)((uint)uVar7 >> 8);
  ovr_ovc28_compute2(entries,count,hint,(char)pcVar5);
  cStack_4 = (char)puVar6;
  if ((char)puVar6 != '\0') {
    ((char_sheet_t *)(((uint)in_stack_00000004 << 2)))->buildType[0] =
         (&stack0xfe0a)[((uint)puVar6 & 0xff) * 2];
  }
  return;
}
