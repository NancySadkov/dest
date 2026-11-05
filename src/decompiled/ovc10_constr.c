/*
 * ovc10_constr.c - recovered from STRONG.EXE
 * memory block: OVC10_constr.c
 * range: 36ce:0000 - 36ce:38cf
 * functions: 20
 */
#include "recovered.h"


/* 36ce:0000 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl16far constr_36ce_0000(int param_1,int param_2)

{
  int iVar1;
  
  if ((((param_1 + GfxRndSeed < 0x94) && (SCARRY2(param_1,GfxRndSeed) == param_1 + GfxRndSeed < 0))
      && (GfxRndSeed2 - param_2 < 0x3c)) && (param_2 <= GfxRndSeed2)) {
    iVar1 = (int)*(char *)((int)_DAT_2000_cb05 + (GfxRndSeed2 - param_2) * 0x94 + param_1 +
                          GfxRndSeed);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 36ce:0080 */

undefined2 __cdecl16far constr_36ce_0080(int param_1,int param_2)

{
  char *pcVar1;
  undefined2 uVar2;
  
  pcVar1 = (char *)"puppetmaker" + 3;
  if ((((param_1 + GfxRndSeed < 0x94) &&
       (pcVar1 = (char *)"puppetmaker" + 3, SCARRY2(param_1,GfxRndSeed) == param_1 + GfxRndSeed < 0)
       ) && (pcVar1 = (char *)(GfxRndSeed2 - param_2), (int)pcVar1 < 0x3c)) &&
     (pcVar1 = (char *)(GfxRndSeed2 - param_2), param_2 <= GfxRndSeed2)) {
    uVar2 = CONCAT11(0x24,*(undefined1 *)
                           ((int)DAT_2000_cb09 + (GfxRndSeed2 - param_2) * 0x128 +
                           (param_1 + GfxRndSeed) * 2));
  }
  else {
    uVar2 = CONCAT11((char)((uint)pcVar1 >> 8),3);
  }
  return uVar2;
}



/* 36ce:0101 */

int __cdecl16far constr_36ce_0101(undefined2 param_1,int param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = constr_36ce_0000(param_1,param_2);
  *param_3 = iVar1;
  iVar1 = (*param_3 - DAT_2410_0742) * 3;
  if (iVar1 < 0) {
    iVar1 = (int)(iVar1 * (uint)*(byte *)(param_2 + 0x733)) / 0x10;
  }
  else {
    iVar1 = (int)(iVar1 * (uint)*(byte *)(param_2 + 0x733)) >> 4;
  }
  return iVar1;
}



/* 36ce:0159 */

/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined1 __cdecl16far constr_36ce_0159(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  if ((((param_1 + GfxRndSeed < 0x94) && (SCARRY2(param_1,GfxRndSeed) == param_1 + GfxRndSeed < 0))
      && (GfxRndSeed2 - param_2 < 0x3c)) && (param_2 <= GfxRndSeed2)) {
    uVar2 = (undefined2)((ulong)DAT_2000_cb0d >> 0x10);
    uVar3 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
    DAT_2000_d022 =
         (uint)*(byte *)((int)DAT_2000_ca95 +
                         *(int *)((int)DAT_2000_cb0d + (param_1 + GfxRndSeed) * 0x78 +
                                 (GfxRndSeed2 - param_2) * 2) * 9 + 1);
    uVar1 = *(undefined1 *)
             ((int)DAT_2000_ca95 +
             *(int *)((int)DAT_2000_cb0d + (param_1 + GfxRndSeed) * 0x78 +
                     (GfxRndSeed2 - param_2) * 2) * 9);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 36ce:023c */

void __cdecl16far constr_36ce_023c(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_6 [2];
  int iStack_4;
  
  DAT_2410_0742 = 0;
  iVar1 = constr_36ce_0101(0xffff,0xffff,local_6);
  iStack_4 = iVar1;
  iVar2 = constr_36ce_0101(0,0xffff,local_6);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  if (iStack_4 < iVar2) {
    iStack_4 = iVar2;
  }
  iVar2 = constr_36ce_0101(1,0xffff,local_6);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  if (iStack_4 < iVar2) {
    iStack_4 = iVar2;
  }
  iVar2 = constr_36ce_0101(2,0xffff,local_6);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  iVar2 = constr_36ce_0101(0xfffe,0xffff,local_6);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  if (0x5a < iStack_4 - iVar1) {
    iVar1 = iStack_4 + -0x5a;
  }
  DAT_2410_0742 = iVar1 / 3;
  return;
}



/* 36ce:02f0 */

void __cdecl16far constr_36ce_02f0(void)

{
  if (GOngoingBattle == '\0') {
    ovr_OVC13_3d16_08ee();
  }
  else {
    ovr_OVC13_3d16_1558();
  }
  ovr_attact_3f0b_2a09();
  return;
}



/* 36ce:0313 */

void __cdecl16far blitRect(brect_t *br)

{
  brect_t *pbr;
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)br >> 0x10);
  pbr = (brect_t *)br;
  ovr_blitRaw(br->x,pbr->y,pbr->w,pbr->h,pbr->seg,0xa000);
  return;
}



/* 36ce:0345 */

void __cdecl16far constr_36ce_0345(brect_t *param_1)

{
  uint16_t dst;
  brect_t *pbVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  pbVar1 = (brect_t *)param_1;
  dst = pbVar1->seg;
  pbVar1->seg = 0xa000;
  ovr_miceRestoreArea(param_1);
  ovr_blitRaw(param_1->x,pbVar1->y,pbVar1->w,pbVar1->h,0xa000,dst);
  ovr_miceBlitRect(param_1);
  pbVar1->seg = dst;
  return;
}



/* 36ce:03a6 */

void __cdecl16far constr_36ce_03a6(void)

{
  char cVar1;
  far_t ptr;
  far_t fVar2;
  
  ptr = (far_t)ovr_stshAlloc(0xfa0f);
  fVar2 = ovr_alignToSeg(ptr);
  if (GOngoingBattle != '\0') {
    BlitRects[0].seg = fVar2.seg;
    ovr_miceRestoreArea(BlitRects);
    ovr_OVC13_3d16_1558();
    ovr_miceBlitRect(BlitRects);
    blitRect(BlitRects);
    ovr_miceUpdate();
    BlitRects[0].seg = 0xa000;
  }
  if (GOngoingBattle != '\0') {
    cVar1 = ovr_draw_2e25_15d6();
    if (cVar1 != '\0') goto LAB_36ce_0489;
  }
  BlitRects[3].seg = fVar2.seg;
  ovr_miceRestoreArea(BlitRects + 3);
  ovr_OVC13_3d16_08ee();
  ovr_miceBlitRect(BlitRects + 3);
  blitRect(BlitRects + 3);
  ovr_miceUpdate();
  BlitRects[3].seg = 0xa000;
LAB_36ce_0489:
  ovr_stshFree(ptr);
  ovr_attact_3f0b_2a09();
  return;
}



/* 36ce:049f */

undefined2 __cdecl16far
constr_36ce_049f(undefined1 param_1,undefined1 param_2,undefined1 param_3,byte param_4,byte param_5)

{
  undefined2 uVar1;
  
  if ((param_4 & param_5) == 0) {
    uVar1 = ovr_driver_2d63_0107(param_1,param_2,param_3);
  }
  else {
    uVar1 = 0xe2;
  }
  return uVar1;
}



/* 36ce:04c4 */

undefined2 __cdecl16far
constr_36ce_04c4(undefined1 param_1,undefined1 param_2,undefined1 param_3,byte param_4,byte param_5)

{
  undefined2 uVar1;
  
  if ((param_4 & param_5) == 0) {
    uVar1 = ovr_driver_2d63_014b(param_1,param_2,param_3);
  }
  else {
    uVar1 = 0xe2;
  }
  return uVar1;
}



/* 36ce:04e9 */

void __cdecl16far constr_36ce_04e9(undefined2 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  char cVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  int iVar8;
  int iVar9;
  undefined1 local_c [2];
  undefined1 local_a [2];
  uint uStack_8;
  uint uStack_6;
  int iStack_4;
  
  for (iVar8 = DAT_2000_cfea; iVar9 = DAT_2000_cfea, iVar8 < DAT_2000_cfd8; iVar8 = iVar8 + 1) {
    if ((0xb < *(int *)(iVar8 * 2 + 0x6c0)) && (*(int *)(iVar8 * 2 + 0xa20) < 0xdf)) {
      iVar9 = *(int *)(iVar8 * 2 + 0x360);
      uStack_6 = constr_36ce_0000(iVar9,0xfffe);
      uStack_8 = constr_36ce_0000(iVar9 + 1,0xfffe);
      iVar5 = constr_36ce_0101(iVar9,0xffff,local_a);
      iVar6 = constr_36ce_0101(iVar9 + 1,0xffff,local_c);
      uVar7 = constr_36ce_0080(iVar9,0xffff);
      if ((uVar7 & 4) == 0) {
        cVar2 = constr_36ce_04c4(local_a[0],local_c[0],uStack_8 & 0xff,uVar7,2);
        ovr_OVC07_32c9_0044(*(undefined2 *)(iVar8 * 2 + 0xa20),DAT_2000_cffc - iVar5,
                            *(undefined2 *)(iVar8 * 2 + 0x6c0),DAT_2000_cffc - iVar6,
                            *(undefined2 *)(iVar8 * 2 + 0x6c0),0x96,cVar2,param_1,param_2);
        uVar3 = constr_36ce_04c4(CONCAT11(extraout_AH_00,(undefined1)uStack_6),
                                 CONCAT11(extraout_AH_00,(undefined1)uStack_8),
                                 CONCAT11(extraout_AH_00,local_a[0]),
                                 CONCAT11(extraout_AH_00,(char)uVar7),1);
        ovr_OVC07_32c9_0044(*(undefined2 *)(iVar8 * 2 + 0xa20),DAT_2000_cffc - iVar5,
                            *(undefined2 *)(iVar8 * 2 + 0xa20),0x96,
                            *(undefined2 *)(iVar8 * 2 + 0x6c0),0x96,uVar3,param_1,param_2);
      }
      else {
        cVar2 = constr_36ce_04c4(local_a[0],local_c[0],uStack_6 & 0xff,uVar7,1);
        ovr_OVC07_32c9_0044(*(undefined2 *)(iVar8 * 2 + 0xa20),DAT_2000_cffc - iVar5,
                            *(undefined2 *)(iVar8 * 2 + 0x6c0),DAT_2000_cffc - iVar6,
                            *(undefined2 *)(iVar8 * 2 + 0xa20),0x96,cVar2,param_1,param_2);
        uVar3 = constr_36ce_04c4(CONCAT11(extraout_AH,(undefined1)uStack_6),
                                 CONCAT11(extraout_AH,(undefined1)uStack_8),
                                 CONCAT11(extraout_AH,local_c[0]),CONCAT11(extraout_AH,(char)uVar7),
                                 2);
        ovr_OVC07_32c9_0044(*(undefined2 *)(iVar8 * 2 + 0x6c0),DAT_2000_cffc - iVar6,
                            *(undefined2 *)(iVar8 * 2 + 0xa20),0x96,
                            *(undefined2 *)(iVar8 * 2 + 0x6c0),0x96,uVar3,param_1,param_2);
      }
      cVar4 = constr_36ce_306b(iVar9 + GfxRndSeed,GfxRndSeed2);
      if (cVar4 != '\0') {
        ovr_OVC07_32c9_0466(*(undefined2 *)(iVar8 * 2 + 0xa20),DAT_2000_cffc - iVar5,
                            *(undefined2 *)(iVar8 * 2 + 0x6c0),DAT_2000_cffc - iVar6,cVar2 + -2,
                            param_1,param_2);
        ovr_OVC07_32c9_0466(*(undefined2 *)(iVar8 * 2 + 0xa20),(DAT_2000_cffc - iVar5) + 1,
                            *(undefined2 *)(iVar8 * 2 + 0x6c0),(DAT_2000_cffc - iVar6) + 1,
                            cVar2 + -1,param_1,param_2);
      }
    }
  }
  for (; iVar9 < DAT_2000_cfd8; iVar9 = iVar9 + 1) {
    uVar1 = *(undefined2 *)(iVar9 * 2 + 0x360);
    iStack_4 = constr_36ce_0159(uVar1,0);
    if ((iStack_4 != 0) &&
       (iVar8 = constr_36ce_0101(uVar1,0xffff,local_a),
       (*(byte *)(iStack_4 * 0x27 + 0x11e) & 2) != 0)) {
      ovr_blit_317e_0db7(*(undefined2 *)
                          ((char *)
                           "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                           + 0x32 + iStack_4 * 0xc),
                         *(undefined2 *)
                          ((char *)
                           "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                           + 0x34 + iStack_4 * 0xc),*(undefined2 *)(iVar9 * 2 + 0xa20),
                         (uint)DAT_2410_0728 - iVar8,0x10,99,0x10,param_1,param_2);
      ovr_OVC15_4207_0b55(*(int *)(iVar9 * 2 + 0xa20) + -0xc);
    }
  }
  return;
}



/* 36ce:08ee */

void __cdecl16far constr_36ce_08ee(brect_t *param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  far_t gfx;
  
  for (iVar2 = DAT_2000_cfea; iVar2 < DAT_2000_cfd8; iVar2 = iVar2 + 1) {
    iVar1 = *(int *)(iVar2 * 2 + 0x360);
    if ((0xb < iVar1 + 0x2f) && (iVar1 < 0xdf)) {
      iVar1 = constr_36ce_0159(iVar1,0);
      if ((*(byte *)(iVar1 * 0x27 + 0x11e) & 5) != 0) {
        gfx.seg = *(uint16_t *)
                   ((char *)
                    "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                    + 0x38 + iVar1 * 0xc);
        gfx.ofs = *(uint16_t *)
                   ((char *)
                    "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                    + 0x36 + iVar1 * 0xc);
        ovr_blitGfxRect(gfx,*(int16_t *)(iVar2 * 2 + 0xa20),144,(brect_t *)CONCAT22(param_2,param_1)
                        ,0x10,false);
      }
    }
  }
  return;
}



/* 36ce:0995 */

void __cdecl16far constr_36ce_0995(void)

{
  byte bVar1;
  int iVar2;
  char *arg1;
  int iVar3;
  int iVar4;
  undefined2 unaff_SS;
  char *text;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  byte *widths;
  undefined1 uVar5;
  undefined1 uVar6;
  uint8_t term;
  char buf [81];
  byte bStack_3b;
  int iStack_3a;
  int iStack_38;
  int iStack_36;
  int iStack_34;
  uint uStack_32;
  int iStack_30;
  int iStack_2e;
  undefined1 local_2c [2];
  undefined1 local_2a [2];
  undefined1 local_28 [2];
  undefined1 local_26 [2];
  int iStack_24;
  int iStack_22;
  int iStack_20;
  int iStack_1e;
  int iStack_1c;
  int iStack_1a;
  uint8_t local_18 [6];
  int iStack_12;
  uint uStack_10;
  int iStack_e;
  byte bStack_b;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  undefined2 uStack_4;
  
  F_SCOPY(local_18,(uint8_t *)0x745,6);
  if (GOngoingBattle == '\0') {
    ovr_OVC13_3d16_08ee();
    constr_36ce_023c();
    ovr_OVC23_55fe_0000();
    GGameState = 0x24;
    if (DebugVerbose != false) {
      printf("%d \r",0x24);
    }
    iStack_12 = GfxRndSeed >> 2;
    if (0xb < 0x14bU - iStack_12) {
      gfx.seg = ((undefined2 *)&DAT_2000_d04a)[((uint)DAT_2410_0744 + (uint)GSeason) * 4];
      gfx.ofs = ((undefined2 *)&DAT_2000_d048)[((uint)DAT_2410_0744 + (uint)GSeason) * 4];
      ovr_blitGfxRect(gfx,0xc - iStack_12,7,BlitRects,0x10,false);
    }
    if (0x14cU - iStack_12 < 0xdf) {
      gfx_00.seg = ((undefined2 *)&DAT_2000_d04e)[((uint)DAT_2410_0744 + (uint)GSeason) * 4];
      gfx_00.ofs = ((undefined2 *)&DAT_2000_d04c)[((uint)DAT_2410_0744 + (uint)GSeason) * 4];
      ovr_blitGfxRect(gfx_00,0x14c - iStack_12,7,BlitRects,0x10,false);
    }
    ovr_driver_2d63_05e5(0xc,0x43,0xde,0x56,0xf0,BlitRects[0].seg);
    GGameState = 0x53;
    if (DebugVerbose != false) {
      printf("%d \r",0x53);
    }
    for (iVar3 = 8; -1 < iVar3; iVar3 = iVar3 + -1) {
      for (iVar4 = ((undefined2 *)&DAT_2000_cfea)[iVar3];
          iVar4 < (int)((undefined2 *)&DAT_2000_cfd8)[iVar3]; iVar4 = iVar4 + 1) {
        iStack_2e = *(int *)(iVar4 * 2 + 0x360);
        iStack_1e = constr_36ce_0101(iStack_2e,iVar3 + -1,(char)local_26);
        iStack_20 = constr_36ce_0101(iStack_2e + 1,iVar3 + -1,(char)local_28);
        iStack_22 = constr_36ce_0101(iStack_2e,iVar3,(char)local_2a);
        iStack_24 = constr_36ce_0101(iStack_2e + 1,iVar3,(char)local_2c);
        bStack_b = constr_36ce_0080((char)iStack_2e,iVar3);
        if ((bStack_b & 4) == 0) {
          if (iStack_2e < 0) {
            bVar1 = constr_36ce_049f();
            uStack_32 = (uint)bVar1;
            ovr_OVC07_32c9_0044(*(undefined2 *)((int)&AgntAnms[0x5d].sx + 1 + iVar4 * 2),
                                *(int *)(iVar3 * 2 + -0x70f2) - iStack_22,
                                *(undefined2 *)(iVar4 * 2 + 0xa20),
                                ((undefined2 *)&DAT_2000_cffc)[iVar3] - iStack_1e,
                                *(undefined2 *)(iVar4 * 2 + 0x6c0),
                                ((undefined2 *)&DAT_2000_cffc)[iVar3] - iStack_20,uStack_32,0x40,
                                (char *)"puppetmaker" + 3);
            bVar1 = constr_36ce_049f();
            uStack_32 = (uint)bVar1;
            ovr_OVC07_32c9_0044(*(undefined2 *)((int)&AgntAnms[0x5d].sx + 1 + iVar4 * 2));
          }
          else {
            bVar1 = constr_36ce_049f();
            uStack_32 = (uint)bVar1;
            ovr_OVC07_32c9_0044(*(undefined2 *)((int)&AgntAnms[0x5d].sx + 1 + iVar4 * 2),
                                *(int *)(iVar3 * 2 + -0x70f2) - iStack_22,
                                *(undefined2 *)(iVar4 * 2 + 0xd80),
                                *(int *)(iVar3 * 2 + -0x70f2) - iStack_24,
                                *(undefined2 *)(iVar4 * 2 + 0x6c0),
                                ((undefined2 *)&DAT_2000_cffc)[iVar3] - iStack_20,uStack_32,0x40,
                                (char *)"puppetmaker" + 3);
            bVar1 = constr_36ce_049f();
            uStack_32 = (uint)bVar1;
            ovr_OVC07_32c9_0044(*(undefined2 *)((int)&AgntAnms[0x5d].sx + 1 + iVar4 * 2));
          }
        }
        else if (iStack_2e < 0) {
          bVar1 = constr_36ce_049f();
          uStack_32 = (uint)bVar1;
          ovr_OVC07_32c9_0044(*(undefined2 *)((int)&AgntAnms[0x5d].sx + 1 + iVar4 * 2),
                              *(int *)(iVar3 * 2 + -0x70f2) - iStack_22,
                              *(undefined2 *)(iVar4 * 2 + 0xd80),
                              *(int *)(iVar3 * 2 + -0x70f2) - iStack_24,
                              *(undefined2 *)(iVar4 * 2 + 0xa20),
                              ((undefined2 *)&DAT_2000_cffc)[iVar3] - iStack_1e,uStack_32,0x40,
                              (char *)"puppetmaker" + 3);
          bVar1 = constr_36ce_049f();
          uStack_32 = (uint)bVar1;
          ovr_OVC07_32c9_0044(*(undefined2 *)(iVar4 * 2 + 0xd80));
        }
        else {
          bVar1 = constr_36ce_049f();
          uStack_32 = (uint)bVar1;
          ovr_OVC07_32c9_0044(*(undefined2 *)(iVar4 * 2 + 0xd80),
                              *(int *)(iVar3 * 2 + -0x70f2) - iStack_24,
                              *(undefined2 *)(iVar4 * 2 + 0xa20),
                              ((undefined2 *)&DAT_2000_cffc)[iVar3] - iStack_1e,
                              *(undefined2 *)(iVar4 * 2 + 0x6c0),
                              ((undefined2 *)&DAT_2000_cffc)[iVar3] - iStack_20,uStack_32,0x40,
                              (char *)"puppetmaker" + 3);
          bVar1 = constr_36ce_049f();
          uStack_32 = (uint)bVar1;
          ovr_OVC07_32c9_0044(*(undefined2 *)((int)&AgntAnms[0x5d].sx + 1 + iVar4 * 2));
        }
      }
      if (iVar3 < 6) {
        for (bStack_3b = 0; bStack_3b < 2; bStack_3b = bStack_3b + 1) {
          for (iVar4 = ((undefined2 *)&DAT_2000_cfea)[iVar3];
              iVar4 < (int)((undefined2 *)&DAT_2000_cfd8)[iVar3]; iVar4 = iVar4 + 1) {
            iStack_2e = *(int *)(iVar4 * 2 + 0x360);
            iStack_e = constr_36ce_0159((char)iStack_2e,iVar3);
            GGameState = 0x37;
            if (DebugVerbose != false) {
              printf("%d \r",0x37);
            }
            if (iStack_e < 0xf8) {
              if ((iStack_e != 0) &&
                 (((bStack_3b == 0 && ((*(uint *)(iStack_e * 0x27 + 0x121) & 0x800) != 0)) ||
                  ((bStack_3b != 0 && ((*(uint *)(iStack_e * 0x27 + 0x121) & 0x800) == 0)))))) {
                if (*(byte *)(iStack_e * 0x27 + 0x11b) < 2) {
                  iStack_1e = constr_36ce_0101(iStack_2e,iVar3 + -1,(char)local_26);
                  iStack_22 = constr_36ce_0101(iStack_2e,iVar3,(char)local_2a);
                  iStack_20 = constr_36ce_0101(iStack_2e + 1,iVar3 + -1,(char)local_28);
                  iStack_24 = constr_36ce_0101(iStack_2e + 1,iVar3,(char)local_2c);
                }
                else if (*(byte *)(iStack_e * 0x27 + 0x11b) < 3) {
                  iStack_1e = constr_36ce_0101(iStack_2e,iVar3 + -1,(char)local_26);
                  iStack_22 = constr_36ce_0101(iStack_2e,iVar3,(char)local_2a);
                  iStack_20 = constr_36ce_0101(iStack_2e + 2,iVar3 + -1,(char)local_28);
                  iStack_24 = constr_36ce_0101(iStack_2e + 2,iVar3,(char)local_2c);
                }
                else {
                  iStack_1e = constr_36ce_0101(iStack_2e + 1,iVar3 + -1,(char)local_26);
                  iStack_22 = constr_36ce_0101(iStack_2e + 1,iVar3,(char)local_2a);
                  iStack_20 = constr_36ce_0101(iStack_2e + 2,iVar3 + -1,(char)local_28);
                  iStack_24 = constr_36ce_0101(iStack_2e + 2,iVar3,(char)local_2c);
                }
                uStack_10 = (uint)*(byte *)(iVar3 + 0x73c);
                iStack_30 = iStack_22 + iStack_1e + iStack_20 + iStack_24 >> 2;
                if ((int)(iStack_1e - uStack_10) < (int)(iStack_20 - uStack_10)) {
                  iVar2 = iStack_1e - uStack_10;
                }
                else {
                  iVar2 = iStack_20 - uStack_10;
                }
                if (iStack_30 < iVar2) {
                  if ((int)(iStack_1e - uStack_10) < (int)(iStack_20 - uStack_10)) {
                    iStack_30 = iStack_1e - uStack_10;
                  }
                  else {
                    iStack_30 = iStack_20 - uStack_10;
                  }
                }
                if (*(char *)(iStack_e * 0x27 + 0x11e) == '\0') {
                  if ((*(uint *)(iStack_e * 0x27 + 0x121) & 0x20) == 0) {
                    iVar2 = iStack_e * 0xc + *(int *)(iVar4 * 2) * 4;
                    if (((*(int *)((char *)"build\\clebath2.lbm" + 8 + iVar2) == 0 &&
                          *(int *)((char *)"build\\clebath2.lbm" + 10 + iVar2) == 0) || (2 < iVar3))
                       || (7 < DAT_2000_d022)) {
                      iVar2 = iStack_e * 0xc + *(int *)(iVar4 * 2) * 4;
                      gfx_03.seg = *(uint16_t *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x30 + iVar2);
                      gfx_03.ofs = *(uint16_t *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x2e + iVar2);
                      ovr_blitGfxRect(gfx_03,*(int16_t *)(iVar4 * 2 + 0xa20),
                                      (uint)*(byte *)(iVar3 + 0x728) - iStack_30,BlitRects,
                                      local_18[iVar3],false);
                    }
                    else {
                      iVar2 = iStack_e * 0xc + *(int *)(iVar4 * 2) * 4;
                      gfx_02.seg = *(uint16_t *)((char *)"build\\clebath2.lbm" + 10 + iVar2);
                      gfx_02.ofs = *(uint16_t *)((char *)"build\\clebath2.lbm" + 8 + iVar2);
                      ovr_blitGfxRect(gfx_02,*(int16_t *)(iVar4 * 2 + 0xa20),
                                      (uint)*(byte *)(iVar3 + 0x728) - iStack_30,BlitRects,
                                      local_18[iVar3],false);
                      if (1 < DAT_2000_d022) {
                        ovr_gfxRlePrepare();
                      }
                    }
                  }
                  else {
                    iVar2 = iStack_e * 0xc + (uint)GSeason * 4;
                    gfx_01.seg = *(uint16_t *)
                                  ((char *)
                                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                   + 0x30 + iVar2);
                    gfx_01.ofs = *(uint16_t *)
                                  ((char *)
                                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                   + 0x2e + iVar2);
                    ovr_blitGfxRect(gfx_01,*(int16_t *)(iVar4 * 2 + 0xa20),
                                    (uint)*(byte *)(iVar3 + 0x728) - iStack_30,BlitRects,
                                    local_18[iVar3],false);
                  }
                }
                else {
                  if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 0x10) != 0) {
                    for (iStack_6 = 0; iStack_6 < 6; iStack_6 = iStack_6 + 1) {
                      ovr_blit_317e_1240(*(undefined2 *)
                                          ((char *)
                                           "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                           + 0x32 + iStack_e * 0xc),
                                         *(undefined2 *)
                                          ((char *)
                                           "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                           + 0x34 + iStack_e * 0xc),
                                         *(undefined2 *)
                                          ((char *)"build\\clebath2.lbm" + 0xc + iStack_e * 0xc),
                                         *(undefined2 *)
                                          ((char *)"build\\clebath2.lbm" + 0xe + iStack_e * 0xc),
                                         (*(int *)(iVar4 * 2 + 0xa20) * (5 - iStack_6)) / 5 +
                                         (*(int *)(iVar4 * 2 + 0x6c0) * iStack_6) / 5);
                    }
                  }
                  if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 10) != 0) {
                    if (*(int *)(iVar4 * 2 + 0xa20) ==
                        *(int *)((int)&AgntAnms[0x5d].sx + 1 + iVar4 * 2)) {
                      ovr_blit_317e_0db7(*(undefined2 *)
                                          ((char *)
                                           "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                           + 0x32 + iStack_e * 0xc));
                    }
                    else {
                      ovr_blit_317e_0f7d();
                    }
                  }
                  if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 8) != 0) {
                    if (*(int *)(iVar4 * 2 + 0xd80) == *(int *)(iVar4 * 2 + 0x6c0)) {
                      ovr_blit_317e_0db7(*(undefined2 *)
                                          ((char *)
                                           "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                           + 0x32 + iStack_e * 0xc));
                    }
                    else {
                      ovr_blit_317e_0f7d();
                    }
                  }
                  if (((*(byte *)(iStack_e * 0x27 + 0x11e) & 4) != 0) ||
                     (((*(byte *)(iStack_e * 0x27 + 0x11e) & 1) != 0 && (iVar3 != 0)))) {
                    ovr_blit_317e_0f7d();
                  }
                }
              }
            }
            else {
              printf("Bad House # %d \r",iStack_e);
              ovr_biosReadKey();
            }
          }
        }
      }
    }
    GGameState = 0x25;
    if (DebugVerbose != false) {
      printf("%d \r",0x25);
    }
    constr_36ce_04e9(0x40,(char *)"puppetmaker" + 3);
    iStack_8 = 0;
    iStack_a = 0;
    for (iVar3 = DAT_2000_cfea; iVar3 < DAT_2000_cfd8; iVar3 = iVar3 + 1) {
      if ((0xb < *(int *)(iVar3 * 2 + 0x6c0)) && (*(int *)(iVar3 * 2 + 0xa20) < 0xdf)) {
        iStack_2e = *(int *)(iVar3 * 2 + 0x360);
        iStack_1a = constr_36ce_0101(iStack_2e,0xffff,(char)local_2a);
        iStack_1c = constr_36ce_0101(iStack_2e + 1,0xffff,(char)local_2c);
        bStack_b = constr_36ce_0080((char)iStack_2e,0xffff);
        iStack_36 = DAT_2000_cffc - iStack_1a;
        iStack_38 = iStack_1a - iStack_1c;
        iStack_3a = *(int *)(iVar3 * 2 + 0x6c0) - *(int *)(iVar3 * 2 + 0xa20);
        for (iStack_34 = *(int *)(iVar3 * 2 + 0xa20); iStack_34 <= *(int *)(iVar3 * 2 + 0x6c0);
            iStack_34 = iStack_34 + 1) {
          if ((0xb < iStack_34) && (iStack_34 < 0xdf)) {
            *(int *)((iStack_34 + -0xc) * 2 + 0x34c) =
                 iStack_36 + (iStack_38 * (iStack_34 - *(int *)(iVar3 * 2 + 0xa20))) / iStack_3a;
            *(int *)((iStack_34 + -0xc) * 2 + 0x1a6) = -iStack_38;
            if ((bStack_b & 3) == 0) {
              *(undefined2 *)((iStack_34 + -0xc) * 2) = 1;
            }
            else {
              *(undefined2 *)((iStack_34 + -0xc) * 2) = 0;
              if ((bStack_b & 3) != 0) {
                iStack_a = iStack_a + 1;
              }
              iStack_8 = iStack_8 + 1;
            }
          }
        }
      }
    }
    if (AgntClearFlag != false) {
      ovr_agnt_clear();
      AgntClearFlag = false;
    }
    GAnimPlaying = 1;
    GGameState = 0x26;
    if (DebugVerbose != false) {
      printf("%d \r",0x26);
    }
    uStack_4 = TextBlitDstSeg;
    TextBlitDstSeg = BlitRects[0].seg;
    TextBlitX = 0xb6;
    TextBlitY = 10;
    if (GameRunning == false) {
      term = 0xe0;
      uVar5 = 0x3f;
      uVar6 = 1;
      widths = (byte *)Font02.ofs;
      arg1 = (char *)ovr_OVC23_55fe_3450(GfxRndSeed,GfxRndSeed2,Font02.ofs,Font02.seg);
      text = ovr_stsprintf(buf,"(%d, %d)",arg1);
      ovr_blitText(text,widths,CONCAT11(uVar6,uVar5),term);
    }
    TextBlitDstSeg = uStack_4;
    ovr_agnt_3b1d_19e0();
    GGameState = 0x27;
    if (DebugVerbose != false) {
      printf("x:%d y:%d  %x %x %x %x   %x %x %x %x    \r",GfxRndSeed);
    }
    ovr_attact_3f0b_2a09();
  }
  else {
    constr_36ce_1f99();
    ovr_OVC13_3d16_1558();
    ovr_attact_3f0b_2a09();
  }
  return;
}



/* 36ce:1db4 */

void __cdecl16far constr_36ce_1db4(void)

{
  far_t ptr;
  far_t fVar1;
  
  ptr = (far_t)ovr_stshAlloc(0xfa0f);
  fVar1 = ovr_alignToSeg(ptr);
  BlitRects[0].seg = fVar1.seg;
  BlitRects[3].seg = BlitRects[0].seg;
  ovr_miceRestoreArea(BlitRects);
  ovr_miceRestoreArea(BlitRects + 3);
  constr_36ce_0995();
  ovr_miceBlitRect(BlitRects);
  blitRect(BlitRects);
  ovr_miceUpdate();
  ovr_miceBlitRect(BlitRects + 3);
  blitRect(BlitRects + 3);
  BlitRects[3].seg = 0xa000;
  BlitRects[0].seg = 0xa000;
  ovr_stshFree(ptr);
  return;
}



/* 36ce:1e76 */

void __cdecl16far constr_36ce_1e76(void)

{
  far_t ptr;
  far_t fVar1;
  
  ptr = (far_t)ovr_stshAlloc(0xfa0f);
  fVar1 = ovr_alignToSeg(ptr);
  BlitRects[3].seg = fVar1.seg;
  ovr_miceRestoreArea(BlitRects + 3);
  constr_36ce_1f99();
  ovr_miceBlitRect(BlitRects + 3);
  blitRect(BlitRects + 3);
  ovr_miceUpdate();
  BlitRects[3].seg = 0xa000;
  ovr_stshFree(ptr);
  return;
}



/* 36ce:1efc */

void __cdecl16far constr_36ce_1efc(void)

{
  far_t ptr;
  far_t fVar1;
  
  ptr = (far_t)ovr_stshAlloc(0xfa0f);
  fVar1 = ovr_alignToSeg(ptr);
  BlitRects[0].seg = fVar1.seg;
  GGameState = 0x22;
  BlitRects[3].seg = BlitRects[0].seg;
  constr_36ce_0995();
  GGameState = 0x23;
  blitRect(BlitRects);
  blitRect(BlitRects + 3);
  BlitRects[3].seg = 0xa000;
  BlitRects[0].seg = 0xa000;
  ovr_stshFree(ptr);
  return;
}



/* 36ce:1f99 */

void __cdecl16far constr_36ce_1f99(void)

{
  undefined2 uVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  int iVar5;
  uint uVar6;
  undefined1 extraout_AH_03;
  undefined1 extraout_AH_04;
  int iVar7;
  int iVar8;
  undefined2 unaff_SS;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  int iStack_26;
  undefined1 local_22 [2];
  undefined1 local_20 [2];
  uint local_1e;
  uint local_1c;
  int iStack_1a;
  int iStack_18;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  int iStack_10;
  int iStack_e;
  uint8_t local_c [2];
  uint8_t auStack_a [4];
  int iStack_6;
  uint uStack_4;
  
  F_SCOPY(local_c,(uint8_t *)0x74f,6);
  cVar2 = ovr_draw_2e25_15d6();
  if (cVar2 == '\0') {
    ovr_OVC13_3d16_08ee();
  }
  else {
    iStack_6 = GfxRndSeed * 6 >> 6;
    if (0xee < 0x166 - iStack_6) {
      gfx.seg = ((undefined2 *)&DAT_2000_d04a)[((uint)DAT_2410_0744 + (uint)GSeason) * 4];
      gfx.ofs = ((undefined2 *)&DAT_2000_d048)[((uint)DAT_2410_0744 + (uint)GSeason) * 4];
      ovr_blitGfxRect(gfx,0xef - iStack_6,7,BlitRects + 3,0x6,false);
    }
    if (0x167 - iStack_6 < 0x135) {
      gfx_00.seg = ((undefined2 *)&DAT_2000_d04e)[((uint)DAT_2410_0744 + (uint)GSeason) * 4];
      gfx_00.ofs = ((undefined2 *)&DAT_2000_d04c)[((uint)DAT_2410_0744 + (uint)GSeason) * 4];
      ovr_blitGfxRect(gfx_00,0x22f - iStack_6,7,BlitRects + 3,0x6,false);
    }
    ovr_driver_2d63_05e5(0xef,0x1d,0x134,0x24,0xf0,BlitRects[3].seg);
    constr_36ce_023c();
    for (iVar7 = 2; iVar8 = DAT_2000_cdcc, -1 < iVar7; iVar7 = iVar7 + -1) {
      for (iVar8 = ((undefined2 *)&DAT_2000_cdcc)[iVar7];
          iVar8 < (int)((undefined2 *)&DAT_2000_cdc6)[iVar7]; iVar8 = iVar8 + 1) {
        iVar5 = ((undefined2 *)&DAT_2000_ce26)[iVar8];
        iStack_14 = constr_36ce_0101(iVar5,iVar7 + -1,&local_1c);
        iStack_14 = iStack_14 / 3;
        iStack_16 = constr_36ce_0101(iVar5 + 1,iVar7 + -1,&local_1e);
        iStack_16 = iStack_16 / 3;
        iStack_18 = constr_36ce_0101(iVar5,iVar7,local_20);
        iStack_18 = iStack_18 / 3;
        iStack_1a = constr_36ce_0101(iVar5 + 1,iVar7,local_22);
        iStack_1a = iStack_1a / 3;
        bVar3 = constr_36ce_0080(iVar5,iVar7);
        if ((bVar3 & 4) == 0) {
          if (iVar5 < 0) {
            uVar4 = constr_36ce_049f(local_1c & 0xff,local_1e & 0xff,local_20[0],bVar3,1);
            ovr_OVC07_32c9_0044(((undefined2 *)&DAT_2000_cf8e)[iVar8],
                                *(int *)(iVar7 * 2 + -0x7328) - iStack_18,
                                ((undefined2 *)&DAT_2000_ceb6)[iVar8],
                                ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_14,
                                ((undefined2 *)&DAT_2000_ce6e)[iVar8],
                                ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_16,uVar4,0x45e,
                                (char *)"puppetmaker" + 3);
            uVar4 = constr_36ce_049f(CONCAT11(extraout_AH,local_20[0]),
                                     CONCAT11(extraout_AH,local_22[0]),
                                     CONCAT11(extraout_AH,(undefined1)local_1e),
                                     CONCAT11(extraout_AH,bVar3),2);
            ovr_OVC07_32c9_0044(((undefined2 *)&DAT_2000_cf8e)[iVar8],
                                *(int *)(iVar7 * 2 + -0x7328) - iStack_18,
                                ((undefined2 *)&DAT_2000_cefe)[iVar8],
                                *(int *)(iVar7 * 2 + -0x7328) - iStack_1a,
                                ((undefined2 *)&DAT_2000_ce6e)[iVar8],
                                ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_16,uVar4,0x45e,
                                (char *)"puppetmaker" + 3);
          }
          else {
            uVar4 = constr_36ce_049f(local_20[0],local_22[0],local_1e & 0xff,bVar3,2);
            ovr_OVC07_32c9_0044(((undefined2 *)&DAT_2000_cf8e)[iVar8],
                                *(int *)(iVar7 * 2 + -0x7328) - iStack_18,
                                ((undefined2 *)&DAT_2000_cefe)[iVar8],
                                *(int *)(iVar7 * 2 + -0x7328) - iStack_1a,
                                ((undefined2 *)&DAT_2000_ce6e)[iVar8],
                                ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_16,uVar4,0x45e,
                                (char *)"puppetmaker" + 3);
            uVar4 = constr_36ce_049f(CONCAT11(extraout_AH_00,(undefined1)local_1c),
                                     CONCAT11(extraout_AH_00,(undefined1)local_1e),
                                     CONCAT11(extraout_AH_00,local_20[0]),
                                     CONCAT11(extraout_AH_00,bVar3),1);
            ovr_OVC07_32c9_0044(((undefined2 *)&DAT_2000_cf8e)[iVar8],
                                *(int *)(iVar7 * 2 + -0x7328) - iStack_18,
                                ((undefined2 *)&DAT_2000_ceb6)[iVar8],
                                ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_14,
                                ((undefined2 *)&DAT_2000_ce6e)[iVar8],
                                ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_16,uVar4,0x45e,
                                (char *)"puppetmaker" + 3);
          }
        }
        else if (iVar5 < 0) {
          uVar4 = constr_36ce_049f(local_20[0],local_22[0],local_1c & 0xff,bVar3,1);
          ovr_OVC07_32c9_0044(((undefined2 *)&DAT_2000_cf8e)[iVar8],
                              *(int *)(iVar7 * 2 + -0x7328) - iStack_18,
                              ((undefined2 *)&DAT_2000_cefe)[iVar8],
                              *(int *)(iVar7 * 2 + -0x7328) - iStack_1a,
                              ((undefined2 *)&DAT_2000_ceb6)[iVar8],
                              ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_14,uVar4,0x45e,
                              (char *)"puppetmaker" + 3);
          uVar4 = constr_36ce_049f(CONCAT11(extraout_AH_01,(undefined1)local_1c),
                                   CONCAT11(extraout_AH_01,(undefined1)local_1e),
                                   CONCAT11(extraout_AH_01,local_22[0]),
                                   CONCAT11(extraout_AH_01,bVar3),2);
          ovr_OVC07_32c9_0044(((undefined2 *)&DAT_2000_cefe)[iVar8],
                              *(int *)(iVar7 * 2 + -0x7328) - iStack_1a,
                              ((undefined2 *)&DAT_2000_ceb6)[iVar8],
                              ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_14,
                              ((undefined2 *)&DAT_2000_ce6e)[iVar8],
                              ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_16,uVar4,0x45e,
                              (char *)"puppetmaker" + 3);
        }
        else {
          uVar4 = constr_36ce_049f(local_1c & 0xff,local_1e & 0xff,local_22[0],bVar3,2);
          ovr_OVC07_32c9_0044(((undefined2 *)&DAT_2000_cefe)[iVar8],
                              *(int *)(iVar7 * 2 + -0x7328) - iStack_1a,
                              ((undefined2 *)&DAT_2000_ceb6)[iVar8],
                              ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_14,
                              ((undefined2 *)&DAT_2000_ce6e)[iVar8],
                              ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_16,uVar4,0x45e,
                              (char *)"puppetmaker" + 3);
          uVar4 = constr_36ce_049f(CONCAT11(extraout_AH_02,local_20[0]),
                                   CONCAT11(extraout_AH_02,local_22[0]),
                                   CONCAT11(extraout_AH_02,(undefined1)local_1c),
                                   CONCAT11(extraout_AH_02,bVar3),1);
          ovr_OVC07_32c9_0044(((undefined2 *)&DAT_2000_cf8e)[iVar8],
                              *(int *)(iVar7 * 2 + -0x7328) - iStack_18,
                              ((undefined2 *)&DAT_2000_cefe)[iVar8],
                              *(int *)(iVar7 * 2 + -0x7328) - iStack_1a,
                              ((undefined2 *)&DAT_2000_ceb6)[iVar8],
                              ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_14,uVar4,0x45e,
                              (char *)"puppetmaker" + 3);
        }
      }
      for (iVar8 = ((undefined2 *)&DAT_2000_cdcc)[iVar7];
          iVar8 < (int)((undefined2 *)&DAT_2000_cdc6)[iVar7]; iVar8 = iVar8 + 1) {
        iVar5 = ((undefined2 *)&DAT_2000_ce26)[iVar8];
        iStack_e = constr_36ce_0159(iVar5,iVar7);
        if (iStack_e != 0) {
          iStack_14 = constr_36ce_0101(iVar5,iVar7 + -1,&local_1c);
          iStack_14 = iStack_14 / 3;
          iStack_18 = constr_36ce_0101(iVar5,iVar7,local_20);
          iStack_18 = iStack_18 / 3;
          if (*(byte *)(iStack_e * 0x27 + 0x11b) < 2) {
            iStack_16 = constr_36ce_0101(iVar5 + 1,iVar7 + -1,&local_1e);
            iStack_16 = iStack_16 / 3;
            iStack_1a = constr_36ce_0101(iVar5 + 1,iVar7,local_22);
            iStack_1a = iStack_1a / 3;
          }
          else if (*(byte *)(iStack_e * 0x27 + 0x11b) < 3) {
            iStack_16 = constr_36ce_0101(iVar5 + 2,iVar7 + -1,&local_1e);
            iStack_16 = iStack_16 / 3;
            iStack_1a = constr_36ce_0101(iVar5 + 2,iVar7,local_22);
            iStack_1a = iStack_1a / 3;
          }
          else {
            iStack_16 = constr_36ce_0101(iVar5 + 4,iVar7 + -1,&local_1e);
            iStack_16 = iStack_16 / 3;
            iStack_1a = constr_36ce_0101(iVar5 + 4,iVar7,local_22);
            iStack_1a = iStack_1a / 3;
          }
          iStack_26 = iStack_18 + iStack_14 + iStack_16 + iStack_1a >> 2;
          uStack_4 = (uint)*(byte *)(iVar7 + 0x73e);
          if ((int)(iStack_14 - uStack_4) < (int)(iStack_16 - uStack_4)) {
            iVar5 = iStack_14 - uStack_4;
          }
          else {
            iVar5 = iStack_16 - uStack_4;
          }
          if (iStack_26 < iVar5) {
            if ((int)(iStack_14 - uStack_4) < (int)(iStack_16 - uStack_4)) {
              iStack_26 = iStack_14 - uStack_4;
            }
            else {
              iStack_26 = iStack_16 - uStack_4;
            }
          }
          if (*(char *)(iStack_e * 0x27 + 0x11e) == '\0') {
            if ((*(uint *)(iStack_e * 0x27 + 0x121) & 0x20) == 0) {
              iVar5 = iStack_e * 0xc + ((undefined2 *)&DAT_2000_cdde)[iVar8] * 4;
              if (((*(int *)((char *)"build\\clebath2.lbm" + 8 + iVar5) == 0 &&
                    *(int *)((char *)"build\\clebath2.lbm" + 10 + iVar5) == 0) || (1 < iVar7)) ||
                 (7 < DAT_2000_d022)) {
                iVar5 = iStack_e * 0xc + ((undefined2 *)&DAT_2000_cdde)[iVar8] * 4;
                gfx_03.seg = *(uint16_t *)
                              ((char *)
                               "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                               + 0x30 + iVar5);
                gfx_03.ofs = *(uint16_t *)
                              ((char *)
                               "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                               + 0x2e + iVar5);
                ovr_blitGfxRect(gfx_03,((undefined2 *)&DAT_2000_ceb6)[iVar8],
                                (uint)*(byte *)(iVar7 + 0x74b) - iStack_26,BlitRects + 3,
                                auStack_a[iVar7],false);
              }
              else {
                iVar5 = iStack_e * 0xc + ((undefined2 *)&DAT_2000_cdde)[iVar8] * 4;
                gfx_02.seg = *(uint16_t *)((char *)"build\\clebath2.lbm" + 10 + iVar5);
                gfx_02.ofs = *(uint16_t *)((char *)"build\\clebath2.lbm" + 8 + iVar5);
                ovr_blitGfxRect(gfx_02,((undefined2 *)&DAT_2000_ceb6)[iVar8],
                                (uint)*(byte *)(iVar7 + 0x74b) - iStack_26,BlitRects + 3,
                                auStack_a[iVar7],false);
                if (1 < DAT_2000_d022) {
                  iVar5 = iStack_e * 0xc + ((undefined2 *)&DAT_2000_cdde)[iVar8] * 4;
                  ovr_gfxRlePrepare(*(undefined2 *)
                                     ((char *)
                                      "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                      + 0x2e + iVar5),
                                    *(undefined2 *)
                                     ((char *)
                                      "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                      + 0x30 + iVar5),((undefined2 *)&DAT_2000_ceb6)[iVar8],
                                    (uint)*(byte *)(iVar7 + 0x74b) - iStack_26,0x45e,
                                    (char *)"puppetmaker" + 3,
                                    CONCAT11((byte)(DAT_2000_d022 * 0xff >> 0xb),auStack_a[iVar7]),0
                                    ,0,DAT_2000_d022 * 0xff >> 3,0);
                }
              }
            }
            else {
              iVar5 = iStack_e * 0xc + (uint)GSeason * 4;
              gfx_01.seg = *(uint16_t *)
                            ((char *)
                             "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                             + 0x30 + iVar5);
              gfx_01.ofs = *(uint16_t *)
                            ((char *)
                             "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                             + 0x2e + iVar5);
              ovr_blitGfxRect(gfx_01,((undefined2 *)&DAT_2000_ceb6)[iVar8],
                              (uint)*(byte *)(iVar7 + 0x74b) - iStack_26,BlitRects + 3,
                              auStack_a[iVar7],false);
            }
          }
          else {
            if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 10) != 0) {
              uVar4 = (undefined1)((uint)((undefined2 *)&DAT_2000_ceb6)[iVar8] >> 8);
              if (((undefined2 *)&DAT_2000_ceb6)[iVar8] == ((undefined2 *)&DAT_2000_cf8e)[iVar8]) {
                iVar5 = (uint)*(byte *)(iVar7 + 0x74c) - iStack_18;
                ovr_blit_317e_0db7(*(undefined2 *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x32 + iStack_e * 0xc),
                                   *(undefined2 *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x34 + iStack_e * 0xc),((undefined2 *)&DAT_2000_ceb6)[iVar8],
                                   (uint)*(byte *)(iVar7 + 0x74b) - iStack_14,
                                   CONCAT11((char)((uint)iVar5 >> 8),auStack_a[iVar7]),iVar5,
                                   CONCAT11(uVar4,auStack_a[iVar7 + 1]),0x45e,
                                   (char *)"puppetmaker" + 3);
              }
              else {
                ovr_blit_317e_0f7d(*(undefined2 *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x2e + iStack_e * 0xc),
                                   *(undefined2 *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x30 + iStack_e * 0xc),((undefined2 *)&DAT_2000_ceb6)[iVar8],
                                   ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_14,
                                   CONCAT11(0x24,auStack_a[iVar7]),
                                   ((undefined2 *)&DAT_2000_cf8e)[iVar8],
                                   *(int *)(iVar7 * 2 + -0x7328) - iStack_18,
                                   CONCAT11(uVar4,auStack_a[iVar7 + 1]),0x45e,
                                   (char *)"puppetmaker" + 3,0);
              }
            }
            if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 8) != 0) {
              uVar4 = (undefined1)((uint)((undefined2 *)&DAT_2000_cefe)[iVar8] >> 8);
              if (((undefined2 *)&DAT_2000_cefe)[iVar8] == ((undefined2 *)&DAT_2000_ce6e)[iVar8]) {
                iVar5 = (uint)*(byte *)(iVar7 + 0x74c) - iStack_1a;
                ovr_blit_317e_0db7(*(undefined2 *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x32 + iStack_e * 0xc),
                                   *(undefined2 *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x34 + iStack_e * 0xc),((undefined2 *)&DAT_2000_ce6e)[iVar8],
                                   (uint)*(byte *)(iVar7 + 0x74b) - iStack_16,
                                   CONCAT11((char)((uint)iVar5 >> 8),auStack_a[iVar7]),iVar5,
                                   CONCAT11(uVar4,auStack_a[iVar7 + 1]),0x45e,
                                   (char *)"puppetmaker" + 3);
              }
              else {
                ovr_blit_317e_0f7d(*(undefined2 *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x2e + iStack_e * 0xc),
                                   *(undefined2 *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x30 + iStack_e * 0xc),((undefined2 *)&DAT_2000_ce6e)[iVar8],
                                   ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_16,
                                   CONCAT11(0x24,auStack_a[iVar7]),
                                   ((undefined2 *)&DAT_2000_cefe)[iVar8],
                                   *(int *)(iVar7 * 2 + -0x7328) - iStack_1a,
                                   CONCAT11(uVar4,auStack_a[iVar7 + 1]),0x45e,
                                   (char *)"puppetmaker" + 3,0);
              }
            }
            if (((*(byte *)(iStack_e * 0x27 + 0x11e) & 4) != 0) ||
               (((*(byte *)(iStack_e * 0x27 + 0x11e) & 1) != 0 && (iVar7 != 0)))) {
              ovr_blit_317e_0f7d(*(undefined2 *)
                                  ((char *)
                                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                   + 0x2e + iStack_e * 0xc),
                                 *(undefined2 *)
                                  ((char *)
                                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                   + 0x30 + iStack_e * 0xc),((undefined2 *)&DAT_2000_ceb6)[iVar8],
                                 ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_14,
                                 CONCAT11(0x24,auStack_a[iVar7]),
                                 ((undefined2 *)&DAT_2000_ce6e)[iVar8],
                                 ((undefined2 *)&DAT_2000_cdd2)[iVar7] - iStack_16,
                                 CONCAT11((char)((uint)(iStack_e * 0x27) >> 8),auStack_a[iVar7]),
                                 0x45e,(char *)"puppetmaker" + 3,0);
            }
          }
        }
      }
    }
    for (; iVar7 = DAT_2000_cdcc, iVar8 < DAT_2000_cdc6; iVar8 = iVar8 + 1) {
      if ((0xee < (int)((undefined2 *)&DAT_2000_ce6e)[iVar8]) &&
         ((int)((undefined2 *)&DAT_2000_ceb6)[iVar8] < 0x135)) {
        iVar7 = ((undefined2 *)&DAT_2000_ce26)[iVar8];
        local_1c = constr_36ce_0000(iVar7,0xfffe);
        local_1e = constr_36ce_0000(iVar7 + 1,0xfffe);
        iStack_10 = constr_36ce_0101(iVar7,0xffff,local_20);
        iStack_10 = iStack_10 / 3;
        iStack_12 = constr_36ce_0101(iVar7 + 1,0xffff,local_22);
        iStack_12 = iStack_12 / 3;
        uVar6 = constr_36ce_0080(iVar7,0xffff);
        if ((uVar6 & 4) == 0) {
          uVar4 = constr_36ce_04c4(local_20[0],local_22[0],local_1e & 0xff,uVar6,2);
          ovr_OVC07_32c9_0044(((undefined2 *)&DAT_2000_ceb6)[iVar8],DAT_2000_cdd2 - iStack_10,
                              ((undefined2 *)&DAT_2000_ce6e)[iVar8],DAT_2000_cdd2 - iStack_12,
                              ((undefined2 *)&DAT_2000_ce6e)[iVar8],0x36,uVar4,0x45e,
                              (char *)"puppetmaker" + 3);
          uVar4 = constr_36ce_04c4(CONCAT11(extraout_AH_04,(undefined1)local_1c),
                                   CONCAT11(extraout_AH_04,(undefined1)local_1e),
                                   CONCAT11(extraout_AH_04,local_20[0]),
                                   CONCAT11(extraout_AH_04,(char)uVar6),1);
          ovr_OVC07_32c9_0044(((undefined2 *)&DAT_2000_ceb6)[iVar8],DAT_2000_cdd2 - iStack_10,
                              ((undefined2 *)&DAT_2000_ceb6)[iVar8],0x36,
                              ((undefined2 *)&DAT_2000_ce6e)[iVar8],0x36,uVar4,0x45e,
                              (char *)"puppetmaker" + 3);
        }
        else {
          uVar4 = constr_36ce_04c4(local_20[0],local_22[0],local_1c & 0xff,uVar6,1);
          ovr_OVC07_32c9_0044(((undefined2 *)&DAT_2000_ceb6)[iVar8],DAT_2000_cdd2 - iStack_10,
                              ((undefined2 *)&DAT_2000_ce6e)[iVar8],DAT_2000_cdd2 - iStack_12,
                              ((undefined2 *)&DAT_2000_ceb6)[iVar8],0x36,uVar4,0x45e,
                              (char *)"puppetmaker" + 3);
          uVar4 = constr_36ce_04c4(CONCAT11(extraout_AH_03,(undefined1)local_1c),
                                   CONCAT11(extraout_AH_03,(undefined1)local_1e),
                                   CONCAT11(extraout_AH_03,local_22[0]),
                                   CONCAT11(extraout_AH_03,(char)uVar6),2);
          ovr_OVC07_32c9_0044(((undefined2 *)&DAT_2000_ce6e)[iVar8],DAT_2000_cdd2 - iStack_12,
                              ((undefined2 *)&DAT_2000_ceb6)[iVar8],0x36,
                              ((undefined2 *)&DAT_2000_ce6e)[iVar8],0x36,uVar4,0x45e,
                              (char *)"puppetmaker" + 3);
        }
        cVar2 = constr_36ce_306b(iVar7 + GfxRndSeed,GfxRndSeed2);
        if (cVar2 != '\0') {
          ovr_OVC07_32c9_0466();
        }
      }
    }
    for (; iVar7 < DAT_2000_cdc6; iVar7 = iVar7 + 1) {
      uVar1 = ((undefined2 *)&DAT_2000_ce26)[iVar7];
      iStack_e = constr_36ce_0159(uVar1,0);
      if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 2) != 0) {
        iStack_10 = constr_36ce_0101(uVar1,0xffff,local_20);
        iStack_10 = iStack_10 / 3;
        ovr_blit_317e_0db7(*(undefined2 *)
                            ((char *)
                             "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                             + 0x32 + iStack_e * 0xc),
                           *(undefined2 *)
                            ((char *)
                             "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                             + 0x34 + iStack_e * 0xc),((undefined2 *)&DAT_2000_ceb6)[iVar7],
                           (uint)DAT_2410_074b - iStack_10,6,0x27,6,0x45e,(char *)"puppetmaker" + 3)
        ;
      }
      if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 1) != 0) {
        gfx_04.seg = *(uint16_t *)
                      ((char *)
                       "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                       + 0x38 + iStack_e * 0xc);
        gfx_04.ofs = *(uint16_t *)
                      ((char *)
                       "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                       + 0x36 + iStack_e * 0xc);
        ovr_blitGfxRect(gfx_04,((undefined2 *)&DAT_2000_ceb6)[iVar7],51,BlitRects + 3,auStack_a[0],
                        false);
      }
    }
  }
  return;
}



/* 36ce:306b */

uint __cdecl16far constr_36ce_306b(int param_1,int param_2)

{
  uint in_AX;
  uint uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uStack_4;
  
  if ((((param_1 < 0) || (param_2 < 0)) || (in_AX = param_1 + 1, 0x93 < (int)in_AX)) ||
     (in_AX = param_2 + 1, 0x3b < (int)in_AX)) {
    DAT_2000_d090 = 2;
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar5 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
    uVar1 = param_1 * 2;
    if (((*(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + uVar1) & 3) == 0) &&
       (uVar1 = param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2,
       (*(uint *)(uVar1 + 0x128) & 3) == 0)) {
      uStack_4 = (int)*(char *)(param_2 * 0x94 + DAT_2000_cb05 + param_1 + 0x94);
      iVar2 = (int)*(char *)(param_2 * 0x94 + DAT_2000_cb05 + param_1 + 0x95);
      iVar4 = uStack_4;
      if (iVar2 < uStack_4) {
        iVar4 = iVar2;
      }
      if (uStack_4 < iVar2) {
        uStack_4 = iVar2;
      }
      bVar3 = (byte)((uint)(uStack_4 - iVar4) >> 8);
      if (uStack_4 - iVar4 < 9) {
        DAT_2000_d090 = 3;
        uVar1 = CONCAT11(bVar3,1);
      }
      else {
        uVar1 = (uint)bVar3 << 8;
      }
    }
    else {
      DAT_2000_d090 = 1;
      uVar1 = uVar1 & 0xff00;
    }
  }
  return uVar1;
}



/* 36ce:3172 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far constr_36ce_3172(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined1 uVar6;
  int iVar7;
  undefined2 uVar8;
  byte bStack_4;
  byte bStack_3;
  
  uVar8 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
  iVar7 = (int)DAT_2000_cb09;
  uVar5 = *(uint *)(iVar7 + param_2 * 0x128 + param_1 * 2);
  if ((uVar5 & 3) == 0) {
    if (((*(uint *)(param_2 * 0x128 + iVar7 + param_1 * 2 + -0x12a) |
          *(uint *)(param_2 * 0x128 + iVar7 + param_1 * 2 + -0x128) |
          *(uint *)(param_2 * 0x128 + iVar7 + param_1 * 2 + -0x126) |
          *(uint *)(iVar7 + param_2 * 0x128 + param_1 * 2 + -2) |
          *(uint *)(iVar7 + param_2 * 0x128 + param_1 * 2 + 2) |
          *(uint *)(param_2 * 0x128 + iVar7 + param_1 * 2 + 0x126) |
          *(uint *)(param_2 * 0x128 + iVar7 + param_1 * 2 + 0x128) |
         *(uint *)(param_2 * 0x128 + iVar7 + param_1 * 2 + 0x12a)) & 3) == 0) {
      uVar1 = *(undefined1 *)(param_2 * 0x94 + DAT_2000_cb05 + param_1 + 0x94);
      uVar2 = *(undefined1 *)(param_2 * 0x94 + DAT_2000_cb05 + param_1 + 0x95);
      uVar3 = *(undefined1 *)(DAT_2000_cb05 + param_2 * 0x94 + param_1);
      uVar4 = *(undefined1 *)(DAT_2000_cb05 + param_2 * 0x94 + param_1 + 1);
      uVar6 = (undefined1)((uint)(param_2 * 0x94) >> 8);
      if ((uVar5 & 4) == 0) {
        bStack_3 = ovr_driver_2d63_014b
                             (CONCAT11(uVar6,uVar3),CONCAT11(uVar6,uVar4),CONCAT11(uVar6,uVar2));
        bStack_4 = ovr_driver_2d63_014b(uVar1,uVar2,uVar3);
      }
      else {
        bStack_3 = ovr_driver_2d63_014b
                             (CONCAT11(uVar6,uVar3),CONCAT11(uVar6,uVar4),CONCAT11(uVar6,uVar1));
        bStack_4 = ovr_driver_2d63_014b(uVar1,uVar2,uVar4);
      }
      if ((bStack_3 < 0xfa) && (bStack_4 < 0xfa)) {
        if ((bStack_3 < 0xf5) && (bStack_4 < 0xf5)) {
          uVar8 = 2;
        }
        else {
          uVar8 = 3;
        }
      }
      else {
        uVar8 = 4;
      }
    }
    else {
      uVar8 = 1;
    }
  }
  else {
    uVar8 = 0;
  }
  return uVar8;
}


