/*
 * ovc41_main.c - recovered from STRONG.EXE
 * memory block: OVC41_main.c
 * range: 6a8f:0000 - 6a8f:2eaf
 * functions: 37
 */
#include "recovered.h"


/* 6a8f:0000 */

/* Returns "" for a count of 1 and "s" otherwise (plural suffix for formatted strings). */

undefined2 __cdecl16far ovc41_pluralSuffix(int count,...)

{
  undefined2 uVar1;
  int in_stack_00000004;
  
  if (in_stack_00000004 == 1) {
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

void __cdecl16far ovc41_compute3(uint32_t view,...)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int in_stack_00000004;
  byte bStack_7;
  
  bStack_7 = *(byte *)((int)&worldMenuLabels[9].ofs + 1 +
                      (uint)*(byte *)(in_stack_00000004 + 0xd) * 0x95);
  if (bStack_7 == 0xff) {
    bStack_7 = 0;
  }
  piVar3 = (int *)((uint)bStack_7 * 0x94 + (uint)*(byte *)(in_stack_00000004 + 0xf) * 4);
  if (*piVar3 == 0 && piVar3[1] == 0) {
    iVar4 = (uint)bStack_7 * 0x94 + (uint)*(byte *)(in_stack_00000004 + 0xf) * 4;
    uVar1 = *(uint *)(iVar4 + -4);
    *(int *)(in_stack_00000004 + 0x12) = *(int *)(iVar4 + -2) + (uint)(0xfffe < uVar1);
    *(int *)(in_stack_00000004 + 0x10) = uVar1 + 1;
  }
  else {
    puVar5 = (uint *)((uint)bStack_7 * 0x94 + (uint)*(byte *)(in_stack_00000004 + 0xf) * 4);
    uVar1 = puVar5[1];
    if ((uVar1 <= *(uint *)(in_stack_00000004 + 0x12)) &&
       ((uVar1 != *(uint *)(in_stack_00000004 + 0x12) ||
        (*puVar5 <= *(uint *)(in_stack_00000004 + 0x10))))) {
      puVar5 = (uint *)((uint)bStack_7 * 0x94 + (uint)*(byte *)(in_stack_00000004 + 0xf) * 4);
      uVar1 = *puVar5;
      *(int *)(in_stack_00000004 + 0x12) = puVar5[1] + (uint)(0xfffe < uVar1);
      *(int *)(in_stack_00000004 + 0x10) = uVar1 + 1;
      *(char *)(in_stack_00000004 + 0xf) = *(char *)(in_stack_00000004 + 0xf) + '\x01';
      cVar2 = ovr_ovc15_textView(in_stack_00000004,(undefined2)view);
      *(char *)(in_stack_00000004 + 0x31) = *(char *)(in_stack_00000004 + 0x31) + cVar2;
      *(char *)(in_stack_00000004 + 0x32) = *(char *)(in_stack_00000004 + 0x32) + cVar2;
    }
  }
  return;
}



/* 6a8f:016b */

/* [R7] body shape: compute */

void __cdecl16far ovc41_compute4(agnt_t *agnt,byte flag,int pad,agnt_t *other,...)

{
  uint *puVar1;
  uint uVar2;
  long *plVar3;
  uint uVar4;
  int iVar5;
  long *unaff_BP;
  long in_stack_00000000;
  undefined2 in_stack_00000004;
  undefined3 in_stack_0000fffa;
  agnt_t *agnt_00;
  undefined2 uVar6;
  
  if ((*(uint8_t *)((uint8_t *)&(agnt) + 2)) != '\0') {
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)*(byte *)(flag + 0xd) * 0x95) != -1) {
      agnt_00 = (agnt_t *)
                CONCAT22((int)(CONCAT13(*(byte *)(flag + 0xd),in_stack_0000fffa) >> 0x10),
                         (agnt_t *)agnt);
      ovc41_growthForLevel(agnt_00,in_stack_00000004);
      uVar6 = (undefined2)((ulong)agnt_00 >> 0x10);
      iVar5 = 0;
      plVar3 = LXMUL_at_(unaff_BP,in_stack_00000000,CONCAT22((agnt_t *)agnt,in_stack_00000004));
      uVar4 = ovr_ovc15_textError(flag,pad,plVar3,iVar5);
      puVar1 = (uint *)(flag + 0x10);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + uVar4;
      *(int *)(flag + 0x12) = *(int *)(flag + 0x12) + iVar5 + (uint)CARRY2(uVar2,uVar4);
      ovc41_compute3(CONCAT22(uVar6,pad),flag);
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

void __cdecl16far OVC41_6a8f_01e7_entry(agnt_t *agnt,...)

{
  agnt_t *in_stack_00000004;
  
  if ((in_stack_00000004->flags & 0xae4) == 0) {
    ovc41_markAgentDead((agnt_t *)CONCAT22((agnt_t *)agnt,in_stack_00000004));
  }
  return;
}



/* 6a8f:0246 */

/* Increments the animFrame byte of the entity the agent belongs to. */

void __cdecl16far ovc41_advanceAnimFrame(agnt_t *agnt,...)

{
  char *pcVar1;
  int in_stack_00000004;
  
  pcVar1 = (char *)((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0xe);
  *pcVar1 = *pcVar1 + '\x01';
  return;
}



/* 6a8f:0256 */

/* Removes an agent record from Agnts, fixes the +0xc references and memmoves the tail down. */

void __cdecl16far ovc41_removeAgent(uint agntIndex,int notify,...)

{
  char *pcVar1;
  agnt_t *paVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  uint uVar7;
  uint unaff_DI;
  uint in_stack_00000004;
  byte dir;
  undefined4 uStack_8;
  
  uVar5 = in_stack_00000004;
  paVar2 = (agnt_t *)*(undefined2 *)(in_stack_00000004 * 0x34 + 0x19);
  puVar3 = (uint *)*(int *)(in_stack_00000004 * 0x34 + 0x17);
  uStack_8 = (uint *)CONCAT22(paVar2,puVar3);
  iVar4 = *(int *)(in_stack_00000004 * 0x34 + 0x1b);
  ovr_agnt_usesAgntCount4(unaff_DI,in_stack_00000004 + 1);
  dir = (byte)unaff_DI;
  bVar6 = false;
  for (uVar7 = 0; (int)uVar7 < (int)(uint)AgntCount; uVar7 = uVar7 + 1) {
    if ((uVar7 != uVar5) && (*(int *)(uVar7 * 0x34 + 0x1b) == iVar4)) {
      bVar6 = true;
    }
    if (*(char *)(uVar7 * 0x34 + 0xc) != -1) {
      if ((int)uVar5 < (int)(uint)*(byte *)(uVar7 * 0x34 + 0xc)) {
        pcVar1 = (char *)(uVar7 * 0x34 + 0xc);
        *pcVar1 = *pcVar1 + -1;
      }
      else if (*(byte *)(uVar7 * 0x34 + 0xc) == uVar5) {
        *(undefined1 *)(uVar7 * 0x34 + 0xc) = 0xff;
      }
    }
  }
  if ((int)(uVar5 + 1) < (int)(uint)AgntCount) {
    _fmemmove((char *)CONCAT22(0x1726,(char *)(uVar5 * 0x34)),
              (char *)CONCAT22(0x1726,(char *)(uVar5 * 0x34 + 0x34)),
              ((AgntCount - uVar5) + -1) * 0x34);
  }
  AgntCount = AgntCount - 1;
  if ((((agntIndex != 0) && (!bVar6)) && (puVar3[1] == GfxRndSeed2)) &&
     ((GfxRndSeed - 2U <= *uStack_8 && (GfxRndSeed - 2U <= *uStack_8)))) {
    puVar3[4] = puVar3[2];
    uVar5 = puVar3[3];
    puVar3[5] = uVar5;
    ovr_attact_usesRandBelow
              ((agnt_t *)CONCAT22(CONCAT11((char)(uVar5 >> 8),(char)puVar3[6]),paVar2),dir,puVar3);
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

void __cdecl16far ovc41_unitStatusText(byte menuIndex,...)

{
  undefined4 uVar1;
  far_t remainderOut;
  far_t partOut;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  undefined2 uVar5;
  char *pcVar6;
  uint uVar7;
  uint16_t unaff_DI;
  int count;
  char *unaff_SS;
  byte in_stack_00000004;
  far_t pctOut;
  uint uVar8;
  undefined2 uVar9;
  uint8_t msg;
  uint8_t part;
  uint8_t remainder;
  uint8_t pct;
  
  uVar5 = 0x2410;
  if (((uint8_t *)MenuItemEnabled)[in_stack_00000004] != 0xff) {
    count = 0;
    for (uVar7 = 0; uVar7 < AgntCount; uVar7 = uVar7 + 1) {
      uVar5 = 0x1726;
      uVar1 = *(undefined4 *)(uVar7 * 0x34 + 0x17);
      if (((uint8_t *)MenuItemEnabled)[in_stack_00000004] == *(uint8_t *)((int)uVar1 + 0x1a)) {
        count = count + 1;
      }
    }
    pctOut.seg = (uint16_t)&remainder;
    pctOut.ofs = (uint16_t)unaff_SS;
    remainderOut.seg = (uint16_t)&part;
    remainderOut.ofs = (uint16_t)unaff_SS;
    partOut.seg = unaff_DI;
    partOut.ofs = (uint16_t)unaff_SS;
    ovr_attact_compute2((uint16_t)&pct,pctOut,remainderOut,partOut,
                        CONCAT11((char)((uint)&pct >> 8),in_stack_00000004));
    uVar9 = 0xa000;
    uVar7 = (uint)pct;
    uVar2 = (uint)remainder;
    uVar8 = (uint)part;
    pcVar3 = ovc41_isAre(count);
    piVar4 = (int *)((uint)((uint8_t *)MenuItemEnabled)[in_stack_00000004] * 4);
    pcVar6 = (char *)"halfling castle" + 0xc;
    pcVar3 = (char *)ovc41_pluralSuffix(*piVar4,count,piVar4[1],pcVar3,uVar5,uVar8,uVar2,uVar7);
    pcVar3 = ovr_stsprintf((char *)CONCAT22(0x6e86,unaff_SS),
                           (char *)CONCAT22(count,(char *)"puppetmaker" + 3),pcVar3,&msg,pcVar6);
    ovr_drawTextAt((char *)CONCAT22(uVar9,pcVar6),unaff_DI,pcVar3);
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

uint __cdecl16far ovc41_settleAgentCombat(agnt_t *a,agnt_t *b,...)

{
  uint in_AX;
  uint uVar1;
  undefined2 uVar2;
  byte bVar3;
  agnt_t *unaff_BP;
  undefined2 in_stack_00000000;
  int in_stack_00000004;
  byte flag;
  undefined1 uVar4;
  
  bVar3 = (byte)unaff_BP;
  uVar4 = (undefined1)((uint)unaff_BP >> 8);
  if (((*(uint16_t *)((uint8_t *)&(a) + 2)))->combatState == 0x2) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    if ((in_stack_00000004 != 0 || (agnt_t *)a != (agnt_t *)0x0) &&
       (*(char *)*(undefined4 *)(in_stack_00000004 + 0x1d) == *(char *)(in_stack_00000004 + 0x2f)))
    {
      flag = (byte)*(undefined2 *)(in_stack_00000004 + 0x17);
      ovc41_compute4((agnt_t *)CONCAT22(1,(agnt_t *)*(undefined2 *)((int)&((*(uint16_t *)((uint8_t *)&(a) + 2)))->entity + 2)),
                     flag,*(int *)(in_stack_00000004 + 0x19),
                     (agnt_t *)CONCAT22(in_stack_00000000,unaff_BP),
                     *(undefined2 *)&((*(uint16_t *)((uint8_t *)&(a) + 2)))->entity,flag,bVar3);
    }
    if (((((((entity_t *)((*(uint16_t *)((uint8_t *)&(a) + 2)))->entity)->base).animFrame == 0x0) ||
         ((uint)(((entity_t *)((*(uint16_t *)((uint8_t *)&(a) + 2)))->entity)->base).animFrame % 0x10 == 1)) ||
        ((((*(uint16_t *)((uint8_t *)&(a) + 2)))->flags & 0xae4) != 0)) || ((((agntG_t *)((*(uint16_t *)((uint8_t *)&(a) + 2)))->gdata)->flags2 & 4) != 0)) {
      ((*(uint16_t *)((uint8_t *)&(a) + 2)))->strength = 0x0;
      ((*(uint16_t *)((uint8_t *)&(a) + 2)))->timer = 0xa;
      ((*(uint16_t *)((uint8_t *)&(a) + 2)))->combatState = 0x2;
      ((*(uint16_t *)((uint8_t *)&(a) + 2)))->targetY = 0;
    }
    else {
      ((*(uint16_t *)((uint8_t *)&(a) + 2)))->strength = ((agntG_t *)((*(uint16_t *)((uint8_t *)&(a) + 2)))->gdata)->strength;
      ((*(uint16_t *)((uint8_t *)&(a) + 2)))->timer = 0x6;
      ((*(uint16_t *)((uint8_t *)&(a) + 2)))->combatState = 0x1;
      ((*(uint16_t *)((uint8_t *)&(a) + 2)))->targetY = 0;
    }
    ovr_agnt_usesAnimFrame
              ((agnt_t *)CONCAT13(uVar4,CONCAT12(bVar3,(agnt_t *)b)),(char)((ulong)a >> 0x10));
    uVar2 = CONCAT11((char)(((*(uint16_t *)((uint8_t *)&(a) + 2)))->owner * 0x37 >> 8),
                     *(undefined1 *)((int)&((entity_t *)Entities)[((*(uint16_t *)((uint8_t *)&(a) + 2)))->owner].base.entity + 3)
                    );
    ovr_ovc25_attackingNotice(bVar3,uVar2);
    bVar3 = (byte)((uint)uVar2 >> 8);
    if ((((*(uint16_t *)((uint8_t *)&(a) + 2)))->flags & 0xae4) == 0) {
      ovc41_markAgentDead((agnt_t *)CONCAT22((agnt_t *)b,(*(uint16_t *)((uint8_t *)&(a) + 2))));
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
  undefined2 unaff_SI;
  int iVar2;
  agnt_t *paVar3;
  
  if (AgntFlag1) {
    for (iVar2 = 0; iVar2 < (int)(uint)AgntCount; iVar2 = iVar2 + 1) {
      if ((*(uint *)(iVar2 * 0x34 + 0x2b) & 0x800) == 0) {
        paVar3 = (agnt_t *)CONCAT22(unaff_SI,(agnt_t *)((int)&AgntAnms[0x75].halfWidth + 1));
        OVC41_6a8f_01e7_entry(paVar3,iVar2 * 0x34);
        puVar1 = (uint *)(iVar2 * 0x34 + 0x2b);
        *puVar1 = *puVar1 | 0x800;
        paVar3 = (agnt_t *)
                 CONCAT22((int)((ulong)paVar3 >> 0x10),
                          (agnt_t *)((int)&AgntAnms[0x75].halfWidth + 1));
        iVar2 = ovr_audio_panFromX(paVar3,iVar2 * 0x34);
        ovr_play_sfxU(0,iVar2,(uint16_t)((ulong)paVar3 >> 0x10),0x1b);
        ovr_attact_usesEntityCount();
        return;
      }
    }
  }
  return;
}



/* 6a8f:0807 */

/* Rolls a paralysis check against every agent within 50 pixels when the source type allows it. */

void __cdecl16far ovc41_paralyzeNearbyAgents(int agntIndex,...)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint unaff_DI;
  int in_stack_00000004;
  undefined4 uStack_6;
  
  piVar2 = (int *)(in_stack_00000004 * 0x34);
  uStack_6 = (int *)CONCAT22(0x1726,piVar2);
  if ((*(uint *)((int)*(undefined4 *)((int)piVar2 + 0x1d) + 0x3e) & 4) != 0) {
    for (iVar6 = 0; iVar6 < (int)(uint)AgntCount; iVar6 = iVar6 + 1) {
      if ((iVar6 != in_stack_00000004) &&
         (uVar3 = *uStack_6 - *(int *)(iVar6 * 0x34), uVar5 = (int)uVar3 >> 0xf,
         (int)((uVar3 ^ uVar5) - uVar5) < 0x32)) {
        bVar1 = ovr_manage_rollDice('\x06',(char)unaff_DI,6,6);
        uVar3 = (uint)bVar1;
        iVar4 = ovr_ovc27_rollToHitEntity();
        if ((char)iVar4 != '\0') {
          uVar3 = (int)uVar3 >> 1;
        }
        ovc41_textParalyzed((agnt_t *)
                            CONCAT22(iVar6 * 0x34,(agnt_t *)((int)&AgntAnms[0x75].halfWidth + 1)),
                            (agnt_t *)CONCAT22(uVar3,(agnt_t *)((int)&AgntAnms[0x75].halfWidth + 1))
                            ,unaff_DI,piVar2);
      }
    }
  }
  return;
}



/* 6a8f:08c2 */

/* [R6] touches xOfs */

void __cdecl16far ovc41_usesXOfs(int agntIndex,...)

{
  int iVar1;
  uint uVar2;
  uint16_t unaff_SS;
  int in_stack_00000004;
  far_t dst;
  int iStack_c;
  uint8_t xOfs;
  
  iVar1 = in_stack_00000004;
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&xOfs;
  F_SCOPY(far_from_u32((uint32_t)(0x24106e00)),dst);
  uVar2 = (uint)*(byte *)(iVar1 * 0x34 + 0xc);
  iStack_c = *(int *)(iVar1 * 0x34 + 6);
  if (2 < iStack_c) {
    iStack_c = 3;
  }
  if (*(char *)(iVar1 * 0x34 + 0xf) == '\0') {
    *(int *)(uVar2 * 0x34) = *(int *)(iVar1 * 0x34) + *(int *)(&xOfs + iStack_c * 2);
  }
  else {
    *(int *)(uVar2 * 0x34) = *(int *)(iVar1 * 0x34) - *(int *)(&xOfs + iStack_c * 2);
  }
  if (0xd2 < *(int *)(uVar2 * 0x34)) {
    *(undefined2 *)(uVar2 * 0x34) = 0xd2;
  }
  if (*(int *)(uVar2 * 0x34) < 0) {
    *(undefined2 *)(uVar2 * 0x34) = 0;
  }
  *(undefined2 *)(uVar2 * 0x34 + 2) = *(undefined2 *)(iVar1 * 0x34 + 2);
  *(undefined1 *)(uVar2 * 0x34 + 5) = 0;
  *(undefined1 *)(uVar2 * 0x34 + 4) = 0;
  return;
}



/* 6a8f:0a45 */

/* [R7] body shape: compute */

undefined2 __cdecl16far ovc41_compute6(byte rank,uint8_t level)

{
  byte bVar1;
  undefined2 in_AX;
  undefined2 uVar2;
  undefined1 uVar3;
  byte in_stack_0000fffc;
  
  bVar1 = ovr_agnt_compute14(in_stack_0000fffc,CONCAT11((char)((uint)in_AX >> 8),level));
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
  undefined2 in_AX;
  byte in_stack_0000fffc;
  
  bVar1 = ovr_agnt_compute14(in_stack_0000fffc,CONCAT11((char)((uint)in_AX >> 8),level));
  if (bVar1 + 1 < rank + 0xf) {
    if (bVar1 + 1 < rank + 10) {
      ovr_manage_rollDice('\x06',in_stack_0000fffc,2);
    }
    else {
      ovr_manage_rollDice('\x06',in_stack_0000fffc,3);
    }
  }
  else {
    ovr_manage_rollDice('\x06',in_stack_0000fffc,4);
  }
  return;
}



/* 6a8f:0b0a */

/* [R7] body shape: compute */

int __cdecl16far ovc41_compute8(byte rank,uint8_t level)

{
  byte bVar1;
  undefined2 in_AX;
  byte bVar3;
  int iVar2;
  byte in_stack_0000fffc;
  
  bVar1 = ovr_agnt_compute14(in_stack_0000fffc,CONCAT11((char)((uint)in_AX >> 8),level));
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
  uint8_t *puVar6;
  undefined1 uVar8;
  int iVar7;
  agnt_t *paVar9;
  undefined2 unaff_DI;
  uint uVar10;
  agnt_t *paVar11;
  char *unaff_SS;
  undefined1 uVar12;
  char cVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  char sides;
  undefined1 uVar17;
  uint8_t text;
  uint8_t msg;
  int iStack_a;
  undefined2 uStack_8;
  byte bStack_6;
  char cStack_5;
  char cStack_4;
  char cStack_3;
  
  sides = (char)unaff_DI;
  uVar17 = (undefined1)((uint)unaff_DI >> 8);
  paVar11 = (agnt_t *)((ulong)agnt >> 0x10);
  paVar9 = (agnt_t *)agnt;
  bVar3 = (byte)((uint)in_AX >> 8);
  if ((paVar9->flags & 2) == 0) {
    iVar7 = (uint)bVar3 << 8;
  }
  else {
    paVar9->health = 0x0;
    paVar9->flags = paVar9->flags & 0xfffd;
    if (paVar9->target == 0xff) {
      iVar7 = (uint)bVar3 << 8;
    }
    else {
      iStack_a = (uint)paVar9->target * 0x34;
      uStack_8 = 0x1726;
      bStack_6 = *(byte *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x42);
      if (bStack_6 == 0) {
        iVar7 = 0;
      }
      else {
        bVar3 = ovr_manage_rollDice('\x06',sides,2);
        uVar8 = extraout_AH;
        uVar4 = ovc41_compute6(*(byte *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x42),
                               (((entity_t *)paVar9->entity)->base).level);
        uVar12 = SUB41(agnt,0);
        if (bVar3 < (byte)uVar4) {
          uVar15 = (undefined1)GSavedBlitSeg;
          uVar16 = (undefined1)((uint)GSavedBlitSeg >> 8);
          pcVar5 = ovr_agnt_statusText((agnt_t *)
                                       CONCAT13((char)((uint)&text >> 8),
                                                CONCAT12((char)&text,paVar11)),paVar9);
          puVar6 = ovr_ovc15_usesStshRealloc
                             ((char *)CONCAT13(uVar16,CONCAT12(uVar15,CONCAT11(uVar8,bVar3))),
                              (char)pcVar5);
          pcVar5 = ovr_stsprintf((char *)CONCAT22(0x6ed6,unaff_SS),
                                 (char *)CONCAT13((char)((uint)puVar6 >> 8),
                                                  CONCAT12((char)puVar6,0x2410)),
                                 (char *)CONCAT11(uVar8,bVar3),&msg,(char)puVar6,bVar3);
          ovr_uiNotify((char *)CONCAT13(uVar16,CONCAT12(uVar15,CONCAT11(uVar8,bVar3))),(char)pcVar5)
          ;
          uVar8 = (undefined1)((uint)pcVar5 >> 8);
          ovr_agnt_usesAnimFrame((agnt_t *)CONCAT13(uVar17,CONCAT12(sides,paVar11)),uVar12);
          iVar7 = CONCAT11(uVar8,1);
        }
        else {
          rank = *(byte *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x42);
          uVar10 = (uint)rank;
          ovc41_rollStatDice(rank,(((entity_t *)paVar9->entity)->base).level);
          uVar10 = uVar10 & 0xff;
          iVar7 = ovc41_compute8(*(byte *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x42),
                                 (((entity_t *)paVar9->entity)->base).level);
          cStack_4 = (char)iVar7;
          cStack_5 = '\0';
          iVar7 = 0;
          while ((iVar7 < (int)(uint)AgntCount && (uVar10 != 0))) {
            uVar2 = *(undefined4 *)(iVar7 * 0x34 + 0x1d);
            if (((*(char *)((int)uVar2 + 0x42) != '\0') &&
                ((((*(uint8_t *)(iVar7 * 0x34 + 0x2f) != paVar9->faction &&
                   ((*(uint *)(iVar7 * 0x34 + 0x2b) & 4) == 0)) &&
                  (*(char *)(iVar7 * 0x34 + 0x24) == '\0')) &&
                 ((cStack_5 == '\0' ||
                  (uVar2 = *(undefined4 *)(iVar7 * 0x34 + 0x17),
                  (int)(uint)*(byte *)((int)uVar2 + 0xf) <= (int)uVar10)))))) &&
               (uVar2 = *(undefined4 *)(iVar7 * 0x34 + 0x1d),
               *(byte *)((int)uVar2 + 0x42) <= bStack_6)) {
              if ((*(uint *)(iVar7 * 0x34 + 0x2b) & 0xae4) == 0) {
                uVar2 = *(undefined4 *)(iVar7 * 0x34 + 0x17);
                cStack_3 = *(char *)((int)uVar2 + 0xe);
              }
              else {
                cStack_3 = '\x01';
              }
              while ((cStack_3 != '\0' && (uVar10 != 0))) {
                if (cStack_4 == '\0') {
                  OVC41_6a8f_01e7_entry
                            ((agnt_t *)CONCAT13(uVar17,CONCAT12(sides,0x1726)),(char)(iVar7 * 0x34))
                  ;
                  *(undefined1 *)(iVar7 * 0x34 + 4) = 0;
                  *(undefined1 *)(iVar7 * 0x34 + 5) = 0;
                  puVar1 = (uint *)(iVar7 * 0x34 + 0x2b);
                  *puVar1 = *puVar1 | 4;
                  *(undefined1 *)(iVar7 * 0x34 + 0x24) = 1;
                  *(undefined2 *)(iVar7 * 0x34 + 6) = 0;
                  *(undefined1 *)(iVar7 * 0x34 + 0x23) = 5;
                  ovr_agnt_usesAnimFrame
                            ((agnt_t *)CONCAT13(uVar17,CONCAT12(sides,0x1726)),(char)(iVar7 * 0x34))
                  ;
                }
                else {
                  ovc41_settleAgentCombat
                            ((agnt_t *)
                             CONCAT13((char)((uint)(iVar7 * 0x34) >> 8),
                                      CONCAT12((char)(iVar7 * 0x34),paVar11)),
                             (agnt_t *)CONCAT13(uVar17,CONCAT12(sides,0x1726)),paVar9,0x26);
                }
                cStack_5 = cStack_5 + '\x01';
                uVar2 = *(undefined4 *)(iVar7 * 0x34 + 0x17);
                if ((int)uVar10 < (int)(uint)*(byte *)((int)uVar2 + 0xf)) {
                  uVar10 = 0;
                }
                else {
                  uVar2 = *(undefined4 *)(iVar7 * 0x34 + 0x17);
                  uVar10 = uVar10 - *(byte *)((int)uVar2 + 0xf);
                }
                cStack_3 = cStack_3 + -1;
              }
            }
            bVar3 = 0x26;
            uVar8 = 0x17;
            iVar7 = iVar7 + 1;
          }
          uVar15 = (undefined1)GSavedBlitSeg;
          uVar16 = (undefined1)((uint)GSavedBlitSeg >> 8);
          if (cStack_5 == '\0') {
            pcVar5 = ovr_agnt_statusText((agnt_t *)
                                         CONCAT13((char)((uint)&text >> 8),
                                                  CONCAT12((char)&text,paVar11)),paVar9);
            puVar6 = ovr_ovc15_usesStshRealloc
                               ((char *)CONCAT13(uVar16,CONCAT12(uVar15,CONCAT11(uVar8,bVar3))),
                                (char)pcVar5);
            pcVar5 = ovr_stsprintf((char *)CONCAT22(0x6ee8,unaff_SS),
                                   (char *)CONCAT13((char)((uint)puVar6 >> 8),
                                                    CONCAT12((char)puVar6,0x2410)),
                                   (char *)CONCAT11(uVar8,bVar3),&msg,(char)puVar6,bVar3);
            ovr_uiNotify((char *)CONCAT13(uVar16,CONCAT12(uVar15,CONCAT11(uVar8,bVar3))),
                         (char)pcVar5);
            uVar8 = (undefined1)((uint)pcVar5 >> 8);
          }
          else {
            if (cStack_4 == '\0') {
              uVar14 = 0;
              cVar13 = cStack_5;
              pcVar5 = ovr_agnt_statusText((agnt_t *)CONCAT22(&text,paVar11),paVar9);
              puVar6 = ovr_ovc15_usesStshRealloc
                                 ((char *)CONCAT13(uVar14,CONCAT12(cVar13,CONCAT11(uVar8,bVar3))),
                                  pcVar5);
              pcVar5 = ovr_stsprintf((char *)CONCAT22(0x6f0f,unaff_SS),
                                     (char *)CONCAT22(puVar6,(char *)"puppetmaker" + 3),
                                     (char *)CONCAT11(uVar8,bVar3),&msg,bVar3);
              ovr_uiNotify((char *)CONCAT13(uVar16,CONCAT12(uVar15,CONCAT11(uVar8,bVar3))),
                           (char)pcVar5);
            }
            else {
              uVar14 = 0;
              cVar13 = cStack_5;
              pcVar5 = ovr_agnt_statusText((agnt_t *)CONCAT22(&text,paVar11),paVar9);
              puVar6 = ovr_ovc15_usesStshRealloc
                                 ((char *)CONCAT13(uVar14,CONCAT12(cVar13,CONCAT11(uVar8,bVar3))),
                                  pcVar5);
              pcVar5 = ovr_stsprintf((char *)CONCAT22(0x6ef8,unaff_SS),
                                     (char *)CONCAT22(puVar6,(char *)"puppetmaker" + 3),
                                     (char *)CONCAT11(uVar8,bVar3),&msg,bVar3);
              ovr_uiNotify((char *)CONCAT13(uVar16,CONCAT12(uVar15,CONCAT11(uVar8,bVar3))),
                           (char)pcVar5);
            }
            iVar7 = ovr_audio_panFromX((agnt_t *)CONCAT13(uVar17,CONCAT12(sides,paVar11)),uVar12);
            ovr_play_sfxU(0,iVar7,0x3b,(char)iVar7);
            uVar8 = (undefined1)((uint)iVar7 >> 8);
          }
          ovr_agnt_usesAnimFrame((agnt_t *)CONCAT13(uVar17,CONCAT12(sides,paVar11)),uVar12);
          iVar7 = CONCAT11(uVar8,1);
        }
      }
    }
  }
  return iVar7;
}



/* 6a8f:0fc1 */

/* Formats the "Building %d %s." notice. */

void __cdecl16far ovc41_buildingNotice(char delta,...)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined2 unaff_SI;
  undefined2 uVar4;
  char *unaff_SS;
  char in_stack_00000004;
  uint8_t text;
  byte bStack_3;
  
  iVar1 = ((short (*) [148] [60])GUnitGrid)[-1][GfxRndSeed + 0x93][GfxRndSeed2];
  if (0xf7 < iVar1) {
    uVar4 = (undefined2)((ulong)GUnits >> 0x10);
    bStack_3 = ((unit_t *)GUnits + iVar1)->bldType + in_stack_00000004;
    if (0xf7 < bStack_3) {
      bStack_3 = 0;
    }
    ((unit_t *)GUnits + iVar1)->bldType = bStack_3;
    ovr_constr_flushDirtyRects();
    pcVar3 = (char *)&AgntAnms[0x88].missileDy;
    pcVar2 = ovr_stsprintf((char *)CONCAT22(0x6f23,unaff_SS),
                           (char *)(ulong)CONCAT12(bStack_3,(char *)"puppetmaker" + 3),
                           (char *)*(undefined2 *)((uint)bStack_3 * 0x27 + 0x10e),&text,
                           *(undefined2 *)((uint)bStack_3 * 0x27 + 0x110));
    ovr_say((char *)CONCAT22(unaff_SI,pcVar3),pcVar2);
  }
  return;
}



/* 6a8f:108a */

void __cdecl16far dbgPromoteEnemy(void)

{
  uint8_t *puVar1;
  int iVar2;
  entity_t *peVar3;
  uint unaff_SI;
  uint16_t i;
  undefined2 uVar4;
  char *unaff_SS;
  long lVar5;
  uint uVar6;
  char buf [80];
  
  lVar5 = (ulong)unaff_SI << 0x10;
  for (i = 0; uVar6 = (uint)((ulong)lVar5 >> 0x10), i < EntityCount; i = i + 1) {
    lVar5 = CONCAT22(uVar6,GfxRndSeed - 2U);
    uVar4 = (undefined2)((ulong)Entities >> 0x10);
    peVar3 = (entity_t *)Entities;
    if (((GfxRndSeed - 2U <= ((peVar3 + i)->base).x) &&
        (lVar5 = CONCAT22(uVar6,GfxRndSeed + 1U), ((peVar3 + i)->base).x <= GfxRndSeed + 1U)) &&
       (peVar3[i].base.y == GfxRndSeed2)) {
      puVar1 = &peVar3[i].base.gindex;
      *puVar1 = *puVar1 + 0x1;
      uVar4 = (undefined2)((ulong)Entities >> 0x10);
      if (0x29 < ((entity_t *)Entities)[i].base.gindex) {
        ((entity_t *)Entities)[i].base.gindex = 0x0;
      }
      iVar2 = (uint)((entity_t *)Entities)[i].base.gindex * 0x95;
      ovr_stsprintf((char *)CONCAT22(0x6f33,unaff_SS),
                    (char *)CONCAT22(*(undefined2 *)((int)&AgntGs[0].name + iVar2),
                                     (char *)((int)&BuildingTypes[0xe5].halfWidth + 1)),
                    (char *)*(undefined2 *)((int)&AgntGs[0].name + 2 + iVar2),buf);
      lVar5 = (ulong)uVar6 << 0x10;
      ovr_say();
    }
  }
  TextBlitFlag = 0;
  AgntFlag1 = false;
  ovc41_usesAgnt_clear((char)((ulong)lVar5 >> 0x10),1);
  return;
}



/* 6a8f:11d2 */

/* [R4] calls ovr_agnt_clear */

void __cdecl16far ovc41_usesAgnt_clear(char playSound,...)

{
  bool bVar1;
  int unaff_SI;
  int iVar2;
  char in_stack_00000004;
  
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  if (((in_stack_00000004 != '\0') && (CFG_Sfx != '1')) && (CFG_Sfx != '4')) {
    ovr_play_sfx();
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
    for (iVar2 = 0; iVar2 < 5; iVar2 = iVar2 + 1) {
      ovr_draw_usesBlitLoadRleGfx3(unaff_SI,iVar2);
      ovr_draw_menuRowBar();
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
  uint16_t unaff_SI;
  int iVar1;
  
  ovr_gfxInitRand();
  ovr_resetTextBlitCycle();
  ovr_agnt_clear();
  ovr_attact_usesSquareRecCount2();
  TextBlitDstSeg = 0xa000;
  for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
    ovr_draw_usesBlitLoadRleGfx3(unaff_SI,iVar1);
    ovr_draw_menuRowBar(-0x6000,unaff_SI,iVar1);
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
/* [R4] calls ovr_biosKeyAvail */

char * __cdecl16far ovc41_usesBiosKeyAvail(char backdropIndex,...)

{
  bool bVar1;
  far_t text2;
  far_t text2_00;
  far_t text2_01;
  far_t text2_02;
  char cVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  uint16_t uVar6;
  uint uVar7;
  undefined1 extraout_AH;
  undefined1 uVar8;
  uint uVar9;
  char *pcVar10;
  undefined2 in_DX;
  int iVar11;
  undefined2 *unaff_SI;
  int unaff_DI;
  undefined2 uVar12;
  int iVar13;
  undefined2 unaff_SS;
  far_t text1;
  far_t text1_00;
  far_t text1_01;
  far_t text1_02;
  uint in_stack_00000004;
  undefined1 uStack0007;
  undefined1 uVar14;
  char in_stack_0000000e;
  undefined1 auStack_2cc [214];
  undefined1 auStack_1f6 [100];
  char acStack_192 [274];
  undefined1 auStack_80 [56];
  undefined2 uStack_48;
  undefined2 uStack_46;
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
  uint uStack_1a;
  undefined2 uStack_18;
  undefined1 uStack_17;
  undefined1 auStack_14 [2];
  undefined2 uStack_12;
  undefined2 uStack_10;
  undefined2 uStack_e;
  undefined2 uVar15;
  long lVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  
  uVar8 = (undefined1)(in_stack_00000004 >> 8);
  lVar16 = CONCAT22(FontHandle.ofs,0x6a8f);
  uStack_e = (undefined1 *)0xbead;
  ovr_blitLoadRleGfx();
  if (backdropIndex != '\0') {
    pcVar10 = (char *)(in_stack_00000004 & 0xff);
    pcVar5 = (char *)(in_stack_00000004 & 0xff);
    switch(pcVar5) {
    case (char *)0x0:
      return (char *)((int)(undefined4 *)&_DATA + 1);
    case (char *)0x1:
      ovr_ovc15_usesStExit();
      return pcVar5;
    case (char *)0x2:
      return (char *)CONCAT11(uVar8,(char)in_stack_00000004);
    case (char *)0x3:
      if ((in_stack_00000004 & 2) == 0) {
        ovr_constr_usesBlitRect();
      }
      return pcVar10;
    }
  }
  if (3 < (in_stack_00000004 & 0xff)) {
    if (TextBlitFlag != '\0') {
      ovr_say();
    }
    TextBlitFlag = 0;
    AgntFlag1 = false;
    GGameState = 0x33;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    ovc41_usesAgnt_clear();
    GGameState = 0x35;
    pcVar10 = (char *)"puppetmaker" + 3;
    if (DebugVerbose != false) {
      pcVar10 = (char *)"puppetmaker" + 3;
      printf("%d \r");
    }
    return pcVar10;
  }
  iVar11 = (in_stack_00000004 & 0xff) * 2;
  iVar13 = 0x6000;
  switch((char)in_stack_00000004) {
  case '\x01':
    cVar2 = *(char *)(iVar11 + 0x3f);
    do {
      if (((cVar2 == '\0') && (0xf7 < (int)unaff_SI)) &&
         (((unit_t *)GUnits)[(int)unaff_SI].level < 8)) {
        if ((*(uint *)((uint)(byte)((ulong)lVar16 >> 0x18) * 0x27 + 0x121) & 0x80) == 0) {
          ovc39_loadArchiveEntry(8);
        }
        else {
          ovc39_loadArchiveEntry(9);
        }
        ovc39_lordOrLady();
        uStack_e = auStack_2cc;
        uStack_12 = 0x938f;
        uStack_10 = iVar13;
        pcVar10 = ovr_stsprintf();
        ovr_drawString();
        ovr_stshFree();
        return pcVar10;
      }
      do {
        cVar2 = (char)((ulong)lVar16 >> 8);
        bVar3 = (byte)((ulong)lVar16 >> 0x18);
        if (((cVar2 == '\x01') && ((int)unaff_SI < 0xf8)) &&
           ((*(uint *)((uint)bVar3 * 0x27 + 0x121) & 2) != 0)) {
          ovc39_loadArchiveEntry(10);
          ovc39_lordOrLady();
          uStack_e = auStack_2cc;
          uStack_12 = 0x93f9;
          uStack_10 = iVar13;
          pcVar10 = ovr_stsprintf();
          ovr_drawString();
          ovr_stshFree();
          return pcVar10;
        }
        if (((cVar2 == '\x02') && ((int)unaff_SI < 0xf8)) &&
           ((*(uint *)((uint)bVar3 * 0x27 + 0x121) & 0x20) != 0)) {
          ovc39_loadArchiveEntry(0xb);
          ovc39_lordOrLady();
          uStack_e = auStack_2cc;
          uStack_12 = 0x9463;
          uStack_10 = iVar13;
          pcVar10 = ovr_stsprintf();
          ovr_drawString();
          ovr_stshFree();
          return pcVar10;
        }
        if (cVar2 == '\x03') {
          iVar13 = 0x23f1;
          lVar16 = CONCAT22(0x949c,(int)lVar16);
          uVar9 = ovr_ovc45_compute4();
          if ((char)uVar9 != '\0') {
            ovc39_loadArchiveEntry(0xc);
            ovc39_lordOrLady();
            uStack_e = auStack_2cc;
            uStack_10 = 0x23f1;
            uStack_12 = 0x94c9;
            pcVar10 = ovr_stsprintf();
            ovr_drawString();
            ovr_stshFree();
            return pcVar10;
          }
        }
        iVar11 = iVar13;
        if ((((char)((ulong)lVar16 >> 8) == '\x04') && ((int)unaff_SI < 0xf8)) &&
           ((*(uint *)((uint)(byte)((ulong)lVar16 >> 0x18) * 0x27 + 0x121) & 0x400) != 0)) {
          ovc39_loadArchiveEntry(0xd);
          ovc39_lordOrLady();
          uStack_e = auStack_2cc;
          uStack_12 = 0x9533;
          uStack_10 = iVar13;
          pcVar10 = ovr_stsprintf();
          ovr_drawString();
          ovr_stshFree();
          return pcVar10;
        }
        do {
          unaff_DI = unaff_DI + 1;
          while (1 < unaff_DI) {
            bVar3 = (char)((ulong)lVar16 >> 8) + 1;
            lVar16 = (ulong)bVar3 << 8;
            if (3 < bVar3) {
              uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
              uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
              uVar12 = (undefined2)((ulong)uVar18 >> 0x10);
              iVar13 = (int)uVar18;
              if (*(uint *)((int)uVar17 + 0x4f) <
                  (uint)(*(int *)(iVar13 + 0x4d) * 2 + *(int *)(iVar13 + 0x4d)) >> 1) {
                uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                if (*(uint *)((int)uVar17 + 0x4f) < *(uint *)((int)uVar18 + 0x4d)) {
                  uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                  uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                  uVar12 = (undefined2)((ulong)uVar18 >> 0x10);
                  iVar13 = (int)uVar18;
                  if (*(uint *)((int)uVar17 + 0x4f) <
                      (uint)(*(int *)(iVar13 + 0x4d) * 2 + *(int *)(iVar13 + 0x4d)) >> 2) {
                    uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                    uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                    if (*(uint *)((int)uVar17 + 0x4f) < *(uint *)((int)uVar18 + 0x4d) >> 1) {
                      uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                      uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                      if (*(uint *)((int)uVar17 + 0x4f) < *(uint *)((int)uVar18 + 0x4d) >> 2) {
                        bVar3 = 5;
                      }
                      else {
                        bVar3 = 4;
                      }
                    }
                    else {
                      bVar3 = 3;
                    }
                  }
                  else {
                    bVar3 = 2;
                  }
                }
                else {
                  bVar3 = 1;
                }
              }
              else {
                bVar3 = 0;
              }
              uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
              uVar12 = (undefined2)((ulong)uVar17 >> 0x10);
              iVar4 = (int)uVar17;
              uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
              iVar13 = *(int *)(iVar4 + 0x62);
              if ((iVar13 < 0) ||
                 ((iVar13 == 0 &&
                  (*(uint *)(iVar4 + 0x60) < (uint)(*(int *)((int)uVar17 + 0x4d) * 0x28))))) {
                uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                uVar12 = (undefined2)((ulong)uVar17 >> 0x10);
                iVar4 = (int)uVar17;
                uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                iVar13 = *(int *)(iVar4 + 0x62);
                if ((iVar13 < 0) ||
                   ((iVar13 == 0 &&
                    (*(uint *)(iVar4 + 0x60) < (uint)(*(int *)((int)uVar17 + 0x4d) * 0x14))))) {
                  uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                  uVar12 = (undefined2)((ulong)uVar17 >> 0x10);
                  iVar4 = (int)uVar17;
                  uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                  iVar13 = *(int *)(iVar4 + 0x62);
                  if ((iVar13 < 0) ||
                     ((iVar13 == 0 &&
                      (*(uint *)(iVar4 + 0x60) < (uint)(*(int *)((int)uVar17 + 0x4d) * 0x3c) >> 2)))
                     ) {
                    uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                    uVar12 = (undefined2)((ulong)uVar17 >> 0x10);
                    iVar4 = (int)uVar17;
                    uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                    iVar13 = *(int *)(iVar4 + 0x62);
                    if ((iVar13 < 0) ||
                       ((iVar13 == 0 &&
                        (*(uint *)(iVar4 + 0x60) < (uint)(*(int *)((int)uVar17 + 0x4d) * 0x14) >> 1)
                        ))) {
                      uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                      uVar12 = (undefined2)((ulong)uVar17 >> 0x10);
                      iVar4 = (int)uVar17;
                      uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                      iVar13 = *(int *)(iVar4 + 0x62);
                      if ((iVar13 < 0) ||
                         ((iVar13 == 0 &&
                          (*(uint *)(iVar4 + 0x60) <
                           (uint)(*(int *)((int)uVar17 + 0x4d) * 0x14) >> 2)))) {
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
              if ((*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) < bVar3) {
                bVar3 = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
              }
              uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
              uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
              uVar12 = (undefined2)((ulong)uVar18 >> 0x10);
              iVar13 = (int)uVar18;
              if (*(uint *)((int)uVar17 + 0x5b) <
                  (uint)(*(int *)(iVar13 + 0x4d) * 2 + *(int *)(iVar13 + 0x4d)) >> 1) {
                uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                if (*(uint *)((int)uVar17 + 0x5b) < *(uint *)((int)uVar18 + 0x4d)) {
                  uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                  uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                  uVar12 = (undefined2)((ulong)uVar18 >> 0x10);
                  iVar13 = (int)uVar18;
                  if (*(uint *)((int)uVar17 + 0x5b) <
                      (uint)(*(int *)(iVar13 + 0x4d) * 2 + *(int *)(iVar13 + 0x4d)) >> 2) {
                    uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                    uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                    if (*(uint *)((int)uVar17 + 0x5b) < *(uint *)((int)uVar18 + 0x4d) >> 1) {
                      uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                      uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                      if (*(uint *)((int)uVar17 + 0x5b) < *(uint *)((int)uVar18 + 0x4d) >> 2) {
                        (*(uint8_t *)((uint8_t *)&(uStack_e))) = 5;
                      }
                      else {
                        (*(uint8_t *)((uint8_t *)&(uStack_e))) = 4;
                      }
                    }
                    else {
                      (*(uint8_t *)((uint8_t *)&(uStack_e))) = 3;
                    }
                  }
                  else {
                    (*(uint8_t *)((uint8_t *)&(uStack_e))) = 2;
                  }
                }
                else {
                  (*(uint8_t *)((uint8_t *)&(uStack_e))) = 1;
                }
              }
              else {
                (*(uint8_t *)((uint8_t *)&(uStack_e))) = 0;
              }
              (*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) = 0;
              uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
              uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
              if (*(uint *)((int)uVar17 + 0x54) < (uint)(*(int *)((int)uVar18 + 0x4d) << 1)) {
                uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                if (*(uint *)((int)uVar17 + 0x54) < *(uint *)((int)uVar18 + 0x4d)) {
                  uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                  uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                  if (*(uint *)((int)uVar17 + 0x54) < *(uint *)((int)uVar18 + 0x4d) >> 1) {
                    uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                    if (*(int *)((int)uVar17 + 0x54) < 0) {
                      uVar17 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                      uVar18 = *(undefined4 *)((in_stack_00000004 & 0xff) << 2);
                      if (*(uint *)((int)uVar17 + 0x54) < (uint)-*(int *)((int)uVar18 + 0x4d)) {
                        (*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) = 5;
                      }
                      else {
                        (*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) = 4;
                      }
                    }
                    else {
                      (*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) = 3;
                    }
                  }
                  else {
                    (*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) = 2;
                  }
                }
                else {
                  (*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) = 1;
                }
              }
              if (((bVar3 != 0) && ((byte)uStack_e <= bVar3)) && ((*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) <= bVar3)) {
                ovc39_loadArchiveEntry(bVar3 + 0x12);
                ovc39_lordOrLady();
                uStack_e = auStack_2cc;
                uStack_12 = 0x9ad8;
                uStack_10 = iVar11;
                pcVar10 = ovr_stsprintf();
                ovr_drawString();
                ovr_stshFree();
                return pcVar10;
              }
              if (((byte)uStack_e != 0) && ((*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) <= (byte)uStack_e)) {
                ovc39_loadArchiveEntry((byte)uStack_e + 0xd);
                ovc39_lordOrLady();
                uStack_e = auStack_2cc;
                uStack_12 = 0x9b2e;
                uStack_10 = iVar11;
                pcVar10 = ovr_stsprintf();
                ovr_drawString();
                ovr_stshFree();
                return pcVar10;
              }
              if ((*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) != 0) {
                ovc39_loadArchiveEntry((*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) + 0x17);
                ovc39_lordOrLady();
                uStack_e = auStack_2cc;
                uStack_12 = 0x9b7b;
                uStack_10 = iVar11;
                pcVar10 = ovr_stsprintf();
                ovr_drawString();
                ovr_stshFree();
                return pcVar10;
              }
              ovc39_lordOrLady();
              uStack_e = auStack_2cc;
              uStack_12 = 0x9bb1;
              uStack_10 = iVar11;
              pcVar10 = ovr_stsprintf();
              ovr_drawString();
              return pcVar10;
            }
            unaff_DI = -2;
          }
          iVar13 = 0x236f;
          lVar16 = CONCAT22(0x9297,(int)lVar16);
          iVar4 = iVar11;
          uVar9 = ovr_ovc23_findRecordAt();
          iVar11 = iVar13;
        } while (uVar9 != 0xffff);
        uVar15 = (undefined2)lVar16;
        unaff_SI = (undefined2 *)ovc39_findBuildingAt(iVar4 + unaff_DI,GfxRndSeed2);
        uVar12 = (undefined2)((ulong)GUnits >> 0x10);
        bVar3 = ((unit_t *)GUnits)[(int)unaff_SI].unitType;
        lVar16 = CONCAT13(((unit_t *)GUnits + (int)unaff_SI)->bldType,CONCAT12(bVar3,uVar15));
      } while ((char)((uint)uVar15 >> 8) != '\0');
      uVar17 = *(undefined4 *)((uint)bVar3 << 2);
      cVar2 = *(char *)((int)uVar17 + 0x3f);
    } while( true );
  case '\x02':
    LOCK();
    iVar13 = *(int *)((char *)"Too many construction sites." + 0x17 + unaff_DI);
    *(undefined1 **)((char *)"Too many construction sites." + 0x17 + unaff_DI) = &stack0xfffe;
    UNLOCK();
    *(int *)(iVar13 + -2) = unaff_DI;
    iVar11 = 0;
    lVar16 = 0;
    pcVar10 = (char *)(*(uint16_t *)((uint8_t *)&(PromoteThreshold)));
    while( true ) {
      pcVar5 = (char *)CONCAT11(0x24,GLeaderCount);
      bVar3 = (byte)((ulong)lVar16 >> 8);
      if (GLeaderCount <= bVar3) break;
      pcVar10 = (char *)((uint)bVar3 << 2);
      if ((byte)(&stack0xfffa)[in_stack_00000004 & 0xff] <=
          *(byte *)((int)*(undefined4 *)pcVar10 + 0xa5)) {
        for (uVar9 = 0xf8; bVar3 = (byte)((ulong)lVar16 >> 8), uVar9 < GUnitCount; uVar9 = uVar9 + 1
            ) {
          pcVar10 = (char *)"puppetmaker" + 3;
          uVar12 = (undefined2)((ulong)GUnits >> 0x10);
          if (((unit_t *)GUnits)[uVar9].unitType == bVar3) {
            pcVar10 = (char *)"puppetmaker" + 3;
            if (((unit_t *)GUnits)[uVar9].level < 8) {
              *(undefined2 *)(iVar13 + -4) = CONCAT11((char)(uVar9 * 9 >> 8),bVar3);
              *(uint *)(iVar13 + -6) = uVar9;
              *(undefined2 *)(iVar13 + -8) = 0x6000;
              *(undefined2 *)(iVar13 + -10) = 0x8958;
              iVar4 = season_usesAlignUp42(*(int *)(iVar13 + -6),*(byte *)(iVar13 + -4));
              if ((char)iVar4 != '\0') {
                pcVar10 = (char *)"puppetmaker" + 3;
                ((unit_t *)GUnits)[uVar9].level = 8;
                iVar11 = iVar11 + 1;
              }
            }
          }
        }
      }
      lVar16 = (ulong)(byte)(bVar3 + 1) << 8;
    }
    if (iVar11 != 0) {
      *(undefined2 *)(iVar13 + -4) = 0;
      *(undefined2 *)(iVar13 + -6) = 0x24;
      *(undefined2 *)(iVar13 + -8) = 0x6000;
      *(undefined2 *)(iVar13 + -10) = (uint8_t *)SpecialColors + 5;
      ovr_inputUpdate();
      *(undefined2 *)(iVar13 + -4) = 0xa000;
      *(int *)(iVar13 + -6) = iVar11;
      *(undefined2 *)(iVar13 + -8) = (char *)"steam bath" + 6;
      *(undefined2 *)(iVar13 + -10) = 0x89b2;
      uVar12 = ovr_ovc41_pluralSuffix();
      *(undefined2 *)(iVar13 + -6) = pcVar10;
      *(undefined2 *)(iVar13 + -8) = uVar12;
      *(int *)(iVar13 + -10) = iVar11;
      *(undefined2 *)(iVar13 + -0xc) = (char *)"puppetmaker" + 3;
      *(undefined2 *)(iVar13 + -0xe) = (char *)"%d building%s repaired.";
      *(undefined2 *)(iVar13 + -0x10) = unaff_SS;
      *(int *)(iVar13 + -0x12) = (int)auStack_80;
      *(char **)((code *)init_textFilename + iVar13) = (char *)"builder\'s hall" + 8;
      *(undefined2 *)(iVar13 + -0x16) = 0x89c6;
      pcVar5 = ovr_stsprintf();
      *(undefined2 *)(iVar13 + -6) = pcVar10;
      *(undefined2 *)(iVar13 + -8) = pcVar5;
      *(undefined2 *)(iVar13 + -10) = (char *)"glassworks" + 9;
      *(undefined2 *)(iVar13 + -0xc) = 0x89d0;
      ovr_uiNotify();
    }
    return pcVar5;
  case '\x03':
    (*(uint16_t *)((uint8_t *)&(AgntAnms[0x11]) + 18)) = (*(uint16_t *)((uint8_t *)&(AgntAnms[0x11]) + 18)) + iVar11;
    uVar9 = (*(uint16_t *)((uint8_t *)&(_streams[5]) + 3)) * -0xcc;
    ovr_stsprintf();
    pcVar10 = acStack_192;
    ovr_ovc28_compute2();
    if ((char)pcVar10 != '\0') {
      uVar8 = auStack_1f6[((uint)pcVar10 & 0xff) * 2];
      pcVar10 = (char *)CONCAT11((char)((uint)(auStack_1f6 + ((uint)pcVar10 & 0xff) * 2) >> 8),uVar8
                                );
      uVar17 = *(undefined4 *)((uVar9 & 0xff) << 2);
      *(undefined1 *)((int)uVar17 + 0x85) = uVar8;
    }
    return pcVar10;
  }
  out(*unaff_SI,in_DX);
  uStack0007 = 0;
  uVar12 = 0xa329;
  text1.seg = uStack_22;
  text1.ofs = uStack_24;
  uVar18 = CONCAT22(uStack_24,0x6000);
  (*(uint8_t *)((uint8_t *)&(text2.seg))) = (char)uStack_46;
  text2.ofs = uStack_48;
  (*(uint8_t *)((uint8_t *)&(text2.seg) + 1)) = (char)((uint)uStack_46 >> 8);
  ovc40_usesBlitLabel(text1,text2,2,0xf2);
  uStack0007 = 0xa4;
  ovc40_flushInput();
  uStack0007 = 0xa4;
  ovr_ovr_miceButton0PressStates_entry();
  uVar9 = *(uint *)BDA_DailyTimeCounter;
  uVar17 = CONCAT22(uVar12,*(undefined2 *)(BDA_DailyTimeCounter.ofs + 2));
  if ((char)uStack_46 == '\x04') {
    uStack0007 = 0;
    uVar6 = ovr_inputUpdate();
    if (1 < (byte)uVar6) {
      cStack_1d = '\x02';
    }
  }
  else {
    if (cStack_1f < '\0') {
      iVar13 = 0xee;
    }
    else {
      iVar13 = 1;
    }
    cStack_1e = 'w';
    while( true ) {
      lVar16 = (ulong)uVar9 << 0x10;
      uVar12 = (undefined2)uVar18;
      cVar2 = cStack_1e + -1;
      bVar1 = cStack_1e == '\0';
      uVar8 = (undefined1)unaff_SS;
      uVar14 = (undefined1)((uint)unaff_SS >> 8);
      cStack_1e = cVar2;
      if (bVar1) break;
      if ((iVar13 == 100) && (in_stack_0000000e == '\x02')) {
        uStack0007 = 0xb4;
        ovr_blitLoadRleGfx();
        uStack0007 = 0;
        uVar12 = (undefined2)uVar17;
        text1_00.seg = uStack_36;
        text1_00.ofs = uStack_38;
        (*(uint8_t *)((uint8_t *)&(text2_00.seg))) = (char)uStack_36;
        text2_00.ofs = uStack_38;
        (*(uint8_t *)((uint8_t *)&(text2_00.seg) + 1)) = (char)(uStack_36 >> 8);
        ovc40_usesBlitLabel(text1_00,text2_00,0,0xf2);
        uStack0007 = 0;
        text1_01.seg = uStack_32;
        text1_01.ofs = uStack_34;
        (*(uint8_t *)((uint8_t *)&(text2_01.seg))) = (char)uStack_32;
        text2_01.ofs = uStack_34;
        (*(uint8_t *)((uint8_t *)&(text2_01.seg) + 1)) = (char)(uStack_32 >> 8);
        ovc40_usesBlitLabel(text1_01,text2_01,1,0xf2);
        uStack0007 = 0;
        uVar17 = CONCAT22(0xa5ad,uVar12);
        text1_02.seg = uStack_2e;
        text1_02.ofs = uStack_30;
        uVar12 = 0x22d3;
        (*(uint8_t *)((uint8_t *)&(text2_02.seg))) = (char)uStack_2e;
        text2_02.ofs = uStack_30;
        (*(uint8_t *)((uint8_t *)&(text2_02.seg) + 1)) = (char)(uStack_2e >> 8);
        ovc40_usesBlitLabel(text1_02,text2_02,2,0xf2);
      }
      uStack0007 = (undefined1)((uint)auStack_14 >> 8);
      uVar18 = CONCAT22(0xa5be,uVar12);
      ovc40_usesBlitGfx10((byte)iVar13,iVar13,(brect_t *)CONCAT13(uVar14,CONCAT12(uVar8,auStack_14))
                         );
      uStack0007 = 0xa5;
      uVar6 = ovr_biosKeyAvail();
      if ((char)uVar6 != '\0') {
        uStack0007 = 0xa5;
        uVar6 = ovr_gameProcessKey();
        uVar12 = (undefined2)uVar18;
        if (uVar6 == 0x11b) {
          cStack_1d = '\x02';
          break;
        }
        if (uVar6 == 0x1c0d) break;
      }
      uStack0007 = 0xa5;
      uVar7 = ovr_init2_updateMouseButtons();
      uVar12 = (undefined2)uVar18;
      if (uVar7 != 0) break;
      if (rightButtonLatch != '\0') {
        cStack_1d = '\x02';
        break;
      }
      do {
        uStack0007 = 0xa6;
        ovr_audio_usesLDIV_at_();
        if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != (int)uVar17) break;
      } while (*(int *)BDA_DailyTimeCounter == (int)((ulong)lVar16 >> 0x10));
      uVar9 = *(uint *)BDA_DailyTimeCounter;
      uVar17 = CONCAT22((int)((ulong)uVar17 >> 0x10),*(undefined2 *)(BDA_DailyTimeCounter.ofs + 2));
      iVar13 = iVar13 + cStack_1f;
    }
    if (cStack_1f < '\x01') {
      uStack0007 = (undefined1)((uint)auStack_14 >> 8);
      ovc40_usesBlitGfx10(0,0,(brect_t *)CONCAT13(uVar14,CONCAT12(uVar8,auStack_14)));
    }
    else {
      uStack0007 = (undefined1)((uint)auStack_14 >> 8);
      ovc40_usesBlitGfx10(0xef,0xef,(brect_t *)CONCAT13(uVar14,CONCAT12(uVar8,auStack_14)));
    }
    uStack0007 = 0xa6;
    ovc40_flushInput();
    rightButtonLatch = '\0';
    if ((in_stack_0000000e == '\x02') || (in_stack_0000000e == '\x03')) {
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
      uVar9 = *(uint *)BDA_DailyTimeCounter;
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = uVar9;
      if (cStack_1d == '\0') {
        uStack0007 = 0;
        uVar6 = ovr_inputUpdate();
        cStack_1d = (char)uVar6;
      }
    }
    else {
      uStack0007 = 0xe9;
      uVar18 = CONCAT22(0xa6e4,uVar12);
      ovr_blitLoadRleGfx();
      MiceProcessed = 0;
      uStack0007 = 4;
      ovr_miceBlitRect();
      do {
        do {
          uVar12 = (undefined2)uVar18;
          uStack0007 = 0xa7;
          ovr_audio_usesLDIV_at_();
          uStack0007 = (undefined1)((uint)&stack0xfffa >> 8);
          uVar18 = CONCAT22(0xa714,uVar12);
          bVar3 = ovr_init2_usesCFGMice();
          if ((((CONCAT11(extraout_AH,bVar3) != 0) && (0x87 < (uint)uVar18)) &&
              (uVar7 = (uint)((ulong)uVar17 >> 0x10), 0xb9 < uVar7)) &&
             (((uint)uVar18 < 0xd6 && (uVar7 < 0xc6)))) goto L_OVC40_69c8_04c6_0AF0;
          if (rightButtonLatch != '\0') {
            cStack_1d = '\x02';
            goto L_OVC40_69c8_04c6_0AF0;
          }
          uStack0007 = 0xa7;
          uVar6 = ovr_biosKeyAvail();
        } while ((char)uVar6 == '\0');
        uStack0007 = 0xa7;
        uVar6 = ovr_gameProcessKey();
        if (uVar6 == 0x11b) {
          cStack_1d = '\x02';
          break;
        }
      } while (uVar6 != 0x1c0d);
    }
  }
L_OVC40_69c8_04c6_0AF0:
  uStack0007 = 4;
  ovr_miceRestoreArea();
  uStack0007 = 0xa7;
  ovr_clearMiceProcessed();
  uStack0007 = uStack_17;
  ovr_stshFree();
  uStack0007 = 0x23;
  psStack_1c = ovc40_usesStshLoadGfx(0xde);
  uStack0007 = (undefined1)((uint)psStack_1c >> 8);
  uStack_1a = uVar9;
  ovc40_usesVgaSetPalette8bit();
  uStack0007 = 0xa7;
  ovr_stop_audio();
  CurMusicType = 0xff;
  uStack0007 = 0xa7;
  ovr_init_usesBlitGfxRect();
  uVar9 = (uint)GameRunning;
  if (uVar9 == 0) {
    uStack0007 = 0x22;
    ovc40_usesCalcSeasonPalette();
  }
  uVar8 = (undefined1)(uVar9 >> 8);
  uStack0007 = 0xa7;
  ovr_ovc28_textHalflingCastle();
  uStack0007 = 0xa7;
  ovr_ovc41_usesGMenuItem();
  uStack0007 = 4;
  ovr_miceBlitRect();
  return (char *)CONCAT11(uVar8,cStack_1d);
}



/* 6a8f:1847 */

/* Prints the "You cannot see the terrain here." notice. */

void __cdecl16far ovc41_cannotSeeTerrainNotice(void)

{
  bool bVar1;
  undefined2 unaff_BP;
  
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
    ovr_say((char *)CONCAT22(unaff_BP,(char *)"puppetmaker" + 3),0x6f42);
    ovr_stop_audio();
  }
  return;
}



/* 6a8f:18c6 */

/* [R6] touches GMenuItem, MenuMode */

void __cdecl16far ovc41_usesGMenuItem(void)

{
  char unaff_BP;
  
  ovr_draw_usesBlitLoadRleGfx2();
  GMenuItem = savedMenuItem;
  MenuMode = MenuModeSaved;
  ovc41_usesAgnt_clear(unaff_BP,0);
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
  uint16_t unaff_BP;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t dst;
  far_t dst_00;
  uint16_t uVar1;
  far_t dst_01;
  far_t dst_02;
  
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  savedMenuItem = GMenuItem;
  MenuModeSaved = MenuMode;
  dst.seg = unaff_BP;
  dst.ofs = 0xa000;
  gfx.seg = 0xe249;
  gfx.ofs = nwpanel1Cut2Seg;
  ovr_blitLoadRleGfx(gfx,dst,nwpanel1Cut2Ofs);
  dst_00.seg = dst.seg;
  dst_00.ofs = 0xa000;
  gfx_00.seg = 0xe249;
  gfx_00.ofs = trianglsCut6Seg;
  ovr_blitLoadRleGfx(gfx_00,dst_00,trianglsCut6Ofs);
  uVar1 = dst_00.seg;
  ovr_uiMainMenuLoop();
  dst_01.seg = uVar1;
  dst_01.ofs = 0xa000;
  gfx_01.seg = 0xe249;
  gfx_01.ofs = nwpanel1Cut2Seg;
  ovr_blitLoadRleGfx(gfx_01,dst_01,nwpanel1Cut2Ofs);
  dst_02.seg = dst_01.seg;
  dst_02.ofs = 0xa000;
  gfx_02.seg = 0xe249;
  gfx_02.ofs = trianglsCut5Seg;
  ovr_blitLoadRleGfx(gfx_02,dst_02,trianglsCut5Ofs);
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

void __cdecl16far ovc41_usesMiceBlitRect(uint menuIndex,...)

{
  uint uVar1;
  uint16_t unaff_SI;
  bool bVar2;
  uint in_stack_00000004;
  brect_t *br;
  
  uVar1 = in_stack_00000004;
  bVar2 = MiceNeedsUpdate == '\0';
  if (bVar2) {
    br = (brect_t *)CONCAT22(unaff_SI,(brect_t *)((char *)"puppetmaker" + 3));
    ovr_miceRestoreArea(br,0x44a);
    unaff_SI = (uint16_t)((ulong)br >> 0x10);
  }
  TextBlitDstSeg = 0xa000;
  if (GMenuItem == uVar1) {
    ovr_draw_usesFillRect2(0xa000,unaff_SI,(uint)((uint8_t *)menuItemRow)[GMenuItem]);
  }
  ovr_draw_menuRowBar(-0x6000,unaff_SI,uVar1);
  if (bVar2) {
    ovr_miceBlitRect((brect_t *)CONCAT22(unaff_SI,(brect_t *)((char *)"puppetmaker" + 3)),0x44a);
  }
  return;
}



/* 6a8f:1c74 */

/* WARNING: Variable defined which should be unmapped: victimName */
/* [R2] string "%s is paralyzed by %s." */

undefined1 __cdecl16far ovc41_textParalyzed(agnt_t *source,agnt_t *victim,uint strength,...)

{
  uint uVar1;
  uint8_t *puVar2;
  uint16_t uVar3;
  char *pcVar4;
  int iVar5;
  char *in_DX;
  char *unaff_SS;
  int in_stack_00000004;
  undefined1 uVar6;
  undefined1 uVar7;
  byte bVar8;
  undefined2 uVar9;
  uint8_t victimName;
  undefined1 uStack_11b;
  uint8_t sourceName;
  uint8_t msg;
  undefined1 uStack_3;
  
  uStack_3 = 0;
  if ((*(uint *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x2b) & 0x80) != 0) {
    (*(uint8_t *)((uint8_t *)&(victim) + 2)) = *(char *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x21);
    (*(uint8_t *)((uint8_t *)&(victim) + 3)) = 0;
  }
  uVar6 = (undefined1)((ulong)source >> 0x10);
  if (CONCAT11((*(uint8_t *)((uint8_t *)&(victim) + 3)),(*(uint8_t *)((uint8_t *)&(victim) + 2))) < (int)(uint)*(byte *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x21)) {
    *(undefined1 *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x23) = 6;
    *(undefined1 *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x24) = 1;
    *(undefined2 *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 6) = 0;
    ovr_agnt_usesAnimFrame
              ((agnt_t *)CONCAT13(uStack_11b,CONCAT12(victimName,(agnt_t *)victim)),uVar6);
    if (((*(char *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x11) == '\0') && ((*(uint *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x2b) & 0x200) == 0)
        ) && ((*(uint *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x3c) & 0x40) != 0)) {
      uVar9 = GSavedBlitSeg;
      pcVar4 = ovr_agnt_statusText();
      uVar7 = SUB21(in_DX,0);
      ovr_agnt_statusText();
      puVar2 = ovr_ovc15_usesStshRealloc();
      pcVar4 = ovr_stsprintf((char *)CONCAT22(0x6f63,unaff_SS),
                             (char *)CONCAT22(puVar2,(char *)"puppetmaker" + 3),in_DX,&msg,pcVar4,
                             uVar7);
      ovr_uiNotify((char *)CONCAT22(uVar9,in_DX),(uint16_t)pcVar4);
      iVar5 = ovr_audio_panFromX((agnt_t *)
                                 CONCAT13(uStack_11b,CONCAT12(victimName,(agnt_t *)victim)),uVar6);
      ovr_play_sfxU(0,iVar5,3);
      OVC41_6a8f_01e7_entry
                ((agnt_t *)CONCAT13(uStack_11b,CONCAT12(victimName,(agnt_t *)victim)),uVar6);
      *(uint *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x2b) = *(uint *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x2b) | 0x200;
      ovr_attact_usesLDIV_at_2();
      return uStack_3;
    }
    if (((*(char *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x11) == '\0') && ((*(uint *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x2b) & 0x800) == 0)
        ) && (((*(uint *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x40) & 0x100) != 0 &&
              (uVar1 = ovr_ovc27_rollToHitEntity
                                 ((uint32_t)CONCAT22(2,(agnt_t *)victim),victimName,(*(uint16_t *)((uint8_t *)&(source) + 2))),
              (uVar1 & 0xff) == 0)))) {
      uVar9 = GSavedBlitSeg;
      pcVar4 = ovr_agnt_statusText();
      uVar7 = SUB21(in_DX,0);
      ovr_agnt_statusText();
      puVar2 = ovr_ovc15_usesStshRealloc();
      pcVar4 = ovr_stsprintf((char *)CONCAT22(0x6f7a,unaff_SS),
                             (char *)CONCAT22(puVar2,(char *)"puppetmaker" + 3),in_DX,&msg,pcVar4,
                             uVar7);
      ovr_uiNotify((char *)CONCAT22(uVar9,in_DX),(uint16_t)pcVar4);
      *(uint *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x2b) = *(uint *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x2b) | 0x800;
      iVar5 = ovr_audio_panFromX((agnt_t *)
                                 CONCAT13(uStack_11b,CONCAT12(victimName,(agnt_t *)victim)),uVar6);
      ovr_play_sfxU(0,iVar5,0x1b);
      OVC41_6a8f_01e7_entry
                ((agnt_t *)CONCAT13(uStack_11b,CONCAT12(victimName,(agnt_t *)victim)),uVar6);
      ovr_attact_usesLDIV_at_2();
      return uStack_3;
    }
    *(char *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x21) = *(char *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x21) - (*(uint8_t *)((uint8_t *)&(victim) + 2));
    if (((*(uint *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x3c) & 0x8000) == 0) ||
       ((*(uint *)((int)*(undefined4 *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x1d) + 0x3c) & 0x8000) == 0)) {
      if (*(char *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x50) == '\0') {
        iVar5 = ovr_audio_panFromX((agnt_t *)
                                   CONCAT13(uStack_11b,CONCAT12(victimName,(agnt_t *)victim)),uVar6)
        ;
        bVar8 = 0;
        uVar3 = ovr_randBelow(0,2);
        ovr_play_sfxU(bVar8,iVar5,CONCAT11((char)(uVar3 >> 8),(char)uVar3 + '='));
      }
      else if (*(char *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x50) == '\x15') {
        uVar3 = ovr_randBelow(CONCAT11(uStack_11b,victimName),2);
        if ((uVar3 & 0xff) == 0) {
          ovr_play_sfx(0,0x15);
        }
        else {
          ovr_play_sfx(0,0x47);
        }
      }
      else if (*(char *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x50) == '\x03') {
        iVar5 = ovr_audio_panFromX((agnt_t *)
                                   CONCAT13(uStack_11b,CONCAT12(victimName,(agnt_t *)victim)),uVar6)
        ;
        bVar8 = 0;
        uVar3 = ovr_randBelow(0,2);
        ovr_play_sfxU(bVar8,iVar5,CONCAT11((char)(uVar3 >> 8),(char)uVar3 + '\x14'));
      }
      else {
        ovr_play_sfx(0,*(undefined1 *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x50));
      }
    }
    else {
      iVar5 = ovr_audio_panFromX((agnt_t *)
                                 CONCAT13(uStack_11b,CONCAT12(victimName,(agnt_t *)victim)),uVar6);
      bVar8 = 0;
      uVar3 = ovr_randBelow(0,2);
      ovr_play_sfxU(bVar8,iVar5,CONCAT11((char)(uVar3 >> 8),(char)uVar3 + '\x14'));
    }
    if ((*(uint *)(in_stack_00000004 + 0x2b) & 0x20) != 0) {
      *(uint *)(in_stack_00000004 + 0x2b) = *(uint *)(in_stack_00000004 + 0x2b) & 0xffdf;
      uVar9 = GSavedBlitSeg;
      pcVar4 = ovr_agnt_statusText();
      ovr_ovc15_usesStshRealloc((char *)CONCAT22(uVar9,in_DX),pcVar4);
      pcVar4 = ovr_stsprintf();
      ovr_uiNotify((char *)CONCAT22(uVar9,in_DX),(uint16_t)pcVar4);
      *(undefined1 *)(in_stack_00000004 + 0x2f) =
           *(undefined1 *)*(undefined4 *)(in_stack_00000004 + 0x1d);
      ovc41_advanceAnimFrame
                ((agnt_t *)CONCAT13(uStack_11b,CONCAT12(victimName,(agnt_t *)source)),
                 (char)in_stack_00000004);
      ovr_attact_usesLDIV_at_2();
    }
  }
  else {
    if (*(char *)((int)*(undefined4 *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x1d) + 0x51) == -1) {
      iVar5 = ovr_audio_panFromX((agnt_t *)
                                 CONCAT13(uStack_11b,CONCAT12(victimName,(agnt_t *)victim)),uVar6);
      ovr_play_sfxU(0,iVar5,4);
    }
    else {
      iVar5 = ovr_audio_panFromX((agnt_t *)
                                 CONCAT13(uStack_11b,CONCAT12(victimName,(agnt_t *)victim)),uVar6);
      ovr_play_sfxU(0,iVar5,CONCAT11((char)((uint)iVar5 >> 8),
                                     *(undefined1 *)
                                      ((int)*(undefined4 *)((*(uint16_t *)((uint8_t *)&(source) + 2)) + 0x1d) + 0x51)));
    }
    ovc41_settleAgentCombat
              (source,(agnt_t *)CONCAT13(uStack_11b,CONCAT12(victimName,(agnt_t *)victim)),
               in_stack_00000004);
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
  byte *pbVar4;
  code *pcVar5;
  int iVar6;
  byte bVar7;
  undefined1 extraout_AH;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  char cVar11;
  byte *pbVar12;
  uint uVar13;
  entity_t *peVar14;
  char *pcVar15;
  agnt_t *paVar16;
  undefined1 *puVar17;
  int unaff_SI;
  undefined2 *unaff_DI;
  undefined2 uVar18;
  uint unaff_SS;
  uint16_t count;
  far_t dst;
  uint8_t text;
  uint8_t msg;
  char acStack_42 [6];
  char cStack_3c;
  byte bStack_3b;
  int iStack_3a;
  byte *pbStack_38;
  byte *pbStack_36;
  byte *pbStack_34;
  byte *pbStack_32;
  byte *pbStack_30;
  byte *pbStack_2e;
  byte *pbStack_2c;
  byte *pbStack_2a;
  byte *pbStack_28;
  byte *pbStack_26;
  byte *pbStack_24;
  byte *pbStack_22;
  byte *pbStack_20;
  byte *pbStack_1e;
  uint8_t agnt;
  byte abStack_16 [8];
  int iStack_e;
  byte *pbStack_c;
  int iStack_a;
  undefined2 uStack_8;
  undefined4 uStack_6;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&agnt;
  iVar10 = 0x10;
  F_SCOPY(far_from_u32((uint32_t)(0x24106e38)),dst);
  pbVar4 = (byte *)((long)agntIndex * 0x34);
  pbVar9 = (byte *)pbVar4;
  pbStack_c = pbVar9;
  iStack_a = 0x1726;
  if ((*(uint *)(pbVar9 + 0x2b) & 0x820) == 0) {
    uVar18 = (undefined2)((ulong)agntPtr >> 0x10);
    paVar16 = (agnt_t *)agntPtr;
    paVar16->flags = paVar16->flags & 0xfff7;
    if ((((entity_t *)paVar16->entity)->base).level < 8) {
      uStack_6 = (char *)((ulong)uStack_6 & 0xffffff);
    }
    else if ((((entity_t *)paVar16->entity)->base).level < 10) {
      uStack_6 = (char *)CONCAT13(1,(undefined3)uStack_6);
    }
    else if ((((entity_t *)paVar16->entity)->base).level < 0xc) {
      uStack_6 = (char *)CONCAT13(2,(undefined3)uStack_6);
    }
    else {
      uStack_6 = (char *)CONCAT13(3,(undefined3)uStack_6);
    }
    uVar13 = (uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 3));
    if (uVar13 < 4) {
      switch(uVar13) {
      case 0:
        return (byte *)((int)(undefined4 *)&_DATA + 1);
      case 2:
        cVar3 = *(char *)(uVar13 * 2 + unaff_SI);
        puVar17 = &stack0xfffe + unaff_SI;
        iVar6 = uVar13 * 3;
        *(undefined1 **)((char *)" You can only place a single arena." + 0xd + iVar6) =
             puVar17 + *(int *)((char *)" You can only place a single arena." + 0xd + iVar6);
        *(int *)(&stack0xffff + (int)puVar17) = *(int *)(&stack0xffff + (int)puVar17) + iVar6;
        *(int *)(&stack0xfffe + (int)unaff_DI) = *(int *)(&stack0xfffe + (int)unaff_DI) + iVar6;
                    /* WARNING: Read-only address (ram,0x00033501) is written */
        iRam00033501 = uVar13 + 0x8b26;
        cVar11 = (char)(&stack0xfed8 + (int)unaff_DI +
                       CONCAT11((char)((ulong)pbVar4 >> 0x18),(char)((ulong)pbVar4 >> 0x10) + cVar3)
                       );
        pcVar15 = (char *)(uint)(byte)((char)iVar6 + cVar11);
        (&stack0x6ffe)[(int)puVar17] = (&stack0x6ffe)[(int)puVar17];
        pcVar1 = pcVar15;
        *pcVar1 = *pcVar1 + cVar11;
        *(undefined2 *)(&stack0xfed6 + (int)unaff_DI) = 0x6000;
        pcVar1 = pcVar15 + -0x61f9;
        *pcVar1 = *pcVar1;
        cVar11 = *pcVar1;
        *(undefined1 **)(&stack0xfeda + (int)unaff_DI) = &stack0xfedc + (int)unaff_DI;
        uVar18 = *(undefined2 *)(&stack0xfeda + (int)unaff_DI);
        *(undefined2 *)(&stack0xfeda + (int)unaff_DI) = uVar18;
        if (iVar10 == 1 || cVar11 == '\0') {
          s_constructing_2410_06a4[10] = -0x6b;
          s_constructing_2410_06a4[0xb] = '\x06';
                    /* WARNING: Read-only address (ram,0x000247ae) is written */
        }
        uVar2 = in(&stack0xfed8 + (int)unaff_DI +
                   CONCAT11((char)((ulong)pbVar4 >> 0x18),(char)((ulong)pbVar4 >> 0x10) + cVar3));
        *unaff_DI = uVar2;
        *(undefined2 *)(&stack0xfed8 + (int)unaff_DI) = uVar18;
        *(undefined2 *)(&stack0xfed6 + (int)unaff_DI) = uVar18;
        *(undefined2 *)(&stack0xfed4 + (int)unaff_DI) = uVar18;
        *(undefined2 *)(&stack0xfed4 + (int)unaff_DI) =
             *(undefined2 *)(&stack0xfed4 + (int)unaff_DI);
        pcVar5 = (code *)swi(1);
        pbVar9 = (byte *)(*pcVar5)();
        return pbVar9;
      case 3:
        do {
          TextBlitDstSeg = 0xa000;
          TextBlitX = uStack_8 + 6;
          TextBlitY = (uint16_t)(unaff_DI + 1);
          uStack_6 = (char *)CONCAT22((&paVar16->x + unaff_SI * 2)[1],
                                      (char *)(&paVar16->x)[unaff_SI * 2]);
          iVar10 = unaff_SI;
          if (*uStack_6 == '%') {
            BlitLetterType = 2;
            ovr_ovc45_compute9();
            ovr_blitLabel();
            pbVar9 = (byte *)((char *)"puppetmaker" + 3);
            BlitLetterType = 0;
          }
          else if (*uStack_6 == '@') {
            ovr_ovc45_compute9();
            pbVar9 = (byte *)ovr_blitLabel();
          }
          else {
            ovr_ovc45_compute9();
            pbVar9 = (byte *)ovr_blitLabel();
          }
          while( true ) {
            unaff_DI = unaff_DI + 7;
            unaff_SI = iVar10 + 1;
            if (agntIndex <= unaff_SI) {
              if (goldPartyIndex != 0xff) {
                pbVar9 = (byte *)CONCAT11((char)((uint)pbVar9 >> 8),goldPartyIndex);
                ovc28_drawGold(goldPartyIndex);
              }
              return pbVar9;
            }
            if ((&paVar16->targetX)[iVar10 * 2] != 0 || (&paVar16->targetX + iVar10 * 2)[1] != 0)
            break;
            pbVar9 = (byte *)0x0;
            iVar10 = unaff_SI;
          }
          ovr_blitLoadRleGfx();
        } while( true );
      }
switchD_6000_ca06_caseD_1:
      (&stack0xfffe)[(int)unaff_DI] = (&stack0xfffe)[(int)unaff_DI] + (char)iVar10;
      *(undefined1 *)((int)unaff_DI + 0x15) = 0;
      bStack_3b = ovr_init2_usesCFGMice();
      while( true ) {
        if (rightButtonLatch != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((pbStack_2e != pbStack_2a) || (pbStack_30 != pbStack_2c)) {
          pbStack_2a = pbStack_2e;
          _agnt = pbStack_2e;
          pbStack_2c = pbStack_30;
          pbStack_1e = pbStack_30;
        }
        if (bStack_3b != 0) break;
        uVar18 = keyprocessor_usesBiosKeyAvail
                           ((uint16_t *)CONCAT22(unaff_SS,&pbStack_36),
                            (uint16_t *)CONCAT22(unaff_SS,&pbStack_38),
                            (byte *)CONCAT22(unaff_SS,&bStack_3b));
        if ((char)uVar18 != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((pbStack_36 != pbStack_32) || (pbStack_38 != pbStack_34)) {
          pbStack_32 = pbStack_36;
          _agnt = pbStack_36;
          pbStack_34 = pbStack_38;
          pbStack_1e = pbStack_38;
          iStack_e = uStack_8;
          ovr_blitLoadRleGfx();
          ovr_blitGfx10();
          ovr_miceBlitRect();
          ovr_blitRect();
          ovr_miceUpdate();
        }
        if (bStack_3b == 0) goto switchD_6000_ca06_caseD_1;
      }
      if (((((int)_agnt < 0xc) || (0xde < (int)_agnt)) || ((int)pbStack_1e < 7)) ||
         (0x96 < (int)pbStack_1e)) goto L_ui_unit_order_6616_0689_1054;
      do {
        bVar7 = ovr_init2_usesCFGMice();
      } while (CONCAT11(extraout_AH,bVar7) != 0);
      pbStack_26 = (byte *)0xffff;
      pbStack_28 = (byte *)0xffff;
      pbStack_20 = pbStack_1e;
      bStack_3b = 0;
      pbVar9 = _agnt;
      do {
        uVar18 = keyprocessor_usesBiosKeyAvail
                           ((uint16_t *)CONCAT22(unaff_SS,&pbStack_36),
                            (uint16_t *)CONCAT22(unaff_SS,&pbStack_38),
                            (byte *)CONCAT22(unaff_SS,&bStack_3b));
        if ((char)uVar18 != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((pbStack_36 != pbStack_32) || (pbStack_38 != pbStack_34)) {
          pbStack_32 = pbStack_36;
          pbStack_34 = pbStack_38;
          pbStack_20 = pbStack_38;
          pbVar9 = pbStack_36;
        }
        if ((int)pbVar9 < 0xc) {
          pbVar9 = (byte *)__C0_ASM_CopyRight + 8;
        }
        if (0xde < (int)pbVar9) {
          pbVar9 = (byte *)0xde;
        }
        if ((int)pbStack_20 < 7) {
          pbStack_20 = (byte *)__C0_ASM_CopyRight + 3;
        }
        if (0x96 < (int)pbStack_20) {
          pbStack_20 = (byte *)((char *)"%d \r" + 1);
        }
        if ((pbStack_26 != pbVar9) || (pbStack_28 != pbStack_20)) {
          iStack_e = uStack_8;
          ovr_blitLoadRleGfx();
          ovr_driver_drawLine();
          ovr_driver_drawLine();
          ovr_driver_drawLine();
          ovr_driver_drawLine();
          ovr_miceBlitRect();
          ovr_blitRect();
          ovr_miceUpdate();
          pbVar8 = (byte *)((int)(pbStack_20 + -9) / 3 + Seed_2000_d10e);
          pbVar12 = (byte *)(Seed_2000_d110 + ((uint)(pbVar9 + -0xc) >> 1) + 2 & 0xfffc);
          pbStack_24 = (byte *)((int)(pbStack_1e + -9) / 3 + Seed_2000_d10e);
          pbStack_22 = (byte *)(Seed_2000_d110 + ((uint)(_agnt + -0xc) >> 1) + 2 & 0xfffc);
          pbStack_26 = pbVar12;
          if ((int)pbVar12 < (int)pbStack_22) {
            pbStack_26 = pbStack_22;
            pbStack_22 = pbVar12;
            pbStack_c = pbVar12;
          }
          pbStack_28 = pbVar8;
          if ((int)pbVar8 < (int)pbStack_24) {
            pbStack_28 = pbStack_24;
            pbStack_24 = pbVar8;
            pbStack_c = pbVar8;
          }
          iStack_a = 0;
          for (uVar13 = 0; uVar13 < EntityCount; uVar13 = uVar13 + 1) {
            uVar18 = (undefined2)((ulong)Entities >> 0x10);
            peVar14 = (entity_t *)Entities;
            if ((((*(char *)((int)&peVar14[uVar13].base.entity + 3) == cStack_3c) &&
                 (pbStack_22 <= (byte *)((peVar14 + uVar13)->base).x)) &&
                ((byte *)((peVar14 + uVar13)->base).x <= pbStack_26)) &&
               ((pbStack_24 <= (byte *)peVar14[uVar13].base.y &&
                ((byte *)peVar14[uVar13].base.y <= pbStack_28)))) {
              iStack_a = iStack_a + 1;
            }
          }
          ovr_resetTextBlitCycle();
          ovr_ovc45_compute9();
          ovr_ovc41_pluralSuffix();
          ovr_stsprintf();
          ovr_uiNotify();
        }
        pbStack_28 = pbStack_20;
        pbStack_26 = pbVar9;
        if (bStack_3b == 0) {
          bStack_3b = ovr_init2_usesCFGMice();
        }
        count = dst.seg;
        if (rightButtonLatch != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((pbStack_2e != pbStack_2a) || (pbStack_30 != pbStack_2c)) {
          pbStack_2a = pbStack_2e;
          pbStack_2c = pbStack_30;
          pbStack_20 = pbStack_30;
          pbVar9 = pbStack_2e;
        }
      } while (bStack_3b == 0);
      ovr_miceRestoreArea();
      if (((((int)pbVar9 < 0xc) || (0xde < (int)pbVar9)) || ((int)pbStack_20 < 7)) ||
         (0x96 < (int)pbStack_20)) {
L_ui_unit_order_6616_0689_1054:
        ovr_miceRestoreArea();
        ovr_say();
      }
      else {
        pbVar8 = (byte *)((int)(pbStack_20 + -9) / 3 + Seed_2000_d10e);
        pbVar12 = (byte *)(Seed_2000_d110 + ((uint)(pbVar9 + -0xc) >> 1) + 2 & 0xfffc);
        pbVar9 = (byte *)((int)(pbStack_1e + -9) / 3 + Seed_2000_d10e);
        uVar13 = Seed_2000_d110 + ((uint)(_agnt + -0xc) >> 1) + 2;
        pbStack_22 = (byte *)(uVar13 & 0xfffc);
        pbStack_26 = pbVar12;
        if ((int)pbVar12 < (int)pbStack_22) {
          pbStack_c = (byte *)(uVar13 & 0xfffc);
          pbStack_26 = pbStack_c;
          pbStack_22 = pbVar12;
        }
        pbStack_28 = pbVar8;
        pbStack_24 = pbVar9;
        if ((int)pbVar8 < (int)pbVar9) {
          pbStack_28 = pbVar9;
          pbStack_24 = pbVar8;
          pbStack_c = pbVar9;
        }
        _fmemset((void *)(ulong)unaff_SS,5,count);
        iStack_a = 0;
        for (uVar13 = 0; uVar13 < EntityCount; uVar13 = uVar13 + 1) {
          uVar18 = (undefined2)((ulong)Entities >> 0x10);
          peVar14 = (entity_t *)Entities;
          if (((*(char *)((int)&peVar14[uVar13].base.entity + 3) == cStack_3c) &&
              (pbStack_22 <= (byte *)((peVar14 + uVar13)->base).x)) &&
             (((byte *)((peVar14 + uVar13)->base).x <= pbStack_26 &&
              ((pbStack_24 <= (byte *)peVar14[uVar13].base.y &&
               ((byte *)peVar14[uVar13].base.y <= pbStack_28)))))) {
            if (bStack_3b < 2) {
              unit_usesAlignUp42((byte)agntPtr,((peVar14 + uVar13)->base).x,peVar14[uVar13].base.y);
            }
            else {
              unit_usesEntities(bStack_3b,uVar13,(uint16_t)acStack_42,unaff_SS);
            }
            iStack_a = iStack_a + 1;
          }
        }
        for (iStack_3a = 0; iStack_3a < 5; iStack_3a = iStack_3a + 1) {
          if (acStack_42[iStack_3a] != '\0') {
            ovr_ovc41_usesMiceBlitRect();
          }
        }
        ovr_constr_flushDirtyRects();
        ovr_resetTextBlitCycle();
        if (bStack_3b == 1) {
          ovr_ovc41_pluralSuffix();
          ovr_stsprintf();
          ovr_say();
        }
        else if (bStack_3b == 2) {
          ovr_ovc41_pluralSuffix();
          ovr_stsprintf();
          ovr_say();
        }
        else if (bStack_3b == 3) {
          ovr_ovc41_pluralSuffix();
          ovr_stsprintf();
          ovr_say();
        }
        else if (bStack_3b == 4) {
          ovr_ovc41_pluralSuffix();
          ovr_stsprintf();
          ovr_say();
        }
        ovr_inputUpdate();
      }
      iStack_e = uStack_8;
      ovr_blitLoadRleGfx();
      ovr_miceBlitRect();
      pbVar9 = abStack_16;
      ovr_blitRect();
      ovr_miceUpdate();
      ovr_stshFree();
      ovr_stshFree();
      ovr_miceRestoreArea();
      return pbVar9;
    }
    bVar7 = pbVar9[0x21];
    pbVar9[0x21] = pbVar9[0x21] + (char)uStack_6;
    if (pbVar9[0x22] < pbVar9[0x21]) {
      pbVar9[0x21] = pbVar9[0x22];
    }
    pbVar8 = pbVar9 + 0x21;
    pbVar9 = (byte *)(uint)*pbVar8;
    if (*pbVar8 != bVar7) {
      (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = bVar7;
      ovr_audio_panFromX();
      ovr_play_sfxU();
      ovc41_pluralSuffix();
      ovc41_pluralSuffix();
      ovr_agnt_statusText();
      ovr_agnt_statusText();
      ovr_ovc15_usesStshRealloc();
      pbVar9 = (byte *)ovr_stsprintf();
      ovr_uiNotify();
    }
  }
  return pbVar9;
}



/* 6a8f:22cb */

/* Resolves an agent's special attack (poison, blast spore disease, energy drain) and reports it. */

void __cdecl16far ovc41_specialAttack(agnt_t *agnt,int targetIndex,...)

{
  uint *puVar1;
  long lVar2;
  undefined4 uVar3;
  byte bVar4;
  undefined2 uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  uint16_t uVar9;
  uint8_t *puVar10;
  char *arg1;
  undefined2 unaff_DI;
  char *unaff_SS;
  uint16_t in_stack_00000004;
  undefined1 uVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  byte abilityIndex;
  undefined1 uVar14;
  uint8_t actorName;
  uint8_t targetName;
  uint8_t msg;
  undefined4 uStack_8;
  char cStack_3;
  
  abilityIndex = (byte)unaff_DI;
  uVar14 = (undefined1)((uint)unaff_DI >> 8);
  uVar11 = (undefined1)((ulong)agnt >> 8);
  uVar5 = ovc41_turnUndeadNotice((agnt_t *)CONCAT13(uVar11,CONCAT12((char)agnt,in_stack_00000004)));
  if ((((char)uVar5 == '\0') && (-1 < (long)agnt)) && ((*(uint16_t *)((uint8_t *)&(agnt) + 2)) < (int)(uint)AgntCount)) {
    lVar2 = (long)(*(uint16_t *)((uint8_t *)&(agnt) + 2)) * 0x34;
    arg1 = (char *)((ulong)lVar2 >> 0x10);
    iVar6 = (int)lVar2;
    uStack_8 = CONCAT22(0x1726,iVar6);
    if (*(char *)(iVar6 + 0x11) == '\0') {
      *(undefined1 *)(iVar6 + 4) = 0;
      *(undefined1 *)(iVar6 + 5) = 0;
    }
    if ((*(uint *)(in_stack_00000004 + 0x2b) & 8) == 0) {
      if (*(char *)(in_stack_00000004 + 0x2e) == '\0') {
        if ((*(char *)(in_stack_00000004 + 0xd) == '\x04') &&
           ((*(uint *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x3e) & 0x200) != 0)) {
          bVar4 = *(byte *)(in_stack_00000004 + 0x21);
          uVar5 = ovr_ovc27_breathHalfDamage
                            ((agnt_t *)CONCAT13(uVar14,CONCAT12(abilityIndex,0x1726)),(char)lVar2);
          pcVar7 = (char *)(uint)bVar4;
          if ((char)uVar5 != '\0') {
            pcVar7 = (char *)((int)(uint)bVar4 >> 1);
          }
        }
        else {
          bVar4 = ovr_manage_rollDice(*(char *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) +
                                               0x39),abilityIndex,
                                      *(undefined1 *)
                                       ((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x38));
          iVar6 = (uint)bVar4 +
                  (uint)*(byte *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x3a);
          bVar4 = ovr_agnt_compute9((agnt_t *)
                                    CONCAT13((char)((uint)iVar6 >> 8),
                                             CONCAT12((char)iVar6,(agnt_t *)agnt)),in_stack_00000004
                                   );
          arg1 = (char *)(iVar6 + (char)bVar4);
          pcVar7 = arg1;
        }
        if ((pcVar7 != (char *)0x0) &&
           ((*(uint *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x40) & 8) != 0)) {
          ovr_agnt_abilityModifier
                    (0,abilityIndex,
                     *(undefined1 *)((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0x1a));
        }
        uVar3 = *(undefined4 *)((int)uStack_8 + 0x1d);
        if (((*(uint *)((int)uVar3 + 0x3e) & 8) == 0) ||
           (bVar4 = ovr_agnt_compute9((agnt_t *)
                                      CONCAT13(uVar14,CONCAT12(abilityIndex,(agnt_t *)agnt)),
                                      (char)in_stack_00000004), '\0' < (char)bVar4)) {
          uVar3 = *(undefined4 *)((int)uStack_8 + 0x1d);
          if (((*(uint *)((int)uVar3 + 0x40) & 0x40) == 0) ||
             (bVar4 = ovr_agnt_compute9((agnt_t *)
                                        CONCAT13(uVar14,CONCAT12(abilityIndex,(agnt_t *)agnt)),
                                        (char)in_stack_00000004), '\x01' < (char)bVar4)) {
            uVar3 = *(undefined4 *)((int)uStack_8 + 0x1d);
            if (((*(uint *)((int)uVar3 + 0x3e) & 0x10) == 0) ||
               (*(char *)(in_stack_00000004 + 0xd) != '\x02')) {
              cStack_3 = ovc41_textParalyzed();
              if ((cStack_3 == '\0') &&
                 ((*(char *)(in_stack_00000004 + 0xd) == '\0' &&
                  ((*(uint *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x3e) & 2) != 0)))) {
                uVar8 = ovr_ovc27_rollToHitEntity
                                  (uStack_8 >> 0x10,abilityIndex,(undefined2)uStack_8);
                if ((uVar8 & 0xff) == 0) {
                  uVar13 = (undefined1)GSavedBlitSeg;
                  uVar12 = (undefined1)((uint)GSavedBlitSeg >> 8);
                  pcVar7 = ovr_agnt_statusText();
                  uVar11 = SUB21(arg1,0);
                  ovr_agnt_statusText();
                  puVar10 = ovr_ovc15_usesStshRealloc();
                  pcVar7 = ovr_stsprintf((char *)CONCAT22(0x70b5,unaff_SS),
                                         (char *)CONCAT22(puVar10,(char *)"puppetmaker" + 3),arg1,
                                         &msg,pcVar7,uVar11);
                  ovr_uiNotify((char *)CONCAT13(uVar12,CONCAT12(uVar13,arg1)),(uint16_t)pcVar7);
                  iVar6 = ovr_audio_panFromX((agnt_t *)
                                             CONCAT13(uVar14,CONCAT12(abilityIndex,(agnt_t *)agnt)),
                                             (char)in_stack_00000004);
                  ovr_play_sfxU(0,iVar6,0x55,(char)iVar6);
                  ovc41_settleAgentCombat
                            ((agnt_t *)
                             CONCAT13((char)(uStack_8 >> 8),CONCAT12((char)uStack_8,(agnt_t *)agnt))
                             ,(agnt_t *)CONCAT13(uVar14,CONCAT12(abilityIndex,(*(uint16_t *)((uint8_t *)&(uStack_8) + 2)))),
                             in_stack_00000004,(char)(uStack_8 >> 0x10));
                  cStack_3 = '\x01';
                }
              }
              if ((cStack_3 == '\0') &&
                 ((*(uint *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x3e) & 4) != 0)) {
                uVar8 = ovr_ovc27_rollToHitEntity
                                  (uStack_8 >> 0x10,abilityIndex,(undefined2)uStack_8);
                if (((uVar8 & 0xff) == 0) &&
                   (uVar3 = *(undefined4 *)((int)uStack_8 + 0x17),
                   (*(uint *)((int)uVar3 + 0x14) & 1) == 0)) {
                  uVar13 = (undefined1)GSavedBlitSeg;
                  uVar12 = (undefined1)((uint)GSavedBlitSeg >> 8);
                  pcVar7 = ovr_agnt_statusText();
                  uVar11 = SUB21(arg1,0);
                  ovr_agnt_statusText();
                  puVar10 = ovr_ovc15_usesStshRealloc();
                  pcVar7 = ovr_stsprintf((char *)CONCAT22(0x70c4,unaff_SS),
                                         (char *)CONCAT22(puVar10,(char *)"puppetmaker" + 3),arg1,
                                         &msg,pcVar7,uVar11);
                  ovr_uiNotify((char *)CONCAT13(uVar12,CONCAT12(uVar13,arg1)),(uint16_t)pcVar7);
                  iVar6 = ovr_audio_panFromX((agnt_t *)
                                             CONCAT13(uVar14,CONCAT12(abilityIndex,(*(uint16_t *)((uint8_t *)&(uStack_8) + 2)))),
                                             (char)uStack_8);
                  ovr_play_sfxU(0,iVar6,5,(char)iVar6);
                  uVar3 = *(undefined4 *)((int)uStack_8 + 0x17);
                  puVar1 = (uint *)((int)uVar3 + 0x14);
                  *puVar1 = *puVar1 | 1;
                }
              }
              if (((cStack_3 == '\0') &&
                  ((*(uint *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x3e) & 0x400) != 0))
                 && (uVar9 = ovr_randBelow(CONCAT11(uVar14,abilityIndex),
                                           *(undefined1 *)
                                            ((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0xe)),
                    (uVar9 & 0xff) == 0)) {
                uVar5 = ovr_ovc27_usesPlay_sfxU();
                uVar11 = (undefined1)GSavedBlitSeg;
                uVar13 = (undefined1)((uint)GSavedBlitSeg >> 8);
                if ((char)uVar5 == '\0') {
                  pcVar7 = ovr_agnt_statusText();
                  uVar12 = SUB21(arg1,0);
                  ovr_agnt_statusText();
                  puVar10 = ovr_ovc15_usesStshRealloc();
                  pcVar7 = ovr_stsprintf((char *)CONCAT22(0x7107,unaff_SS),
                                         (char *)CONCAT22(puVar10,(char *)"puppetmaker" + 3),arg1,
                                         &msg,pcVar7,uVar12);
                  ovr_uiNotify((char *)CONCAT13(uVar13,CONCAT12(uVar11,arg1)),(uint16_t)pcVar7);
                }
                else {
                  pcVar7 = ovr_agnt_statusText();
                  uVar12 = SUB21(arg1,0);
                  ovr_agnt_statusText();
                  puVar10 = ovr_ovc15_usesStshRealloc();
                  pcVar7 = ovr_stsprintf((char *)CONCAT22(0x70ec,unaff_SS),
                                         (char *)CONCAT22(puVar10,(char *)"puppetmaker" + 3),arg1,
                                         &msg,pcVar7,uVar12);
                  ovr_uiNotify((char *)CONCAT13(uVar13,CONCAT12(uVar11,arg1)),(uint16_t)pcVar7);
                }
              }
              if (((cStack_3 == '\0') &&
                  ((*(uint *)((int)*(undefined4 *)(in_stack_00000004 + 0x1d) + 0x3e) & 0x800) != 0))
                 && (uVar9 = ovr_randBelow(CONCAT11(uVar14,abilityIndex),
                                           *(undefined1 *)
                                            ((int)*(undefined4 *)(in_stack_00000004 + 0x17) + 0xe)),
                    (uVar9 & 0xff) == 0)) {
                uVar5 = ovr_ovc27_usesPlay_sfxU();
                uVar11 = (undefined1)GSavedBlitSeg;
                uVar14 = (undefined1)((uint)GSavedBlitSeg >> 8);
                if ((char)uVar5 == '\0') {
                  pcVar7 = ovr_agnt_statusText();
                  uVar13 = SUB21(arg1,0);
                  ovr_agnt_statusText();
                  puVar10 = ovr_ovc15_usesStshRealloc();
                  pcVar7 = ovr_stsprintf((char *)CONCAT22(0x7107,unaff_SS),
                                         (char *)CONCAT22(puVar10,(char *)"puppetmaker" + 3),arg1,
                                         &msg,pcVar7,uVar13);
                  ovr_uiNotify((char *)CONCAT13(uVar14,CONCAT12(uVar11,arg1)),(uint16_t)pcVar7);
                }
                else {
                  pcVar7 = ovr_agnt_statusText();
                  uVar13 = SUB21(arg1,0);
                  ovr_agnt_statusText();
                  puVar10 = ovr_ovc15_usesStshRealloc();
                  pcVar7 = ovr_stsprintf((char *)CONCAT22(0x7125,unaff_SS),
                                         (char *)CONCAT22(puVar10,(char *)"puppetmaker" + 3),arg1,
                                         &msg,pcVar7,uVar13);
                  ovr_uiNotify((char *)CONCAT13(uVar14,CONCAT12(uVar11,arg1)),(uint16_t)pcVar7);
                }
              }
            }
            else {
              uVar11 = (undefined1)GSavedBlitSeg;
              uVar13 = (undefined1)((uint)GSavedBlitSeg >> 8);
              pcVar7 = ovr_agnt_statusText();
              ovr_ovc15_usesStshRealloc((char *)CONCAT13(uVar13,CONCAT12(uVar11,arg1)),pcVar7);
              pcVar7 = ovr_stsprintf();
              ovr_uiNotify((char *)CONCAT13(uVar13,CONCAT12(uVar11,arg1)),(uint16_t)pcVar7);
              iVar6 = ovr_audio_panFromX((agnt_t *)
                                         CONCAT13(uVar14,CONCAT12(abilityIndex,(*(uint16_t *)((uint8_t *)&(uStack_8) + 2)))),
                                         (char)uStack_8);
              ovr_play_sfxU(0,iVar6,0x16,(char)iVar6);
            }
          }
          else {
            uVar11 = (undefined1)GSavedBlitSeg;
            uVar13 = (undefined1)((uint)GSavedBlitSeg >> 8);
            pcVar7 = ovr_agnt_statusText();
            ovr_ovc15_usesStshRealloc((char *)CONCAT13(uVar13,CONCAT12(uVar11,arg1)),pcVar7);
            pcVar7 = ovr_stsprintf();
            ovr_uiNotify((char *)CONCAT13(uVar13,CONCAT12(uVar11,arg1)),(uint16_t)pcVar7);
            iVar6 = ovr_audio_panFromX((agnt_t *)
                                       CONCAT13(uVar14,CONCAT12(abilityIndex,(*(uint16_t *)((uint8_t *)&(uStack_8) + 2)))),
                                       (char)uStack_8);
            ovr_play_sfxU(0,iVar6,0x16,(char)iVar6);
          }
        }
        else {
          uVar11 = (undefined1)GSavedBlitSeg;
          uVar13 = (undefined1)((uint)GSavedBlitSeg >> 8);
          pcVar7 = ovr_agnt_statusText();
          ovr_ovc15_usesStshRealloc((char *)CONCAT13(uVar13,CONCAT12(uVar11,arg1)),pcVar7);
          pcVar7 = ovr_stsprintf();
          ovr_uiNotify((char *)CONCAT13(uVar13,CONCAT12(uVar11,arg1)),(uint16_t)pcVar7);
          iVar6 = ovr_audio_panFromX((agnt_t *)
                                     CONCAT13(uVar14,CONCAT12(abilityIndex,(*(uint16_t *)((uint8_t *)&(uStack_8) + 2)))),
                                     (char)uStack_8);
          ovr_play_sfxU(0,iVar6,0x16,(char)iVar6);
        }
      }
      else {
        ovr_ovc27_textTakesHalfDamage3(agnt,in_stack_00000004);
      }
    }
    else {
      ovc41_textOnlyPlaceSingle
                ((agnt_t *)CONCAT13(uVar11,CONCAT12((char)agnt,in_stack_00000004)),(*(uint16_t *)((uint8_t *)&(agnt) + 2)));
    }
  }
  return;
}



/* 6a8f:297d */

/* Applies the special attack to an agent and then runs the follow-up tick. */

void __cdecl16far ovc41_resolveSpecialAttack(agnt_t *agnt,uint16_t param)

{
  int unaff_BP;
  
  ovc41_specialAttack((agnt_t *)CONCAT22(param,(*(uint16_t *)((uint8_t *)&(agnt) + 2))),unaff_BP,(agnt_t *)agnt);
  ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT22(unaff_BP,(*(uint16_t *)((uint8_t *)&(agnt) + 2))),(agnt_t *)agnt);
  return;
}



/* 6a8f:29a0 */

/* [R6] touches AgntCount */

void __cdecl16far ovc41_usesAgntCount3(void)

{
  uint unaff_SI;
  int iVar1;
  agnt_t *b;
  
  b = (agnt_t *)((ulong)unaff_SI << 0x10);
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    if (*(char *)(iVar1 * 0x34 + 0x2f) != '\0') {
      b = (agnt_t *)CONCAT22((int)((ulong)b >> 0x10),(agnt_t *)((int)&AgntAnms[0x75].halfWidth + 1))
      ;
      ovc41_settleAgentCombat((agnt_t *)((ulong)(uint)(iVar1 * 0x34) << 0x10),b,0);
    }
  }
  return;
}



/* 6a8f:29ea */

/* Returns the growth requirement for an agent's level, from the growth table or its type record. */

int __cdecl16far ovc41_growthForLevel(agnt_t *agnt,...)

{
  int iVar1;
  uint16_t unaff_SS;
  int in_stack_00000004;
  far_t dst;
  uint8_t growthMap;
  byte bStack_4;
  byte bStack_3;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&growthMap;
  F_SCOPY(far_from_u32((uint32_t)(0x24106e48)),dst);
  bStack_3 = *(byte *)(in_stack_00000004 + 0xd);
  if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bStack_3 * 0x95) == -1) {
    iVar1 = *(int *)((int)&worldMenuLabels[9].seg + 1 + (uint)bStack_3 * 0x95);
  }
  else {
    bStack_4 = *(byte *)(in_stack_00000004 + 0xf);
    if (bStack_4 < 0x16) {
      iVar1 = *(int *)(&growthMap + (uint)bStack_4 * 2);
    }
    else {
      iVar1 = (uint)bStack_4 * 0xfa + -0xabe;
    }
  }
  return iVar1;
}


