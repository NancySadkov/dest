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
  byte unaff_SI;
  
  TextBlitFlag = 1;
  TextBlitDstSeg = 0xa000;
  if (GameRunning) {
    ovr_ovc42_usesBlitLabel((char *)CONCAT22(CONCAT11(0x24,row),text1.seg),unaff_SI,text1.ofs);
  }
  else {
    TextBlitX = 0;
    TextBlitY = (uint)row * 0xb + 0x98;
    iVar1 = ovr_font_textWidth();
    if ((text2.ofs == 0 && text2.seg == 0) || (iVar1 < 0x140)) {
      TextBlitX = TextBlitX + (0x140U - iVar1 >> 1);
    }
    else {
      text1 = text2;
      iVar1 = ovr_font_textWidth();
      if (iVar1 < 0x140) {
        TextBlitX = TextBlitX + (0x140U - iVar1 >> 1);
      }
    }
    BlitLetterType = 1;
    ovr_blitLabel((char *)CONCAT22(Font03.ofs,text1.seg),(uint8_t *)CONCAT22(0x13f,Font03.seg),
                  CONCAT11(0x24,term),unaff_SI,text1.ofs);
    BlitLetterType = 0;
  }
  return;
}



/* 69c8:011e */

/* [R4] calls ovr_vgaSetPalette8bit */

void __cdecl16far ovc40_usesVgaSetPalette8bit(far_t palette,...)

{
  int iVar1;
  uint unaff_DI;
  int iVar2;
  uint8_t *unaff_SS;
  int in_stack_00000004;
  uint8_t *pal_00;
  uint8_t pal;
  int iStack_6;
  int iStack_4;
  
  pal_00 = (uint8_t *)((ulong)unaff_DI << 0x10);
  iStack_4 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
  iStack_6 = *(int *)BDA_DailyTimeCounter;
  iVar2 = 10;
  do {
    if (iVar2 < 0) {
      return;
    }
    for (iVar1 = 0; iVar1 < 0x300; iVar1 = iVar1 + 1) {
      (&pal)[iVar1] =
           (uint8_t)(((long)(int)(uint)*(byte *)(in_stack_00000004 + iVar1) * (long)iVar2 & 0xffffU)
                    / 10);
    }
    pal_00 = (uint8_t *)CONCAT22((int)((ulong)pal_00 >> 0x10),unaff_SS);
    ovr_vgaSetPalette8bit(pal_00,&pal);
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
  uint unaff_DI;
  uint uVar2;
  uint8_t *unaff_SS;
  int in_stack_00000004;
  uint8_t *pal_00;
  uint8_t pal;
  int iStack_6;
  int iStack_4;
  
  pal_00 = (uint8_t *)((ulong)unaff_DI << 0x10);
  iStack_4 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
  iStack_6 = *(int *)BDA_DailyTimeCounter;
  uVar2 = 0;
  do {
    if (10 < uVar2) {
      return;
    }
    for (uVar1 = 0; uVar1 < 0x300; uVar1 = uVar1 + 1) {
      (&pal)[uVar1] =
           (uint8_t)(((long)(int)(uint)*(byte *)(in_stack_00000004 + uVar1) * (long)(int)uVar2 &
                     0xffffU) / 10);
    }
    pal_00 = (uint8_t *)CONCAT22((int)((ulong)pal_00 >> 0x10),unaff_SS);
    ovr_vgaSetPalette8bit(pal_00,&pal);
    do {
      if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != iStack_4) break;
    } while (*(int *)BDA_DailyTimeCounter == iStack_6);
    iStack_4 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
    iStack_6 = *(int *)BDA_DailyTimeCounter;
    uVar2 = uVar2 + 1;
  } while( true );
}



/* 69c8:023a */

/* WARNING: Variable defined which should be unmapped: cmapBackupB */
/* [R4] calls ovr_stshLoadGfx */

stg_tmp_t * __cdecl16far ovc40_usesStshLoadGfx(byte backdropIndex)

{
  undefined2 in_DX;
  undefined2 uVar1;
  undefined2 unaff_SS;
  uint8_t cmapBackupB;
  undefined4 uStack_d8;
  uint8_t cmapBackupA;
  stg_tmp_t *psStack_6;
  undefined2 uStack_4;
  
  psStack_6 = ovr_stshLoadGfx();
  _fmemmove((char *)CONCAT22(unaff_SS,&cmapBackupB),(char *)CONCAT22(in_DX,psStack_6->cmap + 0x231),
            0xcf);
  psStack_6 = ovr_stshLoadGfx();
  _fmemmove((char *)CONCAT22(unaff_SS,&cmapBackupA),(char *)CONCAT22(in_DX,psStack_6->cmap + 0x2ac),
            0xc);
  if (backdropIndex == 4) {
    uStack_d8 = CONCAT22(_cmapBackupB,youlose1Cut1Seg);
    psStack_6 = ovr_stshLoadGfx();
    uStack_4 = in_DX;
  }
  else {
    uVar1 = 0x2410;
    uStack_d8 = CONCAT22(_cmapBackupB,((undefined2 *)&back03Cut1Seg)[(uint)backdropIndex * 2]);
    psStack_6 = ovr_stshLoadGfx();
    uStack_4 = uVar1;
  }
  uStack_d8 = CONCAT22(_cmapBackupB,0xcf);
  _fmemmove((char *)CONCAT22(uStack_4,psStack_6->cmap + 0x231),
            (char *)CONCAT22(unaff_SS,&cmapBackupB),0xcf);
  return psStack_6;
}



/* 69c8:0317 */

/* WARNING: Variable defined which should be unmapped: pal */
/* [R4] calls ovr_calcSeasonPalette */

void __cdecl16far ovc40_usesCalcSeasonPalette(char useVgaPalette,...)

{
  stg_tmp_t *psVar1;
  uint8_t *in_DX;
  uint16_t unaff_SS;
  char in_stack_00000004;
  uint8_t pal;
  undefined4 uStack_308;
  uint16_t in_stack_0000fcfc;
  
  psVar1 = ovr_stshLoadGfx();
  ovr_calcSeasonPalette((uint8_t *)CONCAT22(&pal,in_DX),unaff_SS,_pal,in_stack_0000fcfc,psVar1);
  if (in_stack_00000004 == '\0') {
    uStack_308 = CONCAT22(_pal,unaff_SS);
    ovc40_usesVgaSetPalette8bit();
  }
  else {
    uStack_308 = CONCAT22(_pal,unaff_SS);
    setSeasonPalette();
  }
  return;
}



/* 69c8:0373 */

/* [R4] calls ovr_blitGfx10 */

void __cdecl16far ovc40_usesBlitGfx10(byte backdropIndex,int scrollOffset,brect_t *rect)

{
  far_t gfx;
  far_t dst;
  brect_t *y;
  undefined2 unaff_SI;
  uint uVar1;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  undefined1 type;
  undefined1 uVar2;
  
  type = (undefined1)unaff_SI;
  uVar2 = (undefined1)((uint)unaff_SI >> 8);
  uVar1 = (uint)((ulong)rect >> 0x10);
  y = (brect_t *)rect;
  gfx.seg = 0;
  gfx.ofs = ((undefined2 *)&back03Cut2Seg)[(uint)backdropIndex * 2];
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = type;
  dst.ofs = y->seg;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar2;
  ovr_blitLoadRleGfx(gfx,dst,((undefined2 *)&back03Cut2Ofs)[(uint)backdropIndex * 2]);
  gfx_00.seg = -(scrollOffset >> 1);
  gfx_00.ofs = ((undefined2 *)&midgrnd5Cut1Seg)[(uint)backdropIndex * 2];
  ovr_blitGfx10(gfx_00,0,(uint16_t)y,(brect_t *)(ulong)uVar1,(bool)type,
                ((undefined2 *)&midgrnd5Cut1Ofs)[(uint)backdropIndex * 2]);
  gfx_01.seg = 0xdc - (scrollOffset >> 1);
  gfx_01.ofs = ((undefined2 *)&midgrnd5Cut2Seg)[(uint)backdropIndex * 2];
  ovr_blitGfx10(gfx_01,0,(uint16_t)y,(brect_t *)(ulong)uVar1,(bool)type,
                ((undefined2 *)&midgrnd5Cut2Ofs)[(uint)backdropIndex * 2]);
  gfx_02.seg = -scrollOffset;
  gfx_02.ofs = ((undefined2 *)&strong4Cut1Seg)[(uint)backdropIndex * 2];
  ovr_blitGfx10(gfx_02,0,(uint16_t)y,(brect_t *)(ulong)uVar1,(bool)type,
                ((undefined2 *)&strong4Cut1Ofs)[(uint)backdropIndex * 2]);
  gfx_03.seg = 0x118 - scrollOffset;
  gfx_03.ofs = ((undefined2 *)&strong4Cut2Seg)[(uint)backdropIndex * 2];
  ovr_blitGfx10(gfx_03,0,(uint16_t)y,(brect_t *)(ulong)uVar1,(bool)type,
                ((undefined2 *)&strong4Cut2Ofs)[(uint)backdropIndex * 2]);
  ovr_blitRect((brect_t *)CONCAT13(uVar2,CONCAT12(type,uVar1)),y);
  return;
}



/* 69c8:047f */

/* Drains pending keyboard and mouse input, then clears the mouse-button flags. */

void __cdecl16far ovc40_flushInput(void...)

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
  far_t text2_11;
  far_t text2_12;
  far_t text2_13;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t dst_00;
  far_t dst_01;
  far_t dst_02;
  far_t ptr;
  far_t dst_03;
  far_t dst_04;
  far_t palette;
  far_t dst_05;
  far_t dst_06;
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
  undefined2 unaff_DI;
  int scrollOffset;
  char *unaff_SS;
  byte in_stack_00000004;
  undefined1 uStack0007;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  byte bVar13;
  undefined1 uVar14;
  char useVgaPalette;
  undefined1 uVar15;
  uint8_t text1;
  uint8_t text2;
  uint8_t dst;
  uint8_t format1;
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
  
  useVgaPalette = (char)unaff_DI;
  uVar15 = (undefined1)((uint)unaff_DI >> 8);
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
  pvStack_18 = ovr_stshAlloc((ulong)CONCAT11(uVar15,useVgaPalette) << 0x10,0xf);
  (*(uint8_t *)((uint8_t *)&(ptr.seg))) = useVgaPalette;
  ptr.ofs = in_DX;
  (*(uint8_t *)((uint8_t *)&(ptr.seg) + 1)) = uVar15;
  uStack_16 = in_DX;
  ovr_alignToSeg(ptr,(char)pvStack_18);
  if (GameRunning == false) {
    ovc40_usesCalcSeasonPalette(useVgaPalette,0);
  }
  MiceNeedsUpdate = 1;
  ovr_driver_fillRect(0,0x13f,199,0xec,0x0,0,0x3f,0xec);
  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = 0;
  gfx.ofs = marbleCut2Seg;
  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = 0xb4;
  (*(uint8_t *)((uint8_t *)&(dst_03.seg))) = useVgaPalette;
  dst_03.ofs = 0xa000;
  (*(uint8_t *)((uint8_t *)&(dst_03.seg) + 1)) = uVar15;
  ovr_blitLoadRleGfx(gfx,dst_03,(char)marbleCut2Ofs,0);
  if (in_stack_00000004 == 2) {
    cStack_1f = '\x02';
  }
  else {
    cStack_1f = -2;
  }
  if (in_stack_00000004 == 4) {
    gfx_00.seg = 0;
    gfx_00.ofs = youlose1Cut2Seg;
    (*(uint8_t *)((uint8_t *)&(dst_04.seg))) = useVgaPalette;
    dst_04.ofs = 0xa000;
    (*(uint8_t *)((uint8_t *)&(dst_04.seg) + 1)) = uVar15;
    ovr_blitLoadRleGfx(gfx_00,dst_04,(char)youlose1Cut2Ofs,0);
  }
  else if (cStack_1f < '\0') {
    ovc40_usesBlitGfx10(in_stack_00000004,0xef,(brect_t *)CONCAT13(uVar14,CONCAT12(uVar12,&rect)));
  }
  else {
    ovc40_usesBlitGfx10(in_stack_00000004,0,(brect_t *)CONCAT13(uVar14,CONCAT12(uVar12,&rect)));
  }
  psStack_1c = ovc40_usesStshLoadGfx(in_stack_00000004);
  if ((char)textOfs == '\x04') {
    CurMusicType = 0x44;
  }
  else if (((char)textOfs == '\0') || ((char)textOfs == '\x06')) {
    CurMusicType = 0x21;
  }
  else {
    CurMusicType = 0x2d;
  }
  uStack_1a = in_DX;
  ovr_play_sfx(0,CurMusicType);
  (*(uint8_t *)((uint8_t *)&(palette.seg))) = useVgaPalette;
  palette.ofs = uStack_1a;
  (*(uint8_t *)((uint8_t *)&(palette.seg) + 1)) = uVar15;
  setSeasonPalette(palette,(char)psStack_1c);
  if ((char)textOfs == '\x02') {
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
  else if ((char)textOfs == '\x03') {
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
  else if (((char)textOfs == '\x04') || ((char)textOfs == '\x06')) {
    ovr_ovc15_capitalize
              ((char *)CONCAT13(uStack0007,CONCAT12(backdropIndex,unaff_SS)),(char)&text1,
               (char)capTextOfs);
    bVar13 = 0xf2;
    bVar3 = 1;
    uVar5 = 0;
    uVar10 = 0;
    uVar11 = 0;
    pcVar4 = ovr_stsprintf((char *)CONCAT22(uStack_2c,unaff_SS),(char *)CONCAT22(&text1,pcStack_2a),
                           unaff_SS,&text2);
    text1_06.seg = in_DX;
    text1_06.ofs = (uint16_t)pcVar4;
    (*(uint8_t *)((uint8_t *)&(text2_06.ofs) + 1)) = uVar11;
    (*(uint8_t *)((uint8_t *)&(text2_06.ofs))) = uVar10;
    text2_06.seg = uVar5;
    ovc40_usesBlitLabel(text1_06,text2_06,bVar3,bVar13);
  }
  else if ((char)textOfs == '\x05') {
    ovr_ovc15_capitalize
              ((char *)CONCAT13(uStack0007,CONCAT12(backdropIndex,unaff_SS)),(char)&text1,
               (char)capTextOfs);
    bVar13 = 0xf2;
    bVar3 = 0;
    uVar5 = 0;
    uVar10 = 0;
    uVar11 = 0;
    pcVar4 = ovr_stsprintf((char *)CONCAT22(uStack_2c,unaff_SS),(char *)CONCAT22(&text1,pcStack_2a),
                           unaff_SS,&text2);
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
    text1_09.ofs = _rankMsg;
    text2_08.seg = uStack_5a;
    text2_08.ofs = _rankMsg;
    ovc40_usesBlitLabel(text1_09,text2_08,0,0xf2);
    bVar13 = 0xf2;
    bVar3 = 1;
    pcVar4 = ovr_stsprintf();
    uVar10 = SUB21(pcVar4,0);
    uVar11 = (undefined1)((uint)pcVar4 >> 8);
    uVar5 = in_DX;
    pcVar4 = ovr_stsprintf((char *)CONCAT22(uStack_58,unaff_SS),
                           (char *)CONCAT22(_backdropIndex,pcStack_56),(char *)capTextOfs,&text2);
    text1_10.seg = in_DX;
    text1_10.ofs = (uint16_t)pcVar4;
    (*(uint8_t *)((uint8_t *)&(text2_09.ofs) + 1)) = uVar11;
    (*(uint8_t *)((uint8_t *)&(text2_09.ofs))) = uVar10;
    text2_09.seg = uVar5;
    ovc40_usesBlitLabel(text1_10,text2_09,bVar3,bVar13);
    bVar13 = 0xf2;
    bVar3 = 2;
    puVar7 = &format1;
    pcVar4 = ovr_stsprintf();
    uVar10 = SUB21(pcVar4,0);
    uVar11 = (undefined1)((uint)pcVar4 >> 8);
    puVar8 = &format2;
    pcVar4 = ovr_stsprintf((char *)CONCAT22(*(undefined2 *)(puVar8 + ((uint)textOfs & 0xff) * 4),
                                            unaff_SS),
                           (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(capTextOfs) + 2)),
                                            (char *)auStack_52[((uint)textOfs & 0xff) * 2]),
                           (char *)capTextSeg,&text2);
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
  if (in_stack_00000004 == 4) {
    iStack_a = iVar9;
    uVar5 = ovr_inputUpdate((ulong)CONCAT11(uVar15,useVgaPalette) << 0x10,0xb4);
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
      if ((scrollOffset == 100) && ((char)textOfs == '\x02')) {
        (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = 0;
        gfx_01.ofs = marbleCut2Seg;
        (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = 0xb4;
        (*(uint8_t *)((uint8_t *)&(dst_05.seg))) = useVgaPalette;
        dst_05.ofs = 0xa000;
        (*(uint8_t *)((uint8_t *)&(dst_05.seg) + 1)) = uVar15;
        ovr_blitLoadRleGfx(gfx_01,dst_05,(char)marbleCut2Ofs,0);
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
      ovc40_usesBlitGfx10(in_stack_00000004,scrollOffset,
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
      ovc40_usesBlitGfx10(in_stack_00000004,0,(brect_t *)CONCAT13(uVar14,CONCAT12(uVar12,&rect)));
    }
    else {
      ovc40_usesBlitGfx10(in_stack_00000004,0xef,(brect_t *)CONCAT13(uVar14,CONCAT12(uVar12,&rect)))
      ;
    }
    ovc40_flushInput();
    rightButtonLatch = '\0';
    if (((char)textOfs == '\x02') || ((char)textOfs == '\x03')) {
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
      iVar9 = *(int *)BDA_DailyTimeCounter;
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = iVar9;
      if (cStack_1d == '\0') {
        uVar5 = ovr_inputUpdate((ulong)CONCAT11(uVar15,useVgaPalette) << 0x10,0x48);
        cStack_1d = (char)uVar5;
      }
    }
    else {
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = 8;
      gfx_02.ofs = far_t_2000_d3e4.seg;
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = 0xe9;
      (*(uint8_t *)((uint8_t *)&(dst_06.seg))) = useVgaPalette;
      dst_06.ofs = 0xa000;
      (*(uint8_t *)((uint8_t *)&(dst_06.seg) + 1)) = uVar15;
      ovr_blitLoadRleGfx(gfx_02,dst_06,(char)far_t_2000_d3e4.ofs,0);
      MiceProcessed = 0;
      ovr_miceBlitRect((brect_t *)CONCAT13(uVar15,CONCAT12(useVgaPalette,0x2410)),0x4a);
      do {
        do {
          ovr_audio_usesLDIV_at_();
          bVar3 = ovr_init2_usesCFGMice
                            ((uint16_t *)
                             CONCAT13((char)((uint)&clickY >> 8),CONCAT12((char)&clickY,unaff_SS)),
                             (char)&clickX);
          if ((((CONCAT11(extraout_AH,bVar3) != 0) && (0x87 < _clickX)) && (0xb9 < _clickY)) &&
             ((_clickX < 0xd6 && (_clickY < 0xc6)))) goto L_OVC40_69c8_04c6_0AF0;
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
  ovr_miceRestoreArea((brect_t *)CONCAT13(uVar15,CONCAT12(useVgaPalette,0x2410)),0x4a);
  ovr_clearMiceProcessed();
  (*(uint8_t *)((uint8_t *)&(handle.seg))) = useVgaPalette;
  handle.ofs = uStack_16;
  (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar15;
  ovr_stshFree(handle,(char)pvStack_18);
  psStack_1c = ovc40_usesStshLoadGfx(in_stack_00000004);
  (*(uint8_t *)((uint8_t *)&(palette_00.seg))) = useVgaPalette;
  palette_00.ofs = iVar9;
  (*(uint8_t *)((uint8_t *)&(palette_00.seg) + 1)) = uVar15;
  uStack_1a = iVar9;
  ovc40_usesVgaSetPalette8bit(palette_00,(char)psStack_1c);
  ovr_stop_audio();
  CurMusicType = 0xff;
  ovr_init_usesBlitGfxRect();
  if (GameRunning == false) {
    ovc40_usesCalcSeasonPalette(useVgaPalette,1);
  }
  ovr_ovc28_textHalflingCastle();
  ovr_ovc41_usesGMenuItem();
  ovr_miceBlitRect((brect_t *)CONCAT13(uVar15,CONCAT12(useVgaPalette,0x2410)),0x4a);
  return cStack_1d;
}


