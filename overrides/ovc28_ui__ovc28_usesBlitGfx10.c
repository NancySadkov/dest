/* ovc28_usesBlitGfx10 - recovered from STRONG.EXE.
   x starts at 0xeb and is used as dst.ofs base and TextBlitX; y starts at 0x3c,
   forms dst.ofs = x + y*0x140 (the VGA scanline width) and TextBlitY, stepping by
   0xe per entry; idx walks the count far_t entries at stride 4. */
void __cdecl16far ovc28_usesBlitGfx10(far_t entries,int count)

{
  far_t gfx;
  char *pcVar1;
  uint8_t *puVar2;
  uint16_t uVar3;
  int *piVar4;
  undefined2 *puVar5;
  int idx;
  int y;
  uint16_t uVar8;
  char *unaff_SS;
  far_t gfx_00;
  uint16_t max_width;
  uint8_t uVar9;
  far_t dst;
  uint8_t text;
  int x;
  undefined1 *uStack_6;   /* hand fix: dereferenced as *uStack_6 */
  
  gfx_00.seg = fullScreenGfxSeg;
  gfx_00.ofs = fullScreenGfxOfs;
  ovr_blitGfx10(gfx_00,0,0,(brect_t *)0x5ce5,true);
  x = 0xeb;
  y = 0x3c;
  for (idx = 0; idx < count; idx = idx + 1) {
    uVar8 = entries.seg;
    uVar3 = entries.ofs;
    piVar4 = (int *)(uVar3 + idx * 4);
    if (*piVar4 != 0 || piVar4[1] != 0) {
      dst.seg = 0xa000;
      dst.ofs = x + y * 0x140;
      gfx.seg = butt01Cut5Seg;
      gfx.ofs = butt01Cut5Ofs;
      ovr_blitLoadRleGfx(gfx,dst);
      TextBlitDstSeg = 0xa000;
      TextBlitX = x + 6;
      TextBlitY = y + 2;
      puVar5 = (undefined2 *)(uVar3 + idx * 4);
      pcVar1 = (char *)puVar5[1];
      puVar2 = (uint8_t *)*puVar5;
      uStack_6 = (uint8_t *)CONCAT22(pcVar1,puVar2);
      if (*uStack_6 == 0x25) {
        BlitLetterType = 2;
        uVar9 = 0x3f;
        uVar3 = FontMain.ofs;
        uVar8 = FontMain.seg;
        pcVar1 = (char *)ovr_ovc45_compute9((char *)&text,(char *)CONCAT22(puVar2 + 1,unaff_SS),
                                            (char *)CONCAT22(FontMain.ofs,pcVar1),FontMain.seg,'E',3
                                           );
        ovr_blitLabel(pcVar1,(uint8_t *)CONCAT22(uVar3,puVar2),uVar8,uVar9);
        BlitLetterType = 0;
      }
      else if (*uStack_6 == 0x40) {
        uVar9 = 0x3f;
        uVar3 = FontMain.ofs;
        uVar8 = FontMain.seg;
        pcVar1 = (char *)ovr_ovc45_compute9((char *)&text,(char *)CONCAT22(puVar2 + 1,unaff_SS),
                                            (char *)CONCAT22(FontMain.ofs,pcVar1),FontMain.seg,'E',3
                                           );
        ovr_blitLabel(pcVar1,(uint8_t *)CONCAT22(uVar3,puVar2),uVar8,uVar9);
      }
      else {
        uVar9 = 0x3f;
        puVar5 = (undefined2 *)(uVar3 + idx * 4);
        uVar3 = FontMain.ofs;
        max_width = FontMain.seg;
        pcVar1 = (char *)ovr_ovc45_compute9((char *)&text,(char *)CONCAT22(*puVar5,unaff_SS),
                                            (char *)CONCAT22(FontMain.ofs,(char *)puVar5[1]),
                                            FontMain.seg,'E',3);
        ovr_blitLabel(pcVar1,(uint8_t *)CONCAT22(uVar3,puVar2),max_width,uVar9);
      }
    }
    y = y + 0xe;
  }
  if (goldPartyIndex != 0xff) {
    ovc28_drawGold(goldPartyIndex);
  }
  return;
}
