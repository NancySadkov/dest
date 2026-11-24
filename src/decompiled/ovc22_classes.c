/*
 * ovc22_classes.c - recovered from STRONG.EXE
 * memory block: OVC22_classes.c
 * range: 5087:0000 - 5087:576f
 * functions: 31
 */
#include "recovered.h"


/* 5087:0000 */

/* [R2] string "arena" */

bool __cdecl16far ovc22_textArena(int x,int y)

{
  bool bVar1;
  int cellB;
  int cellMin;
  uint16_t uVar4;
  int cellA;
  
  if ((((x < 0) || (y < 0)) || (0x93 < x + 1)) || (0x3b < y + 1)) {
    placementStatus = 2;
    bVar1 = false;
  }
  else {
    uVar4 = (uint16_t)((ulong)GMapFlags >> 0x10);
    if ((((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) == 0) &&
       (((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) == 0)) {
      cellA = (int)(char)(*(byte (*) [59] [148])GMapCells)[y + 1][x];
      cellB = (int)(char)(*(byte (*) [59] [148])GMapCells)[y + 1][x + 1];
      cellMin = cellA;
      if (cellB < cellA) {
        cellMin = cellB;
      }
      if (cellA < cellB) {
        cellA = cellB;
      }
      if (cellA - cellMin < 9) {
        placementStatus = 3;
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      placementStatus = 1;
      bVar1 = false;
    }
  }
  return bVar1;
}



/* 5087:0119 */

/* Returns the class name of a party slot (cls < 7 from the table at 0x123) or "monster". */

char * __cdecl16far ovc22_className(byte partyIndex,uint16_t arg2)

{
  byte bVar1;
  char *pcVar2;
  
  bVar1 = *(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x2f);
  if (bVar1 < 7) {
    pcVar2 = (char *)*(uint16_t *)((uint)bVar1 * 4 + 0x123);
  }
  else {
    pcVar2 = (char *)"monster";
  }
  return pcVar2;
}



/* 5087:015c */

/* [R7] body shape: compute */

uint __cdecl16far ovc22_compute1(byte partyIndex,uint value)

{
  if (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x2f) == '\x04') {
    value = value >> 1;
  }
  return value;
}



/* 5087:018f */

/* Scales a value by the leader's rank (rank+10)/10, doubles it at rank >= 10 and applies 96% for
   class 6. */

int __cdecl16far ovc22_applyRankBonus(byte partyIndex,int cost)

{
  if ((GLeaderSheets[partyIndex])->rank < 10) {
    if ((GLeaderSheets[partyIndex])->rank != 0) {
      cost = (int)(((long)cost *
                    (long)((GLeaderSheets[partyIndex])->rank + 10) &
                   0xffffU) / 10);
    }
  }
  else {
    cost = cost << 1;
  }
  if (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x2f) == '\x06') {
    cost = (int)(((long)cost * 0x96 & 0xffffU) / 100);
  }
  return cost;
}



/* 5087:0234 */

/* WARNING: Instruction at (ram,0x0005ff51) overlaps instruction at (ram,0x0005ff50)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R2] string "POPULATION" */

char * __cdecl16far ovc22_textPOPULATION(byte bldType,byte partyIndex,agnt_t *agnt,uint16_t arg4,uint16_t arg5)

{
  undefined1 stk_bac4;   /* stack slot bac4 */
  byte *pbVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  uint16_t uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  char in_CL;
  uint16_t uVar9;
  uint16_t unaff_BP;
  char *pcVar10;
  uint16_t unaff_SI;
  uint16_t unaff_DI;
  uint16_t in_stack_0000000a;
  uint16_t in_stack_0000000c;
  uint16_t in_stack_0000000e;
  uint8_t numBuf;
  uint16_t auStackY_11a [66];
  uint8_t labelPtrs;
  uint8_t menuItems;
  uint8_t labelOfs;
  char *suffix;
  far_t entries;
  byte bVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  
  uVar12 = (undefined1)unaff_BP;
  uVar13 = (undefined1)((uint)unaff_BP >> 8);
  if (BuildingTypes[bldType].unitType == '\x16') {
    pcVar6 = (char *)0x0;
  }
  else if (BuildingTypes[bldType].production == '\0') {
    pcVar6 = (char *)0x0;
  }
  else {
    if ((BuildingTypes[bldType].flags2 & 0x20) == 0) {
      if ((BuildingTypes[bldType].flags2 & 0x80) == 0) {
        pcVar6 = (char *)(uint)BuildingTypes[bldType].production;
      }
      else {
        pcVar6 = (char *)ovc22_applyRankBonus
                                   (partyIndex,(uint)BuildingTypes[bldType].production);
      }
    }
    else {
      pcVar6 = (char *)ovc22_compute1(partyIndex,(uint)BuildingTypes[bldType].production);
    }
    if (pcVar6 == (char *)0x0) {
      pcVar6 = (char *)0x0;
    }
    else if (BuildingTypes[bldType].unitType == '\x19') {
      if (GSeason == '\0') {
        if (GTimeLo < 0xf) {
          pcVar6 = (char *)((uint)pcVar6 >> 2);
        }
        else {
          pcVar6 = (char *)((uint)pcVar6 >> 1);
        }
      }
      else if (GSeason == '\x02') {
        pcVar6 = pcVar6 + ((uint)pcVar6 >> 2);
      }
    }
    else {
      if ((BuildingTypes[bldType].flags2 & 0x80) != 0) {
        uVar9 = in_stack_0000000a;
        uVar7 = ovr_constr_usesGMapFlags2((int)agnt,in_stack_0000000a);
        switch(uVar7 & 0xff) {
        case 1:
          *(char *)(unaff_DI + 0x34) = *(char *)(unaff_DI + 0x34) << 1;
code_r0x0005b805:
          if (((entity_t *)Entities)[pcVar6].base.destY != in_stack_0000000a)
          goto L_OVC25_5b66_00ff_01D9;
          do {
            pbVar1 = (byte *)((uint8_t *)&((entity_t *)Entities)[pcVar6] + 0x33);
            *pbVar1 = *pbVar1 | 8;
L_OVC25_5b66_00ff_01D9:
            while( true ) {
              do {
                pcVar6 = pcVar6 + 1;
                if (EntityCount <= pcVar6) {
                  if (partyIndex != 0) {
                    iVar4 = 0;
                    while ((iVar4 < (int)(uint)partyIndex &&
                           (uVar7 = ovc25_usesAlignUp4(bldType,in_stack_0000000c,in_stack_0000000e,
                                                       unaff_DI,in_stack_0000000a), -1 < (int)uVar7)
                           )) {
                      ((entity_t *)Entities)[uVar7].base.state = 0;
                      ((entity_t *)Entities)[uVar7].base.destX = unaff_DI;
                      ((entity_t *)Entities)[uVar7].base.destY = in_stack_0000000a;
                      pbVar1 = (byte *)((uint8_t *)&((entity_t *)Entities)[uVar7] + 0x33);
                      *pbVar1 = *pbVar1 | 8;
                      iVar4 = iVar4 + 1;
                    }
                  }
                  return (char *)0xffff;
                }
                uVar5 = (uint16_t)((ulong)Entities >> 0x10);
              } while (AGNT_FIELD(&((entity_t *)Entities)[pcVar6], base.entity, 3) != bldType);
              uVar7 = ovr_alignUp4(((entity_t *)Entities)[pcVar6].base.x,0,0);
              uVar8 = ovr_alignUp4(unaff_DI,0,0);
              uVar5 = (uint16_t)((ulong)Entities >> 0x10);
              if ((uVar7 == uVar8) &&
                 (((entity_t *)Entities)[pcVar6].base.y == in_stack_0000000a))
              break;
              uVar7 = ovr_alignUp4(((entity_t *)Entities)[pcVar6].base.destX,0,0);
              uVar8 = ovr_alignUp4(unaff_DI,0,0);
              if (uVar7 == uVar8) goto code_r0x0005b805;
            }
          } while( true );
        case 2:
          pcVar2 = (code *)swi(1);
          pcVar6 = (char *)(*pcVar2)();
          return pcVar6;
        case 3:
          do {
            if (*(byte *)(uVar9 + 0x32) < Agnts[pcVar6].strengthMax) {
              Agnts[pcVar6].strengthMax = *(undefined1 *)(uVar9 + 0x32);
            }
            uVar9 = 0x34;
            pcVar10 = pcVar6;
code_r0x0005ff56:
            bVar11 = *(byte *)((int)pcVar6 * uVar9 + 0x21);
            uVar9 = CONCAT11((char)((int)pcVar6 * uVar9 >> 8),bVar11);
            pcVar6 = pcVar10;
            if (Agnts[pcVar10].strengthMax < bVar11) {
              uVar12 = Agnts[pcVar10].strengthMax;
              uVar9 = CONCAT11((char)((uint)((int)pcVar10 * 0x34) >> 8),uVar12);
              Agnts[pcVar10].strength = uVar12;
            }
            do {
              pcVar6 = pcVar6 + 1;
              if ((int)(uint)AgntCount <= (int)pcVar6) {
                iVar4 = ovr_audio_panFromX(agnt,0);
                uVar12 = (undefined1)((uint)iVar4 >> 8);
                ovr_play_sfxU(0x1c,0,0,0,0);
                return (char *)CONCAT11(uVar12,1);
              }
            } while (Agnts[pcVar6].owner != agnt->owner);
          } while( true );
        case 4:
          iVar4 = ovr_font_textWidth((char *)"POPULATION",(char *)CONCAT13(uVar13,CONCAT12(uVar12,unaff_SI)),0,0,0);
          uVar9 = 0xd4 - iVar4;
          cVar3 = -0x3c;
          bVar11 = 0x22;
          TextBlitX = uVar9;
          unaff_SI = Font02.seg;
          ovr_blitLabel((char *)"POPULATION");
          for (pcVar10 = (char *)0x0; TextBlitY = TextBlitY + 0xc, (int)pcVar10 < (int)(uint)bVar11;
              pcVar10 = pcVar10 + 1) {
            TextBlitX = 0x11;
            if (((int)pcVar10 < 5) || (cVar3 == '\0')) {
              suffix = (char *)0x24298;
              ovr_blitLabel(*(char **)(&labelPtrs + (int)pcVar10 * 4));
            }
            else {
              suffix = (char *)&VideoFlag_2410_0167;
              ovr_blitLabel((char *)auStackY_11a
                                    [(int)pcVar10 * 2 +
                                     (uint)*(byte *)((int)*(uint32_t *)((uint)bldType << 2) + 0x2f
                                                    ) * 8]);
            }
            suffix = (char *)0x263c4;
            labelOfs = 0x1b7;
            ovc27_textCharmed();
            ovr_stsprintf((char *)&numBuf);
            iVar4 = ovr_font_textWidth((char *)&numBuf,0,0,0,0);
            TextBlitX = 0x89 - iVar4;
            suffix = (char *)0x2431a;
            ovr_blitLabel((char *)&numBuf);
            ovr_stsprintf((char *)&numBuf);
            iVar4 = ovr_font_textWidth((char *)&numBuf,0,0,0,0);
            uVar9 = 0xd4 - iVar4;
            cVar3 = (char)Font02.ofs;
            bVar11 = (byte)(Font02.ofs >> 8);
            suffix = (char *)0x27d;
            TextBlitX = uVar9;
            ovr_blitLabel((char *)&numBuf);
          }
          CurSfxType3 = 0x3c;
          entries.seg = _SS;
          entries.ofs = (uint16_t)&menuItems;
          suffix = (char *)0x263c4;
          labelOfs = 0x327;
          uVar5 = ovr_ovc28_usesUiInputText(entries,0,0,0,0,0);
          cVar3 = (char)uVar5;
          keyboardInputMode = 0;
          if (((cVar3 != '\0') && (cVar3 != '\x01')) && (cVar3 != -2)) {
            (&stk_bac4)[unaff_DI] = (&stk_bac4)[unaff_DI] + in_CL;
            pcVar6 = (char *)0x26510;
            goto code_r0x0005ff56;
          }
          if (cVar3 == -2) {
            Cancelled = 1;
          }
          return (char *)0x26510;
        }
      }
      if (GSeason == '\x01') {
        pcVar6 = pcVar6 + ((uint)pcVar6 >> 2);
      }
      else if (GSeason == '\x02') {
        pcVar6 = (char *)((uint)pcVar6 >> 2);
      }
    }
  }
  return pcVar6;
}



/* 5087:0411 */

/* Returns a building's income adjusted for the current season and time of day. */

uint __cdecl16far ovc22_seasonalIncome(byte bldType,uint8_t partyIndex,uint16_t arg3,uint16_t arg4,uint16_t arg5)

{
  uint uVar1;
  
  if (BuildingTypes[bldType].income == 0) {
    uVar1 = 0;
  }
  else if (BuildingTypes[bldType].unitType == '\x19') {
    uVar1 = BuildingTypes[bldType].income;
    if (GSeason == '\0') {
      if (GTimeLo < 0xf) {
        uVar1 = uVar1 >> 2;
      }
      else {
        uVar1 = uVar1 >> 1;
      }
    }
    else if (GSeason == '\x02') {
      uVar1 = uVar1 + (uVar1 >> 2);
    }
  }
  else if ((BuildingTypes[bldType].flags2 & 0x20) == 0) {
    if ((BuildingTypes[bldType].flags2 & 0x80) == 0) {
      uVar1 = BuildingTypes[bldType].income;
    }
    else {
      uVar1 = ovc22_applyRankBonus(partyIndex,BuildingTypes[bldType].income);
      if (GSeason == '\x01') {
        uVar1 = uVar1 + ((int)uVar1 >> 2);
      }
      else if (GSeason == '\x02') {
        uVar1 = (int)uVar1 >> 2;
      }
    }
  }
  else {
    uVar1 = ovc22_compute1(partyIndex,BuildingTypes[bldType].income);
  }
  return uVar1;
}



/* 5087:056e */
far_t * __cdecl16far ovc22_textRingProt(byte partyIndex)

{
  undefined1 stk_0035;   /* stack slot 0035 */
  undefined1 stk_681c;   /* stack slot 681c */
  undefined1 stk_8ed6;   /* stack slot 8ed6 */
  undefined1 stk_bac4;   /* stack slot bac4 */
  undefined1 stk_ffaa;   /* stack slot ffaa */
  undefined1 stk_ffaf;   /* stack slot ffaf */
  undefined1 stk_ffb4;   /* stack slot ffb4 */
  undefined1 stk_ffbc;   /* stack slot ffbc */
  undefined1 stk_fffe;   /* stack slot fffe */
  char *pcVar1;
  byte *pbVar2;
  uint *puVar3;
  int *piVar4;
  uint8_t *puVar5;
  byte *pbVar6;
  short sVar7;
  undefined1 *puVar8;
  byte bVar9;
  undefined1 *puVar10;
  uint32_t uVar11;
  far_t table;
  far_t entries;
  far_t pctOut;
  far_t remainderOut;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t gfx_08;
  far_t gfx_09;
  far_t gfx_10;
  far_t gfx_11;
  far_t partOut;
  uint3 uVar12;
  far_t far *pfVar13;
  char cVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  char cVar18;
  undefined1 uVar19;
  far_t far *in_AX;
  far_t far *pfVar20;
  char *pcVar21;
  uint uVar22;
  uint uVar23;
  uint16_t index;
  uint16_t uVar24;
  char cVar25;
  uint16_t in_CX;
  byte bVar26;
  byte bVar27;
  uint16_t *puVar28;
  byte bVar34;
  int iVar29;
  int iVar30;
  uint16_t uVar31;
  uint uVar32;
  uint uVar33;
  byte bVar35;
  byte bVar43;
  uint *puVar36;
  unit_t *units;
  unit_t *puVar38;
  int iVar39;
  int iVar40;
  entity_t *peVar41;
  entity_t *peVar42;
  uint *puVar45;
  uint uVar46;
  uint *puVar47;
  uint uVar48;
  uint16_t unaff_SI;
  uint *puVar49;
  uint *puVar50;
  uint16_t *puVar51;
  uint *unaff_DI;
  int iVar52;
  uint16_t uVar53;
  uint16_t uVar54;
  uint16_t uVar55;
  bool bVar56;
  bool bVar57;
  bool bVar58;
  bool bVar59;
  byte in_AF;
  bool bVar60;
  bool bVar61;
  bool bVar62;
  byte bStack0006;
  byte bStack0008;
  undefined1 uStack0009;
  undefined1 *in_stack_0000000a;
  uint16_t in_stack_0000000c;
  byte in_stack_0000000e;
  char in_stack_00000010;
  char acStackY_13e [36];
  uint16_t auStackY_11a [58];
  char acStackY_a6 [16];
  uint16_t auStackY_96 [22];
  uint16_t unitNameOfs;
  char acStackY_68 [6];
  uint16_t uStackY_62;
  uint16_t uStackY_60;
  uint16_t *puVar63;
  char cVar64;
  undefined1 uVar65;
  char cVar66;
  undefined1 uVar67;
  undefined1 uVar68;
  undefined1 in_stack_0000ffb8;
  undefined1 in_stack_0000ffb9;
  undefined1 uVar69;
  uint16_t in_stack_0000ffbe;
  uint16_t in_stack_0000ffc0;
  agnt_t *in_stack_0000ffc2;
  int iStack_3c;
  uint uStack_38;
  int iStack_36;
  uint uStack_34;
  int16_t resourceTotals [4];
  int16_t animStep;
  uint16_t uStack_28;
  /* stack temporaries cleared by _fmemset at 5087:05ae / 05f1 / 064f; the
     recovered declaration list had no name for these offsets */
  uint16_t uStack_2e;
  uint16_t uStack_a;
  uint16_t uStack_42;
  uint16_t uStack_26;
  uint uStack_24;
  int iStack_22;
  uint16_t uStack_20;
  uint16_t uStack_1e;
  char cStack_1c;
  byte bStack_1b;
  uint16_t uStack_1a;
  uint16_t uStack_18;
  far_t far *uStack_16;   /* hand fix: far_t far * cursor */
  far_t far *uStack_14;   /* hand fix: far_t far * cursor */
  uint *puStack_12;
  uint *puStack_10;
  uint16_t uStack_e;
  uint16_t scratch;
  uint *puStack_a;
  uint16_t uStack_8;
  far_t far *uStack_6;   /* was uint32_t: assigned far_t * values */
  byte bVar44;
  
  uVar19 = (undefined1)((uint)in_CX >> 8);
  cVar25 = (char)unaff_DI;
  uVar68 = (undefined1)((uint)unaff_DI >> 8);
  if (partyIndex != 0xff) {
    uStack_1e = 0;
    uVar67 = 0;
    uVar69 = 0;
    iStack_22 = 0;
    uStack_20 =(uint16_t)( (byte *)__C0_ASM_CopyRight + 6);
    cVar14 = (char)_SS;
    uVar65 = (undefined1)((uint)_SS >> 8);
    _fmemset(MK_FP(_SS, &uStack_28), 0, 6);
    _fmemset(MK_FP(_SS, &uStack_2e), 0, 6);
    _fmemset(MK_FP(GUnitDescriptions[partyIndex].seg, GUnitDescriptions[partyIndex].ofs + 0x9a), 0, 3);
    _fmemset(MK_FP(_SS, &uStack_a), 0, 6);
    if (Difficulty == '\x01') {
      uStack_38 = 4000;
    }
    else if (Difficulty == '\x02') {
      uStack_38 = 3000;
    }
    else {
      uStack_38 = 2000;
    }
    iStack_36 = 0;
    resourceTotals[0] = 0;
    uStack_34 = 0;
    iStack_3c = 0;
    _fmemset(MK_FP(_SS, &uStack_42), 0, 8);
    uStack_14 =(uint16_t)( (far_t far *)&GUnitDescriptions[3].ofs);
    while (uStack_14 = (far_t far *)((int)uStack_14 + 1), uStack_14 < GUnitCount) {
      pbVar2 = &((unit_t *)GUnits)[(int)uStack_14].flags;
      *pbVar2 = *pbVar2 & 0xfd;
    }
    bVar17 = *(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x3f);
    uVar23 = CONCAT11(uVar19,bVar17);
    uStack_e =(uint16_t)( (uint *)(0x1000 << (bVar17 & 0x1f)));
    *(undefined1 *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xad) = 0;
    _fmemset(MK_FP(GUnitDescriptions[partyIndex].seg, GUnitDescriptions[partyIndex].ofs + 0xaa), 0, 3);
    iVar30 = CONCAT11(uVar69,uVar67);
    if (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x3f) == '\0') {
      pbVar2 = (uint16_t)((byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5d));
      *pbVar2 = *pbVar2 | 4;
    }
    else {
      pbVar2 = (uint16_t)((byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5d));
      *pbVar2 = *pbVar2 & 0xf9;
    }
    pbVar2 = (uint16_t)((byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5d));
    *pbVar2 = *pbVar2 & 0xf7;
    (GLeaderSheets[partyIndex])->maxTrade = 0;
    *(undefined1 *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xa6) = 0;
    *(undefined1 *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xa5) = 0;
    *(undefined1 *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xa9) = 0;
    bVar17 = (GLeaderSheets[partyIndex])->classStr;
    (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)( (far_t far *)CONCAT11(bVar17,(byte)uStack_6));
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar17 * 0x95) == '\x01') {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(far_t far *)uStack_6);
      uVar12 = (uint3)uStack_6;
    }
    else {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((far_t far *)uStack_6);
      uVar12 = (uint3)uStack_6;
    }
    (*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) = (byte)(uVar12 >> 8);
    if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) * 0x95) == '\0') ||
       (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) * 0x95) == '\x05')) {
      uStack_6 = (far_t far *)CONCAT13(1,uVar12);
    }
    else {
      uStack_6 = (far_t far *)(ulong)uVar12;
    }
    *(undefined1 *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xa8) = 0;
    GCanPromote = '\0';
    puVar49 = (uint *)&GUnitDescriptions[3].ofs;
    while (puVar50 = puVar49, puVar49 = (uint *)((int)puVar50 + 1), puVar49 < GUnitCount) {
      uVar53 = (uint16_t)((ulong)GUnits >> 0x10);
      units = (unit_t *)GUnits;
      if (units[(int)puVar49].unitType == partyIndex) {
        (*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) = (units + (int)puVar49)->bldType;
        uStack_16 =(uint16_t)( (far_t far *)ovr_alignUp4(units[(int)puVar49].x,0,0));
        uVar53 = (uint16_t)((ulong)GUnits >> 0x10);
        uStack_18 = ((unit_t *)GUnits)[(int)puVar49].y;
        puStack_10 = (uint *)0x0;
        uStack_1a = (uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) << 8;
        while( true ) {
          if (3 < (byte)uStack_1a) break;
          puStack_10 = (uint *)((uint)puStack_10 |
                               ((short (*) [60] [148])GMapFlags)[-1][uStack_18 + 0x3b]
                               [(int)uStack_16 + (uStack_1a & 0xff) + 0x92] & 0x3000U);
          uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(byte)uStack_1a + 1);
        }
        puStack_12 = (uint *)0x0;
        if ((*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x11e) & 3) == 1) {
          uStack_1a = (uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) << 8;
          while ((byte)uStack_1a < 4) {
            puStack_12 = (uint *)((uint)puStack_12 |
                                 (*(short (*) [60] [148])GMapFlags)[uStack_18]
                                 [(int)uStack_16 + (uStack_1a & 0xff) + 0x92] & 0x3000U);
            uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(byte)uStack_1a + 1);
          }
        }
        if ((((uint)uStack_e & (uint)puStack_10) != 0) || (((uint)uStack_e & (uint)puStack_12) != 0)
           ) {
          pbVar2 = &((unit_t *)GUnits)[(int)puVar49].flags;
          *pbVar2 = *pbVar2 | 3;
          pfVar20 = (far_t far *)(*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) - 7);
          units = (unit_t *)GUnits;
          uVar53 = (uint16_t)((ulong)GUnits >> 0x10);
          if (pfVar20 < (far_t far *)((byte *)__C0_ASM_CopyRight + 0x12)) {
            puVar38 = (unit_t *)((int)pfVar20 * 2);
            bVar16 = (byte)pfVar20;
            uVar19 = (undefined1)((uint)pfVar20 >> 8);
            bVar17 = (byte)uVar23;
            bVar15 = (byte)(uVar23 >> 8);
            switch((uint16_t)pfVar20)   /* hand fix: case values are ints */ {
            case (uint16_t)0x0:
              AgntAnms[0x68].ey = AgntAnms[0x68].ey | 0x195d;
              puVar3 = unaff_DI;
              iVar30 = 1 - (*puVar3 & 3);
              *puVar3 = *puVar3 + (uint)(0 < iVar30) * iVar30;
              *(char *)puVar49 = (char)*puVar49 + '\x01';
              uVar33 = CONCAT11(uVar19,(s_my_s_we_in_this_neighbor_b984[0x4c] - 0x2fU)
                                       + (0xe7U < (byte)
                                                  s_my_s_we_in_this_neighbor_b984
                                                  [0x4c]));
              puVar3 = (uint *)((int)unaff_DI + (int)((int)&puVar38[-0xd8c].y + 1));
              uVar22 = (uint)(0x46 < (byte)(s_my_s_we_in_this_neighbor_b984[0x4c] +
                                           0x18U) ||
                             CARRY1(s_my_s_we_in_this_neighbor_b984[0x4c] - 0x2fU,
                                    0xe7U < (byte)s_my_s_we_in_this_neighbor_b984
                                                  [0x4c]));
              uVar48 = (int)resourceTotals + (-0x1f - *puVar3);
              iVar30 = -uVar22;
              puVar8 = (undefined1 *)(uint)(&stk_ffaf < (undefined1 *)*puVar3 || uVar48 < uVar22)
              ;
              puVar10 = &stk_fffe + -*puVar49;
              uVar22 = (uint)(&stk_fffe < (undefined1 *)*puVar49 || puVar10 < puVar8);
              uVar32 = (int)puVar38 - *(uint *)(&puVar38->bldType + (int)unaff_DI);
              iVar39 = uVar32 - uVar22;
              uVar22 = (uint)(puVar38 < *(unit_t **)(&puVar38->bldType + (int)unaff_DI) ||
                             uVar32 < uVar22);
              uVar32 = 0x145d - *(uint *)(iVar39 + (int)unaff_DI);
              iVar52 = uVar32 - uVar22;
              uVar22 = (uint)(0x145d < *(uint *)(iVar39 + (int)unaff_DI) || uVar32 < uVar22);
              uVar32 = uVar33 - *unaff_DI;
              iVar29 = uVar32 - uVar22;
              uVar22 = (uint)(uVar33 < *unaff_DI || uVar32 < uVar22);
              uVar32 = (int)(puVar10 + -(int)puVar8) - (uVar48 + iVar30);
              bVar58 = puVar10 + -(int)puVar8 < (undefined1 *)(uVar48 + iVar30) || uVar32 < uVar22;
              uVar32 = uVar32 - uVar22;
              bVar26 = (byte)((uint)iVar29 >> 8);
              bVar27 = (byte)((uint)iVar39 >> 8);
              bVar16 = bVar26 - bVar27;
              bVar59 = bVar26 < bVar27 || bVar16 < bVar58;
              bVar35 = (byte)iVar29;
              bVar16 = bVar16 - bVar58;
              bVar43 = (byte)iVar52;
              bVar26 = bVar43 - bVar16;
              bVar58 = bVar43 < bVar16 || bVar26 < bVar59;
              bVar34 = (byte)((uint)iVar52 >> 8);
              bVar26 = bVar26 - bVar59;
              bVar43 = bVar27 - *(byte *)(iVar39 + -0x4ae6);
              bVar59 = bVar27 < *(byte *)(iVar39 + -0x4ae6) || bVar43 < bVar58;
              bVar43 = bVar43 - bVar58;
              bVar27 = bVar35 - (char)unaff_DI[0x250d];
              bVar58 = bVar35 < (byte)unaff_DI[0x250d] || bVar27 < bVar59;
              bVar27 = bVar27 - bVar59;
              bVar35 = (byte)iVar39 - AgntAnms[0xf].frmid;
              bVar59 = (byte)iVar39 < AgntAnms[0xf].frmid || bVar35 < bVar58;
              bVar35 = bVar35 - bVar58;
              bVar9 = bVar43 - bVar27;
              bVar44 = bVar9 - bVar59;
              puVar36 = (uint *)CONCAT11(bVar44,bVar35);
              uVar22 = (uint)(bVar43 < bVar27 || bVar9 < bVar59);
              uVar33 = uVar32 - uVar23;
              puVar47 = (uint *)(uVar33 - uVar22);
              puVar3 = (uint *)((int)unaff_DI + -0x57e7);
              uVar33 = (uint)(uVar32 < uVar23 || uVar33 < uVar22);
              uVar22 = *puVar3;
              uVar32 = *puVar3;
              *puVar3 = (uVar32 - (int)puVar47) - uVar33;
              puVar3 = (uint *)((int)puVar47 + 0x7419);
              uVar33 = (uint)(uVar22 < puVar47 || uVar32 - (int)puVar47 < uVar33);
              uVar32 = *puVar3;
              uVar22 = *puVar3;
              *puVar3 = (uVar22 - uVar23) - uVar33;
              puVar3 = puVar50 + 0xd;
              uVar22 = (uint)(uVar32 < uVar23 || uVar22 - uVar23 < uVar33);
              puVar50 = (uint *)*puVar3;
              uVar23 = *puVar3;
              *puVar3 = (uVar23 - (int)puVar36) - uVar22;
              *(uint16_t *)(uVar48 + iVar30 + -2) =(uint16_t)( unaff_DI);
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
              uVar23 = (uint)(puVar50 < puVar36 || uVar23 - (int)puVar36 < uVar22);
              (*(uint16_t *)((uint8_t *)&("Peaceful") + 4)) = (0x6665U - (int)unaff_DI) - uVar23;
              uVar23 = (uint)((uint)0x6665 < unaff_DI || (uint)(0x6665U - (int)unaff_DI) < uVar23);
              bVar58 = (uint)AgntAnms[6].y < CONCAT11(bVar34,bVar26);
              uVar22 = AgntAnms[6].y - CONCAT11(bVar34,bVar26);
              AgntAnms[6].y = uVar22 - uVar23;
              uVar23 = (uint)(bVar58 || uVar22 < uVar23);
              uVar22 = (uVar48 + iVar30 + -2) - (int)unaff_DI;
              bVar58 = (uint *)(uVar48 + iVar30 + -2) < unaff_DI || uVar22 < uVar23;
              iVar30 = -uVar23;
              puVar45 = (uint *)(uVar22 + iVar30);
              bVar59 = bVar26 < bVar15 || (byte)(bVar26 - bVar15) < bVar58;
              bVar43 = (bVar26 - bVar15) - bVar58;
              bVar58 = bVar16 < bVar35 || (byte)(bVar16 - bVar35) < bVar59;
              bVar26 = (bVar16 - bVar35) - bVar59;
              bVar16 = bVar43 - bVar27;
              bVar59 = bVar43 < bVar27 || bVar16 < bVar58;
              bVar16 = bVar16 - bVar58;
              pbVar2 = (uint16_t)((byte *)((char *)((int)puVar36 + (int)puVar49) + -0x60e8));
              bVar58 = *pbVar2 < bVar15 || (byte)(*pbVar2 - bVar15) < bVar59;
              *pbVar2 = (*pbVar2 - bVar15) - bVar59;
              puVar3 = puVar47 + -0x3974;
              bVar15 = (byte)*puVar3 - bVar16;
              bVar59 = (byte)*puVar3 < bVar16 || bVar15 < bVar58;
              *(byte *)puVar3 = bVar15 - bVar58;
              puVar3 = puVar49 + 0x3c8c;
              bVar15 = (byte)*puVar3 - bVar27;
              bVar56 = (byte)*puVar3 < bVar27 || bVar15 < bVar59;
              *(byte *)puVar3 = bVar15 - bVar59;
              puVar3 = puVar47 + 0xc;
              bVar59 = (byte)*puVar3 < bVar34;
              bVar15 = (byte)*puVar3 - bVar34;
              bVar57 = bVar59 || bVar15 < bVar56;
              bVar62 = SBORROW1((byte)*puVar3,bVar34) != SBORROW1(bVar15,bVar56);
              *(byte *)puVar3 = bVar15 - bVar56;
              bVar61 = (char)(byte)*puVar3 < '\0';
              bVar60 = (byte)*puVar3 == 0;
              bVar58 = !bVar62;
              puVar50 = (uint16_t)(puVar47);
              if (!bVar58) {
                puVar3 = unaff_DI;
                unaff_DI = (uint *)((int)unaff_DI + 1);
                cVar25 = in(CONCAT11(bVar34,bVar16));
                *(char *)puVar3 = cVar25;
                puVar3 = puVar49 + 0xc;
                uVar23 = *puVar3;
                bVar43 = (byte)*puVar3 - bVar26;
                *(byte *)puVar3 = bVar43 - bVar57;
                *(uint16_t *)(uVar22 + iVar30 + -2) =(uint16_t)( puVar36);
                ((char *)((int)puVar47 + (int)puVar49))[0x18] =
                     (((char *)((int)puVar47 + (int)puVar49))[0x18] - bVar17) -
                     ((byte)uVar23 < bVar26 || bVar43 < bVar57);
                *(uint *)((int)puVar36 + (int)puVar49) =
                     *(uint *)((int)puVar36 + (int)puVar49) ^ (uint)puVar36;
                *(uint *)((int)puVar36 + (int)puVar49) =
                     *(uint *)((int)puVar36 + (int)puVar49) | (uint)puVar36;
                *(char *)((int)puVar36 + (int)puVar49) =
                     *(char *)((int)puVar36 + (int)puVar49) + bVar35;
                *puVar36 = ~*puVar36;
                puVar50 = (uint *)*puVar47;
                uVar23 = CONCAT11(bVar26,bVar27 - 0x18) & 0x9e1f;
                bVar61 = (int)uVar23 < 0;
                bVar60 = uVar23 == 0;
                puVar45 = puVar47 + 3;
              }
              bVar57 = bVar58 && bVar57;
              uVar53 = *puVar45;
              if (bVar60 || (bVar58 && bVar62) != bVar61) {
                bVar61 = bVar57;
                if ((!bVar58 || !bVar59 && bVar15 >= bVar56) && !bVar60) {
                  *puVar45 = (uint)puVar50;
                  uVar53 = *puVar45;
                  uVar23 = (int)(char)bVar17 + 0xe299;
                  iVar30 = uVar23 - bVar57;
                  *puVar45 = iVar30;
                  *(char *)puVar49 = -(char)*puVar49;
                  return (far_t far *)((iVar30 + -0x1d32) -
                                  (uint)((uint)(int)(char)bVar17 < 0x1d67 || uVar23 < bVar57));
                }
              }
              else {
                bVar61 = bVar17 < 0x74 || (byte)(bVar17 + 0x8c) < bVar57;
                bVar17 = (bVar17 + 0x8c) - bVar57;
              }
              bVar58 = bVar17 < 100 || (byte)(bVar17 + 0x9c) < bVar61;
              bVar15 = (bVar17 + 0x9c) - bVar61;
              bVar17 = bVar15 - 0x39;
              bVar59 = bVar15 < 0x39 || bVar17 < bVar58;
              bVar17 = bVar17 - bVar58;
              bVar15 = bVar17 - 0x14;
              bVar58 = bVar17 < 0x14 || bVar15 < bVar59;
              bVar15 = bVar15 - bVar59;
              bVar17 = bVar15 - 8;
              bVar59 = bVar15 < 8 || bVar17 < bVar58;
              bVar17 = bVar17 - bVar58;
              bVar15 = bVar17 - 5;
              bVar26 = bVar15 - bVar59;
              iVar30 = ((int)puVar50 - (int)puVar36) -
                       (uint)(bVar26 < 0xfa || (byte)(bVar26 + 6) < (bVar17 < 5 || bVar15 < bVar59))
              ;
              uVar22 = (uint)puVar49 & *(uint *)((char *)((int)puVar36 + (int)puVar49) + -0x6bdd);
              uVar32 = (uint)unaff_DI & *(uint *)((char *)((int)puVar36 + (int)unaff_DI) + 0x23);
              *puVar45 = uVar22;
              uVar22 = uVar22 & *(uint *)((int)puVar36 + uVar32);
              uVar23 = CONCAT11(bVar34,bVar16) & *(uint *)(iVar30 + uVar22);
              puVar49 = (uint *)CONCAT11(bVar44,bVar35 & bVar44 &
                                                *(byte *)((int)&_streams[0xc].curp +
                                                         CONCAT11(bVar44,bVar35 & bVar44)));
              uVar54 = *puVar45;
              *(uint *)(iVar30 + uVar22) = *(uint *)(iVar30 + uVar22) ^ (uint)(puVar45 + 1);
              *(int *)(iVar30 + uVar22) = *(int *)(iVar30 + uVar22) - (int)(puVar45 + 1);
              bVar17 = in(uVar23);
              uVar22 = uVar22 & uVar23;
              puVar3 = (uint *)((int)puVar49 + (int)((char *)0x2a321 + uVar22));
              *puVar3 = *puVar3 & uVar32;
              *(uint *)(uVar32 + 0x21) = *(uint *)(uVar32 + 0x21) & (uint)puVar49;
              *puVar49 = *puVar49 & uVar32;
              puVar3 = (uint *)&AgntAnms[0x5c].sx;
              *puVar3 = *puVar3 & (uint)(puVar45 + 1);
              puVar3 = (uint *)((int)puVar49 + uVar22);
              *puVar3 = *puVar3 & CONCAT11((char)((uint)uVar54 >> 8),bVar17);
              bVar16 = -(0x99 < bVar17);
              return (far_t far *)CONCAT11((char)((uint)uVar54 >> 8),
                                       bVar16 + (9 < (bVar16 & 0xf) | 9 < (bVar17 & 0xf) | in_AF) *
                                                '\x06' + (0x99 < bVar16 || 0x99 < bVar17) * '`');
            case (uint16_t)0x1:
              *(uint *)(&stk_8ed6 + (int)unaff_DI) =
                   *(uint *)(&stk_8ed6 + (int)unaff_DI) & uVar23;
              return pfVar20;
            default:
              goto switchD_5000_123d_caseD_2;
            case (uint16_t)0x3:
            case (far_t far *)0x14:
              goto switchD_5000_123d_caseD_3;
            case (uint16_t)0x4:
              break;
            case (uint16_t)0x5:
              do {
                uVar11 = *(uint32_t *)(((uint)pfVar20 & 0xff) << 2);
                ovr_blitLabel((char *)auStackY_11a
                                      [(int)puVar49 * 2 + (uint)*(byte *)((int)uVar11 + 0x2f) * 8]);
                while( true ) {
                  ovc27_textCharmed();
                  ovr_stsprintf(acStackY_13e);
                  iVar30 = ovr_font_textWidth(acStackY_13e,0,0,0,0);
                  TextBlitX = 0x89 - iVar30;
                  ovr_blitLabel(acStackY_13e);
                  ovr_stsprintf(acStackY_13e);
                  iVar30 = ovr_font_textWidth(acStackY_13e,0,0,0,0);
                  puVar28 = (uint16_t *)(0xd4 - iVar30);
                  TextBlitX = (uint16_t)puVar28;
                  ovr_blitLabel(acStackY_13e);
                  puVar49 = (uint *)((int)puVar49 + 1);
L_OVC22_5087_0234_323C:
                  TextBlitY = TextBlitY + 0xc;
                  cVar25 = (char)uVar23;
                  if ((int)(scratch >> 8) <= (int)puVar49) goto L_OVC22_5087_0234_32B8;
                  TextBlitX = 0x11;
                  if ((4 < (int)puVar49) && ((char)scratch != '\0')) break;
                  ovr_blitLabel((char *)auStackY_96[(int)puVar49 * 2]);
                }
                pfVar20 = (far_t far *)(uint)partyIndex;
              } while( true );
            case (far_t far *)0x6:
              *(uint *)(&stk_681c + (int)puVar49) =
                   *(uint *)(&stk_681c + (int)puVar49) & uVar23;
            case (far_t far *)0xb:
              *(uint *)(&stk_681c + (int)puVar49) =
                   *(uint *)(&stk_681c + (int)puVar49) & uVar23;
              ovr_blitLabel(&stk_fffe);
              iVar30 = ovr_font_textWidth((char *)"POPULATION",0,0,0,0);
              puVar28 = (uint16_t *)(0xd4 - iVar30);
              TextBlitX = (uint16_t)puVar28;
              ovr_blitLabel((char *)"POPULATION");
              puVar49 = (uint *)0x0;
              goto L_OVC22_5087_0234_323C;
            case (far_t far *)0x7:
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
              return pfVar20;
            case (far_t far *)0x8:
              bVar26 = (&stk_fffe)[(int)unaff_DI];
              in_AF = 9 < (bVar16 & 0xf) | in_AF;
              uVar46 = (uint)&stk_ffb4 ^ *(uint *)((int)puVar49 + (int)(&puVar38->level + -1));
              uVar22 = (uint)puVar38 ^ (uint)puVar49;
              uVar32 = CONCAT11((byte)(uVar22 >> 8) ^ *(byte *)((int)unaff_DI + uVar22 + 0x8332),
                                (char)uVar22);
              bVar27 = bVar15 ^ 0x5d ^ *(byte *)((int)unaff_DI + uVar32 + 0x32);
              uVar22 = CONCAT11(bVar26,bVar27) ^ 0x1900;
              *(uint *)(&stk_fffe + (int)puVar49) =
                   *(uint *)(&stk_fffe + (int)puVar49) ^ (uint)puVar49;
              uVar48 = (int)puVar49 - *(int *)(&stk_fffe + (int)puVar49);
              uVar32 = uVar32 ^ uVar46;
              uVar33 = (uint)&stk_fffe ^ uVar32;
              uVar23 = CONCAT11(uVar19,bVar16 + in_AF * -6 + (0x99 < bVar16) * -0x60 + '2' +
                                       (puVar49 < *(uint **)(&stk_fffe + (int)puVar49))) - 0x5ceU
                       ^ uVar23;
              puVar3 = (uint *)((int)unaff_DI + uVar32 + 0xa231);
              *puVar3 = *puVar3 ^ uVar48;
              *(uint *)((char *)0x2c131 + uVar32) =
                   *(uint *)((char *)0x2c131 + uVar32) ^
                   uVar22;
              puVar3 = (uint *)(uVar33 + uVar48 + 0x31);
              *puVar3 = *puVar3 ^ (uint)unaff_DI;
              iVar29 = uVar48 + 1;
              *(uint *)(uVar33 + (int)unaff_DI) = *(uint *)(uVar33 + (int)unaff_DI) ^ uVar46;
              *unaff_DI = *unaff_DI ^ uVar22;
              puVar51 = (uint16_t *)((uint)unaff_DI ^ uVar46);
              bVar43 = (byte)(uVar23 >> 8);
              bVar16 = (byte)uVar23 ^ bVar27;
              pbVar2 = (uint16_t)((byte *)((int)puVar51 + uVar33 + 0xa330));
              *pbVar2 = *pbVar2 ^ bVar26 ^ 0x19;
              *(byte *)(puVar51 + -0x3be8) = *(byte *)(puVar51 + -0x3be8) ^ (byte)uVar32;
              pbVar2 = (uint16_t)((byte *)(uVar32 + iVar29 + 0x30));
              bVar26 = (byte)(uVar32 >> 8);
              *pbVar2 = *pbVar2 ^ bVar26;
              pbVar6 = (uint16_t)((byte *)(puVar51 + 1));
              uVar53 = in(uVar22);
              *puVar51 = uVar53;
              pbVar2 = (uint16_t)((byte *)(uVar32 + iVar29 + 0x30));
              *pbVar2 = *pbVar2 ^ (byte)uVar32;
              *(uint *)(uVar46 - 2) = uVar22;
              *pbVar6 = *pbVar6 ^ bVar26;
              *pbVar6 = *pbVar6 ^ bVar15;
              *(byte *)(uVar33 + iVar29) = *(byte *)(uVar33 + iVar29) ^ bVar43;
              *pbVar6 = *pbVar6 ^ bVar17;
              *(byte *)(uVar33 + iVar29) = *(byte *)(uVar33 + iVar29) ^ bVar16;
              in_AF = 9 < (bVar16 & 0xf) | in_AF;
              bVar17 = bVar16 + in_AF * -6 + (0x99 < bVar16) * -0x60;
              iVar30 = *(int *)(uVar46 - 2);
              uVar23 = CONCAT11(bVar43 ^ bVar26,
                                bVar17 + (9 < (bVar17 & 0xf) | in_AF) * -6 +
                                (0x99 < bVar17 || 0x99 < bVar16) * -0x60) ^ 0xaf;
              uVar33 = uVar33 ^ uVar23;
              bVar17 = (byte)uVar23 ^ (byte)*(uint16_t *)(uVar32 + iVar29);
              { int _rep0; for (_rep0 = 0; _rep0 < 27; _rep0++)
                  *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              }
              pcVar1 = (uint16_t)((char *)(iVar30 + -0x75));
              *pcVar1 = *pcVar1 + bVar27;
              in(uVar22);
              *(int *)(uVar46 - 0x10) = iVar29;
              *(int *)(uVar46 - 0x12) = iVar30;
              iVar30 = *(int *)(uVar33 + 6);
              iVar29 = *(int *)(uVar33 + 8);
              if ((((iVar30 < 0) || (iVar29 < 0)) || (0x93 < iVar30 + 1)) || (0x3b < iVar29 + 1)) {
                placementStatus = 2;
                pfVar20 = (far_t far *)((char *)0x2400);
              }
              else {
                uVar53 = (uint16_t)((ulong)GMapFlags >> 0x10);
                if ((((*(short (*) [60] [148])GMapFlags)[iVar29][iVar30] & 3U) == 0) &&
                   (((*(short (*) [60] [148])GMapFlags)[iVar29 + 1][iVar30] & 3U) == 0)) {
                  *(int *)(uVar33 - 10) =
                       (int)(char)(*(byte (*) [59] [148])GMapCells)[iVar29 + 1][iVar30];
                  *(int *)(uVar33 - 8) =
                       (int)(char)(*(byte (*) [59] [148])GMapCells)[iVar29 + 1][iVar30 + 1];
                  iVar30 = *(int *)(uVar33 - 10);
                  *(uint16_t *)(uVar33 - 2) = *(uint16_t *)(uVar33 - 10);
                  if (*(int *)(uVar33 - 8) < iVar30) {
                    iVar30 = *(int *)(uVar33 - 8);
                  }
                  if (*(int *)(uVar33 - 2) < *(int *)(uVar33 - 8)) {
                    *(uint16_t *)(uVar33 - 2) = *(uint16_t *)(uVar33 - 8);
                  }
                  uVar23 = *(int *)(uVar33 - 2) - iVar30;
                  if ((int)uVar23 < 9) {
                    placementStatus = 3;
                    pfVar20 = (far_t far *)((char *)0x2401);
                  }
                  else {
                    pfVar20 = (far_t far *)(uVar23 & 0xff00);
                  }
                }
                else {
                  placementStatus = 1;
                  pfVar20 = (far_t far *)((char *)0x2400);
                }
              }
              return pfVar20;
            case (far_t far *)0x9:
              do {
                ovc22_textRingProt((byte)pfVar20);
                do {
                  uStack_16 =(uint16_t)( (far_t far *)((int)uStack_16 + 1));
                  if ((int)(uint)GLeaderCount <= (int)uStack_16) {
                    GGameState = 0x3e;
                    if (DebugVerbose != false) {
                      printf("%d \r");
                    }
                    unaff_DI = (uint *)&GUnitDescriptions[3].ofs;
                    goto L_upd_units_5087_1d7d_202C;
                  }
                } while (((char_sheet_t *)(((int)uStack_16 * 4)))->active == '\0');
                pfVar20 = (far_t far *)CONCAT11(0x21,(undefined1)uStack_16);
              } while( true );
            case (far_t far *)0xa:
              iVar29 = 0x6574;
              break;
            case (far_t far *)0xc:
              (*(uint8_t *)((uint8_t *)&(iVar30))) = (puVar38 + -0xc24)->bldType;
              (*(uint8_t *)((uint8_t *)&(iVar30) + 1)) = (puVar38 + -0xc24)->level;
              do {
                pfVar20 = (far_t far *)uStack_6;
                if (units[iVar30].unitType == partyIndex) {
                  if ((byte)uStack_6 == (*(uint8_t *)((uint8_t *)&(uStack_6) + 1))) {
L_OVC22_5087_4975_4ABE:
                    (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)( pfVar20);
                    if ((byte)uStack_8 < ListCount) {
                      puStack_a = (uint *)units[*(int *)((uStack_8 & 0xff) * 2 + -0x6d44)].x;
                      scratch = units[*(int *)((uStack_8 & 0xff) * 2 + -0x6d44)].y;
                    }
                    else {
                      puStack_a = (uint *)(GLeaderSheets[partyIndex])->x;
                      scratch = (GLeaderSheets[partyIndex])->y;
                    }
                    uVar53 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
                    iVar29 = (int)*(uint32_t *)((uint)partyIndex << 2);
                    iVar30 = *(int *)(iVar29 + 0x58);
                    if ((iVar30 < 1) && ((iVar30 < 0 || (*(uint *)(iVar29 + 0x56) < 10)))) {
                      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(far_t far *)uStack_6);
                    }
                    else {
                      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((far_t far *)uStack_6);
                    }
                    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                                  (uint)(GLeaderSheets[partyIndex])->classStr * 0x95) & 0x80) == 0) {
                      uStack_6 = (far_t far *)(ulong)(uint3)uStack_6;
                    }
                    else {
                      uStack_6 = (far_t far *)CONCAT13(3,(uint3)uStack_6);
                    }
                    if (((GLeaderSheets[partyIndex])->flags5d & 2) != 0) {
                      uStack_6 = (far_t far *)((ulong)uStack_6 | 0x1000000);
                    }
                    uVar11 = *(uint32_t *)((uint)partyIndex << 2);
                    if ((*(byte *)((int)uVar11 + 0x5d) & 4) != 0) {
                      uStack_6 = (far_t far *)((ulong)uStack_6 | 0x2000000);
                    }
                    uVar23 = ovc22_searchCellsAround
                                       ((uint *)CONCAT13((char)((uint)&scratch >> 8),
                                                         CONCAT12((char)&scratch,_SS)),
                                        (uint *)CONCAT13((char)(((uint)partyIndex << 2) >> 8),
                                                         CONCAT12(partyIndex,_SS)),
                                        (*(uint8_t *)((uint8_t *)&(uStack_6) + 3)),(*(uint8_t *)((uint8_t *)&(uStack_6) + 2)),cVar25);
                    pfVar20 = (far_t far *)(uVar23 & 0xff);
                    if (pfVar20 != (far_t far *)0x0) {
                      if (pfVar20 != (far_t far *)((int)(uint32_t *)&_DATA + 1U)) {
                        return pfVar20;
                      }
                      uStack_e =(uint16_t)( (uint *)ovc22_usesRandBelow(partyIndex,(uint16_t)puStack_a,scratch)
                      );
                      if (uStack_e == (uint *)0x0) {
                        puStack_a = (uint *)(GLeaderSheets[partyIndex])->x;
                        scratch = (GLeaderSheets[partyIndex])->y;
                      }
                      else {
                        if ((BuildingTypes[uStack_e].flags2 & 0x60) == 0) {
                          uVar53 = (uint16_t)
                                   ((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
                          iVar29 = (int)*(uint32_t *)((uint)partyIndex << 2);
                          iVar30 = *(int *)(iVar29 + 0x58);
                          if ((iVar30 < 0) ||
                             ((iVar30 == 0 &&
                              (*(uint *)(iVar29 + 0x56) < BuildingTypes[uStack_e].cost)))
                             ) {
                            uVar53 = (uint16_t)
                                     ((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
                            iVar30 = (int)*(uint32_t *)((uint)partyIndex << 2);
                            *(uint16_t *)(iVar30 + 0x58) = 0;
                            *(uint16_t *)(iVar30 + 0x56) = 0;
                          }
                          else {
                            uVar22 = BuildingTypes[uStack_e].cost;
                            uVar53 = (uint16_t)
                                     ((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
                            iVar30 = (int)*(uint32_t *)((uint)partyIndex << 2);
                            puVar3 = (uint *)(iVar30 + 0x56);
                            uVar23 = *puVar3;
                            *puVar3 = *puVar3 - uVar22;
                            piVar4 = (int *)(iVar30 + 0x58);
                            *piVar4 = *piVar4 - (uint)(uVar23 < uVar22);
                          }
                        }
                        ovr_createConstructionRecordFar((byte)uStack_e,0,0,0,0,0,0,0,0);
                      }
                    }
                    if (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x3f) == '\0') {
                      if ((GLeaderSheets[partyIndex])->housing <
                          (GLeaderSheets[partyIndex])->population) {
                        pfVar20 = (far_t far *)ovr_ovc18_textTypeLen(partyIndex,0,0,0,0,0);
                      }
                      else {
                        pfVar20 = (far_t far *)ovr_ovc18_textTypeLen(partyIndex,0,0,0,0,0);
                      }
                    }
                    else {
                      pfVar20 = (far_t far *)ovr_ovc18_textTypeLen(partyIndex,0,0,0,0,0);
                    }
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
                    return pfVar20;
                  }
                  uStack_6 = (far_t far *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),(byte)uStack_6 + '\x01');
                }
                do {
                  bVar17 = (byte)uStack_8 + 1;
                  uStack_8 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_8) + 1)),bVar17);
                  pfVar20 = (far_t far *)uStack_6;
                  if (ListCount <= bVar17) goto L_OVC22_5087_4975_4ABE;
                } while (*(char *)((uint)(units + *(int *)((uint)bVar17 * 2 + -0x6d44))->bldType *
                                   0x27 + 0x133) != '\x12');
                iVar30 = *(int *)((uint)bVar17 * 2 + -0x6d44);
              } while( true );
            case (far_t far *)0xd:
              bVar17 = (byte)((uint)puVar38 >> 8);
              if (!CARRY1(bVar17,bVar17) && ((uint)puVar38 & 0x7f00) != 0) {
                uVar23 = ovr_ovc23_findRecordAt((int)unaff_DI,0,0);
                if (uVar23 == 0xffff) {
                  pfVar20 = (far_t far *)(uint)((unit_t *)GUnits + (*(uint16_t *)((uint8_t *)&(uStack_6) + 2)))->bldType;
                  if ((BuildingTypes[(uint)pfVar20].flags2 & 0x20) == 0) {
                    pfVar20 = (far_t far *)0x0;
                  }
                  else if (BuildingTypes[(uint)pfVar20].resource == '\0') {
                    if (*(char *)((int)*(uint32_t *)((uint)bStack0008 << 2) + 0x2f) == '\x05') {
                      pfVar20 = pfVar20 + 6;
                    }
                    else {
                      pfVar20 = (far_t far *)&pfVar20[1].seg;
                    }
                  }
                }
                else {
                  pfVar20 = (far_t far *)0x0;
                }
                return pfVar20;
              }
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            case (far_t far *)0xe:
              puVar38->bldType = puVar38->bldType | bVar16;
              if (uVar23 != 0) {
                pfVar20 = (far_t far *)*(far_t far **)((char *)0x24751);
              }
              *(uint *)((char *)0x24721) = *(uint *)((char *)0x24721) ^ (uint)pfVar20;
              uVar19 = in(5);
              if (((uint)pfVar20 | 0x606) == 0) {
                *unaff_DI = *unaff_DI +
                            ((CONCAT11((char)(((uint)pfVar20 | 0x606) >> 8),uVar19) + 0x53e) -
                            *unaff_DI);
              }
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            case (far_t far *)0xf:
              do {
                uVar53 = (uint16_t)((ulong)Entities >> 0x10);
                uVar23 = CONCAT11(uVar68,cVar25) -
                         *(uint16_t *)
                          ((int)&(((entity_t *)Entities)->base).x +
                          CONCAT11((char)((int)pfVar20 % (int)(char)(&stk_0035)[(int)puVar49]),
                                   (char)((int)pfVar20 / (int)(char)(&stk_0035)[(int)puVar49])) *
                          iVar29);
                uVar32 = (int)uVar23 >> 0xf;
                uVar22 = ((char_sheet_t *)(((int)puStack_a << 2)))->y -
                         ((entity_t *)Entities)[scratch].base.y;
                uVar33 = (int)uVar22 >> 0xf;
                puVar49 = (uint *)((int)((uVar23 ^ uVar32) - uVar32) / 2 +
                                  ((uVar22 ^ uVar33) - uVar33));
                if (puVar49 < uStack_e) {
                  uStack_e =(uint16_t)( puVar49);
                  unaff_DI = (uint *)scratch;
                }
                if (puVar49 < (byte *)__C0_ASM_CopyRight + 6) {
                  piVar4 = (int *)((int)*(uint32_t *)((int)puStack_a << 2) + 0x43);
                  *piVar4 = *piVar4 + 1;
                }
                do {
                  while( true ) {
                    scratch = scratch + 1;
                    while (EntityCount <= scratch) {
                      ((char_sheet_t *)(((int)puStack_a << 2)))->nearestEnemy =(uint16_t)( unaff_DI);
                      uStack_16 =(uint16_t)( (far_t far *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_16) + 1)),0xff));
                      if (((char_sheet_t *)(((int)puStack_a << 2)))->spyReports != '\0') {
                        puStack_10 = (uint *)0xffff;
                        for (scratch = 0; (int)scratch < (int)(uint)GLeaderCount;
                            scratch = scratch + 1) {
                          if ((*(char *)((int)*(uint32_t *)(scratch << 2) + 0x3f) !=
                               *(char *)((int)*(uint32_t *)((int)puStack_a << 2) + 0x3f)) &&
                             (uVar23 = ((char_sheet_t *)(((int)puStack_a << 2)))->x -
                                       (GLeaderSheets[scratch])->x,
                             uVar32 = (int)uVar23 >> 0xf,
                             uVar22 = ((char_sheet_t *)(((int)puStack_a << 2)))->y -
                                      (GLeaderSheets[scratch])->y,
                             uVar33 = (int)uVar22 >> 0xf,
                             puVar49 = (uint *)((int)((uVar23 ^ uVar32) - uVar32) / 2 +
                                               ((uVar22 ^ uVar33) - uVar33)), puVar49 < puStack_10))
                          {
                            uStack_16 =(uint16_t)( (far_t far *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_16) + 1)),(char)scratch));
                            puStack_10 = (uint16_t)(puVar49);
                          }
                        }
                      }
                      ((char_sheet_t *)(((int)puStack_a << 2)))->nearestEnemyLeader =
                           (undefined1)uStack_16;
                      do {
                        puStack_a = (uint *)((int)puStack_a + 1);
                        if ((int)(uint)GLeaderCount <= (int)puStack_a) {
                          for (puStack_a = (uint *)0x0; pfVar20 = (far_t far *)(uint)GLeaderCount,
                              (int)puStack_a < (int)pfVar20;
                              puStack_a = (uint *)((int)puStack_a + 1)) {
                            if ((((char_sheet_t *)(((int)puStack_a << 2)))->spyReports != '\0'
                                ) && (((char_sheet_t *)(((int)puStack_a << 2)))->active !=
                                      '\0')) {
                              ovc25_intelAttackingNotice((byte)puStack_a);
                              if (((char_sheet_t *)(((int)puStack_a << 2)))->nearestEnemy == -1)
                              {
                                uStack_14 =(uint16_t)( (far_t far *)0xffff);
                              }
                              else {
                                unaff_DI = (uint *)((char_sheet_t *)(((int)puStack_a << 2)))->nearestEnemy;
                                uVar53 = (uint16_t)((ulong)Entities >> 0x10);
                                uVar23 = ((char_sheet_t *)(((int)puStack_a << 2)))->x
                                         - (((entity_t *)Entities + (int)unaff_DI)->base).x;
                                uVar32 = (int)uVar23 >> 0xf;
                                uVar22 = ((char_sheet_t *)(((int)puStack_a << 2)))->y
                                         - ((entity_t *)Entities)[(int)unaff_DI].base.y;
                                uVar33 = (int)uVar22 >> 0xf;
                                uStack_14 =(uint16_t)( (far_t far *)((int)((uVar23 ^ uVar32) - uVar32) / 2 +
                                                     ((uVar22 ^ uVar33) - uVar33)));
                              }
                              if ((((char_sheet_t *)(((int)puStack_a << 2)))->enemiesNear == 0)
                                 || ((byte *)__C0_ASM_CopyRight + 6 <= uStack_14)) {
                                if ((((char_sheet_t *)(((int)puStack_a << 2)))->nearestEnemyLeader ==
                                     -1) || ((((char_sheet_t *)(((int)puStack_a << 2)))->flags5d & 1) == 0)) {
                                  if (((char_sheet_t *)(((int)puStack_a << 2)))->unitsOnTile <
                                      10) {
                                    ovc25_usesAlignUp43((byte)puStack_a,10,
                                                        ((char_sheet_t *)(((int)puStack_a << 2)))->x,((char_sheet_t *)(((int)puStack_a << 2)))->y,'\0');
                                    ((char_sheet_t *)(((int)puStack_a << 2)))->reportState = 0;
                                  }
                                  else {
                                    ((char_sheet_t *)(((int)puStack_a << 2)))->reportState = 0;
                                    bVar17 = ((char_sheet_t *)(((int)puStack_a << 2)))->classStr;
                                    uStack_18 = CONCAT11(bVar17,(undefined1)uStack_18);
                                    iVar30 = ovc25_compute1(bVar17);
                                    uStack_6 = (far_t far *)CONCAT22(iVar30,(far_t far *)uStack_6);
                                    if ((int)(uint)PlayerCount < iVar30) {
                                      uVar31 = ovr_randBelow(0x28,0);
                                      pfVar20 = (far_t far *)(((char_sheet_t *)(((int)puStack_a << 2)))->x + -0x14 + (uVar31 & 0xff));
                                      (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)( pfVar20);
                                      if ((int)pfVar20 < 4) {
                                        (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)( (far_t far *)__C0_ASM_CopyRight);
                                      }
                                      if (0x8c < (int)(far_t far *)uStack_6) {
                                        (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)( (far_t far *)&_brklvl);
                                      }
                                      uVar31 = ovr_randBelow(0x14,0);
                                      uStack_8 = ((char_sheet_t *)(((int)puStack_a << 2)))->y + -10 + (uVar31 & 0xff);
                                      if ((int)uStack_8 < 1) {
                                        uStack_8 = 1;
                                      }
                                      if (0x3a < (int)uStack_8) {
                                        uStack_8 = 0x3a;
                                      }
                                      ovr_ovc25_usesAlignUp44((char)puStack_a,1);
                                    }
                                  }
                                }
                                else {
                                  ovc25_usesEntityCount((byte)puStack_a);
                                  bVar17 = ((char_sheet_t *)(((int)puStack_a << 2)))->nearestEnemyLeader;
                                  uStack_16 =(uint16_t)( (far_t far *)CONCAT11(bVar17,(undefined1)uStack_16));
                                  if (0xe < ((char_sheet_t *)(((int)puStack_a << 2)))->unitsOnTile) {
                                    ovc25_usesAlignUp42((byte)puStack_a,10,
                                                        (GLeaderSheets[bVar17])->x,(GLeaderSheets[bVar17])->y,
                                                        ((char_sheet_t *)(((int)puStack_a << 2)))->x,((char_sheet_t *)(((int)puStack_a << 2)))->y);
                                    if (((char_sheet_t *)(((int)puStack_a << 2)))->reportState
                                        != '\x02') {
                                      uVar11 = *(uint32_t *)(((uint)uStack_16 >> 8) << 2);
                                      ovr_alignUp4(*(int *)((int)uVar11 + 0x39),0,0);
                                      uStackY_60 = 0xc5d4;
                                      pcVar21 = ovr_stsprintf(acStackY_68,
                                                              (char *)CONCAT13(0x58,CONCAT12(0xc0,
                                                  _SS)));
                                      ovr_uiNotify(pcVar21,0,0);
                                    }
                                  }
                                  ovc25_usesAlignUp43((byte)puStack_a,0xf,
                                                      ((char_sheet_t *)(((int)puStack_a << 2)))->x,((char_sheet_t *)(((int)puStack_a << 2)))->y,
                                                      '\0');
                                  ((char_sheet_t *)(((int)puStack_a << 2)))->reportState
                                       = 2;
                                }
                              }
                              else {
                                ovc25_usesEntityCount((byte)puStack_a);
                                if (9 < ((char_sheet_t *)(((int)puStack_a << 2)))->unitsOnTile)
                                {
                                  uVar53 = (uint16_t)((ulong)Entities >> 0x10);
                                  ovc25_usesAlignUp43((byte)puStack_a,5,
                                                      (((entity_t *)Entities + (int)unaff_DI)->base
                                                      ).x,((entity_t *)Entities)[(int)unaff_DI].
                                                          base.y,'\x01');
                                }
                                ovc25_usesAlignUp43((byte)puStack_a,10,
                                                    ((char_sheet_t *)(((int)puStack_a << 2)))->x,((char_sheet_t *)(((int)puStack_a << 2)))->y,
                                                    '\0');
                                ((char_sheet_t *)(((int)puStack_a << 2)))->reportState =
                                     1;
                              }
                            }
                          }
                          ovc25_clearEntityFlags();
                          return pfVar20;
                        }
                      } while (((char_sheet_t *)(((int)puStack_a * 4)))->active == '\0');
                      ((char_sheet_t *)(((int)puStack_a * 4)))->unitsOnTile = 0;
                      ((char_sheet_t *)(((int)puStack_a * 4)))->unitsNear = 0;
                      ((char_sheet_t *)(((int)puStack_a * 4)))->enemiesNear = 0;
                      ((char_sheet_t *)(((int)puStack_a * 4)))->unitCount = 0;
                      uStack_e =(uint16_t)( (uint *)0xffff);
                      unaff_DI = (uint *)0xffff;
                      puStack_12 = (uint *)ovr_alignUp4(((char_sheet_t *)(((int)puStack_a * 4)))->x,0,0)
                      ;
                      scratch = 0;
                    }
                    uVar53 = (uint16_t)((ulong)Entities >> 0x10);
                    peVar41 = (entity_t *)Entities;
                    if ((uint *)(uint)*(byte *)((int)&peVar41[scratch].base.entity + 3) != puStack_a
                       ) break;
                    uVar23 = ((char_sheet_t *)(((int)puStack_a << 2)))->x -
                             ((peVar41 + scratch)->base).x;
                    uVar32 = (int)uVar23 >> 0xf;
                    uVar22 = ((char_sheet_t *)(((int)puStack_a << 2)))->y -
                             peVar41[scratch].base.y;
                    uVar33 = (int)uVar22 >> 0xf;
                    puVar49 = (uint *)((int)((uVar23 ^ uVar32) - uVar32) / 2 +
                                      ((uVar22 ^ uVar33) - uVar33));
                    piVar4 = (int *)((int)*(uint32_t *)((int)puStack_a << 2) + 0x45);
                    *piVar4 = *piVar4 + 1;
                    if (puVar49 < (byte *)__C0_ASM_CopyRight + 6) {
                      piVar4 = (int *)((int)*(uint32_t *)((int)puStack_a << 2) + 0x41);
                      *piVar4 = *piVar4 + 1;
                      uVar53 = (uint16_t)((ulong)Entities >> 0x10);
                      if ((((char_sheet_t *)(((int)puStack_a << 2)))->y ==
                           ((entity_t *)Entities)[scratch].base.y) &&
                         (puVar50 = (uint *)ovr_alignUp4((((entity_t *)Entities + scratch)->base).x,0,0), puVar50 == puStack_12)) {
                        piVar4 = (int *)((int)*(uint32_t *)((int)puStack_a << 2) + 0x47);
                        *piVar4 = *piVar4 + 1;
                      }
                    }
                  }
                } while (AgntGs[(uint)peVar41[scratch].base.gindex].ai ==
                         *(char *)((int)*(uint32_t *)((int)puStack_a << 2) + 0x3f));
                uVar53 = ((char_sheet_t *)(((int)puStack_a << 2)))->x;
                cVar25 = (char)uVar53;
                uVar68 = (undefined1)((uint)uVar53 >> 8);
                iVar29 = 0x37;
                pfVar20 = (far_t far *)scratch;
              } while( true );
            case (far_t far *)0x10:
              puVar28 = &unitNameOfs;
              manage_applyUnitFilter
                        (partyIndex,((uint)uStack_e >> 8) - 4,
                         (char *)CONCAT13((char)((uint)*(uint16_t *)
                                                        (acStackY_68 + ((uint)pfVar20 & 0xff) * 4)
                                                >> 8),
                                          CONCAT12((char)*(uint16_t *)
                                                          (acStackY_68 + ((uint)pfVar20 & 0xff) * 4)
                                                   ,puVar28[((uint)pfVar20 & 0xff) * 2])));
              cVar25 = (char)uVar23;
L_OVC22_5087_0234_32B8:
              CurSfxType3 = 0x3c;
              (*(uint8_t *)((uint8_t *)&(entries.seg))) = cVar14;
              entries.ofs = (uint16_t)(acStackY_68 + 2);
              (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar65;
              uVar53 = ovr_ovc28_usesUiInputText(entries,0,0,0,0,0);
              cVar14 = (char)uVar53;
              uStack_e =(uint16_t)( (uint *)CONCAT11(cVar14,(byte)uStack_e));
              keyboardInputMode = 0;
              if (((cVar14 != '\0') && (cVar14 != '\x01')) && (cVar14 != -2)) {
                (&stk_bac4)[(int)unaff_DI] = (&stk_bac4)[(int)unaff_DI] + cVar25;
                puVar50 = (uint *)((char *)0x26510);
                do {
                  iVar30 = (int)puVar50 * (int)puVar28;
                  puVar50 = (uint16_t)(puVar49);
                  if (Agnts[puVar49].strengthMax < *(byte *)(iVar30 + 0x21)) {
                    Agnts[puVar49].strength =
                         Agnts[puVar49].strengthMax;
                  }
                  do {
                    puVar50 = (uint *)((int)puVar50 + 1);
                    if ((int)(uint)AgntCount <= (int)puVar50) {
                      iVar30 = ovr_audio_panFromX((agnt_t *)CONCAT11(uStack0009,bStack0008),0);
                      uVar19 = (undefined1)((uint)iVar30 >> 8);
                      ovr_play_sfxU(0x1c,0,0,0,0);
                      return (far_t far *)CONCAT11(uVar19,1);
                    }
                  } while (Agnts[puVar50].owner !=
                           *(int *)(CONCAT11(uStack0009,bStack0008) + 0x1b));
                  uVar53 = (uint16_t)((ulong)uStack_6 >> 0x10);
                  if ((byte)((far_t far *)uStack_6)[0xc].seg < Agnts[puVar50].strengthMax) {
                    Agnts[puVar50].strengthMax = (char)((far_t far *)uStack_6)[0xc].seg
                    ;
                  }
                  puVar28 = (uint16_t *)((char *)0x24134);
                  puVar49 = (uint16_t)(puVar50);
                } while( true );
              }
              if (cVar14 != -2) {
                keyboardInputMode = 0;
                return (far_t far *)((char *)0x26510);
              }
              Cancelled = 1;
              keyboardInputMode = 0;
              return (far_t far *)((char *)0x26510);
            case (far_t far *)0x11:
              GRecordCount = GRecordCount + -1;
              _fmemset(GRecords + GRecordCount, 0, 0x12);
              *(byte *)((uint8_t *)&GRecords[GRecordCount] + 8) = partyIndex;
              *(uint16_t *)((uint8_t *)&GRecords[GRecordCount] + 2) = (uint16_t)bStack0006;
              *(uint16_t *)((uint8_t *)&GRecords[GRecordCount] + 4) = CONCAT11(uStack0009,bStack0008);
              *(byte *)((uint8_t *)&GRecords[GRecordCount] + 9) = in_stack_0000000e;
              iVar30 = ovc23_isLargeBuilding((int)bStack0006,CONCAT11(uStack0009,bStack0008));
              uVar54 = (uint16_t)((ulong)GUnitGrid >> 0x10);
              uVar53 = (uint16_t)((ulong)GUnits >> 0x10);
              if ((char)iVar30 == '\0') {
                bVar17 = ((unit_t *)GUnits +
                         GUnitGrid[(int)bStack0006]
                         [CONCAT11(uStack0009,bStack0008)])->bldType;
              }
              else {
                bVar17 = ((unit_t *)GUnits +
                         GUnitGrid[(int)((int)&bStack0006 - 1)   /* hand fix: byte array, no [-1].seg */]
                         [CONCAT11(uStack0009,bStack0008)])->bldType;
              }
              cVar25 = BuildingTypes[bVar17].buildTime;
              (*(uint32_t *)((uint8_t *)&(uStack_6))) =
                   CONCAT12(BuildingTypes[bVar17].size,
                            CONCAT11(bVar17,(byte)uStack_6));
              uStack_6 = (far_t far *)CONCAT13(cVar25,(uint3)uStack_6);
              if (cVar25 == '\0') {
                uStack_6 = (far_t far *)CONCAT13(1,(uint3)uStack_6);
              }
              if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) < BuildingTypes[partyIndex].minBuildTime) {
                *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 6) =
                     BuildingTypes[partyIndex].minBuildTime;
              }
              else {
                *(byte *)((uint8_t *)&GRecords[GRecordCount] + 6) = (*(uint8_t *)((uint8_t *)&(uStack_6) + 3));
              }
              *(uint16_t *)((uint8_t *)&GRecords[GRecordCount] + 0xf) = GameTick;
              *(uint16_t *)(&GRecords[GRecordCount]) = 0;
              uVar53 = ovc23_usesGRecordCount3
                                 (BuildingTypes[partyIndex].expinc,in_stack_0000000e,
                                  GRecordCount);
              *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xc) = (char)uVar53;
              if (*(char *)((uint8_t *)&GRecords[GRecordCount] + 0xc) == '\0') {
                *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xc) = 1;
              }
              if (partyIndex == 0) {
                iVar30 = ovc23_isLargeBuilding((int)bStack0006,CONCAT11(uStack0009,bStack0008));
                if ((char)iVar30 != '\0') {
                  piVar4 = (int *)((uint8_t *)&GRecords[GRecordCount] + 2);
                  *piVar4 = *piVar4 + -1;
                }
                *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 7) = (*(uint8_t *)((uint8_t *)&(uStack_6) + 2));
                if (in_stack_00000010 == '\x01') {
                  *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xe) = 1;
                }
                else {
                  *(char *)((uint8_t *)&GRecords[GRecordCount] + 0xc) = in_stack_00000010;
                  *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xe) = 0;
                }
                pbVar2 = (uint16_t)((byte *)((uint8_t *)&GRecords[GRecordCount] + 0xd));
                *pbVar2 = *pbVar2 | 3;
              }
              else {
                *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 7) =
                     BuildingTypes[partyIndex].size;
                if (in_stack_00000010 != '\0') {
                  ovr_ovc23_placeBuilding((int)bStack0006);
                  uVar53 = ovr_ovc22_usesGOngoingBattle(bStack0006,bStack0008);
                  if ((char)uVar53 != '\0') {
                    *(undefined1 *)CONCAT22(in_stack_0000000c,in_stack_0000000a) = 1;
                  }
                }
                *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xe) = 0;
              }
              *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0x11) = 0;
              *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xb) =
                   *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xc);
              iVar30 = GRecordCount;
              GRecordCount = GRecordCount + 1;
              ovc23_abandonConstruction(iVar30);
              pfVar20 = (far_t far *)ovc23_textAdlibNone(in_stack_0000ffbe,in_stack_0000ffc0,
                                                     in_stack_0000ffc2);
              return pfVar20;
            case (far_t far *)0x12:
              GRecordCount = GRecordCount + -1;
              pfVar20 = (far_t far *)ovr_ovc23_textAdlibNone(CONCAT11(uVar68,cVar25),unaff_SI);
              return pfVar20;
            case (far_t far *)0x15:
              iVar30 = (uint)*(byte *)((int)&pfVar20[3].ofs + (int)ovrAuxSlot + 1) * 0x95;
              uVar53 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar30);
              pcVar21 = ovr_fmVsprintf("Intelligence reports %s unit infected with disease. (%d, %d)"
                                       ,(char *)CONCAT13((char)((uint)uVar53 >> 8),
                                                         CONCAT12((char)uVar53,
                                                                  *(uint16_t *)
                                                                   ((int)&worldMenuLabels[0].seg + 1
                                                                   + iVar30))));
              asm { mov uVar31,dx };
              ovr_uiNotify(pcVar21,uVar31,0);
              uVar53 = (uint16_t)((ulong)Entities >> 0x10);
              pfVar20 = (far_t far *)((uint)((entity_t *)Entities)[(int)puStack_a].base.gindex * 0x95);
              if (((pfVar20 + 0x9c5)->ofs & 0xc00) != 0) {
                uVar23 = ovr_ovc27_rollToHitAgent
                                   ((uint32_t)CONCAT22(uVar53,(entity_t *)Entities + (int)unaff_DI)
                                    ,3);
                pfVar20 = (far_t far *)(uVar23 & 0xff);
                if (pfVar20 == (far_t far *)0x0) {
                  uVar53 = (uint16_t)((ulong)Entities >> 0x10);
                  if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                                (uint)((entity_t *)Entities)[(int)puStack_a].base.gindex * 0x95) &
                      0x800) == 0) {
                    puStack_12 = (uint *)CONCAT11((*(uint8_t *)((uint8_t *)&(puStack_12) + 1)),1);
                  }
                  else {
                    puStack_12 = (uint *)CONCAT11((*(uint8_t *)((uint8_t *)&(puStack_12) + 1)),2);
                  }
                  uVar53 = ovr_ovc27_compute3((uint32_t)
                                              CONCAT22(uVar53,(entity_t *)Entities + (int)unaff_DI)
                                              ,(char)puStack_12);
                  if ((char)uVar53 != '\0') {
                    if (DebugVerbose != false) {
                      printf("kill 3\r");
                    }
                    uVar53 = (uint16_t)((ulong)Entities >> 0x10);
                    if (((entity_t *)Entities)[(int)unaff_DI].base.animFrame != 0x0) {
                      puVar5 = &((entity_t *)Entities)[(int)unaff_DI].base.animFrame;
                      *puVar5 = *puVar5 + 0xff;
                    }
                  }
                  alignUp4((((entity_t *)Entities + (int)puVar49)->base).x,0,0);
                  iVar30 = (uint)((entity_t *)Entities)[(int)unaff_DI].base.gindex * 0x95;
                  uVar53 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar30);
                  pfVar20 = (far_t far *)ovr_fmVsprintf(
                                                  "Intelligence reports %s unit drained of energy. (%d, %d)"
                                                  ,(char *)CONCAT13((char)((uint)uVar53 >> 8),
                                                                    CONCAT12((char)uVar53,
                                                                             *(uint16_t *)
                                                                              ((int)&worldMenuLabels
                                                                                     [0].seg + 1 +
                                                                              iVar30))));
                  asm { mov uVar31,dx };
                  ovr_uiNotify((char *)pfVar20,uVar31,0);
                }
              }
              return pfVar20;
            }
            do {
              uVar53 = *(uint16_t *)((int)(uint16_t *)&tmstrsSprites3Seg + iVar29);
              (*(uint8_t *)((uint8_t *)&(gfx_05.seg))) = (char)uVar53;
              gfx_05.ofs = *(uint16_t *)((int)(uint16_t *)&tmstrsSprites3Ofs + iVar29);
              (*(uint8_t *)((uint8_t *)&(gfx_05.seg) + 1)) = (char)((uint)uVar53 >> 8);
              ovr_blitGfxRect(gfx_05,0,0,0,0,0,0,0,0,0,0,0);
              (*(uint8_t *)((uint8_t *)&(gfx_06.seg))) = (char)((uint16_t *)&tmstrsSprites3Seg)[((uint)unaff_DI % 7) * 2];
              gfx_06.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[((uint)unaff_DI % 7) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_06.seg) + 1)) =
                   (char)((uint)((uint16_t *)&tmstrsSprites3Seg)[((uint)unaff_DI % 7) * 2] >> 8);
              ovr_blitGfxRect(gfx_06,0,0,0,0,0,0,0,0,0,0,0);
              (*(uint8_t *)((uint8_t *)&(gfx_07.seg))) =
                   (char)((uint16_t *)&tmstrsSprites3Seg)[((uint)(unaff_DI + 1) % 7) * 2];
              gfx_07.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[((uint)(unaff_DI + 1) % 7) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_07.seg) + 1)) =
                   (char)((uint)((uint16_t *)&tmstrsSprites3Seg)[((uint)(unaff_DI + 1) % 7) * 2]
                         >> 8);
              ovr_blitGfxRect(gfx_07,0,0,0,0,0,0,0,0,0,0,0);
              uVar23 = (uint)((int)unaff_DI + 3) & 7;
              (*(uint8_t *)((uint8_t *)&(gfx_08.seg))) = (char)((uint16_t *)&tmstrsSprites2Seg)[uVar23 * 2];
              gfx_08.ofs = ((uint16_t *)&tmstrsSprites2Ofs)[uVar23 * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_08.seg) + 1)) = (char)((uint)((uint16_t *)&tmstrsSprites2Seg)[uVar23 * 2] >> 8);
              ovr_blitGfxRect(gfx_08,0,0,0,0,0,0,0,0,0,0,0);
              (*(uint8_t *)((uint8_t *)&(gfx_09.seg))) = (char)((uint16_t *)&tmstrsSprites2Seg)[((uint)unaff_DI & 7) * 2];
              gfx_09.ofs = ((uint16_t *)&tmstrsSprites2Ofs)[((uint)unaff_DI & 7) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_09.seg) + 1)) =
                   (char)((uint)((uint16_t *)&tmstrsSprites2Seg)[((uint)unaff_DI & 7) * 2] >> 8);
              ovr_blitGfxRect(gfx_09,0,0,0,0,0,0,0,0,0,0,0);
              (*(uint8_t *)((uint8_t *)&(gfx_10.seg))) = (char)((uint16_t *)&tmstrsSprites1Seg)[((uint)unaff_DI % 5) * 2];
              gfx_10.ofs = ((uint16_t *)&tmstrsSprites1Ofs)[((uint)unaff_DI % 5) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_10.seg) + 1)) =
                   (char)((uint)((uint16_t *)&tmstrsSprites1Seg)[((uint)unaff_DI % 5) * 2] >> 8);
              ovr_blitGfxRect(gfx_10,0,0,0,0,0,0,0,0,0,0,0);
              pfVar20 = (far_t far *)((char *)0x26510);
              (*(uint8_t *)((uint8_t *)&(gfx_11.seg))) = (char)((uint16_t *)&tmstrsSprites1Seg)[((uint)unaff_DI % 5) * 2];
              gfx_11.ofs = ((uint16_t *)&tmstrsSprites1Ofs)[((uint)unaff_DI % 5) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_11.seg) + 1)) =
                   (char)((uint)((uint16_t *)&tmstrsSprites1Seg)[((uint)unaff_DI % 5) * 2] >> 8);
              ovr_blitGfxRect(gfx_11,0,0,0,0,0,0,0,0,0,0,0);
              while( true ) {
                while( true ) {
                  scratch = scratch - 1;
                  if ((int)scratch < 0) {
                    return pfVar20;
                  }
                  pcVar21 = (uint16_t)((char *)(scratch + GfxRndSeed2 + ((uint)unaff_DI >> 5)));
                  puStack_a = (uint *)((int)puStack_a + 0x13);
                  if (((*(uint8_t *)((uint8_t *)&(uStack_14) + 1)) == 2) || ((byte *)__C0_ASM_CopyRight + 0xf < unaff_DI))
                  break;
                  if (((char *)((int)puStack_12 + -1) == (char *)scratch) &&
                     (unaff_DI <= (byte *)__C0_ASM_CopyRight + 8)) {
                    uStack_8 = ((uint16_t *)&csite1Ofs)[(int)unaff_DI * 2];
                    pfVar20 = (far_t far *)((uint16_t *)&csite1Seg)[(int)unaff_DI * 2];
                  }
                  else {
                    uStack_8 = csite1_12Ofs;
                    pfVar20 = csite1_12Seg;
                  }
                  uStack_6 = (far_t far *)CONCAT22(pcVar21,pfVar20);
                  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)pfVar20;
                  gfx.ofs = uStack_8;
                  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)pfVar20 >> 8);
                  ovr_blitGfxRect(gfx,0,0,0,0,0,0,0,0,0,0,0);
                }
                if ((*(uint8_t *)((uint8_t *)&(uStack_14) + 1)) < 2) break;
                if ((byte *)__C0_ASM_CopyRight + 5 < unaff_DI) {
                  uStack_8 = csite1_22Ofs;
                  pfVar20 = csite1_22Seg;
                }
                else {
                  uStack_8 = ((uint16_t *)&csite1Ofs)[(int)(unaff_DI + 6) * 2];
                  pfVar20 = (far_t far *)((uint16_t *)&csite1Seg)[(int)(unaff_DI + 6) * 2];
                }
                uStack_6 = (far_t far *)CONCAT22(pcVar21,pfVar20);
                (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)pfVar20;
                gfx_00.ofs = uStack_8;
                (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)pfVar20 >> 8);
                ovr_blitGfxRect(gfx_00,0,0,0,0,0,0,0,0,0,0,0);
              }
              uStack_6 = (far_t far *)CONCAT22(pcVar21,csite1_12Seg);
              uStack_8 = csite1_12Ofs;
              if ((char *)scratch == (char *)0x0) {
                uVar23 = (uint)((int)unaff_DI + GfxRndSeed2) % 0xe;
                (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = (char)((uint16_t *)&tmstrsSprites6Seg)[uVar23 * 2];
                gfx_01.ofs = ((uint16_t *)&tmstrsSprites6Ofs)[uVar23 * 2];
                (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = (char)((uint)((uint16_t *)&tmstrsSprites6Seg)[uVar23 * 2] >> 8)
                ;
                ovr_blitGfxRect(gfx_01,0,0,0,0,0,0,0,0,0,0,0);
              }
              (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)uStack_6;
              gfx_02.ofs = uStack_8;
              (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = (char)((ulong)uStack_6 >> 8);
              ovr_blitGfxRect(gfx_02,0,0,0,0,0,0,0,0,0,0,0);
              if (((uint)((char *)((int)unaff_DI + GfxRndSeed2 + scratch) + (int)puVar49) & 0x1f) <
                  0x11) {
                uVar23 = ((uint)((char *)((int)unaff_DI + GfxRndSeed2 + scratch) + (int)puVar49) >>
                         5) + scratch + GfxRndSeed2;
                uStack_6 = (far_t far *)CONCAT22(uVar23,(far_t far *)uStack_6);
                uStack_e =(uint16_t)( (uint *)((int)((uint)*(byte *)(uVar23 & 0xff) * 0x25) >> 8));
                uVar23 = (uint)((char *)((int)unaff_DI + GfxRndSeed2 + scratch) + (int)puVar49) &
                         0x1f;
                (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = (char)((uint16_t *)&tmstrsSprites5Seg)[uVar23 * 2];
                gfx_03.ofs = ((uint16_t *)&tmstrsSprites5Ofs)[uVar23 * 2];
                (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) = (char)((uint)((uint16_t *)&tmstrsSprites5Seg)[uVar23 * 2] >> 8)
                ;
                ovr_blitGfxRect(gfx_03,0,0,0,0,0,0,0,0,0,0,0);
              }
              if (((uint)((int)unaff_DI + ((scratch - GfxRndSeed2) - (int)puVar49)) & 0xf) < 7) {
                iVar30 = (((uint)((int)unaff_DI + ((scratch - GfxRndSeed2) - (int)puVar49)) >> 4) +
                         scratch) - GfxRndSeed2;
                uStack_6 = (far_t far *)CONCAT22(iVar30,(far_t far *)uStack_6);
                uStack_e =(uint16_t)( (uint *)((int)((uint)*(byte *)(iVar30 + 0xeU & 0xff) * 0x25) >> 8));
                uVar23 = (uint)((int)unaff_DI + ((scratch - GfxRndSeed2) - (int)puVar49)) & 0xf;
                (*(uint8_t *)((uint8_t *)&(gfx_04.seg))) = (char)((uint16_t *)&tmstrsSprites4Seg)[uVar23 * 2];
                gfx_04.ofs = ((uint16_t *)&tmstrsSprites4Ofs)[uVar23 * 2];
                (*(uint8_t *)((uint8_t *)&(gfx_04.seg) + 1)) = (char)((uint)((uint16_t *)&tmstrsSprites4Seg)[uVar23 * 2] >> 8)
                ;
                ovr_blitGfxRect(gfx_04,0,0,0,0,0,0,0,0,0,0,0);
              }
              iVar29 = (uint)((int)unaff_DI + 5) % 7 << 2;
            } while( true );
          }
          if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\x13') {
            uVar22 = *(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x12a);
            bVar58 = CARRY2(uStack_38,uVar22);
            uStack_38 = uStack_38 + uVar22;
            iStack_36 = iStack_36 + (uint)bVar58;
          }
          else {
            uVar22 = *(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x12a);
            bVar58 = CARRY2(uStack_34,uVar22);
            uStack_34 = uStack_34 + uVar22;
            resourceTotals[0] = resourceTotals[0] + (uint)bVar58;
          }
          if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\x1d') {
            if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 2)) == '\0') {
              resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131)] =
                   resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131)] +
                   (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129);
            }
          }
          else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\x10') {
            if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 2)) != '\0') {
              resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131)] =
                   resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131)] +
                   (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129);
            }
          }
          else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129) != '\0') {
            if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\r') {
              if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) != '\0') {
                resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) + 3] =
                     resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) + 3] +
                     (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129);
              }
            }
            else {
              resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) + 3] =
                   resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) + 3] +
                   (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129);
            }
          }
          iStack_22 = iStack_22 + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x127);
          if (0xf7 < (int)puVar49) {
            pcVar21 = ovr_ovc22_textPOPULATION((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),partyIndex,0,0,0);
            uStack_20 = uStack_20 + (int)pcVar21;
            uVar22 = ovc22_seasonalIncome((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),partyIndex,0,0,0);
            iVar30 = iVar30 + uVar22;
          }
          if (((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x121) & 1) != 0) &&
             (((*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x2f) == -1 ||
               (bVar17 = *(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x2f),
               uVar23 = CONCAT11((char)(uVar23 >> 8),bVar17),
               (1 << (bVar17 & 0x1f) & (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x11f)) != 0))
              && (*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) < 4)))) {
            *(int *)(&stk_ffbc + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) * 2) =
                 *(int *)(&stk_ffbc + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) * 2)
                 + 1;
          }
          if ((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x121) & 0x200) != 0) {
            iStack_3c = iStack_3c + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131);
          }
        }
      }
    }
    for (uStack_14 = (far_t far *)0x0; uStack_14 < EntityCount;
        uStack_14 = (far_t far *)((int)&uStack_14->ofs + 1)) {
      uVar53 = (uint16_t)((ulong)Entities >> 0x10);
      if (*(byte *)((int)&((entity_t *)Entities)[(int)uStack_14].base.entity + 3) == partyIndex) {
        uStack_1e = uStack_1e + ((entity_t *)Entities)[(int)uStack_14].base.animFrame;
      }
    }
    bStack_1b = *(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xad);
    for (iVar29 = 2; -1 < iVar29; iVar29 = iVar29 + -1) {
      if (bStack_1b < *(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + iVar29 + 0xaa)) {
        *(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + iVar29 + 0xaa) = bStack_1b;
        bStack_1b = 0;
      }
      else {
        bStack_1b = bStack_1b -
                    *(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + iVar29 + 0xaa);
      }
    }
    iVar29 = 0;
    for (iVar52 = 0; iVar52 < 3; iVar52 = iVar52 + 1) {
      iVar29 = iVar29 + (uint)*(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + iVar52 + 0xaa)
                        * (iVar52 + 1) * 3;
    }
    if (iVar29 < 0x32) {
      *(undefined1 *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xaa) = (char)iVar29;
    }
    else {
      *(undefined1 *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xaa) = 0x32;
    }
    *(uint16_t *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x94) = scratch;
    *(uint16_t *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x96) =(uint16_t)( puStack_a);
    *(uint16_t *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x98) = uStack_8;
    uStack_24 = in_stack_0000ffbe;
    if (5 < in_stack_0000ffbe) {
      uStack_24 = 5;
    }
    if (in_stack_0000ffc0 + uStack_24 < 0xb) {
      uStack_24 = uStack_24 + in_stack_0000ffc0;
    }
    else {
      uStack_24 = 10;
    }
    uStack_24 = (int)&in_stack_0000ffc2->x + uStack_24;
    if (in_stack_0000ffc2 == (agnt_t *)0x0) {
      if (in_stack_0000ffc0 == 0) {
        if (in_stack_0000ffbe == 0) {
          *(undefined1 *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x53) = 4;
        }
        else {
          *(undefined1 *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x53) = 8;
        }
      }
      else {
        *(undefined1 *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x53) = 0xc;
      }
    }
    else {
      *(undefined1 *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x53) = 0xff;
    }
    (GLeaderSheets[partyIndex])->reserved_82 = 0;
    if ((resourceTotals[0] < 0) || (resourceTotals[0] < 1)) {
      uVar53 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
      iVar29 = (int)*(uint32_t *)((uint)partyIndex << 2);
      *(int16_t *)(iVar29 + 0x80) = resourceTotals[0];
      *(uint *)(iVar29 + 0x7e) = uStack_34;
    }
    else {
      uVar53 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
      iVar29 = (int)*(uint32_t *)((uint)partyIndex << 2);
      *(uint16_t *)(iVar29 + 0x80) = 0;
      *(uint16_t *)(iVar29 + 0x7e) = 0xffff;
    }
    (GLeaderSheets[partyIndex])->housing = iStack_22;
    (GLeaderSheets[partyIndex])->population = uStack_1e;
    (GLeaderSheets[partyIndex])->foodProd = (int)uStack_20;
    (GLeaderSheets[partyIndex])->income = iVar30;
    uVar53 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
    iVar30 = (int)*(uint32_t *)((uint)partyIndex << 2);
    *(int *)(iVar30 + 0x8c) = iStack_36;
    *(uint *)(iVar30 + 0x8a) = uStack_38;
    *(int16_t *)((int)*(uint32_t *)((uint)partyIndex << 2) + 100) = animStep;
    *(uint16_t *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x66) = uStack_28;
    *(uint16_t *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x68) = uStack_26;
    (GLeaderSheets[partyIndex])->ringBudgetIn[0] = resourceTotals[1];
    *(int16_t *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x72) = resourceTotals[2];
    *(int16_t *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x74) = resourceTotals[3];
    (GLeaderSheets[partyIndex])->rank = iStack_3c;
    if (uStack_24 < 0x100) {
      *(undefined1 *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x52) = (undefined1)uStack_24;
    }
    else {
      *(undefined1 *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x52) = 0xff;
    }
    uVar23 = ovr_ovc36_usesLDIV_at_(partyIndex);
    (GLeaderSheets[partyIndex])->popularity = (char)uVar23;
    in_AX = (far_t far *)ovc22_usesPlayerCount(partyIndex);
  }
  return in_AX;
switchD_5000_123d_caseD_2:
  do {
    bVar17 = ((entity_t *)Entities)[(int)puVar49].base.gindex;
    uStack_6 = (far_t far *)CONCAT13(bVar17,(uint3)uStack_6);
    pfVar20 = (far_t far *)(uint)AgntGs[(uint)bVar17].ai;
    if (pfVar20 == (far_t far *)0x0) {
      ovr_ovc15_capitalize(acStackY_a6);
      uStackY_60 = 0x2322;
      uStackY_62 = 0x8f4e;
      pfVar20 = (far_t far *)ovr_stsprintf(&stk_ffaa,(char *)CONCAT22(0x5665,_SS));
      ovr_uiNotify((char *)pfVar20,0,0);
    }
    ovr_ovc15_removeEntity((uint)puVar49);
    while( true ) {
      do {
        puVar49 = (uint *)((int)puVar49 + -1);
        if ((int)puVar49 < 0) {
          return pfVar20;
        }
        pfVar20 = (far_t far *)((int)puVar49 * 0x37);
        uVar53 = (uint16_t)((ulong)Entities >> 0x10);
      } while (((uint *)(((entity_t *)Entities + (int)puVar49)->base).x != unaff_DI) ||
              (pfVar20 = (far_t far *)((entity_t *)Entities)[(int)puVar49].base.y,
              pfVar20 != bStack0006));
      pfVar20 = (far_t far *)ovr_ovc23_findClearColumn((int)unaff_DI);
      uStack_6 = (far_t far *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),pfVar20);
      if ((int)pfVar20 < 0) break;
      (((entity_t *)Entities + (int)puVar49)->base).x = (uint16_t)pfVar20;
    }
  } while( true );
switchD_5000_123d_caseD_3:
  while( true ) {
    if ((puVar38->flags & 3) == 0) {
      uVar53 = (uint16_t)((ulong)GUnits >> 0x10);
      bVar17 = ((unit_t *)GUnits)[(int)unaff_DI].unitType;
      if ((bVar17 == 0xff) ||
         (uVar11 = *(uint32_t *)((uint)bVar17 << 2), *(char *)((int)uVar11 + 0x3f) == '\0')) {
        uStack_8 = 0x96;
      }
      else {
        uStack_8 = 0x5dc;
      }
      if (((unit_t *)GUnits)[(int)unaff_DI].level != 0) {
        uVar31 = ovr_randBelow(uStack_8,0);
        uVar53 = (uint16_t)((ulong)GUnits >> 0x10);
        units = (unit_t *)GUnits;
        if ((int)(uVar31 & 0xff) <
            (int)(100 - (uint)*(byte *)((uint)(units + (int)unaff_DI)->bldType * 0x27 + 0x130))) {
          bVar17 = (units + (int)unaff_DI)->bldType;
          uStack_20 =(uint16_t)( (byte *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)),bVar17));
          units[(int)unaff_DI].level = units[(int)unaff_DI].level - 1;
          units = (unit_t *)GUnits;
          uVar53 = (uint16_t)((ulong)GUnits >> 0x10);
          if (((BuildingTypes[bVar17].flags2 & 4) == 0) &&
             ((units[(int)unaff_DI].level == 0 ||
              ((BuildingTypes[bVar17].flags2 & 0x200) != 0)))) {
            ovc22_usesGUnits((int)unaff_DI,
                             (uint8_t *)
                             CONCAT13((char)((uint)((int)unaff_DI * 9) >> 8),
                                      CONCAT12(units[(int)unaff_DI].unitType,_SS)));
          }
          else if (((((bld_inst_t *)BldInstances + bVar17)->ofs != 0 ||
                     *(int *)((int)&BldInstances[0].seg + (uint)bVar17 * 0xc) != 0) ||
                   (BuildingTypes[bVar17].flags == '\x10')) &&
                  (uVar53 = ovc22_usesGOngoingBattle2
                                      (*(byte *)&units[(int)unaff_DI].x,
                                       *(byte *)&units[(int)unaff_DI].y), (char)uVar53 != '\0')) {
            cStack_1c = '\x01';
          }
        }
      }
    }
L_upd_units_5087_1d7d_202C:
    unaff_DI = (uint *)((int)unaff_DI + 1);
    if (GUnitCount <= unaff_DI) break;
    uVar54 = (uint16_t)((ulong)GUnits >> 0x10);
    puVar38 = (unit_t *)GUnits + (int)unaff_DI;
  }
  GGameState = 0x43;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  for (uStack_16 = (far_t far *)0x0; (int)uStack_16 < (int)(uint)GLeaderCount;
      uStack_16 = (far_t far *)((int)uStack_16 + 1)) {
    if (((char_sheet_t *)(((int)uStack_16 << 2)))->active != '\0') {
      ((char_sheet_t *)(((int)uStack_16 << 2)))->foodSold = 0;
      cVar18 = *(char *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x3f);
      if ((cVar18 == '\0') &&
         (((char_sheet_t *)(((int)uStack_16 << 2)))->foodProd <
          ((char_sheet_t *)(((int)uStack_16 << 2)))->population >> 1)) {
        bVar58 = true;
      }
      else {
        bVar58 = false;
      }
      uVar23 = ((char_sheet_t *)(((int)uStack_16 << 2)))->income;
      uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
      iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
      iVar29 = *(int *)(iVar29 + 0x58) + ((int)uVar23 >> 0xf) +
               (uint)CARRY2(*(uint *)(iVar29 + 0x56),uVar23);
      if ((iVar29 < 1) && (iVar29 < 0)) {
        puVar49 = (uint *)&GUnitDescriptions[3].ofs;
        while (puVar49 = (uint *)((int)puVar49 + 1), puVar49 < GUnitCount) {
          uVar53 = (uint16_t)((ulong)GUnits >> 0x10);
          units = (unit_t *)GUnits;
          bVar17 = (units + (int)puVar49)->bldType;
          uStack_20 =(uint16_t)( (byte *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)),bVar17));
          if (((far_t far *)(uint)units[(int)puVar49].unitType == uStack_16) &&
             (BuildingTypes[bVar17].income < 0)) {
            uVar23 = BuildingTypes[bVar17].income;
            uVar54 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
            iVar29 = *(int *)(iVar29 + 0x58) + ((int)uVar23 >> 0xf) +
                     (uint)CARRY2(*(uint *)(iVar29 + 0x56),uVar23);
            if ((iVar29 < 1) && (iVar29 < 0)) {
              if ((cVar18 == '\0') && (units[(int)puVar49].level != 0)) {
                uVar31 = ovr_randBelow(100,0);
                uVar53 = (uint16_t)((ulong)GUnits >> 0x10);
                units = (unit_t *)GUnits;
                if (*(byte *)((uint)(units + (int)puVar49)->bldType * 0x27 + 0x130) <=
                    (byte)uVar31) {
                  if (units[(int)puVar49].level != 0) {
                    units[(int)puVar49].level = units[(int)puVar49].level - 1;
                  }
                  units = (unit_t *)GUnits;
                  uVar53 = (uint16_t)((ulong)GUnits >> 0x10);
                  if (((*(uint *)(((uint)uStack_20 & 0xff) * 0x27 + 0x121) & 4) == 0) &&
                     ((iVar29 = 0, units[(int)puVar49].level == 0 ||
                      (iVar29 = ((uint)uStack_20 & 0xff) * 0x27,
                      (*(uint *)(iVar29 + 0x121) & 0x200) != 0)))) {
                    ovc22_usesGUnits((int)puVar49,
                                     (uint8_t *)
                                     CONCAT13((char)((uint)iVar29 >> 8),
                                              CONCAT12((undefined1)uStack_16,_SS)));
                  }
                  else if (((((bld_inst_t *)BldInstances + ((uint)uStack_20 & 0xff))->ofs != 0 ||
                             *(int *)((int)&BldInstances[0].seg + ((uint)uStack_20 & 0xff) * 0xc) !=
                             0) || (*(char *)(((uint)uStack_20 & 0xff) * 0x27 + 0x11e) == '\x10'))
                          && (uVar53 = ovc22_usesGOngoingBattle2
                                                 (*(byte *)&units[(int)puVar49].x,
                                                  *(byte *)&units[(int)puVar49].y),
                             (char)uVar53 != '\0')) {
                    cStack_1c = '\x01';
                  }
                }
              }
            }
            else {
              uVar22 = BuildingTypes[bVar17].income;
              uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
              iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
              puVar3 = (uint *)(iVar29 + 0x56);
              uVar23 = *puVar3;
              *puVar3 = *puVar3 + uVar22;
              piVar4 = (int *)(iVar29 + 0x58);
              *piVar4 = *piVar4 + ((int)uVar22 >> 0xf) + (uint)CARRY2(uVar23,uVar22);
            }
          }
        }
        uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
        *(uint16_t *)(iVar29 + 0x58) = 0;
        *(uint16_t *)(iVar29 + 0x56) = 0;
      }
      else {
        if ((cVar18 == '\0') && (0 < ((char_sheet_t *)(((int)uStack_16 << 2)))->income)) {
          puStack_10 = (uint *)(((char_sheet_t *)(((int)uStack_16 << 2)))->income / 10);
        }
        else {
          puStack_10 = (uint *)0x0;
        }
        bVar59 = CARRY2((uint)GPopulationLo,(uint)puStack_10);
        GPopulationLo = GPopulationLo + (int)puStack_10;
        GPopulationHi = GPopulationHi + ((int)puStack_10 >> 0xf) + (uint)bVar59;
        uVar22 = ((char_sheet_t *)(((int)uStack_16 << 2)))->income - (int)puStack_10;
        uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar29 + 0x56);
        uVar23 = *puVar3;
        *puVar3 = *puVar3 + uVar22;
        piVar4 = (int *)(iVar29 + 0x58);
        *piVar4 = *piVar4 + ((int)uVar22 >> 0xf) + (uint)CARRY2(uVar23,uVar22);
      }
      if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                    (uint)((char_sheet_t *)(((int)uStack_16 << 2)))->classStr * 0x95) &
          0x100) == 0) {
        if (((char_sheet_t *)(((int)uStack_16 << 2)))->foodProd <
            ((char_sheet_t *)(((int)uStack_16 << 2)))->population) {
          puStack_12 = (uint *)(((char_sheet_t *)(((int)uStack_16 << 2)))->population -
                               ((char_sheet_t *)(((int)uStack_16 << 2)))->foodProd);
          uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
          iVar52 = (int)*(uint32_t *)((int)uStack_16 << 2);
          iVar29 = *(int *)(iVar52 + 0x62);
          if ((-1 < iVar29) && ((0 < iVar29 || (*(int *)(iVar52 + 0x60) != 0)))) {
            uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
            uVar23 = *(uint *)(iVar29 + 0x62);
            if ((0x7fff < uVar23) ||
               ((uStack_14 = (far_t far *)puStack_12, (int)uVar23 < 1 &&
                ((uint *)*(uint16_t *)(iVar29 + 0x60) <= puStack_12)))) {
              uStack_14 =(uint16_t)( (far_t far *)*(uint16_t *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x60)
              );
            }
            puStack_12 = (uint *)((int)puStack_12 - (int)uStack_14);
            uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
            piVar4 = (int *)(iVar29 + 0x60);
            puVar49 = (uint *)*piVar4;
            *piVar4 = *piVar4 - (int)uStack_14;
            piVar4 = (int *)(iVar29 + 0x62);
            *piVar4 = *piVar4 - (uint)(puVar49 < uStack_14);
          }
          if (puStack_12 != (uint *)0x0) {
            puStack_a = (uint16_t)(puStack_12);
            if ((uint *)((char_sheet_t *)(((int)uStack_16 << 2)))->maxTrade <
                puStack_12) {
              puStack_a = (uint *)((char_sheet_t *)(((int)uStack_16 << 2)))->maxTrade;
            }
            uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
            uVar23 = *(uint *)(iVar29 + 0x58);
            if (((int)uVar23 < 1) &&
               ((0x7fff < uVar23 || ((uint *)*(uint16_t *)(iVar29 + 0x56) < puStack_a)))) {
              puStack_a = (uint *)*(uint16_t *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x56);
            }
            uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
            piVar4 = (int *)(iVar29 + 0x56);
            puVar49 = (uint *)*piVar4;
            *piVar4 = *piVar4 - (int)puStack_a;
            piVar4 = (int *)(iVar29 + 0x58);
            *piVar4 = *piVar4 - (uint)(puVar49 < puStack_a);
            puStack_12 = (uint *)((int)puStack_12 - (int)puStack_a);
            ((char_sheet_t *)(((int)uStack_16 << 2)))->foodSold =(uint16_t)( puStack_a);
          }
          if (cVar18 == '\0') {
            for (iVar29 = 0; (puStack_12 != (uint *)0x0 && (iVar29 < (int)(uint)GLeaderCount));
                iVar29 = iVar29 + 1) {
              if (((GLeaderSheets[iVar29])->active != '\0') &&
                 ((*(char *)((int)*(uint32_t *)(iVar29 << 2) + 0x3f) == '\0' &&
                  (uVar53 = (uint16_t)((ulong)*(uint32_t *)(iVar29 << 2) >> 0x10),
                  iVar52 = (int)*(uint32_t *)(iVar29 << 2),
                  *(int *)(iVar52 + 0x60) != 0 || *(int *)(iVar52 + 0x62) != 0)))) {
                uVar53 = (uint16_t)((ulong)*(uint32_t *)(iVar29 << 2) >> 0x10);
                iVar52 = (int)*(uint32_t *)(iVar29 << 2);
                uVar23 = *(uint *)(iVar52 + 0x62);
                if ((uVar23 < 0x8000) &&
                   ((0 < (int)uVar23 || (puStack_12 < (uint *)*(uint16_t *)(iVar52 + 0x60))))) {
                  uStack_14 =(uint16_t)( (far_t far *)puStack_12);
                }
                else {
                  uStack_14 =(uint16_t)( (far_t far *)*(uint16_t *)((int)*(uint32_t *)(iVar29 << 2) + 0x60));
                }
                puStack_12 = (uint *)((int)puStack_12 - (int)uStack_14);
                uVar53 = (uint16_t)((ulong)*(uint32_t *)(iVar29 << 2) >> 0x10);
                iVar52 = (int)*(uint32_t *)(iVar29 << 2);
                piVar4 = (int *)(iVar52 + 0x60);
                puVar49 = (uint *)*piVar4;
                *piVar4 = *piVar4 - (int)uStack_14;
                piVar4 = (int *)(iVar52 + 0x62);
                *piVar4 = *piVar4 - (uint)(puVar49 < uStack_14);
              }
            }
          }
          pfVar20 = (far_t far *)0x0;
          while ((pfVar20 < EntityCount && (puStack_12 != (uint *)0x0))) {
            uVar53 = (uint16_t)((ulong)Entities >> 0x10);
            peVar41 = (entity_t *)Entities;
            if (((*(char *)((int)&peVar41[(int)pfVar20].base.entity + 1) == '\0') &&
                ((far_t far *)(uint)*(byte *)((int)&peVar41[(int)pfVar20].base.entity + 3) == uStack_16)
                ) && ((bVar58 || (1 < peVar41[(int)pfVar20].base.animFrame)))) {
              if (peVar41[(int)pfVar20].base.animFrame != 0x0) {
                if (DebugVerbose != false) {
                  printf("kill 3\r");
                }
                puVar5 = &((entity_t *)Entities)[(int)pfVar20].base.animFrame;
                *puVar5 = *puVar5 + 0xff;
                if (((entity_t *)Entities)[(int)pfVar20].base.animFrame == 0x0) {
                  uStack_1e = CONCAT11(1,(byte)uStack_1e);
                }
              }
              puStack_12 = (uint *)((int)puStack_12 + -1);
            }
            pfVar20 = (far_t far *)((int)&pfVar20->ofs + 1);
          }
        }
        else {
          uVar22 = ((char_sheet_t *)(((int)uStack_16 << 2)))->foodProd -
                   ((char_sheet_t *)(((int)uStack_16 << 2)))->population;
          uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
          iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
          puVar3 = (uint *)(iVar29 + 0x60);
          uVar23 = *puVar3;
          *puVar3 = *puVar3 + uVar22;
          piVar4 = (int *)(iVar29 + 0x62);
          *piVar4 = *piVar4 + (uint)CARRY2(uVar23,uVar22);
        }
      }
      uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
      iVar39 = (int)*(uint32_t *)((int)uStack_16 << 2);
      iVar29 = *(int *)(iVar39 + 0x62);
      uVar54 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
      iVar40 = (int)*(uint32_t *)((int)uStack_16 << 2);
      iVar52 = *(int *)(iVar40 + 0x80);
      if ((iVar52 <= iVar29) &&
         ((iVar52 < iVar29 || (*(uint *)(iVar40 + 0x7e) < *(uint *)(iVar39 + 0x60))))) {
        uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
        uVar23 = *(uint *)(iVar29 + 0x60);
        uVar54 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
        iVar52 = (int)*(uint32_t *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar52 + 0x7e);
        uVar22 = (uint)(uVar23 < *puVar3);
        uVar32 = *(int *)(iVar29 + 0x62) - *(int *)(iVar52 + 0x80);
        if (((int)(uVar32 - uVar22) < 0) ||
           ((uVar32 == uVar22 &&
            (uVar23 - *puVar3 <= ((char_sheet_t *)(((int)uStack_16 << 2)))->maxTrade)))) {
          puStack_a = (uint *)(*(int *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x60) -
                              *(int *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x7e));
        }
        else {
          puStack_a = (uint *)((char_sheet_t *)(((int)uStack_16 << 2)))->maxTrade;
        }
        ((char_sheet_t *)(((int)uStack_16 << 2)))->foodSold = -(int)puStack_a;
        uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar29 + 0x56);
        uVar23 = *puVar3;
        *puVar3 = (uint)(*puVar3 + (int)puStack_a);
        piVar4 = (int *)(iVar29 + 0x58);
        *piVar4 = *piVar4 + (uint)CARRY2(uVar23,(uint)puStack_a);
        uVar54 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
        uVar53 = *(uint16_t *)(iVar29 + 0x7e);
        uVar55 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
        iVar52 = (int)*(uint32_t *)((int)uStack_16 << 2);
        *(uint16_t *)(iVar52 + 0x62) = *(uint16_t *)(iVar29 + 0x80);
        *(uint16_t *)(iVar52 + 0x60) = uVar53;
      }
      if ((((char_sheet_t *)(((int)uStack_16 << 2)))->housing <
           ((char_sheet_t *)(((int)uStack_16 << 2)))->population) &&
         ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                    (uint)((char_sheet_t *)(((int)uStack_16 << 2)))->classStr * 0x95) & 0x80
          ) == 0)) {
        puStack_12 = (uint *)(((char_sheet_t *)(((int)uStack_16 << 2)))->population -
                             ((char_sheet_t *)(((int)uStack_16 << 2)))->housing);
        pfVar20 = (far_t far *)0x0;
        while ((pfVar20 < EntityCount && (puStack_12 != (uint *)0x0))) {
          uVar53 = (uint16_t)((ulong)Entities >> 0x10);
          peVar41 = (entity_t *)Entities;
          if (((far_t far *)(uint)*(byte *)((int)&peVar41[(int)pfVar20].base.entity + 3) == uStack_16)
             && ((((*(char *)((int)&peVar41[(int)pfVar20].base.entity + 1) == '\0' &&
                   (peVar41[(int)pfVar20].base.destX == 0)) &&
                  (peVar41[(int)pfVar20].base.destY == 0)) &&
                 (3 < peVar41[(int)pfVar20].base.animFrame)))) {
            if (DebugVerbose != false) {
              printf("kill 2 \r");
            }
            puVar5 = &((entity_t *)Entities)[(int)pfVar20].base.animFrame;
            *puVar5 = *puVar5 + 0xff;
            puStack_12 = (uint *)((int)puStack_12 + -1);
          }
          pfVar20 = (far_t far *)((int)&pfVar20->ofs + 1);
        }
      }
      ovr_ovc25_tickCountdown((int)uStack_16);
      _fmemset((char far *)GLeaderSheets[(int)uStack_16] + 0x6a, 0, 6);
      _fmemset((char far *)GLeaderSheets[(int)uStack_16] + 0x76, 0, 6);
      uVar31 = ovr_randBelow(100,0);
      if ((byte)uVar31 < *(byte *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0xa9)) {
        *(uint16_t *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x6c) =
             *(uint16_t *)((int)*(uint32_t *)((int)uStack_16 << 2) + 100);
      }
      else {
        ((char_sheet_t *)(((int)uStack_16 << 2)))->dirBudget[0] =
             *(uint16_t *)((int)*(uint32_t *)((int)uStack_16 << 2) + 100);
      }
      uVar31 = ovr_randBelow(100,0);
      if ((byte)uVar31 < *(byte *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0xa9)) {
        *(uint16_t *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x6e) =
             *(uint16_t *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x66);
      }
      else {
        piVar4 = (int *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x6c);
        *piVar4 = *piVar4 + *(int *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x66);
      }
      piVar4 = (int *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x6e);
      *piVar4 = *piVar4 + *(int *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x68);
      uVar31 = ovr_randBelow(100,0);
      if ((byte)uVar31 < *(byte *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0xa9)) {
        *(uint16_t *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x78) =
             ((char_sheet_t *)(((int)uStack_16 << 2)))->ringBudgetIn[0];
      }
      else {
        ((char_sheet_t *)(((int)uStack_16 << 2)))->ringBudget[0] =
             ((char_sheet_t *)(((int)uStack_16 << 2)))->ringBudgetIn[0];
      }
      uVar31 = ovr_randBelow(100,0);
      if ((byte)uVar31 < *(byte *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0xa9)) {
        *(uint16_t *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x7a) =
             *(uint16_t *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x72);
      }
      else {
        piVar4 = (int *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x78);
        *piVar4 = *piVar4 + *(int *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x72);
      }
      uVar31 = ovr_randBelow(100,0);
      if ((byte)uVar31 < *(byte *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0xa9)) {
        *(uint16_t *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x7c) =
             *(uint16_t *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x74);
      }
      else {
        piVar4 = (int *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x7a);
        *piVar4 = *piVar4 + *(int *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x74);
      }
      *(undefined1 *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0xa7) =
           *(undefined1 *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0xa6);
      if (*(char *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x3f) != '\0') {
        uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
        iVar52 = (int)*(uint32_t *)((int)uStack_16 << 2);
        iVar29 = *(int *)(iVar52 + 0x58);
        if ((iVar29 < 1) && ((iVar29 != 0 || (*(int *)(iVar52 + 0x56) == 0)))) {
          uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
          iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
          *(uint16_t *)(iVar29 + 0x58) = 0;
          *(uint16_t *)(iVar29 + 0x56) = 0x32;
        }
      }
      if (*(char *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0xaa) != '\0') {
        bVar17 = *(byte *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0xaa);
        uStack_6 = (far_t far *)(ulong)CONCAT12(bVar17,(far_t far *)uStack_6);
        pfVar13 = uStack_6;
        for (uVar23 = 0; uStack_6 = pfVar13, (int)uVar23 < (int)(uint)GLeaderCount;
            uVar23 = uVar23 + 1) {
          uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
          iVar39 = (int)*(uint32_t *)((int)uStack_16 << 2);
          iVar29 = *(int *)(iVar39 + 0x58);
          uVar54 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
          iVar40 = (int)*(uint32_t *)((int)uStack_16 << 2);
          iVar52 = *(int *)(iVar40 + 0x8c);
          if ((iVar52 <= iVar29) &&
             ((iVar29 != iVar52 || (*(uint *)(iVar40 + 0x8a) <= *(uint *)(iVar39 + 0x56))))) break;
          if (((GLeaderSheets[uVar23])->active != '\0') &&
             (((0 < (GLeaderSheets[uVar23])->income &&
               (*(char *)((int)*(uint32_t *)(uVar23 << 2) + 0x3f) == '\0')) &&
              ((far_t far *)uVar23 != uStack_16)))) {
            (*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) = (uint)bVar17;
            resourceTotals[2] =
                 (int16_t)(((long)(GLeaderSheets[uVar23])->income *
                            (long)(int)(*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) & 0xffffU) / 100);
            resourceTotals[3] = 0;
            uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
            uVar22 = *(uint *)(iVar29 + 0x8a);
            uVar54 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
            iVar52 = (int)*(uint32_t *)((int)uStack_16 << 2);
            puVar3 = (uint *)(iVar52 + 0x56);
            iVar29 = (*(int *)(iVar29 + 0x8c) - *(int *)(iVar52 + 0x58)) - (uint)(uVar22 < *puVar3);
            if ((iVar29 < 1) && ((iVar29 < 0 || (uVar22 - *puVar3 < (uint)resourceTotals[2])))) {
              uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
              iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
              uVar22 = *(uint *)(iVar29 + 0x8a);
              uVar54 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
              iVar52 = (int)*(uint32_t *)((int)uStack_16 << 2);
              puVar3 = (uint *)(iVar52 + 0x56);
              resourceTotals[2] = uVar22 - *puVar3;
              resourceTotals[3] =
                   (*(int *)(iVar29 + 0x8c) - *(int *)(iVar52 + 0x58)) - (uint)(uVar22 < *puVar3);
            }
            uVar53 = (uint16_t)((ulong)*(uint32_t *)(uVar23 << 2) >> 0x10);
            iVar52 = (int)*(uint32_t *)(uVar23 << 2);
            iVar29 = *(int *)(iVar52 + 0x58);
            if ((iVar29 <= resourceTotals[3]) &&
               ((iVar29 < resourceTotals[3] || (*(uint *)(iVar52 + 0x56) < (uint)resourceTotals[2]))
               )) {
              uVar53 = (uint16_t)((ulong)*(uint32_t *)(uVar23 << 2) >> 0x10);
              iVar29 = (int)*(uint32_t *)(uVar23 << 2);
              resourceTotals[3] = *(int16_t *)(iVar29 + 0x58);
              resourceTotals[2] = *(int16_t *)(iVar29 + 0x56);
            }
            uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
            puVar3 = (uint *)(iVar29 + 0x56);
            uVar22 = *puVar3;
            *puVar3 = *puVar3 + resourceTotals[2];
            piVar4 = (int *)(iVar29 + 0x58);
            *piVar4 = *piVar4 + resourceTotals[3] + (uint)CARRY2(uVar22,resourceTotals[2]);
            uVar53 = (uint16_t)((ulong)*(uint32_t *)(uVar23 << 2) >> 0x10);
            iVar29 = (int)*(uint32_t *)(uVar23 << 2);
            puVar3 = (uint *)(iVar29 + 0x56);
            uVar22 = *puVar3;
            *puVar3 = *puVar3 - resourceTotals[2];
            piVar4 = (int *)(iVar29 + 0x58);
            *piVar4 = (*piVar4 - resourceTotals[3]) - (uint)(uVar22 < (uint)resourceTotals[2]);
          }
        }
      }
      iVar29 = *(int *)((int)*(uint32_t *)((int)uStack_16 << 2) + 0x58);
      if ((iVar29 < 1) && (iVar29 < 0)) {
        uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
        *(uint16_t *)(iVar29 + 0x58) = 0;
        *(uint16_t *)(iVar29 + 0x56) = 0;
      }
      uVar53 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
      iVar39 = (int)*(uint32_t *)((int)uStack_16 << 2);
      iVar29 = *(int *)(iVar39 + 0x58);
      uVar54 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
      iVar40 = (int)*(uint32_t *)((int)uStack_16 << 2);
      iVar52 = *(int *)(iVar40 + 0x8c);
      if ((iVar52 <= iVar29) &&
         ((iVar52 < iVar29 || (*(uint *)(iVar40 + 0x8a) < *(uint *)(iVar39 + 0x56))))) {
        uVar54 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(uint32_t *)((int)uStack_16 << 2);
        uVar53 = *(uint16_t *)(iVar29 + 0x8a);
        uVar55 = (uint16_t)((ulong)*(uint32_t *)((int)uStack_16 << 2) >> 0x10);
        iVar52 = (int)*(uint32_t *)((int)uStack_16 << 2);
        *(uint16_t *)(iVar52 + 0x58) = *(uint16_t *)(iVar29 + 0x8c);
        *(uint16_t *)(iVar52 + 0x56) = uVar53;
      }
    }
  }
  GGameState = 0x40;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  puVar49 = (uint *)&GUnitDescriptions[3].ofs;
  while (puVar49 = (uint *)((int)puVar49 + 1), puVar49 < GUnitCount) {
    uVar53 = (uint16_t)((ulong)GUnits >> 0x10);
    units = (unit_t *)GUnits;
    if ((*(uint *)((uint)(units + (int)puVar49)->bldType * 0x27 + 0x121) & 0x40) != 0) {
      if (units[(int)puVar49].timer != 0) {
        units[(int)puVar49].timer = units[(int)puVar49].timer - 1;
      }
      uVar53 = (uint16_t)((ulong)GUnits >> 0x10);
      if (((unit_t *)GUnits)[(int)puVar49].timer == 0) {
        uVar11 = *(uint32_t *)((uint)((unit_t *)GUnits)[(int)puVar49].unitType << 2);
        if (*(char *)((int)uVar11 + 0x3f) == '\0') {
          ovr_play_sfx(81,0,0);
          uVar53 = (uint16_t)((ulong)GUnits >> 0x10);
          sVar7 = ((unit_t *)GUnits)[(int)puVar49].y;
          uVar19 = (undefined1)sVar7;
          uVar67 = (undefined1)((uint)sVar7 >> 8);
          uVar23 = ovr_alignUp4(((unit_t *)GUnits)[(int)puVar49].x,0,0);
          pcVar21 = ovr_fmVsprintf("Mine exhausted at (%d, %d).",
                                   (char *)CONCAT13(uVar67,CONCAT12(uVar19,uVar23)));
          ovr_say(pcVar21,0);
          ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
        }
        ovc22_usesGUnits((int)puVar49,
                         (uint8_t *)
                         CONCAT13((char)((uint)((int)puVar49 * 9) >> 8),
                                  CONCAT12(((unit_t *)GUnits)[(int)puVar49].unitType,_SS)));
      }
    }
  }
  GGameState = 0x42;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_driver_clearMapFlagsRect((uint32_t)GMapFlags,0,0,0,0,0,0,0);
  for (uStack_16 = (far_t far *)0x0; uStack_16 < SquareRecCount;
      uStack_16 = (far_t far *)((int)uStack_16 + 1)) {
    puVar3 = (uint *)((*(short (*) [60] [148])GMapFlags)[*(int *)((int)uStack_16 * 0x13 + 2)] +
                     *(int *)((int)uStack_16 * 0x13));
    *puVar3 = *puVar3 | 8;
  }
  if (EntityCount <= EntityScanPos) {
    EntityScanPos = (uint16_t)(0x0);
    for (uStack_16 = (far_t far *)0x0; (int)uStack_16 < (int)(uint)GLeaderCount;
        uStack_16 = (far_t far *)((int)uStack_16 + 1)) {
      if (((char_sheet_t *)(((int)uStack_16 << 2)))->active != '\0') {
        iVar29 = ((int *)((int)uStack_16 * 4))[1];
        iVar52 = ((int *)((int)uStack_16 * 4))[1];
        memcpy((char *)CONCAT13((char)((uint)iVar52 >> 8),
                                CONCAT12((char)iVar52,*(int *)((int)uStack_16 * 4) + 0x8e)),
               (char *)CONCAT13((char)((uint)iVar29 >> 8),
                                CONCAT12((char)iVar29,*(int *)((int)uStack_16 * 4) + 0x94)),3);
      }
    }
  }
  uStack_e =(uint16_t)( (uint *)0x0);
  bVar17 = ovr_manage_findFirstLeader();
  (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)( (far_t far *)CONCAT11(bVar17,(byte)uStack_6));
  if ((bVar17 == 0xff) || (GCanPromote == '\0')) {
    scratch = 0;
  }
  else if ((GLeaderSheets[bVar17])->titleIndex < 5) {
    scratch = 0x28;
  }
  else {
    scratch = (uint)(GLeaderSheets[bVar17])->titleIndex * 4 + 0x14;
  }
  for (uStack_16 = EntityScanPos; uStack_16 < EntityCount;
      uStack_16 = (far_t far *)((int)&uStack_16->ofs + 1)) {
    uVar53 = (uint16_t)((ulong)Entities >> 0x10);
    peVar41 = (entity_t *)Entities;
    if (((*(char *)((int)&peVar41[(int)uStack_16].base.entity + 1) == '\0') &&
        (peVar41[(int)uStack_16].base.destX == 0)) && (peVar41[(int)uStack_16].base.destY == 0)) {
      bVar17 = peVar41[(int)uStack_16].base.gindex;
      uStack_6 = (far_t far *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),bVar17);
      bVar16 = *(byte *)((int)&peVar41[(int)uStack_16].base.entity + 3);
      bVar56 = false;
      bVar59 = false;
      bVar58 = false;
      if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar17 * 0x95) == -1) {
        bVar56 = false;
        bVar59 = true;
      }
      else {
        bStack_1b = (GLeaderSheets[bVar16])->partySlot;
        if (bStack_1b < 5) {
          uStack_1a = peVar41[(int)uStack_16].base.y;
          uStack_18 = ovr_alignUp4(((peVar41 + (int)uStack_16)->base).x,0,0);
          uVar31 = 0x2410;
          if (((*(short (*) [60] [148])GMapFlags)[uStack_1a][uStack_18] & 8U) == 0) {
            uStack_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)),0x22);
            uStack_20 = (uint16_t)((byte *)((char *)0x26222));
          }
          else {
            puVar51 = &uStack_1e;
            iVar29 = (int)&uStack_20 + 1;
            puVar63 = &uStack_20;
            index = CONCAT11((char)((uint)puVar63 >> 8),bStack_1b);
            uStackY_60 = 0x2379;
            uStackY_62 = 0x3d98;
            cVar18 = cVar14;
            uVar19 = uVar65;
            cVar64 = cVar14;
            uVar67 = uVar65;
            cVar66 = cVar14;
            uVar69 = uVar65;
            uVar24 = ovr_attact_usesSquareRecCount(uStack_18,uStack_1a);
            uStackY_60 = 0x2315;
            uStackY_62 = 0x3da2;
            table.seg = uVar31;
            table.ofs = uVar24;
            (*(uint8_t *)((uint8_t *)&(pctOut.seg))) = cVar18;
            pctOut.ofs = (uint16_t)puVar63;
            (*(uint8_t *)((uint8_t *)&(pctOut.seg) + 1)) = uVar19;
            (*(uint8_t *)((uint8_t *)&(remainderOut.seg))) = cVar64;
            remainderOut.ofs = iVar29;
            (*(uint8_t *)((uint8_t *)&(remainderOut.seg) + 1)) = uVar67;
            (*(uint8_t *)((uint8_t *)&(partOut.seg))) = cVar66;
            partOut.ofs = (uint16_t)puVar51;
            (*(uint8_t *)((uint8_t *)&(partOut.seg) + 1)) = uVar69;
            ovr_attact_compute3(table,index,pctOut,remainderOut,partOut);
          }
        }
        else {
          uStack_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)),0x22);
          uStack_20 = (uint16_t)((byte *)((char *)0x26222));
        }
        uVar31 = ovr_randBelow(100,0);
        if ((byte)uVar31 < (byte)uStack_1e) {
          bVar56 = false;
          bVar59 = true;
        }
        else if ((uVar31 & 0xff) < ((uint)uStack_20 >> 8) + (uStack_1e & 0xff)) {
          bVar56 = true;
          bVar59 = false;
        }
        else {
          bVar58 = true;
        }
      }
      if ((bVar58) &&
         (cVar18 = ovr_ovc23_tickRecordsAt((((entity_t *)Entities + (int)uStack_16)->base).x,0,0,0),
         cVar18 == '\0')) {
        if (((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)) == 0) && ((byte)uStack_1e == '\0')) {
          uVar31 = ovr_randBelow(2,0);
          if ((uVar31 & 0xff) == 0) {
            bVar59 = true;
          }
          else {
            bVar56 = true;
          }
        }
        else {
          uVar31 = ovr_randBelow((uint)(*(uint8_t *)((uint8_t *)&(uStack_20) + 1)) + (uStack_1e & 0xff),0);
          if ((byte)uVar31 < (byte)uStack_1e) {
            bVar59 = true;
          }
          else {
            bVar56 = true;
          }
        }
      }
      if ((bVar59) && (uVar23 = ovc22_usesEntities((int)uStack_16), (uVar23 & 0xff) == 0)) {
        bVar56 = true;
      }
      if (bVar56) {
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)uStack_6 * 0x95) != -1) &&
           (bVar16 != 0xff)) {
          if ((*(char *)((int)*(uint32_t *)((uint)bVar16 << 2) + 0x3f) != '\0') ||
             (Entities[(int)uStack_16].base.level <
              *(byte *)((int)*(uint32_t *)((uint)bVar16 << 2) + 0x53))) {
            uVar19 = (undefined1)scratch;
            uVar67 = (undefined1)(scratch >> 8);
            ovc22_usesLUDIV_at_((entity_t *)
                                CONCAT13((char)((ulong)Entities >> 0x18),
                                         CONCAT12((char)((ulong)Entities >> 0x10),
                                                  Entities + (int)uStack_16)));
            LXMUL_at_((long *)CONCAT11(uVar67,uVar19),CONCAT22(unaff_SI,CONCAT11(uVar68,cVar25)),
                      CONCAT13((char)((uint)iVar30 >> 8),
                               CONCAT12((char)iVar30,CONCAT11(in_stack_0000ffb9,in_stack_0000ffb8)))
                     );
            peVar41 = Entities + (int)uStack_16;
            uVar31 = ovr_ovc15_textError();
            uVar22 = ovc22_usesLUDIV_at_2(uVar31,(uint16_t)peVar41,CONCAT11(uVar67,uVar19));
            uVar53 = (uint16_t)((ulong)Entities >> 0x10);
            peVar42 = (entity_t *)Entities;
            uVar23 = *(uint *)&peVar42[(int)uStack_16].base.health;
            *(uint *)&peVar42[(int)uStack_16].base.frameIndex =
                 (int)&(peVar41->base).x +
                 (uint)CARRY2(uVar23,uVar22) + *(int *)&peVar42[(int)uStack_16].base.frameIndex;
            *(uint *)&peVar42[(int)uStack_16].base.health = uVar23 + uVar22;
            ovr_ovc41_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                        CONCAT12((char)((ulong)Entities >> 0x10),
                                                 Entities + (int)uStack_16)));
          }
        }
        ovc22_usesEntities2((int)uStack_16);
        ovc22_usesEntities3((int)uStack_16);
        ovc22_usesEntities4((int)uStack_16);
      }
      animStep = (uint)((entity_t *)Entities)[(int)uStack_16].base.animFrame -
                 (uint)*(byte *)((int)*(uint32_t *)((uint)bVar16 << 2) + 0xa4);
      if (0 < animStep) {
        if (3 < animStep) {
          animStep = 3;
        }
        if (animStep == 3) {
          if (*(int *)((int)*(uint32_t *)((uint)bVar16 << 2) + 0x92) == 0) {
            animStep = 2;
          }
          else {
            piVar4 = (int *)((int)*(uint32_t *)((uint)bVar16 << 2) + 0x92);
            *piVar4 = *piVar4 + -1;
          }
        }
        if (animStep == 2) {
          if (*(int *)((int)*(uint32_t *)((uint)bVar16 << 2) + 0x90) == 0) {
            animStep = 1;
          }
          else {
            piVar4 = (int *)((int)*(uint32_t *)((uint)bVar16 << 2) + 0x90);
            *piVar4 = *piVar4 + -1;
          }
        }
        if (animStep == 1) {
          if (*(int *)((int)*(uint32_t *)((uint)bVar16 << 2) + 0x8e) == 0) {
            animStep = 0;
          }
          else {
            piVar4 = (int *)((int)*(uint32_t *)((uint)bVar16 << 2) + 0x8e);
            *piVar4 = *piVar4 + -1;
          }
        }
        ((entity_t *)Entities)[(int)uStack_16].base.animFrame =
             *(char *)((int)*(uint32_t *)((uint)bVar16 << 2) + 0xa4) + (char)animStep;
      }
      uStack_e =(uint16_t)( (uint *)((int)uStack_e + 1));
      if (199 < (int)uStack_e) break;
    }
  }
  EntityScanPos = (uint16_t)uStack_16;   /* hand fix: 16-bit slot */
  mapDirty = 1;
  ovr_unit_usesAlignUp4();
  GGameState = 0x44;
  pfVar20 = (far_t far *)((char *)0x26510);
  if (DebugVerbose != false) {
    pfVar20 = (far_t far *)((char *)0x26510);
    printf("%d \r");
  }
  if ((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)) != '\0') {
    pfVar20 = (far_t far *)((int)&EntityCount - 1)   /* hand fix: scalar counter, no [-1].seg */;
    for (uStack_16 = pfVar20; -1 < (int)uStack_16;
        uStack_16 = (far_t far *)((int)&uStack_16[-1].seg + 1)) {
      uVar53 = (uint16_t)((ulong)Entities >> 0x10);
      peVar41 = (entity_t *)Entities;
      pfVar20 = (far_t far *)(uint)peVar41[(int)uStack_16].base.animFrame;
      if (pfVar20 == (far_t far *)0x0) {
        pfVar20 = (far_t far *)(uint)AgntGs[(uint)peVar41[(int)uStack_16].base.gindex].ai;
        if (pfVar20 == (far_t far *)0x0) {
          ovr_alignUp4(((peVar41 + (int)uStack_16)->base).x,0,0);
          iVar30 = (uint)((entity_t *)Entities)[(int)uStack_16].base.gindex * 0x95;
          uVar53 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar30);
          pfVar20 = (far_t far *)ovr_fmVsprintf("Intelligence reports %s unit died of starvation. (%d, %d)"
                                            ,(char *)CONCAT13((char)((uint)uVar53 >> 8),
                                                              CONCAT12((char)uVar53,
                                                                       *(uint16_t *)
                                                                        ((int)&worldMenuLabels[0].
                                                                               seg + 1 + iVar30))));
          ovr_uiNotify((char *)pfVar20,0,0);
        }
        ovr_ovc15_removeEntity((uint)uStack_16);
      }
    }
  }
  if (cStack_1c != '\0') {
    ovr_constr_flushDirtyRects();
  }
  return pfVar20;
}


/* 5087:1470 */

/* [R6] touches PlayerCount */

uint16_t __cdecl16far ovc22_usesPlayerCount(byte partyIndex)

{
  uint32_t uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  uint16_t uVar5;
  
  if (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x3f) == '\0') {
    cVar3 = (char)((ulong)(GLeaderSheets[partyIndex])->unitCount / 10);
    bVar2 = cVar3 + 2;
    uVar5 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
    iVar4 = (int)*(uint32_t *)((uint)partyIndex << 2);
    if ((uint)(*(int *)(iVar4 + 0x4d) * 2 + *(int *)(iVar4 + 0x4d)) >> 1 <=
        (GLeaderSheets[partyIndex])->foodProd) {
      bVar2 = cVar3 + 4;
    }
  }
  else {
    bVar2 = PlayerCount / 2 + 1;
  }
  if (10 < bVar2) {
    bVar2 = 10;
  }
  uVar1 = *(uint32_t *)((uint)partyIndex << 2);
  *(byte *)((int)uVar1 + 0xa4) = bVar2;
  return CONCAT11((char)(((uint)partyIndex << 2) >> 8),bVar2);
}



/* 5087:1532 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities, animFrame */

uint __cdecl16far ovc22_usesEntities(int entityIndex)

{
  char *pcVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  uint16_t uVar6;
  
  uVar6 = (uint16_t)((ulong)Entities >> 0x10);
  iVar5 = (int)Entities;
  bVar2 = AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 3);
  if (bVar2 == 0xff) {
    uVar3 = entityIndex * 0x37 & 0xff00;
  }
  else {
    uVar3 = (uint)((entity_t *)iVar5)[entityIndex].base.gindex * 0x95;
    if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + uVar3) & 0x800) == 0) {
      if ((*(char *)((int)*(uint32_t *)((uint)bVar2 << 2) + 0x3f) == '\0') &&
         (uVar3 = (GLeaderSheets[bVar2])->housing,
         uVar3 < (GLeaderSheets[bVar2])->population)) {
        uVar3 = uVar3 & 0xff00;
      }
      else {
        bVar4 = 3;
        while ((bVar4 != 0 &&
               (*(int *)((int)*(uint32_t *)((uint)bVar2 << 2) + (uint)bVar4 * 2 + 0x8c) == 0))) {
          bVar4 = bVar4 - 1;
        }
        if (((entity_t *)iVar5)[entityIndex].base.animFrame <
            (byte)(*(char *)((int)*(uint32_t *)((uint)bVar2 << 2) + 0xa4) + bVar4)) {
          pcVar1 = (char *)((uint8_t *)&((entity_t *)Entities)[entityIndex] + 0xe);
          *pcVar1 = *pcVar1 + '\x01';
          uVar3 = CONCAT11((char)((uint)(entityIndex * 0x37) >> 8),1);
        }
        else {
          uVar3 = entityIndex * 0x37 & 0xff00;
        }
      }
    }
    else {
      uVar3 = uVar3 & 0xff00;
    }
  }
  return uVar3;
}



/* 5087:1674 */

/* [R6] touches GUnits, GRecordCount */

void __cdecl16far ovc22_usesGUnits(int unitIndex,uint8_t *outFlag)

{
  byte bVar1;
  uint16_t uVar2;
  unit_t *puVar3;
  char unaff_DI;
  uint uVar4;
  uint8_t *in_stack_00000006;
  
  uVar4 = 0;
  while( true ) {
    puVar3 = (unit_t *)GUnits;
    uVar2 = (uint16_t)((ulong)GUnits >> 0x10);
    if (GRecordCount <= uVar4) {
      bVar1 = (puVar3 + unitIndex)->bldType;
      if ((BuildingTypes[bVar1].flags2 & 4) == 0) {
        uVar2 = ovc22_usesGOngoingBattle
                          (*(byte *)&puVar3[unitIndex].x,*(byte *)&puVar3[unitIndex].y);
        if ((char)uVar2 != '\0') {
          *(uint8_t *)CONCAT22((uint8_t *)outFlag,in_stack_00000006) = 0x1;
        }
        uVar2 = (uint16_t)((ulong)GUnits >> 0x10);
        ovr_createConstructionRecordFar
                  (0,((unit_t *)GUnits)[unitIndex].x,((unit_t *)GUnits)[unitIndex].y,(uint8_t *)CONCAT22((uint8_t *)outFlag,in_stack_00000006),(*(uint8_t *)((uint8_t *)&(outFlag) + 2)),unaff_DI,0,0,0)
        ;
        if ((1 < BuildingTypes[bVar1].size) &&
           (uVar2 = (uint16_t)((ulong)GUnits >> 0x10),
           ovr_createConstructionRecordFar
                     (0,((unit_t *)GUnits)[unitIndex].x + 1,((unit_t *)GUnits)[unitIndex].y,(uint8_t *)CONCAT22((uint8_t *)outFlag,in_stack_00000006),(*(uint8_t *)((uint8_t *)&(outFlag) + 2)),unaff_DI,0,0,0), 3 < BuildingTypes[bVar1].size)) {
          uVar2 = (uint16_t)((ulong)GUnits >> 0x10);
          ovr_createConstructionRecordFar
                    (0,((unit_t *)GUnits)[unitIndex].x + 2,((unit_t *)GUnits)[unitIndex].y,(uint8_t *)CONCAT22((uint8_t *)outFlag,in_stack_00000006),(*(uint8_t *)((uint8_t *)&(outFlag) + 2)),unaff_DI,0,0,0);
          uVar2 = (uint16_t)((ulong)GUnits >> 0x10);
          ovr_createConstructionRecordFar
                    (0,((unit_t *)GUnits)[unitIndex].x + 3,((unit_t *)GUnits)[unitIndex].y,(uint8_t *)CONCAT22((uint8_t *)outFlag,in_stack_00000006),(*(uint8_t *)((uint8_t *)&(outFlag) + 2)),unaff_DI,0,0,0);
        }
      }
      return;
    }
    if ((GRecords[uVar4].x == puVar3[unitIndex].x) &&
       (GRecords[uVar4].y == puVar3[unitIndex].y)) break;
    uVar4 = uVar4 + 1;
  }
  return;
}



/* 5087:18b6 */

/* [R4] calls LUDIV_at_ */

void __cdecl16far ovc22_usesLUDIV_at_(entity_t *entity)

{
  uint32_t uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  entity_t *peVar5;
  uint16_t uVar6;
  byte bStack_3;
  
  uVar6 = (uint16_t)((ulong)entity >> 0x10);
  peVar5 = (entity_t *)entity;
  uVar2 = (uint)*(byte *)((int)&(peVar5->base).entity + 3);
  uVar1 = *(uint32_t *)(uVar2 << 2);
  uVar3 = *(byte *)((int)uVar1 + 0x52) + 1;
  if ((peVar5->base).level < uVar3) {
    uVar3 = (uint)(peVar5->base).level;
  }
  if (0x24 < uVar3) {
    uVar3 = 0x24;
  }
  uVar1 = *(uint32_t *)(uVar2 << 2);
  bStack_3 = *(byte *)((int)uVar1 + 0x2f);
  if (bStack_3 == 0xff) {
    bStack_3 = 0;
  }
  for (; (piVar4 = (int *)((uint)bStack_3 * 0x94 + uVar3 * 4), *piVar4 == 0 && piVar4[1] == 0 &&
         (uVar3 != 0)); uVar3 = uVar3 - 1) {
  }
  piVar4 = (int *)((uint)bStack_3 * 0x94 + uVar3 * 4);
  LUDIV_at_(*piVar4,piVar4[1],0x1e,0);
  return;
}



/* 5087:197d */

/* [R7] body shape: compute */

char __cdecl16far ovc22_compute3(char direction)

{
  if (direction < '\0') {
    direction = direction + '\x06';
  }
  return direction;
}



/* 5087:1991 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities */

void __cdecl16far ovc22_usesEntities2(int entityIndex)

{
  int *budgetPtr;
  byte partyId;
  uint32_t gdataPtr;
  byte dirLevel;
  char ringBase;
  char innerDir;
  uint16_t entSeg;
  char budgetIdx;
  
  entSeg = (uint16_t)((ulong)Entities >> 0x10);
  if (*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3) != -1) {
    dirLevel = ovr_agnt_compute8((agnt_t *)((uint8_t *)&((entity_t *)Entities)[entityIndex]),entSeg);
    partyId = AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 3);
    for (budgetIdx = '\0'; budgetIdx < '\x03'; budgetIdx = budgetIdx + '\x01') {
      gdataPtr = *(uint32_t *)((uint)partyId << 2);
      if ((*(int *)((int)gdataPtr + budgetIdx * 2 + 0x6a) != 0) && ((char)dirLevel < budgetIdx)) {
        gdataPtr = *(uint32_t *)((uint)partyId << 2);
        budgetPtr = (int *)((int)gdataPtr + budgetIdx * 2 + 0x6a);
        *budgetPtr = *budgetPtr + -1;
        entSeg = (uint16_t)((ulong)Entities >> 0x10);
        ringBase = ((entity_t *)Entities)[entityIndex].dir -
                ((entity_t *)Entities)[entityIndex].dir % 6;
        innerDir = ovc22_compute3(budgetIdx);
        ((entity_t *)Entities)[entityIndex].dir = ringBase + innerDir;
        return;
      }
    }
  }
  return;
}



/* 5087:1ac1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities */

void __cdecl16far ovc22_usesEntities3(int entityIndex)

{
  int *budgetPtr;
  byte bVar2;
  uint32_t gdataPtr;
  byte dirLevel;
  char innerDir;
  int iVar6;
  uint16_t entSeg;
  char chosenIdx;
  char budgetIdx;
  
  entSeg = (uint16_t)((ulong)Entities >> 0x10);
  if (*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3) != -1) {
    dirLevel = ovr_agnt_compute10((agnt_t *)((uint8_t *)&((entity_t *)Entities)[entityIndex]),entSeg);
    bVar2 = AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 3);
    for (budgetIdx = '\0'; budgetIdx < '\x04'; budgetIdx = budgetIdx + '\x01') {
      gdataPtr = *(uint32_t *)((uint)bVar2 << 2);
      if ((*(int *)((int)gdataPtr + budgetIdx * 2 + 0x76) != 0) && ((int)(char)dirLevel < budgetIdx + 1)) {
        chosenIdx = budgetIdx;
        gdataPtr = *(uint32_t *)((uint)bVar2 << 2);
        budgetPtr = (int *)((int)gdataPtr + budgetIdx * 2 + 0x76);
        *budgetPtr = *budgetPtr + -1;
        entSeg = (uint16_t)((ulong)Entities >> 0x10);
        iVar6 = (int)Entities;
        ((entity_t *)iVar6)[entityIndex].dir =
             ((entity_t *)iVar6)[entityIndex].dir +
             (char)(((ulong)((entity_t *)iVar6)[entityIndex].dir / 6) % 6) * -6;
        bVar2 = ((entity_t *)Entities)[entityIndex].base.gindex;
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar2 * 0x95) == '\x03') &&
           ('\x01' < budgetIdx)) {
          chosenIdx = '\x01';
        }
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar2 * 0x95) == '\x01') &&
           ('\x02' < chosenIdx)) {
          chosenIdx = '\x02';
        }
        innerDir = ovc22_compute3(chosenIdx + '\x01');
        entSeg = (uint16_t)((ulong)Entities >> 0x10);
        ((entity_t *)Entities)[entityIndex].dir =
             ((entity_t *)Entities)[entityIndex].dir + innerDir * '\x06';
        return;
      }
    }
  }
  return;
}



/* 5087:1ca4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities */

void __cdecl16far ovc22_usesEntities4(int entityIndex)

{
  char *pcVar1;
  uint *puVar2;
  byte bVar3;
  uint32_t uVar4;
  int iVar5;
  uint16_t uVar6;
  
  uVar6 = (uint16_t)((ulong)Entities >> 0x10);
  iVar5 = (int)Entities;
  if (((AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 3) != -1) &&
      ((AGNT_WORD(&((entity_t *)Entities)[entityIndex], base.frames, 1) & 2) == 0)) &&
     (bVar3 = AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 3),
     uVar4 = *(uint32_t *)((uint)bVar3 << 2), *(char *)((int)uVar4 + 0xa7) != '\0')) {
    uVar4 = *(uint32_t *)((uint)bVar3 << 2);
    pcVar1 = (char *)((int)uVar4 + 0xa7);
    *pcVar1 = *pcVar1 + -1;
    puVar2 = (uint *)((uint8_t *)&((entity_t *)Entities)[entityIndex] + 0x14);
    *puVar2 = *puVar2 | 2;
  }
  return;
}



/* 5087:1d4a */

/* [R4] calls LUDIV_at_ */

uint16_t __cdecl16far ovc22_usesLUDIV_at_2(uint16_t valueLo,uint16_t valueHi,int applyPercent)

{
  long *dividendLo;
  uint16_t unaff_BP;
  uint unaff_SI;
  uint32_t uVar1;
  uint16_t in_stack_00000000;
  uint divisorLo;
  long a;
  
  if (applyPercent != 0) {
    a = (ulong)unaff_SI << 0x10;
    divisorLo = 100;
    dividendLo = LXMUL_at_((long *)((int)&GSTARTX_SavedVectors[2].ofs + 1),a,
                           CONCAT22(in_stack_00000000,unaff_BP));
    uVar1 = LUDIV_at_((int)dividendLo,valueHi,divisorLo,(uint)a);
    valueLo = (uint16_t)uVar1;
  }
  return valueLo;
}



/* 5087:1d7d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

void __cdecl16far upd_usesAlignUp4(void)

{
  byte *pbVar1;
  uint *accLo;
  int *accHi;
  uint8_t *puVar4;
  byte bVar5;
  short sVar6;
  uint32_t uVar7;
  far_t pctOut;
  far_t remainderOut;
  far_t partOut;
  bool bVar8;
  bool bVar9;
  char sheetFaction;
  uint16_t randVal;
  uint uVar12;
  char *pcVar13;
  uint16_t index;
  uint16_t uVar14;
  long *plVar15;
  agnt_t *valueLo;
  unit_t *units;
  int iVar17;
  int iVar18;
  int sheetOfs;
  entity_t *peVar20;
  int iVar21;
  entity_t *peVar22;
  uint16_t unaff_SI;
  uint16_t unaff_DI;
  uint uVar23;
  uint leaderIdxB;   /* the 0..GLeaderCount loop at 3529 only */
  uint unitIdx;   /* the 0xf8..GUnitCount loops only */
  uint16_t unitsSeg;
  uint16_t uVar25;
  uint16_t uVar26;
  bool bVar27;
  far_t table;
  uint8_t *puVar28;
  uint16_t uVar29;
  uint8_t *puVar30;
  uint16_t uVar31;
  uint8_t *puVar32;
  undefined1 uVar33;
  undefined1 uVar34;
  undefined1 uVar35;
  long a;
  uint uVar36;
  ulong in_stack_0000ffd2;
  int iStack_2a;
  uint8_t bldType;
  uint8_t partialWeight;
  uint8_t successWeight;
  char cStack_1d;
  uint8_t found;
  byte bStack_1b;
  uint16_t uStack_1a;
  uint entX;
  uint idx;
  uint uStack_14;
  uint popAcc;
  uint uStack_10;
  int iStack_e;
  int iStack_c;
  uint uStack_a;
  uint16_t uStack_8;
  byte bStack_6;
  byte bStack_5;
  uint sheetAA;
  
  a = CONCAT22(unaff_SI,unaff_DI);
  if (!GameRunning) {
    cStack_1d = '\0';
    found = 0x0;
    for (idx = 0xf8; idx < GUnitCount; idx = idx + 1) {
      pbVar1 = &((unit_t *)GUnits)[idx].flags;
      *pbVar1 = *pbVar1 & 0xfc;
    }
    for (idx = 0; (int)idx < (int)(uint)GLeaderCount; idx = idx + 1) {
      if ((GLeaderSheets[idx])->active != '\0') {
        ovc22_textRingProt((byte)idx);
      }
    }
    GGameState = 0x3e;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (unitIdx = 0xf8; unitIdx < GUnitCount; unitIdx = unitIdx + 1) {
      unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
      units = (unit_t *)GUnits;
      if ((units[unitIdx].flags & 3) == 0) {
        if ((units[unitIdx].unitType == 0xff) ||
           (uVar7 = *(uint32_t *)((uint)units[unitIdx].unitType << 2),
           *(char *)((int)uVar7 + 0x3f) == '\0')) {
          uStack_8 = 0x96;
        }
        else {
          uStack_8 = 0x5dc;
        }
        if (units[unitIdx].level != 0) {
          randVal = ovr_randBelow(uStack_8,0);
          unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
          units = (unit_t *)GUnits;
          if ((int)(randVal & 0xff) <
              (int)(100 - (uint)*(byte *)((uint)(units + unitIdx)->bldType * 0x27 + 0x130))) {
            bldType = (units + unitIdx)->bldType;
            units[unitIdx].level = units[unitIdx].level - 1;
            units = (unit_t *)GUnits;
            unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
            if (((BuildingTypes[bldType].flags2 & 4) == 0) &&
               ((units[unitIdx].level == 0 ||
                ((BuildingTypes[bldType].flags2 & 0x200) != 0)))) {
              ovc22_usesGUnits(unitIdx,(uint8_t *)
                                      CONCAT13((char)(unitIdx * 9 >> 8),
                                               CONCAT12(units[unitIdx].unitType,_SS)));
            }
            else if (((((bld_inst_t *)BldInstances + bldType)->ofs != 0 ||
                       *(int *)((int)&BldInstances[0].seg + (uint)bldType * 0xc) != 0) ||
                     (BuildingTypes[bldType].flags == '\x10')) &&
                    (unitsSeg = ovc22_usesGOngoingBattle2
                                        (*(byte *)&units[unitIdx].x,*(byte *)&units[unitIdx].y),
                    (char)unitsSeg != '\0')) {
              found = 0x1;
            }
          }
        }
      }
    }
    GGameState = 0x43;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (idx = 0; (int)idx < (int)(uint)GLeaderCount; idx = idx + 1) {
      if ((GLeaderSheets[idx])->active != '\0') {
        (GLeaderSheets[idx])->foodSold = 0;
        sheetFaction = *(char *)((int)(uint32_t)GLeaderSheets[idx] + 0x3f);
        if ((sheetFaction == '\0') &&
           ((GLeaderSheets[idx])->foodProd <
            (GLeaderSheets[idx])->population >> 1)) {
          bVar8 = true;
        }
        else {
          bVar8 = false;
        }
        uVar23 = *(uint *)((int)(uint32_t)GLeaderSheets[idx] + 0x54);
        unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        iVar17 = (int)(uint32_t)GLeaderSheets[idx];
        iVar17 = *(int *)(iVar17 + 0x58) + ((int)uVar23 >> 0xf) +
                 (uint)CARRY2(*(uint *)(iVar17 + 0x56),uVar23);
        if ((iVar17 < 1) && (iVar17 < 0)) {
          for (unitIdx = 0xf8; unitIdx < GUnitCount; unitIdx = unitIdx + 1) {
            unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
            units = (unit_t *)GUnits;
            bldType = (units + unitIdx)->bldType;
            if ((units[unitIdx].unitType == idx) &&
               (BuildingTypes[bldType].income < 0)) {
              uVar12 = BuildingTypes[bldType].income;
              uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              iVar17 = (int)(uint32_t)GLeaderSheets[idx];
              iVar17 = *(int *)(iVar17 + 0x58) + ((int)uVar12 >> 0xf) +
                       (uint)CARRY2(*(uint *)(iVar17 + 0x56),uVar12);
              if ((iVar17 < 1) && (iVar17 < 0)) {
                if ((sheetFaction == '\0') && (units[unitIdx].level != 0)) {
                  randVal = ovr_randBelow(100,0);
                  unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
                  units = (unit_t *)GUnits;
                  if (*(byte *)((uint)(units + unitIdx)->bldType * 0x27 + 0x130) <= (byte)randVal) {
                    if (units[unitIdx].level != 0) {
                      units[unitIdx].level = units[unitIdx].level - 1;
                    }
                    units = (unit_t *)GUnits;
                    unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
                    if (((BuildingTypes[bldType].flags2 & 4) == 0) &&
                       ((iVar17 = 0, units[unitIdx].level == 0 ||
                        (iVar17 = (uint)bldType * 0x27, (*(uint *)(iVar17 + 0x121) & 0x200) != 0))))
                    {
                      ovc22_usesGUnits(unitIdx,(uint8_t *)
                                              CONCAT13((char)((uint)iVar17 >> 8),
                                                       CONCAT12((byte)idx,_SS)));
                    }
                    else if (((((bld_inst_t *)BldInstances + bldType)->ofs != 0 ||
                               *(int *)((int)&BldInstances[0].seg + (uint)bldType * 0xc) != 0) ||
                             (BuildingTypes[bldType].flags == '\x10')) &&
                            (unitsSeg = ovc22_usesGOngoingBattle2
                                                (*(byte *)&units[unitIdx].x,
                                                 *(byte *)&units[unitIdx].y), (char)unitsSeg != '\0')
                            ) {
                      found = 0x1;
                    }
                  }
                }
              }
              else {
                uVar36 = BuildingTypes[bldType].income;
                unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
                iVar17 = (int)(uint32_t)GLeaderSheets[idx];
                accLo = (uint *)(iVar17 + 0x56);
                uVar12 = *accLo;
                *accLo = *accLo + uVar36;
                accHi = (int *)(iVar17 + 0x58);
                *accHi = *accHi + ((int)uVar36 >> 0xf) + (uint)CARRY2(uVar12,uVar36);
              }
            }
          }
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar17 = (int)(uint32_t)GLeaderSheets[idx];
          *(uint16_t *)(iVar17 + 0x58) = 0;
          *(uint16_t *)(iVar17 + 0x56) = 0;
        }
        else {
          if ((sheetFaction == '\0') && (0 < *(int *)((int)(uint32_t)GLeaderSheets[idx] + 0x54))) {
            uStack_10 = *(int *)((int)(uint32_t)GLeaderSheets[idx] + 0x54) / 10;
          }
          else {
            uStack_10 = 0;
          }
          bVar27 = CARRY2(GPopulationLo,uStack_10);
          GPopulationLo = GPopulationLo + uStack_10;
          GPopulationHi = GPopulationHi + ((int)uStack_10 >> 0xf) + (uint)bVar27;
          uVar12 = *(int *)((int)(uint32_t)GLeaderSheets[idx] + 0x54) - uStack_10;
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar17 = (int)(uint32_t)GLeaderSheets[idx];
          accLo = (uint *)(iVar17 + 0x56);
          uVar23 = *accLo;
          *accLo = *accLo + uVar12;
          accHi = (int *)(iVar17 + 0x58);
          *accHi = *accHi + ((int)uVar12 >> 0xf) + (uint)CARRY2(uVar23,uVar12);
        }
        if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)(GLeaderSheets[idx])->classStr * 0x95) & 0x100)
            == 0) {
          if ((GLeaderSheets[idx])->foodProd <
              (GLeaderSheets[idx])->population) {
            popAcc = (GLeaderSheets[idx])->population -
                        (GLeaderSheets[idx])->foodProd;
            unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            iVar21 = (int)(uint32_t)GLeaderSheets[idx];
            iVar17 = *(int *)(iVar21 + 0x62);
            if ((-1 < iVar17) && ((0 < iVar17 || (*(int *)(iVar21 + 0x60) != 0)))) {
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              iVar17 = (int)(uint32_t)GLeaderSheets[idx];
              uVar23 = *(uint *)(iVar17 + 0x62);
              if ((0x7fff < uVar23) ||
                 ((uStack_14 = popAcc, (int)uVar23 < 1 && (*(uint *)(iVar17 + 0x60) <= popAcc)
                  ))) {
                uStack_14 = *(uint *)((int)(uint32_t)GLeaderSheets[idx] + 0x60);
              }
              popAcc = popAcc - uStack_14;
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              iVar17 = (int)(uint32_t)GLeaderSheets[idx];
              accLo = (uint *)(iVar17 + 0x60);
              uVar23 = *accLo;
              *accLo = *accLo - uStack_14;
              accHi = (int *)(iVar17 + 0x62);
              *accHi = *accHi - (uint)(uVar23 < uStack_14);
            }
            if (popAcc != 0) {
              uStack_a = popAcc;
              if ((GLeaderSheets[idx])->maxTrade < popAcc) {
                uStack_a = (GLeaderSheets[idx])->maxTrade;
              }
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              iVar17 = (int)(uint32_t)GLeaderSheets[idx];
              uVar23 = *(uint *)(iVar17 + 0x58);
              if (((int)uVar23 < 1) && ((0x7fff < uVar23 || (*(uint *)(iVar17 + 0x56) < uStack_a))))
              {
                uStack_a = *(uint *)((int)(uint32_t)GLeaderSheets[idx] + 0x56);
              }
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              iVar17 = (int)(uint32_t)GLeaderSheets[idx];
              accLo = (uint *)(iVar17 + 0x56);
              uVar23 = *accLo;
              *accLo = *accLo - uStack_a;
              accHi = (int *)(iVar17 + 0x58);
              *accHi = *accHi - (uint)(uVar23 < uStack_a);
              popAcc = popAcc - uStack_a;
              (GLeaderSheets[idx])->foodSold = uStack_a;
            }
            if (sheetFaction == '\0') {
              for (iVar17 = 0; (popAcc != 0 && (iVar17 < (int)(uint)GLeaderCount));
                  iVar17 = iVar17 + 1) {
                if (((GLeaderSheets[iVar17])->active != '\0') &&
                   ((*(char *)((int)*(uint32_t *)(iVar17 << 2) + 0x3f) == '\0' &&
                    (unitsSeg = (uint16_t)((ulong)*(uint32_t *)(iVar17 << 2) >> 0x10),
                    iVar21 = (int)*(uint32_t *)(iVar17 << 2),
                    *(int *)(iVar21 + 0x60) != 0 || *(int *)(iVar21 + 0x62) != 0)))) {
                  unitsSeg = (uint16_t)((ulong)*(uint32_t *)(iVar17 << 2) >> 0x10);
                  iVar21 = (int)*(uint32_t *)(iVar17 << 2);
                  uVar23 = *(uint *)(iVar21 + 0x62);
                  if ((uVar23 < 0x8000) &&
                     ((0 < (int)uVar23 || (popAcc < *(uint *)(iVar21 + 0x60))))) {
                    uStack_14 = popAcc;
                  }
                  else {
                    uStack_14 = *(uint *)((int)*(uint32_t *)(iVar17 << 2) + 0x60);
                  }
                  popAcc = popAcc - uStack_14;
                  unitsSeg = (uint16_t)((ulong)*(uint32_t *)(iVar17 << 2) >> 0x10);
                  iVar21 = (int)*(uint32_t *)(iVar17 << 2);
                  accLo = (uint *)(iVar21 + 0x60);
                  uVar23 = *accLo;
                  *accLo = *accLo - uStack_14;
                  accHi = (int *)(iVar21 + 0x62);
                  *accHi = *accHi - (uint)(uVar23 < uStack_14);
                }
              }
            }
            uVar23 = 0;
            while ((uVar23 < EntityCount && (popAcc != 0))) {
              unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
              peVar20 = (entity_t *)Entities;
              if (((*(char *)((int)&peVar20[uVar23].base.entity + 1) == '\0') &&
                  (*(byte *)((int)&peVar20[uVar23].base.entity + 3) == idx)) &&
                 ((bVar8 || (1 < peVar20[uVar23].base.animFrame)))) {
                if (peVar20[uVar23].base.animFrame != 0x0) {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  puVar4 = &((entity_t *)Entities)[uVar23].base.animFrame;
                  *puVar4 = *puVar4 + 0xff;
                  if (((entity_t *)Entities)[uVar23].base.animFrame == 0x0) {
                    cStack_1d = '\x01';
                  }
                }
                popAcc = popAcc - 1;
              }
              uVar23 = uVar23 + 1;
            }
          }
          else {
            uVar12 = (GLeaderSheets[idx])->foodProd -
                     (GLeaderSheets[idx])->population;
            unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            iVar17 = (int)(uint32_t)GLeaderSheets[idx];
            accLo = (uint *)(iVar17 + 0x60);
            uVar23 = *accLo;
            *accLo = *accLo + uVar12;
            accHi = (int *)(iVar17 + 0x62);
            *accHi = *accHi + (uint)CARRY2(uVar23,uVar12);
          }
        }
        unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        iVar18 = (int)(uint32_t)GLeaderSheets[idx];
        iVar17 = *(int *)(iVar18 + 0x62);
        uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
        iVar21 = *(int *)(sheetOfs + 0x80);
        if ((iVar21 <= iVar17) &&
           ((iVar21 < iVar17 || (*(uint *)(sheetOfs + 0x7e) < *(uint *)(iVar18 + 0x60))))) {
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar17 = (int)(uint32_t)GLeaderSheets[idx];
          uVar23 = *(uint *)(iVar17 + 0x60);
          uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar21 = (int)(uint32_t)GLeaderSheets[idx];
          accLo = (uint *)(iVar21 + 0x7e);
          uVar12 = (uint)(uVar23 < *accLo);
          uVar36 = *(int *)(iVar17 + 0x62) - *(int *)(iVar21 + 0x80);
          if (((int)(uVar36 - uVar12) < 0) ||
             ((uVar36 == uVar12 &&
              (uVar23 - *accLo <= (GLeaderSheets[idx])->maxTrade)))) {
            uStack_a = *(int *)((int)(uint32_t)GLeaderSheets[idx] + 0x60) -
                       *(int *)((int)(uint32_t)GLeaderSheets[idx] + 0x7e);
          }
          else {
            uStack_a = (GLeaderSheets[idx])->maxTrade;
          }
          (GLeaderSheets[idx])->foodSold = -uStack_a;
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar17 = (int)(uint32_t)GLeaderSheets[idx];
          accLo = (uint *)(iVar17 + 0x56);
          uVar23 = *accLo;
          *accLo = *accLo + uStack_a;
          accHi = (int *)(iVar17 + 0x58);
          *accHi = *accHi + (uint)CARRY2(uVar23,uStack_a);
          uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar17 = (int)(uint32_t)GLeaderSheets[idx];
          unitsSeg = *(uint16_t *)(iVar17 + 0x7e);
          uVar26 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar21 = (int)(uint32_t)GLeaderSheets[idx];
          *(uint16_t *)(iVar21 + 0x62) = *(uint16_t *)(iVar17 + 0x80);
          *(uint16_t *)(iVar21 + 0x60) = unitsSeg;
        }
        if (((GLeaderSheets[idx])->housing <
             (GLeaderSheets[idx])->population) &&
           ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)(GLeaderSheets[idx])->classStr * 0x95) & 0x80)
            == 0)) {
          popAcc = (GLeaderSheets[idx])->population -
                      (GLeaderSheets[idx])->housing;
          uVar23 = 0;
          while ((uVar23 < EntityCount && (popAcc != 0))) {
            unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
            peVar20 = (entity_t *)Entities;
            if ((*(byte *)((int)&peVar20[uVar23].base.entity + 3) == idx) &&
               ((((*(char *)((int)&peVar20[uVar23].base.entity + 1) == '\0' &&
                  (peVar20[uVar23].base.destX == 0)) && (peVar20[uVar23].base.destY == 0)) &&
                (3 < peVar20[uVar23].base.animFrame)))) {
              if (DebugVerbose != false) {
                printf("kill 2 \r");
              }
              puVar4 = &((entity_t *)Entities)[uVar23].base.animFrame;
              *puVar4 = *puVar4 + 0xff;
              popAcc = popAcc - 1;
            }
            uVar23 = uVar23 + 1;
          }
        }
        ovr_ovc25_tickCountdown(idx);
        _fmemset((char far *)GLeaderSheets[idx] + 0x6a, 0, 6);
        _fmemset((char far *)GLeaderSheets[idx] + 0x76, 0, 6);
        randVal = ovr_randBelow(100,0);
        if ((byte)randVal < *(byte *)((int)(uint32_t)GLeaderSheets[idx] + 0xa9)) {
          *(uint16_t *)((int)(uint32_t)GLeaderSheets[idx] + 0x6c) =
               *(uint16_t *)((int)(uint32_t)GLeaderSheets[idx] + 100);
        }
        else {
          (GLeaderSheets[idx])->dirBudget[0] =
               *(uint16_t *)((int)(uint32_t)GLeaderSheets[idx] + 100);
        }
        randVal = ovr_randBelow(100,0);
        if ((byte)randVal < *(byte *)((int)(uint32_t)GLeaderSheets[idx] + 0xa9)) {
          *(uint16_t *)((int)(uint32_t)GLeaderSheets[idx] + 0x6e) =
               *(uint16_t *)((int)(uint32_t)GLeaderSheets[idx] + 0x66);
        }
        else {
          accHi = (int *)((int)(uint32_t)GLeaderSheets[idx] + 0x6c);
          *accHi = *accHi + *(int *)((int)(uint32_t)GLeaderSheets[idx] + 0x66);
        }
        accHi = (int *)((int)(uint32_t)GLeaderSheets[idx] + 0x6e);
        *accHi = *accHi + *(int *)((int)(uint32_t)GLeaderSheets[idx] + 0x68);
        randVal = ovr_randBelow(100,0);
        if ((byte)randVal < *(byte *)((int)(uint32_t)GLeaderSheets[idx] + 0xa9)) {
          *(uint16_t *)((int)(uint32_t)GLeaderSheets[idx] + 0x78) =
               (GLeaderSheets[idx])->ringBudgetIn[0];
        }
        else {
          (GLeaderSheets[idx])->ringBudget[0] =
               (GLeaderSheets[idx])->ringBudgetIn[0];
        }
        randVal = ovr_randBelow(100,0);
        if ((byte)randVal < *(byte *)((int)(uint32_t)GLeaderSheets[idx] + 0xa9)) {
          *(uint16_t *)((int)(uint32_t)GLeaderSheets[idx] + 0x7a) =
               *(uint16_t *)((int)(uint32_t)GLeaderSheets[idx] + 0x72);
        }
        else {
          accHi = (int *)((int)(uint32_t)GLeaderSheets[idx] + 0x78);
          *accHi = *accHi + *(int *)((int)(uint32_t)GLeaderSheets[idx] + 0x72);
        }
        randVal = ovr_randBelow(100,0);
        if ((byte)randVal < *(byte *)((int)(uint32_t)GLeaderSheets[idx] + 0xa9)) {
          *(uint16_t *)((int)(uint32_t)GLeaderSheets[idx] + 0x7c) =
               *(uint16_t *)((int)(uint32_t)GLeaderSheets[idx] + 0x74);
        }
        else {
          accHi = (int *)((int)(uint32_t)GLeaderSheets[idx] + 0x7a);
          *accHi = *accHi + *(int *)((int)(uint32_t)GLeaderSheets[idx] + 0x74);
        }
        *(undefined1 *)((int)(uint32_t)GLeaderSheets[idx] + 0xa7) =
             *(undefined1 *)((int)(uint32_t)GLeaderSheets[idx] + 0xa6);
        if (*(char *)((int)(uint32_t)GLeaderSheets[idx] + 0x3f) != '\0') {
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar21 = (int)(uint32_t)GLeaderSheets[idx];
          iVar17 = *(int *)(iVar21 + 0x58);
          if ((iVar17 < 1) && ((iVar17 != 0 || (*(int *)(iVar21 + 0x56) == 0)))) {
            unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            iVar17 = (int)(uint32_t)GLeaderSheets[idx];
            *(uint16_t *)(iVar17 + 0x58) = 0;
            *(uint16_t *)(iVar17 + 0x56) = 0x32;
          }
        }
        if (*(char *)((int)(uint32_t)GLeaderSheets[idx] + 0xaa) != '\0') {
          sheetAA = (uint)*(byte *)((int)(uint32_t)GLeaderSheets[idx] + 0xaa);
          for (leaderIdxB = 0; (int)leaderIdxB < (int)(uint)GLeaderCount; leaderIdxB = leaderIdxB + 1) {
            unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            iVar18 = (int)(uint32_t)GLeaderSheets[idx];
            iVar17 = *(int *)(iVar18 + 0x58);
            uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
            iVar21 = *(int *)(sheetOfs + 0x8c);
            if ((iVar21 <= iVar17) &&
               ((iVar17 != iVar21 || (*(uint *)(sheetOfs + 0x8a) <= *(uint *)(iVar18 + 0x56)))))
            break;
            if (((GLeaderSheets[leaderIdxB])->active != '\0') &&
               (((0 < *(int *)((int)*(uint32_t *)(leaderIdxB << 2) + 0x54) &&
                 (*(char *)((int)*(uint32_t *)(leaderIdxB << 2) + 0x3f) == '\0')) &&
                (leaderIdxB != idx)))) {
              in_stack_0000ffd2 =
                   ((long)*(int *)((int)*(uint32_t *)(leaderIdxB << 2) + 0x54) * (long)(int)sheetAA &
                   0xffffU) / 100;
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              iVar17 = (int)(uint32_t)GLeaderSheets[idx];
              uVar12 = *(uint *)(iVar17 + 0x8a);
              uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              iVar21 = (int)(uint32_t)GLeaderSheets[idx];
              accLo = (uint *)(iVar21 + 0x56);
              iVar17 = (*(int *)(iVar17 + 0x8c) - *(int *)(iVar21 + 0x58)) -
                       (uint)(uVar12 < *accLo);
              if ((iVar17 < 1) && ((iVar17 < 0 || (uVar12 - *accLo < (uint)in_stack_0000ffd2)))) {
                unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
                iVar17 = (int)(uint32_t)GLeaderSheets[idx];
                uVar12 = *(uint *)(iVar17 + 0x8a);
                uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
                iVar21 = (int)(uint32_t)GLeaderSheets[idx];
                accLo = (uint *)(iVar21 + 0x56);
                in_stack_0000ffd2 =
                     CONCAT22((*(int *)(iVar17 + 0x8c) - *(int *)(iVar21 + 0x58)) -
                              (uint)(uVar12 < *accLo),uVar12 - *accLo);
              }
              unitsSeg = (uint16_t)((ulong)*(uint32_t *)(leaderIdxB << 2) >> 0x10);
              iVar21 = (int)*(uint32_t *)(leaderIdxB << 2);
              iVar17 = *(int *)(iVar21 + 0x58);
              iVar18 = (int)(in_stack_0000ffd2 >> 0x10);
              if ((iVar17 <= iVar18) &&
                 ((iVar17 < iVar18 || (*(uint *)(iVar21 + 0x56) < (uint)in_stack_0000ffd2)))) {
                unitsSeg = (uint16_t)((ulong)*(uint32_t *)(leaderIdxB << 2) >> 0x10);
                iVar17 = (int)*(uint32_t *)(leaderIdxB << 2);
                in_stack_0000ffd2 =
                     CONCAT22(*(uint16_t *)(iVar17 + 0x58),*(uint16_t *)(iVar17 + 0x56));
              }
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              iVar17 = (int)(uint32_t)GLeaderSheets[idx];
              iVar21 = (int)(in_stack_0000ffd2 >> 0x10);
              uVar36 = (uint)in_stack_0000ffd2;
              accLo = (uint *)(iVar17 + 0x56);
              uVar12 = *accLo;
              *accLo = *accLo + uVar36;
              accHi = (int *)(iVar17 + 0x58);
              *accHi = *accHi + iVar21 + (uint)CARRY2(uVar12,uVar36);
              unitsSeg = (uint16_t)((ulong)*(uint32_t *)(leaderIdxB << 2) >> 0x10);
              iVar17 = (int)*(uint32_t *)(leaderIdxB << 2);
              accLo = (uint *)(iVar17 + 0x56);
              uVar12 = *accLo;
              *accLo = *accLo - uVar36;
              accHi = (int *)(iVar17 + 0x58);
              *accHi = (*accHi - iVar21) - (uint)(uVar12 < uVar36);
            }
          }
        }
        iVar17 = *(int *)((int)(uint32_t)GLeaderSheets[idx] + 0x58);
        if ((iVar17 < 1) && (iVar17 < 0)) {
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar17 = (int)(uint32_t)GLeaderSheets[idx];
          *(uint16_t *)(iVar17 + 0x58) = 0;
          *(uint16_t *)(iVar17 + 0x56) = 0;
        }
        unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        iVar18 = (int)(uint32_t)GLeaderSheets[idx];
        iVar17 = *(int *)(iVar18 + 0x58);
        uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
        iVar21 = *(int *)(sheetOfs + 0x8c);
        if ((iVar21 <= iVar17) &&
           ((iVar21 < iVar17 || (*(uint *)(sheetOfs + 0x8a) < *(uint *)(iVar18 + 0x56))))) {
          uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar17 = (int)(uint32_t)GLeaderSheets[idx];
          unitsSeg = *(uint16_t *)(iVar17 + 0x8a);
          uVar26 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar21 = (int)(uint32_t)GLeaderSheets[idx];
          *(uint16_t *)(iVar21 + 0x58) = *(uint16_t *)(iVar17 + 0x8c);
          *(uint16_t *)(iVar21 + 0x56) = unitsSeg;
        }
      }
    }
    GGameState = 0x40;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (unitIdx = 0xf8; unitIdx < GUnitCount; unitIdx = unitIdx + 1) {
      unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
      units = (unit_t *)GUnits;
      if ((*(uint *)((uint)(units + unitIdx)->bldType * 0x27 + 0x121) & 0x40) != 0) {
        if (units[unitIdx].timer != 0) {
          units[unitIdx].timer = units[unitIdx].timer - 1;
        }
        unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
        if (((unit_t *)GUnits)[unitIdx].timer == 0) {
          uVar7 = *(uint32_t *)((uint)((unit_t *)GUnits)[unitIdx].unitType << 2);
          if (*(char *)((int)uVar7 + 0x3f) == '\0') {
            ovr_play_sfx(81,0,0);
            unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
            sVar6 = ((unit_t *)GUnits)[unitIdx].y;
            uVar33 = (undefined1)sVar6;
            uVar35 = (undefined1)((uint)sVar6 >> 8);
            uVar34 = 0x10;
            uVar12 = ovr_alignUp4(((unit_t *)GUnits)[unitIdx].x,0,0);
            pcVar13 = ovr_fmVsprintf("Mine exhausted at (%d, %d).",
                                     (char *)CONCAT13(uVar35,CONCAT12(uVar33,uVar12)));
            ovr_say(pcVar13,uVar34);
            ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
          }
          ovc22_usesGUnits(unitIdx,(uint8_t *)
                                  CONCAT13((char)(unitIdx * 9 >> 8),
                                           CONCAT12(((unit_t *)GUnits)[unitIdx].unitType,_SS)));
        }
      }
    }
    GGameState = 0x42;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    ovr_driver_clearMapFlagsRect((uint32_t)GMapFlags,0,0,0x93,0x3b,0xfff7,0x3b,0xf7);
    for (idx = 0; idx < SquareRecCount; idx = idx + 1) {
      accLo = (uint *)((*(short (*) [60] [148])GMapFlags)[*(int *)((uint8_t *)&SquareRecs[idx] + 2)] +
                       *(int *)(idx * 0x13));
      *accLo = *accLo | 8;
    }
    if (EntityCount <= EntityScanPos) {
      EntityScanPos = 0;
      for (idx = 0; (int)idx < (int)(uint)GLeaderCount; idx = idx + 1) {
        if ((GLeaderSheets[idx])->active != '\0') {
          iVar17 = ((int *)(idx * 4))[1];
          memcpy((char *)CONCAT22(((int *)(idx * 4))[1],
                                  (char *)(*(int *)(idx * 4) + 0x8e)),
                 (char *)CONCAT13((char)((uint)iVar17 >> 8),
                                  CONCAT12((char)iVar17,*(int *)(idx * 4) + 0x94)),3);
        }
      }
    }
    iStack_e = 0;
    bStack_5 = ovr_manage_findFirstLeader();
    if ((bStack_5 == 0xff) || (GCanPromote == '\0')) {
      iStack_c = 0;
    }
    else if ((GLeaderSheets[bStack_5])->titleIndex < 5) {
      iStack_c = 0x28;
    }
    else {
      iStack_c = (uint)(GLeaderSheets[bStack_5])->titleIndex * 4 + 0x14;
    }
    for (idx = EntityScanPos; idx < EntityCount; idx = idx + 1) {
      unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
      peVar20 = (entity_t *)Entities;
      if (((*(char *)((int)&peVar20[idx].base.entity + 1) == '\0') &&
          (peVar20[idx].base.destX == 0)) && (peVar20[idx].base.destY == 0)) {
        bStack_6 = peVar20[idx].base.gindex;
        sheetFaction = AgntGs[(uint)bStack_6].ai;
        bVar5 = *(byte *)((int)&peVar20[idx].base.entity + 3);
        bVar27 = false;
        bVar9 = false;
        bVar8 = false;
        if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bStack_6 * 0x95) == -1) {
          bVar27 = true;
        }
        else {
          bStack_1b = (GLeaderSheets[bVar5])->partySlot;
          if (bStack_1b < 5) {
            uStack_1a = peVar20[idx].base.y;
            entX = ovr_alignUp4(((peVar20 + idx)->base).x,0,0);
            randVal = 0x2410;
            if (((*(short (*) [60] [148])GMapFlags)[uStack_1a][entX] & 8U) == 0) {
              successWeight = 0x22;
              partialWeight = 0x21;
              bldType = 0x22;
            }
            else {
              uVar34 = (undefined1)_SS;
              uVar33 = (undefined1)(_SS >> 8);
              puVar32 = &successWeight;
              puVar30 = &partialWeight;
              puVar28 = &bldType;
              index = CONCAT11((char)((uint)puVar28 >> 8),bStack_1b);
              uVar29 = _SS;
              uVar31 = _SS;
              uVar14 = ovr_attact_usesSquareRecCount(entX,uStack_1a);
              table.seg = randVal;
              table.ofs = uVar14;
              pctOut.seg = uVar29;
              pctOut.ofs = (uint16_t)puVar28;
              remainderOut.seg = uVar31;
              remainderOut.ofs = (uint16_t)puVar30;
              (*(uint8_t *)((uint8_t *)&(partOut.seg))) = uVar34;
              partOut.ofs = (uint16_t)puVar32;
              (*(uint8_t *)((uint8_t *)&(partOut.seg) + 1)) = uVar33;
              ovr_attact_compute3(table,index,pctOut,remainderOut,partOut);
            }
          }
          else {
            successWeight = 0x22;
            partialWeight = 0x21;
            bldType = 0x22;
          }
          randVal = ovr_randBelow(100,0);
          if ((byte)randVal < successWeight) {
            bVar27 = true;
          }
          else if ((randVal & 0xff) < (uint)partialWeight + (uint)successWeight) {
            bVar9 = true;
          }
          else {
            bVar8 = true;
          }
        }
        if ((bVar8) &&
           (unitsSeg = (uint16_t)((ulong)Entities >> 0x10),
           randVal = ((entity_t *)Entities)[idx].base.y,
           sheetFaction = ovr_ovc23_tickRecordsAt
                              ((((entity_t *)Entities + idx)->base).x,randVal,sheetFaction,
                               (char)randVal), sheetFaction == '\0')) {
          if ((partialWeight == 0x0) && (successWeight == 0x0)) {
            randVal = ovr_randBelow(2,0);
            if ((randVal & 0xff) == 0) {
              bVar27 = true;
            }
            else {
              bVar9 = true;
            }
          }
          else {
            randVal = ovr_randBelow((uint)partialWeight + (uint)successWeight,0);
            if ((byte)randVal < successWeight) {
              bVar27 = true;
            }
            else {
              bVar9 = true;
            }
          }
        }
        if ((bVar27) && (uVar23 = ovc22_usesEntities(idx), (uVar23 & 0xff) == 0)) {
          bVar9 = true;
        }
        if (bVar9) {
          if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bStack_6 * 0x95) != -1) &&
             (bVar5 != 0xff)) {
            if ((*(char *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x3f) != '\0') ||
               (Entities[idx].base.level <
                *(byte *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x53))) {
              uVar34 = (undefined1)iStack_c;
              uVar33 = (undefined1)((uint)iStack_c >> 8);
              ovc22_usesLUDIV_at_((entity_t *)
                                  CONCAT13((char)((ulong)Entities >> 0x18),
                                           CONCAT12((char)((ulong)Entities >> 0x10),
                                                    Entities + idx)));
              uVar23 = 0;
              plVar15 = LXMUL_at_((long *)CONCAT11(uVar33,uVar34),a,in_stack_0000ffd2);
              peVar20 = Entities + idx;
              valueLo = ovr_ovc15_textError((entity_t *)CONCAT22(DAT_2000_d190,peVar20),
                                            (agnt_t *)(CONCAT12((uVar23 & 1) != 0,plVar15) >> 1));
              uVar12 = ovc22_usesLUDIV_at_2
                                 ((uint16_t)valueLo,(uint16_t)peVar20,CONCAT11(uVar33,uVar34));
              unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
              peVar22 = (entity_t *)Entities;
              uVar23 = *(uint *)&peVar22[idx].base.health;
              *(uint *)&peVar22[idx].base.frameIndex =
                   (int)&(peVar20->base).x +
                   (uint)CARRY2(uVar23,uVar12) + *(int *)&peVar22[idx].base.frameIndex;
              *(uint *)&peVar22[idx].base.health = uVar23 + uVar12;
              ovr_ovc41_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                          CONCAT12((char)((ulong)Entities >> 0x10),
                                                   Entities + idx)));
            }
          }
          ovc22_usesEntities2(idx);
          ovc22_usesEntities3(idx);
          ovc22_usesEntities4(idx);
        }
        iStack_2a = (uint)((entity_t *)Entities)[idx].base.animFrame -
                    (uint)*(byte *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0xa4);
        if (0 < iStack_2a) {
          if (3 < iStack_2a) {
            iStack_2a = 3;
          }
          if (iStack_2a == 3) {
            if (*(int *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x92) == 0) {
              iStack_2a = 2;
            }
            else {
              accHi = (int *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x92);
              *accHi = *accHi + -1;
            }
          }
          if (iStack_2a == 2) {
            if (*(int *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x90) == 0) {
              iStack_2a = 1;
            }
            else {
              accHi = (int *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x90);
              *accHi = *accHi + -1;
            }
          }
          if (iStack_2a == 1) {
            if (*(int *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x8e) == 0) {
              iStack_2a = 0;
            }
            else {
              accHi = (int *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x8e);
              *accHi = *accHi + -1;
            }
          }
          ((entity_t *)Entities)[idx].base.animFrame =
               *(char *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0xa4) + (char)iStack_2a;
        }
        iStack_e = iStack_e + 1;
        if (199 < iStack_e) break;
      }
    }
    EntityScanPos = idx;
    mapDirty = 1;
    ovr_unit_usesAlignUp4();
    GGameState = 0x44;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    uVar23 = EntityCount;
    if (cStack_1d != '\0') {
      while (idx = uVar23 - 1, -1 < (int)idx) {
        unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
        peVar20 = (entity_t *)Entities;
        uVar23 = idx;
        if (peVar20[idx].base.animFrame == 0x0) {
          if (AgntGs[(uint)peVar20[idx].base.gindex].ai == '\0') {
            ovr_alignUp4(((peVar20 + idx)->base).x,(char)peVar20[idx].base.y,0);
            iVar17 = (uint)((entity_t *)Entities)[idx].base.gindex * 0x95;
            pcVar13 = ovr_fmVsprintf("Intelligence reports %s unit died of starvation. (%d, %d)",
                                     (char *)CONCAT22(*(uint16_t *)
                                                       ((int)&worldMenuLabels[1].ofs + 1 + iVar17),
                                                      (char *)*(uint16_t *)
                                                               ((int)&worldMenuLabels[0].seg + 1 +
                                                               iVar17)));
            asm { mov randVal,dx };
            ovr_uiNotify(pcVar13,randVal,(char)randVal);
          }
          ovr_ovc15_removeEntity(idx);
          uVar23 = idx;
        }
      }
    }
    if (found != 0x0) {
      ovr_constr_flushDirtyRects();
    }
  }
  return;
}



/* 5087:3a6b */

/* [R2] string "arena" */

bool __cdecl16far ovc22_textArena2(uint x,int y)

{
  bool bVar1;
  short (*paasVar2) [148] [60];
  unit_t *puVar3;
  uint uVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  
  bVar1 = ovc22_textArena(x,y);
  if (bVar1) {
    uVar5 = (uint16_t)((ulong)GUnitGrid >> 0x10);
    paasVar2 = (short (*) [148] [60])GUnitGrid;
    uVar6 = (uint16_t)((ulong)GUnits >> 0x10);
    puVar3 = (unit_t *)GUnits;
    if (((puVar3 + (*paasVar2)[x][y])->bldType == 0) ||
       ((*(uint *)((uint)(puVar3 + (*paasVar2)[x][y])->bldType * 0x27 + 0x121) & 0x1000) != 0)) {
      if ((int)x < 4) {
        bVar1 = false;
      }
      else if (*(byte *)((uint)(puVar3 + paasVar2[-1][x + 0x93][y])->bldType * 0x27 + 0x11b) < 2) {
        if (*(byte *)((uint)(puVar3 + paasVar2[-1][x + 0x92][y])->bldType * 0x27 + 0x11b) < 3) {
          if (*(byte *)((uint)(puVar3 + paasVar2[-1][x + 0x91][y])->bldType * 0x27 + 0x11b) < 4) {
            for (uVar4 = 0; uVar4 < GRecordCount; uVar4 = uVar4 + 1) {
              if (((GRecords[uVar4].y == y) && (GRecords[uVar4].x <= x)) &&
                 (x < GRecords[uVar4].x +
                      (uint)BuildingTypes[GRecords[uVar4].reserved08].size)) {
                return false;
              }
            }
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
        }
        else {
          bVar1 = false;
        }
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}



/* 5087:3c93 */

/* [R4] calls ovr_alignUp4 */

uint __cdecl16far ovc22_usesAlignUp4(int x,int y,byte unitType,uint mask)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = (*(short (*) [148] [60])GUnitGrid)[x][y];
  bVar1 = ((unit_t *)GUnits)[iVar4].unitType;
  uVar3 = CONCAT11((char)((uint)(iVar4 * 9) >> 8),bVar1);
  if (bVar1 == unitType) {
    uVar2 = ovr_alignUp4(x,0,0);
    uVar5 = 0;
    uVar3 = uVar2;
    for (iVar4 = -2; iVar4 < 2; iVar4 = iVar4 + 1) {
      uVar3 = (uVar2 + iVar4) * 2;
      uVar5 = uVar5 | (*(short (*) [60] [148])GMapFlags)[y][uVar2 + iVar4];
    }
    if ((mask & uVar5) == 0) {
      return CONCAT11((char)(uVar3 >> 8),1);
    }
  }
  return uVar3 & 0xff00;
}



/* 5087:3d25 */

/* [R6] touches GUnitGrid, GUnits */

uint __cdecl16far ovc22_usesGUnitGrid(int x,int y)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (*(short (*) [148] [60])GUnitGrid)[x][y];
  if (uVar1 < 0xf8) {
    uVar2 = ovr_ovc23_findRecordAt(x,y,0);
    if (uVar2 == 0xffff) {
      uVar1 = (uint)((unit_t *)GUnits + uVar1)->bldType;
      if (((*(uint *)((uint8_t *)&BuildingTypes[uVar1] + 19) & 2) == 0) &&
         ((*(uint *)((uint8_t *)&BuildingTypes[uVar1] + 19) & 0x20) == 0)) {
        uVar1 = 0;
      }
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



/* 5087:3dc7 */

/* [R6] touches GUnitGrid, GUnits */

uint __cdecl16far ovc22_usesGUnitGrid2(int x,int y,byte partyIndex)

{
  uint uVar1;
  uint uVar2;
  
  if (((GLeaderSheets[partyIndex])->flags5d & 4) == 0) {
    uVar1 = (*(short (*) [148] [60])GUnitGrid)[x][y];
    if (uVar1 < 0xf8) {
      uVar2 = ovr_ovc23_findRecordAt(x,y,0);
      if (uVar2 == 0xffff) {
        uVar1 = (uint)((unit_t *)GUnits + uVar1)->bldType;
        if ((*(uint *)((uint8_t *)&BuildingTypes[uVar1] + 19) & 0x20) == 0) {
          uVar1 = 0;
        }
        else if (*(char *)((uint8_t *)&BuildingTypes[uVar1] + 35) == '\0') {
          if (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x2f) == '\x05') {
            uVar1 = uVar1 + 0x18;
          }
          else {
            uVar1 = uVar1 + 6;
          }
        }
      }
      else {
        uVar1 = 0;
      }
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



/* 5087:3eb1 */

/* Returns the type of the completed building at (x,y), or 0. */

uint __cdecl16far ovc22_buildingTypeAt(int x,int y)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (*(short (*) [148] [60])GUnitGrid)[x][y];
  if (uVar1 < 0xf8) {
    uVar2 = ovr_ovc23_findRecordAt(x,y,0);
    if (uVar2 == 0xffff) {
      uVar1 = (uint)((unit_t *)GUnits + uVar1)->bldType;
      if ((*(uint *)((uint8_t *)&BuildingTypes[uVar1] + 19) & 0x20) == 0) {
        uVar1 = 0;
      }
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



/* 5087:3f3b */

/* Returns whether the map flags at (x,y) have any bit of the mask set (0 outside the map). */

int __cdecl16far ovc22_testMapFlags(int x,int y,uint mask)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  
  bVar1 = ovc22_textArena(x,y);
  if (bVar1) {
    bVar3 = (byte)(mask >> 8);
    if (((*(short (*) [60] [148])GMapFlags)[y][x] & mask) == 0) {
      iVar2 = CONCAT11(bVar3,1);
    }
    else {
      iVar2 = (uint)bVar3 << 8;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* 5087:3f8d */

/* [R6] touches GMapFlags */

uint16_t __cdecl16far ovc22_usesGMapFlags2(char skipCheck,int x1,int y1,int x2,int y2)

{
  uint16_t in_AX;
  uint16_t uVar1;
  int iVar2;
  byte bVar3;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  char cStack_3;
  
  if (skipCheck == '\0') {
    iStack_6 = ovr_ovc07_signum(x2 - x1);
    iStack_8 = ovr_ovc07_signum(y2 - y1);
    if ((iStack_6 != 0) || (iStack_8 != 0)) {
      cStack_3 = '\0';
      while( true ) {
        iStack_a = iStack_6;
        iStack_c = iStack_8;
        uVar1 = (uint16_t)((ulong)GMapFlags >> 0x10);
        iVar2 = iStack_8;
        if ((iStack_6 != 0) &&
           (iVar2 = (x1 + iStack_6) * 2,
           ((*(short (*) [60] [148])GMapFlags)[y1][x1 + iStack_6] & 3U) != 0)) {
          iStack_a = 0;
        }
        bVar3 = (byte)((uint)iVar2 >> 8);
        if ((iStack_8 != 0) &&
           (bVar3 = (byte)((uint)(x1 * 2) >> 8),
           ((*(short (*) [60] [148])GMapFlags)[y1 + iStack_8][x1] & 3U) != 0)) {
          iStack_c = 0;
        }
        if ((iStack_a == 0) && (iStack_c == 0)) break;
        if ((iStack_c == 0) || ((iStack_a != 0 && (cStack_3 != '\0')))) {
          x1 = x1 + iStack_a;
          if (x1 == x2) {
            if (y1 == y2) {
              return CONCAT11(bVar3,1);
            }
            iStack_6 = 0;
          }
        }
        else {
          y1 = y1 + iStack_c;
          if (y1 == y2) {
            if (x1 == x2) {
              return CONCAT11(bVar3,1);
            }
            iStack_8 = 0;
          }
        }
        cStack_3 = '\x01' - (cStack_3 != '\0');
      }
      return (uint)bVar3 << 8;
    }
    uVar1 = 1;
  }
  else {
    uVar1 = CONCAT11((char)((uint)in_AX >> 8),1);
  }
  return uVar1;
}



/* 5087:40ad */

/* [R4] calls ovr_alignUp4 */

uint16_t __cdecl16far
ovc22_usesAlignUp42(uint16_t *xOut,uint16_t *yOut,uint8_t classIndex,uint16_t blockedFlags)

{
  uint16_t uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uStack_4;
  
  uStack_4 = 0;
  do {
    if (GRecordCount <= uStack_4) {
      return GRecordCount & 0xff00;
    }
    if (GRecords[uStack_4].party == classIndex) {
      uVar2 = ovr_alignUp4(GRecords[uStack_4].x,0,0);
      uVar1 = GRecords[uStack_4].y;
      uVar4 = 0;
      for (iVar3 = -2; iVar3 < 2; iVar3 = iVar3 + 1) {
        uVar4 = uVar4 | (*(short (*) [60] [148])GMapFlags)[uVar1][uVar2 + iVar3];
      }
      if ((blockedFlags & uVar4) == 0) {
        *xOut = uVar2;
        *yOut = uVar1;
        return CONCAT11((char)(uVar1 >> 8),1);
      }
    }
    uStack_4 = uStack_4 + 1;
  } while( true );
}



/* 5087:416e */

/* Scans cells in expanding rings around a start point and returns 1 for the first cell that passes
   the requested occupancy/flag/arena checks, writing its coordinates through the out pointers. */

uint __cdecl16far
ovc22_searchCellsAround(uint *xPtr,uint *yPtr,byte yOutOfs,byte yOutSeg,char partyIndex)

{
  byte *pbVar1;
  byte skipCheck;
  uint x1;
  uint y1;
  bool bVar2;
  uint16_t mask;
  uint uVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  uint32_t *puVar6;
  uint *in_stack_00000004;
  char cStack_8;
  char cStack_7;
  int iStack_6;
  int iStack_4;
  
  x1 = *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004);
  y1 = *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)));
  skipCheck = *(byte *)((int)*(uint32_t *)((uint)(*(uint8_t *)((uint8_t *)&(yPtr) + 2)) << 2) + 0x3f);
  mask = 0x1000 << (skipCheck & 0x1f);
  uVar3 = ovc22_usesAlignUp4(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                             *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2)),mask);
  if ((char)uVar3 == '\0') {
    uVar4 = ovc22_usesAlignUp42((uint16_t *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                (uint16_t *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2)),mask);
    if ((char)uVar4 == '\0') {
      for (iStack_4 = 1; iStack_4 < 0x94; iStack_4 = iStack_4 + 1) {
        for (iStack_6 = 0; iStack_6 <= iStack_4; iStack_6 = iStack_6 + 1) {
          for (cStack_7 = -1; cStack_7 < '\x02'; cStack_7 = cStack_7 + '\x02') {
            for (cStack_8 = -1; cStack_8 < '\x02'; cStack_8 = cStack_8 + '\x02') {
              *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) = x1 + cStack_7 * iStack_6;
              if (cStack_7 < '\0') {
                *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) =
                     *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) - 1;
              }
              *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) = y1 + cStack_8 * iStack_4;
              if ((((3 < *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004)) &&
                   (*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) < 0x90)) &&
                  (*(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) != 0)) &&
                 (*(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) < 0x3b)) {
                uVar3 = ovc22_usesAlignUp4(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                           *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2)),
                                           mask);
                if ((char)uVar3 != '\0') {
                  return uVar3 & 0xff00;
                }
                if ((skipCheck != 0) &&
                   (uVar3 = ovc22_usesGUnitGrid(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                                *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))),
                   uVar3 != 0)) {
                  return CONCAT11((char)(uVar3 >> 8),1);
                }
                if (((yOutOfs == 3) &&
                    (uVar5 = ovc22_testMapFlags(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                                *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),mask),
                    (char)uVar5 != '\0')) &&
                   (uVar3 = ovc22_usesGMapFlags2
                                      (skipCheck,x1,y1,
                                       *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                       *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))),
                   (char)uVar3 != '\0')) {
                  return uVar3 & 0xff00;
                }
                if ((((yOutOfs & 1) == 0) && (yOutSeg == 0)) &&
                   (bVar2 = ovc22_textArena2(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                             *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))), bVar2)) {
                  uVar5 = ovc22_usesGMapFlags2
                                    (skipCheck,x1,y1,
                                     *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                     *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))));
                  if ((char)uVar5 != '\0') {
                    return CONCAT11((char)((uint)uVar5 >> 8),1);
                  }
                }
                if (((yOutOfs & 2) == 0) &&
                   (uVar3 = ovc22_usesGUnitGrid2
                                      (*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                       *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2))),
                   uVar3 != 0)) {
                  uVar5 = ovc22_usesGMapFlags2
                                    (skipCheck,x1,y1,
                                     *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                     *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))));
                  if ((char)uVar5 != '\0') {
                    return CONCAT11((char)((uint)uVar5 >> 8),1);
                  }
                }
              }
              *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) = x1 + cStack_7 * iStack_4;
              if (cStack_7 < '\0') {
                *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) =
                     *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) - 1;
              }
              *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) = y1 + cStack_8 * iStack_6;
              if (((3 < *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004)) &&
                  (*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) < 0x90)) &&
                 ((*(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) != 0 &&
                  (*(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) < 0x3b)))) {
                uVar3 = ovc22_usesAlignUp4(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                           *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2)),
                                           mask);
                if ((char)uVar3 != '\0') {
                  return uVar3 & 0xff00;
                }
                if ((skipCheck != 0) &&
                   (uVar3 = ovc22_usesGUnitGrid(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                                *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))),
                   uVar3 != 0)) {
                  return CONCAT11((char)(uVar3 >> 8),1);
                }
                if ((((yOutOfs & 3) == 3) &&
                    (uVar5 = ovc22_testMapFlags(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                                *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),mask),
                    (char)uVar5 != '\0')) &&
                   (uVar3 = ovc22_usesGMapFlags2
                                      (skipCheck,x1,y1,
                                       *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                       *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))),
                   (char)uVar3 != '\0')) {
                  return uVar3 & 0xff00;
                }
                if ((((yOutOfs & 1) == 0) && (yOutSeg == 0)) &&
                   (bVar2 = ovc22_textArena2(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                             *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))), bVar2)) {
                  uVar5 = ovc22_usesGMapFlags2
                                    (skipCheck,x1,y1,
                                     *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                     *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))));
                  if ((char)uVar5 != '\0') {
                    return CONCAT11((char)((uint)uVar5 >> 8),1);
                  }
                }
                if (((yOutOfs & 2) == 0) &&
                   (uVar3 = ovc22_usesGUnitGrid2
                                      (*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                       *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2))),
                   uVar3 != 0)) {
                  uVar5 = ovc22_usesGMapFlags2
                                    (skipCheck,x1,y1,
                                     *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                     *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))));
                  if ((char)uVar5 != '\0') {
                    return CONCAT11((char)((uint)uVar5 >> 8),1);
                  }
                }
              }
            }
          }
        }
      }
      puVar6 = (uint32_t *)0x0;
      if ((yOutOfs & 1) == 0) {
        puVar6 = (uint32_t *)((uint)(*(uint8_t *)((uint8_t *)&(yPtr) + 2)) << 2);
        pbVar1 = (byte *)((int)*puVar6 + 0x5d);
        *pbVar1 = *pbVar1 | 2;
      }
      *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) = x1;
      *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) = y1;
      uVar3 = (uint)puVar6 & 0xff00;
    }
    else {
      uVar3 = uVar4 & 0xff00;
    }
  }
  else {
    uVar3 = uVar3 & 0xff00;
  }
  return uVar3;
}



/* 5087:4576 */

/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc22_usesRandBelow(byte partyIndex,uint16_t x,uint16_t y)

{
  byte bVar1;
  uint bldType;
  uint16_t roll;
  int iVar4;
  int sheetBase;
  uint16_t sheetSeg;
  
  if ((((GLeaderSheets[partyIndex])->flags5d & 2) == 0) ||
     (((GLeaderSheets[partyIndex])->flags5d & 4) == 0)) {
    if (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x3f) == '\0') {
      bldType = ovc22_usesGUnitGrid2(x,y,partyIndex);
      if ((*(uint *)((uint8_t *)&BuildingTypes[bldType] + 19) & 0x20) == 0) {
        if (((GLeaderSheets[partyIndex])->flags5d & 2) == 0) {
          sheetSeg = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
          iVar4 = (int)*(uint32_t *)((uint)partyIndex << 2);
          if (*(int *)(iVar4 + 0x56) == 0 && *(int *)(iVar4 + 0x58) == 0) {
            bldType = 0;
          }
          else {
            sheetSeg = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
            iVar4 = (int)*(uint32_t *)((uint)partyIndex << 2);
            if ((GLeaderSheets[partyIndex])->foodProd <
                (uint)(*(int *)(iVar4 + 0x4d) * 2 + *(int *)(iVar4 + 0x4d)) >> 2) {
              bldType = 0;
            }
            else {
              iVar4 = ovr_bldng_getClass(partyIndex);
              bldType = ovr_bldng_usesRandBelow((byte)iVar4);
              bldType = bldType & 0xff;
              sheetSeg = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
              sheetBase = (int)*(uint32_t *)((uint)partyIndex << 2);
              iVar4 = *(int *)(sheetBase + 0x58);
              if ((iVar4 < 0) ||
                 ((iVar4 == 0 && (*(uint *)(sheetBase + 0x56) < *(uint *)((uint8_t *)&BuildingTypes[bldType] + 23))))) {
                bldType = 0;
              }
            }
          }
        }
        else {
          bldType = 0;
        }
      }
    }
    else {
      bldType = ovc22_usesGUnitGrid(x,y);
      if ((*(uint *)((uint8_t *)&BuildingTypes[bldType] + 19) & 2) == 0) {
        roll = ovr_randBelow(2,0);
        if (((roll & 0xff) == 0) && ((*(uint *)((uint8_t *)&BuildingTypes[bldType] + 19) & 0x20) != 0)) {
          if (*(char *)((uint8_t *)&BuildingTypes[bldType] + 35) == '\0') {
            bldType = bldType + 6;
          }
        }
        else {
          roll = ovr_randBelow(8,0);
          if (((roll & 0xff) == 0) ||
             ((roll = ovr_randBelow(3,0), (roll & 0xff) == 0 &&
              ((GLeaderSheets[partyIndex])->foodProd <
               (GLeaderSheets[partyIndex])->population)))) {
            roll = ovr_randBelow(3,0);
            bldType = (roll & 0xff) + 1;
          }
          else {
            roll = ovr_randBelow(0xc,0);
            if ((roll & 0xff) == 0) {
              roll = ovr_randBelow(3,0);
              bldType = (roll & 0xff) + 0x2b;
              sheetSeg = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
              sheetBase = (int)*(uint32_t *)((uint)partyIndex << 2);
              iVar4 = *(int *)(sheetBase + 0x58);
              if (-1 < iVar4) {
                if (iVar4 != 0) {
                  return bldType;
                }
                if (*(uint *)((uint8_t *)&BuildingTypes[bldType] + 23) <= *(uint *)(sheetBase + 0x56)) {
                  return bldType;
                }
              }
            }
            roll = ovr_randBelow(0xc,0);
            if ((roll & 0xff) == 0) {
              roll = ovr_randBelow(3,0);
              bldType = (roll & 0xff) + 0xec;
              sheetSeg = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
              sheetBase = (int)*(uint32_t *)((uint)partyIndex << 2);
              iVar4 = *(int *)(sheetBase + 0x58);
              if (-1 < iVar4) {
                if (iVar4 != 0) {
                  return bldType;
                }
                if (*(uint *)((uint8_t *)&BuildingTypes[bldType] + 23) <= *(uint *)(sheetBase + 0x56)) {
                  return bldType;
                }
              }
            }
            bVar1 = (GLeaderSheets[partyIndex])->classStr;
            roll = ovr_randBelow(3,0);
            bldType = (roll & 0xff) +
                    (uint)*(byte *)((int)&worldMenuLabels[0xb].ofs + 1 + (uint)bVar1 * 0x95);
            sheetSeg = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
            sheetBase = (int)*(uint32_t *)((uint)partyIndex << 2);
            iVar4 = *(int *)(sheetBase + 0x58);
            if ((iVar4 < 0) ||
               ((iVar4 == 0 && (*(uint *)(sheetBase + 0x56) < *(uint *)((uint8_t *)&BuildingTypes[bldType] + 23))))) {
              bldType = (uint)*(byte *)((int)&worldMenuLabels[0xb].ofs + 1 + (uint)bVar1 * 0x95);
            }
          }
        }
      }
      else {
        roll = ovr_randBelow(0x14,0);
        if ((roll & 0xff) == 0) {
          bldType = 0x72;
        }
        else {
          roll = ovr_randBelow(4,0);
          if ((roll & 0xff) == 0) {
            bldType = 0x71;
          }
          else {
            bldType = 0x70;
          }
        }
      }
    }
  }
  else {
    bldType = 0;
  }
  return bldType;
}



/* 5087:4975 */

/* [R4] calls ovr_randBelow */

void __cdecl16far ovc22_usesRandBelow2(byte partyIndex,uint16_t outFlag,uint16_t outFlagSeg)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint32_t uVar5;
  uint16_t uVar6;
  uint uVar7;
  int sheetOfs;
  int unitCount;
  char unaff_SI;
  uint16_t unitsSeg;
  byte bStack_e;
  uint16_t y;
  uint16_t x;
  byte listIndex;
  undefined1 roll;
  char matchIdx;
  char targetIdx;
  byte hasUnits;
  byte bStack_3;
  
  listIndex = ListCount;
  if (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xa8) != '\0') {
    uVar6 = ovr_randBelow(100,0);
    roll = (undefined1)uVar6;
    if ((uVar6 & 0xff) <
        ((uint)*(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xa8) * 100) /
        (*(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xa8) + 1)) {
      uVar6 = ovr_randBelow((uint)*(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xa8),0);
      targetIdx = (char)uVar6;
      matchIdx = '\0';
      for (listIndex = 0; listIndex < ListCount; listIndex = listIndex + 1) {
        unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
        if ((*(char *)((uint)((unit_t *)GUnits + *(int *)((uint)listIndex * 2 + -0x6d44))->bldType *
                       0x27 + 0x133) == '\x12') &&
           (((unit_t *)GUnits)[*(int *)((uint)listIndex * 2 + -0x6d44)].unitType == partyIndex)) {
          if (matchIdx == targetIdx) break;
          matchIdx = matchIdx + '\x01';
        }
      }
    }
  }
  if (listIndex < ListCount) {
    unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
    x = ((unit_t *)GUnits)[*(int *)((uint)listIndex * 2 + -0x6d44)].x;
    y = ((unit_t *)GUnits)[*(int *)((uint)listIndex * 2 + -0x6d44)].y;
  }
  else {
    x = (GLeaderSheets[partyIndex])->x;
    y = (GLeaderSheets[partyIndex])->y;
  }
  unitsSeg = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
  sheetOfs = (int)*(uint32_t *)((uint)partyIndex << 2);
  unitCount = *(int *)(sheetOfs + 0x58);
  if ((unitCount < 1) && ((unitCount < 0 || (*(uint *)(sheetOfs + 0x56) < 10)))) {
    hasUnits = 1;
  }
  else {
    hasUnits = 0;
  }
  if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                (uint)(GLeaderSheets[partyIndex])->classStr * 0x95) & 0x80)
      == 0) {
    bStack_3 = 0;
  }
  else {
    bStack_3 = 3;
  }
  if (((GLeaderSheets[partyIndex])->flags5d & 2) != 0) {
    bStack_3 = bStack_3 | 1;
  }
  uVar5 = *(uint32_t *)((uint)partyIndex << 2);
  if ((*(byte *)((int)uVar5 + 0x5d) & 4) != 0) {
    bStack_3 = bStack_3 | 2;
  }
  uVar7 = ovc22_searchCellsAround
                    ((uint *)CONCAT22(&y,_SS),
                     (uint *)CONCAT13((char)(((uint)partyIndex << 2) >> 8),
                                      CONCAT12(partyIndex,_SS)),bStack_3,hasUnits,unaff_SI);
  if ((uVar7 & 0xff) != 0) {
    if ((uVar7 & 0xff) != 1) {
      return;
    }
    uVar7 = ovc22_usesRandBelow(partyIndex,x,y);
    if (uVar7 == 0) {
      x = (GLeaderSheets[partyIndex])->x;
      y = (GLeaderSheets[partyIndex])->y;
    }
    else {
      if ((*(uint *)((uint8_t *)&BuildingTypes[uVar7] + 19) & 0x60) == 0) {
        unitsSeg = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
        sheetOfs = (int)*(uint32_t *)((uint)partyIndex << 2);
        unitCount = *(int *)(sheetOfs + 0x58);
        if ((unitCount < 0) ||
           ((unitCount == 0 && (*(uint *)(sheetOfs + 0x56) < *(uint *)((uint8_t *)&BuildingTypes[uVar7] + 23))))) {
          unitsSeg = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
          unitCount = (int)*(uint32_t *)((uint)partyIndex << 2);
          *(uint16_t *)(unitCount + 0x58) = 0;
          *(uint16_t *)(unitCount + 0x56) = 0;
        }
        else {
          uVar4 = *(uint *)((uint8_t *)&BuildingTypes[uVar7] + 23);
          unitsSeg = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
          unitCount = (int)*(uint32_t *)((uint)partyIndex << 2);
          puVar1 = (uint *)(unitCount + 0x56);
          uVar3 = *puVar1;
          *puVar1 = *puVar1 - uVar4;
          piVar2 = (int *)(unitCount + 0x58);
          *piVar2 = *piVar2 - (uint)(uVar3 < uVar4);
        }
      }
      bStack_e = (byte)uVar7;
      ovr_createConstructionRecordFar
                (bStack_e,x,y,
                 (uint8_t *)CONCAT13((char)(outFlagSeg >> 8),CONCAT12((char)outFlagSeg,outFlag)),
                 partyIndex,unaff_SI,(char)y,(char)outFlag,(char)outFlagSeg);
    }
  }
  if (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x3f) == '\0') {
    if ((GLeaderSheets[partyIndex])->housing <
        (GLeaderSheets[partyIndex])->population) {
      ovr_ovc18_textTypeLen(partyIndex,x,y,0x1,(char)x,(char)y);
    }
    else {
      ovr_ovc18_textTypeLen(partyIndex,x,y,0x0,(char)x,(char)y);
    }
  }
  else {
    ovr_ovc18_textTypeLen(partyIndex,0,0,0x0,0,0);
  }
  return;
}



/* 5087:4dd9 */

/* Runs the per-leader random spawn chance and spawns through ovc22_usesRandBelow2. */

void __cdecl16far ovc22_spawnForLeaders(void)

{
  uint16_t uVar1;
  uint8_t outFlag;
  int leader;
  
  outFlag = 0x0;
  for (leader = 0; leader < (int)(uint)GLeaderCount; leader = leader + 1) {
    if ((((GLeaderSheets[leader])->active != '\0') &&
        (uVar1 = ovr_randBelow((uint)(byte)((char *)0x2686a)
                                           [(uint)(GLeaderSheets[leader])->classStr * 0x95],0),
        (byte)uVar1 < ((agnt_t *)((leader << 2)))->variant)) &&
       ((*(char *)((int)*(uint32_t *)(leader << 2) + 0x3f) != '\0' ||
        ((GLeaderSheets[leader])->population <=
         (GLeaderSheets[leader])->housing)))) {
      if (EntityCount < 0x21c) {
        ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
      }
      else if (*(char *)((int)*(uint32_t *)(leader << 2) + 0x3f) == '\0') {
        if ((GLeaderSheets[leader])->unitCount < 0x23) {
          ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
        }
        else if ((GLeaderSheets[leader])->unitCount < 0x4b) {
          uVar1 = ovr_randBelow(8,0);
          if ((uVar1 & 0xff) == 0) {
            ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
          }
        }
        else {
          uVar1 = ovr_randBelow(0x10,0);
          if ((uVar1 & 0xff) == 0) {
            ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
          }
        }
      }
      else if ((GLeaderSheets[leader])->unitsOnTile == 0) {
        ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
      }
      else if ((GLeaderSheets[leader])->unitCount < 0x19) {
        ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
      }
      else if ((GLeaderSheets[leader])->unitCount < 0x32) {
        uVar1 = ovr_randBelow(8,0);
        if ((uVar1 & 0xff) == 0) {
          ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
        }
      }
      else {
        uVar1 = ovr_randBelow(0x10,0);
        if ((uVar1 & 0xff) == 0) {
          ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
        }
      }
    }
  }
  if (outFlag == 0x0) {
    ovr_constr_usesBlitRect();
  }
  else {
    ovr_constr_flushDirtyRects();
  }
  return;
}



/* 5087:503d */

/* [R6] touches GOngoingBattle, GfxRndSeed2 */

uint16_t __cdecl16far ovc22_usesGOngoingBattle(byte x,byte y)

{
  uint16_t uVar1;
  
  if (GOngoingBattle == '\0') {
    if (((int)(uint)y < GfxRndSeed2 + -4) || (GfxRndSeed2 < (int)(uint)y)) {
      return 0;
    }
  }
  else if (((int)(uint)y < GfxRndSeed2 + -2) || (GfxRndSeed2 < (int)(uint)y)) {
    return 0;
  }
  if (((int)(uint)x < GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)y) * 2 + -0x73ed)) ||
     (GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)y) * 2 + -0x73ff) < (int)(uint)x)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 5087:510e */

/* [R6] touches GOngoingBattle, GfxRndSeed2 */

uint16_t __cdecl16far ovc22_usesGOngoingBattle2(byte x,byte y)

{
  uint16_t uVar1;
  
  if (GOngoingBattle == '\0') {
    if (((int)(uint)y < GfxRndSeed2 + -2) || (GfxRndSeed2 < (int)(uint)y)) {
      return 0;
    }
  }
  else if (((int)(uint)y < GfxRndSeed2 + -1) || (GfxRndSeed2 < (int)(uint)y)) {
    return 0;
  }
  if (((int)(uint)x < GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)y) * 2 + -0x73ed)) ||
     (GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)y) * 2 + -0x73ff) < (int)(uint)x)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


