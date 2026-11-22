void __cdecl16far musInit(void)

{
  far_t handle;
  far_t handle_00;
  bool bVar1;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  uint8_t *in_DX;
  int iVar2;
  int unaff_SI;
  uint16_t uVar3;
  int size;
  
  size = unaff_SI;
  bVar1 = ovr_midIsLoaded();
  if (CONCAT11(extraout_AH,bVar1) == 0) {
    if ((CFG_Mus < '1') || ('9' < CFG_Mus)) {
      if (('@' < CFG_Mus) && (CFG_Mus < 'G')) {
        unaff_SI = CFG_Mus + -0x38;
      }
    }
    else {
      unaff_SI = CFG_Mus + -0x31;
    }
    if (((uint16_t *)&musDriver0Ofs)[unaff_SI * 2] != 0 ||
        ((uint16_t *)&musDriver0Seg)[unaff_SI * 2] != 0) {
      MidGfxOfs = ovr_stshLoadGfx(cmidpakComOfs);
      MidGfxSeg = (uint16_t)in_DX;   /* hand fix: segment is 16-bit */
      MIDHandle.ofs =
           audio_usesAlignToSeg
                     ((uint8_t *)CONCAT22(*(uint16_t *)((char *)cmidpakComOfs + 5),in_DX),
                      *(uint16_t *)((char *)cmidpakComOfs + 7),size);
      MIDHandle.seg = (uint16_t)in_DX;
      ovr_ovc20_compute1(cmidpakComOfs,cmidpakComSeg);
      handle.seg = ((uint16_t *)&musDriver0Seg)[unaff_SI * 2];
      handle.ofs = ((uint16_t *)&musDriver0Ofs)[unaff_SI * 2];
      MusGfxOfs = ovr_stshLoadGfx(handle);
      uVar3 = (uint16_t)
              ((ulong)*(uint32_t *)((uint16_t *)&musDriver0Ofs + unaff_SI * 2) >> 0x10);
      iVar2 = (int)*(uint32_t *)((uint16_t *)&musDriver0Ofs + unaff_SI * 2);
      MusGfxSeg = (uint16_t)in_DX;   /* hand fix: segment is 16-bit */
      MusHandle_07ca = audio_usesAlignToSeg
                            ((uint8_t *)CONCAT22(*(uint16_t *)(iVar2 + 5),in_DX),
                             *(uint16_t *)(iVar2 + 7),size);
      MusHandleSeg_07cc = (uint16_t)in_DX;   /* hand fix: segment is 16-bit */
      ovr_ovc20_compute1((char *)((uint16_t *)&musDriver0Ofs)[unaff_SI * 2],
                         ((uint16_t *)&musDriver0Seg)[unaff_SI * 2]);
      handle_00.seg = midpakAd.seg;
      handle_00.ofs = midpakAd.ofs;
      MusDrvOfs = ovr_stshLoadGfx(handle_00);
      MusDrvSeg = (uint16_t)in_DX;   /* hand fix: segment is 16-bit */
      ovr_ovc20_compute1((char *)midpakAd.ofs,midpakAd.seg);
      bVar1 = audio_init(MIDHandle.seg);
      if (CONCAT11(extraout_AH_00,bVar1) == 0) {
        MIDHandle.seg = 0;
        MIDHandle.ofs = 0;
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x82);
      }
      ovr_midLoadDriver();
      MusRunning = 1;
    }
  }
  else {
    MusRunning = 1;
  }
  return;
}
