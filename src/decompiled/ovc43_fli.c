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
  far_t *pfVar2;
  char_sheet_t *pcVar3;
  undefined2 in_CX;
  char_sheet_t *pcVar4;
  uint uVar5;
  uint unaff_SI;
  int iVar6;
  int unaff_DI;
  undefined2 uVar7;
  uint16_t uVar8;
  byte in_stack_0000fcf6;
  undefined1 in_stack_0000fcf7;
  byte bStack_8;
  undefined4 uStack_6;
  
  pcVar3 = (char_sheet_t *)((char *)"puppetmaker" + 3);
  TextBlitDstSeg = 0xa000;
  iVar6 = 0;
  while( true ) {
    uVar8 = (uint16_t)(gindex >> 0x10);
    if (*(int *)((int)gindex + 6) <= iVar6) {
      return pcVar3;
    }
    uStack_6 = (char_sheet_t *)CONCAT22(sheetSeg,sheet);
    bStack_8 = (byte)sheetSeg;
    pcVar4 = (char_sheet_t *)(sheet->nameText + 6);
    uVar5 = *(int *)(sheet->nameText + 4) - 0xb;
    if (uVar5 < 6) break;
    pcVar3 = (char_sheet_t *)ovr_lowNibble(sheetSeg,sheet->nameText + *(int *)uStack_6->nameText);
    iVar6 = iVar6 + 1;
    sheet = pcVar3;
    sheetSeg = (uint16_t)pcVar4;
  }
  switch(uVar5) {
  case 0:
    do {
    } while (bStack_8 == 0xff);
    goto code_r0x00061e64;
  case 1:
    pcVar1 = (char *)(uVar5 * 2 + iVar6);
    *pcVar1 = *pcVar1 + (char)pcVar4;
    break;
  case 2:
    goto L_OVC30_619c_0339_03CE;
  case 3:
    goto code_r0x00061d78;
  case 4:
    if (-1 < (int)uVar5) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(sheetSeg,0x21);
    }
    sheetSeg = 0x2410;
code_r0x00061d78:
    if (*(bool *)&GameRunning == false) {
      ovr_fmFreeAudio(unaff_SI,1);
    }
L_OVC30_619c_0339_03CE:
    pcVar3 = ovr_stshAlloc((ulong)unaff_SI << 0x10,0xae);
    uStack_6 = (char_sheet_t *)CONCAT22(pcVar4,pcVar3);
    bStack_8 = GLeaderCount;
    uVar5 = (uint)GLeaderCount;
    ((undefined2 *)(uVar5 * 4))[1] = pcVar4;
    *(undefined2 *)(uVar5 * 4) = pcVar3;
    GLeaderCount = GLeaderCount + 1;
    break;
  case 5:
    pcVar1 = (char *)(uVar5 * 2 + unaff_DI + -0x1ba);
    *pcVar1 = *pcVar1 + (char)in_CX;
    uStack_6 = (char_sheet_t *)CONCAT22(sheetSeg,pcVar4);
  }
  _fmemset((void *)(ulong)(*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),0xae,unaff_SI);
  strcpy(uStack_6->nameText,
         (char *)CONCAT22(*(undefined2 *)
                           ((int)&worldMenuLabels[1].ofs + 1 + (uint)(byte)gindex * 0x95),
                          (char *)*(undefined2 *)
                                   ((int)&worldMenuLabels[0].seg + 1 + (uint)(byte)gindex * 0x95)));
  ((char_sheet_t *)uStack_6)->active = 1;
  ((char_sheet_t *)uStack_6)->x = uVar8;
  ((char_sheet_t *)uStack_6)->y = (uint16_t)sheet;
  ((char_sheet_t *)uStack_6)->classStr = (byte)gindex;
  ((char_sheet_t *)uStack_6)->cls = 0xff;
  ((char_sheet_t *)uStack_6)->race = 3;
  uVar8 = ovr_randBelow(unaff_SI,1);
  ((char_sheet_t *)uStack_6)->gender = (byte)uVar8;
  unaff_SI = (*(uint16_t *)((uint8_t *)&(uStack_6) + 2));
code_r0x00061e64:
  ovr_manage_rollStats
            ((char_sheet_t *)CONCAT13(in_stack_0000fcf7,CONCAT12(in_stack_0000fcf6,unaff_SI)),
             (char_sheet_t *)uStack_6);
  uVar7 = (undefined2)((ulong)uStack_6 >> 0x10);
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
  pfVar2 = ovr_ovc22_textRingProt
                     (in_stack_0000fcf6,CONCAT11((char)((uint)(byte)gindex * 0x95 >> 8),bStack_8));
  return (char_sheet_t *)CONCAT11((char)((uint)pfVar2 >> 8),bStack_8);
}



/* 6fbe:013a */

/* [R4] calls ovr_stExit */

void __cdecl16far ovc43_usesStExit(uint32_t gindex,uint16_t hnd,uint16_t sheetOfs,uint16_t sheetSeg)

{
  int unaff_SI;
  undefined2 unaff_SS;
  bool bVar1;
  uint16_t remainingLo;
  int iStack_10;
  int iStack_e;
  
  ovr_stshRead();
  if (iStack_e != -0xe06) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(unaff_SI,0x46);
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
  int iVar4;
  undefined2 unaff_SI;
  uint unaff_DI;
  uint uVar5;
  int iStack_84;
  int iStack_82;
  char cStack_7;
  int iStack_6;
  ulong *puStack_4;
  
  ovr_stshRead(handle);
  if (iStack_84 != -0x50ef) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(unaff_DI,0x47);
  }
  tempScreenOfs = ovr_stshAlloc((ulong)unaff_DI << 0x10,0xfa0f);
  tempScreenSeg = in_DX;
  ovc43_usesStExit(CONCAT22(paletteSeg,paletteOfs),handle,(uint16_t)tempScreenOfs,in_DX);
  ovr_ovr_miceButton0PressStates_entry();
  puStack_4 = (ulong *)*(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  iVar4 = *(int *)BDA_DailyTimeCounter;
  cStack_7 = '\0';
  iStack_6 = iVar4;
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
      puVar3 = ovr_attact_usesBDADailyTimeCounter(puStack_4,CONCAT22(unaff_SI,unaff_DI),iStack_6);
    } while ((iVar4 == 0) && (iVar4 = 0, puVar3 < (ulong *)(uint)delayTicks));
    puStack_4 = (ulong *)*(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    iVar4 = *(int *)BDA_DailyTimeCounter;
    iStack_6 = iVar4;
L_OVC43_6fbe_01a9_02C7:
    if (cStack_7 != '\0') break;
    ovc43_usesStExit(CONCAT22(paletteSeg,paletteOfs),handle,(uint16_t)tempScreenOfs,tempScreenSeg);
  }
  TextBlitDstSeg = 0xa000;
  handle_00.seg = unaff_DI;
  handle_00.ofs = tempScreenSeg;
  ovr_stshFree(handle_00,tempScreenOfs);
  return cStack_7;
}



/* 6fbe:0322 */

/* Seeks strong.dat to the offset in the given graphic entry and plays it through the frame loop. */

void __cdecl16far
ovc43_playArchiveFli(far_t gfx,uint16_t paletteOfs,uint16_t paletteSeg,uint8_t delayTicks,...)

{
  undefined2 unaff_BP;
  int in_stack_00000004;
  
  ovr_stshSeek(*(uint16_t *)(in_stack_00000004 + 1),
               CONCAT22(unaff_BP,*(undefined2 *)(in_stack_00000004 + 3)),StshStrongDatHnd);
  ovc43_playFliFrames(StshStrongDatHnd,gfx.seg,paletteOfs,(byte)paletteSeg);
  return;
}



/* 6fbe:035f */

/* Plays an archive FLI entry (StshNames[0x184] = strong.fli): opens it, hands the handle to the
   frame loop the palette and frame delay, closes it on exit. */

char __cdecl16far ovc43_playFli(uint16_t fileId,uint16_t paletteOfs,uint16_t paletteSeg,...)

{
  char cVar1;
  uint16_t handle;
  uint16_t unaff_SI;
  undefined2 in_stack_00000004;
  
  handle = ovr_stshOpen(unaff_SI,in_stack_00000004);
  if (*(int *)((char *)"toymaker" + 7 + handle * 2) < 0) {
    cVar1 = '\x01';
  }
  else {
    cVar1 = ovc43_playFliFrames(handle,fileId,paletteOfs,4);
    ovr_stshClose(unaff_SI,handle);
  }
  return cVar1;
}


