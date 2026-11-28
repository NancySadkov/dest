/*
 * ovc41_main.c - recovered from STRONG.EXE
 * memory block: OVC41_main.c
 * range: 6a8f:0000 - 6a8f:2eaf
 * functions: 37
 */
#include "recovered.h"


/* 6a8f:0000 */

/* Returns "" for a count of 1 and "s" otherwise (plural suffix for formatted strings). */

uint16_t __cdecl16far ovc41_pluralSuffix(int count,...)

{
  uint16_t uVar1;
  
  if (count == 1) {
    uVar1 = 0x6e74;
  }
  else {
    uVar1 = 0x6e75;
  }
  return uVar1;
}



/* 6a8f:0017 */

/* [R7] body shape: compute */

uint16_t __cdecl16far ovc41_compute2(int count)

{
  uint16_t uVar1;
  
  if (count == 1) {
    uVar1 = 0x6e74;
  }
  else {
    uVar1 = 0x6e75;
  }
  return uVar1;
}



/* 6a8f:002e */

/* [R7] body shape: compute */

void __cdecl16far ovc41_compute3(uint32_t view,...)

{
  /* Re-derived: `view` is a far pointer and its offset half is the menu-view record.
     ownerIdx comes from the agnt-g table via view[0xd] (0xff normalises to 0);
     entryOfs addresses a 0x94-stride table at view[0xf]*4.  An all-zero entry means
     "nothing selected yet", so the cursor is placed one past the previous entry;
     otherwise the stored position is compared and, when it is behind the cursor, the
     cursor steps forward and ovc15_textView's delta is added to view[0x31]/view[0x32]. */
  uint16_t ownerIdx;
  far_t viewFar;
  uint8_t far *viewRec;
  uint16_t entryOfs;
  int *entry;
  uint entryLo;
  char panDelta;

  viewFar = far_from_u32(view);
  viewRec = (uint8_t far *)MK_FP(viewFar.seg,viewFar.ofs);
  ownerIdx = AgntGs[(uint)*(byte far *)(viewRec + 0xd)].shortName[3];
  if (ownerIdx == 0xff) {
    ownerIdx = 0;
  }
  entryOfs = (uint)ownerIdx * 0x94 + (uint)*(byte far *)(viewRec + 0xf) * 4;
  entry = (int *)entryOfs;
  if (*entry == 0 && entry[1] == 0) {
    entryLo = *(uint *)(entryOfs + -4);
    *(int far *)(viewRec + 0x12) = *(int *)(entryOfs + -2) + (uint)(0xfffe < entryLo);
    *(int far *)(viewRec + 0x10) = entryLo + 1;
  }
  else {
    entryLo = entry[1];
    if ((entryLo <= *(uint far *)(viewRec + 0x12)) &&
       ((entryLo != *(uint far *)(viewRec + 0x12)) ||
        ((uint)*entry <= *(uint far *)(viewRec + 0x10)))) {
      entryLo = (uint)*entry;
      *(int far *)(viewRec + 0x12) = entry[1] + (uint)(0xfffe < entryLo);
      *(int far *)(viewRec + 0x10) = entryLo + 1;
      *(char far *)(viewRec + 0xf) = *(char far *)(viewRec + 0xf) + '\x01';
      panDelta = ovr_ovc15_textView(view);
      *(char far *)(viewRec + 0x31) = *(char far *)(viewRec + 0x31) + panDelta;
      *(char far *)(viewRec + 0x32) = *(char far *)(viewRec + 0x32) + panDelta;
    }
  }
  return;
}



/* 6a8f:016b */

/* [R7] body shape: compute */

void __cdecl16far ovc41_compute4(agnt_t far *agnt,byte flag,byte pad,agnt_t far *other,uint16_t arg5,uint16_t arg6,uint16_t arg7,uint16_t arg8)

{
  uint *puVar1;
  uint healthOld;
  agnt_t far *paVar3;
  int carryIn;
  uint16_t unaff_BP;
  uint16_t in_stack_00000000;
  long b;
  uint16_t in_stack_0000000c;
  undefined1 in_stack_0000fffc;
  long *retStorage;
  
  if (pad != 0) {
    retStorage = (long *)CONCAT11(other->gindex,in_stack_0000fffc);
    if (AgntGs[(uint)other->gindex].shortName[3] != -1) {
      ovc41_growthForLevel(agnt,0);
      carryIn = 0;
      paVar3 = (agnt_t far *)LXMUL_at_(retStorage,CONCAT22(in_stack_00000000,unaff_BP),b);
      paVar3 = ovr_ovc15_textError((agnt_t far *)CONCAT22(in_stack_0000000c,other),paVar3);
      puVar1 = (uint *)&other->health;
      healthOld = *puVar1;
      *puVar1 = (int)&paVar3->x + *puVar1;
      *(uint *)&other->frameIndex =
           *(int *)&other->frameIndex + carryIn + (uint)CARRY2(healthOld,(uint)paVar3);
      ovc41_compute3((uint32_t)CONCAT22(in_stack_0000000c,other),retStorage,unaff_BP);
    }
  }
  return;
}



/* 6a8f:01e7 */

/* Marks an agent for death: steps the animFrame back and flags the agent list changed. */

void __cdecl16far ovc41_markAgentDead(agnt_t far *agnt)

{
  uint8_t *puVar1;
  entity_t *peVar2;
  
  if (DebugVerbose) {
    printf("kill 4\r");
  }
  peVar2 = ((agnt_t far *)agnt)->entity;
  if ((((entity_t *)peVar2)->base).animFrame != 0x0) {
    peVar2 = ((agnt_t far *)agnt)->entity;
    puVar1 = &(((entity_t *)peVar2)->base).animFrame;
    *puVar1 = *puVar1 + 0xff;
  }
  AgentsChanged = 1;
  return;
}



/* 6a8f:0229 */

/* [R1] forwards to OVC41_6a8f_01e7 */

void __cdecl16far OVC41_6a8f_01e7_entry(agnt_t far *agnt,uint16_t arg2)

{
  uint16_t in_stack_00000006;
  
  if ((agnt->flags & 0xae4) == 0) {
    ovc41_markAgentDead((agnt_t far *)CONCAT22(in_stack_00000006,agnt));
  }
  return;
}



/* 6a8f:0246 */

/* Increments the animFrame byte of the entity the agent belongs to. */

void __cdecl16far ovc41_advanceAnimFrame(agnt_t far *agnt,uint16_t arg2)

{
  uint8_t *puVar1;
  
  puVar1 = &(((entity_t *)agnt->entity)->base).animFrame;
  *puVar1 = *puVar1 + 0x1;
  return;
}



/* 6a8f:0256 */
void __cdecl16far ovc41_removeAgent(uint agntIndex,int notify,uint16_t arg3)

{
  /* Re-derived from 6a8f:0256.  The entity pointer is Agnts[i].entity, loaded with `les` in the
     original and used for y (+2), x (+0), targetX (+4), targetY (+6), destX (+8), destY (+0xa) and
     target (+0xc).  The export rebuilt it from the two halves of the field and cast them to a near
     entity_t*, which truncated and, for the offset half, produced segment 0. */
  byte *targetPtr;
  entity_t far *ent;
  int owner;
  bool sharedOwner;
  uint i;

  ent = Agnts[agntIndex].entity;
  owner = Agnts[agntIndex].owner;
  ovr_agnt_usesAgntCount4(agntIndex + 1);
  sharedOwner = false;
  for (i = 0; (int)i < (int)(uint)AgntCount; i = i + 1) {
    if ((i != agntIndex) && (Agnts[i].owner == owner)) {
      sharedOwner = true;
    }
    if (Agnts[i].target != -1) {
      if ((int)agntIndex < (int)(uint)Agnts[i].target) {
        targetPtr = (byte *)&Agnts[i].target;
        *targetPtr = *targetPtr + -1;
      }
      else if (Agnts[i].target == agntIndex) {
        Agnts[i].target = 0xff;
      }
    }
  }
  if ((int)(agntIndex + 1) < (int)(uint)AgntCount) {
    _fmemmove((char far *)MK_FP(SEG_OF(Agnts),(char *)&Agnts[agntIndex].x),
              (char far *)MK_FP(SEG_OF(Agnts),(char *)&Agnts[agntIndex + 1].x),
              ((AgntCount - agntIndex) + -1) * 0x34);
  }
  AgntCount = AgntCount - 1;
  if ((((notify != 0) && (!sharedOwner)) && (ent->base.y == GfxRndSeed2)) &&
     ((GfxRndSeed - 2U <= ent->base.x && (GfxRndSeed - 2U <= ent->base.x)))) {
    ent->base.destX = ent->base.targetX;
    ent->base.destY = ent->base.targetY;
    ovr_attact_usesRandBelow((agnt_t far *)ent,(byte)ent->base.target,0,0);
  }
  return;
}


/* 6a8f:0422 */

/* [R6] touches MenuItemEnabled */

uint16_t __cdecl16far ovc41_usesMenuItemEnabled(byte menuIndex,int gfxVariant)

{
  byte itemFlag;
  uint32_t itemPtr;
  uint16_t uVar3;
  
  if (((uint8_t *)MenuItemEnabled)[menuIndex] == 0xff) {
    uVar3 = 0x6e74;
  }
  else {
    itemPtr = *(uint32_t *)((uint)((uint8_t *)MenuItemEnabled)[menuIndex] << 2);
    itemFlag = *(byte *)((int)itemPtr + 0x2f);
    if (gfxVariant == 1) {
      uVar3 = *(uint16_t *)((uint)itemFlag * 4 + 0x123);
    }
    else {
      uVar3 = *(uint16_t *)((uint)itemFlag * 4 + 0x107);
    }
  }
  return uVar3;
}



/* 6a8f:04a9 */

/* Returns "is" for a count of 1 and "are" otherwise (verb agreement for formatted strings). */

char * __cdecl16far ovc41_isAre(int count)

{
  char *pcVar1;
  
  if (count == 1) {
    pcVar1 = (char *)"is";
  }
  else {
    pcVar1 = (char *)"are";
  }
  return pcVar1;
}



/* 6a8f:04c0 */

/* Builds the party's unit-status summary (count, recruiting, training and building percentages). */

void __cdecl16far ovc41_unitStatusText(byte menuIndex)

{
  char *isAreText;
  char *statusText;
  uint16_t *itemPtr;
  uint16_t agntSeg;
  uint16_t dst;
  uint agntIdx;
  int count;
  far_t pctOut;
  far_t remainderOut;
  ulong packedValue;
  far_t partOut;
  uint32_t screenAddr;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  uint8_t part;
  uint8_t remainder;
  uint8_t pct;
  
  agntSeg = 0x2410;
  if (((uint8_t *)MenuItemEnabled)[menuIndex] != 0xff) {
    count = 0;
    for (agntIdx = 0; agntIdx < AgntCount; agntIdx = agntIdx + 1) {
      agntSeg = SEG_OF(Agnts);
      if (((uint8_t *)MenuItemEnabled)[menuIndex] ==
          AGNT_FIELD(Agnts[agntIdx].entity, base.entity, 3)) {
        count = count + 1;
      }
    }
    partOut.seg = (uint16_t)_SS;
    partOut.ofs = (uint16_t)&part;
    remainderOut.seg = (uint16_t)_SS;
    remainderOut.ofs = (uint16_t)&remainder;
    pctOut.seg = (uint16_t)_SS;
    pctOut.ofs = (uint16_t)&pct;
    ovr_attact_compute2(CONCAT11((char)((uint)&pct >> 8),menuIndex),pctOut,remainderOut,partOut);
    screenAddr = CONCAT22(0xa000,(uint)pct);
    packedValue = (ulong)CONCAT12(remainder,(uint)part);
    isAreText = ovc41_isAre(count);
    itemPtr = (uint16_t *)((uint)((uint8_t *)MenuItemEnabled)[menuIndex] * 4);
    dst = _DS;
    ovc41_pluralSuffix(count,*itemPtr,itemPtr[1],isAreText,agntSeg,packedValue,screenAddr);
    statusText = ovr_stsprintf(msg,(char *)CONCAT22(0x6e86,_SS),
                           (char *)CONCAT22(count,(char *)0x26510),agntSeg,dst);
    ovr_drawTextAt(statusText,dst,0);
  }
  return;
}



/* 6a8f:05ad */

/* [R6] touches DebugVerbose */

void __cdecl16far ovc41_usesDebugVerbose(void)

{
  int col;
  int row;
  
  if (DebugVerbose) {
    for (row = 0; row < 10; row = row + 1) {
      for (col = 0; col < 0x69; col = col + 1) {
        *(char *)(row * 0x140 + col + -0x1280) = AgntArrayA[row][col] + '@';
      }
    }
    for (row = 0; row < 10; row = row + 1) {
      for (col = 0; col < 0x69; col = col + 1) {
        *(char *)(row * 0x140 + col + -0x120d) = AgntArrayB[row][col] + '@';
      }
    }
  }
  return;
}



/* 6a8f:063f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Applies the combat outcome to an agent: sets the dead state or restores its strength and timer.
    */

uint __cdecl16far ovc41_settleAgentCombat(agnt_t far *a,agnt_t far *b,uint16_t arg3)

{
  uint in_AX;
  uint uVar1;
  int ownerOfs;
  byte ofsHi;
  agnt_t far *agnt;
  
  agnt = (agnt_t far *)b;
  if (agnt->combatState == 0x2) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    if ((a != (agnt_t far *)0x0) && (((agnt_t far *)a)->gdata->ai == ((agnt_t far *)a)->faction)) {
      ovc41_compute4(*(agnt_t far **)&agnt->entity,(byte)*(uint16_t *)((int)&agnt->entity + 2),1,*(agnt_t far **)&((agnt_t far *)a)->entity,0,0,0,0);
    }
    if (((((((entity_t *)agnt->entity)->base).animFrame == 0x0) ||
         ((uint)(((entity_t *)agnt->entity)->base).animFrame % 0x10 == 1)) ||
        ((agnt->flags & 0xae4) != 0)) || ((((agntG_t far *)agnt->gdata)->flags2 & 4) != 0)) {
      agnt->strength = 0x0;
      agnt->timer = 0xa;
      agnt->combatState = 0x2;
      agnt->targetY = 0;
    }
    else {
      agnt->strength = ((agntG_t far *)agnt->gdata)->strength;
      agnt->timer = 0x6;
      agnt->combatState = 0x1;
      agnt->targetY = 0;
    }
    ovr_agnt_usesAnimFrame(agnt);
    ownerOfs = agnt->owner * 0x37;
    ofsHi = (byte)((uint)ownerOfs >> 8);
    ovr_ovc25_attackingNotice(*(byte *)((int)Entities + ownerOfs + 0x1a));
    if ((agnt->flags & 0xae4) == 0) {
      ovc41_markAgentDead(b);
      uVar1 = CONCAT11(ofsHi,1);
    }
    else {
      uVar1 = (uint)ofsHi << 8;
    }
  }
  return uVar1;
}



/* 6a8f:076f */

/* [R4] calls ovr_play_sfxU */

void __cdecl16far ovc41_usesPlay_sfxU(void)

{
  uint *puVar1;
  uint16_t unk;
  int iVar2;

  if (AgntFlag1) {
    for (iVar2 = 0; iVar2 < (int)(uint)AgntCount; iVar2 = iVar2 + 1) {
      if ((Agnts[iVar2].flags & 0x800) == 0) {
        OVC41_6a8f_01e7_entry((agnt_t far *)&Agnts[iVar2].x,SEG_OF(Agnts));
        puVar1 = (uint *)&Agnts[iVar2].flags;
        *puVar1 = *puVar1 | 0x800;
        unk = ovr_audio_panFromX((agnt_t far *)&Agnts[iVar2].x,SEG_OF(Agnts));
        ovr_play_sfxU(0x1b,0,unk,0,0);
        ovr_attact_usesEntityCount();
        return;
      }
    }
  }
  return;
}



/* 6a8f:0807 */
void __cdecl16far ovc41_paralyzeNearbyAgents(int agntIndex)

{
  /* Re-derived: when the agent's gdata has flag 4 set, every other agent within 0x31 columns
     is struck - a 6d6 roll, halved when the to-hit test succeeds - and handed to
     ovc41_textParalyzed for both this agent and the target. */
  byte diceRoll;
  agnt_t far *agntBase;
  uint dx;
  uint dxSign;
  int hitResult;
  int otherIdx;
  uint rollVal;
  entity_t *agntPtr;

  agntBase = (agnt_t far *)&Agnts[agntIndex].x;
  agntPtr = (agnt_t far *)MK_FP(SEG_OF(Agnts),agntBase);
  if ((((agntG_t far *)agntBase->gdata)->flags2 & 4) != 0) {
    for (otherIdx = 0; otherIdx < (int)(uint)AgntCount; otherIdx = otherIdx + 1) {
      if ((otherIdx != agntIndex) &&
         (dx = agntPtr->base.x - Agnts[otherIdx].x, dxSign = (int)dx >> 0xf,
         (int)((dx ^ dxSign) - dxSign) < 0x32)) {
        diceRoll = ovr_manage_rollDice('\x06','\x06');
        rollVal = (uint)diceRoll;
        hitResult = ovr_ovc27_rollToHitEntity(CONCAT22(SEG_OF(Agnts),otherIdx * 0x34),1);
        if ((char)hitResult != '\0') {
          rollVal = (int)rollVal >> 1;
        }
        ovc41_textParalyzed((agnt_t far *)MK_FP(SEG_OF(Agnts),agntBase),
                            (agnt_t far *)MK_FP(SEG_OF(Agnts),
                                               (agnt_t far *)&Agnts[otherIdx].x),rollVal,0,0,0);
      }
    }
  }
  return;
}


/* 6a8f:08c2 */

/* [R6] touches xOfs */

void __cdecl16far ovc41_usesXOfs(int agntIndex)

{
  uint targetIdx;
  far_t dst;
  int iStack_c;
  uint8_t xOfs;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)&xOfs;
  F_SCOPY(far_from_u32((uint32_t)(0x24106e00)),dst,8);
  targetIdx = (uint)Agnts[agntIndex].target;
  iStack_c = Agnts[agntIndex].targetY;
  if (2 < iStack_c) {
    iStack_c = 3;
  }
  if (Agnts[agntIndex].level == '\0') {
    Agnts[targetIdx].x = Agnts[agntIndex].x + *(int *)(&xOfs + iStack_c * 2);
  }
  else {
    Agnts[targetIdx].x = Agnts[agntIndex].x - *(int *)(&xOfs + iStack_c * 2);
  }
  if (0xd2 < Agnts[targetIdx].x) {
    Agnts[targetIdx].x = 0xd2;
  }
  if (Agnts[targetIdx].x < 0) {
    Agnts[targetIdx].x = 0;
  }
  Agnts[targetIdx].y = Agnts[agntIndex].y;
  AGNT_FIELD(&Agnts[targetIdx], targetX, 1) = 0;
  AGNT_FIELD(&Agnts[targetIdx], targetX, 0) = 0;
  return;
}



/* 6a8f:0a45 */

/* [R7] body shape: compute */

uint16_t __cdecl16far ovc41_compute6(byte rank,uint8_t level)

{
  byte baseRank;
  uint16_t packed;
  undefined1 packHi;
  
  baseRank = ovr_agnt_compute14(level);
  if (baseRank + 2 < (uint)rank) {
    packed = CONCAT11((char)(baseRank + 2 >> 8),0xd);
  }
  else if (baseRank + 2 == (uint)rank) {
    packed = CONCAT11((char)(baseRank + 2 >> 8),0xb);
  }
  else {
    packHi = (undefined1)(baseRank + 1 >> 8);
    if (baseRank + 1 == (uint)rank) {
      packed = CONCAT11(packHi,9);
    }
    else if (baseRank == rank) {
      packed = CONCAT11(packHi,7);
    }
    else {
      packed = CONCAT11(packHi,2);
    }
  }
  return packed;
}



/* 6a8f:0aa7 */

/* Rolls 2d6/3d6/4d6 depending on the margin between the value and its target. */

void __cdecl16far ovc41_rollStatDice(byte rank,uint8_t level)

{
  byte bVar1;
  
  bVar1 = ovr_agnt_compute14(level);
  if (bVar1 + 1 < rank + 0xf) {
    if (bVar1 + 1 < rank + 10) {
      ovr_manage_rollDice('\x02','\x06');
    }
    else {
      ovr_manage_rollDice('\x03','\x06');
    }
  }
  else {
    ovr_manage_rollDice('\x04','\x06');
  }
  return;
}



/* 6a8f:0b0a */

/* [R7] body shape: compute */

int __cdecl16far ovc41_compute8(byte rank,uint8_t level)

{
  byte baseRank;
  byte packHi;
  int iVar2;
  
  baseRank = ovr_agnt_compute14(level);
  packHi = (byte)(rank + 4 >> 8);
  if (baseRank + 1 < rank + 4) {
    iVar2 = (uint)packHi << 8;
  }
  else {
    iVar2 = CONCAT11(packHi,1);
  }
  return iVar2;
}



/* 6a8f:0b39 */

/* Rolls the turn-undead attempt and reports its result. */

int __cdecl16far ovc41_turnUndeadNotice(agnt_t far *agnt)

{
  /* Re-derived from 6a8f:0b39 (1160 bytes).  Clears the agent's health and its "2" flag, then rolls
     2d6 against the target's rank ladder: on a success the target is reported as turned, otherwise
     every enemy within range loses a level per hit until the budget runs out.

     The agent, `gdata` and `entity` chains are three chained far loads in the original
     (`les bx,es:[bx+0x1d]` then `mov al,es:[bx+0x42]`), so the field accesses below are direct struct
     reads.  The export truncated those pointers through `uint32_t` locals and `(int)` casts.

     Every exit writes only AL and the caller reads the low byte, so the returns are plain 0 / 1.

     The argument lists of agnt_statusText / usesStshRealloc / stsprintf / uiNotify / play_sfxU are
     kept exactly as exported: their push sequences here are interleaved with buffer setup that is not
     yet established, so they are not reinterpreted. */
  uint *flagsWord;
  char diceRoll;
  uint16_t diceTarget;
  uint8_t *allocPtr;
  uint levelBudget;
  char *textPtr;
  uint16_t roll;
  uint16_t notifyValue;
  uint32_t extraArg;
  uint8_t text;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  byte targetRank;
  byte hitCount;
  char spotResult;
  char attacksLeft;
  int i;

  textPtr = (char *)SEG_OF(agnt);
  if ((agnt->flags & 2) == 0) {
    return 0;
  }
  agnt->health = 0x0;
  agnt->flags = agnt->flags & 0xfffd;
  if (agnt->target == 0xff) {
    return 0;
  }
  targetRank = Agnts[agnt->target].gdata->rank;
  if (targetRank == 0) {
    return 0;
  }
  diceRoll = ovr_manage_rollDice('\x02','\x06');
  roll = (uint16_t)(uint8_t)diceRoll;
  diceTarget = ovc41_compute6(Agnts[agnt->target].gdata->rank,
                              agnt->entity->base.level);
  if ((byte)roll < (byte)diceTarget) {
    textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT13((char)((uint)&text >> 8),
                                                        CONCAT12((char)&text,textPtr)),0);
    allocPtr = ovr_ovc15_usesStshRealloc(textPtr,roll,0,0,0,0,0,0);
    textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x6ed6,_SS),
                            (char *)CONCAT13((char)((uint)allocPtr >> 8),
                                             CONCAT12((char)allocPtr,0x2410)),(char)allocPtr,roll
                           );
    ovr_uiNotify(textPtr,roll,0);
    ovr_agnt_usesAnimFrame(agnt);
    return 1;
  }
  targetRank = Agnts[agnt->target].gdata->rank;
  levelBudget = (uint)targetRank;
  ovc41_rollStatDice(targetRank,agnt->entity->base.level);
  levelBudget = levelBudget & 0xff;
  spotResult = (char)ovc41_compute8(Agnts[agnt->target].gdata->rank,
                                    agnt->entity->base.level);
  hitCount = 0;
  i = 0;
  while ((i < (int)(uint)AgntCount && (levelBudget != 0))) {
    if (((Agnts[i].gdata->rank != '\0') &&
        ((((Agnts[i].faction != agnt->faction &&
           ((Agnts[i].flags & 4) == 0)) &&
          (Agnts[i].combatState == '\0')) &&
         ((hitCount == 0 ||
          ((int)(uint)Agnts[i].entity->base.level <= (int)levelBudget)))))) &&
       (Agnts[i].gdata->rank <= targetRank)) {
      if ((Agnts[i].flags & 0xae4) == 0) {
        attacksLeft = (char)Agnts[i].entity->base.animFrame;
      }
      else {
        attacksLeft = '\x01';
      }
      while ((attacksLeft != '\0' && (levelBudget != 0))) {
        if (spotResult == '\0') {
          OVC41_6a8f_01e7_entry((agnt_t far *)&Agnts[i].x,0);
          AGNT_FIELD(&Agnts[i], targetX, 0) = 0;
          AGNT_FIELD(&Agnts[i], targetX, 1) = 0;
          flagsWord = (uint *)&Agnts[i].flags;
          *flagsWord = *flagsWord | 4;
          Agnts[i].combatState = 1;
          Agnts[i].targetY = 0;
          Agnts[i].timer = 5;
          ovr_agnt_usesAnimFrame((agnt_t far *)&Agnts[i].x);
        }
        else {
          ovc41_settleAgentCombat(agnt,(agnt_t far *)MK_FP(SEG_OF(Agnts),(agnt_t far *)&Agnts[i].x),0);
        }
        hitCount = hitCount + 1;
        if ((int)levelBudget < (int)(uint)Agnts[i].entity->base.level) {
          levelBudget = 0;
        }
        else {
          levelBudget = levelBudget - Agnts[i].entity->base.level;
        }
        attacksLeft = attacksLeft + -1;
      }
    }
    notifyValue = SEG_OF(Agnts);
    i = i + 1;
  }
  if (hitCount == 0) {
    textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT13((char)((uint)&text >> 8),
                                                        CONCAT12((char)&text,textPtr)),0);
    allocPtr = ovr_ovc15_usesStshRealloc(textPtr,notifyValue,0,0,0,0,0,0);
    textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x6ee8,_SS),
                            (char *)CONCAT13((char)((uint)allocPtr >> 8),
                                             CONCAT12((char)allocPtr,0x2410)),(char)allocPtr,
                            notifyValue);
    ovr_uiNotify(textPtr,notifyValue,0);
  }
  else {
    if (spotResult == '\0') {
      extraArg = CONCAT22(GSavedBlitSeg,(uint)hitCount);
      textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&text,textPtr),0);
      allocPtr = ovr_ovc15_usesStshRealloc(textPtr,(char)notifyValue,extraArg,0,0,0,0,0);
      textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x6f0f,_SS),
                              (char *)CONCAT22(allocPtr,(char *)0x26510),(char)notifyValue
                             );
      ovr_uiNotify(textPtr,notifyValue,0);
    }
    else {
      extraArg = CONCAT22(GSavedBlitSeg,(uint)hitCount);
      textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&text,textPtr),0);
      allocPtr = ovr_ovc15_usesStshRealloc(textPtr,(char)notifyValue,extraArg,0,0,0,0,0);
      textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x6ef8,_SS),
                              (char *)CONCAT22(allocPtr,(char *)0x26510),(char)notifyValue
                             );
      ovr_uiNotify(textPtr,notifyValue,0);
    }
    notifyValue = ovr_audio_panFromX(agnt,0);
    ovr_play_sfxU(0x3b,0,notifyValue,0,0);
  }
  ovr_agnt_usesAnimFrame(agnt);
  return 1;
}



/* 6a8f:0fc1 */

/* Formats the "Building %d %s." notice. */

void __cdecl16far ovc41_buildingNotice(char delta)

{
  int unitIdx;
  char *msg;
  uint16_t unitsSeg;
  static char text[64];   /* DGROUP-backed formatting buffer */
  byte bStack_3;
  
  unitIdx = ((short (*) [148] [60])GUnitGrid)[-1][GfxRndSeed + 0x93][GfxRndSeed2];
  if (0xf7 < unitIdx) {
    unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
    bStack_3 = (GUnits + unitIdx)->bldType + delta;
    if (0xf7 < bStack_3) {
      bStack_3 = 0;
    }
    (GUnits + unitIdx)->bldType = bStack_3;
    ovr_constr_flushDirtyRects();
    msg = ovr_stsprintf(text,(char *)CONCAT22(0x6f23,_SS),
                        (char *)(ulong)CONCAT12(bStack_3,(char *)0x26510),
                        BLD_WORD(&BuildingTypes[bStack_3], name, 0),
                        BLD_WORD(&BuildingTypes[bStack_3], name, 2));
    asm { mov unitsSeg,dx };
    ovr_say(msg,unitsSeg);
  }
  return;
}



/* 6a8f:108a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far dbgPromoteEnemy(void)

{
  char *pcVar1;
  char *msg;
  int iVar2;
  uint16_t i;
  uint16_t uVar3;
  char buf [80];
  
  for (i = 0; i < EntityCount; i = i + 1) {
    uVar3 = (uint16_t)((ulong)Entities >> 0x10);
    if (((GfxRndSeed - 2U <= *(uint *)((entity_t far *)Entities + i)) &&
        (*(uint *)((entity_t far *)Entities + i) <= GfxRndSeed + 1U)) &&
       (((entity_t far *)Entities)[i].base.y == GfxRndSeed2)) {
      pcVar1 = (char *)((uint8_t *)&(Entities)[i] + 0xd);
      *pcVar1 = *pcVar1 + '\x01';
      uVar3 = (uint16_t)((ulong)Entities >> 0x10);
      if (0x29 < (Entities)[i].base.gindex) {
        (Entities)[i].base.gindex = 0;
      }
      msg = ovr_stsprintf((char far *)buf,(char far *)"Enemy %s.",
                          AgntGs[(Entities)[i].base.gindex].name);
      asm { mov uVar3,dx };
      ovr_say(msg,uVar3);
    }
  }
  TextBlitFlag = 0;
  AgntFlag1 = false;
  ovc41_usesAgnt_clear('\x01');
  return;
}



/* 6a8f:11d2 */

/* [R4] calls ovr_agnt_clear */

void __cdecl16far ovc41_usesAgnt_clear(char playSound)

{
  bool bVar1;
  int menuIndex;
  
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  if (((playSound != '\0') && (CFG_Sfx != '1')) && (CFG_Sfx != '4')) {
    ovr_play_sfx(6,0,0);
  }
  ovr_unit_usesAlignUp4();
  GOngoingBattle = GBattleMode;
  if (GBattleMode == '\0') {
    bVar1 = ovr_draw_textArena();
    if (!bVar1) {
      GOngoingBattle = '\x01';
    }
  }
  ovr_ovc28_usesBlitGfxRect2();
  ovr_gfxInitRand();
  GGameState = 9;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  ovr_resetTextBlitCycle();
  GGameState = 10;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  ovr_agnt_clear();
  GGameState = 0xb;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  ovr_constr_usesBlitRect4();
  GGameState = 0xc;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  ovr_attact_usesSquareRecCount2();
  GGameState = 0xd;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  TextBlitDstSeg = 0xa000;
  if (GameRunning == false) {
    for (menuIndex = 0; menuIndex < 5; menuIndex = menuIndex + 1) {
      ovr_draw_usesBlitLoadRleGfx3(menuIndex);
      ovr_draw_menuRowBar(menuIndex,0xa000);
    }
    GGameState = 0xe;
    if (DebugVerbose != false) {
      printf("%d \r",GGameState);
    }
  }
  GGameState = 0xf;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  ovr_ovc18_showLeaderView();
  GGameState = 0x10;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  ovc41_initIndexPerms();
  GGameState = 0x11;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  if (trianglesShown == '\0') {
    ovc41_removeIndexPerm(8);
  }
  GGameState = 0x12;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  GGameState = 0x13;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  ovr_draw_toolbarLabels();
  GGameState = 0x14;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  if ((GPaused != '\0') && (GOngoingBattle == '\0')) {
    ovr_update_pause_button();
  }
  return;
}



/* 6a8f:1520 */

/* Clears the agents, redraws the five menu bars and opens the leader view. */

void __cdecl16far ovc41_enterLeaderView(void)

{
  int menuIndex;
  
  ovr_gfxInitRand();
  ovr_resetTextBlitCycle();
  ovr_agnt_clear();
  ovr_attact_usesSquareRecCount2();
  TextBlitDstSeg = 0xa000;
  for (menuIndex = 0; menuIndex < 5; menuIndex = menuIndex + 1) {
    ovr_draw_usesBlitLoadRleGfx3(menuIndex);
    ovr_draw_menuRowBar(menuIndex,0xa000);
  }
  ovr_ovc18_showLeaderView();
  ovc41_initIndexPerms();
  if (trianglesShown == '\0') {
    ovc41_removeIndexPerm(8);
  }
  GMenuItem = savedMenuItem;
  ovr_draw_toolbarLabels();
  return;
}



/* 6a8f:15a0 */
void __cdecl16far ovc41_usesBiosKeyAvail(uint8_t dir,uint16_t coarse)

{
  /* 6a8f:15a0, re-derived.  Scroll the leader-view backdrop: a coarse step (eight pixels, sixteen
     vertically) when `coarse` is set, then a fine step (one pixel, four vertically).  A coarse step
     consumes the direction (dir = 0xff), so the fine switch then matches nothing; a fine step that
     would leave the valid range returns immediately, without the tail.  Each step sets
     bigcompFrame to 0/2/4/6 (left/up/right/down) and redraws the toolbar labels and the agent flag
     view.  The tail emits the pending text, clears TextBlitFlag/AgntFlag1 and re-enters the main
     loop by way of GGameState 0x33 -> ovc41_usesAgnt_clear(1) -> 0x35. */
  ovr_blitLoadRleGfx(FontHandle,0xc31d,0xa000);
  if (coarse != 0 && dir <= 3) {
    switch (dir) {
    case 0:
      if (8 < GfxRndSeed2) {
        bigcompFrame = 0;
        ovr_draw_toolbarLabels();
        ovr_attact_usesAgntFlag1();
        GfxRndSeed2 = GfxRndSeed2 - 8;
        dir = 0xff;
      }
      break;
    case 1:
      if ((int16_t)(GfxRndSeed + 0x11) < 0x94) {
        bigcompFrame = 2;
        ovr_draw_toolbarLabels();
        ovr_attact_usesAgntFlag1();
        GfxRndSeed = GfxRndSeed + 0x10;
        dir = 0xff;
      }
      break;
    case 2:
      if ((int16_t)(GfxRndSeed2 + 8) <= 0x39) {
        bigcompFrame = 4;
        ovr_draw_toolbarLabels();
        ovr_attact_usesAgntFlag1();
        GfxRndSeed2 = GfxRndSeed2 + 8;
        dir = 0xff;
      }
      break;
    case 3:
      if ((int16_t)(GfxRndSeed + 0xffef) >= 0) {
        bigcompFrame = 6;
        ovr_draw_toolbarLabels();
        ovr_attact_usesAgntFlag1();
        GfxRndSeed = GfxRndSeed - 0x10;
        dir = 0xff;
      }
      break;
    }
  }
  if (dir <= 3) {
    switch (dir) {
    case 0:
      if (GfxRndSeed2 == 0) return;
      bigcompFrame = 0;
      ovr_draw_toolbarLabels();
      ovr_attact_usesAgntFlag1();
      GfxRndSeed2--;
      break;
    case 1:
      if (0x94 <= (int16_t)(GfxRndSeed + 5)) return;
      bigcompFrame = 2;
      ovr_draw_toolbarLabels();
      ovr_attact_usesAgntFlag1();
      GfxRndSeed = GfxRndSeed + 4;
      break;
    case 2:
      if (0x39 < (int16_t)(GfxRndSeed2 + 1)) return;
      bigcompFrame = 4;
      ovr_draw_toolbarLabels();
      ovr_attact_usesAgntFlag1();
      GfxRndSeed2++;
      break;
    case 3:
      if ((int16_t)GfxRndSeed < 6) return;
      bigcompFrame = 6;
      ovr_draw_toolbarLabels();
      ovr_attact_usesAgntFlag1();
      GfxRndSeed = GfxRndSeed - 4;
      break;
    }
  }
  if (TextBlitFlag != 0) {
    ovr_say((char *)0x6e74,0);
  }
  TextBlitFlag = 0;
  AgntFlag1 = false;
  GGameState = 0x33;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  ovc41_usesAgnt_clear(1);
  GGameState = 0x35;
  if (DebugVerbose != false) {
    printf("%d \r",GGameState);
  }
  return;
}


/* 6a8f:1847 */

/* Prints the "You cannot see the terrain here." notice. */

void __cdecl16far ovc41_cannotSeeTerrainNotice(void)

{
  bool bVar1;
  
  GBattleMode = '\x01' - (GBattleMode != '\0');
  GOngoingBattle = GBattleMode;
  ovr_ovc28_blitButton();
  bVar1 = ovr_draw_textArena();
  if (bVar1) {
    ovr_agnt_clear();
    ovr_constr_usesBlitRect4();
    if (GOngoingBattle != '\0') {
      ovr_stop_audio();
    }
    ovr_update_pause_button();
  }
  else {
    GOngoingBattle = '\x01';
    ovr_say((char *)"You cannot see the terrain here.",0x2410);
    ovr_stop_audio();
  }
  return;
}



/* 6a8f:18c6 */
void __cdecl16far ovc41_usesGMenuItem(void)

{
  ovr_draw_usesBlitLoadRleGfx2();
  GMenuItem = savedMenuItem;
  MenuMode = MenuModeSaved;
  ovc41_usesAgnt_clear('\0');
  if (5 < GMenuItem) {
    GMenuItem = 5;
  }
  while ((GMenuItem != 5 && (((uint8_t *)MenuItemEnabled)[GMenuItem] == 0xff))) {
    if (GMenuItem == 0) {
      GMenuItem = 5;
    }
    else {
      GMenuItem = GMenuItem - 1;
    }
  }
  if (GameRunning == false) {
    ovr_draw_toolbarLabels();
  }
  ovr_draw_textTalkwin9Lbm();
  (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter) + 2)) = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter))) = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
  return;
}


/* 6a8f:199c */

void __cdecl16far uiMainMenu(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  savedMenuItem = GMenuItem;
  MenuModeSaved = MenuMode;
  gfx.seg = nwpanel1Cut2Seg;
  gfx.ofs = nwpanel1Cut2Ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000e249)),0);
  gfx_00.seg = trianglsCut6Seg;
  gfx_00.ofs = trianglsCut6Ofs;
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa000e249)),0);
  ovr_uiMainMenuLoop();
  gfx_01.seg = nwpanel1Cut2Seg;
  gfx_01.ofs = nwpanel1Cut2Ofs;
  ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000e249)),0);
  gfx_02.seg = trianglsCut5Seg;
  gfx_02.ofs = trianglsCut5Ofs;
  ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)(0xa000e249)),0);
  ovc41_usesGMenuItem();
  return;
}



/* 6a8f:1a4c */

/* Initialises the four index-permutation tables (IndexPermA..D) from the static 12-byte blocks. */

void __cdecl16far ovc41_initIndexPerms(void)

{
  _fmemmove(&IndexPermD,(char far *)MK_FP(0x2410,0x6e08),0xc);
  _fmemmove(&IndexPermC,(char far *)MK_FP(0x2410,0x6e14),0xc);
  _fmemmove(&IndexPermB,(char far *)MK_FP(0x2410,0x6e20),0xc);
  _fmemmove(&IndexPermA,(char far *)MK_FP(0x2410,0x6e2c),0xc);
  return;
}



/* 6a8f:1aa1 */

/* Rewrites the four 12-entry index-permutation tables to drop references to one index. */

void __cdecl16far ovc41_removeIndexPerm(uint removedIndex)

{
  undefined1 permByte;
  uint permIdx;
  
  for (permIdx = 0; (int)permIdx < 0xc; permIdx = permIdx + 1) {
    if (permIdx != removedIndex) {
      permByte = (undefined1)permIdx;
      if ((byte)((undefined1 *)&IndexPermD)[permIdx] == removedIndex) {
        if ((byte)((undefined1 *)&IndexPermD)[removedIndex] == removedIndex) {
          ((undefined1 *)&IndexPermD)[permIdx] = permByte;
        }
        else {
          ((undefined1 *)&IndexPermD)[permIdx] = ((undefined1 *)&IndexPermD)[removedIndex];
        }
      }
      if ((byte)((undefined1 *)&IndexPermC)[permIdx] == removedIndex) {
        if ((byte)((undefined1 *)&IndexPermC)[removedIndex] == removedIndex) {
          ((undefined1 *)&IndexPermC)[permIdx] = permByte;
        }
        else {
          ((undefined1 *)&IndexPermC)[permIdx] = ((undefined1 *)&IndexPermC)[removedIndex];
        }
      }
      if ((byte)((undefined1 *)&IndexPermB)[permIdx] == removedIndex) {
        if ((byte)((undefined1 *)&IndexPermB)[removedIndex] == removedIndex) {
          ((undefined1 *)&IndexPermB)[permIdx] = permByte;
        }
        else {
          ((undefined1 *)&IndexPermB)[permIdx] = ((undefined1 *)&IndexPermB)[removedIndex];
        }
      }
      if ((byte)((undefined1 *)&IndexPermA)[permIdx] == removedIndex) {
        if ((byte)((undefined1 *)&IndexPermA)[removedIndex] == removedIndex) {
          ((undefined1 *)&IndexPermA)[permIdx] = permByte;
        }
        else {
          ((undefined1 *)&IndexPermA)[permIdx] = ((undefined1 *)&IndexPermA)[removedIndex];
        }
      }
    }
  }
  return;
}



/* 6a8f:1be0 */

/* [R4] calls ovr_miceBlitRect */

void __cdecl16far ovc41_usesMiceBlitRect(uint menuIndex)

{
  bool bVar1;
  
  bVar1 = MiceNeedsUpdate == '\0';
  if (bVar1) {
    ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
  }
  TextBlitDstSeg = 0xa000;
  if (GMenuItem == menuIndex) {
    ovr_draw_usesFillRect2((uint)((uint8_t *)menuItemRow)[GMenuItem],-0x6000);
  }
  ovr_draw_menuRowBar(menuIndex,0xa000);
  if (bVar1) {
    ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x2410);
  }
  return;
}



/* 6a8f:1c74 */

/* [R2] string "%s is paralyzed by %s." */

undefined1 __cdecl16far ovc41_textParalyzed(agnt_t far *source,agnt_t far *victim,uint strength,uint16_t arg4,uint16_t arg5,uint16_t arg6)

{
  uint hitResult;
  char *textPtr;
  int pan;
  uint8_t *stashOfs;
  uint16_t stashSeg;
  uint16_t sfxPan;
  uint16_t roll;
  uint16_t in_DX;
  agnt_t far *agnt;
  agnt_t far *agnt_00;
  char *victimSegWord;
  char *statusText;
  char *notifyText;
  uint16_t sourceSeg;
  undefined1 textLo;
  undefined1 panHi;
  undefined1 savedSeg;
  undefined1 victimSeg;
  undefined1 panLo;
  undefined1 blitSegLo;
  uint8_t victimName;
  uint8_t sourceName;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  undefined1 resolved;
  
  resolved = 0;
  victimSegWord = (char *)((ulong)victim >> 0x10);
  agnt = (agnt_t far *)victim;
  if ((agnt->flags & 0x80) != 0) {
    strength = (uint)agnt->strength;
  }
  agnt_00 = (agnt_t far *)source;
  sourceSeg = (uint16_t)((ulong)source >> 0x10);
  victimSeg = (undefined1)((ulong)victim >> 0x10);
  if ((int)strength < (int)(uint)agnt->strength) {
    agnt->timer = 0x6;
    agnt->combatState = 0x1;
    agnt->targetY = 0;
    ovr_agnt_usesAnimFrame(agnt,victimSeg);
    if (((agnt->animVariant == 0x0) && ((agnt->flags & 0x200) == 0)) &&
       ((((agntG_t far *)agnt_00->gdata)->flags & 0x40) != 0)) {
      savedSeg = (undefined1)GSavedBlitSeg;
      textPtr = ovr_agnt_statusText(agnt_00,(char *)CONCAT13((char)((uint)&victimName >> 8),
                                                            CONCAT12((char)&victimName,sourceSeg)),0);
      textLo = SUB21(textPtr,0);
      stashSeg = in_DX;
      textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&sourceName,victimSegWord),0);
      stashOfs = ovr_ovc15_usesStshRealloc(textPtr,in_DX,textLo,stashSeg,savedSeg,0,0,0);
      textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x6f63,_SS),
                             (char *)CONCAT22(stashOfs,(char *)0x26510),in_DX);
      ovr_uiNotify(textPtr,in_DX,0);
      sfxPan = ovr_audio_panFromX(agnt,victimSeg);
      ovr_play_sfxU(3,0,sfxPan,(char)sfxPan,0);
      OVC41_6a8f_01e7_entry(agnt,victimSeg);
      agnt->flags = agnt->flags | 0x200;
      ovr_attact_usesLDIV_at_2();
      return resolved;
    }
    if (((agnt->animVariant == 0x0) && ((agnt->flags & 0x800) == 0)) &&
       (((((agntG_t far *)agnt_00->gdata)->flags3 & 0x100) != 0 &&
        (hitResult = ovr_ovc27_rollToHitEntity((uint32_t)victim,2), (hitResult & 0xff) == 0)))) {
      savedSeg = (undefined1)GSavedBlitSeg;
      textPtr = ovr_agnt_statusText(agnt_00,(char *)CONCAT13((char)((uint)&victimName >> 8),
                                                            CONCAT12((char)&victimName,sourceSeg)),0);
      textLo = SUB21(textPtr,0);
      stashSeg = in_DX;
      textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&sourceName,victimSegWord),0);
      stashOfs = ovr_ovc15_usesStshRealloc(textPtr,in_DX,textLo,stashSeg,savedSeg,0,0,0);
      textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x6f7a,_SS),
                             (char *)CONCAT22(stashOfs,(char *)0x26510),in_DX);
      ovr_uiNotify(textPtr,in_DX,0);
      agnt->flags = agnt->flags | 0x800;
      sfxPan = ovr_audio_panFromX(agnt,victimSeg);
      ovr_play_sfxU(0x1b,0,sfxPan,(char)sfxPan,0);
      OVC41_6a8f_01e7_entry(agnt,victimSeg);
      ovr_attact_usesLDIV_at_2();
      return resolved;
    }
    agnt->strength = agnt->strength - (char)strength;
    if (((((agntG_t far *)agnt_00->gdata)->flags & 0x8000) == 0) ||
       ((((agntG_t far *)agnt->gdata)->flags & 0x8000) == 0)) {
      if (((agntG_t far *)agnt_00->gdata)->hitSound == 0) {
        pan = ovr_audio_panFromX(agnt,victimSeg);
        panLo = (undefined1)pan;
        panHi = (undefined1)((uint)pan >> 8);
        pan = 0;
        roll = ovr_randBelow(2,0);
        ovr_play_sfxU((char)roll + 0x3d,pan,CONCAT11(panHi,panLo),panLo,0);
      }
      else if (((agntG_t far *)agnt_00->gdata)->hitSound == 0x15) {
        roll = ovr_randBelow(2,0);
        if ((roll & 0xff) == 0) {
          ovr_play_sfx(21,0,0);
        }
        else {
          ovr_play_sfx(71,0,0);
        }
      }
      else if (((agntG_t far *)agnt_00->gdata)->hitSound == 3) {
        pan = ovr_audio_panFromX(agnt,panLo);
        panLo = (undefined1)pan;
        panHi = (undefined1)((uint)pan >> 8);
        pan = 0;
        roll = ovr_randBelow(2,0);
        ovr_play_sfxU((char)roll + 0x14,pan,CONCAT11(panHi,panLo),panLo,0);
      }
      else {
        ovr_play_sfx((uint)((agntG_t far *)agnt_00->gdata)->hitSound,0,0);
      }
    }
    else {
      pan = ovr_audio_panFromX(agnt,panLo);
      panLo = (undefined1)pan;
      panHi = (undefined1)((uint)pan >> 8);
      pan = 0;
      roll = ovr_randBelow(2,0);
      ovr_play_sfxU((char)roll + 0x14,pan,CONCAT11(panHi,panLo),panLo,0);
    }
    if ((agnt_00->flags & 0x20) != 0) {
      agnt_00->flags = agnt_00->flags & 0xffdf;
      blitSegLo = (undefined1)GSavedBlitSeg;
      statusText = ovr_agnt_statusText(agnt,(char *)CONCAT13((char)((uint)&sourceName >> 8),
                                                         CONCAT12((char)&sourceName,victimSegWord)),0);
      stashOfs = ovr_ovc15_usesStshRealloc(statusText,in_DX,blitSegLo,0,0,0,0,0);
      notifyText = ovr_stsprintf(msg,(char *)CONCAT22(0x6f8e,_SS),
                             (char *)CONCAT13((char)((uint)stashOfs >> 8),
                                              CONCAT12((char)stashOfs,0x2410)),(char)stashOfs,in_DX);
      ovr_uiNotify(notifyText,in_DX,0);
      agnt_00->faction = agnt_00->gdata->ai;
      ovc41_advanceAnimFrame(agnt_00,(char)((ulong)source >> 0x10));
      ovr_attact_usesLDIV_at_2();
    }
  }
  else {
    if (((agntG_t far *)agnt->gdata)->actSound == 0xff) {
      sfxPan = ovr_audio_panFromX(agnt,blitSegLo);
      ovr_play_sfxU(4,0,sfxPan,(char)sfxPan,0);
    }
    else {
      sfxPan = ovr_audio_panFromX(agnt,blitSegLo);
      ovr_play_sfxU(((agntG_t far *)agnt->gdata)->actSound,0,sfxPan,(char)sfxPan,0);
    }
    ovc41_settleAgentCombat(source,victim,0);
    resolved = 1;
  }
  ovr_attact_usesLDIV_at_2();
  return resolved;
}



/* 6a8f:2084 */

/* Heals one unit and reports it.  Re-derived from the image; the former body carried 546 lines and
   71 calls for a 438-byte function, including an unrelated texture/mouse section. */

byte * __cdecl16far ovc41_textOnlyPlaceSingle(agnt_t far *agnt,int entityIndex)

{
  far_t curePtrs[4];
  agnt_t far *ent;
  uint8_t level;
  uint16_t healed;
  uint16_t old;
  uint16_t delta;
  uint16_t total;
  uint16_t pan;
  char far *text1;
  char far *text2;
  char far *stash;
  char far *msg;
  char far *pluralA;
  char far *pluralB;
  char buf1[0x80];
  char buf2[0x50];
  char buf3[0x78];
  int i;

  for (i = 0; i < 4; i++) {
    curePtrs[i] = CureSpellPtrs[i];
  }
  ent = &Agnts[entityIndex];
  if ((ent->flags & 0x820) != 0) {
    return (byte *)ent;
  }
  agnt->flags = agnt->flags & ~0x800;
  if (((entity_t far *)agnt->entity)->base.level < 8) {
    level = 0;
  }
  else if (((entity_t far *)agnt->entity)->base.level < 0xa) {
    level = 1;
  }
  else if (((entity_t far *)agnt->entity)->base.level < 0xc) {
    level = 2;
  }
  else {
    level = 3;
  }
  switch (level) {
  case 0:
    healed = (uint16_t)((ovr_manage_rollDice(1,6) & 0xff) + 1);
    break;
  case 1:
    healed = (uint16_t)((ovr_manage_rollDice(2,6) & 0xff) + 2);
    break;
  case 2:
    healed = (uint16_t)((ovr_manage_rollDice(3,6) & 0xff) + 3);
    break;
  default:
    healed = (uint16_t)((ent->strengthMax - ent->strength) -
                        (ovr_manage_rollDice(1,6) & 0xff));
    if ((int)healed < 6) {
      healed = (uint16_t)((ovr_manage_rollDice(3,6) & 0xff) + 3);
      level = 2;
    }
    break;
  }
  old = ent->strength;
  ent->strength = (uint8_t)(ent->strength + healed);
  if (ent->strength > ent->strengthMax) {
    ent->strength = ent->strengthMax;
  }
  total = ent->strength;
  delta = (uint16_t)(total - old);
  if (total == old) {
    return (byte *)ent;
  }
  pan = (uint16_t)ovr_audio_panFromX(agnt,0);
  ovr_play_sfxU(0x3b,0,pan);
  pluralA = (char far *)ovc41_pluralSuffix((uint16_t)total);
  pluralB = (char far *)ovc41_pluralSuffix(delta);
  text1 = (char far *)ovr_agnt_statusText(ent,
                                          (char far *)MK_FP(_SS,&buf1));
  text2 = (char far *)ovr_agnt_statusText(agnt,(char far *)MK_FP(_SS,&buf2));
  stash = (char far *)ovr_ovc15_usesStshRealloc(text2);
  msg = (char far *)ovr_stsprintf((char far *)MK_FP(_SS,&buf3),
                                  (char far *)MK_FP(_DS,0x6feb),
                                  stash,curePtrs[level],text1,delta,pluralB,total,
                                  pluralA);
  /* GUESS: ds:[0x8ff7] is anonymous in the original; GSavedBlitSeg is the tree's name for the saved
     blit segment that uiNotify takes as its second argument. */
  ovr_uiNotify(msg,GSavedBlitSeg,0);
  return (byte *)ent;
}


/* 6a8f:22cb */
void __cdecl16far ovc41_specialAttack(agnt_t far *agnt,int targetIndex,uint16_t arg3,uint16_t arg4)

{
  uint *flagsPtr;
  agntG_t far *targetGdata;
  entity_t *targetEnt;
  byte strength;            /* agnt->strength, the breath-weapon damage base */
  byte rollRes;             /* ovr_manage_rollDice's result */
  byte compute9Res;         /* ovr_agnt_compute9(agnt,targetIndex)'s result */
  uint16_t turnRes;         /* ovc41_turnUndeadNotice's result */
  uint16_t halfRes;         /* ovr_ovc27_breathHalfDamage's result */
  uint16_t modRes;          /* ovr_agnt_abilityModifier's result */
  uint16_t agntSegDead;     /* agntPtr's segment, stored and never read */
  uint16_t agntSeg;         /* agntPtr's segment, used to build the name pointer */
  uint16_t sfxResA;         /* ovr_ovc27_usesPlay_sfxU's result (first call) */
  uint16_t sfxResB;         /* the same at 1680; 1713 reads it as a pointer high byte */
  agnt_t far *targetAgnt;
  int damageTotal;
  char *textPtr;
  uint8_t *stashOfs;
  uint16_t panRes;          /* ovr_audio_panFromX's result, fed to play_sfxU */
  uint16_t randRes;         /* ovr_randBelow(animFrame)'s result, tested for zero */
  uint16_t deadTgtHi;       /* the target index times 0x34, high word: never read */
  uint16_t dmgOut;          /* the damage figure carried to the message calls */
  uint16_t panOut;          /* ovr_audio_panFromX's result in the notice branches */
  uint damage;
  int targetAgentIdx;       /* the third argument, read signed: an agent index */
  undefined1 textOfsLo;     /* SUB21(textPtr,0), the actor name's offset low byte */
  undefined1 gSavedSegLo;   /* (undefined1)GSavedBlitSeg */
  undefined1 dmgLo;         /* (undefined1)dmgOut, the damage low byte */
  undefined1 targetIdxLo;   /* (undefined1)targetIndex */
  undefined1 targetIdxHi;   /* (undefined1)(targetIndex >> 8) */
  undefined1 blitSegLo;
  uint8_t actorName;
  uint8_t targetName;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  agnt_t far *agntPtr;   /* was uint32_t: assigned agnt_t far * values */
  char resolved;
  
  targetIdxLo = (undefined1)targetIndex;
  targetIdxHi = (undefined1)((uint)targetIndex >> 8);
  turnRes = ovc41_turnUndeadNotice((agnt_t far *)CONCAT13(targetIdxHi,CONCAT12(targetIdxLo,agnt)));
  if ((((char)turnRes == '\0') && (-1 < targetAgentIdx)) &&
     (targetAgentIdx < (int)(uint)AgntCount)) {
    deadTgtHi = (uint16_t)((ulong)((long)targetAgentIdx * 0x34) >> 0x10);
    targetAgnt = (agnt_t far *)(agnt_t far *)((long)targetAgentIdx * 0x34);
    agntPtr = (agnt_t far *)MK_FP(SEG_OF(Agnts),targetAgnt);
    if (targetAgnt->animVariant == 0x0) {
      *(undefined1 *)&targetAgnt->targetX = 0;
      *(undefined1 *)((int)&targetAgnt->targetX + 1) = 0;
    }
    if ((agnt->flags & 8) == 0) {
      if (agnt->variant == 0x0) {
        if ((agnt->gindex == 0x4) && ((((agntG_t far *)agnt->gdata)->flags2 & 0x200) != 0)) {
          strength = agnt->strength;
          halfRes = ovr_ovc27_breathHalfDamage(targetAgnt);
          damage = (uint)strength;
          if ((char)halfRes != '\0') {
            damage = (int)(uint)strength >> 1;
          }
        }
        else {
          rollRes = ovr_manage_rollDice(((agntG_t far *)agnt->gdata)->dmgDice,
                                      ((agntG_t far *)agnt->gdata)->dmgSides);
          damageTotal = (uint)rollRes + (uint)((agntG_t far *)agnt->gdata)->dmgBonus;
          compute9Res = ovr_agnt_compute9(agnt,targetIdxLo);
          dmgOut = damageTotal + (char)compute9Res;
          damage = dmgOut;
        }
        if ((damage != 0) && ((((agntG_t far *)agnt->gdata)->flags3 & 8) != 0)) {
          modRes = ovr_agnt_abilityModifier
                            (*(byte *)((int)&(((entity_t *)agnt->entity)->base).entity + 3),0);
          damage = damage + (int)(char)modRes;
          if ((int)damage < 1) {
            damage = 1;
          }
        }
        targetGdata = ((agnt_t far *)agntPtr)->gdata;
        if (((((agntG_t *)targetGdata)->flags2 & 8) == 0) ||
           (compute9Res = ovr_agnt_compute9(agnt,targetIdxLo), '\0' < (char)compute9Res)) {
          targetGdata = ((agnt_t far *)agntPtr)->gdata;
          if (((((agntG_t *)targetGdata)->flags3 & 0x40) == 0) ||
             (compute9Res = ovr_agnt_compute9(agnt,targetIdxLo), '\x01' < (char)compute9Res)) {
            agntSegDead = (uint16_t)((ulong)agntPtr >> 0x10);
            targetGdata = ((agnt_t far *)agntPtr)->gdata;
            if (((((agntG_t *)targetGdata)->flags2 & 0x10) == 0) || (agnt->gindex != 0x2)) {
              resolved = ovc41_textParalyzed((agnt_t far *)CONCAT22(targetIndex,agnt),(agnt_t far *)agntPtr,damage,
                                             (char)agntPtr,(char)((ulong)agntPtr >> 0x10),
                                             (char)damage);
              if ((resolved == '\0') &&
                 (((agnt->gindex == 0x0 && ((((agntG_t far *)agnt->gdata)->flags2 & 2) != 0)) &&
                  (damage = ovr_ovc27_rollToHitEntity((uint32_t)agntPtr,0), (damage & 0xff) == 0)))
                 ) {
                blitSegLo = (undefined1)GSavedBlitSeg;
                textPtr = ovr_agnt_statusText((agnt_t far *)agntPtr,(char *)CONCAT13((char)((uint)&actorName >> 8),
                                                              CONCAT12((char)&actorName,
                                                                       (*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))),0);
                dmgLo = (undefined1)dmgOut;
                textOfsLo = SUB21(textPtr,0);
                textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex),0);
                stashOfs = ovr_ovc15_usesStshRealloc(textPtr,dmgOut,textOfsLo,dmgLo,blitSegLo,0,0,0);
                textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x70b5,_SS),
                                       (char *)CONCAT22(stashOfs,(char *)0x2410),dmgOut);
                ovr_uiNotify(textPtr,dmgOut,(char)dmgOut);
                panRes = ovr_audio_panFromX(agnt,targetIdxLo);
                ovr_play_sfxU(0x55,0,panRes,0,(char)panRes);
                ovc41_settleAgentCombat
                          ((agnt_t far *)CONCAT13(targetIdxHi,CONCAT12(targetIdxLo,agnt)),(agnt_t far *)agntPtr,(char)agntPtr)
                ;
                resolved = '\x01';
              }
              if (((resolved == '\0') && ((((agntG_t far *)agnt->gdata)->flags2 & 4) != 0)) &&
                 (damage = ovr_ovc27_rollToHitEntity((uint32_t)agntPtr,0), (damage & 0xff) == 0)) {
                agntSeg = (uint16_t)((ulong)agntPtr >> 0x10);
                targetEnt = ((agnt_t far *)agntPtr)->entity;
                if ((*(uint *)((int)&(((entity_t *)targetEnt)->base).frames + 1) & 1) == 0) {
                  gSavedSegLo = (undefined1)GSavedBlitSeg;
                  textPtr = ovr_agnt_statusText((agnt_t far *)agntPtr,(char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,agntSeg)),0);
                  dmgLo = (undefined1)dmgOut;
                  textOfsLo = SUB21(textPtr,0);
                  textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex),0);
                  stashOfs = ovr_ovc15_usesStshRealloc(textPtr,dmgOut,textOfsLo,dmgLo,gSavedSegLo,0,0,0);
                  textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x70c4,_SS),
                                         (char *)CONCAT22(stashOfs,(char *)0x2410),dmgOut);
                  ovr_uiNotify(textPtr,dmgOut,(char)dmgOut);
                  panRes = ovr_audio_panFromX((agnt_t far *)agntPtr,(char)((ulong)agntPtr >> 0x10));
                  ovr_play_sfxU(5,0,panRes,0,(char)panRes);
                  targetEnt = ((agnt_t far *)agntPtr)->entity;
                  flagsPtr = (uint *)((int)&(((entity_t *)targetEnt)->base).frames + 1);
                  *flagsPtr = *flagsPtr | 1;
                }
              }
              if (((resolved == '\0') && ((((agntG_t far *)agnt->gdata)->flags2 & 0x400) != 0)) &&
                 (randRes = ovr_randBelow((uint)(((entity_t *)agnt->entity)->base).animFrame,0),
                 (randRes & 0xff) == 0)) {
                sfxResA = ovr_ovc27_usesPlay_sfxU
                                  ((uint16_t)agnt,targetIndex,agntPtr,0x1,(char)agntPtr,
                                   (char)((ulong)agntPtr >> 0x10));
                gSavedSegLo = (undefined1)GSavedBlitSeg;
                if ((char)sfxResA == '\0') {
                  textPtr = ovr_agnt_statusText((agnt_t far *)agntPtr,(char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,
                                                                         (*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))),0);
                  dmgLo = (undefined1)dmgOut;
                  textOfsLo = SUB21(textPtr,0);
                  textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex),0);
                  stashOfs = ovr_ovc15_usesStshRealloc(textPtr,dmgOut,textOfsLo,dmgLo,gSavedSegLo,0,0,0);
                  textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x7107,_SS),
                                         (char *)CONCAT22(stashOfs,(char *)0x2410),dmgOut);
                  ovr_uiNotify(textPtr,dmgOut,(char)dmgOut);
                }
                else {
                  textPtr = ovr_agnt_statusText((agnt_t far *)agntPtr,(char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,
                                                                         (*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))),0);
                  dmgLo = (undefined1)dmgOut;
                  textOfsLo = SUB21(textPtr,0);
                  textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex),0);
                  stashOfs = ovr_ovc15_usesStshRealloc(textPtr,dmgOut,textOfsLo,dmgLo,gSavedSegLo,0,0,0);
                  textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x70ec,_SS),
                                         (char *)CONCAT22(stashOfs,(char *)0x2410),dmgOut);
                  ovr_uiNotify(textPtr,dmgOut,(char)dmgOut);
                }
              }
              if (((resolved == '\0') && ((((agntG_t far *)agnt->gdata)->flags2 & 0x800) != 0)) &&
                 (randRes = ovr_randBelow((uint)(((entity_t *)agnt->entity)->base).animFrame,0),
                 (randRes & 0xff) == 0)) {
                sfxResB = ovr_ovc27_usesPlay_sfxU
                                  ((uint16_t)agnt,targetIndex,agntPtr,0x2,(char)agntPtr,
                                   (char)((ulong)agntPtr >> 0x10));
                gSavedSegLo = (undefined1)GSavedBlitSeg;
                if ((char)sfxResB == '\0') {
                  textPtr = ovr_agnt_statusText((agnt_t far *)agntPtr,(char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,
                                                                         (*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))),0);
                  dmgLo = (undefined1)dmgOut;
                  textOfsLo = SUB21(textPtr,0);
                  textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex),0);
                  stashOfs = ovr_ovc15_usesStshRealloc(textPtr,dmgOut,textOfsLo,dmgLo,gSavedSegLo,0,0,0);
                  textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x7107,_SS),
                                         (char *)CONCAT22(stashOfs,(char *)0x2410),dmgOut);
                  ovr_uiNotify(textPtr,dmgOut,(char)dmgOut);
                }
                else {
                  textPtr = ovr_agnt_statusText((agnt_t far *)agntPtr,(char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,
                                                                         (*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))),0);
                  dmgLo = (undefined1)dmgOut;
                  textOfsLo = SUB21(textPtr,0);
                  textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex),0);
                  stashOfs = ovr_ovc15_usesStshRealloc(textPtr,dmgOut,textOfsLo,dmgLo,gSavedSegLo,0,0,0);
                  textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x7125,_SS),
                                         (char *)CONCAT22(stashOfs,(char *)0x2410),dmgOut);
                  ovr_uiNotify(textPtr,dmgOut,(char)dmgOut);
                }
              }
            }
            else {
              gSavedSegLo = (undefined1)GSavedBlitSeg;
              textPtr = ovr_agnt_statusText((agnt_t far *)agntPtr,(char *)CONCAT13((char)((uint)&targetName >> 8),
                                                            CONCAT12((char)&targetName,sfxResB)),0);
              stashOfs = ovr_ovc15_usesStshRealloc(textPtr,(char)dmgOut,gSavedSegLo,0,0,0,0,0);
              textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x708c,_SS),
                                     (char *)CONCAT13((char)((uint)stashOfs >> 8),
                                                      CONCAT12((char)stashOfs,0x2410)),(char)stashOfs,
                                     (char)dmgOut);
              ovr_uiNotify(textPtr,dmgOut,(char)dmgOut);
              panOut = ovr_audio_panFromX((agnt_t far *)agntPtr,(char)((ulong)agntPtr >> 0x10));
              ovr_play_sfxU(0x16,0,panOut,0,(char)panOut);
            }
          }
          else {
            gSavedSegLo = (undefined1)GSavedBlitSeg;
            textPtr = ovr_agnt_statusText((agnt_t far *)agntPtr,(char *)CONCAT13((char)((uint)&targetName >> 8),
                                                          CONCAT12((char)&targetName,(*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))
                                                         ),0);
            stashOfs = ovr_ovc15_usesStshRealloc(textPtr,(char)dmgOut,gSavedSegLo,0,0,0,0,0);
            textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x705e,_SS),
                                   (char *)CONCAT13((char)((uint)stashOfs >> 8),
                                                    CONCAT12((char)stashOfs,0x2410)),(char)stashOfs,
                                   (char)dmgOut);
            ovr_uiNotify(textPtr,dmgOut,(char)dmgOut);
            panOut = ovr_audio_panFromX((agnt_t far *)agntPtr,(char)((ulong)agntPtr >> 0x10));
            ovr_play_sfxU(0x16,0,panOut,0,(char)panOut);
          }
        }
        else {
          gSavedSegLo = (undefined1)GSavedBlitSeg;
          textPtr = ovr_agnt_statusText((agnt_t far *)agntPtr,(char *)CONCAT13((char)((uint)&targetName >> 8),
                                                        CONCAT12((char)&targetName,(*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))),0)
          ;
          stashOfs = ovr_ovc15_usesStshRealloc(textPtr,(char)dmgOut,gSavedSegLo,0,0,0,0,0);
          textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x7031,_SS),
                                 (char *)CONCAT13((char)((uint)stashOfs >> 8),
                                                  CONCAT12((char)stashOfs,0x2410)),(char)stashOfs,
                                 (char)dmgOut);
          ovr_uiNotify(textPtr,dmgOut,(char)dmgOut);
          panOut = ovr_audio_panFromX((agnt_t far *)agntPtr,(char)((ulong)agntPtr >> 0x10));
          ovr_play_sfxU(0x16,0,panOut,0,(char)panOut);
        }
      }
      else {
        ovr_ovc27_textTakesHalfDamage3(agnt,targetIndex,targetIdxLo,(char)targetAgentIdx);
      }
    }
    else {
      ovc41_textOnlyPlaceSingle((agnt_t far *)CONCAT13(targetIdxHi,CONCAT12(targetIdxLo,agnt)),targetAgentIdx);
    }
  }
  return;
}


/* 6a8f:297d */

/* Applies the special attack to an agent and then runs the follow-up tick. */

void __cdecl16far ovc41_resolveSpecialAttack(agnt_t far *agnt,uint16_t param)

{
  ovc41_specialAttack((agnt_t far *)agnt,(*(uint16_t *)((uint8_t *)&(agnt) + 2)),param,0);
  ovr_agnt_advanceAnimFrame((agnt_t far *)agnt,(*(uint16_t *)((uint8_t *)&(agnt) + 2)));
  return;
}



/* 6a8f:29a0 */

/* [R6] touches AgntCount */

void __cdecl16far ovc41_usesAgntCount3(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    if (Agnts[iVar1].faction != '\0') {
      ovc41_settleAgentCombat((agnt_t far *)0x0,(agnt_t far *)MK_FP(SEG_OF(Agnts),(agnt_t far *)&Agnts[iVar1].x),0);
    }
  }
  return;
}



/* 6a8f:29ea */

/* Returns the growth requirement for an agent's level, from the growth table or its type record. */

int __cdecl16far ovc41_growthForLevel(agnt_t far *agnt,uint16_t arg2)

{
  int iVar1;
  far_t dst;
  uint8_t growthMap;
  byte level;
  byte gindex;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)&growthMap;
  F_SCOPY(far_from_u32((uint32_t)(0x24106e48)),dst,44);
  gindex = agnt->gindex;
  if (AgntGs[(uint)gindex].shortName[3] == -1) {
    iVar1 = AGNT_WORD(&AgntGs[(uint)gindex], shortName, 5);
  }
  else {
    level = agnt->level;
    if (level < 0x16) {
      iVar1 = *(int *)(&growthMap + (uint)level * 2);
    }
    else {
      iVar1 = (uint)level * 0xfa + -0xabe;
    }
  }
  return iVar1;
}


