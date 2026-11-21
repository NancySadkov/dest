/*
 * ovc40_palette.c - recovered from STRONG.EXE
 * memory block: OVC40_palette.c
 * range: 69c8:0000 - 69c8:0c6f
 * functions: 8
 */
#include "recovered.h"


/* 69c8:0000 */

/* [R4] calls ovr_blitLabel */

void __cdecl16far ovc40_usesBlitLabel(far_t text1,far_t text2,byte row,byte term)

{
  int iVar1;
  
  TextBlitFlag = 1;
  TextBlitDstSeg = 0xa000;
  if (GameRunning) {
    ovr_ovc42_usesBlitLabel((char *)text1.ofs,(byte)text1.seg,CONCAT11(0x24,row));
  }
  else {
    TextBlitX = 0;
    TextBlitY = (uint)row * 0xb + 0x98;
    iVar1 = ovr_font_textWidth((char *)text1.ofs,(char *)CONCAT22(Font03.ofs,text1.seg),Font03.seg);
    if ((text2.ofs == 0 && text2.seg == 0) || (iVar1 < 0x140)) {
      TextBlitX = TextBlitX + (0x140U - iVar1 >> 1);
    }
    else {
      text1 = text2;
      iVar1 = ovr_font_textWidth((char *)text2.ofs,(char *)CONCAT22(Font03.ofs,text2.seg),Font03.seg
                                );
      if (iVar1 < 0x140) {
        TextBlitX = TextBlitX + (0x140U - iVar1 >> 1);
      }
    }
    BlitLetterType = 1;
    ovr_blitLabel((char *)text1.ofs,(uint8_t *)CONCAT22(Font03.ofs,text1.seg),Font03.seg,0x3f,
                  CONCAT11(0x24,term));
    BlitLetterType = 0;
  }
  return;
}



/* 69c8:011e */

/* [R4] calls ovr_vgaSetPalette8bit */

void __cdecl16far ovc40_usesVgaSetPalette8bit(far_t palette,...)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_SS;
  uint8_t pal;
  int iStack_6;
  int iStack_4;
  
  iStack_4 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
  iStack_6 = *(int *)BDA_DailyTimeCounter;
  iVar2 = 10;
  do {
    if (iVar2 < 0) {
      return;
    }
    for (iVar1 = 0; iVar1 < 0x300; iVar1 = iVar1 + 1) {
      (&pal)[iVar1] =
           (uint8_t)(((long)(int)(uint)*(byte *)(palette.ofs + iVar1) * (long)iVar2 & 0xffffU) / 10)
      ;
    }
    ovr_vgaSetPalette8bit(&pal);
    do {
      if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != iStack_4) break;
    } while (*(int *)BDA_DailyTimeCounter == iStack_6);
    iStack_4 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
    iStack_6 = *(int *)BDA_DailyTimeCounter;
    iVar2 = iVar2 + -1;
  } while( true );
}



/* 69c8:01ac */

void __cdecl16far setSeasonPalette(far_t palette,...)

{
  uint uVar1;
  uint uVar2;
  undefined2 unaff_SS;
  uint8_t pal;
  int iStack_6;
  int iStack_4;
  
  iStack_4 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
  iStack_6 = *(int *)BDA_DailyTimeCounter;
  uVar2 = 0;
  do {
    if (10 < uVar2) {
      return;
    }
    for (uVar1 = 0; uVar1 < 0x300; uVar1 = uVar1 + 1) {
      (&pal)[uVar1] =
           (uint8_t)(((long)(int)(uint)*(byte *)(palette.ofs + uVar1) * (long)(int)uVar2 & 0xffffU)
                    / 10);
    }
    ovr_vgaSetPalette8bit(&pal);
    do {
      if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != iStack_4) break;
    } while (*(int *)BDA_DailyTimeCounter == iStack_6);
    iStack_4 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
    iStack_6 = *(int *)BDA_DailyTimeCounter;
    uVar2 = uVar2 + 1;
  } while( true );
}



/* 69c8:023a */

/* [R4] calls ovr_stshLoadGfx */

stg_tmp_t * __cdecl16far ovc40_usesStshLoadGfx(byte backdropIndex)

{
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  undefined2 in_DX;
  undefined2 uVar1;
  undefined2 unaff_SS;
  uint8_t cmapBackupB;
  uint8_t cmapBackupA;
  stg_tmp_t *psStack_6;
  undefined2 uStack_4;
  
  handle.seg = marbleCut1Seg;
  handle.ofs = marbleCut1Ofs;
  psStack_6 = ovr_stshLoadGfx(handle);
  _fmemmove((char *)CONCAT22(unaff_SS,&cmapBackupB),(char *)CONCAT22(in_DX,psStack_6->cmap + 0x231),
            0xcf);
  handle_00.seg = Lbm_nwpanel1.seg;
  handle_00.ofs = Lbm_nwpanel1.ofs;
  psStack_6 = ovr_stshLoadGfx(handle_00);
  _fmemmove((char *)CONCAT22(unaff_SS,&cmapBackupA),(char *)CONCAT22(in_DX,psStack_6->cmap + 0x2ac),
            0xc);
  if (backdropIndex == 4) {
    handle_01.seg = youlose1Cut1Seg;
    handle_01.ofs = youlose1Cut1Ofs;
    psStack_6 = ovr_stshLoadGfx(handle_01);
    uStack_4 = in_DX;
  }
  else {
    uVar1 = 0x2410;
    handle_02.seg = ((undefined2 *)&back03Cut1Seg)[(uint)backdropIndex * 2];
    handle_02.ofs = ((undefined2 *)&back03Cut1Ofs)[(uint)backdropIndex * 2];
    psStack_6 = ovr_stshLoadGfx(handle_02);
    uStack_4 = uVar1;
  }
  _fmemmove((char *)CONCAT22(uStack_4,psStack_6->cmap + 0x231),
            (char *)CONCAT22(unaff_SS,&cmapBackupB),0xcf);
  return psStack_6;
}



/* 69c8:0317 */

/* [R4] calls ovr_calcSeasonPalette */

void __cdecl16far ovc40_usesCalcSeasonPalette(char useVgaPalette,...)

{
  uint16_t in_DX;
  uint16_t unaff_SS;
  far_t handle;
  far_t palette;
  far_t palette_00;
  uint8_t pal;
  stg_tmp_t *psStack_6;
  
  handle.seg = Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  psStack_6 = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette(psStack_6->cmap,in_DX,&pal,unaff_SS);
  if (useVgaPalette == '\0') {
    palette_00.seg = unaff_SS;
    palette_00.ofs = (uint16_t)&pal;
    ovc40_usesVgaSetPalette8bit(palette_00);
  }
  else {
    palette.seg = unaff_SS;
    palette.ofs = (uint16_t)&pal;
    setSeasonPalette(palette);
  }
  return;
}



/* 69c8:0373 */

/* [R4] calls ovr_blitGfx10 */

void __cdecl16far ovc40_usesBlitGfx10(byte backdropIndex,int scrollOffset,brect_t *rect)

{
  brect_t *dst;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  bool type;
  
  dst = (brect_t *)rect;
  gfx_03.seg = ((undefined2 *)&back03Cut2Seg)[(uint)backdropIndex * 2];
  gfx_03.ofs = ((undefined2 *)&back03Cut2Ofs)[(uint)backdropIndex * 2];
  ovr_blitLoadRleGfx(gfx_03,far_from_u32((uint32_t)((ulong)dst->seg << 0x10)));
  gfx.seg = ((undefined2 *)&midgrnd5Cut1Seg)[(uint)backdropIndex * 2];
  gfx.ofs = ((undefined2 *)&midgrnd5Cut1Ofs)[(uint)backdropIndex * 2];
  type = SUB41((ulong)rect >> 0x10,0);
  ovr_blitGfx10(gfx,-(scrollOffset >> 1),0,dst,type);
  gfx_00.seg = ((undefined2 *)&midgrnd5Cut2Seg)[(uint)backdropIndex * 2];
  gfx_00.ofs = ((undefined2 *)&midgrnd5Cut2Ofs)[(uint)backdropIndex * 2];
  ovr_blitGfx10(gfx_00,0xdc - (scrollOffset >> 1),0,dst,type);
  gfx_01.seg = ((undefined2 *)&strong4Cut1Seg)[(uint)backdropIndex * 2];
  gfx_01.ofs = ((undefined2 *)&strong4Cut1Ofs)[(uint)backdropIndex * 2];
  ovr_blitGfx10(gfx_01,-scrollOffset,0,dst,type);
  gfx_02.seg = ((undefined2 *)&strong4Cut2Seg)[(uint)backdropIndex * 2];
  gfx_02.ofs = ((undefined2 *)&strong4Cut2Ofs)[(uint)backdropIndex * 2];
  ovr_blitGfx10(gfx_02,0x118 - scrollOffset,0,dst,type);
  ovr_blitRect(dst);
  return;
}



/* 69c8:047f */

/* Drains pending keyboard and mouse input, then clears the mouse-button flags. */

void __cdecl16far ovc40_flushInput(void)

{
  uint16_t uVar1;
  bool bStack_3;
  
  do {
    uVar1 = ovr_biosKeyAvail();
    bStack_3 = (char)uVar1 != '\0';
    if (bStack_3) {
      ovr_gameProcessKey();
    }
    uVar1 = ovr_miceButtonsStates();
    bStack_3 = uVar1 != 0 || bStack_3;
  } while (bStack_3);
  rightButtonLatch = 0;
  middleButtonLatch = 0;
  return;
}



/* 69c8:04c6 */

/* [R4] calls ovr_alignToSeg */

char __cdecl16far
ovc40_usesAlignToSeg
          (char backdropIndex,char *capTextOfs,uint16_t capTextSeg,char *textOfs,uint16_t textSeg,
          byte formatIndex,...)

{
  char cVar1;
  bool bVar2;
  far_t text1_00;
  far_t text1_01;
  far_t text1_02;
  far_t text1_03;
  far_t text1_04;
  far_t text1_05;
  far_t text1_06;
  far_t text1_07;
  far_t text1_08;
  far_t text1_09;
  far_t text1_10;
  far_t text1_11;
  far_t text1_12;
  far_t text1_13;
  far_t text1_14;
  far_t gfx;
  far_t gfx_00;
  far_t text2_00;
  far_t text2_01;
  far_t text2_02;
  far_t text2_03;
  far_t text2_04;
  far_t text2_05;
  far_t text2_06;
  far_t text2_07;
  far_t text2_08;
  far_t text2_09;
  far_t text2_10;
  far_t gfx_01;
  far_t text2_11;
  far_t text2_12;
  far_t text2_13;
  far_t gfx_02;
  far_t dst_00;
  far_t dst_01;
  far_t dst_02;
  far_t ptr;
  far_t palette;
  far_t handle;
  far_t palette_00;
  byte bVar3;
  char *pcVar4;
  uint16_t uVar5;
  uint uVar6;
  undefined1 extraout_AH;
  uint16_t in_DX;
  uint8_t *puVar7;
  uint8_t *puVar8;
  int iVar9;
  int scrollOffset;
  char *unaff_SS;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  byte bVar13;
  undefined1 uVar14;
  uint8_t text1;
  uint8_t text2;
  uint8_t dst;
  undefined2 uStack_68;
  undefined2 uStack_66;
  uint8_t format1;
  undefined2 auStack_62 [3];
  uint8_t rankMsg;
  uint16_t uStack_5a;
  undefined2 uStack_58;
  char *pcStack_56;
  uint8_t format2;
  uint16_t auStack_52 [4];
  uint16_t uStack_4a;
  uint16_t uStack_48;
  uint16_t uStack_46;
  uint16_t uStack_44;
  uint16_t uStack_42;
  uint16_t uStack_40;
  uint16_t uStack_3e;
  uint16_t uStack_3c;
  uint16_t uStack_3a;
  uint16_t uStack_38;
  uint16_t uStack_36;
  uint16_t uStack_34;
  uint16_t uStack_32;
  uint16_t uStack_30;
  uint16_t uStack_2e;
  undefined2 uStack_2c;
  char *pcStack_2a;
  uint16_t uStack_28;
  uint16_t uStack_26;
  uint16_t uStack_24;
  uint16_t uStack_22;
  char cStack_1f;
  char cStack_1e;
  char cStack_1d;
  stg_tmp_t *psStack_1c;
  uint16_t uStack_1a;
  void *pvStack_18;
  uint16_t uStack_16;
  uint8_t rect;
  int iStack_a;
  int iStack_8;
  uint8_t clickY;
  uint8_t clickX;
  
  uVar12 = SUB21(unaff_SS,0);
  uVar14 = (undefined1)((uint)unaff_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = uVar12;
  dst_00.ofs = (uint16_t)&rankMsg;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = uVar14;
  F_SCOPY(far_from_u32((uint32_t)(0x24106b3a)),dst_00);
  (*(uint8_t *)((uint8_t *)&(dst_01.seg))) = uVar12;
  dst_01.ofs = (uint16_t)&dst;
  (*(uint8_t *)((uint8_t *)&(dst_01.seg) + 1)) = uVar14;
  F_SCOPY(far_from_u32((uint32_t)(0x24106b76)),dst_01);
  (*(uint8_t *)((uint8_t *)&(dst_02.seg))) = uVar12;
  dst_02.ofs = (uint16_t)&rect;
  (*(uint8_t *)((uint8_t *)&(dst_02.seg) + 1)) = uVar14;
  F_SCOPY(far_from_u32((uint32_t)(0x24106b86)),dst_02);
  cStack_1d = '\0';
  ovr_stop_audio();
  ovc40_flushInput();
  ovr_draw_freeRingBuffers();
  MiceUnkState = 0;
  pvStack_18 = ovr_stshAlloc(0xfa0f);
  (*(uint8_t *)((uint8_t *)&(ptr.seg))) = (char)in_DX;
  ptr.ofs = (uint16_t)pvStack_18;
  (*(uint8_t *)((uint8_t *)&(ptr.seg) + 1)) = (char)(in_DX >> 8);
  uStack_16 = in_DX;
  ovr_alignToSeg(ptr);
  if (GameRunning == false) {
    ovc40_usesCalcSeasonPalette('\0');
  }
  MiceNeedsUpdate = 1;
  ovr_driver_fillRect(0,0,0x13f,199,0xec,0xa000,0x3f,0xec,0);
  gfx.seg = marbleCut2Seg;
  gfx.ofs = marbleCut2Ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000b400)),0);
  if (backdropIndex == '\x02') {
    cStack_1f = '\x02';
  }
  else {
    cStack_1f = -2;
  }
  if (backdropIndex == '\x04') {
    gfx_00.seg = youlose1Cut2Seg;
    gfx_00.ofs = youlose1Cut2Ofs;
    ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa0000000)),0);
  }
  else if (cStack_1f < '\0') {
    ovc40_usesBlitGfx10(backdropIndex,0xef,(brect_t *)CONCAT13(uVar14,CONCAT12(uVar12,&rect)));
  }
  else {
    ovc40_usesBlitGfx10(backdropIndex,0,(brect_t *)CONCAT13(uVar14,CONCAT12(uVar12,&rect)));
  }
  psStack_1c = ovc40_usesStshLoadGfx(backdropIndex);
  if (formatIndex == 4) {
    CurMusicType = 0x44;
  }
  else if ((formatIndex == 0) || (formatIndex == 6)) {
    CurMusicType = 0x21;
  }
  else {
    CurMusicType = 0x2d;
  }
  uStack_1a = in_DX;
  ovr_play_sfx(CONCAT11(0x24,CurMusicType),0,0);
  (*(uint8_t *)((uint8_t *)&(palette.seg))) = (char)uStack_1a;
  palette.ofs = (uint16_t)psStack_1c;
  (*(uint8_t *)((uint8_t *)&(palette.seg) + 1)) = (char)(uStack_1a >> 8);
  setSeasonPalette(palette);
  if (formatIndex == 2) {
    text1_00.seg = uStack_4a;
    text1_00.ofs = auStack_52[3];
    text2_00.seg = uStack_4a;
    text2_00.ofs = auStack_52[3];
    ovc40_usesBlitLabel(text1_00,text2_00,0,0xf2);
    text1_01.seg = uStack_46;
    text1_01.ofs = uStack_48;
    text2_01.seg = uStack_46;
    text2_01.ofs = uStack_48;
    ovc40_usesBlitLabel(text1_01,text2_01,1,0xf2);
    text1_02.seg = uStack_22;
    text1_02.ofs = uStack_24;
    text2_02.seg = uStack_46;
    text2_02.ofs = uStack_48;
    ovc40_usesBlitLabel(text1_02,text2_02,2,0xf2);
  }
  else if (formatIndex == 3) {
    text1_03.seg = uStack_42;
    text1_03.ofs = uStack_44;
    text2_03.seg = uStack_42;
    text2_03.ofs = uStack_44;
    ovc40_usesBlitLabel(text1_03,text2_03,0,0xf2);
    text1_04.seg = uStack_3e;
    text1_04.ofs = uStack_40;
    text2_04.seg = uStack_3e;
    text2_04.ofs = uStack_40;
    ovc40_usesBlitLabel(text1_04,text2_04,1,0xf2);
    text1_05.seg = uStack_3a;
    text1_05.ofs = uStack_3c;
    text2_05.seg = uStack_3a;
    text2_05.ofs = uStack_3c;
    ovc40_usesBlitLabel(text1_05,text2_05,2,0xf2);
  }
  else if ((formatIndex == 4) || (formatIndex == 6)) {
    ovr_ovc15_capitalize((char *)&text1);
    bVar13 = 0xf2;
    bVar3 = 1;
    uVar5 = 0;
    uVar10 = 0;
    uVar11 = 0;
    pcVar4 = ovr_stsprintf((char *)&text2,(char *)CONCAT22(uStack_2c,unaff_SS),
                           (char *)CONCAT22(&text1,pcStack_2a));
    text1_06.seg = in_DX;
    text1_06.ofs = (uint16_t)pcVar4;
    (*(uint8_t *)((uint8_t *)&(text2_06.ofs) + 1)) = uVar11;
    (*(uint8_t *)((uint8_t *)&(text2_06.ofs))) = uVar10;
    text2_06.seg = uVar5;
    ovc40_usesBlitLabel(text1_06,text2_06,bVar3,bVar13);
  }
  else if (formatIndex == 5) {
    ovr_ovc15_capitalize((char *)&text1);
    bVar13 = 0xf2;
    bVar3 = 0;
    uVar5 = 0;
    uVar10 = 0;
    uVar11 = 0;
    pcVar4 = ovr_stsprintf((char *)&text2,(char *)CONCAT22(uStack_2c,unaff_SS),
                           (char *)CONCAT22(&text1,pcStack_2a));
    text1_07.seg = in_DX;
    text1_07.ofs = (uint16_t)pcVar4;
    (*(uint8_t *)((uint8_t *)&(text2_07.ofs) + 1)) = uVar11;
    (*(uint8_t *)((uint8_t *)&(text2_07.ofs))) = uVar10;
    text2_07.seg = uVar5;
    ovc40_usesBlitLabel(text1_07,text2_07,bVar3,bVar13);
    text1_08.seg = uStack_26;
    text1_08.ofs = uStack_28;
    ovc40_usesBlitLabel(text1_08,far_from_u32((uint32_t)(0x0)),1,0xf2);
  }
  else {
    text1_09.seg = uStack_5a;
    text1_09.ofs = rankMsg;
    text2_08.seg = uStack_5a;
    text2_08.ofs = rankMsg;
    ovc40_usesBlitLabel(text1_09,text2_08,0,0xf2);
    bVar13 = 0xf2;
    bVar3 = 1;
    pcVar4 = ovr_stsprintf((char *)&text1,(char *)CONCAT22(uStack_68,unaff_SS),
                           (char *)CONCAT13((char)((uint)capTextOfs >> 8),
                                            CONCAT12((char)capTextOfs,uStack_66)),(char)capTextOfs,
                           capTextSeg);
    uVar10 = SUB21(pcVar4,0);
    uVar11 = (undefined1)((uint)pcVar4 >> 8);
    uVar5 = in_DX;
    pcVar4 = ovr_stsprintf((char *)&text2,(char *)CONCAT22(uStack_58,unaff_SS),
                           (char *)CONCAT22(capTextOfs,pcStack_56),capTextSeg);
    text1_10.seg = in_DX;
    text1_10.ofs = (uint16_t)pcVar4;
    (*(uint8_t *)((uint8_t *)&(text2_09.ofs) + 1)) = uVar11;
    (*(uint8_t *)((uint8_t *)&(text2_09.ofs))) = uVar10;
    text2_09.seg = uVar5;
    ovc40_usesBlitLabel(text1_10,text2_09,bVar3,bVar13);
    bVar13 = 0xf2;
    bVar3 = 2;
    puVar7 = &format1;
    pcVar4 = ovr_stsprintf((char *)&text1,
                           (char *)CONCAT22(*(undefined2 *)(puVar7 + (uint)formatIndex * 4),unaff_SS
                                           ),
                           (char *)CONCAT13((char)((uint)textOfs >> 8),
                                            CONCAT12((char)textOfs,auStack_62[(uint)formatIndex * 2]
                                                    )),(char)textOfs,textSeg);
    uVar10 = SUB21(pcVar4,0);
    uVar11 = (undefined1)((uint)pcVar4 >> 8);
    puVar8 = &format2;
    pcVar4 = ovr_stsprintf((char *)&text2,
                           (char *)CONCAT22(*(undefined2 *)(puVar8 + (uint)formatIndex * 4),unaff_SS
                                           ),
                           (char *)CONCAT22(textOfs,(char *)auStack_52[(uint)formatIndex * 2]),
                           textSeg);
    text1_11.seg = (uint16_t)puVar8;
    text1_11.ofs = (uint16_t)pcVar4;
    (*(uint8_t *)((uint8_t *)&(text2_10.ofs) + 1)) = uVar11;
    (*(uint8_t *)((uint8_t *)&(text2_10.ofs))) = uVar10;
    text2_10.seg = (uint16_t)puVar7;
    ovc40_usesBlitLabel(text1_11,text2_10,bVar3,bVar13);
  }
  ovc40_flushInput();
  ovr_ovr_miceButton0PressStates_entry();
  iStack_8 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
  iVar9 = *(int *)BDA_DailyTimeCounter;
  if (backdropIndex == '\x04') {
    iStack_a = iVar9;
    uVar5 = ovr_inputUpdate(0xb4);
    if (1 < (byte)uVar5) {
      cStack_1d = '\x02';
    }
  }
  else {
    if (cStack_1f < '\0') {
      scrollOffset = 0xee;
    }
    else {
      scrollOffset = 1;
    }
    cStack_1e = 'w';
    while (cVar1 = cStack_1e + -1, bVar2 = cStack_1e != '\0', cStack_1e = cVar1, iStack_a = iVar9,
          bVar2) {
      if ((scrollOffset == 100) && (formatIndex == 2)) {
        gfx_01.seg = marbleCut2Seg;
        gfx_01.ofs = marbleCut2Ofs;
        ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000b400)),0);
        text1_12.seg = uStack_36;
        text1_12.ofs = uStack_38;
        text2_11.seg = uStack_36;
        text2_11.ofs = uStack_38;
        ovc40_usesBlitLabel(text1_12,text2_11,0,0xf2);
        text1_13.seg = uStack_32;
        text1_13.ofs = uStack_34;
        text2_12.seg = uStack_32;
        text2_12.ofs = uStack_34;
        ovc40_usesBlitLabel(text1_13,text2_12,1,0xf2);
        text1_14.seg = uStack_2e;
        text1_14.ofs = uStack_30;
        text2_13.seg = uStack_2e;
        text2_13.ofs = uStack_30;
        ovc40_usesBlitLabel(text1_14,text2_13,2,0xf2);
      }
      ovc40_usesBlitGfx10(backdropIndex,scrollOffset,
                          (brect_t *)CONCAT13(uVar14,CONCAT12(uVar12,&rect)));
      uVar5 = ovr_biosKeyAvail();
      if ((char)uVar5 != '\0') {
        uVar5 = ovr_gameProcessKey();
        if (uVar5 == 0x11b) {
          cStack_1d = '\x02';
          break;
        }
        if (uVar5 == 0x1c0d) break;
      }
      uVar6 = ovr_init2_updateMouseButtons();
      if (uVar6 != 0) break;
      if (rightButtonLatch != '\0') {
        cStack_1d = '\x02';
        break;
      }
      do {
        ovr_audio_usesLDIV_at_();
        if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != iStack_8) break;
      } while (*(int *)BDA_DailyTimeCounter == iStack_a);
      iStack_8 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
      iVar9 = *(int *)BDA_DailyTimeCounter;
      scrollOffset = scrollOffset + cStack_1f;
    }
    if (cStack_1f < '\x01') {
      ovc40_usesBlitGfx10(backdropIndex,0,(brect_t *)CONCAT13(uVar14,CONCAT12(uVar12,&rect)));
    }
    else {
      ovc40_usesBlitGfx10(backdropIndex,0xef,(brect_t *)CONCAT13(uVar14,CONCAT12(uVar12,&rect)));
    }
    ovc40_flushInput();
    rightButtonLatch = '\0';
    if ((formatIndex == 2) || (formatIndex == 3)) {
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
      iVar9 = *(int *)BDA_DailyTimeCounter;
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = iVar9;
      if (cStack_1d == '\0') {
        uVar5 = ovr_inputUpdate(0x48);
        cStack_1d = (char)uVar5;
      }
    }
    else {
      gfx_02.seg = far_t_2000_d3e4.seg;
      gfx_02.ofs = far_t_2000_d3e4.ofs;
      ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)(0xa000e908)),8);
      MiceProcessed = 0;
      ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
      do {
        do {
          ovr_audio_usesLDIV_at_();
          bVar3 = ovr_init2_usesCFGMice
                            ((uint16_t *)&clickX,
                             (uint16_t *)
                             CONCAT13((char)((uint)&clickY >> 8),CONCAT12((char)&clickY,unaff_SS)));
          if ((((CONCAT11(extraout_AH,bVar3) != 0) && (0x87 < clickX)) && (0xb9 < clickY)) &&
             ((clickX < 0xd6 && (clickY < 0xc6)))) goto L_OVC40_69c8_04c6_0AF0;
          if (rightButtonLatch != '\0') {
            cStack_1d = '\x02';
            goto L_OVC40_69c8_04c6_0AF0;
          }
          uVar5 = ovr_biosKeyAvail();
        } while ((char)uVar5 == '\0');
        uVar5 = ovr_gameProcessKey();
        if (uVar5 == 0x11b) {
          cStack_1d = '\x02';
          break;
        }
      } while (uVar5 != 0x1c0d);
    }
  }
L_OVC40_69c8_04c6_0AF0:
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
  ovr_clearMiceProcessed();
  (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uStack_16;
  handle.ofs = (uint16_t)pvStack_18;
  (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)(uStack_16 >> 8);
  ovr_stshFree(handle);
  psStack_1c = ovc40_usesStshLoadGfx(backdropIndex);
  (*(uint8_t *)((uint8_t *)&(palette_00.seg))) = (char)iVar9;
  palette_00.ofs = (uint16_t)psStack_1c;
  (*(uint8_t *)((uint8_t *)&(palette_00.seg) + 1)) = (char)((uint)iVar9 >> 8);
  uStack_1a = iVar9;
  ovc40_usesVgaSetPalette8bit(palette_00);
  ovr_stop_audio();
  CurMusicType = 0xff;
  ovr_init_usesBlitGfxRect();
  if (GameRunning == false) {
    ovc40_usesCalcSeasonPalette('\x01');
  }
  ovr_ovc28_textHalflingCastle();
  ovr_ovc41_usesGMenuItem();
  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
  return cStack_1d;
}


