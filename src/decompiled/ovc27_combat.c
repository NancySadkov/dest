/*
 * ovc27_combat.c - recovered from STRONG.EXE
 * memory block: OVC27_combat.c
 * range: 5ded:0000 - 5ded:22af
 * functions: 21
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
  undefined2 uVar7;
  uint16_t unaff_SS;
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
  if (x1 < *rectOfs) {
    x1 = *rectOfs;
  }
  uVar7 = (undefined2)((ulong)rectOfs >> 0x10);
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
    iStack_e = ovr_ovc07_signum();
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
    iStack_e = ovr_ovc07_signum();
    iStack_10 = x2 - x1 >> 1;
    bStack_3 = rectSeg;
    for (iStack_8 = x1; iStack_8 <= x2; iStack_8 = iStack_8 + 1) {
      bStack_3 = bStack_3 + 1 & 0xf;
      iVar2 = y1 + -1;
      puVar3 = (uint8_t *)(iVar2 * 0x140 + iStack_8);
      if ((((pbVar7->y <= iVar2) && (iVar2 <= pbVar7->h)) &&
          (*(int *)(&plane0 + (uint)bStack_3 * 2) != 0)) &&
         (uVar4 = ovr_randBelow(), (uVar4 & 0xff) == 0)) {
        *puVar3 = (&plane0)[(uint)bStack_3 * 2];
      }
      if (((pbVar7->y <= y1) && (y1 <= pbVar7->h)) &&
         ((*(int *)(&plane1 + (uint)bStack_3 * 2) != 0 &&
          (uVar4 = ovr_randBelow(), (uVar4 & 0xff) == 0)))) {
        puVar3[0x140] = (&plane1)[(uint)bStack_3 * 2];
      }
      if (((pbVar7->y <= y1 + 1) && (y1 + 1 <= pbVar7->h)) &&
         ((*(int *)(&plane2 + (uint)bStack_3 * 2) != 0 &&
          (uVar4 = ovr_randBelow(), (uVar4 & 0xff) == 0)))) {
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

uint __cdecl16far ovc27_compute1(agnt_t *agnt,int param,...)

{
  undefined4 uVar1;
  uint in_AX;
  byte bVar3;
  undefined1 uVar4;
  uint uVar2;
  int in_stack_00000004;
  
  if ((*(uint *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x3c) & 2) != 0) {
    uVar1 = *(undefined4 *)((*(uint16_t *)((uint8_t *)&(agnt) + 2)) * 0x34 + 0x1d);
    bVar3 = (byte)((uint)((*(uint16_t *)((uint8_t *)&(agnt) + 2)) * 0x34) >> 8);
    if (((*(uint *)((int)uVar1 + 0x3e) & 0x10) != 0) &&
       (*(byte *)((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0xf) < 3)) {
      return (uint)bVar3 << 8;
    }
    return CONCAT11(bVar3,1);
  }
  if ((*(uint *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x3c) & 1) != 0) {
    in_AX = (*(uint16_t *)((uint8_t *)&(agnt) + 2)) * 0x34;
    uVar4 = (undefined1)(in_AX >> 8);
    if (((*(uint *)((int)*(undefined4 *)(in_AX + 0x1d) + 0x3c) & 4) != 0) &&
       (3 < *(byte *)((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0xf))) {
      return CONCAT11(uVar4,1);
    }
    if (9 < *(byte *)((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0xf)) {
      return CONCAT11(uVar4,1);
    }
  }
  if (((*(uint *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x3c) & 0x800) == 0) ||
     (in_AX = (*(uint16_t *)((uint8_t *)&(agnt) + 2)) * 0x34, (*(uint *)((int)*(undefined4 *)(in_AX + 0x1d) + 0x3c) & 4) == 0)) {
    uVar2 = in_AX & 0xff00;
  }
  else {
    uVar2 = CONCAT11((char)(in_AX >> 8),1);
  }
  return uVar2;
}



/* 5ded:04cd */

/* Rolls 1..40 against the owner's stat and returns whether the roll succeeds. */

int __cdecl16far ovc27_rollAgainstStat(agnt_t *agnt,byte mode,...)

{
  uint16_t uVar1;
  uint uVar2;
  byte bVar4;
  int iVar3;
  int in_stack_00000004;
  uint n;
  
  bVar4 = *(byte *)((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0x1a);
  if (bVar4 == 0xff) {
    n = 0xff06;
  }
  else {
    n = CONCAT11(bVar4,*(undefined1 *)
                        ((int)*(undefined4 *)((uint)bVar4 << 2) + (uint)(*(uint8_t *)((uint8_t *)&(agnt) + 2)) + 0x29));
  }
  uVar1 = ovr_randBelow(n,0x28);
  uVar2 = (uVar1 & 0xff) + 1;
  bVar4 = (byte)(uVar2 >> 8);
  if ((n & 0xff) < uVar2) {
    iVar3 = (uint)bVar4 << 8;
  }
  else {
    iVar3 = CONCAT11(bVar4,1);
  }
  return iVar3;
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
                     (uVar4 = ovr_randBelow(), *(byte *)(iVar6 + 0xd) <= (byte)uVar4)) {
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
  uint16_t unaff_BP;
  
  bVar3 = (byte)((uint)in_AX >> 8);
  if (level < threshold) {
    iVar1 = (uint)bVar3 << 8;
  }
  else if (level == threshold) {
    uVar2 = ovr_randBelow(unaff_BP,8);
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

uint __cdecl16far ovc27_compute2(agnt_t *agnt,int param,...)

{
  undefined4 uVar1;
  uint in_AX;
  uint uVar2;
  undefined2 uVar3;
  byte unaff_SI;
  agnt_t *in_stack_00000004;
  byte bStack_3;
  
  if ((((agntG_t *)in_stack_00000004->gdata)->flags & 2) == 0) {
    if ((((agntG_t *)in_stack_00000004->gdata)->flags & 1) == 0) {
      if (((((((agntG_t *)in_stack_00000004->gdata)->flags & 0x800) != 0) &&
           (in_AX = ovc27_rollAgainstStat
                              ((agnt_t *)(ulong)CONCAT12(5,(agnt_t *)agnt),unaff_SI,
                               in_stack_00000004), (char)in_AX != '\0')) &&
          (in_AX = (*(uint16_t *)((uint8_t *)&(agnt) + 2)) * 0x34, (*(uint *)(in_AX + 0x2b) & 0x7e0) == 0)) &&
         ((in_AX = (*(uint16_t *)((uint8_t *)&(agnt) + 2)) * 0x34,
          (*(uint *)((int)*(undefined4 *)(in_AX + 0x1d) + 0x40) & 0x80) == 0 &&
          (in_AX = (*(uint16_t *)((uint8_t *)&(agnt) + 2)) * 0x34,
          (*(uint *)((int)*(undefined4 *)(in_AX + 0x1d) + 0x3c) & 4) != 0)))) {
        return CONCAT11((char)(in_AX >> 8),1);
      }
      uVar2 = in_AX & 0xff00;
    }
    else {
      uVar3 = ovc27_usesRandBelow3
                        ((agnt_t *)CONCAT22((agnt_t *)agnt,in_stack_00000004),0x222b0108,(*(uint16_t *)((uint8_t *)&(agnt) + 2)))
      ;
      if ((char)uVar3 == '\0') {
        uVar2 = ovc27_usesRandBelow3
                          ((agnt_t *)CONCAT22((agnt_t *)agnt,in_stack_00000004),0x222b014a,
                           (*(uint16_t *)((uint8_t *)&(agnt) + 2)));
        if ((char)uVar2 == '\0') {
          return uVar2 & 0xff00;
        }
        bStack_3 = 10;
      }
      else {
        bStack_3 = 4;
      }
      uVar2 = ovc27_usesRandBelow4((((entity_t *)in_stack_00000004->entity)->base).level,bStack_3);
      if ((uVar2 & 0xff) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = ovc27_rollAgainstStat
                          ((agnt_t *)(ulong)CONCAT12(2,(agnt_t *)agnt),unaff_SI,in_stack_00000004);
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
    uVar2 = ovc27_usesRandBelow4((((entity_t *)in_stack_00000004->entity)->base).level,1);
    if ((uVar2 & 0xff) == 0) {
      uVar2 = 0;
    }
    else {
      uVar1 = *(undefined4 *)((*(uint16_t *)((uint8_t *)&(agnt) + 2)) * 0x34 + 0x1d);
      if (((*(uint *)((int)uVar1 + 0x3e) & 0x10) == 0) ||
         (2 < (((entity_t *)in_stack_00000004->entity)->base).level)) {
        uVar2 = ovc27_rollAgainstStat
                          ((agnt_t *)(ulong)CONCAT12(1,(agnt_t *)agnt),unaff_SI,in_stack_00000004);
        if ((uVar2 & 0xff) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
      else {
        uVar2 = (*(uint16_t *)((uint8_t *)&(agnt) + 2)) * 0x34 & 0xff00;
      }
    }
  }
  return uVar2;
}



/* 5ded:0960 */

/* WARNING: Variable defined which should be unmapped: indexMap */
/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc27_usesRandBelow5(agnt_t *agnt)

{
  uint in_AX;
  uint uVar1;
  undefined2 uVar2;
  uint16_t uVar3;
  undefined2 uVar4;
  uint unaff_SS;
  uint8_t indexMap;
  byte bStack_4;
  byte bStack_3;
  
  uVar4 = (undefined2)((ulong)agnt >> 0x10);
  if (((agnt_t *)agnt)->target == 0xff) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    _fmemset((void *)(ulong)unaff_SS,0xf,_indexMap);
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
      uVar3 = ovr_randBelow(_indexMap,(uint)bStack_3);
      uVar1 = CONCAT11((char)((uint)(&indexMap + (uVar3 & 0xff)) >> 8),(&indexMap)[uVar3 & 0xff]);
    }
  }
  return uVar1;
}



/* 5ded:0a05 */

/* WARNING: Variable defined which should be unmapped: text */
/* Formats the "%s casts a %s spell %s %s." notice. */

uint __cdecl16far ovc27_spellNotice(int agntIndex,...)

{
  int iVar1;
  undefined2 uVar2;
  byte bVar3;
  uint16_t uVar4;
  uint uVar5;
  uint8_t *puVar6;
  char *pcVar7;
  int iVar8;
  undefined1 *puVar9;
  char *arg1;
  int *piVar10;
  char *unaff_SS;
  int in_stack_00000004;
  undefined2 uVar11;
  uint8_t text;
  byte bStack_13;
  int iStack_12;
  undefined2 uStack_10;
  int iStack_e;
  int iStack_c;
  int iStack_a;
  undefined2 uStack_8;
  agnt_t *paStack_6;
  agnt_t *paStack_4;
  
  paStack_6 = (agnt_t *)(in_stack_00000004 * 0x34);
  paStack_4 = (agnt_t *)((int)&AgntAnms[0x75].halfWidth + 1);
  bVar3 = (byte)((uint)paStack_6 >> 8);
  if ((((agntG_t *)paStack_6->gdata)->flags & 0x803) == 0) {
    return (uint)bVar3 << 8;
  }
  if (paStack_6->animFrame == 0xff) {
    iStack_a = (uint)paStack_6->target * 0x34;
    uStack_8 = 0x1726;
    uVar11 = uStack_8;
    uStack_8 = 0x1726;
    uVar2 = uVar11;
    if (((((((agntG_t *)paStack_6->gdata)->flags & 0x1000) != 0) &&
         (uVar2 = uStack_8, (*(uint *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x3e) & 0x10) == 0))
        && ((uStack_8 = uVar11, (*(uint *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x3e) & 8) == 0
            || (bVar3 = ovr_agnt_compute9((agnt_t *)
                                          CONCAT22(_text,(agnt_t *)
                                                         ((int)&AgntAnms[0x75].halfWidth + 1)),
                                          (char)paStack_6), uVar2 = uStack_8, '\0' < (char)bVar3))))
       && (uVar4 = ovr_randBelow(_text,2), uVar2 = uStack_8, (uVar4 & 0xff) == 0)) {
      return 0;
    }
    uStack_8 = uVar2;
    uVar5 = ovc27_usesRandBelow5((agnt_t *)CONCAT22(paStack_4,paStack_6));
    bStack_13 = (byte)uVar5;
    uVar5 = uVar5 & 0xff;
    if (uVar5 == 0) {
      ovr_agnt_usesAnimFrame((agnt_t *)CONCAT22(_text,paStack_4),(char)paStack_6);
      uVar5 = uVar5 & 0xff00;
    }
    else {
      arg1 = (char *)"n/s gate" + 4;
      uVar11 = GSavedBlitSeg;
      puVar6 = ovr_ovc15_usesStshRealloc();
      pcVar7 = ovr_stsprintf((char *)CONCAT22(0x5ba4,unaff_SS),
                             (char *)CONCAT22(puVar6,(char *)"puppetmaker" + 3),arg1,&text);
      ovr_uiNotify((char *)CONCAT22(uVar11,arg1),_text,pcVar7);
      paStack_6->variant = bStack_13;
      if (*(char *)((uint)bStack_13 * 0x21 + -0x17) == '9') {
        iVar8 = ovr_audio_panFromX((agnt_t *)CONCAT22(_text,paStack_4),(char)paStack_6);
        bVar3 = 0;
        uVar4 = ovr_randBelow(0,2);
        ovr_play_sfxU(bVar3,iVar8,_text,CONCAT11((char)(uVar4 >> 8),(char)uVar4 + '9'));
      }
      else {
        iVar8 = ovr_audio_panFromX((agnt_t *)CONCAT22(_text,paStack_4),(char)paStack_6);
        puVar9 = (undefined1 *)((uint)bStack_13 * 0x21 + -0x17);
        ovr_play_sfxU(0,iVar8,_text,CONCAT11((char)((uint)puVar9 >> 8),*puVar9));
      }
      if (*(char *)((uint)bStack_13 * 0x21 + -0x16) == '\0') {
        paStack_6->animFrame = 0xf5;
        uVar5 = 1;
      }
      else {
        uVar11 = *(undefined2 *)((int)&paStack_6->frames + 2);
        _iStack_12 = CONCAT22(uVar11,*(int *)&paStack_6->frames);
        piVar10 = (int *)(*(int *)&paStack_6->frames + (uint)paStack_6->frameIndex * 4);
        iVar8 = piVar10[1];
        iVar1 = *piVar10;
        _iStack_e = CONCAT22(iVar8,iVar1);
        if (iVar1 == 0 && iVar8 == 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(_text,0x42);
        }
        paStack_6->animFrame = 0x0;
        *(char *)&paStack_6->destY = *(char *)(iVar1 + 0x15) + (char)paStack_6->screenY;
        if (paStack_6->level == 0x0) {
          uVar4 = *(int *)(iVar1 + 0x13) + paStack_6->screenX;
          paStack_6->destX = uVar4;
        }
        else {
          uVar4 = paStack_6->screenX - *(int *)(iVar1 + 0x13);
          paStack_6->destX = uVar4;
        }
        *(uint8_t *)((int)&paStack_6->destY + 1) = paStack_6->level;
        uVar5 = CONCAT11((char)(uVar4 >> 8),1);
      }
    }
    return uVar5;
  }
  return (uint)bVar3 << 8;
}



/* 5ded:0cc2 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc27_usesBlitGfxRect(int agntIndex,brect_t *rect,uint16_t type,...)

{
  uint8_t type_00;
  undefined2 uVar1;
  uint16_t uVar2;
  agnt_t *paVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 uVar8;
  int y1;
  stg_tmp_t *psVar7;
  uint16_t uVar9;
  uint16_t *puVar10;
  undefined1 unaff_DI;
  int in_stack_00000004;
  far_t gfx;
  far_t gfx_00;
  int iStack_e;
  undefined2 uStack_c;
  
  paVar3 = (agnt_t *)(in_stack_00000004 * 0x34);
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
    puVar10 = (uint16_t *)(*(int *)(iVar4 + 0x13) + (uint)*(byte *)(iVar4 + 0x12) * 4);
    uVar2 = puVar10[1];
    uVar9 = *puVar10;
    if ((*(int *)(iVar4 + 0x28) != 0) || (*(int *)(iVar4 + 0x26) != 0)) {
      if (paVar3->variant == 0x1) {
        if (paVar3->animFrame < 0xfc) {
          ovc27_intelAttackingNotice
                    (uVar5,*(int *)(iStack_e + 0x15) + paVar3->screenY,*(int *)(iVar4 + 0x26),
                     *(int *)(iVar4 + 0x28) - (*(int *)(uVar9 + 0xd) >> 1),
                     (int *)CONCAT22((brect_t *)rect,agntIndex));
        }
        uVar5 = paVar3->animFrame & 3;
        gfx.seg = *(uint16_t *)(iVar4 + 0x26);
        gfx.ofs = ((undefined2 *)&boltSpritesSeg)[uVar5 * 2];
        ovr_blitGfxRect(gfx,*(int *)(iVar4 + 0x28) - (*(int *)(uVar9 + 0xd) >> 1),agntIndex,
                        (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,(bool)unaff_DI,
                        ((undefined2 *)&boltSpritesOfs)[uVar5 * 2],0);
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
        uVar8 = (undefined1)((uint)iVar6 >> 8);
        if (paVar3->animFrame < 0xfb) {
          y1 = *(int *)(iStack_e + 0x15) + paVar3->screenY;
          ovc27_usesRandBelow(uVar5,y1,iVar6,*(int *)(iVar4 + 0x28) + -6,
                              (brect_t *)CONCAT22((brect_t *)rect,agntIndex),paVar3->animFrame << 1)
          ;
          uVar8 = (undefined1)((uint)y1 >> 8);
        }
        if (0xf8 < paVar3->animFrame) {
          psVar7 = ovr_stash_usesStExit
                             ((stg_tmp_t *)
                              CONCAT13(uVar8,CONCAT12(paVar3->animFrame + 0x7,
                                                      *(undefined2 *)(SprProjectiles.ofs + 0x8e))),
                              *(undefined2 *)(SprProjectiles.ofs + 0x8c));
          type_00 = (uint8_t)paVar3->flags32;
          gfx_00.seg = *(uint16_t *)(iVar4 + 0x26);
          gfx_00.ofs = uVar9;
          ovr_blitGfxRect(gfx_00,*(int16_t *)(iVar4 + 0x28),agntIndex,
                          (brect_t *)CONCAT22(0x10,(brect_t *)rect),type_00,(bool)unaff_DI,
                          psVar7->cmap + 6,type_00);
        }
      }
      paVar3->animFrame = paVar3->animFrame + 0x1;
      paVar3->health = 0x2;
      if (paVar3->animFrame == 0xff) {
        ovr_ovc41_resolveSpecialAttack((agnt_t *)CONCAT22(0x1726,paVar3),(uint)paVar3->target);
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

/* WARNING: Variable defined which should be unmapped: text */
/* Notifies "%s takes half damage from spells." for the qualifying types and levels. */

uint __cdecl16far ovc27_spellHalfDamage(agnt_t *agnt)

{
  uint in_AX;
  uint8_t *puVar1;
  char *pcVar2;
  uint uVar3;
  char *in_DX;
  agnt_t *paVar5;
  undefined2 uVar6;
  char *unaff_SS;
  uint8_t text;
  uint8_t msg;
  undefined1 uVar4;
  
  uVar6 = (undefined2)((ulong)agnt >> 0x10);
  paVar5 = (agnt_t *)agnt;
  if (((((agntG_t *)paVar5->gdata)->shortName[3] == '\x04') &&
      (0xf < (((entity_t *)paVar5->entity)->base).level)) ||
     ((((agntG_t *)paVar5->gdata)->shortName[3] == '\x06' &&
      (8 < (((entity_t *)paVar5->entity)->base).level)))) {
    ovr_agnt_statusText();
    puVar1 = ovr_ovc15_usesStshRealloc();
    pcVar2 = ovr_stsprintf((char *)CONCAT22(0x5bbf,unaff_SS),
                           (char *)CONCAT22(puVar1,(char *)"puppetmaker" + 3),in_DX,&msg);
    uVar4 = (undefined1)((uint)pcVar2 >> 8);
    ovr_uiNotify();
    uVar3 = CONCAT11(uVar4,1);
  }
  else {
    uVar3 = in_AX & 0xff00;
  }
  return uVar3;
}



/* 5ded:105e */

/* WARNING: Variable defined which should be unmapped: text */
/* Notifies "%s takes half damage from dragon breath." for the qualifying types. */

uint __cdecl16far ovc27_breathHalfDamage(agnt_t *agnt,...)

{
  uint in_AX;
  uint8_t *puVar1;
  char *pcVar2;
  uint uVar3;
  char *in_DX;
  char *unaff_SS;
  int in_stack_00000004;
  uint8_t text;
  uint8_t msg;
  undefined1 uVar4;
  
  if (((*(char *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x46) == '\x05') &&
      (0xd < *(byte *)((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0xf))) ||
     ((*(char *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x46) == '\x06' &&
      (0xe < *(byte *)((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0xf))))) {
    ovr_agnt_statusText();
    puVar1 = ovr_ovc15_usesStshRealloc();
    pcVar2 = ovr_stsprintf((char *)CONCAT22(0x5be1,unaff_SS),
                           (char *)CONCAT22(puVar1,(char *)"puppetmaker" + 3),in_DX,&msg);
    uVar4 = (undefined1)((uint)pcVar2 >> 8);
    ovr_uiNotify();
    uVar3 = CONCAT11(uVar4,1);
  }
  else {
    uVar3 = in_AX & 0xff00;
  }
  return uVar3;
}



/* 5ded:10ea */

/* [R2] string "%s takes half damage from lightning." */

void __cdecl16far ovc27_textTakesHalfDamage3(agnt_t *agnt,uint16_t agntIndex,...)

{
  long lVar1;
  uint16_t uVar2;
  uint uVar3;
  int iVar4;
  uint8_t *puVar5;
  char *arg1;
  uint16_t unaff_DI;
  char *unaff_SS;
  int in_stack_00000004;
  char sides;
  undefined1 uVar6;
  uint8_t text1;
  uint8_t text2;
  uint8_t msg;
  int iStack_c;
  undefined2 uStack_a;
  int iStack_8;
  
  sides = (char)unaff_DI;
  uVar6 = (undefined1)(unaff_DI >> 8);
  lVar1 = (long)(*(uint16_t *)((uint8_t *)&(agnt) + 2)) * 0x34;
  arg1 = (char *)((ulong)lVar1 >> 0x10);
  iStack_c = (int)lVar1;
  uStack_a = 0x1726;
  if (*(char *)(in_stack_00000004 + 0x2e) == '\x01') {
    if ((*(uint *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x40) & 1) == 0) {
      ovr_manage_rollDice('\x06',sides,
                          *(undefined1 *)((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0xf));
      ovc27_spellHalfDamage
                ((agnt_t *)CONCAT13((char)((uint)uStack_a >> 8),CONCAT12((char)uStack_a,iStack_c)));
    }
    else {
      ovc27_breathHalfDamage((agnt_t *)CONCAT13(uVar6,CONCAT12(sides,0x1726)),(char)lVar1);
    }
    if ((*(uint *)((int)*(undefined4 *)(iStack_c + 0x1d) + 0x40) & 1) != 0) {
      ovr_agnt_statusText();
      ovr_ovc15_usesStshRealloc();
      ovr_stsprintf();
      ovr_uiNotify();
      emptyFunction();
      return;
    }
    ovc27_rollToHitEntity();
    ovr_ovc41_textParalyzed();
    *(undefined1 *)(iStack_c + 0x30) = 0xb;
    *(undefined1 *)(iStack_c + 0x31) = 0;
    emptyFunction();
    return;
  }
  if (*(char *)(in_stack_00000004 + 0x2e) == '\x02') {
    iStack_8 = (*(byte *)((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0xf) / 5) * 2 + 1;
    ovr_manage_rollDice('\x06',sides,(undefined1)iStack_8);
    ovc27_spellHalfDamage
              ((agnt_t *)CONCAT13((char)((uint)uStack_a >> 8),CONCAT12((char)uStack_a,iStack_c)));
    ovr_ovc41_textParalyzed();
    *(undefined1 *)(iStack_c + 0x30) = 0xb;
    *(undefined1 *)(iStack_c + 0x31) = 0;
    emptyFunction();
    return;
  }
  if (*(char *)(in_stack_00000004 + 0x2e) != '\n') {
    if ((*(char *)(in_stack_00000004 + 0x2e) != '\x03') &&
       (*(char *)(in_stack_00000004 + 0x2e) != '\x05')) {
      ovc27_textTakesHalfDamage4();
      return;
    }
    if ((*(uint *)(iStack_c + 0x2b) & 0x20) != 0) {
      emptyFunction();
      return;
    }
    iVar4 = ovc27_rollToHitEntity();
    if ((char)iVar4 != '\0') {
      emptyFunction();
      return;
    }
    ovr_agnt_statusText();
    ovr_agnt_statusText();
    puVar5 = ovr_ovc15_usesStshRealloc();
    ovr_stsprintf((char *)CONCAT22(0x5c2f,unaff_SS),
                  (char *)CONCAT22(puVar5,(char *)"puppetmaker" + 3),arg1,&msg);
    ovr_uiNotify();
    *(undefined1 *)(iStack_c + 0x2f) = *(undefined1 *)(in_stack_00000004 + 0x2f);
    ovr_OVC41_6a8f_01e7_entry((agnt_t *)CONCAT13(uVar6,CONCAT12(sides,uStack_a)),(char)iStack_c);
    *(uint *)(iStack_c + 0x2b) = *(uint *)(iStack_c + 0x2b) | 0x20;
    ovr_audio_panFromX((agnt_t *)CONCAT13(uVar6,CONCAT12(sides,uStack_a)),(char)iStack_c);
    ovr_play_sfxU();
    emptyFunction();
    return;
  }
  if ((*(uint *)(iStack_c + 0x2b) & 0x420) != 0) {
    emptyFunction();
    return;
  }
  uVar2 = ovr_randBelow(unaff_DI,3);
  if (((uVar2 & 0xff) == 0) && (uVar3 = ovc27_rollToHitEntity(), (uVar3 & 0xff) == 0)) {
    ovr_agnt_statusText();
    ovr_agnt_statusText();
    puVar5 = ovr_ovc15_usesStshRealloc();
    ovr_stsprintf((char *)CONCAT22(0x5c2f,unaff_SS),
                  (char *)CONCAT22(puVar5,(char *)"puppetmaker" + 3),arg1,&msg);
    ovr_uiNotify();
    ovr_OVC41_6a8f_01e7_entry((agnt_t *)CONCAT13(uVar6,CONCAT12(sides,uStack_a)),(char)iStack_c);
    *(undefined1 *)(iStack_c + 0x2f) = *(undefined1 *)(in_stack_00000004 + 0x2f);
    *(uint *)(iStack_c + 0x2b) = *(uint *)(iStack_c + 0x2b) | 0x20;
    ovr_audio_panFromX((agnt_t *)CONCAT13(uVar6,CONCAT12(sides,uStack_a)),(char)iStack_c);
    ovr_play_sfxU();
    emptyFunction();
    return;
  }
  ovr_agnt_statusText();
  ovr_agnt_statusText();
  puVar5 = ovr_ovc15_usesStshRealloc();
  ovr_stsprintf((char *)CONCAT22(0x5c44,unaff_SS),(char *)CONCAT22(puVar5,(char *)"puppetmaker" + 3)
                ,arg1,&msg);
  ovr_uiNotify();
  *(uint *)(iStack_c + 0x2b) = *(uint *)(iStack_c + 0x2b) | 0x400;
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
  undefined1 uVar6;
  int iVar3;
  uint uVar4;
  uint8_t *puVar5;
  char *in_DX;
  int unaff_BP;
  int unaff_DI;
  char *unaff_SS;
  char in_stack_00000000;
  
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\x04') {
    iVar3 = ovr_audio_panFromX();
    uVar6 = (undefined1)((uint)iVar3 >> 8);
    ovr_play_sfxU();
    uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x1d);
    if ((*(uint *)((int)uVar2 + 0x40) & 0x20) != 0) {
      ovr_agnt_statusText();
      ovr_ovc15_usesStshRealloc();
      ovr_stsprintf();
      ovr_uiNotify();
      emptyFunction();
      return;
    }
    ovr_ovc28_usesBDADailyTimeCounter();
    uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 6) + 0x17);
    ovr_manage_rollDice('\x06',in_stack_00000000,CONCAT11(uVar6,*(undefined1 *)((int)uVar2 + 0xf)),6
                       );
    ovc27_rollToHitEntity();
    ovc27_spellHalfDamage
              ((agnt_t *)
               CONCAT22(*(undefined2 *)(unaff_BP + -8),(agnt_t *)*(undefined2 *)(unaff_BP + -10)));
    uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x1d);
    if ((*(uint *)((int)uVar2 + 0x3e) & 0x200) != 0) {
      ovr_agnt_statusText();
      ovr_ovc15_usesStshRealloc();
      ovr_stsprintf();
      ovr_uiNotify();
    }
    ovr_ovc41_textParalyzed();
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 10;
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\x06') {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -10) + 0x11) != '\0') {
      emptyFunction();
      return;
    }
    if ((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x40) != 0) {
      emptyFunction();
      return;
    }
    iVar3 = ovc27_rollToHitEntity();
    if ((char)iVar3 != '\0') {
      emptyFunction();
      return;
    }
    ovr_agnt_statusText();
    ovr_agnt_statusText();
    puVar5 = ovr_ovc15_usesStshRealloc();
    ovr_stsprintf((char *)CONCAT22(0x5c90,unaff_SS),
                  (char *)CONCAT22(puVar5,(char *)"puppetmaker" + 3),in_DX,unaff_BP + -0x82);
    ovr_uiNotify();
    ovr_OVC41_6a8f_01e7_entry();
    puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
    *puVar1 = *puVar1 | 0x40;
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0x10;
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
    ovr_audio_panFromX();
    ovr_play_sfxU();
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\a') {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -10) + 0x11) != '\0') {
      emptyFunction();
      return;
    }
    if ((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x80) != 0) {
      emptyFunction();
      return;
    }
    uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x17);
    if (4 < *(byte *)((int)uVar2 + 0xf)) {
      emptyFunction();
      return;
    }
    ovr_agnt_statusText();
    ovr_agnt_statusText();
    puVar5 = ovr_ovc15_usesStshRealloc();
    ovr_stsprintf((char *)CONCAT22(0x5ca2,unaff_SS),
                  (char *)CONCAT22(puVar5,(char *)"puppetmaker" + 3),in_DX,unaff_BP + -0x82);
    ovr_uiNotify();
    ovr_OVC41_6a8f_01e7_entry();
    puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
    *puVar1 = *puVar1 | 0x80;
    ovr_audio_panFromX();
    ovr_play_sfxU();
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xc;
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\b') {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -10) + 0x11) != '\0') {
      emptyFunction();
      return;
    }
    if ((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x100) != 0) {
      emptyFunction();
      return;
    }
    ovr_agnt_statusText();
    ovr_agnt_statusText();
    puVar5 = ovr_ovc15_usesStshRealloc();
    ovr_stsprintf((char *)CONCAT22(0x5cbc,unaff_SS),
                  (char *)CONCAT22(puVar5,(char *)"puppetmaker" + 3),in_DX,unaff_BP + -0x82);
    ovr_uiNotify();
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x33) =
         *(undefined1 *)((int)*(undefined4 *)(unaff_BP + 6) + 0x32);
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xd;
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 5;
    puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
    *puVar1 = *puVar1 | 0x100;
    ovr_audio_panFromX();
    ovr_play_sfxU();
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\t') {
    if ((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x40) != 0) {
      emptyFunction();
      return;
    }
    iVar3 = ovc27_rollToHitEntity();
    if ((char)iVar3 != '\0') {
      emptyFunction();
      return;
    }
    ovr_agnt_statusText();
    ovr_agnt_statusText();
    puVar5 = ovr_ovc15_usesStshRealloc();
    ovr_stsprintf((char *)CONCAT22(0x5c90,unaff_SS),
                  (char *)CONCAT22(puVar5,(char *)"puppetmaker" + 3),in_DX,unaff_BP + -0x82);
    ovr_uiNotify();
    ovr_OVC41_6a8f_01e7_entry();
    puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
    *puVar1 = *puVar1 | 0x40;
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0x10;
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
    ovr_audio_panFromX();
    ovr_play_sfxU();
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\v') {
    iVar3 = ovc27_rollToHitEntity();
    if ((char)iVar3 != '\0') {
      emptyFunction();
      return;
    }
    ovr_ovc41_textParalyzed();
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xb;
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\f') {
    uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x17);
    if (7 < *(byte *)((int)uVar2 + 0xf)) {
      emptyFunction();
      return;
    }
    iVar3 = ovc27_rollToHitEntity();
    if ((char)iVar3 != '\0') {
      emptyFunction();
      return;
    }
    ovr_ovc41_textParalyzed();
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xb;
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\r') {
    iVar3 = ovc27_rollToHitEntity();
    if ((char)iVar3 != '\0') {
      emptyFunction();
      return;
    }
    ovr_ovc41_textParalyzed();
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xb;
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
    emptyFunction();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\x0e') {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -10) + 0x11) != '\0') {
      emptyFunction();
      return;
    }
    iVar3 = ovc27_rollToHitEntity();
    if ((char)iVar3 != '\0') {
      emptyFunction();
      return;
    }
    ovr_OVC41_6a8f_01e7_entry();
    puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
    *puVar1 = *puVar1 | 0x800;
    ovr_audio_panFromX();
    ovr_play_sfxU();
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
       (uVar4 = ovc27_rollToHitEntity(), (uVar4 & 0xff) == 0)) {
      ovr_agnt_statusText();
      ovr_agnt_statusText();
      puVar5 = ovr_ovc15_usesStshRealloc();
      ovr_stsprintf((char *)CONCAT22(0x5c2f,unaff_SS),
                    (char *)CONCAT22(puVar5,(char *)"puppetmaker" + 3),in_DX,unaff_BP + -0x82);
      ovr_uiNotify();
      ovr_OVC41_6a8f_01e7_entry();
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2f) =
           *(undefined1 *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2f);
      puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x20;
      ovr_audio_panFromX();
      ovr_play_sfxU();
    }
    do {
      iVar3 = ovc27_usesAgntCount((agnt_t *)
                                  CONCAT22(*(undefined2 *)(unaff_BP + 8),
                                           (agnt_t *)*(undefined2 *)(unaff_BP + 6)),0xe,
                                  *(byte *)(unaff_BP + -4),
                                  (int *)CONCAT22(unaff_SS,(int *)(unaff_BP + -2)));
      *(undefined2 *)(unaff_BP + -8) = in_DX;
      *(int *)(unaff_BP + -10) = iVar3;
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
  
  while( true ) {
    if ((int)(uint)AgntCount <= *cursor) {
      return 0;
    }
    uVar2 = *(undefined4 *)(*cursor * 0x34 + 0x17);
    if (((*(byte *)((int)uVar2 + 0xf) <= maxLevel) &&
        (*(uint8_t *)*(undefined4 *)(*cursor * 0x34 + 0x1d) != ((agnt_t *)agnt)->faction)) &&
       (uVar3 = ovc27_usesRandBelow3(agnt,CONCAT22(0x222b,(uint)recIndex * 0x21),*cursor),
       (char)uVar3 != '\0')) break;
    *cursor = *cursor + 1;
  }
  iVar1 = *cursor;
  *cursor = *cursor + 1;
  return iVar1 * 0x34;
}



/* 5ded:1c94 */

/* Rolls to hit using the entity's level and the type record's faction ramp. */

int __cdecl16far ovc27_rollToHitEntity(uint32_t agnt,byte column,...)

{
  undefined4 uVar1;
  char cVar2;
  uint16_t uVar3;
  byte bVar5;
  int iVar4;
  int in_stack_00000004;
  undefined1 in_stack_0000fff6;
  uint16_t n;
  byte bStack_8;
  byte bStack_7;
  undefined4 uStack_6;
  
  bStack_7 = *(byte *)((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0xf);
  bStack_8 = *(byte *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x46);
  if ((bStack_8 == 0xff) &&
     (bStack_8 = 0, *(byte *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x53) < 4)) {
    bStack_7 = bStack_7 >> 1;
  }
  uStack_6 = (byte *)CONCAT22(*(undefined2 *)((int)&RampTables[0].seg + (uint)bStack_8 * 4),
                              (byte *)((far_t *)RampTables + bStack_8)->ofs);
  while ((*uStack_6 != 0xff && (*uStack_6 < bStack_7))) {
    uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + 6);
  }
  n = CONCAT11(((byte *)uStack_6)[(*(uint8_t *)((uint8_t *)&(agnt) + 2)) + 1],in_stack_0000fff6);
  if (((*(uint8_t *)((uint8_t *)&(agnt) + 2)) == 3) && (*(char *)((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0x1a) != -1))
  {
    uVar1 = *(undefined4 *)
             ((uint)*(byte *)((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0x1a) << 2);
    cVar2 = ovr_manage_abilityModifier(*(byte *)((int)uVar1 + 0x2b));
    n = CONCAT11((char)(n >> 8) - cVar2,(char)n);
  }
  uVar3 = ovr_randBelow(n,0x14);
  cVar2 = (char)(n >> 8);
  bVar5 = cVar2 >> 7;
  if ((int)((uVar3 & 0xff) + 1) < (int)cVar2) {
    iVar4 = (uint)bVar5 << 8;
  }
  else {
    iVar4 = CONCAT11(bVar5,1);
  }
  return iVar4;
}



/* 5ded:1d8e */

/* Rolls to hit using the agent's own level and type-record ramp. */

int __cdecl16far ovc27_rollToHitAgent(uint32_t agnt,byte column,...)

{
  undefined4 uVar1;
  char cVar2;
  uint16_t uVar3;
  byte bVar5;
  int iVar4;
  int in_stack_00000004;
  undefined1 in_stack_0000fff6;
  uint16_t n;
  byte bStack_8;
  byte bStack_7;
  undefined4 uStack_6;
  
  bStack_7 = *(byte *)(in_stack_00000004 + 0xf);
  bStack_8 = *(byte *)((int)&worldMenuLabels[9].ofs + 1 +
                      (uint)*(byte *)(in_stack_00000004 + 0xd) * 0x95);
  if ((bStack_8 == 0xff) &&
     (bStack_8 = 0,
     *(byte *)((int)&worldMenuLabels[0xc].seg + (uint)*(byte *)(in_stack_00000004 + 0xd) * 0x95) < 4
     )) {
    bStack_7 = bStack_7 >> 1;
  }
  uStack_6 = (byte *)CONCAT22(*(undefined2 *)((int)&RampTables[0].seg + (uint)bStack_8 * 4),
                              (byte *)((far_t *)RampTables + bStack_8)->ofs);
  while ((*uStack_6 != 0xff && (*uStack_6 < bStack_7))) {
    uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + 6);
  }
  n = CONCAT11(((byte *)uStack_6)[(*(uint8_t *)((uint8_t *)&(agnt) + 2)) + 1],in_stack_0000fff6);
  if (((*(uint8_t *)((uint8_t *)&(agnt) + 2)) == 3) && (*(char *)(in_stack_00000004 + 0x1a) != -1)) {
    uVar1 = *(undefined4 *)((uint)*(byte *)(in_stack_00000004 + 0x1a) << 2);
    *(undefined1 *)((int)uVar1 + 0x2b) = 0x12;
    uVar1 = *(undefined4 *)((uint)*(byte *)(in_stack_00000004 + 0x1a) << 2);
    cVar2 = ovr_manage_abilityModifier(*(byte *)((int)uVar1 + 0x2b));
    n = CONCAT11((char)(n >> 8) - cVar2,(char)n);
  }
  uVar3 = ovr_randBelow(n,0x14);
  cVar2 = (char)(n >> 8);
  bVar5 = cVar2 >> 7;
  if ((int)((uVar3 & 0xff) + 1) < (int)cVar2) {
    iVar4 = (uint)bVar5 << 8;
  }
  else {
    iVar4 = CONCAT11(bVar5,1);
  }
  return iVar4;
}



/* 5ded:1eb7 */

/* [R7] body shape: compute */

undefined2 __cdecl16far ovc27_compute3(uint32_t view,char frames,...)

{
  undefined2 uVar1;
  undefined2 uVar2;
  byte bVar3;
  int iVar4;
  bool bVar5;
  int in_stack_00000004;
  byte bStack_6;
  uint uStack_4;
  
  uStack_4 = 0;
  while (((*(uint8_t *)((uint8_t *)&(view) + 2)) != '\0' && (*(char *)(in_stack_00000004 + 0xf) != '\0'))) {
    bVar3 = ovr_ovc15_textView(in_stack_00000004,(undefined2)view);
    uStack_4 = uStack_4 + bVar3;
    *(char *)(in_stack_00000004 + 0xf) = *(char *)(in_stack_00000004 + 0xf) + -1;
    (*(uint8_t *)((uint8_t *)&(view) + 2)) = (*(uint8_t *)((uint8_t *)&(view) + 2)) + -1;
  }
  bVar5 = *(char *)(in_stack_00000004 + 0xf) == '\0';
  if (bVar5) {
    *(undefined1 *)(in_stack_00000004 + 0xf) = 1;
  }
  if (uStack_4 < *(byte *)(in_stack_00000004 + 0x32)) {
    *(char *)(in_stack_00000004 + 0x32) = *(char *)(in_stack_00000004 + 0x32) - (char)uStack_4;
  }
  else {
    *(undefined1 *)(in_stack_00000004 + 0x32) = 1;
  }
  if (uStack_4 < *(byte *)(in_stack_00000004 + 0x31)) {
    *(char *)(in_stack_00000004 + 0x31) = *(char *)(in_stack_00000004 + 0x31) - (char)uStack_4;
  }
  else {
    *(undefined1 *)(in_stack_00000004 + 0x31) = 1;
  }
  if (*(byte *)(in_stack_00000004 + 0x32) < *(byte *)(in_stack_00000004 + 0x31)) {
    *(undefined1 *)(in_stack_00000004 + 0x31) = *(undefined1 *)(in_stack_00000004 + 0x32);
  }
  bStack_6 = *(byte *)((int)&worldMenuLabels[9].ofs + 1 +
                      (uint)*(byte *)(in_stack_00000004 + 0xd) * 0x95);
  if (bStack_6 == 0xff) {
    bStack_6 = 0;
  }
  iVar4 = (uint)bStack_6 * 0x94 + (uint)*(byte *)(in_stack_00000004 + 0xf) * 4;
  uVar1 = *(undefined2 *)(iVar4 + -2);
  uVar2 = *(undefined2 *)(iVar4 + -4);
  *(undefined2 *)(in_stack_00000004 + 0x12) = uVar1;
  *(undefined2 *)(in_stack_00000004 + 0x10) = uVar2;
  return CONCAT11((char)((uint)uVar1 >> 8),bVar5);
}



/* 5ded:1fe1 */

/* [R4] calls ovr_play_sfxU */

uint __cdecl16far
ovc27_usesPlay_sfxU(uint16_t ptrOfs,uint16_t ptrSeg,agnt_t *agnt,uint8_t frames,...)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_SI;
  int iVar5;
  undefined2 in_stack_00000004;
  char frames_00;
  undefined1 uVar6;
  
  frames_00 = (char)unaff_SI;
  uVar6 = (undefined1)((uint)unaff_SI >> 8);
  uVar1 = *(undefined2 *)(ptrSeg + 0x19);
  iVar4 = *(int *)(ptrSeg + 0x17);
  uVar2 = ovc27_compute3(CONCAT22(CONCAT11((char)((uint)uVar1 >> 8),(*(uint8_t *)((uint8_t *)&(agnt) + 2))),uVar1),frames_00,
                         iVar4);
  if ((char)uVar2 == '\0') {
    for (iVar5 = 0; iVar5 < (int)(uint)AgntCount; iVar5 = iVar5 + 1) {
      if (*(int *)(iVar5 * 0x34 + 0x1b) == *(int *)(ptrSeg + 0x1b)) {
        if (*(byte *)(iVar4 + 0x32) < *(byte *)(iVar5 * 0x34 + 0x22)) {
          *(undefined1 *)(iVar5 * 0x34 + 0x22) = *(undefined1 *)(iVar4 + 0x32);
        }
        if (*(byte *)(iVar5 * 0x34 + 0x22) < *(byte *)(iVar5 * 0x34 + 0x21)) {
          *(undefined1 *)(iVar5 * 0x34 + 0x21) = *(undefined1 *)(iVar5 * 0x34 + 0x22);
        }
      }
    }
    iVar4 = ovr_audio_panFromX((agnt_t *)CONCAT13(uVar6,CONCAT12(frames_00,(agnt_t *)agnt)),
                               (char)ptrSeg);
    ovr_play_sfxU(0,iVar4,0x1c);
    uVar3 = CONCAT11((char)((uint)iVar4 >> 8),1);
  }
  else {
    uVar3 = ovr_ovc41_settleAgentCombat
                      ((agnt_t *)CONCAT13((char)(ptrSeg >> 8),CONCAT12((char)ptrSeg,ptrOfs)),
                       (agnt_t *)CONCAT13(uVar6,CONCAT12(frames_00,(agnt_t *)agnt)),
                       in_stack_00000004);
    uVar3 = uVar3 & 0xff00;
  }
  return uVar3;
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


