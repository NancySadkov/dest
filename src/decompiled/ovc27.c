/*
 * ovc27.c - recovered from STRONG.EXE
 * memory block: OVC27
 * range: 5ded:0000 - 5ded:22af
 * functions: 21
 */
#include "recovered.h"


/* 5ded:0000 */

/* Emits the "Intelligence reports %s attacking." notice. */

void __cdecl16far ovc27_intelAttackingNotice(int x1,int y1,int x2,int y2,int *rectOfs,byte rectSeg)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  uint16_t unaff_SS;
  undefined1 in_stack_0000000f;
  byte in_stack_00000010;
  far_t dst;
  uint8_t yOffset;
  int iStack_10;
  int iStack_e;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  byte bStack_3;
  
  iVar5 = y2;
  iVar4 = x2;
  _rectOfs = (int *)CONCAT13(in_stack_0000000f,CONCAT12(rectSeg,rectOfs));
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&yOffset;
  F_SCOPY(far_from_u32((uint32_t)(0x2410592a)),dst);
  if (x2 < x1) {
    x2 = x1;
    x1 = iVar4;
    iStack_6 = y2;
    y2 = y1;
    y1 = iVar5;
  }
  if (x1 < *_rectOfs) {
    x1 = *_rectOfs;
  }
  uVar6 = (undefined2)((ulong)_rectOfs >> 0x10);
  if (rectOfs[2] < x2) {
    x2 = rectOfs[2];
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
    iStack_e = ovr_ovc07_signum(y2 - y1);
    iStack_10 = x2 - x1 >> 1;
    bStack_3 = 0;
    for (iStack_8 = x1; iStack_8 <= x2; iStack_8 = iStack_8 + 1) {
      iVar4 = y1 + *(int *)(&yOffset + ((uint)bStack_3 + (uint)in_stack_00000010 & 0xf) * 2);
      iVar5 = iVar4 + -1;
      bStack_3 = bStack_3 + 1;
      puVar1 = (undefined1 *)(iVar5 * 0x140 + iStack_8);
      if ((rectOfs[1] <= iVar5) && (iVar5 <= rectOfs[3])) {
        *puVar1 = 0xc;
      }
      if ((rectOfs[1] <= iVar4) && (iVar4 <= rectOfs[3])) {
        puVar1[0x140] = 0xf;
      }
      if ((rectOfs[1] <= iVar4 + 1) && (iVar4 + 1 <= rectOfs[3])) {
        puVar1[0x280] = 0xc;
      }
      y1 = y1 + iStack_a;
      iStack_10 = iStack_10 + iStack_c;
      if (x2 - x1 <= iStack_10) {
        y1 = y1 + iStack_e;
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
  int iVar1;
  int iVar2;
  uint8_t *puVar3;
  uint16_t uVar4;
  uint uVar5;
  uint uVar6;
  brect_t *pbVar7;
  undefined2 uVar8;
  uint16_t unaff_SS;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  uint8_t plane2;
  uint8_t plane1;
  uint8_t plane0;
  int iStack_10;
  int iStack_e;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  byte bStack_3;
  
  iVar1 = y2;
  iVar2 = x2;
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&plane0;
  F_SCOPY(far_from_u32((uint32_t)(0x2410594a)),dst);
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&plane1;
  F_SCOPY(far_from_u32((uint32_t)(0x2410596a)),dst_00);
  dst_01.seg = unaff_SS;
  dst_01.ofs = (uint16_t)&plane2;
  F_SCOPY(far_from_u32((uint32_t)(0x2410598a)),dst_01);
  if (x2 < x1) {
    x2 = x1;
    x1 = iVar2;
    iStack_6 = y2;
    y2 = y1;
    y1 = iVar1;
  }
  if (x1 < rect->x) {
    x1 = rect->x;
  }
  uVar8 = (undefined2)((ulong)rect >> 0x10);
  pbVar7 = (brect_t *)rect;
  if (pbVar7->w < x2) {
    x2 = pbVar7->w;
  }
  if (x1 <= x2) {
    if (x1 == x2) {
      iStack_a = 0;
      iStack_c = 0;
    }
    else {
      iStack_a = (y2 - y1) / (x2 - x1);
      uVar5 = (y2 - y1) % (x2 - x1);
      uVar6 = (int)uVar5 >> 0xf;
      iStack_c = (uVar5 ^ uVar6) - uVar6;
    }
    iStack_e = ovr_ovc07_signum(y2 - y1);
    iStack_10 = x2 - x1 >> 1;
    bStack_3 = rectSeg;
    for (iStack_8 = x1; iStack_8 <= x2; iStack_8 = iStack_8 + 1) {
      bStack_3 = bStack_3 + 1 & 0xf;
      iVar2 = y1 + -1;
      puVar3 = (uint8_t *)(iVar2 * 0x140 + iStack_8);
      if ((((pbVar7->y <= iVar2) && (iVar2 <= pbVar7->h)) &&
          (*(int *)(&plane0 + (uint)bStack_3 * 2) != 0)) &&
         (uVar4 = ovr_randBelow(3), (uVar4 & 0xff) == 0)) {
        *puVar3 = (&plane0)[(uint)bStack_3 * 2];
      }
      if (((pbVar7->y <= y1) && (y1 <= pbVar7->h)) &&
         ((*(int *)(&plane1 + (uint)bStack_3 * 2) != 0 &&
          (uVar4 = ovr_randBelow(3), (uVar4 & 0xff) == 0)))) {
        puVar3[0x140] = (&plane1)[(uint)bStack_3 * 2];
      }
      if (((pbVar7->y <= y1 + 1) && (y1 + 1 <= pbVar7->h)) &&
         ((*(int *)(&plane2 + (uint)bStack_3 * 2) != 0 &&
          (uVar4 = ovr_randBelow(3), (uVar4 & 0xff) == 0)))) {
        puVar3[0x280] = (&plane2)[(uint)bStack_3 * 2];
      }
      y1 = y1 + iStack_a;
      iStack_10 = iStack_10 + iStack_c;
      if (x2 - x1 <= iStack_10) {
        y1 = y1 + iStack_e;
        iStack_10 = iStack_10 - (x2 - x1);
      }
    }
  }
  return;
}



/* 5ded:0404 */

/* [R7] body shape: compute */

uint __cdecl16far ovc27_compute1(agnt_t *agnt,int param)

{
  undefined4 uVar1;
  uint in_AX;
  byte bVar3;
  undefined1 uVar4;
  uint uVar2;
  agnt_t *paVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)agnt >> 0x10);
  paVar5 = (agnt_t *)agnt;
  if ((((agntG_t *)paVar5->gdata)->flags & 2) != 0) {
    uVar1 = *(undefined4 *)(param * 0x34 + 0x1d);
    bVar3 = (byte)((uint)(param * 0x34) >> 8);
    if (((*(uint *)((int)uVar1 + 0x3e) & 0x10) != 0) &&
       ((((entity_t *)paVar5->entity)->base).level < 3)) {
      return (uint)bVar3 << 8;
    }
    return CONCAT11(bVar3,1);
  }
  if ((((agntG_t *)paVar5->gdata)->flags & 1) != 0) {
    in_AX = param * 0x34;
    uVar4 = (undefined1)(in_AX >> 8);
    if (((*(uint *)((int)*(undefined4 *)(in_AX + 0x1d) + 0x3c) & 4) != 0) &&
       (3 < (((entity_t *)paVar5->entity)->base).level)) {
      return CONCAT11(uVar4,1);
    }
    if (9 < (((entity_t *)paVar5->entity)->base).level) {
      return CONCAT11(uVar4,1);
    }
  }
  if (((((agntG_t *)paVar5->gdata)->flags & 0x800) == 0) ||
     (in_AX = param * 0x34, (*(uint *)((int)*(undefined4 *)(in_AX + 0x1d) + 0x3c) & 4) == 0)) {
    uVar2 = in_AX & 0xff00;
  }
  else {
    uVar2 = CONCAT11((char)(in_AX >> 8),1);
  }
  return uVar2;
}



/* 5ded:04cd */

/* Rolls 1..40 against the owner's stat and returns whether the roll succeeds. */

int __cdecl16far ovc27_rollAgainstStat(agnt_t *agnt,byte mode)

{
  entity_t *peVar1;
  undefined4 uVar2;
  uint16_t uVar3;
  uint uVar4;
  byte bVar6;
  int iVar5;
  byte bStack_4;
  
  peVar1 = ((agnt_t *)agnt)->entity;
  bVar6 = *(byte *)((int)&(((entity_t *)peVar1)->base).entity + 3);
  if (bVar6 == 0xff) {
    bStack_4 = 6;
  }
  else {
    uVar2 = *(undefined4 *)((uint)bVar6 << 2);
    bStack_4 = *(byte *)((int)uVar2 + (uint)mode + 0x29);
  }
  uVar3 = ovr_randBelow(0x28);
  uVar4 = (uVar3 & 0xff) + 1;
  bVar6 = (byte)(uVar4 >> 8);
  if (bStack_4 < uVar4) {
    iVar5 = (uint)bVar6 << 8;
  }
  else {
    iVar5 = CONCAT11(bVar6,1);
  }
  return iVar5;
}



/* 5ded:052d */

/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc27_usesRandBelow3(agnt_t *agnt,uint32_t reqRecord,int agntIndex)

{
  byte bVar1;
  uint uVar2;
  byte bVar5;
  uint uVar3;
  uint16_t uVar4;
  int iVar6;
  agnt_t *paVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  uint16_t unaff_SS;
  far_t dst;
  far_t dst_00;
  uint8_t reqLevel2;
  uint uStack_10;
  undefined2 uStack_e;
  uint8_t reqLevel1;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&reqLevel1;
  F_SCOPY(far_from_u32((uint32_t)(0x241059aa)),dst);
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&reqLevel2;
  F_SCOPY(far_from_u32((uint32_t)(0x241059b4)),dst_00);
  uVar2 = agntIndex * 0x34;
  _uStack_10 = CONCAT22(0x1726,uVar2);
  uVar8 = (undefined2)(reqRecord >> 0x10);
  iVar6 = (int)reqRecord;
  paVar7 = (agnt_t *)agnt;
  uVar9 = (undefined2)((ulong)agnt >> 0x10);
  if (*(char *)(iVar6 + 8) == '\0') {
    if ((((agntG_t *)paVar7->gdata)->flags & 2) == 0) {
      return uVar2 & 0xff00;
    }
    if ((((entity_t *)paVar7->entity)->base).level < (&reqLevel1)[*(byte *)(iVar6 + 9)]) {
      return (uint)(&reqLevel1 + *(byte *)(iVar6 + 9)) & 0xff00;
    }
  }
  else {
    bVar5 = (byte)(uVar2 >> 8);
    if (*(char *)(iVar6 + 8) == '\x01') {
      if ((((agntG_t *)paVar7->gdata)->flags & 1) == 0) {
        return (uint)bVar5 << 8;
      }
      if ((((entity_t *)paVar7->entity)->base).level < (&reqLevel2)[*(byte *)(iVar6 + 9)]) {
        return (uint)(&reqLevel2 + *(byte *)(iVar6 + 9)) & 0xff00;
      }
    }
    else if ((*(char *)(iVar6 + 8) == '\x02') && ((((agntG_t *)paVar7->gdata)->flags & 0x800) == 0))
    {
      return (uint)bVar5 << 8;
    }
  }
  if ((*(uint *)((int)*(undefined4 *)(uVar2 + 0x1d) + 0x3c) & *(uint *)(iVar6 + 0x15)) == 0) {
    if ((*(uint *)((int)*(undefined4 *)(uVar2 + 0x1d) + 0x3e) & *(uint *)(iVar6 + 0x19)) == 0) {
      if ((*(uint *)((int)*(undefined4 *)(uVar2 + 0x1d) + 0x40) & *(uint *)(iVar6 + 0x1d)) == 0) {
        if ((*(uint *)(uVar2 + 0x2b) & *(uint *)(iVar6 + 0xf)) == 0) {
          uVar3 = (uint)*(byte *)(iVar6 + 0x13);
          if ((*(uint *)((int)*(undefined4 *)(uVar2 + 0x17) + 0x14) & uVar3) == 0) {
            if ((*(int *)(iVar6 + 0x17) != 0) &&
               (uVar3 = *(uint *)(iVar6 + 0x17),
               (*(uint *)((int)*(undefined4 *)(uVar2 + 0x1d) + 0x3c) & uVar3) == 0)) {
              return uVar3 & 0xff00;
            }
            if ((*(int *)(iVar6 + 0x1b) != 0) &&
               (uVar3 = *(uint *)(iVar6 + 0x1b),
               (*(uint *)((int)*(undefined4 *)(uVar2 + 0x1d) + 0x3e) & uVar3) == 0)) {
              return uVar3 & 0xff00;
            }
            if ((*(int *)(iVar6 + 0x1f) != 0) &&
               (uVar3 = *(uint *)(iVar6 + 0x1f),
               (*(uint *)((int)*(undefined4 *)(uVar2 + 0x1d) + 0x40) & uVar3) == 0)) {
              return uVar3 & 0xff00;
            }
            if ((*(int *)(iVar6 + 0x11) != 0) &&
               (uVar3 = *(uint *)(iVar6 + 0x11), (*(uint *)(uVar2 + 0x2b) & uVar3) == 0)) {
              return uVar3 & 0xff00;
            }
            if ((*(char *)(iVar6 + 0x14) == '\0') ||
               (uVar3 = (uint)*(byte *)(iVar6 + 0x14),
               (*(uint *)((int)*(undefined4 *)(uVar2 + 0x17) + 0x14) & uVar3) != 0)) {
              bVar5 = (byte)(uVar3 >> 8);
              if ((*(char *)(iVar6 + 0xc) == '\0') || (*(char *)(uVar2 + 0x11) == '\0')) {
                bVar1 = *(byte *)((int)*(undefined4 *)(uVar2 + 0x17) + 0xf);
                uVar4 = CONCAT11(bVar5,bVar1);
                if (bVar1 < *(byte *)(iVar6 + 0xe)) {
                  if ((*(byte *)(iVar6 + 0xd) < 100) &&
                     (uVar4 = ovr_randBelow(100), *(byte *)(iVar6 + 0xd) <= (byte)uVar4)) {
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
          uVar2 = *(uint *)(iVar6 + 0xf) & 0xff00;
        }
      }
      else {
        uVar2 = *(uint *)(iVar6 + 0x1d) & 0xff00;
      }
    }
    else {
      uVar2 = *(uint *)(iVar6 + 0x19) & 0xff00;
    }
  }
  else {
    uVar2 = *(uint *)(iVar6 + 0x15) & 0xff00;
  }
  return uVar2;
}



/* 5ded:079d */

/* [R4] calls ovr_randBelow */

int __cdecl16far ovc27_usesRandBelow4(byte level,byte threshold)

{
  undefined2 in_AX;
  byte bVar3;
  int iVar1;
  uint16_t uVar2;
  
  bVar3 = (byte)((uint)in_AX >> 8);
  if (level < threshold) {
    iVar1 = (uint)bVar3 << 8;
  }
  else if (level == threshold) {
    uVar2 = ovr_randBelow(8);
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

uint __cdecl16far ovc27_compute2(agnt_t *agnt,int param)

{
  undefined4 uVar1;
  uint in_AX;
  uint uVar2;
  undefined2 uVar3;
  agnt_t *paVar4;
  undefined2 uVar5;
  byte bStack_3;
  
  uVar5 = (undefined2)((ulong)agnt >> 0x10);
  paVar4 = (agnt_t *)agnt;
  if ((((agntG_t *)paVar4->gdata)->flags & 2) == 0) {
    if ((((agntG_t *)paVar4->gdata)->flags & 1) == 0) {
      if (((((((agntG_t *)paVar4->gdata)->flags & 0x800) != 0) &&
           (in_AX = ovc27_rollAgainstStat(agnt,5), (char)in_AX != '\0')) &&
          (in_AX = param * 0x34, (*(uint *)(in_AX + 0x2b) & 0x7e0) == 0)) &&
         ((in_AX = param * 0x34, (*(uint *)((int)*(undefined4 *)(in_AX + 0x1d) + 0x40) & 0x80) == 0
          && (in_AX = param * 0x34, (*(uint *)((int)*(undefined4 *)(in_AX + 0x1d) + 0x3c) & 4) != 0)
          ))) {
        return CONCAT11((char)(in_AX >> 8),1);
      }
      uVar2 = in_AX & 0xff00;
    }
    else {
      uVar3 = ovc27_usesRandBelow3(agnt,0x222b0108,param);
      if ((char)uVar3 == '\0') {
        uVar2 = ovc27_usesRandBelow3(agnt,0x222b014a,param);
        if ((char)uVar2 == '\0') {
          return uVar2 & 0xff00;
        }
        bStack_3 = 10;
      }
      else {
        bStack_3 = 4;
      }
      uVar2 = ovc27_usesRandBelow4((((entity_t *)paVar4->entity)->base).level,bStack_3);
      if ((uVar2 & 0xff) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = ovc27_rollAgainstStat(agnt,2);
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
    uVar2 = ovc27_usesRandBelow4((((entity_t *)paVar4->entity)->base).level,1);
    if ((uVar2 & 0xff) == 0) {
      uVar2 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(param * 0x34 + 0x1d);
      if (((*(uint *)((int)uVar1 + 0x3e) & 0x10) == 0) ||
         (2 < (((entity_t *)paVar4->entity)->base).level)) {
        uVar2 = ovc27_rollAgainstStat(agnt,1);
        if ((uVar2 & 0xff) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
      else {
        uVar2 = param * 0x34 & 0xff00;
      }
    }
  }
  return uVar2;
}



/* 5ded:0960 */

/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc27_usesRandBelow5(agnt_t *agnt)

{
  uint in_AX;
  uint uVar1;
  undefined2 uVar2;
  uint16_t uVar3;
  undefined2 uVar4;
  uint16_t unaff_SS;
  uint8_t indexMap;
  byte bStack_4;
  byte bStack_3;
  
  uVar4 = (undefined2)((ulong)agnt >> 0x10);
  if (((agnt_t *)agnt)->target == 0xff) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    _fmemset(&indexMap,unaff_SS,0);
    bStack_3 = 0;
    for (bStack_4 = 0; bStack_4 < 0xf; bStack_4 = bStack_4 + 1) {
      uVar2 = ovc27_usesRandBelow3
                        (agnt,CONCAT22(0x222b,(uint)bStack_4 * 0x21),(uint)((agnt_t *)agnt)->target)
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
      uVar3 = ovr_randBelow((uint)bStack_3);
      uVar1 = CONCAT11((char)((uint)(&indexMap + (uVar3 & 0xff)) >> 8),(&indexMap)[uVar3 & 0xff]);
    }
  }
  return uVar1;
}



/* 5ded:0a05 */

/* Formats the "%s casts a %s spell %s %s." notice. */

uint __cdecl16far ovc27_spellNotice(int agntIndex)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  byte bVar4;
  uint16_t uVar5;
  uint uVar6;
  char *msg;
  agntG_t *paVar7;
  int *piVar8;
  undefined2 uVar9;
  char *unaff_SS;
  long lVar10;
  uint8_t text;
  byte bStack_13;
  int iStack_12;
  undefined2 uStack_10;
  int iStack_e;
  int iStack_c;
  int iStack_a;
  undefined2 uStack_8;
  agnt_t *paStack_6;
  undefined2 uStack_4;
  
  paStack_6 = (agnt_t *)(agntIndex * 0x34);
  uStack_4 = 0x1726;
  bVar4 = (byte)((uint)paStack_6 >> 8);
  if ((((agntG_t *)paStack_6->gdata)->flags & 0x803) == 0) {
    return (uint)bVar4 << 8;
  }
  if (paStack_6->animFrame == 0xff) {
    iStack_a = (uint)paStack_6->target * 0x34;
    uStack_8 = 0x1726;
    uVar9 = uStack_8;
    uStack_8 = 0x1726;
    uVar3 = uVar9;
    if (((((((agntG_t *)paStack_6->gdata)->flags & 0x1000) != 0) &&
         (uVar3 = uStack_8, (*(uint *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x3e) & 0x10) == 0))
        && ((uStack_8 = uVar9, (*(uint *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x3e) & 8) == 0 ||
            (bVar4 = ovr_agnt_compute9((agnt_t *)CONCAT22(0x1726,paStack_6)), uVar3 = uStack_8,
            '\0' < (char)bVar4)))) &&
       (uVar5 = ovr_randBelow(2), uVar3 = uStack_8, (uVar5 & 0xff) == 0)) {
      return 0;
    }
    uStack_8 = uVar3;
    uVar6 = ovc27_usesRandBelow5((agnt_t *)CONCAT22(uStack_4,paStack_6));
    bStack_13 = (byte)uVar6;
    uVar6 = uVar6 & 0xff;
    if (uVar6 == 0) {
      ovr_agnt_usesAnimFrame((agnt_t *)CONCAT22(uStack_4,paStack_6));
      uVar6 = uVar6 & 0xff00;
    }
    else {
      uVar5 = 0x222b;
      uVar9 = (undefined2)((ulong)paStack_6->gdata >> 0x10);
      paVar7 = (agntG_t *)paStack_6->gdata;
                    /* WARNING: Load size is inaccurate */
      ovr_ovc15_usesStshRealloc
                ((char *)CONCAT22(*(undefined2 *)((int)&paVar7->name + 2),paVar7->name));
      msg = ovr_stsprintf((char *)&text,unaff_SS,(char *)"%s casts a %s spell %s %s.");
      ovr_uiNotify(msg,uVar5);
      paStack_6->variant = bStack_13;
      if (*(char *)((uint)bStack_13 * 0x21 + -0x17) == '9') {
        uVar6 = ovr_audio_panFromX((agnt_t *)CONCAT22(uStack_4,paStack_6));
        lVar10 = (ulong)uVar6 << 0x10;
        uVar5 = ovr_randBelow(2);
        ovr_play_sfxU((char)uVar5 + 0x39,(int)lVar10,(uint16_t)((ulong)lVar10 >> 0x10));
      }
      else {
        uVar5 = ovr_audio_panFromX((agnt_t *)CONCAT22(uStack_4,paStack_6));
        ovr_play_sfxU(*(byte *)((uint)bStack_13 * 0x21 + -0x17),0,uVar5);
      }
      if (*(char *)((uint)bStack_13 * 0x21 + -0x16) == '\0') {
        paStack_6->animFrame = 0xf5;
        uVar6 = 1;
      }
      else {
        uVar9 = *(undefined2 *)((int)&paStack_6->frames + 2);
        _iStack_12 = CONCAT22(uVar9,*(int *)&paStack_6->frames);
        piVar8 = (int *)(*(int *)&paStack_6->frames + (uint)paStack_6->frameIndex * 4);
        iVar1 = piVar8[1];
        iVar2 = *piVar8;
        _iStack_e = CONCAT22(iVar1,iVar2);
        if (iVar2 == 0 && iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x42);
        }
        paStack_6->animFrame = 0x0;
        *(char *)&paStack_6->destY = *(char *)(iVar2 + 0x15) + (char)paStack_6->screenY;
        if (paStack_6->level == 0x0) {
          uVar5 = *(int *)(iVar2 + 0x13) + paStack_6->screenX;
          paStack_6->destX = uVar5;
        }
        else {
          uVar5 = paStack_6->screenX - *(int *)(iVar2 + 0x13);
          paStack_6->destX = uVar5;
        }
        *(uint8_t *)((int)&paStack_6->destY + 1) = paStack_6->level;
        uVar6 = CONCAT11((char)(uVar5 >> 8),1);
      }
    }
    return uVar6;
  }
  return (uint)bVar4 << 8;
}



/* 5ded:0cc2 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc27_usesBlitGfxRect(int agntIndex,brect_t *rect,uint16_t type)

{
  undefined2 uVar1;
  uint16_t uVar2;
  agnt_t *paVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  stg_tmp_t *psVar7;
  uint16_t uVar8;
  uint16_t *puVar9;
  far_t gfx;
  far_t gfx_00;
  byte rectSeg;
  int iStack_e;
  undefined2 uStack_c;
  
  paVar3 = (agnt_t *)(agntIndex * 0x34);
  iVar4 = (uint)paVar3->target * 0x34;
  if (((paVar3->combatState == 0x0) && (paVar3->target != 0xff)) && (paVar3->animFrame != 0xff)) {
    uVar1 = *(undefined2 *)((int)&paVar3->frames + 2);
    iVar6 = *(int *)&paVar3->frames;
    if (paVar3->animVariant == 0x0) {
      uStack_c = *(undefined2 *)(iVar6 + 0xe);
      iStack_e = *(int *)(iVar6 + 0xc);
    }
    else {
      uStack_c = *(undefined2 *)(iVar6 + 0x12);
      iStack_e = *(int *)(iVar6 + 0x10);
    }
    if (paVar3->level == 0x0) {
      uVar5 = paVar3->screenX + *(int *)(iStack_e + 0x13);
      if (*(uint *)(iVar4 + 0x26) <= uVar5) {
        paVar3->animFrame = 0xff;
        paVar3->variant = 0x0;
        return;
      }
    }
    else {
      uVar5 = paVar3->screenX - *(int *)(iStack_e + 0x13);
      if (uVar5 <= *(uint *)(iVar4 + 0x26)) {
        paVar3->animFrame = 0xff;
        paVar3->variant = 0x0;
        return;
      }
    }
    puVar9 = (uint16_t *)(*(int *)(iVar4 + 0x13) + (uint)*(byte *)(iVar4 + 0x12) * 4);
    uVar2 = puVar9[1];
    uVar8 = *puVar9;
    if ((*(int *)(iVar4 + 0x28) != 0) || (*(int *)(iVar4 + 0x26) != 0)) {
      rectSeg = (byte)type;
      if (paVar3->variant == 0x1) {
        if (paVar3->animFrame < 0xfc) {
          ovc27_intelAttackingNotice
                    (uVar5,*(int *)(iStack_e + 0x15) + paVar3->screenY,*(int *)(iVar4 + 0x26),
                     *(int *)(iVar4 + 0x28) - (*(int *)(uVar8 + 0xd) >> 1),&rect->x,rectSeg);
        }
        uVar5 = paVar3->animFrame & 3;
        gfx.seg = ((undefined2 *)&boltSpritesSeg)[uVar5 * 2];
        gfx.ofs = ((undefined2 *)&boltSpritesOfs)[uVar5 * 2];
        ovr_blitGfxRect(gfx,*(int16_t *)(iVar4 + 0x26),
                        *(int *)(iVar4 + 0x28) - (*(int *)(uVar8 + 0xd) >> 1),rect,rectSeg,true);
      }
      else {
        if (uVar5 < *(uint *)(iVar4 + 0x26)) {
          *(undefined1 *)&paVar3->flags32 = 0;
          iVar6 = *(int *)(iVar4 + 0x26) + -8;
        }
        else {
          *(undefined1 *)&paVar3->flags32 = 1;
          iVar6 = *(int *)(iVar4 + 0x26) + 8;
        }
        if (paVar3->animFrame < 0xfb) {
          ovc27_usesRandBelow(uVar5,*(int *)(iStack_e + 0x15) + paVar3->screenY,iVar6,
                              *(int *)(iVar4 + 0x28) + -6,(brect_t *)CONCAT22(type,rect),
                              paVar3->animFrame << 1);
        }
        if (0xf8 < paVar3->animFrame) {
          psVar7 = ovr_stash_usesStExit
                             ((stg_tmp_t *)*(undefined2 *)(SprProjectiles.ofs + 0x8c),
                              (byte)*(undefined2 *)(SprProjectiles.ofs + 0x8e));
          gfx_00.seg = uVar8;
          gfx_00.ofs = (uint16_t)(psVar7->cmap + 6);
          ovr_blitGfxRect(gfx_00,*(int16_t *)(iVar4 + 0x26),*(int16_t *)(iVar4 + 0x28),rect,rectSeg,
                          true);
        }
      }
      paVar3->animFrame = paVar3->animFrame + 0x1;
      paVar3->health = 0x2;
      if (paVar3->animFrame == 0xff) {
        ovr_ovc41_resolveSpecialAttack_2((agnt_t *)CONCAT22(0x1726,paVar3),(uint)paVar3->target);
        paVar3->variant = 0x0;
        paVar3->health = 0x0;
      }
    }
  }
  else {
    paVar3->animFrame = 0xff;
    paVar3->variant = 0x0;
  }
  return;
}



/* 5ded:0fd2 */

/* Notifies "%s takes half damage from spells." for the qualifying types and levels. */

uint __cdecl16far ovc27_spellHalfDamage(agnt_t *agnt)

{
  uint in_AX;
  char *pcVar1;
  uint uVar2;
  uint16_t in_DX;
  agnt_t *paVar3;
  undefined2 uVar4;
  char *unaff_SS;
  uint8_t text;
  uint8_t msg;
  
  uVar4 = (undefined2)((ulong)agnt >> 0x10);
  paVar3 = (agnt_t *)agnt;
  if (((((agntG_t *)paVar3->gdata)->shortName[3] == '\x04') &&
      (0xf < (((entity_t *)paVar3->entity)->base).level)) ||
     ((((agntG_t *)paVar3->gdata)->shortName[3] == '\x06' &&
      (8 < (((entity_t *)paVar3->entity)->base).level)))) {
    pcVar1 = ovr_agnt_statusText(agnt,(char *)&text);
    ovr_ovc15_usesStshRealloc((char *)CONCAT22(in_DX,pcVar1));
    pcVar1 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s takes half damage from spells.");
    ovr_uiNotify(pcVar1,in_DX);
    uVar2 = CONCAT11((char)((uint)pcVar1 >> 8),1);
  }
  else {
    uVar2 = in_AX & 0xff00;
  }
  return uVar2;
}



/* 5ded:105e */

/* Notifies "%s takes half damage from dragon breath." for the qualifying types. */

uint __cdecl16far ovc27_breathHalfDamage(agnt_t *agnt)

{
  uint in_AX;
  char *pcVar1;
  uint uVar2;
  uint16_t in_DX;
  agnt_t *paVar3;
  undefined2 uVar4;
  char *unaff_SS;
  uint8_t text;
  uint8_t msg;
  
  uVar4 = (undefined2)((ulong)agnt >> 0x10);
  paVar3 = (agnt_t *)agnt;
  if (((((agntG_t *)paVar3->gdata)->shortName[3] == '\x05') &&
      (0xd < (((entity_t *)paVar3->entity)->base).level)) ||
     ((((agntG_t *)paVar3->gdata)->shortName[3] == '\x06' &&
      (0xe < (((entity_t *)paVar3->entity)->base).level)))) {
    pcVar1 = ovr_agnt_statusText(agnt,(char *)&text);
    ovr_ovc15_usesStshRealloc((char *)CONCAT22(in_DX,pcVar1));
    pcVar1 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s takes half damage from dragon breath.")
    ;
    ovr_uiNotify(pcVar1,in_DX);
    uVar2 = CONCAT11((char)((uint)pcVar1 >> 8),1);
  }
  else {
    uVar2 = in_AX & 0xff00;
  }
  return uVar2;
}



/* 5ded:10ea */

/* [R2] string "%s takes half damage from lightning." */

void __cdecl16far ovc27_textTakesHalfDamage3(agnt_t *agnt,uint16_t agntIndex)

{
  byte bVar1;
  uint uVar2;
  uint16_t uVar3;
  int iVar4;
  char *pcVar5;
  uint16_t uVar6;
  agnt_t *paVar7;
  undefined2 uVar8;
  char *unaff_SS;
  uint8_t text1;
  uint8_t text2;
  uint8_t msg;
  agnt_t *paStack_c;
  undefined2 uStack_a;
  int iStack_8;
  
  uVar6 = (uint16_t)((ulong)((long)(int)agntIndex * 0x34) >> 0x10);
  paStack_c = (agnt_t *)(agnt_t *)((long)(int)agntIndex * 0x34);
  uStack_a = 0x1726;
  uVar8 = (undefined2)((ulong)agnt >> 0x10);
  paVar7 = (agnt_t *)agnt;
  if (paVar7->variant == 0x1) {
    if ((((agntG_t *)paVar7->gdata)->flags3 & 1) == 0) {
      bVar1 = ovr_manage_rollDice((((entity_t *)paVar7->entity)->base).level,'\x06');
      uVar2 = (uint)bVar1;
      uVar8 = ovc27_spellHalfDamage
                        ((agnt_t *)
                         CONCAT13((char)((uint)uStack_a >> 8),CONCAT12((char)uStack_a,paStack_c)));
      if ((char)uVar8 != '\0') {
        uVar2 = (int)uVar2 >> 1;
      }
    }
    else {
      uVar2 = (uint)paVar7->strength;
      uVar8 = ovc27_breathHalfDamage((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,paStack_c)));
      if ((char)uVar8 != '\0') {
        uVar2 = (int)uVar2 >> 1;
      }
    }
    if ((((agntG_t *)paStack_c->gdata)->flags3 & 1) == 0) {
      iVar4 = ovc27_rollToHitEntity
                        (CONCAT13((char)((uint)uStack_a >> 8),CONCAT12((char)uStack_a,paStack_c)),3)
      ;
      if ((char)iVar4 != '\0') {
        uVar2 = (int)uVar2 >> 1;
      }
      ovr_ovc41_textParalyzed
                (agnt,(agnt_t *)
                      CONCAT13((char)((uint)uStack_a >> 8),CONCAT12((char)uStack_a,paStack_c)),uVar2
                );
      *(undefined1 *)&paStack_c->state = 0xb;
      *(undefined1 *)((int)&paStack_c->state + 1) = 0;
      emptyFunction();
      return;
    }
    pcVar5 = ovr_agnt_statusText((agnt_t *)CONCAT22(uStack_a,paStack_c),(char *)&text2);
    ovr_ovc15_usesStshRealloc((char *)CONCAT13((char)(uVar6 >> 8),CONCAT12((char)uVar6,pcVar5)));
    pcVar5 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s takes half damage from lightning.");
    ovr_uiNotify(pcVar5,uVar6);
    emptyFunction();
    return;
  }
  if (paVar7->variant == 0x2) {
    iStack_8 = ((((entity_t *)paVar7->entity)->base).level / 5) * 2 + 1;
    bVar1 = ovr_manage_rollDice((char)iStack_8,'\x06');
    uVar2 = (uint)bVar1 + iStack_8;
    uVar8 = ovc27_spellHalfDamage
                      ((agnt_t *)
                       CONCAT13((char)((uint)uStack_a >> 8),CONCAT12((char)uStack_a,paStack_c)));
    if ((char)uVar8 != '\0') {
      uVar2 = (int)uVar2 >> 1;
    }
    ovr_ovc41_textParalyzed
              (agnt,(agnt_t *)
                    CONCAT13((char)((uint)uStack_a >> 8),CONCAT12((char)uStack_a,paStack_c)),uVar2);
    *(undefined1 *)&paStack_c->state = 0xb;
    *(undefined1 *)((int)&paStack_c->state + 1) = 0;
    emptyFunction();
    return;
  }
  if (paVar7->variant == 0xa) {
    if ((paStack_c->flags & 0x420) != 0) {
      emptyFunction();
      return;
    }
    uVar3 = ovr_randBelow(3);
    if (((uVar3 & 0xff) == 0) &&
       (uVar2 = ovc27_rollToHitEntity
                          (CONCAT13((char)((uint)uStack_a >> 8),CONCAT12((char)uStack_a,paStack_c)),
                           3), (uVar2 & 0xff) == 0)) {
      ovr_agnt_statusText(agnt,(char *)&text1);
      pcVar5 = ovr_agnt_statusText((agnt_t *)CONCAT22(uStack_a,paStack_c),(char *)&text2);
      ovr_ovc15_usesStshRealloc((char *)CONCAT22(uVar6,pcVar5));
      pcVar5 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s is charmed by %s.");
      ovr_uiNotify(pcVar5,uVar6);
      ovr_OVC41_6a8f_01e7_entry
                ((agnt_t *)CONCAT13((char)((uint)uStack_a >> 8),CONCAT12((char)uStack_a,paStack_c)))
      ;
      paStack_c->faction = paVar7->faction;
      paStack_c->flags = paStack_c->flags | 0x20;
      uVar6 = ovr_audio_panFromX((agnt_t *)
                                 CONCAT13((char)((uint)uStack_a >> 8),
                                          CONCAT12((char)uStack_a,paStack_c)));
      ovr_play_sfxU(0x1b,0,uVar6);
      emptyFunction();
      return;
    }
    ovr_agnt_statusText((agnt_t *)CONCAT22(uStack_a,paStack_c),(char *)&text1);
    pcVar5 = ovr_agnt_statusText(agnt,(char *)&text2);
    ovr_ovc15_usesStshRealloc((char *)CONCAT22(uVar6,pcVar5));
    pcVar5 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s fails to charm %s.");
    ovr_uiNotify(pcVar5,uVar6);
    paStack_c->flags = paStack_c->flags | 0x400;
    emptyFunction();
    return;
  }
  if ((paVar7->variant != 0x3) && (paVar7->variant != 0x5)) {
    ovc27_textTakesHalfDamage4();
    return;
  }
  if ((paStack_c->flags & 0x20) != 0) {
    emptyFunction();
    return;
  }
  iVar4 = ovc27_rollToHitEntity(CONCAT13(0x17,CONCAT12(0x26,paStack_c)),3);
  if ((char)iVar4 == '\0') {
    ovr_agnt_statusText(agnt,(char *)&text1);
    pcVar5 = ovr_agnt_statusText((agnt_t *)CONCAT22(uStack_a,paStack_c),(char *)&text2);
    ovr_ovc15_usesStshRealloc((char *)CONCAT22(uVar6,pcVar5));
    pcVar5 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s is charmed by %s.");
    ovr_uiNotify(pcVar5,uVar6);
    paStack_c->faction = paVar7->faction;
    ovr_OVC41_6a8f_01e7_entry
              ((agnt_t *)CONCAT13((char)((uint)uStack_a >> 8),CONCAT12((char)uStack_a,paStack_c)));
    paStack_c->flags = paStack_c->flags | 0x20;
    uVar6 = ovr_audio_panFromX((agnt_t *)
                               CONCAT13((char)((uint)uStack_a >> 8),
                                        CONCAT12((char)uStack_a,paStack_c)));
    ovr_play_sfxU(0x1b,0,uVar6);
    emptyFunction();
    return;
  }
  emptyFunction();
  return;
}



/* 5ded:14a8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* [R2] string "%s takes half damage from fire." */

void ovc27_textTakesHalfDamage4(void)

{
  uint *puVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined2 uVar4;
  int iVar5;
  uint16_t uVar6;
  uint uVar7;
  char *pcVar8;
  uint16_t in_DX;
  int unaff_BP;
  int unaff_DI;
  char *unaff_SS;
  
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\x04') {
    uVar6 = ovr_audio_panFromX((agnt_t *)
                               CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                        CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                                 *(undefined2 *)(unaff_BP + -10))));
    ovr_play_sfxU(0x4c,0,uVar6);
    uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x1d);
    if ((*(uint *)((int)uVar2 + 0x40) & 0x20) == 0) {
      ovr_ovc28_usesBDADailyTimeCounter(6);
      uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 6) + 0x17);
      bVar3 = ovr_manage_rollDice(*(char *)((int)uVar2 + 0xf),'\x06');
      uVar7 = bVar3 + 1;
      iVar5 = ovc27_rollToHitEntity
                        (CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                  CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                           *(undefined2 *)(unaff_BP + -10))),3);
      if ((char)iVar5 != '\0') {
        uVar7 = (int)uVar7 >> 1;
      }
      uVar4 = ovc27_spellHalfDamage
                        ((agnt_t *)
                         CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                  CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                           *(undefined2 *)(unaff_BP + -10))));
      if ((char)uVar4 != '\0') {
        uVar7 = (int)uVar7 >> 1;
      }
      uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x1d);
      if ((*(uint *)((int)uVar2 + 0x3e) & 0x200) != 0) {
        pcVar8 = ovr_agnt_statusText((agnt_t *)
                                     CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                              CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                                       *(undefined2 *)(unaff_BP + -10))),
                                     (char *)(unaff_BP + -0xd2));
        ovr_ovc15_usesStshRealloc((char *)CONCAT13((char)(in_DX >> 8),CONCAT12((char)in_DX,pcVar8)))
        ;
        pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),unaff_SS,
                               (char *)"%s takes half damage from fire.");
        ovr_uiNotify(pcVar8,in_DX);
        uVar7 = (int)uVar7 >> 1;
      }
      ovr_ovc41_textParalyzed
                ((agnt_t *)
                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + 8) >> 8),
                          CONCAT12((char)*(undefined2 *)(unaff_BP + 8),*(undefined2 *)(unaff_BP + 6)
                                  )),
                 (agnt_t *)
                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                          CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                   *(undefined2 *)(unaff_BP + -10))),uVar7);
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 10;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
      emptyFunction();
      return;
    }
    pcVar8 = ovr_agnt_statusText((agnt_t *)
                                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                          CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                                   *(undefined2 *)(unaff_BP + -10))),
                                 (char *)(unaff_BP + -0xd2));
    ovr_ovc15_usesStshRealloc((char *)CONCAT13((char)(in_DX >> 8),CONCAT12((char)in_DX,pcVar8)));
    pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),unaff_SS,(char *)"%s is immune to fire.");
    ovr_uiNotify(pcVar8,in_DX);
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\x06') {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -10) + 0x11) != '\0') {
      emptyFunction();
      return;
    }
    if ((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x40) == 0) {
      iVar5 = ovc27_rollToHitEntity
                        (CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                  CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                           *(undefined2 *)(unaff_BP + -10))),3);
      if ((char)iVar5 == '\0') {
        ovr_agnt_statusText((agnt_t *)
                            CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + 8) >> 8),
                                     CONCAT12((char)*(undefined2 *)(unaff_BP + 8),
                                              *(undefined2 *)(unaff_BP + 6))),
                            (char *)(unaff_BP + -0x122));
        pcVar8 = ovr_agnt_statusText((agnt_t *)
                                     CONCAT22(*(undefined2 *)(unaff_BP + -8),
                                              (agnt_t *)*(undefined2 *)(unaff_BP + -10)),
                                     (char *)(unaff_BP + -0xd2));
        ovr_ovc15_usesStshRealloc((char *)CONCAT13((char)(in_DX >> 8),CONCAT12((char)in_DX,pcVar8)))
        ;
        pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),unaff_SS,(char *)"%s is held by %s.");
        ovr_uiNotify(pcVar8,in_DX);
        ovr_OVC41_6a8f_01e7_entry
                  ((agnt_t *)
                   CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                            CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                     *(undefined2 *)(unaff_BP + -10))));
        puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
        *puVar1 = *puVar1 | 0x40;
        *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0x10;
        *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
        uVar6 = ovr_audio_panFromX((agnt_t *)
                                   CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                            CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                                     *(undefined2 *)(unaff_BP + -10))));
        ovr_play_sfxU(0x1b,0,uVar6);
        emptyFunction();
        return;
      }
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\a') {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -10) + 0x11) != '\0') {
      emptyFunction();
      return;
    }
    if ((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x80) == 0) {
      uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x17);
      if (*(byte *)((int)uVar2 + 0xf) < 5) {
        ovr_agnt_statusText((agnt_t *)
                            CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + 8) >> 8),
                                     CONCAT12((char)*(undefined2 *)(unaff_BP + 8),
                                              *(undefined2 *)(unaff_BP + 6))),
                            (char *)(unaff_BP + -0x122));
        pcVar8 = ovr_agnt_statusText((agnt_t *)
                                     CONCAT22(*(undefined2 *)(unaff_BP + -8),
                                              (agnt_t *)*(undefined2 *)(unaff_BP + -10)),
                                     (char *)(unaff_BP + -0xd2));
        ovr_ovc15_usesStshRealloc((char *)CONCAT13((char)(in_DX >> 8),CONCAT12((char)in_DX,pcVar8)))
        ;
        pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),unaff_SS,
                               (char *)"%s is put to sleep by %s.");
        ovr_uiNotify(pcVar8,in_DX);
        ovr_OVC41_6a8f_01e7_entry
                  ((agnt_t *)
                   CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                            CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                     *(undefined2 *)(unaff_BP + -10))));
        puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
        *puVar1 = *puVar1 | 0x80;
        uVar6 = ovr_audio_panFromX((agnt_t *)
                                   CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                            CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                                     *(undefined2 *)(unaff_BP + -10))));
        ovr_play_sfxU(0x1b,0,uVar6);
        *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xc;
        *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
        emptyFunction();
        return;
      }
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\b') {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -10) + 0x11) != '\0') {
      emptyFunction();
      return;
    }
    if ((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x100) == 0) {
      ovr_agnt_statusText((agnt_t *)
                          CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + 8) >> 8),
                                   CONCAT12((char)*(undefined2 *)(unaff_BP + 8),
                                            *(undefined2 *)(unaff_BP + 6))),
                          (char *)(unaff_BP + -0x122));
      pcVar8 = ovr_agnt_statusText((agnt_t *)
                                   CONCAT22(*(undefined2 *)(unaff_BP + -8),
                                            (agnt_t *)*(undefined2 *)(unaff_BP + -10)),
                                   (char *)(unaff_BP + -0xd2));
      ovr_ovc15_usesStshRealloc((char *)CONCAT13((char)(in_DX >> 8),CONCAT12((char)in_DX,pcVar8)));
      pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),unaff_SS,
                             (char *)"%s is entangled in a web created by %s.");
      ovr_uiNotify(pcVar8,in_DX);
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x33) =
           *(undefined1 *)((int)*(undefined4 *)(unaff_BP + 6) + 0x32);
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xd;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 5;
      puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x100;
      uVar6 = ovr_audio_panFromX((agnt_t *)
                                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                          CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                                   *(undefined2 *)(unaff_BP + -10))));
      ovr_play_sfxU(0x1b,0,uVar6);
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\t') {
    if ((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x40) != 0) {
      emptyFunction();
      return;
    }
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                         *(undefined2 *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
      ovr_agnt_statusText((agnt_t *)
                          CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + 8) >> 8),
                                   CONCAT12((char)*(undefined2 *)(unaff_BP + 8),
                                            *(undefined2 *)(unaff_BP + 6))),
                          (char *)(unaff_BP + -0x122));
      pcVar8 = ovr_agnt_statusText((agnt_t *)
                                   CONCAT22(*(undefined2 *)(unaff_BP + -8),
                                            (agnt_t *)*(undefined2 *)(unaff_BP + -10)),
                                   (char *)(unaff_BP + -0xd2));
      ovr_ovc15_usesStshRealloc((char *)CONCAT13((char)(in_DX >> 8),CONCAT12((char)in_DX,pcVar8)));
      pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),unaff_SS,(char *)"%s is held by %s.");
      ovr_uiNotify(pcVar8,in_DX);
      ovr_OVC41_6a8f_01e7_entry
                ((agnt_t *)
                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                          CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                   *(undefined2 *)(unaff_BP + -10))));
      puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x40;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0x10;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
      uVar6 = ovr_audio_panFromX((agnt_t *)
                                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                          CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                                   *(undefined2 *)(unaff_BP + -10))));
      ovr_play_sfxU(0x1b,0,uVar6);
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\v') {
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                         *(undefined2 *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
      ovr_ovc41_textParalyzed
                ((agnt_t *)
                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + 8) >> 8),
                          CONCAT12((char)*(undefined2 *)(unaff_BP + 8),*(undefined2 *)(unaff_BP + 6)
                                  )),
                 (agnt_t *)
                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                          CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                   *(undefined2 *)(unaff_BP + -10))),
                 (uint)*(byte *)((int)*(undefined4 *)(unaff_BP + -10) + 0x21));
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xb;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\f') {
    uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x17);
    if (7 < *(byte *)((int)uVar2 + 0xf)) {
      emptyFunction();
      return;
    }
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                         *(undefined2 *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
      ovr_ovc41_textParalyzed
                ((agnt_t *)
                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + 8) >> 8),
                          CONCAT12((char)*(undefined2 *)(unaff_BP + 8),*(undefined2 *)(unaff_BP + 6)
                                  )),
                 (agnt_t *)
                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                          CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                   *(undefined2 *)(unaff_BP + -10))),
                 (uint)*(byte *)((int)*(undefined4 *)(unaff_BP + -10) + 0x21));
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xb;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\r') {
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                         *(undefined2 *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
      ovr_ovc41_textParalyzed
                ((agnt_t *)
                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + 8) >> 8),
                          CONCAT12((char)*(undefined2 *)(unaff_BP + 8),*(undefined2 *)(unaff_BP + 6)
                                  )),
                 (agnt_t *)
                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                          CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                   *(undefined2 *)(unaff_BP + -10))),
                 (uint)*(byte *)((int)*(undefined4 *)(unaff_BP + -10) + 0x21));
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xb;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\x0e') {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -10) + 0x11) != '\0') {
      emptyFunction();
      return;
    }
    iVar5 = ovc27_rollToHitEntity
                      (CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                         *(undefined2 *)(unaff_BP + -10))),3);
    if ((char)iVar5 == '\0') {
      ovr_OVC41_6a8f_01e7_entry
                ((agnt_t *)
                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                          CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                   *(undefined2 *)(unaff_BP + -10))));
      puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x800;
      uVar6 = ovr_audio_panFromX((agnt_t *)
                                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                          CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                                   *(undefined2 *)(unaff_BP + -10))));
      ovr_play_sfxU(0x1b,0,uVar6);
      emptyFunction();
      return;
    }
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) != '\x0f') {
    emptyFunction();
    return;
  }
  *(undefined2 *)(unaff_BP + -4) = 0x1e;
  *(undefined2 *)(unaff_BP + -2) = 0;
  do {
    if (((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x20) == 0) &&
       (uVar7 = ovc27_rollToHitEntity
                          (CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                    CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                             *(undefined2 *)(unaff_BP + -10))),3),
       (uVar7 & 0xff) == 0)) {
      ovr_agnt_statusText((agnt_t *)
                          CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + 8) >> 8),
                                   CONCAT12((char)*(undefined2 *)(unaff_BP + 8),
                                            *(undefined2 *)(unaff_BP + 6))),
                          (char *)(unaff_BP + -0x122));
      pcVar8 = ovr_agnt_statusText((agnt_t *)
                                   CONCAT22(*(undefined2 *)(unaff_BP + -8),
                                            (agnt_t *)*(undefined2 *)(unaff_BP + -10)),
                                   (char *)(unaff_BP + -0xd2));
      ovr_ovc15_usesStshRealloc((char *)CONCAT13((char)(in_DX >> 8),CONCAT12((char)in_DX,pcVar8)));
      pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),unaff_SS,(char *)"%s is charmed by %s.");
      ovr_uiNotify(pcVar8,in_DX);
      ovr_OVC41_6a8f_01e7_entry
                ((agnt_t *)
                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                          CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                   *(undefined2 *)(unaff_BP + -10))));
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2f) =
           *(undefined1 *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2f);
      puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x20;
      uVar6 = ovr_audio_panFromX((agnt_t *)
                                 CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                          CONCAT12((char)*(undefined2 *)(unaff_BP + -8),
                                                   *(undefined2 *)(unaff_BP + -10))));
      ovr_play_sfxU(0x1b,0,uVar6);
    }
    do {
      iVar5 = ovc27_usesAgntCount((agnt_t *)
                                  CONCAT22(*(undefined2 *)(unaff_BP + 8),
                                           (agnt_t *)*(undefined2 *)(unaff_BP + 6)),0xe,
                                  *(byte *)(unaff_BP + -4),(int *)(unaff_BP + -2));
      *(uint16_t *)(unaff_BP + -8) = in_DX;
      *(int *)(unaff_BP + -10) = iVar5;
      if (*(int *)(unaff_BP + -10) == 0 && *(int *)(unaff_BP + -8) == 0) break;
    } while (*(int *)(unaff_BP + -2) == unaff_DI);
    if (*(int *)(unaff_BP + -10) != 0 || *(int *)(unaff_BP + -8) != 0) {
      uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x17);
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

int __cdecl16far ovc27_usesAgntCount(agnt_t *agnt,byte recIndex,byte maxLevel,int *cursor)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  undefined2 in_stack_0000000e;
  
  while( true ) {
    if ((int)(uint)AgntCount <= *_cursor) {
      return 0;
    }
    uVar2 = *(undefined4 *)(*_cursor * 0x34 + 0x17);
    if (((*(byte *)((int)uVar2 + 0xf) <= maxLevel) &&
        (*(uint8_t *)*(undefined4 *)(*_cursor * 0x34 + 0x1d) != ((agnt_t *)agnt)->faction)) &&
       (uVar3 = ovc27_usesRandBelow3(agnt,CONCAT22(0x222b,(uint)recIndex * 0x21),*_cursor),
       (char)uVar3 != '\0')) break;
    *_cursor = *_cursor + 1;
  }
  iVar1 = *_cursor;
  *_cursor = *_cursor + 1;
  return iVar1 * 0x34;
}



/* 5ded:1c94 */

/* Rolls to hit using the entity's level and the type record's faction ramp. */

int __cdecl16far ovc27_rollToHitEntity(uint32_t agnt,byte column)

{
  undefined4 uVar1;
  char cVar2;
  uint16_t uVar3;
  int iVar4;
  undefined2 uVar5;
  byte bStack_9;
  byte bStack_8;
  byte bStack_7;
  undefined4 uStack_6;
  
  uVar5 = (undefined2)(agnt >> 0x10);
  iVar4 = (int)agnt;
  bStack_7 = *(byte *)((int)*(undefined4 *)(iVar4 + 0x17) + 0xf);
  bStack_8 = *(byte *)((int)*(undefined4 *)(iVar4 + 0x1d) + 0x46);
  if ((bStack_8 == 0xff) && (bStack_8 = 0, *(byte *)((int)*(undefined4 *)(iVar4 + 0x1d) + 0x53) < 4)
     ) {
    bStack_7 = bStack_7 >> 1;
  }
  uStack_6 = (byte *)CONCAT22(*(undefined2 *)((int)&RampTables[0].seg + (uint)bStack_8 * 4),
                              (byte *)((far_t *)RampTables + bStack_8)->ofs);
  while ((*uStack_6 != 0xff && (*uStack_6 < bStack_7))) {
    uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + 6);
  }
  bStack_9 = ((byte *)uStack_6)[column + 1];
  if ((column == 3) && (*(char *)((int)*(undefined4 *)(iVar4 + 0x17) + 0x1a) != -1)) {
    uVar1 = *(undefined4 *)((uint)*(byte *)((int)*(undefined4 *)(iVar4 + 0x17) + 0x1a) << 2);
    cVar2 = ovr_manage_abilityModifier_2(*(byte *)((int)uVar1 + 0x2b));
    bStack_9 = bStack_9 - cVar2;
  }
  uVar3 = ovr_randBelow(0x14);
  if ((int)((uVar3 & 0xff) + 1) < (int)(char)bStack_9) {
    iVar4 = (uint)(byte)((char)bStack_9 >> 7) << 8;
  }
  else {
    iVar4 = CONCAT11((char)bStack_9 >> 7,1);
  }
  return iVar4;
}



/* 5ded:1d8e */

/* Rolls to hit using the agent's own level and type-record ramp. */

int __cdecl16far ovc27_rollToHitAgent(uint32_t agnt,byte column)

{
  undefined4 uVar1;
  char cVar2;
  uint16_t uVar3;
  int iVar4;
  undefined2 uVar5;
  byte bStack_9;
  byte bStack_8;
  byte bStack_7;
  undefined4 uStack_6;
  
  uVar5 = (undefined2)(agnt >> 0x10);
  iVar4 = (int)agnt;
  bStack_7 = *(byte *)(iVar4 + 0xf);
  bStack_8 = *(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)*(byte *)(iVar4 + 0xd) * 0x95);
  if ((bStack_8 == 0xff) &&
     (bStack_8 = 0,
     *(byte *)((int)&worldMenuLabels[0xc].seg + (uint)*(byte *)(iVar4 + 0xd) * 0x95) < 4)) {
    bStack_7 = bStack_7 >> 1;
  }
  uStack_6 = (byte *)CONCAT22(*(undefined2 *)((int)&RampTables[0].seg + (uint)bStack_8 * 4),
                              (byte *)((far_t *)RampTables + bStack_8)->ofs);
  while ((*uStack_6 != 0xff && (*uStack_6 < bStack_7))) {
    uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + 6);
  }
  bStack_9 = ((byte *)uStack_6)[column + 1];
  if ((column == 3) && (*(char *)(iVar4 + 0x1a) != -1)) {
    uVar1 = *(undefined4 *)((uint)*(byte *)(iVar4 + 0x1a) << 2);
    *(undefined1 *)((int)uVar1 + 0x2b) = 0x12;
    uVar1 = *(undefined4 *)((uint)*(byte *)(iVar4 + 0x1a) << 2);
    cVar2 = ovr_manage_abilityModifier_2(*(byte *)((int)uVar1 + 0x2b));
    bStack_9 = bStack_9 - cVar2;
  }
  uVar3 = ovr_randBelow(0x14);
  if ((int)((uVar3 & 0xff) + 1) < (int)(char)bStack_9) {
    iVar4 = (uint)(byte)((char)bStack_9 >> 7) << 8;
  }
  else {
    iVar4 = CONCAT11((char)bStack_9 >> 7,1);
  }
  return iVar4;
}



/* 5ded:1eb7 */

/* [R7] body shape: compute */

undefined2 __cdecl16far ovc27_compute3(uint32_t view,char frames)

{
  undefined2 uVar1;
  undefined2 uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  bool bVar7;
  byte bStack_6;
  uint uStack_4;
  
  uStack_4 = 0;
  while( true ) {
    iVar5 = (int)view;
    uVar6 = (undefined2)(view >> 0x10);
    if ((frames == '\0') || (*(char *)(iVar5 + 0xf) == '\0')) break;
    bVar3 = ovr_ovc15_textView(view);
    uStack_4 = uStack_4 + bVar3;
    *(char *)(iVar5 + 0xf) = *(char *)(iVar5 + 0xf) + -1;
    frames = frames + -1;
  }
  bVar7 = *(char *)(iVar5 + 0xf) == '\0';
  if (bVar7) {
    *(undefined1 *)(iVar5 + 0xf) = 1;
  }
  if (uStack_4 < *(byte *)(iVar5 + 0x32)) {
    *(char *)(iVar5 + 0x32) = *(char *)(iVar5 + 0x32) - (char)uStack_4;
  }
  else {
    *(undefined1 *)(iVar5 + 0x32) = 1;
  }
  if (uStack_4 < *(byte *)(iVar5 + 0x31)) {
    *(char *)(iVar5 + 0x31) = *(char *)(iVar5 + 0x31) - (char)uStack_4;
  }
  else {
    *(undefined1 *)(iVar5 + 0x31) = 1;
  }
  if (*(byte *)(iVar5 + 0x32) < *(byte *)(iVar5 + 0x31)) {
    *(undefined1 *)(iVar5 + 0x31) = *(undefined1 *)(iVar5 + 0x32);
  }
  bStack_6 = *(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)*(byte *)(iVar5 + 0xd) * 0x95);
  if (bStack_6 == 0xff) {
    bStack_6 = 0;
  }
  iVar4 = (uint)bStack_6 * 0x94 + (uint)*(byte *)(iVar5 + 0xf) * 4;
  uVar1 = *(undefined2 *)(iVar4 + -2);
  uVar2 = *(undefined2 *)(iVar4 + -4);
  *(undefined2 *)(iVar5 + 0x12) = uVar1;
  *(undefined2 *)(iVar5 + 0x10) = uVar2;
  return CONCAT11((char)((uint)uVar1 >> 8),bVar7);
}



/* 5ded:1fe1 */

/* [R4] calls ovr_play_sfxU */

uint __cdecl16far ovc27_usesPlay_sfxU(uint16_t ptrOfs,uint16_t ptrSeg,agnt_t *agnt,uint8_t frames)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  uint16_t unk;
  agnt_t *paVar5;
  int iVar6;
  undefined2 uVar7;
  
  uVar7 = (undefined2)((ulong)agnt >> 0x10);
  paVar5 = (agnt_t *)agnt;
  uVar1 = *(undefined2 *)((int)&paVar5->entity + 2);
  iVar2 = *(int *)&paVar5->entity;
  uVar3 = ovc27_compute3(CONCAT22(uVar1,iVar2),frames);
  if ((char)uVar3 == '\0') {
    for (iVar6 = 0; iVar6 < (int)(uint)AgntCount; iVar6 = iVar6 + 1) {
      if (*(uint16_t *)(iVar6 * 0x34 + 0x1b) == paVar5->owner) {
        if (*(byte *)(iVar2 + 0x32) < *(byte *)(iVar6 * 0x34 + 0x22)) {
          *(undefined1 *)(iVar6 * 0x34 + 0x22) = *(undefined1 *)(iVar2 + 0x32);
        }
        if (*(byte *)(iVar6 * 0x34 + 0x22) < *(byte *)(iVar6 * 0x34 + 0x21)) {
          *(undefined1 *)(iVar6 * 0x34 + 0x21) = *(undefined1 *)(iVar6 * 0x34 + 0x22);
        }
      }
    }
    unk = ovr_audio_panFromX(agnt);
    ovr_play_sfxU(0x1c,0,unk);
    uVar4 = CONCAT11((char)(unk >> 8),1);
  }
  else {
    uVar4 = ovr_ovc41_settleAgentCombat
                      ((agnt_t *)CONCAT13((char)(ptrSeg >> 8),CONCAT12((char)ptrSeg,ptrOfs)),agnt);
    uVar4 = uVar4 & 0xff00;
  }
  return uVar4;
}



/* 5ded:218c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* duplicate name, disambiguated by address order */

void switchD_6000_3cd8_caseD_0_3(void)

{
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + '\x01';
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


