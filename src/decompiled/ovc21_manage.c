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
  char diceRoll;
  uint16_t randIdx;
  byte bStack_3;
  
  for (bStack_3 = 0; bStack_3 < 6; bStack_3 = bStack_3 + 1) {
    diceRoll = manage_rollDice('\x03','\x06');
    randIdx = ovr_randBelow(4,0);
    sheet->stats[bStack_3] = diceRoll + (char)randIdx;
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
  int lastDigit;
  char *pcStack_6;
  
  lastDigit = n % 10;
  if ((lastDigit == 1) && (n != 0xb)) {
    pcStack_6 = (char *)"st";
  }
  else if ((lastDigit == 2) && (n != 0xc)) {
    pcStack_6 = (char *)"nd";
  }
  else if ((lastDigit == 3) && (n != 0xd)) {
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

void * __cdecl16far manage_playerTitle(char_sheet_t far *sheet,...)

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

void __cdecl16far manage_usesBlitLabel2(char *text,int x,uint16_t colour)

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
      manage_usesBlitLabel2("popularity",0x7d,0xe0);
      manage_usesBlitLabel2("city blocks",0xdc,0xe0);
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
  uint choice;
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
    choice = (uint)inputResult & 0xff;
    if (choice == 0) {
      return 0;
    }
    align = (char)inputResult;
    ((char_sheet_t *)sheet)->alignment = align - 1;
    pbVar1 = &((char_sheet_t *)sheet)->statMask;
    *pbVar1 = *pbVar1 | 4;
    if (CurPartySlot != '\0') {
      return 1;
    }
    widths = *(uint16_t *)((int)&GAlignmentString.seg + choice * 4);
    ovr_drawString((char *)((far_t *)&GAlignmentString + choice)->ofs,widths,(char)widths);
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

/* Class code -> the character's animation/sprite index: classes 0..3 keep their own index,
   4/5/6 map to 0xa/8/0xb, anything else to 0.  Re-derived from the image (seven-entry jump
   table at CS:0x1288); the former body was another screen's text code. */

byte __cdecl16far chargen_switch(uint16_t index)

{
  switch (index & 0xff) {
  case 0:
  case 1:
  case 2:
  case 3:
    return (byte)index;
  case 4:
    return 0xa;
  case 5:
    return 8;
  case 6:
    return 0xb;
  default:
    return 0;
  }
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

void __cdecl16far manage_4d05_22cf_entry(byte charIndex,uint16_t minLevel,uint16_t maxLevel,
                                          uint16_t far *units,uint16_t far *population)

{
  (void)charIndex;
  (void)minLevel;
  (void)maxLevel;
  *units = 0;
  *population = 0;
  if (EntityCount != 0) {
    manage_usesEntities();
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



/* 4d05:277a */
void __cdecl16near manage_textAllProperty2(uint16_t partyArg)

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
  char apMsg[80];
  char apNum[80];
  uint16_t apNameOfs;
  uint16_t apNameSeg;
  int apUnitTotal;
  int apLvl1Value;
  int apLvl2Value;
  int apLvl3Value;
  int apLvl1Shown;
  int apLvl2Shown;
  int apLvl3Shown;
  int iVar8;
  int iVar9;
  uint16_t fontOfs;
  undefined1 uVar11;
  undefined1 fontSegHi;
  uint8_t term;
  
  far_t apList[35];
  uint8_t apSel;
  uint8_t apFlag;
  int apI;

  /* The five menu results, then one entry per structure type. */
  for (apI = 0; apI < 5; apI++) {
    apList[apI] = ManageResultPtrs[apI];
  }
  for (apI = 0; apI < 30; apI++) {
    apList[5 + apI] = GStructures[apI].name;
  }
  apSel = 2;
  manage_openTalkWindow();
  apFlag = 0;
L_menuLoop:
  if (((apSel != '\x02') && (apSel != '\x03')) &&
     (apSel != '\x04')) {
  goto L_menuTail;
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
  if (partyArg == -1) { ovr_blitLabel((char far *)"All property.",(byte far *)MK_FP(Font02.seg,Font02.ofs),0xde,0x50);
  }
  else {
    puVar2 = (uint16_t *)((uint)partyArg * 4);
    puVar6 = (uint8_t *)*puVar2;
    apNameSeg = puVar2[1];
    apNameOfs =(uint16_t)( puVar6);
    uVar7 = 0x50;
    term = 0xde;
    uVar11 = (undefined1)Font02.seg;
    fontSegHi = (undefined1)(Font02.seg >> 8);
    fontOfs = Font02.ofs;
    iVar9 = ovr_ovc45_compute9((char *)((int)&apNum),
                               (char *)CONCAT22(apNameOfs,_SS),
                               (char *)CONCAT22(Font02.ofs,(char *)apNameSeg),
                               Font02.seg,'i',0x69,3);
    pvVar3 = manage_playerTitle((char_sheet_t *)apNameOfs,
                                apNameSeg,(char)iVar9,puVar6);
    numText = ovr_stsprintf((char *)((int)&apMsg),(char *)CONCAT22(0x52a1,_SS),
                           (char *)CONCAT22(pvVar3,(char *)0x26510),puVar6);
  ovr_blitLabel((char far *)numText,(byte far *)MK_FP(Font02.seg,Font02.ofs),0xde,0x50);
  }
  TextBlitY = TextBlitY + 0xc;
  TextBlitX = 0x11;
  ovr_blitLabel((char far *)"Buildings",(byte far *)MK_FP(Font02.seg,Font02.ofs),0xde,0xe0);
  manage_usesBlitLabel2("Total",100,0xe0);
  manage_usesBlitLabel2("Level 1",0x8c,0xe0);
  manage_usesBlitLabel2("Level 2",0xb4,0xe0);
  manage_usesBlitLabel2("Level 3",0xdc,0xe0);
  TextBlitY = TextBlitY + 0xc;
  if (apSel == '\x04') {
    iVar9 = 0x1a;
  }
  else if (apSel == '\x03') {
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
  ovr_blitLabel((char far *)MK_FP(GStructures[iVar8 + iVar9].name.seg,GStructures[iVar8 + iVar9].name.ofs),(byte far *)MK_FP(Font02.seg,Font02.ofs),0xde,0xe0);
      lVar1 = (long)(iVar8 + iVar9) * 6;
      uVar7 = (uint16_t)((ulong)lVar1 >> 0x10);
      iVar4 = manage_usesGUnitCount
                        (partyArg,(&((unk01_t *)GStructures)->type)[(int)lVar1],
                         (int *)CONCAT22(_SS,(int *)((int)&apLvl1Value)),
                         (int *)CONCAT22(_SS,(int *)((int)&apLvl2Value)),
                         (int *)CONCAT22(_SS,(int *)((int)&apUnitTotal)),
                         (int *)CONCAT22(_SS,(int *)((int)&apLvl3Value)));
      apUnitTotal = iVar4;
      if (apLvl3Value == 0) {
        iVar4 = 100;
        uVar11 = (undefined1)apUnitTotal;
        numText = litoa10((char *)((int)&apNum),
                         CONCAT13((char)((uint)apUnitTotal
                                        >> 8),CONCAT12(uVar11,_SS)),uVar11,0);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
      }
      else {
        iVar4 = 100;
        numText = ovr_stsprintf((char *)((int)&apMsg));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
      }
      lVar1 = (long)(iVar8 + iVar9) * 6;
      uVar7 = (uint16_t)((ulong)lVar1 >> 0x10);
      if (*(char *)((int)&GStructures[0].pad + (int)lVar1) != '\0') {
        if (apLvl1Shown == 0) {
          iVar4 = 0x8c;
          uVar11 = (undefined1)apLvl1Value;
          numText = litoa10((char *)((int)&apNum),
                           CONCAT13((char)((uint)apLvl1Value >> 8),
                                    CONCAT12(uVar11,_SS)),uVar11,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
        }
        else {
          iVar4 = 0x8c;
          numText = ovr_stsprintf((char *)((int)&apMsg));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
        }
        if (apLvl2Shown == 0) {
          iVar4 = 0xb4;
          uVar11 = (undefined1)apLvl2Value;
          numText = litoa10((char *)((int)&apNum),
                           CONCAT13((char)((uint)apLvl2Value >> 8),
                                    CONCAT12(uVar11,_SS)),uVar11,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
        }
        else {
          iVar4 = 0xb4;
          numText = ovr_stsprintf((char *)((int)&apMsg));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
        }
        if (apLvl3Shown == 0) {
          iVar4 = 0xdc;
          uVar11 = (undefined1)apUnitTotal;
          numText = litoa10((char *)((int)&apNum),
                           CONCAT13((char)((uint)apUnitTotal >> 8),
                                    CONCAT12(uVar11,_SS)),uVar11,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
        }
        else {
          iVar4 = 0xdc;
          numText = ovr_stsprintf((char *)((int)&apMsg));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,numText)),iVar4);
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
    iVar8 = iVar8 + 1;
  }
L_menuTail:
  if (apSel == 0x5) {
    manage_highlightStructures(partyArg,0xfe);
  }
  else {
    manage_highlightStructures(partyArg,
        (uint16_t)*(uint8_t *)((uint16_t)&menuHighlightTable[2].seg + 1 +
                               (uint16_t)apSel * 6));
  }
  keyboardInputMode = 1;
  CurSfxType3 = 0x3c;
  (*(uint8_t *)((uint8_t *)&(entries.seg))) = (char)_SS;
  entries.ofs = (uint16_t)apList;
  (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = (char)((uint)_SS >> 8);
  uVar7 = ovr_ovc28_usesUiInputText
                    (entries,0x23,far_from_u32((uint32_t)(0x0)),(uint8_t *)((int)&apFlag),0,
                     (char)(uint8_t *)((int)&apFlag));
  *(undefined1 *)((int)&apSel) = (char)uVar7;
  keyboardInputMode = 0;
  if (((apSel != '\0') && (apSel != '\x01')) &&
     (apSel != -2)) {
  goto L_menuLoop;
  }
  if ((ScreenMode == '\0') && (apSel != -2)) {
    manage_openTalkWindow();
  }
  if (apSel == -2) {
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
  
  manage_usesBlitLabel2((char *)CONCAT22(textSeg,in_stack_00000002),uStack0006,0xe0);
  manage_usesBlitLabel2("Level 3",0xdc,0xe0);
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
    manage_textAllProperty2(0);   /* GUESS: the duplicate fragment below has no frame argument to forward */
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
    manage_textAllProperty2(0);   /* GUESS: the duplicate fragment below has no frame argument to forward */
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

/* "Total population" panel for one leader: a filtered list of level bands (Done /
   Summary / All levels plus one entry per band), a header line naming the leader, a
   UNITS and a POPULATION column per band, and a menu returning the chosen entry.
   Re-derived from the image; the former body carried another screen's text code. */

char * __cdecl16far manage_textTotalPopulation(byte charIndex,short arg6,char_sheet_t *sheet)

{
  far_t bands[24];
  far_t items[16];
  uint8_t bandCounts[7];
  uint8_t count;
  uint8_t extraBands;
  uint8_t sel;
  uint8_t result;
  uint8_t cls;
  char_sheet_t far *sheetPtr;
  char bandBuf[120];
  char textBuf[56];
  far_t list;
  uint16_t units;
  uint16_t population;
  uint16_t retVal;
  int itemCount;
  int bandIdx;
  int n;

  (void)arg6;
  (void)sheet;
  /* bands[12..23] are the twelve level labels; bands[0..11] the per-class continua
     (class 4, class 5, class 6 - four entries each, the last of 5 and 6 null). */
  memcpy(&bands[12],LevelBandLabels,0x30);
  memcpy(&bands[0],&LevelBandLabels[12],8 * 4);
  memcpy(&bands[8],LevelRangeLabels,4 * 4);
  memcpy(bandCounts,levelRangeTails,7);
  extraBands = 0;
  cls = 0;
  if (charIndex == 0xff) {
    count = 0xc;
  }
  else {
    cls = GLeaderSheets[charIndex]->cls;
    count = bandCounts[cls];
    if (cls >= 4) {
      extraBands = 1;
    }
  }
  items[0].ofs = (uint16_t)s_Done_2410_50fb;
  items[0].seg = _DS;
  items[1].ofs = (uint16_t)s_summary;
  items[1].seg = _DS;
  items[2].ofs = (uint16_t)s_all_levels;
  items[2].seg = _DS;
  itemCount = 3;
  for (n = 0; n < count; n++) {
    if (n >= 5 && extraBands) {
      items[itemCount] = bands[(cls - 4) * 4 + (n - 5)];
    }
    else {
      items[itemCount] = bands[12 + n];
    }
    itemCount = itemCount + 1;
  }
  sel = 2;
  manage_openTalkWindow();
  result = 0;
  for (;;) {
    if (sel == 2) {
      if (ScreenMode == 0) {
        manage_openTalkWindow();
      }
      TextBlitY = 0xc;
      TextBlitX = 0x11;
      if (charIndex == 0xff) {
        ovr_blitLabel((char far *)MK_FP(_DS,(uint16_t)s_total_population),
                      (byte far *)MK_FP(Font02.seg,Font02.ofs),0xde,0x50);
      }
      else {
        sheetPtr = GLeaderSheets[charIndex];
        ovr_stsprintf((char far *)MK_FP(_SS,textBuf),
                      (char far *)MK_FP(_DS,(uint16_t)s_s_population_loyal_to_s_s),
                      (char far *)MK_FP(GUnitDescriptions[cls].seg,GUnitDescriptions[cls].ofs),
                      (char far *)MK_FP(_DS,(uint16_t)manage_playerTitle(sheetPtr)),
                      (char far *)ovr_ovc45_compute9((char far *)MK_FP(_SS,bandBuf),
                                                    (char far *)sheetPtr,
                                                    (char far *)MK_FP(Font02.seg,Font02.ofs),
                                                    0x4b,3));
        ovr_blitLabel((char far *)MK_FP(_SS,textBuf),
                      (byte far *)MK_FP(Font02.seg,Font02.ofs),0xde,0x50);
      }
      TextBlitY = TextBlitY + 0xc;
      TextBlitX = (uint16_t)(0x89 -
                  (int)ovr_font_textWidth((char far *)MK_FP(_DS,(uint16_t)s_units),
                                          (char far *)MK_FP(Font02.seg,Font02.ofs)));
      ovr_blitLabel((char far *)MK_FP(_DS,(uint16_t)s_units),
                    (byte far *)MK_FP(Font02.seg,Font02.ofs),0xde,0xe0);
      TextBlitX = (uint16_t)(0xd4 -
                  (int)ovr_font_textWidth((char far *)MK_FP(_DS,(uint16_t)s_population),
                                          (char far *)MK_FP(Font02.seg,Font02.ofs)));
      ovr_blitLabel((char far *)MK_FP(_DS,(uint16_t)s_population),
                    (byte far *)MK_FP(Font02.seg,Font02.ofs),0xde,0xe0);
      TextBlitY = TextBlitY + 0xc;
      for (n = 0; n < count; n++) {
        TextBlitX = 0x11;
        if (n >= 5 && extraBands) {
          bandIdx = (cls - 4) * 4 + (n - 5);
        }
        else {
          bandIdx = 12 + n;
        }
        ovr_blitLabel((char far *)MK_FP(bands[bandIdx].seg,bands[bandIdx].ofs),
                      (byte far *)MK_FP(Font02.seg,Font02.ofs),0x13f,0xe0);
        manage_4d05_22cf_entry(charIndex,LevelRangeMin[n],LevelRangeMax[n],
                               &units,&population);
        ovr_stsprintf((char far *)MK_FP(_SS,textBuf),
                      (char far *)MK_FP(_DS,(uint16_t)s__d_2410_4cd1),(uint16_t)units);
        TextBlitX = (uint16_t)(0x89 -
                    (int)ovr_font_textWidth((char far *)MK_FP(_SS,textBuf),
                                            (char far *)MK_FP(Font02.seg,Font02.ofs)));
        ovr_blitLabel((char far *)MK_FP(_SS,textBuf),
                      (byte far *)MK_FP(Font02.seg,Font02.ofs),0xde,0x50);
        ovr_stsprintf((char far *)MK_FP(_SS,textBuf),
                      (char far *)MK_FP(_DS,(uint16_t)s__d_2410_4cd1),(uint16_t)population);
        TextBlitX = (uint16_t)(0xd4 -
                    (int)ovr_font_textWidth((char far *)MK_FP(_SS,textBuf),
                                            (char far *)MK_FP(Font02.seg,Font02.ofs)));
        ovr_blitLabel((char far *)MK_FP(_SS,textBuf),
                      (byte far *)MK_FP(Font02.seg,Font02.ofs),0xde,0x50);
        TextBlitY = TextBlitY + 0xc;
      }
    }
    else {
      keyboardInputMode = 1;
      if (sel == 3) {
        manage_applyUnitFilter(charIndex,0xfe,
                               (char far *)MK_FP(items[sel - 1].seg,items[sel - 1].ofs));
      }
      else {
        manage_applyUnitFilter(charIndex,(uint16_t)(sel - 4),
                               (char far *)MK_FP(items[sel - 1].seg,items[sel - 1].ofs));
      }
    }
    CurSfxType3 = 0x3c;
    list.ofs = (uint16_t)items;
    list.seg = _SS;
    retVal = (uint16_t)ovr_ovc28_usesUiInputText(list,(uint16_t)itemCount,0,0,
                                                (uint8_t far *)&result);
    sel = (uint8_t)retVal;
    keyboardInputMode = 0;
    if (sel == 0 || sel == 1 || sel == 0xfe) {
      break;
    }
  }
  if (sel == 0xfe) {
    Cancelled = 1;
  }
  return (char *)(uint)retVal;
}


/* 4d05:330c */

/* Applies a party/type display filter to the unit list and reports which filter is active. */

void __cdecl16far manage_applyUnitFilter(uint8_t partyIndex,uint16_t unitType,char far *unitName)

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


