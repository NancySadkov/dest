uint __cdecl16far ovc30_createLeader(byte gindex,uint16_t x,uint16_t y)

{
  undefined2 uVar1;
  uint uVar2;
  uint16_t uVar3;
  far_t far *pfVar4;
  uint in_DX;
  byte partyIndex;
  uint count;
  char_sheet_t *pcStack_6;
  uint uStack_4;
  
  count = 0;
  while ((count < GLeaderCount && (*(char *)((int)*(undefined4 *)(count << 2) + 0x28) != '\0'))) {
    count = count + 1;
  }
  if (count < GLeaderCount) {
    uStack_4 = ((undefined2 *)(count * 4))[1];
    pcStack_6 = (char_sheet_t *)*(undefined2 *)(count * 4);
  }
  else {
    if (0x4f < GLeaderCount) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x21);
    }
    if (!GameRunning) {
      ovr_fmFreeAudio(1);
    }
    pcStack_6 = ovr_stshAlloc(0xae);
    count = (uint)GLeaderCount;
    uVar2 = (uint)GLeaderCount;
    ((undefined2 *)(uVar2 * 4))[1] = in_DX;
    *(undefined2 *)(uVar2 * 4) = (uint16_t)pcStack_6;   /* hand fix: store of the far pointer's offset half */
    GLeaderCount = GLeaderCount + 1;
    uStack_4 = in_DX;
  }
  _fmemset((void *)(ulong)uStack_4,0xae,count);
  partyIndex = (byte)count;
  uVar1 = *(undefined2 *)((int)&worldMenuLabels[1].ofs + 1 + (uint)gindex * 0x95);
  strcpy((char *)CONCAT22(uStack_4,pcStack_6),
         (char *)CONCAT13((char)((uint)uVar1 >> 8),
                          CONCAT12((char)uVar1,
                                   *(undefined2 *)
                                    ((int)&worldMenuLabels[0].seg + 1 + (uint)gindex * 0x95))));
  pcStack_6->active = 1;
  pcStack_6->x = x;
  pcStack_6->y = y;
  pcStack_6->classStr = gindex;
  pcStack_6->cls = 0xff;
  pcStack_6->race = 3;
  uVar3 = ovr_randBelow(1);
  pcStack_6->gender = (byte)uVar3;
  ovr_manage_rollStats(pcStack_6,(char)uStack_4);
  if (*(char *)((int)&worldMenuLabels[0xc].seg + (uint)gindex * 0x95) != -1) {
    pcStack_6->stats[1] = *(byte *)((int)&worldMenuLabels[0xc].seg + (uint)gindex * 0x95);
  }
  if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)gindex * 0x95) & 0x800) != 0) {
    pcStack_6->stats[4] = 0x12;
  }
  pcStack_6->faction = *(uint8_t *)((int)(char **)GMenuStrings + (uint)gindex * 0x95 + 0x1f);
  pcStack_6->alignment = *(byte *)((int)(far_t far *)(worldMenuLabels + 9) + (uint)gindex * 0x95);
  pcStack_6->hp[0] = *(byte *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
  pcStack_6->hp[1] = pcStack_6->hp[0];
  pcStack_6->statMask = pcStack_6->statMask | 0x16;
  pcStack_6->spyReports = 0x1;
  *(undefined2 *)((int)&pcStack_6->gold + 2) = 0;
  *(undefined2 *)&pcStack_6->gold = 100;
  pcStack_6->partySlot = 0xff;
  pfVar4 = ovr_ovc22_textRingProt(partyIndex);
  return CONCAT11((char)((uint)pfVar4 >> 8),partyIndex);
}
