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
  undefined2 in_AX;
  int iVar1;
  uint uVar2;
  byte bVar3;
  
  if (count == 0) {
    iVar1 = CONCAT11((char)((uint)in_AX >> 8),1);
  }
  else {
    uVar2 = read(handle,buf,bufSeg);
    bVar3 = (byte)(uVar2 >> 8);
    if (uVar2 == count) {
      iVar1 = CONCAT11(bVar3,1);
    }
    else {
      iVar1 = (uint)bVar3 << 8;
    }
  }
  return iVar1;
}



/* 49fd:0035 */

/* [R4] calls ovr_calcSeasonPalette */

void __cdecl16far save_usesCalcSeasonPalette(void)

{
  uint16_t in_DX;
  unit_t *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  uint16_t unaff_SS;
  far_t handle;
  uint8_t palette;
  stg_tmp_t *psStack_6;
  uint16_t uStack_4;
  
  iVar3 = 0;
  for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
    uVar4 = (undefined2)((ulong)Entities >> 0x10);
    if (100 < ((entity_t *)Entities)[uVar2].base.animFrame) {
      ((entity_t *)Entities)[uVar2].base.animFrame = 0xf;
      iVar3 = iVar3 + 1;
    }
    in_DX = 0x2410;
  }
  if (iVar3 == 0) {
    for (uVar2 = 0xf8; uVar2 < GUnitCount; uVar2 = uVar2 + 1) {
      uVar4 = (undefined2)((ulong)GUnits >> 0x10);
      puVar1 = (unit_t *)GUnits;
      in_DX = 0x195d;
      if ((*(byte *)((uint)(puVar1 + uVar2)->bldType * 0x27 + 0x11e) & 3) != 0) {
        ovr_ovc23_rebuildDirectionFlags(puVar1[uVar2].x,puVar1[uVar2].y);
        uVar4 = (undefined2)((ulong)GUnits >> 0x10);
        ovr_ovc23_rebuildDirectionFlags
                  (((unit_t *)GUnits)[uVar2].x + -1,((unit_t *)GUnits)[uVar2].y);
        uVar4 = (undefined2)((ulong)GUnits >> 0x10);
        in_DX = 0x2410;
        ovr_ovc23_rebuildDirectionFlags(((unit_t *)GUnits)[uVar2].x,((unit_t *)GUnits)[uVar2].y + 1)
        ;
      }
    }
    ovr_attact_usesGMapFlags3();
    ovr_season_countPromotable();
    handle.seg = Lbm_nwpanel1.seg;
    handle.ofs = Lbm_nwpanel1.ofs;
    psStack_6 = ovr_stshLoadGfx(handle);
    uStack_4 = in_DX;
    ovr_calcSeasonPalette(psStack_6->cmap,in_DX,&palette,unaff_SS);
    ovr_vgaSetPalette8bit((uint8_t *)CONCAT22(unaff_SS,&palette));
    ovr_manage_mapPartySlots();
    strongholdCheckPending = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x4d);
}



/* 49fd:01da */

/* Loads a saved game: frees the game resources, then reads the magic, GUnitGrid, GMapFlags,
   GMapCells, the RNG seeds, EntityCount and Entities from the handle. */

uint __cdecl16far stLoad(int handle)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  char *unaff_SS;
  uint8_t header;
  
  ovr_stop_audio();
  ovr_drawTextAt((char *)"Loading...",0x2410);
  if (-1 < handle) {
    SaveAuto = 0;
    AgntFlag1 = false;
    ovr_freeGameResources();
    uVar1 = save_readBlock(handle,&header,(uint16_t)unaff_SS,0x28);
    if (((((uVar1 & 0xff) != 0) && (iVar2 = strcmp((char *)&header,unaff_SS), iVar2 == 0)) &&
        (uVar1 = save_readBlock(handle,(short (*) [148] [60])GUnitGrid,(*(uint16_t *)((uint8_t *)&(GUnitGrid) + 2)),0x4560),
        (uVar1 & 0xff) != 0)) &&
       ((((uVar1 = save_readBlock(handle,(short (*) [60] [148])GMapFlags,(*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),0x4560),
          (uVar1 & 0xff) != 0 &&
          (uVar1 = save_readBlock(handle,(byte (*) [59] [148])GMapCells,(*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),0x22b0),
          (uVar1 & 0xff) != 0)) &&
         ((uVar1 = save_readBlock(handle,(undefined2 *)&GfxRndSeed,0x2410,2), (uVar1 & 0xff) != 0 &&
          ((uVar1 = save_readBlock(handle,(undefined2 *)&GfxRndSeed2,0x2410,2), (uVar1 & 0xff) != 0
           && (uVar1 = save_readBlock(handle,(undefined2 *)&EntityCount,0x2410,2),
              (uVar1 & 0xff) != 0)))))) &&
        ((uVar1 = save_readBlock(handle,(entity_t *)Entities,(*(uint16_t *)((uint8_t *)&(Entities) + 2)),EntityCount * 0x37),
         (uVar1 & 0xff) != 0 &&
         (uVar1 = save_readBlock(handle,(undefined2 *)&SquareRecCount,0x2410,2), (uVar1 & 0xff) != 0
         )))))) {
      uVar5 = (undefined2)((ulong)((long)SquareRecCount * 0x13) >> 0x10);
      uVar1 = save_readBlock(handle,(void *)0x0,0x17f8,(uint)((long)SquareRecCount * 0x13));
      if (((uVar1 & 0xff) != 0) &&
         (uVar1 = save_readBlock(handle,(undefined1 *)&GLeaderCount,0x2410,1), (uVar1 & 0xff) != 0))
      {
        for (iVar2 = 0; iVar2 < (int)(uint)GLeaderCount; iVar2 = iVar2 + 1) {
          pvVar3 = ovr_stshAlloc(0xae);
          ((undefined2 *)(iVar2 * 4))[1] = uVar5;
          *(undefined2 *)(iVar2 * 4) = pvVar3;
          uVar1 = save_readBlock(handle,(void *)*(undefined2 *)(iVar2 * 4),
                                 ((undefined2 *)(iVar2 * 4))[1],0xae);
          if ((uVar1 & 0xff) == 0) goto L_save_49fd_01da_0800;
        }
        uVar1 = save_readBlock(handle,(DW *)&TimerSeed,0x2410,4);
        if (((((((((((uVar1 & 0xff) != 0) &&
                   (uVar1 = save_readBlock(handle,(undefined1 *)&CurPartySlot,0x2410,1),
                   (uVar1 & 0xff) != 0)) &&
                  (uVar1 = save_readBlock(handle,(undefined1 *)&PartyCount,0x2410,1),
                  (uVar1 & 0xff) != 0)) &&
                 (((uVar1 = save_readBlock(handle,(undefined2 *)&GRecordCount,0x2410,2),
                   (uVar1 & 0xff) != 0 &&
                   (uVar1 = save_readBlock(handle,(void *)0x0,0x21f2,GRecordCount * 0x12),
                   (uVar1 & 0xff) != 0)) &&
                  ((uVar1 = save_readBlock(handle,(undefined2 *)&GUnitCount,0x2410,2),
                   (uVar1 & 0xff) != 0 &&
                   ((uVar1 = save_readBlock(handle,(unit_t *)GUnits,(*(uint16_t *)((uint8_t *)&(GUnits) + 2)),GUnitCount * 9),
                    (uVar1 & 0xff) != 0 &&
                    (uVar1 = save_readBlock(handle,(undefined1 *)&MessageDelay,0x2410,1),
                    (uVar1 & 0xff) != 0)))))))) &&
                (uVar1 = save_readBlock(handle,(undefined1 *)&worldIndex,0x2410,1),
                (uVar1 & 0xff) != 0)) &&
               ((((uVar1 = save_readBlock(handle,(undefined1 *)&spyReportTimer,0x2410,1),
                  (uVar1 & 0xff) != 0 &&
                  (uVar1 = save_readBlock(handle,(undefined1 *)&seasonTimer,0x2410,1),
                  (uVar1 & 0xff) != 0)) &&
                 (uVar1 = save_readBlock(handle,(undefined2 *)&tickCountLo,0x2410,4),
                 (uVar1 & 0xff) != 0)) &&
                ((uVar1 = save_readBlock(handle,(undefined1 *)&PlayerIndex,0x2410,1),
                 (uVar1 & 0xff) != 0 &&
                 (uVar1 = save_readBlock(handle,(undefined1 *)&PartySize,0x2410,1),
                 (uVar1 & 0xff) != 0)))))) &&
              (((uVar1 = save_readBlock(handle,(undefined1 *)&unitUpdateTimer,0x2410,1),
                (uVar1 & 0xff) != 0 &&
                ((uVar1 = save_readBlock(handle,(undefined1 *)&messageDelayTicks,0x2410,1),
                 (uVar1 & 0xff) != 0 &&
                 (uVar1 = save_readBlock(handle,(undefined2 *)&GameTick,0x2410,2),
                 (uVar1 & 0xff) != 0)))) &&
               (uVar1 = save_readBlock(handle,(undefined1 *)&Difficulty,0x2410,1),
               (uVar1 & 0xff) != 0)))) &&
             ((((uVar1 = save_readBlock(handle,(undefined1 *)&lowIntelEnemies,0x2410,1),
                (uVar1 & 0xff) != 0 &&
                (uVar1 = save_readBlock(handle,(undefined1 *)&medIntelEnemies,0x2410,1),
                (uVar1 & 0xff) != 0)) &&
               (uVar1 = save_readBlock(handle,(undefined1 *)&highIntelEnemies,0x2410,1),
               (uVar1 & 0xff) != 0)) &&
              (((uVar1 = save_readBlock(handle,(undefined1 *)&secondWaveSize,0x2410,1),
                (uVar1 & 0xff) != 0 &&
                (uVar1 = save_readBlock(handle,(byte *)promotionBandUsed,0x2410,2),
                (uVar1 & 0xff) != 0)) &&
               ((uVar1 = save_readBlock(handle,(undefined1 *)&promotionCount,0x2410,1),
                (uVar1 & 0xff) != 0 &&
                ((uVar1 = save_readBlock(handle,(undefined2 *)&strongholdsDestroyed,0x2410,2),
                 (uVar1 & 0xff) != 0 &&
                 (uVar1 = save_readBlock(handle,(undefined1 *)&GHighScoreSaved,0x2410,1),
                 (uVar1 & 0xff) != 0)))))))))) &&
            ((uVar1 = save_readBlock(handle,(undefined1 *)&GPaused,0x2410,1), (uVar1 & 0xff) != 0 &&
             ((((uVar1 = save_readBlock(handle,(undefined2 *)&GPopulationLo,0x2410,4),
                (uVar1 & 0xff) != 0 &&
                (uVar1 = save_readBlock(handle,(undefined1 *)&GGameInProgress,0x2410,1),
                (uVar1 & 0xff) != 0)) &&
               (uVar1 = save_readBlock(handle,(undefined1 *)&GSeason,0x2410,1), (uVar1 & 0xff) != 0)
               ) && (((uVar1 = save_readBlock(handle,(undefined2 *)&GTimeLo,0x2410,2),
                      (uVar1 & 0xff) != 0 &&
                      (uVar1 = save_readBlock(handle,(undefined1 *)&seasonGroupBase,0x2410,1),
                      (uVar1 & 0xff) != 0)) &&
                     ((uVar1 = save_readBlock(handle,(undefined1 *)&GWantsExit2,0x2410,1),
                      (uVar1 & 0xff) != 0 &&
                      ((uVar1 = save_readBlock(handle,(undefined1 *)&PlayerCount,0x2410,1),
                       (uVar1 & 0xff) != 0 &&
                       (uVar1 = save_readBlock(handle,(undefined2 *)&GYear,0x2410,2),
                       (uVar1 & 0xff) != 0)))))))))))) &&
           ((uVar1 = save_readBlock(handle,(undefined2 *)&GSeed,0x2410,4), (uVar1 & 0xff) != 0 &&
            ((((uVar1 = save_readBlock(handle,(undefined1 *)&ListCount,0x2410,1),
               (uVar1 & 0xff) != 0 &&
               (uVar1 = save_readBlock(handle,(void *)0x92bc,0x2410,10), (uVar1 & 0xff) != 0)) &&
              (uVar1 = save_readBlock(handle,&header,(uint16_t)unaff_SS,0x28), (uVar1 & 0xff) != 0))
             && (iVar2 = strcmp((char *)&header,unaff_SS), iVar2 == 0)))))) {
          ovr_drawTextAt((char *)"Load complete.",0x2410);
          uVar4 = (undefined1)((uint)iVar2 >> 8);
          SaveAuto = 1;
          ovr_ovc24_usesAlignUp4();
          save_usesCalcSeasonPalette();
          return CONCAT11(uVar4,1);
        }
      }
    }
  }
L_save_49fd_01da_0800:
  uVar1 = (uint)suppressLoadError;
  if (uVar1 == 0) {
    ovr_drawTextAt((char *)"Load Error",0x2410);
  }
  return uVar1 & 0xff00;
}



/* 49fd:081e */

/* Loads the save slot named save.NNN: builds the filename, opens it, runs stLoad on the handle and
   closes it. */

undefined1 __cdecl16far save_loadGameFile(void)

{
  char *filename;
  int handle;
  undefined2 uVar1;
  
  filename = ovr_fmVsprintf((char *)"%ssave.%03d",(char *)"puppetmaker" + 3);
  handle = ovr_open_wait_unlock_and_disk(filename);
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
  undefined2 uVar1;
  int unaff_SI;
  
  handle = StshHandles[0];
  if (StshHandles[0] < 0) {
    handle = ovr_open_wait_unlock_and_disk((char *)StshNames[0]);
  }
  lseek(handle,(ulong)*(uint *)((int)_cred03Cut3Ofs + 3),unaff_SI);
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
  undefined2 in_AX;
  int iVar1;
  uint16_t uVar2;
  byte bVar3;
  
  if (count == 0) {
    iVar1 = CONCAT11((char)((uint)in_AX >> 8),1);
  }
  else {
    uVar2 = write(handle,buf,bufSeg);
    bVar3 = (byte)(uVar2 >> 8);
    if (uVar2 == count) {
      iVar1 = CONCAT11(bVar3,1);
    }
    else {
      iVar1 = (uint)bVar3 << 8;
    }
  }
  return iVar1;
}



/* 49fd:090f */

int __cdecl16far stSave(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  byte bVar5;
  int iVar6;
  
  ovr_drawTextAt((char *)"Saving...",0x2410);
  ovr_stop_audio();
  pcVar1 = ovr_fmVsprintf((char *)"%ssave.%03d",(char *)"puppetmaker" + 3);
  iVar2 = ovr_creat_wait_unlock_and_disk(pcVar1);
  if (-1 < iVar2) {
    uVar3 = save_writeBlock(iVar2,(void *)SaveHeader.ofs,SaveHeader.seg,0x28);
    if ((((((uVar3 & 0xff) != 0) &&
          (uVar3 = save_writeBlock(iVar2,(short (*) [148] [60])GUnitGrid,(*(uint16_t *)((uint8_t *)&(GUnitGrid) + 2)),0x4560),
          (uVar3 & 0xff) != 0)) &&
         (uVar3 = save_writeBlock(iVar2,(short (*) [60] [148])GMapFlags,(*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),0x4560),
         (uVar3 & 0xff) != 0)) &&
        ((((uVar3 = save_writeBlock(iVar2,(byte (*) [59] [148])GMapCells,(*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),0x22b0),
           (uVar3 & 0xff) != 0 &&
           (uVar3 = save_writeBlock(iVar2,(undefined2 *)&GfxRndSeed,0x2410,2), (uVar3 & 0xff) != 0))
          && ((uVar3 = save_writeBlock(iVar2,(undefined2 *)&GfxRndSeed2,0x2410,2),
              (uVar3 & 0xff) != 0 &&
              ((uVar3 = save_writeBlock(iVar2,(undefined2 *)&EntityCount,0x2410,2),
               (uVar3 & 0xff) != 0 &&
               (uVar3 = save_writeBlock(iVar2,(entity_t *)Entities,(*(uint16_t *)((uint8_t *)&(Entities) + 2)),EntityCount * 0x37
                                       ), (uVar3 & 0xff) != 0)))))) &&
         (uVar3 = save_writeBlock(iVar2,(undefined2 *)&SquareRecCount,0x2410,2), (uVar3 & 0xff) != 0
         )))) && ((uVar3 = save_writeBlock(iVar2,(void *)0x0,0x17f8,SquareRecCount * 0x13),
                  (uVar3 & 0xff) != 0 &&
                  (uVar3 = save_writeBlock(iVar2,(undefined1 *)&GLeaderCount,0x2410,1),
                  (uVar3 & 0xff) != 0)))) {
      for (iVar6 = 0; iVar6 < (int)(uint)GLeaderCount; iVar6 = iVar6 + 1) {
        uVar3 = save_writeBlock(iVar2,(void *)*(undefined2 *)(iVar6 * 4),
                                ((undefined2 *)(iVar6 * 4))[1],0xae);
        if ((uVar3 & 0xff) == 0) goto L_stSave_0EE6;
      }
      uVar3 = save_writeBlock(iVar2,(DW *)&TimerSeed,0x2410,4);
      if (((((((uVar3 & 0xff) != 0) &&
             (uVar3 = save_writeBlock(iVar2,(undefined1 *)&CurPartySlot,0x2410,1),
             (uVar3 & 0xff) != 0)) &&
            (uVar3 = save_writeBlock(iVar2,(undefined1 *)&PartyCount,0x2410,1), (uVar3 & 0xff) != 0)
            ) && (((uVar3 = save_writeBlock(iVar2,(undefined2 *)&GRecordCount,0x2410,2),
                   (uVar3 & 0xff) != 0 &&
                   (uVar3 = save_writeBlock(iVar2,(void *)0x0,0x21f2,GRecordCount * 0x12),
                   (uVar3 & 0xff) != 0)) &&
                  ((uVar3 = save_writeBlock(iVar2,(undefined2 *)&GUnitCount,0x2410,2),
                   (uVar3 & 0xff) != 0 &&
                   ((uVar3 = save_writeBlock(iVar2,(unit_t *)GUnits,(*(uint16_t *)((uint8_t *)&(GUnits) + 2)),GUnitCount * 9),
                    (uVar3 & 0xff) != 0 &&
                    (uVar3 = save_writeBlock(iVar2,(undefined1 *)&MessageDelay,0x2410,1),
                    (uVar3 & 0xff) != 0)))))))) &&
          ((uVar3 = save_writeBlock(iVar2,(undefined1 *)&worldIndex,0x2410,1), (uVar3 & 0xff) != 0
           && (((((uVar3 = save_writeBlock(iVar2,(undefined1 *)&spyReportTimer,0x2410,1),
                  (uVar3 & 0xff) != 0 &&
                  (uVar3 = save_writeBlock(iVar2,(undefined1 *)&seasonTimer,0x2410,1),
                  (uVar3 & 0xff) != 0)) &&
                 (uVar3 = save_writeBlock(iVar2,(undefined2 *)&tickCountLo,0x2410,4),
                 (uVar3 & 0xff) != 0)) &&
                ((uVar3 = save_writeBlock(iVar2,(undefined1 *)&PlayerIndex,0x2410,1),
                 (uVar3 & 0xff) != 0 &&
                 (uVar3 = save_writeBlock(iVar2,(undefined1 *)&PartySize,0x2410,1),
                 (uVar3 & 0xff) != 0)))) &&
               (uVar3 = save_writeBlock(iVar2,(undefined1 *)&unitUpdateTimer,0x2410,1),
               (uVar3 & 0xff) != 0)))))) &&
         (((((uVar3 = save_writeBlock(iVar2,(undefined1 *)&messageDelayTicks,0x2410,1),
             (uVar3 & 0xff) != 0 &&
             (uVar3 = save_writeBlock(iVar2,(undefined2 *)&GameTick,0x2410,2), (uVar3 & 0xff) != 0))
            && ((((uVar3 = save_writeBlock(iVar2,(undefined1 *)&Difficulty,0x2410,1),
                  (uVar3 & 0xff) != 0 &&
                  (((uVar3 = save_writeBlock(iVar2,(undefined1 *)&lowIntelEnemies,0x2410,1),
                    (uVar3 & 0xff) != 0 &&
                    (uVar3 = save_writeBlock(iVar2,(undefined1 *)&medIntelEnemies,0x2410,1),
                    (uVar3 & 0xff) != 0)) &&
                   (uVar3 = save_writeBlock(iVar2,(undefined1 *)&highIntelEnemies,0x2410,1),
                   (uVar3 & 0xff) != 0)))) &&
                 (((uVar3 = save_writeBlock(iVar2,(undefined1 *)&secondWaveSize,0x2410,1),
                   (uVar3 & 0xff) != 0 &&
                   (uVar3 = save_writeBlock(iVar2,(byte *)promotionBandUsed,0x2410,2),
                   (uVar3 & 0xff) != 0)) &&
                  (uVar3 = save_writeBlock(iVar2,(undefined1 *)&promotionCount,0x2410,1),
                  (uVar3 & 0xff) != 0)))) &&
                ((uVar3 = save_writeBlock(iVar2,(undefined2 *)&strongholdsDestroyed,0x2410,2),
                 (uVar3 & 0xff) != 0 &&
                 (uVar3 = save_writeBlock(iVar2,(undefined1 *)&GHighScoreSaved,0x2410,1),
                 (uVar3 & 0xff) != 0)))))) &&
           ((uVar3 = save_writeBlock(iVar2,(undefined1 *)&GPaused,0x2410,1), (uVar3 & 0xff) != 0 &&
            (((uVar3 = save_writeBlock(iVar2,(undefined2 *)&GPopulationLo,0x2410,4),
              (uVar3 & 0xff) != 0 &&
              (uVar3 = save_writeBlock(iVar2,(undefined1 *)&GGameInProgress,0x2410,1),
              (uVar3 & 0xff) != 0)) &&
             (uVar3 = save_writeBlock(iVar2,(undefined1 *)&GSeason,0x2410,1), (uVar3 & 0xff) != 0)))
            ))) && (((uVar3 = save_writeBlock(iVar2,(undefined2 *)&GTimeLo,0x2410,2),
                     (uVar3 & 0xff) != 0 &&
                     (uVar3 = save_writeBlock(iVar2,(undefined1 *)&seasonGroupBase,0x2410,1),
                     (uVar3 & 0xff) != 0)) &&
                    ((uVar3 = save_writeBlock(iVar2,(undefined1 *)&GWantsExit2,0x2410,1),
                     (uVar3 & 0xff) != 0 &&
                     (((uVar3 = save_writeBlock(iVar2,(undefined1 *)&PlayerCount,0x2410,1),
                       (uVar3 & 0xff) != 0 &&
                       (uVar3 = save_writeBlock(iVar2,(undefined2 *)&GYear,0x2410,2),
                       (uVar3 & 0xff) != 0)) &&
                      ((uVar3 = save_writeBlock(iVar2,(undefined2 *)&GSeed,0x2410,4),
                       (uVar3 & 0xff) != 0 &&
                       (((uVar3 = save_writeBlock(iVar2,(undefined1 *)&ListCount,0x2410,1),
                         (uVar3 & 0xff) != 0 &&
                         (uVar3 = save_writeBlock(iVar2,(void *)0x92bc,0x2410,10),
                         (uVar3 & 0xff) != 0)) &&
                        (uVar3 = save_writeBlock(iVar2,(void *)SaveHeader.ofs,SaveHeader.seg,0x28),
                        (uVar3 & 0xff) != 0)))))))))))))) {
        iVar2 = close(iVar2);
        uVar4 = (undefined1)((uint)iVar2 >> 8);
        ovr_drawTextAt((char *)"Save complete.",0x2410);
        return CONCAT11(uVar4,1);
      }
    }
L_stSave_0EE6:
    close(iVar2);
    pcVar1 = ovr_fmVsprintf((char *)"%ssave.%03d",(char *)"puppetmaker" + 3);
    iVar2 = unlink(pcVar1);
  }
  bVar5 = (byte)((uint)iVar2 >> 8);
  ovr_drawTextAt((char *)"Save Error",0x2410);
  return (uint)bVar5 << 8;
}



/* 49fd:0f26 */

/* Deletes the save slot file save.NNN after the "Deleting..." prompt. */

void __cdecl16far save_deleteGameFile(void)

{
  char *file;
  
  ovr_drawTextAt((char *)"Deleting...",0x2410);
  file = ovr_fmVsprintf((char *)"%ssave.%03d",(char *)"puppetmaker" + 3);
  unlink(file);
  ovr_drawTextAt((char *)"Delete complete.",0x2410);
  return;
}


