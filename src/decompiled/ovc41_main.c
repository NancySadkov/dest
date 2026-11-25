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
  uint uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint16_t uVar7;
  byte bStack_7;
  
  uVar7 = (uint16_t)(view >> 0x10);
  iVar6 = (int)view;
  bStack_7 = *(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)*(byte *)(iVar6 + 0xd) * 0x95);
  if (bStack_7 == 0xff) {
    bStack_7 = 0;
  }
  piVar3 = (int *)((uint)bStack_7 * 0x94 + (uint)*(byte *)(iVar6 + 0xf) * 4);
  if (*piVar3 == 0 && piVar3[1] == 0) {
    iVar4 = (uint)bStack_7 * 0x94 + (uint)*(byte *)(iVar6 + 0xf) * 4;
    uVar1 = *(uint *)(iVar4 + -4);
    *(int *)(iVar6 + 0x12) = *(int *)(iVar4 + -2) + (uint)(0xfffe < uVar1);
    *(int *)(iVar6 + 0x10) = uVar1 + 1;
  }
  else {
    puVar5 = (uint *)((uint)bStack_7 * 0x94 + (uint)*(byte *)(iVar6 + 0xf) * 4);
    uVar1 = puVar5[1];
    if ((uVar1 <= *(uint *)(iVar6 + 0x12)) &&
       ((uVar1 != *(uint *)(iVar6 + 0x12) || (*puVar5 <= *(uint *)(iVar6 + 0x10))))) {
      puVar5 = (uint *)((uint)bStack_7 * 0x94 + (uint)*(byte *)(iVar6 + 0xf) * 4);
      uVar1 = *puVar5;
      *(int *)(iVar6 + 0x12) = puVar5[1] + (uint)(0xfffe < uVar1);
      *(int *)(iVar6 + 0x10) = uVar1 + 1;
      *(char *)(iVar6 + 0xf) = *(char *)(iVar6 + 0xf) + '\x01';
      cVar2 = ovr_ovc15_textView(view);
      *(char *)(iVar6 + 0x31) = *(char *)(iVar6 + 0x31) + cVar2;
      *(char *)(iVar6 + 0x32) = *(char *)(iVar6 + 0x32) + cVar2;
    }
  }
  return;
}



/* 6a8f:016b */

/* [R7] body shape: compute */

void __cdecl16far ovc41_compute4(agnt_t *agnt,byte flag,byte pad,agnt_t *other,uint16_t arg5,uint16_t arg6,uint16_t arg7,uint16_t arg8)

{
  uint *puVar1;
  uint uVar2;
  agnt_t *paVar3;
  int iVar4;
  uint16_t unaff_BP;
  uint16_t in_stack_00000000;
  uint16_t in_stack_00000002;
  long b;
  uint16_t in_stack_0000000c;
  undefined1 in_stack_0000fffc;
  long *retStorage;
  
  if (pad != 0) {
    retStorage = (long *)CONCAT11(other->gindex,in_stack_0000fffc);
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)other->gindex * 0x95) != -1) {
      ovc41_growthForLevel(agnt,0);
      iVar4 = 0;
      paVar3 = (agnt_t *)LXMUL_at_(retStorage,CONCAT22(in_stack_00000000,unaff_BP),b);
      paVar3 = ovr_ovc15_textError((agnt_t *)CONCAT22(in_stack_0000000c,other),paVar3);
      puVar1 = (uint *)&other->health;
      uVar2 = *puVar1;
      *puVar1 = (int)&paVar3->x + *puVar1;
      *(uint *)&other->frameIndex =
           *(int *)&other->frameIndex + iVar4 + (uint)CARRY2(uVar2,(uint)paVar3);
      ovc41_compute3((uint32_t)CONCAT22(in_stack_0000000c,other),retStorage,unaff_BP);
    }
  }
  return;
}



/* 6a8f:01e7 */

/* Marks an agent for death: steps the animFrame back and flags the agent list changed. */

void __cdecl16far ovc41_markAgentDead(agnt_t *agnt)

{
  uint8_t *puVar1;
  entity_t *peVar2;
  uint16_t uVar3;
  
  if (DebugVerbose) {
    printf("kill 4\r");
  }
  uVar3 = (uint16_t)((ulong)agnt >> 0x10);
  peVar2 = ((agnt_t *)agnt)->entity;
  if ((((entity_t *)peVar2)->base).animFrame != 0x0) {
    peVar2 = ((agnt_t *)agnt)->entity;
    puVar1 = &(((entity_t *)peVar2)->base).animFrame;
    *puVar1 = *puVar1 + 0xff;
  }
  AgentsChanged = 1;
  return;
}



/* 6a8f:0229 */

/* [R1] forwards to OVC41_6a8f_01e7 */

void __cdecl16far OVC41_6a8f_01e7_entry(agnt_t *agnt,uint16_t arg2)

{
  uint16_t in_stack_00000006;
  
  if ((agnt->flags & 0xae4) == 0) {
    ovc41_markAgentDead((agnt_t *)CONCAT22(in_stack_00000006,agnt));
  }
  return;
}



/* 6a8f:0246 */

/* Increments the animFrame byte of the entity the agent belongs to. */

void __cdecl16far ovc41_advanceAnimFrame(agnt_t *agnt,uint16_t arg2)

{
  uint8_t *puVar1;
  uint16_t in_stack_00000006;
  
  puVar1 = &(((entity_t *)agnt->entity)->base).animFrame;
  *puVar1 = *puVar1 + 0x1;
  return;
}



/* 6a8f:0256 */
void __cdecl16far ovc41_removeAgent(uint agntIndex,int notify,uint16_t arg3)

{
  char *pcVar1;
  uint16_t uVar2;
  agnt_t *agnt;
  int iVar3;
  uint16_t uVar4;
  bool bVar5;
  uint uVar6;
  entity_t *uStack_8;   /* hand fix: dereferenced as uStack_8->base.x */
  
  uVar2 = AGNT_WORD(&Agnts[agntIndex], entity, 2);
  agnt = (agnt_t *)AGNT_WORD(&Agnts[agntIndex], entity, 0);
  uStack_8 = (agnt_t *)CONCAT22(uVar2,agnt);
  iVar3 = Agnts[agntIndex].owner;
  ovr_agnt_usesAgntCount4(agntIndex + 1);
  bVar5 = false;
  for (uVar6 = 0; (int)uVar6 < (int)(uint)AgntCount; uVar6 = uVar6 + 1) {
    if ((uVar6 != agntIndex) && (Agnts[uVar6].owner == iVar3)) {
      bVar5 = true;
    }
    if (Agnts[uVar6].target != -1) {
      if ((int)agntIndex < (int)(uint)Agnts[uVar6].target) {
        pcVar1 = (char *)&Agnts[uVar6].target;
        *pcVar1 = *pcVar1 + -1;
      }
      else if (Agnts[uVar6].target == agntIndex) {
        Agnts[uVar6].target = 0xff;
      }
    }
  }
  if ((int)(agntIndex + 1) < (int)(uint)AgntCount) {
    _fmemmove((char *)CONCAT22(SEG_OF(Agnts),(char *)&Agnts[agntIndex].x),
              (char *)CONCAT22(SEG_OF(Agnts),(char *)&Agnts[agntIndex + 1].x),
              ((AgntCount - agntIndex) + -1) * 0x34);
  }
  AgntCount = AgntCount - 1;
  if ((((notify != 0) && (!bVar5)) && (agnt->y == GfxRndSeed2)) &&
     ((GfxRndSeed - 2U <= uStack_8->base.x && (GfxRndSeed - 2U <= uStack_8->base.x)))) {
    agnt->destX = agnt->targetX;
    uVar4 = agnt->targetY;
    agnt->destY = uVar4;
    ovr_attact_usesRandBelow(agnt,(byte)uVar2,CONCAT11((char)(uVar4 >> 8),agnt->target),0);
  }
  return;
}


/* 6a8f:0422 */

/* [R6] touches MenuItemEnabled */

uint16_t __cdecl16far ovc41_usesMenuItemEnabled(byte menuIndex,int gfxVariant)

{
  byte bVar1;
  uint32_t uVar2;
  uint16_t uVar3;
  
  if (((uint8_t *)MenuItemEnabled)[menuIndex] == 0xff) {
    uVar3 = 0x6e74;
  }
  else {
    uVar2 = *(uint32_t *)((uint)((uint8_t *)MenuItemEnabled)[menuIndex] << 2);
    bVar1 = *(byte *)((int)uVar2 + 0x2f);
    if (gfxVariant == 1) {
      uVar3 = *(uint16_t *)((uint)bVar1 * 4 + 0x123);
    }
    else {
      uVar3 = *(uint16_t *)((uint)bVar1 * 4 + 0x107);
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
  char *pcVar1;
  uint16_t *puVar2;
  uint16_t uVar3;
  uint16_t dst;
  uint uVar4;
  int count;
  far_t pctOut;
  far_t remainderOut;
  ulong uVar5;
  far_t partOut;
  uint32_t uVar6;
  uint8_t msg;
  uint8_t part;
  uint8_t remainder;
  uint8_t pct;
  
  uVar3 = 0x2410;
  if (((uint8_t *)MenuItemEnabled)[menuIndex] != 0xff) {
    count = 0;
    for (uVar4 = 0; uVar4 < AgntCount; uVar4 = uVar4 + 1) {
      uVar3 = SEG_OF(Agnts);
      uVar6 = *(uint32_t far *)&Agnts[uVar4].entity;
      if (((uint8_t *)MenuItemEnabled)[menuIndex] == *(uint8_t *)((int)uVar6 + 0x1a)) {
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
    uVar6 = CONCAT22(0xa000,(uint)pct);
    uVar5 = (ulong)CONCAT12(remainder,(uint)part);
    pcVar1 = ovc41_isAre(count);
    puVar2 = (uint16_t *)((uint)((uint8_t *)MenuItemEnabled)[menuIndex] * 4);
    dst = _DS;
    uVar3 = ovc41_pluralSuffix(count,*puVar2,puVar2[1],pcVar1,uVar3,uVar5,uVar6);
    pcVar1 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6e86,_SS),
                           (char *)CONCAT22(count,(char *)0x26510),uVar3,dst);
    ovr_drawTextAt(pcVar1,dst,0);
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

uint __cdecl16far ovc41_settleAgentCombat(agnt_t *a,agnt_t *b,uint16_t arg3)

{
  uint in_AX;
  uint uVar1;
  int iVar2;
  byte bVar3;
  agnt_t *agnt;
  uint16_t uVar4;
  
  uVar4 = (uint16_t)((ulong)b >> 0x10);
  agnt = (agnt_t *)b;
  if (agnt->combatState == 0x2) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    if ((a != (agnt_t *)0x0) && (((agnt_t *)a)->gdata->ai == ((agnt_t *)a)->faction)) {
      ovc41_compute4(*(agnt_t **)&agnt->entity,(byte)*(uint16_t *)((int)&agnt->entity + 2),1,*(agnt_t **)&((agnt_t *)a)->entity,0,0,0,0);
    }
    if (((((((entity_t *)agnt->entity)->base).animFrame == 0x0) ||
         ((uint)(((entity_t *)agnt->entity)->base).animFrame % 0x10 == 1)) ||
        ((agnt->flags & 0xae4) != 0)) || ((((agntG_t *)agnt->gdata)->flags2 & 4) != 0)) {
      agnt->strength = 0x0;
      agnt->timer = 0xa;
      agnt->combatState = 0x2;
      agnt->targetY = 0;
    }
    else {
      agnt->strength = ((agntG_t *)agnt->gdata)->strength;
      agnt->timer = 0x6;
      agnt->combatState = 0x1;
      agnt->targetY = 0;
    }
    ovr_agnt_usesAnimFrame(agnt);
    iVar2 = agnt->owner * 0x37;
    bVar3 = (byte)((uint)iVar2 >> 8);
    ovr_ovc25_attackingNotice(*(byte *)((int)Entities + iVar2 + 0x1a));
    if ((agnt->flags & 0xae4) == 0) {
      ovc41_markAgentDead(b);
      uVar1 = CONCAT11(bVar3,1);
    }
    else {
      uVar1 = (uint)bVar3 << 8;
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
        OVC41_6a8f_01e7_entry((agnt_t *)&Agnts[iVar2].x,SEG_OF(Agnts));
        puVar1 = (uint *)&Agnts[iVar2].flags;
        *puVar1 = *puVar1 | 0x800;
        unk = ovr_audio_panFromX((agnt_t *)&Agnts[iVar2].x,SEG_OF(Agnts));
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
  byte bVar1;
  agnt_t *paVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  entity_t *uStack_6;   /* hand fix: dereferenced as uStack_6->base.x */
  
  paVar2 = (agnt_t *)&Agnts[agntIndex].x;
  uStack_6 = (agnt_t *)CONCAT22(SEG_OF(Agnts),paVar2);
  if ((((agntG_t *)paVar2->gdata)->flags2 & 4) != 0) {
    for (iVar6 = 0; iVar6 < (int)(uint)AgntCount; iVar6 = iVar6 + 1) {
      if ((iVar6 != agntIndex) &&
         (uVar3 = uStack_6->base.x - Agnts[iVar6].x, uVar5 = (int)uVar3 >> 0xf,
         (int)((uVar3 ^ uVar5) - uVar5) < 0x32)) {
        bVar1 = ovr_manage_rollDice('\x06','\x06');
        uVar3 = (uint)bVar1;
        iVar4 = ovr_ovc27_rollToHitEntity(CONCAT22(SEG_OF(Agnts),iVar6 * 0x34),1);
        if ((char)iVar4 != '\0') {
          uVar3 = (int)uVar3 >> 1;
        }
        ovc41_textParalyzed((agnt_t *)CONCAT22(SEG_OF(Agnts),paVar2),(agnt_t *)CONCAT22(SEG_OF(Agnts),(agnt_t *)&Agnts[iVar6].x),uVar3,0,0,0);
      }
    }
  }
  return;
}


/* 6a8f:08c2 */

/* [R6] touches xOfs */

void __cdecl16far ovc41_usesXOfs(int agntIndex)

{
  uint uVar1;
  far_t dst;
  int iStack_c;
  uint8_t xOfs;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)&xOfs;
  F_SCOPY(far_from_u32((uint32_t)(0x24106e00)),dst);
  uVar1 = (uint)Agnts[agntIndex].target;
  iStack_c = Agnts[agntIndex].targetY;
  if (2 < iStack_c) {
    iStack_c = 3;
  }
  if (Agnts[agntIndex].level == '\0') {
    Agnts[uVar1].x = Agnts[agntIndex].x + *(int *)(&xOfs + iStack_c * 2);
  }
  else {
    Agnts[uVar1].x = Agnts[agntIndex].x - *(int *)(&xOfs + iStack_c * 2);
  }
  if (0xd2 < Agnts[uVar1].x) {
    Agnts[uVar1].x = 0xd2;
  }
  if (Agnts[uVar1].x < 0) {
    Agnts[uVar1].x = 0;
  }
  Agnts[uVar1].y = Agnts[agntIndex].y;
  AGNT_FIELD(&Agnts[uVar1], targetX, 1) = 0;
  AGNT_FIELD(&Agnts[uVar1], targetX, 0) = 0;
  return;
}



/* 6a8f:0a45 */

/* [R7] body shape: compute */

uint16_t __cdecl16far ovc41_compute6(byte rank,uint8_t level)

{
  byte bVar1;
  uint16_t packed;
  undefined1 uVar3;
  
  bVar1 = ovr_agnt_compute14(level);
  if (bVar1 + 2 < (uint)rank) {
    packed = CONCAT11((char)(bVar1 + 2 >> 8),0xd);
  }
  else if (bVar1 + 2 == (uint)rank) {
    packed = CONCAT11((char)(bVar1 + 2 >> 8),0xb);
  }
  else {
    uVar3 = (undefined1)(bVar1 + 1 >> 8);
    if (bVar1 + 1 == (uint)rank) {
      packed = CONCAT11(uVar3,9);
    }
    else if (bVar1 == rank) {
      packed = CONCAT11(uVar3,7);
    }
    else {
      packed = CONCAT11(uVar3,2);
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
  byte bVar1;
  byte bVar3;
  int iVar2;
  
  bVar1 = ovr_agnt_compute14(level);
  bVar3 = (byte)(rank + 4 >> 8);
  if (bVar1 + 1 < rank + 4) {
    iVar2 = (uint)bVar3 << 8;
  }
  else {
    iVar2 = CONCAT11(bVar3,1);
  }
  return iVar2;
}



/* 6a8f:0b39 */

/* Rolls the turn-undead attempt and reports its result. */

int __cdecl16far ovc41_turnUndeadNotice(agnt_t *agnt)

{
  uint *flagsPtr;
  char cVar2;
  uint16_t in_AX;
  byte bVar7;
  undefined1 extraout_AH;
  uint16_t uVar3;
  uint8_t *stashOfs;
  undefined1 savedSeg;
  int iVar5;
  uint16_t uVar6;
  agnt_t *agnt_00;
  uint uVar9;
  char *pcVar10;
  uint32_t agntPtr2;
  uint8_t text;
  uint8_t msg;
  int targetOfs;
  uint16_t uStack_8;
  byte bStack_6;
  byte bStack_5;
  char cStack_4;
  char stateVal;
  
  pcVar10 = (char *)((ulong)agnt >> 0x10);
  agnt_00 = (agnt_t *)agnt;
  bVar7 = (byte)((uint)in_AX >> 8);
  if ((agnt_00->flags & 2) == 0) {
    iVar5 = (uint)bVar7 << 8;
  }
  else {
    agnt_00->health = 0x0;
    agnt_00->flags = agnt_00->flags & 0xfffd;
    if (agnt_00->target == 0xff) {
      iVar5 = (uint)bVar7 << 8;
    }
    else {
      targetOfs = (uint)agnt_00->target * 0x34;
      uStack_8 = SEG_OF(Agnts);
      bStack_6 = ((agntG_t *)((targetOfs + 0x1d)))->rank;
      if (bStack_6 == 0) {
        iVar5 = 0;
      }
      else {
        cVar2 = ovr_manage_rollDice('\x02','\x06');
        uVar6 = CONCAT11(extraout_AH,cVar2);
        uVar3 = ovc41_compute6(((agntG_t *)((targetOfs + 0x1d)))->rank,
                               (((entity_t *)agnt_00->entity)->base).level);
        if ((byte)uVar6 < (byte)uVar3) {
          pcVar10 = ovr_agnt_statusText(agnt_00,(char *)CONCAT13((char)((uint)&text >> 8),
                                                                 CONCAT12((char)&text,pcVar10)),0);
          stashOfs = ovr_ovc15_usesStshRealloc(pcVar10,uVar6,0,0,0,0,0,0);
          pcVar10 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6ed6,_SS),
                                  (char *)CONCAT13((char)((uint)stashOfs >> 8),
                                                   CONCAT12((char)stashOfs,0x2410)),(char)stashOfs,uVar6
                                 );
          ovr_uiNotify(pcVar10,uVar6,0);
          savedSeg = (undefined1)((uint)pcVar10 >> 8);
          ovr_agnt_usesAnimFrame(agnt_00);
          iVar5 = CONCAT11(savedSeg,1);
        }
        else {
          bVar7 = ((agntG_t *)((targetOfs + 0x1d)))->rank;
          uVar9 = (uint)bVar7;
          ovc41_rollStatDice(bVar7,(((entity_t *)agnt_00->entity)->base).level);
          uVar9 = uVar9 & 0xff;
          iVar5 = ovc41_compute8(((agntG_t *)((targetOfs + 0x1d)))->rank,
                                 (((entity_t *)agnt_00->entity)->base).level);
          cStack_4 = (char)iVar5;
          bStack_5 = 0;
          iVar5 = 0;
          while ((iVar5 < (int)(uint)AgntCount && (uVar9 != 0))) {
            agntPtr2 = *(uint32_t far *)&Agnts[iVar5].gdata;
            if (((*(char *)((int)agntPtr2 + 0x42) != '\0') &&
                ((((Agnts[iVar5].faction != agnt_00->faction &&
                   ((Agnts[iVar5].flags & 4) == 0)) &&
                  (Agnts[iVar5].combatState == '\0')) &&
                 ((bStack_5 == 0 ||
                  (agntPtr2 = *(uint32_t far *)&Agnts[iVar5].entity,
                  (int)(uint)*(byte *)((int)agntPtr2 + 0xf) <= (int)uVar9)))))) &&
               (agntPtr2 = *(uint32_t far *)&Agnts[iVar5].gdata,
               *(byte *)((int)agntPtr2 + 0x42) <= bStack_6)) {
              if ((Agnts[iVar5].flags & 0xae4) == 0) {
                agntPtr2 = *(uint32_t far *)&Agnts[iVar5].entity;
                stateVal = *(char *)((int)agntPtr2 + 0xe);
              }
              else {
                stateVal = '\x01';
              }
              while ((stateVal != '\0' && (uVar9 != 0))) {
                if (cStack_4 == '\0') {
                  OVC41_6a8f_01e7_entry((agnt_t *)&Agnts[iVar5].x,0);
                  AGNT_FIELD(&Agnts[iVar5], targetX, 0) = 0;
                  AGNT_FIELD(&Agnts[iVar5], targetX, 1) = 0;
                  flagsPtr = (uint *)&Agnts[iVar5].flags;
                  *flagsPtr = *flagsPtr | 4;
                  Agnts[iVar5].combatState = 1;
                  Agnts[iVar5].targetY = 0;
                  Agnts[iVar5].timer = 5;
                  ovr_agnt_usesAnimFrame((agnt_t *)&Agnts[iVar5].x);
                }
                else {
                  ovc41_settleAgentCombat(agnt,(agnt_t *)CONCAT22(SEG_OF(Agnts),(agnt_t *)&Agnts[iVar5].x),0);
                }
                bStack_5 = bStack_5 + 1;
                agntPtr2 = *(uint32_t far *)&Agnts[iVar5].entity;
                if ((int)uVar9 < (int)(uint)*(byte *)((int)agntPtr2 + 0xf)) {
                  uVar9 = 0;
                }
                else {
                  agntPtr2 = *(uint32_t far *)&Agnts[iVar5].entity;
                  uVar9 = uVar9 - *(byte *)((int)agntPtr2 + 0xf);
                }
                stateVal = stateVal + -1;
              }
            }
            uVar6 = SEG_OF(Agnts);
            iVar5 = iVar5 + 1;
          }
          if (bStack_5 == 0) {
            pcVar10 = ovr_agnt_statusText(agnt_00,(char *)CONCAT13((char)((uint)&text >> 8),
                                                                   CONCAT12((char)&text,pcVar10)),0);
            stashOfs = ovr_ovc15_usesStshRealloc(pcVar10,uVar6,0,0,0,0,0,0);
            pcVar10 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6ee8,_SS),
                                    (char *)CONCAT13((char)((uint)stashOfs >> 8),
                                                     CONCAT12((char)stashOfs,0x2410)),(char)stashOfs,
                                    uVar6);
            ovr_uiNotify(pcVar10,uVar6,0);
            savedSeg = (undefined1)((uint)pcVar10 >> 8);
          }
          else {
            if (cStack_4 == '\0') {
              agntPtr2 = CONCAT22(GSavedBlitSeg,(uint)bStack_5);
              pcVar10 = ovr_agnt_statusText(agnt_00,(char *)CONCAT22(&text,pcVar10),0);
              stashOfs = ovr_ovc15_usesStshRealloc(pcVar10,(char)uVar6,agntPtr2,0,0,0,0,0);
              pcVar10 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6f0f,_SS),
                                      (char *)CONCAT22(stashOfs,(char *)0x26510),(char)uVar6
                                     );
              ovr_uiNotify(pcVar10,uVar6,0);
            }
            else {
              agntPtr2 = CONCAT22(GSavedBlitSeg,(uint)bStack_5);
              pcVar10 = ovr_agnt_statusText(agnt_00,(char *)CONCAT22(&text,pcVar10),0);
              stashOfs = ovr_ovc15_usesStshRealloc(pcVar10,(char)uVar6,agntPtr2,0,0,0,0,0);
              pcVar10 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6ef8,_SS),
                                      (char *)CONCAT22(stashOfs,(char *)0x26510),(char)uVar6
                                     );
              ovr_uiNotify(pcVar10,uVar6,0);
            }
            uVar6 = ovr_audio_panFromX(agnt_00,0);
            ovr_play_sfxU(0x3b,0,uVar6,0,0);
            savedSeg = (undefined1)(uVar6 >> 8);
          }
          ovr_agnt_usesAnimFrame(agnt_00);
          iVar5 = CONCAT11(savedSeg,1);
        }
      }
    }
  }
  return iVar5;
}



/* 6a8f:0fc1 */

/* Formats the "Building %d %s." notice. */

void __cdecl16far ovc41_buildingNotice(char delta)

{
  int iVar1;
  char *msg;
  uint16_t uVar2;
  uint8_t text;
  byte bStack_3;
  
  iVar1 = ((short (*) [148] [60])GUnitGrid)[-1][GfxRndSeed + 0x93][GfxRndSeed2];
  if (0xf7 < iVar1) {
    uVar2 = (uint16_t)((ulong)GUnits >> 0x10);
    bStack_3 = ((unit_t *)GUnits + iVar1)->bldType + delta;
    if (0xf7 < bStack_3) {
      bStack_3 = 0;
    }
    ((unit_t *)GUnits + iVar1)->bldType = bStack_3;
    ovr_constr_flushDirtyRects();
    msg = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x6f23,_SS),
                        (char *)(ulong)CONCAT12(bStack_3,(char *)0x26510),
                        BLD_WORD(&BuildingTypes[bStack_3], name, 0),
                        BLD_WORD(&BuildingTypes[bStack_3], name, 2));
    asm { mov uVar2,dx };
    ovr_say(msg,uVar2);
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
    iVar2 = (int)Entities;
    if (((GfxRndSeed - 2U <= *(uint *)((entity_t *)iVar2 + i)) &&
        (*(uint *)((entity_t *)iVar2 + i) <= GfxRndSeed + 1U)) &&
       (((entity_t *)iVar2)[i].base.y == GfxRndSeed2)) {
      pcVar1 = (char *)((uint8_t *)&((entity_t *)Entities)[i] + 0xd);
      *pcVar1 = *pcVar1 + '\x01';
      uVar3 = (uint16_t)((ulong)Entities >> 0x10);
      if (0x29 < ((entity_t *)Entities)[i].base.gindex) {
        ((entity_t *)Entities)[i].base.gindex = 0;
      }
      iVar2 = (uint)((entity_t *)Entities)[i].base.gindex * 0x95;
      msg = ovr_stsprintf(buf,(char *)CONCAT22(0x6f33,_SS),
                          (char *)CONCAT22(*(uint16_t *)((int)&AgntGs[0].name + iVar2),
                                           (char *)((int)&BuildingTypes[0xe5].halfWidth + 1)),
                          *(uint16_t *)((int)&AgntGs[0].name + 2 + iVar2));
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
    printf("%d \r");
  }
  ovr_resetTextBlitCycle();
  GGameState = 10;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_agnt_clear();
  GGameState = 0xb;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_constr_usesBlitRect4();
  GGameState = 0xc;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_attact_usesSquareRecCount2();
  GGameState = 0xd;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  TextBlitDstSeg = 0xa000;
  if (GameRunning == false) {
    for (menuIndex = 0; menuIndex < 5; menuIndex = menuIndex + 1) {
      ovr_draw_usesBlitLoadRleGfx3(menuIndex);
      ovr_draw_menuRowBar(menuIndex,0xa000);
    }
    GGameState = 0xe;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
  }
  GGameState = 0xf;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_ovc18_showLeaderView();
  GGameState = 0x10;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovc41_initIndexPerms();
  GGameState = 0x11;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  if (trianglesShown == '\0') {
    ovc41_removeIndexPerm(8);
  }
  GGameState = 0x12;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  GGameState = 0x13;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_draw_toolbarLabels();
  GGameState = 0x14;
  if (DebugVerbose != false) {
    printf("%d \r");
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
char * __cdecl16far ovc41_usesBiosKeyAvail(char backdropIndex,uint16_t arg2)

{
  undefined1 stk_fffa;   /* stack slot fffa */
  undefined1 stk_fffc;   /* stack slot fffc */
  undefined1 stk_fffe;   /* stack slot fffe */
  undefined1 _backdropIndex;   /* local lost by the decompiler */
  uint32_t backdropRec;
  uint32_t backdropRec2;
  bool bVar3;
  far_t text2;
  far_t gfx;
  far_t text2_00;
  far_t text2_01;
  far_t text2_02;
  far_t gfx_00;
  far_t handle;
  far_t palette;
  far_t gfx_01;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  far_t handle_04;
  far_t handle_05;
  far_t handle_06;
  far_t handle_07;
  far_t entries;
  char cVar4;
  int iVar5;
  char *textPtr;
  uint16_t uVar7;
  uint uVar8;
  undefined1 extraout_AH;
  undefined1 segLo;
  byte *pbVar9;
  uint uVar11;
  char *pcVar12;
  uint16_t backdropSeg;
  uint16_t in_DX;
  int iVar14;
  uint16_t *unaff_SI;
  int iVar15;
  int unaff_DI;
  uint16_t uVar16;
  far_t text1;
  far_t text1_00;
  far_t text1_01;
  far_t text1_02;
  undefined1 uStack0005;
  char in_stack_00000006;
  char in_stack_0000000e;
  char acStack_2cc [214];
  undefined1 auStack_1f6 [100];
  char acStack_192 [274];
  undefined1 auStack_80 [56];
  uint16_t uStack_48;
  uint16_t uStack_46;
  uint16_t uStack_38;
  uint16_t uStack_36;
  uint16_t uStack_34;
  uint16_t uStack_32;
  uint16_t uStack_30;
  uint16_t uStack_2e;
  uint16_t uStack_24;
  uint16_t uStack_22;
  char cStack_1f;
  char cStack_1e;
  char cStack_1d;
  stg_tmp_t *psStack_1c;
  uint16_t uStack_1a;
  uint16_t uStack_18;
  uint16_t uStack_16;
  undefined1 auStack_14 [2];
  uint16_t fmtOfs;
  uint16_t uStack_10;
  byte bVar17;
  undefined1 uVar18;
  byte bVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  byte bVar22;
  undefined1 segHi;
  undefined1 uVar24;
  undefined1 uVar25;
  undefined1 uVar26;
  
  bVar22 = 0x6a;
  (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = (char)FontHandle.seg;
  gfx_01.ofs = FontHandle.ofs;
  (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = (char)(FontHandle.seg >> 8);
  uVar7 = FontHandle.seg;
  uVar11 = FontHandle.ofs;
  ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000c31d)),0);
  if (in_stack_00000006 != '\0') {
    pcVar12 = (char *)((uint)_backdropIndex & 0xff);
    pbVar9 = (byte *)((uint)_backdropIndex & 0xff);
    if (pbVar9 < (byte *)__C0_ASM_CopyRight) {
      switch((int)pbVar9) {
      case (byte *)0x0:
        return (char *)((int)(uint32_t *)&_DATA + 1);
      case (byte *)0x1:
        ovr_ovc15_usesStExit(*(int *)((int)pbVar9 * 2 + 0x1b));
        return (char *)pbVar9;
      case (byte *)0x2:
        return _backdropIndex;
      }
      if (((uint)_backdropIndex & 2) == 0) {
        ovr_constr_usesBlitRect();
      }
      return pcVar12;
    }
  }
  pcVar12 = (char *)((uint)_backdropIndex & 0xff);
  if ((char *)((int)(uint32_t *)&_DATA + 3U) < pcVar12) {
    if (TextBlitFlag != '\0') {
      ovr_say((char *)0x6e74,0);
    }
    TextBlitFlag = 0;
    AgntFlag1 = false;
    GGameState = 0x33;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    ovc41_usesAgnt_clear('\x01');
    GGameState = 0x35;
    pcVar12 = 0x2410;   /* hand fix: segment-half slot */
    if (DebugVerbose != false) {
      pcVar12 = 0x2410;   /* hand fix: segment-half slot */
      printf("%d \r");
    }
    return pcVar12;
  }
  uVar16 = 0x6000;
  segLo = (undefined1)_SS;
  segHi = (undefined1)(_SS >> 8);
  switch((int)pcVar12) {
  case (char *)0x1:
    cVar4 = *(char *)((int)pcVar12 * 2 + 0x3f);
    do {
      if (((cVar4 == '\0') && (0xf7 < (int)unaff_SI)) &&
         (in_DX = 0x2410, ((unit_t *)GUnits)[(int)unaff_SI].level < 8)) {
        if ((*(uint *)((uVar11 >> 8) * 0x27 + 0x121) & 0x80) == 0) {
          ovc39_loadArchiveEntry(8);
        }
        else {
          ovc39_loadArchiveEntry(9);
        }
        ovc39_lordOrLady();
        fmtOfs = 0x938f;
        uStack_10 = uVar16;
        textPtr = ovr_stsprintf(acStack_2cc);
        asm { mov backdropSeg,dx };
        segLo = (undefined1)backdropSeg;
        segHi = (undefined1)((uint)backdropSeg >> 8);
        pcVar12 = textPtr;
        ovr_drawString(textPtr,0,0);
        (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = segLo;
        handle_00.ofs = (uint16_t)pcVar12;
        (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = segHi;
        ovr_stshFree(handle_00);
        return textPtr;
      }
      do {
        bVar19 = (byte)(uVar11 >> 8);
        if (((bVar22 == 1) && ((int)unaff_SI < 0xf8)) &&
           ((BuildingTypes[bVar19].flags2 & 2) != 0)) {
          ovc39_loadArchiveEntry(10);
          ovc39_lordOrLady();
          fmtOfs = 0x93f9;
          uStack_10 = uVar16;
          textPtr = ovr_stsprintf(acStack_2cc);
          asm { mov in_DX,dx };
          segLo = (undefined1)in_DX;
          segHi = (undefined1)((uint)in_DX >> 8);
          pcVar12 = textPtr;
          ovr_drawString(textPtr,0,0);
          (*(uint8_t *)((uint8_t *)&(handle_01.seg))) = segLo;
          handle_01.ofs = (uint16_t)pcVar12;
          (*(uint8_t *)((uint8_t *)&(handle_01.seg) + 1)) = segHi;
          ovr_stshFree(handle_01);
          return textPtr;
        }
        if (((bVar22 == 2) && ((int)unaff_SI < 0xf8)) &&
           ((BuildingTypes[bVar19].flags2 & 0x20) != 0)) {
          ovc39_loadArchiveEntry(0xb);
          ovc39_lordOrLady();
          fmtOfs = 0x9463;
          uStack_10 = uVar16;
          textPtr = ovr_stsprintf(acStack_2cc);
          asm { mov in_DX,dx };
          segLo = (undefined1)in_DX;
          segHi = (undefined1)((uint)in_DX >> 8);
          pcVar12 = textPtr;
          ovr_drawString(textPtr,0,0);
          (*(uint8_t *)((uint8_t *)&(handle_02.seg))) = segLo;
          handle_02.ofs = (uint16_t)pcVar12;
          (*(uint8_t *)((uint8_t *)&(handle_02.seg) + 1)) = segHi;
          ovr_stshFree(handle_02);
          return textPtr;
        }
        if (bVar22 == 3) {
          segLo = (undefined1)uVar16;
          segHi = (undefined1)((uint)uVar16 >> 8);
          uVar16 = 0x23f1;
          bVar19 = 0x94;
          uVar11 = ovr_ovc45_compute4(uVar7 + unaff_DI,0,0);
          uVar7 = CONCAT11(segHi,segLo);
          if ((char)uVar11 != '\0') {
            ovc39_loadArchiveEntry(0xc);
            ovc39_lordOrLady();
            uStack_10 = 0x23f1;
            fmtOfs = 0x94c9;
            textPtr = ovr_stsprintf(acStack_2cc);
            segLo = (undefined1)in_DX;
            segHi = (undefined1)((uint)in_DX >> 8);
            pcVar12 = textPtr;
            ovr_drawString(textPtr,0,0);
            (*(uint8_t *)((uint8_t *)&(handle_03.seg))) = segLo;
            handle_03.ofs = (uint16_t)pcVar12;
            (*(uint8_t *)((uint8_t *)&(handle_03.seg) + 1)) = segHi;
            ovr_stshFree(handle_03);
            return textPtr;
          }
        }
        if (((bVar22 == 4) && ((int)unaff_SI < 0xf8)) &&
           ((BuildingTypes[bVar19].flags2 & 0x400) != 0)) {
          ovc39_loadArchiveEntry(0xd);
          ovc39_lordOrLady();
          fmtOfs = 0x9533;
          uStack_10 = uVar16;
          textPtr = ovr_stsprintf(acStack_2cc);
          asm { mov backdropSeg,dx };
          segLo = (undefined1)backdropSeg;
          segHi = (undefined1)((uint)backdropSeg >> 8);
          pcVar12 = textPtr;
          ovr_drawString(textPtr,0,0);
          (*(uint8_t *)((uint8_t *)&(handle_04.seg))) = segLo;
          handle_04.ofs = (uint16_t)pcVar12;
          (*(uint8_t *)((uint8_t *)&(handle_04.seg) + 1)) = segHi;
          ovr_stshFree(handle_04);
          return textPtr;
        }
        do {
          unaff_DI = unaff_DI + 1;
          while( true ) {
            segLo = (undefined1)uVar16;
            segHi = (undefined1)((uint)uVar16 >> 8);
            if (unaff_DI < 2) break;
            bVar22 = bVar22 + 1;
            if (3 < bVar22) {
              backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
              backdropRec2 = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
              backdropSeg = (uint16_t)((ulong)backdropRec2 >> 0x10);
              iVar14 = (int)backdropRec2;
              if (*(uint *)((int)backdropRec + 0x4f) <
                  (uint)(*(int *)(iVar14 + 0x4d) * 2 + *(int *)(iVar14 + 0x4d)) >> 1) {
                backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                backdropRec2 = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                if (*(uint *)((int)backdropRec + 0x4f) < *(uint *)((int)backdropRec2 + 0x4d)) {
                  backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                  backdropRec2 = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                  backdropSeg = (uint16_t)((ulong)backdropRec2 >> 0x10);
                  iVar14 = (int)backdropRec2;
                  if (*(uint *)((int)backdropRec + 0x4f) <
                      (uint)(*(int *)(iVar14 + 0x4d) * 2 + *(int *)(iVar14 + 0x4d)) >> 2) {
                    backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                    backdropRec2 = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                    if (*(uint *)((int)backdropRec + 0x4f) < *(uint *)((int)backdropRec2 + 0x4d) >> 1) {
                      backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                      backdropRec2 = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                      if (*(uint *)((int)backdropRec + 0x4f) < *(uint *)((int)backdropRec2 + 0x4d) >> 2) {
                        bVar22 = 5;
                      }
                      else {
                        bVar22 = 4;
                      }
                    }
                    else {
                      bVar22 = 3;
                    }
                  }
                  else {
                    bVar22 = 2;
                  }
                }
                else {
                  bVar22 = 1;
                }
              }
              else {
                bVar22 = 0;
              }
              backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
              backdropSeg = (uint16_t)((ulong)backdropRec >> 0x10);
              iVar15 = (int)backdropRec;
              backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
              iVar14 = *(int *)(iVar15 + 0x62);
              if ((iVar14 < 0) ||
                 ((iVar14 == 0 &&
                  (*(uint *)(iVar15 + 0x60) < (uint)(*(int *)((int)backdropRec + 0x4d) * 0x28))))) {
                backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                backdropSeg = (uint16_t)((ulong)backdropRec >> 0x10);
                iVar15 = (int)backdropRec;
                backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                iVar14 = *(int *)(iVar15 + 0x62);
                if ((iVar14 < 0) ||
                   ((iVar14 == 0 &&
                    (*(uint *)(iVar15 + 0x60) < (uint)(*(int *)((int)backdropRec + 0x4d) * 0x14))))) {
                  backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                  backdropSeg = (uint16_t)((ulong)backdropRec >> 0x10);
                  iVar15 = (int)backdropRec;
                  backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                  iVar14 = *(int *)(iVar15 + 0x62);
                  if ((iVar14 < 0) ||
                     ((iVar14 == 0 &&
                      (*(uint *)(iVar15 + 0x60) < (uint)(*(int *)((int)backdropRec + 0x4d) * 0x3c) >> 2)))
                     ) {
                    backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                    backdropSeg = (uint16_t)((ulong)backdropRec >> 0x10);
                    iVar15 = (int)backdropRec;
                    backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                    iVar14 = *(int *)(iVar15 + 0x62);
                    if ((iVar14 < 0) ||
                       ((iVar14 == 0 &&
                        (*(uint *)(iVar15 + 0x60) < (uint)(*(int *)((int)backdropRec + 0x4d) * 0x14) >> 1)
                        ))) {
                      backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                      backdropSeg = (uint16_t)((ulong)backdropRec >> 0x10);
                      iVar15 = (int)backdropRec;
                      backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                      iVar14 = *(int *)(iVar15 + 0x62);
                      if ((iVar14 < 0) ||
                         ((iVar14 == 0 &&
                          (*(uint *)(iVar15 + 0x60) <
                           (uint)(*(int *)((int)backdropRec + 0x4d) * 0x14) >> 2)))) {
                        uStack_10 = CONCAT11(5,(undefined1)uStack_10);
                      }
                      else {
                        uStack_10 = CONCAT11(4,(undefined1)uStack_10);
                      }
                    }
                    else {
                      uStack_10 = CONCAT11(3,(undefined1)uStack_10);
                    }
                  }
                  else {
                    uStack_10 = CONCAT11(2,(undefined1)uStack_10);
                  }
                }
                else {
                  uStack_10 = CONCAT11(1,(undefined1)uStack_10);
                }
              }
              else {
                uStack_10 = uStack_10 & 0xff;
              }
              if ((*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) < bVar22) {
                bVar22 = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
              }
              backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
              backdropRec2 = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
              backdropSeg = (uint16_t)((ulong)backdropRec2 >> 0x10);
              iVar14 = (int)backdropRec2;
              if (*(uint *)((int)backdropRec + 0x5b) <
                  (uint)(*(int *)(iVar14 + 0x4d) * 2 + *(int *)(iVar14 + 0x4d)) >> 1) {
                backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                backdropRec2 = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                if (*(uint *)((int)backdropRec + 0x5b) < *(uint *)((int)backdropRec2 + 0x4d)) {
                  backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                  backdropRec2 = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                  backdropSeg = (uint16_t)((ulong)backdropRec2 >> 0x10);
                  iVar14 = (int)backdropRec2;
                  if (*(uint *)((int)backdropRec + 0x5b) <
                      (uint)(*(int *)(iVar14 + 0x4d) * 2 + *(int *)(iVar14 + 0x4d)) >> 2) {
                    backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                    backdropRec2 = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                    if (*(uint *)((int)backdropRec + 0x5b) < *(uint *)((int)backdropRec2 + 0x4d) >> 1) {
                      backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                      backdropRec2 = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                      if (*(uint *)((int)backdropRec + 0x5b) < *(uint *)((int)backdropRec2 + 0x4d) >> 2) {
                        bVar19 = 5;
                      }
                      else {
                        bVar19 = 4;
                      }
                    }
                    else {
                      bVar19 = 3;
                    }
                  }
                  else {
                    bVar19 = 2;
                  }
                }
                else {
                  bVar19 = 1;
                }
              }
              else {
                bVar19 = 0;
              }
              bVar17 = 0;
              backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
              pcVar12 = (char *)_DS;
              backdropRec2 = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
              if (*(uint *)((int)backdropRec + 0x54) < (uint)(*(int *)((int)backdropRec2 + 0x4d) << 1)) {
                backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                pcVar12 = (char *)(((uint)_backdropIndex & 0xff) << 2);
                if (*(uint *)((int)backdropRec + 0x54) < ((char_sheet_t *)(pcVar12))->population) {
                  backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                  pcVar12 = (char *)_DS;
                  backdropRec2 = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                  if (*(uint *)((int)backdropRec + 0x54) < *(uint *)((int)backdropRec2 + 0x4d) >> 1) {
                    pcVar12 = (char *)_DS;
                    backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                    if (*(int *)((int)backdropRec + 0x54) < 0) {
                      backdropRec = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                      pcVar12 = (char *)_DS;
                      backdropRec2 = *(uint32_t *)(((uint)_backdropIndex & 0xff) << 2);
                      if (*(uint *)((int)backdropRec + 0x54) < (uint)-*(int *)((int)backdropRec2 + 0x4d)) {
                        bVar17 = 5;
                      }
                      else {
                        bVar17 = 4;
                      }
                    }
                    else {
                      bVar17 = 3;
                    }
                  }
                  else {
                    bVar17 = 2;
                  }
                }
                else {
                  bVar17 = 1;
                }
              }
              if (((bVar22 != 0) && (bVar19 <= bVar22)) && (bVar17 <= bVar22)) {
                ovc39_loadArchiveEntry(bVar22 + 0x12);
                ovc39_lordOrLady();
                fmtOfs = 0x9ad8;
                uStack_10 = uVar16;
                textPtr = ovr_stsprintf(acStack_2cc);
                segLo = SUB21(pcVar12,0);
                segHi = (undefined1)((uint)pcVar12 >> 8);
                pcVar12 = textPtr;
                ovr_drawString(textPtr,0,0);
                (*(uint8_t *)((uint8_t *)&(handle_05.seg))) = segLo;
                handle_05.ofs = (uint16_t)pcVar12;
                (*(uint8_t *)((uint8_t *)&(handle_05.seg) + 1)) = segHi;
                ovr_stshFree(handle_05);
                return textPtr;
              }
              if ((bVar19 != 0) && (bVar17 <= bVar19)) {
                ovc39_loadArchiveEntry(bVar19 + 0xd);
                ovc39_lordOrLady();
                fmtOfs = 0x9b2e;
                uStack_10 = uVar16;
                textPtr = ovr_stsprintf(acStack_2cc);
                segLo = SUB21(pcVar12,0);
                segHi = (undefined1)((uint)pcVar12 >> 8);
                pcVar12 = textPtr;
                ovr_drawString(textPtr,0,0);
                (*(uint8_t *)((uint8_t *)&(handle_06.seg))) = segLo;
                handle_06.ofs = (uint16_t)pcVar12;
                (*(uint8_t *)((uint8_t *)&(handle_06.seg) + 1)) = segHi;
                ovr_stshFree(handle_06);
                return textPtr;
              }
              if (bVar17 != 0) {
                ovc39_loadArchiveEntry(bVar17 + 0x17);
                ovc39_lordOrLady();
                fmtOfs = 0x9b7b;
                uStack_10 = uVar16;
                textPtr = ovr_stsprintf(acStack_2cc);
                segLo = SUB21(pcVar12,0);
                segHi = (undefined1)((uint)pcVar12 >> 8);
                pcVar12 = textPtr;
                ovr_drawString(textPtr,0,0);
                (*(uint8_t *)((uint8_t *)&(handle_07.seg))) = segLo;
                handle_07.ofs = (uint16_t)pcVar12;
                (*(uint8_t *)((uint8_t *)&(handle_07.seg) + 1)) = segHi;
                ovr_stshFree(handle_07);
                return textPtr;
              }
              ovc39_lordOrLady();
              fmtOfs = 0x9bb1;
              uStack_10 = uVar16;
              pcVar12 = ovr_stsprintf(acStack_2cc);
              ovr_drawString(pcVar12,0,0);
              return pcVar12;
            }
            unaff_DI = -2;
          }
          uVar16 = 0x236f;
          uVar11 = ovr_ovc23_findRecordAt(uVar7 + unaff_DI,0,0);
          uVar7 = CONCAT11(segHi,segLo);
        } while (uVar11 != 0xffff);
        uVar18 = 0x6f;
        uVar20 = 0x23;
        unaff_SI = (uint16_t *)
                   ovc39_findBuildingAt(CONCAT11(segHi,segLo) + unaff_DI,GfxRndSeed2);
        uVar7 = CONCAT11(uVar20,uVar18);
        backdropSeg = (uint16_t)((ulong)GUnits >> 0x10);
        in_DX = 0x2410;
        bVar19 = ((unit_t *)GUnits)[(int)unaff_SI].unitType;
        uVar11 = CONCAT11(((unit_t *)GUnits + (int)unaff_SI)->bldType,bVar19);
      } while (bVar22 != 0);
      in_DX = _DS;
      backdropRec = *(uint32_t *)((uint)bVar19 << 2);
      cVar4 = *(char *)((int)backdropRec + 0x3f);
    } while( true );
  case (char *)0x2:
    LOCK();
    iVar14 = *(int *)((char *)0x81c9 + unaff_DI);
    *(undefined1 **)((char *)0x81c9 + unaff_DI) = &stk_fffe;
    UNLOCK();
    *(int *)(iVar14 + -2) = unaff_DI;
    iVar15 = 0;
    pcVar12 = (char *)(*(uint16_t *)((uint8_t *)&(PromoteThreshold)));
    for (bVar22 = 0; textPtr = (char *)CONCAT11(0x24,GLeaderCount), bVar22 < GLeaderCount;
        bVar22 = bVar22 + 1) {
      pcVar12 = (char *)((uint)bVar22 << 2);
      if ((byte)(&stk_fffa)[(uint)_backdropIndex & 0xff] <=
          *(byte *)((int)*(uint32_t *)pcVar12 + 0xa5)) {
        for (uVar11 = 0xf8; uVar11 < GUnitCount; uVar11 = uVar11 + 1) {
          pcVar12 = 0x2410;   /* hand fix: segment-half slot */
          uVar16 = (uint16_t)((ulong)GUnits >> 0x10);
          if (((unit_t *)GUnits)[uVar11].unitType == bVar22) {
            pcVar12 = 0x2410;   /* hand fix: segment-half slot */
            if (((unit_t *)GUnits)[uVar11].level < 8) {
              *(uint16_t *)(iVar14 + -4) = (uint16_t)(CONCAT11((char)(uVar11 * 9 >> 8),bVar22));
              *(uint *)(iVar14 + -6) = uVar11;
              *(uint16_t *)(iVar14 + -8) = (uint16_t)(0x6000);
              *(uint16_t *)(iVar14 + -10) = (uint16_t)(0x8958);
              iVar5 = season_usesAlignUp42(*(int *)(iVar14 + -6),*(byte *)(iVar14 + -4));
              if ((char)iVar5 != '\0') {
                pcVar12 = 0x2410;   /* hand fix: segment-half slot */
                ((unit_t *)GUnits)[uVar11].level = 8;
                iVar15 = iVar15 + 1;
              }
            }
          }
        }
      }
    }
    if (iVar15 != 0) {
      *(uint16_t *)(iVar14 + -4) = (uint16_t)(0);
      *(uint16_t *)(iVar14 + -6) = (uint16_t)(0x24);
      *(uint16_t *)(iVar14 + -8) = (uint16_t)(0x6000);
      *(uint16_t *)(iVar14 + -10) = (uint16_t)((uint8_t *)SpecialColors + 5);
      ovr_inputUpdate(*(ulong *)(iVar14 + -6));
      *(uint16_t *)(iVar14 + -4) = (uint16_t)(0xa000);
      *(int *)(iVar14 + -6) = iVar15;
      *(uint16_t *)(iVar14 + -8) = (uint16_t)(0x2410);   /* hand fix: segment-half slot */
      *(uint16_t *)(iVar14 + -10) = (uint16_t)(0x89b2);
      uVar16 = ovr_ovc41_pluralSuffix(*(int *)(iVar14 + -6));
      *(uint16_t *)(iVar14 + -6) = (uint16_t)(pcVar12);
      *(uint16_t *)(iVar14 + -8) = (uint16_t)(uVar16);
      *(int *)(iVar14 + -10) = iVar15;
      *(uint16_t *)(iVar14 + -0xc) = (uint16_t)(0x2410);   /* hand fix: segment-half slot */
      *(uint16_t *)(iVar14 + -0xe) = (uint16_t)((char *)"%d building%s repaired.");
      *(uint16_t *)(iVar14 + -0x10) = _SS;
      *(int *)(iVar14 + -0x12) = (int)auStack_80;
      *(char **)((char *)init_textFilename + iVar14) = (char *)0x23d5;
      *(uint16_t *)(iVar14 + -0x16) = (uint16_t)(0x89c6);
      textPtr = ovr_stsprintf((char *)*(uint16_t *)(iVar14 + -0x12),
                             (char *)*(uint32_t *)(iVar14 + -0x10),
                             (char *)*(uint32_t *)(iVar14 + -0xc));
      *(uint16_t *)(iVar14 + -6) = (uint16_t)(pcVar12);
      *(uint16_t *)(iVar14 + -8) = (uint16_t)(textPtr);
      *(uint16_t *)(iVar14 + -10) = (uint16_t)((char *)0x2337);
      *(uint16_t *)(iVar14 + -0xc) = (uint16_t)(0x89d0);
      ovr_uiNotify((char *)*(uint16_t *)(iVar14 + -8),*(uint16_t *)(iVar14 + -6),0);
    }
    return textPtr;
  case (char *)0x3:
    (*(uint16_t *)((uint8_t *)&(AgntAnms[0x11]) + 18)) = (*(uint16_t *)((uint8_t *)&(AgntAnms[0x11]) + 18)) + (int)pcVar12 * 2;
    uVar11 = (*(uint16_t *)((uint8_t *)&(_streams[5]) + 3)) * -0xcc;
    ovr_stsprintf(pcVar12);
    pcVar12 = acStack_192;
    entries.seg = _SS;
    entries.ofs = (uint16_t)pcVar12;
    ovr_ovc28_compute2(entries,(uint16_t)unaff_SI,0,0,0);
    if ((char)pcVar12 != '\0') {
      segLo = auStack_1f6[((uint)pcVar12 & 0xff) * 2];
      pcVar12 = (char *)CONCAT11((char)((uint)(auStack_1f6 + ((uint)pcVar12 & 0xff) * 2) >> 8),
                                 segLo);
      backdropRec = *(uint32_t *)((uVar11 & 0xff) << 2);
      *(undefined1 *)((int)backdropRec + 0x85) = segLo;
    }
    return pcVar12;
  }
  out(*unaff_SI,in_DX);
  backdropIndex = (char)uStack_46;
  uStack0005 = (undefined1)((uint)uStack_46 >> 8);
  uVar25 = 0;
  uVar26 = 0x60;
  uVar11 = 0xa329;
  text1.seg = uStack_22;
  text1.ofs = uStack_24;
  (*(uint8_t *)((uint8_t *)&(text2.seg))) = backdropIndex;
  text2.ofs = uStack_48;
  (*(uint8_t *)((uint8_t *)&(text2.seg) + 1)) = uStack0005;
  ovc40_usesBlitLabel(text1,text2,2,0xf2);
  ovc40_flushInput();
  ovr_ovr_miceButton0PressStates_entry();
  uVar16 = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  backdropSeg = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
  uVar21 = (undefined1)uVar16;
  uVar24 = (undefined1)((uint)uVar16 >> 8);
  uVar18 = (undefined1)backdropSeg;
  uVar20 = (undefined1)((uint)backdropSeg >> 8);
  if (backdropIndex == '\x04') {
    uVar7 = ovr_inputUpdate(0xb4);
    if (1 < (byte)uVar7) {
      cStack_1d = '\x02';
    }
  }
  else {
    if (cStack_1f < '\0') {
      iVar14 = 0xee;
    }
    else {
      iVar14 = 1;
    }
    cStack_1e = 'w';
    while (cVar4 = cStack_1e + -1, bVar3 = cStack_1e != '\0', cStack_1e = cVar4, bVar3) {
      if ((iVar14 == 100) && (in_stack_0000000e == '\x02')) {
        backdropIndex = (char)marbleCut2Seg;
        uStack0005 = (undefined1)((uint)marbleCut2Seg >> 8);
        (*(uint8_t *)((uint8_t *)&(gfx.seg))) = backdropIndex;
        gfx.ofs = marbleCut2Ofs;
        (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = uStack0005;
        ovr_blitLoadRleGfx(gfx,0,0);
        backdropIndex = (char)uStack_36;
        uStack0005 = (undefined1)(uStack_36 >> 8);
        text1_00.seg = uStack_36;
        text1_00.ofs = uStack_38;
        (*(uint8_t *)((uint8_t *)&(text2_00.seg))) = backdropIndex;
        text2_00.ofs = uStack_38;
        (*(uint8_t *)((uint8_t *)&(text2_00.seg) + 1)) = uStack0005;
        ovc40_usesBlitLabel(text1_00,text2_00,0,0xf2);
        backdropIndex = (char)uStack_32;
        uStack0005 = (undefined1)(uStack_32 >> 8);
        text1_01.seg = uStack_32;
        text1_01.ofs = uStack_34;
        (*(uint8_t *)((uint8_t *)&(text2_01.seg))) = backdropIndex;
        text2_01.ofs = uStack_34;
        (*(uint8_t *)((uint8_t *)&(text2_01.seg) + 1)) = uStack0005;
        ovc40_usesBlitLabel(text1_01,text2_01,1,0xf2);
        backdropIndex = (char)uStack_2e;
        uStack0005 = (undefined1)(uStack_2e >> 8);
        uVar25 = 0xd3;
        uVar26 = 0x22;
        uVar11 = 0xa5ad;
        text1_02.seg = uStack_2e;
        text1_02.ofs = uStack_30;
        (*(uint8_t *)((uint8_t *)&(text2_02.seg))) = backdropIndex;
        text2_02.ofs = uStack_30;
        (*(uint8_t *)((uint8_t *)&(text2_02.seg) + 1)) = uStack0005;
        ovc40_usesBlitLabel(text1_02,text2_02,2,0xf2);
      }
      backdropIndex = (char)iVar14;
      ovc40_usesBlitGfx10(backdropIndex,iVar14,
                          (brect_t *)CONCAT13(segHi,CONCAT12(segLo,auStack_14)));
      uVar7 = ovr_biosKeyAvail();
      if ((char)uVar7 != '\0') {
        uVar7 = ovr_gameProcessKey();
        if (uVar7 == 0x11b) {
          cStack_1d = '\x02';
          break;
        }
        if (uVar7 == 0x1c0d) break;
      }
      uVar8 = ovr_init2_updateMouseButtons();
      if (uVar8 != 0) break;
      if (rightButtonLatch != '\0') {
        cStack_1d = '\x02';
        break;
      }
      do {
        ovr_audio_usesLDIV_at_();
        if (*(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != CONCAT11(uVar24,uVar21)) break;
      } while (*(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) == CONCAT11(uVar20,uVar18));
      uVar16 = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
      backdropSeg = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
      uVar21 = (undefined1)uVar16;
      uVar24 = (undefined1)((uint)uVar16 >> 8);
      uVar18 = (undefined1)backdropSeg;
      uVar20 = (undefined1)((uint)backdropSeg >> 8);
      iVar14 = iVar14 + cStack_1f;
    }
    if (cStack_1f < '\x01') {
      ovc40_usesBlitGfx10(0,0,(brect_t *)CONCAT13(segHi,CONCAT12(segLo,auStack_14)));
    }
    else {
      ovc40_usesBlitGfx10(0xef,0xef,(brect_t *)CONCAT13(segHi,CONCAT12(segLo,auStack_14)));
    }
    ovc40_flushInput();
    rightButtonLatch = '\0';
    if ((in_stack_0000000e == '\x02') || (in_stack_0000000e == '\x03')) {
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
      backdropSeg = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = backdropSeg;
      if (cStack_1d == '\0') {
        uVar7 = ovr_inputUpdate(0x48);
        cStack_1d = (char)uVar7;
      }
    }
    else {
      backdropIndex = (char)far_t_2000_d3e4.seg;
      uStack0005 = (undefined1)(far_t_2000_d3e4.seg >> 8);
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = backdropIndex;
      gfx_00.ofs = far_t_2000_d3e4.ofs;
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = uStack0005;
      ovr_blitLoadRleGfx(gfx_00,0,0);
      MiceProcessed = 0;
      ovr_miceBlitRect((brect_t *)(BlitRects + 1),0);
      do {
        do {
          ovr_audio_usesLDIV_at_();
          bVar22 = ovr_init2_usesCFGMice((uint16_t *)&stk_fffc,0,0);
          if ((((CONCAT11(extraout_AH,bVar22) != 0) && (0x87 < CONCAT11(uVar26,uVar25))) &&
              (0xb9 < uVar11)) && ((CONCAT11(uVar26,uVar25) < 0xd6 && (uVar11 < 0xc6))))
          goto L_OVC40_69c8_04c6_0AF0;
          if (rightButtonLatch != '\0') {
            cStack_1d = '\x02';
            goto L_OVC40_69c8_04c6_0AF0;
          }
          uVar7 = ovr_biosKeyAvail();
        } while ((char)uVar7 == '\0');
        uVar7 = ovr_gameProcessKey();
        if (uVar7 == 0x11b) {
          cStack_1d = '\x02';
          break;
        }
      } while (uVar7 != 0x1c0d);
    }
  }
L_OVC40_69c8_04c6_0AF0:
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0);
  ovr_clearMiceProcessed();
  (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uStack_16;
  handle.ofs = uStack_18;
  (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)uStack_16 >> 8);
  ovr_stshFree(handle);
  psStack_1c = ovc40_usesStshLoadGfx(0xde);
  (*(uint8_t *)((uint8_t *)&(palette.seg))) = (char)backdropSeg;
  palette.ofs = (uint16_t)psStack_1c;
  (*(uint8_t *)((uint8_t *)&(palette.seg) + 1)) = (char)((uint)backdropSeg >> 8);
  uStack_1a = backdropSeg;
  ovc40_usesVgaSetPalette8bit(palette);
  ovr_stop_audio();
  CurMusicType = 0xff;
  ovr_init_usesBlitGfxRect();
  uVar11 = (uint)GameRunning;
  if (uVar11 == 0) {
    ovc40_usesCalcSeasonPalette('\x01');
  }
  segLo = (undefined1)(uVar11 >> 8);
  ovr_ovc28_textHalflingCastle();
  ovr_ovc41_usesGMenuItem();
  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0);
  return (char *)CONCAT11(segLo,cStack_1d);
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
  memcpy(&IndexPermD,(char *)0x24106e08,0xc);
  memcpy(&IndexPermC,(char *)0x24106e14,0xc);
  memcpy(&IndexPermB,(char *)0x24106e20,0xc);
  memcpy(&IndexPermA,(char *)0x24106e2c,0xc);
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

undefined1 __cdecl16far ovc41_textParalyzed(agnt_t *source,agnt_t *victim,uint strength,uint16_t arg4,uint16_t arg5,uint16_t arg6)

{
  uint uVar1;
  char *textPtr;
  int pan;
  uint8_t *stashOfs;
  uint16_t uVar5;
  uint16_t in_DX;
  agnt_t *agnt;
  agnt_t *agnt_00;
  char *pcVar6;
  uint16_t sourceSeg;
  undefined1 uVar8;
  undefined1 savedSeg;
  undefined1 uVar10;
  uint8_t victimName;
  uint8_t sourceName;
  uint8_t msg;
  undefined1 resolved;
  
  resolved = 0;
  pcVar6 = (char *)((ulong)victim >> 0x10);
  agnt = (agnt_t *)victim;
  if ((agnt->flags & 0x80) != 0) {
    strength = (uint)agnt->strength;
  }
  agnt_00 = (agnt_t *)source;
  sourceSeg = (uint16_t)((ulong)source >> 0x10);
  uVar10 = (undefined1)((ulong)victim >> 0x10);
  if ((int)strength < (int)(uint)agnt->strength) {
    agnt->timer = 0x6;
    agnt->combatState = 0x1;
    agnt->targetY = 0;
    ovr_agnt_usesAnimFrame(agnt,uVar10);
    if (((agnt->animVariant == 0x0) && ((agnt->flags & 0x200) == 0)) &&
       ((((agntG_t *)agnt_00->gdata)->flags & 0x40) != 0)) {
      savedSeg = (undefined1)GSavedBlitSeg;
      textPtr = ovr_agnt_statusText(agnt_00,(char *)CONCAT13((char)((uint)&victimName >> 8),
                                                            CONCAT12((char)&victimName,sourceSeg)),0);
      uVar8 = SUB21(textPtr,0);
      uVar5 = in_DX;
      textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&sourceName,pcVar6),0);
      stashOfs = ovr_ovc15_usesStshRealloc(textPtr,in_DX,uVar8,uVar5,savedSeg,0,0,0);
      textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6f63,_SS),
                             (char *)CONCAT22(stashOfs,(char *)0x26510),in_DX);
      ovr_uiNotify(textPtr,in_DX,0);
      uVar5 = ovr_audio_panFromX(agnt,uVar10);
      ovr_play_sfxU(3,0,uVar5,(char)uVar5,0);
      OVC41_6a8f_01e7_entry(agnt,uVar10);
      agnt->flags = agnt->flags | 0x200;
      ovr_attact_usesLDIV_at_2();
      return resolved;
    }
    if (((agnt->animVariant == 0x0) && ((agnt->flags & 0x800) == 0)) &&
       (((((agntG_t *)agnt_00->gdata)->flags3 & 0x100) != 0 &&
        (uVar1 = ovr_ovc27_rollToHitEntity((uint32_t)victim,2), (uVar1 & 0xff) == 0)))) {
      savedSeg = (undefined1)GSavedBlitSeg;
      textPtr = ovr_agnt_statusText(agnt_00,(char *)CONCAT13((char)((uint)&victimName >> 8),
                                                            CONCAT12((char)&victimName,sourceSeg)),0);
      uVar8 = SUB21(textPtr,0);
      uVar5 = in_DX;
      textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&sourceName,pcVar6),0);
      stashOfs = ovr_ovc15_usesStshRealloc(textPtr,in_DX,uVar8,uVar5,savedSeg,0,0,0);
      textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6f7a,_SS),
                             (char *)CONCAT22(stashOfs,(char *)0x26510),in_DX);
      ovr_uiNotify(textPtr,in_DX,0);
      agnt->flags = agnt->flags | 0x800;
      uVar5 = ovr_audio_panFromX(agnt,uVar10);
      ovr_play_sfxU(0x1b,0,uVar5,(char)uVar5,0);
      OVC41_6a8f_01e7_entry(agnt,uVar10);
      ovr_attact_usesLDIV_at_2();
      return resolved;
    }
    agnt->strength = agnt->strength - (char)strength;
    if (((((agntG_t *)agnt_00->gdata)->flags & 0x8000) == 0) ||
       ((((agntG_t *)agnt->gdata)->flags & 0x8000) == 0)) {
      if (((agntG_t *)agnt_00->gdata)->hitSound == 0) {
        pan = ovr_audio_panFromX(agnt,uVar10);
        uVar10 = (undefined1)pan;
        uVar8 = (undefined1)((uint)pan >> 8);
        pan = 0;
        uVar5 = ovr_randBelow(2,0);
        ovr_play_sfxU((char)uVar5 + 0x3d,pan,CONCAT11(uVar8,uVar10),uVar10,0);
      }
      else if (((agntG_t *)agnt_00->gdata)->hitSound == 0x15) {
        uVar5 = ovr_randBelow(2,0);
        if ((uVar5 & 0xff) == 0) {
          ovr_play_sfx(21,0,0);
        }
        else {
          ovr_play_sfx(71,0,0);
        }
      }
      else if (((agntG_t *)agnt_00->gdata)->hitSound == 3) {
        pan = ovr_audio_panFromX(agnt,uVar10);
        uVar10 = (undefined1)pan;
        uVar8 = (undefined1)((uint)pan >> 8);
        pan = 0;
        uVar5 = ovr_randBelow(2,0);
        ovr_play_sfxU((char)uVar5 + 0x14,pan,CONCAT11(uVar8,uVar10),uVar10,0);
      }
      else {
        ovr_play_sfx((uint)((agntG_t *)agnt_00->gdata)->hitSound,0,0);
      }
    }
    else {
      pan = ovr_audio_panFromX(agnt,uVar10);
      uVar10 = (undefined1)pan;
      uVar8 = (undefined1)((uint)pan >> 8);
      pan = 0;
      uVar5 = ovr_randBelow(2,0);
      ovr_play_sfxU((char)uVar5 + 0x14,pan,CONCAT11(uVar8,uVar10),uVar10,0);
    }
    if ((agnt_00->flags & 0x20) != 0) {
      agnt_00->flags = agnt_00->flags & 0xffdf;
      uVar10 = (undefined1)GSavedBlitSeg;
      pcVar6 = ovr_agnt_statusText(agnt,(char *)CONCAT13((char)((uint)&sourceName >> 8),
                                                         CONCAT12((char)&sourceName,pcVar6)),0);
      stashOfs = ovr_ovc15_usesStshRealloc(pcVar6,in_DX,uVar10,0,0,0,0,0);
      pcVar6 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6f8e,_SS),
                             (char *)CONCAT13((char)((uint)stashOfs >> 8),
                                              CONCAT12((char)stashOfs,0x2410)),(char)stashOfs,in_DX);
      ovr_uiNotify(pcVar6,in_DX,0);
      agnt_00->faction = agnt_00->gdata->ai;
      ovc41_advanceAnimFrame(agnt_00,(char)((ulong)source >> 0x10));
      ovr_attact_usesLDIV_at_2();
    }
  }
  else {
    if (((agntG_t *)agnt->gdata)->actSound == 0xff) {
      uVar5 = ovr_audio_panFromX(agnt,uVar10);
      ovr_play_sfxU(4,0,uVar5,(char)uVar5,0);
    }
    else {
      uVar5 = ovr_audio_panFromX(agnt,uVar10);
      ovr_play_sfxU(((agntG_t *)agnt->gdata)->actSound,0,uVar5,(char)uVar5,0);
    }
    ovc41_settleAgentCombat(source,victim,0);
    resolved = 1;
  }
  ovr_attact_usesLDIV_at_2();
  return resolved;
}



/* 6a8f:2084 */
byte * __cdecl16far ovc41_textOnlyPlaceSingle(agnt_t *agntPtr,int agntIndex)

{
  undefined1 stk_6ffe;   /* stack slot 6ffe */
  undefined1 stk_fecc;   /* stack slot fecc */
  undefined1 stk_fed4;   /* stack slot fed4 */
  undefined1 stk_fed6;   /* stack slot fed6 */
  undefined1 stk_fed8;   /* stack slot fed8 */
  undefined1 stk_feda;   /* stack slot feda */
  undefined1 stk_fedc;   /* stack slot fedc */
  undefined1 stk_fef4;   /* stack slot fef4 */
  undefined1 stk_fffe;   /* stack slot fffe */
  undefined1 stk_ffff;   /* stack slot ffff */
  char *pcVar1;
  uint16_t uVar2;
  char cVar3;
  agnt_t *paVar4;
  code *pcVar5;
  far_t dst;
  far_t gfx;
  far_t gfx_00;
  far_t dst_00;
  far_t gfx_01;
  far_t dst_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t dst_02;
  far_t dst_03;
  byte bVar6;
  char *pcVar7;
  byte *pbVar8;
  undefined1 extraout_AH;
  brect_t *br;
  agnt_t *paVar9;
  uint16_t uVar10;
  uint8_t *puVar11;
  int iVar12;
  char cVar13;
  uint8_t *puVar14;
  agnt_t *paVar15;
  uint uVar16;
  agnt_t *paVar17;
  undefined1 *puVar18;
  int unaff_SI;
  uint16_t *unaff_DI;
  char *pcVar19;
  int iVar20;
  char acStack_1aa [104];
  uint16_t uStack_142;
  uint16_t uStack_140;
  char *pcStack_13e;
  uint16_t *count;
  uint32_t drawPtr;
  bool type;
  undefined1 uVar21;
  uint16_t uVar22;
  uint8_t uStack_120;
  undefined1 uStack_11f;
  undefined1 uStack_11e;
  undefined1 uStack_11d;
  uint16_t uStack_10e;
  uint8_t text;
  uint8_t msg;
  char acStack_80 [62];
  char acStack_42 [6];
  byte bStack_3c;
  byte bStack_3b;
  uint uStack_3a;
  agnt_t *paStack_38;
  agnt_t *paStack_36;
  agnt_t *paStack_34;
  agnt_t *paStack_32;
  agnt_t *paStack_30;
  agnt_t *paStack_2e;
  agnt_t *paStack_2c;
  agnt_t *paStack_2a;
  agnt_t *paStack_28;
  agnt_t *paStack_26;
  agnt_t *paStack_24;
  agnt_t *paStack_22;
  agnt_t *paStack_20;
  agnt_t *paStack_1e;
  agnt_t *agnt;   /* hand fix: assigned from agnt_t * paStack_N and indexed */
  uint16_t uStack_1a;
  uint16_t uStack_18;
  brect_t bStack_16;
  agnt_t *paStack_c;
  int iStack_a;
  uint16_t uStack_8;
  far_t fStack_6;
  
  iVar12 = 0x10;
  pcStack_13e = (char *)0x6a8f;
  uStack_140 = 0xc98c;
  dst.seg = (uint16_t)_SS;
  dst.ofs = (uint16_t)&agnt;
  count = _SS;
  F_SCOPY(far_from_u32((uint32_t)(0x24106e38)),dst);
  paVar4 = (agnt_t *)((long)agntIndex * 0x34);
  paVar9 = (agnt_t *)paVar4;
  paStack_c = paVar9;
  iStack_a = SEG_OF(Agnts);
  if ((paVar9->flags & 0x820) == 0) {
    pcVar19 = (char *)((ulong)agntPtr >> 0x10);
    paVar17 = (agnt_t *)agntPtr;
    paVar17->flags = paVar17->flags & 0xfff7;
    if ((((entity_t *)paVar17->entity)->base).level < 8) {
      fStack_6 = far_from_u32((uint32_t)(far_to_u32(fStack_6) & 0xffffff));
    }
    else if ((((entity_t *)paVar17->entity)->base).level < 10) {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = 1;
    }
    else if ((((entity_t *)paVar17->entity)->base).level < 0xc) {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = 2;
    }
    else {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = 3;
    }
    uVar16 = (uint)(*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1));
    type = SUB21(_SS,0);
    uVar21 = (undefined1)((uint)_SS >> 8);
    if (uVar16 < 4) {
      iVar20 = 0x6000;
      switch(uVar16) {
      case 0:
        return (byte *)((int)(uint32_t *)&_DATA + 1);
      case 2:
        cVar3 = *(char *)(uVar16 * 2 + unaff_SI);
        puVar18 = &stk_fffe + unaff_SI;
        iVar20 = uVar16 * 3;
        *(undefined1 **)((char *)0x7501 + iVar20) =
             puVar18 + *(int *)((char *)0x7501 + iVar20);
        *(int *)(&stk_ffff + (int)puVar18) = *(int *)(&stk_ffff + (int)puVar18) + iVar20;
        *(int *)(&stk_fffe + (int)unaff_DI) = *(int *)(&stk_fffe + (int)unaff_DI) + iVar20;
                    /* WARNING: Read-only address (ram,0x00033501) is written */
        iRam00033501 = uVar16 + 0x8b26;
        cVar13 = (char)(&stk_fed8 + (int)unaff_DI +
                       CONCAT11((char)((ulong)paVar4 >> 0x18),(char)((ulong)paVar4 >> 0x10) + cVar3)
                       );
        pcVar19 = (char *)(uint)(byte)((char)iVar20 + cVar13);
        (&stk_6ffe)[(int)puVar18] = (&stk_6ffe)[(int)puVar18];
        pcVar1 = pcVar19;
        *pcVar1 = *pcVar1 + cVar13;
        *(uint16_t *)(&stk_fed6 + (int)unaff_DI) = 0x6000;
        pcVar1 = pcVar19 + -0x61f9;
        *pcVar1 = *pcVar1;
        cVar13 = *pcVar1;
        *(undefined1 **)(&stk_feda + (int)unaff_DI) = &stk_fedc + (int)unaff_DI;
        uVar22 = *(uint16_t *)(&stk_feda + (int)unaff_DI);
        *(uint16_t *)(&stk_feda + (int)unaff_DI) = uVar22;
        if (iVar12 == 1 || cVar13 == '\0') {
          ((char *)0x06a4)[10] = -0x6b;
          ((char *)0x06a4)[0xb] = '\x06';
                    /* WARNING: Read-only address (ram,0x000247ae) is written */
        }
        uVar2 = in(&stk_fed8 + (int)unaff_DI +
                   CONCAT11((char)((ulong)paVar4 >> 0x18),(char)((ulong)paVar4 >> 0x10) + cVar3));
        *unaff_DI = uVar2;
        *(uint16_t *)(&stk_fed8 + (int)unaff_DI) = uVar22;
        *(uint16_t *)(&stk_fed6 + (int)unaff_DI) = uVar22;
        *(uint16_t *)(&stk_fed4 + (int)unaff_DI) = uVar22;
        *(uint16_t *)(&stk_fed4 + (int)unaff_DI) =
             *(uint16_t *)(&stk_fed4 + (int)unaff_DI);
        pcVar5 = (code *)swi(1);
        pbVar8 = (byte *)(*pcVar5)();
        return pbVar8;
      case 3:
        do {
          TextBlitDstSeg = 0xa000;
          TextBlitX = uStack_8 + 6;
          TextBlitY = (uint16_t)(unaff_DI + 1);
          (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)(&paVar17->x + unaff_SI * 2)[1];
          puVar14 = (uint8_t *)(&paVar17->x)[unaff_SI * 2];
          fStack_6.seg = (uint16_t)(agnt_t *)drawPtr;
          fStack_6.ofs = (uint16_t)puVar14;
          iVar12 = unaff_SI;
          if (*(uint8_t *)MK_FP(fStack_6.seg, fStack_6.ofs) == 0x25) {
            BlitLetterType = 2;
            uVar22 = 0x13f;
            (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = FontMain.ofs;
            pcVar7 = (char *)ovr_ovc45_compute9(acStack_80,(char *)CONCAT22(puVar14 + 1,_SS),
                                                (char *)CONCAT22(FontMain.ofs,(agnt_t *)drawPtr),
                                                FontMain.seg,'E');
            ovr_blitLabel(pcVar7,(uint8_t *)CONCAT22(uVar22,puVar14),15,uStack_120);
            pbVar8 = (byte *)((char *)0x2410);
            BlitLetterType = 0;
          }
          else if (*(uint8_t *)MK_FP(fStack_6.seg, fStack_6.ofs) == 0x40) {
            uVar22 = 0x13f;
            (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = FontMain.ofs;
            pcVar7 = (char *)ovr_ovc45_compute9(acStack_80,(char *)CONCAT22(puVar14 + 1,_SS),
                                                (char *)CONCAT22(FontMain.ofs,(agnt_t *)drawPtr),
                                                FontMain.seg,'E');
            pbVar8 = (byte *)ovr_blitLabel(pcVar7,(uint8_t *)CONCAT22(uVar22,puVar14),15,uStack_120)
            ;
          }
          else {
            uVar22 = 0x13f;
            (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = FontMain.ofs;
            (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)(&paVar17->x + unaff_SI * 2)[1];
            pcVar7 = (char *)ovr_ovc45_compute9(acStack_80,
                                                (char *)CONCAT22((&paVar17->x)[unaff_SI * 2],
                                                                 _SS),
                                                (char *)CONCAT22(FontMain.ofs,(agnt_t *)drawPtr),
                                                FontMain.seg,'E');
            pbVar8 = (byte *)ovr_blitLabel(pcVar7,(uint8_t *)CONCAT22(uVar22,puVar14),15,uStack_120)
            ;
          }
          while( true ) {
            unaff_DI = unaff_DI + 7;
            unaff_SI = iVar12 + 1;
            if (agntIndex <= unaff_SI) {
              if (goldPartyIndex != 0xff) {
                pbVar8 = (byte *)CONCAT11((char)((uint)pbVar8 >> 8),goldPartyIndex);
                ovc28_drawGold(goldPartyIndex);
              }
              return pbVar8;
            }
            if ((&paVar17->targetX)[iVar12 * 2] != 0 || (&paVar17->targetX + iVar12 * 2)[1] != 0)
            break;
            pbVar8 = (byte *)0x0;
            iVar12 = unaff_SI;
          }
          uStack_11e = (undefined1)butt01Cut5Seg;
          uStack_11d = (undefined1)((uint)butt01Cut5Seg >> 8);
          uStack_120 = (uint8_t)butt01Cut5Ofs;
          (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = uStack_11e;
          gfx_03.ofs = butt01Cut5Ofs;
          (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) = uStack_11d;
          (*(uint8_t *)((uint8_t *)&(dst_03.seg))) = 0;
          dst_03.ofs = uStack_8 + (int)unaff_DI * 0x140;
          (*(uint8_t *)((uint8_t *)&(dst_03.seg) + 1)) = 0xa0;
          ovr_blitLoadRleGfx(gfx_03,dst_03,0);
        } while( true );
      }
switchD_6000_ca06_caseD_1:
      (&stk_fffe)[(int)unaff_DI] = (&stk_fffe)[(int)unaff_DI] + (char)iVar12;
      *(undefined1 *)((int)unaff_DI + 0x15) = 0;
      (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)0x6a64;
      (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = iVar20;
      bStack_3b = ovr_init2_usesCFGMice
                            ((uint16_t *)&paStack_2e,(uint16_t *)
                             CONCAT13((char)((uint)&paStack_30 >> 8),
                                      CONCAT12((char)&paStack_30,_SS)),0);
      while( true ) {
        if (rightButtonLatch != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((paStack_2e != paStack_2a) || (paStack_30 != paStack_2c)) {
          paStack_2a = paStack_2e;
          agnt = paStack_2e;
          paStack_2c = paStack_30;
          paStack_1e = paStack_30;
        }
        if (bStack_3b != 0) break;
        (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = 0x22de;
        (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)0x69b5;
        uVar22 = keyprocessor_usesBiosKeyAvail
                           ((uint16_t *)CONCAT13(uVar21,CONCAT12(type,&paStack_36)),
                            (uint16_t *)CONCAT22(_SS,&paStack_38),
                            (byte *)CONCAT22(_SS,&bStack_3b));
        if ((char)uVar22 != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((paStack_36 != paStack_32) || (paStack_38 != paStack_34)) {
          paStack_32 = paStack_36;
          agnt = paStack_36;
          paStack_34 = paStack_38;
          paStack_1e = paStack_38;
          bStack_16.seg = uStack_8;
          gfx_00.seg = uStack_18;
          gfx_00.ofs = uStack_1a;
          dst_00.seg = uStack_8;
          dst_00.ofs = 0x8cc;
          ovr_blitLoadRleGfx(gfx_00,dst_00,0);
          (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = 0x6a2a;
          (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)MiceCursors[3].seg;
          gfx.ofs = MiceCursors[3].ofs;
          (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)(MiceCursors[3].seg >> 8);
          ovr_blitGfx10(gfx,(uint16_t)&paStack_36[-1].variant,(uint16_t)&paStack_38[-1].faction,&bStack_16,type,0,0);
          ovr_miceBlitRect(&bStack_16,0);
          ovr_blitRect(&bStack_16,0);
          ovr_miceUpdate();
        }
        iVar20 = 0x22de;
        if (bStack_3b == 0) goto switchD_6000_ca06_caseD_1;
      }
      if (((((int)agnt < 0xc) || (0xde < (int)agnt)) || ((int)paStack_1e < 7)) ||
         (0x96 < (int)paStack_1e)) goto L_ui_unit_order_6616_0689_1054;
      do {
        iVar12 = 0x22de;
        (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)0x6ae3;
        bVar6 = ovr_init2_usesCFGMice
                          ((uint16_t *)&paStack_2e,(uint16_t *)CONCAT22(&paStack_30,_SS),0);
      } while (CONCAT11(extraout_AH,bVar6) != 0);
      paStack_26 = (agnt_t *)0xffff;
      paStack_28 = (agnt_t *)0xffff;
      paStack_20 = paStack_1e;
      bStack_3b = 0;
      paVar9 = agnt;
      do {
        (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)0x6b14;
        (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = iVar12;
        uVar22 = keyprocessor_usesBiosKeyAvail
                           ((uint16_t *)CONCAT13(uVar21,CONCAT12(type,&paStack_36)),
                            (uint16_t *)CONCAT22(_SS,&paStack_38),
                            (byte *)CONCAT22(_SS,&bStack_3b));
        if ((char)uVar22 != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((paStack_36 != paStack_32) || (paStack_38 != paStack_34)) {
          paStack_32 = paStack_36;
          paStack_34 = paStack_38;
          paStack_20 = paStack_38;
          paVar9 = paStack_36;
        }
        if ((int)paVar9 < 0xc) {
          paVar9 = (agnt_t *)((byte *)__C0_ASM_CopyRight + 8);
        }
        if (0xde < (int)paVar9) {
          paVar9 = (agnt_t *)0xde;
        }
        if ((int)paStack_20 < 7) {
          paStack_20 = (agnt_t *)((byte *)__C0_ASM_CopyRight + 3);
        }
        if (0x96 < (int)paStack_20) {
          paStack_20 = (agnt_t *)((char *)0x96);
        }
        if ((paStack_26 != paVar9) || (paStack_28 != paStack_20)) {
          bStack_16.seg = uStack_8;
          uStack_120 = (uint8_t)uStack_8;
          uStack_11f = (undefined1)(uStack_8 >> 8);
          gfx_01.seg = uStack_18;
          gfx_01.ofs = uStack_1a;
          (*(uint8_t *)((uint8_t *)&(dst_01.seg))) = uStack_120;
          dst_01.ofs = 0x8cc;
          (*(uint8_t *)((uint8_t *)&(dst_01.seg) + 1)) = uStack_11f;
          ovr_blitLoadRleGfx(gfx_01,dst_01,0);
          ovr_driver_drawLine((uint8_t *)agnt,(int)paStack_1e,(uint8_t *)paVar9,(int)paStack_1e,0xff,0,0,0,0);
          ovr_driver_drawLine((uint8_t *)agnt,(int)paStack_1e,(uint8_t *)agnt,(int)paStack_20,0xff,0,0,0,0);
          ovr_driver_drawLine((uint8_t *)paVar9,(int)paStack_1e,(uint8_t *)paVar9,(int)paStack_20,0xff,0,0,0,0);
          ovr_driver_drawLine((uint8_t *)agnt,(int)paStack_20,(uint8_t *)paVar9,(int)paStack_20,0xff,0,0,0,0);
          ovr_miceBlitRect(&bStack_16,0);
          ovr_blitRect(&bStack_16,0);
          ovr_miceUpdate();
          paVar17 = (agnt_t *)((int)&paStack_20[-1].flags / 3 + Seed_2000_d10e);
          paVar15 = (agnt_t *)(Seed_2000_d110 + ((uint)&paVar9[-1].screenY >> 1) + 2 & 0xfffc);
          paStack_24 = (agnt_t *)((int)&paStack_1e[-1].flags / 3 + Seed_2000_d10e);
          paStack_22 = (agnt_t *)(Seed_2000_d110 + ((uint)&agnt[-1].screenY >> 1) + 2 & 0xfffc);
          paStack_26 = paVar15;
          if ((int)paVar15 < (int)paStack_22) {
            paStack_26 = paStack_22;
            paStack_22 = paVar15;
            paStack_c = paVar15;
          }
          paStack_28 = paVar17;
          if ((int)paVar17 < (int)paStack_24) {
            paStack_28 = paStack_24;
            paStack_24 = paVar17;
            paStack_c = paVar17;
          }
          iStack_a = 0;
          for (uVar16 = 0; uVar16 < EntityCount; uVar16 = uVar16 + 1) {
            uVar22 = (uint16_t)((ulong)Entities >> 0x10);
            iVar12 = (int)Entities;
            if ((((AGNT_FIELD(&((entity_t *)Entities)[uVar16], base.entity, 3) == bStack_3c) &&
                 (paStack_22 <= (agnt_t *)*(uint *)((entity_t *)iVar12 + uVar16))) &&
                ((agnt_t *)*(uint *)((entity_t *)iVar12 + uVar16) <= paStack_26)) &&
               ((paStack_24 <= (agnt_t *)((entity_t *)iVar12)[uVar16].base.y &&
                ((agnt_t *)((entity_t *)iVar12)[uVar16].base.y <= paStack_28)))) {
              iStack_a = iStack_a + 1;
            }
          }
          ovr_resetTextBlitCycle();
          ovr_ovc45_compute9(acStack_1aa,
                             (char *)CONCAT22(*(uint16_t *)((uint)bStack_3c * 4),_SS),
                             (char *)CONCAT22(Font03.ofs,
                                              (char *)((uint16_t *)((uint)bStack_3c * 4))[1]),
                             Font03.seg,'C');
          ovr_ovc41_pluralSuffix(iStack_a);
          uVar10 = 0x2410;
          pcVar19 = ovr_stsprintf((char *)&drawPtr,(char *)CONCAT22(0x64b8,_SS),
                                  (char *)CONCAT22(iStack_a,(char *)0x2410));
          iVar12 = 0x22c4;
          ovr_uiNotify(pcVar19,uVar10,0);
        }
        paStack_28 = paStack_20;
        paStack_26 = paVar9;
        if (bStack_3b == 0) {
          iVar12 = 0x22de;
          (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)0x6e04;
          bStack_3b = ovr_init2_usesCFGMice
                                ((uint16_t *)&paStack_2e,(uint16_t *)CONCAT22(&paStack_30,_SS),0)
          ;
        }
        if (rightButtonLatch != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((paStack_2e != paStack_2a) || (paStack_30 != paStack_2c)) {
          paStack_2a = paStack_2e;
          paStack_2c = paStack_30;
          paStack_20 = paStack_30;
          paVar9 = paStack_2e;
        }
      } while (bStack_3b == 0);
      uStack_142 = 0x6e56;
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0);
      if (((((int)paVar9 < 0xc) || (0xde < (int)paVar9)) || ((int)paStack_20 < 7)) ||
         (0x96 < (int)paStack_20)) {
L_ui_unit_order_6616_0689_1054:
        ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0);
        ovr_say((char *)"Region selection aborted.",0);
      }
      else {
        paVar17 = (agnt_t *)((int)&paStack_20[-1].flags / 3 + Seed_2000_d10e);
        paVar15 = (agnt_t *)(Seed_2000_d110 + ((uint)&paVar9[-1].screenY >> 1) + 2 & 0xfffc);
        paVar9 = (agnt_t *)((int)&paStack_1e[-1].flags / 3 + Seed_2000_d10e);
        uVar16 = Seed_2000_d110 + ((uint)&agnt[-1].screenY >> 1) + 2;
        paStack_22 = (agnt_t *)(uVar16 & 0xfffc);
        paStack_26 = paVar15;
        if ((int)paVar15 < (int)paStack_22) {
          paStack_c = (agnt_t *)(uVar16 & 0xfffc);
          paStack_26 = paStack_c;
          paStack_22 = paVar15;
        }
        paStack_28 = paVar17;
        paStack_24 = paVar9;
        if ((int)paVar17 < (int)paVar9) {
          paStack_28 = paVar9;
          paStack_24 = paVar17;
          paStack_c = paVar9;
        }
        pcStack_13e = acStack_42;
        uStack_140 = 0x22de;
        uStack_142 = 0x6f2a;
        _fmemset((void *)ZEXT24(_SS),5,(uint16_t)count);
        iStack_a = 0;
        for (uVar16 = 0; uVar16 < EntityCount; uVar16 = uVar16 + 1) {
          uVar22 = (uint16_t)((ulong)Entities >> 0x10);
          iVar12 = (int)Entities;
          if (((AGNT_FIELD(&((entity_t *)Entities)[uVar16], base.entity, 3) == bStack_3c) &&
              (paStack_22 <= (agnt_t *)*(uint *)((entity_t *)iVar12 + uVar16))) &&
             (((agnt_t *)*(uint *)((entity_t *)iVar12 + uVar16) <= paStack_26 &&
              ((paStack_24 <= (agnt_t *)((entity_t *)iVar12)[uVar16].base.y &&
               ((agnt_t *)((entity_t *)iVar12)[uVar16].base.y <= paStack_28)))))) {
            if (bStack_3b < 2) {
              unit_usesAlignUp42((byte)agntPtr,*(uint16_t *)((entity_t *)iVar12 + uVar16),
                                 ((entity_t *)iVar12)[uVar16].base.y);
            }
            else {
              pcStack_13e = (char *)0x6fdf;
              unit_usesEntities(bStack_3b,uVar16,(uint16_t)acStack_42,(uint16_t)_SS);
            }
            iStack_a = iStack_a + 1;
          }
        }
        for (uStack_3a = 0; (int)uStack_3a < 5; uStack_3a = uStack_3a + 1) {
          if (acStack_42[uStack_3a] != '\0') {
            ovr_ovc41_usesMiceBlitRect(uStack_3a);
          }
        }
        ovr_constr_flushDirtyRects();
        (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = 0x22ef;
        (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)0x7063;
        ovr_resetTextBlitCycle();
        if (bStack_3b == 1) {
          (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = 0x7071;
          ovr_ovc41_pluralSuffix(iStack_a);
          (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = iStack_a;
          (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)0x2410;
          pcVar19 = ovr_stsprintf((char *)&drawPtr,(char *)CONCAT22(0x6522,_SS),
                                  (char *)CONCAT22(iStack_a,(char *)0x2410));
          ovr_say(pcVar19,0);
        }
        else if (bStack_3b == 2) {
          (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = 0x70bf;
          ovr_ovc41_pluralSuffix(iStack_a);
          (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = iStack_a;
          (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)0x2410;
          pcVar19 = ovr_stsprintf((char *)&drawPtr,(char *)CONCAT22(0x6543,_SS),
                                  (char *)CONCAT22(iStack_a,(char *)0x2410));
          ovr_say(pcVar19,0);
        }
        else if (bStack_3b == 3) {
          (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = 0x710d;
          ovr_ovc41_pluralSuffix(iStack_a);
          (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = iStack_a;
          (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)0x2410;
          pcVar19 = ovr_stsprintf((char *)&drawPtr,(char *)CONCAT22(0x6557,_SS),
                                  (char *)CONCAT22(iStack_a,(char *)0x2410));
          ovr_say(pcVar19,0);
        }
        else if (bStack_3b == 4) {
          (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = 0x715a;
          ovr_ovc41_pluralSuffix(iStack_a);
          (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = iStack_a;
          (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)0x2410;
          pcVar19 = ovr_stsprintf((char *)&drawPtr,(char *)CONCAT22(0x6568,_SS),
                                  (char *)CONCAT22(iStack_a,(char *)0x2410));
          ovr_say(pcVar19,0);
        }
        ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
      }
      bStack_16.seg = uStack_8;
      uStack_120 = (uint8_t)uStack_18;
      uStack_11f = (undefined1)(uStack_18 >> 8);
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = uStack_120;
      gfx_02.ofs = uStack_1a;
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = uStack_11f;
      dst_02.seg = uStack_8;
      dst_02.ofs = 0x8cc;
      ovr_blitLoadRleGfx(gfx_02,dst_02,0);
      ovr_miceBlitRect(&bStack_16,0);
      br = &bStack_16;
      ovr_blitRect(br,0);
      ovr_miceUpdate();
      stk_fef4 = uStack_18;
      uStack_10e = uStack_1a;
      ovr_stshFree(uStack_10e);
      ovr_stshFree(fStack_6);
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0);
      return (byte *)br;
    }
    bVar6 = paVar9->strength;
    paVar9->strength = paVar9->strength + (char)fStack_6.ofs;
    if (paVar9->strengthMax < paVar9->strength) {
      paVar9->strength = paVar9->strengthMax;
    }
    puVar14 = &paVar9->strength;
    paVar9 = (agnt_t *)(uint)*puVar14;
    if (*puVar14 != bVar6) {
      (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = 0xcae7;
      (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = bVar6;
      uVar10 = ovr_audio_panFromX(paVar17,0);
      ovr_play_sfxU(0x3b,0,uVar10,0,0);
      ovc41_pluralSuffix((uint)paStack_c->strength);
      ovc41_pluralSuffix((uint)paStack_c->strength - (uint)(*(uint8_t *)((uint8_t *)&(uStack_8) + 1)));
      (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = 0x22f8;
      (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)0xcb5a;
      ovr_agnt_statusText(paStack_c,(char *)CONCAT13((char)((uint)&stk_fecc >> 8),
                                           CONCAT12((char)&stk_fecc,iStack_a)),0);
      puVar14 = &agnt;
      drawPtr = (uint16_t)agntPtr;
      pcVar19 = ovr_agnt_statusText(paVar17,(char *)CONCAT22(&text,pcVar19),0);
      puVar11 = ovr_ovc15_usesStshRealloc(pcVar19,0,0,0,0,0,0,0);
      (*(uint16_t *)((uint8_t *)&(drawPtr) + 2)) = 0x2322;
      (*(uint16_t *)((uint8_t *)&(drawPtr))) = (uint16_t)(agnt_t *)0xcba4;
      paVar9 = (agnt_t *)
               ovr_stsprintf((char *)&msg,(char *)CONCAT13(0x6f,CONCAT12(0xeb,_SS)),
                             (char *)CONCAT22(puVar11,(char *)0x2410));
      ovr_uiNotify((char *)paVar9,(uint16_t)puVar14,0);
    }
  }
  return (byte *)paVar9;
}


/* 6a8f:22cb */
void __cdecl16far ovc41_specialAttack(agnt_t *agnt,int targetIndex,uint16_t arg3,uint16_t arg4)

{
  uint *flagsPtr;
  agntG_t *targetGdata;
  entity_t *targetEnt;
  byte bVar4;
  uint16_t uVar5;
  agnt_t *targetAgnt;
  int iVar6;
  char *textPtr;
  uint8_t *stashOfs;
  uint16_t uVar9;
  uint16_t uVar10;
  uint damage;
  int in_stack_00000008;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  uint8_t actorName;
  uint8_t targetName;
  uint8_t msg;
  agnt_t far *agntPtr;   /* was uint32_t: assigned agnt_t * values */
  char resolved;
  
  uVar13 = (undefined1)targetIndex;
  uVar14 = (undefined1)((uint)targetIndex >> 8);
  uVar5 = ovc41_turnUndeadNotice((agnt_t *)CONCAT13(uVar14,CONCAT12(uVar13,agnt)));
  if ((((char)uVar5 == '\0') && (-1 < in_stack_00000008)) &&
     (in_stack_00000008 < (int)(uint)AgntCount)) {
    uVar10 = (uint16_t)((ulong)((long)in_stack_00000008 * 0x34) >> 0x10);
    targetAgnt = (agnt_t *)(agnt_t *)((long)in_stack_00000008 * 0x34);
    agntPtr = (agnt_t *)CONCAT22(SEG_OF(Agnts),targetAgnt);
    if (targetAgnt->animVariant == 0x0) {
      *(undefined1 *)&targetAgnt->targetX = 0;
      *(undefined1 *)((int)&targetAgnt->targetX + 1) = 0;
    }
    if ((agnt->flags & 8) == 0) {
      if (agnt->variant == 0x0) {
        if ((agnt->gindex == 0x4) && ((((agntG_t *)agnt->gdata)->flags2 & 0x200) != 0)) {
          bVar4 = agnt->strength;
          uVar5 = ovr_ovc27_breathHalfDamage(targetAgnt,0x26);
          damage = (uint)bVar4;
          if ((char)uVar5 != '\0') {
            damage = (int)(uint)bVar4 >> 1;
          }
        }
        else {
          bVar4 = ovr_manage_rollDice(((agntG_t *)agnt->gdata)->dmgDice,
                                      ((agntG_t *)agnt->gdata)->dmgSides);
          iVar6 = (uint)bVar4 + (uint)((agntG_t *)agnt->gdata)->dmgBonus;
          bVar4 = ovr_agnt_compute9(agnt,uVar13);
          uVar10 = iVar6 + (char)bVar4;
          damage = uVar10;
        }
        if ((damage != 0) && ((((agntG_t *)agnt->gdata)->flags3 & 8) != 0)) {
          uVar5 = ovr_agnt_abilityModifier
                            (*(byte *)((int)&(((entity_t *)agnt->entity)->base).entity + 3),0);
          damage = damage + (int)(char)uVar5;
          if ((int)damage < 1) {
            damage = 1;
          }
        }
        targetGdata = ((agnt_t *)agntPtr)->gdata;
        if (((((agntG_t *)targetGdata)->flags2 & 8) == 0) ||
           (bVar4 = ovr_agnt_compute9(agnt,uVar13), '\0' < (char)bVar4)) {
          targetGdata = ((agnt_t *)agntPtr)->gdata;
          if (((((agntG_t *)targetGdata)->flags3 & 0x40) == 0) ||
             (bVar4 = ovr_agnt_compute9(agnt,uVar13), '\x01' < (char)bVar4)) {
            uVar5 = (uint16_t)((ulong)agntPtr >> 0x10);
            targetGdata = ((agnt_t *)agntPtr)->gdata;
            if (((((agntG_t *)targetGdata)->flags2 & 0x10) == 0) || (agnt->gindex != 0x2)) {
              resolved = ovc41_textParalyzed((agnt_t *)CONCAT22(targetIndex,agnt),(agnt_t *)agntPtr,damage,
                                             (char)agntPtr,(char)((ulong)agntPtr >> 0x10),
                                             (char)damage);
              if ((resolved == '\0') &&
                 (((agnt->gindex == 0x0 && ((((agntG_t *)agnt->gdata)->flags2 & 2) != 0)) &&
                  (damage = ovr_ovc27_rollToHitEntity((uint32_t)agntPtr,0), (damage & 0xff) == 0)))
                 ) {
                uVar16 = (undefined1)GSavedBlitSeg;
                textPtr = ovr_agnt_statusText((agnt_t *)agntPtr,(char *)CONCAT13((char)((uint)&actorName >> 8),
                                                              CONCAT12((char)&actorName,
                                                                       (*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))),0);
                uVar15 = (undefined1)uVar10;
                uVar12 = SUB21(textPtr,0);
                textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex),0);
                stashOfs = ovr_ovc15_usesStshRealloc(textPtr,uVar10,uVar12,uVar15,uVar16,0,0,0);
                textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x70b5,_SS),
                                       (char *)CONCAT22(stashOfs,(char *)0x2410),uVar10);
                ovr_uiNotify(textPtr,uVar10,(char)uVar10);
                uVar9 = ovr_audio_panFromX(agnt,uVar13);
                ovr_play_sfxU(0x55,0,uVar9,0,(char)uVar9);
                ovc41_settleAgentCombat
                          ((agnt_t *)CONCAT13(uVar14,CONCAT12(uVar13,agnt)),(agnt_t *)agntPtr,(char)agntPtr)
                ;
                resolved = '\x01';
              }
              if (((resolved == '\0') && ((((agntG_t *)agnt->gdata)->flags2 & 4) != 0)) &&
                 (damage = ovr_ovc27_rollToHitEntity((uint32_t)agntPtr,0), (damage & 0xff) == 0)) {
                uVar5 = (uint16_t)((ulong)agntPtr >> 0x10);
                targetEnt = ((agnt_t *)agntPtr)->entity;
                if ((*(uint *)((int)&(((entity_t *)targetEnt)->base).frames + 1) & 1) == 0) {
                  uVar12 = (undefined1)GSavedBlitSeg;
                  textPtr = ovr_agnt_statusText((agnt_t *)agntPtr,(char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,uVar5)),0);
                  uVar14 = (undefined1)uVar10;
                  uVar13 = SUB21(textPtr,0);
                  textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex),0);
                  stashOfs = ovr_ovc15_usesStshRealloc(textPtr,uVar10,uVar13,uVar14,uVar12,0,0,0);
                  textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x70c4,_SS),
                                         (char *)CONCAT22(stashOfs,(char *)0x2410),uVar10);
                  ovr_uiNotify(textPtr,uVar10,(char)uVar10);
                  uVar9 = ovr_audio_panFromX((agnt_t *)agntPtr,(char)((ulong)agntPtr >> 0x10));
                  ovr_play_sfxU(5,0,uVar9,0,(char)uVar9);
                  targetEnt = ((agnt_t *)agntPtr)->entity;
                  flagsPtr = (uint *)((int)&(((entity_t *)targetEnt)->base).frames + 1);
                  *flagsPtr = *flagsPtr | 1;
                }
              }
              if (((resolved == '\0') && ((((agntG_t *)agnt->gdata)->flags2 & 0x400) != 0)) &&
                 (uVar9 = ovr_randBelow((uint)(((entity_t *)agnt->entity)->base).animFrame,0),
                 (uVar9 & 0xff) == 0)) {
                uVar5 = ovr_ovc27_usesPlay_sfxU
                                  ((uint16_t)agnt,targetIndex,agntPtr,0x1,(char)agntPtr,
                                   (char)((ulong)agntPtr >> 0x10));
                uVar13 = (undefined1)GSavedBlitSeg;
                if ((char)uVar5 == '\0') {
                  textPtr = ovr_agnt_statusText((agnt_t *)agntPtr,(char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,
                                                                         (*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))),0);
                  uVar12 = (undefined1)uVar10;
                  uVar14 = SUB21(textPtr,0);
                  textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex),0);
                  stashOfs = ovr_ovc15_usesStshRealloc(textPtr,uVar10,uVar14,uVar12,uVar13,0,0,0);
                  textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x7107,_SS),
                                         (char *)CONCAT22(stashOfs,(char *)0x2410),uVar10);
                  ovr_uiNotify(textPtr,uVar10,(char)uVar10);
                }
                else {
                  textPtr = ovr_agnt_statusText((agnt_t *)agntPtr,(char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,
                                                                         (*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))),0);
                  uVar12 = (undefined1)uVar10;
                  uVar14 = SUB21(textPtr,0);
                  textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex),0);
                  stashOfs = ovr_ovc15_usesStshRealloc(textPtr,uVar10,uVar14,uVar12,uVar13,0,0,0);
                  textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x70ec,_SS),
                                         (char *)CONCAT22(stashOfs,(char *)0x2410),uVar10);
                  ovr_uiNotify(textPtr,uVar10,(char)uVar10);
                }
              }
              if (((resolved == '\0') && ((((agntG_t *)agnt->gdata)->flags2 & 0x800) != 0)) &&
                 (uVar9 = ovr_randBelow((uint)(((entity_t *)agnt->entity)->base).animFrame,0),
                 (uVar9 & 0xff) == 0)) {
                uVar5 = ovr_ovc27_usesPlay_sfxU
                                  ((uint16_t)agnt,targetIndex,agntPtr,0x2,(char)agntPtr,
                                   (char)((ulong)agntPtr >> 0x10));
                uVar13 = (undefined1)GSavedBlitSeg;
                if ((char)uVar5 == '\0') {
                  textPtr = ovr_agnt_statusText((agnt_t *)agntPtr,(char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,
                                                                         (*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))),0);
                  uVar12 = (undefined1)uVar10;
                  uVar14 = SUB21(textPtr,0);
                  textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex),0);
                  stashOfs = ovr_ovc15_usesStshRealloc(textPtr,uVar10,uVar14,uVar12,uVar13,0,0,0);
                  textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x7107,_SS),
                                         (char *)CONCAT22(stashOfs,(char *)0x2410),uVar10);
                  ovr_uiNotify(textPtr,uVar10,(char)uVar10);
                }
                else {
                  textPtr = ovr_agnt_statusText((agnt_t *)agntPtr,(char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,
                                                                         (*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))),0);
                  uVar12 = (undefined1)uVar10;
                  uVar14 = SUB21(textPtr,0);
                  textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex),0);
                  stashOfs = ovr_ovc15_usesStshRealloc(textPtr,uVar10,uVar14,uVar12,uVar13,0,0,0);
                  textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x7125,_SS),
                                         (char *)CONCAT22(stashOfs,(char *)0x2410),uVar10);
                  ovr_uiNotify(textPtr,uVar10,(char)uVar10);
                }
              }
            }
            else {
              uVar13 = (undefined1)GSavedBlitSeg;
              textPtr = ovr_agnt_statusText((agnt_t *)agntPtr,(char *)CONCAT13((char)((uint)&targetName >> 8),
                                                            CONCAT12((char)&targetName,uVar5)),0);
              stashOfs = ovr_ovc15_usesStshRealloc(textPtr,(char)uVar10,uVar13,0,0,0,0,0);
              textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x708c,_SS),
                                     (char *)CONCAT13((char)((uint)stashOfs >> 8),
                                                      CONCAT12((char)stashOfs,0x2410)),(char)stashOfs,
                                     (char)uVar10);
              ovr_uiNotify(textPtr,uVar10,(char)uVar10);
              uVar10 = ovr_audio_panFromX((agnt_t *)agntPtr,(char)((ulong)agntPtr >> 0x10));
              ovr_play_sfxU(0x16,0,uVar10,0,(char)uVar10);
            }
          }
          else {
            uVar13 = (undefined1)GSavedBlitSeg;
            textPtr = ovr_agnt_statusText((agnt_t *)agntPtr,(char *)CONCAT13((char)((uint)&targetName >> 8),
                                                          CONCAT12((char)&targetName,(*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))
                                                         ),0);
            stashOfs = ovr_ovc15_usesStshRealloc(textPtr,(char)uVar10,uVar13,0,0,0,0,0);
            textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x705e,_SS),
                                   (char *)CONCAT13((char)((uint)stashOfs >> 8),
                                                    CONCAT12((char)stashOfs,0x2410)),(char)stashOfs,
                                   (char)uVar10);
            ovr_uiNotify(textPtr,uVar10,(char)uVar10);
            uVar10 = ovr_audio_panFromX((agnt_t *)agntPtr,(char)((ulong)agntPtr >> 0x10));
            ovr_play_sfxU(0x16,0,uVar10,0,(char)uVar10);
          }
        }
        else {
          uVar13 = (undefined1)GSavedBlitSeg;
          textPtr = ovr_agnt_statusText((agnt_t *)agntPtr,(char *)CONCAT13((char)((uint)&targetName >> 8),
                                                        CONCAT12((char)&targetName,(*(uint16_t *)((uint8_t *)&(agntPtr) + 2)))),0)
          ;
          stashOfs = ovr_ovc15_usesStshRealloc(textPtr,(char)uVar10,uVar13,0,0,0,0,0);
          textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x7031,_SS),
                                 (char *)CONCAT13((char)((uint)stashOfs >> 8),
                                                  CONCAT12((char)stashOfs,0x2410)),(char)stashOfs,
                                 (char)uVar10);
          ovr_uiNotify(textPtr,uVar10,(char)uVar10);
          uVar10 = ovr_audio_panFromX((agnt_t *)agntPtr,(char)((ulong)agntPtr >> 0x10));
          ovr_play_sfxU(0x16,0,uVar10,0,(char)uVar10);
        }
      }
      else {
        ovr_ovc27_textTakesHalfDamage3(agnt,targetIndex,uVar13,(char)in_stack_00000008);
      }
    }
    else {
      ovc41_textOnlyPlaceSingle((agnt_t *)CONCAT13(uVar14,CONCAT12(uVar13,agnt)),in_stack_00000008);
    }
  }
  return;
}


/* 6a8f:297d */

/* Applies the special attack to an agent and then runs the follow-up tick. */

void __cdecl16far ovc41_resolveSpecialAttack(agnt_t *agnt,uint16_t param)

{
  ovc41_specialAttack((agnt_t *)agnt,(*(uint16_t *)((uint8_t *)&(agnt) + 2)),param,0);
  ovr_agnt_advanceAnimFrame((agnt_t *)agnt,(*(uint16_t *)((uint8_t *)&(agnt) + 2)));
  return;
}



/* 6a8f:29a0 */

/* [R6] touches AgntCount */

void __cdecl16far ovc41_usesAgntCount3(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    if (Agnts[iVar1].faction != '\0') {
      ovc41_settleAgentCombat((agnt_t *)0x0,(agnt_t *)CONCAT22(SEG_OF(Agnts),(agnt_t *)&Agnts[iVar1].x),0);
    }
  }
  return;
}



/* 6a8f:29ea */

/* Returns the growth requirement for an agent's level, from the growth table or its type record. */

int __cdecl16far ovc41_growthForLevel(agnt_t *agnt,uint16_t arg2)

{
  int iVar1;
  uint16_t in_stack_00000006;
  far_t dst;
  uint8_t growthMap;
  byte bStack_4;
  byte bStack_3;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)&growthMap;
  F_SCOPY(far_from_u32((uint32_t)(0x24106e48)),dst);
  bStack_3 = agnt->gindex;
  if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bStack_3 * 0x95) == -1) {
    iVar1 = *(int *)((int)&worldMenuLabels[9].seg + 1 + (uint)bStack_3 * 0x95);
  }
  else {
    bStack_4 = agnt->level;
    if (bStack_4 < 0x16) {
      iVar1 = *(int *)(&growthMap + (uint)bStack_4 * 2);
    }
    else {
      iVar1 = (uint)bStack_4 * 0xfa + -0xabe;
    }
  }
  return iVar1;
}


