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
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  int iStack_4;
  
  if ((((x < 0) || (y < 0)) || (0x93 < x + 1)) || (0x3b < y + 1)) {
    placementStatus = 2;
    bVar1 = false;
  }
  else {
    uVar4 = (undefined2)((ulong)GMapFlags >> 0x10);
    if ((((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) == 0) &&
       (((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) == 0)) {
      iStack_4 = (int)(char)(*(byte (*) [59] [148])GMapCells)[y + 1][x];
      iVar2 = (int)(char)(*(byte (*) [59] [148])GMapCells)[y + 1][x + 1];
      iVar3 = iStack_4;
      if (iVar2 < iStack_4) {
        iVar3 = iVar2;
      }
      if (iStack_4 < iVar2) {
        iStack_4 = iVar2;
      }
      if (iStack_4 - iVar3 < 9) {
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

char * __cdecl16far ovc22_className(byte partyIndex,...)

{
  byte bVar1;
  char *pcVar2;
  byte in_stack_00000004;
  
  bVar1 = *(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x2f);
  if (bVar1 < 7) {
    pcVar2 = (char *)*(undefined2 *)((uint)bVar1 * 4 + 0x123);
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
  if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x2f) == '\x04') {
    value = value >> 1;
  }
  return value;
}



/* 5087:018f */

/* Scales a value by the leader's rank (rank+10)/10, doubles it at rank >= 10 and applies 96% for
   class 6. */

int __cdecl16far ovc22_applyRankBonus(byte partyIndex,int cost)

{
  if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x87) < 10) {
    if (*(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x87) != 0) {
      cost = (int)(((long)cost *
                    (long)(*(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x87) + 10) &
                   0xffffU) / 10);
    }
  }
  else {
    cost = cost << 1;
  }
  if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x2f) == '\x06') {
    cost = (int)(((long)cost * 0x96 & 0xffffU) / 100);
  }
  return cost;
}



/* 5087:0234 */

/* WARNING: Instruction at (ram,0x0005ff51) overlaps instruction at (ram,0x0005ff50)
    */
/* [R2] string "POPULATION" */

char * __cdecl16far ovc22_textPOPULATION(byte bldType,byte partyIndex,agnt_t *agnt,...)

{
  byte *pbVar1;
  undefined1 uVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  undefined2 uVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  agnt_t *paVar10;
  char in_CL;
  uint16_t uVar11;
  char *pcVar12;
  undefined2 unaff_SI;
  uint16_t unaff_DI;
  undefined2 unaff_SS;
  byte in_stack_00000004;
  undefined1 uStack0009;
  uint16_t in_stack_0000000e;
  uint8_t numBuf;
  uint8_t labelPtrs;
  uint8_t menuItems;
  uint8_t labelOfs;
  char *suffix;
  uint8_t *puStack_12;
  byte bVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  
  uVar14 = (undefined1)unaff_SI;
  uVar15 = (undefined1)((uint)unaff_SI >> 8);
  if (*(char *)((uint)in_stack_00000004 * 0x27 + 0x133) == '\x16') {
    pcVar7 = (char *)0x0;
  }
  else if (*(char *)((uint)in_stack_00000004 * 0x27 + 0x128) == '\0') {
    pcVar7 = (char *)0x0;
  }
  else {
    if ((*(uint *)((uint)in_stack_00000004 * 0x27 + 0x121) & 0x20) == 0) {
      if ((*(uint *)((uint)in_stack_00000004 * 0x27 + 0x121) & 0x80) == 0) {
        pcVar7 = (char *)(uint)*(byte *)((uint)in_stack_00000004 * 0x27 + 0x128);
      }
      else {
        pcVar7 = (char *)ovc22_applyRankBonus
                                   (bldType,(uint)*(byte *)((uint)in_stack_00000004 * 0x27 + 0x128))
        ;
      }
    }
    else {
      pcVar7 = (char *)ovc22_compute1(bldType,(uint)*(byte *)((uint)in_stack_00000004 * 0x27 + 0x128
                                                             ));
    }
    if (pcVar7 == (char *)0x0) {
      pcVar7 = (char *)0x0;
    }
    else if (*(char *)((uint)in_stack_00000004 * 0x27 + 0x133) == '\x19') {
      if (GSeason == '\0') {
        if (GTimeLo < 0xf) {
          pcVar7 = (char *)((uint)pcVar7 >> 2);
        }
        else {
          pcVar7 = (char *)((uint)pcVar7 >> 1);
        }
      }
      else if (GSeason == '\x02') {
        pcVar7 = pcVar7 + ((uint)pcVar7 >> 2);
      }
    }
    else {
      if ((*(uint *)((uint)in_stack_00000004 * 0x27 + 0x121) & 0x80) != 0) {
        paVar10 = (agnt_t *)agnt;
        uVar8 = ovr_constr_usesGMapFlags2();
        switch(uVar8 & 0xff) {
        case 1:
          *(char *)(unaff_DI + 0x34) = *(char *)(unaff_DI + 0x34) << 1;
code_r0x0005b805:
          if ((agnt_t *)((entity_t *)Entities)[(int)pcVar7].base.destY != (agnt_t *)agnt)
          goto L_OVC25_5b66_00ff_01D9;
          do {
            pbVar1 = (byte *)((int)&((entity_t *)Entities)[(int)pcVar7].base.flags32 + 1);
            *pbVar1 = *pbVar1 | 8;
L_OVC25_5b66_00ff_01D9:
            while( true ) {
              do {
                pcVar7 = pcVar7 + 1;
                if (EntityCount <= pcVar7) {
                  if (bldType == 0) {
                    return (char *)0xffff;
                  }
                  iVar5 = 0;
                  while( true ) {
                    if ((int)(uint)bldType <= iVar5) {
                      return (char *)0xffff;
                    }
                    puStack_12 = (uint8_t *)0xb86c;
                    uVar8 = ovc25_usesAlignUp4(in_stack_00000004,(*(uint16_t *)((uint8_t *)&(agnt) + 2)),in_stack_0000000e,
                                               unaff_DI,(uint16_t)(agnt_t *)agnt);
                    if ((int)uVar8 < 0) break;
                    *(undefined1 *)&((entity_t *)Entities)[uVar8].base.state = 0;
                    ((entity_t *)Entities)[uVar8].base.destX = unaff_DI;
                    ((entity_t *)Entities)[uVar8].base.destY = (uint16_t)(agnt_t *)agnt;
                    pbVar1 = (byte *)((int)&((entity_t *)Entities)[uVar8].base.flags32 + 1);
                    *pbVar1 = *pbVar1 | 8;
                    iVar5 = iVar5 + 1;
                  }
                  return (char *)0xffff;
                }
              } while (*(byte *)((int)&((entity_t *)Entities)[(int)pcVar7].base.entity + 3) !=
                       in_stack_00000004);
              uVar8 = ovr_alignUp4();
              uVar9 = ovr_alignUp4();
              if ((uVar8 == uVar9) &&
                 ((agnt_t *)((entity_t *)Entities)[(int)pcVar7].base.y == (agnt_t *)agnt)) break;
              uVar8 = ovr_alignUp4();
              uVar9 = ovr_alignUp4();
              if (uVar8 == uVar9) goto code_r0x0005b805;
            }
          } while( true );
        case 2:
          pcVar3 = (code *)swi(1);
          pcVar7 = (char *)(*pcVar3)();
          return pcVar7;
        case 3:
          do {
            if ((byte)paVar10->flags32 < *(byte *)((int)pcVar7 * 0x34 + 0x22)) {
              *(undefined1 *)((int)pcVar7 * 0x34 + 0x22) = (char)paVar10->flags32;
            }
            uVar11 = 0x34;
            pcVar12 = pcVar7;
code_r0x0005ff56:
            bVar13 = *(byte *)((int)pcVar7 * uVar11 + 0x21);
            paVar10 = (agnt_t *)CONCAT11((char)((int)pcVar7 * uVar11 >> 8),bVar13);
            pcVar7 = pcVar12;
            if (*(byte *)((int)pcVar12 * 0x34 + 0x22) < bVar13) {
              uVar2 = *(undefined1 *)((int)pcVar12 * 0x34 + 0x22);
              paVar10 = (agnt_t *)CONCAT11((char)((uint)((int)pcVar12 * 0x34) >> 8),uVar2);
              *(undefined1 *)((int)pcVar12 * 0x34 + 0x21) = uVar2;
            }
            do {
              pcVar7 = pcVar7 + 1;
              if ((int)(uint)AgntCount <= (int)pcVar7) {
                iVar5 = ovr_audio_panFromX();
                uVar14 = (undefined1)((uint)iVar5 >> 8);
                ovr_play_sfxU();
                return (char *)CONCAT11(uVar14,1);
              }
            } while (*(int *)((int)pcVar7 * 0x34 + 0x1b) !=
                     *(int *)(CONCAT11(uStack0009,partyIndex) + 0x1b));
          } while( true );
        case 4:
          iVar5 = ovr_font_textWidth();
          uVar11 = 0xd4 - iVar5;
          uVar14 = (undefined1)Font02.seg;
          uVar15 = (undefined1)(Font02.seg >> 8);
          cVar4 = -0x3c;
          bVar13 = 0x22;
          TextBlitX = uVar11;
          ovr_blitLabel();
          for (pcVar12 = (char *)0x0; TextBlitY = TextBlitY + 0xc, (int)pcVar12 < (int)(uint)bVar13;
              pcVar12 = pcVar12 + 1) {
            TextBlitX = 0x11;
            if (((int)pcVar12 < 5) || (cVar4 == '\0')) {
              puStack_12 = "bath";
              suffix = (char *)"fighters" + 2;
              ovr_blitLabel();
            }
            else {
              puStack_12 = "bath";
              suffix = (char *)&VideoFlag_2410_0167;
              ovr_blitLabel();
            }
            puStack_12 = (uint8_t *)CONCAT11((char)((uint)&suffix >> 8),in_stack_00000004);
            suffix = (char *)"steam bath" + 6;
            _labelOfs = 0x1b7;
            func_0x0005f303();
            puStack_12 = "";
            ovr_stsprintf();
            iVar5 = ovr_font_textWidth();
            TextBlitX = 0x89 - iVar5;
            puStack_12 = "bath";
            suffix = (char *)"clerical unit" + 9;
            ovr_blitLabel();
            puStack_12 = " unit";
            ovr_stsprintf();
            iVar5 = ovr_font_textWidth();
            uVar11 = 0xd4 - iVar5;
            cVar4 = (char)Font02.ofs;
            bVar13 = (byte)(Font02.ofs >> 8);
            puStack_12 = "bath";
            suffix = (char *)"Archduchess" + 3;
            TextBlitX = uVar11;
            ovr_blitLabel();
          }
          CurSfxType3 = 0x3c;
          puStack_12 = &menuItems;
          suffix = (char *)"steam bath" + 6;
          _labelOfs = 0x327;
          uVar6 = ovr_ovc28_usesUiInputText();
          cVar4 = (char)uVar6;
          keyboardInputMode = 0;
          if (((cVar4 != '\0') && (cVar4 != '\x01')) && (cVar4 != -2)) {
            (&stack0xbac4)[unaff_DI] = (&stack0xbac4)[unaff_DI] + in_CL;
            pcVar7 = (char *)"puppetmaker" + 3;
            goto code_r0x0005ff56;
          }
          if (cVar4 == -2) {
            Cancelled = 1;
          }
          return (char *)"puppetmaker" + 3;
        }
      }
      if (GSeason == '\x01') {
        pcVar7 = pcVar7 + ((uint)pcVar7 >> 2);
      }
      else if (GSeason == '\x02') {
        pcVar7 = (char *)((uint)pcVar7 >> 2);
      }
    }
  }
  return pcVar7;
}



/* 5087:0411 */

/* Returns a building's income adjusted for the current season and time of day. */

uint __cdecl16far ovc22_seasonalIncome(byte bldType,uint8_t partyIndex,...)

{
  uint uVar1;
  byte in_stack_00000004;
  
  if (*(int *)((uint)in_stack_00000004 * 0x27 + 0x123) == 0) {
    uVar1 = 0;
  }
  else if (*(char *)((uint)in_stack_00000004 * 0x27 + 0x133) == '\x19') {
    uVar1 = *(uint *)((uint)in_stack_00000004 * 0x27 + 0x123);
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
  else if ((*(uint *)((uint)in_stack_00000004 * 0x27 + 0x121) & 0x20) == 0) {
    if ((*(uint *)((uint)in_stack_00000004 * 0x27 + 0x121) & 0x80) == 0) {
      uVar1 = *(uint *)((uint)in_stack_00000004 * 0x27 + 0x123);
    }
    else {
      uVar1 = ovc22_applyRankBonus(bldType,*(int *)((uint)in_stack_00000004 * 0x27 + 0x123));
      if (GSeason == '\x01') {
        uVar1 = uVar1 + ((int)uVar1 >> 2);
      }
      else if (GSeason == '\x02') {
        uVar1 = (int)uVar1 >> 2;
      }
    }
  }
  else {
    uVar1 = ovc22_compute1(bldType,*(uint *)((uint)in_stack_00000004 * 0x27 + 0x123));
  }
  return uVar1;
}



/* 5087:056e */

/* WARNING: Instruction at (ram,0x0005ff51) overlaps instruction at (ram,0x0005ff50)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Type propagation algorithm not settling */
/* [R2] string "+%d ring of prot." */

far_t * __cdecl16far ovc22_textRingProt(byte partyIndex,...)

{
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
  undefined4 uVar11;
  far_t table;
  far_t pctOut;
  far_t remainderOut;
  far_t partOut;
  uint3 uVar12;
  far_t *pfVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  char cVar17;
  undefined1 uVar18;
  far_t *in_AX;
  far_t *pfVar19;
  char *pcVar20;
  uint uVar21;
  uint uVar22;
  uint16_t uVar23;
  uint16_t index;
  uint16_t uVar24;
  char cVar25;
  undefined2 in_CX;
  byte bVar26;
  byte bVar27;
  uint16_t *puVar28;
  byte bVar33;
  int iVar29;
  int iVar30;
  uint uVar31;
  uint uVar32;
  byte bVar34;
  byte bVar41;
  uint *puVar35;
  unit_t *puVar36;
  unit_t *puVar37;
  int iVar38;
  entity_t *peVar39;
  entity_t *peVar40;
  uint *puVar43;
  uint uVar44;
  uint *puVar45;
  uint uVar46;
  undefined2 unaff_SI;
  uint *puVar47;
  uint *puVar48;
  undefined2 *puVar49;
  uint *unaff_DI;
  int iVar50;
  undefined2 uVar51;
  undefined2 uVar52;
  undefined2 uVar53;
  uint unaff_SS;
  bool bVar54;
  bool bVar55;
  bool bVar56;
  bool bVar57;
  byte in_AF;
  bool bVar58;
  bool bVar59;
  bool bVar60;
  byte in_stack_00000004;
  byte bStack0008;
  undefined1 uStack0009;
  undefined1 *in_stack_0000000a;
  undefined2 in_stack_0000000c;
  byte in_stack_0000000e;
  char in_stack_00000010;
  uint16_t unitNameOfs;
  undefined2 auStackY_68 [5];
  undefined2 *puVar61;
  undefined1 uVar62;
  undefined1 uVar63;
  undefined1 uVar64;
  undefined1 uVar65;
  undefined1 uVar66;
  undefined1 uVar67;
  undefined1 uVar68;
  undefined1 uVar69;
  undefined1 in_stack_0000ffb8;
  undefined1 in_stack_0000ffb9;
  undefined1 uVar70;
  undefined1 uVar71;
  undefined1 in_stack_0000ffbc;
  undefined1 in_stack_0000ffbd;
  undefined1 in_stack_0000ffbe;
  undefined1 in_stack_0000ffbf;
  int in_stack_0000ffc0;
  int in_stack_0000ffc2;
  int iVar72;
  uint uStack_38;
  int iStack_36;
  uint uStack_34;
  int16_t resourceTotals [4];
  int16_t animStep;
  undefined2 uStack_28;
  undefined2 uStack_26;
  int iStack_24;
  int iStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  char cStack_1c;
  byte bStack_1b;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  uint *puStack_12;
  uint *puStack_10;
  undefined2 uStack_e;
  uint16_t scratch;
  uint *puStack_a;
  uint uStack_8;
  undefined4 uStack_6;
  byte bVar42;
  
  uVar18 = (undefined1)((uint)in_CX >> 8);
  uVar68 = (undefined1)unaff_SI;
  uVar69 = (undefined1)((uint)unaff_SI >> 8);
  cVar25 = (char)unaff_DI;
  uVar67 = (undefined1)((uint)unaff_DI >> 8);
  if (in_stack_00000004 != 0xff) {
    uStack_1e = 0;
    uVar70 = 0;
    uVar71 = 0;
    iStack_22 = 0;
    uStack_20 = (byte *)__C0_ASM_CopyRight + 6;
    _fmemset((void *)(ulong)unaff_SS,6,(uint16_t)unaff_DI);
    _fmemset((void *)(ulong)unaff_SS,6,CONCAT11(uVar67,cVar25));
    _fmemset((void *)(ulong)*(uint *)((uint)in_stack_00000004 * 4 + 2),3,CONCAT11(uVar67,cVar25));
    _fmemset((void *)(ulong)unaff_SS,6,CONCAT11(uVar67,cVar25));
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
    iVar72 = 0;
    _fmemset((void *)(ulong)unaff_SS,8,CONCAT11(uVar67,cVar25));
    uStack_14 = (far_t *)&GUnitDescriptions[3].ofs;
    while (uStack_14 = (far_t *)((int)uStack_14 + 1), uStack_14 < GUnitCount) {
      pbVar2 = &((unit_t *)GUnits)[(int)uStack_14].flags;
      *pbVar2 = *pbVar2 & 0xfd;
    }
    bVar16 = *(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x3f);
    uVar22 = CONCAT11(uVar18,bVar16);
    uStack_e = (uint *)(0x1000 << (bVar16 & 0x1f));
    *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0xad) = 0;
    _fmemset((void *)(ulong)*(uint *)((uint)in_stack_00000004 * 4 + 2),3,CONCAT11(uVar67,cVar25));
    iVar30 = CONCAT11(uVar71,uVar70);
    if (*(char *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x3f) == '\0') {
      pbVar2 = (byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x5d);
      *pbVar2 = *pbVar2 | 4;
    }
    else {
      pbVar2 = (byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x5d);
      *pbVar2 = *pbVar2 & 0xf9;
    }
    pbVar2 = (byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x5d);
    *pbVar2 = *pbVar2 & 0xf7;
    *(undefined2 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0xa0) = 0;
    *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0xa6) = 0;
    *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0xa5) = 0;
    *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0xa9) = 0;
    bVar16 = *(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x3e);
    (*(uint16_t *)((uint8_t *)&(uStack_6))) = (far_t *)CONCAT11(bVar16,(byte)uStack_6);
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar16 * 0x95) == '\x01') {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(far_t *)uStack_6);
      uVar12 = (uint3)uStack_6;
    }
    else {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((far_t *)uStack_6);
      uVar12 = (uint3)uStack_6;
    }
    (*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) = (byte)(uVar12 >> 8);
    if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) * 0x95) == '\0') ||
       (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) * 0x95) == '\x05')) {
      uStack_6 = (far_t *)CONCAT13(1,uVar12);
    }
    else {
      uStack_6 = (far_t *)(ulong)uVar12;
    }
    *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0xa8) = 0;
    GCanPromote = '\0';
    puVar47 = (uint *)&GUnitDescriptions[3].ofs;
    while (puVar48 = puVar47, puVar47 = (uint *)((int)puVar48 + 1), puVar47 < GUnitCount) {
      uVar51 = (undefined2)((ulong)GUnits >> 0x10);
      if (((unit_t *)GUnits)[(int)puVar47].unitType == in_stack_00000004) {
        (*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) = ((unit_t *)GUnits + (int)puVar47)->bldType;
        uStack_16 = (far_t *)ovr_alignUp4();
        uVar51 = (undefined2)((ulong)GUnits >> 0x10);
        uStack_18 = ((unit_t *)GUnits)[(int)puVar47].y;
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
          pbVar2 = &((unit_t *)GUnits)[(int)puVar47].flags;
          *pbVar2 = *pbVar2 | 3;
          iVar29 = 0x195d;
          uVar52 = 0x195d;
          pfVar19 = (far_t *)(*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) - 7);
          puVar37 = (unit_t *)GUnits;
          uVar51 = (undefined2)((ulong)GUnits >> 0x10);
          if (pfVar19 < (far_t *)((byte *)__C0_ASM_CopyRight + 0x12)) {
            puVar36 = (unit_t *)((int)pfVar19 * 2);
            bVar15 = (byte)pfVar19;
            uVar18 = (undefined1)((uint)pfVar19 >> 8);
            bVar16 = (byte)uVar22;
            bVar14 = (byte)(uVar22 >> 8);
            uVar70 = (undefined1)unaff_SS;
            uVar71 = (undefined1)(unaff_SS >> 8);
            switch(pfVar19) {
            case (far_t *)0x0:
              AgntAnms[0x68].ey = AgntAnms[0x68].ey | 0x195d;
              puVar3 = unaff_DI;
              iVar72 = 1 - (*puVar3 & 3);
              *puVar3 = *puVar3 + (uint)(0 < iVar72) * iVar72;
              *(char *)puVar47 = (char)*puVar47 + '\x01';
              uVar32 = CONCAT11(uVar18,(s_my_s_we_in_this_neighborhood_are_doing_well[0x4c] - 0x2fU)
                                       + (0xe7U < (byte)
                                                  s_my_s_we_in_this_neighborhood_are_doing_well
                                                  [0x4c]));
              puVar3 = (uint *)((int)unaff_DI + (int)((int)&puVar36[-0xd8c].y + 1));
              uVar21 = (uint)(0x46 < (byte)(s_my_s_we_in_this_neighborhood_are_doing_well[0x4c] +
                                           0x18U) ||
                             CARRY1(s_my_s_we_in_this_neighborhood_are_doing_well[0x4c] - 0x2fU,
                                    0xe7U < (byte)s_my_s_we_in_this_neighborhood_are_doing_well
                                                  [0x4c]));
              uVar46 = (int)resourceTotals + (-0x1f - *puVar3);
              iVar72 = -uVar21;
              puVar8 = (undefined1 *)(uint)(&stack0xffaf < (undefined1 *)*puVar3 || uVar46 < uVar21)
              ;
              puVar10 = &stack0xfffe + -*puVar47;
              uVar21 = (uint)(&stack0xfffe < (undefined1 *)*puVar47 || puVar10 < puVar8);
              uVar31 = (int)puVar36 - *(uint *)(&puVar36->bldType + (int)unaff_DI);
              iVar50 = uVar31 - uVar21;
              uVar21 = (uint)(puVar36 < *(unit_t **)(&puVar36->bldType + (int)unaff_DI) ||
                             uVar31 < uVar21);
              uVar31 = 0x145d - *(uint *)(iVar50 + (int)unaff_DI);
              iVar29 = uVar31 - uVar21;
              uVar21 = (uint)(0x145d < *(uint *)(iVar50 + (int)unaff_DI) || uVar31 < uVar21);
              uVar31 = uVar32 - *unaff_DI;
              iVar30 = uVar31 - uVar21;
              uVar21 = (uint)(uVar32 < *unaff_DI || uVar31 < uVar21);
              uVar31 = (int)(puVar10 + -(int)puVar8) - (uVar46 + iVar72);
              bVar56 = puVar10 + -(int)puVar8 < (undefined1 *)(uVar46 + iVar72) || uVar31 < uVar21;
              uVar31 = uVar31 - uVar21;
              bVar26 = (byte)((uint)iVar30 >> 8);
              bVar27 = (byte)((uint)iVar50 >> 8);
              bVar15 = bVar26 - bVar27;
              bVar57 = bVar26 < bVar27 || bVar15 < bVar56;
              bVar34 = (byte)iVar30;
              bVar15 = bVar15 - bVar56;
              bVar41 = (byte)iVar29;
              bVar26 = bVar41 - bVar15;
              bVar56 = bVar41 < bVar15 || bVar26 < bVar57;
              bVar33 = (byte)((uint)iVar29 >> 8);
              bVar26 = bVar26 - bVar57;
              bVar41 = bVar27 - *(byte *)(iVar50 + -0x4ae6);
              bVar57 = bVar27 < *(byte *)(iVar50 + -0x4ae6) || bVar41 < bVar56;
              bVar41 = bVar41 - bVar56;
              bVar27 = bVar34 - (char)unaff_DI[0x250d];
              bVar56 = bVar34 < (byte)unaff_DI[0x250d] || bVar27 < bVar57;
              bVar27 = bVar27 - bVar57;
              bVar34 = (byte)iVar50 - AgntAnms[0xf].frmid;
              bVar57 = (byte)iVar50 < AgntAnms[0xf].frmid || bVar34 < bVar56;
              bVar34 = bVar34 - bVar56;
              bVar9 = bVar41 - bVar27;
              bVar42 = bVar9 - bVar57;
              puVar35 = (uint *)CONCAT11(bVar42,bVar34);
              uVar21 = (uint)(bVar41 < bVar27 || bVar9 < bVar57);
              uVar32 = uVar31 - uVar22;
              puVar45 = (uint *)(uVar32 - uVar21);
              puVar3 = (uint *)((int)unaff_DI + -0x57e7);
              uVar32 = (uint)(uVar31 < uVar22 || uVar32 < uVar21);
              uVar21 = *puVar3;
              uVar31 = *puVar3;
              *puVar3 = (uVar31 - (int)puVar45) - uVar32;
              puVar3 = (uint *)((int)puVar45 + 0x7419);
              uVar32 = (uint)(uVar21 < puVar45 || uVar31 - (int)puVar45 < uVar32);
              uVar21 = *puVar3;
              uVar31 = *puVar3;
              *puVar3 = (uVar31 - uVar22) - uVar32;
              puVar3 = puVar48 + 0xd;
              uVar21 = (uint)(uVar21 < uVar22 || uVar31 - uVar22 < uVar32);
              puVar48 = (uint *)*puVar3;
              uVar22 = *puVar3;
              *puVar3 = (uVar22 - (int)puVar35) - uVar21;
              *(undefined2 *)(uVar46 + iVar72 + -2) = unaff_DI;
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
              uVar22 = (uint)(puVar48 < puVar35 || uVar22 - (int)puVar35 < uVar21);
              (*(uint16_t *)((uint8_t *)&(s_Peaceful_2410_2915) + 4)) = (0x6665U - (int)unaff_DI) - uVar22;
              uVar22 = (uint)((uint)0x6665 < unaff_DI || (uint)(0x6665U - (int)unaff_DI) < uVar22);
              bVar56 = (uint)AgntAnms[6].y < CONCAT11(bVar33,bVar26);
              uVar21 = AgntAnms[6].y - CONCAT11(bVar33,bVar26);
              AgntAnms[6].y = uVar21 - uVar22;
              uVar22 = (uint)(bVar56 || uVar21 < uVar22);
              uVar21 = (uVar46 + iVar72 + -2) - (int)unaff_DI;
              bVar56 = (uint *)(uVar46 + iVar72 + -2) < unaff_DI || uVar21 < uVar22;
              iVar72 = -uVar22;
              puVar43 = (uint *)(uVar21 + iVar72);
              bVar57 = bVar26 < bVar14 || (byte)(bVar26 - bVar14) < bVar56;
              bVar41 = (bVar26 - bVar14) - bVar56;
              bVar56 = bVar15 < bVar34 || (byte)(bVar15 - bVar34) < bVar57;
              bVar26 = (bVar15 - bVar34) - bVar57;
              bVar15 = bVar41 - bVar27;
              bVar57 = bVar41 < bVar27 || bVar15 < bVar56;
              bVar15 = bVar15 - bVar56;
              pbVar2 = (byte *)((char *)((int)puVar35 + (int)puVar47) + -0x60e8);
              bVar56 = *pbVar2 < bVar14 || (byte)(*pbVar2 - bVar14) < bVar57;
              *pbVar2 = (*pbVar2 - bVar14) - bVar57;
              puVar3 = puVar45 + -0x3974;
              bVar14 = (byte)*puVar3 - bVar15;
              bVar57 = (byte)*puVar3 < bVar15 || bVar14 < bVar56;
              *(byte *)puVar3 = bVar14 - bVar56;
              puVar3 = puVar47 + 0x3c8c;
              bVar14 = (byte)*puVar3 - bVar27;
              bVar54 = (byte)*puVar3 < bVar27 || bVar14 < bVar57;
              *(byte *)puVar3 = bVar14 - bVar57;
              puVar3 = puVar45 + 0xc;
              bVar57 = (byte)*puVar3 < bVar33;
              bVar14 = (byte)*puVar3 - bVar33;
              bVar55 = bVar57 || bVar14 < bVar54;
              bVar60 = SBORROW1((byte)*puVar3,bVar33) != SBORROW1(bVar14,bVar54);
              *(byte *)puVar3 = bVar14 - bVar54;
              bVar59 = (char)(byte)*puVar3 < '\0';
              bVar58 = (byte)*puVar3 == 0;
              bVar56 = !bVar60;
              puVar48 = puVar45;
              if (!bVar56) {
                puVar3 = unaff_DI;
                unaff_DI = (uint *)((int)unaff_DI + 1);
                cVar25 = in(CONCAT11(bVar33,bVar15));
                *(char *)puVar3 = cVar25;
                puVar3 = puVar47 + 0xc;
                uVar22 = *puVar3;
                bVar41 = (byte)*puVar3 - bVar26;
                *(byte *)puVar3 = bVar41 - bVar55;
                *(undefined2 *)(uVar21 + iVar72 + -2) = puVar35;
                ((char *)((int)puVar45 + (int)puVar47))[0x18] =
                     (((char *)((int)puVar45 + (int)puVar47))[0x18] - bVar16) -
                     ((byte)uVar22 < bVar26 || bVar41 < bVar55);
                *(uint *)((int)puVar35 + (int)puVar47) =
                     *(uint *)((int)puVar35 + (int)puVar47) ^ (uint)puVar35;
                *(uint *)((int)puVar35 + (int)puVar47) =
                     *(uint *)((int)puVar35 + (int)puVar47) | (uint)puVar35;
                *(char *)((int)puVar35 + (int)puVar47) =
                     *(char *)((int)puVar35 + (int)puVar47) + bVar34;
                *puVar35 = ~*puVar35;
                puVar48 = (uint *)*puVar45;
                uVar22 = CONCAT11(bVar26,bVar27 - 0x18) & 0x9e1f;
                bVar59 = (int)uVar22 < 0;
                bVar58 = uVar22 == 0;
                puVar43 = puVar45 + 3;
              }
              bVar55 = bVar56 && bVar55;
              uVar51 = *puVar43;
              if (bVar58 || (bVar56 && bVar60) != bVar59) {
                bVar59 = bVar55;
                if ((!bVar56 || !bVar57 && bVar14 >= bVar54) && !bVar58) {
                  *puVar43 = (uint)puVar48;
                  uVar51 = *puVar43;
                  uVar22 = (int)(char)bVar16 + 0xe299;
                  iVar72 = uVar22 - bVar55;
                  *puVar43 = iVar72;
                  *(char *)puVar47 = -(char)*puVar47;
                  return (far_t *)((iVar72 + -0x1d32) -
                                  (uint)((uint)(int)(char)bVar16 < 0x1d67 || uVar22 < bVar55));
                }
              }
              else {
                bVar59 = bVar16 < 0x74 || (byte)(bVar16 + 0x8c) < bVar55;
                bVar16 = (bVar16 + 0x8c) - bVar55;
              }
              bVar56 = bVar16 < 100 || (byte)(bVar16 + 0x9c) < bVar59;
              bVar14 = (bVar16 + 0x9c) - bVar59;
              bVar16 = bVar14 - 0x39;
              bVar57 = bVar14 < 0x39 || bVar16 < bVar56;
              bVar16 = bVar16 - bVar56;
              bVar14 = bVar16 - 0x14;
              bVar56 = bVar16 < 0x14 || bVar14 < bVar57;
              bVar14 = bVar14 - bVar57;
              bVar16 = bVar14 - 8;
              bVar57 = bVar14 < 8 || bVar16 < bVar56;
              bVar16 = bVar16 - bVar56;
              bVar14 = bVar16 - 5;
              bVar26 = bVar14 - bVar57;
              iVar72 = ((int)puVar48 - (int)puVar35) -
                       (uint)(bVar26 < 0xfa || (byte)(bVar26 + 6) < (bVar16 < 5 || bVar14 < bVar57))
              ;
              uVar21 = (uint)puVar47 & *(uint *)((char *)((int)puVar35 + (int)puVar47) + -0x6bdd);
              uVar31 = (uint)unaff_DI & *(uint *)((char *)((int)puVar35 + (int)unaff_DI) + 0x23);
              *puVar43 = uVar21;
              uVar21 = uVar21 & *(uint *)((int)puVar35 + uVar31);
              uVar22 = CONCAT11(bVar33,bVar15) & *(uint *)(iVar72 + uVar21);
              puVar47 = (uint *)CONCAT11(bVar42,bVar34 & bVar42 &
                                                *(byte *)((int)&_streams[0xc].curp +
                                                         CONCAT11(bVar42,bVar34 & bVar42)));
              uVar52 = *puVar43;
              *(uint *)(iVar72 + uVar21) = *(uint *)(iVar72 + uVar21) ^ (uint)(puVar43 + 1);
              *(int *)(iVar72 + uVar21) = *(int *)(iVar72 + uVar21) - (int)(puVar43 + 1);
              bVar16 = in(uVar22);
              uVar21 = uVar21 & uVar22;
              puVar3 = (uint *)((int)puVar47 + (int)((char *)"+%d ring of prot." + 1 + uVar21));
              *puVar3 = *puVar3 & uVar31;
              *(uint *)(uVar31 + 0x21) = *(uint *)(uVar31 + 0x21) & (uint)puVar47;
              *puVar47 = *puVar47 & uVar31;
              puVar3 = (uint *)&AgntAnms[0x5c].sx;
              *puVar3 = *puVar3 & (uint)(puVar43 + 1);
              puVar3 = (uint *)((int)puVar47 + uVar21);
              *puVar3 = *puVar3 & CONCAT11((char)((uint)uVar52 >> 8),bVar16);
              bVar15 = -(0x99 < bVar16);
              return (far_t *)CONCAT11((char)((uint)uVar52 >> 8),
                                       bVar15 + (9 < (bVar15 & 0xf) | 9 < (bVar16 & 0xf) | in_AF) *
                                                '\x06' + (0x99 < bVar15 || 0x99 < bVar16) * '`');
            case (far_t *)0x1:
              *(uint *)(&stack0x8ed6 + (int)unaff_DI) =
                   *(uint *)(&stack0x8ed6 + (int)unaff_DI) & uVar22;
              return pfVar19;
            default:
              goto switchD_5000_123d_caseD_2;
            case (far_t *)0x3:
            case (far_t *)0x14:
              goto switchD_5000_123d_caseD_3;
            case (far_t *)0x4:
              break;
            case (far_t *)0x5:
              do {
                ovr_blitLabel();
                while( true ) {
                  func_0x0005f303();
                  ovr_stsprintf();
                  iVar72 = ovr_font_textWidth();
                  TextBlitX = 0x89 - iVar72;
                  ovr_blitLabel();
                  ovr_stsprintf();
                  iVar72 = ovr_font_textWidth();
                  puVar28 = (uint16_t *)(0xd4 - iVar72);
                  TextBlitX = (uint16_t)puVar28;
                  ovr_blitLabel();
                  puVar47 = (uint *)((int)puVar47 + 1);
L_OVC22_5087_0234_323C:
                  TextBlitY = TextBlitY + 0xc;
                  cVar25 = (char)uVar22;
                  if ((int)(scratch >> 8) <= (int)puVar47) goto L_OVC22_5087_0234_32B8;
                  TextBlitX = 0x11;
                  if ((4 < (int)puVar47) && ((char)scratch != '\0')) break;
                  ovr_blitLabel();
                }
              } while( true );
            case (far_t *)0x6:
              *(uint *)(&stack0x681c + (int)puVar47) =
                   *(uint *)(&stack0x681c + (int)puVar47) & uVar22;
            case (far_t *)0xb:
              *(uint *)(&stack0x681c + (int)puVar47) =
                   *(uint *)(&stack0x681c + (int)puVar47) & uVar22;
              ovr_blitLabel();
              iVar72 = ovr_font_textWidth();
              puVar28 = (uint16_t *)(0xd4 - iVar72);
              TextBlitX = (uint16_t)puVar28;
              ovr_blitLabel();
              puVar47 = (uint *)0x0;
              goto L_OVC22_5087_0234_323C;
            case (far_t *)0x7:
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
              return pfVar19;
            case (far_t *)0x8:
              bVar26 = (&stack0xfffe)[(int)unaff_DI];
              in_AF = 9 < (bVar15 & 0xf) | in_AF;
              uVar44 = (uint)&stack0xffb4 ^ *(uint *)((int)puVar47 + (int)(&puVar36->level + -1));
              uVar21 = (uint)puVar36 ^ (uint)puVar47;
              uVar31 = CONCAT11((byte)(uVar21 >> 8) ^ *(byte *)((int)unaff_DI + uVar21 + 0x8332),
                                (char)uVar21);
              bVar27 = bVar14 ^ 0x5d ^ *(byte *)((int)unaff_DI + uVar31 + 0x32);
              uVar21 = CONCAT11(bVar26,bVar27) ^ 0x1900;
              *(uint *)(&stack0xfffe + (int)puVar47) =
                   *(uint *)(&stack0xfffe + (int)puVar47) ^ (uint)puVar47;
              uVar46 = (int)puVar47 - *(int *)(&stack0xfffe + (int)puVar47);
              uVar31 = uVar31 ^ uVar44;
              uVar32 = (uint)&stack0xfffe ^ uVar31;
              uVar22 = CONCAT11(uVar18,bVar15 + in_AF * -6 + (0x99 < bVar15) * -0x60 + '2' +
                                       (puVar47 < *(uint **)(&stack0xfffe + (int)puVar47))) - 0x5ceU
                       ^ uVar22;
              puVar3 = (uint *)((int)unaff_DI + uVar31 + 0xa231);
              *puVar3 = *puVar3 ^ uVar46;
              *(uint *)((char *)"%s: %s %d gold. Provides housing for %d %s." + 3 + uVar31) =
                   *(uint *)((char *)"%s: %s %d gold. Provides housing for %d %s." + 3 + uVar31) ^
                   uVar21;
              puVar3 = (uint *)(uVar32 + uVar46 + 0x31);
              *puVar3 = *puVar3 ^ (uint)unaff_DI;
              iVar30 = uVar46 + 1;
              *(uint *)(uVar32 + (int)unaff_DI) = *(uint *)(uVar32 + (int)unaff_DI) ^ uVar44;
              *unaff_DI = *unaff_DI ^ uVar21;
              puVar49 = (undefined2 *)((uint)unaff_DI ^ uVar44);
              bVar41 = (byte)(uVar22 >> 8);
              bVar15 = (byte)uVar22 ^ bVar27;
              pbVar2 = (byte *)((int)puVar49 + uVar32 + 0xa330);
              *pbVar2 = *pbVar2 ^ bVar26 ^ 0x19;
              *(byte *)(puVar49 + -0x3be8) = *(byte *)(puVar49 + -0x3be8) ^ (byte)uVar31;
              pbVar2 = (byte *)(uVar31 + iVar30 + 0x30);
              bVar26 = (byte)(uVar31 >> 8);
              *pbVar2 = *pbVar2 ^ bVar26;
              pbVar6 = (byte *)(puVar49 + 1);
              uVar51 = in(uVar21);
              *puVar49 = uVar51;
              pbVar2 = (byte *)(uVar31 + iVar30 + 0x30);
              *pbVar2 = *pbVar2 ^ (byte)uVar31;
              *(uint *)(uVar44 - 2) = uVar21;
              *pbVar6 = *pbVar6 ^ bVar26;
              *pbVar6 = *pbVar6 ^ bVar14;
              *(byte *)(uVar32 + iVar30) = *(byte *)(uVar32 + iVar30) ^ bVar41;
              *pbVar6 = *pbVar6 ^ bVar16;
              *(byte *)(uVar32 + iVar30) = *(byte *)(uVar32 + iVar30) ^ bVar15;
              in_AF = 9 < (bVar15 & 0xf) | in_AF;
              bVar16 = bVar15 + in_AF * -6 + (0x99 < bVar15) * -0x60;
              iVar72 = *(int *)(uVar44 - 2);
              uVar22 = CONCAT11(bVar41 ^ bVar26,
                                bVar16 + (9 < (bVar16 & 0xf) | in_AF) * -6 +
                                (0x99 < bVar16 || 0x99 < bVar15) * -0x60) ^ 0xaf;
              uVar32 = uVar32 ^ uVar22;
              bVar16 = (byte)uVar22 ^ (byte)*(undefined2 *)(uVar31 + iVar30);
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              *(char *)(uVar31 + iVar30) = *(char *)(uVar31 + iVar30) + bVar16;
              pcVar1 = (char *)(iVar72 + -0x75);
              *pcVar1 = *pcVar1 + bVar27;
              in(uVar21);
              *(int *)(uVar44 - 0x10) = iVar30;
              *(int *)(uVar44 - 0x12) = iVar72;
              iVar72 = *(int *)(uVar32 + 6);
              iVar30 = *(int *)(uVar32 + 8);
              if ((((iVar72 < 0) || (iVar30 < 0)) || (0x93 < iVar72 + 1)) || (0x3b < iVar30 + 1)) {
                placementStatus = 2;
                pfVar19 = (far_t *)((char *)"arena" + 4);
              }
              else {
                uVar51 = (undefined2)((ulong)GMapFlags >> 0x10);
                if ((((*(short (*) [60] [148])GMapFlags)[iVar30][iVar72] & 3U) == 0) &&
                   (((*(short (*) [60] [148])GMapFlags)[iVar30 + 1][iVar72] & 3U) == 0)) {
                  *(int *)(uVar32 - 10) =
                       (int)(char)(*(byte (*) [59] [148])GMapCells)[iVar30 + 1][iVar72];
                  *(int *)(uVar32 - 8) =
                       (int)(char)(*(byte (*) [59] [148])GMapCells)[iVar30 + 1][iVar72 + 1];
                  iVar72 = *(int *)(uVar32 - 10);
                  *(undefined2 *)(uVar32 - 2) = *(undefined2 *)(uVar32 - 10);
                  if (*(int *)(uVar32 - 8) < iVar72) {
                    iVar72 = *(int *)(uVar32 - 8);
                  }
                  if (*(int *)(uVar32 - 2) < *(int *)(uVar32 - 8)) {
                    *(undefined2 *)(uVar32 - 2) = *(undefined2 *)(uVar32 - 8);
                  }
                  uVar22 = *(int *)(uVar32 - 2) - iVar72;
                  if ((int)uVar22 < 9) {
                    placementStatus = 3;
                    pfVar19 = (far_t *)((char *)"arena" + 5);
                  }
                  else {
                    pfVar19 = (far_t *)(uVar22 & 0xff00);
                  }
                }
                else {
                  placementStatus = 1;
                  pfVar19 = (far_t *)((char *)"arena" + 4);
                }
              }
              return pfVar19;
            case (far_t *)0x9:
              do {
                ovc22_textRingProt();
                do {
                  uStack_16 = (far_t *)((int)uStack_16 + 1);
                  if ((int)(uint)GLeaderCount <= (int)uStack_16) {
                    GGameState = 0x3e;
                    if (DebugVerbose != false) {
                      printf("%d \r");
                    }
                    unaff_DI = (uint *)&GUnitDescriptions[3].ofs;
                    goto L_upd_units_5087_1d7d_202C;
                  }
                } while (*(char *)((int)*(undefined4 *)((int)uStack_16 * 4) + 0x3d) == '\0');
              } while( true );
            case (far_t *)0xa:
              break;
            case (far_t *)0xc:
              (*(uint8_t *)((uint8_t *)&(iVar72))) = (puVar36 + -0xc24)->bldType;
              (*(uint8_t *)((uint8_t *)&(iVar72) + 1)) = (puVar36 + -0xc24)->level;
              do {
                pfVar19 = (far_t *)uStack_6;
                if (puVar37[iVar72].unitType == in_stack_00000004) {
                  if ((byte)uStack_6 == (*(uint8_t *)((uint8_t *)&(uStack_6) + 1))) {
L_OVC22_5087_4975_4ABE:
                    (*(uint16_t *)((uint8_t *)&(uStack_6))) = pfVar19;
                    if ((byte)uStack_8 < ListCount) {
                      puStack_a = (uint *)puVar37[*(int *)((uStack_8 & 0xff) * 2 + -0x6d44)].x;
                      scratch = puVar37[*(int *)((uStack_8 & 0xff) * 2 + -0x6d44)].y;
                    }
                    else {
                      puStack_a = (uint *)*(uint16_t *)
                                           ((int)*(undefined4 *)((uint)in_stack_00000004 << 2) +
                                           0x39);
                      scratch = *(uint16_t *)
                                 ((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x3b);
                    }
                    uVar51 = (undefined2)
                             ((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
                    iVar30 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
                    iVar72 = *(int *)(iVar30 + 0x58);
                    if ((iVar72 < 1) && ((iVar72 < 0 || (*(uint *)(iVar30 + 0x56) < 10)))) {
                      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(far_t *)uStack_6);
                    }
                    else {
                      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((far_t *)uStack_6);
                    }
                    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                                  (uint)*(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2)
                                                 + 0x3e) * 0x95) & 0x80) == 0) {
                      uStack_6 = (far_t *)(ulong)(uint3)uStack_6;
                    }
                    else {
                      uStack_6 = (far_t *)CONCAT13(3,(uint3)uStack_6);
                    }
                    if ((*(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x5d) & 2)
                        != 0) {
                      uStack_6 = (far_t *)((ulong)uStack_6 | 0x1000000);
                    }
                    uVar11 = *(undefined4 *)((uint)in_stack_00000004 << 2);
                    if ((*(byte *)((int)uVar11 + 0x5d) & 4) != 0) {
                      uStack_6 = (far_t *)((ulong)uStack_6 | 0x2000000);
                    }
                    uVar22 = ovc22_searchCellsAround
                                       ((uint *)CONCAT13((char)((uint)&scratch >> 8),
                                                         CONCAT12((char)&scratch,unaff_SS)),
                                        (uint *)CONCAT13((char)(((uint)in_stack_00000004 << 2) >> 8)
                                                         ,CONCAT12(in_stack_00000004,unaff_SS)),
                                        (*(uint8_t *)((uint8_t *)&(uStack_6) + 3)),(*(uint8_t *)((uint8_t *)&(uStack_6) + 2)),cVar25);
                    pfVar19 = (far_t *)(uVar22 & 0xff);
                    if (pfVar19 != (far_t *)0x0) {
                      if (pfVar19 != (far_t *)((int)(undefined4 *)&_DATA + 1U)) {
                        return pfVar19;
                      }
                      uStack_e = (uint *)ovc22_usesRandBelow(in_stack_00000004,(uint16_t)puStack_a,
                                                             scratch);
                      if (uStack_e == (uint *)0x0) {
                        puStack_a = (uint *)*(uint16_t *)
                                             ((int)*(undefined4 *)((uint)in_stack_00000004 << 2) +
                                             0x39);
                        scratch = *(uint16_t *)
                                   ((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x3b);
                      }
                      else {
                        if ((*(uint *)((int)uStack_e * 0x27 + 0x121) & 0x60) == 0) {
                          uVar51 = (undefined2)
                                   ((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
                          iVar30 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
                          iVar72 = *(int *)(iVar30 + 0x58);
                          if ((iVar72 < 0) ||
                             ((iVar72 == 0 &&
                              (*(uint *)(iVar30 + 0x56) < *(uint *)((int)uStack_e * 0x27 + 0x125))))
                             ) {
                            uVar51 = (undefined2)
                                     ((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
                            iVar72 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
                            *(undefined2 *)(iVar72 + 0x58) = 0;
                            *(undefined2 *)(iVar72 + 0x56) = 0;
                          }
                          else {
                            uVar21 = *(uint *)((int)uStack_e * 0x27 + 0x125);
                            uVar51 = (undefined2)
                                     ((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
                            iVar72 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
                            puVar3 = (uint *)(iVar72 + 0x56);
                            uVar22 = *puVar3;
                            *puVar3 = *puVar3 - uVar21;
                            piVar4 = (int *)(iVar72 + 0x58);
                            *piVar4 = *piVar4 - (uint)(uVar22 < uVar21);
                          }
                        }
                        ovr_createConstructionRecordFar();
                      }
                    }
                    if (*(char *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x3f) == '\0'
                       ) {
                      if (*(uint *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x5b) <
                          *(uint *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x4d)) {
                        pfVar19 = (far_t *)ovr_ovc18_textTypeLen();
                      }
                      else {
                        pfVar19 = (far_t *)ovr_ovc18_textTypeLen();
                      }
                    }
                    else {
                      pfVar19 = (far_t *)ovr_ovc18_textTypeLen();
                    }
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
                    return pfVar19;
                  }
                  uStack_6 = (far_t *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),(byte)uStack_6 + '\x01');
                }
                do {
                  bVar16 = (byte)uStack_8 + 1;
                  uStack_8 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_8) + 1)),bVar16);
                  pfVar19 = (far_t *)uStack_6;
                  if (ListCount <= bVar16) goto L_OVC22_5087_4975_4ABE;
                } while (*(char *)((uint)(puVar37 + *(int *)((uint)bVar16 * 2 + -0x6d44))->bldType *
                                   0x27 + 0x133) != '\x12');
                iVar72 = *(int *)((uint)bVar16 * 2 + -0x6d44);
              } while( true );
            case (far_t *)0xd:
              bVar16 = (byte)((uint)puVar36 >> 8);
              if (!CARRY1(bVar16,bVar16) && ((uint)puVar36 & 0x7f00) != 0) {
                uVar22 = ovr_ovc23_findRecordAt();
                if (uVar22 == 0xffff) {
                  pfVar19 = (far_t *)(uint)((unit_t *)GUnits + (*(uint16_t *)((uint8_t *)&(uStack_6) + 2)))->bldType;
                  if ((*(uint *)((int)pfVar19 * 0x27 + 0x121) & 0x20) == 0) {
                    pfVar19 = (far_t *)0x0;
                  }
                  else if (*(char *)((int)pfVar19 * 0x27 + 0x131) == '\0') {
                    if (*(char *)((int)*(undefined4 *)((uint)bStack0008 << 2) + 0x2f) == '\x05') {
                      pfVar19 = pfVar19 + 6;
                    }
                    else {
                      pfVar19 = (far_t *)&pfVar19[1].seg;
                    }
                  }
                }
                else {
                  pfVar19 = (far_t *)0x0;
                }
                return pfVar19;
              }
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            case (far_t *)0xe:
              uVar51 = CONCAT11(uVar69,uVar68);
              puVar36->bldType = puVar36->bldType | bVar15;
              if (uVar22 != 0) {
                pfVar19 = (far_t *)*(far_t **)((char *)"sage" + 3);
              }
              *(uint *)((char *)"squares" + 3) = *(uint *)((char *)"squares" + 3) ^ (uint)pfVar19;
              uVar18 = in(5);
              if (((uint)pfVar19 | 0x606) == 0) {
                *unaff_DI = *unaff_DI +
                            ((CONCAT11((char)(((uint)pfVar19 | 0x606) >> 8),uVar18) + 0x53e) -
                            *unaff_DI);
              }
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            case (far_t *)0xf:
              do {
                uVar51 = (undefined2)((ulong)Entities >> 0x10);
                uVar22 = CONCAT11(uVar67,cVar25) -
                         *(uint16_t *)
                          ((int)&(((entity_t *)Entities)->base).x +
                          CONCAT11((char)((int)pfVar19 % (int)(char)(&stack0x0035)[(int)puVar47]),
                                   (char)((int)pfVar19 / (int)(char)(&stack0x0035)[(int)puVar47])) *
                          iVar29);
                uVar31 = (int)uVar22 >> 0xf;
                uVar21 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b) -
                         ((entity_t *)Entities)[scratch].base.y;
                uVar32 = (int)uVar21 >> 0xf;
                puVar47 = (uint *)((int)((uVar22 ^ uVar31) - uVar31) / 2 +
                                  ((uVar21 ^ uVar32) - uVar32));
                if (puVar47 < uStack_e) {
                  uStack_e = puVar47;
                  unaff_DI = (uint *)scratch;
                }
                if (puVar47 < (byte *)__C0_ASM_CopyRight + 6) {
                  piVar4 = (int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x43);
                  *piVar4 = *piVar4 + 1;
                }
                do {
                  while( true ) {
                    scratch = scratch + 1;
                    while (EntityCount <= scratch) {
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x4b) = unaff_DI;
                      uStack_16 = (far_t *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_16) + 1)),0xff);
                      if (*(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x40) != '\0') {
                        puStack_10 = (uint *)0xffff;
                        for (scratch = 0; (int)scratch < (int)(uint)GLeaderCount;
                            scratch = scratch + 1) {
                          if ((*(char *)((int)*(undefined4 *)(scratch << 2) + 0x3f) !=
                               *(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3f)) &&
                             (uVar22 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x39) -
                                       *(int *)((int)*(undefined4 *)(scratch << 2) + 0x39),
                             uVar31 = (int)uVar22 >> 0xf,
                             uVar21 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b) -
                                      *(int *)((int)*(undefined4 *)(scratch << 2) + 0x3b),
                             uVar32 = (int)uVar21 >> 0xf,
                             puVar47 = (uint *)((int)((uVar22 ^ uVar31) - uVar31) / 2 +
                                               ((uVar21 ^ uVar32) - uVar32)), puVar47 < puStack_10))
                          {
                            uStack_16 = (far_t *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_16) + 1)),(char)scratch);
                            puStack_10 = puVar47;
                          }
                        }
                      }
                      *(undefined1 *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x49) =
                           (undefined1)uStack_16;
                      do {
                        puStack_a = (uint *)((int)puStack_a + 1);
                        if ((int)(uint)GLeaderCount <= (int)puStack_a) {
                          for (puStack_a = (uint *)0x0; pfVar19 = (far_t *)(uint)GLeaderCount,
                              (int)puStack_a < (int)pfVar19;
                              puStack_a = (uint *)((int)puStack_a + 1)) {
                            if ((*(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x40) != '\0'
                                ) && (*(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3d) !=
                                      '\0')) {
                              ovc25_intelAttackingNotice((byte)puStack_a);
                              if (*(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x4b) == -1)
                              {
                                uStack_14 = (far_t *)0xffff;
                              }
                              else {
                                unaff_DI = (uint *)*(undefined2 *)
                                                    ((int)*(undefined4 *)((int)puStack_a << 2) +
                                                    0x4b);
                                uVar51 = (undefined2)((ulong)Entities >> 0x10);
                                uVar22 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x39)
                                         - (((entity_t *)Entities + (int)unaff_DI)->base).x;
                                uVar31 = (int)uVar22 >> 0xf;
                                uVar21 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b)
                                         - ((entity_t *)Entities)[(int)unaff_DI].base.y;
                                uVar32 = (int)uVar21 >> 0xf;
                                uStack_14 = (far_t *)((int)((uVar22 ^ uVar31) - uVar31) / 2 +
                                                     ((uVar21 ^ uVar32) - uVar32));
                              }
                              if ((*(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x43) == 0)
                                 || ((byte *)__C0_ASM_CopyRight + 6 <= uStack_14)) {
                                if ((*(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x49) ==
                                     -1) || ((*(byte *)((int)*(undefined4 *)((int)puStack_a << 2) +
                                                       0x5d) & 1) == 0)) {
                                  if (*(uint *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x47) <
                                      10) {
                                    ovc25_usesAlignUp43((byte)puStack_a,10,
                                                        *(uint16_t *)
                                                         ((int)*(undefined4 *)((int)puStack_a << 2)
                                                         + 0x39),*(uint16_t *)
                                                                  ((int)*(undefined4 *)
                                                                         ((int)puStack_a << 2) +
                                                                  0x3b),'\0');
                                    *(undefined1 *)
                                     ((int)*(undefined4 *)((int)puStack_a << 2) + 0x4a) = 0;
                                  }
                                  else {
                                    *(undefined1 *)
                                     ((int)*(undefined4 *)((int)puStack_a << 2) + 0x4a) = 0;
                                    uStack_18 = CONCAT11(*(undefined1 *)
                                                          ((int)*(undefined4 *)((int)puStack_a << 2)
                                                          + 0x3e),(undefined1)uStack_18);
                                    iVar72 = ovc25_compute1();
                                    uStack_6 = (far_t *)CONCAT22(iVar72,(far_t *)uStack_6);
                                    if ((int)(uint)PlayerCount < iVar72) {
                                      uVar23 = ovr_randBelow();
                                      pfVar19 = (far_t *)(*(int *)((int)*(undefined4 *)
                                                                         ((int)puStack_a << 2) +
                                                                  0x39) + -0x14 + (uVar23 & 0xff));
                                      (*(uint16_t *)((uint8_t *)&(uStack_6))) = pfVar19;
                                      if ((int)pfVar19 < 4) {
                                        (*(uint16_t *)((uint8_t *)&(uStack_6))) = (far_t *)__C0_ASM_CopyRight;
                                      }
                                      if (0x8c < (int)(far_t *)uStack_6) {
                                        (*(uint16_t *)((uint8_t *)&(uStack_6))) = (far_t *)&_brklvl;
                                      }
                                      uVar23 = ovr_randBelow();
                                      uStack_8 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2)
                                                         + 0x3b) + -10 + (uVar23 & 0xff);
                                      if ((int)uStack_8 < 1) {
                                        uStack_8 = 1;
                                      }
                                      if (0x3a < (int)uStack_8) {
                                        uStack_8 = 0x3a;
                                      }
                                      ovc25_usesAlignUp44();
                                    }
                                  }
                                }
                                else {
                                  ovc25_usesEntityCount((byte)puStack_a);
                                  bVar16 = *(byte *)((int)*(undefined4 *)((int)puStack_a << 2) +
                                                    0x49);
                                  uStack_16 = (far_t *)CONCAT11(bVar16,(undefined1)uStack_16);
                                  if (0xe < *(uint *)((int)*(undefined4 *)((int)puStack_a << 2) +
                                                     0x47)) {
                                    ovc25_usesAlignUp42((byte)puStack_a,10,
                                                        *(uint16_t *)
                                                         ((int)*(undefined4 *)((uint)bVar16 << 2) +
                                                         0x39),*(uint16_t *)
                                                                ((int)*(undefined4 *)
                                                                       ((uint)bVar16 << 2) + 0x3b),
                                                        *(uint16_t *)
                                                         ((int)*(undefined4 *)((int)puStack_a << 2)
                                                         + 0x39),*(uint16_t *)
                                                                  ((int)*(undefined4 *)
                                                                         ((int)puStack_a << 2) +
                                                                  0x3b));
                                    if (*(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x4a)
                                        != '\x02') {
                                      ovr_alignUp4();
                                      auStackY_68[4] = 0xc5d4;
                                      ovr_stsprintf();
                                      ovr_uiNotify();
                                    }
                                  }
                                  ovc25_usesAlignUp43((byte)puStack_a,0xf,
                                                      *(uint16_t *)
                                                       ((int)*(undefined4 *)((int)puStack_a << 2) +
                                                       0x39),*(uint16_t *)
                                                              ((int)*(undefined4 *)
                                                                     ((int)puStack_a << 2) + 0x3b),
                                                      '\0');
                                  *(undefined1 *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x4a)
                                       = 2;
                                }
                              }
                              else {
                                ovc25_usesEntityCount((byte)puStack_a);
                                if (9 < *(uint *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x47))
                                {
                                  uVar51 = (undefined2)((ulong)Entities >> 0x10);
                                  ovc25_usesAlignUp43((byte)puStack_a,5,
                                                      (((entity_t *)Entities + (int)unaff_DI)->base)
                                                      .x,((entity_t *)Entities)[(int)unaff_DI].base.
                                                         y,'\x01');
                                }
                                ovc25_usesAlignUp43((byte)puStack_a,10,
                                                    *(uint16_t *)
                                                     ((int)*(undefined4 *)((int)puStack_a << 2) +
                                                     0x39),*(uint16_t *)
                                                            ((int)*(undefined4 *)
                                                                   ((int)puStack_a << 2) + 0x3b),
                                                    '\0');
                                *(undefined1 *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x4a) =
                                     1;
                              }
                            }
                          }
                          ovc25_clearEntityFlags();
                          return pfVar19;
                        }
                      } while (*(char *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x3d) == '\0');
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x47) = 0;
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x41) = 0;
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x43) = 0;
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x45) = 0;
                      uStack_e = (uint *)0xffff;
                      unaff_DI = (uint *)0xffff;
                      puStack_12 = (uint *)ovr_alignUp4();
                      scratch = 0;
                    }
                    uVar51 = (undefined2)((ulong)Entities >> 0x10);
                    peVar39 = (entity_t *)Entities;
                    if ((uint *)(uint)*(byte *)((int)&peVar39[scratch].base.entity + 3) != puStack_a
                       ) break;
                    uVar22 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x39) -
                             ((peVar39 + scratch)->base).x;
                    uVar31 = (int)uVar22 >> 0xf;
                    uVar21 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b) -
                             peVar39[scratch].base.y;
                    uVar32 = (int)uVar21 >> 0xf;
                    puVar47 = (uint *)((int)((uVar22 ^ uVar31) - uVar31) / 2 +
                                      ((uVar21 ^ uVar32) - uVar32));
                    piVar4 = (int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x45);
                    *piVar4 = *piVar4 + 1;
                    if (((puVar47 < (byte *)__C0_ASM_CopyRight + 6) &&
                        (piVar4 = (int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x41),
                        *piVar4 = *piVar4 + 1,
                        *(uint16_t *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b) ==
                        ((entity_t *)Entities)[scratch].base.y)) &&
                       (puVar48 = (uint *)ovr_alignUp4(), puVar48 == puStack_12)) {
                      piVar4 = (int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x47);
                      *piVar4 = *piVar4 + 1;
                    }
                  }
                } while (*(char *)((int)(char **)GMenuStrings +
                                  (uint)peVar39[scratch].base.gindex * 0x95 + 0x1f) ==
                         *(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3f));
                uVar51 = *(undefined2 *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x39);
                cVar25 = (char)uVar51;
                uVar67 = (undefined1)((uint)uVar51 >> 8);
                iVar29 = 0x37;
                pfVar19 = (far_t *)scratch;
              } while( true );
            case (far_t *)0x10:
              puVar28 = &unitNameOfs;
              manage_applyUnitFilter
                        (in_stack_00000004,((uint)uStack_e >> 8) - 4,
                         (char *)CONCAT13((char)((uint)auStackY_68[((uint)pfVar19 & 0xff) * 2] >> 8)
                                          ,CONCAT12((char)auStackY_68[((uint)pfVar19 & 0xff) * 2],
                                                    puVar28[((uint)pfVar19 & 0xff) * 2])));
              cVar25 = (char)uVar22;
L_OVC22_5087_0234_32B8:
              CurSfxType3 = 0x3c;
              uVar51 = ovr_ovc28_usesUiInputText();
              cVar17 = (char)uVar51;
              uStack_e = (uint *)CONCAT11(cVar17,(undefined1)uStack_e);
              keyboardInputMode = 0;
              if (((cVar17 != '\0') && (cVar17 != '\x01')) && (cVar17 != -2)) {
                (&stack0xbac4)[(int)unaff_DI] = (&stack0xbac4)[(int)unaff_DI] + cVar25;
                puVar48 = (uint *)((char *)"puppetmaker" + 3);
                do {
                  iVar72 = (int)puVar48 * (int)puVar28;
                  puVar48 = puVar47;
                  if (*(byte *)((int)puVar47 * 0x34 + 0x22) < *(byte *)(iVar72 + 0x21)) {
                    *(undefined1 *)((int)puVar47 * 0x34 + 0x21) =
                         *(undefined1 *)((int)puVar47 * 0x34 + 0x22);
                  }
                  do {
                    puVar48 = (uint *)((int)puVar48 + 1);
                    if ((int)(uint)AgntCount <= (int)puVar48) {
                      iVar72 = ovr_audio_panFromX();
                      uVar18 = (undefined1)((uint)iVar72 >> 8);
                      ovr_play_sfxU();
                      return (far_t *)CONCAT11(uVar18,1);
                    }
                  } while (*(int *)((int)puVar48 * 0x34 + 0x1b) !=
                           *(int *)(CONCAT11(uStack0009,bStack0008) + 0x1b));
                  uVar51 = (undefined2)((ulong)uStack_6 >> 0x10);
                  if ((byte)((far_t *)uStack_6)[0xc].seg < *(byte *)((int)puVar48 * 0x34 + 0x22)) {
                    *(undefined1 *)((int)puVar48 * 0x34 + 0x22) = (char)((far_t *)uStack_6)[0xc].seg
                    ;
                  }
                  puVar28 = (uint16_t *)((char *)"Divide error\r\n" + 5);
                  puVar47 = puVar48;
                } while( true );
              }
              if (cVar17 != -2) {
                keyboardInputMode = 0;
                return (far_t *)((char *)"puppetmaker" + 3);
              }
              Cancelled = 1;
              keyboardInputMode = 0;
              return (far_t *)((char *)"puppetmaker" + 3);
            case (far_t *)0x11:
              GRecordCount = GRecordCount + -1;
              _fmemset((void *)0x21f2,0x12,CONCAT11(in_stack_0000ffbf,in_stack_0000ffbe));
              *(byte *)(GRecordCount * 0x12 + 8) = in_stack_00000004;
              *(uint16_t *)(GRecordCount * 0x12 + 2) = (uint16_t)_partyIndex;
              *(undefined2 *)(GRecordCount * 0x12 + 4) = CONCAT11(uStack0009,bStack0008);
              *(byte *)(GRecordCount * 0x12 + 9) = in_stack_0000000e;
              iVar72 = ovc23_isLargeBuilding((int)_partyIndex,CONCAT11(uStack0009,bStack0008));
              uVar52 = (undefined2)((ulong)GUnitGrid >> 0x10);
              uVar51 = (undefined2)((ulong)GUnits >> 0x10);
              if ((char)iVar72 == '\0') {
                bVar16 = ((unit_t *)GUnits +
                         (*(short (*) [148] [60])GUnitGrid)[(int)_partyIndex]
                         [CONCAT11(uStack0009,bStack0008)])->bldType;
              }
              else {
                bVar16 = ((unit_t *)GUnits +
                         (*(short (*) [148] [60])GUnitGrid)[(int)((int)&_partyIndex[-1].seg + 1)]
                         [CONCAT11(uStack0009,bStack0008)])->bldType;
              }
              cVar25 = *(char *)((uint)bVar16 * 0x27 + 0x11d);
              (*(uint32_t *)((uint8_t *)&(uStack_6))) =
                   CONCAT12(*(undefined1 *)((uint)bVar16 * 0x27 + 0x11b),
                            CONCAT11(bVar16,(byte)uStack_6));
              uStack_6 = (far_t *)CONCAT13(cVar25,(uint3)uStack_6);
              if (cVar25 == '\0') {
                uStack_6 = (far_t *)CONCAT13(1,(uint3)uStack_6);
              }
              if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) < *(byte *)((uint)in_stack_00000004 * 0x27 + 0x11c)) {
                *(undefined1 *)(GRecordCount * 0x12 + 6) =
                     *(undefined1 *)((uint)in_stack_00000004 * 0x27 + 0x11c);
              }
              else {
                *(byte *)(GRecordCount * 0x12 + 6) = (*(uint8_t *)((uint8_t *)&(uStack_6) + 3));
              }
              *(undefined2 *)(GRecordCount * 0x12 + 0xf) = GameTick;
              *(undefined2 *)(GRecordCount * 0x12) = 0;
              uVar51 = ovc23_usesGRecordCount3
                                 (*(byte *)((uint)in_stack_00000004 * 0x27 + 0x120),
                                  in_stack_0000000e,GRecordCount);
              *(undefined1 *)(GRecordCount * 0x12 + 0xc) = (char)uVar51;
              if (*(char *)(GRecordCount * 0x12 + 0xc) == '\0') {
                *(undefined1 *)(GRecordCount * 0x12 + 0xc) = 1;
              }
              if (in_stack_00000004 == 0) {
                iVar72 = ovc23_isLargeBuilding((int)_partyIndex,CONCAT11(uStack0009,bStack0008));
                if ((char)iVar72 != '\0') {
                  piVar4 = (int *)(GRecordCount * 0x12 + 2);
                  *piVar4 = *piVar4 + -1;
                }
                *(undefined1 *)(GRecordCount * 0x12 + 7) = (*(uint8_t *)((uint8_t *)&(uStack_6) + 2));
                if (in_stack_00000010 == '\x01') {
                  *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 1;
                }
                else {
                  *(char *)(GRecordCount * 0x12 + 0xc) = in_stack_00000010;
                  *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 0;
                }
                pbVar2 = (byte *)(GRecordCount * 0x12 + 0xd);
                *pbVar2 = *pbVar2 | 3;
              }
              else {
                *(undefined1 *)(GRecordCount * 0x12 + 7) =
                     *(undefined1 *)((uint)in_stack_00000004 * 0x27 + 0x11b);
                if (in_stack_00000010 != '\0') {
                  ovc23_placeBuilding();
                  uVar51 = ovr_ovc22_usesGOngoingBattle();
                  if ((char)uVar51 != '\0') {
                    *(undefined1 *)CONCAT22(in_stack_0000000c,in_stack_0000000a) = 1;
                  }
                }
                *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 0;
              }
              *(undefined1 *)(GRecordCount * 0x12 + 0x11) = 0;
              *(undefined1 *)(GRecordCount * 0x12 + 0xb) =
                   *(undefined1 *)(GRecordCount * 0x12 + 0xc);
              iVar72 = GRecordCount;
              GRecordCount = GRecordCount + 1;
              ovc23_abandonConstruction(iVar72);
              pfVar19 = (far_t *)ovc23_textAdlibNone();
              return pfVar19;
            case (far_t *)0x12:
              GRecordCount = GRecordCount + -1;
              pfVar19 = (far_t *)ovc23_textAdlibNone();
              return pfVar19;
            case (far_t *)0x15:
              iVar72 = (uint)*(byte *)((int)&pfVar19[3].ofs + (int)ovrAuxSlot + 1) * 0x95;
              uVar51 = *(undefined2 *)((int)&worldMenuLabels[0].seg + 1 + iVar72);
              ovr_fmVsprintf((char *)CONCAT13((char)((uint)uVar51 >> 8),
                                              CONCAT12((char)uVar51,0x2410)),
                             (char *)CONCAT13(uVar67,CONCAT12(cVar25,*(undefined2 *)
                                                                      ((int)&worldMenuLabels[1].ofs
                                                                       + 1 + iVar72))));
              ovr_uiNotify();
              pfVar19 = (far_t *)((uint)((entity_t *)Entities)[(int)puStack_a].base.gindex * 0x95);
              if (((pfVar19 + 0x9c5)->ofs & 0xc00) != 0) {
                uVar22 = ovr_ovc27_rollToHitAgent();
                pfVar19 = (far_t *)(uVar22 & 0xff);
                if (pfVar19 == (far_t *)0x0) {
                  if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                                (uint)((entity_t *)Entities)[(int)puStack_a].base.gindex * 0x95) &
                      0x800) == 0) {
                    puStack_12 = (uint *)CONCAT11((*(uint8_t *)((uint8_t *)&(puStack_12) + 1)),1);
                  }
                  else {
                    puStack_12 = (uint *)CONCAT11((*(uint8_t *)((uint8_t *)&(puStack_12) + 1)),2);
                  }
                  uVar51 = ovr_ovc27_compute3();
                  if ((char)uVar51 != '\0') {
                    if (DebugVerbose != false) {
                      printf("kill 3\r");
                    }
                    uVar51 = (undefined2)((ulong)Entities >> 0x10);
                    if (((entity_t *)Entities)[(int)unaff_DI].base.animFrame != 0x0) {
                      puVar5 = &((entity_t *)Entities)[(int)unaff_DI].base.animFrame;
                      *puVar5 = *puVar5 + 0xff;
                    }
                  }
                  uVar22 = alignUp4();
                  iVar72 = (uint)((entity_t *)Entities)[(int)unaff_DI].base.gindex * 0x95;
                  uVar51 = *(undefined2 *)((int)&worldMenuLabels[0].seg + 1 + iVar72);
                  pfVar19 = (far_t *)ovr_fmVsprintf((char *)CONCAT13((char)((uint)uVar51 >> 8),
                                                                     CONCAT12((char)uVar51,0x2410)),
                                                    (char *)CONCAT13((char)(uVar22 >> 8),
                                                                     CONCAT12((char)uVar22,
                                                                              *(undefined2 *)
                                                                               ((int)&
                                                  worldMenuLabels[1].ofs + 1 + iVar72))));
                  ovr_uiNotify();
                }
              }
              return pfVar19;
            }
            do {
              ovr_blitGfxRect();
              ovr_blitGfxRect();
              ovr_blitGfxRect();
              ovr_blitGfxRect();
              ovr_blitGfxRect();
              ovr_blitGfxRect();
              pfVar19 = (far_t *)((char *)"puppetmaker" + 3);
              ovr_blitGfxRect();
              while( true ) {
                while( true ) {
                  scratch = scratch - 1;
                  if ((int)scratch < 0) {
                    return pfVar19;
                  }
                  pcVar20 = (char *)(scratch + GfxRndSeed2 + ((uint)unaff_DI >> 5));
                  puStack_a = (uint *)((int)puStack_a + 0x13);
                  if (((*(uint8_t *)((uint8_t *)&(uStack_14) + 1)) == 2) || ((byte *)__C0_ASM_CopyRight + 0xf < unaff_DI))
                  break;
                  if (((char *)((int)puStack_12 + -1) == (char *)scratch) &&
                     (unaff_DI <= (byte *)__C0_ASM_CopyRight + 8)) {
                    uStack_8 = ((undefined2 *)&csite1Ofs)[(int)unaff_DI * 2];
                    pfVar19 = (far_t *)((undefined2 *)&csite1Seg)[(int)unaff_DI * 2];
                  }
                  else {
                    uStack_8 = csite1_12Ofs;
                    pfVar19 = csite1_12Seg;
                  }
                  uStack_6 = (far_t *)CONCAT22(pcVar20,pfVar19);
                  ovr_blitGfxRect();
                }
                if ((*(uint8_t *)((uint8_t *)&(uStack_14) + 1)) < 2) break;
                if ((byte *)__C0_ASM_CopyRight + 5 < unaff_DI) {
                  uStack_8 = csite1_22Ofs;
                  pfVar19 = csite1_22Seg;
                }
                else {
                  uStack_8 = ((undefined2 *)&csite1Ofs)[(int)(unaff_DI + 6) * 2];
                  pfVar19 = (far_t *)((undefined2 *)&csite1Seg)[(int)(unaff_DI + 6) * 2];
                }
                uStack_6 = (far_t *)CONCAT22(pcVar20,pfVar19);
                ovr_blitGfxRect();
              }
              uStack_6 = (far_t *)CONCAT22(pcVar20,csite1_12Seg);
              uStack_8 = csite1_12Ofs;
              if ((char *)scratch == (char *)0x0) {
                ovr_blitGfxRect();
              }
              ovr_blitGfxRect();
              if (((uint)((char *)((int)unaff_DI + GfxRndSeed2 + scratch) + (int)puVar47) & 0x1f) <
                  0x11) {
                uVar22 = ((uint)((char *)((int)unaff_DI + GfxRndSeed2 + scratch) + (int)puVar47) >>
                         5) + scratch + GfxRndSeed2;
                uStack_6 = (far_t *)CONCAT22(uVar22,(far_t *)uStack_6);
                uStack_e = (uint *)((int)((uint)*(byte *)(uVar22 & 0xff) * 0x25) >> 8);
                ovr_blitGfxRect();
              }
              if (((uint)((int)unaff_DI + ((scratch - GfxRndSeed2) - (int)puVar47)) & 0xf) < 7) {
                iVar72 = (((uint)((int)unaff_DI + ((scratch - GfxRndSeed2) - (int)puVar47)) >> 4) +
                         scratch) - GfxRndSeed2;
                uStack_6 = (far_t *)CONCAT22(iVar72,(far_t *)uStack_6);
                uStack_e = (uint *)((int)((uint)*(byte *)(iVar72 + 0xeU & 0xff) * 0x25) >> 8);
                ovr_blitGfxRect();
              }
            } while( true );
          }
          if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\x13') {
            uVar21 = *(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x12a);
            bVar56 = CARRY2(uStack_38,uVar21);
            uStack_38 = uStack_38 + uVar21;
            iStack_36 = iStack_36 + (uint)bVar56;
          }
          else {
            uVar21 = *(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x12a);
            bVar56 = CARRY2(uStack_34,uVar21);
            uStack_34 = uStack_34 + uVar21;
            resourceTotals[0] = resourceTotals[0] + (uint)bVar56;
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
          iStack_22 = iStack_22 + (uint)*(byte *)((uStack_1a >> 8) * 0x27 + 0x127);
          if (0xf7 < (int)puVar47) {
            pcVar20 = ovc22_textPOPULATION();
            uStack_20 = uStack_20 + (int)pcVar20;
            uVar21 = ovc22_seasonalIncome();
            iVar30 = iVar30 + uVar21;
          }
          if (((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x121) & 1) != 0) &&
             (((*(char *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x2f) == -1 ||
               (bVar16 = *(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x2f),
               uVar22 = CONCAT11((char)(uVar22 >> 8),bVar16),
               (1 << (bVar16 & 0x1f) & (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x11f)) != 0))
              && (*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) < 4)))) {
            *(int *)(&stack0xffbc + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) * 2) =
                 *(int *)(&stack0xffbc + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) * 2)
                 + 1;
          }
          if ((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x121) & 0x200) != 0) {
            iVar72 = iVar72 + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131);
          }
        }
      }
    }
    for (uStack_14 = (far_t *)0x0; uStack_14 < EntityCount;
        uStack_14 = (far_t *)((int)&uStack_14->ofs + 1)) {
      uVar51 = (undefined2)((ulong)Entities >> 0x10);
      if (*(byte *)((int)&((entity_t *)Entities)[(int)uStack_14].base.entity + 3) ==
          in_stack_00000004) {
        uStack_1e = uStack_1e + ((entity_t *)Entities)[(int)uStack_14].base.animFrame;
      }
    }
    bStack_1b = *(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0xad);
    for (iVar29 = 2; -1 < iVar29; iVar29 = iVar29 + -1) {
      if (bStack_1b < *(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + iVar29 + 0xaa))
      {
        *(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + iVar29 + 0xaa) = bStack_1b;
        bStack_1b = 0;
      }
      else {
        bStack_1b = bStack_1b -
                    *(char *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + iVar29 + 0xaa);
      }
    }
    iVar29 = 0;
    for (iVar50 = 0; iVar50 < 3; iVar50 = iVar50 + 1) {
      iVar29 = iVar29 + (uint)*(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + iVar50
                                       + 0xaa) * (iVar50 + 1) * 3;
    }
    if (iVar29 < 0x32) {
      *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0xaa) = (char)iVar29;
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0xaa) = 0x32;
    }
    *(uint16_t *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x94) = scratch;
    *(undefined2 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x96) = puStack_a;
    *(uint *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x98) = uStack_8;
    if (CONCAT11(in_stack_0000ffbf,in_stack_0000ffbe) < 6) {
      iStack_24 = CONCAT11(in_stack_0000ffbf,in_stack_0000ffbe);
    }
    else {
      iStack_24 = 5;
    }
    if ((uint)(in_stack_0000ffc0 + iStack_24) < 0xb) {
      iStack_24 = iStack_24 + in_stack_0000ffc0;
    }
    else {
      iStack_24 = 10;
    }
    if (in_stack_0000ffc2 == 0) {
      if (in_stack_0000ffc0 == 0) {
        if (CONCAT11(in_stack_0000ffbf,in_stack_0000ffbe) == 0) {
          *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x53) = 4;
        }
        else {
          *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x53) = 8;
        }
      }
      else {
        *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x53) = 0xc;
      }
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x53) = 0xff;
    }
    *(undefined2 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x82) = 0;
    if ((resourceTotals[0] < 0) || (resourceTotals[0] < 1)) {
      uVar51 = (undefined2)((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
      iVar29 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
      *(int16_t *)(iVar29 + 0x80) = resourceTotals[0];
      *(uint *)(iVar29 + 0x7e) = uStack_34;
    }
    else {
      uVar51 = (undefined2)((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
      iVar29 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
      *(undefined2 *)(iVar29 + 0x80) = 0;
      *(undefined2 *)(iVar29 + 0x7e) = 0xffff;
    }
    *(int *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x5b) = iStack_22;
    *(uint *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x4d) = uStack_1e;
    *(int *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x4f) = (int)uStack_20;
    *(int *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x54) = iVar30;
    uVar51 = (undefined2)((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
    iVar30 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
    *(int *)(iVar30 + 0x8c) = iStack_36;
    *(uint *)(iVar30 + 0x8a) = uStack_38;
    *(int16_t *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 100) = animStep;
    *(undefined2 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x66) = uStack_28;
    *(undefined2 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x68) = uStack_26;
    *(int16_t *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x70) = resourceTotals[1];
    *(int16_t *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x72) = resourceTotals[2];
    *(int16_t *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x74) = resourceTotals[3];
    *(int *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x87) = iVar72;
    if ((uint)(iStack_24 + in_stack_0000ffc2) < 0x100) {
      (*(uint8_t *)((uint8_t *)&(iStack_24))) = (undefined1)(iStack_24 + in_stack_0000ffc2);
      *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x52) =
           (undefined1)iStack_24;
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x52) = 0xff;
    }
    uVar22 = ovr_ovc36_usesLDIV_at_();
    *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x84) = (char)uVar22;
    in_AX = (far_t *)ovc22_usesPlayerCount(in_stack_00000004);
  }
  return in_AX;
switchD_5000_123d_caseD_2:
  do {
    bVar16 = ((entity_t *)Entities)[(int)puVar47].base.gindex;
    uStack_6 = (far_t *)CONCAT13(bVar16,(uint3)uStack_6);
    pfVar19 = (far_t *)(uint)*(byte *)((int)(char **)GMenuStrings + (uint)bVar16 * 0x95 + 0x1f);
    if (pfVar19 == (far_t *)0x0) {
      ovr_ovc15_capitalize();
      auStackY_68[4] = 0x2322;
      auStackY_68[3] = 0x8f4e;
      pfVar19 = (far_t *)ovr_stsprintf();
      ovr_uiNotify();
    }
    ovr_ovc15_removeEntity();
    while( true ) {
      do {
        puVar47 = (uint *)((int)puVar47 + -1);
        if ((int)puVar47 < 0) {
          return pfVar19;
        }
        pfVar19 = (far_t *)((int)puVar47 * 0x37);
        uVar51 = (undefined2)((ulong)Entities >> 0x10);
      } while (((uint *)(((entity_t *)Entities + (int)puVar47)->base).x != unaff_DI) ||
              (pfVar19 = (far_t *)((entity_t *)Entities)[(int)puVar47].base.y,
              pfVar19 != _partyIndex));
      pfVar19 = (far_t *)ovc23_findClearColumn();
      uStack_6 = (far_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),pfVar19);
      if ((int)pfVar19 < 0) break;
      (((entity_t *)Entities + (int)puVar47)->base).x = (uint16_t)pfVar19;
    }
  } while( true );
switchD_5000_123d_caseD_3:
  while( true ) {
    if ((puVar36->flags & 3) == 0) {
      uVar51 = (undefined2)((ulong)GUnits >> 0x10);
      bVar16 = ((unit_t *)GUnits)[(int)unaff_DI].unitType;
      if ((bVar16 == 0xff) ||
         (uVar11 = *(undefined4 *)((uint)bVar16 << 2), *(char *)((int)uVar11 + 0x3f) == '\0')) {
        uStack_8 = 0x96;
      }
      else {
        uStack_8 = 0x5dc;
      }
      if (((unit_t *)GUnits)[(int)unaff_DI].level != 0) {
        uVar23 = ovr_randBelow();
        uVar51 = (undefined2)((ulong)GUnits >> 0x10);
        puVar37 = (unit_t *)GUnits;
        if ((int)(uVar23 & 0xff) <
            (int)(100 - (uint)*(byte *)((uint)(puVar37 + (int)unaff_DI)->bldType * 0x27 + 0x130))) {
          bVar16 = (puVar37 + (int)unaff_DI)->bldType;
          uStack_20 = (byte *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)),bVar16);
          puVar37[(int)unaff_DI].level = puVar37[(int)unaff_DI].level - 1;
          puVar37 = (unit_t *)GUnits;
          uVar51 = (undefined2)((ulong)GUnits >> 0x10);
          if (((*(uint *)((uint)bVar16 * 0x27 + 0x121) & 4) == 0) &&
             ((puVar37[(int)unaff_DI].level == 0 ||
              ((*(uint *)((uint)bVar16 * 0x27 + 0x121) & 0x200) != 0)))) {
            ovc22_usesGUnits((int)unaff_DI,
                             (uint8_t *)
                             CONCAT13((char)((uint)((int)unaff_DI * 9) >> 8),
                                      CONCAT12(puVar37[(int)unaff_DI].unitType,unaff_SS)));
          }
          else if (((((bld_inst_t *)BldInstances + bVar16)->ofs != 0 ||
                     *(int *)((int)&BldInstances[0].seg + (uint)bVar16 * 0xc) != 0) ||
                   (*(char *)((uint)bVar16 * 0x27 + 0x11e) == '\x10')) &&
                  (uVar51 = ovc22_usesGOngoingBattle2
                                      (*(byte *)&puVar37[(int)unaff_DI].x,
                                       *(byte *)&puVar37[(int)unaff_DI].y), (char)uVar51 != '\0')) {
            cStack_1c = '\x01';
          }
        }
      }
    }
L_upd_units_5087_1d7d_202C:
    unaff_DI = (uint *)((int)unaff_DI + 1);
    if (GUnitCount <= unaff_DI) break;
    uVar52 = (undefined2)((ulong)GUnits >> 0x10);
    puVar36 = (unit_t *)GUnits + (int)unaff_DI;
  }
  GGameState = 0x43;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  for (uStack_16 = (far_t *)0x0; (int)uStack_16 < (int)(uint)GLeaderCount;
      uStack_16 = (far_t *)((int)uStack_16 + 1)) {
    if (*(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3d) != '\0') {
      *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa2) = 0;
      cVar17 = *(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3f);
      if ((cVar17 == '\0') &&
         (*(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f) <
          *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d) >> 1)) {
        bVar56 = true;
      }
      else {
        bVar56 = false;
      }
      uVar22 = *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54);
      uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar72 = *(int *)(iVar72 + 0x58) + ((int)uVar22 >> 0xf) +
               (uint)CARRY2(*(uint *)(iVar72 + 0x56),uVar22);
      if ((iVar72 < 1) && (iVar72 < 0)) {
        puVar47 = (uint *)&GUnitDescriptions[3].ofs;
        while (puVar47 = (uint *)((int)puVar47 + 1), puVar47 < GUnitCount) {
          uVar51 = (undefined2)((ulong)GUnits >> 0x10);
          puVar37 = (unit_t *)GUnits;
          bVar16 = (puVar37 + (int)puVar47)->bldType;
          uStack_20 = (byte *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)),bVar16);
          if (((far_t *)(uint)puVar37[(int)puVar47].unitType == uStack_16) &&
             (*(int *)((uint)bVar16 * 0x27 + 0x123) < 0)) {
            uVar22 = *(uint *)((uint)bVar16 * 0x27 + 0x123);
            uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
            iVar72 = *(int *)(iVar72 + 0x58) + ((int)uVar22 >> 0xf) +
                     (uint)CARRY2(*(uint *)(iVar72 + 0x56),uVar22);
            if ((iVar72 < 1) && (iVar72 < 0)) {
              if ((cVar17 == '\0') && (puVar37[(int)puVar47].level != 0)) {
                uVar23 = ovr_randBelow();
                uVar51 = (undefined2)((ulong)GUnits >> 0x10);
                puVar37 = (unit_t *)GUnits;
                if (*(byte *)((uint)(puVar37 + (int)puVar47)->bldType * 0x27 + 0x130) <=
                    (byte)uVar23) {
                  if (puVar37[(int)puVar47].level != 0) {
                    puVar37[(int)puVar47].level = puVar37[(int)puVar47].level - 1;
                  }
                  puVar37 = (unit_t *)GUnits;
                  uVar51 = (undefined2)((ulong)GUnits >> 0x10);
                  if (((*(uint *)(((uint)uStack_20 & 0xff) * 0x27 + 0x121) & 4) == 0) &&
                     ((iVar72 = 0, puVar37[(int)puVar47].level == 0 ||
                      (iVar72 = ((uint)uStack_20 & 0xff) * 0x27,
                      (*(uint *)(iVar72 + 0x121) & 0x200) != 0)))) {
                    ovc22_usesGUnits((int)puVar47,
                                     (uint8_t *)
                                     CONCAT13((char)((uint)iVar72 >> 8),
                                              CONCAT12((undefined1)uStack_16,unaff_SS)));
                  }
                  else if (((((bld_inst_t *)BldInstances + ((uint)uStack_20 & 0xff))->ofs != 0 ||
                             *(int *)((int)&BldInstances[0].seg + ((uint)uStack_20 & 0xff) * 0xc) !=
                             0) || (*(char *)(((uint)uStack_20 & 0xff) * 0x27 + 0x11e) == '\x10'))
                          && (uVar51 = ovc22_usesGOngoingBattle2
                                                 (*(byte *)&puVar37[(int)puVar47].x,
                                                  *(byte *)&puVar37[(int)puVar47].y),
                             (char)uVar51 != '\0')) {
                    cStack_1c = '\x01';
                  }
                }
              }
            }
            else {
              uVar21 = *(uint *)((uint)bVar16 * 0x27 + 0x123);
              uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
              iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
              puVar3 = (uint *)(iVar72 + 0x56);
              uVar22 = *puVar3;
              *puVar3 = *puVar3 + uVar21;
              piVar4 = (int *)(iVar72 + 0x58);
              *piVar4 = *piVar4 + ((int)uVar21 >> 0xf) + (uint)CARRY2(uVar22,uVar21);
            }
          }
        }
        uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar72 + 0x58) = 0;
        *(undefined2 *)(iVar72 + 0x56) = 0;
      }
      else {
        if ((cVar17 == '\0') && (0 < *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54))) {
          puStack_10 = (uint *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54) / 10);
        }
        else {
          puStack_10 = (uint *)0x0;
        }
        bVar57 = CARRY2((uint)GPopulationLo,(uint)puStack_10);
        GPopulationLo = GPopulationLo + (int)puStack_10;
        GPopulationHi = GPopulationHi + ((int)puStack_10 >> 0xf) + (uint)bVar57;
        uVar21 = *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54) - (int)puStack_10;
        uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar72 + 0x56);
        uVar22 = *puVar3;
        *puVar3 = *puVar3 + uVar21;
        piVar4 = (int *)(iVar72 + 0x58);
        *piVar4 = *piVar4 + ((int)uVar21 >> 0xf) + (uint)CARRY2(uVar22,uVar21);
      }
      if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                    (uint)*(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3e) * 0x95) &
          0x100) == 0) {
        if (*(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f) <
            *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d)) {
          puStack_12 = (uint *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d) -
                               *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f));
          uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
          iVar72 = *(int *)(iVar29 + 0x62);
          if ((-1 < iVar72) && ((0 < iVar72 || (*(int *)(iVar29 + 0x60) != 0)))) {
            uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
            uVar22 = *(uint *)(iVar72 + 0x62);
            if ((0x7fff < uVar22) ||
               ((uStack_14 = (far_t *)puStack_12, (int)uVar22 < 1 &&
                ((uint *)*(undefined2 *)(iVar72 + 0x60) <= puStack_12)))) {
              uStack_14 = (far_t *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x60)
              ;
            }
            puStack_12 = (uint *)((int)puStack_12 - (int)uStack_14);
            uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
            piVar4 = (int *)(iVar72 + 0x60);
            puVar47 = (uint *)*piVar4;
            *piVar4 = *piVar4 - (int)uStack_14;
            piVar4 = (int *)(iVar72 + 0x62);
            *piVar4 = *piVar4 - (uint)(puVar47 < uStack_14);
          }
          if (puStack_12 != (uint *)0x0) {
            puStack_a = puStack_12;
            if ((uint *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0) <
                puStack_12) {
              puStack_a = (uint *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0);
            }
            uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
            uVar22 = *(uint *)(iVar72 + 0x58);
            if (((int)uVar22 < 1) &&
               ((0x7fff < uVar22 || ((uint *)*(undefined2 *)(iVar72 + 0x56) < puStack_a)))) {
              puStack_a = (uint *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x56);
            }
            uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
            piVar4 = (int *)(iVar72 + 0x56);
            puVar47 = (uint *)*piVar4;
            *piVar4 = *piVar4 - (int)puStack_a;
            piVar4 = (int *)(iVar72 + 0x58);
            *piVar4 = *piVar4 - (uint)(puVar47 < puStack_a);
            puStack_12 = (uint *)((int)puStack_12 - (int)puStack_a);
            *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa2) = puStack_a;
          }
          if (cVar17 == '\0') {
            for (iVar72 = 0; (puStack_12 != (uint *)0x0 && (iVar72 < (int)(uint)GLeaderCount));
                iVar72 = iVar72 + 1) {
              if ((*(char *)((int)*(undefined4 *)(iVar72 << 2) + 0x3d) != '\0') &&
                 ((*(char *)((int)*(undefined4 *)(iVar72 << 2) + 0x3f) == '\0' &&
                  (uVar51 = (undefined2)((ulong)*(undefined4 *)(iVar72 << 2) >> 0x10),
                  iVar29 = (int)*(undefined4 *)(iVar72 << 2),
                  *(int *)(iVar29 + 0x60) != 0 || *(int *)(iVar29 + 0x62) != 0)))) {
                uVar51 = (undefined2)((ulong)*(undefined4 *)(iVar72 << 2) >> 0x10);
                iVar29 = (int)*(undefined4 *)(iVar72 << 2);
                uVar22 = *(uint *)(iVar29 + 0x62);
                if ((uVar22 < 0x8000) &&
                   ((0 < (int)uVar22 || (puStack_12 < (uint *)*(undefined2 *)(iVar29 + 0x60))))) {
                  uStack_14 = (far_t *)puStack_12;
                }
                else {
                  uStack_14 = (far_t *)*(undefined2 *)((int)*(undefined4 *)(iVar72 << 2) + 0x60);
                }
                puStack_12 = (uint *)((int)puStack_12 - (int)uStack_14);
                uVar51 = (undefined2)((ulong)*(undefined4 *)(iVar72 << 2) >> 0x10);
                iVar29 = (int)*(undefined4 *)(iVar72 << 2);
                piVar4 = (int *)(iVar29 + 0x60);
                puVar47 = (uint *)*piVar4;
                *piVar4 = *piVar4 - (int)uStack_14;
                piVar4 = (int *)(iVar29 + 0x62);
                *piVar4 = *piVar4 - (uint)(puVar47 < uStack_14);
              }
            }
          }
          pfVar19 = (far_t *)0x0;
          while ((pfVar19 < EntityCount && (puStack_12 != (uint *)0x0))) {
            uVar51 = (undefined2)((ulong)Entities >> 0x10);
            peVar39 = (entity_t *)Entities;
            if (((*(char *)((int)&peVar39[(int)pfVar19].base.entity + 1) == '\0') &&
                ((far_t *)(uint)*(byte *)((int)&peVar39[(int)pfVar19].base.entity + 3) == uStack_16)
                ) && ((bVar56 || (1 < peVar39[(int)pfVar19].base.animFrame)))) {
              if (peVar39[(int)pfVar19].base.animFrame != 0x0) {
                if (DebugVerbose != false) {
                  printf("kill 3\r");
                }
                puVar5 = &((entity_t *)Entities)[(int)pfVar19].base.animFrame;
                *puVar5 = *puVar5 + 0xff;
                if (((entity_t *)Entities)[(int)pfVar19].base.animFrame == 0x0) {
                  uStack_1e = CONCAT11(1,(byte)uStack_1e);
                }
              }
              puStack_12 = (uint *)((int)puStack_12 + -1);
            }
            pfVar19 = (far_t *)((int)&pfVar19->ofs + 1);
          }
        }
        else {
          uVar21 = *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f) -
                   *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d);
          uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
          puVar3 = (uint *)(iVar72 + 0x60);
          uVar22 = *puVar3;
          *puVar3 = *puVar3 + uVar21;
          piVar4 = (int *)(iVar72 + 0x62);
          *piVar4 = *piVar4 + (uint)CARRY2(uVar22,uVar21);
        }
      }
      uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar50 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar72 = *(int *)(iVar50 + 0x62);
      uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar38 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar29 = *(int *)(iVar38 + 0x80);
      if ((iVar29 <= iVar72) &&
         ((iVar29 < iVar72 || (*(uint *)(iVar38 + 0x7e) < *(uint *)(iVar50 + 0x60))))) {
        uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
        uVar22 = *(uint *)(iVar72 + 0x60);
        uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar29 + 0x7e);
        uVar21 = (uint)(uVar22 < *puVar3);
        uVar31 = *(int *)(iVar72 + 0x62) - *(int *)(iVar29 + 0x80);
        if (((int)(uVar31 - uVar21) < 0) ||
           ((uVar31 == uVar21 &&
            (uVar22 - *puVar3 <= *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0))))) {
          puStack_a = (uint *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x60) -
                              *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7e));
        }
        else {
          puStack_a = (uint *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0);
        }
        *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa2) = -(int)puStack_a;
        uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar72 + 0x56);
        uVar22 = *puVar3;
        *puVar3 = (uint)(*puVar3 + (int)puStack_a);
        piVar4 = (int *)(iVar72 + 0x58);
        *piVar4 = *piVar4 + (uint)CARRY2(uVar22,(uint)puStack_a);
        uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
        uVar51 = *(undefined2 *)(iVar72 + 0x7e);
        uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar29 + 0x62) = *(undefined2 *)(iVar72 + 0x80);
        *(undefined2 *)(iVar29 + 0x60) = uVar51;
      }
      if ((*(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x5b) <
           *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d)) &&
         ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                    (uint)*(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3e) * 0x95) & 0x80
          ) == 0)) {
        puStack_12 = (uint *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d) -
                             *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x5b));
        pfVar19 = (far_t *)0x0;
        while ((pfVar19 < EntityCount && (puStack_12 != (uint *)0x0))) {
          uVar51 = (undefined2)((ulong)Entities >> 0x10);
          peVar39 = (entity_t *)Entities;
          if ((((far_t *)(uint)*(byte *)((int)&peVar39[(int)pfVar19].base.entity + 3) == uStack_16)
              && (((*(char *)((int)&peVar39[(int)pfVar19].base.entity + 1) == '\0' &&
                   (peVar39[(int)pfVar19].base.destX == 0)) &&
                  (peVar39[(int)pfVar19].base.destY == 0)))) &&
             (3 < peVar39[(int)pfVar19].base.animFrame)) {
            if (DebugVerbose != false) {
              printf("kill 2 \r");
            }
            puVar5 = &((entity_t *)Entities)[(int)pfVar19].base.animFrame;
            *puVar5 = *puVar5 + 0xff;
            puStack_12 = (uint *)((int)puStack_12 + -1);
          }
          pfVar19 = (far_t *)((int)&pfVar19->ofs + 1);
        }
      }
      ovr_ovc25_tickCountdown();
      _fmemset((void *)(ulong)*(uint *)((int)uStack_16 * 4 + 2),6,CONCAT11(uVar67,cVar25));
      _fmemset((void *)(ulong)*(uint *)((int)uStack_16 * 4 + 2),6,CONCAT11(uVar67,cVar25));
      uVar23 = ovr_randBelow();
      if ((byte)uVar23 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6c) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 100);
      }
      else {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6a) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 100);
      }
      uVar23 = ovr_randBelow();
      if ((byte)uVar23 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6e) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x66);
      }
      else {
        piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6c);
        *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x66);
      }
      piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6e);
      *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x68);
      uVar23 = ovr_randBelow();
      if ((byte)uVar23 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x78) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x70);
      }
      else {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x76) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x70);
      }
      uVar23 = ovr_randBelow();
      if ((byte)uVar23 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7a) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x72);
      }
      else {
        piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x78);
        *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x72);
      }
      uVar23 = ovr_randBelow();
      if ((byte)uVar23 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7c) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x74);
      }
      else {
        piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7a);
        *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x74);
      }
      *(undefined1 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa7) =
           *(undefined1 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa6);
      if (*(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3f) != '\0') {
        uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
        iVar72 = *(int *)(iVar29 + 0x58);
        if ((iVar72 < 1) && ((iVar72 != 0 || (*(int *)(iVar29 + 0x56) == 0)))) {
          uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
          *(undefined2 *)(iVar72 + 0x58) = 0;
          *(undefined2 *)(iVar72 + 0x56) = 0x32;
        }
      }
      if (*(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xaa) != '\0') {
        bVar16 = *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xaa);
        uStack_6 = (far_t *)(ulong)CONCAT12(bVar16,(far_t *)uStack_6);
        pfVar13 = uStack_6;
        for (uVar22 = 0; uStack_6 = pfVar13, (int)uVar22 < (int)(uint)GLeaderCount;
            uVar22 = uVar22 + 1) {
          uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar50 = (int)*(undefined4 *)((int)uStack_16 << 2);
          iVar72 = *(int *)(iVar50 + 0x58);
          uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar38 = (int)*(undefined4 *)((int)uStack_16 << 2);
          iVar29 = *(int *)(iVar38 + 0x8c);
          if ((iVar29 <= iVar72) &&
             ((iVar72 != iVar29 || (*(uint *)(iVar38 + 0x8a) <= *(uint *)(iVar50 + 0x56))))) break;
          if ((*(char *)((int)*(undefined4 *)(uVar22 << 2) + 0x3d) != '\0') &&
             (((0 < *(int *)((int)*(undefined4 *)(uVar22 << 2) + 0x54) &&
               (*(char *)((int)*(undefined4 *)(uVar22 << 2) + 0x3f) == '\0')) &&
              ((far_t *)uVar22 != uStack_16)))) {
            (*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) = (uint)bVar16;
            resourceTotals[2] =
                 (int16_t)(((long)*(int *)((int)*(undefined4 *)(uVar22 << 2) + 0x54) *
                            (long)(int)(*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) & 0xffffU) / 100);
            resourceTotals[3] = 0;
            uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
            uVar21 = *(uint *)(iVar72 + 0x8a);
            uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
            puVar3 = (uint *)(iVar29 + 0x56);
            iVar72 = (*(int *)(iVar72 + 0x8c) - *(int *)(iVar29 + 0x58)) - (uint)(uVar21 < *puVar3);
            if ((iVar72 < 1) && ((iVar72 < 0 || (uVar21 - *puVar3 < (uint)resourceTotals[2])))) {
              uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
              iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
              uVar21 = *(uint *)(iVar72 + 0x8a);
              uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
              iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
              puVar3 = (uint *)(iVar29 + 0x56);
              resourceTotals[2] = uVar21 - *puVar3;
              resourceTotals[3] =
                   (*(int *)(iVar72 + 0x8c) - *(int *)(iVar29 + 0x58)) - (uint)(uVar21 < *puVar3);
            }
            uVar51 = (undefined2)((ulong)*(undefined4 *)(uVar22 << 2) >> 0x10);
            iVar29 = (int)*(undefined4 *)(uVar22 << 2);
            iVar72 = *(int *)(iVar29 + 0x58);
            if ((iVar72 <= resourceTotals[3]) &&
               ((iVar72 < resourceTotals[3] || (*(uint *)(iVar29 + 0x56) < (uint)resourceTotals[2]))
               )) {
              uVar51 = (undefined2)((ulong)*(undefined4 *)(uVar22 << 2) >> 0x10);
              iVar72 = (int)*(undefined4 *)(uVar22 << 2);
              resourceTotals[3] = *(int16_t *)(iVar72 + 0x58);
              resourceTotals[2] = *(int16_t *)(iVar72 + 0x56);
            }
            uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
            puVar3 = (uint *)(iVar72 + 0x56);
            uVar21 = *puVar3;
            *puVar3 = *puVar3 + resourceTotals[2];
            piVar4 = (int *)(iVar72 + 0x58);
            *piVar4 = *piVar4 + resourceTotals[3] + (uint)CARRY2(uVar21,resourceTotals[2]);
            uVar51 = (undefined2)((ulong)*(undefined4 *)(uVar22 << 2) >> 0x10);
            iVar72 = (int)*(undefined4 *)(uVar22 << 2);
            puVar3 = (uint *)(iVar72 + 0x56);
            uVar21 = *puVar3;
            *puVar3 = *puVar3 - resourceTotals[2];
            piVar4 = (int *)(iVar72 + 0x58);
            *piVar4 = (*piVar4 - resourceTotals[3]) - (uint)(uVar21 < (uint)resourceTotals[2]);
          }
        }
      }
      iVar72 = *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x58);
      if ((iVar72 < 1) && (iVar72 < 0)) {
        uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar72 + 0x58) = 0;
        *(undefined2 *)(iVar72 + 0x56) = 0;
      }
      uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar50 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar72 = *(int *)(iVar50 + 0x58);
      uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar38 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar29 = *(int *)(iVar38 + 0x8c);
      if ((iVar29 <= iVar72) &&
         ((iVar29 < iVar72 || (*(uint *)(iVar38 + 0x8a) < *(uint *)(iVar50 + 0x56))))) {
        uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar72 = (int)*(undefined4 *)((int)uStack_16 << 2);
        uVar51 = *(undefined2 *)(iVar72 + 0x8a);
        uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar29 + 0x58) = *(undefined2 *)(iVar72 + 0x8c);
        *(undefined2 *)(iVar29 + 0x56) = uVar51;
      }
    }
  }
  GGameState = 0x40;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  puVar47 = (uint *)&GUnitDescriptions[3].ofs;
  while (puVar47 = (uint *)((int)puVar47 + 1), puVar47 < GUnitCount) {
    uVar51 = (undefined2)((ulong)GUnits >> 0x10);
    puVar37 = (unit_t *)GUnits;
    if ((*(uint *)((uint)(puVar37 + (int)puVar47)->bldType * 0x27 + 0x121) & 0x40) != 0) {
      if (puVar37[(int)puVar47].timer != 0) {
        puVar37[(int)puVar47].timer = puVar37[(int)puVar47].timer - 1;
      }
      uVar51 = (undefined2)((ulong)GUnits >> 0x10);
      if (((unit_t *)GUnits)[(int)puVar47].timer == 0) {
        uVar11 = *(undefined4 *)((uint)((unit_t *)GUnits)[(int)puVar47].unitType << 2);
        if (*(char *)((int)uVar11 + 0x3f) == '\0') {
          ovr_play_sfx();
          sVar7 = ((unit_t *)GUnits)[(int)puVar47].y;
          uVar18 = (undefined1)sVar7;
          uVar65 = (undefined1)((uint)sVar7 >> 8);
          uVar22 = ovr_alignUp4();
          ovr_fmVsprintf((char *)CONCAT13((char)(uVar22 >> 8),CONCAT12((char)uVar22,0x2410)),
                         (char *)CONCAT13(uVar67,CONCAT12(cVar25,CONCAT11(uVar65,uVar18))));
          ovr_say();
          ovr_inputUpdate();
        }
        ovc22_usesGUnits((int)puVar47,
                         (uint8_t *)
                         CONCAT13((char)((uint)((int)puVar47 * 9) >> 8),
                                  CONCAT12(((unit_t *)GUnits)[(int)puVar47].unitType,unaff_SS)));
      }
    }
  }
  GGameState = 0x42;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_driver_clearMapFlagsRect();
  for (uStack_16 = (far_t *)0x0; uStack_16 < SquareRecCount;
      uStack_16 = (far_t *)((int)uStack_16 + 1)) {
    puVar3 = (uint *)((*(short (*) [60] [148])GMapFlags)[*(int *)((int)uStack_16 * 0x13 + 2)] +
                     *(int *)((int)uStack_16 * 0x13));
    *puVar3 = *puVar3 | 8;
  }
  if (EntityCount <= EntityScanPos) {
    EntityScanPos = (uint16_t)(0x0);
    for (uStack_16 = (far_t *)0x0; (int)uStack_16 < (int)(uint)GLeaderCount;
        uStack_16 = (far_t *)((int)uStack_16 + 1)) {
      if (*(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3d) != '\0') {
        iVar72 = ((int *)((int)uStack_16 * 4))[1];
        iVar29 = ((int *)((int)uStack_16 * 4))[1];
        memcpy((char *)CONCAT13((char)((uint)iVar29 >> 8),
                                CONCAT12((char)iVar29,*(int *)((int)uStack_16 * 4) + 0x8e)),
               (char *)CONCAT13((char)((uint)iVar72 >> 8),
                                CONCAT12((char)iVar72,*(int *)((int)uStack_16 * 4) + 0x94)),3);
      }
    }
  }
  uStack_e = (uint *)0x0;
  bVar16 = ovr_manage_findFirstLeader();
  (*(uint16_t *)((uint8_t *)&(uStack_6))) = (far_t *)CONCAT11(bVar16,(byte)uStack_6);
  if ((bVar16 == 0xff) || (GCanPromote == '\0')) {
    scratch = 0;
  }
  else if (*(byte *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x86) < 5) {
    scratch = 0x28;
  }
  else {
    scratch = (uint)*(byte *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x86) * 4 + 0x14;
  }
  for (uStack_16 = EntityScanPos; uStack_16 < EntityCount;
      uStack_16 = (far_t *)((int)&uStack_16->ofs + 1)) {
    uVar51 = (undefined2)((ulong)Entities >> 0x10);
    peVar39 = (entity_t *)Entities;
    if (((*(char *)((int)&peVar39[(int)uStack_16].base.entity + 1) == '\0') &&
        (peVar39[(int)uStack_16].base.destX == 0)) && (peVar39[(int)uStack_16].base.destY == 0)) {
      bVar16 = peVar39[(int)uStack_16].base.gindex;
      uStack_6 = (far_t *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),bVar16);
      bVar15 = *(byte *)((int)&peVar39[(int)uStack_16].base.entity + 3);
      bVar54 = false;
      bVar57 = false;
      bVar56 = false;
      if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar16 * 0x95) == -1) {
        bVar54 = false;
        bVar57 = true;
      }
      else {
        bStack_1b = *(byte *)((int)*(undefined4 *)((uint)bVar15 << 2) + 0x89);
        if (bStack_1b < 5) {
          uStack_1a = peVar39[(int)uStack_16].base.y;
          uStack_18 = ovr_alignUp4();
          uVar23 = 0x2410;
          if (((*(short (*) [60] [148])GMapFlags)[uStack_1a][uStack_18] & 8U) == 0) {
            uStack_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)),0x22);
            uStack_20 = (byte *)((char *)"stronghold" + 6);
          }
          else {
            puVar49 = &uStack_1e;
            iVar72 = (int)&uStack_20 + 1;
            puVar61 = &uStack_20;
            index = CONCAT11((char)((uint)puVar61 >> 8),bStack_1b);
            auStackY_68[4] = 0x2379;
            auStackY_68[3] = 0x3d98;
            uVar18 = uVar70;
            uVar65 = uVar71;
            uVar62 = uVar70;
            uVar63 = uVar71;
            uVar64 = uVar70;
            uVar66 = uVar71;
            uVar24 = ovr_attact_usesSquareRecCount();
            auStackY_68[4] = 0x2315;
            auStackY_68[3] = 0x3da2;
            table.seg = uVar23;
            table.ofs = uVar24;
            (*(uint8_t *)((uint8_t *)&(pctOut.seg))) = uVar18;
            pctOut.ofs = (uint16_t)puVar61;
            (*(uint8_t *)((uint8_t *)&(pctOut.seg) + 1)) = uVar65;
            (*(uint8_t *)((uint8_t *)&(remainderOut.seg))) = uVar62;
            remainderOut.ofs = iVar72;
            (*(uint8_t *)((uint8_t *)&(remainderOut.seg) + 1)) = uVar63;
            (*(uint8_t *)((uint8_t *)&(partOut.seg))) = uVar64;
            partOut.ofs = (uint16_t)puVar49;
            (*(uint8_t *)((uint8_t *)&(partOut.seg) + 1)) = uVar66;
            ovr_attact_compute3(table,index,pctOut,remainderOut,partOut);
          }
        }
        else {
          uStack_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)),0x22);
          uStack_20 = (byte *)((char *)"stronghold" + 6);
        }
        uVar23 = ovr_randBelow();
        if ((byte)uVar23 < (byte)uStack_1e) {
          bVar54 = false;
          bVar57 = true;
        }
        else if ((uVar23 & 0xff) < ((uint)uStack_20 >> 8) + (uStack_1e & 0xff)) {
          bVar54 = true;
          bVar57 = false;
        }
        else {
          bVar56 = true;
        }
      }
      if ((bVar56) && (cVar17 = ovr_ovc23_tickRecordsAt(), cVar17 == '\0')) {
        if (((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)) == '\0') && ((byte)uStack_1e == '\0')) {
          uVar23 = ovr_randBelow();
          if ((uVar23 & 0xff) == 0) {
            bVar57 = true;
          }
          else {
            bVar54 = true;
          }
        }
        else {
          uVar23 = ovr_randBelow();
          if ((byte)uVar23 < (byte)uStack_1e) {
            bVar57 = true;
          }
          else {
            bVar54 = true;
          }
        }
      }
      if ((bVar57) && (uVar22 = ovc22_usesEntities((int)uStack_16), (uVar22 & 0xff) == 0)) {
        bVar54 = true;
      }
      if (bVar54) {
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)uStack_6 * 0x95) != -1) &&
           (bVar15 != 0xff)) {
          if ((*(char *)((int)*(undefined4 *)((uint)bVar15 << 2) + 0x3f) != '\0') ||
             (((entity_t *)Entities)[(int)uStack_16].base.level <
              *(byte *)((int)*(undefined4 *)((uint)bVar15 << 2) + 0x53))) {
            uVar18 = (undefined1)scratch;
            uVar65 = (undefined1)(scratch >> 8);
            ovc22_usesLUDIV_at_((entity_t *)
                                CONCAT13((char)((ulong)Entities >> 0x18),
                                         CONCAT12((char)((ulong)Entities >> 0x10),
                                                  (entity_t *)Entities + (int)uStack_16)));
            LXMUL_at_((long *)CONCAT11(uVar67,cVar25),
                      CONCAT13(in_stack_0000ffb9,CONCAT12(in_stack_0000ffb8,CONCAT11(uVar69,uVar68))
                              ),CONCAT13(in_stack_0000ffbd,CONCAT12(in_stack_0000ffbc,iVar30)));
            peVar39 = (entity_t *)Entities + (int)uStack_16;
            uVar23 = ovr_ovc15_textError();
            uVar21 = ovc22_usesLUDIV_at_2(uVar23,(uint16_t)peVar39,CONCAT11(uVar65,uVar18));
            uVar51 = (undefined2)((ulong)Entities >> 0x10);
            peVar40 = (entity_t *)Entities;
            uVar22 = *(uint *)&peVar40[(int)uStack_16].base.health;
            *(uint *)&peVar40[(int)uStack_16].base.frameIndex =
                 (int)&(peVar39->base).x +
                 (uint)CARRY2(uVar22,uVar21) + *(int *)&peVar40[(int)uStack_16].base.frameIndex;
            *(uint *)&peVar40[(int)uStack_16].base.health = uVar22 + uVar21;
            ovr_ovc41_compute3();
          }
        }
        ovc22_usesEntities2((int)uStack_16);
        ovc22_usesEntities3((int)uStack_16);
        ovc22_usesEntities4((int)uStack_16);
      }
      animStep = (uint)((entity_t *)Entities)[(int)uStack_16].base.animFrame -
                 (uint)*(byte *)((int)*(undefined4 *)((uint)bVar15 << 2) + 0xa4);
      if (0 < animStep) {
        if (3 < animStep) {
          animStep = 3;
        }
        if (animStep == 3) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar15 << 2) + 0x92) == 0) {
            animStep = 2;
          }
          else {
            piVar4 = (int *)((int)*(undefined4 *)((uint)bVar15 << 2) + 0x92);
            *piVar4 = *piVar4 + -1;
          }
        }
        if (animStep == 2) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar15 << 2) + 0x90) == 0) {
            animStep = 1;
          }
          else {
            piVar4 = (int *)((int)*(undefined4 *)((uint)bVar15 << 2) + 0x90);
            *piVar4 = *piVar4 + -1;
          }
        }
        if (animStep == 1) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar15 << 2) + 0x8e) == 0) {
            animStep = 0;
          }
          else {
            piVar4 = (int *)((int)*(undefined4 *)((uint)bVar15 << 2) + 0x8e);
            *piVar4 = *piVar4 + -1;
          }
        }
        ((entity_t *)Entities)[(int)uStack_16].base.animFrame =
             *(char *)((int)*(undefined4 *)((uint)bVar15 << 2) + 0xa4) + (char)animStep;
      }
      uStack_e = (uint *)((int)uStack_e + 1);
      if (199 < (int)uStack_e) break;
    }
  }
  EntityScanPos = uStack_16;
  mapDirty = 1;
  ovr_unit_usesAlignUp4();
  GGameState = 0x44;
  pfVar19 = (far_t *)((char *)"puppetmaker" + 3);
  if (DebugVerbose != false) {
    pfVar19 = (far_t *)((char *)"puppetmaker" + 3);
    printf("%d \r");
  }
  if ((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)) != '\0') {
    pfVar19 = (far_t *)((int)&EntityCount[-1].seg + 1);
    for (uStack_16 = pfVar19; -1 < (int)uStack_16;
        uStack_16 = (far_t *)((int)&uStack_16[-1].seg + 1)) {
      uVar51 = (undefined2)((ulong)Entities >> 0x10);
      pfVar19 = (far_t *)(uint)((entity_t *)Entities)[(int)uStack_16].base.animFrame;
      if (pfVar19 == (far_t *)0x0) {
        pfVar19 = (far_t *)(uint)*(byte *)((int)(char **)GMenuStrings +
                                          (uint)((entity_t *)Entities)[(int)uStack_16].base.gindex *
                                          0x95 + 0x1f);
        if (pfVar19 == (far_t *)0x0) {
          uVar22 = ovr_alignUp4();
          iVar72 = (uint)((entity_t *)Entities)[(int)uStack_16].base.gindex * 0x95;
          uVar51 = *(undefined2 *)((int)&worldMenuLabels[0].seg + 1 + iVar72);
          pfVar19 = (far_t *)ovr_fmVsprintf((char *)CONCAT13((char)((uint)uVar51 >> 8),
                                                             CONCAT12((char)uVar51,0x2410)),
                                            (char *)CONCAT13((char)(uVar22 >> 8),
                                                             CONCAT12((char)uVar22,
                                                                      *(undefined2 *)
                                                                       ((int)&worldMenuLabels[1].ofs
                                                                        + 1 + iVar72))));
          ovr_uiNotify();
        }
        ovr_ovc15_removeEntity();
      }
    }
  }
  if (cStack_1c != '\0') {
    ovr_constr_flushDirtyRects();
  }
  return pfVar19;
}



/* 5087:1470 */

/* [R6] touches PlayerCount */

undefined2 __cdecl16far ovc22_usesPlayerCount(byte partyIndex)

{
  undefined4 uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  undefined2 uVar5;
  
  if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3f) == '\0') {
    cVar3 = (char)((ulong)*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x45) / 10);
    bVar2 = cVar3 + 2;
    uVar5 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
    iVar4 = (int)*(undefined4 *)((uint)partyIndex << 2);
    if ((uint)(*(int *)(iVar4 + 0x4d) * 2 + *(int *)(iVar4 + 0x4d)) >> 1 <=
        *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4f)) {
      bVar2 = cVar3 + 4;
    }
  }
  else {
    bVar2 = PlayerCount / 2 + 1;
  }
  if (10 < bVar2) {
    bVar2 = 10;
  }
  uVar1 = *(undefined4 *)((uint)partyIndex << 2);
  *(byte *)((int)uVar1 + 0xa4) = bVar2;
  return CONCAT11((char)(((uint)partyIndex << 2) >> 8),bVar2);
}



/* 5087:1532 */

/* [R6] touches Entities, animFrame */

uint __cdecl16far ovc22_usesEntities(int entityIndex)

{
  uint8_t *puVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  entity_t *peVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)Entities >> 0x10);
  peVar5 = (entity_t *)Entities;
  bVar2 = *(byte *)((int)&peVar5[entityIndex].base.entity + 3);
  if (bVar2 == 0xff) {
    uVar3 = entityIndex * 0x37 & 0xff00;
  }
  else {
    uVar3 = (uint)peVar5[entityIndex].base.gindex * 0x95;
    if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + uVar3) & 0x800) == 0) {
      if ((*(char *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0x3f) == '\0') &&
         (uVar3 = *(uint *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0x5b),
         uVar3 < *(uint *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0x4d))) {
        uVar3 = uVar3 & 0xff00;
      }
      else {
        bVar4 = 3;
        while ((bVar4 != 0 &&
               (*(int *)((int)*(undefined4 *)((uint)bVar2 << 2) + (uint)bVar4 * 2 + 0x8c) == 0))) {
          bVar4 = bVar4 - 1;
        }
        if (peVar5[entityIndex].base.animFrame <
            (byte)(*(char *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0xa4) + bVar4)) {
          puVar1 = &peVar5[entityIndex].base.animFrame;
          *puVar1 = *puVar1 + 0x1;
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
  undefined2 uVar2;
  int iVar3;
  unit_t *puVar4;
  char unaff_SI;
  byte unaff_DI;
  uint uVar5;
  undefined2 uVar6;
  undefined1 *in_stack_00000006;
  
  uVar5 = 0;
  while( true ) {
    puVar4 = (unit_t *)GUnits;
    uVar2 = (undefined2)((ulong)GUnits >> 0x10);
    if (GRecordCount <= uVar5) {
      bVar1 = (puVar4 + unitIndex)->bldType;
      if ((*(uint *)((uint)bVar1 * 0x27 + 0x121) & 4) == 0) {
        uVar2 = ovc22_usesGOngoingBattle
                          (*(byte *)&puVar4[unitIndex].y,unaff_DI,
                           CONCAT11((char)((uint)(unitIndex * 9) >> 8),(char)puVar4[unitIndex].x),
                           CONCAT11((char)((uint)(unitIndex * 9) >> 8),*(byte *)&puVar4[unitIndex].y
                                   ));
        if ((char)uVar2 != '\0') {
          *(undefined1 *)CONCAT22((uint8_t *)outFlag,in_stack_00000006) = 1;
        }
        uVar6 = (undefined2)((ulong)GUnits >> 0x10);
        ovr_createConstructionRecordFar
                  ((byte)((unit_t *)GUnits)[unitIndex].x,((unit_t *)GUnits)[unitIndex].y,
                   (int)in_stack_00000006,
                   (uint8_t *)
                   CONCAT22(CONCAT11((char)((uint)uVar2 >> 8),(*(uint8_t *)((uint8_t *)&(outFlag) + 2))),(uint8_t *)outFlag),
                   unaff_DI,unaff_SI,0);
        if (1 < *(byte *)((uint)bVar1 * 0x27 + 0x11b)) {
          uVar2 = (undefined2)((ulong)GUnits >> 0x10);
          ovr_createConstructionRecordFar
                    ((char)((unit_t *)GUnits)[unitIndex].x + 1,((unit_t *)GUnits)[unitIndex].y,
                     (int)in_stack_00000006,
                     (uint8_t *)
                     CONCAT22(CONCAT11((char)((uint)bVar1 * 0x27 >> 8),(*(uint8_t *)((uint8_t *)&(outFlag) + 2))),
                              (uint8_t *)outFlag),unaff_DI,unaff_SI,0);
          if (3 < *(byte *)((uint)bVar1 * 0x27 + 0x11b)) {
            uVar2 = (undefined2)((ulong)GUnits >> 0x10);
            iVar3 = ((unit_t *)GUnits)[unitIndex].x + 2;
            ovr_createConstructionRecordFar
                      ((byte)iVar3,((unit_t *)GUnits)[unitIndex].y,(int)in_stack_00000006,
                       (uint8_t *)
                       CONCAT22(CONCAT11((char)((uint)bVar1 * 0x27 >> 8),(*(uint8_t *)((uint8_t *)&(outFlag) + 2))),
                                (uint8_t *)outFlag),unaff_DI,unaff_SI,0);
            uVar2 = (undefined2)((ulong)GUnits >> 0x10);
            ovr_createConstructionRecordFar
                      ((char)((unit_t *)GUnits)[unitIndex].x + 3,((unit_t *)GUnits)[unitIndex].y,
                       (int)in_stack_00000006,
                       (uint8_t *)
                       CONCAT22(CONCAT11((char)((uint)iVar3 >> 8),(*(uint8_t *)((uint8_t *)&(outFlag) + 2))),(uint8_t *)outFlag)
                       ,unaff_DI,unaff_SI,0);
          }
        }
      }
      return;
    }
    if ((*(int *)(uVar5 * 0x12 + 2) == puVar4[unitIndex].x) &&
       (*(int *)(uVar5 * 0x12 + 4) == puVar4[unitIndex].y)) break;
    uVar5 = uVar5 + 1;
  }
  return;
}



/* 5087:18b6 */

/* [R4] calls LUDIV_at_ */

void __cdecl16far ovc22_usesLUDIV_at_(entity_t *entity)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  entity_t *peVar5;
  undefined2 uVar6;
  byte bStack_3;
  
  uVar6 = (undefined2)((ulong)entity >> 0x10);
  peVar5 = (entity_t *)entity;
  uVar2 = (uint)*(byte *)((int)&(peVar5->base).entity + 3);
  uVar1 = *(undefined4 *)(uVar2 << 2);
  uVar3 = *(byte *)((int)uVar1 + 0x52) + 1;
  if ((peVar5->base).level < uVar3) {
    uVar3 = (uint)(peVar5->base).level;
  }
  if (0x24 < uVar3) {
    uVar3 = 0x24;
  }
  uVar1 = *(undefined4 *)(uVar2 << 2);
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

char __cdecl16far ovc22_compute3(char direction,...)

{
  char in_stack_00000004;
  
  if (in_stack_00000004 < '\0') {
    in_stack_00000004 = in_stack_00000004 + '\x06';
  }
  return in_stack_00000004;
}



/* 5087:1991 */

/* [R6] touches Entities */

void __cdecl16far ovc22_usesEntities2(int entityIndex)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  byte bVar4;
  char direction;
  char cVar5;
  undefined2 unaff_SI;
  agnt_t *paVar6;
  undefined2 uVar7;
  char cStack_5;
  
  paVar6 = (agnt_t *)((ulong)Entities >> 0x10);
  if (*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3) != -1) {
    bVar4 = ovr_agnt_compute8((agnt_t *)CONCAT22(unaff_SI,paVar6),(entity_t *)Entities + entityIndex
                             );
    bVar2 = *(byte *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3);
    for (cStack_5 = '\0'; cStack_5 < '\x03'; cStack_5 = cStack_5 + '\x01') {
      uVar3 = *(undefined4 *)((uint)bVar2 << 2);
      if ((*(int *)((int)uVar3 + cStack_5 * 2 + 0x6a) != 0) && ((char)bVar4 < cStack_5)) {
        uVar3 = *(undefined4 *)((uint)bVar2 << 2);
        piVar1 = (int *)((int)uVar3 + cStack_5 * 2 + 0x6a);
        *piVar1 = *piVar1 + -1;
        uVar7 = (undefined2)((ulong)Entities >> 0x10);
        direction = ((entity_t *)Entities)[entityIndex].dir -
                    ((entity_t *)Entities)[entityIndex].dir % 6;
        cVar5 = ovc22_compute3(direction,CONCAT11((char)((uint)(entityIndex * 0x37) >> 8),cStack_5))
        ;
        ((entity_t *)Entities)[entityIndex].dir = direction + cVar5;
        return;
      }
    }
  }
  return;
}



/* 5087:1ac1 */

/* [R6] touches Entities */

void __cdecl16far ovc22_usesEntities3(int entityIndex)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  entity_t *peVar7;
  undefined2 unaff_SI;
  agnt_t *paVar8;
  undefined2 uVar9;
  agnt_t *agnt;
  agnt_t *paVar10;
  char cStack_7;
  char cStack_6;
  
  paVar8 = (agnt_t *)((ulong)Entities >> 0x10);
  if (*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3) != -1) {
    agnt = (agnt_t *)CONCAT22(unaff_SI,paVar8);
    bVar4 = ovr_agnt_compute10(agnt,(entity_t *)Entities + entityIndex);
    bVar2 = *(byte *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3);
    for (cStack_6 = '\0'; cStack_6 < '\x04'; cStack_6 = cStack_6 + '\x01') {
      uVar3 = *(undefined4 *)((uint)bVar2 << 2);
      paVar10 = agnt;
      if ((*(int *)((int)uVar3 + cStack_6 * 2 + 0x76) != 0) &&
         (paVar10 = (agnt_t *)CONCAT22((int)((ulong)agnt >> 0x10),(agnt_t *)(cStack_6 + 1)),
         (int)(char)bVar4 < cStack_6 + 1)) {
        cStack_7 = cStack_6;
        uVar3 = *(undefined4 *)((uint)bVar2 << 2);
        piVar1 = (int *)((int)uVar3 + cStack_6 * 2 + 0x76);
        *piVar1 = *piVar1 + -1;
        uVar9 = (undefined2)((ulong)Entities >> 0x10);
        peVar7 = (entity_t *)Entities;
        peVar7[entityIndex].dir =
             peVar7[entityIndex].dir + (char)(((ulong)peVar7[entityIndex].dir / 6) % 6) * -6;
        bVar2 = ((entity_t *)Entities)[entityIndex].base.gindex;
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar2 * 0x95) == '\x03') &&
           ('\x01' < cStack_6)) {
          cStack_7 = '\x01';
        }
        iVar6 = (uint)bVar2 * 0x95;
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + iVar6) == '\x01') && ('\x02' < cStack_7))
        {
          cStack_7 = '\x02';
        }
        cVar5 = ovc22_compute3((char)((ulong)agnt >> 0x10),
                               CONCAT11((char)((uint)iVar6 >> 8),cStack_7 + '\x01'));
        uVar9 = (undefined2)((ulong)Entities >> 0x10);
        ((entity_t *)Entities)[entityIndex].dir =
             ((entity_t *)Entities)[entityIndex].dir + cVar5 * '\x06';
        return;
      }
      agnt = paVar10;
    }
  }
  return;
}



/* 5087:1ca4 */

/* [R6] touches Entities */

void __cdecl16far ovc22_usesEntities4(int entityIndex)

{
  char *pcVar1;
  uint *puVar2;
  byte bVar3;
  undefined4 uVar4;
  entity_t *peVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)Entities >> 0x10);
  peVar5 = (entity_t *)Entities;
  if (((*(char *)((int)&peVar5[entityIndex].base.entity + 3) != -1) &&
      ((*(uint *)((int)&peVar5[entityIndex].base.frames + 1) & 2) == 0)) &&
     (bVar3 = *(byte *)((int)&peVar5[entityIndex].base.entity + 3),
     uVar4 = *(undefined4 *)((uint)bVar3 << 2), *(char *)((int)uVar4 + 0xa7) != '\0')) {
    uVar4 = *(undefined4 *)((uint)bVar3 << 2);
    pcVar1 = (char *)((int)uVar4 + 0xa7);
    *pcVar1 = *pcVar1 + -1;
    puVar2 = (uint *)((int)&((entity_t *)Entities)[entityIndex].base.frames + 1);
    *puVar2 = *puVar2 | 2;
  }
  return;
}



/* 5087:1d4a */

/* [R4] calls LUDIV_at_ */

uint16_t __cdecl16far ovc22_usesLUDIV_at_2(uint16_t valueLo,uint16_t valueHi,int applyPercent)

{
  long *dividendLo;
  undefined2 unaff_BP;
  undefined2 unaff_SI;
  undefined4 uVar1;
  long in_stack_00000000;
  uint divisorLo;
  uint divisorHi;
  
  if (applyPercent != 0) {
    divisorHi = 0;
    divisorLo = 100;
    dividendLo = LXMUL_at_((long *)0x0,CONCAT22(unaff_BP,unaff_SI),in_stack_00000000);
    uVar1 = LUDIV_at_((int)dividendLo,valueHi,divisorLo,divisorHi);
    valueLo = (uint16_t)uVar1;
  }
  return valueLo;
}



/* 5087:1d7d */

/* [R4] calls ovr_alignUp4 */

void __cdecl16far upd_usesAlignUp4(void...)

{
  byte *pbVar1;
  uint *puVar2;
  int *piVar3;
  uint8_t *puVar4;
  byte bVar5;
  undefined4 uVar6;
  far_t pctOut;
  far_t remainderOut;
  far_t partOut;
  bool bVar7;
  bool bVar8;
  ulong uVar9;
  char cVar10;
  uint16_t uVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  uint16_t index;
  uint16_t uVar15;
  uint16_t uVar16;
  long *plVar17;
  unit_t *puVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  entity_t *peVar22;
  int iVar23;
  entity_t *peVar24;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  uint uVar25;
  undefined2 uVar26;
  undefined2 uVar27;
  undefined2 uVar28;
  uint16_t unaff_SS;
  bool bVar29;
  far_t table;
  uint8_t *puVar30;
  uint8_t *puVar31;
  uint16_t uVar32;
  uint8_t *puVar33;
  undefined1 uVar34;
  undefined1 uVar35;
  undefined1 uVar36;
  byte partyIndex;
  undefined1 uVar37;
  undefined4 in_stack_0000ffd0;
  long a;
  ulong in_stack_0000ffd4;
  uint8_t bldType;
  uint8_t partialWeight;
  uint8_t successWeight;
  char cStack_1d;
  uint8_t found;
  byte bStack_1b;
  uint16_t uStack_1a;
  uint uStack_18;
  uint uStack_16;
  uint uStack_14;
  uint uStack_12;
  uint uStack_10;
  int iStack_e;
  int iStack_c;
  uint uStack_a;
  undefined2 uStack_8;
  byte bStack_6;
  byte bStack_5;
  uint uStack_4;
  
  a = CONCAT22((int)((ulong)in_stack_0000ffd0 >> 0x10),unaff_SI);
  partyIndex = (byte)unaff_DI;
  uVar37 = (undefined1)((uint)unaff_DI >> 8);
  if (!GameRunning) {
    cStack_1d = '\0';
    found = 0x0;
    for (uStack_16 = 0xf8; uStack_16 < GUnitCount; uStack_16 = uStack_16 + 1) {
      pbVar1 = &((unit_t *)GUnits)[uStack_16].flags;
      *pbVar1 = *pbVar1 & 0xfc;
    }
    for (uStack_16 = 0; (int)uStack_16 < (int)(uint)GLeaderCount; uStack_16 = uStack_16 + 1) {
      if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3d) != '\0') {
        ovc22_textRingProt(partyIndex,(undefined1)uStack_16);
      }
    }
    GGameState = 0x3e;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (uVar25 = 0xf8; uVar25 < GUnitCount; uVar25 = uVar25 + 1) {
      uVar26 = (undefined2)((ulong)GUnits >> 0x10);
      puVar18 = (unit_t *)GUnits;
      if ((puVar18[uVar25].flags & 3) == 0) {
        if ((puVar18[uVar25].unitType == 0xff) ||
           (uVar6 = *(undefined4 *)((uint)puVar18[uVar25].unitType << 2),
           *(char *)((int)uVar6 + 0x3f) == '\0')) {
          uStack_8 = 0x96;
        }
        else {
          uStack_8 = 0x5dc;
        }
        if (puVar18[uVar25].level != 0) {
          uVar11 = ovr_randBelow(CONCAT11(uVar37,partyIndex),(char)uStack_8);
          uVar26 = (undefined2)((ulong)GUnits >> 0x10);
          puVar18 = (unit_t *)GUnits;
          if ((int)(uVar11 & 0xff) <
              (int)(100 - (uint)*(byte *)((uint)(puVar18 + uVar25)->bldType * 0x27 + 0x130))) {
            bldType = (puVar18 + uVar25)->bldType;
            puVar18[uVar25].level = puVar18[uVar25].level - 1;
            puVar18 = (unit_t *)GUnits;
            uVar26 = (undefined2)((ulong)GUnits >> 0x10);
            if (((*(uint *)((uint)bldType * 0x27 + 0x121) & 4) == 0) &&
               ((puVar18[uVar25].level == 0 ||
                ((*(uint *)((uint)bldType * 0x27 + 0x121) & 0x200) != 0)))) {
              ovc22_usesGUnits(uVar25,(uint8_t *)
                                      CONCAT13((char)(uVar25 * 9 >> 8),
                                               CONCAT12(puVar18[uVar25].unitType,unaff_SS)));
            }
            else if (((((bld_inst_t *)BldInstances + bldType)->ofs != 0 ||
                       *(int *)((int)&BldInstances[0].seg + (uint)bldType * 0xc) != 0) ||
                     (*(char *)((uint)bldType * 0x27 + 0x11e) == '\x10')) &&
                    (uVar26 = ovc22_usesGOngoingBattle2
                                        (*(byte *)&puVar18[uVar25].x,*(byte *)&puVar18[uVar25].y),
                    (char)uVar26 != '\0')) {
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
    for (uStack_16 = 0; (int)uStack_16 < (int)(uint)GLeaderCount; uStack_16 = uStack_16 + 1) {
      if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3d) != '\0') {
        *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa2) = 0;
        cVar10 = *(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3f);
        if ((cVar10 == '\0') &&
           (*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f) <
            *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d) >> 1)) {
          bVar7 = true;
        }
        else {
          bVar7 = false;
        }
        uVar25 = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54);
        uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar19 = *(int *)(iVar19 + 0x58) + ((int)uVar25 >> 0xf) +
                 (uint)CARRY2(*(uint *)(iVar19 + 0x56),uVar25);
        if ((iVar19 < 1) && (iVar19 < 0)) {
          for (uVar25 = 0xf8; uVar25 < GUnitCount; uVar25 = uVar25 + 1) {
            uVar26 = (undefined2)((ulong)GUnits >> 0x10);
            puVar18 = (unit_t *)GUnits;
            bldType = (puVar18 + uVar25)->bldType;
            if ((puVar18[uVar25].unitType == uStack_16) &&
               (*(int *)((uint)bldType * 0x27 + 0x123) < 0)) {
              uVar12 = *(uint *)((uint)bldType * 0x27 + 0x123);
              uVar27 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
              iVar19 = *(int *)(iVar19 + 0x58) + ((int)uVar12 >> 0xf) +
                       (uint)CARRY2(*(uint *)(iVar19 + 0x56),uVar12);
              if ((iVar19 < 1) && (iVar19 < 0)) {
                if ((cVar10 == '\0') && (puVar18[uVar25].level != 0)) {
                  uVar11 = ovr_randBelow(CONCAT11(uVar37,partyIndex),100);
                  uVar26 = (undefined2)((ulong)GUnits >> 0x10);
                  puVar18 = (unit_t *)GUnits;
                  if (*(byte *)((uint)(puVar18 + uVar25)->bldType * 0x27 + 0x130) <= (byte)uVar11) {
                    if (puVar18[uVar25].level != 0) {
                      puVar18[uVar25].level = puVar18[uVar25].level - 1;
                    }
                    puVar18 = (unit_t *)GUnits;
                    uVar26 = (undefined2)((ulong)GUnits >> 0x10);
                    if (((*(uint *)((uint)bldType * 0x27 + 0x121) & 4) == 0) &&
                       ((iVar19 = 0, puVar18[uVar25].level == 0 ||
                        (iVar19 = (uint)bldType * 0x27, (*(uint *)(iVar19 + 0x121) & 0x200) != 0))))
                    {
                      ovc22_usesGUnits(uVar25,(uint8_t *)
                                              CONCAT13((char)((uint)iVar19 >> 8),
                                                       CONCAT12((undefined1)uStack_16,unaff_SS)));
                    }
                    else if (((((bld_inst_t *)BldInstances + bldType)->ofs != 0 ||
                               *(int *)((int)&BldInstances[0].seg + (uint)bldType * 0xc) != 0) ||
                             (*(char *)((uint)bldType * 0x27 + 0x11e) == '\x10')) &&
                            (uVar26 = ovc22_usesGOngoingBattle2
                                                (*(byte *)&puVar18[uVar25].x,
                                                 *(byte *)&puVar18[uVar25].y), (char)uVar26 != '\0')
                            ) {
                      found = 0x1;
                    }
                  }
                }
              }
              else {
                uVar13 = *(uint *)((uint)bldType * 0x27 + 0x123);
                uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
                iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
                puVar2 = (uint *)(iVar19 + 0x56);
                uVar12 = *puVar2;
                *puVar2 = *puVar2 + uVar13;
                piVar3 = (int *)(iVar19 + 0x58);
                *piVar3 = *piVar3 + ((int)uVar13 >> 0xf) + (uint)CARRY2(uVar12,uVar13);
              }
            }
          }
          uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar19 + 0x58) = 0;
          *(undefined2 *)(iVar19 + 0x56) = 0;
        }
        else {
          if ((cVar10 == '\0') && (0 < *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54))) {
            uStack_10 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54) / 10;
          }
          else {
            uStack_10 = 0;
          }
          bVar29 = CARRY2(GPopulationLo,uStack_10);
          GPopulationLo = GPopulationLo + uStack_10;
          GPopulationHi = GPopulationHi + ((int)uStack_10 >> 0xf) + (uint)bVar29;
          uVar12 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54) - uStack_10;
          uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
          puVar2 = (uint *)(iVar19 + 0x56);
          uVar25 = *puVar2;
          *puVar2 = *puVar2 + uVar12;
          piVar3 = (int *)(iVar19 + 0x58);
          *piVar3 = *piVar3 + ((int)uVar12 >> 0xf) + (uint)CARRY2(uVar25,uVar12);
        }
        if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3e) * 0x95) & 0x100)
            == 0) {
          if (*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f) <
              *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d)) {
            uStack_12 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d) -
                        *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f);
            uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar23 = (int)*(undefined4 *)(uStack_16 << 2);
            iVar19 = *(int *)(iVar23 + 0x62);
            if ((-1 < iVar19) && ((0 < iVar19 || (*(int *)(iVar23 + 0x60) != 0)))) {
              uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar25 = *(uint *)(iVar19 + 0x62);
              if ((0x7fff < uVar25) ||
                 ((uStack_14 = uStack_12, (int)uVar25 < 1 && (*(uint *)(iVar19 + 0x60) <= uStack_12)
                  ))) {
                uStack_14 = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x60);
              }
              uStack_12 = uStack_12 - uStack_14;
              uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar2 = (uint *)(iVar19 + 0x60);
              uVar25 = *puVar2;
              *puVar2 = *puVar2 - uStack_14;
              piVar3 = (int *)(iVar19 + 0x62);
              *piVar3 = *piVar3 - (uint)(uVar25 < uStack_14);
            }
            if (uStack_12 != 0) {
              uStack_a = uStack_12;
              if (*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0) < uStack_12) {
                uStack_a = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0);
              }
              uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar25 = *(uint *)(iVar19 + 0x58);
              if (((int)uVar25 < 1) && ((0x7fff < uVar25 || (*(uint *)(iVar19 + 0x56) < uStack_a))))
              {
                uStack_a = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x56);
              }
              uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar2 = (uint *)(iVar19 + 0x56);
              uVar25 = *puVar2;
              *puVar2 = *puVar2 - uStack_a;
              piVar3 = (int *)(iVar19 + 0x58);
              *piVar3 = *piVar3 - (uint)(uVar25 < uStack_a);
              uStack_12 = uStack_12 - uStack_a;
              *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa2) = uStack_a;
            }
            if (cVar10 == '\0') {
              for (iVar19 = 0; (uStack_12 != 0 && (iVar19 < (int)(uint)GLeaderCount));
                  iVar19 = iVar19 + 1) {
                if ((*(char *)((int)*(undefined4 *)(iVar19 << 2) + 0x3d) != '\0') &&
                   ((*(char *)((int)*(undefined4 *)(iVar19 << 2) + 0x3f) == '\0' &&
                    (uVar26 = (undefined2)((ulong)*(undefined4 *)(iVar19 << 2) >> 0x10),
                    iVar23 = (int)*(undefined4 *)(iVar19 << 2),
                    *(int *)(iVar23 + 0x60) != 0 || *(int *)(iVar23 + 0x62) != 0)))) {
                  uVar26 = (undefined2)((ulong)*(undefined4 *)(iVar19 << 2) >> 0x10);
                  iVar23 = (int)*(undefined4 *)(iVar19 << 2);
                  uVar25 = *(uint *)(iVar23 + 0x62);
                  if ((uVar25 < 0x8000) &&
                     ((0 < (int)uVar25 || (uStack_12 < *(uint *)(iVar23 + 0x60))))) {
                    uStack_14 = uStack_12;
                  }
                  else {
                    uStack_14 = *(uint *)((int)*(undefined4 *)(iVar19 << 2) + 0x60);
                  }
                  uStack_12 = uStack_12 - uStack_14;
                  uVar26 = (undefined2)((ulong)*(undefined4 *)(iVar19 << 2) >> 0x10);
                  iVar23 = (int)*(undefined4 *)(iVar19 << 2);
                  puVar2 = (uint *)(iVar23 + 0x60);
                  uVar25 = *puVar2;
                  *puVar2 = *puVar2 - uStack_14;
                  piVar3 = (int *)(iVar23 + 0x62);
                  *piVar3 = *piVar3 - (uint)(uVar25 < uStack_14);
                }
              }
            }
            uVar25 = 0;
            while ((uVar25 < EntityCount && (uStack_12 != 0))) {
              uVar26 = (undefined2)((ulong)Entities >> 0x10);
              peVar22 = (entity_t *)Entities;
              if (((*(char *)((int)&peVar22[uVar25].base.entity + 1) == '\0') &&
                  (*(byte *)((int)&peVar22[uVar25].base.entity + 3) == uStack_16)) &&
                 ((bVar7 || (1 < peVar22[uVar25].base.animFrame)))) {
                if (peVar22[uVar25].base.animFrame != 0x0) {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  puVar4 = &((entity_t *)Entities)[uVar25].base.animFrame;
                  *puVar4 = *puVar4 + 0xff;
                  if (((entity_t *)Entities)[uVar25].base.animFrame == 0x0) {
                    cStack_1d = '\x01';
                  }
                }
                uStack_12 = uStack_12 - 1;
              }
              uVar25 = uVar25 + 1;
            }
          }
          else {
            uVar12 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f) -
                     *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d);
            uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
            puVar2 = (uint *)(iVar19 + 0x60);
            uVar25 = *puVar2;
            *puVar2 = *puVar2 + uVar12;
            piVar3 = (int *)(iVar19 + 0x62);
            *piVar3 = *piVar3 + (uint)CARRY2(uVar25,uVar12);
          }
        }
        uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar19 = *(int *)(iVar20 + 0x62);
        uVar27 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar21 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar23 = *(int *)(iVar21 + 0x80);
        if ((iVar23 <= iVar19) &&
           ((iVar23 < iVar19 || (*(uint *)(iVar21 + 0x7e) < *(uint *)(iVar20 + 0x60))))) {
          uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
          uVar25 = *(uint *)(iVar19 + 0x60);
          uVar27 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar23 = (int)*(undefined4 *)(uStack_16 << 2);
          puVar2 = (uint *)(iVar23 + 0x7e);
          uVar12 = (uint)(uVar25 < *puVar2);
          uVar13 = *(int *)(iVar19 + 0x62) - *(int *)(iVar23 + 0x80);
          if (((int)(uVar13 - uVar12) < 0) ||
             ((uVar13 == uVar12 &&
              (uVar25 - *puVar2 <= *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0))))) {
            uStack_a = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x60) -
                       *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7e);
          }
          else {
            uStack_a = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0);
          }
          *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa2) = -uStack_a;
          uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
          puVar2 = (uint *)(iVar19 + 0x56);
          uVar25 = *puVar2;
          *puVar2 = *puVar2 + uStack_a;
          piVar3 = (int *)(iVar19 + 0x58);
          *piVar3 = *piVar3 + (uint)CARRY2(uVar25,uStack_a);
          uVar27 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
          uVar26 = *(undefined2 *)(iVar19 + 0x7e);
          uVar28 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar23 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar23 + 0x62) = *(undefined2 *)(iVar19 + 0x80);
          *(undefined2 *)(iVar23 + 0x60) = uVar26;
        }
        if ((*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x5b) <
             *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d)) &&
           ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3e) * 0x95) & 0x80)
            == 0)) {
          uStack_12 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d) -
                      *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x5b);
          uVar25 = 0;
          while ((uVar25 < EntityCount && (uStack_12 != 0))) {
            uVar26 = (undefined2)((ulong)Entities >> 0x10);
            peVar22 = (entity_t *)Entities;
            if ((*(byte *)((int)&peVar22[uVar25].base.entity + 3) == uStack_16) &&
               ((((*(char *)((int)&peVar22[uVar25].base.entity + 1) == '\0' &&
                  (peVar22[uVar25].base.destX == 0)) && (peVar22[uVar25].base.destY == 0)) &&
                (3 < peVar22[uVar25].base.animFrame)))) {
              if (DebugVerbose != false) {
                printf("kill 2 \r");
              }
              puVar4 = &((entity_t *)Entities)[uVar25].base.animFrame;
              *puVar4 = *puVar4 + 0xff;
              uStack_12 = uStack_12 - 1;
            }
            uVar25 = uVar25 + 1;
          }
        }
        ovr_ovc25_tickCountdown(CONCAT11(uVar37,partyIndex),(char)uStack_16);
        _fmemset((void *)(ulong)*(uint *)(uStack_16 * 4 + 2),6,CONCAT11(uVar37,partyIndex));
        _fmemset((void *)(ulong)*(uint *)(uStack_16 * 4 + 2),6,CONCAT11(uVar37,partyIndex));
        uVar11 = ovr_randBelow(CONCAT11(uVar37,partyIndex),100);
        if ((byte)uVar11 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6c) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 100);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6a) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 100);
        }
        uVar11 = ovr_randBelow(CONCAT11(uVar37,partyIndex),100);
        if ((byte)uVar11 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6e) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x66);
        }
        else {
          piVar3 = (int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6c);
          *piVar3 = *piVar3 + *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x66);
        }
        piVar3 = (int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6e);
        *piVar3 = *piVar3 + *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x68);
        uVar11 = ovr_randBelow(CONCAT11(uVar37,partyIndex),100);
        if ((byte)uVar11 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x78) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x70);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x76) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x70);
        }
        uVar11 = ovr_randBelow(CONCAT11(uVar37,partyIndex),100);
        if ((byte)uVar11 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7a) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x72);
        }
        else {
          piVar3 = (int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x78);
          *piVar3 = *piVar3 + *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x72);
        }
        uVar11 = ovr_randBelow(CONCAT11(uVar37,partyIndex),100);
        if ((byte)uVar11 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7c) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x74);
        }
        else {
          piVar3 = (int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7a);
          *piVar3 = *piVar3 + *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x74);
        }
        *(undefined1 *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa7) =
             *(undefined1 *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa6);
        if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3f) != '\0') {
          uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar23 = (int)*(undefined4 *)(uStack_16 << 2);
          iVar19 = *(int *)(iVar23 + 0x58);
          if ((iVar19 < 1) && ((iVar19 != 0 || (*(int *)(iVar23 + 0x56) == 0)))) {
            uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
            *(undefined2 *)(iVar19 + 0x58) = 0;
            *(undefined2 *)(iVar19 + 0x56) = 0x32;
          }
        }
        if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0xaa) != '\0') {
          uStack_4 = (uint)*(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xaa);
          for (uVar25 = 0; (int)uVar25 < (int)(uint)GLeaderCount; uVar25 = uVar25 + 1) {
            uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
            iVar19 = *(int *)(iVar20 + 0x58);
            uVar27 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar21 = (int)*(undefined4 *)(uStack_16 << 2);
            iVar23 = *(int *)(iVar21 + 0x8c);
            if ((iVar23 <= iVar19) &&
               ((iVar19 != iVar23 || (*(uint *)(iVar21 + 0x8a) <= *(uint *)(iVar20 + 0x56)))))
            break;
            if ((*(char *)((int)*(undefined4 *)(uVar25 << 2) + 0x3d) != '\0') &&
               (((0 < *(int *)((int)*(undefined4 *)(uVar25 << 2) + 0x54) &&
                 (*(char *)((int)*(undefined4 *)(uVar25 << 2) + 0x3f) == '\0')) &&
                (uVar25 != uStack_16)))) {
              uVar13 = (uint)(((long)*(int *)((int)*(undefined4 *)(uVar25 << 2) + 0x54) *
                               (long)(int)uStack_4 & 0xffffU) / 100);
              uVar9 = in_stack_0000ffd4 >> 0x10;
              in_stack_0000ffd4 = in_stack_0000ffd4 & 0xffff0000;
              uVar28 = (undefined2)a;
              a = CONCAT22(uVar13,uVar28);
              uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar12 = *(uint *)(iVar19 + 0x8a);
              uVar27 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar23 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar2 = (uint *)(iVar23 + 0x56);
              iVar19 = (*(int *)(iVar19 + 0x8c) - *(int *)(iVar23 + 0x58)) -
                       (uint)(uVar12 < *puVar2);
              if ((iVar19 < 1) && ((iVar19 < 0 || (uVar12 - *puVar2 < uVar13)))) {
                uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
                iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
                uVar12 = *(uint *)(iVar19 + 0x8a);
                uVar27 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
                iVar23 = (int)*(undefined4 *)(uStack_16 << 2);
                puVar2 = (uint *)(iVar23 + 0x56);
                in_stack_0000ffd4 =
                     CONCAT22((int)uVar9,
                              (*(int *)(iVar19 + 0x8c) - *(int *)(iVar23 + 0x58)) -
                              (uint)(uVar12 < *puVar2));
                a = CONCAT22(uVar12 - *puVar2,uVar28);
              }
              uVar26 = (undefined2)((ulong)*(undefined4 *)(uVar25 << 2) >> 0x10);
              iVar23 = (int)*(undefined4 *)(uVar25 << 2);
              iVar19 = *(int *)(iVar23 + 0x58);
              if ((iVar19 <= (int)in_stack_0000ffd4) &&
                 ((iVar19 < (int)in_stack_0000ffd4 ||
                  (*(uint *)(iVar23 + 0x56) < (uint)((ulong)a >> 0x10))))) {
                uVar26 = (undefined2)((ulong)*(undefined4 *)(uVar25 << 2) >> 0x10);
                iVar19 = (int)*(undefined4 *)(uVar25 << 2);
                in_stack_0000ffd4 =
                     CONCAT22((int)(in_stack_0000ffd4 >> 0x10),*(undefined2 *)(iVar19 + 0x58));
                a = CONCAT22(*(undefined2 *)(iVar19 + 0x56),(int)a);
              }
              uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar13 = (uint)((ulong)a >> 0x10);
              puVar2 = (uint *)(iVar19 + 0x56);
              uVar12 = *puVar2;
              *puVar2 = *puVar2 + uVar13;
              piVar3 = (int *)(iVar19 + 0x58);
              *piVar3 = *piVar3 + (int)in_stack_0000ffd4 + (uint)CARRY2(uVar12,uVar13);
              uVar26 = (undefined2)((ulong)*(undefined4 *)(uVar25 << 2) >> 0x10);
              iVar19 = (int)*(undefined4 *)(uVar25 << 2);
              puVar2 = (uint *)(iVar19 + 0x56);
              uVar12 = *puVar2;
              *puVar2 = *puVar2 - uVar13;
              piVar3 = (int *)(iVar19 + 0x58);
              *piVar3 = (*piVar3 - (int)in_stack_0000ffd4) - (uint)(uVar12 < uVar13);
            }
          }
        }
        iVar19 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x58);
        if ((iVar19 < 1) && (iVar19 < 0)) {
          uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar19 + 0x58) = 0;
          *(undefined2 *)(iVar19 + 0x56) = 0;
        }
        uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar19 = *(int *)(iVar20 + 0x58);
        uVar27 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar21 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar23 = *(int *)(iVar21 + 0x8c);
        if ((iVar23 <= iVar19) &&
           ((iVar23 < iVar19 || (*(uint *)(iVar21 + 0x8a) < *(uint *)(iVar20 + 0x56))))) {
          uVar27 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
          uVar26 = *(undefined2 *)(iVar19 + 0x8a);
          uVar28 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar23 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar23 + 0x58) = *(undefined2 *)(iVar19 + 0x8c);
          *(undefined2 *)(iVar23 + 0x56) = uVar26;
        }
      }
    }
    GGameState = 0x40;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (uVar25 = 0xf8; uVar25 < GUnitCount; uVar25 = uVar25 + 1) {
      uVar26 = (undefined2)((ulong)GUnits >> 0x10);
      puVar18 = (unit_t *)GUnits;
      if ((*(uint *)((uint)(puVar18 + uVar25)->bldType * 0x27 + 0x121) & 0x40) != 0) {
        if (puVar18[uVar25].timer != 0) {
          puVar18[uVar25].timer = puVar18[uVar25].timer - 1;
        }
        uVar26 = (undefined2)((ulong)GUnits >> 0x10);
        if (((unit_t *)GUnits)[uVar25].timer == 0) {
          uVar6 = *(undefined4 *)((uint)((unit_t *)GUnits)[uVar25].unitType << 2);
          if (*(char *)((int)uVar6 + 0x3f) == '\0') {
            ovr_play_sfx(0,0x51);
            uVar27 = (undefined2)((ulong)GUnits >> 0x10);
            iVar19 = ((unit_t *)GUnits)[uVar25].y;
            uVar34 = (undefined1)iVar19;
            uVar35 = (undefined1)((uint)iVar19 >> 8);
            uVar26 = 0x2410;
            uVar12 = ovr_alignUp4(iVar19,(char)((unit_t *)GUnits)[uVar25].x);
            pcVar14 = ovr_fmVsprintf((char *)CONCAT13((char)(uVar12 >> 8),
                                                      CONCAT12((char)uVar12,0x2410)),
                                     (char *)CONCAT13(uVar37,CONCAT12(partyIndex,
                                                                      CONCAT11(uVar35,uVar34))));
            ovr_say((char *)CONCAT13(uVar37,CONCAT12(partyIndex,uVar26)),(char)pcVar14);
            ovr_inputUpdate((ulong)CONCAT11(uVar37,partyIndex) << 0x10,MessageDelay * '\x02' + '$');
          }
          ovc22_usesGUnits(uVar25,(uint8_t *)
                                  CONCAT13((char)(uVar25 * 9 >> 8),
                                           CONCAT12(((unit_t *)GUnits)[uVar25].unitType,unaff_SS)));
        }
      }
    }
    GGameState = 0x42;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    ovr_driver_clearMapFlagsRect
              ((ulong)GMapFlags >> 0x10,0,0x93,0x3b,-9,(uint)(short (*) [60] [148])GMapFlags,0x3b,
               0xf7);
    for (uStack_16 = 0; uStack_16 < SquareRecCount; uStack_16 = uStack_16 + 1) {
      puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[*(int *)(uStack_16 * 0x13 + 2)] +
                       *(int *)(uStack_16 * 0x13));
      *puVar2 = *puVar2 | 8;
    }
    if (EntityCount <= EntityScanPos) {
      EntityScanPos = 0;
      for (uStack_16 = 0; (int)uStack_16 < (int)(uint)GLeaderCount; uStack_16 = uStack_16 + 1) {
        if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3d) != '\0') {
          iVar19 = ((int *)(uStack_16 * 4))[1];
          memcpy((char *)CONCAT22(((int *)(uStack_16 * 4))[1],
                                  (char *)(*(int *)(uStack_16 * 4) + 0x8e)),
                 (char *)CONCAT13((char)((uint)iVar19 >> 8),
                                  CONCAT12((char)iVar19,*(int *)(uStack_16 * 4) + 0x94)),3);
        }
      }
    }
    iStack_e = 0;
    bStack_5 = ovr_manage_findFirstLeader();
    if ((bStack_5 == 0xff) || (GCanPromote == '\0')) {
      iStack_c = 0;
    }
    else if (*(byte *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x86) < 5) {
      iStack_c = 0x28;
    }
    else {
      iStack_c = (uint)*(byte *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x86) * 4 + 0x14;
    }
    for (uStack_16 = EntityScanPos; uStack_16 < EntityCount; uStack_16 = uStack_16 + 1) {
      uVar26 = (undefined2)((ulong)Entities >> 0x10);
      peVar22 = (entity_t *)Entities;
      if (((*(char *)((int)&peVar22[uStack_16].base.entity + 1) == '\0') &&
          (peVar22[uStack_16].base.destX == 0)) && (peVar22[uStack_16].base.destY == 0)) {
        bStack_6 = peVar22[uStack_16].base.gindex;
        uVar34 = *(undefined1 *)((int)(char **)GMenuStrings + (uint)bStack_6 * 0x95 + 0x1f);
        bVar5 = *(byte *)((int)&peVar22[uStack_16].base.entity + 3);
        bVar29 = false;
        bVar8 = false;
        bVar7 = false;
        if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bStack_6 * 0x95) == -1) {
          bVar29 = true;
          uVar16 = (uint)bStack_6 * 0x95;
        }
        else {
          bStack_1b = *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x89);
          if (bStack_1b < 5) {
            uStack_1a = peVar22[uStack_16].base.y;
            uStack_18 = ovr_alignUp4(CONCAT11(uVar37,partyIndex),
                                     (char)((peVar22 + uStack_16)->base).x);
            uVar11 = 0x2410;
            if (((*(short (*) [60] [148])GMapFlags)[uStack_1a][uStack_18] & 8U) == 0) {
              successWeight = 0x22;
              partialWeight = 0x21;
              bldType = 0x22;
            }
            else {
              uVar35 = (undefined1)unaff_SS;
              uVar36 = (undefined1)(unaff_SS >> 8);
              puVar33 = &successWeight;
              puVar31 = &partialWeight;
              puVar30 = &bldType;
              index = CONCAT11((char)((uint)puVar30 >> 8),bStack_1b);
              uVar16 = unaff_SS;
              uVar32 = unaff_SS;
              uVar15 = ovr_attact_usesSquareRecCount();
              table.seg = uVar11;
              table.ofs = uVar15;
              pctOut.seg = uVar16;
              pctOut.ofs = (uint16_t)puVar30;
              remainderOut.seg = uVar32;
              remainderOut.ofs = (uint16_t)puVar31;
              (*(uint8_t *)((uint8_t *)&(partOut.seg))) = uVar35;
              partOut.ofs = (uint16_t)puVar33;
              (*(uint8_t *)((uint8_t *)&(partOut.seg) + 1)) = uVar36;
              ovr_attact_compute3(table,index,pctOut,remainderOut,partOut);
            }
          }
          else {
            successWeight = 0x22;
            partialWeight = 0x21;
            bldType = 0x22;
          }
          uVar11 = ovr_randBelow(CONCAT11(uVar37,partyIndex),100);
          if ((byte)uVar11 < successWeight) {
            bVar29 = true;
            uVar16 = uVar11;
          }
          else {
            uVar16 = (uint)partialWeight + (uint)successWeight;
            if ((uVar11 & 0xff) < uVar16) {
              bVar8 = true;
            }
            else {
              bVar7 = true;
            }
          }
        }
        if ((bVar7) &&
           (uVar26 = (undefined2)((ulong)Entities >> 0x10),
           cVar10 = ovr_ovc23_tickRecordsAt
                              (((entity_t *)Entities)[uStack_16].base.y,
                               CONCAT11((char)(uVar16 >> 8),uVar34),partyIndex,
                               (((entity_t *)Entities + uStack_16)->base).x,uVar34), cVar10 == '\0')
           ) {
          if ((partialWeight == 0x0) && (successWeight == 0x0)) {
            uVar11 = ovr_randBelow(CONCAT11(uVar37,partyIndex),2);
            if ((uVar11 & 0xff) == 0) {
              bVar29 = true;
            }
            else {
              bVar8 = true;
            }
          }
          else {
            uVar11 = ovr_randBelow(CONCAT11(uVar37,partyIndex),partialWeight + successWeight);
            if ((byte)uVar11 < successWeight) {
              bVar29 = true;
            }
            else {
              bVar8 = true;
            }
          }
        }
        if ((bVar29) && (uVar25 = ovc22_usesEntities(uStack_16), (uVar25 & 0xff) == 0)) {
          bVar8 = true;
        }
        if (bVar8) {
          if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bStack_6 * 0x95) != -1) &&
             (bVar5 != 0xff)) {
            if ((*(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x3f) != '\0') ||
               (((entity_t *)Entities)[uStack_16].base.level <
                *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x53))) {
              uVar34 = (undefined1)iStack_c;
              uVar35 = (undefined1)((uint)iStack_c >> 8);
              ovc22_usesLUDIV_at_((entity_t *)
                                  CONCAT13((char)((ulong)Entities >> 0x18),
                                           CONCAT12((char)((ulong)Entities >> 0x10),
                                                    (entity_t *)Entities + uStack_16)));
              uVar25 = 0;
              plVar17 = LXMUL_at_((long *)CONCAT11(uVar37,partyIndex),a,in_stack_0000ffd4);
              peVar22 = (entity_t *)Entities + uStack_16;
              uVar11 = ovr_ovc15_textError(peVar22,(*(uint16_t *)((uint8_t *)&(Entities) + 2)),
                                           (int)(CONCAT12((uVar25 & 1) != 0,plVar17) >> 1),
                                           (char)((int)uVar25 >> 1));
              uVar12 = ovc22_usesLUDIV_at_2(uVar11,(uint16_t)peVar22,CONCAT11(uVar35,uVar34));
              uVar26 = (undefined2)((ulong)Entities >> 0x10);
              peVar24 = (entity_t *)Entities;
              uVar25 = *(uint *)&peVar24[uStack_16].base.health;
              *(uint *)&peVar24[uStack_16].base.frameIndex =
                   (int)&(peVar22->base).x +
                   (uint)CARRY2(uVar25,uVar12) + *(int *)&peVar24[uStack_16].base.frameIndex;
              *(uint *)&peVar24[uStack_16].base.health = uVar25 + uVar12;
              ovr_ovc41_compute3(CONCAT13(uVar37,CONCAT12(partyIndex,(*(uint16_t *)((uint8_t *)&(Entities) + 2)))),
                                 (char)((entity_t *)Entities + uStack_16));
            }
          }
          ovc22_usesEntities2(uStack_16);
          ovc22_usesEntities3(uStack_16);
          ovc22_usesEntities4(uStack_16);
        }
        iVar19 = (uint)((entity_t *)Entities)[uStack_16].base.animFrame -
                 (uint)*(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4);
        uVar26 = (undefined2)in_stack_0000ffd4;
        in_stack_0000ffd4 = CONCAT22(iVar19,uVar26);
        if (0 < iVar19) {
          if (3 < iVar19) {
            in_stack_0000ffd4 = CONCAT22(3,uVar26);
          }
          if ((int)(in_stack_0000ffd4 >> 0x10) == 3) {
            if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x92) == 0) {
              in_stack_0000ffd4 = CONCAT22(2,(int)in_stack_0000ffd4);
            }
            else {
              piVar3 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x92);
              *piVar3 = *piVar3 + -1;
            }
          }
          if ((int)(in_stack_0000ffd4 >> 0x10) == 2) {
            if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x90) == 0) {
              in_stack_0000ffd4 = CONCAT22(1,(int)in_stack_0000ffd4);
            }
            else {
              piVar3 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x90);
              *piVar3 = *piVar3 + -1;
            }
          }
          if ((int)(in_stack_0000ffd4 >> 0x10) == 1) {
            if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x8e) == 0) {
              in_stack_0000ffd4 = in_stack_0000ffd4 & 0xffff;
            }
            else {
              piVar3 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x8e);
              *piVar3 = *piVar3 + -1;
            }
          }
          ((entity_t *)Entities)[uStack_16].base.animFrame =
               *(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4) +
               (char)(in_stack_0000ffd4 >> 0x10);
        }
        iStack_e = iStack_e + 1;
        if (199 < iStack_e) break;
      }
    }
    EntityScanPos = uStack_16;
    mapDirty = 1;
    ovr_unit_usesAlignUp4();
    GGameState = 0x44;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    uVar25 = EntityCount;
    if (cStack_1d != '\0') {
      while (uStack_16 = uVar25 - 1, -1 < (int)uStack_16) {
        uVar26 = (undefined2)((ulong)Entities >> 0x10);
        peVar22 = (entity_t *)Entities;
        uVar25 = uStack_16;
        if (peVar22[uStack_16].base.animFrame == 0x0) {
          if (*(char *)((int)(char **)GMenuStrings +
                       (uint)peVar22[uStack_16].base.gindex * 0x95 + 0x1f) == '\0') {
            uVar34 = 0;
            uVar35 = 0xa0;
            uVar25 = ovr_alignUp4(peVar22[uStack_16].base.y,((peVar22 + uStack_16)->base).x);
            iVar19 = (uint)((entity_t *)Entities)[uStack_16].base.gindex * 0x95;
            uVar26 = 0x195d;
            pcVar14 = ovr_fmVsprintf((char *)CONCAT22(*(undefined2 *)
                                                       ((int)&worldMenuLabels[0].seg + 1 + iVar19),
                                                      (char *)"puppetmaker" + 3),
                                     (char *)CONCAT22(uVar25,(char *)*(undefined2 *)
                                                                      ((int)&worldMenuLabels[1].ofs
                                                                       + 1 + iVar19)));
            ovr_uiNotify((char *)CONCAT13(uVar35,CONCAT12(uVar34,uVar26)),(uint16_t)pcVar14);
          }
          ovr_ovc15_removeEntity(CONCAT11(uVar37,partyIndex),(char)uStack_16);
          uVar25 = uStack_16;
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
  undefined2 uVar5;
  undefined2 uVar6;
  
  bVar1 = ovc22_textArena(x,y);
  if (bVar1) {
    uVar5 = (undefined2)((ulong)GUnitGrid >> 0x10);
    paasVar2 = (short (*) [148] [60])GUnitGrid;
    uVar6 = (undefined2)((ulong)GUnits >> 0x10);
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
              if (((*(int *)(uVar4 * 0x12 + 4) == y) && (*(uint *)(uVar4 * 0x12 + 2) <= x)) &&
                 (x < *(int *)(uVar4 * 0x12 + 2) +
                      (uint)*(byte *)((uint)*(byte *)(uVar4 * 0x12 + 8) * 0x27 + 0x11b))) {
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
  int unaff_DI;
  uint uVar5;
  
  iVar4 = (*(short (*) [148] [60])GUnitGrid)[x][y];
  bVar1 = ((unit_t *)GUnits)[iVar4].unitType;
  uVar3 = CONCAT11((char)((uint)(iVar4 * 9) >> 8),bVar1);
  if (bVar1 == unitType) {
    uVar2 = ovr_alignUp4(unaff_DI,x);
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
  int unaff_DI;
  
  uVar1 = (*(short (*) [148] [60])GUnitGrid)[x][y];
  if (uVar1 < 0xf8) {
    uVar2 = ovr_ovc23_findRecordAt(y,unaff_DI,x);
    if (uVar2 == 0xffff) {
      uVar1 = (uint)((unit_t *)GUnits + uVar1)->bldType;
      if (((*(uint *)(uVar1 * 0x27 + 0x121) & 2) == 0) &&
         ((*(uint *)(uVar1 * 0x27 + 0x121) & 0x20) == 0)) {
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
  int unaff_DI;
  
  if ((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 4) == 0) {
    uVar1 = (*(short (*) [148] [60])GUnitGrid)[x][y];
    if (uVar1 < 0xf8) {
      uVar2 = ovr_ovc23_findRecordAt(y,unaff_DI,x);
      if (uVar2 == 0xffff) {
        uVar1 = (uint)((unit_t *)GUnits + uVar1)->bldType;
        if ((*(uint *)(uVar1 * 0x27 + 0x121) & 0x20) == 0) {
          uVar1 = 0;
        }
        else if (*(char *)(uVar1 * 0x27 + 0x131) == '\0') {
          if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x2f) == '\x05') {
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
  int unaff_DI;
  
  uVar1 = (*(short (*) [148] [60])GUnitGrid)[x][y];
  if (uVar1 < 0xf8) {
    uVar2 = ovr_ovc23_findRecordAt(y,unaff_DI,x);
    if (uVar2 == 0xffff) {
      uVar1 = (uint)((unit_t *)GUnits + uVar1)->bldType;
      if ((*(uint *)(uVar1 * 0x27 + 0x121) & 0x20) == 0) {
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

undefined2 __cdecl16far ovc22_usesGMapFlags2(char skipCheck,int x1,int y1,int x2,int y2)

{
  undefined2 in_AX;
  undefined2 uVar1;
  int iVar2;
  byte bVar3;
  int unaff_DI;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  char cStack_3;
  
  if (skipCheck == '\0') {
    iStack_6 = ovr_ovc07_signum(unaff_DI,x2 - x1);
    iStack_8 = ovr_ovc07_signum(unaff_DI,y2 - y1);
    if ((iStack_6 != 0) || (iStack_8 != 0)) {
      cStack_3 = '\0';
      while( true ) {
        iStack_a = iStack_6;
        iStack_c = iStack_8;
        uVar1 = (undefined2)((ulong)GMapFlags >> 0x10);
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
  int unaff_DI;
  uint uVar4;
  uint uStack_4;
  
  uStack_4 = 0;
  do {
    if (GRecordCount <= uStack_4) {
      return GRecordCount & 0xff00;
    }
    if (*(uint8_t *)(uStack_4 * 0x12 + 9) == classIndex) {
      uVar2 = ovr_alignUp4(unaff_DI,*(undefined2 *)(uStack_4 * 0x12 + 2));
      uVar1 = *(uint16_t *)(uStack_4 * 0x12 + 4);
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
  undefined2 uVar5;
  undefined4 *puVar6;
  uint *in_stack_00000004;
  char cStack_8;
  char cStack_7;
  int iStack_6;
  int iStack_4;
  
  x1 = *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004);
  y1 = *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)));
  skipCheck = *(byte *)((int)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(yPtr) + 2)) << 2) + 0x3f);
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
      puVar6 = (undefined4 *)0x0;
      if ((yOutOfs & 1) == 0) {
        puVar6 = (undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(yPtr) + 2)) << 2);
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
  uint uVar1;
  uint16_t uVar2;
  int iVar3;
  int iVar4;
  uint16_t unaff_DI;
  undefined2 uVar5;
  byte bVar6;
  
  if (((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 2) == 0) ||
     ((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 4) == 0)) {
    if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3f) == '\0') {
      uVar1 = ovc22_usesGUnitGrid2(x,y,partyIndex);
      bVar6 = (byte)unaff_DI;
      if ((*(uint *)(uVar1 * 0x27 + 0x121) & 0x20) == 0) {
        if ((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 2) == 0) {
          uVar5 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
          iVar3 = (int)*(undefined4 *)((uint)partyIndex << 2);
          if (*(int *)(iVar3 + 0x56) == 0 && *(int *)(iVar3 + 0x58) == 0) {
            uVar1 = 0;
          }
          else {
            uVar5 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
            iVar3 = (int)*(undefined4 *)((uint)partyIndex << 2);
            uVar1 = *(int *)(iVar3 + 0x4d) * 2 + *(int *)(iVar3 + 0x4d);
            if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4f) < uVar1 >> 2) {
              uVar1 = 0;
            }
            else {
              uVar1 = ovr_bldng_getClass(bVar6,CONCAT11((byte)(uVar1 >> 10),partyIndex));
              uVar1 = ovr_bldng_usesRandBelow(bVar6,uVar1 & 0xff);
              uVar1 = uVar1 & 0xff;
              uVar5 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
              iVar4 = (int)*(undefined4 *)((uint)partyIndex << 2);
              iVar3 = *(int *)(iVar4 + 0x58);
              if ((iVar3 < 0) ||
                 ((iVar3 == 0 && (*(uint *)(iVar4 + 0x56) < *(uint *)(uVar1 * 0x27 + 0x125))))) {
                uVar1 = 0;
              }
            }
          }
        }
        else {
          uVar1 = 0;
        }
      }
    }
    else {
      uVar1 = ovc22_usesGUnitGrid(x,y);
      if ((*(uint *)(uVar1 * 0x27 + 0x121) & 2) == 0) {
        uVar2 = ovr_randBelow(unaff_DI,2);
        if (((uVar2 & 0xff) == 0) && ((*(uint *)(uVar1 * 0x27 + 0x121) & 0x20) != 0)) {
          if (*(char *)(uVar1 * 0x27 + 0x131) == '\0') {
            uVar1 = uVar1 + 6;
          }
        }
        else {
          uVar2 = ovr_randBelow(unaff_DI,8);
          if (((uVar2 & 0xff) == 0) ||
             ((uVar2 = ovr_randBelow(unaff_DI,3), (uVar2 & 0xff) == 0 &&
              (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4f) <
               *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d))))) {
            uVar2 = ovr_randBelow(unaff_DI,3);
            uVar1 = (uVar2 & 0xff) + 1;
          }
          else {
            uVar2 = ovr_randBelow(unaff_DI,0xc);
            if ((uVar2 & 0xff) == 0) {
              uVar2 = ovr_randBelow(unaff_DI,3);
              uVar1 = (uVar2 & 0xff) + 0x2b;
              uVar5 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
              iVar4 = (int)*(undefined4 *)((uint)partyIndex << 2);
              iVar3 = *(int *)(iVar4 + 0x58);
              if (-1 < iVar3) {
                if (iVar3 != 0) {
                  return uVar1;
                }
                if (*(uint *)(uVar1 * 0x27 + 0x125) <= *(uint *)(iVar4 + 0x56)) {
                  return uVar1;
                }
              }
            }
            uVar2 = ovr_randBelow(unaff_DI,0xc);
            if ((uVar2 & 0xff) == 0) {
              uVar2 = ovr_randBelow(unaff_DI,3);
              uVar1 = (uVar2 & 0xff) + 0xec;
              uVar5 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
              iVar4 = (int)*(undefined4 *)((uint)partyIndex << 2);
              iVar3 = *(int *)(iVar4 + 0x58);
              if (-1 < iVar3) {
                if (iVar3 != 0) {
                  return uVar1;
                }
                if (*(uint *)(uVar1 * 0x27 + 0x125) <= *(uint *)(iVar4 + 0x56)) {
                  return uVar1;
                }
              }
            }
            bVar6 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3e);
            uVar2 = ovr_randBelow(unaff_DI,3);
            uVar1 = (uVar2 & 0xff) +
                    (uint)*(byte *)((int)&worldMenuLabels[0xb].ofs + 1 + (uint)bVar6 * 0x95);
            uVar5 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
            iVar4 = (int)*(undefined4 *)((uint)partyIndex << 2);
            iVar3 = *(int *)(iVar4 + 0x58);
            if ((iVar3 < 0) ||
               ((iVar3 == 0 && (*(uint *)(iVar4 + 0x56) < *(uint *)(uVar1 * 0x27 + 0x125))))) {
              uVar1 = (uint)*(byte *)((int)&worldMenuLabels[0xb].ofs + 1 + (uint)bVar6 * 0x95);
            }
          }
        }
      }
      else {
        uVar2 = ovr_randBelow(unaff_DI,0x14);
        if ((uVar2 & 0xff) == 0) {
          uVar1 = 0x72;
        }
        else {
          uVar2 = ovr_randBelow(unaff_DI,4);
          if ((uVar2 & 0xff) == 0) {
            uVar1 = 0x71;
          }
          else {
            uVar1 = 0x70;
          }
        }
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 5087:4975 */

/* [R4] calls ovr_randBelow */

void __cdecl16far ovc22_usesRandBelow2(byte partyIndex,uint16_t outFlag,uint16_t outFlagSeg,...)

{
  uint *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint16_t uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined1 uVar8;
  int iVar9;
  int iVar10;
  byte unaff_SI;
  undefined2 uVar11;
  uint *unaff_SS;
  byte in_stack_00000004;
  uint16_t y;
  uint16_t x;
  byte bStack_8;
  undefined1 uStack_7;
  char cStack_6;
  char cStack_5;
  byte bStack_4;
  byte bStack_3;
  
  bStack_8 = ListCount;
  if (*(char *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0xa8) != '\0') {
    uVar5 = ovr_randBelow();
    uStack_7 = (undefined1)uVar5;
    if ((uVar5 & 0xff) <
        ((uint)*(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0xa8) * 100) /
        (*(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0xa8) + 1)) {
      uVar5 = ovr_randBelow();
      cStack_5 = (char)uVar5;
      cStack_6 = '\0';
      for (bStack_8 = 0; bStack_8 < ListCount; bStack_8 = bStack_8 + 1) {
        uVar11 = (undefined2)((ulong)GUnits >> 0x10);
        if ((*(char *)((uint)((unit_t *)GUnits + *(int *)((uint)bStack_8 * 2 + -0x6d44))->bldType *
                       0x27 + 0x133) == '\x12') &&
           (((unit_t *)GUnits)[*(int *)((uint)bStack_8 * 2 + -0x6d44)].unitType == in_stack_00000004
           )) {
          if (cStack_6 == cStack_5) break;
          cStack_6 = cStack_6 + '\x01';
        }
      }
    }
  }
  if (bStack_8 < ListCount) {
    uVar11 = (undefined2)((ulong)GUnits >> 0x10);
    x = ((unit_t *)GUnits)[*(int *)((uint)bStack_8 * 2 + -0x6d44)].x;
    y = ((unit_t *)GUnits)[*(int *)((uint)bStack_8 * 2 + -0x6d44)].y;
  }
  else {
    x = *(uint16_t *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x39);
    y = *(uint16_t *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x3b);
  }
  uVar11 = (undefined2)((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
  iVar9 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
  iVar10 = *(int *)(iVar9 + 0x58);
  if ((iVar10 < 1) && ((iVar10 < 0 || (*(uint *)(iVar9 + 0x56) < 10)))) {
    bStack_4 = 1;
  }
  else {
    bStack_4 = 0;
  }
  if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                (uint)*(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x3e) * 0x95) &
      0x80) == 0) {
    bStack_3 = 0;
  }
  else {
    bStack_3 = 3;
  }
  if ((*(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x5d) & 2) != 0) {
    bStack_3 = bStack_3 | 1;
  }
  uVar4 = *(undefined4 *)((uint)in_stack_00000004 << 2);
  if ((*(byte *)((int)uVar4 + 0x5d) & 4) != 0) {
    bStack_3 = bStack_3 | 2;
  }
  uVar6 = ovc22_searchCellsAround
                    ((uint *)CONCAT22(&y,unaff_SS),
                     (uint *)CONCAT22(CONCAT11((char)(((uint)in_stack_00000004 << 2) >> 8),
                                               in_stack_00000004),unaff_SS),bStack_3,bStack_4,
                     unaff_SI);
  if ((uVar6 & 0xff) != 0) {
    if ((uVar6 & 0xff) != 1) {
      return;
    }
    uVar6 = ovc22_usesRandBelow(in_stack_00000004,x,y);
    if (uVar6 == 0) {
      x = *(uint16_t *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x39);
      y = *(uint16_t *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x3b);
    }
    else {
      puVar7 = (undefined4 *)(uVar6 * 0x27);
      if ((*(uint *)((int)puVar7 + 0x121) & 0x60) == 0) {
        uVar11 = (undefined2)((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
        iVar9 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
        iVar10 = *(int *)(iVar9 + 0x58);
        if ((iVar10 < 0) ||
           ((iVar10 == 0 && (*(uint *)(iVar9 + 0x56) < *(uint *)(uVar6 * 0x27 + 0x125))))) {
          puVar7 = (undefined4 *)((uint)in_stack_00000004 << 2);
          uVar11 = (undefined2)((ulong)*puVar7 >> 0x10);
          iVar10 = (int)*puVar7;
          *(undefined2 *)(iVar10 + 0x58) = 0;
          *(undefined2 *)(iVar10 + 0x56) = 0;
        }
        else {
          puVar7 = (undefined4 *)*(uint *)(uVar6 * 0x27 + 0x125);
          uVar11 = (undefined2)((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
          iVar10 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
          puVar1 = (uint *)(iVar10 + 0x56);
          puVar3 = (undefined4 *)*puVar1;
          *puVar1 = *puVar1 - (int)puVar7;
          piVar2 = (int *)(iVar10 + 0x58);
          *piVar2 = *piVar2 - (uint)(puVar3 < puVar7);
        }
      }
      uVar8 = (undefined1)((uint)puVar7 >> 8);
      ovr_createConstructionRecordFar
                ((byte)x,y,_partyIndex,
                 (uint8_t *)CONCAT22(CONCAT11(uVar8,in_stack_00000004),outFlag),unaff_SI,(char)uVar6
                 ,CONCAT11(uVar8,(char)uVar6),x);
    }
  }
  uVar4 = *(undefined4 *)((uint)in_stack_00000004 << 2);
  if (*(char *)((int)uVar4 + 0x3f) == '\0') {
    uVar6 = *(uint *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x5b);
    uVar8 = (undefined1)(uVar6 >> 8);
    if (uVar6 < *(uint *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x4d)) {
      ovr_ovc18_textTypeLen((uint8_t)x,y,1,unaff_SI,CONCAT11(uVar8,in_stack_00000004),x);
    }
    else {
      ovr_ovc18_textTypeLen((uint8_t)x,y,0,unaff_SI,CONCAT11(uVar8,in_stack_00000004),x);
    }
  }
  else {
    ovr_ovc18_textTypeLen
              (0x0,0,0,unaff_SI,
               CONCAT11((char)(((uint)in_stack_00000004 << 2) >> 8),in_stack_00000004),0);
  }
  return;
}



/* 5087:4dd9 */

/* WARNING: Variable defined which should be unmapped: outFlag */
/* Runs the per-leader random spawn chance and spawns through ovc22_usesRandBelow2. */

void __cdecl16far ovc22_spawnForLeaders(void...)

{
  uint16_t uVar1;
  uint16_t unaff_SS;
  byte bStack_6;
  uint8_t outFlag;
  int iStack_4;
  
  _bStack_6 = (uint)bStack_6;
  for (iStack_4 = 0; iStack_4 < (int)(uint)GLeaderCount; iStack_4 = iStack_4 + 1) {
    if (((*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3d) != '\0') &&
        (uVar1 = ovr_randBelow(_bStack_6,
                               (uint)(byte)((char *)"Decrease message delay" + 5)
                                           [(uint)*(byte *)((int)*(undefined4 *)(iStack_4 << 2) +
                                                           0x3e) * 0x95]),
        (byte)uVar1 < *(byte *)((int)*(undefined4 *)(iStack_4 << 2) + 0x2e))) &&
       ((*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3f) != '\0' ||
        (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x4d) <=
         *(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x5b))))) {
      if (EntityCount < 0x21c) {
        ovc22_usesRandBelow2
                  ((byte)&outFlag,unaff_SS,_bStack_6,
                   CONCAT11((char)((uint)&outFlag >> 8),(undefined1)iStack_4));
      }
      else if (*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3f) == '\0') {
        if (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x45) < 0x23) {
          ovc22_usesRandBelow2
                    ((byte)&outFlag,unaff_SS,_bStack_6,
                     CONCAT11((char)((uint)&outFlag >> 8),(undefined1)iStack_4));
        }
        else if (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x45) < 0x4b) {
          uVar1 = ovr_randBelow(_bStack_6,8);
          if ((uVar1 & 0xff) == 0) {
            ovc22_usesRandBelow2
                      ((byte)&outFlag,unaff_SS,_bStack_6,
                       CONCAT11((char)((uint)&outFlag >> 8),(undefined1)iStack_4));
          }
        }
        else {
          uVar1 = ovr_randBelow(_bStack_6,0x10);
          if ((uVar1 & 0xff) == 0) {
            ovc22_usesRandBelow2
                      ((byte)&outFlag,unaff_SS,_bStack_6,
                       CONCAT11((char)((uint)&outFlag >> 8),(undefined1)iStack_4));
          }
        }
      }
      else if (*(int *)((int)*(undefined4 *)(iStack_4 << 2) + 0x47) == 0) {
        ovc22_usesRandBelow2
                  ((byte)&outFlag,unaff_SS,_bStack_6,
                   CONCAT11((char)((uint)&outFlag >> 8),(undefined1)iStack_4));
      }
      else if (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x45) < 0x19) {
        ovc22_usesRandBelow2
                  ((byte)&outFlag,unaff_SS,_bStack_6,
                   CONCAT11((char)((uint)&outFlag >> 8),(undefined1)iStack_4));
      }
      else if (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x45) < 0x32) {
        uVar1 = ovr_randBelow(_bStack_6,8);
        if ((uVar1 & 0xff) == 0) {
          ovc22_usesRandBelow2
                    ((byte)&outFlag,unaff_SS,_bStack_6,
                     CONCAT11((char)((uint)&outFlag >> 8),(undefined1)iStack_4));
        }
      }
      else {
        uVar1 = ovr_randBelow(_bStack_6,0x10);
        if ((uVar1 & 0xff) == 0) {
          ovc22_usesRandBelow2
                    ((byte)&outFlag,unaff_SS,_bStack_6,
                     CONCAT11((char)((uint)&outFlag >> 8),(undefined1)iStack_4));
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

undefined2 __cdecl16far ovc22_usesGOngoingBattle(byte x,byte y,...)

{
  undefined2 uVar1;
  byte in_stack_00000004;
  
  if (GOngoingBattle == '\0') {
    if (((int)(uint)x < GfxRndSeed2 + -4) || (GfxRndSeed2 < (int)(uint)x)) {
      return 0;
    }
  }
  else if (((int)(uint)x < GfxRndSeed2 + -2) || (GfxRndSeed2 < (int)(uint)x)) {
    return 0;
  }
  if (((int)(uint)in_stack_00000004 < GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)x) * 2 + -0x73ed))
     || (GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)x) * 2 + -0x73ff) < (int)(uint)in_stack_00000004
        )) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 5087:510e */

/* [R6] touches GOngoingBattle, GfxRndSeed2 */

undefined2 __cdecl16far ovc22_usesGOngoingBattle2(byte x,byte y)

{
  undefined2 uVar1;
  
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


