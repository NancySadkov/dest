void __cdecl16far ovc38_usesStshAlloc(void)

{
  far_t entries;
  int16_t iVar1;
  size_t sVar2;
  void *pvVar3;
  uint16_t in_DX;
  uint16_t uVar4;
  int iVar5;
  uint16_t *puVar6;
  uint16_t unaff_SS;
  far_t handle;
  far_t entries_00;
  far_t handle_00;
  uint8_t msg;
  void *pvStack_8;
  uint16_t uStack_6;
  byte bStack_3;
  
  if ((GHighScoreSaved == '\0') && (bStack_3 = ovr_manage_findFirstLeader(), bStack_3 != 0xff)) {
    pvStack_8 = ovr_stshAlloc(0x18);
    entries.seg = in_DX;
    entries.ofs = (uint16_t)pvStack_8;
    uStack_6 = in_DX;
    ovc38_loadHighScores(entries);
    if (*(int *)((int)pvStack_8 + 0x14) != 0 || *(int *)((int)pvStack_8 + 0x16) != 0) {
      handle.seg = *(uint16_t *)((int)pvStack_8 + 0x16);
      handle.ofs = *(uint16_t *)((int)pvStack_8 + 0x14);
      ovr_stshFree(handle);
    }
    ovr_manage_playerTitle
              ((char_sheet_t *)*(uint16_t *)((uint)bStack_3 * 4),
               ((uint16_t *)((uint)bStack_3 * 4))[1],*(uint16_t *)((uint)bStack_3 * 4),
               ((uint16_t *)((uint)bStack_3 * 4))[1]);
    uVar4 = 0x217a;
    _sprintf((char *)CONCAT22(unaff_SS,&msg),"%c%s%s@%d");
    iVar5 = 5;
    while ((0 < iVar5 &&
           (iVar1 = ovc38_scan1((char *)CONCAT22(unaff_SS,&msg),
                                (char *)CONCAT22(*(uint16_t *)((int)pvStack_8 + iVar5 * 4 + -2),
                                                 (char *)*(uint16_t *)
                                                          ((int)pvStack_8 + iVar5 * 4 + -4))),
           (char)iVar1 == '\0'))) {
      uVar4 = *(uint16_t *)((int)pvStack_8 + iVar5 * 4 + -4);
      puVar6 = (uint16_t *)((int)pvStack_8 + iVar5 * 4);
      puVar6[1] = *(uint16_t *)((int)pvStack_8 + iVar5 * 4 + -2);
      *puVar6 = uVar4;
      iVar5 = iVar5 + -1;
    }
    sVar2 = strlen((char *)CONCAT22(unaff_SS,&msg));
    pvVar3 = ovr_stshAlloc((ulong)(sVar2 + 1));
    puVar6 = (uint16_t *)((int)pvStack_8 + iVar5 * 4);
    puVar6[1] = uVar4;
    *puVar6 = (uint16_t)pvVar3;   /* hand fix: 2-byte slot */
    puVar6 = (uint16_t *)((int)pvStack_8 + iVar5 * 4);
    strcpy((char *)CONCAT22(puVar6[1],(char *)*puVar6),(char *)CONCAT22(unaff_SS,&msg));
    entries_00.seg = uStack_6;
    entries_00.ofs = (uint16_t)pvStack_8;
    ovc38_saveHighScores(entries_00);
    handle_00.seg = uStack_6;
    handle_00.ofs = (uint16_t)pvStack_8;
    ovc38_usesStshFree(handle_00);
    GHighScoreSaved = '\x01';
  }
  return;
}
