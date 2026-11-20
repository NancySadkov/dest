/*
 * ovc41.c - recovered from STRONG.EXE
 * memory block: OVC41
 * range: 6a8f:0000 - 6a8f:2eaf
 * functions: 37
 */
#include "recovered.h"


/* 6a8f:0000 */

/* Returns "" for a count of 1 and "s" otherwise (plural suffix for formatted strings). */

undefined2 __cdecl16far ovc41_pluralSuffix(int count)

{
  undefined2 uVar1;
  
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

undefined2 __cdecl16far ovc41_compute2(int count)

{
  undefined2 uVar1;
  
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

void __cdecl16far ovc41_compute3(uint32_t view)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  undefined2 uVar7;
  byte bStack_7;
  
  uVar7 = (undefined2)(view >> 0x10);
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

void __cdecl16far ovc41_compute4(agnt_t *agnt,byte flag,byte pad,agnt_t *other)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  byte bVar4;
  long *plVar5;
  uint uVar6;
  int iVar7;
  long in_stack_00000000;
  undefined1 in_stack_0000000b;
  undefined1 in_stack_0000fffc;
  
  if (flag != 0) {
    bVar4 = *(byte *)(CONCAT11(in_stack_0000000b,pad) + 0xd);
    plVar5 = (long *)CONCAT11(bVar4,in_stack_0000fffc);
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar4 * 0x95) != -1) {
      ovc41_growthForLevel(agnt);
      iVar7 = 0;
      plVar5 = LXMUL_at_(plVar5,in_stack_00000000,(long)agnt);
      uVar6 = ovr_ovc15_textError(CONCAT11(in_stack_0000000b,pad),(agnt_t *)other,plVar5);
      puVar1 = (uint *)(CONCAT11(in_stack_0000000b,pad) + 0x10);
      uVar3 = *puVar1;
      *puVar1 = *puVar1 + uVar6;
      piVar2 = (int *)(CONCAT11(in_stack_0000000b,pad) + 0x12);
      *piVar2 = *piVar2 + iVar7 + (uint)CARRY2(uVar3,uVar6);
      ovc41_compute3(CONCAT22((agnt_t *)other,CONCAT11(in_stack_0000000b,pad)));
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
  undefined2 uVar3;
  
  if (DebugVerbose) {
    printf("kill 4\r");
  }
  uVar3 = (undefined2)((ulong)agnt >> 0x10);
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

void __cdecl16far OVC41_6a8f_01e7_entry(agnt_t *agnt)

{
  if ((((agnt_t *)agnt)->flags & 0xae4) == 0) {
    ovc41_markAgentDead(agnt);
  }
  return;
}



/* 6a8f:0246 */

/* Increments the animFrame byte of the entity the agent belongs to. */

void __cdecl16far ovc41_advanceAnimFrame(agnt_t *agnt)

{
  uint8_t *puVar1;
  entity_t *peVar2;
  
  peVar2 = ((agnt_t *)agnt)->entity;
  puVar1 = &(((entity_t *)peVar2)->base).animFrame;
  *puVar1 = *puVar1 + 0x1;
  return;
}



/* 6a8f:0256 */

/* Removes an agent record from Agnts, fixes the +0xc references and memmoves the tail down. */

void __cdecl16far ovc41_removeAgent(uint agntIndex,int notify)

{
  char *pcVar1;
  undefined2 uVar2;
  agnt_t *paVar3;
  int iVar4;
  bool bVar5;
  uint uVar6;
  undefined4 uStack_8;
  
  uVar2 = *(undefined2 *)(agntIndex * 0x34 + 0x19);
  paVar3 = (agnt_t *)*(int *)(agntIndex * 0x34 + 0x17);
  uStack_8 = (agnt_t *)CONCAT22(uVar2,paVar3);
  iVar4 = *(int *)(agntIndex * 0x34 + 0x1b);
  ovr_agnt_usesAgntCount4(agntIndex + 1);
  bVar5 = false;
  for (uVar6 = 0; (int)uVar6 < (int)(uint)AgntCount; uVar6 = uVar6 + 1) {
    if ((uVar6 != agntIndex) && (*(int *)(uVar6 * 0x34 + 0x1b) == iVar4)) {
      bVar5 = true;
    }
    if (*(char *)(uVar6 * 0x34 + 0xc) != -1) {
      if ((int)agntIndex < (int)(uint)*(byte *)(uVar6 * 0x34 + 0xc)) {
        pcVar1 = (char *)(uVar6 * 0x34 + 0xc);
        *pcVar1 = *pcVar1 + -1;
      }
      else if (*(byte *)(uVar6 * 0x34 + 0xc) == agntIndex) {
        *(undefined1 *)(uVar6 * 0x34 + 0xc) = 0xff;
      }
    }
  }
  if ((int)(agntIndex + 1) < (int)(uint)AgntCount) {
    _fmemmove((char *)CONCAT22(0x1726,(char *)(agntIndex * 0x34)),
              (char *)CONCAT22(0x1726,(char *)(agntIndex * 0x34 + 0x34)),
              ((AgntCount - agntIndex) + -1) * 0x34);
  }
  AgntCount = AgntCount - 1;
  if ((((notify != 0) && (!bVar5)) && (paVar3->y == GfxRndSeed2)) &&
     ((GfxRndSeed - 2U <= uStack_8->x && (GfxRndSeed - 2U <= uStack_8->x)))) {
    paVar3->destX = paVar3->targetX;
    paVar3->destY = paVar3->targetY;
    ovr_attact_usesRandBelow((agnt_t *)CONCAT22(uVar2,paVar3),paVar3->target);
  }
  return;
}



/* 6a8f:0422 */

/* [R6] touches MenuItemEnabled */

undefined2 __cdecl16far ovc41_usesMenuItemEnabled(byte menuIndex,int gfxVariant)

{
  byte bVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  
  if (((uint8_t *)MenuItemEnabled)[menuIndex] == 0xff) {
    uVar3 = 0x6e74;
  }
  else {
    uVar2 = *(undefined4 *)((uint)((uint8_t *)MenuItemEnabled)[menuIndex] << 2);
    bVar1 = *(byte *)((int)uVar2 + 0x2f);
    if (gfxVariant == 1) {
      uVar3 = *(undefined2 *)((uint)bVar1 * 4 + 0x123);
    }
    else {
      uVar3 = *(undefined2 *)((uint)bVar1 * 4 + 0x107);
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
  undefined4 uVar1;
  char *txt;
  uint16_t dst;
  uint uVar2;
  int count;
  char *unaff_SS;
  far_t pctOut;
  far_t remainderOut;
  far_t partOut;
  uint8_t msg;
  uint8_t part;
  uint8_t remainder;
  uint8_t pct;
  
  if (((uint8_t *)MenuItemEnabled)[menuIndex] != 0xff) {
    count = 0;
    for (uVar2 = 0; uVar2 < AgntCount; uVar2 = uVar2 + 1) {
      uVar1 = *(undefined4 *)(uVar2 * 0x34 + 0x17);
      if (((uint8_t *)MenuItemEnabled)[menuIndex] == *(uint8_t *)((int)uVar1 + 0x1a)) {
        count = count + 1;
      }
    }
    partOut.seg = (uint16_t)unaff_SS;
    partOut.ofs = (uint16_t)&part;
    remainderOut.seg = (uint16_t)unaff_SS;
    remainderOut.ofs = (uint16_t)&remainder;
    pctOut.seg = (uint16_t)unaff_SS;
    pctOut.ofs = (uint16_t)&pct;
    ovr_attact_compute2(CONCAT11((char)((uint)&pct >> 8),menuIndex),pctOut,remainderOut,partOut);
    ovc41_isAre(count);
    dst = 0x217a;
    ovc41_pluralSuffix(count);
    txt = ovr_stsprintf((char *)&msg,unaff_SS,
                        (char *)
                        "The %d unit%s loyal to %s %s %d%% recruiting, %d%% training, and %d%% building."
                       );
    ovr_drawTextAt(txt,dst);
  }
  return;
}



/* 6a8f:05ad */

/* [R6] touches DebugVerbose */

void __cdecl16far ovc41_usesDebugVerbose(void)

{
  int iVar1;
  int iVar2;
  
  if (DebugVerbose) {
    for (iVar2 = 0; iVar2 < 10; iVar2 = iVar2 + 1) {
      for (iVar1 = 0; iVar1 < 0x69; iVar1 = iVar1 + 1) {
        *(char *)(iVar2 * 0x140 + iVar1 + -0x1280) = *(char *)(iVar2 * 0x69 + iVar1 + 0x8fa) + '@';
      }
    }
    for (iVar2 = 0; iVar2 < 10; iVar2 = iVar2 + 1) {
      for (iVar1 = 0; iVar1 < 0x69; iVar1 = iVar1 + 1) {
        *(char *)(iVar2 * 0x140 + iVar1 + -0x120d) = *(char *)(iVar2 * 0x69 + iVar1 + 0x4e0) + '@';
      }
    }
  }
  return;
}



/* 6a8f:063f */

/* Applies the combat outcome to an agent: sets the dead state or restores its strength and timer.
    */

uint __cdecl16far ovc41_settleAgentCombat(agnt_t *a,agnt_t *b)

{
  uint in_AX;
  uint uVar1;
  byte bVar2;
  agnt_t *paVar3;
  undefined2 unaff_BP;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)b >> 0x10);
  paVar3 = (agnt_t *)b;
  if (paVar3->combatState == 0x2) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    if ((a != (agnt_t *)0x0) && (((agnt_t *)a)->gdata->ai == ((agnt_t *)a)->faction)) {
      ovc41_compute4((agnt_t *)
                     CONCAT22(*(undefined2 *)((int)&paVar3->entity + 2),*(agnt_t **)&paVar3->entity)
                     ,1,(byte)*(undefined2 *)&((agnt_t *)a)->entity,
                     (agnt_t *)
                     CONCAT22(unaff_BP,(agnt_t *)*(undefined2 *)((int)&((agnt_t *)a)->entity + 2)));
    }
    if (((((((entity_t *)paVar3->entity)->base).animFrame == 0x0) ||
         ((uint)(((entity_t *)paVar3->entity)->base).animFrame % 0x10 == 1)) ||
        ((paVar3->flags & 0xae4) != 0)) || ((((agntG_t *)paVar3->gdata)->flags2 & 4) != 0)) {
      paVar3->strength = 0x0;
      paVar3->timer = 0xa;
      paVar3->combatState = 0x2;
      paVar3->targetY = 0;
    }
    else {
      paVar3->strength = ((agntG_t *)paVar3->gdata)->strength;
      paVar3->timer = 0x6;
      paVar3->combatState = 0x1;
      paVar3->targetY = 0;
    }
    ovr_agnt_usesAnimFrame(b);
    bVar2 = (byte)(paVar3->owner * 0x37 >> 8);
    ovr_ovc25_attackingNotice
              (*(byte *)((int)&((entity_t *)Entities)[paVar3->owner].base.entity + 3));
    if ((paVar3->flags & 0xae4) == 0) {
      ovc41_markAgentDead(b);
      uVar1 = CONCAT11(bVar2,1);
    }
    else {
      uVar1 = (uint)bVar2 << 8;
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
      if ((*(uint *)(iVar2 * 0x34 + 0x2b) & 0x800) == 0) {
        OVC41_6a8f_01e7_entry((agnt_t *)CONCAT22(0x1726,(agnt_t *)(iVar2 * 0x34)));
        puVar1 = (uint *)(iVar2 * 0x34 + 0x2b);
        *puVar1 = *puVar1 | 0x800;
        unk = ovr_audio_panFromX((agnt_t *)CONCAT22(0x1726,(agnt_t *)(iVar2 * 0x34)));
        ovr_play_sfxU(0x1b,0,unk);
        ovr_attact_usesEntityCount();
        return;
      }
    }
  }
  return;
}



/* 6a8f:0807 */

/* Rolls a paralysis check against every agent within 50 pixels when the source type allows it. */

void __cdecl16far ovc41_paralyzeNearbyAgents(int agntIndex)

{
  byte bVar1;
  agnt_t *paVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uStack_6;
  
  paVar2 = (agnt_t *)(agntIndex * 0x34);
  uStack_6 = (agnt_t *)CONCAT22(0x1726,paVar2);
  if ((((agntG_t *)paVar2->gdata)->flags2 & 4) != 0) {
    for (iVar6 = 0; iVar6 < (int)(uint)AgntCount; iVar6 = iVar6 + 1) {
      if ((iVar6 != agntIndex) &&
         (uVar3 = uStack_6->x - *(int *)(iVar6 * 0x34), uVar5 = (int)uVar3 >> 0xf,
         (int)((uVar3 ^ uVar5) - uVar5) < 0x32)) {
        bVar1 = ovr_manage_rollDice('\x06','\x06');
        uVar3 = (uint)bVar1;
        iVar4 = ovr_ovc27_rollToHitEntity(CONCAT22(0x1726,iVar6 * 0x34),1);
        if ((char)iVar4 != '\0') {
          uVar3 = (int)uVar3 >> 1;
        }
        ovc41_textParalyzed((agnt_t *)CONCAT22(0x1726,paVar2),
                            (agnt_t *)CONCAT22(0x1726,(agnt_t *)(iVar6 * 0x34)),uVar3);
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
  uint16_t unaff_SS;
  far_t dst;
  int iStack_c;
  uint8_t xOfs;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&xOfs;
  F_SCOPY(far_from_u32((uint32_t)(0x24106e00)),dst);
  uVar1 = (uint)*(byte *)(agntIndex * 0x34 + 0xc);
  iStack_c = *(int *)(agntIndex * 0x34 + 6);
  if (2 < iStack_c) {
    iStack_c = 3;
  }
  if (*(char *)(agntIndex * 0x34 + 0xf) == '\0') {
    *(int *)(uVar1 * 0x34) = *(int *)(agntIndex * 0x34) + *(int *)(&xOfs + iStack_c * 2);
  }
  else {
    *(int *)(uVar1 * 0x34) = *(int *)(agntIndex * 0x34) - *(int *)(&xOfs + iStack_c * 2);
  }
  if (0xd2 < *(int *)(uVar1 * 0x34)) {
    *(undefined2 *)(uVar1 * 0x34) = 0xd2;
  }
  if (*(int *)(uVar1 * 0x34) < 0) {
    *(undefined2 *)(uVar1 * 0x34) = 0;
  }
  *(undefined2 *)(uVar1 * 0x34 + 2) = *(undefined2 *)(agntIndex * 0x34 + 2);
  *(undefined1 *)(uVar1 * 0x34 + 5) = 0;
  *(undefined1 *)(uVar1 * 0x34 + 4) = 0;
  return;
}



/* 6a8f:0a45 */

/* [R7] body shape: compute */

undefined2 __cdecl16far ovc41_compute6(byte rank,uint8_t level)

{
  byte bVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  
  bVar1 = ovr_agnt_compute14(level);
  if (bVar1 + 2 < (uint)rank) {
    uVar2 = CONCAT11((char)(bVar1 + 2 >> 8),0xd);
  }
  else if (bVar1 + 2 == (uint)rank) {
    uVar2 = CONCAT11((char)(bVar1 + 2 >> 8),0xb);
  }
  else {
    uVar3 = (undefined1)(bVar1 + 1 >> 8);
    if (bVar1 + 1 == (uint)rank) {
      uVar2 = CONCAT11(uVar3,9);
    }
    else if (bVar1 == rank) {
      uVar2 = CONCAT11(uVar3,7);
    }
    else {
      uVar2 = CONCAT11(uVar3,2);
    }
  }
  return uVar2;
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
  uint *puVar1;
  byte rank;
  undefined4 uVar2;
  byte bVar3;
  undefined2 in_AX;
  undefined1 extraout_AH;
  undefined2 uVar4;
  char *pcVar5;
  undefined1 uVar7;
  int iVar6;
  uint16_t unk;
  agnt_t *paVar8;
  uint uVar9;
  undefined2 uVar10;
  char *unaff_SS;
  uint8_t text;
  uint8_t msg;
  int iStack_a;
  undefined2 uStack_8;
  byte bStack_6;
  char cStack_5;
  char cStack_4;
  char cStack_3;
  
  uVar10 = (undefined2)((ulong)agnt >> 0x10);
  paVar8 = (agnt_t *)agnt;
  bVar3 = (byte)((uint)in_AX >> 8);
  if ((paVar8->flags & 2) == 0) {
    iVar6 = (uint)bVar3 << 8;
  }
  else {
    paVar8->health = 0x0;
    paVar8->flags = paVar8->flags & 0xfffd;
    if (paVar8->target == 0xff) {
      iVar6 = (uint)bVar3 << 8;
    }
    else {
      iStack_a = (uint)paVar8->target * 0x34;
      uStack_8 = 0x1726;
      bStack_6 = *(byte *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x42);
      if (bStack_6 == 0) {
        iVar6 = 0;
      }
      else {
        bVar3 = ovr_manage_rollDice('\x02','\x06');
        uVar7 = extraout_AH;
        uVar4 = ovc41_compute6(*(byte *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x42),
                               (((entity_t *)paVar8->entity)->base).level);
        if (bVar3 < (byte)uVar4) {
          pcVar5 = ovr_agnt_statusText(agnt,(char *)&text);
          ovr_ovc15_usesStshRealloc((char *)CONCAT13(uVar7,CONCAT12(bVar3,pcVar5)));
          pcVar5 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s fails to turn.");
          ovr_uiNotify(pcVar5,CONCAT11(uVar7,bVar3));
          uVar7 = (undefined1)((uint)pcVar5 >> 8);
          ovr_agnt_usesAnimFrame(agnt);
          iVar6 = CONCAT11(uVar7,1);
        }
        else {
          rank = *(byte *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x42);
          uVar9 = (uint)rank;
          ovc41_rollStatDice(rank,(((entity_t *)paVar8->entity)->base).level);
          uVar9 = uVar9 & 0xff;
          iVar6 = ovc41_compute8(*(byte *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x42),
                                 (((entity_t *)paVar8->entity)->base).level);
          cStack_4 = (char)iVar6;
          cStack_5 = '\0';
          iVar6 = 0;
          while ((iVar6 < (int)(uint)AgntCount && (uVar9 != 0))) {
            uVar2 = *(undefined4 *)(iVar6 * 0x34 + 0x1d);
            if (((*(char *)((int)uVar2 + 0x42) != '\0') &&
                ((((*(uint8_t *)(iVar6 * 0x34 + 0x2f) != paVar8->faction &&
                   ((*(uint *)(iVar6 * 0x34 + 0x2b) & 4) == 0)) &&
                  (*(char *)(iVar6 * 0x34 + 0x24) == '\0')) &&
                 ((cStack_5 == '\0' ||
                  (uVar2 = *(undefined4 *)(iVar6 * 0x34 + 0x17),
                  (int)(uint)*(byte *)((int)uVar2 + 0xf) <= (int)uVar9)))))) &&
               (uVar2 = *(undefined4 *)(iVar6 * 0x34 + 0x1d),
               *(byte *)((int)uVar2 + 0x42) <= bStack_6)) {
              if ((*(uint *)(iVar6 * 0x34 + 0x2b) & 0xae4) == 0) {
                uVar2 = *(undefined4 *)(iVar6 * 0x34 + 0x17);
                cStack_3 = *(char *)((int)uVar2 + 0xe);
              }
              else {
                cStack_3 = '\x01';
              }
              while ((cStack_3 != '\0' && (uVar9 != 0))) {
                if (cStack_4 == '\0') {
                  OVC41_6a8f_01e7_entry((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,iVar6 * 0x34)));
                  *(undefined1 *)(iVar6 * 0x34 + 4) = 0;
                  *(undefined1 *)(iVar6 * 0x34 + 5) = 0;
                  puVar1 = (uint *)(iVar6 * 0x34 + 0x2b);
                  *puVar1 = *puVar1 | 4;
                  *(undefined1 *)(iVar6 * 0x34 + 0x24) = 1;
                  *(undefined2 *)(iVar6 * 0x34 + 6) = 0;
                  *(undefined1 *)(iVar6 * 0x34 + 0x23) = 5;
                  ovr_agnt_usesAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,iVar6 * 0x34)));
                }
                else {
                  ovc41_settleAgentCombat(agnt,(agnt_t *)CONCAT13(0x17,CONCAT12(0x26,iVar6 * 0x34)))
                  ;
                }
                cStack_5 = cStack_5 + '\x01';
                uVar2 = *(undefined4 *)(iVar6 * 0x34 + 0x17);
                if ((int)uVar9 < (int)(uint)*(byte *)((int)uVar2 + 0xf)) {
                  uVar9 = 0;
                }
                else {
                  uVar2 = *(undefined4 *)(iVar6 * 0x34 + 0x17);
                  uVar9 = uVar9 - *(byte *)((int)uVar2 + 0xf);
                }
                cStack_3 = cStack_3 + -1;
              }
            }
            bVar3 = 0x26;
            uVar7 = 0x17;
            iVar6 = iVar6 + 1;
          }
          if (cStack_5 == '\0') {
            pcVar5 = ovr_agnt_statusText(agnt,(char *)&text);
            ovr_ovc15_usesStshRealloc((char *)CONCAT13(uVar7,CONCAT12(bVar3,pcVar5)));
            pcVar5 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s cannot turn.");
            ovr_uiNotify(pcVar5,CONCAT11(uVar7,bVar3));
            uVar7 = (undefined1)((uint)pcVar5 >> 8);
          }
          else {
            if (cStack_4 == '\0') {
              pcVar5 = ovr_agnt_statusText(agnt,(char *)&text);
              ovr_ovc15_usesStshRealloc((char *)CONCAT13(uVar7,CONCAT12(bVar3,pcVar5)));
              pcVar5 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s turns %d undead.");
              ovr_uiNotify(pcVar5,CONCAT11(uVar7,bVar3));
            }
            else {
              pcVar5 = ovr_agnt_statusText(agnt,(char *)&text);
              ovr_ovc15_usesStshRealloc((char *)CONCAT13(uVar7,CONCAT12(bVar3,pcVar5)));
              pcVar5 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s destroys %d undead.");
              ovr_uiNotify(pcVar5,CONCAT11(uVar7,bVar3));
            }
            unk = ovr_audio_panFromX(agnt);
            ovr_play_sfxU(0x3b,0,unk);
            uVar7 = (undefined1)(unk >> 8);
          }
          ovr_agnt_usesAnimFrame(agnt);
          iVar6 = CONCAT11(uVar7,1);
        }
      }
    }
  }
  return iVar6;
}



/* 6a8f:0fc1 */

/* Formats the "Building %d %s." notice. */

void __cdecl16far ovc41_buildingNotice(char delta)

{
  int iVar1;
  char *msg;
  undefined2 uVar2;
  char *unaff_SS;
  uint8_t text;
  byte bStack_3;
  
  iVar1 = ((short (*) [148] [60])GUnitGrid)[-1][GfxRndSeed + 0x93][GfxRndSeed2];
  if (0xf7 < iVar1) {
    uVar2 = (undefined2)((ulong)GUnits >> 0x10);
    bStack_3 = ((unit_t *)GUnits + iVar1)->bldType + delta;
    if (0xf7 < bStack_3) {
      bStack_3 = 0;
    }
    ((unit_t *)GUnits + iVar1)->bldType = bStack_3;
    ovr_constr_flushDirtyRects();
    msg = ovr_stsprintf((char *)&text,unaff_SS,(char *)"Building %d %s.");
    ovr_say(msg);
  }
  return;
}



/* 6a8f:108a */

void __cdecl16far dbgPromoteEnemy(void)

{
  uint8_t *puVar1;
  char *msg;
  entity_t *peVar2;
  uint16_t i;
  undefined2 uVar3;
  char *unaff_SS;
  char buf [80];
  
  for (i = 0; i < EntityCount; i = i + 1) {
    uVar3 = (undefined2)((ulong)Entities >> 0x10);
    peVar2 = (entity_t *)Entities;
    if (((GfxRndSeed - 2U <= ((peVar2 + i)->base).x) && (((peVar2 + i)->base).x <= GfxRndSeed + 1U))
       && (peVar2[i].base.y == GfxRndSeed2)) {
      puVar1 = &peVar2[i].base.gindex;
      *puVar1 = *puVar1 + 0x1;
      uVar3 = (undefined2)((ulong)Entities >> 0x10);
      if (0x29 < ((entity_t *)Entities)[i].base.gindex) {
        ((entity_t *)Entities)[i].base.gindex = 0x0;
      }
      msg = ovr_stsprintf(buf,unaff_SS,(char *)"Enemy %s.");
      ovr_say(msg);
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
  char *pcVar1;
  int menuIndex;
  
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  if (((playSound != '\0') && (CFG_Sfx != '1')) && (CFG_Sfx != '4')) {
    ovr_play_sfx(6,0);
  }
  ovr_unit_usesAlignUp4();
  GOngoingBattle = GBattleMode;
  if (GBattleMode == '\0') {
    pcVar1 = ovr_draw_textArena();
    if (((uint)pcVar1 & 0xff) == 0) {
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

/* WARNING: Instruction at (ram,0x00068912) overlaps instruction at (ram,0x0006890f)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x00068915) */
/* WARNING: Variable defined which should be unmapped: backdropIndex */
/* [R4] calls ovr_biosKeyAvail */

char * __cdecl16far ovc41_usesBiosKeyAvail(char backdropIndex)

{
  undefined4 uVar1;
  bool bVar2;
  far_t gfx;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  far_t handle_04;
  far_t handle_05;
  far_t handle_06;
  far_t entries;
  char cVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  undefined1 extraout_AH;
  undefined1 uVar10;
  byte *pbVar9;
  uint uVar11;
  uint16_t uVar12;
  uint16_t uVar13;
  uint16_t in_DX;
  int iVar14;
  char *unaff_BP;
  undefined2 *unaff_SI;
  int iVar15;
  int unaff_DI;
  undefined2 uVar16;
  int16_t iVar17;
  uint16_t *unaff_SS;
  far_t text1;
  far_t text1_00;
  far_t text1_01;
  far_t text1_02;
  undefined1 in_stack_00000005;
  far_t hint;
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
  int16_t iStack_12;
  undefined2 uStack_10;
  byte bVar18;
  byte bVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  byte bVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  undefined1 uVar25;
  
  bVar22 = 0x6a;
  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)FontHandle.seg;
  gfx.ofs = FontHandle.ofs;
  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)(FontHandle.seg >> 8);
  uVar12 = FontHandle.seg;
  uVar11 = FontHandle.ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)));
  if (in_stack_00000006 != '\0') {
    pcVar4 = (char *)(uint)(byte)backdropIndex;
    pbVar9 = (byte *)(uint)(byte)backdropIndex;
    if (pbVar9 < (byte *)__C0_ASM_CopyRight) {
      switch(pbVar9) {
      case (byte *)0x0:
        return (char *)((int)(undefined4 *)&_DATA + 1);
      case (byte *)0x1:
        ovr_ovc15_usesStExit(*(int *)((int)pbVar9 * 2 + 0x1b));
        return (char *)pbVar9;
      case (byte *)0x2:
        return (char *)CONCAT11(in_stack_00000005,backdropIndex);
      }
      if ((backdropIndex & 2U) == 0) {
        ovr_constr_usesBlitRect();
      }
      return pcVar4;
    }
  }
  pcVar4 = (char *)(uint)(byte)backdropIndex;
  if ((char *)((int)(undefined4 *)&_DATA + 3U) < pcVar4) {
    if (TextBlitFlag != '\0') {
      ovr_say((char *)0x6e74);
    }
    TextBlitFlag = 0;
    AgntFlag1 = false;
    GGameState = 0x33;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    ovc41_usesAgnt_clear('\x01');
    GGameState = 0x35;
    pcVar4 = (char *)"puppetmaker" + 3;
    if (DebugVerbose != false) {
      pcVar4 = (char *)"puppetmaker" + 3;
      printf("%d \r");
    }
    return pcVar4;
  }
  iVar17 = 24576;
  switch(pcVar4) {
  case (char *)0x1:
    cVar3 = *(char *)((int)pcVar4 * 2 + 0x3f);
    do {
      if (((cVar3 == '\0') && (0xf7 < (int)unaff_SI)) &&
         (in_DX = 0x2410, ((unit_t *)GUnits)[(int)unaff_SI].level < 8)) {
        uVar12 = 0x195d;
        if ((*(uint *)((uVar11 >> 8) * 0x27 + 0x121) & 0x80) == 0) {
          ovc39_loadArchiveEntry(8);
        }
        else {
          ovc39_loadArchiveEntry(9);
        }
        pcVar4 = ovc39_lordOrLady();
        iStack_12 = -27761;
        uStack_10 = iVar17;
        pcVar6 = ovr_stsprintf(acStack_2cc,(char *)unaff_SS,pcVar4);
        uVar10 = (undefined1)uVar12;
        uVar20 = (undefined1)(uVar12 >> 8);
        pcVar4 = pcVar6;
        ovr_drawString(pcVar6,uVar12);
        (*(uint8_t *)((uint8_t *)&(handle.seg))) = uVar10;
        handle.ofs = (uint16_t)pcVar4;
        (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar20;
        ovr_stshFree(handle);
        return pcVar6;
      }
      do {
        bVar19 = (byte)(uVar11 >> 8);
        if (((bVar22 == 1) && ((int)unaff_SI < 0xf8)) &&
           (in_DX = 0x195d, (*(uint *)((uint)bVar19 * 0x27 + 0x121) & 2) != 0)) {
          ovc39_loadArchiveEntry(10);
          pcVar4 = ovc39_lordOrLady();
          iStack_12 = -27655;
          uStack_10 = iVar17;
          pcVar6 = ovr_stsprintf(acStack_2cc,(char *)unaff_SS,pcVar4);
          uVar10 = (undefined1)in_DX;
          uVar20 = (undefined1)(in_DX >> 8);
          pcVar4 = pcVar6;
          ovr_drawString(pcVar6,in_DX);
          (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = uVar10;
          handle_00.ofs = (uint16_t)pcVar4;
          (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar20;
          ovr_stshFree(handle_00);
          return pcVar6;
        }
        if (((bVar22 == 2) && ((int)unaff_SI < 0xf8)) &&
           (in_DX = 0x195d, (*(uint *)((uint)bVar19 * 0x27 + 0x121) & 0x20) != 0)) {
          ovc39_loadArchiveEntry(0xb);
          pcVar4 = ovc39_lordOrLady();
          iStack_12 = -27549;
          uStack_10 = iVar17;
          pcVar6 = ovr_stsprintf(acStack_2cc,(char *)unaff_SS,pcVar4);
          uVar10 = (undefined1)in_DX;
          uVar20 = (undefined1)(in_DX >> 8);
          pcVar4 = pcVar6;
          ovr_drawString(pcVar6,in_DX);
          (*(uint8_t *)((uint8_t *)&(handle_01.seg))) = uVar10;
          handle_01.ofs = (uint16_t)pcVar4;
          (*(uint8_t *)((uint8_t *)&(handle_01.seg) + 1)) = uVar20;
          ovr_stshFree(handle_01);
          return pcVar6;
        }
        if (bVar22 == 3) {
          uVar10 = (undefined1)iVar17;
          uVar20 = (undefined1)((uint)iVar17 >> 8);
          iVar17 = 9201;
          bVar19 = 0x94;
          uVar11 = ovr_ovc45_compute4(uVar12 + unaff_DI,GfxRndSeed2);
          uVar12 = CONCAT11(uVar20,uVar10);
          if ((char)uVar11 != '\0') {
            ovc39_loadArchiveEntry(0xc);
            pcVar4 = ovc39_lordOrLady();
            uStack_10 = 9201;
            iStack_12 = -27447;
            pcVar6 = ovr_stsprintf(acStack_2cc,(char *)unaff_SS,pcVar4);
            uVar10 = (undefined1)in_DX;
            uVar20 = (undefined1)(in_DX >> 8);
            pcVar4 = pcVar6;
            ovr_drawString(pcVar6,in_DX);
            (*(uint8_t *)((uint8_t *)&(handle_02.seg))) = uVar10;
            handle_02.ofs = (uint16_t)pcVar4;
            (*(uint8_t *)((uint8_t *)&(handle_02.seg) + 1)) = uVar20;
            ovr_stshFree(handle_02);
            return pcVar6;
          }
        }
        if (((bVar22 == 4) && ((int)unaff_SI < 0xf8)) &&
           (uVar13 = 0x195d, (*(uint *)((uint)bVar19 * 0x27 + 0x121) & 0x400) != 0)) {
          ovc39_loadArchiveEntry(0xd);
          pcVar4 = ovc39_lordOrLady();
          iStack_12 = -27341;
          uStack_10 = iVar17;
          pcVar6 = ovr_stsprintf(acStack_2cc,(char *)unaff_SS,pcVar4);
          uVar10 = (undefined1)uVar13;
          uVar20 = (undefined1)(uVar13 >> 8);
          pcVar4 = pcVar6;
          ovr_drawString(pcVar6,uVar13);
          (*(uint8_t *)((uint8_t *)&(handle_03.seg))) = uVar10;
          handle_03.ofs = (uint16_t)pcVar4;
          (*(uint8_t *)((uint8_t *)&(handle_03.seg) + 1)) = uVar20;
          ovr_stshFree(handle_03);
          return pcVar6;
        }
        do {
          unaff_DI = unaff_DI + 1;
          while( true ) {
            uVar10 = (undefined1)iVar17;
            uVar20 = (undefined1)((uint)iVar17 >> 8);
            if (unaff_DI < 2) break;
            bVar22 = bVar22 + 1;
            if (3 < bVar22) {
              uVar16 = (undefined2)((ulong)*(undefined4 *)((uint)(byte)backdropIndex << 2) >> 0x10);
              iVar14 = (int)*(undefined4 *)((uint)(byte)backdropIndex << 2);
              if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4f) <
                  (uint)(*(int *)(iVar14 + 0x4d) * 2 + *(int *)(iVar14 + 0x4d)) >> 1) {
                if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4f) <
                    *(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4d)) {
                  uVar16 = (undefined2)
                           ((ulong)*(undefined4 *)((uint)(byte)backdropIndex << 2) >> 0x10);
                  iVar14 = (int)*(undefined4 *)((uint)(byte)backdropIndex << 2);
                  if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4f) <
                      (uint)(*(int *)(iVar14 + 0x4d) * 2 + *(int *)(iVar14 + 0x4d)) >> 2) {
                    if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4f) <
                        *(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4d) >> 1)
                    {
                      if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4f) <
                          *(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4d) >>
                          2) {
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
              uVar16 = (undefined2)((ulong)*(undefined4 *)((uint)(byte)backdropIndex << 2) >> 0x10);
              iVar15 = (int)*(undefined4 *)((uint)(byte)backdropIndex << 2);
              iVar14 = *(int *)(iVar15 + 0x62);
              if ((iVar14 < 0) ||
                 ((iVar14 == 0 &&
                  (*(uint *)(iVar15 + 0x60) <
                   (uint)(*(int *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4d) *
                         0x28))))) {
                uVar16 = (undefined2)
                         ((ulong)*(undefined4 *)((uint)(byte)backdropIndex << 2) >> 0x10);
                iVar15 = (int)*(undefined4 *)((uint)(byte)backdropIndex << 2);
                iVar14 = *(int *)(iVar15 + 0x62);
                if ((iVar14 < 0) ||
                   ((iVar14 == 0 &&
                    (*(uint *)(iVar15 + 0x60) <
                     (uint)(*(int *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4d) *
                           0x14))))) {
                  uVar16 = (undefined2)
                           ((ulong)*(undefined4 *)((uint)(byte)backdropIndex << 2) >> 0x10);
                  iVar15 = (int)*(undefined4 *)((uint)(byte)backdropIndex << 2);
                  iVar14 = *(int *)(iVar15 + 0x62);
                  if ((iVar14 < 0) ||
                     ((iVar14 == 0 &&
                      (*(uint *)(iVar15 + 0x60) <
                       (uint)(*(int *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4d)
                             * 0x3c) >> 2)))) {
                    uVar16 = (undefined2)
                             ((ulong)*(undefined4 *)((uint)(byte)backdropIndex << 2) >> 0x10);
                    iVar15 = (int)*(undefined4 *)((uint)(byte)backdropIndex << 2);
                    iVar14 = *(int *)(iVar15 + 0x62);
                    if ((iVar14 < 0) ||
                       ((iVar14 == 0 &&
                        (*(uint *)(iVar15 + 0x60) <
                         (uint)(*(int *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4d
                                        ) * 0x14) >> 1)))) {
                      uVar16 = (undefined2)
                               ((ulong)*(undefined4 *)((uint)(byte)backdropIndex << 2) >> 0x10);
                      iVar15 = (int)*(undefined4 *)((uint)(byte)backdropIndex << 2);
                      iVar14 = *(int *)(iVar15 + 0x62);
                      if ((iVar14 < 0) ||
                         ((iVar14 == 0 &&
                          (*(uint *)(iVar15 + 0x60) <
                           (uint)(*(int *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) +
                                          0x4d) * 0x14) >> 2)))) {
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
              uVar16 = (undefined2)((ulong)*(undefined4 *)((uint)(byte)backdropIndex << 2) >> 0x10);
              iVar14 = (int)*(undefined4 *)((uint)(byte)backdropIndex << 2);
              if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x5b) <
                  (uint)(*(int *)(iVar14 + 0x4d) * 2 + *(int *)(iVar14 + 0x4d)) >> 1) {
                if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x5b) <
                    *(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4d)) {
                  uVar16 = (undefined2)
                           ((ulong)*(undefined4 *)((uint)(byte)backdropIndex << 2) >> 0x10);
                  iVar14 = (int)*(undefined4 *)((uint)(byte)backdropIndex << 2);
                  if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x5b) <
                      (uint)(*(int *)(iVar14 + 0x4d) * 2 + *(int *)(iVar14 + 0x4d)) >> 2) {
                    if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x5b) <
                        *(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4d) >> 1)
                    {
                      if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x5b) <
                          *(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4d) >>
                          2) {
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
              bVar18 = 0;
              pcVar4 = (char *)"halfling castle" + 0xc;
              if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x54) <
                  (uint)(*(int *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4d) << 1)
                 ) {
                pcVar4 = (char *)((uint)(byte)backdropIndex << 2);
                if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x54) <
                    *(uint *)((int)*(undefined4 *)pcVar4 + 0x4d)) {
                  pcVar4 = (char *)"halfling castle" + 0xc;
                  if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x54) <
                      *(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x4d) >> 1) {
                    pcVar4 = (char *)"halfling castle" + 0xc;
                    if (*(int *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x54) < 0) {
                      pcVar4 = (char *)"halfling castle" + 0xc;
                      if (*(uint *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) + 0x54) <
                          (uint)-*(int *)((int)*(undefined4 *)((uint)(byte)backdropIndex << 2) +
                                         0x4d)) {
                        bVar18 = 5;
                      }
                      else {
                        bVar18 = 4;
                      }
                    }
                    else {
                      bVar18 = 3;
                    }
                  }
                  else {
                    bVar18 = 2;
                  }
                }
                else {
                  bVar18 = 1;
                }
              }
              if (((bVar22 != 0) && (bVar19 <= bVar22)) && (bVar18 <= bVar22)) {
                ovc39_loadArchiveEntry(bVar22 + 0x12);
                pcVar6 = ovc39_lordOrLady();
                iStack_12 = -25896;
                uStack_10 = iVar17;
                pcVar7 = ovr_stsprintf(acStack_2cc,(char *)unaff_SS,pcVar6);
                uVar10 = SUB21(pcVar4,0);
                uVar20 = (undefined1)((uint)pcVar4 >> 8);
                pcVar6 = pcVar7;
                ovr_drawString(pcVar7,(uint16_t)pcVar4);
                (*(uint8_t *)((uint8_t *)&(handle_04.seg))) = uVar10;
                handle_04.ofs = (uint16_t)pcVar6;
                (*(uint8_t *)((uint8_t *)&(handle_04.seg) + 1)) = uVar20;
                ovr_stshFree(handle_04);
                return pcVar7;
              }
              if ((bVar19 != 0) && (bVar18 <= bVar19)) {
                ovc39_loadArchiveEntry(bVar19 + 0xd);
                pcVar6 = ovc39_lordOrLady();
                iStack_12 = -25810;
                uStack_10 = iVar17;
                pcVar7 = ovr_stsprintf(acStack_2cc,(char *)unaff_SS,pcVar6);
                uVar10 = SUB21(pcVar4,0);
                uVar20 = (undefined1)((uint)pcVar4 >> 8);
                pcVar6 = pcVar7;
                ovr_drawString(pcVar7,(uint16_t)pcVar4);
                (*(uint8_t *)((uint8_t *)&(handle_05.seg))) = uVar10;
                handle_05.ofs = (uint16_t)pcVar6;
                (*(uint8_t *)((uint8_t *)&(handle_05.seg) + 1)) = uVar20;
                ovr_stshFree(handle_05);
                return pcVar7;
              }
              if (bVar18 != 0) {
                ovc39_loadArchiveEntry(bVar18 + 0x17);
                pcVar6 = ovc39_lordOrLady();
                iStack_12 = -25733;
                uStack_10 = iVar17;
                pcVar7 = ovr_stsprintf(acStack_2cc,(char *)unaff_SS,pcVar6);
                uVar10 = SUB21(pcVar4,0);
                uVar20 = (undefined1)((uint)pcVar4 >> 8);
                pcVar6 = pcVar7;
                ovr_drawString(pcVar7,(uint16_t)pcVar4);
                (*(uint8_t *)((uint8_t *)&(handle_06.seg))) = uVar10;
                handle_06.ofs = (uint16_t)pcVar6;
                (*(uint8_t *)((uint8_t *)&(handle_06.seg) + 1)) = uVar20;
                ovr_stshFree(handle_06);
                return pcVar7;
              }
              ovc39_lordOrLady();
              iStack_12 = -25679;
              uStack_10 = iVar17;
              pcVar6 = ovr_stsprintf(acStack_2cc,(char *)unaff_SS,(char *)msgFormat.ofs);
              ovr_drawString(pcVar6,(uint16_t)pcVar4);
              return pcVar6;
            }
            unaff_DI = -2;
          }
          iVar17 = 9071;
          uVar11 = ovr_ovc23_findRecordAt(uVar12 + unaff_DI,GfxRndSeed2);
          uVar12 = CONCAT11(uVar20,uVar10);
        } while (uVar11 != 0xffff);
        uVar21 = 0x6f;
        uVar23 = 0x23;
        unaff_SI = (undefined2 *)
                   ovc39_findBuildingAt(CONCAT11(uVar20,uVar10) + unaff_DI,GfxRndSeed2);
        uVar12 = CONCAT11(uVar23,uVar21);
        uVar16 = (undefined2)((ulong)GUnits >> 0x10);
        in_DX = 0x2410;
        bVar19 = ((unit_t *)GUnits)[(int)unaff_SI].unitType;
        uVar11 = CONCAT11(((unit_t *)GUnits + (int)unaff_SI)->bldType,bVar19);
      } while (bVar22 != 0);
      in_DX = 0x217a;
      uVar1 = *(undefined4 *)((uint)bVar19 << 2);
      cVar3 = *(char *)((int)uVar1 + 0x3f);
    } while( true );
  case (char *)0x2:
    LOCK();
    iVar14 = *(int *)((char *)"Too many construction sites." + 0x17 + unaff_DI);
    *(undefined1 **)((char *)"Too many construction sites." + 0x17 + unaff_DI) = &stack0xfffe;
    UNLOCK();
    *(int *)(iVar14 + -2) = unaff_DI;
    iVar15 = 0;
    pcVar4 = (char *)(*(uint16_t *)((uint8_t *)&(PromoteThreshold)));
    for (bVar22 = 0; pcVar6 = (char *)CONCAT11(0x24,GLeaderCount), bVar22 < GLeaderCount;
        bVar22 = bVar22 + 1) {
      pcVar4 = (char *)((uint)bVar22 << 2);
      if ((byte)(&stack0xfffa)[(byte)backdropIndex] <= *(byte *)((int)*(undefined4 *)pcVar4 + 0xa5))
      {
        for (uVar11 = 0xf8; uVar11 < GUnitCount; uVar11 = uVar11 + 1) {
          pcVar4 = (char *)"puppetmaker" + 3;
          uVar16 = (undefined2)((ulong)GUnits >> 0x10);
          if (((unit_t *)GUnits)[uVar11].unitType == bVar22) {
            pcVar4 = (char *)"puppetmaker" + 3;
            if (((unit_t *)GUnits)[uVar11].level < 8) {
              *(undefined2 *)(iVar14 + -4) = CONCAT11((char)(uVar11 * 9 >> 8),bVar22);
              *(uint *)(iVar14 + -6) = uVar11;
              *(undefined2 *)(iVar14 + -8) = 0x6000;
              *(undefined2 *)(iVar14 + -10) = 0x8958;
              iVar5 = season_usesAlignUp42(*(int *)(iVar14 + -6),*(byte *)(iVar14 + -4));
              if ((char)iVar5 != '\0') {
                pcVar4 = (char *)"puppetmaker" + 3;
                ((unit_t *)GUnits)[uVar11].level = 8;
                iVar15 = iVar15 + 1;
              }
            }
          }
        }
      }
    }
    if (iVar15 != 0) {
      *(undefined2 *)(iVar14 + -4) = 0;
      *(undefined2 *)(iVar14 + -6) = 0x24;
      *(undefined2 *)(iVar14 + -8) = 0x6000;
      *(undefined2 *)(iVar14 + -10) = (uint8_t *)SpecialColors + 5;
      ovr_inputUpdate(*(ulong *)(iVar14 + -6));
      *(undefined2 *)(iVar14 + -4) = 0xa000;
      *(int *)(iVar14 + -6) = iVar15;
      *(undefined2 *)(iVar14 + -8) = (char *)"steam bath" + 6;
      *(undefined2 *)(iVar14 + -10) = 0x89b2;
      uVar16 = ovr_ovc41_pluralSuffix(*(int *)(iVar14 + -6));
      *(undefined2 *)(iVar14 + -6) = pcVar4;
      *(undefined2 *)(iVar14 + -8) = uVar16;
      *(int *)(iVar14 + -10) = iVar15;
      *(undefined2 *)(iVar14 + -0xc) = (char *)"puppetmaker" + 3;
      *(undefined2 *)(iVar14 + -0xe) = (char *)"%d building%s repaired.";
      *(undefined2 *)(iVar14 + -0x10) = unaff_SS;
      *(int *)(iVar14 + -0x12) = (int)auStack_80;
      *(char **)((code *)init_textFilename + iVar14) = (char *)"builder\'s hall" + 8;
      *(undefined2 *)(iVar14 + -0x16) = 0x89c6;
      pcVar6 = ovr_stsprintf((char *)*(undefined2 *)(iVar14 + -0x12),
                             (char *)*(undefined2 *)(iVar14 + -0x10),
                             (char *)*(undefined2 *)(iVar14 + -0xe));
      *(undefined2 *)(iVar14 + -6) = pcVar4;
      *(undefined2 *)(iVar14 + -8) = pcVar6;
      *(undefined2 *)(iVar14 + -10) = (char *)"glassworks" + 9;
      *(undefined2 *)(iVar14 + -0xc) = 0x89d0;
      ovr_uiNotify((char *)*(undefined2 *)(iVar14 + -8),*(uint16_t *)(iVar14 + -6));
    }
    return pcVar6;
  case (char *)0x3:
    (*(uint16_t *)((uint8_t *)&(AgntAnms[0x11]) + 18)) = (*(uint16_t *)((uint8_t *)&(AgntAnms[0x11]) + 18)) + (int)pcVar4 * 2;
    uVar11 = (*(uint16_t *)((uint8_t *)&(_streams[5]) + 3)) * -0xcc;
    pcVar4 = ovr_stsprintf(pcVar4,(char *)
                                  "Sound Effects (1. PC Speaker  2. Sound Blaster  3. Pro Audio Spectrum\n"
                           ,unaff_BP);
    _backdropIndex = uVar11;
    hint.ofs = (uint16_t)pcVar4;
    pcVar4 = acStack_192;
    entries.seg = (uint16_t)unaff_SS;
    entries.ofs = (uint16_t)pcVar4;
    ovr_ovc28_compute2(entries,(uint16_t)unaff_SI,hint);
    if ((char)pcVar4 != '\0') {
      uVar10 = auStack_1f6[((uint)pcVar4 & 0xff) * 2];
      pcVar4 = (char *)CONCAT11((char)((uint)(auStack_1f6 + ((uint)pcVar4 & 0xff) * 2) >> 8),uVar10)
      ;
      uVar1 = *(undefined4 *)((uVar11 & 0xff) << 2);
      *(undefined1 *)((int)uVar1 + 0x85) = uVar10;
    }
    return pcVar4;
  }
  out(*unaff_SI,in_DX);
  _backdropIndex = uStack_46;
  hint.ofs = uStack_48;
  uVar24 = 0;
  uVar25 = 0x60;
  uVar11 = 0xa329;
  text1.seg = uStack_22;
  text1.ofs = uStack_24;
  ovc40_usesBlitLabel(text1,hint,2,0xf2);
  ovc40_flushInput();
  ovr_ovr_miceButton0PressStates_entry();
  uVar16 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  uVar12 = *(uint16_t *)BDA_DailyTimeCounter;
  uVar21 = (undefined1)uVar16;
  uVar23 = (undefined1)((uint)uVar16 >> 8);
  uVar10 = (undefined1)uVar12;
  uVar20 = (undefined1)(uVar12 >> 8);
  backdropIndex = (char)uStack_46;
  if (backdropIndex == '\x04') {
    uVar13 = ovr_inputUpdate(0xb4);
    if (1 < (byte)uVar13) {
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
    while (cVar3 = cStack_1e + -1, bVar2 = cStack_1e != '\0', cStack_1e = cVar3, bVar2) {
      if ((iVar14 == 100) && (in_stack_0000000e == '\x02')) {
        _backdropIndex = marbleCut2Seg;
        hint.ofs = marbleCut2Ofs;
        ovr_blitLoadRleGfx(hint,far_from_u32((uint32_t)(0xa000b400)));
        _backdropIndex = uStack_36;
        hint.ofs = uStack_38;
        text1_00.seg = uStack_36;
        text1_00.ofs = uStack_38;
        ovc40_usesBlitLabel(text1_00,hint,0,0xf2);
        _backdropIndex = uStack_32;
        hint.ofs = uStack_34;
        text1_01.seg = uStack_32;
        text1_01.ofs = uStack_34;
        ovc40_usesBlitLabel(text1_01,hint,1,0xf2);
        _backdropIndex = uStack_2e;
        hint.ofs = uStack_30;
        uVar24 = 0xd3;
        uVar25 = 0x22;
        uVar11 = 0xa5ad;
        text1_02.seg = uStack_2e;
        text1_02.ofs = uStack_30;
        ovc40_usesBlitLabel(text1_02,hint,2,0xf2);
      }
      backdropIndex = (char)iVar14;
      ovc40_usesBlitGfx10(backdropIndex,iVar14,(brect_t *)&stack0xffec);
      uVar13 = ovr_biosKeyAvail();
      if ((char)uVar13 != '\0') {
        uVar13 = ovr_gameProcessKey();
        if (uVar13 == 0x11b) {
          cStack_1d = '\x02';
          break;
        }
        if (uVar13 == 0x1c0d) break;
      }
      uVar8 = ovr_init2_updateMouseButtons();
      if (uVar8 != 0) break;
      if (rightButtonLatch != '\0') {
        cStack_1d = '\x02';
        break;
      }
      do {
        ovr_audio_usesLDIV_at_();
        if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != CONCAT11(uVar23,uVar21)) break;
      } while (*(int *)BDA_DailyTimeCounter == CONCAT11(uVar20,uVar10));
      uVar16 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
      uVar12 = *(uint16_t *)BDA_DailyTimeCounter;
      uVar21 = (undefined1)uVar16;
      uVar23 = (undefined1)((uint)uVar16 >> 8);
      uVar10 = (undefined1)uVar12;
      uVar20 = (undefined1)(uVar12 >> 8);
      iVar14 = iVar14 + cStack_1f;
    }
    if (cStack_1f < '\x01') {
      ovc40_usesBlitGfx10(0,0,(brect_t *)&stack0xffec);
    }
    else {
      ovc40_usesBlitGfx10(0xef,0xef,(brect_t *)&stack0xffec);
    }
    ovc40_flushInput();
    rightButtonLatch = '\0';
    if ((in_stack_0000000e == '\x02') || (in_stack_0000000e == '\x03')) {
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
      uVar12 = *(uint16_t *)BDA_DailyTimeCounter;
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = uVar12;
      if (cStack_1d == '\0') {
        uVar13 = ovr_inputUpdate(0x48);
        cStack_1d = (char)uVar13;
      }
    }
    else {
      _backdropIndex = far_t_2000_d3e4.seg;
      hint.ofs = far_t_2000_d3e4.ofs;
      ovr_blitLoadRleGfx(hint,far_from_u32((uint32_t)(0xa000e908)));
      MiceProcessed = 0;
      ovr_miceBlitRect((brect_t *)(BlitRects + 1));
      do {
        do {
          ovr_audio_usesLDIV_at_();
          bVar22 = ovr_init2_usesCFGMice((uint16_t *)&stack0xfffc,unaff_SS);
          if ((((CONCAT11(extraout_AH,bVar22) != 0) && (0x87 < CONCAT11(uVar25,uVar24))) &&
              (0xb9 < uVar11)) && ((CONCAT11(uVar25,uVar24) < 0xd6 && (uVar11 < 0xc6))))
          goto L_OVC40_69c8_04c6_0AF0;
          if (rightButtonLatch != '\0') {
            cStack_1d = '\x02';
            goto L_OVC40_69c8_04c6_0AF0;
          }
          uVar13 = ovr_biosKeyAvail();
        } while ((char)uVar13 == '\0');
        uVar13 = ovr_gameProcessKey();
        if (uVar13 == 0x11b) {
          cStack_1d = '\x02';
          break;
        }
      } while (uVar13 != 0x1c0d);
    }
  }
L_OVC40_69c8_04c6_0AF0:
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
  ovr_clearMiceProcessed();
  stack0x0008 = uStack_16;
  _in_stack_00000006 = uStack_18;
  ovr_stshFree(_in_stack_00000006);
  psStack_1c = ovc40_usesStshLoadGfx(0xde);
  stack0x0008 = uVar12;
  _in_stack_00000006 = (uint16_t)psStack_1c;
  uStack_1a = uVar12;
  ovc40_usesVgaSetPalette8bit(_in_stack_00000006);
  ovr_stop_audio();
  CurMusicType = 0xff;
  ovr_init_usesBlitGfxRect();
  uVar11 = (uint)GameRunning;
  if (uVar11 == 0) {
    ovc40_usesCalcSeasonPalette('\x01');
  }
  uVar10 = (undefined1)(uVar11 >> 8);
  ovr_ovc28_textHalflingCastle();
  ovr_ovc41_usesGMenuItem();
  ovr_miceBlitRect((brect_t *)(BlitRects + 1));
  return (char *)CONCAT11(uVar10,cStack_1d);
}



/* 6a8f:1847 */

/* Prints the "You cannot see the terrain here." notice. */

void __cdecl16far ovc41_cannotSeeTerrainNotice(void)

{
  char *pcVar1;
  
  GBattleMode = '\x01' - (GBattleMode != '\0');
  GOngoingBattle = GBattleMode;
  ovr_ovc28_blitButton();
  pcVar1 = ovr_draw_textArena();
  if (((uint)pcVar1 & 0xff) == 0) {
    GOngoingBattle = '\x01';
    ovr_say((char *)"You cannot see the terrain here.");
    ovr_stop_audio();
  }
  else {
    ovr_agnt_clear();
    ovr_constr_usesBlitRect4();
    if (GOngoingBattle != '\0') {
      ovr_stop_audio();
    }
    ovr_update_pause_button();
  }
  return;
}



/* 6a8f:18c6 */

/* [R6] touches GMenuItem, MenuMode */

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
  (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter))) = *(undefined2 *)BDA_DailyTimeCounter;
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
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000e249)));
  gfx_00.seg = trianglsCut6Seg;
  gfx_00.ofs = trianglsCut6Ofs;
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa000e249)));
  ovr_uiMainMenuLoop();
  gfx_01.seg = nwpanel1Cut2Seg;
  gfx_01.ofs = nwpanel1Cut2Ofs;
  ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000e249)));
  gfx_02.seg = trianglsCut5Seg;
  gfx_02.ofs = trianglsCut5Ofs;
  ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)(0xa000e249)));
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
  undefined1 uVar1;
  uint uVar2;
  
  for (uVar2 = 0; (int)uVar2 < 0xc; uVar2 = uVar2 + 1) {
    if (uVar2 != removedIndex) {
      uVar1 = (undefined1)uVar2;
      if ((byte)((undefined1 *)&IndexPermD)[uVar2] == removedIndex) {
        if ((byte)((undefined1 *)&IndexPermD)[removedIndex] == removedIndex) {
          ((undefined1 *)&IndexPermD)[uVar2] = uVar1;
        }
        else {
          ((undefined1 *)&IndexPermD)[uVar2] = ((undefined1 *)&IndexPermD)[removedIndex];
        }
      }
      if ((byte)((undefined1 *)&IndexPermC)[uVar2] == removedIndex) {
        if ((byte)((undefined1 *)&IndexPermC)[removedIndex] == removedIndex) {
          ((undefined1 *)&IndexPermC)[uVar2] = uVar1;
        }
        else {
          ((undefined1 *)&IndexPermC)[uVar2] = ((undefined1 *)&IndexPermC)[removedIndex];
        }
      }
      if ((byte)((undefined1 *)&IndexPermB)[uVar2] == removedIndex) {
        if ((byte)((undefined1 *)&IndexPermB)[removedIndex] == removedIndex) {
          ((undefined1 *)&IndexPermB)[uVar2] = uVar1;
        }
        else {
          ((undefined1 *)&IndexPermB)[uVar2] = ((undefined1 *)&IndexPermB)[removedIndex];
        }
      }
      if ((byte)((undefined1 *)&IndexPermA)[uVar2] == removedIndex) {
        if ((byte)((undefined1 *)&IndexPermA)[removedIndex] == removedIndex) {
          ((undefined1 *)&IndexPermA)[uVar2] = uVar1;
        }
        else {
          ((undefined1 *)&IndexPermA)[uVar2] = ((undefined1 *)&IndexPermA)[removedIndex];
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
    ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
  }
  TextBlitDstSeg = 0xa000;
  if (GMenuItem == menuIndex) {
    ovr_draw_usesFillRect2((uint)((uint8_t *)menuItemRow)[GMenuItem],-0x6000);
  }
  ovr_draw_menuRowBar(menuIndex,0xa000);
  if (bVar1) {
    ovr_miceBlitRect((brect_t *)(BlitRects + 1));
  }
  return;
}



/* 6a8f:1c74 */

/* [R2] string "%s is paralyzed by %s." */

undefined1 __cdecl16far ovc41_textParalyzed(agnt_t *source,agnt_t *victim,uint strength)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  uint16_t uVar4;
  uint16_t in_DX;
  agnt_t *paVar5;
  agnt_t *paVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  char *unaff_SS;
  undefined1 uVar9;
  undefined1 uVar10;
  uint8_t victimName;
  uint8_t sourceName;
  uint8_t msg;
  undefined1 uStack_3;
  
  uStack_3 = 0;
  uVar7 = (undefined2)((ulong)victim >> 0x10);
  paVar5 = (agnt_t *)victim;
  if ((paVar5->flags & 0x80) != 0) {
    strength = (uint)paVar5->strength;
  }
  paVar6 = (agnt_t *)source;
  uVar8 = (undefined2)((ulong)source >> 0x10);
  if ((int)strength < (int)(uint)paVar5->strength) {
    paVar5->timer = 0x6;
    paVar5->combatState = 0x1;
    paVar5->targetY = 0;
    ovr_agnt_usesAnimFrame(victim);
    if (((paVar5->animVariant == 0x0) && ((paVar5->flags & 0x200) == 0)) &&
       ((((agntG_t *)paVar6->gdata)->flags & 0x40) != 0)) {
      ovr_agnt_statusText(source,(char *)&victimName);
      pcVar3 = ovr_agnt_statusText(victim,(char *)&sourceName);
      ovr_ovc15_usesStshRealloc((char *)CONCAT22(in_DX,pcVar3));
      pcVar3 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s is paralyzed by %s.");
      ovr_uiNotify(pcVar3,in_DX);
      uVar4 = ovr_audio_panFromX(victim);
      ovr_play_sfxU(3,0,uVar4);
      OVC41_6a8f_01e7_entry(victim);
      paVar5->flags = paVar5->flags | 0x200;
      ovr_attact_usesLDIV_at_2();
      return uStack_3;
    }
    if (((paVar5->animVariant == 0x0) && ((paVar5->flags & 0x800) == 0)) &&
       (((((agntG_t *)paVar6->gdata)->flags3 & 0x100) != 0 &&
        (uVar1 = ovr_ovc27_rollToHitEntity((uint32_t)victim,2), (uVar1 & 0xff) == 0)))) {
      ovr_agnt_statusText(source,(char *)&victimName);
      pcVar3 = ovr_agnt_statusText(victim,(char *)&sourceName);
      ovr_ovc15_usesStshRealloc((char *)CONCAT22(in_DX,pcVar3));
      pcVar3 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s is stoned by %s.");
      ovr_uiNotify(pcVar3,in_DX);
      paVar5->flags = paVar5->flags | 0x800;
      uVar4 = ovr_audio_panFromX(victim);
      ovr_play_sfxU(0x1b,0,uVar4);
      OVC41_6a8f_01e7_entry(victim);
      ovr_attact_usesLDIV_at_2();
      return uStack_3;
    }
    paVar5->strength = paVar5->strength - (char)strength;
    if (((((agntG_t *)paVar6->gdata)->flags & 0x8000) == 0) ||
       ((((agntG_t *)paVar5->gdata)->flags & 0x8000) == 0)) {
      if (((agntG_t *)paVar6->gdata)->hitSound == 0) {
        iVar2 = ovr_audio_panFromX(victim);
        uVar9 = (undefined1)iVar2;
        uVar10 = (undefined1)((uint)iVar2 >> 8);
        iVar2 = 0;
        uVar4 = ovr_randBelow(2);
        ovr_play_sfxU((char)uVar4 + 0x3d,iVar2,CONCAT11(uVar10,uVar9));
      }
      else if (((agntG_t *)paVar6->gdata)->hitSound == 0x15) {
        uVar4 = ovr_randBelow(2);
        if ((uVar4 & 0xff) == 0) {
          ovr_play_sfx(21,0);
        }
        else {
          ovr_play_sfx(71,0);
        }
      }
      else if (((agntG_t *)paVar6->gdata)->hitSound == 3) {
        iVar2 = ovr_audio_panFromX(victim);
        uVar9 = (undefined1)iVar2;
        uVar10 = (undefined1)((uint)iVar2 >> 8);
        iVar2 = 0;
        uVar4 = ovr_randBelow(2);
        ovr_play_sfxU((char)uVar4 + 0x14,iVar2,CONCAT11(uVar10,uVar9));
      }
      else {
        ovr_play_sfx((uint)((agntG_t *)paVar6->gdata)->hitSound,0);
      }
    }
    else {
      iVar2 = ovr_audio_panFromX(victim);
      uVar9 = (undefined1)iVar2;
      uVar10 = (undefined1)((uint)iVar2 >> 8);
      iVar2 = 0;
      uVar4 = ovr_randBelow(2);
      ovr_play_sfxU((char)uVar4 + 0x14,iVar2,CONCAT11(uVar10,uVar9));
    }
    if ((paVar6->flags & 0x20) != 0) {
      paVar6->flags = paVar6->flags & 0xffdf;
      pcVar3 = ovr_agnt_statusText(victim,(char *)&sourceName);
      ovr_ovc15_usesStshRealloc((char *)CONCAT22(in_DX,pcVar3));
      pcVar3 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s is no longer charmed.");
      ovr_uiNotify(pcVar3,in_DX);
      paVar6->faction = paVar6->gdata->ai;
      ovc41_advanceAnimFrame(source);
      ovr_attact_usesLDIV_at_2();
    }
  }
  else {
    if (((agntG_t *)paVar5->gdata)->actSound == 0xff) {
      uVar4 = ovr_audio_panFromX(victim);
      ovr_play_sfxU(4,0,uVar4);
    }
    else {
      uVar4 = ovr_audio_panFromX(victim);
      ovr_play_sfxU(((agntG_t *)paVar5->gdata)->actSound,0,uVar4);
    }
    ovc41_settleAgentCombat(source,victim);
    uStack_3 = 1;
  }
  ovr_attact_usesLDIV_at_2();
  return uStack_3;
}



/* 6a8f:2084 */

/* WARNING: Instruction at (ram,0x00066a51) overlaps instruction at (ram,0x00066a50)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* [R2] string " You can only place a single arena." */

byte * __cdecl16far ovc41_textOnlyPlaceSingle(agnt_t *agntPtr,int agntIndex)

{
  char *pcVar1;
  undefined2 uVar2;
  char cVar3;
  agnt_t *paVar4;
  code *pcVar5;
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  far_t gfx_01;
  far_t dst_00;
  far_t gfx_02;
  far_t gfx_03;
  far_t dst_01;
  far_t dst_02;
  far_t handle;
  int iVar6;
  byte bVar7;
  byte *pbVar8;
  undefined1 extraout_AH;
  brect_t *br;
  agnt_t *paVar9;
  uint16_t uVar10;
  char *pcVar11;
  int iVar12;
  char cVar13;
  uint8_t *puVar14;
  agnt_t *paVar15;
  uint uVar16;
  entity_t *peVar17;
  agnt_t *paVar18;
  undefined1 *puVar19;
  int unaff_SI;
  undefined2 *unaff_DI;
  undefined2 uVar20;
  uint16_t *unaff_SS;
  char acStackY_1aa [104];
  undefined2 uStackY_142;
  undefined2 uStackY_140;
  far_t dst_03;
  int16_t iVar21;
  uint8_t uVar22;
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
  uint8_t agnt;
  uint16_t uStack_1a;
  uint16_t uStack_18;
  brect_t bStack_16;
  agnt_t *paStack_c;
  int iStack_a;
  undefined2 uStack_8;
  far_t fStack_6;
  
  dst_03.seg = (uint16_t)unaff_SS;
  dst_03.ofs = (uint16_t)&agnt;
  iVar12 = 0x10;
  uStackY_140 = 0xc98c;
  F_SCOPY(far_from_u32((uint32_t)(0x24106e38)),dst_03);
  paVar4 = (agnt_t *)((long)agntIndex * 0x34);
  paVar9 = (agnt_t *)paVar4;
  paStack_c = paVar9;
  iStack_a = 0x1726;
  if ((paVar9->flags & 0x820) == 0) {
    uVar20 = (undefined2)((ulong)agntPtr >> 0x10);
    paVar18 = (agnt_t *)agntPtr;
    paVar18->flags = paVar18->flags & 0xfff7;
    if ((((entity_t *)paVar18->entity)->base).level < 8) {
      fStack_6 = far_from_u32((uint32_t)(far_to_u32(fStack_6) & 0xffffff));
    }
    else if ((((entity_t *)paVar18->entity)->base).level < 10) {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = 1;
    }
    else if ((((entity_t *)paVar18->entity)->base).level < 0xc) {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = 2;
    }
    else {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = 3;
    }
    uVar16 = (uint)(*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1));
    if (uVar16 < 4) {
      switch(uVar16) {
      case 0:
        return (byte *)((int)(undefined4 *)&_DATA + 1);
      case 2:
        cVar3 = *(char *)(uVar16 * 2 + unaff_SI);
        puVar19 = &stack0xfffe + unaff_SI;
        iVar6 = uVar16 * 3;
        *(undefined1 **)((char *)" You can only place a single arena." + 0xd + iVar6) =
             puVar19 + *(int *)((char *)" You can only place a single arena." + 0xd + iVar6);
        *(int *)(&stack0xffff + (int)puVar19) = *(int *)(&stack0xffff + (int)puVar19) + iVar6;
        *(int *)(&stack0xfffe + (int)unaff_DI) = *(int *)(&stack0xfffe + (int)unaff_DI) + iVar6;
                    /* WARNING: Read-only address (ram,0x00033501) is written */
        iRam00033501 = uVar16 + 0x8b26;
        cVar13 = (char)(&stack0xfed8 + (int)unaff_DI +
                       CONCAT11((char)((ulong)paVar4 >> 0x18),(char)((ulong)paVar4 >> 0x10) + cVar3)
                       );
        pcVar11 = (char *)(uint)(byte)((char)iVar6 + cVar13);
        (&stack0x6ffe)[(int)puVar19] = (&stack0x6ffe)[(int)puVar19];
        pcVar1 = pcVar11;
        *pcVar1 = *pcVar1 + cVar13;
        *(undefined2 *)(&stack0xfed6 + (int)unaff_DI) = 0x6000;
        pcVar1 = pcVar11 + -0x61f9;
        *pcVar1 = *pcVar1;
        cVar13 = *pcVar1;
        *(undefined1 **)(&stack0xfeda + (int)unaff_DI) = &stack0xfedc + (int)unaff_DI;
        uVar20 = *(undefined2 *)(&stack0xfeda + (int)unaff_DI);
        *(undefined2 *)(&stack0xfeda + (int)unaff_DI) = uVar20;
        if (iVar12 == 1 || cVar13 == '\0') {
          s_constructing_2410_06a4[10] = -0x6b;
          s_constructing_2410_06a4[0xb] = '\x06';
                    /* WARNING: Read-only address (ram,0x000247ae) is written */
        }
        uVar2 = in(&stack0xfed8 + (int)unaff_DI +
                   CONCAT11((char)((ulong)paVar4 >> 0x18),(char)((ulong)paVar4 >> 0x10) + cVar3));
        *unaff_DI = uVar2;
        *(undefined2 *)(&stack0xfed8 + (int)unaff_DI) = uVar20;
        *(undefined2 *)(&stack0xfed6 + (int)unaff_DI) = uVar20;
        *(undefined2 *)(&stack0xfed4 + (int)unaff_DI) = uVar20;
        *(undefined2 *)(&stack0xfed4 + (int)unaff_DI) =
             *(undefined2 *)(&stack0xfed4 + (int)unaff_DI);
        pcVar5 = (code *)swi(1);
        pbVar8 = (byte *)(*pcVar5)();
        return pbVar8;
      case 3:
        do {
          TextBlitDstSeg = 0xa000;
          TextBlitX = uStack_8 + 6;
          TextBlitY = (uint16_t)(unaff_DI + 1);
          fStack_6.seg = (&paVar18->x + unaff_SI * 2)[1];
          puVar14 = (uint8_t *)(&paVar18->x)[unaff_SI * 2];
          fStack_6.ofs = (uint16_t)puVar14;
          iVar12 = unaff_SI;
          if (*(uint8_t *)MK_FP(fStack_6.seg, fStack_6.ofs) == 0x25) {
            BlitLetterType = 2;
            uVar22 = 0xf;
            iVar21 = 319;
            pcVar11 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,acStack_80),
                                                 (char *)CONCAT22(fStack_6.seg,puVar14 + 1),
                                                 (char *)CONCAT22(FontMain.seg,FontMain.ofs),0x45,
                                                 '\x03');
            ovr_blitLabel(pcVar11,puVar14,iVar21,uVar22);
            pbVar8 = (byte *)((char *)"puppetmaker" + 3);
            BlitLetterType = 0;
          }
          else if (*(uint8_t *)MK_FP(fStack_6.seg, fStack_6.ofs) == 0x40) {
            uVar22 = 0xf;
            iVar21 = 319;
            pcVar11 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,acStack_80),
                                                 (char *)CONCAT22(fStack_6.seg,puVar14 + 1),
                                                 (char *)CONCAT22(FontMain.seg,FontMain.ofs),0x45,
                                                 '\x03');
            pbVar8 = (byte *)ovr_blitLabel(pcVar11,puVar14,iVar21,uVar22);
          }
          else {
            uVar22 = 0xf;
            iVar21 = 319;
            pcVar11 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,acStack_80),
                                                 (char *)CONCAT22((&paVar18->x + unaff_SI * 2)[1],
                                                                  (char *)(&paVar18->x)
                                                                          [unaff_SI * 2]),
                                                 (char *)CONCAT22(FontMain.seg,FontMain.ofs),0x45,
                                                 '\x03');
            pbVar8 = (byte *)ovr_blitLabel(pcVar11,puVar14,iVar21,uVar22);
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
            if ((&paVar18->targetX)[iVar12 * 2] != 0 || (&paVar18->targetX + iVar12 * 2)[1] != 0)
            break;
            pbVar8 = (byte *)0x0;
            iVar12 = unaff_SI;
          }
          (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = (char)butt01Cut5Seg;
          gfx_03.ofs = butt01Cut5Ofs;
          (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) = (char)((uint)butt01Cut5Seg >> 8);
          (*(uint8_t *)((uint8_t *)&(dst_02.seg))) = 0;
          dst_02.ofs = uStack_8 + (int)unaff_DI * 0x140;
          (*(uint8_t *)((uint8_t *)&(dst_02.seg) + 1)) = 0xa0;
          ovr_blitLoadRleGfx(gfx_03,dst_02);
        } while( true );
      }
switchD_6000_ca06_caseD_1:
      (&stack0xfffe)[(int)unaff_DI] = (&stack0xfffe)[(int)unaff_DI] + (char)iVar12;
      *(undefined1 *)((int)unaff_DI + 0x15) = 0;
      bStack_3b = ovr_init2_usesCFGMice((uint16_t *)&paStack_2e,unaff_SS);
      while( true ) {
        if (rightButtonLatch != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((paStack_2e != paStack_2a) || (paStack_30 != paStack_2c)) {
          paStack_2a = paStack_2e;
          _agnt = paStack_2e;
          paStack_2c = paStack_30;
          paStack_1e = paStack_30;
        }
        if (bStack_3b != 0) break;
        uVar20 = keyprocessor_usesBiosKeyAvail
                           ((uint16_t *)CONCAT22(unaff_SS,&paStack_36),
                            (uint16_t *)CONCAT22(unaff_SS,&paStack_38),
                            (byte *)CONCAT22(unaff_SS,&bStack_3b));
        if ((char)uVar20 != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((paStack_36 != paStack_32) || (paStack_38 != paStack_34)) {
          paStack_32 = paStack_36;
          _agnt = paStack_36;
          paStack_34 = paStack_38;
          paStack_1e = paStack_38;
          bStack_16.seg = uStack_8;
          gfx_00.seg = uStack_18;
          gfx_00.ofs = uStack_1a;
          dst.seg = uStack_8;
          dst.ofs = 0x8cc;
          ovr_blitLoadRleGfx(gfx_00,dst);
          (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)MiceCursors[3].seg;
          gfx.ofs = MiceCursors[3].ofs;
          (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)(MiceCursors[3].seg >> 8);
          ovr_blitGfx10(gfx,(uint16_t)&paStack_36[-1].variant,(uint16_t)&paStack_38[-1].faction,
                        (brect_t *)
                        CONCAT13((char)((uint)unaff_SS >> 8),CONCAT12((char)unaff_SS,&bStack_16)),
                        false);
          ovr_miceBlitRect(&bStack_16);
          ovr_blitRect(&bStack_16);
          ovr_miceUpdate();
        }
        if (bStack_3b == 0) goto switchD_6000_ca06_caseD_1;
      }
      if (((((int)_agnt < 0xc) || (0xde < (int)_agnt)) || ((int)paStack_1e < 7)) ||
         (0x96 < (int)paStack_1e)) goto L_ui_unit_order_6616_0689_1054;
      do {
        bVar7 = ovr_init2_usesCFGMice((uint16_t *)&paStack_2e,unaff_SS);
      } while (CONCAT11(extraout_AH,bVar7) != 0);
      paStack_26 = (agnt_t *)0xffff;
      paStack_28 = (agnt_t *)0xffff;
      paStack_20 = paStack_1e;
      bStack_3b = 0;
      paVar9 = _agnt;
      do {
        uVar20 = keyprocessor_usesBiosKeyAvail
                           ((uint16_t *)CONCAT22(unaff_SS,&paStack_36),
                            (uint16_t *)CONCAT22(unaff_SS,&paStack_38),
                            (byte *)CONCAT22(unaff_SS,&bStack_3b));
        if ((char)uVar20 != '\0') goto L_ui_unit_order_6616_0689_1054;
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
          paStack_20 = (agnt_t *)((char *)"%d \r" + 1);
        }
        if ((paStack_26 != paVar9) || (paStack_28 != paStack_20)) {
          bStack_16.seg = uStack_8;
          gfx_01.seg = uStack_18;
          gfx_01.ofs = uStack_1a;
          (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = (char)uStack_8;
          dst_00.ofs = 0x8cc;
          (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = (char)(uStack_8 >> 8);
          ovr_blitLoadRleGfx(gfx_01,dst_00);
          ovr_driver_drawLine((uint8_t *)_agnt,(int)paStack_1e,(uint8_t *)paVar9,(int)paStack_1e,
                              0xff);
          ovr_driver_drawLine((uint8_t *)_agnt,(int)paStack_1e,(uint8_t *)_agnt,(int)paStack_20,0xff
                             );
          ovr_driver_drawLine((uint8_t *)paVar9,(int)paStack_1e,(uint8_t *)paVar9,(int)paStack_20,
                              0xff);
          ovr_driver_drawLine((uint8_t *)_agnt,(int)paStack_20,(uint8_t *)paVar9,(int)paStack_20,
                              0xff);
          ovr_miceBlitRect(&bStack_16);
          ovr_blitRect(&bStack_16);
          ovr_miceUpdate();
          paVar18 = (agnt_t *)((int)&paStack_20[-1].flags / 3 + Seed_2000_d10e);
          paVar15 = (agnt_t *)(Seed_2000_d110 + ((uint)&paVar9[-1].screenY >> 1) + 2 & 0xfffc);
          paStack_24 = (agnt_t *)((int)&paStack_1e[-1].flags / 3 + Seed_2000_d10e);
          paStack_22 = (agnt_t *)(Seed_2000_d110 + ((uint)&_agnt[-1].screenY >> 1) + 2 & 0xfffc);
          paStack_26 = paVar15;
          if ((int)paVar15 < (int)paStack_22) {
            paStack_26 = paStack_22;
            paStack_22 = paVar15;
            paStack_c = paVar15;
          }
          paStack_28 = paVar18;
          if ((int)paVar18 < (int)paStack_24) {
            paStack_28 = paStack_24;
            paStack_24 = paVar18;
            paStack_c = paVar18;
          }
          iStack_a = 0;
          for (uVar16 = 0; uVar16 < EntityCount; uVar16 = uVar16 + 1) {
            uVar20 = (undefined2)((ulong)Entities >> 0x10);
            peVar17 = (entity_t *)Entities;
            if ((((*(byte *)((int)&peVar17[uVar16].base.entity + 3) == bStack_3c) &&
                 (paStack_22 <= (agnt_t *)((peVar17 + uVar16)->base).x)) &&
                ((agnt_t *)((peVar17 + uVar16)->base).x <= paStack_26)) &&
               ((paStack_24 <= (agnt_t *)peVar17[uVar16].base.y &&
                ((agnt_t *)peVar17[uVar16].base.y <= paStack_28)))) {
              iStack_a = iStack_a + 1;
            }
          }
          ovr_resetTextBlitCycle();
          ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,acStackY_1aa),
                             (char *)CONCAT22(((undefined2 *)((uint)bStack_3c * 4))[1],
                                              (char *)*(undefined2 *)((uint)bStack_3c * 4)),
                             (char *)CONCAT22(Font03.seg,Font03.ofs),0x43,'\x03');
          ovr_ovc41_pluralSuffix(iStack_a);
          uVar10 = 0x2410;
          pcVar11 = ovr_stsprintf(&stack0xfece,(char *)unaff_SS,
                                  (char *)
                                  "%d %s%s loyal to %s found. Left click: set triangles. R: ready. U: unassign. H: home. Right click: abort."
                                 );
          ovr_uiNotify(pcVar11,uVar10);
        }
        paStack_28 = paStack_20;
        paStack_26 = paVar9;
        if (bStack_3b == 0) {
          bStack_3b = ovr_init2_usesCFGMice((uint16_t *)&paStack_2e,unaff_SS);
        }
        if (rightButtonLatch != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((paStack_2e != paStack_2a) || (paStack_30 != paStack_2c)) {
          paStack_2a = paStack_2e;
          paStack_2c = paStack_30;
          paStack_20 = paStack_30;
          paVar9 = paStack_2e;
        }
      } while (bStack_3b == 0);
      uStackY_142 = 0x6e56;
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
      if (((((int)paVar9 < 0xc) || (0xde < (int)paVar9)) || ((int)paStack_20 < 7)) ||
         (0x96 < (int)paStack_20)) {
L_ui_unit_order_6616_0689_1054:
        ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
        ovr_say((char *)"Region selection aborted.");
      }
      else {
        paVar18 = (agnt_t *)((int)&paStack_20[-1].flags / 3 + Seed_2000_d10e);
        paVar15 = (agnt_t *)(Seed_2000_d110 + ((uint)&paVar9[-1].screenY >> 1) + 2 & 0xfffc);
        paVar9 = (agnt_t *)((int)&paStack_1e[-1].flags / 3 + Seed_2000_d10e);
        uVar16 = Seed_2000_d110 + ((uint)&_agnt[-1].screenY >> 1) + 2;
        paStack_22 = (agnt_t *)(uVar16 & 0xfffc);
        paStack_26 = paVar15;
        if ((int)paVar15 < (int)paStack_22) {
          paStack_c = (agnt_t *)(uVar16 & 0xfffc);
          paStack_26 = paStack_c;
          paStack_22 = paVar15;
        }
        paStack_28 = paVar18;
        paStack_24 = paVar9;
        if ((int)paVar18 < (int)paVar9) {
          paStack_28 = paVar9;
          paStack_24 = paVar18;
          paStack_c = paVar9;
        }
        uStackY_140 = 0x22de;
        uStackY_142 = 0x6f2a;
        _fmemset(acStack_42,(uint16_t)unaff_SS,0);
        iStack_a = 0;
        for (uVar16 = 0; uVar16 < EntityCount; uVar16 = uVar16 + 1) {
          uVar20 = (undefined2)((ulong)Entities >> 0x10);
          peVar17 = (entity_t *)Entities;
          if (((*(byte *)((int)&peVar17[uVar16].base.entity + 3) == bStack_3c) &&
              (paStack_22 <= (agnt_t *)((peVar17 + uVar16)->base).x)) &&
             (((agnt_t *)((peVar17 + uVar16)->base).x <= paStack_26 &&
              ((paStack_24 <= (agnt_t *)peVar17[uVar16].base.y &&
               ((agnt_t *)peVar17[uVar16].base.y <= paStack_28)))))) {
            if (bStack_3b < 2) {
              unit_usesAlignUp42((byte)agntPtr,((peVar17 + uVar16)->base).x,peVar17[uVar16].base.y);
            }
            else {
              unit_usesEntities(bStack_3b,uVar16,(uint16_t)acStack_42,(uint16_t)unaff_SS);
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
        ovr_resetTextBlitCycle();
        if (bStack_3b == 1) {
          ovr_ovc41_pluralSuffix(iStack_a);
          pcVar11 = ovr_stsprintf(&stack0xfece,(char *)unaff_SS,
                                  (char *)"Priorities adjusted for %d %s%s.");
          ovr_say(pcVar11);
        }
        else if (bStack_3b == 2) {
          ovr_ovc41_pluralSuffix(iStack_a);
          pcVar11 = ovr_stsprintf(&stack0xfece,(char *)unaff_SS,(char *)"%d %s%s unassigned.");
          ovr_say(pcVar11);
        }
        else if (bStack_3b == 3) {
          ovr_ovc41_pluralSuffix(iStack_a);
          pcVar11 = ovr_stsprintf(&stack0xfece,(char *)unaff_SS,(char *)"%d %s%s readied.");
          ovr_say(pcVar11);
        }
        else if (bStack_3b == 4) {
          ovr_ovc41_pluralSuffix(iStack_a);
          pcVar11 = ovr_stsprintf(&stack0xfece,(char *)unaff_SS,(char *)"%d %s%s homed.");
          ovr_say(pcVar11);
        }
        ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
      }
      bStack_16.seg = uStack_8;
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)uStack_18;
      gfx_02.ofs = uStack_1a;
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = (char)(uStack_18 >> 8);
      dst_01.seg = uStack_8;
      dst_01.ofs = 0x8cc;
      ovr_blitLoadRleGfx(gfx_02,dst_01);
      ovr_miceBlitRect(&bStack_16);
      br = &bStack_16;
      ovr_blitRect(br);
      ovr_miceUpdate();
      handle.seg = uStack_18;
      handle.ofs = uStack_1a;
      ovr_stshFree(handle);
      ovr_stshFree(fStack_6);
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
      return (byte *)br;
    }
    bVar7 = paVar9->strength;
    paVar9->strength = paVar9->strength + (char)fStack_6.ofs;
    if (paVar9->strengthMax < paVar9->strength) {
      paVar9->strength = paVar9->strengthMax;
    }
    puVar14 = &paVar9->strength;
    paVar9 = (agnt_t *)(uint)*puVar14;
    if (*puVar14 != bVar7) {
      (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = bVar7;
      uVar10 = ovr_audio_panFromX(agntPtr);
      ovr_play_sfxU(0x3b,0,uVar10);
      ovc41_pluralSuffix((uint)paStack_c->strength);
      ovc41_pluralSuffix((uint)paStack_c->strength - (uint)(*(uint8_t *)((uint8_t *)&(uStack_8) + 1)));
      ovr_agnt_statusText((agnt_t *)CONCAT22(iStack_a,paStack_c),&stack0xfecc);
      puVar14 = &agnt;
      pcVar11 = ovr_agnt_statusText(agntPtr,(char *)&text);
      ovr_ovc15_usesStshRealloc((char *)CONCAT22(puVar14,pcVar11));
      paVar9 = (agnt_t *)
               ovr_stsprintf((char *)&msg,(char *)unaff_SS,
                             (char *)
                             "%s casts %s on %s to heal %d hitpoint%s for a total of %d hitpoint%s."
                            );
      ovr_uiNotify((char *)paVar9,(uint16_t)puVar14);
    }
  }
  return (byte *)paVar9;
}



/* 6a8f:22cb */

/* Resolves an agent's special attack (poison, blast spore disease, energy drain) and reports it. */

void __cdecl16far ovc41_specialAttack(agnt_t *agnt,int targetIndex)

{
  uint *puVar1;
  agntG_t *paVar2;
  entity_t *peVar3;
  byte bVar4;
  undefined2 uVar5;
  agnt_t *paVar6;
  int iVar7;
  char *pcVar8;
  uint16_t uVar9;
  uint16_t uVar10;
  uint uVar11;
  char *unaff_SS;
  uint8_t actorName;
  uint8_t targetName;
  uint8_t msg;
  undefined4 uStack_8;
  char cStack_3;
  
  uVar5 = ovc41_turnUndeadNotice(agnt);
  if ((((char)uVar5 == '\0') && (-1 < targetIndex)) && (targetIndex < (int)(uint)AgntCount)) {
    uVar10 = (uint16_t)((ulong)((long)targetIndex * 0x34) >> 0x10);
    paVar6 = (agnt_t *)(agnt_t *)((long)targetIndex * 0x34);
    uStack_8 = (agnt_t *)CONCAT22(0x1726,paVar6);
    if (paVar6->animVariant == 0x0) {
      *(undefined1 *)&paVar6->targetX = 0;
      *(undefined1 *)((int)&paVar6->targetX + 1) = 0;
    }
    if ((((agnt_t *)agnt)->flags & 8) == 0) {
      if (((agnt_t *)agnt)->variant == 0x0) {
        if ((((agnt_t *)agnt)->gindex == 0x4) &&
           ((((agntG_t *)((agnt_t *)agnt)->gdata)->flags2 & 0x200) != 0)) {
          bVar4 = ((agnt_t *)agnt)->strength;
          uVar5 = ovr_ovc27_breathHalfDamage((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,paVar6)));
          uVar11 = (uint)bVar4;
          if ((char)uVar5 != '\0') {
            uVar11 = (int)(uint)bVar4 >> 1;
          }
        }
        else {
          bVar4 = ovr_manage_rollDice(((agntG_t *)((agnt_t *)agnt)->gdata)->dmgDice,
                                      ((agntG_t *)((agnt_t *)agnt)->gdata)->dmgSides);
          iVar7 = (uint)bVar4 + (uint)((agntG_t *)((agnt_t *)agnt)->gdata)->dmgBonus;
          bVar4 = ovr_agnt_compute9(agnt);
          uVar10 = iVar7 + (char)bVar4;
          uVar11 = uVar10;
        }
        if ((uVar11 != 0) && ((((agntG_t *)((agnt_t *)agnt)->gdata)->flags3 & 8) != 0)) {
          uVar5 = ovr_agnt_abilityModifier
                            (*(byte *)((int)&(((entity_t *)((agnt_t *)agnt)->entity)->base).entity +
                                      3),0);
          uVar11 = uVar11 + (int)(char)uVar5;
          if ((int)uVar11 < 1) {
            uVar11 = 1;
          }
        }
        paVar2 = ((agnt_t *)uStack_8)->gdata;
        if (((((agntG_t *)paVar2)->flags2 & 8) == 0) ||
           (bVar4 = ovr_agnt_compute9(agnt), '\0' < (char)bVar4)) {
          paVar2 = ((agnt_t *)uStack_8)->gdata;
          if (((((agntG_t *)paVar2)->flags3 & 0x40) == 0) ||
             (bVar4 = ovr_agnt_compute9(agnt), '\x01' < (char)bVar4)) {
            paVar2 = ((agnt_t *)uStack_8)->gdata;
            if (((((agntG_t *)paVar2)->flags2 & 0x10) == 0) || (((agnt_t *)agnt)->gindex != 0x2)) {
              cStack_3 = ovc41_textParalyzed(agnt,uStack_8,uVar11);
              if ((cStack_3 == '\0') &&
                 (((((agnt_t *)agnt)->gindex == 0x0 &&
                   ((((agntG_t *)((agnt_t *)agnt)->gdata)->flags2 & 2) != 0)) &&
                  (uVar11 = ovr_ovc27_rollToHitEntity((uint32_t)uStack_8,0), (uVar11 & 0xff) == 0)))
                 ) {
                ovr_agnt_statusText(uStack_8,(char *)&actorName);
                pcVar8 = ovr_agnt_statusText(agnt,(char *)&targetName);
                ovr_ovc15_usesStshRealloc((char *)CONCAT22(uVar10,pcVar8));
                pcVar8 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s poisons %s.");
                ovr_uiNotify(pcVar8,uVar10);
                uVar9 = ovr_audio_panFromX(agnt);
                ovr_play_sfxU(0x55,0,uVar9);
                ovc41_settleAgentCombat(agnt,uStack_8);
                cStack_3 = '\x01';
              }
              if (((cStack_3 == '\0') && ((((agntG_t *)((agnt_t *)agnt)->gdata)->flags2 & 4) != 0))
                 && ((uVar11 = ovr_ovc27_rollToHitEntity((uint32_t)uStack_8,0), (uVar11 & 0xff) == 0
                     && (peVar3 = ((agnt_t *)uStack_8)->entity,
                        (*(uint *)((int)&(((entity_t *)peVar3)->base).frames + 1) & 1) == 0)))) {
                ovr_agnt_statusText(uStack_8,(char *)&actorName);
                pcVar8 = ovr_agnt_statusText(agnt,(char *)&targetName);
                ovr_ovc15_usesStshRealloc((char *)CONCAT22(uVar10,pcVar8));
                pcVar8 = ovr_stsprintf((char *)&msg,unaff_SS,
                                       (char *)"%s infects %s with blast spore disease.");
                ovr_uiNotify(pcVar8,uVar10);
                uVar9 = ovr_audio_panFromX(uStack_8);
                ovr_play_sfxU(5,0,uVar9);
                peVar3 = ((agnt_t *)uStack_8)->entity;
                puVar1 = (uint *)((int)&(((entity_t *)peVar3)->base).frames + 1);
                *puVar1 = *puVar1 | 1;
              }
              if (((cStack_3 == '\0') &&
                  ((((agntG_t *)((agnt_t *)agnt)->gdata)->flags2 & 0x400) != 0)) &&
                 (uVar9 = ovr_randBelow((uint)(((entity_t *)((agnt_t *)agnt)->entity)->base).
                                              animFrame), (uVar9 & 0xff) == 0)) {
                uVar5 = ovr_ovc27_usesPlay_sfxU((uint16_t)(agnt_t *)agnt,(*(uint16_t *)((uint8_t *)&(agnt) + 2)),uStack_8,0x1);
                if ((char)uVar5 == '\0') {
                  ovr_agnt_statusText(uStack_8,(char *)&actorName);
                  pcVar8 = ovr_agnt_statusText(agnt,(char *)&targetName);
                  ovr_ovc15_usesStshRealloc((char *)CONCAT22(uVar10,pcVar8));
                  pcVar8 = ovr_stsprintf((char *)&msg,unaff_SS,
                                         (char *)"%s drains all energy from %s.");
                  ovr_uiNotify(pcVar8,uVar10);
                }
                else {
                  ovr_agnt_statusText(uStack_8,(char *)&actorName);
                  pcVar8 = ovr_agnt_statusText(agnt,(char *)&targetName);
                  ovr_ovc15_usesStshRealloc((char *)CONCAT22(uVar10,pcVar8));
                  pcVar8 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s drains a level from %s.")
                  ;
                  ovr_uiNotify(pcVar8,uVar10);
                }
              }
              if (((cStack_3 == '\0') &&
                  ((((agntG_t *)((agnt_t *)agnt)->gdata)->flags2 & 0x800) != 0)) &&
                 (uVar9 = ovr_randBelow((uint)(((entity_t *)((agnt_t *)agnt)->entity)->base).
                                              animFrame), (uVar9 & 0xff) == 0)) {
                uVar5 = ovr_ovc27_usesPlay_sfxU((uint16_t)(agnt_t *)agnt,(*(uint16_t *)((uint8_t *)&(agnt) + 2)),uStack_8,0x2);
                if ((char)uVar5 == '\0') {
                  ovr_agnt_statusText(uStack_8,(char *)&actorName);
                  pcVar8 = ovr_agnt_statusText(agnt,(char *)&targetName);
                  ovr_ovc15_usesStshRealloc((char *)CONCAT22(uVar10,pcVar8));
                  pcVar8 = ovr_stsprintf((char *)&msg,unaff_SS,
                                         (char *)"%s drains all energy from %s.");
                  ovr_uiNotify(pcVar8,uVar10);
                }
                else {
                  ovr_agnt_statusText(uStack_8,(char *)&actorName);
                  pcVar8 = ovr_agnt_statusText(agnt,(char *)&targetName);
                  ovr_ovc15_usesStshRealloc((char *)CONCAT22(uVar10,pcVar8));
                  pcVar8 = ovr_stsprintf((char *)&msg,unaff_SS,
                                         (char *)"%s drains two levels from %s.");
                  ovr_uiNotify(pcVar8,uVar10);
                }
              }
            }
            else {
              pcVar8 = ovr_agnt_statusText(uStack_8,(char *)&targetName);
              ovr_ovc15_usesStshRealloc
                        ((char *)CONCAT13((char)(uVar10 >> 8),CONCAT12((char)uVar10,pcVar8)));
              pcVar8 = ovr_stsprintf((char *)&msg,unaff_SS,
                                     (char *)"%s takes no damage from missile attacks.");
              ovr_uiNotify(pcVar8,uVar10);
              uVar10 = ovr_audio_panFromX(uStack_8);
              ovr_play_sfxU(0x16,0,uVar10);
            }
          }
          else {
            pcVar8 = ovr_agnt_statusText(uStack_8,(char *)&targetName);
            ovr_ovc15_usesStshRealloc
                      ((char *)CONCAT13((char)(uVar10 >> 8),CONCAT12((char)uVar10,pcVar8)));
            pcVar8 = ovr_stsprintf((char *)&msg,unaff_SS,
                                   (char *)"%s takes no damage from less than +2 weapons.");
            ovr_uiNotify(pcVar8,uVar10);
            uVar10 = ovr_audio_panFromX(uStack_8);
            ovr_play_sfxU(0x16,0,uVar10);
          }
        }
        else {
          pcVar8 = ovr_agnt_statusText(uStack_8,(char *)&targetName);
          ovr_ovc15_usesStshRealloc
                    ((char *)CONCAT13((char)(uVar10 >> 8),CONCAT12((char)uVar10,pcVar8)));
          pcVar8 = ovr_stsprintf((char *)&msg,unaff_SS,
                                 (char *)"%s takes no damage from non-magical weapons.");
          ovr_uiNotify(pcVar8,uVar10);
          uVar10 = ovr_audio_panFromX(uStack_8);
          ovr_play_sfxU(0x16,0,uVar10);
        }
      }
      else {
        ovr_ovc27_textTakesHalfDamage3(agnt,targetIndex);
      }
    }
    else {
      ovc41_textOnlyPlaceSingle(agnt,targetIndex);
    }
  }
  return;
}



/* 6a8f:297d */

/* Applies the special attack to an agent and then runs the follow-up tick. */

void __cdecl16far ovc41_resolveSpecialAttack(agnt_t *agnt,uint16_t param)

{
  ovc41_specialAttack(agnt,param);
  ovr_agnt_advanceAnimFrame(agnt);
  return;
}



/* 6a8f:29a0 */

/* [R6] touches AgntCount */

void __cdecl16far ovc41_usesAgntCount3(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    if (*(char *)(iVar1 * 0x34 + 0x2f) != '\0') {
      ovc41_settleAgentCombat((agnt_t *)0x0,(agnt_t *)CONCAT22(0x1726,(agnt_t *)(iVar1 * 0x34)));
    }
  }
  return;
}



/* 6a8f:29ea */

/* Returns the growth requirement for an agent's level, from the growth table or its type record. */

int __cdecl16far ovc41_growthForLevel(agnt_t *agnt)

{
  int iVar1;
  undefined2 uVar2;
  uint16_t unaff_SS;
  far_t dst;
  uint8_t growthMap;
  byte bStack_4;
  byte bStack_3;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&growthMap;
  F_SCOPY(far_from_u32((uint32_t)(0x24106e48)),dst);
  uVar2 = (undefined2)((ulong)agnt >> 0x10);
  bStack_3 = ((agnt_t *)agnt)->gindex;
  if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bStack_3 * 0x95) == -1) {
    iVar1 = *(int *)((int)&worldMenuLabels[9].seg + 1 + (uint)bStack_3 * 0x95);
  }
  else {
    bStack_4 = ((agnt_t *)agnt)->level;
    if (bStack_4 < 0x16) {
      iVar1 = *(int *)(&growthMap + (uint)bStack_4 * 2);
    }
    else {
      iVar1 = (uint)bStack_4 * 0xfa + -0xabe;
    }
  }
  return iVar1;
}


