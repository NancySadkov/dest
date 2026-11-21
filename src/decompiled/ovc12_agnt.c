/*
 * ovc12_agnt.c - recovered from STRONG.EXE
 * memory block: OVC12_agnt.c
 * range: 3b1d:0000 - 3b1d:1f8f
 * functions: 34
 */
#include "recovered.h"


/* 3b1d:0000 */

/* Returns whether any agent, pending flag or playing animation is active. */

bool __cdecl16far agnt_isAnimating(void)

{
  bool bVar1;
  
  if (((AgntCount == '\0') && (cursorRecordFound == '\0')) && (GAnimPlaying == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}



/* 3b1d:0032 */

/* [R7] body shape: compute */

undefined2 __cdecl16far agnt_compute1(int y)

{
  if (y < 0xc) {
    y = 0xc;
  }
  if (0xde < y) {
    y = 0xde;
  }
  return *(undefined2 *)((y + -0xc) * 2 + 0x34c);
}



/* 3b1d:005e */

/* Clamps an x coordinate to 0..0xd2. */

int __cdecl16far agnt_clampX(int x,...)

{
  if (x < 0) {
    x = 0;
  }
  if (0xd2 < x) {
    x = 0xd2;
  }
  return x;
}



/* 3b1d:0079 */

/* [R7] body shape: compute */

undefined1 __cdecl16far agnt_compute3(agnt_t *agnt)

{
  undefined1 uVar1;
  int iVar2;
  agnt_t *agnt_00;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)agnt >> 0x10);
  agnt_00 = (agnt_t *)agnt;
  if (((((int)agnt_00->y < 0x15) || (agnt_00->moveState == 0x1)) && ((int)agnt->x < 0xd3)) &&
     (-1 < (int)agnt->x)) {
    iVar2 = ovr_ovc49_usesStExit(agnt_00,uVar3);
    uVar1 = (undefined1)iVar2;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 3b1d:00b7 */

/* [R7] body shape: compute */

bool __cdecl16far agnt_compute4(char *flag,...)

{
  return *flag != '\0';
}



/* 3b1d:00ce */

/* Computes the screen extents of the agent's current animation frame. */

undefined1 __cdecl16far agnt_computeFrameExtents(agnt_t *agnt,uint8_t *result,...)

{
  uint8_t uVar1;
  undefined2 uVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  undefined2 in_stack_0000000a;
  char cStack_e;
  char cStack_d;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  
  if ((int)agnt->y < 0x15) {
    uVar1 = agnt->faction;
    uVar2 = *(undefined2 *)((int)&agnt->frames + 2);
    piVar6 = (int *)(*(int *)&agnt->frames + (uint)agnt->frameIndex * 4);
    iVar5 = piVar6[1];
    iVar3 = *piVar6;
    iStack_6 = (int)agnt->y >> 1;
    if (iStack_6 < 0) {
      iStack_6 = 0;
    }
    if (9 < iStack_6) {
      iStack_6 = 9;
    }
    if (agnt->level == 0x0) {
      cStack_d = '\x01';
      iStack_a = ((int)((int)(*(((agntG_t *)agnt->gdata)->extents + 2))[0] + *(int *)(iVar3 + 0x17)
                       + ((agnt_t *)CONCAT22((uint8_t *)result,agnt))->x) >> 1) + -1;
      iStack_c = iStack_a +
                 ((int)((agntG_t *)agnt->gdata)->extents[2][1] -
                  (int)(*(((agntG_t *)agnt->gdata)->extents + 2))[0] >> 1);
    }
    else {
      cStack_d = -1;
      iStack_a = ((int)((-*(int *)(iVar3 + 0x17) -
                        (int)(*(((agntG_t *)agnt->gdata)->extents + 2))[0]) +
                       ((agnt_t *)CONCAT22((uint8_t *)result,agnt))->x) >> 1) + 1;
      iStack_c = iStack_a -
                 ((int)((agntG_t *)agnt->gdata)->extents[2][1] -
                  (int)(*(((agntG_t *)agnt->gdata)->extents + 2))[0] >> 1);
    }
    if (iStack_a < 0) {
      iStack_a = 0;
    }
    if (iStack_c < 0) {
      iStack_c = 0;
    }
    if (0x68 < iStack_a) {
      iStack_a = 0x68;
    }
    if (0x68 < iStack_c) {
      iStack_c = 0x68;
    }
    while( true ) {
      for (iStack_8 = 0; iStack_8 <= (int)((agntG_t *)agnt->gdata)->extents[2][2] >> 1;
          iStack_8 = iStack_8 + 1) {
        cStack_e = -1;
        while (((cStack_e < '\x02' && (iStack_8 != 0)) || ((cStack_e == -1 && (iStack_8 == 0))))) {
          iVar5 = iStack_6 + iStack_8 * cStack_e;
          if ((-1 < iVar5) && (iVar5 < 10)) {
            if ((*(char *)(iVar5 * 0x69 + iStack_a + 0x8fa) != '\0') &&
               (((*(byte *)(iVar5 * 0x69 + iStack_a + 0x8fa) <= AgntCount &&
                 (*(uint8_t *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x8fa) * 0x34 + -5) !=
                  uVar1)) &&
                (*(char *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x8fa) * 0x34 + -0x10) == '\0')
                ))) {
              *(char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(result) + 2))) =
                   *(char *)(iVar5 * 0x69 + iStack_a + 0x8fa);
              bVar4 = agnt_compute4((char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(result) + 2))));
              if (bVar4) {
                return *(char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(result) + 2)));
              }
            }
            if (((*(char *)(iVar5 * 0x69 + iStack_a + 0x4e0) != '\0') &&
                (*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) <= AgntCount)) &&
               ((*(uint8_t *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) * 0x34 + -5) != uVar1
                && (*(char *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x10) ==
                    '\0')))) {
              *(char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(result) + 2))) =
                   *(char *)(iVar5 * 0x69 + iStack_a + 0x4e0);
              return *(char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(result) + 2)));
            }
          }
          cStack_e = cStack_e + '\x02';
        }
      }
      if (iStack_a == iStack_c) break;
      iStack_a = iStack_a + cStack_d;
    }
    *(char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(result) + 2))) = '\0';
  }
  else {
    *(char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(result) + 2))) = '\0';
  }
  return 0;
}



/* 3b1d:0426 */

/* WARNING: Type propagation algorithm not settling */
/* [R6] touches strengthMax, frameIndex */

undefined1 __cdecl16far agnt_usesStrengthMax(agnt_t *agnt,byte *out,...)

{
  uint8_t uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined1 uVar6;
  int iVar7;
  int *piVar8;
  undefined2 in_stack_0000000a;
  char in_stack_0000000c;
  char cStack_e;
  char cStack_d;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  
  if (((agnt->strength < agnt->strengthMax) && ((agnt->flags & 0x820) == 0)) &&
     ((((agntG_t *)agnt->gdata)->flags & 0x20) == 0)) {
    *(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) = in_stack_0000000c + 1;
    uVar6 = 1;
  }
  else {
    uVar1 = agnt->faction;
    uVar2 = *(undefined2 *)((int)&agnt->frames + 2);
    piVar8 = (int *)(*(int *)&agnt->frames + (uint)agnt->frameIndex * 4);
    iVar7 = piVar8[1];
    iVar3 = *piVar8;
    iStack_6 = (int)agnt->y >> 1;
    if (iStack_6 < 0) {
      iStack_6 = 0;
    }
    if (9 < iStack_6) {
      iStack_6 = 9;
    }
    if (agnt->level == 0x0) {
      cStack_d = '\x01';
      iStack_a = ((int)((int)(*((agntG_t *)agnt->gdata)->extents)[0] + *(int *)(iVar3 + 0x17) +
                       ((agnt_t *)CONCAT22((byte *)out,agnt))->x) >> 1) + -1;
      iStack_c = iStack_a +
                 ((int)((agntG_t *)agnt->gdata)->extents[0][1] -
                  (int)(*((agntG_t *)agnt->gdata)->extents)[0] >> 1);
    }
    else {
      cStack_d = -1;
      iStack_a = ((int)((-*(int *)(iVar3 + 0x17) - (int)(*((agntG_t *)agnt->gdata)->extents)[0]) +
                       ((agnt_t *)CONCAT22((byte *)out,agnt))->x) >> 1) + 1;
      iStack_c = iStack_a -
                 ((int)((agntG_t *)agnt->gdata)->extents[0][1] -
                  (int)(*((agntG_t *)agnt->gdata)->extents)[0] >> 1);
    }
    if (iStack_a < 0) {
      iStack_a = 0;
    }
    if (iStack_c < 0) {
      iStack_c = 0;
    }
    if (0x68 < iStack_a) {
      iStack_a = 0x68;
    }
    if (0x68 < iStack_c) {
      iStack_c = 0x68;
    }
    for (; iStack_a != iStack_c; iStack_a = iStack_a + cStack_d) {
      for (iStack_8 = 0; iStack_8 <= (int)((agntG_t *)agnt->gdata)->extents[0][2] >> 1;
          iStack_8 = iStack_8 + 1) {
        cStack_e = -1;
        while (((cStack_e < '\x02' && (iStack_8 != 0)) || ((cStack_e == -1 && (iStack_8 == 0))))) {
          iVar7 = iStack_6 + iStack_8 * cStack_e;
          if ((-1 < iVar7) && (iVar7 < 10)) {
            if ((*(char *)(iVar7 * 0x69 + iStack_a + 0x8fa) != '\0') &&
               ((((*(byte *)(iVar7 * 0x69 + iStack_a + 0x8fa) <= AgntCount &&
                  (*(byte *)((uint)*(byte *)(iVar7 * 0x69 + iStack_a + 0x8fa) * 0x34 + -0x13) <
                   *(byte *)((uint)*(byte *)(iVar7 * 0x69 + iStack_a + 0x8fa) * 0x34 + -0x12))) &&
                 (*(uint8_t *)((uint)*(byte *)(iVar7 * 0x69 + iStack_a + 0x8fa) * 0x34 + -5) ==
                  uVar1)) &&
                ((*(uint8_t *)
                   *(undefined4 *)((uint)*(byte *)(iVar7 * 0x69 + iStack_a + 0x8fa) * 0x34 + -0x17)
                  == uVar1 &&
                 (uVar4 = *(undefined4 *)
                           ((uint)*(byte *)(iVar7 * 0x69 + iStack_a + 0x8fa) * 0x34 + -0x17),
                 (*(uint *)((int)uVar4 + 0x3c) & 0x20) == 0)))))) {
              *(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) =
                   *(byte *)(iVar7 * 0x69 + iStack_a + 0x8fa);
              bVar5 = agnt_compute4((char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))));
              if ((bVar5) &&
                 ((*(byte *)((uint)*(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) * 0x34 + -0x13) <
                   *(byte *)((uint)*(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) * 0x34 + -0x12) &&
                  ((*(uint *)((uint)*(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) * 0x34 + -9) &
                   0x820) == 0)))) {
                return *(undefined1 *)(iVar7 * 0x69 + iStack_a + 0x8fa);
              }
            }
            if ((((*(char *)(iVar7 * 0x69 + iStack_a + 0x4e0) != '\0') &&
                 (*(byte *)(iVar7 * 0x69 + iStack_a + 0x4e0) <= AgntCount)) &&
                (*(byte *)((uint)*(byte *)(iVar7 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x13) <
                 *(byte *)((uint)*(byte *)(iVar7 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x12))) &&
               (((*(uint8_t *)((uint)*(byte *)(iVar7 * 0x69 + iStack_a + 0x4e0) * 0x34 + -5) ==
                  uVar1 && (*(uint8_t *)
                             *(undefined4 *)
                              ((uint)*(byte *)(iVar7 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x17) ==
                            uVar1)) &&
                (uVar4 = *(undefined4 *)
                          ((uint)*(byte *)(iVar7 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x17),
                (*(uint *)((int)uVar4 + 0x3c) & 0x20) == 0)))) {
              *(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) =
                   *(byte *)(iVar7 * 0x69 + iStack_a + 0x4e0);
              return *(undefined1 *)(iVar7 * 0x69 + iStack_a + 0x4e0);
            }
          }
          cStack_e = cStack_e + '\x02';
        }
      }
    }
    *(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) = 0;
    uVar6 = 0;
  }
  return uVar6;
}



/* 3b1d:093e */

/* [R6] touches AgntCount */

bool __cdecl16far
agnt_usesAgntCount2(agnt_t *agnt,uint16_t *xDir,uint16_t *yDir,uint16_t *distance,...)

{
  uint8_t uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  undefined2 in_stack_00000012;
  byte bStack_4;
  
  uVar1 = agnt->faction;
  *(uint *)CONCAT22(in_stack_00000012,(*(uint16_t *)((uint8_t *)&(distance) + 2))) = 0xffff;
  bStack_4 = 0;
  while( true ) {
    if (AgntCount <= bStack_4) break;
    if ((*(uint8_t *)((uint)bStack_4 * 0x34 + 0x2f) != uVar1) &&
       (uVar2 = *(int *)((uint)bStack_4 * 0x34) - agnt->x, uVar5 = (int)uVar2 >> 0xf,
       uVar3 = *(int *)((uint)bStack_4 * 0x34 + 2) - agnt->y, uVar6 = (int)uVar3 >> 0xf,
       uVar2 = ((uVar2 ^ uVar5) - uVar5) + ((uVar3 ^ uVar6) - uVar6),
       uVar2 < *(uint *)CONCAT22(in_stack_00000012,(*(uint16_t *)((uint8_t *)&(distance) + 2))))) {
      *(uint *)CONCAT22(in_stack_00000012,(*(uint16_t *)((uint8_t *)&(distance) + 2))) = uVar2;
      uVar4 = ovr_ovc07_signum(*(int *)((uint)bStack_4 * 0x34) -
                               ((agnt_t *)CONCAT22((uint16_t *)xDir,agnt))->x);
      *(undefined2 *)CONCAT22((uint16_t *)yDir,(*(uint16_t *)((uint8_t *)&(xDir) + 2))) = uVar4;
      uVar4 = ovr_ovc07_signum(*(int *)((uint)bStack_4 * 0x34 + 2) - agnt->y);
      *(undefined2 *)CONCAT22((uint16_t *)distance,(*(uint16_t *)((uint8_t *)&(yDir) + 2))) = uVar4;
    }
    bStack_4 = bStack_4 + 1;
  }
  return *(uint *)CONCAT22(in_stack_00000012,(*(uint16_t *)((uint8_t *)&(distance) + 2))) != 0xffff;
}



/* 3b1d:0a53 */

/* [R6] touches animFrame */

void __cdecl16far agnt_usesAnimFrame(agnt_t *agnt,...)

{
  undefined2 in_stack_00000006;
  
  agnt->animFrame = 0xff;
  agnt->target = 0xff;
  agnt->health = 0x0;
  agnt->gindex = 0x0;
  agnt->flags = agnt->flags & 0xfff5;
  agnt->variant = 0x0;
  animBranchCode = 0;
  return;
}



/* 3b1d:0a8d */

/* [R7] body shape: compute */

void __cdecl16far agnt_compute5(agnt_t *agnt)

{
  ((agnt_t *)agnt)->health = 0x0;
  animBranchCode = 0;
  return;
}



/* 3b1d:0a9f */

/* Advances the agent's animation frame unless bit 2 of its type record (agntG_t+0) is set. */

void __cdecl16far agnt_advanceAnimFrame(agnt_t *agnt,...)

{
  undefined2 in_stack_00000006;
  
  if ((((agntG_t *)agnt->gdata)->flags3 & 4) == 0) {
    agnt_usesAnimFrame(agnt,in_stack_00000006);
  }
  return;
}



/* 3b1d:0ac0 */

/* Builds the agent's status text from its flags (charmed / diseased / held / paralyzed). */

char * __cdecl16far agnt_statusText(agnt_t *agnt,char *text,...)

{
  char *pcVar1;
  agntG_t *paVar2;
  undefined2 uVar3;
  char *in_stack_0000000a;
  
  if ((agnt->flags & 0x20) == 0) {
    if ((agnt->flags & 4) == 0) {
      if ((agnt->flags & 0x800) == 0) {
        if ((*(uint *)((int)&(((entity_t *)agnt->entity)->base).frames + 1) & 1) == 0) {
          if ((agnt->flags & 0x200) == 0) {
            if ((agnt->flags & 0x80) == 0) {
              if ((agnt->flags & 0x40) == 0) {
                    /* WARNING: Load size is inaccurate */
                pcVar1 = ((agntG_t *)agnt->gdata)->name;
              }
              else {
                uVar3 = (undefined2)((ulong)agnt->gdata >> 0x10);
                paVar2 = (agntG_t *)agnt->gdata;
                pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x83c,in_stack_0000000a),
                                       (char *)CONCAT22(*(undefined2 *)&paVar2->name,
                                                        (char *)0x26510),
                                       *(undefined2 *)((int)&paVar2->name + 2));
              }
            }
            else {
              uVar3 = (undefined2)((ulong)agnt->gdata >> 0x10);
              paVar2 = (agntG_t *)agnt->gdata;
              pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x830,in_stack_0000000a),
                                     (char *)CONCAT22(*(undefined2 *)&paVar2->name,
                                                      (char *)0x26510),
                                     *(undefined2 *)((int)&paVar2->name + 2));
            }
          }
          else {
            uVar3 = (undefined2)((ulong)agnt->gdata >> 0x10);
            paVar2 = (agntG_t *)agnt->gdata;
            pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x823,in_stack_0000000a),
                                   (char *)CONCAT22(*(undefined2 *)&paVar2->name,
                                                    (char *)0x26510),
                                   *(undefined2 *)((int)&paVar2->name + 2));
          }
        }
        else {
          uVar3 = (undefined2)((ulong)agnt->gdata >> 0x10);
          paVar2 = (agntG_t *)agnt->gdata;
          pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x817,in_stack_0000000a),
                                 (char *)CONCAT22(*(undefined2 *)&paVar2->name,
                                                  (char *)0x26510),
                                 *(undefined2 *)((int)&paVar2->name + 2));
        }
      }
      else {
        uVar3 = (undefined2)((ulong)agnt->gdata >> 0x10);
        paVar2 = (agntG_t *)agnt->gdata;
        pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x80d,in_stack_0000000a),
                               (char *)CONCAT22(*(undefined2 *)&paVar2->name,
                                                (char *)0x26510),
                               *(undefined2 *)((int)&paVar2->name + 2));
      }
    }
    else {
      uVar3 = (undefined2)((ulong)agnt->gdata >> 0x10);
      paVar2 = (agntG_t *)agnt->gdata;
      pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x803,in_stack_0000000a),
                             (char *)CONCAT22(*(undefined2 *)&paVar2->name,(char *)0x26510
                                             ),*(undefined2 *)((int)&paVar2->name + 2));
    }
  }
  else {
    uVar3 = (undefined2)((ulong)agnt->gdata >> 0x10);
    paVar2 = (agntG_t *)agnt->gdata;
    pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x7f8,in_stack_0000000a),
                           (char *)CONCAT22(*(undefined2 *)&paVar2->name,(char *)0x26510),
                           *(undefined2 *)((int)&paVar2->name + 2));
  }
  return pcVar1;
}



/* 3b1d:0c1e */

/* Returns the ability modifier of a party sheet's stat (same thresholds as manage_abilityModifier).
    */

undefined2 __cdecl16far agnt_abilityModifier(byte partyIndex,byte abilityIndex,...)

{
  byte bVar1;
  undefined2 uVar2;
  
  bVar1 = ((char_sheet_t *)(((uint)partyIndex << 2) + (uint)abilityIndex))->stats[0];
  if (bVar1 < 4) {
    uVar2 = 0xfd;
  }
  else if (bVar1 < 6) {
    uVar2 = 0xfe;
  }
  else if (bVar1 < 9) {
    uVar2 = 0xff;
  }
  else if (bVar1 < 0xd) {
    uVar2 = 0;
  }
  else if (bVar1 < 0x10) {
    uVar2 = 1;
  }
  else if (bVar1 < 0x12) {
    uVar2 = 2;
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}



/* 3b1d:0c7c */

/* [R7] body shape: compute */

byte __cdecl16far agnt_compute8(agnt_t *agnt,...)

{
  byte bVar1;
  undefined2 in_stack_00000006;
  
  bVar1 = (byte)agnt[1].y % 6;
  if (3 < bVar1) {
    bVar1 = bVar1 - 6;
  }
  return bVar1;
}



/* 3b1d:0c9f */

/* [R7] body shape: compute */

byte __cdecl16far agnt_compute9(agnt_t *agnt,...)

{
  byte bVar1;
  undefined2 in_stack_00000006;
  
  bVar1 = ((entity_t *)agnt->entity)->dir % 6;
  if (3 < bVar1) {
    bVar1 = bVar1 - 6;
  }
  return bVar1;
}



/* 3b1d:0cc6 */

/* [R7] body shape: compute */

byte __cdecl16far agnt_compute10(agnt_t *agnt,...)

{
  byte bVar1;
  undefined2 in_stack_00000006;
  
  bVar1 = (byte)(((ulong)(byte)agnt[1].y / 6) % 6);
  if (4 < bVar1) {
    bVar1 = bVar1 - 6;
  }
  return bVar1;
}



/* 3b1d:0cef */

/* [R7] body shape: compute */

byte __cdecl16far agnt_compute11(agnt_t *agnt,...)

{
  byte bVar1;
  undefined2 in_stack_00000006;
  
  bVar1 = (byte)(((ulong)((entity_t *)agnt->entity)->dir / 6) % 6);
  if (4 < bVar1) {
    bVar1 = bVar1 - 6;
  }
  return bVar1;
}



/* 3b1d:0d1c */

/* [R6] touches animFrame */

undefined1 __cdecl16far agnt_usesAnimFrame2(agnt_t *agnt,...)

{
  undefined1 uVar1;
  undefined2 in_stack_00000006;
  
  if (agnt->animFrame == 0xff) {
    if ((char)agnt->health < '\x02') {
      uVar1 = 1;
    }
    else if (agnt->health == 0x4) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 3b1d:0d4d */

/* [R7] body shape: compute */

uint __cdecl16far agnt_compute12(agnt_t *a,agnt_t *b,...)

{
  uint uVar1;
  undefined2 in_stack_0000000a;
  
  uVar1 = ((agnt_t *)CONCAT22((agnt_t *)b,a))->x;
  if ((int)uVar1 < *(int *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(b) + 2)))) {
    if (*(char *)((int)(*(uint16_t *)((uint8_t *)&(b) + 2)) + 0xf) != '\0') {
      return CONCAT11((char)(uVar1 >> 8),1);
    }
  }
  else {
    uVar1 = (uint)*(char *)((int)(*(uint16_t *)((uint8_t *)&(b) + 2)) + 0xf);
    if (uVar1 == 0) {
      return CONCAT11(*(char *)((int)(*(uint16_t *)((uint8_t *)&(b) + 2)) + 0xf) >> 7,1);
    }
  }
  return uVar1 & 0xff00;
}



/* 3b1d:0d82 */

/* [R4] calls ovr_stExit */

void __cdecl16far agnt_usesStExit(agnt_t *agnt,anm_t *anim,stg_tmp_t *sprite,...)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  undefined2 in_stack_0000000e;
  uint uStack_10;
  
  iVar3 = (uint)agnt->target * 0x34;
  piVar7 = (int *)(*(int *)(iVar3 + 0x13) + (uint)*(byte *)(iVar3 + 0x12) * 4);
  iVar1 = piVar7[1];
  iVar2 = *piVar7;
  if (iVar2 == 0 && iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x12);
  }
  uVar4 = *(int *)(iVar3 + 0x26) - agnt->destX;
  uStack_10 = (*(int *)(iVar3 + 0x28) - (uint)(byte)agnt->destY) - (*(int *)(iVar2 + 0xd) >> 1);
  if (((int)((uVar4 ^ (int)uVar4 >> 0xf) - ((int)uVar4 >> 0xf)) < 4) &&
     ((int)((uStack_10 ^ (int)uStack_10 >> 0xf) - ((int)uStack_10 >> 0xf)) < 4)) {
    ovr_ovc41_resolveSpecialAttack((agnt_t *)CONCAT22((anm_t *)anim,agnt),(uint)agnt->target);
    animBranchCode = 3;
    agnt_usesAnimFrame(agnt,(anm_t *)anim);
  }
  else {
    if (-uStack_10 == *(int *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0x11) || -*(int *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0x11) < (int)uStack_10)
    {
      if (*(int *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0x11) < (int)uStack_10) {
        uStack_10 = *(uint *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0x11);
      }
    }
    else {
      uStack_10 = -*(int *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0x11);
    }
    if (*(char *)((*(uint16_t *)((uint8_t *)&(sprite) + 2)) + 5) != '\0') {
      *(char *)&agnt->destY = (char)agnt->destY + (char)uStack_10;
    }
    if (*(int *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0xf) < (int)uVar4) {
      uVar4 = *(uint *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0xf);
    }
    else if (-uVar4 != *(int *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0xf) && (int)uVar4 <= -*(int *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0xf)) {
      uVar4 = -*(int *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0xf);
    }
    if (((*(byte *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0x1c) & 4) == 0) &&
       (((*(int *)(iVar3 + 0x28) - (uint)(byte)agnt->destY != *(int *)(iVar2 + 0xd) >> 1 ||
         ((*(char *)((int)&agnt->destY + 1) == '\0' && ((int)uVar4 < 0)))) ||
        ((*(char *)((int)&agnt->destY + 1) != '\0' && (0 < (int)uVar4)))))) {
      if (*(char *)((int)&agnt->destY + 1) == '\0') {
        uVar4 = *(uint *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0xf);
      }
      else {
        uVar4 = -*(int *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0xf);
      }
    }
    if (*(char *)((*(uint16_t *)((uint8_t *)&(sprite) + 2)) + 5) != '\0') {
      agnt->destX = agnt->destX + uVar4;
    }
    uVar4 = *(int *)(iVar3 + 0x26) - agnt->destX;
    uVar5 = (*(int *)(iVar3 + 0x28) - (uint)(byte)agnt->destY) - (*(int *)(iVar2 + 0xd) >> 1);
    uVar6 = (int)uVar4 >> 0xf;
    if (((int)((uVar4 ^ uVar6) - uVar6) < 4) &&
       (uVar4 = (int)uVar5 >> 0xf, (int)((uVar5 ^ uVar4) - uVar4) < 4)) {
      ovr_ovc41_resolveSpecialAttack((agnt_t *)CONCAT22((anm_t *)anim,agnt),(uint)agnt->target);
      animBranchCode = 5;
      agnt_usesAnimFrame(agnt,(anm_t *)anim);
    }
    else if (((int)agnt->destX < -0xe) || (0xe0 < (int)agnt->destX)) {
      animBranchCode = 4;
      agnt_usesAnimFrame(agnt,(anm_t *)anim);
    }
    else {
      agnt->animFrame = agnt->animFrame + 0x1;
      if (*(byte *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0x1b) <= agnt->animFrame) {
        if (*(char *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0x1a) == -1) {
          agnt_usesAnimFrame(agnt,(anm_t *)anim);
          animBranchCode = 6;
        }
        else {
          agnt->animFrame = *(uint8_t *)((*(uint16_t *)((uint8_t *)&(anim) + 2)) + 0x1a);
        }
      }
    }
  }
  return;
}



/* 3b1d:1035 */

/* Draws the agent's current sprite frame, advances the counter and wraps at nframes. */

void __cdecl16far agnt_drawSpriteFrame(byte index,brect_t *rect,uint16_t type,...)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  agnt_t *agnt;
  stg_tmp_t *psVar6;
  stg_tmp_t *psVar7;
  uint16_t uVar8;
  stg_tmp_t *y;
  int *piVar9;
  int iVar10;
  far_t gfx;
  uint16_t uStack_e;
  uint16_t uStack_c;
  
  agnt = (agnt_t *)((uint)index * 0x34);
  uStack_c = *(uint16_t *)((int)&agnt->frames + 2);
  uStack_e = *(uint16_t *)&agnt->frames;
  piVar9 = (int *)(uStack_e + (uint)agnt->frameIndex * 4);
  iVar2 = piVar9[1];
  iVar3 = *piVar9;
  piVar9 = (int *)(uStack_e + (uint)(byte)agnt->state * 4);
  if (*piVar9 == 0 && piVar9[1] == 0) {
    uStack_e = SprProjectiles.ofs;
    uStack_c = SprProjectiles.seg;
  }
  piVar9 = (int *)(uStack_e + (uint)(byte)agnt->state * 4);
  iVar4 = piVar9[1];
  iVar5 = *piVar9;
  uVar8 = 0x1726;
  iVar10 = uStack_e + (uint)(byte)agnt->state * 4;
  psVar6 = ovr_stash_usesStExit
                     ((stg_tmp_t *)*(undefined2 *)(iVar10 + 0x58),*(undefined2 *)(iVar10 + 0x5a),
                      CONCAT11((char)((uint)index * 0x34 >> 8),
                               *(undefined1 *)((uint)index * 0x34 + 0x31)));
  if ((char)agnt->state == '\r') {
    psVar7 = psVar6;
    y = (stg_tmp_t *)agnt->screenY;
  }
  else if ((char)agnt->state == '\f') {
    psVar7 = (stg_tmp_t *)(agnt->screenY - *(int *)(iVar3 + 0xd));
    y = psVar7;
  }
  else {
    psVar7 = (stg_tmp_t *)(*(int *)(iVar3 + 0xd) >> 1);
    y = (stg_tmp_t *)(agnt->screenY - (int)psVar7);
  }
  gfx.seg = uVar8;
  gfx.ofs = (uint16_t)(psVar6->cmap + 6);
  ovr_blitGfxRect(gfx,agnt->screenX,(int16_t)y,rect,(uint8_t)type,true,
                  CONCAT11((char)((uint)psVar7 >> 8),*(undefined1 *)((int)&agnt->flags32 + 1)));
  pcVar1 = (char *)((int)&agnt->state + 1);
  *pcVar1 = *pcVar1 + '\x01';
  if (*(byte *)(iVar5 + 0x1b) <= *(byte *)((int)&agnt->state + 1)) {
    if (*(char *)(iVar5 + 0x1a) == -1) {
      *(undefined1 *)&agnt->state = 0;
    }
    else {
      *(undefined1 *)((int)&agnt->state + 1) = *(undefined1 *)(iVar5 + 0x1a);
    }
  }
  agnt_compute13(agnt,0x1726);
  return;
}



/* 3b1d:11c1 */

/* [R7] body shape: compute */

void __cdecl16far agnt_compute13(agnt_t *agnt,...)

{
  undefined2 in_stack_00000006;
  
  if ((char)agnt->state == '\0') {
    if ((agnt->flags & 0x100) == 0) {
      if ((agnt->flags & 0x80) != 0) {
        *(undefined1 *)&agnt->state = 0xc;
        *(undefined1 *)((int)&agnt->state + 1) = 0;
      }
    }
    else {
      *(undefined1 *)&agnt->state = 0xd;
      *(undefined1 *)((int)&agnt->state + 1) = 5;
    }
  }
  return;
}



/* 3b1d:120b */

/* Rewrites the two 10x0x69 agent-index grids after an agent record is moved from `fromIndex` to
   `toIndex`; values in (from,to] shift down by one and from+1 becomes to+1. */

void __cdecl16far agnt_remapGridRefs(uint fromIndex,int toIndex)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined2 uStack_4;
  
  if ((int)fromIndex < toIndex) {
    for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
      for (iVar2 = 0; iVar2 < 0x69; iVar2 = iVar2 + 1) {
        if (((int)(fromIndex + 1) < (int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa)) &&
           ((int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) <= toIndex + 1)) {
          pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x8fa);
          *pcVar1 = *pcVar1 + -1;
        }
        else if ((uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) == fromIndex + 1) {
          *(char *)(iVar3 * 0x69 + iVar2 + 0x8fa) = (char)toIndex + '\x01';
        }
        if (((int)(fromIndex + 1) < (int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0)) &&
           ((int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) <= toIndex + 1)) {
          pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x4e0);
          *pcVar1 = *pcVar1 + -1;
        }
        else if ((uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) == fromIndex + 1) {
          *(char *)(iVar3 * 0x69 + iVar2 + 0x4e0) = (char)toIndex + '\x01';
        }
      }
    }
    for (uStack_4 = 0; uStack_4 < (int)(uint)AgntCount; uStack_4 = uStack_4 + 1) {
      if (*(char *)(uStack_4 * 0x34 + 0xc) != -1) {
        if (((int)fromIndex < (int)(uint)*(byte *)(uStack_4 * 0x34 + 0xc)) &&
           ((int)(uint)*(byte *)(uStack_4 * 0x34 + 0xc) <= toIndex)) {
          pcVar1 = (char *)(uStack_4 * 0x34 + 0xc);
          *pcVar1 = *pcVar1 + -1;
        }
        else if (*(byte *)(uStack_4 * 0x34 + 0xc) == fromIndex) {
          *(char *)(uStack_4 * 0x34 + 0xc) = (char)toIndex;
        }
      }
    }
  }
  else {
    for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
      for (iVar2 = 0; iVar2 < 0x69; iVar2 = iVar2 + 1) {
        if (((int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) < toIndex + 1) ||
           ((int)(fromIndex + 1) <= (int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa))) {
          if ((uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) == fromIndex + 1) {
            *(char *)(iVar3 * 0x69 + iVar2 + 0x8fa) = (char)toIndex + '\x01';
          }
        }
        else {
          pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x8fa);
          *pcVar1 = *pcVar1 + '\x01';
        }
        if (((int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) < toIndex + 1) ||
           ((int)(fromIndex + 1) <= (int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0))) {
          if ((uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) == fromIndex + 1) {
            *(char *)(iVar3 * 0x69 + iVar2 + 0x4e0) = (char)toIndex + '\x01';
          }
        }
        else {
          pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x4e0);
          *pcVar1 = *pcVar1 + '\x01';
        }
      }
    }
    for (uStack_4 = 0; uStack_4 < (int)(uint)AgntCount; uStack_4 = uStack_4 + 1) {
      if (*(char *)(uStack_4 * 0x34 + 0xc) != -1) {
        if (((int)(uint)*(byte *)(uStack_4 * 0x34 + 0xc) < toIndex) ||
           ((int)fromIndex <= (int)(uint)*(byte *)(uStack_4 * 0x34 + 0xc))) {
          if (*(byte *)(uStack_4 * 0x34 + 0xc) == fromIndex) {
            *(char *)(uStack_4 * 0x34 + 0xc) = (char)toIndex;
          }
        }
        else {
          pcVar1 = (char *)(uStack_4 * 0x34 + 0xc);
          *pcVar1 = *pcVar1 + '\x01';
        }
      }
    }
  }
  return;
}



/* 3b1d:15bd */

/* [R6] touches AgntCount */

void __cdecl16far agnt_usesAgntCount4(uint agntIndex,...)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
    for (iVar2 = 0; iVar2 < 0x69; iVar2 = iVar2 + 1) {
      if ((AgntCount < *(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa)) ||
         ((int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) <= (int)agntIndex)) {
        if (*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) == agntIndex) {
          *(undefined1 *)(iVar3 * 0x69 + iVar2 + 0x8fa) = 0;
        }
      }
      else {
        pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x8fa);
        *pcVar1 = *pcVar1 + -1;
      }
      if ((AgntCount < *(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0)) ||
         ((int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) <= (int)agntIndex)) {
        if (*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) == agntIndex) {
          *(undefined1 *)(iVar3 * 0x69 + iVar2 + 0x4e0) = 0;
        }
      }
      else {
        pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x4e0);
        *pcVar1 = *pcVar1 + -1;
      }
    }
  }
  return;
}



/* 3b1d:16cd */

/* [R6] touches AgntCount */

void __cdecl16far agnt_usesAgntCount5(int agntIndex,...)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
    for (iVar2 = 0; iVar2 < 0x69; iVar2 = iVar2 + 1) {
      if ((*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) <= AgntCount) &&
         (agntIndex <= (int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa))) {
        pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x8fa);
        *pcVar1 = *pcVar1 + '\x01';
      }
      if ((*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) <= AgntCount) &&
         (agntIndex <= (int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0))) {
        pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x4e0);
        *pcVar1 = *pcVar1 + '\x01';
      }
    }
  }
  return;
}



/* 3b1d:177f */

/* [R6] touches agntSaved, AgntCount */

uint __cdecl16far agnt_usesAgntSaved(int agntIndex,...)

{
  byte bVar3;
  uint uVar1;
  void *pvVar2;
  int iVar5;
  int toIndex;
  undefined2 unaff_SS;
  agnt_t agntSaved;
  undefined1 uVar4;
  
  if ((agntIndex < 1) ||
     (iVar5 = agntIndex, *(int *)(agntIndex * 0x34 + -0x32) <= *(int *)(agntIndex * 0x34 + 2))) {
    uVar1 = (uint)AgntCount;
    if ((agntIndex + 1 < (int)uVar1) &&
       (uVar1 = *(uint *)(agntIndex * 0x34 + 2), iVar5 = agntIndex,
       *(int *)(agntIndex * 0x34 + 0x36) < (int)uVar1)) {
      do {
        toIndex = iVar5 + 1;
        if ((int)(uint)AgntCount <= iVar5 + 2) break;
        iVar5 = toIndex;
      } while (*(int *)(toIndex * 0x34 + 0x36) < *(int *)(agntIndex * 0x34 + 2));
      memcpy((char *)CONCAT22(unaff_SS,&agntSaved),
             (char *)CONCAT22(0x1726,(char *)(agntIndex * 0x34)),0x34);
      _fmemmove((char *)CONCAT22(0x1726,(char *)(agntIndex * 0x34)),
                (char *)CONCAT22(0x1726,(char *)(agntIndex * 0x34 + 0x34)),
                (toIndex - agntIndex) * 0x34);
      pvVar2 = memcpy((char *)CONCAT22(0x1726,(char *)(toIndex * 0x34)),
                      (char *)CONCAT22(unaff_SS,&agntSaved),0x34);
      uVar4 = (undefined1)((uint)pvVar2 >> 8);
      agnt_remapGridRefs(agntIndex,toIndex);
      uVar1 = CONCAT11(uVar4,1);
    }
    else {
      uVar1 = uVar1 & 0xff00;
    }
  }
  else {
    do {
      iVar5 = iVar5 + -1;
      if (iVar5 < 1) break;
    } while (*(int *)(agntIndex * 0x34 + 2) < *(int *)(iVar5 * 0x34 + -0x32));
    memcpy((char *)CONCAT22(unaff_SS,&agntSaved),(char *)CONCAT22(0x1726,(char *)(agntIndex * 0x34))
           ,0x34);
    _fmemmove((char *)CONCAT22(0x1726,(char *)(iVar5 * 0x34 + 0x34)),
              (char *)CONCAT22(0x1726,(char *)(iVar5 * 0x34)),(agntIndex - iVar5) * 0x34);
    pvVar2 = memcpy((char *)CONCAT22(0x1726,(char *)(iVar5 * 0x34)),
                    (char *)CONCAT22(unaff_SS,&agntSaved),0x34);
    bVar3 = (byte)((uint)pvVar2 >> 8);
    agnt_remapGridRefs(agntIndex,iVar5);
    uVar1 = (uint)bVar3 << 8;
  }
  return uVar1;
}



/* 3b1d:196b */

/* [R6] touches AgntCount */

void __cdecl16far agnt_usesAgntCount6(entity_t *ptr,...)

{
  uint16_t i;
  int in_stack_00000006;
  
  for (i = 0; (int)i < (int)(uint)AgntCount; i = i + 1) {
    if ((*(int *)(i * 0x34 + 0x19) == in_stack_00000006) &&
       ((entity_t *)*(int *)(i * 0x34 + 0x17) == ptr)) {
      if (*(byte *)(i * 0x34 + 0x25) < 2) {
        *(undefined1 *)(i * 0x34 + 0x25) = 1;
      }
      *(undefined1 *)(i * 0x34 + 4) = 0;
    }
  }
  return;
}



/* 3b1d:19e0 */

/* [R4] calls ovr_fmFreeAudio */

void __cdecl16far agnt_usesFmFreeAudio(void)

{
  bool bVar1;
  undefined2 in_DX;
  int16_t unaff_BP;
  far_t src;
  far_t src_00;
  far_t handle;
  far_t handle_00;
  
  if (audioSaveCut1Ofs != (far_t *)0x0 || audioSaveCut1Seg != 0) {
    handle.seg = audioSaveCut1Seg;
    handle.ofs = (uint16_t)audioSaveCut1Ofs;
    ovr_stshFree(handle);
  }
  if (audioSaveCut2Ofs != (far_t *)0x0 || audioSaveCut2Seg != 0) {
    handle_00.seg = audioSaveCut2Seg;
    handle_00.ofs = (uint16_t)audioSaveCut2Ofs;
    ovr_stshFree(handle_00);
  }
  GGameState = 0x28;
  if (GameRunning == false) {
    ovr_fmFreeAudio(1);
  }
  else {
    ovr_fmFreeAudio(0);
  }
  src.seg = 0xc;
  src.ofs = BlitRects[0].seg;
  audioSaveCut1Ofs = ovr_stshRleCut((far_t *)0x0,src,7,222,77,unaff_BP);
  src_00.seg = 0xc;
  src_00.ofs = BlitRects[0].seg;
  audioSaveCut1Seg = in_DX;
  audioSaveCut2Ofs = ovr_stshRleCut((far_t *)0x0,src_00,78,222,150,unaff_BP);
  GGameState = 0x29;
  audioSaveCut2Seg = in_DX;
  if (AgntFlag2 != false) {
    ovr_ovc15_usesAgntIndex();
  }
  AgntFlag2 = false;
  GSavedBlitSeg = BlitRects[0].seg;
  GGameState = 0x2a;
  ovr_ovc49_drawAgents();
  bVar1 = agnt_isAnimating();
  if (bVar1) {
    AnimActive = 1;
  }
  return;
}



/* 3b1d:1ad8 */

/* [R4] calls ovr_alignToSeg */

void __cdecl16far agnt_usesAlignToSeg(void)

{
  bool bVar1;
  uint16_t in_DX;
  uint16_t unaff_SS;
  far_t dst;
  far_t ptr;
  far_t handle;
  brect_t mouseRect;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&mouseRect;
  F_SCOPY(far_from_u32((uint32_t)(0x241007ec)),dst);
  constructionDirty = '\0';
  bVar1 = agnt_isAnimating();
  if (bVar1) {
    AnimActive = '\x01';
  }
  if (((AnimActive != '\0') && (GOngoingBattle == '\0')) &&
     (BattleDelay = BattleDelay + 1, 2 < BattleDelay)) {
    tempScreenOfs = ovr_stshAlloc(0xfa0f);
    ptr.seg = in_DX;
    ptr.ofs = (uint16_t)tempScreenOfs;
    tempScreenSeg = in_DX;
    ovr_alignToSeg(ptr);
    GSavedBlitSeg = in_DX;
    bVar1 = agnt_isAnimating();
    if (!bVar1) {
      AnimActive = '\0';
    }
    ovr_ovc49_drawAgents();
    BattleDelay = 0;
    agnt_blitCrossFrame();
    ovr_miceBlitRect(&mouseRect);
    ovr_blitRaw(0xc,7,0xde,0x96,GSavedBlitSeg,0xa000);
    ovr_miceUpdate();
    handle.seg = tempScreenSeg;
    handle.ofs = (uint16_t)tempScreenOfs;
    ovr_stshFree(handle);
    if (constructionDirty != '\0') {
      ovr_constr_usesBlitRect();
    }
  }
  return;
}



/* 3b1d:1bc1 */

/* [R7] body shape: compute */

byte __cdecl16far agnt_compute14(byte level,...)

{
  if (8 < level) {
    if ((level < 9) || (0x10 < level)) {
      level = (char)((int)(level - 0x11) >> 2) + 0xd;
    }
    else {
      level = (char)((int)(level - 9) >> 1) + 9;
    }
  }
  return level;
}



/* 3b1d:1bf5 */

/* [R7] body shape: compute */

int __cdecl16far agnt_compute15(byte rank,uint8_t level)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  
  if (rank == 0) {
    iVar2 = 0;
  }
  else {
    bVar1 = agnt_compute14(level);
    bVar3 = (byte)(bVar1 + 2 >> 8);
    if (bVar1 + 2 < (uint)rank) {
      iVar2 = (uint)bVar3 << 8;
    }
    else {
      iVar2 = CONCAT11(bVar3,1);
    }
  }
  return iVar2;
}



/* 3b1d:1c26 */

/* Selects an enemy agent as target, flags it and reports the index with the attack sound. */

uint __cdecl16far agnt_acquireTarget(agnt_t *agnt,char *agntIndex,...)

{
  undefined4 uVar1;
  uint in_AX;
  uint uVar2;
  int iVar3;
  uint16_t unk;
  undefined2 in_stack_0000000a;
  int iStack_4;
  
  if ((agnt->flags & 1) == 0) {
    for (iStack_4 = 0; iStack_4 < (int)(uint)AgntCount; iStack_4 = iStack_4 + 1) {
      if ((((*(uint8_t *)(iStack_4 * 0x34 + 0x2f) != agnt->faction) &&
           ((*(uint *)(iStack_4 * 0x34 + 0x2b) & 0xae4) == 0)) &&
          (*(char *)(iStack_4 * 0x34 + 0x24) == '\0')) &&
         (uVar1 = *(undefined4 *)(iStack_4 * 0x34 + 0x1d),
         iVar3 = agnt_compute15(*(byte *)((int)uVar1 + 0x42),
                                (((entity_t *)agnt->entity)->base).level), (char)iVar3 != '\0')) {
        agnt->flags = agnt->flags | 3;
        *(char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(agntIndex) + 2))) = (char)iStack_4 + '\x01';
        unk = ovr_audio_panFromX(agnt,(char *)agntIndex);
        ovr_play_sfxU(0x3b,0,unk);
        return CONCAT11((char)(unk >> 8),1);
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = in_AX & 0xff00;
  }
  return uVar2;
}



/* 3b1d:1d0c */

/* Blits the next cross-hair animation frame into the saved screen segment and advances the counter.
    */

void __cdecl16far agnt_blitCrossFrame(void)

{
  far_t gfx;
  far_t dst;
  
  if (((CrossBlitFlag != '\0') && (CrossBlitCount != 0)) && (CrossBlitCount < 5)) {
    dst.seg = GSavedBlitSeg;
    dst.ofs = CrossBlitX + CrossBlitY * 0x140;
    gfx.seg = *(uint16_t *)((uint)CrossBlitCount * 4 + -0x748d);
    gfx.ofs = *(uint16_t *)((uint)CrossBlitCount * 4 + -0x748f);
    ovr_blitLoadRleGfx(gfx,dst);
    CrossBlitCount = CrossBlitCount + 1;
    if (4 < CrossBlitCount) {
      CrossBlitCount = 0;
    }
  }
  return;
}



/* 3b1d:1da5 */

/* [R7] body shape: compute */

undefined1 __cdecl16far agnt_compute16(agnt_t *a,agnt_t *b)

{
  agntG_t *paVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)a >> 0x10);
  paVar1 = ((agnt_t *)a)->gdata;
  if ((((agntG_t *)paVar1)->flags & 2) == 0) {
    uVar2 = 1;
  }
  else {
    bVar3 = agnt_compute9((agnt_t *)a,uVar4);
    uVar4 = (undefined2)((ulong)b >> 0x10);
    paVar1 = ((agnt_t *)b)->gdata;
    if (((((agntG_t *)paVar1)->flags3 & 0x40) == 0) || ('\x01' < (char)bVar3)) {
      paVar1 = ((agnt_t *)b)->gdata;
      if (((((agntG_t *)paVar1)->flags2 & 8) == 0) || ('\0' < (char)bVar3)) {
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


