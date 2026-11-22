/* ovc13_usesBlitRects - recovered from STRONG.EXE.
   row/col walk the 16x0x23 map-cell panel, destX/destY are the destination
   pixel coordinates (0xef/7 stepping by 2/3), cellsBelow/cellsHere and
   flagsHere/flagsAbove are the GMapCells/GMapFlags row cursors, flags/flagsLo
   are the flag word read from flagsHere.  The tail uses of the old iVar7/iVar8
   are separate values and are named offX/offY. */
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
  undefined2 uStack_1a;
  short *flagsHere;
  undefined2 uStack_16;
  byte *cellsHere;
  undefined2 uStack_12;
  byte *cellsBelow;
  undefined2 uStack_e;
  int destY;
  int row;
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
        uVar4 = ovr_constr_compute1(cornerA,cornerB,cornerC,flagsLo,1);
        uVar3 = (uint8_t)uVar4;
        uVar4 = ovr_constr_compute1(cornerC,cornerB_00,cornerB,flagsLo,2);
        ovr_driver_compute4(destX,(byte)destY,(uint8_t)uVar4,uVar3,uVar9);
      }
      else {
        uVar9 = seg;
        uVar4 = ovr_constr_compute1(cornerA,cornerB,cornerB_00,flagsLo,2);
        uVar3 = (uint8_t)uVar4;
        uVar4 = ovr_constr_compute1(cornerC,cornerB_00,cornerA,flagsLo,1);
        ovr_driver_compute3(destX,(byte)destY,(uint8_t)uVar4,uVar3,uVar9);
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
