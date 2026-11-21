char __cdecl16far
ovc43_playFliFrames(uint16_t handle,uint16_t paletteOfs,uint16_t paletteSeg,byte delayTicks)

{
  far_t handle_00;
  uint16_t uVar1;
  uint uVar2;
  ulong *puVar3;
  uint16_t in_DX;
  ulong *puVar4;
  undefined2 unaff_DI;
  uint uVar5;
  int iStack_84;
  int iStack_82;
  char cStack_7;
  ulong *puStack_6;
  undefined2 uStack_4;
  
  ovr_stshRead();
  if (iStack_84 != -0x50ef) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x47);
  }
  tempScreenOfs = ovr_stshAlloc(0xfa0f);
  tempScreenSeg = in_DX;
  ovc43_usesStExit(CONCAT22(paletteSeg,paletteOfs),handle,(uint16_t)tempScreenOfs,in_DX);
  ovr_ovr_miceButton0PressSt_789c();
  uStack_4 = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  puVar4 = *(ulong **)BDA_DailyTimeCounter.ofs;   /* hand fix: the offset half is the address, not the far_t struct */
  cStack_7 = '\0';
  puStack_6 = puVar4;
  for (uVar5 = 0; uVar5 < iStack_82 - 1U; uVar5 = uVar5 + 1) {
    do {
      uVar1 = ovr_biosKeyAvail();
      if ((char)uVar1 != '\0') {
        uVar1 = ovr_gameProcessKey();
        if (uVar1 == 0x11b) {
          cStack_7 = '\x02';
        }
        if (uVar1 == 0x1c0d) {
          cStack_7 = '\x01';
        }
      }
      uVar2 = ovr_init2_updateMouseButtons();
      if (((uVar2 != 0) || (rightButtonLatch != '\0')) &&
         (cStack_7 = '\x01', rightButtonLatch != '\0')) {
        cStack_7 = '\x02';
      }
      if (cStack_7 != '\0') goto L_OVC43_6fbe_01a9_02C7;
      puVar3 = ovr_attact_usesBDADailyTim_8bbe(puStack_6,CONCAT22(unaff_DI,uStack_4));
    } while ((puVar4 == (ulong *)0x0) && (puVar4 = (ulong *)0x0, puVar3 < (ulong *)(uint)delayTicks)
            );
    uStack_4 = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    puVar4 = *(ulong **)BDA_DailyTimeCounter.ofs;   /* hand fix: the offset half is the address, not the far_t struct */
    puStack_6 = puVar4;
L_OVC43_6fbe_01a9_02C7:
    if (cStack_7 != '\0') break;
    ovc43_usesStExit(CONCAT22(paletteSeg,paletteOfs),handle,(uint16_t)tempScreenOfs,tempScreenSeg);
  }
  TextBlitDstSeg = 0xa000;
  handle_00.seg = tempScreenSeg;
  handle_00.ofs = (uint16_t)tempScreenOfs;
  ovr_stshFree(handle_00);
  return cStack_7;
}
