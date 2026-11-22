void __cdecl16far sfxInit(void)

{
  far_t handle;
  bool bVar1;
  undefined1 extraout_AH;
  uint8_t *in_DX;
  int iVar2;
  int unaff_SI;
  uint16_t uVar3;
  int size;
  
  size = unaff_SI;
  bVar1 = ovr_digIsInstalled();
  if (bVar1) {
    SfxRunning = 1;
  }
  else {
    if ((CFG_Sfx < '1') || ('9' < CFG_Sfx)) {
      if (('@' < CFG_Sfx) && (CFG_Sfx < 'G')) {
        unaff_SI = CFG_Sfx + -0x38;
      }
    }
    else {
      unaff_SI = CFG_Sfx + -0x31;
    }
    if (((uint16_t *)&ibmsndComOfs)[unaff_SI * 2] != 0 ||
        ((uint16_t *)&ibmsndComSeg)[unaff_SI * 2] != 0) {
      (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)((uint16_t *)&ibmsndComSeg)[unaff_SI * 2];
      handle.ofs = ((uint16_t *)&ibmsndComOfs)[unaff_SI * 2];
      (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)((uint16_t *)&ibmsndComSeg)[unaff_SI * 2] >> 8);
      SfxGfxOfs = ovr_stshLoadGfx(handle);
      uVar3 = (uint16_t)
              ((ulong)*(uint32_t *)((uint16_t *)&ibmsndComOfs + unaff_SI * 2) >> 0x10);
      iVar2 = (int)*(uint32_t *)((uint16_t *)&ibmsndComOfs + unaff_SI * 2);
      SfxGfxSeg = (uint16_t)in_DX;   /* hand fix: segment is 16-bit */
      DIGHandle.ofs =
           audio_usesAlignToSeg
                     ((uint8_t *)CONCAT22(*(uint16_t *)(iVar2 + 5),in_DX),*(uint16_t *)(iVar2 + 7)
                      ,size);
      DIGHandle.seg = (uint16_t)in_DX;
      audio_parseHexDigit((char *)CONCAT22(in_DX,DIGHandle.ofs),CFG_Irq);
      ovr_ovc20_compute1((char *)((uint16_t *)&ibmsndComOfs)[unaff_SI * 2],
                         (char)((uint16_t *)&ibmsndComSeg)[unaff_SI * 2]);
      bVar1 = audio_init(DIGHandle.seg);
      if (CONCAT11(extraout_AH,bVar1) == 0) {
        DIGHandle.seg = 0;
        DIGHandle.ofs = 0;
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x81);
      }
      SfxRunning = 1;
    }
  }
  return;
}
