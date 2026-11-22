    ovc43_usesFmFreeAudio
              ((uint32_t)CONCAT22(unaff_SS,&remainingLo),(char_sheet_t *)sheetOfs,sheetSeg);
  }
  return;
}



/* 6fbe:01a9 */
char __cdecl16far
ovc43_playFliFrames(uint16_t handle,uint16_t paletteOfs,uint16_t paletteSeg,byte delayTicks)

{
  far_t handle_00;
  uint16_t uVar1;
  uint uVar2;
  ulong *puVar3;
  uint16_t in_DX;
  ulong *puVar4;
  uint16_t unaff_DI;
  uint uVar5;
  int iStack_84;
  int iStack_82;
  char cStack_7;
  ulong *puStack_6;
  uint16_t uStack_4;
  
  ovr_stshRead();
  if (iStack_84 != -0x50ef) {
