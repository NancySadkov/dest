char_sheet_t * __cdecl16far
ovc43_usesFmFreeAudio(uint32_t gindex,char_sheet_t *sheet,uint16_t sheetSeg)

{
  char *pcVar1;
  uint16_t uVar2;
  far_t far *pfVar3;
  char_sheet_t *pcVar4;
  uint16_t in_CX;
  char_sheet_t *pcVar5;
  uint uVar6;
  uint16_t unaff_SI;
  int iVar7;
  int unaff_DI;
  uint16_t uVar8;
  byte bStack_8;
  char_sheet_t *uStack_6;   /* hand fix: used as uStack_6->nameText and (char_sheet_t *)uStack_6 */
  
  pcVar4 = (char_sheet_t *)((char *)0x2410);
  TextBlitDstSeg = 0xa000;
  iVar7 = 0;
  while( true ) {
    uVar8 = (uint16_t)(gindex >> 0x10);
    if (*(int *)((int)gindex + 6) <= iVar7) {
      return pcVar4;
    }
    uStack_6 = (char_sheet_t *)CONCAT22(sheetSeg,sheet);
    bStack_8 = (byte)sheetSeg;
    pcVar5 = (char_sheet_t *)(sheet->nameText + 6);
    uVar6 = *(int *)(sheet->nameText + 4) - 0xb;
    if (uVar6 < 6) break;
    pcVar4 = (char_sheet_t *)
             ovr_lowNibble((uint)(sheet->nameText + *(int *)uStack_6->nameText),sheetSeg);
    iVar7 = iVar7 + 1;
    sheet = pcVar4;
    sheetSeg = (uint16_t)pcVar5;
  }
  switch(uVar6) {
  case 0:
    do {
    } while (bStack_8 == 0xff);
    goto code_r0x00061e64;
  case 1:
    pcVar1 = (char *)(uVar6 * 2 + iVar7);
    *pcVar1 = *pcVar1 + (char)pcVar5;
    break;
  case 2:
    goto L_OVC30_619c_0339_03CE;
  case 3:
    goto code_r0x00061d78;
  case 4:
    if (-1 < (int)uVar6) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x21,sheetSeg);
    }
    sheetSeg = 0x2410;
code_r0x00061d78:
    if (*(bool *)&GameRunning == false) {
      ovr_fmFreeAudio(1);
    }
L_OVC30_619c_0339_03CE:
    pcVar4 = ovr_stshAlloc(0xae);
    uStack_6 = (char_sheet_t *)CONCAT22(pcVar5,pcVar4);
    bStack_8 = GLeaderCount;
    uVar6 = (uint)GLeaderCount;
    ((uint16_t *)(uVar6 * 4))[1] = (uint16_t)pcVar5;   /* hand fix: segment half into a 2-byte slot */
    *(uint16_t *)(uVar6 * 4) = (uint16_t)pcVar4;   /* hand fix: offset half into a 2-byte slot */
    GLeaderCount = GLeaderCount + 1;
    break;
  case 5:
    pcVar1 = (char *)(uVar6 * 2 + unaff_DI + -0x1ba);
    *pcVar1 = *pcVar1 + (char)in_CX;
    uStack_6 = (char_sheet_t *)CONCAT22(sheetSeg,pcVar5);
  }
  _fmemset((void *)(ulong)(*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),0xae,unaff_SI);
  strcpy(uStack_6->nameText,
         (char *)CONCAT22(*(uint16_t *)
                           ((int)&worldMenuLabels[1].ofs + 1 + (uint)(byte)gindex * 0x95),
                          (char *)*(uint16_t *)
                                   ((int)&worldMenuLabels[0].seg + 1 + (uint)(byte)gindex * 0x95)));
  *(undefined1 *)((int)(char_sheet_t *)uStack_6 + 0x3d) = 1;
  *(uint16_t *)((int)(char_sheet_t *)uStack_6 + 0x39) = uVar8;
  *(uint16_t *)((int)(char_sheet_t *)uStack_6 + 0x3b) = (uint16_t)sheet;   /* hand fix: only the offset half is stored */
  *(byte *)((int)(char_sheet_t *)uStack_6 + 0x3e) = (byte)gindex;
  *(undefined1 *)((int)(char_sheet_t *)uStack_6 + 0x2f) = 0xff;
  *(undefined1 *)((int)(char_sheet_t *)uStack_6 + 0x30) = 3;
  uVar2 = ovr_randBelow(1);
  *(undefined1 *)((int)(char_sheet_t *)uStack_6 + 0x34) = (char)uVar2;
code_r0x00061e64:
  ovr_manage_rollStats((char_sheet_t *)uStack_6);
  uVar8 = (uint16_t)((ulong)uStack_6 >> 0x10);
  if (*(char *)((int)&worldMenuLabels[0xc].seg + (uint)(byte)gindex * 0x95) != -1) {
    ((char_sheet_t *)uStack_6)->stats[1] =
         *(byte *)((int)&worldMenuLabels[0xc].seg + (uint)(byte)gindex * 0x95);
  }
  if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)(byte)gindex * 0x95) & 0x800) != 0) {
    ((char_sheet_t *)uStack_6)->stats[4] = 0x12;
  }
  ((char_sheet_t *)uStack_6)->faction =
       *(uint8_t *)((int)(char **)GMenuStrings + (uint)(byte)gindex * 0x95 + 0x1f);
  ((char_sheet_t *)uStack_6)->alignment =
       *(byte *)((int)(far_t far *)(worldMenuLabels + 9) + (uint)(byte)gindex * 0x95);
  ((char_sheet_t *)uStack_6)->hp[0] =
       *(byte *)((int)&worldMenuLabels[6].seg + (uint)(byte)gindex * 0x95);
  ((char_sheet_t *)uStack_6)->hp[1] = ((char_sheet_t *)uStack_6)->hp[0];
  ((char_sheet_t *)uStack_6)->statMask = ((char_sheet_t *)uStack_6)->statMask | 0x16;
  ((char_sheet_t *)uStack_6)->spyReports = 0x1;
  *(uint16_t *)((int)&((char_sheet_t *)uStack_6)->gold + 2) = 0;
  *(uint16_t *)&((char_sheet_t *)uStack_6)->gold = 100;
  ((char_sheet_t *)uStack_6)->partySlot = 0xff;
  pfVar3 = ovr_ovc22_textRingProt(bStack_8);
  return (char_sheet_t *)CONCAT11((char)((uint)pfVar3 >> 8),bStack_8);
}
