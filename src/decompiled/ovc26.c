/*
 * ovc26.c - recovered from STRONG.EXE
 * memory block: OVC26
 * range: 5d45:0000 - 5d45:0a7f
 * functions: 3
 */
#include "recovered.h"


/* 5d45:0000 */

/* [R6] touches FillGrid */

void __cdecl16far ovc26_usesFillGrid(int x,int y,uint8_t ignoreBlocked)

{
  int x_00;
  int y_00;
  int *piVar1;
  undefined2 uVar2;
  int *piVar3;
  undefined2 uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined2 unaff_SS;
  uint8_t nextQueueY;
  uint8_t nextQueueX;
  uint8_t fillQueueY;
  uint8_t fillQueueX;
  byte bStack_1f;
  int *piStack_1e;
  undefined2 uVar11;
  int *piStack_1a;
  undefined2 uVar12;
  int *piStack_12;
  undefined2 uVar13;
  int *piStack_e;
  int iStack_a;
  int iStack_8;
  
  _fmemset((void *)FillGrid,(*(uint16_t *)((uint8_t *)&(FillGrid) + 2)),0);
  iVar7 = 0x50 - x;
  iVar8 = 0x50 - y;
  iStack_a = 1;
  _piStack_1a = (int *)CONCAT22(unaff_SS,&fillQueueX);
  _piStack_1e = (int *)CONCAT22(unaff_SS,&fillQueueY);
  piStack_e = (int *)&nextQueueX;
  piStack_12 = (int *)&nextQueueY;
  *(undefined1 *)((int)FillGrid + (x + iVar7) * 0xa1 + y + iVar8) = 1;
  *_piStack_1a = x;
  *_piStack_1e = y;
  bStack_1f = 2;
  uVar13 = unaff_SS;
  while( true ) {
    piVar6 = piStack_e;
    piVar5 = piStack_12;
    piVar3 = _piStack_1a;
    if (0x50 < bStack_1f) {
      return;
    }
    iVar10 = 0;
    iStack_8 = 0;
    while( true ) {
      piVar1 = _piStack_1e;
      piStack_1a = (int *)piVar3;
      uVar12 = (undefined2)((ulong)piVar3 >> 0x10);
      uVar4 = uVar12;
      uVar11 = (undefined2)((ulong)_piStack_1e >> 0x10);
      uVar2 = uVar11;
      if (iStack_a <= iStack_8) break;
      x_00 = piStack_1a[iStack_8];
      y_00 = piStack_1e[iStack_8];
      _piStack_1e = piVar1;
      if (((*(char *)((x_00 + iVar7) * 0xa1 + (int)(void *)FillGrid + y_00 + iVar8 + -0xa1) == '\0')
          && (uVar9 = ovr_attact_usesSCARRY2(x_00,y_00,3,ignoreBlocked), (uVar9 & 0xff) == 0)) &&
         (iVar10 < 300)) {
        *(byte *)((x_00 + iVar7) * 0xa1 + (int)(void *)FillGrid + y_00 + iVar8 + -0xa1) = bStack_1f;
        piStack_e[iVar10] = x_00 + -1;
        piStack_12[iVar10] = y_00;
        iVar10 = iVar10 + 1;
      }
      if (((*(char *)((x_00 + iVar7) * 0xa1 + (int)(void *)FillGrid + y_00 + iVar8 + 0xa1) == '\0')
          && (uVar9 = ovr_attact_usesSCARRY2(x_00,y_00,1,ignoreBlocked), (uVar9 & 0xff) == 0)) &&
         (iVar10 < 300)) {
        *(byte *)((x_00 + iVar7) * 0xa1 + (int)(void *)FillGrid + y_00 + iVar8 + 0xa1) = bStack_1f;
        piStack_e[iVar10] = x_00 + 1;
        piStack_12[iVar10] = y_00;
        iVar10 = iVar10 + 1;
      }
      if (((*(char *)((int)FillGrid + (x_00 + iVar7) * 0xa1 + y_00 + iVar8 + -1) == '\0') &&
          (uVar9 = ovr_attact_usesSCARRY2(x_00,y_00,0,ignoreBlocked), (uVar9 & 0xff) == 0)) &&
         (iVar10 < 300)) {
        *(byte *)((int)FillGrid + (x_00 + iVar7) * 0xa1 + y_00 + iVar8 + -1) = bStack_1f;
        piStack_e[iVar10] = x_00;
        piStack_12[iVar10] = y_00 + -1;
        iVar10 = iVar10 + 1;
      }
      if (((*(char *)((int)FillGrid + (x_00 + iVar7) * 0xa1 + y_00 + iVar8 + 1) == '\0') &&
          (uVar9 = ovr_attact_usesSCARRY2(x_00,y_00,2,ignoreBlocked), (uVar9 & 0xff) == 0)) &&
         (iVar10 < 300)) {
        *(byte *)((int)FillGrid + (x_00 + iVar7) * 0xa1 + y_00 + iVar8 + 1) = bStack_1f;
        piStack_e[iVar10] = x_00;
        piStack_12[iVar10] = y_00 + 1;
        iVar10 = iVar10 + 1;
      }
      iStack_8 = iStack_8 + 1;
    }
    if (iVar10 == 0) break;
    piStack_e = piStack_1a;
    _piStack_1a = (int *)CONCAT22(unaff_SS,piVar6);
    piStack_12 = piStack_1e;
    _piStack_1e = (int *)CONCAT22(uVar13,piVar5);
    bStack_1f = bStack_1f + 1;
    iStack_a = iVar10;
    unaff_SS = uVar4;
    uVar13 = uVar2;
  }
  return;
}



/* 5d45:031f */

/* [R4] calls ovr_stExit */

uint __cdecl16far ovc26_usesStExit(int entityIndex)

{
  byte *pbVar1;
  uint16_t v;
  char *pcVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  entity_t *peVar10;
  char *pcVar11;
  undefined2 uVar12;
  undefined2 unaff_SS;
  uint8_t pathDirs [80];
  int iStack_1e;
  int iStack_1c;
  int iStack_1a;
  int iStack_18;
  byte bStack_10;
  byte bStack_f;
  uint uStack_c;
  undefined4 uStack_a;
  char *pcStack_6;
  
  v = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
  peVar10 = (entity_t *)Entities + entityIndex;
  uStack_a = (entity_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),peVar10);
  uVar4 = GameTick - peVar10->tick;
  if (uVar4 < 0x19) {
    uVar4 = uVar4 & 0xff00;
  }
  else {
    debugStaleTickCount = debugStaleTickCount + 1;
    ovc26_usesFillGrid((uStack_a->base).x,(peVar10->base).y,
                       *(uint8_t *)
                        ((int)(char **)GMenuStrings + (uint)(peVar10->base).gindex * 0x95 + 0x1f));
    iVar5 = (peVar10->base).destX - ((uStack_a->base).x - 0x50);
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    if (0xa0 < iVar5) {
      iVar5 = 0xa0;
    }
    iVar6 = (peVar10->base).destY - ((peVar10->base).y - 0x50);
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    if (0xa0 < iVar6) {
      iVar6 = 0xa0;
    }
    uVar12 = (undefined2)((ulong)FillGrid >> 0x10);
    pcVar11 = (char *)FillGrid;
    if (pcVar11[iVar6 + iVar5 * 0xa1] == '\0') {
      debugEmptyCellCount = debugEmptyCellCount + 1;
      uStack_c = 0xffff;
      pcStack_6 = FillGrid;
      for (iVar5 = 0; iVar5 < 0xa1; iVar5 = iVar5 + 1) {
        for (iVar6 = 0; pcVar2 = pcStack_6, iVar6 < 0xa1; iVar6 = iVar6 + 1) {
          pcStack_6 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(pcStack_6) + 2)),(char *)pcStack_6 + 1);
          if ((*pcVar2 != '\0') &&
             (uVar4 = (((peVar10->base).x - 0x50) - (peVar10->base).destX) + iVar5,
             uVar8 = (int)uVar4 >> 0xf,
             uVar7 = (((peVar10->base).y - 0x50) - (peVar10->base).destY) + iVar6,
             uVar9 = (int)uVar7 >> 0xf,
             uVar4 = ((uVar4 ^ uVar8) - uVar8) + ((uVar7 ^ uVar9) - uVar9), uVar4 < uStack_c)) {
            iStack_1a = iVar6;
            iStack_18 = iVar5;
            uStack_c = uVar4;
          }
        }
      }
      iVar6 = iStack_1a;
      iVar5 = iStack_18;
      if (uStack_c == 0xffff) {
        (peVar10->base).faction = 0x0;
        *(undefined1 *)&(peVar10->base).state = 0;
        uVar4 = GameTick;
        peVar10->tick = GameTick;
        return uVar4 & 0xff00;
      }
    }
    if ((iVar5 == 0x50) && (iVar6 == 0x50)) {
      (peVar10->base).faction = 0x0;
      *(undefined1 *)&(peVar10->base).state = 0;
      uVar4 = GameTick;
      peVar10->tick = GameTick;
      uVar4 = uVar4 & 0xff00;
    }
    else {
      bStack_f = 0;
      while (pcVar11[iVar6 + iVar5 * 0xa1] != '\x01') {
        bStack_10 = 0;
        while ((bStack_10 < 4 &&
               ((((SCARRY2(iVar5,(int)*(char *)(bStack_10 + 0x885)) !=
                   iVar5 + *(char *)(bStack_10 + 0x885) < 0 ||
                  (0xa0 < iVar5 + *(char *)(bStack_10 + 0x885))) ||
                 (SCARRY2(iVar6,(int)*(char *)(bStack_10 + 0x889)) !=
                  iVar6 + *(char *)(bStack_10 + 0x889) < 0)) ||
                ((0xa0 < iVar6 + *(char *)(bStack_10 + 0x889) ||
                 ((byte)pcVar11[(int)*(char *)(bStack_10 + 0x889) +
                                iVar6 + (iVar5 + *(char *)(bStack_10 + 0x885)) * 0xa1] + 1 !=
                  (uint)(byte)pcVar11[iVar6 + iVar5 * 0xa1]))))))) {
          bStack_10 = bStack_10 + 1;
        }
        if (3 < bStack_10) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x19);
        }
        pathDirs[bStack_f] = bStack_10 ^ 2;
        bStack_f = bStack_f + 1;
        iVar5 = iVar5 + *(char *)(bStack_10 + 0x885);
        iVar6 = iVar6 + *(char *)(bStack_10 + 0x889);
      }
      if (bStack_f == 0) {
        (peVar10->base).faction = 0x0;
        *(undefined1 *)&(peVar10->base).state = 0;
        uVar4 = GameTick;
        peVar10->tick = GameTick;
        uVar4 = uVar4 & 0xff00;
      }
      else {
        _fmemset(&(peVar10->base).owner,v,0);
        *(byte *)&(peVar10->base).state = bStack_f;
        iStack_1c = 0;
        iVar5 = bStack_f - 1;
        for (iStack_1e = iVar5; -1 < iStack_1e; iStack_1e = iStack_1e + -1) {
          bVar3 = pathDirs[iStack_1e] << (((byte)iStack_1c & 3) << 1);
          iVar5 = CONCAT11((char)((uint)pathDirs >> 8),bVar3);
          pbVar1 = (byte *)((int)&(peVar10->base).owner + (iStack_1c >> 2));
          *pbVar1 = *pbVar1 | bVar3;
          iStack_1c = iStack_1c + 1;
        }
        (peVar10->base).faction = 0x0;
        uVar4 = CONCAT11((char)((uint)iVar5 >> 8),1);
      }
    }
  }
  return uVar4;
}



/* 5d45:06f0 */

/* [R4] calls ovr_randBelow */

uint __cdecl16far
ovc26_usesRandBelow(int entityIndex,uint16_t outFlag,uint16_t outFlagSeg,uint16_t flagsOfs,
                   uint16_t flagsSeg)

{
  byte *pbVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  uint16_t destX;
  uint16_t destY;
  byte bVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  uint16_t uVar8;
  undefined1 uVar9;
  entity_t *peVar10;
  undefined2 uVar11;
  short *psStack_c;
  byte bStack_7;
  
  uVar11 = (undefined2)((ulong)Entities >> 0x10);
  peVar10 = (entity_t *)Entities;
  if (*(char *)((int)(char **)GMenuStrings + (uint)peVar10[entityIndex].base.gindex * 0x95 + 0x1f)
      == '\0') {
    uVar5 = 0;
  }
  else {
    uVar5 = (uint)peVar10[entityIndex].base.gindex * 0x95;
    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + uVar5) & 0x80) == 0) {
      if (*(char *)((int)&peVar10[entityIndex].base.entity + 1) == '\0') {
        uVar2 = ((peVar10 + entityIndex)->base).x;
        uVar3 = peVar10[entityIndex].base.y;
        destX = peVar10[entityIndex].base.destX;
        destY = peVar10[entityIndex].base.destY;
        iVar6 = ovr_ovc07_signum(peVar10[entityIndex].base.destX - uVar2);
        psStack_c = (short *)ovr_ovc07_signum(((entity_t *)Entities)[entityIndex].base.destY - uVar3
                                             );
        psVar7 = psStack_c;
        if ((iVar6 != 0) &&
           (psVar7 = (*(short (*) [60] [148])GMapFlags)[uVar3] + uVar2 + iVar6,
           (psVar7[0x94] & 3U) == 0)) {
          iVar6 = 0;
        }
        if ((psStack_c != (short *)0x0) &&
           (psVar7 = (*(short (*) [60] [148])GMapFlags)[uVar3 + (int)psStack_c] + uVar2,
           (psVar7[0x94] & 3U) == 0)) {
          psStack_c = (short *)0x0;
        }
        if ((iVar6 == 0) && (psStack_c == (short *)0x0)) {
          uVar5 = (uint)psVar7 & 0xff00;
        }
        else {
          if ((iVar6 != 0) && (iVar6 != 0)) {
            uVar8 = ovr_randBelow(2);
            if ((uVar8 & 0xff) == 0) {
              iVar6 = 0;
            }
            else {
              psStack_c = (short *)0x0;
            }
          }
          if (iVar6 == 0) {
            bStack_7 = 0xa1;
          }
          else {
            bStack_7 = 0xa0;
          }
          bVar4 = ovr_ovc45_getUnitType(uVar2 + iVar6,uVar3 + (int)psStack_c);
          if ((*(byte *)((uint)bVar4 * 0x27 + 0x11e) & 0xc) == 0) {
            ovr_createConstructionRecordFar
                      (bStack_7,uVar2 + iVar6,uVar3 + (int)psStack_c,(uint8_t *)outFlag,
                       (byte)outFlagSeg,
                       *(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3));
            ovr_attact_usesEntities
                      (entityIndex,uVar2 + iVar6,uVar3 + (int)psStack_c,flagsOfs,flagsSeg);
            ((entity_t *)Entities)[entityIndex].base.targetX = uVar2 + iVar6;
            ((entity_t *)Entities)[entityIndex].base.targetY = uVar3 + (int)psStack_c;
            pbVar1 = (byte *)((int)&((entity_t *)Entities)[entityIndex].base.flags32 + 1);
            *pbVar1 = *pbVar1 | 2;
            pbVar1 = (byte *)((int)&((entity_t *)Entities)[entityIndex].base.flags32 + 1);
            *pbVar1 = *pbVar1 & 0xfa;
            uVar9 = (undefined1)((uint)(entityIndex * 0x37) >> 8);
            ovr_ovc25_usesAlignUp44
                      (*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3),1,destX,
                       destY);
            uVar5 = CONCAT11(uVar9,1);
          }
          else {
            uVar5 = 0;
          }
        }
      }
      else {
        uVar5 = entityIndex * 0x37 & 0xff00;
      }
    }
    else {
      uVar5 = uVar5 & 0xff00;
    }
  }
  return uVar5;
}


