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
    if (100 < *(byte *)((int)Entities + uVar2 * 0x37 + 0xe)) {
      *(undefined1 *)((int)Entities + uVar2 * 0x37 + 0xe) = 0xf;
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
    ovr_vgaSetPalette8bit(&palette);
    ovr_manage_mapPartySlots();
    strongholdCheckPending = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x4d);
}



/* 49fd:01da */
uint __cdecl16far stLoad(int handle)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  uint unaff_SI;
  uint16_t unaff_DI;
  void *unaff_SS;
  uint8_t header;
  
  ovr_stop_audio();
  ovr_drawTextAt((char *)"Loading...",0x2410);
  if (-1 < handle) {
    SaveAuto = 0;
    AgntFlag1 = false;
    ovr_freeGameResources();
    uVar1 = save_readBlock((int)&header,(void *)CONCAT22(0x28,unaff_SS),unaff_DI,unaff_SI);
    if (((((uVar1 & 0xff) != 0) &&
         (iVar2 = strcmp((char *)CONCAT22(unaff_SS,&header),
                         (char *)CONCAT22(SaveHeader.seg,SaveHeader.ofs)), iVar2 == 0)) &&
        (uVar1 = save_readBlock((int)(short (*) [148] [60])GUnitGrid,
                                (void *)CONCAT22(0x4560,(*(uint16_t *)((uint8_t *)&(GUnitGrid) + 2))),unaff_DI,unaff_SI),
        (uVar1 & 0xff) != 0)) &&
       ((((uVar1 = save_readBlock((int)(short (*) [60] [148])GMapFlags,
                                  (void *)CONCAT22(0x4560,(*(uint16_t *)((uint8_t *)&(GMapFlags) + 2))),unaff_DI,unaff_SI),
          (uVar1 & 0xff) != 0 &&
          (uVar1 = save_readBlock((int)(byte (*) [59] [148])GMapCells,
                                  (void *)CONCAT22(0x22b0,(*(uint16_t *)((uint8_t *)&(GMapCells) + 2))),unaff_DI,unaff_SI),
          (uVar1 & 0xff) != 0)) &&
         ((uVar1 = save_readBlock(-0x7661,(void *)0x22410,unaff_DI,unaff_SI), (uVar1 & 0xff) != 0 &&
          ((uVar1 = save_readBlock(-0x7663,(void *)0x22410,unaff_DI,unaff_SI), (uVar1 & 0xff) != 0
           && (uVar1 = save_readBlock(-0x6f69,(void *)0x22410,unaff_DI,unaff_SI),
              (uVar1 & 0xff) != 0)))))) &&
        ((uVar1 = save_readBlock((int)Entities,(void *)CONCAT22(EntityCount * 0x37,DAT_2000_d190),
                                 unaff_DI,unaff_SI), (uVar1 & 0xff) != 0 &&
         (uVar1 = save_readBlock(0x881,(void *)0x22410,unaff_DI,unaff_SI), (uVar1 & 0xff) != 0))))))
    {
      uVar5 = (undefined2)((ulong)((long)SquareRecCount * 0x13) >> 0x10);
      uVar1 = save_readBlock(0,(void *)CONCAT22((int)((long)SquareRecCount * 0x13),
                                                (void *)((int)&AgntAnms[0x7c].halfWidth + 1)),
                             unaff_DI,unaff_SI);
      if (((uVar1 & 0xff) != 0) &&
         (uVar1 = save_readBlock(-0x6f1a,(void *)0x12410,unaff_DI,unaff_SI), (uVar1 & 0xff) != 0)) {
        for (iVar2 = 0; iVar2 < (int)(uint)GLeaderCount; iVar2 = iVar2 + 1) {
          pvVar3 = ovr_stshAlloc(0xae);
          ((undefined2 *)(iVar2 * 4))[1] = uVar5;
          *(undefined2 *)(iVar2 * 4) = (uint16_t)pvVar3;   /* hand fix: store of the far pointer's offset half */
          uVar1 = save_readBlock(*(int *)(iVar2 * 4),
                                 (void *)CONCAT22(0xae,(void *)((int *)(iVar2 * 4))[1]),unaff_DI,
                                 unaff_SI);
          if ((uVar1 & 0xff) == 0) goto L_save_49fd_01da_0800;
        }
        uVar1 = save_readBlock(0x4a12,(void *)0x42410,unaff_DI,unaff_SI);
        if (((((((((((uVar1 & 0xff) != 0) &&
                   (uVar1 = save_readBlock(-0x6f1b,(void *)0x12410,unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0)) &&
                  (uVar1 = save_readBlock(-0x6f1c,(void *)0x12410,unaff_DI,unaff_SI),
                  (uVar1 & 0xff) != 0)) &&
                 (((uVar1 = save_readBlock(-0x6e21,(void *)0x22410,unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0 &&
                   (uVar1 = save_readBlock(0,(char *)CONCAT22(GRecordCount * 0x12,
                                                              (char *)0x21f2),
                                           unaff_DI,unaff_SI), (uVar1 & 0xff) != 0)) &&
                  ((uVar1 = save_readBlock(-0x7667,(void *)0x22410,unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0 &&
                   ((uVar1 = save_readBlock((int)(unit_t *)GUnits,
                                            (void *)CONCAT22(GUnitCount * 9,(*(uint16_t *)((uint8_t *)&(GUnits) + 2))),unaff_DI,
                                            unaff_SI), (uVar1 & 0xff) != 0 &&
                    (uVar1 = save_readBlock(0x2f3,(void *)0x12410,unaff_DI,unaff_SI),
                    (uVar1 & 0xff) != 0)))))))) &&
                (uVar1 = save_readBlock(-0x6f62,(void *)0x12410,unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0)) &&
               ((((uVar1 = save_readBlock(-0x6f91,(void *)0x12410,unaff_DI,unaff_SI),
                  (uVar1 & 0xff) != 0 &&
                  (uVar1 = save_readBlock(-0x6f92,(void *)0x12410,unaff_DI,unaff_SI),
                  (uVar1 & 0xff) != 0)) &&
                 (uVar1 = save_readBlock(-0x6f97,(void *)0x42410,unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0)) &&
                ((uVar1 = save_readBlock(-0x6df0,(void *)0x12410,unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0 &&
                 (uVar1 = save_readBlock(-0x6f1d,(void *)0x12410,unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0)))))) &&
              (((uVar1 = save_readBlock(-0x6f93,(void *)0x12410,unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0 &&
                ((uVar1 = save_readBlock(0x2f4,(void *)0x12410,unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0 &&
                 (uVar1 = save_readBlock(-0x6f99,(void *)0x22410,unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0)))) &&
               (uVar1 = save_readBlock(-0x6f63,(void *)0x12410,unaff_DI,unaff_SI),
               (uVar1 & 0xff) != 0)))) &&
             ((((uVar1 = save_readBlock(0x5dcf,(void *)0x12410,unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0 &&
                (uVar1 = save_readBlock(0x5dd7,(void *)0x12410,unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0)) &&
               (uVar1 = save_readBlock(0x5ddf,(void *)0x12410,unaff_DI,unaff_SI),
               (uVar1 & 0xff) != 0)) &&
              (((uVar1 = save_readBlock(0x5de7,(void *)0x12410,unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0 &&
                (uVar1 = save_readBlock(-0x6d33,(void *)0x22410,unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0)) &&
               ((uVar1 = save_readBlock(-0x6d34,(void *)0x12410,unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0 &&
                ((uVar1 = save_readBlock(0x6a86,(void *)0x22410,unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0 &&
                 (uVar1 = save_readBlock(0x6a88,(void *)0x12410,unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0)))))))))) &&
            ((uVar1 = save_readBlock(0x439,(void *)0x12410,unaff_DI,unaff_SI), (uVar1 & 0xff) != 0
             && ((((uVar1 = save_readBlock(-0x766f,(void *)0x42410,unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0 &&
                   (uVar1 = save_readBlock(-0x7670,(void *)0x12410,unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0)) &&
                  (uVar1 = save_readBlock(0x693a,(void *)0x12410,unaff_DI,unaff_SI),
                  (uVar1 & 0xff) != 0)) &&
                 (((uVar1 = save_readBlock(-0x6d38,(void *)0x22410,unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0 &&
                   (uVar1 = save_readBlock(0x744,(void *)0x12410,unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0)) &&
                  ((uVar1 = save_readBlock(-0x6f65,(void *)0x12410,unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0 &&
                   ((uVar1 = save_readBlock(-0x6e1a,(void *)0x12410,unaff_DI,unaff_SI),
                    (uVar1 & 0xff) != 0 &&
                    (uVar1 = save_readBlock(-0x6e1c,(void *)0x22410,unaff_DI,unaff_SI),
                    (uVar1 & 0xff) != 0)))))))))))) &&
           ((uVar1 = save_readBlock(0x26df,(void *)0x42410,unaff_DI,unaff_SI), (uVar1 & 0xff) != 0
            && ((((uVar1 = save_readBlock(-0x6d3a,(void *)0x12410,unaff_DI,unaff_SI),
                  (uVar1 & 0xff) != 0 &&
                  (uVar1 = save_readBlock(-0x6d44,(void *)0xa2410,unaff_DI,unaff_SI),
                  (uVar1 & 0xff) != 0)) &&
                 (uVar1 = save_readBlock((int)&header,(void *)CONCAT22(0x28,unaff_SS),unaff_DI,
                                         unaff_SI), (uVar1 & 0xff) != 0)) &&
                (iVar2 = strcmp((char *)CONCAT22(unaff_SS,&header),
                                (char *)CONCAT22(SaveHeader.seg,SaveHeader.ofs)), iVar2 == 0)))))) {
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
  undefined2 in_DX;
  
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
  undefined2 uVar1;
  int unaff_SI;
  
  handle = StshHandles[0];
  if (StshHandles[0] < 0) {
    handle = ovr_open_wait_unlock_and_disk((char *)StshNames[0]);
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
  undefined2 in_AX;
  int iVar1;
  uint16_t uVar2;
  byte bVar3;
  int in_stack_00000004;
  
  if ((*(uint16_t *)((uint8_t *)&(buf) + 2)) == 0) {
    iVar1 = CONCAT11((char)((uint)in_AX >> 8),1);
  }
  else {
    uVar2 = write(in_stack_00000004,(void *)CONCAT22((void *)buf,handle),(*(uint16_t *)((uint8_t *)&(buf) + 2)));
    bVar3 = (byte)(uVar2 >> 8);
    if (uVar2 == (*(uint16_t *)((uint8_t *)&(buf) + 2))) {
      iVar1 = CONCAT11(bVar3,1);
    }
    else {
      iVar1 = (uint)bVar3 << 8;
    }
  }
  return iVar1;
}



/* 49fd:090f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl16far stSave(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined2 in_DX;
  uint16_t unaff_SI;
  uint16_t unaff_DI;
  int iVar6;
  
  ovr_drawTextAt((char *)"Saving...",0x2410,0xa000);
  ovr_stop_audio();
  pcVar1 = ovr_fmVsprintf("%ssave.%03d",&GWorkDir);
  iVar2 = ovr_creat_wait_unlock_and_disk(pcVar1,in_DX);
  if (-1 < iVar2) {
    uVar3 = save_writeBlock(SaveHeader.ofs,(void *)CONCAT22(0x28,SaveHeader.seg),unaff_DI,unaff_SI);
    if ((((((uVar3 & 0xff) != 0) &&
          (uVar3 = save_writeBlock((int)(short (*) [148] [60])GUnitGrid,
                                   (void *)CONCAT22(0x4560,(*(uint16_t *)((uint8_t *)&(GUnitGrid) + 2))),unaff_DI,unaff_SI),
          (uVar3 & 0xff) != 0)) &&
         (uVar3 = save_writeBlock((int)(short (*) [60] [148])GMapFlags,
                                  (void *)CONCAT22(0x4560,(*(uint16_t *)((uint8_t *)&(GMapFlags) + 2))),unaff_DI,unaff_SI),
         (uVar3 & 0xff) != 0)) &&
        ((uVar3 = save_writeBlock((int)(byte (*) [59] [148])GMapCells,
                                  (void *)CONCAT22(0x22b0,(*(uint16_t *)((uint8_t *)&(GMapCells) + 2))),unaff_DI,unaff_SI),
         (uVar3 & 0xff) != 0 &&
         (uVar3 = save_writeBlock(-0x7661,(void *)0x22410,unaff_DI,unaff_SI), (uVar3 & 0xff) != 0)))
        ) && ((uVar3 = save_writeBlock(-0x7663,(void *)0x22410,unaff_DI,unaff_SI),
              (uVar3 & 0xff) != 0 &&
              (uVar3 = save_writeBlock(-0x6f69,(void *)0x22410,unaff_DI,unaff_SI),
              (uVar3 & 0xff) != 0)))) {
      in_DX = (undefined2)((ulong)((long)EntityCount * 0x37) >> 0x10);
      uVar3 = save_writeBlock((int)Entities,
                              (void *)CONCAT22((int)((long)EntityCount * 0x37),DAT_2000_d190),
                              unaff_DI,unaff_SI);
      if (((uVar3 & 0xff) != 0) &&
         (uVar3 = save_writeBlock(0x881,(void *)0x22410,unaff_DI,unaff_SI), (uVar3 & 0xff) != 0)) {
        in_DX = (undefined2)((ulong)((long)SquareRecCount * 0x13) >> 0x10);
        uVar3 = save_writeBlock(0,(void *)CONCAT22((int)((long)SquareRecCount * 0x13),
                                                   (void *)((int)&AgntAnms[0x7c].halfWidth + 1)),
                                unaff_DI,unaff_SI);
        if (((uVar3 & 0xff) != 0) &&
           (uVar3 = save_writeBlock(-0x6f1a,(void *)0x12410,unaff_DI,unaff_SI), (uVar3 & 0xff) != 0)
           ) {
          for (iVar6 = 0; iVar6 < (int)(uint)GLeaderCount; iVar6 = iVar6 + 1) {
            uVar3 = save_writeBlock(*(int *)(iVar6 * 4),
                                    (void *)CONCAT22(0xae,(void *)((int *)(iVar6 * 4))[1]),unaff_DI,
                                    unaff_SI);
            if ((uVar3 & 0xff) == 0) goto L_stSave_0EE6;
          }
          uVar3 = save_writeBlock(0x4a12,(void *)0x42410,unaff_DI,unaff_SI);
          if (((((uVar3 & 0xff) != 0) &&
               (uVar3 = save_writeBlock(-0x6f1b,(void *)0x12410,unaff_DI,unaff_SI),
               (uVar3 & 0xff) != 0)) &&
              (uVar3 = save_writeBlock(-0x6f1c,(void *)0x12410,unaff_DI,unaff_SI),
              (uVar3 & 0xff) != 0)) &&
             (uVar3 = save_writeBlock(-0x6e21,(void *)0x22410,unaff_DI,unaff_SI),
             (uVar3 & 0xff) != 0)) {
            in_DX = (undefined2)((ulong)((long)GRecordCount * 0x12) >> 0x10);
            uVar3 = save_writeBlock(0,(char *)CONCAT22((int)((long)GRecordCount * 0x12),
                                                       (char *)0x21f2),unaff_DI,
                                    unaff_SI);
            if (((uVar3 & 0xff) != 0) &&
               (uVar3 = save_writeBlock(-0x7667,(void *)0x22410,unaff_DI,unaff_SI),
               (uVar3 & 0xff) != 0)) {
              in_DX = (undefined2)((ulong)((long)GUnitCount * 9) >> 0x10);
              uVar3 = save_writeBlock((int)(unit_t *)GUnits,
                                      (void *)CONCAT22((int)((long)GUnitCount * 9),(*(uint16_t *)((uint8_t *)&(GUnits) + 2))),
                                      unaff_DI,unaff_SI);
              if ((((uVar3 & 0xff) != 0) &&
                  ((uVar3 = save_writeBlock(0x2f3,(void *)0x12410,unaff_DI,unaff_SI),
                   (uVar3 & 0xff) != 0 &&
                   (uVar3 = save_writeBlock(-0x6f62,(void *)0x12410,unaff_DI,unaff_SI),
                   (uVar3 & 0xff) != 0)))) &&
                 (((uVar3 = save_writeBlock(-0x6f91,(void *)0x12410,unaff_DI,unaff_SI),
                   (uVar3 & 0xff) != 0 &&
                   ((((((uVar3 = save_writeBlock(-0x6f92,(void *)0x12410,unaff_DI,unaff_SI),
                        (uVar3 & 0xff) != 0 &&
                        (uVar3 = save_writeBlock(-0x6f97,(void *)0x42410,unaff_DI,unaff_SI),
                        (uVar3 & 0xff) != 0)) &&
                       (uVar3 = save_writeBlock(-0x6df0,(void *)0x12410,unaff_DI,unaff_SI),
                       (uVar3 & 0xff) != 0)) &&
                      (((uVar3 = save_writeBlock(-0x6f1d,(void *)0x12410,unaff_DI,unaff_SI),
                        (uVar3 & 0xff) != 0 &&
                        (uVar3 = save_writeBlock(-0x6f93,(void *)0x12410,unaff_DI,unaff_SI),
                        (uVar3 & 0xff) != 0)) &&
                       ((uVar3 = save_writeBlock(0x2f4,(void *)0x12410,unaff_DI,unaff_SI),
                        (uVar3 & 0xff) != 0 &&
                        ((uVar3 = save_writeBlock(-0x6f99,(void *)0x22410,unaff_DI,unaff_SI),
                         (uVar3 & 0xff) != 0 &&
                         (uVar3 = save_writeBlock(-0x6f63,(void *)0x12410,unaff_DI,unaff_SI),
                         (uVar3 & 0xff) != 0)))))))) &&
                     (uVar3 = save_writeBlock(0x5dcf,(void *)0x12410,unaff_DI,unaff_SI),
                     (uVar3 & 0xff) != 0)) &&
                    ((((((uVar3 = save_writeBlock(0x5dd7,(void *)0x12410,unaff_DI,unaff_SI),
                         (uVar3 & 0xff) != 0 &&
                         (uVar3 = save_writeBlock(0x5ddf,(void *)0x12410,unaff_DI,unaff_SI),
                         (uVar3 & 0xff) != 0)) &&
                        (uVar3 = save_writeBlock(0x5de7,(void *)0x12410,unaff_DI,unaff_SI),
                        (uVar3 & 0xff) != 0)) &&
                       ((uVar3 = save_writeBlock(-0x6d33,(void *)0x22410,unaff_DI,unaff_SI),
                        (uVar3 & 0xff) != 0 &&
                        (uVar3 = save_writeBlock(-0x6d34,(void *)0x12410,unaff_DI,unaff_SI),
                        (uVar3 & 0xff) != 0)))) &&
                      (uVar3 = save_writeBlock(0x6a86,(void *)0x22410,unaff_DI,unaff_SI),
                      (uVar3 & 0xff) != 0)) &&
                     ((uVar3 = save_writeBlock(0x6a88,(void *)0x12410,unaff_DI,unaff_SI),
                      (uVar3 & 0xff) != 0 &&
                      (uVar3 = save_writeBlock(0x439,(void *)0x12410,unaff_DI,unaff_SI),
                      (uVar3 & 0xff) != 0)))))))) &&
                  ((((uVar3 = save_writeBlock(-0x766f,(void *)0x42410,unaff_DI,unaff_SI),
                     (uVar3 & 0xff) != 0 &&
                     (((uVar3 = save_writeBlock(-0x7670,(void *)0x12410,unaff_DI,unaff_SI),
                       (uVar3 & 0xff) != 0 &&
                       (uVar3 = save_writeBlock(0x693a,(void *)0x12410,unaff_DI,unaff_SI),
                       (uVar3 & 0xff) != 0)) &&
                      (uVar3 = save_writeBlock(-0x6d38,(void *)0x22410,unaff_DI,unaff_SI),
                      (uVar3 & 0xff) != 0)))) &&
                    (((uVar3 = save_writeBlock(0x744,(void *)0x12410,unaff_DI,unaff_SI),
                      (uVar3 & 0xff) != 0 &&
                      (uVar3 = save_writeBlock(-0x6f65,(void *)0x12410,unaff_DI,unaff_SI),
                      (uVar3 & 0xff) != 0)) &&
                     (uVar3 = save_writeBlock(-0x6e1a,(void *)0x12410,unaff_DI,unaff_SI),
                     (uVar3 & 0xff) != 0)))) &&
                   (((uVar3 = save_writeBlock(-0x6e1c,(void *)0x22410,unaff_DI,unaff_SI),
                     (uVar3 & 0xff) != 0 &&
                     (uVar3 = save_writeBlock(0x26df,(void *)0x42410,unaff_DI,unaff_SI),
                     (uVar3 & 0xff) != 0)) &&
                    ((uVar3 = save_writeBlock(-0x6d3a,(void *)0x12410,unaff_DI,unaff_SI),
                     (uVar3 & 0xff) != 0 &&
                     ((uVar3 = save_writeBlock(-0x6d44,(void *)0xa2410,unaff_DI,unaff_SI),
                      (uVar3 & 0xff) != 0 &&
                      (uVar3 = save_writeBlock(SaveHeader.ofs,(void *)CONCAT22(0x28,SaveHeader.seg),
                                               unaff_DI,unaff_SI), (uVar3 & 0xff) != 0)))))))))))) {
                iVar2 = close(iVar2);
                uVar4 = (undefined1)((uint)iVar2 >> 8);
                ovr_drawTextAt((char *)"Save complete.",0x2410,0xa000);
                return CONCAT11(uVar4,1);
              }
            }
          }
        }
      }
    }
L_stSave_0EE6:
    close(iVar2);
    pcVar1 = ovr_fmVsprintf("%ssave.%03d",&GWorkDir);
    iVar2 = unlink((char *)CONCAT22(in_DX,pcVar1));
  }
  bVar5 = (byte)((uint)iVar2 >> 8);
  ovr_drawTextAt((char *)"Save Error",0x2410,0xa000);
  return (uint)bVar5 << 8;
}



/* 49fd:0f26 */

/* Deletes the save slot file save.NNN after the "Deleting..." prompt. */

void __cdecl16far save_deleteGameFile(void)

{
  char *pcVar1;
  undefined2 in_DX;
  
  ovr_drawTextAt((char *)"Deleting...",0x2410,0xa000);
  pcVar1 = ovr_fmVsprintf("%ssave.%03d",&GWorkDir);
  unlink((char *)CONCAT22(in_DX,pcVar1));
  ovr_drawTextAt((char *)"Delete complete.",0x2410,0xa000);
  return;
}


