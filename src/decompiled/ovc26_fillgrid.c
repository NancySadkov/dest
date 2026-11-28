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
  int cellX;
  int cellY;
  int *savedCurY;
  uint16_t nextYSeg;
  int *savedCurX;
  uint16_t nextXSeg;
  int *savedNextY;
  int *savedNextX;
  int xOfs;
  int yOfs;
  uint blockedFlag;
  int nextCount;
  uint16_t curSeg = _SS;
  uint8_t nextQueueY;
  uint8_t nextQueueX;
  uint8_t fillQueueY;
  uint8_t fillQueueX;
  byte depth;
  int *curYQueue;
  uint16_t curYSeg;
  int *curXQueue;
  uint16_t curXSeg;
  int *nextYQueue;
  uint16_t yQueueSeg;
  int *nextXQueue;
  int queueLen;
  int queueIndex;
  
  _fmemset(MK_FP((uint16_t)(FillGrid >> 16), (uint16_t)FillGrid), 0, 0x6541);
  xOfs = 0x50 - x;
  yOfs = 0x50 - y;
  queueLen = 1;
  curXQueue = (int *)CONCAT22(curSeg,&fillQueueX);
  curYQueue = (int *)CONCAT22(curSeg,&fillQueueY);
  nextXQueue = (int *)&nextQueueX;
  nextYQueue = (int *)&nextQueueY;
  *(undefined1 *)((int)FillGrid + (x + xOfs) * 0xa1 + y + yOfs) = 1;
  *curXQueue = x;
  *curYQueue = y;
  depth = 2;
  yQueueSeg = curSeg;
  while( true ) {
    savedNextX = nextXQueue;
    savedNextY = nextYQueue;
    savedCurX = curXQueue;
    if (0x50 < depth) {
      return;
    }
    nextCount = 0;
    queueIndex = 0;
    while( true ) {
      savedCurY = curYQueue;
      curXQueue = (int *)savedCurX;
      curXSeg = (uint16_t)((ulong)savedCurX >> 0x10);
      nextXSeg = curXSeg;
      curYSeg = (uint16_t)((ulong)curYQueue >> 0x10);
      nextYSeg = curYSeg;
      if (queueLen <= queueIndex) break;
      cellX = curXQueue[queueIndex];
      cellY = curYQueue[queueIndex];
      curYQueue = savedCurY;
      if (((*(char *)((cellX + xOfs) * 0xa1 + (int)FillGrid + cellY + yOfs + -0xa1) == '\0') &&
          (blockedFlag = ovr_attact_usesSCARRY2(cellX,cellY,3,ignoreBlocked,0,0), (blockedFlag & 0xff) == 0)) &&
         (nextCount < 300)) {
        *(byte *)((cellX + xOfs) * 0xa1 + (int)FillGrid + cellY + yOfs + -0xa1) = depth;
        nextXQueue[nextCount] = cellX + -1;
        nextYQueue[nextCount] = cellY;
        nextCount = nextCount + 1;
      }
      if (((*(char *)((cellX + xOfs) * 0xa1 + (int)FillGrid + cellY + yOfs + 0xa1) == '\0') &&
          (blockedFlag = ovr_attact_usesSCARRY2(cellX,cellY,1,ignoreBlocked,0,0), (blockedFlag & 0xff) == 0)) &&
         (nextCount < 300)) {
        *(byte *)((cellX + xOfs) * 0xa1 + (int)FillGrid + cellY + yOfs + 0xa1) = depth;
        nextXQueue[nextCount] = cellX + 1;
        nextYQueue[nextCount] = cellY;
        nextCount = nextCount + 1;
      }
      if (((*(char *)((int)FillGrid + (cellX + xOfs) * 0xa1 + cellY + yOfs + -1) == '\0') &&
          (blockedFlag = ovr_attact_usesSCARRY2(cellX,cellY,0,ignoreBlocked,0,0), (blockedFlag & 0xff) == 0)) &&
         (nextCount < 300)) {
        *(byte *)((int)FillGrid + (cellX + xOfs) * 0xa1 + cellY + yOfs + -1) = depth;
        nextXQueue[nextCount] = cellX;
        nextYQueue[nextCount] = cellY + -1;
        nextCount = nextCount + 1;
      }
      if (((*(char *)((int)FillGrid + (cellX + xOfs) * 0xa1 + cellY + yOfs + 1) == '\0') &&
          (blockedFlag = ovr_attact_usesSCARRY2(cellX,cellY,2,ignoreBlocked,0,0), (blockedFlag & 0xff) == 0)) &&
         (nextCount < 300)) {
        *(byte *)((int)FillGrid + (cellX + xOfs) * 0xa1 + cellY + yOfs + 1) = depth;
        nextXQueue[nextCount] = cellX;
        nextYQueue[nextCount] = cellY + 1;
        nextCount = nextCount + 1;
      }
      queueIndex = queueIndex + 1;
    }
    if (nextCount == 0) break;
    nextXQueue = curXQueue;
    curXQueue = (int *)CONCAT22(curSeg,savedNextX);
    nextYQueue = curYQueue;
    curYQueue = (int *)CONCAT22(yQueueSeg,savedNextY);
    depth = depth + 1;
    queueLen = nextCount;
    curSeg = nextXSeg;
    yQueueSeg = nextYSeg;
  }
  return;
}



/* 5d45:031f */
uint __cdecl16far ovc26_usesStExit(int entityIndex)

{
  byte *flagByte;
  char *pcVar3;
  byte bits;
  uint uVar5;
  int row;
  int col;
  uint dy;
  uint dxSign;
  uint dySign;
  entity_t far *peVar11;
  char *fillGrid;
  uint16_t fillGridSeg;
  uint16_t curSeg = _SS;
  uint8_t pathDirs [80];
  int dirPos;
  int bitPos;
  int bestCol;
  int bestRow;
  byte dirIndex;
  byte dirCount;
  uint bestDist;
  char *cellPtr;
  
  peVar11 = Entities + entityIndex;
  uVar5 = GameTick - peVar11->tick;
  if (uVar5 < 0x19) {
    uVar5 = uVar5 & 0xff00;
  }
  else {
    debugStaleTickCount = debugStaleTickCount + 1;
    ovc26_usesFillGrid((peVar11->base).x,(peVar11->base).y,
                       AgntGs[(uint)(peVar11->base).gindex].ai);
    row = (peVar11->base).destX - ((peVar11->base).x - 0x50);
    if (row < 0) {
      row = 0;
    }
    if (0xa0 < row) {
      row = 0xa0;
    }
    col = (peVar11->base).destY - ((peVar11->base).y - 0x50);
    if (col < 0) {
      col = 0;
    }
    if (0xa0 < col) {
      col = 0xa0;
    }
    fillGridSeg = (uint16_t)((ulong)FillGrid >> 0x10);
    fillGrid = (char *)FillGrid;
    if (fillGrid[col + row * 0xa1] == '\0') {
      debugEmptyCellCount = debugEmptyCellCount + 1;
      bestDist = 0xffff;
      cellPtr = (uint16_t)FillGrid;
      for (row = 0; row < 0xa1; row = row + 1) {
        for (col = 0; pcVar3 = cellPtr, col < 0xa1; col = col + 1) {
          cellPtr = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(cellPtr) + 2)),(char *)cellPtr + 1);
          if ((*pcVar3 != '\0') &&
             (uVar5 = (((peVar11->base).x - 0x50) - (peVar11->base).destX) + row,
             dxSign = (int)uVar5 >> 0xf,
             dy = (((peVar11->base).y - 0x50) - (peVar11->base).destY) + col,
             dySign = (int)dy >> 0xf,
             uVar5 = ((uVar5 ^ dxSign) - dxSign) + ((dy ^ dySign) - dySign), uVar5 < bestDist)) {
            bestCol = col;
            bestRow = row;
            bestDist = uVar5;
          }
        }
      }
      col = bestCol;
      row = bestRow;
      if (bestDist == 0xffff) {
        (peVar11->base).faction = 0x0;
        *(undefined1 *)&(peVar11->base).state = 0;
        uVar5 = GameTick;
        peVar11->tick = GameTick;
        return uVar5 & 0xff00;
      }
    }
    if ((row == 0x50) && (col == 0x50)) {
      (peVar11->base).faction = 0x0;
      *(undefined1 *)&(peVar11->base).state = 0;
      uVar5 = GameTick;
      peVar11->tick = GameTick;
      uVar5 = uVar5 & 0xff00;
    }
    else {
      dirCount = 0;
      while (fillGrid[col + row * 0xa1] != '\x01') {
        dirIndex = 0;
        while ((dirIndex < 4 &&
               ((((SCARRY2(row,(int)*(char *)(dirIndex + 0x885)) !=
                   row + *(char *)(dirIndex + 0x885) < 0 ||
                  (0xa0 < row + *(char *)(dirIndex + 0x885))) ||
                 (SCARRY2(col,(int)*(char *)(dirIndex + 0x889)) !=
                  col + *(char *)(dirIndex + 0x889) < 0)) ||
                ((0xa0 < col + *(char *)(dirIndex + 0x889) ||
                 ((byte)fillGrid[(int)*(char *)(dirIndex + 0x889) +
                                col + (row + *(char *)(dirIndex + 0x885)) * 0xa1] + 1 !=
                  (uint)(byte)fillGrid[col + row * 0xa1]))))))) {
          dirIndex = dirIndex + 1;
        }
        if (3 < dirIndex) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x19);
        }
        pathDirs[dirCount] = dirIndex ^ 2;
        dirCount = dirCount + 1;
        row = row + *(char *)(dirIndex + 0x885);
        col = col + *(char *)(dirIndex + 0x889);
      }
      if (dirCount == 0) {
        (peVar11->base).faction = 0x0;
        *(undefined1 *)&(peVar11->base).state = 0;
        uVar5 = GameTick;
        peVar11->tick = GameTick;
        uVar5 = uVar5 & 0xff00;
      }
      else {
        _fmemset(MK_FP(ST_SEG(peVar11), ST_OFF(peVar11) + 0x1b), 0, 0x14);
        *(byte *)&(peVar11->base).state = dirCount;
        bitPos = 0;
        row = dirCount - 1;
        for (dirPos = row; -1 < dirPos; dirPos = dirPos + -1) {
          bits = pathDirs[dirPos] << (((byte)bitPos & 3) << 1);
          row = CONCAT11((char)((uint)pathDirs >> 8),bits);
          flagByte = (byte *)((int)&(peVar11->base).owner + (bitPos >> 2));
          *flagByte = *flagByte | bits;
          bitPos = bitPos + 1;
        }
        (peVar11->base).faction = 0x0;
        uVar5 = CONCAT11((char)((uint)row >> 8),1);
      }
    }
  }
  return uVar5;
}


/* 5d45:06f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_randBelow */

uint __cdecl16far
ovc26_usesRandBelow(int entityIndex,uint16_t outFlag,uint16_t outFlagSeg,uint16_t flagsOfs,uint16_t flagsSeg)

{
  byte *flagPtr;            /* &Entities[i] + 0x33, the flags byte */
  int entX;                 /* Entities[i].base.x */
  int entY;                 /* Entities[i].base.y */
  uint16_t destX;
  uint16_t destY;
  byte unitType;            /* ovr_ovc45_getUnitType's result */
  uint classOfs;            /* gindex * 0x95, the class record offset */
  uint result;              /* the value every return path produces */
  short *mapPtr;            /* a cell in the GMapFlags grid being probed */
  uint16_t randVal;         /* ovr_randBelow(2,0) */
  undefined1 packHi;        /* the high byte of the packed return */
  int entitiesOfs;          /* (int)Entities, the base the body reads through */
  int stepX;                /* ovr_ovc07_signum(destX - x): -1, 0 or 1 */
  char unaff_DI;
  short *psStack_c;
  byte bStack_7;
  
  entitiesOfs = (int)Entities;
  if (AgntGs[(uint)((entity_t *)entitiesOfs)[entityIndex].base.gindex].ai == '\0') {
    result = 0;
  }
  else {
    classOfs = (uint)((entity_t *)entitiesOfs)[entityIndex].base.gindex * 0x95;
    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + classOfs) & 0x80) == 0) {
      if (AGNT_FIELD(&(Entities)[entityIndex], base.entity, 1) == '\0') {
        entX = *(int *)((entity_t *)entitiesOfs + entityIndex);
        entY = ((entity_t *)entitiesOfs)[entityIndex].base.y;
        destX = ((entity_t *)entitiesOfs)[entityIndex].base.destX;
        destY = ((entity_t *)entitiesOfs)[entityIndex].base.destY;
        stepX = ovr_ovc07_signum(((entity_t *)stepX)[entityIndex].base.destX - entX);
        psStack_c = (short *)ovr_ovc07_signum((Entities)[entityIndex].base.destY -
                                              entY);
        mapPtr = psStack_c;
        if ((stepX != 0) &&
           (mapPtr = (*(short (*) [60] [148])GMapFlags)[entY] + entX + stepX,
           (mapPtr[0x94] & 3U) == 0)) {
          stepX = 0;
        }
        if ((psStack_c != (short *)0x0) &&
           (mapPtr = (*(short (*) [60] [148])GMapFlags)[entY + (int)psStack_c] + entX,
           (mapPtr[0x94] & 3U) == 0)) {
          psStack_c = (short *)0x0;
        }
        if ((stepX == 0) && (psStack_c == (short *)0x0)) {
          result = (uint)mapPtr & 0xff00;
        }
        else {
          if ((stepX != 0) && (stepX != 0)) {
            randVal = ovr_randBelow(2,0);
            if ((randVal & 0xff) == 0) {
              stepX = 0;
            }
            else {
              psStack_c = (short *)0x0;
            }
          }
          if (stepX == 0) {
            bStack_7 = 0xa1;
          }
          else {
            bStack_7 = 0xa0;
          }
          unitType = ovr_ovc45_getUnitType(entX + stepX,entY + (int)psStack_c);
          if ((BuildingTypes[unitType].flags & 0xc) == 0) {
            ovr_createConstructionRecordFar
                      (bStack_7,entX + stepX,entY + (int)psStack_c,(uint8_t *)CONCAT22(outFlagSeg,outFlag),AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3),unaff_DI,0,0,0);
            ovr_attact_usesEntities
                      (entityIndex,entX + stepX,entY + (int)psStack_c,flagsOfs,flagsSeg,0,0,0,0);
            (Entities)[entityIndex].base.targetX = entX + stepX;
            (Entities)[entityIndex].base.targetY = entY + (int)psStack_c;
            flagPtr = (byte *)((uint8_t *)&(Entities)[entityIndex] + 0x33);
            *flagPtr = *flagPtr | 2;
            flagPtr = (byte *)((uint8_t *)&(Entities)[entityIndex] + 0x33);
            *flagPtr = *flagPtr & 0xfa;
            packHi = (undefined1)((uint)(entityIndex * 0x37) >> 8);
            ovr_ovc25_usesAlignUp44
                      (*(char *)((int)&(Entities)[entityIndex].base.entity + 3),1,destX,destY);
            result = CONCAT11(packHi,1);
          }
          else {
            result = 0;
          }
        }
      }
      else {
        result = entityIndex * 0x37 & 0xff00;
      }
    }
    else {
      result = result & 0xff00;
    }
  }
  return result;
}


