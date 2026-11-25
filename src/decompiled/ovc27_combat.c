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
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint16_t uVar7;
  byte in_stack_00000010;
  far_t dst;
  uint8_t yOffset;
  int iStack_10;
  int yStep;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  byte bStack_3;
  
  iVar5 = y2;
  iVar4 = x2;
  dst.seg = _SS;
  dst.ofs = (uint16_t)&yOffset;
  F_SCOPY(far_from_u32((uint32_t)(0x2410592a)),dst);
  if (x2 < x1) {
    x2 = x1;
    x1 = iVar4;
    iStack_6 = y2;
    y2 = y1;
    y1 = iVar5;
  }
  if (x1 < *rectOfs) {
    x1 = *rectOfs;
  }
  uVar7 = (uint16_t)((ulong)rectOfs >> 0x10);
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
      uVar2 = (y2 - y1) % (x2 - x1);
      uVar3 = (int)uVar2 >> 0xf;
      iStack_c = (uVar2 ^ uVar3) - uVar3;
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
  F_SCOPY(far_from_u32((uint32_t)(0x2410594a)),dstPlane);
  dstPlane.seg = _SS;
  dstPlane.ofs = (uint16_t)plane1;
  F_SCOPY(far_from_u32((uint32_t)(0x2410596a)),dstPlane);
  dstPlane.seg = _SS;
  dstPlane.ofs = (uint16_t)plane2;
  F_SCOPY(far_from_u32((uint32_t)(0x2410598a)),dstPlane);
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
  uint32_t uVar1;
  uint in_AX;
  byte bVar3;
  undefined1 uVar4;
  uint uVar2;
  int in_stack_00000008;
  
  if ((((agntG_t far *)agnt->gdata)->flags & 2) != 0) {
    uVar1 = *(uint32_t far *)&Agnts[in_stack_00000008].gdata;
    bVar3 = (byte)((uint)(in_stack_00000008 * 0x34) >> 8);
    if (((*(uint *)((int)uVar1 + 0x3e) & 0x10) != 0) &&
       ((((entity_t *)agnt->entity)->base).level < 3)) {
      return (uint)bVar3 << 8;
    }
    return CONCAT11(bVar3,1);
  }
  if ((((agntG_t far *)agnt->gdata)->flags & 1) != 0) {
    in_AX = in_stack_00000008 * 0x34;
    uVar4 = (undefined1)(in_AX >> 8);
    if (((((agntG_t *)((in_AX + 0x1d)))->flags & 4) != 0) &&
       (3 < (((entity_t *)agnt->entity)->base).level)) {
      return CONCAT11(uVar4,1);
    }
    if (9 < (((entity_t *)agnt->entity)->base).level) {
      return CONCAT11(uVar4,1);
    }
  }
  if (((((agntG_t far *)agnt->gdata)->flags & 0x800) == 0) ||
     (in_AX = in_stack_00000008 * 0x34,
     (((agntG_t *)((in_AX + 0x1d)))->flags & 4) == 0)) {
    uVar2 = in_AX & 0xff00;
  }
  else {
    uVar2 = CONCAT11((char)(in_AX >> 8),1);
  }
  return uVar2;
}



/* 5ded:04cd */

/* Rolls 1..40 against the owner's stat and returns whether the roll succeeds. */

int __cdecl16far ovc27_rollAgainstStat(agnt_t far *agnt,byte mode,uint16_t arg3,uint16_t arg4)

{
  uint32_t uVar1;
  uint16_t uVar2;
  uint uVar3;
  byte bVar5;
  int iVar4;
  undefined1 uStack0007;
  byte in_stack_00000008;
  byte bStack_4;
  
  agnt = CONCAT13(uStack0007,CONCAT12(mode,agnt));
  bVar5 = *(byte *)((int)&(((entity_t *)agnt->entity)->base).entity + 3);
  if (bVar5 == 0xff) {
    bStack_4 = 6;
  }
  else {
    uVar1 = *(uint32_t *)((uint)bVar5 << 2);
    bStack_4 = *(byte *)((int)uVar1 + (uint)in_stack_00000008 + 0x29);
  }
  uVar2 = ovr_randBelow(0x28,0);
  uVar3 = (uVar2 & 0xff) + 1;
  bVar5 = (byte)(uVar3 >> 8);
  if (bStack_4 < uVar3) {
    iVar4 = (uint)bVar5 << 8;
  }
  else {
    iVar4 = CONCAT11(bVar5,1);
  }
  return iVar4;
}



/* 5ded:052d */

/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc27_usesRandBelow3(agnt_t far *agnt,uint32_t reqRecord,int agntIndex)

{
  byte bVar1;
  uint uVar2;
  byte bVar5;
  uint uVar3;
  uint16_t uVar4;
  int recIdx;
  agnt_t far *paVar7;
  uint16_t uVar8;
  uint16_t uVar9;
  far_t dst;
  far_t dst_00;
  uint8_t reqLevel2;
  uint uStack_10;
  uint16_t uStack_e;
  uint8_t reqLevel1;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)&reqLevel1;
  F_SCOPY(far_from_u32((uint32_t)(0x241059aa)),dst);
  dst_00.seg = _SS;
  dst_00.ofs = (uint16_t)&reqLevel2;
  F_SCOPY(far_from_u32((uint32_t)(0x241059b4)),dst_00);
  uVar2 = agntIndex * 0x34;
  uStack_10 = CONCAT22(SEG_OF(Agnts),uVar2);
  uVar8 = (uint16_t)(reqRecord >> 0x10);
  recIdx = (int)reqRecord;
  paVar7 = (agnt_t far *)agnt;
  uVar9 = (uint16_t)((ulong)agnt >> 0x10);
  if (*(char *)(recIdx + 8) == '\0') {
    if ((((agntG_t far *)paVar7->gdata)->flags & 2) == 0) {
      return uVar2 & 0xff00;
    }
    if ((((entity_t *)paVar7->entity)->base).level < (&reqLevel1)[*(byte *)(recIdx + 9)]) {
      return (uint)(&reqLevel1 + *(byte *)(recIdx + 9)) & 0xff00;
    }
  }
  else {
    bVar5 = (byte)(uVar2 >> 8);
    if (*(char *)(recIdx + 8) == '\x01') {
      if ((((agntG_t far *)paVar7->gdata)->flags & 1) == 0) {
        return (uint)bVar5 << 8;
      }
      if ((((entity_t *)paVar7->entity)->base).level < (&reqLevel2)[*(byte *)(recIdx + 9)]) {
        return (uint)(&reqLevel2 + *(byte *)(recIdx + 9)) & 0xff00;
      }
    }
    else if ((*(char *)(recIdx + 8) == '\x02') && ((((agntG_t far *)paVar7->gdata)->flags & 0x800) == 0))
    {
      return (uint)bVar5 << 8;
    }
  }
  if ((Agnts[agntIndex].gdata->flags & *(uint *)(recIdx + 0x15)) == 0) {
    if ((Agnts[agntIndex].gdata->flags2 & *(uint *)(recIdx + 0x19)) == 0) {
      if ((Agnts[agntIndex].gdata->flags3 & *(uint *)(recIdx + 0x1d)) == 0) {
        if ((*(uint *)(uVar2 + 0x2b) & *(uint *)(recIdx + 0xf)) == 0) {
          uVar3 = (uint)*(byte *)(recIdx + 0x13);
          if ((*(uint *)((int)*(uint32_t *)(uVar2 + 0x17) + 0x14) & uVar3) == 0) {
            if ((*(int *)(recIdx + 0x17) != 0) &&
               (uVar3 = *(uint *)(recIdx + 0x17),
               (Agnts[agntIndex].gdata->flags & uVar3) == 0)) {
              return uVar3 & 0xff00;
            }
            if ((*(int *)(recIdx + 0x1b) != 0) &&
               (uVar3 = *(uint *)(recIdx + 0x1b),
               (Agnts[agntIndex].gdata->flags2 & uVar3) == 0)) {
              return uVar3 & 0xff00;
            }
            if ((*(int *)(recIdx + 0x1f) != 0) &&
               (uVar3 = *(uint *)(recIdx + 0x1f),
               (Agnts[agntIndex].gdata->flags3 & uVar3) == 0)) {
              return uVar3 & 0xff00;
            }
            if ((*(int *)(recIdx + 0x11) != 0) &&
               (uVar3 = *(uint *)(recIdx + 0x11), (*(uint *)(uVar2 + 0x2b) & uVar3) == 0)) {
              return uVar3 & 0xff00;
            }
            if ((*(char *)(recIdx + 0x14) == '\0') ||
               (uVar3 = (uint)*(byte *)(recIdx + 0x14),
               (*(uint *)((int)*(uint32_t *)(uVar2 + 0x17) + 0x14) & uVar3) != 0)) {
              bVar5 = (byte)(uVar3 >> 8);
              if ((*(char *)(recIdx + 0xc) == '\0') || (*(char *)(uVar2 + 0x11) == '\0')) {
                bVar1 = *(byte *)((int)*(uint32_t *)(uVar2 + 0x17) + 0xf);
                uVar4 = CONCAT11(bVar5,bVar1);
                if (bVar1 < *(byte *)(recIdx + 0xe)) {
                  if ((*(byte *)(recIdx + 0xd) < 100) &&
                     (uVar4 = ovr_randBelow(100,0), *(byte *)(recIdx + 0xd) <= (byte)uVar4)) {
                    return uVar4 & 0xff00;
                  }
                  uVar2 = CONCAT11((char)(uVar4 >> 8),1);
                }
                else {
                  uVar2 = (uint)bVar5 << 8;
                }
              }
              else {
                uVar2 = (uint)bVar5 << 8;
              }
            }
            else {
              uVar2 = 0;
            }
          }
          else {
            uVar2 = 0;
          }
        }
        else {
          uVar2 = *(uint *)(recIdx + 0xf) & 0xff00;
        }
      }
      else {
        uVar2 = *(uint *)(recIdx + 0x1d) & 0xff00;
      }
    }
    else {
      uVar2 = *(uint *)(recIdx + 0x19) & 0xff00;
    }
  }
  else {
    uVar2 = *(uint *)(recIdx + 0x15) & 0xff00;
  }
  return uVar2;
}



/* 5ded:079d */

/* [R4] calls ovr_randBelow */

int __cdecl16far ovc27_usesRandBelow4(byte level,byte threshold)

{
  uint16_t in_AX;
  byte bVar3;
  int iVar1;
  uint16_t uVar2;
  
  bVar3 = (byte)((uint)in_AX >> 8);
  if (level < threshold) {
    iVar1 = (uint)bVar3 << 8;
  }
  else if (level == threshold) {
    uVar2 = ovr_randBelow(8,0);
    if ((uVar2 & 0xff) == 0) {
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
  uint32_t uVar1;
  uint in_AX;
  uint uVar2;
  uint16_t uVar3;
  int in_stack_00000008;
  byte mode;
  byte bStack_3;
  
  mode = (byte)param;
  if ((((agntG_t far *)agnt->gdata)->flags & 2) == 0) {
    if ((((agntG_t far *)agnt->gdata)->flags & 1) == 0) {
      if (((((((agntG_t far *)agnt->gdata)->flags & 0x800) != 0) &&
           (in_AX = ovc27_rollAgainstStat(agnt,mode,5,0), (char)in_AX != '\0')) &&
          (in_AX = in_stack_00000008 * 0x34, (*(uint *)(in_AX + 0x2b) & 0x7e0) == 0)) &&
         ((in_AX = in_stack_00000008 * 0x34,
          (((agntG_t *)((in_AX + 0x1d)))->flags3 & 0x80) == 0 &&
          (in_AX = in_stack_00000008 * 0x34,
          (((agntG_t *)((in_AX + 0x1d)))->flags & 4) != 0)))) {
        return CONCAT11((char)(in_AX >> 8),1);
      }
      uVar2 = in_AX & 0xff00;
    }
    else {
      uVar3 = ovc27_usesRandBelow3((agnt_t far *)CONCAT22(param,agnt),0x222b0108,in_stack_00000008);
      if ((char)uVar3 == '\0') {
        uVar2 = ovc27_usesRandBelow3((agnt_t far *)CONCAT22(param,agnt),0x222b014a,in_stack_00000008);
        if ((char)uVar2 == '\0') {
          return uVar2 & 0xff00;
        }
        bStack_3 = 10;
      }
      else {
        bStack_3 = 4;
      }
      uVar2 = ovc27_usesRandBelow4((((entity_t *)agnt->entity)->base).level,bStack_3);
      if ((uVar2 & 0xff) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = ovc27_rollAgainstStat(agnt,mode,2,0);
        if ((uVar2 & 0xff) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
    }
  }
  else {
    uVar2 = ovc27_usesRandBelow4((((entity_t *)agnt->entity)->base).level,1);
    if ((uVar2 & 0xff) == 0) {
      uVar2 = 0;
    }
    else {
      uVar1 = *(uint32_t far *)&Agnts[in_stack_00000008].gdata;
      if (((*(uint *)((int)uVar1 + 0x3e) & 0x10) == 0) ||
         (2 < (((entity_t *)agnt->entity)->base).level)) {
        uVar2 = ovc27_rollAgainstStat(agnt,mode,1,0);
        if ((uVar2 & 0xff) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
      else {
        uVar2 = in_stack_00000008 * 0x34 & 0xff00;
      }
    }
  }
  return uVar2;
}



/* 5ded:0960 */

/* WARNING: Variable defined which should be unmapped: indexMap */
/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc27_usesRandBelow5(agnt_t far *agnt)

{
  uint in_AX;
  uint uVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  uint8_t indexMap;
  byte bStack_4;
  byte bStack_3;
  
  uVar4 = (uint16_t)((ulong)agnt >> 0x10);
  if (((agnt_t far *)agnt)->target == 0xff) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    _fmemset(MK_FP(_SS, &indexMap), 0, 0xf);
    bStack_3 = 0;
    for (bStack_4 = 0; bStack_4 < 0xf; bStack_4 = bStack_4 + 1) {
      uVar2 = ovc27_usesRandBelow3
                        (agnt,CONCAT22(0x222b,(uint)bStack_4 * 0x21),(uint)((agnt_t far *)agnt)->target)
      ;
      if ((char)uVar2 != '\0') {
        (&indexMap)[bStack_3] = bStack_4 + 1;
        bStack_3 = bStack_3 + 1;
      }
    }
    if (bStack_3 == 0) {
      uVar1 = 0;
    }
    else {
      uVar3 = ovr_randBelow((uint)bStack_3,0);
      uVar1 = CONCAT11((char)((uint)(&indexMap + (uVar3 & 0xff)) >> 8),(&indexMap)[uVar3 & 0xff]);
    }
  }
  return uVar1;
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
  int iVar8;
  agntG_t far *paVar9;
  int *piVar10;
  uint16_t uVar11;
  uint16_t uVar12;
  long lVar13;
  uint8_t text;
  byte variant;
  int iStack_12;
  uint16_t uStack_10;
  int iStack_e;
  int iStack_c;
  int targetOfs;
  uint16_t uStack_8;
  agnt_t far *paStack_6;
  uint16_t agntSeg;
  
  paStack_6 = (agnt_t far *)&Agnts[agntIndex].x;
  agntSeg = SEG_OF(Agnts);
  bVar1 = (byte)((uint)paStack_6 >> 8);
  if ((((agntG_t far *)paStack_6->gdata)->flags & 0x803) == 0) {
    return (uint)bVar1 << 8;
  }
  if (paStack_6->animFrame == 0xff) {
    targetOfs = (uint)paStack_6->target * 0x34;
    uStack_8 = SEG_OF(Agnts);
    uVar11 = uStack_8;
    uStack_8 = SEG_OF(Agnts);
    uVar12 = uVar11;
    if (((((((agntG_t far *)paStack_6->gdata)->flags & 0x1000) != 0) &&
         (uVar12 = uStack_8, (Agnts[paStack_6->target].gdata->flags2 & 0x10) == 0))
        && ((uStack_8 = uVar11, (Agnts[paStack_6->target].gdata->flags2 & 8) == 0
            || (bVar1 = ovr_agnt_compute9(paStack_6,0), uVar12 = uStack_8, '\0' < (char)bVar1)))) &&
       (uVar2 = ovr_randBelow(2,0), uVar12 = uStack_8, (uVar2 & 0xff) == 0)) {
      return 0;
    }
    uStack_8 = uVar12;
    uVar3 = ovc27_usesRandBelow5((agnt_t far *)CONCAT22(agntSeg,paStack_6));
    variant = (byte)uVar3;
    uVar4 = uVar3 & 0xff;
    if (uVar4 == 0) {
      ovr_agnt_usesAnimFrame(paStack_6);
      uVar4 = uVar4 & 0xff00;
    }
    else {
      uVar11 = (uint16_t)((ulong)*(uint32_t *)(targetOfs + 0x1d) >> 0x10);
      iVar8 = (int)*(uint32_t *)(targetOfs + 0x1d);
      iVar5 = (uVar3 & 0xff) * 0x21;
      iVar6 = (uVar3 & 0xff) * 0x21;
      uVar2 = 0x222b;
      uVar12 = (uint16_t)((ulong)paStack_6->gdata >> 0x10);
      paVar9 = (agntG_t far *)paStack_6->gdata;
                    /* WARNING: Load size is inaccurate */
      puVar7 = ovr_ovc15_usesStshRealloc
                         (paVar9->name,*(uint16_t *)((int)&paVar9->name + 2),
                          *(uint16_t *)(iVar6 + -0x21),*(uint16_t *)(iVar6 + -0x1f),
                          *(uint16_t *)(iVar5 + -0x1d),*(uint16_t *)(iVar5 + -0x1b),
                          *(uint16_t *)(iVar8 + 0x24),*(uint16_t *)(iVar8 + 0x26));
      msg = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x5ba4,_SS),
                          (char *)CONCAT22(puVar7,(char *)0x26510),uVar2);
      ovr_uiNotify(msg,uVar2,0);
      paStack_6->variant = variant;
      if (*(char *)((uint)variant * 0x21 + -0x17) == '9') {
        uVar3 = ovr_audio_panFromX(paStack_6,0);
        lVar13 = (ulong)uVar3 << 0x10;
        uVar2 = ovr_randBelow(2,0);
        ovr_play_sfxU((char)uVar2 + 0x39,(int)lVar13,(uint16_t)((ulong)lVar13 >> 0x10),0,0);
      }
      else {
        uVar2 = ovr_audio_panFromX(paStack_6,0);
        ovr_play_sfxU(*(byte *)((uint)variant * 0x21 + -0x17),0,uVar2,0,0);
      }
      if (*(char *)((uint)variant * 0x21 + -0x16) == '\0') {
        paStack_6->animFrame = 0xf5;
        uVar4 = 1;
      }
      else {
        uVar11 = *(uint16_t *)((int)&paStack_6->frames + 2);
        iStack_12 = CONCAT22(uVar11,*(int *)&paStack_6->frames);
        piVar10 = (int *)(*(int *)&paStack_6->frames + (uint)paStack_6->frameIndex * 4);
        iVar5 = piVar10[1];
        iVar6 = *piVar10;
        iStack_e = CONCAT22(iVar5,iVar6);
        if (iVar6 == 0 && iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x42);
        }
        paStack_6->animFrame = 0x0;
        *(char *)&paStack_6->destY = *(char *)(iVar6 + 0x15) + (char)paStack_6->screenY;
        if (paStack_6->level == 0x0) {
          uVar2 = *(int *)(iVar6 + 0x13) + paStack_6->screenX;
          paStack_6->destX = uVar2;
        }
        else {
          uVar2 = paStack_6->screenX - *(int *)(iVar6 + 0x13);
          paStack_6->destX = uVar2;
        }
        *(uint8_t *)((int)&paStack_6->destY + 1) = paStack_6->level;
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
  int targetOfs;
  uint xPos;
  int framesOfs;
  int aimX;
  stg_tmp_t *stash;
  uint16_t spriteSeg;
  uint16_t *spritePtr;
  far_t gfx;
  far_t gfx_00;
  int stateOfs;
  uint16_t stateSeg;
  
  agnt = (agnt_t far *)&Agnts[agntIndex].x;
  targetOfs = (uint)agnt->target * 0x34;
  if (((agnt->combatState == 0x0) && (agnt->target != 0xff)) && (agnt->animFrame != 0xff)) {
    framesSeg = *(uint16_t *)((int)&agnt->frames + 2);
    framesOfs = *(int *)&agnt->frames;
    if (agnt->animVariant == 0x0) {
      stateSeg = *(uint16_t *)(framesOfs + 0xe);
      stateOfs = *(int *)(framesOfs + 0xc);
    }
    else {
      stateSeg = *(uint16_t *)(framesOfs + 0x12);
      stateOfs = *(int *)(framesOfs + 0x10);
    }
    if (agnt->level == 0x0) {
      xPos = agnt->screenX + *(int *)(stateOfs + 0x13);
      if (*(uint *)(targetOfs + 0x26) <= xPos) {
        agnt->animFrame = 0xff;
        agnt->variant = 0x0;
        return;
      }
    }
    else {
      xPos = agnt->screenX - *(int *)(stateOfs + 0x13);
      if (xPos <= *(uint *)(targetOfs + 0x26)) {
        agnt->animFrame = 0xff;
        agnt->variant = 0x0;
        return;
      }
    }
    spritePtr = (uint16_t *)(*(int *)(targetOfs + 0x13) + (uint)*(byte *)(targetOfs + 0x12) * 4);
    spriteLo = spritePtr[1];
    spriteSeg = *spritePtr;
    if ((*(int *)(targetOfs + 0x28) != 0) || (*(int *)(targetOfs + 0x26) != 0)) {
      if (agnt->variant == 0x1) {
        if (agnt->animFrame < 0xfc) {
          ovc27_intelAttackingNotice
                    (xPos,*(int *)(stateOfs + 0x15) + agnt->screenY,*(int *)(targetOfs + 0x26),
                     *(int *)(targetOfs + 0x28) - (*(int *)(spriteSeg + 0xd) >> 1),
                     (int *)CONCAT22(type,rect));
        }
        xPos = agnt->animFrame & 3;
        gfx.seg = ((uint16_t *)&boltSpritesSeg)[xPos * 2];
        gfx.ofs = ((uint16_t *)&boltSpritesOfs)[xPos * 2];
        ovr_blitGfxRect(gfx,*(int16_t *)(targetOfs + 0x26),*(int *)(targetOfs + 0x28) - (*(int *)(spriteSeg + 0xd) >> 1),rect,(uint8_t)type,true,0,0,0,0,0,0);
      }
      else {
        if (xPos < *(uint *)(targetOfs + 0x26)) {
          *(undefined1 *)&agnt->flags32 = 0;
          aimX = *(int *)(targetOfs + 0x26) + -8;
        }
        else {
          *(undefined1 *)&agnt->flags32 = 1;
          aimX = *(int *)(targetOfs + 0x26) + 8;
        }
        if (agnt->animFrame < 0xfb) {
          ovc27_usesRandBelow(xPos,*(int *)(stateOfs + 0x15) + agnt->screenY,aimX,
                              *(int *)(targetOfs + 0x28) + -6,(brect_t *)CONCAT22(type,rect),
                              agnt->animFrame << 1);
        }
        if (0xf8 < agnt->animFrame) {
          stash = ovr_stash_usesStExit((stg_tmp_t *)*(uint16_t far *)((uint8_t far *)MK_FP(SprProjectiles.seg, SprProjectiles.ofs) +  0x8c),0,0);
          gfx_00.seg = spriteSeg;
          gfx_00.ofs = (uint16_t)(stash->cmap + 6);
          ovr_blitGfxRect(gfx_00,*(int16_t *)(targetOfs + 0x26),*(int16_t *)(targetOfs + 0x28),rect,(uint8_t)type,true,CONCAT11((char)((uint)stash >> 8),(char)agnt->flags32),0,0,0,0,0);
        }
      }
      agnt->animFrame = agnt->animFrame + 0x1;
      agnt->health = 0x2;
      if (agnt->animFrame == 0xff) {
        ovr_ovc41_resolveSpecialAttack((agnt_t far *)CONCAT22(SEG_OF(Agnts),agnt),(uint)agnt->target);
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
  uint8_t *puVar1;
  uint uVar2;
  uint16_t in_DX;
  agnt_t far *agnt_00;
  char *pcVar3;
  uint16_t uVar4;
  uint8_t text;
  uint8_t msg;
  
  pcVar3 = (char *)((ulong)agnt >> 0x10);
  agnt_00 = (agnt_t far *)agnt;
  if (((((agntG_t far *)agnt_00->gdata)->shortName[3] == '\x04') &&
      (0xf < (((entity_t *)agnt_00->entity)->base).level)) ||
     ((((agntG_t far *)agnt_00->gdata)->shortName[3] == '\x06' &&
      (8 < (((entity_t *)agnt_00->entity)->base).level)))) {
    uVar4 = GSavedBlitSeg;
    pcVar3 = ovr_agnt_statusText(agnt_00,(char *)CONCAT22(&text,pcVar3),0);
    puVar1 = ovr_ovc15_usesStshRealloc(pcVar3,in_DX,uVar4,0,0,0,0,0);
    pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x5bbf,_SS),
                           (char *)CONCAT22(puVar1,(char *)0x26510),in_DX);
    ovr_uiNotify(pcVar3,in_DX,0);
    uVar2 = CONCAT11((char)((uint)pcVar3 >> 8),1);
  }
  else {
    uVar2 = in_AX & 0xff00;
  }
  return uVar2;
}



/* 5ded:105e */

/* Notifies "%s takes half damage from dragon breath." for the qualifying types. */

uint __cdecl16far ovc27_breathHalfDamage(agnt_t far *agnt,uint16_t arg2)

{
  uint in_AX;
  char *pcVar1;
  uint8_t *puVar2;
  uint uVar3;
  uint16_t in_DX;
  char *in_stack_00000006;
  uint16_t uVar4;
  uint8_t text;
  uint8_t msg;
  
  if (((((agntG_t far *)agnt->gdata)->shortName[3] == '\x05') &&
      (0xd < (((entity_t *)agnt->entity)->base).level)) ||
     ((((agntG_t far *)agnt->gdata)->shortName[3] == '\x06' &&
      (0xe < (((entity_t *)agnt->entity)->base).level)))) {
    uVar4 = GSavedBlitSeg;
    pcVar1 = ovr_agnt_statusText(agnt,(char *)CONCAT22(&text,in_stack_00000006),0);
    puVar2 = ovr_ovc15_usesStshRealloc(pcVar1,in_DX,uVar4,0,0,0,0,0);
    pcVar1 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x5be1,_SS),
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
  uint uVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  int iVar5;
  char *pcVar6;
  uint8_t *bufPtr;
  uint16_t uVar8;
  int in_stack_00000008;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  uint8_t text1;
  uint8_t text2;
  uint8_t msg;
  agnt_t far *paStack_c;
  char *ptrSeg;
  int levelBonus;
  
  uVar8 = (uint16_t)((ulong)((long)in_stack_00000008 * 0x34) >> 0x10);
  paStack_c = (agnt_t far *)(agnt_t far *)((long)in_stack_00000008 * 0x34);
  ptrSeg = (char *)((int)&AgntAnms[0x75].halfWidth + 1);
  if (agnt->variant == 0x1) {
    if ((((agntG_t far *)agnt->gdata)->flags3 & 1) == 0) {
      roll = ovr_manage_rollDice((((entity_t *)agnt->entity)->base).level,'\x06');
      uVar2 = (uint)roll;
      uVar3 = ovc27_spellHalfDamage
                        ((agnt_t far *)
                         CONCAT13((char)((uint)ptrSeg >> 8),CONCAT12((char)ptrSeg,paStack_c)))
      ;
      if ((char)uVar3 != '\0') {
        uVar2 = (int)uVar2 >> 1;
      }
    }
    else {
      uVar2 = (uint)agnt->strength;
      uVar3 = ovc27_breathHalfDamage(paStack_c,0x26);
      if ((char)uVar3 != '\0') {
        uVar2 = (int)uVar2 >> 1;
      }
    }
    if ((((agntG_t far *)paStack_c->gdata)->flags3 & 1) == 0) {
      iVar5 = ovc27_rollToHitEntity
                        (CONCAT13((char)((uint)ptrSeg >> 8),CONCAT12((char)ptrSeg,paStack_c)),
                         3);
      if ((char)iVar5 != '\0') {
        uVar2 = (int)uVar2 >> 1;
      }
      ovr_ovc41_textParalyzed
                ((agnt_t far *)CONCAT22(agntIndex,agnt),
                 (agnt_t far *)
                 CONCAT13((char)((uint)ptrSeg >> 8),CONCAT12((char)ptrSeg,paStack_c)),uVar2,
                 (char)paStack_c,(char)ptrSeg,(char)uVar2);
      *(undefined1 *)&paStack_c->state = 0xb;
      *(undefined1 *)((int)&paStack_c->state + 1) = 0;
      emptyFunction();
      return;
    }
    uVar9 = (undefined1)GSavedBlitSeg;
    pcVar6 = ovr_agnt_statusText(paStack_c,(char *)CONCAT13((char)((uint)&text2 >> 8),
                                                  CONCAT12((char)&text2,ptrSeg)),0);
    bufPtr = ovr_ovc15_usesStshRealloc(pcVar6,(char)uVar8,uVar9,0,0,0,0,0);
    pcVar6 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x5c0a,_SS),
                           (char *)CONCAT13((char)((uint)bufPtr >> 8),CONCAT12((char)bufPtr,0x2410))
                           ,(char)bufPtr,(char)uVar8);
    ovr_uiNotify(pcVar6,uVar8,(char)uVar8);
    emptyFunction();
    return;
  }
  if (agnt->variant == 0x2) {
    levelBonus = ((((entity_t *)agnt->entity)->base).level / 5) * 2 + 1;
    roll = ovr_manage_rollDice((char)levelBonus,'\x06');
    uVar2 = (uint)roll + levelBonus;
    uVar3 = ovc27_spellHalfDamage
                      ((agnt_t far *)
                       CONCAT13((char)((uint)ptrSeg >> 8),CONCAT12((char)ptrSeg,paStack_c)));
    if ((char)uVar3 != '\0') {
      uVar2 = (int)uVar2 >> 1;
    }
    ovr_ovc41_textParalyzed
              ((agnt_t far *)CONCAT22(agntIndex,agnt),
               (agnt_t far *)CONCAT13((char)((uint)ptrSeg >> 8),CONCAT12((char)ptrSeg,paStack_c)),
               uVar2,(char)paStack_c,(char)ptrSeg,(char)uVar2);
    *(undefined1 *)&paStack_c->state = 0xb;
    *(undefined1 *)((int)&paStack_c->state + 1) = 0;
    emptyFunction();
    return;
  }
  if (agnt->variant == 0xa) {
    if ((paStack_c->flags & 0x420) != 0) {
      emptyFunction();
      return;
    }
    uVar4 = ovr_randBelow(3,0);
    if (((uVar4 & 0xff) == 0) &&
       (uVar2 = ovc27_rollToHitEntity
                          (CONCAT13((char)((uint)ptrSeg >> 8),CONCAT12((char)ptrSeg,paStack_c)
                                   ),3), (uVar2 & 0xff) == 0)) {
      uVar11 = (undefined1)GSavedBlitSeg;
      pcVar6 = ovr_agnt_statusText(agnt,(char *)CONCAT13((char)((uint)&text1 >> 8),
                                                         CONCAT12((char)&text1,agntIndex)),0);
      uVar10 = (undefined1)uVar8;
      uVar9 = SUB21(pcVar6,0);
      pcVar6 = ovr_agnt_statusText(paStack_c,(char *)CONCAT22(&text2,ptrSeg),0);
      bufPtr = ovr_ovc15_usesStshRealloc(pcVar6,uVar8,uVar9,uVar10,uVar11,0,0,0);
      pcVar6 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x5c2f,_SS),
                             (char *)CONCAT22(bufPtr,(char *)0x26510),uVar8);
      ovr_uiNotify(pcVar6,uVar8,(char)uVar8);
      ovr_OVC41_6a8f_01e7_entry(paStack_c,(char)ptrSeg);
      paStack_c->faction = agnt->faction;
      paStack_c->flags = paStack_c->flags | 0x20;
      uVar8 = ovr_audio_panFromX(paStack_c,(char)ptrSeg);
      ovr_play_sfxU(0x1b,0,uVar8,0,(char)uVar8);
      emptyFunction();
      return;
    }
    uVar11 = (undefined1)GSavedBlitSeg;
    pcVar6 = ovr_agnt_statusText(paStack_c,(char *)CONCAT13((char)((uint)&text1 >> 8),
                                                  CONCAT12((char)&text1,ptrSeg)),0);
    uVar10 = (undefined1)uVar8;
    uVar9 = SUB21(pcVar6,0);
    pcVar6 = ovr_agnt_statusText(agnt,(char *)CONCAT22(&text2,agntIndex),0);
    bufPtr = ovr_ovc15_usesStshRealloc(pcVar6,uVar8,uVar9,uVar10,uVar11,0,0,0);
    pcVar6 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x5c44,_SS),
                           (char *)CONCAT22(bufPtr,(char *)0x26510),uVar8);
    ovr_uiNotify(pcVar6,uVar8,(char)uVar8);
    paStack_c->flags = paStack_c->flags | 0x400;
    emptyFunction();
    return;
  }
  if ((agnt->variant != 0x3) && (agnt->variant != 0x5)) {
    ovc27_textTakesHalfDamage4();
    return;
  }
  if ((paStack_c->flags & 0x20) != 0) {
    emptyFunction();
    return;
  }
  iVar5 = ovc27_rollToHitEntity((uint32_t)MK_FP(SEG_OF(Agnts), paStack_c),3);
  if ((char)iVar5 == '\0') {
    uVar11 = (undefined1)GSavedBlitSeg;
    pcVar6 = ovr_agnt_statusText(agnt,(char *)CONCAT13((char)((uint)&text1 >> 8),
                                                       CONCAT12((char)&text1,agntIndex)),0);
    uVar10 = (undefined1)uVar8;
    uVar9 = SUB21(pcVar6,0);
    pcVar6 = ovr_agnt_statusText(paStack_c,(char *)CONCAT22(&text2,ptrSeg),0);
    bufPtr = ovr_ovc15_usesStshRealloc(pcVar6,uVar8,uVar9,uVar10,uVar11,0,0,0);
    pcVar6 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x5c2f,_SS),
                           (char *)CONCAT22(bufPtr,(char *)0x26510),uVar8);
    ovr_uiNotify(pcVar6,uVar8,(char)uVar8);
    paStack_c->faction = agnt->faction;
    ovr_OVC41_6a8f_01e7_entry(paStack_c,(char)ptrSeg);
    paStack_c->flags = paStack_c->flags | 0x20;
    uVar8 = ovr_audio_panFromX(paStack_c,(char)ptrSeg);
    ovr_play_sfxU(0x1b,0,uVar8,0,(char)uVar8);
    emptyFunction();
    return;
  }
  emptyFunction();
  return;
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
  emptyFunction();
  return;
}



/* 5ded:14a8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* [R2] string "%s takes half damage from fire." */

void ovc27_textTakesHalfDamage4(void)

{
  uint *puVar1;
  uint32_t uVar2;
  byte bVar3;
  uint16_t uVar4;
  int iVar5;
  uint16_t pan;
  uint uVar7;
  char *pcVar8;
  uint8_t *bufPtr;
  uint16_t in_DX;
  int unaff_BP;
  int unaff_DI;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 savedSeg;
  
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\x04') {
    pan = ovr_audio_panFromX((agnt_t far *)*(uint16_t *)(unaff_BP + -10),
                               (char)*(uint16_t *)(unaff_BP + -8));
    ovr_play_sfxU(0x4c,0,pan,0,(char)pan);
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
        uVar10 = (undefined1)GSavedBlitSeg;
        pcVar8 = ovr_agnt_statusText((agnt_t far *)*(uint16_t *)(unaff_BP + -10),
                                     (char *)CONCAT13((char)((uint)(unaff_BP + -0xd2) >> 8),
                                                      CONCAT12((char)(unaff_BP + -0xd2),
                                                               *(uint16_t *)(unaff_BP + -8))),
                                     (char)*(uint16_t *)(unaff_BP + -8));
        bufPtr = ovr_ovc15_usesStshRealloc(pcVar8,(char)in_DX,uVar10,0,0,0,0,0);
        pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),(char *)CONCAT22(0x5c70,_SS),
                               (char *)CONCAT13((char)((uint)bufPtr >> 8),
                                                CONCAT12((char)bufPtr,0x2410)),0x10,(char)bufPtr,
                               (char)in_DX);
        ovr_uiNotify(pcVar8,in_DX,(char)in_DX);
        uVar7 = (int)uVar7 >> 1;
      }
      uVar10 = (undefined1)*(uint16_t *)(unaff_BP + -8);
      ovr_ovc41_textParalyzed
                ((agnt_t far *)
                 CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + 8) >> 8),
                          CONCAT12((char)*(uint16_t *)(unaff_BP + 8),*(uint16_t *)(unaff_BP + 6)
                                  )),
                 (agnt_t far *)
                 CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                          CONCAT12(uVar10,*(uint16_t *)(unaff_BP + -10))),uVar7,
                 (char)*(uint16_t *)(unaff_BP + -10),uVar10,(char)uVar7);
      ((char_sheet_t *)((unaff_BP + -10)))->race = 10;
      ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
      emptyFunction();
      return;
    }
    uVar10 = (undefined1)GSavedBlitSeg;
    pcVar8 = ovr_agnt_statusText((agnt_t far *)*(uint16_t *)(unaff_BP + -10),
                                 (char *)CONCAT13((char)((uint)(unaff_BP + -0xd2) >> 8),
                                                  CONCAT12((char)(unaff_BP + -0xd2),
                                                           *(uint16_t *)(unaff_BP + -8))),
                                 (char)*(uint16_t *)(unaff_BP + -8));
    bufPtr = ovr_ovc15_usesStshRealloc(pcVar8,(char)in_DX,uVar10,0,0,0,0,0);
    pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),(char *)CONCAT22(0x5c5a,_SS),
                           (char *)CONCAT13((char)((uint)bufPtr >> 8),CONCAT12((char)bufPtr,0x2410))
                           ,0x10,(char)bufPtr,(char)in_DX);
    ovr_uiNotify(pcVar8,in_DX,(char)in_DX);
    emptyFunction();
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\x06') {
    if (*(char *)((int)*(uint32_t *)(unaff_BP + -10) + 0x11) != '\0') {
      emptyFunction();
      return;
    }
    if ((((agnt_t far *)((unaff_BP + -10)))->flags & 0x40) == 0) {
      iVar5 = ovc27_rollToHitEntity
                        (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                  CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                           *(uint16_t *)(unaff_BP + -10))),3);
      if ((char)iVar5 == '\0') {
        savedSeg = (undefined1)GSavedBlitSeg;
        pcVar8 = ovr_agnt_statusText((agnt_t far *)*(uint16_t *)(unaff_BP + 6),
                                     (char *)CONCAT13((char)((uint)(unaff_BP + -0x122) >> 8),
                                                      CONCAT12((char)(unaff_BP + -0x122),
                                                               *(uint16_t *)(unaff_BP + 8))),
                                     (char)*(uint16_t *)(unaff_BP + 8));
        uVar11 = (undefined1)in_DX;
        uVar10 = SUB21(pcVar8,0);
        pcVar8 = ovr_agnt_statusText((agnt_t far *)*(uint16_t *)(unaff_BP + -10),(char *)CONCAT22(unaff_BP + -0xd2,
                                                      (char *)*(uint16_t *)(unaff_BP + -8)),0);
        bufPtr = ovr_ovc15_usesStshRealloc(pcVar8,(char)in_DX,uVar10,uVar11,savedSeg,0,0,0);
        pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),(char *)CONCAT22(0x5c90,_SS),
                               (char *)CONCAT22(bufPtr,(char *)0x26510),(char)in_DX);
        ovr_uiNotify(pcVar8,in_DX,(char)in_DX);
        ovr_OVC41_6a8f_01e7_entry
                  ((agnt_t far *)*(uint16_t *)(unaff_BP + -10),(char)*(uint16_t *)(unaff_BP + -8));
        puVar1 = (uint *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2b);
        *puVar1 = *puVar1 | 0x40;
        ((char_sheet_t *)((unaff_BP + -10)))->race = 0x10;
        ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
        pan = ovr_audio_panFromX((agnt_t far *)*(uint16_t *)(unaff_BP + -10),
                                   (char)*(uint16_t *)(unaff_BP + -8));
        ovr_play_sfxU(0x1b,0,pan,0,(char)pan);
        emptyFunction();
        return;
      }
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  uVar10 = (undefined1)GSavedBlitSeg;
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\a') {
    if (*(char *)((int)*(uint32_t *)(unaff_BP + -10) + 0x11) != '\0') {
      emptyFunction();
      return;
    }
    if ((((agnt_t far *)((unaff_BP + -10)))->flags & 0x80) == 0) {
      uVar2 = ((agnt_t far *)((unaff_BP + -10)))->entity;
      if (*(byte *)((int)uVar2 + 0xf) < 5) {
        pcVar8 = ovr_agnt_statusText((agnt_t far *)*(uint16_t *)(unaff_BP + 6),
                                     (char *)CONCAT13((char)((uint)(unaff_BP + -0x122) >> 8),
                                                      CONCAT12((char)(unaff_BP + -0x122),
                                                               *(uint16_t *)(unaff_BP + 8))),
                                     (char)*(uint16_t *)(unaff_BP + 8));
        savedSeg = (undefined1)in_DX;
        uVar11 = SUB21(pcVar8,0);
        pcVar8 = ovr_agnt_statusText((agnt_t far *)*(uint16_t *)(unaff_BP + -10),(char *)CONCAT22(unaff_BP + -0xd2,
                                                      (char *)*(uint16_t *)(unaff_BP + -8)),0);
        bufPtr = ovr_ovc15_usesStshRealloc(pcVar8,(char)in_DX,uVar11,savedSeg,uVar10,0,0,0);
        pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),(char *)CONCAT22(0x5ca2,_SS),
                               (char *)CONCAT22(bufPtr,(char *)0x26510),(char)in_DX);
        ovr_uiNotify(pcVar8,in_DX,(char)in_DX);
        ovr_OVC41_6a8f_01e7_entry
                  ((agnt_t far *)*(uint16_t *)(unaff_BP + -10),(char)*(uint16_t *)(unaff_BP + -8));
        puVar1 = (uint *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2b);
        *puVar1 = *puVar1 | 0x80;
        pan = ovr_audio_panFromX((agnt_t far *)*(uint16_t *)(unaff_BP + -10),
                                   (char)*(uint16_t *)(unaff_BP + -8));
        ovr_play_sfxU(0x1b,0,pan,0,(char)pan);
        ((char_sheet_t *)((unaff_BP + -10)))->race = 0xc;
        ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
        emptyFunction();
        return;
      }
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\b') {
    if (*(char *)((int)*(uint32_t *)(unaff_BP + -10) + 0x11) != '\0') {
      emptyFunction();
      return;
    }
    if ((((agnt_t far *)((unaff_BP + -10)))->flags & 0x100) == 0) {
      pcVar8 = ovr_agnt_statusText((agnt_t far *)*(uint16_t *)(unaff_BP + 6),
                                   (char *)CONCAT13((char)((uint)(unaff_BP + -0x122) >> 8),
                                                    CONCAT12((char)(unaff_BP + -0x122),
                                                             *(uint16_t *)(unaff_BP + 8))),
                                   (char)*(uint16_t *)(unaff_BP + 8));
      savedSeg = (undefined1)in_DX;
      uVar11 = SUB21(pcVar8,0);
      pcVar8 = ovr_agnt_statusText((agnt_t far *)*(uint16_t *)(unaff_BP + -10),(char *)CONCAT22(unaff_BP + -0xd2,
                                                    (char *)*(uint16_t *)(unaff_BP + -8)),0);
      bufPtr = ovr_ovc15_usesStshRealloc(pcVar8,(char)in_DX,uVar11,savedSeg,uVar10,0,0,0);
      pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),(char *)CONCAT22(0x5cbc,_SS),
                             (char *)CONCAT22(bufPtr,(char *)0x26510),(char)in_DX);
      ovr_uiNotify(pcVar8,in_DX,(char)in_DX);
      ((char_sheet_t *)((unaff_BP + -10)))->alignment =
           *(undefined1 *)((int)*(uint32_t *)(unaff_BP + 6) + 0x32);
      ((char_sheet_t *)((unaff_BP + -10)))->race = 0xd;
      ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 5;
      puVar1 = (uint *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x100;
      pan = ovr_audio_panFromX((agnt_t far *)*(uint16_t *)(unaff_BP + -10),
                                 (char)*(uint16_t *)(unaff_BP + -8));
      ovr_play_sfxU(0x1b,0,pan,0,(char)pan);
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\t') {
    if ((((agnt_t far *)((unaff_BP + -10)))->flags & 0x40) != 0) {
      emptyFunction();
      return;
    }
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                         *(uint16_t *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
      savedSeg = (undefined1)GSavedBlitSeg;
      pcVar8 = ovr_agnt_statusText((agnt_t far *)*(uint16_t *)(unaff_BP + 6),
                                   (char *)CONCAT13((char)((uint)(unaff_BP + -0x122) >> 8),
                                                    CONCAT12((char)(unaff_BP + -0x122),
                                                             *(uint16_t *)(unaff_BP + 8))),
                                   (char)*(uint16_t *)(unaff_BP + 8));
      uVar11 = (undefined1)in_DX;
      uVar10 = SUB21(pcVar8,0);
      pcVar8 = ovr_agnt_statusText((agnt_t far *)*(uint16_t *)(unaff_BP + -10),(char *)CONCAT22(unaff_BP + -0xd2,
                                                    (char *)*(uint16_t *)(unaff_BP + -8)),0);
      bufPtr = ovr_ovc15_usesStshRealloc(pcVar8,(char)in_DX,uVar10,uVar11,savedSeg,0,0,0);
      pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),(char *)CONCAT22(0x5c90,_SS),
                             (char *)CONCAT22(bufPtr,(char *)0x26510),(char)in_DX);
      ovr_uiNotify(pcVar8,in_DX,(char)in_DX);
      ovr_OVC41_6a8f_01e7_entry
                ((agnt_t far *)*(uint16_t *)(unaff_BP + -10),(char)*(uint16_t *)(unaff_BP + -8));
      puVar1 = (uint *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x40;
      ((char_sheet_t *)((unaff_BP + -10)))->race = 0x10;
      ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
      pan = ovr_audio_panFromX((agnt_t far *)*(uint16_t *)(unaff_BP + -10),
                                 (char)*(uint16_t *)(unaff_BP + -8));
      ovr_play_sfxU(0x1b,0,pan,0,(char)pan);
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\v') {
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                         *(uint16_t *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
      bVar3 = ((agnt_t far *)((unaff_BP + -10)))->strength;
      uVar10 = (undefined1)*(uint16_t *)(unaff_BP + -8);
      ovr_ovc41_textParalyzed
                ((agnt_t far *)
                 CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + 8) >> 8),
                          CONCAT12((char)*(uint16_t *)(unaff_BP + 8),*(uint16_t *)(unaff_BP + 6)
                                  )),
                 (agnt_t far *)
                 CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                          CONCAT12(uVar10,*(uint16_t *)(unaff_BP + -10))),(uint)bVar3,
                 (char)*(uint16_t *)(unaff_BP + -10),uVar10,bVar3);
      ((char_sheet_t *)((unaff_BP + -10)))->race = 0xb;
      ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\f') {
    uVar2 = ((agnt_t far *)((unaff_BP + -10)))->entity;
    if (7 < *(byte *)((int)uVar2 + 0xf)) {
      emptyFunction();
      return;
    }
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                         *(uint16_t *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
      bVar3 = ((agnt_t far *)((unaff_BP + -10)))->strength;
      uVar10 = (undefined1)*(uint16_t *)(unaff_BP + -8);
      ovr_ovc41_textParalyzed
                ((agnt_t far *)
                 CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + 8) >> 8),
                          CONCAT12((char)*(uint16_t *)(unaff_BP + 8),*(uint16_t *)(unaff_BP + 6)
                                  )),
                 (agnt_t far *)
                 CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                          CONCAT12(uVar10,*(uint16_t *)(unaff_BP + -10))),(uint)bVar3,
                 (char)*(uint16_t *)(unaff_BP + -10),uVar10,bVar3);
      ((char_sheet_t *)((unaff_BP + -10)))->race = 0xb;
      ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\r') {
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                         *(uint16_t *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
      bVar3 = ((agnt_t far *)((unaff_BP + -10)))->strength;
      uVar10 = (undefined1)*(uint16_t *)(unaff_BP + -8);
      ovr_ovc41_textParalyzed
                ((agnt_t far *)
                 CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + 8) >> 8),
                          CONCAT12((char)*(uint16_t *)(unaff_BP + 8),*(uint16_t *)(unaff_BP + 6)
                                  )),
                 (agnt_t far *)
                 CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                          CONCAT12(uVar10,*(uint16_t *)(unaff_BP + -10))),(uint)bVar3,
                 (char)*(uint16_t *)(unaff_BP + -10),uVar10,bVar3);
      ((char_sheet_t *)((unaff_BP + -10)))->race = 0xb;
      ((char_sheet_t *)((unaff_BP + -10)))->hp[0] = 0;
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant == '\x0e') {
    if (*(char *)((int)*(uint32_t *)(unaff_BP + -10) + 0x11) != '\0') {
      emptyFunction();
      return;
    }
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                         *(uint16_t *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
      ovr_OVC41_6a8f_01e7_entry
                ((agnt_t far *)*(uint16_t *)(unaff_BP + -10),(char)*(uint16_t *)(unaff_BP + -8));
      puVar1 = (uint *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x800;
      pan = ovr_audio_panFromX((agnt_t far *)*(uint16_t *)(unaff_BP + -10),
                                 (char)*(uint16_t *)(unaff_BP + -8));
      ovr_play_sfxU(0x1b,0,pan,0,(char)pan);
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (((agnt_t far *)((unaff_BP + 6)))->variant != '\x0f') {
    emptyFunction();
    return;
  }
  *(uint16_t *)(unaff_BP + -4) = 0x1e;
  *(uint16_t *)(unaff_BP + -2) = 0;
  do {
    if (((((agnt_t far *)((unaff_BP + -10)))->flags & 0x20) == 0) &&
       (uVar7 = ovc27_rollToHitEntity
                          (CONCAT13((char)((uint)*(uint16_t *)(unaff_BP + -8) >> 8),
                                    CONCAT12((char)*(uint16_t *)(unaff_BP + -8),
                                             *(uint16_t *)(unaff_BP + -10))),3),
       (uVar7 & 0xff) == 0)) {
      savedSeg = (undefined1)GSavedBlitSeg;
      pcVar8 = ovr_agnt_statusText((agnt_t far *)*(uint16_t *)(unaff_BP + 6),
                                   (char *)CONCAT13((char)((uint)(unaff_BP + -0x122) >> 8),
                                                    CONCAT12((char)(unaff_BP + -0x122),
                                                             *(uint16_t *)(unaff_BP + 8))),
                                   (char)*(uint16_t *)(unaff_BP + 8));
      uVar11 = (undefined1)in_DX;
      uVar10 = SUB21(pcVar8,0);
      pcVar8 = ovr_agnt_statusText((agnt_t far *)*(uint16_t *)(unaff_BP + -10),(char *)CONCAT22(unaff_BP + -0xd2,
                                                    (char *)*(uint16_t *)(unaff_BP + -8)),0);
      bufPtr = ovr_ovc15_usesStshRealloc(pcVar8,(char)in_DX,uVar10,uVar11,savedSeg,0,0,0);
      pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),(char *)CONCAT22(0x5c2f,_SS),
                             (char *)CONCAT22(bufPtr,(char *)0x26510),(char)in_DX);
      ovr_uiNotify(pcVar8,in_DX,(char)in_DX);
      ovr_OVC41_6a8f_01e7_entry
                ((agnt_t far *)*(uint16_t *)(unaff_BP + -10),(char)*(uint16_t *)(unaff_BP + -8));
      *(undefined1 *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2f) =
           *(undefined1 *)((int)*(uint32_t *)(unaff_BP + 6) + 0x2f);
      puVar1 = (uint *)((int)*(uint32_t *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x20;
      pan = ovr_audio_panFromX((agnt_t far *)*(uint16_t *)(unaff_BP + -10),
                                 (char)*(uint16_t *)(unaff_BP + -8));
      ovr_play_sfxU(0x1b,0,pan,0,(char)pan);
    }
    do {
      iVar5 = ovc27_usesAgntCount((agnt_t far *)
                                  CONCAT22(*(uint16_t *)(unaff_BP + 8),
                                           (agnt_t far *)*(uint16_t *)(unaff_BP + 6)),0xe,
                                  *(byte *)(unaff_BP + -4),
                                  (int *)CONCAT13((char)((uint)_SS >> 8),
                                                  CONCAT12((char)_SS,unaff_BP + -2)));
      *(uint16_t *)(unaff_BP + -8) = in_DX;
      *(int *)(unaff_BP + -10) = iVar5;
      if (*(int *)(unaff_BP + -10) == 0 && *(int *)(unaff_BP + -8) == 0) break;
    } while (*(int *)(unaff_BP + -2) == unaff_DI);
    if (*(int *)(unaff_BP + -10) != 0 || *(int *)(unaff_BP + -8) != 0) {
      uVar2 = ((agnt_t far *)((unaff_BP + -10)))->entity;
      *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) - (uint)*(byte *)((int)uVar2 + 0xf);
    }
    if ((*(int *)(unaff_BP + -10) == 0 && *(int *)(unaff_BP + -8) == 0) ||
       (*(int *)(unaff_BP + -4) == 0)) {
      return;
    }
  } while( true );
}



/* 5ded:1be7 */

/* placeholder with no body */

void __cdecl16far emptyFunction(void)

{
  return;
}



/* 5ded:1beb */

/* [R6] touches AgntCount */

int __cdecl16far ovc27_usesAgntCount(agnt_t far *agnt,byte recIndex,byte maxLevel,int *cursor)

{
  int iVar1;
  uint32_t uVar2;
  uint16_t uVar3;
  
  while( true ) {
    if ((int)(uint)AgntCount <= *cursor) {
      return 0;
    }
    uVar2 = *(uint32_t *)(*cursor * 0x34 + 0x17);
    if (((*(byte *)((int)uVar2 + 0xf) <= maxLevel) &&
        (*(uint8_t *)*(uint32_t *)(*cursor * 0x34 + 0x1d) != ((agnt_t far *)agnt)->faction)) &&
       (uVar3 = ovc27_usesRandBelow3(agnt,CONCAT22(0x222b,(uint)recIndex * 0x21),*cursor),
       (char)uVar3 != '\0')) break;
    *cursor = *cursor + 1;
  }
  iVar1 = *cursor;
  *cursor = *cursor + 1;
  return iVar1 * 0x34;
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
  uint16_t uVar1;
  uint16_t uVar2;
  byte bVar3;
  int iVar4;
  int viewIdx;
  uint16_t uVar6;
  bool bVar7;
  byte bStack_6;
  uint uStack_4;
  
  uStack_4 = 0;
  while( true ) {
    viewIdx = (int)view;
    uVar6 = (uint16_t)(view >> 0x10);
    if ((frames == '\0') || (*(char *)(viewIdx + 0xf) == '\0')) break;
    bVar3 = ovr_ovc15_textView(view);
    uStack_4 = uStack_4 + bVar3;
    *(char *)(viewIdx + 0xf) = *(char *)(viewIdx + 0xf) + -1;
    frames = frames + -1;
  }
  bVar7 = *(char *)(viewIdx + 0xf) == '\0';
  if (bVar7) {
    *(undefined1 *)(viewIdx + 0xf) = 1;
  }
  if (uStack_4 < *(byte *)(viewIdx + 0x32)) {
    *(char *)(viewIdx + 0x32) = *(char *)(viewIdx + 0x32) - (char)uStack_4;
  }
  else {
    *(undefined1 *)(viewIdx + 0x32) = 1;
  }
  if (uStack_4 < *(byte *)(viewIdx + 0x31)) {
    *(char *)(viewIdx + 0x31) = *(char *)(viewIdx + 0x31) - (char)uStack_4;
  }
  else {
    *(undefined1 *)(viewIdx + 0x31) = 1;
  }
  if (*(byte *)(viewIdx + 0x32) < *(byte *)(viewIdx + 0x31)) {
    *(undefined1 *)(viewIdx + 0x31) = *(undefined1 *)(viewIdx + 0x32);
  }
  bStack_6 = AgntGs[(uint)*(byte *)(viewIdx + 0xd)].shortName[3];
  if (bStack_6 == 0xff) {
    bStack_6 = 0;
  }
  iVar4 = (uint)bStack_6 * 0x94 + (uint)*(byte *)(viewIdx + 0xf) * 4;
  uVar1 = *(uint16_t *)(iVar4 + -2);
  uVar2 = *(uint16_t *)(iVar4 + -4);
  *(uint16_t *)(viewIdx + 0x12) = uVar1;
  *(uint16_t *)(viewIdx + 0x10) = uVar2;
  return CONCAT11((char)((uint)uVar1 >> 8),bVar7);
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


