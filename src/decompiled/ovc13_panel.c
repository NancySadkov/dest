/*
 * ovc13_panel.c - recovered from STRONG.EXE
 * memory block: OVC13_panel.c
 * range: 3d16:0000 - 3d16:1f4f
 * functions: 20
 */
#include "recovered.h"


/* 3d16:0000 */

/* Cycles BlitFrame 0..5 and blits that frame graphic to the screen, latching the BDA tick. */

void __cdecl16far ovc13_blitAnimFrame(void)

{
  uint16_t unaff_BP;
  far_t gfx;
  far_t dst;
  
  if (GMenuFlag == '\0') {
    blitFrameTickHi = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    blitFrameTickLo = *(undefined2 *)BDA_DailyTimeCounter;
    if (5 < BlitFrame) {
      BlitFrame = 0;
    }
    dst.seg = unaff_BP;
    dst.ofs = 0xa000;
    gfx.seg = 0xdb93;
    gfx.ofs = ((undefined2 *)&blitFrameSeg)[(uint)BlitFrame * 2];
    ovr_blitLoadRleGfx(gfx,dst,((undefined2 *)&blitFrameOfs)[(uint)BlitFrame * 2]);
    BlitFrame = BlitFrame + 1;
  }
  return;
}



/* 3d16:005b */

/* WARNING: Removing unreachable block (ram,0x0003d1f7) */
/* [R4] calls ovr_miceBlitRect */

void __cdecl16far ovc13_usesMiceBlitRect(void)

{
  far_t dst;
  far_t dst_00;
  ulong *puVar1;
  int in_DX;
  uint8_t *puVar2;
  brect_t *unaff_SS;
  undefined1 uVar3;
  int in_stack_0000ffe2;
  undefined2 in_stack_0000ffe4;
  uint8_t flashPalette1;
  uint8_t flashPalette2;
  uint8_t rect;
  
  uVar3 = (undefined1)((uint)unaff_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
  dst.ofs = (uint16_t)&stack0xffe2;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar3;
  F_SCOPY(far_from_u32((uint32_t)(0x24100846)),dst);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = (char)unaff_SS;
  dst_00.ofs = (uint16_t)&rect;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = uVar3;
  F_SCOPY(far_from_u32((uint32_t)(0x24100858)),dst_00);
  puVar1 = ovr_attact_usesBDADailyTimeCounter
                     (flashTickHi,CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2),flashTickLo);
  if ((in_DX == 0) && (puVar1 <= (byte *)__C0_ASM_CopyRight + 4)) {
    puVar2 = (uint8_t *)0x0;
  }
  else {
    flashTickHi = (uint16_t)(*(undefined2 *)(BDA_DailyTimeCounter.ofs + 2));
    flashTickLo = *(undefined2 *)BDA_DailyTimeCounter;
    FlashToggle = 1 - (FlashToggle != 0);
    ovr_vgaSetPalette((uint8_t *)CONCAT22(0xef,unaff_SS),0x1,in_stack_0000ffe2,
                      &stack0xffe2 + (uint)FlashToggle * 3,1);
    ovr_vgaSetPalette((uint8_t *)CONCAT22(0xee,unaff_SS),0x1,in_stack_0000ffe2,
                      &flashPalette1 + (uint)FlashToggle * 3,1);
    puVar2 = &flashPalette2 + (uint)FlashToggle * 3;
    ovr_vgaSetPalette((uint8_t *)CONCAT22(0xeb,unaff_SS),0x1,in_stack_0000ffe2,puVar2,1);
  }
  if ((((noAnimBlit == 0x0) && (GPaused == '\0')) && (mapViewActive == '\x01')) &&
     ((puVar1 = ovr_attact_usesBDADailyTimeCounter
                          (blitFrameTickHi,CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2),
                           blitFrameTickLo), puVar2 != (uint8_t *)0x0 ||
      ((ulong *)((int)(undefined4 *)&_DATA + 3U) < puVar1)))) {
    ovr_miceRestoreArea((brect_t *)CONCAT22(in_stack_0000ffe2,unaff_SS),&rect);
    ovc13_blitAnimFrame();
    ovr_miceBlitRect((brect_t *)CONCAT22(in_stack_0000ffe2,unaff_SS),&rect);
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

/* Draws the entity markers inside the panel grid without a type filter. */

void __cdecl16far ovc13_drawPanelEntitiesAll(void)

{
  uint16_t uVar1;
  uint16_t uVar2;
  int iVar3;
  int iVar4;
  int screenY;
  entity_t *peVar5;
  uint entityIndex;
  undefined2 unaff_DI;
  undefined2 uVar6;
  int iStack_c;
  byte bStack_3;
  
  for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
    uVar6 = (undefined2)((ulong)Entities >> 0x10);
    peVar5 = (entity_t *)Entities;
    uVar1 = ((peVar5 + entityIndex)->base).x;
    uVar2 = peVar5[entityIndex].base.y;
    iVar3 = uVar2 + 1;
    if (((((*(char *)((int)&peVar5[entityIndex].base.entity + 1) != '\0') ||
          (*(char *)((int)(char **)GMenuStrings + iStack_c * 0x95 + 0x1f) == '\0')) ||
         (DebugVerbose != false)) || (((*(short (*) [60] [148])GMapFlags)[uVar2][uVar1] & 8U) != 0))
       && (((iVar4 = ovc13_usesEntities(entityIndex), (char)iVar4 != '\0' &&
            (PanelGridX <= (int)uVar1)) &&
           (((int)uVar1 <= PanelGridX + 0x22 &&
            ((PanelGridY <= iVar3 && (iVar3 <= PanelGridY + 0xf)))))))) {
      screenY = (iVar3 - PanelGridY) * 3 + 7;
      iVar3 = (uVar1 - PanelGridX) * 2;
      iVar4 = iVar3 + 0xef;
      uVar6 = ovc13_readPixel(iVar4,screenY,BlitRects + 3);
      bStack_3 = (byte)uVar6;
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      peVar5 = (entity_t *)Entities;
      if (*(char *)((int)&peVar5[entityIndex].base.entity + 1) == '\0') {
        if ((*(uint *)((int)&peVar5[entityIndex].base.frames + 1) & 1) == 0) {
          if ((*(byte *)((int)&peVar5[entityIndex].base.flags32 + 1) & 1) == 0) {
            if (((bStack_3 != 0xef) && (bStack_3 != 0xee)) && (bStack_3 != 0xeb)) {
              if (*(char *)((int)(char **)GMenuStrings +
                           (uint)peVar5[entityIndex].base.gindex * 0x95 + 0x1f) == '\0') {
                bStack_3 = 0xff;
              }
              else {
                bStack_3 = 0xea;
              }
            }
          }
          else {
            bStack_3 = 0xee;
          }
        }
        else {
          bStack_3 = 0xeb;
        }
      }
      else {
        bStack_3 = 0xef;
      }
      ovr_driver_fillSpan(iVar4,screenY,bStack_3,0x5e,
                          (int *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3),iVar4,0x5e);
      ovr_driver_fillSpan(iVar3 + 0xf0,screenY,0xec,0x5e,
                          (int *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3),iVar3 + 0xf0,0x5e);
    }
  }
  return;
}



/* 3d16:0472 */

/* Draws the entities inside the panel grid onto the panel minimap. */

void __cdecl16far ovc13_drawPanelEntities(void)

{
  uint16_t uVar1;
  uint16_t uVar2;
  int iVar3;
  int screenX;
  int screenY;
  entity_t *peVar4;
  uint uVar5;
  undefined2 unaff_DI;
  undefined2 uVar6;
  byte bStack_3;
  
  if (unitTypeFilter == -1) {
    for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      peVar4 = (entity_t *)Entities;
      uVar1 = ((peVar4 + uVar5)->base).x;
      uVar2 = peVar4[uVar5].base.y;
      iVar3 = uVar2 + 1;
      if (((((*(char *)((int)&peVar4[uVar5].base.entity + 1) != '\0') ||
            (*(char *)((int)(char **)GMenuStrings + (uint)peVar4[uVar5].base.gindex * 0x95 + 0x1f)
             == '\0')) || (((*(short (*) [60] [148])GMapFlags)[uVar2][uVar1] & 8U) != 0)) &&
          ((PanelGridX <= (int)uVar1 && ((int)uVar1 <= PanelGridX + 0x22)))) &&
         ((PanelGridY <= iVar3 && (iVar3 <= PanelGridY + 0xf)))) {
        screenY = (iVar3 - PanelGridY) * 3 + 7;
        iVar3 = (uVar1 - PanelGridX) * 2;
        screenX = iVar3 + 0xef;
        uVar6 = ovc13_readPixel(screenX,screenY,BlitRects + 3);
        bStack_3 = (byte)uVar6;
        uVar6 = (undefined2)((ulong)Entities >> 0x10);
        peVar4 = (entity_t *)Entities;
        if (*(char *)((int)&peVar4[uVar5].base.entity + 1) == '\0') {
          if ((*(uint *)((int)&peVar4[uVar5].base.frames + 1) & 1) == 0) {
            if ((*(byte *)((int)&peVar4[uVar5].base.flags32 + 1) & 1) == 0) {
              if (((bStack_3 != 0xef) && (bStack_3 != 0xee)) && (bStack_3 != 0xeb)) {
                if (*(char *)((int)(char **)GMenuStrings +
                             (uint)peVar4[uVar5].base.gindex * 0x95 + 0x1f) == '\0') {
                  bStack_3 = 0xff;
                }
                else {
                  bStack_3 = 0xea;
                }
              }
            }
            else {
              bStack_3 = 0xee;
            }
          }
          else {
            bStack_3 = 0xeb;
          }
        }
        else {
          bStack_3 = 0xef;
        }
        ovr_driver_fillSpan(screenX,screenY,bStack_3,0x5e,
                            (int *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3),screenX,0x5e);
        ovr_driver_fillSpan(iVar3 + 0xf0,screenY,0xec,0x5e,
                            (int *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3),iVar3 + 0xf0,0x5e);
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
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint unaff_DI;
  int *piVar5;
  undefined2 uVar6;
  byte bStack_3;
  
  piVar5 = (int *)((ulong)unaff_DI << 0x10);
  bVar2 = ovr_manage_findFirstLeader();
  for (bStack_3 = 0; bStack_3 < GLeaderCount; bStack_3 = bStack_3 + 1) {
    if (*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3d) != '\0') {
      iVar3 = *(int *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x39);
      iVar1 = *(int *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3b);
      if ((((*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3f) == '\0') ||
           (DebugVerbose != false)) ||
          (((*(short (*) [60] [148])GMapFlags)[iVar1][iVar3] & 8U) != 0)) &&
         (((PanelGridX <= iVar3 && (iVar3 <= PanelGridX + 0x22)) &&
          ((PanelGridY <= iVar1 + 1 && (iVar1 <= PanelGridY + 0xf)))))) {
        iVar1 = (iVar1 - PanelGridY) * 3;
        iVar3 = (iVar3 - PanelGridX) * 2;
        iVar4 = iVar3 + 0xed;
        uVar6 = (undefined2)((ulong)piVar5 >> 0x10);
        if (bVar2 == bStack_3) {
          piVar5 = (int *)CONCAT22(uVar6,(char *)"puppetmaker" + 3);
          ovr_driver_fillSpan(iVar3 + 0xf2,iVar1 + 9,0x75,0x5e,piVar5,iVar3 + 0xeb);
          piVar5 = (int *)CONCAT22((int)((ulong)piVar5 >> 0x10),(char *)"puppetmaker" + 3);
          ovr_driver_fillSpan(iVar3 + 0xf2,iVar1 + 10,0x75,0x5e,piVar5,iVar3 + 0xeb);
          piVar5 = (int *)CONCAT22((int)((ulong)piVar5 >> 0x10),(char *)"puppetmaker" + 3);
          ovr_driver_fillSpan(iVar3 + 0xf2,iVar1 + 0xb,0x75,0x5e,piVar5,iVar3 + 0xeb);
        }
        else {
          piVar5 = (int *)CONCAT22(uVar6,(char *)"puppetmaker" + 3);
          ovr_driver_fillSpan(iVar3 + 0xf0,iVar1 + 9,0x75,0x5e,piVar5,iVar4);
          piVar5 = (int *)CONCAT22((int)((ulong)piVar5 >> 0x10),(char *)"puppetmaker" + 3);
          ovr_driver_fillSpan(iVar3 + 0xf0,iVar1 + 10,0x75,0x5e,piVar5,iVar4);
          piVar5 = (int *)CONCAT22((int)((ulong)piVar5 >> 0x10),(char *)"puppetmaker" + 3);
          ovr_driver_fillSpan(iVar3 + 0xf0,iVar1 + 0xb,0x75,0x5e,piVar5,iVar4);
        }
      }
    }
  }
  return;
}



/* 3d16:0883 */

/* [R7] body shape: compute */

void __cdecl16far ovc13_compute2(int x,int y,byte upperMask,byte lowerMask,uint16_t seg)

{
  undefined1 *puVar1;
  undefined4 uStack_6;
  
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
  byte cornerB;
  byte cornerB_00;
  byte cornerA;
  byte cornerA_00;
  uint uVar1;
  uint uVar2;
  uint16_t seg;
  byte bVar5;
  undefined2 uVar3;
  undefined2 uVar4;
  int y1;
  int x2;
  byte *pbVar6;
  short *psVar7;
  int iVar8;
  uint unaff_DI;
  int iVar9;
  long lVar10;
  int *piVar11;
  brect_t *rect;
  uint8_t uStack_26;
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
  
  seg = BlitRects[3].seg;
  lVar10 = (ulong)unaff_DI << 0x10;
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
    iVar8 = 0xef;
    pbStack_10 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),
                                   (*(byte (*) [59] [148])GMapCells)[PanelGridY + iStack_6 + 1] +
                                   PanelGridX);
    pbVar6 = (*(byte (*) [59] [148])GMapCells)[PanelGridY + iStack_6] + PanelGridX;
    pbStack_14 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),pbVar6);
    psVar7 = (*(short (*) [60] [148])GMapFlags)[PanelGridY + iStack_6] + PanelGridX;
    psStack_18 = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),psVar7);
    if (PanelGridY + iStack_6 != 0 && SCARRY2(PanelGridY,iStack_6) == PanelGridY + iStack_6 < 0) {
      psVar7 = ((short (*) [60] [148])GMapFlags)[-1][PanelGridY + iStack_6 + 0x3b] + PanelGridX;
    }
    psStack_1c = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),psVar7);
    cornerB = *pbStack_10;
    pbStack_10 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),
                                   (*(byte (*) [59] [148])GMapCells)[PanelGridY + iStack_6 + 1] +
                                   PanelGridX + 1);
    cornerB_00 = *pbStack_14;
    pbStack_14 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),pbVar6 + 1);
    for (iVar9 = 0; iVar9 < 0x23; iVar9 = iVar9 + 1) {
      cornerA = *pbStack_10;
      pbStack_10 = (byte *)CONCAT22(uStack_e,pbStack_10 + 1);
      cornerA_00 = *pbStack_14;
      pbStack_14 = (byte *)CONCAT22(uStack_12,pbStack_14 + 1);
      uVar1 = *psStack_18;
      psStack_18 = (uint *)CONCAT22(uStack_16,psStack_18 + 1);
      uVar2 = *psStack_1c;
      psStack_1c = (uint *)CONCAT22(uStack_1a,psStack_1c + 1);
      bVar5 = (byte)(uVar2 >> 8);
      uVar3 = (undefined2)((ulong)lVar10 >> 0x10);
      uStack_26 = (uint8_t)uVar1;
      if ((uVar1 & 4) == 0) {
        lVar10 = CONCAT22(uVar3,seg);
        uVar3 = ovr_constr_compute1(cornerA,cornerB_00,uStack_26,1,(byte)seg,CONCAT11(bVar5,cornerB)
                                   );
        uVar4 = ovr_constr_compute1(cornerA_00,cornerA,uStack_26,2,(byte)uVar3,
                                    CONCAT11((char)((uint)uVar3 >> 8),cornerB_00));
        ovr_driver_compute4(CONCAT11((char)((uint)uVar4 >> 8),(undefined1)iStack_8),(byte)uVar4,
                            (uint8_t)uVar3,(uint8_t)lVar10,(uint16_t)((ulong)lVar10 >> 0x10),iVar8);
      }
      else {
        lVar10 = CONCAT22(uVar3,seg);
        uVar3 = ovr_constr_compute1(cornerA,cornerA_00,uStack_26,2,(byte)seg,CONCAT11(bVar5,cornerB)
                                   );
        uVar4 = ovr_constr_compute1(cornerA_00,cornerB,uStack_26,1,(byte)uVar3,
                                    CONCAT11((char)((uint)uVar3 >> 8),cornerB_00));
        ovr_driver_compute3(CONCAT11((char)((uint)uVar4 >> 8),(undefined1)iStack_8),(byte)uVar4,
                            (uint8_t)uVar3,(uint8_t)lVar10,(uint16_t)((ulong)lVar10 >> 0x10),iVar8);
      }
      if (((uVar1 | uVar2) & 0xc000) != 0) {
        lVar10 = CONCAT22((int)((ulong)lVar10 >> 0x10),seg);
        ovc13_compute2(iVar8,iStack_8,bVar5 >> 6,(byte)(uVar1 >> 0xe),seg);
      }
      iVar8 = iVar8 + 2;
      cornerB_00 = cornerA_00;
      cornerB = cornerA;
    }
    iStack_8 = iStack_8 + 3;
  }
  uVar3 = (undefined2)((ulong)lVar10 >> 0x10);
  ovc13_drawPanelLeaders();
  iVar9 = (GfxRndSeed - PanelGridX) * 2;
  y1 = iVar9 + 0xea;
  iVar8 = (GfxRndSeed2 - PanelGridY) * 3;
  x2 = iVar8 + 8;
  piVar11 = (int *)CONCAT22(uVar3,(char *)"puppetmaker" + 3);
  ovr_driver_fillSpan(iVar9 + 0xf3,x2,0xe0,0x5e,piVar11,y1);
  piVar11 = (int *)CONCAT22((int)((ulong)piVar11 >> 0x10),(char *)"puppetmaker" + 3);
  ovr_driver_fillSpan(iVar9 + 0xf3,iVar8 + 0xc,0xe0,0x5e,piVar11,y1);
  rect = (brect_t *)CONCAT22((int)((ulong)piVar11 >> 0x10),(brect_t *)((char *)"puppetmaker" + 3));
  ovr_ovc07_usesFillRect(x2,y1,iVar8 + 0xc,0xe0,0x45e,rect,y1);
  ovr_ovc07_usesFillRect
            (x2,iVar9 + 0xf3,iVar8 + 0xc,0xe0,0x45e,
             (brect_t *)CONCAT22((int)((ulong)rect >> 0x10),(brect_t *)((char *)"puppetmaker" + 3)),
             iVar9 + 0xf3);
  ovc13_drawPanelEntities();
  return;
}



/* 3d16:0c22 */

/* Draws one panel cell of terrain and units at (x,y). */

void __cdecl16far ovc13_drawPanelCell(int x,int y)

{
  int iVar1;
  uint8_t cornerC;
  int iVar2;
  int x1;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined1 uVar9;
  undefined2 uVar8;
  undefined2 unaff_DI;
  int *piVar10;
  undefined2 uVar11;
  uint8_t uStack_a;
  uint8_t uStack_8;
  uint8_t uStack_6;
  uint8_t uStack_4;
  
  iVar1 = y * 3;
  iVar2 = x * 2;
  x1 = iVar2 + 0xc;
  iVar3 = ovc13_usesSeedD110(x,y + 1);
  iVar4 = ovc13_usesSeedD110(x,y);
  iVar5 = ovc13_usesSeedD110(x + 1,y + 1);
  iVar6 = ovc13_usesSeedD110(x + 1,y);
  uVar7 = ovc13_usesSeedD1102(x,y);
  cornerC = (uint8_t)uVar7;
  uVar9 = (undefined1)(uVar7 >> 8);
  uStack_a = (uint8_t)iVar6;
  uStack_8 = (uint8_t)iVar4;
  uStack_6 = (uint8_t)iVar5;
  uStack_4 = (uint8_t)iVar3;
  if ((uVar7 & 4) == 0) {
    uVar8 = ovr_constr_compute1(uStack_a,uStack_6,cornerC,2,(byte)unaff_DI,CONCAT11(uVar9,uStack_8))
    ;
    piVar10 = (int *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3);
    ovr_driver_fillSpan(iVar2 + 0xd,iVar1 + 7,(byte)uVar8,0x40,piVar10,x1);
    piVar10 = (int *)CONCAT22((int)((ulong)piVar10 >> 0x10),(char *)"puppetmaker" + 3);
    iVar3 = iVar2 + 0xd;
    ovr_driver_fillSpan(iVar2 + 0xd,iVar1 + 8,(byte)uVar8,0x40,piVar10,iVar3);
    uVar11 = (undefined2)((ulong)piVar10 >> 0x10);
    uVar8 = ovr_constr_compute1(uStack_6,uStack_8,cornerC,1,(byte)((ulong)piVar10 >> 0x10),
                                CONCAT11((char)((uint)iVar3 >> 8),uStack_4));
    piVar10 = (int *)CONCAT22(uVar11,(char *)"puppetmaker" + 3);
    ovr_driver_fillSpan(x1,iVar1 + 8,(byte)uVar8,0x40,piVar10,x1);
    ovr_driver_fillSpan(iVar2 + 0xd,iVar1 + 9,(byte)uVar8,0x40,
                        (int *)CONCAT22((int)((ulong)piVar10 >> 0x10),(char *)"puppetmaker" + 3),x1)
    ;
  }
  else {
    uVar8 = ovr_constr_compute1(uStack_a,uStack_4,cornerC,1,(byte)unaff_DI,CONCAT11(uVar9,uStack_8))
    ;
    piVar10 = (int *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3);
    ovr_driver_fillSpan(iVar2 + 0xd,iVar1 + 7,(byte)uVar8,0x40,piVar10,x1);
    piVar10 = (int *)CONCAT22((int)((ulong)piVar10 >> 0x10),(char *)"puppetmaker" + 3);
    iVar3 = iVar1 + 8;
    ovr_driver_fillSpan(x1,iVar3,(byte)uVar8,0x40,piVar10,x1);
    uVar11 = (undefined2)((ulong)piVar10 >> 0x10);
    uVar8 = ovr_constr_compute1(uStack_6,uStack_a,cornerC,2,(byte)((ulong)piVar10 >> 0x10),
                                CONCAT11((char)((uint)iVar3 >> 8),uStack_4));
    piVar10 = (int *)CONCAT22(uVar11,(char *)"puppetmaker" + 3);
    ovr_driver_fillSpan(iVar2 + 0xd,iVar1 + 8,(byte)uVar8,0x40,piVar10,iVar2 + 0xd);
    ovr_driver_fillSpan(iVar2 + 0xd,iVar1 + 9,(byte)uVar8,0x40,
                        (int *)CONCAT22((int)((ulong)piVar10 >> 0x10),(char *)"puppetmaker" + 3),x1)
    ;
  }
  return;
}



/* 3d16:0e03 */

/* [R6] touches screenY, EntityCount */

void __cdecl16far ovc13_usesScreenY2(void)

{
  uint uVar1;
  uint16_t uVar2;
  uint uVar3;
  int iVar4;
  int x1;
  int screenY;
  entity_t *peVar5;
  uint uVar6;
  undefined2 unaff_DI;
  undefined2 uVar7;
  byte bStack_3;
  
  if (unitTypeFilter == -1) {
    for (uVar6 = 0; uVar6 < EntityCount; uVar6 = uVar6 + 1) {
      uVar7 = (undefined2)((ulong)Entities >> 0x10);
      peVar5 = (entity_t *)Entities;
      uVar1 = ((peVar5 + uVar6)->base).x;
      uVar2 = peVar5[uVar6].base.y;
      uVar3 = uVar2 + 1;
      if (((((*(char *)((int)&peVar5[uVar6].base.entity + 1) != '\0') ||
            (*(char *)((int)(char **)GMenuStrings + (uint)peVar5[uVar6].base.gindex * 0x95 + 0x1f)
             == '\0')) || (DebugVerbose != false)) ||
          (((*(short (*) [60] [148])GMapFlags)[uVar2][uVar1] & 8U) != 0)) &&
         (((Seed_2000_d110 <= (int)uVar1 && (uVar1 <= Seed_2000_d110 + 0x69U)) &&
          ((Seed_2000_d10e <= (int)uVar3 && (uVar3 <= Seed_2000_d10e + 0x2fU)))))) {
        screenY = (uVar3 - Seed_2000_d10e) * 3 + 7;
        iVar4 = (uVar1 - Seed_2000_d110) * 2;
        x1 = iVar4 + 0xd;
        iVar4 = iVar4 + 0xc;
        uVar7 = ovc13_readPixel(iVar4,screenY,BlitRects);
        bStack_3 = (byte)uVar7;
        uVar7 = (undefined2)((ulong)Entities >> 0x10);
        peVar5 = (entity_t *)Entities;
        if (*(char *)((int)&peVar5[uVar6].base.entity + 1) == '\0') {
          if ((*(uint *)((int)&peVar5[uVar6].base.frames + 1) & 1) == 0) {
            if ((*(byte *)((int)&peVar5[uVar6].base.flags32 + 1) & 1) == 0) {
              if (((bStack_3 != 0xef) && (bStack_3 != 0xee)) && (bStack_3 != 0xeb)) {
                if (*(char *)((int)(char **)GMenuStrings +
                             (uint)peVar5[uVar6].base.gindex * 0x95 + 0x1f) == '\0') {
                  bStack_3 = 0xff;
                }
                else {
                  bStack_3 = 0xea;
                }
              }
            }
            else {
              bStack_3 = 0xee;
            }
          }
          else {
            bStack_3 = 0xeb;
          }
        }
        else {
          bStack_3 = 0xef;
        }
        ovr_driver_fillSpan(iVar4,screenY,bStack_3,0x40,
                            (int *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3),iVar4,0x40);
        ovr_driver_fillSpan(x1,screenY,0xec,0x40,(int *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3)
                            ,x1,0x40);
      }
    }
  }
  else {
    ovc13_drawWindowEntities();
  }
  return;
}



/* 3d16:1045 */

/* [R6] touches Entities, L_OVC13_3d16_1045_10C4 */

int __cdecl16far ovc13_usesEntities(int entityIndex)

{
  int iVar1;
  byte bVar2;
  entity_t *peVar3;
  undefined2 uVar4;
  
  peVar3 = (entity_t *)Entities;
  uVar4 = (undefined2)((ulong)Entities >> 0x10);
  if (unitTypeFilter == 0xfe) {
L_OVC13_3d16_1045_10C4:
    if (partyFilter == -1) {
      if (*(char *)((int)(char **)GMenuStrings + (uint)peVar3[entityIndex].base.gindex * 0x95 + 0x1f
                   ) == '\0') {
        iVar1 = 1;
      }
      else {
        iVar1 = 0;
      }
    }
    else {
      bVar2 = (byte)((uint)(entityIndex * 0x37) >> 8);
      if (*(char *)((int)&peVar3[entityIndex].base.entity + 3) == partyFilter) {
        iVar1 = CONCAT11(bVar2,1);
      }
      else {
        iVar1 = (uint)bVar2 << 8;
      }
    }
  }
  else {
    if ((byte)((undefined1 *)&LevelRangeMin)[unitTypeFilter] <= peVar3[entityIndex].base.level) {
      if (peVar3[entityIndex].base.level <= (byte)((undefined1 *)&LevelRangeMax)[unitTypeFilter])
      goto L_OVC13_3d16_1045_10C4;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 3d16:113d */

/* Draws the entities inside the Seed_2000_d110/d10e window onto the panel, filtered by
   ovc13_usesEntities. */

void __cdecl16far ovc13_drawWindowEntities(void)

{
  uint uVar1;
  uint16_t uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int screenY;
  entity_t *peVar6;
  uint entityIndex;
  undefined2 unaff_DI;
  undefined2 uVar7;
  int iStack_c;
  byte bStack_3;
  
  for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
    uVar7 = (undefined2)((ulong)Entities >> 0x10);
    peVar6 = (entity_t *)Entities;
    uVar1 = ((peVar6 + entityIndex)->base).x;
    uVar2 = peVar6[entityIndex].base.y;
    uVar3 = uVar2 + 1;
    if (((((*(char *)((int)&peVar6[entityIndex].base.entity + 1) != '\0') ||
          (*(char *)((int)(char **)GMenuStrings + iStack_c * 0x95 + 0x1f) == '\0')) ||
         (DebugVerbose != false)) || (((*(short (*) [60] [148])GMapFlags)[uVar2][uVar1] & 8U) != 0))
       && (((iVar4 = ovc13_usesEntities(entityIndex), (char)iVar4 != '\0' &&
            (Seed_2000_d110 <= (int)uVar1)) &&
           ((uVar1 <= Seed_2000_d110 + 0x69U &&
            ((Seed_2000_d10e <= (int)uVar3 && (uVar3 <= Seed_2000_d10e + 0x2fU)))))))) {
      screenY = (uVar3 - Seed_2000_d10e) * 3 + 7;
      iVar5 = (uVar1 - Seed_2000_d110) * 2;
      iVar4 = iVar5 + 0xd;
      iVar5 = iVar5 + 0xc;
      uVar7 = ovc13_readPixel(iVar5,screenY,BlitRects);
      bStack_3 = (byte)uVar7;
      uVar7 = (undefined2)((ulong)Entities >> 0x10);
      peVar6 = (entity_t *)Entities;
      if (*(char *)((int)&peVar6[entityIndex].base.entity + 1) == '\0') {
        if ((*(uint *)((int)&peVar6[entityIndex].base.frames + 1) & 1) == 0) {
          if ((*(byte *)((int)&peVar6[entityIndex].base.flags32 + 1) & 1) == 0) {
            if (((bStack_3 != 0xef) && (bStack_3 != 0xee)) && (bStack_3 != 0xeb)) {
              if (*(char *)((int)(char **)GMenuStrings +
                           (uint)peVar6[entityIndex].base.gindex * 0x95 + 0x1f) == '\0') {
                bStack_3 = 0xff;
              }
              else {
                bStack_3 = 0xea;
              }
            }
          }
          else {
            bStack_3 = 0xee;
          }
        }
        else {
          bStack_3 = 0xeb;
        }
      }
      else {
        bStack_3 = 0xef;
      }
      ovr_driver_fillSpan(iVar5,screenY,bStack_3,0x40,
                          (int *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3),iVar5,0x40);
      ovr_driver_fillSpan(iVar4,screenY,0xec,0x40,
                          (int *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3),iVar4,0x40);
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
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint unaff_DI;
  int *piVar7;
  undefined2 uVar8;
  byte bStack_3;
  
  if (Highlight1 == -1) {
    piVar7 = (int *)((ulong)unaff_DI << 0x10);
    bVar4 = ovr_manage_findFirstLeader();
    for (bStack_3 = 0; bStack_3 < GLeaderCount; bStack_3 = bStack_3 + 1) {
      if (*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3d) != '\0') {
        uVar1 = *(uint *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x39);
        uVar2 = *(uint *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3b);
        if ((((*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3f) == '\0') ||
             (DebugVerbose != false)) ||
            (((*(short (*) [60] [148])GMapFlags)[uVar2][uVar1] & 8U) != 0)) &&
           (((Seed_2000_d110 <= (int)uVar1 && (uVar1 <= Seed_2000_d110 + 0x69U)) &&
            ((Seed_2000_d10e <= (int)uVar2 && (uVar2 <= Seed_2000_d10e + 0x2fU)))))) {
          iVar3 = (uVar2 - Seed_2000_d10e) * 3;
          iVar5 = (uVar1 - Seed_2000_d110) * 2;
          iVar6 = iVar5 + 10;
          uVar8 = (undefined2)((ulong)piVar7 >> 0x10);
          if (bVar4 == bStack_3) {
            piVar7 = (int *)CONCAT22(uVar8,(char *)"puppetmaker" + 3);
            ovr_driver_fillSpan(iVar5 + 0xf,iVar3 + 9,0x75,0x40,piVar7,iVar5 + 8);
            piVar7 = (int *)CONCAT22((int)((ulong)piVar7 >> 0x10),(char *)"puppetmaker" + 3);
            ovr_driver_fillSpan(iVar5 + 0xf,iVar3 + 10,0x75,0x40,piVar7,iVar5 + 8);
            piVar7 = (int *)CONCAT22((int)((ulong)piVar7 >> 0x10),(char *)"puppetmaker" + 3);
            ovr_driver_fillSpan(iVar5 + 0xf,iVar3 + 0xb,0x75,0x40,piVar7,iVar5 + 8);
          }
          else {
            piVar7 = (int *)CONCAT22(uVar8,(char *)"puppetmaker" + 3);
            ovr_driver_fillSpan(iVar5 + 0xd,iVar3 + 9,0x75,0x40,piVar7,iVar6);
            piVar7 = (int *)CONCAT22((int)((ulong)piVar7 >> 0x10),(char *)"puppetmaker" + 3);
            ovr_driver_fillSpan(iVar5 + 0xd,iVar3 + 10,0x75,0x40,piVar7,iVar6);
            piVar7 = (int *)CONCAT22((int)((ulong)piVar7 >> 0x10),(char *)"puppetmaker" + 3);
            ovr_driver_fillSpan(iVar5 + 0xd,iVar3 + 0xb,0x75,0x40,piVar7,iVar6);
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
  undefined2 uVar1;
  undefined1 uVar3;
  uint uVar2;
  byte *pbVar4;
  short *psVar5;
  int x;
  int iVar6;
  char *unaff_SS;
  char *arg1;
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
  
  Seed_2000_d110 = GfxRndSeed + -0x35;
  Seed_2000_d10e = (uint16_t)((GfxRndSeed2 + -0x18));
  if (Seed_2000_d110 < 0) {
    Seed_2000_d110 = 0;
  }
  if ((int)Seed_2000_d10e < 0) {
    Seed_2000_d10e = (uint16_t)(0x0);
  }
  if (0x92 < Seed_2000_d110 + 0x69U) {
    Seed_2000_d110 = 0x29;
  }
  if ((char *)"Divide error\r\n" + 0xb < Seed_2000_d10e + 0x2f) {
    Seed_2000_d10e = (uint16_t)(__C0_ASM_CopyRight + 7);
  }
  uStack_22 = BlitRects[0].seg;
  iStack_18 = 7;
  for (iStack_16 = 0; iStack_16 < 0x30; iStack_16 = iStack_16 + 1) {
    x = 0xc;
    pbStack_8 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),
                                  (*(byte (*) [59] [148])GMapCells)
                                  [(int)(Seed_2000_d10e + iStack_16 + 1)] + Seed_2000_d110);
    pbVar4 = (*(byte (*) [59] [148])GMapCells)[(int)(Seed_2000_d10e + iStack_16)] + Seed_2000_d110;
    pbStack_c = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),pbVar4);
    psVar5 = (*(short (*) [60] [148])GMapFlags)[(int)(Seed_2000_d10e + iStack_16)] + Seed_2000_d110;
    psStack_10 = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),psVar5);
    if (Seed_2000_d10e + iStack_16 != (byte *)0x0 &&
        SCARRY2((int)Seed_2000_d10e,iStack_16) == (int)(Seed_2000_d10e + iStack_16) < 0) {
      psVar5 = ((short (*) [60] [148])GMapFlags)[-1][(int)(Seed_2000_d10e + iStack_16 + 0x3b)] +
               Seed_2000_d110;
    }
    psStack_14 = (uint *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),psVar5);
    iStack_1c = (int)(char)*pbStack_8;
    pbStack_8 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),
                                  (*(byte (*) [59] [148])GMapCells)
                                  [(int)(Seed_2000_d10e + iStack_16 + 1)] + Seed_2000_d110 + 1);
    iStack_20 = (int)(char)*pbStack_c;
    pbStack_c = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(GMapCells) + 2)),pbVar4 + 1);
    for (iVar6 = 0; iVar6 < 0x69; iVar6 = iVar6 + 1) {
      iStack_1a = iStack_1c;
      iStack_1e = iStack_20;
      iStack_1c = (int)(char)*pbStack_8;
      pbStack_8 = (byte *)CONCAT22(uStack_6,pbStack_8 + 1);
      iStack_20 = (int)(char)*pbStack_c;
      pbStack_c = (byte *)CONCAT22(uStack_a,pbStack_c + 1);
      uStack_28 = *psStack_10;
      psStack_10 = (uint *)CONCAT22(uStack_e,psStack_10 + 1);
      uStack_2a = *psStack_14;
      psStack_14 = (uint *)CONCAT22(uStack_12,psStack_14 + 1);
      if ((uStack_28 & 4) == 0) {
        uVar1 = ovr_constr_compute1();
        uVar3 = (undefined1)((uint)uVar1 >> 8);
        ovr_constr_compute1((uint8_t)iStack_20,(uint8_t)iStack_1c,(uint8_t)uStack_28,2,(byte)uVar1,
                            CONCAT11(uVar3,(undefined1)iStack_1e),CONCAT11(uVar3,(uint8_t)iStack_20)
                           );
        ovr_driver_compute4();
      }
      else {
        uVar1 = ovr_constr_compute1();
        uVar3 = (undefined1)((uint)uVar1 >> 8);
        ovr_constr_compute1((uint8_t)iStack_20,(uint8_t)iStack_1a,(uint8_t)uStack_28,1,(byte)uVar1,
                            CONCAT11(uVar3,(undefined1)iStack_1e),CONCAT11(uVar3,(uint8_t)iStack_20)
                           );
        ovr_driver_compute3();
      }
      if (((uStack_28 | uStack_2a) & 0xc000) != 0) {
        ovc13_compute2(x,iStack_18,(byte)(uStack_2a >> 0xe),(byte)(uStack_28 >> 0xe),uStack_22);
      }
      x = x + 2;
    }
    ovc13_drawPanelCell(0x69,iStack_16);
    iStack_18 = iStack_18 + 3;
  }
  ovc13_drawPanelHighlight();
  ovc13_drawHighlightedUnits();
  iStack_24 = (GfxRndSeed - Seed_2000_d110) * 2 + 7;
  iStack_26 = ((int)GfxRndSeed2 - (int)Seed_2000_d10e) * 3 + 8;
  ovr_driver_fillSpan();
  ovr_driver_fillSpan();
  ovr_ovc07_usesFillRect();
  ovr_ovc07_usesFillRect();
  ovc13_usesScreenY2();
  uStack_4 = TextBlitDstSeg;
  TextBlitDstSeg = BlitRects[0].seg;
  TextBlitX = 0xb6;
  TextBlitY = 10;
  if (GameRunning == false) {
    arg1 = GfxRndSeed2;
    uVar2 = ovr_alignUp4();
    ovr_stsprintf((char *)CONCAT22(0x864,unaff_SS),(char *)CONCAT22(uVar2,(char *)"puppetmaker" + 3)
                  ,arg1,&msg);
    ovr_blitText();
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
  uint16_t unaff_DI;
  int in_stack_00000004;
  far_t gfx;
  char playSound;
  far_t dst;
  
  uVar1 = Seed_2000_d110 + in_stack_00000004 + 2U & 0xfffc;
  iVar2 = (x + -2) / 3 + Seed_2000_d10e;
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
  if ((((char)y != '\0') || (GfxRndSeed != uVar1)) || (GfxRndSeed2 != iVar2)) {
    dst.seg = unaff_DI;
    dst.ofs = 0xa000;
    gfx.seg = 0xc31d;
    gfx.ofs = FontHandle.seg;
    ovr_blitLoadRleGfx(gfx,dst,FontHandle.ofs);
    playSound = (char)dst.seg;
    ovr_attact_usesAgntFlag1();
    AgntFlag1 = false;
    GfxRndSeed2 = iVar2;
    GfxRndSeed = uVar1;
    ovr_ovc41_usesAgnt_clear(playSound,1);
  }
  return;
}



/* 3d16:1a01 */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far ovc13_usesBlitLoadRleGfx3(int x,int y,char force,...)

{
  uint uVar1;
  int iVar2;
  uint16_t unaff_DI;
  int in_stack_00000004;
  far_t gfx;
  char playSound;
  far_t dst;
  
  uVar1 = PanelGridX + in_stack_00000004 + 2U & 0xfffc;
  iVar2 = (x + -2) / 3 + PanelGridY;
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
  if ((((char)y != '\0') || (GfxRndSeed != uVar1)) || (GfxRndSeed2 != iVar2)) {
    dst.seg = unaff_DI;
    dst.ofs = 0xa000;
    gfx.seg = 0xc31d;
    gfx.ofs = FontHandle.seg;
    ovr_blitLoadRleGfx(gfx,dst,FontHandle.ofs);
    playSound = (char)dst.seg;
    ovr_attact_usesAgntFlag1();
    AgntFlag1 = false;
    GfxRndSeed2 = iVar2;
    GfxRndSeed = uVar1;
    ovr_ovc41_usesAgnt_clear(playSound,1);
  }
  return;
}



/* 3d16:1abd */

/* [R4] calls ovr_blitRect */

void __cdecl16far ovc13_usesBlitRect(void)

{
  undefined4 in_stack_0000fffa;
  brect_t *pbVar1;
  uint uVar2;
  
  BlitRects[3].seg = GSavedBlitSeg;
  uVar2 = (uint)((ulong)in_stack_0000fffa >> 0x10);
  if (MiceNeedsUpdate == '\0') {
    pbVar1 = (brect_t *)CONCAT22(uVar2,(brect_t *)((char *)"puppetmaker" + 3));
    ovr_miceRestoreArea(pbVar1,0x45e);
    uVar2 = (uint)(CONCAT13(1,(int3)pbVar1) >> 0x10);
  }
  else {
    uVar2 = uVar2 & 0xff;
  }
  ovc13_usesBlitRects();
  if ((char)(uVar2 >> 8) != '\0') {
    pbVar1 = (brect_t *)CONCAT22(uVar2,(brect_t *)((char *)"puppetmaker" + 3));
    ovr_miceBlitRect(pbVar1,0x45e);
    uVar2 = (uint)((ulong)pbVar1 >> 0x10);
  }
  pbVar1 = (brect_t *)CONCAT22(uVar2,(brect_t *)((char *)"puppetmaker" + 3));
  ovr_blitRect(pbVar1,0x45e);
  if ((char)((ulong)pbVar1 >> 0x18) != '\0') {
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
  int iVar4;
  int iVar5;
  int iVar6;
  unit_t *puVar7;
  uint uVar8;
  uint unaff_DI;
  undefined2 uVar9;
  int *piVar10;
  
  piVar10 = (int *)((ulong)unaff_DI << 0x10);
  if (Highlight1 != -1) {
    for (uVar8 = 0xf8; uVar8 < GUnitCount; uVar8 = uVar8 + 1) {
      uVar9 = (undefined2)((ulong)GUnits >> 0x10);
      puVar7 = (unit_t *)GUnits;
      if (((puVar7[uVar8].unitType != 0xff) &&
          (uVar3 = *(undefined4 *)((uint)puVar7[uVar8].unitType << 2),
          *(char *)((int)uVar3 + 0x3f) == '\0')) &&
         ((puVar7[uVar8].unitType == Highlight1 || (Highlight1 == 0xff)))) {
        uVar1 = puVar7[uVar8].x;
        uVar2 = puVar7[uVar8].y;
        if (((((Highlight1 == -2) && (puVar7[uVar8].level < 8)) ||
             (*(char *)((uint)(puVar7 + uVar8)->bldType * 0x27 + 0x133) == Highlight1)) &&
            ((Seed_2000_d110 <= (int)uVar1 && (uVar1 <= Seed_2000_d110 + 0x69U)))) &&
           ((Seed_2000_d10e <= (int)uVar2 && (uVar2 <= Seed_2000_d10e + 0x2fU)))) {
          iVar4 = (uVar2 - Seed_2000_d10e) * 3;
          iVar5 = (uVar1 - Seed_2000_d110) * 2 + 0xc;
          iVar6 = (uint)*(byte *)((uint)(puVar7 + uVar8)->bldType * 0x27 + 0x11b) * 2 + -1;
          piVar10 = (int *)CONCAT22((int)((ulong)piVar10 >> 0x10),(char *)"puppetmaker" + 3);
          ovr_driver_fillSpan(iVar5 + iVar6,iVar4 + 9,0x75,0x40,piVar10,iVar5);
          piVar10 = (int *)CONCAT22((int)((ulong)piVar10 >> 0x10),(char *)"puppetmaker" + 3);
          ovr_driver_fillSpan(iVar5 + iVar6,iVar4 + 10,0x75,0x40,piVar10,iVar5);
          piVar10 = (int *)CONCAT22((int)((ulong)piVar10 >> 0x10),(char *)"puppetmaker" + 3);
          ovr_driver_fillSpan(iVar5 + iVar6,iVar4 + 0xb,0x75,0x40,piVar10,iVar5);
        }
      }
    }
  }
  return;
}


