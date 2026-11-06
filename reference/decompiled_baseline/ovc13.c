/*
 * ovc13.c - recovered from STRONG.EXE
 * memory block: OVC13
 * range: 3d16:0000 - 3d16:1f4f
 * functions: 20
 */
#include "recovered.h"


/* 3d16:0000 */

void __cdecl16far OVC13_3d16_0000(void)

{
  far_t gfx;
  
  if (GMenuFlag == '\0') {
    DAT_2000_d108 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    DAT_2000_d106 = *(undefined2 *)BDA_DailyTimeCounter;
    if (5 < DAT_2000_d100) {
      DAT_2000_d100 = 0;
    }
    gfx.seg = ((undefined2 *)&DAT_2000_d11d)[(uint)DAT_2000_d100 * 2];
    gfx.ofs = ((undefined2 *)&DAT_2000_d11b)[(uint)DAT_2000_d100 * 2];
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000db93)));
    DAT_2000_d100 = DAT_2000_d100 + 1;
  }
  return;
}



/* 3d16:005b */

/* WARNING: Removing unreachable block (ram,0x0003d1f7) */

void __cdecl16far OVC13_3d16_005b(void)

{
  undefined2 unaff_SS;
  ulong uVar1;
  uint8_t local_1e [6];
  undefined1 local_18 [6];
  undefined1 local_12 [6];
  brect_t local_c;
  
  F_SCOPY(local_1e,(uint8_t *)0x846,0x12);
  F_SCOPY((uint8_t *)&local_c,(uint8_t *)0x858,10);
  uVar1 = ovr_attact_3f0b_082f(CONCAT22(DAT_2000_d103,DAT_2000_d101));
  if (((int)(uVar1 >> 0x10) != 0) || (8 < (uint)uVar1)) {
    DAT_2000_d103 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    DAT_2000_d101 = *(undefined2 *)BDA_DailyTimeCounter;
    DAT_2000_d105 = 1 - (DAT_2000_d105 != 0);
    ovr_vgaSetPalette(local_1e + (uint)DAT_2000_d105 * 3);
    ovr_vgaSetPalette(local_18 + (uint)DAT_2000_d105 * 3);
    ovr_vgaSetPalette(local_12 + (uint)DAT_2000_d105 * 3);
  }
  if (((DAT_2410_0845 == '\0') && (GPaused == '\0')) && (DAT_2000_d116 == '\x01')) {
    uVar1 = ovr_attact_3f0b_082f(CONCAT22(DAT_2000_d108,DAT_2000_d106));
    if (((int)(uVar1 >> 0x10) != 0) || (3 < (uint)uVar1)) {
      ovr_miceRestoreArea((brect_t *)CONCAT22(unaff_SS,&local_c));
      OVC13_3d16_0000();
      ovr_miceBlitRect((brect_t *)CONCAT22(unaff_SS,&local_c));
    }
  }
  return;
}



/* 3d16:0186 */

undefined2 __cdecl16far OVC13_3d16_0186(int param_1,int param_2,undefined4 param_3)

{
  return CONCAT11((char)((uint)(param_2 * 0x140) >> 8),*(undefined1 *)(param_1 + param_2 * 0x140));
}



/* 3d16:01a4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl16far OVC13_3d16_01a4(int param_1,int param_2)

{
  int iVar1;
  
  if ((((param_1 + Seed_2000_d110 < 0x94) &&
       (SCARRY2(param_1,Seed_2000_d110) == param_1 + Seed_2000_d110 < 0)) &&
      (Seed_2000_d10e + param_2 < 0x3c)) &&
     (SCARRY2(Seed_2000_d10e,param_2) == Seed_2000_d10e + param_2 < 0)) {
    iVar1 = (int)*(char *)((int)DAT_2000_cb05 + (Seed_2000_d10e + param_2) * 0x94 + param_1 +
                          Seed_2000_d110);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 3d16:01fb */

undefined2 __cdecl16far OVC13_3d16_01fb(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if ((((param_1 + Seed_2000_d110 < 0x94) &&
       (SCARRY2(param_1,Seed_2000_d110) == param_1 + Seed_2000_d110 < 0)) &&
      (Seed_2000_d10e + param_2 < 0x3c)) &&
     (SCARRY2(Seed_2000_d10e,param_2) == Seed_2000_d10e + param_2 < 0)) {
    uVar1 = *(undefined2 *)
             ((int)DAT_2000_cb09 + (Seed_2000_d10e + param_2) * 0x128 +
             (param_1 + Seed_2000_d110) * 2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 3d16:0255 */

void __cdecl16far OVC13_3d16_0255(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint16_t uVar5;
  uint uVar6;
  uint16_t uVar7;
  int iStack_c;
  char cStack_3;
  
  for (uVar6 = 0; uVar6 < EntityCount; uVar6 = uVar6 + 1) {
    uVar7 = Entities.seg;
    uVar5 = Entities.ofs;
    iVar3 = *(int *)(uVar5 + uVar6 * 0x37);
    iVar2 = *(int *)(uVar5 + uVar6 * 0x37 + 2) + 1;
    if (((((*(char *)(uVar5 + uVar6 * 0x37 + 0x18) != '\0') ||
          (*(char *)((int)(char **)GMenuStrings + iStack_c * 0x95 + 0x1f) == '\0')) ||
         (DebugVerbose != false)) ||
        ((*(uint *)(iVar2 * 0x128 + (int)DAT_2000_cb09 + iVar3 * 2 + -0x128) & 8) != 0)) &&
       (((cVar1 = OVC13_3d16_1045(uVar6), cVar1 != '\0' && (DAT_2000_d10c <= iVar3)) &&
        ((iVar3 <= DAT_2000_d10c + 0x22 &&
         ((DAT_2000_d10a <= iVar2 && (iVar2 <= DAT_2000_d10a + 0xf)))))))) {
      iVar4 = (iVar2 - DAT_2000_d10a) * 3 + 7;
      iVar3 = (iVar3 - DAT_2000_d10c) * 2;
      iVar2 = iVar3 + 0xef;
      cStack_3 = OVC13_3d16_0186(iVar2,iVar4,0x45e,(char *)"puppetmaker" + 3);
      uVar7 = Entities.seg;
      uVar5 = Entities.ofs;
      if (*(char *)(uVar5 + uVar6 * 0x37 + 0x18) == '\0') {
        if ((*(uint *)(uVar5 + uVar6 * 0x37 + 0x14) & 1) == 0) {
          if ((*(byte *)(uVar5 + uVar6 * 0x37 + 0x33) & 1) == 0) {
            if (((cStack_3 != -0x11) && (cStack_3 != -0x12)) && (cStack_3 != -0x15)) {
              if (*(char *)((int)(char **)GMenuStrings +
                           (uint)*(byte *)(uVar5 + uVar6 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0') {
                cStack_3 = -1;
              }
              else {
                cStack_3 = -0x16;
              }
            }
          }
          else {
            cStack_3 = -0x12;
          }
        }
        else {
          cStack_3 = -0x15;
        }
      }
      else {
        cStack_3 = -0x11;
      }
      ovr_driver_2d63_09c9(iVar2,iVar2,iVar4,cStack_3,0x45e,(char *)"puppetmaker" + 3);
      ovr_driver_2d63_09c9(iVar3 + 0xf0,iVar3 + 0xf0,iVar4,0xec,0x45e,(char *)"puppetmaker" + 3);
    }
  }
  return;
}



/* 3d16:0472 */

void __cdecl16far OVC13_3d16_0472(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint16_t uVar4;
  uint uVar5;
  uint16_t uVar6;
  char cStack_3;
  
  if (DAT_2410_4b6d == -1) {
    for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
      uVar6 = Entities.seg;
      uVar4 = Entities.ofs;
      iVar2 = *(int *)(uVar4 + uVar5 * 0x37);
      iVar1 = *(int *)(uVar4 + uVar5 * 0x37 + 2) + 1;
      if (((((*(char *)(uVar4 + uVar5 * 0x37 + 0x18) != '\0') ||
            (*(char *)((int)(char **)GMenuStrings +
                      (uint)*(byte *)(uVar4 + uVar5 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0')) ||
           ((*(uint *)(iVar1 * 0x128 + (int)DAT_2000_cb09 + iVar2 * 2 + -0x128) & 8) != 0)) &&
          ((DAT_2000_d10c <= iVar2 && (iVar2 <= DAT_2000_d10c + 0x22)))) &&
         ((DAT_2000_d10a <= iVar1 && (iVar1 <= DAT_2000_d10a + 0xf)))) {
        iVar3 = (iVar1 - DAT_2000_d10a) * 3 + 7;
        iVar2 = (iVar2 - DAT_2000_d10c) * 2;
        iVar1 = iVar2 + 0xef;
        cStack_3 = OVC13_3d16_0186(iVar1,iVar3,0x45e,(char *)"puppetmaker" + 3);
        uVar6 = Entities.seg;
        uVar4 = Entities.ofs;
        if (*(char *)(uVar4 + uVar5 * 0x37 + 0x18) == '\0') {
          if ((*(uint *)(uVar4 + uVar5 * 0x37 + 0x14) & 1) == 0) {
            if ((*(byte *)(uVar4 + uVar5 * 0x37 + 0x33) & 1) == 0) {
              if (((cStack_3 != -0x11) && (cStack_3 != -0x12)) && (cStack_3 != -0x15)) {
                if (*(char *)((int)(char **)GMenuStrings +
                             (uint)*(byte *)(uVar4 + uVar5 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0') {
                  cStack_3 = -1;
                }
                else {
                  cStack_3 = -0x16;
                }
              }
            }
            else {
              cStack_3 = -0x12;
            }
          }
          else {
            cStack_3 = -0x15;
          }
        }
        else {
          cStack_3 = -0x11;
        }
        ovr_driver_2d63_09c9(iVar1,iVar1,iVar3,cStack_3,0x45e,(char *)"puppetmaker" + 3);
        ovr_driver_2d63_09c9(iVar2 + 0xf0,iVar2 + 0xf0,iVar3,0xec,0x45e,(char *)"puppetmaker" + 3);
      }
    }
  }
  else {
    OVC13_3d16_0255();
  }
  return;
}



/* 3d16:06a2 */

void __cdecl16far OVC13_3d16_06a2(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte bStack_3;
  
  bVar2 = ovr_manage_4d05_1b1d();
  for (bStack_3 = 0; bStack_3 < DAT_2000_d1e6; bStack_3 = bStack_3 + 1) {
    if (*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3d) != '\0') {
      iVar3 = *(int *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x39);
      iVar1 = *(int *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3b);
      if ((((*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3f) == '\0') ||
           (DebugVerbose != false)) ||
          ((*(uint *)((int)DAT_2000_cb09 + iVar1 * 0x128 + iVar3 * 2) & 8) != 0)) &&
         (((DAT_2000_d10c <= iVar3 && (iVar3 <= DAT_2000_d10c + 0x22)) &&
          ((DAT_2000_d10a <= iVar1 + 1 && (iVar1 <= DAT_2000_d10a + 0xf)))))) {
        iVar1 = (iVar1 - DAT_2000_d10a) * 3;
        iVar3 = (iVar3 - DAT_2000_d10c) * 2;
        iVar4 = iVar3 + 0xed;
        if (bVar2 == bStack_3) {
          ovr_driver_2d63_09c9
                    (iVar3 + 0xeb,iVar3 + 0xf2,iVar1 + 9,0x75,0x45e,(char *)"puppetmaker" + 3);
          ovr_driver_2d63_09c9
                    (iVar3 + 0xeb,iVar3 + 0xf2,iVar1 + 10,0x75,0x45e,(char *)"puppetmaker" + 3);
          ovr_driver_2d63_09c9
                    (iVar3 + 0xeb,iVar3 + 0xf2,iVar1 + 0xb,0x75,0x45e,(char *)"puppetmaker" + 3);
        }
        else {
          ovr_driver_2d63_09c9(iVar4,iVar3 + 0xf0,iVar1 + 9,0x75,0x45e,(char *)"puppetmaker" + 3);
          ovr_driver_2d63_09c9(iVar4,iVar3 + 0xf0,iVar1 + 10,0x75,0x45e,(char *)"puppetmaker" + 3);
          ovr_driver_2d63_09c9(iVar4,iVar3 + 0xf0,iVar1 + 0xb,0x75,0x45e,(char *)"puppetmaker" + 3);
        }
      }
    }
  }
  return;
}



/* 3d16:0883 */

void __cdecl16far
OVC13_3d16_0883(int param_1,int param_2,byte param_3,byte param_4,undefined2 param_5)

{
  undefined1 *puVar1;
  undefined4 uStack_6;
  
  puVar1 = (undefined1 *)(param_1 + param_2 * 0x140);
  uStack_6 = (undefined1 *)CONCAT22(param_5,puVar1);
  if ((param_3 & 1) != 0) {
    puVar1[0x140] = 0xfd;
    puVar1[0x141] = 0xfd;
  }
  if ((param_3 & 2) != 0) {
    *uStack_6 = 0xfd;
    puVar1[0x140] = 0xfd;
  }
  if (((param_4 & 2) != 0) && (puVar1[0x280] = 0xfd, (param_4 & 1) != 0)) {
    puVar1[0x281] = 0xfd;
  }
  return;
}



/* 3d16:08ee */

void __cdecl16far OVC13_3d16_08ee(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  uint16_t uVar7;
  int iVar8;
  undefined1 uVar11;
  undefined2 uVar9;
  int iVar10;
  int iVar12;
  undefined1 *puVar13;
  uint *puVar14;
  int iVar15;
  undefined1 uStack_26;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint uStack_8;
  int iStack_6;
  
  uVar7 = BlitRects[3].seg;
  DAT_2000_d10c = GfxRndSeed + -0x11;
  DAT_2000_d10a = GfxRndSeed2 + -8;
  if (DAT_2000_d10c < 0) {
    DAT_2000_d10c = 0;
  }
  if (DAT_2000_d10a < 0) {
    DAT_2000_d10a = 0;
  }
  if (0x92 < DAT_2000_d10c + 0x22) {
    DAT_2000_d10c = 0x70;
  }
  if (0x3a < DAT_2000_d10a + 0xf) {
    DAT_2000_d10a = 0x2b;
  }
  uStack_8 = 7;
  for (iStack_6 = 0; iStack_6 < 0x10; iStack_6 = iStack_6 + 1) {
    iVar15 = 0xef;
    iVar8 = (DAT_2000_d10a + iStack_6) * 0x94 + DAT_2000_cb05 + DAT_2000_d10c;
    uStack_10 = (undefined1 *)CONCAT22(DAT_2000_cb07,(undefined1 *)(iVar8 + 0x94));
    puVar13 = (undefined1 *)(DAT_2000_cb05 + (DAT_2000_d10a + iStack_6) * 0x94 + DAT_2000_d10c);
    uStack_14 = (undefined1 *)CONCAT22(DAT_2000_cb07,puVar13);
    puVar14 = (uint *)((int)DAT_2000_cb09 + (DAT_2000_d10a + iStack_6) * 0x128 + DAT_2000_d10c * 2);
    uStack_18 = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(DAT_2000_cb09) + 2)),puVar14);
    if (DAT_2000_d10a + iStack_6 != 0 &&
        SCARRY2(DAT_2000_d10a,iStack_6) == DAT_2000_d10a + iStack_6 < 0) {
      puVar14 = (uint *)((DAT_2000_d10a + iStack_6) * 0x128 + (int)DAT_2000_cb09 + DAT_2000_d10c * 2
                        + -0x128);
    }
    uStack_1c = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(DAT_2000_cb09) + 2)),puVar14);
    uVar1 = *uStack_10;
    uStack_10 = (undefined1 *)CONCAT22(DAT_2000_cb07,(undefined1 *)(iVar8 + 0x95));
    uVar2 = *uStack_14;
    uStack_14 = (undefined1 *)CONCAT22(DAT_2000_cb07,puVar13 + 1);
    for (iVar8 = 0; iVar8 < 0x23; iVar8 = iVar8 + 1) {
      uVar3 = *uStack_10;
      uStack_10 = (undefined1 *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_10) + 2)),(undefined1 *)uStack_10 + 1);
      uVar4 = *uStack_14;
      uStack_14 = (undefined1 *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_14) + 2)),(undefined1 *)uStack_14 + 1);
      uVar5 = *uStack_18;
      uStack_18 = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_18) + 2)),(uint *)uStack_18 + 1);
      uVar6 = *uStack_1c;
      uStack_1c = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_1c) + 2)),(uint *)uStack_1c + 1);
      uVar11 = (undefined1)(uVar6 >> 8);
      uStack_26 = (undefined1)uVar5;
      if ((uVar5 & 4) == 0) {
        uVar9 = ovr_constr_36ce_049f
                          (CONCAT11(uVar11,uVar1),CONCAT11(uVar11,uVar3),CONCAT11(uVar11,uVar2),
                           CONCAT11(uVar11,uStack_26),1,uVar7);
        uVar9 = ovr_constr_36ce_049f(uVar2,uVar4,uVar3,uVar5 & 0xff,2,uVar9);
        ovr_driver_2d63_0687(iVar15,uStack_8 & 0xff,uVar9);
      }
      else {
        uVar9 = ovr_constr_36ce_049f
                          (CONCAT11(uVar11,uVar1),CONCAT11(uVar11,uVar3),CONCAT11(uVar11,uVar4),
                           CONCAT11(uVar11,uStack_26),2,uVar7);
        uVar9 = ovr_constr_36ce_049f(uVar2,uVar4,uVar1,uVar5 & 0xff,1,uVar9);
        ovr_driver_2d63_0652(iVar15,uStack_8 & 0xff,uVar9);
      }
      if (((uVar5 | uVar6) & 0xc000) != 0) {
        OVC13_3d16_0883(iVar15,uStack_8,uVar6 >> 0xe,uVar5 >> 0xe,uVar7);
      }
      iVar15 = iVar15 + 2;
      uVar2 = uVar4;
      uVar1 = uVar3;
    }
    uStack_8 = uStack_8 + 3;
  }
  OVC13_3d16_06a2();
  iVar15 = (GfxRndSeed - DAT_2000_d10c) * 2;
  iVar10 = iVar15 + 0xea;
  iVar8 = (GfxRndSeed2 - DAT_2000_d10a) * 3;
  iVar12 = iVar8 + 8;
  ovr_driver_2d63_09c9(iVar10,iVar15 + 0xf3,iVar12,0xe0,0x45e,(char *)"puppetmaker" + 3);
  ovr_driver_2d63_09c9(iVar10,iVar15 + 0xf3,iVar8 + 0xc,0xe0,0x45e,(char *)"puppetmaker" + 3);
  ovr_OVC07_32c9_03c4(iVar10,iVar12,iVar10,iVar8 + 0xc,0xe0,0x45e,(char *)"puppetmaker" + 3);
  ovr_OVC07_32c9_03c4(iVar15 + 0xf3,iVar12,iVar15 + 0xf3,iVar8 + 0xc,0xe0,0x45e,
                      (char *)"puppetmaker" + 3);
  OVC13_3d16_0472();
  return;
}



/* 3d16:0c22 */

void __cdecl16far OVC13_3d16_0c22(int param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  
  iVar1 = param_2 * 3;
  iVar6 = param_1 * 2;
  iVar7 = iVar6 + 0xc;
  uVar2 = OVC13_3d16_01a4(param_1,param_2 + 1);
  uVar3 = OVC13_3d16_01a4(param_1,param_2);
  uVar4 = OVC13_3d16_01a4(param_1 + 1,param_2 + 1);
  uVar5 = OVC13_3d16_01a4(param_1 + 1,param_2);
  uVar8 = OVC13_3d16_01fb(param_1,param_2);
  if ((uVar8 & 4) == 0) {
    uVar5 = ovr_constr_36ce_049f(uVar3,uVar5,uVar4,uVar8,2);
    ovr_driver_2d63_09c9(iVar7,iVar6 + 0xd,iVar1 + 7,uVar5,0x440,(char *)"puppetmaker" + 3);
    ovr_driver_2d63_09c9(iVar6 + 0xd,iVar6 + 0xd,iVar1 + 8,uVar5,0x440,(char *)"puppetmaker" + 3);
    uVar2 = ovr_constr_36ce_049f
                      (CONCAT11(extraout_AH_00,uVar2),CONCAT11(extraout_AH_00,uVar4),
                       CONCAT11(extraout_AH_00,uVar3),CONCAT11(extraout_AH_00,(char)uVar8),1);
    ovr_driver_2d63_09c9(iVar7,iVar7,iVar1 + 8,uVar2,0x440,(char *)"puppetmaker" + 3);
    ovr_driver_2d63_09c9(iVar7,iVar6 + 0xd,iVar1 + 9,uVar2,0x440,(char *)"puppetmaker" + 3);
  }
  else {
    uVar3 = ovr_constr_36ce_049f(uVar3,uVar5,uVar2,uVar8,1);
    ovr_driver_2d63_09c9(iVar7,iVar6 + 0xd,iVar1 + 7,uVar3,0x440,(char *)"puppetmaker" + 3);
    ovr_driver_2d63_09c9(iVar7,iVar7,iVar1 + 8,uVar3,0x440,(char *)"puppetmaker" + 3);
    uVar2 = ovr_constr_36ce_049f
                      (CONCAT11(extraout_AH,uVar2),CONCAT11(extraout_AH,uVar4),
                       CONCAT11(extraout_AH,uVar5),CONCAT11(extraout_AH,(char)uVar8),2);
    ovr_driver_2d63_09c9(iVar6 + 0xd,iVar6 + 0xd,iVar1 + 8,uVar2,0x440,(char *)"puppetmaker" + 3);
    ovr_driver_2d63_09c9(iVar7,iVar6 + 0xd,iVar1 + 9,uVar2,0x440,(char *)"puppetmaker" + 3);
  }
  return;
}



/* 3d16:0e03 */

void __cdecl16far OVC13_3d16_0e03(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint16_t uVar6;
  uint uVar7;
  uint16_t uVar8;
  char cStack_3;
  
  if (DAT_2410_4b6d == -1) {
    for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
      uVar8 = Entities.seg;
      uVar6 = Entities.ofs;
      uVar1 = *(uint *)(uVar6 + uVar7 * 0x37);
      uVar2 = *(int *)(uVar6 + uVar7 * 0x37 + 2) + 1;
      if (((((*(char *)(uVar6 + uVar7 * 0x37 + 0x18) != '\0') ||
            (*(char *)((int)(char **)GMenuStrings +
                      (uint)*(byte *)(uVar6 + uVar7 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0')) ||
           (DebugVerbose != false)) ||
          ((*(uint *)(uVar2 * 0x128 + (int)DAT_2000_cb09 + uVar1 * 2 + -0x128) & 8) != 0)) &&
         (((Seed_2000_d110 <= (int)uVar1 && (uVar1 <= Seed_2000_d110 + 0x69U)) &&
          ((Seed_2000_d10e <= (int)uVar2 && (uVar2 <= Seed_2000_d10e + 0x2fU)))))) {
        iVar5 = (uVar2 - Seed_2000_d10e) * 3 + 7;
        iVar3 = (uVar1 - Seed_2000_d110) * 2;
        iVar4 = iVar3 + 0xd;
        iVar3 = iVar3 + 0xc;
        cStack_3 = OVC13_3d16_0186(iVar3,iVar5,0x440,(char *)"puppetmaker" + 3);
        uVar8 = Entities.seg;
        uVar6 = Entities.ofs;
        if (*(char *)(uVar6 + uVar7 * 0x37 + 0x18) == '\0') {
          if ((*(uint *)(uVar6 + uVar7 * 0x37 + 0x14) & 1) == 0) {
            if ((*(byte *)(uVar6 + uVar7 * 0x37 + 0x33) & 1) == 0) {
              if (((cStack_3 != -0x11) && (cStack_3 != -0x12)) && (cStack_3 != -0x15)) {
                if (*(char *)((int)(char **)GMenuStrings +
                             (uint)*(byte *)(uVar6 + uVar7 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0') {
                  cStack_3 = -1;
                }
                else {
                  cStack_3 = -0x16;
                }
              }
            }
            else {
              cStack_3 = -0x12;
            }
          }
          else {
            cStack_3 = -0x15;
          }
        }
        else {
          cStack_3 = -0x11;
        }
        ovr_driver_2d63_09c9(iVar3,iVar3,iVar5,cStack_3,0x440,(char *)"puppetmaker" + 3);
        ovr_driver_2d63_09c9(iVar4,iVar4,iVar5,0xec,0x440,(char *)"puppetmaker" + 3);
      }
    }
  }
  else {
    OVC13_3d16_113d();
  }
  return;
}



/* 3d16:1045 */

int __cdecl16far OVC13_3d16_1045(int param_1)

{
  int iVar1;
  byte bVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  
  uVar3 = Entities.ofs;
  uVar4 = Entities.seg;
  if (DAT_2410_4b6d == 0xfe) {
LAB_3d16_10c4:
    if (DAT_2410_4b6e == -1) {
      if (*(char *)((int)(char **)GMenuStrings +
                   (uint)*(byte *)(uVar3 + param_1 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0') {
        iVar1 = 1;
      }
      else {
        iVar1 = 0;
      }
    }
    else {
      bVar2 = (byte)((uint)(param_1 * 0x37) >> 8);
      if (*(char *)(uVar3 + param_1 * 0x37 + 0x1a) == DAT_2410_4b6e) {
        iVar1 = CONCAT11(bVar2,1);
      }
      else {
        iVar1 = (uint)bVar2 << 8;
      }
    }
  }
  else {
    if ((byte)((undefined1 *)&DAT_2410_4aee)[DAT_2410_4b6d] <=
        *(byte *)(uVar3 + param_1 * 0x37 + 0xf)) {
      if (*(byte *)(uVar3 + param_1 * 0x37 + 0xf) <=
          (byte)((undefined1 *)&DAT_2410_4afa)[DAT_2410_4b6d]) goto LAB_3d16_10c4;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 3d16:113d */

void __cdecl16far OVC13_3d16_113d(void)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint16_t uVar7;
  uint uVar8;
  uint16_t uVar9;
  int iStack_c;
  char cStack_3;
  
  for (uVar8 = 0; uVar8 < EntityCount; uVar8 = uVar8 + 1) {
    uVar9 = Entities.seg;
    uVar7 = Entities.ofs;
    uVar1 = *(uint *)(uVar7 + uVar8 * 0x37);
    uVar3 = *(int *)(uVar7 + uVar8 * 0x37 + 2) + 1;
    if (((((*(char *)(uVar7 + uVar8 * 0x37 + 0x18) != '\0') ||
          (*(char *)((int)(char **)GMenuStrings + iStack_c * 0x95 + 0x1f) == '\0')) ||
         (DebugVerbose != false)) ||
        ((*(uint *)(uVar3 * 0x128 + (int)DAT_2000_cb09 + uVar1 * 2 + -0x128) & 8) != 0)) &&
       (((cVar2 = OVC13_3d16_1045(uVar8), cVar2 != '\0' && (Seed_2000_d110 <= (int)uVar1)) &&
        ((uVar1 <= Seed_2000_d110 + 0x69U &&
         ((Seed_2000_d10e <= (int)uVar3 && (uVar3 <= Seed_2000_d10e + 0x2fU)))))))) {
      iVar6 = (uVar3 - Seed_2000_d10e) * 3 + 7;
      iVar4 = (uVar1 - Seed_2000_d110) * 2;
      iVar5 = iVar4 + 0xd;
      iVar4 = iVar4 + 0xc;
      cStack_3 = OVC13_3d16_0186(iVar4,iVar6,0x440,(char *)"puppetmaker" + 3);
      uVar9 = Entities.seg;
      uVar7 = Entities.ofs;
      if (*(char *)(uVar7 + uVar8 * 0x37 + 0x18) == '\0') {
        if ((*(uint *)(uVar7 + uVar8 * 0x37 + 0x14) & 1) == 0) {
          if ((*(byte *)(uVar7 + uVar8 * 0x37 + 0x33) & 1) == 0) {
            if (((cStack_3 != -0x11) && (cStack_3 != -0x12)) && (cStack_3 != -0x15)) {
              if (*(char *)((int)(char **)GMenuStrings +
                           (uint)*(byte *)(uVar7 + uVar8 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0') {
                cStack_3 = -1;
              }
              else {
                cStack_3 = -0x16;
              }
            }
          }
          else {
            cStack_3 = -0x12;
          }
        }
        else {
          cStack_3 = -0x15;
        }
      }
      else {
        cStack_3 = -0x11;
      }
      ovr_driver_2d63_09c9(iVar4,iVar4,iVar6,cStack_3,0x440,(char *)"puppetmaker" + 3);
      ovr_driver_2d63_09c9(iVar5,iVar5,iVar6,0xec,0x440,(char *)"puppetmaker" + 3);
    }
  }
  return;
}



/* 3d16:135d */

void __cdecl16far OVC13_3d16_135d(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  byte bStack_3;
  
  if (Highlight1 == -1) {
    bVar4 = ovr_manage_4d05_1b1d();
    for (bStack_3 = 0; bStack_3 < DAT_2000_d1e6; bStack_3 = bStack_3 + 1) {
      if (*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3d) != '\0') {
        uVar1 = *(uint *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x39);
        uVar2 = *(uint *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3b);
        if ((((*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3f) == '\0') ||
             (DebugVerbose != false)) ||
            ((*(uint *)((int)DAT_2000_cb09 + uVar2 * 0x128 + uVar1 * 2) & 8) != 0)) &&
           (((Seed_2000_d110 <= (int)uVar1 && (uVar1 <= Seed_2000_d110 + 0x69U)) &&
            ((Seed_2000_d10e <= (int)uVar2 && (uVar2 <= Seed_2000_d10e + 0x2fU)))))) {
          iVar3 = (uVar2 - Seed_2000_d10e) * 3;
          iVar5 = (uVar1 - Seed_2000_d110) * 2;
          iVar6 = iVar5 + 10;
          if (bVar4 == bStack_3) {
            ovr_driver_2d63_09c9
                      (iVar5 + 8,iVar5 + 0xf,iVar3 + 9,0x75,0x440,(char *)"puppetmaker" + 3);
            ovr_driver_2d63_09c9
                      (iVar5 + 8,iVar5 + 0xf,iVar3 + 10,0x75,0x440,(char *)"puppetmaker" + 3);
            ovr_driver_2d63_09c9
                      (iVar5 + 8,iVar5 + 0xf,iVar3 + 0xb,0x75,0x440,(char *)"puppetmaker" + 3);
          }
          else {
            ovr_driver_2d63_09c9(iVar6,iVar5 + 0xd,iVar3 + 9,0x75,0x440,(char *)"puppetmaker" + 3);
            ovr_driver_2d63_09c9(iVar6,iVar5 + 0xd,iVar3 + 10,0x75,0x440,(char *)"puppetmaker" + 3);
            ovr_driver_2d63_09c9(iVar6,iVar5 + 0xd,iVar3 + 0xb,0x75,0x440,(char *)"puppetmaker" + 3)
            ;
          }
        }
      }
    }
  }
  return;
}



/* 3d16:1558 */

void __cdecl16far OVC13_3d16_1558(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar8;
  undefined2 uVar6;
  undefined2 uVar7;
  char *pcVar9;
  uint *puVar10;
  char *text;
  byte *widths;
  uint16_t seg;
  uint8_t term;
  char local_7a [80];
  uint uStack_2a;
  uint uStack_28;
  int iStack_26;
  int iStack_24;
  uint16_t uStack_22;
  int iStack_20;
  int iStack_1e;
  int iStack_1c;
  int iStack_1a;
  int iStack_18;
  int iStack_16;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined2 uStack_4;
  
  Seed_2000_d110 = GfxRndSeed + -0x35;
  Seed_2000_d10e = GfxRndSeed2 + -0x18;
  if (Seed_2000_d110 < 0) {
    Seed_2000_d110 = 0;
  }
  if (Seed_2000_d10e < 0) {
    Seed_2000_d10e = 0;
  }
  if (0x92 < Seed_2000_d110 + 0x69U) {
    Seed_2000_d110 = 0x29;
  }
  if (0x3a < Seed_2000_d10e + 0x2fU) {
    Seed_2000_d10e = 0xb;
  }
  uStack_22 = BlitRects[0].seg;
  iStack_18 = 7;
  for (iStack_16 = 0; iStack_16 < 0x30; iStack_16 = iStack_16 + 1) {
    iVar5 = (Seed_2000_d10e + iStack_16) * 0x94 + DAT_2000_cb05 + Seed_2000_d110;
    uStack_8 = (char *)CONCAT22(DAT_2000_cb07,(char *)(iVar5 + 0x94));
    pcVar9 = (char *)(DAT_2000_cb05 + (Seed_2000_d10e + iStack_16) * 0x94 + Seed_2000_d110);
    uStack_c = (char *)CONCAT22(DAT_2000_cb07,pcVar9);
    puVar10 = (uint *)((int)DAT_2000_cb09 + (Seed_2000_d10e + iStack_16) * 0x128 +
                      Seed_2000_d110 * 2);
    uStack_10 = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(DAT_2000_cb09) + 2)),puVar10);
    if (Seed_2000_d10e + iStack_16 != 0 &&
        SCARRY2(Seed_2000_d10e,iStack_16) == Seed_2000_d10e + iStack_16 < 0) {
      puVar10 = (uint *)((Seed_2000_d10e + iStack_16) * 0x128 + (int)DAT_2000_cb09 +
                         Seed_2000_d110 * 2 + -0x128);
    }
    uStack_14 = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(DAT_2000_cb09) + 2)),puVar10);
    iStack_1c = (int)*uStack_8;
    uStack_8 = (char *)CONCAT22(DAT_2000_cb07,(char *)(iVar5 + 0x95));
    iStack_20 = (int)*uStack_c;
    uStack_c = (char *)CONCAT22(DAT_2000_cb07,pcVar9 + 1);
    for (iVar5 = 0; iVar5 < 0x69; iVar5 = iVar5 + 1) {
      iStack_1a = iStack_1c;
      iVar4 = iStack_1a;
      iStack_1e = iStack_20;
      iVar3 = iStack_1e;
      cVar1 = *uStack_8;
      uStack_8 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_8) + 2)),(char *)uStack_8 + 1);
      cVar2 = *uStack_c;
      uStack_c = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_c) + 2)),(char *)uStack_c + 1);
      uStack_28 = *uStack_10;
      uStack_10 = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_10) + 2)),(uint *)uStack_10 + 1);
      uStack_2a = *uStack_14;
      uStack_14 = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_14) + 2)),(uint *)uStack_14 + 1);
      uVar8 = (undefined1)(uStack_2a >> 8);
      (*(uint8_t *)((uint8_t *)&(iStack_1a))) = (undefined1)iStack_1c;
      iStack_1c = (int)cVar1;
      iStack_1a = iVar4;
      if ((uStack_28 & 4) == 0) {
        (*(uint8_t *)((uint8_t *)&(iStack_1e))) = (undefined1)iStack_20;
        uVar6 = CONCAT11(uVar8,(undefined1)iStack_1e);
        uVar7 = CONCAT11(uVar8,(undefined1)iStack_1a);
        iStack_20 = (int)cVar2;
        iStack_1e = iVar3;
        ovr_constr_36ce_049f
                  (uVar7,CONCAT11(uVar8,cVar1),uVar6,CONCAT11(uVar8,(undefined1)uStack_28),1,
                   uStack_22);
        ovr_constr_36ce_049f();
        ovr_driver_2d63_0687();
      }
      else {
        uVar6 = CONCAT11(uVar8,(undefined1)iStack_1a);
        iStack_20 = (int)cVar2;
        ovr_constr_36ce_049f
                  (uVar6,CONCAT11(uVar8,cVar1),CONCAT11(uVar8,cVar2),
                   CONCAT11(uVar8,(undefined1)uStack_28),2,uStack_22);
        ovr_constr_36ce_049f();
        ovr_driver_2d63_0652();
      }
      if (((uStack_28 | uStack_2a) & 0xc000) != 0) {
        OVC13_3d16_0883();
      }
    }
    OVC13_3d16_0c22(0x69,iStack_16);
    iStack_18 = iStack_18 + 3;
  }
  OVC13_3d16_135d();
  OVC13_3d16_1b3b();
  iVar5 = (GfxRndSeed - Seed_2000_d110) * 2;
  iStack_24 = iVar5 + 7;
  iStack_26 = (GfxRndSeed2 - Seed_2000_d10e) * 3 + 8;
  ovr_driver_2d63_09c9(iStack_24,iVar5 + 0x10,iStack_26,0xe0,0x440,(char *)"puppetmaker" + 3);
  ovr_driver_2d63_09c9(iStack_24,iStack_24 + 9,iStack_26 + 4,0xe0,0x440,(char *)"puppetmaker" + 3);
  ovr_OVC07_32c9_03c4();
  ovr_OVC07_32c9_03c4();
  OVC13_3d16_0e03();
  uStack_4 = TextBlitDstSeg;
  TextBlitDstSeg = BlitRects[0].seg;
  TextBlitX = 0xb6;
  TextBlitY = 10;
  if (GameRunning == false) {
    term = 0xe0;
    seg = 0x13f;
    widths = (byte *)Font02.ofs;
    pcVar9 = (char *)ovr_OVC23_55fe_3450(GfxRndSeed,GfxRndSeed2,Font02.ofs,Font02.seg);
    text = ovr_stsprintf(local_7a,"(%d, %d)",pcVar9);
    ovr_blitText(text,widths,seg,term);
  }
  TextBlitDstSeg = uStack_4;
  return;
}



/* 3d16:1945 */

void __cdecl16far OVC13_3d16_1945(int param_1,int param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  far_t gfx;
  
  uVar1 = Seed_2000_d110 + param_1 + 2U & 0xfffc;
  iVar2 = (param_2 + -2) / 3 + Seed_2000_d10e;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if ((int)uVar1 < 4) {
    uVar1 = 4;
  }
  if (0x93 < (int)(uVar1 + 3)) {
    uVar1 = 0x90;
  }
  if (0x39 < iVar2) {
    iVar2 = 0x39;
  }
  if (((param_3 != '\0') || (GfxRndSeed != uVar1)) || (GfxRndSeed2 != iVar2)) {
    gfx.seg = FontHandle.seg;
    gfx.ofs = FontHandle.ofs;
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)));
    ovr_attact_3f0b_0685();
    AgntFlag1 = false;
    GfxRndSeed2 = iVar2;
    GfxRndSeed = uVar1;
    ovr_OVC41_6a8f_11d2();
  }
  return;
}



/* 3d16:1a01 */

void __cdecl16far OVC13_3d16_1a01(int param_1,int param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  far_t gfx;
  
  uVar1 = DAT_2000_d10c + param_1 + 2U & 0xfffc;
  iVar2 = (param_2 + -2) / 3 + DAT_2000_d10a;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if ((int)uVar1 < 4) {
    uVar1 = 4;
  }
  if (0x93 < (int)(uVar1 + 3)) {
    uVar1 = 0x90;
  }
  if (0x39 < iVar2) {
    iVar2 = 0x39;
  }
  if (((param_3 != '\0') || (GfxRndSeed != uVar1)) || (GfxRndSeed2 != iVar2)) {
    gfx.seg = FontHandle.seg;
    gfx.ofs = FontHandle.ofs;
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)));
    ovr_attact_3f0b_0685();
    AgntFlag1 = false;
    GfxRndSeed2 = iVar2;
    GfxRndSeed = uVar1;
    ovr_OVC41_6a8f_11d2();
  }
  return;
}



/* 3d16:1abd */

void __cdecl16far OVC13_3d16_1abd(void)

{
  bool bVar1;
  
  BlitRects[3].seg = DAT_2000_d0f7;
  bVar1 = MiceNeedsUpdate == '\0';
  if (bVar1) {
    ovr_miceRestoreArea(BlitRects + 3);
  }
  OVC13_3d16_08ee();
  if (bVar1) {
    ovr_miceBlitRect(BlitRects + 3);
  }
  ovr_blitRect(BlitRects + 3);
  if (bVar1) {
    ovr_miceUpdate();
  }
  BlitRects[3].seg = 0xa000;
  return;
}



/* 3d16:1b3b */

void __cdecl16far OVC13_3d16_1b3b(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined2 uVar9;
  
  if (Highlight1 != -1) {
    for (uVar8 = 0xf8; uVar8 < DAT_2000_ca99; uVar8 = uVar8 + 1) {
      uVar9 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
      iVar7 = (int)DAT_2000_ca95;
      bVar1 = *(byte *)(iVar7 + uVar8 * 9 + 2);
      if (((bVar1 != 0xff) &&
          (uVar4 = *(undefined4 *)((uint)bVar1 << 2), *(char *)((int)uVar4 + 0x3f) == '\0')) &&
         ((*(char *)(iVar7 + uVar8 * 9 + 2) == Highlight1 || (Highlight1 == -1)))) {
        uVar2 = *(uint *)(iVar7 + uVar8 * 9 + 4);
        uVar3 = *(uint *)(iVar7 + uVar8 * 9 + 6);
        bVar1 = *(byte *)(iVar7 + uVar8 * 9);
        if (((((Highlight1 == -2) && (*(byte *)(iVar7 + uVar8 * 9 + 1) < 8)) ||
             (*(char *)((uint)bVar1 * 0x27 + 0x133) == Highlight1)) &&
            ((Seed_2000_d110 <= (int)uVar2 && (uVar2 <= Seed_2000_d110 + 0x69U)))) &&
           ((Seed_2000_d10e <= (int)uVar3 && (uVar3 <= Seed_2000_d10e + 0x2fU)))) {
          iVar7 = (uVar3 - Seed_2000_d10e) * 3;
          iVar5 = (uVar2 - Seed_2000_d110) * 2 + 0xc;
          iVar6 = (uint)*(byte *)((uint)bVar1 * 0x27 + 0x11b) * 2 + -1;
          ovr_driver_2d63_09c9(iVar5,iVar5 + iVar6,iVar7 + 9,0x75,0x440,(char *)"puppetmaker" + 3);
          ovr_driver_2d63_09c9(iVar5,iVar5 + iVar6,iVar7 + 10,0x75,0x440,(char *)"puppetmaker" + 3);
          ovr_driver_2d63_09c9(iVar5,iVar5 + iVar6,iVar7 + 0xb,0x75,0x440,(char *)"puppetmaker" + 3)
          ;
        }
      }
    }
  }
  return;
}


