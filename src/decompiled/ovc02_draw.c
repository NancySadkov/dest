/*
 * ovc02_draw.c - recovered from STRONG.EXE
 * memory block: OVC02_draw.c
 * range: 2e25:0000 - 2e25:207f
 * functions: 23
 */
#include "recovered.h"


/* 2e25:0000 */

/* Draws the enabled menu row's proportional bar in the two special colours. */

void __cdecl16far draw_menuRowBar(int menuItem,uint16_t dstSeg,...)

{
  uint uVar1;
  uint y1;
  
  if ((menuItem < 5) && (((uint8_t *)MenuItemEnabled)[menuItem] != 0xff)) {
    uVar1 = ovr_attact_usesLDIV_at_((uint8_t)menuItem);
    uVar1 = ((uVar1 & 0xff) * 0x17) / 0x51;
    y1 = menuItem * 0xd + 0x91;
    if (uVar1 != 0) {
      ovr_driver_fillRect(0x124,y1,uVar1 + 0x123,y1,SpecialColors[6],dstSeg);
    }
    if (uVar1 < 0x16) {
      ovr_driver_fillRect(uVar1 + 0x124,y1,0x139,y1,SpecialColors[7],dstSeg);
    }
  }
  return;
}



/* 2e25:0098 */

/* [R4] calls ovr_driver_fillRect */

void __cdecl16far draw_usesFillRect2(uint value,int dstSeg,...)

{
  int iVar1;
  uint uVar2;
  uint uStack_4;
  
  if (GMenuItem < 5) {
    if (dstSeg == -0x6000) {
      draw_usesBlitLoadRleGfx2();
    }
    uStack_4 = ovr_attact_countPartyUnits(GMenuItem);
    iVar1 = ovr_ovc23_findClearColumn(GfxRndSeed,GfxRndSeed2);
    if (iVar1 < 0) {
      uStack_4 = 0;
    }
    if ((int)value < 0) {
      value = 0;
    }
    else if (uStack_4 < value) {
      value = uStack_4;
    }
    ((uint8_t *)menuItemRow)[GMenuItem] = (uint8_t)value;
    uVar2 = ovr_attact_usesLDIV_at_(GMenuItem);
    uVar2 = uVar2 & 0xff;
    if (uVar2 != 0) {
      ovr_driver_fillRect(0xea,0x6d,uVar2 + 0xe9,0x6f,SpecialColors[6],dstSeg);
    }
    if (uVar2 < 0x50) {
      ovr_driver_fillRect(uVar2 + 0xea,0x6d,0x139,0x6f,SpecialColors[7],dstSeg);
    }
    draw_menuRowBar((uint)GMenuItem,dstSeg);
  }
  return;
}



/* 2e25:018a */

/* [R7] body shape: compute */

int __cdecl16far draw_compute1(int menuIndex)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ((char)((undefined *)&menuCursorY)[menuIndex] * 0x12) / 0x39;
  iVar2 = ((char)((undefined *)&menuCursorX)[menuIndex] * 0x12) / 0x39;
  if ((iVar2 < 9) || (iVar2 + -8 <= iVar1)) {
    if ((iVar2 < 8) && (iVar1 < 8 - iVar2)) {
      iVar2 = iVar2 + 1;
    }
  }
  else {
    iVar2 = iVar2 + -1;
  }
  return iVar2 + 0x124;
}



/* 2e25:01eb */

/* [R7] body shape: compute */

int __cdecl16far draw_compute2(int menuIndex)

{
  return *(int *)(menuIndex * 2 + 0xda) +
         ((char)((undefined *)&menuCursorY)[menuIndex] * 0x12) / 0x39;
}



/* 2e25:0217 */

/* [R6] touches CrossBlitX, CrossBlitY */

void __cdecl16far draw_usesCrossBlitX(void)

{
  CrossBlitX = (uint)crossAgentIndex * 0x34 + 0x26;
  CrossBlitY = *(int *)(((uint)crossAgentIndex * 0x34 + 0x1a) * 2 + 0x34c) + -0xf;
  return;
}



/* 2e25:0245 */

/* [R7] body shape: compute */

uint __cdecl16far draw_compute3(int x,...)

{
  return (uint)((0x13f - x) * 0x80) / 0x140;
}



/* 2e25:025a */
void __cdecl16far draw_textTalkwin9Lbm(void)

{
  extern undefined2 _resetTextBlitCycle;   /* hand fix: no symbol exists */
  byte *pbVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  code *pcVar7;
  char cVar8;
  char cVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  char cVar16;
  byte bVar17;
  int iVar13;
  int iVar14;
  uint uVar15;
  char cVar18;
  byte bVar19;
  char cVar21;
  char cVar22;
  int iVar20;
  int in_CX;
  char cVar23;
  byte bVar24;
  char cVar26;
  undefined1 *puVar25;
  byte bVar27;
  byte bVar28;
  byte bVar29;
  uint16_t in_DX;
  char cVar30;
  char cVar31;
  char cVar34;
  char cVar35;
  byte *pbVar32;
  char *pcVar33;
  int iVar36;
  int iVar37;
  undefined1 *puVar38;
  int16_t *piVar39;
  undefined1 *puVar40;
  undefined2 *puVar41;
  int16_t *piVar42;
  undefined1 *puVar43;
  byte *pbVar44;
  ulong uVar45;
  undefined4 in_ESP;
  char *pcVar46;
  byte *pbVar47;
  undefined2 unaff_BP;
  undefined1 *puVar48;
  char *unaff_SI;
  char *pcVar49;
  int *piVar50;
  int unaff_DI;
  undefined2 uVar51;
  undefined2 uVar52;
  undefined2 unaff_SS;
  undefined2 in_FS;
  bool bVar53;
  byte in_AF;
  bool bVar54;
  bool bVar55;
  undefined4 uVar56;
  
  uVar52 = 0x2e25;
  iVar37 = (int)in_ESP;
  uVar51 = (undefined2)((ulong)in_ESP >> 0x10);
  piVar39 = (int16_t *)(iVar37 + -2);
  *(undefined2 *)(iVar37 + -2) = (uint16_t)unaff_BP;
  if (GameRunning != false) {
    return;
  }
  CrossBlitFlag = '\0';
  CrossBlitCount2 = 0;
  CrossBlitCount = 1;
  if (CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0) {
    *(uint16_t *)(iVar37 + -4) = CrossBlitPtr.seg;
    *(uint16_t *)(iVar37 + -6) = CrossBlitPtr.ofs;
    *(undefined2 *)(iVar37 + -8) = (uint16_t)(char *)0x2e25;
    uVar52 = 0x2337;
    puVar38 = (undefined1 *)(iVar37 + -10);
    *(undefined2 *)(iVar37 + -10) = (uint16_t)0xe4f0;
    ovr_stshFree(*(far_t far *)(iVar37 + -6));
    piVar39 = (int16_t *)(puVar38 + 8);
  }
  bVar29 = bigcompFrame;
  CrossBlitPtr.seg = 0;
  CrossBlitPtr.ofs = 0;
  if (MenuMode != '\x01') {
    if (MenuMode == '\x02') {
      if (GMenuItem == 5) {
        CrossBlitX = 0x128;
        CrossBlitY = 0x73;
      }
      else {
        *(undefined2 *)((int)piVar39 + -2) = (uint16_t)CONCAT11(0x24,GMenuItem);
        *(undefined2 *)((int)piVar39 + -4) = (uint16_t)uVar52;
        uVar52 = 0x2315;
        puVar40 = (undefined1 *)((int)piVar39 + -6);
        *(undefined2 *)((int)piVar39 + -6) = (uint16_t)0xe5d2;
        uVar15 = ovr_attact_usesLDIV_at_(*(uint8_t *)((int)piVar39 + -2));
        piVar39 = (int16_t *)(puVar40 + 6);
        CrossBlitX = (uVar15 & 0xff) + 0xe4;
        CrossBlitY = 0x68;
      }
    }
    else if (GMenuItem == 5) {
      CrossBlitX = 0x128;
      CrossBlitY = 0x73;
    }
    else if (GMenuItem < 5) {
      *(uint *)((int)piVar39 + -2) = (uint)GMenuItem;
      *(undefined2 *)((int)piVar39 + -4) = (uint16_t)uVar52;
      puVar41 = (undefined2 *)((int)piVar39 + -6);
      *(undefined2 *)((int)piVar39 + -6) = (uint16_t)0xe60d;
      iVar14 = draw_compute1(*(int *)((int)piVar39 + -2));
      CrossBlitX = iVar14 + -6;
      puVar41[2] = (uint)GMenuItem;
      puVar41[1] = uVar52;
      *puVar41 = 0xe620;
      iVar14 = draw_compute2(puVar41[2]);
      piVar39 = (int16_t *)((int)puVar41 + 6);
      CrossBlitY = iVar14 + -5;
    }
L_draw_2e25_025a_03D9:
    if (CrossBlitFlag == '\0') {
      piVar39[-1] = CrossBlitY + 9;
      piVar39[-2] = CrossBlitX + 0xd;
      piVar39[-3] = CrossBlitY;
      piVar39[-4] = CrossBlitX;
      piVar39[-5] = 0xa000;
      piVar39[-6] = 0;
      piVar39[-7] = uVar52;
      piVar42 = piVar39 + -8;
      piVar39[-8] = 0xe652;
      CrossBlitPtr.ofs =
           (uint16_t)
           ovr_stshRleCut((far_t far *)piVar39[-6],*(far_t far *)(piVar39 + -5),piVar39[-3],piVar39[-2],
                          piVar39[-1],*piVar39);
      CrossBlitPtr.seg = in_DX;
      *(undefined2 *)((int)piVar42 + 0xe) = (uint16_t)0xa000;
      *(int *)((int)piVar42 + 0xc) = CrossBlitX + CrossBlitY * 0x140;
      *(uint16_t *)((int)piVar42 + 10) = CrossBlitGfx.seg;
      *(uint16_t *)((int)piVar42 + 8) = CrossBlitGfx.ofs;
      *(undefined2 *)((int)piVar42 + 6) = (uint16_t)(char *)0x22d3;
      uVar52 = 0x22d3;
      puVar43 = (undefined1 *)((int)piVar42 + 4);
      *(undefined2 *)((int)piVar42 + 4) = (uint16_t)0xe689;
      ovr_blitLoadRleGfx(*(far_t far *)((int)piVar42 + 8),*(far_t far *)((int)piVar42 + 0xc));
      piVar39 = (int16_t *)(puVar43 + 0xc);
    }
    if (MouseMoved == 0) {
      *(int *)((int)piVar39 + -2) = CrossBlitX;
      *(undefined2 *)((int)piVar39 + -4) = (uint16_t)uVar52;
      pbVar44 = (byte *)((int)piVar39 + -6);
      *(undefined2 *)((int)piVar39 + -6) = (uint16_t)0xe69b;
      uVar15 = draw_compute3(*(int *)((int)piVar39 + -2));
      *(uint *)(pbVar44 + 4) = uVar15;
      *(undefined2 *)(pbVar44 + 2) = (uint16_t)1;
      *(undefined2 *)pbVar44 = 0;
      *(undefined2 *)(pbVar44 + -2) = (uint16_t)uVar52;
      *(undefined2 *)(pbVar44 + -4) = (uint16_t)0xe6a8;
      ovr_play_sfxU(*pbVar44,*(int *)(pbVar44 + 2),*(uint16_t *)(pbVar44 + 4));
    }
                    /* WARNING: Read-only address (ram,0x00026001) is written */
                    /* WARNING: Read-only address (ram,0x00033f01) is written */
    return;
  }
  if (GMenuItem != 5) {
    if (GMenuItem < 5) {
      CrossBlitX = (char)((undefined *)&menuCursorX)[GMenuItem] + 0xed;
      in_DX = 0x2410;
      CrossBlitY = (char)((undefined *)&menuCursorY)[GMenuItem] + 0x36;
    }
    goto L_draw_2e25_025a_03D9;
  }
  if (6 < bigcompFrame) goto L_draw_2e25_025a_03D9;
  pcVar33 = (char *)((uint)bigcompFrame * 2);
  pcVar33[(int)unaff_SI] = pcVar33[(int)unaff_SI] + bigcompFrame;
  { int _rep0; for (_rep0 = 0; _rep0 < 3182; _rep0++)
      pcVar33[(int)unaff_SI] = pcVar33[(int)unaff_SI] + bVar29;
  }
  pbVar1 = (byte *)(pcVar33 + (int)unaff_SI);
  bVar11 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar29;
  bVar10 = bVar29 + pcVar33[(int)unaff_SI];
  uVar12 = (uint)(byte)(bVar10 + CARRY1(bVar11,bVar29));
  uVar15 = (uint)(CARRY1(bVar29,pcVar33[(int)unaff_SI]) || CARRY1(bVar10,CARRY1(bVar11,bVar29)));
  uVar6 = uVar12 + *(uint *)(pcVar33 + (int)unaff_SI);
  bVar53 = CARRY2(uVar12,*(uint *)(pcVar33 + (int)unaff_SI)) || CARRY2(uVar6,uVar15);
  iVar14 = uVar6 + uVar15;
  bVar29 = (byte)iVar14;
  iVar14 = CONCAT11((char)((uint)iVar14 >> 8),bVar29 + bVar53) + 0x1600 +
           (uint)CARRY1(bVar29,bVar53);
  cVar30 = (char)pcVar33;
  pcVar33[(int)unaff_SI] = pcVar33[(int)unaff_SI] + cVar30;
  pcVar33[unaff_DI] = pcVar33[unaff_DI] + cVar30;
  cVar34 = (char)((uint)pcVar33 >> 8);
  *(char *)(iVar37 + -2 + unaff_DI) = *(char *)(iVar37 + -2 + unaff_DI) + cVar34;
  cVar9 = (char)iVar14;
  unaff_SI[iVar37 + -2] = unaff_SI[iVar37 + -2] + cVar9;
  *unaff_SI = *unaff_SI + cVar9;
  pcVar46 = (char *)(iVar37 + -1);
  *pcVar46 = *pcVar46 + cVar9;
  pcVar49 = (char *)(unaff_DI + 1);
  (pcVar33 + 1)[(int)unaff_SI] = (pcVar33 + 1)[(int)unaff_SI] + (char)in_CX;
  cVar35 = (char)(in_CX + -1);
  pcVar46[(int)unaff_SI] = pcVar46[(int)unaff_SI] + cVar35;
  *pcVar33 = *pcVar33 + (char)((uint)iVar14 >> 8);
  *(undefined2 *)((int)piVar39 + -2) = (uint16_t)(char *)0x24ae;
  cVar8 = (char)((uint)(in_CX + -1) >> 8);
  pcVar46[(int)unaff_SI] = pcVar46[(int)unaff_SI] + cVar8;
  _resetTextBlitCycle = *(int *)(pcVar33 + (int)unaff_SI) * 0x6c;
  *pcVar49 = *pcVar49 + cVar8;
  piVar5 = (int *)(unaff_SI + 1);
  out(*unaff_SI,in_DX);
  *pcVar33 = *pcVar33 + cVar8;
  pcVar33[(int)piVar5] = (char)_resetTextBlitCycle;
  cVar18 = (char)in_DX;
  cVar9 = cVar18 * '\x02';
  cVar30 = cVar30 + cVar9;
  cVar16 = (char)((uint)_resetTextBlitCycle >> 8) + cVar9;
  cVar21 = cVar8 + cVar35 + cVar9;
  cVar8 = (char)_resetTextBlitCycle + cVar18 + cVar30;
  cVar23 = cVar9 + cVar30;
                    /* WARNING: Read-only address (ram,0x00033f01) is written */
  cRam00033f01 = cVar8 + '\x10';
  cVar18 = cVar35 + cVar18 + cVar30 + cVar21;
  cVar31 = cVar30 + cVar16 + cVar21;
  cVar22 = cVar21 + cVar16;
  cVar26 = (char)(in_DX >> 8) + cVar35 + cVar9 + cVar16 + cVar31;
  cVar35 = cVar34 + cVar35 + cVar9 + cVar30 + cVar21 * '\x04' + cVar16 * '\x02';
  pcVar33 = (char *)CONCAT11(cVar35,cVar31);
  *pcVar33 = *pcVar33 + cVar23;
  *(char **)(pcVar33 + (int)piVar5) = pcVar33 + *(int *)(pcVar33 + (int)piVar5);
  pcVar46 = pcVar46 + (int)pcVar49;
  *pcVar49 = *pcVar49 + cVar31;
                    /* WARNING: Read-only address (ram,0x00026001) is written */
  (*(uint16_t *)((uint8_t *)&(s_halfling_lodge_2410_1efd) + 4)) = (uint16_t)pcVar33 + 0x696c;
  piVar50 = (int *)(pcVar49 + (int)pcVar46);
  cVar35 = cVar35 + cVar22;
  iVar14 = CONCAT11(cVar35,cVar31);
  *(char *)piVar5 = (char)*piVar5 + cVar18;
  *piVar50 = *piVar50 + CONCAT11(cVar22,cVar18);
  (*(uint16_t *)((uint8_t *)&(AgntAnms[0x30]) + 9)) = (uint16_t)(*(uint16_t *)((uint8_t *)&(AgntAnms[0x30]) + 9)) + CONCAT11(cVar22,cVar18);
  piVar2 = (int *)(iVar14 + (int)piVar5);
  *piVar2 = *piVar2 + CONCAT11(cVar26,cVar23);
  piVar2 = (int *)(iVar14 + (int)piVar50);
  *piVar2 = *piVar2 + CONCAT11(cVar26,cVar23);
  cVar35 = cVar35 + cVar26 * '\x02';
  iVar20 = CONCAT11(cVar35,cVar31);
  cVar9 = cVar8 + cVar22 + cVar35;
  iVar14 = CONCAT11(cVar16 * '\x02',cVar9);
  *(char *)(iVar20 + (int)piVar50) = *(char *)(iVar20 + (int)piVar50) + cVar22 + cVar26;
  *(char **)(pcVar46 + (int)piVar5) = pcVar46 + *(int *)(pcVar46 + (int)piVar5);
  puVar25 = (undefined1 *)((int)piVar39 + -2) + (int)piVar5 + CONCAT11(cVar26 * '\x02',cVar23);
  *(char *)((int)piVar50 + 1) = *(char *)((int)piVar50 + 1) + cVar9;
  *(int *)(iVar20 + (int)piVar50) = *(int *)(iVar20 + (int)piVar50) - iVar14;
  *(int *)(iVar20 + (int)piVar50) = *(int *)(iVar20 + (int)piVar50) - iVar14;
  *(int *)(iVar20 + 1) = *(int *)(iVar20 + 1) + CONCAT11(cVar22 + cVar26,cVar18 + cVar35);
  *(int *)((undefined1 *)((int)piVar39 + (int)piVar5) + -4) = iVar14;
  (pcVar46 + (int)unaff_SI)[1] = (pcVar46 + (int)unaff_SI)[1] + (char)puVar25;
  *(int *)((undefined1 *)((int)piVar39 + (int)piVar5) + -6) = iVar20;
  *piVar5 = (int)(puVar25 + *piVar5);
  *(char **)((undefined1 *)((int)piVar39 + (int)piVar5) + -8) = pcVar46;
  *(undefined1 **)(pcVar46 + 1) = puVar25 + *(int *)(pcVar46 + 1);
  *(char **)((undefined1 *)((int)piVar39 + (int)piVar5) + -10) =
       (char *)((int)piVar50 + (int)pcVar46);
  *(int *)(unaff_SI + iVar20 + 1) = *(int *)(unaff_SI + iVar20 + 1) + iVar20;
  *(int *)(pcVar46 + (int)unaff_SI + 1) = *(int *)(pcVar46 + (int)unaff_SI + 1) + iVar20;
  iVar14 = *(int *)((undefined1 *)((int)piVar39 + (int)piVar5) + -8);
  *piVar5 = *piVar5 + iVar14;
  *(int *)(*(int *)((undefined1 *)((int)piVar39 + (int)piVar5) + -6) + 1) =
       *(int *)(*(int *)((undefined1 *)((int)piVar39 + (int)piVar5) + -6) + 1) + iVar14;
  *(undefined1 **)(unaff_SI + iVar14 + 1) =
       (undefined1 *)((int)piVar39 + -2) + (int)piVar5 + *(int *)(unaff_SI + iVar14 + 1);
  piVar50 = *(int **)((undefined1 *)((int)piVar39 + -2) + (int)piVar5);
  puVar48 = (undefined1 *)*(undefined2 *)((int)piVar39 + (int)piVar5);
  pbVar47 = *(byte **)((undefined1 *)((int)piVar39 + (int)piVar5) + 2);
  pbVar32 = *(byte **)((undefined1 *)((int)piVar39 + (int)piVar5) + 6);
  uVar52 = *(undefined2 *)((undefined1 *)((int)piVar39 + (int)piVar5) + 8);
  iVar20 = *(int *)((undefined1 *)((int)piVar39 + (int)piVar5) + 10);
  uVar15 = *(uint *)((undefined1 *)((int)piVar39 + (int)piVar5) + 0xc);
  *(undefined1 **)(pbVar47 + (int)puVar48 + 1) =
       (undefined1 *)((int)piVar39 + (int)piVar5) + *(int *)(pbVar47 + (int)puVar48 + 1) + 0xe;
  puVar3 = (uint *)(pbVar32 + (int)piVar50);
  iVar14 = (uVar15 & 3) - (*puVar3 & 3);
  *puVar3 = *puVar3 + (uint)(0 < iVar14) * iVar14;
  *(int *)((int)piVar50 + 1) =
       (int)((undefined1 *)((int)piVar39 + (int)piVar5) + *(int *)((int)piVar50 + 1) + 0xe);
  *(undefined1 **)(pbVar32 + 1) =
       (undefined1 *)CONCAT22(uVar51,(undefined1 *)((int)piVar39 + (int)piVar5) + 0xe) +
       *(long *)(pbVar32 + 1);
  *(char **)((undefined1 *)((int)piVar39 + (int)piVar5) + 0xc) = (char *)0x24af;
  *(byte **)(pbVar47 + (int)puVar48 + 1) = pbVar47 + *(int *)(pbVar47 + (int)puVar48 + 1);
  uVar15 = *(int *)(pbVar32 + (int)piVar50) * 0x6c;
  *(int *)((int)piVar50 + 1) = (int)(pbVar47 + *(int *)((int)piVar50 + 1));
  puVar25 = puVar48 + 1;
  out(*puVar48,uVar52);
  pbVar1 = pbVar32 + 1;
  iVar14 = *(int *)pbVar1;
  *(byte **)pbVar1 = pbVar47 + *(int *)pbVar1;
  cVar8 = (char)uVar15;
  cVar9 = cVar8;
  if (SCARRY2(iVar14,(int)pbVar47)) {
    puVar3 = (uint *)(pbVar47 + (int)puVar25 + 1);
    uVar6 = *puVar3;
    *puVar3 = (uint)(puVar25 + *puVar3);
    uVar12 = *puVar3;
                    /* WARNING: Read-only address (ram,0x00026001) is written */
                    /* WARNING: Read-only address (ram,0x00033f01) is written */
    if (CARRY2(uVar6,(uint)puVar25)) goto code_r0x000219de;
    puVar3 = (uint *)((int)piVar50 + 1);
    bVar53 = CARRY2(*puVar3,(uint)puVar25);
    uVar6 = *puVar3;
    *puVar3 = (uint)(puVar25 + *puVar3);
    uVar12 = *puVar3;
    bVar55 = *puVar3 == 0;
    uVar4 = *puVar3;
    if (!bVar53 && !bVar55) goto code_r0x000219e4;
    puVar3 = (uint *)(pbVar32 + (int)puVar25 + 1);
    bVar55 = SCARRY2(*puVar3,(int)piVar50);
    *puVar3 = *puVar3 + (int)piVar50;
    bVar53 = (int)*puVar3 < 0;
    uVar4 = *puVar3;
code_r0x000219e8:
    bVar54 = true;
    if (!bVar53) {
      pbVar1 = pbVar47 + (int)piVar50 + 1;
      bVar55 = SCARRY2(*(int *)pbVar1,(int)piVar50);
      *(int *)pbVar1 = *(int *)pbVar1 + (int)piVar50;
      bVar54 = *(int *)pbVar1 < 0;
      goto code_r0x000219ee;
    }
code_r0x000219ea:
    bVar53 = false;
    if ((POPCOUNT(uVar4 & 0xff) & 1U) != 0) goto code_r0x000219ec;
    piVar2 = (int *)(puVar48 + 2);
    bVar55 = SCARRY2(*piVar2,(int)piVar50);
    *piVar2 = *piVar2 + (int)piVar50;
    bVar54 = *piVar2 < 0;
  }
  else {
    puVar3 = (uint *)(pbVar47 + (int)piVar50 + 1);
    *puVar3 = (uint)(puVar25 + *puVar3);
    uVar12 = *puVar3;
code_r0x000219de:
    if (uVar12 == 0) {
      puVar3 = (uint *)(pbVar47 + 1);
      bVar53 = CARRY2(*puVar3,(uint)puVar25);
      uVar6 = *puVar3;
      *puVar3 = (uint)(puVar25 + *puVar3);
      uVar12 = *puVar3;
      bVar55 = *puVar3 == 0;
      uVar4 = *puVar3;
code_r0x000219e4:
      if (bVar53 || bVar55) goto code_r0x000219e6;
      puVar3 = (uint *)(pbVar32 + (int)piVar50 + 1);
      bVar55 = SCARRY2(*puVar3,(int)piVar50);
      *puVar3 = *puVar3 + (int)piVar50;
      bVar54 = (int)*puVar3 < 0;
      uVar4 = *puVar3;
      goto code_r0x000219ea;
    }
    puVar3 = (uint *)(pbVar32 + 1);
    uVar6 = *puVar3;
    *puVar3 = (uint)(puVar25 + *puVar3);
    uVar12 = *puVar3;
    uVar4 = *puVar3;
code_r0x000219e6:
    bVar55 = SCARRY2(uVar6,(int)puVar25);
    bVar53 = false;
    if (-1 < (int)uVar12) goto code_r0x000219e8;
    puVar3 = (uint *)(pbVar47 + (int)puVar25 + 1);
    bVar55 = SCARRY2(*puVar3,(int)piVar50);
    *puVar3 = *puVar3 + (int)piVar50;
    bVar54 = (int)*puVar3 < 0;
    bVar53 = (POPCOUNT(*puVar3 & 0xff) & 1U) == 0;
code_r0x000219ec:
    if (!bVar53) {
      *(int *)((int)piVar50 + 1) = *(int *)((int)piVar50 + 1) + (int)piVar50;
      goto code_r0x000219f5;
    }
code_r0x000219ee:
    if (bVar55 != bVar54) {
      *(undefined1 **)(pbVar47 + (int)puVar25 + 1) =
           (undefined1 *)((int)piVar39 + (int)piVar5) + *(int *)(pbVar47 + (int)puVar25 + 1) + 0xc;
      cVar9 = (*(uint8_t *)((uint8_t *)&(_DATA) + 1));
      goto code_r0x000219f5;
    }
  }
  if (bVar55 == bVar54) {
    *(uint *)(pbVar32 + (int)puVar25) = *(int *)(pbVar32 + (int)puVar25) + uVar15;
    cVar9 = (*(uint8_t *)((uint8_t *)&(_DATA) + 1));
  }
code_r0x000219f5:
  (*(uint8_t *)((uint8_t *)&(_DATA) + 1)) = cVar9;
  { int _rep1; for (_rep1 = 0; _rep1 < 143; _rep1++)
      pbVar32[(int)puVar25] = pbVar32[(int)puVar25] + cVar8;
  }
  pbVar32[(int)puVar25] = pbVar32[(int)puVar25] + cVar8 + (char)uVar52;
  bVar10 = __C0_ASM_CopyRight[0xb];
  (pbVar32 + (int)puVar25)[0x1f] = (pbVar32 + (int)puVar25)[0x1f] + __C0_ASM_CopyRight[0xb];
  pbVar32[(int)puVar25] = pbVar32[(int)puVar25] + bVar10;
  pbVar32[(int)puVar25] = pbVar32[(int)puVar25] + bVar10;
  pbVar1 = pbVar32 + (int)puVar25;
  bVar29 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar10;
  bVar17 = (byte)((uVar15 >> 8) << 1) | CARRY1(bVar29,bVar10);
  (pbVar32 + (int)puVar25)[0x3a9] = (pbVar32 + (int)puVar25)[0x3a9] + bVar10;
  (pbVar32 + (int)puVar25)[0x7e] = (pbVar32 + (int)puVar25)[0x7e] + bVar10;
  *(byte **)((undefined1 *)((int)piVar39 + (int)piVar5) + 0xc) = pbVar32;
  uVar51 = *(undefined2 *)((undefined1 *)((int)piVar39 + (int)piVar5) + 0xc);
  uVar45 = ZEXT24((undefined1 *)((int)piVar39 + (int)piVar5) + 0xe);
  bVar11 = bVar10 * '\x02';
  bVar29 = 9 < (bVar11 & 0xf) | in_AF;
  cVar9 = bVar11 + bVar29 * '\x06' + (0x99 < bVar11 || CARRY1(bVar10,bVar10)) * '`';
  *(uint *)(pbVar32 + (int)puVar25) = *(uint *)(pbVar32 + (int)puVar25) | CONCAT11(bVar17,cVar9);
  (pbVar32 + (int)puVar25)[-0x2f] = (pbVar32 + (int)puVar25)[-0x2f] + cVar9;
  pbVar47[0xe] = pbVar47[0xe] + bVar17;
  (pbVar47 + (int)puVar25)[0x10] = (pbVar47 + (int)puVar25)[0x10];
  pbVar32[0x12] = pbVar32[0x12];
  pbVar32[(int)puVar25] = pbVar32[(int)puVar25] + (cVar9 + 1U & 0x14);
  do {
    pcVar7 = (code *)swi(0x17);
    uVar56 = (*pcVar7)();
    bVar10 = (byte)uVar56;
    (pbVar32 + (int)puVar25)[0x19a2] = (pbVar32 + (int)puVar25)[0x19a2] + bVar10;
    pbVar1 = pbVar32 + (int)puVar25 + 0x77;
    bVar11 = *pbVar1;
    *pbVar1 = *pbVar1 + bVar10;
    iVar14 = ((int)uVar56 - *(int *)(pbVar32 + (int)puVar25)) - (uint)CARRY1(bVar11,bVar10);
    bVar19 = (byte)iVar20;
    puVar48[0x1e] = puVar48[0x1e] + bVar19;
    bVar10 = (char)iVar14 * '\x02';
    *pbVar32 = *pbVar32 & (byte)pbVar32;
    (pbVar32 + (int)puVar25)[0x20f5] = (pbVar32 + (int)puVar25)[0x20f5] + bVar10;
    (pbVar32 + (int)puVar25)[-0x36] = (pbVar32 + (int)puVar25)[-0x36] + bVar10;
    bVar11 = pbVar32[(int)puVar25];
    pbVar32[0x24] = pbVar32[0x24] + (byte)pbVar32;
    (pbVar47 + (int)piVar50)[0x26] = (pbVar47 + (int)piVar50)[0x26];
    (pbVar32 + (int)puVar25)[0x28] = (pbVar32 + (int)puVar25)[0x28];
    bVar27 = (byte)((ulong)uVar56 >> 0x18);
    bVar24 = (char)((ulong)uVar56 >> 0x10) + bVar27;
    uVar15 = (CONCAT11((char)((uint)iVar14 >> 8),bVar10 & bVar11) + -0x29) -
             *(int *)(pbVar32 + (int)puVar25);
    bVar28 = bVar27 << 5 | bVar27 >> 3;
    bVar11 = (byte)uVar15;
    (pbVar32 + (int)puVar25)[0x2f9b] = (pbVar32 + (int)puVar25)[0x2f9b] + bVar11;
    (pbVar32 + (int)puVar25)[0x70] = (pbVar32 + (int)puVar25)[0x70] + bVar11;
    *(uint *)(pbVar32 + (int)puVar25) = *(uint *)(pbVar32 + (int)puVar25) ^ uVar15;
    *(char *)((int)piVar50 + 0x33) = *(char *)((int)piVar50 + 0x33) + bVar11;
    bVar10 = bVar11 * '\x02';
    *piVar50 = (*piVar50 - (int)puVar25) - (uint)CARRY1(bVar11,bVar11);
    pbVar32[(int)puVar25] = pbVar32[(int)puVar25] + bVar10;
    pbVar32[(int)puVar25] = pbVar32[(int)puVar25] + bVar10;
    pbVar32[(int)puVar25] = pbVar32[(int)puVar25] + bVar10;
    pbVar32[(int)puVar25] = pbVar32[(int)puVar25] + bVar10;
    bVar17 = (char)(uVar15 >> 8) + bVar10;
    *(uint *)(pbVar32 + (int)puVar25) = *(uint *)(pbVar32 + (int)puVar25) | CONCAT11(bVar17,bVar10);
    (pbVar32 + (int)puVar25)[0x13] = (pbVar32 + (int)puVar25)[0x13] + bVar19;
    pbVar1 = pbVar32 + (int)puVar25;
    bVar11 = *pbVar1;
    *pbVar1 = *pbVar1 + bVar24;
    bVar29 = 9 < (bVar10 & 0xf) | bVar29;
    cVar9 = bVar10 + bVar29 * '\x06' + (0x99 < bVar10 || CARRY1(bVar11,bVar24)) * '`';
    pbVar32[(int)puVar25] = pbVar32[(int)puVar25] + cVar9;
    *pbVar47 = *pbVar47 & bVar19;
    (pbVar32 + (int)puVar25)[-100] = (pbVar32 + (int)puVar25)[-100] + cVar9;
    pbVar32[(int)puVar25] = pbVar32[(int)puVar25] + cVar9;
    bVar11 = cVar9 + bVar28 + pbVar32[(int)puVar25];
    iVar20 = iVar20 + -2;
  } while (iVar20 != 0 && bVar11 != 0);
  iVar14 = CONCAT11((byte)((uint)iVar20 >> 9),(byte)iVar20);
  iVar36 = (int)uVar45;
  *(undefined2 *)(iVar36 + -2) = (uint16_t)uVar51;
  bVar10 = bVar11 * '\x02';
  *(uint *)(pbVar32 + (int)puVar25) =
       *(uint *)(pbVar32 + (int)puVar25) |
       CONCAT11(bVar17,bVar10 + (9 < (bVar10 & 0xf) | bVar29) * '\x06' +
                       (0x99 < bVar10 || CARRY1(bVar11,bVar11)) * '`');
  cVar9 = (char)AgntAnms[0x25].y;
  uVar51 = *(undefined2 *)(pbVar32 + (int)puVar25);
  (pbVar32 + (int)puVar25)[0x1005] = (pbVar32 + (int)puVar25)[0x1005] + bVar24;
  (pbVar32 + (int)puVar25)[0x124f] = (pbVar32 + (int)puVar25)[0x124f] + cVar9;
  pbVar1 = pbVar32 + (int)puVar25 + -0x67;
  bVar29 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar28;
  uVar15 = CONCAT11(bVar17 | (byte)((uint)uVar51 >> 8),cVar9 + CARRY1(bVar29,bVar28));
  *(uint *)(iVar36 + -4) = uVar15;
  *(int *)(iVar36 + -6) = iVar14;
  *(undefined2 *)(iVar36 + -8) = (uint16_t)CONCAT11(bVar28,bVar24);
  *(undefined2 *)(iVar36 + -10) = (uint16_t)pbVar32;
  *(int *)(iVar36 + -0xc) = iVar36 + -2;
  *(undefined2 *)(iVar36 + -0xe) = (uint16_t)pbVar47;
  *(uint *)(iVar36 + -0x10) = (uint)puVar25;
  *(undefined2 *)(iVar36 + -0x12) = (uint16_t)piVar50;
  if (iVar14 != 0) {
    pbVar1 = pbVar32 + (int)puVar25 + 0x2d;
    bVar29 = *pbVar1;
    *pbVar1 = *pbVar1 + bVar24;
    puVar3 = (uint *)(pbVar32 + (int)puVar25);
    uVar6 = *puVar3;
    uVar12 = *puVar3;
    *puVar3 = (uVar12 - uVar15) - (uint)CARRY1(bVar29,bVar24);
    iVar13 = uVar15 + 1;
    if ((uVar15 <= uVar6 && (uint)CARRY1(bVar29,bVar24) <= uVar12 - uVar15) && iVar13 != 0) {
      iVar13 = iVar13 - *(int *)(pbVar32 + (int)puVar25);
      bVar29 = (bVar27 >> 3) << 5 | bVar28 >> 3;
      (pbVar32 + (int)puVar25)[0x3010] = (pbVar32 + (int)puVar25)[0x3010] + bVar29;
      (pbVar32 + (int)puVar25)[0x325a] =
           (pbVar32 + (int)puVar25)[0x325a] + (char)((uint)iVar13 >> 8);
      (pbVar32 + (int)puVar25)[0x34a4] = (pbVar32 + (int)puVar25)[0x34a4] + bVar24;
      (pbVar32 + (int)puVar25)[0x36ee] = (pbVar32 + (int)puVar25)[0x36ee] + (char)iVar13;
      (pbVar32 + (int)puVar25)[0x38] = (pbVar32 + (int)puVar25)[0x38] + bVar29;
      *(int *)(iVar36 + -0x14) = iVar13;
      *(int *)(iVar36 + -0x16) = iVar14;
      *(undefined2 *)(iVar36 + -0x18) = (uint16_t)CONCAT11(bVar29,bVar24);
      *(undefined2 *)(iVar36 + -0x1a) = (uint16_t)pbVar32;
      *(int *)(iVar36 + -0x1c) = iVar36 + -0x12;
      *(undefined2 *)(iVar36 + -0x1e) = (uint16_t)pbVar47;
      *(uint *)(iVar36 + -0x20) = (uint)puVar25;
      *(undefined2 *)(iVar36 + -0x22) = (uint16_t)piVar50;
      *(int *)(iVar36 + -0x24) = iVar13;
      pcVar7 = (code *)swi(3);
      (*pcVar7)();
      return;
    }
    pbVar32[(int)puVar25] = pbVar32[(int)puVar25] + bVar28;
    *piVar50 = *piVar50;
    pbVar47[(int)piVar50] = pbVar47[(int)piVar50] & (byte)iVar20;
    pbVar32[(int)puVar25] = pbVar32[(int)puVar25] & (byte)iVar13;
    *(byte *)(piVar50 + 0x11) = (char)piVar50[0x11] + bVar24;
    pbVar32[(int)puVar25] = pbVar32[(int)puVar25] + (byte)iVar13;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* 2e25:046b */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far draw_usesBlitLoadRleGfx(void)

{
  far_t gfx;
  far_t dst;
  far_t dst_00;
  uint8_t rect;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  uint16_t uStack_4;
  
  if (CrossBlitFlag == '\0') {
    if ((((CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0) &&
         (CrossBlitCount2 = CrossBlitCount2 + 1, 2 < CrossBlitCount2)) &&
        (CrossBlitCount2 = 0, CrossBlitCount != 0)) && (CrossBlitCount < 5)) {
      rect = CrossBlitX;
      iStack_a = CrossBlitY;
      iStack_8 = CrossBlitX + *(int far *)((uint8_t far *)MK_FP(CrossBlitPtr.seg, CrossBlitPtr.ofs) +  5) + -1;
      iStack_6 = CrossBlitY + *(int far *)((uint8_t far *)MK_FP(CrossBlitPtr.seg, CrossBlitPtr.ofs) +  7) + -1;
      uStack_4 = 0xa000;
      ovr_miceRestoreArea((brect_t *)&rect);
      dst.seg = 0xa000;
      dst.ofs = CrossBlitX + CrossBlitY * 0x140;
      ovr_blitLoadRleGfx(CrossBlitPtr,dst);
      if (CrossBlitCount < 4) {
        dst_00.seg = 0xa000;
        dst_00.ofs = CrossBlitX + CrossBlitY * 0x140;
        gfx.seg = *(uint16_t *)((int)&CrossBlitGfx.seg + (uint)CrossBlitCount * 4);
        gfx.ofs = ((far_t *)&CrossBlitGfx + CrossBlitCount)->ofs;
        ovr_blitLoadRleGfx(gfx,dst_00);
      }
      ovr_miceBlitRect((brect_t *)&rect);
      CrossBlitCount = CrossBlitCount + 1;
    }
  }
  return;
}



/* 2e25:0573 */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far draw_usesBlitLoadRleGfx2(void)

{
  far_t gfx;
  far_t dst;
  far_t handle;
  
  if ((CrossBlitCount != '\0') && (CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0)) {
    CrossBlitCount = '\0';
    dst.seg = 0xa000;
    dst.ofs = CrossBlitX + CrossBlitY * 0x140;
    gfx.seg = CrossBlitPtr.seg;
    gfx.ofs = CrossBlitPtr.ofs;
    ovr_blitLoadRleGfx(gfx,dst);
    handle.seg = CrossBlitPtr.seg;
    handle.ofs = CrossBlitPtr.ofs;
    ovr_stshFree(handle);
    CrossBlitPtr.seg = 0;
    CrossBlitPtr.ofs = 0;
  }
  return;
}



/* 2e25:05e9 */
void __cdecl16far draw_usesPlay_sfx(void)

{
  char *pcVar1;
  char cVar2;
  uint16_t x;
  ulong *puVar3;
  uint uVar4;
  undefined2 uVar5;
  uint uVar6;
  word count;
  int in_DX;
  undefined2 unaff_SI;
  uint uVar7;
  ulong prevTick;
  uint16_t outFlag;
  agnt_t *in_stack_0000fffa;
  byte bStack_4;
  
  prevTick = CONCAT22(unaff_SI,(*(uint16_t *)((uint8_t *)&(recordUpdateTick) + 2)));
  puVar3 = ovr_attact_usesBDADailyTimeCounter((ulong *)recordUpdateTick,prevTick);
  if ((in_DX != 0) || ((ulong *)((int)(undefined4 *)&_DATA + 1U) < puVar3)) {
    (*(uint16_t *)((uint8_t *)&(recordUpdateTick) + 2)) = (uint16_t)*(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    (*(uint16_t *)((uint8_t *)&(recordUpdateTick))) = (uint16_t)*(ulong * far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
    outFlag = 0;
    for (uVar7 = 0; uVar6 = (uint)(prevTick >> 0x10), uVar7 < GRecordCount; uVar7 = uVar7 + 1) {
      *(int *)(uVar7 * 0x12) = *(int *)(uVar7 * 0x12) + 1;
      if (20000 < *(uint *)(uVar7 * 0x12)) {
        *(undefined2 *)(uVar7 * 0x12) = (uint16_t)0x14;
      }
      cVar2 = *(char *)(uVar7 * 0x12 + 0xe);
      if (cVar2 == '\0') {
        uVar4 = *(byte *)(uVar7 * 0x12 + 0x11) + 1;
        prevTick = CONCAT22(uVar6,uVar4);
        if ((uVar4 < *(byte *)(uVar7 * 0x12 + 6)) && (0x13 < *(uint *)(uVar7 * 0x12))) {
          *(undefined2 *)(uVar7 * 0x12) = (uint16_t)0;
          pcVar1 = (char *)(uVar7 * 0x12 + 0x11);
          *pcVar1 = *pcVar1 + '\x01';
        }
      }
      else if (cVar2 == '\x01') {
        uVar4 = *(byte *)(uVar7 * 0x12 + 0x11) + 1;
        prevTick = CONCAT22(uVar6,uVar4);
        if (uVar4 < *(byte *)(uVar7 * 0x12 + 6)) {
          if (0x13 < *(uint *)(uVar7 * 0x12)) {
            *(undefined2 *)(uVar7 * 0x12) = (uint16_t)0;
            pcVar1 = (char *)(uVar7 * 0x12 + 0x11);
            *pcVar1 = *pcVar1 + '\x01';
          }
        }
        else {
          *(undefined1 *)(uVar7 * 0x12 + 0xe) = 2;
          x = *(uint16_t *)(uVar7 * 0x12 + 2);
          in_stack_0000fffa = (agnt_t *)*(int *)(uVar7 * 0x12 + 4);
          uVar5 = ovr_ovc23_isCursorAt(x,(int)in_stack_0000fffa);
          if (((char)uVar5 != '\0') && (*(char *)(uVar7 * 0x12 + 8) != '\0')) {
            ovr_play_sfx(80,0);
          }
          bStack_4 = (byte)x;
          uVar5 = ovr_ovc22_usesGOngoingBattle(bStack_4,(byte)in_stack_0000fffa);
          if ((char)uVar5 != '\0') {
            outFlag = CONCAT11(1,(char)outFlag);
          }
          prevTick = (ulong)uVar6 << 0x10;
          uVar6 = ovr_ovc23_compute1(x,(int)in_stack_0000fffa,*(byte *)(uVar7 * 0x12 + 8),
                                     *(uint8_t *)(uVar7 * 0x12 + 9));
          if ((uVar6 & 0xff) == 0) {
            prevTick = prevTick & 0xffff0000;
            ovr_ovc23_placeBuilding
                      (x,(int)in_stack_0000fffa,*(byte *)(uVar7 * 0x12 + 8),
                       *(uint8_t *)(uVar7 * 0x12 + 9));
          }
          *(undefined2 *)(uVar7 * 0x12) = (uint16_t)0;
        }
      }
      else if ((cVar2 == '\x02') && (9 < *(uint *)(uVar7 * 0x12))) {
        if (uVar7 + 1 < GRecordCount) {
          count = ((GRecordCount - uVar7) + -1) * 0x12;
          prevTick = CONCAT22(uVar6,count);
          _fmemmove((char *)CONCAT22(0x21f2,(char *)(uVar7 * 0x12)),
                    (char *)CONCAT22(0x21f2,(char *)(uVar7 * 0x12 + 0x12)),count);
          uVar7 = uVar7 - 1;
        }
        GRecordCount = GRecordCount - 1;
        outFlag = CONCAT11((char)(outFlag >> 8),1);
      }
    }
    if ((char)outFlag != '\0') {
      ovr_ovc23_textAdlibNone(uVar6,outFlag,in_stack_0000fffa);
    }
    if ((char)(outFlag >> 8) != '\0') {
      ovr_constr_flushDirtyRects();
    }
  }
  return;
}


/* 2e25:0938 */

/* [R4] calls printf */

void __cdecl16far draw_usesPrintf(void)

{
  bool bVar1;
  ulong *puVar2;
  int in_DX;
  undefined2 unaff_BP;
  
  MiceUnkState = 1;
  DrawBusy = 1;
  GGameState = 1;
  if (DebugVerbose) {
    printf("%d \r");
  }
  draw_usesBlitLoadRleGfx();
  GGameState = 2;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_agnt_usesAlignToSeg();
  if ((timePassing != '\0') ||
     (((GPaused == '\0' || ((bVar1 = ovr_ovc15_usesAlignUp42(), bVar1 && (GOngoingBattle == '\0'))))
      && ((puVar2 = ovr_attact_usesBDADailyTimeCounter
                              ((ulong *)GDailyTimeCounter,CONCAT22(unaff_BP,(*(uint16_t *)((uint8_t *)&(GDailyTimeCounter) + 2)))
                              ), in_DX != 0 ||
          ((char *)0x2415a < puVar2)))))) {
    ovr_attact_usesUpdSeason();
  }
  if (GGameInProgress == '\0') {
    GGameState = 4;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    ovr_ovc13_usesMiceBlitRect();
    GGameState = 6;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    draw_usesPlay_sfx();
    GGameState = 8;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    if (strongholdCheckPending != '\0') {
      ovr_ovc24_checkStrongholds();
    }
  }
  DrawBusy = 0;
  return;
}



/* 2e25:0ad1 */

/* [R4] calls ovr_resetTextBlitCycle */

void __cdecl16far draw_usesResetTextBlitCycle(void)

{
  draw_usesBlitLoadRleGfx2();
  ovr_resetTextBlitCycle();
  return;
}



/* 2e25:0adf */

uint16_t __cdecl16far gameProcessKey(void)

{
  uint16_t key;
  uint16_t uVar1;
  char *pcVar2;
  undefined1 in_DL;
  char *unaff_SS;
  uint8_t msg;
  
  key = ovr_biosReadKey();
  if (key == 0x320d) {
    if (AudioAssetsReady2 != '\0') {
      ovr_stop_audio();
    }
    AudioAssetsReady2 = '\x01' - (AudioAssetsReady2 != '\0');
  }
  else if (key == 0x1f13) {
    if (AudioAssetsReady1 != '\0') {
      ovr_stop_audio();
    }
    AudioAssetsReady1 = '\x01' - (AudioAssetsReady1 != '\0');
  }
  else if (GDebug != false) {
    if (key == 0x1000) {
      ovr_ovc30_usesRandBelow2(GfxRndSeed,GfxRndSeed2,(char)GfxRndSeed2);
    }
    else if ((key == 0x1300) && (VideoFlag_2410_0167 == 0)) {
      VideoFlag_2410_0167 = 1;
      ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
      ovr_ovc40_usesAlignToSeg
                ('\0',(char *)"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",0x2410,
                 (char *)"Archduchess",0x2410,0);
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
      VideoFlag_2410_0167 = 0;
    }
    else if (key == 0x1500) {
      ovr_ovc41_usesPlay_sfxU();
    }
    else if ((key == 0x1900) && (VideoFlag_2410_0167 == 0)) {
      VideoFlag_2410_0167 = 1;
      ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
      uVar1 = ovr_randBelow(2);
      ovr_season_textHalflingCastle((uint8_t)uVar1);
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
      VideoFlag_2410_0167 = 0;
    }
    else if (key == 0x1f00) {
      GTimeHi = 1;
    }
    else if (key == 0x2000) {
      DebugVerbose = (bool)('\x01' - (DebugVerbose != false));
    }
    else if (key == 0x2100) {
      ovr_ovc41_buildingNotice('\n');
    }
    else if (key == 0x2200) {
      destroyLatchSide0 = 1;
    }
    else if (key == 0x2300) {
      pcVar2 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x286,unaff_SS),
                             (char *)CONCAT22(GSeed,(char *)0x26510),(char)SeedHi);
      ovr_say(pcVar2,in_DL);
    }
    else if (key == 0x2400) {
      ovr_constrct_usesGLeaderCount();
    }
    else if (key == 0x2500) {
      destroyLatchSide1 = 1;
    }
    else if (key == 0x2600) {
      GCharLevelsInc = GCharLevelsInc + '\x01';
      pcVar2 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x297,unaff_SS),
                             (char *)(ulong)CONCAT12(GCharLevelsInc,0x2410));
      ovr_say(pcVar2,in_DL);
    }
    else if (key == 0x2c00) {
      ovr_ovc41_usesAgntCount3();
    }
    else if (key == 0x2e00) {
      ovr_dbgPromoteEnemy();
    }
    else if (key == 0x3000) {
      ovr_ovc41_buildingNotice('\x01');
    }
    else if (key == 0x3200) {
      ovr_ovc20_textLenLoc();
    }
  }
  return key;
}



/* 2e25:0d35 */
uint16_t __cdecl16far draw_usesGameProcessKey(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  undefined1 extraout_AH;
  int iStack_a;
  int iStack_8;
  
  iStack_8 = -1;
  iStack_a = -1;
  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x2410);
  iVar3 = MouseY;
  iVar2 = MouseX;
  bVar1 = false;
  MouseMoved = 0;
  while( true ) {
    if ((*(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != iStack_8) ||
       (*(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) != iStack_a)) {
      iStack_8 = *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
      iStack_a = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
      draw_usesPrintf();
      if (GGameInProgress != '\0') {
        ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
        draw_usesResetTextBlitCycle();
        return 0;
      }
    }
    uVar5 = ovr_biosKeyAvail();
    if ((char)uVar5 != '\0') break;
    bVar4 = ovr_init2_usesCFGMice((uint16_t *)&MouseX,(uint16_t *)&MouseY,0x2410);
    if (CONCAT11(extraout_AH,bVar4) == 0) {
      bVar1 = true;
    }
    else if (((bVar1) || (iVar2 != MouseX)) || (iVar3 != MouseY)) {
      if (!bVar1) {
        MouseMoved = 1;
      }
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
      MouseBkgPixel = *(undefined1 *)(MouseY * 0x140 + MouseX);
      draw_usesResetTextBlitCycle();
      GGameState = 0x36;
      if (DebugVerbose != false) {
        printf("%d \r");
      }
      return 0xffff;
    }
  }
  GGameState = 0x3b;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
  draw_usesResetTextBlitCycle();
  uVar5 = gameProcessKey();
  while (uVar6 = ovr_biosKeyAvail(), (char)uVar6 != '\0') {
    uVar5 = gameProcessKey();
  }
  GGameState = 0x35;
  if (DebugVerbose == false) {
    GGameState = 0x35;
    return uVar5;
  }
  printf("%d \r");
  return uVar5;
}


/* 2e25:0efd */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far draw_usesBlitLoadRleGfx3(int menuIndex,...)

{
  int row1;
  byte y1;
  int iVar1;
  uint8_t *ofs2;
  uint y1_00;
  byte y2;
  far_t gfx;
  far_t dst;
  
  if (((uint8_t *)MenuItemEnabled)[menuIndex] != 0xff) {
    row1 = *(int *)(menuIndex * 2 + 0xda);
    dst.seg = TextBlitDstSeg;
    dst.ofs = row1 * 0x140 + 0x124;
    gfx.seg = panel01Cut1Seg;
    gfx.ofs = panel01Cut1Ofs;
    ovr_blitLoadRleGfx(gfx,dst);
    iVar1 = draw_compute1(menuIndex);
    ofs2 = (uint8_t *)(iVar1 + 2);
    y1_00 = draw_compute2(menuIndex);
    y1 = (byte)row1;
    y2 = (byte)y1_00;
    ovr_driver_compute5(0x12e,y1,(uint16_t)ofs2,y2,0x126,y1 + 8,(uint)SpecialColors[0]);
    ovr_driver_compute5(0x12e,y1,(uint16_t)ofs2,y2,0x136,y1 + 8,(uint)SpecialColors[1]);
    ovr_driver_compute5((uint16_t)ofs2,y2,0x126,y1 + 8,0x136,y1 + 8,(uint)SpecialColors[2]);
    ovr_driver_drawLine((uint8_t *)((int)&GUnitDescriptions[0x10].seg + 1),row1,ofs2,y1_00,
                        SpecialColors[3]);
    ovr_driver_drawLine(ofs2,y1_00,(uint8_t *)((int)&GUnitDescriptions[0x12].seg + 1),row1 + 8,
                        SpecialColors[4]);
    ovr_driver_drawLine((uint8_t *)((int)&GUnitDescriptions[0xe].seg + 1),row1 + 8,ofs2,y1_00,
                        SpecialColors[5]);
    ovr_driver_fillRect((uint)ofs2,y1_00,(uint)ofs2,y1_00,0x6c,TextBlitDstSeg);
    draw_menuRowBar((uint)GMenuItem,TextBlitDstSeg);
  }
  return;
}



/* 2e25:10c7 */

/* Clamps and stores the menu cursor offset and draws the selection indicator lines. */

void __cdecl16far draw_menuCursor(int x,int y,...)

{
  if (x < 0) {
    x = 0;
  }
  if (y < 0) {
    y = 0;
  }
  if (0x38 < x) {
    x = 0x38;
  }
  if (0x1c < y) {
    y = 0x1c;
  }
  if ((x < 0x1d) || (x + -0x1c <= y)) {
    if ((x < 0x1c) && (y < 0x1c - x)) {
      x = (int)(char)((undefined *)&menuCursorX)[GMenuItem];
      y = (int)(char)((undefined *)&menuCursorY)[GMenuItem];
    }
  }
  else {
    x = (int)(char)((undefined *)&menuCursorX)[GMenuItem];
    y = (int)(char)((undefined *)&menuCursorY)[GMenuItem];
  }
  ((undefined *)&menuCursorX)[GMenuItem] = (undefined1)x;
  ((undefined *)&menuCursorY)[GMenuItem] = (char)y;
  ovr_driver_compute5(0x10f,0x3b,x + 0xf3,(char)y + 0x3b,0xf3,0x57,(uint)SpecialColors[0],
                      TextBlitDstSeg);
  ovr_driver_compute5(0x10f,0x3b,x + 0xf3,(char)y + 0x3b,299,0x57,(uint)SpecialColors[1],
                      TextBlitDstSeg);
  ovr_driver_compute5(x + 0xf3,(char)y + 0x3b,0xf3,0x57,299,0x57,(uint)SpecialColors[2],
                      TextBlitDstSeg);
  ovr_driver_drawLine((uint8_t *)(far_t *)(GUnitDescriptions + 9),0x3b,(uint8_t *)(x + 0xf3),
                      y + 0x3b,SpecialColors[3],TextBlitDstSeg);
  ovr_driver_drawLine((uint8_t *)(x + 0xf3),y + 0x3b,(uint8_t *)(far_t *)(GUnitDescriptions + 0x10),
                      0x57,SpecialColors[4],TextBlitDstSeg);
  ovr_driver_drawLine((uint8_t *)(x + 0xf3),y + 0x3b,(uint8_t *)(far_t *)(GUnitDescriptions + 2),
                      0x57,SpecialColors[5],TextBlitDstSeg);
  ovr_driver_fillRect(x + 0xf3,y + 0x3b,x + 0xf3,y + 0x3b,0x6c,TextBlitDstSeg);
  draw_usesBlitLoadRleGfx3((uint)GMenuItem);
  return;
}



/* 2e25:130a */

/* Blits the Build/Recruit/Train/Movement labels at their fixed toolbar positions. */

void __cdecl16far draw_toolbarLabels(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  void *pvVar1;
  undefined2 *puVar2;
  char *text;
  uint16_t in_DX;
  uint16_t uVar3;
  byte *pbVar4;
  char *unaff_SS;
  uint16_t seg;
  uint8_t term;
  far_t ptr;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  far_t handle;
  char textBuf [44];
  
  if (!GameRunning) {
    pvVar1 = ovr_stshAlloc(0xfa0f);
    ptr.seg = in_DX;
    ptr.ofs = (uint16_t)pvVar1;
    uVar3 = in_DX;
    ovr_alignToSeg(ptr);
    dst.seg = uVar3;
    dst.ofs = 0x4826;
    gfx.seg = nwpanel1Cut1Seg;
    gfx.ofs = nwpanel1Cut1Ofs;
    TextBlitDstSeg = uVar3;
    ovr_blitLoadRleGfx(gfx,dst);
    if (GMenuItem == 5) {
      dst_00.seg = TextBlitDstSeg;
      dst_00.ofs = 0x4975;
      gfx_00.seg = *(uint16_t *)((int)&LbmBigcomp50x42.seg + (uint)bigcompFrame * 4);
      gfx_00.ofs = ((far_t *)&LbmBigcomp50x42 + bigcompFrame)->ofs;
      ovr_blitLoadRleGfx(gfx_00,dst_00);
      TextBlitX = 0xea;
      TextBlitY = 0x62;
      ovr_blitText((char *)"Movement",(byte *)CONCAT22(Font03.ofs,(char *)0x26510),
                   Font03.seg,0x3f);
    }
    else if ((GMenuItem < 5) && (((uint8_t *)MenuItemEnabled)[GMenuItem] != 0xff)) {
      dst_01.seg = TextBlitDstSeg;
      dst_01.ofs = 0x482a;
      gfx_01.seg = trianglsCut1Seg;
      gfx_01.ofs = trianglsCut1Ofs;
      ovr_blitLoadRleGfx(gfx_01,dst_01);
      TextBlitX = 0xe6;
      TextBlitY = 0x3e;
      ovr_blitText((char *)"Recruit",(byte *)CONCAT22(Font02.ofs,(char *)0x26510),
                   Font02.seg,0x3f);
      TextBlitX = 0x11e;
      TextBlitY = 0x3e;
      ovr_blitText((char *)"Train",(byte *)CONCAT22(Font02.ofs,(char *)0x26510),Font02.seg
                   ,0x3f);
      TextBlitX = 0x104;
      TextBlitY = 0x5b;
      ovr_blitText((char *)"Build",(byte *)CONCAT22(Font02.ofs,(char *)0x26510),Font02.seg
                   ,0x3f);
      TextBlitX = 0xea;
      TextBlitY = 0x62;
      term = 0x3f;
      puVar2 = (undefined2 *)((uint)((uint8_t *)MenuItemEnabled)[GMenuItem] * 4);
      pbVar4 = (byte *)((char *)0x2627a);
      uVar3 = Font03.ofs;
      seg = Font03.seg;
      text = (char *)ovr_ovc45_compute9(textBuf,(char *)CONCAT22(*puVar2,unaff_SS),
                                        (char *)CONCAT22(Font03.ofs,(char *)puVar2[1]),Font03.seg,
                                        'T',3);
      ovr_blitText(text,(byte *)CONCAT22(uVar3,pbVar4),seg,term);
      draw_menuCursor((int)(char)((undefined *)&menuCursorX)[GMenuItem],
                      (int)(char)((undefined *)&menuCursorY)[GMenuItem]);
      draw_usesFillRect2((uint)((uint8_t *)menuItemRow)[GMenuItem],TextBlitDstSeg);
    }
    ovr_blitRaw(0xe6,0x39,0x13a,0x71,TextBlitDstSeg,0xa000);
    TextBlitDstSeg = 0xa000;
    handle.seg = in_DX;
    handle.ofs = (uint16_t)pvVar1;
    ovr_stshFree(handle);
  }
  return;
}



/* 2e25:15d6 */

/* [R2] string "arena" */

bool __cdecl16far draw_textArena(void)

{
  bool bVar1;
  int iVar2;
  
  if (DebugVerbose) {
    bVar1 = true;
  }
  else if (CurPartySlot == '\0') {
    bVar1 = true;
  }
  else if ((CurPartySlot == '\x01') && (PartyCount != '\0')) {
    bVar1 = true;
  }
  else {
    for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
      if ((((short (*) [60] [148])GMapFlags)[-1][GfxRndSeed2 + 0x3b][GfxRndSeed + iVar2 + 0x92] & 8U
          ) != 0) {
        return true;
      }
    }
    bVar1 = false;
  }
  return bVar1;
}



/* 2e25:1662 */

/* Frees the audioSaveCut1/2 ring buffers, clears their handles and cleans the ring buffer. */

void __cdecl16far draw_freeRingBuffers(void)

{
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  
  if (audioSaveCut1Ofs != 0 || audioSaveCut1Seg != 0) {
    handle.seg = audioSaveCut1Seg;
    handle.ofs = audioSaveCut1Ofs;
    ovr_stshFree(handle);
  }
  audioSaveCut1Seg = 0;
  audioSaveCut1Ofs = 0;
  if (audioSaveCut2Ofs != 0 || audioSaveCut2Seg != 0) {
    handle_00.seg = audioSaveCut2Seg;
    handle_00.ofs = audioSaveCut2Ofs;
    ovr_stshFree(handle_00);
  }
  audioSaveCut2Seg = 0;
  audioSaveCut2Ofs = 0;
  if (upperTextOfs != (byte *)0x0 || upperTextSeg != 0) {
    handle_01.seg = upperTextSeg;
    handle_01.ofs = (uint16_t)upperTextOfs;
    ovr_stshFree(handle_01);
  }
  upperTextSeg = 0;
  upperTextOfs = (byte *)0x0;
  ovr_clean_ring_buffer();
  if (CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0) {
    handle_02.seg = CrossBlitPtr.seg;
    handle_02.ofs = CrossBlitPtr.ofs;
    ovr_stshFree(handle_02);
  }
  CrossBlitPtr.seg = 0;
  CrossBlitPtr.ofs = 0;
  ovr_clearMiceProcessed();
  return;
}



/* 2e25:1759 */

/* [R7] body shape: compute */

undefined2 __cdecl16far draw_compute4(byte type)

{
  if (type != 0x37) {
    if (type < 0x38) {
      if (type != 0x1e) {
        if (type < 0x1f) {
          if (((type != 9) && (type != 0xe)) && (type != 0x1c)) {
            return 0;
          }
        }
        else if ((type != 0x1f) && (type != 0x20)) {
          return 0;
        }
      }
    }
    else if (type != 0x44) {
      if (type < 0x45) {
        if ((type != 0x38) && (type != 0x39)) {
          return 0;
        }
      }
      else if ((type != 0x45) && (type != 0x55)) {
        return 0;
      }
    }
  }
  return 1;
}



/* 2e25:17b3 */

/* [R4] calls ovr_toggle_pause */

void __cdecl16far draw_usesToggle_pause(void)

{
  bool bVar1;
  uint16_t value;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  int dstSeg;
  char cStack_6;
  byte bStack_4;
  
  GGameState = 0x36;
  if (DebugVerbose) {
    printf("%d \r");
  }
  if ((((MouseX < 0xc) || (0xde < MouseX)) || (MouseY < 7)) ||
     ((0x96 < MouseY || (MouseMoved != 0)))) {
    if ((MouseMoved == 0) &&
       ((((0xde < MouseX && (MouseX < 0xee)) && ((7 < MouseY && (MouseY < 0x33)))) ||
        ((((GOngoingBattle != '\0' && (0xee < MouseX)) && (MouseX < 0x135)) &&
         (((6 < MouseY && (MouseY < 0x37)) && (bVar1 = draw_textArena(), bVar1)))))))) {
      ovr_ovc41_cannotSeeTerrainNotice();
    }
    else if ((((MouseMoved != 0) || (MouseX < 0xef)) ||
             ((0x134 < MouseX || ((MouseY < 7 || (0x36 < MouseY)))))) ||
            ((GOngoingBattle != '\0' && (bVar1 = draw_textArena(), bVar1)))) {
      if ((((MouseX < 9) || (0x18 < MouseX)) || (MouseY < 0xb5)) ||
         ((0xc4 < MouseY || (MouseMoved != 0)))) {
        if ((((trianglesShown == '\0') || ((MouseX < 10 || (0x16 < MouseX)))) || (MouseY < 0x9e)) ||
           ((0xaa < MouseY || (MouseMoved != 0)))) {
          if ((GMenuItem == 5) &&
             ((((0xf4 < MouseX && (0x39 < MouseY)) && (MouseX < 0x128)) &&
              ((MouseY < 0x65 && (uVar4 = draw_compute4(MouseBkgPixel), (char)uVar4 != '\0')))))) {
            cStack_6 = '\0';
            MenuMode = '\x01';
            if ((int)(MouseX - 0xf5) <= (int)(MouseY - 0x36)) {
              cStack_6 = '\x02';
            }
            if ((int)(0x2e - (MouseY - 0x3a)) < (int)(MouseX - 0xf5)) {
              if (cStack_6 == '\0') {
                cStack_6 = '\x01';
              }
            }
            else if (cStack_6 == '\x02') {
              cStack_6 = '\x03';
            }
            ovr_ovc41_usesBiosKeyAvail(cStack_6,0);
            draw_textTalkwin9Lbm();
          }
          else if (((GMenuItem < 5) &&
                   (((0xf2 < MouseX && (MouseX < 300)) && ((MouseY < 0x58 && (0x3a < MouseY)))))) &&
                  (((MouseX < 0x110 && (0x10f - MouseX <= MouseY - 0x3b)) ||
                   ((0x10f < MouseX && (MouseX - 0x10f <= MouseY - 0x3b)))))) {
            draw_menuCursor(MouseX - 0xf3,MouseY - 0x3b);
            MenuMode = '\x01';
            draw_textTalkwin9Lbm();
            ovr_ovc41_unitStatusText(GMenuItem);
          }
          else if ((((MouseX < 0xea) || (0x13a < MouseX)) || (MouseY < 0x6d)) ||
                  ((0x6f < MouseY || (4 < GMenuItem)))) {
            if (((0x123 < MouseX) && ((MouseX < 0x139 && (0x85 < MouseY)))) && (MouseY < 200)) {
              uVar3 = (MouseY - 0x86) % 0xd;
              if ((uVar3 < 9) &&
                 ((((MouseX < 0x12f && (0x12e - MouseX <= uVar3)) ||
                   ((0x12e < MouseX && (MouseX - 0x12e <= uVar3)))) &&
                  ((uVar2 = (MouseY - 0x86) / 0xd, uVar2 < 5 &&
                   (((uint8_t *)MenuItemEnabled)[uVar2] != 0xff)))))) {
                bStack_4 = (byte)uVar2;
                if (GMenuItem != uVar2) {
                  GMenuItem = bStack_4;
                  MenuMode = 1;
                  draw_toolbarLabels();
                  ovr_ovc41_unitStatusText(GMenuItem);
                  draw_textTalkwin9Lbm();
                  return;
                }
                if (GOngoingBattle != '\0') {
                  ovr_ui_textDefineRegionCommand(bStack_4);
                  return;
                }
                MenuMode = 1;
                draw_toolbarLabels();
                draw_textTalkwin9Lbm();
                ovr_ovc41_unitStatusText(GMenuItem);
                return;
              }
              if (uVar3 == 0xb) {
                uVar3 = (MouseY - 0x86) / 0xd;
                if (((uint8_t *)MenuItemEnabled)[uVar3] == 0xff) {
                  return;
                }
                bStack_4 = (byte)uVar3;
                GMenuItem = bStack_4;
                MenuMode = 2;
                draw_toolbarLabels();
                draw_textTalkwin9Lbm();
                ovr_attact_updateAttractEntry((uint)GMenuItem,1);
                return;
              }
            }
            if ((((MouseX < 0xea) || (0x123 < MouseX)) || (MouseY < 0x86)) ||
               (((199 < MouseY || (uVar3 = (MouseY - 0x86) / 0xd, 8 < (MouseY - 0x86) % 0xd)) ||
                ((4 < uVar3 || (((uint8_t *)MenuItemEnabled)[uVar3] == 0xff)))))) {
              if (((MouseX < 0x125) || (0x137 < MouseX)) ||
                 ((MouseY < 0x72 ||
                  (((0x82 < MouseY || (MouseMoved != 0)) ||
                   (uVar4 = draw_compute4(MouseBkgPixel), (char)uVar4 == '\0')))))) {
                if (((MouseMoved == 0) && (0xea < MouseX)) &&
                   ((MouseX < 0x115 && ((0x73 < MouseY && (MouseY < 0x80)))))) {
                  ovr_toggle_pause();
                  draw_toolbarLabels();
                }
              }
              else {
                GMenuItem = 5;
                MenuMode = '\x01';
                draw_toolbarLabels();
                draw_textTalkwin9Lbm();
              }
            }
            else {
              ovr_manage_showSettlementScreen(((uint8_t *)MenuItemEnabled)[uVar3]);
            }
          }
          else {
            dstSeg = -0x6000;
            value = ovr_attact_textAbnormalProgramTermination(MouseX - 0xea,GMenuItem);
            draw_usesFillRect2(value,dstSeg);
            if (MenuMode == '\x02') {
              ovr_attact_updateAttractEntry((uint)GMenuItem,0);
            }
            else {
              ovr_attact_updateAttractEntry((uint)GMenuItem,1);
            }
            MenuMode = '\x02';
            draw_textTalkwin9Lbm();
          }
        }
        else {
          ovr_manage_textHalflingCastle();
        }
      }
      else {
        ovr_attact_usesAgntFlag1();
        ovr_uiMainMenu();
      }
    }
    else {
      ovr_ovc13_usesBlitLoadRleGfx3(MouseX - 0xef >> 1,MouseY - 7,'\0');
    }
  }
  else if (GOngoingBattle == '\0') {
    bVar1 = ovr_stats_selectAgentAt(MouseX - 0xc,MouseY - 7);
    if (!bVar1) {
      ovr_ovc45_showLandInfo(MouseX - 0xc,MouseY - 7);
    }
  }
  else {
    ovr_ovc13_usesBlitLoadRleGfx2(MouseX - 0xc >> 1,MouseY - 7,'\0');
  }
  return;
}



/* 2e25:1d7c */

/* [R2] string "%s: provides more housing." */

bool __cdecl16far draw_textProvidesMoreHousing(void)

{
  undefined1 uVar1;
  uint16_t uVar2;
  
  uVar2 = ovr_miceButtonsStates();
  if ((uVar2 & 1) == 0) {
    if ((uVar2 & 2) == 0) {
      uVar2 = ovr_biosKeyAvail();
      if ((char)uVar2 != '\0') {
        uVar2 = gameProcessKey();
        if (uVar2 == 0x11b) {
          return true;
        }
        if (uVar2 == 0x1c0d) {
          return true;
        }
      }
      ovr_audio_usesLDIV_at_();
      uVar1 = 0;
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  return (bool)uVar1;
}



/* 2e25:1e42 */

/* [R2] string "%s: %s %d gold. provides housing for %d " */

void __stdcall16far draw_textGoldProvidesHousing(void)

{
  uint *puVar1;
  byte *pbVar2;
  undefined1 uVar3;
  int iVar4;
  byte bVar5;
  undefined2 in_AX;
  uint uVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  uint in_CX;
  uint uVar10;
  byte bVar11;
  uint in_DX;
  uint uVar12;
  byte bVar13;
  byte bVar14;
  uint in_BX;
  uint *puVar15;
  byte bVar16;
  byte bVar17;
  uint unaff_BP;
  uint uVar18;
  uint unaff_SI;
  uint uVar19;
  uint *puVar20;
  uint unaff_DI;
  undefined1 *puVar21;
  uint uVar22;
  byte *pbVar23;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 in_GS;
  undefined2 uStack_4;
  
  uVar6 = CONCAT11((char)((uint)in_AX >> 8),(char)in_AX + -0x3a);
  uVar10 = in_CX | uVar6;
  puVar21 = (undefined1 *)(unaff_DI | *(uint *)(unaff_BP + unaff_SI + -0x59f5));
  puVar15 = (uint *)(in_BX | unaff_DI |
                    *(uint *)((char *)0x2c30b + unaff_BP));
  uVar19 = unaff_SI | *(uint *)(unaff_BP + 0xb);
  uVar3 = in(in_DX);
  *puVar21 = uVar3;
  uVar22 = (uint)(puVar21 + 1) | *(uint *)(unaff_BP + uVar19);
  uVar19 = uVar19 | *puVar15;
  uVar18 = unaff_BP | *(uint *)((int)puVar15 + uVar19);
  uVar12 = (in_DX | *(uint *)(unaff_BP + 0xb)) - 1 | 0x7474;
  uVar6 = uVar6 | *(uint *)(uVar18 + uVar22);
  puVar20 = (uint *)(uVar19 | (uint)&stack0x0000);
  bVar7 = (byte)uVar10;
  bVar5 = (byte)uVar6;
  bVar14 = (byte)puVar15;
  bVar16 = (byte)((uint)puVar15 >> 8) | *(byte *)((int)puVar15 + uVar22 + 0xb30a);
  bVar9 = *(byte *)(uVar18 + uVar22 + -0x69f6);
  bVar8 = bVar7 | bVar5 |
          *(byte *)((int)puVar20 +
                   (int)((char *)0x2c10a + uVar18));
  bVar13 = (byte)(uVar12 >> 8) | *(byte *)((int)puVar20 + CONCAT11(bVar16,bVar14) + 10);
  puVar1 = (uint *)(uVar18 + (int)puVar20);
  iVar4 = (bVar8 & 3) - (*puVar1 & 3);
  *puVar1 = *puVar1 + (uint)(0 < iVar4) * iVar4;
  bVar11 = (byte)uVar12 | (byte)puVar20[5];
  uVar12 = CONCAT11(bVar13,bVar11);
  bVar16 = bVar16 | (byte)*puVar20;
  bVar17 = bVar16 | bVar5;
  uVar19 = CONCAT11(bVar17,bVar14);
  pbVar23 = (byte *)(uVar22 | (int)&uStack_4 + 1U);
  uVar6 = CONCAT11((byte)(uVar6 >> 8) | bVar9 | *(byte *)(uVar18 + uVar22),bVar5) | uVar19;
  uVar10 = CONCAT11((byte)(uVar10 >> 8) | bVar7 | *(byte *)CONCAT11(bVar16,bVar14),
                    bVar8 | (*(uint8_t *)((uint8_t *)&(AgntAnms[0xe].y) + 1))) | uVar12;
  *(uint *)(pbVar23 + uVar18 + 0xb009) = *(uint *)(pbVar23 + uVar18 + 0xb009) | (uint)puVar20;
  puVar1 = (uint *)((int)puVar20 + uVar19 + 0x9809);
  *puVar1 = *puVar1 | uVar18;
  *(uint *)(pbVar23 + uVar18 + 0x7f09) = *(uint *)(pbVar23 + uVar18 + 0x7f09) | uVar10;
  *(uint *)(pbVar23 + 9) = *(uint *)(pbVar23 + 9) | (uint)puVar20;
  puVar1 = (uint *)((int)puVar20 + uVar19 + 9);
  *puVar1 = *puVar1 | uVar19;
  *puVar20 = *puVar20 | (uint)pbVar23;
  *(uint *)(pbVar23 + uVar18) = *(uint *)(pbVar23 + uVar18) | (uint)puVar20;
  *(uint *)(uVar19 + (int)puVar20) = *(uint *)(uVar19 + (int)puVar20) | uVar18;
  *(uint *)(pbVar23 + uVar19) = *(uint *)(pbVar23 + uVar19) | uVar12;
  *(uint *)(uVar19 + (int)puVar20) = *(uint *)(uVar19 + (int)puVar20) | uVar6;
  bVar9 = (byte)uVar10 | (byte)pbVar23;
  pbVar23[-0x54f8] = pbVar23[-0x54f8] | bVar17;
  *(byte *)(puVar20 + -0x3c7c) = (byte)puVar20[-0x3c7c] | bVar11;
  pbVar2 = (byte *)((int)puVar20 + uVar18 + 8);
  *pbVar2 = *pbVar2 | bVar13;
  pbVar23[uVar18 + 8] = pbVar23[uVar18 + 8] | bVar9;
  *(byte *)(uVar18 + uStack_4) = *(byte *)(uVar18 + uStack_4) | (byte)(uVar6 >> 8);
  *pbVar23 = *pbVar23 | bVar9;
  pbVar2 = (byte *)CONCAT11(bVar17,bVar14 | bVar13);
  *pbVar2 = *pbVar2 >> 1 | *pbVar2 << 7;
  return;
}


