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
  /* Re-derived: the building's value from BuildingTypes[..].word_0x12e, scaled by the
     placement quality (3 -> *3/2, 4 -> *2), plus 5 when the unit type's sheet byte +0x5d
     has bit 8 set. */
  byte unitType;
  uint32_t sheetRef;
  uint quality;
  unit_t *units;
  int value;

  units = GUnits;
  value = BuildingTypes[(uint)(units + unitIndex)->bldType].sight;
  quality = ovr_constr_usesGMapFlags2(units[unitIndex].x,units[unitIndex].y);
  if ((quality & 0xff) == 3) {
    value = value * 3 >> 1;
  }
  else if ((quality & 0xff) == 4) {
    value = value << 1;
  }
  unitType = (GUnits)[unitIndex].unitType;
  if ((unitType != 0xff) &&
     (sheetRef = *(uint32_t *)((uint)unitType << 2),
      (*(byte *)((int)sheetRef + 0x5d) & 8) != 0)) {
    value = value + 5;
  }
  return value;
}



/* 6616:00d8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

void __cdecl16far unit_usesAlignUp4(void)

{
  byte gunitType;
  uint32_t typePtr;
  uint agntIdx;
  uint alignedX;
  int entX;
  int halfExtent;
  int unitX;
  int extent;
  int rowBottom;
  int rowTop;
  int colRight;
  int colLeft;
  uint index;
  
  if (mapDirty != '\0') {
    mapDirty = '\0';
    ovr_driver_clearMapFlagsRect
              ((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),(short (*) [60] [148])GMapFlags),0,0,0x93,0x3b,0xfff7,0,0);
    for (index = 0; index < EntityCount; index = index + 1) {
      agntIdx = (uint)((entity_t far *)Entities)[index].base.gindex;
      if (AgntGs[alignedX].ai == '\0') {
        if (alignedX == 3) {
          extent = 0xf;
        }
        else if (alignedX == 0xb) {
          extent = 8;
        }
        else {
          extent = 5;
        }
        entX = *(int *)((entity_t far *)Entities + index);
        rowBottom = ((entity_t far *)Entities)[index].base.y;
        alignedX = ovr_alignUp4(entX + extent * -2,0,0);
        colLeft = alignedX - 2;
        alignedX = ovr_alignUp4(entX + extent * 2,0,0);
        colRight = alignedX + 1;
        if (colLeft < 0) {
          colLeft = 0;
        }
        if (0x93 < colRight) {
          colRight = 0x93;
        }
        rowTop = rowBottom - extent;
        rowBottom = rowBottom + extent;
        if (rowTop < 0) {
          rowTop = 0;
        }
        if (0x3b < rowBottom) {
          rowBottom = 0x3b;
        }
        ovr_driver_setMapFlagsRect
                  ((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),(short (*) [60] [148])GMapFlags),colLeft,
                   rowTop,colRight,rowBottom,8);
      }
    }
    for (index = 0xf8; index < GUnitCount; index = index + 1) {
      if (((BuildingTypes[(uint)(GUnits + index)->bldType].sight != 0) &&
          (gunitType = (GUnits)[index].unitType, gunitType != 0xff)) &&
         (typePtr = *(uint32_t *)((uint)gunitType << 2), *(char *)((int)typePtr + 0x3f) == '\0')) {
        halfExtent = unit_usesGUnits(index);
        unitX = (GUnits)[index].x;
        rowBottom = (GUnits)[index].y;
        alignedX = ovr_alignUp4(unitX + halfExtent * -2,0,0);
        colLeft = alignedX - 2;
        alignedX = ovr_alignUp4(unitX + halfExtent * 2,0,0);
        colRight = alignedX + 1;
        if (colLeft < 0) {
          colLeft = 0;
        }
        if (0x93 < colRight) {
          colRight = 0x93;
        }
        rowTop = rowBottom - halfExtent;
        rowBottom = rowBottom + halfExtent;
        if (rowTop < 0) {
          rowTop = 0;
        }
        if (0x3b < rowBottom) {
          rowBottom = 0x3b;
        }
        ovr_driver_setMapFlagsRect
                  ((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),(short (*) [60] [148])GMapFlags),colLeft,
                   rowTop,colRight,rowBottom,8);
      }
    }
  }
  return;
}



/* 6616:03bd */

/* [R4] calls ovr_biosKeyAvail */

uint __cdecl16far keyprocessor_usesBiosKeyAvail(uint16_t *cursorX,uint16_t *cursorY,uint8_t *input)

{
  uint key;
  uint coord;
  uint16_t keyCheck;
  
  ovr_ovc13_usesMiceBlitRect();
  key = ovr_biosKeyAvail();
  if ((char)key == '\0') goto L_keyprocessor_6616_03bd_0684;
  key = ovr_gameProcessKey();
  while (keyCheck = ovr_biosKeyAvail(), (char)keyCheck != '\0') {
    key = ovr_gameProcessKey();
  }
  if (key == 0x4900) {
L_keyprocessor_6616_03bd_059D:
    if ((int)*cursorY < 0x20) {
      coord = (*cursorY - 7) / 3;
      *cursorY = (*cursorY - 7) % 3 + 7;
    }
    else {
      *cursorY = *cursorY - 0x18;
    }
    goto L_keyprocessor_6616_03bd_0684;
  }
  if (0x4900 < key) {
    if (key == 0x4f00) {
L_keyprocessor_6616_03bd_0633:
      coord = *cursorX + 0x20;
      if ((int)coord < 0xde) {
        *cursorX = *cursorX + 0x20;
      }
      else {
        coord = 0xde - *cursorX & 7;
        *cursorX = 0xde - coord;
      }
    }
    else {
      if (key < 0x4f01) {
        if (key != 0x4b34) {
          if (0x4b34 < key) {
            if ((key == 0x4d00) || (key == 0x4d36)) {
              coord = *cursorX + 8;
              if ((int)coord < 0xde) {
                *cursorX = *cursorX + 8;
              }
              else {
                coord = 0xde - *cursorX & 7;
                *cursorX = 0xde - coord;
              }
              goto L_keyprocessor_6616_03bd_0684;
            }
            goto L_keyprocessor_6616_03bd_0680;
          }
          if (key == 0x4939) goto L_keyprocessor_6616_03bd_059D;
          if (key != 0x4b00) goto L_keyprocessor_6616_03bd_0680;
        }
        if ((int)*cursorX < 0x15) {
          coord = (*cursorX - 0xc & 7) + 0xc;
          *cursorX = coord;
        }
        else {
          *cursorX = *cursorX - 8;
        }
        goto L_keyprocessor_6616_03bd_0684;
      }
      if (key != 0x5032) {
        if (0x5032 < key) {
          if ((key == 0x5100) || (key == 0x5133)) {
            coord = *cursorY + 0x18;
            if ((int)coord < 0x96) {
              *cursorY = *cursorY + 0x18;
            }
            else {
              coord = 0x96 - (0x96 - *cursorY) % 3;
              *cursorY = coord;
            }
            goto L_keyprocessor_6616_03bd_0684;
          }
          goto L_keyprocessor_6616_03bd_0680;
        }
        if (key == 0x4f31) goto L_keyprocessor_6616_03bd_0633;
        if (key != 0x5000) goto L_keyprocessor_6616_03bd_0680;
      }
      coord = *cursorY + 3;
      if ((int)coord < 0x96) {
        *cursorY = *cursorY + 3;
      }
      else {
        coord = 0x96 - (0x96 - *cursorY) % 3;
        *cursorY = coord;
      }
    }
    goto L_keyprocessor_6616_03bd_0684;
  }
  if (key == 0x2348) {
L_keyprocessor_6616_03bd_066E:
    *input = 0x4;
  }
  else {
    if (key < 0x2349) {
      if (key != 0x1655) {
        if (key < 0x1656) {
          if ((key != 0x1352) && (key != 0x1372)) goto L_keyprocessor_6616_03bd_0680;
          *input = 0x3;
          goto L_keyprocessor_6616_03bd_0684;
        }
        if (key != 0x1675) {
          if (key != 0x1c0d) goto L_keyprocessor_6616_03bd_0680;
          *input = 0x1;
          goto L_keyprocessor_6616_03bd_0684;
        }
      }
      *input = 0x2;
      goto L_keyprocessor_6616_03bd_0684;
    }
    if (key != 0x4737) {
      if (0x4737 < key) {
        if ((key == 0x4800) || (key == 0x4838)) {
          if ((int)*cursorY < 0xb) {
            coord = (*cursorY - 7) / 3;
            *cursorY = (*cursorY - 7) % 3 + 7;
          }
          else {
            *cursorY = *cursorY - 3;
          }
          goto L_keyprocessor_6616_03bd_0684;
        }
L_keyprocessor_6616_03bd_0680:
        return CONCAT11((char)(key >> 8),1);
      }
      if (key == 0x2368) goto L_keyprocessor_6616_03bd_066E;
      if (key != 0x4700) goto L_keyprocessor_6616_03bd_0680;
    }
    if ((int)*cursorX < 0x2d) {
      coord = (*cursorX - 0xc & 7) + 0xc;
      *cursorX = coord;
    }
    else {
      *cursorX = *cursorX - 0x20;
    }
  }
L_keyprocessor_6616_03bd_0684:
  return key & 0xff00;
}



/* 6616:0689 */
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
  byte mouseStatus;
  char *textPtr;
  undefined1 extraout_AH;
  uint16_t keyAvail;       /* ovr_biosKeyAvail's result */
  uint16_t sheetEntry;   /* sheetByte record +0x107 */
  uint16_t keyPressed;   /* keyprocessor_usesBiosKeyAvail result */
  uint16_t entitiesSeg;  /* (uint16_t)((ulong)Entities >> 16) */
  uint16_t suffix;       /* ovr_ovc41_pluralSuffix result */
  undefined1 extraout_AH_00;
  byte *idxPtr;            /* (pbStack_20 - 9) / 3 + Seed_2000_d10e */
  uint16_t segTmp;         /* segment argument, 0x2410 at the first call */
  byte *namePtrB;          /* the same computation driven by rowPtr */
  byte *namePtr;           /* computed pointer into Seed_2000_d110 */
  uint16_t textSeg;
  int textWidth;   /* ovr_ovc45_compute9() result */
  uint entityIdx;
  uint16_t diArg;          /* the argument ovr_stshRleCut receives in DI */
  byte *rowPtr;            /* running pointer down the drawn rows */
  undefined1 sheetLo;      /* low byte of sheetEntry */
  undefined1 ptrLo;        /* low byte of rowPtr, passed to drawLine */
  bool type;
  static char text[64];   /* DGROUP-backed formatting buffer */
  static char msg[64];   /* DGROUP-backed formatting buffer */
  uint8_t unitFlags;
  byte sheetByte;
  byte partyIdx;
  uint8_t input;
  uint i;
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
  far_t far *pfStack_1a;
  uint16_t gfxSeg2;
  uint8_t saveArea;
  uint16_t frameSeg;        /* 0xa000, then the current graphic's segment */
  byte *pbStack_c;
  int matchCount;
  uint16_t gfxSeg;
  void *pvStack_6;
  uint16_t gfxSeg3;
  
  if (GOngoingBattle == '\0') {
    return;
  }
  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x2410);
  partyIdx = ((uint8_t *)MenuItemEnabled)[menuIndex];
  if (partyIdx == 0xff) {
    return;
  }
  sheetByte = *(byte *)((int)*(uint32_t *)((uint)partyIdx << 2) + 0x2f);
  if (sheetByte == 0xff) {
    return;
  }
  segTmp = 0x2410;
  sheetEntry = *(uint16_t *)((uint)sheetByte * 4 + 0x107);
  sheetLo = (undefined1)sheetEntry;
  textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x648f,_SS),
                         (char *)CONCAT13((char)((uint)sheetEntry >> 8),CONCAT12(sheetLo,0x2410)),sheetLo,
                         (char)*(uint16_t *)((uint)sheetByte * 4 + 0x109),
                         (char)*(uint16_t *)((uint)partyIdx * 4),
                         ((uint16_t *)((uint)partyIdx * 4))[1]);
  ovr_say(textPtr,segTmp);
  do {
    type = SUB21(_SS,0);
    sheetLo = (undefined1)((uint)_SS >> 8);
    mouseStatus = ovr_init2_usesCFGMice((uint16_t *)&mouseX,0,0);
  } while (CONCAT11(extraout_AH,mouseStatus) != 0);
  while (keyAvail = ovr_biosKeyAvail(), (char)keyAvail != '\0') {
    ovr_gameProcessKey();
  }
  memcpy((char *)CONCAT13(sheetLo,CONCAT12(type,&saveArea)),(char *)BlitRects,10);
  frameSeg = 0xa000;
  ovr_miceRestoreArea((brect_t *)&saveArea,0);
  pfStack_1a = ovr_stshRleCut((far_t far *)0x0,far_from_u32((uint32_t)(0xca000)),7,222,150,diArg,0xc,7,0xde);
  gfxSeg2 = segTmp;
  ovr_miceBlitRect((brect_t *)&saveArea,0);
  pvStack_6 = ovr_stshAlloc(0xfa0f);
  ptr.seg = segTmp;
  ptr.ofs = (uint16_t)pvStack_6;
  gfxSeg3 = segTmp;
  ovr_alignToSeg(ptr);
  pbStack_2a = mouseX;
  pbStack_2c = mouseY;
  cursorX = (uint8_t)((GfxRndSeed - Seed_2000_d110) * 2 + 7);   /* hand fix: cursorX is a uint8_t cursor coordinate, not a pointer */
  cursorY = (uint8_t)((GfxRndSeed2 - Seed_2000_d10e) * 3 + 8);   /* hand fix: cursorY is a uint8_t cursor coordinate, not a pointer */
  pbStack_32 = (byte *)0xffff;
  pbStack_34 = (byte *)0xffff;
  input = 0x0;
  rightButtonLatch = '\0';
  gfxSeg = segTmp;
  do {
    keyPressed = keyprocessor_usesBiosKeyAvail
                      ((uint16_t *)CONCAT22(_SS,&cursorX),
                       (uint16_t *)CONCAT13(sheetLo,CONCAT12(type,&cursorY)),
                       (uint8_t *)CONCAT22(_SS,&input));
    if ((char)keyPressed != '\0') goto L_ui_unit_order_6616_0689_1054;
    if ((cursorX != pbStack_32) || (cursorY != pbStack_34)) {
      pbStack_32 = cursorX;
      pbStack_1c = cursorX;
      pbStack_34 = cursorY;
      pbStack_1e = cursorY;
      frameSeg = gfxSeg;
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)gfxSeg2;
      gfx_00.ofs = (uint16_t)pfStack_1a;
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)(gfxSeg2 >> 8);
      dst.seg = gfxSeg;
      dst.ofs = 0x8cc;
      ovr_blitLoadRleGfx(gfx_00,dst,0xcc);
      gfx.seg = MiceCursors[3].seg;
      gfx.ofs = MiceCursors[3].ofs;
      ovr_blitGfx10(gfx,(uint16_t)(cursorX + -6),(uint16_t)(cursorY + -5),(brect_t *)&saveArea,
                    type,(char)(cursorY + -5),(char)(brect_t *)&saveArea);
      ovr_miceBlitRect((brect_t *)&saveArea,0);
      ovr_blitRect((brect_t *)&saveArea,0);
      ovr_miceUpdate();
    }
    if (input == 0x0) {
      input = ovr_init2_usesCFGMice((uint16_t *)&mouseX,0,0);
    }
    if (rightButtonLatch != '\0') goto L_ui_unit_order_6616_0689_1054;
    if ((mouseX != pbStack_2a) || (mouseY != pbStack_2c)) {
      pbStack_2a = mouseX;
      pbStack_1c = mouseX;
      pbStack_2c = mouseY;
      pbStack_1e = mouseY;
    }
  } while (input == 0x0);
  if ((((0xb < (int)pbStack_1c) && ((int)pbStack_1c < 0xdf)) && (6 < (int)pbStack_1e)) &&
     ((int)pbStack_1e < 0x97)) {
    do {
      mouseStatus = ovr_init2_usesCFGMice((uint16_t *)&mouseX,0,0);
    } while (CONCAT11(extraout_AH_00,mouseStatus) != 0);
    pbStack_26 = (byte *)0xffff;
    pbStack_28 = (byte *)0xffff;
    pbStack_20 = pbStack_1e;
    input = 0x0;
    rowPtr = pbStack_1c;
    do {
      keyPressed = keyprocessor_usesBiosKeyAvail
                        ((uint16_t *)CONCAT22(_SS,&cursorX),
                         (uint16_t *)CONCAT13(sheetLo,CONCAT12(type,&cursorY)),
                         (uint8_t *)CONCAT22(_SS,&input));
      if ((char)keyPressed != '\0') goto L_ui_unit_order_6616_0689_1054;
      if ((cursorX != pbStack_32) || (cursorY != pbStack_34)) {
        pbStack_32 = cursorX;
        pbStack_34 = cursorY;
        pbStack_20 = cursorY;
        rowPtr = cursorX;
      }
      if ((int)rowPtr < 0xc) {
        rowPtr = (byte *)__C0_ASM_CopyRight + 8;
      }
      if (0xde < (int)rowPtr) {
        rowPtr = (byte *)0xde;
      }
      if ((int)pbStack_20 < 7) {
        pbStack_20 = (byte *)__C0_ASM_CopyRight + 3;
      }
      if (0x96 < (int)pbStack_20) {
        pbStack_20 = (byte *)((char *)0x96);
      }
      if ((pbStack_26 != rowPtr) || (pbStack_28 != pbStack_20)) {
        frameSeg = gfxSeg;
        (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = (char)gfxSeg2;
        gfx_01.ofs = (uint16_t)pfStack_1a;
        (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = (char)(gfxSeg2 >> 8);
        dst_00.seg = gfxSeg;
        dst_00.ofs = 0x8cc;
        ovr_blitLoadRleGfx(gfx_01,dst_00,0xcc);
        ptrLo = SUB21(rowPtr,0);
        ovr_driver_drawLine(pbStack_1c,(int)pbStack_1e,rowPtr,(int)pbStack_1e,0xff,ptrLo,
                            (char)pbStack_1e,0xff,gfxSeg);
        ovr_driver_drawLine(pbStack_1c,(int)pbStack_1e,pbStack_1c,(int)pbStack_20,0xff,
                            (char)pbStack_1c,(char)pbStack_20,0xff,gfxSeg);
        ovr_driver_drawLine(rowPtr,(int)pbStack_1e,rowPtr,(int)pbStack_20,0xff,ptrLo,
                            (char)pbStack_20,0xff,gfxSeg);
        ovr_driver_drawLine(pbStack_1c,(int)pbStack_20,rowPtr,(int)pbStack_20,0xff,ptrLo,
                            (char)pbStack_20,0xff,gfxSeg);
        ovr_miceBlitRect((brect_t *)&saveArea,0);
        ovr_blitRect((brect_t *)&saveArea,0);
        ovr_miceUpdate();
        idxPtr = (byte *)((int)(pbStack_20 + -9) / 3 + Seed_2000_d10e);
        namePtrB = (byte *)(Seed_2000_d110 + ((uint)(rowPtr + -0xc) >> 1) + 2 & 0xfffc);
        pbStack_24 = (byte *)((int)(pbStack_1e + -9) / 3 + Seed_2000_d10e);
        pbStack_22 = (byte *)(Seed_2000_d110 + ((uint)(pbStack_1c + -0xc) >> 1) + 2 & 0xfffc);
        pbStack_26 = namePtrB;
        if ((int)namePtrB < (int)pbStack_22) {
          pbStack_26 = pbStack_22;
          pbStack_22 = namePtrB;
          pbStack_c = namePtrB;
        }
        pbStack_28 = idxPtr;
        if ((int)idxPtr < (int)pbStack_24) {
          pbStack_28 = pbStack_24;
          pbStack_24 = idxPtr;
          pbStack_c = idxPtr;
        }
        matchCount = 0;
        for (entityIdx = 0; entityIdx < EntityCount; entityIdx = entityIdx + 1) {
          entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
          if ((((AGNT_FIELD(&(Entities)[entityIdx], base.entity, 3) == partyIdx) &&
               (pbStack_22 <= (byte *)*(uint *)((entity_t far *)Entities + entityIdx))) &&
              ((byte *)*(uint *)((entity_t far *)Entities + entityIdx) <= pbStack_26)) &&
             ((pbStack_24 <= (byte *)((entity_t far *)Entities)[entityIdx].base.y &&
              ((byte *)((entity_t far *)Entities)[entityIdx].base.y <= pbStack_28)))) {
            matchCount = matchCount + 1;
          }
        }
        ovr_resetTextBlitCycle();
        ptrLo = 0x7a;
        textWidth = ovr_ovc45_compute9(text,
                                    (char *)CONCAT22(*(uint16_t *)((uint)partyIdx * 4),_SS),
                                    (char *)CONCAT22(Font03.ofs,
                                                     (char *)((uint16_t *)((uint)partyIdx * 4))
                                                             [1]),Font03.seg,'C',(char)Font03.seg,
                                    0x43,3,0xa000);
        suffix = ovr_ovc41_pluralSuffix(matchCount,(char)textWidth,ptrLo);
        segTmp = 0x2410;
        textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x64b8,_SS),
                               (char *)CONCAT22(matchCount,(char *)0x2410),
                               *(uint16_t *)((uint)sheetByte * 4 + 0x13f),
                               *(uint16_t *)((uint)sheetByte * 4 + 0x141),suffix,ptrLo);
        ovr_uiNotify(textPtr,segTmp,(char)segTmp);
      }
      pbStack_28 = pbStack_20;
      pbStack_26 = rowPtr;
      if (input == 0x0) {
        input = ovr_init2_usesCFGMice((uint16_t *)&mouseX,0,0);
      }
      if (rightButtonLatch != '\0') goto L_ui_unit_order_6616_0689_1054;
      if ((mouseX != pbStack_2a) || (mouseY != pbStack_2c)) {
        pbStack_2a = mouseX;
        pbStack_2c = mouseY;
        pbStack_20 = mouseY;
        rowPtr = mouseX;
      }
    } while (input == 0x0);
    ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
    if ((((0xb < (int)rowPtr) && ((int)rowPtr < 0xdf)) && (6 < (int)pbStack_20)) &&
       ((int)pbStack_20 < 0x97)) {
      idxPtr = (byte *)((int)(pbStack_20 + -9) / 3 + Seed_2000_d10e);
      namePtrB = (byte *)(Seed_2000_d110 + ((uint)(rowPtr + -0xc) >> 1) + 2 & 0xfffc);
      rowPtr = (byte *)((int)(pbStack_1e + -9) / 3 + Seed_2000_d10e);
      namePtr = (byte *)(Seed_2000_d110 + ((uint)(pbStack_1c + -0xc) >> 1) + 2 & 0xfffc);
      pbStack_26 = namePtrB;
      pbStack_22 = namePtr;
      if ((int)namePtrB < (int)namePtr) {
        pbStack_26 = namePtr;
        pbStack_22 = namePtrB;
        pbStack_c = namePtr;
      }
      pbStack_28 = idxPtr;
      pbStack_24 = rowPtr;
      if ((int)idxPtr < (int)rowPtr) {
        pbStack_28 = rowPtr;
        pbStack_24 = idxPtr;
        pbStack_c = rowPtr;
      }
      _fmemset(MK_FP(_SS, &unitFlags), 0, 5);
      matchCount = 0;
      for (entityIdx = 0; entityIdx < EntityCount; entityIdx = entityIdx + 1) {
        namePtr = (byte *)((char *)0x2410);
        entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
        if (((AGNT_FIELD(&(Entities)[entityIdx], base.entity, 3) == partyIdx) &&
            (namePtr = (byte *)((char *)0x2410),
            pbStack_22 <= (byte *)*(uint *)((entity_t far *)Entities + entityIdx))) &&
           ((namePtr = (byte *)((char *)0x2410),
            (byte *)*(uint *)((entity_t far *)Entities + entityIdx) <= pbStack_26 &&
            ((namePtr = (byte *)((char *)0x2410),
             pbStack_24 <= (byte *)((entity_t far *)Entities)[entityIdx].base.y &&
             (namePtr = (byte *)((char *)0x2410),
             (byte *)((entity_t far *)Entities)[entityIdx].base.y <= pbStack_28)))))) {
          if (input < 2) {
            namePtr = (byte *)((char *)0x2410);
            unit_usesAlignUp42(menuIndex,*(uint16_t *)((entity_t far *)Entities + entityIdx),
                               ((entity_t far *)Entities)[entityIdx].base.y);
          }
          else {
            unit_usesEntities(input,entityIdx,(uint16_t)&unitFlags,(uint16_t)_SS);
          }
          matchCount = matchCount + 1;
        }
      }
      for (i = 0; (int)i < 5; i = i + 1) {
        if ((&unitFlags)[i] != 0x0) {
          ovr_ovc41_usesMiceBlitRect(i);
        }
      }
      ovr_constr_flushDirtyRects();
      ovr_resetTextBlitCycle();
      if (input == 0x1) {
        suffix = ovr_ovc41_pluralSuffix(matchCount);
        textSeg = _DS;
        textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x6522,_SS),
                               (char *)CONCAT22(matchCount,(char *)0x2410),
                               (char)*(uint16_t *)((uint)sheetByte * 4 + 0x13f),
                               (char)*(uint16_t *)((uint)sheetByte * 4 + 0x141),(char)suffix,namePtr
                              );
        ovr_say(textPtr,textSeg);
      }
      else if (input == 0x2) {
        suffix = ovr_ovc41_pluralSuffix(matchCount);
        textSeg = _DS;
        textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x6543,_SS),
                               (char *)CONCAT22(matchCount,(char *)0x2410),
                               (char)*(uint16_t *)((uint)sheetByte * 4 + 0x13f),
                               (char)*(uint16_t *)((uint)sheetByte * 4 + 0x141),(char)suffix,namePtr
                              );
        ovr_say(textPtr,textSeg);
      }
      else if (input == 0x3) {
        suffix = ovr_ovc41_pluralSuffix(matchCount);
        textSeg = _DS;
        textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x6557,_SS),
                               (char *)CONCAT22(matchCount,(char *)0x2410),
                               (char)*(uint16_t *)((uint)sheetByte * 4 + 0x13f),
                               (char)*(uint16_t *)((uint)sheetByte * 4 + 0x141),(char)suffix,namePtr
                              );
        ovr_say(textPtr,textSeg);
      }
      else if (input == 0x4) {
        suffix = ovr_ovc41_pluralSuffix(matchCount);
        textSeg = _DS;
        textPtr = ovr_stsprintf(msg,(char *)CONCAT22(0x6568,_SS),
                               (char *)CONCAT22(matchCount,(char *)0x2410),
                               (char)*(uint16_t *)((uint)sheetByte * 4 + 0x13f),
                               (char)*(uint16_t *)((uint)sheetByte * 4 + 0x141),(char)suffix,namePtr
                              );
        ovr_say(textPtr,textSeg);
      }
      ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
      goto L_ui_unit_order_6616_0689_106E;
    }
  }
L_ui_unit_order_6616_0689_1054:
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
  ovr_say((char *)"Region selection aborted.",0x2410);
L_ui_unit_order_6616_0689_106E:
  frameSeg = gfxSeg;
  (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)gfxSeg2;
  gfx_02.ofs = (uint16_t)pfStack_1a;
  (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = (char)(gfxSeg2 >> 8);
  dst_01.seg = gfxSeg;
  dst_01.ofs = 0x8cc;
  ovr_blitLoadRleGfx(gfx_02,dst_01,0xcc);
  ovr_miceBlitRect((brect_t *)&saveArea,0);
  ovr_blitRect((brect_t *)&saveArea,0);
  ovr_miceUpdate();
  handle.seg = gfxSeg2;
  handle.ofs = (uint16_t)pfStack_1a;
  ovr_stshFree(handle);
  handle_00.seg = gfxSeg3;
  handle_00.ofs = (uint16_t)pvStack_6;
  ovr_stshFree(handle_00);
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
  return;
}


/* 6616:10d5 */

/* [R4] calls ovr_alignUp4 */

void __cdecl16far unit_usesAlignUp42(byte menuIndex,uint16_t x,int y)

{
  uint alignedX;
  uint recAlignedX;
  int16_t cmpResult;
  uint recIdx;
  uint8_t rec;
  int recY;
  uint8_t savedCursorX;
  uint8_t savedCursorY;
  
  alignedX = ovr_alignUp4(x,0,0);
  recIdx = 0;
  do {
    if (SquareRecCount <= recIdx) {
L_unit_6616_10d5_1152:
      if (SquareRecCount <= recIdx) {
        _fmemmove((char far *)MK_FP(_SS,&rec),(char *)&SquareRecX,0x13);
      }
      rec = GfxRndSeed;
      recY = GfxRndSeed2;
      (&savedCursorX)[menuIndex] = ((undefined *)&menuCursorX)[menuIndex];
      (&savedCursorY)[menuIndex] = ((undefined *)&menuCursorY)[menuIndex];
      if (recIdx < SquareRecCount) {
        if (recIdx + 1 < SquareRecCount) {
          _fmemmove((char *)CONCAT22(0x17f8,(char *)(recIdx * 0x13)),
                    (char *)CONCAT22(0x17f8,(char *)(recIdx * 0x13 + 0x13)),
                    ((SquareRecCount - recIdx) + -1) * 0x13);
        }
        SquareRecCount = SquareRecCount - 1;
        cmpResult = memcmp((char *)&SquareRecX,(char *)CONCAT22(_SS,&rec),0x13);
        if (cmpResult == 0) {
          return;
        }
      }
      else {
        cmpResult = memcmp((char *)&SquareRecX,(char *)CONCAT22(_SS,&rec),0x13);
        if (cmpResult == 0) {
          return;
        }
        if (299 < SquareRecCount) {
          _fmemmove((char far *)SquareRecs,(char *)(SquareRecs + 1),0x1631);
          SquareRecCount = 299;
        }
      }
      recY = y;
      rec = alignedX;
      _fmemmove((char far *)MK_FP(0x17f8,(char *)(SquareRecCount * 0x13)),
             (char far *)MK_FP(_SS,&rec),0x13);
      SquareRecCount = SquareRecCount + 1;
      return;
    }
    recAlignedX = ovr_alignUp4(*(int *)(recIdx * 0x13),0,0);
    if ((recAlignedX == alignedX) && (*(int *)((uint8_t *)&SquareRecs[recIdx] + 2) == y)) {
      _fmemmove((char far *)MK_FP(_SS,&rec),(char far *)MK_FP(0x17f8,(char *)(recIdx * 0x13)),0x13);
      goto L_unit_6616_10d5_1152;
    }
    recIdx = recIdx + 1;
  } while( true );
}



/* 6616:12ce */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities, targetX */

void __cdecl16far
unit_usesEntities(char state,int entityIndex,uint16_t unitFlags,uint16_t unitFlagsSeg)

{
  /* Re-derived: clears the low three bits of the entity's +0x33 flags byte, then for state 3 sets
     bit 0 and for state 4 sets bit 1, copies the entity's x/y into targetX/targetY and clears bit
     2; both then hand off to attact_usesEntities.  State 2 does nothing beyond the clear.  The
     exported uVar3/uVar4 segment halves were dead. */
  byte *flagsPtr;
  uint16_t entY;

  flagsPtr = (byte *)((uint8_t *)&(Entities)[entityIndex] + 0x33);
  *flagsPtr = *flagsPtr & 0xf8;
  if (state != '\x02') {
    if (state == '\x03') {
      flagsPtr = (byte *)((uint8_t *)&(Entities)[entityIndex] + 0x33);
      *flagsPtr = *flagsPtr | 1;
      ovr_attact_usesEntities(entityIndex,0,0,unitFlags,unitFlagsSeg,0,0,0,0);
    }
    else if (state == '\x04') {
      flagsPtr = (byte *)((uint8_t *)&(Entities)[entityIndex] + 0x33);
      *flagsPtr = *flagsPtr | 2;
      entY = (Entities)[entityIndex].base.y;
      (Entities)[entityIndex].base.targetX =
          (Entities)[entityIndex].base.x;
      (Entities)[entityIndex].base.targetY = entY;
      flagsPtr = (byte *)((uint8_t *)&(Entities)[entityIndex] + 0x33);
      *flagsPtr = *flagsPtr & 0xfa;
      ovr_attact_usesEntities(entityIndex,0,0,unitFlags,unitFlagsSeg,0,0,0,0);
    }
  }
  return;
}


