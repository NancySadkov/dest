/*
 * ovc13_panel.c - recovered from STRONG.EXE
 * memory block: OVC13_panel.c
 * range: 3d16:0000 - 3d16:1f4f
 * functions: 20
 */
#include "recovered.h"


/* 3d16:0000 */
void __cdecl16far ovc13_blitAnimFrame(void)

{
  far_t gfx;
  
  if (GMenuFlag == '\0') {
    blitFrameTickHi = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    blitFrameTickLo = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t far */;
    if (5 < BlitFrame) {
      BlitFrame = 0;
    }
    gfx.seg = ((uint16_t *)&blitFrameSeg)[(uint)BlitFrame * 2];
    gfx.ofs = ((uint16_t *)&blitFrameOfs)[(uint)BlitFrame * 2];
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000db93)),0);
    BlitFrame = BlitFrame + 1;
  }
  return;
}


/* 3d16:005b */
void __cdecl16far ovc13_usesMiceBlitRect(void)

{
  undefined1 stk_ffe2;   /* stack slot ffe2 */
  far_t dst;
  far_t dst_00;
  ulong *puVar1;
  int in_DX;
  uint8_t *paletteOfs;
  uint8_t paletteSeg;
  uint16_t in_stack_0000ffe2;
  uint8_t flashPalette1;
  uint8_t flashPalette2;
  uint8_t rect;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)&stk_ffe2;
  F_SCOPY(far_from_u32((uint32_t)(0x24100846)),dst);
  dst_00.seg = _SS;
  dst_00.ofs = (uint16_t)&rect;
  F_SCOPY(far_from_u32((uint32_t)(0x24100858)),dst_00);
  puVar1 = ovr_attact_usesBDADailyTimeCounter(flashTickLo,CONCAT22(in_stack_0000ffe2,flashTickHi),0);
  if ((in_DX == 0) && (puVar1 <= (byte *)__C0_ASM_CopyRight + 4)) {
    paletteOfs = (uint8_t *)0x0;
  }
  else {
    flashTickHi = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    flashTickLo = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t far */;
    FlashToggle = 1 - (FlashToggle != 0);
    paletteSeg = (uint8_t)_SS;
    ovr_vgaSetPalette(&stk_ffe2 + (uint)FlashToggle * 3,paletteSeg,0xef,1);
    ovr_vgaSetPalette(&flashPalette1 + (uint)FlashToggle * 3,paletteSeg,0xee,1);
    paletteOfs = &flashPalette2 + (uint)FlashToggle * 3;
    ovr_vgaSetPalette(paletteOfs,paletteSeg,0xeb,1);
  }
  if ((((noAnimBlit == 0x0) && (GPaused == '\0')) && (mapViewActive == '\x01')) &&
     ((puVar1 = ovr_attact_usesBDADailyTimeCounter
                          (blitFrameTickLo,CONCAT22(in_stack_0000ffe2,blitFrameTickHi),0),
      paletteOfs != (uint8_t *)0x0 || ((ulong *)((int)(uint32_t *)&_DATA + 3U) < puVar1)))) {
    ovr_miceRestoreArea((brect_t *)&rect,0);
    ovc13_blitAnimFrame();
    ovr_miceBlitRect((brect_t *)&rect,0);
  }
  return;
}


/* 3d16:0186 */

/* Reads the screen byte at (screenX, screenY) and returns it packed with the offset high byte. */

uint16_t __cdecl16far ovc13_readPixel(int16_t screenX,int16_t screenY,brect_t *surface)

{
  return CONCAT11((char)((uint)(screenY * 0x140) >> 8),*(undefined1 *)(screenX + screenY * 0x140));
}



/* 3d16:01a4 */

/* [R6] touches Seed_2000_d110, SCARRY2 */

int __cdecl16far ovc13_usesSeedD110(int x,int y)

{
  int iVar1;
  
  if ((((x + Seed_2000_d110 < 0x94) && (SCARRY2(x,Seed_2000_d110) == x + Seed_2000_d110 < 0)) &&
      (Seed_2000_d10e + y < 0x3c)) && (SCARRY2(Seed_2000_d10e,y) == Seed_2000_d10e + y < 0)) {
    iVar1 = (int)(char)(*(byte (*) [59] [148])GMapCells)[Seed_2000_d10e + y][Seed_2000_d110 + x];
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 3d16:01fb */

/* [R6] touches Seed_2000_d110, SCARRY2 */

short __cdecl16far ovc13_usesSeedD1102(int x,int y)

{
  short sVar1;
  
  if ((((x + Seed_2000_d110 < 0x94) && (SCARRY2(x,Seed_2000_d110) == x + Seed_2000_d110 < 0)) &&
      (Seed_2000_d10e + y < 0x3c)) && (SCARRY2(Seed_2000_d10e,y) == Seed_2000_d10e + y < 0)) {
    sVar1 = (*(short (*) [60] [148])GMapFlags)[Seed_2000_d10e + y][x + Seed_2000_d110];
  }
  else {
    sVar1 = 0;
  }
  return sVar1;
}



/* 3d16:0255 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Draws the entity markers inside the panel grid without a type filter. */

void __cdecl16far ovc13_drawPanelEntitiesAll(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint entityIndex;
  uint16_t uVar5;
  byte y;
  int iStack_c;
  uint8_t uStack_3;
  
  for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
    uVar5 = (uint16_t)((ulong)Entities >> 0x10);
    iVar4 = (int)Entities;
    iVar3 = *(int *)((entity_t *)iVar4 + entityIndex);
    iVar2 = ((entity_t *)iVar4)[entityIndex].base.y;
    iVar1 = iVar2 + 1;
    if (((((AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 1) != '\0') ||
          (AgntGs[iStack_c].ai == '\0')) ||
         (DebugVerbose != false)) || (((*(short (*) [60] [148])GMapFlags)[iVar2][iVar3] & 8U) != 0))
       && (((iVar2 = ovc13_usesEntities(entityIndex), (char)iVar2 != '\0' && (PanelGridX <= iVar3))
           && ((iVar3 <= PanelGridX + 0x22 && ((PanelGridY <= iVar1 && (iVar1 <= PanelGridY + 0xf)))
               ))))) {
      iVar1 = (iVar1 - PanelGridY) * 3 + 7;
      iVar3 = (iVar3 - PanelGridX) * 2;
      iVar2 = iVar3 + 0xef;
      uVar5 = ovc13_readPixel(iVar2,iVar1,BlitRects + 3);
      uStack_3 = (uint8_t)uVar5;
      uVar5 = (uint16_t)((ulong)Entities >> 0x10);
      iVar4 = (int)Entities;
      if (AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 1) == '\0') {
        if ((AGNT_WORD(&((entity_t *)Entities)[entityIndex], base.frames, 1) & 1) == 0) {
          if ((AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.flags32, 1) & 1) == 0) {
            if (((uStack_3 != 0xef) && (uStack_3 != 0xee)) && (uStack_3 != 0xeb)) {
              if (AgntGs[(uint)((entity_t *)iVar4)[entityIndex].base.gindex].ai == '\0')
              {
                uStack_3 = 0xff;
              }
              else {
                uStack_3 = 0xea;
              }
            }
          }
          else {
            uStack_3 = 0xee;
          }
        }
        else {
          uStack_3 = 0xeb;
        }
      }
      else {
        uStack_3 = 0xef;
      }
      y = (byte)iVar1;
      ovr_driver_fillSpan(iVar2,iVar2,y,uStack_3,&((brect_t *)(BlitRects + 3))->x,0);
      ovr_driver_fillSpan(iVar3 + 0xf0,iVar3 + 0xf0,y,0xec,&((brect_t *)(BlitRects + 3))->x,0);
    }
  }
  return;
}



/* 3d16:0472 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Draws the entities inside the panel grid onto the panel minimap. */

void __cdecl16far ovc13_drawPanelEntities(void)

{
  /* Re-derived: every entity inside the panel window becomes a short vertical bar coloured
     by its state, plus a one-pixel bar to its right. */
  int rowY;
  int entX;
  int entY;
  int entitiesOfs;
  uint entIdx;
  int xPix;
  int spanX;
  uint16_t pixelResult;
  byte pixel;
  byte y;

  if (unitTypeFilter == -1) {
    for (entIdx = 0; entIdx < EntityCount; entIdx = entIdx + 1) {
      entitiesOfs = (int)Entities;
      entX = *(int *)((entity_t *)entitiesOfs + entIdx);
      entY = ((entity_t *)entitiesOfs)[entIdx].base.y;
      rowY = entY + 1;
      if (((((AGNT_FIELD(&((entity_t *)Entities)[entIdx], base.entity, 1) != '\0') ||
            (AgntGs[(uint)((entity_t *)entitiesOfs)[entIdx].base.gindex].ai == '\0')) ||
           (((*(short (*) [60] [148])GMapFlags)[entY][entX] & 8U) != 0)) &&
          ((PanelGridX <= entX && (entX <= PanelGridX + 0x22)))) &&
         ((PanelGridY <= rowY && (rowY <= PanelGridY + 0xf)))) {
        rowY = (rowY - PanelGridY) * 3 + 7;
        xPix = (entX - PanelGridX) * 2;
        spanX = xPix + 0xef;
        pixelResult = ovc13_readPixel(spanX,rowY,BlitRects + 3);
        pixel = (uint8_t)pixelResult;
        entitiesOfs = (int)Entities;
        if (AGNT_FIELD(&((entity_t *)Entities)[entIdx], base.entity, 1) == '\0') {
          if ((AGNT_WORD(&((entity_t *)Entities)[entIdx], base.frames, 1) & 1) == 0) {
            if ((AGNT_FIELD(&((entity_t *)Entities)[entIdx], base.flags32, 1) & 1) == 0) {
              if (((pixel != 0xef) && (pixel != 0xee)) && (pixel != 0xeb)) {
                if (AgntGs[(uint)((entity_t *)entitiesOfs)[entIdx].base.gindex].ai == '\0') {
                  pixel = 0xff;
                }
                else {
                  pixel = 0xea;
                }
              }
            }
            else {
              pixel = 0xee;
            }
          }
          else {
            pixel = 0xeb;
          }
        }
        else {
          pixel = 0xef;
        }
        y = (byte)rowY;
        ovr_driver_fillSpan(spanX,spanX,y,pixel,&((brect_t *)(BlitRects + 3))->x,0);
        ovr_driver_fillSpan(xPix + 0xf0,xPix + 0xf0,y,0xec,
                            &((brect_t *)(BlitRects + 3))->x,0);
      }
    }
  }
  else {
    ovc13_drawPanelEntitiesAll();
  }
  return;
}



/* 3d16:06a2 */

/* Draws the leader markers inside the panel grid. */

void __cdecl16far ovc13_drawPanelLeaders(void)

{
  /* Re-derived: for every active leader inside the panel window, fill three rows of its
     bar - wider when it is the selected leader, narrower otherwise. */
  char rowOffset;
  byte selectedLeader;
  int leaderX;
  int leaderY;
  int xPix;
  int leftX;
  byte panelIdx;

  selectedLeader = ovr_manage_findFirstLeader();
  for (panelIdx = 0; panelIdx < GLeaderCount; panelIdx = panelIdx + 1) {
    if ((GLeaderSheets[panelIdx])->active != '\0') {
      leaderX = (GLeaderSheets[panelIdx])->x;
      leaderY = (GLeaderSheets[panelIdx])->y;
      if ((((*(char *)((int)*(uint32_t *)((uint)panelIdx << 2) + 0x3f) == '\0') ||
           (DebugVerbose != false)) ||
          (((*(short (*) [60] [148])GMapFlags)[leaderY][leaderX] & 8U) != 0)) &&
         (((PanelGridX <= leaderX && (leaderX <= PanelGridX + 0x22)) &&
          ((PanelGridY <= leaderY + 1 && (leaderY <= PanelGridY + 0xf)))))) {
        rowOffset = ((char)leaderY - (char)PanelGridY) * '\x03';
        xPix = (leaderX - PanelGridX) * 2;
        leftX = xPix + 0xed;
        if (selectedLeader == panelIdx) {
          ovr_driver_fillSpan(xPix + 0xeb,xPix + 0xf2,rowOffset + 9U,0x75,
                              &((brect_t *)(BlitRects + 3))->x,0x2410);
          ovr_driver_fillSpan(xPix + 0xeb,xPix + 0xf2,rowOffset + 10,0x75,
                              &((brect_t *)(BlitRects + 3))->x,0x2410);
          ovr_driver_fillSpan(xPix + 0xeb,xPix + 0xf2,rowOffset + 0xb,0x75,
                              &((brect_t *)(BlitRects + 3))->x,0x2410);
        }
        else {
          ovr_driver_fillSpan(leftX,xPix + 0xf0,rowOffset + 9U,0x75,
                              &((brect_t *)(BlitRects + 3))->x,0x2410);
          ovr_driver_fillSpan(leftX,xPix + 0xf0,rowOffset + 10,0x75,
                              &((brect_t *)(BlitRects + 3))->x,0x2410);
          ovr_driver_fillSpan(leftX,xPix + 0xf0,rowOffset + 0xb,0x75,
                              &((brect_t *)(BlitRects + 3))->x,0x2410);
        }
      }
    }
  }
  return;
}



/* 3d16:0883 */
void __cdecl16far ovc13_compute2(int x,int y,byte upperMask,byte lowerMask,uint16_t seg)

{
  undefined1 *puVar1;
  undefined1 *uStack_6;   /* hand fix: assigned a byte pointer and dereferenced as *uStack_6 */
  
  puVar1 = (undefined1 *)(x + y * 0x140);
  uStack_6 = (undefined1 *)CONCAT22(seg,puVar1);
  if ((upperMask & 1) != 0) {
    puVar1[0x140] = 0xfd;
    puVar1[0x141] = 0xfd;
  }
  if ((upperMask & 2) != 0) {
    *uStack_6 = 0xfd;
    puVar1[0x140] = 0xfd;
  }
  if (((lowerMask & 2) != 0) && (puVar1[0x280] = 0xfd, (lowerMask & 1) != 0)) {
    puVar1[0x281] = 0xfd;
  }
  return;
}


/* 3d16:08ee */

/* [R6] touches BlitRects, PanelGridX */

void __cdecl16far ovc13_usesBlitRects(void)

{
  byte cornerA;
  byte cornerC;
  byte cornerB;
  byte cornerB_00;
  uint uVar1;
  uint uVar2;
  uint16_t seg;
  uint8_t uVar3;
  int x1;
  int y1;
  byte *pbVar5;
  short *psVar6;
  int destX;
  int offY;
  int col;
  int offX;
  uint16_t uVar9;
  byte flagsLo;
  short *flagsAbove;
  uint16_t uStack_1a;
  short *flagsHere;
  uint16_t uStack_16;
  byte *cellsHere;
  uint16_t uStack_12;
  byte *cellsBelow;
  uint16_t uStack_e;
  int destY;
  int row;
  uint16_t edge;
  
  seg = BlitRects[3].seg;
  PanelGridX = GfxRndSeed + -0x11;
  PanelGridY = GfxRndSeed2 + -8;
  if (PanelGridX < 0) {
    PanelGridX = 0;
  }
  if (PanelGridY < 0) {
    PanelGridY = 0;
  }
  if (0x92 < PanelGridX + 0x22) {
    PanelGridX = 0x70;
  }
  if (0x3a < PanelGridY + 0xf) {
    PanelGridY = 0x2b;
  }
  destY = 7;
  for (row = 0; row < 0x10; row = row + 1) {
    destX = 0xef;
    cellsBelow = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),
                                   (*(byte (*) [59] [148])GMapCells)[PanelGridY + row + 1] +
                                   PanelGridX);
    pbVar5 = (*(byte (*) [59] [148])GMapCells)[PanelGridY + row] + PanelGridX;
    cellsHere = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),pbVar5);
    psVar6 = (*(short (*) [60] [148])GMapFlags)[PanelGridY + row] + PanelGridX;
    flagsHere = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),psVar6);
    if (PanelGridY + row != 0 && SCARRY2(PanelGridY,row) == PanelGridY + row < 0) {
      psVar6 = ((short (*) [60] [148])GMapFlags)[-1][PanelGridY + row + 0x3b] + PanelGridX;
    }
    flagsAbove = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),psVar6);
    cornerA = *cellsBelow;
    cellsBelow = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),
                                   (*(byte (*) [59] [148])GMapCells)[PanelGridY + row + 1] +
                                   PanelGridX + 1);
    cornerC = *cellsHere;
    cellsHere = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),pbVar5 + 1);
    for (col = 0; col < 0x23; col = col + 1) {
      cornerB = *cellsBelow;
      cellsBelow = (byte *)CONCAT22(uStack_e,cellsBelow + 1);
      cornerB_00 = *cellsHere;
      cellsHere = (byte *)CONCAT22(uStack_12,cellsHere + 1);
      uVar1 = *flagsHere;
      flagsHere = (uint *)CONCAT22(uStack_16,flagsHere + 1);
      uVar2 = *flagsAbove;
      flagsAbove = (uint *)CONCAT22(uStack_1a,flagsAbove + 1);
      flagsLo = (byte)uVar1;
      if ((uVar1 & 4) == 0) {
        uVar9 = seg;
        edge = ovr_constr_compute1(cornerA,cornerB,cornerC,flagsLo,1,0,0,0);
        uVar3 = (uint8_t)edge;
        edge = ovr_constr_compute1(cornerC,cornerB_00,cornerB,flagsLo,2,0,0,0);
        ovr_driver_compute4(destX,(byte)destY,(uint8_t)edge,uVar3,uVar9);
      }
      else {
        uVar9 = seg;
        edge = ovr_constr_compute1(cornerA,cornerB,cornerB_00,flagsLo,2,0,0,0);
        uVar3 = (uint8_t)edge;
        edge = ovr_constr_compute1(cornerC,cornerB_00,cornerA,flagsLo,1,0,0,0);
        ovr_driver_compute3(destX,(byte)destY,(uint8_t)edge,uVar3,uVar9);
      }
      if (((uVar1 | uVar2) & 0xc000) != 0) {
        ovc13_compute2(destX,destY,(byte)(uVar2 >> 0xe),(byte)(uVar1 >> 0xe),seg);
      }
      destX = destX + 2;
      cornerC = cornerB_00;
      cornerA = cornerB;
    }
    destY = destY + 3;
  }
  ovc13_drawPanelLeaders();
  offX = (GfxRndSeed - PanelGridX) * 2;
  x1 = offX + 0xea;
  offY = (GfxRndSeed2 - PanelGridY) * 3;
  y1 = offY + 8;
  ovr_driver_fillSpan(x1,offX + 0xf3,(byte)y1,0xe0,&((brect_t *)(BlitRects + 3))->x,0x2410);
  ovr_driver_fillSpan(x1,offX + 0xf3,(char)offY + 0xc,0xe0,&((brect_t *)(BlitRects + 3))->x,0x2410
                     );
  ovr_ovc07_usesFillRect(x1,y1,x1,offY + 0xc,0xe0,(brect_t *)(BlitRects + 3),0x2410);
  ovr_ovc07_usesFillRect
            (offX + 0xf3,y1,offX + 0xf3,offY + 0xc,0xe0,(brect_t *)(BlitRects + 3),0x2410);
  ovc13_drawPanelEntities();
  return;
}



/* 3d16:0c22 */

/* Draws one panel cell of terrain and units at (x,y). */

void __cdecl16far ovc13_drawPanelCell(int x,int y)

{
  char rowY;
  byte flags;
  int xTimes2;
  int x1;
  int cellBottomLeft;
  int cellTopLeft;
  int cellBottomRight;
  int cellTopRight;
  uint cellFlags;
  uint16_t fillColor;
  uint8_t topRight;
  uint8_t topLeft;
  uint8_t bottomRight;
  uint8_t bottomLeft;
  
  rowY = (char)y * '\x03';
  xTimes2 = x * 2;
  x1 = xTimes2 + 0xc;
  cellBottomLeft = ovc13_usesSeedD110(x,y + 1);
  cellTopLeft = ovc13_usesSeedD110(x,y);
  cellBottomRight = ovc13_usesSeedD110(x + 1,y + 1);
  cellTopRight = ovc13_usesSeedD110(x + 1,y);
  cellFlags = ovc13_usesSeedD1102(x,y);
  flags = (byte)cellFlags;
  topRight = (uint8_t)cellTopRight;
  topLeft = (uint8_t)cellTopLeft;
  bottomRight = (uint8_t)cellBottomRight;
  bottomLeft = (uint8_t)cellBottomLeft;
  if ((cellFlags & 4) == 0) {
    fillColor = ovr_constr_compute1(topLeft,topRight,bottomRight,flags,2,0,0,0);
    ovr_driver_fillSpan(x1,xTimes2 + 0xd,rowY + 7U,(uint8_t)fillColor,&((brect_t *)BlitRects)->x,0x2410);
    ovr_driver_fillSpan(xTimes2 + 0xd,xTimes2 + 0xd,rowY + 8,(uint8_t)fillColor,&((brect_t *)BlitRects)->x,
                        0x2410);
    fillColor = ovr_constr_compute1(bottomLeft,bottomRight,topLeft,flags,1,0,0,0);
    ovr_driver_fillSpan(x1,x1,rowY + 8,(uint8_t)fillColor,&((brect_t *)BlitRects)->x,0x2410);
    ovr_driver_fillSpan(x1,xTimes2 + 0xd,rowY + 9,(uint8_t)fillColor,&((brect_t *)BlitRects)->x,0x2410);
  }
  else {
    fillColor = ovr_constr_compute1(topLeft,topRight,bottomLeft,flags,1,0,0,0);
    ovr_driver_fillSpan(x1,xTimes2 + 0xd,rowY + 7U,(uint8_t)fillColor,&((brect_t *)BlitRects)->x,0x2410);
    ovr_driver_fillSpan(x1,x1,rowY + 8,(uint8_t)fillColor,&((brect_t *)BlitRects)->x,0x2410);
    fillColor = ovr_constr_compute1(bottomLeft,bottomRight,topRight,flags,2,0,0,0);
    ovr_driver_fillSpan(xTimes2 + 0xd,xTimes2 + 0xd,rowY + 8,(uint8_t)fillColor,&((brect_t *)BlitRects)->x,
                        0x2410);
    ovr_driver_fillSpan(x1,xTimes2 + 0xd,rowY + 9,(uint8_t)fillColor,&((brect_t *)BlitRects)->x,0x2410);
  }
  return;
}



/* 3d16:0e03 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches screenY, EntityCount */

void __cdecl16far ovc13_usesScreenY2(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int screenY;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint16_t uVar7;
  byte y;
  uint8_t uStack_3;
  
  if (unitTypeFilter == -1) {
    for (uVar6 = 0; uVar6 < EntityCount; uVar6 = uVar6 + 1) {
      uVar7 = (uint16_t)((ulong)Entities >> 0x10);
      iVar4 = (int)Entities;
      uVar1 = *(uint *)((entity_t *)iVar4 + uVar6);
      iVar3 = ((entity_t *)iVar4)[uVar6].base.y;
      uVar2 = iVar3 + 1;
      if (((((AGNT_FIELD(&((entity_t *)Entities)[uVar6], base.entity, 1) != '\0') ||
            (AgntGs[(uint)((entity_t *)iVar4)[uVar6].base.gindex].ai == '\0')) ||
           (DebugVerbose != false)) ||
          (((*(short (*) [60] [148])GMapFlags)[iVar3][uVar1] & 8U) != 0)) &&
         (((Seed_2000_d110 <= (int)uVar1 && (uVar1 <= Seed_2000_d110 + 0x69U)) &&
          ((Seed_2000_d10e <= (int)uVar2 && (uVar2 <= Seed_2000_d10e + 0x2fU)))))) {
        screenY = (uVar2 - Seed_2000_d10e) * 3 + 7;
        iVar4 = (uVar1 - Seed_2000_d110) * 2;
        iVar3 = iVar4 + 0xd;
        iVar4 = iVar4 + 0xc;
        uVar7 = ovc13_readPixel(iVar4,screenY,BlitRects);
        uStack_3 = (uint8_t)uVar7;
        uVar7 = (uint16_t)((ulong)Entities >> 0x10);
        iVar5 = (int)Entities;
        if (AGNT_FIELD(&((entity_t *)Entities)[uVar6], base.entity, 1) == '\0') {
          if ((AGNT_WORD(&((entity_t *)Entities)[uVar6], base.frames, 1) & 1) == 0) {
            if ((AGNT_FIELD(&((entity_t *)Entities)[uVar6], base.flags32, 1) & 1) == 0) {
              if (((uStack_3 != 0xef) && (uStack_3 != 0xee)) && (uStack_3 != 0xeb)) {
                if (AgntGs[(uint)((entity_t *)iVar5)[uVar6].base.gindex].ai == '\0') {
                  uStack_3 = 0xff;
                }
                else {
                  uStack_3 = 0xea;
                }
              }
            }
            else {
              uStack_3 = 0xee;
            }
          }
          else {
            uStack_3 = 0xeb;
          }
        }
        else {
          uStack_3 = 0xef;
        }
        y = (byte)screenY;
        ovr_driver_fillSpan(iVar4,iVar4,y,uStack_3,&((brect_t *)BlitRects)->x,0);
        ovr_driver_fillSpan(iVar3,iVar3,y,0xec,&((brect_t *)BlitRects)->x,0);
      }
    }
  }
  else {
    ovc13_drawWindowEntities();
  }
  return;
}



/* 3d16:1045 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities, L_OVC13_3d16_1045_10C4 */

int __cdecl16far ovc13_usesEntities(int entityIndex)

{
  int iVar1;
  byte bVar2;
  uint16_t uVar3;
  
  iVar1 = (int)Entities;
  uVar3 = (uint16_t)((ulong)Entities >> 0x10);
  if (unitTypeFilter == 0xfe) {
L_OVC13_3d16_1045_10C4:
    if (partyFilter == -1) {
      if (AgntGs[(uint)((entity_t *)iVar1)[entityIndex].base.gindex].ai == '\0') {
        iVar1 = 1;
      }
      else {
        iVar1 = 0;
      }
    }
    else {
      bVar2 = (byte)((uint)(entityIndex * 0x37) >> 8);
      if (AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 3) == partyFilter) {
        iVar1 = CONCAT11(bVar2,1);
      }
      else {
        iVar1 = (uint)bVar2 << 8;
      }
    }
  }
  else {
    if ((byte)((undefined1 *)&LevelRangeMin)[unitTypeFilter] <=
        ((entity_t *)iVar1)[entityIndex].base.level) {
      if (((entity_t *)iVar1)[entityIndex].base.level <=
          (byte)((undefined1 *)&LevelRangeMax)[unitTypeFilter]) goto L_OVC13_3d16_1045_10C4;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 3d16:113d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Draws the entities inside the Seed_2000_d110/d10e window onto the panel, filtered by
   ovc13_usesEntities. */

void __cdecl16far ovc13_drawWindowEntities(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int screenY;
  int iVar4;
  int iVar5;
  uint entityIndex;
  uint16_t uVar6;
  byte y;
  int iStack_c;
  uint8_t uStack_3;
  
  for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
    uVar6 = (uint16_t)((ulong)Entities >> 0x10);
    iVar4 = (int)Entities;
    uVar1 = *(uint *)((entity_t *)iVar4 + entityIndex);
    iVar3 = ((entity_t *)iVar4)[entityIndex].base.y;
    uVar2 = iVar3 + 1;
    if (((((AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 1) != '\0') ||
          (AgntGs[iStack_c].ai == '\0')) ||
         (DebugVerbose != false)) || (((*(short (*) [60] [148])GMapFlags)[iVar3][uVar1] & 8U) != 0))
       && (((iVar3 = ovc13_usesEntities(entityIndex), (char)iVar3 != '\0' &&
            (Seed_2000_d110 <= (int)uVar1)) &&
           ((uVar1 <= Seed_2000_d110 + 0x69U &&
            ((Seed_2000_d10e <= (int)uVar2 && (uVar2 <= Seed_2000_d10e + 0x2fU)))))))) {
      screenY = (uVar2 - Seed_2000_d10e) * 3 + 7;
      iVar4 = (uVar1 - Seed_2000_d110) * 2;
      iVar3 = iVar4 + 0xd;
      iVar4 = iVar4 + 0xc;
      uVar6 = ovc13_readPixel(iVar4,screenY,BlitRects);
      uStack_3 = (uint8_t)uVar6;
      uVar6 = (uint16_t)((ulong)Entities >> 0x10);
      iVar5 = (int)Entities;
      if (AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 1) == '\0') {
        if ((AGNT_WORD(&((entity_t *)Entities)[entityIndex], base.frames, 1) & 1) == 0) {
          if ((AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.flags32, 1) & 1) == 0) {
            if (((uStack_3 != 0xef) && (uStack_3 != 0xee)) && (uStack_3 != 0xeb)) {
              if (AgntGs[(uint)((entity_t *)iVar5)[entityIndex].base.gindex].ai == '\0')
              {
                uStack_3 = 0xff;
              }
              else {
                uStack_3 = 0xea;
              }
            }
          }
          else {
            uStack_3 = 0xee;
          }
        }
        else {
          uStack_3 = 0xeb;
        }
      }
      else {
        uStack_3 = 0xef;
      }
      y = (byte)screenY;
      ovr_driver_fillSpan(iVar4,iVar4,y,uStack_3,&((brect_t *)BlitRects)->x,0);
      ovr_driver_fillSpan(iVar3,iVar3,y,0xec,&((brect_t *)BlitRects)->x,0);
    }
  }
  return;
}



/* 3d16:135d */

/* Draws the marker of the highlighted leader in the panel. */

void __cdecl16far ovc13_drawPanelHighlight(void)

{
  /* Re-derived: the same bar drawing as ovc13_drawPanelLeaders, but only inside the
     Seed_2000_d110/d10e window and using BlitRects[0]. */
  uint leaderX;
  uint leaderY;
  char rowOffset;
  byte selectedLeader;
  int xPix;
  int leftX;
  byte panelIdx;

  if (Highlight1 == -1) {
    selectedLeader = ovr_manage_findFirstLeader();
    for (panelIdx = 0; panelIdx < GLeaderCount; panelIdx = panelIdx + 1) {
      if ((GLeaderSheets[panelIdx])->active != '\0') {
        leaderX = (GLeaderSheets[panelIdx])->x;
        leaderY = (GLeaderSheets[panelIdx])->y;
        if ((((*(char *)((int)*(uint32_t *)((uint)panelIdx << 2) + 0x3f) == '\0') ||
             (DebugVerbose != false)) ||
            (((*(short (*) [60] [148])GMapFlags)[leaderY][leaderX] & 8U) != 0)) &&
           (((Seed_2000_d110 <= (int)leaderX && (leaderX <= Seed_2000_d110 + 0x69U)) &&
            ((Seed_2000_d10e <= (int)leaderY && (leaderY <= Seed_2000_d10e + 0x2fU)))))) {
          rowOffset = ((char)leaderY - (char)Seed_2000_d10e) * '\x03';
          xPix = (leaderX - Seed_2000_d110) * 2;
          leftX = xPix + 10;
          if (selectedLeader == panelIdx) {
            ovr_driver_fillSpan(xPix + 8,xPix + 0xf,rowOffset + 9U,0x75,
                                &((brect_t *)BlitRects)->x,0x2410);
            ovr_driver_fillSpan(xPix + 8,xPix + 0xf,rowOffset + 10,0x75,
                                &((brect_t *)BlitRects)->x,0x2410);
            ovr_driver_fillSpan(xPix + 8,xPix + 0xf,rowOffset + 0xb,0x75,
                                &((brect_t *)BlitRects)->x,0x2410);
          }
          else {
            ovr_driver_fillSpan(leftX,xPix + 0xd,rowOffset + 9U,0x75,
                                &((brect_t *)BlitRects)->x,0x2410);
            ovr_driver_fillSpan(leftX,xPix + 0xd,rowOffset + 10,0x75,
                                &((brect_t *)BlitRects)->x,0x2410);
            ovr_driver_fillSpan(leftX,xPix + 0xd,rowOffset + 0xb,0x75,
                                &((brect_t *)BlitRects)->x,0x2410);
          }
        }
      }
    }
  }
  return;
}



/* 3d16:1558 */

/* [R4] calls ovr_alignUp4 */

void __cdecl16far ovc13_usesAlignUp4(void)

{
  /* Re-derived (3d16:1558).  Draws the terrain panel: for each of the 48 rows and 105
     columns it reads the four corner cell bytes (row,col), (row,col+1), (row+1,col),
     (row+1,col+1) plus the current and previous-row map-flag words, calls constr_compute1
     twice with the edge mode chosen by flag bit 4, and draws with driver_compute4 (mode 1)
     or driver_compute3 (mode 2); when either flag word has bits 0xc000 set it overlays with
     ovc13_compute2.  The cursor cell is then highlighted with three fill spans.

     Fixed against the original: the two map-flag pointers advance 2 bytes per cell
     (`add word ptr [bp-0xe],2` / `[bp-0x12],2`) so they are uint16_t*, not uint*; and their
     segment halves - and the cell pointers' - came from four uninitialised locals, so they
     are now the GMapCells/GMapFlags segment words the export already uses when it builds
     the pointers.  Everything else is a rename. */
  byte cornerB;
  byte cornerC;
  uint8_t cornerC_00;
  int savedBelow;
  int savedRow;
  uint8_t uVar3;
  uint uVar5;
  char *text;
  byte *rowCellPtr;
  uint16_t *flagsRowPtr;
  int xPos;
  int colIdx;
  uint16_t uVar10;
  uint16_t uVar11;
  uint8_t msg;
  uint16_t flags2;
  uint16_t flags;
  int spanH;
  int spanX;
  uint16_t blitSeg;
  int rowPrev;
  int rowPrevSaved;
  int belowPrev;
  int belowPrevSaved;
  int rowY;
  int rowIdx;
  uint16_t *flagsAbove;
  uint16_t *flagsCur;
  byte *rowPtr;
  byte *belowPtr;
  uint16_t cellsSeg;
  uint16_t flagsSeg;
  uint16_t savedDstSeg;
  uint16_t uVar4;

  cellsSeg = *(uint16_t *)((uint8_t *)&(GMapCells) + 2);
  flagsSeg = *(uint16_t *)((uint8_t *)&(GMapFlags) + 2);
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
  blitSeg = BlitRects[0].seg;
  rowY = 7;
  for (rowIdx = 0; rowIdx < 0x30; rowIdx = rowIdx + 1) {
    xPos = 0xc;
    belowPtr = (byte *)CONCAT22(cellsSeg,
                                (*(byte (*) [59] [148])GMapCells)[Seed_2000_d10e + rowIdx + 1]
                                + Seed_2000_d110);
    rowCellPtr = (*(byte (*) [59] [148])GMapCells)[Seed_2000_d10e + rowIdx] + Seed_2000_d110;
    rowPtr = (byte *)CONCAT22(cellsSeg,rowCellPtr);
    flagsRowPtr = (*(short (*) [60] [148])GMapFlags)[Seed_2000_d10e + rowIdx] + Seed_2000_d110;
    flagsCur = (uint16_t *)CONCAT22(flagsSeg,flagsRowPtr);
    if (Seed_2000_d10e + rowIdx != 0 &&
        SCARRY2(Seed_2000_d10e,rowIdx) == Seed_2000_d10e + rowIdx < 0) {
      flagsRowPtr = ((short (*) [60] [148])GMapFlags)[-1][Seed_2000_d10e + rowIdx + 0x3b] +
                    Seed_2000_d110;
    }
    flagsAbove = (uint16_t *)CONCAT22(flagsSeg,flagsRowPtr);
    belowPrev = (int)(char)*belowPtr;
    belowPtr = (byte *)CONCAT22(cellsSeg,
                                (*(byte (*) [59] [148])GMapCells)[Seed_2000_d10e + rowIdx + 1]
                                + Seed_2000_d110 + 1);
    rowPrev = (int)(char)*rowPtr;
    rowPtr = (byte *)CONCAT22(cellsSeg,rowCellPtr + 1);
    for (colIdx = 0; colIdx < 0x69; colIdx = colIdx + 1) {
      belowPrevSaved = belowPrev;
      savedBelow = belowPrevSaved;
      rowPrevSaved = rowPrev;
      savedRow = rowPrevSaved;
      cornerB = *belowPtr;
      belowPtr = (byte *)CONCAT22(cellsSeg,belowPtr + 1);
      cornerC = *rowPtr;
      rowPtr = (byte *)CONCAT22(cellsSeg,rowPtr + 1);
      flags = *flagsCur;
      flagsCur = (uint16_t *)CONCAT22(flagsSeg,flagsCur + 1);
      flags2 = *flagsAbove;
      flagsAbove = (uint16_t *)CONCAT22(flagsSeg,flagsAbove + 1);
      (*(uint8_t *)((uint8_t *)&(belowPrevSaved))) = (uint8_t)belowPrev;
      uVar3 = (uint8_t)belowPrevSaved;
      belowPrev = (int)(char)cornerB;
      belowPrevSaved = savedBelow;
      if ((flags & 4) == 0) {
        (*(uint8_t *)((uint8_t *)&(rowPrevSaved))) = (uint8_t)rowPrev;
        cornerC_00 = (uint8_t)rowPrevSaved;
        uVar11 = blitSeg;
        rowPrev = (int)(char)cornerC;
        rowPrevSaved = savedRow;
        uVar4 = ovr_constr_compute1(uVar3,cornerB,cornerC_00,(byte)flags,1,0,0,0);
        uVar3 = (uint8_t)uVar4;
        uVar4 = ovr_constr_compute1((uint8_t)rowPrevSaved,(uint8_t)rowPrev,
                                    (uint8_t)belowPrev,(byte)flags,2,0,0,0);
        ovr_driver_compute4(xPos,(byte)rowY,(uint8_t)uVar4,uVar3,uVar11);
      }
      else {
        uVar11 = blitSeg;
        rowPrev = (int)(char)cornerC;
        uVar4 = ovr_constr_compute1(uVar3,cornerB,cornerC,(byte)flags,2,0,0,0);
        uVar3 = (uint8_t)uVar4;
        uVar4 = ovr_constr_compute1((uint8_t)rowPrevSaved,(uint8_t)rowPrev,
                                    (uint8_t)belowPrevSaved,(byte)flags,1,0,0,0);
        ovr_driver_compute3(xPos,(byte)rowY,(uint8_t)uVar4,uVar3,uVar11);
      }
      if (((flags | flags2) & 0xc000) != 0) {
        ovc13_compute2(xPos,rowY,(byte)(flags2 >> 0xe),(byte)(flags >> 0xe),blitSeg);
      }
      xPos = xPos + 2;
    }
    ovc13_drawPanelCell(0x69,rowIdx);
    rowY = rowY + 3;
  }
  ovc13_drawPanelHighlight();
  ovc13_drawHighlightedUnits();
  xPos = (GfxRndSeed - Seed_2000_d110) * 2;
  spanX = xPos + 7;
  spanH = (GfxRndSeed2 - Seed_2000_d10e) * 3 + 8;
  ovr_driver_fillSpan(spanX,xPos + 0x10,(byte)spanH,0xe0,&((brect_t *)BlitRects)->x,0x2410);
  ovr_driver_fillSpan(spanX,spanX + 9,(char)spanH + 4,0xe0,&((brect_t *)BlitRects)->x,0x2410);
  ovr_ovc07_usesFillRect(spanX,spanH,spanX,spanH + 4,0xe0,(brect_t *)BlitRects,0x2410);
  ovr_ovc07_usesFillRect(spanX + 9,spanH,spanX + 9,spanH + 4,0xe0,(brect_t *)BlitRects,0x2410);
  ovc13_usesScreenY2();
  savedDstSeg = TextBlitDstSeg;
  rowCellPtr = (byte *)((char *)0x26510);
  TextBlitDstSeg = BlitRects[0].seg;
  TextBlitX = 0xb6;
  TextBlitY = 10;
  if (GameRunning == false) {
    uVar4 = 0xe0;
    uVar3 = 0x3f;
    uVar11 = Font02.seg;
    uVar10 = Font02.ofs;
    uVar5 = ovr_alignUp4(GfxRndSeed,GfxRndSeed2,0);
    text = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x864,_SS),
                         (char *)CONCAT22(uVar5,(char *)0x26510));
    ovr_blitText(text,(byte *)CONCAT22(uVar10,rowCellPtr),uVar11,uVar3,uVar4);
  }
  TextBlitDstSeg = savedDstSeg;
  return;
}



/* 3d16:1945 */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far ovc13_usesBlitLoadRleGfx2(int x,int y,char force)

{
  uint uVar1;
  int iVar2;
  far_t gfx;
  
  uVar1 = Seed_2000_d110 + x + 2U & 0xfffc;
  iVar2 = (y + -2) / 3 + Seed_2000_d10e;
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
  if (((force != '\0') || (GfxRndSeed != uVar1)) || (GfxRndSeed2 != iVar2)) {
    gfx.seg = FontHandle.seg;
    gfx.ofs = FontHandle.ofs;
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)),0);
    ovr_attact_usesAgntFlag1();
    AgntFlag1 = false;
    GfxRndSeed2 = iVar2;
    GfxRndSeed = uVar1;
    ovr_ovc41_usesAgnt_clear('\x01');
  }
  return;
}



/* 3d16:1a01 */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far ovc13_usesBlitLoadRleGfx3(int x,int y,char force)

{
  uint uVar1;
  int iVar2;
  far_t gfx;
  
  uVar1 = PanelGridX + x + 2U & 0xfffc;
  iVar2 = (y + -2) / 3 + PanelGridY;
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
  if (((force != '\0') || (GfxRndSeed != uVar1)) || (GfxRndSeed2 != iVar2)) {
    gfx.seg = FontHandle.seg;
    gfx.ofs = FontHandle.ofs;
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)),0);
    ovr_attact_usesAgntFlag1();
    AgntFlag1 = false;
    GfxRndSeed2 = iVar2;
    GfxRndSeed = uVar1;
    ovr_ovc41_usesAgnt_clear('\x01');
  }
  return;
}



/* 3d16:1abd */

/* [R4] calls ovr_blitRect */

void __cdecl16far ovc13_usesBlitRect(void)

{
  bool bVar1;
  
  BlitRects[3].seg = GSavedBlitSeg;
  bVar1 = MiceNeedsUpdate == '\0';
  if (bVar1) {
    ovr_miceRestoreArea((brect_t *)(BlitRects + 3),0x2410);
  }
  ovc13_usesBlitRects();
  if (bVar1) {
    ovr_miceBlitRect((brect_t *)(BlitRects + 3),0x2410);
  }
  ovr_blitRect((brect_t *)(BlitRects + 3),0x2410);
  if (bVar1) {
    ovr_miceUpdate();
  }
  BlitRects[3].seg = 0xa000;
  return;
}



/* 3d16:1b3b */

/* Draws the units of the highlighted type in the panel. */

void __cdecl16far ovc13_drawHighlightedUnits(void)

{
  uint ux;
  uint uy;
  uint32_t unitRec;
  char rowY;
  int x1;
  int spanW;
  unit_t *puVar6;
  uint unitIndex;
  
  if (Highlight1 != -1) {
    for (unitIndex = 0xf8; unitIndex < GUnitCount; unitIndex = unitIndex + 1) {
      puVar6 = (unit_t *)GUnits;
      if (((puVar6[unitIndex].unitType != 0xff) &&
          (unitRec = *(uint32_t *)((uint)puVar6[unitIndex].unitType << 2),
          *(char *)((int)unitRec + 0x3f) == '\0')) &&
         ((puVar6[unitIndex].unitType == Highlight1 || (Highlight1 == 0xff)))) {
        ux = puVar6[unitIndex].x;
        uy = puVar6[unitIndex].y;
        if (((((Highlight1 == -2) && (puVar6[unitIndex].level < 8)) ||
             (*(char *)((uint)(puVar6 + unitIndex)->bldType * 0x27 + 0x133) == Highlight1)) &&
            ((Seed_2000_d110 <= (int)ux && (ux <= Seed_2000_d110 + 0x69U)))) &&
           ((Seed_2000_d10e <= (int)uy && (uy <= Seed_2000_d10e + 0x2fU)))) {
          rowY = ((char)uy - (char)Seed_2000_d10e) * '\x03';
          x1 = (ux - Seed_2000_d110) * 2 + 0xc;
          spanW = (uint)*(byte *)((uint)(puVar6 + unitIndex)->bldType * 0x27 + 0x11b) * 2 + -1;
          ovr_driver_fillSpan(x1,x1 + spanW,rowY + 9,0x75,&((brect_t *)BlitRects)->x,0x2410);
          ovr_driver_fillSpan(x1,x1 + spanW,rowY + 10,0x75,&((brect_t *)BlitRects)->x,0x2410);
          ovr_driver_fillSpan(x1,x1 + spanW,rowY + 0xb,0x75,&((brect_t *)BlitRects)->x,0x2410);
        }
      }
    }
  }
  return;
}


