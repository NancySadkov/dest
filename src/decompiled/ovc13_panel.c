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
    blitFrameTickHi = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    blitFrameTickLo = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t far */;
    if (5 < BlitFrame) {
      BlitFrame = 0;
    }
    gfx.seg = ((undefined2 *)&blitFrameSeg)[(uint)BlitFrame * 2];
    gfx.ofs = ((undefined2 *)&blitFrameOfs)[(uint)BlitFrame * 2];
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000db93)));
    BlitFrame = BlitFrame + 1;
  }
  return;
}


/* 3d16:005b */
void __cdecl16far ovc13_usesMiceBlitRect(void)

{
  far_t dst;
  far_t dst_00;
  ulong *puVar1;
  int in_DX;
  uint8_t *paletteOfs;
  uint16_t unaff_SS;
  uint8_t paletteSeg;
  undefined2 in_stack_0000ffe2;
  uint8_t flashPalette1;
  uint8_t flashPalette2;
  uint8_t rect;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&stack0xffe2;
  F_SCOPY(far_from_u32((uint32_t)(0x24100846)),dst);
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&rect;
  F_SCOPY(far_from_u32((uint32_t)(0x24100858)),dst_00);
  puVar1 = ovr_attact_usesBDADailyTim_8bbe(flashTickLo,CONCAT22(in_stack_0000ffe2,flashTickHi));
  if ((in_DX == 0) && (puVar1 <= (byte *)__C0_ASM_CopyRight + 4)) {
    paletteOfs = (uint8_t *)0x0;
  }
  else {
    flashTickHi = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    flashTickLo = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t far */;
    FlashToggle = 1 - (FlashToggle != 0);
    paletteSeg = (uint8_t)unaff_SS;
    ovr_vgaSetPalette(&stack0xffe2 + (uint)FlashToggle * 3,paletteSeg,0xef,1);
    ovr_vgaSetPalette(&flashPalette1 + (uint)FlashToggle * 3,paletteSeg,0xee,1);
    paletteOfs = &flashPalette2 + (uint)FlashToggle * 3;
    ovr_vgaSetPalette(paletteOfs,paletteSeg,0xeb,1);
  }
  if ((((noAnimBlit == 0x0) && (GPaused == '\0')) && (mapViewActive == '\x01')) &&
     ((puVar1 = ovr_attact_usesBDADailyTim_8bbe
                          (blitFrameTickLo,CONCAT22(in_stack_0000ffe2,blitFrameTickHi)),
      paletteOfs != (uint8_t *)0x0 || ((ulong *)((int)(undefined4 *)&_DATA + 3U) < puVar1)))) {
    ovr_miceRestoreArea((brect_t *)&rect);
    ovc13_blitAnimFrame();
    ovr_miceBlitRect((brect_t *)&rect);
  }
  return;
}


/* 3d16:0186 */

/* Reads the screen byte at (screenX, screenY) and returns it packed with the offset high byte. */

undefined2 __cdecl16far ovc13_readPixel(int16_t screenX,int16_t screenY,brect_t *surface)

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
  undefined2 uVar5;
  byte y;
  int iStack_c;
  uint8_t uStack_3;
  
  for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
    uVar5 = (undefined2)((ulong)Entities >> 0x10);
    iVar4 = (int)Entities;
    iVar3 = *(int *)((entity_t *)iVar4 + entityIndex);
    iVar2 = ((entity_t *)iVar4)[entityIndex].base.y;
    iVar1 = iVar2 + 1;
    if (((((*(char *)(iVar4 + entityIndex * 0x37 + 0x18) != '\0') ||
          (*(char *)((int)(char **)GMenuStrings + iStack_c * 0x95 + 0x1f) == '\0')) ||
         (DebugVerbose != false)) || (((*(short (*) [60] [148])GMapFlags)[iVar2][iVar3] & 8U) != 0))
       && (((iVar2 = ovc13_usesEntities(entityIndex), (char)iVar2 != '\0' && (PanelGridX <= iVar3))
           && ((iVar3 <= PanelGridX + 0x22 && ((PanelGridY <= iVar1 && (iVar1 <= PanelGridY + 0xf)))
               ))))) {
      iVar1 = (iVar1 - PanelGridY) * 3 + 7;
      iVar3 = (iVar3 - PanelGridX) * 2;
      iVar2 = iVar3 + 0xef;
      uVar5 = ovc13_readPixel(iVar2,iVar1,BlitRects + 3);
      uStack_3 = (uint8_t)uVar5;
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      iVar4 = (int)Entities;
      if (*(char *)(iVar4 + entityIndex * 0x37 + 0x18) == '\0') {
        if ((*(uint *)(iVar4 + entityIndex * 0x37 + 0x14) & 1) == 0) {
          if ((*(byte *)(iVar4 + entityIndex * 0x37 + 0x33) & 1) == 0) {
            if (((uStack_3 != 0xef) && (uStack_3 != 0xee)) && (uStack_3 != 0xeb)) {
              if (*(char *)((int)(char **)GMenuStrings +
                           (uint)((entity_t *)iVar4)[entityIndex].base.gindex * 0x95 + 0x1f) == '\0')
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
      ovr_driver_fillSpan(iVar2,iVar2,y,uStack_3,&((brect_t *)(BlitRects + 3))->x);
      ovr_driver_fillSpan(iVar3 + 0xf0,iVar3 + 0xf0,y,0xec,&((brect_t *)(BlitRects + 3))->x);
    }
  }
  return;
}



/* 3d16:0472 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Draws the entities inside the panel grid onto the panel minimap. */

void __cdecl16far ovc13_drawPanelEntities(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 uVar6;
  byte y;
  uint8_t uStack_3;
  
  if (unitTypeFilter == -1) {
    for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      iVar4 = (int)Entities;
      iVar2 = *(int *)((entity_t *)iVar4 + uVar5);
      iVar3 = ((entity_t *)iVar4)[uVar5].base.y;
      iVar1 = iVar3 + 1;
      if (((((*(char *)(iVar4 + uVar5 * 0x37 + 0x18) != '\0') ||
            (*(char *)((int)(char **)GMenuStrings +
                      (uint)((entity_t *)iVar4)[uVar5].base.gindex * 0x95 + 0x1f) == '\0')) ||
           (((*(short (*) [60] [148])GMapFlags)[iVar3][iVar2] & 8U) != 0)) &&
          ((PanelGridX <= iVar2 && (iVar2 <= PanelGridX + 0x22)))) &&
         ((PanelGridY <= iVar1 && (iVar1 <= PanelGridY + 0xf)))) {
        iVar1 = (iVar1 - PanelGridY) * 3 + 7;
        iVar2 = (iVar2 - PanelGridX) * 2;
        iVar3 = iVar2 + 0xef;
        uVar6 = ovc13_readPixel(iVar3,iVar1,BlitRects + 3);
        uStack_3 = (uint8_t)uVar6;
        uVar6 = (undefined2)((ulong)Entities >> 0x10);
        iVar4 = (int)Entities;
        if (*(char *)(iVar4 + uVar5 * 0x37 + 0x18) == '\0') {
          if ((*(uint *)(iVar4 + uVar5 * 0x37 + 0x14) & 1) == 0) {
            if ((*(byte *)(iVar4 + uVar5 * 0x37 + 0x33) & 1) == 0) {
              if (((uStack_3 != 0xef) && (uStack_3 != 0xee)) && (uStack_3 != 0xeb)) {
                if (*(char *)((int)(char **)GMenuStrings +
                             (uint)((entity_t *)iVar4)[uVar5].base.gindex * 0x95 + 0x1f) == '\0') {
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
        ovr_driver_fillSpan(iVar3,iVar3,y,uStack_3,&((brect_t *)(BlitRects + 3))->x);
        ovr_driver_fillSpan(iVar2 + 0xf0,iVar2 + 0xf0,y,0xec,&((brect_t *)(BlitRects + 3))->x);
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
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte bStack_3;
  
  bVar2 = ovr_manage_findFirstLeader();
  for (bStack_3 = 0; bStack_3 < GLeaderCount; bStack_3 = bStack_3 + 1) {
    if (((char_sheet_t *)(((uint)bStack_3 << 2)))->active != '\0') {
      iVar3 = ((char_sheet_t *)(((uint)bStack_3 << 2)))->x;
      iVar4 = ((char_sheet_t *)(((uint)bStack_3 << 2)))->y;
      if ((((*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3f) == '\0') ||
           (DebugVerbose != false)) ||
          (((*(short (*) [60] [148])GMapFlags)[iVar4][iVar3] & 8U) != 0)) &&
         (((PanelGridX <= iVar3 && (iVar3 <= PanelGridX + 0x22)) &&
          ((PanelGridY <= iVar4 + 1 && (iVar4 <= PanelGridY + 0xf)))))) {
        cVar1 = ((char)iVar4 - (char)PanelGridY) * '\x03';
        iVar3 = (iVar3 - PanelGridX) * 2;
        iVar4 = iVar3 + 0xed;
        if (bVar2 == bStack_3) {
          ovr_driver_fillSpan(iVar3 + 0xeb,iVar3 + 0xf2,cVar1 + 9U,0x75,
                              &((brect_t *)(BlitRects + 3))->x,0x2410);
          ovr_driver_fillSpan(iVar3 + 0xeb,iVar3 + 0xf2,cVar1 + 10,0x75,
                              &((brect_t *)(BlitRects + 3))->x,0x2410);
          ovr_driver_fillSpan(iVar3 + 0xeb,iVar3 + 0xf2,cVar1 + 0xb,0x75,
                              &((brect_t *)(BlitRects + 3))->x,0x2410);
        }
        else {
          ovr_driver_fillSpan(iVar4,iVar3 + 0xf0,cVar1 + 9U,0x75,&((brect_t *)(BlitRects + 3))->x,
                              0x2410);
          ovr_driver_fillSpan(iVar4,iVar3 + 0xf0,cVar1 + 10,0x75,&((brect_t *)(BlitRects + 3))->x,
                              0x2410);
          ovr_driver_fillSpan(iVar4,iVar3 + 0xf0,cVar1 + 0xb,0x75,&((brect_t *)(BlitRects + 3))->x,
                              0x2410);
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
  int iVar7;
  int iVar8;
  uint16_t uVar9;
  byte bStack_26;
  short *psStack_1c;
  undefined2 uStack_1a;
  short *psStack_18;
  undefined2 uStack_16;
  byte *pbStack_14;
  undefined2 uStack_12;
  byte *pbStack_10;
  undefined2 uStack_e;
  int iStack_8;
  int iStack_6;
  undefined2 uVar4;
  
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
  iStack_8 = 7;
  for (iStack_6 = 0; iStack_6 < 0x10; iStack_6 = iStack_6 + 1) {
    iVar7 = 0xef;
    pbStack_10 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),
                                   (*(byte (*) [59] [148])GMapCells)[PanelGridY + iStack_6 + 1] +
                                   PanelGridX);
    pbVar5 = (*(byte (*) [59] [148])GMapCells)[PanelGridY + iStack_6] + PanelGridX;
    pbStack_14 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),pbVar5);
    psVar6 = (*(short (*) [60] [148])GMapFlags)[PanelGridY + iStack_6] + PanelGridX;
    psStack_18 = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),psVar6);
    if (PanelGridY + iStack_6 != 0 && SCARRY2(PanelGridY,iStack_6) == PanelGridY + iStack_6 < 0) {
      psVar6 = ((short (*) [60] [148])GMapFlags)[-1][PanelGridY + iStack_6 + 0x3b] + PanelGridX;
    }
    psStack_1c = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),psVar6);
    cornerA = *pbStack_10;
    pbStack_10 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),
                                   (*(byte (*) [59] [148])GMapCells)[PanelGridY + iStack_6 + 1] +
                                   PanelGridX + 1);
    cornerC = *pbStack_14;
    pbStack_14 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),pbVar5 + 1);
    for (iVar8 = 0; iVar8 < 0x23; iVar8 = iVar8 + 1) {
      cornerB = *pbStack_10;
      pbStack_10 = (byte *)CONCAT22(uStack_e,pbStack_10 + 1);
      cornerB_00 = *pbStack_14;
      pbStack_14 = (byte *)CONCAT22(uStack_12,pbStack_14 + 1);
      uVar1 = *psStack_18;
      psStack_18 = (uint *)CONCAT22(uStack_16,psStack_18 + 1);
      uVar2 = *psStack_1c;
      psStack_1c = (uint *)CONCAT22(uStack_1a,psStack_1c + 1);
      bStack_26 = (byte)uVar1;
      if ((uVar1 & 4) == 0) {
        uVar9 = seg;
        uVar4 = ovr_constr_compute1(cornerA,cornerB,cornerC,bStack_26,1);
        uVar3 = (uint8_t)uVar4;
        uVar4 = ovr_constr_compute1(cornerC,cornerB_00,cornerB,bStack_26,2);
        ovr_driver_compute4(iVar7,(byte)iStack_8,(uint8_t)uVar4,uVar3,uVar9);
      }
      else {
        uVar9 = seg;
        uVar4 = ovr_constr_compute1(cornerA,cornerB,cornerB_00,bStack_26,2);
        uVar3 = (uint8_t)uVar4;
        uVar4 = ovr_constr_compute1(cornerC,cornerB_00,cornerA,bStack_26,1);
        ovr_driver_compute3(iVar7,(byte)iStack_8,(uint8_t)uVar4,uVar3,uVar9);
      }
      if (((uVar1 | uVar2) & 0xc000) != 0) {
        ovc13_compute2(iVar7,iStack_8,(byte)(uVar2 >> 0xe),(byte)(uVar1 >> 0xe),seg);
      }
      iVar7 = iVar7 + 2;
      cornerC = cornerB_00;
      cornerA = cornerB;
    }
    iStack_8 = iStack_8 + 3;
  }
  ovc13_drawPanelLeaders();
  iVar8 = (GfxRndSeed - PanelGridX) * 2;
  x1 = iVar8 + 0xea;
  iVar7 = (GfxRndSeed2 - PanelGridY) * 3;
  y1 = iVar7 + 8;
  ovr_driver_fillSpan(x1,iVar8 + 0xf3,(byte)y1,0xe0,&((brect_t *)(BlitRects + 3))->x,0x2410);
  ovr_driver_fillSpan(x1,iVar8 + 0xf3,(char)iVar7 + 0xc,0xe0,&((brect_t *)(BlitRects + 3))->x,0x2410
                     );
  ovr_ovc07_usesFillRect(x1,y1,x1,iVar7 + 0xc,0xe0,(brect_t *)(BlitRects + 3),0x2410);
  ovr_ovc07_usesFillRect
            (iVar8 + 0xf3,y1,iVar8 + 0xf3,iVar7 + 0xc,0xe0,(brect_t *)(BlitRects + 3),0x2410);
  ovc13_drawPanelEntities();
  return;
}



/* 3d16:0c22 */

/* Draws one panel cell of terrain and units at (x,y). */

void __cdecl16far ovc13_drawPanelCell(int x,int y)

{
  char cVar1;
  byte flags;
  int iVar2;
  int x1;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined2 uVar8;
  uint8_t uStack_a;
  uint8_t uStack_8;
  uint8_t uStack_6;
  uint8_t uStack_4;
  
  cVar1 = (char)y * '\x03';
  iVar2 = x * 2;
  x1 = iVar2 + 0xc;
  iVar3 = ovc13_usesSeedD110(x,y + 1);
  iVar4 = ovc13_usesSeedD110(x,y);
  iVar5 = ovc13_usesSeedD110(x + 1,y + 1);
  iVar6 = ovc13_usesSeedD110(x + 1,y);
  uVar7 = ovc13_usesSeedD1102(x,y);
  flags = (byte)uVar7;
  uStack_a = (uint8_t)iVar6;
  uStack_8 = (uint8_t)iVar4;
  uStack_6 = (uint8_t)iVar5;
  uStack_4 = (uint8_t)iVar3;
  if ((uVar7 & 4) == 0) {
    uVar8 = ovr_constr_compute1(uStack_8,uStack_a,uStack_6,flags,2);
    ovr_driver_fillSpan(x1,iVar2 + 0xd,cVar1 + 7U,(uint8_t)uVar8,&((brect_t *)BlitRects)->x,0x2410);
    ovr_driver_fillSpan(iVar2 + 0xd,iVar2 + 0xd,cVar1 + 8,(uint8_t)uVar8,&((brect_t *)BlitRects)->x,
                        0x2410);
    uVar8 = ovr_constr_compute1(uStack_4,uStack_6,uStack_8,flags,1);
    ovr_driver_fillSpan(x1,x1,cVar1 + 8,(uint8_t)uVar8,&((brect_t *)BlitRects)->x,0x2410);
    ovr_driver_fillSpan(x1,iVar2 + 0xd,cVar1 + 9,(uint8_t)uVar8,&((brect_t *)BlitRects)->x,0x2410);
  }
  else {
    uVar8 = ovr_constr_compute1(uStack_8,uStack_a,uStack_4,flags,1);
    ovr_driver_fillSpan(x1,iVar2 + 0xd,cVar1 + 7U,(uint8_t)uVar8,&((brect_t *)BlitRects)->x,0x2410);
    ovr_driver_fillSpan(x1,x1,cVar1 + 8,(uint8_t)uVar8,&((brect_t *)BlitRects)->x,0x2410);
    uVar8 = ovr_constr_compute1(uStack_4,uStack_6,uStack_a,flags,2);
    ovr_driver_fillSpan(iVar2 + 0xd,iVar2 + 0xd,cVar1 + 8,(uint8_t)uVar8,&((brect_t *)BlitRects)->x,
                        0x2410);
    ovr_driver_fillSpan(x1,iVar2 + 0xd,cVar1 + 9,(uint8_t)uVar8,&((brect_t *)BlitRects)->x,0x2410);
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
  undefined2 uVar7;
  byte y;
  uint8_t uStack_3;
  
  if (unitTypeFilter == -1) {
    for (uVar6 = 0; uVar6 < EntityCount; uVar6 = uVar6 + 1) {
      uVar7 = (undefined2)((ulong)Entities >> 0x10);
      iVar4 = (int)Entities;
      uVar1 = *(uint *)((entity_t *)iVar4 + uVar6);
      iVar3 = ((entity_t *)iVar4)[uVar6].base.y;
      uVar2 = iVar3 + 1;
      if (((((*(char *)(iVar4 + uVar6 * 0x37 + 0x18) != '\0') ||
            (*(char *)((int)(char **)GMenuStrings +
                      (uint)((entity_t *)iVar4)[uVar6].base.gindex * 0x95 + 0x1f) == '\0')) ||
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
        uVar7 = (undefined2)((ulong)Entities >> 0x10);
        iVar5 = (int)Entities;
        if (*(char *)(iVar5 + uVar6 * 0x37 + 0x18) == '\0') {
          if ((*(uint *)(iVar5 + uVar6 * 0x37 + 0x14) & 1) == 0) {
            if ((*(byte *)(iVar5 + uVar6 * 0x37 + 0x33) & 1) == 0) {
              if (((uStack_3 != 0xef) && (uStack_3 != 0xee)) && (uStack_3 != 0xeb)) {
                if (*(char *)((int)(char **)GMenuStrings +
                             (uint)((entity_t *)iVar5)[uVar6].base.gindex * 0x95 + 0x1f) == '\0') {
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
        ovr_driver_fillSpan(iVar4,iVar4,y,uStack_3,&((brect_t *)BlitRects)->x);
        ovr_driver_fillSpan(iVar3,iVar3,y,0xec,&((brect_t *)BlitRects)->x);
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
  undefined2 uVar3;
  
  iVar1 = (int)Entities;
  uVar3 = (undefined2)((ulong)Entities >> 0x10);
  if (unitTypeFilter == 0xfe) {
L_OVC13_3d16_1045_10C4:
    if (partyFilter == -1) {
      if (*(char *)((int)(char **)GMenuStrings +
                   (uint)((entity_t *)iVar1)[entityIndex].base.gindex * 0x95 + 0x1f) == '\0') {
        iVar1 = 1;
      }
      else {
        iVar1 = 0;
      }
    }
    else {
      bVar2 = (byte)((uint)(entityIndex * 0x37) >> 8);
      if (*(char *)(iVar1 + entityIndex * 0x37 + 0x1a) == partyFilter) {
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
  undefined2 uVar6;
  byte y;
  int iStack_c;
  uint8_t uStack_3;
  
  for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
    uVar6 = (undefined2)((ulong)Entities >> 0x10);
    iVar4 = (int)Entities;
    uVar1 = *(uint *)((entity_t *)iVar4 + entityIndex);
    iVar3 = ((entity_t *)iVar4)[entityIndex].base.y;
    uVar2 = iVar3 + 1;
    if (((((*(char *)(iVar4 + entityIndex * 0x37 + 0x18) != '\0') ||
          (*(char *)((int)(char **)GMenuStrings + iStack_c * 0x95 + 0x1f) == '\0')) ||
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
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      iVar5 = (int)Entities;
      if (*(char *)(iVar5 + entityIndex * 0x37 + 0x18) == '\0') {
        if ((*(uint *)(iVar5 + entityIndex * 0x37 + 0x14) & 1) == 0) {
          if ((*(byte *)(iVar5 + entityIndex * 0x37 + 0x33) & 1) == 0) {
            if (((uStack_3 != 0xef) && (uStack_3 != 0xee)) && (uStack_3 != 0xeb)) {
              if (*(char *)((int)(char **)GMenuStrings +
                           (uint)((entity_t *)iVar5)[entityIndex].base.gindex * 0x95 + 0x1f) == '\0')
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
      ovr_driver_fillSpan(iVar4,iVar4,y,uStack_3,&((brect_t *)BlitRects)->x);
      ovr_driver_fillSpan(iVar3,iVar3,y,0xec,&((brect_t *)BlitRects)->x);
    }
  }
  return;
}



/* 3d16:135d */

/* Draws the marker of the highlighted leader in the panel. */

void __cdecl16far ovc13_drawPanelHighlight(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  int x1;
  byte bStack_3;
  
  if (Highlight1 == -1) {
    bVar4 = ovr_manage_findFirstLeader();
    for (bStack_3 = 0; bStack_3 < GLeaderCount; bStack_3 = bStack_3 + 1) {
      if (((char_sheet_t *)(((uint)bStack_3 << 2)))->active != '\0') {
        uVar1 = ((char_sheet_t *)(((uint)bStack_3 << 2)))->x;
        uVar2 = ((char_sheet_t *)(((uint)bStack_3 << 2)))->y;
        if ((((*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3f) == '\0') ||
             (DebugVerbose != false)) ||
            (((*(short (*) [60] [148])GMapFlags)[uVar2][uVar1] & 8U) != 0)) &&
           (((Seed_2000_d110 <= (int)uVar1 && (uVar1 <= Seed_2000_d110 + 0x69U)) &&
            ((Seed_2000_d10e <= (int)uVar2 && (uVar2 <= Seed_2000_d10e + 0x2fU)))))) {
          cVar3 = ((char)uVar2 - (char)Seed_2000_d10e) * '\x03';
          iVar5 = (uVar1 - Seed_2000_d110) * 2;
          x1 = iVar5 + 10;
          if (bVar4 == bStack_3) {
            ovr_driver_fillSpan(iVar5 + 8,iVar5 + 0xf,cVar3 + 9U,0x75,&((brect_t *)BlitRects)->x,
                                0x2410);
            ovr_driver_fillSpan(iVar5 + 8,iVar5 + 0xf,cVar3 + 10,0x75,&((brect_t *)BlitRects)->x,
                                0x2410);
            ovr_driver_fillSpan(iVar5 + 8,iVar5 + 0xf,cVar3 + 0xb,0x75,&((brect_t *)BlitRects)->x,
                                0x2410);
          }
          else {
            ovr_driver_fillSpan(x1,iVar5 + 0xd,cVar3 + 9U,0x75,&((brect_t *)BlitRects)->x,0x2410);
            ovr_driver_fillSpan(x1,iVar5 + 0xd,cVar3 + 10,0x75,&((brect_t *)BlitRects)->x,0x2410);
            ovr_driver_fillSpan(x1,iVar5 + 0xd,cVar3 + 0xb,0x75,&((brect_t *)BlitRects)->x,0x2410);
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
  byte cornerB;
  byte cornerC;
  uint8_t cornerC_00;
  int iVar1;
  int iVar2;
  uint8_t uVar3;
  uint uVar5;
  char *text;
  byte *pbVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  char *unaff_SS;
  uint16_t uVar10;
  uint16_t uVar11;
  uint8_t msg;
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
  short *psStack_14;
  undefined2 uStack_12;
  short *psStack_10;
  undefined2 uStack_e;
  byte *pbStack_c;
  undefined2 uStack_a;
  byte *pbStack_8;
  undefined2 uStack_6;
  undefined2 uStack_4;
  undefined2 uVar4;
  
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
    iVar8 = 0xc;
    pbStack_8 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),
                                  (*(byte (*) [59] [148])GMapCells)[Seed_2000_d10e + iStack_16 + 1]
                                  + Seed_2000_d110);
    pbVar6 = (*(byte (*) [59] [148])GMapCells)[Seed_2000_d10e + iStack_16] + Seed_2000_d110;
    pbStack_c = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),pbVar6);
    psVar7 = (*(short (*) [60] [148])GMapFlags)[Seed_2000_d10e + iStack_16] + Seed_2000_d110;
    psStack_10 = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),psVar7);
    if (Seed_2000_d10e + iStack_16 != 0 &&
        SCARRY2(Seed_2000_d10e,iStack_16) == Seed_2000_d10e + iStack_16 < 0) {
      psVar7 = ((short (*) [60] [148])GMapFlags)[-1][Seed_2000_d10e + iStack_16 + 0x3b] +
               Seed_2000_d110;
    }
    psStack_14 = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),psVar7);
    iStack_1c = (int)(char)*pbStack_8;
    pbStack_8 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),
                                  (*(byte (*) [59] [148])GMapCells)[Seed_2000_d10e + iStack_16 + 1]
                                  + Seed_2000_d110 + 1);
    iStack_20 = (int)(char)*pbStack_c;
    pbStack_c = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),pbVar6 + 1);
    for (iVar9 = 0; iVar9 < 0x69; iVar9 = iVar9 + 1) {
      iStack_1a = iStack_1c;
      iVar2 = iStack_1a;
      iStack_1e = iStack_20;
      iVar1 = iStack_1e;
      cornerB = *pbStack_8;
      pbStack_8 = (byte *)CONCAT22(uStack_6,pbStack_8 + 1);
      cornerC = *pbStack_c;
      pbStack_c = (byte *)CONCAT22(uStack_a,pbStack_c + 1);
      uStack_28 = *psStack_10;
      psStack_10 = (uint *)CONCAT22(uStack_e,psStack_10 + 1);
      uStack_2a = *psStack_14;
      psStack_14 = (uint *)CONCAT22(uStack_12,psStack_14 + 1);
      (*(uint8_t *)((uint8_t *)&(iStack_1a))) = (uint8_t)iStack_1c;
      uVar3 = (uint8_t)iStack_1a;
      iStack_1c = (int)(char)cornerB;
      iStack_1a = iVar2;
      if ((uStack_28 & 4) == 0) {
        (*(uint8_t *)((uint8_t *)&(iStack_1e))) = (uint8_t)iStack_20;
        cornerC_00 = (uint8_t)iStack_1e;
        uVar11 = uStack_22;
        iStack_20 = (int)(char)cornerC;
        iStack_1e = iVar1;
        uVar4 = ovr_constr_compute1(uVar3,cornerB,cornerC_00,(byte)uStack_28,1);
        uVar3 = (uint8_t)uVar4;
        uVar4 = ovr_constr_compute1((uint8_t)iStack_1e,(uint8_t)iStack_20,(uint8_t)iStack_1c,
                                    (byte)uStack_28,2);
        ovr_driver_compute4(iVar8,(byte)iStack_18,(uint8_t)uVar4,uVar3,uVar11);
      }
      else {
        uVar11 = uStack_22;
        iStack_20 = (int)(char)cornerC;
        uVar4 = ovr_constr_compute1(uVar3,cornerB,cornerC,(byte)uStack_28,2);
        uVar3 = (uint8_t)uVar4;
        uVar4 = ovr_constr_compute1((uint8_t)iStack_1e,(uint8_t)iStack_20,(uint8_t)iStack_1a,
                                    (byte)uStack_28,1);
        ovr_driver_compute3(iVar8,(byte)iStack_18,(uint8_t)uVar4,uVar3,uVar11);
      }
      if (((uStack_28 | uStack_2a) & 0xc000) != 0) {
        ovc13_compute2(iVar8,iStack_18,(byte)(uStack_2a >> 0xe),(byte)(uStack_28 >> 0xe),uStack_22);
      }
      iVar8 = iVar8 + 2;
    }
    ovc13_drawPanelCell(0x69,iStack_16);
    iStack_18 = iStack_18 + 3;
  }
  ovc13_drawPanelHighlight();
  ovc13_drawHighlightedUnits();
  iVar8 = (GfxRndSeed - Seed_2000_d110) * 2;
  iStack_24 = iVar8 + 7;
  iStack_26 = (GfxRndSeed2 - Seed_2000_d10e) * 3 + 8;
  ovr_driver_fillSpan(iStack_24,iVar8 + 0x10,(byte)iStack_26,0xe0,&((brect_t *)BlitRects)->x,0x2410)
  ;
  ovr_driver_fillSpan(iStack_24,iStack_24 + 9,(char)iStack_26 + 4,0xe0,&((brect_t *)BlitRects)->x,
                      0x2410);
  ovr_ovc07_usesFillRect
            (iStack_24,iStack_26,iStack_24,iStack_26 + 4,0xe0,(brect_t *)BlitRects,0x2410);
  ovr_ovc07_usesFillRect
            (iStack_24 + 9,iStack_26,iStack_24 + 9,iStack_26 + 4,0xe0,(brect_t *)BlitRects,0x2410);
  ovc13_usesScreenY2();
  uStack_4 = TextBlitDstSeg;
  pbVar6 = (byte *)((char *)0x26510);
  TextBlitDstSeg = BlitRects[0].seg;
  TextBlitX = 0xb6;
  TextBlitY = 10;
  if (GameRunning == false) {
    uVar4 = 0xe0;
    uVar3 = 0x3f;
    uVar11 = Font02.seg;
    uVar10 = Font02.ofs;
    uVar5 = ovr_alignUp4(GfxRndSeed,GfxRndSeed2);
    text = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x864,unaff_SS),
                         (char *)CONCAT22(uVar5,(char *)0x26510));
    ovr_blitText(text,(byte *)CONCAT22(uVar10,pbVar6),uVar11,uVar3,uVar4);
  }
  TextBlitDstSeg = uStack_4;
  return;
}



/* 3d16:1945 */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far ovc13_usesBlitLoadRleGfx2(int x,int y,char force,...)

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
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)));
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

void __cdecl16far ovc13_usesBlitLoadRleGfx3(int x,int y,char force,...)

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
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)));
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
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  int x1;
  int iVar5;
  unit_t *puVar6;
  uint uVar7;
  undefined2 uVar8;
  
  if (Highlight1 != -1) {
    for (uVar7 = 0xf8; uVar7 < GUnitCount; uVar7 = uVar7 + 1) {
      uVar8 = (undefined2)((ulong)GUnits >> 0x10);
      puVar6 = (unit_t *)GUnits;
      if (((puVar6[uVar7].unitType != 0xff) &&
          (uVar3 = *(undefined4 *)((uint)puVar6[uVar7].unitType << 2),
          *(char *)((int)uVar3 + 0x3f) == '\0')) &&
         ((puVar6[uVar7].unitType == Highlight1 || (Highlight1 == 0xff)))) {
        uVar1 = puVar6[uVar7].x;
        uVar2 = puVar6[uVar7].y;
        if (((((Highlight1 == -2) && (puVar6[uVar7].level < 8)) ||
             (*(char *)((uint)(puVar6 + uVar7)->bldType * 0x27 + 0x133) == Highlight1)) &&
            ((Seed_2000_d110 <= (int)uVar1 && (uVar1 <= Seed_2000_d110 + 0x69U)))) &&
           ((Seed_2000_d10e <= (int)uVar2 && (uVar2 <= Seed_2000_d10e + 0x2fU)))) {
          cVar4 = ((char)uVar2 - (char)Seed_2000_d10e) * '\x03';
          x1 = (uVar1 - Seed_2000_d110) * 2 + 0xc;
          iVar5 = (uint)*(byte *)((uint)(puVar6 + uVar7)->bldType * 0x27 + 0x11b) * 2 + -1;
          ovr_driver_fillSpan(x1,x1 + iVar5,cVar4 + 9,0x75,&((brect_t *)BlitRects)->x,0x2410);
          ovr_driver_fillSpan(x1,x1 + iVar5,cVar4 + 10,0x75,&((brect_t *)BlitRects)->x,0x2410);
          ovr_driver_fillSpan(x1,x1 + iVar5,cVar4 + 0xb,0x75,&((brect_t *)BlitRects)->x,0x2410);
        }
      }
    }
  }
  return;
}


