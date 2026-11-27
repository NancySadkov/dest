/*
 * ovc27_combat.c - recovered from STRONG.EXE
 * memory block: OVC27_combat.c
 * range: 5ded:0000 - 5ded:22af
 * functions: 22
 */
#include "recovered.h"


/* 5ded:0000 */

/* Emits the "Intelligence reports %s attacking." notice. */

void __cdecl16far ovc27_intelAttackingNotice(int x1,int y1,int x2,int y2,int *rectOfs)

{
  undefined1 *puVar1;
  uint slopeRem;
  uint remSign;
  int iVar4;
  int iVar5;
  int *piVar6;
  byte in_stack_00000010;
  far_t dst;
  uint8_t yOffset;
  int iStack_10;
  int yStep;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int y2Saved;
  byte bStack_3;
  
  iVar5 = y2;
  iVar4 = x2;
  dst.seg = _SS;
  dst.ofs = (uint16_t)&yOffset;
  F_SCOPY(far_from_u32((uint32_t)(0x2410592a)),dst,32);
  if (x2 < x1) {
    x2 = x1;
    x1 = iVar4;
    y2Saved = y2;
    y2 = y1;
    y1 = iVar5;
  }
  if (x1 < *rectOfs) {
    x1 = *rectOfs;
  }
  piVar6 = (int *)rectOfs;
  if (piVar6[2] < x2) {
    x2 = piVar6[2];
  }
  if (x1 <= x2) {
    if (x1 == x2) {
      iStack_a = 0;
      iStack_c = 0;
    }
    else {
      iStack_a = (y2 - y1) / (x2 - x1);
      slopeRem = (y2 - y1) % (x2 - x1);
      remSign = (int)slopeRem >> 0xf;
      iStack_c = (slopeRem ^ remSign) - remSign;
    }
    yStep = ovr_ovc07_signum(y2 - y1);
    iStack_10 = x2 - x1 >> 1;
    bStack_3 = 0;
    for (iStack_8 = x1; iStack_8 <= x2; iStack_8 = iStack_8 + 1) {
      iVar4 = y1 + *(int *)(&yOffset + ((uint)bStack_3 + (uint)in_stack_00000010 & 0xf) * 2);
      iVar5 = iVar4 + -1;
      bStack_3 = bStack_3 + 1;
      puVar1 = (undefined1 *)(iVar5 * 0x140 + iStack_8);
      if ((piVar6[1] <= iVar5) && (iVar5 <= piVar6[3])) {
        *puVar1 = 0xc;
      }
      if ((piVar6[1] <= iVar4) && (iVar4 <= piVar6[3])) {
        puVar1[0x140] = 0xf;
      }
      if ((piVar6[1] <= iVar4 + 1) && (iVar4 + 1 <= piVar6[3])) {
        puVar1[0x280] = 0xc;
      }
      y1 = y1 + iStack_a;
      iStack_10 = iStack_10 + iStack_c;
      if (x2 - x1 <= iStack_10) {
        y1 = y1 + yStep;
        iStack_10 = iStack_10 - (x2 - x1);
      }
    }
  }
  return;
}



/* 5ded:01ac */

/* [R4] calls ovr_randBelow */

void __cdecl16far ovc27_usesRandBelow(int x1,int y1,int x2,int y2,brect_t *rect,byte rectSeg)

{
  /* Re-derived from 5ded:01ac (600 bytes).  Copies the three dither planes out of
     ditherPlane0/1/2, clamps the segment to the rect, then walks x at a Bresenham-ish step,
     picking a random dither column per pixel and writing the three planes at row offsets 0,
     0x140 and 0x280.  The planes are 0x20-byte buffers (the frame is sub sp,0x6e), not the
     single bytes the export declared. */
  int savedY2;
  int savedX2;
  uint8_t *rowPtr;
  uint16_t randPick;
  uint plane0Rem;
  uint plane0Sign;
  int rowY;
  int slopeY;
  int dirY;
  int stepFrac;
  int err;
  int x;
  byte ditherPhase;
  byte plane0 [0x20];
  byte plane1 [0x20];
  byte plane2 [0x20];
  far_t dstPlane;

  savedY2 = y2;
  savedX2 = x2;
  dstPlane.seg = _SS;
  dstPlane.ofs = (uint16_t)plane0;
  F_SCOPY(far_from_u32((uint32_t)(0x2410594a)),dstPlane,32);
  dstPlane.seg = _SS;
  dstPlane.ofs = (uint16_t)plane1;
  F_SCOPY(far_from_u32((uint32_t)(0x2410596a)),dstPlane,32);
  dstPlane.seg = _SS;
  dstPlane.ofs = (uint16_t)plane2;
  F_SCOPY(far_from_u32((uint32_t)(0x2410598a)),dstPlane,32);
  if (x2 < x1) {
    x2 = x1;
    x1 = savedX2;
    y2 = y1;
    y1 = savedY2;
  }
  if (x1 < rect->x) {
    x1 = rect->x;
  }
  if (rect->w < x2) {
    x2 = rect->w;
  }
  if (x1 <= x2) {
    if (x1 == x2) {
      slopeY = 0;
      stepFrac = 0;
    }
    else {
      slopeY = (y2 - y1) / (x2 - x1);
      plane0Rem = (y2 - y1) % (x2 - x1);
      plane0Sign = (int)plane0Rem >> 0xf;
      stepFrac = (plane0Rem ^ plane0Sign) - plane0Sign;
    }
    dirY = ovr_ovc07_signum(y2 - y1);
    err = x2 - x1 >> 1;
    ditherPhase = rectSeg;
    for (x = x1; x <= x2; x = x + 1) {
      ditherPhase = ditherPhase + 1 & 0xf;
      rowY = y1 + -1;
      rowPtr = (uint8_t *)(rowY * 0x140 + x);
      if ((((rect->y <= rowY) && (rowY <= rect->h)) &&
          (*(uint16_t *)(plane0 + (uint)ditherPhase * 2) != 0)) &&
         (randPick = ovr_randBelow(3,0), (randPick & 0xff) == 0)) {
        *rowPtr = plane0[(uint)ditherPhase * 2];
      }
      if (((rect->y <= y1) && (y1 <= rect->h)) &&
         ((*(uint16_t *)(plane1 + (uint)ditherPhase * 2) != 0 &&
          (randPick = ovr_randBelow(3,0), (randPick & 0xff) == 0)))) {
        rowPtr[0x140] = plane1[(uint)ditherPhase * 2];
      }
      if (((rect->y <= y1 + 1) && (y1 + 1 <= rect->h)) &&
         ((*(uint16_t *)(plane2 + (uint)ditherPhase * 2) != 0 &&
          (randPick = ovr_randBelow(3,0), (randPick & 0xff) == 0)))) {
        rowPtr[0x280] = plane2[(uint)ditherPhase * 2];
      }
      y1 = y1 + slopeY;
      err = err + stepFrac;
      if (x2 - x1 <= err) {
        y1 = y1 + dirY;
        err = err - (x2 - x1);
      }
    }
  }
  return;
}



/* 5ded:0404 */

/* [R7] body shape: compute */

uint __cdecl16far ovc27_compute1(agnt_t far *agnt,int param,uint16_t arg3,uint16_t arg4)

{
  uint in_AX;
  byte ptrHi2;
  undefined1 ptrHi1;
  uint result;
  
  if ((((agntG_t far *)agnt->gdata)->flags & 2) != 0) {
    ptrHi2 = (byte)((uint)(param * 0x34) >> 8);
    if (((Agnts[param].gdata->flags2 & 0x10) != 0) &&
       ((((entity_t *)agnt->entity)->base).level < 3)) {
      return (uint)ptrHi2 << 8;
    }
    return CONCAT11(ptrHi2,1);
  }
  if ((((agntG_t far *)agnt->gdata)->flags & 1) != 0) {
    in_AX = param * 0x34;
    ptrHi1 = (undefined1)(in_AX >> 8);
    if (((Agnts[param].gdata->flags & 4) != 0) &&
       (3 < (((entity_t *)agnt->entity)->base).level)) {
      return CONCAT11(ptrHi1,1);
    }
    if (9 < (((entity_t *)agnt->entity)->base).level) {
      return CONCAT11(ptrHi1,1);
    }
  }
  if (((((agntG_t far *)agnt->gdata)->flags & 0x800) == 0) ||
     (in_AX = param * 0x34,
     (Agnts[param].gdata->flags & 4) == 0)) {
    result = in_AX & 0xff00;
  }
  else {
    result = CONCAT11((char)(in_AX >> 8),1);
  }
  return result;
}



/* 5ded:04cd */

/* Rolls 1..40 against the owner's stat and returns whether the roll succeeds. */

int __cdecl16far ovc27_rollAgainstStat(agnt_t far *agnt,byte mode,uint16_t arg3,uint16_t arg4)

{
  /* Re-derived from 5ded:04cd.  Takes the leader index from the agent's entity record, looks the
     leader sheet up in the segment-0x70 table (GLeaderSheets), picks the byte at +0x29+mode as the
     target stat, rolls 0x28 and returns 1 when rand+1 <= target.  The leader index 0xff means a
     target of 6.  The exported `agnt = CONCAT13(uStack0007,CONCAT12(mode,agnt))` corrupted the
     parameter and is removed; the return is a plain 0/1 (every exit writes only AL). */
  byte leaderIdx;
  byte target;
  uint16_t roll;

  leaderIdx = AGNT_FIELD(&((entity_t *)agnt->entity)->base, entity, 3);
  if (leaderIdx == 0xff) {
    target = 6;
  }
  else {
    target = *(uint8_t far *)((uint8_t far *)GLeaderSheets[leaderIdx] + 0x29 + mode);
  }
  roll = ovr_randBelow(0x28,0);
  if (target < (uint16_t)((roll & 0xff) + 1)) {
    return 0;
  }
  return 1;
}



/* 5ded:052d */

/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc27_usesRandBelow3(agnt_t far *agnt,uint32_t reqRecord,int agntIndex)

{
  byte entityLevel;
  uint result;
  byte retHi;
  uint flagsMask;
  uint mask;
  uint maskByte;
  uint16_t packed;
  uint16_t roll;
  far_t reqFar;
  uint8_t far *rec;
  far_t dst;
  far_t dst_00;
  uint8_t reqLevel2;
  uint8_t reqLevel1;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)&reqLevel1;
  F_SCOPY(far_from_u32((uint32_t)(0x241059aa)),dst,10);
  dst_00.seg = _SS;
  dst_00.ofs = (uint16_t)&reqLevel2;
  F_SCOPY(far_from_u32((uint32_t)(0x241059b4)),dst_00,11);
  reqFar = far_from_u32(reqRecord);
  rec = (uint8_t far *)MK_FP(reqFar.seg,reqFar.ofs);
  if (*(char far *)(rec + 8) == '\0') {
    if ((((agntG_t far *)agnt->gdata)->flags & 2) == 0) {
      return result & 0xff00;
    }
    if ((((entity_t *)agnt->entity)->base).level < (&reqLevel1)[*(byte far *)(rec + 9)]) {
      return (uint)(&reqLevel1 + *(byte far *)(rec + 9)) & 0xff00;
    }
  }
  else {
    retHi = (byte)(result >> 8);
    if (*(char far *)(rec + 8) == '\x01') {
      if ((((agntG_t far *)agnt->gdata)->flags & 1) == 0) {
        return (uint)retHi << 8;
      }
      if ((((entity_t *)agnt->entity)->base).level < (&reqLevel2)[*(byte far *)(rec + 9)]) {
        return (uint)(&reqLevel2 + *(byte far *)(rec + 9)) & 0xff00;
      }
    }
    else if ((*(char far *)(rec + 8) == '\x02') && ((((agntG_t far *)agnt->gdata)->flags & 0x800) == 0))
    {
      return (uint)retHi << 8;
    }
  }
  if ((Agnts[agntIndex].gdata->flags & *(uint far *)(rec + 0x15)) == 0) {
    if ((Agnts[agntIndex].gdata->flags2 & *(uint far *)(rec + 0x19)) == 0) {
      if ((Agnts[agntIndex].gdata->flags3 & *(uint far *)(rec + 0x1d)) == 0) {
        if (((uint)Agnts[agntIndex].flags & *(uint far *)(rec + 0xf)) == 0) {
          flagsMask = (uint)*(byte far *)(rec + 0x13);
          if ((*(uint far *)((uint8_t far *)Agnts[agntIndex].entity + 0x14) & flagsMask) == 0) {
            if ((*(int far *)(rec + 0x17) != 0) &&
               (mask = *(uint far *)(rec + 0x17),
               (Agnts[agntIndex].gdata->flags & mask) == 0)) {
              return mask & 0xff00;
            }
            if ((*(int far *)(rec + 0x1b) != 0) &&
               (mask = *(uint far *)(rec + 0x1b),
               (Agnts[agntIndex].gdata->flags2 & mask) == 0)) {
              return mask & 0xff00;
            }
            if ((*(int far *)(rec + 0x1f) != 0) &&
               (mask = *(uint far *)(rec + 0x1f),
               (Agnts[agntIndex].gdata->flags3 & mask) == 0)) {
              return mask & 0xff00;
            }
            if ((*(int far *)(rec + 0x11) != 0) &&
               (mask = *(uint far *)(rec + 0x11), ((uint)Agnts[agntIndex].flags & mask) == 0)) {
              return mask & 0xff00;
            }
            if ((*(char far *)(rec + 0x14) == '\0') ||
               (maskByte = (uint)*(byte far *)(rec + 0x14),
               (*(uint far *)((uint8_t far *)Agnts[agntIndex].entity + 0x14) & maskByte) != 0)) {
              retHi = (byte)(maskByte >> 8);
              if ((*(char far *)(rec + 0xc) == '\0') || (Agnts[agntIndex].animVariant == '\0')) {
                entityLevel = *(uint8_t far *)((uint8_t far *)Agnts[agntIndex].entity + 0xf);
                packed = CONCAT11(retHi,entityLevel);
                if (entityLevel < *(byte far *)(rec + 0xe)) {
                  if ((*(byte far *)(rec + 0xd) < 100) &&
                     (roll = ovr_randBelow(100,0), *(byte far *)(rec + 0xd) <= (byte)roll)) {
                    return roll & 0xff00;
                  }
                  result = CONCAT11((char)(packed >> 8),1);
                }
                else {
                  result = (uint)retHi << 8;
                }
              }
              else {
                result = (uint)retHi << 8;
              }
            }
            else {
              result = 0;
            }
          }
          else {
            result = 0;
          }
        }
        else {
          result = *(uint far *)(rec + 0xf) & 0xff00;
        }
      }
      else {
        result = *(uint far *)(rec + 0x1d) & 0xff00;
      }
    }
    else {
      result = *(uint far *)(rec + 0x19) & 0xff00;
    }
  }
  else {
    result = *(uint far *)(rec + 0x15) & 0xff00;
  }
  return result;
}



/* 5ded:079d */

/* [R4] calls ovr_randBelow */

int __cdecl16far ovc27_usesRandBelow4(byte level,byte threshold)

{
  uint16_t in_AX;
  byte bVar3;
  int iVar1;
  uint16_t randVal;
  
  bVar3 = (byte)((uint)in_AX >> 8);
  if (level < threshold) {
    iVar1 = (uint)bVar3 << 8;
  }
  else if (level == threshold) {
    randVal = ovr_randBelow(8,0);
    if ((randVal & 0xff) == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = CONCAT11(bVar3,1);
  }
  return iVar1;
}



/* 5ded:07d0 */

/* [R7] body shape: compute */

uint __cdecl16far ovc27_compute2(agnt_t far *agnt,int param,uint16_t arg3,uint16_t arg4)

{
  uint rollResult;
  uint slotOfs;
  uint result;
  uint16_t firstRoll;
  byte mode;
  byte threshold;
  
  mode = (byte)param;
  if ((((agntG_t far *)agnt->gdata)->flags & 2) == 0) {
    if ((((agntG_t far *)agnt->gdata)->flags & 1) == 0) {
      if (((((((agntG_t far *)agnt->gdata)->flags & 0x800) != 0) &&
           (rollResult = ovc27_rollAgainstStat(agnt,mode,5,0), (char)rollResult != '\0')) &&
          (slotOfs = param * 0x34, (Agnts[param].flags & 0x7e0) == 0)) &&
         ((slotOfs = param * 0x34,
          (Agnts[param].gdata->flags3 & 0x80) == 0 &&
          (slotOfs = param * 0x34,
          (Agnts[param].gdata->flags & 4) != 0)))) {
        return CONCAT11((char)(slotOfs >> 8),1);
      }
      result = slotOfs & 0xff00;
    }
    else {
      firstRoll = ovc27_usesRandBelow3((agnt_t far *)CONCAT22(param,agnt),0x900108,param);
      if ((char)firstRoll == '\0') {
        result = ovc27_usesRandBelow3((agnt_t far *)CONCAT22(param,agnt),0x90014a,param);
        if ((char)result == '\0') {
          return result & 0xff00;
        }
        threshold = 10;
      }
      else {
        threshold = 4;
      }
      result = ovc27_usesRandBelow4((((entity_t *)agnt->entity)->base).level,threshold);
      if ((result & 0xff) == 0) {
        result = 0;
      }
      else {
        result = ovc27_rollAgainstStat(agnt,mode,2,0);
        if ((result & 0xff) == 0) {
          result = 0;
        }
        else {
          result = 1;
        }
      }
    }
  }
  else {
    result = ovc27_usesRandBelow4((((entity_t *)agnt->entity)->base).level,1);
    if ((result & 0xff) == 0) {
      result = 0;
    }
    else {
      if (((Agnts[param].gdata->flags2 & 0x10) == 0) ||
         (2 < (((entity_t *)agnt->entity)->base).level)) {
        result = ovc27_rollAgainstStat(agnt,mode,1,0);
        if ((result & 0xff) == 0) {
          result = 0;
        }
        else {
          result = 1;
        }
      }
      else {
        result = param * 0x34 & 0xff00;
      }
    }
  }
  return result;
}



/* 5ded:0960 */

/* WARNING: Variable defined which should be unmapped: indexMap */
/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc27_usesRandBelow5(agnt_t far *agnt)

{
  uint in_AX;
  uint result;
  uint16_t rollResult;
  uint16_t pick;
  uint8_t indexMap;
  byte mapIdx;
  byte count;
  
  if (((agnt_t far *)agnt)->target == 0xff) {
    result = in_AX & 0xff00;
  }
  else {
    _fmemset(MK_FP(_SS, &indexMap), 0, 0xf);
    count = 0;
    for (mapIdx = 0; mapIdx < 0xf; mapIdx = mapIdx + 1) {
      rollResult = ovc27_usesRandBelow3
                        (agnt,CONCAT22(0x90,(uint)mapIdx * 0x21),(uint)((agnt_t far *)agnt)->target)
      ;
      if ((char)rollResult != '\0') {
        (&indexMap)[count] = mapIdx + 1;
        count = count + 1;
      }
    }
    if (count == 0) {
      result = 0;
    }
    else {
      pick = ovr_randBelow((uint)count,0);
      result = CONCAT11((char)((uint)(&indexMap + (pick & 0xff)) >> 8),(&indexMap)[pick & 0xff]);
    }
  }
  return result;
}



/* 5ded:0a05 */

/* Formats the "%s casts a %s spell %s %s." notice. */

uint __cdecl16far ovc27_spellNotice(int agntIndex)

{
  byte bVar1;
  uint16_t uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint8_t *puVar7;
  char *msg;
  agntG_t far *paVar9;
  int *piVar10;
  uint16_t uVar11;
  uint16_t uVar12;
  long lVar13;
  static char text[64];   /* DGROUP-backed formatting buffer */
  byte variant;
  int iStack_12;
  int iStack_e;
  uint16_t uStack_8;
  agnt_t far *agnt;
  uint16_t agntSeg;
  
  agnt = (agnt_t far *)&Agnts[agntIndex].x;
  agntSeg = SEG_OF(Agnts);
  bVar1 = (byte)((uint)agnt >> 8);
  if ((((agntG_t far *)agnt->gdata)->flags & 0x803) == 0) {
    return (uint)bVar1 << 8;
  }
  if (agnt->animFrame == 0xff) {
    uStack_8 = SEG_OF(Agnts);
    uVar11 = uStack_8;
    uStack_8 = SEG_OF(Agnts);
    uVar12 = uVar11;
    if (((((((agntG_t far *)agnt->gdata)->flags & 0x1000) != 0) &&
         (uVar12 = uStack_8, (Agnts[agnt->target].gdata->flags2 & 0x10) == 0))
        && ((uStack_8 = uVar11, (Agnts[agnt->target].gdata->flags2 & 8) == 0
            || (bVar1 = ovr_agnt_compute9(agnt,0), uVar12 = uStack_8, '\0' < (char)bVar1)))) &&
       (uVar2 = ovr_randBelow(2,0), uVar12 = uStack_8, (uVar2 & 0xff) == 0)) {
      return 0;
    }
    uStack_8 = uVar12;
    uVar3 = ovc27_usesRandBelow5((agnt_t far *)MK_FP(agntSeg,agnt));
    variant = (byte)uVar3;
    uVar4 = uVar3 & 0xff;
    if (uVar4 == 0) {
      ovr_agnt_usesAnimFrame(agnt);
      uVar4 = uVar4 & 0xff00;
    }
    else {
      iVar5 = (uVar3 & 0xff) * 0x21;
      iVar6 = (uVar3 & 0xff) * 0x21;
      uVar2 = 0x90;
      uVar12 = (uint16_t)((ulong)agnt->gdata >> 0x10);
      paVar9 = (agntG_t far *)agnt->gdata;
                    /* WARNING: Load size is inaccurate */
      puVar7 = ovr_ovc15_usesStshRealloc
                         (paVar9->name,*(uint16_t *)((int)&paVar9->name + 2),
                          *(uint16_t *)(iVar6 + -0x21),*(uint16_t *)(iVar6 + -0x1f),
                          *(uint16_t *)(iVar5 + -0x1d),*(uint16_t *)(iVar5 + -0x1b),
                          far_ofs_u32(Agnts[agnt->target].gdata->name),(uint16_t)SEG_OF(Agnts[agnt->target].gdata->name));
      msg = ovr_stsprintf(text,(char *)CONCAT22(0x5ba4,_SS),
                          (char *)CONCAT22(puVar7,(char *)0x26510),uVar2);
      ovr_uiNotify(msg,uVar2,0);
      agnt->variant = variant;
      if (*(char *)((uint)variant * 0x21 + -0x17) == '9') {
        uVar3 = ovr_audio_panFromX(agnt,0);
        lVar13 = (ulong)uVar3 << 0x10;
        uVar2 = ovr_randBelow(2,0);
        ovr_play_sfxU((char)uVar2 + 0x39,(int)lVar13,(uint16_t)((ulong)lVar13 >> 0x10),0,0);
      }
      else {
        uVar2 = ovr_audio_panFromX(agnt,0);
        ovr_play_sfxU(*(byte *)((uint)variant * 0x21 + -0x17),0,uVar2,0,0);
      }
      if (*(char *)((uint)variant * 0x21 + -0x16) == '\0') {
        agnt->animFrame = 0xf5;
        uVar4 = 1;
      }
      else {
        uVar11 = *(uint16_t *)((int)&agnt->frames + 2);
        iStack_12 = CONCAT22(uVar11,*(int *)&agnt->frames);
        piVar10 = (int *)(*(int *)&agnt->frames + (uint)agnt->frameIndex * 4);
        iVar5 = piVar10[1];
        iVar6 = *piVar10;
        iStack_e = CONCAT22(iVar5,iVar6);
        if (iVar6 == 0 && iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x42);
        }
        agnt->animFrame = 0x0;
        *(char *)&agnt->destY = *(char *)(iVar6 + 0x15) + (char)agnt->screenY;
        if (agnt->level == 0x0) {
          uVar2 = *(int *)(iVar6 + 0x13) + agnt->screenX;
          agnt->destX = uVar2;
        }
        else {
          uVar2 = agnt->screenX - *(int *)(iVar6 + 0x13);
          agnt->destX = uVar2;
        }
        *(uint8_t *)((int)&agnt->destY + 1) = agnt->level;
        uVar4 = CONCAT11((char)(uVar2 >> 8),1);
      }
    }
    return uVar4;
  }
  return (uint)bVar1 << 8;
}



/* 5ded:0cc2 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc27_usesBlitGfxRect(int agntIndex,brect_t *rect,uint16_t type)

{
  uint16_t framesSeg;
  uint16_t spriteLo;
  agnt_t far *agnt;
  uint xPos;
  int framesOfs;
  uint8_t far *frames;
  far_t stateEntry;
  uint8_t far *state;
  int aimX;
  stg_tmp_t *stash;
  uint16_t spriteSeg;
  uint16_t *spritePtr;
  far_t gfx;
  far_t gfx_00;
  
  agnt = (agnt_t far *)&Agnts[agntIndex].x;
  if (((agnt->combatState == 0x0) && (agnt->target != 0xff)) && (agnt->animFrame != 0xff)) {
    framesSeg = *(uint16_t *)((int)&agnt->frames + 2);
    framesOfs = *(int *)&agnt->frames;
    frames = (uint8_t far *)MK_FP(framesSeg,(uint16_t)framesOfs);
    if (agnt->animVariant == 0x0) {
      stateEntry = *(far_t far *)(frames + 0xc);
    }
    else {
      stateEntry = *(far_t far *)(frames + 0x10);
    }
    state = (uint8_t far *)MK_FP(stateEntry.seg,stateEntry.ofs);
    if (agnt->level == 0x0) {
      xPos = agnt->screenX + *(int far *)(state + 0x13);
      if ((uint)Agnts[agnt->target].screenX <= xPos) {
        agnt->animFrame = 0xff;
        agnt->variant = 0x0;
        return;
      }
    }
    else {
      xPos = agnt->screenX - *(int far *)(state + 0x13);
      if (xPos <= (uint)Agnts[agnt->target].screenX) {
        agnt->animFrame = 0xff;
        agnt->variant = 0x0;
        return;
      }
    }
    spritePtr = (uint16_t *)(*(int *)&Agnts[agnt->target].frames + (uint)Agnts[agnt->target].frameIndex * 4);
    spriteLo = spritePtr[1];
    spriteSeg = *spritePtr;
    if (((int)Agnts[agnt->target].screenY != 0) || ((int)Agnts[agnt->target].screenX != 0)) {
      if (agnt->variant == 0x1) {
        if (agnt->animFrame < 0xfc) {
          ovc27_intelAttackingNotice
                    (xPos,*(int far *)(state + 0x15) + agnt->screenY,(int)Agnts[agnt->target].screenX,
                     (int)Agnts[agnt->target].screenY - (*(int *)(spriteSeg + 0xd) >> 1),
                     (int *)CONCAT22(type,rect));
        }
        xPos = agnt->animFrame & 3;
        gfx.seg = ((uint16_t *)&boltSpritesSeg)[xPos * 2];
        gfx.ofs = ((uint16_t *)&boltSpritesOfs)[xPos * 2];
        ovr_blitGfxRect(gfx,(int16_t)Agnts[agnt->target].screenX,(int)Agnts[agnt->target].screenY - (*(int *)(spriteSeg + 0xd) >> 1),rect,(uint8_t)type,true,0,0,0,0,0,0);
      }
      else {
        if (xPos < (uint)Agnts[agnt->target].screenX) {
          *(undefined1 *)&agnt->flags32 = 0;
          aimX = (int)Agnts[agnt->target].screenX + -8;
        }
        else {
          *(undefined1 *)&agnt->flags32 = 1;
          aimX = (int)Agnts[agnt->target].screenX + 8;
        }
        if (agnt->animFrame < 0xfb) {
          ovc27_usesRandBelow(xPos,*(int far *)(state + 0x15) + agnt->screenY,aimX,
                              (int)Agnts[agnt->target].screenY + -6,(brect_t *)CONCAT22(type,rect),
                              agnt->animFrame << 1);
        }
        if (0xf8 < agnt->animFrame) {
          stash = ovr_stash_usesStExit((stg_tmp_t *)*(uint16_t far *)((uint8_t far *)MK_FP(SprProjectiles.seg, SprProjectiles.ofs) +  0x8c),0,0);
          gfx_00.seg = spriteSeg;
          gfx_00.ofs = (uint16_t)(stash->cmap + 6);
          ovr_blitGfxRect(gfx_00,(int16_t)Agnts[agnt->target].screenX,(int16_t)Agnts[agnt->target].screenY,rect,(uint8_t)type,true,CONCAT11((char)((uint)stash >> 8),(char)agnt->flags32),0,0,0,0,0);
        }
      }
      agnt->animFrame = agnt->animFrame + 0x1;
      agnt->health = 0x2;
      if (agnt->animFrame == 0xff) {
        ovr_ovc41_resolveSpecialAttack((agnt_t far *)MK_FP(SEG_OF(Agnts),agnt),(uint)agnt->target);
        agnt->variant = 0x0;
        agnt->health = 0x0;
      }
    }
  }
  else {
    agnt->animFrame = 0xff;
    agnt->variant = 0x0;
  }
  return;
}



/* 5ded:0fd2 */

/* Notifies "%s takes half damage from spells." for the qualifying types and levels. */

uint __cdecl16far ovc27_spellHalfDamage(agnt_t far *agnt)

{
  uint in_AX;
  uint8_t *stashPtr;
  uint result;
  uint16_t in_DX;
  char *agntSegWord;
  char *statusText;
  char *notifyPtr;
  uint16_t blitSeg;
  uint8_t text;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  
  agntSegWord = (char *)((ulong)agnt >> 0x10);
  if (((((agntG_t far *)agnt->gdata)->shortName[3] == '\x04') &&
      (0xf < (((entity_t *)agnt->entity)->base).level)) ||
     ((((agntG_t far *)agnt->gdata)->shortName[3] == '\x06' &&
      (8 < (((entity_t *)agnt->entity)->base).level)))) {
    blitSeg = GSavedBlitSeg;
    statusText = ovr_agnt_statusText(agnt,(char *)CONCAT22(&text,agntSegWord),0);
    stashPtr = ovr_ovc15_usesStshRealloc(statusText,in_DX,blitSeg,0,0,0,0,0);
    notifyPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x5bbf,_SS),
                           (char *)CONCAT22(stashPtr,(char *)0x26510),in_DX);
    ovr_uiNotify(notifyPtr,in_DX,0);
    result = CONCAT11((char)((uint)notifyPtr >> 8),1);
  }
  else {
    result = in_AX & 0xff00;
  }
  return result;
}



/* 5ded:105e */

/* Notifies "%s takes half damage from dragon breath." for the qualifying types. */

uint __cdecl16far ovc27_breathHalfDamage(agnt_t far *agnt)

{
  uint in_AX;
  char *pcVar1;
  uint8_t *puVar2;
  uint uVar3;
  uint16_t in_DX;
  char *in_stack_00000006;
  uint16_t uVar4;
  uint8_t text;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  
  if (((((agntG_t far *)agnt->gdata)->shortName[3] == '\x05') &&
      (0xd < (((entity_t *)agnt->entity)->base).level)) ||
     ((((agntG_t far *)agnt->gdata)->shortName[3] == '\x06' &&
      (0xe < (((entity_t *)agnt->entity)->base).level)))) {
    uVar4 = GSavedBlitSeg;
    pcVar1 = ovr_agnt_statusText(agnt,(char *)CONCAT22(&text,in_stack_00000006),0);
    puVar2 = ovr_ovc15_usesStshRealloc(pcVar1,in_DX,uVar4,0,0,0,0,0);
    pcVar1 = ovr_stsprintf(msg,(char *)CONCAT22(0x5be1,_SS),
                           (char *)CONCAT22(puVar2,(char *)0x26510),in_DX);
    ovr_uiNotify(pcVar1,in_DX,0);
    uVar3 = CONCAT11((char)((uint)pcVar1 >> 8),1);
  }
  else {
    uVar3 = in_AX & 0xff00;
  }
  return uVar3;
}



/* 5ded:10ea */

/* [R2] string "%s takes half damage from lightning." */

void __cdecl16far ovc27_textTakesHalfDamage3(agnt_t far *agnt,uint16_t agntIndex,uint16_t arg3,uint16_t arg4)

{
  byte roll;
  uint damage;
  uint16_t halfRoll;
  uint16_t randRoll;
  int hitRoll;
  char far *statusText;
  uint8_t far *stashPtr;
  uint16_t agntSeg;
  uint8_t text1;
  uint8_t text2;
  uint8_t msg;
  agnt_t far *agntRec;
  char *ptrSeg;
  int levelBonus;
  
  uint *puVar1;
  uint32_t uVar2;
  byte bVar3;
  uint16_t uVar4;
  int iVar5;
  uint16_t pan;
  uint uVar7;
  char far *pcVar8;
  uint8_t far *bufPtr;
  uint16_t in_DX;
  int unaff_BP;
  int unaff_DI;
  int half4Remaining;
  int half4LoopIdx;
  char far *st1;
  ptrSeg = (char *)((int)&AgntAnms[0x75].halfWidth + 1);
  /* 0016-001B: the original builds {seg: 0x50, ofs: agntIndex*0x34}. */
  agntRec = (agnt_t far *)MK_FP(SEG_OF(Agnts),(uint16_t)(agntIndex * 0x34));
  if (agnt->variant == 0x1) {
    if ((((agntG_t far *)agnt->gdata)->flags3 & 1) == 0) {
      roll = ovr_manage_rollDice((((entity_t *)agnt->entity)->base).level,'\x06');
      damage = (uint)roll;
      halfRoll = ovc27_spellHalfDamage
                        ((agnt_t far *)
                         agntRec)
      ;
      if ((char)halfRoll != '\0') {
        damage = (int)damage >> 1;
      }
    }
    else {
      damage = (uint)agnt->strength;
  halfRoll = ovc27_breathHalfDamage(agntRec);
      if ((char)halfRoll != '\0') {
        damage = (int)damage >> 1;
      }
    }
    if ((((agntG_t far *)agntRec->gdata)->flags3 & 1) == 0) {
      hitRoll = ovc27_rollToHitEntity
                        ((uint32_t)agntRec,
                         3);
      if ((char)hitRoll != '\0') {
        damage = (int)damage >> 1;
  } ovr_ovc41_textParalyzed(agnt,agntRec,damage);
      *(undefined1 *)&agntRec->state = 0xb;
      *(undefined1 *)((int)&agntRec->state + 1) = 0;
      return;
    }
  statusText = ovr_agnt_statusText((char far *)MK_FP(_SS,&text2),agntRec);
    stashPtr = ovr_ovc15_usesStshRealloc(statusText);
    statusText = ovr_stsprintf((char far *)MK_FP(_SS,&msg),(char far *)MK_FP(_DS,0x5c0a),stashPtr);
  ovr_uiNotify(statusText,(uint16_t)GSavedBlitSeg);
    return;
  }
  if (agnt->variant == 0x2) {
    levelBonus = ((((entity_t *)agnt->entity)->base).level / 5) * 2 + 1;
    roll = ovr_manage_rollDice((char)levelBonus,'\x06');
    damage = (uint)roll + levelBonus;
    halfRoll = ovc27_spellHalfDamage
                      ((agnt_t far *)
                       agntRec);
    if ((char)halfRoll != '\0') {
      damage = (int)damage >> 1;
  } ovr_ovc41_textParalyzed(agnt,agntRec,damage);
    *(undefined1 *)&agntRec->state = 0xb;
    *(undefined1 *)((int)&agntRec->state + 1) = 0;
    return;
  }
  if (agnt->variant == 0xa) {
    if ((agntRec->flags & 0x420) != 0) {
      return;
  } randRoll = ovr_randBelow(3);
    if (((randRoll & 0xff) == 0) &&
       (damage = ovc27_rollToHitEntity
                          (CONCAT13((char)((uint)ptrSeg >> 8),CONCAT12((char)ptrSeg,agntRec)
                                   ),3), (damage & 0xff) == 0)) {
  statusText = ovr_agnt_statusText((char far *)MK_FP(_SS,&text1),agnt);
  statusText = ovr_agnt_statusText((char far *)MK_FP(_SS,&text2),agntRec);
  st1 = statusText;
      stashPtr = ovr_ovc15_usesStshRealloc(statusText);
  statusText = ovr_stsprintf((char far *)MK_FP(_SS,&msg),(char far *)MK_FP(_DS,0x5c2f),st1,stashPtr);
  ovr_uiNotify(statusText,(uint16_t)GSavedBlitSeg);
  ovr_OVC41_6a8f_01e7_entry(agntRec);
      agntRec->faction = agnt->faction;
      agntRec->flags = agntRec->flags | 0x20;
      agntSeg = ovr_audio_panFromX(agntRec);
      ovr_play_sfxU(0x1b,0,agntSeg);
      return;
    }
  statusText = ovr_agnt_statusText((char far *)MK_FP(_SS,&text1),agntRec);
  statusText = ovr_agnt_statusText((char far *)MK_FP(_SS,&text2),agnt);
  st1 = statusText;
    stashPtr = ovr_ovc15_usesStshRealloc(statusText);
  statusText = ovr_stsprintf((char far *)MK_FP(_SS,&msg),(char far *)MK_FP(_DS,0x5c44),st1,stashPtr);
  ovr_uiNotify(statusText,(uint16_t)GSavedBlitSeg);
    agntRec->flags = agntRec->flags | 0x400;
    return;
  }
  if ((agnt->variant != 0x3) && (agnt->variant != 0x5)) {
    goto L_half4;
  }
  if ((agntRec->flags & 0x20) != 0) {
    return;
  }
  hitRoll = ovc27_rollToHitEntity((uint32_t)MK_FP(SEG_OF(Agnts), agntRec),3);
  if ((char)hitRoll == '\0') {
  statusText = ovr_agnt_statusText((char far *)MK_FP(_SS,&text1),agnt);
  statusText = ovr_agnt_statusText((char far *)MK_FP(_SS,&text2),agntRec);
  st1 = statusText;
    stashPtr = ovr_ovc15_usesStshRealloc(statusText);
  statusText = ovr_stsprintf((char far *)MK_FP(_SS,&msg),(char far *)MK_FP(_DS,0x5c2f),st1,stashPtr);
  ovr_uiNotify(statusText,(uint16_t)GSavedBlitSeg);
    agntRec->faction = agnt->faction;
  ovr_OVC41_6a8f_01e7_entry(agntRec);
    agntRec->flags = agntRec->flags | 0x20;
    agntSeg = ovr_audio_panFromX(agntRec);
    ovr_play_sfxU(0x1b,0,agntSeg);
    return;
  }
  return;
L_half4:
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\x04') {
  pan = ovr_audio_panFromX(agntRec);
  ovr_play_sfxU(0x4c,0,pan);
    uVar2 = ((agnt_t far *)((unaff_BP + -10)))->gdata;
    if ((*(uint *)((int)uVar2 + 0x40) & 0x20) == 0) {
      ovr_ovc28_usesBDADailyTimeCounter(6);
      uVar2 = ((agnt_t far *)((unaff_BP + 6)))->entity;
      bVar3 = ovr_manage_rollDice(*(char *)((int)uVar2 + 0xf),'\x06');
      uVar7 = bVar3 + 1;
      iVar5 = ovc27_rollToHitEntity
                        (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                  CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                           *(uint16_t *)(unaff_BP + -10))),3);
      if ((char)iVar5 != '\0') {
        uVar7 = (int)uVar7 >> 1;
      }
      uVar4 = ovc27_spellHalfDamage
                        ((agnt_t far *)
                         CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                  CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                           *(uint16_t *)(unaff_BP + -10))));
      if ((char)uVar4 != '\0') {
        uVar7 = (int)uVar7 >> 1;
      }
      uVar2 = ((agnt_t far *)((unaff_BP + -10)))->gdata;
      if ((*(uint *)((int)uVar2 + 0x3e) & 0x200) != 0) {
  pcVar8 = ovr_agnt_statusText((char far *)MK_FP(_SS,&text2),agntRec);
  bufPtr = ovr_ovc15_usesStshRealloc(pcVar8);
  pcVar8 = ovr_stsprintf((char far *)MK_FP(_SS,&msg),(char far *)MK_FP(_DS,0x5c70),bufPtr);
  ovr_uiNotify(pcVar8,(uint16_t)GSavedBlitSeg);
        uVar7 = (int)uVar7 >> 1;
      }
  ovr_ovc41_textParalyzed(agnt,agntRec,uVar7);
      ((char_sheet_t *)((unaff_BP + -10)))->race = 10;
      ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
      return;
    }
  pcVar8 = ovr_agnt_statusText((char far *)MK_FP(_SS,&text2),agntRec);
  bufPtr = ovr_ovc15_usesStshRealloc(pcVar8);
  pcVar8 = ovr_stsprintf((char far *)MK_FP(_SS,&msg),(char far *)MK_FP(_DS,0x5c5a),bufPtr);
  ovr_uiNotify(pcVar8,(uint16_t)GSavedBlitSeg);
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\x06') {
    if (*(char *)((int)*(uint32_t *)(unaff_BP + -10) + 0x11) != '\0') {
      return;
    }
    if ((((agnt_t far *)((unaff_BP + -10)))->flags & 0x40) == 0) {
      iVar5 = ovc27_rollToHitEntity
                        (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                  CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                           *(uint16_t *)(unaff_BP + -10))),3);
      if ((char)iVar5 == '\0') {
  pcVar8 = ovr_agnt_statusText((char far *)MK_FP(_SS,&text1),agnt);
  st1 = pcVar8;
  pcVar8 = ovr_agnt_statusText((char far *)MK_FP(_SS,&text2),agntRec);
  bufPtr = ovr_ovc15_usesStshRealloc(pcVar8);
  pcVar8 = ovr_stsprintf((char far *)MK_FP(_SS,&msg),(char far *)MK_FP(_DS,0x5c90),st1,bufPtr);
  ovr_uiNotify(pcVar8,(uint16_t)GSavedBlitSeg);
  ovr_OVC41_6a8f_01e7_entry(agntRec);
        puVar1 = (uint *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2b);
        *puVar1 = *puVar1 | 0x40;
        ((char_sheet_t *)((unaff_BP + -10)))->race = 0x10;
        ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
  pan = ovr_audio_panFromX(agntRec);
  ovr_play_sfxU(0x1b,0,pan);
        return;
      }
      return;
    }
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\a') {
    if (*(char *)((int)*(uint32_t *)(unaff_BP + -10) + 0x11) != '\0') {
      return;
    }
    if ((((agnt_t far *)((unaff_BP + -10)))->flags & 0x80) == 0) {
      uVar2 = ((agnt_t far *)((unaff_BP + -10)))->entity;
      if (*(byte *)((int)uVar2 + 0xf) < 5) {
  pcVar8 = ovr_agnt_statusText((char far *)MK_FP(_SS,&text1),agnt);
  st1 = pcVar8;
  pcVar8 = ovr_agnt_statusText((char far *)MK_FP(_SS,&text2),agntRec);
  bufPtr = ovr_ovc15_usesStshRealloc(pcVar8);
  pcVar8 = ovr_stsprintf((char far *)MK_FP(_SS,&msg),(char far *)MK_FP(_DS,0x5ca2),st1,bufPtr);
  ovr_uiNotify(pcVar8,(uint16_t)GSavedBlitSeg);
  ovr_OVC41_6a8f_01e7_entry(agntRec);
        puVar1 = (uint *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2b);
        *puVar1 = *puVar1 | 0x80;
  pan = ovr_audio_panFromX(agntRec);
  ovr_play_sfxU(0x1b,0,pan);
        ((char_sheet_t *)((unaff_BP + -10)))->race = 0xc;
        ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
        return;
      }
      return;
    }
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\b') {
    if (*(char *)((int)*(uint32_t *)(unaff_BP + -10) + 0x11) != '\0') {
      return;
    }
    if ((((agnt_t far *)((unaff_BP + -10)))->flags & 0x100) == 0) {
  pcVar8 = ovr_agnt_statusText((char far *)MK_FP(_SS,&text1),agnt);
  st1 = pcVar8;
  pcVar8 = ovr_agnt_statusText((char far *)MK_FP(_SS,&text2),agntRec);
  bufPtr = ovr_ovc15_usesStshRealloc(pcVar8);
  pcVar8 = ovr_stsprintf((char far *)MK_FP(_SS,&msg),(char far *)MK_FP(_DS,0x5cbc),st1,bufPtr);
  ovr_uiNotify(pcVar8,(uint16_t)GSavedBlitSeg);
      ((char_sheet_t *)((unaff_BP + -10)))->alignment =
           *(undefined1 *)((int)*(uint32_t *)(unaff_BP + 6) + 0x32);
      ((char_sheet_t *)((unaff_BP + -10)))->race = 0xd;
      ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 5;
      puVar1 = (uint *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x100;
  pan = ovr_audio_panFromX(agntRec);
  ovr_play_sfxU(0x1b,0,pan);
      return;
    }
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\t') {
    if ((((agnt_t far *)((unaff_BP + -10)))->flags & 0x40) != 0) {
      return;
    }
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                         *(uint16_t *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
  pcVar8 = ovr_agnt_statusText((char far *)MK_FP(_SS,&text1),agnt);
  st1 = pcVar8;
  pcVar8 = ovr_agnt_statusText((char far *)MK_FP(_SS,&text2),agntRec);
  bufPtr = ovr_ovc15_usesStshRealloc(pcVar8);
  pcVar8 = ovr_stsprintf((char far *)MK_FP(_SS,&msg),(char far *)MK_FP(_DS,0x5c90),st1,bufPtr);
  ovr_uiNotify(pcVar8,(uint16_t)GSavedBlitSeg);
  ovr_OVC41_6a8f_01e7_entry(agntRec);
      puVar1 = (uint *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x40;
      ((char_sheet_t *)((unaff_BP + -10)))->race = 0x10;
      ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
  pan = ovr_audio_panFromX(agntRec);
  ovr_play_sfxU(0x1b,0,pan);
      return;
    }
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\v') {
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                         *(uint16_t *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
      bVar3 = ((agnt_t far *)((unaff_BP + -10)))->strength;
  ovr_ovc41_textParalyzed(agnt,agntRec,(uint)bVar3);
      ((char_sheet_t *)((unaff_BP + -10)))->race = 0xb;
      ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
      return;
    }
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\f') {
    uVar2 = ((agnt_t far *)((unaff_BP + -10)))->entity;
    if (7 < *(byte *)((int)uVar2 + 0xf)) {
      return;
    }
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                         *(uint16_t *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
      bVar3 = ((agnt_t far *)((unaff_BP + -10)))->strength;
  ovr_ovc41_textParalyzed(agnt,agntRec,(uint)bVar3);
      ((char_sheet_t *)((unaff_BP + -10)))->race = 0xb;
      ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
      return;
    }
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\r') {
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                         *(uint16_t *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
      bVar3 = ((agnt_t far *)((unaff_BP + -10)))->strength;
  ovr_ovc41_textParalyzed(agnt,agntRec,(uint)bVar3);
      ((char_sheet_t *)((unaff_BP + -10)))->race = 0xb;
      ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
      return;
    }
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\x0e') {
    if (*(char *)((int)*(uint32_t *)(unaff_BP + -10) + 0x11) != '\0') {
      return;
    }
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                         *(uint16_t *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
  ovr_OVC41_6a8f_01e7_entry(agntRec);
      puVar1 = (uint *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x800;
  pan = ovr_audio_panFromX(agntRec);
  ovr_play_sfxU(0x1b,0,pan);
      return;
    }
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant != '\x0f') {
    return;
  }
  half4Remaining = 0x1e;
  half4LoopIdx = 0;
  do {
    if (((((agnt_t far *)((unaff_BP + -10)))->flags & 0x20) == 0) &&
       (uVar7 = ovc27_rollToHitEntity
                          (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                    CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                             *(uint16_t *)(unaff_BP + -10))),3),
       (uVar7 & 0xff) == 0)) {
  pcVar8 = ovr_agnt_statusText((char far *)MK_FP(_SS,&text1),agnt);
  st1 = pcVar8;
  pcVar8 = ovr_agnt_statusText((char far *)MK_FP(_SS,&text2),agntRec);
  bufPtr = ovr_ovc15_usesStshRealloc(pcVar8);
  pcVar8 = ovr_stsprintf((char far *)MK_FP(_SS,&msg),(char far *)MK_FP(_DS,0x5c2f),st1,bufPtr);
  ovr_uiNotify(pcVar8,(uint16_t)GSavedBlitSeg);
  ovr_OVC41_6a8f_01e7_entry(agntRec);
      *(undefined1 *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2f) =
           *(undefined1 *)((int)*(uint32_t *)(unaff_BP + 6) + 0x2f);
      puVar1 = (uint *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x20;
  pan = ovr_audio_panFromX(agntRec);
  ovr_play_sfxU(0x1b,0,pan);
    }
    do {
      agntRec = ovc27_usesAgntCount((agnt_t far *)
                                   CONCAT22(*(uint16_t *)(unaff_BP + 8),
                                            (agnt_t far *)*(uint16_t *)(unaff_BP + 6)),0xe,
                                   (byte)half4Remaining,
                                   (int far *)&half4LoopIdx);
      if (agntRec == (agnt_t far *)0) break;
    } while (half4LoopIdx == (int)agntIndex);
    if (*(int *)(unaff_BP + -10) != 0 || *(int *)(unaff_BP + -8) != 0) {
      uVar2 = ((agnt_t far *)((unaff_BP + -10)))->entity;
      half4Remaining = half4Remaining - (uint)*(byte *)((int)uVar2 + 0xf);
    }
    if ((*(int *)(unaff_BP + -10) == 0 && *(int *)(unaff_BP + -8) == 0) ||
       (half4Remaining == 0)) {
      return;
    }
  } while( true );
}



/* 5ded:1433 */

/* [R2] string "%s is charmed by %s." */

uint16_t __cdecl16far ovc27_textCharmed()

{
  uint *puVar1;
  char *pcVar2;
  uint8_t *puVar3;
  uint16_t unk;
  uint16_t in_DX;
  int unaff_BP;
  char *in_stack_00000000;
  
  pcVar2 = ovr_agnt_statusText((agnt_t far *)*(uint16_t *)(unaff_BP + -10),in_stack_00000000,0);
  puVar3 = ovr_ovc15_usesStshRealloc(pcVar2,0,0,0,0,0,0,0);
  pcVar2 = ovr_stsprintf((char *)(unaff_BP + -0x82),(char *)CONCAT22(0x5c2f,_SS),
                         (char *)CONCAT22(puVar3,(char *)0x26510));
  ovr_uiNotify(pcVar2,in_DX,0);
  *(undefined1 *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2f) =
       *(undefined1 *)((int)*(uint32_t *)(unaff_BP + 6) + 0x2f);
  ovr_OVC41_6a8f_01e7_entry((agnt_t far *)*(uint16_t *)(unaff_BP + -10),0);
  puVar1 = (uint *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2b);
  *puVar1 = *puVar1 | 0x20;
  unk = ovr_audio_panFromX((agnt_t far *)*(uint16_t *)(unaff_BP + -10),0);
  ovr_play_sfxU(0x1b,0,unk,0,0);
  return;
}



/* 5ded:1beb */

/* [R6] touches AgntCount */

agnt_t far * __cdecl16far ovc27_usesAgntCount(agnt_t far *agnt,byte recIndex,byte maxLevel,int far *cursor)

{
  int foundIdx;
  uint32_t recPtr;
  uint16_t roll;
  
  while( true ) {
    if ((int)(uint)AgntCount <= *cursor) {
      return (agnt_t far *)0;
    }
    recPtr = *(uint32_t *)(*cursor * 0x34 + 0x17);
    if (((*(byte *)((int)recPtr + 0xf) <= maxLevel) &&
        (*(uint8_t *)*(uint32_t *)(*cursor * 0x34 + 0x1d) != ((agnt_t far *)agnt)->faction)) &&
       (roll = ovc27_usesRandBelow3(agnt,CONCAT22(0x90,(uint)recIndex * 0x21),*cursor),
       (char)roll != '\0')) break;
    *cursor = *cursor + 1;
  }
  foundIdx = *cursor;
  *cursor = *cursor + 1;
  return (agnt_t far *)MK_FP(SEG_OF(Agnts),foundIdx * 0x34);
}



/* 5ded:1c94 */
int __cdecl16far ovc27_rollToHitEntity(uint32_t agnt,byte column)

{
  /* Re-derived.  `ability` is read through the agent record; the ramp index comes from
     the leader sheet (0xff normalises to 0, and a negative ?sheet value < 4 halves the
     ability).  RampTables[rampIdx] is a far table row of 6-byte strides, walked until
     its first byte is 0xff or not less than ability; the column+1 byte of that row is
     the target number.  Column 3 subtracts the ability modifier.  The return arithmetic
     is left exactly as the export has it. */
  uint32_t sheetRef;
  char abilityMod;
  uint16_t roll;
  int agntOfs;
  byte ability;
  byte rampIdx;
  byte toHit;
  byte *rampRow;
  int result;

  agntOfs = (int)agnt;
  ability = *(byte *)((int)*(uint32_t *)(agntOfs + 0x17) + 0xf);
  rampIdx = *(byte *)((int)*(uint32_t *)(agntOfs + 0x1d) + 0x46);
  if ((rampIdx == 0xff) &&
     (rampIdx = 0, *(byte *)((int)*(uint32_t *)(agntOfs + 0x1d) + 0x53) < 4)) {
    ability = ability >> 1;
  }
  rampRow = (byte *)CONCAT22(*(uint16_t *)((int)&RampTables[0].seg + (uint)rampIdx * 4),
                             (byte *)((far_t far *)RampTables + rampIdx)->ofs);
  while ((*rampRow != 0xff && (*rampRow < ability))) {
    rampRow = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(rampRow) + 2)),
                               (byte *)rampRow + 6);
  }
  toHit = ((byte *)rampRow)[column + 1];
  if ((column == 3) && (*(char *)((int)*(uint32_t *)(agntOfs + 0x17) + 0x1a) != -1)) {
    sheetRef = *(uint32_t *)((uint)*(byte *)((int)*(uint32_t *)(agntOfs + 0x17) + 0x1a)
                             << 2);
    abilityMod = ovr_manage_abilityModifier(*(byte *)((int)sheetRef + 0x2b));
    toHit = toHit - abilityMod;
  }
  roll = ovr_randBelow(0x14,0);
  if ((int)((roll & 0xff) + 1) < (int)(char)toHit) {
    result = (uint)(byte)((char)toHit >> 7) << 8;
  }
  else {
    result = CONCAT11((char)toHit >> 7,1);
  }
  return result;
}


/* 5ded:1d8e */
int __cdecl16far ovc27_rollToHitAgent(uint32_t agnt,byte column)

{
  /* Re-derived; same shape as ovc27_rollToHitEntity but the ability and ramp index are
     read straight out of the agent record, and column 3 first stores 0x12 into the
     sheet's +0x2b byte before taking the ability modifier.  The return arithmetic is
     left exactly as the export has it. */
  uint32_t sheetRef;
  char abilityMod;
  uint16_t roll;
  int agntOfs;
  byte ability;
  byte rampIdx;
  byte toHit;
  byte *rampRow;
  int result;

  agntOfs = (int)agnt;
  ability = *(byte *)(agntOfs + 0xf);
  rampIdx = AgntGs[(uint)*(byte *)(agntOfs + 0xd)].shortName[3];
  if ((rampIdx == 0xff) &&
     (rampIdx = 0,
     *(byte *)((int)&worldMenuLabels[0xc].seg + (uint)*(byte *)(agntOfs + 0xd) * 0x95) < 4)) {
    ability = ability >> 1;
  }
  rampRow = (byte *)CONCAT22(*(uint16_t *)((int)&RampTables[0].seg + (uint)rampIdx * 4),
                             (byte *)((far_t far *)RampTables + rampIdx)->ofs);
  while ((*rampRow != 0xff && (*rampRow < ability))) {
    rampRow = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(rampRow) + 2)),
                               (byte *)rampRow + 6);
  }
  toHit = ((byte *)rampRow)[column + 1];
  if ((column == 3) && (*(char *)(agntOfs + 0x1a) != -1)) {
    sheetRef = *(uint32_t *)((uint)*(byte *)(agntOfs + 0x1a) << 2);
    *(undefined1 *)((int)sheetRef + 0x2b) = 0x12;
    sheetRef = *(uint32_t *)((uint)*(byte *)(agntOfs + 0x1a) << 2);
    abilityMod = ovr_manage_abilityModifier(*(byte *)((int)sheetRef + 0x2b));
    toHit = toHit - abilityMod;
  }
  roll = ovr_randBelow(0x14,0);
  if ((int)((roll & 0xff) + 1) < (int)(char)toHit) {
    result = (uint)(byte)((char)toHit >> 7) << 8;
  }
  else {
    result = CONCAT11((char)toHit >> 7,1);
  }
  return result;
}


/* 5ded:1eb7 */

/* [R7] body shape: compute */

uint16_t __cdecl16far ovc27_compute3(uint32_t view,char frames)

{
  uint16_t segWord;
  uint16_t ofsWord;
  byte advance;
  int rampOfs;
  far_t viewFar;
  uint8_t far *viewRec;
  bool exhausted;
  byte rampIdx;
  uint total;
  
  total = 0;
  while( true ) {
    viewFar = far_from_u32(view);
    viewRec = (uint8_t far *)MK_FP(viewFar.seg,viewFar.ofs);
    if ((frames == '\0') || (*(char far *)(viewRec + 0xf) == '\0')) break;
    advance = ovr_ovc15_textView(view);
    total = total + advance;
    *(char far *)(viewRec + 0xf) = *(char far *)(viewRec + 0xf) + -1;
    frames = frames + -1;
  }
  exhausted = *(char far *)(viewRec + 0xf) == '\0';
  if (exhausted) {
    *(undefined1 far *)(viewRec + 0xf) = 1;
  }
  if (total < *(byte far *)(viewRec + 0x32)) {
    *(char far *)(viewRec + 0x32) = *(char far *)(viewRec + 0x32) - (char)total;
  }
  else {
    *(undefined1 far *)(viewRec + 0x32) = 1;
  }
  if (total < *(byte far *)(viewRec + 0x31)) {
    *(char far *)(viewRec + 0x31) = *(char far *)(viewRec + 0x31) - (char)total;
  }
  else {
    *(undefined1 far *)(viewRec + 0x31) = 1;
  }
  if (*(byte far *)(viewRec + 0x32) < *(byte far *)(viewRec + 0x31)) {
    *(undefined1 far *)(viewRec + 0x31) = *(undefined1 far *)(viewRec + 0x32);
  }
  rampIdx = AgntGs[(uint)*(byte far *)(viewRec + 0xd)].shortName[3];
  if (rampIdx == 0xff) {
    rampIdx = 0;
  }
  rampOfs = (uint)rampIdx * 0x94 + (uint)*(byte far *)(viewRec + 0xf) * 4;
  segWord = *(uint16_t *)(rampOfs + -2);
  ofsWord = *(uint16_t *)(rampOfs + -4);
  *(uint16_t far *)(viewRec + 0x12) = segWord;
  *(uint16_t far *)(viewRec + 0x10) = ofsWord;
  return CONCAT11((char)((uint)segWord >> 8),exhausted);
}



/* 5ded:1fe1 */

/* [R4] calls ovr_play_sfxU */

uint __cdecl16far
ovc27_usesPlay_sfxU(uint16_t ptrOfs,uint16_t ptrSeg,agnt_t far *agnt,uint8_t frames,uint16_t arg5,uint16_t arg6)

{
  /* Re-derived: when ovc27_compute3 says the agent is not ready, lower the strengthMax of every
     agent of the same owner to entity+0x32 and clamp strength to it, then play sfx 0x1c panned by
     audio_panFromX and return 1; otherwise hand off to ovc41_settleAgentCombat and return its
     high byte.  The dead segment half uVar6 is gone. */
  uint16_t entSeg;
  int entOfs;
  uint16_t computed;
  uint result;
  uint16_t pan;
  agnt_t far *a;
  int agntIdx;

  a = (agnt_t far *)agnt;
  entSeg = *(uint16_t *)((int)&a->entity + 2);
  entOfs = *(int *)&a->entity;
  computed = ovc27_compute3(CONCAT22(entSeg,entOfs),frames);
  if ((char)computed == '\0') {
    for (agntIdx = 0; agntIdx < (int)(uint)AgntCount; agntIdx = agntIdx + 1) {
      if (Agnts[agntIdx].owner == a->owner) {
        if (*(byte *)(entOfs + 0x32) < Agnts[agntIdx].strengthMax) {
          Agnts[agntIdx].strengthMax = *(undefined1 *)(entOfs + 0x32);
        }
        if (Agnts[agntIdx].strengthMax < Agnts[agntIdx].strength) {
          Agnts[agntIdx].strength = Agnts[agntIdx].strengthMax;
        }
      }
    }
    pan = ovr_audio_panFromX(a,(char)((ulong)agnt >> 0x10));
    ovr_play_sfxU(0x1c,0,pan,(char)pan,0);
    result = 1;
  }
  else {
    result = ovr_ovc41_settleAgentCombat
               ((agnt_t far *)CONCAT13((char)(ptrSeg >> 8),CONCAT12((char)ptrSeg,ptrOfs)),agnt,0);
    result = result & 0xff00;
  }
  return result;
}



/* 5ded:218c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* duplicate name, disambiguated by address order */

void switchD_6000_3cd8__caseD_0_3(void)

{
  int unaff_BP;
  int unaff_SI;
  
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + '\x01';
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


