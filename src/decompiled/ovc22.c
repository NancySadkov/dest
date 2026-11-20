/*
 * ovc22.c - recovered from STRONG.EXE
 * memory block: OVC22
 * range: 5087:0000 - 5087:576f
 * functions: 31
 */
#include "recovered.h"


/* 5087:0000 */

/* [R2] string "arena" */

char * __cdecl16far ovc22_textArena(int x,int y)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined2 uVar4;
  int iStack_4;
  
  if ((((x < 0) || (y < 0)) || (0x93 < x + 1)) || (0x3b < y + 1)) {
    placementStatus = 2;
    pcVar2 = (char *)"arena" + 4;
  }
  else {
    uVar4 = (undefined2)((ulong)GMapFlags >> 0x10);
    if ((((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) == 0) &&
       (((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) == 0)) {
      iStack_4 = (int)(char)(*(byte (*) [59] [148])GMapCells)[y + 1][x];
      iVar1 = (int)(char)(*(byte (*) [59] [148])GMapCells)[y + 1][x + 1];
      iVar3 = iStack_4;
      if (iVar1 < iStack_4) {
        iVar3 = iVar1;
      }
      if (iStack_4 < iVar1) {
        iStack_4 = iVar1;
      }
      if (iStack_4 - iVar3 < 9) {
        placementStatus = 3;
        pcVar2 = (char *)"arena" + 5;
      }
      else {
        pcVar2 = (char *)(iStack_4 - iVar3 & 0xff00);
      }
    }
    else {
      placementStatus = 1;
      pcVar2 = (char *)"arena" + 4;
    }
  }
  return pcVar2;
}



/* 5087:0119 */

/* Returns the class name of a party slot (cls < 7 from the table at 0x123) or "monster". */

char * __cdecl16far ovc22_className(byte partyIndex)

{
  byte bVar1;
  char *pcVar2;
  
  bVar1 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x2f);
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

char * __cdecl16far ovc22_textPOPULATION(byte bldType,byte partyIndex,agnt_t *agnt)

{
  byte *pbVar1;
  byte bVar2;
  undefined1 uVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  undefined2 uVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  char in_CL;
  uint16_t uVar11;
  char *unaff_BP;
  char *pcVar12;
  undefined2 unaff_SI;
  uint16_t unaff_DI;
  uint8_t *unaff_SS;
  undefined2 in_stack_00000000;
  uint16_t in_stack_0000000c;
  uint16_t in_stack_0000000e;
  uint8_t numBuf;
  undefined2 auStackY_11a [66];
  uint8_t labelPtrs;
  undefined2 auStackY_94 [23];
  uint8_t menuItems;
  uint8_t labelOfs;
  char *suffix;
  far_t entries;
  undefined4 uVar13;
  uint8_t term;
  undefined1 uVar14;
  
  term = (uint8_t)unaff_SI;
  uVar14 = (undefined1)((uint)unaff_SI >> 8);
  if (*(char *)((uint)bldType * 0x27 + 0x133) == '\x16') {
    pcVar8 = (char *)0x0;
  }
  else if (*(char *)((uint)bldType * 0x27 + 0x128) == '\0') {
    pcVar8 = (char *)0x0;
  }
  else {
    if ((*(uint *)((uint)bldType * 0x27 + 0x121) & 0x20) == 0) {
      if ((*(uint *)((uint)bldType * 0x27 + 0x121) & 0x80) == 0) {
        pcVar8 = (char *)(uint)*(byte *)((uint)bldType * 0x27 + 0x128);
      }
      else {
        pcVar8 = (char *)ovc22_applyRankBonus
                                   (partyIndex,(uint)*(byte *)((uint)bldType * 0x27 + 0x128));
      }
    }
    else {
      pcVar8 = (char *)ovc22_compute1(partyIndex,(uint)*(byte *)((uint)bldType * 0x27 + 0x128));
    }
    if (pcVar8 == (char *)0x0) {
      pcVar8 = (char *)0x0;
    }
    else if (*(char *)((uint)bldType * 0x27 + 0x133) == '\x19') {
      if (GSeason == '\0') {
        if (GTimeLo < 0xf) {
          pcVar8 = (char *)((uint)pcVar8 >> 2);
        }
        else {
          pcVar8 = (char *)((uint)pcVar8 >> 1);
        }
      }
      else if (GSeason == '\x02') {
        pcVar8 = pcVar8 + ((uint)pcVar8 >> 2);
      }
    }
    else {
      if ((*(uint *)((uint)bldType * 0x27 + 0x121) & 0x80) != 0) {
        uVar11 = (*(uint16_t *)((uint8_t *)&(agnt) + 2));
        uVar9 = ovr_constr_usesGMapFlags2((int)(agnt_t *)agnt,(*(uint16_t *)((uint8_t *)&(agnt) + 2)));
        switch(uVar9 & 0xff) {
        case 1:
          *(char *)(unaff_DI + 0x34) = *(char *)(unaff_DI + 0x34) << 1;
code_r0x0005b805:
          if (((entity_t *)Entities)[(int)pcVar8].base.destY != (*(uint16_t *)((uint8_t *)&(agnt) + 2)))
          goto L_OVC25_5b66_00ff_01D9;
          do {
            pbVar1 = (byte *)((int)&((entity_t *)Entities)[(int)pcVar8].base.flags32 + 1);
            *pbVar1 = *pbVar1 | 8;
L_OVC25_5b66_00ff_01D9:
            while( true ) {
              do {
                pcVar8 = pcVar8 + 1;
                if (EntityCount <= pcVar8) {
                  if (partyIndex != 0) {
                    iVar6 = 0;
                    while ((iVar6 < (int)(uint)partyIndex &&
                           (uVar9 = ovc25_usesAlignUp4(bldType,in_stack_0000000c,in_stack_0000000e,
                                                       unaff_DI,(*(uint16_t *)((uint8_t *)&(agnt) + 2))), -1 < (int)uVar9))) {
                      *(undefined1 *)&((entity_t *)Entities)[uVar9].base.state = 0;
                      ((entity_t *)Entities)[uVar9].base.destX = unaff_DI;
                      ((entity_t *)Entities)[uVar9].base.destY = (*(uint16_t *)((uint8_t *)&(agnt) + 2));
                      pbVar1 = (byte *)((int)&((entity_t *)Entities)[uVar9].base.flags32 + 1);
                      *pbVar1 = *pbVar1 | 8;
                      iVar6 = iVar6 + 1;
                    }
                  }
                  return (char *)0xffff;
                }
                uVar7 = (undefined2)((ulong)Entities >> 0x10);
              } while (*(byte *)((int)&((entity_t *)Entities)[(int)pcVar8].base.entity + 3) !=
                       bldType);
              uVar9 = ovr_alignUp4((((entity_t *)Entities + (int)pcVar8)->base).x);
              uVar10 = ovr_alignUp4(unaff_DI);
              uVar7 = (undefined2)((ulong)Entities >> 0x10);
              if ((uVar9 == uVar10) && (((entity_t *)Entities)[(int)pcVar8].base.y == (*(uint16_t *)((uint8_t *)&(agnt) + 2))))
              break;
              uVar9 = ovr_alignUp4(((entity_t *)Entities)[(int)pcVar8].base.destX);
              uVar10 = ovr_alignUp4(unaff_DI);
              if (uVar9 == uVar10) goto code_r0x0005b805;
            }
          } while( true );
        case 2:
          pcVar4 = (code *)swi(1);
          pcVar8 = (char *)(*pcVar4)();
          return pcVar8;
        case 3:
          do {
            if (*(byte *)(uVar11 + 0x32) < *(byte *)((int)pcVar8 * 0x34 + 0x22)) {
              *(undefined1 *)((int)pcVar8 * 0x34 + 0x22) = *(undefined1 *)(uVar11 + 0x32);
            }
            uVar11 = 0x34;
            pcVar12 = pcVar8;
code_r0x0005ff56:
            bVar2 = *(byte *)((int)pcVar8 * uVar11 + 0x21);
            uVar11 = CONCAT11((char)((int)pcVar8 * uVar11 >> 8),bVar2);
            pcVar8 = pcVar12;
            if (*(byte *)((int)pcVar12 * 0x34 + 0x22) < bVar2) {
              uVar3 = *(undefined1 *)((int)pcVar12 * 0x34 + 0x22);
              uVar11 = CONCAT11((char)((uint)((int)pcVar12 * 0x34) >> 8),uVar3);
              *(undefined1 *)((int)pcVar12 * 0x34 + 0x21) = uVar3;
            }
            do {
              pcVar8 = pcVar8 + 1;
              if ((int)(uint)AgntCount <= (int)pcVar8) {
                uVar11 = ovr_audio_panFromX(agnt);
                ovr_play_sfxU(0x1c,0,uVar11);
                return (char *)CONCAT11((char)(uVar11 >> 8),1);
              }
            } while (*(uint16_t *)((int)pcVar8 * 0x34 + 0x1b) != ((agnt_t *)agnt)->owner);
          } while( true );
        case 4:
          iVar6 = ovr_font_textWidth((char *)CONCAT13(uVar14,CONCAT12(term,0x552d)),
                                     (char *)CONCAT22(in_stack_00000000,unaff_BP));
          uVar11 = 0xd4 - iVar6;
          term = (uint8_t)Font02.seg;
          uVar14 = (undefined1)(Font02.seg >> 8);
          uVar13 = 0x552d22c4;
          TextBlitX = uVar11;
          ovr_blitLabel((char *)"POPULATION",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,term)
          ;
          for (pcVar12 = (char *)0x0; TextBlitY = TextBlitY + 0xc,
              (int)pcVar12 < (int)(uint)(byte)((ulong)uVar13 >> 8); pcVar12 = pcVar12 + 1) {
            TextBlitX = 0x11;
            if (((int)pcVar12 < 5) || ((char)uVar13 == '\0')) {
              suffix = (char *)"fighters" + 2;
              ovr_blitLabel(*(char **)(&labelPtrs + (int)pcVar12 * 4),
                            (uint8_t *)auStackY_94[(int)pcVar12 * 2],Font02.ofs,(uint8_t)Font02.seg)
              ;
            }
            else {
              uVar9 = (uint)*(byte *)((int)*(undefined4 *)((uint)bldType << 2) + 0x2f);
              suffix = (char *)&VideoFlag_2410_0167;
              ovr_blitLabel((char *)auStackY_11a[(int)pcVar12 * 2 + uVar9 * 8],
                            (uint8_t *)auStackY_11a[(int)pcVar12 * 2 + uVar9 * 8 + 1],Font02.ofs,
                            (uint8_t)Font02.seg);
            }
            suffix = (char *)"steam bath" + 6;
            _labelOfs = 0x1b7;
            func_0x0005f303();
            ovr_stsprintf((char *)&numBuf,(char *)unaff_SS,(char *)"%d");
            iVar6 = ovr_font_textWidth((char *)CONCAT22(unaff_SS,&numBuf),
                                       (char *)CONCAT22(Font02.seg,Font02.ofs));
            TextBlitX = 0x89 - iVar6;
            suffix = (char *)"clerical unit" + 9;
            ovr_blitLabel((char *)&numBuf,unaff_SS,Font02.ofs,(uint8_t)Font02.seg);
            ovr_stsprintf((char *)&numBuf,(char *)unaff_SS,(char *)"%d");
            iVar6 = ovr_font_textWidth((char *)CONCAT22(unaff_SS,&numBuf),
                                       (char *)CONCAT22(Font02.seg,Font02.ofs));
            uVar11 = 0xd4 - iVar6;
            uVar13 = CONCAT22(Font02.seg,Font02.ofs);
            suffix = (char *)"Archduchess" + 3;
            TextBlitX = uVar11;
            ovr_blitLabel((char *)&numBuf,unaff_SS,Font02.ofs,(uint8_t)Font02.seg);
          }
          CurSfxType3 = 0x3c;
          entries.seg = (uint16_t)unaff_SS;
          entries.ofs = (uint16_t)&menuItems;
          suffix = (char *)"steam bath" + 6;
          _labelOfs = 0x327;
          uVar7 = ovr_ovc28_usesUiInputText
                            (entries,unaff_DI,far_from_u32((uint32_t)(0x0)),&stack0xfff2,(uint16_t)unaff_SS);
          cVar5 = (char)uVar7;
          keyboardInputMode = 0;
          if (((cVar5 != '\0') && (cVar5 != '\x01')) && (cVar5 != -2)) {
            (&stack0xbac4)[unaff_DI] = (&stack0xbac4)[unaff_DI] + in_CL;
            pcVar8 = (char *)"puppetmaker" + 3;
            goto code_r0x0005ff56;
          }
          if (cVar5 == -2) {
            Cancelled = 1;
          }
          return (char *)"puppetmaker" + 3;
        }
      }
      if (GSeason == '\x01') {
        pcVar8 = pcVar8 + ((uint)pcVar8 >> 2);
      }
      else if (GSeason == '\x02') {
        pcVar8 = (char *)((uint)pcVar8 >> 2);
      }
    }
  }
  return pcVar8;
}



/* 5087:0411 */

/* Returns a building's income adjusted for the current season and time of day. */

uint __cdecl16far ovc22_seasonalIncome(byte bldType,uint8_t partyIndex)

{
  uint uVar1;
  
  if (*(int *)((uint)bldType * 0x27 + 0x123) == 0) {
    uVar1 = 0;
  }
  else if (*(char *)((uint)bldType * 0x27 + 0x133) == '\x19') {
    uVar1 = *(uint *)((uint)bldType * 0x27 + 0x123);
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
  else if ((*(uint *)((uint)bldType * 0x27 + 0x121) & 0x20) == 0) {
    if ((*(uint *)((uint)bldType * 0x27 + 0x121) & 0x80) == 0) {
      uVar1 = *(uint *)((uint)bldType * 0x27 + 0x123);
    }
    else {
      uVar1 = ovc22_applyRankBonus(partyIndex,*(int *)((uint)bldType * 0x27 + 0x123));
      if (GSeason == '\x01') {
        uVar1 = uVar1 + ((int)uVar1 >> 2);
      }
      else if (GSeason == '\x02') {
        uVar1 = (int)uVar1 >> 2;
      }
    }
  }
  else {
    uVar1 = ovc22_compute1(partyIndex,*(uint *)((uint)bldType * 0x27 + 0x123));
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

far_t * __cdecl16far ovc22_textRingProt(byte partyIndex)

{
  char *pcVar1;
  byte *pbVar2;
  uint *puVar3;
  int *piVar4;
  uint8_t *puVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  byte bVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
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
  uint3 uVar11;
  far_t *pfVar12;
  char cVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  char cVar18;
  undefined1 uVar19;
  far_t *in_AX;
  far_t *pfVar20;
  char *pcVar21;
  uint uVar22;
  uint uVar23;
  uint16_t index;
  uint16_t uVar24;
  undefined2 in_CX;
  byte bVar25;
  uint16_t *puVar26;
  byte bVar33;
  uint *puVar27;
  int iVar28;
  int iVar29;
  uint16_t uVar30;
  uint uVar31;
  uint uVar32;
  byte bVar34;
  byte bVar41;
  byte bVar42;
  unit_t *puVar35;
  unit_t *puVar36;
  int iVar37;
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
  uint *unaff_SS;
  bool bVar54;
  bool bVar55;
  bool bVar56;
  bool bVar57;
  byte in_AF;
  bool bVar58;
  bool bVar59;
  bool bVar60;
  byte bStack0006;
  byte in_stack_00000008;
  undefined1 in_stack_00000009;
  brect_t *in_stack_0000000a;
  undefined2 in_stack_0000000c;
  byte in_stack_0000000e;
  char in_stack_00000010;
  char acStackY_13e [36];
  undefined2 auStackY_11a [58];
  undefined1 auStackY_a6 [16];
  undefined2 auStackY_96 [22];
  uint16_t unitNameOfs;
  char acStackY_68 [6];
  undefined2 uStackY_62;
  undefined2 uStackY_60;
  far_t table;
  undefined2 *puVar61;
  undefined1 uVar62;
  undefined1 uVar63;
  undefined1 uVar64;
  undefined1 uVar65;
  uint8_t uVar66;
  undefined1 uVar67;
  uint8_t in_stack_0000ffb8;
  undefined1 in_stack_0000ffb9;
  undefined1 uVar68;
  undefined1 in_stack_0000ffbc;
  undefined1 in_stack_0000ffbd;
  uint in_stack_0000ffbe;
  uint16_t in_stack_0000ffc0;
  uint in_stack_0000ffc2;
  agnt_t *agnt;
  uint uStack_38;
  int iStack_36;
  uint uStack_34;
  int16_t resourceTotals [4];
  int16_t animStep;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  uint8_t uStack_1c;
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
  uint16_t uStack_8;
  undefined4 uStack_6;
  
  uVar19 = (undefined1)((uint)in_CX >> 8);
  uVar66 = (uint8_t)unaff_SI;
  uVar67 = (undefined1)((uint)unaff_SI >> 8);
  uVar65 = SUB21(unaff_DI,0);
  uVar64 = (undefined1)((uint)unaff_DI >> 8);
  if (partyIndex != 0xff) {
    uStack_1e = 0;
    uVar63 = 0;
    uVar68 = 0;
    uStack_22 = 0;
    uStack_24 = 0;
    uStack_20 = (byte *)__C0_ASM_CopyRight + 6;
    bVar16 = (byte)unaff_SS;
    uVar62 = (undefined1)((uint)unaff_SS >> 8);
    _fmemset(&animStep,(uint16_t)unaff_SS,0);
    _fmemset(resourceTotals + 1,(uint16_t)unaff_SS,0);
    _fmemset((void *)(*(int *)((uint)partyIndex * 4) + 0x9a),((int *)((uint)partyIndex * 4))[1],0);
    _fmemset(&scratch,(uint16_t)unaff_SS,0);
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
    agnt = (agnt_t *)(ulong)in_stack_0000ffc2;
    _fmemset(&stack0xffbc,(uint16_t)unaff_SS,0);
    uStack_14 = (far_t *)&GUnitDescriptions[3].ofs;
    while (uStack_14 = (far_t *)((int)uStack_14 + 1), uStack_14 < GUnitCount) {
      pbVar2 = &((unit_t *)GUnits)[(int)uStack_14].flags;
      *pbVar2 = *pbVar2 & 0xfd;
    }
    bVar17 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3f);
    uVar23 = CONCAT11(uVar19,bVar17);
    uStack_e = (uint *)(0x1000 << (bVar17 & 0x1f));
    *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xad) = 0;
    _fmemset((void *)(*(int *)((uint)partyIndex * 4) + 0xaa),((int *)((uint)partyIndex * 4))[1],0);
    iVar29 = CONCAT11(uVar68,uVar63);
    if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3f) == '\0') {
      pbVar2 = (byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d);
      *pbVar2 = *pbVar2 | 4;
    }
    else {
      pbVar2 = (byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d);
      *pbVar2 = *pbVar2 & 0xf9;
    }
    pbVar2 = (byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d);
    *pbVar2 = *pbVar2 & 0xf7;
    *(undefined2 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa0) = 0;
    *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa6) = 0;
    *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa5) = 0;
    *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa9) = 0;
    bVar17 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3e);
    (*(uint16_t *)((uint8_t *)&(uStack_6))) = (far_t *)CONCAT11(bVar17,(byte)uStack_6);
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar17 * 0x95) == '\x01') {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(far_t *)uStack_6);
      uVar11 = (uint3)uStack_6;
    }
    else {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((far_t *)uStack_6);
      uVar11 = (uint3)uStack_6;
    }
    (*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) = (byte)(uVar11 >> 8);
    if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) * 0x95) == '\0') ||
       (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) * 0x95) == '\x05')) {
      uStack_6 = (far_t *)CONCAT13(1,uVar11);
    }
    else {
      uStack_6 = (far_t *)(ulong)uVar11;
    }
    *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa8) = 0;
    GCanPromote = '\0';
    puVar47 = (uint *)&GUnitDescriptions[3].ofs;
    while (puVar48 = puVar47, puVar47 = (uint *)((int)puVar48 + 1), puVar47 < GUnitCount) {
      uVar51 = (undefined2)((ulong)GUnits >> 0x10);
      puVar35 = (unit_t *)GUnits;
      if (puVar35[(int)puVar47].unitType == partyIndex) {
        iVar28 = puVar35[(int)puVar47].x;
        uVar19 = (undefined1)iVar28;
        uVar63 = (undefined1)((uint)iVar28 >> 8);
        (*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) = (puVar35 + (int)puVar47)->bldType;
        uStack_16 = (far_t *)ovr_alignUp4(iVar28);
        uVar68 = (undefined1)iVar29;
        puVar27 = (uint *)CONCAT11(uVar63,uVar19);
        uVar51 = (undefined2)((ulong)GUnits >> 0x10);
        uStack_18 = ((unit_t *)GUnits)[(int)puVar47].y;
        puStack_10 = (uint *)0x0;
        uStack_1a = (uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) << 8;
        while( true ) {
          if (3 < (byte)uStack_1a) break;
          puVar27 = (uint *)(((int)uStack_16 + (uStack_1a & 0xff)) * 2);
          puStack_10 = (uint *)((uint)puStack_10 |
                               *(short *)((int)puVar27 +
                                         (int)((*(short (*) [60] [148])GMapFlags)[uStack_18 - 1] +
                                              0x92)) & 0x3000U);
          uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(byte)uStack_1a + 1);
        }
        puStack_12 = (uint *)0x0;
        if ((*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x11e) & 3) == 1) {
          uStack_1a = (uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) << 8;
          while ((byte)uStack_1a < 4) {
            puVar27 = (uint *)(((int)uStack_16 + (uStack_1a & 0xff)) * 2);
            puStack_12 = (uint *)((uint)puStack_12 |
                                 *(short *)((int)puVar27 +
                                           (int)((*(short (*) [60] [148])GMapFlags)[uStack_18] +
                                                0x92)) & 0x3000U);
            uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(byte)uStack_1a + 1);
          }
        }
        if ((((uint)uStack_e & (uint)puStack_10) != 0) || (((uint)uStack_e & (uint)puStack_12) != 0)
           ) {
          pbVar2 = &((unit_t *)GUnits)[(int)puVar47].flags;
          *pbVar2 = *pbVar2 | 3;
          iVar28 = 0x195d;
          uVar52 = 0x195d;
          pfVar20 = (far_t *)(*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) - 7);
          puVar35 = (unit_t *)GUnits;
          uVar51 = (undefined2)((ulong)GUnits >> 0x10);
          if (pfVar20 < (far_t *)((byte *)__C0_ASM_CopyRight + 0x12)) {
            puVar36 = (unit_t *)((int)pfVar20 * 2);
            bVar15 = (byte)pfVar20;
            uVar19 = (undefined1)((uint)pfVar20 >> 8);
            bVar17 = (byte)uVar23;
            bVar14 = (byte)(uVar23 >> 8);
            switch(pfVar20) {
            case (far_t *)0x0:
              AgntAnms[0x68].ey = AgntAnms[0x68].ey | 0x195d;
              puVar3 = unaff_DI;
              iVar29 = 1 - (*puVar3 & 3);
              *puVar3 = *puVar3 + (uint)(0 < iVar29) * iVar29;
              *(char *)puVar47 = (char)*puVar47 + '\x01';
              uVar32 = CONCAT11(uVar19,(s_my_s_we_in_this_neighborhood_are_doing_well[0x4c] - 0x2fU)
                                       + (0xe7U < (byte)
                                                  s_my_s_we_in_this_neighborhood_are_doing_well
                                                  [0x4c]));
              puVar3 = (uint *)((int)unaff_DI + (int)((int)&puVar36[-0xd8c].y + 1));
              uVar22 = (uint)(0x46 < (byte)(s_my_s_we_in_this_neighborhood_are_doing_well[0x4c] +
                                           0x18U) ||
                             CARRY1(s_my_s_we_in_this_neighborhood_are_doing_well[0x4c] - 0x2fU,
                                    0xe7U < (byte)s_my_s_we_in_this_neighborhood_are_doing_well
                                                  [0x4c]));
              uVar46 = (int)resourceTotals + (-0x1f - *puVar3);
              iVar29 = -uVar22;
              puVar7 = (undefined1 *)(uint)(&stack0xffaf < (undefined1 *)*puVar3 || uVar46 < uVar22)
              ;
              puVar9 = &stack0xfffe + -*puVar47;
              uVar22 = (uint)(&stack0xfffe < (undefined1 *)*puVar47 || puVar9 < puVar7);
              uVar31 = (int)puVar36 - *(uint *)(&puVar36->bldType + (int)unaff_DI);
              iVar37 = uVar31 - uVar22;
              uVar22 = (uint)(puVar36 < *(unit_t **)(&puVar36->bldType + (int)unaff_DI) ||
                             uVar31 < uVar22);
              uVar31 = 0x145d - *(uint *)(iVar37 + (int)unaff_DI);
              iVar50 = uVar31 - uVar22;
              uVar22 = (uint)(0x145d < *(uint *)(iVar37 + (int)unaff_DI) || uVar31 < uVar22);
              uVar31 = uVar32 - *unaff_DI;
              iVar28 = uVar31 - uVar22;
              uVar22 = (uint)(uVar32 < *unaff_DI || uVar31 < uVar22);
              uVar31 = (int)(puVar9 + -(int)puVar7) - (uVar46 + iVar29);
              bVar57 = puVar9 + -(int)puVar7 < (undefined1 *)(uVar46 + iVar29) || uVar31 < uVar22;
              uVar31 = uVar31 - uVar22;
              bVar15 = (byte)((uint)iVar28 >> 8);
              bVar25 = (byte)((uint)iVar37 >> 8);
              bVar16 = bVar15 - bVar25;
              bVar54 = bVar15 < bVar25 || bVar16 < bVar57;
              bVar34 = (byte)iVar28;
              bVar16 = bVar16 - bVar57;
              bVar41 = (byte)iVar50;
              bVar15 = bVar41 - bVar16;
              bVar57 = bVar41 < bVar16 || bVar15 < bVar54;
              bVar33 = (byte)((uint)iVar50 >> 8);
              bVar15 = bVar15 - bVar54;
              bVar41 = bVar25 - *(byte *)(iVar37 + -0x4ae6);
              bVar54 = bVar25 < *(byte *)(iVar37 + -0x4ae6) || bVar41 < bVar57;
              bVar41 = bVar41 - bVar57;
              bVar25 = bVar34 - (char)unaff_DI[0x250d];
              bVar57 = bVar34 < (byte)unaff_DI[0x250d] || bVar25 < bVar54;
              bVar25 = bVar25 - bVar54;
              bVar34 = (byte)iVar37 - AgntAnms[0xf].frmid;
              bVar54 = (byte)iVar37 < AgntAnms[0xf].frmid || bVar34 < bVar57;
              bVar34 = bVar34 - bVar57;
              bVar8 = bVar41 - bVar25;
              bVar42 = bVar8 - bVar54;
              puVar27 = (uint *)CONCAT11(bVar42,bVar34);
              uVar22 = (uint)(bVar41 < bVar25 || bVar8 < bVar54);
              uVar32 = uVar31 - uVar23;
              puVar45 = (uint *)(uVar32 - uVar22);
              puVar3 = (uint *)((int)unaff_DI + -0x57e7);
              uVar32 = (uint)(uVar31 < uVar23 || uVar32 < uVar22);
              uVar22 = *puVar3;
              uVar31 = *puVar3;
              *puVar3 = (uVar31 - (int)puVar45) - uVar32;
              puVar3 = (uint *)((int)puVar45 + 0x7419);
              uVar32 = (uint)(uVar22 < puVar45 || uVar31 - (int)puVar45 < uVar32);
              uVar31 = *puVar3;
              uVar22 = *puVar3;
              *puVar3 = (uVar22 - uVar23) - uVar32;
              puVar3 = puVar48 + 0xd;
              uVar22 = (uint)(uVar31 < uVar23 || uVar22 - uVar23 < uVar32);
              puVar48 = (uint *)*puVar3;
              uVar23 = *puVar3;
              *puVar3 = (uVar23 - (int)puVar27) - uVar22;
              *(undefined2 *)(uVar46 + iVar29 + -2) = unaff_DI;
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
              uVar23 = (uint)(puVar48 < puVar27 || uVar23 - (int)puVar27 < uVar22);
              (*(uint16_t *)((uint8_t *)&(s_Peaceful_2410_2915) + 4)) = (0x6665U - (int)unaff_DI) - uVar23;
              uVar23 = (uint)((uint)0x6665 < unaff_DI || (uint)(0x6665U - (int)unaff_DI) < uVar23);
              bVar57 = (uint)AgntAnms[6].y < CONCAT11(bVar33,bVar15);
              uVar22 = AgntAnms[6].y - CONCAT11(bVar33,bVar15);
              AgntAnms[6].y = uVar22 - uVar23;
              uVar23 = (uint)(bVar57 || uVar22 < uVar23);
              uVar22 = (uVar46 + iVar29 + -2) - (int)unaff_DI;
              bVar57 = (uint *)(uVar46 + iVar29 + -2) < unaff_DI || uVar22 < uVar23;
              iVar29 = -uVar23;
              puVar43 = (uint *)(uVar22 + iVar29);
              bVar54 = bVar15 < bVar14 || (byte)(bVar15 - bVar14) < bVar57;
              bVar15 = (bVar15 - bVar14) - bVar57;
              bVar57 = bVar16 < bVar34 || (byte)(bVar16 - bVar34) < bVar54;
              bVar41 = (bVar16 - bVar34) - bVar54;
              bVar16 = bVar15 - bVar25;
              bVar54 = bVar15 < bVar25 || bVar16 < bVar57;
              bVar16 = bVar16 - bVar57;
              pbVar2 = (byte *)((char *)((int)puVar27 + (int)puVar47) + -0x60e8);
              bVar57 = *pbVar2 < bVar14 || (byte)(*pbVar2 - bVar14) < bVar54;
              *pbVar2 = (*pbVar2 - bVar14) - bVar54;
              puVar3 = puVar45 + -0x3974;
              bVar15 = (byte)*puVar3 - bVar16;
              bVar54 = (byte)*puVar3 < bVar16 || bVar15 < bVar57;
              *(byte *)puVar3 = bVar15 - bVar57;
              puVar3 = puVar47 + 0x3c8c;
              bVar15 = (byte)*puVar3 - bVar25;
              bVar55 = (byte)*puVar3 < bVar25 || bVar15 < bVar54;
              *(byte *)puVar3 = bVar15 - bVar54;
              puVar3 = puVar45 + 0xc;
              bVar54 = (byte)*puVar3 < bVar33;
              bVar15 = (byte)*puVar3 - bVar33;
              bVar56 = bVar54 || bVar15 < bVar55;
              bVar60 = SBORROW1((byte)*puVar3,bVar33) != SBORROW1(bVar15,bVar55);
              *(byte *)puVar3 = bVar15 - bVar55;
              bVar59 = (char)(byte)*puVar3 < '\0';
              bVar58 = (byte)*puVar3 == 0;
              bVar57 = !bVar60;
              puVar48 = puVar45;
              if (!bVar57) {
                puVar3 = unaff_DI;
                unaff_DI = (uint *)((int)unaff_DI + 1);
                cVar18 = in(CONCAT11(bVar33,bVar16));
                *(char *)puVar3 = cVar18;
                puVar3 = puVar47 + 0xc;
                uVar23 = *puVar3;
                bVar14 = (byte)*puVar3 - bVar41;
                *(byte *)puVar3 = bVar14 - bVar56;
                *(undefined2 *)(uVar22 + iVar29 + -2) = puVar27;
                ((char *)((int)puVar45 + (int)puVar47))[0x18] =
                     (((char *)((int)puVar45 + (int)puVar47))[0x18] - bVar17) -
                     ((byte)uVar23 < bVar41 || bVar14 < bVar56);
                *(uint *)((int)puVar27 + (int)puVar47) =
                     *(uint *)((int)puVar27 + (int)puVar47) ^ (uint)puVar27;
                *(uint *)((int)puVar27 + (int)puVar47) =
                     *(uint *)((int)puVar27 + (int)puVar47) | (uint)puVar27;
                *(char *)((int)puVar27 + (int)puVar47) =
                     *(char *)((int)puVar27 + (int)puVar47) + bVar34;
                *puVar27 = ~*puVar27;
                puVar48 = (uint *)*puVar45;
                uVar23 = CONCAT11(bVar41,bVar25 - 0x18) & 0x9e1f;
                bVar59 = (int)uVar23 < 0;
                bVar58 = uVar23 == 0;
                puVar43 = puVar45 + 3;
              }
              bVar56 = bVar57 && bVar56;
              uVar51 = *puVar43;
              if (bVar58 || (bVar57 && bVar60) != bVar59) {
                bVar59 = bVar56;
                if ((!bVar57 || !bVar54 && bVar15 >= bVar55) && !bVar58) {
                  *puVar43 = (uint)puVar48;
                  uVar51 = *puVar43;
                  uVar23 = (int)(char)bVar17 + 0xe299;
                  iVar29 = uVar23 - bVar56;
                  *puVar43 = iVar29;
                  *(char *)puVar47 = -(char)*puVar47;
                  return (far_t *)((iVar29 + -0x1d32) -
                                  (uint)((uint)(int)(char)bVar17 < 0x1d67 || uVar23 < bVar56));
                }
              }
              else {
                bVar59 = bVar17 < 0x74 || (byte)(bVar17 + 0x8c) < bVar56;
                bVar17 = (bVar17 + 0x8c) - bVar56;
              }
              bVar57 = bVar17 < 100 || (byte)(bVar17 + 0x9c) < bVar59;
              bVar15 = (bVar17 + 0x9c) - bVar59;
              bVar17 = bVar15 - 0x39;
              bVar54 = bVar15 < 0x39 || bVar17 < bVar57;
              bVar17 = bVar17 - bVar57;
              bVar15 = bVar17 - 0x14;
              bVar57 = bVar17 < 0x14 || bVar15 < bVar54;
              bVar15 = bVar15 - bVar54;
              bVar17 = bVar15 - 8;
              bVar54 = bVar15 < 8 || bVar17 < bVar57;
              bVar17 = bVar17 - bVar57;
              bVar15 = bVar17 - 5;
              bVar14 = bVar15 - bVar54;
              iVar29 = ((int)puVar48 - (int)puVar27) -
                       (uint)(bVar14 < 0xfa || (byte)(bVar14 + 6) < (bVar17 < 5 || bVar15 < bVar54))
              ;
              uVar22 = (uint)puVar47 & *(uint *)((char *)((int)puVar27 + (int)puVar47) + -0x6bdd);
              uVar31 = (uint)unaff_DI & *(uint *)((char *)((int)puVar27 + (int)unaff_DI) + 0x23);
              *puVar43 = uVar22;
              uVar22 = uVar22 & *(uint *)((int)puVar27 + uVar31);
              uVar23 = CONCAT11(bVar33,bVar16) & *(uint *)(iVar29 + uVar22);
              puVar47 = (uint *)CONCAT11(bVar42,bVar34 & bVar42 &
                                                *(byte *)((int)&_streams[0xc].curp +
                                                         CONCAT11(bVar42,bVar34 & bVar42)));
              uVar52 = *puVar43;
              *(uint *)(iVar29 + uVar22) = *(uint *)(iVar29 + uVar22) ^ (uint)(puVar43 + 1);
              *(int *)(iVar29 + uVar22) = *(int *)(iVar29 + uVar22) - (int)(puVar43 + 1);
              bVar16 = in(uVar23);
              uVar22 = uVar22 & uVar23;
              puVar3 = (uint *)((int)puVar47 + (int)((char *)"+%d ring of prot." + 1 + uVar22));
              *puVar3 = *puVar3 & uVar31;
              *(uint *)(uVar31 + 0x21) = *(uint *)(uVar31 + 0x21) & (uint)puVar47;
              *puVar47 = *puVar47 & uVar31;
              puVar3 = (uint *)&AgntAnms[0x5c].sx;
              *puVar3 = *puVar3 & (uint)(puVar43 + 1);
              puVar3 = (uint *)((int)puVar47 + uVar22);
              *puVar3 = *puVar3 & CONCAT11((char)((uint)uVar52 >> 8),bVar16);
              bVar17 = -(0x99 < bVar16);
              return (far_t *)CONCAT11((char)((uint)uVar52 >> 8),
                                       bVar17 + (9 < (bVar17 & 0xf) | 9 < (bVar16 & 0xf) | in_AF) *
                                                '\x06' + (0x99 < bVar17 || 0x99 < bVar16) * '`');
            case (far_t *)0x1:
              *(uint *)(&stack0x8ed6 + (int)unaff_DI) =
                   *(uint *)(&stack0x8ed6 + (int)unaff_DI) & uVar23;
              return pfVar20;
            default:
              goto switchD_5000_123d_caseD_2;
            case (far_t *)0x3:
            case (far_t *)0x14:
              goto switchD_5000_123d_caseD_3;
            case (far_t *)0x4:
              puVar45 = (uint *)CONCAT11(uVar64,uVar65);
              if (uVar23 != 1) {
                puVar27 = (uint *)puVar36[-0xc52].y;
                puVar45 = (uint *)CONCAT11(uVar64,uVar65);
              }
              break;
            case (far_t *)0x5:
              do {
                uVar10 = *(undefined4 *)(((uint)pfVar20 & 0xff) << 2);
                uVar22 = (uint)*(byte *)((int)uVar10 + 0x2f);
                ovr_blitLabel((char *)auStackY_11a[(int)puVar47 * 2 + uVar22 * 8],
                              (uint8_t *)auStackY_11a[(int)puVar47 * 2 + uVar22 * 8 + 1],
                              CONCAT11(uVar64,uVar65),uVar66);
                while( true ) {
                  func_0x0005f303();
                  ovr_stsprintf(acStackY_13e,(char *)unaff_SS,(char *)"%d");
                  iVar29 = ovr_font_textWidth((char *)CONCAT13(uVar62,CONCAT12(bVar16,acStackY_13e))
                                              ,(char *)CONCAT13((char)(Font02.seg >> 8),
                                                                CONCAT12((char)Font02.seg,Font02.ofs
                                                                        )));
                  TextBlitX = 0x89 - iVar29;
                  ovr_blitLabel(acStackY_13e,(uint8_t *)unaff_SS,Font02.ofs,(uint8_t)Font02.seg);
                  ovr_stsprintf(acStackY_13e,(char *)unaff_SS,(char *)"%d");
                  iVar29 = ovr_font_textWidth((char *)CONCAT13(uVar62,CONCAT12(bVar16,acStackY_13e))
                                              ,(char *)CONCAT13((char)(Font02.seg >> 8),
                                                                CONCAT12((char)Font02.seg,Font02.ofs
                                                                        )));
                  puVar26 = (uint16_t *)(0xd4 - iVar29);
                  TextBlitX = (uint16_t)puVar26;
                  ovr_blitLabel(acStackY_13e,(uint8_t *)unaff_SS,Font02.ofs,(uint8_t)Font02.seg);
                  puVar47 = (uint *)((int)puVar47 + 1);
L_OVC22_5087_0234_323C:
                  TextBlitY = TextBlitY + 0xc;
                  cVar18 = (char)uVar23;
                  if ((int)(scratch >> 8) <= (int)puVar47) goto L_OVC22_5087_0234_32B8;
                  TextBlitX = 0x11;
                  if ((4 < (int)puVar47) && ((char)scratch != '\0')) break;
                  ovr_blitLabel((char *)auStackY_96[(int)puVar47 * 2],
                                (uint8_t *)auStackY_96[(int)puVar47 * 2 + 1],Font02.ofs,
                                (uint8_t)Font02.seg);
                }
                pfVar20 = (far_t *)(uint)partyIndex;
              } while( true );
            case (far_t *)0x6:
              *(uint *)(&stack0x681c + (int)puVar47) =
                   *(uint *)(&stack0x681c + (int)puVar47) & uVar23;
            case (far_t *)0xb:
              *(uint *)(&stack0x681c + (int)puVar47) =
                   *(uint *)(&stack0x681c + (int)puVar47) & uVar23;
              ovr_blitLabel(&stack0xfffe,(uint8_t *)CONCAT11(uVar64,uVar65),CONCAT11(uVar67,uVar66),
                            in_stack_0000ffb8);
              iVar29 = ovr_font_textWidth("POPULATION",
                                          (char *)CONCAT13((char)(Font02.seg >> 8),
                                                           CONCAT12((char)Font02.seg,Font02.ofs)));
              puVar26 = (uint16_t *)(0xd4 - iVar29);
              uVar66 = (uint8_t)Font02.ofs;
              uVar65 = 0x10;
              uVar64 = 0x24;
              TextBlitX = (uint16_t)puVar26;
              ovr_blitLabel((char *)"POPULATION",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                            (uint8_t)Font02.seg);
              puVar47 = (uint *)0x0;
              goto L_OVC22_5087_0234_323C;
            case (far_t *)0x7:
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
              return pfVar20;
            case (far_t *)0x8:
              bVar16 = (&stack0xfffe)[(int)unaff_DI];
              in_AF = 9 < (bVar15 & 0xf) | in_AF;
              uVar44 = (uint)&stack0xffb4 ^ *(uint *)((int)puVar47 + (int)(&puVar36->level + -1));
              uVar22 = (uint)puVar36 ^ (uint)puVar47;
              uVar31 = CONCAT11((byte)(uVar22 >> 8) ^ *(byte *)((int)unaff_DI + uVar22 + 0x8332),
                                (char)uVar22);
              bVar25 = bVar14 ^ 0x5d ^ *(byte *)((int)unaff_DI + uVar31 + 0x32);
              uVar22 = CONCAT11(bVar16,bVar25) ^ 0x1900;
              *(uint *)(&stack0xfffe + (int)puVar47) =
                   *(uint *)(&stack0xfffe + (int)puVar47) ^ (uint)puVar47;
              uVar46 = (int)puVar47 - *(int *)(&stack0xfffe + (int)puVar47);
              uVar31 = uVar31 ^ uVar44;
              uVar32 = (uint)&stack0xfffe ^ uVar31;
              uVar23 = CONCAT11(uVar19,bVar15 + in_AF * -6 + (0x99 < bVar15) * -0x60 + '2' +
                                       (puVar47 < *(uint **)(&stack0xfffe + (int)puVar47))) - 0x5ceU
                       ^ uVar23;
              puVar3 = (uint *)((int)unaff_DI + uVar31 + 0xa231);
              *puVar3 = *puVar3 ^ uVar46;
              *(uint *)((char *)"%s: %s %d gold. Provides housing for %d %s." + 3 + uVar31) =
                   *(uint *)((char *)"%s: %s %d gold. Provides housing for %d %s." + 3 + uVar31) ^
                   uVar22;
              puVar3 = (uint *)(uVar32 + uVar46 + 0x31);
              *puVar3 = *puVar3 ^ (uint)unaff_DI;
              iVar28 = uVar46 + 1;
              *(uint *)(uVar32 + (int)unaff_DI) = *(uint *)(uVar32 + (int)unaff_DI) ^ uVar44;
              *unaff_DI = *unaff_DI ^ uVar22;
              puVar49 = (undefined2 *)((uint)unaff_DI ^ uVar44);
              bVar41 = (byte)(uVar23 >> 8);
              bVar15 = (byte)uVar23 ^ bVar25;
              pbVar2 = (byte *)((int)puVar49 + uVar32 + 0xa330);
              *pbVar2 = *pbVar2 ^ bVar16 ^ 0x19;
              *(byte *)(puVar49 + -0x3be8) = *(byte *)(puVar49 + -0x3be8) ^ (byte)uVar31;
              pbVar2 = (byte *)(uVar31 + iVar28 + 0x30);
              bVar34 = (byte)(uVar31 >> 8);
              *pbVar2 = *pbVar2 ^ bVar34;
              pbVar6 = (byte *)(puVar49 + 1);
              uVar51 = in(uVar22);
              *puVar49 = uVar51;
              pbVar2 = (byte *)(uVar31 + iVar28 + 0x30);
              *pbVar2 = *pbVar2 ^ (byte)uVar31;
              *(uint *)(uVar44 - 2) = uVar22;
              *pbVar6 = *pbVar6 ^ bVar34;
              *pbVar6 = *pbVar6 ^ bVar14;
              *(byte *)(uVar32 + iVar28) = *(byte *)(uVar32 + iVar28) ^ bVar41;
              *pbVar6 = *pbVar6 ^ bVar17;
              *(byte *)(uVar32 + iVar28) = *(byte *)(uVar32 + iVar28) ^ bVar15;
              in_AF = 9 < (bVar15 & 0xf) | in_AF;
              bVar16 = bVar15 + in_AF * -6 + (0x99 < bVar15) * -0x60;
              iVar29 = *(int *)(uVar44 - 2);
              uVar23 = CONCAT11(bVar41 ^ bVar34,
                                bVar16 + (9 < (bVar16 & 0xf) | in_AF) * -6 +
                                (0x99 < bVar16 || 0x99 < bVar15) * -0x60) ^ 0xaf;
              uVar32 = uVar32 ^ uVar23;
              bVar16 = (byte)uVar23 ^ (byte)*(undefined2 *)(uVar31 + iVar28);
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              *(char *)(uVar31 + iVar28) = *(char *)(uVar31 + iVar28) + bVar16;
              pcVar1 = (char *)(iVar29 + -0x75);
              *pcVar1 = *pcVar1 + bVar25;
              in(uVar22);
              *(int *)(uVar44 - 0x10) = iVar28;
              *(int *)(uVar44 - 0x12) = iVar29;
              iVar29 = *(int *)(uVar32 + 6);
              iVar28 = *(int *)(uVar32 + 8);
              if ((((iVar29 < 0) || (iVar28 < 0)) || (0x93 < iVar29 + 1)) || (0x3b < iVar28 + 1)) {
                placementStatus = 2;
                pfVar20 = (far_t *)((char *)"arena" + 4);
              }
              else {
                uVar51 = (undefined2)((ulong)GMapFlags >> 0x10);
                if ((((*(short (*) [60] [148])GMapFlags)[iVar28][iVar29] & 3U) == 0) &&
                   (((*(short (*) [60] [148])GMapFlags)[iVar28 + 1][iVar29] & 3U) == 0)) {
                  *(int *)(uVar32 - 10) =
                       (int)(char)(*(byte (*) [59] [148])GMapCells)[iVar28 + 1][iVar29];
                  *(int *)(uVar32 - 8) =
                       (int)(char)(*(byte (*) [59] [148])GMapCells)[iVar28 + 1][iVar29 + 1];
                  iVar29 = *(int *)(uVar32 - 10);
                  *(undefined2 *)(uVar32 - 2) = *(undefined2 *)(uVar32 - 10);
                  if (*(int *)(uVar32 - 8) < iVar29) {
                    iVar29 = *(int *)(uVar32 - 8);
                  }
                  if (*(int *)(uVar32 - 2) < *(int *)(uVar32 - 8)) {
                    *(undefined2 *)(uVar32 - 2) = *(undefined2 *)(uVar32 - 8);
                  }
                  uVar23 = *(int *)(uVar32 - 2) - iVar29;
                  if ((int)uVar23 < 9) {
                    placementStatus = 3;
                    pfVar20 = (far_t *)((char *)"arena" + 5);
                  }
                  else {
                    pfVar20 = (far_t *)(uVar23 & 0xff00);
                  }
                }
                else {
                  placementStatus = 1;
                  pfVar20 = (far_t *)((char *)"arena" + 4);
                }
              }
              return pfVar20;
            case (far_t *)0x9:
              do {
                ovc22_textRingProt((byte)pfVar20);
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
                pfVar20 = (far_t *)CONCAT11(0x21,(undefined1)uStack_16);
              } while( true );
            case (far_t *)0xa:
              iVar28 = 0x6574;
              puVar45 = (uint *)CONCAT11(uVar64,uVar65);
              break;
            case (far_t *)0xc:
              (*(uint8_t *)((uint8_t *)&(iVar29))) = (puVar36 + -0xc24)->bldType;
              (*(uint8_t *)((uint8_t *)&(iVar29) + 1)) = (puVar36 + -0xc24)->level;
              do {
                pfVar20 = (far_t *)uStack_6;
                if (puVar35[iVar29].unitType == partyIndex) {
                  if ((byte)uStack_6 == (*(uint8_t *)((uint8_t *)&(uStack_6) + 1))) {
L_OVC22_5087_4975_4ABE:
                    (*(uint16_t *)((uint8_t *)&(uStack_6))) = pfVar20;
                    if ((byte)uStack_8 < ListCount) {
                      puStack_a = (uint *)puVar35[*(int *)((uStack_8 & 0xff) * 2 + -0x6d44)].x;
                      scratch = puVar35[*(int *)((uStack_8 & 0xff) * 2 + -0x6d44)].y;
                    }
                    else {
                      puStack_a = (uint *)*(uint16_t *)
                                           ((int)*(undefined4 *)((uint)partyIndex << 2) + 0x39);
                      scratch = *(uint16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3b);
                    }
                    uVar51 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
                    iVar28 = (int)*(undefined4 *)((uint)partyIndex << 2);
                    iVar29 = *(int *)(iVar28 + 0x58);
                    if ((iVar29 < 1) && ((iVar29 < 0 || (*(uint *)(iVar28 + 0x56) < 10)))) {
                      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(far_t *)uStack_6);
                    }
                    else {
                      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((far_t *)uStack_6);
                    }
                    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                                  (uint)*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3e
                                                 ) * 0x95) & 0x80) == 0) {
                      uStack_6 = (far_t *)(ulong)(uint3)uStack_6;
                    }
                    else {
                      uStack_6 = (far_t *)CONCAT13(3,(uint3)uStack_6);
                    }
                    if ((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 2) != 0) {
                      uStack_6 = (far_t *)((ulong)uStack_6 | 0x1000000);
                    }
                    if ((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 4) != 0) {
                      uStack_6 = (far_t *)((ulong)uStack_6 | 0x2000000);
                    }
                    uVar23 = ovc22_searchCellsAround
                                       ((uint *)&puStack_a,unaff_SS,(byte)&scratch,bVar16,partyIndex
                                       );
                    pfVar20 = (far_t *)(uVar23 & 0xff);
                    if (pfVar20 != (far_t *)0x0) {
                      if (pfVar20 != (far_t *)((int)(undefined4 *)&_DATA + 1U)) {
                        return pfVar20;
                      }
                      uStack_e = (uint *)ovc22_usesRandBelow(partyIndex,(uint16_t)puStack_a,scratch)
                      ;
                      if (uStack_e == (uint *)0x0) {
                        puStack_a = (uint *)*(uint16_t *)
                                             ((int)*(undefined4 *)((uint)partyIndex << 2) + 0x39);
                        scratch = *(uint16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3b);
                      }
                      else {
                        if ((*(uint *)((int)uStack_e * 0x27 + 0x121) & 0x60) == 0) {
                          uVar51 = (undefined2)
                                   ((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
                          iVar28 = (int)*(undefined4 *)((uint)partyIndex << 2);
                          iVar29 = *(int *)(iVar28 + 0x58);
                          if ((iVar29 < 0) ||
                             ((iVar29 == 0 &&
                              (*(uint *)(iVar28 + 0x56) < *(uint *)((int)uStack_e * 0x27 + 0x125))))
                             ) {
                            uVar51 = (undefined2)
                                     ((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
                            iVar29 = (int)*(undefined4 *)((uint)partyIndex << 2);
                            *(undefined2 *)(iVar29 + 0x58) = 0;
                            *(undefined2 *)(iVar29 + 0x56) = 0;
                          }
                          else {
                            uVar22 = *(uint *)((int)uStack_e * 0x27 + 0x125);
                            uVar51 = (undefined2)
                                     ((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
                            iVar29 = (int)*(undefined4 *)((uint)partyIndex << 2);
                            puVar3 = (uint *)(iVar29 + 0x56);
                            uVar23 = *puVar3;
                            *puVar3 = *puVar3 - uVar22;
                            piVar4 = (int *)(iVar29 + 0x58);
                            *piVar4 = *piVar4 - (uint)(uVar23 < uVar22);
                          }
                        }
                        ovr_createConstructionRecordFar
                                  ((byte)uStack_e,(int)puStack_a,scratch,(uint8_t *)_bStack0006,
                                   in_stack_00000008,partyIndex);
                      }
                    }
                    if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3f) == '\0') {
                      if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5b) <
                          *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d)) {
                        pfVar20 = (far_t *)ovr_ovc18_textTypeLen
                                                     (partyIndex,(uint16_t)puStack_a,scratch,0x1);
                      }
                      else {
                        pfVar20 = (far_t *)ovr_ovc18_textTypeLen
                                                     (partyIndex,(uint16_t)puStack_a,scratch,0x0);
                      }
                    }
                    else {
                      pfVar20 = (far_t *)ovr_ovc18_textTypeLen(partyIndex,0,0,0x0);
                    }
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
                    return pfVar20;
                  }
                  uStack_6 = (far_t *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),(byte)uStack_6 + '\x01');
                }
                do {
                  bVar17 = (byte)uStack_8 + 1;
                  uStack_8 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_8) + 1)),bVar17);
                  pfVar20 = (far_t *)uStack_6;
                  if (ListCount <= bVar17) goto L_OVC22_5087_4975_4ABE;
                } while (*(char *)((uint)(puVar35 + *(int *)((uint)bVar17 * 2 + -0x6d44))->bldType *
                                   0x27 + 0x133) != '\x12');
                iVar29 = *(int *)((uint)bVar17 * 2 + -0x6d44);
              } while( true );
            case (far_t *)0xd:
              bVar16 = (byte)((uint)puVar36 >> 8);
              if (!CARRY1(bVar16,bVar16) && ((uint)puVar36 & 0x7f00) != 0) {
                uVar23 = ovr_ovc23_findRecordAt((int)unaff_DI,CONCAT11(uVar64,uVar65));
                if (uVar23 == 0xffff) {
                  pfVar20 = (far_t *)(uint)((unit_t *)GUnits + (*(uint16_t *)((uint8_t *)&(uStack_6) + 2)))->bldType;
                  if ((*(uint *)((int)pfVar20 * 0x27 + 0x121) & 0x20) == 0) {
                    pfVar20 = (far_t *)0x0;
                  }
                  else if (*(char *)((int)pfVar20 * 0x27 + 0x131) == '\0') {
                    if (*(char *)((int)*(undefined4 *)((uint)in_stack_00000008 << 2) + 0x2f) ==
                        '\x05') {
                      pfVar20 = pfVar20 + 6;
                    }
                    else {
                      pfVar20 = (far_t *)&pfVar20[1].seg;
                    }
                  }
                }
                else {
                  pfVar20 = (far_t *)0x0;
                }
                return pfVar20;
              }
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            case (far_t *)0xe:
              uVar51 = CONCAT11(uVar67,uVar66);
              puVar36->bldType = puVar36->bldType | bVar15;
              if (uVar23 != 0) {
                pfVar20 = (far_t *)*(far_t **)((char *)"sage" + 3);
              }
              *(uint *)((char *)"squares" + 3) = *(uint *)((char *)"squares" + 3) ^ (uint)pfVar20;
              uVar19 = in(5);
              if (((uint)pfVar20 | 0x606) == 0) {
                *unaff_DI = *unaff_DI +
                            ((CONCAT11((char)(((uint)pfVar20 | 0x606) >> 8),uVar19) + 0x53e) -
                            *unaff_DI);
              }
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            case (far_t *)0xf:
              do {
                uVar51 = (undefined2)((ulong)Entities >> 0x10);
                uVar23 = CONCAT11(uVar64,uVar65) -
                         *(uint16_t *)
                          ((int)&(((entity_t *)Entities)->base).x +
                          CONCAT11((char)((int)pfVar20 % (int)(char)(&stack0x0035)[(int)puVar47]),
                                   (char)((int)pfVar20 / (int)(char)(&stack0x0035)[(int)puVar47])) *
                          iVar28);
                uVar31 = (int)uVar23 >> 0xf;
                uVar22 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b) -
                         ((entity_t *)Entities)[scratch].base.y;
                uVar32 = (int)uVar22 >> 0xf;
                puVar47 = (uint *)((int)((uVar23 ^ uVar31) - uVar31) / 2 +
                                  ((uVar22 ^ uVar32) - uVar32));
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
                             (uVar23 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x39) -
                                       *(int *)((int)*(undefined4 *)(scratch << 2) + 0x39),
                             uVar31 = (int)uVar23 >> 0xf,
                             uVar22 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b) -
                                      *(int *)((int)*(undefined4 *)(scratch << 2) + 0x3b),
                             uVar32 = (int)uVar22 >> 0xf,
                             puVar47 = (uint *)((int)((uVar23 ^ uVar31) - uVar31) / 2 +
                                               ((uVar22 ^ uVar32) - uVar32)), puVar47 < puStack_10))
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
                          for (puStack_a = (uint *)0x0; pfVar20 = (far_t *)(uint)GLeaderCount,
                              (int)puStack_a < (int)pfVar20;
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
                                uVar23 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x39)
                                         - (((entity_t *)Entities + (int)unaff_DI)->base).x;
                                uVar31 = (int)uVar23 >> 0xf;
                                uVar22 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b)
                                         - ((entity_t *)Entities)[(int)unaff_DI].base.y;
                                uVar32 = (int)uVar22 >> 0xf;
                                uStack_14 = (far_t *)((int)((uVar23 ^ uVar31) - uVar31) / 2 +
                                                     ((uVar22 ^ uVar32) - uVar32));
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
                                    bVar16 = *(byte *)((int)*(undefined4 *)((int)puStack_a << 2) +
                                                      0x3e);
                                    uStack_18 = CONCAT11(bVar16,(undefined1)uStack_18);
                                    iVar29 = ovc25_compute1(bVar16);
                                    uStack_6 = (far_t *)CONCAT22(iVar29,(far_t *)uStack_6);
                                    if ((int)(uint)PlayerCount < iVar29) {
                                      uVar30 = ovr_randBelow(0x28);
                                      pfVar20 = (far_t *)(*(int *)((int)*(undefined4 *)
                                                                         ((int)puStack_a << 2) +
                                                                  0x39) + -0x14 + (uVar30 & 0xff));
                                      (*(uint16_t *)((uint8_t *)&(uStack_6))) = pfVar20;
                                      if ((int)pfVar20 < 4) {
                                        (*(uint16_t *)((uint8_t *)&(uStack_6))) = (far_t *)__C0_ASM_CopyRight;
                                      }
                                      if (0x8c < (int)(far_t *)uStack_6) {
                                        (*(uint16_t *)((uint8_t *)&(uStack_6))) = (far_t *)&_brklvl;
                                      }
                                      uVar30 = ovr_randBelow(0x14);
                                      uStack_8 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2)
                                                         + 0x3b) + -10 + (uVar30 & 0xff);
                                      if ((int)uStack_8 < 1) {
                                        uStack_8 = 1;
                                      }
                                      if (0x3a < (int)uStack_8) {
                                        uStack_8 = 0x3a;
                                      }
                                      ovc25_usesAlignUp44((char)puStack_a,1,
                                                          (uint16_t)(far_t *)uStack_6,uStack_8);
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
                                      uVar10 = *(undefined4 *)(((uint)uStack_16 >> 8) << 2);
                                      ovr_alignUp4(*(int *)((int)uVar10 + 0x39));
                                      uVar30 = 0x195d;
                                      uStackY_60 = 0xc5d4;
                                      pcVar21 = ovr_stsprintf(acStackY_68,(char *)unaff_SS,
                                                              (char *)
                                                  "Spies report %s heading towards stronghold. (%d, %d)"
                                                  );
                                      ovr_uiNotify(pcVar21,uVar30);
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
                          return pfVar20;
                        }
                      } while (*(char *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x3d) == '\0');
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x47) = 0;
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x41) = 0;
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x43) = 0;
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x45) = 0;
                      uStack_e = (uint *)0xffff;
                      unaff_DI = (uint *)0xffff;
                      puStack_12 = (uint *)ovr_alignUp4(*(int *)((int)*(undefined4 *)
                                                                       ((int)puStack_a * 4) + 0x39))
                      ;
                      scratch = 0;
                    }
                    uVar51 = (undefined2)((ulong)Entities >> 0x10);
                    peVar39 = (entity_t *)Entities;
                    if ((uint *)(uint)*(byte *)((int)&peVar39[scratch].base.entity + 3) != puStack_a
                       ) break;
                    uVar23 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x39) -
                             ((peVar39 + scratch)->base).x;
                    uVar31 = (int)uVar23 >> 0xf;
                    uVar22 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b) -
                             peVar39[scratch].base.y;
                    uVar32 = (int)uVar22 >> 0xf;
                    puVar47 = (uint *)((int)((uVar23 ^ uVar31) - uVar31) / 2 +
                                      ((uVar22 ^ uVar32) - uVar32));
                    piVar4 = (int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x45);
                    *piVar4 = *piVar4 + 1;
                    if (puVar47 < (byte *)__C0_ASM_CopyRight + 6) {
                      piVar4 = (int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x41);
                      *piVar4 = *piVar4 + 1;
                      uVar51 = (undefined2)((ulong)Entities >> 0x10);
                      if ((*(uint16_t *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b) ==
                           ((entity_t *)Entities)[scratch].base.y) &&
                         (puVar48 = (uint *)ovr_alignUp4((((entity_t *)Entities + scratch)->base).x)
                         , puVar48 == puStack_12)) {
                        piVar4 = (int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x47);
                        *piVar4 = *piVar4 + 1;
                      }
                    }
                  }
                } while (*(char *)((int)(char **)GMenuStrings +
                                  (uint)peVar39[scratch].base.gindex * 0x95 + 0x1f) ==
                         *(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3f));
                uVar51 = *(undefined2 *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x39);
                uVar65 = (undefined1)uVar51;
                uVar64 = (undefined1)((uint)uVar51 >> 8);
                iVar28 = 0x37;
                pfVar20 = (far_t *)scratch;
              } while( true );
            case (far_t *)0x10:
              puVar26 = &unitNameOfs;
              manage_applyUnitFilter
                        (partyIndex,((uint)uStack_e >> 8) - 4,
                         (char *)CONCAT13((char)((uint)*(undefined2 *)
                                                        (acStackY_68 + ((uint)pfVar20 & 0xff) * 4)
                                                >> 8),
                                          CONCAT12((char)*(undefined2 *)
                                                          (acStackY_68 + ((uint)pfVar20 & 0xff) * 4)
                                                   ,puVar26[((uint)pfVar20 & 0xff) * 2])));
              cVar18 = (char)uVar23;
L_OVC22_5087_0234_32B8:
              CurSfxType3 = 0x3c;
              (*(uint8_t *)((uint8_t *)&(entries.seg))) = bVar16;
              entries.ofs = (uint16_t)(acStackY_68 + 2);
              (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar62;
              uVar51 = ovr_ovc28_usesUiInputText
                                 (entries,(uint16_t)unaff_DI,far_from_u32((uint32_t)(0x0)),(uint8_t *)&uStack_e,
                                  (uint16_t)unaff_SS);
              cVar13 = (char)uVar51;
              uStack_e = (uint *)CONCAT11(cVar13,(byte)uStack_e);
              keyboardInputMode = 0;
              if (((cVar13 != '\0') && (cVar13 != '\x01')) && (cVar13 != -2)) {
                (&stack0xbac4)[(int)unaff_DI] = (&stack0xbac4)[(int)unaff_DI] + cVar18;
                puVar48 = (uint *)((char *)"puppetmaker" + 3);
                do {
                  iVar29 = (int)puVar48 * (int)puVar26;
                  puVar48 = puVar47;
                  if (*(byte *)((int)puVar47 * 0x34 + 0x22) < *(byte *)(iVar29 + 0x21)) {
                    *(undefined1 *)((int)puVar47 * 0x34 + 0x21) =
                         *(undefined1 *)((int)puVar47 * 0x34 + 0x22);
                  }
                  do {
                    puVar48 = (uint *)((int)puVar48 + 1);
                    if ((int)(uint)AgntCount <= (int)puVar48) {
                      uVar30 = ovr_audio_panFromX((agnt_t *)
                                                  CONCAT13((char)((uint)in_stack_0000000a >> 8),
                                                           CONCAT12((char)in_stack_0000000a,
                                                                    CONCAT11(in_stack_00000009,
                                                                             in_stack_00000008))));
                      ovr_play_sfxU(0x1c,0,uVar30);
                      return (far_t *)CONCAT11((char)(uVar30 >> 8),1);
                    }
                  } while (*(int *)((int)puVar48 * 0x34 + 0x1b) !=
                           *(int *)(CONCAT11(in_stack_00000009,in_stack_00000008) + 0x1b));
                  uVar51 = (undefined2)((ulong)uStack_6 >> 0x10);
                  if ((byte)((far_t *)uStack_6)[0xc].seg < *(byte *)((int)puVar48 * 0x34 + 0x22)) {
                    *(undefined1 *)((int)puVar48 * 0x34 + 0x22) = (char)((far_t *)uStack_6)[0xc].seg
                    ;
                  }
                  puVar26 = (uint16_t *)((char *)"Divide error\r\n" + 5);
                  puVar47 = puVar48;
                } while( true );
              }
              if (cVar13 != -2) {
                keyboardInputMode = 0;
                return (far_t *)((char *)"puppetmaker" + 3);
              }
              Cancelled = 1;
              keyboardInputMode = 0;
              return (far_t *)((char *)"puppetmaker" + 3);
            case (far_t *)0x11:
              GRecordCount = GRecordCount + -1;
              _fmemset((void *)(GRecordCount * 0x12),0x21f2,0);
              *(byte *)(GRecordCount * 0x12 + 8) = partyIndex;
              *(uint16_t *)(GRecordCount * 0x12 + 2) = (uint16_t)_bStack0006;
              *(undefined2 *)(GRecordCount * 0x12 + 4) =
                   CONCAT11(in_stack_00000009,in_stack_00000008);
              *(byte *)(GRecordCount * 0x12 + 9) = in_stack_0000000e;
              iVar29 = ovc23_isLargeBuilding
                                 ((int)_bStack0006,CONCAT11(in_stack_00000009,in_stack_00000008));
              uVar51 = (undefined2)((ulong)GUnitGrid >> 0x10);
              uVar52 = (undefined2)((ulong)GUnits >> 0x10);
              if ((char)iVar29 == '\0') {
                bVar16 = ((unit_t *)GUnits +
                         (*(short (*) [148] [60])GUnitGrid)[(int)_bStack0006]
                         [CONCAT11(in_stack_00000009,in_stack_00000008)])->bldType;
              }
              else {
                bVar16 = ((unit_t *)GUnits +
                         (*(short (*) [148] [60])GUnitGrid)[(int)((int)&_bStack0006[-1].seg + 1)]
                         [CONCAT11(in_stack_00000009,in_stack_00000008)])->bldType;
              }
              cVar18 = *(char *)((uint)bVar16 * 0x27 + 0x11d);
              (*(uint32_t *)((uint8_t *)&(uStack_6))) =
                   CONCAT12(*(undefined1 *)((uint)bVar16 * 0x27 + 0x11b),
                            CONCAT11(bVar16,(byte)uStack_6));
              uStack_6 = (far_t *)CONCAT13(cVar18,(uint3)uStack_6);
              if (cVar18 == '\0') {
                uStack_6 = (far_t *)CONCAT13(1,(uint3)uStack_6);
              }
              if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) < *(byte *)((uint)partyIndex * 0x27 + 0x11c)) {
                *(undefined1 *)(GRecordCount * 0x12 + 6) =
                     *(undefined1 *)((uint)partyIndex * 0x27 + 0x11c);
              }
              else {
                *(byte *)(GRecordCount * 0x12 + 6) = (*(uint8_t *)((uint8_t *)&(uStack_6) + 3));
              }
              *(undefined2 *)(GRecordCount * 0x12 + 0xf) = GameTick;
              *(undefined2 *)(GRecordCount * 0x12) = 0;
              uVar51 = ovc23_usesGRecordCount3
                                 (*(byte *)((uint)partyIndex * 0x27 + 0x120),in_stack_0000000e,
                                  GRecordCount);
              *(undefined1 *)(GRecordCount * 0x12 + 0xc) = (char)uVar51;
              if (*(char *)(GRecordCount * 0x12 + 0xc) == '\0') {
                *(undefined1 *)(GRecordCount * 0x12 + 0xc) = 1;
              }
              if (partyIndex == 0) {
                iVar29 = ovc23_isLargeBuilding
                                   ((int)_bStack0006,CONCAT11(in_stack_00000009,in_stack_00000008));
                if ((char)iVar29 != '\0') {
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
                     *(undefined1 *)((uint)partyIndex * 0x27 + 0x11b);
                if (in_stack_00000010 != '\0') {
                  ovc23_placeBuilding((int)_bStack0006,CONCAT11(in_stack_00000009,in_stack_00000008)
                                      ,0,in_stack_0000000e);
                  uVar51 = ovr_ovc22_usesGOngoingBattle(bStack0006,in_stack_00000008);
                  if ((char)uVar51 != '\0') {
                    *(undefined1 *)&((brect_t *)CONCAT22(in_stack_0000000c,in_stack_0000000a))->x =
                         1;
                  }
                }
                *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 0;
              }
              *(undefined1 *)(GRecordCount * 0x12 + 0x11) = 0;
              *(undefined1 *)(GRecordCount * 0x12 + 0xb) =
                   *(undefined1 *)(GRecordCount * 0x12 + 0xc);
              iVar29 = GRecordCount;
              GRecordCount = GRecordCount + 1;
              ovc23_abandonConstruction(iVar29);
              pfVar20 = (far_t *)ovc23_textAdlibNone(in_stack_0000ffbe,in_stack_0000ffc0,agnt);
              return pfVar20;
            case (far_t *)0x12:
              GRecordCount = GRecordCount + -1;
              pfVar20 = (far_t *)ovc23_textAdlibNone(CONCAT11(uVar64,uVar65),CONCAT11(uVar67,uVar66)
                                                     ,(agnt_t *)
                                                      CONCAT13((char)((uint)iVar29 >> 8),
                                                               CONCAT12(uVar68,CONCAT11(
                                                  in_stack_0000ffb9,in_stack_0000ffb8))));
              return pfVar20;
            case (far_t *)0x15:
              uVar30 = 0x195d;
              pcVar21 = ovr_fmVsprintf((char *)
                                       "Intelligence reports %s unit infected with disease. (%d, %d)"
                                       ,(char *)"puppetmaker" + 3);
              ovr_uiNotify(pcVar21,uVar30);
              pfVar20 = (far_t *)((uint)((entity_t *)Entities)[(int)puStack_a].base.gindex * 0x95);
              if (((pfVar20 + 0x9c5)->ofs & 0xc00) != 0) {
                uVar23 = ovr_ovc27_rollToHitAgent
                                   (CONCAT13((char)((ulong)Entities >> 0x18),
                                             CONCAT12((char)((ulong)Entities >> 0x10),
                                                      (entity_t *)Entities + (int)unaff_DI)),3);
                pfVar20 = (far_t *)(uVar23 & 0xff);
                if (pfVar20 == (far_t *)0x0) {
                  if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                                (uint)((entity_t *)Entities)[(int)puStack_a].base.gindex * 0x95) &
                      0x800) == 0) {
                    puStack_12 = (uint *)CONCAT11((*(uint8_t *)((uint8_t *)&(puStack_12) + 1)),1);
                  }
                  else {
                    puStack_12 = (uint *)CONCAT11((*(uint8_t *)((uint8_t *)&(puStack_12) + 1)),2);
                  }
                  uVar51 = ovr_ovc27_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                                       CONCAT12((char)((ulong)Entities >> 0x10),
                                                                (entity_t *)Entities + (int)unaff_DI
                                                               )),(char)puStack_12);
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
                  alignUp4((((entity_t *)Entities + (int)puVar47)->base).x);
                  uVar30 = 0x195d;
                  pfVar20 = (far_t *)ovr_fmVsprintf((char *)
                                                  "Intelligence reports %s unit drained of energy. (%d, %d)"
                                                  ,(char *)"puppetmaker" + 3);
                  ovr_uiNotify((char *)pfVar20,uVar30);
                }
              }
              return pfVar20;
            }
            do {
              uVar51 = *(undefined2 *)((int)(undefined2 *)&tmstrsSprites3Seg + iVar28);
              (*(uint8_t *)((uint8_t *)&(gfx_05.seg))) = (char)uVar51;
              gfx_05.ofs = *(undefined2 *)((int)(undefined2 *)&tmstrsSprites3Ofs + iVar28);
              (*(uint8_t *)((uint8_t *)&(gfx_05.seg) + 1)) = (char)((uint)uVar51 >> 8);
              ovr_blitGfxRect(gfx_05,(int16_t)puVar27,(int16_t)puVar45,
                              (brect_t *)CONCAT11(uVar67,uVar66),in_stack_0000ffb8,(bool)uVar68);
              (*(uint8_t *)((uint8_t *)&(gfx_06.seg))) = (char)((undefined2 *)&tmstrsSprites3Seg)[((uint)unaff_DI % 7) * 2];
              gfx_06.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[((uint)unaff_DI % 7) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_06.seg) + 1)) =
                   (char)((uint)((undefined2 *)&tmstrsSprites3Seg)[((uint)unaff_DI % 7) * 2] >> 8);
              ovr_blitGfxRect(gfx_06,(int16_t)(puVar48 + 4),(int16_t)(puStack_a + -3),
                              in_stack_0000000a,(uint8_t)in_stack_0000000c,true);
              (*(uint8_t *)((uint8_t *)&(gfx_07.seg))) =
                   (char)((undefined2 *)&tmstrsSprites3Seg)[((uint)(unaff_DI + 1) % 7) * 2];
              gfx_07.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[((uint)(unaff_DI + 1) % 7) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_07.seg) + 1)) =
                   (char)((uint)((undefined2 *)&tmstrsSprites3Seg)[((uint)(unaff_DI + 1) % 7) * 2]
                         >> 8);
              ovr_blitGfxRect(gfx_07,(int16_t)(puVar48 + 0xd),(int16_t)(puStack_a + -3),
                              in_stack_0000000a,(uint8_t)in_stack_0000000c,true);
              uVar23 = (uint)((int)unaff_DI + 3) & 7;
              (*(uint8_t *)((uint8_t *)&(gfx_08.seg))) = (char)((undefined2 *)&tmstrsSprites2Seg)[uVar23 * 2];
              gfx_08.ofs = ((undefined2 *)&tmstrsSprites2Ofs)[uVar23 * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_08.seg) + 1)) = (char)((uint)((undefined2 *)&tmstrsSprites2Seg)[uVar23 * 2] >> 8);
              ovr_blitGfxRect(gfx_08,(int16_t)(puVar48 + 0x12),(int16_t)(puStack_a + -3),
                              in_stack_0000000a,(uint8_t)in_stack_0000000c,true);
              (*(uint8_t *)((uint8_t *)&(gfx_09.seg))) = (char)((undefined2 *)&tmstrsSprites2Seg)[((uint)unaff_DI & 7) * 2];
              gfx_09.ofs = ((undefined2 *)&tmstrsSprites2Ofs)[((uint)unaff_DI & 7) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_09.seg) + 1)) =
                   (char)((uint)((undefined2 *)&tmstrsSprites2Seg)[((uint)unaff_DI & 7) * 2] >> 8);
              ovr_blitGfxRect(gfx_09,(int16_t)(puVar47 + 0xf),(int16_t)(puStack_a + -3),
                              in_stack_0000000a,(uint8_t)in_stack_0000000c,true);
              (*(uint8_t *)((uint8_t *)&(gfx_10.seg))) = (char)((undefined2 *)&tmstrsSprites1Seg)[((uint)unaff_DI % 5) * 2];
              gfx_10.ofs = ((undefined2 *)&tmstrsSprites1Ofs)[((uint)unaff_DI % 5) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_10.seg) + 1)) =
                   (char)((uint)((undefined2 *)&tmstrsSprites1Seg)[((uint)unaff_DI % 5) * 2] >> 8);
              ovr_blitGfxRect(gfx_10,(int16_t)(puVar47 + 10),(int16_t)(puStack_a + -3),
                              in_stack_0000000a,(uint8_t)in_stack_0000000c,true);
              pfVar20 = (far_t *)((char *)"puppetmaker" + 3);
              (*(uint8_t *)((uint8_t *)&(gfx_11.seg))) = (char)((undefined2 *)&tmstrsSprites1Seg)[((uint)unaff_DI % 5) * 2];
              gfx_11.ofs = ((undefined2 *)&tmstrsSprites1Ofs)[((uint)unaff_DI % 5) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_11.seg) + 1)) =
                   (char)((uint)((undefined2 *)&tmstrsSprites1Seg)[((uint)unaff_DI % 5) * 2] >> 8);
              ovr_blitGfxRect(gfx_11,(int16_t)(puVar47 + 0x10),(int16_t)(puStack_a + -3),
                              in_stack_0000000a,(uint8_t)in_stack_0000000c,true);
              while( true ) {
                while( true ) {
                  scratch = scratch - 1;
                  if ((int)scratch < 0) {
                    return pfVar20;
                  }
                  pcVar21 = (char *)(scratch + GfxRndSeed2 + ((uint)unaff_DI >> 5));
                  puVar27 = (uint *)((int)puStack_a + 0x13);
                  uVar66 = (uint8_t)in_stack_0000000c;
                  if (((*(uint8_t *)((uint8_t *)&(uStack_14) + 1)) == 2) || ((byte *)__C0_ASM_CopyRight + 0xf < unaff_DI))
                  break;
                  if (((char *)((int)puStack_12 + -1) == (char *)scratch) &&
                     (unaff_DI <= (byte *)__C0_ASM_CopyRight + 8)) {
                    uStack_8 = ((undefined2 *)&csite1Ofs)[(int)unaff_DI * 2];
                    pfVar20 = (far_t *)((undefined2 *)&csite1Seg)[(int)unaff_DI * 2];
                  }
                  else {
                    uStack_8 = csite1_12Ofs;
                    pfVar20 = csite1_12Seg;
                  }
                  uStack_6 = (far_t *)CONCAT22(pcVar21,pfVar20);
                  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)pfVar20;
                  gfx.ofs = uStack_8;
                  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)pfVar20 >> 8);
                  puStack_a = puVar27;
                  ovr_blitGfxRect(gfx,(int16_t)puVar47,(int16_t)puVar27,in_stack_0000000a,uVar66,
                                  true);
                }
                if ((*(uint8_t *)((uint8_t *)&(uStack_14) + 1)) < 2) break;
                if ((byte *)__C0_ASM_CopyRight + 5 < unaff_DI) {
                  uStack_8 = csite1_22Ofs;
                  pfVar20 = csite1_22Seg;
                }
                else {
                  uStack_8 = ((undefined2 *)&csite1Ofs)[(int)(unaff_DI + 6) * 2];
                  pfVar20 = (far_t *)((undefined2 *)&csite1Seg)[(int)(unaff_DI + 6) * 2];
                }
                uStack_6 = (far_t *)CONCAT22(pcVar21,pfVar20);
                (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)pfVar20;
                gfx_00.ofs = uStack_8;
                (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)pfVar20 >> 8);
                puStack_a = puVar27;
                ovr_blitGfxRect(gfx_00,(int16_t)puVar47,(int16_t)puVar27,in_stack_0000000a,uVar66,
                                true);
              }
              uStack_6 = (far_t *)CONCAT22(pcVar21,csite1_12Seg);
              uStack_8 = csite1_12Ofs;
              if ((char *)scratch == (char *)0x0) {
                puVar45 = puStack_a + 0x11;
                uVar23 = (uint)((int)unaff_DI + GfxRndSeed2) % 0xe;
                (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = (char)((undefined2 *)&tmstrsSprites6Seg)[uVar23 * 2];
                gfx_01.ofs = ((undefined2 *)&tmstrsSprites6Ofs)[uVar23 * 2];
                (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = (char)((uint)((undefined2 *)&tmstrsSprites6Seg)[uVar23 * 2] >> 8)
                ;
                puStack_a = puVar27;
                ovr_blitGfxRect(gfx_01,(int16_t)(puVar48 + 8),(int16_t)puVar45,in_stack_0000000a,
                                uVar66,true);
                puVar27 = puStack_a;
              }
              puStack_a = puVar27;
              (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)uStack_6;
              gfx_02.ofs = uStack_8;
              (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = (char)((ulong)uStack_6 >> 8);
              ovr_blitGfxRect(gfx_02,(int16_t)puVar47,(int16_t)puStack_a,in_stack_0000000a,
                              (uint8_t)in_stack_0000000c,true);
              if (((uint)((char *)((int)unaff_DI + GfxRndSeed2 + scratch) + (int)puVar47) & 0x1f) <
                  0x11) {
                uVar23 = ((uint)((char *)((int)unaff_DI + GfxRndSeed2 + scratch) + (int)puVar47) >>
                         5) + scratch + GfxRndSeed2;
                uStack_6 = (far_t *)CONCAT22(uVar23,(far_t *)uStack_6);
                uStack_e = (uint *)((int)((uint)*(byte *)(uVar23 & 0xff) * 0x25) >> 8);
                uVar23 = (uint)((char *)((int)unaff_DI + GfxRndSeed2 + scratch) + (int)puVar47) &
                         0x1f;
                (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = (char)((undefined2 *)&tmstrsSprites5Seg)[uVar23 * 2];
                gfx_03.ofs = ((undefined2 *)&tmstrsSprites5Ofs)[uVar23 * 2];
                (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) = (char)((uint)((undefined2 *)&tmstrsSprites5Seg)[uVar23 * 2] >> 8)
                ;
                ovr_blitGfxRect(gfx_03,(int16_t)((char *)((int)puVar47 + (int)uStack_e) + 3),
                                (int16_t)((int)puStack_a + -3),in_stack_0000000a,
                                (uint8_t)in_stack_0000000c,true);
              }
              if (((uint)((int)unaff_DI + ((scratch - GfxRndSeed2) - (int)puVar47)) & 0xf) < 7) {
                iVar29 = (((uint)((int)unaff_DI + ((scratch - GfxRndSeed2) - (int)puVar47)) >> 4) +
                         scratch) - GfxRndSeed2;
                uStack_6 = (far_t *)CONCAT22(iVar29,(far_t *)uStack_6);
                uStack_e = (uint *)((int)((uint)*(byte *)(iVar29 + 0xeU & 0xff) * 0x25) >> 8);
                uVar23 = (uint)((int)unaff_DI + ((scratch - GfxRndSeed2) - (int)puVar47)) & 0xf;
                (*(uint8_t *)((uint8_t *)&(gfx_04.seg))) = (char)((undefined2 *)&tmstrsSprites4Seg)[uVar23 * 2];
                gfx_04.ofs = ((undefined2 *)&tmstrsSprites4Ofs)[uVar23 * 2];
                (*(uint8_t *)((uint8_t *)&(gfx_04.seg) + 1)) = (char)((uint)((undefined2 *)&tmstrsSprites4Seg)[uVar23 * 2] >> 8)
                ;
                ovr_blitGfxRect(gfx_04,(int16_t)((char *)((int)puVar47 + (int)uStack_e) + 3),
                                (int16_t)((int)puStack_a + -3),in_stack_0000000a,
                                (uint8_t)in_stack_0000000c,true);
              }
              uVar68 = 0x10;
              in_stack_0000ffb8 = (uint8_t)in_stack_0000000c;
              uVar66 = (uint8_t)in_stack_0000000a;
              uVar67 = (undefined1)((uint)in_stack_0000000a >> 8);
              puVar27 = puVar48 + 3;
              iVar28 = (uint)((int)unaff_DI + 5) % 7 << 2;
              puVar45 = puStack_a + -3;
            } while( true );
          }
          if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\x13') {
            uVar22 = *(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x12a);
            bVar57 = CARRY2(uStack_38,uVar22);
            uStack_38 = uStack_38 + uVar22;
            iStack_36 = iStack_36 + (uint)bVar57;
          }
          else {
            uVar22 = *(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x12a);
            bVar57 = CARRY2(uStack_34,uVar22);
            uStack_34 = uStack_34 + uVar22;
            resourceTotals[0] = resourceTotals[0] + (uint)bVar57;
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
          uStack_22 = uStack_22 + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x127);
          if (0xf7 < (int)puVar47) {
            pcVar21 = ovc22_textPOPULATION
                                ((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),partyIndex,
                                 (agnt_t *)
                                 CONCAT13((char)((uint)puVar35[(int)puVar47].y >> 8),
                                          CONCAT12((char)puVar35[(int)puVar47].y,
                                                   puVar35[(int)puVar47].x)));
            uStack_20 = uStack_20 + (int)pcVar21;
            uVar22 = ovc22_seasonalIncome((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),partyIndex);
            iVar29 = iVar29 + uVar22;
          }
          if (((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x121) & 1) != 0) &&
             (((*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x2f) == -1 ||
               (bVar17 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x2f),
               uVar23 = CONCAT11((char)(uVar23 >> 8),bVar17),
               (1 << (bVar17 & 0x1f) & (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x11f)) != 0))
              && (*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) < 4)))) {
            *(int *)(&stack0xffbc + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) * 2) =
                 *(int *)(&stack0xffbc + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) * 2)
                 + 1;
          }
          if ((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x121) & 0x200) != 0) {
            agnt = (agnt_t *)
                   CONCAT22((int)((ulong)agnt >> 0x10) +
                            (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131),(agnt_t *)agnt);
          }
        }
      }
    }
    for (uStack_14 = (far_t *)0x0; uStack_14 < EntityCount;
        uStack_14 = (far_t *)((int)&uStack_14->ofs + 1)) {
      uVar51 = (undefined2)((ulong)Entities >> 0x10);
      if (*(byte *)((int)&((entity_t *)Entities)[(int)uStack_14].base.entity + 3) == partyIndex) {
        uStack_1e = uStack_1e + ((entity_t *)Entities)[(int)uStack_14].base.animFrame;
      }
    }
    bStack_1b = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xad);
    for (iVar28 = 2; -1 < iVar28; iVar28 = iVar28 + -1) {
      if (bStack_1b < *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + iVar28 + 0xaa)) {
        *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + iVar28 + 0xaa) = bStack_1b;
        bStack_1b = 0;
      }
      else {
        bStack_1b = bStack_1b -
                    *(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + iVar28 + 0xaa);
      }
    }
    iVar28 = 0;
    for (iVar50 = 0; iVar50 < 3; iVar50 = iVar50 + 1) {
      iVar28 = iVar28 + (uint)*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + iVar50 + 0xaa)
                        * (iVar50 + 1) * 3;
    }
    if (iVar28 < 0x32) {
      *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xaa) = (char)iVar28;
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xaa) = 0x32;
    }
    *(uint16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x94) = scratch;
    *(undefined2 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x96) = puStack_a;
    *(uint16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x98) = uStack_8;
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
    uStack_24 = (int)&((agnt_t *)agnt)->x + uStack_24;
    if ((agnt_t *)agnt == (agnt_t *)0x0) {
      if (in_stack_0000ffc0 == 0) {
        if (in_stack_0000ffbe == 0) {
          *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x53) = 4;
        }
        else {
          *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x53) = 8;
        }
      }
      else {
        *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x53) = 0xc;
      }
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x53) = 0xff;
    }
    *(undefined2 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x82) = 0;
    if ((resourceTotals[0] < 0) || (resourceTotals[0] < 1)) {
      uVar51 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
      iVar28 = (int)*(undefined4 *)((uint)partyIndex << 2);
      *(int16_t *)(iVar28 + 0x80) = resourceTotals[0];
      *(uint *)(iVar28 + 0x7e) = uStack_34;
    }
    else {
      uVar51 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
      iVar28 = (int)*(undefined4 *)((uint)partyIndex << 2);
      *(undefined2 *)(iVar28 + 0x80) = 0;
      *(undefined2 *)(iVar28 + 0x7e) = 0xffff;
    }
    *(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5b) = uStack_22;
    *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d) = uStack_1e;
    *(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4f) = (int)uStack_20;
    *(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x54) = iVar29;
    uVar51 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
    iVar29 = (int)*(undefined4 *)((uint)partyIndex << 2);
    *(int *)(iVar29 + 0x8c) = iStack_36;
    *(uint *)(iVar29 + 0x8a) = uStack_38;
    *(int16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 100) = animStep;
    *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x66) = uStack_28;
    *(undefined2 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x68) = uStack_26;
    *(int16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x70) = resourceTotals[1];
    *(int16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x72) = resourceTotals[2];
    *(int16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x74) = resourceTotals[3];
    *(undefined2 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x87) = (int)((ulong)agnt >> 0x10)
    ;
    if (uStack_24 < 0x100) {
      *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x52) = (char)uStack_24;
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x52) = 0xff;
    }
    uVar23 = ovr_ovc36_usesLDIV_at_(partyIndex);
    *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x84) = (char)uVar23;
    in_AX = (far_t *)ovc22_usesPlayerCount(partyIndex);
  }
  return in_AX;
switchD_5000_123d_caseD_2:
  do {
    bVar17 = ((entity_t *)Entities)[(int)puVar47].base.gindex;
    uStack_6 = (far_t *)CONCAT13(bVar17,(uint3)uStack_6);
    pfVar20 = (far_t *)(uint)*(byte *)((int)(char **)GMenuStrings + (uint)bVar17 * 0x95 + 0x1f);
    if (pfVar20 == (far_t *)0x0) {
      uVar30 = 0x195d;
      ovr_ovc15_capitalize((char *)CONCAT13(uVar62,CONCAT12(bVar16,auStackY_a6)));
      uStackY_60 = 0x2322;
      uStackY_62 = 0x8f4e;
      pfVar20 = (far_t *)ovr_stsprintf(&stack0xffaa,(char *)unaff_SS,
                                       (char *)"%s unit drowns.  (%d, %d)");
      ovr_uiNotify((char *)pfVar20,uVar30);
    }
    ovr_ovc15_removeEntity((uint)puVar47);
    while( true ) {
      do {
        puVar47 = (uint *)((int)puVar47 + -1);
        if ((int)puVar47 < 0) {
          return pfVar20;
        }
        pfVar20 = (far_t *)((int)puVar47 * 0x37);
        uVar51 = (undefined2)((ulong)Entities >> 0x10);
      } while (((uint *)(((entity_t *)Entities + (int)puVar47)->base).x != unaff_DI) ||
              (pfVar20 = (far_t *)((entity_t *)Entities)[(int)puVar47].base.y,
              pfVar20 != _bStack0006));
      pfVar20 = (far_t *)ovc23_findClearColumn((int)unaff_DI,(int)_bStack0006);
      uStack_6 = (far_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),pfVar20);
      if ((int)pfVar20 < 0) break;
      (((entity_t *)Entities + (int)puVar47)->base).x = (uint16_t)pfVar20;
    }
  } while( true );
switchD_5000_123d_caseD_3:
  while( true ) {
    if ((puVar36->flags & 3) == 0) {
      uVar51 = (undefined2)((ulong)GUnits >> 0x10);
      bVar17 = ((unit_t *)GUnits)[(int)unaff_DI].unitType;
      uStack_24 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_24) + 1)),bVar17);
      if ((bVar17 == 0xff) || (*(char *)((int)*(undefined4 *)((uint)bVar17 << 2) + 0x3f) == '\0')) {
        uStack_8 = 0x96;
      }
      else {
        uStack_8 = 0x5dc;
      }
      if (((unit_t *)GUnits)[(int)unaff_DI].level != 0) {
        uVar30 = ovr_randBelow(uStack_8);
        uVar51 = (undefined2)((ulong)GUnits >> 0x10);
        puVar35 = (unit_t *)GUnits;
        if ((int)(uVar30 & 0xff) <
            (int)(100 - (uint)*(byte *)((uint)(puVar35 + (int)unaff_DI)->bldType * 0x27 + 0x130))) {
          bVar17 = (puVar35 + (int)unaff_DI)->bldType;
          uStack_20 = (byte *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)),bVar17);
          puVar35[(int)unaff_DI].level = puVar35[(int)unaff_DI].level - 1;
          puVar35 = (unit_t *)GUnits;
          uVar51 = (undefined2)((ulong)GUnits >> 0x10);
          if (((*(uint *)((uint)bVar17 * 0x27 + 0x121) & 4) == 0) &&
             ((puVar35[(int)unaff_DI].level == 0 ||
              ((*(uint *)((uint)bVar17 * 0x27 + 0x121) & 0x200) != 0)))) {
            ovc22_usesGUnits((int)unaff_DI,&uStack_1c,bVar16);
          }
          else if (((((bld_inst_t *)BldInstances + bVar17)->ofs != 0 ||
                     *(int *)((int)&BldInstances[0].seg + (uint)bVar17 * 0xc) != 0) ||
                   (*(char *)((uint)bVar17 * 0x27 + 0x11e) == '\x10')) &&
                  (uVar51 = ovc22_usesGOngoingBattle2
                                      (*(byte *)&puVar35[(int)unaff_DI].x,
                                       *(byte *)&puVar35[(int)unaff_DI].y), (char)uVar51 != '\0')) {
            uStack_1c = 0x1;
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
      cVar18 = *(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3f);
      uStack_22 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_22) + 1)),cVar18);
      if ((cVar18 == '\0') &&
         (*(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f) <
          *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d) >> 1)) {
        uStack_24 = CONCAT11(1,(char)uStack_24);
      }
      else {
        uStack_24 = uStack_24 & 0xff;
      }
      uVar23 = *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54);
      uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar28 = *(int *)(iVar28 + 0x58) + ((int)uVar23 >> 0xf) +
               (uint)CARRY2(*(uint *)(iVar28 + 0x56),uVar23);
      if ((iVar28 < 1) && (iVar28 < 0)) {
        puVar47 = (uint *)&GUnitDescriptions[3].ofs;
        while (puVar47 = (uint *)((int)puVar47 + 1), puVar47 < GUnitCount) {
          uVar51 = (undefined2)((ulong)GUnits >> 0x10);
          puVar35 = (unit_t *)GUnits;
          bVar17 = (puVar35 + (int)puVar47)->bldType;
          uStack_20 = (byte *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)),bVar17);
          if (((far_t *)(uint)puVar35[(int)puVar47].unitType == uStack_16) &&
             (*(int *)((uint)bVar17 * 0x27 + 0x123) < 0)) {
            uVar23 = *(uint *)((uint)bVar17 * 0x27 + 0x123);
            uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
            iVar28 = *(int *)(iVar28 + 0x58) + ((int)uVar23 >> 0xf) +
                     (uint)CARRY2(*(uint *)(iVar28 + 0x56),uVar23);
            if ((iVar28 < 1) && (iVar28 < 0)) {
              if (((char)uStack_22 == '\0') && (puVar35[(int)puVar47].level != 0)) {
                uVar30 = ovr_randBelow(100);
                uVar51 = (undefined2)((ulong)GUnits >> 0x10);
                puVar35 = (unit_t *)GUnits;
                if (*(byte *)((uint)(puVar35 + (int)puVar47)->bldType * 0x27 + 0x130) <=
                    (byte)uVar30) {
                  if (puVar35[(int)puVar47].level != 0) {
                    puVar35[(int)puVar47].level = puVar35[(int)puVar47].level - 1;
                  }
                  puVar35 = (unit_t *)GUnits;
                  uVar51 = (undefined2)((ulong)GUnits >> 0x10);
                  if (((*(uint *)(((uint)uStack_20 & 0xff) * 0x27 + 0x121) & 4) == 0) &&
                     ((puVar35[(int)puVar47].level == 0 ||
                      ((*(uint *)(((uint)uStack_20 & 0xff) * 0x27 + 0x121) & 0x200) != 0)))) {
                    ovc22_usesGUnits((int)puVar47,&uStack_1c,bVar16);
                  }
                  else if (((((bld_inst_t *)BldInstances + ((uint)uStack_20 & 0xff))->ofs != 0 ||
                             *(int *)((int)&BldInstances[0].seg + ((uint)uStack_20 & 0xff) * 0xc) !=
                             0) || (*(char *)(((uint)uStack_20 & 0xff) * 0x27 + 0x11e) == '\x10'))
                          && (uVar51 = ovc22_usesGOngoingBattle2
                                                 (*(byte *)&puVar35[(int)puVar47].x,
                                                  *(byte *)&puVar35[(int)puVar47].y),
                             (char)uVar51 != '\0')) {
                    uStack_1c = 0x1;
                  }
                }
              }
            }
            else {
              uVar22 = *(uint *)((uint)bVar17 * 0x27 + 0x123);
              uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
              iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
              puVar3 = (uint *)(iVar28 + 0x56);
              uVar23 = *puVar3;
              *puVar3 = *puVar3 + uVar22;
              piVar4 = (int *)(iVar28 + 0x58);
              *piVar4 = *piVar4 + ((int)uVar22 >> 0xf) + (uint)CARRY2(uVar23,uVar22);
            }
          }
        }
        uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar28 + 0x58) = 0;
        *(undefined2 *)(iVar28 + 0x56) = 0;
      }
      else {
        if ((cVar18 == '\0') && (0 < *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54))) {
          puStack_10 = (uint *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54) / 10);
        }
        else {
          puStack_10 = (uint *)0x0;
        }
        bVar57 = CARRY2((uint)GPopulationLo,(uint)puStack_10);
        GPopulationLo = GPopulationLo + (int)puStack_10;
        GPopulationHi = GPopulationHi + ((int)puStack_10 >> 0xf) + (uint)bVar57;
        uVar22 = *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54) - (int)puStack_10;
        uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar28 + 0x56);
        uVar23 = *puVar3;
        *puVar3 = *puVar3 + uVar22;
        piVar4 = (int *)(iVar28 + 0x58);
        *piVar4 = *piVar4 + ((int)uVar22 >> 0xf) + (uint)CARRY2(uVar23,uVar22);
      }
      if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                    (uint)*(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3e) * 0x95) &
          0x100) == 0) {
        if (*(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f) <
            *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d)) {
          puStack_12 = (uint *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d) -
                               *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f));
          uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar50 = (int)*(undefined4 *)((int)uStack_16 << 2);
          iVar28 = *(int *)(iVar50 + 0x62);
          if ((-1 < iVar28) && ((0 < iVar28 || (*(int *)(iVar50 + 0x60) != 0)))) {
            uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
            uVar23 = *(uint *)(iVar28 + 0x62);
            if ((0x7fff < uVar23) ||
               ((uStack_14 = (far_t *)puStack_12, (int)uVar23 < 1 &&
                ((uint *)*(undefined2 *)(iVar28 + 0x60) <= puStack_12)))) {
              uStack_14 = (far_t *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x60)
              ;
            }
            puStack_12 = (uint *)((int)puStack_12 - (int)uStack_14);
            uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
            piVar4 = (int *)(iVar28 + 0x60);
            puVar47 = (uint *)*piVar4;
            *piVar4 = *piVar4 - (int)uStack_14;
            piVar4 = (int *)(iVar28 + 0x62);
            *piVar4 = *piVar4 - (uint)(puVar47 < uStack_14);
          }
          if (puStack_12 != (uint *)0x0) {
            puStack_a = puStack_12;
            if ((uint *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0) <
                puStack_12) {
              puStack_a = (uint *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0);
            }
            uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
            uVar23 = *(uint *)(iVar28 + 0x58);
            if (((int)uVar23 < 1) &&
               ((0x7fff < uVar23 || ((uint *)*(undefined2 *)(iVar28 + 0x56) < puStack_a)))) {
              puStack_a = (uint *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x56);
            }
            uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
            piVar4 = (int *)(iVar28 + 0x56);
            puVar47 = (uint *)*piVar4;
            *piVar4 = *piVar4 - (int)puStack_a;
            piVar4 = (int *)(iVar28 + 0x58);
            *piVar4 = *piVar4 - (uint)(puVar47 < puStack_a);
            puStack_12 = (uint *)((int)puStack_12 - (int)puStack_a);
            *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa2) = puStack_a;
          }
          if ((char)uStack_22 == '\0') {
            for (iVar28 = 0; (puStack_12 != (uint *)0x0 && (iVar28 < (int)(uint)GLeaderCount));
                iVar28 = iVar28 + 1) {
              if ((*(char *)((int)*(undefined4 *)(iVar28 << 2) + 0x3d) != '\0') &&
                 ((*(char *)((int)*(undefined4 *)(iVar28 << 2) + 0x3f) == '\0' &&
                  (uVar51 = (undefined2)((ulong)*(undefined4 *)(iVar28 << 2) >> 0x10),
                  iVar50 = (int)*(undefined4 *)(iVar28 << 2),
                  *(int *)(iVar50 + 0x60) != 0 || *(int *)(iVar50 + 0x62) != 0)))) {
                uVar51 = (undefined2)((ulong)*(undefined4 *)(iVar28 << 2) >> 0x10);
                iVar50 = (int)*(undefined4 *)(iVar28 << 2);
                uVar23 = *(uint *)(iVar50 + 0x62);
                if ((uVar23 < 0x8000) &&
                   ((0 < (int)uVar23 || (puStack_12 < (uint *)*(undefined2 *)(iVar50 + 0x60))))) {
                  uStack_14 = (far_t *)puStack_12;
                }
                else {
                  uStack_14 = (far_t *)*(undefined2 *)((int)*(undefined4 *)(iVar28 << 2) + 0x60);
                }
                puStack_12 = (uint *)((int)puStack_12 - (int)uStack_14);
                uVar51 = (undefined2)((ulong)*(undefined4 *)(iVar28 << 2) >> 0x10);
                iVar50 = (int)*(undefined4 *)(iVar28 << 2);
                piVar4 = (int *)(iVar50 + 0x60);
                puVar47 = (uint *)*piVar4;
                *piVar4 = *piVar4 - (int)uStack_14;
                piVar4 = (int *)(iVar50 + 0x62);
                *piVar4 = *piVar4 - (uint)(puVar47 < uStack_14);
              }
            }
          }
          pfVar20 = (far_t *)0x0;
          while ((pfVar20 < EntityCount && (puStack_12 != (uint *)0x0))) {
            uVar51 = (undefined2)((ulong)Entities >> 0x10);
            peVar39 = (entity_t *)Entities;
            if (((*(char *)((int)&peVar39[(int)pfVar20].base.entity + 1) == '\0') &&
                ((far_t *)(uint)*(byte *)((int)&peVar39[(int)pfVar20].base.entity + 3) == uStack_16)
                ) && (((*(uint8_t *)((uint8_t *)&(uStack_24) + 1)) != '\0' || (1 < peVar39[(int)pfVar20].base.animFrame)))) {
              if (peVar39[(int)pfVar20].base.animFrame != 0x0) {
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
            pfVar20 = (far_t *)((int)&pfVar20->ofs + 1);
          }
        }
        else {
          uVar22 = *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f) -
                   *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d);
          uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
          puVar3 = (uint *)(iVar28 + 0x60);
          uVar23 = *puVar3;
          *puVar3 = *puVar3 + uVar22;
          piVar4 = (int *)(iVar28 + 0x62);
          *piVar4 = *piVar4 + (uint)CARRY2(uVar23,uVar22);
        }
      }
      uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar37 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar28 = *(int *)(iVar37 + 0x62);
      uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar38 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar50 = *(int *)(iVar38 + 0x80);
      if ((iVar50 <= iVar28) &&
         ((iVar50 < iVar28 || (*(uint *)(iVar38 + 0x7e) < *(uint *)(iVar37 + 0x60))))) {
        uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
        uVar23 = *(uint *)(iVar28 + 0x60);
        uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar50 = (int)*(undefined4 *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar50 + 0x7e);
        uVar22 = (uint)(uVar23 < *puVar3);
        uVar31 = *(int *)(iVar28 + 0x62) - *(int *)(iVar50 + 0x80);
        if (((int)(uVar31 - uVar22) < 0) ||
           ((uVar31 == uVar22 &&
            (uVar23 - *puVar3 <= *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0))))) {
          puStack_a = (uint *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x60) -
                              *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7e));
        }
        else {
          puStack_a = (uint *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0);
        }
        *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa2) = -(int)puStack_a;
        uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar28 + 0x56);
        uVar23 = *puVar3;
        *puVar3 = (uint)(*puVar3 + (int)puStack_a);
        piVar4 = (int *)(iVar28 + 0x58);
        *piVar4 = *piVar4 + (uint)CARRY2(uVar23,(uint)puStack_a);
        uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
        uVar51 = *(undefined2 *)(iVar28 + 0x7e);
        uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar50 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar50 + 0x62) = *(undefined2 *)(iVar28 + 0x80);
        *(undefined2 *)(iVar50 + 0x60) = uVar51;
      }
      if ((*(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x5b) <
           *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d)) &&
         ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                    (uint)*(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3e) * 0x95) & 0x80
          ) == 0)) {
        puStack_12 = (uint *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d) -
                             *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x5b));
        pfVar20 = (far_t *)0x0;
        while ((pfVar20 < EntityCount && (puStack_12 != (uint *)0x0))) {
          uVar51 = (undefined2)((ulong)Entities >> 0x10);
          peVar39 = (entity_t *)Entities;
          if (((far_t *)(uint)*(byte *)((int)&peVar39[(int)pfVar20].base.entity + 3) == uStack_16)
             && ((((*(char *)((int)&peVar39[(int)pfVar20].base.entity + 1) == '\0' &&
                   (peVar39[(int)pfVar20].base.destX == 0)) &&
                  (peVar39[(int)pfVar20].base.destY == 0)) &&
                 (3 < peVar39[(int)pfVar20].base.animFrame)))) {
            if (DebugVerbose != false) {
              printf("kill 2 \r");
            }
            puVar5 = &((entity_t *)Entities)[(int)pfVar20].base.animFrame;
            *puVar5 = *puVar5 + 0xff;
            puStack_12 = (uint *)((int)puStack_12 + -1);
          }
          pfVar20 = (far_t *)((int)&pfVar20->ofs + 1);
        }
      }
      ovr_ovc25_tickCountdown((int)uStack_16);
      _fmemset((void *)(*(int *)((int)uStack_16 * 4) + 0x6a),((int *)((int)uStack_16 * 4))[1],0);
      _fmemset((void *)(*(int *)((int)uStack_16 * 4) + 0x76),((int *)((int)uStack_16 * 4))[1],0);
      uVar30 = ovr_randBelow(100);
      if ((byte)uVar30 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6c) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 100);
      }
      else {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6a) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 100);
      }
      uVar30 = ovr_randBelow(100);
      if ((byte)uVar30 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6e) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x66);
      }
      else {
        piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6c);
        *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x66);
      }
      piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6e);
      *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x68);
      uVar30 = ovr_randBelow(100);
      if ((byte)uVar30 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x78) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x70);
      }
      else {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x76) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x70);
      }
      uVar30 = ovr_randBelow(100);
      if ((byte)uVar30 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7a) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x72);
      }
      else {
        piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x78);
        *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x72);
      }
      uVar30 = ovr_randBelow(100);
      if ((byte)uVar30 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
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
        iVar50 = (int)*(undefined4 *)((int)uStack_16 << 2);
        iVar28 = *(int *)(iVar50 + 0x58);
        if ((iVar28 < 1) && ((iVar28 != 0 || (*(int *)(iVar50 + 0x56) == 0)))) {
          uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
          *(undefined2 *)(iVar28 + 0x58) = 0;
          *(undefined2 *)(iVar28 + 0x56) = 0x32;
        }
      }
      if (*(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xaa) != '\0') {
        bVar17 = *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xaa);
        uStack_6 = (far_t *)(ulong)CONCAT12(bVar17,(far_t *)uStack_6);
        pfVar12 = uStack_6;
        for (uVar23 = 0; uStack_6 = pfVar12, (int)uVar23 < (int)(uint)GLeaderCount;
            uVar23 = uVar23 + 1) {
          uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar37 = (int)*(undefined4 *)((int)uStack_16 << 2);
          iVar28 = *(int *)(iVar37 + 0x58);
          uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar38 = (int)*(undefined4 *)((int)uStack_16 << 2);
          iVar50 = *(int *)(iVar38 + 0x8c);
          if ((iVar50 <= iVar28) &&
             ((iVar28 != iVar50 || (*(uint *)(iVar38 + 0x8a) <= *(uint *)(iVar37 + 0x56))))) break;
          if ((*(char *)((int)*(undefined4 *)(uVar23 << 2) + 0x3d) != '\0') &&
             (((0 < *(int *)((int)*(undefined4 *)(uVar23 << 2) + 0x54) &&
               (*(char *)((int)*(undefined4 *)(uVar23 << 2) + 0x3f) == '\0')) &&
              ((far_t *)uVar23 != uStack_16)))) {
            (*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) = (uint)bVar17;
            resourceTotals[2] =
                 (int16_t)(((long)*(int *)((int)*(undefined4 *)(uVar23 << 2) + 0x54) *
                            (long)(int)(*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) & 0xffffU) / 100);
            resourceTotals[3] = 0;
            uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
            uVar22 = *(uint *)(iVar28 + 0x8a);
            uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar50 = (int)*(undefined4 *)((int)uStack_16 << 2);
            puVar3 = (uint *)(iVar50 + 0x56);
            iVar28 = (*(int *)(iVar28 + 0x8c) - *(int *)(iVar50 + 0x58)) - (uint)(uVar22 < *puVar3);
            if ((iVar28 < 1) && ((iVar28 < 0 || (uVar22 - *puVar3 < (uint)resourceTotals[2])))) {
              uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
              iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
              uVar22 = *(uint *)(iVar28 + 0x8a);
              uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
              iVar50 = (int)*(undefined4 *)((int)uStack_16 << 2);
              puVar3 = (uint *)(iVar50 + 0x56);
              resourceTotals[2] = uVar22 - *puVar3;
              resourceTotals[3] =
                   (*(int *)(iVar28 + 0x8c) - *(int *)(iVar50 + 0x58)) - (uint)(uVar22 < *puVar3);
            }
            uVar51 = (undefined2)((ulong)*(undefined4 *)(uVar23 << 2) >> 0x10);
            iVar50 = (int)*(undefined4 *)(uVar23 << 2);
            iVar28 = *(int *)(iVar50 + 0x58);
            if ((iVar28 <= resourceTotals[3]) &&
               ((iVar28 < resourceTotals[3] || (*(uint *)(iVar50 + 0x56) < (uint)resourceTotals[2]))
               )) {
              uVar51 = (undefined2)((ulong)*(undefined4 *)(uVar23 << 2) >> 0x10);
              iVar28 = (int)*(undefined4 *)(uVar23 << 2);
              resourceTotals[3] = *(int16_t *)(iVar28 + 0x58);
              resourceTotals[2] = *(int16_t *)(iVar28 + 0x56);
            }
            uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
            puVar3 = (uint *)(iVar28 + 0x56);
            uVar22 = *puVar3;
            *puVar3 = *puVar3 + resourceTotals[2];
            piVar4 = (int *)(iVar28 + 0x58);
            *piVar4 = *piVar4 + resourceTotals[3] + (uint)CARRY2(uVar22,resourceTotals[2]);
            uVar51 = (undefined2)((ulong)*(undefined4 *)(uVar23 << 2) >> 0x10);
            iVar28 = (int)*(undefined4 *)(uVar23 << 2);
            puVar3 = (uint *)(iVar28 + 0x56);
            uVar22 = *puVar3;
            *puVar3 = *puVar3 - resourceTotals[2];
            piVar4 = (int *)(iVar28 + 0x58);
            *piVar4 = (*piVar4 - resourceTotals[3]) - (uint)(uVar22 < (uint)resourceTotals[2]);
          }
        }
      }
      iVar28 = *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x58);
      if ((iVar28 < 1) && (iVar28 < 0)) {
        uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar28 + 0x58) = 0;
        *(undefined2 *)(iVar28 + 0x56) = 0;
      }
      uVar51 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar37 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar28 = *(int *)(iVar37 + 0x58);
      uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar38 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar50 = *(int *)(iVar38 + 0x8c);
      if ((iVar50 <= iVar28) &&
         ((iVar50 < iVar28 || (*(uint *)(iVar38 + 0x8a) < *(uint *)(iVar37 + 0x56))))) {
        uVar52 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar28 = (int)*(undefined4 *)((int)uStack_16 << 2);
        uVar51 = *(undefined2 *)(iVar28 + 0x8a);
        uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar50 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar50 + 0x58) = *(undefined2 *)(iVar28 + 0x8c);
        *(undefined2 *)(iVar50 + 0x56) = uVar51;
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
    puVar35 = (unit_t *)GUnits;
    if ((*(uint *)((uint)(puVar35 + (int)puVar47)->bldType * 0x27 + 0x121) & 0x40) != 0) {
      if (puVar35[(int)puVar47].timer != 0) {
        puVar35[(int)puVar47].timer = puVar35[(int)puVar47].timer - 1;
      }
      uVar51 = (undefined2)((ulong)GUnits >> 0x10);
      if (((unit_t *)GUnits)[(int)puVar47].timer == 0) {
        uVar10 = *(undefined4 *)((uint)((unit_t *)GUnits)[(int)puVar47].unitType << 2);
        if (*(char *)((int)uVar10 + 0x3f) == '\0') {
          ovr_play_sfx(81,0);
          ovr_alignUp4(((unit_t *)GUnits)[(int)puVar47].x);
          pcVar21 = ovr_fmVsprintf((char *)"Mine exhausted at (%d, %d).",(char *)"puppetmaker" + 3);
          ovr_say(pcVar21);
          ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
        }
        ovc22_usesGUnits((int)puVar47,&uStack_1c,bVar16);
      }
    }
  }
  GGameState = 0x42;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_driver_clearMapFlagsRect((uint32_t)GMapFlags,0,0,0x93,0x3b,0xfff7);
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
        iVar28 = ((int *)((int)uStack_16 * 4))[1];
        iVar50 = ((int *)((int)uStack_16 * 4))[1];
        memcpy((char *)CONCAT13((char)((uint)iVar50 >> 8),
                                CONCAT12((char)iVar50,*(int *)((int)uStack_16 * 4) + 0x8e)),
               (char *)CONCAT13((char)((uint)iVar28 >> 8),
                                CONCAT12((char)iVar28,*(int *)((int)uStack_16 * 4) + 0x94)),3);
      }
    }
  }
  uStack_e = (uint *)0x0;
  bVar17 = ovr_manage_findFirstLeader();
  (*(uint16_t *)((uint8_t *)&(uStack_6))) = (far_t *)CONCAT11(bVar17,(byte)uStack_6);
  if ((bVar17 == 0xff) || (GCanPromote == '\0')) {
    scratch = 0;
  }
  else if (*(byte *)((int)*(undefined4 *)((uint)bVar17 << 2) + 0x86) < 5) {
    scratch = 0x28;
  }
  else {
    scratch = (uint)*(byte *)((int)*(undefined4 *)((uint)bVar17 << 2) + 0x86) * 4 + 0x14;
  }
  for (uStack_16 = EntityScanPos; uStack_16 < EntityCount;
      uStack_16 = (far_t *)((int)&uStack_16->ofs + 1)) {
    uVar51 = (undefined2)((ulong)Entities >> 0x10);
    peVar39 = (entity_t *)Entities;
    if (((*(char *)((int)&peVar39[(int)uStack_16].base.entity + 1) == '\0') &&
        (peVar39[(int)uStack_16].base.destX == 0)) && (peVar39[(int)uStack_16].base.destY == 0)) {
      bVar17 = peVar39[(int)uStack_16].base.gindex;
      uStack_6 = (far_t *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),bVar17);
      uStack_22 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_22) + 1)),
                           *(undefined1 *)((int)(char **)GMenuStrings + (uint)bVar17 * 0x95 + 0x1f))
      ;
      bVar15 = *(byte *)((int)&peVar39[(int)uStack_16].base.entity + 3);
      uStack_24 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_24) + 1)),bVar15);
      uStack_26 = 0;
      uStack_28 = uStack_28 & 0xff;
      if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar17 * 0x95) == -1) {
        uStack_26 = 0x100;
      }
      else {
        uVar10 = *(undefined4 *)((uint)bVar15 << 2);
        bStack_1b = *(byte *)((int)uVar10 + 0x89);
        if (bStack_1b < 5) {
          uStack_1a = peVar39[(int)uStack_16].base.y;
          uStack_18 = ovr_alignUp4(((peVar39 + (int)uStack_16)->base).x);
          uVar30 = 0x2410;
          if (((*(short (*) [60] [148])GMapFlags)[uStack_1a][uStack_18] & 8U) == 0) {
            uStack_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)),0x22);
            uStack_20 = (byte *)((char *)"stronghold" + 6);
          }
          else {
            puVar49 = &uStack_1e;
            iVar28 = (int)&uStack_20 + 1;
            puVar61 = &uStack_20;
            index = CONCAT11((char)((uint)puVar61 >> 8),bStack_1b);
            uStackY_60 = 0x2379;
            uStackY_62 = 0x3d98;
            bVar17 = bVar16;
            uVar19 = uVar62;
            bVar15 = bVar16;
            uVar65 = uVar62;
            bVar14 = bVar16;
            uVar64 = uVar62;
            uVar24 = ovr_attact_usesSquareRecCount(uStack_18,uStack_1a);
            table.seg = uVar30;
            table.ofs = uVar24;
            uStackY_60 = 0x2315;
            uStackY_62 = 0x3da2;
            (*(uint8_t *)((uint8_t *)&(pctOut.seg))) = bVar17;
            pctOut.ofs = (uint16_t)puVar61;
            (*(uint8_t *)((uint8_t *)&(pctOut.seg) + 1)) = uVar19;
            (*(uint8_t *)((uint8_t *)&(remainderOut.seg))) = bVar15;
            remainderOut.ofs = iVar28;
            (*(uint8_t *)((uint8_t *)&(remainderOut.seg) + 1)) = uVar65;
            (*(uint8_t *)((uint8_t *)&(partOut.seg))) = bVar14;
            partOut.ofs = (uint16_t)puVar49;
            (*(uint8_t *)((uint8_t *)&(partOut.seg) + 1)) = uVar64;
            ovr_attact_compute3_2(table,index,pctOut,remainderOut,partOut);
          }
        }
        else {
          uStack_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)),0x22);
          uStack_20 = (byte *)((char *)"stronghold" + 6);
        }
        uVar30 = ovr_randBelow(100);
        uStack_22 = CONCAT11((byte)uVar30,(char)uStack_22);
        if ((byte)uVar30 < (byte)uStack_1e) {
          uStack_26 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_26) + 1)) + '\x01',(char)uStack_26);
        }
        else if ((uVar30 & 0xff) < ((uint)uStack_20 >> 8) + (uStack_1e & 0xff)) {
          uStack_26 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_26) + 1)),(char)uStack_26 + '\x01');
        }
        else {
          uStack_28 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_28) + 1)) + '\x01',(undefined1)uStack_28);
        }
      }
      if ((*(uint8_t *)((uint8_t *)&(uStack_28) + 1)) != '\0') {
        uVar51 = (undefined2)((ulong)Entities >> 0x10);
        cVar18 = ovr_ovc23_tickRecordsAt
                           ((((entity_t *)Entities + (int)uStack_16)->base).x,
                            ((entity_t *)Entities)[(int)uStack_16].base.y,(char)uStack_22);
        if (cVar18 == '\0') {
          if (((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)) == 0) && ((byte)uStack_1e == '\0')) {
            uVar30 = ovr_randBelow(2);
            if ((uVar30 & 0xff) == 0) {
              uStack_26 = CONCAT11(1,(char)uStack_26);
            }
            else {
              uStack_26 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_26) + 1)),1);
            }
          }
          else {
            uVar30 = ovr_randBelow((uint)(*(uint8_t *)((uint8_t *)&(uStack_20) + 1)) + (uStack_1e & 0xff));
            if ((byte)uVar30 < (byte)uStack_1e) {
              uStack_26 = CONCAT11(1,(char)uStack_26);
            }
            else {
              uStack_26 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_26) + 1)),1);
            }
          }
        }
      }
      if (((*(uint8_t *)((uint8_t *)&(uStack_26) + 1)) != '\0') &&
         (uVar23 = ovc22_usesEntities((int)uStack_16), (uVar23 & 0xff) == 0)) {
        uStack_26 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_26) + 1)),1);
      }
      if ((char)uStack_26 != '\0') {
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)uStack_6 * 0x95) != -1) &&
           ((char)uStack_24 != -1)) {
          uVar10 = *(undefined4 *)((uStack_24 & 0xff) << 2);
          if ((*(char *)((int)uVar10 + 0x3f) != '\0') ||
             (uVar10 = *(undefined4 *)((uStack_24 & 0xff) << 2),
             ((entity_t *)Entities)[(int)uStack_16].base.level < *(byte *)((int)uVar10 + 0x53))) {
            uVar19 = (undefined1)scratch;
            uVar65 = (undefined1)(scratch >> 8);
            ovc22_usesLUDIV_at_((entity_t *)
                                CONCAT13((char)((ulong)Entities >> 0x18),
                                         CONCAT12((char)((ulong)Entities >> 0x10),
                                                  (entity_t *)Entities + (int)uStack_16)));
            LXMUL_at_((long *)CONCAT11(uVar65,uVar19),
                      CONCAT13(in_stack_0000ffb9,CONCAT12(in_stack_0000ffb8,CONCAT11(uVar67,uVar66))
                              ),CONCAT13(in_stack_0000ffbd,CONCAT12(in_stack_0000ffbc,iVar29)));
            peVar39 = (entity_t *)Entities + (int)uStack_16;
            uVar30 = ovr_ovc15_textError();
            uVar22 = ovc22_usesLUDIV_at_2(uVar30,(uint16_t)peVar39,CONCAT11(uVar65,uVar19));
            uVar51 = (undefined2)((ulong)Entities >> 0x10);
            peVar40 = (entity_t *)Entities;
            uVar23 = *(uint *)&peVar40[(int)uStack_16].base.health;
            *(uint *)&peVar40[(int)uStack_16].base.frameIndex =
                 (int)&(peVar39->base).x +
                 (uint)CARRY2(uVar23,uVar22) + *(int *)&peVar40[(int)uStack_16].base.frameIndex;
            *(uint *)&peVar40[(int)uStack_16].base.health = uVar23 + uVar22;
            ovr_ovc41_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                        CONCAT12((char)((ulong)Entities >> 0x10),
                                                 (entity_t *)Entities + (int)uStack_16)));
          }
        }
        ovc22_usesEntities2((int)uStack_16);
        ovc22_usesEntities3((int)uStack_16);
        ovc22_usesEntities4((int)uStack_16);
      }
      uVar10 = *(undefined4 *)((uStack_24 & 0xff) << 2);
      animStep = (uint)((entity_t *)Entities)[(int)uStack_16].base.animFrame -
                 (uint)*(byte *)((int)uVar10 + 0xa4);
      if (0 < animStep) {
        if (3 < animStep) {
          animStep = 3;
        }
        if (animStep == 3) {
          uVar10 = *(undefined4 *)((uStack_24 & 0xff) << 2);
          if (*(int *)((int)uVar10 + 0x92) == 0) {
            animStep = 2;
          }
          else {
            uVar10 = *(undefined4 *)((uStack_24 & 0xff) << 2);
            piVar4 = (int *)((int)uVar10 + 0x92);
            *piVar4 = *piVar4 + -1;
          }
        }
        if (animStep == 2) {
          uVar10 = *(undefined4 *)((uStack_24 & 0xff) << 2);
          if (*(int *)((int)uVar10 + 0x90) == 0) {
            animStep = 1;
          }
          else {
            uVar10 = *(undefined4 *)((uStack_24 & 0xff) << 2);
            piVar4 = (int *)((int)uVar10 + 0x90);
            *piVar4 = *piVar4 + -1;
          }
        }
        if (animStep == 1) {
          uVar10 = *(undefined4 *)((uStack_24 & 0xff) << 2);
          if (*(int *)((int)uVar10 + 0x8e) == 0) {
            animStep = 0;
          }
          else {
            uVar10 = *(undefined4 *)((uStack_24 & 0xff) << 2);
            piVar4 = (int *)((int)uVar10 + 0x8e);
            *piVar4 = *piVar4 + -1;
          }
        }
        uVar10 = *(undefined4 *)((uStack_24 & 0xff) << 2);
        ((entity_t *)Entities)[(int)uStack_16].base.animFrame =
             *(char *)((int)uVar10 + 0xa4) + (char)animStep;
      }
      uStack_e = (uint *)((int)uStack_e + 1);
      if (199 < (int)uStack_e) break;
    }
  }
  EntityScanPos = uStack_16;
  mapDirty = 1;
  ovr_unit_usesAlignUp4();
  GGameState = 0x44;
  pfVar20 = (far_t *)((char *)"puppetmaker" + 3);
  if (DebugVerbose != false) {
    pfVar20 = (far_t *)((char *)"puppetmaker" + 3);
    printf("%d \r");
  }
  if ((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)) != '\0') {
    pfVar20 = (far_t *)((int)&EntityCount[-1].seg + 1);
    for (uStack_16 = pfVar20; -1 < (int)uStack_16;
        uStack_16 = (far_t *)((int)&uStack_16[-1].seg + 1)) {
      uVar51 = (undefined2)((ulong)Entities >> 0x10);
      peVar39 = (entity_t *)Entities;
      pfVar20 = (far_t *)(uint)peVar39[(int)uStack_16].base.animFrame;
      if (pfVar20 == (far_t *)0x0) {
        pfVar20 = (far_t *)(uint)*(byte *)((int)(char **)GMenuStrings +
                                          (uint)peVar39[(int)uStack_16].base.gindex * 0x95 + 0x1f);
        if (pfVar20 == (far_t *)0x0) {
          ovr_alignUp4(((peVar39 + (int)uStack_16)->base).x);
          uVar30 = 0x195d;
          pfVar20 = (far_t *)ovr_fmVsprintf((char *)
                                            "Intelligence reports %s unit died of starvation. (%d, %d)"
                                            ,(char *)"puppetmaker" + 3);
          ovr_uiNotify((char *)pfVar20,uVar30);
        }
        ovr_ovc15_removeEntity((uint)uStack_16);
      }
    }
  }
  if (uStack_1c != 0x0) {
    ovr_constr_flushDirtyRects();
  }
  return pfVar20;
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

void __cdecl16far ovc22_usesGUnits(int unitIndex,uint8_t *outFlag,uint8_t outFlagSeg)

{
  byte bVar1;
  undefined2 uVar2;
  unit_t *puVar3;
  uint uVar4;
  undefined1 in_stack_00000009;
  char in_stack_0000000a;
  
  _outFlag = (undefined1 *)CONCAT13(in_stack_00000009,CONCAT12(outFlagSeg,outFlag));
  uVar4 = 0;
  while( true ) {
    puVar3 = (unit_t *)GUnits;
    uVar2 = (undefined2)((ulong)GUnits >> 0x10);
    if (GRecordCount <= uVar4) {
      bVar1 = (puVar3 + unitIndex)->bldType;
      if ((*(uint *)((uint)bVar1 * 0x27 + 0x121) & 4) == 0) {
        uVar2 = ovc22_usesGOngoingBattle
                          (*(byte *)&puVar3[unitIndex].x,*(byte *)&puVar3[unitIndex].y);
        if ((char)uVar2 != '\0') {
          *_outFlag = 1;
        }
        uVar2 = (undefined2)((ulong)GUnits >> 0x10);
        ovr_createConstructionRecordFar
                  (0,((unit_t *)GUnits)[unitIndex].x,((unit_t *)GUnits)[unitIndex].y,outFlag,
                   outFlagSeg,in_stack_0000000a);
        if ((1 < *(byte *)((uint)bVar1 * 0x27 + 0x11b)) &&
           (uVar2 = (undefined2)((ulong)GUnits >> 0x10),
           ovr_createConstructionRecordFar
                     (0,((unit_t *)GUnits)[unitIndex].x + 1,((unit_t *)GUnits)[unitIndex].y,outFlag,
                      outFlagSeg,in_stack_0000000a), 3 < *(byte *)((uint)bVar1 * 0x27 + 0x11b))) {
          uVar2 = (undefined2)((ulong)GUnits >> 0x10);
          ovr_createConstructionRecordFar
                    (0,((unit_t *)GUnits)[unitIndex].x + 2,((unit_t *)GUnits)[unitIndex].y,outFlag,
                     outFlagSeg,in_stack_0000000a);
          uVar2 = (undefined2)((ulong)GUnits >> 0x10);
          ovr_createConstructionRecordFar
                    (0,((unit_t *)GUnits)[unitIndex].x + 3,((unit_t *)GUnits)[unitIndex].y,outFlag,
                     outFlagSeg,in_stack_0000000a);
        }
      }
      return;
    }
    if ((*(int *)(uVar4 * 0x12 + 2) == puVar3[unitIndex].x) &&
       (*(int *)(uVar4 * 0x12 + 4) == puVar3[unitIndex].y)) break;
    uVar4 = uVar4 + 1;
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

char __cdecl16far ovc22_compute3(char direction)

{
  if (direction < '\0') {
    direction = direction + '\x06';
  }
  return direction;
}



/* 5087:1991 */

/* [R6] touches Entities */

void __cdecl16far ovc22_usesEntities2(int entityIndex)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  undefined2 uVar7;
  char cStack_5;
  
  uVar7 = (undefined2)((ulong)Entities >> 0x10);
  if (*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3) != -1) {
    bVar4 = ovr_agnt_compute8((agnt_t *)CONCAT22(uVar7,(entity_t *)Entities + entityIndex));
    bVar2 = *(byte *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3);
    for (cStack_5 = '\0'; cStack_5 < '\x03'; cStack_5 = cStack_5 + '\x01') {
      uVar3 = *(undefined4 *)((uint)bVar2 << 2);
      if ((*(int *)((int)uVar3 + cStack_5 * 2 + 0x6a) != 0) && ((char)bVar4 < cStack_5)) {
        uVar3 = *(undefined4 *)((uint)bVar2 << 2);
        piVar1 = (int *)((int)uVar3 + cStack_5 * 2 + 0x6a);
        *piVar1 = *piVar1 + -1;
        uVar7 = (undefined2)((ulong)Entities >> 0x10);
        cVar5 = ((entity_t *)Entities)[entityIndex].dir -
                ((entity_t *)Entities)[entityIndex].dir % 6;
        cVar6 = ovc22_compute3(cStack_5);
        ((entity_t *)Entities)[entityIndex].dir = cVar5 + cVar6;
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
  entity_t *peVar6;
  undefined2 uVar7;
  char cStack_7;
  char cStack_6;
  
  uVar7 = (undefined2)((ulong)Entities >> 0x10);
  if (*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3) != -1) {
    bVar4 = ovr_agnt_compute10((agnt_t *)CONCAT22(uVar7,(entity_t *)Entities + entityIndex));
    bVar2 = *(byte *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3);
    for (cStack_6 = '\0'; cStack_6 < '\x04'; cStack_6 = cStack_6 + '\x01') {
      uVar3 = *(undefined4 *)((uint)bVar2 << 2);
      if ((*(int *)((int)uVar3 + cStack_6 * 2 + 0x76) != 0) && ((int)(char)bVar4 < cStack_6 + 1)) {
        cStack_7 = cStack_6;
        uVar3 = *(undefined4 *)((uint)bVar2 << 2);
        piVar1 = (int *)((int)uVar3 + cStack_6 * 2 + 0x76);
        *piVar1 = *piVar1 + -1;
        uVar7 = (undefined2)((ulong)Entities >> 0x10);
        peVar6 = (entity_t *)Entities;
        peVar6[entityIndex].dir =
             peVar6[entityIndex].dir + (char)(((ulong)peVar6[entityIndex].dir / 6) % 6) * -6;
        bVar2 = ((entity_t *)Entities)[entityIndex].base.gindex;
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar2 * 0x95) == '\x03') &&
           ('\x01' < cStack_6)) {
          cStack_7 = '\x01';
        }
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar2 * 0x95) == '\x01') &&
           ('\x02' < cStack_7)) {
          cStack_7 = '\x02';
        }
        cVar5 = ovc22_compute3(cStack_7 + '\x01');
        uVar7 = (undefined2)((ulong)Entities >> 0x10);
        ((entity_t *)Entities)[entityIndex].dir =
             ((entity_t *)Entities)[entityIndex].dir + cVar5 * '\x06';
        return;
      }
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
    dividendLo = LXMUL_at_((long *)((int)&GSTARTX_SavedVectors[2].ofs + 1),
                           CONCAT22(unaff_BP,unaff_SI),in_stack_00000000);
    uVar1 = LUDIV_at_((int)dividendLo,valueHi,divisorLo,divisorHi);
    valueLo = (uint16_t)uVar1;
  }
  return valueLo;
}



/* 5087:1d7d */

/* [R4] calls ovr_alignUp4 */

void __cdecl16far upd_usesAlignUp4(void)

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
  long *plVar16;
  unit_t *puVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  entity_t *peVar21;
  int iVar22;
  entity_t *peVar23;
  undefined2 unaff_SI;
  uint uVar24;
  undefined2 uVar25;
  undefined2 uVar26;
  undefined2 uVar27;
  uint16_t unaff_SS;
  bool bVar28;
  far_t table;
  uint8_t *puVar29;
  uint16_t uVar30;
  uint8_t *puVar31;
  uint16_t uVar32;
  uint8_t outFlagSeg;
  uint8_t *puVar33;
  uint8_t uVar34;
  undefined1 uVar35;
  undefined1 uVar36;
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
  uint16_t uStack_8;
  byte bStack_6;
  byte bStack_5;
  uint uStack_4;
  
  a = CONCAT22((int)((ulong)in_stack_0000ffd0 >> 0x10),unaff_SI);
  if (!GameRunning) {
    cStack_1d = '\0';
    found = 0x0;
    for (uStack_16 = 0xf8; uStack_16 < GUnitCount; uStack_16 = uStack_16 + 1) {
      pbVar1 = &((unit_t *)GUnits)[uStack_16].flags;
      *pbVar1 = *pbVar1 & 0xfc;
    }
    for (uStack_16 = 0; (int)uStack_16 < (int)(uint)GLeaderCount; uStack_16 = uStack_16 + 1) {
      if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3d) != '\0') {
        ovc22_textRingProt((byte)uStack_16);
      }
    }
    GGameState = 0x3e;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    uVar24 = 0xf8;
    while( true ) {
      outFlagSeg = (uint8_t)unaff_SS;
      if (GUnitCount <= uVar24) break;
      uVar25 = (undefined2)((ulong)GUnits >> 0x10);
      puVar17 = (unit_t *)GUnits;
      if ((puVar17[uVar24].flags & 3) == 0) {
        if ((puVar17[uVar24].unitType == 0xff) ||
           (uVar6 = *(undefined4 *)((uint)puVar17[uVar24].unitType << 2),
           *(char *)((int)uVar6 + 0x3f) == '\0')) {
          uStack_8 = 0x96;
        }
        else {
          uStack_8 = 0x5dc;
        }
        if (puVar17[uVar24].level != 0) {
          uVar11 = ovr_randBelow(uStack_8);
          uVar25 = (undefined2)((ulong)GUnits >> 0x10);
          puVar17 = (unit_t *)GUnits;
          if ((int)(uVar11 & 0xff) <
              (int)(100 - (uint)*(byte *)((uint)(puVar17 + uVar24)->bldType * 0x27 + 0x130))) {
            bldType = (puVar17 + uVar24)->bldType;
            puVar17[uVar24].level = puVar17[uVar24].level - 1;
            puVar17 = (unit_t *)GUnits;
            uVar25 = (undefined2)((ulong)GUnits >> 0x10);
            if (((*(uint *)((uint)bldType * 0x27 + 0x121) & 4) == 0) &&
               ((puVar17[uVar24].level == 0 ||
                ((*(uint *)((uint)bldType * 0x27 + 0x121) & 0x200) != 0)))) {
              ovc22_usesGUnits(uVar24,&found,outFlagSeg);
            }
            else if (((((bld_inst_t *)BldInstances + bldType)->ofs != 0 ||
                       *(int *)((int)&BldInstances[0].seg + (uint)bldType * 0xc) != 0) ||
                     (*(char *)((uint)bldType * 0x27 + 0x11e) == '\x10')) &&
                    (uVar25 = ovc22_usesGOngoingBattle2
                                        (*(byte *)&puVar17[uVar24].x,*(byte *)&puVar17[uVar24].y),
                    (char)uVar25 != '\0')) {
              found = 0x1;
            }
          }
        }
      }
      uVar24 = uVar24 + 1;
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
        uVar24 = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54);
        uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar18 = *(int *)(iVar18 + 0x58) + ((int)uVar24 >> 0xf) +
                 (uint)CARRY2(*(uint *)(iVar18 + 0x56),uVar24);
        if ((iVar18 < 1) && (iVar18 < 0)) {
          for (uVar24 = 0xf8; uVar24 < GUnitCount; uVar24 = uVar24 + 1) {
            uVar25 = (undefined2)((ulong)GUnits >> 0x10);
            puVar17 = (unit_t *)GUnits;
            bldType = (puVar17 + uVar24)->bldType;
            if ((puVar17[uVar24].unitType == uStack_16) &&
               (*(int *)((uint)bldType * 0x27 + 0x123) < 0)) {
              uVar12 = *(uint *)((uint)bldType * 0x27 + 0x123);
              uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
              iVar18 = *(int *)(iVar18 + 0x58) + ((int)uVar12 >> 0xf) +
                       (uint)CARRY2(*(uint *)(iVar18 + 0x56),uVar12);
              if ((iVar18 < 1) && (iVar18 < 0)) {
                if ((cVar10 == '\0') && (puVar17[uVar24].level != 0)) {
                  uVar11 = ovr_randBelow(100);
                  uVar25 = (undefined2)((ulong)GUnits >> 0x10);
                  puVar17 = (unit_t *)GUnits;
                  if (*(byte *)((uint)(puVar17 + uVar24)->bldType * 0x27 + 0x130) <= (byte)uVar11) {
                    if (puVar17[uVar24].level != 0) {
                      puVar17[uVar24].level = puVar17[uVar24].level - 1;
                    }
                    puVar17 = (unit_t *)GUnits;
                    uVar25 = (undefined2)((ulong)GUnits >> 0x10);
                    if (((*(uint *)((uint)bldType * 0x27 + 0x121) & 4) == 0) &&
                       ((puVar17[uVar24].level == 0 ||
                        ((*(uint *)((uint)bldType * 0x27 + 0x121) & 0x200) != 0)))) {
                      ovc22_usesGUnits(uVar24,&found,outFlagSeg);
                    }
                    else if (((((bld_inst_t *)BldInstances + bldType)->ofs != 0 ||
                               *(int *)((int)&BldInstances[0].seg + (uint)bldType * 0xc) != 0) ||
                             (*(char *)((uint)bldType * 0x27 + 0x11e) == '\x10')) &&
                            (uVar25 = ovc22_usesGOngoingBattle2
                                                (*(byte *)&puVar17[uVar24].x,
                                                 *(byte *)&puVar17[uVar24].y), (char)uVar25 != '\0')
                            ) {
                      found = 0x1;
                    }
                  }
                }
              }
              else {
                uVar13 = *(uint *)((uint)bldType * 0x27 + 0x123);
                uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
                iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
                puVar2 = (uint *)(iVar18 + 0x56);
                uVar12 = *puVar2;
                *puVar2 = *puVar2 + uVar13;
                piVar3 = (int *)(iVar18 + 0x58);
                *piVar3 = *piVar3 + ((int)uVar13 >> 0xf) + (uint)CARRY2(uVar12,uVar13);
              }
            }
          }
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar18 + 0x58) = 0;
          *(undefined2 *)(iVar18 + 0x56) = 0;
        }
        else {
          if ((cVar10 == '\0') && (0 < *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54))) {
            uStack_10 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54) / 10;
          }
          else {
            uStack_10 = 0;
          }
          bVar28 = CARRY2(GPopulationLo,uStack_10);
          GPopulationLo = GPopulationLo + uStack_10;
          GPopulationHi = GPopulationHi + ((int)uStack_10 >> 0xf) + (uint)bVar28;
          uVar12 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54) - uStack_10;
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
          puVar2 = (uint *)(iVar18 + 0x56);
          uVar24 = *puVar2;
          *puVar2 = *puVar2 + uVar12;
          piVar3 = (int *)(iVar18 + 0x58);
          *piVar3 = *piVar3 + ((int)uVar12 >> 0xf) + (uint)CARRY2(uVar24,uVar12);
        }
        if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3e) * 0x95) & 0x100)
            == 0) {
          if (*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f) <
              *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d)) {
            uStack_12 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d) -
                        *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f);
            uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar22 = (int)*(undefined4 *)(uStack_16 << 2);
            iVar18 = *(int *)(iVar22 + 0x62);
            if ((-1 < iVar18) && ((0 < iVar18 || (*(int *)(iVar22 + 0x60) != 0)))) {
              uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar24 = *(uint *)(iVar18 + 0x62);
              if ((0x7fff < uVar24) ||
                 ((uStack_14 = uStack_12, (int)uVar24 < 1 && (*(uint *)(iVar18 + 0x60) <= uStack_12)
                  ))) {
                uStack_14 = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x60);
              }
              uStack_12 = uStack_12 - uStack_14;
              uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar2 = (uint *)(iVar18 + 0x60);
              uVar24 = *puVar2;
              *puVar2 = *puVar2 - uStack_14;
              piVar3 = (int *)(iVar18 + 0x62);
              *piVar3 = *piVar3 - (uint)(uVar24 < uStack_14);
            }
            if (uStack_12 != 0) {
              uStack_a = uStack_12;
              if (*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0) < uStack_12) {
                uStack_a = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0);
              }
              uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar24 = *(uint *)(iVar18 + 0x58);
              if (((int)uVar24 < 1) && ((0x7fff < uVar24 || (*(uint *)(iVar18 + 0x56) < uStack_a))))
              {
                uStack_a = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x56);
              }
              uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar2 = (uint *)(iVar18 + 0x56);
              uVar24 = *puVar2;
              *puVar2 = *puVar2 - uStack_a;
              piVar3 = (int *)(iVar18 + 0x58);
              *piVar3 = *piVar3 - (uint)(uVar24 < uStack_a);
              uStack_12 = uStack_12 - uStack_a;
              *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa2) = uStack_a;
            }
            if (cVar10 == '\0') {
              for (iVar18 = 0; (uStack_12 != 0 && (iVar18 < (int)(uint)GLeaderCount));
                  iVar18 = iVar18 + 1) {
                if ((*(char *)((int)*(undefined4 *)(iVar18 << 2) + 0x3d) != '\0') &&
                   ((*(char *)((int)*(undefined4 *)(iVar18 << 2) + 0x3f) == '\0' &&
                    (uVar25 = (undefined2)((ulong)*(undefined4 *)(iVar18 << 2) >> 0x10),
                    iVar22 = (int)*(undefined4 *)(iVar18 << 2),
                    *(int *)(iVar22 + 0x60) != 0 || *(int *)(iVar22 + 0x62) != 0)))) {
                  uVar25 = (undefined2)((ulong)*(undefined4 *)(iVar18 << 2) >> 0x10);
                  iVar22 = (int)*(undefined4 *)(iVar18 << 2);
                  uVar24 = *(uint *)(iVar22 + 0x62);
                  if ((uVar24 < 0x8000) &&
                     ((0 < (int)uVar24 || (uStack_12 < *(uint *)(iVar22 + 0x60))))) {
                    uStack_14 = uStack_12;
                  }
                  else {
                    uStack_14 = *(uint *)((int)*(undefined4 *)(iVar18 << 2) + 0x60);
                  }
                  uStack_12 = uStack_12 - uStack_14;
                  uVar25 = (undefined2)((ulong)*(undefined4 *)(iVar18 << 2) >> 0x10);
                  iVar22 = (int)*(undefined4 *)(iVar18 << 2);
                  puVar2 = (uint *)(iVar22 + 0x60);
                  uVar24 = *puVar2;
                  *puVar2 = *puVar2 - uStack_14;
                  piVar3 = (int *)(iVar22 + 0x62);
                  *piVar3 = *piVar3 - (uint)(uVar24 < uStack_14);
                }
              }
            }
            uVar24 = 0;
            while ((uVar24 < EntityCount && (uStack_12 != 0))) {
              uVar25 = (undefined2)((ulong)Entities >> 0x10);
              peVar21 = (entity_t *)Entities;
              if (((*(char *)((int)&peVar21[uVar24].base.entity + 1) == '\0') &&
                  (*(byte *)((int)&peVar21[uVar24].base.entity + 3) == uStack_16)) &&
                 ((bVar7 || (1 < peVar21[uVar24].base.animFrame)))) {
                if (peVar21[uVar24].base.animFrame != 0x0) {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  puVar4 = &((entity_t *)Entities)[uVar24].base.animFrame;
                  *puVar4 = *puVar4 + 0xff;
                  if (((entity_t *)Entities)[uVar24].base.animFrame == 0x0) {
                    cStack_1d = '\x01';
                  }
                }
                uStack_12 = uStack_12 - 1;
              }
              uVar24 = uVar24 + 1;
            }
          }
          else {
            uVar12 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f) -
                     *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d);
            uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
            puVar2 = (uint *)(iVar18 + 0x60);
            uVar24 = *puVar2;
            *puVar2 = *puVar2 + uVar12;
            piVar3 = (int *)(iVar18 + 0x62);
            *piVar3 = *piVar3 + (uint)CARRY2(uVar24,uVar12);
          }
        }
        uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar18 = *(int *)(iVar19 + 0x62);
        uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar22 = *(int *)(iVar20 + 0x80);
        if ((iVar22 <= iVar18) &&
           ((iVar22 < iVar18 || (*(uint *)(iVar20 + 0x7e) < *(uint *)(iVar19 + 0x60))))) {
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
          uVar24 = *(uint *)(iVar18 + 0x60);
          uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar22 = (int)*(undefined4 *)(uStack_16 << 2);
          puVar2 = (uint *)(iVar22 + 0x7e);
          uVar12 = (uint)(uVar24 < *puVar2);
          uVar13 = *(int *)(iVar18 + 0x62) - *(int *)(iVar22 + 0x80);
          if (((int)(uVar13 - uVar12) < 0) ||
             ((uVar13 == uVar12 &&
              (uVar24 - *puVar2 <= *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0))))) {
            uStack_a = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x60) -
                       *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7e);
          }
          else {
            uStack_a = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0);
          }
          *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa2) = -uStack_a;
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
          puVar2 = (uint *)(iVar18 + 0x56);
          uVar24 = *puVar2;
          *puVar2 = *puVar2 + uStack_a;
          piVar3 = (int *)(iVar18 + 0x58);
          *piVar3 = *piVar3 + (uint)CARRY2(uVar24,uStack_a);
          uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
          uVar25 = *(undefined2 *)(iVar18 + 0x7e);
          uVar27 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar22 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar22 + 0x62) = *(undefined2 *)(iVar18 + 0x80);
          *(undefined2 *)(iVar22 + 0x60) = uVar25;
        }
        if ((*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x5b) <
             *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d)) &&
           ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3e) * 0x95) & 0x80)
            == 0)) {
          uStack_12 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d) -
                      *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x5b);
          uVar24 = 0;
          while ((uVar24 < EntityCount && (uStack_12 != 0))) {
            uVar25 = (undefined2)((ulong)Entities >> 0x10);
            peVar21 = (entity_t *)Entities;
            if ((*(byte *)((int)&peVar21[uVar24].base.entity + 3) == uStack_16) &&
               ((((*(char *)((int)&peVar21[uVar24].base.entity + 1) == '\0' &&
                  (peVar21[uVar24].base.destX == 0)) && (peVar21[uVar24].base.destY == 0)) &&
                (3 < peVar21[uVar24].base.animFrame)))) {
              if (DebugVerbose != false) {
                printf("kill 2 \r");
              }
              puVar4 = &((entity_t *)Entities)[uVar24].base.animFrame;
              *puVar4 = *puVar4 + 0xff;
              uStack_12 = uStack_12 - 1;
            }
            uVar24 = uVar24 + 1;
          }
        }
        ovr_ovc25_tickCountdown(uStack_16);
        _fmemset((void *)(*(int *)(uStack_16 * 4) + 0x6a),((int *)(uStack_16 * 4))[1],0);
        _fmemset((void *)(*(int *)(uStack_16 * 4) + 0x76),((int *)(uStack_16 * 4))[1],0);
        uVar11 = ovr_randBelow(100);
        if ((byte)uVar11 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6c) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 100);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6a) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 100);
        }
        uVar11 = ovr_randBelow(100);
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
        uVar11 = ovr_randBelow(100);
        if ((byte)uVar11 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x78) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x70);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x76) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x70);
        }
        uVar11 = ovr_randBelow(100);
        if ((byte)uVar11 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7a) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x72);
        }
        else {
          piVar3 = (int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x78);
          *piVar3 = *piVar3 + *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x72);
        }
        uVar11 = ovr_randBelow(100);
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
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar22 = (int)*(undefined4 *)(uStack_16 << 2);
          iVar18 = *(int *)(iVar22 + 0x58);
          if ((iVar18 < 1) && ((iVar18 != 0 || (*(int *)(iVar22 + 0x56) == 0)))) {
            uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
            *(undefined2 *)(iVar18 + 0x58) = 0;
            *(undefined2 *)(iVar18 + 0x56) = 0x32;
          }
        }
        if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0xaa) != '\0') {
          uStack_4 = (uint)*(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xaa);
          for (uVar24 = 0; (int)uVar24 < (int)(uint)GLeaderCount; uVar24 = uVar24 + 1) {
            uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
            iVar18 = *(int *)(iVar19 + 0x58);
            uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
            iVar22 = *(int *)(iVar20 + 0x8c);
            if ((iVar22 <= iVar18) &&
               ((iVar18 != iVar22 || (*(uint *)(iVar20 + 0x8a) <= *(uint *)(iVar19 + 0x56)))))
            break;
            if ((*(char *)((int)*(undefined4 *)(uVar24 << 2) + 0x3d) != '\0') &&
               (((0 < *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x54) &&
                 (*(char *)((int)*(undefined4 *)(uVar24 << 2) + 0x3f) == '\0')) &&
                (uVar24 != uStack_16)))) {
              uVar13 = (uint)(((long)*(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x54) *
                               (long)(int)uStack_4 & 0xffffU) / 100);
              uVar9 = in_stack_0000ffd4 >> 0x10;
              in_stack_0000ffd4 = in_stack_0000ffd4 & 0xffff0000;
              uVar27 = (undefined2)a;
              a = CONCAT22(uVar13,uVar27);
              uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar12 = *(uint *)(iVar18 + 0x8a);
              uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar22 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar2 = (uint *)(iVar22 + 0x56);
              iVar18 = (*(int *)(iVar18 + 0x8c) - *(int *)(iVar22 + 0x58)) -
                       (uint)(uVar12 < *puVar2);
              if ((iVar18 < 1) && ((iVar18 < 0 || (uVar12 - *puVar2 < uVar13)))) {
                uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
                iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
                uVar12 = *(uint *)(iVar18 + 0x8a);
                uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
                iVar22 = (int)*(undefined4 *)(uStack_16 << 2);
                puVar2 = (uint *)(iVar22 + 0x56);
                in_stack_0000ffd4 =
                     CONCAT22((int)uVar9,
                              (*(int *)(iVar18 + 0x8c) - *(int *)(iVar22 + 0x58)) -
                              (uint)(uVar12 < *puVar2));
                a = CONCAT22(uVar12 - *puVar2,uVar27);
              }
              uVar25 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
              iVar22 = (int)*(undefined4 *)(uVar24 << 2);
              iVar18 = *(int *)(iVar22 + 0x58);
              if ((iVar18 <= (int)in_stack_0000ffd4) &&
                 ((iVar18 < (int)in_stack_0000ffd4 ||
                  (*(uint *)(iVar22 + 0x56) < (uint)((ulong)a >> 0x10))))) {
                uVar25 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
                iVar18 = (int)*(undefined4 *)(uVar24 << 2);
                in_stack_0000ffd4 =
                     CONCAT22((int)(in_stack_0000ffd4 >> 0x10),*(undefined2 *)(iVar18 + 0x58));
                a = CONCAT22(*(undefined2 *)(iVar18 + 0x56),(int)a);
              }
              uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar13 = (uint)((ulong)a >> 0x10);
              puVar2 = (uint *)(iVar18 + 0x56);
              uVar12 = *puVar2;
              *puVar2 = *puVar2 + uVar13;
              piVar3 = (int *)(iVar18 + 0x58);
              *piVar3 = *piVar3 + (int)in_stack_0000ffd4 + (uint)CARRY2(uVar12,uVar13);
              uVar25 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uVar24 << 2);
              puVar2 = (uint *)(iVar18 + 0x56);
              uVar12 = *puVar2;
              *puVar2 = *puVar2 - uVar13;
              piVar3 = (int *)(iVar18 + 0x58);
              *piVar3 = (*piVar3 - (int)in_stack_0000ffd4) - (uint)(uVar12 < uVar13);
            }
          }
        }
        iVar18 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x58);
        if ((iVar18 < 1) && (iVar18 < 0)) {
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar18 + 0x58) = 0;
          *(undefined2 *)(iVar18 + 0x56) = 0;
        }
        uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar18 = *(int *)(iVar19 + 0x58);
        uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar22 = *(int *)(iVar20 + 0x8c);
        if ((iVar22 <= iVar18) &&
           ((iVar22 < iVar18 || (*(uint *)(iVar20 + 0x8a) < *(uint *)(iVar19 + 0x56))))) {
          uVar26 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
          uVar25 = *(undefined2 *)(iVar18 + 0x8a);
          uVar27 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar22 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar22 + 0x58) = *(undefined2 *)(iVar18 + 0x8c);
          *(undefined2 *)(iVar22 + 0x56) = uVar25;
        }
      }
    }
    GGameState = 0x40;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (uVar24 = 0xf8; uVar24 < GUnitCount; uVar24 = uVar24 + 1) {
      uVar25 = (undefined2)((ulong)GUnits >> 0x10);
      puVar17 = (unit_t *)GUnits;
      if ((*(uint *)((uint)(puVar17 + uVar24)->bldType * 0x27 + 0x121) & 0x40) != 0) {
        if (puVar17[uVar24].timer != 0) {
          puVar17[uVar24].timer = puVar17[uVar24].timer - 1;
        }
        uVar25 = (undefined2)((ulong)GUnits >> 0x10);
        if (((unit_t *)GUnits)[uVar24].timer == 0) {
          uVar6 = *(undefined4 *)((uint)((unit_t *)GUnits)[uVar24].unitType << 2);
          if (*(char *)((int)uVar6 + 0x3f) == '\0') {
            ovr_play_sfx(81,0);
            ovr_alignUp4(((unit_t *)GUnits)[uVar24].x);
            pcVar14 = ovr_fmVsprintf((char *)"Mine exhausted at (%d, %d).",(char *)"puppetmaker" + 3
                                    );
            ovr_say(pcVar14);
            ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
          }
          ovc22_usesGUnits(uVar24,&found,outFlagSeg);
        }
      }
    }
    GGameState = 0x42;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    ovr_driver_clearMapFlagsRect((uint32_t)GMapFlags,0,0,0x93,0x3b,0xfff7);
    for (uStack_16 = 0; uStack_16 < SquareRecCount; uStack_16 = uStack_16 + 1) {
      puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[*(int *)(uStack_16 * 0x13 + 2)] +
                       *(int *)(uStack_16 * 0x13));
      *puVar2 = *puVar2 | 8;
    }
    if (EntityCount <= EntityScanPos) {
      EntityScanPos = 0;
      for (uStack_16 = 0; (int)uStack_16 < (int)(uint)GLeaderCount; uStack_16 = uStack_16 + 1) {
        if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3d) != '\0') {
          iVar18 = ((int *)(uStack_16 * 4))[1];
          memcpy((char *)CONCAT22(((int *)(uStack_16 * 4))[1],
                                  (char *)(*(int *)(uStack_16 * 4) + 0x8e)),
                 (char *)CONCAT13((char)((uint)iVar18 >> 8),
                                  CONCAT12((char)iVar18,*(int *)(uStack_16 * 4) + 0x94)),3);
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
      uVar25 = (undefined2)((ulong)Entities >> 0x10);
      peVar21 = (entity_t *)Entities;
      if (((*(char *)((int)&peVar21[uStack_16].base.entity + 1) == '\0') &&
          (peVar21[uStack_16].base.destX == 0)) && (peVar21[uStack_16].base.destY == 0)) {
        bStack_6 = peVar21[uStack_16].base.gindex;
        cVar10 = *(char *)((int)(char **)GMenuStrings + (uint)bStack_6 * 0x95 + 0x1f);
        bVar5 = *(byte *)((int)&peVar21[uStack_16].base.entity + 3);
        bVar28 = false;
        bVar8 = false;
        bVar7 = false;
        if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bStack_6 * 0x95) == -1) {
          bVar28 = true;
        }
        else {
          bStack_1b = *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x89);
          if (bStack_1b < 5) {
            uStack_1a = peVar21[uStack_16].base.y;
            uStack_18 = ovr_alignUp4(((peVar21 + uStack_16)->base).x);
            uVar11 = 0x2410;
            if (((*(short (*) [60] [148])GMapFlags)[uStack_1a][uStack_18] & 8U) == 0) {
              successWeight = 0x22;
              partialWeight = 0x21;
              bldType = 0x22;
            }
            else {
              puVar33 = &successWeight;
              puVar31 = &partialWeight;
              puVar29 = &bldType;
              index = CONCAT11((char)((uint)puVar29 >> 8),bStack_1b);
              uVar30 = unaff_SS;
              uVar32 = unaff_SS;
              uVar34 = outFlagSeg;
              uVar35 = (char)(unaff_SS >> 8);
              uVar15 = ovr_attact_usesSquareRecCount(uStack_18,uStack_1a);
              table.seg = uVar11;
              table.ofs = uVar15;
              pctOut.seg = uVar30;
              pctOut.ofs = (uint16_t)puVar29;
              remainderOut.seg = uVar32;
              remainderOut.ofs = (uint16_t)puVar31;
              (*(uint8_t *)((uint8_t *)&(partOut.seg))) = uVar34;
              partOut.ofs = (uint16_t)puVar33;
              (*(uint8_t *)((uint8_t *)&(partOut.seg) + 1)) = uVar35;
              ovr_attact_compute3_2(table,index,pctOut,remainderOut,partOut);
            }
          }
          else {
            successWeight = 0x22;
            partialWeight = 0x21;
            bldType = 0x22;
          }
          uVar11 = ovr_randBelow(100);
          if ((byte)uVar11 < successWeight) {
            bVar28 = true;
          }
          else if ((uVar11 & 0xff) < (uint)partialWeight + (uint)successWeight) {
            bVar8 = true;
          }
          else {
            bVar7 = true;
          }
        }
        if ((bVar7) &&
           (uVar25 = (undefined2)((ulong)Entities >> 0x10),
           cVar10 = ovr_ovc23_tickRecordsAt
                              ((((entity_t *)Entities + uStack_16)->base).x,
                               ((entity_t *)Entities)[uStack_16].base.y,cVar10), cVar10 == '\0')) {
          if ((partialWeight == 0x0) && (successWeight == 0x0)) {
            uVar11 = ovr_randBelow(2);
            if ((uVar11 & 0xff) == 0) {
              bVar28 = true;
            }
            else {
              bVar8 = true;
            }
          }
          else {
            uVar11 = ovr_randBelow((uint)partialWeight + (uint)successWeight);
            if ((byte)uVar11 < successWeight) {
              bVar28 = true;
            }
            else {
              bVar8 = true;
            }
          }
        }
        if ((bVar28) && (uVar24 = ovc22_usesEntities(uStack_16), (uVar24 & 0xff) == 0)) {
          bVar8 = true;
        }
        if (bVar8) {
          if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bStack_6 * 0x95) != -1) &&
             (bVar5 != 0xff)) {
            if ((*(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x3f) != '\0') ||
               (((entity_t *)Entities)[uStack_16].base.level <
                *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x53))) {
              uVar35 = (undefined1)iStack_c;
              uVar36 = (undefined1)((uint)iStack_c >> 8);
              ovc22_usesLUDIV_at_((entity_t *)
                                  CONCAT13((char)((ulong)Entities >> 0x18),
                                           CONCAT12((char)((ulong)Entities >> 0x10),
                                                    (entity_t *)Entities + uStack_16)));
              uVar24 = 0;
              plVar16 = LXMUL_at_((long *)CONCAT11(uVar36,uVar35),a,in_stack_0000ffd4);
              peVar21 = (entity_t *)Entities + uStack_16;
              uVar11 = ovr_ovc15_textError(peVar21,(*(uint16_t *)((uint8_t *)&(Entities) + 2)),
                                           (int)(CONCAT12((uVar24 & 1) != 0,plVar16) >> 1),
                                           (char)((int)uVar24 >> 1));
              uVar12 = ovc22_usesLUDIV_at_2(uVar11,(uint16_t)peVar21,CONCAT11(uVar36,uVar35));
              uVar25 = (undefined2)((ulong)Entities >> 0x10);
              peVar23 = (entity_t *)Entities;
              uVar24 = *(uint *)&peVar23[uStack_16].base.health;
              *(uint *)&peVar23[uStack_16].base.frameIndex =
                   (int)&(peVar21->base).x +
                   (uint)CARRY2(uVar24,uVar12) + *(int *)&peVar23[uStack_16].base.frameIndex;
              *(uint *)&peVar23[uStack_16].base.health = uVar24 + uVar12;
              ovr_ovc41_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                          CONCAT12((char)((ulong)Entities >> 0x10),
                                                   (entity_t *)Entities + uStack_16)));
            }
          }
          ovc22_usesEntities2(uStack_16);
          ovc22_usesEntities3(uStack_16);
          ovc22_usesEntities4(uStack_16);
        }
        iVar18 = (uint)((entity_t *)Entities)[uStack_16].base.animFrame -
                 (uint)*(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4);
        uVar25 = (undefined2)in_stack_0000ffd4;
        in_stack_0000ffd4 = CONCAT22(iVar18,uVar25);
        if (0 < iVar18) {
          if (3 < iVar18) {
            in_stack_0000ffd4 = CONCAT22(3,uVar25);
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
    uVar24 = EntityCount;
    if (cStack_1d != '\0') {
      while (uStack_16 = uVar24 - 1, -1 < (int)uStack_16) {
        uVar25 = (undefined2)((ulong)Entities >> 0x10);
        peVar21 = (entity_t *)Entities;
        uVar24 = uStack_16;
        if (peVar21[uStack_16].base.animFrame == 0x0) {
          if (*(char *)((int)(char **)GMenuStrings +
                       (uint)peVar21[uStack_16].base.gindex * 0x95 + 0x1f) == '\0') {
            ovr_alignUp4(((peVar21 + uStack_16)->base).x);
            uVar11 = 0x195d;
            pcVar14 = ovr_fmVsprintf((char *)
                                     "Intelligence reports %s unit died of starvation. (%d, %d)",
                                     (char *)"puppetmaker" + 3);
            ovr_uiNotify(pcVar14,uVar11);
          }
          ovr_ovc15_removeEntity(uStack_16);
          uVar24 = uStack_16;
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

char * __cdecl16far ovc22_textArena2(uint x,int y)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  short (*paasVar6) [148] [60];
  unit_t *puVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  
  pcVar3 = ovc22_textArena(x,y);
  if (((uint)pcVar3 & 0xff) == 0) {
    pcVar3 = (char *)0x0;
  }
  else {
    uVar8 = (undefined2)((ulong)GUnitGrid >> 0x10);
    paasVar6 = (short (*) [148] [60])GUnitGrid;
    iVar2 = (*paasVar6)[x][y];
    uVar9 = (undefined2)((ulong)GUnits >> 0x10);
    puVar7 = (unit_t *)GUnits;
    bVar1 = (puVar7 + iVar2)->bldType;
    uVar4 = CONCAT11((char)((uint)(iVar2 * 9) >> 8),bVar1);
    if ((bVar1 == 0) || (uVar4 = (uint)bVar1 * 0x27, (*(uint *)(uVar4 + 0x121) & 0x1000) != 0)) {
      if ((int)x < 4) {
        pcVar3 = (char *)(uVar4 & 0xff00);
      }
      else {
        uVar4 = (uint)(puVar7 + paasVar6[-1][x + 0x93][y])->bldType * 0x27;
        if (*(byte *)(uVar4 + 0x11b) < 2) {
          uVar4 = (uint)(puVar7 + paasVar6[-1][x + 0x92][y])->bldType * 0x27;
          if (*(byte *)(uVar4 + 0x11b) < 3) {
            uVar4 = (uint)(puVar7 + paasVar6[-1][x + 0x91][y])->bldType * 0x27;
            if (*(byte *)(uVar4 + 0x11b) < 4) {
              for (uVar4 = 0; uVar4 < GRecordCount; uVar4 = uVar4 + 1) {
                if (((*(int *)(uVar4 * 0x12 + 4) == y) && (*(uint *)(uVar4 * 0x12 + 2) <= x)) &&
                   (uVar5 = *(int *)(uVar4 * 0x12 + 2) +
                            (uint)*(byte *)((uint)*(byte *)(uVar4 * 0x12 + 8) * 0x27 + 0x11b),
                   x < uVar5)) {
                  return (char *)(uVar5 & 0xff00);
                }
              }
              pcVar3 = (char *)"arena" + 5;
            }
            else {
              pcVar3 = (char *)(uVar4 & 0xff00);
            }
          }
          else {
            pcVar3 = (char *)(uVar4 & 0xff00);
          }
        }
        else {
          pcVar3 = (char *)(uVar4 & 0xff00);
        }
      }
    }
    else {
      pcVar3 = (char *)(uVar4 & 0xff00);
    }
  }
  return pcVar3;
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
    uVar2 = ovr_alignUp4(x);
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
    uVar2 = ovr_ovc23_findRecordAt(x,y);
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
  
  if ((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 4) == 0) {
    uVar1 = (*(short (*) [148] [60])GUnitGrid)[x][y];
    if (uVar1 < 0xf8) {
      uVar2 = ovr_ovc23_findRecordAt(x,y);
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
  
  uVar1 = (*(short (*) [148] [60])GUnitGrid)[x][y];
  if (uVar1 < 0xf8) {
    uVar2 = ovr_ovc23_findRecordAt(x,y);
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
  char *pcVar1;
  int iVar2;
  byte bVar3;
  
  pcVar1 = ovc22_textArena(x,y);
  if (((uint)pcVar1 & 0xff) == 0) {
    iVar2 = 0;
  }
  else {
    bVar3 = (byte)(mask >> 8);
    if (((*(short (*) [60] [148])GMapFlags)[y][x] & mask) == 0) {
      iVar2 = CONCAT11(bVar3,1);
    }
    else {
      iVar2 = (uint)bVar3 << 8;
    }
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
  uint uVar4;
  uint uStack_4;
  
  uStack_4 = 0;
  do {
    if (GRecordCount <= uStack_4) {
      return GRecordCount & 0xff00;
    }
    if (*(uint8_t *)(uStack_4 * 0x12 + 9) == classIndex) {
      uVar2 = ovr_alignUp4(*(int *)(uStack_4 * 0x12 + 2));
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
  uint16_t mask;
  uint uVar2;
  uint16_t uVar3;
  undefined2 uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined1 in_stack_00000009;
  undefined1 in_stack_0000000b;
  byte in_stack_0000000e;
  char in_stack_00000010;
  char cStack_8;
  char cStack_7;
  int iStack_6;
  int iStack_4;
  
  _yOutOfs = (uint *)CONCAT13(in_stack_0000000b,
                              CONCAT12(yOutSeg,(uint16_t *)CONCAT11(in_stack_00000009,yOutOfs)));
  x1 = *_xPtr;
  y1 = *_yOutOfs;
  skipCheck = *(byte *)((int)*(undefined4 *)((uint)(byte)partyIndex << 2) + 0x3f);
  mask = 0x1000 << (skipCheck & 0x1f);
  uVar2 = ovc22_usesAlignUp4(*_xPtr,*_yOutOfs,partyIndex,mask);
  if ((char)uVar2 == '\0') {
    uVar3 = ovc22_usesAlignUp42((uint16_t *)CONCAT22(yPtr,xPtr),
                                (uint16_t *)
                                CONCAT22((int)((ulong)_yOutOfs >> 0x10),
                                         (uint16_t *)CONCAT11(in_stack_00000009,yOutOfs)),partyIndex
                                ,mask);
    if ((char)uVar3 == '\0') {
      for (iStack_4 = 1; iStack_4 < 0x94; iStack_4 = iStack_4 + 1) {
        for (iStack_6 = 0; iStack_6 <= iStack_4; iStack_6 = iStack_6 + 1) {
          for (cStack_7 = -1; cStack_7 < '\x02'; cStack_7 = cStack_7 + '\x02') {
            for (cStack_8 = -1; cStack_8 < '\x02'; cStack_8 = cStack_8 + '\x02') {
              *_xPtr = x1 + cStack_7 * iStack_6;
              if (cStack_7 < '\0') {
                *_xPtr = *_xPtr - 1;
              }
              *_yOutOfs = y1 + cStack_8 * iStack_4;
              if ((((3 < *_xPtr) && (*_xPtr < 0x90)) && (*_yOutOfs != 0)) && (*_yOutOfs < 0x3b)) {
                uVar2 = ovc22_usesAlignUp4(*_xPtr,*_yOutOfs,partyIndex,mask);
                if ((char)uVar2 != '\0') {
                  return uVar2 & 0xff00;
                }
                if ((skipCheck != 0) && (uVar2 = ovc22_usesGUnitGrid(*_xPtr,*_yOutOfs), uVar2 != 0))
                {
                  return CONCAT11((char)(uVar2 >> 8),1);
                }
                if (((in_stack_0000000e == 3) &&
                    (uVar4 = ovc22_testMapFlags(*_xPtr,*_yOutOfs,mask), (char)uVar4 != '\0')) &&
                   (uVar2 = ovc22_usesGMapFlags2(skipCheck,x1,y1,*_xPtr,*_yOutOfs),
                   (char)uVar2 != '\0')) {
                  return uVar2 & 0xff00;
                }
                if ((((in_stack_0000000e & 1) == 0) && (in_stack_00000010 == '\0')) &&
                   (pcVar5 = ovc22_textArena2(*_xPtr,*_yOutOfs), (char)pcVar5 != '\0')) {
                  uVar4 = ovc22_usesGMapFlags2(skipCheck,x1,y1,*_xPtr,*_yOutOfs);
                  if ((char)uVar4 != '\0') {
                    return CONCAT11((char)((uint)uVar4 >> 8),1);
                  }
                }
                if (((in_stack_0000000e & 2) == 0) &&
                   (uVar2 = ovc22_usesGUnitGrid2(*_xPtr,*_yOutOfs,partyIndex), uVar2 != 0)) {
                  uVar4 = ovc22_usesGMapFlags2(skipCheck,x1,y1,*_xPtr,*_yOutOfs);
                  if ((char)uVar4 != '\0') {
                    return CONCAT11((char)((uint)uVar4 >> 8),1);
                  }
                }
              }
              *_xPtr = x1 + cStack_7 * iStack_4;
              if (cStack_7 < '\0') {
                *_xPtr = *_xPtr - 1;
              }
              *_yOutOfs = y1 + cStack_8 * iStack_6;
              if (((3 < *_xPtr) && (*_xPtr < 0x90)) && ((*_yOutOfs != 0 && (*_yOutOfs < 0x3b)))) {
                uVar2 = ovc22_usesAlignUp4(*_xPtr,*_yOutOfs,partyIndex,mask);
                if ((char)uVar2 != '\0') {
                  return uVar2 & 0xff00;
                }
                if ((skipCheck != 0) && (uVar2 = ovc22_usesGUnitGrid(*_xPtr,*_yOutOfs), uVar2 != 0))
                {
                  return CONCAT11((char)(uVar2 >> 8),1);
                }
                if ((((in_stack_0000000e & 3) == 3) &&
                    (uVar4 = ovc22_testMapFlags(*_xPtr,*_yOutOfs,mask), (char)uVar4 != '\0')) &&
                   (uVar2 = ovc22_usesGMapFlags2(skipCheck,x1,y1,*_xPtr,*_yOutOfs),
                   (char)uVar2 != '\0')) {
                  return uVar2 & 0xff00;
                }
                if ((((in_stack_0000000e & 1) == 0) && (in_stack_00000010 == '\0')) &&
                   (pcVar5 = ovc22_textArena2(*_xPtr,*_yOutOfs), (char)pcVar5 != '\0')) {
                  uVar4 = ovc22_usesGMapFlags2(skipCheck,x1,y1,*_xPtr,*_yOutOfs);
                  if ((char)uVar4 != '\0') {
                    return CONCAT11((char)((uint)uVar4 >> 8),1);
                  }
                }
                if (((in_stack_0000000e & 2) == 0) &&
                   (uVar2 = ovc22_usesGUnitGrid2(*_xPtr,*_yOutOfs,partyIndex), uVar2 != 0)) {
                  uVar4 = ovc22_usesGMapFlags2(skipCheck,x1,y1,*_xPtr,*_yOutOfs);
                  if ((char)uVar4 != '\0') {
                    return CONCAT11((char)((uint)uVar4 >> 8),1);
                  }
                }
              }
            }
          }
        }
      }
      puVar6 = (undefined4 *)0x0;
      if ((in_stack_0000000e & 1) == 0) {
        puVar6 = (undefined4 *)((uint)(byte)partyIndex << 2);
        pbVar1 = (byte *)((int)*puVar6 + 0x5d);
        *pbVar1 = *pbVar1 | 2;
      }
      *_xPtr = x1;
      *_yOutOfs = y1;
      uVar2 = (uint)puVar6 & 0xff00;
    }
    else {
      uVar2 = uVar3 & 0xff00;
    }
  }
  else {
    uVar2 = uVar2 & 0xff00;
  }
  return uVar2;
}



/* 5087:4576 */

/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc22_usesRandBelow(byte partyIndex,uint16_t x,uint16_t y)

{
  byte bVar1;
  uint uVar2;
  uint16_t uVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  
  if (((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 2) == 0) ||
     ((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 4) == 0)) {
    if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3f) == '\0') {
      uVar2 = ovc22_usesGUnitGrid2(x,y,partyIndex);
      if ((*(uint *)(uVar2 * 0x27 + 0x121) & 0x20) == 0) {
        if ((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 2) == 0) {
          uVar6 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
          iVar4 = (int)*(undefined4 *)((uint)partyIndex << 2);
          if (*(int *)(iVar4 + 0x56) == 0 && *(int *)(iVar4 + 0x58) == 0) {
            uVar2 = 0;
          }
          else {
            uVar6 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
            iVar4 = (int)*(undefined4 *)((uint)partyIndex << 2);
            if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4f) <
                (uint)(*(int *)(iVar4 + 0x4d) * 2 + *(int *)(iVar4 + 0x4d)) >> 2) {
              uVar2 = 0;
            }
            else {
              iVar4 = ovr_bldng_getClass(partyIndex);
              uVar2 = ovr_bldng_usesRandBelow((byte)iVar4);
              uVar2 = uVar2 & 0xff;
              uVar6 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
              iVar5 = (int)*(undefined4 *)((uint)partyIndex << 2);
              iVar4 = *(int *)(iVar5 + 0x58);
              if ((iVar4 < 0) ||
                 ((iVar4 == 0 && (*(uint *)(iVar5 + 0x56) < *(uint *)(uVar2 * 0x27 + 0x125))))) {
                uVar2 = 0;
              }
            }
          }
        }
        else {
          uVar2 = 0;
        }
      }
    }
    else {
      uVar2 = ovc22_usesGUnitGrid(x,y);
      if ((*(uint *)(uVar2 * 0x27 + 0x121) & 2) == 0) {
        uVar3 = ovr_randBelow(2);
        if (((uVar3 & 0xff) == 0) && ((*(uint *)(uVar2 * 0x27 + 0x121) & 0x20) != 0)) {
          if (*(char *)(uVar2 * 0x27 + 0x131) == '\0') {
            uVar2 = uVar2 + 6;
          }
        }
        else {
          uVar3 = ovr_randBelow(8);
          if (((uVar3 & 0xff) == 0) ||
             ((uVar3 = ovr_randBelow(3), (uVar3 & 0xff) == 0 &&
              (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4f) <
               *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d))))) {
            uVar3 = ovr_randBelow(3);
            uVar2 = (uVar3 & 0xff) + 1;
          }
          else {
            uVar3 = ovr_randBelow(0xc);
            if ((uVar3 & 0xff) == 0) {
              uVar3 = ovr_randBelow(3);
              uVar2 = (uVar3 & 0xff) + 0x2b;
              uVar6 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
              iVar5 = (int)*(undefined4 *)((uint)partyIndex << 2);
              iVar4 = *(int *)(iVar5 + 0x58);
              if (-1 < iVar4) {
                if (iVar4 != 0) {
                  return uVar2;
                }
                if (*(uint *)(uVar2 * 0x27 + 0x125) <= *(uint *)(iVar5 + 0x56)) {
                  return uVar2;
                }
              }
            }
            uVar3 = ovr_randBelow(0xc);
            if ((uVar3 & 0xff) == 0) {
              uVar3 = ovr_randBelow(3);
              uVar2 = (uVar3 & 0xff) + 0xec;
              uVar6 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
              iVar5 = (int)*(undefined4 *)((uint)partyIndex << 2);
              iVar4 = *(int *)(iVar5 + 0x58);
              if (-1 < iVar4) {
                if (iVar4 != 0) {
                  return uVar2;
                }
                if (*(uint *)(uVar2 * 0x27 + 0x125) <= *(uint *)(iVar5 + 0x56)) {
                  return uVar2;
                }
              }
            }
            bVar1 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3e);
            uVar3 = ovr_randBelow(3);
            uVar2 = (uVar3 & 0xff) +
                    (uint)*(byte *)((int)&worldMenuLabels[0xb].ofs + 1 + (uint)bVar1 * 0x95);
            uVar6 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
            iVar5 = (int)*(undefined4 *)((uint)partyIndex << 2);
            iVar4 = *(int *)(iVar5 + 0x58);
            if ((iVar4 < 0) ||
               ((iVar4 == 0 && (*(uint *)(iVar5 + 0x56) < *(uint *)(uVar2 * 0x27 + 0x125))))) {
              uVar2 = (uint)*(byte *)((int)&worldMenuLabels[0xb].ofs + 1 + (uint)bVar1 * 0x95);
            }
          }
        }
      }
      else {
        uVar3 = ovr_randBelow(0x14);
        if ((uVar3 & 0xff) == 0) {
          uVar2 = 0x72;
        }
        else {
          uVar3 = ovr_randBelow(4);
          if ((uVar3 & 0xff) == 0) {
            uVar2 = 0x71;
          }
          else {
            uVar2 = 0x70;
          }
        }
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 5087:4975 */

/* [R4] calls ovr_randBelow */

void __cdecl16far ovc22_usesRandBelow2(byte partyIndex,uint16_t outFlag,uint16_t outFlagSeg)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint16_t uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  uint *unaff_SS;
  byte bStack_e;
  uint16_t y;
  uint16_t x;
  byte bStack_8;
  undefined1 uStack_7;
  char cStack_6;
  char cStack_5;
  undefined1 uStack_4;
  byte bStack_3;
  
  bStack_8 = ListCount;
  if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa8) != '\0') {
    uVar5 = ovr_randBelow(100);
    uStack_7 = (undefined1)uVar5;
    if ((uVar5 & 0xff) <
        ((uint)*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa8) * 100) /
        (*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa8) + 1)) {
      uVar5 = ovr_randBelow((uint)*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa8));
      cStack_5 = (char)uVar5;
      cStack_6 = '\0';
      for (bStack_8 = 0; bStack_8 < ListCount; bStack_8 = bStack_8 + 1) {
        uVar9 = (undefined2)((ulong)GUnits >> 0x10);
        if ((*(char *)((uint)((unit_t *)GUnits + *(int *)((uint)bStack_8 * 2 + -0x6d44))->bldType *
                       0x27 + 0x133) == '\x12') &&
           (((unit_t *)GUnits)[*(int *)((uint)bStack_8 * 2 + -0x6d44)].unitType == partyIndex)) {
          if (cStack_6 == cStack_5) break;
          cStack_6 = cStack_6 + '\x01';
        }
      }
    }
  }
  if (bStack_8 < ListCount) {
    uVar9 = (undefined2)((ulong)GUnits >> 0x10);
    x = ((unit_t *)GUnits)[*(int *)((uint)bStack_8 * 2 + -0x6d44)].x;
    y = ((unit_t *)GUnits)[*(int *)((uint)bStack_8 * 2 + -0x6d44)].y;
  }
  else {
    x = *(uint16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x39);
    y = *(uint16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3b);
  }
  uVar9 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
  iVar7 = (int)*(undefined4 *)((uint)partyIndex << 2);
  iVar8 = *(int *)(iVar7 + 0x58);
  if ((iVar8 < 1) && ((iVar8 < 0 || (*(uint *)(iVar7 + 0x56) < 10)))) {
    uStack_4 = 1;
  }
  else {
    uStack_4 = 0;
  }
  if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                (uint)*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3e) * 0x95) & 0x80)
      == 0) {
    bStack_3 = 0;
  }
  else {
    bStack_3 = 3;
  }
  if ((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 2) != 0) {
    bStack_3 = bStack_3 | 1;
  }
  if ((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 4) != 0) {
    bStack_3 = bStack_3 | 2;
  }
  uVar6 = ovc22_searchCellsAround(&x,unaff_SS,(byte)&y,(byte)unaff_SS,partyIndex);
  if ((uVar6 & 0xff) != 0) {
    if ((uVar6 & 0xff) != 1) {
      return;
    }
    uVar6 = ovc22_usesRandBelow(partyIndex,x,y);
    if (uVar6 == 0) {
      x = *(uint16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x39);
      y = *(uint16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3b);
    }
    else {
      if ((*(uint *)(uVar6 * 0x27 + 0x121) & 0x60) == 0) {
        uVar9 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
        iVar7 = (int)*(undefined4 *)((uint)partyIndex << 2);
        iVar8 = *(int *)(iVar7 + 0x58);
        if ((iVar8 < 0) ||
           ((iVar8 == 0 && (*(uint *)(iVar7 + 0x56) < *(uint *)(uVar6 * 0x27 + 0x125))))) {
          uVar9 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
          iVar8 = (int)*(undefined4 *)((uint)partyIndex << 2);
          *(undefined2 *)(iVar8 + 0x58) = 0;
          *(undefined2 *)(iVar8 + 0x56) = 0;
        }
        else {
          uVar4 = *(uint *)(uVar6 * 0x27 + 0x125);
          uVar9 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
          iVar8 = (int)*(undefined4 *)((uint)partyIndex << 2);
          puVar1 = (uint *)(iVar8 + 0x56);
          uVar3 = *puVar1;
          *puVar1 = *puVar1 - uVar4;
          piVar2 = (int *)(iVar8 + 0x58);
          *piVar2 = *piVar2 - (uint)(uVar3 < uVar4);
        }
      }
      bStack_e = (byte)uVar6;
      ovr_createConstructionRecordFar(bStack_e,x,y,(uint8_t *)outFlag,(byte)outFlagSeg,partyIndex);
    }
  }
  if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3f) == '\0') {
    if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5b) <
        *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d)) {
      ovr_ovc18_textTypeLen(partyIndex,x,y,0x1);
    }
    else {
      ovr_ovc18_textTypeLen(partyIndex,x,y,0x0);
    }
  }
  else {
    ovr_ovc18_textTypeLen(partyIndex,0,0,0x0);
  }
  return;
}



/* 5087:4dd9 */

/* Runs the per-leader random spawn chance and spawns through ovc22_usesRandBelow2. */

void __cdecl16far ovc22_spawnForLeaders(void)

{
  uint16_t uVar1;
  uint16_t unaff_SS;
  uint8_t outFlag;
  int iStack_4;
  
  outFlag = 0x0;
  for (iStack_4 = 0; iStack_4 < (int)(uint)GLeaderCount; iStack_4 = iStack_4 + 1) {
    if (((*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3d) != '\0') &&
        (uVar1 = ovr_randBelow((uint)(byte)((char *)"Decrease message delay" + 5)
                                           [(uint)*(byte *)((int)*(undefined4 *)(iStack_4 << 2) +
                                                           0x3e) * 0x95]),
        (byte)uVar1 < *(byte *)((int)*(undefined4 *)(iStack_4 << 2) + 0x2e))) &&
       ((*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3f) != '\0' ||
        (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x4d) <=
         *(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x5b))))) {
      if (EntityCount < 0x21c) {
        ovc22_usesRandBelow2((byte)iStack_4,(uint16_t)&outFlag,unaff_SS);
      }
      else if (*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3f) == '\0') {
        if (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x45) < 0x23) {
          ovc22_usesRandBelow2((byte)iStack_4,(uint16_t)&outFlag,unaff_SS);
        }
        else if (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x45) < 0x4b) {
          uVar1 = ovr_randBelow(8);
          if ((uVar1 & 0xff) == 0) {
            ovc22_usesRandBelow2((byte)iStack_4,(uint16_t)&outFlag,unaff_SS);
          }
        }
        else {
          uVar1 = ovr_randBelow(0x10);
          if ((uVar1 & 0xff) == 0) {
            ovc22_usesRandBelow2((byte)iStack_4,(uint16_t)&outFlag,unaff_SS);
          }
        }
      }
      else if (*(int *)((int)*(undefined4 *)(iStack_4 << 2) + 0x47) == 0) {
        ovc22_usesRandBelow2((byte)iStack_4,(uint16_t)&outFlag,unaff_SS);
      }
      else if (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x45) < 0x19) {
        ovc22_usesRandBelow2((byte)iStack_4,(uint16_t)&outFlag,unaff_SS);
      }
      else if (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x45) < 0x32) {
        uVar1 = ovr_randBelow(8);
        if ((uVar1 & 0xff) == 0) {
          ovc22_usesRandBelow2((byte)iStack_4,(uint16_t)&outFlag,unaff_SS);
        }
      }
      else {
        uVar1 = ovr_randBelow(0x10);
        if ((uVar1 & 0xff) == 0) {
          ovc22_usesRandBelow2((byte)iStack_4,(uint16_t)&outFlag,unaff_SS);
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

undefined2 __cdecl16far ovc22_usesGOngoingBattle(byte x,byte y)

{
  undefined2 uVar1;
  
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


