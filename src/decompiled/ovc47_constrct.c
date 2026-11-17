/*
 * ovc47_constrct.c - recovered from STRONG.EXE
 * memory block: OVC47_constrct.c
 * range: 7e7c:0000 - 7e7c:33cf
 * functions: 6
 */
#include "recovered.h"


/* 7e7c:0000 */

void __cdecl16far constrct_7e7c_0000(void)

{
  int iVar1;
  char local_4;
  byte bStack_3;
  
  local_4 = '\0';
  for (bStack_3 = 0; bStack_3 < DAT_2000_d1e6; bStack_3 = bStack_3 + 1) {
    for (iVar1 = 0; iVar1 < 10; iVar1 = iVar1 + 1) {
      ovr_OVC22_5087_4975(CONCAT11((char)((uint)&local_4 >> 8),bStack_3),&local_4);
    }
  }
  if (local_4 != '\0') {
    ovr_constr_36ce_1db4();
  }
  return;
}



/* 7e7c:004b */

void __cdecl16far land_info(byte param_1)

{
  undefined1 uVar1;
  char cVar2;
  uint uVar3;
  uint16_t uVar4;
  undefined2 *puVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  undefined2 uVar12;
  undefined2 unaff_SS;
  int16_t type;
  undefined1 local_2ee [80];
  undefined1 local_29e [80];
  char *local_24e [20];
  char local_226 [513];
  char cStack_25;
  undefined1 uStack_24;
  char cStack_23;
  char local_22;
  byte bStack_21;
  int local_20;
  char local_1e;
  byte bStack_1d;
  char cStack_1c;
  byte bStack_1b;
  int local_1a;
  uint16_t local_18;
  undefined2 uStack_16;
  undefined1 auStack_14 [10];
  char *local_a;
  char *pcStack_8;
  char *pcStack_6;
  char *pcStack_4;
  
  uStack_16 = far_t_2410_78e4.seg;
  local_18 = far_t_2410_78e4.ofs;
  ovr_attact_3f0b_0685();
  DAT_2000_ca71 = GMenuItem;
  local_1e = '\0';
  ovr_OVC18_48ac_0027();
  if ('\x02' < (char)param_1) {
    param_1 = 3;
  }
  if ((char)param_1 < '\0') {
    param_1 = 0;
  }
  bStack_21 = 0xff;
  uStack_24 = 0xff;
  local_1a = GfxRndSeed + (char)param_1 + -2;
  bStack_1d = ovr_OVC45_77eb_20e8(&local_1a);
  uVar3 = ovr_OVC45_77eb_0179(local_1a,GfxRndSeed2);
  uVar12 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
  if (*(char *)((int)DAT_2000_ca95 + uVar3 * 9 + 2) != -1) {
    uStack_24 = *(undefined1 *)((int)DAT_2000_ca95 + uVar3 * 9 + 2);
  }
  if (*(int *)((char)param_1 * 2 + -0x6e29) != -1) {
    if (*(char *)(*(int *)((char)param_1 * 2 + -0x6e29) * 0x12 + 0xc) == '\0') {
      *(undefined1 *)(*(int *)((char)param_1 * 2 + -0x6e29) * 0x12 + 0xc) = 1;
    }
    bStack_21 = param_1;
    uStack_24 = *(undefined1 *)(*(int *)((uint)param_1 * 2 + -0x6e29) * 0x12 + 9);
  }
  if (((*(uint *)((uint)bStack_1d * 0x27 + 0x121) & 0x80) == 0) &&
     (*(byte *)((int)DAT_2000_ca95 + uVar3 * 9 + 1) < 3)) {
    type = 0;
    uVar4 = ovr_randBelow(2);
    ovr_play_sfx(CONCAT11((char)(uVar4 >> 8),(char)uVar4 + '?'),type);
  }
  cStack_1c = ovr_OVC45_77eb_02c1(GfxRndSeed,GfxRndSeed2,&local_20);
  if (cStack_1c == -1) {
    ovr_OVC41_6a8f_1520();
  }
  else {
    if (cStack_1c == '\0') {
      if (bStack_21 == 0xff) {
        uVar12 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
        iVar11 = (int)DAT_2000_ca95;
        if (*(char *)(iVar11 + uVar3 * 9 + 2) == -1) {
          if (bStack_1d == 0) {
            cStack_25 = ovr_OVC45_77eb_215a(local_1a,GfxRndSeed2);
          }
          else {
            cStack_25 = '\0';
          }
          if (cStack_25 == '\x02') {
            strcpy(local_226,(char *)"Water:");
          }
          else if (cStack_25 == '\x01') {
            strcpy(local_226,(char *)"Shore:");
          }
          else {
            pcVar8 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e),
                                                 *(undefined2 *)((uint)bStack_1d * 0x27 + 0x110));
            pcVar8 = ovr_fmVsprintf((char *)"%s:",pcVar8);
            strcpy(local_226,pcVar8);
          }
        }
        else if (*(char *)((uint)bStack_1d * 0x27 + 0x130) == 'd') {
          puVar5 = (undefined2 *)((uint)*(byte *)(iVar11 + uVar3 * 9 + 2) * 4);
          pcVar8 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e),
                                               *(undefined2 *)((uint)bStack_1d * 0x27 + 0x110),
                                               *puVar5,puVar5[1]);
          pcVar8 = ovr_fmVsprintf((char *)"%s: Held by %s.",pcVar8);
          strcpy(local_226,pcVar8);
        }
        else {
          puVar5 = (undefined2 *)((uint)*(byte *)(iVar11 + uVar3 * 9 + 2) * 4);
          uVar1 = ovr_OVC45_77eb_21d3(CONCAT11((char)(uVar3 * 9 >> 8),
                                               *(undefined1 *)(iVar11 + uVar3 * 9 + 1)),
                                      CONCAT11((char)((uint)bStack_1d * 0x27 >> 8),
                                               *(undefined1 *)((uint)bStack_1d * 0x27 + 0x130)),
                                      *(undefined1 *)((uint)bStack_1d * 0x27 + 0x130),*puVar5,
                                      puVar5[1]);
          pcVar8 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e),
                                               *(undefined2 *)((uint)bStack_1d * 0x27 + 0x110),uVar1
                                              );
          pcVar8 = ovr_fmVsprintf((char *)"%s (%u/%u): Held by %s.",pcVar8);
          strcpy(local_226,pcVar8);
          cVar2 = func_0x0007164e(0x1000,uVar3);
          if (cVar2 != '\0') {
            strcat(local_226,(char *)" Home a unit here to halt damage.");
          }
        }
      }
      else {
        bStack_1d = *(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 8);
        pcVar8 = (char *)"halfling castle" + 0xc;
        uVar12 = ovr_OVC45_77eb_226e(local_29e);
        pcVar8 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e),
                                             *(undefined2 *)((uint)bStack_1d * 0x27 + 0x110),
                                             100 - ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 +
                                                                            -0x6e29) * 0x12 + 0xb) *
                                                   100) / (uint)*(byte *)(*(int *)((uint)bStack_21 *
                                                                                   2 + -0x6e29) *
                                                                          0x12 + 0xc),uVar12,pcVar8)
        ;
        pcVar8 = ovr_fmVsprintf((char *)"%s: %d%% complete. Owned by %s.",pcVar8);
        strcpy(local_226,pcVar8);
      }
      bStack_1b = ovr_OVC28_6018_1527(&local_18);
    }
    else if (bStack_21 == 0xff) {
      if (((*(uint *)((uint)bStack_1d * 0x27 + 0x121) & 2) == 0) || (0xf7 < uVar3)) {
        if (((*(uint *)((uint)bStack_1d * 0x27 + 0x121) & 0x20) == 0) || (0xf7 < uVar3)) {
          if (bStack_1d == 0) {
            ovr_OVC45_77eb_0d61(GfxRndSeed + (char)param_1 + -2,GfxRndSeed2,local_20,cStack_1c,
                                local_22);
          }
          else {
            constrct_7e7c_0b9c((char *)"trade faire" + 8,
                               CONCAT11((char)((uint)&local_1e >> 8),param_1),&local_1e);
          }
        }
        else {
          uVar1 = (undefined1)((uint)&local_1e >> 8);
          ovr_OVC45_77eb_1bb3(CONCAT11(uVar1,local_22),CONCAT11(uVar1,bStack_1d),local_20,local_1a,
                              &local_1e);
        }
      }
      else {
        uVar1 = (undefined1)((uint)&local_1e >> 8);
        ovr_OVC45_77eb_1754(CONCAT11(uVar1,local_22),CONCAT11(uVar1,bStack_1d),local_20,local_1a,
                            &local_1e);
      }
    }
    else {
      bStack_1d = *(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 8);
      if (bStack_1d != 0) {
        local_24e[1] = (char *)"puppetmaker" + 3;
        local_24e[0] = (char *)"Suspend";
        auStack_14[0] = 1;
      }
      uVar3 = (uint)(bStack_1d != 0);
      if (local_22 != '\0') {
        local_24e[uVar3 * 2 + 1] = (char *)"puppetmaker" + 3;
        local_24e[uVar3 * 2] = (char *)"Change party";
        auStack_14[uVar3] = 2;
        uVar3 = uVar3 + 1;
      }
      local_24e[uVar3 * 2 + 1] = (char *)"puppetmaker" + 3;
      local_24e[uVar3 * 2] = (char *)"Done";
      auStack_14[uVar3] = 3;
      cStack_23 = '\0';
      do {
        if (bStack_1d == 0) {
          ovr_OVC22_5087_0119(CONCAT11((char)((uint)(local_20 * 0x37) >> 8),
                                       *(undefined1 *)(Entities.ofs + local_20 * 0x37 + 0x1a)));
          ovr_OVC45_77eb_226e(local_2ee);
          ovr_OVC45_77eb_226e(local_29e);
          pcVar8 = ovr_fmVsprintf((char *)
                                  "Clearing of land: %d%% complete. Owned by %s. Active party is %s the %s."
                                  ,(char *)(100 - ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 +
                                                                           -0x6e29) * 0x12 + 0xb) *
                                                  100) / (uint)*(byte *)(*(int *)((uint)bStack_21 *
                                                                                  2 + -0x6e29) *
                                                                         0x12 + 0xc)));
          strcpy(local_226,pcVar8);
        }
        else {
          pcVar8 = (char *)"puppetmaker" + 3;
          uVar12 = ovr_OVC22_5087_0119(CONCAT11((char)((uint)(local_20 * 0x37) >> 8),
                                                *(undefined1 *)
                                                 (Entities.ofs + local_20 * 0x37 + 0x1a)));
          pcVar9 = (char *)"halfling castle" + 0xc;
          uVar6 = ovr_OVC45_77eb_226e(local_2ee);
          pcVar10 = (char *)"halfling castle" + 0xc;
          uVar7 = ovr_OVC45_77eb_226e(local_29e);
          pcVar8 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e),
                                               *(undefined2 *)((uint)bStack_1d * 0x27 + 0x110),
                                               100 - ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 +
                                                                              -0x6e29) * 0x12 + 0xb)
                                                     * 100) / (uint)*(byte *)(*(int *)((uint)
                                                  bStack_21 * 2 + -0x6e29) * 0x12 + 0xc),uVar7,
                                               pcVar10,uVar6,pcVar9,uVar12,pcVar8);
          pcVar8 = ovr_fmVsprintf((char *)
                                  "%s: %d%% complete. Owned by %s. Active party is %s the %s.",
                                  pcVar8);
          strcpy(local_226,pcVar8);
        }
        DAT_2410_5cef = *(undefined1 *)(Entities.ofs + local_20 * 0x37 + 0x1a);
        bStack_1b = ovr_OVC28_6018_1527(local_24e);
        DAT_2410_5cef = 0xff;
        if (bStack_1b != 0) {
          bStack_1b = auStack_14[bStack_1b - 1];
        }
        if (bStack_1b == 1) {
          pcStack_8 = local_24e[1];
          local_a = local_24e[0];
          pcStack_4 = (char *)"puppetmaker" + 3;
          pcStack_6 = (char *)"No";
          pcVar8 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e),
                                               *(undefined2 *)((uint)bStack_1d * 0x27 + 0x110));
          ovr_fmVsprintf((char *)"Construction of %s will be permanently suspended. Are you sure?",
                         pcVar8);
          bStack_1b = ovr_OVC28_6018_1527(&local_a);
          if (bStack_1b == 1) {
            ovr_OVC23_55fe_1803(*(undefined2 *)((uint)bStack_21 * 2 + -0x6e29));
          }
          cStack_23 = '\x01';
        }
        else if (bStack_1b == 2) {
          cStack_1c = ovr_OVC45_77eb_04d8(GfxRndSeed + (char)param_1 + -2,GfxRndSeed2,&local_20);
          if (cStack_1c == -1) {
            cStack_23 = '\x01';
          }
        }
        else if ((bStack_1b == 3) || (bStack_1b == 0)) {
          cStack_23 = '\x01';
        }
      } while (cStack_23 == '\0');
    }
    if (local_1e != '\0') {
      ovr_constr_36ce_1db4();
    }
    ovr_OVC28_6018_0251();
    ovr_OVC41_6a8f_1520();
  }
  return;
}



/* 7e7c:0b40 */

int __cdecl16far constrct_7e7c_0b40(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = ovr_manage_4d05_1b1d();
  if (bVar1 == 0xff) {
    iVar2 = 0;
  }
  else if (*(byte *)((int)*(undefined4 *)((uint)bVar1 << 2) + 0x86) < 5) {
    iVar2 = 0x14;
  }
  else {
    iVar2 = (uint)*(byte *)((int)*(undefined4 *)((uint)bVar1 << 2) + 0x86) * 4 + 0x14;
  }
  return iVar2;
}



/* 7e7c:0b9c */
/* recovered by relaxed-limit retry */
/* constrct_7e7c_0b9c @ 7e7c:0b9c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00085000) overlaps instruction at (ram,0x00084ffe)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far
constrct_7e7c_0b9c(bool param_1,undefined2 param_2,undefined2 param_3,int param_4,undefined2 param_5
                  ,undefined2 param_6,char param_7)

{
  int *piVar1;
  char *pcVar2;
  uint *puVar3;
  bool bVar4;
  far_t pixels;
  far_t buf;
  far_t hndl;
  far_t gfx;
  undefined1 uVar5;
  int iVar8;
  int iVar9;
  byte bVar6;
  char cVar7;
  undefined2 uVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  undefined2 *puVar14;
  uint16_t uVar15;
  undefined2 unaff_SI;
  int iVar16;
  uint unaff_DI;
  uint16_t uVar17;
  undefined2 uVar18;
  undefined2 unaff_SS;
  undefined1 auVar19 [4];
  uint8_t *puVar20;
  cte_t *pcVar21;
  undefined4 uVar22;
  stg_tmp_t *psVar23;
  far_t fVar24;
  DW sz;
  far_t fVar25;
  far_t fVar26;
  far_t fVar27;
  far_t fVar28;
  far_t fVar29;
  far_t fVar30;
  far_t fVar31;
  far_t fVar32;
  far_t fVar33;
  far_t fVar34;
  far_t fVar35;
  far_t fVar36;
  far_t fVar37;
  uint32_t uVar38;
  far_t fVar39;
  far_t fVar40;
  far_t fVar41;
  far_t pixels_00;
  far_t pixels_01;
  far_t pixels_02;
  far_t pixels_03;
  far_t pixels_04;
  far_t pixels_05;
  far_t pixels_06;
  far_t pixels_07;
  far_t pixels_08;
  far_t pixels_09;
  far_t pixels_10;
  far_t pixels_11;
  far_t pixels_12;
  far_t pixels_13;
  far_t pixels_14;
  far_t pixels_15;
  far_t pixels_16;
  far_t pixels_17;
  far_t pixels_18;
  far_t pixels_19;
  far_t pixels_20;
  far_t pixels_21;
  far_t pixels_22;
  far_t pixels_23;
  far_t pixels_24;
  far_t pixels_25;
  far_t pixels_26;
  far_t pixels_27;
  far_t pixels_28;
  far_t pixels_29;
  far_t pixels_30;
  far_t pixels_31;
  far_t pixels_32;
  far_t pixels_33;
  far_t pixels_34;
  far_t pixels_35;
  far_t pixels_36;
  far_t pixels_37;
  far_t pixels_38;
  far_t pixels_39;
  far_t pixels_40;
  far_t pixels_41;
  far_t pixels_42;
  far_t pixels_43;
  far_t pixels_44;
  far_t pixels_45;
  far_t pixels_46;
  far_t pixels_47;
  far_t pixels_48;
  far_t pixels_49;
  far_t pixels_50;
  far_t pixels_51;
  far_t pixels_52;
  far_t pixels_53;
  far_t pixels_54;
  far_t pixels_55;
  far_t pixels_56;
  far_t pixels_57;
  far_t pixels_58;
  far_t pixels_59;
  far_t pixels_60;
  far_t pixels_61;
  far_t pixels_62;
  far_t pixels_63;
  far_t pixels_64;
  far_t pixels_65;
  far_t pixels_66;
  far_t pixels_67;
  far_t pixels_68;
  far_t pixels_69;
  far_t pixels_70;
  far_t pixels_71;
  far_t pixels_72;
  far_t pixels_73;
  far_t pixels_74;
  far_t pixels_75;
  far_t pixels_76;
  far_t pixels_77;
  far_t pixels_78;
  far_t pixels_79;
  far_t pixels_80;
  far_t pixels_81;
  far_t pixels_82;
  far_t pixels_83;
  far_t pixels_84;
  far_t pixels_85;
  far_t pixels_86;
  far_t pixels_87;
  far_t pixels_88;
  far_t pixels_89;
  far_t pixels_90;
  far_t pixels_91;
  far_t pixels_92;
  far_t pixels_93;
  far_t pixels_94;
  far_t pixels_95;
  far_t pixels_96;
  far_t pixels_97;
  far_t pixels_98;
  far_t pixels_99;
  far_t pixels_x00100;
  far_t pixels_x00101;
  far_t pixels_x00102;
  far_t pixels_x00103;
  far_t pixels_x00104;
  far_t pixels_x00105;
  far_t pixels_x00106;
  far_t pixels_x00107;
  far_t pixels_x00108;
  far_t pixels_x00109;
  far_t pixels_x00110;
  far_t pixels_x00111;
  far_t pixels_x00112;
  far_t pixels_x00113;
  far_t pixels_x00114;
  far_t pixels_x00115;
  far_t pixels_x00116;
  far_t pixels_x00117;
  far_t pixels_x00118;
  far_t pixels_x00119;
  far_t pixels_x00120;
  far_t pixels_x00121;
  far_t pixels_x00122;
  far_t pixels_x00123;
  far_t pixels_x00124;
  far_t pixels_x00125;
  far_t pixels_x00126;
  far_t pixels_x00127;
  far_t pixels_x00128;
  far_t pixels_x00129;
  far_t pixels_x00130;
  far_t pixels_x00131;
  far_t pixels_x00132;
  far_t pixels_x00133;
  far_t pixels_x00134;
  far_t pixels_x00135;
  far_t pixels_x00136;
  far_t pixels_x00137;
  far_t pixels_x00138;
  far_t pixels_x00139;
  far_t pixels_x00140;
  far_t pixels_x00141;
  far_t pixels_x00142;
  far_t pixels_x00143;
  far_t pixels_x00144;
  far_t pixels_x00145;
  far_t pixels_x00146;
  far_t pixels_x00147;
  far_t pixels_x00148;
  far_t pixels_x00149;
  far_t pixels_x00150;
  far_t pixels_x00151;
  far_t pixels_x00152;
  far_t pixels_x00153;
  far_t pixels_x00154;
  far_t pixels_x00155;
  far_t pixels_x00156;
  far_t pixels_x00157;
  far_t pixels_x00158;
  far_t pixels_x00159;
  far_t pixels_x00160;
  far_t pixels_x00161;
  far_t pixels_x00162;
  far_t pixels_x00163;
  far_t pixels_x00164;
  far_t pixels_x00165;
  far_t pixels_x00166;
  far_t pixels_x00167;
  far_t pixels_x00168;
  far_t pixels_x00169;
  far_t pixels_x00170;
  far_t pixels_x00171;
  far_t pixels_x00172;
  far_t pixels_x00173;
  far_t pixels_x00174;
  far_t pixels_x00175;
  far_t pixels_x00176;
  far_t pixels_x00177;
  far_t pixels_x00178;
  far_t pixels_x00179;
  far_t pixels_x00180;
  far_t pixels_x00181;
  far_t pixels_x00182;
  far_t pixels_x00183;
  far_t pixels_x00184;
  far_t pixels_x00185;
  far_t pixels_x00186;
  far_t pixels_x00187;
  far_t pixels_x00188;
  far_t pixels_x00189;
  far_t pixels_x00190;
  far_t pixels_x00191;
  far_t pixels_x00192;
  far_t pixels_x00193;
  far_t pixels_x00194;
  far_t pixels_x00195;
  far_t pixels_x00196;
  far_t pixels_x00197;
  far_t pixels_x00198;
  far_t pixels_x00199;
  far_t pixels_x00200;
  far_t pixels_x00201;
  far_t pixels_x00202;
  far_t pixels_x00203;
  far_t pixels_x00204;
  far_t pixels_x00205;
  far_t pixels_x00206;
  far_t pixels_x00207;
  far_t pixels_x00208;
  far_t pixels_x00209;
  far_t pixels_x00210;
  far_t pixels_x00211;
  far_t pixels_x00212;
  far_t pixels_x00213;
  far_t pixels_x00214;
  far_t pixels_x00215;
  far_t pixels_x00216;
  far_t pixels_x00217;
  far_t pixels_x00218;
  far_t pixels_x00219;
  far_t pixels_x00220;
  far_t pixels_x00221;
  far_t pixels_x00222;
  far_t pixels_x00223;
  far_t pixels_x00224;
  far_t pixels_x00225;
  far_t pixels_x00226;
  far_t pixels_x00227;
  far_t pixels_x00228;
  far_t pixels_x00229;
  far_t pixels_x00230;
  far_t pixels_x00231;
  far_t pixels_x00232;
  far_t pixels_x00233;
  far_t pixels_x00234;
  far_t pixels_x00235;
  far_t pixels_x00236;
  far_t pixels_x00237;
  far_t pixels_x00238;
  far_t pixels_x00239;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t src;
  far_t src_00;
  far_t src_01;
  far_t src_02;
  far_t src_03;
  far_t src_04;
  far_t src_05;
  far_t src_06;
  far_t src_07;
  far_t src_08;
  far_t src_09;
  far_t src_10;
  far_t src_11;
  far_t src_12;
  far_t src_13;
  far_t src_14;
  far_t src_15;
  far_t src_16;
  far_t src_17;
  far_t src_18;
  far_t src_19;
  far_t src_20;
  far_t src_21;
  far_t src_22;
  far_t src_23;
  far_t src_24;
  far_t src_25;
  far_t src_26;
  far_t src_27;
  far_t src_28;
  far_t src_29;
  far_t src_30;
  far_t src_31;
  far_t src_32;
  far_t src_33;
  far_t src_34;
  far_t src_35;
  far_t src_36;
  far_t src_37;
  far_t src_38;
  far_t src_39;
  far_t src_40;
  far_t src_41;
  far_t src_42;
  far_t src_43;
  far_t src_44;
  far_t src_45;
  far_t src_46;
  far_t src_47;
  far_t src_48;
  far_t src_49;
  far_t src_50;
  far_t src_51;
  far_t src_52;
  far_t src_53;
  far_t src_54;
  far_t src_55;
  far_t src_56;
  far_t src_57;
  far_t src_58;
  far_t src_59;
  far_t src_60;
  far_t src_61;
  far_t src_62;
  far_t src_63;
  far_t src_64;
  far_t src_65;
  far_t src_66;
  far_t src_67;
  far_t src_68;
  far_t src_69;
  far_t src_70;
  far_t src_71;
  far_t src_72;
  far_t src_73;
  far_t src_74;
  far_t src_75;
  far_t src_76;
  far_t src_77;
  far_t src_78;
  far_t src_79;
  far_t src_80;
  far_t src_81;
  far_t src_82;
  far_t src_83;
  far_t src_84;
  far_t src_85;
  far_t src_86;
  far_t src_87;
  far_t src_88;
  far_t src_89;
  far_t src_90;
  far_t src_91;
  far_t src_92;
  far_t src_93;
  far_t src_94;
  far_t src_95;
  far_t src_96;
  far_t src_97;
  far_t src_98;
  far_t src_99;
  far_t src_x00100;
  undefined1 uVar42;
  undefined1 uVar43;
  undefined1 uVar44;
  undefined1 uVar45;
  char *local_2f2 [20];
  char local_2ca [512];
  undefined1 local_ca [80];
  undefined1 local_7a [72];
  undefined1 auStack_32 [9];
  char cStack_29;
  int iStack_28;
  uint uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  byte bStack_1c;
  byte bStack_1b;
  uint uStack_1a;
  int iStack_18;
  undefined2 local_16;
  undefined1 auStack_14 [2];
  uint16_t uStack_12;
  undefined2 uStack_10;
  stg_tmp_t *psStack_e;
  undefined1 auStack_c [4];
  stg_tmp_t *psStack_8;
  far_t fStack_6;
  
  cStack_29 = '\0';
  local_16 = (GfxRndSeed + (uint)param_1) - 2;
  (*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) = ovr_OVC45_77eb_20e8((char)&local_16);
  uVar44 = 0xf1;
  uStack_26 = ovr_OVC45_77eb_0179((char)local_16,(char)GfxRndSeed2);
  uVar17 = Entities.seg;
  uVar15 = Entities.ofs;
  uVar5 = *(undefined1 *)(uVar15 + param_4 * 0x37 + 0x1a);
  uStack_22 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_22) + 1)),uVar5);
  iVar16 = (int)DAT_2000_ca95;
  uVar18 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
  uVar42 = (undefined1)unaff_SS;
  uVar43 = (undefined1)((uint)unaff_SS >> 8);
  if (cStack_29 == '\0') {
    uVar44 = 0x10;
    if (*(char *)(iVar16 + uStack_26 * 9 + 2) == -1) {
      uVar5 = ovr_OVC22_5087_0119(uVar5);
      uVar42 = 0x7a;
      uVar18 = ovr_OVC45_77eb_226e(local_7a);
      iVar16 = (uStack_22 >> 8) * 0x27;
      pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar16 + 0x10e),
                                            *(undefined2 *)(iVar16 + 0x110),uVar18,uVar42,uVar5,
                                            uVar44);
      pcVar11 = ovr_fmVsprintf((char *)"%s: Active party is %s the %s.",pcVar11);
      uVar44 = 0;
      strcpy(local_2ca,pcVar11);
    }
    else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x130) == 'd') {
      uVar44 = 0x10;
      uVar5 = ovr_OVC22_5087_0119(*(undefined1 *)(uVar15 + param_4 * 0x37 + 0x1a));
      uVar42 = 0x7a;
      uVar18 = ovr_OVC45_77eb_226e(local_ca);
      pcVar11 = (char *)"halfling castle" + 0xc;
      uVar10 = ovr_OVC45_77eb_226e(local_7a);
      iVar16 = (uStack_22 >> 8) * 0x27;
      pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar16 + 0x10e),
                                            *(undefined2 *)(iVar16 + 0x110),uVar10,pcVar11,uVar18,
                                            uVar42,uVar5,uVar44);
      pcVar11 = ovr_fmVsprintf((char *)"%s: Owned by %s. Active party is %s the %s.",pcVar11);
      uVar44 = 0;
      strcpy(local_2ca,pcVar11);
    }
    else {
      uVar44 = 0x10;
      uVar5 = ovr_OVC22_5087_0119(*(undefined1 *)(uVar15 + param_4 * 0x37 + 0x1a));
      uVar42 = 0x7a;
      uVar18 = ovr_OVC45_77eb_226e(local_ca);
      pcVar11 = (char *)"halfling castle" + 0xc;
      uVar10 = ovr_OVC45_77eb_226e(local_7a);
      uVar5 = ovr_OVC45_77eb_21d3(CONCAT11((char)(uStack_26 * 9 >> 8),
                                           *(undefined1 *)((int)DAT_2000_ca95 + uStack_26 * 9 + 1)),
                                  CONCAT11((char)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 >> 8),
                                           *(undefined1 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x130)),
                                  *(undefined1 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x130),uVar10,
                                  pcVar11,uVar18,uVar42,uVar5,uVar44);
      iVar16 = (uStack_22 >> 8) * 0x27;
      pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar16 + 0x10e),
                                            *(undefined2 *)(iVar16 + 0x110),uVar5);
      pcVar11 = ovr_fmVsprintf((char *)"%s (%d/%d): Owned by %s. Active party is %s the %s.",pcVar11
                              );
      uVar44 = 0;
      strcpy(local_2ca,pcVar11);
    }
  }
  else {
    if (*(char *)(iVar16 + uStack_26 * 9 + 2) == -1) {
      iStack_18 = 0;
      unaff_DI = 0;
      uStack_1a = 0;
    }
    else {
      iStack_18 = ovr_OVC22_5087_0234(CONCAT11((char)(uStack_26 * 9 >> 8),(*(uint8_t *)((uint8_t *)&(uStack_22) + 1))),
                                      *(undefined1 *)(iVar16 + uStack_26 * 9 + 2),
                                      (char)*(undefined2 *)(iVar16 + uStack_26 * 9 + 4),
                                      (char)*(undefined2 *)(iVar16 + uStack_26 * 9 + 6));
      uVar18 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
      iVar16 = (int)DAT_2000_ca95;
      uVar44 = 99;
      unaff_DI = ovr_OVC22_5087_0411(CONCAT11((char)(uStack_26 * 9 >> 8),(*(uint8_t *)((uint8_t *)&(uStack_22) + 1))),
                                     *(undefined1 *)(iVar16 + uStack_26 * 9 + 2),
                                     (char)*(undefined2 *)(iVar16 + uStack_26 * 9 + 4),
                                     (char)*(undefined2 *)(iVar16 + uStack_26 * 9 + 6));
      uStack_1a = (uint)*(byte *)((uStack_22 >> 8) * 0x27 + 0x127);
    }
    if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x06') {
      bVar6 = *(byte *)((int)&far_t_ARRAY_2410_74ad[1].seg + 1 +
                       (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x131));
      iStack_28 = CONCAT11((*(uint8_t *)((uint8_t *)&(iStack_28) + 1)),bVar6);
      uVar22 = *(undefined4 *)((uStack_22 & 0xff) << 2);
      cVar7 = *(char *)((int)uVar22 + 0x2f);
      if (cVar7 == '\x04') {
        if (0xc < bVar6) {
          iStack_28 = CONCAT11((*(uint8_t *)((uint8_t *)&(iStack_28) + 1)),0xc);
        }
      }
      else if (cVar7 == '\x05') {
        if (10 < bVar6) {
          iStack_28 = CONCAT11((*(uint8_t *)((uint8_t *)&(iStack_28) + 1)),10);
        }
      }
      else if ((cVar7 == '\x06') && (8 < bVar6)) {
        iStack_28 = CONCAT11((*(uint8_t *)((uint8_t *)&(iStack_28) + 1)),8);
      }
      pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                            (char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                            (char)-unaff_DI,(char)iStack_28);
      uVar44 = 0x37;
      ovr_stsprintf(local_2ca,"%s: Costs %d gold and provides training to level %d.",pcVar11);
    }
    else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x01') {
      if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x131) == '\x01') {
        pcVar11 = (char *)ovr_OVC15_4207_1c16((char)*(undefined2 *)
                                                     ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                              (char)*(undefined2 *)
                                                     ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                              (char)-unaff_DI);
        pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold of income. Replaces broken weapons.",
                                 pcVar11);
        uVar44 = 0;
        strcpy(local_2ca,pcVar11);
      }
      else {
        pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                              (char)*(undefined2 *)
                                                     ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                              (char)-unaff_DI,
                                              *(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x131) + -1);
        pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold of income. Forges +%d weapons.",pcVar11)
        ;
        uVar44 = 0;
        strcpy(local_2ca,pcVar11);
      }
    }
    else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x1d') {
      if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x131) == '\x01') {
        pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                              (char)*(undefined2 *)
                                                     ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                              (char)-unaff_DI,
                                              *(undefined1 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x131))
        ;
        pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold of income. Improves armor.",pcVar11);
        uVar44 = 0;
        strcpy(local_2ca,pcVar11);
      }
      else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x131) == '\x01') {
        pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                              (char)*(undefined2 *)
                                                     ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                              (char)-unaff_DI,
                                              *(undefined1 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x131))
        ;
        pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold of income. Improves armor class by -%d."
                                 ,pcVar11);
        uVar44 = 0;
        strcpy(local_2ca,pcVar11);
      }
    }
    else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\r') {
      if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x131) == '\x01') {
        pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                              (char)*(undefined2 *)
                                                     ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                              (char)-unaff_DI,
                                              *(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x131) + -1);
        pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold of income. Replaces broken bows.",
                                 pcVar11);
        uVar44 = 0;
        strcpy(local_2ca,pcVar11);
      }
      else {
        pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                              (char)*(undefined2 *)
                                                     ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                              (char)-unaff_DI,
                                              *(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x131) + -1);
        pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold of income. Creates +%d bow and arrows.",
                                 pcVar11);
        uVar44 = 0;
        strcpy(local_2ca,pcVar11);
      }
    }
    else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x0e') {
      pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                            (char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                            (char)-unaff_DI,
                                            *(undefined1 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x131));
      pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold. Increases unit size of five units by %d."
                               ,pcVar11);
      uVar44 = 0;
      strcpy(local_2ca,pcVar11);
    }
    else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x0f') {
      pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                            (char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                            (char)-unaff_DI,
                                            *(undefined1 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x131));
      pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold. Increases building speed by %d0%%.",
                               pcVar11);
      uVar44 = 0;
      strcpy(local_2ca,pcVar11);
    }
    else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x17') {
      uVar5 = constrct_7e7c_0b40();
      iVar16 = (uStack_22 >> 8) * 0x27;
      pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar16 + 0x10e),
                                            (char)*(undefined2 *)(iVar16 + 0x110),(char)-unaff_DI,
                                            uVar5);
      pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold. Enhances training by %d%%.",pcVar11);
      uVar44 = 0;
      strcpy(local_2ca,pcVar11);
    }
    else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x10') {
      pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                            (char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                            (char)-unaff_DI,
                                            *(undefined1 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x131));
      pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold. Produces +%d rings of protection.",
                               pcVar11);
      uVar44 = 0;
      strcpy(local_2ca,pcVar11);
    }
    else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x11') {
      pcVar11 = (char *)ovr_OVC15_4207_1c16((char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                            (char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                            (char)-unaff_DI);
      pcVar11 = ovr_fmVsprintf((char *)
                               "%s: Costs %d gold. Produces mirrors for medusae combat. Increases tower range by 5."
                               ,pcVar11);
      uVar44 = 0;
      strcpy(local_2ca,pcVar11);
    }
    else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x12') {
      pcVar11 = (char *)ovr_OVC15_4207_1c16((char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                            (char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                            (char)-unaff_DI);
      pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold. Attracts new units to this location.",
                               pcVar11);
      uVar44 = 0;
      strcpy(local_2ca,pcVar11);
    }
    else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x13') {
      pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                            (char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                            (char)-unaff_DI,
                                            (char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x12a));
      pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold. Provides %u units of gold storage.",
                               pcVar11);
      uVar44 = 0;
      strcpy(local_2ca,pcVar11);
    }
    else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x14') {
      pcVar11 = (char *)ovr_OVC15_4207_1c16((char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                            (char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                            (char)-unaff_DI);
      pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold. Claim trees automatically.",pcVar11);
      uVar44 = 0;
      strcpy(local_2ca,pcVar11);
    }
    else {
      if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) != '\x15') {
        uVar13 = (int)unaff_DI >> 0xf;
        if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x16') {
          uVar22 = *(undefined4 *)((uStack_22 & 0xff) << 2);
          pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)
                                                 ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                                (char)*(undefined2 *)
                                                       ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                                *(undefined1 *)
                                                 ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x128),
                                                (char)*(undefined2 *)((int)uVar22 + 0xa0));
          pcVar11 = ovr_fmVsprintf((char *)"%s: Trades %d food for gold. Total trade is %d food.",
                                   pcVar11);
          strcpy(local_2ca,pcVar11);
        }
        else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x04') {
          uVar5 = ovr_OVC45_77eb_0976(*(undefined1 *)((int)DAT_2000_ca95 + uStack_26 * 9 + 2));
          iVar16 = (uStack_22 >> 8) * 0x27;
          pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar16 + 0x10e),
                                                (char)*(undefined2 *)(iVar16 + 0x110),(char)unaff_DI
                                                ,uVar5);
          pcVar11 = ovr_fmVsprintf((char *)
                                   "%s: Creates %d gold of income, and accesses %d%% of the market fund."
                                   ,pcVar11);
          strcpy(local_2ca,pcVar11);
        }
        else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x02') {
          cVar7 = ovr_unit_6616_0000((char)uStack_26);
          ovr_unit_6616_0000((char)uStack_26,cVar7 << 1);
          pcVar11 = (char *)ovr_OVC15_4207_1c16();
          pcVar11 = ovr_fmVsprintf((char *)
                                   "%s: Costs %d gold of income and provides visibility of %d squares n/s, %d squares e/w."
                                   ,pcVar11);
          strcpy(local_2ca,pcVar11);
        }
        else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x05') {
          pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)
                                                 ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                                (char)*(undefined2 *)
                                                       ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                                (char)-unaff_DI,
                                                (char)*(undefined2 *)
                                                       ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x12a));
          pcVar11 = ovr_fmVsprintf((char *)
                                   "%s: Costs %d gold of income and provides storage for %u food.",
                                   pcVar11);
          strcpy(local_2ca,pcVar11);
        }
        else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\x13') {
          pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)
                                                 ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                                (char)*(undefined2 *)
                                                       ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                                (char)-unaff_DI,
                                                (char)*(undefined2 *)
                                                       ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x12a));
          pcVar11 = ovr_fmVsprintf((char *)
                                   "%s: Costs %d gold of income and provides storage for %u gold.",
                                   pcVar11);
          strcpy(local_2ca,pcVar11);
        }
        else {
          uVar5 = (undefined1)uStack_1a;
          if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\0') {
            if (*(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x12a) == 0) {
              ovr_OVC45_77eb_1ba2(uVar5);
              pcVar11 = (char *)ovr_OVC15_4207_1c16();
              pcVar11 = ovr_fmVsprintf((char *)"%s: Provides housing for %d %s.",pcVar11);
              strcpy(local_2ca,pcVar11);
            }
            else {
              bVar6 = ovr_OVC45_77eb_1ba2(uVar5,(char)*(undefined2 *)
                                                       ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x12a));
              iVar16 = (uStack_22 >> 8) * 0x27;
              pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar16 + 0x10e),
                                                    *(undefined2 *)(iVar16 + 0x110),uStack_1a,
                                                    (char)((far_t *)far_t_ARRAY_2410_74ad + bVar6)->
                                                          ofs,
                                                    (char)*(undefined2 *)
                                                           ((int)&far_t_ARRAY_2410_74ad[0].seg +
                                                           (uint)bVar6 * 4));
              pcVar11 = ovr_fmVsprintf((char *)
                                       "%s: Provides housing for %d %s and storage for %d food.",
                                       pcVar11);
              strcpy(local_2ca,pcVar11);
            }
          }
          else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\b') {
            if (*(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x12a) == 0) {
              ovr_OVC45_77eb_1ba2(uVar5);
              pcVar11 = (char *)ovr_OVC15_4207_1c16();
              pcVar11 = ovr_fmVsprintf((char *)"%s: Provides housing for %d %s.",pcVar11);
              strcpy(local_2ca,pcVar11);
            }
            else {
              bVar6 = ovr_OVC45_77eb_1ba2(uVar5,(char)*(undefined2 *)
                                                       ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x12a));
              iVar16 = (uStack_22 >> 8) * 0x27;
              pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar16 + 0x10e),
                                                    *(undefined2 *)(iVar16 + 0x110),uStack_1a,
                                                    (char)((far_t *)far_t_ARRAY_2410_74ad + bVar6)->
                                                          ofs,
                                                    (char)*(undefined2 *)
                                                           ((int)&far_t_ARRAY_2410_74ad[0].seg +
                                                           (uint)bVar6 * 4));
              pcVar11 = ovr_fmVsprintf((char *)
                                       "%s: Provides housing for %d %s and storage for %d food.",
                                       pcVar11);
              strcpy(local_2ca,pcVar11);
            }
          }
          else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x133) == '\t') {
            bVar6 = ovr_OVC45_77eb_1ba2((char)iStack_18);
            uVar45 = (undefined1)
                     *(undefined2 *)((int)&far_t_ARRAY_2410_74ad[0].seg + (uint)bVar6 * 4);
            uVar44 = (undefined1)((far_t *)far_t_ARRAY_2410_74ad + bVar6)->ofs;
            uVar5 = (undefined1)iStack_18;
            iVar16 = (unaff_DI ^ uVar13) - uVar13;
            uVar12 = uVar13;
            uVar18 = ovr_OVC45_77eb_2257();
            iVar8 = (uStack_22 >> 8) * 0x27;
            pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar8 + 0x10e),
                                                  *(undefined2 *)(iVar8 + 0x110),uVar18,uVar12,
                                                  iVar16,uVar5,uVar44,uVar45);
            pcVar11 = ovr_fmVsprintf((char *)"%s: %s %d gold. Feeds %d %s.",pcVar11);
            strcpy(local_2ca,pcVar11);
          }
          else if (((iStack_18 != 0) || (unaff_DI != 0)) || (uStack_1a != 0)) {
            if (iStack_18 == 0) {
              if (uStack_1a == 0) {
                ovr_OVC45_77eb_2257((char)unaff_DI,(char)((unaff_DI ^ uVar13) - uVar13));
                pcVar11 = (char *)ovr_OVC15_4207_1c16();
                pcVar11 = ovr_fmVsprintf((char *)"%s: %s %d gold.",pcVar11);
                strcpy(local_2ca,pcVar11);
              }
              else {
                bVar6 = ovr_OVC45_77eb_1ba2(uVar5);
                uVar45 = (undefined1)
                         *(undefined2 *)((int)&far_t_ARRAY_2410_74ad[0].seg + (uint)bVar6 * 4);
                uVar44 = (undefined1)((far_t *)far_t_ARRAY_2410_74ad + bVar6)->ofs;
                uVar5 = (undefined1)uStack_1a;
                iVar16 = (unaff_DI ^ uVar13) - uVar13;
                uVar12 = uVar13;
                uVar18 = ovr_OVC45_77eb_2257();
                iVar8 = (uStack_22 >> 8) * 0x27;
                pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar8 + 0x10e),
                                                      *(undefined2 *)(iVar8 + 0x110),uVar18,uVar12,
                                                      iVar16,uVar5,uVar44,uVar45);
                pcVar11 = ovr_fmVsprintf((char *)"%s: %s %d gold. Provides housing for %d %s.",
                                         pcVar11);
                strcpy(local_2ca,pcVar11);
              }
            }
            else {
              if (uStack_1a == 0) goto LAB_7e7c_1dc8;
              bVar6 = ovr_OVC45_77eb_1ba2((char)iStack_18);
              bVar6 = ovr_OVC45_77eb_1ba2(uStack_1a,(char)iStack_18,
                                          (char)((far_t *)far_t_ARRAY_2410_74ad + bVar6)->ofs,
                                          (char)*(undefined2 *)
                                                 ((int)&far_t_ARRAY_2410_74ad[0].seg +
                                                 (uint)bVar6 * 4));
              uVar12 = uVar13;
              uVar18 = ovr_OVC45_77eb_2257(unaff_DI,(unaff_DI ^ uVar13) - uVar13,uStack_1a,
                                           ((far_t *)far_t_ARRAY_2410_74ad + bVar6)->ofs,
                                           *(undefined2 *)
                                            ((int)&far_t_ARRAY_2410_74ad[0].seg + (uint)bVar6 * 4));
              iVar16 = (uStack_22 >> 8) * 0x27;
              pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar16 + 0x10e),
                                                    *(undefined2 *)(iVar16 + 0x110),uVar18,uVar12);
              pcVar11 = ovr_fmVsprintf((char *)
                                       "%s: %s %d gold. provides housing for %d %s and feeds %d %s."
                                       ,pcVar11);
              strcpy(local_2ca,pcVar11);
            }
          }
        }
        do {
          iVar8 = 0;
          uVar18 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
          iVar16 = (int)DAT_2000_ca95;
          uStack_20 = (char *)((int)(((long)*(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x125) *
                                      (long)(int)(uint)*(byte *)(iVar16 + uStack_26 * 9 + 1) &
                                     0xffffU) / 0x18) + 1);
          auStack_14[0] = 1;
          if (*(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x116) == 0 &&
              *(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x118) == 0) {
            if (((uStack_26 < 0xf8) || (*(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x125) == 0)) ||
               ((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x121) & 4) != 0)) {
              if ((((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x121) & 4) == 0) ||
                  (*(char *)(iVar16 + uStack_26 * 9 + 2) == -1)) ||
                 (uVar22 = *(undefined4 *)((uint)*(byte *)(iVar16 + uStack_26 * 9 + 2) << 2),
                 *(char *)((int)uVar22 + 0x3f) != '\0')) {
                local_2f2[1] = (char *)"puppetmaker" + 3;
                local_2f2[0] = (char *)"Demolish";
                iVar8 = 1;
              }
              uStack_20 = (char *)0x0;
            }
            else {
              local_2f2[1] = (char *)"puppetmaker" + 3;
              local_2f2[0] = (char *)"Salvage";
              iVar8 = 1;
              if (cStack_29 != '\0') {
                pcVar11 = ovr_fmVsprintf((char *)" Salvage value %d gold.",uStack_20);
                strcat(local_2ca,pcVar11);
              }
            }
          }
          else {
            local_2f2[1] = (char *)*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x118);
            local_2f2[0] = (char *)*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x116);
            iVar8 = 1;
          }
          cVar7 = ovr_OVC45_77eb_2226(*(undefined1 *)((int)DAT_2000_ca95 + uStack_26 * 9 + 2));
          uVar18 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
          if ((cVar7 == '\0') || (7 < *(byte *)((int)DAT_2000_ca95 + uStack_26 * 9 + 1))) {
            cVar7 = ovr_OVC45_77eb_2226(*(undefined1 *)((int)DAT_2000_ca95 + uStack_26 * 9 + 2));
            if ((cVar7 != '\0') && (*(char *)((uStack_22 >> 8) * 0x27 + 300) != '\0')) {
              auStack_14[iVar8] = 3;
              local_2f2[iVar8 * 2 + 1] = (char *)"puppetmaker" + 3;
              local_2f2[iVar8 * 2] = (char *)"Upgrade";
              iVar8 = iVar8 + 1;
              uStack_1e = (char *)*(undefined2 *)
                                   (((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) +
                                    (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 300)) * 0x27 +
                                   0x125);
              if (cStack_29 == '\0') {
                pcVar11 = ovr_fmVsprintf((char *)" Upgrade costs %d gp.",uStack_1e);
                strcat(local_2ca,pcVar11);
              }
            }
          }
          else {
            auStack_14[iVar8] = 2;
            local_2f2[iVar8 * 2 + 1] = (char *)"puppetmaker" + 3;
            local_2f2[iVar8 * 2] = (char *)"Repair";
            iVar8 = iVar8 + 1;
            uStack_1e = (char *)(*(uint *)((uStack_22 >> 8) * 0x27 + 0x125) / 5 + 1);
            if (cStack_29 == '\0') {
              pcVar11 = ovr_fmVsprintf((char *)" Repair costs %d gp.",uStack_1e);
              strcat(local_2ca,pcVar11);
            }
          }
          bVar6 = *(byte *)((int)DAT_2000_ca95 + uStack_26 * 9 + 2);
          uStack_24 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_24) + 1)),bVar6);
          if ((((*(uint *)((uStack_22 >> 8) * 0x27 + 0x121) & 0x400) == 0) && (bVar6 != 0xff)) &&
             (*(char *)((int)*(undefined4 *)((uint)bVar6 << 2) + 0x3f) == '\0')) {
            auStack_14[iVar8] = 7;
            local_2f2[iVar8 * 2 + 1] = (char *)"puppetmaker" + 3;
            local_2f2[iVar8 * 2] = (char *)"Information";
            iVar8 = iVar8 + 1;
          }
          uVar5 = 0x19;
          if (((*(uint *)((uStack_22 >> 8) * 0x27 + 0x121) & 4) == 0) && (0xf7 < uStack_26)) {
            uVar5 = 0x24;
            if (*(char *)(Entities.ofs + param_4 * 0x37 + 0x1a) != (char)uStack_24) {
              auStack_14[iVar8] = 6;
              local_2f2[iVar8 * 2 + 1] = (char *)"puppetmaker" + 3;
              local_2f2[iVar8 * 2] = (char *)"New Owner";
              iVar8 = iVar8 + 1;
            }
          }
          if (param_7 != '\0') {
            auStack_14[iVar8] = 4;
            local_2f2[iVar8 * 2 + 1] = (char *)"puppetmaker" + 3;
            local_2f2[iVar8 * 2] = (char *)"Change Party";
            iVar8 = iVar8 + 1;
          }
          auStack_14[iVar8] = 5;
          local_2f2[iVar8 * 2 + 1] = (char *)"puppetmaker" + 3;
          local_2f2[iVar8 * 2] = (char *)"Done";
          uVar15 = CONCAT11(uVar5,(char)uStack_22);
          DAT_2410_5cef = (char)uStack_22;
          bStack_1b = ovr_OVC28_6018_1527();
          DAT_2410_5cef = 0xff;
          if (bStack_1b != 0) {
            uVar15 = (int)&local_16 + 1;
            bStack_1b = *(byte *)(bStack_1b + uVar15);
          }
          uVar12 = (uint)bStack_1b;
          fVar24.seg = uVar15;
          fVar24.ofs = uVar12;
          if (7 < uVar12) {
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          pcVar11 = (char *)(uVar12 * 2);
          switch(uVar12) {
          case 0:
            goto code_r0x00088b00;
          case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          case 2:
LAB_7e7c_1dc8:
            bVar6 = ovr_OVC45_77eb_1ba2((char)iStack_18);
            uVar45 = (undefined1)
                     *(undefined2 *)((int)&far_t_ARRAY_2410_74ad[0].seg + (uint)bVar6 * 4);
            uVar44 = (undefined1)((far_t *)far_t_ARRAY_2410_74ad + bVar6)->ofs;
            uVar5 = (undefined1)iStack_18;
            iVar16 = (unaff_DI ^ uVar13) - uVar13;
            uVar12 = uVar13;
            uVar18 = ovr_OVC45_77eb_2257();
            iVar8 = (uStack_22 >> 8) * 0x27;
            pcVar11 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar8 + 0x10e),
                                                  *(undefined2 *)(iVar8 + 0x110),uVar18,uVar12,
                                                  iVar16,uVar5,uVar44,uVar45);
            pcVar11 = ovr_fmVsprintf((char *)"%s: %s %d gold. Feeds %d %s.",pcVar11);
            strcpy(local_2ca,pcVar11);
            break;
          case 3:
            SpecialColors[1] = bStack_1b;
            SpecialColors[2] =
                 ((char *)"If you lead with wisdom and cunning..." + 9)
                 [(*(far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300)).ofs];
            SpecialColors[3] =
                 ((char *)"ENTER: use previous configuration, SPACE: reconfigure, ESC: quit" + 0x12)
                 [(*(far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300)).ofs];
            SpecialColors[4] =
                 ((char *)"%s turns %d undead." + 0x10)[(*(far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300)).ofs];
            SpecialColors[5] =
                 *(uint8_t *)
                  ((int)&GStrangeTable[0x12].seg + 1 + (*(far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300)).ofs);
            SpecialColors[6] =
                 *(uint8_t *)
                  ((int)(undefined2 *)&DAT_2000_d43e + (*(far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300)).ofs);
            SpecialColors[7] = *(uint8_t *)((*(far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300)).ofs + 0x936e);
            uVar38 = ovr_stshWrite((uint8_t *)SpecialColors,8);
            DAT_2000_d1ce = (undefined2)(uVar38 >> 0x10);
            DAT_2000_d1cc = (undefined2)uVar38;
            src_26.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
            src_26.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
            fVar24 = ovr_stshRleCut(src_26,234,64,314,120);
            pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
            DAT_2000_cafb = (undefined2)((ulong)pcVar21 >> 0x10);
            DAT_2000_caf9 = (uint16_t)(pcVar21);
            src_27.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
            src_27.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
            fVar24 = ovr_stshRleCut(src_27,208,158,228,176);
            pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
            DAT_2000_cb13 = (undefined2)((ulong)pcVar21 >> 0x10);
            DAT_2000_cb11 = (uint16_t)(pcVar21);
            src_28.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
            src_28.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
            fVar24 = ovr_stshRleCut(src_28,179,180,198,196);
            pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
            DAT_2000_cacb = (undefined2)((ulong)pcVar21 >> 0x10);
            DAT_2000_cac9 = (uint16_t)(pcVar21);
            src_29.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
            src_29.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
            fVar24 = ovr_stshRleCut(src_29,207,180,226,196);
            pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
            DAT_2000_cac7 = (undefined2)((ulong)pcVar21 >> 0x10);
            DAT_2000_cac5 = (uint16_t)(pcVar21);
            src_30.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
            src_30.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
            fVar24 = ovr_stshRleCut(src_30,38,181,57,196);
            pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
            DAT_2000_cac3 = (undefined2)((ulong)pcVar21 >> 0x10);
            DAT_2000_cac1 = (uint16_t)(pcVar21);
            src_31.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
            src_31.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
            fVar24 = ovr_stshRleCut(src_31,9,181,24,196);
            pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
            DAT_2000_cabf = (undefined2)((ulong)pcVar21 >> 0x10);
            DAT_2000_cabd = (uint16_t)(pcVar21);
            ovr_stgFreeTmp((stg_tmp_t *)
                           CONCAT13((char)((uint)psStack_8 >> 8),
                                    CONCAT12((char)psStack_8,(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)))));
            if (param_1 == false) {
              fVar24 = ovr_stshAllocStub();
              DAT_2000_ca3a = fVar24.seg;
              DAT_2000_ca38 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_caf7 = fVar24.seg;
              DAT_2000_caf5 = (uint16_t)(fVar24.ofs);
              fVar25 = ovr_stshAllocStub();
            }
            else {
              join_0x00000008_0x00000000_ = ovr_grabLbmTR(127);
              uVar18 = (undefined2)((ulong)join_0x00000008_0x00000000_ >> 0x10);
              src_32.seg = (((stg_tmp_t *)join_0x00000008_0x00000000_)->aptr).seg;
              src_32.ofs = (&((stg_tmp_t *)join_0x00000008_0x00000000_)->aptr)->ofs;
              fVar24 = ovr_stshRleCut(src_32,245,116,267,128);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_ca3a = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_ca38 = (uint16_t)(pcVar21);
              src_33.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_33.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_33,292,114,314,133);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_caf7 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_caf5 = (uint16_t)(pcVar21);
              src_34.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_34.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_34,221,157,228,198);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_caf3 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_caf1 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar25.seg = DAT_2000_caf3;
              fVar25.ofs = (uint16_t)DAT_2000_caf1;
            }
            DAT_2000_caf3 = fVar25.seg;
            DAT_2000_caf1 = (uint16_t)(fVar25.ofs);
            if (param_1 == false) {
              Lbm_nwpanel1 = ovr_stshAllocStub();
              fVar24 = ovr_stshAllocStub();
              DAT_2000_caff = fVar24.seg;
              DAT_2000_cafd = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_cacf = fVar24.seg;
              DAT_2000_cacd = (uint16_t)(fVar24.ofs);
              FontHandle = ovr_stshAllocStub();
              fVar24 = ovr_stshAllocStub();
              DAT_2000_cabb = fVar24.seg;
              DAT_2000_cab9 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_caab = fVar24.seg;
              DAT_2000_caa9 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d1aa = fVar24.seg;
              DAT_2000_d1a8 = (uint16_t)(fVar24.ofs);
              fVar26 = ovr_stshAllocStub();
            }
            else {
              psVar23 = ovr_grabLbm(15,0,0);
              unique0x1002b7e5 = psVar23;
              Lbm_nwpanel1 = far_from_u32((uint32_t)(ovr_stshWrite(((stg_tmp_t *)psVar23)->cmap,0x300)));
              src_35.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_35.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_35,230,57,314,113);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_caff = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_cafd = (uint16_t)(pcVar21);
              src_36.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_36.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_36,0,0,319,199);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_cacf = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_cacd = (uint16_t)(pcVar21);
              src_37.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_37.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_37,29,156,207,199);
              FontHandle = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
              src_38.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_38.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_38,9,181,28,196);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_cabb = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_cab9 = (uint16_t)(pcVar21);
              src_39.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_39.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_39,223,8,237,50);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_caab = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_caa9 = (uint16_t)(pcVar21);
              src_40.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_40.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_40,6,156,28,171);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d1aa = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d1a8 = (uint16_t)(pcVar21);
              src_41.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_41.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_41,208,157,229,198);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d119 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d117 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar26.seg = DAT_2000_d119;
              fVar26.ofs = (uint16_t)DAT_2000_d117;
            }
            DAT_2000_d119 = fVar26.seg;
            DAT_2000_d117 = (uint16_t)(fVar26.ofs);
            if (param_1 == false) {
              iVar16 = 0;
              while( true ) {
                DAT_2000_d119 = fVar26.seg;
                DAT_2000_d117 = (uint16_t)(fVar26.ofs);
                if (3 < iVar16) break;
                fVar24 = ovr_stshAllocStub();
                *(uint16_t *)((int)&CrossBlitGfx.seg + iVar16 * 4) = fVar24.seg;
                ((far_t *)&CrossBlitGfx + iVar16)->ofs = fVar24.ofs;
                fVar24 = ovr_stshAllocStub();
                ((undefined2 *)&DAT_2000_cc67)[iVar16 * 2] = fVar24.seg;
                ((undefined2 *)&DAT_2000_cc65)[iVar16 * 2] = fVar24.ofs;
                fVar26.seg = DAT_2000_d119;
                fVar26.ofs = (uint16_t)DAT_2000_d117;
                iVar16 = iVar16 + 1;
              }
            }
            else {
              psVar23 = ovr_grabLbm(12,0,0);
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                unique0x1002bc59 = psVar23;
                if (3 < iVar16) break;
                src_42.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                src_42.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                fVar24 = ovr_stshRleCut(src_42,iVar16 * 0xe,46,iVar16 * 0xe + 0xd,55);
                pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
                *(undefined2 *)((int)&CrossBlitGfx.seg + iVar16 * 4) = (int)((ulong)pcVar21 >> 0x10)
                ;
                ((far_t *)&CrossBlitGfx + iVar16)->ofs = (uint16_t)(cte_t *)pcVar21;
                pixels_x00201.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00201.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00201,iVar16 * 0xe,16,iVar16 * 0xe + 0xd,24,6,4);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cc67)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cc65)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              ovr_stgFreeTmp(psVar23);
              fVar26.seg = DAT_2000_d119;
              fVar26.ofs = (uint16_t)DAT_2000_d117;
            }
            DAT_2000_d119 = fVar26.seg;
            DAT_2000_d117 = (uint16_t)(fVar26.ofs);
            if (param_1 == false) {
              iVar16 = 0;
              while( true ) {
                DAT_2000_d119 = fVar26.seg;
                DAT_2000_d117 = (uint16_t)(fVar26.ofs);
                if (0x16 < iVar16) break;
                fVar24 = ovr_stshAllocStub();
                ((undefined2 *)&DAT_2000_cc0b)[iVar16 * 2] = fVar24.seg;
                ((undefined2 *)&DAT_2000_cc09)[iVar16 * 2] = fVar24.ofs;
                fVar26.seg = DAT_2000_d119;
                fVar26.ofs = (uint16_t)DAT_2000_d117;
                iVar16 = iVar16 + 1;
              }
              iVar16 = 0;
              while( true ) {
                DAT_2000_d119 = fVar26.seg;
                DAT_2000_d117 = (uint16_t)(fVar26.ofs);
                if (0x17 < iVar16) break;
                fVar24 = ovr_stshAllocStub();
                ((undefined2 *)&DAT_2000_cbab)[iVar16 * 2] = fVar24.seg;
                ((undefined2 *)&DAT_2000_cba9)[iVar16 * 2] = fVar24.ofs;
                fVar26.seg = DAT_2000_d119;
                fVar26.ofs = (uint16_t)DAT_2000_d117;
                iVar16 = iVar16 + 1;
              }
              iVar16 = 0;
              while( true ) {
                DAT_2000_d119 = fVar26.seg;
                DAT_2000_d117 = (uint16_t)(fVar26.ofs);
                if (0x1f < iVar16) break;
                fVar24 = ovr_stshAllocStub();
                ((undefined2 *)&DAT_2000_cb2b)[iVar16 * 2] = fVar24.seg;
                ((undefined2 *)&DAT_2000_cb29)[iVar16 * 2] = fVar24.ofs;
                fVar26.seg = DAT_2000_d119;
                fVar26.ofs = (uint16_t)DAT_2000_d117;
                iVar16 = iVar16 + 1;
              }
              iVar16 = 0;
              while( true ) {
                DAT_2000_d119 = fVar26.seg;
                DAT_2000_d117 = (uint16_t)(fVar26.ofs);
                if (0xd < iVar16) break;
                fVar24 = ovr_stshAllocStub();
                ((undefined2 *)&DAT_2000_d2a0)[iVar16 * 2] = fVar24.seg;
                ((undefined2 *)&DAT_2000_d29e)[iVar16 * 2] = fVar24.ofs;
                fVar26.seg = DAT_2000_d119;
                fVar26.ofs = (uint16_t)DAT_2000_d117;
                iVar16 = iVar16 + 1;
              }
              iVar16 = 0;
              while( true ) {
                DAT_2000_d119 = fVar26.seg;
                DAT_2000_d117 = (uint16_t)(fVar26.ofs);
                if (0x10 < iVar16) break;
                fVar24 = ovr_stshAllocStub();
                ((undefined2 *)&DAT_2000_d25c)[iVar16 * 2] = fVar24.seg;
                ((undefined2 *)&DAT_2000_d25a)[iVar16 * 2] = fVar24.ofs;
                fVar26.seg = DAT_2000_d119;
                fVar26.ofs = (uint16_t)DAT_2000_d117;
                iVar16 = iVar16 + 1;
              }
              iVar16 = 0;
              while( true ) {
                DAT_2000_d119 = fVar26.seg;
                DAT_2000_d117 = (uint16_t)(fVar26.ofs);
                if (6 < iVar16) break;
                fVar24 = ovr_stshAllocStub();
                ((undefined2 *)&DAT_2000_d240)[iVar16 * 2] = fVar24.seg;
                ((undefined2 *)&DAT_2000_d23e)[iVar16 * 2] = fVar24.ofs;
                fVar26.seg = DAT_2000_d119;
                fVar26.ofs = (uint16_t)DAT_2000_d117;
                iVar16 = iVar16 + 1;
              }
              iVar16 = 0;
              while( true ) {
                DAT_2000_d119 = fVar26.seg;
                DAT_2000_d117 = (uint16_t)(fVar26.ofs);
                if (6 < iVar16) break;
                fVar24 = ovr_stshAllocStub();
                ((undefined2 *)&DAT_2000_d224)[iVar16 * 2] = fVar24.seg;
                ((undefined2 *)&DAT_2000_d222)[iVar16 * 2] = fVar24.ofs;
                fVar26.seg = DAT_2000_d119;
                fVar26.ofs = (uint16_t)DAT_2000_d117;
                iVar16 = iVar16 + 1;
              }
              iVar16 = 0;
              while( true ) {
                DAT_2000_d119 = fVar26.seg;
                DAT_2000_d117 = (uint16_t)(fVar26.ofs);
                if (7 < iVar16) break;
                fVar24 = ovr_stshAllocStub();
                ((undefined2 *)&DAT_2000_d204)[iVar16 * 2] = fVar24.seg;
                ((undefined2 *)&DAT_2000_d202)[iVar16 * 2] = fVar24.ofs;
                fVar26.seg = DAT_2000_d119;
                fVar26.ofs = (uint16_t)DAT_2000_d117;
                iVar16 = iVar16 + 1;
              }
              iVar16 = 0;
              while( true ) {
                DAT_2000_d119 = fVar26.seg;
                DAT_2000_d117 = (uint16_t)(fVar26.ofs);
                psVar23 = unique0x100287f5;
                if (4 < iVar16) break;
                fVar24 = ovr_stshAllocStub();
                ((undefined2 *)&DAT_2000_d1f0)[iVar16 * 2] = fVar24.seg;
                ((undefined2 *)&DAT_2000_d1ee)[iVar16 * 2] = fVar24.ofs;
                fVar26.seg = DAT_2000_d119;
                fVar26.ofs = (uint16_t)DAT_2000_d117;
                iVar16 = iVar16 + 1;
              }
            }
            else {
              psVar23 = ovr_grabLbm(93,0,0);
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (5 < iVar16) break;
                pixels_x00202.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00202.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b7fd = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00202,8,iVar16 * 0x20 + 10,63,
                                           iVar16 * 0x20 + 0x24,0,0);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cc0b)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cc09)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (5 < iVar16) break;
                pixels_x00203.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00203.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b989 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00203,85,iVar16 * 0x20 + 10,140,
                                           iVar16 * 0x20 + 0x24,0,0);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cc23)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cc21)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (5 < iVar16) break;
                pixels_x00204.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00204.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002ba21 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00204,159,iVar16 * 0x20 + 10,214,
                                           iVar16 * 0x20 + 0x24,0,0);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cc3b)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cc39)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                unique0x1002bc7d = psVar23;
                if (4 < iVar16) break;
                pixels_x00205.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00205.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00205,229,iVar16 * 0x20 + 10,284,
                                           iVar16 * 0x20 + 0x24,0,0);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cc53)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cc51)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              ovr_stgFreeTmp(psVar23);
              psVar23 = ovr_grabLbm(94,0,0);
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (2 < iVar16) break;
                pixels_x00206.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00206.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b809 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00206,0,iVar16 * 0x3d + 0x11,104,
                                           iVar16 * 0x3d + 0x49,0,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cbab)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cba9)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (2 < iVar16) break;
                pixels_x00207.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00207.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b995 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00207,109,iVar16 * 0x3d + 0x11,213,
                                           iVar16 * 0x3d + 0x49,0,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cbb7)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cbb5)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                unique0x1002bc69 = psVar23;
                if (2 < iVar16) break;
                pixels_x00208.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00208.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00208,215,iVar16 * 0x3d + 0x11,319,
                                           iVar16 * 0x3d + 0x49,0,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cbc3)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cbc1)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              ovr_stgFreeTmp(psVar23);
              psVar23 = ovr_grabLbm(95,0,0);
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (2 < iVar16) break;
                pixels_x00209.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00209.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b815 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00209,0,iVar16 * 0x3d + 0x11,104,
                                           iVar16 * 0x3d + 0x49,0,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cbcf)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cbcd)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                unique0x1002bc61 = psVar23;
                if (2 < iVar16) break;
                pixels_x00210.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00210.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00210,109,iVar16 * 0x3d + 0x11,213,
                                           iVar16 * 0x3d + 0x49,0,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cbdb)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cbd9)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              ovr_stgFreeTmp(psVar23);
              psVar23 = ovr_grabLbm(96,0,0);
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (2 < iVar16) break;
                pixels_x00211.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00211.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b821 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00211,0,iVar16 * 0x3d + 0x11,104,
                                           iVar16 * 0x3d + 0x49,0,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cbe7)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cbe5)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (2 < iVar16) break;
                pixels_x00212.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00212.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b9ad = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00212,109,iVar16 * 0x3d + 0x11,213,
                                           iVar16 * 0x3d + 0x49,0,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cbf3)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cbf1)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                unique0x1002bc6d = psVar23;
                if (2 < iVar16) break;
                pixels_x00213.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00213.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00213,215,iVar16 * 0x3d + 0x11,319,
                                           iVar16 * 0x3d + 0x49,0,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cbff)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cbfd)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              ovr_stgFreeTmp(psVar23);
              psVar23 = ovr_grabLbm(531,0,0);
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (2 < iVar16) break;
                pixels_x00214.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00214.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b82d = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00214,1,iVar16 * 0x3d + 0x11,103,
                                           iVar16 * 0x3d + 0x49,-4,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cb2b)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cb29)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (2 < iVar16) break;
                pixels_x00215.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00215.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b9b9 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00215,104,iVar16 * 0x3d + 0x11,206,
                                           iVar16 * 0x3d + 0x49,-4,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cb37)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cb35)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                unique0x1002bc71 = psVar23;
                if (2 < iVar16) break;
                pixels_x00216.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00216.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00216,209,iVar16 * 0x3d + 0x11,311,
                                           iVar16 * 0x3d + 0x49,-4,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cb43)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cb41)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              ovr_stgFreeTmp(psVar23);
              psVar23 = ovr_grabLbm(532,0,0);
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (2 < iVar16) break;
                pixels_x00217.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00217.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b839 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00217,1,iVar16 * 0x3d + 0x11,103,
                                           iVar16 * 0x3d + 0x49,-4,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cb4f)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cb4d)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (2 < iVar16) break;
                pixels_x00218.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00218.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b9c5 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00218,104,iVar16 * 0x3d + 0x11,206,
                                           iVar16 * 0x3d + 0x49,-4,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cb5b)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cb59)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                unique0x1002bc75 = psVar23;
                if (2 < iVar16) break;
                pixels_x00219.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00219.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00219,209,iVar16 * 0x3d + 0x11,311,
                                           iVar16 * 0x3d + 0x49,-4,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cb67)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cb65)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              ovr_stgFreeTmp(psVar23);
              psVar23 = ovr_grabLbm(533,0,0);
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (2 < iVar16) break;
                pixels_x00220.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00220.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b845 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00220,1,iVar16 * 0x3d + 0x11,103,
                                           iVar16 * 0x3d + 0x49,-4,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cb73)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cb71)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (2 < iVar16) break;
                pixels_x00221.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00221.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b9d1 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00221,104,iVar16 * 0x3d + 0x11,206,
                                           iVar16 * 0x3d + 0x49,-4,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cb7f)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cb7d)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                unique0x1002bc79 = psVar23;
                if (2 < iVar16) break;
                pixels_x00222.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00222.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00222,209,iVar16 * 0x3d + 0x11,311,
                                           iVar16 * 0x3d + 0x49,-4,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cb8b)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cb89)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              ovr_stgFreeTmp(psVar23);
              psVar23 = ovr_grabLbm(534,0,0);
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (2 < iVar16) break;
                pixels_x00223.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00223.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b851 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00223,1,iVar16 * 0x3d + 0x11,103,
                                           iVar16 * 0x3d + 0x49,-4,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cb97)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cb95)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                unique0x1002bc65 = psVar23;
                if (1 < iVar16) break;
                pixels_x00224.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00224.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00224,104,iVar16 * 0x3d + 0x11,206,
                                           iVar16 * 0x3d + 0x49,-4,-60);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_cba3)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_cba1)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              ovr_stgFreeTmp(psVar23);
              psVar23 = ovr_grabLbm(535,0,0);
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (6 < iVar16) break;
                pixels_x00225.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00225.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b85d = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00225,6,iVar16 * 0x1b + 8,33,iVar16 * 0x1b + 0x13
                                           ,0,0);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_d2a0)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_d29e)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (6 < iVar16) break;
                pixels_x00226.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00226.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002b9e9 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00226,35,iVar16 * 0x1b + 8,62,
                                           iVar16 * 0x1b + 0x13,0,0);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_d2bc)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_d2ba)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (6 < iVar16) break;
                pixels_x00227.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00227.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002ba71 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00227,76,iVar16 * 0x1b + 8,88,
                                           iVar16 * 0x1b + 0x13,0,0);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_d25c)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_d25a)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (6 < iVar16) break;
                pixels_x00228.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00228.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002bb05 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00228,102,iVar16 * 0x1b + 8,114,
                                           iVar16 * 0x1b + 0x13,0,0);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_d278)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_d276)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (2 < iVar16) break;
                pixels_x00229.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00229.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002bb29 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00229,128,iVar16 * 0x1b + 8,140,
                                           iVar16 * 0x1b + 0x13,0,0);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_d294)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_d292)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (6 < iVar16) break;
                pixels_x00230.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00230.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002bb41 = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00230,154,iVar16 * 0x1b + 8,163,
                                           iVar16 * 0x1b + 0x13,0,0);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_d240)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_d23e)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                if (6 < iVar16) break;
                pixels_x00231.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00231.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                unique0x1002bb4d = psVar23;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00231,184,iVar16 * 0x1b + 8,185,
                                           iVar16 * 0x1b + 0x13,0,0);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_d224)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_d222)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              iVar16 = 0;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                unique0x1002bc81 = psVar23;
                if (6 < iVar16) break;
                pixels_x00232.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00232.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00232,207,iVar16 * 0x1b + 8,223,
                                           iVar16 * 0x1b + 0x13,0,0);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_d204)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_d202)[iVar16 * 2] = (uint16_t)(pcVar21);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              pixels_x00233.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              pixels_x00233.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00233,235,8,251,19,0,0);
              pcVar21 = ovr_stshStoreFile(puVar20);
              iVar16 = 0;
              psVar23 = stack0xfff6;
              while( true ) {
                psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
                (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
                DAT_2000_d220 = (undefined2)((ulong)pcVar21 >> 0x10);
                DAT_2000_d21e = (uint16_t)(pcVar21);
                unique0x1002bc85 = psVar23;
                if (4 < iVar16) break;
                pixels_x00234.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00234.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00234,267,iVar16 * 0x1b + 8,286,
                                           iVar16 * 0x1b + 0x13,0,0);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_d1f0)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_d1ee)[iVar16 * 2] = (uint16_t)(pcVar21);
                pcVar21 = (cte_t *)CONCAT22(DAT_2000_d220,DAT_2000_d21e);
                iVar16 = iVar16 + 1;
                psVar23 = stack0xfff6;
              }
              ovr_stgFreeTmp(psVar23);
              fVar26.seg = DAT_2000_d119;
              fVar26.ofs = (uint16_t)DAT_2000_d117;
              psVar23 = stack0xfff6;
            }
            DAT_2000_d119 = fVar26.seg;
            DAT_2000_d117 = (uint16_t)(fVar26.ofs);
            if (param_1 != false) {
              unique0x1002bb79 = psVar23;
              psVar23 = ovr_grabLbm(35,0,0);
              fVar26.seg = DAT_2000_d119;
              fVar26.ofs = (uint16_t)DAT_2000_d117;
            }
            iVar16 = 0;
            while( true ) {
              psStack_8 = (stg_tmp_t *)((ulong)psVar23 >> 0x10);
              (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = SUB42(psVar23,0);
              DAT_2000_d119 = fVar26.seg;
              DAT_2000_d117 = (uint16_t)(fVar26.ofs);
              unique0x1002bc5d = psVar23;
              if (3 < iVar16) break;
              if (param_1 == false) {
                fVar24 = ovr_stshAllocStub();
                ((undefined2 *)&DAT_2000_d2ee)[iVar16 * 2] = fVar24.seg;
                ((undefined2 *)&DAT_2000_d2ec)[iVar16 * 2] = fVar24.ofs;
                psVar23 = stack0xfff6;
              }
              else {
                pixels_x00235.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
                pixels_x00235.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
                puVar20 = (uint8_t *)
                          ovr_stshRleType2(pixels_x00235,iVar16 * 0x16,0,iVar16 * 0x16 + 0x15,14,11,
                                           7);
                pcVar21 = ovr_stshStoreFile(puVar20);
                ((undefined2 *)&DAT_2000_d2ee)[iVar16 * 2] = (int)((ulong)pcVar21 >> 0x10);
                ((undefined2 *)&DAT_2000_d2ec)[iVar16 * 2] = (uint16_t)(pcVar21);
                psVar23 = stack0xfff6;
              }
              fVar26.seg = DAT_2000_d119;
              fVar26.ofs = (uint16_t)DAT_2000_d117;
              iVar16 = iVar16 + 1;
            }
            if (param_1 == false) {
              fVar27 = ovr_stshAllocStub();
            }
            else {
              ovr_stgFreeTmp(psVar23);
              psVar23 = ovr_grabLbm(8,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_43.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_43.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b865 = psVar23;
              fVar24 = ovr_stshRleCut(src_43,0,0,319,199);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d1ca = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d1c8 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar27.seg = DAT_2000_d1ca;
              fVar27.ofs = (uint16_t)DAT_2000_d1c8;
            }
            DAT_2000_d1ca = fVar27.seg;
            DAT_2000_d1c8 = (uint16_t)(fVar27.ofs);
            if (param_1 == false) {
              fVar28 = ovr_stshAllocStub();
            }
            else {
              psVar23 = ovr_grabLbm(6,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_44.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_44.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b869 = psVar23;
              fVar24 = ovr_stshRleCut(src_44,0,0,319,199);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d1c6 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d1c4 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar28.seg = DAT_2000_d1c6;
              fVar28.ofs = (uint16_t)DAT_2000_d1c4;
            }
            DAT_2000_d1c6 = fVar28.seg;
            DAT_2000_d1c4 = (uint16_t)(fVar28.ofs);
            if (param_1 == false) {
              fVar29 = ovr_stshAllocStub();
            }
            else {
              psVar23 = ovr_grabLbm(140,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_45.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_45.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b86d = psVar23;
              fVar24 = ovr_stshRleCut(src_45,0,0,319,27);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d1c2 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d1c0 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar29.seg = DAT_2000_d1c2;
              fVar29.ofs = (uint16_t)DAT_2000_d1c0;
            }
            DAT_2000_d1c2 = fVar29.seg;
            DAT_2000_d1c0 = (uint16_t)(fVar29.ofs);
            if (param_1 == false) {
              fVar30 = ovr_stshAllocStub();
            }
            else {
              psVar23 = ovr_grabLbm(411,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              FontSize.hi = 0;
              FontSize.lo = 0;
              uVar15 = (((stg_tmp_t *)psVar23)->aptr).seg;
              (*(uint8_t *)((uint8_t *)&(hndl.seg))) = (char)uVar15;
              hndl.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              (*(uint8_t *)((uint8_t *)&(hndl.seg) + 1)) = (char)(uVar15 >> 8);
              unique0x1002b871 = psVar23;
              fStack_6 = ovr_stshProcessFontSub(hndl);
              uVar38 = ovr_stshWrite((uint8_t *)fStack_6.ofs,
                                     CONCAT13((char)(FontSize.hi >> 8),
                                              CONCAT12((char)FontSize.hi,FontSize.lo)));
              DAT_2000_d47e = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d47c = (uint16_t)uVar38;
              ovr_stgFreeTmp(stack0xfff6);
              fVar30.seg = DAT_2000_d47e;
              fVar30.ofs = DAT_2000_d47c;
            }
            DAT_2000_d47e = fVar30.seg;
            DAT_2000_d47c = fVar30.ofs;
            if (param_1 == false) {
              fVar24 = ovr_stshAllocStub();
              DAT_2000_cc87 = fVar24.seg;
              DAT_2000_cc85 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d3a6 = fVar24.seg;
              DAT_2000_d3a4 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d3a2 = fVar24.seg;
              DAT_2000_d3a0 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d39e = fVar24.seg;
              DAT_2000_d39c = (uint16_t)(fVar24.ofs);
              fVar31 = ovr_stshAllocStub();
            }
            else {
              psVar23 = ovr_grabLbm(78,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              pixels_x00236.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              pixels_x00236.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b875 = psVar23;
              puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00236,8,3,226,194,-8,-3);
              pcVar21 = ovr_stshStoreFile(puVar20);
              DAT_2000_cc87 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_cc85 = (uint16_t)(pcVar21);
              pixels_x00237.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              pixels_x00237.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00237,221,157,229,198,-221,-157);
              pcVar21 = ovr_stshStoreFile(puVar20);
              DAT_2000_d3a6 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d3a4 = (uint16_t)(pcVar21);
              pixels_x00238.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              pixels_x00238.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00238,208,195,223,199,-208,-195);
              pcVar21 = ovr_stshStoreFile(puVar20);
              DAT_2000_d3a2 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d3a0 = (uint16_t)(pcVar21);
              pixels_x00239.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              pixels_x00239.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00239,8,117,226,194,-8,-117);
              pcVar21 = ovr_stshStoreFile(puVar20);
              DAT_2000_d39e = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d39c = (uint16_t)(pcVar21);
              uVar38 = ovr_stshWrite((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)),0x300);
              DAT_2000_d386 = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d384 = (uint16_t)uVar38;
              ovr_stgFreeTmp(stack0xfff6);
              fVar31.seg = DAT_2000_d386;
              fVar31.ofs = DAT_2000_d384;
            }
            DAT_2000_d386 = fVar31.seg;
            DAT_2000_d384 = fVar31.ofs;
            if (param_1 == false) {
              LbxButton2 = ovr_stshAllocStub();
              fVar24 = ovr_stshAllocStub();
              pcVar11 = (char *)"puppetmaker" + 3;
code_r0x00083f6a:
              *(uint16_t *)&DAT_2000_d36e = fVar24.seg;
              *(uint16_t *)&DAT_2000_d36c = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d372 = fVar24.seg;
              DAT_2000_d370 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d376 = fVar24.seg;
              DAT_2000_d374 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d37a = fVar24.seg;
              DAT_2000_d378 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d37e = fVar24.seg;
              DAT_2000_d37c = (uint16_t)(fVar24.ofs);
              fVar32 = ovr_stshAllocStub();
            }
            else {
              psVar23 = ovr_grabLbm(543,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_46.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_46.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b879 = psVar23;
              fVar24 = ovr_stshRleCut(src_46,8,5,16,10);
              LbxButton2 = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(139,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_47.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_47.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b87d = psVar23;
              fVar24 = ovr_stshRleCut(src_47,16,121,57,131);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d36e = (undefined2)((ulong)pcVar21 >> 0x10);
              DAT_2000_d36c = (uint16_t)(pcVar21);
              src_48.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_48.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_48,16,134,57,144);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d372 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d370 = (uint16_t)(pcVar21);
              src_49.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_49.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_49,234,121,300,131);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d376 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d374 = (uint16_t)(pcVar21);
              src_50.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_50.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_50,234,134,300,144);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d37a = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d378 = (uint16_t)(pcVar21);
              src_51.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_51.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_51,153,121,230,131);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d37e = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d37c = (uint16_t)(pcVar21);
              src_52.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_52.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_52,153,134,230,144);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d382 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d380 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar32.seg = DAT_2000_d382;
              fVar32.ofs = (uint16_t)DAT_2000_d380;
            }
            DAT_2000_d382 = fVar32.seg;
            DAT_2000_d380 = (uint16_t)(fVar32.ofs);
            if (param_1 == false) {
              fVar24 = ovr_stshAllocStub();
              DAT_2000_cab7 = fVar24.seg;
              DAT_2000_cab5 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_cab3 = fVar24.seg;
              DAT_2000_cab1 = (uint16_t)(fVar24.ofs);
              fVar33 = ovr_stshAllocStub();
            }
            else {
              psVar23 = ovr_grabLbm(179,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_53.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_53.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b881 = psVar23;
              fVar24 = ovr_stshRleCut(src_53,94,47,108,89);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_cab7 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_cab5 = (uint16_t)(pcVar21);
              src_54.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_54.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_54,114,47,128,89);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_cab3 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_cab1 = (uint16_t)(pcVar21);
              src_55.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_55.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_55,223,8,237,50);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_caaf = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_caad = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar33.seg = DAT_2000_caaf;
              fVar33.ofs = (uint16_t)DAT_2000_caad;
            }
            DAT_2000_caaf = fVar33.seg;
            DAT_2000_caad = (uint16_t)(fVar33.ofs);
            if (param_1 == false) {
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d3d6 = fVar24.seg;
              DAT_2000_d3d4 = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d3ee = fVar24.seg;
              DAT_2000_d3ec = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d3fe = fVar24.seg;
              DAT_2000_d3fc = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d40e = fVar24.seg;
              DAT_2000_d40c = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d41e = fVar24.seg;
              DAT_2000_d41c = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d42e = fVar24.seg;
              DAT_2000_d42c = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d3d2 = fVar24.seg;
              DAT_2000_d3d0 = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d3ea = fVar24.seg;
              DAT_2000_d3e8 = (uint16_t)(fVar24.ofs);
              far_t_2000_d3e4 = ovr_stshAllocStub();
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d3da = fVar24.seg;
              DAT_2000_d3d8 = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d3f2 = fVar24.seg;
              DAT_2000_d3f0 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d402 = fVar24.seg;
              DAT_2000_d400 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d412 = fVar24.seg;
              DAT_2000_d410 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d422 = fVar24.seg;
              DAT_2000_d420 = (uint16_t)(fVar24.ofs);
              fVar34 = ovr_stshAllocStub();
            }
            else {
              psVar23 = ovr_grabLbm(158,0,0);
              unique0x1002b885 = psVar23;
              uVar38 = ovr_stshWrite(((stg_tmp_t *)psVar23)->cmap,0x300);
              DAT_2000_d3d6 = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d3d4 = (uint16_t)uVar38;
              src_56.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_56.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_56,0,0,319,80);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d3ee = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d3ec = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(159,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_57.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_57.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b889 = psVar23;
              fVar24 = ovr_stshRleCut(src_57,0,0,219,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d3fe = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d3fc = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(159,220,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_58.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_58.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b88d = psVar23;
              fVar24 = ovr_stshRleCut(src_58,0,0,219,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d40e = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d40c = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(160,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_59.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_59.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b891 = psVar23;
              fVar24 = ovr_stshRleCut(src_59,0,0,279,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d41e = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d41c = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(160,280,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_60.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_60.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b895 = psVar23;
              fVar24 = ovr_stshRleCut(src_60,0,0,279,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d42e = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d42c = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(161,0,0);
              unique0x1002b899 = psVar23;
              uVar38 = ovr_stshWrite(((stg_tmp_t *)psVar23)->cmap,0x300);
              DAT_2000_d3d2 = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d3d0 = (uint16_t)uVar38;
              src_61.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_61.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_61,0,144,319,199);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d3ea = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d3e8 = (uint16_t)(pcVar21);
              src_62.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_62.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_62,0,0,47,10);
              far_t_2000_d3e4 = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(412,0,0);
              unique0x1002b89d = psVar23;
              uVar38 = ovr_stshWrite(((stg_tmp_t *)psVar23)->cmap,0x300);
              DAT_2000_d3da = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d3d8 = (uint16_t)uVar38;
              src_63.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_63.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_63,0,0,319,80);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d3f2 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d3f0 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(414,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_64.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_64.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b8a1 = psVar23;
              fVar24 = ovr_stshRleCut(src_64,0,0,219,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d402 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d400 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(414,220,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_65.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_65.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b8a5 = psVar23;
              fVar24 = ovr_stshRleCut(src_65,0,0,219,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d412 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d410 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(413,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_66.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_66.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b8a9 = psVar23;
              fVar24 = ovr_stshRleCut(src_66,0,0,279,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d422 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d420 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(413,280,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_67.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_67.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b8ad = psVar23;
              fVar24 = ovr_stshRleCut(src_67,0,0,279,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d432 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d430 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar34.seg = DAT_2000_d432;
              fVar34.ofs = (uint16_t)DAT_2000_d430;
            }
            DAT_2000_d432 = fVar34.seg;
            DAT_2000_d430 = (uint16_t)(fVar34.ofs);
            if (param_1 == false) {
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d3de = fVar24.seg;
              DAT_2000_d3dc = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d3f6 = fVar24.seg;
              DAT_2000_d3f4 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d406 = fVar24.seg;
              DAT_2000_d404 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d416 = fVar24.seg;
              DAT_2000_d414 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d426 = fVar24.seg;
              DAT_2000_d424 = (uint16_t)(fVar24.ofs);
              fVar35 = ovr_stshAllocStub();
            }
            else {
              psVar23 = ovr_grabLbm(422,0,0);
              unique0x1002b8b1 = psVar23;
              uVar38 = ovr_stshWrite(((stg_tmp_t *)psVar23)->cmap,0x300);
              DAT_2000_d3de = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d3dc = (uint16_t)uVar38;
              src_68.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_68.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_68,0,0,319,113);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d3f6 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d3f4 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(421,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_69.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_69.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b8b5 = psVar23;
              fVar24 = ovr_stshRleCut(src_69,0,0,219,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d406 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d404 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(421,220,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_70.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_70.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b8b9 = psVar23;
              fVar24 = ovr_stshRleCut(src_70,0,0,219,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d416 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d414 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(420,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_71.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_71.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b8bd = psVar23;
              fVar24 = ovr_stshRleCut(src_71,0,0,279,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d426 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d424 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(420,280,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_72.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_72.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b8c1 = psVar23;
              fVar24 = ovr_stshRleCut(src_72,0,0,279,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d436 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d434 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar35.seg = DAT_2000_d436;
              fVar35.ofs = (uint16_t)DAT_2000_d434;
            }
            DAT_2000_d436 = fVar35.seg;
            DAT_2000_d434 = (uint16_t)(fVar35.ofs);
            if (param_1 == false) {
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d3e2 = fVar24.seg;
              DAT_2000_d3e0 = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d3fa = fVar24.seg;
              DAT_2000_d3f8 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d40a = fVar24.seg;
              DAT_2000_d408 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d41a = fVar24.seg;
              DAT_2000_d418 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d42a = fVar24.seg;
              DAT_2000_d428 = (uint16_t)(fVar24.ofs);
              fVar36 = ovr_stshAllocStub();
            }
            else {
              psVar23 = ovr_grabLbm(437,0,0);
              unique0x1002b8c5 = psVar23;
              uVar38 = ovr_stshWrite(((stg_tmp_t *)psVar23)->cmap,0x300);
              DAT_2000_d3e2 = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d3e0 = (uint16_t)uVar38;
              src_73.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_73.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_73,0,0,319,113);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d3fa = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d3f8 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(438,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_74.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_74.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b8c9 = psVar23;
              fVar24 = ovr_stshRleCut(src_74,0,0,219,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d40a = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d408 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(438,220,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_75.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_75.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b8cd = psVar23;
              fVar24 = ovr_stshRleCut(src_75,0,0,219,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d41a = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d418 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(439,0,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_76.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_76.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b8d1 = psVar23;
              fVar24 = ovr_stshRleCut(src_76,0,0,279,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d42a = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d428 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(439,280,0);
              uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
              src_77.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
              src_77.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
              unique0x1002b8d5 = psVar23;
              fVar24 = ovr_stshRleCut(src_77,0,0,279,143);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d43a = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d438 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar36.seg = DAT_2000_d43a;
              fVar36.ofs = (uint16_t)DAT_2000_d438;
            }
            DAT_2000_d43a = fVar36.seg;
            DAT_2000_d438 = (uint16_t)(fVar36.ofs);
            if (param_1 == false) {
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d04a = fVar24.seg;
              DAT_2000_d048 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d026 = fVar24.seg;
              DAT_2000_d024 = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d04e = fVar24.seg;
              DAT_2000_d04c = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d052 = fVar24.seg;
              DAT_2000_d050 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d02a = fVar24.seg;
              DAT_2000_d028 = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d056 = fVar24.seg;
              DAT_2000_d054 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d05a = fVar24.seg;
              DAT_2000_d058 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d02e = fVar24.seg;
              DAT_2000_d02c = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d05e = fVar24.seg;
              DAT_2000_d05c = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d062 = fVar24.seg;
              DAT_2000_d060 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d032 = fVar24.seg;
              DAT_2000_d030 = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d066 = fVar24.seg;
              DAT_2000_d064 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d06a = fVar24.seg;
              DAT_2000_d068 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d036 = fVar24.seg;
              DAT_2000_d034 = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d06e = fVar24.seg;
              DAT_2000_d06c = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d072 = fVar24.seg;
              DAT_2000_d070 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d03a = fVar24.seg;
              DAT_2000_d038 = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d076 = fVar24.seg;
              DAT_2000_d074 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d07a = fVar24.seg;
              DAT_2000_d078 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d03e = fVar24.seg;
              DAT_2000_d03c = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d07e = fVar24.seg;
              DAT_2000_d07c = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d082 = fVar24.seg;
              DAT_2000_d080 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d042 = fVar24.seg;
              DAT_2000_d040 = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d086 = fVar24.seg;
              DAT_2000_d084 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d08a = fVar24.seg;
              DAT_2000_d088 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d046 = fVar24.seg;
              DAT_2000_d044 = fVar24.ofs;
              fVar37 = ovr_stshAllocStub();
            }
            else {
LAB_81b9_2fc9:
              DAT_2000_d43a = fVar36.seg;
              DAT_2000_d438 = (uint16_t)(fVar36.ofs);
              psVar23 = ovr_grabLbm(305,0,0);
              unique0x1002b8d9 = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_78.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_78.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_78,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d04a = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d048 = (uint16_t)(pcVar21);
              uVar38 = ovr_stshWrite((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x1e0,0x90);
              DAT_2000_d026 = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d024 = (uint16_t)uVar38;
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(305,320,0);
              unique0x1002b8dd = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_79.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_79.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_79,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d04e = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d04c = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(328,0,0);
              unique0x1002b8e1 = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_80.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_80.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_80,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d052 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d050 = (uint16_t)(pcVar21);
              uVar38 = ovr_stshWrite((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x1e0,0x90);
              DAT_2000_d02a = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d028 = (uint16_t)uVar38;
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(328,320,0);
              unique0x1002b8e5 = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_81.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_81.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_81,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d056 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d054 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(331,0,0);
              unique0x1002b8e9 = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_82.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_82.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_82,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d05a = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d058 = (uint16_t)(pcVar21);
              uVar38 = ovr_stshWrite((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x1e0,0x90);
              DAT_2000_d02e = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d02c = (uint16_t)uVar38;
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(331,320,0);
              unique0x1002b8ed = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_83.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_83.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_83,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d05e = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d05c = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(307,0,0);
              unique0x1002b8f1 = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_84.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_84.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_84,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d062 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d060 = (uint16_t)(pcVar21);
              uVar38 = ovr_stshWrite((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x1e0,0x90);
              DAT_2000_d032 = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d030 = (uint16_t)uVar38;
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(307,320,0);
              unique0x1002b8f5 = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_85.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_85.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_85,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d066 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d064 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(329,0,0);
              unique0x1002b8f9 = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_86.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_86.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_86,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d06a = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d068 = (uint16_t)(pcVar21);
              uVar38 = ovr_stshWrite((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x1e0,0x90);
              DAT_2000_d036 = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d034 = (uint16_t)uVar38;
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(329,320,0);
              unique0x1002b8fd = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_87.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_87.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_87,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d06e = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d06c = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(332,0,0);
              unique0x1002b901 = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_88.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_88.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_88,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d072 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d070 = (uint16_t)(pcVar21);
              uVar38 = ovr_stshWrite((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x1e0,0x90);
              DAT_2000_d03a = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d038 = (uint16_t)uVar38;
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(332,320,0);
              unique0x1002b905 = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_89.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_89.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_89,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d076 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d074 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(306,0,0);
              unique0x1002b909 = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_90.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_90.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_90,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d07a = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d078 = (uint16_t)(pcVar21);
              uVar38 = ovr_stshWrite((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x1e0,0x90);
              DAT_2000_d03e = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d03c = (uint16_t)uVar38;
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(306,320,0);
              unique0x1002b90d = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_91.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_91.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_91,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d07e = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d07c = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(330,0,0);
              unique0x1002b911 = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_92.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_92.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_92,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d082 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d080 = (uint16_t)(pcVar21);
              uVar38 = ovr_stshWrite((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x1e0,0x90);
              DAT_2000_d042 = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d040 = (uint16_t)uVar38;
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(330,320,0);
              unique0x1002b915 = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_93.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_93.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_93,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d086 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d084 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(333,0,0);
              unique0x1002b919 = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_94.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_94.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_94,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d08a = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d088 = (uint16_t)(pcVar21);
              uVar38 = ovr_stshWrite((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x1e0,0x90);
              DAT_2000_d046 = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d044 = (uint16_t)uVar38;
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(333,320,0);
              unique0x1002b91d = psVar23;
              ovr_stshUniqueColorsRemap(psVar23);
              src_95.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_95.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_95,0,0,319,59);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d08e = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d08c = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar37.seg = DAT_2000_d08e;
              fVar37.ofs = (uint16_t)DAT_2000_d08c;
            }
            DAT_2000_d08e = fVar37.seg;
            DAT_2000_d08c = (uint16_t)(fVar37.ofs);
            ovr_stshInitAudioAssets(param_1);
            ovr_stshLoadAudioDrivers(param_1);
            ovr_stshInitSprites(param_1);
            stshInitTxtFiles(param_1);
            if (param_1 == false) {
              fVar24 = ovr_stshAllocStub();
            }
            else {
              fVar24 = ovr_stshStoreFile_2((char *)StshNames[0x19f],0);
            }
            DAT_2000_d486 = fVar24.seg;
            DAT_2000_d484 = fVar24.ofs;
            if (param_1 == false) {
              fVar24 = ovr_stshAllocStub();
            }
            else {
              fVar24 = ovr_stshStoreFile_2((char *)"bolt12.fli",0);
            }
            DAT_2000_d482 = fVar24.seg;
            DAT_2000_d480 = fVar24.ofs;
            if (param_1 == false) {
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d45a = fVar24.seg;
              DAT_2000_d458 = fVar24.ofs;
              fVar39 = ovr_stshAllocStub();
            }
            else {
              psVar23 = ovr_grabLbm(417,0,0);
              unique0x1002b921 = psVar23;
              uVar38 = ovr_stshWrite(((stg_tmp_t *)psVar23)->cmap,0x300);
              DAT_2000_d45a = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d458 = (uint16_t)uVar38;
              src_96.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_96.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_96,0,0,319,199);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d476 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d474 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar39.seg = DAT_2000_d476;
              fVar39.ofs = (uint16_t)DAT_2000_d474;
            }
            DAT_2000_d476 = fVar39.seg;
            DAT_2000_d474 = (uint16_t)(fVar39.ofs);
            if (param_1 == false) {
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d43e = fVar24.seg;
              DAT_2000_d43c = fVar24.ofs;
              fVar40 = ovr_stshAllocStub();
            }
            else {
              psVar23 = ovr_grabLbm(542,0,0);
              unique0x1002b925 = psVar23;
              uVar38 = ovr_stshWrite(((stg_tmp_t *)psVar23)->cmap,0x300);
              DAT_2000_d43e = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d43c = (uint16_t)uVar38;
              src_97.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_97.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_97,0,0,319,144);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d45e = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d45c = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar40.seg = DAT_2000_d45e;
              fVar40.ofs = (uint16_t)DAT_2000_d45c;
            }
            DAT_2000_d45e = fVar40.seg;
            DAT_2000_d45c = (uint16_t)(fVar40.ofs);
            if (param_1 == false) {
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d442 = fVar24.seg;
              DAT_2000_d440 = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d462 = fVar24.seg;
              DAT_2000_d460 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d446 = fVar24.seg;
              DAT_2000_d444 = fVar24.ofs;
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d466 = fVar24.seg;
              DAT_2000_d464 = (uint16_t)(fVar24.ofs);
              fVar24 = ovr_stshAllocStub();
              DAT_2000_d44a = fVar24.seg;
              DAT_2000_d448 = fVar24.ofs;
              fVar41 = ovr_stshAllocStub();
            }
            else {
              psVar23 = ovr_grabLbm(539,0,0);
              unique0x1002b929 = psVar23;
              uVar38 = ovr_stshWrite(((stg_tmp_t *)psVar23)->cmap,0x300);
              DAT_2000_d442 = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d440 = (uint16_t)uVar38;
              src_98.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_98.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_98,0,0,319,199);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d462 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d460 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(540,0,0);
              unique0x1002b92d = psVar23;
              uVar38 = ovr_stshWrite(((stg_tmp_t *)psVar23)->cmap,0x300);
              DAT_2000_d446 = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d444 = (uint16_t)uVar38;
              src_99.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_99.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_99,0,0,319,199);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d466 = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d464 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              psVar23 = ovr_grabLbm(541,0,0);
              unique0x1002b931 = psVar23;
              uVar38 = ovr_stshWrite(((stg_tmp_t *)psVar23)->cmap,0x300);
              DAT_2000_d44a = (uint16_t)(uVar38 >> 0x10);
              DAT_2000_d448 = (uint16_t)uVar38;
              src_x00100.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->seg;
              src_x00100.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + 0x300))->ofs;
              fVar24 = ovr_stshRleCut(src_x00100,0,0,319,199);
              pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
              DAT_2000_d46a = (uint16_t)((ulong)pcVar21 >> 0x10);
              DAT_2000_d468 = (uint16_t)(pcVar21);
              ovr_stgFreeTmp(stack0xfff6);
              fVar41.seg = DAT_2000_d46a;
              fVar41.ofs = (uint16_t)DAT_2000_d468;
            }
            DAT_2000_d46a = fVar41.seg;
            DAT_2000_d468 = (uint16_t)(fVar41.ofs);
            if (param_1 == false) {
              fVar24 = ovr_stshAllocStub();
            }
            else {
              fVar24 = ovr_stshStoreFile_2((char *)"save.999",0);
            }
            DAT_2000_d1b2 = fVar24.seg;
            DAT_2000_d1b0 = fVar24.ofs;
            return;
          case 4:
            *(char *)(iVar8 + 1) = *(char *)(iVar8 + 1) + (0x44 < bStack_1b);
            fVar36.seg = DAT_2000_d43a;
            fVar36.ofs = (uint16_t)DAT_2000_d438;
            goto LAB_81b9_2fc9;
          case 5:
            goto code_r0x00083f6a;
          case 6:
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          case 7:
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
        } while( true );
      }
      pcVar11 = (char *)ovr_OVC15_4207_1c16((char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x10e),
                                            (char)*(undefined2 *)
                                                   ((uint)(*(uint8_t *)((uint8_t *)&(uStack_22) + 1)) * 0x27 + 0x110),
                                            (char)-unaff_DI);
      pcVar11 = ovr_fmVsprintf((char *)"%s: Costs %d gold. Repairs buildings at season changes.",
                               pcVar11);
      uVar44 = 0;
      strcpy(local_2ca,pcVar11);
    }
  }
  LOCK();
  *(undefined2 *)(&stack0xfffe + unaff_DI) = unaff_SI;
  UNLOCK();
  while (fStack_6.seg = fStack_6.seg + 1, (int)fStack_6.seg < 0xc) {
    if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(uVar44);
      *(int *)((undefined *)&DAT_2000_d135 + fStack_6.seg * 4) = (int)((ulong)uVar22 >> 0x10);
      *(int *)((undefined *)&DAT_2000_d133 + fStack_6.seg * 4) = (int)uVar22;
    }
    else {
      src.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      src.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      fVar24 = ovr_stshRleCut(src,fStack_6.seg * 0x17 + 6,21,fStack_6.seg * 0x17 + 0x1b,62);
      uVar44 = 0x4c;
      pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
      *(int *)((undefined *)&DAT_2000_d135 + fStack_6.seg * 4) = (int)((ulong)pcVar21 >> 0x10);
      *(cte_t **)((undefined *)&DAT_2000_d133 + fStack_6.seg * 4) = (cte_t *)pcVar21;
    }
  }
  for (fStack_6.seg = 0; (int)fStack_6.seg < 6; fStack_6.seg = fStack_6.seg + 1) {
    if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(uVar44);
      ((undefined2 *)&DAT_2000_d11d)[fStack_6.seg * 2] = (int)((ulong)uVar22 >> 0x10);
      ((undefined2 *)&DAT_2000_d11b)[fStack_6.seg * 2] = (int)uVar22;
    }
    else {
      src_00.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      src_00.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      fVar24 = ovr_stshRleCut(src_00,fStack_6.seg * 0x17 + 9,72,fStack_6.seg * 0x17 + 0x16,75);
      uVar44 = 0x4c;
      pcVar21 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs));
      ((undefined2 *)&DAT_2000_d11d)[fStack_6.seg * 2] = (int)((ulong)pcVar21 >> 0x10);
      ((undefined2 *)&DAT_2000_d11b)[fStack_6.seg * 2] = (uint16_t)(pcVar21);
    }
  }
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[4] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar44)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[7] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar44)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[10] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar44)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[4] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar44)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[7] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar44)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[10] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar44)));
    stshStubifyBld(4);
    stshStubifyBld(7);
    stshStubifyBld(10);
    stshStubifyBld(0xd);
    stshStubifyBld(0x10);
    stshStubifyBld(0x13);
    stshStubifyBld(0x16);
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x4c] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar44)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x4f] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar44)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x52] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar44)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x4c] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar44)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x4f] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar44)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x52] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar44)));
  }
  else {
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13(SUB21((*(uint16_t *)((uint8_t *)&(auStack_c) + 2)),1),CONCAT12((char)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)),(*(uint16_t *)((uint8_t *)&(auStack_c))))
                           ));
    auStack_c = (undefined1  [4])ovr_grabLbmTR(80);
    uVar18 = (undefined2)((ulong)auStack_c >> 0x10);
    src_01.seg = (SUB42(auStack_c,0)->aptr).seg;
    src_01.ofs = (&SUB42(auStack_c,0)->aptr)->ofs;
    fVar24 = ovr_stshRleCut(src_01,40,173,50,179);
    BldGfxNormal[4] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_02.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_02.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_02,140,108,150,114);
    BldGfxNormal[7] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_03.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_03.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_03,240,43,252,49);
    BldGfxNormal[10] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_04.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_04.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_04,40,108,50,114);
    BldGfxRuin[4] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_05.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_05.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_05,140,173,150,179);
    BldGfxRuin[7] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_06.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_06.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_06,240,108,252,114);
    BldGfxRuin[10] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(387);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_00.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_00.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_00,9,130,97,194,11,-5);
    BldGfxNormal[0xc] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_01.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_01.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_01,100,130,199,194,11,-5);
    BldGfxNormal[0xd] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_02.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_02.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_02,204,130,292,194,11,-5);
    BldGfxNormal[0xe] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_03.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_03.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_03,9,65,97,129,11,-5);
    BldGfxNormal[0xf] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_04.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_04.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_04,100,65,199,129,11,-5);
    BldGfxNormal[0x10] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_05.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_05.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_05,204,65,292,129,11,-5);
    BldGfxNormal[0x11] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_06.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_06.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_06,9,0,97,64,11,-5);
    BldGfxNormal[0x12] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_07.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_07.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_07,108,0,191,64,11,-5);
    BldGfxNormal[0x13] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_08.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_08.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_08,204,0,292,64,11,-5);
    BldGfxNormal[0x14] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(485);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_09.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_09.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_09,9,130,97,194,11,-5);
    BldGfxRuin[0xc] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_10.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_10.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_10,100,130,199,194,11,-5);
    BldGfxRuin[0xd] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_11.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_11.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_11,204,130,292,194,11,-5);
    BldGfxRuin[0xe] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_12.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_12.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_12,9,65,97,129,11,-5);
    BldGfxRuin[0xf] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_13.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_13.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_13,100,65,199,129,11,-5);
    BldGfxRuin[0x10] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_14.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_14.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_14,204,65,292,129,11,-5);
    BldGfxRuin[0x11] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_15.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_15.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_15,9,0,97,64,11,-5);
    BldGfxRuin[0x12] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_16.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_16.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_16,108,0,191,64,11,-5);
    BldGfxRuin[0x13] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_17.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_17.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_17,204,0,292,64,11,-5);
    BldGfxRuin[0x14] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(392);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_18.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_18.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_18,0,130,99,194,26,-1);
    BldGfxNormal[0x15] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_19.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_19.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_19,100,130,199,194,26,-1);
    BldGfxNormal[0x16] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_20.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_20.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_20,200,130,299,194,26,-1);
    BldGfxNormal[0x17] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_21.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_21.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_21,0,65,99,129,26,-1);
    BldGfxNormal[0x18] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_22.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_22.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_22,100,65,199,129,26,-1);
    BldGfxNormal[0x19] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_23.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_23.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_23,200,65,299,129,26,-1);
    BldGfxNormal[0x1a] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_24.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_24.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_24,0,0,99,64,26,7);
    BldGfxNormal[0x1b] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_25.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_25.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_25,100,0,199,64,26,7);
    BldGfxNormal[0x1c] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_26.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_26.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_26,200,0,299,64,26,7);
    BldGfxNormal[0x1d] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(393);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_27.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_27.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_27,0,130,99,194,26,-1);
    BldGfxRuin[0x15] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_28.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_28.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_28,100,130,199,194,26,-1);
    BldGfxRuin[0x16] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_29.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_29.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_29,200,130,299,194,26,-1);
    BldGfxRuin[0x17] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_30.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_30.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_30,0,65,99,129,26,-1);
    BldGfxRuin[0x18] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_31.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_31.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_31,100,65,199,129,26,-1);
    BldGfxRuin[0x19] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_32.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_32.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_32,200,65,299,129,26,-1);
    BldGfxRuin[0x1a] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_33.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_33.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_33,0,0,99,64,26,7);
    BldGfxRuin[0x1b] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_34.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_34.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_34,100,0,199,64,26,7);
    BldGfxRuin[0x1c] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_35.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_35.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_35,200,0,299,64,26,7);
    BldGfxRuin[0x1d] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(56);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_36.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_36.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_36,6,151,91,180,0,-25);
    BldGfxNormal[0x1e] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_37.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_37.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_37,110,151,185,180,0,-25);
    BldGfxNormal[0x1f] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_38.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_38.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_38,216,151,299,180,0,-25);
    BldGfxNormal[0x20] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_39.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_39.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_39,6,72,91,115,0,-11);
    BldGfxNormal[0x21] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_40.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_40.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_40,110,72,185,115,0,-11);
    BldGfxNormal[0x22] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_41.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_41.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_41,216,72,299,115,0,-11);
    BldGfxNormal[0x23] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_42.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_42.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_42,6,6,91,59,0,-1);
    BldGfxNormal[0x24] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_43.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_43.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_43,110,6,185,59,0,-1);
    BldGfxNormal[0x25] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_44.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_44.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_44,216,6,299,59,0,-1);
    BldGfxNormal[0x26] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(444);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_45.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_45.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_45,6,151,91,180,0,-25);
    BldGfxRuin[0x1e] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_46.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_46.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_46,110,151,185,180,0,-25);
    BldGfxRuin[0x1f] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_47.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_47.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_47,216,151,299,180,0,-25);
    BldGfxRuin[0x20] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_48.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_48.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_48,6,72,91,115,0,-11);
    BldGfxRuin[0x21] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_49.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_49.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_49,110,72,185,115,0,-11);
    BldGfxRuin[0x22] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_50.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_50.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_50,216,72,299,115,0,-11);
    BldGfxRuin[0x23] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_51.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_51.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_51,6,6,91,59,0,-1);
    BldGfxRuin[0x24] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_52.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_52.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_52,110,6,185,59,0,-1);
    BldGfxRuin[0x25] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_53.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_53.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_53,216,6,299,59,0,-1);
    BldGfxRuin[0x26] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(447);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_54.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_54.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_54,2,130,89,180,0,-3);
    BldGfxNormal[0x27] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_55.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_55.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_55,108,130,191,180,0,-3);
    BldGfxNormal[0x28] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_56.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_56.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_56,212,130,298,180,0,-3);
    BldGfxNormal[0x29] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_57.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_57.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_57,2,65,89,115,0,-3);
    BldGfxNormal[0x2a] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_58.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_58.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_58,108,65,191,115,0,-3);
    BldGfxNormal[0x2b] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_59.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_59.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_59,212,65,298,115,0,-3);
    BldGfxNormal[0x2c] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_60.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_60.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_60,2,9,89,59,0,-3);
    BldGfxNormal[0x2d] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_61.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_61.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_61,108,9,191,59,0,-3);
    BldGfxNormal[0x2e] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_62.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_62.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_62,212,9,298,59,0,-3);
    BldGfxNormal[0x2f] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(448);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_63.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_63.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_63,2,130,89,180,0,-3);
    BldGfxRuin[0x27] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_64.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_64.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_64,108,130,191,180,0,-3);
    BldGfxRuin[0x28] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_65.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_65.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_65,212,130,298,180,0,-3);
    BldGfxRuin[0x29] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_66.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_66.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_66,2,65,89,115,0,-3);
    BldGfxRuin[0x2a] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_67.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_67.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_67,108,65,191,115,0,-3);
    BldGfxRuin[0x2b] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_68.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_68.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_68,212,65,298,115,0,-3);
    BldGfxRuin[0x2c] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_69.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_69.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_69,2,9,89,59,0,-3);
    BldGfxRuin[0x2d] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_70.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_70.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_70,108,9,191,59,0,-3);
    BldGfxRuin[0x2e] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_71.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_71.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_71,212,9,298,59,0,-3);
    BldGfxRuin[0x2f] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    ovr_grabBldLbm(115,116,0x10);
    ovr_grabBldLbm(423,446,0x13);
    ovr_grabBldLbm(312,313,0x16);
    psVar23 = ovr_grabLbmTR(459);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_72.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_72.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_72,9,68,92,182,-4,56);
    BldGfxNormal[0x4c] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_73.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_73.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_73,108,68,191,182,-3,56);
    BldGfxNormal[0x4f] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_74.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_74.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_74,208,68,291,182,-1,56);
    BldGfxNormal[0x52] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(460);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_75.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_75.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_75,9,68,92,182,-4,56);
    BldGfxRuin[0x4c] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_76.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_76.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_76,108,68,191,182,-3,56);
    BldGfxRuin[0x4f] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_77.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_77.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_77,208,68,291,182,-1,56);
    BldGfxRuin[0x52] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  ovr_stshStubifyCopy1to0(0x19);
  auVar19 = auStack_c;
  if (param_1 != false) {
    auVar19 = (undefined1  [4])ovr_grabLbmTR(172);
  }
  fStack_6.seg = 0;
  while( true ) {
    (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
    (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
    auStack_c = auVar19;
    if (2 < (int)fStack_6.seg) break;
    if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[1].seg + (fStack_6.seg + 0x1c) * 0xc) =
           (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 1) + (fStack_6.seg + 0x1c) * 3)->ofs = (uint16_t)uVar22;
      auVar19 = auStack_c;
    }
    else {
      pixels_78.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_78.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_78,fStack_6.seg * 100 + 0x14,33,fStack_6.seg * 100 + 99,116,
                                 8,28);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[1].seg + (fStack_6.seg + 0x1c) * 0xc) =
           (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 1) + (fStack_6.seg + 0x1c) * 3)->ofs = (uint16_t)(cte_t *)pcVar21;
      auVar19 = auStack_c;
    }
    uVar15 = ((far_t *)(BldGfxNormal + 1) + (fStack_6.seg + 0x1c) * 3)->ofs;
    *(undefined2 *)((int)&BldGfxNormal[0].seg + (fStack_6.seg + 0x1c) * 0xc) =
         *(undefined2 *)((int)&BldGfxNormal[1].seg + (fStack_6.seg + 0x1c) * 0xc);
    ((far_t *)BldGfxNormal + (fStack_6.seg + 0x1c) * 3)->ofs = uVar15;
    uVar15 = ((far_t *)(BldGfxNormal + 1) + (fStack_6.seg + 0x1c) * 3)->ofs;
    *(undefined2 *)((int)&BldGfxNormal[2].seg + (fStack_6.seg + 0x1c) * 0xc) =
         *(undefined2 *)((int)&BldGfxNormal[1].seg + (fStack_6.seg + 0x1c) * 0xc);
    ((far_t *)(BldGfxNormal + 2) + (fStack_6.seg + 0x1c) * 3)->ofs = uVar15;
    fStack_6.seg = fStack_6.seg + 1;
  }
  if (param_1 != false) {
    ovr_stgFreeTmp((stg_tmp_t *)auVar19);
    auVar19 = (undefined1  [4])ovr_grabLbmTR(175);
  }
  fStack_6.seg = 0;
  while( true ) {
    (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
    (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
    auStack_c = auVar19;
    if (2 < (int)fStack_6.seg) break;
    if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxRuin[1].seg + (fStack_6.seg + 0x1c) * 0xc) =
           (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxRuin + 1) + (fStack_6.seg + 0x1c) * 3)->ofs = (uint16_t)uVar22;
      auVar19 = auStack_c;
    }
    else {
      pixels_79.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_79.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_79,fStack_6.seg * 100 + 0x14,33,fStack_6.seg * 100 + 99,116,
                                 8,28);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxRuin[1].seg + (fStack_6.seg + 0x1c) * 0xc) =
           (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxRuin + 1) + (fStack_6.seg + 0x1c) * 3)->ofs = (uint16_t)(cte_t *)pcVar21;
      auVar19 = auStack_c;
    }
    uVar15 = ((far_t *)(BldGfxRuin + 1) + (fStack_6.seg + 0x1c) * 3)->ofs;
    *(undefined2 *)((int)&BldGfxRuin[0].seg + (fStack_6.seg + 0x1c) * 0xc) =
         *(undefined2 *)((int)&BldGfxRuin[1].seg + (fStack_6.seg + 0x1c) * 0xc);
    ((far_t *)BldGfxRuin + (fStack_6.seg + 0x1c) * 3)->ofs = uVar15;
    uVar15 = ((far_t *)(BldGfxRuin + 1) + (fStack_6.seg + 0x1c) * 3)->ofs;
    *(undefined2 *)((int)&BldGfxRuin[2].seg + (fStack_6.seg + 0x1c) * 0xc) =
         *(undefined2 *)((int)&BldGfxRuin[1].seg + (fStack_6.seg + 0x1c) * 0xc);
    ((far_t *)(BldGfxRuin + 2) + (fStack_6.seg + 0x1c) * 3)->ofs = uVar15;
    fStack_6.seg = fStack_6.seg + 1;
  }
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x5e] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x61] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[100] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x5e] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x61] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[100] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    ovr_stgFreeTmp((stg_tmp_t *)auVar19);
    psVar23 = ovr_grabLbmTR(174);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_80.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_80.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_80,100,130,199,194,26,-4);
    BldGfxNormal[0x5e] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_81.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_81.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_81,100,65,199,129,26,-4);
    BldGfxNormal[0x61] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_82.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_82.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_82,100,0,199,64,26,-4);
    BldGfxNormal[100] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(176);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_83.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_83.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_83,100,130,199,194,26,-4);
    BldGfxRuin[0x5e] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_84.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_84.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_84,100,65,199,129,26,-4);
    BldGfxRuin[0x61] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_85.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_85.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_85,100,0,199,64,26,-4);
    BldGfxRuin[100] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  ovr_stshStubifyCopy1to0(0x1f);
  if (param_1 == false) {
    stshStubifyBld(0x22);
    stshStubifyBld(0x25);
    stshStubifyBld(0x28);
    stshStubifyBld(0x2b);
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x8b] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x8e] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x91] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x94] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x97] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x9a] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    ovr_grabBldLbm(449,450,0x22);
    ovr_grabBldLbm(390,391,0x25);
    ovr_grabBldLbm(389,442,0x28);
    psVar23 = ovr_grabLbmTR(394);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_86.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_86.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_86,6,151,91,180,-10,-26);
    BldGfxNormal[0x81] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_87.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_87.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_87,110,151,185,180,-10,-26);
    BldGfxNormal[0x82] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_88.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_88.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_88,216,151,299,180,-10,-26);
    BldGfxNormal[0x83] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_89.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_89.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_89,6,72,91,115,-10,-12);
    BldGfxNormal[0x84] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_90.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_90.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_90,110,72,185,115,-10,-12);
    BldGfxNormal[0x85] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_91.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_91.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_91,216,72,299,115,-10,-12);
    BldGfxNormal[0x86] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_92.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_92.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_92,6,6,91,59,-10,-4);
    BldGfxNormal[0x87] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_93.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_93.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_93,110,6,185,59,-10,-4);
    BldGfxNormal[0x88] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_94.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_94.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_94,216,6,299,59,-10,-4);
    BldGfxNormal[0x89] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(443);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_95.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_95.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_95,6,151,91,180,-10,-26);
    BldGfxRuin[0x81] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_96.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_96.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_96,110,151,185,180,-10,-26);
    BldGfxRuin[0x82] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_97.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_97.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_97,216,151,299,180,-10,-26);
    BldGfxRuin[0x83] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_98.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_98.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_98,6,72,91,115,-10,-12);
    BldGfxRuin[0x84] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_99.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_99.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_99,110,72,185,115,-10,-12);
    BldGfxRuin[0x85] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00100.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00100.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00100,216,72,299,115,-10,-12);
    BldGfxRuin[0x86] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00101.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00101.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00101,6,6,91,59,-10,-4);
    BldGfxRuin[0x87] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00102.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00102.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00102,110,6,185,59,-10,-4);
    BldGfxRuin[0x88] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00103.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00103.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00103,216,6,299,59,-10,-4);
    BldGfxRuin[0x89] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(173);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00104.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00104.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00104,0,130,99,194,26,0);
    BldGfxNormal[0x8b] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00105.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00105.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00105,100,130,199,194,26,0);
    BldGfxNormal[0x8e] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00106.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00106.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00106,200,130,299,194,26,0);
    BldGfxNormal[0x91] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00107.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00107.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00107,0,65,99,129,26,0);
    BldGfxNormal[0x94] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00108.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00108.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00108,100,65,199,129,26,0);
    BldGfxNormal[0x97] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00109.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00109.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00109,200,65,299,129,26,0);
    BldGfxNormal[0x9a] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  ovr_stshStubifyCopy1to0(0x2e);
  ovr_stshStubifyCopy1to0(0x31);
  if (param_1 == false) {
    stshStubifyBld(0x34);
    stshStubifyBld(0x37);
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0xaf] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0xb2] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0xb5] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0xaf] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0xb2] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0xb5] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    ovr_grabBldLbm(314,315,0x34);
    ovr_grabBldLbm(316,317,0x37);
    psVar23 = ovr_grabLbmTR(320);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00110.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00110.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00110,58,141,134,199,-4,0);
    BldGfxNormal[0xaf] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00111.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00111.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00111,58,84,134,142,-4,0);
    BldGfxNormal[0xb2] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00112.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00112.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00112,58,25,134,83,-4,0);
    BldGfxNormal[0xb5] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(321);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00113.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00113.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00113,58,141,134,199,-4,0);
    BldGfxRuin[0xaf] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00114.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00114.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00114,58,84,134,142,-4,0);
    BldGfxRuin[0xb2] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00115.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00115.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00115,58,25,134,83,-4,0);
    BldGfxRuin[0xb5] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  ovr_stshStubifyCopy1to0(0x3a);
  auVar19 = auStack_c;
  if (param_1 != false) {
    auVar19 = (undefined1  [4])ovr_grabLbmTR(500);
  }
  iVar16 = 0;
  while( true ) {
    (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
    (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
    auStack_c = auVar19;
    if (3 < iVar16) break;
    if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xb7].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb7) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xb8].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb8) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xb9].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb9) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
      auVar19 = auStack_c;
    }
    else {
      pixels_x00116.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00116.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00116,iVar16 * 0x30 + 3,0,iVar16 * 0x30 + 0x32,54,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xb7].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb7) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      pixels_x00117.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00117.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00117,iVar16 * 0x30 + 3,62,iVar16 * 0x30 + 0x32,116,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xb8].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb8) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      pixels_x00118.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00118.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00118,iVar16 * 0x30 + 3,62,iVar16 * 0x30 + 0x32,116,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xb9].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb9) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      auVar19 = auStack_c;
    }
    iVar16 = iVar16 + 1;
  }
  if (param_1 != false) {
    ovr_stgFreeTmp((stg_tmp_t *)auVar19);
    auVar19 = (undefined1  [4])ovr_grabLbmTR(501);
  }
  iVar16 = 0;
  while( true ) {
    (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
    (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
    auStack_c = auVar19;
    if (3 < iVar16) break;
    if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xba].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xba) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xbb].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbb) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xbc].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbc) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
      auVar19 = auStack_c;
    }
    else {
      pixels_x00119.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00119.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00119,iVar16 * 0x30 + 3,0,iVar16 * 0x30 + 0x32,54,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xba].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xba) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      pixels_x00120.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00120.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00120,iVar16 * 0x30 + 3,62,iVar16 * 0x30 + 0x32,116,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xbb].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbb) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      pixels_x00121.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00121.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00121,iVar16 * 0x30 + 3,62,iVar16 * 0x30 + 0x32,116,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xbc].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbc) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      auVar19 = auStack_c;
    }
    iVar16 = iVar16 + 1;
  }
  if (param_1 != false) {
    ovr_stgFreeTmp((stg_tmp_t *)auVar19);
    auVar19 = (undefined1  [4])ovr_grabLbmTR(502);
  }
  iVar16 = 0;
  while( true ) {
    (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
    (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
    auStack_c = auVar19;
    if (3 < iVar16) break;
    if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xbd].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbd) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xbe].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbe) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xbf].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbf) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
      auVar19 = auStack_c;
    }
    else {
      pixels_x00122.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00122.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00122,iVar16 * 0x30 + 3,0,iVar16 * 0x30 + 0x32,54,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xbd].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbd) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      pixels_x00123.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00123.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00123,iVar16 * 0x30 + 3,62,iVar16 * 0x30 + 0x32,116,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xbe].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbe) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      pixels_x00124.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00124.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00124,iVar16 * 0x30 + 3,62,iVar16 * 0x30 + 0x32,116,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xbf].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbf) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      auVar19 = auStack_c;
    }
    iVar16 = iVar16 + 1;
  }
  if (param_1 != false) {
    ovr_stgFreeTmp((stg_tmp_t *)auVar19);
    auVar19 = (undefined1  [4])ovr_grabLbmTR(503);
  }
  iVar16 = 0;
  while( true ) {
    (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
    (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
    auStack_c = auVar19;
    if (3 < iVar16) break;
    if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc0].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc0) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc1].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc1) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc2].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc2) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
      auVar19 = auStack_c;
    }
    else {
      pixels_x00125.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00125.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00125,iVar16 * 0x30 + 3,0,iVar16 * 0x30 + 0x32,54,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xc0].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc0) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      pixels_x00126.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00126.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00126,iVar16 * 0x30 + 3,62,iVar16 * 0x30 + 0x32,116,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xc1].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc1) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      pixels_x00127.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00127.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00127,iVar16 * 0x30 + 3,62,iVar16 * 0x30 + 0x32,116,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xc2].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc2) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      auVar19 = auStack_c;
    }
    iVar16 = iVar16 + 1;
  }
  if (param_1 != false) {
    ovr_stgFreeTmp((stg_tmp_t *)auVar19);
    auVar19 = (undefined1  [4])ovr_grabLbmTR(504);
  }
  iVar16 = 0;
  while( true ) {
    (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
    (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
    auStack_c = auVar19;
    if (3 < iVar16) break;
    if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc3].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc3) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc4].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc4) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc5].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc5) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
      auVar19 = auStack_c;
    }
    else {
      pixels_x00128.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00128.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00128,iVar16 * 0x30 + 3,0,iVar16 * 0x30 + 0x32,54,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xc3].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc3) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      pixels_x00129.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00129.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00129,iVar16 * 0x30 + 3,62,iVar16 * 0x30 + 0x32,116,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xc4].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc4) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      pixels_x00130.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00130.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00130,iVar16 * 0x30 + 3,62,iVar16 * 0x30 + 0x32,116,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xc5].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc5) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      auVar19 = auStack_c;
    }
    iVar16 = iVar16 + 1;
  }
  if (param_1 != false) {
    ovr_stgFreeTmp((stg_tmp_t *)auVar19);
    auVar19 = (undefined1  [4])ovr_grabLbmTR(505);
  }
  iVar16 = 0;
  while( true ) {
    (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
    (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
    auStack_c = auVar19;
    if (3 < iVar16) break;
    if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc6].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc6) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[199].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 199) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[200].seg + iVar16 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 200) + iVar16 * 0x12)->ofs = (uint16_t)uVar22;
      auVar19 = auStack_c;
    }
    else {
      pixels_x00131.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00131.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00131,iVar16 * 0x30 + 3,0,iVar16 * 0x30 + 0x32,54,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[0xc6].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc6) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      pixels_x00132.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00132.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00132,iVar16 * 0x30 + 3,62,iVar16 * 0x30 + 0x32,116,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[199].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 199) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      pixels_x00133.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00133.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00133,iVar16 * 0x30 + 3,62,iVar16 * 0x30 + 0x32,116,0,1);
      pcVar21 = ovr_stshStoreFile(puVar20);
      *(undefined2 *)((int)&BldGfxNormal[200].seg + iVar16 * 0x48) = (int)((ulong)pcVar21 >> 0x10);
      ((far_t *)(BldGfxNormal + 200) + iVar16 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar21;
      auVar19 = auStack_c;
    }
    iVar16 = iVar16 + 1;
  }
  if (param_1 != false) {
    ovr_stgFreeTmp((stg_tmp_t *)auVar19);
  }
  for (fStack_6.seg = 0; (int)fStack_6.seg < 0x12; fStack_6.seg = fStack_6.seg + 1) {
    ovr_stshStubifyFromSrc((char)(fStack_6.seg + 0x43),(char)(fStack_6.seg + 0x55));
  }
  auVar19 = auStack_c;
  if (param_1 != false) {
    auVar19 = (undefined1  [4])ovr_grabLbmTR(11);
  }
  for (iVar16 = 0; iVar16 < 3; iVar16 = iVar16 + 1) {
    fStack_6.seg = 0;
    while( true ) {
      (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
      (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
      if (2 < (int)fStack_6.seg) break;
      auStack_c = auVar19;
      if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
        uVar22 = func_0x0007ffe0(0x4c);
        iVar8 = iVar16 * 3 + fStack_6.seg;
        *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar8 * 0xc) = (int)((ulong)uVar22 >> 0x10);
        ((far_t *)(BldGfxNormal + 0x135) + iVar8 * 3)->ofs = (uint16_t)uVar22;
        auVar19 = auStack_c;
      }
      else {
        pixels_x00134.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
        pixels_x00134.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
        puVar20 = (uint8_t *)
                  ovr_stshRleType2(pixels_x00134,fStack_6.seg * 100,iVar16 * 0x41,
                                   fStack_6.seg * 100 + 99,iVar16 * 0x41 + 0x40,30,-4);
        pcVar21 = ovr_stshStoreFile(puVar20);
        iVar8 = iVar16 * 3 + fStack_6.seg;
        *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar8 * 0xc) = (int)((ulong)pcVar21 >> 0x10)
        ;
        ((far_t *)(BldGfxNormal + 0x135) + iVar8 * 3)->ofs = (uint16_t)(cte_t *)pcVar21;
        auVar19 = auStack_c;
      }
      iVar8 = iVar16 * 3 + fStack_6.seg;
      uVar15 = ((far_t *)(BldGfxNormal + 0x135) + iVar8 * 3)->ofs;
      iVar9 = iVar16 * 3 + fStack_6.seg;
      *(undefined2 *)((int)&BldGfxNormal[0x136].seg + iVar9 * 0xc) =
           *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar8 * 0xc);
      ((far_t *)(BldGfxNormal + 0x136) + iVar9 * 3)->ofs = uVar15;
      iVar8 = iVar16 * 3 + fStack_6.seg;
      uVar15 = ((far_t *)(BldGfxNormal + 0x135) + iVar8 * 3)->ofs;
      iVar9 = iVar16 * 3 + fStack_6.seg;
      *(undefined2 *)((int)&BldGfxNormal[0x137].seg + iVar9 * 0xc) =
           *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar8 * 0xc);
      ((far_t *)(BldGfxNormal + 0x137) + iVar9 * 3)->ofs = uVar15;
      fStack_6.seg = fStack_6.seg + 1;
    }
  }
  if (param_1 != false) {
    auStack_c = auVar19;
    ovr_stgFreeTmp((stg_tmp_t *)auVar19);
    auVar19 = (undefined1  [4])ovr_grabLbmTR(52);
  }
  (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
  (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
  auStack_c = auVar19;
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x151] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    pixels_x00135.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00135.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00135,167,12,206,32,-4,-37);
    BldGfxNormal[0x151] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
  }
  ovr_StubifyCopy1to0_alt(0x70);
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x154] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    pixels_x00136.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00136.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00136,167,45,206,65,-4,-37);
    BldGfxNormal[0x154] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
  }
  ovr_StubifyCopy1to0_alt(0x71);
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x157] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    pixels_x00137.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00137.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00137,167,78,206,98,-4,-37);
    BldGfxNormal[0x157] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
  }
  ovr_StubifyCopy1to0_alt(0x72);
  if (param_1 == false) {
    for (fStack_6.seg = 0; (int)fStack_6.seg < 6; fStack_6.seg = fStack_6.seg + 1) {
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      uVar15 = AnimSeqPtr[1].seg;
      puVar14 = (undefined2 *)(AnimSeqPtr[1].ofs + fStack_6.seg * 4);
      puVar14[1] = (int)((ulong)uVar22 >> 0x10);
      *puVar14 = (int)uVar22;
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      uVar15 = AnimSeqPtr[2].seg;
      puVar14 = (undefined2 *)(AnimSeqPtr[2].ofs + fStack_6.seg * 4);
      puVar14[1] = (int)((ulong)uVar22 >> 0x10);
      *puVar14 = (int)uVar22;
    }
                    /* WARNING: Call to offcut address within same function */
    uVar22 = func_0x0007ffe0(0x4c);
    uVar17 = AnimSeqPtr[1].seg;
    uVar15 = AnimSeqPtr[1].ofs;
    *(undefined2 *)(uVar15 + 0x1a) = (int)((ulong)uVar22 >> 0x10);
    *(undefined2 *)(uVar15 + 0x18) = (int)uVar22;
                    /* WARNING: Call to offcut address within same function */
    uVar22 = func_0x0007ffe0(0x4c);
    uVar17 = AnimSeqPtr[2].seg;
    uVar15 = AnimSeqPtr[2].ofs;
    *(undefined2 *)(uVar15 + 0x1a) = (int)((ulong)uVar22 >> 0x10);
    *(undefined2 *)(uVar15 + 0x18) = (int)uVar22;
  }
  else {
    fStack_6.seg = 0;
    auVar19 = auStack_c;
    while( true ) {
      (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
      (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
      auStack_c = auVar19;
      if (5 < (int)fStack_6.seg) break;
      pixels_x00138.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00138.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00138,13,fStack_6.seg * 0x21 + 0x14,16,
                                 fStack_6.seg * 0x21 + 0x20,-22,-44);
      pcVar21 = ovr_stshStoreFile(puVar20);
      uVar15 = AnimSeqPtr[1].seg;
      puVar14 = (undefined2 *)(AnimSeqPtr[1].ofs + fStack_6.seg * 4);
      puVar14[1] = (int)((ulong)pcVar21 >> 0x10);
      *puVar14 = (cte_t *)pcVar21;
      pixels_x00139.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00139.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00139,95,fStack_6.seg * 0x21 + 0x14,98,
                                 fStack_6.seg * 0x21 + 0x20,-22,-44);
      pcVar21 = ovr_stshStoreFile(puVar20);
      uVar15 = AnimSeqPtr[2].seg;
      puVar14 = (undefined2 *)(AnimSeqPtr[2].ofs + fStack_6.seg * 4);
      puVar14[1] = (int)((ulong)pcVar21 >> 0x10);
      *puVar14 = (cte_t *)pcVar21;
      fStack_6.seg = fStack_6.seg + 1;
      auVar19 = auStack_c;
    }
    pixels_x00140.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00140.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00140,43,20,46,32,-22,-44);
    pcVar21 = ovr_stshStoreFile(puVar20);
    uVar17 = AnimSeqPtr[1].seg;
    uVar15 = AnimSeqPtr[1].ofs;
    *(undefined2 *)(uVar15 + 0x1a) = (int)((ulong)pcVar21 >> 0x10);
    *(undefined2 *)(uVar15 + 0x18) = (cte_t *)pcVar21;
    pixels_x00141.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00141.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00141,125,20,128,32,-22,-44);
    pcVar21 = ovr_stshStoreFile(puVar20);
    uVar17 = AnimSeqPtr[2].seg;
    uVar15 = AnimSeqPtr[2].ofs;
    *(undefined2 *)(uVar15 + 0x1a) = (int)((ulong)pcVar21 >> 0x10);
    *(undefined2 *)(uVar15 + 0x18) = (cte_t *)pcVar21;
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  builtin_memcpy(&ram0x0000d528 + 0x153,"\x02\x02\x02\x03\x03\x03",6);
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x15a] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x15d] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x160] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x15a] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x15d] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x160] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    psVar23 = ovr_grabLbmTR(308);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00142.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00142.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00142,2,86,85,180,-2,38);
    BldGfxNormal[0x15a] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00143.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00143.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00143,108,86,191,180,-2,38);
    BldGfxNormal[0x15d] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00144.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00144.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00144,208,86,298,180,0,38);
    BldGfxNormal[0x160] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(309);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00145.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00145.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00145,2,86,85,180,-2,38);
    BldGfxRuin[0x15a] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00146.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00146.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00146,108,86,191,180,-2,38);
    BldGfxRuin[0x15d] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00147.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00147.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00147,208,86,298,180,0,38);
    BldGfxRuin[0x160] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  ovr_stshStubifyCopy1to0(0x73);
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x163] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x166] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x169] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x163] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x166] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x169] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    psVar23 = ovr_grabLbmTR(467);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00148.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00148.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00148,4,74,91,180,-3,50);
    BldGfxNormal[0x163] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00149.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00149.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00149,110,74,195,180,-3,50);
    BldGfxNormal[0x166] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00150.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00150.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00150,204,74,299,180,3,50);
    BldGfxNormal[0x169] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(468);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00151.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00151.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00151,4,74,91,180,-3,50);
    BldGfxRuin[0x163] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00152.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00152.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00152,110,74,195,180,-3,50);
    BldGfxRuin[0x166] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00153.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00153.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00153,204,74,299,180,3,50);
    BldGfxRuin[0x169] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  ovr_stshStubifyCopy1to0(0x76);
  ovr_stubyBufSrcToDst(0x76,0x79);
  ovr_stubyBufSrcToDst(0x73,0x7c);
  ovr_stubyBufSrcToDst(0x76,0x7f);
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x186] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x187] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x188] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x186] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x187] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x188] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x189] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x18a] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x18b] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x189] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x18a] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x18b] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x18d] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x18d] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    psVar23 = ovr_grabLbmTR(513);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00154.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00154.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00154,2,70,86,180,0,52);
    BldGfxNormal[0x186] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00155.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00155.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00155,108,70,191,180,0,52);
    BldGfxNormal[0x187] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00156.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00156.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00156,215,70,298,180,0,52);
    BldGfxNormal[0x188] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(514);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00157.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00157.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00157,2,70,86,180,0,52);
    BldGfxRuin[0x186] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00158.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00158.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00158,108,70,191,180,0,52);
    BldGfxRuin[0x187] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00159.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00159.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00159,215,70,298,180,0,52);
    BldGfxRuin[0x188] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(517);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00160.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00160.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00160,2,70,86,180,0,52);
    BldGfxNormal[0x189] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00161.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00161.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00161,108,70,191,180,0,52);
    BldGfxNormal[0x18a] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00162.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00162.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00162,215,70,298,180,0,52);
    BldGfxNormal[0x18b] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(518);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00163.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00163.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00163,2,70,86,180,0,52);
    BldGfxRuin[0x189] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00164.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00164.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00164,108,70,191,180,0,52);
    BldGfxRuin[0x18a] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00165.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00165.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00165,215,70,298,180,0,52);
    BldGfxRuin[0x18b] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(525);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00166.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00166.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00166,108,70,191,180,0,52);
    BldGfxNormal[0x18d] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(526);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00167.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00167.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00167,108,70,191,180,0,52);
    BldGfxRuin[0x18d] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  BldGfxNormal[0x18c].ofs = BldGfxNormal[0x18d].ofs;
  BldGfxNormal[0x18c].seg = BldGfxNormal[0x18d].seg;
  BldGfxNormal[0x18e].ofs = BldGfxNormal[0x18d].ofs;
  BldGfxNormal[0x18e].seg = BldGfxNormal[0x18d].seg;
  BldGfxRuin[0x18c].ofs = BldGfxRuin[0x18d].ofs;
  BldGfxRuin[0x18c].seg = BldGfxRuin[0x18d].seg;
  BldGfxRuin[0x18e].ofs = BldGfxRuin[0x18d].ofs;
  BldGfxRuin[0x18e].seg = BldGfxRuin[0x18d].seg;
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[399] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[400] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x191] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[399] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[400] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x191] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x193] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x193] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    psVar23 = ovr_grabLbmTR(515);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00168.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00168.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00168,2,70,86,180,0,52);
    BldGfxNormal[399] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00169.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00169.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00169,108,70,191,180,0,52);
    BldGfxNormal[400] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00170.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00170.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00170,215,70,298,180,0,52);
    BldGfxNormal[0x191] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(516);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00171.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00171.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00171,2,70,86,180,0,52);
    BldGfxRuin[399] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00172.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00172.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00172,108,70,191,180,0,52);
    BldGfxRuin[400] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00173.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00173.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00173,215,70,298,180,0,52);
    BldGfxRuin[0x191] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(519);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00174.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00174.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00174,108,70,191,180,0,52);
    BldGfxNormal[0x193] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(520);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00175.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00175.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00175,108,70,191,180,0,52);
    BldGfxRuin[0x193] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  BldGfxNormal[0x192].ofs = BldGfxNormal[0x193].ofs;
  BldGfxNormal[0x192].seg = BldGfxNormal[0x193].seg;
  BldGfxNormal[0x194].ofs = BldGfxNormal[0x193].ofs;
  BldGfxNormal[0x194].seg = BldGfxNormal[0x193].seg;
  BldGfxRuin[0x192].ofs = BldGfxRuin[0x193].ofs;
  BldGfxRuin[0x192].seg = BldGfxRuin[0x193].seg;
  BldGfxRuin[0x194].ofs = BldGfxRuin[0x193].ofs;
  BldGfxRuin[0x194].seg = BldGfxRuin[0x193].seg;
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x196] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x196] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    psVar23 = ovr_grabLbmTR(521);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00176.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00176.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00176,108,70,191,180,0,52);
    BldGfxNormal[0x196] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(522);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00177.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00177.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00177,108,70,191,180,0,52);
    BldGfxRuin[0x196] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  BldGfxNormal[0x195].ofs = BldGfxNormal[0x196].ofs;
  BldGfxNormal[0x195].seg = BldGfxNormal[0x196].seg;
  BldGfxNormal[0x197].ofs = BldGfxNormal[0x196].ofs;
  BldGfxNormal[0x197].seg = BldGfxNormal[0x196].seg;
  BldGfxRuin[0x195].ofs = BldGfxRuin[0x196].ofs;
  BldGfxRuin[0x195].seg = BldGfxRuin[0x196].seg;
  BldGfxRuin[0x197].ofs = BldGfxRuin[0x196].ofs;
  BldGfxRuin[0x197].seg = BldGfxRuin[0x196].seg;
  if (param_1 == false) {
    for (fStack_6.seg = 0; (int)fStack_6.seg < 5; fStack_6.seg = fStack_6.seg + 1) {
                    /* WARNING: Call to offcut address within same function */
      uVar22 = func_0x0007ffe0(0x4c);
      uVar15 = AnimSeqPtr[0].seg;
      puVar14 = (undefined2 *)(AnimSeqPtr[0].ofs + fStack_6.seg * 4);
      puVar14[1] = (int)((ulong)uVar22 >> 0x10);
      *puVar14 = (int)uVar22;
    }
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x199] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x199] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    auVar19 = (undefined1  [4])ovr_grabLbmTR(523);
    fStack_6.seg = 0;
    while( true ) {
      (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
      (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
      auStack_c = auVar19;
      if (4 < (int)fStack_6.seg) break;
      pixels_x00178.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
      pixels_x00178.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
      puVar20 = (uint8_t *)
                ovr_stshRleType2(pixels_x00178,fStack_6.seg * 0x22 + 0x50,39,
                                 fStack_6.seg * 0x22 + 0x68,58,-68,22);
      pcVar21 = ovr_stshStoreFile(puVar20);
      uVar15 = AnimSeqPtr[0].seg;
      puVar14 = (undefined2 *)(AnimSeqPtr[0].ofs + fStack_6.seg * 4);
      puVar14[1] = (int)((ulong)pcVar21 >> 0x10);
      *puVar14 = (cte_t *)pcVar21;
      fStack_6.seg = fStack_6.seg + 1;
      auVar19 = auStack_c;
    }
    pixels_x00179.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00179.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00179,82,87,222,181,22,32);
    BldGfxNormal[0x199] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(524);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00180.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00180.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00180,82,87,222,181,22,32);
    BldGfxRuin[0x199] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  ovr_StubifyCopy1to0_alt(0x88);
  BldFlags[0x198] = 0x1;
  BldFlags[0x199] = 0x1;
  BldFlags[0x19a] = 0x1;
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x19c] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x19f] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x19c] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x19f] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1a2] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x1a2] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    psVar23 = ovr_grabLbmTR(156);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00181.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00181.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00181,0,101,319,199,60,26);
    BldGfxNormal[0x19c] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00182.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00182.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00182,0,0,319,100,60,28);
    BldGfxNormal[0x19f] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(441);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00183.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00183.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00183,0,101,319,199,60,26);
    BldGfxRuin[0x19c] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00184.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00184.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00184,0,0,319,100,60,28);
    BldGfxRuin[0x19f] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(157);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00185.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00185.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00185,0,70,319,193,60,51);
    BldGfxNormal[0x1a2] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(440);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00186.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00186.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00186,0,70,319,193,60,51);
    BldGfxRuin[0x1a2] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  ovr_stshStubifyCopy1to0(0x89);
  ovr_stubyBufSrcToDst(0x73,0x8c);
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1ae] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1b1] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1b4] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x1ae] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x1b1] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x1b4] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    psVar23 = ovr_grabLbmTR(318);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00187.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00187.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00187,8,50,110,154,-4,45);
    BldGfxNormal[0x1ae] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00188.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00188.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00188,111,50,212,154,-4,45);
    BldGfxNormal[0x1b1] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00189.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00189.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00189,213,50,313,154,-4,45);
    BldGfxNormal[0x1b4] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(319);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00190.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00190.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00190,8,50,110,154,-4,45);
    BldGfxRuin[0x1ae] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00191.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00191.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00191,111,50,212,154,-4,45);
    BldGfxRuin[0x1b1] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00192.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00192.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00192,213,50,313,154,-4,45);
    BldGfxRuin[0x1b4] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  uVar5 = 0x4c;
  ovr_stshStubifyCopy1to0(0x8f);
  iVar16 = 0x92;
  if (param_1 != false) {
    psVar23 = ovr_grabLbm(17,0,0);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    uVar15 = (((stg_tmp_t *)psVar23)->aptr).seg;
    uVar5 = 0xa6;
    (*(uint8_t *)((uint8_t *)&(pixels.seg))) = (char)uVar15;
    pixels.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    (*(uint8_t *)((uint8_t *)&(pixels.seg) + 1)) = (char)(uVar15 >> 8);
    auStack_c = (undefined1  [4])psVar23;
    ovr_grabRemap(pixels,0xff,0x0);
  }
  auVar19 = auStack_c;
  for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
    fStack_6.seg = 0;
    while( true ) {
      (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
      (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
      if (1 < (int)fStack_6.seg) break;
      if ((fStack_6.seg != 0) || (iVar8 != 0)) {
        auStack_c = auVar19;
        if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
          uVar22 = func_0x0007ffe0(uVar5);
          *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar16 * 0xc) = (int)((ulong)uVar22 >> 0x10);
          ((far_t *)BldGfxNormal + iVar16 * 3)->ofs = (uint16_t)uVar22;
          auVar19 = auStack_c;
        }
        else {
          pixels_x00193.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
          pixels_x00193.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
          puVar20 = (uint8_t *)
                    ovr_stshRleType2(pixels_x00193,fStack_6.seg * 0x87,iVar8 * 0x41,
                                     fStack_6.seg * 0x87 + 0x86,iVar8 * 0x41 + 0x40,30,-10);
          uVar5 = 0x4c;
          pcVar21 = ovr_stshStoreFile(puVar20);
          *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar16 * 0xc) = (int)((ulong)pcVar21 >> 0x10);
          ((far_t *)BldGfxNormal + iVar16 * 3)->ofs = (uint16_t)(cte_t *)pcVar21;
          auVar19 = auStack_c;
        }
        uVar15 = ((far_t *)BldGfxNormal + iVar16 * 3)->ofs;
        *(undefined2 *)((int)&BldGfxNormal[1].seg + iVar16 * 0xc) =
             *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar16 * 0xc);
        ((far_t *)(BldGfxNormal + 1) + iVar16 * 3)->ofs = uVar15;
        uVar15 = ((far_t *)BldGfxNormal + iVar16 * 3)->ofs;
        *(undefined2 *)((int)&BldGfxNormal[2].seg + iVar16 * 0xc) =
             *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar16 * 0xc);
        ((far_t *)(BldGfxNormal + 2) + iVar16 * 3)->ofs = uVar15;
        iVar16 = iVar16 + 1;
      }
      fStack_6.seg = fStack_6.seg + 1;
    }
  }
  if (param_1 != false) {
    auStack_c = auVar19;
    ovr_stgFreeTmp((stg_tmp_t *)auVar19);
    uVar5 = 0x4c;
    auVar19 = (undefined1  [4])ovr_grabLbmTR(31);
  }
  (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
  (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
  auStack_c = auVar19;
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1c5] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1c6] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1c7] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
    auVar19 = auStack_c;
  }
  else {
    src_07.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_07.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_07,0,18,200,33);
    BldGfxNormal[0x1c5] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_08.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_08.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_08,131,74,179,130);
    BldGfxNormal[0x1c6] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_09.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_09.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_09,31,49,79,55);
    uVar5 = 0x4c;
    BldGfxNormal[0x1c7] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    auVar19 = auStack_c;
  }
  (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
  (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
  auStack_c = auVar19;
  BldGfxNormal[0x1c8] = BldGfxNormal[0x1c5];
  BldGfxNormal[0x1c9] = BldGfxNormal[0x1c6];
  BldGfxNormal[0x1ca] = BldGfxNormal[0x1c7];
  BldGfxNormal[0x1cb] = BldGfxNormal[0x1c5];
  BldGfxNormal[0x1cc] = BldGfxNormal[0x1c6];
  BldGfxNormal[0x1cd] = BldGfxNormal[0x1c7];
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1ce] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1cf] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1d0] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
    auVar19 = auStack_c;
  }
  else {
    src_10.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_10.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_10,0,49,200,65);
    BldGfxNormal[0x1ce] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_11.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_11.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_11,31,74,79,130);
    BldGfxNormal[0x1cf] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_12.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_12.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_12,131,49,179,55);
    uVar5 = 0x4c;
    BldGfxNormal[0x1d0] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    auVar19 = auStack_c;
  }
  (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
  (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
  auStack_c = auVar19;
  BldGfxNormal[0x1d1] = BldGfxNormal[0x1ce];
  BldGfxNormal[0x1d3] = BldGfxNormal[0x1d0];
  BldGfxNormal[0x1d4] = BldGfxNormal[0x1ce];
  BldGfxNormal[0x1d5] = BldGfxNormal[0x1cf];
  BldGfxNormal[0x1d6] = BldGfxNormal[0x1d0];
  BldGfxNormal[0x1d2] = BldGfxNormal[0x1cf];
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1d7] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
    auVar19 = auStack_c;
  }
  else {
    src_13.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_13.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_13,0,1,200,17);
    uVar5 = 0x4c;
    BldGfxNormal[0x1d7] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    auVar19 = auStack_c;
  }
  (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = (undefined2)((ulong)auVar19 >> 0x10);
  (*(uint16_t *)((uint8_t *)&(auStack_c))) = SUB42(auVar19,0);
  BldGfxNormal[0x1d8].ofs = BldGfxNormal[0x1d2].ofs;
  BldGfxNormal[0x1d8].seg = BldGfxNormal[0x1d2].seg;
  auStack_c = auVar19;
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1d9] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
  }
  else {
    src_14.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_14.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_14,231,49,279,55);
    uVar5 = 0x4c;
    BldGfxNormal[0x1d9] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
  }
  BldGfxNormal[0x1db].seg = BldGfxNormal[0x1d8].seg;
  BldGfxNormal[0x1db].ofs = BldGfxNormal[0x1d8].ofs;
  BldGfxNormal[0x1de].seg = BldGfxNormal[0x1d8].seg;
  BldGfxNormal[0x1de].ofs = BldGfxNormal[0x1d8].ofs;
  BldGfxNormal[0x1da] = BldGfxNormal[0x1d7];
  BldGfxNormal[0x1dc] = BldGfxNormal[0x1d9];
  BldGfxNormal[0x1dd] = BldGfxNormal[0x1d7];
  BldGfxNormal[0x1df] = BldGfxNormal[0x1d9];
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1e0] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1e1] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1e2] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
  }
  else {
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(51);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    src_15.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    src_15.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    fVar24 = ovr_stshRleCut(src_15,131,49,219,65);
    BldGfxNormal[0x1e0] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_16.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_16.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_16,131,74,179,130);
    BldGfxNormal[0x1e1] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_17.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_17.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_17,131,59,179,65);
    BldGfxNormal[0x1e2] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    uVar5 = 0x4c;
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  BldGfxNormal[0x1e3].ofs = BldGfxNormal[0x1e0].ofs;
  BldGfxNormal[0x1e3].seg = BldGfxNormal[0x1e0].seg;
  BldGfxNormal[0x1e4].ofs = BldGfxNormal[0x1e1].ofs;
  BldGfxNormal[0x1e4].seg = BldGfxNormal[0x1e1].seg;
  BldGfxNormal[0x1e5].ofs = BldGfxNormal[0x1e2].ofs;
  BldGfxNormal[0x1e5].seg = BldGfxNormal[0x1e2].seg;
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1e6] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1e7] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1e8] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1ec] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1ed] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1ee] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1f2] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[499] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[500] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
  }
  else {
    psVar23 = ovr_grabLbmTR(288);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    src_18.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    src_18.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    fVar24 = ovr_stshRleCut(src_18,0,51,200,65);
    BldGfxNormal[0x1e6] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_19.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_19.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_19,31,74,79,130);
    BldGfxNormal[0x1e7] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_20.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_20.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_20,0,51,48,57);
    BldGfxNormal[0x1e8] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_21.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_21.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_21,0,14,200,28);
    BldGfxNormal[0x1ec] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_22.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_22.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_22,131,74,179,130);
    BldGfxNormal[0x1ed] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_23.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_23.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_23,0,14,48,20);
    BldGfxNormal[0x1ee] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_24.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_24.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_24,0,168,200,195);
    BldGfxNormal[0x1f2] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    src_25.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    src_25.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    fVar24 = ovr_stshRleCut(src_25,231,74,279,130);
    BldGfxNormal[499] = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar24.seg, fVar24.ofs))));
    pixels_x00194.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00194.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00194,0,168,48,187,0,13);
    BldGfxNormal[500] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    uVar5 = 0x4c;
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  BldGfxNormal[0x1ef].ofs = BldGfxNormal[0x1ec].ofs;
  BldGfxNormal[0x1ef].seg = BldGfxNormal[0x1ec].seg;
  BldGfxNormal[0x1f0].ofs = BldGfxNormal[0x1ed].ofs;
  BldGfxNormal[0x1f0].seg = BldGfxNormal[0x1ed].seg;
  BldGfxNormal[0x1f1].ofs = BldGfxNormal[0x1ee].ofs;
  BldGfxNormal[0x1f1].seg = BldGfxNormal[0x1ee].seg;
  BldGfxNormal[0x1f5].ofs = BldGfxNormal[0x1ec].ofs;
  BldGfxNormal[0x1f5].seg = BldGfxNormal[0x1ec].seg;
  BldGfxNormal[0x1f6].ofs = BldGfxNormal[0x1ed].ofs;
  BldGfxNormal[0x1f6].seg = BldGfxNormal[0x1ed].seg;
  BldGfxNormal[0x1f7].ofs = BldGfxNormal[0x1ee].ofs;
  BldGfxNormal[0x1f7].seg = BldGfxNormal[0x1ee].seg;
  BldGfxNormal[0x1e9] = BldGfxNormal[0x1e6];
  BldGfxNormal[0x1ea] = BldGfxNormal[0x1e7];
  BldGfxNormal[0x1eb] = BldGfxNormal[0x1e8];
  if (param_1 == false) {
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1f9] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1fc] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxNormal[0x1ff] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x1f9] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x1fc] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
                    /* WARNING: Call to offcut address within same function */
    BldGfxRuin[0x1ff] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar5)));
  }
  else {
    psVar23 = ovr_grabLbmTR(462);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00195.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00195.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00195,13,28,96,119,0,32);
    BldGfxNormal[0x1f9] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00196.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00196.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00196,119,28,202,119,0,32);
    BldGfxNormal[0x1fc] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00197.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00197.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00197,226,28,309,119,0,32);
    BldGfxNormal[0x1ff] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
    psVar23 = ovr_grabLbmTR(463);
    uVar18 = (undefined2)((ulong)psVar23 >> 0x10);
    pixels_x00198.seg = (((stg_tmp_t *)psVar23)->aptr).seg;
    pixels_x00198.ofs = (&((stg_tmp_t *)psVar23)->aptr)->ofs;
    auStack_c = (undefined1  [4])psVar23;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00198,13,28,96,119,0,32);
    BldGfxRuin[0x1f9] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00199.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00199.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00199,119,28,202,119,0,32);
    BldGfxRuin[0x1fc] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    pixels_x00200.seg = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->seg;
    pixels_x00200.ofs = ((far_t *)((*(uint16_t *)((uint8_t *)&(auStack_c))) + 0x300))->ofs;
    puVar20 = (uint8_t *)ovr_stshRleType2(pixels_x00200,226,28,309,119,0,32);
    BldGfxRuin[0x1ff] = far_from_u32((uint32_t)(ovr_stshStoreFile(puVar20)));
    ovr_stgFreeTmp((stg_tmp_t *)auStack_c);
  }
  ovr_stshStubifyCopy1to0(0xa8);
  ovr_init_assets1(param_1);
  ovr_init_assets2(param_1);
  if (param_1 != false) {
    sz = dw_from_u32((uint32_t)LXMUL_at_(0x15,(ulong)StshCount));
    (*(uint8_t *)((uint8_t *)&(buf.seg))) = (char)StshCtPtr.seg;
    buf.ofs = StshCtPtr.ofs;
    (*(uint8_t *)((uint8_t *)&(buf.seg) + 1)) = (char)(StshCtPtr.seg >> 8);
    ovr_stshWriteFile(StshFile,buf,sz);
    lseek(StshFile,0,0);
    write(StshFile,(DW *)&StshCtOfs,4);
    close(StshFile);
    if (StshCount != 0xd93) {
      printf("getcache %d  SIZESTASH %d  \r",StshCount);
      ovr_biosReadKey();
    }
  }
  stshInitPtrs();
  return;
code_r0x00088b00:
  if (*(char *)(uVar12 * 0x34 + 5) < '\0') {
    piVar1 = (int *)(uStack_22 * 0x34 + 2);
    *piVar1 = *piVar1 - *(int *)((int)_uStack_12 + 0x11);
  }
LAB_8699_21a5:
  if (((*(int *)(uStack_22 * 0x34) < 0) || (0xd2 < *(int *)(uStack_22 * 0x34))) ||
     ((*(int *)(uStack_22 * 0x34 + 2) < 0 ||
      ((*(char *)(uStack_22 * 0x34 + 0x11) == '\0' &&
       (cVar7 = OVC49_8699_0849((char)*(undefined2 *)(uStack_22 * 0x34)), cVar7 != '\0')))))) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if ((bVar4) && (*(int *)(uStack_22 * 0x34 + 2) < 0x15)) {
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  uStack_20 = (char *)CONCAT11(bVar4,uVar5);
  if (*(char *)(uStack_22 * 0x34 + 0x11) == '\0') {
    iVar16 = ovr_agnt_3b1d_005e((char)*(undefined2 *)(uStack_22 * 0x34));
    iStack_28 = *(int *)(iVar16 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) + 3;
  }
  else {
    iVar16 = ovr_agnt_3b1d_005e((char)*(undefined2 *)(uStack_22 * 0x34));
    iStack_28 = *(int *)(iVar16 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) + -0x16;
  }
  *(int *)(uStack_22 * 0x34 + 0x28) = iStack_28;
  if ((*(char *)(uStack_22 * 0x34 + 0x10) == '\x05') && (*(char *)(uStack_22 * 0x34 + 0xc) != -1)) {
    ovr_OVC41_6a8f_08c2((char)uStack_22);
  }
  cVar7 = OVC49_8699_1711((char)(uStack_22 * 0x34),0x26);
  if (((cVar7 == '\0') || (*(int *)(uStack_22 * 0x34 + 2) < 0)) ||
     ((-1 < *(int *)(uStack_22 * 0x34) &&
      ((*(int *)(uStack_22 * 0x34) < 0xd3 &&
       ((uint)(*(int *)(uStack_22 * 0x34 + 0x28) - *(int *)(iStack_18 + 9)) < 0x96)))))) {
    if ((*(char *)(uStack_22 * 0x34 + 0x11) == '\0') &&
       (cVar7 = OVC49_8699_0849((char)*(undefined2 *)(uStack_22 * 0x34)), cVar7 != '\0')) {
      *(undefined2 *)(uStack_22 * 0x34) = uStack_24;
      *(uint *)(uStack_22 * 0x34 + 2) = uStack_26;
      if (*(char *)(uStack_22 * 0x34 + 4) == '\0') {
        uVar15 = ovr_randBelow(3);
        *(char *)(uStack_22 * 0x34 + 4) = (char)uVar15 + -1;
      }
      else {
        *(char *)(uStack_22 * 0x34 + 4) = -*(char *)(uStack_22 * 0x34 + 4);
      }
      cVar7 = OVC49_8699_1711((char)(uStack_22 * 0x34),0x26);
      if (cVar7 == '\0') {
        uVar15 = ovr_randBelow(3);
        *(char *)(uStack_22 * 0x34 + 5) = (char)uVar15 + -1;
      }
      else {
        uVar15 = ovr_randBelow(2);
        *(undefined1 *)(uStack_22 * 0x34 + 5) = (char)uVar15;
      }
      if (*(char *)(uStack_22 * 0x34 + 4) == '\0') {
        *(undefined1 *)(uStack_22 * 0x34 + 5) = 0;
      }
      if ((('\0' < *(char *)(uStack_22 * 0x34 + 4)) && (*(char *)(uStack_22 * 0x34 + 0xf) != '\0'))
         || ((*(char *)(uStack_22 * 0x34 + 4) < '\0' && (*(char *)(uStack_22 * 0x34 + 0xf) == '\0'))
            )) {
        *(undefined1 *)(uStack_22 * 0x34 + 0x10) = 1;
      }
      uStack_1e = (char *)((uint)uStack_1e & 0xff);
      *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
      OVC49_8699_18c4((char)(uStack_22 * 0x34),0x26);
    }
    else if (((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)) == '\0') ||
            ((((char)uStack_20 == '\0' && (-1 < *(char *)(uStack_22 * 0x34 + 5))) &&
             (cVar7 = OVC49_8699_1711((char)(uStack_22 * 0x34),0x26), cVar7 == '\0')))) {
      if (*(char *)(uStack_22 * 0x34 + 0x25) != '\x02') {
        *(undefined2 *)(uStack_22 * 0x34) = uStack_24;
        *(uint *)(uStack_22 * 0x34 + 2) = uStack_26;
        if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0xbc0) == 0) {
          if (*(char *)(uStack_22 * 0x34 + 4) == '\0') {
            uVar15 = ovr_randBelow(2);
            *(char *)(uStack_22 * 0x34 + 4) = (char)uVar15 * '\x02' + -1;
          }
          else {
            *(char *)(uStack_22 * 0x34 + 4) = -*(char *)(uStack_22 * 0x34 + 4);
          }
          uVar15 = ovr_randBelow(3);
          *(char *)(uStack_22 * 0x34 + 5) = (char)uVar15 + -1;
        }
        if ((('\0' < *(char *)(uStack_22 * 0x34 + 4)) && (*(char *)(uStack_22 * 0x34 + 0xf) != '\0')
            ) || ((*(char *)(uStack_22 * 0x34 + 4) < '\0' &&
                  (*(char *)(uStack_22 * 0x34 + 0xf) == '\0')))) {
          *(undefined1 *)(uStack_22 * 0x34 + 0x10) = 1;
        }
        uStack_1e = (char *)((uint)uStack_1e & 0xff);
        *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
        OVC49_8699_18c4((char)(uStack_22 * 0x34),0x26);
      }
    }
    else {
      cVar7 = OVC49_8699_06dc((char)(uStack_22 * 0x34),0x26);
      if (cVar7 != '\0') {
        *(undefined2 *)(uStack_22 * 0x34) = uStack_24;
        *(uint *)(uStack_22 * 0x34 + 2) = uStack_26;
        if ((*(char *)(uStack_22 * 0x34 + 0x11) == '\0') ||
           (*(char *)(uStack_22 * 0x34 + 4) != '\0')) {
          if (*(char *)(uStack_22 * 0x34 + 0x11) == '\0') {
            *(undefined1 *)(uStack_22 * 0x34 + 4) = 0;
          }
          else {
            *(char *)(uStack_22 * 0x34 + 4) = -*(char *)(uStack_22 * 0x34 + 4);
          }
        }
        else {
          uVar15 = ovr_randBelow(2);
          *(char *)(uStack_22 * 0x34 + 4) = (char)uVar15 * '\x02' + -1;
        }
        *(undefined1 *)(uStack_22 * 0x34 + 5) = 0;
        *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
        if ((('\0' < *(char *)(uStack_22 * 0x34 + 4)) && (*(char *)(uStack_22 * 0x34 + 0xf) != '\0')
            ) || ((*(char *)(uStack_22 * 0x34 + 4) < '\0' &&
                  (*(char *)(uStack_22 * 0x34 + 0xf) == '\0')))) {
          *(undefined1 *)(uStack_22 * 0x34 + 0x10) = 1;
        }
        uStack_1e = (char *)((uint)uStack_1e & 0xff);
        OVC49_8699_18c4((char)(uStack_22 * 0x34),0x26);
      }
    }
  }
  else {
    *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
  }
  OVC49_8699_1753((char)uStack_22 + '\x01',(char)(uStack_22 * 0x34),0x26);
  if (((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)) != '\0') && (cVar7 = ovr_agnt_3b1d_177f((char)uStack_22), cVar7 != '\0')) {
    uStack_22 = uStack_22 - 1;
  }
  uStack_22 = uStack_22 + 1;
  if ((int)uStack_22 < (int)(uint)AgntCount) {
    psStack_8 = (stg_tmp_t *)*(undefined2 *)(uStack_22 * 0x34 + 0x15);
    (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = *(undefined2 *)(uStack_22 * 0x34 + 0x13);
    OVC49_8699_1753(0,(char)(uStack_22 * 0x34),0x26);
    OVC49_8699_0874((char)(uStack_22 * 0x34),0x26,(char)uStack_22);
    uStack_24 = *(undefined2 *)(uStack_22 * 0x34);
    uStack_26 = *(uint *)(uStack_22 * 0x34 + 2);
    bStack_1b = OVC49_8699_18c4((char)(uStack_22 * 0x34),0x26);
    _uStack_12 = CONCAT22(*(undefined2 *)((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + (uint)bStack_1b * 4 + 2),
                          *(undefined2 *)((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + (uint)bStack_1b * 4));
    uVar15 = 0x1726;
    iStack_18 = ovr_stash_474a_10ac((char)*(undefined2 *)
                                           ((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + (uint)bStack_1b * 4 + 0x58)
                                    ,(char)*(undefined2 *)
                                            ((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + (uint)bStack_1b * 4 + 0x5a
                                            ),*(undefined1 *)(uStack_22 * 0x34 + 6));
    pcVar11 = uStack_1e;
    if (*(char *)(uStack_22 * 0x34 + 4) < '\x01') {
      if (*(char *)(uStack_22 * 0x34 + 4) < '\0') {
        *(int *)(uStack_22 * 0x34) = *(int *)(uStack_22 * 0x34) - (int)*(char *)(iStack_18 + 5);
      }
    }
    else {
      *(int *)(uStack_22 * 0x34) = *(int *)(uStack_22 * 0x34) + (int)*(char *)(iStack_18 + 5);
    }
    uStack_1e = (char *)CONCAT11(1,(undefined1)uStack_1e);
    iVar16 = (int)_uStack_12;
    uVar18 = (undefined2)((ulong)_uStack_12 >> 0x10);
    if (*(char *)(uStack_22 * 0x34 + 5) < '\x01') {
      if (*(char *)(uStack_22 * 0x34 + 5) < '\0') {
        piVar1 = (int *)(uStack_22 * 0x34 + 2);
        *piVar1 = *piVar1 - *(int *)(iVar16 + 0x11);
      }
      else {
        uStack_1e = (char *)((uint)pcVar11 & 0xff);
      }
    }
    else {
      piVar1 = (int *)(uStack_22 * 0x34 + 2);
      *piVar1 = *piVar1 + *(int *)(iVar16 + 0x11);
    }
    local_16 = uVar15;
    if (0x14 < *(int *)(uStack_22 * 0x34 + 2)) {
      uVar12 = uStack_22;
      if ('\0' < *(char *)(uStack_22 * 0x34 + 5)) {
        piVar1 = (int *)(uStack_22 * 0x34 + 2);
        *piVar1 = *piVar1 + *(int *)(iVar16 + 0x11);
        goto LAB_8699_21a5;
      }
      goto code_r0x00088b00;
    }
    goto LAB_8699_21a5;
  }
  GGameState = 0x2e;
  if (DebugVerbose != false) {
    printf("%d \r",0x2e);
  }
  for (uStack_22 = 0; (int)uStack_22 < (int)(uint)AgntCount; uStack_22 = uStack_22 + 1) {
    psStack_8 = (stg_tmp_t *)*(undefined2 *)(uStack_22 * 0x34 + 0x15);
    (*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) = *(int *)(uStack_22 * 0x34 + 0x13);
    uStack_1a = *(uint *)(uStack_22 * 0x34 + 6);
    bStack_1b = *(byte *)(uStack_22 * 0x34 + 0x12);
    _uStack_12 = CONCAT22(*(undefined2 *)
                           (((stg_tmp_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)))->cmap + (uint)bStack_1b * 4 + 2),
                          *(undefined2 *)
                           (((stg_tmp_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)))->cmap + (uint)bStack_1b * 4));
    GGameState = 0x37;
    if (DebugVerbose != false) {
      printf("%d \r",0x37);
    }
    uVar15 = 0x1726;
    iStack_18 = ovr_stash_474a_10ac((char)*(undefined2 *)
                                           ((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + (uint)bStack_1b * 4 + 0x58)
                                    ,(char)*(undefined2 *)
                                            ((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + (uint)bStack_1b * 4 + 0x5a
                                            ),*(undefined1 *)(uStack_22 * 0x34 + 6));
    GGameState = 0x38;
    local_16 = uVar15;
    if (DebugVerbose != false) {
      printf("%d \r",0x38);
    }
    iVar16 = *(int *)(uStack_22 * 0x34) + 0xc;
    if (*(char *)(uStack_22 * 0x34 + 0x11) == '\0') {
      iVar8 = ovr_agnt_3b1d_005e((char)*(undefined2 *)(uStack_22 * 0x34));
      iStack_28 = *(int *)(iVar8 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) + 3;
    }
    else {
      iVar8 = ovr_agnt_3b1d_005e((char)*(undefined2 *)(uStack_22 * 0x34));
      uVar22 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d);
      iStack_28 = *(int *)(iVar8 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) +
                  (int)*(char *)((int)uVar22 + 0x52) + -0x16;
    }
    *(int *)(uStack_22 * 0x34 + 0x26) = iVar16;
    *(int16_t *)(uStack_22 * 0x34 + 0x28) = iStack_28;
    if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0x800) == 0) {
      if (*(char *)(uStack_22 * 0x34 + 0x24) == '\0') {
        GGameState = 0x32;
        gfx_00.seg = local_16;
        gfx_00.ofs = iStack_18 + 6;
        ovr_blitGfxRect(gfx_00,iVar16,iStack_28,
                        (brect_t *)CONCAT13(uVar43,CONCAT12(uVar42,auStack_32)),0x10,
                        *(bool *)(uStack_22 * 0x34 + 0xf));
        GGameState = 0x33;
        if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 100) != 0) {
          bVar4 = *(bool *)(uStack_22 * 0x34 + 0xf);
          iVar8 = *(int *)((int)_uStack_12 + 0xd);
          bVar6 = *(byte *)(uStack_22 * 0x34 + 0x23);
          pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
          *pcVar2 = *pcVar2 + -1;
          uVar13 = bVar6 & 3;
          gfx_01.seg = ((undefined2 *)&DAT_2000_cc67)[uVar13 * 2];
          gfx_01.ofs = ((undefined2 *)&DAT_2000_cc65)[uVar13 * 2];
          ovr_blitGfxRect(gfx_01,iVar16,iStack_28 - iVar8,
                          (brect_t *)CONCAT13(uVar43,CONCAT12(uVar42,auStack_32)),0x10,bVar4);
        }
      }
      else if (*(char *)(uStack_22 * 0x34 + 0x24) == '\x01') {
        uVar22 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d);
        if ((*(uint *)((int)uVar22 + 0x40) & 2) == 0) {
          gfx_03.seg = local_16;
          gfx_03.ofs = iStack_18 + 6;
          ovr_blitGfxRect(gfx_03,iVar16,iStack_28,
                          (brect_t *)CONCAT13(uVar43,CONCAT12(uVar42,auStack_32)),0x10,
                          *(bool *)(uStack_22 * 0x34 + 0xf));
          uVar13 = *(byte *)(uStack_22 * 0x34 + 0x23) & 3;
          gfx_04.seg = ((undefined2 *)&DAT_2000_cc67)[uVar13 * 2];
          gfx_04.ofs = ((undefined2 *)&DAT_2000_cc65)[uVar13 * 2];
          ovr_blitGfxRect(gfx_04,iVar16,iStack_28 - *(int *)((int)_uStack_12 + 0xd),
                          (brect_t *)CONCAT13(uVar43,CONCAT12(uVar42,auStack_32)),0x10,
                          *(bool *)(uStack_22 * 0x34 + 0xf));
          if (*(char *)(uStack_22 * 0x34 + 0x23) == '\0') {
            *(undefined1 *)(uStack_22 * 0x34 + 0x24) = 0;
          }
          else {
            pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
            *pcVar2 = *pcVar2 + -1;
          }
        }
        else {
          gfx_02.seg = local_16;
          gfx_02.ofs = iStack_18 + 6;
          ovr_blitGfxRect(gfx_02,iVar16,iStack_28,
                          (brect_t *)CONCAT13(uVar43,CONCAT12(uVar42,auStack_32)),0x10,
                          *(bool *)(uStack_22 * 0x34 + 0xf));
          if ((int)(uint)*(byte *)((int)_uStack_12 + 0x1b) <= *(int *)(uStack_22 * 0x34 + 6) + 1) {
            *(undefined1 *)(uStack_22 * 0x34 + 0x24) = 0;
          }
        }
      }
      else if (*(char *)(uStack_22 * 0x34 + 0x24) == '\x02') {
        if (bStack_1b == 0x12) {
          gfx_05.seg = local_16;
          gfx_05.ofs = iStack_18 + 6;
          ovr_blitGfxRect(gfx_05,iVar16,iStack_28,
                          (brect_t *)CONCAT13(uVar43,CONCAT12(uVar42,auStack_32)),0x10,
                          *(bool *)(uStack_22 * 0x34 + 0xf));
          if ((int)(uint)*(byte *)((int)_uStack_12 + 0x1b) <= *(int *)(uStack_22 * 0x34 + 6) + 1) {
            *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
            ovr_OVC41_6a8f_0807((char)uStack_22);
          }
        }
        else {
          ovr_randBelow(0x100);
          ovr_gfxRlePrepare(iStack_18 + 6,local_16,iVar16,iStack_28);
          if (*(char *)(uStack_22 * 0x34 + 0x23) == '\0') {
            *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
            ovr_OVC41_6a8f_0807((char)uStack_22);
          }
          else {
            pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
            *pcVar2 = *pcVar2 + -1;
          }
        }
      }
    }
    else {
      ovr_gfxRlePrepare(iStack_18 + 6,local_16,iVar16,iStack_28);
    }
    if (*(char *)(uStack_22 * 0x34 + 0x30) != '\0') {
      ovr_agnt_3b1d_1035((char)uStack_22,(char)auStack_32);
    }
    uVar18 = (undefined2)((ulong)_uStack_12 >> 0x10);
    if (((*(uint *)(uStack_22 * 0x34 + 0x2b) & 8) == 0) ||
       ((uint)*(byte *)((int)_uStack_12 + 0x19) != *(uint *)(uStack_22 * 0x34 + 6))) {
      if (((uint)*(byte *)((int)_uStack_12 + 0x19) == *(uint *)(uStack_22 * 0x34 + 6)) &&
         ((*(char *)(uStack_22 * 0x34 + 0x24) == '\0' && (*(char *)(uStack_22 * 0x34 + 0xe) == -1)))
         ) {
        if (*(char *)(uStack_22 * 0x34 + 0xd) == '\0') {
          cVar7 = OVC49_8699_036e(uStack_22 * 0x34,0x26,(char)&bStack_1c);
          if (cVar7 == '\0') {
            if ((*(char *)(uStack_22 * 0x34 + 0x12) == '\x03') ||
               (*(char *)(uStack_22 * 0x34 + 0x12) == '\x0f')) {
              uVar15 = ovr_audio_3a5b_0afd((char)(uStack_22 * 0x34),0x26);
              ovr_play_sfxU(0x33,0,uVar15);
            }
            DAT_2410_07e2 = 9;
            ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
          }
          else {
            *(char *)(uStack_22 * 0x34 + 0xc) = bStack_1c - 1;
          }
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x01') {
          cVar7 = OVC49_8699_0000(uStack_22 * 0x34,0x26,(char)&bStack_1c);
          if ((cVar7 == '\0') ||
             (cVar7 = ovr_OVC27_5ded_0404((char)(uStack_22 * 0x34),0x26,bStack_1c - 1),
             cVar7 == '\0')) {
            DAT_2410_07e2 = 10;
            ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
          }
          else {
            *(char *)(uStack_22 * 0x34 + 0xc) = bStack_1c - 1;
          }
        }
        else if (((*(char *)(uStack_22 * 0x34 + 0xd) == '\x02') ||
                 (*(char *)(uStack_22 * 0x34 + 0xd) == '\x04')) ||
                (*(char *)(uStack_22 * 0x34 + 0xd) == '\x05')) {
          cVar7 = ovr_agnt_3b1d_00ce(uStack_22 * 0x34,0x26,(char)&bStack_1c);
          if (cVar7 == '\0') {
            DAT_2410_07e2 = 0xb;
            ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
          }
          else {
            *(char *)(uStack_22 * 0x34 + 0xc) = bStack_1c - 1;
          }
        }
        bStack_1c = *(char *)(uStack_22 * 0x34 + 0xc) + 1;
        if (((bStack_1c == 0) || (*(char *)((uint)bStack_1c * 0x34 + -0x10) != '\0')) ||
           ((*(char *)(uStack_22 * 0x34 + 0xd) != '\x06' &&
            ((0x14 < *(int *)(uStack_22 * 0x34 + 2) ||
             (0x14 < *(int *)((uint)bStack_1c * 0x34 + -0x32))))))) {
          DAT_2410_07e2 = 0xc;
          ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x01') {
          cVar7 = ovr_OVC27_5ded_0a05((char)uStack_22);
          if (cVar7 == '\0') {
            DAT_2410_07e2 = 0xf;
            ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
          }
        }
        else if (((*(char *)(uStack_22 * 0x34 + 0xd) == '\x02') ||
                 (*(char *)(uStack_22 * 0x34 + 0xd) == '\x04')) &&
                (*(char *)(uStack_22 * 0x34 + 0xe) == -1)) {
          uVar15 = ovr_audio_3a5b_0afd((char)(uStack_22 * 0x34),0x26);
          ovr_play_sfxU(*(byte *)((int)_uStack_12 + 0x1d),0,uVar15);
          *(undefined1 *)(uStack_22 * 0x34 + 0xe) = 0;
          *(undefined1 *)(uStack_22 * 0x34 + 0x2e) = 0;
          uVar18 = (undefined2)((ulong)_uStack_12 >> 0x10);
          iVar8 = (int)_uStack_12;
          *(char *)(uStack_22 * 0x34 + 10) = *(char *)(iVar8 + 0x15) + (char)iStack_28;
          if (*(char *)(uStack_22 * 0x34 + 0xf) == '\0') {
            *(int *)(uStack_22 * 0x34 + 8) = *(int *)(iVar8 + 0x13) + iVar16;
          }
          else {
            *(int *)(uStack_22 * 0x34 + 8) = iVar16 - *(int *)(iVar8 + 0x13);
          }
          *(undefined1 *)(uStack_22 * 0x34 + 0xb) = *(undefined1 *)(uStack_22 * 0x34 + 0xf);
        }
        else if ((*(char *)(uStack_22 * 0x34 + 0xd) == '\0') &&
                (uVar22 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d),
                (*(uint *)((int)uVar22 + 0x3c) & 8) == 0)) {
          uVar15 = ovr_audio_3a5b_0afd((char)(uStack_22 * 0x34),0x26);
          ovr_play_sfxU(*(byte *)((int)_uStack_12 + 0x1d),0,uVar15);
          ovr_OVC41_6a8f_297d((char)(uStack_22 * 0x34),0x26,*(undefined1 *)(uStack_22 * 0x34 + 0xc))
          ;
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x03') {
          cVar7 = ovr_agnt_3b1d_0d4d(uStack_22 * 0x34,0x26,bStack_1c * '4' + -0x34,0x26);
          if ((cVar7 != '\0') && ((*(uint *)((uint)bStack_1c * 0x34 + -9) & 0x800) == 0)) {
            uVar22 = *(undefined4 *)((uint)bStack_1c * 0x34 + -0x1d);
            if (((*(uint *)((int)uVar22 + 0x14) & 2) == 0) ||
               ((uVar15 = ovr_randBelow(2), (uVar15 & 0xff) != 0 ||
                ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0x800) == 0)))) {
              ovr_OVC41_6a8f_0229(bStack_1c * '4' + -0x34,0x26);
              puVar3 = (uint *)((uint)bStack_1c * 0x34 + -9);
              *puVar3 = *puVar3 | 0x800;
              uVar15 = ovr_audio_3a5b_0afd(bStack_1c * '4' + -0x34,0x26);
              ovr_play_sfxU(0x1b,0,uVar15);
            }
            else {
              uVar15 = ovr_audio_3a5b_0afd((char)(uStack_22 * 0x34),0x26);
              ovr_play_sfxU(0x1b,0,uVar15);
              ovr_OVC41_6a8f_0229(bStack_1c * '4' + -0x34,0x26);
              puVar3 = (uint *)(uStack_22 * 0x34 + 0x2b);
              *puVar3 = *puVar3 | 0x800;
            }
          }
          DAT_2410_07e2 = 0xd;
          ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x05') {
          uVar15 = ovr_audio_3a5b_0afd((char)(uStack_22 * 0x34),0x26);
          ovr_play_sfxU(*(byte *)((int)_uStack_12 + 0x1d),0,uVar15);
          *(undefined1 *)(uStack_22 * 0x34 + 0xe) = 0xf5;
          *(undefined1 *)(uStack_22 * 0x34 + 0x2e) = 1;
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x06') {
          uVar15 = ovr_audio_3a5b_0afd((char)(uStack_22 * 0x34),0x26);
          ovr_play_sfxU(*(byte *)((int)_uStack_12 + 0x1d),0,uVar15);
          ovr_OVC41_6a8f_297d((char)(uStack_22 * 0x34),0x26,*(undefined1 *)(uStack_22 * 0x34 + 0xc))
          ;
        }
        else {
          DAT_2410_07e2 = 0xe;
          ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
        }
      }
    }
    else {
      ovr_OVC41_6a8f_297d((char)(uStack_22 * 0x34),0x26,*(undefined1 *)(uStack_22 * 0x34 + 0xc));
    }
    GGameState = 0x39;
    if (DebugVerbose != false) {
      printf("%d \r",0x39);
    }
    piVar1 = (int *)(uStack_22 * 0x34 + 6);
    *piVar1 = *piVar1 + 1;
    if (*(char *)(uStack_22 * 0x34 + 0xe) != -1) {
      if (*(char *)(uStack_22 * 0x34 + 0xc) == -1) {
        ovr_agnt_3b1d_0a53((char)(uStack_22 * 0x34),0x26);
        DAT_2410_07e2 = 7;
      }
      else if ((*(char *)(uStack_22 * 0x34 + 0x2e) == '\0') ||
              (*(char *)((uint)*(byte *)(uStack_22 * 0x34 + 0x2e) * 0x21 + -0x16) != '\0')) {
        bVar6 = *(byte *)(uStack_22 * 0x34 + 0xe);
        uStack_1a = (uint)bVar6;
        (*(uint16_t *)((uint8_t *)&(auStack_c))) = psStack_8;
        psStack_e = (stg_tmp_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2));
        if (*(char *)(uStack_22 * 0x34 + 0x2e) == '\0') {
          uStack_1e = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)),6);
        }
        else {
          uStack_1e = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)),
                                       *(undefined1 *)
                                        ((uint)*(byte *)(uStack_22 * 0x34 + 0x2e) * 0x21 + -0x16));
        }
        if (*(int *)((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + ((uint)uStack_1e & 0xff) * 4) == 0 &&
            *(int *)((uint8_t *)(*(uint16_t *)((uint8_t *)&(auStack_c) + 2)) + ((uint)uStack_1e & 0xff) * 4 + 2) == 0) {
          (*(uint16_t *)((uint8_t *)&(auStack_c))) = SprProjectiles.seg;
          psStack_e = (stg_tmp_t *)SprProjectiles.ofs;
        }
        uVar15 = *(uint16_t *)(psStack_e->cmap + ((uint)uStack_1e & 0xff) * 4);
        _uStack_12 = CONCAT22(*(undefined2 *)(psStack_e->cmap + ((uint)uStack_1e & 0xff) * 4 + 2),
                              uVar15);
        if (*(int *)(psStack_e->cmap + ((uint)uStack_1e & 0xff) * 4) == 0 &&
            *(int *)(psStack_e->cmap + ((uint)uStack_1e & 0xff) * 4 + 2) == 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0xf);
        }
        iStack_18 = ovr_stash_474a_10ac((char)*(undefined2 *)
                                               (psStack_e->cmap +
                                               ((uint)uStack_1e & 0xff) * 4 + 0x58),
                                        (char)*(undefined2 *)
                                               (psStack_e->cmap +
                                               ((uint)uStack_1e & 0xff) * 4 + 0x5a),bVar6);
        GGameState = 0x30;
        gfx.seg = uVar15;
        gfx.ofs = iStack_18 + 6;
        local_16 = uVar15;
        ovr_blitGfxRect(gfx,*(int16_t *)(uStack_22 * 0x34 + 8),
                        (uint)*(byte *)(uStack_22 * 0x34 + 10),
                        (brect_t *)CONCAT13(uVar43,CONCAT12(uVar42,auStack_32)),0x10,
                        *(bool *)(uStack_22 * 0x34 + 0xb));
        GGameState = 0x31;
        uVar18 = (undefined2)((ulong)_uStack_12 >> 0x10);
        iVar16 = (int)_uStack_12;
        if ((*(byte *)(iVar16 + 0x1c) & 2) == 0) {
          if (*(char *)(uStack_22 * 0x34 + 0xb) == '\0') {
            piVar1 = (int *)(uStack_22 * 0x34 + 8);
            *piVar1 = *piVar1 + (int)*(char *)(iStack_18 + 5);
          }
          else {
            piVar1 = (int *)(uStack_22 * 0x34 + 8);
            *piVar1 = *piVar1 - (int)*(char *)(iStack_18 + 5);
          }
          uStack_1a = uStack_1a + 1;
          if (*(byte *)(iVar16 + 0x19) + 1 == uStack_1a) {
            ovr_OVC41_6a8f_22cb((char)(uStack_22 * 0x34),0x26,
                                *(undefined1 *)(uStack_22 * 0x34 + 0xc));
          }
          if ((int)uStack_1a < (int)(uint)*(byte *)((int)_uStack_12 + 0x1b)) {
            *(undefined1 *)(uStack_22 * 0x34 + 0xe) = (undefined1)uStack_1a;
          }
          else {
            DAT_2410_07e2 = 8;
            ovr_agnt_3b1d_0a53((char)(uStack_22 * 0x34),0x26);
          }
        }
        else {
          ovr_agnt_3b1d_0d82(uStack_22 * 0x34,0x1726,iVar16,(char)((ulong)_uStack_12 >> 0x10),
                             (char)iStack_18,(char)local_16);
        }
      }
      else {
        ovr_OVC27_5ded_0cc2((char)uStack_22,(char)auStack_32);
      }
    }
  }
  GGameState = 0x3a;
  if (DebugVerbose != false) {
    printf("%d \r",0x3a);
  }
  ovr_constr_36ce_08ee((char)auStack_32);
  GGameState = 0x2f;
  if (DebugVerbose != false) {
    printf("%d \r",0x2f);
  }
  if (DAT_2000_d0f5 != '\0') {
    ovr_attact_3f0b_26bd();
    DAT_2000_d0f5 = '\0';
  }
  (*(uint8_t *)((uint8_t *)&(fStack_6.seg))) = '\0';
  (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = '\0';
  uStack_22 = (uint)AgntCount;
  do {
    do {
      uStack_22 = uStack_22 - 1;
      if ((int)uStack_22 < 0) goto LAB_8699_3cf7;
    } while (((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0xae4) != 0) ||
            (*(char *)(uStack_22 * 0x34 + 0x25) == '\x02'));
    if (*(char *)(uStack_22 * 0x34 + 0x2f) == '\0') {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = '\x01';
    }
    else {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg))) = '\x01';
    }
  } while (((char)fStack_6.seg == '\0') || ((*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) == '\0'));
LAB_8699_3cf7:
  if (((*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) == '\0') || ((char)fStack_6.seg == '\0')) {
    (*(uint8_t *)((uint8_t *)&(fStack_6.ofs) + 1)) = '\x01';
  }
  else {
    (*(uint8_t *)((uint8_t *)&(fStack_6.ofs) + 1)) = '\0';
  }
  (*(uint8_t *)((uint8_t *)&(fStack_6.ofs))) = '\0';
  uStack_22 = (uint)AgntCount;
  while (uStack_22 = uStack_22 - 1, -1 < (int)uStack_22) {
    if (*(char *)(uStack_22 * 0x34 + 0x25) == '\x02') {
      ovr_OVC41_6a8f_0256((char)uStack_22,0);
      DAT_2000_d0f5 = '\x01';
    }
    else if (((*(uint8_t *)((uint8_t *)&(fStack_6.ofs) + 1)) != '\0') && ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0xae4) != 0)) {
      (*(uint8_t *)((uint8_t *)&(fStack_6.ofs))) = '\x01';
      *(undefined1 *)(uStack_22 * 0x34 + 0x30) = 0;
      if ((((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0x800) == 0) &&
          ((*(char *)*(undefined4 *)(uStack_22 * 0x34 + 0x1d) == '\0' ||
           ((char)fStack_6.seg != '\0')))) &&
         ((*(char *)*(undefined4 *)(uStack_22 * 0x34 + 0x1d) != '\0' || ((*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) != '\0')
          ))) {
        puVar3 = (uint *)(uStack_22 * 0x34 + 0x2b);
        *puVar3 = *puVar3 & 0xf51b;
        *(undefined1 *)(uStack_22 * 0x34 + 0x2f) =
             *(undefined1 *)*(undefined4 *)(uStack_22 * 0x34 + 0x1d);
        ovr_OVC41_6a8f_0246((char)(uStack_22 * 0x34),0x26);
      }
      else {
        puVar3 = (uint *)(uStack_22 * 0x34 + 0x2b);
        *puVar3 = *puVar3 & 0xf51b;
        *(undefined1 *)(uStack_22 * 0x34 + 0x21) = 0;
        *(undefined1 *)(uStack_22 * 0x34 + 0x23) = 10;
        *(undefined1 *)(uStack_22 * 0x34 + 0x24) = 2;
        *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
      }
      DAT_2000_d0f5 = '\x01';
    }
  }
  if (DAT_2000_d0f5 != '\0') {
    ovr_attact_3f0b_26bd();
    DAT_2000_d0f5 = '\0';
  }
  iVar16 = EntityCount;
  if ((char)fStack_6.ofs != '\0') {
    ovr_play_sfxU(0x3b,0,0x80);
    iVar16 = EntityCount;
  }
  do {
    do {
      iVar16 = iVar16 + -1;
      if (iVar16 < 0) {
        ovr_OVC41_6a8f_05ad();
        return;
      }
      uVar17 = Entities.seg;
      uVar15 = Entities.ofs;
    } while ((*(char *)(uVar15 + iVar16 * 0x37 + 0xe) != '\0') ||
            (cVar7 = ovr_OVC23_55fe_05db((char)*(undefined2 *)(uVar15 + iVar16 * 0x37),
                                         (char)*(undefined2 *)(uVar15 + iVar16 * 0x37 + 2)),
            cVar7 == '\0'));
    uStack_22 = (uint)AgntCount;
    do {
      uStack_22 = uStack_22 - 1;
      if ((int)uStack_22 < 0) break;
    } while (*(int *)(uStack_22 * 0x34 + 0x1b) != iVar16);
    if ((int)uStack_22 < 0) {
      ovr_OVC15_4207_0e17((char)iVar16);
      DAT_2000_d0fd = 1;
    }
  } while( true );
}




/* 7e7c:2b4c */

/* WARNING: Removing unreachable block (ram,0x00081559) */
/* WARNING: Removing unreachable block (ram,0x00081610) */
/* WARNING: Removing unreachable block (ram,0x0008155e) */
/* WARNING: Removing unreachable block (ram,0x00081597) */
/* WARNING: Removing unreachable block (ram,0x000815cd) */
/* WARNING: Removing unreachable block (ram,0x0008160f) */

void __cdecl16far constrct_7e7c_2b4c(byte param_1,int param_2)

{
  uint *puVar1;
  int *piVar2;
  long lVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  char *msg;
  char local_a0 [140];
  byte bStack_14;
  byte bStack_13;
  long lStack_12;
  long lStack_e;
  uint uStack_a;
  int iStack_8;
  undefined4 uStack_6;
  
  bStack_14 = *(byte *)(Entities.ofs + param_2 * 0x37 + 0x1a);
  if ((param_1 != 0xff) && (bStack_14 != 0xff)) {
    bStack_13 = *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3e);
    (*(uint16_t *)((uint8_t *)&(uStack_6))) =
         (char *)(*(int *)((int)&far_t_ARRAY_2410_26f7[9].seg + 1 + (uint)bStack_13 * 0x95) * 0xf);
    (*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) = 0;
    uStack_a = *(int *)((int)&far_t_ARRAY_2410_26f7[9].seg + 1 + (uint)bStack_13 * 0x95) * 0xf;
    iStack_8 = 0;
    iVar10 = 0;
    for (uVar9 = 0; uVar9 < EntityCount; uVar9 = uVar9 + 1) {
      cVar4 = ovr_OVC23_55fe_05db(*(undefined2 *)(Entities.ofs + uVar9 * 0x37));
      if ((cVar4 != '\0') &&
         (bStack_13 = *(byte *)(Entities.ofs + uVar9 * 0x37 + 0xd),
         *(char *)((int)(char **)GMenuStrings + (uint)bStack_13 * 0x95 + 0x1f) == '\0')) {
        iVar10 = iVar10 + 1;
      }
    }
    lStack_12 = LDIV_at_(CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(char *)uStack_6),(long)iVar10);
    lStack_12 = lStack_12 + 1;
    uStack_6 = (char *)LXMUL_at_(lStack_12,(long)iVar10);
    msg = ovr_stsprintf(local_a0,
                        "%ld experience obtained. %ld experience given to each unit. %ld gold recovered."
                        ,(char *)uStack_6);
    ovr_say(msg);
    lStack_e = LDIV_at_(CONCAT22(iStack_8,uStack_a),10);
    uVar11 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_14 << 2) >> 0x10);
    iVar10 = (int)*(undefined4 *)((uint)bStack_14 << 2);
    uVar5 = uStack_a - (uint)lStack_e;
    puVar1 = (uint *)(iVar10 + 0x56);
    uVar9 = *puVar1;
    *puVar1 = *puVar1 + uVar5;
    piVar2 = (int *)(iVar10 + 0x58);
    *piVar2 = *piVar2 + ((iStack_8 - (int)((ulong)lStack_e >> 0x10)) -
                        (uint)(uStack_a < (uint)lStack_e)) + (uint)CARRY2(uVar9,uVar5);
    lVar3 = lStack_e + CONCAT22(DAT_2000_ca93,DAT_2000_ca91);
    DAT_2000_ca91 = (undefined2)lVar3;
    DAT_2000_ca93 = (undefined2)((ulong)lVar3 >> 0x10);
    uVar11 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_14 << 2) >> 0x10);
    iVar6 = (int)*(undefined4 *)((uint)bStack_14 << 2);
    iVar10 = *(int *)(iVar6 + 0x58);
    uVar12 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_14 << 2) >> 0x10);
    iVar7 = (int)*(undefined4 *)((uint)bStack_14 << 2);
    iVar8 = *(int *)(iVar7 + 0x8c);
    if ((iVar8 <= iVar10) &&
       ((iVar8 < iVar10 || (*(uint *)(iVar7 + 0x8a) < *(uint *)(iVar6 + 0x56))))) {
      uVar12 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_14 << 2) >> 0x10);
      iVar10 = (int)*(undefined4 *)((uint)bStack_14 << 2);
      uVar11 = *(undefined2 *)(iVar10 + 0x8a);
      uVar13 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_14 << 2) >> 0x10);
      iVar8 = (int)*(undefined4 *)((uint)bStack_14 << 2);
      *(undefined2 *)(iVar8 + 0x58) = *(undefined2 *)(iVar10 + 0x8c);
      *(undefined2 *)(iVar8 + 0x56) = uVar11;
      lVar3 = CONCAT22(DAT_2000_ca93,DAT_2000_ca91);
    }
    DAT_2000_ca93 = (undefined2)((ulong)lVar3 >> 0x10);
    DAT_2000_ca91 = (undefined2)lVar3;
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
    ovr_inputUpdate(0x36);
  }
  return;
}



/* 7e7c:2e8e */

uint __cdecl16far constrct_7e7c_2e8e(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined2 uVar8;
  
  uVar8 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
  iVar5 = (int)DAT_2000_ca95;
  if (*(char *)(iVar5 + param_1 * 9 + 2) == -1) {
    uVar2 = param_1 * 9 & 0xff00;
  }
  else {
    bVar4 = *(byte *)(iVar5 + param_1 * 9 + 2);
    uVar1 = *(undefined4 *)((uint)bVar4 << 2);
    if (*(char *)((int)uVar1 + 0x3f) == '\0') {
      iVar5 = ovr_OVC23_55fe_3450(*(undefined2 *)(iVar5 + param_1 * 9 + 4));
      uVar2 = *(uint *)((int)DAT_2000_ca95 + param_1 * 9 + 6);
      uVar7 = 0;
      uVar3 = uVar2;
      for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
        uVar3 = *(uint *)((int)DAT_2000_cb09 + uVar2 * 0x128 + (iVar5 + iVar6) * 2 + -4) & 0x1000;
        uVar7 = uVar7 | uVar3;
      }
      bVar4 = (byte)(uVar3 >> 8);
      if (uVar7 == 0) {
        uVar2 = CONCAT11(bVar4,1);
      }
      else {
        uVar2 = (uint)bVar4 << 8;
      }
    }
    else {
      uVar2 = (uint)(bVar4 >> 6) << 8;
    }
  }
  return uVar2;
}


