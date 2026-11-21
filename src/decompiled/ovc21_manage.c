/*
 * ovc21_manage.c - recovered from STRONG.EXE
 * memory block: OVC21_manage.c
 * range: 4d05:0000 - 4d05:381f
 * functions: 39
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
    if ((*(char *)((int)*(undefined4 *)(iVar1 << 2) + 0x3d) != '\0') &&
       (*(char *)((int)*(undefined4 *)(iVar1 << 2) + 0x89) != -1)) {
      ((uint8_t *)MenuItemEnabled)[*(byte *)((int)*(undefined4 *)(iVar1 << 2) + 0x89)] =
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
  uint16_t unaff_SS;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t handle;
  uint8_t palette;
  stg_tmp_t *psStack_6;
  
  mapViewActive = 0xff;
  ScreenMode = 1;
  handle.seg = talkwin9Cut5Seg;
  handle.ofs = talkwin9Cut5Ofs;
  psStack_6 = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette(psStack_6->cmap,in_DX,&palette,unaff_SS);
  ovr_driver_fillRect(0xc,7,0xde,0x96,0xec,0xa000);
  ovr_vgaSetPalette8bit(&palette);
  gfx.seg = talkwin9Cut1Seg;
  gfx.ofs = talkwin9Cut1Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)(BlitRects + 1),0x10,true);
  gfx_00.seg = talkwin9Cut2Seg;
  gfx_00.ofs = talkwin9Cut2Ofs;
  ovr_blitGfxRect(gfx_00,0,0,(brect_t *)(BlitRects + 1),0x10,true);
  gfx_01.seg = talkwin9Cut3Seg;
  gfx_01.ofs = talkwin9Cut3Ofs;
  ovr_blitGfxRect(gfx_01,0,0,(brect_t *)(BlitRects + 1),0x10,true);
  return;
}



/* 4d05:0166 */

/* Blits the talkwin9Cut1 window graphic at the origin, clipped by panelClipRect. */

void __cdecl16far manage_blitTalkWindow(void)

{
  uint16_t unaff_SS;
  far_t gfx;
  far_t dst;
  uint8_t rect;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&rect;
  F_SCOPY(far_from_u32((uint32_t)(0x2410493b)),dst);
  gfx.seg = talkwin9Cut1Seg;
  gfx.ofs = talkwin9Cut1Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)&rect,(uint8_t)unaff_SS,true);
  return;
}



/* 4d05:01a3 */

/* Rolls count dice of the given number of sides and returns the sum. */

char __cdecl16far manage_rollDice(char count,char sides,...)

{
  uint16_t uVar1;
  undefined1 uStack_3;
  
  uStack_3 = '\0';
  while (count != '\0') {
    uVar1 = ovr_randBelow((uint)(byte)sides);
    uStack_3 = (char)uVar1 + uStack_3 + '\x01';
    count = count + -1;
  }
  return uStack_3;
}



/* 4d05:01d4 */

/* Rolls the six stats (3d6 + randBelow(4), capped at 18) and marks statMask bit 5. */

void __cdecl16far manage_rollStats(char_sheet_t *sheet,...)

{
  char cVar1;
  uint16_t uVar2;
  undefined2 in_stack_00000006;
  byte bStack_3;
  
  for (bStack_3 = 0; bStack_3 < 6; bStack_3 = bStack_3 + 1) {
    cVar1 = manage_rollDice('\x03','\x06');
    uVar2 = ovr_randBelow(4);
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

char * __cdecl16far manage_compute1(int n,...)

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

byte __cdecl16far manage_compute2(char_sheet_t *sheet)

{
  byte bVar1;
  char_sheet_t *pcVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)sheet >> 0x10);
  pcVar2 = (char_sheet_t *)sheet;
  if ((pcVar2->cls == 4) && (0xc < pcVar2->race)) {
    bVar1 = 0xc;
  }
  else if ((pcVar2->cls == 5) && (10 < pcVar2->race)) {
    bVar1 = 10;
  }
  else if ((pcVar2->cls == 6) && (8 < pcVar2->race)) {
    bVar1 = 8;
  }
  else {
    bVar1 = pcVar2->race;
  }
  return bVar1;
}



/* 4d05:02f1 */

/* [R7] body shape: compute */

byte __cdecl16far manage_compute3(char_sheet_t *sheet)

{
  byte bVar1;
  char_sheet_t *pcVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)sheet >> 0x10);
  pcVar2 = (char_sheet_t *)sheet;
  if ((pcVar2->cls == 4) && (0xb < pcVar2->race)) {
    bVar1 = 1;
  }
  else if ((pcVar2->cls == 5) && (9 < pcVar2->race)) {
    bVar1 = 1;
  }
  else if ((pcVar2->cls == 6) && (7 < pcVar2->race)) {
    bVar1 = 1;
  }
  else {
    bVar1 = 0;
  }
  return bVar1;
}



/* 4d05:0340 */

/* [R7] body shape: compute */

byte __cdecl16far manage_compute4(char_sheet_t *sheet)

{
  byte bVar1;
  char_sheet_t *pcVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)sheet >> 0x10);
  pcVar2 = (char_sheet_t *)sheet;
  if ((pcVar2->cls == 4) && (0xb < pcVar2->race)) {
    bVar1 = pcVar2->race + 0x37;
  }
  else if ((pcVar2->cls == 5) && (9 < pcVar2->race)) {
    bVar1 = pcVar2->race + 0x39;
  }
  else if ((pcVar2->cls == 6) && (7 < pcVar2->race)) {
    bVar1 = pcVar2->race + 0x39;
  }
  else {
    bVar1 = 0x30;
  }
  return bVar1;
}



/* 4d05:03a4 */

/* Returns the player title for a character sheet from GPlayerTitles (indexed by gender and class).
    */

void * __cdecl16far manage_playerTitle(char_sheet_t *sheet,...)

{
  char *pcVar1;
  uint16_t unaff_SS;
  undefined2 in_stack_00000006;
  far_t dst;
  uint8_t titlesMap;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&titlesMap;
  F_SCOPY(far_from_u32((uint32_t)(0x241049a5)),dst);
  if (sheet->cls == 0xff) {
    pcVar1 = (char *)"Lawful" + 6;
  }
  else if (sheet->titleIndex == 0) {
    if ((sheet->race < 9) && ((sheet->cls != 6 || (sheet->race < 8)))) {
      pcVar1 = (char *)"Lawful" + 6;
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
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = 0;
  for (iVar2 = 0; iVar2 < (int)(uint)GLeaderCount; iVar2 = iVar2 + 1) {
    if ((*(char *)((int)*(undefined4 *)(iVar2 << 2) + 0x3d) != '\0') &&
       (*(char *)((int)*(undefined4 *)(iVar2 << 2) + 0x3f) == '\0')) {
      uVar3 = uVar3 + *(byte *)((int)*(undefined4 *)(iVar2 << 2) + 0x84);
      bVar1 = bVar1 + 1;
    }
  }
  if (bVar1 != 0) {
    uVar3 = uVar3 / bVar1;
  }
  return uVar3;
}



/* 4d05:04c6 */

/* Right-aligns text at x (TextBlitX = x - text width) and blits it with Font02. */

void __cdecl16far manage_blitLabelRight(char *text,int x)

{
  int iVar1;
  
  iVar1 = ovr_font_textWidth((char *)text,(char *)CONCAT22(Font02.ofs,(*(uint16_t *)((uint8_t *)&(text) + 2))),Font02.seg);
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
  
  iVar1 = ovr_font_textWidth((char *)text,(char *)CONCAT22(Font02.ofs,(*(uint16_t *)((uint8_t *)&(text) + 2))),Font02.seg);
  TextBlitX = x - iVar1;
  ovr_blitLabel((char *)text,(uint8_t *)CONCAT22(Font02.ofs,(*(uint16_t *)((uint8_t *)&(text) + 2))),Font02.seg,0xde,
                CONCAT11(0x24,in_stack_0000000a));
  return;
}



/* 4d05:056e */

/* [R4] calls litoa10 */

void __cdecl16far manage_usesLitoa10(char_sheet_t *sheet)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  undefined2 uVar4;
  uint uVar5;
  uint8_t *in_DX;
  int iVar6;
  char_sheet_t *sheet_00;
  int iVar7;
  uint16_t uVar8;
  char *pcVar9;
  char *unaff_SS;
  uint16_t uVar10;
  undefined1 uVar11;
  uint8_t uVar12;
  undefined1 uVar13;
  char textBuf [120];
  uint8_t msg;
  byte bStack_6;
  byte bStack_5;
  int iStack_4;
  
  pcVar9 = (char *)((ulong)sheet >> 0x10);
  sheet_00 = (char_sheet_t *)sheet;
  bStack_6 = sheet_00->statMask;
  if ((bStack_6 & 0x20) != 0) {
    uVar8 = 0x1b;
    for (iVar7 = 0; iVar7 < 6; iVar7 = iVar7 + 1) {
      TextBlitX = 0x15;
      TextBlitY = uVar8;
      ovr_blitLabel((char *)((far_t *)GStatsLabels + iVar7)->ofs,
                    (uint8_t *)
                    CONCAT22(Font02.ofs,
                             (uint8_t *)*(undefined2 *)((int)&GStatsLabels[0].seg + iVar7 * 4)),
                    Font02.seg,0xde,0xde,0xe0);
      ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,unaff_SS),
                    (char *)(ulong)CONCAT12(sheet_00->stats[iVar7],0x2410),0x10);
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)unaff_SS >> 8),CONCAT12((char)unaff_SS,&msg)),0x31);
      uVar8 = uVar8 + 10;
    }
  }
  TextBlitY = 0xc;
  if ((bStack_6 & 2) != 0) {
    TextBlitX = 0x15;
    uVar11 = (undefined1)Font02.ofs;
    uVar13 = (undefined1)(Font02.ofs >> 8);
    pcVar3 = manage_playerTitle(sheet_00,pcVar9,uVar11,(char)Font02.seg);
    iStack_4 = ovr_font_textWidth(pcVar3,(char *)CONCAT13(uVar13,CONCAT12(uVar11,in_DX)));
    uVar11 = 0x50;
    uVar12 = 0xde;
    cVar1 = (char)(0x7d - iStack_4);
    uVar8 = Font02.ofs;
    uVar10 = Font02.seg;
    iVar7 = ovr_ovc45_compute9((char *)&msg,(char *)CONCAT22(sheet_00,unaff_SS),
                               (char *)CONCAT22(Font02.ofs,pcVar9),Font02.seg,cVar1,cVar1,3);
    pvVar2 = manage_playerTitle(sheet_00,pcVar9,(char)iVar7,in_DX);
    pcVar3 = ovr_stsprintf(textBuf,(char *)CONCAT22(0x4cd4,unaff_SS),
                           (char *)CONCAT22(pvVar2,(char *)"puppetmaker" + 3),in_DX);
    ovr_blitLabel(pcVar3,(uint8_t *)CONCAT22(uVar8,in_DX),uVar10,uVar12,uVar12,uVar11);
  }
  if ((bStack_6 & 4) != 0) {
    uVar11 = 0x50;
    uVar12 = 0xde;
    uVar8 = Font02.ofs;
    uVar10 = Font02.seg;
    pcVar3 = ovr_fmVsprintf("%s ",(char *)CONCAT22(*(undefined2 *)
                                                    ((int)&GAlignmentsNames[0].seg +
                                                    (uint)sheet_00->alignment * 4),
                                                   (char *)((far_t *)GAlignmentsNames +
                                                           sheet_00->alignment)->ofs));
    ovr_blitLabel(pcVar3,(uint8_t *)CONCAT22(uVar8,in_DX),uVar10,uVar12,uVar12,uVar11);
  }
  if ((bStack_6 & 1) != 0) {
    uVar11 = 0x50;
    uVar12 = 0xde;
    iVar7 = (uint)sheet_00->cls * 4;
    in_DX = (uint8_t *)((char *)"puppetmaker" + 3);
    uVar8 = Font02.ofs;
    uVar10 = Font02.seg;
    pcVar3 = ovr_fmVsprintf("%s",(char *)CONCAT22(*(undefined2 *)(iVar7 + 0xed),
                                                  (char *)*(undefined2 *)(iVar7 + 0xeb)));
    ovr_blitLabel(pcVar3,(uint8_t *)CONCAT22(uVar8,in_DX),uVar10,uVar12,uVar12,uVar11);
  }
  TextBlitY = TextBlitY + 10;
  if (((bStack_6 & 0x40) != 0) || (DebugVerbose != false)) {
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Population",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0x7d;
    uVar13 = 0;
    pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,unaff_SS),
                           (char *)CONCAT13((char)((uint)sheet_00->population >> 8),
                                            CONCAT12((char)sheet_00->population,0x2410)));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitX = 0x82;
    ovr_ovc22_textRingProt(sheet_00->charIndex);
    ovr_blitLabel((char *)"Food prod.",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    pcVar3 = litoa10(textBuf,(long)CONCAT22(sheet_00->foodProd,unaff_SS),0);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x82;
    ovr_blitLabel((char *)"Food stored",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    pcVar3 = litoa10(textBuf,(long)CONCAT22((int)sheet_00->foodStored,unaff_SS),
                     (char)*(undefined2 *)((int)&sheet_00->foodStored + 2));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Housing",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0x7d;
    uVar13 = 0;
    pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,unaff_SS),
                           (char *)CONCAT13((char)((uint)sheet_00->housing >> 8),
                                            CONCAT12((char)sheet_00->housing,0x2410)));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitX = 0x82;
    ovr_blitLabel((char *)"Food storage",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    pcVar3 = litoa10(textBuf,(long)CONCAT22((int)sheet_00->foodStorage,unaff_SS),
                     (char)*(undefined2 *)((int)&sheet_00->foodStorage + 2));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 0xf;
    if (sheet_00->maxTrade != 0) {
      TextBlitX = 0x37;
      if (sheet_00->foodSold < 0) {
        ovr_blitLabel((char *)"Food sold",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                      Font02.seg,0xde,0xde,0xe0);
        uVar11 = 0x7d;
        uVar13 = 0;
        iVar7 = -sheet_00->foodSold;
        iVar6 = iVar7 >> 0xf;
        pcVar3 = litoa10(textBuf,(long)CONCAT22(iVar7,unaff_SS),(char)(iVar7 >> 0xf));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
                   CONCAT11(uVar13,uVar11));
      }
      else {
        ovr_blitLabel((char *)"Food bought",
                      (uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),Font02.seg,0xde,0xde
                      ,0xe0);
        uVar11 = 0x7d;
        uVar13 = 0;
        iVar7 = sheet_00->foodSold;
        iVar6 = iVar7 >> 0xf;
        pcVar3 = litoa10(textBuf,(long)CONCAT22(iVar7,unaff_SS),(char)(iVar7 >> 0xf));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
                   CONCAT11(uVar13,uVar11));
      }
      TextBlitX = 0x82;
      ovr_blitLabel((char *)"Max. trade",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                    Font02.seg,0xde,0xde,0xe0);
      uVar11 = 0xdc;
      uVar13 = 0;
      pcVar3 = litoa10(textBuf,(long)CONCAT22(sheet_00->maxTrade,unaff_SS),0);
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
                 CONCAT11(uVar13,uVar11));
    }
    TextBlitY = TextBlitY + 0xf;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Income",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    iVar7 = sheet_00->income;
    iVar6 = iVar7 >> 0xf;
    pcVar3 = litoa10((char *)&msg,(long)CONCAT22(iVar7,unaff_SS),(char)(iVar7 >> 0xf));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Gold",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    pcVar3 = litoa10((char *)&msg,(long)CONCAT22((int)sheet_00->gold,unaff_SS),
                     (char)*(undefined2 *)((int)&sheet_00->gold + 2));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Vault storage",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    pcVar3 = litoa10((char *)&msg,(long)CONCAT22((int)sheet_00->vaultStorage,unaff_SS),
                     (char)*(undefined2 *)((int)&sheet_00->vaultStorage + 2));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Fund Access",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    uVar4 = ovr_ovc45_usesLDIV_at_(sheet_00->charIndex);
    pcVar3 = litoa10(textBuf,(long)CONCAT22(uVar4,unaff_SS),(char)iVar6);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Common fund",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    pcVar3 = litoa10(textBuf,(long)CONCAT22(GPopulationLo,unaff_SS),(char)GPopulationHi);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
               CONCAT11(uVar13,uVar11));
    bStack_5 = manage_findFirstLeader();
    TextBlitY = TextBlitY + 0xf;
    if (((sheet_00->titleIndex != 0) && (bStack_5 != 0xff)) &&
       (uVar4 = 0x217a, *(byte *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x86) < 9)) {
      manage_usesBlitLabel2("popularity",0x7d);
      manage_usesBlitLabel2("city blocks",0xdc);
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x11;
      ovr_blitLabel((char *)"Current",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                    Font02.seg,0xde,0xde,0xe0);
      uVar11 = 0x7d;
      uVar13 = 0;
      uVar5 = manage_usesGLeaderCount();
      pcVar9 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4d8b,unaff_SS),
                             (char *)CONCAT13((char)(uVar5 >> 8),CONCAT12((char)uVar5,0x2410)));
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar9)),
                 CONCAT11(uVar13,uVar11));
      uVar11 = 0xdc;
      uVar13 = 0;
      pcVar9 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,unaff_SS),
                             (char *)CONCAT13((char)((uint)GPromotableCount >> 8),
                                              CONCAT12((char)GPromotableCount,0x2410)));
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar9)),
                 CONCAT11(uVar13,uVar11));
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x11;
      ovr_blitLabel((char *)"to promote",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                    Font02.seg,0xde,0xde,0xe0);
      uVar11 = 0x7d;
      uVar13 = 0;
      cVar1 = ovr_season_usesDifficulty();
      pcVar9 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4d8b,unaff_SS),
                             (char *)(ulong)CONCAT12(cVar1,0x2410));
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar9)),
                 CONCAT11(uVar13,uVar11));
      uVar11 = 0xdc;
      uVar13 = 0;
      iVar7 = ovr_season_usesGPromotableCount2();
      pcVar9 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,unaff_SS),
                             (char *)CONCAT13((char)((uint)iVar7 >> 8),CONCAT12((char)iVar7,0x2410))
                            );
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar9)),
                 CONCAT11(uVar13,uVar11));
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

/* WARNING: Variable defined which should be unmapped: menuItems */

undefined2 __cdecl16far abilitiesDlg(char_sheet_t *sheet)

{
  uint16_t uVar1;
  far_t dst;
  far_t dst_00;
  byte bVar2;
  undefined1 extraout_AH;
  uint8_t *puVar3;
  char *pcVar4;
  uint uVar5;
  uint16_t unaff_SS;
  far_t entries;
  far_t entries_00;
  undefined1 uVar6;
  undefined1 uVar7;
  uint8_t menuItems;
  undefined2 auStack_28 [7];
  char cStack_1a;
  byte bStack_19;
  uint8_t statIndex;
  byte abStack_17 [5];
  uint8_t classStatMap2;
  uint8_t classStatMap1;
  
  uVar6 = (undefined1)unaff_SS;
  uVar7 = (undefined1)(unaff_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = uVar6;
  dst.ofs = (uint16_t)&classStatMap1;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar7;
  F_SCOPY(far_from_u32((uint32_t)(0x241049dd)),dst);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = uVar6;
  dst_00.ofs = (uint16_t)&classStatMap2;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = uVar7;
  F_SCOPY(far_from_u32((uint32_t)(0x241049e4)),dst_00);
  while( true ) {
    _fsetmem((void *)CONCAT13(uVar7,CONCAT12(uVar6,&menuItems)),0x10,0);
    auStack_28[0] = 0x2410;
    menuItems = 0x4d9b;
    bStack_19 = 1;
    bVar2 = manage_statSelectable
                      ((&classStatMap1)[((char_sheet_t *)sheet)->cls],
                       (char_sheet_t *)CONCAT22(0x4d9b,(*(uint16_t *)((uint8_t *)&(sheet) + 2))));
    if (bVar2 != 0) {
      abStack_17[bStack_19] = (&classStatMap1)[((char_sheet_t *)sheet)->cls];
      uVar1 = ((far_t *)GStatsLabels + (&classStatMap1)[((char_sheet_t *)sheet)->cls])->ofs;
      uVar5 = (uint)bStack_19;
      auStack_28[uVar5 * 2] =
           *(undefined2 *)
            ((int)&GStatsLabels[0].seg + (uint)(&classStatMap1)[((char_sheet_t *)sheet)->cls] * 4);
      *(uint16_t *)(&menuItems + uVar5 * 4) = uVar1;
      bStack_19 = bStack_19 + 1;
    }
    puVar3 = &classStatMap2 + ((char_sheet_t *)sheet)->cls;
    if (*puVar3 != 0xff) {
      bVar2 = manage_statSelectable
                        ((&classStatMap2)[((char_sheet_t *)sheet)->cls],
                         (char_sheet_t *)CONCAT22(menuItems,(*(uint16_t *)((uint8_t *)&(sheet) + 2))));
      puVar3 = (uint8_t *)CONCAT11(extraout_AH,bVar2);
      if (bVar2 != 0) {
        abStack_17[bStack_19] = (&classStatMap2)[((char_sheet_t *)sheet)->cls];
        puVar3 = (uint8_t *)
                 *(undefined2 *)
                  ((int)&GStatsLabels[0].seg +
                  (uint)(&classStatMap2)[((char_sheet_t *)sheet)->cls] * 4);
        uVar1 = ((far_t *)GStatsLabels + (&classStatMap2)[((char_sheet_t *)sheet)->cls])->ofs;
        uVar5 = (uint)bStack_19;
        auStack_28[uVar5 * 2] = puVar3;
        *(uint16_t *)(&menuItems + uVar5 * 4) = uVar1;
        bStack_19 = bStack_19 + 1;
      }
    }
    if (bStack_19 == 1) {
      return CONCAT11((char)((uint)puVar3 >> 8),1);
    }
    ovr_drawString((char *)
                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                   ,0x2410,0x10);
    entries.seg = unaff_SS;
    entries.ofs = (uint16_t)&menuItems;
    pcVar4 = ovr_uiInputText(entries,(uint)bStack_19,far_from_u32((uint32_t)(0x0)),0x0,0);
    cStack_1a = (char)pcVar4;
    if (cStack_1a == '\0') {
      return 0;
    }
    if (cStack_1a == '\x01') break;
    abStack_17[0] = abStack_17[((uint)pcVar4 & 0xff) - 1];
    ovr_drawString((char *)"Select ability to adjust downwards by two points.",0x2410,0x10);
    _fsetmem((void *)CONCAT13(uVar7,CONCAT12(uVar6,&menuItems)),0x10,0);
    auStack_28[0] = 0x2410;
    menuItems = 0x4e3a;
    bStack_19 = 1;
    for (statIndex = 0x0; statIndex < 3; statIndex = statIndex + 0x1) {
      if ((10 < ((char_sheet_t *)sheet)->stats[statIndex]) && (abStack_17[0] != statIndex)) {
        abStack_17[bStack_19] = statIndex;
        uVar1 = ((far_t *)GStatsLabels + statIndex)->ofs;
        uVar5 = (uint)bStack_19;
        auStack_28[uVar5 * 2] = *(undefined2 *)((int)&GStatsLabels[0].seg + (uint)statIndex * 4);
        *(uint16_t *)(&menuItems + uVar5 * 4) = uVar1;
        bStack_19 = bStack_19 + 1;
      }
    }
    entries_00.seg = unaff_SS;
    entries_00.ofs = (uint16_t)&menuItems;
    pcVar4 = ovr_uiInputText(entries_00,(uint)bStack_19,far_from_u32((uint32_t)(0x0)),0x0,0);
    cStack_1a = (char)pcVar4;
    if (cStack_1a == '\0') {
      return 0;
    }
    if (cStack_1a != '\x01') {
      ((char_sheet_t *)sheet)->stats[abStack_17[0]] =
           ((char_sheet_t *)sheet)->stats[abStack_17[0]] + 1;
      ((char_sheet_t *)sheet)->stats[abStack_17[((uint)pcVar4 & 0xff) - 1]] =
           ((char_sheet_t *)sheet)->stats[abStack_17[((uint)pcVar4 & 0xff) - 1]] - 2;
      manage_openTalkWindow();
      manage_usesLitoa10(sheet);
    }
  }
  return 1;
}



/* 4d05:1095 */

undefined2 __cdecl16far alignmentDlg(char_sheet_t *sheet)

{
  byte *pbVar1;
  uint16_t widths;
  far_t dst;
  uint8_t done;
  char *pcVar2;
  uint uVar3;
  undefined2 uVar4;
  uint16_t unaff_SS;
  far_t entries;
  char cStack_c;
  uint8_t inputBuf;
  
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
  dst.ofs = (uint16_t)&inputBuf;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)(unaff_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x24104a03)),dst);
  do {
    ovr_drawString((char *)"Select an alignment.",0x2410,0x10);
    pcVar2 = ovr_uiInputText(far_from_u32((uint32_t)(0x24104927)),3,far_from_u32((uint32_t)(0x0)),0x0);
    uVar3 = (uint)pcVar2 & 0xff;
    if (uVar3 == 0) {
      return 0;
    }
    uVar4 = (undefined2)((ulong)sheet >> 0x10);
    cStack_c = (char)pcVar2;
    ((char_sheet_t *)sheet)->alignment = cStack_c - 1;
    pbVar1 = &((char_sheet_t *)sheet)->statMask;
    *pbVar1 = *pbVar1 | 4;
    if (CurPartySlot != '\0') {
      return 1;
    }
    widths = *(uint16_t *)((int)&GAlignmentString.seg + uVar3 * 4);
    ovr_drawString((char *)((far_t *)&GAlignmentString + uVar3)->ofs,widths,(char)widths);
    entries.seg = unaff_SS;
    entries.ofs = (uint16_t)&inputBuf;
    pcVar2 = ovr_uiInputText(entries,2,far_from_u32((uint32_t)(0x0)),0x0);
    if (((uint)pcVar2 & 0xff) == 0) {
      return 0;
    }
  } while (((uint)pcVar2 & 0xff) != 1);
  return 1;
}



/* 4d05:1146 */

bool __cdecl16far uiPickGender(char_sheet_t *sheet)

{
  char *pcVar1;
  bool bVar2;
  char cStack_4;
  
  ovr_drawString((char *)"Male or female?",0x2410);
  pcVar1 = ovr_uiInputText(far_from_u32((uint32_t)(0x24104933)),2,far_from_u32((uint32_t)(0x0)),0x0);
  bVar2 = ((uint)pcVar1 & 0xff) != 0;
  if (bVar2) {
    cStack_4 = (char)pcVar1;
    ((char_sheet_t *)sheet)->gender = cStack_4 - 1;
  }
  return bVar2;
}



/* 4d05:118b */

/* Returns the AD&D ability modifier for a score (-3..+3 at the 4/6/9/13/16/18 thresholds). */

undefined1 __cdecl16far manage_abilityModifier(byte abilityScore)

{
  undefined1 uVar1;
  
  if (abilityScore < 4) {
    uVar1 = 0xfd;
  }
  else if (abilityScore < 6) {
    uVar1 = 0xfe;
  }
  else if (abilityScore < 9) {
    uVar1 = 0xff;
  }
  else if (abilityScore < 0xd) {
    uVar1 = 0;
  }
  else if (abilityScore < 0x10) {
    uVar1 = 1;
  }
  else if (abilityScore < 0x12) {
    uVar1 = 2;
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}



/* 4d05:11cb */

/* Rolls and stores the party member's hit points, then sets statMask bit 4. */

void __cdecl16far manage_rollHitPoints(char_sheet_t *sheet)

{
  char cVar1;
  uint16_t uVar2;
  uint uVar3;
  int iVar4;
  char_sheet_t *pcVar5;
  int iVar6;
  undefined2 uVar7;
  uint16_t unaff_SS;
  far_t dst;
  uint8_t classLimits;
  int iStack_4;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&classLimits;
  F_SCOPY(far_from_u32((uint32_t)(0x24104a0b)),dst);
  iStack_4 = 0;
  for (iVar6 = 0; uVar7 = (undefined2)((ulong)sheet >> 0x10), pcVar5 = (char_sheet_t *)sheet,
      iVar6 < (int)(uint)pcVar5->race; iVar6 = iVar6 + 1) {
    uVar2 = ovr_randBelow((uint)(&classLimits)[pcVar5->cls]);
    uVar3 = uVar2 & 0xff;
    cVar1 = manage_abilityModifier(pcVar5->stats[4]);
    iVar4 = uVar3 + (int)cVar1 + 1;
    if (iVar4 < 1) {
      iVar4 = 1;
    }
    iStack_4 = iStack_4 + iVar4;
  }
  pcVar5->hp[0] = (byte)iStack_4;
  pcVar5->hp[1] = (byte)iStack_4;
  pcVar5->statMask = pcVar5->statMask | 0x10;
  return;
}



/* 4d05:125c */

/* WARNING: Instruction at (ram,0x0004ff54) overlaps instruction at (ram,0x0004ff53)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * __cdecl16far chargen_switch(uint16_t index)

{
  uint16_t *puVar1;
  uint8_t *puVar2;
  uint *puVar3;
  int *piVar4;
  byte *pbVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  far_t entries;
  far_t entries_00;
  far_t handle;
  char cVar8;
  char cVar9;
  bool bVar10;
  bool bVar11;
  undefined2 uVar12;
  uint16_t uVar13;
  uint uVar14;
  uint uVar15;
  char *pcVar16;
  uint32_t *puVar17;
  far_t *pfVar18;
  uint32_t *puVar19;
  far_t *pfVar20;
  char_sheet_t *pcVar21;
  char *pcVar22;
  int iVar23;
  int iVar24;
  undefined1 uVar25;
  undefined2 in_CX;
  uint16_t uVar26;
  undefined2 in_DX;
  entity_t *peVar27;
  far_t *unaff_BP;
  char *unaff_SI;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  uint32_t uVar28;
  uint16_t uVar29;
  char *in_stack_00000000;
  agnt_t *paStack0008;
  undefined2 uStack000a;
  char acStack_1b6 [120];
  char acStack_13e [36];
  undefined2 auStack_11a [66];
  undefined2 auStack_96 [24];
  undefined1 auStack_66 [16];
  char acStack_56 [52];
  undefined2 uStack_22;
  undefined2 uStack_20;
  entity_t *in_stack_0000ffe2;
  undefined2 in_stack_0000ffe4;
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
  undefined1 uVar39;
  
  uVar13 = CONCAT11((char)((uint)in_DX >> 8),(byte)index);
  uVar14 = index & 0xff;
  if (6 < uVar14) {
    return (char *)0x0;
  }
  peVar27 = (entity_t *)(uVar14 * 2);
  cVar9 = (char)unaff_SS;
  bVar38 = (byte)((uint)unaff_SS >> 8);
  switch(uVar14) {
  case 0:
    cVar9 = in(uVar13);
    *unaff_DI = cVar9;
    midpakAd.ofs = (uint16_t)stshStoreFile_2(unaff_BP,in_stack_00000000,index);
    midpakAd.seg = uVar13;
    cmidpakComOfs = stshStoreFile_2((far_t *)"cmidpak.com",(char *)0x12410,index);
    _cmidpakComSeg = uVar13;
    ibmsndComOfs = stshStoreFile_2((far_t *)"ibmsnd.com",(char *)0x12410,index);
    ibmsndComSeg = uVar13;
    sblasterComOfs = stshStoreFile_2((far_t *)"sblaster.com",(char *)0x12410,index);
    audioPlaceholder2.seg = 0;
    audioPlaceholder2.ofs = 0;
    sblasterComSeg = uVar13;
    fibmbakComOfs = stshStoreFile_2((far_t *)"fibmbak.com",(char *)0x12410,index);
    fibmbakComSeg = uVar13;
    pfVar20 = stshStoreFile_2((far_t *)"sbpro.com",(char *)0x12410,index);
    sbproComOfs = pfVar20;
    sbproComSeg = uVar13;
    sbproComCopyOfs = pfVar20;
    sbproComCopySeg = uVar13;
    paudioComOfs = stshStoreFile_2((far_t *)"paudio.com",(char *)0x12410,index);
    sblasterComCopySeg = sblasterComSeg;
    sblasterComCopyOfs = sblasterComOfs;
    pfVar18 = sblasterComOfs;
    paudioComSeg = pfVar20;
    adlibComOfs = stshStoreFile_2((far_t *)"adlib.com",(char *)0x12410,index);
    adlibComSeg = pfVar18;
    adlibgComOfs = stshStoreFile_2((far_t *)"adlibg.com",(char *)0x12410,index);
    audioPlaceholder3.seg = 0;
    audioPlaceholder3.ofs = 0;
    musDriver0Seg = 0;
    musDriver0Ofs = 0;
    adlibgComSeg = pfVar18;
    sbfmAdvOfs = stshStoreFile_2((far_t *)"sbfm.adv",(char *)0x12410,index);
    audioPlaceholder0.seg = 0;
    audioPlaceholder0.ofs = 0;
    audioPlaceholder1.seg = 0;
    audioPlaceholder1.ofs = 0;
    sbfmAdvSeg = pfVar18;
    sbp2fmAdvOfs = stshStoreFile_2((far_t *)"sbp2fm.adv",(char *)0x12410,index);
    sbp2fmAdvSeg = pfVar18;
    sbp1fmAdvOfs = stshStoreFile_2((far_t *)"sbp1fm.adv",(char *)0x12410,index);
    sbp1fmAdvSeg = pfVar18;
    pasfmAdvOfs = stshStoreFile_2((far_t *)"pasfm.adv",(char *)0x12410,index);
    pasfmAdvSeg = pfVar18;
    pasoplAdvOfs = stshStoreFile_2((far_t *)"pasopl.adv",(char *)0x12410,index);
    pasoplAdvSeg = pfVar18;
    adlibAdvOfs = stshStoreFile_2((far_t *)"adlib.adv",(char *)0x12410,index);
    adlibAdvSeg = pfVar18;
    adlibgAdvOfs = stshStoreFile_2((far_t *)"adlibg.adv",(char *)0x12410,index);
    adlibgAdvSeg = pfVar18;
    mt32mpuAdvOfs = stshStoreFile_2((far_t *)"mt32mpu.adv",(char *)0x12410,index);
    mt32mpuAdvSeg = pfVar18;
    return (char *)mt32mpuAdvOfs;
  case 1:
    iVar23 = ovr_ovc23_findClearColumn(GfxRndSeed);
    if (iVar23 < 0) {
      ovr_drawTextAt((char *)"You cannot attract units to this location.");
      pcVar16 = (char *)"puppetmaker" + 3;
      ((uint8_t *)menuItemRow)[index] = 0x0;
    }
    else {
      uVar31 = 0x6f;
      uVar25 = 0x23;
      bVar38 = (byte)index;
      callResultTemp = func_0x0004f501();
      if (callResultTemp < CONCAT11(uVar25,uVar31)) {
        uVar31 = (uint8_t)callResultTemp;
        uVar25 = (undefined1)(callResultTemp >> 8);
        ((uint8_t *)menuItemRow)[index] = uVar31;
      }
      uVar7 = *(undefined4 *)((uint)bVar38 << 2);
      cVar9 = *(char *)((int)uVar7 + 0x2f);
      pcVar16 = (char *)CONCAT11((char)(((uint)bVar38 << 2) >> 8),cVar9);
      if (cVar9 != -1) {
        ovr_ovc41_pluralSuffix(CONCAT11(uVar25,uVar31));
        pcVar16 = ovr_stsprintf(acStack_56,(char *)CONCAT13(9,CONCAT12(0x21,unaff_SS)));
        ovr_drawTextAt(pcVar16);
      }
    }
    return pcVar16;
  case 2:
    ((int *)StshHandles)[(int)unaff_SI] = uVar14;
    *(undefined2 *)((int)(long *)StshPtrs + (int)unaff_SI * 4 + 2) = 0;
    *(undefined2 *)((long *)StshPtrs + (int)unaff_SI) = 0;
    return unaff_SI;
  case 3:
    for (iVar23 = 0; iVar23 < (int)(uint)GLeaderCount; iVar23 = iVar23 + 1) {
      if (((*(char *)((int)*(undefined4 *)(iVar23 << 2) + 0x3d) != '\0') &&
          (uVar13 = 0x2410, *(int *)((int)*(undefined4 *)(iVar23 << 2) + 0x39) == GfxRndSeed)) &&
         (uVar13 = 0x2410, *(uint16_t *)((int)*(undefined4 *)(iVar23 << 2) + 0x3b) == GfxRndSeed2))
      {
        if (GCharLevelsInc != '\0') {
          uVar12 = (undefined2)((ulong)*(undefined4 *)(iVar23 << 2) >> 0x10);
          iVar24 = (int)*(undefined4 *)(iVar23 << 2);
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
             (*(char *)((int)*(undefined4 *)(iVar23 << 2) + 0x28) != '\0'))) {
        iVar23 = iVar23 + 1;
      }
      if (iVar23 < (int)(uint)GLeaderCount) {
        PartyCount = (char)iVar23 + 1;
        uVar12 = *(undefined2 *)((uint)PartyCount * 4 + -2);
        (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uVar12;
        handle.ofs = *(undefined2 *)((uint)PartyCount * 4 + -4);
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
      *(undefined2 *)(uVar14 * 4 + -2) = CONCAT11(uVar34,uVar33);
      *(undefined2 *)(uVar14 * 4 + -4) = CONCAT11(uVar32,uVar25);
      if (CurPartySlot == 0) {
        *(undefined1 *)(CONCAT11(uVar32,uVar25) + 0x86) = 1;
      }
      CurPartySlot = CurPartySlot + 1;
    }
    else {
      manage_openTalkWindow();
      uVar12 = *(undefined2 *)((uint)PartyCount * 4 + -2);
      uVar6 = *(undefined2 *)((uint)PartyCount * 4 + -4);
      uVar33 = (undefined1)uVar12;
      uVar34 = (undefined1)((uint)uVar12 >> 8);
      uVar25 = (undefined1)uVar6;
      uVar32 = (undefined1)((uint)uVar6 >> 8);
      manage_usesLitoa10((char_sheet_t *)CONCAT13(uVar34,CONCAT12(uVar33,uVar6)));
    }
    pcVar16 = ovr_fmVsprintf("Place %s here.",
                             (char *)CONCAT13(uVar34,CONCAT12(uVar33,CONCAT11(uVar32,uVar25))));
    ovr_drawString(pcVar16);
    (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = cVar9;
    entries_00.ofs = (uint16_t)&stack0xfff2;
    (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = bVar38;
    pcVar16 = ovr_uiInputText(entries_00,2);
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
    index = (uint32_t *)CONCAT22(uVar13,puVar17);
    if ((char)*index == '\0') {
      uVar28 = CONCAT22((int)((ulong)in_stack_00000000 >> 0x10),*(undefined2 *)((int)puVar17 + 7));
      uVar26 = uVar13;
      pfVar18 = fmMalloc((far_t *)*(undefined2 *)((int)puVar17 + 5),uVar28);
      uVar25 = SUB21(pfVar18,0);
      uVar32 = (undefined1)((uint)pfVar18 >> 8);
      if (pfVar18 == (far_t *)0x0 && uVar26 == 0) {
        puVar17 = (uint32_t *)0x0;
      }
      else {
        uVar29 = (uint16_t)(uVar28 >> 0x10);
        if (*(int *)((int)puVar17 + 0x11) == 0 && *(int *)((int)puVar17 + 0x13) == 0) {
          stshSeek(StshStrongDatHnd,
                   CONCAT22(*(undefined2 *)((int)puVar17 + 3),*(undefined2 *)((int)puVar17 + 1)));
          uVar33 = 0xfd;
          uVar34 = 0x83;
          stshRead();
          uVar28 = CONCAT22(uVar29,*(undefined2 *)((int)puVar17 + 7));
          pfVar18 = ovr_heapMalloc((far_t *)*(undefined2 *)((int)puVar17 + 5),uVar28);
          uVar29 = (uint16_t)(uVar28 >> 0x10);
          *(uint16_t *)((int)puVar17 + 0x13) = uVar26;
          *(undefined2 *)((int)puVar17 + 0x11) = pfVar18;
          if (*(int *)((int)puVar17 + 0x11) == 0 && *(int *)((int)puVar17 + 0x13) == 0) {
            bVar10 = false;
          }
          else {
            memcpy((char *)CONCAT13((char)((uint)*(undefined2 *)((int)puVar17 + 0x13) >> 8),
                                    CONCAT12((char)*(undefined2 *)((int)puVar17 + 0x13),
                                             *(undefined2 *)((int)puVar17 + 0x11))),
                   (char *)CONCAT22(CONCAT11(uVar34,uVar33),(char *)CONCAT11(uVar32,uVar25)),
                   *(word *)((int)puVar17 + 5));
            bVar10 = true;
          }
        }
        else {
          memcpy((char *)CONCAT13((char)(uVar26 >> 8),CONCAT12((char)uVar26,pfVar18)),
                 (char *)CONCAT22(*(undefined2 *)((int)puVar17 + 0x13),
                                  (char *)*(undefined2 *)((int)puVar17 + 0x11)),
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
              uVar12 = (undefined2)
                       (CONCAT13((char)(uVar26 >> 8),CONCAT12((char)uVar26,uVar29)) >> 0x10);
              *(int *)(uVar29 + 0xf) = iVar23;
              *(int *)(uVar29 + 0xd) = iVar24;
            }
            if (iVar24 != 0 || iVar23 != 0) {
              uVar12 = (undefined2)
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
            *(undefined2 *)((int)puVar17 + 0xb) = 0;
            *(undefined2 *)((int)puVar17 + 9) = 0;
            *(uint16_t *)(Stsh_2410_47f6.ofs + 0xb) = uVar13;
            *(undefined2 *)(Stsh_2410_47f6.ofs + 9) = puVar17;
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
      *unaff_SI = *unaff_SI + (char)(uVar14 >> 8) + ((undefined1 *)0xfff3 < &stack0xfff2);
      *(undefined1 *)((int)&(((entity_t *)*(entity_t **)&Entities)->base).entity + uVar14 + 1) = 0;
      uVar12 = (undefined2)((ulong)Entities >> 0x10);
      *(undefined1 *)((int)&((entity_t *)Entities)[(int)unaff_SI].base.state + 1) =
           (char)((entity_t *)Entities)[(int)unaff_SI].base.flags32;
      if (unaff_SI + 1 < EntityCount) {
        pcVar16 = (char *)"thief" + 5;
        ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.");
        return pcVar16;
      }
      if ((cVar9 != '\0') || (cVar30 != '\0')) {
        if ((char)((uint)((int)unaff_SI * 0x37) >> 8) == '\0') {
          ovr_stop_audio();
          CurSfxType3 = 0xff;
          ovr_play_sfx(90);
        }
        else if (cVar30 == '\0') {
          if (cVar9 != '\0') {
            ovr_play_sfx(37);
          }
        }
        else {
          ovr_play_sfx(35);
        }
      }
      GGameState = 0x3d;
      pcVar16 = (char *)"puppetmaker" + 3;
      if (DebugVerbose != false) {
        pcVar16 = (char *)"puppetmaker" + 3;
        printf("%d \r");
      }
      ovr_OVC23_55fe_29a2_entry();
      return pcVar16;
    }
    ovr_ovc45_compute9(acStack_1b6);
    func_0x0005d3f4();
    uStack_20 = 0x23f1;
    uStack_22 = 0x44;
    pcVar16 = ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x55,CONCAT12(10,unaff_SS)));
    ovr_blitLabel(pcVar16);
    TextBlitY = TextBlitY + 0xc;
    iVar23 = ovr_font_textWidth((char *)"UNITS");
    TextBlitX = 0x89 - iVar23;
    ovr_blitLabel((char *)"UNITS");
    iVar23 = ovr_font_textWidth((char *)"POPULATION");
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
        uVar7 = *(undefined4 *)((index & 0xff) << 2);
        ovr_blitLabel((char *)auStack_11a[iVar23 * 2 + (uint)*(byte *)((int)uVar7 + 0x2f) * 8]);
      }
      func_0x0005f303();
      ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x4c,CONCAT12(0xd1,unaff_SS)));
      iVar24 = ovr_font_textWidth(acStack_13e);
      TextBlitX = 0x89 - iVar24;
      ovr_blitLabel(acStack_13e);
      ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x4c,CONCAT12(0xd1,unaff_SS)));
      iVar24 = ovr_font_textWidth(acStack_13e);
      uVar13 = 0xd4 - iVar24;
      TextBlitX = uVar13;
      cVar30 = cVar9;
      bVar35 = bVar38;
      ovr_blitLabel(acStack_13e);
      iVar23 = iVar23 + 1;
    }
    CurSfxType3 = 0x3c;
    puVar36 = &stack0xfff2;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = cVar9;
    entries.ofs = (uint16_t)auStack_66;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = bVar38;
    uVar12 = ovr_ovc28_usesUiInputText(entries);
    cVar9 = (char)uVar12;
    keyboardInputMode = 0;
    if (((cVar9 != '\0') && (cVar9 != '\x01')) && (cVar9 != -2)) {
      (&stack0xbac4)[(int)unaff_DI] = (&stack0xbac4)[(int)unaff_DI] + cVar8;
      iVar24 = 0x2410;
      do {
        bVar38 = *(byte *)(iVar24 * uVar13 + 0x21);
        uVar25 = (undefined1)(iVar24 * uVar13 >> 8);
        iVar24 = iVar23;
        if (*(byte *)(iVar23 * 0x34 + 0x22) < bVar38) {
          bVar38 = *(byte *)(iVar23 * 0x34 + 0x22);
          uVar25 = (undefined1)((uint)(iVar23 * 0x34) >> 8);
          *(byte *)(iVar23 * 0x34 + 0x21) = bVar38;
        }
        do {
          iVar24 = iVar24 + 1;
          if ((int)(uint)AgntCount <= iVar24) {
            iVar23 = ovr_audio_panFromX(paStack0008);
            uVar25 = (undefined1)((uint)iVar23 >> 8);
            ovr_play_sfxU(0x1c);
            return (char *)CONCAT11(uVar25,1);
          }
        } while (*(uint16_t *)(iVar24 * 0x34 + 0x1b) != paStack0008->owner);
        if ((byte)puVar36[0x32] < *(byte *)(iVar24 * 0x34 + 0x22)) {
          *(undefined1 *)(iVar24 * 0x34 + 0x22) = puVar36[0x32];
        }
        uVar13 = 0x34;
        iVar23 = iVar24;
      } while( true );
    }
    if (cVar9 == -2) {
      Cancelled = 1;
    }
    return (char *)"puppetmaker" + 3;
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
    uVar14 = ovr_alignUp4((in_stack_0000ffe2->base).destX);
    uVar37 = (undefined1)uVar14;
    uVar39 = (undefined1)(uVar14 >> 8);
    uVar13 = (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x;
    uVar33 = (undefined1)uVar13;
    uVar34 = (undefined1)(uVar13 >> 8);
    uVar25 = 0x79;
    uVar32 = 0x23;
    uVar15 = ovr_alignUp4(uVar13);
    uVar14 = CONCAT11(uVar34,uVar33);
    if ((CONCAT11(uVar39,uVar37) == uVar15) &&
       (uVar14 = CONCAT11(uVar34,uVar33),
       (in_stack_0000ffe2->base).destY == (in_stack_0000ffe2->base).y)) {
      (in_stack_0000ffe2->base).destX = 0;
      (in_stack_0000ffe2->base).destY = 0;
      if (*(char *)((int)&(in_stack_0000ffe2->base).entity + 3) == -1) {
        cVar9 = -1;
      }
      else {
        uVar7 = *(undefined4 *)((uint)*(byte *)((int)&(in_stack_0000ffe2->base).entity + 3) << 2);
        cVar9 = *(char *)((int)uVar7 + 0x89);
      }
      uVar14 = CONCAT11(uVar34,uVar33);
      if (cVar9 != -1) {
        for (uVar15 = 0; uVar14 = CONCAT11(uVar34,uVar33), uVar15 < SquareRecCount;
            uVar15 = uVar15 + 1) {
          uVar14 = ovr_alignUp4(*(int *)(uVar15 * 0x13));
          bVar38 = (byte)uVar14;
          uVar37 = (undefined1)(uVar14 >> 8);
          uVar13 = (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x;
          uVar33 = (undefined1)uVar13;
          uVar34 = (undefined1)(uVar13 >> 8);
          uVar25 = 0x79;
          uVar32 = 0x23;
          uVar14 = ovr_alignUp4(uVar13);
          if ((CONCAT11(uVar37,bVar38) == uVar14) &&
             (*(uint16_t *)(uVar15 * 0x13 + 2) == (in_stack_0000ffe2->base).y)) {
            uVar14 = uVar15 * 0x13 + (uint)bVar38 + 0xe;
            uVar25 = 0x79;
            uVar32 = 0x23;
            func_0x0004f930();
            if (*(uint16_t *)(uVar15 * 0x13 + 2) == GfxRndSeed2) {
              uVar14 = ovr_alignUp4(*(int *)(uVar15 * 0x13));
              bVar38 = (byte)uVar14;
              uVar37 = (undefined1)(uVar14 >> 8);
              uVar33 = (undefined1)GfxRndSeed;
              uVar34 = (undefined1)((uint)GfxRndSeed >> 8);
              uVar25 = 0x79;
              uVar32 = 0x23;
              uVar15 = ovr_alignUp4(GfxRndSeed);
              uVar14 = CONCAT11(uVar34,uVar33);
              if (CONCAT11(uVar37,bVar38) == uVar15) {
                (&stack0xfff2)[bVar38] = 1;
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
            cVar9 = func_0x0004f944();
            while ((cVar9 != '\0' &&
                   (pcVar16 = ovr_ovc15_textArena((int)unaff_DI), ((uint)pcVar16 & 0xff) != 0))) {
              cVar9 = cVar9 + -1;
            }
          }
          else {
            cVar9 = (char)((ulong)((in_stack_0000ffe2->base).animFrame + 0xf) / 0x10);
            while (cVar30 = cVar9 + -1, cVar9 != '\0') {
              ovr_agnt_usesAgntCount6((entity_t *)Entities + (int)unaff_DI);
              cVar9 = cVar30;
            }
          }
        }
        else {
          ovr_ovc15_clearVisited();
          cVar9 = (char)((ulong)((in_stack_0000ffe2->base).animFrame + 0xf) / 0x10);
          while (cVar30 = cVar9 + -1, cVar9 != '\0') {
            ovr_ovc15_textArena((int)unaff_DI);
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
        ovr_ovc24_removeOtherEntities(&stack0xffe9);
        GGameState = 0x1f;
        if (uVar31 != 0x0) {
          ovr_constr_usesBlitRect();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (uVar14 = 0; (int)uVar14 < 5; uVar14 = uVar14 + 1) {
          if ((&stack0xfff2)[uVar14] != '\0') {
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
        return (char *)"puppetmaker" + 3;
      }
      peVar27 = (entity_t *)Entities + (int)unaff_DI;
      unaff_ES = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
      uVar14 = ovr_alignUp4((peVar27->base).destX);
      uVar25 = (undefined1)uVar14;
      uVar32 = (undefined1)(uVar14 >> 8);
      uVar14 = ovr_alignUp4((((entity_t *)CONCAT22(unaff_ES,peVar27))->base).x);
      if ((CONCAT11(uVar32,uVar25) == uVar14) && ((peVar27->base).destY == (peVar27->base).y)) {
        func_0x0004fb8e();
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
      (uVar13 = ovr_randBelow(2), in_stack_0000ffe2 = peVar27, in_stack_0000ffe4 = unaff_ES,
      (char)uVar13 == '\0')) ||
     (cVar8 = func_0x0004f412(), in_stack_0000ffe2 = peVar27, in_stack_0000ffe4 = unaff_ES,
     cVar8 != '\0')) {
    if ((CONCAT11(uVar25,cVar9) == 0) || (cVar8 = func_0x0004f412(), cVar8 != '\0')) {
      if ((CONCAT11(uVar32,cVar30) == 0) || (cVar9 = func_0x0004f412(), cVar9 != '\0')) {
        uVar14 = ovr_ovc26_usesStExit((int)unaff_DI);
        if ((char)uVar14 == '\0') {
          uVar14 = ovr_ovc26_usesRandBelow((int)unaff_DI,(uint16_t)&stack0xffe9);
          if ((uVar14 & 0xff) == 0) {
            peVar27 = (entity_t *)((uint)(in_stack_0000ffe2->base).gindex * 0x95);
            uVar13 = 0x195d;
switchD_4000_e2bf_caseD_6:
            if (peVar27[0xb4].base.teamCode == 0x0) {
              func_0x0004fb8e();
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
  undefined2 uVar1;
  far_t entries;
  far_t entries_00;
  far_t dst;
  far_t handle;
  far_t handle_00;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint in_DX;
  uint16_t widths;
  uint16_t unaff_SI;
  int iVar6;
  char *unaff_SS;
  char acStack_9d [11];
  uint8_t menuItems;
  uint16_t auStack_90 [21];
  uint8_t msg;
  char_sheet_t *pcStack_16;
  uint uStack_14;
  int iStack_12;
  uint uStack_10;
  char *pcStack_e;
  uint16_t uStack_c;
  uint8_t keepDiscard;
  
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
  dst.ofs = (uint16_t)&keepDiscard;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)((uint)unaff_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x24104a16)),dst);
  ovr_fmFreeAudio(1);
  ovr_ovc13_usesBlitRect();
  pcStack_16 = ovr_stshAlloc(0xae);
  uStack_14 = in_DX;
  do {
    while( true ) {
      _fmemset((void *)(ulong)uStack_14,0xae,unaff_SI);
      pcStack_16->charIndex = 0xff;
      while( true ) {
        if (TimerSeed.lo == 0 && TimerSeed.hi == 0) {
          TimerSeed.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
          TimerSeed.lo = *(uint16_t *)BDA_DailyTimeCounter;
        }
        srand8(CONCAT13((char)(TimerSeed.hi >> 8),CONCAT12((char)TimerSeed.hi,TimerSeed.lo)));
        manage_openTalkWindow();
        manage_rollStats(pcStack_16,(char)uStack_14);
        manage_usesLitoa10((char_sheet_t *)
                           CONCAT13((char)(uStack_14 >> 8),CONCAT12((char)uStack_14,pcStack_16)));
        auStack_90[0] = 0x2410;
        menuItems = 0x4fce;
        acStack_9d[0] = '\0';
        auStack_90[2] = 0;
        auStack_90[1] = 0;
        iVar4 = 1;
        for (iStack_12 = 0; iVar6 = iVar4 + 1, iStack_12 < 4; iStack_12 = iStack_12 + 1) {
          acStack_9d[iVar4] = (char)iStack_12 + '\x02';
          uVar1 = *(undefined2 *)(iStack_12 * 4 + 0xeb);
          auStack_90[iVar6 * 2] = *(uint16_t *)(iStack_12 * 4 + 0xed);
          *(undefined2 *)(&menuItems + iVar6 * 4) = uVar1;
          iVar4 = iVar6;
        }
        acStack_9d[iVar4] = '\x06';
        if (pcStack_16->stats[4] < 9) {
          auStack_90[iVar6 * 2] = 0;
          (&menuItems + iVar6 * 4)[0] = 0x0;
          (&menuItems + iVar6 * 4)[1] = 0x0;
        }
        else {
          auStack_90[iVar6 * 2] = GUnitDescriptions[4].seg;
          *(uint16_t *)(&menuItems + iVar6 * 4) = GUnitDescriptions[4].ofs;
        }
        iVar6 = iVar4 + 2;
        acStack_9d[iVar4 + 1] = '\a';
        if (pcStack_16->stats[1] < 9) {
          auStack_90[iVar6 * 2] = 0;
          (&menuItems + iVar6 * 4)[0] = 0x0;
          (&menuItems + iVar6 * 4)[1] = 0x0;
        }
        else {
          auStack_90[iVar6 * 2] = GUnitDescriptions[5].seg;
          *(uint16_t *)(&menuItems + iVar6 * 4) = GUnitDescriptions[5].ofs;
        }
        iVar6 = iVar4 + 3;
        acStack_9d[iVar4 + 2] = '\b';
        if ((pcStack_16->stats[4] < 9) || (pcStack_16->stats[3] < 9)) {
          auStack_90[iVar6 * 2] = 0;
          (&menuItems + iVar6 * 4)[0] = 0x0;
          (&menuItems + iVar6 * 4)[1] = 0x0;
        }
        else {
          auStack_90[iVar6 * 2] = GUnitDescriptions[6].seg;
          *(uint16_t *)(&menuItems + iVar6 * 4) = GUnitDescriptions[6].ofs;
        }
        ovr_drawString((char *)"Reroll ability scores, or select the character\'s class.",0x2410,
                       0x10);
        entries.seg = (uint16_t)unaff_SS;
        entries.ofs = (uint16_t)&menuItems;
        pcVar3 = ovr_uiInputText(entries,9,far_from_u32((uint32_t)(0x0)),0x0);
        uStack_10 = (uint)pcVar3 & 0xff;
        if (uStack_10 != 0) {
          uStack_10 = (uint)(char)(&stack0xff61)[uStack_10];
        }
        if (uStack_10 == 0) goto L_chargen_17B2;
        if (uStack_10 != 1) break;
        TimerSeed.hi = 0;
        TimerSeed.lo = 0;
      }
      uStack_10 = uStack_10 - 1;
      if (Difficulty < 2) {
        pcStack_16->flags5d = pcStack_16->flags5d | 4;
      }
      else {
        pcStack_16->flags5d = pcStack_16->flags5d | 6;
      }
      pcStack_16->cls = (char)uStack_10 - 1;
      pcVar3 = chargen_switch(CONCAT11(0x24,pcStack_16->cls));
      pcStack_16->classStr = (byte)pcVar3;
      pcStack_16->race = 6;
      iVar4 = (uint)pcStack_16->cls * 0x94 + (uint)pcStack_16->race * 4;
      widths = *(uint16_t *)(iVar4 + -4);
      (pcStack_16->name).seg = *(uint16_t *)(iVar4 + -2);
      (&pcStack_16->name)->ofs = widths;
      pcStack_16->statMask = pcStack_16->statMask | 8;
      pcStack_16->statMask = pcStack_16->statMask | 1;
      if (Difficulty == 1) {
        *(undefined2 *)((int)&pcStack_16->gold + 2) = 0;
        *(undefined2 *)&pcStack_16->gold = 500;
      }
      else if (Difficulty == 2) {
        *(undefined2 *)((int)&pcStack_16->gold + 2) = 0;
        *(undefined2 *)&pcStack_16->gold = 300;
      }
      else {
        *(undefined2 *)((int)&pcStack_16->gold + 2) = 0;
        *(undefined2 *)&pcStack_16->gold = 100;
      }
      pcStack_16->buildType[0] = 7;
      pcStack_16->partySlot = 0xff;
      manage_usesLitoa10((char_sheet_t *)
                         CONCAT13((char)(uStack_14 >> 8),CONCAT12((char)uStack_14,pcStack_16)));
      uVar5 = abilitiesDlg((char_sheet_t *)
                           CONCAT13((char)(uStack_14 >> 8),CONCAT12((char)uStack_14,pcStack_16)));
      if ((uVar5 & 0xff) == 0) break;
      manage_rollHitPoints
                ((char_sheet_t *)
                 CONCAT13((char)(uStack_14 >> 8),CONCAT12((char)uStack_14,pcStack_16)));
      while( true ) {
        manage_usesLitoa10((char_sheet_t *)
                           CONCAT13((char)(uStack_14 >> 8),CONCAT12((char)uStack_14,pcStack_16)));
        uVar5 = alignmentDlg((char_sheet_t *)
                             CONCAT13((char)(uStack_14 >> 8),CONCAT12((char)uStack_14,pcStack_16)));
        if ((uVar5 & 0xff) == 0) break;
L_chargen_1661:
        manage_openTalkWindow();
        manage_usesLitoa10((char_sheet_t *)
                           CONCAT13((char)(uStack_14 >> 8),CONCAT12((char)uStack_14,pcStack_16)));
        bVar2 = uiPickGender((char_sheet_t *)
                             CONCAT13((char)(uStack_14 >> 8),CONCAT12((char)uStack_14,pcStack_16)));
        if (bVar2) {
          do {
            manage_blitTalkWindow();
            ovr_drawString((char *)"Select the character\'s name.",0x2410,0x10);
            while (pcStack_e = ovr_uiReadString((char *)0x0,0,6,(char *)0x0,0,0), uStack_c = widths,
                  pcStack_e == (char *)0x0 && widths == 0) {
              if (inputCancelled != '\0') {
                if (UserWantsExit == '\0') goto L_chargen_1661;
                goto L_chargen_17B2;
              }
              manage_blitTalkWindow();
              ovr_drawString((char *)"Please type your character\'s name. Esc go back.",0x2410,0x10)
              ;
            }
            ovr_drawString((char *)"Lawful" + 6,0x2410,0x10);
            __fstrncpy((char *)CONCAT22(uStack_14,pcStack_16),(char *)CONCAT22(uStack_c,pcStack_e),
                       0x27);
            (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uStack_c;
            handle.ofs = (uint16_t)pcStack_e;
            (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)(uStack_c >> 8);
            ovr_stshFree(handle);
            pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x505a,unaff_SS),
                                   (char *)CONCAT22(pcStack_16,(char *)"puppetmaker" + 3),
                                   (char)uStack_14);
            ovr_drawString(pcVar3,widths,(char)widths);
            entries_00.seg = (uint16_t)unaff_SS;
            entries_00.ofs = (uint16_t)&keepDiscard;
            pcVar3 = ovr_uiInputText(entries_00,2,far_from_u32((uint32_t)(0x0)),0x0);
            uStack_10 = (uint)pcVar3 & 0xff;
            if (uStack_10 != 0) {
              if (uStack_10 != 2) {
                pcStack_16->statMask = pcStack_16->statMask | 2;
                manage_openTalkWindow();
                manage_usesLitoa10((char_sheet_t *)
                                   CONCAT13((char)(uStack_14 >> 8),
                                            CONCAT12((char)uStack_14,pcStack_16)));
                TimerSeed.lo = 0;
                TimerSeed.hi = 0;
                return pcStack_16;
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
  (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)uStack_14;
  handle_00.ofs = (uint16_t)pcStack_16;
  (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)(uStack_14 >> 8);
  ovr_stshFree(handle_00);
  return (char_sheet_t *)0x0;
}



/* 4d05:17c7 */

/* Stops music/agents and opens the settlement screen for a party slot (manage_settlementScreen),
   restoring the menu afterwards. */

void __cdecl16far manage_showSettlementScreen(uint8_t partySlot,...)

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

/* [R2] string "halfling castle" */

void __cdecl16far manage_textHalflingCastle(void)

{
  uint *puVar1;
  int *piVar2;
  far_t gfx;
  far_t dst;
  far_t handle;
  uint uVar3;
  char *pcVar4;
  char_sheet_t *widths;
  int iVar5;
  undefined2 uVar6;
  uint16_t unaff_SS;
  far_t entries;
  char_sheet_t *pcStack_12;
  int iStack_10;
  uint8_t inputBuf;
  uint uStack_6;
  int iStack_4;
  
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
  dst.ofs = (uint16_t)&inputBuf;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)(unaff_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x24104a1e)),dst);
  gfx.seg = FontHandle.seg;
  gfx.ofs = FontHandle.ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)));
  ovr_attact_usesAgntFlag1();
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  CurMusicType = 0xff;
  savedMenuItem = GMenuItem;
  MenuModeSaved = MenuMode;
  TextBlitDstSeg = 0xa000;
  for (iStack_4 = 0; iStack_10 = 0x2410, iStack_4 < (int)(uint)GLeaderCount; iStack_4 = iStack_4 + 1
      ) {
    if (((*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3d) != '\0') &&
        (*(int *)((int)*(undefined4 *)(iStack_4 << 2) + 0x39) == GfxRndSeed)) &&
       (*(int *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3b) == GfxRndSeed2)) {
      if (GCharLevelsInc != '\0') {
        uVar6 = (undefined2)((ulong)*(undefined4 *)(iStack_4 << 2) >> 0x10);
        iVar5 = (int)*(undefined4 *)(iStack_4 << 2);
        puVar1 = (uint *)(iVar5 + 0x56);
        uVar3 = *puVar1;
        *puVar1 = *puVar1 + 10000;
        piVar2 = (int *)(iVar5 + 0x58);
        *piVar2 = *piVar2 + (uint)(0xd8ef < uVar3);
        GCharLevelsInc = '\0';
      }
      manage_settlementScreen((byte)iStack_4);
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
    pcStack_12 = chargen();
    if (pcStack_12 == (char_sheet_t *)0x0 && iStack_10 == 0) {
      ovr_stats_openCastlePanel();
      ovr_ovc41_usesGMenuItem();
      return;
    }
    iStack_4 = 0;
    while ((iStack_4 < (int)(uint)GLeaderCount &&
           (*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x28) != '\0'))) {
      iStack_4 = iStack_4 + 1;
    }
    if (iStack_4 < (int)(uint)GLeaderCount) {
      PartyCount = (byte)iStack_4 + 1;
      uVar6 = *(undefined2 *)((uint)PartyCount * 4 + -2);
      (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uVar6;
      handle.ofs = *(undefined2 *)((uint)PartyCount * 4 + -4);
      (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)uVar6 >> 8);
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
    pcStack_12->statMask = pcStack_12->statMask | 0x40;
    pcStack_12->charIndex = PartyCount - 1;
    uVar3 = (uint)PartyCount;
    widths = (char_sheet_t *)((char *)"halfling castle" + 0xc);
    *(int *)(uVar3 * 4 + -2) = iStack_10;
    *(undefined2 *)(uVar3 * 4 + -4) = pcStack_12;
    if (CurPartySlot == 0) {
      pcStack_12->titleIndex = 1;
    }
    CurPartySlot = CurPartySlot + 1;
  }
  else {
    manage_openTalkWindow();
    iStack_10 = *(int *)((uint)PartyCount * 4 + -2);
    pcStack_12 = (char_sheet_t *)*(undefined2 *)((uint)PartyCount * 4 + -4);
    widths = pcStack_12;
    manage_usesLitoa10((char_sheet_t *)
                       CONCAT13((char)((uint)iStack_10 >> 8),CONCAT12((char)iStack_10,pcStack_12)));
  }
  pcVar4 = ovr_fmVsprintf("Place %s here.",
                          (char *)CONCAT13((char)((uint)iStack_10 >> 8),
                                           CONCAT12((char)iStack_10,pcStack_12)));
  ovr_drawString(pcVar4,(uint16_t)widths,(char)widths);
  entries.seg = unaff_SS;
  entries.ofs = (uint16_t)&inputBuf;
  pcVar4 = ovr_uiInputText(entries,2,far_from_u32((uint32_t)(0x0)),0x0);
  uStack_6 = (uint)pcVar4 & 0xff;
  if (uStack_6 == 1) {
    iStack_4 = PartyCount - 1;
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
    if (*(char *)((int)*(undefined4 *)((uint)bVar1 << 2) + 0x86) != '\0') break;
    bVar1 = bVar1 + 1;
  }
  return bVar1;
}



/* 4d05:1b51 */

/* [R6] touches GLeaderCount */

undefined2 __cdecl16far manage_usesGLeaderCount3(byte partyIndex)

{
  char cVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined1 extraout_AH;
  undefined4 *puVar4;
  undefined1 uVar5;
  byte bStack_4;
  
  bVar3 = manage_findFirstLeader();
  bStack_4 = partyIndex;
  uVar5 = extraout_AH;
  do {
    puVar4 = (undefined4 *)CONCAT11(uVar5,bStack_4);
    if ((((bStack_4 < GLeaderCount) &&
         (puVar4 = (undefined4 *)CONCAT11(uVar5,bStack_4), bStack_4 != bVar3)) &&
        (puVar4 = (undefined4 *)CONCAT11(uVar5,bStack_4), bStack_4 != partyIndex)) &&
       (puVar4 = (undefined4 *)((uint)bStack_4 << 2), *(char *)((int)*puVar4 + 0x3d) != '\0')) {
      uVar2 = *(undefined4 *)((uint)bStack_4 << 2);
      cVar1 = *(char *)((int)uVar2 + 0x3f);
      uVar5 = (undefined1)(((uint)bStack_4 << 2) >> 8);
      puVar4 = (undefined4 *)CONCAT11(uVar5,cVar1);
      if (cVar1 == *(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3f)) {
        return CONCAT11(uVar5,bStack_4);
      }
    }
    bStack_4 = bStack_4 + 1;
    uVar5 = (undefined1)((uint)puVar4 >> 8);
    if (GLeaderCount <= bStack_4) {
      bStack_4 = 0;
    }
  } while (bStack_4 != partyIndex);
  return CONCAT11(uVar5,0xff);
}



/* 4d05:1bee */
/* DECOMPILATION FAILED: Exception while decompiling 4d05:1bee: Response buffer size exceeded for: st.exe
 */
void manage_settlementScreen(void) { /* failed */ }

/* 4d05:217a */

/* Long itoa in base 10 */

char * __cdecl16far litoa10(char *buf,long n,...)

{
  bool bVar1;
  size_t sVar2;
  uint16_t len;
  bool bVar3;
  uint32_t digit;
  long dividend;
  long lVar4;
  int in_stack_0000000a;
  uint8_t sign;
  
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
  *(char *)CONCAT22((undefined2)n,buf) = (char)digit + '0';
  buf[1] = '\0';
  while (lVar4 = LDIV_at_(dividend,10), lVar4 != 0) {
    sVar2 = strlen((char *)CONCAT22((undefined2)n,buf));
    if ((sVar2 & 3) == 3) {
      len = strlen((char *)CONCAT22((undefined2)n,buf));
      _fmemmove((char *)CONCAT22((undefined2)n,buf + 1),(char *)CONCAT22((undefined2)n,buf),len + 1)
      ;
      *(char *)CONCAT22((undefined2)n,buf) = ',';
    }
    sVar2 = strlen((char *)CONCAT22((undefined2)n,buf));
    _fmemmove((char *)CONCAT22((undefined2)n,buf + 1),(char *)CONCAT22((undefined2)n,buf),sVar2 + 1)
    ;
    dividend = LDIV_at_(dividend,10);
    lVar4 = LMOD_at_(dividend,10);
    *(char *)CONCAT22((undefined2)n,buf) = (char)lVar4 + '0';
  }
  if (bVar1) {
    sVar2 = strlen((char *)CONCAT22((undefined2)n,buf));
    _fmemmove((char *)CONCAT22((undefined2)n,buf + 1),(char *)CONCAT22((undefined2)n,buf),sVar2 + 1)
    ;
    *(char *)CONCAT22((undefined2)n,buf) = '-';
  }
  return buf;
}



/* 4d05:22b3 */

/* [R1] forwards to manage_4d05_22cf */

void __cdecl16far manage_4d05_22cf_entry(void)

{
  undefined2 *in_stack_0000000a;
  undefined2 *in_stack_0000000e;
  
  *in_stack_0000000a = 0;
  *in_stack_0000000e = 0;
  if (EntityCount != 0) {
    manage_usesEntities();
    return;
  }
  return;
}



/* 4d05:22cf */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* [R6] touches Entities, GMenuStrings */

void manage_usesEntities(void)

{
  char in_CL;
  entity_t *peVar1;
  int unaff_BP;
  int unaff_SI;
  undefined2 uVar2;
  undefined2 unaff_SS;
  
  if (in_CL != -1) {
    manage_usesEntities2();
    return;
  }
  uVar2 = (undefined2)((ulong)Entities >> 0x10);
  peVar1 = (entity_t *)Entities;
  if (((*(char *)((int)(char **)GMenuStrings + (uint)peVar1[unaff_SI].base.gindex * 0x95 + 0x1f) ==
        '\0') && (*(byte *)(unaff_BP + 8) <= peVar1[unaff_SI].base.level)) &&
     (peVar1[unaff_SI].base.level <= *(byte *)(unaff_BP + 10))) {
    *(int *)*(undefined4 *)(unaff_BP + 0xc) = *(int *)*(undefined4 *)(unaff_BP + 0xc) + 1;
    *(int *)*(undefined4 *)(unaff_BP + 0x10) =
         *(int *)*(undefined4 *)(unaff_BP + 0x10) +
         (uint)((entity_t *)Entities)[unaff_SI].base.animFrame;
  }
  if (EntityCount <= unaff_SI + 1U) {
    return;
  }
  manage_usesEntities();
  return;
}



/* 4d05:2371 */

/* [R6] touches Entities, animFrame */

void __cdecl16far manage_usesEntities2(void)

{
  char in_CL;
  entity_t *peVar1;
  int unaff_BP;
  int unaff_SI;
  undefined2 uVar2;
  undefined2 unaff_SS;
  
  uVar2 = (undefined2)((ulong)Entities >> 0x10);
  peVar1 = (entity_t *)Entities;
  if (((*(char *)((int)&peVar1[unaff_SI].base.entity + 3) == in_CL) &&
      (*(byte *)(unaff_BP + 8) <= peVar1[unaff_SI].base.level)) &&
     (peVar1[unaff_SI].base.level <= *(byte *)(unaff_BP + 10))) {
    *(int *)*(undefined4 *)(unaff_BP + 0xc) = *(int *)*(undefined4 *)(unaff_BP + 0xc) + 1;
    *(int *)*(undefined4 *)(unaff_BP + 0x10) =
         *(int *)*(undefined4 *)(unaff_BP + 0x10) +
         (uint)((entity_t *)Entities)[unaff_SI].base.animFrame;
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
  undefined4 uVar3;
  int iVar4;
  unit_t *puVar5;
  uint uVar6;
  undefined2 uVar7;
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
        if ((*(char *)(uVar6 * 0x12 + 9) == partyIndex) &&
           (bVar1 = *(byte *)(uVar6 * 0x12 + 8), *(char *)((uint)bVar1 * 0x27 + 0x133) == unitType))
        {
          *recordCount = *recordCount + 1;
          if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x01') {
            *in_stack_00000018 = *in_stack_00000018 + 1;
          }
          else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x02') {
            *in_stack_0000001c = *in_stack_0000001c + 1;
          }
          else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x03') {
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
    uVar7 = (undefined2)((ulong)GUnits >> 0x10);
    puVar5 = (unit_t *)GUnits;
    if (((puVar5[uVar6].unitType != 0xff) &&
        (uVar3 = *(undefined4 *)((uint)puVar5[uVar6].unitType << 2),
        *(char *)((int)uVar3 + 0x3f) == '\0')) &&
       (bVar1 = (puVar5 + uVar6)->bldType, *(char *)((uint)bVar1 * 0x27 + 0x133) == unitType)) {
      iStack_4 = iStack_4 + 1;
      if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x01') {
        *resource1Count = *resource1Count + 1;
      }
      else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x02') {
        *resource2Count = *resource2Count + 1;
      }
      else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x03') {
        *resource3Count = *resource3Count + 1;
      }
    }
    uVar6 = uVar6 + 1;
  }
  iVar4 = manage_usesGUnits();
  return iVar4;
}



/* 4d05:2543 */

/* [R6] touches GUnits, unitType */

undefined2 __cdecl16far manage_usesGUnits(void)

{
  byte bVar1;
  undefined4 uVar2;
  unit_t *puVar3;
  int unaff_BP;
  uint unaff_SI;
  uint uVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  
  uVar5 = (undefined2)((ulong)GUnits >> 0x10);
  if ((((unit_t *)GUnits)[unaff_SI].unitType == *(byte *)(unaff_BP + 6)) &&
     (bVar1 = ((unit_t *)GUnits + unaff_SI)->bldType,
     *(char *)((uint)bVar1 * 0x27 + 0x133) == *(char *)(unaff_BP + 8))) {
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
    if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x01') {
      *(int *)*(undefined4 *)(unaff_BP + 10) = *(int *)*(undefined4 *)(unaff_BP + 10) + 1;
    }
    else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x02') {
      *(int *)*(undefined4 *)(unaff_BP + 0xe) = *(int *)*(undefined4 *)(unaff_BP + 0xe) + 1;
    }
    else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x03') {
      *(int *)*(undefined4 *)(unaff_BP + 0x12) = *(int *)*(undefined4 *)(unaff_BP + 0x12) + 1;
    }
  }
  while( true ) {
    unaff_SI = unaff_SI + 1;
    if (GUnitCount <= unaff_SI) {
      for (uVar4 = 0; uVar4 < GRecordCount; uVar4 = uVar4 + 1) {
        if ((*(char *)(uVar4 * 0x12 + 9) == *(char *)(unaff_BP + 6)) &&
           (bVar1 = *(byte *)(uVar4 * 0x12 + 8),
           *(char *)((uint)bVar1 * 0x27 + 0x133) == *(char *)(unaff_BP + 8))) {
          *(int *)*(undefined4 *)(unaff_BP + 0x16) = *(int *)*(undefined4 *)(unaff_BP + 0x16) + 1;
          if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x01') {
            *(int *)*(undefined4 *)(unaff_BP + 0x1a) = *(int *)*(undefined4 *)(unaff_BP + 0x1a) + 1;
          }
          else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x02') {
            *(int *)*(undefined4 *)(unaff_BP + 0x1e) = *(int *)*(undefined4 *)(unaff_BP + 0x1e) + 1;
          }
          else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x03') {
            *(int *)*(undefined4 *)(unaff_BP + 0x22) = *(int *)*(undefined4 *)(unaff_BP + 0x22) + 1;
          }
        }
      }
      *(int *)(unaff_BP + -2) =
           *(int *)(unaff_BP + -2) -
           (*(int *)*(undefined4 *)(unaff_BP + 0x1e) + *(int *)*(undefined4 *)(unaff_BP + 0x22));
      *(int *)*(undefined4 *)(unaff_BP + 10) =
           *(int *)*(undefined4 *)(unaff_BP + 10) - *(int *)*(undefined4 *)(unaff_BP + 0x1e);
      *(int *)*(undefined4 *)(unaff_BP + 0xe) =
           *(int *)*(undefined4 *)(unaff_BP + 0xe) - *(int *)*(undefined4 *)(unaff_BP + 0x22);
      return *(undefined2 *)(unaff_BP + -2);
    }
    if (*(char *)(unaff_BP + 6) != -1) break;
    uVar5 = (undefined2)((ulong)GUnits >> 0x10);
    puVar3 = (unit_t *)GUnits;
    if (((puVar3[unaff_SI].unitType != 0xff) &&
        (uVar2 = *(undefined4 *)((uint)puVar3[unaff_SI].unitType << 2),
        *(char *)((int)uVar2 + 0x3f) == '\0')) &&
       (bVar1 = (puVar3 + unaff_SI)->bldType,
       *(char *)((uint)bVar1 * 0x27 + 0x133) == *(char *)(unaff_BP + 8))) {
      *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
      if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x01') {
        *(int *)*(undefined4 *)(unaff_BP + 10) = *(int *)*(undefined4 *)(unaff_BP + 10) + 1;
      }
      else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x02') {
        *(int *)*(undefined4 *)(unaff_BP + 0xe) = *(int *)*(undefined4 *)(unaff_BP + 0xe) + 1;
      }
      else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x03') {
        *(int *)*(undefined4 *)(unaff_BP + 0x12) = *(int *)*(undefined4 *)(unaff_BP + 0x12) + 1;
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
  char *pcVar4;
  char_sheet_t *pcVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  char *unaff_SS;
  byte in_stack_00000004;
  uint16_t uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  uint8_t term;
  uint8_t resultPtrs;
  undefined2 auStack_156 [9];
  uint8_t menuItems;
  undefined2 auStack_142 [9];
  uint8_t structNames;
  undefined2 auStack_12e [59];
  char acStack_b8 [80];
  char acStack_68 [80];
  uint8_t uStack_18;
  char cStack_17;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  int iStack_10;
  int iStack_e;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  char_sheet_t *pcStack_6;
  char *pcStack_4;
  
  dst.seg = (uint16_t)unaff_SS;
  dst.ofs = (uint16_t)&resultPtrs;
  F_SCOPY(far_from_u32((uint32_t)(0x24104ada)),dst);
  for (iVar7 = 0; iVar7 < 5; iVar7 = iVar7 + 1) {
    uVar6 = *(undefined2 *)(&resultPtrs + iVar7 * 4);
    auStack_142[iVar7 * 2] = auStack_156[iVar7 * 2];
    *(undefined2 *)(&menuItems + iVar7 * 4) = uVar6;
  }
  for (iVar7 = 0; iVar7 < 0x1e; iVar7 = iVar7 + 1) {
    uVar6 = *(undefined2 *)((int)&GStructures[0].name + iVar7 * 6);
    auStack_12e[iVar7 * 2] = *(undefined2 *)((int)&GStructures[0].name + 2 + iVar7 * 6);
    *(undefined2 *)(&structNames + iVar7 * 4) = uVar6;
  }
  cStack_17 = '\x02';
  manage_openTalkWindow();
  uStack_18 = 0x0;
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
    ovr_blitGfxRect(gfx,0,0,(brect_t *)(BlitRects + 1),0x10,true,0,0x10,0x10,0);
  }
  TextBlitY = 0xc;
  TextBlitX = 0x11;
  uVar10 = (undefined1)Font02.seg;
  uVar11 = (undefined1)(Font02.seg >> 8);
  if (in_stack_00000004 == 0xff) {
    ovr_blitLabel((char *)"All property.",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                  Font02.seg,0xde,uVar10,0xde,0x50);
  }
  else {
    pcStack_4 = (char *)((undefined2 *)((uint)in_stack_00000004 * 4))[1];
    pcVar5 = (char_sheet_t *)*(undefined2 *)((uint)in_stack_00000004 * 4);
    uVar6 = 0x50;
    term = 0xde;
    uVar9 = Font02.ofs;
    pcStack_6 = pcVar5;
    iVar7 = ovr_ovc45_compute9(acStack_68,(char *)CONCAT22(pcVar5,unaff_SS),
                               (char *)CONCAT22(Font02.ofs,pcStack_4),Font02.seg,'i',0x69,3);
    pvVar2 = manage_playerTitle(pcStack_6,pcStack_4,(char)iVar7,pcVar5);
    pcVar4 = ovr_stsprintf(acStack_b8,(char *)CONCAT22(0x52a1,unaff_SS),
                           (char *)CONCAT22(pvVar2,(char *)"puppetmaker" + 3),pcVar5);
    ovr_blitLabel(pcVar4,(uint8_t *)CONCAT22(uVar9,pcVar5),CONCAT11(uVar11,uVar10),term,uVar10,term,
                  uVar6);
  }
  TextBlitY = TextBlitY + 0xc;
  TextBlitX = 0x11;
  ovr_blitLabel((char *)"Buildings",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
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
      ovr_blitLabel((char *)*(undefined2 *)((int)&GStructures[0].name + iVar3),
                    (uint8_t *)
                    CONCAT22(Font02.ofs,
                             (uint8_t *)*(undefined2 *)((int)&GStructures[0].name + 2 + iVar3)),
                    Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
      lVar1 = (long)(iVar8 + iVar7) * 6;
      uVar6 = (undefined2)((ulong)lVar1 >> 0x10);
      iStack_16 = manage_usesGUnitCount
                            (in_stack_00000004,(&((unk01_t *)GStructures)->type)[(int)lVar1],
                             (int *)CONCAT22(unaff_SS,&iStack_8),(int *)CONCAT22(unaff_SS,&iStack_a)
                             ,(int *)CONCAT22(unaff_SS,&iStack_c),
                             (int *)CONCAT22(unaff_SS,&iStack_e));
      if (iStack_e == 0) {
        iVar3 = 100;
        pcVar4 = litoa10(acStack_68,
                         CONCAT13((char)((uint)iStack_16 >> 8),CONCAT12((char)iStack_16,unaff_SS)),
                         (char)iStack_16,0);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,pcVar4)),iVar3);
      }
      else {
        iVar3 = 100;
        pcVar4 = ovr_stsprintf(acStack_b8);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,pcVar4)),iVar3);
      }
      lVar1 = (long)(iVar8 + iVar7) * 6;
      uVar6 = (undefined2)((ulong)lVar1 >> 0x10);
      if (*(char *)((int)&GStructures[0].pad + (int)lVar1) != '\0') {
        if (iStack_10 == 0) {
          iVar3 = 0x8c;
          pcVar4 = litoa10(acStack_68,
                           CONCAT13((char)((uint)iStack_8 >> 8),CONCAT12((char)iStack_8,unaff_SS)),
                           (char)iStack_8,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,pcVar4)),iVar3);
        }
        else {
          iVar3 = 0x8c;
          pcVar4 = ovr_stsprintf(acStack_b8);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,pcVar4)),iVar3);
        }
        if (iStack_12 == 0) {
          iVar3 = 0xb4;
          pcVar4 = litoa10(acStack_68,
                           CONCAT13((char)((uint)iStack_a >> 8),CONCAT12((char)iStack_a,unaff_SS)),
                           (char)iStack_a,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,pcVar4)),iVar3);
        }
        else {
          iVar3 = 0xb4;
          pcVar4 = ovr_stsprintf(acStack_b8);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,pcVar4)),iVar3);
        }
        if (iStack_14 == 0) {
          iVar3 = 0xdc;
          pcVar4 = litoa10(acStack_68,
                           CONCAT13((char)((uint)iStack_c >> 8),CONCAT12((char)iStack_c,unaff_SS)),
                           (char)iStack_c,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,pcVar4)),iVar3);
        }
        else {
          iVar3 = 0xdc;
          pcVar4 = ovr_stsprintf(acStack_b8);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar6 >> 8),CONCAT12((char)uVar6,pcVar4)),iVar3);
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
    iVar8 = iVar8 + 1;
  }
  CurSfxType3 = 0x3c;
  (*(uint8_t *)((uint8_t *)&(entries.seg))) = (char)unaff_SS;
  entries.ofs = (uint16_t)&menuItems;
  (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = (char)((uint)unaff_SS >> 8);
  uVar6 = ovr_ovc28_usesUiInputText(entries,0x23,far_from_u32((uint32_t)(0x0)),&uStack_18,0,(char)&uStack_18);
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

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* [R2] string "All property." */

void manage_textAllProperty2(void)

{
  long lVar1;
  far_t gfx;
  far_t entries;
  undefined2 *puVar2;
  void *pvVar3;
  int iVar4;
  char *pcVar5;
  uint8_t *puVar6;
  undefined2 uVar7;
  int unaff_BP;
  int iVar8;
  int iVar9;
  char *unaff_SS;
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
    ovr_blitGfxRect(gfx,0,0,(brect_t *)(BlitRects + 1),0x10,true,0,0x10,0x10,0);
  }
  TextBlitY = 0xc;
  TextBlitX = 0x11;
  if (*(char *)(unaff_BP + 6) == -1) {
    ovr_blitLabel((char *)"All property.",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
                  Font02.seg,0xde,(char)Font02.seg,0xde,0x50);
  }
  else {
    puVar2 = (undefined2 *)((uint)*(byte *)(unaff_BP + 6) * 4);
    puVar6 = (uint8_t *)*puVar2;
    *(undefined2 *)(unaff_BP + -2) = puVar2[1];
    *(undefined2 *)(unaff_BP + -4) = puVar6;
    uVar7 = 0x50;
    term = 0xde;
    uVar11 = (undefined1)Font02.seg;
    uVar12 = (undefined1)(Font02.seg >> 8);
    uVar10 = Font02.ofs;
    iVar9 = ovr_ovc45_compute9((char *)(unaff_BP + -0x66),
                               (char *)CONCAT22(*(undefined2 *)(unaff_BP + -4),unaff_SS),
                               (char *)CONCAT22(Font02.ofs,(char *)*(undefined2 *)(unaff_BP + -2)),
                               Font02.seg,'i',0x69,3);
    pvVar3 = manage_playerTitle((char_sheet_t *)*(undefined2 *)(unaff_BP + -4),
                                *(undefined2 *)(unaff_BP + -2),(char)iVar9,puVar6);
    pcVar5 = ovr_stsprintf((char *)(unaff_BP + -0xb6),(char *)CONCAT22(0x52a1,unaff_SS),
                           (char *)CONCAT22(pvVar3,(char *)"puppetmaker" + 3),puVar6);
    ovr_blitLabel(pcVar5,(uint8_t *)CONCAT22(uVar10,puVar6),CONCAT11(uVar12,uVar11),term,uVar11,term
                  ,uVar7);
  }
  TextBlitY = TextBlitY + 0xc;
  TextBlitX = 0x11;
  ovr_blitLabel((char *)"Buildings",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3),
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
      ovr_blitLabel((char *)*(undefined2 *)((int)&GStructures[0].name + iVar4),
                    (uint8_t *)
                    CONCAT22(Font02.ofs,
                             (uint8_t *)*(undefined2 *)((int)&GStructures[0].name + 2 + iVar4)),
                    Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
      lVar1 = (long)(iVar8 + iVar9) * 6;
      uVar7 = (undefined2)((ulong)lVar1 >> 0x10);
      iVar4 = manage_usesGUnitCount
                        (*(char *)(unaff_BP + 6),(&((unk01_t *)GStructures)->type)[(int)lVar1],
                         (int *)CONCAT22(unaff_SS,(int *)(unaff_BP + -6)),
                         (int *)CONCAT22(unaff_SS,(int *)(unaff_BP + -8)),
                         (int *)CONCAT22(unaff_SS,(int *)(unaff_BP + -10)),
                         (int *)CONCAT22(unaff_SS,(int *)(unaff_BP + -0xc)));
      *(int *)((code *)init_textFilename + unaff_BP) = iVar4;
      if (*(int *)(unaff_BP + -0xc) == 0) {
        iVar4 = 100;
        uVar11 = (undefined1)*(undefined2 *)((code *)init_textFilename + unaff_BP);
        pcVar5 = litoa10((char *)(unaff_BP + -0x66),
                         CONCAT13((char)((uint)*(undefined2 *)((code *)init_textFilename + unaff_BP)
                                        >> 8),CONCAT12(uVar11,unaff_SS)),uVar11,0);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
      }
      else {
        iVar4 = 100;
        pcVar5 = ovr_stsprintf((char *)(unaff_BP + -0xb6));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
      }
      lVar1 = (long)(iVar8 + iVar9) * 6;
      uVar7 = (undefined2)((ulong)lVar1 >> 0x10);
      if (*(char *)((int)&GStructures[0].pad + (int)lVar1) != '\0') {
        if (*(int *)(unaff_BP + -0xe) == 0) {
          iVar4 = 0x8c;
          uVar11 = (undefined1)*(undefined2 *)(unaff_BP + -6);
          pcVar5 = litoa10((char *)(unaff_BP + -0x66),
                           CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -6) >> 8),
                                    CONCAT12(uVar11,unaff_SS)),uVar11,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
        }
        else {
          iVar4 = 0x8c;
          pcVar5 = ovr_stsprintf((char *)(unaff_BP + -0xb6));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
        }
        if (*(int *)(unaff_BP + -0x10) == 0) {
          iVar4 = 0xb4;
          uVar11 = (undefined1)*(undefined2 *)(unaff_BP + -8);
          pcVar5 = litoa10((char *)(unaff_BP + -0x66),
                           CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                    CONCAT12(uVar11,unaff_SS)),uVar11,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
        }
        else {
          iVar4 = 0xb4;
          pcVar5 = ovr_stsprintf((char *)(unaff_BP + -0xb6));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
        }
        if (*(int *)(unaff_BP + -0x12) == 0) {
          iVar4 = 0xdc;
          uVar11 = (undefined1)*(undefined2 *)(unaff_BP + -10);
          pcVar5 = litoa10((char *)(unaff_BP + -0x66),
                           CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -10) >> 8),
                                    CONCAT12(uVar11,unaff_SS)),uVar11,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
        }
        else {
          iVar4 = 0xdc;
          pcVar5 = ovr_stsprintf((char *)(unaff_BP + -0xb6));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
    iVar8 = iVar8 + 1;
  }
  CurSfxType3 = 0x3c;
  (*(uint8_t *)((uint8_t *)&(entries.seg))) = (char)unaff_SS;
  entries.ofs = unaff_BP + -0x142;
  (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = (char)((uint)unaff_SS >> 8);
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



/* 4d05:2b09 */

/* [R6] touches CurSfxType3, __C0_ASM_CopyRight */

void __cdecl16far manage_usesCurSfxType3(void)

{
  undefined2 uVar1;
  int unaff_BP;
  uint16_t unaff_SS;
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
  entries.seg = unaff_SS;
  entries.ofs = unaff_BP - 0x142;
  uVar1 = ovr_ovc28_usesUiInputText(entries,0x23,far_from_u32((uint32_t)(0x0)),(uint8_t *)(unaff_BP + -0x16));
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
  char *pcVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  char *unaff_SS;
  uint8_t msg;
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  Highlight1 = (undefined1)structType;
  Highlight1 = partyIndex;
  if (ScreenMode != '\0') {
    ovr_stats_openCastlePanel();
  }
  uStack_4 = GfxRndSeed;
  uStack_6 = GfxRndSeed2;
  GfxRndSeed = Seed_2000_d1da;
  GfxRndSeed2 = Seed_2000_d1d8;
  ovr_ovc13_usesAlignUp4();
  GfxRndSeed = uStack_4;
  GfxRndSeed2 = uStack_6;
  Highlight1 = 0xff;
  Highlight1 = 0xff;
  if (structType == 0xfe) {
    if (partyIndex == 0xff) {
      ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.",
              0x2410);
    }
    else {
      uVar2 = uStack_6;
      pcVar1 = ovr_ovc22_className(partyIndex);
      uVar3 = 0x217a;
      pcVar1 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x535b,unaff_SS),
                             (char *)CONCAT22(*(undefined2 *)((uint)partyIndex * 4),
                                              (char *)"puppetmaker" + 3),
                             ((undefined2 *)((uint)partyIndex * 4))[1],pcVar1,uVar2);
      ovr_say(pcVar1,uVar3);
    }
  }
  else {
    iVar4 = 0;
    uVar2 = uStack_6;
    while ((iVar4 < 0x1e &&
           (uVar2 = (undefined2)((ulong)((long)iVar4 * 6) >> 0x10),
           (uint)(&((unk01_t *)GStructures)->type)[(int)((long)iVar4 * 6)] != structType))) {
      iVar4 = iVar4 + 1;
    }
    if (iVar4 != 0x1e) {
      if (partyIndex == 0xff) {
        uVar2 = (undefined2)((ulong)((long)iVar4 * 6) >> 0x10);
        iVar4 = (int)((long)iVar4 * 6);
        pcVar1 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x5323,unaff_SS),
                               (char *)CONCAT22(*(undefined2 *)((int)&GStructures[0].name + iVar4),
                                                (char *)"puppetmaker" + 3),
                               *(undefined2 *)((int)&GStructures[0].name + 2 + iVar4));
        ovr_say(pcVar1,uVar2);
      }
      else {
        pcVar1 = ovr_ovc22_className(partyIndex);
        uVar3 = (undefined2)((ulong)((long)iVar4 * 6) >> 0x10);
        iVar4 = (int)((long)iVar4 * 6);
        pcVar1 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x52ed,unaff_SS),
                               (char *)CONCAT22(*(undefined2 *)((int)&GStructures[0].name + iVar4),
                                                (char *)"puppetmaker" + 3),
                               *(undefined2 *)((int)&GStructures[0].name + 2 + iVar4),
                               *(undefined2 *)((uint)partyIndex * 4),
                               ((undefined2 *)((uint)partyIndex * 4))[1],pcVar1,uVar2);
        ovr_say(pcVar1,uVar3);
      }
    }
  }
  return;
}



/* 4d05:2d79 */

/* WARNING: Instruction at (ram,0x0005ff51) overlaps instruction at (ram,0x0005ff50)
    */
/* [R2] string "Total population." */

char * __cdecl16far manage_textTotalPopulation(byte charIndex,short arg6,char_sheet_t *sheet)

{
  uint16_t *puVar1;
  uint8_t *puVar2;
  undefined4 uVar3;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  char cVar4;
  uint16_t uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined1 uVar12;
  byte *pbVar13;
  uint16_t in_DX;
  uint8_t *puVar14;
  entity_t *peVar15;
  entity_t *peVar16;
  char *pcVar17;
  char *count;
  undefined2 uVar18;
  undefined2 unaff_ES;
  uint8_t *unaff_SS;
  bool bVar19;
  undefined2 in_stack_0000000a;
  far_t entries;
  char acStack_1b6 [120];
  char acStack_13e [36];
  uint16_t auStack_11a [42];
  uint8_t bandLabels2;
  uint8_t bandLabels;
  undefined2 auStack_94 [23];
  undefined1 auStack_66 [10];
  undefined2 uStack_5c;
  entity_t *peStack_1e;
  char cStack_1a;
  char cStack_19;
  char cStack_18;
  uint8_t uStack_17;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  undefined2 uStack_10;
  char acStack_e [6];
  uint16_t uStack_8;
  undefined1 auStack_6 [2];
  undefined2 uStack_4;
  
  dst.seg = (uint16_t)unaff_SS;
  dst.ofs = (uint16_t)&bandLabels;
  F_SCOPY(far_from_u32((uint32_t)(0x24104b06)),dst);
  dst_00.seg = (uint16_t)unaff_SS;
  dst_00.ofs = (uint16_t)&bandLabels2;
  F_SCOPY(far_from_u32((uint32_t)(0x24104b36)),dst_00);
  pbVar13 = (byte *)__C0_ASM_CopyRight + 3;
  dst_01.seg = (uint16_t)unaff_SS;
  dst_01.ofs = (uint16_t)(acStack_e + 4);
  F_SCOPY(far_from_u32((uint32_t)(0x24104b66)),dst_01);
  acStack_e[2] = '\0';
  if (charIndex == 0xff) {
    acStack_e[3] = 0xc;
  }
  else {
    in_DX = 0x217a;
    unaff_ES = (undefined2)((ulong)*(undefined4 *)((uint)charIndex << 2) >> 0x10);
    if (*(char *)((int)*(undefined4 *)((uint)charIndex << 2) + 0x2f) == -1) {
      acStack_e[3] = 0xc;
    }
    else {
      acStack_e[3] = acStack_e[*(byte *)((int)*(undefined4 *)((uint)charIndex << 2) + 0x2f) + 4];
      in_DX = 0x217a;
      unaff_ES = (undefined2)((ulong)*(undefined4 *)((uint)charIndex << 2) >> 0x10);
      if (3 < *(byte *)((int)*(undefined4 *)((uint)charIndex << 2) + 0x2f)) {
        acStack_e[2] = '\x01';
      }
    }
  }
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 2)) = 0x2410;
  (*(uint16_t *)((uint8_t *)&(auStack_66))) = 0x50fb;
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 6)) = 0x2410;
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 4)) = 0x54e5;
  peVar15 = (entity_t *)(auStack_66 + 8);
  uStack_5c = 0x2410;
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 8)) = 0x54ed;
  count = (char *)((int)(undefined4 *)&_DATA + 3);
  for (pcVar17 = (char *)0x0; (int)pcVar17 < (int)(uint)(byte)acStack_e[3]; pcVar17 = pcVar17 + 1) {
    if (((int)pcVar17 < 5) || (acStack_e[2] == '\0')) {
      in_DX = *(uint16_t *)(&bandLabels + (int)pcVar17 * 4);
      peVar15 = (entity_t *)(auStack_66 + (int)count * 4);
      *(undefined2 *)(auStack_66 + (int)count * 4 + 2) = auStack_94[(int)pcVar17 * 2];
      (peVar15->base).x = in_DX;
    }
    else {
      unaff_ES = (undefined2)((ulong)*(undefined4 *)((uint)charIndex << 2) >> 0x10);
      uVar6 = (uint)*(byte *)((int)*(undefined4 *)((uint)charIndex << 2) + 0x2f);
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
                            (uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3));
      *pcVar17 = *pcVar17 + (char)(uVar6 >> 8) + ((undefined1 *)0xfff3 < &stack0xfe3a);
      *(undefined1 *)((int)&(((entity_t *)*(entity_t **)&Entities)->base).entity + uVar6 + 1) = 0;
      uVar18 = (undefined2)((ulong)Entities >> 0x10);
      *(undefined1 *)((int)&((entity_t *)Entities)[(int)pcVar17].base.state + 1) =
           (char)((entity_t *)Entities)[(int)pcVar17].base.flags32;
      if (EntityCount <= pcVar17 + 1) {
        if ((acStack_e[0] != '\0') || (acStack_e[1] != '\0')) {
          if ((*(uint8_t *)((uint8_t *)&(uStack_4) + 1)) == '\0') {
            ovr_stop_audio();
            CurSfxType3 = 0xff;
            ovr_play_sfx(90,0);
          }
          else if (acStack_e[1] == '\0') {
            if (acStack_e[0] != '\0') {
              ovr_play_sfx(37,0);
            }
          }
          else {
            ovr_play_sfx(35,0);
          }
        }
        GGameState = 0x3d;
        pcVar17 = (char *)"puppetmaker" + 3;
        if (DebugVerbose != false) {
          pcVar17 = (char *)"puppetmaker" + 3;
          printf("%d \r");
        }
        ovr_OVC23_55fe_29a2_entry();
        return pcVar17;
      }
      pcVar17 = (char *)"thief" + 5;
      ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.");
      return pcVar17;
    }
    uStack_10 = (char *)((int *)((uint)charIndex * 4))[1];
    iStack_12 = *(int *)((uint)charIndex * 4);
    uVar5 = Font02.ofs;
    ovr_ovc45_compute9(acStack_1b6,(char *)CONCAT22(iStack_12,unaff_SS),
                       (char *)CONCAT22(Font02.ofs,uStack_10),Font02.seg,'K');
    func_0x0005d3f4();
    puVar14 = (uint8_t *)((char *)"puppetmaker" + 3);
    pcVar17 = ovr_stsprintf(acStack_13e,(char *)CONCAT22(0x550a,unaff_SS),
                            (char *)CONCAT22(*(undefined2 *)
                                              ((uint)*(byte *)(iStack_12 + 0x2f) * 4 + 0xeb),
                                             (char *)"puppetmaker" + 3));
    ovr_blitLabel(pcVar17,(uint8_t *)CONCAT22(uVar5,puVar14));
    TextBlitY = TextBlitY + 0xc;
    iVar9 = ovr_font_textWidth((char *)"UNITS");
    TextBlitX = 0x89 - iVar9;
    ovr_blitLabel((char *)"UNITS",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3));
    iVar9 = ovr_font_textWidth((char *)"POPULATION");
    uVar5 = 0xd4 - iVar9;
    TextBlitX = uVar5;
    ovr_blitLabel((char *)"POPULATION",(uint8_t *)CONCAT22(Font02.ofs,(char *)"puppetmaker" + 3));
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
        uVar6 = (uint)*(byte *)((int)*(undefined4 *)((uint)charIndex << 2) + 0x2f);
        ovr_blitLabel((char *)auStack_11a[iVar9 * 2 + uVar6 * 8],
                      (uint8_t *)
                      CONCAT22(Font02.ofs,(uint8_t *)auStack_11a[iVar9 * 2 + uVar6 * 8 + 1]));
      }
      func_0x0005f303();
      ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x4c,CONCAT12(0xd1,unaff_SS)));
      iVar10 = ovr_font_textWidth(acStack_13e);
      TextBlitX = 0x89 - iVar10;
      ovr_blitLabel(acStack_13e,(uint8_t *)CONCAT22(Font02.ofs,unaff_SS));
      ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x4c,CONCAT12(0xd1,unaff_SS)));
      iVar10 = ovr_font_textWidth(acStack_13e);
      uVar5 = 0xd4 - iVar10;
      TextBlitX = uVar5;
      ovr_blitLabel(acStack_13e,(uint8_t *)CONCAT22(Font02.ofs,unaff_SS));
      iVar9 = iVar9 + 1;
    }
    CurSfxType3 = 0x3c;
    entries.seg = (uint16_t)unaff_SS;
    entries.ofs = (uint16_t)auStack_66;
    uVar18 = ovr_ovc28_usesUiInputText(entries,(uint16_t)count,far_from_u32((uint32_t)(0x0)));
    acStack_e[1] = (char)uVar18;
    keyboardInputMode = 0;
    if (((acStack_e[1] != '\0') && (acStack_e[1] != '\x01')) && (acStack_e[1] != -2)) {
      (&stack0xbac4)[(int)count] = (&stack0xbac4)[(int)count] + cVar4;
      iVar10 = 0x2410;
      do {
        iVar11 = iVar10 * uVar5;
        iVar10 = iVar9;
        if (*(byte *)(iVar9 * 0x34 + 0x22) < *(byte *)(iVar11 + 0x21)) {
          *(undefined1 *)(iVar9 * 0x34 + 0x21) = *(undefined1 *)(iVar9 * 0x34 + 0x22);
        }
        do {
          iVar10 = iVar10 + 1;
          if ((int)(uint)AgntCount <= iVar10) {
            iVar9 = ovr_audio_panFromX((agnt_t *)sheet);
            uVar12 = (undefined1)((uint)iVar9 >> 8);
            ovr_play_sfxU(0x1c);
            return (char *)CONCAT11(uVar12,1);
          }
        } while (*(int *)(iVar10 * 0x34 + 0x1b) != *(int *)(sheet->nameText + 0x1b));
        uVar18 = (undefined2)((ulong)auStack_6 >> 0x10);
        if (*(byte *)((int)auStack_6 + 0x32) < *(byte *)(iVar10 * 0x34 + 0x22)) {
          *(undefined1 *)(iVar10 * 0x34 + 0x22) = *(undefined1 *)((int)auStack_6 + 0x32);
        }
        uVar5 = 0x34;
        iVar9 = iVar10;
      } while( true );
    }
    if (acStack_e[1] == -2) {
      Cancelled = 1;
    }
    return (char *)"puppetmaker" + 3;
  }
  do {
    uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
    peVar16 = (entity_t *)peStack_1e;
    (peVar16->base).target =
         (byte)((int)(uint)*(byte *)((int)&(peVar16->base).owner +
                                    ((int)(uint)(peVar15->base).faction >> 2)) >>
               (((peVar16->base).faction & 3) << 1)) & 3;
    cVar4 = func_0x0004f32d();
    peVar15 = (entity_t *)peStack_1e;
    uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
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
    uStack_17 = 0x1;
    uVar6 = ovr_alignUp4((((entity_t *)peStack_1e)->base).destX);
    uVar7 = ovr_alignUp4((peStack_1e->base).x);
    if (uVar6 == uVar7) {
      uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
      peVar15 = (entity_t *)peStack_1e;
      if ((peVar15->base).destY == (peVar15->base).y) {
        (peVar15->base).destX = 0;
        (peVar15->base).destY = 0;
        if (*(char *)((int)&(peVar15->base).entity + 3) == -1) {
          auStack_6 = CONCAT12(0xff,auStack_6);
        }
        else {
          uVar3 = *(undefined4 *)((uint)*(byte *)((int)&(peVar15->base).entity + 3) << 2);
          auStack_6 = CONCAT12(*(undefined1 *)((int)uVar3 + 0x89),auStack_6);
        }
        uVar3 = auStack_6;
        (*(uint8_t *)((uint8_t *)&(uStack_4))) = (byte)((uint3)auStack_6 >> 0x10);
        bVar19 = (byte)uStack_4 != -1;
        auStack_6 = uVar3;
        if (bVar19) {
          for (uVar6 = 0; uVar6 < SquareRecCount; uVar6 = uVar6 + 1) {
            uVar7 = ovr_alignUp4(*(int *)(uVar6 * 0x13));
            uVar8 = ovr_alignUp4((peStack_1e->base).x);
            if ((uVar7 == uVar8) &&
               (*(uint16_t *)(uVar6 * 0x13 + 2) == (((entity_t *)peStack_1e)->base).y)) {
              func_0x0004f930();
              if (*(uint16_t *)(uVar6 * 0x13 + 2) == GfxRndSeed2) {
                uVar6 = ovr_alignUp4(*(int *)(uVar6 * 0x13));
                uVar7 = ovr_alignUp4(GfxRndSeed);
                if (uVar6 == uVar7) {
                  acStack_e[(byte)uStack_4] = '\x01';
                }
              }
              break;
            }
          }
        }
      }
    }
    if (AgntFlag1 != false) {
      uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
      if ((((peStack_1e->base).x < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (peStack_1e->base).x)) ||
         ((((entity_t *)peStack_1e)->base).y != GfxRndSeed2)) {
        cStack_19 = '\0';
      }
      else {
        cStack_19 = '\x01';
      }
      if ((((uint)auStack_6 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (uint)auStack_6)) ||
         (GfxRndSeed2 != uStack_8)) {
        cStack_18 = '\0';
      }
      else {
        cStack_18 = '\x01';
      }
      if (cStack_18 != '\0' || cStack_19 != '\0') {
        if (cStack_18 == '\0') {
          ovr_ovc15_clearVisited();
          uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
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
            ovr_ovc15_textArena((int)count);
          }
          cStack_1a = -1;
        }
        else if (cStack_19 == '\0') {
          cStack_1a = (char)((ulong)((((entity_t *)peStack_1e)->base).animFrame + 0xf) / 0x10);
          while (cStack_1a != '\0') {
            cStack_1a = cStack_1a + -1;
            ovr_agnt_usesAgntCount6((entity_t *)Entities + (int)count);
          }
          cStack_1a = -1;
        }
        else if ((cStack_18 != '\0') && (cStack_19 != '\0')) {
          for (cStack_1a = func_0x0004f944(); cStack_1a != '\0'; cStack_1a = cStack_1a + -1) {
            uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
            if (((((entity_t *)peStack_1e)->base).target & 1) == 0) {
              iStack_16 = 0;
            }
            else {
              iStack_16 = (((entity_t *)peStack_1e)->base).target - 2;
            }
            pcVar17 = ovr_ovc15_textArena((int)count);
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
        ovr_ovc24_removeOtherEntities(&uStack_17);
        GGameState = 0x1f;
        if (uStack_17 != 0x0) {
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
        return (char *)"puppetmaker" + 3;
      }
      uVar18 = (undefined2)((ulong)Entities >> 0x10);
      peStack_1e = (entity_t *)CONCAT22(uVar18,(entity_t *)Entities + (int)count);
      uVar6 = ovr_alignUp4(((entity_t *)Entities)[(int)count].base.destX);
      uVar7 = ovr_alignUp4((peStack_1e->base).x);
      if ((uVar6 == uVar7) &&
         (uVar18 = (undefined2)((ulong)peStack_1e >> 0x10),
         (((entity_t *)peStack_1e)->base).destY == (((entity_t *)peStack_1e)->base).y)) {
        func_0x0004fb8e();
      }
      unaff_ES = (undefined2)((ulong)peStack_1e >> 0x10);
      peVar15 = (entity_t *)peStack_1e;
    } while (((peVar15->base).destX == 0 && (peVar15->base).destY == 0) ||
            (*(char *)((int)&(peVar15->base).entity + 1) != '\0'));
    if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)(peVar15->base).gindex * 0x95) & 0x4000)
        == 0) {
      uStack_4 = (uint)((ulong)auStack_6 >> 0x10) & 0xff;
    }
    else {
      auStack_6 = CONCAT13(1,auStack_6);
    }
    auStack_6 = CONCAT22(uStack_4,(peStack_1e->base).x);
    uStack_8 = (peVar15->base).y;
    iStack_12 = CONCAT13(*(undefined1 *)
                           ((int)(char **)GMenuStrings + (uint)(peVar15->base).gindex * 0x95 + 0x1f)
                          ,iStack_12);
  } while ((peVar15->base).faction < (byte)(peVar15->base).state);
  uVar18 = ovr_ovc07_signum((peVar15->base).destX - (peStack_1e->base).x);
  iStack_12 = CONCAT22(uStack_10,uVar18);
  uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
  iStack_14 = ovr_ovc07_signum((((entity_t *)peStack_1e)->base).destY -
                               (((entity_t *)peStack_1e)->base).y);
  if (((iStack_12 == 0) || (uVar5 = ovr_randBelow(2), (char)uVar5 == '\0')) ||
     (cVar4 = func_0x0004f412(), cVar4 != '\0')) {
    if ((iStack_14 == 0) || (cVar4 = func_0x0004f412(), cVar4 != '\0')) {
      if ((iStack_12 == 0) || (cVar4 = func_0x0004f412(), cVar4 != '\0')) {
        uVar6 = ovr_ovc26_usesStExit((int)count);
        if ((char)uVar6 == '\0') {
          uVar6 = ovr_ovc26_usesRandBelow((int)count,(uint16_t)&uStack_17);
          if (((uVar6 & 0xff) == 0) &&
             (*(char *)((int)(char **)GMenuStrings +
                       (uint)(((entity_t *)peStack_1e)->base).gindex * 0x95 + 0x1f) == '\0')) {
            func_0x0004fb8e();
          }
        }
        else {
          uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
          peVar15 = (entity_t *)peStack_1e;
          (peVar15->base).target =
               (byte)((int)(uint)*(byte *)((int)&(peVar15->base).owner +
                                          ((int)(uint)(peVar15->base).faction >> 2)) >>
                     (((peVar15->base).faction & 3) << 1)) & 3;
          cVar4 = func_0x0004f32d();
          if (cVar4 == '\0') {
            uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
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
      uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
      puVar1 = &(((entity_t *)peStack_1e)->base).y;
      *puVar1 = *puVar1 + iStack_14;
      (((entity_t *)peStack_1e)->base).target = (char)iStack_14 + 0x1;
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
  char *pcVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  char *unaff_SS;
  uint8_t msg;
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  unitTypeFilter = (undefined1)unitType;
  partyFilter = partyIndex;
  if (ScreenMode != '\0') {
    ovr_stats_openCastlePanel();
  }
  uStack_4 = GfxRndSeed;
  uStack_6 = GfxRndSeed2;
  GfxRndSeed = Seed_2000_d1da;
  GfxRndSeed2 = Seed_2000_d1d8;
  ovr_ovc13_usesAlignUp4();
  GfxRndSeed = uStack_4;
  GfxRndSeed2 = uStack_6;
  unitTypeFilter = 0xff;
  partyFilter = 0xff;
  if (unitType == 0xfe) {
    if (partyIndex == 0xff) {
      ovr_say((char *)"All units are displayed.",0x2410);
    }
    else {
      uVar3 = uStack_6;
      pcVar1 = ovr_ovc22_className(partyIndex);
      uVar2 = 0x217a;
      pcVar1 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x5538,unaff_SS),
                             (char *)CONCAT22(*(undefined2 *)((uint)partyIndex * 4),
                                              (char *)"puppetmaker" + 3),
                             ((undefined2 *)((uint)partyIndex * 4))[1],pcVar1,uVar3);
      ovr_say(pcVar1,uVar2);
    }
  }
  else if (partyIndex == 0xff) {
    uVar3 = uStack_6;
    pcVar1 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x55b0,unaff_SS),
                           (char *)CONCAT22((char *)unitName,(char *)"puppetmaker" + 3),
                           (*(uint16_t *)((uint8_t *)&(unitName) + 2)));
    ovr_say(pcVar1,uVar3);
  }
  else {
    uVar3 = uStack_6;
    pcVar1 = ovr_ovc22_className(partyIndex);
    uVar2 = 0x217a;
    pcVar1 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x557d,unaff_SS),
                           (char *)CONCAT22((char *)unitName,(char *)"puppetmaker" + 3),
                           (*(uint16_t *)((uint8_t *)&(unitName) + 2)),*(undefined2 *)((uint)partyIndex * 4),
                           ((undefined2 *)((uint)partyIndex * 4))[1],pcVar1,uVar3);
    ovr_say(pcVar1,uVar2);
  }
  return;
}


