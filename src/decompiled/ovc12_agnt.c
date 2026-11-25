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

uint16_t __cdecl16far agnt_compute1(int y)

{
  if (y < 0xc) {
    y = 0xc;
  }
  if (0xde < y) {
    y = 0xde;
  }
  return *(uint16_t *)((y + -0xc) * 2 + 0x34c);
}



/* 3b1d:005e */

/* Clamps an x coordinate to 0..0xd2. */

int __cdecl16far agnt_clampX(int x)

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

undefined1 __cdecl16far agnt_compute3(agnt_t far *agnt)

{
  undefined1 uVar1;
  int iVar2;
  agnt_t far *agnt_00;
  uint16_t uVar3;
  
  uVar3 = (uint16_t)((ulong)agnt >> 0x10);
  agnt_00 = (agnt_t far *)agnt;
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

bool __cdecl16far agnt_compute4(char *flag)

{
  return *flag != '\0';
}



/* 3b1d:00ce */

/* Computes the screen extents of the agent's current animation frame. */

undefined1 __cdecl16far agnt_computeFrameExtents(agnt_t far *agnt,uint8_t *result,uint16_t arg3)

{
  uint8_t uVar1;
  uint16_t uVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  uint16_t in_stack_0000000a;
  char cStack_e;
  char cStack_d;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  
  if ((int)agnt->y < 0x15) {
    uVar1 = agnt->faction;
    uVar2 = *(uint16_t *)((int)&agnt->frames + 2);
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
      iStack_a = ((int)((int)(*(((agntG_t far *)agnt->gdata)->extents + 2))[0] + *(int *)(iVar3 + 0x17)
                       + ((agnt_t far *)CONCAT22((uint8_t *)result,agnt))->x) >> 1) + -1;
      iStack_c = iStack_a +
                 ((int)((agntG_t far *)agnt->gdata)->extents[2][1] -
                  (int)(*(((agntG_t far *)agnt->gdata)->extents + 2))[0] >> 1);
    }
    else {
      cStack_d = -1;
      iStack_a = ((int)((-*(int *)(iVar3 + 0x17) -
                        (int)(*(((agntG_t far *)agnt->gdata)->extents + 2))[0]) +
                       ((agnt_t far *)CONCAT22((uint8_t *)result,agnt))->x) >> 1) + 1;
      iStack_c = iStack_a -
                 ((int)((agntG_t far *)agnt->gdata)->extents[2][1] -
                  (int)(*(((agntG_t far *)agnt->gdata)->extents + 2))[0] >> 1);
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
      for (iStack_8 = 0; iStack_8 <= (int)((agntG_t far *)agnt->gdata)->extents[2][2] >> 1;
          iStack_8 = iStack_8 + 1) {
        cStack_e = -1;
        while (((cStack_e < '\x02' && (iStack_8 != 0)) || ((cStack_e == -1 && (iStack_8 == 0))))) {
          iVar5 = iStack_6 + iStack_8 * cStack_e;
          if ((-1 < iVar5) && (iVar5 < 10)) {
            if ((AgntArrayA[iVar5][iStack_a] != '\0') &&
               (((AgntArrayA[iVar5][iStack_a] <= AgntCount &&
                 (Agnts[AgntArrayA[iVar5][iStack_a] - 1].faction !=
                  uVar1)) &&
                (Agnts[AgntArrayA[iVar5][iStack_a] - 1].combatState == '\0')
                ))) {
              *(char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(result) + 2))) =
                   AgntArrayA[iVar5][iStack_a];
              bVar4 = agnt_compute4((char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(result) + 2))));
              if (bVar4) {
                return *(char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(result) + 2)));
              }
            }
            if (((AgntArrayB[iVar5][iStack_a] != '\0') &&
                (AgntArrayB[iVar5][iStack_a] <= AgntCount)) &&
               ((Agnts[AgntArrayB[iVar5][iStack_a] - 1].faction != uVar1
                && (Agnts[AgntArrayB[iVar5][iStack_a] - 1].combatState ==
                    '\0')))) {
              *(char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(result) + 2))) =
                   AgntArrayB[iVar5][iStack_a];
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

undefined1 __cdecl16far agnt_usesStrengthMax(agnt_t far *agnt,byte *out)

{
  uint8_t factionId;
  uint16_t uVar2;
  int frameOfs;
  uint32_t gdataFar;
  bool bVar5;
  undefined1 result;
  int iVar7;
  int *framePtr;
  uint16_t in_stack_0000000a;
  char in_stack_0000000c;
  char rowDir;
  char levelSign;
  int colB;
  int colA;
  int rowOff;
  int baseRow;
  
  if (((agnt->strength < agnt->strengthMax) && ((agnt->flags & 0x820) == 0)) &&
     ((((agntG_t far *)agnt->gdata)->flags & 0x20) == 0)) {
    *(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) = in_stack_0000000c + 1;
    result = 1;
  }
  else {
    factionId = agnt->faction;
    uVar2 = *(uint16_t *)((int)&agnt->frames + 2);
    framePtr = (int *)(*(int *)&agnt->frames + (uint)agnt->frameIndex * 4);
    iVar7 = framePtr[1];
    frameOfs = *framePtr;
    baseRow = (int)agnt->y >> 1;
    if (baseRow < 0) {
      baseRow = 0;
    }
    if (9 < baseRow) {
      baseRow = 9;
    }
    if (agnt->level == 0x0) {
      levelSign = '\x01';
      colA = ((int)((int)(*((agntG_t far *)agnt->gdata)->extents)[0] + *(int *)(frameOfs + 0x17) +
                       ((agnt_t far *)CONCAT22((byte *)out,agnt))->x) >> 1) + -1;
      colB = colA +
                 ((int)((agntG_t far *)agnt->gdata)->extents[0][1] -
                  (int)(*((agntG_t far *)agnt->gdata)->extents)[0] >> 1);
    }
    else {
      levelSign = -1;
      colA = ((int)((-*(int *)(frameOfs + 0x17) - (int)(*((agntG_t far *)agnt->gdata)->extents)[0]) +
                       ((agnt_t far *)CONCAT22((byte *)out,agnt))->x) >> 1) + 1;
      colB = colA -
                 ((int)((agntG_t far *)agnt->gdata)->extents[0][1] -
                  (int)(*((agntG_t far *)agnt->gdata)->extents)[0] >> 1);
    }
    if (colA < 0) {
      colA = 0;
    }
    if (colB < 0) {
      colB = 0;
    }
    if (0x68 < colA) {
      colA = 0x68;
    }
    if (0x68 < colB) {
      colB = 0x68;
    }
    for (; colA != colB; colA = colA + levelSign) {
      for (rowOff = 0; rowOff <= (int)((agntG_t far *)agnt->gdata)->extents[0][2] >> 1;
          rowOff = rowOff + 1) {
        rowDir = -1;
        while (((rowDir < '\x02' && (rowOff != 0)) || ((rowDir == -1 && (rowOff == 0))))) {
          iVar7 = baseRow + rowOff * rowDir;
          if ((-1 < iVar7) && (iVar7 < 10)) {
            if ((AgntArrayA[iVar7][colA] != '\0') &&
               ((((AgntArrayA[iVar7][colA] <= AgntCount &&
                  (Agnts[AgntArrayA[iVar7][colA] - 1].strength <
                   Agnts[AgntArrayA[iVar7][colA] - 1].strengthMax)) &&
                 (Agnts[AgntArrayA[iVar7][colA] - 1].faction ==
                  factionId)) &&
                ((*(uint8_t *)
                   *(uint32_t far *)&Agnts[AgntArrayA[iVar7][colA] - 1].gdata
                  == factionId &&
                 (gdataFar = *(uint32_t far *)&Agnts[AgntArrayA[iVar7][colA] - 1].gdata,
                 (*(uint *)((int)gdataFar + 0x3c) & 0x20) == 0)))))) {
              *(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) =
                   AgntArrayA[iVar7][colA];
              bVar5 = agnt_compute4((char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))));
              if ((bVar5) &&
                 ((*(byte *)((uint)*(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) * 0x34 + -0x13) <
                   *(byte *)((uint)*(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) * 0x34 + -0x12) &&
                  ((*(uint *)((uint)*(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) * 0x34 + -9) &
                   0x820) == 0)))) {
                return AgntArrayA[iVar7][colA];
              }
            }
            if ((((AgntArrayB[iVar7][colA] != '\0') &&
                 (AgntArrayB[iVar7][colA] <= AgntCount)) &&
                (Agnts[AgntArrayB[iVar7][colA] - 1].strength <
                 Agnts[AgntArrayB[iVar7][colA] - 1].strengthMax)) &&
               (((Agnts[AgntArrayB[iVar7][colA] - 1].faction ==
                  factionId && (*(uint8_t *)
                             *(uint32_t far *)&Agnts[AgntArrayB[iVar7][colA] - 1].gdata ==
                            factionId)) &&
                (gdataFar = *(uint32_t far *)&Agnts[AgntArrayB[iVar7][colA] - 1].gdata,
                (*(uint *)((int)gdataFar + 0x3c) & 0x20) == 0)))) {
              *(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) =
                   AgntArrayB[iVar7][colA];
              return AgntArrayB[iVar7][colA];
            }
          }
          rowDir = rowDir + '\x02';
        }
      }
    }
    *(byte *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(out) + 2))) = 0;
    result = 0;
  }
  return result;
}



/* 3b1d:093e */

/* [R6] touches AgntCount */

bool __cdecl16far
agnt_usesAgntCount2(agnt_t far *agnt,uint16_t *xDir,uint16_t *yDir,uint16_t *distance)

{
  /* Re-derived from 3b1d:093e.  All four parameters are far pointers read directly by the
     original, so the exported CONCAT22 forms - each of which used one parameter's offset as
     another's segment - collapse to plain dereferences.  As written they sent the x-direction
     sign into yDir and the y-direction sign into distance, overwriting the distance just
     stored. */
  uint8_t faction;
  uint dx;
  uint dxSign;
  uint dy;
  uint dySign;
  uint dist;
  uint16_t dirVal;
  byte agntIdx;

  faction = agnt->faction;
  *distance = 0xffff;
  agntIdx = 0;
  while( true ) {
    if (AgntCount <= agntIdx) break;
    if ((Agnts[agntIdx].faction != faction) &&
       (dx = Agnts[agntIdx].x - agnt->x, dxSign = (int)dx >> 0xf,
       dy = Agnts[agntIdx].y - agnt->y, dySign = (int)dy >> 0xf,
       dist = ((dx ^ dxSign) - dxSign) + ((dy ^ dySign) - dySign),
       dist < *distance)) {
      *distance = dist;
      dirVal = ovr_ovc07_signum(Agnts[agntIdx].x - agnt->x);
      *xDir = dirVal;
      dirVal = ovr_ovc07_signum(Agnts[agntIdx].y - agnt->y);
      *yDir = dirVal;
    }
    agntIdx = agntIdx + 1;
  }
  return *distance != 0xffff;
}



/* 3b1d:0a53 */

/* [R6] touches animFrame */

void __cdecl16far agnt_usesAnimFrame(agnt_t far *agnt,...)

{
  
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

void __cdecl16far agnt_compute5(agnt_t far *agnt)

{
  ((agnt_t far *)agnt)->health = 0x0;
  animBranchCode = 0;
  return;
}



/* 3b1d:0a9f */

/* Advances the agent's animation frame unless bit 2 of its type record (agntG_t+0) is set. */

void __cdecl16far agnt_advanceAnimFrame(agnt_t far *agnt,uint16_t arg2)

{
  uint16_t in_stack_00000006;
  
  if ((((agntG_t far *)agnt->gdata)->flags3 & 4) == 0) {
    agnt_usesAnimFrame(agnt,in_stack_00000006);
  }
  return;
}



/* 3b1d:0ac0 */

/* Builds the agent's status text from its flags (charmed / diseased / held / paralyzed). */

char * __cdecl16far agnt_statusText(agnt_t far *agnt,char *text,uint16_t arg3)

{
  char *pcVar1;
  agntG_t far *paVar2;
  uint16_t uVar3;
  char *in_stack_0000000a;
  
  if ((agnt->flags & 0x20) == 0) {
    if ((agnt->flags & 4) == 0) {
      if ((agnt->flags & 0x800) == 0) {
        if ((*(uint *)((int)&(((entity_t *)agnt->entity)->base).frames + 1) & 1) == 0) {
          if ((agnt->flags & 0x200) == 0) {
            if ((agnt->flags & 0x80) == 0) {
              if ((agnt->flags & 0x40) == 0) {
                    /* WARNING: Load size is inaccurate */
                pcVar1 = ((agntG_t far *)agnt->gdata)->name;
              }
              else {
                uVar3 = (uint16_t)((ulong)agnt->gdata >> 0x10);
                paVar2 = (agntG_t far *)agnt->gdata;
                pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x83c,in_stack_0000000a),
                                       (char *)CONCAT22(*(uint16_t *)&paVar2->name,
                                                        (char *)0x26510),
                                       *(uint16_t *)((int)&paVar2->name + 2));
              }
            }
            else {
              uVar3 = (uint16_t)((ulong)agnt->gdata >> 0x10);
              paVar2 = (agntG_t far *)agnt->gdata;
              pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x830,in_stack_0000000a),
                                     (char *)CONCAT22(*(uint16_t *)&paVar2->name,
                                                      (char *)0x26510),
                                     *(uint16_t *)((int)&paVar2->name + 2));
            }
          }
          else {
            uVar3 = (uint16_t)((ulong)agnt->gdata >> 0x10);
            paVar2 = (agntG_t far *)agnt->gdata;
            pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x823,in_stack_0000000a),
                                   (char *)CONCAT22(*(uint16_t *)&paVar2->name,
                                                    (char *)0x26510),
                                   *(uint16_t *)((int)&paVar2->name + 2));
          }
        }
        else {
          uVar3 = (uint16_t)((ulong)agnt->gdata >> 0x10);
          paVar2 = (agntG_t far *)agnt->gdata;
          pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x817,in_stack_0000000a),
                                 (char *)CONCAT22(*(uint16_t *)&paVar2->name,
                                                  (char *)0x26510),
                                 *(uint16_t *)((int)&paVar2->name + 2));
        }
      }
      else {
        uVar3 = (uint16_t)((ulong)agnt->gdata >> 0x10);
        paVar2 = (agntG_t far *)agnt->gdata;
        pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x80d,in_stack_0000000a),
                               (char *)CONCAT22(*(uint16_t *)&paVar2->name,
                                                (char *)0x26510),
                               *(uint16_t *)((int)&paVar2->name + 2));
      }
    }
    else {
      uVar3 = (uint16_t)((ulong)agnt->gdata >> 0x10);
      paVar2 = (agntG_t far *)agnt->gdata;
      pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x803,in_stack_0000000a),
                             (char *)CONCAT22(*(uint16_t *)&paVar2->name,(char *)0x26510
                                             ),*(uint16_t *)((int)&paVar2->name + 2));
    }
  }
  else {
    uVar3 = (uint16_t)((ulong)agnt->gdata >> 0x10);
    paVar2 = (agntG_t far *)agnt->gdata;
    pcVar1 = ovr_stsprintf((*(uint16_t *)((uint8_t *)&(text) + 2)),(char *)CONCAT22(0x7f8,in_stack_0000000a),
                           (char *)CONCAT22(*(uint16_t *)&paVar2->name,(char *)0x26510),
                           *(uint16_t *)((int)&paVar2->name + 2));
  }
  return pcVar1;
}



/* 3b1d:0c1e */

/* Returns the ability modifier of a party sheet's stat (same thresholds as manage_abilityModifier).
    */

uint16_t __cdecl16far agnt_abilityModifier(byte partyIndex,byte abilityIndex)

{
  byte bVar1;
  uint16_t modifier;
  
  bVar1 = ((char_sheet_t *)(((uint)partyIndex << 2) + (uint)abilityIndex))->stats[0];
  if (bVar1 < 4) {
    modifier = 0xfd;
  }
  else if (bVar1 < 6) {
    modifier = 0xfe;
  }
  else if (bVar1 < 9) {
    modifier = 0xff;
  }
  else if (bVar1 < 0xd) {
    modifier = 0;
  }
  else if (bVar1 < 0x10) {
    modifier = 1;
  }
  else if (bVar1 < 0x12) {
    modifier = 2;
  }
  else {
    modifier = 3;
  }
  return modifier;
}



/* 3b1d:0c7c */

/* [R7] body shape: compute */

byte __cdecl16far agnt_compute8(agnt_t far *agnt,uint16_t arg2)

{
  byte bVar1;
  
  bVar1 = (byte)agnt[1].y % 6;
  if (3 < bVar1) {
    bVar1 = bVar1 - 6;
  }
  return bVar1;
}



/* 3b1d:0c9f */

/* [R7] body shape: compute */

byte __cdecl16far agnt_compute9(agnt_t far *agnt,uint16_t arg2)

{
  byte bVar1;
  
  bVar1 = ((entity_t *)agnt->entity)->dir % 6;
  if (3 < bVar1) {
    bVar1 = bVar1 - 6;
  }
  return bVar1;
}



/* 3b1d:0cc6 */

/* [R7] body shape: compute */

byte __cdecl16far agnt_compute10(agnt_t far *agnt,uint16_t arg2)

{
  byte bVar1;
  
  bVar1 = (byte)(((ulong)(byte)agnt[1].y / 6) % 6);
  if (4 < bVar1) {
    bVar1 = bVar1 - 6;
  }
  return bVar1;
}



/* 3b1d:0cef */

/* [R7] body shape: compute */

byte __cdecl16far agnt_compute11(agnt_t far *agnt,uint16_t arg2)

{
  byte bVar1;
  
  bVar1 = (byte)(((ulong)((entity_t *)agnt->entity)->dir / 6) % 6);
  if (4 < bVar1) {
    bVar1 = bVar1 - 6;
  }
  return bVar1;
}



/* 3b1d:0d1c */

/* [R6] touches animFrame */

undefined1 __cdecl16far agnt_usesAnimFrame2(agnt_t far *agnt,uint16_t arg2)

{
  undefined1 uVar1;
  
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

uint __cdecl16far agnt_compute12(agnt_t far *a,agnt_t far *b,uint16_t arg3,uint16_t arg4,uint16_t arg5)

{
  uint uVar1;
  uint16_t in_stack_0000000a;
  
  uVar1 = ((agnt_t far *)CONCAT22((agnt_t far *)b,a))->x;
  if ((int)uVar1 < *(int *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(b) + 2)))) {
    if (*(char *)((int)(*(uint16_t *)((uint8_t *)&(b) + 2)) + 0xf) != '\0') {
      return 1;
    }
  }
  else {
    uVar1 = (uint)*(char *)((int)(*(uint16_t *)((uint8_t *)&(b) + 2)) + 0xf);
    if (uVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* 3b1d:0d82 */

/* [R4] calls ovr_stExit */

void __cdecl16far agnt_usesStExit(agnt_t far *agnt, anm_t far *anim, stg_tmp_t *sprite, uint16_t arg4, uint16_t arg5, uint16_t arg6, uint16_t arg7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
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
    ovr_ovc41_resolveSpecialAttack((agnt_t far *)CONCAT22((anm_t *)anim,agnt),(uint)agnt->target);
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
      ovr_ovc41_resolveSpecialAttack((agnt_t far *)CONCAT22((anm_t *)anim,agnt),(uint)agnt->target);
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

void __cdecl16far agnt_drawSpriteFrame(byte index,brect_t *rect,uint16_t type)

{
  /* Re-derived from 3b1d:1035 (396 bytes).  frames is the agent's frame table; frame is the entry
     for its current animation frame, stateFrame the one for its state (falling back to
     SprProjectiles when that entry is null).  The sprite comes from stash_usesStExit, the vertical
     offset depends on the state (0xd screenY, 0xc screenY minus the frame's +0xd, otherwise
     screenY minus half of it), then the frame is blitted, the animation counter advanced and
     wrapped, and agnt_compute13 called.
     gfx.seg is SEG_OF(Agnts): the original takes it from the stash call (`mov [bp-6],dx`), but this
     build passes data pointers as near, so that return's segment half is not available.  The blit
     type is the constant 0x10 - the third parameter `type` is unused. */
  agnt_t far *agnt;
  uint16_t framesOfs;
  uint16_t framesSeg;
  int frameOfs;
  int frameSeg;
  int stateFrameOfs;
  int stateFrameSeg;
  stg_tmp_t *stash;
  int offsetY;
  int y;
  far_t gfx;
  byte *animPtr;

  agnt = (agnt_t far *)&Agnts[index].x;
  framesSeg = *(uint16_t *)((int)&agnt->frames + 2);
  framesOfs = *(uint16_t *)&agnt->frames;
  frameSeg = *(int *)(framesOfs + (uint)agnt->frameIndex * 4 + 2);
  frameOfs = *(int *)(framesOfs + (uint)agnt->frameIndex * 4);
  if ((*(int *)(framesOfs + (uint)(byte)agnt->state * 4) == 0) &&
     (*(int *)(framesOfs + (uint)(byte)agnt->state * 4 + 2) == 0)) {
    framesOfs = SprProjectiles.ofs;
    framesSeg = SprProjectiles.seg;
  }
  stateFrameSeg = *(int *)(framesOfs + (uint)(byte)agnt->state * 4 + 2);
  stateFrameOfs = *(int *)(framesOfs + (uint)(byte)agnt->state * 4);
  stash = ovr_stash_usesStExit(
              (stg_tmp_t *)*(uint16_t *)(framesOfs + (uint)(byte)agnt->state * 4 + 0x58),
              *(uint16_t *)(framesOfs + (uint)(byte)agnt->state * 4 + 0x5a),
              CONCAT11((char)((uint)index * 0x34 >> 8),
                       AGNT_FIELD(&Agnts[index], state, 1)));
  if ((char)agnt->state == '\r') {
    offsetY = (int)stash;
    y = agnt->screenY;
  }
  else if ((char)agnt->state == '\f') {
    offsetY = agnt->screenY - *(int *)(frameOfs + 0xd);
    y = offsetY;
  }
  else {
    offsetY = *(int *)(frameOfs + 0xd) >> 1;
    y = agnt->screenY - offsetY;
  }
  gfx.seg = SEG_OF(Agnts);
  gfx.ofs = (uint16_t)(stash->cmap + 6);
  ovr_blitGfxRect(gfx,agnt->screenX,(int16_t)y,rect,0x10,true,
                  CONCAT11((char)((uint)offsetY >> 8),
                           *(undefined1 *)((int)&agnt->flags32 + 1)),0,0,0,0,0);
  animPtr = (char *)((int)&agnt->state + 1);
  *animPtr = *animPtr + '\x01';
  if (*(byte *)(stateFrameOfs + 0x1b) <= *(byte *)((int)&agnt->state + 1)) {
    if (*(char *)(stateFrameOfs + 0x1a) == -1) {
      *(undefined1 *)&agnt->state = 0;
    }
    else {
      *(undefined1 *)((int)&agnt->state + 1) = *(undefined1 *)(stateFrameOfs + 0x1a);
    }
  }
  agnt_compute13(agnt,SEG_OF(Agnts));
  return;
}



/* 3b1d:11c1 */

/* [R7] body shape: compute */

void __cdecl16far agnt_compute13(agnt_t far *agnt,uint16_t arg2)

{
  
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
  char *cellPtr;
  int ofs;
  int rec;
  uint16_t agentIndex;
  
  if ((int)fromIndex < toIndex) {
    for (rec = 0; rec < 10; rec = rec + 1) {
      for (ofs = 0; ofs < 0x69; ofs = ofs + 1) {
        if (((int)(fromIndex + 1) < (int)(uint)AgntArrayA[rec][ofs]) &&
           ((int)(uint)AgntArrayA[rec][ofs] <= toIndex + 1)) {
          cellPtr = (char *)(&AgntArrayA[rec][ofs]);
          *cellPtr = *cellPtr + -1;
        }
        else if ((uint)AgntArrayA[rec][ofs] == fromIndex + 1) {
          AgntArrayA[rec][ofs] = (char)toIndex + '\x01';
        }
        if (((int)(fromIndex + 1) < (int)(uint)AgntArrayB[rec][ofs]) &&
           ((int)(uint)AgntArrayB[rec][ofs] <= toIndex + 1)) {
          cellPtr = (char *)(&AgntArrayB[rec][ofs]);
          *cellPtr = *cellPtr + -1;
        }
        else if ((uint)AgntArrayB[rec][ofs] == fromIndex + 1) {
          AgntArrayB[rec][ofs] = (char)toIndex + '\x01';
        }
      }
    }
    for (agentIndex = 0; agentIndex < (int)(uint)AgntCount; agentIndex = agentIndex + 1) {
      if (Agnts[agentIndex].target != -1) {
        if (((int)fromIndex < (int)(uint)Agnts[agentIndex].target) &&
           ((int)(uint)Agnts[agentIndex].target <= toIndex)) {
          cellPtr = (char *)&Agnts[agentIndex].target;
          *cellPtr = *cellPtr + -1;
        }
        else if (Agnts[agentIndex].target == fromIndex) {
          Agnts[agentIndex].target = (char)toIndex;
        }
      }
    }
  }
  else {
    for (rec = 0; rec < 10; rec = rec + 1) {
      for (ofs = 0; ofs < 0x69; ofs = ofs + 1) {
        if (((int)(uint)AgntArrayA[rec][ofs] < toIndex + 1) ||
           ((int)(fromIndex + 1) <= (int)(uint)AgntArrayA[rec][ofs])) {
          if ((uint)AgntArrayA[rec][ofs] == fromIndex + 1) {
            AgntArrayA[rec][ofs] = (char)toIndex + '\x01';
          }
        }
        else {
          cellPtr = (char *)(&AgntArrayA[rec][ofs]);
          *cellPtr = *cellPtr + '\x01';
        }
        if (((int)(uint)AgntArrayB[rec][ofs] < toIndex + 1) ||
           ((int)(fromIndex + 1) <= (int)(uint)AgntArrayB[rec][ofs])) {
          if ((uint)AgntArrayB[rec][ofs] == fromIndex + 1) {
            AgntArrayB[rec][ofs] = (char)toIndex + '\x01';
          }
        }
        else {
          cellPtr = (char *)(&AgntArrayB[rec][ofs]);
          *cellPtr = *cellPtr + '\x01';
        }
      }
    }
    for (agentIndex = 0; agentIndex < (int)(uint)AgntCount; agentIndex = agentIndex + 1) {
      if (Agnts[agentIndex].target != -1) {
        if (((int)(uint)Agnts[agentIndex].target < toIndex) ||
           ((int)fromIndex <= (int)(uint)Agnts[agentIndex].target)) {
          if (Agnts[agentIndex].target == fromIndex) {
            Agnts[agentIndex].target = (char)toIndex;
          }
        }
        else {
          cellPtr = (char *)&Agnts[agentIndex].target;
          *cellPtr = *cellPtr + '\x01';
        }
      }
    }
  }
  return;
}



/* 3b1d:15bd */

/* [R6] touches AgntCount */

void __cdecl16far agnt_usesAgntCount4(uint agntIndex)

{
  /* Re-derived: removes agntIndex from both agent-index arrays.  A cell greater than the
     index is decremented, a matching cell is zeroed.  The decrement keeps the export's
     byte semantics - a char pointer into the cell, so only its low byte changes. */
  char *cellPtr;
  int colIdx;
  int rowIdx;

  for (rowIdx = 0; rowIdx < 10; rowIdx = rowIdx + 1) {
    for (colIdx = 0; colIdx < 0x69; colIdx = colIdx + 1) {
      if ((AgntCount < AgntArrayA[rowIdx][colIdx]) ||
         ((int)(uint)AgntArrayA[rowIdx][colIdx] <= (int)agntIndex)) {
        if (AgntArrayA[rowIdx][colIdx] == agntIndex) {
          AgntArrayA[rowIdx][colIdx] = 0;
        }
      }
      else {
        cellPtr = (char *)(&AgntArrayA[rowIdx][colIdx]);
        *cellPtr = *cellPtr + -1;
      }
      if ((AgntCount < AgntArrayB[rowIdx][colIdx]) ||
         ((int)(uint)AgntArrayB[rowIdx][colIdx] <= (int)agntIndex)) {
        if (AgntArrayB[rowIdx][colIdx] == agntIndex) {
          AgntArrayB[rowIdx][colIdx] = 0;
        }
      }
      else {
        cellPtr = (char *)(&AgntArrayB[rowIdx][colIdx]);
        *cellPtr = *cellPtr + -1;
      }
    }
  }
  return;
}



/* 3b1d:16cd */

/* [R6] touches AgntCount */

void __cdecl16far agnt_usesAgntCount5(int agntIndex)

{
  char *countPtr;
  int col;
  int row;
  
  for (row = 0; row < 10; row = row + 1) {
    for (col = 0; col < 0x69; col = col + 1) {
      if ((AgntArrayA[row][col] <= AgntCount) &&
         (agntIndex <= (int)(uint)AgntArrayA[row][col])) {
        countPtr = (char *)(&AgntArrayA[row][col]);
        *countPtr = *countPtr + '\x01';
      }
      if ((AgntArrayB[row][col] <= AgntCount) &&
         (agntIndex <= (int)(uint)AgntArrayB[row][col])) {
        countPtr = (char *)(&AgntArrayB[row][col]);
        *countPtr = *countPtr + '\x01';
      }
    }
  }
  return;
}



/* 3b1d:177f */

/* [R6] touches agntSaved, AgntCount */

uint __cdecl16far agnt_usesAgntSaved(int agntIndex)

{
  byte bVar3;
  uint uVar1;
  void *pvVar2;
  int iVar5;
  int toIndex;
  agnt_t agntSaved;
  undefined1 uVar4;
  
  if ((agntIndex < 1) ||
     (iVar5 = agntIndex, Agnts[agntIndex - 1].y <= Agnts[agntIndex].y)) {
    uVar1 = (uint)AgntCount;
    if ((agntIndex + 1 < (int)uVar1) &&
       (uVar1 = Agnts[agntIndex].y, iVar5 = agntIndex,
       Agnts[agntIndex + 1].y < (int)uVar1)) {
      do {
        toIndex = iVar5 + 1;
        if ((int)(uint)AgntCount <= iVar5 + 2) break;
        iVar5 = toIndex;
      } while (Agnts[toIndex + 1].y < Agnts[agntIndex].y);
      memcpy((char *)CONCAT22(_SS,&agntSaved),
             (char *)CONCAT22(SEG_OF(Agnts),(char *)&Agnts[agntIndex].x),0x34);
      _fmemmove((char *)CONCAT22(SEG_OF(Agnts),(char *)&Agnts[agntIndex].x),
                (char *)CONCAT22(SEG_OF(Agnts),(char *)&Agnts[agntIndex + 1].x),
                (toIndex - agntIndex) * 0x34);
      pvVar2 = memcpy((char *)CONCAT22(SEG_OF(Agnts),(char *)&Agnts[toIndex].x),
                      (char *)CONCAT22(_SS,&agntSaved),0x34);
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
    } while (Agnts[agntIndex].y < Agnts[iVar5 - 1].y);
    memcpy((char *)CONCAT22(_SS,&agntSaved),(char *)CONCAT22(SEG_OF(Agnts),(char *)&Agnts[agntIndex].x)
           ,0x34);
    _fmemmove((char *)CONCAT22(SEG_OF(Agnts),(char *)&Agnts[iVar5 + 1].x),
              (char *)CONCAT22(SEG_OF(Agnts),(char *)&Agnts[iVar5].x),(agntIndex - iVar5) * 0x34);
    pvVar2 = memcpy((char *)CONCAT22(SEG_OF(Agnts),(char *)&Agnts[iVar5].x),
                    (char *)CONCAT22(_SS,&agntSaved),0x34);
    bVar3 = (byte)((uint)pvVar2 >> 8);
    agnt_remapGridRefs(agntIndex,iVar5);
    uVar1 = (uint)bVar3 << 8;
  }
  return uVar1;
}



/* 3b1d:196b */

/* [R6] touches AgntCount */

void __cdecl16far agnt_usesAgntCount6(entity_t *ptr,uint16_t arg2)

{
  uint16_t i;
  
  for (i = 0; (int)i < (int)(uint)AgntCount; i = i + 1) {
    if ((AGNT_WORD(&Agnts[i], entity, 2) == arg2) &&
       ((entity_t *)AGNT_WORD(&Agnts[i], entity, 0) == ptr)) {
      if (Agnts[i].moveState < 2) {
        Agnts[i].moveState = 1;
      }
      AGNT_FIELD(&Agnts[i], targetX, 0) = 0;
    }
  }
  return;
}



/* 3b1d:19e0 */

/* [R4] calls ovr_fmFreeAudio */

void __cdecl16far agnt_usesFmFreeAudio(void)

{
  bool bVar1;
  uint16_t in_DX;
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
  audioSaveCut1Ofs = ovr_stshRleCut((far_t *)0x0,src,7,222,77,unaff_BP,0,0,0);
  src_00.seg = 0xc;
  src_00.ofs = BlitRects[0].seg;
  audioSaveCut1Seg = in_DX;
  audioSaveCut2Ofs = ovr_stshRleCut((far_t *)0x0,src_00,78,222,150,unaff_BP,0,0,0);
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
  bool animating;
  uint16_t in_DX;
  far_t dst;
  far_t ptr;
  far_t handle;
  brect_t mouseRect;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)&mouseRect;
  F_SCOPY(far_from_u32((uint32_t)(0x241007ec)),dst,10);
  constructionDirty = '\0';
  animating = agnt_isAnimating();
  if (animating) {
    AnimActive = '\x01';
  }
  if (((AnimActive != '\0') && (GOngoingBattle == '\0')) &&
     (BattleDelay = BattleDelay + 1, 2 < BattleDelay)) {
    {
      void far *p = ovr_stshAlloc(0xfa0f);
      ptr.ofs = ST_OFF(p);
      ptr.seg = ST_SEG(p);
    }
    tempScreenOfs = ptr.ofs;
    tempScreenSeg = ptr.seg;
    ovr_alignToSeg(ptr);
    GSavedBlitSeg = in_DX;
    animating = agnt_isAnimating();
    if (!animating) {
      AnimActive = '\0';
    }
    ovr_ovc49_drawAgents();
    BattleDelay = 0;
    agnt_blitCrossFrame();
    ovr_miceBlitRect(&mouseRect,0);
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

byte __cdecl16far agnt_compute14(byte level)

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

uint __cdecl16far agnt_acquireTarget(agnt_t far *agnt,char *agntIndex,uint16_t arg3)

{
  uint32_t uVar1;
  uint in_AX;
  uint uVar2;
  int iVar3;
  uint16_t unk;
  uint16_t in_stack_0000000a;
  int iStack_4;
  
  if ((agnt->flags & 1) == 0) {
    for (iStack_4 = 0; iStack_4 < (int)(uint)AgntCount; iStack_4 = iStack_4 + 1) {
      if ((((Agnts[iStack_4].faction != agnt->faction) &&
           ((Agnts[iStack_4].flags & 0xae4) == 0)) &&
          (Agnts[iStack_4].combatState == '\0')) &&
         (uVar1 = *(uint32_t far *)&Agnts[iStack_4].gdata,
         iVar3 = agnt_compute15(*(byte *)((int)uVar1 + 0x42),
                                (((entity_t *)agnt->entity)->base).level), (char)iVar3 != '\0')) {
        agnt->flags = agnt->flags | 3;
        *(char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(agntIndex) + 2))) = (char)iStack_4 + '\x01';
        unk = ovr_audio_panFromX(agnt,(char *)agntIndex);
        ovr_play_sfxU(0x3b,0,unk,0,0);
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
    ovr_blitLoadRleGfx(gfx,dst,0);
    CrossBlitCount = CrossBlitCount + 1;
    if (4 < CrossBlitCount) {
      CrossBlitCount = 0;
    }
  }
  return;
}



/* 3b1d:1da5 */

/* [R7] body shape: compute */

undefined1 __cdecl16far agnt_compute16(agnt_t far *a,agnt_t far *b)

{
  agntG_t far *paVar1;
  undefined1 uVar2;
  byte bVar3;
  uint16_t uVar4;
  
  uVar4 = (uint16_t)((ulong)a >> 0x10);
  paVar1 = ((agnt_t far *)a)->gdata;
  if ((((agntG_t *)paVar1)->flags & 2) == 0) {
    uVar2 = 1;
  }
  else {
    bVar3 = agnt_compute9((agnt_t far *)a,uVar4);
    uVar4 = (uint16_t)((ulong)b >> 0x10);
    paVar1 = ((agnt_t far *)b)->gdata;
    if (((((agntG_t *)paVar1)->flags3 & 0x40) == 0) || ('\x01' < (char)bVar3)) {
      paVar1 = ((agnt_t far *)b)->gdata;
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


