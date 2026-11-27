/*
 * ovc21_manage.c - recovered from STRONG.EXE
 * memory block: OVC21_manage.c
 * range: 4d05:0000 - 4d05:381f
 * functions: 43
 */
#include "recovered.h"


/* 4d05:0000 */

/* Builds MenuItemEnabled: partySlot -> leader index for the active leaders, 0xff elsewhere. */

void __cdecl16far manage_mapPartySlots(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
    ((uint8_t *)MenuItemEnabled)[iVar1] = 0xff;
  }
  for (iVar1 = 0; iVar1 < (int)(uint)GLeaderCount; iVar1 = iVar1 + 1) {
    if (((GLeaderSheets[iVar1])->active != '\0') &&
       ((GLeaderSheets[iVar1])->partySlot != -1)) {
      ((uint8_t *)MenuItemEnabled)[(GLeaderSheets[iVar1])->partySlot] =
           (uint8_t)iVar1;
    }
  }
  return;
}



/* 4d05:0081 */

/* Opens the talk window: sets ScreenMode, installs the talkwin9 palette, fills the panel and blits
   the three window cuts. */

void __cdecl16far manage_openTalkWindow(void)

{
  uint16_t in_DX;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t handle;
  uint8_t palette;
  stg_tmp_t *palRec;
  
  mapViewActive = 0xff;
  ScreenMode = 1;
  handle.seg = talkwin9Cut5Seg;
  handle.ofs = talkwin9Cut5Ofs;
  palRec = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette(palRec->cmap,in_DX,&palette,_SS,0,0);
  ovr_driver_fillRect(0xc,7,0xde,0x96,0xec,0xa000,0,0,0,0,0);
  ovr_vgaSetPalette8bit(&palette,0);
  gfx.seg = talkwin9Cut1Seg;
  gfx.ofs = talkwin9Cut1Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)(BlitRects + 1),0x10,true,0,0,0,0,0,0);
  gfx_00.seg = talkwin9Cut2Seg;
  gfx_00.ofs = talkwin9Cut2Ofs;
  ovr_blitGfxRect(gfx_00,0,0,(brect_t *)(BlitRects + 1),0x10,true,0,0,0,0,0,0);
  gfx_01.seg = talkwin9Cut3Seg;
  gfx_01.ofs = talkwin9Cut3Ofs;
  ovr_blitGfxRect(gfx_01,0,0,(brect_t *)(BlitRects + 1),0x10,true,0,0,0,0,0,0);
  return;
}



/* 4d05:0166 */

/* Blits the talkwin9Cut1 window graphic at the origin, clipped by panelClipRect. */

void __cdecl16far manage_blitTalkWindow(void)

{
  far_t gfx;
  far_t dst;
  uint8_t rect;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)&rect;
  F_SCOPY(far_from_u32((uint32_t)(0x2410493b)),dst,10);
  gfx.seg = talkwin9Cut1Seg;
  gfx.ofs = talkwin9Cut1Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)&rect,(uint8_t)_SS,true,0,0,0,0,0,0);
  return;
}



/* 4d05:01a3 */

/* Rolls count dice of the given number of sides and returns the sum. */

char __cdecl16far manage_rollDice(char count,char sides)

{
  uint16_t uVar1;
  undefined1 uStack_3;
  
  uStack_3 = '\0';
  while (count != '\0') {
    uVar1 = ovr_randBelow((uint)(byte)sides,0);
    uStack_3 = (char)uVar1 + uStack_3 + '\x01';
    count = count + -1;
  }
  return uStack_3;
}



/* 4d05:01d4 */

/* Rolls the six stats (3d6 + randBelow(4), capped at 18) and marks statMask bit 5. */

void __cdecl16far manage_rollStats(char_sheet_t *sheet,uint16_t arg2)

{
  char cVar1;
  uint16_t uVar2;
  byte bStack_3;
  
  for (bStack_3 = 0; bStack_3 < 6; bStack_3 = bStack_3 + 1) {
    cVar1 = manage_rollDice('\x03','\x06');
    uVar2 = ovr_randBelow(4,0);
    sheet->stats[bStack_3] = cVar1 + (char)uVar2;
    if (0x11 < sheet->stats[bStack_3]) {
      sheet->stats[bStack_3] = 0x12;
    }
  }
  sheet->statMask = sheet->statMask | 0x20;
  return;
}



/* 4d05:023a */

/* [R7] body shape: compute */

char * __cdecl16far manage_compute1(int n,uint16_t arg2)

{
  int iVar1;
  char *pcStack_6;
  
  iVar1 = n % 10;
  if ((iVar1 == 1) && (n != 0xb)) {
    pcStack_6 = (char *)"st";
  }
  else if ((iVar1 == 2) && (n != 0xc)) {
    pcStack_6 = (char *)"nd";
  }
  else if ((iVar1 == 3) && (n != 0xd)) {
    pcStack_6 = (char *)"rd";
  }
  else {
    pcStack_6 = (char *)"th";
  }
  return pcStack_6;
}



/* 4d05:029d */

/* [R7] body shape: compute */

byte __cdecl16far manage_compute2(char_sheet_t far *sheet)

{
  byte result;
  
  if ((sheet->cls == 4) && (0xc < sheet->race)) {
    result = 0xc;
  }
  else if ((sheet->cls == 5) && (10 < sheet->race)) {
    result = 10;
  }
  else if ((sheet->cls == 6) && (8 < sheet->race)) {
    result = 8;
  }
  else {
    result = sheet->race;
  }
  return result;
}



/* 4d05:02f1 */

/* [R7] body shape: compute */

byte __cdecl16far manage_compute3(char_sheet_t far *sheet)

{
  byte result;
  
  if ((sheet->cls == 4) && (0xb < sheet->race)) {
    result = 1;
  }
  else if ((sheet->cls == 5) && (9 < sheet->race)) {
    result = 1;
  }
  else if ((sheet->cls == 6) && (7 < sheet->race)) {
    result = 1;
  }
  else {
    result = 0;
  }
  return result;
}



/* 4d05:0340 */

/* [R7] body shape: compute */

byte __cdecl16far manage_compute4(char_sheet_t far *sheet)

{
  byte result;
  
  if ((sheet->cls == 4) && (0xb < sheet->race)) {
    result = sheet->race + 0x37;
  }
  else if ((sheet->cls == 5) && (9 < sheet->race)) {
    result = sheet->race + 0x39;
  }
  else if ((sheet->cls == 6) && (7 < sheet->race)) {
    result = sheet->race + 0x39;
  }
  else {
    result = 0x30;
  }
  return result;
}



/* 4d05:03a4 */

/* Returns the player title for a character sheet from GPlayerTitles (indexed by gender and class).
    */

void * __cdecl16far manage_playerTitle(char_sheet_t *sheet,...)

{
  char *pcVar1;
  far_t dst;
  uint8_t titlesMap;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)&titlesMap;
  F_SCOPY(far_from_u32((uint32_t)(0x241049a5)),dst,56);
  if (sheet->cls == 0xff) {
    pcVar1 = (char *)0x28c75;
  }
  else if (sheet->titleIndex == 0) {
    if ((sheet->race < 9) && ((sheet->cls != 6 || (sheet->race < 8)))) {
      pcVar1 = (char *)0x28c75;
    }
    else {
      pcVar1 = *(char **)(&titlesMap + (uint)sheet->cls * 8 + (uint)sheet->gender * 4);
    }
  }
  else {
    pcVar1 = (char *)((far_t *)(GStatsLabels + 4) +
                     (uint)sheet->gender + (uint)sheet->titleIndex * 2)->ofs;
  }
  return pcVar1;
}



/* 4d05:044e */

/* [R6] touches GLeaderCount */

uint __cdecl16far manage_usesGLeaderCount(void)

{
  /* Re-derived: the mean popularity of the active leaders whose sheet +0x3f byte is clear,
     or 0 when there are none. */
  byte activeCount;
  int leaderIdx;
  uint sum;

  sum = 0;
  activeCount = 0;
  for (leaderIdx = 0; leaderIdx < (int)(uint)GLeaderCount; leaderIdx = leaderIdx + 1) {
    if (((GLeaderSheets[leaderIdx])->active != '\0') &&
       (*((char far *)GLeaderSheets[leaderIdx] + 0x3f) == '\0')) {
      sum = sum + (GLeaderSheets[leaderIdx])->popularity;
      activeCount = activeCount + 1;
    }
  }
  if (activeCount != 0) {
    sum = sum / activeCount;
  }
  return sum;
}



/* 4d05:04c6 */

/* Right-aligns text at x (TextBlitX = x - text width) and blits it with Font02. */

void __cdecl16far manage_blitLabelRight(char *text,int x)

{
  int iVar1;
  
  iVar1 = ovr_font_textWidth((char *)text,(char *)CONCAT22(Font02.ofs,(*(uint16_t *)((uint8_t *)&(text) + 2))),Font02.seg,0,0);
  TextBlitX = x - iVar1;
  ovr_blitLabel((char *)text,(uint8_t *)CONCAT22(Font02.ofs,(*(uint16_t *)((uint8_t *)&(text) + 2))),Font02.seg,0xde,0x50);
  return;
}



/* 4d05:0519 */

/* [R4] calls ovr_blitLabel */

void __cdecl16far manage_usesBlitLabel2(char *text,int x)

{
  int iVar1;
  undefined1 in_stack_0000000a;
  
  iVar1 = ovr_font_textWidth((char *)text,(char *)CONCAT22(Font02.ofs,(*(uint16_t *)((uint8_t *)&(text) + 2))),Font02.seg,0,0);
  TextBlitX = x - iVar1;
  ovr_blitLabel((char *)text,(uint8_t *)CONCAT22(Font02.ofs,(*(uint16_t *)((uint8_t *)&(text) + 2))),Font02.seg,0xde,
                CONCAT11(0x24,in_stack_0000000a));
  return;
}



/* 4d05:056e */

/* [R4] calls litoa10 */

void __cdecl16far manage_usesLitoa10(char_sheet_t *sheet)

{
  char xOffset;
  char difficulty;
  void *titleWord;
  char *textPtr;
  uint16_t diffValue;
  uint16_t dsSegment;
  uint leaderCount;
  uint8_t *in_DX;
  int signWord;
  char_sheet_t *sheet_00;
  int statIndex;
  int titleResult;
  int classOfs;
  int statValue;
  int promotableCount;
  uint16_t textY;
  uint16_t fontOfs;
  char *sheetWord;
  char *labelText;
  uint16_t fontSegment;
  undefined1 loByte;
  uint8_t attr;
  undefined1 hiByte;
  char textBuf [120];
  uint8_t msg;
  byte statMask;
  byte firstLeader;
  int textWidth;
  
  sheetWord = (char *)((ulong)sheet >> 0x10);
  sheet_00 = (char_sheet_t *)sheet;
  statMask = sheet_00->statMask;
  if ((statMask & 0x20) != 0) {
    textY = 0x1b;
    for (statIndex = 0; statIndex < 6; statIndex = statIndex + 1) {
      TextBlitX = 0x15;
      TextBlitY = textY;
      ovr_blitLabel((char *)((far_t *)GStatsLabels + statIndex)->ofs,
                    (uint8_t *)
                    CONCAT22(Font02.ofs,
                             (uint8_t *)*(uint16_t *)((int)&GStatsLabels[0].seg + statIndex * 4)),
                    Font02.seg,0xde,0xde,0xe0);
      ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,_SS),
                    (char *)(ulong)CONCAT12(sheet_00->stats[statIndex],0x2410),0x10);
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)_SS >> 8),CONCAT12((char)_SS,&msg)),0x31);
      textY = textY + 10;
    }
  }
  TextBlitY = 0xc;
  if ((statMask & 2) != 0) {
    TextBlitX = 0x15;
    loByte = (undefined1)Font02.ofs;
    hiByte = (undefined1)(Font02.ofs >> 8);
    textPtr = manage_playerTitle(sheet_00,sheetWord,loByte,(char)Font02.seg);
    textWidth = ovr_font_textWidth(textPtr,(char *)CONCAT13(hiByte,CONCAT12(loByte,in_DX)),0,0,0);
    loByte = 0x50;
    attr = 0xde;
    xOffset = (char)(0x7d - textWidth);
    fontOfs = Font02.ofs;
    fontSegment = Font02.seg;
    titleResult = ovr_ovc45_compute9((char *)&msg,(char *)CONCAT22(sheet_00,_SS),
                               (char *)CONCAT22(Font02.ofs,sheetWord),Font02.seg,xOffset,xOffset,3);
    titleWord = manage_playerTitle(sheet_00,sheetWord,(char)titleResult,in_DX);
    textPtr = ovr_stsprintf(textBuf,(char *)CONCAT22(0x4cd4,_SS),
                           (char *)CONCAT22(titleWord,(char *)0x26510),in_DX);
    ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),fontSegment,attr,attr,loByte);
  }
  if ((statMask & 4) != 0) {
    loByte = 0x50;
    attr = 0xde;
    fontOfs = Font02.ofs;
    fontSegment = Font02.seg;
    textPtr = ovr_fmVsprintf("%s ",(char *)CONCAT22(*(uint16_t *)
                                                    ((int)&GAlignmentsNames[0].seg +
                                                    (uint)sheet_00->alignment * 4),
                                                   (char *)((far_t *)GAlignmentsNames +
                                                           sheet_00->alignment)->ofs));
    ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),fontSegment,attr,attr,loByte);
  }
  if ((statMask & 1) != 0) {
    loByte = 0x50;
    attr = 0xde;
    classOfs = (uint)sheet_00->cls * 4;
    in_DX = (uint8_t *)((char *)0x26510);
    fontOfs = Font02.ofs;
    fontSegment = Font02.seg;
    textPtr = ovr_fmVsprintf("%s",(char *)CONCAT22(*(uint16_t *)(classOfs + 0xed),
                                                  (char *)*(uint16_t *)(classOfs + 0xeb)));
    ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),fontSegment,attr,attr,loByte);
  }
  TextBlitY = TextBlitY + 10;
  if (((statMask & 0x40) != 0) || (DebugVerbose != false)) {
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Population",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    loByte = 0x7d;
    hiByte = 0;
    textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,_SS),
                           (char *)CONCAT13((char)((uint)sheet_00->population >> 8),
                                            CONCAT12((char)sheet_00->population,0x2410)));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,textPtr)),
               CONCAT11(hiByte,loByte));
    TextBlitX = 0x82;
    ovr_ovc22_textRingProt(sheet_00->charIndex);
    ovr_blitLabel((char *)"Food prod.",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    loByte = 0xdc;
    hiByte = 0;
    textPtr = litoa10(textBuf,(long)CONCAT22(sheet_00->foodProd,_SS),0,0);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,textPtr)),
               CONCAT11(hiByte,loByte));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x82;
    ovr_blitLabel((char *)"Food stored",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    loByte = 0xdc;
    hiByte = 0;
    textPtr = litoa10(textBuf,(long)CONCAT22((int)sheet_00->foodStored,_SS),(char)*(uint16_t *)((int)&sheet_00->foodStored + 2),0);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,textPtr)),
               CONCAT11(hiByte,loByte));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Housing",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    loByte = 0x7d;
    hiByte = 0;
    textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,_SS),
                           (char *)CONCAT13((char)((uint)sheet_00->housing >> 8),
                                            CONCAT12((char)sheet_00->housing,0x2410)));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,textPtr)),
               CONCAT11(hiByte,loByte));
    TextBlitX = 0x82;
    ovr_blitLabel((char *)"Food storage",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    loByte = 0xdc;
    hiByte = 0;
    textPtr = litoa10(textBuf,(long)CONCAT22((int)sheet_00->foodStorage,_SS),(char)*(uint16_t *)((int)&sheet_00->foodStorage + 2),0);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,textPtr)),
               CONCAT11(hiByte,loByte));
    TextBlitY = TextBlitY + 0xf;
    if (sheet_00->maxTrade != 0) {
      TextBlitX = 0x37;
      if (sheet_00->foodSold < 0) {
        ovr_blitLabel((char *)"Food sold",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                      Font02.seg,0xde,0xde,0xe0);
        loByte = 0x7d;
        hiByte = 0;
        statValue = -sheet_00->foodSold;
        signWord = statValue >> 0xf;
        textPtr = litoa10(textBuf,(long)CONCAT22(statValue,_SS),(char)(statValue >> 0xf),0);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)signWord >> 8),CONCAT12((char)signWord,textPtr)),
                   CONCAT11(hiByte,loByte));
      }
      else {
        ovr_blitLabel((char *)"Food bought",
                      (uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),Font02.seg,0xde,0xde
                      ,0xe0);
        loByte = 0x7d;
        hiByte = 0;
        statValue = sheet_00->foodSold;
        signWord = statValue >> 0xf;
        textPtr = litoa10(textBuf,(long)CONCAT22(statValue,_SS),(char)(statValue >> 0xf),0);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)signWord >> 8),CONCAT12((char)signWord,textPtr)),
                   CONCAT11(hiByte,loByte));
      }
      TextBlitX = 0x82;
      ovr_blitLabel((char *)"Max. trade",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                    Font02.seg,0xde,0xde,0xe0);
      loByte = 0xdc;
      hiByte = 0;
      textPtr = litoa10(textBuf,(long)CONCAT22(sheet_00->maxTrade,_SS),0,0);
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)signWord >> 8),CONCAT12((char)signWord,textPtr)),
                 CONCAT11(hiByte,loByte));
    }
    TextBlitY = TextBlitY + 0xf;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Income",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    loByte = 0xdc;
    hiByte = 0;
    statValue = sheet_00->income;
    signWord = statValue >> 0xf;
    textPtr = litoa10((char *)&msg,(long)CONCAT22(statValue,_SS),(char)(statValue >> 0xf),0);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)signWord >> 8),CONCAT12((char)signWord,textPtr)),
               CONCAT11(hiByte,loByte));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Gold",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    loByte = 0xdc;
    hiByte = 0;
    textPtr = litoa10((char *)&msg,(long)CONCAT22((int)sheet_00->gold,_SS),(char)*(uint16_t *)((int)&sheet_00->gold + 2),0);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)signWord >> 8),CONCAT12((char)signWord,textPtr)),
               CONCAT11(hiByte,loByte));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Vault storage",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    loByte = 0xdc;
    hiByte = 0;
    textPtr = litoa10((char *)&msg,(long)CONCAT22((int)sheet_00->vaultStorage,_SS),(char)*(uint16_t *)((int)&sheet_00->vaultStorage + 2),0);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)signWord >> 8),CONCAT12((char)signWord,textPtr)),
               CONCAT11(hiByte,loByte));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Fund Access",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    loByte = 0xdc;
    hiByte = 0;
    diffValue = ovr_ovc45_usesLDIV_at_(sheet_00->charIndex,0,0);
    textPtr = litoa10(textBuf,(long)CONCAT22(diffValue,_SS),(char)signWord,0);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)signWord >> 8),CONCAT12((char)signWord,textPtr)),
               CONCAT11(hiByte,loByte));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Common fund",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    loByte = 0xdc;
    hiByte = 0;
    textPtr = litoa10(textBuf,(long)CONCAT22(GPopulationLo,_SS),(char)GPopulationHi,0);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)signWord >> 8),CONCAT12((char)signWord,textPtr)),
               CONCAT11(hiByte,loByte));
    firstLeader = manage_findFirstLeader();
    TextBlitY = TextBlitY + 0xf;
    if (((sheet_00->titleIndex != 0) && (firstLeader != 0xff)) &&
       (dsSegment = _DS, (GLeaderSheets[firstLeader])->titleIndex < 9)) {
      manage_usesBlitLabel2("popularity",0x7d);
      manage_usesBlitLabel2("city blocks",0xdc);
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x11;
      ovr_blitLabel((char *)"Current",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                    Font02.seg,0xde,0xde,0xe0);
      loByte = 0x7d;
      hiByte = 0;
      leaderCount = manage_usesGLeaderCount();
      labelText = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4d8b,_SS),
                             (char *)CONCAT13((char)(leaderCount >> 8),CONCAT12((char)leaderCount,0x2410)));
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)dsSegment >> 8),CONCAT12((char)dsSegment,labelText)),
                 CONCAT11(hiByte,loByte));
      loByte = 0xdc;
      hiByte = 0;
      labelText = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,_SS),
                             (char *)CONCAT13((char)((uint)GPromotableCount >> 8),
                                              CONCAT12((char)GPromotableCount,0x2410)));
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)dsSegment >> 8),CONCAT12((char)dsSegment,labelText)),
                 CONCAT11(hiByte,loByte));
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x11;
      ovr_blitLabel((char *)"to promote",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                    Font02.seg,0xde,0xde,0xe0);
      loByte = 0x7d;
      hiByte = 0;
      difficulty = ovr_season_usesDifficulty();
      labelText = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4d8b,_SS),
                             (char *)(ulong)CONCAT12(difficulty,0x2410));
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)dsSegment >> 8),CONCAT12((char)dsSegment,labelText)),
                 CONCAT11(hiByte,loByte));
      loByte = 0xdc;
      hiByte = 0;
      promotableCount = ovr_season_usesGPromotableCount2();
      labelText = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,_SS),
                             (char *)CONCAT13((char)((uint)promotableCount >> 8),CONCAT12((char)promotableCount,0x2410))
                            );
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)dsSegment >> 8),CONCAT12((char)dsSegment,labelText)),
                 CONCAT11(hiByte,loByte));
    }
  }
  return;
}



/* 4d05:0d7b */

/* Decides whether a class stat is offered in the abilities dialog: returns 1 when the stat is below
   18 and another of the first three stats is above 10. */

byte __cdecl16far manage_statSelectable(byte statIndex,char_sheet_t *sheet)

{
  byte bVar1;
  int in_stack_00000006;
  
  if (*(byte *)(in_stack_00000006 + (uint)statIndex + 0x29) < 0x12) {
    for (bVar1 = 0; bVar1 < 3; bVar1 = bVar1 + 1) {
      if ((10 < *(byte *)(in_stack_00000006 + (uint)bVar1 + 0x29)) && (statIndex != bVar1)) {
        return 1;
      }
    }
  }
  return 0;
}



/* 4d05:0dbe */
uint16_t __cdecl16far abilitiesDlg(char_sheet_t *sheet)

{
  uint16_t labelOfs;
  far_t dst;
  far_t dst_00;
  byte selectable;
  undefined1 extraout_AH;
  uint8_t *stat2Entry;
  char *inputResult;
  uint itemIndex;
  far_t entries;
  far_t entries_00;
  undefined1 ssLo;
  undefined1 ssHi;
  uint8_t menuItems;
  uint16_t entrySegs [7];
  char inputCode;
  byte itemCount;
  uint8_t statIndex;
  byte statChoices [5];
  uint8_t classStatMap2;
  uint8_t classStatMap1;
  
  ssLo = (undefined1)_SS;
  ssHi = (undefined1)(_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = ssLo;
  dst.ofs = (uint16_t)&classStatMap1;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = ssHi;
  F_SCOPY(far_from_u32((uint32_t)(0x241049dd)),dst,7);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = ssLo;
  dst_00.ofs = (uint16_t)&classStatMap2;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = ssHi;
  F_SCOPY(far_from_u32((uint32_t)(0x241049e4)),dst_00,7);
  while( true ) {
    _fsetmem(MK_FP(_SS,&menuItems),0x10,0);
    entrySegs[0] = 0x2410;
    menuItems = 0x4d9b;
    itemCount = 1;
    selectable = manage_statSelectable
                      ((&classStatMap1)[((char_sheet_t *)sheet)->cls],
                       (char_sheet_t *)CONCAT22(0x4d9b,(*(uint16_t *)((uint8_t *)&(sheet) + 2))));
    if (selectable != 0) {
      statChoices[itemCount] = (&classStatMap1)[((char_sheet_t *)sheet)->cls];
      labelOfs = ((far_t far *)GStatsLabels + (&classStatMap1)[((char_sheet_t *)sheet)->cls])->ofs;
      itemIndex = (uint)itemCount;
      entrySegs[itemIndex * 2] =
           *(uint16_t *)
            ((int)&GStatsLabels[0].seg + (uint)(&classStatMap1)[((char_sheet_t *)sheet)->cls] * 4);
      *(uint16_t *)(&menuItems + itemIndex * 4) = labelOfs;
      itemCount = itemCount + 1;
    }
    stat2Entry = &classStatMap2 + ((char_sheet_t *)sheet)->cls;
    if (*stat2Entry != 0xff) {
      selectable = manage_statSelectable
                        ((&classStatMap2)[((char_sheet_t *)sheet)->cls],
                         (char_sheet_t *)CONCAT22(menuItems,(*(uint16_t *)((uint8_t *)&(sheet) + 2))));
      stat2Entry = (uint8_t *)CONCAT11(extraout_AH,selectable);
      if (selectable != 0) {
        statChoices[itemCount] = (&classStatMap2)[((char_sheet_t *)sheet)->cls];
        stat2Entry = (uint8_t *)
                 *(uint16_t *)
                  ((int)&GStatsLabels[0].seg +
                  (uint)(&classStatMap2)[((char_sheet_t *)sheet)->cls] * 4);
        labelOfs = ((far_t far *)GStatsLabels + (&classStatMap2)[((char_sheet_t *)sheet)->cls])->ofs;
        itemIndex = (uint)itemCount;
        entrySegs[itemIndex * 2] =(uint16_t)( stat2Entry);
        *(uint16_t *)(&menuItems + itemIndex * 4) = labelOfs;
        itemCount = itemCount + 1;
      }
    }
    if (itemCount == 1) {
      return CONCAT11((char)((uint)stat2Entry >> 8),1);
    }
    ovr_drawString((char *)
                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                   ,0x2410,0x10);
    entries.seg = _SS;
    entries.ofs = (uint16_t)&menuItems;
    inputResult = ovr_uiInputText(entries,(uint)itemCount,far_from_u32((uint32_t)(0x0)),0x0,0);
    inputCode = (char)inputResult;
    if (inputCode == '\0') {
      return 0;
    }
    if (inputCode == '\x01') break;
    statChoices[0] = statChoices[((uint)inputResult & 0xff) - 1];
    ovr_drawString((char *)"Select ability to adjust downwards by two points.",0x2410,0x10);
    _fsetmem(MK_FP(_SS,&menuItems),0x10,0);
    entrySegs[0] = 0x2410;
    menuItems = 0x4e3a;
    itemCount = 1;
    for (statIndex = 0x0; statIndex < 3; statIndex = statIndex + 0x1) {
      if ((10 < ((char_sheet_t *)sheet)->stats[statIndex]) && (statChoices[0] != statIndex)) {
        statChoices[itemCount] = statIndex;
        labelOfs = ((far_t far *)GStatsLabels + statIndex)->ofs;
        itemIndex = (uint)itemCount;
        entrySegs[itemIndex * 2] = *(uint16_t *)((int)&GStatsLabels[0].seg + (uint)statIndex * 4);
        *(uint16_t *)(&menuItems + itemIndex * 4) = labelOfs;
        itemCount = itemCount + 1;
      }
    }
    entries_00.seg = _SS;
    entries_00.ofs = (uint16_t)&menuItems;
    inputResult = ovr_uiInputText(entries_00,(uint)itemCount,far_from_u32((uint32_t)(0x0)),0x0,0);
    inputCode = (char)inputResult;
    if (inputCode == '\0') {
      return 0;
    }
    if (inputCode != '\x01') {
      ((char_sheet_t *)sheet)->stats[statChoices[0]] =
           ((char_sheet_t *)sheet)->stats[statChoices[0]] + 1;
      ((char_sheet_t *)sheet)->stats[statChoices[((uint)inputResult & 0xff) - 1]] =
           ((char_sheet_t *)sheet)->stats[statChoices[((uint)inputResult & 0xff) - 1]] - 2;
      manage_openTalkWindow();
      manage_usesLitoa10(sheet);
    }
  }
  return 1;
}


/* 4d05:1095 */

uint16_t __cdecl16far alignmentDlg(char_sheet_t *sheet)

{
  byte *pbVar1;
  uint16_t widths;
  far_t dst;
  char *inputResult;
  uint uVar3;
  far_t entries;
  char align;
  uint8_t inputBuf;
  
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)_SS;
  dst.ofs = (uint16_t)&inputBuf;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)(_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x24104a03)),dst,8);
  do {
    ovr_drawString((char *)"Select an alignment.",0x2410,0x10);
    inputResult = ovr_uiInputText(far_from_u32((uint32_t)(0x24104927)),3,far_from_u32((uint32_t)(0x0)),0x0,0);
    uVar3 = (uint)inputResult & 0xff;
    if (uVar3 == 0) {
      return 0;
    }
    align = (char)inputResult;
    ((char_sheet_t *)sheet)->alignment = align - 1;
    pbVar1 = &((char_sheet_t *)sheet)->statMask;
    *pbVar1 = *pbVar1 | 4;
    if (CurPartySlot != '\0') {
      return 1;
    }
    widths = *(uint16_t *)((int)&GAlignmentString.seg + uVar3 * 4);
    ovr_drawString((char *)((far_t *)&GAlignmentString + uVar3)->ofs,widths,(char)widths);
    entries.seg = _SS;
    entries.ofs = (uint16_t)&inputBuf;
    inputResult = ovr_uiInputText(entries,2,far_from_u32((uint32_t)(0x0)),0x0,0);
    if (((uint)inputResult & 0xff) == 0) {
      return 0;
    }
  } while (((uint)inputResult & 0xff) != 1);
  return 1;
}



/* 4d05:1146 */

bool __cdecl16far uiPickGender(char_sheet_t *sheet)

{
  char *pcVar1;
  bool bVar2;
  char gender;
  
  ovr_drawString((char *)"Male or female?",0x2410,0);
  pcVar1 = ovr_uiInputText(far_from_u32((uint32_t)(0x24104933)),2,far_from_u32((uint32_t)(0x0)),0x0,0);
  bVar2 = ((uint)pcVar1 & 0xff) != 0;
  if (bVar2) {
    gender = (char)pcVar1;
    ((char_sheet_t *)sheet)->gender = gender - 1;
  }
  return bVar2;
}



/* 4d05:118b */

/* Returns the AD&D ability modifier for a score (-3..+3 at the 4/6/9/13/16/18 thresholds). */

undefined1 __cdecl16far manage_abilityModifier(byte abilityScore)

{
  undefined1 modifier;
  
  if (abilityScore < 4) {
    modifier = 0xfd;
  }
  else if (abilityScore < 6) {
    modifier = 0xfe;
  }
  else if (abilityScore < 9) {
    modifier = 0xff;
  }
  else if (abilityScore < 0xd) {
    modifier = 0;
  }
  else if (abilityScore < 0x10) {
    modifier = 1;
  }
  else if (abilityScore < 0x12) {
    modifier = 2;
  }
  else {
    modifier = 3;
  }
  return modifier;
}



/* 4d05:11cb */

/* Rolls and stores the party member's hit points, then sets statMask bit 4. */

void __cdecl16far manage_rollHitPoints(char_sheet_t *sheet)

{
  /* Re-derived: one hit die per race, rolled below the class limit, plus the constitution
     modifier and one, floored at 1; the total goes into both hp bytes and the 0x10 stat
     mask bit is set. */
  char conBonus;
  uint16_t roll;
  uint rollLo;
  int addend;
  char_sheet_t *sh;
  int i;
  far_t dst;
  uint8_t classLimits;
  int total;

  dst.seg = _SS;
  dst.ofs = (uint16_t)&classLimits;
  F_SCOPY(far_from_u32((uint32_t)(0x24104a0b)),dst,7);
  total = 0;
  for (i = 0; sh = (char_sheet_t *)sheet, i < (int)(uint)sh->race; i = i + 1) {
    roll = ovr_randBelow((uint)(&classLimits)[sh->cls],0);
    rollLo = roll & 0xff;
    conBonus = manage_abilityModifier(sh->stats[4]);
    addend = rollLo + (int)conBonus + 1;
    if (addend < 1) {
      addend = 1;
    }
    total = total + addend;
  }
  sh->hp[0] = (byte)total;
  sh->hp[1] = (byte)total;
  sh->statMask = sh->statMask | 0x10;
  return;
}



/* 4d05:125c */
char * __cdecl16far chargen_switch(uint16_t index)

{
  undefined1 stk_bac4;   /* stack slot bac4 */
  undefined1 stk_ffe9;   /* stack slot ffe9 */
  undefined1 stk_fff2;   /* stack slot fff2 */
  uint16_t *puVar1;
  uint8_t *puVar2;
  uint *puVar3;
  int *piVar4;
  byte *pbVar5;
  uint16_t placeOfs;
  uint32_t uVar7;
  far_t entries;
  far_t entries_00;
  far_t handle;
  char cVar8;
  char cVar9;
  bool bVar10;
  bool bVar11;
  uint16_t uVar12;
  uint16_t uVar13;
  uint uVar14;
  uint uVar15;
  char *pcVar16;
  uint32_t *puVar17;
  far_t far *pfVar18;
  uint32_t *puVar19;
  far_t far *pfVar20;
  char_sheet_t *pcVar21;
  char *pcVar22;
  int iVar23;
  int iVar24;
  undefined1 uVar25;
  uint16_t in_CX;
  uint16_t uVar26;
  uint16_t in_DX;
  entity_t *peVar27;
  far_t far *unaff_BP;
  char *unaff_SI;
  char *unaff_DI;
  uint16_t unaff_ES;
  uint32_t packed;
  uint16_t uVar29;
  char *in_stack_00000000;
  agnt_t far *paStack0008;
  char acStack_1b6 [120];
  char acStack_13e [36];
  uint16_t auStack_11a [66];
  uint16_t auStack_96 [24];
  undefined1 auStack_66 [16];
  char acStack_56 [52];
  entity_t *in_stack_0000ffe2;
  uint16_t in_stack_0000ffe4;
  char cVar30;
  uint8_t uVar31;
  undefined1 uVar32;
  undefined1 uVar33;
  undefined1 uVar34;
  char in_stack_0000fff3;
  byte bVar35;
  undefined1 *puVar36;
  undefined1 uVar37;
  byte bVar38;
  undefined1 destXHi;
  
  uVar13 = CONCAT11((char)((uint)in_DX >> 8),(byte)index);
  uVar14 = index & 0xff;
  if (6 < uVar14) {
    return (char *)0x0;
  }
  peVar27 = (entity_t *)(uVar14 * 2);
  cVar9 = (char)_SS;
  bVar38 = (byte)((uint)_SS >> 8);
  switch(uVar14) {
  case 0:
    cVar9 = in(uVar13);
    *unaff_DI = cVar9;
    midpakAd.ofs = (uint16_t)stshStoreFile_2(unaff_BP,in_stack_00000000,index);
    midpakAd.seg = uVar13;
    cmidpakComOfs =(uint16_t)( stshStoreFile_2((far_t *)"cmidpak.com",(char *)MK_FP(0x2410, 0x1),index));
    cmidpakComSeg = uVar13;
    ibmsndComOfs =(uint16_t)( stshStoreFile_2((far_t *)"ibmsnd.com",(char *)MK_FP(0x2410, 0x1),index));
    ibmsndComSeg = uVar13;
    sblasterComOfs =(uint16_t)( stshStoreFile_2((far_t *)"sblaster.com",(char *)MK_FP(0x2410, 0x1),index));
    audioPlaceholder2.seg = 0;
    audioPlaceholder2.ofs = 0;
    sblasterComSeg = uVar13;
    fibmbakComOfs =(uint16_t)( stshStoreFile_2((far_t *)"fibmbak.com",(char *)MK_FP(0x2410, 0x1),index));
    fibmbakComSeg = uVar13;
    pfVar20 = stshStoreFile_2((far_t *)"sbpro.com",(char *)MK_FP(0x2410, 0x1),index);
    sbproComOfs =(uint16_t)( pfVar20);
    sbproComSeg = uVar13;
    sbproComCopyOfs =(uint16_t)( pfVar20);
    sbproComCopySeg = uVar13;
    paudioComOfs =(uint16_t)( stshStoreFile_2((far_t *)"paudio.com",(char *)MK_FP(0x2410, 0x1),index));
    sblasterComCopySeg = sblasterComSeg;
    sblasterComCopyOfs = sblasterComOfs;
    pfVar18 = sblasterComOfs;
    paudioComSeg =(uint16_t)( pfVar20);
    adlibComOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlib.com",(char *)MK_FP(0x2410, 0x1),index));
    adlibComSeg =(uint16_t)( pfVar18);
    adlibgComOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlibg.com",(char *)MK_FP(0x2410, 0x1),index));
    audioPlaceholder3.seg = 0;
    audioPlaceholder3.ofs = 0;
    musDriver0Seg = 0;
    musDriver0Ofs = 0;
    adlibgComSeg =(uint16_t)( pfVar18);
    sbfmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"sbfm.adv",(char *)MK_FP(0x2410, 0x1),index));
    audioPlaceholder0.seg = 0;
    audioPlaceholder0.ofs = 0;
    audioPlaceholder1.seg = 0;
    audioPlaceholder1.ofs = 0;
    sbfmAdvSeg =(uint16_t)( pfVar18);
    sbp2fmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"sbp2fm.adv",(char *)MK_FP(0x2410, 0x1),index));
    sbp2fmAdvSeg =(uint16_t)( pfVar18);
    sbp1fmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"sbp1fm.adv",(char *)MK_FP(0x2410, 0x1),index));
    sbp1fmAdvSeg =(uint16_t)( pfVar18);
    pasfmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"pasfm.adv",(char *)MK_FP(0x2410, 0x1),index));
    pasfmAdvSeg =(uint16_t)( pfVar18);
    pasoplAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"pasopl.adv",(char *)MK_FP(0x2410, 0x1),index));
    pasoplAdvSeg =(uint16_t)( pfVar18);
    adlibAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlib.adv",(char *)MK_FP(0x2410, 0x1),index));
    adlibAdvSeg =(uint16_t)( pfVar18);
    adlibgAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlibg.adv",(char *)MK_FP(0x2410, 0x1),index));
    adlibgAdvSeg =(uint16_t)( pfVar18);
    mt32mpuAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"mt32mpu.adv",(char *)MK_FP(0x2410, 0x1),index));
    mt32mpuAdvSeg =(uint16_t)( pfVar18);
    return (char *)mt32mpuAdvOfs;
  case 1:
    iVar23 = ovr_ovc23_findClearColumn(GfxRndSeed);
    if (iVar23 < 0) {
      ovr_drawTextAt((char *)"You cannot attract units to this location.",0,0);
      pcVar16 = (char *)0x26510;
      ((uint8_t *)menuItemRow)[index] = 0x0;
    }
    else {
      uVar31 = 0x6f;
      uVar25 = 0x23;
      bVar38 = (byte)index;
      callResultTemp = sub_OVC21_manage_c_24B1();
      if (callResultTemp < CONCAT11(uVar25,uVar31)) {
        uVar31 = (uint8_t)callResultTemp;
        uVar25 = (undefined1)(callResultTemp >> 8);
        ((uint8_t *)menuItemRow)[index] = uVar31;
      }
      uVar7 = *(uint32_t *)((uint)bVar38 << 2);
      cVar9 = *(char *)((int)uVar7 + 0x2f);
      pcVar16 = (char *)CONCAT11((char)(((uint)bVar38 << 2) >> 8),cVar9);
      if (cVar9 != -1) {
        ovr_ovc41_pluralSuffix(CONCAT11(uVar25,uVar31));
        pcVar16 = ovr_stsprintf(acStack_56,(char *)CONCAT13(9,CONCAT12(0x21,_SS)));
        ovr_drawTextAt(pcVar16,0,0);
      }
    }
    return pcVar16;
  case 2:
    ((int far *)StshHandles)[(int)unaff_SI] = uVar14;
    *(uint16_t *)((int)(long far *)StshPtrs + (int)unaff_SI * 4 + 2) = 0;
    *(uint16_t *)((long far *)StshPtrs + (int)unaff_SI) = 0;
    return unaff_SI;
  case 3:
    for (iVar23 = 0; iVar23 < (int)(uint)GLeaderCount; iVar23 = iVar23 + 1) {
      if ((((GLeaderSheets[iVar23])->active != '\0') &&
          (uVar13 = 0x2410, (GLeaderSheets[iVar23])->x == GfxRndSeed)) &&
         (uVar13 = 0x2410, (GLeaderSheets[iVar23])->y == GfxRndSeed2))
      {
        if (GCharLevelsInc != '\0') {
          uVar12 = (uint16_t)SEG_OF(GLeaderSheets[iVar23]);
          iVar24 = (int)far_ofs_u32(GLeaderSheets[iVar23]);
          puVar3 = (uint *)(iVar24 + 0x56);
          uVar14 = *puVar3;
          *puVar3 = *puVar3 + 10000;
          piVar4 = (int *)(iVar24 + 0x58);
          *piVar4 = *piVar4 + (uint)(0xd8ef < uVar14);
          GCharLevelsInc = '\0';
        }
        pfVar18 = manage_settlementScreen((byte)iVar23);
        ovr_stats_openCastlePanel();
        ovr_ovc41_usesGMenuItem();
        return (char *)pfVar18;
      }
    }
    ovr_stats_drawStatsPanel();
    if (PartyCount == 0) {
      pcVar16 = (char *)(uint)CurPartySlot;
      if (PartySize <= CurPartySlot) {
        ovr_ovc41_usesGMenuItem();
        return pcVar16;
      }
      pcVar21 = chargen();
      uVar33 = (undefined1)uVar13;
      uVar34 = (undefined1)(uVar13 >> 8);
      uVar25 = SUB21(pcVar21,0);
      uVar32 = (undefined1)((uint)pcVar21 >> 8);
      pcVar16 = (char *)((uint)pcVar21 | uVar13);
      if (pcVar16 == (char *)0x0) {
        ovr_stats_openCastlePanel();
        ovr_ovc41_usesGMenuItem();
        return pcVar16;
      }
      iVar23 = 0;
      while ((iVar23 < (int)(uint)GLeaderCount &&
             ((GLeaderSheets[iVar23])->statMask != '\0'))) {
        iVar23 = iVar23 + 1;
      }
      if (iVar23 < (int)(uint)GLeaderCount) {
        PartyCount = (char)iVar23 + 1;
        uVar12 = *(uint16_t *)((uint)PartyCount * 4 + -2);
        (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uVar12;
        handle.ofs = *(uint16_t *)((uint)PartyCount * 4 + -4);
        (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)uVar12 >> 8);
        ovr_stshFree(handle);
      }
      else {
        if (0x4f < GLeaderCount) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x1d);
        }
        PartyCount = GLeaderCount + 1;
        GLeaderCount = PartyCount;
      }
      pbVar5 = (byte *)(CONCAT11(uVar32,uVar25) + 0x28);
      *pbVar5 = *pbVar5 | 0x40;
      *(char *)(CONCAT11(uVar32,uVar25) + 0x51) = PartyCount - 1;
      uVar14 = (uint)PartyCount;
      *(uint16_t *)(uVar14 * 4 + -2) = CONCAT11(uVar34,uVar33);
      *(uint16_t *)(uVar14 * 4 + -4) = CONCAT11(uVar32,uVar25);
      if (CurPartySlot == 0) {
        *(undefined1 *)(CONCAT11(uVar32,uVar25) + 0x86) = 1;
      }
      CurPartySlot = CurPartySlot + 1;
    }
    else {
      manage_openTalkWindow();
      uVar12 = *(uint16_t *)((uint)PartyCount * 4 + -2);
      placeOfs = *(uint16_t *)((uint)PartyCount * 4 + -4);
      uVar33 = (undefined1)uVar12;
      uVar34 = (undefined1)((uint)uVar12 >> 8);
      uVar25 = (undefined1)placeOfs;
      uVar32 = (undefined1)((uint)placeOfs >> 8);
      manage_usesLitoa10((char_sheet_t *)CONCAT13(uVar34,CONCAT12(uVar33,placeOfs)));
    }
    pcVar16 = ovr_fmVsprintf("Place %s here.",
                             (char *)CONCAT13(uVar34,CONCAT12(uVar33,CONCAT11(uVar32,uVar25))));
    ovr_drawString(pcVar16,0,0);
    (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = cVar9;
    entries_00.ofs = (uint16_t)&stk_fff2;
    (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = bVar38;
    pcVar16 = ovr_uiInputText(entries_00,2,0,0,0);
    pcVar22 = (char *)((uint)pcVar16 & 0xff);
    if (((uint)pcVar16 & 0xff) == 1) {
      pcVar22 = (char *)(PartyCount - 1);
      if (CurPartySlot == 1) {
        ovr_ovc18_checkFortressPlacement('\x02');
      }
      else {
        ovr_ovc18_checkFortressPlacement('\x01');
      }
      ovr_ovc41_usesGMenuItem();
    }
    else {
      ovr_stats_openCastlePanel();
      ovr_ovc41_usesGMenuItem();
    }
    return pcVar22;
  case 5:
    puVar17 = ovr_mkp((uint32_t *)unaff_BP,(uint16_t)(char *)in_stack_00000000,
                      (uint16_t)((ulong)in_stack_00000000 >> 0x10));
    index = (uint16_t)CONCAT22(uVar13,puVar17);   /* hand fix: 16-bit slot keeps the offset */
    if ((char)*(uint8_t *)(uint)index == '\0') {   /* hand fix: deref the offset */
      packed = CONCAT22((int)((ulong)in_stack_00000000 >> 0x10),*(uint16_t *)((int)puVar17 + 7));
      uVar26 = uVar13;
      pfVar18 = fmMalloc((far_t *)*(uint16_t *)((int)puVar17 + 5),packed);
      uVar25 = SUB21(pfVar18,0);
      uVar32 = (undefined1)((uint)pfVar18 >> 8);
      if (pfVar18 == (far_t far *)0x0 && uVar26 == 0) {
        puVar17 = (uint32_t *)0x0;
      }
      else {
        uVar29 = (uint16_t)(packed >> 0x10);
        if (*(int *)((int)puVar17 + 0x11) == 0 && *(int *)((int)puVar17 + 0x13) == 0) {
          stshSeek(StshStrongDatHnd,
                   CONCAT22(*(uint16_t *)((int)puVar17 + 3),*(uint16_t *)((int)puVar17 + 1)));
          uVar33 = 0xfd;
          uVar34 = 0x83;
          stshRead();
          packed = CONCAT22(uVar29,*(uint16_t *)((int)puVar17 + 7));
          pfVar18 = ovr_heapMalloc((far_t far *)*(uint16_t *)((int)puVar17 + 5),packed);
          uVar29 = (uint16_t)(packed >> 0x10);
          *(uint16_t *)((int)puVar17 + 0x13) = uVar26;
          *(uint16_t *)((int)puVar17 + 0x11) =(uint16_t)( pfVar18);
          if (*(int *)((int)puVar17 + 0x11) == 0 && *(int *)((int)puVar17 + 0x13) == 0) {
            bVar10 = false;
          }
          else {
            memcpy((char *)CONCAT13((char)((uint)*(uint16_t *)((int)puVar17 + 0x13) >> 8),
                                    CONCAT12((char)*(uint16_t *)((int)puVar17 + 0x13),
                                             *(uint16_t *)((int)puVar17 + 0x11))),
                   (char *)CONCAT22(CONCAT11(uVar34,uVar33),(char *)CONCAT11(uVar32,uVar25)),
                   *(word *)((int)puVar17 + 5));
            bVar10 = true;
          }
        }
        else {
          memcpy((char *)CONCAT13((char)(uVar26 >> 8),CONCAT12((char)uVar26,pfVar18)),
                 (char *)CONCAT22(*(uint16_t *)((int)puVar17 + 0x13),
                                  (char *)*(uint16_t *)((int)puVar17 + 0x11)),
                 *(word *)((int)puVar17 + 5));
          bVar10 = true;
        }
        if (bVar10) {
          puVar19 = ovr_mkp((uint32_t *)Stsh_2410_47f6.ofs,Stsh_2410_47f6.seg,uVar29);
          if ((uVar26 != uVar13) || (puVar19 != puVar17)) {
            iVar23 = *(int *)((int)puVar17 + 0xf);
            iVar24 = *(int *)((int)puVar17 + 0xd);
            uVar26 = *(uint16_t *)((int)puVar17 + 0xb);
            uVar29 = *(uint16_t *)((int)puVar17 + 9);
            if (uVar29 != 0 || uVar26 != 0) {
              uVar12 = (uint16_t)
                       (CONCAT13((char)(uVar26 >> 8),CONCAT12((char)uVar26,uVar29)) >> 0x10);
              *(int *)(uVar29 + 0xf) = iVar23;
              *(int *)(uVar29 + 0xd) = iVar24;
            }
            if (iVar24 != 0 || iVar23 != 0) {
              uVar12 = (uint16_t)
                       (CONCAT13((char)((uint)iVar23 >> 8),CONCAT12((char)iVar23,iVar24)) >> 0x10);
              *(uint16_t *)(iVar24 + 0xb) = uVar26;
              *(uint16_t *)(iVar24 + 9) = uVar29;
              uVar29 = StshCtPtr2.ofs;
              uVar26 = StshCtPtr2.seg;
            }
            StshCtPtr2.seg = uVar26;
            StshCtPtr2.ofs = uVar29;
            uVar26 = Stsh_2410_47f6.ofs;
            *(uint16_t *)((int)puVar17 + 0xf) = Stsh_2410_47f6.seg;
            *(uint16_t *)((int)puVar17 + 0xd) = uVar26;
            *(uint16_t *)((int)puVar17 + 0xb) = 0;
            *(uint16_t *)((int)puVar17 + 9) = 0;
            *(uint16_t far *)((uint8_t far *)MK_FP(Stsh_2410_47f6.seg, Stsh_2410_47f6.ofs) +  0xb) = uVar13;
            *(uint16_t far *)((uint8_t far *)MK_FP(Stsh_2410_47f6.seg, Stsh_2410_47f6.ofs) +  9) =(uint16_t)( puVar17);
            Stsh_2410_47f6.seg = uVar13;
            Stsh_2410_47f6.ofs = (uint16_t)puVar17;
          }
        }
        puVar17 = (uint32_t *)CONCAT11(uVar32,uVar25);
      }
    }
    return (char *)puVar17;
  case 6:
    goto switchD_4000_e2bf_caseD_6;
  }
  if ((uVar14 == 0) && (manage_openTalkWindow(), in_stack_0000fff3 == '\x02')) {
    if (ScreenMode == '\0') {
      manage_openTalkWindow();
    }
    TextBlitY = 0xc;
    TextBlitX = 0x11;
    if ((byte)index == 0xff) {
      cVar9 = -8;
      cVar30 = 'T';
      uVar14 = ovr_blitLabel((char *)"Total population.");
      *unaff_SI = *unaff_SI + (char)(uVar14 >> 8) + ((undefined1 *)0xfff3 < &stk_fff2);
      ((dos_psp_t *)((entity_t **)&Entities + uVar14))->jft[0] = 0;
      uVar12 = (uint16_t)((ulong)Entities >> 0x10);
      *(undefined1 *)((int)&(Entities)[(int)unaff_SI].base.state + 1) =
           (char)(Entities)[(int)unaff_SI].base.flags32;
      if (unaff_SI + 1 < EntityCount) {
        pcVar16 = (char *)0x1e6;
        ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.",0);
        return pcVar16;
      }
      if ((cVar9 != '\0') || (cVar30 != '\0')) {
        if ((char)((uint)((int)unaff_SI * 0x37) >> 8) == '\0') {
          ovr_stop_audio();
          CurSfxType3 = 0xff;
          ovr_play_sfx(90,0,0);
        }
        else if (cVar30 == '\0') {
          if (cVar9 != '\0') {
            ovr_play_sfx(37,0,0);
          }
        }
        else {
          ovr_play_sfx(35,0,0);
        }
      }
      GGameState = 0x3d;
      pcVar16 = (char *)0x26510;
      if (DebugVerbose != false) {
        pcVar16 = (char *)0x26510;
        printf("%d \r");
      }
      ovr_OVC23_55fe_29a2_entry();
      return pcVar16;
    }
    ovr_ovc45_compute9(acStack_1b6);
    SUB_5b66_1d94();
    pcVar16 = ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x55,CONCAT12(10,_SS)));
    ovr_blitLabel(pcVar16);
    TextBlitY = TextBlitY + 0xc;
    iVar23 = ovr_font_textWidth((char *)"UNITS",0,0,0,0);
    TextBlitX = 0x89 - iVar23;
    ovr_blitLabel((char *)"UNITS");
    iVar23 = ovr_font_textWidth((char *)"POPULATION",0,0,0,0);
    uVar13 = 0xd4 - iVar23;
    cVar30 = '\x10';
    bVar35 = 0x24;
    TextBlitX = uVar13;
    ovr_blitLabel((char *)"POPULATION");
    iVar23 = 0;
    while( true ) {
      TextBlitY = TextBlitY + 0xc;
      cVar8 = (char)in_CX;
      if ((int)(uint)bVar35 <= iVar23) break;
      TextBlitX = 0x11;
      if ((iVar23 < 5) || (cVar30 == '\0')) {
        ovr_blitLabel((char *)auStack_96[iVar23 * 2]);
      }
      else {
        uVar7 = *(uint32_t *)((index & 0xff) << 2);
        ovr_blitLabel((char *)auStack_11a[iVar23 * 2 + (uint)*(byte *)((int)uVar7 + 0x2f) * 8]);
      }
      ovc27_textCharmed();
      ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x4c,CONCAT12(0xd1,_SS)));
      iVar24 = ovr_font_textWidth(acStack_13e,0,0,0,0);
      TextBlitX = 0x89 - iVar24;
      ovr_blitLabel(acStack_13e);
      ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x4c,CONCAT12(0xd1,_SS)));
      iVar24 = ovr_font_textWidth(acStack_13e,0,0,0,0);
      uVar13 = 0xd4 - iVar24;
      TextBlitX = uVar13;
      cVar30 = cVar9;
      bVar35 = bVar38;
      ovr_blitLabel(acStack_13e);
      iVar23 = iVar23 + 1;
    }
    CurSfxType3 = 0x3c;
    puVar36 = &stk_fff2;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = cVar9;
    entries.ofs = (uint16_t)auStack_66;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = bVar38;
    uVar12 = ovr_ovc28_usesUiInputText(entries,0,0,0,0,0);
    cVar9 = (char)uVar12;
    keyboardInputMode = 0;
    if (((cVar9 != '\0') && (cVar9 != '\x01')) && (cVar9 != -2)) {
      (&stk_bac4)[(int)unaff_DI] = (&stk_bac4)[(int)unaff_DI] + cVar8;
      iVar24 = 0x2410;
      do {
        bVar38 = *(byte *)(iVar24 * uVar13 + 0x21);
        uVar25 = (undefined1)(iVar24 * uVar13 >> 8);
        iVar24 = iVar23;
        if (Agnts[iVar23].strengthMax < bVar38) {
          bVar38 = Agnts[iVar23].strengthMax;
          uVar25 = (undefined1)((uint)(iVar23 * 0x34) >> 8);
          Agnts[iVar23].strength = bVar38;
        }
        do {
          iVar24 = iVar24 + 1;
          if ((int)(uint)AgntCount <= iVar24) {
            iVar23 = ovr_audio_panFromX(paStack0008,0);
            uVar25 = (undefined1)((uint)iVar23 >> 8);
            ovr_play_sfxU(0x1c,0,0,0,0);
            return (char *)CONCAT11(uVar25,1);
          }
        } while (Agnts[iVar24].owner != paStack0008->owner);
        if ((byte)puVar36[0x32] < Agnts[iVar24].strengthMax) {
          Agnts[iVar24].strengthMax = puVar36[0x32];
        }
        uVar13 = 0x34;
        iVar23 = iVar24;
      } while( true );
    }
    if (cVar9 == -2) {
      Cancelled = 1;
    }
    return (char *)0x26510;
  }
  do {
    (in_stack_0000ffe2->base).target =
         (byte)((int)(uint)*(byte *)((int)&(in_stack_0000ffe2->base).owner +
                                    ((int)(uint)(peVar27->base).faction >> 2)) >>
               (((in_stack_0000ffe2->base).faction & 3) << 1)) & 3;
    cVar9 = func_0x0004f32d();
    if (cVar9 == '\0') {
      (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x =
           (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x +
           (int)*(char *)((in_stack_0000ffe2->base).target + 0x885);
      puVar1 = &(in_stack_0000ffe2->base).y;
      *puVar1 = *puVar1 + (int)*(char *)((in_stack_0000ffe2->base).target + 0x889);
      puVar2 = &(in_stack_0000ffe2->base).faction;
      *puVar2 = *puVar2 + 0x1;
    }
    else {
      (in_stack_0000ffe2->base).faction = 0x0;
      *(undefined1 *)&(in_stack_0000ffe2->base).state = 0;
    }
L_attact_3f0b_1082_1477:
    uVar31 = 0x1;
    uVar14 = ovr_alignUp4((in_stack_0000ffe2->base).destX,0,0);
    uVar37 = (undefined1)uVar14;
    destXHi = (undefined1)(uVar14 >> 8);
    uVar13 = (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x;
    uVar33 = (undefined1)uVar13;
    uVar34 = (undefined1)(uVar13 >> 8);
    uVar25 = 0x79;
    uVar32 = 0x23;
    uVar15 = ovr_alignUp4(uVar13,0,0);
    uVar14 = CONCAT11(uVar34,uVar33);
    if ((CONCAT11(destXHi,uVar37) == uVar15) &&
       (uVar14 = CONCAT11(uVar34,uVar33),
       (in_stack_0000ffe2->base).destY == (in_stack_0000ffe2->base).y)) {
      (in_stack_0000ffe2->base).destX = 0;
      (in_stack_0000ffe2->base).destY = 0;
      if (*(char *)((int)&(in_stack_0000ffe2->base).entity + 3) == -1) {
        cVar9 = -1;
      }
      else {
        uVar7 = *(uint32_t *)((uint)*(byte *)((int)&(in_stack_0000ffe2->base).entity + 3) << 2);
        cVar9 = *(char *)((int)uVar7 + 0x89);
      }
      uVar14 = CONCAT11(uVar34,uVar33);
      if (cVar9 != -1) {
        for (uVar15 = 0; uVar14 = CONCAT11(uVar34,uVar33), uVar15 < SquareRecCount;
            uVar15 = uVar15 + 1) {
          uVar14 = ovr_alignUp4(*(int *)(uVar15 * 0x13),0,0);
          bVar38 = (byte)uVar14;
          uVar37 = (undefined1)(uVar14 >> 8);
          uVar13 = (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x;
          uVar33 = (undefined1)uVar13;
          uVar34 = (undefined1)(uVar13 >> 8);
          uVar25 = 0x79;
          uVar32 = 0x23;
          uVar14 = ovr_alignUp4(uVar13,0,0);
          if ((CONCAT11(uVar37,bVar38) == uVar14) &&
             (*(uint16_t *)((uint8_t *)&SquareRecs[uVar15] + 2) == (in_stack_0000ffe2->base).y)) {
            uVar14 = uVar15 * 0x13 + (uint)bVar38 + 0xe;
            uVar25 = 0x79;
            uVar32 = 0x23;
            func_0x0004f930();
            if (*(uint16_t *)((uint8_t *)&SquareRecs[uVar15] + 2) == GfxRndSeed2) {
              uVar14 = ovr_alignUp4(*(int *)(uVar15 * 0x13),0,0);
              bVar38 = (byte)uVar14;
              uVar37 = (undefined1)(uVar14 >> 8);
              uVar33 = (undefined1)GfxRndSeed;
              uVar34 = (undefined1)((uint)GfxRndSeed >> 8);
              uVar25 = 0x79;
              uVar32 = 0x23;
              uVar15 = ovr_alignUp4(GfxRndSeed,0,0);
              uVar14 = CONCAT11(uVar34,uVar33);
              if (CONCAT11(uVar37,bVar38) == uVar15) {
                (&stk_fff2)[bVar38] = 1;
                uVar14 = CONCAT11(uVar34,uVar33);
              }
            }
            break;
          }
        }
      }
    }
    if (AgntFlag1 != false) {
      if ((((((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x < GfxRndSeed - 2U)
          || (GfxRndSeed + 1U <
              (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x)) ||
         ((in_stack_0000ffe2->base).y != GfxRndSeed2)) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      if (((uVar14 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uVar14)) ||
         (GfxRndSeed2 != CONCAT11(uVar32,uVar25))) {
        bVar11 = false;
      }
      else {
        bVar11 = true;
      }
      if (bVar11 || bVar10) {
        if (bVar11) {
          if (bVar10) {
            cVar9 = manage_usesLitoa103();
            while ((cVar9 != '\0' &&
                   (pcVar16 = ovr_ovc15_textArena((int)unaff_DI,0,0), ((uint)pcVar16 & 0xff) != 0))) {
              cVar9 = cVar9 + -1;
            }
          }
          else {
            cVar9 = (char)((ulong)((in_stack_0000ffe2->base).animFrame + 0xf) / 0x10);
            while (cVar30 = cVar9 + -1, cVar9 != '\0') {
              ovr_agnt_usesAgntCount6(Entities + (int)unaff_DI,0);
              cVar9 = cVar30;
            }
          }
        }
        else {
          ovr_ovc15_clearVisited();
          cVar9 = (char)((ulong)((in_stack_0000ffe2->base).animFrame + 0xf) / 0x10);
          while (cVar30 = cVar9 + -1, cVar9 != '\0') {
            ovr_ovc15_textArena((int)unaff_DI,0,0);
            cVar9 = cVar30;
          }
        }
      }
    }
    do {
      unaff_DI = unaff_DI + 1;
      if (EntityCount <= unaff_DI) {
        GGameState = 0x3c;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        func_0x0004fcda();
        GGameState = 0x3d;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        ovr_OVC23_55fe_29a2_entry();
        GGameState = 0xc;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        ovr_ovc24_removeOtherEntities(&stk_ffe9);
        GGameState = 0x1f;
        if (uVar31 != 0x0) {
          ovr_constr_usesBlitRect();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (uVar14 = 0; (int)uVar14 < 5; uVar14 = uVar14 + 1) {
          if ((&stk_fff2)[uVar14] != '\0') {
            ovr_ovc41_usesMiceBlitRect(uVar14);
          }
        }
        GGameState = 0xd;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        ovr_ovc24_checkStrongholds();
        GGameState = 0xe;
        mapDirty = 1;
        return (char *)0x26510;
      }
      peVar27 = Entities + (int)unaff_DI;
      unaff_ES = DAT_2000_d190;
      uVar14 = ovr_alignUp4((peVar27->base).destX,0,0);
      uVar25 = (undefined1)uVar14;
      uVar32 = (undefined1)(uVar14 >> 8);
      uVar14 = ovr_alignUp4((((entity_t *)CONCAT22(unaff_ES,peVar27))->base).x,0,0);
      if ((CONCAT11(uVar32,uVar25) == uVar14) && ((peVar27->base).destY == (peVar27->base).y)) {
        manage_usesCurSfxType32();
      }
    } while (((peVar27->base).destX == 0 && (peVar27->base).destY == 0) ||
            (*(char *)((int)&(peVar27->base).entity + 1) != '\0'));
    in_stack_0000ffe2 = peVar27;
    in_stack_0000ffe4 = unaff_ES;
  } while ((peVar27->base).faction < (byte)(peVar27->base).state);
  uVar12 = ovr_ovc07_signum((peVar27->base).destX -
                            (((entity_t *)CONCAT22(unaff_ES,peVar27))->base).x);
  cVar30 = (char)uVar12;
  uVar32 = (undefined1)((uint)uVar12 >> 8);
  uVar12 = ovr_ovc07_signum((peVar27->base).destY - (peVar27->base).y);
  cVar9 = (char)uVar12;
  uVar25 = (undefined1)((uint)uVar12 >> 8);
  in_stack_0000ffe2 = peVar27;
  in_stack_0000ffe4 = unaff_ES;
  if (((CONCAT11(uVar32,cVar30) == 0) ||
      (uVar13 = ovr_randBelow(2,0), in_stack_0000ffe2 = peVar27, in_stack_0000ffe4 = unaff_ES,
      (char)uVar13 == '\0')) ||
     (cVar8 = sub_OVC21_manage_c_23C2(), in_stack_0000ffe2 = peVar27, in_stack_0000ffe4 = unaff_ES,
     cVar8 != '\0')) {
    if ((CONCAT11(uVar25,cVar9) == 0) || (cVar8 = sub_OVC21_manage_c_23C2(), cVar8 != '\0')) {
      if ((CONCAT11(uVar32,cVar30) == 0) || (cVar9 = sub_OVC21_manage_c_23C2(), cVar9 != '\0')) {
        uVar14 = ovr_ovc26_usesStExit((int)unaff_DI);
        if ((char)uVar14 == '\0') {
          uVar14 = ovr_ovc26_usesRandBelow((int)unaff_DI,(uint16_t)&stk_ffe9);
          if ((uVar14 & 0xff) == 0) {
            peVar27 = (entity_t *)((uint)(in_stack_0000ffe2->base).gindex * 0x95);
            uVar13 = 0x195d;
switchD_4000_e2bf_caseD_6:
            if (peVar27[0xb4].base.teamCode == 0x0) {
              manage_usesCurSfxType32();
            }
          }
        }
        else {
          (in_stack_0000ffe2->base).target =
               (byte)((int)(uint)*(byte *)((int)&(in_stack_0000ffe2->base).owner +
                                          ((int)(uint)(in_stack_0000ffe2->base).faction >> 2)) >>
                     (((in_stack_0000ffe2->base).faction & 3) << 1)) & 3;
          cVar9 = func_0x0004f32d();
          if (cVar9 == '\0') {
            (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x =
                 (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x +
                 (int)*(char *)((in_stack_0000ffe2->base).target + 0x885);
            puVar1 = &(in_stack_0000ffe2->base).y;
            *puVar1 = *puVar1 + (int)*(char *)((in_stack_0000ffe2->base).target + 0x889);
            puVar2 = &(in_stack_0000ffe2->base).faction;
            *puVar2 = *puVar2 + 0x1;
          }
        }
      }
      else {
        (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x =
             (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x +
             CONCAT11(uVar32,cVar30);
        (in_stack_0000ffe2->base).target = 0x2 - cVar30;
      }
    }
    else {
      puVar1 = &(in_stack_0000ffe2->base).y;
      *puVar1 = *puVar1 + CONCAT11(uVar25,cVar9);
      (in_stack_0000ffe2->base).target = cVar9 + 0x1;
    }
  }
  else {
    (((entity_t *)CONCAT22(unaff_ES,peVar27))->base).x =
         (((entity_t *)CONCAT22(unaff_ES,peVar27))->base).x + CONCAT11(uVar32,cVar30);
    (peVar27->base).target = 0x2 - cVar30;
  }
  goto L_attact_3f0b_1082_1477;
}


/* 4d05:1296 */

char_sheet_t * __cdecl16far chargen(void)

{
  undefined1 stk_ff61;   /* stack slot ff61 */
  uint16_t descWord;
  far_t entries;
  far_t entries_00;
  far_t dst;
  far_t handle;
  far_t handle_00;
  bool genderPicked;
  char *textInput;
  char *switchVal;
  char *statusText;
  int entryPos;
  int nameOfs;
  uint dlgResult;
  uint in_DX;
  uint16_t widths;
  int entryIdx;
  char itemHotkeys [11];
  uint8_t menuItems;
  uint16_t itemSegs [21];
  static char msg[64];   /* DGROUP-backed formatting buffer */
  char_sheet_t *sheet;
  uint sheetSeg;
  int statIdx;
  uint choice;
  char *inputText;
  uint16_t widSeg;
  uint8_t keepDiscard;
  
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)_SS;
  dst.ofs = (uint16_t)&keepDiscard;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)((uint)_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x24104a16)),dst,8);
  ovr_fmFreeAudio(1);
  ovr_ovc13_usesBlitRect();
  sheet = ovr_stshAlloc(0xae);
  sheetSeg = in_DX;
  do {
    while( true ) {
      _fmemset(MK_FP(sheetSeg, (uint16_t)sheet), 0, 0xae);
      sheet->charIndex = 0xff;
      while( true ) {
        if (TimerSeed.lo == 0 && TimerSeed.hi == 0) {
          TimerSeed.hi = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
          TimerSeed.lo = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
        }
        srand8(CONCAT13((char)(TimerSeed.hi >> 8),CONCAT12((char)TimerSeed.hi,TimerSeed.lo)));
        manage_openTalkWindow();
        manage_rollStats(sheet,(char)sheetSeg);
        manage_usesLitoa10((char_sheet_t *)
                           CONCAT13((char)(sheetSeg >> 8),CONCAT12((char)sheetSeg,sheet)));
        itemSegs[0] = 0x2410;
        menuItems = 0x4fce;
        itemHotkeys[0] = '\0';
        itemSegs[2] = 0;
        itemSegs[1] = 0;
        entryPos = 1;
        for (statIdx = 0; entryIdx = entryPos + 1, statIdx < 4; statIdx = statIdx + 1) {
          itemHotkeys[entryPos] = (char)statIdx + '\x02';
          descWord = *(uint16_t *)(&GUnitDescriptions[statIdx]);
          itemSegs[entryIdx * 2] = *(uint16_t *)((uint8_t *)&GUnitDescriptions[statIdx] + 2);
          *(uint16_t *)(&menuItems + entryIdx * 4) = descWord;
          entryPos = entryIdx;
        }
        itemHotkeys[entryPos] = '\x06';
        if (sheet->stats[4] < 9) {
          itemSegs[entryIdx * 2] = 0;
          (&menuItems + entryIdx * 4)[0] = 0x0;
          (&menuItems + entryIdx * 4)[1] = 0x0;
        }
        else {
          itemSegs[entryIdx * 2] = GUnitDescriptions[4].seg;
          *(uint16_t *)(&menuItems + entryIdx * 4) = GUnitDescriptions[4].ofs;
        }
        entryIdx = entryPos + 2;
        itemHotkeys[entryPos + 1] = '\a';
        if (sheet->stats[1] < 9) {
          itemSegs[entryIdx * 2] = 0;
          (&menuItems + entryIdx * 4)[0] = 0x0;
          (&menuItems + entryIdx * 4)[1] = 0x0;
        }
        else {
          itemSegs[entryIdx * 2] = GUnitDescriptions[5].seg;
          *(uint16_t *)(&menuItems + entryIdx * 4) = GUnitDescriptions[5].ofs;
        }
        entryIdx = entryPos + 3;
        itemHotkeys[entryPos + 2] = '\b';
        if ((sheet->stats[4] < 9) || (sheet->stats[3] < 9)) {
          itemSegs[entryIdx * 2] = 0;
          (&menuItems + entryIdx * 4)[0] = 0x0;
          (&menuItems + entryIdx * 4)[1] = 0x0;
        }
        else {
          itemSegs[entryIdx * 2] = GUnitDescriptions[6].seg;
          *(uint16_t *)(&menuItems + entryIdx * 4) = GUnitDescriptions[6].ofs;
        }
        ovr_drawString((char *)"Reroll ability scores, or select the character\'s class.",0x2410,
                       0x10);
        entries.seg = (uint16_t)_SS;
        entries.ofs = (uint16_t)&menuItems;
        textInput = ovr_uiInputText(entries,9,far_from_u32((uint32_t)(0x0)),0x0,0);
        choice = (uint)textInput & 0xff;
        if (choice != 0) {
          choice = (uint)(char)(&stk_ff61)[choice];
        }
        if (choice == 0) goto L_chargen_17B2;
        if (choice != 1) break;
        TimerSeed.hi = 0;
        TimerSeed.lo = 0;
      }
      choice = choice - 1;
      if (Difficulty < 2) {
        sheet->flags5d = sheet->flags5d | 4;
      }
      else {
        sheet->flags5d = sheet->flags5d | 6;
      }
      sheet->cls = (char)choice - 1;
      switchVal = chargen_switch(CONCAT11(0x24,sheet->cls));
      sheet->classStr = (byte)switchVal;
      sheet->race = 6;
      nameOfs = (uint)sheet->cls * 0x94 + (uint)sheet->race * 4;
      widths = *(uint16_t *)(nameOfs + -4);
      (sheet->name).seg = *(uint16_t *)(nameOfs + -2);
      (&sheet->name)->ofs = widths;
      sheet->statMask = sheet->statMask | 8;
      sheet->statMask = sheet->statMask | 1;
      if (Difficulty == 1) {
        *(uint16_t *)((int)&sheet->gold + 2) = 0;
        *(uint16_t *)&sheet->gold = 500;
      }
      else if (Difficulty == 2) {
        *(uint16_t *)((int)&sheet->gold + 2) = 0;
        *(uint16_t *)&sheet->gold = 300;
      }
      else {
        *(uint16_t *)((int)&sheet->gold + 2) = 0;
        *(uint16_t *)&sheet->gold = 100;
      }
      sheet->buildType[0] = 7;
      sheet->partySlot = 0xff;
      manage_usesLitoa10((char_sheet_t *)
                         CONCAT13((char)(sheetSeg >> 8),CONCAT12((char)sheetSeg,sheet)));
      dlgResult = abilitiesDlg((char_sheet_t *)
                           CONCAT13((char)(sheetSeg >> 8),CONCAT12((char)sheetSeg,sheet)));
      if ((dlgResult & 0xff) == 0) break;
      manage_rollHitPoints
                ((char_sheet_t *)
                 CONCAT13((char)(sheetSeg >> 8),CONCAT12((char)sheetSeg,sheet)));
      while( true ) {
        manage_usesLitoa10((char_sheet_t *)
                           CONCAT13((char)(sheetSeg >> 8),CONCAT12((char)sheetSeg,sheet)));
        dlgResult = alignmentDlg((char_sheet_t *)
                             CONCAT13((char)(sheetSeg >> 8),CONCAT12((char)sheetSeg,sheet)));
        if ((dlgResult & 0xff) == 0) break;
L_chargen_1661:
        manage_openTalkWindow();
        manage_usesLitoa10((char_sheet_t *)
                           CONCAT13((char)(sheetSeg >> 8),CONCAT12((char)sheetSeg,sheet)));
        genderPicked = uiPickGender((char_sheet_t *)
                             CONCAT13((char)(sheetSeg >> 8),CONCAT12((char)sheetSeg,sheet)));
        if (genderPicked) {
          do {
            manage_blitTalkWindow();
            ovr_drawString((char *)"Select the character\'s name.",0x2410,0x10);
            while (inputText = ovr_uiReadString((char *)0x0,0,6,(char *)0x0,0,0), widSeg = widths,
                  inputText == (char *)0x0 && widths == 0) {
              if (inputCancelled != '\0') {
                if (UserWantsExit == '\0') goto L_chargen_1661;
                goto L_chargen_17B2;
              }
              manage_blitTalkWindow();
              ovr_drawString((char *)"Please type your character\'s name. Esc go back.",0x2410,0x10)
              ;
            }
            ovr_drawString((char *)0x28c75,0x2410,0x10);
            __fstrncpy((char *)CONCAT22(sheetSeg,sheet),(char *)CONCAT22(widSeg,inputText),
                       0x27);
            (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)widSeg;
            handle.ofs = (uint16_t)inputText;
            (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)(widSeg >> 8);
            ovr_stshFree(handle);
            statusText = ovr_stsprintf(msg,(char *)CONCAT22(0x505a,_SS),
                                   (char *)CONCAT22(sheet,(char *)0x26510),
                                   (char)sheetSeg);
            ovr_drawString(statusText,widths,(char)widths);
            entries_00.seg = (uint16_t)_SS;
            entries_00.ofs = (uint16_t)&keepDiscard;
            textInput = ovr_uiInputText(entries_00,2,far_from_u32((uint32_t)(0x0)),0x0,0);
            choice = (uint)textInput & 0xff;
            if (choice != 0) {
              if (choice != 2) {
                sheet->statMask = sheet->statMask | 2;
                manage_openTalkWindow();
                manage_usesLitoa10((char_sheet_t *)
                                   CONCAT13((char)(sheetSeg >> 8),
                                            CONCAT12((char)sheetSeg,sheet)));
                TimerSeed.lo = 0;
                TimerSeed.hi = 0;
                return sheet;
              }
              break;
            }
          } while (UserWantsExit == '\0');
          goto L_chargen_17B2;
        }
        if (UserWantsExit != '\0') goto L_chargen_17B2;
      }
      if (UserWantsExit != '\0') goto L_chargen_17B2;
    }
  } while (UserWantsExit == '\0');
L_chargen_17B2:
  (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)sheetSeg;
  handle_00.ofs = (uint16_t)sheet;
  (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)(sheetSeg >> 8);
  ovr_stshFree(handle_00);
  return (char_sheet_t *)0x0;
}



/* 4d05:17c7 */

/* Stops music/agents and opens the settlement screen for a party slot (manage_settlementScreen),
   restoring the menu afterwards. */

void __cdecl16far manage_showSettlementScreen(uint8_t partySlot)

{
  ovr_attact_usesAgntFlag1();
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  CurMusicType = 0xff;
  savedMenuItem = GMenuItem;
  MenuModeSaved = MenuMode;
  TextBlitDstSeg = 0xa000;
  manage_settlementScreen(partySlot);
  if (Cancelled == '\0') {
    ovr_stats_openCastlePanel();
    ovr_ovc41_usesGMenuItem();
  }
  return;
}



/* 4d05:1835 */
void __cdecl16far manage_textHalflingCastle(void)

{
  far_t gfx;
  far_t dst;
  far_t handle;
  char *sayText;
  char *inputText;
  char_sheet_t *widths;
  far_t entries;
  char_sheet_t *newLeader;
  int sheetSeg;
  uint8_t inputBuf;
  uint inputResult;
  int leaderIdx;
  
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)_SS;
  dst.ofs = (uint16_t)&inputBuf;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)(_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x24104a1e)),dst,8);
  gfx.seg = FontHandle.seg;
  gfx.ofs = FontHandle.ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)),0);
  ovr_attact_usesAgntFlag1();
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  CurMusicType = 0xff;
  savedMenuItem = GMenuItem;
  MenuModeSaved = MenuMode;
  TextBlitDstSeg = 0xa000;
  for (leaderIdx = 0; sheetSeg = 0x2410, leaderIdx < (int)(uint)GLeaderCount; leaderIdx = leaderIdx + 1
      ) {
    if ((((GLeaderSheets[leaderIdx])->active != '\0') &&
        ((GLeaderSheets[leaderIdx])->x == GfxRndSeed)) &&
       ((GLeaderSheets[leaderIdx])->y == GfxRndSeed2)) {
      if (GCharLevelsInc != '\0') {
        GLeaderSheets[leaderIdx]->gold = GLeaderSheets[leaderIdx]->gold + 10000;
        GCharLevelsInc = '\0';
      }
      manage_settlementScreen((byte)leaderIdx);
      ovr_stats_openCastlePanel();
      ovr_ovc41_usesGMenuItem();
      return;
    }
  }
  ovr_stats_drawStatsPanel();
  if (PartyCount == 0) {
    if (PartySize <= CurPartySlot) {
      ovr_ovc41_usesGMenuItem();
      return;
    }
    newLeader = chargen();
    if (newLeader == (char_sheet_t *)0x0 && sheetSeg == 0) {
      ovr_stats_openCastlePanel();
      ovr_ovc41_usesGMenuItem();
      return;
    }
    leaderIdx = 0;
    while ((leaderIdx < (int)(uint)GLeaderCount &&
           ((GLeaderSheets[leaderIdx])->statMask != '\0'))) {
      leaderIdx = leaderIdx + 1;
    }
    if (leaderIdx < (int)(uint)GLeaderCount) {
      PartyCount = (byte)leaderIdx + 1;
      handle.ofs = far_ofs_u32(GLeaderSheets[PartyCount - 1]);
      handle.seg = (uint16_t)SEG_OF(GLeaderSheets[PartyCount - 1]);
      ovr_stshFree(handle);
    }
    else {
      if (0x4f < GLeaderCount) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x1d);
      }
      PartyCount = GLeaderCount + 1;
      GLeaderCount = PartyCount;
    }
    newLeader->statMask = newLeader->statMask | 0x40;
    newLeader->charIndex = PartyCount - 1;
    widths = (char_sheet_t *)((char *)0x2627a);
    GLeaderSheets[PartyCount - 1] =
        (char_sheet_t far *)MK_FP((uint16_t)sheetSeg, (uint16_t)newLeader);
    if (CurPartySlot == 0) {
      newLeader->titleIndex = 1;
    }
    CurPartySlot = CurPartySlot + 1;
  }
  else {
    manage_openTalkWindow();
    sheetSeg = (int)SEG_OF(GLeaderSheets[PartyCount - 1]);
    newLeader = (char_sheet_t *)far_ofs_u32(GLeaderSheets[PartyCount - 1]);
    widths = newLeader;
    manage_usesLitoa10((char_sheet_t *)
                       CONCAT13((char)((uint)sheetSeg >> 8),CONCAT12((char)sheetSeg,newLeader)));
  }
  sayText = ovr_fmVsprintf("Place %s here.",
                          (char *)CONCAT13((char)((uint)sheetSeg >> 8),
                                           CONCAT12((char)sheetSeg,newLeader)));
  ovr_drawString(sayText,(uint16_t)widths,(char)widths);
  entries.seg = _SS;
  entries.ofs = (uint16_t)&inputBuf;
  inputText = ovr_uiInputText(entries,2,far_from_u32((uint32_t)(0x0)),0x0,0);
  inputResult = (uint)inputText & 0xff;
  if (inputResult == 1) {
    leaderIdx = PartyCount - 1;
    if (CurPartySlot == 1) {
      ovr_ovc18_checkFortressPlacement('\x02');
    }
    else {
      ovr_ovc18_checkFortressPlacement('\x01');
    }
    ovr_ovc41_usesGMenuItem();
  }
  else {
    ovr_stats_openCastlePanel();
    ovr_ovc41_usesGMenuItem();
  }
  return;
}


/* 4d05:1b1d */

/* Returns the index of the first leader with a non-zero level, or 0xff. */

byte __cdecl16far manage_findFirstLeader(void)

{
  byte bVar1;
  
  bVar1 = 0;
  while( true ) {
    if (GLeaderCount <= bVar1) {
      return 0xff;
    }
    if ((GLeaderSheets[bVar1])->titleIndex != '\0') break;
    bVar1 = bVar1 + 1;
  }
  return bVar1;
}



/* 4d05:1b51 */

/* [R6] touches GLeaderCount */

byte __cdecl16far manage_usesGLeaderCount3(byte partyIndex)

{
  /* Re-derived from 4d05:1b51: scan leader indices from partyIndex, wrapping at
     GLeaderCount, skipping the first leader and partyIndex itself, and return the first
     leader whose sheet byte +0x3d is set and whose +0x3f byte equals the party's own.
     0xff means none.  The original writes only AL (mov al,[bp-2] at 0x40A1A, mov al,0xff
     at 0x40A3A), so the exported CONCAT11 high bytes were stale-AH noise. */
  byte firstLeader;
  byte leaderIdx;
  uint32_t sheetRef;

  firstLeader = manage_findFirstLeader();
  leaderIdx = partyIndex;
  do {
    if ((((leaderIdx < GLeaderCount) && (leaderIdx != firstLeader)) &&
        (leaderIdx != partyIndex)) &&
       (*((char far *)GLeaderSheets[leaderIdx] + 0x3d) != '\0')) {
      sheetRef = (uint32_t)GLeaderSheets[leaderIdx];
      if (*(char *)((int)sheetRef + 0x3f) ==
          *((char far *)GLeaderSheets[partyIndex] + 0x3f)) {
        return leaderIdx;
      }
    }
    leaderIdx = leaderIdx + 1;
    if (GLeaderCount <= leaderIdx) {
      leaderIdx = 0;
    }
  } while (leaderIdx != partyIndex);
  return 0xff;
}



/* 4d05:1bee */
/* DECOMPILATION FAILED: Exception while decompiling 4d05:1bee: Response buffer size exceeded for: st.exe
 */
undefined manage_settlementScreen() { return 0; }

/* 4d05:217a */

/* Long itoa in base 10 */

char * __cdecl16far litoa10(char *buf,long n,uint16_t arg3,uint16_t arg4)

{
  bool bVar1;
  size_t textLen;
  uint16_t len;
  bool bVar3;
  uint32_t digit;
  long dividend;
  long lVar4;
  int in_stack_0000000a;
  
  if ((in_stack_0000000a < 1) && (in_stack_0000000a < 0)) {
    bVar1 = true;
    bVar3 = (*(uint16_t *)((uint8_t *)&(n) + 2)) != 0;
    (*(uint16_t *)((uint8_t *)&(n) + 2)) = -(*(uint16_t *)((uint8_t *)&(n) + 2));
    in_stack_0000000a = -(uint)bVar3 - in_stack_0000000a;
  }
  else {
    bVar1 = false;
  }
  dividend = CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(n) + 2)));
  digit = LMOD_at_(dividend,10);
  *(char *)CONCAT22((uint16_t)n,buf) = (char)digit + '0';
  buf[1] = '\0';
  while (lVar4 = LDIV_at_(dividend,10), lVar4 != 0) {
    textLen = strlen((char *)CONCAT22((uint16_t)n,buf));
    if ((textLen & 3) == 3) {
      textLen = strlen((char *)CONCAT22((uint16_t)n,buf));
      _fmemmove((char far *)MK_FP((uint16_t)n,buf + 1),(char far *)MK_FP((uint16_t)n,buf),len + 1)
      ;
      *(char *)CONCAT22((uint16_t)n,buf) = ',';
    }
    textLen = strlen((char *)CONCAT22((uint16_t)n,buf));
    _fmemmove((char far *)MK_FP((uint16_t)n,buf + 1),(char far *)MK_FP((uint16_t)n,buf),len + 1)
    ;
    dividend = LDIV_at_(dividend,10);
    lVar4 = LMOD_at_(dividend,10);
    *(char *)CONCAT22((uint16_t)n,buf) = (char)lVar4 + '0';
  }
  if (bVar1) {
    textLen = strlen((char *)CONCAT22((uint16_t)n,buf));
    _fmemmove((char far *)MK_FP((uint16_t)n,buf + 1),(char far *)MK_FP((uint16_t)n,buf),len + 1)
    ;
    *(char *)CONCAT22((uint16_t)n,buf) = '-';
  }
  return buf;
}



/* 4d05:22b3 */

/* [R1] forwards to manage_4d05_22cf */

void __cdecl16far manage_4d05_22cf_entry(void)

{
  uint16_t *in_stack_0000000a;
  uint16_t *in_stack_0000000e;
  
  *in_stack_0000000a = 0;
  *in_stack_0000000e = 0;
  if (EntityCount != 0) {
    manage_usesEntities();
    return;
  }
  return;
}



/* 4d05:22cf */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* [R6] touches Entities, GMenuStrings */

void manage_usesEntities(void)

{
  char in_CL;
  int unaff_BP;
  int unaff_SI;
  
  if (in_CL != -1) {
    manage_usesEntities2();
    return;
  }
  if (((AgntGs[(uint)(Entities)[unaff_SI].base.gindex].ai == '\0') &&
      (*(byte *)(unaff_BP + 8) <= (Entities)[unaff_SI].base.level)) &&
     ((Entities)[unaff_SI].base.level <= *(byte *)(unaff_BP + 10))) {
    *(int *)*(uint32_t *)(unaff_BP + 0xc) = *(int *)*(uint32_t *)(unaff_BP + 0xc) + 1;
    *(int *)*(uint32_t *)(unaff_BP + 0x10) =
         *(int *)*(uint32_t *)(unaff_BP + 0x10) +
         (uint)(Entities)[unaff_SI].base.animFrame;
  }
  if (EntityCount <= unaff_SI + 1U) {
    return;
  }
  manage_usesEntities();
  return;
}



/* 4d05:2371 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities, animFrame */

void __cdecl16far manage_usesEntities2(void)

{
  char in_CL;
  int unaff_BP;
  int unaff_SI;
  
  if (((AGNT_FIELD(&(Entities)[unaff_SI], base.entity, 3) == in_CL) &&
      (*(byte *)(unaff_BP + 8) <= (Entities)[unaff_SI].base.level)) &&
     ((Entities)[unaff_SI].base.level <= *(byte *)(unaff_BP + 10))) {
    *(int *)*(uint32_t *)(unaff_BP + 0xc) = *(int *)*(uint32_t *)(unaff_BP + 0xc) + 1;
    *(int *)*(uint32_t *)(unaff_BP + 0x10) =
         *(int *)*(uint32_t *)(unaff_BP + 0x10) +
         (uint)(Entities)[unaff_SI].base.animFrame;
  }
  if (unaff_SI + 1U < EntityCount) {
    manage_usesEntities();
    return;
  }
  return;
}



/* 4d05:23c2 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint16_t __cdecl16far sub_OVC21_manage_c_23C2()

{
  int unaff_BP;
  int unaff_SI;
  bool in_CF;
  bool in_ZF;
  
  if (in_CF || in_ZF) {
    *(int *)*(uint32_t *)(unaff_BP + 0xc) = *(int *)*(uint32_t *)(unaff_BP + 0xc) + 1;
    *(int *)*(uint32_t *)(unaff_BP + 0x10) =
         *(int *)*(uint32_t *)(unaff_BP + 0x10) +
         (uint)(Entities)[unaff_SI].base.animFrame;
  }
  if (unaff_SI + 1U < EntityCount) {
    manage_usesEntities();
    return;
  }
  return;
}



/* 4d05:23fc */

/* [R6] touches GUnitCount, GRecordCount */

int __cdecl16far
manage_usesGUnitCount
          (char partyIndex,char unitType,int *resource1Count,int *resource2Count,int *resource3Count
          ,int *recordCount)

{
  byte bVar1;
  int iVar2;
  uint32_t uVar3;
  int iVar4;
  unit_t *puVar5;
  uint uVar6;
  int *in_stack_00000018;
  int *in_stack_0000001c;
  int *in_stack_00000020;
  int iStack_4;
  
  iStack_4 = 0;
  *resource1Count = 0;
  *resource2Count = 0;
  *resource3Count = 0;
  *recordCount = 0;
  *in_stack_00000018 = 0;
  *in_stack_0000001c = 0;
  *in_stack_00000020 = 0;
  uVar6 = 0xf8;
  while( true ) {
    if (GUnitCount <= uVar6) {
      for (uVar6 = 0; uVar6 < GRecordCount; uVar6 = uVar6 + 1) {
        if ((GRecords[uVar6].party == partyIndex) &&
           (bVar1 = GRecords[uVar6].reserved08, BuildingTypes[bVar1].unitType == unitType))
        {
          *recordCount = *recordCount + 1;
          if (BuildingTypes[bVar1].resource == '\x01') {
            *in_stack_00000018 = *in_stack_00000018 + 1;
          }
          else if (BuildingTypes[bVar1].resource == '\x02') {
            *in_stack_0000001c = *in_stack_0000001c + 1;
          }
          else if (BuildingTypes[bVar1].resource == '\x03') {
            *in_stack_00000020 = *in_stack_00000020 + 1;
          }
        }
      }
      iVar4 = *in_stack_0000001c;
      iVar2 = *in_stack_00000020;
      *resource1Count = *resource1Count - *in_stack_0000001c;
      *resource2Count = *resource2Count - *in_stack_00000020;
      return iStack_4 - (iVar4 + iVar2);
    }
    if (partyIndex != -1) break;
    puVar5 = GUnits;
    if (((puVar5[uVar6].unitType != 0xff) &&
        (uVar3 = *(uint32_t *)((uint)puVar5[uVar6].unitType << 2),
        *(char *)((int)uVar3 + 0x3f) == '\0')) &&
       (bVar1 = (puVar5 + uVar6)->bldType, BuildingTypes[bVar1].unitType == unitType)) {
      iStack_4 = iStack_4 + 1;
      if (BuildingTypes[bVar1].resource == '\x01') {
        *resource1Count = *resource1Count + 1;
      }
      else if (BuildingTypes[bVar1].resource == '\x02') {
        *resource2Count = *resource2Count + 1;
      }
      else if (BuildingTypes[bVar1].resource == '\x03') {
        *resource3Count = *resource3Count + 1;
      }
    }
    uVar6 = uVar6 + 1;
  }
  iVar4 = manage_usesGUnits();
  return iVar4;
}



/* 4d05:24b1 */

/* WARNING: Instruction at (ram,0x0004f503) overlaps instruction at (ram,0x0004f502)
    */

uint16_t __cdecl16far sub_OVC21_manage_c_24B1()

{
  byte bldTypeVal;
  uint32_t unitPtr;
  uint16_t uVar3;
  uint in_AX;
  uint tallyPtr;
  unit_t *puVar5;
  uint unaff_BP;
  uint unaff_SI;
  int unaff_DI;
  uint uVar6;
  
  do {
    tallyPtr = in_AX;
    *(uint *)(tallyPtr + unaff_DI) = unaff_BP;
    if (BuildingTypes[(unaff_BP & 0xff)].unitType == *(char *)(tallyPtr + 8)) {
      *(int *)(tallyPtr - 2) = *(int *)(tallyPtr - 2) + 1;
      if (BuildingTypes[(unaff_BP & 0xff)].resource == '\x01') {
        *(int *)*(uint32_t *)(tallyPtr + 10) = *(int *)*(uint32_t *)(tallyPtr + 10) + 1;
      }
      else if (BuildingTypes[(unaff_BP & 0xff)].resource == '\x02') {
        *(int *)*(uint32_t *)(tallyPtr + 0xe) = *(int *)*(uint32_t *)(tallyPtr + 0xe) + 1;
      }
      else if (BuildingTypes[(unaff_BP & 0xff)].resource == '\x03') {
        *(int *)*(uint32_t *)(tallyPtr + 0x12) = *(int *)*(uint32_t *)(tallyPtr + 0x12) + 1;
      }
    }
    do {
      unaff_SI = unaff_SI + 1;
      if (GUnitCount <= unaff_SI) {
        for (uVar6 = 0; uVar6 < GRecordCount; uVar6 = uVar6 + 1) {
          if ((GRecords[uVar6].party == *(char *)(tallyPtr + 6)) &&
             (bldTypeVal = GRecords[uVar6].reserved08,
             BuildingTypes[bldTypeVal].unitType == *(char *)(tallyPtr + 8))) {
            *(int *)*(uint32_t *)(tallyPtr + 0x16) = *(int *)*(uint32_t *)(tallyPtr + 0x16) + 1;
            if (BuildingTypes[bldTypeVal].resource == '\x01') {
              *(int *)*(uint32_t *)(tallyPtr + 0x1a) = *(int *)*(uint32_t *)(tallyPtr + 0x1a) + 1;
            }
            else if (BuildingTypes[bldTypeVal].resource == '\x02') {
              *(int *)*(uint32_t *)(tallyPtr + 0x1e) = *(int *)*(uint32_t *)(tallyPtr + 0x1e) + 1;
            }
            else if (BuildingTypes[bldTypeVal].resource == '\x03') {
              *(int *)*(uint32_t *)(tallyPtr + 0x22) = *(int *)*(uint32_t *)(tallyPtr + 0x22) + 1;
            }
          }
        }
        *(int *)(tallyPtr - 2) =
             *(int *)(tallyPtr - 2) -
             (*(int *)*(uint32_t *)(tallyPtr + 0x1e) + *(int *)*(uint32_t *)(tallyPtr + 0x22));
        *(int *)*(uint32_t *)(tallyPtr + 10) =
             *(int *)*(uint32_t *)(tallyPtr + 10) - *(int *)*(uint32_t *)(tallyPtr + 0x1e);
        *(int *)*(uint32_t *)(tallyPtr + 0xe) =
             *(int *)*(uint32_t *)(tallyPtr + 0xe) - *(int *)*(uint32_t *)(tallyPtr + 0x22);
        return *(uint16_t *)(tallyPtr - 2);
      }
      if (*(char *)(tallyPtr + 6) != -1) {
        uVar3 = manage_usesGUnits();
        return uVar3;
      }
      uVar3 = (uint16_t)((ulong)GUnits >> 0x10);
      puVar5 = GUnits;
    } while ((puVar5[unaff_SI].unitType == 0xff) ||
            (unitPtr = *(uint32_t *)((uint)puVar5[unaff_SI].unitType << 2),
            *(char *)((int)unitPtr + 0x3f) != '\0'));
    in_AX = CONCAT11((char)(unaff_SI * 9 >> 8),(puVar5 + unaff_SI)->bldType);
    unaff_BP = tallyPtr;
  } while( true );
}



/* 4d05:2543 */

/* [R6] touches GUnits, unitType */

uint16_t __cdecl16far manage_usesGUnits(void)

{
  byte bVar1;
  uint32_t uVar2;
  unit_t *puVar3;
  int unaff_BP;
  uint unaff_SI;
  uint uVar4;
  uint16_t uVar5;
  
  uVar5 = (uint16_t)((ulong)GUnits >> 0x10);
  if (((GUnits)[unaff_SI].unitType == *(byte *)(unaff_BP + 6)) &&
     (bVar1 = (GUnits + unaff_SI)->bldType,
     BuildingTypes[bVar1].unitType == *(char *)(unaff_BP + 8))) {
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
    if (BuildingTypes[bVar1].resource == '\x01') {
      *(int *)*(uint32_t *)(unaff_BP + 10) = *(int *)*(uint32_t *)(unaff_BP + 10) + 1;
    }
    else if (BuildingTypes[bVar1].resource == '\x02') {
      *(int *)*(uint32_t *)(unaff_BP + 0xe) = *(int *)*(uint32_t *)(unaff_BP + 0xe) + 1;
    }
    else if (BuildingTypes[bVar1].resource == '\x03') {
      *(int *)*(uint32_t *)(unaff_BP + 0x12) = *(int *)*(uint32_t *)(unaff_BP + 0x12) + 1;
    }
  }
  while( true ) {
    unaff_SI = unaff_SI + 1;
    if (GUnitCount <= unaff_SI) {
      for (uVar4 = 0; uVar4 < GRecordCount; uVar4 = uVar4 + 1) {
        if ((GRecords[uVar4].party == *(char *)(unaff_BP + 6)) &&
           (bVar1 = GRecords[uVar4].reserved08,
           BuildingTypes[bVar1].unitType == *(char *)(unaff_BP + 8))) {
          *(int *)*(uint32_t *)(unaff_BP + 0x16) = *(int *)*(uint32_t *)(unaff_BP + 0x16) + 1;
          if (BuildingTypes[bVar1].resource == '\x01') {
            *(int *)*(uint32_t *)(unaff_BP + 0x1a) = *(int *)*(uint32_t *)(unaff_BP + 0x1a) + 1;
          }
          else if (BuildingTypes[bVar1].resource == '\x02') {
            *(int *)*(uint32_t *)(unaff_BP + 0x1e) = *(int *)*(uint32_t *)(unaff_BP + 0x1e) + 1;
          }
          else if (BuildingTypes[bVar1].resource == '\x03') {
            *(int *)*(uint32_t *)(unaff_BP + 0x22) = *(int *)*(uint32_t *)(unaff_BP + 0x22) + 1;
          }
        }
      }
      *(int *)(unaff_BP + -2) =
           *(int *)(unaff_BP + -2) -
           (*(int *)*(uint32_t *)(unaff_BP + 0x1e) + *(int *)*(uint32_t *)(unaff_BP + 0x22));
      *(int *)*(uint32_t *)(unaff_BP + 10) =
           *(int *)*(uint32_t *)(unaff_BP + 10) - *(int *)*(uint32_t *)(unaff_BP + 0x1e);
      *(int *)*(uint32_t *)(unaff_BP + 0xe) =
           *(int *)*(uint32_t *)(unaff_BP + 0xe) - *(int *)*(uint32_t *)(unaff_BP + 0x22);
      return *(uint16_t *)(unaff_BP + -2);
    }
    if (*(char *)(unaff_BP + 6) != -1) break;
    uVar5 = (uint16_t)((ulong)GUnits >> 0x10);
    puVar3 = GUnits;
    if (((puVar3[unaff_SI].unitType != 0xff) &&
        (uVar2 = *(uint32_t *)((uint)puVar3[unaff_SI].unitType << 2),
        *(char *)((int)uVar2 + 0x3f) == '\0')) &&
       (bVar1 = (puVar3 + unaff_SI)->bldType,
       BuildingTypes[bVar1].unitType == *(char *)(unaff_BP + 8))) {
      *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
      if (BuildingTypes[bVar1].resource == '\x01') {
        *(int *)*(uint32_t *)(unaff_BP + 10) = *(int *)*(uint32_t *)(unaff_BP + 10) + 1;
      }
      else if (BuildingTypes[bVar1].resource == '\x02') {
        *(int *)*(uint32_t *)(unaff_BP + 0xe) = *(int *)*(uint32_t *)(unaff_BP + 0xe) + 1;
      }
      else if (BuildingTypes[bVar1].resource == '\x03') {
        *(int *)*(uint32_t *)(unaff_BP + 0x12) = *(int *)*(uint32_t *)(unaff_BP + 0x12) + 1;
      }
    }
  }
  uVar5 = manage_usesGUnits();
  return uVar5;
}



/* 4d05:26f6 */

/* [R2] string "All property." */

void __cdecl16near manage_textAllProperty(uint16_t partyIndex)

{
  long lVar1;
  far_t gfx;
  far_t entries;
  far_t dst;
  void *pvVar2;
  int iVar3;
  char *numText;
  char_sheet_t *pcVar5;
  uint16_t uVar6;
  int iVar7;
  int iVar8;
  byte in_stack_00000004;
  uint16_t fontOfs;
  undefined1 fontSegLo;
  undefined1 fontSegHi;
  uint8_t term;
  uint8_t resultPtrs;
  uint16_t auStack_156 [9];
  uint8_t menuItems;
  uint16_t auStack_142 [9];
  uint8_t structNames;
  uint16_t auStack_12e [59];
  char acStack_b8 [80];
  char acStack_68 [80];
  /* GUESS: byte whose address is passed to ovc28_usesUiInputText and then used as the
     choice; the callee takes it as an out-parameter. */
  uint8_t selected;
  char cStack_17;
  int unitCount;
  int iStack_14;
  int iStack_12;
  int iStack_10;
  int resultFlag;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  char_sheet_t *sheetPtr;
  char *titlePtr;
  
  dst.seg = (uint16_t)_SS;
  dst.ofs = (uint16_t)&resultPtrs;
  F_SCOPY(far_from_u32((uint32_t)(0x24104ada)),dst,20);
  for (iVar7 = 0; iVar7 < 5; iVar7 = iVar7 + 1) {
    uVar6 = *(uint16_t *)(&resultPtrs + iVar7 * 4);
    auStack_142[iVar7 * 2] = auStack_156[iVar7 * 2];
    *(uint16_t *)(&menuItems + iVar7 * 4) = uVar6;
  }
  for (iVar7 = 0; iVar7 < 0x1e; iVar7 = iVar7 + 1) {
    uVar6 = *(uint16_t *)((int)&GStructures[0].name + iVar7 * 6);
    auStack_12e[iVar7 * 2] = *(uint16_t *)((int)&GStructures[0].name + 2 + iVar7 * 6);
    *(uint16_t *)(&structNames + iVar7 * 4) = uVar6;
  }
  cStack_17 = '\x02';
  manage_openTalkWindow();
  selected = 0x0;
  if (((cStack_17 != '\x02') && (cStack_17 != '\x03')) && (cStack_17 != '\x04')) {
    manage_usesCurSfxType3();
    return;
  }
  if (ScreenMode == '\0') {
    manage_openTalkWindow();
  }
  else {
    gfx.seg = talkwin9Cut1Seg;
    gfx.ofs = talkwin9Cut1Ofs;
    ovr_blitGfxRect(gfx,0,0,(brect_t *)(BlitRects + 1),0x10,true,0,0x10,0x10,0,0,0);
  }
  TextBlitY = 0xc;
  TextBlitX = 0x11;
  fontSegLo = (undefined1)Font02.seg;
  fontSegHi = (undefined1)(Font02.seg >> 8);
  if (in_stack_00000004 == 0xff) {
    ovr_blitLabel((char *)"All property.",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,fontSegLo,0xde,0x50);
  }
  else {
    titlePtr = (char *)((uint16_t *)((uint)in_stack_00000004 * 4))[1];
    pcVar5 = (char_sheet_t *)*(uint16_t *)((uint)in_stack_00000004 * 4);
    uVar6 = 0x50;
    term = 0xde;
    fontOfs = Font02.ofs;
    sheetPtr = pcVar5;
    iVar7 = ovr_ovc45_compute9(acStack_68,(char *)CONCAT22(pcVar5,_SS),
                               (char *)CONCAT22(Font02.ofs,titlePtr),Font02.seg,'i',0x69,3);
    pvVar2 = manage_playerTitle(sheetPtr,titlePtr,(char)iVar7,pcVar5);
    numText = ovr_stsprintf(acStack_b8,(char *)CONCAT22(0x52a1,_SS),
                           (char *)CONCAT22(pvVar2,(char *)0x26510),pcVar5);
    ovr_blitLabel(numText,(uint8_t *)CONCAT22(fontOfs,pcVar5),CONCAT11(fontSegHi,fontSegLo),term,fontSegLo,term,
                  uVar6);
  }
  TextBlitY = TextBlitY + 0xc;
  TextBlitX = 0x11;
  ovr_blitLabel((char *)"Buildings",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
  manage_usesBlitLabel2("Total",100);
  manage_usesBlitLabel2("Level 1",0x8c);
  manage_usesBlitLabel2("Level 2",0xb4);
  manage_usesBlitLabel2("Level 3",0xdc);
  TextBlitY = TextBlitY + 0xc;
  if (cStack_17 == '\x04') {
    iVar7 = 0x1a;
  }
  else if (cStack_17 == '\x03') {
    iVar7 = 0xd;
  }
  else {
    iVar7 = 0;
  }
  iVar8 = 0;
  while( true ) {
    if (0xc < iVar8) break;
    if (iVar8 + iVar7 < 0x1e) {
      TextBlitX = 0x11;
      iVar3 = (iVar8 + iVar7) * 6;
      ovr_blitLabel((char *)*(uint16_t *)((int)&GStructures[0].name + iVar3),
                    (uint8_t *)
                    CONCAT22(Font02.ofs,
                             (uint8_t *)*(uint16_t *)((int)&GStructures[0].name + 2 + iVar3)),
                    Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
      lVar1 = (long)(iVar8 + iVar7) * 6;
      uVar6 = (uint16_t)((ulong)lVar1 >> 0x10);
      unitCount = manage_usesGUnitCount
                            (in_stack_00000004,(&((unk01_t *)GStructures)->type)[(int)lVar1],
                             (int *)CONCAT22(_SS,&iStack_8),(int *)CONCAT22(_SS,&iStack_a)
                             ,(int *)CONCAT22(_SS,&iStack_c),
                             (int *)CONCAT22(_SS,&resultFlag));
      if (resultFlag == 0) {
        iVar3 = 100;
        numText = litoa10(acStack_68,
                         CONCAT13((char)((uint)unitCount >> 8),CONCAT12((char)unitCount,_SS)),
                         (char)unitCount,0);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,numText)),iVar3);
      }
      else {
        iVar3 = 100;
        numText = ovr_stsprintf(acStack_b8);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,numText)),iVar3);
      }
      lVar1 = (long)(iVar8 + iVar7) * 6;
      uVar6 = (uint16_t)((ulong)lVar1 >> 0x10);
      if (*(char *)((int)&GStructures[0].pad + (int)lVar1) != '\0') {
        if (iStack_10 == 0) {
          iVar3 = 0x8c;
          numText = litoa10(acStack_68,
                           CONCAT13((char)((uint)iStack_8 >> 8),CONCAT12((char)iStack_8,_SS)),
                           (char)iStack_8,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,numText)),iVar3);
        }
        else {
          iVar3 = 0x8c;
          numText = ovr_stsprintf(acStack_b8);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,numText)),iVar3);
        }
        if (iStack_12 == 0) {
          iVar3 = 0xb4;
          numText = litoa10(acStack_68,
                           CONCAT13((char)((uint)iStack_a >> 8),CONCAT12((char)iStack_a,_SS)),
                           (char)iStack_a,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,numText)),iVar3);
        }
        else {
          iVar3 = 0xb4;
          numText = ovr_stsprintf(acStack_b8);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,numText)),iVar3);
        }
        if (iStack_14 == 0) {
          iVar3 = 0xdc;
          numText = litoa10(acStack_68,
                           CONCAT13((char)((uint)iStack_c >> 8),CONCAT12((char)iStack_c,_SS)),
                           (char)iStack_c,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,numText)),iVar3);
        }
        else {
          iVar3 = 0xdc;
          numText = ovr_stsprintf(acStack_b8);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,numText)),iVar3);
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
    iVar8 = iVar8 + 1;
  }
  CurSfxType3 = 0x3c;
  (*(uint8_t *)((uint8_t *)&(entries.seg))) = (char)_SS;
  entries.ofs = (uint16_t)&menuItems;
  (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = (char)((uint)_SS >> 8);
  uVar6 = ovr_ovc28_usesUiInputText(entries,0x23,far_from_u32((uint32_t)(0x0)),&selected,0,(char)&selected);
  cStack_17 = (char)uVar6;
  keyboardInputMode = 0;
  if (((cStack_17 != '\0') && (cStack_17 != '\x01')) && (cStack_17 != -2)) {
    manage_textAllProperty2();
    return;
  }
  if ((ScreenMode == '\0') && (cStack_17 != -2)) {
    manage_openTalkWindow();
  }
  if (cStack_17 == -2) {
    Cancelled = 1;
  }
  return;
}



/* 4d05:277a */
void manage_textAllProperty2(void)

{
  long lVar1;
  far_t gfx;
  far_t entries;
  uint16_t *puVar2;
  void *pvVar3;
  int iVar4;
  char *numText;
  uint8_t *puVar6;
  uint16_t uVar7;
  int unaff_BP;
  int iVar8;
  int iVar9;
  uint16_t uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  uint8_t term;
  
  if (((*(char *)(unaff_BP + -0x15) != '\x02') && (*(char *)(unaff_BP + -0x15) != '\x03')) &&
     (*(char *)(unaff_BP + -0x15) != '\x04')) {
    manage_usesCurSfxType3();
    return;
  }
  if (ScreenMode == '\0') {
    manage_openTalkWindow();
  }
  else {
    gfx.seg = talkwin9Cut1Seg;
    gfx.ofs = talkwin9Cut1Ofs;
    ovr_blitGfxRect(gfx,0,0,(brect_t *)(BlitRects + 1),0x10,true,0,0x10,0x10,0,0,0);
  }
  TextBlitY = 0xc;
  TextBlitX = 0x11;
  if (*(char *)(unaff_BP + 6) == -1) {
    ovr_blitLabel((char *)"All property.",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,(char)Font02.seg,0xde,0x50);
  }
  else {
    puVar2 = (uint16_t *)((uint)*(byte *)(unaff_BP + 6) * 4);
    puVar6 = (uint8_t *)*puVar2;
    *(uint16_t *)(unaff_BP + -2) = puVar2[1];
    *(uint16_t *)(unaff_BP + -4) =(uint16_t)( puVar6);
    uVar7 = 0x50;
    term = 0xde;
    uVar11 = (undefined1)Font02.seg;
    uVar12 = (undefined1)(Font02.seg >> 8);
    uVar10 = Font02.ofs;
    iVar9 = ovr_ovc45_compute9((char *)(unaff_BP + -0x66),
                               (char *)CONCAT22(*(uint16_t *)(unaff_BP + -4),_SS),
                               (char *)CONCAT22(Font02.ofs,(char *)*(uint16_t *)(unaff_BP + -2)),
                               Font02.seg,'i',0x69,3);
    pvVar3 = manage_playerTitle((char_sheet_t *)*(uint16_t *)(unaff_BP + -4),
                                *(uint16_t *)(unaff_BP + -2),(char)iVar9,puVar6);
    numText = ovr_stsprintf((char *)(unaff_BP + -0xb6),(char *)CONCAT22(0x52a1,_SS),
                           (char *)CONCAT22(pvVar3,(char *)0x26510),puVar6);
    ovr_blitLabel(numText,(uint8_t *)CONCAT22(uVar10,puVar6),CONCAT11(uVar12,uVar11),term,uVar11,term
                  ,uVar7);
  }
  TextBlitY = TextBlitY + 0xc;
  TextBlitX = 0x11;
  ovr_blitLabel((char *)"Buildings",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
  manage_usesBlitLabel2("Total",100);
  manage_usesBlitLabel2("Level 1",0x8c);
  manage_usesBlitLabel2("Level 2",0xb4);
  manage_usesBlitLabel2("Level 3",0xdc);
  TextBlitY = TextBlitY + 0xc;
  if (*(char *)(unaff_BP + -0x15) == '\x04') {
    iVar9 = 0x1a;
  }
  else if (*(char *)(unaff_BP + -0x15) == '\x03') {
    iVar9 = 0xd;
  }
  else {
    iVar9 = 0;
  }
  iVar8 = 0;
  while( true ) {
    if (0xc < iVar8) break;
    if (iVar8 + iVar9 < 0x1e) {
      TextBlitX = 0x11;
      iVar4 = (iVar8 + iVar9) * 6;
      ovr_blitLabel((char *)*(uint16_t *)((int)&GStructures[0].name + iVar4),
                    (uint8_t *)
                    CONCAT22(Font02.ofs,
                             (uint8_t *)*(uint16_t *)((int)&GStructures[0].name + 2 + iVar4)),
                    Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
      lVar1 = (long)(iVar8 + iVar9) * 6;
      uVar7 = (uint16_t)((ulong)lVar1 >> 0x10);
      iVar4 = manage_usesGUnitCount
                        (*(char *)(unaff_BP + 6),(&((unk01_t *)GStructures)->type)[(int)lVar1],
                         (int *)CONCAT22(_SS,(int *)(unaff_BP + -6)),
                         (int *)CONCAT22(_SS,(int *)(unaff_BP + -8)),
                         (int *)CONCAT22(_SS,(int *)(unaff_BP + -10)),
                         (int *)CONCAT22(_SS,(int *)(unaff_BP + -0xc)));
      *(int *)((char *)init_textFilename + unaff_BP) = iVar4;
      if (*(int *)(unaff_BP + -0xc) == 0) {
        iVar4 = 100;
        uVar11 = (undefined1)*(uint16_t *)((char *)init_textFilename + unaff_BP);
        numText = litoa10((char *)(unaff_BP + -0x66),
                         CONCAT13((char)((uint)*(uint16_t *)((char *)init_textFilename + unaff_BP)
                                        >> 8),CONCAT12(uVar11,_SS)),uVar11,0);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
      }
      else {
        iVar4 = 100;
        numText = ovr_stsprintf((char *)(unaff_BP + -0xb6));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
      }
      lVar1 = (long)(iVar8 + iVar9) * 6;
      uVar7 = (uint16_t)((ulong)lVar1 >> 0x10);
      if (*(char *)((int)&GStructures[0].pad + (int)lVar1) != '\0') {
        if (*(int *)(unaff_BP + -0xe) == 0) {
          iVar4 = 0x8c;
          uVar11 = (undefined1)*(uint16_t *)(unaff_BP + -6);
          numText = litoa10((char *)(unaff_BP + -0x66),
                           CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -6) >> 8),
                                    CONCAT12(uVar11,_SS)),uVar11,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
        }
        else {
          iVar4 = 0x8c;
          numText = ovr_stsprintf((char *)(unaff_BP + -0xb6));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
        }
        if (*(int *)(unaff_BP + -0x10) == 0) {
          iVar4 = 0xb4;
          uVar11 = (undefined1)*(uint16_t *)(unaff_BP + -8);
          numText = litoa10((char *)(unaff_BP + -0x66),
                           CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                    CONCAT12(uVar11,_SS)),uVar11,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
        }
        else {
          iVar4 = 0xb4;
          numText = ovr_stsprintf((char *)(unaff_BP + -0xb6));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
        }
        if (*(int *)(unaff_BP + -0x12) == 0) {
          iVar4 = 0xdc;
          uVar11 = (undefined1)*(uint16_t *)(unaff_BP + -10);
          numText = litoa10((char *)(unaff_BP + -0x66),
                           CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -10) >> 8),
                                    CONCAT12(uVar11,_SS)),uVar11,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
        }
        else {
          iVar4 = 0xdc;
          numText = ovr_stsprintf((char *)(unaff_BP + -0xb6));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
    iVar8 = iVar8 + 1;
  }
  CurSfxType3 = 0x3c;
  (*(uint8_t *)((uint8_t *)&(entries.seg))) = (char)_SS;
  entries.ofs = unaff_BP + -0x142;
  (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = (char)((uint)_SS >> 8);
  uVar7 = ovr_ovc28_usesUiInputText
                    (entries,0x23,far_from_u32((uint32_t)(0x0)),(uint8_t *)(unaff_BP + -0x16),0,
                     (char)(uint8_t *)(unaff_BP + -0x16));
  *(undefined1 *)(unaff_BP + -0x15) = (char)uVar7;
  keyboardInputMode = 0;
  if (((*(char *)(unaff_BP + -0x15) != '\0') && (*(char *)(unaff_BP + -0x15) != '\x01')) &&
     (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_textAllProperty2();
    return;
  }
  if ((ScreenMode == '\0') && (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_openTalkWindow();
  }
  if (*(char *)(unaff_BP + -0x15) == -2) {
    Cancelled = 1;
  }
  return;
}


/* 4d05:28f4 */

/* [R4] calls litoa10 */

uint16_t __cdecl16far manage_usesLitoa103(textSeg,owner)
uint16_t textSeg;
int owner;

{
  long lVar1;
  far_t entries;
  int iVar2;
  char *pcVar3;
  uint16_t uVar4;
  int unaff_BP;
  int iVar5;
  int iVar6;
  char *in_stack_00000002;
  undefined1 uStack0006;
  undefined1 uStack0007;
  
  manage_usesBlitLabel2((char *)CONCAT22(textSeg,in_stack_00000002),uStack0006);
  manage_usesBlitLabel2("Level 3",0xdc);
  TextBlitY = TextBlitY + 0xc;
  if (*(char *)(unaff_BP + -0x15) == '\x04') {
    iVar6 = 0x1a;
  }
  else if (*(char *)(unaff_BP + -0x15) == '\x03') {
    iVar6 = 0xd;
  }
  else {
    iVar6 = 0;
  }
  for (iVar5 = 0; iVar5 < 0xd; iVar5 = iVar5 + 1) {
    if (iVar5 + iVar6 < 0x1e) {
      TextBlitX = 0x11;
      iVar2 = (iVar5 + iVar6) * 6;
      ovr_blitLabel((char *)*(uint16_t *)((int)&GStructures[0].name + iVar2),
                    (uint8_t *)
                    CONCAT22(Font02.ofs,
                             (uint8_t *)*(uint16_t *)((int)&GStructures[0].name + 2 + iVar2)),
                    Font02.seg,0xde);
      lVar1 = (long)(iVar5 + iVar6) * 6;
      uVar4 = (uint16_t)((ulong)lVar1 >> 0x10);
      iVar2 = manage_usesGUnitCount
                        (*(char *)(unaff_BP + 6),(&((unk01_t *)GStructures)->type)[(int)lVar1],
                         (int *)CONCAT22(_SS,(int *)(unaff_BP + -6)),
                         (int *)CONCAT22(_SS,(int *)(unaff_BP + -8)),
                         (int *)CONCAT22(_SS,(int *)(unaff_BP + -10)),
                         (int *)CONCAT22(_SS,(int *)(unaff_BP + -0xc)));
      *(int *)((char *)init_textFilename + unaff_BP) = iVar2;
      if (*(int *)(unaff_BP + -0xc) == 0) {
        pcVar3 = litoa10((char *)(unaff_BP + -0x66),(long)CONCAT22(*(uint16_t *)((char *)init_textFilename + unaff_BP),
                                        _SS),0,0);
        uStack0006 = (undefined1)uVar4;
        uStack0007 = (undefined1)((uint)uVar4 >> 8);
        manage_blitLabelRight((char *)CONCAT13(uStack0007,CONCAT12(uStack0006,pcVar3)),100);
      }
      else {
        pcVar3 = ovr_stsprintf((char *)(unaff_BP + -0xb6),(char *)CONCAT22(0x52e5,_SS),
                               (char *)CONCAT22(*(uint16_t *)
                                                 ((char *)init_textFilename + unaff_BP),
                                                (char *)0x26510));
        uStack0006 = (undefined1)uVar4;
        uStack0007 = (undefined1)((uint)uVar4 >> 8);
        manage_blitLabelRight((char *)CONCAT13(uStack0007,CONCAT12(uStack0006,pcVar3)),100);
      }
      lVar1 = (long)(iVar5 + iVar6) * 6;
      uVar4 = (uint16_t)((ulong)lVar1 >> 0x10);
      if (*(char *)((int)&GStructures[0].pad + (int)lVar1) != '\0') {
        if (*(int *)(unaff_BP + -0xe) == 0) {
          pcVar3 = litoa10((char *)(unaff_BP + -0x66),(long)CONCAT22(*(uint16_t *)(unaff_BP + -6),_SS),0,0);
          uStack0006 = (undefined1)uVar4;
          uStack0007 = (undefined1)((uint)uVar4 >> 8);
          manage_blitLabelRight((char *)CONCAT13(uStack0007,CONCAT12(uStack0006,pcVar3)),0x8c);
        }
        else {
          pcVar3 = ovr_stsprintf((char *)(unaff_BP + -0xb6),(char *)CONCAT22(0x52e5,_SS),
                                 (char *)CONCAT22(*(uint16_t *)(unaff_BP + -6),
                                                  (char *)0x26510));
          uStack0006 = (undefined1)uVar4;
          uStack0007 = (undefined1)((uint)uVar4 >> 8);
          manage_blitLabelRight((char *)CONCAT13(uStack0007,CONCAT12(uStack0006,pcVar3)),0x8c);
        }
        if (*(int *)(unaff_BP + -0x10) == 0) {
          pcVar3 = litoa10((char *)(unaff_BP + -0x66),(long)CONCAT22(*(uint16_t *)(unaff_BP + -8),_SS),0,0);
          uStack0006 = (undefined1)uVar4;
          uStack0007 = (undefined1)((uint)uVar4 >> 8);
          manage_blitLabelRight((char *)CONCAT13(uStack0007,CONCAT12(uStack0006,pcVar3)),0xb4);
        }
        else {
          pcVar3 = ovr_stsprintf((char *)(unaff_BP + -0xb6),(char *)CONCAT22(0x52e5,_SS),
                                 (char *)CONCAT22(*(uint16_t *)(unaff_BP + -8),
                                                  (char *)0x26510));
          uStack0006 = (undefined1)uVar4;
          uStack0007 = (undefined1)((uint)uVar4 >> 8);
          manage_blitLabelRight((char *)CONCAT13(uStack0007,CONCAT12(uStack0006,pcVar3)),0xb4);
        }
        if (*(int *)(unaff_BP + -0x12) == 0) {
          pcVar3 = litoa10((char *)(unaff_BP + -0x66),(long)CONCAT22(*(uint16_t *)(unaff_BP + -10),_SS),0,0);
          uStack0006 = (undefined1)uVar4;
          uStack0007 = (undefined1)((uint)uVar4 >> 8);
          manage_blitLabelRight((char *)CONCAT13(uStack0007,CONCAT12(uStack0006,pcVar3)),0xdc);
        }
        else {
          pcVar3 = ovr_stsprintf((char *)(unaff_BP + -0xb6),(char *)CONCAT22(0x52e5,_SS),
                                 (char *)CONCAT22(*(uint16_t *)(unaff_BP + -10),
                                                  (char *)0x26510));
          uStack0006 = (undefined1)uVar4;
          uStack0007 = (undefined1)((uint)uVar4 >> 8);
          manage_blitLabelRight((char *)CONCAT13(uStack0007,CONCAT12(uStack0006,pcVar3)),0xdc);
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
  }
  CurSfxType3 = 0x3c;
  entries.seg = (uint16_t)_SS;
  entries.ofs = unaff_BP - 0x142;
  uVar4 = ovr_ovc28_usesUiInputText(entries,0x23,far_from_u32((uint32_t)(0x0)),0,0,0);
  *(undefined1 *)(unaff_BP + -0x15) = (char)uVar4;
  keyboardInputMode = 0;
  if (((*(char *)(unaff_BP + -0x15) != '\0') && (*(char *)(unaff_BP + -0x15) != '\x01')) &&
     (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_textAllProperty2();
    return;
  }
  if ((ScreenMode == '\0') && (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_openTalkWindow();
  }
  if (*(char *)(unaff_BP + -0x15) == -2) {
    Cancelled = 1;
  }
  return;
}



/* 4d05:2b09 */

/* [R6] touches CurSfxType3, __C0_ASM_CopyRight */

void __cdecl16far manage_usesCurSfxType3(void)

{
  uint16_t uVar1;
  int unaff_BP;
  far_t entries;
  
  if (*(char *)(unaff_BP + -0x15) == '\x05') {
    manage_highlightStructures(*(uint8_t *)(unaff_BP + 6),0xfe);
  }
  else {
    manage_highlightStructures
              (*(uint8_t *)(unaff_BP + 6),
               (uint)*(byte *)((int)&menuHighlightTable[2].seg + 1 +
                              (uint)*(byte *)(unaff_BP + -0x15) * 6));
  }
  keyboardInputMode = 1;
  CurSfxType3 = 0x3c;
  entries.seg = _SS;
  entries.ofs = unaff_BP - 0x142;
  uVar1 = ovr_ovc28_usesUiInputText(entries,0x23,far_from_u32((uint32_t)(0x0)),(uint8_t *)(unaff_BP + -0x16),0,0);
  *(undefined1 *)(unaff_BP + -0x15) = (char)uVar1;
  keyboardInputMode = 0;
  if (((*(char *)(unaff_BP + -0x15) != '\0') && (*(char *)(unaff_BP + -0x15) != '\x01')) &&
     (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_textAllProperty2();
    return;
  }
  if ((ScreenMode == '\0') && (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_openTalkWindow();
  }
  if (*(char *)(unaff_BP + -0x15) == -2) {
    Cancelled = 1;
  }
  return;
}



/* 4d05:2b3e */

/* [R6] touches CurSfxType3, __C0_ASM_CopyRight */

uint16_t __cdecl16far manage_usesCurSfxType32()

{
  uint16_t uVar1;
  int unaff_BP;
  int in_stack_00000000;
  far_t entries;
  
  manage_highlightStructures(*(uint8_t *)(unaff_BP + 6),in_stack_00000000);
  keyboardInputMode = 1;
  CurSfxType3 = 0x3c;
  entries.seg = _SS;
  entries.ofs = unaff_BP - 0x142;
  uVar1 = ovr_ovc28_usesUiInputText(entries,0x23,far_from_u32((uint32_t)(0x0)),(uint8_t *)(unaff_BP + -0x16),0,0);
  *(undefined1 *)(unaff_BP + -0x15) = (char)uVar1;
  keyboardInputMode = 0;
  if (((*(char *)(unaff_BP + -0x15) != '\0') && (*(char *)(unaff_BP + -0x15) != '\x01')) &&
     (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_textAllProperty2();
    return;
  }
  if ((ScreenMode == '\0') && (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_openTalkWindow();
  }
  if (*(char *)(unaff_BP + -0x15) == -2) {
    Cancelled = 1;
  }
  return;
}



/* 4d05:2bc4 */

/* Applies the damaged-structure highlight filter for a party/type and reports it. */

void __cdecl16far manage_highlightStructures(uint8_t partyIndex,int structType)

{
  char *className;
  char *sayText;
  uint16_t seedArg;
  uint16_t strSeg;
  uint16_t saySeg;
  int structIdx;
  int nameOfs;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  uint16_t savedSeed;
  uint16_t savedSeed2;
  
  Highlight1 = (undefined1)structType;
  Highlight1 = partyIndex;
  if (ScreenMode != '\0') {
    ovr_stats_openCastlePanel();
  }
  savedSeed2 = GfxRndSeed;
  savedSeed = GfxRndSeed2;
  GfxRndSeed = Seed_2000_d1da;
  GfxRndSeed2 = Seed_2000_d1d8;
  ovr_ovc13_usesAlignUp4();
  GfxRndSeed = savedSeed2;
  GfxRndSeed2 = savedSeed;
  Highlight1 = 0xff;
  Highlight1 = 0xff;
  if (structType == 0xfe) {
    if (partyIndex == 0xff) {
      ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.",
              0x2410);
    }
    else {
      seedArg = savedSeed;
      className = ovr_ovc22_className(partyIndex,0);
      saySeg = _DS;
      sayText = ovr_stsprintf(msg,(char *)CONCAT22(0x535b,_SS),
                             (char *)CONCAT22(*(uint16_t *)((uint)partyIndex * 4),
                                              (char *)0x26510),
                             ((uint16_t *)((uint)partyIndex * 4))[1],className,seedArg);
      ovr_say(sayText,saySeg);
    }
  }
  else {
    structIdx = 0;
    strSeg = savedSeed;
    while ((structIdx < 0x1e &&
           (strSeg = (uint16_t)((ulong)((long)structIdx * 6) >> 0x10),
           (uint)(&((unk01_t *)GStructures)->type)[(int)((long)structIdx * 6)] != structType))) {
      structIdx = structIdx + 1;
    }
    if (structIdx != 0x1e) {
      if (partyIndex == 0xff) {
        strSeg = (uint16_t)((ulong)((long)structIdx * 6) >> 0x10);
        nameOfs = (int)((long)nameOfs * 6);
        sayText = ovr_stsprintf(msg,(char *)CONCAT22(0x5323,_SS),
                               (char *)CONCAT22(*(uint16_t *)((int)&GStructures[0].name + nameOfs),
                                                (char *)0x26510),
                               *(uint16_t *)((int)&GStructures[0].name + 2 + nameOfs));
        ovr_say(sayText,strSeg);
      }
      else {
        className = ovr_ovc22_className(partyIndex,0);
        saySeg = (uint16_t)((ulong)((long)structIdx * 6) >> 0x10);
        nameOfs = (int)((long)nameOfs * 6);
        sayText = ovr_stsprintf(msg,(char *)CONCAT22(0x52ed,_SS),
                               (char *)CONCAT22(*(uint16_t *)((int)&GStructures[0].name + nameOfs),
                                                (char *)0x26510),
                               *(uint16_t *)((int)&GStructures[0].name + 2 + nameOfs),
                               *(uint16_t *)((uint)partyIndex * 4),
                               ((uint16_t *)((uint)partyIndex * 4))[1],className,strSeg);
        ovr_say(sayText,saySeg);
      }
    }
  }
  return;
}



/* 4d05:2d79 */
char * __cdecl16far manage_textTotalPopulation(byte charIndex,short arg6,char_sheet_t *sheet)

{
  undefined1 stk_bac4;   /* stack slot bac4 */
  undefined1 stk_fe3a;   /* stack slot fe3a */
  uint16_t *puVar1;
  uint8_t *puVar2;
  uint32_t uVar3;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  char cVar4;
  uint16_t uVar5;
  uint uVar6;
  uint aligned;
  uint alignedX;
  int iVar9;
  int iVar10;
  int product;
  undefined1 uVar12;
  byte *pbVar13;
  uint16_t in_DX;
  uint8_t *puVar14;
  entity_t *peVar15;
  entity_t *peVar16;
  char *pcVar17;
  char *count;
  uint16_t uVar18;
  uint16_t unaff_ES;
  bool bVar19;
  far_t entries;
  char acStack_1b6 [120];
  char acStack_13e [36];
  uint16_t auStack_11a [42];
  uint8_t bandLabels2;
  uint8_t bandLabels;
  uint16_t auStack_94 [23];
  undefined1 auStack_66 [10];
  entity_t *peStack_1e;
  char cStack_1a;
  char cStack_19;
  char cStack_18;
  uint8_t changedFlag;
  int iStack_16;
  int ySign;
  int iStack_12;
  uint16_t fontSeg;
  char acStack_e [6];
  uint16_t entY;
  uint32_t auStack_6;   /* hand fix: CONCAT12/13/22 target, read as uint3 */
  uint16_t packedByte;
  
  dst.seg = (uint16_t)_SS;
  dst.ofs = (uint16_t)&bandLabels;
  F_SCOPY(far_from_u32((uint32_t)(0x24104b06)),dst,48);
  dst_00.seg = (uint16_t)_SS;
  dst_00.ofs = (uint16_t)&bandLabels2;
  F_SCOPY(far_from_u32((uint32_t)(0x24104b36)),dst_00,48);
  pbVar13 = (byte *)__C0_ASM_CopyRight + 3;
  dst_01.seg = (uint16_t)_SS;
  dst_01.ofs = (uint16_t)(acStack_e + 4);
  F_SCOPY(far_from_u32((uint32_t)(0x24104b66)),dst_01,7);
  acStack_e[2] = '\0';
  if (charIndex == 0xff) {
    acStack_e[3] = 0xc;
  }
  else {
    in_DX = _DS;
    unaff_ES = (uint16_t)((ulong)*(uint32_t *)((uint)charIndex << 2) >> 0x10);
    if (*(char *)((int)*(uint32_t *)((uint)charIndex << 2) + 0x2f) == -1) {
      acStack_e[3] = 0xc;
    }
    else {
      acStack_e[3] = acStack_e[*(byte *)((int)*(uint32_t *)((uint)charIndex << 2) + 0x2f) + 4];
      in_DX = _DS;
      unaff_ES = (uint16_t)((ulong)*(uint32_t *)((uint)charIndex << 2) >> 0x10);
      if (3 < *(byte *)((int)*(uint32_t *)((uint)charIndex << 2) + 0x2f)) {
        acStack_e[2] = '\x01';
      }
    }
  }
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 2)) = 0x2410;
  (*(uint16_t *)((uint8_t *)&(auStack_66))) = 0x50fb;
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 6)) = 0x2410;
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 4)) = 0x54e5;
  peVar15 = (entity_t *)(auStack_66 + 8);
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 8)) = 0x54ed;
  count = (char *)((int)(uint32_t *)&_DATA + 3);
  for (pcVar17 = (char *)0x0; (int)pcVar17 < (int)(uint)(byte)acStack_e[3]; pcVar17 = pcVar17 + 1) {
    if (((int)pcVar17 < 5) || (acStack_e[2] == '\0')) {
      in_DX = *(uint16_t *)(&bandLabels + (int)pcVar17 * 4);
      peVar15 = (entity_t *)(auStack_66 + (int)count * 4);
      *(uint16_t *)(auStack_66 + (int)count * 4 + 2) = auStack_94[(int)pcVar17 * 2];
      (peVar15->base).x = in_DX;
    }
    else {
      unaff_ES = (uint16_t)((ulong)*(uint32_t *)((uint)charIndex << 2) >> 0x10);
      uVar6 = (uint)*(byte *)((int)*(uint32_t *)((uint)charIndex << 2) + 0x2f);
      in_DX = auStack_11a[(int)pcVar17 * 2 + uVar6 * 8];
      peVar15 = (entity_t *)(auStack_66 + (int)count * 4);
      *(uint16_t *)(auStack_66 + (int)count * 4 + 2) = auStack_11a[(int)pcVar17 * 2 + uVar6 * 8 + 1]
      ;
      (peVar15->base).x = in_DX;
    }
    pbVar13 = auStack_66;
    count = count + 1;
  }
  acStack_e[1] = '\x02';
  manage_openTalkWindow();
  acStack_e[0] = '\0';
  if (acStack_e[1] == '\x02') {
    if (ScreenMode == '\0') {
      manage_openTalkWindow();
    }
    TextBlitY = 0xc;
    TextBlitX = 0x11;
    if (charIndex == 0xff) {
      uVar6 = ovr_blitLabel((char *)"Total population.",
                            (uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510));
      *pcVar17 = *pcVar17 + (char)(uVar6 >> 8) + ((undefined1 *)0xfff3 < &stk_fe3a);
      ((dos_psp_t *)((entity_t **)&Entities + uVar6))->jft[0] = 0;
      uVar18 = (uint16_t)((ulong)Entities >> 0x10);
      *(undefined1 *)((int)&(Entities)[(int)pcVar17].base.state + 1) =
           (char)(Entities)[(int)pcVar17].base.flags32;
      if (EntityCount <= pcVar17 + 1) {
        if ((acStack_e[0] != '\0') || (acStack_e[1] != '\0')) {
          if ((*(uint8_t *)((uint8_t *)&(packedByte) + 1)) == '\0') {
            ovr_stop_audio();
            CurSfxType3 = 0xff;
            ovr_play_sfx(90,0,0);
          }
          else if (acStack_e[1] == '\0') {
            if (acStack_e[0] != '\0') {
              ovr_play_sfx(37,0,0);
            }
          }
          else {
            ovr_play_sfx(35,0,0);
          }
        }
        GGameState = 0x3d;
        pcVar17 = (char *)0x26510;
        if (DebugVerbose != false) {
          pcVar17 = (char *)0x26510;
          printf("%d \r");
        }
        ovr_OVC23_55fe_29a2_entry();
        return pcVar17;
      }
      pcVar17 = (char *)0x1e6;
      ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.",0);
      return pcVar17;
    }
    fontSeg = (uint16_t)SEG_OF(GLeaderSheets[charIndex]);
    iStack_12 = (int)far_ofs_u32(GLeaderSheets[charIndex]);
    uVar5 = Font02.ofs;
    ovr_ovc45_compute9(acStack_1b6,(char *)CONCAT22(iStack_12,_SS),
                       (char *)CONCAT22(Font02.ofs,fontSeg),Font02.seg,'K');
    SUB_5b66_1d94();
    puVar14 = (uint8_t *)((char *)0x26510);
    pcVar17 = ovr_stsprintf(acStack_13e,(char *)CONCAT22(0x550a,_SS),
                            (char *)CONCAT22(*(uint16_t *)
                                              ((uint)*(byte *)(iStack_12 + 0x2f) * 4 + 0xeb),
                                             (char *)0x26510));
    ovr_blitLabel(pcVar17,(uint8_t *)CONCAT22(uVar5,puVar14));
    TextBlitY = TextBlitY + 0xc;
    iVar9 = ovr_font_textWidth((char *)"UNITS",0,0,0,0);
    TextBlitX = 0x89 - iVar9;
    ovr_blitLabel((char *)"UNITS",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510));
    iVar9 = ovr_font_textWidth((char *)"POPULATION",0,0,0,0);
    uVar5 = 0xd4 - iVar9;
    TextBlitX = uVar5;
    ovr_blitLabel((char *)"POPULATION",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510));
    iVar9 = 0;
    while( true ) {
      TextBlitY = TextBlitY + 0xc;
      cVar4 = (char)pbVar13;
      if ((int)(uint)(byte)acStack_e[3] <= iVar9) break;
      TextBlitX = 0x11;
      if ((iVar9 < 5) || (acStack_e[2] == '\0')) {
        ovr_blitLabel(*(char **)(&bandLabels + iVar9 * 4),
                      (uint8_t *)CONCAT22(Font02.ofs,(uint8_t *)auStack_94[iVar9 * 2]));
      }
      else {
        uVar6 = (uint)*(byte *)((int)*(uint32_t *)((uint)charIndex << 2) + 0x2f);
        ovr_blitLabel((char *)auStack_11a[iVar9 * 2 + uVar6 * 8],
                      (uint8_t *)
                      CONCAT22(Font02.ofs,(uint8_t *)auStack_11a[iVar9 * 2 + uVar6 * 8 + 1]));
      }
      ovc27_textCharmed();
      ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x4c,CONCAT12(0xd1,_SS)));
      iVar10 = ovr_font_textWidth(acStack_13e,0,0,0,0);
      TextBlitX = 0x89 - iVar10;
      ovr_blitLabel(acStack_13e,(uint8_t *)CONCAT22(Font02.ofs,_SS));
      ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x4c,CONCAT12(0xd1,_SS)));
      iVar10 = ovr_font_textWidth(acStack_13e,0,0,0,0);
      uVar5 = 0xd4 - iVar10;
      TextBlitX = uVar5;
      ovr_blitLabel(acStack_13e,(uint8_t *)CONCAT22(Font02.ofs,_SS));
      iVar9 = iVar9 + 1;
    }
    CurSfxType3 = 0x3c;
    entries.seg = (uint16_t)_SS;
    entries.ofs = (uint16_t)auStack_66;
    uVar18 = ovr_ovc28_usesUiInputText(entries,(uint16_t)count,far_from_u32((uint32_t)(0x0)),0,0,0);
    acStack_e[1] = (char)uVar18;
    keyboardInputMode = 0;
    if (((acStack_e[1] != '\0') && (acStack_e[1] != '\x01')) && (acStack_e[1] != -2)) {
      (&stk_bac4)[(int)count] = (&stk_bac4)[(int)count] + cVar4;
      iVar10 = 0x2410;
      do {
        product = iVar10 * uVar5;
        iVar10 = iVar9;
        if (Agnts[iVar9].strengthMax < *(byte *)(product + 0x21)) {
          Agnts[iVar9].strength = Agnts[iVar9].strengthMax;
        }
        do {
          iVar10 = iVar10 + 1;
          if ((int)(uint)AgntCount <= iVar10) {
            iVar9 = ovr_audio_panFromX((agnt_t far *)sheet,0);
            uVar12 = (undefined1)((uint)iVar9 >> 8);
            ovr_play_sfxU(0x1c,0,0,0,0);
            return (char *)CONCAT11(uVar12,1);
          }
        } while (Agnts[iVar10].owner != *(int *)(sheet->nameText + 0x1b));
        uVar18 = (uint16_t)((ulong)auStack_6 >> 0x10);
        if (*(byte *)((int)auStack_6 + 0x32) < Agnts[iVar10].strengthMax) {
          Agnts[iVar10].strengthMax = *(undefined1 *)((int)auStack_6 + 0x32);
        }
        uVar5 = 0x34;
        iVar9 = iVar10;
      } while( true );
    }
    if (acStack_e[1] == -2) {
      Cancelled = 1;
    }
    return (char *)0x26510;
  }
  do {
    uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
    peVar16 = (entity_t *)peStack_1e;
    (peVar16->base).target =
         (byte)((int)(uint)*(byte *)((int)&(peVar16->base).owner +
                                    ((int)(uint)(peVar15->base).faction >> 2)) >>
               (((peVar16->base).faction & 3) << 1)) & 3;
    cVar4 = func_0x0004f32d();
    peVar15 = (entity_t *)peStack_1e;
    uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
    if (cVar4 == '\0') {
      (peStack_1e->base).x = (peStack_1e->base).x + (int)*(char *)((peVar15->base).target + 0x885);
      puVar1 = &(peVar15->base).y;
      *puVar1 = *puVar1 + (int)*(char *)((peVar15->base).target + 0x889);
      puVar2 = &(peVar15->base).faction;
      *puVar2 = *puVar2 + 0x1;
    }
    else {
      (peVar15->base).faction = 0x0;
      *(undefined1 *)&(peVar15->base).state = 0;
    }
L_attact_3f0b_1082_1477:
    changedFlag = 0x1;
    uVar6 = ovr_alignUp4((((entity_t *)peStack_1e)->base).destX,0,0);
    aligned = ovr_alignUp4((peStack_1e->base).x,0,0);
    if (uVar6 == aligned) {
      uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
      peVar15 = (entity_t *)peStack_1e;
      if ((peVar15->base).destY == (peVar15->base).y) {
        (peVar15->base).destX = 0;
        (peVar15->base).destY = 0;
        if (*(char *)((int)&(peVar15->base).entity + 3) == -1) {
          auStack_6 = CONCAT12(0xff,auStack_6);
        }
        else {
          uVar3 = *(uint32_t *)((uint)*(byte *)((int)&(peVar15->base).entity + 3) << 2);
          auStack_6 = CONCAT12(*(undefined1 *)((int)uVar3 + 0x89),auStack_6);
        }
        uVar3 = auStack_6;
        (*(uint8_t *)((uint8_t *)&(packedByte))) = (byte)((uint3)auStack_6 >> 0x10);
        bVar19 = (byte)packedByte != -1;
        auStack_6 = uVar3;
        if (bVar19) {
          for (uVar6 = 0; uVar6 < SquareRecCount; uVar6 = uVar6 + 1) {
            aligned = ovr_alignUp4(*(int *)(uVar6 * 0x13),0,0);
            alignedX = ovr_alignUp4((peStack_1e->base).x,0,0);
            if ((aligned == alignedX) &&
               (*(uint16_t *)((uint8_t *)&SquareRecs[uVar6] + 2) == (((entity_t *)peStack_1e)->base).y)) {
              func_0x0004f930();
              if (*(uint16_t *)((uint8_t *)&SquareRecs[uVar6] + 2) == GfxRndSeed2) {
                uVar6 = ovr_alignUp4(*(int *)(uVar6 * 0x13),0,0);
                aligned = ovr_alignUp4(GfxRndSeed,0,0);
                if (uVar6 == aligned) {
                  acStack_e[(byte)packedByte] = '\x01';
                }
              }
              break;
            }
          }
        }
      }
    }
    if (AgntFlag1 != false) {
      uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
      if ((((peStack_1e->base).x < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (peStack_1e->base).x)) ||
         ((((entity_t *)peStack_1e)->base).y != GfxRndSeed2)) {
        cStack_19 = '\0';
      }
      else {
        cStack_19 = '\x01';
      }
      if ((((uint)auStack_6 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (uint)auStack_6)) ||
         (GfxRndSeed2 != entY)) {
        cStack_18 = '\0';
      }
      else {
        cStack_18 = '\x01';
      }
      if (cStack_18 != '\0' || cStack_19 != '\0') {
        if (cStack_18 == '\0') {
          ovr_ovc15_clearVisited();
          uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
          peVar15 = (entity_t *)peStack_1e;
          cStack_1a = (char)((ulong)((peVar15->base).animFrame + 0xf) / 0x10);
          if (((peVar15->base).target & 1) == 0) {
            iStack_16 = 0;
          }
          else {
            iStack_16 = (peVar15->base).target - 2;
          }
          while (cStack_1a != '\0') {
            cStack_1a = cStack_1a + -1;
            ovr_ovc15_textArena((int)count,0,0);
          }
          cStack_1a = -1;
        }
        else if (cStack_19 == '\0') {
          cStack_1a = (char)((ulong)((((entity_t *)peStack_1e)->base).animFrame + 0xf) / 0x10);
          while (cStack_1a != '\0') {
            cStack_1a = cStack_1a + -1;
            ovr_agnt_usesAgntCount6(Entities + (int)count,0);
          }
          cStack_1a = -1;
        }
        else if ((cStack_18 != '\0') && (cStack_19 != '\0')) {
          for (cStack_1a = manage_usesLitoa103(); cStack_1a != '\0'; cStack_1a = cStack_1a + -1) {
            uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
            if (((((entity_t *)peStack_1e)->base).target & 1) == 0) {
              iStack_16 = 0;
            }
            else {
              iStack_16 = (((entity_t *)peStack_1e)->base).target - 2;
            }
            pcVar17 = ovr_ovc15_textArena((int)count,0,0);
            if (((uint)pcVar17 & 0xff) == 0) break;
          }
        }
      }
    }
    do {
      count = count + 1;
      if (EntityCount <= count) {
        GGameState = 0x3c;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        func_0x0004fcda();
        GGameState = 0x3d;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        ovr_OVC23_55fe_29a2_entry();
        GGameState = 0xc;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        ovr_ovc24_removeOtherEntities(&changedFlag);
        GGameState = 0x1f;
        if (changedFlag != 0x0) {
          ovr_constr_usesBlitRect();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (uVar6 = 0; (int)uVar6 < 5; uVar6 = uVar6 + 1) {
          if (acStack_e[uVar6] != '\0') {
            ovr_ovc41_usesMiceBlitRect(uVar6);
          }
        }
        GGameState = 0xd;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        ovr_ovc24_checkStrongholds();
        GGameState = 0xe;
        mapDirty = 1;
        return (char *)0x26510;
      }
      uVar18 = (uint16_t)((ulong)Entities >> 0x10);
      peStack_1e = (entity_t *)CONCAT22(uVar18,Entities + (int)count);
      uVar6 = ovr_alignUp4(Entities[(int)count].base.destX,0,0);
      aligned = ovr_alignUp4((peStack_1e->base).x,0,0);
      if ((uVar6 == aligned) &&
         (uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10),
         (((entity_t *)peStack_1e)->base).destY == (((entity_t *)peStack_1e)->base).y)) {
        manage_usesCurSfxType32();
      }
      unaff_ES = (uint16_t)((ulong)peStack_1e >> 0x10);
      peVar15 = (entity_t *)peStack_1e;
    } while (((peVar15->base).destX == 0 && (peVar15->base).destY == 0) ||
            (*(char *)((int)&(peVar15->base).entity + 1) != '\0'));
    if ((AgntGs[(uint)(peVar15->base).gindex].flags2 & 0x4000)
        == 0) {
      packedByte = (uint)((ulong)auStack_6 >> 0x10) & 0xff;
    }
    else {
      auStack_6 = CONCAT13(1,auStack_6);
    }
    auStack_6 = CONCAT22(packedByte,(peStack_1e->base).x);
    entY = (peVar15->base).y;
    iStack_12 = CONCAT13(AgntGs[(uint)(peVar15->base).gindex].ai
                          ,iStack_12);
  } while ((peVar15->base).faction < (byte)(peVar15->base).state);
  uVar18 = ovr_ovc07_signum((peVar15->base).destX - (peStack_1e->base).x);
  iStack_12 = CONCAT22(fontSeg,uVar18);
  uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
  ySign = ovr_ovc07_signum((((entity_t *)peStack_1e)->base).destY -
                               (((entity_t *)peStack_1e)->base).y);
  if (((iStack_12 == 0) || (uVar5 = ovr_randBelow(2,0), (char)uVar5 == '\0')) ||
     (cVar4 = sub_OVC21_manage_c_23C2(), cVar4 != '\0')) {
    if ((ySign == 0) || (cVar4 = sub_OVC21_manage_c_23C2(), cVar4 != '\0')) {
      if ((iStack_12 == 0) || (cVar4 = sub_OVC21_manage_c_23C2(), cVar4 != '\0')) {
        uVar6 = ovr_ovc26_usesStExit((int)count);
        if ((char)uVar6 == '\0') {
          uVar6 = ovr_ovc26_usesRandBelow((int)count,(uint16_t)&changedFlag);
          if (((uVar6 & 0xff) == 0) &&
             (AgntGs[(uint)(((entity_t *)peStack_1e)->base).gindex].ai == '\0')) {
            manage_usesCurSfxType32();
          }
        }
        else {
          uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
          peVar15 = (entity_t *)peStack_1e;
          (peVar15->base).target =
               (byte)((int)(uint)*(byte *)((int)&(peVar15->base).owner +
                                          ((int)(uint)(peVar15->base).faction >> 2)) >>
                     (((peVar15->base).faction & 3) << 1)) & 3;
          cVar4 = func_0x0004f32d();
          if (cVar4 == '\0') {
            uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
            peVar15 = (entity_t *)peStack_1e;
            (peStack_1e->base).x =
                 (peStack_1e->base).x + (int)*(char *)((peVar15->base).target + 0x885);
            puVar1 = &(peVar15->base).y;
            *puVar1 = *puVar1 + (int)*(char *)((peVar15->base).target + 0x889);
            puVar2 = &(peVar15->base).faction;
            *puVar2 = *puVar2 + 0x1;
          }
        }
      }
      else {
        (peStack_1e->base).x = (peStack_1e->base).x + iStack_12;
        (((entity_t *)peStack_1e)->base).target = 0x2 - (char)iStack_12;
      }
    }
    else {
      uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
      puVar1 = &(((entity_t *)peStack_1e)->base).y;
      *puVar1 = *puVar1 + ySign;
      (((entity_t *)peStack_1e)->base).target = (char)ySign + 0x1;
    }
  }
  else {
    (peStack_1e->base).x = (peStack_1e->base).x + iStack_12;
    (((entity_t *)peStack_1e)->base).target = 0x2 - (char)iStack_12;
  }
  goto L_attact_3f0b_1082_1477;
}


/* 4d05:330c */

/* Applies a party/type display filter to the unit list and reports which filter is active. */

void __cdecl16far manage_applyUnitFilter(uint8_t partyIndex,uint16_t unitType,char *unitName)

{
  char *className;
  char *sayText;
  uint16_t saySeg;
  uint16_t seedCopy;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  uint16_t savedSeed;
  uint16_t savedSeed3;
  
  unitTypeFilter = (undefined1)unitType;
  partyFilter = partyIndex;
  if (ScreenMode != '\0') {
    ovr_stats_openCastlePanel();
  }
  savedSeed3 = GfxRndSeed;
  savedSeed = GfxRndSeed2;
  GfxRndSeed = Seed_2000_d1da;
  GfxRndSeed2 = Seed_2000_d1d8;
  ovr_ovc13_usesAlignUp4();
  GfxRndSeed = savedSeed3;
  GfxRndSeed2 = savedSeed;
  unitTypeFilter = 0xff;
  partyFilter = 0xff;
  if (unitType == 0xfe) {
    if (partyIndex == 0xff) {
      ovr_say((char *)"All units are displayed.",0x2410);
    }
    else {
      seedCopy = savedSeed;
      className = ovr_ovc22_className(partyIndex,0);
      saySeg = _DS;
      sayText = ovr_stsprintf(msg,(char *)CONCAT22(0x5538,_SS),
                             (char *)CONCAT22(*(uint16_t *)((uint)partyIndex * 4),
                                              (char *)0x26510),
                             ((uint16_t *)((uint)partyIndex * 4))[1],className,seedCopy);
      ovr_say(sayText,saySeg);
    }
  }
  else if (partyIndex == 0xff) {
    seedCopy = savedSeed;
    sayText = ovr_stsprintf(msg,(char *)CONCAT22(0x55b0,_SS),
                           (char *)CONCAT22((char *)unitName,(char *)0x26510),
                           (*(uint16_t *)((uint8_t *)&(unitName) + 2)));
    ovr_say(sayText,seedCopy);
  }
  else {
    seedCopy = savedSeed;
    className = ovr_ovc22_className(partyIndex,0);
    saySeg = _DS;
    sayText = ovr_stsprintf(msg,(char *)CONCAT22(0x557d,_SS),
                           (char *)CONCAT22((char *)unitName,(char *)0x26510),
                           (*(uint16_t *)((uint8_t *)&(unitName) + 2)),*(uint16_t *)((uint)partyIndex * 4),
                           ((uint16_t *)((uint)partyIndex * 4))[1],className,seedCopy);
    ovr_say(sayText,saySeg);
  }
  return;
}


