/*
 * ovc23.c - recovered from STRONG.EXE
 * memory block: OVC23
 * range: 55fe:0000 - 55fe:345d
 * functions: 26
 */
#include "recovered.h"


/* 55fe:0000 */
/* DECOMPILATION FAILED: 
Low-level Error: Cannot marshal address space: NO ADDRESS */
void OVC23_55fe_0000(void) { /* failed */ }

/* 55fe:0487 */

undefined1 __cdecl16far OVC23_55fe_0487(undefined2 param_1,int param_2,char param_3)

{
  char *pcVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 uStack_3;
  
  iVar4 = ovr_OVC23_55fe_3450(param_1);
  uStack_3 = 0;
  for (uVar5 = 0; uVar5 < DAT_2000_d2df; uVar5 = uVar5 + 1) {
    if (((*(int *)(uVar5 * 0x12 + 4) == param_2) && (*(uint *)(uVar5 * 0x12 + 2) <= iVar4 + 1U)) &&
       (iVar4 - 2U <= (*(int *)(uVar5 * 0x12 + 2) + (uint)*(byte *)(uVar5 * 0x12 + 7)) - 1)) {
      bVar2 = *(byte *)(uVar5 * 0x12 + 9);
      if ((bVar2 != 0xff) &&
         (uVar3 = *(undefined4 *)((uint)bVar2 << 2), *(char *)((int)uVar3 + 0x3f) == param_3)) {
        *(undefined2 *)(uVar5 * 0x12 + 0xf) = DAT_2000_d167;
        if (*(char *)(uVar5 * 0x12 + 0xb) != '\0') {
          pcVar1 = (char *)(uVar5 * 0x12 + 0xb);
          *pcVar1 = *pcVar1 + -1;
        }
        if (*(char *)(uVar5 * 0x12 + 0xb) == '\0') {
          *(undefined1 *)(uVar5 * 0x12 + 0xe) = 1;
        }
        uStack_3 = 1;
      }
    }
  }
  return uStack_3;
}



/* 55fe:05db */

undefined2 __cdecl16far OVC23_55fe_05db(undefined2 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar1 = ovr_OVC23_55fe_3450(param_1);
  iVar2 = ovr_OVC23_55fe_3450(GfxRndSeed);
  if ((iVar1 == iVar2) && (GfxRndSeed2 == param_2)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* 55fe:0617 */

int __cdecl16far OVC23_55fe_0617(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iStack_14;
  int iStack_12;
  undefined1 local_c [2];
  undefined1 local_a [2];
  undefined1 local_8 [2];
  undefined1 local_6 [2];
  int iStack_4;
  
  iVar1 = ovr_constr_36ce_0101(param_1,0xffff,local_6);
  iVar2 = ovr_constr_36ce_0101(param_1,0,local_a);
  if (*(byte *)(param_2 * 0x27 + 0x11b) < 2) {
    iStack_12 = ovr_constr_36ce_0101(param_1 + 1,0xffff,local_8);
    iStack_14 = ovr_constr_36ce_0101(param_1 + 1,0,local_c);
  }
  else if (*(byte *)(param_2 * 0x27 + 0x11b) < 3) {
    iStack_12 = ovr_constr_36ce_0101(param_1 + 2,0xffff,local_8);
    iStack_14 = ovr_constr_36ce_0101(param_1 + 2,0,local_c);
  }
  else {
    iStack_12 = ovr_constr_36ce_0101(param_1 + 4,0xffff,local_8);
    iStack_14 = ovr_constr_36ce_0101(param_1 + 4,0,local_c);
  }
  uVar3 = (uint)DAT_2410_073c;
  iStack_4 = iVar2 + iVar1 + iStack_12 + iStack_14 >> 2;
  if ((int)(iVar1 - uVar3) < (int)(iStack_12 - uVar3)) {
    iVar2 = iVar1 - uVar3;
  }
  else {
    iVar2 = iStack_12 - uVar3;
  }
  if (iStack_4 < iVar2) {
    if ((int)(iVar1 - uVar3) < (int)(iStack_12 - uVar3)) {
      iStack_4 = iVar1 - uVar3;
    }
    else {
      iStack_4 = iStack_12 - uVar3;
    }
  }
  return iStack_4;
}



/* 55fe:0768 */

int __cdecl16far OVC23_55fe_0768(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iStack_12;
  undefined1 local_10 [2];
  undefined1 local_e [2];
  undefined1 local_c [2];
  undefined1 local_a [2];
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  if (param_2 == 4) {
    iVar1 = ovr_constr_36ce_0101(param_1 + 1,0xffff,local_a);
    iStack_4 = ovr_constr_36ce_0101(param_1 + 1,0,local_e);
    iStack_6 = ovr_constr_36ce_0101(param_1 + 2,0xffff,local_c);
    iStack_8 = ovr_constr_36ce_0101(param_1 + 2,0,local_10);
  }
  else {
    iVar1 = ovr_constr_36ce_0101(param_1,0xffff,local_a);
    iStack_4 = ovr_constr_36ce_0101(param_1,0,local_e);
    iStack_6 = ovr_constr_36ce_0101(param_1 + param_2,0xffff,local_c);
    iStack_8 = ovr_constr_36ce_0101(param_1 + param_2,0,local_10);
  }
  iStack_12 = iStack_4 + iVar1 + iStack_6 + iStack_8 >> 2;
  iVar2 = iStack_6;
  if (iVar1 < iStack_6) {
    iVar2 = iVar1;
  }
  if ((iStack_12 < iVar2) && (iStack_12 = iStack_6, iVar1 < iStack_6)) {
    iStack_12 = iVar1;
  }
  return iStack_12;
}



/* 55fe:0863 */

void __cdecl16far OVC23_55fe_0863(uint16_t param_1,uint16_t param_2)

{
  uint16_t play_id;
  undefined2 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  far_t dst;
  
  bVar2 = false;
  GAnimPlaying = 0;
  for (uVar5 = DAT_2000_cfea; uVar5 < DAT_2000_cfd8; uVar5 = uVar5 + 1) {
    play_id = *(uint16_t *)(uVar5 * 2 + 0x360);
    if ((-3 < (int)play_id) && ((int)play_id < 2)) {
      iVar3 = ovr_constr_36ce_0159();
      if (((char *)"build\\thfres01.lbm" + 0x10)[iVar3 * 3 + *(int *)(uVar5 * 2)] != '\0') {
        iVar4 = OVC23_55fe_0617(play_id);
        dst.seg = param_2;
        dst.ofs = param_1;
        ovr_animAdvance(play_id,((char *)"build\\thfres01.lbm" + 0x10)
                                [iVar3 * 3 + *(int *)(uVar5 * 2)],*(uint16_t *)(uVar5 * 2 + 0xa20),
                        (uint)DAT_2410_0728 - iVar4,dst);
        bVar2 = true;
      }
      uVar1 = uRam0002d2d7;
      if (*(int *)(play_id * 2 + -0x6e25) != -1) {
        if (*(char *)(play_id + 0x90ec) == '\0') {
          uVar1 = *(undefined2 *)(play_id * 2 + -0x6e25);
          iVar3 = OVC23_55fe_0768(play_id);
          OVC23_55fe_23d8(*(undefined2 *)(uVar5 * 2 + 0xa20),(uint)DAT_2410_0728 - iVar3,uVar1);
          bVar2 = true;
        }
        else if (play_id == 0xfffe) {
          iVar3 = OVC23_55fe_0768(0xfffe);
          OVC23_55fe_23d8(*(int *)(uVar5 * 2 + 0xa20) + -0x30,(uint)DAT_2410_0728 - iVar3,uVar1);
          bVar2 = true;
        }
      }
    }
  }
  if (bVar2) {
    ovr_constr_36ce_04e9(param_1,param_2);
  }
  return;
}



/* 55fe:0a56 */

int __cdecl16far OVC23_55fe_0a56(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = (uint)*(byte *)((int)DAT_2000_ca95 +
                         *(int *)(param_1 * 0x78 + (int)DAT_2000_cb0d + param_2 * 2 + -0x78) * 9) *
          0x27;
  bVar2 = (byte)((uint)iVar1 >> 8);
  if (*(byte *)(iVar1 + 0x11b) < 2) {
    iVar1 = (uint)bVar2 << 8;
  }
  else {
    iVar1 = CONCAT11(bVar2,1);
  }
  return iVar1;
}



/* 55fe:0aba */

void __cdecl16far OVC23_55fe_0aba(int param_1,int param_2)

{
  if (((GfxRndSeed2 == param_2) && (GfxRndSeed + -2 <= param_1)) && (param_1 <= GfxRndSeed + 1)) {
    AgntClearFlag = true;
  }
  return;
}



/* 55fe:0af5 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00053af7) overlaps instruction at (ram,0x00053af6)
    */

uint * __cdecl16far OVC23_55fe_0af5(int param_1,uint *param_2,byte param_3)

{
  char *pcVar1;
  int *piVar2;
  uint *puVar3;
  byte *pbVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  char cVar11;
  char cVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  int in_CX;
  undefined2 uVar16;
  int iVar17;
  int *piVar18;
  int *piVar19;
  uint16_t uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined2 unaff_SI;
  char *unaff_DI;
  undefined2 uVar24;
  undefined2 uVar25;
  uint16_t uVar26;
  char *pcVar27;
  undefined2 unaff_SS;
  bool bVar28;
  uint uStackY_2e;
  int iStackY_2c;
  int iStackY_2a;
  byte bStackY_20;
  byte bStackY_1f;
  undefined2 uStackY_1e;
  undefined2 uStackY_1c;
  char *pcStackY_1a;
  char *pcStackY_18;
  uint uVar29;
  char *pcVar30;
  uint *puVar31;
  uint in_stack_0000ffea;
  uint uStack_14;
  byte bVar32;
  char *fmt;
  uint in_stack_0000fffc;
  
  fmt = (char *)CONCAT22(unaff_SI,unaff_DI);
  pcVar30 = (char *)"puppetmaker" + 3;
  bVar32 = (byte)((uint)(param_1 + *(char *)(param_3 + 0x885)) >> 8);
  cVar12 = ovr_attact_3f0b_01ec();
  if (cVar12 == '\0') {
    return (uint *)((int)(undefined4 *)&_DATA + 1);
  }
  uVar29 = (uint)param_3;
  if (3 < uVar29) {
    return (uint *)0x0;
  }
  iVar23 = uVar29 * 2;
  pcVar27 = (char *)"Reroll ability scores, or select the character\'s class." + 0x2b;
  switch(uVar29) {
  case 0:
    return param_2;
  case 1:
    while( true ) {
      if ((*(byte *)(iVar23 + uVar29 + 3) & 3) == 0) {
        uVar16 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
        bVar32 = *(byte *)((int)DAT_2000_ca95 + (int)param_2 * 9 + 2);
        if ((bVar32 == 0xff) ||
           (uVar8 = *(undefined4 *)((uint)bVar32 << 2), *(char *)((int)uVar8 + 0x3f) == '\0')) {
          pcVar30 = (char *)"%d \r" + 1;
        }
        else {
          pcVar30 = (char *)"NEW MAXSQUARE %d \r" + 10;
        }
        fmt = (char *)CONCAT22((int)((ulong)fmt >> 0x10),pcVar30);
        if (*(char *)((int)DAT_2000_ca95 + (int)param_2 * 9 + 1) != '\0') {
          pcVar27 = (char *)"glassworks" + 9;
          uVar20 = ovr_randBelow((uint16_t)pcVar30);
          uVar16 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
          iVar23 = (int)DAT_2000_ca95;
          if ((int)(uVar20 & 0xff) <
              (int)(100 - (uint)*(byte *)((uint)*(byte *)(iVar23 + (int)param_2 * 9) * 0x27 + 0x130)
                   )) {
            bStackY_20 = *(byte *)(iVar23 + (int)param_2 * 9);
            pcVar1 = (char *)(iVar23 + (int)param_2 * 9 + 1);
            *pcVar1 = *pcVar1 + -1;
            if (((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 4) == 0) &&
               ((*(char *)((int)DAT_2000_ca95 + (int)param_2 * 9 + 1) == '\0' ||
                ((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 0x200) != 0)))) {
              OVC22_5087_1674();
            }
            else if (((*(int *)((char *)"build\\clebath2.lbm" + 0xc + (uint)bStackY_20 * 0xc) != 0
                       || *(int *)((char *)"build\\clebath2.lbm" + 0xe + (uint)bStackY_20 * 0xc) !=
                          0) || (*(char *)((uint)bStackY_20 * 0x27 + 0x11e) == '\x10')) &&
                    (cVar12 = OVC22_5087_510e(), cVar12 != '\0')) {
              uStackY_1c = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1c) + 1)),1);
            }
          }
        }
      }
      param_2 = (uint *)((int)param_2 + 1);
      if (DAT_2000_ca99 <= param_2) break;
      uVar29 = (int)param_2 * 9;
      pcVar30 = (char *)((ulong)DAT_2000_ca95 >> 0x10);
      iVar23 = (int)DAT_2000_ca95;
    }
    GGameState = 0x43;
    if (DebugVerbose != false) {
      pcVar27 = (char *)0x1000;
      printf("%d \r",0x43);
    }
    for (uVar29 = 0; (int)uVar29 < (int)(uint)DAT_2000_d1e6; uVar29 = uVar29 + 1) {
      if (*(char *)((int)*(undefined4 *)(uVar29 << 2) + 0x3d) != '\0') {
        *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 0xa2) = 0;
        cVar12 = *(char *)((int)*(undefined4 *)(uVar29 << 2) + 0x3f);
        if ((cVar12 == '\0') &&
           (*(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0x4f) <
            *(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0x4d) >> 1)) {
          bVar9 = true;
        }
        else {
          bVar9 = false;
        }
        uVar14 = *(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0x54);
        uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
        iVar23 = (int)*(undefined4 *)(uVar29 << 2);
        iVar23 = *(int *)(iVar23 + 0x58) + ((int)uVar14 >> 0xf) +
                 (uint)CARRY2(*(uint *)(iVar23 + 0x56),uVar14);
        if ((iVar23 < 1) && (iVar23 < 0)) {
          puVar15 = (uint *)&GUnitDescriptions[3].ofs;
          while (puVar15 = (uint *)((int)puVar15 + 1), puVar15 < DAT_2000_ca99) {
            uVar16 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
            iVar23 = (int)DAT_2000_ca95;
            bStackY_20 = *(byte *)(iVar23 + (int)puVar15 * 9);
            if ((*(byte *)(iVar23 + (int)puVar15 * 9 + 2) == uVar29) &&
               (*(int *)((uint)bStackY_20 * 0x27 + 0x123) < 0)) {
              uVar14 = *(uint *)((uint)bStackY_20 * 0x27 + 0x123);
              uVar24 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
              iVar21 = (int)*(undefined4 *)(uVar29 << 2);
              iVar21 = *(int *)(iVar21 + 0x58) + ((int)uVar14 >> 0xf) +
                       (uint)CARRY2(*(uint *)(iVar21 + 0x56),uVar14);
              if ((iVar21 < 1) && (iVar21 < 0)) {
                if ((cVar12 == '\0') && (*(char *)(iVar23 + (int)puVar15 * 9 + 1) != '\0')) {
                  uVar20 = ovr_randBelow(100);
                  uVar16 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
                  iVar23 = (int)DAT_2000_ca95;
                  if (*(byte *)((uint)*(byte *)(iVar23 + (int)puVar15 * 9) * 0x27 + 0x130) <=
                      (byte)uVar20) {
                    if (*(char *)(iVar23 + (int)puVar15 * 9 + 1) != '\0') {
                      pcVar1 = (char *)(iVar23 + (int)puVar15 * 9 + 1);
                      *pcVar1 = *pcVar1 + -1;
                    }
                    if (((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 4) == 0) &&
                       ((*(char *)((int)DAT_2000_ca95 + (int)puVar15 * 9 + 1) == '\0' ||
                        ((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 0x200) != 0)))) {
                      OVC22_5087_1674();
                    }
                    else if (((*(int *)((char *)"build\\clebath2.lbm" + 0xc + (uint)bStackY_20 * 0xc
                                       ) != 0 ||
                               *(int *)((char *)"build\\clebath2.lbm" + 0xe + (uint)bStackY_20 * 0xc
                                       ) != 0) ||
                             (*(char *)((uint)bStackY_20 * 0x27 + 0x11e) == '\x10')) &&
                            (cVar11 = OVC22_5087_510e(), cVar11 != '\0')) {
                      uStackY_1c = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1c) + 1)),1);
                    }
                  }
                }
              }
              else {
                uVar13 = *(uint *)((uint)bStackY_20 * 0x27 + 0x123);
                uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
                iVar23 = (int)*(undefined4 *)(uVar29 << 2);
                puVar3 = (uint *)(iVar23 + 0x56);
                uVar14 = *puVar3;
                *puVar3 = *puVar3 + uVar13;
                piVar2 = (int *)(iVar23 + 0x58);
                *piVar2 = *piVar2 + ((int)uVar13 >> 0xf) + (uint)CARRY2(uVar14,uVar13);
              }
            }
          }
          uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
          iVar23 = (int)*(undefined4 *)(uVar29 << 2);
          *(undefined2 *)(iVar23 + 0x58) = 0;
          *(undefined2 *)(iVar23 + 0x56) = 0;
        }
        else {
          if ((cVar12 == '\0') && (0 < *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x54))) {
            uVar14 = *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x54) / 10;
          }
          else {
            uVar14 = 0;
          }
          bVar28 = CARRY2(DAT_2000_ca91,uVar14);
          DAT_2000_ca91 = DAT_2000_ca91 + uVar14;
          DAT_2000_ca93 = DAT_2000_ca93 + ((int)uVar14 >> 0xf) + (uint)bVar28;
          uVar14 = *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x54) - uVar14;
          uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
          iVar23 = (int)*(undefined4 *)(uVar29 << 2);
          puVar3 = (uint *)(iVar23 + 0x56);
          uVar13 = *puVar3;
          *puVar3 = *puVar3 + uVar14;
          piVar2 = (int *)(iVar23 + 0x58);
          *piVar2 = *piVar2 + ((int)uVar14 >> 0xf) + (uint)CARRY2(uVar13,uVar14);
        }
        if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uVar29 << 2) + 0x3e) * 0x95) & 0x100) ==
            0) {
          if (*(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0x4f) <
              *(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0x4d)) {
            uVar14 = *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x4d) -
                     *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x4f);
            uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
            iVar21 = (int)*(undefined4 *)(uVar29 << 2);
            iVar23 = *(int *)(iVar21 + 0x62);
            if ((-1 < iVar23) && ((0 < iVar23 || (*(int *)(iVar21 + 0x60) != 0)))) {
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
              iVar23 = (int)*(undefined4 *)(uVar29 << 2);
              uVar13 = *(uint *)(iVar23 + 0x62);
              if ((0x7fff < uVar13) ||
                 ((uStack_14 = uVar14, (int)uVar13 < 1 && (*(uint *)(iVar23 + 0x60) <= uVar14)))) {
                uStack_14 = *(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0x60);
              }
              uVar14 = uVar14 - uStack_14;
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
              iVar23 = (int)*(undefined4 *)(uVar29 << 2);
              puVar3 = (uint *)(iVar23 + 0x60);
              uVar13 = *puVar3;
              *puVar3 = *puVar3 - uStack_14;
              piVar2 = (int *)(iVar23 + 0x62);
              *piVar2 = *piVar2 - (uint)(uVar13 < uStack_14);
            }
            if (uVar14 == 0) {
              uVar14 = 0;
            }
            else {
              uVar13 = uVar14;
              if (*(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0xa0) < uVar14) {
                uVar13 = *(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0xa0);
              }
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
              iVar23 = (int)*(undefined4 *)(uVar29 << 2);
              uVar7 = *(uint *)(iVar23 + 0x58);
              if (((int)uVar7 < 1) && ((0x7fff < uVar7 || (*(uint *)(iVar23 + 0x56) < uVar13)))) {
                uVar13 = *(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0x56);
              }
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
              iVar23 = (int)*(undefined4 *)(uVar29 << 2);
              puVar3 = (uint *)(iVar23 + 0x56);
              uVar7 = *puVar3;
              *puVar3 = *puVar3 - uVar13;
              piVar2 = (int *)(iVar23 + 0x58);
              *piVar2 = *piVar2 - (uint)(uVar7 < uVar13);
              uVar14 = uVar14 - uVar13;
              *(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0xa2) = uVar13;
            }
            if (cVar12 == '\0') {
              for (iVar23 = 0; (uVar14 != 0 && (iVar23 < (int)(uint)DAT_2000_d1e6));
                  iVar23 = iVar23 + 1) {
                if ((*(char *)((int)*(undefined4 *)(iVar23 << 2) + 0x3d) != '\0') &&
                   ((*(char *)((int)*(undefined4 *)(iVar23 << 2) + 0x3f) == '\0' &&
                    (uVar16 = (undefined2)((ulong)*(undefined4 *)(iVar23 << 2) >> 0x10),
                    iVar21 = (int)*(undefined4 *)(iVar23 << 2),
                    *(int *)(iVar21 + 0x60) != 0 || *(int *)(iVar21 + 0x62) != 0)))) {
                  uVar16 = (undefined2)((ulong)*(undefined4 *)(iVar23 << 2) >> 0x10);
                  iVar21 = (int)*(undefined4 *)(iVar23 << 2);
                  uVar13 = *(uint *)(iVar21 + 0x62);
                  if ((0x7fff < uVar13) ||
                     ((uStack_14 = uVar14, (int)uVar13 < 1 && (*(uint *)(iVar21 + 0x60) <= uVar14)))
                     ) {
                    uStack_14 = *(uint *)((int)*(undefined4 *)(iVar23 << 2) + 0x60);
                  }
                  uVar14 = uVar14 - uStack_14;
                  uVar16 = (undefined2)((ulong)*(undefined4 *)(iVar23 << 2) >> 0x10);
                  iVar21 = (int)*(undefined4 *)(iVar23 << 2);
                  puVar3 = (uint *)(iVar21 + 0x60);
                  uVar13 = *puVar3;
                  *puVar3 = *puVar3 - uStack_14;
                  piVar2 = (int *)(iVar21 + 0x62);
                  *piVar2 = *piVar2 - (uint)(uVar13 < uStack_14);
                }
              }
            }
            pcVar30 = (char *)0x0;
            while ((pcVar30 < EntityCount && (uVar14 != 0))) {
              uVar26 = Entities.seg;
              uVar20 = Entities.ofs;
              if (((*(char *)(uVar20 + (int)pcVar30 * 0x37 + 0x18) == '\0') &&
                  (*(byte *)(uVar20 + (int)pcVar30 * 0x37 + 0x1a) == uVar29)) &&
                 ((bVar9 || (1 < *(byte *)(uVar20 + (int)pcVar30 * 0x37 + 0xe))))) {
                if (*(char *)(uVar20 + (int)pcVar30 * 0x37 + 0xe) != '\0') {
                  if (DebugVerbose != false) {
                    printf("kill 3\r",(char *)fmt);
                  }
                  pcVar1 = (char *)(Entities.ofs + (int)pcVar30 * 0x37 + 0xe);
                  *pcVar1 = *pcVar1 + -1;
                  if (*(char *)(Entities.ofs + (int)pcVar30 * 0x37 + 0xe) == '\0') {
                    uStackY_1e = (char *)CONCAT11(1,(byte)uStackY_1e);
                  }
                }
                uVar14 = uVar14 - 1;
              }
              pcVar30 = pcVar30 + 1;
            }
          }
          else {
            uVar13 = *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x4f) -
                     *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x4d);
            uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
            iVar23 = (int)*(undefined4 *)(uVar29 << 2);
            puVar3 = (uint *)(iVar23 + 0x60);
            uVar14 = *puVar3;
            *puVar3 = *puVar3 + uVar13;
            piVar2 = (int *)(iVar23 + 0x62);
            *piVar2 = *piVar2 + (uint)CARRY2(uVar14,uVar13);
          }
        }
        uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
        iVar22 = (int)*(undefined4 *)(uVar29 << 2);
        iVar23 = *(int *)(iVar22 + 0x62);
        uVar24 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
        iVar17 = (int)*(undefined4 *)(uVar29 << 2);
        iVar21 = *(int *)(iVar17 + 0x80);
        if ((iVar21 <= iVar23) &&
           ((iVar21 < iVar23 || (*(uint *)(iVar17 + 0x7e) < *(uint *)(iVar22 + 0x60))))) {
          uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
          iVar23 = (int)*(undefined4 *)(uVar29 << 2);
          uVar14 = *(uint *)(iVar23 + 0x60);
          uVar24 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
          iVar21 = (int)*(undefined4 *)(uVar29 << 2);
          puVar3 = (uint *)(iVar21 + 0x7e);
          uVar13 = (uint)(uVar14 < *puVar3);
          uVar7 = *(int *)(iVar23 + 0x62) - *(int *)(iVar21 + 0x80);
          if (((int)(uVar7 - uVar13) < 0) ||
             ((uVar7 == uVar13 &&
              (uVar14 - *puVar3 <= *(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0xa0))))) {
            uVar14 = *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x60) -
                     *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x7e);
          }
          else {
            uVar14 = *(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0xa0);
          }
          *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0xa2) = -uVar14;
          uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
          iVar23 = (int)*(undefined4 *)(uVar29 << 2);
          puVar3 = (uint *)(iVar23 + 0x56);
          uVar13 = *puVar3;
          *puVar3 = *puVar3 + uVar14;
          piVar2 = (int *)(iVar23 + 0x58);
          *piVar2 = *piVar2 + (uint)CARRY2(uVar13,uVar14);
          uVar24 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
          iVar23 = (int)*(undefined4 *)(uVar29 << 2);
          uVar16 = *(undefined2 *)(iVar23 + 0x7e);
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
          iVar21 = (int)*(undefined4 *)(uVar29 << 2);
          *(undefined2 *)(iVar21 + 0x62) = *(undefined2 *)(iVar23 + 0x80);
          *(undefined2 *)(iVar21 + 0x60) = uVar16;
        }
        if ((*(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0x5b) <
             *(uint *)((int)*(undefined4 *)(uVar29 << 2) + 0x4d)) &&
           ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uVar29 << 2) + 0x3e) * 0x95) & 0x80) == 0
           )) {
          iVar23 = *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x4d) -
                   *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x5b);
          pcVar30 = (char *)0x0;
          while ((pcVar30 < EntityCount && (iVar23 != 0))) {
            uVar26 = Entities.seg;
            uVar20 = Entities.ofs;
            if ((*(byte *)(uVar20 + (int)pcVar30 * 0x37 + 0x1a) == uVar29) &&
               ((((*(char *)(uVar20 + (int)pcVar30 * 0x37 + 0x18) == '\0' &&
                  (*(int *)(uVar20 + (int)pcVar30 * 0x37 + 8) == 0)) &&
                 (*(int *)(uVar20 + (int)pcVar30 * 0x37 + 10) == 0)) &&
                (3 < *(byte *)(uVar20 + (int)pcVar30 * 0x37 + 0xe))))) {
              if (DebugVerbose != false) {
                printf("kill 2 \r",(char *)fmt);
              }
              pcVar1 = (char *)(Entities.ofs + (int)pcVar30 * 0x37 + 0xe);
              *pcVar1 = *pcVar1 + -1;
              iVar23 = iVar23 + -1;
            }
            pcVar30 = pcVar30 + 1;
          }
        }
        ovr_OVC25_5b66_1b48();
        _fmemset((void *)CONCAT22(((int *)(uVar29 * 4))[1],(void *)(*(int *)(uVar29 * 4) + 0x6a)),0,
                 6);
        _fmemset((void *)CONCAT22(((int *)(uVar29 * 4))[1],(void *)(*(int *)(uVar29 * 4) + 0x76)),0,
                 6);
        uVar20 = ovr_randBelow(100);
        if ((byte)uVar20 < *(byte *)((int)*(undefined4 *)(uVar29 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 0x6c) =
               *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 100);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 0x6a) =
               *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 100);
        }
        uVar20 = ovr_randBelow(100);
        if ((byte)uVar20 < *(byte *)((int)*(undefined4 *)(uVar29 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 0x6e) =
               *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 0x66);
        }
        else {
          piVar2 = (int *)((int)*(undefined4 *)(uVar29 << 2) + 0x6c);
          *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x66);
        }
        piVar2 = (int *)((int)*(undefined4 *)(uVar29 << 2) + 0x6e);
        *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x68);
        uVar20 = ovr_randBelow(100);
        if ((byte)uVar20 < *(byte *)((int)*(undefined4 *)(uVar29 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 0x78) =
               *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 0x70);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 0x76) =
               *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 0x70);
        }
        uVar20 = ovr_randBelow(100);
        if ((byte)uVar20 < *(byte *)((int)*(undefined4 *)(uVar29 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 0x7a) =
               *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 0x72);
        }
        else {
          piVar2 = (int *)((int)*(undefined4 *)(uVar29 << 2) + 0x78);
          *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x72);
        }
        pcVar27 = (char *)"glassworks" + 9;
        uVar20 = ovr_randBelow(100);
        if ((byte)uVar20 < *(byte *)((int)*(undefined4 *)(uVar29 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 0x7c) =
               *(undefined2 *)((int)*(undefined4 *)(uVar29 << 2) + 0x74);
        }
        else {
          piVar2 = (int *)((int)*(undefined4 *)(uVar29 << 2) + 0x7a);
          *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x74);
        }
        *(undefined1 *)((int)*(undefined4 *)(uVar29 << 2) + 0xa7) =
             *(undefined1 *)((int)*(undefined4 *)(uVar29 << 2) + 0xa6);
        if (*(char *)((int)*(undefined4 *)(uVar29 << 2) + 0x3f) != '\0') {
          uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
          iVar21 = (int)*(undefined4 *)(uVar29 << 2);
          iVar23 = *(int *)(iVar21 + 0x58);
          if ((iVar23 < 1) && ((iVar23 != 0 || (*(int *)(iVar21 + 0x56) == 0)))) {
            uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
            iVar23 = (int)*(undefined4 *)(uVar29 << 2);
            *(undefined2 *)(iVar23 + 0x58) = 0;
            *(undefined2 *)(iVar23 + 0x56) = 0x32;
          }
        }
        if (*(char *)((int)*(undefined4 *)(uVar29 << 2) + 0xaa) != '\0') {
          in_stack_0000fffc = (uint)*(byte *)((int)*(undefined4 *)(uVar29 << 2) + 0xaa);
          for (uVar14 = 0; (int)uVar14 < (int)(uint)DAT_2000_d1e6; uVar14 = uVar14 + 1) {
            uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
            iVar22 = (int)*(undefined4 *)(uVar29 << 2);
            iVar23 = *(int *)(iVar22 + 0x58);
            uVar24 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
            iVar17 = (int)*(undefined4 *)(uVar29 << 2);
            iVar21 = *(int *)(iVar17 + 0x8c);
            if ((iVar21 <= iVar23) &&
               ((iVar23 != iVar21 || (*(uint *)(iVar17 + 0x8a) <= *(uint *)(iVar22 + 0x56)))))
            break;
            if ((*(char *)((int)*(undefined4 *)(uVar14 << 2) + 0x3d) != '\0') &&
               (((0 < *(int *)((int)*(undefined4 *)(uVar14 << 2) + 0x54) &&
                 (*(char *)((int)*(undefined4 *)(uVar14 << 2) + 0x3f) == '\0')) &&
                (uVar14 != uVar29)))) {
              uStackY_2e = (uint)(((long)*(int *)((int)*(undefined4 *)(uVar14 << 2) + 0x54) *
                                   (long)(int)in_stack_0000fffc & 0xffffU) / 100);
              iStackY_2c = 0;
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
              iVar23 = (int)*(undefined4 *)(uVar29 << 2);
              uVar13 = *(uint *)(iVar23 + 0x8a);
              uVar24 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
              iVar21 = (int)*(undefined4 *)(uVar29 << 2);
              puVar3 = (uint *)(iVar21 + 0x56);
              iVar23 = (*(int *)(iVar23 + 0x8c) - *(int *)(iVar21 + 0x58)) -
                       (uint)(uVar13 < *puVar3);
              if ((iVar23 < 1) && ((iVar23 < 0 || (uVar13 - *puVar3 < uStackY_2e)))) {
                uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
                iVar23 = (int)*(undefined4 *)(uVar29 << 2);
                uVar13 = *(uint *)(iVar23 + 0x8a);
                uVar24 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
                iVar21 = (int)*(undefined4 *)(uVar29 << 2);
                puVar3 = (uint *)(iVar21 + 0x56);
                uStackY_2e = uVar13 - *puVar3;
                iStackY_2c = (*(int *)(iVar23 + 0x8c) - *(int *)(iVar21 + 0x58)) -
                             (uint)(uVar13 < *puVar3);
              }
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar14 << 2) >> 0x10);
              iVar21 = (int)*(undefined4 *)(uVar14 << 2);
              iVar23 = *(int *)(iVar21 + 0x58);
              if ((iVar23 <= iStackY_2c) &&
                 ((iVar23 < iStackY_2c || (*(uint *)(iVar21 + 0x56) < uStackY_2e)))) {
                uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar14 << 2) >> 0x10);
                iVar23 = (int)*(undefined4 *)(uVar14 << 2);
                iStackY_2c = *(int *)(iVar23 + 0x58);
                uStackY_2e = *(uint *)(iVar23 + 0x56);
              }
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
              iVar23 = (int)*(undefined4 *)(uVar29 << 2);
              puVar3 = (uint *)(iVar23 + 0x56);
              uVar13 = *puVar3;
              *puVar3 = *puVar3 + uStackY_2e;
              piVar2 = (int *)(iVar23 + 0x58);
              *piVar2 = *piVar2 + iStackY_2c + (uint)CARRY2(uVar13,uStackY_2e);
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar14 << 2) >> 0x10);
              iVar23 = (int)*(undefined4 *)(uVar14 << 2);
              puVar3 = (uint *)(iVar23 + 0x56);
              uVar13 = *puVar3;
              *puVar3 = *puVar3 - uStackY_2e;
              piVar2 = (int *)(iVar23 + 0x58);
              *piVar2 = (*piVar2 - iStackY_2c) - (uint)(uVar13 < uStackY_2e);
            }
          }
        }
        iVar23 = *(int *)((int)*(undefined4 *)(uVar29 << 2) + 0x58);
        if ((iVar23 < 1) && (iVar23 < 0)) {
          uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
          iVar23 = (int)*(undefined4 *)(uVar29 << 2);
          *(undefined2 *)(iVar23 + 0x58) = 0;
          *(undefined2 *)(iVar23 + 0x56) = 0;
        }
        uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
        iVar22 = (int)*(undefined4 *)(uVar29 << 2);
        iVar23 = *(int *)(iVar22 + 0x58);
        uVar24 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
        iVar17 = (int)*(undefined4 *)(uVar29 << 2);
        iVar21 = *(int *)(iVar17 + 0x8c);
        if ((iVar21 <= iVar23) &&
           ((iVar21 < iVar23 || (*(uint *)(iVar17 + 0x8a) < *(uint *)(iVar22 + 0x56))))) {
          uVar24 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
          iVar23 = (int)*(undefined4 *)(uVar29 << 2);
          uVar16 = *(undefined2 *)(iVar23 + 0x8a);
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uVar29 << 2) >> 0x10);
          iVar21 = (int)*(undefined4 *)(uVar29 << 2);
          *(undefined2 *)(iVar21 + 0x58) = *(undefined2 *)(iVar23 + 0x8c);
          *(undefined2 *)(iVar21 + 0x56) = uVar16;
        }
      }
    }
    GGameState = 0x40;
    if (DebugVerbose != false) {
      pcVar27 = (char *)0x1000;
      printf("%d \r",0x40);
    }
    puVar15 = (uint *)&GUnitDescriptions[3].ofs;
    while (puVar15 = (uint *)((int)puVar15 + 1), puVar15 < DAT_2000_ca99) {
      uVar16 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
      iVar23 = (int)DAT_2000_ca95;
      if ((*(uint *)((uint)*(byte *)(iVar23 + (int)puVar15 * 9) * 0x27 + 0x121) & 0x40) != 0) {
        if (*(char *)(iVar23 + (int)puVar15 * 9 + 8) != '\0') {
          pcVar1 = (char *)(iVar23 + (int)puVar15 * 9 + 8);
          *pcVar1 = *pcVar1 + -1;
        }
        uVar16 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
        if (*(char *)((int)DAT_2000_ca95 + (int)puVar15 * 9 + 8) == '\0') {
          uVar8 = *(undefined4 *)((uint)*(byte *)((int)DAT_2000_ca95 + (int)puVar15 * 9 + 2) << 2);
          if (*(char *)((int)uVar8 + 0x3f) == '\0') {
            ovr_play_sfx(81,0);
            pcVar27 = (char *)"puppetmaker" + 3;
            pcVar30 = (char *)ovr_OVC23_55fe_3450();
            pcVar30 = ovr_fmVsprintf((char *)"Mine exhausted at (%d, %d).",pcVar30);
            ovr_say((char *)CONCAT22(pcVar27,pcVar30));
            pcVar27 = (char *)"steam bath" + 6;
            ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
          }
          OVC22_5087_1674();
        }
      }
    }
    GGameState = 0x42;
    if (DebugVerbose == false) goto LAB_5087_323a;
    break;
  case 2:
    if (in_CX != 1 && uVar29 != 0) goto code_r0x00053afb;
    break;
  case 3:
    puVar3 = param_2 + uVar29;
    *puVar3 = *puVar3 >> 7 | *puVar3 << 9;
    *(uint *)((char *)"%s: Costs %d gold of income and provides storage for %u food." + 8 +
             iVar23 + param_1) =
         *(uint *)((char *)"%s: Costs %d gold of income and provides storage for %u food." + 8 +
                  iVar23 + param_1) | (uint)&stack0xfff8;
    puVar3 = (uint *)(iVar23 + param_1 + 9);
    *puVar3 = *puVar3 | (uint)&stack0xfffe;
    AgntAnms[0x7d].x = AgntAnms[0x7d].x | (uint)&stack0xfff8;
    *param_2 = *param_2 | uVar29;
    (&stack0x8d06)[(int)param_2] = (&stack0x8d06)[(int)param_2];
    *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | bVar32;
    (&stack0xfffe)[param_1] = (&stack0xfffe)[param_1] | (byte)((uint)(iVar23 + 1) >> 8);
    pbVar4 = (byte *)(iVar23 + 1 + (int)param_2);
    *pbVar4 = *pbVar4 | (byte)in_CX | (byte)param_1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pcVar27 = (char *)0x1000;
  printf(fmt,in_stack_0000fffc);
LAB_5087_323a:
  pcStackY_1a = (char *)"farm1.voc" + 1;
  pcStackY_18 = pcVar27;
  ovr_driver_2d63_0a67();
  uVar29 = 0;
  while (uVar29 < DAT_2410_0881) {
    pcVar30 = (char *)((ulong)DAT_2000_cb09 >> 0x10);
    iVar23 = (int)DAT_2000_cb09 + *(int *)(uVar29 * 0x13 + 2) * 0x128;
    in_stack_0000ffea = uVar29;
code_r0x00053afb:
    puVar3 = (uint *)(iVar23 + *(int *)(uVar29 * 0x13) * 2);
    *puVar3 = *puVar3 | 8;
    uVar29 = in_stack_0000ffea + 1;
  }
  if (EntityCount <= DAT_2410_55d6) {
    DAT_2410_55d6 = (uint16_t)(0x0);
    for (pcVar30 = (char *)0x0; (int)pcVar30 < (int)(uint)DAT_2000_d1e6; pcVar30 = pcVar30 + 1) {
      if (*(char *)((int)*(undefined4 *)((int)pcVar30 << 2) + 0x3d) != '\0') {
        piVar18 = (int *)((int)pcVar30 * 4);
        piVar19 = (int *)((int)pcVar30 * 4);
        pcVar30 = (char *)"build\\magres01.lbm" + 2;
        memcpy((uint8_t *)(*piVar19 + 0x8e),(uint8_t *)(*piVar18 + 0x94),3);
      }
    }
  }
  pcVar30 = (char *)0x0;
  ovr_manage_4d05_1b1d();
  for (pcVar27 = DAT_2410_55d6; pcVar27 < EntityCount; pcVar27 = pcVar27 + 1) {
    uVar26 = Entities.seg;
    uVar20 = Entities.ofs;
    if (((*(char *)(uVar20 + (int)pcVar27 * 0x37 + 0x18) == '\0') &&
        (*(int *)(uVar20 + (int)pcVar27 * 0x37 + 8) == 0)) &&
       (*(int *)(uVar20 + (int)pcVar27 * 0x37 + 10) == 0)) {
      bVar32 = *(byte *)(uVar20 + (int)pcVar27 * 0x37 + 0xd);
      bVar5 = *(byte *)(uVar20 + (int)pcVar27 * 0x37 + 0x1a);
      bVar28 = false;
      bVar10 = false;
      bVar9 = false;
      if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bVar32 * 0x95) == -1) {
        bVar28 = true;
      }
      else {
        bVar6 = *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x89);
        uStackY_1c = (char *)CONCAT11(bVar6,(char)uStackY_1c);
        if (bVar6 < 5) {
          pcStackY_1a = (char *)*(undefined2 *)(uVar20 + (int)pcVar27 * 0x37 + 2);
          pcStackY_18 = (char *)ovr_OVC23_55fe_3450();
          pcVar30 = (char *)"puppetmaker" + 3;
          if ((*(uint *)((int)DAT_2000_cb09 + (int)pcStackY_1a * 0x128 + (int)pcStackY_18 * 2) & 8)
              == 0) {
            uStackY_1e = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)),0x22);
            bStackY_1f = 0x21;
            bStackY_20 = 0x22;
          }
          else {
            pcVar27 = (char *)CONCAT11((char)((uint)&bStackY_20 >> 8),(*(uint8_t *)((uint8_t *)&(uStackY_1c) + 1)));
            pcStackY_18 = pcStackY_1a;
            uStackY_1c = (char *)"dwarf outpost" + 6;
            uStackY_1e = (char *)"portrait\\sp23.lbm" + 0x11;
            pcStackY_1a = (char *)ovr_attact_3f0b_0585();
            uStackY_1c = (char *)"ringmaker\'s shop" + 7;
            uStackY_1e = (char *)"portrait\\sp24.lbm" + 9;
            pcStackY_18 = pcVar30;
            ovr_attact_3f0b_2303();
          }
        }
        else {
          uStackY_1e = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)),0x22);
          bStackY_1f = 0x21;
          bStackY_20 = 0x22;
        }
        pcVar30 = (char *)"portrait\\sp26.lbm" + 0xd;
        uVar20 = ovr_randBelow(100);
        if ((byte)uVar20 < (byte)uStackY_1e) {
          bVar28 = true;
        }
        else if ((uVar20 & 0xff) < (uint)bStackY_1f + ((uint)uStackY_1e & 0xff)) {
          bVar10 = true;
        }
        else {
          bVar9 = true;
        }
      }
      if (bVar9) {
        pcVar30 = (char *)*(int *)(Entities.ofs + (int)pcVar27 * 0x37);
        cVar12 = ovr_OVC23_55fe_0487();
        if (cVar12 == '\0') {
          if ((bStackY_1f == 0) && ((byte)uStackY_1e == '\0')) {
            pcVar30 = (char *)"portrait\\sp34.lbm" + 0x10;
            uVar20 = ovr_randBelow(2);
            if ((uVar20 & 0xff) == 0) {
              bVar28 = true;
            }
            else {
              bVar10 = true;
            }
          }
          else {
            pcVar30 = (char *)"captmg3.lbm" + 9;
            uVar20 = ovr_randBelow((uint)bStackY_1f + ((uint)uStackY_1e & 0xff));
            if ((byte)uVar20 < (byte)uStackY_1e) {
              bVar28 = true;
            }
            else {
              bVar10 = true;
            }
          }
        }
      }
      if (bVar28) {
        pcVar30 = (char *)"build\\gencas04.lbm" + 0x10;
        cVar12 = OVC22_5087_1532();
        if (cVar12 == '\0') {
          bVar10 = true;
        }
      }
      if (bVar10) {
        if ((*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bVar32 * 0x95) != -1) &&
           (bVar5 != 0xff)) {
          if ((*(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x3f) != '\0') ||
             (*(byte *)(Entities.ofs + (int)pcVar27 * 0x37 + 0xf) <
              *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x53))) {
            iVar23 = Entities.ofs + (int)pcVar27 * 0x37;
            uVar16 = OVC22_5087_18b6();
            LXMUL_at_(3,CONCAT22(iVar23,uVar16));
            iVar23 = Entities.ofs + (int)pcVar27 * 0x37;
            pcVar27 = (char *)"portrait\\sp38.lbm" + 7;
            ovr_OVC15_4207_26bc();
            uVar14 = OVC22_5087_1d4a();
            uVar20 = Entities.seg;
            iVar21 = Entities.ofs + (int)pcVar27 * 0x37;
            uVar29 = *(uint *)(iVar21 + 0x10);
            iVar22 = Entities.ofs + (int)pcVar27 * 0x37;
            *(int *)(iVar22 + 0x12) = *(int *)(iVar21 + 0x12) + iVar23 + (uint)CARRY2(uVar29,uVar14)
            ;
            *(int *)(iVar22 + 0x10) = uVar29 + uVar14;
            ovr_OVC41_6a8f_002e();
          }
        }
        OVC22_5087_1991();
        OVC22_5087_1ac1();
        pcVar30 = (char *)"portrait\\sp00.lbm" + 2;
        OVC22_5087_1ca4();
      }
      iStackY_2a = (uint)*(byte *)(Entities.ofs + (int)pcVar27 * 0x37 + 0xe) -
                   (uint)*(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4);
      if (0 < iStackY_2a) {
        if (3 < iStackY_2a) {
          iStackY_2a = 3;
        }
        if (iStackY_2a == 3) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x92) == 0) {
            iStackY_2a = 2;
          }
          else {
            piVar2 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x92);
            *piVar2 = *piVar2 + -1;
          }
        }
        if (iStackY_2a == 2) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x90) == 0) {
            iStackY_2a = 1;
          }
          else {
            piVar2 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x90);
            *piVar2 = *piVar2 + -1;
          }
        }
        if (iStackY_2a == 1) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x8e) == 0) {
            iStackY_2a = 0;
          }
          else {
            piVar2 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x8e);
            *piVar2 = *piVar2 + -1;
          }
        }
        *(char *)(Entities.ofs + (int)pcVar27 * 0x37 + 0xe) =
             *(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4) + (char)iStackY_2a;
      }
      pcVar30 = pcVar30 + 1;
      if (199 < (int)pcVar30) break;
    }
  }
  DAT_2410_55d6 = pcVar27;
  DAT_2410_648e = 1;
  ovr_unit_6616_00d8();
  GGameState = 0x44;
  puVar15 = (uint *)((char *)"puppetmaker" + 3);
  if (DebugVerbose != false) {
    puVar15 = (uint *)printf("%d \r",0x44);
  }
  if ((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)) != '\0') {
    puVar15 = (uint *)(EntityCount + -1);
    for (puVar31 = puVar15; -1 < (int)puVar31; puVar31 = (uint *)((int)puVar31 + -1)) {
      puVar15 = (uint *)(uint)*(byte *)(Entities.ofs + (int)puVar31 * 0x37 + 0xe);
      if (puVar15 == (uint *)0x0) {
        if (*(char *)((int)(char **)GMenuStrings +
                     (uint)*(byte *)(Entities.ofs + (int)puVar31 * 0x37 + 0xd) * 0x95 + 0x1f) ==
            '\0') {
          uVar20 = 0xa000;
          ovr_OVC23_55fe_3450();
          iVar23 = (int)puVar31 * 0x37;
          uVar16 = 0x195d;
          puVar31 = (uint *)"Intelligence reports %s unit died of starvation. (%d, %d)";
          pcStackY_18 = (char *)"dwarf outpost" + 6;
          pcStackY_1a = (char *)"build\\genoutp1.lbm" + 0xe;
          pcVar30 = ovr_fmVsprintf((char *)
                                   "Intelligence reports %s unit died of starvation. (%d, %d)",
                                   (char *)*(undefined2 *)
                                            ((int)&far_t_ARRAY_2410_26f7[0].seg + 1 +
                                            (uint)*(byte *)(Entities.ofs + iVar23 + 0xd) * 0x95));
          ovr_uiNotify((char *)CONCAT22(uVar16,pcVar30),uVar20);
        }
        puVar15 = (uint *)ovr_OVC15_4207_0e17();
      }
    }
  }
  if ((char)uStackY_1c != '\0') {
    puVar15 = (uint *)ovr_constr_36ce_1db4();
  }
  return puVar15;
}



/* 55fe:0cdf */

/* WARNING: Instruction at (ram,0x00056a00) overlaps instruction at (ram,0x000569fe)
    */
/* WARNING: Unable to track spacebase fully for stack */

char * __cdecl16far OVC23_55fe_0cdf(char *param_1,undefined1 *param_2,byte param_3)

{
  int *piVar1;
  uint *puVar2;
  byte *pbVar3;
  byte bVar4;
  undefined1 *puVar6;
  undefined1 uVar7;
  uint16_t play_id;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined2 uVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  char cVar14;
  byte bVar18;
  int iVar15;
  char *pcVar16;
  undefined4 *puVar17;
  undefined1 *in_CX;
  byte bVar19;
  byte bVar20;
  byte bVar23;
  uint uVar21;
  char *pcVar22;
  uint *puVar24;
  uint *puVar25;
  int iVar26;
  uint *puVar28;
  undefined2 *puVar29;
  undefined2 *puVar30;
  uint uVar31;
  int unaff_SI;
  uint uVar32;
  undefined1 *puVar33;
  undefined2 unaff_SS;
  undefined2 uVar34;
  bool bVar35;
  bool bVar36;
  bool bVar37;
  byte in_AF;
  bool bVar38;
  bool bVar39;
  bool bVar40;
  far_t dst;
  long lVar41;
  int in_stack_0000fffc;
  byte bVar5;
  byte bVar27;
  
  puVar33 = param_2;
  pcVar16 = param_1;
  pcVar22 = param_1 + *(char *)(param_3 + 0x885);
  bVar19 = (byte)pcVar22;
  cVar14 = ovr_attact_3f0b_01ec();
  if ((cVar14 != '\0') &&
     (puVar17 = (undefined4 *)(uint)param_3,
     puVar17 <= (undefined4 *)((int)(undefined4 *)&_DATA + 3))) {
    iVar26 = (int)puVar17 * 2;
    switch(puVar17) {
    case (undefined4 *)0x0:
      (**(code **)(pcVar16 + iVar26 + -0x70))();
      break;
    case (undefined4 *)0x2:
      uVar21 = 0x1000 << (*(byte *)((int)*puVar17 + 0x3f) & 0x1f);
      uVar31 = 0;
      lVar41 = (ulong)(uint)(0x1000 <<
                            ((*(byte *)((int)*(undefined4 *)((uint)bVar19 << 2) + 0x3f) ^ 1) & 0x1f)
                            ) << 0x10;
      while (bVar19 = (byte)((ulong)lVar41 >> 8), bVar19 < 4) {
        iVar26 = (in_stack_0000fffc + (uint)bVar19) * 2;
        uVar31 = uVar31 | *(uint *)((int)DAT_2000_cb09 + unaff_SI * 0x128 + iVar26 + -4) & 0x3000;
        lVar41 = (ulong)CONCAT21(iVar26,bVar19 + 1) << 8;
      }
      if ((((*(byte *)((int)pcVar16 * 0x12 + 0xd) & 3) == 1) &&
          (uVar31 == (uint)((ulong)lVar41 >> 0x10))) &&
         (cVar14 = ovr_OVC24_5943_1eeb(), cVar14 == '\0')) {
        cVar14 = OVC23_55fe_05db();
        if (cVar14 != '\0') {
          ovr_say("Construction abandoned.");
        }
        if (pcVar16 + 1 < DAT_2000_d2df) {
          _fmemmove((uint8_t *)((int)pcVar16 * 0x12),(uint8_t *)((int)pcVar16 * 0x12 + 0x12),
                    (int)(DAT_2000_d2df + (-1 - (int)pcVar16)) * 0x12);
        }
        DAT_2000_d2df = DAT_2000_d2df + -1;
        pcVar22 = (char *)OVC23_55fe_0000();
      }
      else {
        bVar19 = *(byte *)((int)pcVar16 * 0x12 + 0xd);
        pcVar22 = (char *)(uint)bVar19;
        if (((bVar19 & 1) == 0) && ((uVar21 & uVar31) != 0)) {
          pcVar22 = (char *)((int)pcVar16 * 0x12);
          pcVar22[0xd] = pcVar22[0xd] | 1;
        }
      }
      return pcVar22;
    case (undefined4 *)0x3:
      pcVar22 = pcVar22 + -1;
      bVar20 = (byte)iVar26;
      bVar13 = bVar20 - AgntAnms[0xf].frmid;
      bVar11 = (byte)((uint)iVar26 >> 8);
      bVar19 = bVar11 - param_3;
      bVar27 = bVar19 - (bVar20 < AgntAnms[0xf].frmid);
      puVar24 = (uint *)CONCAT11(bVar27,bVar13);
      puVar8 = (undefined1 *)(uint)(bVar11 < param_3 || bVar19 < (bVar20 < AgntAnms[0xf].frmid));
      puVar29 = (undefined2 *)(&stack0xfffe + -(int)in_CX + -(int)puVar8);
      puVar2 = (uint *)(puVar33 + -0x57e7);
      uVar31 = (uint)(&stack0xfffe < in_CX || &stack0xfffe + -(int)in_CX < puVar8);
      puVar30 = (undefined2 *)*puVar2;
      uVar21 = *puVar2;
      *puVar2 = (uVar21 - (int)puVar29) - uVar31;
      puVar2 = (uint *)((int)puVar29 + 0x7419);
      uVar31 = (uint)(puVar30 < puVar29 || uVar21 - (int)puVar29 < uVar31);
      puVar8 = (undefined1 *)*puVar2;
      uVar21 = *puVar2;
      *puVar2 = (uVar21 - (int)in_CX) - uVar31;
      puVar2 = (uint *)(pcVar16 + 0x19);
      uVar31 = (uint)(puVar8 < in_CX || uVar21 - (int)in_CX < uVar31);
      puVar25 = (uint *)*puVar2;
      uVar21 = *puVar2;
      *puVar2 = (uVar21 - (int)puVar24) - uVar31;
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
      uVar21 = (uint)(puVar25 < puVar24 || uVar21 - (int)puVar24 < uVar31);
      (*(uint16_t *)((uint8_t *)&(s_Peaceful_2410_2915) + 4)) = (0x6665U - (int)puVar33) - uVar21;
      uVar21 = (uint)((uint)0x6665 < puVar33 || (uint)(0x6665U - (int)puVar33) < uVar21);
      bVar35 = (uint)AgntAnms[6].y < pcVar22;
      uVar31 = AgntAnms[6].y - (int)pcVar22;
      AgntAnms[6].y = uVar31 - uVar21;
      puVar8 = (undefined1 *)(uint)(bVar35 || uVar31 < uVar21);
      puVar9 = &stack0xfff6 + -(int)puVar33;
      bVar35 = &stack0xfff6 < puVar33 || puVar9 < puVar8;
      iVar26 = -(int)puVar8;
      puVar28 = (uint *)(puVar9 + iVar26);
      bVar11 = (byte)((uint)in_CX >> 8);
      bVar19 = (byte)pcVar22 - bVar11;
      bVar36 = (byte)pcVar22 < bVar11 || bVar19 < bVar35;
      bVar23 = (byte)((uint)pcVar22 >> 8);
      bVar19 = bVar19 - bVar35;
      bVar35 = bVar13 != 0 || (byte)-bVar13 < bVar36;
      bVar18 = -bVar13 - bVar36;
      bVar20 = bVar19 - param_3;
      bVar36 = bVar19 < param_3 || bVar20 < bVar35;
      bVar20 = bVar20 - bVar35;
      pbVar3 = (byte *)((char *)((int)puVar24 + (int)pcVar16) + -0x60e8);
      bVar35 = *pbVar3 < bVar11 || (byte)(*pbVar3 - bVar11) < bVar36;
      *pbVar3 = (*pbVar3 - bVar11) - bVar36;
      pbVar3 = (byte *)(puVar29 + -0x3974);
      bVar36 = *pbVar3 < bVar20 || (byte)(*pbVar3 - bVar20) < bVar35;
      *pbVar3 = (*pbVar3 - bVar20) - bVar35;
      pbVar3 = (byte *)(pcVar16 + 31000);
      bVar37 = *pbVar3 < param_3 || (byte)(*pbVar3 - param_3) < bVar36;
      *pbVar3 = (*pbVar3 - param_3) - bVar36;
      pbVar3 = (byte *)(puVar29 + 0xc);
      bVar19 = *pbVar3;
      bVar11 = *pbVar3 - bVar23;
      bVar36 = bVar19 < bVar23 || bVar11 < bVar37;
      bVar40 = SBORROW1(*pbVar3,bVar23) != SBORROW1(bVar11,bVar37);
      *pbVar3 = bVar11 - bVar37;
      bVar39 = (char)*pbVar3 < '\0';
      bVar38 = *pbVar3 == 0;
      bVar35 = !bVar40;
      bVar12 = (byte)in_CX;
      puVar30 = puVar29;
      if (!bVar35) {
        puVar6 = puVar33;
        puVar33 = puVar33 + 1;
        uVar7 = in(CONCAT11(bVar23,bVar20));
        *puVar6 = uVar7;
        pbVar3 = (byte *)(pcVar16 + 0x18);
        bVar4 = *pbVar3;
        bVar5 = *pbVar3;
        *pbVar3 = (bVar5 - bVar18) - bVar36;
        *(uint **)(puVar9 + iVar26 + -2) = puVar24;
        ((char *)((int)puVar29 + (int)pcVar16))[0x18] =
             (((char *)((int)puVar29 + (int)pcVar16))[0x18] - bVar12) -
             (bVar4 < bVar18 || (byte)(bVar5 - bVar18) < bVar36);
        *(uint *)((int)puVar24 + (int)pcVar16) =
             *(uint *)((int)puVar24 + (int)pcVar16) ^ (uint)puVar24;
        *(uint *)((int)puVar24 + (int)pcVar16) =
             *(uint *)((int)puVar24 + (int)pcVar16) | (uint)puVar24;
        *(char *)((int)puVar24 + (int)pcVar16) = *(char *)((int)puVar24 + (int)pcVar16) + bVar13;
        *puVar24 = ~*puVar24;
        puVar30 = (undefined2 *)*puVar29;
        uVar21 = CONCAT11(bVar18,param_3 - 0x18) & 0x9e1f;
        bVar39 = (int)uVar21 < 0;
        bVar38 = uVar21 == 0;
        puVar28 = puVar29 + 3;
      }
      bVar36 = bVar35 && bVar36;
      uVar34 = *puVar28;
      if (bVar38 || (bVar35 && bVar40) != bVar39) {
        bVar39 = bVar36;
        if ((!bVar35 || bVar19 >= bVar23 && bVar11 >= bVar37) && !bVar38) {
          *puVar28 = (uint)puVar30;
          uVar34 = *puVar28;
          pcVar22 = (char *)(int)(char)bVar12 + -0x1d67;
          iVar26 = (int)pcVar22 - (int)(uint)bVar36;
          *puVar28 = iVar26;
          *pcVar16 = -*pcVar16;
          return (char *)((iVar26 + -0x1d32) -
                         (uint)((char *)(int)(char)bVar12 < (char *)"magicians\' cottage" + 9 ||
                               pcVar22 < (char *)(uint)bVar36));
        }
      }
      else {
        bVar39 = bVar12 < 0x74 || (byte)(bVar12 + 0x8c) < bVar36;
        bVar12 = (bVar12 + 0x8c) - bVar36;
      }
      bVar35 = bVar12 < 100 || (byte)(bVar12 + 0x9c) < bVar39;
      bVar11 = (bVar12 + 0x9c) - bVar39;
      bVar19 = bVar11 - 0x39;
      bVar36 = bVar11 < 0x39 || bVar19 < bVar35;
      bVar19 = bVar19 - bVar35;
      bVar11 = bVar19 - 0x14;
      bVar35 = bVar19 < 0x14 || bVar11 < bVar36;
      bVar11 = bVar11 - bVar36;
      bVar19 = bVar11 - 8;
      bVar36 = bVar11 < 8 || bVar19 < bVar35;
      bVar19 = bVar19 - bVar35;
      bVar11 = bVar19 - 5;
      bVar12 = bVar11 - bVar36;
      iVar26 = -(uint)(bVar12 < 0xfa || (byte)(bVar12 + 6) < (bVar19 < 5 || bVar11 < bVar36)) -
               (int)puVar24;
      uVar31 = (uint)pcVar16 & *(uint *)((char *)((int)puVar24 + (int)pcVar16) + -0x6bdd);
      uVar32 = (uint)puVar33 & *(uint *)((undefined1 *)((int)puVar24 + (int)puVar33) + 0x23);
      *puVar28 = uVar31;
      uVar31 = uVar31 & *(uint *)((int)puVar24 + uVar32);
      uVar21 = CONCAT11(bVar23,bVar20) & *(uint *)((int)puVar30 + uVar31 + iVar26);
      puVar25 = (uint *)CONCAT11(bVar27,bVar13 & bVar27 &
                                        *(byte *)((int)&_streams[0xc].curp +
                                                 CONCAT11(bVar27,bVar13 & bVar27)));
      uVar10 = *puVar28;
      puVar2 = (uint *)((int)puVar30 + uVar31 + iVar26);
      *puVar2 = *puVar2 ^ (uint)(puVar28 + 1);
      piVar1 = (int *)((int)puVar30 + uVar31 + iVar26);
      *piVar1 = *piVar1 - (int)(puVar28 + 1);
      bVar19 = in(uVar21);
      uVar31 = uVar31 & uVar21;
      puVar2 = (uint *)((int)puVar25 + (int)((char *)"+%d ring of prot." + 1 + uVar31));
      *puVar2 = *puVar2 & uVar32;
      *(uint *)(uVar32 + 0x21) = *(uint *)(uVar32 + 0x21) & (uint)puVar25;
      *puVar25 = *puVar25 & uVar32;
      puVar2 = (uint *)&AgntAnms[0x5c].sx;
      *puVar2 = *puVar2 & (uint)(puVar28 + 1);
      puVar2 = (uint *)((int)puVar25 + uVar31);
      *puVar2 = *puVar2 & CONCAT11((char)((uint)uVar10 >> 8),bVar19);
      bVar13 = -(0x99 < bVar19);
      return (char *)CONCAT11((char)((uint)uVar10 >> 8),
                              bVar13 + (9 < (bVar13 & 0xf) | 9 < (bVar19 & 0xf) | in_AF) * '\x06' +
                              (0x99 < bVar13 || 0x99 < bVar19) * '`');
    }
    do {
      OVC23_55fe_23d8();
      cVar14 = '\x01';
      do {
        while( true ) {
          do {
            do {
              puVar33 = puVar33 + 1;
              pcVar16 = (char *)"puppetmaker" + 3;
              if (DAT_2000_cfd8 <= puVar33) {
                if (cVar14 != '\0') {
                  pcVar16 = (char *)ovr_constr_36ce_04e9();
                }
                return pcVar16;
              }
              play_id = *(uint16_t *)((int)puVar33 * 2 + 0x360);
            } while (((int)play_id < -2) || (1 < (int)play_id));
            iVar26 = ovr_constr_36ce_0159();
            if (((char *)"build\\thfres01.lbm" + 0x10)[iVar26 * 3 + *(int *)((int)puVar33 * 2)] !=
                '\0') {
              iVar15 = OVC23_55fe_0617();
              dst.seg = (uint16_t)param_2;
              dst.ofs = (uint16_t)param_1;
              ovr_animAdvance(play_id,((char *)"build\\thfres01.lbm" + 0x10)
                                      [iVar26 * 3 + *(int *)((int)puVar33 * 2)],
                              *(uint16_t *)((int)puVar33 * 2 + 0xa20),(uint)DAT_2410_0728 - iVar15,
                              dst);
              cVar14 = '\x01';
            }
          } while (*(int *)(play_id * 2 + -0x6e25) == -1);
          if (*(char *)(play_id + 0x90ec) != '\0') break;
          OVC23_55fe_0768();
          OVC23_55fe_23d8();
          cVar14 = '\x01';
        }
      } while (play_id != 0xfffe);
      OVC23_55fe_0768();
    } while( true );
  }
  return (char *)0x0;
}



/* 55fe:0f39 */

void __cdecl16far OVC23_55fe_0f39(int param_1,int param_2)

{
  uint *puVar1;
  char cVar2;
  byte bStack_3;
  
  if ((((param_1 < 0x94) && (-1 < param_1)) && (param_2 < 0x3c)) && (-1 < param_2)) {
    puVar1 = (uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2);
    *puVar1 = *puVar1 & 0xff0f;
    for (bStack_3 = 0; bStack_3 < 4; bStack_3 = bStack_3 + 1) {
      cVar2 = OVC23_55fe_0af5(param_1,param_2,bStack_3);
      if (cVar2 != '\0') {
        puVar1 = (uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2);
        *puVar1 = *puVar1 | 0x10 << (bStack_3 & 0x1f);
      }
      cVar2 = OVC23_55fe_0cdf(param_1,param_2,bStack_3);
      if (cVar2 != '\0') {
        puVar1 = (uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2);
        *puVar1 = *puVar1 | 0x100 << (bStack_3 & 0x1f);
      }
    }
  }
  return;
}



/* 55fe:1005 */

void __cdecl16far OVC23_55fe_1005(int param_1,int param_2,byte param_3,undefined1 param_4)

{
  byte *pbVar1;
  uint *puVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  undefined1 uVar8;
  int iVar6;
  int iVar7;
  
  iVar4 = *(int *)((int)DAT_2000_cb0d + param_1 * 0x78 + param_2 * 2);
  bVar3 = *(byte *)((int)DAT_2000_ca95 + iVar4 * 9);
  pcVar5 = (char *)((uint)bVar3 * 0x27);
  if ((*(uint *)(pcVar5 + 0x121) & 4) != 0) {
    pcVar5 = (char *)"puppetmaker" + 3;
    DAT_2000_d2e2 = 1;
  }
  uVar8 = (undefined1)((uint)pcVar5 >> 8);
  iVar6 = ovr_OVC18_48ac_0bf4(param_1,param_2,CONCAT11(uVar8,param_3),CONCAT11(uVar8,param_4));
  if ((*(byte *)((uint)param_3 * 0x27 + 0x11e) & 2) == 2) {
    OVC23_55fe_0aba(param_1,param_2);
  }
  if (((*(byte *)((uint)param_3 * 0x27 + 0x11e) & 0xf) != 0) ||
     ((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 0xf) != 0)) {
    OVC23_55fe_0f39(param_1,param_2);
  }
  if (((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 1) != 0) ||
     ((*(byte *)((uint)param_3 * 0x27 + 0x11e) & 1) != 0)) {
    OVC23_55fe_0f39(param_1,param_2 + 1);
  }
  if (((*(byte *)((uint)param_3 * 0x27 + 0x11e) & 2) != 0) ||
     ((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 2) != 0)) {
    OVC23_55fe_0f39(param_1 + -1,param_2);
  }
  if (((*(byte *)((uint)param_3 * 0x27 + 0x11e) & 3) == 3) ||
     ((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 3) == 3)) {
    OVC23_55fe_0f39(param_1 + 1,param_2);
    OVC23_55fe_0f39(param_1,param_2 + 1);
  }
  if (*(char *)((uint)param_3 * 0x27 + 0x11a) == '\x02') {
    if ((*(uint *)(param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2 + 0x128) & 3) != 0) {
      pbVar1 = (byte *)((int)DAT_2000_ca95 + iVar6 * 9 + 3);
      *pbVar1 = *pbVar1 | 4;
      puVar2 = (uint *)(param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2 + 0x128);
      *puVar2 = *puVar2 & 0xfffc;
    }
    if ((*(byte *)((uint)param_3 * 0x27 + 0x11e) & 4) != 0) {
      if ((*(uint *)(param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2 + 0x126) & 3) != 0) {
        pbVar1 = (byte *)((int)DAT_2000_ca95 + iVar6 * 9 + 3);
        *pbVar1 = *pbVar1 | 8;
        puVar2 = (uint *)(param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2 + 0x126);
        *puVar2 = *puVar2 & 0xfffc;
        OVC23_55fe_0f39(param_1 + -2,param_2);
        OVC23_55fe_0f39(param_1 + -1,param_2 + -1);
        OVC23_55fe_0f39(param_1 + -1,param_2 + 1);
      }
      if ((*(uint *)(param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2 + 0x12a) & 3) != 0) {
        pbVar1 = (byte *)((int)DAT_2000_ca95 + iVar6 * 9 + 3);
        *pbVar1 = *pbVar1 | 0x10;
        puVar2 = (uint *)(param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2 + 0x12a);
        *puVar2 = *puVar2 & 0xfffc;
        OVC23_55fe_0f39(param_1 + 1,param_2 + -1);
        OVC23_55fe_0f39(param_1 + 1,param_2 + 1);
        OVC23_55fe_0f39(param_1 + 2,param_2);
      }
    }
    if ((*(byte *)((uint)param_3 * 0x27 + 0x11e) & 8) != 0) {
      if ((*(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2) & 3) != 0) {
        pbVar1 = (byte *)((int)DAT_2000_ca95 + iVar6 * 9 + 3);
        *pbVar1 = *pbVar1 | 8;
        puVar2 = (uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2);
        *puVar2 = *puVar2 & 0xfffc;
        OVC23_55fe_0f39(param_1 + -1,param_2 + -1);
        OVC23_55fe_0f39(param_1 + 1,param_2 + -1);
        OVC23_55fe_0f39(param_1,param_2 + -2);
      }
      if ((*(uint *)(param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2 + 0x250) & 3) != 0) {
        pbVar1 = (byte *)((int)DAT_2000_ca95 + iVar6 * 9 + 3);
        *pbVar1 = *pbVar1 | 0x10;
        puVar2 = (uint *)(param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2 + 0x250);
        *puVar2 = *puVar2 & 0xfffc;
        OVC23_55fe_0f39(param_1 + -1,param_2 + 1);
        OVC23_55fe_0f39(param_1 + 1,param_2 + 1);
        OVC23_55fe_0f39(param_1,param_2 + 2);
      }
    }
    OVC23_55fe_0f39(param_1,param_2);
    OVC23_55fe_0f39(param_1 + 1,param_2);
    OVC23_55fe_0f39(param_1 + -1,param_2);
    OVC23_55fe_0f39(param_1,param_2 + -1);
    OVC23_55fe_0f39(param_1,param_2 + 1);
  }
  if (*(char *)((uint)bVar3 * 0x27 + 0x11a) == '\x02') {
    OVC23_55fe_0aba(param_1,param_2);
    if ((*(byte *)((int)DAT_2000_ca95 + iVar4 * 9 + 3) & 4) != 0) {
      OVC23_55fe_2e4c(param_1,param_2);
    }
    if (*(char *)((uint)bVar3 * 0x27 + 0x11e) == '\x04') {
      iVar7 = ovr_OVC45_77eb_0121(param_1 + -1,param_2);
      if ((iVar7 == 0) && ((*(byte *)((int)DAT_2000_ca95 + iVar4 * 9 + 3) & 8) != 0)) {
        OVC23_55fe_0aba(param_1 + -1,param_2);
        OVC23_55fe_2e4c(param_1 + -1,param_2);
        OVC23_55fe_0f39(param_1 + -1,param_2 + -1);
        OVC23_55fe_0f39(param_1 + -1,param_2 + 1);
        OVC23_55fe_0f39(param_1 + -2,param_2);
      }
      iVar7 = ovr_OVC45_77eb_0121(param_1 + 1,param_2);
      if ((iVar7 == 0) && ((*(byte *)((int)DAT_2000_ca95 + iVar4 * 9 + 3) & 0x10) != 0)) {
        OVC23_55fe_0aba(param_1 + 1,param_2);
        OVC23_55fe_2e4c(param_1 + 1,param_2);
        OVC23_55fe_0f39(param_1 + 1,param_2 + -1);
        OVC23_55fe_0f39(param_1 + 1,param_2 + 1);
        OVC23_55fe_0f39(param_1 + 2,param_2);
      }
    }
    else if (*(char *)((uint)bVar3 * 0x27 + 0x11e) == '\b') {
      iVar7 = ovr_OVC45_77eb_0121(param_1,param_2 + -1);
      if ((iVar7 == 0) && ((*(byte *)((int)DAT_2000_ca95 + iVar4 * 9 + 3) & 8) != 0)) {
        OVC23_55fe_0aba(param_1,param_2 + -1);
        OVC23_55fe_2e4c(param_1,param_2 + -1);
        OVC23_55fe_0f39(param_1 + -1,param_2 + -1);
        OVC23_55fe_0f39(param_1 + 1,param_2 + -1);
        OVC23_55fe_0f39(param_1,param_2 + -2);
      }
      iVar7 = ovr_OVC45_77eb_0121(param_1,param_2 + 1);
      if ((iVar7 == 0) && ((*(byte *)((int)DAT_2000_ca95 + iVar4 * 9 + 3) & 0x10) != 0)) {
        OVC23_55fe_0aba(param_1,param_2 + 1);
        OVC23_55fe_2e4c(param_1,param_2 + 1);
        OVC23_55fe_0f39(param_1 + -1,param_2 + 1);
        OVC23_55fe_0f39(param_1 + 1,param_2 + 1);
        OVC23_55fe_0f39(param_1,param_2 + 2);
      }
    }
    OVC23_55fe_0f39(param_1,param_2);
    OVC23_55fe_0f39(param_1 + 1,param_2);
    OVC23_55fe_0f39(param_1 + -1,param_2);
    OVC23_55fe_0f39(param_1,param_2 + -1);
    OVC23_55fe_0f39(param_1,param_2 + 1);
  }
  if ((*(char *)((uint)param_3 * 0x27 + 0x133) == '\x12') && (DAT_2000_d3c6 < 5)) {
    *(int *)((uint)DAT_2000_d3c6 * 2 + -0x6d44) = iVar6;
    DAT_2000_d3c6 = DAT_2000_d3c6 + 1;
  }
  if ((*(int *)((uint)param_3 * 0x27 + 0x12e) != 0) || (*(int *)((uint)bVar3 * 0x27 + 0x12e) != 0))
  {
    ovr_unit_6616_00d8();
  }
  return;
}



/* 55fe:1803 */

void __cdecl16far OVC23_55fe_1803(int param_1)

{
  if (param_1 + 1U < DAT_2000_d2df) {
    _fmemmove((uint8_t *)(param_1 * 0x12),(uint8_t *)(param_1 * 0x12 + 0x12),
              ((DAT_2000_d2df - param_1) + -1) * 0x12);
  }
  DAT_2000_d2df = DAT_2000_d2df - 1;
  OVC23_55fe_0000();
  return;
}



/* 55fe:184e */

void __cdecl16far
OVC23_55fe_184e(byte param_1,int param_2,int param_3,undefined1 *param_4,byte param_5,char param_6)

{
  int *piVar1;
  byte *pbVar2;
  undefined4 uVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 uVar7;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  uint uVar8;
  uint uVar9;
  undefined2 uVar10;
  uint uStack_8;
  byte bStack_5;
  byte bStack_3;
  undefined2 uVar11;
  
  for (uStack_8 = 0; (int)uStack_8 < (int)(uint)*(byte *)((uint)param_1 * 0x27 + 0x11b);
      uStack_8 = uStack_8 + 1) {
    iVar6 = OVC23_55fe_2937(param_2 + uStack_8,param_3);
    if (-1 < iVar6) {
      OVC23_55fe_1803(iVar6);
    }
  }
  cVar4 = OVC23_55fe_0a56(param_2,param_3);
  if (cVar4 != '\0') {
    OVC23_55fe_1005(param_2 + -1,param_3,0,param_5);
    cVar4 = ovr_OVC22_5087_503d(CONCAT11(extraout_AH,(char)param_2 + -1),
                                CONCAT11(extraout_AH,(undefined1)param_3));
    if (cVar4 != '\0') {
      *param_4 = 1;
    }
  }
  for (uStack_8 = 1; (int)uStack_8 < (int)(uint)*(byte *)((uint)param_1 * 0x27 + 0x11b);
      uStack_8 = uStack_8 + 1) {
    OVC23_55fe_1005(param_2 + uStack_8,param_3,0,param_5);
    cVar4 = ovr_OVC22_5087_503d(CONCAT11(extraout_AH_00,(char)param_2 + (char)uStack_8),
                                CONCAT11(extraout_AH_00,(undefined1)param_3));
    if (cVar4 != '\0') {
      *param_4 = 1;
    }
  }
  uVar3 = *(undefined4 *)((uint)param_5 << 2);
  if (*(char *)((int)uVar3 + 0x3f) == '\0') {
    if (0x31 < DAT_2000_d2df) {
      uVar8 = 0;
      uVar9 = 0xffff;
      for (uStack_8 = 0; uStack_8 < DAT_2000_d2df; uStack_8 = uStack_8 + 1) {
        cVar4 = ovr_OVC22_5087_503d(CONCAT11((char)(uStack_8 * 0x12 >> 8),
                                             *(undefined1 *)(uStack_8 * 0x12 + 2)),
                                    CONCAT11((char)(uStack_8 * 0x12 >> 8),
                                             *(undefined1 *)(uStack_8 * 0x12 + 4)));
        if ((cVar4 == '\0') && (uVar8 <= (uint)(DAT_2000_d167 - *(int *)(uStack_8 * 0x12 + 0xf)))) {
          uVar8 = DAT_2000_d167 - *(int *)(uStack_8 * 0x12 + 0xf);
          uVar9 = uStack_8;
        }
      }
      if (uVar9 == 0xffff) {
        for (uStack_8 = 0; uStack_8 < DAT_2000_d2df; uStack_8 = uStack_8 + 1) {
          if (uVar8 <= (uint)(DAT_2000_d167 - *(int *)(uStack_8 * 0x12 + 0xf))) {
            uVar8 = DAT_2000_d167 - *(int *)(uStack_8 * 0x12 + 0xf);
            uVar9 = uStack_8;
          }
        }
      }
      if (uVar9 == 0xffff) {
        return;
      }
      if (uVar9 + 1 < DAT_2000_d2df) {
        _fmemmove((uint8_t *)(uVar9 * 0x12),(uint8_t *)(uVar9 * 0x12 + 0x12),
                  ((DAT_2000_d2df - uVar9) + -1) * 0x12);
      }
      DAT_2000_d2df = DAT_2000_d2df - 1;
    }
    _fmemset((void *)CONCAT22((char *)"manned n/s wall" + 0xd,(void *)(DAT_2000_d2df * 0x12)),0,0x12
            );
    *(byte *)(DAT_2000_d2df * 0x12 + 8) = param_1;
    *(int *)(DAT_2000_d2df * 0x12 + 2) = param_2;
    *(int *)(DAT_2000_d2df * 0x12 + 4) = param_3;
    *(byte *)(DAT_2000_d2df * 0x12 + 9) = param_5;
    cVar4 = OVC23_55fe_0a56(param_2,param_3);
    uVar10 = (undefined2)((ulong)DAT_2000_cb0d >> 0x10);
    uVar11 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
    if (cVar4 == '\0') {
      bStack_5 = *(byte *)((int)DAT_2000_ca95 +
                          *(int *)((int)DAT_2000_cb0d + param_2 * 0x78 + param_3 * 2) * 9);
    }
    else {
      bStack_5 = *(byte *)((int)DAT_2000_ca95 +
                          *(int *)((int)DAT_2000_cb0d + (param_2 + -1) * 0x78 + param_3 * 2) * 9);
    }
    bStack_3 = *(byte *)((uint)bStack_5 * 0x27 + 0x11d);
    uVar7 = *(undefined1 *)((uint)bStack_5 * 0x27 + 0x11b);
    if (bStack_3 == 0) {
      bStack_3 = 1;
    }
    if (bStack_3 < *(byte *)((uint)param_1 * 0x27 + 0x11c)) {
      *(undefined1 *)(DAT_2000_d2df * 0x12 + 6) = *(undefined1 *)((uint)param_1 * 0x27 + 0x11c);
    }
    else {
      *(byte *)(DAT_2000_d2df * 0x12 + 6) = bStack_3;
    }
    *(int *)(DAT_2000_d2df * 0x12 + 0xf) = DAT_2000_d167;
    *(undefined2 *)(DAT_2000_d2df * 0x12) = 0;
    uVar5 = OVC23_55fe_2f90();
    *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xc) = uVar5;
    if (*(char *)(DAT_2000_d2df * 0x12 + 0xc) == '\0') {
      *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xc) = 1;
    }
    if (param_1 == 0) {
      cVar4 = OVC23_55fe_0a56(param_2,param_3);
      if (cVar4 != '\0') {
        piVar1 = (int *)(DAT_2000_d2df * 0x12 + 2);
        *piVar1 = *piVar1 + -1;
      }
      *(undefined1 *)(DAT_2000_d2df * 0x12 + 7) = uVar7;
      if (param_6 == '\x01') {
        *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xe) = 1;
      }
      else {
        *(char *)(DAT_2000_d2df * 0x12 + 0xc) = param_6;
        *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xe) = 0;
      }
      pbVar2 = (byte *)(DAT_2000_d2df * 0x12 + 0xd);
      *pbVar2 = *pbVar2 | 3;
    }
    else {
      *(undefined1 *)(DAT_2000_d2df * 0x12 + 7) = *(undefined1 *)((uint)param_1 * 0x27 + 0x11b);
      if (param_6 != '\0') {
        OVC23_55fe_1005(param_2,param_3,0,CONCAT11((char)((uint)param_1 * 0x27 >> 8),param_5));
        cVar4 = ovr_OVC22_5087_503d(CONCAT11(extraout_AH_02,(char)param_2),
                                    CONCAT11(extraout_AH_02,(undefined1)param_3));
        if (cVar4 != '\0') {
          *param_4 = 1;
        }
      }
      *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xe) = 0;
    }
    *(undefined1 *)(DAT_2000_d2df * 0x12 + 0x11) = 0;
    *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xb) = *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xc);
    uVar9 = DAT_2000_d2df;
    DAT_2000_d2df = DAT_2000_d2df + 1;
    OVC23_55fe_29a2(uVar9);
    OVC23_55fe_0000();
  }
  else {
    uVar7 = (undefined1)(((uint)param_5 << 2) >> 8);
    OVC23_55fe_1005(param_2,param_3,CONCAT11(uVar7,param_1),CONCAT11(uVar7,param_5));
    cVar4 = ovr_OVC22_5087_503d(CONCAT11(extraout_AH_01,(char)param_2),
                                CONCAT11(extraout_AH_01,(undefined1)param_3));
    if (cVar4 != '\0') {
      *param_4 = 1;
    }
  }
  return;
}



/* 55fe:1e87 */

void __cdecl16far
OVC23_55fe_1e87(undefined1 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 param_5,undefined1 param_6)

{
  OVC23_55fe_184e(param_1,param_2,param_3,param_4,param_5,param_6,1);
  return;
}



/* 55fe:1ea9 */

void __cdecl16far
OVC23_55fe_1ea9(int param_1,int param_2,int param_3,brect_t *param_4,undefined2 param_5)

{
  int y;
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int x;
  uint uVar4;
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
  uint uStack_10;
  uint uStack_e;
  int iStack_c;
  uint16_t uStack_a;
  uint16_t uStack_8;
  
  uStack_10 = (uint)*(byte *)(param_3 * 0x12 + 6);
  uVar3 = *(uint *)(param_3 * 0x12);
  bVar1 = *(byte *)(param_3 * 0x12 + 0xe);
  bVar2 = *(byte *)(param_3 * 0x12 + 0x11);
  if (bVar2 < uStack_10) {
    uStack_10 = bVar2 + 1;
  }
  x = param_1 + -1;
  iStack_c = param_2 + uStack_10 * -0x26 + -0x32;
  uStack_e = uStack_10;
  while (uStack_e = uStack_e - 1, -1 < (int)uStack_e) {
    y = iStack_c + 0x26;
    if ((bVar1 == 2) || (0x13 < uVar3)) {
      if (bVar1 < 2) {
        if ((uStack_e == 0) && ((uVar3 - x & 0x3f) < 0x20)) {
          uVar4 = uVar3 - x & 0x3f;
          uStack_8 = ((undefined2 *)&DAT_2000_cb2b)[uVar4 * 2];
          uStack_a = ((undefined2 *)&DAT_2000_cb29)[uVar4 * 2];
        }
        else {
          uStack_8 = DAT_2000_cbe3;
          uStack_a = DAT_2000_cbe1;
        }
        if (uStack_e == 0) {
          uVar4 = (uVar3 + GfxRndSeed2) % 0xe;
          gfx_01.seg = ((undefined2 *)&DAT_2000_d2a0)[uVar4 * 2];
          gfx_01.ofs = ((undefined2 *)&DAT_2000_d29e)[uVar4 * 2];
          ovr_blitGfxRect(gfx_01,param_1 + 0xe,iStack_c + 0x8b,(brect_t *)CONCAT22(param_5,param_4),
                          0x10,true);
        }
        gfx_02.seg = uStack_8;
        gfx_02.ofs = uStack_a;
        ovr_blitGfxRect(gfx_02,x,y,(brect_t *)CONCAT22(param_5,param_4),0x10,false);
        if ((uVar3 + uStack_e + GfxRndSeed2 + x & 0x1f) < 0x11) {
          uVar4 = uVar3 + uStack_e + GfxRndSeed2 + x & 0x1f;
          gfx_03.seg = ((undefined2 *)&DAT_2000_d25c)[uVar4 * 2];
          gfx_03.ofs = ((undefined2 *)&DAT_2000_d25a)[uVar4 * 2];
          ovr_blitGfxRect(gfx_03,x + ((uint)*(byte *)((uVar3 + uStack_e + GfxRndSeed2 + x >> 5) +
                                                      uStack_e + GfxRndSeed2 & 0xff) * 0x50) / 0x100
                          ,iStack_c + 0x66,(brect_t *)CONCAT22(param_5,param_4),0x10,false);
        }
        if ((((uVar3 + uStack_e) - GfxRndSeed2) - x & 0xf) < 7) {
          uVar4 = ((uVar3 + uStack_e) - GfxRndSeed2) - x & 0xf;
          gfx_04.seg = ((undefined2 *)&DAT_2000_d240)[uVar4 * 2];
          gfx_04.ofs = ((undefined2 *)&DAT_2000_d23e)[uVar4 * 2];
          ovr_blitGfxRect(gfx_04,x + ((uint)*(byte *)((((((uVar3 + uStack_e) - GfxRndSeed2) - x >> 4
                                                        ) + uStack_e) - GfxRndSeed2) + 0xe & 0xff) *
                                     0x50) / 0x100,iStack_c + 0x66,
                          (brect_t *)CONCAT22(param_5,param_4),0x10,false);
        }
        uVar4 = (uVar3 + 5) % 7;
        gfx_05.seg = ((undefined2 *)&DAT_2000_d224)[uVar4 * 2];
        gfx_05.ofs = ((undefined2 *)&DAT_2000_d222)[uVar4 * 2];
        ovr_blitGfxRect(gfx_05,param_1 + 9,iStack_c + 0x62,(brect_t *)CONCAT22(param_5,param_4),0x10
                        ,false);
        gfx_06.seg = ((undefined2 *)&DAT_2000_d224)[(uVar3 % 7) * 2];
        gfx_06.ofs = ((undefined2 *)&DAT_2000_d222)[(uVar3 % 7) * 2];
        ovr_blitGfxRect(gfx_06,param_1 + 0xd,iStack_c + 0x62,(brect_t *)CONCAT22(param_5,param_4),
                        0x10,false);
        uVar4 = (uVar3 + 2) % 7;
        gfx_07.seg = ((undefined2 *)&DAT_2000_d224)[uVar4 * 2];
        gfx_07.ofs = ((undefined2 *)&DAT_2000_d222)[uVar4 * 2];
        ovr_blitGfxRect(gfx_07,param_1 + 0x31,iStack_c + 0x62,(brect_t *)CONCAT22(param_5,param_4),
                        0x10,false);
        uVar4 = uVar3 + 3 & 7;
        gfx_08.seg = ((undefined2 *)&DAT_2000_d204)[uVar4 * 2];
        gfx_08.ofs = ((undefined2 *)&DAT_2000_d202)[uVar4 * 2];
        ovr_blitGfxRect(gfx_08,param_1 + 0x45,iStack_c + 0x62,(brect_t *)CONCAT22(param_5,param_4),
                        0x10,false);
        gfx_09.seg = ((undefined2 *)&DAT_2000_d204)[(uVar3 & 7) * 2];
        gfx_09.ofs = ((undefined2 *)&DAT_2000_d202)[(uVar3 & 7) * 2];
        ovr_blitGfxRect(gfx_09,param_1 + 0x3b,iStack_c + 0x62,(brect_t *)CONCAT22(param_5,param_4),
                        0x10,false);
        gfx_10.seg = ((undefined2 *)&DAT_2000_d1f0)[(uVar3 % 5) * 2];
        gfx_10.ofs = ((undefined2 *)&DAT_2000_d1ee)[(uVar3 % 5) * 2];
        ovr_blitGfxRect(gfx_10,param_1 + 0x27,iStack_c + 0x62,(brect_t *)CONCAT22(param_5,param_4),
                        0x10,false);
        gfx_11.seg = ((undefined2 *)&DAT_2000_d1f0)[(uVar3 % 5) * 2];
        gfx_11.ofs = ((undefined2 *)&DAT_2000_d1ee)[(uVar3 % 5) * 2];
        ovr_blitGfxRect(gfx_11,param_1 + 0x3f,iStack_c + 0x62,(brect_t *)CONCAT22(param_5,param_4),
                        0x10,false);
        iStack_c = y;
      }
      else {
        if (uVar3 < 9) {
          uStack_8 = ((undefined2 *)&DAT_2000_cbab)[(uVar3 + 0xe) * 2];
          uStack_a = ((undefined2 *)&DAT_2000_cba9)[(uVar3 + 0xe) * 2];
        }
        else {
          uStack_8 = DAT_2000_cc07;
          uStack_a = DAT_2000_cc05;
        }
        gfx_00.seg = uStack_8;
        gfx_00.ofs = uStack_a;
        ovr_blitGfxRect(gfx_00,x,y,(brect_t *)CONCAT22(param_5,param_4),0x10,false);
        iStack_c = y;
      }
    }
    else {
      if ((uStack_10 - 1 == uStack_e) && (uVar3 < 0xf)) {
        uStack_8 = ((undefined2 *)&DAT_2000_cbab)[uVar3 * 2];
        uStack_a = ((undefined2 *)&DAT_2000_cba9)[uVar3 * 2];
      }
      else {
        uStack_8 = DAT_2000_cbe3;
        uStack_a = DAT_2000_cbe1;
      }
      gfx.seg = uStack_8;
      gfx.ofs = uStack_a;
      ovr_blitGfxRect(gfx,x,y,(brect_t *)CONCAT22(param_5,param_4),0x10,false);
      iStack_c = y;
    }
  }
  return;
}



/* 55fe:23d8 */

void __cdecl16far
OVC23_55fe_23d8(int param_1,int param_2,int param_3,brect_t *param_4,undefined2 param_5)

{
  int y;
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  int x;
  uint uVar6;
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
  uint uStack_12;
  uint uStack_c;
  int iStack_a;
  uint16_t uStack_8;
  uint16_t uStack_6;
  
  bVar1 = *(byte *)(param_3 * 0x12 + 7);
  if (bVar1 < 2) {
    uStack_12 = (uint)*(byte *)(param_3 * 0x12 + 6);
    uVar3 = *(uint *)(param_3 * 0x12);
    bVar1 = *(byte *)(param_3 * 0x12 + 0xe);
    bVar2 = *(byte *)(param_3 * 0x12 + 0x11);
    if (bVar2 < uStack_12) {
      uStack_12 = bVar2 + 1;
    }
    x = param_1 + -1;
    iStack_a = param_2 + uStack_12 * -0x13 + 0x2a;
    uStack_c = uStack_12;
    while (uVar5 = DAT_2000_cc3b, uVar4 = DAT_2000_cc39, uStack_c = uStack_c - 1, -1 < (int)uStack_c
          ) {
      y = iStack_a + 0x13;
      if ((bVar1 == 2) || (0x13 < uVar3)) {
        if (bVar1 < 2) {
          if (uStack_c == 0) {
            uVar6 = (uVar3 + GfxRndSeed2) % 0xe;
            gfx_01.seg = ((undefined2 *)&DAT_2000_d2a0)[uVar6 * 2];
            gfx_01.ofs = ((undefined2 *)&DAT_2000_d29e)[uVar6 * 2];
            ovr_blitGfxRect(gfx_01,param_1 + 0xe,iStack_a + 0x22,
                            (brect_t *)CONCAT22(param_5,param_4),0x10,true);
          }
          gfx_02.seg = uVar5;
          gfx_02.ofs = uVar4;
          ovr_blitGfxRect(gfx_02,x,y,(brect_t *)CONCAT22(param_5,param_4),0x10,false);
          if ((uVar3 + uStack_c + GfxRndSeed2 + x & 0x1f) < 0x11) {
            uVar6 = uVar3 + uStack_c + GfxRndSeed2 + x & 0x1f;
            gfx_03.seg = ((undefined2 *)&DAT_2000_d25c)[uVar6 * 2];
            gfx_03.ofs = ((undefined2 *)&DAT_2000_d25a)[uVar6 * 2];
            ovr_blitGfxRect(gfx_03,x + ((int)((uint)*(byte *)((uVar3 + uStack_c + GfxRndSeed2 + x >>
                                                              5) + uStack_c + GfxRndSeed2 & 0xff) *
                                             0x25) >> 8) + 3,iStack_a + 0x10,
                            (brect_t *)CONCAT22(param_5,param_4),0x10,false);
          }
          if ((((uVar3 + uStack_c) - GfxRndSeed2) - x & 0xf) < 7) {
            uVar6 = ((uVar3 + uStack_c) - GfxRndSeed2) - x & 0xf;
            gfx_04.seg = ((undefined2 *)&DAT_2000_d240)[uVar6 * 2];
            gfx_04.ofs = ((undefined2 *)&DAT_2000_d23e)[uVar6 * 2];
            ovr_blitGfxRect(gfx_04,x + ((int)((uint)*(byte *)((((((uVar3 + uStack_c) - GfxRndSeed2)
                                                                 - x >> 4) + uStack_c) - GfxRndSeed2
                                                              ) + 0xe & 0xff) * 0x25) >> 8) + 3,
                            iStack_a + 0x10,(brect_t *)CONCAT22(param_5,param_4),0x10,false);
          }
          uVar6 = (uVar3 + 5) % 7;
          gfx_05.seg = ((undefined2 *)&DAT_2000_d224)[uVar6 * 2];
          gfx_05.ofs = ((undefined2 *)&DAT_2000_d222)[uVar6 * 2];
          ovr_blitGfxRect(gfx_05,param_1 + 4,iStack_a + 0xd,(brect_t *)CONCAT22(param_5,param_4),
                          0x10,false);
          gfx_06.seg = ((undefined2 *)&DAT_2000_d224)[(uVar3 % 7) * 2];
          gfx_06.ofs = ((undefined2 *)&DAT_2000_d222)[(uVar3 % 7) * 2];
          ovr_blitGfxRect(gfx_06,param_1 + 6,iStack_a + 0xd,(brect_t *)CONCAT22(param_5,param_4),
                          0x10,false);
          uVar6 = (uVar3 + 2) % 7;
          gfx_07.seg = ((undefined2 *)&DAT_2000_d224)[uVar6 * 2];
          gfx_07.ofs = ((undefined2 *)&DAT_2000_d222)[uVar6 * 2];
          ovr_blitGfxRect(gfx_07,param_1 + 0x18,iStack_a + 0xd,(brect_t *)CONCAT22(param_5,param_4),
                          0x10,false);
          uVar6 = uVar3 + 3 & 7;
          gfx_08.seg = ((undefined2 *)&DAT_2000_d204)[uVar6 * 2];
          gfx_08.ofs = ((undefined2 *)&DAT_2000_d202)[uVar6 * 2];
          ovr_blitGfxRect(gfx_08,param_1 + 0x22,iStack_a + 0xd,(brect_t *)CONCAT22(param_5,param_4),
                          0x10,false);
          gfx_09.seg = ((undefined2 *)&DAT_2000_d204)[(uVar3 & 7) * 2];
          gfx_09.ofs = ((undefined2 *)&DAT_2000_d202)[(uVar3 & 7) * 2];
          ovr_blitGfxRect(gfx_09,param_1 + 0x1d,iStack_a + 0xd,(brect_t *)CONCAT22(param_5,param_4),
                          0x10,false);
          gfx_10.seg = ((undefined2 *)&DAT_2000_d1f0)[(uVar3 % 5) * 2];
          gfx_10.ofs = ((undefined2 *)&DAT_2000_d1ee)[(uVar3 % 5) * 2];
          ovr_blitGfxRect(gfx_10,param_1 + 0x13,iStack_a + 0xd,(brect_t *)CONCAT22(param_5,param_4),
                          0x10,false);
          gfx_11.seg = ((undefined2 *)&DAT_2000_d1f0)[(uVar3 % 5) * 2];
          gfx_11.ofs = ((undefined2 *)&DAT_2000_d1ee)[(uVar3 % 5) * 2];
          ovr_blitGfxRect(gfx_11,param_1 + 0x1f,iStack_a + 0xd,(brect_t *)CONCAT22(param_5,param_4),
                          0x10,false);
          iStack_a = y;
        }
        else {
          if (uVar3 < 10) {
            uStack_6 = ((undefined2 *)&DAT_2000_cc0b)[(uVar3 + 0xc) * 2];
            uStack_8 = ((undefined2 *)&DAT_2000_cc09)[(uVar3 + 0xc) * 2];
          }
          else {
            uStack_6 = DAT_2000_cc63;
            uStack_8 = DAT_2000_cc61;
          }
          gfx_00.seg = uStack_6;
          gfx_00.ofs = uStack_8;
          ovr_blitGfxRect(gfx_00,x,y,(brect_t *)CONCAT22(param_5,param_4),0x10,false);
          iStack_a = y;
        }
      }
      else {
        if ((uStack_12 - 1 == uStack_c) && (uVar3 < 0xd)) {
          uStack_6 = ((undefined2 *)&DAT_2000_cc0b)[uVar3 * 2];
          uStack_8 = ((undefined2 *)&DAT_2000_cc09)[uVar3 * 2];
        }
        else {
          uStack_6 = DAT_2000_cc3b;
          uStack_8 = DAT_2000_cc39;
        }
        gfx.seg = uStack_6;
        gfx.ofs = uStack_8;
        ovr_blitGfxRect(gfx,x,y,(brect_t *)CONCAT22(param_5,param_4),0x10,false);
        iStack_a = y;
      }
    }
  }
  else {
    OVC23_55fe_1ea9(param_1,param_2 + 10,param_3,param_4,param_5);
    if (2 < bVar1) {
      OVC23_55fe_1ea9(param_1 + 0x5e,param_2 + 10,param_3,param_4,param_5);
    }
  }
  return;
}



/* 55fe:2937 */

uint __cdecl16far OVC23_55fe_2937(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (DAT_2000_d2df <= uVar2) {
      return 0xffff;
    }
    if (((*(int *)(uVar2 * 0x12 + 4) == param_2) &&
        (iVar1 = *(int *)(uVar2 * 0x12 + 2),
        param_1 <= (int)(iVar1 + (uint)*(byte *)(uVar2 * 0x12 + 7) + -1))) && (iVar1 <= param_1))
    break;
    uVar2 = uVar2 + 1;
  }
  return uVar2;
}



/* 55fe:29a2 */

void __cdecl16far OVC23_55fe_29a2(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  byte bStack_b;
  
  bVar2 = *(byte *)(param_1 * 0x12 + 9);
  if (*(char *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0x3f) == '\0') {
    iVar6 = ovr_OVC23_55fe_3450();
    iVar4 = *(int *)(param_1 * 0x12 + 4);
    bVar3 = *(byte *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0x3f);
    uVar7 = 0;
    for (bStack_b = 0; bStack_b < 4; bStack_b = bStack_b + 1) {
      uVar7 = uVar7 | *(uint *)((int)DAT_2000_cb09 + iVar4 * 0x128 + (iVar6 + (uint)bStack_b) * 2 +
                               -4) & 0x3000;
    }
    if ((((*(byte *)(param_1 * 0x12 + 0xd) & 3) == 1) &&
        (uVar7 == 0x1000 << ((*(byte *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0x3f) ^ 1) & 0x1f))
        ) && (cVar5 = ovr_OVC24_5943_1eeb(iVar6,iVar4), cVar5 == '\0')) {
      cVar5 = OVC23_55fe_05db(iVar6);
      if (cVar5 != '\0') {
        ovr_say("Construction abandoned.");
      }
      if (param_1 + 1U < DAT_2000_d2df) {
        _fmemmove((uint8_t *)(param_1 * 0x12),(uint8_t *)(param_1 * 0x12 + 0x12),
                  ((DAT_2000_d2df - param_1) + -1) * 0x12);
      }
      DAT_2000_d2df = DAT_2000_d2df - 1;
      OVC23_55fe_0000();
    }
    else if (((*(byte *)(param_1 * 0x12 + 0xd) & 1) == 0) &&
            ((0x1000 << (bVar3 & 0x1f) & uVar7) != 0)) {
      pbVar1 = (byte *)(param_1 * 0x12 + 0xd);
      *pbVar1 = *pbVar1 | 1;
    }
  }
  return;
}



/* 55fe:2b82 */

void __cdecl16far OVC23_55fe_2b82(void)

{
  int iVar1;
  
  iVar1 = DAT_2000_d2df;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    OVC23_55fe_29a2(iVar1);
  }
  return;
}



/* 55fe:2b9e */

undefined2 __cdecl16far OVC23_55fe_2b9e(int param_1,int param_2,byte param_3,undefined1 param_4)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  
  cVar1 = *(char *)((uint)param_3 * 0x27 + 0x11e);
  if (cVar1 == '\0') {
    uVar3 = 0;
  }
  else if (cVar1 == '\x01') {
    bVar2 = ovr_OVC45_77eb_0121(param_1,param_2 + -1);
    uVar4 = (undefined1)((uint)bVar2 * 0x27 >> 8);
    if (*(char *)((uint)bVar2 * 0x27 + 0x11e) == '\x02') {
      OVC23_55fe_1005(param_1,param_2,CONCAT11(uVar4,param_3 + 2),CONCAT11(uVar4,param_4));
    }
    else {
      OVC23_55fe_1005(param_1,param_2,CONCAT11(uVar4,param_3),CONCAT11(uVar4,param_4));
    }
    bVar2 = ovr_OVC45_77eb_0121(param_1 + -1,param_2);
    if (*(char *)((uint)bVar2 * 0x27 + 0x11e) == '\x02') {
      uVar4 = (undefined1)((uint)bVar2 * 0x27 >> 8);
      OVC23_55fe_1005(param_1 + -1,param_2,CONCAT11(uVar4,bVar2 + 1),CONCAT11(uVar4,param_4));
    }
    uVar3 = 1;
  }
  else if (cVar1 == '\x02') {
    bVar2 = ovr_OVC45_77eb_0121(param_1 + 1,param_2);
    uVar4 = (undefined1)((uint)bVar2 * 0x27 >> 8);
    if (*(char *)((uint)bVar2 * 0x27 + 0x11e) == '\x01') {
      OVC23_55fe_1005(param_1,param_2,CONCAT11(uVar4,param_3 + 1),CONCAT11(uVar4,param_4));
    }
    else {
      OVC23_55fe_1005(param_1,param_2,CONCAT11(uVar4,param_3),CONCAT11(uVar4,param_4));
    }
    bVar2 = ovr_OVC45_77eb_0121(param_1,param_2 + 1);
    if (*(char *)((uint)bVar2 * 0x27 + 0x11e) == '\x01') {
      uVar4 = (undefined1)((uint)bVar2 * 0x27 >> 8);
      OVC23_55fe_1005(param_1,param_2 + 1,CONCAT11(uVar4,bVar2 + 2),CONCAT11(uVar4,param_4));
    }
    uVar3 = 1;
  }
  else if (cVar1 == '!') {
    bVar2 = ovr_OVC45_77eb_0121(param_1 + -1,param_2);
    if (*(char *)((uint)bVar2 * 0x27 + 0x11e) == '\x02') {
      uVar4 = (undefined1)((uint)bVar2 * 0x27 >> 8);
      OVC23_55fe_1005(param_1 + -1,param_2,CONCAT11(uVar4,bVar2 + 1),CONCAT11(uVar4,param_4));
    }
    uVar3 = 0;
  }
  else if (cVar1 == '\"') {
    bVar2 = ovr_OVC45_77eb_0121(param_1,param_2 + 1);
    if (*(char *)((uint)bVar2 * 0x27 + 0x11e) == '\x01') {
      uVar4 = (undefined1)((uint)bVar2 * 0x27 >> 8);
      OVC23_55fe_1005(param_1,param_2 + 1,CONCAT11(uVar4,bVar2 + 2),CONCAT11(uVar4,param_4));
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* 55fe:2da3 */

int __cdecl16far OVC23_55fe_2da3(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*(uint *)(param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2 + 0x128) & 3) != 0) {
    iVar1 = ovr_OVC23_55fe_3450(param_1);
    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
      if ((*(uint *)(param_2 * 0x128 + (int)DAT_2000_cb09 + (iVar1 + iVar2) * 2 + 0x124) & 3) == 0)
      {
        return iVar1 + iVar2 + -2;
      }
    }
    param_1 = -1;
  }
  return param_1;
}



/* 55fe:2e2b */

int __cdecl16far OVC23_55fe_2e2b(int param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = OVC23_55fe_2da3(param_1,param_2);
  if (iVar1 < 0) {
    iVar1 = param_1;
  }
  return iVar1;
}



/* 55fe:2e4c */

void __cdecl16far OVC23_55fe_2e4c(int param_1,int param_2)

{
  uint *puVar1;
  char *arg1;
  int iVar2;
  char *msg;
  uint16_t dst;
  undefined1 local_a6 [80];
  char local_56 [80];
  int iStack_6;
  byte bStack_3;
  
  puVar1 = (uint *)(param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2 + 0x128);
  *puVar1 = *puVar1 | 3;
  iVar2 = EntityCount;
  while (iVar2 = iVar2 + -1, -1 < iVar2) {
    if ((*(int *)(Entities.ofs + iVar2 * 0x37) == param_1) &&
       (*(int *)(Entities.ofs + iVar2 * 0x37 + 2) == param_2)) {
      iStack_6 = OVC23_55fe_2da3();
      if (iStack_6 < 0) {
        bStack_3 = *(byte *)(Entities.ofs + iVar2 * 0x37 + 0xd);
        if (*(char *)((int)(char **)GMenuStrings + (uint)bStack_3 * 0x95 + 0x1f) == '\0') {
          dst = 0xa000;
          arg1 = (char *)ovr_OVC15_4207_1c79(local_a6);
          msg = ovr_stsprintf(local_56,"%s unit drowns.  (%d, %d)",arg1);
          ovr_uiNotify(msg,dst);
        }
        ovr_OVC15_4207_0e17(iVar2);
      }
      else {
        *(int *)(Entities.ofs + iVar2 * 0x37) = iStack_6;
      }
    }
  }
  return;
}



/* 55fe:2f90 */

undefined2 __cdecl16far OVC23_55fe_2f90(byte param_1,byte param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined2 unaff_SS;
  byte bStack_8;
  byte local_6;
  byte bStack_5;
  byte bStack_4;
  
  uVar3 = (uint)param_1;
  bStack_8 = param_1;
  _fmemset((byte *)CONCAT22(unaff_SS,&local_6),0,3);
  for (uVar5 = 0; uVar5 < DAT_2000_d2df; uVar5 = uVar5 + 1) {
    if (*(byte *)(uVar5 * 0x12 + 9) == param_2) {
      if ((*(byte *)(uVar5 * 0x12 + 0xd) & 4) != 0) {
        local_6 = local_6 + 1;
      }
      if ((*(byte *)(uVar5 * 0x12 + 0xd) & 8) != 0) {
        bStack_5 = bStack_5 + 1;
      }
      if ((*(byte *)(uVar5 * 0x12 + 0xd) & 0x10) != 0) {
        bStack_4 = bStack_4 + 1;
      }
    }
  }
  if (bStack_4 < *(byte *)((int)*(undefined4 *)((uint)param_2 << 2) + 0x9c)) {
    bStack_8 = (byte)((ulong)((long)(int)uVar3 * 7) / 10);
    iVar4 = param_3 * 0x12;
    *(byte *)(iVar4 + 0xd) = *(byte *)(iVar4 + 0xd) | 0x10;
  }
  else if (bStack_5 < *(byte *)((int)*(undefined4 *)((uint)param_2 << 2) + 0x9b)) {
    bStack_8 = (byte)((uVar3 << 3) / 100);
    iVar4 = param_3 * 0x12;
    *(byte *)(iVar4 + 0xd) = *(byte *)(iVar4 + 0xd) | 8;
  }
  else {
    uVar2 = *(undefined4 *)((uint)param_2 << 2);
    bVar1 = *(byte *)((int)uVar2 + 0x9a);
    iVar4 = CONCAT11((char)(((uint)param_2 << 2) >> 8),bVar1);
    if (local_6 < bVar1) {
      bStack_8 = (byte)((ulong)((long)(int)uVar3 * 9) / 10);
      iVar4 = param_3 * 0x12;
      *(byte *)(iVar4 + 0xd) = *(byte *)(iVar4 + 0xd) | 4;
    }
  }
  return CONCAT11((char)((uint)iVar4 >> 8),bStack_8);
}



/* 55fe:3450 */

uint __cdecl16far OVC23_55fe_3450(int param_1)

{
  return param_1 + 2U & 0xfffc;
}


