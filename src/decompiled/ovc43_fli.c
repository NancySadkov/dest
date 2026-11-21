/*
 * ovc43_fli.c - recovered from STRONG.EXE
 * memory block: OVC43_fli.c
 * range: 6fbe:0000 - 6fbe:03ff
 * functions: 5
 */
#include "recovered.h"


/* 6fbe:0000 */

/* WARNING: Instruction at (ram,0x00061dad) overlaps instruction at (ram,0x00061dac)
    */
/* [R4] calls ovr_fmFreeAudio */

char_sheet_t * __cdecl16far
ovc43_usesFmFreeAudio(uint32_t gindex,char_sheet_t *sheet,uint16_t sheetSeg)

{
  char *pcVar1;
  uint16_t uVar2;
  far_t *pfVar3;
  char_sheet_t *pcVar4;
  undefined2 in_CX;
  char_sheet_t *pcVar5;
  uint uVar6;
  uint16_t unaff_SI;
  int iVar7;
  int unaff_DI;
  undefined2 uVar8;
  byte bStack_8;
  undefined4 uStack_6;
  
  pcVar4 = (char_sheet_t *)((char *)"puppetmaker" + 3);
  TextBlitDstSeg = 0xa000;
  iVar7 = 0;
  while( true ) {
    uVar8 = (undefined2)(gindex >> 0x10);
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
    ((undefined2 *)(uVar6 * 4))[1] = pcVar5;
    *(undefined2 *)(uVar6 * 4) = pcVar4;
    GLeaderCount = GLeaderCount + 1;
    break;
  case 5:
    pcVar1 = (char *)(uVar6 * 2 + unaff_DI + -0x1ba);
    *pcVar1 = *pcVar1 + (char)in_CX;
    uStack_6 = (char_sheet_t *)CONCAT22(sheetSeg,pcVar5);
  }
  _fmemset((void *)(ulong)(*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),0xae,unaff_SI);
  strcpy(uStack_6->nameText,
         (char *)CONCAT22(*(undefined2 *)
                           ((int)&worldMenuLabels[1].ofs + 1 + (uint)(byte)gindex * 0x95),
                          (char *)*(undefined2 *)
                                   ((int)&worldMenuLabels[0].seg + 1 + (uint)(byte)gindex * 0x95)));
  *(undefined1 *)((int)(char_sheet_t *)uStack_6 + 0x3d) = 1;
  *(undefined2 *)((int)(char_sheet_t *)uStack_6 + 0x39) = uVar8;
  *(undefined2 *)((int)(char_sheet_t *)uStack_6 + 0x3b) = sheet;
  *(byte *)((int)(char_sheet_t *)uStack_6 + 0x3e) = (byte)gindex;
  *(undefined1 *)((int)(char_sheet_t *)uStack_6 + 0x2f) = 0xff;
  *(undefined1 *)((int)(char_sheet_t *)uStack_6 + 0x30) = 3;
  uVar2 = ovr_randBelow(1);
  *(undefined1 *)((int)(char_sheet_t *)uStack_6 + 0x34) = (char)uVar2;
code_r0x00061e64:
  ovr_manage_rollStats((char_sheet_t *)uStack_6);
  uVar8 = (undefined2)((ulong)uStack_6 >> 0x10);
  if (*(char *)((int)&worldMenuLabels[0xc].seg + (uint)(byte)gindex * 0x95) != -1) {
    ((char_sheet_t *)uStack_6)->stats[1] =
         *(byte *)((int)&worldMenuLabels[0xc].seg + (uint)(byte)gindex * 0x95);
  }
  if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)(byte)gindex * 0x95) & 0x800) != 0) {
    ((char_sheet_t *)uStack_6)->stats[4] = 0x12;
  }
  ((char_sheet_t *)uStack_6)->faction =
       *(uint8_t *)((int)(char **)GMenuStrings + (uint)(byte)gindex * 0x95 + 0x1f);
  ((char_sheet_t *)uStack_6)->alignment =
       *(byte *)((int)(far_t *)(worldMenuLabels + 9) + (uint)(byte)gindex * 0x95);
  ((char_sheet_t *)uStack_6)->hp[0] =
       *(byte *)((int)&worldMenuLabels[6].seg + (uint)(byte)gindex * 0x95);
  ((char_sheet_t *)uStack_6)->hp[1] = ((char_sheet_t *)uStack_6)->hp[0];
  ((char_sheet_t *)uStack_6)->statMask = ((char_sheet_t *)uStack_6)->statMask | 0x16;
  ((char_sheet_t *)uStack_6)->spyReports = 0x1;
  *(undefined2 *)((int)&((char_sheet_t *)uStack_6)->gold + 2) = 0;
  *(undefined2 *)&((char_sheet_t *)uStack_6)->gold = 100;
  ((char_sheet_t *)uStack_6)->partySlot = 0xff;
  pfVar3 = ovr_ovc22_textRingProt(bStack_8);
  return (char_sheet_t *)CONCAT11((char)((uint)pfVar3 >> 8),bStack_8);
}



/* 6fbe:013a */

/* [R4] calls ovr_stExit */

void __cdecl16far ovc43_usesStExit(uint32_t gindex,uint16_t hnd,uint16_t sheetOfs,uint16_t sheetSeg)

{
  undefined2 unaff_SS;
  bool bVar1;
  uint16_t remainingLo;
  int iStack_10;
  int iStack_e;
  
  ovr_stshRead();
  if (iStack_e != -0xe06) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x46);
  }
  bVar1 = remainingLo < 0x10;
  remainingLo = remainingLo - 0x10;
  iStack_10 = iStack_10 - (uint)bVar1;
  if (remainingLo != 0 || iStack_10 != 0) {
    ovr_stshRead();
    ovc43_usesFmFreeAudio
              ((uint32_t)CONCAT22(unaff_SS,&remainingLo),(char_sheet_t *)sheetOfs,sheetSeg);
  }
  return;
}



/* 6fbe:01a9 */

/* Plays FLI frames from an already-open handle: allocates a 320x200 frame buffer, presents one
   frame per iteration with the given palette, delays param_4 ticks, and returns 1 (ENTER/mouse) or
   2 (ESC). */

char __cdecl16far
ovc43_playFliFrames(uint16_t handle,uint16_t paletteOfs,uint16_t paletteSeg,byte delayTicks)

{
  far_t handle_00;
  uint16_t uVar1;
  uint uVar2;
  ulong *puVar3;
  uint16_t in_DX;
  ulong *puVar4;
  undefined2 unaff_DI;
  uint uVar5;
  int iStack_84;
  int iStack_82;
  char cStack_7;
  ulong *puStack_6;
  undefined2 uStack_4;
  
  ovr_stshRead();
  if (iStack_84 != -0x50ef) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x47);
  }
  tempScreenOfs = ovr_stshAlloc(0xfa0f);
  tempScreenSeg = in_DX;
  ovc43_usesStExit(CONCAT22(paletteSeg,paletteOfs),handle,(uint16_t)tempScreenOfs,in_DX);
  ovr_ovr_miceButton0PressStates_entry();
  uStack_4 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  puVar4 = *(ulong **)BDA_DailyTimeCounter;
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
      puVar3 = ovr_attact_usesBDADailyTimeCounter(puStack_6,CONCAT22(unaff_DI,uStack_4));
    } while ((puVar4 == (ulong *)0x0) && (puVar4 = (ulong *)0x0, puVar3 < (ulong *)(uint)delayTicks)
            );
    uStack_4 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    puVar4 = *(ulong **)BDA_DailyTimeCounter;
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
ovc43_playArchiveFli(far_t gfx,uint16_t paletteOfs,uint16_t paletteSeg,uint8_t delayTicks,...)

{
  ovr_stshSeek(StshStrongDatHnd,CONCAT22(*(undefined2 *)(gfx.ofs + 3),*(undefined2 *)(gfx.ofs + 1)))
  ;
  ovc43_playFliFrames(StshStrongDatHnd,paletteOfs,paletteSeg,delayTicks);
  return;
}



/* 6fbe:035f */

/* Plays an archive FLI entry (StshNames[0x184] = strong.fli): opens it, hands the handle to the
   frame loop the palette and frame delay, closes it on exit. */

char __cdecl16far ovc43_playFli(uint16_t fileId,uint16_t paletteOfs,uint16_t paletteSeg,...)

{
  char cVar1;
  uint16_t handle;
  
  handle = ovr_stshOpen(fileId);
  if (*(int *)((char *)0x2a9d6 + handle * 2) < 0) {
    cVar1 = '\x01';
  }
  else {
    cVar1 = ovc43_playFliFrames(handle,paletteOfs,paletteSeg,4);
    ovr_stshClose(handle);
  }
  return cVar1;
}


