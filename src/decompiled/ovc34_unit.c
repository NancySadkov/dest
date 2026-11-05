/*
 * ovc34_unit.c - recovered from STRONG.EXE
 * memory block: OVC34_unit.c
 * range: 6616:0000 - 6616:155f
 * functions: 6
 */
#include "recovered.h"


/* 6616:0000 */

int __cdecl16far unit_6616_0000(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
  iVar4 = (int)DAT_2000_ca95;
  iVar5 = *(int *)((uint)*(byte *)(iVar4 + param_1 * 9) * 0x27 + 0x12e);
  cVar3 = ovr_constr_36ce_3172
                    (*(undefined2 *)(iVar4 + param_1 * 9 + 4),
                     *(undefined2 *)(iVar4 + param_1 * 9 + 6));
  if (cVar3 == '\x03') {
    iVar5 = iVar5 * 3 >> 1;
  }
  else if (cVar3 == '\x04') {
    iVar5 = iVar5 << 1;
  }
  bVar1 = *(byte *)((int)DAT_2000_ca95 + param_1 * 9 + 2);
  if ((bVar1 != 0xff) &&
     (uVar2 = *(undefined4 *)((uint)bVar1 << 2), (*(byte *)((int)uVar2 + 0x5d) & 8) != 0)) {
    iVar5 = iVar5 + 5;
  }
  return iVar5;
}



/* 6616:00d8 */

void __cdecl16far unit_6616_00d8(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint16_t uVar6;
  uint16_t uVar7;
  undefined2 uVar8;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  int iStack_10;
  int iStack_e;
  uint uStack_c;
  
  if (DAT_2410_648e != '\0') {
    DAT_2410_648e = '\0';
    ovr_driver_2d63_0a67((undefined2)DAT_2000_cb09,DAT_2000_cb09._2_2_,0,0,0x93,0x3b,0xfff7);
    for (uStack_c = 0; uStack_c < EntityCount; uStack_c = uStack_c + 1) {
      uVar7 = Entities.seg;
      uVar6 = Entities.ofs;
      uVar4 = (uint)*(byte *)(uVar6 + uStack_c * 0x37 + 0xd);
      if (*(char *)((int)(char **)GMenuStrings + uVar4 * 0x95 + 0x1f) == '\0') {
        if (uVar4 == 3) {
          iStack_16 = 0xf;
        }
        else if (uVar4 == 0xb) {
          iStack_16 = 8;
        }
        else {
          iStack_16 = 5;
        }
        iVar2 = *(int *)(uVar6 + uStack_c * 0x37);
        iStack_14 = *(int *)(uVar6 + uStack_c * 0x37 + 2);
        iStack_e = ovr_OVC23_55fe_3450(iVar2 + iStack_16 * -2);
        iStack_e = iStack_e + -2;
        iStack_10 = ovr_OVC23_55fe_3450(iVar2 + iStack_16 * 2);
        iStack_10 = iStack_10 + 1;
        if (iStack_e < 0) {
          iStack_e = 0;
        }
        if (0x93 < iStack_10) {
          iStack_10 = 0x93;
        }
        iStack_12 = iStack_14 - iStack_16;
        iStack_14 = iStack_14 + iStack_16;
        if (iStack_12 < 0) {
          iStack_12 = 0;
        }
        if (0x3b < iStack_14) {
          iStack_14 = 0x3b;
        }
        ovr_driver_2d63_0a24
                  ((undefined2)DAT_2000_cb09,DAT_2000_cb09._2_2_,iStack_e,iStack_12,iStack_10,
                   iStack_14,8);
      }
    }
    for (uStack_c = 0xf8; uStack_c < DAT_2000_ca99; uStack_c = uStack_c + 1) {
      uVar8 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
      if (((*(int *)((uint)*(byte *)((int)DAT_2000_ca95 + uStack_c * 9) * 0x27 + 0x12e) != 0) &&
          (bVar1 = *(byte *)((int)DAT_2000_ca95 + uStack_c * 9 + 2), bVar1 != 0xff)) &&
         (uVar3 = *(undefined4 *)((uint)bVar1 << 2), *(char *)((int)uVar3 + 0x3f) == '\0')) {
        iVar5 = unit_6616_0000(uStack_c);
        uVar8 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
        iVar2 = *(int *)((int)DAT_2000_ca95 + uStack_c * 9 + 4);
        iStack_14 = *(int *)((int)DAT_2000_ca95 + uStack_c * 9 + 6);
        iStack_e = ovr_OVC23_55fe_3450(iVar2 + iVar5 * -2);
        iStack_e = iStack_e + -2;
        iStack_10 = ovr_OVC23_55fe_3450(iVar2 + iVar5 * 2);
        iStack_10 = iStack_10 + 1;
        if (iStack_e < 0) {
          iStack_e = 0;
        }
        if (0x93 < iStack_10) {
          iStack_10 = 0x93;
        }
        iStack_12 = iStack_14 - iVar5;
        iStack_14 = iStack_14 + iVar5;
        if (iStack_12 < 0) {
          iStack_12 = 0;
        }
        if (0x3b < iStack_14) {
          iStack_14 = 0x3b;
        }
        ovr_driver_2d63_0a24
                  ((undefined2)DAT_2000_cb09,DAT_2000_cb09._2_2_,iStack_e,iStack_12,iStack_10,
                   iStack_14,8);
      }
    }
  }
  return;
}



/* 6616:03bd */

undefined2 __cdecl16far keyprocessor_6616_03bd(int *param_1,int *param_2,undefined1 *param_3)

{
  uint16_t uVar1;
  char *pcVar2;
  
  ovr_OVC13_3d16_005b();
  uVar1 = ovr_biosKeyAvail();
  if ((char)uVar1 == '\0') {
    return 0;
  }
  pcVar2 = (char *)ovr_gameProcessKey();
  while (uVar1 = ovr_biosKeyAvail(), (char)uVar1 != '\0') {
    pcVar2 = (char *)ovr_gameProcessKey();
  }
  if (pcVar2 == (char *)"pasopl.adv" + 7) {
LAB_6616_059d:
    if (0x1f < *param_2) {
      *param_2 = *param_2 + -0x18;
      return 0;
    }
    *param_2 = (*param_2 - 7U) % 3 + 7;
    return 0;
  }
  if ((char *)"pasopl.adv" + 7 < pcVar2) {
    if (pcVar2 != (char *)"has achieved the rank of EMPEROR.  Congratulations!" + 0x17) {
      if (pcVar2 <= (char *)"has achieved the rank of EMPEROR.  Congratulations!" + 0x17) {
        if (pcVar2 != (char *)0x4b34) {
          if ((char *)0x4b34 < pcVar2) {
            if ((pcVar2 != (char *)"Food stored" + 8) && (pcVar2 != (char *)"Max. trade" + 7)) {
              return 1;
            }
            if (*param_1 + 8 < 0xde) {
              *param_1 = *param_1 + 8;
              return 0;
            }
            *param_1 = 0xde - (0xdeU - *param_1 & 7);
            return 0;
          }
          if (pcVar2 == (char *)0x4939) goto LAB_6616_059d;
          if (pcVar2 != (char *)0x4b00) {
            return 1;
          }
        }
        if (0x14 < *param_1) {
          *param_1 = *param_1 + -8;
          return 0;
        }
        *param_1 = (*param_1 - 0xcU & 7) + 0xc;
        return 0;
      }
      if (pcVar2 != (char *)"Please type your character\'s name. Esc go back." + 8) {
        if ((char *)"Please type your character\'s name. Esc go back." + 8 < pcVar2) {
          if ((pcVar2 != (char *)"%s will now build homes automatically.") &&
             (pcVar2 != (char *)"%s will no longer build houses automatically." + 0xc)) {
            return 1;
          }
          if (*param_2 + 0x18 < 0x96) {
            *param_2 = *param_2 + 0x18;
            return 0;
          }
          *param_2 = 0x96 - (0x96U - *param_2) % 3;
          return 0;
        }
        if (pcVar2 == (char *)"has destroyed all enemies and has achieved EMPEROR. Congratulations!"
                      + 0x14) goto LAB_6616_0633;
        if (pcVar2 != (char *)"Reroll ability scores, or select the character\'s class." + 0x2b) {
          return 1;
        }
      }
      if (*param_2 + 3 < 0x96) {
        *param_2 = *param_2 + 3;
        return 0;
      }
      *param_2 = 0x96 - (0x96U - *param_2) % 3;
      return 0;
    }
LAB_6616_0633:
    if (*param_1 + 0x20 < 0xde) {
      *param_1 = *param_1 + 0x20;
      return 0;
    }
    *param_1 = 0xde - (0xdeU - *param_1 & 7);
    return 0;
  }
  if (pcVar2 == (char *)"fighter outpost" + 0xf) {
LAB_6616_066e:
    *param_3 = 4;
  }
  else {
    if (pcVar2 <= (char *)"fighter outpost" + 0xf) {
      if (pcVar2 != (char *)0x1655) {
        if (pcVar2 < (char *)0x1656) {
          if ((pcVar2 != (char *)0x1352) && (pcVar2 != (char *)0x1372)) {
            return 1;
          }
          *param_3 = 3;
          return 0;
        }
        if (pcVar2 != (char *)0x1675) {
          if (pcVar2 == (char *)"%s: provides housing and income." + 8) {
            *param_3 = 1;
            return 0;
          }
          return 1;
        }
      }
      *param_3 = 2;
      return 0;
    }
    if (pcVar2 != (char *)"Your stronghold is too far away." + 3) {
      if ((char *)"Your stronghold is too far away." + 3 < pcVar2) {
        if ((pcVar2 != (char *)0x4800) && (pcVar2 != (char *)"dc%lx %d ln %ld lc %ld @%lx \r" + 0xf)
           ) {
          return 1;
        }
        if (10 < *param_2) {
          *param_2 = *param_2 + -3;
          return 0;
        }
        *param_2 = (*param_2 - 7U) % 3 + 7;
        return 0;
      }
      if (pcVar2 == (char *)"thief outpost" + 3) goto LAB_6616_066e;
      if (pcVar2 != (char *)"This location is unsuitable for a main stronghold.  %s" + 0x24) {
        return 1;
      }
    }
    if (*param_1 < 0x2d) {
      *param_1 = (*param_1 - 0xcU & 7) + 0xc;
    }
    else {
      *param_1 = *param_1 + -0x20;
    }
  }
  return 0;
}



/* 6616:0689 */

void __cdecl16far ui_unit_order_6616_0689(byte param_1)

{
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  char cVar1;
  int iVar2;
  uint16_t uVar3;
  undefined2 uVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint16_t uVar10;
  undefined2 unaff_SS;
  char *pcVar11;
  far_t fVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  char local_132 [240];
  char local_42 [5];
  byte bStack_3d;
  byte bStack_3c;
  byte local_3b;
  int iStack_3a;
  uint local_38;
  uint local_36;
  uint uStack_34;
  uint uStack_32;
  uint local_30;
  uint local_2e;
  uint uStack_2c;
  uint uStack_2a;
  uint uStack_28;
  uint uStack_26;
  uint uStack_24;
  uint uStack_22;
  uint uStack_20;
  uint uStack_1e;
  uint uStack_1c;
  far_t fStack_1a;
  brect_t local_16;
  uint uStack_c;
  char *pcStack_a;
  uint16_t uStack_8;
  far_t fStack_6;
  
  if (GOngoingBattle == '\0') {
    return;
  }
  ovr_miceBlitRect(BlitRects + 1);
  bStack_3c = ((undefined1 *)&DAT_2000_d1de)[param_1];
  if (bStack_3c == 0xff) {
    return;
  }
  bStack_3d = *(byte *)((int)*(undefined4 *)((uint)bStack_3c << 2) + 0x2f);
  if (bStack_3d == 0xff) {
    return;
  }
  pcVar11 = ovr_stsprintf(local_132,"Define region to command %s loyal to %s.",
                          (char *)*(undefined2 *)((uint)bStack_3d * 4 + 0x107));
  ovr_say(pcVar11);
  do {
    iVar2 = ovr_init2_3338_0388(&local_2e);
  } while (iVar2 != 0);
  while (uVar3 = ovr_biosKeyAvail(), (char)uVar3 != '\0') {
    ovr_gameProcessKey();
  }
  memcpy((uint8_t *)&local_16,(uint8_t *)(brect_t *)BlitRects,10);
  local_16.seg = 0xa000;
  uVar13 = (undefined1)unaff_SS;
  uVar15 = (undefined1)((uint)unaff_SS >> 8);
  ovr_miceRestoreArea((brect_t *)CONCAT13(uVar15,CONCAT12(uVar13,&local_16)));
  fStack_1a = ovr_stshRleCut((far_t)0xa0000000,12,7,222,150);
  ovr_miceBlitRect((brect_t *)CONCAT13(uVar15,CONCAT12(uVar13,&local_16)));
  fStack_6 = (far_t)ovr_stshAlloc(0xfa0f);
  fVar12 = ovr_alignToSeg(fStack_6);
  uStack_8 = fVar12.seg;
  uStack_2a = local_2e;
  uStack_2c = local_30;
  local_36 = (GfxRndSeed - Seed_2000_d110) * 2 + 7;
  local_38 = (GfxRndSeed2 - Seed_2000_d10e) * 3 + 8;
  uStack_32 = 0xffff;
  uStack_34 = 0xffff;
  local_3b = 0;
  DAT_2000_ccaf = '\0';
  do {
    cVar1 = keyprocessor_6616_03bd(&local_36);
    if (cVar1 != '\0') goto LAB_6616_1054;
    if ((local_36 != uStack_32) || (local_38 != uStack_34)) {
      uStack_32 = local_36;
      uStack_1c = local_36;
      uStack_34 = local_38;
      uStack_1e = local_38;
      local_16.seg = uStack_8;
      dst.seg._0_1_ = (char)uStack_8;
      dst.ofs = 0x8cc;
      dst.seg._1_1_ = (char)(uStack_8 >> 8);
      ovr_blitLoadRleGfx(fStack_1a,dst);
      fVar12.seg = MiceCursors[3].seg;
      fVar12.ofs = MiceCursors[3].ofs;
      ovr_blitGfx10(fVar12,local_36 - 6,local_38 - 5,(brect_t *)CONCAT22(unaff_SS,&local_16),0);
      ovr_miceBlitRect((brect_t *)CONCAT13(uVar15,CONCAT12(uVar13,&local_16)));
      ovr_blitRect((brect_t *)CONCAT13(uVar15,CONCAT12(uVar13,&local_16)));
      ovr_miceUpdate();
    }
    if (local_3b == 0) {
      local_3b = ovr_init2_3338_0388(&local_2e);
    }
    if (DAT_2000_ccaf != '\0') goto LAB_6616_1054;
    if ((local_2e != uStack_2a) || (local_30 != uStack_2c)) {
      uStack_2a = local_2e;
      uStack_1c = local_2e;
      uStack_2c = local_30;
      uStack_1e = local_30;
    }
  } while (local_3b == 0);
  if ((((0xb < (int)uStack_1c) && ((int)uStack_1c < 0xdf)) && (6 < (int)uStack_1e)) &&
     ((int)uStack_1e < 0x97)) {
    do {
      iVar2 = ovr_init2_3338_0388(&local_2e);
    } while (iVar2 != 0);
    uStack_26 = 0xffff;
    uStack_28 = 0xffff;
    uStack_20 = uStack_1e;
    local_3b = 0;
    uVar9 = uStack_1c;
    do {
      cVar1 = keyprocessor_6616_03bd(&local_36);
      if (cVar1 != '\0') goto LAB_6616_1054;
      if ((local_36 != uStack_32) || (local_38 != uStack_34)) {
        uStack_32 = local_36;
        uStack_34 = local_38;
        uStack_20 = local_38;
        uVar9 = local_36;
      }
      if ((int)uVar9 < 0xc) {
        uVar9 = 0xc;
      }
      if (0xde < (int)uVar9) {
        uVar9 = 0xde;
      }
      if ((int)uStack_20 < 7) {
        uStack_20 = 7;
      }
      if (0x96 < (int)uStack_20) {
        uStack_20 = 0x96;
      }
      if ((uStack_26 != uVar9) || (uStack_28 != uStack_20)) {
        local_16.seg = uStack_8;
        dst_00.seg._0_1_ = (char)uStack_8;
        dst_00.ofs = 0x8cc;
        dst_00.seg._1_1_ = (char)(uStack_8 >> 8);
        ovr_blitLoadRleGfx(fStack_1a,dst_00);
        ovr_vga_2d63_04b7(uStack_1c,uStack_1e,uVar9,uStack_1e,0xff,(char)uStack_8);
        ovr_vga_2d63_04b7(uStack_1c,uStack_1e,uStack_1c,uStack_20,0xff,(char)uStack_8);
        ovr_vga_2d63_04b7(uVar9,uStack_1e,uVar9,uStack_20,0xff,(char)uStack_8);
        ovr_vga_2d63_04b7(uStack_1c,uStack_20,uVar9,uStack_20,0xff,(char)uStack_8);
        ovr_miceBlitRect((brect_t *)CONCAT13(uVar15,CONCAT12(uVar13,&local_16)));
        ovr_blitRect((brect_t *)CONCAT13(uVar15,CONCAT12(uVar13,&local_16)));
        ovr_miceUpdate();
        uVar5 = (int)(uStack_20 - 9) / 3 + Seed_2000_d10e;
        uVar7 = Seed_2000_d110 + (uVar9 - 0xc >> 1) + 2 & 0xfffc;
        uStack_24 = (int)(uStack_1e - 9) / 3 + Seed_2000_d10e;
        uStack_22 = Seed_2000_d110 + (uStack_1c - 0xc >> 1) + 2 & 0xfffc;
        uStack_26 = uVar7;
        if ((int)uVar7 < (int)uStack_22) {
          uStack_26 = uStack_22;
          uStack_22 = uVar7;
          uStack_c = uVar7;
        }
        uStack_28 = uVar5;
        if ((int)uVar5 < (int)uStack_24) {
          uStack_28 = uStack_24;
          uStack_24 = uVar5;
          uStack_c = uVar5;
        }
        pcStack_a = (char *)0x0;
        for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
          uVar10 = Entities.seg;
          uVar3 = Entities.ofs;
          if ((((*(byte *)(uVar3 + uVar5 * 0x37 + 0x1a) == bStack_3c) &&
               (uStack_22 <= *(uint *)(uVar3 + uVar5 * 0x37))) &&
              (*(uint *)(uVar3 + uVar5 * 0x37) <= uStack_26)) &&
             ((uStack_24 <= *(uint *)(uVar3 + uVar5 * 0x37 + 2) &&
              (*(uint *)(uVar3 + uVar5 * 0x37 + 2) <= uStack_28)))) {
            pcStack_a = pcStack_a + 1;
          }
        }
        ovr_font_302d_0a30();
        uVar14 = 0;
        uVar16 = 0xa0;
        pcVar6 = (char *)"halfling castle" + 0xc;
        uVar4 = ovr_OVC45_77eb_226e();
        ovr_OVC41_6a8f_0000(pcStack_a,uVar4,pcVar6);
        pcVar11 = ovr_stsprintf(local_132,
                                "%d %s%s loyal to %s found. Left click: set triangles. R: ready. U: unassign. H: home. Right click: abort."
                                ,pcStack_a);
        ovr_uiNotify(pcVar11,CONCAT11(uVar16,uVar14));
      }
      uStack_28 = uStack_20;
      uStack_26 = uVar9;
      if (local_3b == 0) {
        local_3b = ovr_init2_3338_0388(&local_2e);
      }
      if (DAT_2000_ccaf != '\0') goto LAB_6616_1054;
      if ((local_2e != uStack_2a) || (local_30 != uStack_2c)) {
        uStack_2a = local_2e;
        uStack_2c = local_30;
        uStack_20 = local_30;
        uVar9 = local_2e;
      }
    } while (local_3b == 0);
    ovr_miceRestoreArea(BlitRects + 1);
    if ((((0xb < (int)uVar9) && ((int)uVar9 < 0xdf)) && (6 < (int)uStack_20)) &&
       ((int)uStack_20 < 0x97)) {
      uVar5 = (int)(uStack_20 - 9) / 3 + Seed_2000_d10e;
      uVar7 = Seed_2000_d110 + (uVar9 - 0xc >> 1) + 2 & 0xfffc;
      uVar9 = (int)(uStack_1e - 9) / 3 + Seed_2000_d10e;
      uVar8 = Seed_2000_d110 + (uStack_1c - 0xc >> 1) + 2 & 0xfffc;
      uStack_26 = uVar7;
      uStack_22 = uVar8;
      if ((int)uVar7 < (int)uVar8) {
        uStack_26 = uVar8;
        uStack_22 = uVar7;
        uStack_c = uVar8;
      }
      uStack_28 = uVar5;
      uStack_24 = uVar9;
      if ((int)uVar5 < (int)uVar9) {
        uStack_28 = uVar9;
        uStack_24 = uVar5;
        uStack_c = uVar9;
      }
      _fmemset((char *)CONCAT22(unaff_SS,local_42),0,5);
      pcStack_a = (char *)0x0;
      for (uVar9 = 0; uVar9 < EntityCount; uVar9 = uVar9 + 1) {
        uVar10 = Entities.seg;
        uVar3 = Entities.ofs;
        if (((*(byte *)(uVar3 + uVar9 * 0x37 + 0x1a) == bStack_3c) &&
            (uStack_22 <= *(uint *)(uVar3 + uVar9 * 0x37))) &&
           ((*(uint *)(uVar3 + uVar9 * 0x37) <= uStack_26 &&
            ((uStack_24 <= *(uint *)(uVar3 + uVar9 * 0x37 + 2) &&
             (*(uint *)(uVar3 + uVar9 * 0x37 + 2) <= uStack_28)))))) {
          if (local_3b < 2) {
            unit_6616_10d5(CONCAT11((char)(uVar9 * 0x37 >> 8),param_1),
                           *(undefined2 *)(uVar3 + uVar9 * 0x37),
                           (char)*(undefined2 *)(uVar3 + uVar9 * 0x37 + 2));
          }
          else {
            unit_6616_12ce(CONCAT11((char)((uint)local_42 >> 8),local_3b),uVar9,local_42);
          }
          pcStack_a = pcStack_a + 1;
        }
      }
      for (iStack_3a = 0; iStack_3a < 5; iStack_3a = iStack_3a + 1) {
        if (local_42[iStack_3a] != '\0') {
          ovr_OVC41_6a8f_1be0((char)iStack_3a);
        }
      }
      ovr_constr_36ce_1db4();
      ovr_font_302d_0a30();
      uVar14 = SUB21(pcStack_a,0);
      if (local_3b == 1) {
        ovr_OVC41_6a8f_0000(uVar14);
        pcVar11 = ovr_stsprintf(local_132,"Priorities adjusted for %d %s%s.",pcStack_a);
        ovr_say(pcVar11);
      }
      else if (local_3b == 2) {
        ovr_OVC41_6a8f_0000(uVar14);
        pcVar11 = ovr_stsprintf(local_132,"%d %s%s unassigned.",pcStack_a);
        ovr_say(pcVar11);
      }
      else if (local_3b == 3) {
        ovr_OVC41_6a8f_0000(uVar14);
        pcVar11 = ovr_stsprintf(local_132,"%d %s%s readied.",pcStack_a);
        ovr_say(pcVar11);
      }
      else if (local_3b == 4) {
        ovr_OVC41_6a8f_0000(uVar14);
        pcVar11 = ovr_stsprintf(local_132,"%d %s%s homed.",pcStack_a);
        ovr_say(pcVar11);
      }
      ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
      goto LAB_6616_106e;
    }
  }
LAB_6616_1054:
  ovr_miceRestoreArea(BlitRects + 1);
  ovr_say("Region selection aborted.");
LAB_6616_106e:
  local_16.seg = uStack_8;
  dst_01.seg._0_1_ = (char)uStack_8;
  dst_01.ofs = 0x8cc;
  dst_01.seg._1_1_ = (char)(uStack_8 >> 8);
  ovr_blitLoadRleGfx(fStack_1a,dst_01);
  ovr_miceBlitRect((brect_t *)CONCAT13(uVar15,CONCAT12(uVar13,&local_16)));
  ovr_blitRect((brect_t *)CONCAT13(uVar15,CONCAT12(uVar13,&local_16)));
  ovr_miceUpdate();
  ovr_stshFree(fStack_1a);
  ovr_stshFree(fStack_6);
  ovr_miceRestoreArea(BlitRects + 1);
  return;
}



/* 6616:10d5 */

void __cdecl16far unit_6616_10d5(byte param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 unaff_SS;
  int local_16;
  int iStack_14;
  undefined1 local_12 [5];
  undefined1 local_d [11];
  
  iVar1 = ovr_OVC23_55fe_3450(param_2);
  uVar3 = 0;
  do {
    if (DAT_2410_0881 <= uVar3) {
LAB_6616_1152:
      if (DAT_2410_0881 <= uVar3) {
        memcpy((uint8_t *)&local_16,(uint8_t *)&DAT_2410_086e,0x13);
      }
      local_16 = GfxRndSeed;
      iStack_14 = GfxRndSeed2;
      local_12[param_1] = ((undefined *)&DAT_2000_d178)[param_1];
      local_d[param_1] = ((undefined *)&DAT_2000_d17d)[param_1];
      if (uVar3 < DAT_2410_0881) {
        if (uVar3 + 1 < DAT_2410_0881) {
          _fmemmove((uint8_t *)(uVar3 * 0x13),(uint8_t *)(uVar3 * 0x13 + 0x13),
                    ((DAT_2410_0881 - uVar3) + -1) * 0x13);
        }
        DAT_2410_0881 = DAT_2410_0881 - 1;
        iVar2 = memcmp(0x86e,(char *)"puppetmaker" + 3,&local_16);
        if (iVar2 == 0) {
          return;
        }
      }
      else {
        iVar2 = memcmp(0x86e,(char *)"puppetmaker" + 3,&local_16);
        if (iVar2 == 0) {
          return;
        }
        if (299 < DAT_2410_0881) {
          _fmemmove((uint8_t *)0x0,
                    (uint8_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xf),0x1631);
          DAT_2410_0881 = 299;
        }
      }
      iStack_14 = param_3;
      local_16 = iVar1;
      memcpy((uint8_t *)(DAT_2410_0881 * 0x13),(uint8_t *)&local_16,0x13);
      DAT_2410_0881 = DAT_2410_0881 + 1;
      return;
    }
    iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(uVar3 * 0x13));
    if ((iVar2 == iVar1) && (*(int *)(uVar3 * 0x13 + 2) == param_3)) {
      memcpy((uint8_t *)&local_16,(uint8_t *)(uVar3 * 0x13),0x13);
      goto LAB_6616_1152;
    }
    uVar3 = uVar3 + 1;
  } while( true );
}



/* 6616:12ce */

void __cdecl16far unit_6616_12ce(char param_1,int param_2,undefined2 param_3,undefined2 param_4)

{
  byte *pbVar1;
  undefined2 uVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  
  pbVar1 = (byte *)(Entities.ofs + param_2 * 0x37 + 0x33);
  *pbVar1 = *pbVar1 & 0xf8;
  if (param_1 != '\x02') {
    if (param_1 == '\x03') {
      pbVar1 = (byte *)(Entities.ofs + param_2 * 0x37 + 0x33);
      *pbVar1 = *pbVar1 | 1;
      ovr_attact_3f0b_0ade(param_2,0,0,param_3,param_4);
    }
    else if (param_1 == '\x04') {
      pbVar1 = (byte *)(Entities.ofs + param_2 * 0x37 + 0x33);
      *pbVar1 = *pbVar1 | 2;
      uVar4 = Entities.seg;
      uVar3 = Entities.ofs;
      uVar2 = *(undefined2 *)(uVar3 + param_2 * 0x37 + 2);
      *(undefined2 *)(uVar3 + param_2 * 0x37 + 4) = *(undefined2 *)(uVar3 + param_2 * 0x37);
      *(undefined2 *)(Entities.ofs + param_2 * 0x37 + 6) = uVar2;
      pbVar1 = (byte *)(Entities.ofs + param_2 * 0x37 + 0x33);
      *pbVar1 = *pbVar1 & 0xfa;
      ovr_attact_3f0b_0ade(param_2,0,0,param_3,param_4);
    }
  }
  return;
}


