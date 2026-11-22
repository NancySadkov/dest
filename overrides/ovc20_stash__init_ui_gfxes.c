void __cdecl16far init_ui_gfxes(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t handle;
  far_t handle_00;
  far_t ptr;
  far_t handle_01;
  far_t hndl;
  far_t hndl_00;
  far_t hndl_01;
  char *pcVar1;
  far_t far *pfVar2;
  void *pvVar3;
  uint16_t in_DX;
  uint16_t uVar4;
  uint16_t i;
  uint16_t unaff_DI;
  uint16_t unaff_SS;
  uint8_t palette;
  stg_tmp_t *psStack_e;
  stg_tmp_t *psStack_a;
  void *pvStack_6;
  uint16_t uStack_4;
  
  handle.seg = Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  psStack_a = ovr_stshLoadGfx(handle);
  pcVar1 = (char *)ovr_calcSeasonPalette(psStack_a->cmap,in_DX,&palette,unaff_SS,(char)&palette);
  init_special_graphics((char *)CONCAT22(in_DX,pcVar1));
  ovr_vgaSetPalette8bit(&palette);
  init_special_graphics((char *)CONCAT22(Lbm_nwpanel1.seg,Lbm_nwpanel1.ofs));
  handle_00.seg = specialColorsSeg;
  handle_00.ofs = (uint16_t)specialColorsOfs;
  psStack_e = ovr_stshLoadGfx(handle_00);
  memcpy((char *)SpecialColors,(char *)CONCAT13((char)(in_DX >> 8),CONCAT12((char)in_DX,psStack_e)),
         8);
  init_special_graphics((char *)CONCAT22(specialColorsSeg,specialColorsOfs));
  pvStack_6 = ovr_stshAlloc(0xfa0f);
  ptr.seg = in_DX;
  ptr.ofs = (uint16_t)pvStack_6;
  uStack_4 = in_DX;
  ovr_alignToSeg(ptr);
  uVar4 = in_DX;
  ovr_driver_fillRect(0,0,0x13f,199,0x0,in_DX,0);
  gfx.seg = gamfont1Cut1Seg;
  gfx.ofs = (uint16_t)gamfont1Cut1Ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)((ulong)in_DX << 0x10)),0);
  init_special_graphics((char *)CONCAT22(gamfont1Cut1Seg,gamfont1Cut1Ofs));
  hndl.seg = unaff_DI;
  hndl.ofs = in_DX;
  Font03.ofs = (uint16_t)ovr_stshProcessFontSub((far_t far *)0x0,hndl);
  Font03.seg = uVar4;
  ovr_driver_fillRect(0,0,0x13f,199,0x0,in_DX,0);
  gfx_00.seg = davfontCut1Seg;
  gfx_00.ofs = (uint16_t)davfontCut1Ofs;
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)((ulong)in_DX << 0x10)),0);
  init_special_graphics((char *)CONCAT22(davfontCut1Seg,davfontCut1Ofs));
  hndl_00.seg = unaff_DI;
  hndl_00.ofs = in_DX;
  Font02.ofs = (uint16_t)ovr_stshProcessFontSub((far_t far *)0x0,hndl_00);
  Font02.seg = uVar4;
  ovr_driver_fillRect(0,0,0x13f,199,0x0,in_DX,0);
  gfx_01.seg = davfont2Cut1Seg;
  gfx_01.ofs = (uint16_t)davfont2Cut1Ofs;
  ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)((ulong)in_DX << 0x10)),0);
  init_special_graphics((char *)CONCAT22(davfont2Cut1Seg,davfont2Cut1Ofs));
  hndl_01.seg = unaff_DI;
  hndl_01.ofs = in_DX;
  pfVar2 = ovr_stshProcessFontSub((far_t far *)0x0,hndl_01);
  FontMain.ofs = (uint16_t)pfVar2;
  FontMain.seg = uVar4;
  Font01.ofs = (uint16_t)pfVar2;
  Font01.seg = uVar4;
  for (i = 0; (int)i < 4; i = i + 1) {
    ovr_driver_fillRect(0,0,0x11,0x11,0x0,in_DX,0);
    gfx_02.seg = *(uint16_t *)((int)&MiceCursors[0].seg + i * 4);
    gfx_02.ofs = ((far_t far *)MiceCursors + i)->ofs;
    ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)((ulong)in_DX << 0x10)),0);
    init_special_graphics
              ((char *)CONCAT22(*(undefined2 *)((int)&MiceCursors[0].seg + i * 4),
                                (char *)((far_t far *)MiceCursors + i)->ofs));
    video_copyScreenTile(in_DX,0,0);
    pvVar3 = ovr_stshAlloc(0x121);
    *(undefined2 *)((int)&MicePtrs.seg + i * 4) =(uint16_t)( pfVar2);
    ((far_t far *)&MicePtrs + i)->ofs = (uint16_t)pvVar3;
    memcpy((char *)CONCAT22(*(undefined2 *)((int)&MicePtrs.seg + i * 4),
                            (char *)((far_t far *)&MicePtrs + i)->ofs),(char *)MiceSaveBuf,0x121);
  }
  handle_01.seg = uStack_4;
  handle_01.ofs = (uint16_t)pvStack_6;
  ovr_stshFree(handle_01);
  return;
}
