/*
 * ovc34_unit.c - recovered from STRONG.EXE
 * memory block: OVC34_unit.c
 * range: 6616:0000 - 6616:155f
 * functions: 6
 */
#include "recovered.h"


/* 6616:0000 */

/* [R6] touches GUnits, bldType */

int __cdecl16far unit_usesGUnits(int unitIndex,...)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  unit_t *puVar5;
  int iVar6;
  int unaff_DI;
  undefined2 uVar7;
  int in_stack_00000004;
  
  iVar3 = in_stack_00000004;
  uVar7 = (undefined2)((ulong)GUnits >> 0x10);
  puVar5 = (unit_t *)GUnits;
  iVar6 = *(int *)((uint)(puVar5 + in_stack_00000004)->bldType * 0x27 + 0x12e);
  uVar4 = ovr_constr_usesGMapFlags2
                    (puVar5[in_stack_00000004].y,unaff_DI,puVar5[in_stack_00000004].x);
  if ((uVar4 & 0xff) == 3) {
    iVar6 = iVar6 * 3 >> 1;
  }
  else if ((uVar4 & 0xff) == 4) {
    iVar6 = iVar6 << 1;
  }
  bVar1 = ((unit_t *)GUnits)[iVar3].unitType;
  if ((bVar1 != 0xff) &&
     (uVar2 = *(undefined4 *)((uint)bVar1 << 2), (*(byte *)((int)uVar2 + 0x5d) & 8) != 0)) {
    iVar6 = iVar6 + 5;
  }
  return iVar6;
}



/* 6616:00d8 */

/* [R4] calls ovr_alignUp4 */

void __cdecl16far unit_usesAlignUp4(void...)

{
  byte bVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  entity_t *peVar8;
  uint unaff_DI;
  undefined2 uVar9;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  int iStack_10;
  int iStack_e;
  uint uStack_c;
  
  if (mapDirty != '\0') {
    mapDirty = '\0';
    ovr_driver_clearMapFlagsRect
              ((ulong)(*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),0,0x93,0x3b,-9,unaff_DI,(short (*) [60] [148])GMapFlags);
    for (uStack_c = 0; uStack_c < EntityCount; uStack_c = uStack_c + 1) {
      uVar9 = (undefined2)((ulong)Entities >> 0x10);
      peVar8 = (entity_t *)Entities;
      uVar6 = (uint)peVar8[uStack_c].base.gindex;
      if (*(char *)((int)(char **)GMenuStrings + uVar6 * 0x95 + 0x1f) == '\0') {
        if (uVar6 == 3) {
          iStack_16 = 0xf;
        }
        else if (uVar6 == 0xb) {
          iStack_16 = 8;
        }
        else {
          iStack_16 = 5;
        }
        uVar2 = ((peVar8 + uStack_c)->base).x;
        uVar3 = peVar8[uStack_c].base.y;
        uVar6 = ovr_alignUp4(unaff_DI,uVar2 + iStack_16 * -2);
        iStack_e = uVar6 - 2;
        uVar6 = ovr_alignUp4(unaff_DI,uVar2 + iStack_16 * 2);
        iStack_10 = uVar6 + 1;
        if (iStack_e < 0) {
          iStack_e = 0;
        }
        if (0x93 < iStack_10) {
          iStack_10 = 0x93;
        }
        iStack_12 = uVar3 - iStack_16;
        iStack_14 = uVar3 + iStack_16;
        if (iStack_12 < 0) {
          iStack_12 = 0;
        }
        if (0x3b < iStack_14) {
          iStack_14 = 0x3b;
        }
        ovr_driver_setMapFlagsRect
                  (CONCAT22(iStack_e,(*(uint16_t *)((uint8_t *)&(GMapFlags) + 2))),iStack_12,iStack_10,iStack_14,8,unaff_DI,
                   (short (*) [60] [148])GMapFlags);
      }
    }
    for (uStack_c = 0xf8; uStack_c < GUnitCount; uStack_c = uStack_c + 1) {
      uVar9 = (undefined2)((ulong)GUnits >> 0x10);
      if (((*(int *)((uint)((unit_t *)GUnits + uStack_c)->bldType * 0x27 + 0x12e) != 0) &&
          (bVar1 = ((unit_t *)GUnits)[uStack_c].unitType, bVar1 != 0xff)) &&
         (uVar5 = *(undefined4 *)((uint)bVar1 << 2), *(char *)((int)uVar5 + 0x3f) == '\0')) {
        iVar7 = unit_usesGUnits(unaff_DI,uStack_c);
        uVar9 = (undefined2)((ulong)GUnits >> 0x10);
        iVar4 = ((unit_t *)GUnits)[uStack_c].x;
        iStack_14 = ((unit_t *)GUnits)[uStack_c].y;
        uVar6 = ovr_alignUp4(unaff_DI,iVar4 + iVar7 * -2);
        iStack_e = uVar6 - 2;
        uVar6 = ovr_alignUp4(unaff_DI,iVar4 + iVar7 * 2);
        iStack_10 = uVar6 + 1;
        if (iStack_e < 0) {
          iStack_e = 0;
        }
        if (0x93 < iStack_10) {
          iStack_10 = 0x93;
        }
        iStack_12 = iStack_14 - iVar7;
        iStack_14 = iStack_14 + iVar7;
        if (iStack_12 < 0) {
          iStack_12 = 0;
        }
        if (0x3b < iStack_14) {
          iStack_14 = 0x3b;
        }
        ovr_driver_setMapFlagsRect
                  (CONCAT22(iStack_e,(*(uint16_t *)((uint8_t *)&(GMapFlags) + 2))),iStack_12,iStack_10,iStack_14,8,unaff_DI,
                   (short (*) [60] [148])GMapFlags);
      }
    }
  }
  return;
}



/* 6616:03bd */

/* [R4] calls ovr_biosKeyAvail */

uint __cdecl16far keyprocessor_usesBiosKeyAvail(uint16_t *cursorX,uint16_t *cursorY,uint8_t *input)

{
  uint uVar1;
  uint16_t uVar2;
  
  ovr_ovc13_usesMiceBlitRect();
  uVar1 = ovr_biosKeyAvail();
  if ((char)uVar1 == '\0') goto L_keyprocessor_6616_03bd_0684;
  uVar1 = ovr_gameProcessKey();
  while (uVar2 = ovr_biosKeyAvail(), (char)uVar2 != '\0') {
    uVar1 = ovr_gameProcessKey();
  }
  if (uVar1 == 0x4900) {
L_keyprocessor_6616_03bd_059D:
    if ((int)*cursorY < 0x20) {
      uVar1 = (*cursorY - 7) / 3;
      *cursorY = (*cursorY - 7) % 3 + 7;
    }
    else {
      *cursorY = *cursorY - 0x18;
    }
    goto L_keyprocessor_6616_03bd_0684;
  }
  if (0x4900 < uVar1) {
    if (uVar1 == 0x4f00) {
L_keyprocessor_6616_03bd_0633:
      uVar1 = *cursorX + 0x20;
      if ((int)uVar1 < 0xde) {
        *cursorX = *cursorX + 0x20;
      }
      else {
        uVar1 = 0xde - *cursorX & 7;
        *cursorX = 0xde - uVar1;
      }
    }
    else {
      if (uVar1 < 0x4f01) {
        if (uVar1 != 0x4b34) {
          if (0x4b34 < uVar1) {
            if ((uVar1 == 0x4d00) || (uVar1 == 0x4d36)) {
              uVar1 = *cursorX + 8;
              if ((int)uVar1 < 0xde) {
                *cursorX = *cursorX + 8;
              }
              else {
                uVar1 = 0xde - *cursorX & 7;
                *cursorX = 0xde - uVar1;
              }
              goto L_keyprocessor_6616_03bd_0684;
            }
            goto L_keyprocessor_6616_03bd_0680;
          }
          if (uVar1 == 0x4939) goto L_keyprocessor_6616_03bd_059D;
          if (uVar1 != 0x4b00) goto L_keyprocessor_6616_03bd_0680;
        }
        if ((int)*cursorX < 0x15) {
          uVar1 = (*cursorX - 0xc & 7) + 0xc;
          *cursorX = uVar1;
        }
        else {
          *cursorX = *cursorX - 8;
        }
        goto L_keyprocessor_6616_03bd_0684;
      }
      if (uVar1 != 0x5032) {
        if (0x5032 < uVar1) {
          if ((uVar1 == 0x5100) || (uVar1 == 0x5133)) {
            uVar1 = *cursorY + 0x18;
            if ((int)uVar1 < 0x96) {
              *cursorY = *cursorY + 0x18;
            }
            else {
              uVar1 = 0x96 - (0x96 - *cursorY) % 3;
              *cursorY = uVar1;
            }
            goto L_keyprocessor_6616_03bd_0684;
          }
          goto L_keyprocessor_6616_03bd_0680;
        }
        if (uVar1 == 0x4f31) goto L_keyprocessor_6616_03bd_0633;
        if (uVar1 != 0x5000) goto L_keyprocessor_6616_03bd_0680;
      }
      uVar1 = *cursorY + 3;
      if ((int)uVar1 < 0x96) {
        *cursorY = *cursorY + 3;
      }
      else {
        uVar1 = 0x96 - (0x96 - *cursorY) % 3;
        *cursorY = uVar1;
      }
    }
    goto L_keyprocessor_6616_03bd_0684;
  }
  if (uVar1 == 0x2348) {
L_keyprocessor_6616_03bd_066E:
    *input = 0x4;
  }
  else {
    if (uVar1 < 0x2349) {
      if (uVar1 != 0x1655) {
        if (uVar1 < 0x1656) {
          if ((uVar1 != 0x1352) && (uVar1 != 0x1372)) goto L_keyprocessor_6616_03bd_0680;
          *input = 0x3;
          goto L_keyprocessor_6616_03bd_0684;
        }
        if (uVar1 != 0x1675) {
          if (uVar1 != 0x1c0d) goto L_keyprocessor_6616_03bd_0680;
          *input = 0x1;
          goto L_keyprocessor_6616_03bd_0684;
        }
      }
      *input = 0x2;
      goto L_keyprocessor_6616_03bd_0684;
    }
    if (uVar1 != 0x4737) {
      if (0x4737 < uVar1) {
        if ((uVar1 == 0x4800) || (uVar1 == 0x4838)) {
          if ((int)*cursorY < 0xb) {
            uVar1 = (*cursorY - 7) / 3;
            *cursorY = (*cursorY - 7) % 3 + 7;
          }
          else {
            *cursorY = *cursorY - 3;
          }
          goto L_keyprocessor_6616_03bd_0684;
        }
L_keyprocessor_6616_03bd_0680:
        return CONCAT11((char)(uVar1 >> 8),1);
      }
      if (uVar1 == 0x2368) goto L_keyprocessor_6616_03bd_066E;
      if (uVar1 != 0x4700) goto L_keyprocessor_6616_03bd_0680;
    }
    if ((int)*cursorX < 0x2d) {
      uVar1 = (*cursorX - 0xc & 7) + 0xc;
      *cursorX = uVar1;
    }
    else {
      *cursorX = *cursorX - 0x20;
    }
  }
L_keyprocessor_6616_03bd_0684:
  return uVar1 & 0xff00;
}



/* 6616:0689 */

/* [R2] string "Define region to command %s loyal to %s." */

void __cdecl16far ui_textDefineRegionCommand(byte menuIndex,...)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t ptr;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  far_t handle;
  far_t handle_00;
  byte bVar1;
  char *pcVar2;
  undefined1 extraout_AH;
  uint16_t uVar3;
  undefined2 uVar4;
  undefined1 extraout_AH_00;
  int count;
  byte *pbVar5;
  uint16_t uVar6;
  undefined2 uVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined2 uVar10;
  entity_t *peVar11;
  uint uVar12;
  undefined2 unaff_DI;
  byte *pbVar13;
  uint16_t *unaff_SS;
  byte in_stack_00000004;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  undefined1 type;
  undefined1 uVar18;
  uint8_t text;
  uint8_t msg;
  uint8_t unitFlags;
  byte bStack_3d;
  byte bStack_3c;
  uint8_t input;
  int iStack_3a;
  uint8_t cursorY;
  uint8_t cursorX;
  byte *pbStack_34;
  byte *pbStack_32;
  uint8_t mouseY;
  uint8_t mouseX;
  byte *pbStack_2c;
  byte *pbStack_2a;
  byte *pbStack_28;
  byte *pbStack_26;
  byte *pbStack_24;
  byte *pbStack_22;
  byte *pbStack_20;
  byte *pbStack_1e;
  byte *pbStack_1c;
  far_t *pfStack_1a;
  uint16_t uStack_18;
  uint8_t saveArea;
  uint16_t uStack_e;
  byte *pbStack_c;
  int iStack_a;
  uint16_t uStack_8;
  void *pvStack_6;
  uint16_t uStack_4;
  
  type = (undefined1)unaff_DI;
  uVar18 = (undefined1)((uint)unaff_DI >> 8);
  if (GOngoingBattle == '\0') {
    return;
  }
  ovr_miceBlitRect((brect_t *)CONCAT13(uVar18,CONCAT12(type,0x2410)),0x44a);
  bStack_3c = ((uint8_t *)MenuItemEnabled)[in_stack_00000004];
  if (bStack_3c == 0xff) {
    return;
  }
  bStack_3d = *(byte *)((int)*(undefined4 *)((uint)bStack_3c << 2) + 0x2f);
  if (bStack_3d == 0xff) {
    return;
  }
  uVar6 = 0x2410;
  pcVar2 = (char *)*(undefined2 *)((uint)bStack_3d * 4 + 0x109);
  uVar4 = *(undefined2 *)((uint)bStack_3d * 4 + 0x107);
  uVar14 = (undefined1)uVar4;
  pcVar2 = ovr_stsprintf((char *)CONCAT22(0x648f,unaff_SS),
                         (char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12(uVar14,0x2410)),pcVar2,
                         &msg,uVar14,(char)pcVar2,*(undefined2 *)((uint)bStack_3c * 4),
                         (char)((undefined2 *)((uint)bStack_3c * 4))[1]);
  ovr_say((char *)CONCAT13(uVar18,CONCAT12(type,uVar6)),pcVar2);
  do {
    uVar14 = SUB21(unaff_SS,0);
    uVar16 = (undefined1)((uint)unaff_SS >> 8);
    bVar1 = ovr_init2_usesCFGMice((uint16_t *)CONCAT22(&mouseY,unaff_SS),(char)&mouseX);
  } while (CONCAT11(extraout_AH,bVar1) != 0);
  while (uVar3 = ovr_biosKeyAvail(), (char)uVar3 != '\0') {
    ovr_gameProcessKey();
  }
  memcpy((char *)CONCAT13(uVar16,CONCAT12(uVar14,&saveArea)),(char *)BlitRects,10);
  uStack_e = 0xa000;
  ovr_miceRestoreArea((brect_t *)CONCAT13(uVar18,CONCAT12(type,unaff_SS)),&saveArea);
  pfStack_1a = ovr_stshRleCut((far_t *)0xa000,far_from_u32((uint32_t)(0x7000c)),222,150,0,0xc,7,0x96);
  uStack_18 = uVar6;
  ovr_miceBlitRect((brect_t *)CONCAT13(uVar18,CONCAT12(type,unaff_SS)),&saveArea);
  pvStack_6 = ovr_stshAlloc((ulong)CONCAT11(uVar18,type) << 0x10,0xfa0f);
  (*(uint8_t *)((uint8_t *)&(ptr.seg))) = type;
  ptr.ofs = uVar6;
  (*(uint8_t *)((uint8_t *)&(ptr.seg) + 1)) = uVar18;
  uStack_4 = uVar6;
  ovr_alignToSeg(ptr,pvStack_6);
  pbStack_2a = _mouseX;
  pbStack_2c = _mouseY;
  _cursorX = (byte *)((GfxRndSeed - Seed_2000_d110) * 2 + 7);
  _cursorY = (byte *)((GfxRndSeed2 - Seed_2000_d10e) * 3 + 8);
  pbStack_32 = (byte *)0xffff;
  pbStack_34 = (byte *)0xffff;
  input = 0x0;
  rightButtonLatch = '\0';
  uStack_8 = uVar6;
  do {
    uVar4 = keyprocessor_usesBiosKeyAvail
                      ((uint16_t *)CONCAT22(unaff_SS,&cursorX),
                       (uint16_t *)CONCAT13(uVar16,CONCAT12(uVar14,&cursorY)),
                       (uint8_t *)CONCAT13(uVar16,CONCAT12(uVar14,&input)));
    if ((char)uVar4 != '\0') goto L_ui_unit_order_6616_0689_1054;
    if ((_cursorX != pbStack_32) || (_cursorY != pbStack_34)) {
      pbStack_32 = _cursorX;
      pbStack_1c = _cursorX;
      pbStack_34 = _cursorY;
      pbStack_1e = _cursorY;
      uStack_e = uStack_8;
      gfx_00.seg = 0x8cc;
      gfx_00.ofs = uStack_18;
      (*(uint8_t *)((uint8_t *)&(dst.seg))) = type;
      dst.ofs = uStack_8;
      (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar18;
      ovr_blitLoadRleGfx(gfx_00,dst,(char)pfStack_1a,(char)uStack_8);
      gfx.seg = (uint16_t)(_cursorX + -6);
      gfx.ofs = MiceCursors[3].seg;
      ovr_blitGfx10(gfx,(uint16_t)(_cursorY + -5),(uint16_t)&saveArea,(brect_t *)ZEXT24(unaff_SS),
                    (bool)type,MiceCursors[3].ofs,(char)(_cursorY + -5),(char)&saveArea,0);
      ovr_miceBlitRect((brect_t *)CONCAT13(uVar18,CONCAT12(type,unaff_SS)),&saveArea);
      ovr_blitRect((brect_t *)CONCAT13(uVar18,CONCAT12(type,unaff_SS)),&saveArea);
      ovr_miceUpdate();
    }
    if (input == 0x0) {
      input = ovr_init2_usesCFGMice((uint16_t *)CONCAT22(&mouseY,unaff_SS),(char)&mouseX);
    }
    if (rightButtonLatch != '\0') goto L_ui_unit_order_6616_0689_1054;
    if ((_mouseX != pbStack_2a) || (_mouseY != pbStack_2c)) {
      pbStack_2a = _mouseX;
      pbStack_1c = _mouseX;
      pbStack_2c = _mouseY;
      pbStack_1e = _mouseY;
    }
  } while (input == 0x0);
  if ((((0xb < (int)pbStack_1c) && ((int)pbStack_1c < 0xdf)) && (6 < (int)pbStack_1e)) &&
     ((int)pbStack_1e < 0x97)) {
    do {
      bVar1 = ovr_init2_usesCFGMice((uint16_t *)CONCAT22(&mouseY,unaff_SS),(char)&mouseX);
    } while (CONCAT11(extraout_AH_00,bVar1) != 0);
    pbStack_26 = (byte *)0xffff;
    pbStack_28 = (byte *)0xffff;
    pbStack_20 = pbStack_1e;
    input = 0x0;
    pbVar13 = pbStack_1c;
    do {
      uVar4 = keyprocessor_usesBiosKeyAvail
                        ((uint16_t *)CONCAT22(unaff_SS,&cursorX),
                         (uint16_t *)CONCAT13(uVar16,CONCAT12(uVar14,&cursorY)),
                         (uint8_t *)CONCAT13(uVar16,CONCAT12(uVar14,&input)));
      if ((char)uVar4 != '\0') goto L_ui_unit_order_6616_0689_1054;
      if ((_cursorX != pbStack_32) || (_cursorY != pbStack_34)) {
        pbStack_32 = _cursorX;
        pbStack_34 = _cursorY;
        pbStack_20 = _cursorY;
        pbVar13 = _cursorX;
      }
      if ((int)pbVar13 < 0xc) {
        pbVar13 = (byte *)__C0_ASM_CopyRight + 8;
      }
      if (0xde < (int)pbVar13) {
        pbVar13 = (byte *)0xde;
      }
      if ((int)pbStack_20 < 7) {
        pbStack_20 = (byte *)__C0_ASM_CopyRight + 3;
      }
      if (0x96 < (int)pbStack_20) {
        pbStack_20 = (byte *)((char *)"%d \r" + 1);
      }
      if ((pbStack_26 != pbVar13) || (pbStack_28 != pbStack_20)) {
        uStack_e = uStack_8;
        gfx_01.seg = 0x8cc;
        gfx_01.ofs = uStack_18;
        (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = type;
        dst_00.ofs = uStack_8;
        (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = uVar18;
        ovr_blitLoadRleGfx(gfx_01,dst_00,(char)pfStack_1a,(char)uStack_8);
        uVar15 = SUB21(pbVar13,0);
        ovr_driver_drawLine(pbStack_1e,(int)pbVar13,pbStack_1e,0xff,(uint8_t)uStack_8,pbStack_1c,
                            uVar15,(char)pbStack_1e);
        ovr_driver_drawLine(pbStack_1e,(int)pbStack_1c,pbStack_20,0xff,(uint8_t)uStack_8,pbStack_1c,
                            (char)pbStack_1c,(char)pbStack_20);
        ovr_driver_drawLine(pbStack_1e,(int)pbVar13,pbStack_20,0xff,(uint8_t)uStack_8,pbVar13,uVar15
                            ,(char)pbStack_20);
        ovr_driver_drawLine(pbStack_20,(int)pbVar13,pbStack_20,0xff,(uint8_t)uStack_8,pbStack_1c,
                            uVar15,(char)pbStack_20);
        ovr_miceBlitRect((brect_t *)CONCAT13(uVar18,CONCAT12(type,unaff_SS)),&saveArea);
        ovr_blitRect((brect_t *)CONCAT13(uVar18,CONCAT12(type,unaff_SS)),&saveArea);
        ovr_miceUpdate();
        pbVar5 = (byte *)((int)(pbStack_20 + -9) / 3 + Seed_2000_d10e);
        pbVar8 = (byte *)(Seed_2000_d110 + ((uint)(pbVar13 + -0xc) >> 1) + 2 & 0xfffc);
        pbStack_24 = (byte *)((int)(pbStack_1e + -9) / 3 + Seed_2000_d10e);
        pbStack_22 = (byte *)(Seed_2000_d110 + ((uint)(pbStack_1c + -0xc) >> 1) + 2 & 0xfffc);
        pbStack_26 = pbVar8;
        if ((int)pbVar8 < (int)pbStack_22) {
          pbStack_26 = pbStack_22;
          pbStack_22 = pbVar8;
          pbStack_c = pbVar8;
        }
        pbStack_28 = pbVar5;
        if ((int)pbVar5 < (int)pbStack_24) {
          pbStack_28 = pbStack_24;
          pbStack_24 = pbVar5;
          pbStack_c = pbVar5;
        }
        iStack_a = 0;
        for (uVar12 = 0; uVar12 < EntityCount; uVar12 = uVar12 + 1) {
          uVar4 = (undefined2)((ulong)Entities >> 0x10);
          peVar11 = (entity_t *)Entities;
          if ((((*(byte *)((int)&peVar11[uVar12].base.entity + 3) == bStack_3c) &&
               (pbStack_22 <= (byte *)((peVar11 + uVar12)->base).x)) &&
              ((byte *)((peVar11 + uVar12)->base).x <= pbStack_26)) &&
             ((pbStack_24 <= (byte *)peVar11[uVar12].base.y &&
              ((byte *)peVar11[uVar12].base.y <= pbStack_28)))) {
            iStack_a = iStack_a + 1;
          }
        }
        ovr_resetTextBlitCycle();
        uVar15 = 0;
        uVar17 = 0xa0;
        uVar10 = 0x217a;
        count = ovr_ovc45_compute9((char *)CONCAT22(*(undefined2 *)((uint)bStack_3c * 4),unaff_SS),
                                   (char *)CONCAT22(Font03.ofs,
                                                    (char *)((undefined2 *)((uint)bStack_3c * 4))[1]
                                                   ),(char *)(ulong)CONCAT12(0x43,Font03.seg),3,'\0'
                                   ,&text,(char)Font03.seg,0x43);
        uVar4 = ovr_ovc41_pluralSuffix(count,(char)iStack_a,uVar10);
        uVar7 = 0x2410;
        pcVar2 = ovr_stsprintf((char *)CONCAT22(0x64b8,unaff_SS),
                               (char *)CONCAT22(iStack_a,(char *)"puppetmaker" + 3),
                               (char *)*(undefined2 *)((uint)bStack_3d * 4 + 0x13f),&msg,
                               *(undefined2 *)((uint)bStack_3d * 4 + 0x141),uVar4,(char)uVar10);
        ovr_uiNotify((char *)CONCAT13(uVar17,CONCAT12(uVar15,uVar7)),(char)pcVar2);
      }
      pbStack_28 = pbStack_20;
      pbStack_26 = pbVar13;
      if (input == 0x0) {
        input = ovr_init2_usesCFGMice((uint16_t *)CONCAT22(&mouseY,unaff_SS),(char)&mouseX);
      }
      if (rightButtonLatch != '\0') goto L_ui_unit_order_6616_0689_1054;
      if ((_mouseX != pbStack_2a) || (_mouseY != pbStack_2c)) {
        pbStack_2a = _mouseX;
        pbStack_2c = _mouseY;
        pbStack_20 = _mouseY;
        pbVar13 = _mouseX;
      }
    } while (input == 0x0);
    ovr_miceRestoreArea((brect_t *)CONCAT13(uVar18,CONCAT12(type,0x2410)),0x44a);
    if ((((0xb < (int)pbVar13) && ((int)pbVar13 < 0xdf)) && (6 < (int)pbStack_20)) &&
       ((int)pbStack_20 < 0x97)) {
      pbVar5 = (byte *)((int)(pbStack_20 + -9) / 3 + Seed_2000_d10e);
      pbVar8 = (byte *)(Seed_2000_d110 + ((uint)(pbVar13 + -0xc) >> 1) + 2 & 0xfffc);
      pbVar13 = (byte *)((int)(pbStack_1e + -9) / 3 + Seed_2000_d10e);
      pbVar9 = (byte *)(Seed_2000_d110 + ((uint)(pbStack_1c + -0xc) >> 1) + 2 & 0xfffc);
      pbStack_26 = pbVar8;
      pbStack_22 = pbVar9;
      if ((int)pbVar8 < (int)pbVar9) {
        pbStack_26 = pbVar9;
        pbStack_22 = pbVar8;
        pbStack_c = pbVar9;
      }
      pbStack_28 = pbVar5;
      pbStack_24 = pbVar13;
      if ((int)pbVar5 < (int)pbVar13) {
        pbStack_28 = pbVar13;
        pbStack_24 = pbVar5;
        pbStack_c = pbVar13;
      }
      _fmemset((void *)ZEXT24(unaff_SS),5,CONCAT11(uVar18,type));
      iStack_a = 0;
      for (uVar12 = 0; uVar12 < EntityCount; uVar12 = uVar12 + 1) {
        pbVar9 = (byte *)((char *)"puppetmaker" + 3);
        uVar4 = (undefined2)((ulong)Entities >> 0x10);
        peVar11 = (entity_t *)Entities;
        if (((*(byte *)((int)&peVar11[uVar12].base.entity + 3) == bStack_3c) &&
            (pbVar9 = (byte *)((char *)"puppetmaker" + 3),
            pbStack_22 <= (byte *)((peVar11 + uVar12)->base).x)) &&
           ((pbVar9 = (byte *)((char *)"puppetmaker" + 3),
            (byte *)((peVar11 + uVar12)->base).x <= pbStack_26 &&
            ((pbVar9 = (byte *)((char *)"puppetmaker" + 3),
             pbStack_24 <= (byte *)peVar11[uVar12].base.y &&
             (pbVar9 = (byte *)((char *)"puppetmaker" + 3),
             (byte *)peVar11[uVar12].base.y <= pbStack_28)))))) {
          if (input < 2) {
            pbVar9 = (byte *)((char *)"puppetmaker" + 3);
            unit_usesAlignUp42(in_stack_00000004,((peVar11 + uVar12)->base).x,peVar11[uVar12].base.y
                              );
          }
          else {
            unit_usesEntities(input,uVar12,(uint16_t)&unitFlags,(uint16_t)unaff_SS);
          }
          iStack_a = iStack_a + 1;
        }
      }
      for (iStack_3a = 0; uVar14 = SUB21(pbVar9,0), iStack_3a < 5; iStack_3a = iStack_3a + 1) {
        if ((&unitFlags)[iStack_3a] != 0x0) {
          ovr_ovc41_usesMiceBlitRect(CONCAT11(uVar18,type),(char)iStack_3a);
        }
      }
      ovr_constr_flushDirtyRects();
      ovr_resetTextBlitCycle();
      uVar16 = (undefined1)iStack_a;
      if (input == 0x1) {
        uVar4 = ovr_ovc41_pluralSuffix(CONCAT11(uVar18,type),uVar16);
        uVar10 = 0x2410;
        pcVar2 = (char *)*(undefined2 *)((uint)bStack_3d * 4 + 0x13f);
        pcVar2 = ovr_stsprintf((char *)CONCAT22(0x6522,unaff_SS),
                               (char *)CONCAT22(iStack_a,(char *)"puppetmaker" + 3),pcVar2,&msg,
                               (char)pcVar2,(char)*(undefined2 *)((uint)bStack_3d * 4 + 0x141),uVar4
                               ,uVar14);
        ovr_say((char *)CONCAT13(uVar18,CONCAT12(type,uVar10)),pcVar2);
      }
      else if (input == 0x2) {
        uVar4 = ovr_ovc41_pluralSuffix(CONCAT11(uVar18,type),uVar16);
        uVar10 = 0x2410;
        pcVar2 = (char *)*(undefined2 *)((uint)bStack_3d * 4 + 0x13f);
        pcVar2 = ovr_stsprintf((char *)CONCAT22(0x6543,unaff_SS),
                               (char *)CONCAT22(iStack_a,(char *)"puppetmaker" + 3),pcVar2,&msg,
                               (char)pcVar2,(char)*(undefined2 *)((uint)bStack_3d * 4 + 0x141),uVar4
                               ,uVar14);
        ovr_say((char *)CONCAT13(uVar18,CONCAT12(type,uVar10)),pcVar2);
      }
      else if (input == 0x3) {
        uVar4 = ovr_ovc41_pluralSuffix(CONCAT11(uVar18,type),uVar16);
        uVar10 = 0x2410;
        pcVar2 = (char *)*(undefined2 *)((uint)bStack_3d * 4 + 0x13f);
        pcVar2 = ovr_stsprintf((char *)CONCAT22(0x6557,unaff_SS),
                               (char *)CONCAT22(iStack_a,(char *)"puppetmaker" + 3),pcVar2,&msg,
                               (char)pcVar2,(char)*(undefined2 *)((uint)bStack_3d * 4 + 0x141),uVar4
                               ,uVar14);
        ovr_say((char *)CONCAT13(uVar18,CONCAT12(type,uVar10)),pcVar2);
      }
      else if (input == 0x4) {
        uVar4 = ovr_ovc41_pluralSuffix(CONCAT11(uVar18,type),uVar16);
        uVar10 = 0x2410;
        pcVar2 = (char *)*(undefined2 *)((uint)bStack_3d * 4 + 0x13f);
        pcVar2 = ovr_stsprintf((char *)CONCAT22(0x6568,unaff_SS),
                               (char *)CONCAT22(iStack_a,(char *)"puppetmaker" + 3),pcVar2,&msg,
                               (char)pcVar2,(char)*(undefined2 *)((uint)bStack_3d * 4 + 0x141),uVar4
                               ,uVar14);
        ovr_say((char *)CONCAT13(uVar18,CONCAT12(type,uVar10)),pcVar2);
      }
      ovr_inputUpdate((ulong)CONCAT11(uVar18,type) << 0x10,(uint)MessageDelay * 2 + 0x24);
      goto L_ui_unit_order_6616_0689_106E;
    }
  }
L_ui_unit_order_6616_0689_1054:
  ovr_miceRestoreArea((brect_t *)CONCAT13(uVar18,CONCAT12(type,0x2410)),0x44a);
  ovr_say((char *)CONCAT13(uVar18,CONCAT12(type,0x2410)),0x6577);
L_ui_unit_order_6616_0689_106E:
  uStack_e = uStack_8;
  gfx_02.seg = 0x8cc;
  gfx_02.ofs = uStack_18;
  (*(uint8_t *)((uint8_t *)&(dst_01.seg))) = type;
  dst_01.ofs = uStack_8;
  (*(uint8_t *)((uint8_t *)&(dst_01.seg) + 1)) = uVar18;
  ovr_blitLoadRleGfx(gfx_02,dst_01,(char)pfStack_1a,(char)uStack_8);
  ovr_miceBlitRect((brect_t *)CONCAT13(uVar18,CONCAT12(type,unaff_SS)),&saveArea);
  ovr_blitRect((brect_t *)CONCAT13(uVar18,CONCAT12(type,unaff_SS)),&saveArea);
  ovr_miceUpdate();
  (*(uint8_t *)((uint8_t *)&(handle.seg))) = type;
  handle.ofs = uStack_18;
  (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar18;
  ovr_stshFree(handle,pfStack_1a);
  (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = type;
  handle_00.ofs = uStack_4;
  (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar18;
  ovr_stshFree(handle_00,pvStack_6);
  ovr_miceRestoreArea((brect_t *)CONCAT13(uVar18,CONCAT12(type,0x2410)),0x44a);
  return;
}



/* 6616:10d5 */

/* [R4] calls ovr_alignUp4 */

void __cdecl16far unit_usesAlignUp42(byte menuIndex,uint16_t x,int y)

{
  uint uVar1;
  uint uVar2;
  int16_t iVar3;
  uint uVar4;
  int unaff_DI;
  undefined2 unaff_SS;
  uint8_t rec;
  int iStack_14;
  uint8_t savedCursorX;
  uint8_t savedCursorY;
  
  uVar1 = ovr_alignUp4(unaff_DI,x);
  uVar4 = 0;
  do {
    if (SquareRecCount <= uVar4) {
L_unit_6616_10d5_1152:
      if (SquareRecCount <= uVar4) {
        memcpy((char *)CONCAT22(unaff_SS,&rec),(char *)&SquareRecX,0x13);
      }
      _rec = GfxRndSeed;
      iStack_14 = GfxRndSeed2;
      (&savedCursorX)[menuIndex] = ((undefined *)&menuCursorX)[menuIndex];
      (&savedCursorY)[menuIndex] = ((undefined *)&menuCursorY)[menuIndex];
      if (uVar4 < SquareRecCount) {
        if (uVar4 + 1 < SquareRecCount) {
          _fmemmove((char *)CONCAT22(0x17f8,(char *)(uVar4 * 0x13)),
                    (char *)CONCAT22(0x17f8,(char *)(uVar4 * 0x13 + 0x13)),
                    ((SquareRecCount - uVar4) + -1) * 0x13);
        }
        SquareRecCount = SquareRecCount - 1;
        iVar3 = memcmp((char *)&SquareRecX,(char *)CONCAT22(unaff_SS,&rec),0x13);
        if (iVar3 == 0) {
          return;
        }
      }
      else {
        iVar3 = memcmp((char *)&SquareRecX,(char *)CONCAT22(unaff_SS,&rec),0x13);
        if (iVar3 == 0) {
          return;
        }
        if (299 < SquareRecCount) {
          _fmemmove((char *)SquareRecs,(char *)(SquareRecs + 1),0x1631);
          SquareRecCount = 299;
        }
      }
      iStack_14 = y;
      _rec = uVar1;
      memcpy((char *)CONCAT22(0x17f8,(char *)(SquareRecCount * 0x13)),
             (char *)CONCAT22(unaff_SS,&rec),0x13);
      SquareRecCount = SquareRecCount + 1;
      return;
    }
    uVar2 = ovr_alignUp4(unaff_DI,*(undefined2 *)(uVar4 * 0x13));
    if ((uVar2 == uVar1) && (*(int *)(uVar4 * 0x13 + 2) == y)) {
      memcpy((char *)CONCAT22(unaff_SS,&rec),(char *)CONCAT22(0x17f8,(char *)(uVar4 * 0x13)),0x13);
      goto L_unit_6616_10d5_1152;
    }
    uVar4 = uVar4 + 1;
  } while( true );
}



/* 6616:12ce */

/* [R6] touches Entities, targetX */

void __cdecl16far
unit_usesEntities(char state,int entityIndex,uint16_t unitFlags,uint16_t unitFlagsSeg)

{
  byte *pbVar1;
  uint16_t uVar2;
  entity_t *peVar3;
  uint16_t unaff_SI;
  undefined2 uVar4;
  
  pbVar1 = (byte *)((int)&((entity_t *)Entities)[entityIndex].base.flags32 + 1);
  *pbVar1 = *pbVar1 & 0xf8;
  if (state != '\x02') {
    uVar4 = (undefined2)((ulong)Entities >> 0x10);
    if (state == '\x03') {
      pbVar1 = (byte *)((int)&((entity_t *)Entities)[entityIndex].base.flags32 + 1);
      *pbVar1 = *pbVar1 | 1;
      ovr_attact_usesEntities(0,0,unitFlags,unitFlagsSeg,unaff_SI,entityIndex);
    }
    else if (state == '\x04') {
      pbVar1 = (byte *)((int)&((entity_t *)Entities)[entityIndex].base.flags32 + 1);
      *pbVar1 = *pbVar1 | 2;
      uVar4 = (undefined2)((ulong)Entities >> 0x10);
      peVar3 = (entity_t *)Entities;
      uVar2 = peVar3[entityIndex].base.y;
      peVar3[entityIndex].base.targetX = ((peVar3 + entityIndex)->base).x;
      ((entity_t *)Entities)[entityIndex].base.targetY = uVar2;
      pbVar1 = (byte *)((int)&((entity_t *)Entities)[entityIndex].base.flags32 + 1);
      *pbVar1 = *pbVar1 & 0xfa;
      ovr_attact_usesEntities(0,0,unitFlags,unitFlagsSeg,unaff_SI,entityIndex);
    }
  }
  return;
}


