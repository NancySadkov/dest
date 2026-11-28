/*
 * ovc43_fli.c - recovered from STRONG.EXE
 * memory block: OVC43_fli.c
 * range: 6fbe:0000 - 6fbe:03ff
 * functions: 5
 */
#include "recovered.h"


/* 6fbe:0000 */
char_sheet_t * __cdecl16far
ovc43_usesFmFreeAudio(uint32_t gindex,char_sheet_t *sheet,uint16_t sheetSeg)

{
  char *statPtrA;          /* &stat byte, from the level-scaled index */
  char *statPtrB;          /* the same, from the class-scaled index */
  uint16_t randVal;         /* ovr_randBelow(1,0) */
  far_t far *protPtr;       /* ovr_ovc22_textRingProt's result */
  char_sheet_t *resultSheet;   /* what the loop returns when it stops */
  char_sheet_t *nextSheet;     /* the sheet the chain step found */
  char_sheet_t *allocSheet;    /* ovr_stshAlloc(0xae)'s result */
  uint16_t in_CX;
  char_sheet_t *pcVar5;
  uint opcode;              /* nameText[4] - 0xb, the record kind */
  uint newLeaderIdx;        /* GLeaderCount before the increment */
  uint16_t unaff_SI;
  int scanIdx;              /* how many records the chain has walked */
  int unaff_DI;
  uint16_t gindexHi;        /* the high word of gindex */
  uint16_t sheetSegHi;      /* the high word of newSheet */
  byte bStack_8;
  char_sheet_t *curSheet;      /* the sheet the chain is walking */
  char_sheet_t *newSheet;      /* the sheet being built */
  
  resultSheet = (char_sheet_t *)((char *)0x2410);
  TextBlitDstSeg = 0xa000;
  scanIdx = 0;
  while( true ) {
    gindexHi = (uint16_t)(gindex >> 0x10);
    if (*(int *)((int)gindex + 6) <= scanIdx) {
      return resultSheet;
    }
    curSheet = (char_sheet_t *)CONCAT22(sheetSeg,sheet);
    bStack_8 = (byte)sheetSeg;
    pcVar5 = (char_sheet_t *)(sheet->nameText + 6);
    opcode = *(int *)(sheet->nameText + 4) - 0xb;
    if (opcode < 6) break;
    nextSheet = (char_sheet_t *)
             ovr_lowNibble((uint)(sheet->nameText + *(int *)curSheet->nameText),sheetSeg);
    scanIdx = scanIdx + 1;
    sheet = nextSheet;
    sheetSeg = (uint16_t)pcVar5;
  }
  switch(opcode) {
  case 0:
    do {
    } while (bStack_8 == 0xff);
    goto code_r0x00061e64;
  case 1:
    statPtrA = (char *)(opcode * 2 + scanIdx);
    *statPtrA = *statPtrA + (char)pcVar5;
    break;
  case 2:
    goto L_OVC30_619c_0339_03CE;
  case 3:
    goto code_r0x00061d78;
  case 4:
    if (-1 < (int)opcode) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x21,sheetSeg);
    }
    sheetSeg = 0x2410;
code_r0x00061d78:
    if (*(bool *)&GameRunning == false) {
      ovr_fmFreeAudio(1);
    }
L_OVC30_619c_0339_03CE:
    allocSheet = ovr_stshAlloc(0xae);
    newSheet = (char_sheet_t *)CONCAT22(pcVar5,allocSheet);
    bStack_8 = GLeaderCount;
    newLeaderIdx = (uint)GLeaderCount;
    ((uint16_t *)(newLeaderIdx * 4))[1] = (uint16_t)pcVar5;   /* hand fix: segment half into a 2-byte slot */
    *(uint16_t *)(newLeaderIdx * 4) = (uint16_t)allocSheet;   /* hand fix: offset half into a 2-byte slot */
    GLeaderCount = GLeaderCount + 1;
    break;
  case 5:
    statPtrB = (char *)(opcode * 2 + unaff_DI + -0x1ba);
    *statPtrB = *statPtrB + (char)in_CX;
    newSheet = (char_sheet_t *)CONCAT22(sheetSeg,pcVar5);
  }
  _fmemset((void *)(ulong)(*(uint16_t *)((uint8_t *)&(newSheet) + 2)),0xae,unaff_SI);
  strcpy(newSheet->nameText,
         (char *)CONCAT22(*(uint16_t *)
                           ((int)&worldMenuLabels[1].ofs + 1 + (uint)(byte)gindex * 0x95),
                          (char *)*(uint16_t *)
                                   ((int)&worldMenuLabels[0].seg + 1 + (uint)(byte)gindex * 0x95)));
  *(undefined1 *)((int)(char_sheet_t *)newSheet + 0x3d) = 1;
  *(uint16_t *)((int)(char_sheet_t *)newSheet + 0x39) = gindexHi;
  *(uint16_t *)((int)(char_sheet_t *)newSheet + 0x3b) = (uint16_t)sheet;   /* hand fix: only the offset half is stored */
  *(byte *)((int)(char_sheet_t *)newSheet + 0x3e) = (byte)gindex;
  *(undefined1 *)((int)(char_sheet_t *)newSheet + 0x2f) = 0xff;
  *(undefined1 *)((int)(char_sheet_t *)newSheet + 0x30) = 3;
  randVal = ovr_randBelow(1,0);
  *(undefined1 *)((int)(char_sheet_t *)newSheet + 0x34) = (char)randVal;
code_r0x00061e64:
  ovr_manage_rollStats((char_sheet_t *)newSheet,0);
  sheetSegHi = (uint16_t)((ulong)newSheet >> 0x10);
  if (*(char *)((int)&worldMenuLabels[0xc].seg + (uint)(byte)gindex * 0x95) != -1) {
    ((char_sheet_t *)newSheet)->stats[1] =
         *(byte *)((int)&worldMenuLabels[0xc].seg + (uint)(byte)gindex * 0x95);
  }
  if ((AgntGs[(uint)(byte)gindex].flags3 & 0x800) != 0) {
    ((char_sheet_t *)newSheet)->stats[4] = 0x12;
  }
  ((char_sheet_t *)newSheet)->faction =
       AgntGs[(uint)(byte)gindex].ai;
  ((char_sheet_t *)newSheet)->alignment =
       *(byte *)((int)(far_t far *)(worldMenuLabels + 9) + (uint)(byte)gindex * 0x95);
  ((char_sheet_t *)newSheet)->hp[0] =
       AgntGs[(uint)(byte)gindex].strength;
  ((char_sheet_t *)newSheet)->hp[1] = ((char_sheet_t *)newSheet)->hp[0];
  ((char_sheet_t *)newSheet)->statMask = ((char_sheet_t *)newSheet)->statMask | 0x16;
  ((char_sheet_t *)newSheet)->spyReports = 0x1;
  *(uint16_t *)((int)&((char_sheet_t *)newSheet)->gold + 2) = 0;
  *(uint16_t *)&((char_sheet_t *)newSheet)->gold = 100;
  ((char_sheet_t *)newSheet)->partySlot = 0xff;
  protPtr = ovr_ovc22_textRingProt(bStack_8);
  return (char_sheet_t *)CONCAT11((char)((uint)protPtr >> 8),bStack_8);
}


/* 6fbe:013a */

/* [R4] calls ovr_stExit */

void __cdecl16far ovc43_usesStExit(uint32_t gindex,uint16_t hnd,uint16_t sheetOfs,uint16_t sheetSeg)

{
  bool bVar1;
  uint16_t remainingLo;
  int remainingHi;
  int iStack_e;
  
  ovr_stshRead();
  if (iStack_e != -0xe06) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x46);
  }
  bVar1 = remainingLo < 0x10;
  remainingLo = remainingLo - 0x10;
  remainingHi = remainingHi - (uint)bVar1;
  if (remainingLo != 0 || remainingHi != 0) {
    ovr_stshRead();
    ovc43_usesFmFreeAudio
              ((uint32_t)CONCAT22(_SS,&remainingLo),(char_sheet_t *)sheetOfs,sheetSeg);
  }
  return;
}



/* 6fbe:01a9 */
char __cdecl16far
ovc43_playFliFrames(uint16_t handle,uint16_t paletteOfs,uint16_t paletteSeg,byte delayTicks)

{
  far_t handle_00;
  uint16_t keyAvail;       /* ovr_biosKeyAvail's result */
  uint16_t keyCode;        /* ovr_gameProcessKey's result */
  uint mouseRes;            /* ovr_init2_updateMouseButtons' result */
  ulong *elapsed;           /* ovr_attact_usesBDADailyTimeCounter's result */
  uint16_t in_DX;
  ulong *tickPtr;           /* the BDA daily tick counter */
  uint16_t diArg;           /* the value the image leaves in DI */
  uint frameIdx;            /* the frame being played */
  int readHdr;              /* the header word ovr_stshRead leaves */
  int frameCount;           /* how many frames the header declares */
  char exitCode;            /* 0 none, 1 confirm, 2 escape */
  ulong *puStack_6;
  uint16_t tickHi;          /* the tick counter's high word */
  
  ovr_stshRead();
  if (readHdr != -0x50ef) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x47);
  }
  {
    void far *p = ovr_stshAlloc(0xfa0f);
    tempScreenOfs = ST_OFF(p);
    tempScreenSeg = ST_SEG(p);
  }
  ovc43_usesStExit(CONCAT22(paletteSeg,paletteOfs),handle,tempScreenOfs,tempScreenSeg);
  ovr_ovr_miceButton0PressStates_entry();
  tickHi = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  tickPtr = *(ulong * far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);   /* hand fix: the offset half is the address, not the far_t struct */
  exitCode = '\0';
  puStack_6 = tickPtr;
  for (frameIdx = 0; frameIdx < frameCount - 1U; frameIdx = frameIdx + 1) {
    do {
      keyAvail = ovr_biosKeyAvail();
      if ((char)keyAvail != '\0') {
        keyCode = ovr_gameProcessKey();
        if (keyCode == 0x11b) {
          exitCode = '\x02';
        }
        if (keyCode == 0x1c0d) {
          exitCode = '\x01';
        }
      }
      mouseRes = ovr_init2_updateMouseButtons();
      if (((mouseRes != 0) || (rightButtonLatch != '\0')) &&
         (exitCode = '\x01', rightButtonLatch != '\0')) {
        exitCode = '\x02';
      }
      if (exitCode != '\0') goto L_OVC43_6fbe_01a9_02C7;
      elapsed = ovr_attact_usesBDADailyTimeCounter(puStack_6,CONCAT22(diArg,tickHi),0);
    } while ((tickPtr == (ulong *)0x0) && (tickPtr = (ulong *)0x0, elapsed < (ulong *)(uint)delayTicks)
            );
    tickHi = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    tickPtr = *(ulong * far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);   /* hand fix: the offset half is the address, not the far_t struct */
    puStack_6 = tickPtr;
L_OVC43_6fbe_01a9_02C7:
    if (exitCode != '\0') break;
    ovc43_usesStExit(CONCAT22(paletteSeg,paletteOfs),handle,(uint16_t)tempScreenOfs,tempScreenSeg);
  }
  TextBlitDstSeg = 0xa000;
  handle_00.seg = tempScreenSeg;
  handle_00.ofs = (uint16_t)tempScreenOfs;
  ovr_stshFree(handle_00);
  return exitCode;
}


/* 6fbe:0322 */

/* Seeks strong.dat to the offset in the given graphic entry and plays it through the frame loop. */

void __cdecl16far
ovc43_playArchiveFli(far_t gfx,uint16_t paletteOfs,uint16_t paletteSeg,uint8_t delayTicks)

{
  ovr_stshSeek(StshStrongDatHnd,CONCAT22(*(uint16_t *)(gfx.ofs + 3),*(uint16_t *)(gfx.ofs + 1)))
  ;
  ovc43_playFliFrames(StshStrongDatHnd,paletteOfs,paletteSeg,delayTicks);
  return;
}



/* 6fbe:035f */

/* Plays an archive FLI entry (StshNames[0x184] = strong.fli): opens it, hands the handle to the
   frame loop the palette and frame delay, closes it on exit. */

char __cdecl16far ovc43_playFli(uint16_t fileId,uint16_t paletteOfs,uint16_t paletteSeg)

{
  char cVar1;
  uint16_t handle;
  
  handle = ovr_stshOpen(fileId);
  if (*(int *)((char *)0x2420 + handle * 2) < 0) {
    cVar1 = '\x01';
  }
  else {
    cVar1 = ovc43_playFliFrames(handle,paletteOfs,paletteSeg,4);
    ovr_stshClose(handle);
  }
  return cVar1;
}


