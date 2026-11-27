/*
 * ovc49_agents.c - recovered from STRONG.EXE
 * memory block: OVC49_agents.c
 * range: 8699:0000 - 8699:441f
 * functions: 9
 */
#include "recovered.h"


/* 8699:0000 */

/* [R6] touches frameIndex, AgntCount */

undefined1 __cdecl16far ovc49_usesFrameIndex(agnt_t far *agnt,byte *out)

{
  uint8_t faction;
  int frameOfs;
  bool ok;
  int frameSeg;
  int testRow;
  int *framePtr;
  char side;
  char step;
  int xEnd;
  int x;
  int radius;
  int row;
  
  if (((agntG_t far *)agnt->gdata)->extents[1][1] == 0) {
    *out = 0;
  }
  else {
    faction = agnt->faction;
    framePtr = (int *)(*(int *)&agnt->frames + (uint)agnt->frameIndex * 4);
    frameSeg = framePtr[1];
    frameOfs = *framePtr;
    row = (int)agnt->y >> 1;
    if (row < 0) {
      row = 0;
    }
    if (9 < row) {
      row = 9;
    }
    if (agnt->level == 0x0) {
      step = '\x01';
      x = ((int)((int)(*(((agntG_t far *)agnt->gdata)->extents + 1))[0] +
                        *(int *)(frameOfs + 0x17) + agnt->x) >> 1) + -1;
      xEnd = x +
                 ((int)((agntG_t far *)agnt->gdata)->extents[1][1] -
                  (int)(*(((agntG_t far *)agnt->gdata)->extents + 1))[0] >> 1);
    }
    else {
      step = -1;
      x = ((int)((-*(int *)(frameOfs + 0x17) -
                        (int)(*(((agntG_t far *)agnt->gdata)->extents + 1))[0]) + agnt->x) >> 1) + 1;
      xEnd = x -
                 ((int)((agntG_t far *)agnt->gdata)->extents[1][1] -
                  (int)(*(((agntG_t far *)agnt->gdata)->extents + 1))[0] >> 1);
    }
    if (x < 0) {
      x = 0;
    }
    if (xEnd < 0) {
      xEnd = 0;
    }
    if (0x68 < x) {
      x = 0x68;
    }
    if (0x68 < xEnd) {
      xEnd = 0x68;
    }
    for (; x != xEnd; x = x + step) {
      for (radius = 0; radius <= (int)((agntG_t far *)agnt->gdata)->extents[1][2] >> 1;
          radius = radius + 1) {
        side = -1;
        while (((side < '\x02' && (radius != 0)) || ((side == -1 && (radius == 0))))) {
          testRow = row + radius * side;
          if ((-1 < testRow) && (testRow < 10)) {
            if ((AgntArrayA[testRow][x] != '\0') &&
               (((AgntArrayA[testRow][x] <= AgntCount &&
                 (Agnts[AgntArrayA[testRow][x] - 1].faction !=
                  faction)) &&
                (Agnts[AgntArrayA[testRow][x] - 1].combatState == '\0')
                ))) {
              *out = AgntArrayA[testRow][x];
              ok = ovr_agnt_compute4((char *)out);
              if (ok) {
                return *out;
              }
            }
            if (((AgntArrayB[testRow][x] != '\0') &&
                (AgntArrayB[testRow][x] <= AgntCount)) &&
               ((Agnts[AgntArrayB[testRow][x] - 1].faction != faction
                && (Agnts[AgntArrayB[testRow][x] - 1].combatState ==
                    '\0')))) {
              *out = AgntArrayB[testRow][x];
              return *out;
            }
          }
          side = side + '\x02';
        }
      }
    }
    *out = 0;
  }
  return 0;
}



/* 8699:036e */

/* [R6] touches frameIndex, AgntCount */

undefined1 __cdecl16far ovc49_usesFrameIndex2(agnt_t far *agnt,byte *out)

{
  uint8_t faction;
  int frameOfs;
  bool ok;
  int frameSeg;
  int testRow;
  int *framePtr;
  char side;
  char step;
  int xEnd;
  int x;
  int radius;
  int row;
  
  if (((agntG_t far *)agnt->gdata)->extents[0][1] == 0) {
    *out = 0;
  }
  else {
    faction = agnt->faction;
    framePtr = (int *)(*(int *)&agnt->frames + (uint)agnt->frameIndex * 4);
    frameSeg = framePtr[1];
    frameOfs = *framePtr;
    row = (int)agnt->y >> 1;
    if (row < 0) {
      row = 0;
    }
    if (9 < row) {
      row = 9;
    }
    if (agnt->level == 0x0) {
      step = '\x01';
      x = ((int)((int)(*((agntG_t far *)agnt->gdata)->extents)[0] + *(int *)(frameOfs + 0x17) +
                       agnt->x) >> 1) + -1;
      xEnd = x +
                 ((int)((agntG_t far *)agnt->gdata)->extents[0][1] -
                  (int)(*((agntG_t far *)agnt->gdata)->extents)[0] >> 1);
    }
    else {
      step = -1;
      x = ((int)((-*(int *)(frameOfs + 0x17) - (int)(*((agntG_t far *)agnt->gdata)->extents)[0]) +
                       agnt->x) >> 1) + 1;
      xEnd = x -
                 ((int)((agntG_t far *)agnt->gdata)->extents[0][1] -
                  (int)(*((agntG_t far *)agnt->gdata)->extents)[0] >> 1);
    }
    if (x < 0) {
      x = 0;
    }
    if (xEnd < 0) {
      xEnd = 0;
    }
    if (0x68 < x) {
      x = 0x68;
    }
    if (0x68 < xEnd) {
      xEnd = 0x68;
    }
    for (; x != xEnd; x = x + step) {
      for (radius = 0; radius <= (int)((agntG_t far *)agnt->gdata)->extents[0][2] >> 1;
          radius = radius + 1) {
        side = -1;
        while (((side < '\x02' && (radius != 0)) || ((side == -1 && (radius == 0))))) {
          testRow = row + radius * side;
          if ((-1 < testRow) && (testRow < 10)) {
            if ((AgntArrayA[testRow][x] != '\0') &&
               (((AgntArrayA[testRow][x] <= AgntCount &&
                 (Agnts[AgntArrayA[testRow][x] - 1].faction !=
                  faction)) &&
                (Agnts[AgntArrayA[testRow][x] - 1].combatState == '\0')
                ))) {
              *out = AgntArrayA[testRow][x];
              ok = ovr_agnt_compute4((char *)out);
              if (ok) {
                return *out;
              }
            }
            if (((AgntArrayB[testRow][x] != '\0') &&
                (AgntArrayB[testRow][x] <= AgntCount)) &&
               ((Agnts[AgntArrayB[testRow][x] - 1].faction != faction
                && (Agnts[AgntArrayB[testRow][x] - 1].combatState ==
                    '\0')))) {
              *out = AgntArrayB[testRow][x];
              return *out;
            }
          }
          side = side + '\x02';
        }
      }
    }
    *out = 0;
  }
  return 0;
}



/* 8699:06dc */

/* [R4] calls ovr_stExit */

int __cdecl16far ovc49_usesStExit(agnt_t far *agnt,uint16_t arg2)

{
  /* Re-derived: row = (agnt->y >> 1) clamped 0..7; the column bounds come from agnt->x +- the frame's
     width (frameOfs + 0x17) halved and clamped 0..0x68; if they cross, the game exits.  Then
     AgntArrayA (variant 0) or AgntArrayB is scanned for a non-zero cell alongside two further
     [row][col] tables at +0x963 (A path) or +0x549/+0x5b2 (B path), all with the 0x69 row stride.
     The return packs the row offset's high byte in AH, which is deliberate: every success exit in the
     original is `mov ax,di / mov al,1` with di = row*0x69.  Removed as dead: the frames segment
     (loaded and clamped but never read) and the frame segment load. */
  int frameOfs;
  int row;
  int colStart;
  int colEnd;
  int rowOfs;
  byte retHi;
  uint variant;
  int *frameEntry;

  frameEntry = (int *)(*(int *)&agnt->frames + (uint)agnt->frameIndex * 4);
  frameOfs = *frameEntry;
  row = (int)agnt->y >> 1;
  if (row < 0) {
    row = 0;
  }
  if (7 < row) {
    row = 7;
  }
  colStart = (int)(agnt->x - *(int *)(frameOfs + 0x17)) >> 1;
  colEnd = (int)(agnt->x + *(int *)(frameOfs + 0x17)) >> 1;
  if (colStart < 0) {
    colStart = 0;
  }
  if (colEnd < 0) {
    colEnd = 0;
  }
  if (0x68 < colStart) {
    colStart = 0x68;
  }
  if (0x68 < colEnd) {
    colEnd = 0x68;
  }
  if (colEnd < colStart) {
    ovr_stExit(0x1e);
  }
  variant = (uint)agnt->animVariant;
  if (variant == 0) {
    rowOfs = 0;
    for (; retHi = (byte)((uint)rowOfs >> 8), colStart <= colEnd; colStart = colStart + 1) {
      if (AgntArrayA[row][colStart] != '\0') {
        return CONCAT11((char)((uint)(row * 0x69) >> 8),1);
      }
      rowOfs = row * 0x69;
      if (*(char *)(rowOfs + colStart + 0x963) != '\0') {
        return CONCAT11((char)((uint)rowOfs >> 8),1);
      }
    }
  }
  else {
    for (; retHi = (byte)(variant >> 8), colStart <= colEnd; colStart = colStart + 1) {
      if (AgntArrayB[row][colStart] != '\0') {
        return CONCAT11((char)((uint)(row * 0x69) >> 8),1);
      }
      if (*(char *)(row * 0x69 + colStart + 0x549) != '\0') {
        return CONCAT11((char)((uint)(row * 0x69) >> 8),1);
      }
      rowOfs = row * 0x69;
      if (*(char *)(rowOfs + colStart + 0x5b2) != '\0') {
        return CONCAT11((char)((uint)rowOfs >> 8),1);
      }
    }
  }
  return (uint)retHi << 8;
}



/* 8699:0849 */

/* [R7] body shape: compute */

uint __cdecl16far ovc49_compute1(int x)

{
  uint in_AX;
  uint uVar1;
  
  if ((x < 0) || (0xd2 < x)) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar1 = (uint)(*(int *)(x * 2) == 0);
  }
  return uVar1;
}



/* 8699:0874 */

/* [R2] string "%s is no longer paralyzed." */

void __cdecl16far ovc49_textLongerParalyzed(agnt_t far *agnt,byte param)

{
  char ok;
  bool countOk;
  uint16_t roll;
  char *textPtr;
  uint8_t *stashOfs;
  uint checkOk;
  uint16_t blitSeg;
  uint16_t activeOk;
  uint16_t targetOk;
  int rollOk;
  int recOfs;
  uint16_t randChance;
  uint16_t panVal;
  uint16_t in_DX;
  agnt_t far *agnt_00;
  uint16_t *agntSeg;
  byte mode;
  undefined1 slotByte;
  uint8_t strengthCopy;
  uint8_t text;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  uint8_t dirY;
  uint8_t dx;
  uint8_t agntIndex;
  uint16_t distance;
  
  agntSeg = (uint16_t *)((ulong)agnt >> 0x10);
  agnt_00 = (agnt_t far *)agnt;
  if ((agnt_00->combatState == 0x0) && (agnt_00->animFrame == 0xff)) {
    if (((agnt_00->flags & 0x200) != 0) && (roll = ovr_randBelow(0xc,0), (roll & 0xff) == 0)) {
      agnt_00->flags = agnt_00->flags & 0xfdff;
      blitSeg = GSavedBlitSeg;
      textPtr = ovr_agnt_statusText(agnt_00,(char *)CONCAT13((char)((uint)&text >> 8),
                                                            CONCAT12((char)&text,agntSeg)),0);
      stashOfs = ovr_ovc15_usesStshRealloc(textPtr,(char)in_DX,blitSeg,0,0,0,0,0);
      textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x8436,_SS),
                             (char *)CONCAT13((char)((uint)stashOfs >> 8),
                                              CONCAT12((char)stashOfs,0x2410)),(char)stashOfs,
                             (char)in_DX);
      ovr_uiNotify(textPtr,in_DX,(char)in_DX);
      ovr_ovc41_advanceAnimFrame(agnt_00,agntSeg);
      ovr_attact_usesLDIV_at_2();
    }
    if (((agnt_00->flags & 0x100) != 0) &&
       ((roll = ovr_randBelow(0x40,0), (roll & 0xff) == 0 ||
        (((((agntG_t far *)agnt_00->gdata)->flags3 & 0x2000) != 0 &&
         (roll = ovr_randBelow(0x20,0), (roll & 0xff) == 0)))))) {
      agnt_00->flags = agnt_00->flags & 0xfeff;
      blitSeg = GSavedBlitSeg;
      textPtr = ovr_agnt_statusText(agnt_00,(char *)CONCAT13((char)((uint)&text >> 8),
                                                            CONCAT12((char)&text,agntSeg)),0);
      stashOfs = ovr_ovc15_usesStshRealloc(textPtr,(char)in_DX,blitSeg,0,0,0,0,0);
      textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x8451,_SS),
                             (char *)CONCAT13((char)((uint)stashOfs >> 8),
                                              CONCAT12((char)stashOfs,0x2410)),(char)stashOfs,
                             (char)in_DX);
      ovr_uiNotify(textPtr,in_DX,(char)in_DX);
      *(undefined1 *)&agnt_00->state = 0;
      ovr_agnt_compute13(agnt_00,agntSeg);
      ovr_attact_usesLDIV_at_2();
    }
    if ((agnt_00->flags & 0xbc0) == 0) {
      if (((*(char *)((int)&agnt_00->targetX + 1) < '\0') || ((int)agnt_00->y < 0x15)) ||
         (checkOk = ovc49_agentIsActive(agnt), (checkOk & 0xff) != 0)) {
        activeOk = ovc49_agentIsActive(agnt);
        if ((char)activeOk == '\0') {
          mode = (byte)((ulong)agnt >> 0x10);
          if ((agnt_00->animVariant == 0x0) ||
             (ok = ovr_agnt_usesAnimFrame2(agnt_00,agntSeg), ok == '\0')) {
            if ((((agnt_00->animVariant == 0x0) &&
                 (ok = ovr_agnt_usesAnimFrame2(agnt_00,agntSeg), ok != '\0')) &&
                (agnt_00->moveState == 0x0)) && (agnt_00->animFrame == 0xff)) {
              if ((((((agntG_t far *)agnt_00->gdata)->flags & 1) == 0) ||
                  (rollOk = ovr_ovc27_rollAgainstStat(agnt_00,mode,mode,2), (char)rollOk == '\0')) ||
                 (targetOk = ovr_agnt_acquireTarget
                                    (agnt_00,(char *)CONCAT13((char)((uint)&agntIndex >> 8),
                                                              CONCAT12((char)&agntIndex,agntSeg)),
                                     mode), (char)targetOk == '\0')) {
                if ((((((agntG_t far *)agnt_00->gdata)->flags & 1) == 0) ||
                    ((((entity_t *)agnt_00->entity)->base).level < 2)) ||
                   ((rollOk = ovr_ovc27_rollAgainstStat(agnt_00,mode,mode,2), (char)rollOk == '\0' ||
                    (ok = ovr_agnt_usesStrengthMax
                                       (agnt_00,(byte *)CONCAT13((char)((uint)&agntIndex >> 8),
                                                                 CONCAT12((char)&agntIndex,agntSeg)
                                                                )), ok == '\0')))) {
                  if (((((((agntG_t far *)agnt_00->gdata)->flags & 0x400) == 0) ||
                       (0x14 < (int)agnt_00->y)) ||
                      (ok = ovc49_usesFrameIndex(agnt,(byte *)CONCAT22(_SS,&agntIndex)),
                      ok == '\0')) ||
                     ((0x14 < Agnts[agntIndex - 1].y ||
                      (checkOk = ovr_ovc27_compute2(agnt_00,(int)agntSeg,mode,agntIndex - 1),
                      (char)checkOk == '\0')))) {
                    if (((int)agnt_00->y < 0x15) &&
                       (rollOk = ovr_ovc27_rollAgainstStat(agnt_00,mode,mode,3), (char)rollOk != '\0')
                       ) {
                      ok = ovc49_usesFrameIndex2(agnt,(byte *)CONCAT22(_SS,&agntIndex));
                      if ((ok == '\0') || (0x14 < Agnts[agntIndex - 1].y)) {
                        if ((((((((agntG_t far *)agnt_00->gdata)->flags2 & 1) == 0) ||
                              (ok = ovr_agnt_computeFrameExtents
                                                 (agnt_00,(uint8_t *)
                                                          CONCAT13((char)((uint)&agntIndex >> 8),
                                                                   CONCAT12((char)&agntIndex,
                                                                            agntSeg)),mode),
                              ok == '\0')) || (0x14 < Agnts[agntIndex - 1].y))
                            || (((((agntG_t far *)agnt_00->gdata)->flags3 & 0x400) != 0 &&
                                (roll = ovr_randBelow(0x14,0), (roll & 0xff) != 0)))) ||
                           (ok = ovr_agnt_compute16(agnt,(agnt_t far *)MK_FP(SEG_OF(Agnts),(agnt_t far *)&Agnts[agntIndex - 1].x)),
                           ok == '\0')) {
                          if (((((((agntG_t far *)agnt_00->gdata)->flags2 & 0x200) == 0) ||
                               (ok = ovr_agnt_computeFrameExtents
                                                  (agnt_00,(uint8_t *)
                                                           CONCAT13((char)((uint)&agntIndex >> 8),
                                                                    CONCAT12((char)&agntIndex,
                                                                             agntSeg)),mode),
                               ok == '\0')) ||
                              (((((agntG_t far *)agnt_00->gdata)->flags3 & 0x400) != 0 &&
                               (roll = ovr_randBelow(0x14,0), (roll & 0xff) != 0)))) ||
                             (0x14 < Agnts[agntIndex - 1].y)) {
                            if ((((((agntG_t far *)agnt_00->gdata)->flags3 & 1) != 0) &&
                                (ok = ovr_agnt_computeFrameExtents
                                                   (agnt_00,(uint8_t *)
                                                            CONCAT13((char)((uint)&agntIndex >> 8),
                                                                     CONCAT12((char)&agntIndex,
                                                                              agntSeg)),mode),
                                ok != '\0')) && (Agnts[agntIndex - 1].y < 0x15)
                               ) {
                              agnt_00->health = 0x2;
                              agnt_00->targetY = 0;
                              agnt_00->target = agntIndex + 0xff;
                              agnt_00->gindex = 0x5;
                            }
                          }
                          else {
                            agnt_00->health = 0x2;
                            agnt_00->targetY = 0;
                            agnt_00->target = agntIndex + 0xff;
                            agnt_00->gindex = 0x4;
                          }
                        }
                        else {
                          agnt_00->health = 0x2;
                          agnt_00->targetY = 0;
                          agnt_00->target = agntIndex + 0xff;
                          agnt_00->gindex = 0x2;
                        }
                      }
                      else {
                        agnt_00->health = 0x2;
                        agnt_00->targetY = 0;
                        agnt_00->target = agntIndex + 0xff;
                        agnt_00->gindex = 0x0;
                      }
                    }
                    else if ((((int)agnt_00->y < 0x15) &&
                             (roll = ovr_randBelow(0x20,0), (roll & 0xff) == 0)) &&
                            (((((agntG_t far *)agnt_00->gdata)->flags & 0x4000) != 0 &&
                             ((agnt_00->health != 0x4 &&
                              (*(char *)((int)&(((entity_t *)agnt_00->entity)->base).entity + 1) !=
                               '\0')))))) {
                      agnt_00->health = 0x4;
                      agnt_00->targetY = 0;
                      roll = ovr_audio_panFromX(agnt_00,agntSeg);
                      ovr_play_sfxU(0x32,0,roll,0,0);
                    }
                    else if (((((int)agnt_00->y < 0x15) &&
                              (roll = ovr_randBelow(8,0), (roll & 0xff) == 0)) &&
                             ((((agntG_t far *)agnt_00->gdata)->flags2 & 0x40) != 0)) &&
                            (((agnt_00->health != 0x5 &&
                              (ok = ovc49_usesFrameIndex
                                                 (agnt,(byte *)CONCAT22(_SS,&agntIndex)),
                              ok != '\0')) &&
                             ((Agnts[agntIndex - 1].gdata->flags2 & 0x80) != 0)))) {
                      roll = ovr_audio_panFromX((agnt_t far *)&Agnts[param].x,SEG_OF(Agnts));
                      ovr_play_sfxU(0x1e,0,roll,0,0);
                      agnt_00->target = agntIndex + 0xff;
                      agnt_00->health = 0x5;
                      agnt_00->targetY = 0;
                    }
                    else if ((((int)agnt_00->y < 0x15) &&
                             ((((agntG_t far *)agnt_00->gdata)->flags2 & 0x100) != 0)) &&
                            ((agnt_00->health != 0x6 &&
                             ((((ok = ovc49_usesFrameIndex
                                                   (agnt,(byte *)CONCAT22(_SS,&agntIndex)),
                                ok != '\0' &&
                                (recOfs = (uint)agntIndex * 0x34 + -0x34, slotByte = (undefined1)recOfs,
                                checkOk = ovr_agnt_compute12(agnt_00,(agnt_t far *)
                                                                   CONCAT13((char)((uint)recOfs >> 8)
                                                                            ,CONCAT12(slotByte,
                                                  agntSeg)),mode,slotByte,SEG_OF(Agnts)),
                                (char)checkOk != '\0')) &&
                               ((Agnts[agntIndex - 1].flags & 0x800) == 0)) &&
                              ((Agnts[agntIndex - 1].gdata->flags & 4) != 0)))))) {
                      roll = ovr_audio_panFromX((agnt_t far *)&Agnts[param].x,SEG_OF(Agnts));
                      ovr_play_sfxU(0x1f,0,roll,0,0);
                      agnt_00->target = agntIndex + 0xff;
                      agnt_00->health = 0x6;
                      agnt_00->targetY = 0;
                      agnt_00->gindex = 0x3;
                    }
                    else if ((((((agntG_t far *)agnt_00->gdata)->flags3 & 0x200) == 0) ||
                             (roll = (uint16_t)agnt_00->strengthMax, roll < agnt_00->strength + 3)
                             ) || (randChance = ovr_randBelow(0x40,0), (randChance & 0xff) != 0)) {
                      if (((((char)agnt_00->targetX == '\0') &&
                           (*(char *)((int)&agnt_00->targetX + 1) == '\0')) ||
                          (roll = ovr_randBelow(8,0), (roll & 0xff) == 0)) &&
                         (agnt_00->health != 0x4)) {
                        roll = ovr_randBelow(0xc,0);
                        if ((roll & 0xff) == 0) {
                          if (((char)agnt_00->targetX == '\0') &&
                             (*(char *)((int)&agnt_00->targetX + 1) == '\0')) {
                            roll = ovr_randBelow(2,0);
                            *(char *)&agnt_00->targetX = (char)roll * '\x02' + -1;
                            roll = ovr_randBelow(3,0);
                            *(char *)((int)&agnt_00->targetX + 1) = (char)roll + -1;
                          }
                          else {
                            *(undefined1 *)&agnt_00->targetX = 0;
                            *(undefined1 *)((int)&agnt_00->targetX + 1) = 0;
                          }
                        }
                        else {
                          countOk = ovr_agnt_usesAgntCount2
                                            (agnt_00,(uint16_t *)CONCAT22(&dx,agntSeg),
                                             (uint16_t *)CONCAT22(&dirY,_SS));
                          if (countOk) {
                            *(uint8_t *)((int)&agnt_00->targetX + 1) = dirY;
                            if ((distance < 0x6e) &&
                               ((((agntG_t far *)agnt_00->gdata)->flags3 & 0x10) != 0)) {
                              if (distance < 0x30) {
                                if ((agnt_00->screenX < 0x14) || (0xbe < agnt_00->screenX)) {
                                  roll = ovr_randBelow(2,0);
                                  *(char *)&agnt_00->targetX = (char)roll * '\x02' + -1;
                                  roll = ovr_randBelow(3,0);
                                  *(char *)((int)&agnt_00->targetX + 1) = (char)roll + -1;
                                }
                                else if (dx == 0) {
                                  roll = ovr_randBelow(2,0);
                                  *(char *)&agnt_00->targetX = (char)roll * '\x02' + -1;
                                }
                                else {
                                  *(uint8_t *)&agnt_00->targetX = -dx;
                                }
                              }
                              else {
                                if (dx < 0) {
                                  agnt_00->level = 0x1;
                                }
                                else {
                                  agnt_00->level = 0x0;
                                }
                                *(undefined1 *)&agnt_00->targetX = 0;
                                *(undefined1 *)((int)&agnt_00->targetX + 1) = 0;
                              }
                            }
                            else if (distance < 6) {
                              if (dx < 0) {
                                agnt_00->level = 0x1;
                              }
                              else {
                                agnt_00->level = 0x0;
                              }
                              *(undefined1 *)&agnt_00->targetX = 0;
                              *(undefined1 *)((int)&agnt_00->targetX + 1) = 0;
                            }
                            else if (dx == 0) {
                              roll = ovr_randBelow(2,0);
                              *(char *)&agnt_00->targetX = (char)roll * '\x02' + -1;
                            }
                            else {
                              *(uint8_t *)&agnt_00->targetX = dx;
                            }
                          }
                          else {
                            roll = ovr_randBelow(8,0);
                            if ((roll & 0xff) == 0) {
                              if ((char)agnt_00->targetX == '\0') {
                                roll = ovr_randBelow(2,0);
                                *(char *)&agnt_00->targetX = (char)roll * '\x02' + -1;
                              }
                              else {
                                *(undefined1 *)&agnt_00->targetX = 0;
                              }
                            }
                            *(undefined1 *)((int)&agnt_00->targetX + 1) = 0;
                          }
                        }
                        if ((((char)agnt_00->targetX < '\x01') || (agnt_00->level == 0x0)) &&
                           ((-1 < (char)agnt_00->targetX || (agnt_00->level != 0x0)))) {
                          agnt_00->health = 0x0;
                        }
                        else {
                          agnt_00->health = 0x1;
                        }
                      }
                    }
                    else {
                      agnt_00->strength = agnt_00->strength + 0x3;
                      panVal = ovr_audio_panFromX(agnt_00,agntSeg);
                      ovr_play_sfxU(0x4a,0,panVal,0,0);
                      strengthCopy = agnt_00->strength;
                      blitSeg = GSavedBlitSeg;
                      textPtr = ovr_agnt_statusText(agnt_00,(char *)CONCAT22(&text,agntSeg),0);
                      stashOfs = ovr_ovc15_usesStshRealloc(textPtr,(char)roll,strengthCopy,blitSeg,0,0,0,0);
                      textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x846c,_SS),
                                             (char *)CONCAT22(stashOfs,(char *)0x26510),
                                             (char)roll);
                      ovr_uiNotify(textPtr,roll,(char)roll);
                    }
                  }
                  else {
                    agnt_00->health = 0x2;
                    agnt_00->targetY = 0;
                    agnt_00->target = agntIndex + 0xff;
                    agnt_00->gindex = 0x1;
                  }
                }
                else {
                  agnt_00->health = 0x3;
                  agnt_00->targetY = 0;
                  agnt_00->target = agntIndex + 0xff;
                  agnt_00->flags = agnt_00->flags | 0x18;
                  agnt_00->gindex = 0x0;
                }
              }
              else {
                agnt_00->health = 0x3;
                agnt_00->targetY = 0;
                agnt_00->target = agntIndex + 0xff;
                agnt_00->gindex = 0x6;
              }
            }
          }
          else if (((((((agntG_t far *)agnt_00->gdata)->flags & 0x400) == 0) ||
                    ((0x14 < (int)agnt_00->y ||
                     (ok = ovc49_usesFrameIndex(agnt,(byte *)CONCAT22(_SS,&agntIndex)),
                     ok == '\0')))) || (0x14 < Agnts[agntIndex - 1].y)) ||
                  (checkOk = ovr_ovc27_compute2(agnt_00,(int)agntSeg,mode,agntIndex - 1),
                  (char)checkOk == '\0')) {
            if (((((int)agnt_00->y < 0x15) &&
                 (rollOk = ovr_ovc27_rollAgainstStat(agnt_00,mode,mode,3), (char)rollOk != '\0')) &&
                (ok = ovc49_usesFrameIndex2(agnt,(byte *)CONCAT22(_SS,&agntIndex)),
                ok != '\0')) && (Agnts[agntIndex - 1].y < 0x15)) {
              agnt_00->health = 0x2;
              agnt_00->targetY = 0;
              agnt_00->target = agntIndex + 0xff;
              agnt_00->gindex = 0x0;
            }
            else if ((((((agntG_t far *)agnt_00->gdata)->flags2 & 0x200) == 0) ||
                     (0x14 < (int)agnt_00->y)) ||
                    ((ok = ovr_agnt_computeFrameExtents
                                        (agnt_00,(uint8_t *)
                                                 CONCAT13((char)((uint)&agntIndex >> 8),
                                                          CONCAT12((char)&agntIndex,agntSeg)),mode)
                     , ok == '\0' || (0x14 < Agnts[agntIndex - 1].y)))) {
              if ((((((agntG_t far *)agnt_00->gdata)->flags3 & 1) == 0) || (0x14 < (int)agnt_00->y)) ||
                 ((ok = ovr_agnt_computeFrameExtents
                                     (agnt_00,(uint8_t *)
                                              CONCAT13((char)((uint)&agntIndex >> 8),
                                                       CONCAT12((char)&agntIndex,agntSeg)),mode),
                  ok == '\0' || (0x14 < Agnts[agntIndex - 1].y)))) {
                if (((('\0' < (char)agnt_00->targetX) && (0xaa < (int)agnt->x)) ||
                    (((char)agnt_00->targetX < '\0' && ((int)agnt->x < 0x34)))) &&
                   (roll = ovr_randBelow(8,0), (roll & 0xff) == 0)) {
                  countOk = ovr_agnt_usesAgntCount2
                                    (agnt_00,(uint16_t *)CONCAT22(&dx,agntSeg),
                                     (uint16_t *)CONCAT22(&dirY,_SS));
                  if (countOk) {
                    *(uint8_t *)((int)&agnt_00->targetX + 1) = dirY;
                  }
                  else {
                    *(undefined1 *)((int)&agnt_00->targetX + 1) = 0;
                  }
                  *(char *)&agnt_00->targetX = -(char)agnt_00->targetX;
                  Agnts[param].health = 1;
                  agnt_00->targetY = 0;
                }
              }
              else {
                agnt_00->health = 0x2;
                agnt_00->targetY = 0;
                agnt_00->target = agntIndex + 0xff;
                agnt_00->gindex = 0x5;
              }
            }
            else {
              agnt_00->health = 0x2;
              agnt_00->targetY = 0;
              agnt_00->target = agntIndex + 0xff;
              agnt_00->gindex = 0x4;
            }
          }
          else {
            agnt_00->health = 0x2;
            agnt_00->targetY = 0;
            agnt_00->target = agntIndex + 0xff;
            agnt_00->gindex = 0x1;
          }
        }
        else if ((agnt_00->moveState != 0x2) &&
                ((((*(char *)((int)&agnt_00->targetX + 1) == '\0' &&
                   ((char)agnt_00->targetX == '\0')) &&
                  (roll = ovr_randBelow(4,0), (roll & 0xff) == 0)) ||
                 (((*(char *)((int)&agnt_00->targetX + 1) < '\0' || (agnt_00->moveState != 0x1)) ||
                  (roll = ovr_randBelow(8,0), (roll & 0xff) == 0)))))) {
          agnt_00->moveState = 0x1;
          roll = ovr_randBelow(2,0);
          *(undefined1 *)((int)&agnt_00->targetX + 1) = (char)roll;
          roll = ovr_randBelow(2,0);
          *(char *)&agnt_00->targetX = (char)roll * '\x02' + -1;
          if ((int)agnt->x < 0x2a) {
            *(undefined1 *)&agnt_00->targetX = 0xff;
          }
          else if ((int)agnt->x < 0xb5) {
            *(undefined1 *)((int)&agnt_00->targetX + 1) = 1;
          }
          else {
            *(undefined1 *)&agnt_00->targetX = 1;
          }
        }
      }
      else {
        *(undefined1 *)((int)&agnt_00->targetX + 1) = 0xff;
        if ((char)agnt_00->targetX == '\0') {
          roll = ovr_randBelow(3,0);
          *(char *)&agnt_00->targetX = (char)roll + -1;
        }
      }
    }
    else {
      *(undefined1 *)&agnt_00->targetX = 0;
      *(undefined1 *)((int)&agnt_00->targetX + 1) = 0;
      agnt_00->health = 0x0;
    }
  }
  return;
}



/* 8699:1711 */

/* Returns whether an agent is active this frame: moveState below 2 and either the flags bit 2,
   moving, or field 0x2a == 2 with BothFactions. */

uint16_t __cdecl16far ovc49_agentIsActive(agnt_t far *agnt)

{
  agnt_t far *paVar1;
  uint16_t uVar2;
  
  uVar2 = (uint16_t)((ulong)agnt >> 0x10);
  paVar1 = (agnt_t far *)agnt;
  if ((paVar1->moveState < 2) &&
     ((((paVar1->flags & 4) != 0 || (paVar1->moveState == 0x1)) ||
      ((paVar1->teamCode == 0x2 && (BothFactions != '\0')))))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 8699:1753 */

/* Clears a span of `count` cells at the agent's grid position in the agent-index grids (two layers
   normally, three when animVariant is set). */

void * __cdecl16far ovc49_fillGridCells(byte count,agnt_t far *agnt,uint16_t arg3,uint16_t arg4)

{
  uint16_t row;
  int iVar3;
  int colStart;
  void *pvVar5;
  int *piVar6;
  int colEnd;
  
  row = *(uint16_t *)((int)&agnt->frames + 2);
  piVar6 = (int *)(*(int *)&agnt->frames + (uint)agnt->frameIndex * 4);
  iVar3 = *piVar6;
  colStart = (int)(agnt->x - *(int *)(iVar3 + 0x17)) >> 1;
  colEnd = (int)(agnt->x + *(int *)(iVar3 + 0x17)) >> 1;
  if (colStart < 0) {
    colStart = 0;
  }
  if (colEnd < 0) {
    colEnd = 0;
  }
  if (0x68 < colStart) {
    colStart = 0x68;
  }
  if (0x68 < colEnd) {
    colEnd = 0x68;
  }
  if (agnt->animVariant == 0x0) {
    _fmemset(&AgntArrayA[row][colStart],
             count,(colEnd - colStart) + 1);
    pvVar5 = _fmemset(&AgntArrayA[row + 1][colStart],
                      count,(colEnd - colStart) + 1);
  }
  else {
    _fmemset(&AgntArrayB[row][colStart],
             count,(colEnd - colStart) + 1);
    _fmemset(&AgntArrayB[row + 1][colStart],
             count,(colEnd - colStart) + 1);
    pvVar5 = _fmemset(&AgntArrayB[row + 2][colStart],
                      count,(colEnd - colStart) + 1);
  }
  return pvVar5;
}



/* 8699:18c4 */

/* Chooses the agent's animation frame from its combat state, facing and health, stores it in
   frameIndex, advances the frame record's counter and returns the frame.  Re-derived from the
   image; the former body belonged to another function (see doc/step6_entry.md). */

uint __cdecl16far ovc49_body1(agnt_t far *agnt,uint16_t arg2)

{
  uint8_t frame;
  uint8_t sub;
  uint8_t dir;
  uint16_t dirDelta;
  uint16_t pick;
  far_t far *frames;
  uint8_t far *rec;

  frames = agnt->frames;
  /* GUESS: the original reads the word table at 16b3:0x1a6, i.e. the 211 words immediately before
     columnScreenY (0x34c); that table's data is not in the recovered image, so the address is taken
     relative to columnScreenY. */
  dirDelta = (((uint16_t far *)columnScreenY) - 211)[ovr_agnt_clampX(agnt->x)];
  frame = 0;
  sub = 0;
  if (agnt->combatState == 1) {
    if ((agnt->gdata->flags3 & 2) != 0) {
      frame = 0x12;
    }
    else if (agnt->animVariant == 0) {
      if (*(uint8_t far *)((uint8_t far *)agnt + 4) > 0) {
        if (*(int8_t far *)((uint8_t far *)agnt + 5) >= 0) {
          dir = *(uint8_t far *)((uint8_t far *)agnt + 5) == 0 ? 1 : 2;
        }
        else {
          dir = 0;
        }
      }
      else if (*(int8_t far *)((uint8_t far *)agnt + 5) < 0) {
        dir = 5;
      }
      else {
        dir = *(uint8_t far *)((uint8_t far *)agnt + 5) == 0 ? 4 : 3;
      }
      pick = ((uint16_t)agnt->timer + (uint16_t)dir) % 6;
      switch (pick) {
      case 0:
        sub = 0;
        frame = 2;
        break;
      case 1:
        sub = 0;
        frame = 0;
        break;
      case 2:
        sub = 0;
        frame = 1;
        break;
      case 3:
        sub = 1;
        frame = 1;
        break;
      case 4:
        sub = 1;
        frame = 0;
        break;
      default:
        sub = 1;
        frame = 2;
        break;
      }
    }
    else {
      pick = (uint16_t)agnt->timer & 3;
      switch (pick) {
      case 0:
        sub = 0;
        frame = 4;
        break;
      case 1:
        sub = 1;
        frame = 5;
        break;
      case 2:
        sub = 1;
        frame = 4;
        break;
      default:
        sub = 0;
        frame = 5;
        break;
      }
    }
  }
  else if (agnt->combatState == 2) {
    if ((*(uint16_t far *)((char far *)frames + 0xa0) |
         *(uint16_t far *)((char far *)frames + 0xa2)) != 0) {
      frame = 0x12;
    }
    else if (agnt->animVariant == 0) {
      frame = 0;
    }
    else {
      frame = 4;
    }
  }
  else {
    if (*(int8_t far *)((uint8_t far *)agnt + 4) > 0) {
      sub = 0;
      if (*(int8_t far *)((uint8_t far *)agnt + 5) > 0) {
        frame = 1;
      }
      else if (*(int8_t far *)((uint8_t far *)agnt + 5) < 0) {
        frame = 2;
      }
      else if ((int)dirDelta > 7) {
        frame = 2;
      }
      else if ((int)dirDelta < -7) {
        frame = 1;
      }
    }
    else if (*(int8_t far *)((uint8_t far *)agnt + 4) < 0) {
      sub = 1;
      if (*(int8_t far *)((uint8_t far *)agnt + 5) > 0) {
        frame = 1;
      }
      else if (*(int8_t far *)((uint8_t far *)agnt + 5) < 0) {
        frame = 2;
      }
      else if ((int)dirDelta > 7) {
        frame = 1;
      }
      else if ((int)dirDelta < -7) {
        frame = 2;
      }
    }
    else {
      sub = agnt->level;
      if (*(int8_t far *)((uint8_t far *)agnt + 5) > 0) {
        frame = 1;
      }
      else if (*(int8_t far *)((uint8_t far *)agnt + 5) < 0) {
        frame = 2;
      }
      else if ((agnt->flags & 0x100) != 0) {
        switch ((uint16_t)(ovr_randBelow(3,0) & 0xff)) {
        case 0:
          frame = 0;
          break;
        case 1:
          frame = 2;
          break;
        default:
          frame = 1;
          break;
        }
      }
      else {
        frame = 1;
      }
    }
    if (agnt->animVariant != 0) {
      frame = 4;
      if (agnt->health == 2) {
        frame = 0xf;
      }
      else if (agnt->health == 1) {
        frame = 5;
      }
      if ((*(uint16_t far *)((char far *)frames + 0x58 + (uint16_t)frame * 4) |
           *(uint16_t far *)((char far *)frames + 0x5a + (uint16_t)frame * 4)) == 0) {
        frame = 4;
      }
    }
    else if (agnt->health == 2) {
      if ((agnt->gindex == 1) &&
          ((*(uint16_t far *)((char far *)frames + 0x74) |
            *(uint16_t far *)((char far *)frames + 0x76)) != 0)) {
        frame = 7;
      }
      else if ((agnt->gindex == 2) &&
               ((*(uint16_t far *)((char far *)frames + 0xa8) |
                 *(uint16_t far *)((char far *)frames + 0xaa)) != 0)) {
        frame = 0x14;
      }
      else {
        frame = 3;
      }
    }
    else if (agnt->health == 3) {
      if ((*(uint16_t far *)((char far *)frames + 0x74) |
           *(uint16_t far *)((char far *)frames + 0x76)) != 0) {
        frame = 7;
      }
      else {
        frame = 3;
      }
    }
    else if (agnt->health == 1) {
      if ((*(uint16_t far *)((char far *)frames + 0x9c) |
           *(uint16_t far *)((char far *)frames + 0x9e)) != 0) {
        frame = 0x11;
      }
    }
    else if (agnt->health == 4) {
      if ((*(uint16_t far *)((char far *)frames + 0xa4) |
           *(uint16_t far *)((char far *)frames + 0xa6)) != 0) {
        frame = 0x13;
      }
    }
    else if ((agnt->health == 5) || (agnt->health == 6)) {
      if ((*(uint16_t far *)((char far *)frames + 0xac) |
           *(uint16_t far *)((char far *)frames + 0xae)) != 0) {
        frame = 0x15;
      }
    }
  }
  if ((*(uint16_t far *)((char far *)frames + 0x58 + (uint16_t)frame * 4) |
       *(uint16_t far *)((char far *)frames + 0x5a + (uint16_t)frame * 4)) == 0) {
    frame = agnt->animVariant != 0 ? 4 : 0;
  }
  if ((agnt->animVariant == 0) && (frame != 0x12) &&
      (agnt->health == 0) &&
      (*(int8_t far *)((uint8_t far *)agnt + 5) == 0) &&
      (*(int8_t far *)((uint8_t far *)agnt + 4) == 0)) {
    agnt->targetY = 0;
  }
  agnt->level = sub;
  agnt->frameIndex = frame;
  rec = (uint8_t far *)CONCAT22(frames[frame].seg,frames[frame].ofs);
  if (rec[0x1a] == 0xff) {
    if (rec[0x1b] > agnt->targetY + 1) {
      return frame;
    }
    if ((agnt->gdata->flags3 & 4) != 0) {
      if (agnt->animFrame == 0xff) {
        *(uint8_t far *)MK_FP(0x280,0x7e2) = 1;
        ovr_agnt_usesAnimFrame(agnt);
      }
      else {
        agnt->health = 0;
      }
    }
    else {
      agnt->health = 0;
    }
    if (rec[0x1b] <= agnt->targetY) {
      agnt->targetY = 0;
    }
  }
  else if (rec[0x1b] <= agnt->targetY) {
    agnt->targetY = rec[0x1a];
  }
  return frame;
}


/* 8699:1e09 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Per-frame agent pass: updates each agent's grid cells and AI state, resolves its animation and
   sprite, and draws it (also sets BothFactions and GGameState). */

void __cdecl16far ovc49_drawAgents(void)

{
  int *pTarget;
  char *counterPtr;
  uint *puVar3;
  byte bVar4;
  bool bVar5;
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  far_t dst_02;
  bool bVar7;
  bool bVar8;
  far_t gfx_01;
  far_t gfx_02;
  char frameOk;
  uint uVar10;
  stg_tmp_t *stgTmp;
  uint16_t uVar12;
  uint16_t uVar13;
  int iVar14;
  uint16_t uVar15;
  uint16_t *sprEntry;
  int iVar17;
  int *entryPtr;
  uint16_t *puVar19;
  uint16_t uVar21;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t gfx_08;
  far_t gfx_09;
  undefined1 recOfsLo;
  uint8_t type;
  undefined1 ssHi;
  brect_t agentRect;
  int scrY;
  uint agentIndex;
  byte sprIdx;
  uint8_t agntIndex;
  byte frameNo;
  uint uStack_1a;
  stg_tmp_t *stgFar;
  uint16_t uStack_16;
  uint8_t factionSeen;
  char cStack_13;
  uint32_t recPtr;
  uint8_t far *rec;
  uint32_t scanPtr;
  uint32_t sprPtr;
  char cStack_6;
  char cStack_5;
  char cStack_4;
  char cStack_3;
  
  type = (uint8_t)_SS;
  ssHi = (undefined1)(_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = type;
  dst.ofs = (uint16_t)&agentRect;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = ssHi;
  F_SCOPY(far_from_u32((uint32_t)(0x2410842c)),dst,10);
  AgentsChanged = '\0';
  agentRect.seg = GSavedBlitSeg;
  GGameState = 0x2b;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)audioSaveCut1Seg;
  gfx.ofs = audioSaveCut1Ofs;
  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)audioSaveCut1Seg >> 8);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = (char)agentRect.seg;
  dst_00.ofs = 0x8cc;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = (char)(agentRect.seg >> 8);
  ovr_blitLoadRleGfx(gfx,dst_00,0xcc);
  (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)audioSaveCut2Seg;
  gfx_00.ofs = audioSaveCut2Ofs;
  (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)audioSaveCut2Seg >> 8);
  (*(uint8_t *)((uint8_t *)&(dst_01.seg))) = (char)agentRect.seg;
  dst_01.ofs = 0x618c;
  (*(uint8_t *)((uint8_t *)&(dst_01.seg) + 1)) = (char)(agentRect.seg >> 8);
  ovr_blitLoadRleGfx(gfx_00,dst_01,0x8c);
  GGameState = 0x2c;
  (*(uint8_t *)((uint8_t *)&(dst_02.seg))) = type;
  dst_02.ofs = (uint16_t)&agentRect;
  (*(uint8_t *)((uint8_t *)&(dst_02.seg) + 1)) = ssHi;
  ovr_ovc23_textBuildThfres01Lbm(dst_02);
  _fmemset(MK_FP(_SS, &recPtr), 0, 4);
  for (agentIndex = 0; (int)agentIndex < (int)(uint)AgntCount; agentIndex = agentIndex + 1) {
    (&factionSeen)[Agnts[agentIndex].faction] = 0x1;
  }
  if ((factionSeen == 0x0) || (cStack_13 == '\0')) {
    BothFactions = 0;
  }
  else {
    BothFactions = 1;
  }
  GGameState = 0x2d;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  for (agentIndex = 0; (int)agentIndex < (int)(uint)AgntCount; agentIndex = agentIndex + 1) {
    sprPtr = CONCAT22(AGNT_WORD(&Agnts[agentIndex], frames, 2),
                        AGNT_WORD(&Agnts[agentIndex], frames, 0));
    ovc49_fillGridCells(0,(agnt_t far *)&Agnts[agentIndex].x,(char)(agnt_t far *)&Agnts[agentIndex].x,0x26);
    ovc49_textLongerParalyzed
              ((agnt_t far *)MK_FP(SEG_OF(Agnts), agentIndex * 0x34),(byte)agentIndex);
    uVar13 = Agnts[agentIndex].x;
    uVar21 = Agnts[agentIndex].y;
    uVar10 = ovc49_body1((agnt_t far *)&Agnts[agentIndex].x,0x26);
    frameNo = (byte)uVar10;
    sprEntry = (uint16_t *)((int)sprPtr + (uVar10 & 0xff) * 4);
    recPtr = CONCAT22(sprEntry[1],*sprEntry);
    rec = (uint8_t far *)MK_FP((uint16_t)(recPtr >> 0x10),(uint16_t)recPtr);
    uVar15 = SEG_OF(Agnts);
    iVar17 = (int)sprPtr + (uVar10 & 0xff) * 4;
    stgTmp = ovr_stash_usesStExit
                        ((stg_tmp_t *)*(uint16_t *)(iVar17 + 0x58),
                         (char)*(uint16_t *)(iVar17 + 0x5a),AGNT_FIELD(&Agnts[agentIndex], targetY, 0))
    ;
    stgFar = (stg_tmp_t *)CONCAT22(uVar15,stgTmp);
    if (AGNT_FIELD(&Agnts[agentIndex], targetX, 0) < '\x01') {
      if (AGNT_FIELD(&Agnts[agentIndex], targetX, 0) < '\0') {
        Agnts[agentIndex].x = Agnts[agentIndex].x - (int)(char)stgTmp->cmap[5];
      }
    }
    else {
      Agnts[agentIndex].x = Agnts[agentIndex].x + (int)(char)stgTmp->cmap[5];
    }
    bVar5 = true;
    iVar17 = (int)recPtr;
    uVar15 = (uint16_t)((ulong)recPtr >> 0x10);
    if (AGNT_FIELD(&Agnts[agentIndex], targetX, 1) < '\x01') {
      if (AGNT_FIELD(&Agnts[agentIndex], targetX, 1) < '\0') {
        pTarget = (int *)&Agnts[agentIndex].y;
        *pTarget = *pTarget - *(int *)(iVar17 + 0x11);
      }
      else {
        bVar5 = false;
      }
    }
    else {
      pTarget = (int *)&Agnts[agentIndex].y;
      *pTarget = *pTarget + *(int *)(iVar17 + 0x11);
    }
    if (0x14 < Agnts[agentIndex].y) {
      if (AGNT_FIELD(&Agnts[agentIndex], targetX, 1) < '\x01') {
        if (AGNT_FIELD(&Agnts[agentIndex], targetX, 1) < '\0') {
          pTarget = (int *)&Agnts[agentIndex].y;
          *pTarget = *pTarget - *(int *)(iVar17 + 0x11);
        }
      }
      else {
        pTarget = (int *)&Agnts[agentIndex].y;
        *pTarget = *pTarget + *(int *)(iVar17 + 0x11);
      }
    }
    if ((((Agnts[agentIndex].x < 0) || (0xd2 < Agnts[agentIndex].x)) ||
        (Agnts[agentIndex].y < 0)) ||
       ((Agnts[agentIndex].animVariant == '\0' &&
        (uVar10 = ovc49_compute1(Agnts[agentIndex].x), (char)uVar10 != '\0')))) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
    }
    if ((bVar7) && (Agnts[agentIndex].y < 0x15)) {
      bVar8 = true;
    }
    else {
      bVar8 = false;
    }
    if (Agnts[agentIndex].animVariant == '\0') {
      iVar17 = ovr_agnt_clampX(Agnts[agentIndex].x);
      scrY = *(int *)(&columnScreenY[iVar17]) + Agnts[agentIndex].y + 3;
    }
    else {
      iVar17 = ovr_agnt_clampX(Agnts[agentIndex].x);
      scrY = *(int *)(&columnScreenY[iVar17]) + Agnts[agentIndex].y + -0x16;
    }
    Agnts[agentIndex].screenY = scrY;
    if ((Agnts[agentIndex].health == '\x05') && (Agnts[agentIndex].target != -1))
    {
      ovr_ovc41_usesXOfs(agentIndex);
    }
    uVar15 = ovc49_agentIsActive((agnt_t far *)MK_FP(SEG_OF(Agnts), agentIndex * 0x34));
    if ((((char)uVar15 == '\0') || (Agnts[agentIndex].y < 0)) ||
       ((-1 < Agnts[agentIndex].x &&
        ((Agnts[agentIndex].x < 0xd3 &&
         ((uint)(Agnts[agentIndex].screenY - *(int *)(((stg_tmp_t *)stgFar)->cmap + 9))
          < 0x96)))))) {
      if ((Agnts[agentIndex].animVariant == '\0') &&
         (uVar10 = ovc49_compute1(Agnts[agentIndex].x), (char)uVar10 != '\0')) {
        Agnts[agentIndex].x = uVar13;
        Agnts[agentIndex].y = uVar21;
        if (AGNT_FIELD(&Agnts[agentIndex], targetX, 0) == '\0') {
          uVar12 = ovr_randBelow(3,0);
          AGNT_FIELD(&Agnts[agentIndex], targetX, 0) = (char)uVar12 + -1;
        }
        else {
          AGNT_FIELD(&Agnts[agentIndex], targetX, 0) = -AGNT_FIELD(&Agnts[agentIndex], targetX, 0);
        }
        uVar13 = ovc49_agentIsActive((agnt_t far *)MK_FP(SEG_OF(Agnts), agentIndex * 0x34));
        if ((char)uVar13 == '\0') {
          uVar12 = ovr_randBelow(3,0);
          AGNT_FIELD(&Agnts[agentIndex], targetX, 1) = (char)uVar12 + -1;
        }
        else {
          uVar12 = ovr_randBelow(2,0);
          AGNT_FIELD(&Agnts[agentIndex], targetX, 1) = (char)uVar12;
        }
        if (AGNT_FIELD(&Agnts[agentIndex], targetX, 0) == '\0') {
          AGNT_FIELD(&Agnts[agentIndex], targetX, 1) = 0;
        }
        if ((('\0' < AGNT_FIELD(&Agnts[agentIndex], targetX, 0)) && (Agnts[agentIndex].level != '\0')
            ) || ((AGNT_FIELD(&Agnts[agentIndex], targetX, 0) < '\0' &&
                  (Agnts[agentIndex].level == '\0')))) {
          Agnts[agentIndex].health = 1;
        }
        bVar5 = false;
        Agnts[agentIndex].targetY = 0;
        ovc49_body1((agnt_t far *)&Agnts[agentIndex].x,0x26);
      }
      else if ((bVar7) &&
              (((bVar8 || (AGNT_FIELD(&Agnts[agentIndex], targetX, 1) < '\0')) ||
               (uVar10 = ovc49_agentIsActive((agnt_t far *)
                                             MK_FP(SEG_OF(Agnts), agentIndex * 0x34)),
               (uVar10 & 0xff) != 0)))) {
        iVar17 = ovc49_usesStExit((agnt_t far *)&Agnts[agentIndex].x,0x26);
        if ((char)iVar17 != '\0') {
          Agnts[agentIndex].x = uVar13;
          Agnts[agentIndex].y = uVar21;
          if ((Agnts[agentIndex].animVariant == '\0') ||
             (AGNT_FIELD(&Agnts[agentIndex], targetX, 0) != '\0')) {
            if (Agnts[agentIndex].animVariant == '\0') {
              AGNT_FIELD(&Agnts[agentIndex], targetX, 0) = 0;
            }
            else {
              AGNT_FIELD(&Agnts[agentIndex], targetX, 0) = -AGNT_FIELD(&Agnts[agentIndex], targetX, 0);
            }
          }
          else {
            uVar12 = ovr_randBelow(2,0);
            AGNT_FIELD(&Agnts[agentIndex], targetX, 0) = (char)uVar12 * '\x02' + -1;
          }
          AGNT_FIELD(&Agnts[agentIndex], targetX, 1) = 0;
          Agnts[agentIndex].targetY = 0;
          if ((('\0' < AGNT_FIELD(&Agnts[agentIndex], targetX, 0)) &&
              (Agnts[agentIndex].level != '\0')) ||
             ((AGNT_FIELD(&Agnts[agentIndex], targetX, 0) < '\0' && (Agnts[agentIndex].level == '\0')
              ))) {
            Agnts[agentIndex].health = 1;
          }
          bVar5 = false;
          ovc49_body1((agnt_t far *)&Agnts[agentIndex].x,0x26);
        }
      }
      else if (Agnts[agentIndex].moveState != '\x02') {
        Agnts[agentIndex].x = uVar13;
        Agnts[agentIndex].y = uVar21;
        if ((Agnts[agentIndex].flags & 0xbc0) == 0) {
          if (AGNT_FIELD(&Agnts[agentIndex], targetX, 0) == '\0') {
            uVar12 = ovr_randBelow(2,0);
            AGNT_FIELD(&Agnts[agentIndex], targetX, 0) = (char)uVar12 * '\x02' + -1;
          }
          else {
            AGNT_FIELD(&Agnts[agentIndex], targetX, 0) = -AGNT_FIELD(&Agnts[agentIndex], targetX, 0);
          }
          uVar12 = ovr_randBelow(3,0);
          AGNT_FIELD(&Agnts[agentIndex], targetX, 1) = (char)uVar12 + -1;
        }
        if ((('\0' < AGNT_FIELD(&Agnts[agentIndex], targetX, 0)) && (Agnts[agentIndex].level != '\0')
            ) || ((AGNT_FIELD(&Agnts[agentIndex], targetX, 0) < '\0' &&
                  (Agnts[agentIndex].level == '\0')))) {
          Agnts[agentIndex].health = 1;
        }
        bVar5 = false;
        Agnts[agentIndex].targetY = 0;
        ovc49_body1((agnt_t far *)&Agnts[agentIndex].x,0x26);
      }
    }
    else {
      Agnts[agentIndex].moveState = 2;
    }
    ovc49_fillGridCells((byte)agentIndex + 1,(agnt_t far *)&Agnts[agentIndex].x,
                        (char)(agnt_t far *)&Agnts[agentIndex].x,0x26);
    if ((bVar5) && (uVar13 = ovr_agnt_usesAgntSaved(agentIndex), (char)uVar13 != '\0')) {
      agentIndex = agentIndex + -1;
    }
  }
  GGameState = 0x2e;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  for (agentIndex = 0; (int)agentIndex < (int)(uint)AgntCount; agentIndex = agentIndex + 1) {
    uVar13 = AGNT_WORD(&Agnts[agentIndex], frames, 2);
    iVar17 = AGNT_WORD(&Agnts[agentIndex], frames, 0);
    sprPtr = CONCAT22(uVar13,iVar17);
    uStack_1a = Agnts[agentIndex].targetY;
    frameNo = Agnts[agentIndex].frameIndex;
    sprEntry = (uint16_t *)(iVar17 + (uint)frameNo * 4);
    recPtr = CONCAT22(sprEntry[1],*sprEntry);
    rec = (uint8_t far *)MK_FP((uint16_t)(recPtr >> 0x10),(uint16_t)recPtr);
    GGameState = 0x37;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    uVar13 = SEG_OF(Agnts);
    uVar21 = (uint16_t)((ulong)sprPtr >> 0x10);
    iVar17 = (int)sprPtr + (uint)frameNo * 4;
    stgTmp = ovr_stash_usesStExit
                        ((stg_tmp_t *)*(uint16_t *)(iVar17 + 0x58),
                         (char)*(uint16_t *)(iVar17 + 0x5a),AGNT_FIELD(&Agnts[agentIndex], targetY, 0))
    ;
    stgFar = (stg_tmp_t *)CONCAT22(uVar13,stgTmp);
    GGameState = 0x38;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    iVar17 = Agnts[agentIndex].x + 0xc;
    if (Agnts[agentIndex].animVariant == '\0') {
      iVar14 = ovr_agnt_clampX(Agnts[agentIndex].x);
      scrY = *(int *)(&columnScreenY[iVar14]) + Agnts[agentIndex].y + 3;
    }
    else {
      iVar14 = ovr_agnt_clampX(Agnts[agentIndex].x);
      scrY = *(int *)(&columnScreenY[iVar14]) + Agnts[agentIndex].y +
                  (int)Agnts[agentIndex].gdata->yOffset + -0x16;
    }
    Agnts[agentIndex].screenX = iVar17;
    Agnts[agentIndex].screenY = scrY;
    if ((Agnts[agentIndex].flags & 0x800) == 0) {
      if (Agnts[agentIndex].combatState == '\0') {
        GGameState = 0x32;
        gfx_04.seg = uStack_16;
        gfx_04.ofs = (uint16_t)(stgFar->cmap + 6);
        ovr_blitGfxRect(gfx_04,iVar17,scrY,&agentRect,type,(*(uint8_t *)((uint8_t *)&(scrY))),0,0,0,0,0,0);
        GGameState = 0x33;
        if ((Agnts[agentIndex].flags & 100) != 0) {
          iVar14 = scrY - *(int far *)(rec + 0xd);
          bVar4 = Agnts[agentIndex].timer;
          counterPtr = (char *)&Agnts[agentIndex].timer;
          *counterPtr = *counterPtr + -1;
          uVar10 = bVar4 & 3;
          gfx_05.seg = ((uint16_t *)&crossBlitType2Seg)[uVar10 * 2];
          gfx_05.ofs = ((uint16_t *)&crossBlitType2Ofs)[uVar10 * 2];
          ovr_blitGfxRect(gfx_05,iVar17,iVar14,&agentRect,type,SUB21(iVar14,0),0,0,0,0,0,0);
        }
      }
      else if (Agnts[agentIndex].combatState == '\x01') {
        if ((Agnts[agentIndex].gdata->flags3 & 2) == 0) {
          gfx_07.seg = uStack_16;
          gfx_07.ofs = (uint16_t)(stgFar->cmap + 6);
          ovr_blitGfxRect(gfx_07,iVar17,scrY,&agentRect,type,(*(uint8_t *)((uint8_t *)&(scrY))),0,0,0,0,0,0);
          iVar14 = scrY - *(int far *)(rec + 0xd);
          uVar10 = Agnts[agentIndex].timer & 3;
          gfx_08.seg = ((uint16_t *)&crossBlitType2Seg)[uVar10 * 2];
          gfx_08.ofs = ((uint16_t *)&crossBlitType2Ofs)[uVar10 * 2];
          ovr_blitGfxRect(gfx_08,iVar17,iVar14,&agentRect,type,SUB21(iVar14,0),0,0,0,0,0,0);
          if (Agnts[agentIndex].timer == '\0') {
            Agnts[agentIndex].combatState = 0;
          }
          else {
            counterPtr = (char *)&Agnts[agentIndex].timer;
            *counterPtr = *counterPtr + -1;
          }
        }
        else {
          gfx_06.seg = uStack_16;
          gfx_06.ofs = (uint16_t)(stgFar->cmap + 6);
          ovr_blitGfxRect(gfx_06,iVar17,scrY,&agentRect,type,(*(uint8_t *)((uint8_t *)&(scrY))),0,0,0,0,0,0);
          if ((int)(uint)*(byte far *)(rec + 0x1b) <= Agnts[agentIndex].targetY + 1) {
            Agnts[agentIndex].combatState = 0;
          }
        }
      }
      else if (Agnts[agentIndex].combatState == '\x02') {
        if (frameNo == 0x12) {
          gfx_09.seg = uStack_16;
          gfx_09.ofs = (uint16_t)(stgFar->cmap + 6);
          ovr_blitGfxRect(gfx_09,iVar17,scrY,&agentRect,type,(*(uint8_t *)((uint8_t *)&(scrY))),0,0,0,0,0,0);
          if ((int)(uint)*(byte far *)(rec + 0x1b) <= Agnts[agentIndex].targetY + 1) {
            Agnts[agentIndex].moveState = 2;
            ovr_ovc41_paralyzeNearbyAgents(agentIndex);
          }
        }
        else {
          uVar12 = ovr_randBelow(0x100,0);
          gfx_01.seg = (uint16_t)((ulong)stgFar >> 0x10);
          gfx_01.ofs = (uint16_t)(stgFar->cmap + 6);
          ovr_gfxRlePrepare(gfx_01,iVar17,scrY,&agentRect.x,type,'\x10',0x10,CONCAT11((char)(agentIndex * 0x34 >> 8),
                                     Agnts[agentIndex].level),1,Agnts[agentIndex].timer * '\x19',(char)uVar12,0,0);
          if (Agnts[agentIndex].timer == '\0') {
            Agnts[agentIndex].moveState = 2;
            ovr_ovc41_paralyzeNearbyAgents(agentIndex);
          }
          else {
            counterPtr = (char *)&Agnts[agentIndex].timer;
            *counterPtr = *counterPtr + -1;
          }
        }
      }
    }
    else {
      gfx_03.seg = uStack_16;
      gfx_03.ofs = (uint16_t)(stgFar->cmap + 6);
      ovr_gfxRlePrepare(gfx_03,iVar17,scrY,&agentRect.x,type,'\x10',0x10,CONCAT11((char)(agentIndex * 0x34 >> 8),
                                 Agnts[agentIndex].level),0xff,0,0,0,0);
    }
    if (AGNT_FIELD(&Agnts[agentIndex], state, 0) != '\0') {
      ovr_agnt_drawSpriteFrame((byte)agentIndex,&agentRect,(char)&agentRect);
    }
    uVar13 = (uint16_t)((ulong)recPtr >> 0x10);
    if (((Agnts[agentIndex].flags & 8) == 0) ||
       ((uint)*(byte far *)(rec + 0x19) != Agnts[agentIndex].targetY)) {
      if (((uint)*(byte far *)(rec + 0x19) == Agnts[agentIndex].targetY) &&
         ((Agnts[agentIndex].combatState == '\0' && (Agnts[agentIndex].animFrame == -1)))
         ) {
        if (Agnts[agentIndex].gindex == '\0') {
          frameOk = ovc49_usesFrameIndex2
                            ((agnt_t far *)MK_FP(SEG_OF(Agnts), agentIndex * 0x34),
                             (byte *)CONCAT13(ssHi,CONCAT12(type,&agntIndex)));
          if (frameOk == '\0') {
            if ((Agnts[agentIndex].frameIndex == '\x03') ||
               (Agnts[agentIndex].frameIndex == '\x0f')) {
              uVar12 = ovr_audio_panFromX((agnt_t far *)&Agnts[agentIndex].x,0x26);
              ovr_play_sfxU(0x33,0,uVar12,0,(char)uVar12);
            }
            animBranchCode = 9;
            ovr_agnt_advanceAnimFrame((agnt_t far *)&Agnts[agentIndex].x,0x26);
          }
          else {
            Agnts[agentIndex].target = agntIndex + 0xff;
          }
        }
        else if (Agnts[agentIndex].gindex == '\x01') {
          frameOk = ovc49_usesFrameIndex
                            ((agnt_t far *)MK_FP(SEG_OF(Agnts), agentIndex * 0x34),
                             (byte *)CONCAT13(ssHi,CONCAT12(type,&agntIndex)));
          if ((frameOk == '\0') ||
             (uVar10 = ovr_ovc27_compute1((agnt_t far *)&Agnts[agentIndex].x,SEG_OF(Agnts),0x26,agntIndex + 0xff)
             , (char)uVar10 == '\0')) {
            animBranchCode = 10;
            ovr_agnt_advanceAnimFrame((agnt_t far *)&Agnts[agentIndex].x,0x26);
          }
          else {
            Agnts[agentIndex].target = agntIndex + 0xff;
          }
        }
        else if (((Agnts[agentIndex].gindex == '\x02') ||
                 (Agnts[agentIndex].gindex == '\x04')) ||
                (Agnts[agentIndex].gindex == '\x05')) {
          frameOk = ovr_agnt_computeFrameExtents
                            ((agnt_t far *)&Agnts[agentIndex].x,
                             (uint8_t *)
                             CONCAT13((char)((uint)&agntIndex >> 8),
                                      CONCAT12((char)&agntIndex,SEG_OF(Agnts))),0x26);
          if (frameOk == '\0') {
            animBranchCode = 0xb;
            ovr_agnt_advanceAnimFrame((agnt_t far *)&Agnts[agentIndex].x,0x26);
          }
          else {
            Agnts[agentIndex].target = agntIndex + 0xff;
          }
        }
        agntIndex = Agnts[agentIndex].target + 1;
        if (((agntIndex == 0) || (Agnts[agntIndex - 1].combatState != '\0')) ||
           ((Agnts[agentIndex].gindex != '\x06' &&
            ((0x14 < Agnts[agentIndex].y ||
             (0x14 < Agnts[agntIndex - 1].y)))))) {
          animBranchCode = 0xc;
          ovr_agnt_advanceAnimFrame((agnt_t far *)&Agnts[agentIndex].x,0x26);
        }
        else if (Agnts[agentIndex].gindex == '\x01') {
          uVar10 = ovr_ovc27_spellNotice(agentIndex);
          if ((uVar10 & 0xff) == 0) {
            animBranchCode = 0xf;
            ovr_agnt_advanceAnimFrame((agnt_t far *)&Agnts[agentIndex].x,0x26);
          }
        }
        else if (((Agnts[agentIndex].gindex == '\x02') ||
                 (Agnts[agentIndex].gindex == '\x04')) &&
                (Agnts[agentIndex].animFrame == -1)) {
          uVar12 = ovr_audio_panFromX((agnt_t far *)&Agnts[agentIndex].x,0x26);
          ovr_play_sfxU(*(byte far *)(rec + 0x1d),0,uVar12,0,(char)uVar12);
          Agnts[agentIndex].animFrame = 0;
          Agnts[agentIndex].variant = 0;
          uVar13 = (uint16_t)((ulong)recPtr >> 0x10);
          iVar14 = (int)recPtr;
          AGNT_FIELD(&Agnts[agentIndex], destY, 0) = *(char *)(iVar14 + 0x15) + (*(uint8_t *)((uint8_t *)&(scrY)));
          if (Agnts[agentIndex].level == '\0') {
            Agnts[agentIndex].destX = *(int *)(iVar14 + 0x13) + iVar17;
          }
          else {
            Agnts[agentIndex].destX = iVar17 - *(int *)(iVar14 + 0x13);
          }
          AGNT_FIELD(&Agnts[agentIndex], destY, 1) = Agnts[agentIndex].level;
        }
        else if ((Agnts[agentIndex].gindex == '\0') &&
                ((Agnts[agentIndex].gdata->flags & 8) == 0)) {
          uVar12 = ovr_audio_panFromX((agnt_t far *)&Agnts[agentIndex].x,0x26);
          ovr_play_sfxU(*(byte far *)(rec + 0x1d),0,uVar12,0,(char)uVar12);
          ovr_ovc41_resolveSpecialAttack
                    ((agnt_t far *)MK_FP(SEG_OF(Agnts), agentIndex * 0x34),
                     (uint)Agnts[agentIndex].target);
        }
        else if (Agnts[agentIndex].gindex == '\x03') {
          iVar17 = (uint)agntIndex * 0x34 + -0x34;
          recOfsLo = (undefined1)iVar17;
          uVar10 = ovr_agnt_compute12((agnt_t far *)&Agnts[agentIndex].x,
                                      (agnt_t far *)
                                      CONCAT13((char)((uint)iVar17 >> 8),CONCAT12(recOfsLo,SEG_OF(Agnts))),
                                      0x26,recOfsLo,0x26);
          if (((char)uVar10 != '\0') && ((Agnts[agntIndex - 1].flags & 0x800) == 0)) {
            if (((*(uint16_t far *)((uint8_t far *)&Agnts[agntIndex - 1].entity->base.frames + 1)
                   & 2) == 0) ||
               ((uVar12 = ovr_randBelow(2,0), (uVar12 & 0xff) != 0 ||
                ((Agnts[agentIndex].flags & 0x800) == 0)))) {
              ovr_OVC41_6a8f_01e7_entry((agnt_t far *)&Agnts[agntIndex - 1].x,0x26);
              puVar3 = (uint *)&Agnts[agntIndex - 1].flags;
              *puVar3 = *puVar3 | 0x800;
              uVar12 = ovr_audio_panFromX((agnt_t far *)&Agnts[agntIndex - 1].x,0x26);
              ovr_play_sfxU(0x1b,0,uVar12,0,(char)uVar12);
            }
            else {
              uVar12 = ovr_audio_panFromX((agnt_t far *)&Agnts[agentIndex].x,0x26);
              ovr_play_sfxU(0x1b,0,uVar12,0,(char)uVar12);
              ovr_OVC41_6a8f_01e7_entry((agnt_t far *)&Agnts[agntIndex - 1].x,0x26);
              puVar3 = (uint *)&Agnts[agentIndex].flags;
              *puVar3 = *puVar3 | 0x800;
            }
          }
          animBranchCode = 0xd;
          ovr_agnt_advanceAnimFrame((agnt_t far *)&Agnts[agentIndex].x,0x26);
        }
        else if (Agnts[agentIndex].gindex == '\x05') {
          uVar12 = ovr_audio_panFromX((agnt_t far *)&Agnts[agentIndex].x,0x26);
          ovr_play_sfxU(*(byte far *)(rec + 0x1d),0,uVar12,0,(char)uVar12);
          Agnts[agentIndex].animFrame = 0xf5;
          Agnts[agentIndex].variant = 1;
        }
        else if (Agnts[agentIndex].gindex == '\x06') {
          uVar12 = ovr_audio_panFromX((agnt_t far *)&Agnts[agentIndex].x,0x26);
          ovr_play_sfxU(*(byte far *)(rec + 0x1d),0,uVar12,0,(char)uVar12);
          ovr_ovc41_resolveSpecialAttack
                    ((agnt_t far *)MK_FP(SEG_OF(Agnts), agentIndex * 0x34),
                     (uint)Agnts[agentIndex].target);
        }
        else {
          animBranchCode = 0xe;
          ovr_agnt_advanceAnimFrame((agnt_t far *)&Agnts[agentIndex].x,0x26);
        }
      }
    }
    else {
      ovr_ovc41_resolveSpecialAttack
                ((agnt_t far *)MK_FP(SEG_OF(Agnts), agentIndex * 0x34),
                 (uint)Agnts[agentIndex].target);
    }
    GGameState = 0x39;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    pTarget = (int *)&Agnts[agentIndex].targetY;
    *pTarget = *pTarget + 1;
    if (Agnts[agentIndex].animFrame != -1) {
      if (Agnts[agentIndex].target == -1) {
        ovr_agnt_usesAnimFrame((agnt_t far *)&Agnts[agentIndex].x,0x26);
        animBranchCode = 7;
      }
      else if ((Agnts[agentIndex].variant == '\0') ||
              (*(char *)((uint)Agnts[agentIndex].variant * 0x21 + -0x16) != '\0')) {
        bVar4 = Agnts[agentIndex].animFrame;
        uStack_1a = (uint)bVar4;
        uVar13 = (uint16_t)((ulong)sprPtr >> 0x10);
        scanPtr = sprPtr;
        if (Agnts[agentIndex].variant == '\0') {
          sprIdx = 6;
        }
        else {
          sprIdx = *(byte *)((uint)Agnts[agentIndex].variant * 0x21 + -0x16);
        }
        entryPtr = (int *)((int)sprPtr + (uint)sprIdx * 4);
        if (*entryPtr == 0 && entryPtr[1] == 0) {
          scanPtr = CONCAT22(SprProjectiles.seg,SprProjectiles.ofs);
        }
        uVar13 = (uint16_t)((ulong)scanPtr >> 0x10);
        iVar17 = (int)scanPtr;
        puVar19 = (uint16_t *)(iVar17 + (uint)sprIdx * 4);
        uVar12 = *puVar19;
        recPtr = CONCAT22(puVar19[1],uVar12);
        rec = (uint8_t far *)MK_FP((uint16_t)(recPtr >> 0x10),(uint16_t)recPtr);
        entryPtr = (int *)(iVar17 + (uint)sprIdx * 4);
        if (*entryPtr == 0 && entryPtr[1] == 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0xf);
        }
        iVar17 = iVar17 + (uint)sprIdx * 4;
        stgTmp = ovr_stash_usesStExit
                            ((stg_tmp_t *)*(uint16_t *)(iVar17 + 0x58),
                             (char)*(uint16_t *)(iVar17 + 0x5a),bVar4);
        stgFar = (stg_tmp_t *)CONCAT22(uVar12,stgTmp);
        GGameState = 0x30;
        bVar5 = AGNT_FIELD(&Agnts[agentIndex], destY, 0);
        gfx_02.seg = uVar12;
        gfx_02.ofs = (uint16_t)(stgTmp->cmap + 6);
        ovr_blitGfxRect(gfx_02,Agnts[agentIndex].destX,(uint)bVar5,&agentRect,type,bVar5,0,0,0,0,0,0)
        ;
        GGameState = 0x31;
        uVar13 = (uint16_t)((ulong)recPtr >> 0x10);
        iVar17 = (int)recPtr;
        if ((*(byte *)(iVar17 + 0x1c) & 2) == 0) {
          uVar21 = (uint16_t)((ulong)stgFar >> 0x10);
          if (AGNT_FIELD(&Agnts[agentIndex], destY, 1) == '\0') {
            pTarget = (int *)&Agnts[agentIndex].destX;
            *pTarget = *pTarget + (int)(char)((stg_tmp_t *)stgFar)->cmap[5];
          }
          else {
            pTarget = (int *)&Agnts[agentIndex].destX;
            *pTarget = *pTarget - (int)(char)((stg_tmp_t *)stgFar)->cmap[5];
          }
          uStack_1a = uStack_1a + 1;
          if (*(byte *)(iVar17 + 0x19) + 1 == uStack_1a) {
            ovr_ovc41_specialAttack
                      ((agnt_t far *)&Agnts[agentIndex].x,SEG_OF(Agnts),0x26,
                       Agnts[agentIndex].target);
          }
          if ((int)uStack_1a < (int)(uint)*(byte far *)(rec + 0x1b)) {
            Agnts[agentIndex].animFrame = (undefined1)uStack_1a;
          }
          else {
            animBranchCode = 8;
            ovr_agnt_usesAnimFrame((agnt_t far *)&Agnts[agentIndex].x,0x26);
          }
        }
        else {
          ovr_agnt_usesStExit((agnt_t far *)&Agnts[agentIndex].x,
                              (anm_t *)CONCAT22(iVar17,(anm_t *)((int)&AgntAnms[0x75].halfWidth + 1)
                                               ),
                              (stg_tmp_t *)
                              CONCAT13((char)((ulong)stgFar >> 8),
                                       CONCAT12((char)stgFar,uVar13)),0x26,
                              (char)((ulong)recPtr >> 0x10),(char)stgFar,
                              (char)((ulong)stgFar >> 0x10));
        }
      }
      else {
        ovr_ovc27_usesBlitGfxRect(agentIndex,&agentRect,(char)&agentRect);
      }
    }
  }
  GGameState = 0x3a;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_constr_blitRowObjects(&agentRect);
  GGameState = 0x2f;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  if (AgentsChanged != '\0') {
    ovr_attact_usesEntityCount();
    AgentsChanged = '\0';
  }
  cStack_3 = '\0';
  cStack_4 = '\0';
  agentIndex = (uint)AgntCount;
  do {
    do {
      agentIndex = agentIndex - 1;
      if ((int)agentIndex < 0) goto L_OVC49_8699_1e09_3CF7;
    } while (((Agnts[agentIndex].flags & 0xae4) != 0) ||
            (Agnts[agentIndex].moveState == '\x02'));
    if (Agnts[agentIndex].faction == '\0') {
      cStack_3 = '\x01';
    }
    else {
      cStack_4 = '\x01';
    }
  } while ((cStack_4 == '\0') || (cStack_3 == '\0'));
L_OVC49_8699_1e09_3CF7:
  if ((cStack_3 == '\0') || (cStack_4 == '\0')) {
    cStack_5 = '\x01';
  }
  else {
    cStack_5 = '\0';
  }
  cStack_6 = '\0';
  agentIndex = (uint)AgntCount;
  while (agentIndex = agentIndex - 1, -1 < (int)agentIndex) {
    if (Agnts[agentIndex].moveState == '\x02') {
      ovr_ovc41_removeAgent(agentIndex,0,0);
      AgentsChanged = '\x01';
    }
    else if ((cStack_5 != '\0') && ((Agnts[agentIndex].flags & 0xae4) != 0)) {
      cStack_6 = '\x01';
      AGNT_FIELD(&Agnts[agentIndex], state, 0) = 0;
      if ((((Agnts[agentIndex].flags & 0x800) == 0) &&
          ((Agnts[agentIndex].gdata->ai == '\0' || (cStack_4 != '\0')))) &&
         ((Agnts[agentIndex].gdata->ai != '\0' || (cStack_3 != '\0')))) {
        puVar3 = (uint *)&Agnts[agentIndex].flags;
        *puVar3 = *puVar3 & 0xf51b;
        Agnts[agentIndex].faction =
             Agnts[agentIndex].gdata->ai;
        ovr_ovc41_advanceAnimFrame((agnt_t far *)&Agnts[agentIndex].x,0x26);
      }
      else {
        puVar3 = (uint *)&Agnts[agentIndex].flags;
        *puVar3 = *puVar3 & 0xf51b;
        Agnts[agentIndex].strength = 0;
        Agnts[agentIndex].timer = 10;
        Agnts[agentIndex].combatState = 2;
        Agnts[agentIndex].targetY = 0;
      }
      AgentsChanged = '\x01';
    }
  }
  if (AgentsChanged != '\0') {
    ovr_attact_usesEntityCount();
    AgentsChanged = '\0';
  }
  uVar10 = EntityCount;
  if (cStack_6 != '\0') {
    ovr_play_sfxU(0x3b,0,0x80,0,0x80);
    uVar10 = EntityCount;
  }
  do {
    do {
      uVar10 = uVar10 - 1;
      if ((int)uVar10 < 0) {
        ovr_ovc41_usesDebugVerbose();
        return;
      }
      uVar13 = (uint16_t)((ulong)Entities >> 0x10);
    } while ((((entity_t far *)Entities)[uVar10].base.animFrame != '\0') ||
            (iVar14 = ((entity_t far *)Entities)[uVar10].base.y,
            uVar13 = ovr_ovc23_isCursorAt(*(uint16_t *)((entity_t far *)Entities + uVar10),iVar14,(char)iVar14)
            , (char)uVar13 == '\0'));
    agentIndex = (uint)AgntCount;
    do {
      agentIndex = agentIndex - 1;
      if ((int)agentIndex < 0) break;
    } while (Agnts[agentIndex].owner != uVar10);
    if ((int)agentIndex < 0) {
      ovr_ovc15_removeEntity(uVar10);
      constructionDirty = 1;
    }
  } while( true );
}


