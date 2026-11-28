/*
 * ovc19_save.c - recovered from STRONG.EXE
 * memory block: OVC19_save.c
 * range: 49fd:0000 - 49fd:10cf
 * functions: 8
 */
#include "recovered.h"


/* 49fd:0000 */

/* Reads exactly `count` bytes from the save handle, returning success. */

int __cdecl16far save_readBlock(int handle,void *buf,uint16_t bufSeg,uint count)

{
  uint16_t in_AX;
  int iVar1;
  byte bVar2;
  uint unaff_SI;
  int in_stack_00000004;
  
  if ((*(uint16_t *)((uint8_t *)&(buf) + 2)) == 0) {
    iVar1 = CONCAT11((char)((uint)in_AX >> 8),1);
  }
  else {
    iVar1 = read(in_stack_00000004,buf,unaff_SI);
    bVar2 = (byte)((uint)iVar1 >> 8);
    if (iVar1 == (*(uint16_t *)((uint8_t *)&(buf) + 2))) {
      iVar1 = CONCAT11(bVar2,1);
    }
    else {
      iVar1 = (uint)bVar2 << 8;
    }
  }
  return iVar1;
}



/* 49fd:0035 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_calcSeasonPalette */

void __cdecl16far save_usesCalcSeasonPalette(void)

{
  /* Re-derived: resets any entity animation frame above 100 to 0xf and counts them; when none
     was reset it rebuilds the direction flags of every placed building with a non-zero
     building-type mask, reloads the seasonal palette and re-maps the party slots.  `in_DX` was
     only ever assigned 0x2410 - the DGROUP segment constant the codebase passes literally - so
     it is that constant here, and uStack_4 (assigned from it, never read) is gone. */
  unit_t *units;
  uint entIdx;
  uint unitIdx;
  int resetCount;
  far_t handle;
  uint8_t palette;
  stg_tmp_t *palRec;

  resetCount = 0;
  for (entIdx = 0; entIdx < EntityCount; entIdx = entIdx + 1) {
    if (100 < (Entities)[entIdx].base.animFrame) {
      (Entities)[entIdx].base.animFrame = 0xf;
      resetCount = resetCount + 1;
    }
  }
  if (resetCount == 0) {
    for (unitIdx = 0xf8; unitIdx < GUnitCount; unitIdx = unitIdx + 1) {
      units = GUnits;
      if ((BuildingTypes[(uint)(units + unitIdx)->bldType].flags & 3) != 0) {
        ovr_ovc23_rebuildDirectionFlags(units[unitIdx].x,units[unitIdx].y);
        ovr_ovc23_rebuildDirectionFlags((GUnits)[unitIdx].x + -1,
                                        (GUnits)[unitIdx].y);
        ovr_ovc23_rebuildDirectionFlags((GUnits)[unitIdx].x,
                                        (GUnits)[unitIdx].y + 1);
      }
    }
    ovr_attact_usesGMapFlags3();
    ovr_season_countPromotable();
    handle.seg = Lbm_nwpanel1.seg;
    handle.ofs = Lbm_nwpanel1.ofs;
    palRec = ovr_stshLoadGfx(handle);
    ovr_calcSeasonPalette(palRec->cmap,0x2410,&palette,_SS,0,0);
    ovr_vgaSetPalette8bit(&palette,0);
    ovr_manage_mapPartySlots();
    strongholdCheckPending = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x4d);
}



/* 49fd:01da */

/* Loads a saved game.  The image is a straight sequence of validated block reads
   (`push count / push bufSeg / push bufOfs / push handle / push cs / call 0`), then the leader
   sheets are allocated 0xae bytes each and read, the 10-byte preview block and the header are
   read again, and the header is compared with the saved one so a truncated file is rejected.

   The previous body passed `unaff_DI`/`unaff_SI` as the segment and count of every call, i.e.
   garbage, and declared the 0x28-byte header as a single byte.  Every argument below is taken from
   the image; the two module-data segments (0x58 for the square records, 0x88 for the record list)
   have no symbol in the tree and are marked as such. */
uint __cdecl16far stLoad(int handle)

{
  uint8_t header[0x28];
  char far *savedHeader;
  int i;

  ovr_stop_audio();
  ovr_drawTextAt((char far *)"Loading...",0xa000);
  if (handle < 0) {
    goto failed;
  }
  SaveAuto = 0;
  AgntFlag1 = false;
  ovr_freeGameResources();
  if ((save_readBlock(handle,(void *)header,_SS,0x28) & 0xff) == 0) {
    goto failed;
  }
  /* The image calls the CRT's far strcmp (`lcall 0,0x2d01`) with two far pointers; this tree's
     strcmp takes near pointers, so the header is compared with the same strcmp semantics by hand. */
  savedHeader = (char far *)MK_FP(SaveHeader.seg,SaveHeader.ofs);
  for (i = 0; i < 0x28; i++) {
    if (header[i] != savedHeader[i]) {
      goto failed;
    }
    if (header[i] == '\0') {
      break;
    }
  }
  if ((save_readBlock(handle,(void *)(uint16_t)GUnitGrid,
                      (uint16_t)((uint32_t)GUnitGrid >> 16),0x4560) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)(uint16_t)GMapFlags,
                      (uint16_t)((uint32_t)GMapFlags >> 16),0x4560) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)(uint16_t)GMapCells,
                      (uint16_t)((uint32_t)GMapCells >> 16),0x22b0) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GfxRndSeed,_DS,2) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GfxRndSeed2,_DS,2) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&EntityCount,_DS,2) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)(uint16_t)Entities,
                      (uint16_t)((uint32_t)Entities >> 16),EntityCount * 0x37) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&SquareRecCount,_DS,2) & 0xff) == 0) {
    goto failed;
  }
  /* GUESS: the square-record array lives at segment 0x58 offset 0 (a module data segment the tree
     has no symbol for); the image pushes the segment as a literal. */
  if ((save_readBlock(handle,(void *)0,0x58,SquareRecCount * 0x13) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GLeaderCount,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  for (i = 0; i < (int)(uint)GLeaderCount; i++) {
    GLeaderSheets[i] = (char_sheet_t far *)ovr_stshAlloc(0xae,0);
    if ((save_readBlock(handle,(void *)(uint16_t)GLeaderSheets[i],
                        (uint16_t)((uint32_t)GLeaderSheets[i] >> 16),0xae) & 0xff) == 0) {
      goto failed;
    }
  }
  if ((save_readBlock(handle,(void *)&TimerSeed,_DS,4) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&CurPartySlot,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&PartyCount,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GRecordCount,_DS,2) & 0xff) == 0) {
    goto failed;
  }
  /* GUESS: the record list lives at segment 0x88 offset 0 (same situation as 0x58 above). */
  if ((save_readBlock(handle,(void *)0,0x88,GRecordCount * 0x12) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GUnitCount,_DS,2) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)(uint16_t)GUnits,
                      (uint16_t)((uint32_t)GUnits >> 16),GUnitCount * 9) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&MessageDelay,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&worldIndex,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&spyReportTimer,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&seasonTimer,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&tickCountLo,_DS,4) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&PlayerIndex,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&PartySize,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&unitUpdateTimer,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&messageDelayTicks,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GameTick,_DS,2) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&Difficulty,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&lowIntelEnemies,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&medIntelEnemies,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&highIntelEnemies,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&secondWaveSize,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&promotionBandUsed,_DS,2) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&promotionCount,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&strongholdsDestroyed,_DS,2) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GHighScoreSaved,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GPaused,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GPopulationLo,_DS,4) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GGameInProgress,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GSeason,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GTimeLo,_DS,2) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&seasonGroupBase,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GWantsExit2,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&PlayerCount,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GYear,_DS,2) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&GSeed,_DS,4) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)&ListCount,_DS,1) & 0xff) == 0) {
    goto failed;
  }
  /* GUESS: an unnamed 10-byte DGROUP block at 0x92bc..0x92c5 (no audit symbol; the tree's
     declarations there are the talkwin9 cut pointers, which the original does not read here). */
  if ((save_readBlock(handle,(void *)0x92bc,_DS,0xa) & 0xff) == 0) {
    goto failed;
  }
  if ((save_readBlock(handle,(void *)header,_SS,0x28) & 0xff) == 0) {
    goto failed;
  }
  for (i = 0; i < 0x28; i++) {
    if (header[i] != savedHeader[i]) {
      goto failed;
    }
    if (header[i] == '\0') {
      break;
    }
  }
  ovr_drawTextAt((char far *)"Load complete.",0xa000);
  SaveAuto = 1;
  ovr_ovc24_usesAlignUp4();
  save_usesCalcSeasonPalette();
  return 1;

failed:
  if (suppressLoadError == 0) {
    ovr_drawTextAt((char far *)"Load Error",0xa000);
  }
  return 0;
}
/* 49fd:081e */

/* Loads the save slot named save.NNN: builds the filename, opens it, runs stLoad on the handle and
   closes it. */

undefined1 __cdecl16far save_loadGameFile(void)

{
  char *filename;
  int handle;
  uint16_t uVar1;
  uint16_t in_DX;
  
  filename = ovr_fmVsprintf("%ssave.%03d",&GWorkDir);
  handle = ovr_open_wait_unlock_and_disk(filename,in_DX);
  uVar1 = stLoad(handle);
  close(handle);
  return (char)uVar1;
}



/* 49fd:0863 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Loads the save embedded in the archive at the offset recorded in the cred03Cut3 record. */

undefined1 __cdecl16far save_loadArchiveGame(void)

{
  int handle;
  uint16_t uVar1;
  int unaff_SI;
  
  handle = StshHandles[0];
  if (StshHandles[0] < 0) {
    handle = ovr_open_wait_unlock_and_disk((char *)StshNames[0],0);
  }
  lseek(handle,(ulong)*(uint *)((int)cred03Cut3Ofs + 3),unaff_SI);
  uVar1 = stLoad(handle);
  if (StshHandles[0] < 0) {
    close(handle);
  }
  return (char)uVar1;
}



/* 49fd:08da */

/* Writes exactly `count` bytes to the save handle, returning success. */

int __cdecl16far save_writeBlock(int handle,void *buf,uint16_t bufSeg,uint16_t count)

{
  uint16_t in_AX;
  int iVar1;
  uint16_t written;
  byte writtenHi;
  int in_stack_00000004;
  
  if ((*(uint16_t *)((uint8_t *)&(buf) + 2)) == 0) {
    iVar1 = CONCAT11((char)((uint)in_AX >> 8),1);
  }
  else {
    written = write(in_stack_00000004,(void *)CONCAT22((void *)buf,handle),(*(uint16_t *)((uint8_t *)&(buf) + 2)));
    writtenHi = (byte)(written >> 8);
    if (written == (*(uint16_t *)((uint8_t *)&(buf) + 2))) {
      iVar1 = CONCAT11(writtenHi,1);
    }
    else {
      iVar1 = (uint)writtenHi << 8;
    }
  }
  return iVar1;
}



/* 49fd:090f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl16far stSave(void)

{
  char *path;
  int iVar2;
  uint writeOk;
  uint16_t in_DX;
  uint16_t unaff_SI;
  uint16_t unaff_DI;
  int iVar6;
  
  ovr_drawTextAt((char *)"Saving...",0x2410,0xa000);
  ovr_stop_audio();
  path = ovr_fmVsprintf("%ssave.%03d",&GWorkDir);
  iVar2 = ovr_creat_wait_unlock_and_disk(path,in_DX);
  if (-1 < iVar2) {
    writeOk = save_writeBlock(SaveHeader.ofs,(void *)CONCAT22(0x28,SaveHeader.seg),unaff_DI,unaff_SI);
    if ((((((writeOk & 0xff) != 0) &&
          (writeOk = save_writeBlock((int)(short (*) [148] [60])GUnitGrid,
                                   (void *)CONCAT22(0x4560,(*(uint16_t *)((uint8_t *)&(GUnitGrid) + 2))),unaff_DI,unaff_SI),
          (writeOk & 0xff) != 0)) &&
         (writeOk = save_writeBlock((int)(short (*) [60] [148])GMapFlags,
                                  (void *)CONCAT22(0x4560,(*(uint16_t *)((uint8_t *)&(GMapFlags) + 2))),unaff_DI,unaff_SI),
         (writeOk & 0xff) != 0)) &&
        ((writeOk = save_writeBlock((int)(byte (*) [59] [148])GMapCells,
                                  (void *)CONCAT22(0x22b0,(*(uint16_t *)((uint8_t *)&(GMapCells) + 2))),unaff_DI,unaff_SI),
         (writeOk & 0xff) != 0 &&
         (writeOk = save_writeBlock(-0x7661,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI), (writeOk & 0xff) != 0)))
        ) && ((writeOk = save_writeBlock(-0x7663,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
              (writeOk & 0xff) != 0 &&
              (writeOk = save_writeBlock(-0x6f69,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
              (writeOk & 0xff) != 0)))) {
      in_DX = (uint16_t)((ulong)((long)EntityCount * 0x37) >> 0x10);
      writeOk = save_writeBlock((int)Entities,
                              (void *)CONCAT22((int)((long)EntityCount * 0x37),DAT_2000_d190),
                              unaff_DI,unaff_SI);
      if (((writeOk & 0xff) != 0) &&
         (writeOk = save_writeBlock(0x881,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI), (writeOk & 0xff) != 0)) {
        in_DX = (uint16_t)((ulong)((long)SquareRecCount * 0x13) >> 0x10);
        writeOk = save_writeBlock(0,(void *)CONCAT22((int)((long)SquareRecCount * 0x13),
                                                   (void *)((int)&AgntAnms[0x7c].halfWidth + 1)),
                                unaff_DI,unaff_SI);
        if (((writeOk & 0xff) != 0) &&
           (writeOk = save_writeBlock(-0x6f1a,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI), (writeOk & 0xff) != 0)
           ) {
          for (iVar6 = 0; iVar6 < (int)(uint)GLeaderCount; iVar6 = iVar6 + 1) {
            writeOk = save_writeBlock(*(int *)(iVar6 * 4),
                                    (void *)CONCAT22(0xae,(void *)((int *)(iVar6 * 4))[1]),unaff_DI,
                                    unaff_SI);
            if ((writeOk & 0xff) == 0) goto L_stSave_0EE6;
          }
          writeOk = save_writeBlock(0x4a12,(void *)&__C0_ASM_CopyRight,unaff_DI,unaff_SI);
          if (((((writeOk & 0xff) != 0) &&
               (writeOk = save_writeBlock(-0x6f1b,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
               (writeOk & 0xff) != 0)) &&
              (writeOk = save_writeBlock(-0x6f1c,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
              (writeOk & 0xff) != 0)) &&
             (writeOk = save_writeBlock(-0x6e21,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
             (writeOk & 0xff) != 0)) {
            in_DX = (uint16_t)((ulong)((long)GRecordCount * 0x12) >> 0x10);
            writeOk = save_writeBlock(0,(char *)CONCAT22((int)((long)GRecordCount * 0x12),
                                                       (char *)0x262f2),unaff_DI,
                                    unaff_SI);
            if (((writeOk & 0xff) != 0) &&
               (writeOk = save_writeBlock(-0x7667,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
               (writeOk & 0xff) != 0)) {
              in_DX = (uint16_t)((ulong)((long)GUnitCount * 9) >> 0x10);
              writeOk = save_writeBlock((int)GUnits,
                                      (void *)CONCAT22((int)((long)GUnitCount * 9),(*(uint16_t *)((uint8_t *)&(GUnits) + 2))),
                                      unaff_DI,unaff_SI);
              if ((((writeOk & 0xff) != 0) &&
                  ((writeOk = save_writeBlock(0x2f3,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                   (writeOk & 0xff) != 0 &&
                   (writeOk = save_writeBlock(-0x6f62,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                   (writeOk & 0xff) != 0)))) &&
                 (((writeOk = save_writeBlock(-0x6f91,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                   (writeOk & 0xff) != 0 &&
                   ((((((writeOk = save_writeBlock(-0x6f92,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                        (writeOk & 0xff) != 0 &&
                        (writeOk = save_writeBlock(-0x6f97,(void *)&__C0_ASM_CopyRight,unaff_DI,unaff_SI),
                        (writeOk & 0xff) != 0)) &&
                       (writeOk = save_writeBlock(-0x6df0,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                       (writeOk & 0xff) != 0)) &&
                      (((writeOk = save_writeBlock(-0x6f1d,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                        (writeOk & 0xff) != 0 &&
                        (writeOk = save_writeBlock(-0x6f93,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                        (writeOk & 0xff) != 0)) &&
                       ((writeOk = save_writeBlock(0x2f4,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                        (writeOk & 0xff) != 0 &&
                        ((writeOk = save_writeBlock(-0x6f99,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
                         (writeOk & 0xff) != 0 &&
                         (writeOk = save_writeBlock(-0x6f63,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                         (writeOk & 0xff) != 0)))))))) &&
                     (writeOk = save_writeBlock(0x5dcf,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                     (writeOk & 0xff) != 0)) &&
                    ((((((writeOk = save_writeBlock(0x5dd7,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                         (writeOk & 0xff) != 0 &&
                         (writeOk = save_writeBlock(0x5ddf,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                         (writeOk & 0xff) != 0)) &&
                        (writeOk = save_writeBlock(0x5de7,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                        (writeOk & 0xff) != 0)) &&
                       ((writeOk = save_writeBlock(-0x6d33,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
                        (writeOk & 0xff) != 0 &&
                        (writeOk = save_writeBlock(-0x6d34,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                        (writeOk & 0xff) != 0)))) &&
                      (writeOk = save_writeBlock(0x6a86,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
                      (writeOk & 0xff) != 0)) &&
                     ((writeOk = save_writeBlock(0x6a88,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                      (writeOk & 0xff) != 0 &&
                      (writeOk = save_writeBlock(0x439,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                      (writeOk & 0xff) != 0)))))))) &&
                  ((((writeOk = save_writeBlock(-0x766f,(void *)&__C0_ASM_CopyRight,unaff_DI,unaff_SI),
                     (writeOk & 0xff) != 0 &&
                     (((writeOk = save_writeBlock(-0x7670,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                       (writeOk & 0xff) != 0 &&
                       (writeOk = save_writeBlock(0x693a,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                       (writeOk & 0xff) != 0)) &&
                      (writeOk = save_writeBlock(-0x6d38,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
                      (writeOk & 0xff) != 0)))) &&
                    (((writeOk = save_writeBlock(0x744,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                      (writeOk & 0xff) != 0 &&
                      (writeOk = save_writeBlock(-0x6f65,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                      (writeOk & 0xff) != 0)) &&
                     (writeOk = save_writeBlock(-0x6e1a,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                     (writeOk & 0xff) != 0)))) &&
                   (((writeOk = save_writeBlock(-0x6e1c,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
                     (writeOk & 0xff) != 0 &&
                     (writeOk = save_writeBlock(0x26df,(void *)&__C0_ASM_CopyRight,unaff_DI,unaff_SI),
                     (writeOk & 0xff) != 0)) &&
                    ((writeOk = save_writeBlock(-0x6d3a,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                     (writeOk & 0xff) != 0 &&
                     ((writeOk = save_writeBlock(-0x6d44,(void *)MK_FP(0x2410, 0xa),unaff_DI,unaff_SI),
                      (writeOk & 0xff) != 0 &&
                      (writeOk = save_writeBlock(SaveHeader.ofs,(void *)CONCAT22(0x28,SaveHeader.seg),
                                               unaff_DI,unaff_SI), (writeOk & 0xff) != 0)))))))))))) {
                iVar2 = close(iVar2);
                ovr_drawTextAt((char *)"Save complete.",0x2410,0xa000);
                return 1;
              }
            }
          }
        }
      }
    }
L_stSave_0EE6:
    close(iVar2);
    path = ovr_fmVsprintf("%ssave.%03d",&GWorkDir);
    iVar2 = unlink((char *)CONCAT22(in_DX,path));
  }
  ovr_drawTextAt((char *)"Save Error",0x2410,0xa000);
  return 0;
}



/* 49fd:0f26 */

/* Deletes the save slot file save.NNN after the "Deleting..." prompt. */

void __cdecl16far save_deleteGameFile(void)

{
  char *pcVar1;
  uint16_t in_DX;
  
  ovr_drawTextAt((char *)"Deleting...",0x2410,0xa000);
  pcVar1 = ovr_fmVsprintf("%ssave.%03d",&GWorkDir);
  unlink((char *)CONCAT22(in_DX,pcVar1));
  ovr_drawTextAt((char *)"Delete complete.",0x2410,0xa000);
  return;
}


