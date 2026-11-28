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
  int textWidth2;
  
  TextBlitFlag = 1;
  TextBlitDstSeg = 0xa000;
  if (GameRunning) {
    ovr_ovc42_usesBlitLabel((char *)text1.ofs,(byte)text1.seg,CONCAT11(0x24,row));
  }
  else {
    TextBlitX = 0;
    TextBlitY = (uint)row * 0xb + 0x98;
    textWidth2 = ovr_font_textWidth((char *)text1.ofs,(char *)CONCAT22(Font03.ofs,text1.seg),Font03.seg,0,0);
    if ((text2.ofs == 0 && text2.seg == 0) || (textWidth2 < 0x140)) {
      TextBlitX = TextBlitX + (0x140U - textWidth2 >> 1);
    }
    else {
      text1 = text2;
      textWidth2 = ovr_font_textWidth((char *)text2.ofs,(char *)CONCAT22(Font03.ofs,text2.seg),Font03.seg,0,0);
      if (textWidth2 < 0x140) {
        TextBlitX = TextBlitX + (0x140U - textWidth2 >> 1);
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
void __cdecl16far ovc40_usesVgaSetPalette8bit(far_t palette)

{
  /* Re-derived: the mirror fade, from the full palette down to black, stopping once the factor
     goes below zero.  Same 768-byte buffer fix as setSeasonPalette. */
  int palIndex;
  int factor;
  uint8_t pal [0x300];
  int savedHi;
  int savedLo;

  savedHi = *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  savedLo = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
  factor = 10;
  do {
    if (factor < 0) {
      return;
    }
    for (palIndex = 0; palIndex < 0x300; palIndex = palIndex + 1) {
      pal[palIndex] =
          (uint8_t)(((long)(int)(uint)*(byte *)(palette.ofs + palIndex) * (long)factor & 0xffffU)
                    / 10);
    }
    ovr_vgaSetPalette8bit(pal,0);
    do {
      if (*(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != savedHi) break;
    } while (*(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) == savedLo);
    savedHi = *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    savedLo = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
    factor = factor + -1;
  } while( true );
}


/* 69c8:01ac */
void __cdecl16far setSeasonPalette(far_t palette)

{
  /* Re-derived: fades the palette in from black.  Each step scales every one of the 0x300 channel
     bytes by factor/10, sets the palette, then busy-waits on the BIOS daily tick counter before
     the next step; it stops once the factor passes 10.  The buffer was declared as a single byte
     while indexed to 0x2ff - a 768-byte stack overrun - and is now the array it really is. */
  uint palIndex;
  uint factor;
  uint8_t pal [0x300];
  int savedHi;
  int savedLo;

  savedHi = *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  savedLo = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
  factor = 0;
  do {
    if (10 < factor) {
      return;
    }
    for (palIndex = 0; palIndex < 0x300; palIndex = palIndex + 1) {
      pal[palIndex] =
          (uint8_t)(((long)(int)(uint)*(byte *)(palette.ofs + palIndex) * (long)(int)factor &
                     0xffffU) / 10);
    }
    ovr_vgaSetPalette8bit(pal,0);
    do {
      if (*(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != savedHi) break;
    } while (*(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) == savedLo);
    savedHi = *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    savedLo = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
    factor = factor + 1;
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
  uint16_t gfxSeg;         /* segment of the record ovr_stshLoadGfx returns */
  uint16_t uVar1;
  static char cmapBackupB[64];   /* DGROUP-backed formatting buffer */
  static char cmapBackupA[64];   /* DGROUP-backed formatting buffer */
  stg_tmp_t *gfxRec;
  uint16_t uStack_4;
  
  handle.seg = marbleCut1Seg;
  handle.ofs = marbleCut1Ofs;
  gfxRec = ovr_stshLoadGfx(handle);
  _fmemmove(cmapBackupB,(char far *)MK_FP(gfxSeg,gfxRec->cmap + 0x231),
            0xcf);
  handle_00.seg = Lbm_nwpanel1.seg;
  handle_00.ofs = Lbm_nwpanel1.ofs;
  gfxRec = ovr_stshLoadGfx(handle_00);
  _fmemmove(cmapBackupA,(char far *)MK_FP(gfxSeg,gfxRec->cmap + 0x2ac),
            0xc);
  if (backdropIndex == 4) {
    handle_01.seg = youlose1Cut1Seg;
    handle_01.ofs = youlose1Cut1Ofs;
    gfxRec = ovr_stshLoadGfx(handle_01);
    uStack_4 = gfxSeg;
  }
  else {
    uVar1 = 0x2410;
    handle_02.seg = ((uint16_t *)&back03Cut1Seg)[(uint)backdropIndex * 2];
    handle_02.ofs = ((uint16_t *)&back03Cut1Ofs)[(uint)backdropIndex * 2];
    gfxRec = ovr_stshLoadGfx(handle_02);
    uStack_4 = uVar1;
  }
  _fmemmove((char far *)MK_FP(uStack_4,gfxRec->cmap + 0x231),
            cmapBackupB,0xcf);
  return gfxRec;
}



/* 69c8:0317 */

/* [R4] calls ovr_calcSeasonPalette */

void __cdecl16far ovc40_usesCalcSeasonPalette(char useVgaPalette)

{
  uint16_t inDX;           /* DX on entry, used as the palette segment */
  far_t handle;
  far_t palette;
  far_t palette_00;
  uint8_t pal;
  stg_tmp_t *palRec;
  
  handle.seg = Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  palRec = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette(palRec->cmap,inDX,&pal,_SS,0,0);
  if (useVgaPalette == '\0') {
    palette_00.seg = _SS;
    palette_00.ofs = (uint16_t)&pal;
    ovc40_usesVgaSetPalette8bit(palette_00);
  }
  else {
    palette.seg = _SS;
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
  gfx_03.seg = ((uint16_t *)&back03Cut2Seg)[(uint)backdropIndex * 2];
  gfx_03.ofs = ((uint16_t *)&back03Cut2Ofs)[(uint)backdropIndex * 2];
  ovr_blitLoadRleGfx(gfx_03,far_from_u32((uint32_t)((ulong)dst->seg << 0x10)),0);
  gfx.seg = ((uint16_t *)&midgrnd5Cut1Seg)[(uint)backdropIndex * 2];
  gfx.ofs = ((uint16_t *)&midgrnd5Cut1Ofs)[(uint)backdropIndex * 2];
  type = SUB41((ulong)rect >> 0x10,0);
  ovr_blitGfx10(gfx,-(scrollOffset >> 1),0,dst,type,0,0);
  gfx_00.seg = ((uint16_t *)&midgrnd5Cut2Seg)[(uint)backdropIndex * 2];
  gfx_00.ofs = ((uint16_t *)&midgrnd5Cut2Ofs)[(uint)backdropIndex * 2];
  ovr_blitGfx10(gfx_00,0xdc - (scrollOffset >> 1),0,dst,type,0,0);
  gfx_01.seg = ((uint16_t *)&strong4Cut1Seg)[(uint)backdropIndex * 2];
  gfx_01.ofs = ((uint16_t *)&strong4Cut1Ofs)[(uint)backdropIndex * 2];
  ovr_blitGfx10(gfx_01,-scrollOffset,0,dst,type,0,0);
  gfx_02.seg = ((uint16_t *)&strong4Cut2Seg)[(uint)backdropIndex * 2];
  gfx_02.ofs = ((uint16_t *)&strong4Cut2Ofs)[(uint)backdropIndex * 2];
  ovr_blitGfx10(gfx_02,0x118 - scrollOffset,0,dst,type,0,0);
  ovr_blitRect(dst,0);
  return;
}



/* 69c8:047f */

/* Drains pending keyboard and mouse input, then clears the mouse-button flags. */

void __cdecl16far ovc40_flushInput(void)

{
  uint16_t keyOrMouse;     /* biosKeyAvail then miceButtonsStates */
  bool pending;            /* either source still has input */
  
  do {
    keyOrMouse = ovr_biosKeyAvail();
    pending = (char)keyOrMouse != '\0';
    if (pending) {
      ovr_gameProcessKey();
    }
    keyOrMouse = ovr_miceButtonsStates();
    pending = keyOrMouse != 0 || pending;
  } while (pending);
  rightButtonLatch = 0;
  middleButtonLatch = 0;
  return;
}



/* 69c8:04c6 */
char __cdecl16far
ovc40_usesAlignToSeg
          (char backdropIndex,char *capTextOfs,uint16_t capTextSeg,char *textOfs,uint16_t textSeg,byte formatIndex,uint16_t arg7,uint16_t arg8,uint16_t arg9,uint16_t arg10)

{
  char waitTmp;            /* the countdown value before it is stored */
  bool waiting;            /* the wait loop's condition */
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
  byte labelIdx;           /* label selector handed to ovc40_usesBlitLabel */
  byte mouseCfg;           /* result of ovr_init2_usesCFGMice */
  char *msgPtr;            /* the string ovr_stsprintf returns */
  uint16_t segTmp;         /* segment half of the far pointer being assembled */
  uint mouseButtons;       /* result of ovr_init2_updateMouseButtons */
  undefined1 axHigh;       /* the AH half carried across the call */
  uint16_t dxIn;           /* DX on entry, used as a graphic's segment */
  uint8_t *format1Tab;     /* the 4-byte entry table format1 indexes */
  uint8_t *format2Tab;     /* the same for format2 */
  int *timeStamp;          /* BDA_DailyTimeCounter's value, used as a timestamp */
  int scrollOffset;
  undefined1 ofsLo;        /* low byte of msgPtr, stored as the offset */
  undefined1 ofsHi;        /* high byte of msgPtr */
  undefined1 ssLo;         /* low byte of _SS, for the split pointers */
  byte blitColour;         /* the label colour, 0xf2 throughout */
  undefined1 ssHi;         /* high byte of _SS */
  uint8_t text1;
  uint8_t text2;
  far_t groupNames[4];     /* 16 bytes copied from ds:0x6b76: four far pointers */
  uint16_t uStack_68;
  uint16_t uStack_66;
  uint8_t format1;
  uint16_t auStack_62 [3];
  far_t rankNames[15];    /* 60 bytes copied from ds:0x6b3a: fifteen far pointers */
  uint16_t uStack_5a;
  uint16_t uStack_58;
  char *capTextShownSeg;   /* segment half of the caption's text pointer */
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
  uint16_t uStack_2c;
  char *text1Seg;          /* segment half of the &text1 far pointer */
  uint16_t uStack_28;
  uint16_t uStack_26;
  uint16_t uStack_24;
  uint16_t uStack_22;
  char backKind;           /* 2 or -2, from backdropIndex */
  char waitTicks;          /* 0x77 ticks the wait loop counts down */
  char result;             /* the value the function returns */
  stg_tmp_t *palRec;       /* the record ovc40_usesStshLoadGfx returns */
  uint16_t palSeg;         /* segment stored into palette.seg */
  void *stashMem;          /* the ovr_stshAlloc scratch block */
  uint16_t handleSeg;      /* segment stored into handle.seg */
  uint8_t rect[10];        /* the 10-byte rectangle copied from ds:0x6b86 */
  int waitStart;           /* the timestamp the wait loop started from */
  int tickMark;            /* the BDA counter value sampled in the loop */
  uint8_t clickY;
  uint8_t clickX;
  
  ssLo = SUB21(_SS,0);
  ssHi = (undefined1)((uint)_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = ssLo;
  dst_00.ofs = (uint16_t)&rankNames;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = ssHi;
  F_SCOPY(far_from_u32((uint32_t)(0x24106b3a)),dst_00,60);
  (*(uint8_t *)((uint8_t *)&(dst_01.seg))) = ssLo;
  dst_01.ofs = (uint16_t)&groupNames;
  (*(uint8_t *)((uint8_t *)&(dst_01.seg) + 1)) = ssHi;
  F_SCOPY(far_from_u32((uint32_t)(0x24106b76)),dst_01,16);
  (*(uint8_t *)((uint8_t *)&(dst_02.seg))) = ssLo;
  dst_02.ofs = (uint16_t)&rect[0];
  (*(uint8_t *)((uint8_t *)&(dst_02.seg) + 1)) = ssHi;
  F_SCOPY(far_from_u32((uint32_t)(0x24106b86)),dst_02,10);
  result = '\0';
  ovr_stop_audio();
  ovc40_flushInput();
  ovr_draw_freeRingBuffers();
  MiceUnkState = 0;
  stashMem = ovr_stshAlloc(0xfa0f);
  (*(uint8_t *)((uint8_t *)&(ptr.seg))) = (char)dxIn;
  ptr.ofs = (uint16_t)stashMem;
  (*(uint8_t *)((uint8_t *)&(ptr.seg) + 1)) = (char)(dxIn >> 8);
  handleSeg = dxIn;
  ovr_alignToSeg(ptr);
  if (GameRunning == false) {
    ovc40_usesCalcSeasonPalette('\0');
  }
  MiceNeedsUpdate = 1;
  ovr_driver_fillRect(0,0,0x13f,199,0xec,0xa000,0x3f,0xec,0,0,0);
  gfx.seg = marbleCut2Seg;
  gfx.ofs = marbleCut2Ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000b400)),0);
  if (backdropIndex == '\x02') {
    backKind = '\x02';
  }
  else {
    backKind = -2;
  }
  if (backdropIndex == '\x04') {
    gfx_00.seg = youlose1Cut2Seg;
    gfx_00.ofs = youlose1Cut2Ofs;
    ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa0000000)),0);
  }
  else if (backKind < '\0') {
    ovc40_usesBlitGfx10(backdropIndex,0xef,(brect_t *)CONCAT13(ssHi,CONCAT12(ssLo,&rect)));
  }
  else {
    ovc40_usesBlitGfx10(backdropIndex,0,(brect_t *)CONCAT13(ssHi,CONCAT12(ssLo,&rect)));
  }
  palRec = ovc40_usesStshLoadGfx(backdropIndex);
  if (formatIndex == 4) {
    CurMusicType = 0x44;
  }
  else if ((formatIndex == 0) || (formatIndex == 6)) {
    CurMusicType = 0x21;
  }
  else {
    CurMusicType = 0x2d;
  }
  palSeg = dxIn;
  ovr_play_sfx(CONCAT11(0x24,CurMusicType),0,0);
  (*(uint8_t *)((uint8_t *)&(palette.seg))) = (char)palSeg;
  palette.ofs = (uint16_t)palRec;
  (*(uint8_t *)((uint8_t *)&(palette.seg) + 1)) = (char)(palSeg >> 8);
  setSeasonPalette(palette);
  if (formatIndex == 2) {
    /* 0x0676: both pointers are rankNames[4]. */
    text1_00 = rankNames[4];
    text2_00 = rankNames[4];
    ovc40_usesBlitLabel(text1_00,text2_00,0,0xf2);
    /* 0x068e: both are rankNames[5]. */
    text1_01 = rankNames[5];
    text2_01 = rankNames[5];
    ovc40_usesBlitLabel(text1_01,text2_01,1,0xf2);
    /* 0x06a6: text1 is rankNames[14], text2 rankNames[5]. */
    text1_02 = rankNames[14];
    text2_02 = rankNames[5];
    ovc40_usesBlitLabel(text1_02,text2_02,2,0xf2);
  }
  else if (formatIndex == 3) {
    /* 0x06c7: both are rankNames[6]. */
    text1_03 = rankNames[6];
    text2_03 = rankNames[6];
    ovc40_usesBlitLabel(text1_03,text2_03,0,0xf2);
    /* 0x06df: both are rankNames[7]. */
    text1_04 = rankNames[7];
    text2_04 = rankNames[7];
    ovc40_usesBlitLabel(text1_04,text2_04,1,0xf2);
    /* 0x06f7: both are rankNames[8]. */
    text1_05 = rankNames[8];
    text2_05 = rankNames[8];
    ovc40_usesBlitLabel(text1_05,text2_05,2,0xf2);
  }
  else if ((formatIndex == 4) || (formatIndex == 6)) {
    ovr_ovc15_capitalize((char *)&text1);
    blitColour = 0xf2;
    labelIdx = 1;
    segTmp = 0;
    ofsLo = 0;
    ofsHi = 0;
    msgPtr = ovr_stsprintf((char *)&text2,(char *)CONCAT22(uStack_2c,_SS),
                           (char *)CONCAT22(&text1,text1Seg));
    text1_06.seg = dxIn;
    text1_06.ofs = (uint16_t)msgPtr;
    (*(uint8_t *)((uint8_t *)&(text2_06.ofs) + 1)) = ofsHi;
    (*(uint8_t *)((uint8_t *)&(text2_06.ofs))) = ofsLo;
    text2_06.seg = segTmp;
    ovc40_usesBlitLabel(text1_06,text2_06,labelIdx,blitColour);
  }
  else if (formatIndex == 5) {
    ovr_ovc15_capitalize((char *)&text1);
    blitColour = 0xf2;
    labelIdx = 0;
    segTmp = 0;
    ofsLo = 0;
    ofsHi = 0;
    msgPtr = ovr_stsprintf((char *)&text2,(char *)CONCAT22(uStack_2c,_SS),
                           (char *)CONCAT22(&text1,text1Seg));
    text1_07.seg = dxIn;
    text1_07.ofs = (uint16_t)msgPtr;
    (*(uint8_t *)((uint8_t *)&(text2_07.ofs) + 1)) = ofsHi;
    (*(uint8_t *)((uint8_t *)&(text2_07.ofs))) = ofsLo;
    text2_07.seg = segTmp;
    ovc40_usesBlitLabel(text1_07,text2_07,labelIdx,blitColour);
    /* 0x07a5: rankNames[13] against a null second pointer. */
    text1_08 = rankNames[13];
    ovc40_usesBlitLabel(text1_08,far_from_u32((uint32_t)(0x0)),1,0xf2);
  }
  else {
    text1_09.seg = rankNames[11].seg;
    text1_09.ofs = rankNames[11].ofs;
    text2_08.seg = rankNames[11].seg;
    text2_08.ofs = rankNames[11].ofs;
    ovc40_usesBlitLabel(text1_09,text2_08,0,0xf2);
    blitColour = 0xf2;
    labelIdx = 1;
    msgPtr = ovr_stsprintf((char *)&text1,(char *)CONCAT22(uStack_68,_SS),
                           (char *)CONCAT13((char)((uint)capTextOfs >> 8),
                                            CONCAT12((char)capTextOfs,uStack_66)),(char)capTextOfs,
                           capTextSeg);
    ofsLo = SUB21(msgPtr,0);
    ofsHi = (undefined1)((uint)msgPtr >> 8);
    segTmp = dxIn;
    msgPtr = ovr_stsprintf((char *)&text2,(char *)CONCAT22(uStack_58,_SS),
                           (char *)CONCAT22(capTextOfs,capTextShownSeg),capTextSeg);
    text1_10.seg = dxIn;
    text1_10.ofs = (uint16_t)msgPtr;
    (*(uint8_t *)((uint8_t *)&(text2_09.ofs) + 1)) = ofsHi;
    (*(uint8_t *)((uint8_t *)&(text2_09.ofs))) = ofsLo;
    text2_09.seg = segTmp;
    ovc40_usesBlitLabel(text1_10,text2_09,labelIdx,blitColour);
    blitColour = 0xf2;
    labelIdx = 2;
    format1Tab = &format1;
    msgPtr = ovr_stsprintf((char *)&text1,
                           (char *)CONCAT22(*(uint16_t *)(format1Tab + (uint)formatIndex * 4),_SS
                                           ),
                           (char *)CONCAT13((char)((uint)textOfs >> 8),
                                            CONCAT12((char)textOfs,auStack_62[(uint)formatIndex * 2]
                                                    )),(char)textOfs,textSeg);
    ofsLo = SUB21(msgPtr,0);
    ofsHi = (undefined1)((uint)msgPtr >> 8);
    format2Tab = &format2;
    msgPtr = ovr_stsprintf((char *)&text2,
                           (char *)CONCAT22(*(uint16_t *)(format2Tab + (uint)formatIndex * 4),_SS
                                           ),
                           (char *)CONCAT22(textOfs,(char *)auStack_52[(uint)formatIndex * 2]),
                           textSeg);
    text1_11.seg = (uint16_t)format2Tab;
    text1_11.ofs = (uint16_t)msgPtr;
    (*(uint8_t *)((uint8_t *)&(text2_10.ofs) + 1)) = ofsHi;
    (*(uint8_t *)((uint8_t *)&(text2_10.ofs))) = ofsLo;
    text2_10.seg = (uint16_t)format1Tab;
    ovc40_usesBlitLabel(text1_11,text2_10,labelIdx,blitColour);
  }
  ovc40_flushInput();
  ovr_ovr_miceButton0PressStates_entry();
  tickMark = *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  timeStamp = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
  if (backdropIndex == '\x04') {
    waitStart = timeStamp;
    segTmp = ovr_inputUpdate(0xb4);
    if (1 < (byte)segTmp) {
      result = '\x02';
    }
  }
  else {
    if (backKind < '\0') {
      scrollOffset = 0xee;
    }
    else {
      scrollOffset = 1;
    }
    waitTicks = 'w';
    while (waitTmp = waitTicks + -1, waiting = waitTicks != '\0', waitTicks = waitTmp, waitStart = timeStamp,
          waiting) {
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
                          (brect_t *)CONCAT13(ssHi,CONCAT12(ssLo,&rect)));
      segTmp = ovr_biosKeyAvail();
      if ((char)segTmp != '\0') {
        segTmp = ovr_gameProcessKey();
        if (segTmp == 0x11b) {
          result = '\x02';
          break;
        }
        if (segTmp == 0x1c0d) break;
      }
      mouseButtons = ovr_init2_updateMouseButtons();
      if (mouseButtons != 0) break;
      if (rightButtonLatch != '\0') {
        result = '\x02';
        break;
      }
      do {
        ovr_audio_usesLDIV_at_();
        if (*(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != tickMark) break;
      } while (*(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */ == waitStart);
      tickMark = *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
      timeStamp = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
      scrollOffset = scrollOffset + backKind;
    }
    if (backKind < '\x01') {
      ovc40_usesBlitGfx10(backdropIndex,0,(brect_t *)CONCAT13(ssHi,CONCAT12(ssLo,&rect)));
    }
    else {
      ovc40_usesBlitGfx10(backdropIndex,0xef,(brect_t *)CONCAT13(ssHi,CONCAT12(ssLo,&rect)));
    }
    ovc40_flushInput();
    rightButtonLatch = '\0';
    if ((formatIndex == 2) || (formatIndex == 3)) {
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
      timeStamp = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = timeStamp;
      if (result == '\0') {
        segTmp = ovr_inputUpdate(0x48);
        result = (char)segTmp;
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
          mouseCfg = ovr_init2_usesCFGMice
                            ((uint16_t *)&clickX,(uint16_t *)
                             CONCAT13((char)((uint)&clickY >> 8),CONCAT12((char)&clickY,_SS)),0);
          if ((((CONCAT11(axHigh,mouseCfg) != 0) && (0x87 < clickX)) && (0xb9 < clickY)) &&
             ((clickX < 0xd6 && (clickY < 0xc6)))) goto L_OVC40_69c8_04c6_0AF0;
          if (rightButtonLatch != '\0') {
            result = '\x02';
            goto L_OVC40_69c8_04c6_0AF0;
          }
          segTmp = ovr_biosKeyAvail();
        } while ((char)segTmp == '\0');
        segTmp = ovr_gameProcessKey();
        if (segTmp == 0x11b) {
          result = '\x02';
          break;
        }
      } while (segTmp != 0x1c0d);
    }
  }
L_OVC40_69c8_04c6_0AF0:
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
  ovr_clearMiceProcessed();
  (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)handleSeg;
  handle.ofs = (uint16_t)stashMem;
  (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)(handleSeg >> 8);
  ovr_stshFree(handle);
  palRec = ovc40_usesStshLoadGfx(backdropIndex);
  (*(uint8_t *)((uint8_t *)&(palette_00.seg))) = (char)timeStamp;
  palette_00.ofs = (uint16_t)palRec;
  (*(uint8_t *)((uint8_t *)&(palette_00.seg) + 1)) = (char)((uint)timeStamp >> 8);
  palSeg = timeStamp;
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
  return result;
}

