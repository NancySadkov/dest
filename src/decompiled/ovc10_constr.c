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

uint16_t __cdecl16far constr_getFlagsAtOffset(int dx,int dy)

{
  int iVar1;
  uint16_t uVar2;
  
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

int __cdecl16far constr_usesSmoothPrev(uint16_t dx,int dy,int *cell,uint16_t arg4,uint16_t arg5)

{
  int iVar1;
  uint16_t in_stack_0000000a;
  
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

byte __cdecl16far constr_setHighlightAtOffset(int dx,int dy,uint16_t arg3)

{
  byte bVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  
  if ((((dx + GfxRndSeed < 0x94) && (SCARRY2(dx,GfxRndSeed) == dx + GfxRndSeed < 0)) &&
      (GfxRndSeed2 - dy < 0x3c)) && (dy <= GfxRndSeed2)) {
    uVar2 = (uint16_t)((ulong)GUnitGrid >> 0x10);
    uVar3 = (uint16_t)((ulong)GUnits >> 0x10);
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
  iVar1 = constr_usesSmoothPrev(0xffff,-1,(int *)&cell,0,0);
  iStack_4 = iVar1;
  iVar2 = constr_usesSmoothPrev(0,-1,(int *)&cell,0,0);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  if (iStack_4 < iVar2) {
    iStack_4 = iVar2;
  }
  iVar2 = constr_usesSmoothPrev(1,-1,(int *)&cell,0,0);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  if (iStack_4 < iVar2) {
    iStack_4 = iVar2;
  }
  iVar2 = constr_usesSmoothPrev(2,-1,(int *)&cell,0,0);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  iVar2 = constr_usesSmoothPrev(0xfffe,-1,(int *)&cell,0,0);
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

void __cdecl16far blitRect(brect_t *br,uint16_t arg2)

{
  uint16_t pbr;
  uint16_t in_stack_00000006;
  
  ovr_blitRaw(br->x,br->y,br->w,br->h,br->seg,0xa000);
  return;
}



/* 36ce:0345 */

/* Restores the mouse area, blits a raw rect to the 0xa000 screen and blits the mouse back. */

void __cdecl16far constr_blitRawToScreen(brect_t *rect)

{
  uint16_t dstSeg;
  brect_t *br;
  uint16_t uVar1;
  
  uVar1 = (uint16_t)((ulong)rect >> 0x10);
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
    ovr_miceRestoreArea((brect_t *)BlitRects,0);
    ovr_ovc13_usesAlignUp4();
    ovr_miceBlitRect((brect_t *)BlitRects,0);
    blitRect((brect_t *)BlitRects,0);
    ovr_miceUpdate();
    BlitRects[0].seg = 0xa000;
  }
  if (GOngoingBattle != '\0') {
    bVar1 = ovr_draw_textArena();
    if (bVar1) goto L_constr_36ce_03a6_0489;
  }
  ovr_miceRestoreArea((brect_t *)(BlitRects + 3),0);
  ovr_ovc13_usesBlitRects();
  ovr_miceBlitRect((brect_t *)(BlitRects + 3),0);
  blitRect((brect_t *)(BlitRects + 3),0);
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

uint16_t __cdecl16far
constr_compute1(uint8_t cornerA,uint8_t cornerB,uint8_t cornerC,byte flags,byte bit,uint16_t arg6,uint16_t arg7,uint16_t arg8)

{
  char cVar1;
  uint16_t in_AX;
  uint16_t uVar2;
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

uint16_t __cdecl16far
constr_compute2(uint8_t cornerA,uint8_t cornerB,uint8_t cornerC,byte flags,byte bit)

{
  char cVar1;
  uint16_t in_AX;
  uint16_t uVar2;
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

void __cdecl16far constr_usesScreenOriginY(uint16_t rect,uint16_t type,uint16_t arg3)

{
  byte flags;
  int smoothL;
  int smoothR;
  uint uVar4;
  undefined1 extraout_AH;
  uint16_t uVar5;
  uint16_t uVar6;
  far_t gfx;
  uint fillColor;
  uint8_t cellNext;
  uint8_t cell;
  int cellR2;
  int cellL2;
  int bldIndex;
  
  for (uVar5 = rowMapSquareFirst[0]; uVar6 = rowMapSquareFirst[0],
      (int)uVar5 < (int)rowMapSquareEnd[0]; uVar5 = uVar5 + 1) {
    if ((0xb < *(int *)(&mapSquareRightX[uVar5])) && (*(int *)(&mapSquareLeftX[uVar5]) < 0xdf)) {
      uVar6 = *(uint16_t *)(&mapSquareColumn[uVar5]);
      cellL2 = constr_getCellAtOffset(uVar6,-2);
      cellR2 = constr_getCellAtOffset(uVar6 + 1,-2);
      smoothL = constr_usesSmoothPrev(uVar6,-1,(int *)&cell,0,0);
      smoothR = constr_usesSmoothPrev(uVar6 + 1,-1,(int *)&cellNext,0,0);
      uVar4 = constr_getFlagsAtOffset(uVar6,-1);
      flags = (byte)uVar4;
      if ((uVar4 & 4) == 0) {
        fillColor = constr_compute2(cell,cellNext,(uint8_t)cellR2,flags,2);
        fillColor = fillColor & 0xff;
        ovr_ovc07_usesBiosReadKey
                  (*(int *)(&mapSquareLeftX[uVar5]),ScreenOriginY[0] - smoothL,*(int *)(&mapSquareRightX[uVar5]),ScreenOriginY[0] - smoothR,*(int *)(&mapSquareRightX[uVar5]),0x96,fillColor,(brect_t *)CONCAT22(type,rect),0,0,0,0,0,0);
        uVar4 = constr_compute2((uint8_t)cellL2,(uint8_t)cellR2,cell,flags,1);
        ovr_ovc07_usesBiosReadKey
                  (*(int *)(&mapSquareLeftX[uVar5]),ScreenOriginY[0] - smoothL,*(int *)(&mapSquareLeftX[uVar5]),0x96,*(int *)(&mapSquareRightX[uVar5]),0x96,uVar4 & 0xff,(brect_t *)CONCAT22(type,rect),0,0,0,0,0,0);
      }
      else {
        fillColor = constr_compute2(cell,cellNext,(uint8_t)cellL2,flags,1);
        fillColor = fillColor & 0xff;
        ovr_ovc07_usesBiosReadKey
                  (*(int *)(&mapSquareLeftX[uVar5]),ScreenOriginY[0] - smoothL,*(int *)(&mapSquareRightX[uVar5]),ScreenOriginY[0] - smoothR,*(int *)(&mapSquareLeftX[uVar5]),0x96,fillColor,(brect_t *)CONCAT22(type,rect),0,0,0,0,0,0);
        uVar4 = constr_compute2((uint8_t)cellL2,(uint8_t)cellR2,cellNext,flags,2);
        ovr_ovc07_usesBiosReadKey
                  (*(int *)(&mapSquareRightX[uVar5]),ScreenOriginY[0] - smoothR,*(int *)(&mapSquareLeftX[uVar5]),0x96,*(int *)(&mapSquareRightX[uVar5]),0x96,uVar4 & 0xff,(brect_t *)CONCAT22(type,rect),0,0,0,0,0,0);
      }
      uVar4 = constr_usesGMapFlags(uVar6 + GfxRndSeed,GfxRndSeed2,0);
      if ((char)uVar4 != '\0') {
        ovr_ovc07_usesLDIV_at_
                  (*(int *)(&mapSquareLeftX[uVar5]),ScreenOriginY[0] - smoothL,*(int *)(&mapSquareRightX[uVar5]),ScreenOriginY[0] - smoothR,(char)fillColor + 0xfe,(brect_t *)rect,0);
        ovr_ovc07_usesLDIV_at_
                  (*(int *)(&mapSquareLeftX[uVar5]),(ScreenOriginY[0] - smoothL) + 1,*(int *)(&mapSquareRightX[uVar5]),(ScreenOriginY[0] - smoothR) + 1,(char)fillColor + 0xff,(brect_t *)rect,0);
      }
    }
  }
  for (; (int)uVar6 < (int)rowMapSquareEnd[0]; uVar6 = uVar6 + 1) {
    uVar5 = *(uint16_t *)(&mapSquareColumn[uVar6]);
    flags = constr_setHighlightAtOffset(uVar5,0,0);
    bldIndex = CONCAT11(extraout_AH,flags);
    if ((bldIndex != 0) &&
       (smoothL = constr_usesSmoothPrev(uVar5,-1,(int *)&cell,0,0),
       (*(byte *)((uint8_t *)&BuildingTypes[bldIndex] + 16) & 2) != 0)) {
      gfx.seg = *(uint16_t *)
                 ((char *)0x28ed6 + bldIndex * 0xc);
      gfx.ofs = *(uint16_t *)
                 ((char *)0x28ed4 + bldIndex * 0xc);
      ovr_blit_usesBlitGfxN
                (gfx,*(int16_t *)(&mapSquareLeftX[uVar6]),(uint)bandOrigin[0] - smoothL,0x10,99,0x10,(brect_t *)rect,type,0,0,0,0,0,0,0);
      ovr_ovc15_fillGridColumn(*(int *)(&mapSquareLeftX[uVar6]) - 0xc);
    }
  }
  return;
}



/* 36ce:08ee */

/* Blits the objects of each map square in the current row range when its bldtp_t flags have bit 0
   or 2 set. */

void __cdecl16far constr_blitRowObjects(brect_t *rect,uint16_t type)

{
  byte bVar1;
  undefined1 extraout_AH;
  int iVar2;
  uint16_t uVar3;
  far_t gfx;
  
  for (uVar3 = rowMapSquareFirst[0]; (int)uVar3 < (int)rowMapSquareEnd[0]; uVar3 = uVar3 + 1) {
    iVar2 = *(int *)(&mapSquareColumn[uVar3]);
    if ((0xb < iVar2 + 0x2f) && (iVar2 < 0xdf)) {
      bVar1 = constr_setHighlightAtOffset(iVar2,0,0);
      if ((*(byte *)(CONCAT11(extraout_AH,bVar1) * 0x27 + 0x11e) & 5) != 0) {
        iVar2 = CONCAT11(extraout_AH,bVar1) * 0xc;
        gfx.seg = *(uint16_t *)
                   ((char *)0x28eda + iVar2);
        gfx.ofs = *(uint16_t *)
                   ((char *)0x28ed8 + iVar2);
        ovr_blitGfxRect(gfx,*(int16_t *)(&mapSquareLeftX[uVar3]),144,rect,(uint8_t)type,true,0,0,0,0,0,0);
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
  uint16_t sqCol;
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
  int scrY;
  int iVar6;
  undefined1 extraout_AH;
  int sqRight;
  int iVar8;
  char *text;
  uint16_t uVar9;
  uint16_t unaff_SI;
  int iVar10;
  uint unaff_DI;
  uint16_t sq;
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
  uint16_t uStack_4;
  
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
  dst.ofs = (uint16_t)&shades;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)((uint)unaff_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x24100745)),dst);
  if (GOngoingBattle == '\0') {
    ovr_ovc13_usesBlitRects();
    constr_usesSmoothPrev2();
    ovr_ovc23_textAdlibNone(unaff_DI,unaff_SI,(agnt_t *)(*(uint16_t *)((uint8_t *)&(buf))));
    GGameState = 0x24;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    iStack_12 = GfxRndSeed >> 2;
    if (0xb < 0x14bU - iStack_12) {
      (*(uint8_t *)((uint8_t *)&(gfx_06.seg))) =
           (char)((uint16_t *)&l1Cut1Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      gfx_06.ofs = ((uint16_t *)&l1Cut1Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      (*(uint8_t *)((uint8_t *)&(gfx_06.seg) + 1)) =
           (char)((uint)((uint16_t *)&l1Cut1Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4] >> 8
                 );
      ovr_blitGfxRect(gfx_06,0xc - iStack_12,7,(brect_t *)BlitRects,0x10,true,
                      (char)(0xc - iStack_12),7,0x40,0x10,0x10,0);
    }
    if (0x14cU - iStack_12 < 0xdf) {
      (*(uint8_t *)((uint8_t *)&(gfx_07.seg))) =
           (char)((uint16_t *)&l1Cut3Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      gfx_07.ofs = ((uint16_t *)&l1Cut3Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      (*(uint8_t *)((uint8_t *)&(gfx_07.seg) + 1)) =
           (char)((uint)((uint16_t *)&l1Cut3Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4] >> 8
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
      for (sq = ((uint16_t *)rowMapSquareFirst)[iVar10]; uVar12 = (undefined1)iVar10,
          (int)sq < (int)((uint16_t *)rowMapSquareEnd)[iVar10]; sq = sq + 1) {
        sqCol = *(uint16_t *)(&mapSquareColumn[sq]);
        iStack_1e = constr_usesSmoothPrev
                              (sqCol,iVar10 + -1,(int *)&cornerTL,(char)(iVar10 + -1),
                               (char)&cornerTL);
        iStack_20 = constr_usesSmoothPrev
                              (sqCol + 1,iVar10 + -1,(int *)&cornerTR,(char)(iVar10 + -1),
                               (char)&cornerTR);
        iStack_22 = constr_usesSmoothPrev(sqCol,iVar10,(int *)&cornerBL,uVar12,(char)&cornerBL);
        iStack_24 = constr_usesSmoothPrev(sqCol + 1,iVar10,(int *)&cornerBR,uVar12,(char)&cornerBR);
        uVar4 = constr_getFlagsAtOffset(sqCol,iVar10);
        bStack_b = (byte)uVar4;
        if ((uVar4 & 4) == 0) {
          if ((int)sqCol < 0) {
            uVar4 = constr_compute1(cornerTL,cornerTR,cornerBL,bStack_b,1,cornerTR,cornerBL,bStack_b
                                   );
            scrY = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
            sqRight = *(int *)(&mapSquareRightX[sq]);
            iVar6 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e;
            iVar8 = *(int *)(&mapSquareLeftX[sq]);
            ovr_ovc07_usesBiosReadKey
                      (*(int *)((int)&AgntAnms[0x5d].sx + 1 + sq * 2),
                       ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22,iVar8,iVar6,sqRight,scrY,
                       uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,(char)sqRight,(char)scrY,
                       (char)uVar4,0x40);
            uVar4 = constr_compute1(cornerBL,cornerBR,cornerTR,bStack_b,2,cornerBR,cornerTR,bStack_b
                                   );
            scrY = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
            sqRight = *(int *)(&mapSquareRightX[sq]);
            iVar6 = ((uint16_t *)ScreenOriginX)[iVar10] - iStack_24;
            iVar8 = *(int *)(&mapSquareBottomY[sq]);
            ovr_ovc07_usesBiosReadKey
                      (*(int *)((int)&AgntAnms[0x5d].sx + 1 + sq * 2),
                       ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22,iVar8,iVar6,sqRight,scrY,
                       uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,(char)sqRight,(char)scrY,
                       (char)uVar4,0x40);
          }
          else {
            uVar4 = constr_compute1(cornerBL,cornerBR,cornerTR,bStack_b,2,cornerBR,cornerTR,bStack_b
                                   );
            scrY = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
            sqRight = *(int *)(&mapSquareRightX[sq]);
            iVar6 = ((uint16_t *)ScreenOriginX)[iVar10] - iStack_24;
            iVar8 = *(int *)(&mapSquareBottomY[sq]);
            ovr_ovc07_usesBiosReadKey
                      (*(int *)((int)&AgntAnms[0x5d].sx + 1 + sq * 2),
                       ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22,iVar8,iVar6,sqRight,scrY,
                       uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,(char)sqRight,(char)scrY,
                       (char)uVar4,0x40);
            uVar4 = constr_compute1(cornerTL,cornerTR,cornerBL,bStack_b,1,cornerTR,cornerBL,bStack_b
                                   );
            scrY = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
            sqRight = *(int *)(&mapSquareRightX[sq]);
            iVar6 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e;
            iVar8 = *(int *)(&mapSquareLeftX[sq]);
            ovr_ovc07_usesBiosReadKey
                      (*(int *)((int)&AgntAnms[0x5d].sx + 1 + sq * 2),
                       ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22,iVar8,iVar6,sqRight,scrY,
                       uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,(char)sqRight,(char)scrY,
                       (char)uVar4,0x40);
          }
        }
        else if ((int)sqCol < 0) {
          uVar4 = constr_compute1(cornerBL,cornerBR,cornerTL,bStack_b,1,cornerBR,cornerTL,bStack_b);
          scrY = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e;
          sqRight = *(int *)(&mapSquareLeftX[sq]);
          iVar6 = ((uint16_t *)ScreenOriginX)[iVar10] - iStack_24;
          iVar8 = *(int *)(&mapSquareBottomY[sq]);
          ovr_ovc07_usesBiosReadKey
                    (*(int *)((int)&AgntAnms[0x5d].sx + 1 + sq * 2),
                     ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22,iVar8,iVar6,sqRight,scrY,
                     uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,(char)sqRight,(char)scrY,
                     (char)uVar4,0x40);
          uVar4 = constr_compute1(cornerTL,cornerTR,cornerBR,bStack_b,2,cornerTR,cornerBR,bStack_b);
          scrY = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
          sqRight = *(int *)(&mapSquareRightX[sq]);
          iVar6 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e;
          iVar8 = *(int *)(&mapSquareLeftX[sq]);
          ovr_ovc07_usesBiosReadKey
                    (*(int *)(&mapSquareBottomY[sq]),((uint16_t *)ScreenOriginX)[iVar10] - iStack_24,
                     iVar8,iVar6,sqRight,scrY,uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,
                     (char)sqRight,(char)scrY,(char)uVar4,0x40);
        }
        else {
          uVar4 = constr_compute1(cornerTL,cornerTR,cornerBR,bStack_b,2,cornerTR,cornerBR,bStack_b);
          scrY = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
          sqRight = *(int *)(&mapSquareRightX[sq]);
          iVar6 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e;
          iVar8 = *(int *)(&mapSquareLeftX[sq]);
          ovr_ovc07_usesBiosReadKey
                    (*(int *)(&mapSquareBottomY[sq]),((uint16_t *)ScreenOriginX)[iVar10] - iStack_24,
                     iVar8,iVar6,sqRight,scrY,uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,
                     (char)sqRight,(char)scrY,(char)uVar4,0x40);
          uVar4 = constr_compute1(cornerBL,cornerBR,cornerTL,bStack_b,1,cornerBR,cornerTL,bStack_b);
          scrY = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e;
          sqRight = *(int *)(&mapSquareLeftX[sq]);
          iVar6 = ((uint16_t *)ScreenOriginX)[iVar10] - iStack_24;
          iVar8 = *(int *)(&mapSquareBottomY[sq]);
          ovr_ovc07_usesBiosReadKey
                    (*(int *)((int)&AgntAnms[0x5d].sx + 1 + sq * 2),
                     ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22,iVar8,iVar6,sqRight,scrY,
                     uVar4 & 0xff,BlitRects,(char)iVar8,(char)iVar6,(char)sqRight,(char)scrY,
                     (char)uVar4,0x40);
        }
      }
      if (iVar10 < 6) {
        for (bStack_3b = 0; bStack_3b < 2; bStack_3b = bStack_3b + 1) {
          for (sq = ((uint16_t *)rowMapSquareFirst)[iVar10];
              (int)sq < (int)((uint16_t *)rowMapSquareEnd)[iVar10]; sq = sq + 1) {
            sqCol = *(uint16_t *)(&mapSquareColumn[sq]);
            bVar3 = constr_setHighlightAtOffset(sqCol,iVar10,uVar12);
            iStack_e = CONCAT11(extraout_AH,bVar3);
            GGameState = 0x37;
            if (DebugVerbose != false) {
              printf("%d \r");
            }
            if (iStack_e < 0xf8) {
              if ((iStack_e != 0) &&
                 (((bStack_3b == 0 && ((*(uint *)((uint8_t *)&BuildingTypes[iStack_e] + 19) & 0x800) != 0)) ||
                  ((bStack_3b != 0 && ((*(uint *)((uint8_t *)&BuildingTypes[iStack_e] + 19) & 0x800) == 0)))))) {
                if (*(byte *)((uint8_t *)&BuildingTypes[iStack_e] + 13) < 2) {
                  iStack_1e = constr_usesSmoothPrev
                                        (sqCol,iVar10 + -1,(int *)&cornerTL,(char)(iVar10 + -1),
                                         (char)&cornerTL);
                  iStack_22 = constr_usesSmoothPrev
                                        (sqCol,iVar10,(int *)&cornerBL,uVar12,(char)&cornerBL);
                  iStack_20 = constr_usesSmoothPrev
                                        (sqCol + 1,iVar10 + -1,(int *)&cornerTR,(char)(iVar10 + -1),
                                         (char)&cornerTR);
                  iStack_24 = constr_usesSmoothPrev
                                        (sqCol + 1,iVar10,(int *)&cornerBR,uVar12,(char)&cornerBR);
                }
                else if (*(byte *)((uint8_t *)&BuildingTypes[iStack_e] + 13) < 3) {
                  iStack_1e = constr_usesSmoothPrev
                                        (sqCol,iVar10 + -1,(int *)&cornerTL,(char)(iVar10 + -1),
                                         (char)&cornerTL);
                  iStack_22 = constr_usesSmoothPrev
                                        (sqCol,iVar10,(int *)&cornerBL,uVar12,(char)&cornerBL);
                  iStack_20 = constr_usesSmoothPrev
                                        (sqCol + 2,iVar10 + -1,(int *)&cornerTR,(char)(iVar10 + -1),
                                         (char)&cornerTR);
                  iStack_24 = constr_usesSmoothPrev
                                        (sqCol + 2,iVar10,(int *)&cornerBR,uVar12,(char)&cornerBR);
                }
                else {
                  iStack_1e = constr_usesSmoothPrev
                                        (sqCol + 1,iVar10 + -1,(int *)&cornerTL,(char)(iVar10 + -1),
                                         (char)&cornerTL);
                  iStack_22 = constr_usesSmoothPrev
                                        (sqCol + 1,iVar10,(int *)&cornerBL,uVar12,(char)&cornerBL);
                  iStack_20 = constr_usesSmoothPrev
                                        (sqCol + 2,iVar10 + -1,(int *)&cornerTR,(char)(iVar10 + -1),
                                         (char)&cornerTR);
                  iStack_24 = constr_usesSmoothPrev
                                        (sqCol + 2,iVar10,(int *)&cornerBR,uVar12,(char)&cornerBR);
                }
                uStack_10 = (uint)*(byte *)(iVar10 + 0x73c);
                iStack_30 = iStack_22 + iStack_1e + iStack_20 + iStack_24 >> 2;
                if ((int)(iStack_1e - uStack_10) < (int)(iStack_20 - uStack_10)) {
                  sqRight = iStack_1e - uStack_10;
                }
                else {
                  sqRight = iStack_20 - uStack_10;
                }
                if (iStack_30 < sqRight) {
                  if ((int)(iStack_1e - uStack_10) < (int)(iStack_20 - uStack_10)) {
                    iStack_30 = iStack_1e - uStack_10;
                  }
                  else {
                    iStack_30 = iStack_20 - uStack_10;
                  }
                }
                if (*(char *)((uint8_t *)&BuildingTypes[iStack_e] + 16) == '\0') {
                  if ((*(uint *)((uint8_t *)&BuildingTypes[iStack_e] + 19) & 0x20) == 0) {
                    sqRight = iStack_e * 0xc + *(int *)(sq * 2) * 4;
                    if (((*(int *)(sqRight + 0x4230) == 0 && *(int *)(sqRight + 0x4232) == 0) ||
                        (2 < iVar10)) || (7 < HighlightLevel)) {
                      iStack_30 = (uint)*(byte *)(iVar10 + 0x728) - iStack_30;
                      iVar2 = *(int16_t *)(&mapSquareLeftX[sq]);
                      sqRight = iStack_e * 0xc + *(int *)(sq * 2) * 4;
                      (*(uint8_t *)((uint8_t *)&(gfx_10.seg))) =
                           (char)*(uint16_t *)
                                  ((char *)0x28ed2 + sqRight);
                      gfx_10.ofs = *(uint16_t *)
                                    ((char *)0x28ed0 + sqRight);
                      (*(uint8_t *)((uint8_t *)&(gfx_10.seg) + 1)) =
                           (char)((uint)*(uint16_t *)
                                         ((char *)0x28ed2 + sqRight) >> 8);
                      ovr_blitGfxRect(gfx_10,iVar2,iStack_30,(brect_t *)BlitRects,0x10,
                                      (bool)abStack_17[iVar10 + -1],(char)iVar2,(char)iStack_30,0x40
                                      ,0x10,abStack_17[iVar10 + -1],0);
                    }
                    else {
                      sqRight = (uint)*(byte *)(iVar10 + 0x728) - iStack_30;
                      iVar2 = *(int16_t *)(&mapSquareLeftX[sq]);
                      iVar8 = iStack_e * 0xc + *(int *)(sq * 2) * 4;
                      uVar9 = *(uint16_t *)(iVar8 + 0x4232);
                      (*(uint8_t *)((uint8_t *)&(gfx_09.seg))) = (char)uVar9;
                      gfx_09.ofs = *(uint16_t *)(iVar8 + 0x4230);
                      (*(uint8_t *)((uint8_t *)&(gfx_09.seg) + 1)) = (char)((uint)uVar9 >> 8);
                      ovr_blitGfxRect(gfx_09,iVar2,sqRight,(brect_t *)BlitRects,0x10,
                                      (bool)abStack_17[iVar10 + -1],(char)iVar2,(char)sqRight,0x40,
                                      0x10,abStack_17[iVar10 + -1],0);
                      if (1 < HighlightLevel) {
                        sqRight = iStack_e * 0xc + *(int *)(sq * 2) * 4;
                        gfx_00.seg = *(uint16_t *)
                                      ((char *)0x28ed2 + sqRight);
                        gfx_00.ofs = *(uint16_t *)
                                      ((char *)0x28ed0 + sqRight);
                        ovr_gfxRlePrepare(gfx_00,*(int *)(&mapSquareLeftX[sq]),
                                          (uint)*(byte *)(iVar10 + 0x728) - iStack_30,
                                          &((brect_t *)BlitRects)->x,'\x10',abStack_17[iVar10 + -1],
                                          0x40,0x10,abStack_17[iVar10 + -1],0,0,
                                          (char)(HighlightLevel * 0xff >> 3),0);
                      }
                    }
                  }
                  else {
                    iStack_30 = (uint)*(byte *)(iVar10 + 0x728) - iStack_30;
                    iVar2 = *(int16_t *)(&mapSquareLeftX[sq]);
                    sqRight = iStack_e * 0xc + (uint)GSeason * 4;
                    (*(uint8_t *)((uint8_t *)&(gfx_08.seg))) =
                         (char)*(uint16_t *)
                                ((char *)0x28ed2 + sqRight);
                    gfx_08.ofs = *(uint16_t *)
                                  ((char *)0x28ed0 + sqRight);
                    (*(uint8_t *)((uint8_t *)&(gfx_08.seg) + 1)) =
                         (char)((uint)*(uint16_t *)
                                       ((char *)0x28ed2 + sqRight) >> 8);
                    ovr_blitGfxRect(gfx_08,iVar2,iStack_30,(brect_t *)BlitRects,0x10,
                                    (bool)abStack_17[iVar10 + -1],(char)iVar2,(char)iStack_30,0x40,
                                    0x10,abStack_17[iVar10 + -1],0);
                  }
                }
                else {
                  if ((*(byte *)((uint8_t *)&BuildingTypes[iStack_e] + 16) & 0x10) != 0) {
                    for (iStack_6 = 0; iStack_6 < 6; iStack_6 = iStack_6 + 1) {
                      sqRight = (int)(((uint)*(byte *)(iVar10 + 0x729) - iStack_22) * (5 - iStack_6))
                              / 5 + (int)(((uint)*(byte *)(iVar10 + 0x729) - iStack_24) * iStack_6)
                                    / 5;
                      iVar8 = (*(int *)((int)&AgntAnms[0x5d].sx + 1 + sq * 2) * (5 - iStack_6))
                              / 5 + (*(int *)(&mapSquareBottomY[sq]) * iStack_6) / 5;
                      gfx.seg = *(uint16_t *)
                                 ((char *)0x28ed6 + iStack_e * 0xc);
                      gfx.ofs = *(uint16_t *)
                                 ((char *)0x28ed4 + iStack_e * 0xc);
                      gfx_00_00.seg = *(uint16_t *)((int)&BldInstances[0].seg + iStack_e * 0xc);
                      gfx_00_00.ofs = ((bld_inst_t *)BldInstances + iStack_e)->ofs;
                      ovr_blit_usesBlitGfxN2
                                (gfx,gfx_00_00,
                                 (*(int *)(&mapSquareLeftX[sq]) * (5 - iStack_6)) / 5 +
                                 (*(int *)(&mapSquareRightX[sq]) * iStack_6) / 5,
                                 (int)(((uint)*(byte *)(iVar10 + 0x728) - iStack_1e) *
                                      (5 - iStack_6)) / 5 +
                                 (int)(((uint)*(byte *)(iVar10 + 0x728) - iStack_20) * iStack_6) / 5
                                 ,abStack_17[iVar10 + -1],iVar8,sqRight,abStack_17[iVar10],
                                 (brect_t *)BlitRects,0x2410,(byte)HighlightLevel,
                                 abStack_17[iVar10 + -1],(char)iVar8,(char)sqRight,abStack_17[iVar10],
                                 0x40,0x10);
                    }
                  }
                  if ((*(byte *)((uint8_t *)&BuildingTypes[iStack_e] + 16) & 10) != 0) {
                    if (*(int *)(&mapSquareLeftX[sq]) ==
                        *(int *)((int)&AgntAnms[0x5d].sx + 1 + sq * 2)) {
                      sqRight = (uint)*(byte *)(iVar10 + 0x729) - iStack_22;
                      iVar8 = (uint)*(byte *)(iVar10 + 0x728) - iStack_1e;
                      iVar2 = *(int16_t *)(&mapSquareLeftX[sq]);
                      gfx_04.seg = *(uint16_t *)
                                    ((char *)0x28ed6 + iStack_e * 0xc);
                      gfx_04.ofs = *(uint16_t *)
                                    ((char *)0x28ed4 + iStack_e * 0xc);
                      ovr_blit_usesBlitGfxN
                                (gfx_04,iVar2,iVar8,abStack_17[iVar10 + -1],sqRight,abStack_17[iVar10]
                                 ,(brect_t *)BlitRects,0x2410,(char)iVar2,(char)iVar8,
                                 abStack_17[iVar10 + -1],(char)sqRight,abStack_17[iVar10],0x40,0x10);
                    }
                    else {
                      iVar8 = ((uint16_t *)ScreenOriginX)[iVar10] - iStack_22;
                      sqRight = *(int *)((int)&AgntAnms[0x5d].sx + 1 + sq * 2);
                      gfx_01.seg = *(uint16_t *)
                                    ((char *)0x28ed2 + iStack_e * 0xc);
                      gfx_01.ofs = *(uint16_t *)
                                    ((char *)0x28ed0 + iStack_e * 0xc);
                      ovr_blit_usesStExit(gfx_01,*(int *)(&mapSquareLeftX[sq]),
                                          ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e,
                                          abStack_17[iVar10 + -1],sqRight,iVar8,abStack_17[iVar10],
                                          &((brect_t *)BlitRects)->x,abStack_17[iVar10 + -1],
                                          (char)sqRight,(char)iVar8,abStack_17[iVar10],0x40,0x10,0);
                    }
                  }
                  if ((*(byte *)((uint8_t *)&BuildingTypes[iStack_e] + 16) & 8) != 0) {
                    if (*(int *)(&mapSquareBottomY[sq]) == *(int *)(&mapSquareRightX[sq])) {
                      sqRight = (uint)*(byte *)(iVar10 + 0x729) - iStack_24;
                      iVar8 = (uint)*(byte *)(iVar10 + 0x728) - iStack_20;
                      iVar2 = *(int16_t *)(&mapSquareRightX[sq]);
                      gfx_05.seg = *(uint16_t *)
                                    ((char *)0x28ed6 + iStack_e * 0xc);
                      gfx_05.ofs = *(uint16_t *)
                                    ((char *)0x28ed4 + iStack_e * 0xc);
                      ovr_blit_usesBlitGfxN
                                (gfx_05,iVar2,iVar8,abStack_17[iVar10 + -1],sqRight,abStack_17[iVar10]
                                 ,(brect_t *)BlitRects,0x2410,(char)iVar2,(char)iVar8,
                                 abStack_17[iVar10 + -1],(char)sqRight,abStack_17[iVar10],0x40,0x10);
                    }
                    else {
                      iVar8 = ((uint16_t *)ScreenOriginX)[iVar10] - iStack_24;
                      sqRight = *(int *)(&mapSquareBottomY[sq]);
                      gfx_02.seg = *(uint16_t *)
                                    ((char *)0x28ed2 + iStack_e * 0xc);
                      gfx_02.ofs = *(uint16_t *)
                                    ((char *)0x28ed0 + iStack_e * 0xc);
                      ovr_blit_usesStExit(gfx_02,*(int *)(&mapSquareRightX[sq]),
                                          ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20,
                                          abStack_17[iVar10 + -1],sqRight,iVar8,abStack_17[iVar10],
                                          &((brect_t *)BlitRects)->x,abStack_17[iVar10 + -1],
                                          (char)sqRight,(char)iVar8,abStack_17[iVar10],0x40,0x10,0);
                    }
                  }
                  if (((*(byte *)((uint8_t *)&BuildingTypes[iStack_e] + 16) & 4) != 0) ||
                     (((*(byte *)((uint8_t *)&BuildingTypes[iStack_e] + 16) & 1) != 0 && (iVar10 != 0)))) {
                    iVar8 = ((uint16_t *)ScreenOriginY)[iVar10] - iStack_20;
                    sqRight = *(int *)(&mapSquareRightX[sq]);
                    gfx_03.seg = *(uint16_t *)
                                  ((char *)0x28ed2 + iStack_e * 0xc);
                    gfx_03.ofs = *(uint16_t *)
                                  ((char *)0x28ed0 + iStack_e * 0xc);
                    ovr_blit_usesStExit(gfx_03,*(int *)(&mapSquareLeftX[sq]),
                                        ((uint16_t *)ScreenOriginY)[iVar10] - iStack_1e,
                                        abStack_17[iVar10 + -1],sqRight,iVar8,abStack_17[iVar10 + -1],
                                        &((brect_t *)BlitRects)->x,abStack_17[iVar10 + -1],
                                        (char)sqRight,(char)iVar8,abStack_17[iVar10 + -1],0x40,0x10,0)
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
    for (sq = rowMapSquareFirst[0]; (int)sq < (int)rowMapSquareEnd[0]; sq = sq + 1)
    {
      if ((0xb < *(int *)(&mapSquareRightX[sq])) && (*(int *)(&mapSquareLeftX[sq]) < 0xdf)) {
        sqCol = *(uint16_t *)(&mapSquareColumn[sq]);
        iStack_1a = constr_usesSmoothPrev(sqCol,-1,(int *)&cornerBL,0xff,(char)&cornerBL);
        iStack_1c = constr_usesSmoothPrev(sqCol + 1,-1,(int *)&cornerBR,0xff,(char)&cornerBR);
        uVar4 = constr_getFlagsAtOffset(sqCol,-1);
        bStack_b = (byte)uVar4;
        iVar8 = ScreenOriginY[0] - iStack_1a;
        iVar10 = *(int *)(&mapSquareRightX[sq]);
        sqRight = *(int *)(&mapSquareLeftX[sq]);
        for (iStack_34 = *(int *)(&mapSquareLeftX[sq]); iStack_34 <= *(int *)(&mapSquareRightX[sq]);
            iStack_34 = iStack_34 + 1) {
          if ((0xb < iStack_34) && (iStack_34 < 0xdf)) {
            *(int *)((iStack_34 + -0xc) * 2 + 0x34c) =
                 iVar8 + ((iStack_1a - iStack_1c) * (iStack_34 - *(int *)(&mapSquareLeftX[sq]))) /
                         (iVar10 - sqRight);
            *(int *)((iStack_34 + -0xc) * 2 + 0x1a6) = -(iStack_1a - iStack_1c);
            if ((uVar4 & 3) == 0) {
              *(uint16_t *)((iStack_34 + -0xc) * 2) = 1;
            }
            else {
              *(uint16_t *)((iStack_34 + -0xc) * 2) = 0;
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
      uVar4 = ovr_alignUp4(GfxRndSeed,(char)GfxRndSeed2,0);
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
  ovr_miceRestoreArea((brect_t *)BlitRects,0);
  ovr_miceRestoreArea((brect_t *)(BlitRects + 3),0);
  constr_usesAgnt_clear();
  ovr_miceBlitRect((brect_t *)BlitRects,0);
  blitRect((brect_t *)BlitRects,0);
  ovr_miceUpdate();
  ovr_miceBlitRect((brect_t *)(BlitRects + 3),0);
  blitRect((brect_t *)(BlitRects + 3),0);
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
  ovr_miceRestoreArea((brect_t *)(BlitRects + 3),0);
  constr_usesBlitGfxRect2();
  ovr_miceBlitRect((brect_t *)(BlitRects + 3),0);
  blitRect((brect_t *)(BlitRects + 3),0);
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
  blitRect((brect_t *)BlitRects,0);
  blitRect((brect_t *)(BlitRects + 3),0);
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
  uint16_t gfxSeg;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  bool textArenaDrawn;
  byte bVar3;
  uint uVar4;
  undefined1 extraout_AH;
  int iVar5;
  undefined1 extraout_AH_00;
  int dy;
  uint16_t sq;
  uint16_t uVar7;
  uint16_t unaff_SS;
  far_t gfx_08;
  far_t gfx_09;
  far_t gfx_10;
  far_t gfx_11;
  ulong uVar8;
  far_t dst_00;
  ulong uVar9;
  uint fillColor;
  int avgDy;
  uint8_t cornerBR;
  uint8_t cornerBL;
  uint8_t cornerTR;
  uint8_t cornerTL;
  int smoothBR;
  int smoothBL;
  int smoothTR;
  int smoothTL;
  int smoothRight;
  int smoothLeft;
  int bldIndex;
  uint8_t bandY[4];   /* per-band Y offsets, F_SCOPY'd from 2410:074f */
  int scrollOfs;
  uint rowBase;
  
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)bandY;
  F_SCOPY(far_from_u32((uint32_t)(0x2410074f)),dst_00);
  textArenaDrawn = ovr_draw_textArena();
  if (textArenaDrawn) {
    scrollOfs = GfxRndSeed * 6 >> 6;
    if (0xee < 0x166 - scrollOfs) {
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) =
           (char)((uint16_t *)&l1Cut1Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      gfx_02.ofs = ((uint16_t *)&l1Cut1Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) =
           (char)((uint)((uint16_t *)&l1Cut1Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4] >> 8
                 );
      ovr_blitGfxRect(gfx_02,0xef - scrollOfs,7,(brect_t *)(BlitRects + 3),0x10,true,0,0,0,0,0,0);
    }
    if (0x167 - scrollOfs < 0x135) {
      (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) =
           (char)((uint16_t *)&l1Cut3Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      gfx_03.ofs = ((uint16_t *)&l1Cut3Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) =
           (char)((uint)((uint16_t *)&l1Cut3Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4] >> 8
                 );
      ovr_blitGfxRect(gfx_03,0x22f - scrollOfs,7,(brect_t *)(BlitRects + 3),0x10,true,0,0,0,0,0,0);
    }
    ovr_driver_fillRect(0xef,0x1d,0x134,0x24,0xf0,BlitRects[3].seg,0,0,0,0,0);
    constr_usesSmoothPrev2();
    for (dy = 2; sq = rowBandSquareFirst[0], -1 < dy; dy = dy + -1) {
      for (sq = ((uint16_t *)rowBandSquareFirst)[dy];
          (int)sq < (int)((uint16_t *)rowBandSquareEnd)[dy]; sq = sq + 1) {
        uVar7 = ((uint16_t *)squareColumn)[sq];
        smoothTL = constr_usesSmoothPrev(uVar7,dy + -1,(int *)&cornerTL,0,0);
        smoothTL = smoothTL / 3;
        smoothTR = constr_usesSmoothPrev(uVar7 + 1,dy + -1,(int *)&cornerTR,0,0);
        smoothTR = smoothTR / 3;
        smoothBL = constr_usesSmoothPrev(uVar7,dy,(int *)&cornerBL,0,0);
        smoothBL = smoothBL / 3;
        smoothBR = constr_usesSmoothPrev(uVar7 + 1,dy,(int *)&cornerBR,0,0);
        smoothBR = smoothBR / 3;
        uVar4 = constr_getFlagsAtOffset(uVar7,dy);
        bVar3 = (byte)uVar4;
        if ((uVar4 & 4) == 0) {
          if ((int)uVar7 < 0) {
            uVar9 = CONCAT22(1,uVar4) & 0xffff00ff;
            uVar8 = (ulong)CONCAT12(cornerBL,cornerTR) & 0xffff00ff;
            uVar4 = constr_compute1(cornerTL,(uint8_t)uVar8,(uint8_t)(uVar8 >> 0x10),(byte)uVar9,(byte)(uVar9 >> 0x10),0,0,0);
            ovr_ovc07_usesBiosReadKey
                      (((uint16_t *)SquareTopY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBL,((uint16_t *)SquareLeftX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTL,((uint16_t *)SquareRightX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTR,uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareLeftX)[sq],0,0,0,0,0);
            uVar4 = constr_compute1(cornerBL,cornerBR,cornerTR,bVar3,2,0,0,0);
            ovr_ovc07_usesBiosReadKey
                      (((uint16_t *)SquareTopY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBL,((uint16_t *)SquareBottomY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBR,((uint16_t *)SquareRightX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTR,uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareBottomY)[sq],0,0,0,0,0);
          }
          else {
            uVar8 = CONCAT22(2,uVar4) & 0xffff00ff;
            uVar4 = constr_compute1(cornerBL,cornerBR,(uint8_t)cornerTR,(byte)uVar8,(byte)(uVar8 >> 0x10),0,0,0);
            ovr_ovc07_usesBiosReadKey
                      (((uint16_t *)SquareTopY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBL,((uint16_t *)SquareBottomY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBR,((uint16_t *)SquareRightX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTR,uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareBottomY)[sq],0,0,0,0,0);
            uVar4 = constr_compute1(cornerTL,cornerTR,cornerBL,bVar3,1,0,0,0);
            ovr_ovc07_usesBiosReadKey
                      (((uint16_t *)SquareTopY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBL,((uint16_t *)SquareLeftX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTL,((uint16_t *)SquareRightX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTR,uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareLeftX)[sq],0,0,0,0,0);
          }
        }
        else if ((int)uVar7 < 0) {
          uVar8 = CONCAT22(1,uVar4) & 0xffff00ff;
          uVar4 = constr_compute1(cornerBL,cornerBR,cornerTL,(byte)uVar8,(byte)(uVar8 >> 0x10),0,0,0);
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareTopY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBL,((uint16_t *)SquareBottomY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBR,((uint16_t *)SquareLeftX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTL,uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareBottomY)[sq],0,0,0,0,0);
          uVar4 = constr_compute1(cornerTL,cornerTR,cornerBR,bVar3,2,0,0,0);
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareBottomY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBR,((uint16_t *)SquareLeftX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTL,((uint16_t *)SquareRightX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTR,uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareLeftX)[sq],0,0,0,0,0);
        }
        else {
          uVar9 = CONCAT22(2,uVar4) & 0xffff00ff;
          uVar8 = (ulong)CONCAT12(cornerBR,cornerTR) & 0xffff00ff;
          uVar4 = constr_compute1(cornerTL,(uint8_t)uVar8,(uint8_t)(uVar8 >> 0x10),(byte)uVar9,(byte)(uVar9 >> 0x10),0,0,0);
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareBottomY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBR,((uint16_t *)SquareLeftX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTL,((uint16_t *)SquareRightX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTR,uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareLeftX)[sq],0,0,0,0,0);
          uVar4 = constr_compute1(cornerBL,cornerBR,cornerTL,bVar3,1,0,0,0);
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareTopY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBL,((uint16_t *)SquareBottomY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBR,((uint16_t *)SquareLeftX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTL,uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareBottomY)[sq],0,0,0,0,0);
        }
      }
      for (sq = ((uint16_t *)rowBandSquareFirst)[dy];
          (int)sq < (int)((uint16_t *)rowBandSquareEnd)[dy]; sq = sq + 1) {
        uVar7 = ((uint16_t *)squareColumn)[sq];
        bVar3 = constr_setHighlightAtOffset(uVar7,dy,0);
        bldIndex = CONCAT11(extraout_AH,bVar3);
        if (bldIndex != 0) {
          smoothTL = constr_usesSmoothPrev(uVar7,dy + -1,(int *)&cornerTL,0,0);
          smoothTL = smoothTL / 3;
          smoothBL = constr_usesSmoothPrev(uVar7,dy,(int *)&cornerBL,0,0);
          smoothBL = smoothBL / 3;
          if (*(byte *)((uint8_t *)&BuildingTypes[bldIndex] + 13) < 2) {
            smoothTR = constr_usesSmoothPrev(uVar7 + 1,dy + -1,(int *)&cornerTR,0,0);
            smoothTR = smoothTR / 3;
            smoothBR = constr_usesSmoothPrev(uVar7 + 1,dy,(int *)&cornerBR,0,0);
            smoothBR = smoothBR / 3;
          }
          else if (*(byte *)((uint8_t *)&BuildingTypes[bldIndex] + 13) < 3) {
            smoothTR = constr_usesSmoothPrev(uVar7 + 2,dy + -1,(int *)&cornerTR,0,0);
            smoothTR = smoothTR / 3;
            smoothBR = constr_usesSmoothPrev(uVar7 + 2,dy,(int *)&cornerBR,0,0);
            smoothBR = smoothBR / 3;
          }
          else {
            smoothTR = constr_usesSmoothPrev(uVar7 + 4,dy + -1,(int *)&cornerTR,0,0);
            smoothTR = smoothTR / 3;
            smoothBR = constr_usesSmoothPrev(uVar7 + 4,dy,(int *)&cornerBR,0,0);
            smoothBR = smoothBR / 3;
          }
          avgDy = smoothBL + smoothTL + smoothTR + smoothBR >> 2;
          rowBase = (uint)*(byte *)(dy + 0x73e);
          if ((int)(smoothTL - rowBase) < (int)(smoothTR - rowBase)) {
            iVar5 = smoothTL - rowBase;
          }
          else {
            iVar5 = smoothTR - rowBase;
          }
          if (avgDy < iVar5) {
            if ((int)(smoothTL - rowBase) < (int)(smoothTR - rowBase)) {
              avgDy = smoothTL - rowBase;
            }
            else {
              avgDy = smoothTR - rowBase;
            }
          }
          if (*(char *)((uint8_t *)&BuildingTypes[bldIndex] + 16) == '\0') {
            if ((*(uint *)((uint8_t *)&BuildingTypes[bldIndex] + 19) & 0x20) == 0) {
              iVar5 = bldIndex * 0xc + ((uint16_t *)squareSide)[sq] * 4;
              if (((*(int *)(iVar5 + 0x4230) == 0 && *(int *)(iVar5 + 0x4232) == 0) || (1 < dy)) ||
                 (7 < HighlightLevel)) {
                iVar5 = bldIndex * 0xc + ((uint16_t *)squareSide)[sq] * 4;
                (*(uint8_t *)((uint8_t *)&(gfx_06.seg))) =
                     (char)*(uint16_t *)
                            ((char *)0x28ed2 + iVar5);
                gfx_06.ofs = *(uint16_t *)
                              ((char *)0x28ed0 + iVar5);
                (*(uint8_t *)((uint8_t *)&(gfx_06.seg) + 1)) =
                     (char)((uint)*(uint16_t *)
                                   ((char *)0x28ed2 + iVar5) >> 8);
                ovr_blitGfxRect(gfx_06,((uint16_t *)SquareLeftX)[sq],(uint)*(byte *)(dy + 0x74b) - avgDy,(brect_t *)(BlitRects + 3),0x10,bandY[2 - dy],0,0,0,0,0,0);
              }
              else {
                iVar5 = bldIndex * 0xc + ((uint16_t *)squareSide)[sq] * 4;
                gfxSeg = *(uint16_t *)(iVar5 + 0x4232);
                (*(uint8_t *)((uint8_t *)&(gfx_05.seg))) = (char)gfxSeg;
                gfx_05.ofs = *(uint16_t *)(iVar5 + 0x4230);
                (*(uint8_t *)((uint8_t *)&(gfx_05.seg) + 1)) = (char)((uint)gfxSeg >> 8);
                ovr_blitGfxRect(gfx_05,((uint16_t *)SquareLeftX)[sq],(uint)*(byte *)(dy + 0x74b) - avgDy,(brect_t *)(BlitRects + 3),0x10,bandY[2 - dy],0,0,0,0,0,0);
                if (1 < HighlightLevel) {
                  iVar5 = bldIndex * 0xc + ((uint16_t *)squareSide)[sq] * 4;
                  gfx_08.seg = *(uint16_t *)
                                ((char *)0x28ed2 + iVar5);
                  gfx_08.ofs = *(uint16_t *)
                                ((char *)0x28ed0 + iVar5);
                  ovr_gfxRlePrepare(gfx_08,((uint16_t *)SquareLeftX)[sq],(uint)*(byte *)(dy + 0x74b) - avgDy,&((brect_t *)(BlitRects + 3))->x,'\x10',bandY[2 - dy],0x5e,0,0,HighlightLevel * 0xff >> 3,0,0,0);
                }
              }
            }
            else {
              iVar5 = bldIndex * 0xc + (uint)GSeason * 4;
              (*(uint8_t *)((uint8_t *)&(gfx_04.seg))) =
                   (char)*(uint16_t *)
                          ((char *)0x28ed2 + iVar5);
              gfx_04.ofs = *(uint16_t *)
                            ((char *)0x28ed0 + iVar5);
              (*(uint8_t *)((uint8_t *)&(gfx_04.seg) + 1)) =
                   (char)((uint)*(uint16_t *)
                                 ((char *)0x28ed2 + iVar5) >> 8);
              ovr_blitGfxRect(gfx_04,((uint16_t *)SquareLeftX)[sq],(uint)*(byte *)(dy + 0x74b) - avgDy,(brect_t *)(BlitRects + 3),0x10,bandY[2 - dy],0,0,0,0,0,0);
            }
          }
          else {
            if ((*(byte *)((uint8_t *)&BuildingTypes[bldIndex] + 16) & 10) != 0) {
              if (((uint16_t *)SquareLeftX)[sq] == ((uint16_t *)SquareTopY)[sq]) {
                gfx.seg = *(uint16_t *)
                           ((char *)0x28ed6 + bldIndex * 0xc);
                gfx.ofs = *(uint16_t *)
                           ((char *)0x28ed4 + bldIndex * 0xc);
                ovr_blit_usesBlitGfxN
                          (gfx,((uint16_t *)SquareLeftX)[sq],(uint)*(byte *)(dy + 0x74b) - smoothTL,bandY[2 - dy],(uint)*(byte *)(dy + 0x74c) - smoothBL,bandY[1 + dy],(brect_t *)(BlitRects + 3),0x2410,(char)((uint16_t *)SquareLeftX)[sq],0,0,0,0,0,0)
                ;
              }
              else {
                gfx_09.seg = *(uint16_t *)
                              ((char *)0x28ed2 + bldIndex * 0xc);
                gfx_09.ofs = *(uint16_t *)
                              ((char *)0x28ed0 + bldIndex * 0xc);
                ovr_blit_usesStExit(gfx_09,((uint16_t *)SquareLeftX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTL,bandY[2 - dy],((uint16_t *)SquareTopY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBL,bandY[1 + dy],&((brect_t *)(BlitRects + 3))->x,bandY[2 - dy],0x2410,0,0,0,0,0);
              }
            }
            if ((*(byte *)((uint8_t *)&BuildingTypes[bldIndex] + 16) & 8) != 0) {
              if (((uint16_t *)SquareBottomY)[sq] == ((uint16_t *)SquareRightX)[sq]) {
                gfx_00.seg = *(uint16_t *)
                              ((char *)0x28ed6 + bldIndex * 0xc);
                gfx_00.ofs = *(uint16_t *)
                              ((char *)0x28ed4 + bldIndex * 0xc);
                ovr_blit_usesBlitGfxN
                          (gfx_00,((uint16_t *)SquareRightX)[sq],(uint)*(byte *)(dy + 0x74b) - smoothTR,bandY[2 - dy],(uint)*(byte *)(dy + 0x74c) - smoothBR,bandY[1 + dy],(brect_t *)(BlitRects + 3),0x2410,(char)((uint16_t *)SquareRightX)[sq],0,0,0,0,0,0);
              }
              else {
                gfx_10.seg = *(uint16_t *)
                              ((char *)0x28ed2 + bldIndex * 0xc);
                gfx_10.ofs = *(uint16_t *)
                              ((char *)0x28ed0 + bldIndex * 0xc);
                ovr_blit_usesStExit(gfx_10,((uint16_t *)SquareRightX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTR,bandY[2 - dy],((uint16_t *)SquareBottomY)[sq],((uint16_t *)RowScreenX)[dy] - smoothBR,bandY[1 + dy],&((brect_t *)(BlitRects + 3))->x,bandY[2 - dy],0x2410,0,0,0,0,0);
              }
            }
            if (((*(byte *)((uint8_t *)&BuildingTypes[bldIndex] + 16) & 4) != 0) ||
               (((*(byte *)((uint8_t *)&BuildingTypes[bldIndex] + 16) & 1) != 0 && (dy != 0)))) {
              gfx_11.seg = *(uint16_t *)
                            ((char *)0x28ed2 + bldIndex * 0xc);
              gfx_11.ofs = *(uint16_t *)
                            ((char *)0x28ed0 + bldIndex * 0xc);
              ovr_blit_usesStExit(gfx_11,((uint16_t *)SquareLeftX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTL,bandY[2 - dy],((uint16_t *)SquareRightX)[sq],((uint16_t *)RowScreenY)[dy] - smoothTR,bandY[2 - dy],&((brect_t *)(BlitRects + 3))->x,bandY[2 - dy],0x2410,0,0,0,0,0);
            }
          }
        }
      }
    }
    for (; uVar7 = rowBandSquareFirst[0], (int)sq < (int)rowBandSquareEnd[0]; sq = sq + 1)
    {
      if ((0xee < (int)((uint16_t *)SquareRightX)[sq]) &&
         ((int)((uint16_t *)SquareLeftX)[sq] < 0x135)) {
        uVar7 = ((uint16_t *)squareColumn)[sq];
        cornerTL = constr_getCellAtOffset(uVar7,-2);
        cornerTR = constr_getCellAtOffset(uVar7 + 1,-2);
        smoothLeft = constr_usesSmoothPrev(uVar7,-1,(int *)&cornerBL,0,0);
        smoothLeft = smoothLeft / 3;
        smoothRight = constr_usesSmoothPrev(uVar7 + 1,-1,(int *)&cornerBR,0,0);
        smoothRight = smoothRight / 3;
        uVar4 = constr_getFlagsAtOffset(uVar7,-1);
        bVar3 = (byte)uVar4;
        if ((uVar4 & 4) == 0) {
          fillColor = constr_compute2(cornerBL,cornerBR,cornerTR,bVar3,2);
          fillColor = fillColor & 0xff;
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareLeftX)[sq],RowScreenY[0] - smoothLeft,((uint16_t *)SquareRightX)[sq],RowScreenY[0] - smoothRight,((uint16_t *)SquareRightX)[sq],0x36,fillColor,BlitRects + 3,(char)((uint16_t *)SquareRightX)[sq],0,0,0,0,0);
          uVar4 = constr_compute2(cornerTL,cornerTR,cornerBL,bVar3,1);
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareLeftX)[sq],RowScreenY[0] - smoothLeft,((uint16_t *)SquareLeftX)[sq],0x36,((uint16_t *)SquareRightX)[sq],0x36,uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareLeftX)[sq],0,0,0,0,0);
        }
        else {
          fillColor = constr_compute2(cornerBL,cornerBR,cornerTL,bVar3,1);
          fillColor = fillColor & 0xff;
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareLeftX)[sq],RowScreenY[0] - smoothLeft,((uint16_t *)SquareRightX)[sq],RowScreenY[0] - smoothRight,((uint16_t *)SquareLeftX)[sq],0x36,fillColor,BlitRects + 3,(char)((uint16_t *)SquareRightX)[sq],0,0,0,0,0);
          uVar4 = constr_compute2(cornerTL,cornerTR,cornerBR,bVar3,2);
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)SquareRightX)[sq],RowScreenY[0] - smoothRight,((uint16_t *)SquareLeftX)[sq],0x36,((uint16_t *)SquareRightX)[sq],0x36,uVar4 & 0xff,BlitRects + 3,(char)((uint16_t *)SquareLeftX)[sq],0,0,0,0,0);
        }
        uVar4 = constr_usesGMapFlags(uVar7 + GfxRndSeed,GfxRndSeed2,0);
        if ((char)uVar4 != '\0') {
          ovr_ovc07_usesLDIV_at_
                    (((uint16_t *)SquareLeftX)[sq],RowScreenY[0] - smoothLeft,((uint16_t *)SquareRightX)[sq],RowScreenY[0] - smoothRight,(char)fillColor + 0xff,(brect_t *)(BlitRects + 3),0);
        }
      }
    }
    for (; (int)uVar7 < (int)rowBandSquareEnd[0]; uVar7 = uVar7 + 1) {
      sq = ((uint16_t *)squareColumn)[uVar7];
      bVar3 = constr_setHighlightAtOffset(sq,0,0);
      bldIndex = CONCAT11(extraout_AH_00,bVar3);
      if ((*(byte *)((uint8_t *)&BuildingTypes[bldIndex] + 16) & 2) != 0) {
        smoothLeft = constr_usesSmoothPrev(sq,-1,(int *)&cornerBL,0,0);
        smoothLeft = smoothLeft / 3;
        gfx_01.seg = *(uint16_t *)
                      ((char *)0x28ed6 + bldIndex * 0xc);
        gfx_01.ofs = *(uint16_t *)
                      ((char *)0x28ed4 + bldIndex * 0xc);
        ovr_blit_usesBlitGfxN
                  (gfx_01,((uint16_t *)SquareLeftX)[uVar7],(uint)rowBandOrigin[0] - smoothLeft,6,0x27,6,(brect_t *)(BlitRects + 3),0x2410,(char)((uint16_t *)SquareLeftX)[uVar7],0,0,0,0,0,0);
      }
      if ((*(byte *)((uint8_t *)&BuildingTypes[bldIndex] + 16) & 1) != 0) {
        (*(uint8_t *)((uint8_t *)&(gfx_07.seg))) =
             (char)*(uint16_t *)
                    ((char *)0x28eda + bldIndex * 0xc);
        gfx_07.ofs = *(uint16_t *)
                      ((char *)0x28ed8 + bldIndex * 0xc);
        (*(uint8_t *)((uint8_t *)&(gfx_07.seg) + 1)) =
             (char)((uint)*(uint16_t *)
                           ((char *)0x28eda + bldIndex * 0xc) >> 8);
        ovr_blitGfxRect(gfx_07,((uint16_t *)SquareLeftX)[uVar7],51,(brect_t *)(BlitRects + 3),0x10,bandY[2],0,0,0,0,0,0);
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

uint __cdecl16far constr_usesGMapFlags(int x,int y,uint16_t arg3)

{
  uint in_AX;
  uint uVar1;
  short *psVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  uint16_t uVar6;
  int iStack_4;
  
  if ((((x < 0) || (y < 0)) || (in_AX = x + 1, 0x93 < (int)in_AX)) ||
     (in_AX = y + 1, 0x3b < (int)in_AX)) {
    placementStatus = 2;
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar6 = (uint16_t)((ulong)GMapFlags >> 0x10);
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

uint __cdecl16far constr_usesGMapFlags2(int x,int y)

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
  uint16_t uVar5;
  byte bStack_4;
  byte bStack_3;
  
  uVar5 = (uint16_t)((ulong)GMapFlags >> 0x10);
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


