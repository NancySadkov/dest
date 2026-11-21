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
  int iVar1;
  int x_00;
  int *piVar2;
  undefined2 uVar3;
  int *piVar4;
  undefined2 uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint16_t unaff_DI;
  undefined2 unaff_SS;
  uint8_t nextQueueY;
  uint8_t nextQueueX;
  uint8_t fillQueueY;
  uint8_t fillQueueX;
  byte bStack_1f;
  int *piStack_1e;
  undefined2 uVar12;
  int *piStack_1a;
  undefined2 uVar13;
  int *piStack_12;
  undefined2 uVar14;
  int *piStack_e;
  int iStack_a;
  int iStack_8;
  
  _fmemset((void *)(FillGrid >> 0x10),0x6541,unaff_DI);
  iVar8 = 0x50 - x;
  iVar9 = 0x50 - y;
  iStack_a = 1;
  piStack_1a = (int *)CONCAT22(unaff_SS,&fillQueueX);
  piStack_1e = (int *)CONCAT22(unaff_SS,&fillQueueY);
  piStack_e = (int *)&nextQueueX;
  piStack_12 = (int *)&nextQueueY;
  *(undefined1 *)((int)FillGrid + (x + iVar8) * 0xa1 + y + iVar9) = 1;
  *piStack_1a = x;
  *piStack_1e = y;
  bStack_1f = 2;
  uVar14 = unaff_SS;
  while( true ) {
    piVar7 = piStack_e;
    piVar6 = piStack_12;
    piVar4 = piStack_1a;
    if (0x50 < bStack_1f) {
      return;
    }
    iVar11 = 0;
    iStack_8 = 0;
    while( true ) {
      piVar2 = piStack_1e;
      piStack_1a = (int *)piVar4;
      uVar13 = (undefined2)((ulong)piVar4 >> 0x10);
      uVar5 = uVar13;
      uVar12 = (undefined2)((ulong)piStack_1e >> 0x10);
      uVar3 = uVar12;
      if (iStack_a <= iStack_8) break;
      iVar1 = piStack_1a[iStack_8];
      x_00 = piStack_1e[iStack_8];
      piStack_1e = piVar2;
      if (((*(char *)((iVar1 + iVar8) * 0xa1 + (int)FillGrid + x_00 + iVar9 + -0xa1) == '\0') &&
          (uVar10 = ovr_attact_usesSCARRY2(x_00,3,ignoreBlocked,(char)unaff_DI,iVar1),
          (uVar10 & 0xff) == 0)) && (iVar11 < 300)) {
        *(byte *)((iVar1 + iVar8) * 0xa1 + (int)FillGrid + x_00 + iVar9 + -0xa1) = bStack_1f;
        piStack_e[iVar11] = iVar1 + -1;
        piStack_12[iVar11] = x_00;
        iVar11 = iVar11 + 1;
      }
      if (((*(char *)((iVar1 + iVar8) * 0xa1 + (int)FillGrid + x_00 + iVar9 + 0xa1) == '\0') &&
          (uVar10 = ovr_attact_usesSCARRY2(x_00,1,ignoreBlocked,(char)unaff_DI,iVar1),
          (uVar10 & 0xff) == 0)) && (iVar11 < 300)) {
        *(byte *)((iVar1 + iVar8) * 0xa1 + (int)FillGrid + x_00 + iVar9 + 0xa1) = bStack_1f;
        piStack_e[iVar11] = iVar1 + 1;
        piStack_12[iVar11] = x_00;
        iVar11 = iVar11 + 1;
      }
      if (((*(char *)((int)FillGrid + (iVar1 + iVar8) * 0xa1 + x_00 + iVar9 + -1) == '\0') &&
          (uVar10 = ovr_attact_usesSCARRY2(x_00,0,ignoreBlocked,(char)unaff_DI,iVar1),
          (uVar10 & 0xff) == 0)) && (iVar11 < 300)) {
        *(byte *)((int)FillGrid + (iVar1 + iVar8) * 0xa1 + x_00 + iVar9 + -1) = bStack_1f;
        piStack_e[iVar11] = iVar1;
        piStack_12[iVar11] = x_00 + -1;
        iVar11 = iVar11 + 1;
      }
      if (((*(char *)((int)FillGrid + (iVar1 + iVar8) * 0xa1 + x_00 + iVar9 + 1) == '\0') &&
          (uVar10 = ovr_attact_usesSCARRY2(x_00,2,ignoreBlocked,(char)unaff_DI,iVar1),
          (uVar10 & 0xff) == 0)) && (iVar11 < 300)) {
        *(byte *)((int)FillGrid + (iVar1 + iVar8) * 0xa1 + x_00 + iVar9 + 1) = bStack_1f;
        piStack_e[iVar11] = iVar1;
        piStack_12[iVar11] = x_00 + 1;
        iVar11 = iVar11 + 1;
      }
      iStack_8 = iStack_8 + 1;
    }
    if (iVar11 == 0) break;
    piStack_e = piStack_1a;
    piStack_1a = (int *)CONCAT22(unaff_SS,piVar7);
    piStack_12 = piStack_1e;
    piStack_1e = (int *)CONCAT22(uVar14,piVar6);
    bStack_1f = bStack_1f + 1;
    iStack_a = iVar11;
    unaff_SS = uVar5;
    uVar14 = uVar3;
  }
  return;
}



/* 5d45:031f */

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
  int in_stack_00000004;
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
  
  uVar2 = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
  peVar11 = (entity_t *)Entities + in_stack_00000004;
  uStack_a = (entity_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),peVar11);
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
          ovr_stExit(unaff_DI,0x19);
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

/* [R4] calls ovr_randBelow */

uint __cdecl16far
ovc26_usesRandBelow(int entityIndex,uint16_t outFlag,uint16_t outFlagSeg,uint16_t flagsOfs,
                   uint16_t flagsSeg,...)

{
  byte *pbVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  uint16_t destX;
  int iVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  short *psVar9;
  uint16_t uVar10;
  entity_t *peVar11;
  char unaff_SI;
  uint16_t unaff_DI;
  undefined2 uVar12;
  int in_stack_00000004;
  short *psStack_c;
  undefined1 uStack_7;
  
  iVar5 = in_stack_00000004;
  uVar12 = (undefined2)((ulong)Entities >> 0x10);
  peVar11 = (entity_t *)Entities;
  if (*(char *)((int)(char **)GMenuStrings +
               (uint)peVar11[in_stack_00000004].base.gindex * 0x95 + 0x1f) == '\0') {
    uVar7 = 0;
  }
  else {
    uVar7 = (uint)peVar11[in_stack_00000004].base.gindex * 0x95;
    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + uVar7) & 0x80) == 0) {
      if (*(char *)((int)&peVar11[in_stack_00000004].base.entity + 1) == '\0') {
        uVar2 = ((peVar11 + in_stack_00000004)->base).x;
        uVar3 = peVar11[in_stack_00000004].base.y;
        uVar4 = peVar11[in_stack_00000004].base.destX;
        destX = peVar11[in_stack_00000004].base.destY;
        iVar8 = ovr_ovc07_signum();
        psStack_c = (short *)ovr_ovc07_signum();
        psVar9 = psStack_c;
        if ((iVar8 != 0) &&
           (psVar9 = (*(short (*) [60] [148])GMapFlags)[uVar3] + uVar2 + iVar8,
           (psVar9[0x94] & 3U) == 0)) {
          iVar8 = 0;
        }
        if ((psStack_c != (short *)0x0) &&
           (psVar9 = (*(short (*) [60] [148])GMapFlags)[uVar3 + (int)psStack_c] + uVar2,
           (psVar9[0x94] & 3U) == 0)) {
          psStack_c = (short *)0x0;
        }
        if ((iVar8 == 0) && (psStack_c == (short *)0x0)) {
          uVar7 = (uint)psVar9 & 0xff00;
        }
        else {
          if ((iVar8 != 0) && (iVar8 != 0)) {
            uVar10 = ovr_randBelow();
            if ((uVar10 & 0xff) == 0) {
              iVar8 = 0;
            }
            else {
              psStack_c = (short *)0x0;
            }
          }
          if (iVar8 == 0) {
            uStack_7 = 0xa1;
          }
          else {
            uStack_7 = 0xa0;
          }
          bVar6 = ovr_ovc45_getUnitType();
          if ((*(byte *)((uint)bVar6 * 0x27 + 0x11e) & 0xc) == 0) {
            ovr_createConstructionRecordFar
                      ((byte)(uVar2 + iVar8),uVar3 + (int)psStack_c,entityIndex,
                       (uint8_t *)
                       CONCAT22(CONCAT11((char)((uint)(iVar5 * 0x37) >> 8),
                                         *(undefined1 *)
                                          ((int)&((entity_t *)Entities)[iVar5].base.entity + 3)),
                                outFlag),(byte)unaff_DI,unaff_SI,
                       CONCAT11((char)(uVar2 + iVar8 >> 8),uStack_7));
            ovr_attact_usesEntities
                      (uVar2 + iVar8,uVar3 + (int)psStack_c,outFlagSeg,flagsOfs,unaff_DI,iVar5);
            ((entity_t *)Entities)[iVar5].base.targetX = uVar2 + iVar8;
            ((entity_t *)Entities)[iVar5].base.targetY = uVar3 + (int)psStack_c;
            pbVar1 = (byte *)((int)&((entity_t *)Entities)[iVar5].base.flags32 + 1);
            *pbVar1 = *pbVar1 | 2;
            pbVar1 = (byte *)((int)&((entity_t *)Entities)[iVar5].base.flags32 + 1);
            *pbVar1 = *pbVar1 & 0xfa;
            uVar12 = CONCAT11((char)((uint)(iVar5 * 0x37) >> 8),
                              *(undefined1 *)((int)&((entity_t *)Entities)[iVar5].base.entity + 3));
            ovr_ovc25_usesAlignUp44('\x01',(byte)uVar4,destX,unaff_DI,uVar12);
            uVar7 = CONCAT11((char)((uint)uVar12 >> 8),1);
          }
          else {
            uVar7 = 0;
          }
        }
      }
      else {
        uVar7 = in_stack_00000004 * 0x37 & 0xff00;
      }
    }
    else {
      uVar7 = uVar7 & 0xff00;
    }
  }
  return uVar7;
}


