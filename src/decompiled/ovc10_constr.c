/*
 * ovc10_constr.c - recovered from STRONG.EXE
 * memory block: OVC10_constr.c
 * range: 36ce:0000 - 36ce:38cf
 * functions: 20
 */
#include "recovered.h"


/* 36ce:0000 */

/* Returns GMapCells at the drawing cursor offset by (dx,dy), or 0 outside the map. */

int __cdecl16far constr_getCellAtOffset(int dx,int dy)

{
  int iVar1;
  
  if ((((dx + GfxRndSeed < 0x94) && (SCARRY2(dx,GfxRndSeed) == dx + GfxRndSeed < 0)) &&
      (GfxRndSeed2 - dy < 0x3c)) && (dy <= GfxRndSeed2)) {
    iVar1 = (int)*(char *)((int)(byte (*) [59] [148])GMapCells +
                          GfxRndSeed + dx + (GfxRndSeed2 - dy) * 0x94);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 36ce:0080 */

/* Returns the map-flag byte at the cursor offset (dx,dy), or 3 outside the map. */

undefined2 __cdecl16far constr_getFlagsAtOffset(int dx,int dy)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = 0x2410;
  if ((((dx + GfxRndSeed < 0x94) && (iVar1 = 0x2410, SCARRY2(dx,GfxRndSeed) == dx + GfxRndSeed < 0))
      && (iVar1 = GfxRndSeed2 - dy, iVar1 < 0x3c)) && (iVar1 = GfxRndSeed2 - dy, dy <= GfxRndSeed2))
  {
    uVar2 = CONCAT11(0x24,*(undefined1 *)
                           ((int)(short (*) [60] [148])GMapFlags +
                           (dx + GfxRndSeed) * 2 + (GfxRndSeed2 - dy) * 0x128));
  }
  else {
    uVar2 = CONCAT11((char)((uint)iVar1 >> 8),3);
  }
  return uVar2;
}



/* 36ce:0101 */

/* [R6] touches SmoothPrev */

int __cdecl16far constr_usesSmoothPrev(uint16_t dx,int dy,int *cell,...)

{
  int iVar1;
  undefined2 in_stack_0000000a;
  
  iVar1 = constr_getCellAtOffset(dx,dy);
  *cell = iVar1;
  iVar1 = (*cell - SmoothPrev) * 3;
  if (iVar1 < 0) {
    iVar1 = (int)(iVar1 * (uint)*(byte *)(dy + 0x733)) / 0x10;
  }
  else {
    iVar1 = (int)(iVar1 * (uint)*(byte *)(dy + 0x733)) >> 4;
  }
  return iVar1;
}



/* 36ce:0159 */

/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* Stores the level of the unit at the cursor offset (dx,dy) into HighlightLevel and returns its
   type. */

byte __cdecl16far constr_setHighlightAtOffset(int dx,int dy,...)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  if ((((dx + GfxRndSeed < 0x94) && (SCARRY2(dx,GfxRndSeed) == dx + GfxRndSeed < 0)) &&
      (GfxRndSeed2 - dy < 0x3c)) && (dy <= GfxRndSeed2)) {
    uVar2 = (undefined2)((ulong)GUnitGrid >> 0x10);
    uVar3 = (undefined2)((ulong)GUnits >> 0x10);
    HighlightLevel =
         (uint)((unit_t *)GUnits)
               [*(int *)((int)(short (*) [148] [60])GUnitGrid +
                        (GfxRndSeed2 - dy) * 2 + (dx + GfxRndSeed) * 0x78)].level;
    bVar1 = ((unit_t *)GUnits +
            *(int *)((int)(short (*) [148] [60])GUnitGrid +
                    (GfxRndSeed2 - dy) * 2 + (dx + GfxRndSeed) * 0x78))->bldType;
  }
  else {
    bVar1 = 0;
  }
  return bVar1;
}



/* 36ce:023c */

/* [R6] touches SmoothPrev */

void __cdecl16far constr_usesSmoothPrev2(void)

{
  int iVar1;
  int iVar2;
  uint8_t cell;
  int iStack_4;
  
  SmoothPrev = 0;
  iVar1 = constr_usesSmoothPrev(0xffff,-1,(int *)&cell);
  iStack_4 = iVar1;
  iVar2 = constr_usesSmoothPrev(0,-1,(int *)&cell);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  if (iStack_4 < iVar2) {
    iStack_4 = iVar2;
  }
  iVar2 = constr_usesSmoothPrev(1,-1,(int *)&cell);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  if (iStack_4 < iVar2) {
    iStack_4 = iVar2;
  }
  iVar2 = constr_usesSmoothPrev(2,-1,(int *)&cell);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  iVar2 = constr_usesSmoothPrev(0xfffe,-1,(int *)&cell);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  if (0x5a < iStack_4 - iVar1) {
    iVar1 = iStack_4 + -0x5a;
  }
  SmoothPrev = iVar1 / 3;
  return;
}



/* 36ce:02f0 */

/* [R6] touches GOngoingBattle */

void __cdecl16far constr_usesGOngoingBattle(void)

{
  if (GOngoingBattle == '\0') {
    ovr_ovc13_usesBlitRects();
  }
  else {
    ovr_ovc13_usesAlignUp4();
  }
  ovr_attact_usesLDIV_at_2();
  return;
}



/* 36ce:0313 */

void __cdecl16far blitRect(brect_t *br,...)

{
  uint16_t pbr;
  undefined2 in_stack_00000006;
  
  ovr_blitRaw(br->x,br->y,br->w,br->h,br->seg,0xa000);
  return;
}



/* 36ce:0345 */

/* Restores the mouse area, blits a raw rect to the 0xa000 screen and blits the mouse back. */

void __cdecl16far constr_blitRawToScreen(brect_t *rect)

{
  uint16_t dstSeg;
  brect_t *br;
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)rect >> 0x10);
  br = (brect_t *)rect;
  dstSeg = br->seg;
  br->seg = 0xa000;
  ovr_miceRestoreArea(br,uVar1);
  ovr_blitRaw(rect->x,br->y,br->w,br->h,0xa000,dstSeg);
  ovr_miceBlitRect(br,uVar1);
  br->seg = dstSeg;
  return;
}



/* 36ce:03a6 */

/* [R4] calls blitRect */

void __cdecl16far constr_usesBlitRect(void)

{
  bool bVar1;
  void *pvVar2;
  uint16_t in_DX;
  far_t ptr;
  far_t handle;
  
  pvVar2 = ovr_stshAlloc(0xfa0f);
  ptr.seg = in_DX;
  ptr.ofs = (uint16_t)pvVar2;
  ovr_alignToSeg(ptr);
  if (GOngoingBattle != '\0') {
    ovr_miceRestoreArea((brect_t *)BlitRects);
    ovr_ovc13_usesAlignUp4();
    ovr_miceBlitRect((brect_t *)BlitRects);
    blitRect((brect_t *)BlitRects);
    ovr_miceUpdate();
    BlitRects[0].seg = 0xa000;
  }
  if (GOngoingBattle != '\0') {
    bVar1 = ovr_draw_textArena();
    if (bVar1) goto L_constr_36ce_03a6_0489;
  }
  ovr_miceRestoreArea((brect_t *)(BlitRects + 3));
  ovr_ovc13_usesBlitRects();
  ovr_miceBlitRect((brect_t *)(BlitRects + 3));
  blitRect((brect_t *)(BlitRects + 3));
  ovr_miceUpdate();
  BlitRects[3].seg = 0xa000;
L_constr_36ce_03a6_0489:
  handle.seg = in_DX;
  handle.ofs = (uint16_t)pvVar2;
  ovr_stshFree(handle);
  ovr_attact_usesLDIV_at_2();
  return;
}



/* 36ce:049f */

/* [R7] body shape: compute */

undefined2 __cdecl16far
constr_compute1(uint8_t cornerA,uint8_t cornerB,uint8_t cornerC,byte flags,byte bit,...)

{
  char cVar1;
  undefined2 in_AX;
  undefined2 uVar2;
  undefined1 extraout_AH;
  
  if ((flags & bit) == 0) {
    cVar1 = ovr_driver_compute1(cornerA,cornerB,cornerC);
    uVar2 = CONCAT11(extraout_AH,cVar1);
  }
  else {
    uVar2 = CONCAT11((char)((uint)in_AX >> 8),0xe2);
  }
  return uVar2;
}



/* 36ce:04c4 */

/* [R7] body shape: compute */

undefined2 __cdecl16far
constr_compute2(uint8_t cornerA,uint8_t cornerB,uint8_t cornerC,byte flags,byte bit)

{
  char cVar1;
  undefined2 in_AX;
  undefined2 uVar2;
  undefined1 extraout_AH;
  
  if ((flags & bit) == 0) {
    cVar1 = ovr_driver_compute2(cornerA,cornerB,cornerC);
    uVar2 = CONCAT11(extraout_AH,cVar1);
  }
  else {
    uVar2 = CONCAT11((char)((uint)in_AX >> 8),0xe2);
  }
  return uVar2;
}



/* 36ce:04e9 */

/* [R6] touches ScreenOriginY, GfxRndSeed */

void __cdecl16far constr_usesScreenOriginY(uint16_t rect,uint16_t type,...)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 extraout_AH;
  uint16_t uVar5;
  uint16_t uVar6;
  far_t gfx;
  uint uStack_12;
  uint8_t cellNext;
  uint8_t cell;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  for (uVar5 = rowMapSquareFirst[0]; uVar6 = rowMapSquareFirst[0],
      (int)uVar5 < (int)rowMapSquareEnd[0]; uVar5 = uVar5 + 1) {
    if ((0xb < *(int *)(uVar5 * 2 + 0x6c0)) && (*(int *)(uVar5 * 2 + 0xa20) < 0xdf)) {
      uVar6 = *(uint16_t *)(uVar5 * 2 + 0x360);
      iStack_6 = constr_getCellAtOffset(uVar6,-2);
      iStack_8 = constr_getCellAtOffset(uVar6 + 1,-2);
      iVar2 = constr_usesSmoothPrev(uVar6,-1,(int *)&cell);
      iVar3 = constr_usesSmoothPrev(uVar6 + 1,-1,(int *)&cellNext);
      uVar4 = constr_getFlagsAtOffset(uVar6,-1);
      bVar1 = (byte)uVar4;
      if ((uVar4 & 4) == 0) {
        uStack_12 = constr_compute2(cell,cellNext,(uint8_t)iStack_8,bVar1,2);
        uStack_12 = uStack_12 & 0xff;
        ovr_ovc07_usesBiosReadKey
                  (*(int *)(uVar5 * 2 + 0xa20),ScreenOriginY[0] - iVar2,*(int *)(uVar5 * 2 + 0x6c0),
                   ScreenOriginY[0] - iVar3,*(int *)(uVar5 * 2 + 0x6c0),0x96,uStack_12,
                   (brect_t *)CONCAT22(type,rect));
        uVar4 = constr_compute2((uint8_t)iStack_6,(uint8_t)iStack_8,cell,bVar1,1);
        ovr_ovc07_usesBiosReadKey
                  (*(int *)(uVar5 * 2 + 0xa20),ScreenOriginY[0] - iVar2,*(int *)(uVar5 * 2 + 0xa20),
                   0x96,*(int *)(uVar5 * 2 + 0x6c0),0x96,uVar4 & 0xff,(brect_t *)CONCAT22(type,rect)
                  );
      }
      else {
        uStack_12 = constr_compute2(cell,cellNext,(uint8_t)iStack_6,bVar1,1);
        uStack_12 = uStack_12 & 0xff;
        ovr_ovc07_usesBiosReadKey
                  (*(int *)(uVar5 * 2 + 0xa20),ScreenOriginY[0] - iVar2,*(int *)(uVar5 * 2 + 0x6c0),
                   ScreenOriginY[0] - iVar3,*(int *)(uVar5 * 2 + 0xa20),0x96,uStack_12,
                   (brect_t *)CONCAT22(type,rect));
        uVar4 = constr_compute2((uint8_t)iStack_6,(uint8_t)iStack_8,cellNext,bVar1,2);
        ovr_ovc07_usesBiosReadKey
                  (*(int *)(uVar5 * 2 + 0x6c0),ScreenOriginY[0] - iVar3,*(int *)(uVar5 * 2 + 0xa20),
                   0x96,*(int *)(uVar5 * 2 + 0x6c0),0x96,uVar4 & 0xff,(brect_t *)CONCAT22(type,rect)
                  );
      }
      uVar4 = constr_usesGMapFlags(uVar6 + GfxRndSeed,GfxRndSeed2);
      if ((char)uVar4 != '\0') {
        ovr_ovc07_usesLDIV_at_
                  (*(int *)(uVar5 * 2 + 0xa20),ScreenOriginY[0] - iVar2,*(int *)(uVar5 * 2 + 0x6c0),
                   ScreenOriginY[0] - iVar3,(char)uStack_12 + 0xfe,(brect_t *)rect);
        ovr_ovc07_usesLDIV_at_
                  (*(int *)(uVar5 * 2 + 0xa20),(ScreenOriginY[0] - iVar2) + 1,
                   *(int *)(uVar5 * 2 + 0x6c0),(ScreenOriginY[0] - iVar3) + 1,(char)uStack_12 + 0xff
                   ,(brect_t *)rect);
      }
    }
  }
  for (; (int)uVar6 < (int)rowMapSquareEnd[0]; uVar6 = uVar6 + 1) {
    uVar5 = *(uint16_t *)(uVar6 * 2 + 0x360);
    bVar1 = constr_setHighlightAtOffset(uVar5,0);
    iStack_4 = CONCAT11(extraout_AH,bVar1);
    if ((iStack_4 != 0) &&
       (iVar2 = constr_usesSmoothPrev(uVar5,-1,(int *)&cell),
       (*(byte *)(iStack_4 * 0x27 + 0x11e) & 2) != 0)) {
      gfx.seg = *(uint16_t *)
                 ((char *)
                  "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                  + 0x34 + iStack_4 * 0xc);
      gfx.ofs = *(uint16_t *)
                 ((char *)
                  "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                  + 0x32 + iStack_4 * 0xc);
      ovr_blit_usesBlitGfxN
                (gfx,*(int16_t *)(uVar6 * 2 + 0xa20),(uint)bandOrigin[0] - iVar2,0x10,99,0x10,
                 (brect_t *)rect,type);
      ovr_ovc15_fillGridColumn(*(int *)(uVar6 * 2 + 0xa20) - 0xc);
    }
  }
  return;
}



/* 36ce:08ee */

/* Blits the objects of each map square in the current row range when its bldtp_t flags have bit 0
   or 2 set. */

void __cdecl16far constr_blitRowObjects(brect_t *rect,uint16_t type,...)

{
  byte bVar1;
  undefined1 extraout_AH;
  int iVar2;
  uint16_t uVar3;
  far_t gfx;
  
  for (uVar3 = rowMapSquareFirst[0]; (int)uVar3 < (int)rowMapSquareEnd[0]; uVar3 = uVar3 + 1) {
    iVar2 = *(int *)(uVar3 * 2 + 0x360);
    if ((0xb < iVar2 + 0x2f) && (iVar2 < 0xdf)) {
      bVar1 = constr_setHighlightAtOffset(iVar2,0);
      if ((*(byte *)(CONCAT11(extraout_AH,bVar1) * 0x27 + 0x11e) & 5) != 0) {
        iVar2 = CONCAT11(extraout_AH,bVar1) * 0xc;
        gfx.seg = *(uint16_t *)
                   ((char *)
                    "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                    + 0x38 + iVar2);
        gfx.ofs = *(uint16_t *)
                   ((char *)
                    "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                    + 0x36 + iVar2);
        ovr_blitGfxRect(gfx,*(int16_t *)(uVar3 * 2 + 0xa20),144,rect,(uint8_t)type,true,0);
      }
    }
  }
  return;
}



/* 36ce:0995 */

/* WARNING: Variable defined which should be unmapped: buf */
/* [R4] calls ovr_agnt_clear */

void __cdecl16far constr_usesAgnt_clear(void)

{
  uint16_t uVar1;
  int16_t iVar2;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_00_00;
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
  far_t dst;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 extraout_AH;
  int iVar7;
  int iVar8;
  char *text;
  undefined2 uVar9;
  uint16_t unaff_SI;
  int iVar10;
  uint unaff_DI;
  uint16_t uVar11;
  char *unaff_SS;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  uint8_t term;
  undefined1 uVar16;
  char buf [81];
  byte bStack_3b;
  int iStack_34;
  int iStack_30;
  uint8_t cornerBR;
  uint8_t cornerBL;
  uint8_t cornerTR;
  uint8_t cornerTL;
  int iStack_24;
  int iStack_22;
  int iStack_20;
  int iStack_1e;
  int iStack_1c;
  int iStack_1a;
  uint8_t shades;
  byte abStack_17 [5];
  int iStack_12;
  uint uStack_10;
  int iStack_e;
  byte bStack_b;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  undefined2 uStack_4;
  
  dst.seg._0_1_ = (char)unaff_SS;
  dst.ofs = (uint16_t)&shades;
  dst.seg._1_1_ = (char)((uint)unaff_SS >> 8);
  F_SCOPY((far_t)0x24100745,dst);
  if (GOngoingBattle == '\0') {
    ovr_ovc13_usesBlitRects();
    constr_usesSmoothPrev2();
    ovr_ovc23_textAdlibNone(unaff_DI,unaff_SI,(agnt_t *)buf._0_2_);
    GGameState = 0x24;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    iStack_12 = GfxRndSeed >> 2;
    if (0xb < 0x14bU - iStack_12) {
      gfx_06.seg._0_1_ =
           (char)((undefined2 *)&l1Cut1Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      gfx_06.ofs = ((undefined2 *)&l1Cut1Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      gfx_06.seg._1_1_ =
           (char)((uint)((undefined2 *)&l1Cut1Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4] >> 8
                 );
      ovr_blitGfxRect(gfx_06,0xc - iStack_12,7,(brect_t *)BlitRects,0x10,true,
                      (char)(0xc - iStack_12),7,0x40,0x10,0x10,0);
    }
    if (0x14cU - iStack_12 < 0xdf) {
      gfx_07.seg._0_1_ =
           (char)((undefined2 *)&l1Cut3Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      gfx_07.ofs = ((undefined2 *)&l1Cut3Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      gfx_07.seg._1_1_ =
           (char)((uint)((undefined2 *)&l1Cut3Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4] >> 8
                 );
      ovr_blitGfxRect(gfx_07,0x14c - iStack_12,7,(brect_t *)BlitRects,0x10,true,
                      (char)(0x14c - iStack_12),7,0x40,0x10,0x10,0);
    }
    ovr_driver_fillRect(0xc,0x43,0xde,0x56,0xf0,BlitRects[0].seg,0x43,0xde,0x56,0xf0,
                        (char)BlitRects[0].seg);
    GGameState = 0x53;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (iVar10 = 8; -1 < iVar10; iVar10 = iVar10 + -1) {
      for (uVar11 = ((uint16_t *)rowMapSquareFirst)[iVar10]; uVar12 = (undefined1)iVar10,
          (int)uVar11 < (int)((uint16_t *)rowMapSquareEnd)[iVar10]; uVar11 = uVar11 + 1) {
        uVar1 = *(uint16_t *)(uVar11 * 2 + 0x360);
        iStack_1e = constr_usesSmoothPrev
                              (uVar1,iVar10 + -1,(int *)&cornerTL,(char)(iVar10 + -1),
                               (char)&cornerTL);
        iStack_20 = constr_usesSmoothPrev
                              (uVar1 + 1,iVar10 + -1,(int *)&cornerTR,(char)(iVar10 + -1),
                               (char)&cornerTR);
        iStack_22 = constr_usesSmoothPrev(uVar1,iVar10,(int *)&cornerBL,uVar12,(char)&cornerBL);
        iStack_24 = constr_usesSmoothPrev(uVar1 + 1,iVar10,(int *)&cornerBR,uVar12,(char)&cornerBR);
        uVar4 = constr_getFlagsAtOffset(uVar1,iVar10);
        bStack_b = (byte)uVar4;
        if ((uVar4 & 4) == 0) {
          if ((int)uVar1 < 0) {
            uVar4 = constr_compute1(cornerTL,cornerTR,cornerBL,bStack_b,1,cornerTR,cornerBL,bStack_b
                                   );
            iVar5 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
            iVar7 = *(int *)(uVar11 * 2 + 0x6c0);
            iVar6 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e;
            iVar8 = *(int *)(uVar11 * 2 + 0xa20);
            ovr_ovc07_usesBiosReadKey
                      (*(int *)((int)&AgntAnms[0x5d].sx + 1 + uVar11 * 2),
                       ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22,iVar8,iVar6,iVar7,iVar5,
                       uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,(char)iVar7,(char)iVar5,
                       (char)uVar4,0x40);
            uVar4 = constr_compute1(cornerBL,cornerBR,cornerTR,bStack_b,2,cornerBR,cornerTR,bStack_b
                                   );
            iVar5 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
            iVar7 = *(int *)(uVar11 * 2 + 0x6c0);
            iVar6 = ((uint16_t *)ScreenOriginX)[iVar10] - iStack_24;
            iVar8 = *(int *)(uVar11 * 2 + 0xd80);
            ovr_ovc07_usesBiosReadKey
                      (*(int *)((int)&AgntAnms[0x5d].sx + 1 + uVar11 * 2),
                       ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22,iVar8,iVar6,iVar7,iVar5,
                       uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,(char)iVar7,(char)iVar5,
                       (char)uVar4,0x40);
          }
          else {
            uVar4 = constr_compute1(cornerBL,cornerBR,cornerTR,bStack_b,2,cornerBR,cornerTR,bStack_b
                                   );
            iVar5 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
            iVar7 = *(int *)(uVar11 * 2 + 0x6c0);
            iVar6 = ((uint16_t *)ScreenOriginX)[iVar10] - iStack_24;
            iVar8 = *(int *)(uVar11 * 2 + 0xd80);
            ovr_ovc07_usesBiosReadKey
                      (*(int *)((int)&AgntAnms[0x5d].sx + 1 + uVar11 * 2),
                       ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22,iVar8,iVar6,iVar7,iVar5,
                       uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,(char)iVar7,(char)iVar5,
                       (char)uVar4,0x40);
            uVar4 = constr_compute1(cornerTL,cornerTR,cornerBL,bStack_b,1,cornerTR,cornerBL,bStack_b
                                   );
            iVar5 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
            iVar7 = *(int *)(uVar11 * 2 + 0x6c0);
            iVar6 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e;
            iVar8 = *(int *)(uVar11 * 2 + 0xa20);
            ovr_ovc07_usesBiosReadKey
                      (*(int *)((int)&AgntAnms[0x5d].sx + 1 + uVar11 * 2),
                       ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22,iVar8,iVar6,iVar7,iVar5,
                       uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,(char)iVar7,(char)iVar5,
                       (char)uVar4,0x40);
          }
        }
        else if ((int)uVar1 < 0) {
          uVar4 = constr_compute1(cornerBL,cornerBR,cornerTL,bStack_b,1,cornerBR,cornerTL,bStack_b);
          iVar5 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e;
          iVar7 = *(int *)(uVar11 * 2 + 0xa20);
          iVar6 = ((uint16_t *)ScreenOriginX)[iVar10] - iStack_24;
          iVar8 = *(int *)(uVar11 * 2 + 0xd80);
          ovr_ovc07_usesBiosReadKey
                    (*(int *)((int)&AgntAnms[0x5d].sx + 1 + uVar11 * 2),
                     ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22,iVar8,iVar6,iVar7,iVar5,
                     uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,(char)iVar7,(char)iVar5,
                     (char)uVar4,0x40);
          uVar4 = constr_compute1(cornerTL,cornerTR,cornerBR,bStack_b,2,cornerTR,cornerBR,bStack_b);
          iVar5 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
          iVar7 = *(int *)(uVar11 * 2 + 0x6c0);
          iVar6 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e;
          iVar8 = *(int *)(uVar11 * 2 + 0xa20);
          ovr_ovc07_usesBiosReadKey
                    (*(int *)(uVar11 * 2 + 0xd80),((uint16_t *)ScreenOriginX)[iVar10] - iStack_24,
                     iVar8,iVar6,iVar7,iVar5,uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,
                     (char)iVar7,(char)iVar5,(char)uVar4,0x40);
        }
        else {
          uVar4 = constr_compute1(cornerTL,cornerTR,cornerBR,bStack_b,2,cornerTR,cornerBR,bStack_b);
          iVar5 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
          iVar7 = *(int *)(uVar11 * 2 + 0x6c0);
          iVar6 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e;
          iVar8 = *(int *)(uVar11 * 2 + 0xa20);
          ovr_ovc07_usesBiosReadKey
                    (*(int *)(uVar11 * 2 + 0xd80),((uint16_t *)ScreenOriginX)[iVar10] - iStack_24,
                     iVar8,iVar6,iVar7,iVar5,uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,
                     (char)iVar7,(char)iVar5,(char)uVar4,0x40);
          uVar4 = constr_compute1(cornerBL,cornerBR,cornerTL,bStack_b,1,cornerBR,cornerTL,bStack_b);
          iVar5 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e;
          iVar7 = *(int *)(uVar11 * 2 + 0xa20);
          iVar6 = ((uint16_t *)ScreenOriginX)[iVar10] - iStack_24;
          iVar8 = *(int *)(uVar11 * 2 + 0xd80);
          ovr_ovc07_usesBiosReadKey
                    (*(int *)((int)&AgntAnms[0x5d].sx + 1 + uVar11 * 2),
                     ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22,iVar8,iVar6,iVar7,iVar5,
                     uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,(char)iVar7,(char)iVar5,
                     (char)uVar4,0x40);
        }
      }
      if (iVar10 < 6) {
        for (bStack_3b = 0; bStack_3b < 2; bStack_3b = bStack_3b + 1) {
          for (uVar11 = ((uint16_t *)rowMapSquareFirst)[iVar10];
              (int)uVar11 < (int)((uint16_t *)rowMapSquareEnd)[iVar10]; uVar11 = uVar11 + 1) {
            uVar1 = *(uint16_t *)(uVar11 * 2 + 0x360);
            bVar3 = constr_setHighlightAtOffset(uVar1,iVar10,uVar12);
            iStack_e = CONCAT11(extraout_AH,bVar3);
            GGameState = 0x37;
            if (DebugVerbose != false) {
              printf("%d \r");
            }
            if (iStack_e < 0xf8) {
              if ((iStack_e != 0) &&
                 (((bStack_3b == 0 && ((*(uint *)(iStack_e * 0x27 + 0x121) & 0x800) != 0)) ||
                  ((bStack_3b != 0 && ((*(uint *)(iStack_e * 0x27 + 0x121) & 0x800) == 0)))))) {
                if (*(byte *)(iStack_e * 0x27 + 0x11b) < 2) {
                  iStack_1e = constr_usesSmoothPrev
                                        (uVar1,iVar10 + -1,(int *)&cornerTL,(char)(iVar10 + -1),
                                         (char)&cornerTL);
                  iStack_22 = constr_usesSmoothPrev
                                        (uVar1,iVar10,(int *)&cornerBL,uVar12,(char)&cornerBL);
                  iStack_20 = constr_usesSmoothPrev
                                        (uVar1 + 1,iVar10 + -1,(int *)&cornerTR,(char)(iVar10 + -1),
                                         (char)&cornerTR);
                  iStack_24 = constr_usesSmoothPrev
                                        (uVar1 + 1,iVar10,(int *)&cornerBR,uVar12,(char)&cornerBR);
                }
                else if (*(byte *)(iStack_e * 0x27 + 0x11b) < 3) {
                  iStack_1e = constr_usesSmoothPrev
                                        (uVar1,iVar10 + -1,(int *)&cornerTL,(char)(iVar10 + -1),
                                         (char)&cornerTL);
                  iStack_22 = constr_usesSmoothPrev
                                        (uVar1,iVar10,(int *)&cornerBL,uVar12,(char)&cornerBL);
                  iStack_20 = constr_usesSmoothPrev
                                        (uVar1 + 2,iVar10 + -1,(int *)&cornerTR,(char)(iVar10 + -1),
                                         (char)&cornerTR);
                  iStack_24 = constr_usesSmoothPrev
                                        (uVar1 + 2,iVar10,(int *)&cornerBR,uVar12,(char)&cornerBR);
                }
                else {
                  iStack_1e = constr_usesSmoothPrev
                                        (uVar1 + 1,iVar10 + -1,(int *)&cornerTL,(char)(iVar10 + -1),
                                         (char)&cornerTL);
                  iStack_22 = constr_usesSmoothPrev
                                        (uVar1 + 1,iVar10,(int *)&cornerBL,uVar12,(char)&cornerBL);
                  iStack_20 = constr_usesSmoothPrev
                                        (uVar1 + 2,iVar10 + -1,(int *)&cornerTR,(char)(iVar10 + -1),
                                         (char)&cornerTR);
                  iStack_24 = constr_usesSmoothPrev
                                        (uVar1 + 2,iVar10,(int *)&cornerBR,uVar12,(char)&cornerBR);
                }
                uStack_10 = (uint)*(byte *)(iVar10 + 0x73c);
                iStack_30 = iStack_22 + iStack_1e + iStack_20 + iStack_24 >> 2;
                if ((int)(iStack_1e - uStack_10) < (int)(iStack_20 - uStack_10)) {
                  iVar7 = iStack_1e - uStack_10;
                }
                else {
                  iVar7 = iStack_20 - uStack_10;
                }
                if (iStack_30 < iVar7) {
                  if ((int)(iStack_1e - uStack_10) < (int)(iStack_20 - uStack_10)) {
                    iStack_30 = iStack_1e - uStack_10;
                  }
                  else {
                    iStack_30 = iStack_20 - uStack_10;
                  }
                }
                if (*(char *)(iStack_e * 0x27 + 0x11e) == '\0') {
                  if ((*(uint *)(iStack_e * 0x27 + 0x121) & 0x20) == 0) {
                    iVar7 = iStack_e * 0xc + *(int *)(uVar11 * 2) * 4;
                    if (((*(int *)(iVar7 + 0x4230) == 0 && *(int *)(iVar7 + 0x4232) == 0) ||
                        (2 < iVar10)) || (7 < HighlightLevel)) {
                      iStack_30 = (uint)*(byte *)(iVar10 + 0x728) - iStack_30;
                      iVar2 = *(int16_t *)(uVar11 * 2 + 0xa20);
                      iVar7 = iStack_e * 0xc + *(int *)(uVar11 * 2) * 4;
                      gfx_10.seg._0_1_ =
                           (char)*(undefined2 *)
                                  ((char *)
                                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                   + 0x30 + iVar7);
                      gfx_10.ofs = *(undefined2 *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x2e + iVar7);
                      gfx_10.seg._1_1_ =
                           (char)((uint)*(undefined2 *)
                                         ((char *)
                                          "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                          + 0x30 + iVar7) >> 8);
                      ovr_blitGfxRect(gfx_10,iVar2,iStack_30,(brect_t *)BlitRects,0x10,
                                      (bool)abStack_17[iVar10 + -1],(char)iVar2,(char)iStack_30,0x40
                                      ,0x10,abStack_17[iVar10 + -1],0);
                    }
                    else {
                      iVar7 = (uint)*(byte *)(iVar10 + 0x728) - iStack_30;
                      iVar2 = *(int16_t *)(uVar11 * 2 + 0xa20);
                      iVar8 = iStack_e * 0xc + *(int *)(uVar11 * 2) * 4;
                      uVar9 = *(undefined2 *)(iVar8 + 0x4232);
                      gfx_09.seg._0_1_ = (char)uVar9;
                      gfx_09.ofs = *(undefined2 *)(iVar8 + 0x4230);
                      gfx_09.seg._1_1_ = (char)((uint)uVar9 >> 8);
                      ovr_blitGfxRect(gfx_09,iVar2,iVar7,(brect_t *)BlitRects,0x10,
                                      (bool)abStack_17[iVar10 + -1],(char)iVar2,(char)iVar7,0x40,
                                      0x10,abStack_17[iVar10 + -1],0);
                      if (1 < HighlightLevel) {
                        iVar7 = iStack_e * 0xc + *(int *)(uVar11 * 2) * 4;
                        gfx_00.seg = *(uint16_t *)
                                      ((char *)
                                       "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                       + 0x30 + iVar7);
                        gfx_00.ofs = *(uint16_t *)
                                      ((char *)
                                       "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                       + 0x2e + iVar7);
                        ovr_gfxRlePrepare(gfx_00,*(int *)(uVar11 * 2 + 0xa20),
                                          (uint)*(byte *)(iVar10 + 0x728) - iStack_30,
                                          &((brect_t *)BlitRects)->x,'\x10',abStack_17[iVar10 + -1],
                                          0x40,0x10,abStack_17[iVar10 + -1],0,0,
                                          (char)(HighlightLevel * 0xff >> 3),0);
                      }
                    }
                  }
                  else {
                    iStack_30 = (uint)*(byte *)(iVar10 + 0x728) - iStack_30;
                    iVar2 = *(int16_t *)(uVar11 * 2 + 0xa20);
                    iVar7 = iStack_e * 0xc + (uint)GSeason * 4;
                    gfx_08.seg._0_1_ =
                         (char)*(undefined2 *)
                                ((char *)
                                 "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                 + 0x30 + iVar7);
                    gfx_08.ofs = *(undefined2 *)
                                  ((char *)
                                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                   + 0x2e + iVar7);
                    gfx_08.seg._1_1_ =
                         (char)((uint)*(undefined2 *)
                                       ((char *)
                                        "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                        + 0x30 + iVar7) >> 8);
                    ovr_blitGfxRect(gfx_08,iVar2,iStack_30,(brect_t *)BlitRects,0x10,
                                    (bool)abStack_17[iVar10 + -1],(char)iVar2,(char)iStack_30,0x40,
                                    0x10,abStack_17[iVar10 + -1],0);
                  }
                }
                else {
                  if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 0x10) != 0) {
                    for (iStack_6 = 0; iStack_6 < 6; iStack_6 = iStack_6 + 1) {
                      iVar7 = (int)(((uint)*(byte *)(iVar10 + 0x729) - iStack_22) * (5 - iStack_6))
                              / 5 + (int)(((uint)*(byte *)(iVar10 + 0x729) - iStack_24) * iStack_6)
                                    / 5;
                      iVar8 = (*(int *)((int)&AgntAnms[0x5d].sx + 1 + uVar11 * 2) * (5 - iStack_6))
                              / 5 + (*(int *)(uVar11 * 2 + 0xd80) * iStack_6) / 5;
                      gfx.seg = *(uint16_t *)
                                 ((char *)
                                  "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                  + 0x34 + iStack_e * 0xc);
                      gfx.ofs = *(uint16_t *)
                                 ((char *)
                                  "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                  + 0x32 + iStack_e * 0xc);
                      gfx_00_00.seg = *(uint16_t *)((int)&BldInstances[0].seg + iStack_e * 0xc);
                      gfx_00_00.ofs = ((bld_inst_t *)BldInstances + iStack_e)->ofs;
                      ovr_blit_usesBlitGfxN2
                                (gfx,gfx_00_00,
                                 (*(int *)(uVar11 * 2 + 0xa20) * (5 - iStack_6)) / 5 +
                                 (*(int *)(uVar11 * 2 + 0x6c0) * iStack_6) / 5,
                                 (int)(((uint)*(byte *)(iVar10 + 0x728) - iStack_1e) *
                                      (5 - iStack_6)) / 5 +
                                 (int)(((uint)*(byte *)(iVar10 + 0x728) - iStack_20) * iStack_6) / 5
                                 ,abStack_17[iVar10 + -1],iVar8,iVar7,abStack_17[iVar10],
                                 (brect_t *)BlitRects,0x2410,(byte)HighlightLevel,
                                 abStack_17[iVar10 + -1],(char)iVar8,(char)iVar7,abStack_17[iVar10],
                                 0x40,0x10);
                    }
                  }
                  if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 10) != 0) {
                    if (*(int *)(uVar11 * 2 + 0xa20) ==
                        *(int *)((int)&AgntAnms[0x5d].sx + 1 + uVar11 * 2)) {
                      iVar7 = (uint)*(byte *)(iVar10 + 0x729) - iStack_22;
                      iVar8 = (uint)*(byte *)(iVar10 + 0x728) - iStack_1e;
                      iVar2 = *(int16_t *)(uVar11 * 2 + 0xa20);
                      gfx_04.seg = *(uint16_t *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x34 + iStack_e * 0xc);
                      gfx_04.ofs = *(uint16_t *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x32 + iStack_e * 0xc);
                      ovr_blit_usesBlitGfxN
                                (gfx_04,iVar2,iVar8,abStack_17[iVar10 + -1],iVar7,abStack_17[iVar10]
                                 ,(brect_t *)BlitRects,0x2410,(char)iVar2,(char)iVar8,
                                 abStack_17[iVar10 + -1],(char)iVar7,abStack_17[iVar10],0x40,0x10);
                    }
                    else {
                      iVar8 = ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22;
                      iVar7 = *(int *)((int)&AgntAnms[0x5d].sx + 1 + uVar11 * 2);
                      gfx_01.seg = *(uint16_t *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x30 + iStack_e * 0xc);
                      gfx_01.ofs = *(uint16_t *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x2e + iStack_e * 0xc);
                      ovr_blit_usesStExit(gfx_01,*(int *)(uVar11 * 2 + 0xa20),
                                          ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e,
                                          abStack_17[iVar10 + -1],iVar7,iVar8,abStack_17[iVar10],
                                          &((brect_t *)BlitRects)->x,abStack_17[iVar10 + -1],
                                          (char)iVar7,(char)iVar8,abStack_17[iVar10],0x40,0x10,0);
                    }
                  }
                  if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 8) != 0) {
                    if (*(int *)(uVar11 * 2 + 0xd80) == *(int *)(uVar11 * 2 + 0x6c0)) {
                      iVar7 = (uint)*(byte *)(iVar10 + 0x729) - iStack_24;
                      iVar8 = (uint)*(byte *)(iVar10 + 0x728) - iStack_20;
                      iVar2 = *(int16_t *)(uVar11 * 2 + 0x6c0);
                      gfx_05.seg = *(uint16_t *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x34 + iStack_e * 0xc);
                      gfx_05.ofs = *(uint16_t *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x32 + iStack_e * 0xc);
                      ovr_blit_usesBlitGfxN
                                (gfx_05,iVar2,iVar8,abStack_17[iVar10 + -1],iVar7,abStack_17[iVar10]
                                 ,(brect_t *)BlitRects,0x2410,(char)iVar2,(char)iVar8,
                                 abStack_17[iVar10 + -1],(char)iVar7,abStack_17[iVar10],0x40,0x10);
                    }
                    else {
                      iVar8 = ((uint16_t *)ScreenOriginX)[iVar10] - iStack_24;
                      iVar7 = *(int *)(uVar11 * 2 + 0xd80);
                      gfx_02.seg = *(uint16_t *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x30 + iStack_e * 0xc);
                      gfx_02.ofs = *(uint16_t *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x2e + iStack_e * 0xc);
                      ovr_blit_usesStExit(gfx_02,*(int *)(uVar11 * 2 + 0x6c0),
                                          ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20,
                                          abStack_17[iVar10 + -1],iVar7,iVar8,abStack_17[iVar10],
                                          &((brect_t *)BlitRects)->x,abStack_17[iVar10 + -1],
                                          (char)iVar7,(char)iVar8,abStack_17[iVar10],0x40,0x10,0);
                    }
                  }
                  if (((*(byte *)(iStack_e * 0x27 + 0x11e) & 4) != 0) ||
                     (((*(byte *)(iStack_e * 0x27 + 0x11e) & 1) != 0 && (iVar10 != 0)))) {
                    iVar8 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
                    iVar7 = *(int *)(uVar11 * 2 + 0x6c0);
                    gfx_03.seg = *(uint16_t *)
                                  ((char *)
                                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                   + 0x30 + iStack_e * 0xc);
                    gfx_03.ofs = *(uint16_t *)
                                  ((char *)
                                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                   + 0x2e + iStack_e * 0xc);
                    ovr_blit_usesStExit(gfx_03,*(int *)(uVar11 * 2 + 0xa20),
                                        ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e,
                                        abStack_17[iVar10 + -1],iVar7,iVar8,abStack_17[iVar10 + -1],
                                        &((brect_t *)BlitRects)->x,abStack_17[iVar10 + -1],
                                        (char)iVar7,(char)iVar8,abStack_17[iVar10 + -1],0x40,0x10,0)
                    ;
                  }
                }
              }
            }
            else {
              printf("Bad House # %d \r");
              ovr_biosReadKey();
            }
          }
        }
      }
    }
    GGameState = 0x25;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    constr_usesScreenOriginY(0x440,0x2410,0x10);
    iStack_8 = 0;
    iStack_a = 0;
    for (uVar11 = rowMapSquareFirst[0]; (int)uVar11 < (int)rowMapSquareEnd[0]; uVar11 = uVar11 + 1)
    {
      if ((0xb < *(int *)(uVar11 * 2 + 0x6c0)) && (*(int *)(uVar11 * 2 + 0xa20) < 0xdf)) {
        uVar1 = *(uint16_t *)(uVar11 * 2 + 0x360);
        iStack_1a = constr_usesSmoothPrev(uVar1,-1,(int *)&cornerBL,0xff,(char)&cornerBL);
        iStack_1c = constr_usesSmoothPrev(uVar1 + 1,-1,(int *)&cornerBR,0xff,(char)&cornerBR);
        uVar4 = constr_getFlagsAtOffset(uVar1,-1);
        bStack_b = (byte)uVar4;
        iVar8 = ScreenOriginY[0] - iStack_1a;
        iVar10 = *(int *)(uVar11 * 2 + 0x6c0);
        iVar7 = *(int *)(uVar11 * 2 + 0xa20);
        for (iStack_34 = *(int *)(uVar11 * 2 + 0xa20); iStack_34 <= *(int *)(uVar11 * 2 + 0x6c0);
            iStack_34 = iStack_34 + 1) {
          if ((0xb < iStack_34) && (iStack_34 < 0xdf)) {
            *(int *)((iStack_34 + -0xc) * 2 + 0x34c) =
                 iVar8 + ((iStack_1a - iStack_1c) * (iStack_34 - *(int *)(uVar11 * 2 + 0xa20))) /
                         (iVar10 - iVar7);
            *(int *)((iStack_34 + -0xc) * 2 + 0x1a6) = -(iStack_1a - iStack_1c);
            if ((uVar4 & 3) == 0) {
              *(undefined2 *)((iStack_34 + -0xc) * 2) = 1;
            }
            else {
              *(undefined2 *)((iStack_34 + -0xc) * 2) = 0;
              if ((uVar4 & 3) != 0) {
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
      printf("%d \r");
    }
    uStack_4 = TextBlitDstSeg;
    uVar9 = 0x2410;
    TextBlitDstSeg = BlitRects[0].seg;
    TextBlitX = 0xb6;
    TextBlitY = 10;
    if (GameRunning == false) {
      uVar16 = 0xe0;
      term = 0x3f;
      uVar14 = (undefined1)Font02.seg;
      uVar15 = (undefined1)(Font02.seg >> 8);
      uVar12 = (undefined1)Font02.ofs;
      uVar13 = (undefined1)(Font02.ofs >> 8);
      uVar4 = ovr_alignUp4(GfxRndSeed,(char)GfxRndSeed2);
      text = ovr_stsprintf(buf,(char *)CONCAT22(0x76b,unaff_SS),
                           (char *)CONCAT13((char)(uVar4 >> 8),CONCAT12((char)uVar4,0x2410)),0x10);
      ovr_blitText(text,(byte *)CONCAT13(uVar13,CONCAT12(uVar12,uVar9)),CONCAT11(uVar15,uVar14),term
                   ,(char)uVar9,uVar12,uVar14,term,uVar16);
    }
    TextBlitDstSeg = uStack_4;
    ovr_agnt_usesFmFreeAudio();
    GGameState = 0x27;
    if (DebugVerbose != false) {
      printf("x:%d y:%d  %x %x %x %x   %x %x %x %x    \r");
    }
    ovr_attact_usesLDIV_at_2();
  }
  else {
    constr_usesBlitGfxRect2();
    ovr_ovc13_usesAlignUp4();
    ovr_attact_usesLDIV_at_2();
  }
  return;
}



/* 36ce:1db4 */

/* Blits the two dirty rects with mouse save/restore and frees the staging block. */

void __cdecl16far constr_flushDirtyRects(void)

{
  void *pvVar1;
  uint16_t in_DX;
  far_t ptr;
  far_t handle;
  
  pvVar1 = ovr_stshAlloc(0xfa0f);
  ptr.seg = in_DX;
  ptr.ofs = (uint16_t)pvVar1;
  ovr_alignToSeg(ptr);
  ovr_miceRestoreArea((brect_t *)BlitRects);
  ovr_miceRestoreArea((brect_t *)(BlitRects + 3));
  constr_usesAgnt_clear();
  ovr_miceBlitRect((brect_t *)BlitRects);
  blitRect((brect_t *)BlitRects);
  ovr_miceUpdate();
  ovr_miceBlitRect((brect_t *)(BlitRects + 3));
  blitRect((brect_t *)(BlitRects + 3));
  BlitRects[3].seg = 0xa000;
  BlitRects[0].seg = 0xa000;
  handle.seg = in_DX;
  handle.ofs = (uint16_t)pvVar1;
  ovr_stshFree(handle);
  return;
}



/* 36ce:1e76 */

/* [R4] calls blitRect */

void __cdecl16far constr_usesBlitRect3(void)

{
  void *pvVar1;
  uint16_t in_DX;
  far_t ptr;
  far_t handle;
  
  pvVar1 = ovr_stshAlloc(0xfa0f);
  ptr.seg = in_DX;
  ptr.ofs = (uint16_t)pvVar1;
  ovr_alignToSeg(ptr);
  ovr_miceRestoreArea((brect_t *)(BlitRects + 3));
  constr_usesBlitGfxRect2();
  ovr_miceBlitRect((brect_t *)(BlitRects + 3));
  blitRect((brect_t *)(BlitRects + 3));
  ovr_miceUpdate();
  BlitRects[3].seg = 0xa000;
  handle.seg = in_DX;
  handle.ofs = (uint16_t)pvVar1;
  ovr_stshFree(handle);
  return;
}



/* 36ce:1efc */

/* [R4] calls blitRect */

void __cdecl16far constr_usesBlitRect4(void)

{
  void *pvVar1;
  uint16_t in_DX;
  far_t ptr;
  far_t handle;
  
  pvVar1 = ovr_stshAlloc(0xfa0f);
  ptr.seg = in_DX;
  ptr.ofs = (uint16_t)pvVar1;
  ovr_alignToSeg(ptr);
  GGameState = 0x22;
  constr_usesAgnt_clear();
  GGameState = 0x23;
  blitRect((brect_t *)BlitRects);
  blitRect((brect_t *)(BlitRects + 3));
  BlitRects[3].seg = 0xa000;
  BlitRects[0].seg = 0xa000;
  handle.seg = in_DX;
  handle.ofs = (uint16_t)pvVar1;
  ovr_stshFree(handle);
  return;
}



/* 36ce:1f99 */

/* WARNING: Type propagation algorithm not settling */
/* [R4] calls ovr_blitGfxRect */

void __cdecl16far constr_usesBlitGfxRect2(void)

{
  undefined2 uVar1;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  undefined1 extraout_AH;
  int iVar5;
  undefined1 extraout_AH_00;
  int dy;
  uint16_t uVar6;
  uint16_t uVar7;
  uint16_t unaff_SS;
  far_t gfx_08;
  far_t gfx_09;
  far_t gfx_10;
  far_t gfx_11;
  ulong uVar8;
  far_t dst_00;
  ulong uVar9;
  uint uStack_28;
  int iStack_26;
  uint8_t cornerBR;
  uint8_t cornerBL;
  uint8_t cornerTR;
  uint8_t cornerTL;
  int iStack_1a;
  int iStack_18;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  int iStack_10;
  int iStack_e;
  uint8_t dst;
  bool bStack_a;
  byte abStack_9 [3];
  int iStack_6;
  uint uStack_4;
  
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&dst;
  F_SCOPY((far_t)0x2410074f,dst_00);
  bVar2 = ovr_draw_textArena();
  if (bVar2) {
    iStack_6 = GfxRndSeed * 6 >> 6;
    if (0xee < 0x166 - iStack_6) {
      gfx_02.seg._0_1_ =
           (char)((undefined2 *)&l1Cut1Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      gfx_02.ofs = ((undefined2 *)&l1Cut1Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      gfx_02.seg._1_1_ =
           (char)((uint)((undefined2 *)&l1Cut1Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4] >> 8
                 );
      ovr_blitGfxRect(gfx_02,0xef - iStack_6,7,(brect_t *)(BlitRects + 3),0x10,true);
    }
    if (0x167 - iStack_6 < 0x135) {
      gfx_03.seg._0_1_ =
           (char)((undefined2 *)&l1Cut3Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      gfx_03.ofs = ((undefined2 *)&l1Cut3Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      gfx_03.seg._1_1_ =
           (char)((uint)((undefined2 *)&l1Cut3Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4] >> 8
                 );
      ovr_blitGfxRect(gfx_03,0x22f - iStack_6,7,(brect_t *)(BlitRects + 3),0x10,true);
    }
    ovr_driver_fillRect(0xef,0x1d,0x134,0x24,0xf0,BlitRects[3].seg);
    constr_usesSmoothPrev2();
    for (dy = 2; uVar6 = rowBandSquareFirst[0], -1 < dy; dy = dy + -1) {
      for (uVar6 = ((uint16_t *)rowBandSquareFirst)[dy];
          (int)uVar6 < (int)((uint16_t *)rowBandSquareEnd)[dy]; uVar6 = uVar6 + 1) {
        uVar7 = ((uint16_t *)squareColumn)[uVar6];
        iStack_14 = constr_usesSmoothPrev(uVar7,dy + -1,(int *)&cornerTL);
        iStack_14 = iStack_14 / 3;
        iStack_16 = constr_usesSmoothPrev(uVar7 + 1,dy + -1,(int *)&cornerTR);
        iStack_16 = iStack_16 / 3;
        iStack_18 = constr_usesSmoothPrev(uVar7,dy,(int *)&cornerBL);
        iStack_18 = iStack_18 / 3;
        iStack_1a = constr_usesSmoothPrev(uVar7 + 1,dy,(int *)&cornerBR);
        iStack_1a = iStack_1a / 3;
        uVar4 = constr_getFlagsAtOffset(uVar7,dy);
        bVar3 = (byte)uVar4;
        if ((uVar4 & 4) == 0) {
          if ((int)uVar7 < 0) {
            uVar9 = CONCAT22(1,uVar4) & 0xffff00ff;
            uVar8 = (ulong)CONCAT12(cornerBL,cornerTR) & 0xffff00ff;
            uVar4 = constr_compute1(cornerTL,(uint8_t)uVar8,(uint8_t)(uVar8 >> 0x10),(byte)uVar9,
                                    (byte)(uVar9 >> 0x10));
            ovr_ovc07_usesBiosReadKey
                      (((uint16_t *)SquareTopY)[uVar6],((uint16_t *)RowScreenX)[dy] - iStack_18,
                       ((uint16_t *)SquareLeftX)[uVar6],((uint16_t *)RowScreenY)[dy] - iStack_14,
                       ((uint16_t *)SquareRightX)[uVar6],((uint16_t *)RowScreenY)[dy] - iStack_16,
                       uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareLeftX)[uVar6]);
            uVar4 = constr_compute1(cornerBL,cornerBR,cornerTR,bVar3,2);
            ovr_ovc07_usesBiosReadKey
                      (((uint16_t *)SquareTopY)[uVar6],((uint16_t *)RowScreenX)[dy] - iStack_18,
                       ((uint16_t *)SquareBottomY)[uVar6],((uint16_t *)RowScreenX)[dy] - iStack_1a,
                       ((uint16_t *)SquareRightX)[uVar6],((uint16_t *)RowScreenY)[dy] - iStack_16,
                       uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareBottomY)[uVar6]);
          }
          else {
            uVar8 = CONCAT22(2,uVar4) & 0xffff00ff;
            uVar4 = constr_compute1(cornerBL,cornerBR,(uint8_t)cornerTR,(byte)uVar8,
                                    (byte)(uVar8 >> 0x10));
            ovr_ovc07_usesBiosReadKey
                      (((uint16_t *)SquareTopY)[uVar6],((uint16_t *)RowScreenX)[dy] - iStack_18,
                       ((uint16_t *)SquareBottomY)[uVar6],((uint16_t *)RowScreenX)[dy] - iStack_1a,
                       ((uint16_t *)SquareRightX)[uVar6],((uint16_t *)RowScreenY)[dy] - iStack_16,
                       uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareBottomY)[uVar6]);
            uVar4 = constr_compute1(cornerTL,cornerTR,cornerBL,bVar3,1);
            ovr_ovc07_usesBiosReadKey
                      (((uint16_t *)SquareTopY)[uVar6],((uint16_t *)RowScreenX)[dy] - iStack_18,
                       ((uint16_t *)SquareLeftX)[uVar6],((uint16_t *)RowScreenY)[dy] - iStack_14,
                       ((uint16_t *)SquareRightX)[uVar6],((uint16_t *)RowScreenY)[dy] - iStack_16,
                       uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareLeftX)[uVar6]);
          }
        }
        else if ((int)uVar7 < 0) {
          uVar8 = CONCAT22(1,uVar4) & 0xffff00ff;
          uVar4 = constr_compute1(cornerBL,cornerBR,cornerTL,(byte)uVar8,(byte)(uVar8 >> 0x10));
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareTopY)[uVar6],((uint16_t *)RowScreenX)[dy] - iStack_18,
                     ((uint16_t *)SquareBottomY)[uVar6],((uint16_t *)RowScreenX)[dy] - iStack_1a,
                     ((uint16_t *)SquareLeftX)[uVar6],((uint16_t *)RowScreenY)[dy] - iStack_14,
                     uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareBottomY)[uVar6]);
          uVar4 = constr_compute1(cornerTL,cornerTR,cornerBR,bVar3,2);
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareBottomY)[uVar6],((uint16_t *)RowScreenX)[dy] - iStack_1a,
                     ((uint16_t *)SquareLeftX)[uVar6],((uint16_t *)RowScreenY)[dy] - iStack_14,
                     ((uint16_t *)SquareRightX)[uVar6],((uint16_t *)RowScreenY)[dy] - iStack_16,
                     uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareLeftX)[uVar6]);
        }
        else {
          uVar9 = CONCAT22(2,uVar4) & 0xffff00ff;
          uVar8 = (ulong)CONCAT12(cornerBR,cornerTR) & 0xffff00ff;
          uVar4 = constr_compute1(cornerTL,(uint8_t)uVar8,(uint8_t)(uVar8 >> 0x10),(byte)uVar9,
                                  (byte)(uVar9 >> 0x10));
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareBottomY)[uVar6],((uint16_t *)RowScreenX)[dy] - iStack_1a,
                     ((uint16_t *)SquareLeftX)[uVar6],((uint16_t *)RowScreenY)[dy] - iStack_14,
                     ((uint16_t *)SquareRightX)[uVar6],((uint16_t *)RowScreenY)[dy] - iStack_16,
                     uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareLeftX)[uVar6]);
          uVar4 = constr_compute1(cornerBL,cornerBR,cornerTL,bVar3,1);
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareTopY)[uVar6],((uint16_t *)RowScreenX)[dy] - iStack_18,
                     ((uint16_t *)SquareBottomY)[uVar6],((uint16_t *)RowScreenX)[dy] - iStack_1a,
                     ((uint16_t *)SquareLeftX)[uVar6],((uint16_t *)RowScreenY)[dy] - iStack_14,
                     uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareBottomY)[uVar6]);
        }
      }
      for (uVar6 = ((uint16_t *)rowBandSquareFirst)[dy];
          (int)uVar6 < (int)((uint16_t *)rowBandSquareEnd)[dy]; uVar6 = uVar6 + 1) {
        uVar7 = ((uint16_t *)squareColumn)[uVar6];
        bVar3 = constr_setHighlightAtOffset(uVar7,dy);
        iStack_e = CONCAT11(extraout_AH,bVar3);
        if (iStack_e != 0) {
          iStack_14 = constr_usesSmoothPrev(uVar7,dy + -1,(int *)&cornerTL);
          iStack_14 = iStack_14 / 3;
          iStack_18 = constr_usesSmoothPrev(uVar7,dy,(int *)&cornerBL);
          iStack_18 = iStack_18 / 3;
          if (*(byte *)(iStack_e * 0x27 + 0x11b) < 2) {
            iStack_16 = constr_usesSmoothPrev(uVar7 + 1,dy + -1,(int *)&cornerTR);
            iStack_16 = iStack_16 / 3;
            iStack_1a = constr_usesSmoothPrev(uVar7 + 1,dy,(int *)&cornerBR);
            iStack_1a = iStack_1a / 3;
          }
          else if (*(byte *)(iStack_e * 0x27 + 0x11b) < 3) {
            iStack_16 = constr_usesSmoothPrev(uVar7 + 2,dy + -1,(int *)&cornerTR);
            iStack_16 = iStack_16 / 3;
            iStack_1a = constr_usesSmoothPrev(uVar7 + 2,dy,(int *)&cornerBR);
            iStack_1a = iStack_1a / 3;
          }
          else {
            iStack_16 = constr_usesSmoothPrev(uVar7 + 4,dy + -1,(int *)&cornerTR);
            iStack_16 = iStack_16 / 3;
            iStack_1a = constr_usesSmoothPrev(uVar7 + 4,dy,(int *)&cornerBR);
            iStack_1a = iStack_1a / 3;
          }
          iStack_26 = iStack_18 + iStack_14 + iStack_16 + iStack_1a >> 2;
          uStack_4 = (uint)*(byte *)(dy + 0x73e);
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
              iVar5 = iStack_e * 0xc + ((uint16_t *)squareSide)[uVar6] * 4;
              if (((*(int *)(iVar5 + 0x4230) == 0 && *(int *)(iVar5 + 0x4232) == 0) || (1 < dy)) ||
                 (7 < HighlightLevel)) {
                iVar5 = iStack_e * 0xc + ((uint16_t *)squareSide)[uVar6] * 4;
                gfx_06.seg._0_1_ =
                     (char)*(undefined2 *)
                            ((char *)
                             "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                             + 0x30 + iVar5);
                gfx_06.ofs = *(undefined2 *)
                              ((char *)
                               "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                               + 0x2e + iVar5);
                gfx_06.seg._1_1_ =
                     (char)((uint)*(undefined2 *)
                                   ((char *)
                                    "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                    + 0x30 + iVar5) >> 8);
                ovr_blitGfxRect(gfx_06,((uint16_t *)SquareLeftX)[uVar6],
                                (uint)*(byte *)(dy + 0x74b) - iStack_26,(brect_t *)(BlitRects + 3),
                                0x10,(&bStack_a)[dy]);
              }
              else {
                iVar5 = iStack_e * 0xc + ((uint16_t *)squareSide)[uVar6] * 4;
                uVar1 = *(undefined2 *)(iVar5 + 0x4232);
                gfx_05.seg._0_1_ = (char)uVar1;
                gfx_05.ofs = *(undefined2 *)(iVar5 + 0x4230);
                gfx_05.seg._1_1_ = (char)((uint)uVar1 >> 8);
                ovr_blitGfxRect(gfx_05,((uint16_t *)SquareLeftX)[uVar6],
                                (uint)*(byte *)(dy + 0x74b) - iStack_26,(brect_t *)(BlitRects + 3),
                                0x10,(&bStack_a)[dy]);
                if (1 < HighlightLevel) {
                  iVar5 = iStack_e * 0xc + ((uint16_t *)squareSide)[uVar6] * 4;
                  gfx_08.seg = *(uint16_t *)
                                ((char *)
                                 "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                 + 0x30 + iVar5);
                  gfx_08.ofs = *(uint16_t *)
                                ((char *)
                                 "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                 + 0x2e + iVar5);
                  ovr_gfxRlePrepare(gfx_08,((uint16_t *)SquareLeftX)[uVar6],
                                    (uint)*(byte *)(dy + 0x74b) - iStack_26,
                                    &((brect_t *)(BlitRects + 3))->x,'\x10',(&bStack_a)[dy],0x5e,0,0
                                    ,HighlightLevel * 0xff >> 3);
                }
              }
            }
            else {
              iVar5 = iStack_e * 0xc + (uint)GSeason * 4;
              gfx_04.seg._0_1_ =
                   (char)*(undefined2 *)
                          ((char *)
                           "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                           + 0x30 + iVar5);
              gfx_04.ofs = *(undefined2 *)
                            ((char *)
                             "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                             + 0x2e + iVar5);
              gfx_04.seg._1_1_ =
                   (char)((uint)*(undefined2 *)
                                 ((char *)
                                  "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                  + 0x30 + iVar5) >> 8);
              ovr_blitGfxRect(gfx_04,((uint16_t *)SquareLeftX)[uVar6],
                              (uint)*(byte *)(dy + 0x74b) - iStack_26,(brect_t *)(BlitRects + 3),
                              0x10,(&bStack_a)[dy]);
            }
          }
          else {
            if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 10) != 0) {
              if (((uint16_t *)SquareLeftX)[uVar6] == ((uint16_t *)SquareTopY)[uVar6]) {
                gfx.seg = *(uint16_t *)
                           ((char *)
                            "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                            + 0x34 + iStack_e * 0xc);
                gfx.ofs = *(uint16_t *)
                           ((char *)
                            "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                            + 0x32 + iStack_e * 0xc);
                ovr_blit_usesBlitGfxN
                          (gfx,((uint16_t *)SquareLeftX)[uVar6],
                           (uint)*(byte *)(dy + 0x74b) - iStack_14,(&bStack_a)[dy],
                           (uint)*(byte *)(dy + 0x74c) - iStack_18,abStack_9[dy],
                           (brect_t *)(BlitRects + 3),0x2410,(char)((uint16_t *)SquareLeftX)[uVar6])
                ;
              }
              else {
                gfx_09.seg = *(uint16_t *)
                              ((char *)
                               "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                               + 0x30 + iStack_e * 0xc);
                gfx_09.ofs = *(uint16_t *)
                              ((char *)
                               "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                               + 0x2e + iStack_e * 0xc);
                ovr_blit_usesStExit(gfx_09,((uint16_t *)SquareLeftX)[uVar6],
                                    ((uint16_t *)RowScreenY)[dy] - iStack_14,(&bStack_a)[dy],
                                    ((uint16_t *)SquareTopY)[uVar6],
                                    ((uint16_t *)RowScreenX)[dy] - iStack_18,abStack_9[dy],
                                    &((brect_t *)(BlitRects + 3))->x,(&bStack_a)[dy],0x2410);
              }
            }
            if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 8) != 0) {
              if (((uint16_t *)SquareBottomY)[uVar6] == ((uint16_t *)SquareRightX)[uVar6]) {
                gfx_00.seg = *(uint16_t *)
                              ((char *)
                               "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                               + 0x34 + iStack_e * 0xc);
                gfx_00.ofs = *(uint16_t *)
                              ((char *)
                               "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                               + 0x32 + iStack_e * 0xc);
                ovr_blit_usesBlitGfxN
                          (gfx_00,((uint16_t *)SquareRightX)[uVar6],
                           (uint)*(byte *)(dy + 0x74b) - iStack_16,(&bStack_a)[dy],
                           (uint)*(byte *)(dy + 0x74c) - iStack_1a,abStack_9[dy],
                           (brect_t *)(BlitRects + 3),0x2410,(char)((uint16_t *)SquareRightX)[uVar6]
                          );
              }
              else {
                gfx_10.seg = *(uint16_t *)
                              ((char *)
                               "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                               + 0x30 + iStack_e * 0xc);
                gfx_10.ofs = *(uint16_t *)
                              ((char *)
                               "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                               + 0x2e + iStack_e * 0xc);
                ovr_blit_usesStExit(gfx_10,((uint16_t *)SquareRightX)[uVar6],
                                    ((uint16_t *)RowScreenY)[dy] - iStack_16,(&bStack_a)[dy],
                                    ((uint16_t *)SquareBottomY)[uVar6],
                                    ((uint16_t *)RowScreenX)[dy] - iStack_1a,abStack_9[dy],
                                    &((brect_t *)(BlitRects + 3))->x,(&bStack_a)[dy],0x2410);
              }
            }
            if (((*(byte *)(iStack_e * 0x27 + 0x11e) & 4) != 0) ||
               (((*(byte *)(iStack_e * 0x27 + 0x11e) & 1) != 0 && (dy != 0)))) {
              gfx_11.seg = *(uint16_t *)
                            ((char *)
                             "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                             + 0x30 + iStack_e * 0xc);
              gfx_11.ofs = *(uint16_t *)
                            ((char *)
                             "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                             + 0x2e + iStack_e * 0xc);
              ovr_blit_usesStExit(gfx_11,((uint16_t *)SquareLeftX)[uVar6],
                                  ((uint16_t *)RowScreenY)[dy] - iStack_14,(&bStack_a)[dy],
                                  ((uint16_t *)SquareRightX)[uVar6],
                                  ((uint16_t *)RowScreenY)[dy] - iStack_16,(&bStack_a)[dy],
                                  &((brect_t *)(BlitRects + 3))->x,(&bStack_a)[dy],0x2410);
            }
          }
        }
      }
    }
    for (; uVar7 = rowBandSquareFirst[0], (int)uVar6 < (int)rowBandSquareEnd[0]; uVar6 = uVar6 + 1)
    {
      if ((0xee < (int)((uint16_t *)SquareRightX)[uVar6]) &&
         ((int)((uint16_t *)SquareLeftX)[uVar6] < 0x135)) {
        uVar7 = ((uint16_t *)squareColumn)[uVar6];
        cornerTL = constr_getCellAtOffset(uVar7,-2);
        cornerTR = constr_getCellAtOffset(uVar7 + 1,-2);
        iStack_10 = constr_usesSmoothPrev(uVar7,-1,(int *)&cornerBL);
        iStack_10 = iStack_10 / 3;
        iStack_12 = constr_usesSmoothPrev(uVar7 + 1,-1,(int *)&cornerBR);
        iStack_12 = iStack_12 / 3;
        uVar4 = constr_getFlagsAtOffset(uVar7,-1);
        bVar3 = (byte)uVar4;
        if ((uVar4 & 4) == 0) {
          uStack_28 = constr_compute2(cornerBL,cornerBR,cornerTR,bVar3,2);
          uStack_28 = uStack_28 & 0xff;
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareLeftX)[uVar6],RowScreenY[0] - iStack_10,
                     ((uint16_t *)SquareRightX)[uVar6],RowScreenY[0] - iStack_12,
                     ((uint16_t *)SquareRightX)[uVar6],0x36,uStack_28,BlitRects + 3,
                     (char)((uint16_t *)SquareRightX)[uVar6]);
          uVar4 = constr_compute2(cornerTL,cornerTR,cornerBL,bVar3,1);
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareLeftX)[uVar6],RowScreenY[0] - iStack_10,
                     ((uint16_t *)SquareLeftX)[uVar6],0x36,((uint16_t *)SquareRightX)[uVar6],0x36,
                     uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareLeftX)[uVar6]);
        }
        else {
          uStack_28 = constr_compute2(cornerBL,cornerBR,cornerTL,bVar3,1);
          uStack_28 = uStack_28 & 0xff;
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareLeftX)[uVar6],RowScreenY[0] - iStack_10,
                     ((uint16_t *)SquareRightX)[uVar6],RowScreenY[0] - iStack_12,
                     ((uint16_t *)SquareLeftX)[uVar6],0x36,uStack_28,BlitRects + 3,
                     (char)((uint16_t *)SquareRightX)[uVar6]);
          uVar4 = constr_compute2(cornerTL,cornerTR,cornerBR,bVar3,2);
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareRightX)[uVar6],RowScreenY[0] - iStack_12,
                     ((uint16_t *)SquareLeftX)[uVar6],0x36,((uint16_t *)SquareRightX)[uVar6],0x36,
                     uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareLeftX)[uVar6]);
        }
        uVar4 = constr_usesGMapFlags(uVar7 + GfxRndSeed,GfxRndSeed2);
        if ((char)uVar4 != '\0') {
          ovr_ovc07_usesLDIV_at_
                    (((uint16_t *)SquareLeftX)[uVar6],RowScreenY[0] - iStack_10,
                     ((uint16_t *)SquareRightX)[uVar6],RowScreenY[0] - iStack_12,
                     (char)uStack_28 + 0xff,(brect_t *)(BlitRects + 3));
        }
      }
    }
    for (; (int)uVar7 < (int)rowBandSquareEnd[0]; uVar7 = uVar7 + 1) {
      uVar6 = ((uint16_t *)squareColumn)[uVar7];
      bVar3 = constr_setHighlightAtOffset(uVar6,0);
      iStack_e = CONCAT11(extraout_AH_00,bVar3);
      if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 2) != 0) {
        iStack_10 = constr_usesSmoothPrev(uVar6,-1,(int *)&cornerBL);
        iStack_10 = iStack_10 / 3;
        gfx_01.seg = *(uint16_t *)
                      ((char *)
                       "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                       + 0x34 + iStack_e * 0xc);
        gfx_01.ofs = *(uint16_t *)
                      ((char *)
                       "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                       + 0x32 + iStack_e * 0xc);
        ovr_blit_usesBlitGfxN
                  (gfx_01,((uint16_t *)SquareLeftX)[uVar7],(uint)rowBandOrigin[0] - iStack_10,6,0x27
                   ,6,(brect_t *)(BlitRects + 3),0x2410,(char)((uint16_t *)SquareLeftX)[uVar7]);
      }
      if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 1) != 0) {
        gfx_07.seg._0_1_ =
             (char)*(undefined2 *)
                    ((char *)
                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                     + 0x38 + iStack_e * 0xc);
        gfx_07.ofs = *(undefined2 *)
                      ((char *)
                       "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                       + 0x36 + iStack_e * 0xc);
        gfx_07.seg._1_1_ =
             (char)((uint)*(undefined2 *)
                           ((char *)
                            "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                            + 0x38 + iStack_e * 0xc) >> 8);
        ovr_blitGfxRect(gfx_07,((uint16_t *)SquareLeftX)[uVar7],51,(brect_t *)(BlitRects + 3),0x10,
                        bStack_a);
      }
    }
  }
  else {
    ovr_ovc13_usesBlitRects();
  }
  return;
}



/* 36ce:306b */

/* [R6] touches GMapFlags, GMapCells */

uint __cdecl16far constr_usesGMapFlags(int x,int y,...)

{
  uint in_AX;
  uint uVar1;
  short *psVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  undefined2 uVar6;
  int iStack_4;
  
  if ((((x < 0) || (y < 0)) || (in_AX = x + 1, 0x93 < (int)in_AX)) ||
     (in_AX = y + 1, 0x3b < (int)in_AX)) {
    placementStatus = 2;
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar6 = (undefined2)((ulong)GMapFlags >> 0x10);
    psVar2 = (short *)(x * 2);
    if ((((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) == 0) &&
       (psVar2 = (*(short (*) [60] [148])GMapFlags)[y] + x, (psVar2[0x94] & 3U) == 0)) {
      iStack_4 = (int)(char)(*(byte (*) [59] [148])GMapCells)[y + 1][x];
      iVar3 = (int)(char)(*(byte (*) [59] [148])GMapCells)[y + 1][x + 1];
      iVar5 = iStack_4;
      if (iVar3 < iStack_4) {
        iVar5 = iVar3;
      }
      if (iStack_4 < iVar3) {
        iStack_4 = iVar3;
      }
      bVar4 = (byte)((uint)(iStack_4 - iVar5) >> 8);
      if (iStack_4 - iVar5 < 9) {
        placementStatus = 3;
        uVar1 = CONCAT11(bVar4,1);
      }
      else {
        uVar1 = (uint)bVar4 << 8;
      }
    }
    else {
      placementStatus = 1;
      uVar1 = (uint)psVar2 & 0xff00;
    }
  }
  return uVar1;
}



/* 36ce:3172 */

/* [R6] touches GMapFlags, GMapCells */

uint __cdecl16far constr_usesGMapFlags2(int x,int y,...)

{
  byte cornerA;
  byte cornerB;
  byte cornerA_00;
  byte cornerB_00;
  uint uVar1;
  uint uVar2;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 uVar3;
  short (*paasVar4) [60] [148];
  undefined2 uVar5;
  byte bStack_4;
  byte bStack_3;
  
  uVar5 = (undefined2)((ulong)GMapFlags >> 0x10);
  paasVar4 = (short (*) [60] [148])GMapFlags;
  uVar1 = (*paasVar4)[y][x];
  if ((uVar1 & 3) == 0) {
    uVar2 = paasVar4[-1][y + 0x3a][x + 0x93] | paasVar4[-1][y + 0x3b][x] |
            paasVar4[-1][y + 0x3b][x + 1] | paasVar4[-1][y + 0x3b][x + 0x93] | (*paasVar4)[y][x + 1]
            | (*paasVar4)[y][x + 0x93] | (*paasVar4)[y + 1][x] | (*paasVar4)[y + 1][x + 1];
    if ((uVar2 & 3) == 0) {
      cornerA = (*(byte (*) [59] [148])GMapCells)[y + 1][x];
      cornerB = (*(byte (*) [59] [148])GMapCells)[y + 1][x + 1];
      cornerA_00 = (*(byte (*) [59] [148])GMapCells)[y][x];
      cornerB_00 = (*(byte (*) [59] [148])GMapCells)[y][x + 1];
      if ((uVar1 & 4) == 0) {
        bStack_3 = ovr_driver_compute2(cornerA_00,cornerB_00,cornerB);
        bStack_4 = ovr_driver_compute2(cornerA,cornerB,cornerA_00);
        uVar3 = extraout_AH_00;
      }
      else {
        bStack_3 = ovr_driver_compute2(cornerA_00,cornerB_00,cornerA);
        bStack_4 = ovr_driver_compute2(cornerA,cornerB,cornerB_00);
        uVar3 = extraout_AH;
      }
      if ((bStack_3 < 0xfa) && (bStack_4 < 0xfa)) {
        if ((bStack_3 < 0xf5) && (bStack_4 < 0xf5)) {
          uVar1 = CONCAT11(uVar3,2);
        }
        else {
          uVar1 = CONCAT11(uVar3,3);
        }
      }
      else {
        uVar1 = CONCAT11(uVar3,4);
      }
    }
    else {
      uVar1 = CONCAT11((char)(uVar2 >> 8),1);
    }
  }
  else {
    uVar1 = uVar1 & 0xff00;
  }
  return uVar1;
}


