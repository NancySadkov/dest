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
  int in_stack_00000004;
  
  iVar1 = constr_getCellAtOffset(in_stack_00000004,dx);
  *(int *)CONCAT22((int *)cell,dy) = iVar1;
  iVar1 = (*(int *)CONCAT22((int *)cell,dy) - SmoothPrev) * 3;
  if (iVar1 < 0) {
    iVar1 = (int)(iVar1 * (uint)*(byte *)(dx + 0x733)) / 0x10;
  }
  else {
    iVar1 = (int)(iVar1 * (uint)*(byte *)(dx + 0x733)) >> 4;
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
  int in_stack_00000004;
  
  if ((((in_stack_00000004 + GfxRndSeed < 0x94) &&
       (SCARRY2(in_stack_00000004,GfxRndSeed) == in_stack_00000004 + GfxRndSeed < 0)) &&
      (GfxRndSeed2 - dx < 0x3c)) && (dx <= GfxRndSeed2)) {
    uVar2 = (undefined2)((ulong)GUnitGrid >> 0x10);
    uVar3 = (undefined2)((ulong)GUnits >> 0x10);
    HighlightLevel =
         (uint)((unit_t *)GUnits)
               [*(int *)((int)(short (*) [148] [60])GUnitGrid +
                        (GfxRndSeed2 - dx) * 2 + (in_stack_00000004 + GfxRndSeed) * 0x78)].level;
    bVar1 = ((unit_t *)GUnits +
            *(int *)((int)(short (*) [148] [60])GUnitGrid +
                    (GfxRndSeed2 - dx) * 2 + (in_stack_00000004 + GfxRndSeed) * 0x78))->bldType;
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
  undefined2 unaff_DI;
  int *unaff_SS;
  int *piVar3;
  uint8_t cell;
  int iStack_4;
  
  SmoothPrev = 0;
  piVar3 = (int *)CONCAT22(unaff_DI,unaff_SS);
  iVar1 = constr_usesSmoothPrev(0xffff,(int)&cell,piVar3,0xffff);
  piVar3 = (int *)CONCAT22((int)((ulong)piVar3 >> 0x10),unaff_SS);
  iStack_4 = iVar1;
  iVar2 = constr_usesSmoothPrev(0xffff,(int)&cell,piVar3,0);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  if (iStack_4 < iVar2) {
    iStack_4 = iVar2;
  }
  piVar3 = (int *)CONCAT22((int)((ulong)piVar3 >> 0x10),unaff_SS);
  iVar2 = constr_usesSmoothPrev(0xffff,(int)&cell,piVar3,1);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  if (iStack_4 < iVar2) {
    iStack_4 = iVar2;
  }
  piVar3 = (int *)CONCAT22((int)((ulong)piVar3 >> 0x10),unaff_SS);
  iVar2 = constr_usesSmoothPrev(0xffff,(int)&cell,piVar3,2);
  if (iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  iVar2 = constr_usesSmoothPrev
                    (0xffff,(int)&cell,(int *)CONCAT22((int)((ulong)piVar3 >> 0x10),unaff_SS),0xfffe
                    );
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
  uint16_t unaff_BP;
  undefined2 *in_stack_00000004;
  
  ovr_blitRaw(in_stack_00000004[1],in_stack_00000004[2],in_stack_00000004[3],in_stack_00000004[4],
              0xa000,unaff_BP,*(undefined2 *)CONCAT22((brect_t *)br,in_stack_00000004));
  return;
}



/* 36ce:0345 */

/* Restores the mouse area, blits a raw rect to the 0xa000 screen and blits the mouse back. */

void __cdecl16far constr_blitRawToScreen(brect_t *rect)

{
  uint16_t srcSeg;
  brect_t *pbVar1;
  undefined2 unaff_SI;
  brect_t *pbVar2;
  brect_t *br;
  uint16_t dstSeg;
  
  pbVar2 = (brect_t *)((ulong)rect >> 0x10);
  pbVar1 = (brect_t *)rect;
  srcSeg = pbVar1->seg;
  pbVar1->seg = 0xa000;
  br = (brect_t *)CONCAT22(unaff_SI,pbVar2);
  ovr_miceRestoreArea(br,pbVar1);
  dstSeg = (uint16_t)((ulong)br >> 0x10);
  ovr_blitRaw(pbVar1->y,pbVar1->w,pbVar1->h,0xa000,srcSeg,dstSeg,rect->x);
  ovr_miceBlitRect((brect_t *)CONCAT22(dstSeg,pbVar2),pbVar1);
  pbVar1->seg = srcSeg;
  return;
}



/* 36ce:03a6 */

/* [R4] calls blitRect */

void __cdecl16far constr_usesBlitRect(void...)

{
  bool bVar1;
  void *pvVar2;
  uint16_t in_DX;
  uint unaff_SI;
  uint32_t nbytes;
  far_t ptr;
  brect_t *pbVar3;
  undefined2 uVar4;
  uint16_t uVar5;
  far_t handle;
  
  nbytes = (ulong)unaff_SI << 0x10;
  pvVar2 = ovr_stshAlloc(nbytes,0xfa0f);
  ptr.seg = (uint16_t)(nbytes >> 0x10);
  ptr.ofs = in_DX;
  ovr_alignToSeg(ptr,pvVar2);
  uVar5 = ptr.seg;
  if (GOngoingBattle != '\0') {
    pbVar3 = (brect_t *)CONCAT22(uVar5,(brect_t *)((char *)"puppetmaker" + 3));
    ovr_miceRestoreArea(pbVar3,0x440);
    uVar4 = (undefined2)((ulong)pbVar3 >> 0x10);
    ovr_ovc13_usesAlignUp4();
    pbVar3 = (brect_t *)CONCAT22(uVar4,(brect_t *)((char *)"puppetmaker" + 3));
    ovr_miceBlitRect(pbVar3,0x440);
    pbVar3 = (brect_t *)
             CONCAT22((int)((ulong)pbVar3 >> 0x10),(brect_t *)((char *)"puppetmaker" + 3));
    blitRect(pbVar3,0x440);
    uVar5 = (uint16_t)((ulong)pbVar3 >> 0x10);
    ovr_miceUpdate();
    BlitRects[0].seg = 0xa000;
  }
  if (GOngoingBattle != '\0') {
    bVar1 = ovr_draw_textArena();
    if (bVar1) goto L_constr_36ce_03a6_0489;
  }
  pbVar3 = (brect_t *)CONCAT22(uVar5,(brect_t *)((char *)"puppetmaker" + 3));
  ovr_miceRestoreArea(pbVar3,0x45e);
  uVar4 = (undefined2)((ulong)pbVar3 >> 0x10);
  ovr_ovc13_usesBlitRects();
  pbVar3 = (brect_t *)CONCAT22(uVar4,(brect_t *)((char *)"puppetmaker" + 3));
  ovr_miceBlitRect(pbVar3,0x45e);
  pbVar3 = (brect_t *)CONCAT22((int)((ulong)pbVar3 >> 0x10),(brect_t *)((char *)"puppetmaker" + 3));
  blitRect(pbVar3,0x45e);
  uVar5 = (uint16_t)((ulong)pbVar3 >> 0x10);
  ovr_miceUpdate();
  BlitRects[3].seg = 0xa000;
L_constr_36ce_03a6_0489:
  handle.seg = uVar5;
  handle.ofs = in_DX;
  ovr_stshFree(handle,pvVar2);
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
  undefined1 uVar3;
  undefined2 uVar2;
  undefined1 extraout_AH;
  char unaff_BP;
  undefined1 in_stack_00000004;
  
  uVar3 = (undefined1)((uint)in_AX >> 8);
  if ((cornerC & flags) == 0) {
    cVar1 = ovr_driver_compute1(cornerA,cornerB,unaff_BP,CONCAT11(uVar3,in_stack_00000004));
    uVar2 = CONCAT11(extraout_AH,cVar1);
  }
  else {
    uVar2 = CONCAT11(uVar3,0xe2);
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
  undefined1 uVar3;
  undefined2 uVar2;
  undefined1 extraout_AH;
  char unaff_BP;
  
  uVar3 = (undefined1)((uint)in_AX >> 8);
  if ((flags & bit) == 0) {
    cVar1 = ovr_driver_compute2(cornerB,cornerC,unaff_BP,CONCAT11(uVar3,cornerA));
    uVar2 = CONCAT11(extraout_AH,cVar1);
  }
  else {
    uVar2 = CONCAT11(uVar3,0xe2);
  }
  return uVar2;
}



/* 36ce:04e9 */

/* [R6] touches ScreenOriginY, GfxRndSeed */

void __cdecl16far constr_usesScreenOriginY(uint16_t rect,uint16_t type,...)

{
  ulong uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 extraout_AH;
  int iVar6;
  uint16_t unaff_SI;
  uint16_t uVar7;
  uint16_t uVar8;
  uint unaff_DI;
  int *unaff_SS;
  uint16_t in_stack_00000004;
  far_t gfx;
  undefined2 uVar11;
  int *piVar9;
  brect_t *pbVar10;
  uint8_t cellNext;
  uint8_t cell;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  piVar9 = (int *)((ulong)unaff_DI << 0x10);
  for (uVar7 = rowMapSquareFirst[0]; uVar8 = rowMapSquareFirst[0],
      (int)uVar7 < (int)rowMapSquareEnd[0]; uVar7 = uVar7 + 1) {
    if ((0xb < *(int *)(uVar7 * 2 + 0x6c0)) && (*(int *)(uVar7 * 2 + 0xa20) < 0xdf)) {
      iVar6 = *(int *)(uVar7 * 2 + 0x360);
      uVar11 = (undefined2)((ulong)piVar9 >> 0x10);
      iStack_6 = constr_getCellAtOffset(iVar6,-2);
      iStack_8 = constr_getCellAtOffset(iVar6 + 1,-2);
      piVar9 = (int *)CONCAT22(uVar11,unaff_SS);
      iVar3 = constr_usesSmoothPrev(0xffff,(int)&cell,piVar9,iVar6);
      piVar9 = (int *)CONCAT22((int)((ulong)piVar9 >> 0x10),unaff_SS);
      iVar4 = constr_usesSmoothPrev(0xffff,(int)&cellNext,piVar9,iVar6 + 1);
      uVar11 = (undefined2)((ulong)piVar9 >> 0x10);
      uVar5 = constr_getFlagsAtOffset(iVar6,-1);
      bVar2 = (byte)uVar5;
      if ((uVar5 & 4) == 0) {
        uVar5 = constr_compute2(cell,cellNext,(uint8_t)iStack_8,bVar2,2);
        pbVar10 = (brect_t *)CONCAT22(uVar11,rect);
        ovr_ovc07_usesBiosReadKey
                  (ScreenOriginY[0] - iVar3,*(int *)(uVar7 * 2 + 0x6c0),ScreenOriginY[0] - iVar4,
                   *(int *)(uVar7 * 2 + 0x6c0),0x96,uVar5 & 0xff,in_stack_00000004,pbVar10,
                   *(undefined2 *)(uVar7 * 2 + 0xa20));
        uVar11 = (undefined2)((ulong)pbVar10 >> 0x10);
        uVar5 = constr_compute2((uint8_t)iStack_6,(uint8_t)iStack_8,cell,bVar2,1);
        pbVar10 = (brect_t *)CONCAT22(uVar11,rect);
        ovr_ovc07_usesBiosReadKey
                  (ScreenOriginY[0] - iVar3,*(int *)(uVar7 * 2 + 0xa20),0x96,
                   *(int *)(uVar7 * 2 + 0x6c0),0x96,uVar5 & 0xff,in_stack_00000004,pbVar10,
                   *(undefined2 *)(uVar7 * 2 + 0xa20));
        iVar3 = (int)((ulong)pbVar10 >> 0x10);
      }
      else {
        uVar5 = constr_compute2(cell,cellNext,(uint8_t)iStack_6,bVar2,1);
        pbVar10 = (brect_t *)CONCAT22(uVar11,rect);
        ovr_ovc07_usesBiosReadKey
                  (ScreenOriginY[0] - iVar3,*(int *)(uVar7 * 2 + 0x6c0),ScreenOriginY[0] - iVar4,
                   *(int *)(uVar7 * 2 + 0xa20),0x96,uVar5 & 0xff,in_stack_00000004,pbVar10,
                   *(undefined2 *)(uVar7 * 2 + 0xa20));
        uVar11 = (undefined2)((ulong)pbVar10 >> 0x10);
        uVar5 = constr_compute2((uint8_t)iStack_6,(uint8_t)iStack_8,cellNext,bVar2,2);
        pbVar10 = (brect_t *)CONCAT22(uVar11,rect);
        ovr_ovc07_usesBiosReadKey
                  (ScreenOriginY[0] - iVar4,*(int *)(uVar7 * 2 + 0xa20),0x96,
                   *(int *)(uVar7 * 2 + 0x6c0),0x96,uVar5 & 0xff,in_stack_00000004,pbVar10,
                   *(undefined2 *)(uVar7 * 2 + 0x6c0));
        iVar3 = (int)((ulong)pbVar10 >> 0x10);
      }
      piVar9 = (int *)CONCAT22(iVar3,GfxRndSeed2);
      uVar5 = constr_usesGMapFlags((int)GfxRndSeed2,iVar3,iVar6 + GfxRndSeed);
      if ((char)uVar5 != '\0') {
        uVar11 = (undefined2)((ulong)piVar9 >> 0x10);
        ovr_ovc07_usesLDIV_at_();
        piVar9 = (int *)CONCAT22(uVar11,rect);
        ovr_ovc07_usesLDIV_at_();
      }
    }
  }
  for (; (int)uVar8 < (int)rowMapSquareEnd[0]; uVar8 = uVar8 + 1) {
    uVar11 = *(undefined2 *)(uVar8 * 2 + 0x360);
    uVar1 = (ulong)piVar9 >> 0x10;
    piVar9 = (int *)((ulong)piVar9 & 0xffff0000);
    bVar2 = constr_setHighlightAtOffset(0,(int)uVar1,uVar11);
    iStack_4 = CONCAT11(extraout_AH,bVar2);
    if (iStack_4 != 0) {
      piVar9 = (int *)CONCAT22((int)((ulong)piVar9 >> 0x10),unaff_SS);
      iVar6 = constr_usesSmoothPrev(0xffff,(int)&cell,piVar9,uVar11);
      if ((*(byte *)(iStack_4 * 0x27 + 0x11e) & 2) != 0) {
        pbVar10 = (brect_t *)CONCAT22((int)((ulong)piVar9 >> 0x10),rect);
        gfx.seg = *(uint16_t *)(uVar8 * 2 + 0xa20);
        gfx.ofs = *(uint16_t *)
                   ((char *)
                    "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                    + 0x34 + iStack_4 * 0xc);
        ovr_blit_usesBlitGfxN
                  (gfx,(uint)bandOrigin[0] - iVar6,0x10,99,0x10,(byte)in_stack_00000004,pbVar10,
                   unaff_SI,*(undefined2 *)
                             ((char *)
                              "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                              + 0x32 + iStack_4 * 0xc));
        piVar9 = (int *)((ulong)pbVar10 & 0xffff0000);
        ovr_ovc15_fillGridColumn();
      }
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
  undefined2 unaff_DI;
  int16_t in_stack_00000004;
  far_t gfx;
  
  for (uVar3 = rowMapSquareFirst[0]; (int)uVar3 < (int)rowMapSquareEnd[0]; uVar3 = uVar3 + 1) {
    iVar2 = *(int *)(uVar3 * 2 + 0x360);
    if ((0xb < iVar2 + 0x2f) && (iVar2 < 0xdf)) {
      bVar1 = constr_setHighlightAtOffset();
      if ((*(byte *)(CONCAT11(extraout_AH,bVar1) * 0x27 + 0x11e) & 5) != 0) {
        iVar2 = CONCAT11(extraout_AH,bVar1) * 0xc;
        gfx.seg = *(uint16_t *)(uVar3 * 2 + 0xa20);
        gfx.ofs = *(uint16_t *)
                   ((char *)
                    "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                    + 0x38 + iVar2);
        ovr_blitGfxRect(gfx,144,in_stack_00000004,(brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,
                        SUB21(unaff_DI,0),
                        *(undefined2 *)
                         ((char *)
                          "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                          + 0x36 + iVar2));
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
  far_t gfx_00;
  far_t gfx;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t dst;
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 extraout_AH;
  undefined1 uVar7;
  int iVar5;
  char *pcVar6;
  undefined2 uVar8;
  uint16_t uVar9;
  undefined2 unaff_DI;
  uint16_t uVar10;
  char *unaff_SS;
  far_t gfx_07;
  undefined1 uVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  byte mirror;
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
  undefined1 auStack_17 [5];
  int iStack_12;
  uint uStack_10;
  int iStack_e;
  uint8_t uStack_b;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  undefined2 uStack_4;
  
  mirror = (byte)unaff_DI;
  uVar11 = (undefined1)((uint)unaff_DI >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
  dst.ofs = (uint16_t)&shades;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)((uint)unaff_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x24100745)),dst);
  if (GOngoingBattle == '\0') {
    ovr_ovc13_usesBlitRects();
    constr_usesSmoothPrev2();
    ovr_ovc23_textAdlibNone();
    GGameState = 0x24;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    iStack_12 = GfxRndSeed >> 2;
    if (0xb < 0x14bU - iStack_12) {
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)(0xc - iStack_12);
      gfx_02.ofs = ((undefined2 *)&l1Cut1Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = (char)((uint)(0xc - iStack_12) >> 8);
      ovr_blitGfxRect(gfx_02,7,1088,(brect_t *)0x102410,0x0,(bool)mirror,
                      ((undefined2 *)&l1Cut1Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 4],0x40,
                      0x10,0x10,0);
    }
    if (0x14cU - iStack_12 < 0xdf) {
      (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = (char)(0x14c - iStack_12);
      gfx_03.ofs = ((undefined2 *)&l1Cut3Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) = (char)((uint)(0x14c - iStack_12) >> 8);
      ovr_blitGfxRect(gfx_03,7,1088,(brect_t *)0x102410,0x0,(bool)mirror,
                      ((undefined2 *)&l1Cut3Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 4],0x40,
                      0x10,0x10,0);
    }
    ovr_driver_fillRect(0x43,0xde,0x56,0xf0,(uint8_t)BlitRects[0].seg,0xc,0xde,0x56,0xf0);
    GGameState = 0x53;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (uVar9 = 8; -1 < (int)uVar9; uVar9 = uVar9 - 1) {
      for (uVar10 = ((uint16_t *)rowMapSquareFirst)[uVar9];
          (int)uVar10 < (int)((uint16_t *)rowMapSquareEnd)[uVar9]; uVar10 = uVar10 + 1) {
        iVar3 = *(int *)(uVar10 * 2 + 0x360);
        iStack_1e = constr_usesSmoothPrev(uVar9 - 1,(int)&cornerTL,(char)iVar3,(char)&cornerTL);
        iStack_20 = constr_usesSmoothPrev
                              (uVar9 - 1,(int)&cornerTR,(char)(iVar3 + 1),(char)&cornerTR);
        iStack_22 = constr_usesSmoothPrev(uVar9,(int)&cornerBL,(char)iVar3,(char)&cornerBL);
        iStack_24 = constr_usesSmoothPrev(uVar9,(int)&cornerBR,(char)(iVar3 + 1),(char)&cornerBR);
        uVar2 = constr_getFlagsAtOffset(iVar3,uVar9);
        uStack_b = (uint8_t)uVar2;
        if ((uVar2 & 4) == 0) {
          if (iVar3 < 0) {
            uVar2 = constr_compute1(cornerTR,cornerBL,uStack_b,1,mirror,(uint)cornerTL,cornerBL,
                                    uStack_b,1);
            iVar3 = ((uint16_t *)ScreenOriginY)[uVar9] - iStack_20;
            iVar4 = ((uint16_t *)ScreenOriginY)[uVar9] - iStack_1e;
            uVar7 = 0x15;
            ovr_ovc07_usesBiosReadKey
                      (((uint16_t *)ScreenOriginX)[uVar9] - iStack_22,*(int *)(uVar10 * 2 + 0xa20),
                       iVar4,*(int *)(uVar10 * 2 + 0x6c0),iVar3,uVar2 & 0xff,0x440,
                       (brect_t *)CONCAT13(uVar11,CONCAT12(mirror,0x2410)),
                       *(undefined2 *)((int)&AgntAnms[0x5d].sx + 1 + uVar10 * 2),(char)iVar4,
                       (char)iVar3,(char)uVar2,0x40,0x10);
            uVar2 = constr_compute1(cornerBR,cornerTR,uStack_b,2,mirror,CONCAT11(uVar7,cornerBL),
                                    cornerTR,uStack_b,2);
            iVar3 = ((uint16_t *)ScreenOriginY)[uVar9] - iStack_20;
            iVar4 = ((uint16_t *)ScreenOriginX)[uVar9] - iStack_24;
            ovr_ovc07_usesBiosReadKey
                      (((uint16_t *)ScreenOriginX)[uVar9] - iStack_22,*(int *)(uVar10 * 2 + 0xd80),
                       iVar4,*(int *)(uVar10 * 2 + 0x6c0),iVar3,uVar2 & 0xff,0x440,
                       (brect_t *)CONCAT13(uVar11,CONCAT12(mirror,0x2410)),
                       *(undefined2 *)((int)&AgntAnms[0x5d].sx + 1 + uVar10 * 2),(char)iVar4,
                       (char)iVar3,(char)uVar2,0x40,0x10);
          }
          else {
            uVar2 = constr_compute1(cornerBR,cornerTR,uStack_b,2,mirror,(uint)cornerBL,cornerTR,
                                    uStack_b,2);
            iVar3 = ((uint16_t *)ScreenOriginY)[uVar9] - iStack_20;
            iVar4 = ((uint16_t *)ScreenOriginX)[uVar9] - iStack_24;
            uVar7 = 0x15;
            ovr_ovc07_usesBiosReadKey
                      (((uint16_t *)ScreenOriginX)[uVar9] - iStack_22,*(int *)(uVar10 * 2 + 0xd80),
                       iVar4,*(int *)(uVar10 * 2 + 0x6c0),iVar3,uVar2 & 0xff,0x440,
                       (brect_t *)CONCAT13(uVar11,CONCAT12(mirror,0x2410)),
                       *(undefined2 *)((int)&AgntAnms[0x5d].sx + 1 + uVar10 * 2),(char)iVar4,
                       (char)iVar3,(char)uVar2,0x40,0x10);
            uVar2 = constr_compute1(cornerTR,cornerBL,uStack_b,1,mirror,CONCAT11(uVar7,cornerTL),
                                    cornerBL,uStack_b,1);
            iVar3 = ((uint16_t *)ScreenOriginY)[uVar9] - iStack_20;
            iVar4 = ((uint16_t *)ScreenOriginY)[uVar9] - iStack_1e;
            ovr_ovc07_usesBiosReadKey
                      (((uint16_t *)ScreenOriginX)[uVar9] - iStack_22,*(int *)(uVar10 * 2 + 0xa20),
                       iVar4,*(int *)(uVar10 * 2 + 0x6c0),iVar3,uVar2 & 0xff,0x440,
                       (brect_t *)CONCAT13(uVar11,CONCAT12(mirror,0x2410)),
                       *(undefined2 *)((int)&AgntAnms[0x5d].sx + 1 + uVar10 * 2),(char)iVar4,
                       (char)iVar3,(char)uVar2,0x40,0x10);
          }
        }
        else if (iVar3 < 0) {
          uVar2 = constr_compute1(cornerBR,cornerTL,uStack_b,1,mirror,(uint)cornerBL,cornerTL,
                                  uStack_b,1);
          iVar3 = ((uint16_t *)ScreenOriginY)[uVar9] - iStack_1e;
          iVar4 = ((uint16_t *)ScreenOriginX)[uVar9] - iStack_24;
          uVar7 = 0x15;
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)ScreenOriginX)[uVar9] - iStack_22,*(int *)(uVar10 * 2 + 0xd80),
                     iVar4,*(int *)(uVar10 * 2 + 0xa20),iVar3,uVar2 & 0xff,0x440,
                     (brect_t *)CONCAT13(uVar11,CONCAT12(mirror,0x2410)),
                     *(undefined2 *)((int)&AgntAnms[0x5d].sx + 1 + uVar10 * 2),(char)iVar4,
                     (char)iVar3,(char)uVar2,0x40,0x10);
          uVar2 = constr_compute1(cornerTR,cornerBR,uStack_b,2,mirror,CONCAT11(uVar7,cornerTL),
                                  cornerBR,uStack_b,2);
          iVar3 = ((uint16_t *)ScreenOriginY)[uVar9] - iStack_20;
          iVar4 = ((uint16_t *)ScreenOriginY)[uVar9] - iStack_1e;
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)ScreenOriginX)[uVar9] - iStack_24,*(int *)(uVar10 * 2 + 0xa20),
                     iVar4,*(int *)(uVar10 * 2 + 0x6c0),iVar3,uVar2 & 0xff,0x440,
                     (brect_t *)CONCAT13(uVar11,CONCAT12(mirror,0x2410)),
                     *(undefined2 *)(uVar10 * 2 + 0xd80),(char)iVar4,(char)iVar3,(char)uVar2,0x40,
                     0x10);
        }
        else {
          uVar2 = constr_compute1(cornerTR,cornerBR,uStack_b,2,mirror,(uint)cornerTL,cornerBR,
                                  uStack_b,2);
          iVar3 = ((uint16_t *)ScreenOriginY)[uVar9] - iStack_20;
          iVar4 = ((uint16_t *)ScreenOriginY)[uVar9] - iStack_1e;
          uVar7 = 0x15;
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)ScreenOriginX)[uVar9] - iStack_24,*(int *)(uVar10 * 2 + 0xa20),
                     iVar4,*(int *)(uVar10 * 2 + 0x6c0),iVar3,uVar2 & 0xff,0x440,
                     (brect_t *)CONCAT13(uVar11,CONCAT12(mirror,0x2410)),
                     *(undefined2 *)(uVar10 * 2 + 0xd80),(char)iVar4,(char)iVar3,(char)uVar2,0x40,
                     0x10);
          uVar2 = constr_compute1(cornerBR,cornerTL,uStack_b,1,mirror,CONCAT11(uVar7,cornerBL),
                                  cornerTL,uStack_b,1);
          iVar3 = ((uint16_t *)ScreenOriginY)[uVar9] - iStack_1e;
          iVar4 = ((uint16_t *)ScreenOriginX)[uVar9] - iStack_24;
          ovr_ovc07_usesBiosReadKey
                    (((uint16_t *)ScreenOriginX)[uVar9] - iStack_22,*(int *)(uVar10 * 2 + 0xd80),
                     iVar4,*(int *)(uVar10 * 2 + 0xa20),iVar3,uVar2 & 0xff,0x440,
                     (brect_t *)CONCAT13(uVar11,CONCAT12(mirror,0x2410)),
                     *(undefined2 *)((int)&AgntAnms[0x5d].sx + 1 + uVar10 * 2),(char)iVar4,
                     (char)iVar3,(char)uVar2,0x40,0x10);
        }
      }
      if ((int)uVar9 < 6) {
        for (bStack_3b = 0; bStack_3b < 2; bStack_3b = bStack_3b + 1) {
          for (uVar10 = ((uint16_t *)rowMapSquareFirst)[uVar9];
              (int)uVar10 < (int)((uint16_t *)rowMapSquareEnd)[uVar9]; uVar10 = uVar10 + 1) {
            iVar3 = *(int *)(uVar10 * 2 + 0x360);
            uVar7 = (undefined1)iVar3;
            bVar1 = constr_setHighlightAtOffset(uVar9,uVar7);
            iStack_e = CONCAT11(extraout_AH,bVar1);
            GGameState = 0x37;
            if (DebugVerbose != false) {
              printf("%d \r");
            }
            if (iStack_e < 0xf8) {
              if ((iStack_e != 0) &&
                 (((bStack_3b == 0 && ((*(uint *)(iStack_e * 0x27 + 0x121) & 0x800) != 0)) ||
                  ((bStack_3b != 0 && ((*(uint *)(iStack_e * 0x27 + 0x121) & 0x800) == 0)))))) {
                if (*(byte *)(iStack_e * 0x27 + 0x11b) < 2) {
                  iStack_1e = constr_usesSmoothPrev(uVar9 - 1,(int)&cornerTL,uVar7,(char)&cornerTL);
                  iStack_22 = constr_usesSmoothPrev(uVar9,(int)&cornerBL,uVar7,(char)&cornerBL);
                  iStack_20 = constr_usesSmoothPrev
                                        (uVar9 - 1,(int)&cornerTR,(char)(iVar3 + 1),(char)&cornerTR)
                  ;
                  iStack_24 = constr_usesSmoothPrev
                                        (uVar9,(int)&cornerBR,(char)(iVar3 + 1),(char)&cornerBR);
                }
                else if (*(byte *)(iStack_e * 0x27 + 0x11b) < 3) {
                  iStack_1e = constr_usesSmoothPrev(uVar9 - 1,(int)&cornerTL,uVar7,(char)&cornerTL);
                  iStack_22 = constr_usesSmoothPrev(uVar9,(int)&cornerBL,uVar7,(char)&cornerBL);
                  iStack_20 = constr_usesSmoothPrev
                                        (uVar9 - 1,(int)&cornerTR,(char)(iVar3 + 2),(char)&cornerTR)
                  ;
                  iStack_24 = constr_usesSmoothPrev
                                        (uVar9,(int)&cornerBR,(char)(iVar3 + 2),(char)&cornerBR);
                }
                else {
                  iStack_1e = constr_usesSmoothPrev
                                        (uVar9 - 1,(int)&cornerTL,(char)(iVar3 + 1),(char)&cornerTL)
                  ;
                  iStack_22 = constr_usesSmoothPrev
                                        (uVar9,(int)&cornerBL,(char)(iVar3 + 1),(char)&cornerBL);
                  iStack_20 = constr_usesSmoothPrev
                                        (uVar9 - 1,(int)&cornerTR,(char)(iVar3 + 2),(char)&cornerTR)
                  ;
                  iStack_24 = constr_usesSmoothPrev
                                        (uVar9,(int)&cornerBR,(char)(iVar3 + 2),(char)&cornerBR);
                }
                uStack_10 = (uint)*(byte *)(uVar9 + 0x73c);
                iStack_30 = iStack_22 + iStack_1e + iStack_20 + iStack_24 >> 2;
                if ((int)(iStack_1e - uStack_10) < (int)(iStack_20 - uStack_10)) {
                  iVar3 = iStack_1e - uStack_10;
                }
                else {
                  iVar3 = iStack_20 - uStack_10;
                }
                if (iStack_30 < iVar3) {
                  if ((int)(iStack_1e - uStack_10) < (int)(iStack_20 - uStack_10)) {
                    iStack_30 = iStack_1e - uStack_10;
                  }
                  else {
                    iStack_30 = iStack_20 - uStack_10;
                  }
                }
                if (*(char *)(iStack_e * 0x27 + 0x11e) == '\0') {
                  if ((*(uint *)(iStack_e * 0x27 + 0x121) & 0x20) == 0) {
                    iVar3 = iStack_e * 0xc + *(int *)(uVar10 * 2) * 4;
                    uVar2 = *(uint *)(iVar3 + 0x4230) | *(uint *)(iVar3 + 0x4232);
                    uVar7 = (undefined1)(uVar2 >> 8);
                    if (((uVar2 == 0) || (2 < (int)uVar9)) || (7 < HighlightLevel)) {
                      uVar8 = *(undefined2 *)(uVar10 * 2 + 0xa20);
                      iVar3 = iStack_e * 0xc + *(int *)(uVar10 * 2) * 4;
                      (*(uint8_t *)((uint8_t *)&(gfx_06.seg))) = (char)uVar8;
                      gfx_06.ofs = *(undefined2 *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x30 + iVar3);
                      (*(uint8_t *)((uint8_t *)&(gfx_06.seg) + 1)) = (char)((uint)uVar8 >> 8);
                      ovr_blitGfxRect(gfx_06,(uint)*(byte *)(uVar9 + 0x728) - iStack_30,1088,
                                      (brect_t *)
                                      CONCAT13(uVar7,CONCAT12(auStack_17[uVar9 - 1],0x2410)),0x0,
                                      (bool)mirror,
                                      *(undefined2 *)
                                       ((char *)
                                        "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                        + 0x2e + iVar3),0x40,0x10,auStack_17[uVar9 - 1],0);
                    }
                    else {
                      uVar8 = *(undefined2 *)(uVar10 * 2 + 0xa20);
                      iVar3 = iStack_e * 0xc + *(int *)(uVar10 * 2) * 4;
                      (*(uint8_t *)((uint8_t *)&(gfx_05.seg))) = (char)uVar8;
                      gfx_05.ofs = *(undefined2 *)(iVar3 + 0x4232);
                      (*(uint8_t *)((uint8_t *)&(gfx_05.seg) + 1)) = (char)((uint)uVar8 >> 8);
                      ovr_blitGfxRect(gfx_05,(uint)*(byte *)(uVar9 + 0x728) - iStack_30,1088,
                                      (brect_t *)
                                      CONCAT13(uVar7,CONCAT12(auStack_17[uVar9 - 1],0x2410)),0x0,
                                      (bool)mirror,*(undefined2 *)(iVar3 + 0x4230),0x40,0x10,
                                      auStack_17[uVar9 - 1],0);
                      if (1 < HighlightLevel) {
                        ovr_gfxRlePrepare();
                      }
                    }
                  }
                  else {
                    uVar8 = *(undefined2 *)(uVar10 * 2 + 0xa20);
                    iVar3 = iStack_e * 0xc + (uint)GSeason * 4;
                    (*(uint8_t *)((uint8_t *)&(gfx_04.seg))) = (char)uVar8;
                    gfx_04.ofs = *(undefined2 *)
                                  ((char *)
                                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                   + 0x30 + iVar3);
                    (*(uint8_t *)((uint8_t *)&(gfx_04.seg) + 1)) = (char)((uint)uVar8 >> 8);
                    ovr_blitGfxRect(gfx_04,(uint)*(byte *)(uVar9 + 0x728) - iStack_30,1088,
                                    (brect_t *)
                                    CONCAT13((char)((uint)(iStack_e * 0x27) >> 8),
                                             CONCAT12(auStack_17[uVar9 - 1],0x2410)),0x0,
                                    (bool)mirror,
                                    *(undefined2 *)
                                     ((char *)
                                      "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                      + 0x2e + iVar3),0x40,0x10,auStack_17[uVar9 - 1],0);
                  }
                }
                else {
                  iVar3 = iStack_e * 0x27;
                  if ((*(byte *)(iVar3 + 0x11e) & 0x10) != 0) {
                    for (iStack_6 = 0; iStack_6 < 6; iStack_6 = iStack_6 + 1) {
                      uVar7 = (undefined1)((uint)iVar3 >> 8);
                      iVar4 = (*(int *)(uVar10 * 2 + 0xd80) * iStack_6) / 5;
                      bVar1 = (byte)((*(int *)((int)&AgntAnms[0x5d].sx + 1 + uVar10 * 2) *
                                     (5 - iStack_6)) / 5 + iVar4);
                      iVar3 = iStack_e * 0xc;
                      gfx_07.seg = ((bld_inst_t *)BldInstances + iStack_e)->ofs;
                      gfx_07.ofs = *(uint16_t *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x34 + iVar3);
                      gfx_00.seg = (*(int *)(uVar10 * 2 + 0xa20) * (5 - iStack_6)) / 5 +
                                   (*(int *)(uVar10 * 2 + 0x6c0) * iStack_6) / 5;
                      gfx_00.ofs = *(uint16_t *)((int)&BldInstances[0].seg + iStack_e * 0xc);
                      ovr_blit_usesBlitGfxN2
                                (gfx_07,gfx_00,
                                 (int)(((uint)*(byte *)(uVar9 + 0x728) - iStack_1e) * (5 - iStack_6)
                                      ) / 5 +
                                 (int)(((uint)*(byte *)(uVar9 + 0x728) - iStack_20) * iStack_6) / 5,
                                 CONCAT11((char)((uint)iVar4 >> 8),auStack_17[uVar9 - 1]),bVar1,
                                 (int)(((uint)*(byte *)(uVar9 + 0x729) - iStack_22) * (5 - iStack_6)
                                      ) / 5 +
                                 (int)(((uint)*(byte *)(uVar9 + 0x729) - iStack_24) * iStack_6) / 5,
                                 CONCAT11(uVar7,auStack_17[uVar9]),0x40,
                                 (brect_t *)
                                 CONCAT13(uVar7,CONCAT12((undefined1)HighlightLevel,0x2410)),
                                 *(uint16_t *)
                                  ((char *)
                                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                   + 0x32 + iVar3),bVar1,auStack_17[uVar9],0x40,0x10);
                    }
                  }
                  if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 10) != 0) {
                    iVar3 = *(int *)(uVar10 * 2 + 0xa20);
                    if (iVar3 == *(int *)((int)&AgntAnms[0x5d].sx + 1 + uVar10 * 2)) {
                      iVar4 = (uint)*(byte *)(uVar9 + 0x729) - iStack_22;
                      bVar1 = (byte)iVar4;
                      iVar5 = (uint)*(byte *)(uVar9 + 0x728) - iStack_1e;
                      gfx.seg = *(uint16_t *)(uVar10 * 2 + 0xa20);
                      gfx.ofs = *(uint16_t *)
                                 ((char *)
                                  "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                  + 0x34 + iStack_e * 0xc);
                      ovr_blit_usesBlitGfxN
                                (gfx,iVar5,CONCAT11((char)((uint)iVar4 >> 8),auStack_17[uVar9 - 1]),
                                 bVar1,CONCAT11((char)((uint)iVar3 >> 8),auStack_17[uVar9]),0x40,
                                 (brect_t *)CONCAT13(uVar11,CONCAT12(mirror,0x2410)),
                                 *(uint16_t *)
                                  ((char *)
                                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                   + 0x32 + iStack_e * 0xc),(char)iVar5,bVar1,auStack_17[uVar9],0x40
                                 ,0x10);
                    }
                    else {
                      ovr_blit_usesStExit();
                    }
                  }
                  if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 8) != 0) {
                    iVar3 = *(int *)(uVar10 * 2 + 0xd80);
                    if (iVar3 == *(int *)(uVar10 * 2 + 0x6c0)) {
                      iVar4 = (uint)*(byte *)(uVar9 + 0x729) - iStack_24;
                      bVar1 = (byte)iVar4;
                      iVar5 = (uint)*(byte *)(uVar9 + 0x728) - iStack_20;
                      gfx_01.seg = *(uint16_t *)(uVar10 * 2 + 0x6c0);
                      gfx_01.ofs = *(uint16_t *)
                                    ((char *)
                                     "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                     + 0x34 + iStack_e * 0xc);
                      ovr_blit_usesBlitGfxN
                                (gfx_01,iVar5,
                                 CONCAT11((char)((uint)iVar4 >> 8),auStack_17[uVar9 - 1]),bVar1,
                                 CONCAT11((char)((uint)iVar3 >> 8),auStack_17[uVar9]),0x40,
                                 (brect_t *)CONCAT13(uVar11,CONCAT12(mirror,0x2410)),
                                 *(uint16_t *)
                                  ((char *)
                                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                   + 0x32 + iStack_e * 0xc),(char)iVar5,bVar1,auStack_17[uVar9],0x40
                                 ,0x10);
                    }
                    else {
                      ovr_blit_usesStExit();
                    }
                  }
                  if (((*(byte *)(iStack_e * 0x27 + 0x11e) & 4) != 0) ||
                     (((*(byte *)(iStack_e * 0x27 + 0x11e) & 1) != 0 && (uVar9 != 0)))) {
                    ovr_blit_usesStExit();
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
    constr_usesScreenOriginY(0x2410,0x40);
    iStack_8 = 0;
    iStack_a = 0;
    for (uVar9 = rowMapSquareFirst[0]; (int)uVar9 < (int)rowMapSquareEnd[0]; uVar9 = uVar9 + 1) {
      if ((0xb < *(int *)(uVar9 * 2 + 0x6c0)) && (*(int *)(uVar9 * 2 + 0xa20) < 0xdf)) {
        iVar3 = *(int *)(uVar9 * 2 + 0x360);
        iStack_1a = constr_usesSmoothPrev(0xffff,(int)&cornerBL,(char)iVar3,(char)&cornerBL);
        iStack_1c = constr_usesSmoothPrev(0xffff,(int)&cornerBR,(char)(iVar3 + 1),(char)&cornerBR);
        uVar2 = constr_getFlagsAtOffset(iVar3,-1);
        uStack_b = (uint8_t)uVar2;
        iVar5 = ScreenOriginY[0] - iStack_1a;
        iVar3 = *(int *)(uVar9 * 2 + 0x6c0);
        iVar4 = *(int *)(uVar9 * 2 + 0xa20);
        for (iStack_34 = *(int *)(uVar9 * 2 + 0xa20); iStack_34 <= *(int *)(uVar9 * 2 + 0x6c0);
            iStack_34 = iStack_34 + 1) {
          if ((0xb < iStack_34) && (iStack_34 < 0xdf)) {
            *(int *)((iStack_34 + -0xc) * 2 + 0x34c) =
                 iVar5 + ((iStack_1a - iStack_1c) * (iStack_34 - *(int *)(uVar9 * 2 + 0xa20))) /
                         (iVar3 - iVar4);
            *(int *)((iStack_34 + -0xc) * 2 + 0x1a6) = -(iStack_1a - iStack_1c);
            if ((uVar2 & 3) == 0) {
              *(undefined2 *)((iStack_34 + -0xc) * 2) = 1;
            }
            else {
              *(undefined2 *)((iStack_34 + -0xc) * 2) = 0;
              if ((uVar2 & 3) != 0) {
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
    uVar8 = 0x2410;
    TextBlitDstSeg = BlitRects[0].seg;
    TextBlitX = 0xb6;
    TextBlitY = 10;
    if (GameRunning == false) {
      uVar16 = 0xe0;
      uVar17 = 0;
      uVar14 = 0x3f;
      uVar15 = 1;
      uVar12 = (undefined1)Font02.seg;
      uVar13 = (undefined1)(Font02.seg >> 8);
      uVar11 = (undefined1)Font02.ofs;
      uVar7 = (undefined1)(Font02.ofs >> 8);
      pcVar6 = GfxRndSeed2;
      uVar2 = ovr_alignUp4((int)GfxRndSeed2,(char)GfxRndSeed);
      pcVar6 = ovr_stsprintf((char *)CONCAT22(0x76b,unaff_SS),
                             (char *)CONCAT13((char)(uVar2 >> 8),CONCAT12((char)uVar2,0x2410)),
                             pcVar6,buf,(char)uVar2);
      ovr_blitText((char *)CONCAT13(uVar7,CONCAT12(uVar11,uVar8)),
                   (byte *)CONCAT13(uVar15,CONCAT12(uVar14,CONCAT11(uVar13,uVar12))),
                   CONCAT11(uVar17,uVar16),mirror,(char)pcVar6,uVar12,uVar14,uVar16);
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

void __cdecl16far constr_flushDirtyRects(void...)

{
  void *pvVar1;
  uint16_t in_DX;
  uint unaff_SI;
  uint32_t nbytes;
  far_t ptr;
  brect_t *pbVar2;
  undefined2 uVar3;
  far_t handle;
  
  nbytes = (ulong)unaff_SI << 0x10;
  pvVar1 = ovr_stshAlloc(nbytes,0xfa0f);
  ptr.seg = (uint16_t)(nbytes >> 0x10);
  ptr.ofs = in_DX;
  ovr_alignToSeg(ptr,pvVar1);
  pbVar2 = (brect_t *)CONCAT22(ptr.seg,(brect_t *)((char *)"puppetmaker" + 3));
  ovr_miceRestoreArea(pbVar2,0x440);
  pbVar2 = (brect_t *)CONCAT22((int)((ulong)pbVar2 >> 0x10),(brect_t *)((char *)"puppetmaker" + 3));
  ovr_miceRestoreArea(pbVar2,0x45e);
  uVar3 = (undefined2)((ulong)pbVar2 >> 0x10);
  constr_usesAgnt_clear();
  pbVar2 = (brect_t *)CONCAT22(uVar3,(brect_t *)((char *)"puppetmaker" + 3));
  ovr_miceBlitRect(pbVar2,0x440);
  pbVar2 = (brect_t *)CONCAT22((int)((ulong)pbVar2 >> 0x10),(brect_t *)((char *)"puppetmaker" + 3));
  blitRect(pbVar2,0x440);
  uVar3 = (undefined2)((ulong)pbVar2 >> 0x10);
  ovr_miceUpdate();
  pbVar2 = (brect_t *)CONCAT22(uVar3,(brect_t *)((char *)"puppetmaker" + 3));
  ovr_miceBlitRect(pbVar2,0x45e);
  pbVar2 = (brect_t *)CONCAT22((int)((ulong)pbVar2 >> 0x10),(brect_t *)((char *)"puppetmaker" + 3));
  blitRect(pbVar2,0x45e);
  BlitRects[3].seg = 0xa000;
  BlitRects[0].seg = 0xa000;
  handle.seg = (uint16_t)((ulong)pbVar2 >> 0x10);
  handle.ofs = in_DX;
  ovr_stshFree(handle,pvVar1);
  return;
}



/* 36ce:1e76 */

/* [R4] calls blitRect */

void __cdecl16far constr_usesBlitRect3(void)

{
  void *pvVar1;
  uint16_t in_DX;
  uint16_t uVar2;
  ulong in_stack_0000fff6;
  ulong nbytes;
  far_t ptr;
  brect_t *pbVar3;
  undefined2 uVar4;
  far_t handle;
  
  nbytes = in_stack_0000fff6 & 0xffff0000;
  pvVar1 = ovr_stshAlloc(nbytes,0xfa0f);
  ptr.seg = (uint16_t)(nbytes >> 0x10);
  ptr.ofs = in_DX;
  uVar2 = in_DX;
  ovr_alignToSeg(ptr,pvVar1);
  pbVar3 = (brect_t *)CONCAT22(uVar2,(brect_t *)((char *)"puppetmaker" + 3));
  ovr_miceRestoreArea(pbVar3,0x45e);
  uVar4 = (undefined2)((ulong)pbVar3 >> 0x10);
  constr_usesBlitGfxRect2();
  pbVar3 = (brect_t *)CONCAT22(uVar4,(brect_t *)((char *)"puppetmaker" + 3));
  ovr_miceBlitRect(pbVar3,0x45e);
  pbVar3 = (brect_t *)CONCAT22((int)((ulong)pbVar3 >> 0x10),(brect_t *)((char *)"puppetmaker" + 3));
  blitRect(pbVar3,0x45e);
  uVar2 = (uint16_t)((ulong)pbVar3 >> 0x10);
  ovr_miceUpdate();
  BlitRects[3].seg = 0xa000;
  handle.seg = uVar2;
  handle.ofs = in_DX;
  ovr_stshFree(handle,pvVar1);
  return;
}



/* 36ce:1efc */

/* [R4] calls blitRect */

void __cdecl16far constr_usesBlitRect4(void...)

{
  void *pvVar1;
  uint16_t in_DX;
  uint unaff_SI;
  uint32_t nbytes;
  far_t ptr;
  uint16_t uVar3;
  brect_t *pbVar2;
  far_t handle;
  
  nbytes = (ulong)unaff_SI << 0x10;
  pvVar1 = ovr_stshAlloc(nbytes,0xfa0f);
  ptr.seg = (uint16_t)(nbytes >> 0x10);
  ptr.ofs = in_DX;
  ovr_alignToSeg(ptr,pvVar1);
  GGameState = 0x22;
  uVar3 = ptr.seg;
  constr_usesAgnt_clear();
  GGameState = 0x23;
  pbVar2 = (brect_t *)CONCAT22(uVar3,(brect_t *)((char *)"puppetmaker" + 3));
  blitRect(pbVar2,0x440);
  pbVar2 = (brect_t *)CONCAT22((int)((ulong)pbVar2 >> 0x10),(brect_t *)((char *)"puppetmaker" + 3));
  blitRect(pbVar2,0x45e);
  BlitRects[3].seg = 0xa000;
  BlitRects[0].seg = 0xa000;
  handle.seg = (uint16_t)((ulong)pbVar2 >> 0x10);
  handle.ofs = in_DX;
  ovr_stshFree(handle,pvVar1);
  return;
}



/* 36ce:1f99 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far constr_usesBlitGfxRect2(void)

{
  uint16_t uVar1;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t dst_00;
  bool bVar2;
  uint8_t cornerC;
  byte bVar3;
  char cVar4;
  uint uVar5;
  undefined1 extraout_AH;
  int iVar6;
  undefined1 uVar9;
  int iVar7;
  undefined1 extraout_AH_00;
  uint16_t uVar10;
  undefined2 unaff_DI;
  uint16_t uVar11;
  undefined2 unaff_SS;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t gfx_08;
  undefined1 uVar12;
  byte mirror;
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
  undefined1 auStack_a [4];
  int iStack_6;
  uint uStack_4;
  undefined2 uVar8;
  
  mirror = (byte)unaff_DI;
  uVar12 = (undefined1)((uint)unaff_DI >> 8);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = (char)unaff_SS;
  dst_00.ofs = (uint16_t)&dst;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = (char)((uint)unaff_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x2410074f)),dst_00);
  bVar2 = ovr_draw_textArena();
  if (bVar2) {
    iStack_6 = GfxRndSeed * 6 >> 6;
    if (0xee < 0x166 - iStack_6) {
      (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)(0xef - iStack_6);
      gfx.ofs = ((undefined2 *)&l1Cut1Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)(0xef - iStack_6) >> 8);
      ovr_blitGfxRect(gfx,7,1118,(brect_t *)0x62410,0x0,(bool)mirror,
                      ((undefined2 *)&l1Cut1Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 4],7,0x5e
                      ,0x10,6,0);
    }
    if (0x167 - iStack_6 < 0x135) {
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)(0x22f - iStack_6);
      gfx_00.ofs = ((undefined2 *)&l1Cut3Seg)[((uint)seasonGroupBase + (uint)GSeason) * 4];
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)(0x22f - iStack_6) >> 8);
      ovr_blitGfxRect(gfx_00,7,1118,(brect_t *)0x62410,0x0,(bool)mirror,
                      ((undefined2 *)&l1Cut3Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 4],7,0x5e
                      ,0x10,6,0);
    }
    ovr_driver_fillRect(0x1d,0x134,0x24,0xf0,(uint8_t)BlitRects[3].seg,0xef,0x34,0x24,0xf0);
    constr_usesSmoothPrev2();
    for (uVar10 = 2; uVar11 = rowBandSquareFirst[0], -1 < (int)uVar10; uVar10 = uVar10 - 1) {
      for (uVar11 = ((uint16_t *)rowBandSquareFirst)[uVar10];
          (int)uVar11 < (int)((uint16_t *)rowBandSquareEnd)[uVar10]; uVar11 = uVar11 + 1) {
        uVar1 = ((uint16_t *)squareColumn)[uVar11];
        iStack_14 = constr_usesSmoothPrev(uVar10 - 1,(int)&cornerTL,(char)uVar1,(char)&cornerTL);
        iStack_14 = iStack_14 / 3;
        iStack_16 = constr_usesSmoothPrev
                              (uVar10 - 1,(int)&cornerTR,(char)(uVar1 + 1),(char)&cornerTR);
        iStack_16 = iStack_16 / 3;
        iStack_18 = constr_usesSmoothPrev(uVar10,(int)&cornerBL,(char)uVar1,(char)&cornerBL);
        iStack_18 = iStack_18 / 3;
        iStack_1a = constr_usesSmoothPrev(uVar10,(int)&cornerBR,(char)(uVar1 + 1),(char)&cornerBR);
        iStack_1a = iStack_1a / 3;
        uVar5 = constr_getFlagsAtOffset(uVar1,uVar10);
        cornerC = (uint8_t)uVar5;
        if ((uVar5 & 4) == 0) {
          if ((int)uVar1 < 0) {
            constr_compute1(cornerTR,cornerBL,cornerC,1,mirror,cornerTL,cornerBL,cornerC,1);
            ovr_ovc07_usesBiosReadKey();
            constr_compute1(cornerBR,cornerTR,cornerC,2,mirror,cornerBL,cornerTR,cornerC,2);
            ovr_ovc07_usesBiosReadKey();
          }
          else {
            constr_compute1(cornerBR,cornerTR,cornerC,2,mirror,cornerBL,cornerTR,cornerC,2);
            ovr_ovc07_usesBiosReadKey();
            constr_compute1(cornerTR,cornerBL,cornerC,1,mirror,cornerTL,cornerBL,cornerC,1);
            ovr_ovc07_usesBiosReadKey();
          }
        }
        else if ((int)uVar1 < 0) {
          constr_compute1(cornerBR,cornerTL,cornerC,1,mirror,cornerBL,cornerTL,cornerC,1);
          ovr_ovc07_usesBiosReadKey();
          constr_compute1(cornerTR,cornerBR,cornerC,2,mirror,cornerTL,cornerBR,cornerC,2);
          ovr_ovc07_usesBiosReadKey();
        }
        else {
          constr_compute1(cornerTR,cornerBR,cornerC,2,mirror,cornerTL,cornerBR,cornerC,2);
          ovr_ovc07_usesBiosReadKey();
          constr_compute1(cornerBR,cornerTL,cornerC,1,mirror,cornerBL,cornerTL,cornerC,1);
          ovr_ovc07_usesBiosReadKey();
        }
      }
      for (uVar11 = ((uint16_t *)rowBandSquareFirst)[uVar10];
          (int)uVar11 < (int)((uint16_t *)rowBandSquareEnd)[uVar10]; uVar11 = uVar11 + 1) {
        uVar1 = ((uint16_t *)squareColumn)[uVar11];
        uVar9 = (undefined1)uVar1;
        bVar3 = constr_setHighlightAtOffset(uVar10,uVar9);
        iStack_e = CONCAT11(extraout_AH,bVar3);
        if (iStack_e != 0) {
          iStack_14 = constr_usesSmoothPrev(uVar10 - 1,(int)&cornerTL,uVar9,(char)&cornerTL);
          iStack_14 = iStack_14 / 3;
          iStack_18 = constr_usesSmoothPrev(uVar10,(int)&cornerBL,uVar9,(char)&cornerBL);
          iStack_18 = iStack_18 / 3;
          if (*(byte *)(iStack_e * 0x27 + 0x11b) < 2) {
            iStack_16 = constr_usesSmoothPrev
                                  (uVar10 - 1,(int)&cornerTR,(char)(uVar1 + 1),(char)&cornerTR);
            iStack_16 = iStack_16 / 3;
            iStack_1a = constr_usesSmoothPrev
                                  (uVar10,(int)&cornerBR,(char)(uVar1 + 1),(char)&cornerBR);
            iStack_1a = iStack_1a / 3;
          }
          else if (*(byte *)(iStack_e * 0x27 + 0x11b) < 3) {
            iStack_16 = constr_usesSmoothPrev
                                  (uVar10 - 1,(int)&cornerTR,(char)(uVar1 + 2),(char)&cornerTR);
            iStack_16 = iStack_16 / 3;
            iStack_1a = constr_usesSmoothPrev
                                  (uVar10,(int)&cornerBR,(char)(uVar1 + 2),(char)&cornerBR);
            iStack_1a = iStack_1a / 3;
          }
          else {
            iStack_16 = constr_usesSmoothPrev
                                  (uVar10 - 1,(int)&cornerTR,(char)(uVar1 + 4),(char)&cornerTR);
            iStack_16 = iStack_16 / 3;
            iStack_1a = constr_usesSmoothPrev
                                  (uVar10,(int)&cornerBR,(char)(uVar1 + 4),(char)&cornerBR);
            iStack_1a = iStack_1a / 3;
          }
          iStack_26 = iStack_18 + iStack_14 + iStack_16 + iStack_1a >> 2;
          uStack_4 = (uint)*(byte *)(uVar10 + 0x73e);
          if ((int)(iStack_14 - uStack_4) < (int)(iStack_16 - uStack_4)) {
            iVar6 = iStack_14 - uStack_4;
          }
          else {
            iVar6 = iStack_16 - uStack_4;
          }
          if (iStack_26 < iVar6) {
            if ((int)(iStack_14 - uStack_4) < (int)(iStack_16 - uStack_4)) {
              iStack_26 = iStack_14 - uStack_4;
            }
            else {
              iStack_26 = iStack_16 - uStack_4;
            }
          }
          if (*(char *)(iStack_e * 0x27 + 0x11e) == '\0') {
            if ((*(uint *)(iStack_e * 0x27 + 0x121) & 0x20) == 0) {
              iVar6 = iStack_e * 0xc + ((uint16_t *)squareSide)[uVar11] * 4;
              uVar5 = *(uint *)(iVar6 + 0x4230) | *(uint *)(iVar6 + 0x4232);
              uVar9 = (undefined1)(uVar5 >> 8);
              if (((uVar5 == 0) || (1 < (int)uVar10)) || (7 < HighlightLevel)) {
                iStack_26 = (uint)*(byte *)(uVar10 + 0x74b) - iStack_26;
                iVar6 = iStack_e * 0xc + ((uint16_t *)squareSide)[uVar11] * 4;
                (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = (char)((uint16_t *)SquareLeftX)[uVar11];
                gfx_03.ofs = *(undefined2 *)
                              ((char *)
                               "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                               + 0x30 + iVar6);
                (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) = (char)(((uint16_t *)SquareLeftX)[uVar11] >> 8);
                ovr_blitGfxRect(gfx_03,iStack_26,1118,
                                (brect_t *)CONCAT13(uVar9,CONCAT12(auStack_a[uVar10],0x2410)),0x0,
                                (bool)mirror,
                                *(undefined2 *)
                                 ((char *)
                                  "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                  + 0x2e + iVar6),(char)iStack_26,0x5e,0x10,auStack_a[uVar10],0);
              }
              else {
                iVar6 = (uint)*(byte *)(uVar10 + 0x74b) - iStack_26;
                iVar7 = iStack_e * 0xc + ((uint16_t *)squareSide)[uVar11] * 4;
                (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)((uint16_t *)SquareLeftX)[uVar11];
                gfx_02.ofs = *(undefined2 *)(iVar7 + 0x4232);
                (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = (char)(((uint16_t *)SquareLeftX)[uVar11] >> 8);
                ovr_blitGfxRect(gfx_02,iVar6,1118,
                                (brect_t *)CONCAT13(uVar9,CONCAT12(auStack_a[uVar10],0x2410)),0x0,
                                (bool)mirror,*(undefined2 *)(iVar7 + 0x4230),(char)iVar6,0x5e,0x10,
                                auStack_a[uVar10],0);
                if (1 < HighlightLevel) {
                  iVar6 = iStack_e * 0xc + ((uint16_t *)squareSide)[uVar11] * 4;
                  gfx_05.seg = ((uint16_t *)SquareLeftX)[uVar11];
                  gfx_05.ofs = *(uint16_t *)
                                ((char *)
                                 "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                 + 0x30 + iVar6);
                  ovr_gfxRlePrepare(gfx_05,(uint)*(byte *)(uVar10 + 0x74b) - iStack_26,0x45e,
                                    (int *)CONCAT13((byte)(HighlightLevel * 0xff >> 0xb),
                                                    CONCAT12(auStack_a[uVar10],0x2410)),'\0','\0',
                                    *(undefined2 *)
                                     ((char *)
                                      "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                      + 0x2e + iVar6),0x10,auStack_a[uVar10],0,0,
                                    (char)(HighlightLevel * 0xff >> 3),0);
                }
              }
            }
            else {
              iStack_26 = (uint)*(byte *)(uVar10 + 0x74b) - iStack_26;
              iVar6 = iStack_e * 0xc + (uint)GSeason * 4;
              (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = (char)((uint16_t *)SquareLeftX)[uVar11];
              gfx_01.ofs = *(undefined2 *)
                            ((char *)
                             "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                             + 0x30 + iVar6);
              (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = (char)(((uint16_t *)SquareLeftX)[uVar11] >> 8);
              ovr_blitGfxRect(gfx_01,iStack_26,1118,
                              (brect_t *)
                              CONCAT13((char)((uint)(iStack_e * 0x27) >> 8),
                                       CONCAT12(auStack_a[uVar10],0x2410)),0x0,(bool)mirror,
                              *(undefined2 *)
                               ((char *)
                                "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                + 0x2e + iVar6),(char)iStack_26,0x5e,0x10,auStack_a[uVar10],0);
            }
          }
          else {
            if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 10) != 0) {
              if (((uint16_t *)SquareLeftX)[uVar11] == ((uint16_t *)SquareTopY)[uVar11]) {
                ovr_blit_usesBlitGfxN();
              }
              else {
                iVar6 = ((uint16_t *)RowScreenX)[uVar10] - iStack_18;
                bVar3 = (byte)((uint16_t *)SquareTopY)[uVar11];
                gfx_06.seg = ((uint16_t *)SquareLeftX)[uVar11];
                gfx_06.ofs = *(uint16_t *)
                              ((char *)
                               "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                               + 0x30 + iStack_e * 0xc);
                ovr_blit_usesStExit(gfx_06,((uint16_t *)RowScreenY)[uVar10] - iStack_14,
                                    CONCAT11(0x24,auStack_a[uVar10]),bVar3,iVar6,
                                    CONCAT11((char)(((uint16_t *)SquareLeftX)[uVar11] >> 8),
                                             auStack_a[uVar10 + 1]),0x5e,(int *)0x2410,
                                    *(undefined2 *)
                                     ((char *)
                                      "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                      + 0x2e + iStack_e * 0xc),bVar3,(char)iVar6,
                                    auStack_a[uVar10 + 1],0x5e,0x10);
              }
            }
            if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 8) != 0) {
              if (((uint16_t *)SquareBottomY)[uVar11] == ((uint16_t *)SquareRightX)[uVar11]) {
                ovr_blit_usesBlitGfxN();
              }
              else {
                iVar6 = ((uint16_t *)RowScreenX)[uVar10] - iStack_1a;
                bVar3 = (byte)((uint16_t *)SquareBottomY)[uVar11];
                gfx_07.seg = ((uint16_t *)SquareRightX)[uVar11];
                gfx_07.ofs = *(uint16_t *)
                              ((char *)
                               "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                               + 0x30 + iStack_e * 0xc);
                ovr_blit_usesStExit(gfx_07,((uint16_t *)RowScreenY)[uVar10] - iStack_16,
                                    CONCAT11(0x24,auStack_a[uVar10]),bVar3,iVar6,
                                    CONCAT11((char)(((uint16_t *)SquareBottomY)[uVar11] >> 8),
                                             auStack_a[uVar10 + 1]),0x5e,(int *)0x2410,
                                    *(undefined2 *)
                                     ((char *)
                                      "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                      + 0x2e + iStack_e * 0xc),bVar3,(char)iVar6,
                                    auStack_a[uVar10 + 1],0x5e,0x10);
              }
            }
            if (((*(byte *)(iStack_e * 0x27 + 0x11e) & 4) != 0) ||
               (((*(byte *)(iStack_e * 0x27 + 0x11e) & 1) != 0 && (uVar10 != 0)))) {
              iVar6 = ((uint16_t *)RowScreenY)[uVar10] - iStack_16;
              bVar3 = (byte)((uint16_t *)SquareRightX)[uVar11];
              gfx_08.seg = ((uint16_t *)SquareLeftX)[uVar11];
              gfx_08.ofs = *(uint16_t *)
                            ((char *)
                             "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                             + 0x30 + iStack_e * 0xc);
              ovr_blit_usesStExit(gfx_08,((uint16_t *)RowScreenY)[uVar10] - iStack_14,
                                  CONCAT11(0x24,auStack_a[uVar10]),bVar3,iVar6,
                                  CONCAT11((char)((uint)(iStack_e * 0x27) >> 8),auStack_a[uVar10]),
                                  0x5e,(int *)0x2410,
                                  *(undefined2 *)
                                   ((char *)
                                    "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                                    + 0x2e + iStack_e * 0xc),bVar3,(char)iVar6,auStack_a[uVar10],
                                  0x5e,0x10);
            }
          }
        }
      }
    }
    for (; uVar10 = rowBandSquareFirst[0], (int)uVar11 < (int)rowBandSquareEnd[0];
        uVar11 = uVar11 + 1) {
      if ((0xee < (int)((uint16_t *)SquareRightX)[uVar11]) &&
         ((int)((uint16_t *)SquareLeftX)[uVar11] < 0x135)) {
        uVar10 = ((uint16_t *)squareColumn)[uVar11];
        _cornerTL = constr_getCellAtOffset(uVar10,-2);
        _cornerTR = constr_getCellAtOffset(uVar10 + 1,-2);
        iStack_10 = constr_usesSmoothPrev(0xffff,(int)&cornerBL,(char)uVar10,(char)&cornerBL);
        iStack_10 = iStack_10 / 3;
        iStack_12 = constr_usesSmoothPrev(0xffff,(int)&cornerBR,(char)(uVar10 + 1),(char)&cornerBR);
        iStack_12 = iStack_12 / 3;
        uVar5 = constr_getFlagsAtOffset(uVar10,-1);
        bVar3 = (byte)uVar5;
        if ((uVar5 & 4) == 0) {
          uVar8 = constr_compute2(cornerBL,cornerBR,cornerTR,bVar3,2);
          cVar4 = (char)uVar8;
          ovr_ovc07_usesBiosReadKey();
          constr_compute2(cornerTL,cornerTR,cornerBL,bVar3,1);
          ovr_ovc07_usesBiosReadKey();
        }
        else {
          uVar8 = constr_compute2(cornerBL,cornerBR,cornerTL,bVar3,1);
          cVar4 = (char)uVar8;
          ovr_ovc07_usesBiosReadKey();
          constr_compute2(cornerTL,cornerTR,cornerBR,bVar3,2);
          ovr_ovc07_usesBiosReadKey();
        }
        uVar5 = constr_usesGMapFlags(GfxRndSeed2,(char)(uVar10 + GfxRndSeed));
        if ((char)uVar5 != '\0') {
          ovr_ovc07_usesLDIV_at_
                    (RowScreenY[0] - iStack_10,((uint16_t *)SquareRightX)[uVar11],
                     RowScreenY[0] - iStack_12,CONCAT11((char)(uVar5 >> 8),cVar4 + -1),0x5e,
                     (brect_t *)CONCAT13(uVar12,CONCAT12(mirror,0x2410)),
                     ((uint16_t *)SquareLeftX)[uVar11],(char)((uint16_t *)SquareRightX)[uVar11],
                     (char)(RowScreenY[0] - iStack_12),cVar4 + -1,0x5e,0x10);
        }
      }
    }
    for (; (int)uVar10 < (int)rowBandSquareEnd[0]; uVar10 = uVar10 + 1) {
      uVar12 = (undefined1)((uint16_t *)squareColumn)[uVar10];
      bVar3 = constr_setHighlightAtOffset(0,uVar12);
      iStack_e = CONCAT11(extraout_AH_00,bVar3);
      if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 2) != 0) {
        iStack_10 = constr_usesSmoothPrev(0xffff,(int)&cornerBL,uVar12,(char)&cornerBL);
        iStack_10 = iStack_10 / 3;
        ovr_blit_usesBlitGfxN();
      }
      if ((*(byte *)(iStack_e * 0x27 + 0x11e) & 1) != 0) {
        (*(uint8_t *)((uint8_t *)&(gfx_04.seg))) = (char)((uint16_t *)SquareLeftX)[uVar10];
        gfx_04.ofs = *(undefined2 *)
                      ((char *)
                       "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                       + 0x38 + iStack_e * 0xc);
        (*(uint8_t *)((uint8_t *)&(gfx_04.seg) + 1)) = (char)(((uint16_t *)SquareLeftX)[uVar10] >> 8);
        ovr_blitGfxRect(gfx_04,51,1118,
                        (brect_t *)
                        CONCAT13((char)((uint)(iStack_e * 0x27) >> 8),CONCAT12(auStack_a[0],0x2410))
                        ,0x0,(bool)mirror,
                        *(undefined2 *)
                         ((char *)
                          "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                          + 0x36 + iStack_e * 0xc),0x33,0x5e,0x10,auStack_a[0],0);
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
  int in_stack_00000004;
  int iStack_4;
  
  if ((((in_stack_00000004 < 0) || (x < 0)) || (in_AX = in_stack_00000004 + 1, 0x93 < (int)in_AX))
     || (in_AX = x + 1, 0x3b < (int)in_AX)) {
    placementStatus = 2;
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar6 = (undefined2)((ulong)GMapFlags >> 0x10);
    psVar2 = (short *)(in_stack_00000004 * 2);
    if ((((*(short (*) [60] [148])GMapFlags)[x][in_stack_00000004] & 3U) == 0) &&
       (psVar2 = (*(short (*) [60] [148])GMapFlags)[x] + in_stack_00000004, (psVar2[0x94] & 3U) == 0
       )) {
      iStack_4 = (int)(char)(*(byte (*) [59] [148])GMapCells)[x + 1][in_stack_00000004];
      iVar3 = (int)(char)(*(byte (*) [59] [148])GMapCells)[x + 1][in_stack_00000004 + 1];
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
  byte cornerB;
  byte cornerB_00;
  byte cornerB_01;
  byte cornerB_02;
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  short (*paasVar4) [60] [148];
  char unaff_DI;
  undefined2 uVar5;
  int in_stack_00000004;
  byte bStack_4;
  byte bStack_3;
  
  uVar5 = (undefined2)((ulong)GMapFlags >> 0x10);
  paasVar4 = (short (*) [60] [148])GMapFlags;
  uVar1 = (*paasVar4)[x][in_stack_00000004];
  if ((uVar1 & 3) == 0) {
    uVar2 = paasVar4[-1][x + 0x3a][in_stack_00000004 + 0x93] |
            paasVar4[-1][x + 0x3b][in_stack_00000004] |
            paasVar4[-1][x + 0x3b][in_stack_00000004 + 1] |
            paasVar4[-1][x + 0x3b][in_stack_00000004 + 0x93] | (*paasVar4)[x][in_stack_00000004 + 1]
            | (*paasVar4)[x][in_stack_00000004 + 0x93] | (*paasVar4)[x + 1][in_stack_00000004] |
            (*paasVar4)[x + 1][in_stack_00000004 + 1];
    if ((uVar2 & 3) == 0) {
      cornerB = (*(byte (*) [59] [148])GMapCells)[x + 1][in_stack_00000004];
      cornerB_00 = (*(byte (*) [59] [148])GMapCells)[x + 1][in_stack_00000004 + 1];
      cornerB_01 = (*(byte (*) [59] [148])GMapCells)[x][in_stack_00000004];
      cornerB_02 = (*(byte (*) [59] [148])GMapCells)[x][in_stack_00000004 + 1];
      uVar3 = (undefined1)((uint)(x * 0x94) >> 8);
      if ((uVar1 & 4) == 0) {
        bStack_3 = ovr_driver_compute2(cornerB_02,cornerB_00,unaff_DI,CONCAT11(uVar3,cornerB_01));
        bStack_4 = ovr_driver_compute2(cornerB_00,cornerB_01,unaff_DI,
                                       CONCAT11(extraout_AH_01,cornerB));
        uVar3 = extraout_AH_02;
      }
      else {
        bStack_3 = ovr_driver_compute2(cornerB_02,cornerB,unaff_DI,CONCAT11(uVar3,cornerB_01));
        bStack_4 = ovr_driver_compute2(cornerB_00,cornerB_02,unaff_DI,CONCAT11(extraout_AH,cornerB))
        ;
        uVar3 = extraout_AH_00;
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


