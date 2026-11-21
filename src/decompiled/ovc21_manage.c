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

/* WARNING: Variable defined which should be unmapped: palette */
/* Opens the talk window: sets ScreenMode, installs the talkwin9 palette, fills the panel and blits
   the three window cuts. */

void __cdecl16far manage_openTalkWindow(void)

{
  long lVar1;
  uint8_t mirror;
  uint8_t *puVar2;
  stg_tmp_t *psVar3;
  uint8_t *in_DX;
  uint16_t unaff_SS;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  uint8_t palette;
  long lStack_308;
  uint16_t in_stack_0000fcfc;
  
  mapViewActive = 0xff;
  ScreenMode = 1;
  psVar3 = ovr_stshLoadGfx();
  ovr_calcSeasonPalette
            ((uint8_t *)CONCAT22(&palette,in_DX),unaff_SS,_palette,in_stack_0000fcfc,psVar3);
  ovr_driver_fillRect();
  ovr_vgaSetPalette8bit();
  gfx.seg = 0;
  gfx.ofs = talkwin9Cut1Seg;
  ovr_blitGfxRect(gfx,0,1098,(brect_t *)0x102410,0x0,(bool)palette,talkwin9Cut1Ofs);
  gfx_00.seg = 0;
  gfx_00.ofs = talkwin9Cut2Seg;
  ovr_blitGfxRect(gfx_00,0,1098,(brect_t *)0x102410,0x0,(bool)palette,talkwin9Cut2Ofs);
  puVar2 = _palette;
  lStack_308 = ZEXT24(_palette) << 0x10;
  lVar1 = lStack_308;
  gfx_01.seg = 0;
  gfx_01.ofs = talkwin9Cut3Seg;
  palette = (uint8_t)puVar2;
  mirror = palette;
  lStack_308 = lVar1;
  ovr_blitGfxRect(gfx_01,0,1098,(brect_t *)0x102410,0x0,(bool)mirror,talkwin9Cut3Ofs);
  return;
}



/* 4d05:0166 */

/* WARNING: Variable defined which should be unmapped: rect */
/* Blits the talkwin9Cut1 window graphic at the origin, clipped by panelClipRect. */

void __cdecl16far manage_blitTalkWindow(void)

{
  far_t dst;
  brect_t *unaff_SS;
  far_t gfx;
  uint8_t rect;
  
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
  dst.ofs = (uint16_t)&rect;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)((uint)unaff_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x2410493b)),dst);
  gfx.seg = 0;
  gfx.ofs = talkwin9Cut1Seg;
  ovr_blitGfxRect(gfx,0,(int16_t)&rect,(brect_t *)CONCAT22(0x10,unaff_SS),0x0,(bool)rect,
                  talkwin9Cut1Ofs,0);
  return;
}



/* 4d05:01a3 */

/* Rolls count dice of the given number of sides and returns the sum. */

char __cdecl16far manage_rollDice(char count,char sides,...)

{
  uint16_t uVar1;
  char in_stack_00000004;
  byte in_stack_0000fffc;
  uint16_t n;
  
  n = (uint16_t)in_stack_0000fffc;
  while (in_stack_00000004 != '\0') {
    in_stack_00000004 = in_stack_00000004 + -1;
    uVar1 = ovr_randBelow(n,(uint)(byte)count);
    n = CONCAT11((char)uVar1 + (char)(n >> 8) + '\x01',(char)n);
  }
  return (char)(n >> 8);
}



/* 4d05:01d4 */

/* Rolls the six stats (3d6 + randBelow(4), capped at 18) and marks statMask bit 5. */

void __cdecl16far manage_rollStats(char_sheet_t *sheet,...)

{
  char cVar1;
  undefined1 extraout_AH;
  uint16_t uVar2;
  int in_stack_00000004;
  char in_stack_0000fffc;
  undefined1 uStack_3;
  uint16_t n;
  
  for (uStack_3 = 0; uStack_3 < 6; uStack_3 = uStack_3 + 1) {
    cVar1 = manage_rollDice('\x06',in_stack_0000fffc,3);
    n = CONCAT11(extraout_AH,cVar1);
    uVar2 = ovr_randBelow(n,4);
    *(char *)(in_stack_00000004 + (uint)uStack_3 + 0x29) = (char)n + (char)uVar2;
    if (0x11 < *(byte *)(in_stack_00000004 + (uint)uStack_3 + 0x29)) {
      *(undefined1 *)(in_stack_00000004 + (uint)uStack_3 + 0x29) = 0x12;
    }
  }
  *(byte *)(in_stack_00000004 + 0x28) = *(byte *)(in_stack_00000004 + 0x28) | 0x20;
  return;
}



/* 4d05:023a */

/* [R7] body shape: compute */

char * __cdecl16far manage_compute1(int n,...)

{
  int iVar1;
  int in_stack_00000004;
  char *pcStack_6;
  
  iVar1 = in_stack_00000004 % 10;
  if ((iVar1 == 1) && (in_stack_00000004 != 0xb)) {
    pcStack_6 = (char *)"st";
  }
  else if ((iVar1 == 2) && (in_stack_00000004 != 0xc)) {
    pcStack_6 = (char *)"nd";
  }
  else if ((iVar1 == 3) && (in_stack_00000004 != 0xd)) {
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
  int in_stack_00000004;
  far_t dst;
  uint8_t titlesMap;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&titlesMap;
  F_SCOPY(far_from_u32((uint32_t)(0x241049a5)),dst);
  if (*(char *)(in_stack_00000004 + 0x2f) == -1) {
    pcVar1 = (char *)"Lawful" + 6;
  }
  else if (*(char *)(in_stack_00000004 + 0x86) == '\0') {
    if ((*(byte *)(in_stack_00000004 + 0x30) < 9) &&
       ((*(char *)(in_stack_00000004 + 0x2f) != '\x06' || (*(byte *)(in_stack_00000004 + 0x30) < 8))
       )) {
      pcVar1 = (char *)"Lawful" + 6;
    }
    else {
      pcVar1 = *(char **)(&titlesMap +
                         (uint)*(byte *)(in_stack_00000004 + 0x2f) * 8 +
                         (uint)*(byte *)(in_stack_00000004 + 0x34) * 4);
    }
  }
  else {
    pcVar1 = (char *)((far_t *)(GStatsLabels + 4) +
                     (uint)*(byte *)(in_stack_00000004 + 0x34) +
                     (uint)*(byte *)(in_stack_00000004 + 0x86) * 2)->ofs;
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
  uint8_t unaff_BP;
  
  iVar1 = ovr_font_textWidth();
  TextBlitX = x - iVar1;
  ovr_blitLabel((char *)CONCAT22(Font02.ofs,(*(uint16_t *)((uint8_t *)&(text) + 2))),(uint8_t *)CONCAT22(0xde,Font02.seg),80,
                unaff_BP,(char *)text);
  return;
}



/* 4d05:0519 */

/* [R4] calls ovr_blitLabel */

void __cdecl16far manage_usesBlitLabel2(char *text,int x)

{
  int iVar1;
  uint8_t unaff_BP;
  undefined1 in_stack_0000000a;
  
  iVar1 = ovr_font_textWidth();
  TextBlitX = x - iVar1;
  ovr_blitLabel((char *)CONCAT22(Font02.ofs,(*(uint16_t *)((uint8_t *)&(text) + 2))),(uint8_t *)CONCAT22(0xde,Font02.seg),
                CONCAT11(0x24,in_stack_0000000a),unaff_BP,(char *)text);
  return;
}



/* 4d05:056e */

/* [R4] calls litoa10 */

void __cdecl16far manage_usesLitoa10(char_sheet_t *sheet)

{
  void *pvVar1;
  char *pcVar2;
  uint uVar3;
  undefined2 uVar4;
  char *in_DX;
  char_sheet_t *pcVar5;
  int iVar6;
  undefined2 unaff_DI;
  uint16_t uVar7;
  char_sheet_t *pcVar8;
  char *unaff_SS;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  byte partyIndex;
  char textBuf [120];
  uint8_t msg;
  byte bStack_6;
  byte bStack_5;
  int iStack_4;
  
  partyIndex = (byte)unaff_DI;
  uVar10 = (undefined1)((uint)unaff_DI >> 8);
  pcVar8 = (char_sheet_t *)((ulong)sheet >> 0x10);
  pcVar5 = (char_sheet_t *)sheet;
  bStack_6 = pcVar5->statMask;
  if ((bStack_6 & 0x20) != 0) {
    uVar7 = 0x1b;
    for (iVar6 = 0; iVar6 < 6; iVar6 = iVar6 + 1) {
      TextBlitX = 0x15;
      TextBlitY = uVar7;
      ovr_blitLabel();
      ovr_stsprintf((char *)CONCAT22(0x4cd1,unaff_SS),
                    (char *)(ulong)CONCAT12(pcVar5->stats[iVar6],0x2410),(char *)&msg);
      manage_blitLabelRight((char *)CONCAT22(unaff_SS,&msg),0x31);
      uVar7 = uVar7 + 10;
    }
  }
  TextBlitY = 0xc;
  if ((bStack_6 & 2) != 0) {
    TextBlitX = 0x15;
    uVar9 = (undefined1)Font02.seg;
    uVar11 = (undefined1)(Font02.seg >> 8);
    uVar7 = Font02.ofs;
    pvVar1 = manage_playerTitle((char_sheet_t *)CONCAT22(Font02.ofs,pcVar8),(char)sheet);
    iStack_4 = ovr_font_textWidth((char *)CONCAT22(uVar7,in_DX),
                                  (char *)CONCAT13(uVar10,CONCAT12(partyIndex,CONCAT11(uVar11,uVar9)
                                                                  )),(char)pvVar1,uVar9);
    ovr_ovc45_compute9((char *)CONCAT22(pcVar5,unaff_SS),(char *)CONCAT22(Font02.ofs,pcVar8),
                       (char *)CONCAT22(0x7d - iStack_4,Font02.seg),3,(char)Font02.ofs,&msg);
    pvVar1 = manage_playerTitle();
    ovr_stsprintf((char *)CONCAT22(0x4cd4,unaff_SS),
                  (char *)CONCAT22(pvVar1,(char *)"puppetmaker" + 3),in_DX,textBuf);
    ovr_blitLabel();
  }
  if ((bStack_6 & 4) != 0) {
    ovr_fmVsprintf((char *)CONCAT22(((far_t *)GAlignmentsNames + pcVar5->alignment)->ofs,
                                    (char *)"puppetmaker" + 3),
                   (char *)CONCAT13((char)(Font02.ofs >> 8),
                                    CONCAT12((char)Font02.ofs,
                                             *(undefined2 *)
                                              ((int)&GAlignmentsNames[0].seg +
                                              (uint)pcVar5->alignment * 4))));
    ovr_blitLabel();
  }
  if ((bStack_6 & 1) != 0) {
    iVar6 = (uint)pcVar5->cls * 4;
    in_DX = (char *)"puppetmaker" + 3;
    ovr_fmVsprintf((char *)CONCAT22(*(undefined2 *)(iVar6 + 0xeb),(char *)"puppetmaker" + 3),
                   (char *)CONCAT13((char)(Font02.ofs >> 8),
                                    CONCAT12((char)Font02.ofs,*(undefined2 *)(iVar6 + 0xed))));
    ovr_blitLabel();
  }
  TextBlitY = TextBlitY + 10;
  if (((bStack_6 & 0x40) != 0) || (DebugVerbose != false)) {
    TextBlitX = 0x37;
    ovr_blitLabel();
    uVar10 = 0x7d;
    uVar9 = 0;
    pcVar2 = ovr_stsprintf();
    manage_blitLabelRight((char *)CONCAT22(in_DX,pcVar2),CONCAT11(uVar9,uVar10));
    TextBlitX = 0x82;
    ovr_ovc22_textRingProt(partyIndex,pcVar5->charIndex);
    ovr_blitLabel();
    uVar10 = 0xdc;
    uVar9 = 0;
    pcVar2 = litoa10((char *)CONCAT22(pcVar5->foodProd,unaff_SS),0xdc0000,textBuf);
    manage_blitLabelRight((char *)CONCAT22(in_DX,pcVar2),CONCAT11(uVar9,uVar10));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x82;
    ovr_blitLabel();
    uVar10 = 0xdc;
    uVar9 = 0;
    pcVar2 = litoa10((char *)CONCAT22((int)pcVar5->foodStored,unaff_SS),
                     (ulong)CONCAT12(0xdc,*(undefined2 *)((int)&pcVar5->foodStored + 2)),textBuf);
    manage_blitLabelRight((char *)CONCAT22(in_DX,pcVar2),CONCAT11(uVar9,uVar10));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel();
    uVar10 = 0x7d;
    uVar9 = 0;
    pcVar2 = ovr_stsprintf();
    manage_blitLabelRight((char *)CONCAT22(in_DX,pcVar2),CONCAT11(uVar9,uVar10));
    TextBlitX = 0x82;
    ovr_blitLabel();
    uVar10 = 0xdc;
    uVar9 = 0;
    pcVar2 = litoa10((char *)CONCAT22((int)pcVar5->foodStorage,unaff_SS),
                     (ulong)CONCAT12(0xdc,*(undefined2 *)((int)&pcVar5->foodStorage + 2)),textBuf);
    manage_blitLabelRight((char *)CONCAT22(in_DX,pcVar2),CONCAT11(uVar9,uVar10));
    TextBlitY = TextBlitY + 0xf;
    if (pcVar5->maxTrade != 0) {
      TextBlitX = 0x37;
      if (pcVar5->foodSold < 0) {
        ovr_blitLabel();
        uVar10 = 0x7d;
        uVar9 = 0;
        iVar6 = -pcVar5->foodSold >> 0xf;
        pcVar2 = litoa10((char *)CONCAT22(-pcVar5->foodSold,unaff_SS),(ulong)CONCAT12(0x7d,iVar6),
                         textBuf);
        manage_blitLabelRight((char *)CONCAT22(iVar6,pcVar2),CONCAT11(uVar9,uVar10));
      }
      else {
        ovr_blitLabel();
        uVar10 = 0x7d;
        uVar9 = 0;
        iVar6 = pcVar5->foodSold >> 0xf;
        pcVar2 = litoa10((char *)CONCAT22(pcVar5->foodSold,unaff_SS),(ulong)CONCAT12(0x7d,iVar6),
                         textBuf);
        manage_blitLabelRight((char *)CONCAT22(iVar6,pcVar2),CONCAT11(uVar9,uVar10));
      }
      TextBlitX = 0x82;
      ovr_blitLabel();
      uVar10 = 0xdc;
      uVar9 = 0;
      pcVar2 = litoa10((char *)CONCAT22(pcVar5->maxTrade,unaff_SS),0xdc0000,textBuf);
      manage_blitLabelRight((char *)CONCAT22(iVar6,pcVar2),CONCAT11(uVar9,uVar10));
    }
    TextBlitY = TextBlitY + 0xf;
    TextBlitX = 0x37;
    ovr_blitLabel();
    uVar10 = 0xdc;
    uVar9 = 0;
    iVar6 = pcVar5->income >> 0xf;
    pcVar2 = litoa10((char *)CONCAT22(pcVar5->income,unaff_SS),(ulong)CONCAT12(0xdc,iVar6),&msg);
    manage_blitLabelRight((char *)CONCAT22(iVar6,pcVar2),CONCAT11(uVar9,uVar10));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel();
    uVar10 = 0xdc;
    uVar9 = 0;
    pcVar2 = litoa10((char *)CONCAT22((int)pcVar5->gold,unaff_SS),
                     (ulong)CONCAT12(0xdc,*(undefined2 *)((int)&pcVar5->gold + 2)),&msg);
    manage_blitLabelRight((char *)CONCAT22(iVar6,pcVar2),CONCAT11(uVar9,uVar10));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel();
    uVar10 = 0xdc;
    uVar9 = 0;
    pcVar2 = litoa10((char *)CONCAT22((int)pcVar5->vaultStorage,unaff_SS),
                     (ulong)CONCAT12(0xdc,*(undefined2 *)((int)&pcVar5->vaultStorage + 2)),&msg);
    manage_blitLabelRight((char *)CONCAT22(iVar6,pcVar2),CONCAT11(uVar9,uVar10));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    uVar3 = ovr_blitLabel();
    uVar10 = 0xdc;
    uVar9 = 0;
    uVar4 = ovr_ovc45_usesLDIV_at_(0xdc,CONCAT11((char)(uVar3 >> 8),pcVar5->charIndex));
    pcVar2 = litoa10((char *)CONCAT22(uVar4,unaff_SS),CONCAT13(uVar9,CONCAT12(uVar10,iVar6)),textBuf
                    );
    manage_blitLabelRight((char *)CONCAT22(iVar6,pcVar2),CONCAT11(uVar9,uVar10));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel();
    uVar10 = 0xdc;
    uVar9 = 0;
    pcVar2 = litoa10((char *)CONCAT22(GPopulationLo,unaff_SS),(ulong)CONCAT12(0xdc,GPopulationHi),
                     textBuf);
    manage_blitLabelRight((char *)CONCAT22(iVar6,pcVar2),CONCAT11(uVar9,uVar10));
    bStack_5 = manage_findFirstLeader();
    TextBlitY = TextBlitY + 0xf;
    if (((pcVar5->titleIndex != 0) && (bStack_5 != 0xff)) &&
       (uVar4 = 0x217a, *(byte *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x86) < 9)) {
      manage_usesBlitLabel2("popularity",0x7d);
      manage_usesBlitLabel2("city blocks",0xdc);
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x11;
      ovr_blitLabel();
      uVar10 = 0x7d;
      uVar9 = 0;
      manage_usesGLeaderCount();
      pcVar2 = ovr_stsprintf();
      manage_blitLabelRight((char *)CONCAT22(uVar4,pcVar2),CONCAT11(uVar9,uVar10));
      uVar10 = 0xdc;
      uVar9 = 0;
      pcVar2 = ovr_stsprintf();
      manage_blitLabelRight((char *)CONCAT22(uVar4,pcVar2),CONCAT11(uVar9,uVar10));
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x11;
      ovr_blitLabel();
      uVar10 = 0x7d;
      uVar9 = 0;
      ovr_season_usesDifficulty();
      pcVar2 = ovr_stsprintf();
      manage_blitLabelRight((char *)CONCAT22(uVar4,pcVar2),CONCAT11(uVar9,uVar10));
      uVar10 = 0xdc;
      uVar9 = 0;
      ovr_season_usesGPromotableCount2();
      pcVar2 = ovr_stsprintf();
      manage_blitLabelRight((char *)CONCAT22(uVar4,pcVar2),CONCAT11(uVar9,uVar10));
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
  far_t entries;
  far_t entries_00;
  far_t dst;
  far_t dst_00;
  byte bVar2;
  undefined1 extraout_AH;
  uint8_t *puVar3;
  char *pcVar4;
  uint16_t unaff_SS;
  undefined1 uVar5;
  uint8_t menuItems;
  undefined1 uStack_29;
  uint16_t uVar6;
  byte bStack_19;
  uint8_t statIndex;
  byte bStack_17;
  uint8_t uStack_16;
  uint8_t classStatMap2;
  uint8_t classStatMap1;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&classStatMap1;
  F_SCOPY(far_from_u32((uint32_t)(0x241049dd)),dst);
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&classStatMap2;
  F_SCOPY(far_from_u32((uint32_t)(0x241049e4)),dst_00);
  while( true ) {
    uVar5 = (undefined1)(unaff_SS >> 8);
    _fsetmem((void *)CONCAT13(uVar5,CONCAT12((char)unaff_SS,&menuItems)),0x10,0);
    uVar6 = 0x2410;
    menuItems = 0x9b;
    uStack_29 = 0x4d;
    bStack_19 = 1;
    bVar2 = manage_statSelectable
                      ((&classStatMap1)[((char_sheet_t *)sheet)->cls],
                       (char_sheet_t *)CONCAT13(0x4d,CONCAT12(0x9b,(*(uint16_t *)((uint8_t *)&(sheet) + 2)))));
    if (bVar2 != 0) {
      uStack_16 = (&classStatMap1)[((char_sheet_t *)sheet)->cls];
      bStack_19 = 2;
    }
    puVar3 = &classStatMap2 + ((char_sheet_t *)sheet)->cls;
    if (*puVar3 != 0xff) {
      bVar2 = manage_statSelectable
                        ((&classStatMap2)[((char_sheet_t *)sheet)->cls],
                         (char_sheet_t *)CONCAT13(uStack_29,CONCAT12(menuItems,(*(uint16_t *)((uint8_t *)&(sheet) + 2)))));
      puVar3 = (uint8_t *)CONCAT11(extraout_AH,bVar2);
      if (bVar2 != 0) {
        (&bStack_17)[bStack_19] = (&classStatMap2)[((char_sheet_t *)sheet)->cls];
        puVar3 = (uint8_t *)
                 *(undefined2 *)
                  ((int)&GStatsLabels[0].seg +
                  (uint)(&classStatMap2)[((char_sheet_t *)sheet)->cls] * 4);
        uVar1 = ((far_t *)GStatsLabels + (&classStatMap2)[((char_sheet_t *)sheet)->cls])->ofs;
        *(uint8_t **)(&stack0xffd8 + (uint)bStack_19 * 4) = puVar3;
        *(uint16_t *)(&menuItems + (uint)bStack_19 * 4) = uVar1;
        bStack_19 = bStack_19 + 1;
      }
    }
    if (bStack_19 == 1) {
      return CONCAT11((char)((uint)puVar3 >> 8),1);
    }
    ovr_drawString((char *)CONCAT13(uStack_29,CONCAT12(menuItems,0x2410)),uVar6,0x4da2);
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = bStack_19;
    entries.ofs = unaff_SS;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = 0;
    pcVar4 = ovr_uiInputText(entries,0,far_from_u32((uint32_t)(0x0)),menuItems,&menuItems,0);
    if ((char)pcVar4 == '\0') {
      return 0;
    }
    if ((char)pcVar4 == '\x01') break;
    bStack_17 = (&statIndex)[(uint)pcVar4 & 0xff];
    ovr_drawString((char *)CONCAT13(uStack_29,CONCAT12(menuItems,0x2410)),uVar6,0x4e08);
    _fsetmem((void *)CONCAT13(uVar5,CONCAT12((char)unaff_SS,&menuItems)),0x10,0);
    menuItems = 0x3a;
    uStack_29 = 0x4e;
    bStack_19 = 1;
    for (statIndex = 0x0; statIndex < 3; statIndex = statIndex + 0x1) {
      if ((10 < ((char_sheet_t *)sheet)->stats[statIndex]) && (bStack_17 != statIndex)) {
        (&bStack_17)[bStack_19] = statIndex;
        uVar6 = ((far_t *)GStatsLabels + statIndex)->ofs;
        *(undefined2 *)(&stack0xffd8 + (uint)bStack_19 * 4) =
             *(undefined2 *)((int)&GStatsLabels[0].seg + (uint)statIndex * 4);
        *(uint16_t *)(&menuItems + (uint)bStack_19 * 4) = uVar6;
        bStack_19 = bStack_19 + 1;
      }
    }
    (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = bStack_19;
    entries_00.ofs = unaff_SS;
    (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = 0;
    pcVar4 = ovr_uiInputText(entries_00,0,far_from_u32((uint32_t)(0x0)),menuItems,&menuItems,0);
    if ((char)pcVar4 == '\0') {
      return 0;
    }
    if ((char)pcVar4 != '\x01') {
      ((char_sheet_t *)sheet)->stats[bStack_17] = ((char_sheet_t *)sheet)->stats[bStack_17] + 1;
      ((char_sheet_t *)sheet)->stats[(&statIndex)[(uint)pcVar4 & 0xff]] =
           ((char_sheet_t *)sheet)->stats[(&statIndex)[(uint)pcVar4 & 0xff]] - 2;
      manage_openTalkWindow();
      manage_usesLitoa10(sheet);
    }
  }
  return 1;
}



/* 4d05:1095 */

/* WARNING: Variable defined which should be unmapped: inputBuf */

undefined2 __cdecl16far alignmentDlg(char_sheet_t *sheet)

{
  byte *pbVar1;
  far_t entries;
  far_t dst;
  uint8_t done;
  char *pcVar2;
  undefined2 uVar3;
  uint16_t unaff_SS;
  uint8_t in_stack_0000fff4;
  uint8_t flags;
  undefined1 in_stack_0000fff5;
  uint8_t inputBuf;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&inputBuf;
  F_SCOPY(far_from_u32((uint32_t)(0x24104a03)),dst);
  do {
    ovr_drawString((char *)CONCAT13(in_stack_0000fff5,CONCAT12(in_stack_0000fff4,0x2410)),_inputBuf,
                   0x4f9c);
    pcVar2 = ovr_uiInputText(far_from_u32((uint32_t)(0x32410)),0,far_from_u32((uint32_t)(0x0)),in_stack_0000fff4,0x4927);
    flags = (uint8_t)pcVar2;
    if (((uint)pcVar2 & 0xff) == 0) {
      return 0;
    }
    uVar3 = (undefined2)((ulong)sheet >> 0x10);
    ((char_sheet_t *)sheet)->alignment = flags - 1;
    pbVar1 = &((char_sheet_t *)sheet)->statMask;
    *pbVar1 = *pbVar1 | 4;
    if (CurPartySlot != '\0') {
      return 1;
    }
    ovr_drawString((char *)(ulong)CONCAT12(flags,*(undefined2 *)
                                                  ((int)&GAlignmentString.seg +
                                                  ((uint)pcVar2 & 0xff) * 4)),_inputBuf,
                   ((far_t *)&GAlignmentString + ((uint)pcVar2 & 0xff))->ofs);
    entries.seg = 2;
    entries.ofs = unaff_SS;
    pcVar2 = ovr_uiInputText(entries,0,far_from_u32((uint32_t)(0x0)),flags,&inputBuf);
    in_stack_0000fff4 = (uint8_t)pcVar2;
    in_stack_0000fff5 = 0;
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
  uint16_t unaff_BP;
  bool bVar2;
  uint8_t in_stack_0000fffc;
  undefined1 in_stack_0000fffd;
  
  ovr_drawString((char *)CONCAT13(in_stack_0000fffd,CONCAT12(in_stack_0000fffc,0x2410)),unaff_BP,
                 0x4fb1);
  pcVar1 = ovr_uiInputText(far_from_u32((uint32_t)(0x22410)),0,far_from_u32((uint32_t)(0x0)),in_stack_0000fffc,0x4933);
  bVar2 = ((uint)pcVar1 & 0xff) != 0;
  if (bVar2) {
    ((char_sheet_t *)sheet)->gender = (char)pcVar1 - 1;
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
    uVar2 = ovr_randBelow();
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
  uint16_t uVar6;
  undefined2 uVar7;
  undefined4 uVar8;
  char cVar9;
  bool bVar10;
  bool bVar11;
  char cVar12;
  undefined2 uVar13;
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
  undefined1 uVar24;
  undefined2 in_CX;
  undefined2 in_DX;
  entity_t *peVar25;
  undefined2 unaff_BP;
  int iVar26;
  char *unaff_SI;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  far_t *in_stack_00000000;
  char *in_stack_00000002;
  uint16_t uStack0006;
  int iStack0008;
  undefined2 uStack000a;
  undefined1 auStack_13e [284];
  undefined2 uStack_22;
  undefined2 uStack_20;
  entity_t *peStack_1e;
  undefined2 in_stack_0000ffe4;
  char cVar27;
  undefined1 uVar28;
  undefined1 uVar29;
  undefined1 uVar30;
  undefined1 uVar31;
  undefined1 uVar32;
  char in_stack_0000fff3;
  byte bVar33;
  uint16_t uVar34;
  undefined1 *puVar35;
  
  uVar24 = (undefined1)unaff_BP;
  uVar29 = (undefined1)((uint)unaff_BP >> 8);
  uVar34 = CONCAT11((char)((uint)in_DX >> 8),(byte)index);
  uVar14 = index & 0xff;
  if (6 < uVar14) {
    return (char *)0x0;
  }
  peVar25 = (entity_t *)(uVar14 * 2);
  switch(uVar14) {
  case 0:
    cVar27 = in(uVar34);
    *unaff_DI = cVar27;
    midpakAd.ofs = (uint16_t)stshStoreFile_2(in_stack_00000000,in_stack_00000002,index);
    midpakAd.seg = uVar34;
    cmidpakComOfs =
         stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                         (char *)((int)(undefined4 *)&_DATA + 1),index);
    _cmidpakComSeg = uVar34;
    ibmsndComOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),index);
    ibmsndComSeg = uVar34;
    sblasterComOfs =
         stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                         (char *)((int)(undefined4 *)&_DATA + 1),index);
    audioPlaceholder2.seg = 0;
    audioPlaceholder2.ofs = 0;
    sblasterComSeg = uVar34;
    fibmbakComOfs =
         stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                         (char *)((int)(undefined4 *)&_DATA + 1),index);
    fibmbakComSeg = uVar34;
    pfVar20 = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                              (char *)((int)(undefined4 *)&_DATA + 1),index);
    sbproComOfs = pfVar20;
    sbproComSeg = uVar34;
    sbproComCopyOfs = pfVar20;
    sbproComCopySeg = uVar34;
    paudioComOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),index);
    sblasterComCopySeg = sblasterComSeg;
    sblasterComCopyOfs = sblasterComOfs;
    pfVar18 = sblasterComOfs;
    paudioComSeg = pfVar20;
    adlibComOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                  (char *)((int)(undefined4 *)&_DATA + 1),index);
    adlibComSeg = pfVar18;
    adlibgComOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),index);
    audioPlaceholder3.seg = 0;
    audioPlaceholder3.ofs = 0;
    musDriver0Seg = 0;
    musDriver0Ofs = 0;
    adlibgComSeg = pfVar18;
    sbfmAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                 (char *)((int)(undefined4 *)&_DATA + 1),index);
    audioPlaceholder0.seg = 0;
    audioPlaceholder0.ofs = 0;
    audioPlaceholder1.seg = 0;
    audioPlaceholder1.ofs = 0;
    sbfmAdvSeg = pfVar18;
    sbp2fmAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),index);
    sbp2fmAdvSeg = pfVar18;
    sbp1fmAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),index);
    sbp1fmAdvSeg = pfVar18;
    pasfmAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                  (char *)((int)(undefined4 *)&_DATA + 1),index);
    pasfmAdvSeg = pfVar18;
    pasoplAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),index);
    pasoplAdvSeg = pfVar18;
    adlibAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                  (char *)((int)(undefined4 *)&_DATA + 1),index);
    adlibAdvSeg = pfVar18;
    adlibgAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),index);
    adlibgAdvSeg = pfVar18;
    mt32mpuAdvOfs =
         stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                         (char *)((int)(undefined4 *)&_DATA + 1),index);
    mt32mpuAdvSeg = pfVar18;
    return (char *)mt32mpuAdvOfs;
  case 1:
    iVar26 = ovr_ovc23_findClearColumn();
    if (iVar26 < 0) {
      ovr_drawTextAt();
      pcVar16 = (char *)"puppetmaker" + 3;
      ((uint8_t *)menuItemRow)[index] = 0x0;
    }
    else {
      uVar24 = 0x6f;
      uVar29 = 0x23;
      bVar33 = (byte)index;
      callResultTemp = func_0x0004f501();
      if (callResultTemp < CONCAT11(uVar29,uVar24)) {
        ((uint8_t *)menuItemRow)[index] = (uint8_t)callResultTemp;
      }
      uVar8 = *(undefined4 *)((uint)bVar33 << 2);
      cVar27 = *(char *)((int)uVar8 + 0x2f);
      pcVar16 = (char *)CONCAT11((char)(((uint)bVar33 << 2) >> 8),cVar27);
      if (cVar27 != -1) {
        ovr_ovc41_pluralSuffix();
        pcVar16 = ovr_stsprintf();
        ovr_drawTextAt();
      }
    }
    return pcVar16;
  case 2:
    ((int *)StshHandles)[(int)unaff_SI] = uVar14;
    *(undefined2 *)((int)(long *)StshPtrs + (int)unaff_SI * 4 + 2) = 0;
    *(undefined2 *)((long *)StshPtrs + (int)unaff_SI) = 0;
    return unaff_SI;
  case 3:
    for (iVar26 = 0; iVar26 < (int)(uint)GLeaderCount; iVar26 = iVar26 + 1) {
      if (((*(char *)((int)*(undefined4 *)(iVar26 << 2) + 0x3d) != '\0') &&
          (uVar34 = 0x2410, *(int *)((int)*(undefined4 *)(iVar26 << 2) + 0x39) == GfxRndSeed)) &&
         (uVar34 = 0x2410, *(uint16_t *)((int)*(undefined4 *)(iVar26 << 2) + 0x3b) == GfxRndSeed2))
      {
        if (GCharLevelsInc != '\0') {
          uVar13 = (undefined2)((ulong)*(undefined4 *)(iVar26 << 2) >> 0x10);
          iVar26 = (int)*(undefined4 *)(iVar26 << 2);
          puVar3 = (uint *)(iVar26 + 0x56);
          uVar14 = *puVar3;
          *puVar3 = *puVar3 + 10000;
          piVar4 = (int *)(iVar26 + 0x58);
          *piVar4 = *piVar4 + (uint)(0xd8ef < uVar14);
          GCharLevelsInc = '\0';
        }
        pfVar18 = manage_settlementScreen();
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
      uVar31 = (undefined1)uVar34;
      uVar32 = (undefined1)(uVar34 >> 8);
      uVar28 = SUB21(pcVar21,0);
      uVar30 = (undefined1)((uint)pcVar21 >> 8);
      pcVar16 = (char *)((uint)pcVar21 | uVar34);
      if (pcVar16 == (char *)0x0) {
        ovr_stats_openCastlePanel();
        ovr_ovc41_usesGMenuItem();
        return pcVar16;
      }
      iVar26 = 0;
      while ((iVar26 < (int)(uint)GLeaderCount &&
             (*(char *)((int)*(undefined4 *)(iVar26 << 2) + 0x28) != '\0'))) {
        iVar26 = iVar26 + 1;
      }
      if (iVar26 < (int)(uint)GLeaderCount) {
        PartyCount = (char)iVar26 + 1;
        ovr_stshFree();
      }
      else {
        if (0x4f < GLeaderCount) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit();
        }
        PartyCount = GLeaderCount + 1;
        GLeaderCount = PartyCount;
      }
      pbVar5 = (byte *)(CONCAT11(uVar30,uVar28) + 0x28);
      *pbVar5 = *pbVar5 | 0x40;
      *(char *)(CONCAT11(uVar30,uVar28) + 0x51) = PartyCount - 1;
      uVar14 = (uint)PartyCount;
      *(undefined2 *)(uVar14 * 4 + -2) = CONCAT11(uVar32,uVar31);
      *(undefined2 *)(uVar14 * 4 + -4) = CONCAT11(uVar30,uVar28);
      if (CurPartySlot == 0) {
        *(undefined1 *)(CONCAT11(uVar30,uVar28) + 0x86) = 1;
      }
      CurPartySlot = CurPartySlot + 1;
    }
    else {
      manage_openTalkWindow();
      uVar13 = *(undefined2 *)((uint)PartyCount * 4 + -2);
      uVar7 = *(undefined2 *)((uint)PartyCount * 4 + -4);
      uVar31 = (undefined1)uVar13;
      uVar32 = (undefined1)((uint)uVar13 >> 8);
      uVar28 = (undefined1)uVar7;
      uVar30 = (undefined1)((uint)uVar7 >> 8);
      manage_usesLitoa10((char_sheet_t *)CONCAT13(uVar32,CONCAT12(uVar31,uVar7)));
    }
    ovr_fmVsprintf((char *)CONCAT13(uVar30,CONCAT12(uVar28,0x2410)),
                   (char *)CONCAT13(uVar29,CONCAT12(uVar24,CONCAT11(uVar32,uVar31))));
    ovr_drawString();
    pcVar16 = ovr_uiInputText();
    pcVar22 = (char *)((uint)pcVar16 & 0xff);
    if (((uint)pcVar16 & 0xff) == 1) {
      pcVar22 = (char *)(PartyCount - 1);
      if (CurPartySlot == 1) {
        ovr_ovc18_checkFortressPlacement();
      }
      else {
        ovr_ovc18_checkFortressPlacement();
      }
      ovr_ovc41_usesGMenuItem();
    }
    else {
      ovr_stats_openCastlePanel();
      ovr_ovc41_usesGMenuItem();
    }
    return pcVar22;
  case 5:
    puVar17 = ovr_mkp();
    (*(uint8_t *)((uint8_t *)&(index))) = (byte)puVar17;
    (*(uint8_t *)((uint8_t *)&(index) + 1)) = (undefined1)((uint)puVar17 >> 8);
    if ((char)*(uint32_t *)CONCAT22(uVar34,puVar17) == '\0') {
      uStack0006 = uVar34;
      pfVar18 = fmMalloc((far_t *)*(undefined2 *)((int)puVar17 + 7),
                         CONCAT13((*(uint8_t *)((uint8_t *)&(index) + 1)),CONCAT12((byte)index,in_stack_00000002)));
      uVar24 = SUB21(pfVar18,0);
      uVar29 = (undefined1)((uint)pfVar18 >> 8);
      if (pfVar18 == (far_t *)0x0 && uVar34 == 0) {
        puVar17 = (uint32_t *)0x0;
      }
      else {
        if (*(int *)((int)puVar17 + 0x11) == 0 && *(int *)((int)puVar17 + 0x13) == 0) {
          stshSeek();
          uVar28 = 0xfd;
          uVar30 = 0x83;
          stshRead();
          pfVar18 = ovr_heapMalloc();
          *(uint16_t *)((int)puVar17 + 0x13) = uVar34;
          *(undefined2 *)((int)puVar17 + 0x11) = pfVar18;
          if (*(int *)((int)puVar17 + 0x11) == 0 && *(int *)((int)puVar17 + 0x13) == 0) {
            bVar10 = false;
          }
          else {
            memcpy((char *)CONCAT13((char)((uint)*(undefined2 *)((int)puVar17 + 0x13) >> 8),
                                    CONCAT12((char)*(undefined2 *)((int)puVar17 + 0x13),
                                             *(undefined2 *)((int)puVar17 + 0x11))),
                   (char *)CONCAT13(uVar30,CONCAT12(uVar28,CONCAT11(uVar29,uVar24))),
                   *(word *)((int)puVar17 + 5));
            bVar10 = true;
          }
        }
        else {
          memcpy((char *)CONCAT13((char)(uVar34 >> 8),CONCAT12((char)uVar34,pfVar18)),
                 (char *)CONCAT13((char)((uint)*(undefined2 *)((int)puVar17 + 0x13) >> 8),
                                  CONCAT12((char)*(undefined2 *)((int)puVar17 + 0x13),
                                           *(undefined2 *)((int)puVar17 + 0x11))),
                 *(word *)((int)puVar17 + 5));
          bVar10 = true;
        }
        if ((bVar10) && ((puVar19 = ovr_mkp(), uVar34 != uStack0006 || (puVar19 != puVar17)))) {
          iVar26 = *(int *)((int)puVar17 + 0xf);
          iVar23 = *(int *)((int)puVar17 + 0xd);
          uVar34 = *(uint16_t *)((int)puVar17 + 0xb);
          uVar6 = *(uint16_t *)((int)puVar17 + 9);
          if (uVar6 != 0 || uVar34 != 0) {
            uVar13 = (undefined2)
                     (CONCAT13((char)(uVar34 >> 8),CONCAT12((char)uVar34,uVar6)) >> 0x10);
            *(int *)(uVar6 + 0xf) = iVar26;
            *(int *)(uVar6 + 0xd) = iVar23;
          }
          if (iVar23 != 0 || iVar26 != 0) {
            *(uint16_t *)(iVar23 + 0xb) = uVar34;
            *(uint16_t *)(iVar23 + 9) = uVar6;
            uVar6 = StshCtPtr2.ofs;
            uVar34 = StshCtPtr2.seg;
          }
          StshCtPtr2.seg = uVar34;
          StshCtPtr2.ofs = uVar6;
          uVar34 = Stsh_2410_47f6.ofs;
          *(uint16_t *)((int)puVar17 + 0xf) = Stsh_2410_47f6.seg;
          *(uint16_t *)((int)puVar17 + 0xd) = uVar34;
          *(undefined2 *)((int)puVar17 + 0xb) = 0;
          *(undefined2 *)((int)puVar17 + 9) = 0;
          *(uint16_t *)(Stsh_2410_47f6.ofs + 0xb) = uStack0006;
          *(undefined2 *)(Stsh_2410_47f6.ofs + 9) = puVar17;
          Stsh_2410_47f6.seg = uStack0006;
          Stsh_2410_47f6.ofs = (uint16_t)puVar17;
        }
        puVar17 = (uint32_t *)CONCAT11(uVar29,uVar24);
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
      cVar27 = -8;
      cVar12 = 'T';
      uVar14 = ovr_blitLabel();
      *unaff_SI = *unaff_SI + (char)(uVar14 >> 8) + ((undefined1 *)0xfff3 < &stack0xfff2);
      *(undefined1 *)((int)&(((entity_t *)*(entity_t **)&Entities)->base).entity + uVar14 + 1) = 0;
      uVar13 = (undefined2)((ulong)Entities >> 0x10);
      *(undefined1 *)((int)&((entity_t *)Entities)[(int)unaff_SI].base.state + 1) =
           (char)((entity_t *)Entities)[(int)unaff_SI].base.flags32;
      if (unaff_SI + 1 < EntityCount) {
        pcVar16 = (char *)"thief" + 5;
        ovr_say();
        return pcVar16;
      }
      if ((cVar27 != '\0') || (cVar12 != '\0')) {
        if ((char)((uint)((int)unaff_SI * 0x37) >> 8) == '\0') {
          ovr_stop_audio();
          CurSfxType3 = 0xff;
          ovr_play_sfx();
        }
        else if (cVar12 == '\0') {
          if (cVar27 != '\0') {
            ovr_play_sfx();
          }
        }
        else {
          ovr_play_sfx();
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
    peStack_1e = (entity_t *)0x4;
    ovr_ovc45_compute9();
    func_0x0005d3f4();
    peStack_1e = (entity_t *)auStack_13e;
    uStack_20 = 0x23f1;
    uStack_22 = 0x44;
    ovr_stsprintf();
    ovr_blitLabel();
    TextBlitY = TextBlitY + 0xc;
    iVar26 = ovr_font_textWidth();
    TextBlitX = 0x89 - iVar26;
    ovr_blitLabel();
    iVar26 = ovr_font_textWidth();
    uVar34 = 0xd4 - iVar26;
    cVar27 = '\x10';
    bVar33 = 0x24;
    TextBlitX = uVar34;
    ovr_blitLabel();
    iVar26 = 0;
    while( true ) {
      TextBlitY = TextBlitY + 0xc;
      cVar12 = (char)in_CX;
      if ((int)(uint)bVar33 <= iVar26) break;
      TextBlitX = 0x11;
      if ((iVar26 < 5) || (cVar27 == '\0')) {
        ovr_blitLabel();
      }
      else {
        ovr_blitLabel();
      }
      func_0x0005f303();
      ovr_stsprintf();
      iVar23 = ovr_font_textWidth();
      TextBlitX = 0x89 - iVar23;
      ovr_blitLabel();
      ovr_stsprintf();
      iVar23 = ovr_font_textWidth();
      uVar34 = 0xd4 - iVar23;
      TextBlitX = uVar34;
      cVar27 = (char)unaff_SS;
      bVar33 = (byte)((uint)unaff_SS >> 8);
      ovr_blitLabel();
      iVar26 = iVar26 + 1;
    }
    CurSfxType3 = 0x3c;
    puVar35 = &stack0xfff2;
    uVar13 = ovr_ovc28_usesUiInputText();
    cVar27 = (char)uVar13;
    keyboardInputMode = 0;
    if (((cVar27 != '\0') && (cVar27 != '\x01')) && (cVar27 != -2)) {
      (&stack0xbac4)[(int)unaff_DI] = (&stack0xbac4)[(int)unaff_DI] + cVar12;
      iVar23 = 0x2410;
      do {
        bVar33 = *(byte *)(iVar23 * uVar34 + 0x21);
        uVar24 = (undefined1)(iVar23 * uVar34 >> 8);
        iVar23 = iVar26;
        if (*(byte *)(iVar26 * 0x34 + 0x22) < bVar33) {
          bVar33 = *(byte *)(iVar26 * 0x34 + 0x22);
          uVar24 = (undefined1)((uint)(iVar26 * 0x34) >> 8);
          *(byte *)(iVar26 * 0x34 + 0x21) = bVar33;
        }
        do {
          iVar23 = iVar23 + 1;
          if ((int)(uint)AgntCount <= iVar23) {
            iVar26 = ovr_audio_panFromX();
            uVar24 = (undefined1)((uint)iVar26 >> 8);
            ovr_play_sfxU();
            return (char *)CONCAT11(uVar24,1);
          }
        } while (*(int *)(iVar23 * 0x34 + 0x1b) != *(int *)(iStack0008 + 0x1b));
        if ((byte)puVar35[0x32] < *(byte *)(iVar23 * 0x34 + 0x22)) {
          *(undefined1 *)(iVar23 * 0x34 + 0x22) = puVar35[0x32];
        }
        uVar34 = 0x34;
        iVar26 = iVar23;
      } while( true );
    }
    if (cVar27 == -2) {
      Cancelled = 1;
    }
    return (char *)"puppetmaker" + 3;
  }
  do {
    (peStack_1e->base).target =
         (byte)((int)(uint)*(byte *)((int)&(peStack_1e->base).owner +
                                    ((int)(uint)(peVar25->base).faction >> 2)) >>
               (((peStack_1e->base).faction & 3) << 1)) & 3;
    cVar27 = func_0x0004f32d();
    if (cVar27 == '\0') {
      (((entity_t *)CONCAT22(in_stack_0000ffe4,peStack_1e))->base).x =
           (((entity_t *)CONCAT22(in_stack_0000ffe4,peStack_1e))->base).x +
           (int)*(char *)((peStack_1e->base).target + 0x885);
      puVar1 = &(peStack_1e->base).y;
      *puVar1 = *puVar1 + (int)*(char *)((peStack_1e->base).target + 0x889);
      puVar2 = &(peStack_1e->base).faction;
      *puVar2 = *puVar2 + 0x1;
    }
    else {
      (peStack_1e->base).faction = 0x0;
      *(undefined1 *)&(peStack_1e->base).state = 0;
    }
L_attact_3f0b_1082_1477:
    cVar27 = '\x01';
    uVar14 = ovr_alignUp4();
    uVar28 = (undefined1)uVar14;
    uVar30 = (undefined1)(uVar14 >> 8);
    uVar34 = (((entity_t *)CONCAT22(in_stack_0000ffe4,peStack_1e))->base).x;
    uVar24 = (undefined1)uVar34;
    uVar29 = (undefined1)(uVar34 >> 8);
    uVar34 = 0x2379;
    uVar15 = ovr_alignUp4();
    uVar14 = CONCAT11(uVar29,uVar24);
    if ((CONCAT11(uVar30,uVar28) == uVar15) &&
       (uVar14 = CONCAT11(uVar29,uVar24), (peStack_1e->base).destY == (peStack_1e->base).y)) {
      (peStack_1e->base).destX = 0;
      (peStack_1e->base).destY = 0;
      if (*(char *)((int)&(peStack_1e->base).entity + 3) == -1) {
        cVar12 = -1;
      }
      else {
        uVar8 = *(undefined4 *)((uint)*(byte *)((int)&(peStack_1e->base).entity + 3) << 2);
        cVar12 = *(char *)((int)uVar8 + 0x89);
      }
      uVar14 = CONCAT11(uVar29,uVar24);
      if (cVar12 != -1) {
        for (uVar15 = 0; uVar14 = CONCAT11(uVar29,uVar24), uVar15 < SquareRecCount;
            uVar15 = uVar15 + 1) {
          uVar14 = ovr_alignUp4();
          bVar33 = (byte)uVar14;
          uVar28 = (undefined1)(uVar14 >> 8);
          uVar34 = (((entity_t *)CONCAT22(in_stack_0000ffe4,peStack_1e))->base).x;
          uVar24 = (undefined1)uVar34;
          uVar29 = (undefined1)(uVar34 >> 8);
          uVar34 = 0x2379;
          uVar14 = ovr_alignUp4();
          if ((CONCAT11(uVar28,bVar33) == uVar14) &&
             (*(uint16_t *)(uVar15 * 0x13 + 2) == (peStack_1e->base).y)) {
            uVar14 = uVar15 * 0x13 + (uint)bVar33 + 0xe;
            uVar34 = 0x2379;
            func_0x0004f930();
            if (*(uint16_t *)(uVar15 * 0x13 + 2) == GfxRndSeed2) {
              uVar14 = ovr_alignUp4();
              bVar33 = (byte)uVar14;
              uVar28 = (undefined1)(uVar14 >> 8);
              uVar24 = (undefined1)GfxRndSeed;
              uVar29 = (undefined1)((uint)GfxRndSeed >> 8);
              uVar34 = 0x2379;
              uVar15 = ovr_alignUp4();
              uVar14 = CONCAT11(uVar29,uVar24);
              if (CONCAT11(uVar28,bVar33) == uVar15) {
                (&stack0xfff2)[bVar33] = 1;
                uVar14 = CONCAT11(uVar29,uVar24);
              }
            }
            break;
          }
        }
      }
    }
    if (AgntFlag1 != false) {
      if ((((((entity_t *)CONCAT22(in_stack_0000ffe4,peStack_1e))->base).x < GfxRndSeed - 2U) ||
          (GfxRndSeed + 1U < (((entity_t *)CONCAT22(in_stack_0000ffe4,peStack_1e))->base).x)) ||
         ((peStack_1e->base).y != GfxRndSeed2)) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      if (((uVar14 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uVar14)) || (GfxRndSeed2 != uVar34)) {
        bVar11 = false;
      }
      else {
        bVar11 = true;
      }
      if (bVar11 || bVar10) {
        if (bVar11) {
          if (bVar10) {
            cVar12 = func_0x0004f944();
            while ((cVar12 != '\0' && (pcVar16 = ovr_ovc15_textArena(), ((uint)pcVar16 & 0xff) != 0)
                   )) {
              cVar12 = cVar12 + -1;
            }
          }
          else {
            cVar12 = (char)((ulong)((peStack_1e->base).animFrame + 0xf) / 0x10);
            while (cVar9 = cVar12 + -1, cVar12 != '\0') {
              ovr_agnt_usesAgntCount6();
              cVar12 = cVar9;
            }
          }
        }
        else {
          ovr_ovc15_clearVisited();
          cVar12 = (char)((ulong)((peStack_1e->base).animFrame + 0xf) / 0x10);
          while (cVar9 = cVar12 + -1, cVar12 != '\0') {
            ovr_ovc15_textArena();
            cVar12 = cVar9;
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
        ovr_ovc24_removeOtherEntities();
        GGameState = 0x1f;
        if (cVar27 != '\0') {
          ovr_constr_usesBlitRect();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (iVar26 = 0; iVar26 < 5; iVar26 = iVar26 + 1) {
          if ((&stack0xfff2)[iVar26] != '\0') {
            ovr_ovc41_usesMiceBlitRect();
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
      peStack_1e = (entity_t *)Entities + (int)unaff_DI;
      unaff_ES = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
      uVar14 = ovr_alignUp4();
      uVar24 = (undefined1)uVar14;
      uVar29 = (undefined1)(uVar14 >> 8);
      uVar14 = ovr_alignUp4();
      if ((CONCAT11(uVar29,uVar24) == uVar14) && ((peStack_1e->base).destY == (peStack_1e->base).y))
      {
        func_0x0004fb8e();
      }
    } while (((peStack_1e->base).destX == 0 && (peStack_1e->base).destY == 0) ||
            (*(char *)((int)&(peStack_1e->base).entity + 1) != '\0'));
    peVar25 = peStack_1e;
    in_stack_0000ffe4 = unaff_ES;
  } while ((peStack_1e->base).faction < (byte)(peStack_1e->base).state);
  uVar13 = ovr_ovc07_signum();
  cVar12 = (char)uVar13;
  uVar29 = (undefined1)((uint)uVar13 >> 8);
  uVar13 = ovr_ovc07_signum();
  cVar27 = (char)uVar13;
  uVar24 = (undefined1)((uint)uVar13 >> 8);
  in_stack_0000ffe4 = unaff_ES;
  if (((CONCAT11(uVar29,cVar12) == 0) ||
      (uVar34 = ovr_randBelow(), in_stack_0000ffe4 = unaff_ES, (char)uVar34 == '\0')) ||
     (cVar9 = func_0x0004f412(), in_stack_0000ffe4 = unaff_ES, cVar9 != '\0')) {
    if ((CONCAT11(uVar24,cVar27) == 0) || (cVar9 = func_0x0004f412(), cVar9 != '\0')) {
      if ((CONCAT11(uVar29,cVar12) == 0) || (cVar27 = func_0x0004f412(), cVar27 != '\0')) {
        uVar14 = ovr_ovc26_usesStExit();
        if ((char)uVar14 == '\0') {
          uVar14 = ovr_ovc26_usesRandBelow();
          if ((uVar14 & 0xff) == 0) {
            peVar25 = (entity_t *)((uint)(peStack_1e->base).gindex * 0x95);
            uVar34 = 0x195d;
switchD_4000_e2bf_caseD_6:
            if (peVar25[0xb4].base.teamCode == 0x0) {
              func_0x0004fb8e();
            }
          }
        }
        else {
          (peStack_1e->base).target =
               (byte)((int)(uint)*(byte *)((int)&(peStack_1e->base).owner +
                                          ((int)(uint)(peStack_1e->base).faction >> 2)) >>
                     (((peStack_1e->base).faction & 3) << 1)) & 3;
          cVar27 = func_0x0004f32d();
          if (cVar27 == '\0') {
            (((entity_t *)CONCAT22(in_stack_0000ffe4,peStack_1e))->base).x =
                 (((entity_t *)CONCAT22(in_stack_0000ffe4,peStack_1e))->base).x +
                 (int)*(char *)((peStack_1e->base).target + 0x885);
            puVar1 = &(peStack_1e->base).y;
            *puVar1 = *puVar1 + (int)*(char *)((peStack_1e->base).target + 0x889);
            puVar2 = &(peStack_1e->base).faction;
            *puVar2 = *puVar2 + 0x1;
          }
        }
      }
      else {
        (((entity_t *)CONCAT22(in_stack_0000ffe4,peStack_1e))->base).x =
             (((entity_t *)CONCAT22(in_stack_0000ffe4,peStack_1e))->base).x +
             CONCAT11(uVar29,cVar12);
        (peStack_1e->base).target = 0x2 - cVar12;
      }
    }
    else {
      puVar1 = &(peStack_1e->base).y;
      *puVar1 = *puVar1 + CONCAT11(uVar24,cVar27);
      (peStack_1e->base).target = cVar27 + 0x1;
    }
  }
  else {
    (((entity_t *)CONCAT22(unaff_ES,peStack_1e))->base).x =
         (((entity_t *)CONCAT22(unaff_ES,peStack_1e))->base).x + CONCAT11(uVar29,cVar12);
    (peStack_1e->base).target = 0x2 - cVar12;
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
  char *in_DX;
  uint16_t uVar6;
  undefined2 unaff_SI;
  int iVar7;
  char *unaff_SS;
  uint8_t flags;
  undefined1 uVar8;
  uint16_t widths;
  undefined1 auStack_9c [10];
  uint8_t menuItems;
  uint16_t auStack_90 [21];
  uint8_t msg;
  char_sheet_t *pcStack_16;
  char *pcStack_14;
  int iStack_12;
  uint uStack_10;
  char *pcStack_e;
  uint16_t uStack_c;
  uint8_t keepDiscard;
  
  flags = (uint8_t)unaff_SI;
  uVar8 = (undefined1)((uint)unaff_SI >> 8);
  dst.seg = (uint16_t)unaff_SS;
  dst.ofs = (uint16_t)&keepDiscard;
  F_SCOPY(far_from_u32((uint32_t)(0x24104a16)),dst);
  ovr_fmFreeAudio(CONCAT11(uVar8,flags),1);
  ovr_ovc13_usesBlitRect();
  pcStack_16 = ovr_stshAlloc((ulong)CONCAT11(uVar8,flags) << 0x10,0xae);
  pcStack_14 = in_DX;
  do {
    while( true ) {
      _fmemset((void *)ZEXT24(pcStack_14),0xae,CONCAT11(uVar8,flags));
      pcStack_16->charIndex = 0xff;
      while( true ) {
        if (TimerSeed.lo == 0 && TimerSeed.hi == 0) {
          TimerSeed.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
          TimerSeed.lo = *(uint16_t *)BDA_DailyTimeCounter;
        }
        srand8(CONCAT22(TimerSeed.hi,TimerSeed.lo));
        manage_openTalkWindow();
        manage_rollStats((char_sheet_t *)CONCAT13(uVar8,CONCAT12(flags,pcStack_14)),pcStack_16);
        manage_usesLitoa10((char_sheet_t *)CONCAT22(pcStack_14,pcStack_16));
        auStack_90[0] = 0x2410;
        _menuItems = 0x4fce;
        widths = 1;
        auStack_90[2] = 0;
        auStack_90[1] = 0;
        iVar4 = 1;
        for (iStack_12 = 0; iVar7 = iVar4 + 1, iStack_12 < 4; iStack_12 = iStack_12 + 1) {
          (&stack0xff63)[iVar4] = (char)iStack_12 + '\x02';
          uVar1 = *(undefined2 *)(iStack_12 * 4 + 0xeb);
          auStack_90[iVar7 * 2] = *(uint16_t *)(iStack_12 * 4 + 0xed);
          *(undefined2 *)(&menuItems + iVar7 * 4) = uVar1;
          iVar4 = iVar7;
        }
        (&stack0xff63)[iVar4] = 6;
        if (pcStack_16->stats[4] < 9) {
          auStack_90[iVar7 * 2] = 0;
          (&menuItems + iVar7 * 4)[0] = 0x0;
          (&menuItems + iVar7 * 4)[1] = 0x0;
        }
        else {
          auStack_90[iVar7 * 2] = GUnitDescriptions[4].seg;
          *(uint16_t *)(&menuItems + iVar7 * 4) = GUnitDescriptions[4].ofs;
        }
        iVar7 = iVar4 + 2;
        auStack_9c[iVar4] = 7;
        if (pcStack_16->stats[1] < 9) {
          auStack_90[iVar7 * 2] = 0;
          (&menuItems + iVar7 * 4)[0] = 0x0;
          (&menuItems + iVar7 * 4)[1] = 0x0;
        }
        else {
          auStack_90[iVar7 * 2] = GUnitDescriptions[5].seg;
          *(uint16_t *)(&menuItems + iVar7 * 4) = GUnitDescriptions[5].ofs;
        }
        iVar7 = iVar4 + 3;
        auStack_9c[iVar4 + 1] = 8;
        if ((pcStack_16->stats[4] < 9) || (pcStack_16->stats[3] < 9)) {
          auStack_90[iVar7 * 2] = 0;
          (&menuItems + iVar7 * 4)[0] = 0x0;
          (&menuItems + iVar7 * 4)[1] = 0x0;
        }
        else {
          auStack_90[iVar7 * 2] = GUnitDescriptions[6].seg;
          *(uint16_t *)(&menuItems + iVar7 * 4) = GUnitDescriptions[6].ofs;
        }
        ovr_drawString((char *)CONCAT13(uVar8,CONCAT12(flags,0x2410)),widths,0x4fd5);
        entries.seg = 9;
        entries.ofs = (uint16_t)unaff_SS;
        pcVar3 = ovr_uiInputText(entries,0,far_from_u32((uint32_t)(0x0)),flags,&menuItems);
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
      uVar6 = *(uint16_t *)(iVar4 + -4);
      (pcStack_16->name).seg = *(uint16_t *)(iVar4 + -2);
      (&pcStack_16->name)->ofs = uVar6;
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
      manage_usesLitoa10((char_sheet_t *)CONCAT22(pcStack_14,pcStack_16));
      uVar5 = abilitiesDlg((char_sheet_t *)CONCAT22(pcStack_14,pcStack_16));
      if ((uVar5 & 0xff) == 0) break;
      manage_rollHitPoints((char_sheet_t *)CONCAT22(pcStack_14,pcStack_16));
      while( true ) {
        manage_usesLitoa10((char_sheet_t *)CONCAT22(pcStack_14,pcStack_16));
        uVar5 = alignmentDlg((char_sheet_t *)CONCAT22(pcStack_14,pcStack_16));
        if ((uVar5 & 0xff) == 0) break;
L_chargen_1661:
        manage_openTalkWindow();
        manage_usesLitoa10((char_sheet_t *)CONCAT22(pcStack_14,pcStack_16));
        bVar2 = uiPickGender((char_sheet_t *)CONCAT22(pcStack_14,pcStack_16));
        if (bVar2) {
          do {
            manage_blitTalkWindow();
            ovr_drawString((char *)CONCAT13(uVar8,CONCAT12(flags,0x2410)),widths,0x500d);
            while (pcStack_e = ovr_uiReadString((char *)0x60000,0,0,(char *)0x0), uStack_c = uVar6,
                  pcStack_e == (char *)0x0 && uVar6 == 0) {
              if (inputCancelled != '\0') {
                if (UserWantsExit == '\0') goto L_chargen_1661;
                goto L_chargen_17B2;
              }
              manage_blitTalkWindow();
              ovr_drawString((char *)CONCAT13(uVar8,CONCAT12(flags,0x2410)),widths,0x502a);
            }
            ovr_drawString((char *)CONCAT13(uVar8,CONCAT12(flags,0x2410)),widths,0x4b75);
            __fstrncpy((char *)CONCAT22(pcStack_14,pcStack_16),(char *)CONCAT22(uStack_c,pcStack_e),
                       0x27);
            (*(uint8_t *)((uint8_t *)&(handle.seg))) = flags;
            handle.ofs = uStack_c;
            (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar8;
            ovr_stshFree(handle,pcStack_e);
            pcVar3 = ovr_stsprintf((char *)CONCAT22(0x505a,unaff_SS),
                                   (char *)CONCAT22(pcStack_16,(char *)"puppetmaker" + 3),pcStack_14
                                   ,&msg);
            ovr_drawString((char *)CONCAT13(uVar8,CONCAT12(flags,uVar6)),widths,pcVar3);
            entries_00.seg = 2;
            entries_00.ofs = (uint16_t)unaff_SS;
            pcVar3 = ovr_uiInputText(entries_00,0,far_from_u32((uint32_t)(0x0)),flags,&keepDiscard);
            uStack_10 = (uint)pcVar3 & 0xff;
            if (uStack_10 != 0) {
              if (uStack_10 != 2) {
                pcStack_16->statMask = pcStack_16->statMask | 2;
                manage_openTalkWindow();
                manage_usesLitoa10((char_sheet_t *)CONCAT22(pcStack_14,pcStack_16));
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
  (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = flags;
  handle_00.ofs = (uint16_t)pcStack_14;
  (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar8;
  ovr_stshFree(handle_00,pcStack_16);
  return (char_sheet_t *)0x0;
}



/* 4d05:17c7 */

/* Stops music/agents and opens the settlement screen for a party slot (manage_settlementScreen),
   restoring the menu afterwards. */

void __cdecl16far manage_showSettlementScreen(uint8_t partySlot,...)

{
  byte unaff_BP;
  undefined1 in_stack_00000004;
  
  ovr_attact_usesAgntFlag1();
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  CurMusicType = 0xff;
  savedMenuItem = GMenuItem;
  MenuModeSaved = MenuMode;
  TextBlitDstSeg = 0xa000;
  manage_settlementScreen(unaff_BP,CONCAT11(0x24,in_stack_00000004));
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
  byte *pbVar3;
  far_t entries;
  far_t gfx;
  far_t dst;
  far_t dst_00;
  far_t handle;
  char_sheet_t *pcVar4;
  uint uVar5;
  char *pcVar6;
  uint16_t widths;
  int iVar7;
  undefined2 uVar8;
  uint16_t unaff_SS;
  byte in_stack_0000ffee;
  uint8_t flags;
  undefined1 in_stack_0000ffef;
  undefined1 uVar9;
  uint8_t inputBuf;
  uint uStack_6;
  int iStack_4;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&inputBuf;
  F_SCOPY(far_from_u32((uint32_t)(0x24104a1e)),dst);
  gfx.seg = 0xc31d;
  gfx.ofs = FontHandle.seg;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = in_stack_0000ffee;
  dst_00.ofs = 0xa000;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = in_stack_0000ffef;
  ovr_blitLoadRleGfx(gfx,dst_00,FontHandle.ofs);
  ovr_attact_usesAgntFlag1();
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  CurMusicType = 0xff;
  savedMenuItem = GMenuItem;
  MenuModeSaved = MenuMode;
  TextBlitDstSeg = 0xa000;
  for (iStack_4 = 0; widths = 0x2410, iStack_4 < (int)(uint)GLeaderCount; iStack_4 = iStack_4 + 1) {
    if (((*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3d) != '\0') &&
        (*(int *)((int)*(undefined4 *)(iStack_4 << 2) + 0x39) == GfxRndSeed)) &&
       (*(int *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3b) == GfxRndSeed2)) {
      if (GCharLevelsInc != '\0') {
        uVar8 = (undefined2)((ulong)*(undefined4 *)(iStack_4 << 2) >> 0x10);
        iVar7 = (int)*(undefined4 *)(iStack_4 << 2);
        puVar1 = (uint *)(iVar7 + 0x56);
        uVar5 = *puVar1;
        *puVar1 = *puVar1 + 10000;
        piVar2 = (int *)(iVar7 + 0x58);
        *piVar2 = *piVar2 + (uint)(0xd8ef < uVar5);
        GCharLevelsInc = '\0';
      }
      manage_settlementScreen(in_stack_0000ffee,CONCAT11(0x24,(char)iStack_4));
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
    pcVar4 = chargen();
    flags = (uint8_t)pcVar4;
    uVar9 = (undefined1)((uint)pcVar4 >> 8);
    if (pcVar4 == (char_sheet_t *)0x0 && widths == 0) {
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
      PartyCount = (char)iStack_4 + 1;
      (*(uint8_t *)((uint8_t *)&(handle.seg))) = flags;
      handle.ofs = *(undefined2 *)((uint)PartyCount * 4 + -2);
      (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar9;
      ovr_stshFree(handle,*(undefined2 *)((uint)PartyCount * 4 + -4));
    }
    else {
      if (0x4f < GLeaderCount) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit((int)pcVar4,0x1d);
      }
      PartyCount = GLeaderCount + 1;
      GLeaderCount = PartyCount;
    }
    pbVar3 = (byte *)(CONCAT11(uVar9,flags) + 0x28);
    *pbVar3 = *pbVar3 | 0x40;
    *(char *)(CONCAT11(uVar9,flags) + 0x51) = PartyCount - 1;
    uVar5 = (uint)PartyCount;
    pcVar4 = (char_sheet_t *)((char *)"halfling castle" + 0xc);
    *(uint16_t *)(uVar5 * 4 + -2) = widths;
    *(undefined2 *)(uVar5 * 4 + -4) = CONCAT11(uVar9,flags);
    if (CurPartySlot == 0) {
      *(undefined1 *)(CONCAT11(uVar9,flags) + 0x86) = 1;
    }
    CurPartySlot = CurPartySlot + 1;
  }
  else {
    manage_openTalkWindow();
    widths = *(uint16_t *)((uint)PartyCount * 4 + -2);
    pcVar4 = (char_sheet_t *)*(undefined2 *)((uint)PartyCount * 4 + -4);
    flags = (uint8_t)pcVar4;
    uVar9 = (undefined1)((uint)pcVar4 >> 8);
    manage_usesLitoa10((char_sheet_t *)CONCAT22(widths,pcVar4));
  }
  pcVar6 = ovr_fmVsprintf((char *)CONCAT22(CONCAT11(uVar9,flags),(char *)"puppetmaker" + 3),
                          (char *)CONCAT13(uVar9,CONCAT12(flags,widths)));
  ovr_drawString((char *)CONCAT13(uVar9,CONCAT12(flags,pcVar4)),widths,pcVar6);
  entries.seg = 2;
  entries.ofs = unaff_SS;
  pcVar6 = ovr_uiInputText(entries,0,far_from_u32((uint32_t)(0x0)),flags,&inputBuf);
  uStack_6 = (uint)pcVar6 & 0xff;
  if (uStack_6 == 1) {
    iStack_4 = PartyCount - 1;
    if (CurPartySlot == 1) {
      ovr_ovc18_checkFortressPlacement(flags,2);
    }
    else {
      ovr_ovc18_checkFortressPlacement(flags,1);
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
  ulong dividend;
  long lVar4;
  char *in_stack_00000004;
  uint8_t sign;
  
  if (((int)n < 1) && ((int)n < 0)) {
    bVar1 = true;
    bVar3 = (*(uint16_t *)((uint8_t *)&(buf) + 2)) != 0;
    (*(uint16_t *)((uint8_t *)&(buf) + 2)) = -(*(uint16_t *)((uint8_t *)&(buf) + 2));
    n = (long)(-(uint)bVar3 - (int)n);
  }
  else {
    bVar1 = false;
  }
  digit = LMOD_at_(CONCAT22((int)n,(*(uint16_t *)((uint8_t *)&(buf) + 2))),10);
  *(char *)CONCAT22((char *)buf,in_stack_00000004) = (char)digit + '0';
  in_stack_00000004[1] = '\0';
  while( true ) {
    lVar4 = LDIV_at_(CONCAT22((int)n,(*(uint16_t *)((uint8_t *)&(buf) + 2))),10);
    if (lVar4 == 0) break;
    sVar2 = strlen((char *)CONCAT22((char *)buf,in_stack_00000004));
    if ((sVar2 & 3) == 3) {
      len = strlen((char *)CONCAT22((char *)buf,in_stack_00000004));
      _fmemmove((char *)CONCAT22((char *)buf,in_stack_00000004 + 1),
                (char *)CONCAT22((char *)buf,in_stack_00000004),len + 1);
      *(char *)CONCAT22((char *)buf,in_stack_00000004) = ',';
    }
    sVar2 = strlen((char *)CONCAT22((char *)buf,in_stack_00000004));
    _fmemmove((char *)CONCAT22((char *)buf,in_stack_00000004 + 1),
              (char *)CONCAT22((char *)buf,in_stack_00000004),sVar2 + 1);
    dividend = LDIV_at_(CONCAT22((int)n,(*(uint16_t *)((uint8_t *)&(buf) + 2))),10);
    n = dividend >> 0x10;
    (*(uint16_t *)((uint8_t *)&(buf) + 2)) = (int)dividend;
    lVar4 = LMOD_at_(dividend,10);
    *(char *)CONCAT22((char *)buf,in_stack_00000004) = (char)lVar4 + '0';
  }
  if (bVar1) {
    sVar2 = strlen((char *)CONCAT22((char *)buf,in_stack_00000004));
    _fmemmove((char *)CONCAT22((char *)buf,in_stack_00000004 + 1),
              (char *)CONCAT22((char *)buf,in_stack_00000004),sVar2 + 1);
    *(char *)CONCAT22((char *)buf,in_stack_00000004) = '-';
  }
  return in_stack_00000004;
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
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  uint8_t unaff_DI;
  char *unaff_SS;
  byte in_stack_00000004;
  char mode;
  uint8_t *puVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  uint8_t resultPtrs;
  undefined2 auStack_156 [9];
  uint8_t menuItems;
  undefined2 auStack_142 [9];
  uint8_t structNames;
  undefined2 auStack_12e [59];
  undefined1 auStack_b8 [80];
  undefined1 auStack_68 [80];
  undefined1 uStack_18;
  char cStack_17;
  int iStack_16;
  char *pcStack_14;
  char *pcStack_12;
  char *pcStack_10;
  char *pcStack_e;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  char *pcStack_6;
  char_sheet_t *pcStack_4;
  
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
  dst.ofs = (uint16_t)&resultPtrs;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)((uint)unaff_SS >> 8);
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
  uStack_18 = 0;
  if (((cStack_17 != '\x02') && (cStack_17 != '\x03')) && (cStack_17 != '\x04')) {
    manage_usesCurSfxType3();
    return;
  }
  if (ScreenMode == '\0') {
    manage_openTalkWindow();
  }
  else {
    gfx.seg = 0;
    gfx.ofs = talkwin9Cut1Seg;
    ovr_blitGfxRect(gfx,0,1098,(brect_t *)0x102410,0x0,(bool)unaff_DI,talkwin9Cut1Ofs,0x4a,0);
  }
  TextBlitY = 0xc;
  TextBlitX = 0x11;
  mode = (char)Font02.ofs;
  uVar11 = (undefined1)(Font02.ofs >> 8);
  if (in_stack_00000004 == 0xff) {
    ovr_blitLabel((char *)CONCAT13(uVar11,CONCAT12(mode,0x2410)),
                  (uint8_t *)CONCAT22(0xde,Font02.seg),80,unaff_DI,0x5293,0x50);
  }
  else {
    pcStack_4 = (char_sheet_t *)((undefined2 *)((uint)in_stack_00000004 * 4))[1];
    pcVar5 = (char *)*(undefined2 *)((uint)in_stack_00000004 * 4);
    uVar10 = 0x50;
    uVar12 = 0;
    uVar6 = 0xde;
    puVar9 = (uint8_t *)Font02.seg;
    pcStack_6 = pcVar5;
    iVar7 = ovr_ovc45_compute9((char *)CONCAT22(pcVar5,unaff_SS),
                               (char *)CONCAT22(Font02.ofs,pcStack_4),
                               (char *)CONCAT22(0x69,Font02.seg),3,mode,auStack_68);
    pvVar2 = manage_playerTitle((char_sheet_t *)CONCAT22(iVar7,pcStack_4),pcStack_6,pcVar5);
    pcVar3 = ovr_stsprintf((char *)CONCAT22(0x52a1,unaff_SS),
                           (char *)CONCAT22(pvVar2,(char *)"puppetmaker" + 3),pcVar5,auStack_b8);
    ovr_blitLabel((char *)CONCAT13(uVar11,CONCAT12(mode,pcVar5)),(uint8_t *)CONCAT22(uVar6,puVar9),
                  CONCAT11(uVar12,uVar10),unaff_DI,pcVar3,uVar10);
  }
  TextBlitY = TextBlitY + 0xc;
  TextBlitX = 0x11;
  ovr_blitLabel((char *)CONCAT13((char)(Font02.ofs >> 8),CONCAT12((char)Font02.ofs,0x2410)),
                (uint8_t *)CONCAT22(0xde,Font02.seg),224,unaff_DI,0x52bd,0xe0);
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
  for (iVar8 = 0; iVar8 < 0xd; iVar8 = iVar8 + 1) {
    if (iVar8 + iVar7 < 0x1e) {
      TextBlitX = 0x11;
      iVar4 = (iVar8 + iVar7) * 6;
      ovr_blitLabel((char *)CONCAT13((char)(Font02.ofs >> 8),
                                     CONCAT12((char)Font02.ofs,
                                              *(undefined2 *)((int)&GStructures[0].name + 2 + iVar4)
                                             )),(uint8_t *)CONCAT22(0xde,Font02.seg),224,unaff_DI,
                    *(undefined2 *)((int)&GStructures[0].name + iVar4),0xe0);
      lVar1 = (long)(iVar8 + iVar7) * 6;
      uVar6 = (undefined2)((ulong)lVar1 >> 0x10);
      iStack_16 = manage_usesGUnitCount
                            (in_stack_00000004,(&((unk01_t *)GStructures)->type)[(int)lVar1],
                             (int *)CONCAT22(unaff_SS,&iStack_8),(int *)CONCAT22(unaff_SS,&iStack_a)
                             ,(int *)CONCAT22(unaff_SS,&iStack_c),
                             (int *)CONCAT22(unaff_SS,&pcStack_e));
      if (pcStack_e == (char *)0x0) {
        uVar11 = 100;
        uVar10 = 0;
        pcVar5 = litoa10((char *)CONCAT22(iStack_16,unaff_SS),0x640000,auStack_68);
        manage_blitLabelRight((char *)CONCAT22(uVar6,pcVar5),CONCAT11(uVar10,uVar11));
      }
      else {
        uVar11 = 100;
        uVar10 = 0;
        pcVar5 = ovr_stsprintf((char *)CONCAT22(0x52e5,unaff_SS),
                               (char *)CONCAT22(iStack_16,(char *)"puppetmaker" + 3),pcStack_e,
                               auStack_b8,0x10);
        manage_blitLabelRight((char *)CONCAT22(uVar6,pcVar5),CONCAT11(uVar10,uVar11));
      }
      lVar1 = (long)(iVar8 + iVar7) * 6;
      uVar6 = (undefined2)((ulong)lVar1 >> 0x10);
      if (*(char *)((int)&GStructures[0].pad + (int)lVar1) != '\0') {
        if (pcStack_10 == (char *)0x0) {
          uVar11 = 0x8c;
          uVar10 = 0;
          pcVar5 = litoa10((char *)CONCAT22(iStack_8,unaff_SS),0x8c0000,auStack_68);
          manage_blitLabelRight((char *)CONCAT22(uVar6,pcVar5),CONCAT11(uVar10,uVar11));
        }
        else {
          uVar11 = 0x8c;
          uVar10 = 0;
          pcVar5 = ovr_stsprintf((char *)CONCAT22(0x52e5,unaff_SS),
                                 (char *)CONCAT22(iStack_8,(char *)"puppetmaker" + 3),pcStack_10,
                                 auStack_b8,0x10);
          manage_blitLabelRight((char *)CONCAT22(uVar6,pcVar5),CONCAT11(uVar10,uVar11));
        }
        if (pcStack_12 == (char *)0x0) {
          uVar11 = 0xb4;
          uVar10 = 0;
          pcVar5 = litoa10((char *)CONCAT22(iStack_a,unaff_SS),0xb40000,auStack_68);
          manage_blitLabelRight((char *)CONCAT22(uVar6,pcVar5),CONCAT11(uVar10,uVar11));
        }
        else {
          uVar11 = 0xb4;
          uVar10 = 0;
          pcVar5 = ovr_stsprintf((char *)CONCAT22(0x52e5,unaff_SS),
                                 (char *)CONCAT22(iStack_a,(char *)"puppetmaker" + 3),pcStack_12,
                                 auStack_b8,0x10);
          manage_blitLabelRight((char *)CONCAT22(uVar6,pcVar5),CONCAT11(uVar10,uVar11));
        }
        if (pcStack_14 == (char *)0x0) {
          uVar11 = 0xdc;
          uVar10 = 0;
          pcVar5 = litoa10((char *)CONCAT22(iStack_c,unaff_SS),0xdc0000,auStack_68);
          manage_blitLabelRight((char *)CONCAT22(uVar6,pcVar5),CONCAT11(uVar10,uVar11));
        }
        else {
          uVar11 = 0xdc;
          uVar10 = 0;
          pcVar5 = ovr_stsprintf((char *)CONCAT22(0x52e5,unaff_SS),
                                 (char *)CONCAT22(iStack_c,(char *)"puppetmaker" + 3),pcStack_14,
                                 auStack_b8,0x10);
          manage_blitLabelRight((char *)CONCAT22(uVar6,pcVar5),CONCAT11(uVar10,uVar11));
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
  }
  CurSfxType3 = 0x3c;
  entries.seg = 0x23;
  entries.ofs = (uint16_t)unaff_SS;
  uVar6 = ovr_ovc28_usesUiInputText(entries,0,far_from_u32((uint32_t)(ZEXT24(&uStack_18) << 0x10)),&menuItems,0);
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
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  undefined2 uVar7;
  int unaff_BP;
  int iVar8;
  int iVar9;
  uint8_t *unaff_SS;
  undefined2 in_stack_00000000;
  char mode;
  undefined1 uVar10;
  uint8_t *puVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  
  if (((*(char *)(unaff_BP + -0x15) != '\x02') && (*(char *)(unaff_BP + -0x15) != '\x03')) &&
     (*(char *)(unaff_BP + -0x15) != '\x04')) {
    manage_usesCurSfxType3();
    return;
  }
  if (ScreenMode == '\0') {
    manage_openTalkWindow();
  }
  else {
    gfx.seg = 0;
    gfx.ofs = talkwin9Cut1Seg;
    ovr_blitGfxRect(gfx,0,1098,(brect_t *)0x102410,0x0,SUB21(in_stack_00000000,0),talkwin9Cut1Ofs,
                    0x4a,0);
  }
  TextBlitY = 0xc;
  TextBlitX = 0x11;
  if (*(char *)(unaff_BP + 6) == -1) {
    ovr_blitLabel((char *)CONCAT13((char)(Font02.ofs >> 8),CONCAT12((char)Font02.ofs,0x2410)),
                  (uint8_t *)CONCAT22(0xde,Font02.seg),80,(uint8_t)in_stack_00000000,0x5293,0x50);
  }
  else {
    puVar2 = (undefined2 *)((uint)*(byte *)(unaff_BP + 6) * 4);
    pcVar6 = (char *)*puVar2;
    *(undefined2 *)(unaff_BP + -2) = puVar2[1];
    *(undefined2 *)(unaff_BP + -4) = pcVar6;
    uVar12 = 0x50;
    uVar13 = 0;
    uVar7 = 0xde;
    mode = (char)Font02.ofs;
    uVar10 = (undefined1)(Font02.ofs >> 8);
    puVar11 = (uint8_t *)Font02.seg;
    iVar9 = ovr_ovc45_compute9((char *)CONCAT22(*(undefined2 *)(unaff_BP + -4),unaff_SS),
                               (char *)CONCAT22(Font02.ofs,(char *)*(undefined2 *)(unaff_BP + -2)),
                               (char *)CONCAT22(0x69,Font02.seg),3,mode,unaff_BP + -0x66);
    pvVar3 = manage_playerTitle((char_sheet_t *)
                                CONCAT22(iVar9,(char_sheet_t *)*(undefined2 *)(unaff_BP + -2)),
                                *(undefined2 *)(unaff_BP + -4),pcVar6);
    pcVar4 = ovr_stsprintf((char *)CONCAT22(0x52a1,unaff_SS),
                           (char *)CONCAT22(pvVar3,(char *)"puppetmaker" + 3),pcVar6,
                           unaff_BP + -0xb6);
    ovr_blitLabel((char *)CONCAT13(uVar10,CONCAT12(mode,pcVar6)),(uint8_t *)CONCAT22(uVar7,puVar11),
                  CONCAT11(uVar13,uVar12),(uint8_t)in_stack_00000000,pcVar4,uVar12);
  }
  TextBlitY = TextBlitY + 0xc;
  TextBlitX = 0x11;
  ovr_blitLabel((char *)CONCAT13((char)(Font02.ofs >> 8),CONCAT12((char)Font02.ofs,0x2410)),
                (uint8_t *)CONCAT22(0xde,Font02.seg),224,(uint8_t)in_stack_00000000,0x52bd,0xe0);
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
  for (iVar8 = 0; iVar8 < 0xd; iVar8 = iVar8 + 1) {
    if (iVar8 + iVar9 < 0x1e) {
      TextBlitX = 0x11;
      iVar5 = (iVar8 + iVar9) * 6;
      ovr_blitLabel((char *)CONCAT13((char)(Font02.ofs >> 8),
                                     CONCAT12((char)Font02.ofs,
                                              *(undefined2 *)((int)&GStructures[0].name + 2 + iVar5)
                                             )),(uint8_t *)CONCAT22(0xde,Font02.seg),224,
                    (uint8_t)in_stack_00000000,*(undefined2 *)((int)&GStructures[0].name + iVar5),
                    0xe0);
      lVar1 = (long)(iVar8 + iVar9) * 6;
      uVar7 = (undefined2)((ulong)lVar1 >> 0x10);
      iVar5 = manage_usesGUnitCount
                        (*(char *)(unaff_BP + 6),(&((unk01_t *)GStructures)->type)[(int)lVar1],
                         (int *)CONCAT22(unaff_SS,(int *)(unaff_BP + -6)),
                         (int *)CONCAT22(unaff_SS,(int *)(unaff_BP + -8)),
                         (int *)CONCAT22(unaff_SS,(int *)(unaff_BP + -10)),
                         (int *)CONCAT22(unaff_SS,(int *)(unaff_BP + -0xc)));
      *(int *)((code *)init_textFilename + unaff_BP) = iVar5;
      if (*(int *)(unaff_BP + -0xc) == 0) {
        uVar10 = 100;
        uVar12 = 0;
        pcVar6 = litoa10((char *)CONCAT22(*(undefined2 *)((code *)init_textFilename + unaff_BP),
                                          unaff_SS),0x640000,unaff_BP + -0x66);
        manage_blitLabelRight((char *)CONCAT22(uVar7,pcVar6),CONCAT11(uVar12,uVar10));
      }
      else {
        uVar10 = 100;
        uVar12 = 0;
        pcVar6 = ovr_stsprintf((char *)CONCAT22(0x52e5,unaff_SS),
                               (char *)CONCAT22(*(undefined2 *)
                                                 ((code *)init_textFilename + unaff_BP),
                                                (char *)"puppetmaker" + 3),
                               (char *)*(undefined2 *)(unaff_BP + -0xc),unaff_BP + -0xb6,0x10);
        manage_blitLabelRight((char *)CONCAT22(uVar7,pcVar6),CONCAT11(uVar12,uVar10));
      }
      lVar1 = (long)(iVar8 + iVar9) * 6;
      uVar7 = (undefined2)((ulong)lVar1 >> 0x10);
      if (*(char *)((int)&GStructures[0].pad + (int)lVar1) != '\0') {
        if (*(int *)(unaff_BP + -0xe) == 0) {
          uVar10 = 0x8c;
          uVar12 = 0;
          pcVar6 = litoa10((char *)CONCAT22(*(undefined2 *)(unaff_BP + -6),unaff_SS),0x8c0000,
                           unaff_BP + -0x66);
          manage_blitLabelRight((char *)CONCAT22(uVar7,pcVar6),CONCAT11(uVar12,uVar10));
        }
        else {
          uVar10 = 0x8c;
          uVar12 = 0;
          pcVar6 = ovr_stsprintf((char *)CONCAT22(0x52e5,unaff_SS),
                                 (char *)CONCAT22(*(undefined2 *)(unaff_BP + -6),
                                                  (char *)"puppetmaker" + 3),
                                 (char *)*(undefined2 *)(unaff_BP + -0xe),unaff_BP + -0xb6,0x10);
          manage_blitLabelRight((char *)CONCAT22(uVar7,pcVar6),CONCAT11(uVar12,uVar10));
        }
        if (*(int *)(unaff_BP + -0x10) == 0) {
          uVar10 = 0xb4;
          uVar12 = 0;
          pcVar6 = litoa10((char *)CONCAT22(*(undefined2 *)(unaff_BP + -8),unaff_SS),0xb40000,
                           unaff_BP + -0x66);
          manage_blitLabelRight((char *)CONCAT22(uVar7,pcVar6),CONCAT11(uVar12,uVar10));
        }
        else {
          uVar10 = 0xb4;
          uVar12 = 0;
          pcVar6 = ovr_stsprintf((char *)CONCAT22(0x52e5,unaff_SS),
                                 (char *)CONCAT22(*(undefined2 *)(unaff_BP + -8),
                                                  (char *)"puppetmaker" + 3),
                                 (char *)*(undefined2 *)(unaff_BP + -0x10),unaff_BP + -0xb6,0x10);
          manage_blitLabelRight((char *)CONCAT22(uVar7,pcVar6),CONCAT11(uVar12,uVar10));
        }
        if (*(int *)(unaff_BP + -0x12) == 0) {
          uVar10 = 0xdc;
          uVar12 = 0;
          pcVar6 = litoa10((char *)CONCAT22(*(undefined2 *)(unaff_BP + -10),unaff_SS),0xdc0000,
                           unaff_BP + -0x66);
          manage_blitLabelRight((char *)CONCAT22(uVar7,pcVar6),CONCAT11(uVar12,uVar10));
        }
        else {
          uVar10 = 0xdc;
          uVar12 = 0;
          pcVar6 = ovr_stsprintf((char *)CONCAT22(0x52e5,unaff_SS),
                                 (char *)CONCAT22(*(undefined2 *)(unaff_BP + -10),
                                                  (char *)"puppetmaker" + 3),
                                 (char *)*(undefined2 *)(unaff_BP + -0x12),unaff_BP + -0xb6,0x10);
          manage_blitLabelRight((char *)CONCAT22(uVar7,pcVar6),CONCAT11(uVar12,uVar10));
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
  }
  CurSfxType3 = 0x3c;
  entries.seg = 0x23;
  entries.ofs = (uint16_t)unaff_SS;
  uVar7 = ovr_ovc28_usesUiInputText
                    (entries,0,far_from_u32((uint32_t)((ulong)(unaff_BP - 0x16) << 0x10)),
                     (uint8_t *)CONCAT22(in_stack_00000000,unaff_SS),unaff_BP + -0x142,0,
                     (char)unaff_SS);
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
  uint8_t *unaff_SS;
  undefined2 in_stack_00000000;
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
  entries.seg = 0x23;
  entries.ofs = (uint16_t)unaff_SS;
  uVar1 = ovr_ovc28_usesUiInputText
                    (entries,0,far_from_u32((uint32_t)((ulong)(unaff_BP - 0x16) << 0x10)),
                     (uint8_t *)CONCAT22(in_stack_00000000,unaff_SS),unaff_BP + -0x142);
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
  uint uVar1;
  byte unaff_SI;
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
  uVar1 = 0x2410;
  Highlight1 = 0xff;
  if (structType == 0xfe) {
    if (partyIndex == 0xff) {
      ovr_say();
    }
    else {
      ovr_ovc22_className(unaff_SI,CONCAT11(0x24,partyIndex));
      ovr_stsprintf();
      ovr_say();
    }
  }
  else {
    iVar2 = 0;
    while ((iVar2 < 0x1e &&
           (uVar1 = (uint)((unk01_t *)GStructures + iVar2)->type, uVar1 != structType))) {
      iVar2 = iVar2 + 1;
    }
    if (iVar2 != 0x1e) {
      if (partyIndex == 0xff) {
        ovr_stsprintf();
        ovr_say();
      }
      else {
        ovr_ovc22_className(unaff_SI,CONCAT11((char)(uVar1 >> 8),partyIndex));
        ovr_stsprintf((char *)CONCAT22(0x52ed,unaff_SS),
                      (char *)CONCAT22(*(undefined2 *)((int)&GStructures[0].name + iVar2 * 6),
                                       (char *)"puppetmaker" + 3),
                      (char *)*(undefined2 *)((int)&GStructures[0].name + 2 + iVar2 * 6),&msg);
        ovr_say();
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
  undefined1 uVar11;
  byte *pbVar12;
  uint16_t in_DX;
  entity_t *peVar13;
  entity_t *peVar14;
  int iVar15;
  char *pcVar16;
  char *pcVar17;
  undefined2 uVar18;
  undefined2 unaff_ES;
  uint16_t unaff_SS;
  bool bVar19;
  undefined2 in_stack_0000000a;
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
  char cStack_17;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  undefined2 uStack_10;
  char acStack_e [6];
  uint16_t uStack_8;
  undefined1 auStack_6 [2];
  undefined2 uStack_4;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&bandLabels;
  F_SCOPY(far_from_u32((uint32_t)(0x24104b06)),dst);
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&bandLabels2;
  F_SCOPY(far_from_u32((uint32_t)(0x24104b36)),dst_00);
  pbVar12 = (byte *)__C0_ASM_CopyRight + 3;
  dst_01.seg = unaff_SS;
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
  peVar13 = (entity_t *)(auStack_66 + 8);
  uStack_5c = 0x2410;
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 8)) = 0x54ed;
  pcVar17 = (char *)((int)(undefined4 *)&_DATA + 3);
  for (pcVar16 = (char *)0x0; (int)pcVar16 < (int)(uint)(byte)acStack_e[3]; pcVar16 = pcVar16 + 1) {
    if (((int)pcVar16 < 5) || (acStack_e[2] == '\0')) {
      in_DX = *(uint16_t *)(&bandLabels + (int)pcVar16 * 4);
      peVar13 = (entity_t *)(auStack_66 + (int)pcVar17 * 4);
      *(undefined2 *)(auStack_66 + (int)pcVar17 * 4 + 2) = auStack_94[(int)pcVar16 * 2];
      (peVar13->base).x = in_DX;
    }
    else {
      unaff_ES = (undefined2)((ulong)*(undefined4 *)((uint)charIndex << 2) >> 0x10);
      uVar6 = (uint)*(byte *)((int)*(undefined4 *)((uint)charIndex << 2) + 0x2f);
      in_DX = auStack_11a[(int)pcVar16 * 2 + uVar6 * 8];
      peVar13 = (entity_t *)(auStack_66 + (int)pcVar17 * 4);
      *(uint16_t *)(auStack_66 + (int)pcVar17 * 4 + 2) =
           auStack_11a[(int)pcVar16 * 2 + uVar6 * 8 + 1];
      (peVar13->base).x = in_DX;
    }
    pbVar12 = auStack_66;
    pcVar17 = pcVar17 + 1;
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
      uVar6 = ovr_blitLabel();
      *pcVar16 = *pcVar16 + (char)(uVar6 >> 8) + ((undefined1 *)0xfff3 < &stack0xfe3a);
      *(undefined1 *)((int)&(((entity_t *)*(entity_t **)&Entities)->base).entity + uVar6 + 1) = 0;
      uVar18 = (undefined2)((ulong)Entities >> 0x10);
      *(undefined1 *)((int)&((entity_t *)Entities)[(int)pcVar16].base.state + 1) =
           (char)((entity_t *)Entities)[(int)pcVar16].base.flags32;
      if (EntityCount <= pcVar16 + 1) {
        if ((acStack_e[0] != '\0') || (acStack_e[1] != '\0')) {
          if ((*(uint8_t *)((uint8_t *)&(uStack_4) + 1)) == '\0') {
            ovr_stop_audio();
            CurSfxType3 = 0xff;
            ovr_play_sfx();
          }
          else if (acStack_e[1] == '\0') {
            if (acStack_e[0] != '\0') {
              ovr_play_sfx();
            }
          }
          else {
            ovr_play_sfx();
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
      pcVar16 = (char *)"thief" + 5;
      ovr_say();
      return pcVar16;
    }
    uStack_10 = ((undefined2 *)((uint)charIndex * 4))[1];
    iStack_12 = *(undefined2 *)((uint)charIndex * 4);
    ovr_ovc45_compute9();
    func_0x0005d3f4();
    ovr_stsprintf();
    ovr_blitLabel();
    TextBlitY = TextBlitY + 0xc;
    iVar15 = ovr_font_textWidth();
    TextBlitX = 0x89 - iVar15;
    ovr_blitLabel();
    iVar15 = ovr_font_textWidth();
    uVar5 = 0xd4 - iVar15;
    TextBlitX = uVar5;
    ovr_blitLabel();
    iVar15 = 0;
    while( true ) {
      TextBlitY = TextBlitY + 0xc;
      cVar4 = (char)pbVar12;
      if ((int)(uint)(byte)acStack_e[3] <= iVar15) break;
      TextBlitX = 0x11;
      if ((iVar15 < 5) || (acStack_e[2] == '\0')) {
        ovr_blitLabel();
      }
      else {
        ovr_blitLabel();
      }
      func_0x0005f303();
      ovr_stsprintf();
      iVar9 = ovr_font_textWidth();
      TextBlitX = 0x89 - iVar9;
      ovr_blitLabel();
      ovr_stsprintf();
      iVar9 = ovr_font_textWidth();
      uVar5 = 0xd4 - iVar9;
      TextBlitX = uVar5;
      ovr_blitLabel();
      iVar15 = iVar15 + 1;
    }
    CurSfxType3 = 0x3c;
    uVar18 = ovr_ovc28_usesUiInputText();
    acStack_e[1] = (char)uVar18;
    keyboardInputMode = 0;
    if (((acStack_e[1] != '\0') && (acStack_e[1] != '\x01')) && (acStack_e[1] != -2)) {
      (&stack0xbac4)[(int)pcVar17] = (&stack0xbac4)[(int)pcVar17] + cVar4;
      iVar9 = 0x2410;
      do {
        iVar10 = iVar9 * uVar5;
        iVar9 = iVar15;
        if (*(byte *)(iVar15 * 0x34 + 0x22) < *(byte *)(iVar10 + 0x21)) {
          *(undefined1 *)(iVar15 * 0x34 + 0x21) = *(undefined1 *)(iVar15 * 0x34 + 0x22);
        }
        do {
          iVar9 = iVar9 + 1;
          if ((int)(uint)AgntCount <= iVar9) {
            iVar15 = ovr_audio_panFromX();
            uVar11 = (undefined1)((uint)iVar15 >> 8);
            ovr_play_sfxU();
            return (char *)CONCAT11(uVar11,1);
          }
        } while (*(int *)(iVar9 * 0x34 + 0x1b) != *(int *)(sheet->nameText + 0x1b));
        uVar18 = (undefined2)((ulong)_auStack_6 >> 0x10);
        if (*(byte *)((int)_auStack_6 + 0x32) < *(byte *)(iVar9 * 0x34 + 0x22)) {
          *(undefined1 *)(iVar9 * 0x34 + 0x22) = *(undefined1 *)((int)_auStack_6 + 0x32);
        }
        uVar5 = 0x34;
        iVar15 = iVar9;
      } while( true );
    }
    if (acStack_e[1] == -2) {
      Cancelled = 1;
    }
    return (char *)"puppetmaker" + 3;
  }
  do {
    uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
    peVar14 = (entity_t *)peStack_1e;
    (peVar14->base).target =
         (byte)((int)(uint)*(byte *)((int)&(peVar14->base).owner +
                                    ((int)(uint)(peVar13->base).faction >> 2)) >>
               (((peVar14->base).faction & 3) << 1)) & 3;
    cVar4 = func_0x0004f32d();
    peVar13 = (entity_t *)peStack_1e;
    uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
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
    cStack_17 = '\x01';
    uVar6 = ovr_alignUp4();
    uVar7 = ovr_alignUp4();
    if (uVar6 == uVar7) {
      uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
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
        bVar19 = (byte)uStack_4 != -1;
        _auStack_6 = uVar3;
        if (bVar19) {
          for (uVar6 = 0; uVar6 < SquareRecCount; uVar6 = uVar6 + 1) {
            uVar7 = ovr_alignUp4();
            uVar8 = ovr_alignUp4();
            if ((uVar7 == uVar8) &&
               (*(uint16_t *)(uVar6 * 0x13 + 2) == (((entity_t *)peStack_1e)->base).y)) {
              func_0x0004f930();
              if (*(uint16_t *)(uVar6 * 0x13 + 2) == GfxRndSeed2) {
                uVar6 = ovr_alignUp4();
                uVar7 = ovr_alignUp4();
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
            ovr_ovc15_textArena();
          }
          cStack_1a = -1;
        }
        else if (cStack_19 == '\0') {
          cStack_1a = (char)((ulong)((((entity_t *)peStack_1e)->base).animFrame + 0xf) / 0x10);
          while (cStack_1a != '\0') {
            cStack_1a = cStack_1a + -1;
            ovr_agnt_usesAgntCount6();
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
            pcVar16 = ovr_ovc15_textArena();
            if (((uint)pcVar16 & 0xff) == 0) break;
          }
        }
      }
    }
    do {
      pcVar17 = pcVar17 + 1;
      if (EntityCount <= pcVar17) {
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
        ovr_ovc24_removeOtherEntities();
        GGameState = 0x1f;
        if (cStack_17 != '\0') {
          ovr_constr_usesBlitRect();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (iVar15 = 0; iVar15 < 5; iVar15 = iVar15 + 1) {
          if (acStack_e[iVar15] != '\0') {
            ovr_ovc41_usesMiceBlitRect();
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
      peStack_1e = (entity_t *)
                   CONCAT22((int)((ulong)Entities >> 0x10),(entity_t *)Entities + (int)pcVar17);
      uVar6 = ovr_alignUp4();
      uVar7 = ovr_alignUp4();
      if ((uVar6 == uVar7) &&
         (uVar18 = (undefined2)((ulong)peStack_1e >> 0x10),
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
    _iStack_12 = CONCAT13(*(undefined1 *)
                           ((int)(char **)GMenuStrings + (uint)(peVar13->base).gindex * 0x95 + 0x1f)
                          ,_iStack_12);
  } while ((peVar13->base).faction < (byte)(peVar13->base).state);
  uVar18 = ovr_ovc07_signum();
  _iStack_12 = CONCAT22(uStack_10,uVar18);
  iStack_14 = ovr_ovc07_signum();
  if (((iStack_12 == 0) || (uVar5 = ovr_randBelow(), (char)uVar5 == '\0')) ||
     (cVar4 = func_0x0004f412(), cVar4 != '\0')) {
    if ((iStack_14 == 0) || (cVar4 = func_0x0004f412(), cVar4 != '\0')) {
      if ((iStack_12 == 0) || (cVar4 = func_0x0004f412(), cVar4 != '\0')) {
        uVar6 = ovr_ovc26_usesStExit();
        if ((char)uVar6 == '\0') {
          uVar6 = ovr_ovc26_usesRandBelow();
          if (((uVar6 & 0xff) == 0) &&
             (*(char *)((int)(char **)GMenuStrings +
                       (uint)(((entity_t *)peStack_1e)->base).gindex * 0x95 + 0x1f) == '\0')) {
            func_0x0004fb8e();
          }
        }
        else {
          uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
          peVar13 = (entity_t *)peStack_1e;
          (peVar13->base).target =
               (byte)((int)(uint)*(byte *)((int)&(peVar13->base).owner +
                                          ((int)(uint)(peVar13->base).faction >> 2)) >>
                     (((peVar13->base).faction & 3) << 1)) & 3;
          cVar4 = func_0x0004f32d();
          if (cVar4 == '\0') {
            uVar18 = (undefined2)((ulong)peStack_1e >> 0x10);
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

/* WARNING: Variable defined which should be unmapped: msg */
/* Applies a party/type display filter to the unit list and reports which filter is active. */

void __cdecl16far manage_applyUnitFilter(uint8_t partyIndex,uint16_t unitType,char *unitName)

{
  undefined2 uVar1;
  char *unaff_SS;
  uint8_t msg;
  undefined4 uStack_108;
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  unitTypeFilter = (undefined1)unitType;
  partyFilter = partyIndex;
  if (ScreenMode != '\0') {
    uStack_108 = CONCAT22(_msg,0x4d05);
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
      uStack_108 = CONCAT22(_msg,0x2410);
      ovr_say();
    }
    else {
      ovr_ovc22_className(msg,CONCAT11(0x24,partyIndex));
      uVar1 = 0x217a;
      ovr_stsprintf();
      uStack_108 = CONCAT22(_msg,uVar1);
      ovr_say();
    }
  }
  else if (partyIndex == 0xff) {
    uVar1 = uStack_6;
    ovr_stsprintf();
    uStack_108 = CONCAT22(_msg,uVar1);
    ovr_say();
  }
  else {
    ovr_ovc22_className(msg,CONCAT11(0x24,partyIndex));
    uVar1 = 0x217a;
    ovr_stsprintf((char *)CONCAT22(0x557d,unaff_SS),
                  (char *)CONCAT22((char *)unitName,(char *)"puppetmaker" + 3),(*(uint16_t *)((uint8_t *)&(unitName) + 2)),&msg);
    uStack_108 = CONCAT22(_msg,uVar1);
    ovr_say();
  }
  return;
}


