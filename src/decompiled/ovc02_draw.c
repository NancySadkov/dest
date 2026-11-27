/*
 * ovc02_draw.c - recovered from STRONG.EXE
 * memory block: OVC02_draw.c
 * range: 2e25:0000 - 2e25:207f
 * functions: 23
 */
#include "recovered.h"


/* 2e25:0000 */

/* Draws the enabled menu row's proportional bar in the two special colours. */

void __cdecl16far draw_menuRowBar(int menuItem,uint16_t dstSeg)

{
  uint uVar1;
  uint y1;
  
  if ((menuItem < 5) && (((uint8_t *)MenuItemEnabled)[menuItem] != 0xff)) {
    uVar1 = ovr_attact_usesLDIV_at_((uint8_t)menuItem);
    uVar1 = ((uVar1 & 0xff) * 0x17) / 0x51;
    y1 = menuItem * 0xd + 0x91;
    if (uVar1 != 0) {
      ovr_driver_fillRect(0x124,y1,uVar1 + 0x123,y1,SpecialColors[6],dstSeg,0,0,0,0,0);
    }
    if (uVar1 < 0x16) {
      ovr_driver_fillRect(uVar1 + 0x124,y1,0x139,y1,SpecialColors[7],dstSeg,0,0,0,0,0);
    }
  }
  return;
}



/* 2e25:0098 */

/* [R4] calls ovr_driver_fillRect */

void __cdecl16far draw_usesFillRect2(uint value,int dstSeg)

{
  int iVar1;
  uint uVar2;
  uint uStack_4;
  
  if (GMenuItem < 5) {
    if (dstSeg == -0x6000) {
      draw_usesBlitLoadRleGfx2();
    }
    uStack_4 = ovr_attact_countPartyUnits(GMenuItem);
    iVar1 = ovr_ovc23_findClearColumn(GfxRndSeed,GfxRndSeed2);
    if (iVar1 < 0) {
      uStack_4 = 0;
    }
    if ((int)value < 0) {
      value = 0;
    }
    else if (uStack_4 < value) {
      value = uStack_4;
    }
    ((uint8_t *)menuItemRow)[GMenuItem] = (uint8_t)value;
    uVar2 = ovr_attact_usesLDIV_at_(GMenuItem);
    uVar2 = uVar2 & 0xff;
    if (uVar2 != 0) {
      ovr_driver_fillRect(0xea,0x6d,uVar2 + 0xe9,0x6f,SpecialColors[6],dstSeg,0,0,0,0,0);
    }
    if (uVar2 < 0x50) {
      ovr_driver_fillRect(uVar2 + 0xea,0x6d,0x139,0x6f,SpecialColors[7],dstSeg,0,0,0,0,0);
    }
    draw_menuRowBar((uint)GMenuItem,dstSeg);
  }
  return;
}



/* 2e25:018a */

/* [R7] body shape: compute */

int __cdecl16far draw_compute1(int menuIndex)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ((char)((undefined *)&menuCursorY)[menuIndex] * 0x12) / 0x39;
  iVar2 = ((char)((undefined *)&menuCursorX)[menuIndex] * 0x12) / 0x39;
  if ((iVar2 < 9) || (iVar2 + -8 <= iVar1)) {
    if ((iVar2 < 8) && (iVar1 < 8 - iVar2)) {
      iVar2 = iVar2 + 1;
    }
  }
  else {
    iVar2 = iVar2 + -1;
  }
  return iVar2 + 0x124;
}



/* 2e25:01eb */

/* [R7] body shape: compute */

int __cdecl16far draw_compute2(int menuIndex)

{
  return *(int *)(menuIndex * 2 + 0xda) +
         ((char)((undefined *)&menuCursorY)[menuIndex] * 0x12) / 0x39;
}



/* 2e25:0217 */

/* [R6] touches CrossBlitX, CrossBlitY */

void __cdecl16far draw_usesCrossBlitX(void)

{
  CrossBlitX = (uint)crossAgentIndex * 0x34 + 0x26;
  CrossBlitY = *(int *)(((uint)crossAgentIndex * 0x34 + 0x1a) * 2 + 0x34c) + -0xf;
  return;
}



/* 2e25:0245 */

/* [R7] body shape: compute */

uint __cdecl16far draw_compute3(int x)

{
  return (uint)((0x13f - x) * 0x80) / 0x140;
}



/* 2e25:025a */

/* Place and capture the nine-slice talk window for the current menu item, then blit its frame.
   Re-derived from the image: with MenuMode 1 and GMenuItem 5 the position follows bigcompFrame
   (0x108/0x46, 0x10c/0x49, 0x108/0x4d, 0x103/0x49 for cases 0/2/4/6; the odd cases leave it alone);
   with MenuMode 1 and a real item it follows menuCursorX/menuCursorY; with MenuMode 2 it is
   (0x128,0x73) for item 5 and (attact_usesLDIV_at_(item)+0xe4, 0x68) otherwise; any other mode uses
   draw_compute1/draw_compute2 minus 6/5.  The window is captured from 0xa000:0000 with stshRleCut
   (six words), then blitted from CrossBlitGfx; the open sound plays unless the mouse just moved. */
void __cdecl16far draw_textTalkwin9Lbm(void)

{
  far_t dst;
  uint16_t resultSeg;

  if (GameRunning != false) {
    return;
  }
  CrossBlitFlag = 0;
  CrossBlitCount2 = 0;
  CrossBlitCount = 1;
  if (CrossBlitPtr.seg != 0 || CrossBlitPtr.ofs != 0) {
    ovr_stshFree(CrossBlitPtr);
  }
  CrossBlitPtr.seg = 0;
  CrossBlitPtr.ofs = 0;
  if (MenuMode == 1) {
    if (GMenuItem == 5) {
      switch (bigcompFrame) {
      case 0:
        CrossBlitX = 0x108;
        CrossBlitY = 0x46;
        break;
      case 2:
        CrossBlitX = 0x10c;
        CrossBlitY = 0x49;
        break;
      case 4:
        CrossBlitX = 0x108;
        CrossBlitY = 0x4d;
        break;
      case 6:
        CrossBlitX = 0x103;
        CrossBlitY = 0x49;
        break;
      }
    }
    else if (GMenuItem < 5) {
      CrossBlitX = (char)((undefined *)&menuCursorX)[GMenuItem] + 0xed;
      CrossBlitY = (char)((undefined *)&menuCursorY)[GMenuItem] + 0x3b - 5;
    }
  }
  else if (MenuMode == 2) {
    if (GMenuItem == 5) {
      CrossBlitX = 0x128;
      CrossBlitY = 0x73;
    }
    else {
      CrossBlitX = ovr_attact_usesLDIV_at_(GMenuItem) + 0xe4;
      CrossBlitY = 0x68;
    }
  }
  else if (GMenuItem == 5) {
    CrossBlitX = 0x128;
    CrossBlitY = 0x73;
  }
  else if (GMenuItem < 5) {
    CrossBlitX = draw_compute1(GMenuItem) - 6;
    CrossBlitY = draw_compute2(GMenuItem) - 5;
  }
  if (CrossBlitFlag == 0) {
    CrossBlitPtr.ofs =
         (uint16_t)ovr_stshRleCut(0,0xa000,CrossBlitX,CrossBlitY,CrossBlitX + 0xd,CrossBlitY + 9);
    asm { mov resultSeg,dx };
    CrossBlitPtr.seg = resultSeg;
    dst.seg = 0xa000;
    dst.ofs = CrossBlitY * 0x140 + CrossBlitX;
    ovr_blitLoadRleGfx(CrossBlitGfx,dst);
  }
  if (MouseMoved == 0) {
    ovr_play_sfxU(0,1,draw_compute3(CrossBlitX));
  }
  return;
}


/* 2e25:046b */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far draw_usesBlitLoadRleGfx(void)

{
  far_t gfx;
  far_t dst;
  far_t dst_00;
  brect_t rect;
  
  if (CrossBlitFlag == '\0') {
    if ((((CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0) &&
         (CrossBlitCount2 = CrossBlitCount2 + 1, 2 < CrossBlitCount2)) &&
        (CrossBlitCount2 = 0, CrossBlitCount != 0)) && (CrossBlitCount < 5)) {
      rect.x = CrossBlitX;
      rect.y = CrossBlitY;
      rect.w = CrossBlitX + *(int far *)((uint8_t far *)MK_FP(CrossBlitPtr.seg, CrossBlitPtr.ofs) +  5) + -1;
      rect.h = CrossBlitY + *(int far *)((uint8_t far *)MK_FP(CrossBlitPtr.seg, CrossBlitPtr.ofs) +  7) + -1;
      rect.seg = 0xa000;
      ovr_miceRestoreArea(&rect,0);
      dst.seg = 0xa000;
      dst.ofs = CrossBlitX + CrossBlitY * 0x140;
      ovr_blitLoadRleGfx(CrossBlitPtr,dst,0);
      if (CrossBlitCount < 4) {
        dst_00.seg = 0xa000;
        dst_00.ofs = CrossBlitX + CrossBlitY * 0x140;
        gfx.seg = *(uint16_t *)((int)&CrossBlitGfx.seg + (uint)CrossBlitCount * 4);
        gfx.ofs = ((far_t *)&CrossBlitGfx + CrossBlitCount)->ofs;
        ovr_blitLoadRleGfx(gfx,dst_00,0);
      }
      ovr_miceBlitRect(&rect,0);
      CrossBlitCount = CrossBlitCount + 1;
    }
  }
  return;
}



/* 2e25:0573 */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far draw_usesBlitLoadRleGfx2(void)

{
  far_t gfx;
  far_t dst;
  far_t handle;
  
  if ((CrossBlitCount != '\0') && (CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0)) {
    CrossBlitCount = '\0';
    dst.seg = 0xa000;
    dst.ofs = CrossBlitX + CrossBlitY * 0x140;
    gfx.seg = CrossBlitPtr.seg;
    gfx.ofs = CrossBlitPtr.ofs;
    ovr_blitLoadRleGfx(gfx,dst,0);
    handle.seg = CrossBlitPtr.seg;
    handle.ofs = CrossBlitPtr.ofs;
    ovr_stshFree(handle);
    CrossBlitPtr.seg = 0;
    CrossBlitPtr.ofs = 0;
  }
  return;
}



/* 2e25:05e9 */
void __cdecl16far draw_usesPlay_sfx(void)

{
  char *pcVar1;
  char cVar2;
  uint16_t x;
  ulong *puVar3;
  uint uVar4;
  uint16_t uVar5;
  uint uVar6;
  word count;
  int in_DX;
  uint16_t unaff_SI;
  uint rec;
  ulong prevTick;
  uint16_t outFlag;
  agnt_t far *in_stack_0000fffa;
  byte col;
  
  prevTick = CONCAT22(unaff_SI,(*(uint16_t *)((uint8_t *)&(recordUpdateTick) + 2)));
  puVar3 = ovr_attact_usesBDADailyTimeCounter((ulong *)recordUpdateTick,prevTick,0);
  if ((in_DX != 0) || ((ulong *)((int)(uint32_t *)&_DATA + 1U) < puVar3)) {
    (*(uint16_t *)((uint8_t *)&(recordUpdateTick) + 2)) = (uint16_t)*(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    (*(uint16_t *)((uint8_t *)&(recordUpdateTick))) = (uint16_t)*(ulong * far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
    outFlag = 0;
    for (rec = 0; uVar6 = (uint)(prevTick >> 0x10), rec < GRecordCount; rec = rec + 1) {
      GRecords[rec].buildTimer = GRecords[rec].buildTimer + 1;
      if (20000 < GRecords[rec].buildTimer) {
        GRecords[rec].buildTimer = (uint16_t)0x14;
      }
      cVar2 = GRecords[rec].state;
      if (cVar2 == '\0') {
        uVar4 = GRecords[rec].frame + 1;
        prevTick = CONCAT22(uVar6,uVar4);
        if ((uVar4 < GRecords[rec].frameCount) && (0x13 < GRecords[rec].buildTimer)) {
          GRecords[rec].buildTimer = (uint16_t)0;
          pcVar1 = (char *)&GRecords[rec].frame;
          *pcVar1 = *pcVar1 + '\x01';
        }
      }
      else if (cVar2 == '\x01') {
        uVar4 = GRecords[rec].frame + 1;
        prevTick = CONCAT22(uVar6,uVar4);
        if (uVar4 < GRecords[rec].frameCount) {
          if (0x13 < GRecords[rec].buildTimer) {
            GRecords[rec].buildTimer = (uint16_t)0;
            pcVar1 = (char *)&GRecords[rec].frame;
            *pcVar1 = *pcVar1 + '\x01';
          }
        }
        else {
          GRecords[rec].state = 2;
          x = GRecords[rec].x;
          in_stack_0000fffa = (agnt_t far *)GRecords[rec].y;
          uVar5 = ovr_ovc23_isCursorAt(x,(int)in_stack_0000fffa,0);
          if (((char)uVar5 != '\0') && (GRecords[rec].reserved08 != '\0')) {
            ovr_play_sfx(80,0,0);
          }
          col = (byte)x;
          uVar5 = ovr_ovc22_usesGOngoingBattle(col,(byte)in_stack_0000fffa);
          if ((char)uVar5 != '\0') {
            outFlag = CONCAT11(1,(char)outFlag);
          }
          prevTick = (ulong)uVar6 << 0x10;
          uVar6 = ovr_ovc23_compute1(x,(int)in_stack_0000fffa,GRecords[rec].reserved08,
                                     GRecords[rec].party);
          if ((uVar6 & 0xff) == 0) {
            prevTick = prevTick & 0xffff0000;
            ovr_ovc23_placeBuilding
                      (x,(int)in_stack_0000fffa,GRecords[rec].reserved08,
                       GRecords[rec].party);
          }
          GRecords[rec].buildTimer = (uint16_t)0;
        }
      }
      else if ((cVar2 == '\x02') && (9 < GRecords[rec].buildTimer)) {
        if (rec + 1 < GRecordCount) {
          count = ((GRecordCount - rec) + -1) * 0x12;
          prevTick = CONCAT22(uVar6,count);
          _fmemmove((char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[rec], buildTimer, 0)),
                    (char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[rec + 1], buildTimer, 0)),count);
          rec = rec - 1;
        }
        GRecordCount = GRecordCount - 1;
        outFlag = CONCAT11((char)(outFlag >> 8),1);
      }
    }
    if ((char)outFlag != '\0') {
      ovr_ovc23_textAdlibNone(uVar6,outFlag,in_stack_0000fffa);
    }
    if ((char)(outFlag >> 8) != '\0') {
      ovr_constr_flushDirtyRects();
    }
  }
  return;
}


/* 2e25:0938 */

/* [R4] calls printf */

void __cdecl16far draw_usesPrintf(void)

{
  bool bVar1;
  ulong *puVar2;
  int in_DX;
  uint16_t unaff_BP;
  
  MiceUnkState = 1;
  DrawBusy = 1;
  GGameState = 1;
  if (DebugVerbose) {
    printf("%d \r",GGameState);
  }
  draw_usesBlitLoadRleGfx();
  GGameState = 2;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  ovr_agnt_usesAlignToSeg();
  if ((timePassing != '\0') ||
     (((GPaused == '\0' || ((bVar1 = ovr_ovc15_usesAlignUp42(), bVar1 && (GOngoingBattle == '\0'))))
      && ((puVar2 = ovr_attact_usesBDADailyTimeCounter
                              ((ulong *)GDailyTimeCounter,CONCAT22(unaff_BP,(*(uint16_t *)((uint8_t *)&(GDailyTimeCounter) + 2))),0), in_DX != 0 ||
          ((char *)0x2415a < puVar2)))))) {
    ovr_attact_usesUpdSeason();
  }
  if (GGameInProgress == '\0') {
    GGameState = 4;
    if (DebugVerbose != false) {
      printf("%d \r",GGameState);
    }
    ovr_ovc13_usesMiceBlitRect();
    GGameState = 6;
    if (DebugVerbose != false) {
      printf("%d \r",GGameState);
    }
    draw_usesPlay_sfx();
    GGameState = 8;
    if (DebugVerbose != false) {
      printf("%d \r",GGameState);
    }
    if (strongholdCheckPending != '\0') {
      ovr_ovc24_checkStrongholds();
    }
  }
  DrawBusy = 0;
  return;
}



/* 2e25:0ad1 */

/* [R4] calls ovr_resetTextBlitCycle */

void __cdecl16far draw_usesResetTextBlitCycle(void)

{
  draw_usesBlitLoadRleGfx2();
  ovr_resetTextBlitCycle();
  return;
}



/* 2e25:0adf */

uint16_t __cdecl16far gameProcessKey(void)

{
  uint16_t key;
  uint16_t uVar1;
  char *msgPtr;
  undefined1 in_DL;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  
  key = ovr_biosReadKey();
  if (key == 0x320d) {
    if (AudioAssetsReady2 != '\0') {
      ovr_stop_audio();
    }
    AudioAssetsReady2 = '\x01' - (AudioAssetsReady2 != '\0');
  }
  else if (key == 0x1f13) {
    if (AudioAssetsReady1 != '\0') {
      ovr_stop_audio();
    }
    AudioAssetsReady1 = '\x01' - (AudioAssetsReady1 != '\0');
  }
  else if (GDebug != false) {
    if (key == 0x1000) {
      ovr_ovc30_usesRandBelow2(GfxRndSeed,GfxRndSeed2,(char)GfxRndSeed2);
    }
    else if ((key == 0x1300) && (VideoFlag_2410_0167 == 0)) {
      VideoFlag_2410_0167 = 1;
      ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
      ovr_ovc40_usesAlignToSeg
                ('\0',(char *)"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",0x2410,(char *)"Archduchess",0x2410,0,0,0,0,0);
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
      VideoFlag_2410_0167 = 0;
    }
    else if (key == 0x1500) {
      ovr_ovc41_usesPlay_sfxU();
    }
    else if ((key == 0x1900) && (VideoFlag_2410_0167 == 0)) {
      VideoFlag_2410_0167 = 1;
      ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
      uVar1 = ovr_randBelow(2,0);
      ovr_season_textHalflingCastle((uint8_t)uVar1);
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
      VideoFlag_2410_0167 = 0;
    }
    else if (key == 0x1f00) {
      GTimeHi = 1;
    }
    else if (key == 0x2000) {
      DebugVerbose = (bool)('\x01' - (DebugVerbose != false));
    }
    else if (key == 0x2100) {
      ovr_ovc41_buildingNotice('\n');
    }
    else if (key == 0x2200) {
      destroyLatchSide0 = 1;
    }
    else if (key == 0x2300) {
      msgPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x286,_SS),
                             (char *)CONCAT22(GSeed,(char *)0x26510),(char)SeedHi);
      ovr_say(msgPtr,in_DL);
    }
    else if (key == 0x2400) {
      ovr_constrct_usesGLeaderCount();
    }
    else if (key == 0x2500) {
      destroyLatchSide1 = 1;
    }
    else if (key == 0x2600) {
      GCharLevelsInc = GCharLevelsInc + '\x01';
      msgPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x297,_SS),
                             (char *)(ulong)CONCAT12(GCharLevelsInc,0x2410));
      ovr_say(msgPtr,in_DL);
    }
    else if (key == 0x2c00) {
      ovr_ovc41_usesAgntCount3();
    }
    else if (key == 0x2e00) {
      ovr_dbgPromoteEnemy();
    }
    else if (key == 0x3000) {
      ovr_ovc41_buildingNotice('\x01');
    }
    else if (key == 0x3200) {
      ovr_ovc20_textLenLoc();
    }
  }
  return key;
}



/* 2e25:0d35 */
uint16_t __cdecl16far draw_usesGameProcessKey(void)

{
  bool firstPass;
  int startX;
  int startY;
  byte miceResult;
  uint16_t keyAvail;
  uint16_t key;
  uint16_t drainKey;
  undefined1 extraout_AH;
  int lastCounterLo;
  int lastCounterHi;
  
  lastCounterHi = -1;
  lastCounterLo = -1;
  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x2410);
  startY = MouseY;
  startX = MouseX;
  firstPass = false;
  MouseMoved = 0;
  while( true ) {
    if ((*(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != lastCounterHi) ||
       (*(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) != lastCounterLo)) {
      lastCounterHi = *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
      lastCounterLo = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
      draw_usesPrintf();
      if (GGameInProgress != '\0') {
        ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
        draw_usesResetTextBlitCycle();
        return 0;
      }
    }
    keyAvail = ovr_biosKeyAvail();
    if ((char)keyAvail != '\0') break;
    miceResult = ovr_init2_usesCFGMice((uint16_t *)&MouseX,(uint16_t *)&MouseY,0x2410);
    if (CONCAT11(extraout_AH,miceResult) == 0) {
      firstPass = true;
    }
    else if (((firstPass) || (startX != MouseX)) || (startY != MouseY)) {
      if (!firstPass) {
        MouseMoved = 1;
      }
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
      MouseBkgPixel = *(undefined1 *)(MouseY * 0x140 + MouseX);
      draw_usesResetTextBlitCycle();
      GGameState = 0x36;
      if (DebugVerbose != false) {
        printf("%d \r",GGameState);
      }
      return 0xffff;
    }
  }
  GGameState = 0x3b;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
  draw_usesResetTextBlitCycle();
  key = gameProcessKey();
  while (drainKey = ovr_biosKeyAvail(), (char)drainKey != '\0') {
    key = gameProcessKey();
  }
  GGameState = 0x35;
  if (DebugVerbose == false) {
    GGameState = 0x35;
    return key;
  }
  printf("%d \r",GGameState);
  return key;
}


/* 2e25:0efd */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far draw_usesBlitLoadRleGfx3(int menuIndex)

{
  int row1;
  byte y1;
  int iVar1;
  uint8_t *ofs2;
  uint y1_00;
  byte y2;
  far_t gfx;
  far_t dst;
  
  if (((uint8_t *)MenuItemEnabled)[menuIndex] != 0xff) {
    row1 = *(int *)(menuIndex * 2 + 0xda);
    dst.seg = TextBlitDstSeg;
    dst.ofs = row1 * 0x140 + 0x124;
    gfx.seg = panel01Cut1Seg;
    gfx.ofs = panel01Cut1Ofs;
    ovr_blitLoadRleGfx(gfx,dst,0);
    iVar1 = draw_compute1(menuIndex);
    ofs2 = (uint8_t *)(iVar1 + 2);
    y1_00 = draw_compute2(menuIndex);
    y1 = (byte)row1;
    y2 = (byte)y1_00;
    ovr_driver_compute5(0x12e,y1,(uint16_t)ofs2,y2,0x126,y1 + 8,(uint)SpecialColors[0],0);
    ovr_driver_compute5(0x12e,y1,(uint16_t)ofs2,y2,0x136,y1 + 8,(uint)SpecialColors[1],0);
    ovr_driver_compute5((uint16_t)ofs2,y2,0x126,y1 + 8,0x136,y1 + 8,(uint)SpecialColors[2],0);
    ovr_driver_drawLine((uint8_t *)((int)&GUnitDescriptions[0x10].seg + 1),row1,ofs2,y1_00,SpecialColors[3],0,0,0,0);
    ovr_driver_drawLine(ofs2,y1_00,(uint8_t *)((int)&GUnitDescriptions[0x12].seg + 1),row1 + 8,SpecialColors[4],0,0,0,0);
    ovr_driver_drawLine((uint8_t *)((int)&GUnitDescriptions[0xe].seg + 1),row1 + 8,ofs2,y1_00,SpecialColors[5],0,0,0,0);
    ovr_driver_fillRect((uint)ofs2,y1_00,(uint)ofs2,y1_00,0x6c,TextBlitDstSeg,0,0,0,0,0);
    draw_menuRowBar((uint)GMenuItem,TextBlitDstSeg);
  }
  return;
}



/* 2e25:10c7 */

/* Clamps and stores the menu cursor offset and draws the selection indicator lines. */

void __cdecl16far draw_menuCursor(int x,int y)

{
  if (x < 0) {
    x = 0;
  }
  if (y < 0) {
    y = 0;
  }
  if (0x38 < x) {
    x = 0x38;
  }
  if (0x1c < y) {
    y = 0x1c;
  }
  if ((x < 0x1d) || (x + -0x1c <= y)) {
    if ((x < 0x1c) && (y < 0x1c - x)) {
      x = (int)(char)((undefined *)&menuCursorX)[GMenuItem];
      y = (int)(char)((undefined *)&menuCursorY)[GMenuItem];
    }
  }
  else {
    x = (int)(char)((undefined *)&menuCursorX)[GMenuItem];
    y = (int)(char)((undefined *)&menuCursorY)[GMenuItem];
  }
  ((undefined *)&menuCursorX)[GMenuItem] = (undefined1)x;
  ((undefined *)&menuCursorY)[GMenuItem] = (char)y;
  ovr_driver_compute5(0x10f,0x3b,x + 0xf3,(char)y + 0x3b,0xf3,0x57,(uint)SpecialColors[0],
                      TextBlitDstSeg);
  ovr_driver_compute5(0x10f,0x3b,x + 0xf3,(char)y + 0x3b,299,0x57,(uint)SpecialColors[1],
                      TextBlitDstSeg);
  ovr_driver_compute5(x + 0xf3,(char)y + 0x3b,0xf3,0x57,299,0x57,(uint)SpecialColors[2],
                      TextBlitDstSeg);
  ovr_driver_drawLine((uint8_t *)(far_t *)(GUnitDescriptions + 9),0x3b,(uint8_t *)(x + 0xf3),y + 0x3b,SpecialColors[3],TextBlitDstSeg,0,0,0);
  ovr_driver_drawLine((uint8_t *)(x + 0xf3),y + 0x3b,(uint8_t *)(far_t *)(GUnitDescriptions + 0x10),0x57,SpecialColors[4],TextBlitDstSeg,0,0,0);
  ovr_driver_drawLine((uint8_t *)(x + 0xf3),y + 0x3b,(uint8_t *)(far_t *)(GUnitDescriptions + 2),0x57,SpecialColors[5],TextBlitDstSeg,0,0,0);
  ovr_driver_fillRect(x + 0xf3,y + 0x3b,x + 0xf3,y + 0x3b,0x6c,TextBlitDstSeg,0,0,0,0,0);
  draw_usesBlitLoadRleGfx3((uint)GMenuItem);
  return;
}



/* 2e25:130a */

/* Blits the Build/Recruit/Train/Movement labels at their fixed toolbar positions. */

void __cdecl16far draw_toolbarLabels(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  void *blitBuf;
  uint16_t *menuEntry;
  char *text;
  uint16_t in_DX;
  uint16_t segWord;
  byte *textOfs;
  uint16_t seg;
  uint8_t term;
  far_t ptr;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  far_t handle;
  char textBuf [44];
  
  if (!GameRunning) {
    blitBuf = ovr_stshAlloc(0xfa0f);
    ptr.seg = in_DX;
    ptr.ofs = (uint16_t)blitBuf;
    segWord = in_DX;
    ovr_alignToSeg(ptr);
    dst.seg = segWord;
    dst.ofs = 0x4826;
    gfx.seg = nwpanel1Cut1Seg;
    gfx.ofs = nwpanel1Cut1Ofs;
    TextBlitDstSeg = segWord;
    ovr_blitLoadRleGfx(gfx,dst,0);
    if (GMenuItem == 5) {
      dst_00.seg = TextBlitDstSeg;
      dst_00.ofs = 0x4975;
      gfx_00.seg = *(uint16_t *)((int)&LbmBigcomp50x42.seg + (uint)bigcompFrame * 4);
      gfx_00.ofs = ((far_t *)&LbmBigcomp50x42 + bigcompFrame)->ofs;
      ovr_blitLoadRleGfx(gfx_00,dst_00,0);
      TextBlitX = 0xea;
      TextBlitY = 0x62;
      ovr_blitText((char *)"Movement",(byte *)CONCAT22(Font03.ofs,(char *)0x26510),
                   Font03.seg,0x3f);
    }
    else if ((GMenuItem < 5) && (((uint8_t *)MenuItemEnabled)[GMenuItem] != 0xff)) {
      dst_01.seg = TextBlitDstSeg;
      dst_01.ofs = 0x482a;
      gfx_01.seg = trianglsCut1Seg;
      gfx_01.ofs = trianglsCut1Ofs;
      ovr_blitLoadRleGfx(gfx_01,dst_01,0);
      TextBlitX = 0xe6;
      TextBlitY = 0x3e;
      ovr_blitText((char *)"Recruit",(byte *)CONCAT22(Font02.ofs,(char *)0x26510),
                   Font02.seg,0x3f);
      TextBlitX = 0x11e;
      TextBlitY = 0x3e;
      ovr_blitText((char *)"Train",(byte *)CONCAT22(Font02.ofs,(char *)0x26510),Font02.seg
                   ,0x3f);
      TextBlitX = 0x104;
      TextBlitY = 0x5b;
      ovr_blitText((char *)"Build",(byte *)CONCAT22(Font02.ofs,(char *)0x26510),Font02.seg
                   ,0x3f);
      TextBlitX = 0xea;
      TextBlitY = 0x62;
      term = 0x3f;
      menuEntry = (uint16_t *)((uint)((uint8_t *)MenuItemEnabled)[GMenuItem] * 4);
      textOfs = (byte *)((char *)0x2627a);
      segWord = Font03.ofs;
      seg = Font03.seg;
      text = (char *)ovr_ovc45_compute9(textBuf,(char *)CONCAT22(*menuEntry,_SS),
                                        (char *)CONCAT22(Font03.ofs,(char *)menuEntry[1]),Font03.seg,
                                        'T',3);
      ovr_blitText(text,(byte *)CONCAT22(segWord,textOfs),seg,term);
      draw_menuCursor((int)(char)((undefined *)&menuCursorX)[GMenuItem],
                      (int)(char)((undefined *)&menuCursorY)[GMenuItem]);
      draw_usesFillRect2((uint)((uint8_t *)menuItemRow)[GMenuItem],TextBlitDstSeg);
    }
    ovr_blitRaw(0xe6,0x39,0x13a,0x71,TextBlitDstSeg,0xa000);
    TextBlitDstSeg = 0xa000;
    handle.seg = in_DX;
    handle.ofs = (uint16_t)blitBuf;
    ovr_stshFree(handle);
  }
  return;
}



/* 2e25:15d6 */

/* [R2] string "arena" */

bool __cdecl16far draw_textArena(void)

{
  bool bVar1;
  int iVar2;
  
  if (DebugVerbose) {
    bVar1 = true;
  }
  else if (CurPartySlot == '\0') {
    bVar1 = true;
  }
  else if ((CurPartySlot == '\x01') && (PartyCount != '\0')) {
    bVar1 = true;
  }
  else {
    for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
      if ((((short (*) [60] [148])GMapFlags)[-1][GfxRndSeed2 + 0x3b][GfxRndSeed + iVar2 + 0x92] & 8U
          ) != 0) {
        return true;
      }
    }
    bVar1 = false;
  }
  return bVar1;
}



/* 2e25:1662 */

/* Frees the audioSaveCut1/2 ring buffers, clears their handles and cleans the ring buffer. */

void __cdecl16far draw_freeRingBuffers(void)

{
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  
  if (audioSaveCut1Ofs != 0 || audioSaveCut1Seg != 0) {
    handle.seg = audioSaveCut1Seg;
    handle.ofs = audioSaveCut1Ofs;
    ovr_stshFree(handle);
  }
  audioSaveCut1Seg = 0;
  audioSaveCut1Ofs = 0;
  if (audioSaveCut2Ofs != 0 || audioSaveCut2Seg != 0) {
    handle_00.seg = audioSaveCut2Seg;
    handle_00.ofs = audioSaveCut2Ofs;
    ovr_stshFree(handle_00);
  }
  audioSaveCut2Seg = 0;
  audioSaveCut2Ofs = 0;
  if (upperTextOfs != (byte *)0x0 || upperTextSeg != 0) {
    handle_01.seg = upperTextSeg;
    handle_01.ofs = (uint16_t)upperTextOfs;
    ovr_stshFree(handle_01);
  }
  upperTextSeg = 0;
  upperTextOfs = (byte *)0x0;
  ovr_clean_ring_buffer();
  if (CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0) {
    handle_02.seg = CrossBlitPtr.seg;
    handle_02.ofs = CrossBlitPtr.ofs;
    ovr_stshFree(handle_02);
  }
  CrossBlitPtr.seg = 0;
  CrossBlitPtr.ofs = 0;
  ovr_clearMiceProcessed();
  return;
}



/* 2e25:1759 */

/* [R7] body shape: compute */

uint16_t __cdecl16far draw_compute4(byte type)

{
  if (type != 0x37) {
    if (type < 0x38) {
      if (type != 0x1e) {
        if (type < 0x1f) {
          if (((type != 9) && (type != 0xe)) && (type != 0x1c)) {
            return 0;
          }
        }
        else if ((type != 0x1f) && (type != 0x20)) {
          return 0;
        }
      }
    }
    else if (type != 0x44) {
      if (type < 0x45) {
        if ((type != 0x38) && (type != 0x39)) {
          return 0;
        }
      }
      else if ((type != 0x45) && (type != 0x55)) {
        return 0;
      }
    }
  }
  return 1;
}



/* 2e25:17b3 */

/* [R4] calls ovr_toggle_pause */

void __cdecl16far draw_usesToggle_pause(void)

{
  bool ok;
  uint16_t value;
  uint menuRow;
  uint menuCol;
  uint16_t hit;
  int dstSeg;
  uint menuRow2;
  char choice;
  byte menuItem;
  
  GGameState = 0x36;
  if (DebugVerbose) {
    printf("%d \r",GGameState);
  }
  if ((((MouseX < 0xc) || (0xde < MouseX)) || (MouseY < 7)) ||
     ((0x96 < MouseY || (MouseMoved != 0)))) {
    if ((MouseMoved == 0) &&
       ((((0xde < MouseX && (MouseX < 0xee)) && ((7 < MouseY && (MouseY < 0x33)))) ||
        ((((GOngoingBattle != '\0' && (0xee < MouseX)) && (MouseX < 0x135)) &&
         (((6 < MouseY && (MouseY < 0x37)) && (ok = draw_textArena(), ok)))))))) {
      ovr_ovc41_cannotSeeTerrainNotice();
    }
    else if ((((MouseMoved != 0) || (MouseX < 0xef)) ||
             ((0x134 < MouseX || ((MouseY < 7 || (0x36 < MouseY)))))) ||
            ((GOngoingBattle != '\0' && (ok = draw_textArena(), ok)))) {
      if ((((MouseX < 9) || (0x18 < MouseX)) || (MouseY < 0xb5)) ||
         ((0xc4 < MouseY || (MouseMoved != 0)))) {
        if ((((trianglesShown == '\0') || ((MouseX < 10 || (0x16 < MouseX)))) || (MouseY < 0x9e)) ||
           ((0xaa < MouseY || (MouseMoved != 0)))) {
          if ((GMenuItem == 5) &&
             ((((0xf4 < MouseX && (0x39 < MouseY)) && (MouseX < 0x128)) &&
              ((MouseY < 0x65 && (hit = draw_compute4(MouseBkgPixel), (char)hit != '\0')))))) {
            choice = '\0';
            MenuMode = '\x01';
            if ((int)(MouseX - 0xf5) <= (int)(MouseY - 0x36)) {
              choice = '\x02';
            }
            if ((int)(0x2e - (MouseY - 0x3a)) < (int)(MouseX - 0xf5)) {
              if (choice == '\0') {
                choice = '\x01';
              }
            }
            else if (choice == '\x02') {
              choice = '\x03';
            }
            ovr_ovc41_usesBiosKeyAvail(choice,0);
            draw_textTalkwin9Lbm();
          }
          else if (((GMenuItem < 5) &&
                   (((0xf2 < MouseX && (MouseX < 300)) && ((MouseY < 0x58 && (0x3a < MouseY)))))) &&
                  (((MouseX < 0x110 && (0x10f - MouseX <= MouseY - 0x3b)) ||
                   ((0x10f < MouseX && (MouseX - 0x10f <= MouseY - 0x3b)))))) {
            draw_menuCursor(MouseX - 0xf3,MouseY - 0x3b);
            MenuMode = '\x01';
            draw_textTalkwin9Lbm();
            ovr_ovc41_unitStatusText(GMenuItem);
          }
          else if ((((MouseX < 0xea) || (0x13a < MouseX)) || (MouseY < 0x6d)) ||
                  ((0x6f < MouseY || (4 < GMenuItem)))) {
            if (((0x123 < MouseX) && ((MouseX < 0x139 && (0x85 < MouseY)))) && (MouseY < 200)) {
              menuCol = (MouseY - 0x86) % 0xd;
              if ((menuCol < 9) &&
                 ((((MouseX < 0x12f && (0x12e - MouseX <= menuCol)) ||
                   ((0x12e < MouseX && (MouseX - 0x12e <= menuCol)))) &&
                  ((menuRow = (MouseY - 0x86) / 0xd, menuRow < 5 &&
                   (((uint8_t *)MenuItemEnabled)[menuRow] != 0xff)))))) {
                menuItem = (byte)menuRow;
                if (GMenuItem != menuRow) {
                  GMenuItem = menuItem;
                  MenuMode = 1;
                  draw_toolbarLabels();
                  ovr_ovc41_unitStatusText(GMenuItem);
                  draw_textTalkwin9Lbm();
                  return;
                }
                if (GOngoingBattle != '\0') {
                  ovr_ui_textDefineRegionCommand(menuItem);
                  return;
                }
                MenuMode = 1;
                draw_toolbarLabels();
                draw_textTalkwin9Lbm();
                ovr_ovc41_unitStatusText(GMenuItem);
                return;
              }
              if (menuRow2 == 0xb) {
                menuRow2 = (MouseY - 0x86) / 0xd;
                if (((uint8_t *)MenuItemEnabled)[menuRow2] == 0xff) {
                  return;
                }
                menuItem = (byte)menuRow2;
                GMenuItem = menuItem;
                MenuMode = 2;
                draw_toolbarLabels();
                draw_textTalkwin9Lbm();
                ovr_attact_updateAttractEntry((uint)GMenuItem,1);
                return;
              }
            }
            if ((((MouseX < 0xea) || (0x123 < MouseX)) || (MouseY < 0x86)) ||
               (((199 < MouseY || (menuRow2 = (MouseY - 0x86) / 0xd, 8 < (MouseY - 0x86) % 0xd)) ||
                ((4 < menuRow2 || (((uint8_t *)MenuItemEnabled)[menuRow2] == 0xff)))))) {
              if (((MouseX < 0x125) || (0x137 < MouseX)) ||
                 ((MouseY < 0x72 ||
                  (((0x82 < MouseY || (MouseMoved != 0)) ||
                   (hit = draw_compute4(MouseBkgPixel), (char)hit == '\0')))))) {
                if (((MouseMoved == 0) && (0xea < MouseX)) &&
                   ((MouseX < 0x115 && ((0x73 < MouseY && (MouseY < 0x80)))))) {
                  ovr_toggle_pause();
                  draw_toolbarLabels();
                }
              }
              else {
                GMenuItem = 5;
                MenuMode = '\x01';
                draw_toolbarLabels();
                draw_textTalkwin9Lbm();
              }
            }
            else {
              ovr_manage_showSettlementScreen(((uint8_t *)MenuItemEnabled)[menuRow2]);
            }
          }
          else {
            dstSeg = -0x6000;
            value = ovr_attact_textAbnormalProgramTermination(MouseX - 0xea,GMenuItem);
            draw_usesFillRect2(value,dstSeg);
            if (MenuMode == '\x02') {
              ovr_attact_updateAttractEntry((uint)GMenuItem,0);
            }
            else {
              ovr_attact_updateAttractEntry((uint)GMenuItem,1);
            }
            MenuMode = '\x02';
            draw_textTalkwin9Lbm();
          }
        }
        else {
          ovr_manage_textHalflingCastle();
        }
      }
      else {
        ovr_attact_usesAgntFlag1();
        ovr_uiMainMenu();
      }
    }
    else {
      ovr_ovc13_usesBlitLoadRleGfx3(MouseX - 0xef >> 1,MouseY - 7,'\0');
    }
  }
  else if (GOngoingBattle == '\0') {
    ok = ovr_stats_selectAgentAt(MouseX - 0xc,MouseY - 7);
    if (!ok) {
      ovr_ovc45_showLandInfo(MouseX - 0xc,MouseY - 7);
    }
  }
  else {
    ovr_ovc13_usesBlitLoadRleGfx2(MouseX - 0xc >> 1,MouseY - 7,'\0');
  }
  return;
}



/* 2e25:1d7c */

/* [R2] string "%s: provides more housing." */

bool __cdecl16far draw_textProvidesMoreHousing(void)

{
  undefined1 uVar1;
  uint16_t uVar2;
  
  uVar2 = ovr_miceButtonsStates();
  if ((uVar2 & 1) == 0) {
    if ((uVar2 & 2) == 0) {
      uVar2 = ovr_biosKeyAvail();
      if ((char)uVar2 != '\0') {
        uVar2 = gameProcessKey();
        if (uVar2 == 0x11b) {
          return true;
        }
        if (uVar2 == 0x1c0d) {
          return true;
        }
      }
      ovr_audio_usesLDIV_at_();
      uVar1 = 0;
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  return (bool)uVar1;
}





