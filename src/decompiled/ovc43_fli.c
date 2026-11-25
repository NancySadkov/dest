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
  char *pcVar1;
  uint16_t uVar2;
  far_t far *pfVar3;
  char_sheet_t *pcVar4;
  uint16_t in_CX;
  char_sheet_t *pcVar5;
  uint uVar6;
  uint16_t unaff_SI;
  int iVar7;
  int unaff_DI;
  uint16_t uVar8;
  byte bStack_8;
  char_sheet_t *uStack_6;   /* hand fix: used as uStack_6->nameText and (char_sheet_t *)uStack_6 */
  
  pcVar4 = (char_sheet_t *)((char *)0x2410);
  TextBlitDstSeg = 0xa000;
  iVar7 = 0;
  while( true ) {
    uVar8 = (uint16_t)(gindex >> 0x10);
    if (*(int *)((int)gindex + 6) <= iVar7) {
      return pcVar4;
    }
    uStack_6 = (char_sheet_t *)CONCAT22(sheetSeg,sheet);
    bStack_8 = (byte)sheetSeg;
    pcVar5 = (char_sheet_t *)(sheet->nameText + 6);
    uVar6 = *(int *)(sheet->nameText + 4) - 0xb;
    if (uVar6 < 6) break;
    pcVar4 = (char_sheet_t *)
             ovr_lowNibble((uint)(sheet->nameText + *(int *)uStack_6->nameText),sheetSeg);
    iVar7 = iVar7 + 1;
    sheet = pcVar4;
    sheetSeg = (uint16_t)pcVar5;
  }
  switch(uVar6) {
  case 0:
    do {
    } while (bStack_8 == 0xff);
    goto code_r0x00061e64;
  case 1:
    pcVar1 = (char *)(uVar6 * 2 + iVar7);
    *pcVar1 = *pcVar1 + (char)pcVar5;
    break;
  case 2:
    goto L_OVC30_619c_0339_03CE;
  case 3:
    goto code_r0x00061d78;
  case 4:
    if (-1 < (int)uVar6) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x21,sheetSeg);
    }
    sheetSeg = 0x2410;
code_r0x00061d78:
    if (*(bool *)&GameRunning == false) {
      ovr_fmFreeAudio(1);
    }
L_OVC30_619c_0339_03CE:
    pcVar4 = ovr_stshAlloc(0xae);
    uStack_6 = (char_sheet_t *)CONCAT22(pcVar5,pcVar4);
    bStack_8 = GLeaderCount;
    uVar6 = (uint)GLeaderCount;
    ((uint16_t *)(uVar6 * 4))[1] = (uint16_t)pcVar5;   /* hand fix: segment half into a 2-byte slot */
    *(uint16_t *)(uVar6 * 4) = (uint16_t)pcVar4;   /* hand fix: offset half into a 2-byte slot */
    GLeaderCount = GLeaderCount + 1;
    break;
  case 5:
    pcVar1 = (char *)(uVar6 * 2 + unaff_DI + -0x1ba);
    *pcVar1 = *pcVar1 + (char)in_CX;
    uStack_6 = (char_sheet_t *)CONCAT22(sheetSeg,pcVar5);
  }
  _fmemset((void *)(ulong)(*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),0xae,unaff_SI);
  strcpy(uStack_6->nameText,
         (char *)CONCAT22(*(uint16_t *)
                           ((int)&worldMenuLabels[1].ofs + 1 + (uint)(byte)gindex * 0x95),
                          (char *)*(uint16_t *)
                                   ((int)&worldMenuLabels[0].seg + 1 + (uint)(byte)gindex * 0x95)));
  *(undefined1 *)((int)(char_sheet_t *)uStack_6 + 0x3d) = 1;
  *(uint16_t *)((int)(char_sheet_t *)uStack_6 + 0x39) = uVar8;
  *(uint16_t *)((int)(char_sheet_t *)uStack_6 + 0x3b) = (uint16_t)sheet;   /* hand fix: only the offset half is stored */
  *(byte *)((int)(char_sheet_t *)uStack_6 + 0x3e) = (byte)gindex;
  *(undefined1 *)((int)(char_sheet_t *)uStack_6 + 0x2f) = 0xff;
  *(undefined1 *)((int)(char_sheet_t *)uStack_6 + 0x30) = 3;
  uVar2 = ovr_randBelow(1,0);
  *(undefined1 *)((int)(char_sheet_t *)uStack_6 + 0x34) = (char)uVar2;
code_r0x00061e64:
  ovr_manage_rollStats((char_sheet_t *)uStack_6,0);
  uVar8 = (uint16_t)((ulong)uStack_6 >> 0x10);
  if (*(char *)((int)&worldMenuLabels[0xc].seg + (uint)(byte)gindex * 0x95) != -1) {
    ((char_sheet_t *)uStack_6)->stats[1] =
         *(byte *)((int)&worldMenuLabels[0xc].seg + (uint)(byte)gindex * 0x95);
  }
  if ((AgntGs[(uint)(byte)gindex].flags3 & 0x800) != 0) {
    ((char_sheet_t *)uStack_6)->stats[4] = 0x12;
  }
  ((char_sheet_t *)uStack_6)->faction =
       AgntGs[(uint)(byte)gindex].ai;
  ((char_sheet_t *)uStack_6)->alignment =
       *(byte *)((int)(far_t far *)(worldMenuLabels + 9) + (uint)(byte)gindex * 0x95);
  ((char_sheet_t *)uStack_6)->hp[0] =
       AgntGs[(uint)(byte)gindex].strength;
  ((char_sheet_t *)uStack_6)->hp[1] = ((char_sheet_t *)uStack_6)->hp[0];
  ((char_sheet_t *)uStack_6)->statMask = ((char_sheet_t *)uStack_6)->statMask | 0x16;
  ((char_sheet_t *)uStack_6)->spyReports = 0x1;
  *(uint16_t *)((int)&((char_sheet_t *)uStack_6)->gold + 2) = 0;
  *(uint16_t *)&((char_sheet_t *)uStack_6)->gold = 100;
  ((char_sheet_t *)uStack_6)->partySlot = 0xff;
  pfVar3 = ovr_ovc22_textRingProt(bStack_8);
  return (char_sheet_t *)CONCAT11((char)((uint)pfVar3 >> 8),bStack_8);
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
  uint16_t uVar1;
  uint uVar2;
  ulong *puVar3;
  uint16_t in_DX;
  ulong *puVar4;
  uint16_t unaff_DI;
  uint uVar5;
  int iStack_84;
  int iStack_82;
  char cStack_7;
  ulong *puStack_6;
  uint16_t uStack_4;
  
  ovr_stshRead();
  if (iStack_84 != -0x50ef) {
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
  uStack_4 = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  puVar4 = *(ulong * far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);   /* hand fix: the offset half is the address, not the far_t struct */
  cStack_7 = '\0';
  puStack_6 = puVar4;
  for (uVar5 = 0; uVar5 < iStack_82 - 1U; uVar5 = uVar5 + 1) {
    do {
      uVar1 = ovr_biosKeyAvail();
      if ((char)uVar1 != '\0') {
        uVar1 = ovr_gameProcessKey();
        if (uVar1 == 0x11b) {
          cStack_7 = '\x02';
        }
        if (uVar1 == 0x1c0d) {
          cStack_7 = '\x01';
        }
      }
      uVar2 = ovr_init2_updateMouseButtons();
      if (((uVar2 != 0) || (rightButtonLatch != '\0')) &&
         (cStack_7 = '\x01', rightButtonLatch != '\0')) {
        cStack_7 = '\x02';
      }
      if (cStack_7 != '\0') goto L_OVC43_6fbe_01a9_02C7;
      puVar3 = ovr_attact_usesBDADailyTimeCounter(puStack_6,CONCAT22(unaff_DI,uStack_4),0);
    } while ((puVar4 == (ulong *)0x0) && (puVar4 = (ulong *)0x0, puVar3 < (ulong *)(uint)delayTicks)
            );
    uStack_4 = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    puVar4 = *(ulong * far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);   /* hand fix: the offset half is the address, not the far_t struct */
    puStack_6 = puVar4;
L_OVC43_6fbe_01a9_02C7:
    if (cStack_7 != '\0') break;
    ovc43_usesStExit(CONCAT22(paletteSeg,paletteOfs),handle,(uint16_t)tempScreenOfs,tempScreenSeg);
  }
  TextBlitDstSeg = 0xa000;
  handle_00.seg = tempScreenSeg;
  handle_00.ofs = (uint16_t)tempScreenOfs;
  ovr_stshFree(handle_00);
  return cStack_7;
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


