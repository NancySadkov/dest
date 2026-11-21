/*
 * ovc26_fillgrid.c - recovered from STRONG.EXE
 * memory block: OVC26_fillgrid.c
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
  uint16_t unaff_DI;
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
  
  _fmemset((void *)(FillGrid >> 0x10),0x6541,unaff_DI);
  iVar7 = 0x50 - x;
  iVar8 = 0x50 - y;
  iStack_a = 1;
  piStack_1a = (int *)CONCAT22(unaff_SS,&fillQueueX);
  piStack_1e = (int *)CONCAT22(unaff_SS,&fillQueueY);
  piStack_e = (int *)&nextQueueX;
  piStack_12 = (int *)&nextQueueY;
  *(undefined1 *)((int)FillGrid + (x + iVar7) * 0xa1 + y + iVar8) = 1;
  *piStack_1a = x;
  *piStack_1e = y;
  bStack_1f = 2;
  uVar13 = unaff_SS;
  while( true ) {
    piVar6 = piStack_e;
    piVar5 = piStack_12;
    piVar3 = piStack_1a;
    if (0x50 < bStack_1f) {
      return;
    }
    iVar10 = 0;
    iStack_8 = 0;
    while( true ) {
      piVar1 = piStack_1e;
      piStack_1a = (int *)piVar3;
      uVar12 = (undefined2)((ulong)piVar3 >> 0x10);
      uVar4 = uVar12;
      uVar11 = (undefined2)((ulong)piStack_1e >> 0x10);
      uVar2 = uVar11;
      if (iStack_a <= iStack_8) break;
      x_00 = piStack_1a[iStack_8];
      y_00 = piStack_1e[iStack_8];
      piStack_1e = piVar1;
      if (((*(char *)((x_00 + iVar7) * 0xa1 + (int)FillGrid + y_00 + iVar8 + -0xa1) == '\0') &&
          (uVar9 = ovr_attact_usesSCARRY2(x_00,y_00,3,ignoreBlocked), (uVar9 & 0xff) == 0)) &&
         (iVar10 < 300)) {
        *(byte *)((x_00 + iVar7) * 0xa1 + (int)FillGrid + y_00 + iVar8 + -0xa1) = bStack_1f;
        piStack_e[iVar10] = x_00 + -1;
        piStack_12[iVar10] = y_00;
        iVar10 = iVar10 + 1;
      }
      if (((*(char *)((x_00 + iVar7) * 0xa1 + (int)FillGrid + y_00 + iVar8 + 0xa1) == '\0') &&
          (uVar9 = ovr_attact_usesSCARRY2(x_00,y_00,1,ignoreBlocked), (uVar9 & 0xff) == 0)) &&
         (iVar10 < 300)) {
        *(byte *)((x_00 + iVar7) * 0xa1 + (int)FillGrid + y_00 + iVar8 + 0xa1) = bStack_1f;
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
    piStack_1a = (int *)CONCAT22(unaff_SS,piVar6);
    piStack_12 = piStack_1e;
    piStack_1e = (int *)CONCAT22(uVar13,piVar5);
    bStack_1f = bStack_1f + 1;
    iStack_a = iVar10;
    unaff_SS = uVar4;
    uVar13 = uVar2;
  }
  return;
}



/* 5d45:031f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_stExit */

uint __cdecl16far ovc26_usesStExit(int entityIndex,...)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  entity_t *peVar11;
  char *pcVar12;
  uint16_t unaff_DI;
  undefined2 uVar13;
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
  
  uVar2 = DAT_2000_d190;
  peVar11 = Entities + entityIndex;
  uStack_a = (entity_t *)CONCAT22(DAT_2000_d190,peVar11);
  uVar5 = GameTick - peVar11->tick;
  if (uVar5 < 0x19) {
    uVar5 = uVar5 & 0xff00;
  }
  else {
    debugStaleTickCount = debugStaleTickCount + 1;
    ovc26_usesFillGrid((uStack_a->base).x,(peVar11->base).y,
                       *(uint8_t *)
                        ((int)(char **)GMenuStrings + (uint)(peVar11->base).gindex * 0x95 + 0x1f));
    iVar6 = (peVar11->base).destX - ((uStack_a->base).x - 0x50);
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    if (0xa0 < iVar6) {
      iVar6 = 0xa0;
    }
    iVar7 = (peVar11->base).destY - ((peVar11->base).y - 0x50);
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    if (0xa0 < iVar7) {
      iVar7 = 0xa0;
    }
    uVar13 = (undefined2)((ulong)FillGrid >> 0x10);
    pcVar12 = (char *)FillGrid;
    if (pcVar12[iVar7 + iVar6 * 0xa1] == '\0') {
      debugEmptyCellCount = debugEmptyCellCount + 1;
      uStack_c = 0xffff;
      pcStack_6 = FillGrid;
      for (iVar6 = 0; iVar6 < 0xa1; iVar6 = iVar6 + 1) {
        for (iVar7 = 0; pcVar3 = pcStack_6, iVar7 < 0xa1; iVar7 = iVar7 + 1) {
          pcStack_6 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(pcStack_6) + 2)),(char *)pcStack_6 + 1);
          if ((*pcVar3 != '\0') &&
             (uVar5 = (((peVar11->base).x - 0x50) - (peVar11->base).destX) + iVar6,
             uVar9 = (int)uVar5 >> 0xf,
             uVar8 = (((peVar11->base).y - 0x50) - (peVar11->base).destY) + iVar7,
             uVar10 = (int)uVar8 >> 0xf,
             uVar5 = ((uVar5 ^ uVar9) - uVar9) + ((uVar8 ^ uVar10) - uVar10), uVar5 < uStack_c)) {
            iStack_1a = iVar7;
            iStack_18 = iVar6;
            uStack_c = uVar5;
          }
        }
      }
      iVar7 = iStack_1a;
      iVar6 = iStack_18;
      if (uStack_c == 0xffff) {
        (peVar11->base).faction = 0x0;
        *(undefined1 *)&(peVar11->base).state = 0;
        uVar5 = GameTick;
        peVar11->tick = GameTick;
        return uVar5 & 0xff00;
      }
    }
    if ((iVar6 == 0x50) && (iVar7 == 0x50)) {
      (peVar11->base).faction = 0x0;
      *(undefined1 *)&(peVar11->base).state = 0;
      uVar5 = GameTick;
      peVar11->tick = GameTick;
      uVar5 = uVar5 & 0xff00;
    }
    else {
      bStack_f = 0;
      while (pcVar12[iVar7 + iVar6 * 0xa1] != '\x01') {
        bStack_10 = 0;
        while ((bStack_10 < 4 &&
               ((((SCARRY2(iVar6,(int)*(char *)(bStack_10 + 0x885)) !=
                   iVar6 + *(char *)(bStack_10 + 0x885) < 0 ||
                  (0xa0 < iVar6 + *(char *)(bStack_10 + 0x885))) ||
                 (SCARRY2(iVar7,(int)*(char *)(bStack_10 + 0x889)) !=
                  iVar7 + *(char *)(bStack_10 + 0x889) < 0)) ||
                ((0xa0 < iVar7 + *(char *)(bStack_10 + 0x889) ||
                 ((byte)pcVar12[(int)*(char *)(bStack_10 + 0x889) +
                                iVar7 + (iVar6 + *(char *)(bStack_10 + 0x885)) * 0xa1] + 1 !=
                  (uint)(byte)pcVar12[iVar7 + iVar6 * 0xa1]))))))) {
          bStack_10 = bStack_10 + 1;
        }
        if (3 < bStack_10) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x19);
        }
        pathDirs[bStack_f] = bStack_10 ^ 2;
        bStack_f = bStack_f + 1;
        iVar6 = iVar6 + *(char *)(bStack_10 + 0x885);
        iVar7 = iVar7 + *(char *)(bStack_10 + 0x889);
      }
      if (bStack_f == 0) {
        (peVar11->base).faction = 0x0;
        *(undefined1 *)&(peVar11->base).state = 0;
        uVar5 = GameTick;
        peVar11->tick = GameTick;
        uVar5 = uVar5 & 0xff00;
      }
      else {
        _fmemset((void *)(ulong)uVar2,0x14,unaff_DI);
        *(byte *)&(peVar11->base).state = bStack_f;
        iStack_1c = 0;
        iVar6 = bStack_f - 1;
        for (iStack_1e = iVar6; -1 < iStack_1e; iStack_1e = iStack_1e + -1) {
          bVar4 = pathDirs[iStack_1e] << (((byte)iStack_1c & 3) << 1);
          iVar6 = CONCAT11((char)((uint)pathDirs >> 8),bVar4);
          pbVar1 = (byte *)((int)&(peVar11->base).owner + (iStack_1c >> 2));
          *pbVar1 = *pbVar1 | bVar4;
          iStack_1c = iStack_1c + 1;
        }
        (peVar11->base).faction = 0x0;
        uVar5 = CONCAT11((char)((uint)iVar6 >> 8),1);
      }
    }
  }
  return uVar5;
}



/* 5d45:06f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_randBelow */

uint __cdecl16far
ovc26_usesRandBelow(int entityIndex,uint16_t outFlag,uint16_t outFlagSeg,uint16_t flagsOfs,
                   uint16_t flagsSeg,...)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint16_t destX;
  uint16_t destY;
  byte bVar4;
  uint uVar5;
  short *psVar6;
  uint16_t uVar7;
  undefined1 uVar8;
  int iVar9;
  char unaff_DI;
  undefined2 uVar10;
  short *psStack_c;
  byte bStack_7;
  
  uVar10 = (undefined2)((ulong)Entities >> 0x10);
  iVar9 = (int)Entities;
  if (*(char *)((int)(char **)GMenuStrings +
               (uint)*(byte *)(iVar9 + entityIndex * 0x37 + 0xd) * 0x95 + 0x1f) == '\0') {
    uVar5 = 0;
  }
  else {
    uVar5 = (uint)*(byte *)(iVar9 + entityIndex * 0x37 + 0xd) * 0x95;
    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + uVar5) & 0x80) == 0) {
      if (*(char *)(iVar9 + entityIndex * 0x37 + 0x18) == '\0') {
        iVar2 = *(int *)(iVar9 + entityIndex * 0x37);
        iVar3 = *(int *)(iVar9 + entityIndex * 0x37 + 2);
        destX = *(uint16_t *)(iVar9 + entityIndex * 0x37 + 8);
        destY = *(uint16_t *)(iVar9 + entityIndex * 0x37 + 10);
        iVar9 = ovr_ovc07_signum(*(int *)(iVar9 + entityIndex * 0x37 + 8) - iVar2);
        psStack_c = (short *)ovr_ovc07_signum(*(int *)((int)Entities + entityIndex * 0x37 + 10) -
                                              iVar3);
        psVar6 = psStack_c;
        if ((iVar9 != 0) &&
           (psVar6 = (*(short (*) [60] [148])GMapFlags)[iVar3] + iVar2 + iVar9,
           (psVar6[0x94] & 3U) == 0)) {
          iVar9 = 0;
        }
        if ((psStack_c != (short *)0x0) &&
           (psVar6 = (*(short (*) [60] [148])GMapFlags)[iVar3 + (int)psStack_c] + iVar2,
           (psVar6[0x94] & 3U) == 0)) {
          psStack_c = (short *)0x0;
        }
        if ((iVar9 == 0) && (psStack_c == (short *)0x0)) {
          uVar5 = (uint)psVar6 & 0xff00;
        }
        else {
          if ((iVar9 != 0) && (iVar9 != 0)) {
            uVar7 = ovr_randBelow(2);
            if ((uVar7 & 0xff) == 0) {
              iVar9 = 0;
            }
            else {
              psStack_c = (short *)0x0;
            }
          }
          if (iVar9 == 0) {
            bStack_7 = 0xa1;
          }
          else {
            bStack_7 = 0xa0;
          }
          bVar4 = ovr_ovc45_getUnitType(iVar2 + iVar9,iVar3 + (int)psStack_c);
          if ((*(byte *)((uint)bVar4 * 0x27 + 0x11e) & 0xc) == 0) {
            ovr_createConstructionRecordFar
                      (bStack_7,iVar2 + iVar9,iVar3 + (int)psStack_c,
                       (uint8_t *)CONCAT22(outFlagSeg,outFlag),
                       *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a),unaff_DI);
            ovr_attact_usesEntities
                      (entityIndex,iVar2 + iVar9,iVar3 + (int)psStack_c,flagsOfs,flagsSeg);
            *(int *)((int)Entities + entityIndex * 0x37 + 4) = iVar2 + iVar9;
            *(int *)((int)Entities + entityIndex * 0x37 + 6) = iVar3 + (int)psStack_c;
            pbVar1 = (byte *)((int)Entities + entityIndex * 0x37 + 0x33);
            *pbVar1 = *pbVar1 | 2;
            pbVar1 = (byte *)((int)Entities + entityIndex * 0x37 + 0x33);
            *pbVar1 = *pbVar1 & 0xfa;
            uVar8 = (undefined1)((uint)(entityIndex * 0x37) >> 8);
            ovr_ovc25_usesAlignUp44
                      (*(char *)((int)Entities + entityIndex * 0x37 + 0x1a),1,destX,destY);
            uVar5 = CONCAT11(uVar8,1);
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


