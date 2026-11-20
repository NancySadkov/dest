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
  ovr_vgaSetPalette8bit((uint8_t *)CONCAT22(unaff_SS,&palette));
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

char __cdecl16far manage_rollDice(char count,char sides)

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

void __cdecl16far manage_rollStats(char_sheet_t *sheet)

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

char * __cdecl16far manage_compute1(int n)

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
  undefined2 in_stack_00000006;
  
  if ((sheet->cls == 4) && (0xc < sheet->race)) {
    bVar1 = 0xc;
  }
  else if ((sheet->cls == 5) && (10 < sheet->race)) {
    bVar1 = 10;
  }
  else if ((sheet->cls == 6) && (8 < sheet->race)) {
    bVar1 = 8;
  }
  else {
    bVar1 = sheet->race;
  }
  return bVar1;
}



/* 4d05:02f1 */

/* [R7] body shape: compute */

byte __cdecl16far manage_compute3(char_sheet_t *sheet)

{
  byte bVar1;
  undefined2 in_stack_00000006;
  
  if ((sheet->cls == 4) && (0xb < sheet->race)) {
    bVar1 = 1;
  }
  else if ((sheet->cls == 5) && (9 < sheet->race)) {
    bVar1 = 1;
  }
  else if ((sheet->cls == 6) && (7 < sheet->race)) {
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
  undefined2 in_stack_00000006;
  
  if ((sheet->cls == 4) && (0xb < sheet->race)) {
    bVar1 = sheet->race + 0x37;
  }
  else if ((sheet->cls == 5) && (9 < sheet->race)) {
    bVar1 = sheet->race + 0x39;
  }
  else if ((sheet->cls == 6) && (7 < sheet->race)) {
    bVar1 = sheet->race + 0x39;
  }
  else {
    bVar1 = 0x30;
  }
  return bVar1;
}



/* 4d05:03a4 */

/* Returns the player title for a character sheet from GPlayerTitles (indexed by gender and class).
    */

void * __cdecl16far manage_playerTitle(char_sheet_t *sheet)

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
  else if (sheet->level == 0) {
    if ((sheet->race < 9) && ((sheet->cls != 6 || (sheet->race < 8)))) {
      pcVar1 = (char *)"Lawful" + 6;
    }
    else {
      pcVar1 = *(char **)(&titlesMap + (uint)sheet->cls * 8 + (uint)sheet->gender * 4);
    }
  }
  else {
    pcVar1 = (char *)((far_t *)(GStatsLabels + 4) + (uint)sheet->gender + (uint)sheet->level * 2)->
                     ofs;
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
  
  iVar1 = ovr_font_textWidth(text,(char *)CONCAT22(Font02.seg,Font02.ofs));
  TextBlitX = x - iVar1;
  ovr_blitLabel((char *)text,(*(uint16_t *)((uint8_t *)&(text) + 2)),Font02.ofs,(uint8_t)Font02.seg);
  return;
}



/* 4d05:0519 */

/* [R4] calls ovr_blitLabel */

void __cdecl16far manage_usesBlitLabel2(char *text,int x)

{
  int iVar1;
  
  iVar1 = ovr_font_textWidth(text,(char *)CONCAT22(Font02.seg,Font02.ofs));
  TextBlitX = x - iVar1;
  ovr_blitLabel((char *)text,(*(uint16_t *)((uint8_t *)&(text) + 2)),Font02.ofs,(uint8_t)Font02.seg);
  return;
}



/* 4d05:056e */

/* [R4] calls litoa10 */

void __cdecl16far manage_usesLitoa10(char_sheet_t *sheet)

{
  void *pvVar1;
  char *pcVar2;
  undefined2 uVar3;
  uint8_t *in_DX;
  int iVar4;
  int iVar5;
  uint16_t uVar6;
  char *unaff_SS;
  undefined2 in_stack_00000006;
  uint8_t uVar7;
  undefined1 uVar8;
  char cVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  char textBuf [120];
  uint8_t msg;
  byte bStack_6;
  byte bStack_5;
  int iStack_4;
  
  bStack_6 = sheet->statMask;
  if ((bStack_6 & 0x20) != 0) {
    uVar6 = 0x1b;
    for (iVar5 = 0; iVar5 < 6; iVar5 = iVar5 + 1) {
      TextBlitX = 0x15;
      TextBlitY = uVar6;
      ovr_blitLabel((char *)((far_t *)GStatsLabels + iVar5)->ofs,
                    (uint8_t *)*(undefined2 *)((int)&GStatsLabels[0].seg + iVar5 * 4),Font02.ofs,
                    (uint8_t)Font02.seg);
      ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%d");
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)unaff_SS >> 8),CONCAT12((char)unaff_SS,&msg)),0x31);
      uVar6 = uVar6 + 10;
    }
  }
  TextBlitY = 0xc;
  if ((bStack_6 & 2) != 0) {
    TextBlitX = 0x15;
    uVar11 = (undefined1)Font02.seg;
    uVar12 = (undefined1)(Font02.seg >> 8);
    uVar8 = (undefined1)Font02.ofs;
    uVar10 = (undefined1)(Font02.ofs >> 8);
    pvVar1 = manage_playerTitle(sheet);
    iStack_4 = ovr_font_textWidth((char *)CONCAT13((char)((uint)in_DX >> 8),
                                                   CONCAT12((char)in_DX,pvVar1)),
                                  (char *)CONCAT13(uVar12,CONCAT12(uVar11,CONCAT11(uVar10,uVar8))));
    uVar7 = (uint8_t)Font02.seg;
    uVar6 = Font02.ofs;
    ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&msg),(char *)CONCAT22(in_stack_00000006,sheet),
                       (char *)CONCAT22(Font02.seg,Font02.ofs),0x7d - iStack_4,'\x03');
    manage_playerTitle(sheet);
    pcVar2 = ovr_stsprintf(textBuf,unaff_SS,(char *)"%s%s, ");
    ovr_blitLabel(pcVar2,in_DX,uVar6,uVar7);
  }
  if ((bStack_6 & 4) != 0) {
    uVar7 = (uint8_t)Font02.seg;
    uVar6 = Font02.ofs;
    pcVar2 = ovr_fmVsprintf((char *)"%s ",(char *)"puppetmaker" + 3);
    ovr_blitLabel(pcVar2,in_DX,uVar6,uVar7);
  }
  if ((bStack_6 & 1) != 0) {
    uVar7 = (uint8_t)Font02.seg;
    in_DX = (uint8_t *)((char *)"puppetmaker" + 3);
    uVar6 = Font02.ofs;
    pcVar2 = ovr_fmVsprintf((char *)"%s",(char *)"puppetmaker" + 3);
    ovr_blitLabel(pcVar2,in_DX,uVar6,uVar7);
  }
  TextBlitY = TextBlitY + 10;
  if (((bStack_6 & 0x40) != 0) || (DebugVerbose != false)) {
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Population",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    uVar8 = 0x7d;
    uVar10 = 0;
    pcVar2 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%d");
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar2)),
               CONCAT11(uVar10,uVar8));
    TextBlitX = 0x82;
    ovr_ovc22_textRingProt(sheet->charIndex);
    ovr_blitLabel((char *)"Food prod.",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    uVar8 = 0xdc;
    uVar10 = 0;
    pcVar2 = litoa10(textBuf,(ulong)(uint)sheet->foodProd);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar2)),
               CONCAT11(uVar10,uVar8));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x82;
    ovr_blitLabel((char *)"Food stored",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    uVar8 = 0xdc;
    uVar10 = 0;
    uVar3 = *(undefined2 *)((int)&sheet->foodStored + 2);
    pcVar2 = litoa10(textBuf,CONCAT13((char)((uint)uVar3 >> 8),
                                      CONCAT12((char)uVar3,(int)sheet->foodStored)));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar2)),
               CONCAT11(uVar10,uVar8));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Housing",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    uVar8 = 0x7d;
    uVar10 = 0;
    pcVar2 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%d");
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar2)),
               CONCAT11(uVar10,uVar8));
    TextBlitX = 0x82;
    ovr_blitLabel((char *)"Food storage",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    uVar8 = 0xdc;
    uVar10 = 0;
    uVar3 = *(undefined2 *)((int)&sheet->foodStorage + 2);
    pcVar2 = litoa10(textBuf,CONCAT13((char)((uint)uVar3 >> 8),
                                      CONCAT12((char)uVar3,(int)sheet->foodStorage)));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar2)),
               CONCAT11(uVar10,uVar8));
    TextBlitY = TextBlitY + 0xf;
    if (sheet->maxTrade != 0) {
      TextBlitX = 0x37;
      if (sheet->foodSold < 0) {
        ovr_blitLabel((char *)"Food sold",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                      (uint8_t)Font02.seg);
        uVar8 = 0x7d;
        uVar10 = 0;
        iVar5 = -sheet->foodSold;
        iVar4 = iVar5 >> 0xf;
        cVar9 = (char)(iVar5 >> 0xf);
        pcVar2 = litoa10(textBuf,CONCAT13(cVar9,CONCAT12(cVar9,iVar5)));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar4 >> 8),CONCAT12((char)iVar4,pcVar2)),
                   CONCAT11(uVar10,uVar8));
      }
      else {
        ovr_blitLabel((char *)"Food bought",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                      (uint8_t)Font02.seg);
        uVar8 = 0x7d;
        uVar10 = 0;
        iVar5 = sheet->foodSold;
        iVar4 = iVar5 >> 0xf;
        cVar9 = (char)(iVar5 >> 0xf);
        pcVar2 = litoa10(textBuf,CONCAT13(cVar9,CONCAT12(cVar9,iVar5)));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar4 >> 8),CONCAT12((char)iVar4,pcVar2)),
                   CONCAT11(uVar10,uVar8));
      }
      TextBlitX = 0x82;
      ovr_blitLabel((char *)"Max. trade",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                    (uint8_t)Font02.seg);
      uVar8 = 0xdc;
      uVar10 = 0;
      pcVar2 = litoa10(textBuf,(ulong)(uint)sheet->maxTrade);
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)iVar4 >> 8),CONCAT12((char)iVar4,pcVar2)),
                 CONCAT11(uVar10,uVar8));
    }
    TextBlitY = TextBlitY + 0xf;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Income",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    uVar8 = 0xdc;
    uVar10 = 0;
    iVar5 = sheet->income;
    iVar4 = iVar5 >> 0xf;
    cVar9 = (char)(iVar5 >> 0xf);
    pcVar2 = litoa10((char *)&msg,CONCAT13(cVar9,CONCAT12(cVar9,iVar5)));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar4 >> 8),CONCAT12((char)iVar4,pcVar2)),
               CONCAT11(uVar10,uVar8));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Gold",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    uVar8 = 0xdc;
    uVar10 = 0;
    uVar3 = *(undefined2 *)((int)&sheet->gold + 2);
    pcVar2 = litoa10((char *)&msg,
                     CONCAT13((char)((uint)uVar3 >> 8),CONCAT12((char)uVar3,(int)sheet->gold)));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar4 >> 8),CONCAT12((char)iVar4,pcVar2)),
               CONCAT11(uVar10,uVar8));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Vault storage",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    uVar8 = 0xdc;
    uVar10 = 0;
    uVar3 = *(undefined2 *)((int)&sheet->vaultStorage + 2);
    pcVar2 = litoa10((char *)&msg,
                     CONCAT13((char)((uint)uVar3 >> 8),
                              CONCAT12((char)uVar3,(int)sheet->vaultStorage)));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar4 >> 8),CONCAT12((char)iVar4,pcVar2)),
               CONCAT11(uVar10,uVar8));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Fund Access",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    uVar8 = 0xdc;
    uVar10 = 0;
    uVar3 = ovr_ovc45_usesLDIV_at_(sheet->charIndex);
    pcVar2 = litoa10(textBuf,CONCAT13((char)((uint)iVar4 >> 8),CONCAT12((char)iVar4,uVar3)));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar4 >> 8),CONCAT12((char)iVar4,pcVar2)),
               CONCAT11(uVar10,uVar8));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Common fund",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    uVar8 = 0xdc;
    uVar10 = 0;
    pcVar2 = litoa10(textBuf,CONCAT13((char)((uint)GPopulationHi >> 8),
                                      CONCAT12((char)GPopulationHi,GPopulationLo)));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar4 >> 8),CONCAT12((char)iVar4,pcVar2)),
               CONCAT11(uVar10,uVar8));
    bStack_5 = manage_findFirstLeader();
    TextBlitY = TextBlitY + 0xf;
    if (((sheet->level != 0) && (bStack_5 != 0xff)) &&
       (uVar3 = 0x217a, *(byte *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x86) < 9)) {
      manage_usesBlitLabel2("popularity",0x7d);
      manage_usesBlitLabel2("city blocks",0xdc);
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x11;
      ovr_blitLabel((char *)"Current",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                    (uint8_t)Font02.seg);
      uVar8 = 0x7d;
      uVar10 = 0;
      manage_usesGLeaderCount();
      pcVar2 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%d%%");
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)uVar3 >> 8),CONCAT12((char)uVar3,pcVar2)),
                 CONCAT11(uVar10,uVar8));
      uVar8 = 0xdc;
      uVar10 = 0;
      pcVar2 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%d");
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)uVar3 >> 8),CONCAT12((char)uVar3,pcVar2)),
                 CONCAT11(uVar10,uVar8));
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x11;
      ovr_blitLabel((char *)"to promote",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                    (uint8_t)Font02.seg);
      uVar8 = 0x7d;
      uVar10 = 0;
      ovr_season_usesDifficulty();
      pcVar2 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%d%%");
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)uVar3 >> 8),CONCAT12((char)uVar3,pcVar2)),
                 CONCAT11(uVar10,uVar8));
      uVar8 = 0xdc;
      uVar10 = 0;
      ovr_season_usesGPromotableCount2();
      pcVar2 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%d");
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)uVar3 >> 8),CONCAT12((char)uVar3,pcVar2)),
                 CONCAT11(uVar10,uVar8));
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
  undefined2 in_stack_00000008;
  
  if (sheet->stats[statIndex] < 0x12) {
    for (bVar1 = 0; bVar1 < 3; bVar1 = bVar1 + 1) {
      if ((10 < sheet->stats[bVar1]) && (statIndex != bVar1)) {
        return 1;
      }
    }
  }
  return 0;
}



/* 4d05:0dbe */

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
  undefined2 in_stack_00000006;
  far_t entries;
  far_t entries_00;
  undefined1 uVar6;
  uint8_t menuItems;
  undefined2 auStack_28 [7];
  char cStack_1a;
  byte bStack_19;
  uint8_t statIndex;
  byte abStack_17 [5];
  uint8_t classStatMap2;
  uint8_t classStatMap1;
  
  uVar6 = (undefined1)(unaff_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
  dst.ofs = (uint16_t)&classStatMap1;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar6;
  F_SCOPY(far_from_u32((uint32_t)(0x241049dd)),dst);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = (char)unaff_SS;
  dst_00.ofs = (uint16_t)&classStatMap2;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = uVar6;
  F_SCOPY(far_from_u32((uint32_t)(0x241049e4)),dst_00);
  while( true ) {
    _fsetmem(&menuItems,unaff_SS,0x10);
    auStack_28[0] = 0x2410;
    _menuItems = 0x4d9b;
    bStack_19 = 1;
    bVar2 = manage_statSelectable((&classStatMap1)[sheet->cls],sheet);
    if (bVar2 != 0) {
      abStack_17[bStack_19] = (&classStatMap1)[sheet->cls];
      uVar1 = ((far_t *)GStatsLabels + (&classStatMap1)[sheet->cls])->ofs;
      uVar5 = (uint)bStack_19;
      auStack_28[uVar5 * 2] =
           *(undefined2 *)((int)&GStatsLabels[0].seg + (uint)(&classStatMap1)[sheet->cls] * 4);
      *(uint16_t *)(&menuItems + uVar5 * 4) = uVar1;
      bStack_19 = bStack_19 + 1;
    }
    puVar3 = &classStatMap2 + sheet->cls;
    if (*puVar3 != 0xff) {
      bVar2 = manage_statSelectable((&classStatMap2)[sheet->cls],sheet);
      puVar3 = (uint8_t *)CONCAT11(extraout_AH,bVar2);
      if (bVar2 != 0) {
        abStack_17[bStack_19] = (&classStatMap2)[sheet->cls];
        puVar3 = (uint8_t *)
                 *(undefined2 *)((int)&GStatsLabels[0].seg + (uint)(&classStatMap2)[sheet->cls] * 4)
        ;
        uVar1 = ((far_t *)GStatsLabels + (&classStatMap2)[sheet->cls])->ofs;
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
                   ,0x2410);
    entries.seg = unaff_SS;
    entries.ofs = (uint16_t)&menuItems;
    pcVar4 = ovr_uiInputText(entries,(uint)bStack_19,far_from_u32((uint32_t)(0x0)),0x0);
    cStack_1a = (char)pcVar4;
    if (cStack_1a == '\0') {
      return 0;
    }
    if (cStack_1a == '\x01') break;
    abStack_17[0] = abStack_17[((uint)pcVar4 & 0xff) - 1];
    ovr_drawString((char *)"Select ability to adjust downwards by two points.",0x2410);
    _fsetmem(&menuItems,unaff_SS,0x10);
    auStack_28[0] = 0x2410;
    _menuItems = 0x4e3a;
    bStack_19 = 1;
    for (statIndex = 0x0; statIndex < 3; statIndex = statIndex + 0x1) {
      if ((10 < sheet->stats[statIndex]) && (abStack_17[0] != statIndex)) {
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
    pcVar4 = ovr_uiInputText(entries_00,(uint)bStack_19,far_from_u32((uint32_t)(0x0)),0x0);
    cStack_1a = (char)pcVar4;
    if (cStack_1a == '\0') {
      return 0;
    }
    if (cStack_1a != '\x01') {
      sheet->stats[abStack_17[0]] = sheet->stats[abStack_17[0]] + 1;
      sheet->stats[abStack_17[((uint)pcVar4 & 0xff) - 1]] =
           sheet->stats[abStack_17[((uint)pcVar4 & 0xff) - 1]] - 2;
      manage_openTalkWindow();
      manage_usesLitoa10(sheet);
    }
  }
  return 1;
}



/* 4d05:1095 */

undefined2 __cdecl16far alignmentDlg(char_sheet_t *sheet)

{
  far_t dst;
  uint8_t done;
  char *pcVar1;
  uint uVar2;
  uint16_t unaff_SS;
  undefined2 in_stack_00000006;
  far_t entries;
  char cStack_c;
  uint8_t inputBuf;
  
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
  dst.ofs = (uint16_t)&inputBuf;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)(unaff_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x24104a03)),dst);
  do {
    ovr_drawString((char *)"Select an alignment.",0x2410);
    pcVar1 = ovr_uiInputText(far_from_u32((uint32_t)(0x24104927)),3,far_from_u32((uint32_t)(0x0)),0x0);
    uVar2 = (uint)pcVar1 & 0xff;
    if (uVar2 == 0) {
      return 0;
    }
    cStack_c = (char)pcVar1;
    sheet->alignment = cStack_c - 1;
    sheet->statMask = sheet->statMask | 4;
    if (CurPartySlot != '\0') {
      return 1;
    }
    ovr_drawString((char *)((far_t *)&GAlignmentString + uVar2)->ofs,
                   *(uint16_t *)((int)&GAlignmentString.seg + uVar2 * 4));
    entries.seg = unaff_SS;
    entries.ofs = (uint16_t)&inputBuf;
    pcVar1 = ovr_uiInputText(entries,2,far_from_u32((uint32_t)(0x0)),0x0);
    if (((uint)pcVar1 & 0xff) == 0) {
      return 0;
    }
  } while (((uint)pcVar1 & 0xff) != 1);
  return 1;
}



/* 4d05:1146 */

bool __cdecl16far uiPickGender(char_sheet_t *sheet)

{
  char *pcVar1;
  bool bVar2;
  undefined2 in_stack_00000006;
  char cStack_4;
  
  ovr_drawString((char *)"Male or female?",0x2410);
  pcVar1 = ovr_uiInputText(far_from_u32((uint32_t)(0x24104933)),2,far_from_u32((uint32_t)(0x0)),0x0);
  bVar2 = ((uint)pcVar1 & 0xff) != 0;
  if (bVar2) {
    cStack_4 = (char)pcVar1;
    sheet->gender = cStack_4 - 1;
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
  int iVar5;
  uint16_t unaff_SS;
  undefined2 in_stack_00000006;
  far_t dst;
  uint8_t classLimits;
  int iStack_4;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&classLimits;
  F_SCOPY(far_from_u32((uint32_t)(0x24104a0b)),dst);
  iStack_4 = 0;
  for (iVar5 = 0; iVar5 < (int)(uint)sheet->race; iVar5 = iVar5 + 1) {
    uVar2 = ovr_randBelow((uint)(&classLimits)[sheet->cls]);
    uVar3 = uVar2 & 0xff;
    cVar1 = manage_abilityModifier(sheet->stats[4]);
    iVar4 = uVar3 + (int)cVar1 + 1;
    if (iVar4 < 1) {
      iVar4 = 1;
    }
    iStack_4 = iStack_4 + iVar4;
  }
  sheet->hp[0] = (byte)iStack_4;
  sheet->hp[1] = (byte)iStack_4;
  sheet->statMask = sheet->statMask | 0x10;
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
  uint16_t uVar6;
  undefined4 uVar7;
  far_t entries;
  far_t entries_00;
  far_t handle;
  char cVar8;
  char cVar9;
  bool bVar10;
  bool bVar11;
  undefined1 uVar12;
  int iVar13;
  uint16_t uVar14;
  uint uVar15;
  uint uVar16;
  char *pcVar17;
  uint32_t *puVar18;
  far_t *pfVar19;
  uint32_t *puVar20;
  far_t *pfVar21;
  char_sheet_t *pcVar22;
  char *pcVar23;
  int iVar24;
  char cVar25;
  undefined2 in_CX;
  undefined2 in_DX;
  uint8_t *puVar26;
  entity_t *peVar27;
  entity_t *peVar28;
  far_t *unaff_BP;
  char *unaff_SI;
  char *unaff_DI;
  undefined2 uVar29;
  undefined2 unaff_ES;
  uint8_t *unaff_SS;
  char *in_stack_00000000;
  uint16_t in_stack_00000002;
  uint16_t uStack0006;
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
  ulong uVar30;
  undefined1 uVar31;
  undefined1 uVar32;
  undefined1 uVar33;
  uint8_t uVar34;
  uint8_t uVar35;
  char in_stack_0000fff3;
  byte bVar36;
  undefined1 uVar37;
  byte bVar38;
  undefined1 uVar39;
  
  uVar14 = CONCAT11((char)((uint)in_DX >> 8),(byte)index);
  uVar15 = index & 0xff;
  if (6 < uVar15) {
    return (char *)0x0;
  }
  peVar28 = (entity_t *)(uVar15 * 2);
  cVar9 = (char)unaff_SS;
  bVar38 = (byte)((uint)unaff_SS >> 8);
  switch(uVar15) {
  case 0:
    cVar9 = in(uVar14);
    *unaff_DI = cVar9;
    midpakAd.ofs = (uint16_t)stshStoreFile_2(unaff_BP,in_stack_00000000,in_stack_00000002);
    midpakAd.seg = uVar14;
    cmidpakComOfs = stshStoreFile_2((far_t *)"cmidpak.com",(char *)"puppetmaker" + 3,1);
    _cmidpakComSeg = uVar14;
    ibmsndComOfs = stshStoreFile_2((far_t *)"ibmsnd.com",(char *)"puppetmaker" + 3,1);
    ibmsndComSeg = uVar14;
    sblasterComOfs = stshStoreFile_2((far_t *)"sblaster.com",(char *)"puppetmaker" + 3,1);
    audioPlaceholder2.seg = 0;
    audioPlaceholder2.ofs = 0;
    sblasterComSeg = uVar14;
    fibmbakComOfs = stshStoreFile_2((far_t *)"fibmbak.com",(char *)"puppetmaker" + 3,1);
    fibmbakComSeg = uVar14;
    pfVar21 = stshStoreFile_2((far_t *)"sbpro.com",(char *)"puppetmaker" + 3,1);
    sbproComOfs = pfVar21;
    sbproComSeg = uVar14;
    sbproComCopyOfs = pfVar21;
    sbproComCopySeg = uVar14;
    paudioComOfs = stshStoreFile_2((far_t *)"paudio.com",(char *)"puppetmaker" + 3,1);
    sblasterComCopySeg = sblasterComSeg;
    sblasterComCopyOfs = sblasterComOfs;
    pfVar19 = sblasterComOfs;
    paudioComSeg = pfVar21;
    adlibComOfs = stshStoreFile_2((far_t *)"adlib.com",(char *)"puppetmaker" + 3,1);
    adlibComSeg = pfVar19;
    adlibgComOfs = stshStoreFile_2((far_t *)"adlibg.com",(char *)"puppetmaker" + 3,1);
    audioPlaceholder3.seg = 0;
    audioPlaceholder3.ofs = 0;
    musDriver0Seg = 0;
    musDriver0Ofs = 0;
    adlibgComSeg = pfVar19;
    sbfmAdvOfs = stshStoreFile_2((far_t *)"sbfm.adv",(char *)"puppetmaker" + 3,1);
    audioPlaceholder0.seg = 0;
    audioPlaceholder0.ofs = 0;
    audioPlaceholder1.seg = 0;
    audioPlaceholder1.ofs = 0;
    sbfmAdvSeg = pfVar19;
    sbp2fmAdvOfs = stshStoreFile_2((far_t *)"sbp2fm.adv",(char *)"puppetmaker" + 3,1);
    sbp2fmAdvSeg = pfVar19;
    sbp1fmAdvOfs = stshStoreFile_2((far_t *)"sbp1fm.adv",(char *)"puppetmaker" + 3,1);
    sbp1fmAdvSeg = pfVar19;
    pasfmAdvOfs = stshStoreFile_2((far_t *)"pasfm.adv",(char *)"puppetmaker" + 3,1);
    pasfmAdvSeg = pfVar19;
    pasoplAdvOfs = stshStoreFile_2((far_t *)"pasopl.adv",(char *)"puppetmaker" + 3,1);
    pasoplAdvSeg = pfVar19;
    adlibAdvOfs = stshStoreFile_2((far_t *)"adlib.adv",(char *)"puppetmaker" + 3,1);
    adlibAdvSeg = pfVar19;
    adlibgAdvOfs = stshStoreFile_2((far_t *)"adlibg.adv",(char *)"puppetmaker" + 3,1);
    adlibgAdvSeg = pfVar19;
    mt32mpuAdvOfs = stshStoreFile_2((far_t *)"mt32mpu.adv",(char *)"puppetmaker" + 3,1);
    mt32mpuAdvSeg = pfVar19;
    return (char *)mt32mpuAdvOfs;
  case 1:
    iVar13 = ovr_ovc23_findClearColumn(GfxRndSeed,GfxRndSeed2);
    if (iVar13 < 0) {
      ovr_drawTextAt((char *)"You cannot attract units to this location.",0x2410);
      pcVar17 = (char *)"puppetmaker" + 3;
      ((uint8_t *)menuItemRow)[index] = 0x0;
    }
    else {
      uVar34 = 0x6f;
      uVar12 = 0x23;
      bVar38 = (byte)index;
      callResultTemp = func_0x0004f501();
      if (callResultTemp < CONCAT11(uVar12,uVar34)) {
        uVar34 = (uint8_t)callResultTemp;
        uVar12 = (undefined1)(callResultTemp >> 8);
        ((uint8_t *)menuItemRow)[index] = uVar34;
      }
      uVar7 = *(undefined4 *)((uint)bVar38 << 2);
      cVar9 = *(char *)((int)uVar7 + 0x2f);
      pcVar17 = (char *)CONCAT11((char)(((uint)bVar38 << 2) >> 8),cVar9);
      if (cVar9 != -1) {
        ovr_ovc41_pluralSuffix(CONCAT11(uVar12,uVar34));
        uVar14 = 0x2410;
        pcVar17 = ovr_stsprintf(acStack_56,(char *)unaff_SS,
                                (char *)"Attracting %d of a possible %d %s%s to this location.");
        ovr_drawTextAt(pcVar17,uVar14);
      }
    }
    return pcVar17;
  case 2:
    ((int *)StshHandles)[(int)unaff_SI] = uVar15;
    *(undefined2 *)((int)(long *)StshPtrs + (int)unaff_SI * 4 + 2) = 0;
    *(undefined2 *)((long *)StshPtrs + (int)unaff_SI) = 0;
    return unaff_SI;
  case 3:
    for (iVar13 = 0; iVar13 < (int)(uint)GLeaderCount; iVar13 = iVar13 + 1) {
      if (((*(char *)((int)*(undefined4 *)(iVar13 << 2) + 0x3d) != '\0') &&
          (uVar14 = 0x2410, *(int *)((int)*(undefined4 *)(iVar13 << 2) + 0x39) == GfxRndSeed)) &&
         (uVar14 = 0x2410, *(uint16_t *)((int)*(undefined4 *)(iVar13 << 2) + 0x3b) == GfxRndSeed2))
      {
        if (GCharLevelsInc != '\0') {
          uVar29 = (undefined2)((ulong)*(undefined4 *)(iVar13 << 2) >> 0x10);
          iVar24 = (int)*(undefined4 *)(iVar13 << 2);
          puVar3 = (uint *)(iVar24 + 0x56);
          uVar15 = *puVar3;
          *puVar3 = *puVar3 + 10000;
          piVar4 = (int *)(iVar24 + 0x58);
          *piVar4 = *piVar4 + (uint)(0xd8ef < uVar15);
          GCharLevelsInc = '\0';
        }
        pfVar19 = manage_settlementScreen((byte)iVar13);
        ovr_stats_openCastlePanel();
        ovr_ovc41_usesGMenuItem();
        return (char *)pfVar19;
      }
    }
    ovr_stats_drawStatsPanel();
    if (PartyCount == 0) {
      pcVar17 = (char *)(uint)CurPartySlot;
      if (PartySize <= CurPartySlot) {
        ovr_ovc41_usesGMenuItem();
        return pcVar17;
      }
      pcVar22 = chargen();
      uVar32 = (undefined1)uVar14;
      uVar33 = (undefined1)(uVar14 >> 8);
      uVar12 = SUB21(pcVar22,0);
      uVar31 = (undefined1)((uint)pcVar22 >> 8);
      pcVar17 = (char *)((uint)pcVar22 | uVar14);
      if (pcVar17 == (char *)0x0) {
        ovr_stats_openCastlePanel();
        ovr_ovc41_usesGMenuItem();
        return pcVar17;
      }
      iVar13 = 0;
      while ((iVar13 < (int)(uint)GLeaderCount &&
             (*(char *)((int)*(undefined4 *)(iVar13 << 2) + 0x28) != '\0'))) {
        iVar13 = iVar13 + 1;
      }
      if (iVar13 < (int)(uint)GLeaderCount) {
        PartyCount = (char)iVar13 + 1;
        uVar29 = *(undefined2 *)((uint)PartyCount * 4 + -2);
        (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uVar29;
        handle.ofs = *(undefined2 *)((uint)PartyCount * 4 + -4);
        (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)uVar29 >> 8);
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
      pbVar5 = (byte *)(CONCAT11(uVar31,uVar12) + 0x28);
      *pbVar5 = *pbVar5 | 0x40;
      *(char *)(CONCAT11(uVar31,uVar12) + 0x51) = PartyCount - 1;
      uVar15 = (uint)PartyCount;
      pcVar22 = (char_sheet_t *)((char *)"halfling castle" + 0xc);
      *(undefined2 *)(uVar15 * 4 + -2) = CONCAT11(uVar33,uVar32);
      *(undefined2 *)(uVar15 * 4 + -4) = CONCAT11(uVar31,uVar12);
      if (CurPartySlot == 0) {
        *(undefined1 *)(CONCAT11(uVar31,uVar12) + 0x86) = 1;
      }
      CurPartySlot = CurPartySlot + 1;
    }
    else {
      manage_openTalkWindow();
      pcVar22 = (char_sheet_t *)*(undefined2 *)((uint)PartyCount * 4 + -4);
      manage_usesLitoa10(pcVar22);
    }
    pcVar17 = ovr_fmVsprintf((char *)"Place %s here.",(char *)"puppetmaker" + 3);
    ovr_drawString(pcVar17,(uint16_t)pcVar22);
    (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = cVar9;
    entries_00.ofs = (uint16_t)&stack0xfff2;
    (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = bVar38;
    pcVar17 = ovr_uiInputText(entries_00,2,far_from_u32((uint32_t)(0x0)),0x0);
    pcVar23 = (char *)((uint)pcVar17 & 0xff);
    if (((uint)pcVar17 & 0xff) == 1) {
      pcVar23 = (char *)(PartyCount - 1);
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
    return pcVar23;
  case 5:
    puVar18 = ovr_mkp((uint32_t *)unaff_BP,(uint16_t)in_stack_00000000,in_stack_00000002);
    (*(uint8_t *)((uint8_t *)&(index))) = (byte)puVar18;
    (*(uint8_t *)((uint8_t *)&(index) + 1)) = (undefined1)((uint)puVar18 >> 8);
    if ((char)*(uint32_t *)CONCAT22(uVar14,puVar18) == '\0') {
      uStack0006 = uVar14;
      pfVar19 = fmMalloc((far_t *)*(undefined2 *)((int)puVar18 + 5),
                         CONCAT13((*(uint8_t *)((uint8_t *)&(index) + 1)),CONCAT12((byte)index,in_stack_00000002)));
      uVar34 = (uint8_t)pfVar19;
      uVar12 = (undefined1)((uint)pfVar19 >> 8);
      if (pfVar19 == (far_t *)0x0 && uVar14 == 0) {
        puVar18 = (uint32_t *)0x0;
      }
      else {
        if (*(int *)((int)puVar18 + 0x11) == 0 && *(int *)((int)puVar18 + 0x13) == 0) {
          stshSeek(StshStrongDatHnd,CONCAT22(in_stack_00000002,*(undefined2 *)((int)puVar18 + 3)));
          uVar31 = 0xfd;
          uVar32 = 0x83;
          stshRead();
          pfVar19 = ovr_heapMalloc((far_t *)*(undefined2 *)((int)puVar18 + 5),
                                   CONCAT13((*(uint8_t *)((uint8_t *)&(index) + 1)),CONCAT12((byte)index,in_stack_00000002)));
          *(uint16_t *)((int)puVar18 + 0x13) = uVar14;
          *(undefined2 *)((int)puVar18 + 0x11) = pfVar19;
          if (*(int *)((int)puVar18 + 0x11) == 0 && *(int *)((int)puVar18 + 0x13) == 0) {
            bVar10 = false;
          }
          else {
            memcpy((char *)CONCAT13((char)((uint)*(undefined2 *)((int)puVar18 + 0x13) >> 8),
                                    CONCAT12((char)*(undefined2 *)((int)puVar18 + 0x13),
                                             *(undefined2 *)((int)puVar18 + 0x11))),
                   (char *)CONCAT22(CONCAT11(uVar32,uVar31),(char *)CONCAT11(uVar12,uVar34)),
                   *(word *)((int)puVar18 + 5));
            bVar10 = true;
          }
        }
        else {
          memcpy((char *)CONCAT13((char)(uVar14 >> 8),CONCAT12((char)uVar14,pfVar19)),
                 (char *)CONCAT22(*(undefined2 *)((int)puVar18 + 0x13),
                                  (char *)*(undefined2 *)((int)puVar18 + 0x11)),
                 *(word *)((int)puVar18 + 5));
          bVar10 = true;
        }
        if (bVar10) {
          puVar20 = ovr_mkp((uint32_t *)Stsh_2410_47f6.ofs,Stsh_2410_47f6.seg,in_stack_00000002);
          if ((uVar14 != uStack0006) || (puVar20 != puVar18)) {
            iVar13 = *(int *)((int)puVar18 + 0xf);
            iVar24 = *(int *)((int)puVar18 + 0xd);
            uVar14 = *(uint16_t *)((int)puVar18 + 0xb);
            uVar6 = *(uint16_t *)((int)puVar18 + 9);
            if (uVar6 != 0 || uVar14 != 0) {
              uVar29 = (undefined2)
                       (CONCAT13((char)(uVar14 >> 8),CONCAT12((char)uVar14,uVar6)) >> 0x10);
              *(int *)(uVar6 + 0xf) = iVar13;
              *(int *)(uVar6 + 0xd) = iVar24;
            }
            if (iVar24 != 0 || iVar13 != 0) {
              uVar29 = (undefined2)
                       (CONCAT13((char)((uint)iVar13 >> 8),CONCAT12((char)iVar13,iVar24)) >> 0x10);
              *(uint16_t *)(iVar24 + 0xb) = uVar14;
              *(uint16_t *)(iVar24 + 9) = uVar6;
              uVar6 = StshCtPtr2.ofs;
              uVar14 = StshCtPtr2.seg;
            }
            StshCtPtr2.seg = uVar14;
            StshCtPtr2.ofs = uVar6;
            uVar14 = Stsh_2410_47f6.ofs;
            *(uint16_t *)((int)puVar18 + 0xf) = Stsh_2410_47f6.seg;
            *(uint16_t *)((int)puVar18 + 0xd) = uVar14;
            *(undefined2 *)((int)puVar18 + 0xb) = 0;
            *(undefined2 *)((int)puVar18 + 9) = 0;
            *(uint16_t *)(Stsh_2410_47f6.ofs + 0xb) = uStack0006;
            *(undefined2 *)(Stsh_2410_47f6.ofs + 9) = puVar18;
            Stsh_2410_47f6.seg = uStack0006;
            Stsh_2410_47f6.ofs = (uint16_t)puVar18;
          }
        }
        puVar18 = (uint32_t *)CONCAT11(uVar12,uVar34);
      }
    }
    return (char *)puVar18;
  case 6:
    goto switchD_4000_e2bf_caseD_6;
  }
  if ((uVar15 == 0) && (manage_openTalkWindow(), in_stack_0000fff3 == '\x02')) {
    if (ScreenMode == '\0') {
      manage_openTalkWindow();
    }
    TextBlitY = 0xc;
    TextBlitX = 0x11;
    uVar34 = (uint8_t)Font02.seg;
    if ((byte)index == 0xff) {
      uVar35 = 0xf8;
      cVar9 = 'T';
      uVar15 = ovr_blitLabel((char *)"Total population.",(uint8_t *)((char *)"puppetmaker" + 3),
                             Font02.ofs,uVar34);
      *unaff_SI = *unaff_SI + (char)(uVar15 >> 8) + ((undefined1 *)0xfff3 < &stack0xfff2);
      *(undefined1 *)((int)&(((entity_t *)*(entity_t **)&Entities)->base).entity + uVar15 + 1) = 0;
      uVar29 = (undefined2)((ulong)Entities >> 0x10);
      *(undefined1 *)((int)&((entity_t *)Entities)[(int)unaff_SI].base.state + 1) =
           (char)((entity_t *)Entities)[(int)unaff_SI].base.flags32;
      if (unaff_SI + 1 < EntityCount) {
        pcVar17 = (char *)"thief" + 5;
        ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.");
        return pcVar17;
      }
      if ((uVar35 != 0x0) || (cVar9 != '\0')) {
        if ((char)((uint)((int)unaff_SI * 0x37) >> 8) == '\0') {
          ovr_stop_audio();
          CurSfxType3 = 0xff;
          ovr_play_sfx(90,0);
        }
        else if (cVar9 == '\0') {
          if (uVar35 != 0x0) {
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
    uVar14 = Font02.ofs;
    ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,acStack_1b6),
                       (char *)CONCAT22(Font02.seg,Font02.ofs),
                       (char *)CONCAT13((char)(Font02.seg >> 8),CONCAT12(uVar34,Font02.ofs)),0x4b,
                       '\x03');
    func_0x0005d3f4();
    puVar26 = (uint8_t *)((char *)"puppetmaker" + 3);
    uStack_20 = 0x23f1;
    uStack_22 = 0x44;
    pcVar17 = ovr_stsprintf(acStack_13e,(char *)unaff_SS,(char *)"%s population, loyal to %s%s");
    ovr_blitLabel(pcVar17,puVar26,uVar14,uVar34);
    TextBlitY = TextBlitY + 0xc;
    iVar13 = ovr_font_textWidth("UNITS",(char *)CONCAT13((char)(Font02.seg >> 8),
                                                         CONCAT12((char)Font02.seg,Font02.ofs)));
    TextBlitX = 0x89 - iVar13;
    ovr_blitLabel((char *)"UNITS",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    iVar13 = ovr_font_textWidth("POPULATION",
                                (char *)CONCAT13((char)(Font02.seg >> 8),
                                                 CONCAT12((char)Font02.seg,Font02.ofs)));
    uVar14 = 0xd4 - iVar13;
    cVar8 = '\x10';
    bVar36 = 0x24;
    TextBlitX = uVar14;
    ovr_blitLabel((char *)"POPULATION",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    iVar13 = 0;
    while( true ) {
      TextBlitY = TextBlitY + 0xc;
      cVar25 = (char)in_CX;
      if ((int)(uint)bVar36 <= iVar13) break;
      TextBlitX = 0x11;
      if ((iVar13 < 5) || (cVar8 == '\0')) {
        ovr_blitLabel((char *)auStack_96[iVar13 * 2],(uint8_t *)auStack_96[iVar13 * 2 + 1],
                      Font02.ofs,(uint8_t)Font02.seg);
      }
      else {
        uVar7 = *(undefined4 *)((index & 0xff) << 2);
        uVar15 = (uint)*(byte *)((int)uVar7 + 0x2f);
        ovr_blitLabel((char *)auStack_11a[iVar13 * 2 + uVar15 * 8],
                      (uint8_t *)auStack_11a[iVar13 * 2 + uVar15 * 8 + 1],Font02.ofs,
                      (uint8_t)Font02.seg);
      }
      func_0x0005f303();
      ovr_stsprintf(acStack_13e,(char *)unaff_SS,(char *)"%d");
      iVar24 = ovr_font_textWidth((char *)CONCAT13(bVar38,CONCAT12(cVar9,acStack_13e)),
                                  (char *)CONCAT13((char)(Font02.seg >> 8),
                                                   CONCAT12((char)Font02.seg,Font02.ofs)));
      TextBlitX = 0x89 - iVar24;
      ovr_blitLabel(acStack_13e,unaff_SS,Font02.ofs,(uint8_t)Font02.seg);
      ovr_stsprintf(acStack_13e,(char *)unaff_SS,(char *)"%d");
      iVar24 = ovr_font_textWidth((char *)CONCAT13(bVar38,CONCAT12(cVar9,acStack_13e)),
                                  (char *)CONCAT13((char)(Font02.seg >> 8),
                                                   CONCAT12((char)Font02.seg,Font02.ofs)));
      uVar14 = 0xd4 - iVar24;
      TextBlitX = uVar14;
      cVar8 = cVar9;
      bVar36 = bVar38;
      ovr_blitLabel(acStack_13e,unaff_SS,Font02.ofs,(uint8_t)Font02.seg);
      iVar13 = iVar13 + 1;
    }
    CurSfxType3 = 0x3c;
    puVar26 = &stack0xfff2;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = cVar9;
    entries.ofs = (uint16_t)auStack_66;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = bVar38;
    uVar29 = ovr_ovc28_usesUiInputText
                       (entries,(uint16_t)unaff_DI,far_from_u32((uint32_t)(0x0)),puVar26,(uint16_t)unaff_SS);
    cVar9 = (char)uVar29;
    keyboardInputMode = 0;
    if (((cVar9 != '\0') && (cVar9 != '\x01')) && (cVar9 != -2)) {
      (&stack0xbac4)[(int)unaff_DI] = (&stack0xbac4)[(int)unaff_DI] + cVar25;
      iVar24 = 0x2410;
      do {
        bVar38 = *(byte *)(iVar24 * uVar14 + 0x21);
        uVar12 = (undefined1)(iVar24 * uVar14 >> 8);
        iVar24 = iVar13;
        if (*(byte *)(iVar13 * 0x34 + 0x22) < bVar38) {
          bVar38 = *(byte *)(iVar13 * 0x34 + 0x22);
          uVar12 = (undefined1)((uint)(iVar13 * 0x34) >> 8);
          *(byte *)(iVar13 * 0x34 + 0x21) = bVar38;
        }
        do {
          iVar24 = iVar24 + 1;
          if ((int)(uint)AgntCount <= iVar24) {
            uVar14 = ovr_audio_panFromX(_paStack0008);
            ovr_play_sfxU(0x1c,0,uVar14);
            return (char *)CONCAT11((char)(uVar14 >> 8),1);
          }
        } while (*(uint16_t *)(iVar24 * 0x34 + 0x1b) != paStack0008->owner);
        if (puVar26[0x32] < *(byte *)(iVar24 * 0x34 + 0x22)) {
          *(uint8_t *)(iVar24 * 0x34 + 0x22) = puVar26[0x32];
        }
        uVar14 = 0x34;
        iVar13 = iVar24;
      } while( true );
    }
    if (cVar9 == -2) {
      Cancelled = 1;
    }
    return (char *)"puppetmaker" + 3;
  }
  do {
    uVar29 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
    peVar27 = (entity_t *)in_stack_0000ffe2;
    (peVar27->base).target =
         (byte)((int)(uint)*(byte *)((int)&(peVar27->base).owner +
                                    ((int)(uint)(peVar28->base).faction >> 2)) >>
               (((peVar27->base).faction & 3) << 1)) & 3;
    cVar9 = func_0x0004f32d();
    peVar28 = (entity_t *)in_stack_0000ffe2;
    uVar29 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
    if (cVar9 == '\0') {
      (in_stack_0000ffe2->base).x =
           (in_stack_0000ffe2->base).x + (int)*(char *)((peVar28->base).target + 0x885);
      puVar1 = &(peVar28->base).y;
      *puVar1 = *puVar1 + (int)*(char *)((peVar28->base).target + 0x889);
      puVar2 = &(peVar28->base).faction;
      *puVar2 = *puVar2 + 0x1;
    }
    else {
      (peVar28->base).faction = 0x0;
      *(undefined1 *)&(peVar28->base).state = 0;
    }
L_attact_3f0b_1082_1477:
    uVar30 = 0x1000000;
    uVar15 = ovr_alignUp4((((entity_t *)in_stack_0000ffe2)->base).destX);
    uVar37 = (undefined1)uVar15;
    uVar39 = (undefined1)(uVar15 >> 8);
    uVar14 = (in_stack_0000ffe2->base).x;
    uVar32 = (undefined1)uVar14;
    uVar33 = (undefined1)(uVar14 >> 8);
    uVar12 = 0x79;
    uVar31 = 0x23;
    uVar16 = ovr_alignUp4(uVar14);
    uVar15 = CONCAT11(uVar33,uVar32);
    if (CONCAT11(uVar39,uVar37) == uVar16) {
      uVar29 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      peVar28 = (entity_t *)in_stack_0000ffe2;
      uVar15 = CONCAT11(uVar33,uVar32);
      if ((peVar28->base).destY == (peVar28->base).y) {
        (peVar28->base).destX = 0;
        (peVar28->base).destY = 0;
        if (*(char *)((int)&(peVar28->base).entity + 3) == -1) {
          cVar9 = -1;
        }
        else {
          uVar7 = *(undefined4 *)((uint)*(byte *)((int)&(peVar28->base).entity + 3) << 2);
          cVar9 = *(char *)((int)uVar7 + 0x89);
        }
        uVar15 = CONCAT11(uVar33,uVar32);
        if (cVar9 != -1) {
          for (uVar16 = 0; uVar15 = CONCAT11(uVar33,uVar32), uVar16 < SquareRecCount;
              uVar16 = uVar16 + 1) {
            uVar15 = ovr_alignUp4(*(int *)(uVar16 * 0x13));
            bVar38 = (byte)uVar15;
            uVar37 = (undefined1)(uVar15 >> 8);
            uVar14 = (in_stack_0000ffe2->base).x;
            uVar32 = (undefined1)uVar14;
            uVar33 = (undefined1)(uVar14 >> 8);
            uVar12 = 0x79;
            uVar31 = 0x23;
            uVar15 = ovr_alignUp4(uVar14);
            if ((CONCAT11(uVar37,bVar38) == uVar15) &&
               (*(uint16_t *)(uVar16 * 0x13 + 2) == (((entity_t *)in_stack_0000ffe2)->base).y)) {
              uVar15 = uVar16 * 0x13 + (uint)bVar38 + 0xe;
              uVar12 = 0x79;
              uVar31 = 0x23;
              func_0x0004f930();
              if (*(uint16_t *)(uVar16 * 0x13 + 2) == GfxRndSeed2) {
                uVar15 = ovr_alignUp4(*(int *)(uVar16 * 0x13));
                bVar38 = (byte)uVar15;
                uVar37 = (undefined1)(uVar15 >> 8);
                uVar32 = (undefined1)GfxRndSeed;
                uVar33 = (undefined1)((uint)GfxRndSeed >> 8);
                uVar12 = 0x79;
                uVar31 = 0x23;
                uVar16 = ovr_alignUp4(GfxRndSeed);
                uVar15 = CONCAT11(uVar33,uVar32);
                if (CONCAT11(uVar37,bVar38) == uVar16) {
                  (&stack0xfff2)[bVar38] = 1;
                  uVar15 = CONCAT11(uVar33,uVar32);
                }
              }
              break;
            }
          }
        }
      }
    }
    if (AgntFlag1 != false) {
      uVar29 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      if ((((in_stack_0000ffe2->base).x < GfxRndSeed - 2U) ||
          (GfxRndSeed + 1U < (in_stack_0000ffe2->base).x)) ||
         ((((entity_t *)in_stack_0000ffe2)->base).y != GfxRndSeed2)) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      if (((uVar15 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uVar15)) ||
         (GfxRndSeed2 != CONCAT11(uVar31,uVar12))) {
        bVar11 = false;
      }
      else {
        bVar11 = true;
      }
      uVar30 = uVar30 & 0xff000000;
      if (bVar11 || bVar10) {
        if (bVar11) {
          if (bVar10) {
            uVar12 = func_0x0004f944();
            uVar30 = CONCAT31((int3)(uVar30 >> 8),uVar12);
            while (((char)uVar30 != '\0' &&
                   (pcVar17 = ovr_ovc15_textArena((int)unaff_DI), ((uint)pcVar17 & 0xff) != 0))) {
              uVar30 = CONCAT31((int3)(uVar30 >> 8),(char)uVar30 + -1);
            }
          }
          else {
            uVar30 = CONCAT31((int3)(uVar30 >> 8),
                              (char)((ulong)((((entity_t *)in_stack_0000ffe2)->base).animFrame + 0xf
                                            ) / 0x10));
            while (cVar9 = (char)uVar30, uVar30 = CONCAT31((int3)(uVar30 >> 8),cVar9 + -1),
                  cVar9 != '\0') {
              ovr_agnt_usesAgntCount6
                        ((entity_t *)
                         CONCAT13((char)((ulong)Entities >> 0x18),
                                  CONCAT12((char)((ulong)Entities >> 0x10),
                                           (entity_t *)Entities + (int)unaff_DI)));
            }
          }
        }
        else {
          ovr_ovc15_clearVisited();
          uVar30 = CONCAT31((int3)(uVar30 >> 8),
                            (char)((ulong)((((entity_t *)in_stack_0000ffe2)->base).animFrame + 0xf)
                                  / 0x10));
          while (cVar9 = (char)uVar30, uVar30 = CONCAT31((int3)(uVar30 >> 8),cVar9 + -1),
                cVar9 != '\0') {
            ovr_ovc15_textArena((int)unaff_DI);
          }
        }
      }
    }
    do {
      uVar34 = (uint8_t)(uVar30 >> 0x18);
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
        if (uVar34 != 0x0) {
          ovr_constr_usesBlitRect();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (uVar15 = 0; (int)uVar15 < 5; uVar15 = uVar15 + 1) {
          if ((&stack0xfff2)[uVar15] != '\0') {
            ovr_ovc41_usesMiceBlitRect(uVar15);
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
      uVar29 = (undefined2)((ulong)Entities >> 0x10);
      in_stack_0000ffe2 = (entity_t *)CONCAT22(uVar29,(entity_t *)Entities + (int)unaff_DI);
      uVar15 = ovr_alignUp4(((entity_t *)Entities)[(int)unaff_DI].base.destX);
      uVar12 = (undefined1)uVar15;
      uVar31 = (undefined1)(uVar15 >> 8);
      uVar15 = ovr_alignUp4((in_stack_0000ffe2->base).x);
      if ((CONCAT11(uVar31,uVar12) == uVar15) &&
         (uVar29 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10),
         (((entity_t *)in_stack_0000ffe2)->base).destY == (((entity_t *)in_stack_0000ffe2)->base).y)
         ) {
        func_0x0004fb8e();
      }
      unaff_ES = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      peVar28 = (entity_t *)in_stack_0000ffe2;
    } while (((peVar28->base).destX == 0 && (peVar28->base).destY == 0) ||
            (*(char *)((int)&(peVar28->base).entity + 1) != '\0'));
  } while ((peVar28->base).faction < (byte)(peVar28->base).state);
  uVar29 = ovr_ovc07_signum((peVar28->base).destX - (in_stack_0000ffe2->base).x);
  cVar9 = (char)uVar29;
  uVar12 = (undefined1)((uint)uVar29 >> 8);
  uVar29 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
  iVar13 = ovr_ovc07_signum((((entity_t *)in_stack_0000ffe2)->base).destY -
                            (((entity_t *)in_stack_0000ffe2)->base).y);
  if (((CONCAT11(uVar12,cVar9) == 0) || (uVar14 = ovr_randBelow(2), (char)uVar14 == '\0')) ||
     (cVar8 = func_0x0004f412(), cVar8 != '\0')) {
    if ((iVar13 == 0) || (cVar8 = func_0x0004f412(), cVar8 != '\0')) {
      if ((CONCAT11(uVar12,cVar9) == 0) || (cVar8 = func_0x0004f412(), cVar8 != '\0')) {
        uVar15 = ovr_ovc26_usesStExit((int)unaff_DI);
        if ((char)uVar15 == '\0') {
          uVar15 = ovr_ovc26_usesRandBelow
                             ((int)unaff_DI,(uint16_t)&stack0xffe9,(uint16_t)unaff_SS,
                              (uint16_t)&stack0xfff2,(uint16_t)unaff_SS);
          if ((uVar15 & 0xff) == 0) {
            peVar28 = (entity_t *)((uint)(((entity_t *)in_stack_0000ffe2)->base).gindex * 0x95);
            uVar14 = 0x195d;
switchD_4000_e2bf_caseD_6:
            if (peVar28[0xb4].base.teamCode == 0x0) {
              func_0x0004fb8e();
            }
          }
        }
        else {
          uVar29 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
          peVar28 = (entity_t *)in_stack_0000ffe2;
          (peVar28->base).target =
               (byte)((int)(uint)*(byte *)((int)&(peVar28->base).owner +
                                          ((int)(uint)(peVar28->base).faction >> 2)) >>
                     (((peVar28->base).faction & 3) << 1)) & 3;
          cVar9 = func_0x0004f32d();
          if (cVar9 == '\0') {
            uVar29 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
            peVar28 = (entity_t *)in_stack_0000ffe2;
            (in_stack_0000ffe2->base).x =
                 (in_stack_0000ffe2->base).x + (int)*(char *)((peVar28->base).target + 0x885);
            puVar1 = &(peVar28->base).y;
            *puVar1 = *puVar1 + (int)*(char *)((peVar28->base).target + 0x889);
            puVar2 = &(peVar28->base).faction;
            *puVar2 = *puVar2 + 0x1;
          }
        }
      }
      else {
        (in_stack_0000ffe2->base).x = (in_stack_0000ffe2->base).x + CONCAT11(uVar12,cVar9);
        (((entity_t *)in_stack_0000ffe2)->base).target = 0x2 - cVar9;
      }
    }
    else {
      uVar29 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      puVar1 = &(((entity_t *)in_stack_0000ffe2)->base).y;
      *puVar1 = *puVar1 + iVar13;
      (((entity_t *)in_stack_0000ffe2)->base).target = (char)iVar13 + 0x1;
    }
  }
  else {
    (in_stack_0000ffe2->base).x = (in_stack_0000ffe2->base).x + CONCAT11(uVar12,cVar9);
    (((entity_t *)in_stack_0000ffe2)->base).target = 0x2 - cVar9;
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
  uint16_t in_DX;
  uint16_t widths;
  int iVar6;
  char *unaff_SS;
  char acStack_9d [11];
  uint8_t menuItems;
  uint16_t auStack_90 [21];
  uint8_t msg;
  char_sheet_t *pcStack_16;
  uint16_t uStack_14;
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
      _fmemset(pcStack_16,uStack_14,0);
      pcStack_16->charIndex = 0xff;
      while( true ) {
        if (TimerSeed.lo == 0 && TimerSeed.hi == 0) {
          TimerSeed.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
          TimerSeed.lo = *(uint16_t *)BDA_DailyTimeCounter;
        }
        srand8(CONCAT13((char)(TimerSeed.hi >> 8),CONCAT12((char)TimerSeed.hi,TimerSeed.lo)));
        manage_openTalkWindow();
        manage_rollStats(pcStack_16);
        manage_usesLitoa10(pcStack_16);
        auStack_90[0] = 0x2410;
        _menuItems = 0x4fce;
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
        ovr_drawString((char *)"Reroll ability scores, or select the character\'s class.",0x2410);
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
      manage_usesLitoa10(pcStack_16);
      uVar5 = abilitiesDlg(pcStack_16);
      if ((uVar5 & 0xff) == 0) break;
      manage_rollHitPoints(pcStack_16);
      while( true ) {
        manage_usesLitoa10(pcStack_16);
        uVar5 = alignmentDlg(pcStack_16);
        if ((uVar5 & 0xff) == 0) break;
L_chargen_1661:
        manage_openTalkWindow();
        manage_usesLitoa10(pcStack_16);
        bVar2 = uiPickGender(pcStack_16);
        if (bVar2) {
          do {
            manage_blitTalkWindow();
            ovr_drawString((char *)"Select the character\'s name.",0x2410);
            while (pcStack_e = ovr_uiReadString((char *)0x0,0,6,(char *)0x0,0), uStack_c = widths,
                  pcStack_e == (char *)0x0 && widths == 0) {
              if (inputCancelled != '\0') {
                if (UserWantsExit == '\0') goto L_chargen_1661;
                goto L_chargen_17B2;
              }
              manage_blitTalkWindow();
              ovr_drawString((char *)"Please type your character\'s name. Esc go back.",0x2410);
            }
            ovr_drawString((char *)"Lawful" + 6,0x2410);
            __fstrncpy((char *)CONCAT22(uStack_14,pcStack_16),(char *)CONCAT22(uStack_c,pcStack_e),
                       0x27);
            (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uStack_c;
            handle.ofs = (uint16_t)pcStack_e;
            (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)(uStack_c >> 8);
            ovr_stshFree(handle);
            pcVar3 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"Keep %s.");
            ovr_drawString(pcVar3,widths);
            entries_00.seg = (uint16_t)unaff_SS;
            entries_00.ofs = (uint16_t)&keepDiscard;
            pcVar3 = ovr_uiInputText(entries_00,2,far_from_u32((uint32_t)(0x0)),0x0);
            uStack_10 = (uint)pcVar3 & 0xff;
            if (uStack_10 != 0) {
              if (uStack_10 != 2) {
                pcStack_16->statMask = pcStack_16->statMask | 2;
                manage_openTalkWindow();
                manage_usesLitoa10(pcStack_16);
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

/* [R2] string "halfling castle" */

void __cdecl16far manage_textHalflingCastle(void)

{
  uint *puVar1;
  int *piVar2;
  far_t gfx;
  far_t dst;
  far_t handle;
  char_sheet_t *pcVar3;
  uint uVar4;
  char *pcVar5;
  char_sheet_t *sheet;
  int iVar6;
  undefined2 uVar7;
  uint16_t unaff_SS;
  far_t entries;
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
  for (iStack_4 = 0; iVar6 = 0x2410, iStack_4 < (int)(uint)GLeaderCount; iStack_4 = iStack_4 + 1) {
    if (((*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3d) != '\0') &&
        (*(int *)((int)*(undefined4 *)(iStack_4 << 2) + 0x39) == GfxRndSeed)) &&
       (*(int *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3b) == GfxRndSeed2)) {
      if (GCharLevelsInc != '\0') {
        uVar7 = (undefined2)((ulong)*(undefined4 *)(iStack_4 << 2) >> 0x10);
        iVar6 = (int)*(undefined4 *)(iStack_4 << 2);
        puVar1 = (uint *)(iVar6 + 0x56);
        uVar4 = *puVar1;
        *puVar1 = *puVar1 + 10000;
        piVar2 = (int *)(iVar6 + 0x58);
        *piVar2 = *piVar2 + (uint)(0xd8ef < uVar4);
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
    pcVar3 = chargen();
    if (pcVar3 == (char_sheet_t *)0x0 && iVar6 == 0) {
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
      uVar7 = *(undefined2 *)((uint)PartyCount * 4 + -2);
      (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uVar7;
      handle.ofs = *(undefined2 *)((uint)PartyCount * 4 + -4);
      (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)uVar7 >> 8);
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
    pcVar3->statMask = pcVar3->statMask | 0x40;
    pcVar3->charIndex = PartyCount - 1;
    uVar4 = (uint)PartyCount;
    sheet = (char_sheet_t *)((char *)"halfling castle" + 0xc);
    *(int *)(uVar4 * 4 + -2) = iVar6;
    *(undefined2 *)(uVar4 * 4 + -4) = pcVar3;
    if (CurPartySlot == 0) {
      pcVar3->level = 1;
    }
    CurPartySlot = CurPartySlot + 1;
  }
  else {
    manage_openTalkWindow();
    sheet = (char_sheet_t *)*(undefined2 *)((uint)PartyCount * 4 + -4);
    manage_usesLitoa10(sheet);
  }
  pcVar5 = ovr_fmVsprintf((char *)"Place %s here.",(char *)"puppetmaker" + 3);
  ovr_drawString(pcVar5,(uint16_t)sheet);
  entries.seg = unaff_SS;
  entries.ofs = (uint16_t)&inputBuf;
  pcVar5 = ovr_uiInputText(entries,2,far_from_u32((uint32_t)(0x0)),0x0);
  uStack_6 = (uint)pcVar5 & 0xff;
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

char * __cdecl16far litoa10(char *buf,long n)

{
  bool bVar1;
  size_t sVar2;
  uint16_t len;
  uint32_t digit;
  long lVar3;
  undefined2 in_stack_00000006;
  uint8_t sign;
  
  if ((n < 0x10000) && (n < 0)) {
    bVar1 = true;
    n = CONCAT22(-(uint)((int)n != 0) - (*(uint16_t *)((uint8_t *)&(n) + 2)),-(int)n);
  }
  else {
    bVar1 = false;
  }
  digit = LMOD_at_(n,10);
  *_buf = (char)digit + '0';
  buf[1] = '\0';
  while (lVar3 = LDIV_at_(n,10), lVar3 != 0) {
    sVar2 = strlen(buf);
    if ((sVar2 & 3) == 3) {
      len = strlen(buf);
      _fmemmove((char *)CONCAT22(in_stack_00000006,buf + 1),_buf,len + 1);
      *_buf = ',';
    }
    sVar2 = strlen(buf);
    _fmemmove((char *)CONCAT22(in_stack_00000006,buf + 1),_buf,sVar2 + 1);
    n = LDIV_at_(n,10);
    lVar3 = LMOD_at_(n,10);
    *_buf = (char)lVar3 + '0';
  }
  if (bVar1) {
    sVar2 = strlen(buf);
    _fmemmove((char *)CONCAT22(in_stack_00000006,buf + 1),(char *)CONCAT22(in_stack_00000006,buf),
              sVar2 + 1);
    *_buf = '-';
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
          (char partyIndex,char unitType,int *resource1Count,int *resource1Seg,int *resource2Count,
          int *resource2Seg,int *resource3Count,int *resource3Seg,int *recordCount)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  unit_t *puVar5;
  uint uVar6;
  undefined2 uVar7;
  undefined2 in_stack_00000016;
  int *in_stack_00000018;
  int *in_stack_0000001c;
  int *in_stack_00000020;
  int iStack_4;
  
  iStack_4 = 0;
  *_resource1Count = 0;
  *_resource2Count = 0;
  *_resource3Count = 0;
  *_recordCount = 0;
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
          *_recordCount = *_recordCount + 1;
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
      *_resource1Count = *_resource1Count - *in_stack_0000001c;
      *_resource2Count = *_resource2Count - *in_stack_00000020;
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
        *_resource1Count = *_resource1Count + 1;
      }
      else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x02') {
        *_resource2Count = *_resource2Count + 1;
      }
      else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x03') {
        *_resource3Count = *_resource3Count + 1;
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
  int iVar2;
  char *pcVar3;
  char_sheet_t *widths;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int *unaff_SS;
  byte in_stack_00000004;
  uint16_t max_width;
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
  uint uStack_16;
  int iStack_14;
  int iStack_12;
  int iStack_10;
  int iStack_e;
  uint uStack_c;
  uint uStack_a;
  uint uStack_8;
  char_sheet_t *pcStack_6;
  undefined2 uStack_4;
  
  dst.seg = (uint16_t)unaff_SS;
  dst.ofs = (uint16_t)&resultPtrs;
  F_SCOPY(far_from_u32((uint32_t)(0x24104ada)),dst);
  for (iVar5 = 0; iVar5 < 5; iVar5 = iVar5 + 1) {
    uVar4 = *(undefined2 *)(&resultPtrs + iVar5 * 4);
    auStack_142[iVar5 * 2] = auStack_156[iVar5 * 2];
    *(undefined2 *)(&menuItems + iVar5 * 4) = uVar4;
  }
  for (iVar5 = 0; iVar5 < 0x1e; iVar5 = iVar5 + 1) {
    uVar4 = *(undefined2 *)((int)&GStructures[0].name + iVar5 * 6);
    auStack_12e[iVar5 * 2] = *(undefined2 *)((int)&GStructures[0].name + 2 + iVar5 * 6);
    *(undefined2 *)(&structNames + iVar5 * 4) = uVar4;
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
    ovr_blitGfxRect(gfx,0,0,(brect_t *)(BlitRects + 1),0x10,true);
  }
  TextBlitY = 0xc;
  TextBlitX = 0x11;
  term = (uint8_t)Font02.seg;
  if (in_stack_00000004 == 0xff) {
    ovr_blitLabel((char *)"All property.",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,term);
  }
  else {
    uStack_4 = ((undefined2 *)((uint)in_stack_00000004 * 4))[1];
    widths = (char_sheet_t *)*(undefined2 *)((uint)in_stack_00000004 * 4);
    max_width = Font02.ofs;
    pcStack_6 = widths;
    ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,acStack_68),(char *)CONCAT22(uStack_4,widths),
                       (char *)CONCAT22(Font02.seg,Font02.ofs),0x69,'\x03');
    manage_playerTitle(pcStack_6);
    pcVar3 = ovr_stsprintf(acStack_b8,(char *)unaff_SS,(char *)"Buildings belonging to %s%s");
    ovr_blitLabel(pcVar3,(uint8_t *)widths,max_width,term);
  }
  TextBlitY = TextBlitY + 0xc;
  TextBlitX = 0x11;
  ovr_blitLabel((char *)"Buildings",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                (uint8_t)Font02.seg);
  manage_usesBlitLabel2("Total",100);
  manage_usesBlitLabel2("Level 1",0x8c);
  manage_usesBlitLabel2("Level 2",0xb4);
  manage_usesBlitLabel2("Level 3",0xdc);
  TextBlitY = TextBlitY + 0xc;
  if (cStack_17 == '\x04') {
    iVar5 = 0x1a;
  }
  else if (cStack_17 == '\x03') {
    iVar5 = 0xd;
  }
  else {
    iVar5 = 0;
  }
  for (iVar6 = 0; iVar6 < 0xd; iVar6 = iVar6 + 1) {
    if (iVar6 + iVar5 < 0x1e) {
      TextBlitX = 0x11;
      iVar2 = (iVar6 + iVar5) * 6;
      ovr_blitLabel((char *)*(undefined2 *)((int)&GStructures[0].name + iVar2),
                    (uint8_t *)*(undefined2 *)((int)&GStructures[0].name + 2 + iVar2),Font02.ofs,
                    (uint8_t)Font02.seg);
      lVar1 = (long)(iVar6 + iVar5) * 6;
      uVar4 = (undefined2)((ulong)lVar1 >> 0x10);
      uStack_16 = manage_usesGUnitCount
                            (in_stack_00000004,(&((unk01_t *)GStructures)->type)[(int)lVar1],
                             (int *)&uStack_8,unaff_SS,(int *)&uStack_a,unaff_SS,(int *)&uStack_c,
                             unaff_SS,&iStack_e);
      if (iStack_e == 0) {
        iVar2 = 100;
        pcVar3 = litoa10(acStack_68,(ulong)uStack_16);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar3)),iVar2);
      }
      else {
        iVar2 = 100;
        pcVar3 = ovr_stsprintf(acStack_b8,(char *)unaff_SS,(char *)"%d (%d)");
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar3)),iVar2);
      }
      lVar1 = (long)(iVar6 + iVar5) * 6;
      uVar4 = (undefined2)((ulong)lVar1 >> 0x10);
      if (*(char *)((int)&GStructures[0].pad + (int)lVar1) != '\0') {
        if (iStack_10 == 0) {
          iVar2 = 0x8c;
          pcVar3 = litoa10(acStack_68,(ulong)uStack_8);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar3)),iVar2);
        }
        else {
          iVar2 = 0x8c;
          pcVar3 = ovr_stsprintf(acStack_b8,(char *)unaff_SS,(char *)"%d (%d)");
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar3)),iVar2);
        }
        if (iStack_12 == 0) {
          iVar2 = 0xb4;
          pcVar3 = litoa10(acStack_68,(ulong)uStack_a);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar3)),iVar2);
        }
        else {
          iVar2 = 0xb4;
          pcVar3 = ovr_stsprintf(acStack_b8,(char *)unaff_SS,(char *)"%d (%d)");
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar3)),iVar2);
        }
        if (iStack_14 == 0) {
          iVar2 = 0xdc;
          pcVar3 = litoa10(acStack_68,(ulong)uStack_c);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar3)),iVar2);
        }
        else {
          iVar2 = 0xdc;
          pcVar3 = ovr_stsprintf(acStack_b8,(char *)unaff_SS,(char *)"%d (%d)");
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar3)),iVar2);
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
  }
  CurSfxType3 = 0x3c;
  entries.seg = (uint16_t)unaff_SS;
  entries.ofs = (uint16_t)&menuItems;
  uVar4 = ovr_ovc28_usesUiInputText(entries,0x23,far_from_u32((uint32_t)(0x0)),&uStack_18,(uint16_t)unaff_SS);
  cStack_17 = (char)uVar4;
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
  int iVar3;
  char *pcVar4;
  uint8_t *widths;
  undefined2 uVar5;
  int unaff_BP;
  int iVar6;
  int iVar7;
  int *unaff_SS;
  uint16_t max_width;
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
    ovr_blitGfxRect(gfx,0,0,(brect_t *)(BlitRects + 1),0x10,true);
  }
  TextBlitY = 0xc;
  TextBlitX = 0x11;
  if (*(char *)(unaff_BP + 6) == -1) {
    ovr_blitLabel((char *)"All property.",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
  }
  else {
    puVar2 = (undefined2 *)((uint)*(byte *)(unaff_BP + 6) * 4);
    widths = (uint8_t *)*puVar2;
    *(undefined2 *)(unaff_BP + -2) = puVar2[1];
    *(undefined2 *)(unaff_BP + -4) = widths;
    term = (uint8_t)Font02.seg;
    max_width = Font02.ofs;
    ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,(char *)(unaff_BP + -0x66)),
                       (char *)CONCAT22(*(undefined2 *)(unaff_BP + -2),
                                        (char *)*(undefined2 *)(unaff_BP + -4)),
                       (char *)CONCAT22(Font02.seg,Font02.ofs),0x69,'\x03');
    manage_playerTitle((char_sheet_t *)*(undefined2 *)(unaff_BP + -4));
    pcVar4 = ovr_stsprintf((char *)(unaff_BP + -0xb6),(char *)unaff_SS,
                           (char *)"Buildings belonging to %s%s");
    ovr_blitLabel(pcVar4,widths,max_width,term);
  }
  TextBlitY = TextBlitY + 0xc;
  TextBlitX = 0x11;
  ovr_blitLabel((char *)"Buildings",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                (uint8_t)Font02.seg);
  manage_usesBlitLabel2("Total",100);
  manage_usesBlitLabel2("Level 1",0x8c);
  manage_usesBlitLabel2("Level 2",0xb4);
  manage_usesBlitLabel2("Level 3",0xdc);
  TextBlitY = TextBlitY + 0xc;
  if (*(char *)(unaff_BP + -0x15) == '\x04') {
    iVar7 = 0x1a;
  }
  else if (*(char *)(unaff_BP + -0x15) == '\x03') {
    iVar7 = 0xd;
  }
  else {
    iVar7 = 0;
  }
  for (iVar6 = 0; iVar6 < 0xd; iVar6 = iVar6 + 1) {
    if (iVar6 + iVar7 < 0x1e) {
      TextBlitX = 0x11;
      iVar3 = (iVar6 + iVar7) * 6;
      ovr_blitLabel((char *)*(undefined2 *)((int)&GStructures[0].name + iVar3),
                    (uint8_t *)*(undefined2 *)((int)&GStructures[0].name + 2 + iVar3),Font02.ofs,
                    (uint8_t)Font02.seg);
      lVar1 = (long)(iVar6 + iVar7) * 6;
      uVar5 = (undefined2)((ulong)lVar1 >> 0x10);
      iVar3 = manage_usesGUnitCount
                        (*(char *)(unaff_BP + 6),(&((unk01_t *)GStructures)->type)[(int)lVar1],
                         (int *)(unaff_BP + -6),unaff_SS,(int *)(unaff_BP + -8),unaff_SS,
                         (int *)(unaff_BP + -10),unaff_SS,(int *)(unaff_BP + -0xc));
      *(int *)((code *)init_textFilename + unaff_BP) = iVar3;
      if (*(int *)(unaff_BP + -0xc) == 0) {
        iVar3 = 100;
        pcVar4 = litoa10((char *)(unaff_BP + -0x66),
                         (ulong)*(uint *)((code *)init_textFilename + unaff_BP));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar5 >> 8),CONCAT12((char)uVar5,pcVar4)),iVar3);
      }
      else {
        iVar3 = 100;
        pcVar4 = ovr_stsprintf((char *)(unaff_BP + -0xb6),(char *)unaff_SS,(char *)"%d (%d)");
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar5 >> 8),CONCAT12((char)uVar5,pcVar4)),iVar3);
      }
      lVar1 = (long)(iVar6 + iVar7) * 6;
      uVar5 = (undefined2)((ulong)lVar1 >> 0x10);
      if (*(char *)((int)&GStructures[0].pad + (int)lVar1) != '\0') {
        if (*(int *)(unaff_BP + -0xe) == 0) {
          iVar3 = 0x8c;
          pcVar4 = litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)(unaff_BP + -6));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar5 >> 8),CONCAT12((char)uVar5,pcVar4)),iVar3);
        }
        else {
          iVar3 = 0x8c;
          pcVar4 = ovr_stsprintf((char *)(unaff_BP + -0xb6),(char *)unaff_SS,(char *)"%d (%d)");
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar5 >> 8),CONCAT12((char)uVar5,pcVar4)),iVar3);
        }
        if (*(int *)(unaff_BP + -0x10) == 0) {
          iVar3 = 0xb4;
          pcVar4 = litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)(unaff_BP + -8));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar5 >> 8),CONCAT12((char)uVar5,pcVar4)),iVar3);
        }
        else {
          iVar3 = 0xb4;
          pcVar4 = ovr_stsprintf((char *)(unaff_BP + -0xb6),(char *)unaff_SS,(char *)"%d (%d)");
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar5 >> 8),CONCAT12((char)uVar5,pcVar4)),iVar3);
        }
        if (*(int *)(unaff_BP + -0x12) == 0) {
          iVar3 = 0xdc;
          pcVar4 = litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)(unaff_BP + -10));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar5 >> 8),CONCAT12((char)uVar5,pcVar4)),iVar3);
        }
        else {
          iVar3 = 0xdc;
          pcVar4 = ovr_stsprintf((char *)(unaff_BP + -0xb6),(char *)unaff_SS,(char *)"%d (%d)");
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar5 >> 8),CONCAT12((char)uVar5,pcVar4)),iVar3);
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
  }
  CurSfxType3 = 0x3c;
  entries.seg = (uint16_t)unaff_SS;
  entries.ofs = unaff_BP - 0x142;
  uVar5 = ovr_ovc28_usesUiInputText
                    (entries,0x23,far_from_u32((uint32_t)(0x0)),(uint8_t *)(unaff_BP + -0x16),(uint16_t)unaff_SS);
  *(undefined1 *)(unaff_BP + -0x15) = (char)uVar5;
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
  uVar1 = ovr_ovc28_usesUiInputText(entries,0x23,far_from_u32((uint32_t)(0x0)),(uint8_t *)(unaff_BP + -0x16),unaff_SS);
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
  int iVar2;
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
      ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.");
    }
    else {
      ovr_ovc22_className(partyIndex);
      pcVar1 = ovr_stsprintf((char *)&msg,unaff_SS,
                             (char *)
                             "The damaged structures belonging to %s the %s are highlighted in red."
                            );
      ovr_say(pcVar1);
    }
  }
  else {
    iVar2 = 0;
    while ((iVar2 < 0x1e && ((uint)((unk01_t *)GStructures + iVar2)->type != structType))) {
      iVar2 = iVar2 + 1;
    }
    if (iVar2 != 0x1e) {
      if (partyIndex == 0xff) {
        pcVar1 = ovr_stsprintf((char *)&msg,unaff_SS,
                               (char *)"The %s belonging to all leaders are highlighted in red.");
        ovr_say(pcVar1);
      }
      else {
        ovr_ovc22_className(partyIndex);
        pcVar1 = ovr_stsprintf((char *)&msg,unaff_SS,
                               (char *)"The %s belonging to %s the %s are highlighted in red.");
        ovr_say(pcVar1);
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
  far_t entries;
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
  byte *pbVar12;
  uint16_t in_DX;
  uint8_t *widths;
  entity_t *peVar13;
  entity_t *peVar14;
  char *pcVar15;
  char *count;
  undefined2 uVar16;
  undefined2 unaff_ES;
  uint8_t *unaff_SS;
  bool bVar17;
  undefined2 in_stack_0000000a;
  uint8_t term;
  undefined1 uVar18;
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
  char *pcStack_12;
  undefined2 uStack_10;
  uint8_t auStack_e [3];
  byte bStack_b;
  byte abStack_a [2];
  uint16_t uStack_8;
  undefined1 auStack_6 [2];
  undefined2 uStack_4;
  
  dst.seg = (uint16_t)unaff_SS;
  dst.ofs = (uint16_t)&bandLabels;
  F_SCOPY(far_from_u32((uint32_t)(0x24104b06)),dst);
  dst_00.seg = (uint16_t)unaff_SS;
  dst_00.ofs = (uint16_t)&bandLabels2;
  F_SCOPY(far_from_u32((uint32_t)(0x24104b36)),dst_00);
  pbVar12 = (byte *)__C0_ASM_CopyRight + 3;
  dst_01.seg = (uint16_t)unaff_SS;
  dst_01.ofs = (uint16_t)(auStack_e + 4);
  F_SCOPY(far_from_u32((uint32_t)(0x24104b66)),dst_01);
  auStack_e[2] = '\0';
  if (charIndex == 0xff) {
    bStack_b = 0xc;
  }
  else {
    in_DX = 0x217a;
    unaff_ES = (undefined2)((ulong)*(undefined4 *)((uint)charIndex << 2) >> 0x10);
    if (*(char *)((int)*(undefined4 *)((uint)charIndex << 2) + 0x2f) == -1) {
      bStack_b = 0xc;
    }
    else {
      bStack_b = auStack_e[*(byte *)((int)*(undefined4 *)((uint)charIndex << 2) + 0x2f) + 4];
      in_DX = 0x217a;
      unaff_ES = (undefined2)((ulong)*(undefined4 *)((uint)charIndex << 2) >> 0x10);
      if (3 < *(byte *)((int)*(undefined4 *)((uint)charIndex << 2) + 0x2f)) {
        auStack_e[2] = '\x01';
      }
    }
  }
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 2)) = 0x2410;
  (*(uint16_t *)((uint8_t *)&(auStack_66))) = 0x50fb;
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 6)) = 0x2410;
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 4)) = 0x54e5;
  peVar13 = (entity_t *)(auStack_66 + 8);
  uStack_5c = 0x2410;
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 8)) = 0x54ed;
  count = (char *)((int)(undefined4 *)&_DATA + 3);
  for (pcVar15 = (char *)0x0; (int)pcVar15 < (int)(uint)bStack_b; pcVar15 = pcVar15 + 1) {
    if (((int)pcVar15 < 5) || (auStack_e[2] == '\0')) {
      in_DX = *(uint16_t *)(&bandLabels + (int)pcVar15 * 4);
      peVar13 = (entity_t *)(auStack_66 + (int)count * 4);
      *(undefined2 *)(auStack_66 + (int)count * 4 + 2) = auStack_94[(int)pcVar15 * 2];
      (peVar13->base).x = in_DX;
    }
    else {
      unaff_ES = (undefined2)((ulong)*(undefined4 *)((uint)charIndex << 2) >> 0x10);
      uVar6 = (uint)*(byte *)((int)*(undefined4 *)((uint)charIndex << 2) + 0x2f);
      in_DX = auStack_11a[(int)pcVar15 * 2 + uVar6 * 8];
      peVar13 = (entity_t *)(auStack_66 + (int)count * 4);
      *(uint16_t *)(auStack_66 + (int)count * 4 + 2) = auStack_11a[(int)pcVar15 * 2 + uVar6 * 8 + 1]
      ;
      (peVar13->base).x = in_DX;
    }
    pbVar12 = auStack_66;
    count = count + 1;
  }
  auStack_e[1] = '\x02';
  manage_openTalkWindow();
  auStack_e[0] = 0x0;
  if (auStack_e[1] == '\x02') {
    if (ScreenMode == '\0') {
      manage_openTalkWindow();
    }
    TextBlitY = 0xc;
    TextBlitX = 0x11;
    term = (uint8_t)Font02.seg;
    if (charIndex == 0xff) {
      uVar6 = ovr_blitLabel((char *)"Total population.",(uint8_t *)((char *)"puppetmaker" + 3),
                            Font02.ofs,term);
      *pcVar15 = *pcVar15 + (char)(uVar6 >> 8) + ((undefined1 *)0xfff3 < &stack0xfe3a);
      *(undefined1 *)((int)&(((entity_t *)*(entity_t **)&Entities)->base).entity + uVar6 + 1) = 0;
      uVar16 = (undefined2)((ulong)Entities >> 0x10);
      *(undefined1 *)((int)&((entity_t *)Entities)[(int)pcVar15].base.state + 1) =
           (char)((entity_t *)Entities)[(int)pcVar15].base.flags32;
      if (EntityCount <= pcVar15 + 1) {
        if ((auStack_e[0] != 0x0) || (auStack_e[1] != '\0')) {
          if ((*(uint8_t *)((uint8_t *)&(uStack_4) + 1)) == '\0') {
            ovr_stop_audio();
            CurSfxType3 = 0xff;
            ovr_play_sfx(90,0);
          }
          else if (auStack_e[1] == '\0') {
            if (auStack_e[0] != 0x0) {
              ovr_play_sfx(37,0);
            }
          }
          else {
            ovr_play_sfx(35,0);
          }
        }
        GGameState = 0x3d;
        pcVar15 = (char *)"puppetmaker" + 3;
        if (DebugVerbose != false) {
          pcVar15 = (char *)"puppetmaker" + 3;
          printf("%d \r");
        }
        ovr_OVC23_55fe_29a2_entry();
        return pcVar15;
      }
      pcVar15 = (char *)"thief" + 5;
      ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.");
      return pcVar15;
    }
    uStack_10 = ((undefined2 *)((uint)charIndex * 4))[1];
    pcStack_12 = (char *)*(undefined2 *)((uint)charIndex * 4);
    uVar5 = Font02.ofs;
    ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,acStack_1b6),(char *)CONCAT22(uStack_10,pcStack_12)
                       ,(char *)CONCAT22(Font02.seg,Font02.ofs),0x4b,'\x03');
    func_0x0005d3f4();
    widths = (uint8_t *)((char *)"puppetmaker" + 3);
    pcVar15 = ovr_stsprintf(acStack_13e,(char *)unaff_SS,(char *)"%s population, loyal to %s%s");
    ovr_blitLabel(pcVar15,widths,uVar5,term);
    TextBlitY = TextBlitY + 0xc;
    iVar9 = ovr_font_textWidth("UNITS",(char *)CONCAT22(Font02.seg,Font02.ofs));
    TextBlitX = 0x89 - iVar9;
    ovr_blitLabel((char *)"UNITS",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    iVar9 = ovr_font_textWidth("POPULATION",(char *)CONCAT22(Font02.seg,Font02.ofs));
    uVar5 = 0xd4 - iVar9;
    TextBlitX = uVar5;
    ovr_blitLabel((char *)"POPULATION",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    iVar9 = 0;
    while( true ) {
      TextBlitY = TextBlitY + 0xc;
      cVar4 = (char)pbVar12;
      if ((int)(uint)bStack_b <= iVar9) break;
      TextBlitX = 0x11;
      if ((iVar9 < 5) || (auStack_e[2] == '\0')) {
        ovr_blitLabel(*(char **)(&bandLabels + iVar9 * 4),(uint8_t *)auStack_94[iVar9 * 2],
                      Font02.ofs,(uint8_t)Font02.seg);
      }
      else {
        uVar6 = (uint)*(byte *)((int)*(undefined4 *)((uint)charIndex << 2) + 0x2f);
        ovr_blitLabel((char *)auStack_11a[iVar9 * 2 + uVar6 * 8],
                      (uint8_t *)auStack_11a[iVar9 * 2 + uVar6 * 8 + 1],Font02.ofs,
                      (uint8_t)Font02.seg);
      }
      func_0x0005f303();
      ovr_stsprintf(acStack_13e,(char *)unaff_SS,(char *)"%d");
      uVar18 = (undefined1)((uint)unaff_SS >> 8);
      iVar10 = ovr_font_textWidth((char *)CONCAT13(uVar18,CONCAT12((char)unaff_SS,acStack_13e)),
                                  (char *)CONCAT22(Font02.seg,Font02.ofs));
      TextBlitX = 0x89 - iVar10;
      ovr_blitLabel(acStack_13e,unaff_SS,Font02.ofs,(uint8_t)Font02.seg);
      ovr_stsprintf(acStack_13e,(char *)unaff_SS,(char *)"%d");
      iVar10 = ovr_font_textWidth((char *)CONCAT13(uVar18,CONCAT12((char)unaff_SS,acStack_13e)),
                                  (char *)CONCAT22(Font02.seg,Font02.ofs));
      uVar5 = 0xd4 - iVar10;
      TextBlitX = uVar5;
      ovr_blitLabel(acStack_13e,unaff_SS,Font02.ofs,(uint8_t)Font02.seg);
      iVar9 = iVar9 + 1;
    }
    CurSfxType3 = 0x3c;
    entries.seg = (uint16_t)unaff_SS;
    entries.ofs = (uint16_t)auStack_66;
    uVar16 = ovr_ovc28_usesUiInputText
                       (entries,(uint16_t)count,far_from_u32((uint32_t)(0x0)),auStack_e,(uint16_t)unaff_SS);
    auStack_e[1] = (uint8_t)uVar16;
    keyboardInputMode = 0;
    if (((auStack_e[1] != '\0') && (auStack_e[1] != '\x01')) && (auStack_e[1] != -2)) {
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
            uVar5 = ovr_audio_panFromX((agnt_t *)CONCAT22(in_stack_0000000a,sheet));
            ovr_play_sfxU(0x1c,0,uVar5);
            return (char *)CONCAT11((char)(uVar5 >> 8),1);
          }
        } while (*(int *)(iVar10 * 0x34 + 0x1b) != *(int *)(sheet->nameText + 0x1b));
        uVar16 = (undefined2)((ulong)_auStack_6 >> 0x10);
        if (*(byte *)((int)_auStack_6 + 0x32) < *(byte *)(iVar10 * 0x34 + 0x22)) {
          *(undefined1 *)(iVar10 * 0x34 + 0x22) = *(undefined1 *)((int)_auStack_6 + 0x32);
        }
        uVar5 = 0x34;
        iVar9 = iVar10;
      } while( true );
    }
    if (auStack_e[1] == -2) {
      Cancelled = 1;
    }
    return (char *)"puppetmaker" + 3;
  }
  do {
    uVar16 = (undefined2)((ulong)peStack_1e >> 0x10);
    peVar14 = (entity_t *)peStack_1e;
    (peVar14->base).target =
         (byte)((int)(uint)*(byte *)((int)&(peVar14->base).owner +
                                    ((int)(uint)(peVar13->base).faction >> 2)) >>
               (((peVar14->base).faction & 3) << 1)) & 3;
    cVar4 = func_0x0004f32d();
    peVar13 = (entity_t *)peStack_1e;
    uVar16 = (undefined2)((ulong)peStack_1e >> 0x10);
    if (cVar4 == '\0') {
      (peStack_1e->base).x = (peStack_1e->base).x + (int)*(char *)((peVar13->base).target + 0x885);
      puVar1 = &(peVar13->base).y;
      *puVar1 = *puVar1 + (int)*(char *)((peVar13->base).target + 0x889);
      puVar2 = &(peVar13->base).faction;
      *puVar2 = *puVar2 + 0x1;
    }
    else {
      (peVar13->base).faction = 0x0;
      *(undefined1 *)&(peVar13->base).state = 0;
    }
L_attact_3f0b_1082_1477:
    uStack_17 = 0x1;
    uVar6 = ovr_alignUp4((((entity_t *)peStack_1e)->base).destX);
    uVar7 = ovr_alignUp4((peStack_1e->base).x);
    if (uVar6 == uVar7) {
      uVar16 = (undefined2)((ulong)peStack_1e >> 0x10);
      peVar13 = (entity_t *)peStack_1e;
      if ((peVar13->base).destY == (peVar13->base).y) {
        (peVar13->base).destX = 0;
        (peVar13->base).destY = 0;
        if (*(char *)((int)&(peVar13->base).entity + 3) == -1) {
          _auStack_6 = CONCAT12(0xff,auStack_6);
        }
        else {
          uVar3 = *(undefined4 *)((uint)*(byte *)((int)&(peVar13->base).entity + 3) << 2);
          _auStack_6 = CONCAT12(*(undefined1 *)((int)uVar3 + 0x89),auStack_6);
        }
        uVar3 = _auStack_6;
        (*(uint8_t *)((uint8_t *)&(uStack_4))) = (byte)((uint3)_auStack_6 >> 0x10);
        bVar17 = (byte)uStack_4 != -1;
        _auStack_6 = uVar3;
        if (bVar17) {
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
                  auStack_e[(byte)uStack_4] = 0x1;
                }
              }
              break;
            }
          }
        }
      }
    }
    if (AgntFlag1 != false) {
      uVar16 = (undefined2)((ulong)peStack_1e >> 0x10);
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
          uVar16 = (undefined2)((ulong)peStack_1e >> 0x10);
          peVar13 = (entity_t *)peStack_1e;
          cStack_1a = (char)((ulong)((peVar13->base).animFrame + 0xf) / 0x10);
          if (((peVar13->base).target & 1) == 0) {
            iStack_16 = 0;
          }
          else {
            iStack_16 = (peVar13->base).target - 2;
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
            ovr_agnt_usesAgntCount6
                      ((entity_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),(entity_t *)Entities + (int)count));
          }
          cStack_1a = -1;
        }
        else if ((cStack_18 != '\0') && (cStack_19 != '\0')) {
          for (cStack_1a = func_0x0004f944(); cStack_1a != '\0'; cStack_1a = cStack_1a + -1) {
            uVar16 = (undefined2)((ulong)peStack_1e >> 0x10);
            if (((((entity_t *)peStack_1e)->base).target & 1) == 0) {
              iStack_16 = 0;
            }
            else {
              iStack_16 = (((entity_t *)peStack_1e)->base).target - 2;
            }
            pcVar15 = ovr_ovc15_textArena((int)count);
            if (((uint)pcVar15 & 0xff) == 0) break;
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
          if (auStack_e[uVar6] != 0x0) {
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
      uVar16 = (undefined2)((ulong)Entities >> 0x10);
      peStack_1e = (entity_t *)CONCAT22(uVar16,(entity_t *)Entities + (int)count);
      uVar6 = ovr_alignUp4(((entity_t *)Entities)[(int)count].base.destX);
      uVar7 = ovr_alignUp4((peStack_1e->base).x);
      if ((uVar6 == uVar7) &&
         (uVar16 = (undefined2)((ulong)peStack_1e >> 0x10),
         (((entity_t *)peStack_1e)->base).destY == (((entity_t *)peStack_1e)->base).y)) {
        func_0x0004fb8e();
      }
      unaff_ES = (undefined2)((ulong)peStack_1e >> 0x10);
      peVar13 = (entity_t *)peStack_1e;
    } while (((peVar13->base).destX == 0 && (peVar13->base).destY == 0) ||
            (*(char *)((int)&(peVar13->base).entity + 1) != '\0'));
    if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)(peVar13->base).gindex * 0x95) & 0x4000)
        == 0) {
      uStack_4 = (uint)((ulong)_auStack_6 >> 0x10) & 0xff;
    }
    else {
      _auStack_6 = CONCAT13(1,_auStack_6);
    }
    _auStack_6 = CONCAT22(uStack_4,(peStack_1e->base).x);
    uStack_8 = (peVar13->base).y;
    _pcStack_12 = CONCAT13(*(undefined1 *)
                            ((int)(char **)GMenuStrings + (uint)(peVar13->base).gindex * 0x95 + 0x1f
                            ),_pcStack_12);
  } while ((peVar13->base).faction < (byte)(peVar13->base).state);
  uVar16 = ovr_ovc07_signum((peVar13->base).destX - (peStack_1e->base).x);
  _pcStack_12 = CONCAT22(uStack_10,uVar16);
  uVar16 = (undefined2)((ulong)peStack_1e >> 0x10);
  iStack_14 = ovr_ovc07_signum((((entity_t *)peStack_1e)->base).destY -
                               (((entity_t *)peStack_1e)->base).y);
  if (((pcStack_12 == (char *)0x0) || (uVar5 = ovr_randBelow(2), (char)uVar5 == '\0')) ||
     (cVar4 = func_0x0004f412(), cVar4 != '\0')) {
    if ((iStack_14 == 0) || (cVar4 = func_0x0004f412(), cVar4 != '\0')) {
      if ((pcStack_12 == (char *)0x0) || (cVar4 = func_0x0004f412(), cVar4 != '\0')) {
        uVar6 = ovr_ovc26_usesStExit((int)count);
        if ((char)uVar6 == '\0') {
          uVar6 = ovr_ovc26_usesRandBelow
                            ((int)count,(uint16_t)&uStack_17,(uint16_t)unaff_SS,(uint16_t)auStack_e,
                             (uint16_t)unaff_SS);
          if (((uVar6 & 0xff) == 0) &&
             (*(char *)((int)(char **)GMenuStrings +
                       (uint)(((entity_t *)peStack_1e)->base).gindex * 0x95 + 0x1f) == '\0')) {
            func_0x0004fb8e();
          }
        }
        else {
          uVar16 = (undefined2)((ulong)peStack_1e >> 0x10);
          peVar13 = (entity_t *)peStack_1e;
          (peVar13->base).target =
               (byte)((int)(uint)*(byte *)((int)&(peVar13->base).owner +
                                          ((int)(uint)(peVar13->base).faction >> 2)) >>
                     (((peVar13->base).faction & 3) << 1)) & 3;
          cVar4 = func_0x0004f32d();
          if (cVar4 == '\0') {
            uVar16 = (undefined2)((ulong)peStack_1e >> 0x10);
            peVar13 = (entity_t *)peStack_1e;
            (peStack_1e->base).x =
                 (peStack_1e->base).x + (int)*(char *)((peVar13->base).target + 0x885);
            puVar1 = &(peVar13->base).y;
            *puVar1 = *puVar1 + (int)*(char *)((peVar13->base).target + 0x889);
            puVar2 = &(peVar13->base).faction;
            *puVar2 = *puVar2 + 0x1;
          }
        }
      }
      else {
        (peStack_1e->base).x = (peStack_1e->base).x + (int)pcStack_12;
        (((entity_t *)peStack_1e)->base).target = 0x2 - (char)pcStack_12;
      }
    }
    else {
      uVar16 = (undefined2)((ulong)peStack_1e >> 0x10);
      puVar1 = &(((entity_t *)peStack_1e)->base).y;
      *puVar1 = *puVar1 + iStack_14;
      (((entity_t *)peStack_1e)->base).target = (char)iStack_14 + 0x1;
    }
  }
  else {
    (peStack_1e->base).x = (peStack_1e->base).x + (int)pcStack_12;
    (((entity_t *)peStack_1e)->base).target = 0x2 - (char)pcStack_12;
  }
  goto L_attact_3f0b_1082_1477;
}



/* 4d05:330c */

/* Applies a party/type display filter to the unit list and reports which filter is active. */

void __cdecl16far manage_applyUnitFilter(uint8_t partyIndex,uint16_t unitType,char *unitName)

{
  char *pcVar1;
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
      ovr_say((char *)"All units are displayed.");
    }
    else {
      ovr_ovc22_className(partyIndex);
      pcVar1 = ovr_stsprintf((char *)&msg,unaff_SS,
                             (char *)"All units loyal to %s the %s are displayed.");
      ovr_say(pcVar1);
    }
  }
  else if (partyIndex == 0xff) {
    pcVar1 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"Only units of %s are displayed.");
    ovr_say(pcVar1);
  }
  else {
    ovr_ovc22_className(partyIndex);
    pcVar1 = ovr_stsprintf((char *)&msg,unaff_SS,
                           (char *)"Only units of %s loyal to %s the %s are displayed.");
    ovr_say(pcVar1);
  }
  return;
}


