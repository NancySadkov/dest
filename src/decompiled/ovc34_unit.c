/*
 * ovc34_unit.c - recovered from STRONG.EXE
 * memory block: OVC34_unit.c
 * range: 6616:0000 - 6616:155f
 * functions: 6
 */
#include "recovered.h"


/* 6616:0000 */

/* [R6] touches GUnits, bldType */

int __cdecl16far unit_usesGUnits(int unitIndex)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  unit_t *puVar4;
  int iVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)GUnits >> 0x10);
  puVar4 = (unit_t *)GUnits;
  iVar5 = *(int *)((uint)(puVar4 + unitIndex)->bldType * 0x27 + 0x12e);
  uVar3 = ovr_constr_usesGMapFlags2(puVar4[unitIndex].x,puVar4[unitIndex].y);
  if ((uVar3 & 0xff) == 3) {
    iVar5 = iVar5 * 3 >> 1;
  }
  else if ((uVar3 & 0xff) == 4) {
    iVar5 = iVar5 << 1;
  }
  bVar1 = ((unit_t *)GUnits)[unitIndex].unitType;
  if ((bVar1 != 0xff) &&
     (uVar2 = *(undefined4 *)((uint)bVar1 << 2), (*(byte *)((int)uVar2 + 0x5d) & 8) != 0)) {
    iVar5 = iVar5 + 5;
  }
  return iVar5;
}



/* 6616:00d8 */

/* [R4] calls ovr_alignUp4 */

void __cdecl16far unit_usesAlignUp4(void)

{
  byte bVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  entity_t *peVar8;
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
              ((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),(short (*) [60] [148])GMapFlags),0,0,0x93,0x3b,
               0xfff7);
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
        uVar6 = ovr_alignUp4(uVar2 + iStack_16 * -2);
        iStack_e = uVar6 - 2;
        uVar6 = ovr_alignUp4(uVar2 + iStack_16 * 2);
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
                  ((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),(short (*) [60] [148])GMapFlags),iStack_e,
                   iStack_12,iStack_10,iStack_14,8);
      }
    }
    for (uStack_c = 0xf8; uStack_c < GUnitCount; uStack_c = uStack_c + 1) {
      uVar9 = (undefined2)((ulong)GUnits >> 0x10);
      if (((*(int *)((uint)((unit_t *)GUnits + uStack_c)->bldType * 0x27 + 0x12e) != 0) &&
          (bVar1 = ((unit_t *)GUnits)[uStack_c].unitType, bVar1 != 0xff)) &&
         (uVar5 = *(undefined4 *)((uint)bVar1 << 2), *(char *)((int)uVar5 + 0x3f) == '\0')) {
        iVar7 = unit_usesGUnits(uStack_c);
        uVar9 = (undefined2)((ulong)GUnits >> 0x10);
        iVar4 = ((unit_t *)GUnits)[uStack_c].x;
        iStack_14 = ((unit_t *)GUnits)[uStack_c].y;
        uVar6 = ovr_alignUp4(iVar4 + iVar7 * -2);
        iStack_e = uVar6 - 2;
        uVar6 = ovr_alignUp4(iVar4 + iVar7 * 2);
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
                  ((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),(short (*) [60] [148])GMapFlags),iStack_e,
                   iStack_12,iStack_10,iStack_14,8);
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

void __cdecl16far ui_textDefineRegionCommand(byte menuIndex)

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
  byte *pbVar5;
  uint16_t uVar6;
  byte *pbVar7;
  byte *pbVar8;
  entity_t *peVar9;
  uint uVar10;
  int16_t unaff_DI;
  byte *pbVar11;
  uint16_t *unaff_SS;
  undefined1 uVar12;
  undefined1 uVar13;
  uint8_t text;
  uint8_t msg;
  uint8_t unitFlags;
  char cStack_3d;
  byte bStack_3c;
  uint8_t input;
  uint uStack_3a;
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
  
  if (GOngoingBattle == '\0') {
    return;
  }
  ovr_miceBlitRect((brect_t *)(BlitRects + 1));
  bStack_3c = ((uint8_t *)MenuItemEnabled)[menuIndex];
  if (bStack_3c == 0xff) {
    return;
  }
  cStack_3d = *(char *)((int)*(undefined4 *)((uint)bStack_3c << 2) + 0x2f);
  if (cStack_3d == -1) {
    return;
  }
  uVar6 = 0x2410;
  pcVar2 = ovr_stsprintf((char *)&msg,(char *)unaff_SS,
                         (char *)"Define region to command %s loyal to %s.");
  ovr_say(pcVar2);
  do {
    uVar12 = SUB21(unaff_SS,0);
    uVar13 = (undefined1)((uint)unaff_SS >> 8);
    bVar1 = ovr_init2_usesCFGMice((uint16_t *)&mouseX,unaff_SS);
  } while (CONCAT11(extraout_AH,bVar1) != 0);
  while (uVar3 = ovr_biosKeyAvail(), (char)uVar3 != '\0') {
    ovr_gameProcessKey();
  }
  memcpy((char *)CONCAT13(uVar13,CONCAT12(uVar12,&saveArea)),(char *)BlitRects,10);
  uStack_e = 0xa000;
  ovr_miceRestoreArea((brect_t *)&saveArea);
  pfStack_1a = ovr_stshRleCut((far_t *)0x0,far_from_u32((uint32_t)(0xca000)),7,222,150,unaff_DI);
  uStack_18 = uVar6;
  ovr_miceBlitRect((brect_t *)&saveArea);
  pvStack_6 = ovr_stshAlloc(0xfa0f);
  (*(uint8_t *)((uint8_t *)&(ptr.seg))) = (char)uVar6;
  ptr.ofs = (uint16_t)pvStack_6;
  (*(uint8_t *)((uint8_t *)&(ptr.seg) + 1)) = (char)(uVar6 >> 8);
  uStack_4 = uVar6;
  ovr_alignToSeg(ptr);
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
                       (uint16_t *)CONCAT13(uVar13,CONCAT12(uVar12,&cursorY)),
                       (uint8_t *)CONCAT13(uVar13,CONCAT12(uVar12,&input)));
    if ((char)uVar4 != '\0') goto L_ui_unit_order_6616_0689_1054;
    if ((_cursorX != pbStack_32) || (_cursorY != pbStack_34)) {
      pbStack_32 = _cursorX;
      pbStack_1c = _cursorX;
      pbStack_34 = _cursorY;
      pbStack_1e = _cursorY;
      uStack_e = uStack_8;
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)uStack_18;
      gfx_00.ofs = (uint16_t)pfStack_1a;
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)(uStack_18 >> 8);
      (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)uStack_8;
      dst.ofs = 0x8cc;
      (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)(uStack_8 >> 8);
      ovr_blitLoadRleGfx(gfx_00,dst);
      gfx.seg = MiceCursors[3].seg;
      gfx.ofs = MiceCursors[3].ofs;
      ovr_blitGfx10(gfx,(uint16_t)(_cursorX + -6),(uint16_t)(_cursorY + -5),
                    (brect_t *)CONCAT13(uVar13,CONCAT12(uVar12,&saveArea)),false);
      ovr_miceBlitRect((brect_t *)&saveArea);
      ovr_blitRect((brect_t *)&saveArea);
      ovr_miceUpdate();
    }
    if (input == 0x0) {
      input = ovr_init2_usesCFGMice((uint16_t *)&mouseX,unaff_SS);
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
      bVar1 = ovr_init2_usesCFGMice((uint16_t *)&mouseX,unaff_SS);
    } while (CONCAT11(extraout_AH_00,bVar1) != 0);
    pbStack_26 = (byte *)0xffff;
    pbStack_28 = (byte *)0xffff;
    pbStack_20 = pbStack_1e;
    input = 0x0;
    pbVar11 = pbStack_1c;
    do {
      uVar4 = keyprocessor_usesBiosKeyAvail
                        ((uint16_t *)CONCAT22(unaff_SS,&cursorX),
                         (uint16_t *)CONCAT13(uVar13,CONCAT12(uVar12,&cursorY)),
                         (uint8_t *)CONCAT13(uVar13,CONCAT12(uVar12,&input)));
      if ((char)uVar4 != '\0') goto L_ui_unit_order_6616_0689_1054;
      if ((_cursorX != pbStack_32) || (_cursorY != pbStack_34)) {
        pbStack_32 = _cursorX;
        pbStack_34 = _cursorY;
        pbStack_20 = _cursorY;
        pbVar11 = _cursorX;
      }
      if ((int)pbVar11 < 0xc) {
        pbVar11 = (byte *)__C0_ASM_CopyRight + 8;
      }
      if (0xde < (int)pbVar11) {
        pbVar11 = (byte *)0xde;
      }
      if ((int)pbStack_20 < 7) {
        pbStack_20 = (byte *)__C0_ASM_CopyRight + 3;
      }
      if (0x96 < (int)pbStack_20) {
        pbStack_20 = (byte *)((char *)"%d \r" + 1);
      }
      if ((pbStack_26 != pbVar11) || (pbStack_28 != pbStack_20)) {
        uStack_e = uStack_8;
        (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = (char)uStack_18;
        gfx_01.ofs = (uint16_t)pfStack_1a;
        (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = (char)(uStack_18 >> 8);
        (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = (char)uStack_8;
        dst_00.ofs = 0x8cc;
        (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = (char)(uStack_8 >> 8);
        ovr_blitLoadRleGfx(gfx_01,dst_00);
        ovr_driver_drawLine(pbStack_1c,(int)pbStack_1e,pbVar11,(int)pbStack_1e,0xff);
        ovr_driver_drawLine(pbStack_1c,(int)pbStack_1e,pbStack_1c,(int)pbStack_20,0xff);
        ovr_driver_drawLine(pbVar11,(int)pbStack_1e,pbVar11,(int)pbStack_20,0xff);
        ovr_driver_drawLine(pbStack_1c,(int)pbStack_20,pbVar11,(int)pbStack_20,0xff);
        ovr_miceBlitRect((brect_t *)&saveArea);
        ovr_blitRect((brect_t *)&saveArea);
        ovr_miceUpdate();
        pbVar5 = (byte *)((int)(pbStack_20 + -9) / 3 + Seed_2000_d10e);
        pbVar7 = (byte *)(Seed_2000_d110 + ((uint)(pbVar11 + -0xc) >> 1) + 2 & 0xfffc);
        pbStack_24 = (byte *)((int)(pbStack_1e + -9) / 3 + Seed_2000_d10e);
        pbStack_22 = (byte *)(Seed_2000_d110 + ((uint)(pbStack_1c + -0xc) >> 1) + 2 & 0xfffc);
        pbStack_26 = pbVar7;
        if ((int)pbVar7 < (int)pbStack_22) {
          pbStack_26 = pbStack_22;
          pbStack_22 = pbVar7;
          pbStack_c = pbVar7;
        }
        pbStack_28 = pbVar5;
        if ((int)pbVar5 < (int)pbStack_24) {
          pbStack_28 = pbStack_24;
          pbStack_24 = pbVar5;
          pbStack_c = pbVar5;
        }
        iStack_a = 0;
        for (uVar10 = 0; uVar10 < EntityCount; uVar10 = uVar10 + 1) {
          uVar4 = (undefined2)((ulong)Entities >> 0x10);
          peVar9 = (entity_t *)Entities;
          if ((((*(byte *)((int)&peVar9[uVar10].base.entity + 3) == bStack_3c) &&
               (pbStack_22 <= (byte *)((peVar9 + uVar10)->base).x)) &&
              ((byte *)((peVar9 + uVar10)->base).x <= pbStack_26)) &&
             ((pbStack_24 <= (byte *)peVar9[uVar10].base.y &&
              ((byte *)peVar9[uVar10].base.y <= pbStack_28)))) {
            iStack_a = iStack_a + 1;
          }
        }
        ovr_resetTextBlitCycle();
        ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text),
                           (char *)CONCAT22(((undefined2 *)((uint)bStack_3c * 4))[1],
                                            (char *)*(undefined2 *)((uint)bStack_3c * 4)),
                           (char *)CONCAT13((char)(Font03.seg >> 8),
                                            CONCAT12((char)Font03.seg,Font03.ofs)),0x43,'\x03');
        ovr_ovc41_pluralSuffix(iStack_a);
        uVar6 = 0x2410;
        pcVar2 = ovr_stsprintf((char *)&msg,(char *)unaff_SS,
                               (char *)
                               "%d %s%s loyal to %s found. Left click: set triangles. R: ready. U: unassign. H: home. Right click: abort."
                              );
        ovr_uiNotify(pcVar2,uVar6);
      }
      pbStack_28 = pbStack_20;
      pbStack_26 = pbVar11;
      if (input == 0x0) {
        input = ovr_init2_usesCFGMice((uint16_t *)&mouseX,unaff_SS);
      }
      if (rightButtonLatch != '\0') goto L_ui_unit_order_6616_0689_1054;
      if ((_mouseX != pbStack_2a) || (_mouseY != pbStack_2c)) {
        pbStack_2a = _mouseX;
        pbStack_2c = _mouseY;
        pbStack_20 = _mouseY;
        pbVar11 = _mouseX;
      }
    } while (input == 0x0);
    ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
    if ((((0xb < (int)pbVar11) && ((int)pbVar11 < 0xdf)) && (6 < (int)pbStack_20)) &&
       ((int)pbStack_20 < 0x97)) {
      pbVar5 = (byte *)((int)(pbStack_20 + -9) / 3 + Seed_2000_d10e);
      pbVar7 = (byte *)(Seed_2000_d110 + ((uint)(pbVar11 + -0xc) >> 1) + 2 & 0xfffc);
      pbVar11 = (byte *)((int)(pbStack_1e + -9) / 3 + Seed_2000_d10e);
      pbVar8 = (byte *)(Seed_2000_d110 + ((uint)(pbStack_1c + -0xc) >> 1) + 2 & 0xfffc);
      pbStack_26 = pbVar7;
      pbStack_22 = pbVar8;
      if ((int)pbVar7 < (int)pbVar8) {
        pbStack_26 = pbVar8;
        pbStack_22 = pbVar7;
        pbStack_c = pbVar8;
      }
      pbStack_28 = pbVar5;
      pbStack_24 = pbVar11;
      if ((int)pbVar5 < (int)pbVar11) {
        pbStack_28 = pbVar11;
        pbStack_24 = pbVar5;
        pbStack_c = pbVar11;
      }
      _fmemset(&unitFlags,(uint16_t)unaff_SS,0);
      iStack_a = 0;
      for (uVar10 = 0; uVar10 < EntityCount; uVar10 = uVar10 + 1) {
        uVar4 = (undefined2)((ulong)Entities >> 0x10);
        peVar9 = (entity_t *)Entities;
        if (((*(byte *)((int)&peVar9[uVar10].base.entity + 3) == bStack_3c) &&
            (pbStack_22 <= (byte *)((peVar9 + uVar10)->base).x)) &&
           (((byte *)((peVar9 + uVar10)->base).x <= pbStack_26 &&
            ((pbStack_24 <= (byte *)peVar9[uVar10].base.y &&
             ((byte *)peVar9[uVar10].base.y <= pbStack_28)))))) {
          if (input < 2) {
            unit_usesAlignUp42(menuIndex,((peVar9 + uVar10)->base).x,peVar9[uVar10].base.y);
          }
          else {
            unit_usesEntities(input,uVar10,(uint16_t)&unitFlags,(uint16_t)unaff_SS);
          }
          iStack_a = iStack_a + 1;
        }
      }
      for (uStack_3a = 0; (int)uStack_3a < 5; uStack_3a = uStack_3a + 1) {
        if ((&unitFlags)[uStack_3a] != 0x0) {
          ovr_ovc41_usesMiceBlitRect(uStack_3a);
        }
      }
      ovr_constr_flushDirtyRects();
      ovr_resetTextBlitCycle();
      if (input == 0x1) {
        ovr_ovc41_pluralSuffix(iStack_a);
        pcVar2 = ovr_stsprintf((char *)&msg,(char *)unaff_SS,
                               (char *)"Priorities adjusted for %d %s%s.");
        ovr_say(pcVar2);
      }
      else if (input == 0x2) {
        ovr_ovc41_pluralSuffix(iStack_a);
        pcVar2 = ovr_stsprintf((char *)&msg,(char *)unaff_SS,(char *)"%d %s%s unassigned.");
        ovr_say(pcVar2);
      }
      else if (input == 0x3) {
        ovr_ovc41_pluralSuffix(iStack_a);
        pcVar2 = ovr_stsprintf((char *)&msg,(char *)unaff_SS,(char *)"%d %s%s readied.");
        ovr_say(pcVar2);
      }
      else if (input == 0x4) {
        ovr_ovc41_pluralSuffix(iStack_a);
        pcVar2 = ovr_stsprintf((char *)&msg,(char *)unaff_SS,(char *)"%d %s%s homed.");
        ovr_say(pcVar2);
      }
      ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
      goto L_ui_unit_order_6616_0689_106E;
    }
  }
L_ui_unit_order_6616_0689_1054:
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
  ovr_say((char *)"Region selection aborted.");
L_ui_unit_order_6616_0689_106E:
  uStack_e = uStack_8;
  (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)uStack_18;
  gfx_02.ofs = (uint16_t)pfStack_1a;
  (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = (char)(uStack_18 >> 8);
  (*(uint8_t *)((uint8_t *)&(dst_01.seg))) = (char)uStack_8;
  dst_01.ofs = 0x8cc;
  (*(uint8_t *)((uint8_t *)&(dst_01.seg) + 1)) = (char)(uStack_8 >> 8);
  ovr_blitLoadRleGfx(gfx_02,dst_01);
  ovr_miceBlitRect((brect_t *)&saveArea);
  ovr_blitRect((brect_t *)&saveArea);
  ovr_miceUpdate();
  (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uStack_18;
  handle.ofs = (uint16_t)pfStack_1a;
  (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)(uStack_18 >> 8);
  ovr_stshFree(handle);
  (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)uStack_4;
  handle_00.ofs = (uint16_t)pvStack_6;
  (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)(uStack_4 >> 8);
  ovr_stshFree(handle_00);
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
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
  undefined2 unaff_SS;
  uint8_t rec;
  int iStack_14;
  uint8_t savedCursorX;
  uint8_t savedCursorY;
  
  uVar1 = ovr_alignUp4(x);
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
    uVar2 = ovr_alignUp4(*(int *)(uVar4 * 0x13));
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
  undefined2 uVar4;
  
  pbVar1 = (byte *)((int)&((entity_t *)Entities)[entityIndex].base.flags32 + 1);
  *pbVar1 = *pbVar1 & 0xf8;
  if (state != '\x02') {
    uVar4 = (undefined2)((ulong)Entities >> 0x10);
    if (state == '\x03') {
      pbVar1 = (byte *)((int)&((entity_t *)Entities)[entityIndex].base.flags32 + 1);
      *pbVar1 = *pbVar1 | 1;
      ovr_attact_usesEntities(entityIndex,0,0,unitFlags,unitFlagsSeg);
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
      ovr_attact_usesEntities(entityIndex,0,0,unitFlags,unitFlagsSeg);
    }
  }
  return;
}


