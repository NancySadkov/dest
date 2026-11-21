undefined2 __cdecl16far run_demo(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t cmap;
  far_t cmap_00;
  far_t cmap_01;
  far_t cmap_02;
  far_t cmap_03;
  far_t cmap_04;
  far_t cmap_05;
  far_t cmap_06;
  far_t palette_00;
  far_t handle;
  far_t palette_01;
  far_t palette_02;
  far_t handle_00;
  far_t palette_03;
  far_t palette_04;
  far_t palette_05;
  far_t palette_06;
  far_t palette_07;
  far_t palette_08;
  far_t palette_09;
  far_t palette_10;
  far_t palette_11;
  far_t palette_12;
  far_t handle_01;
  far_t palette_13;
  far_t palette_14;
  far_t handle_02;
  far_t palette_15;
  far_t palette_16;
  far_t handle_03;
  far_t palette_17;
  byte bVar1;
  char *pcVar2;
  undefined2 uVar3;
  undefined1 extraout_AH;
  undefined1 uVar5;
  uint8_t *puVar4;
  uint16_t uVar6;
  int iVar7;
  uint16_t unaff_DI;
  int iVar8;
  uint unaff_SS;
  undefined1 uVar9;
  uint8_t palette;
  stg_tmp_t *psStack_c;
  uint16_t uStack_a;
  byte bStack_7;
  byte bStack_6;
  byte bStack_5;
  byte bStack_4;
  byte bStack_3;
  
  srand8(100);
  MenuMode = 0;
  Difficulty = 0;
  worldIndex = 0;
  GameRunning = true;
  ovr_init_usesClearEntities();
  GameRunning = false;
  srand8(0xda);
  demoCenterX = 0x58;
  demoCenterY = 0x24;
  bStack_4 = ovr_ovc30_textDivideError(10,1,'\x02',100,1,2);
  GfxRndSeed = demoCenterX;
  GfxRndSeed2 = demoCenterY;
  uVar3 = ((undefined2 *)((uint)bStack_4 * 4))[1];
  strcpy((char *)CONCAT13((char)((uint)uVar3 >> 8),
                          CONCAT12((char)uVar3,*(undefined2 *)((uint)bStack_4 * 4))),"Nasher");
  bStack_5 = ovr_ovc30_textDivideError(10,1,'\x02',100,1,2);
  uVar3 = ((undefined2 *)((uint)bStack_5 * 4))[1];
  strcpy((char *)CONCAT13((char)((uint)uVar3 >> 8),
                          CONCAT12((char)uVar3,*(undefined2 *)((uint)bStack_5 * 4))),"Fordor");
  bStack_6 = ovr_ovc30_textDivideError(10,1,'\x02',100,1,2);
  uVar3 = ((undefined2 *)((uint)bStack_6 * 4))[1];
  strcpy((char *)CONCAT13((char)((uint)uVar3 >> 8),
                          CONCAT12((char)uVar3,*(undefined2 *)((uint)bStack_6 * 4))),"Kaunas");
  ovc42_populateArea(bStack_4);
  for (iVar8 = -2; iVar8 < 3; iVar8 = iVar8 + 1) {
    for (iVar7 = -1; iVar7 < 1; iVar7 = iVar7 + 1) {
      ovr_ovc18_usesRandBelow(iVar8 + 0x48,iVar7 + 0x24,0,0xff,(char)(iVar7 + 0x24),0);
    }
  }
  ovr_ovc18_usesRandBelow(0x49,0x24,0x40,0xff,0x24,0x40);
  ovr_ovc18_usesRandBelow(0x47,0x23,0x3e,0xff,0x23,0x3e);
  ovr_ovc18_usesRandBelow(0x46,0x23,0x26,0xff,0x23,0x26);
  ovr_ovc18_usesRandBelow(GfxRndSeed,GfxRndSeed2,0,0xff,(char)GfxRndSeed2,0);
  ovr_ovc18_usesRandBelow(GfxRndSeed - 1,GfxRndSeed2,0x8c,0xff,(char)GfxRndSeed2,0x8c);
  ovr_ovc30_textDivideError(4,1,'\x01',100,1,1);
  bStack_3 = ovr_ovc30_textDivideError(0x1a,1,'\x01',100,1,1);
  uVar6 = 0x217a;
  uVar3 = ((undefined2 *)((uint)bStack_3 * 4))[1];
  strcpy((char *)CONCAT13((char)((uint)uVar3 >> 8),
                          CONCAT12((char)uVar3,*(undefined2 *)((uint)bStack_3 * 4))),"Mindark");
  ovr_ovc15_usesLDIV_at_(0x48,0x24,0x48,0x24,1,0x1,1,0x48,0x24,1,1);
  ovr_ovc15_usesLDIV_at_(0x48,0x24,0x48,0x24,2,0x1,1,0x48,0x24,2,1);
  ovr_ovc15_usesLDIV_at_(0x48,0x24,0x48,0x24,2,0x1,1,0x48,0x24,2,1);
  ovr_ovc15_usesLDIV_at_(0x48,0x24,0x48,0x24,0xb,0x1,1,0x48,0x24,0xb,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed - 1,GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,10,0x1,1,(char)(GfxRndSeed - 1),
             (char)GfxRndSeed2,10,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed - 1,GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,8,0x1,1,(char)(GfxRndSeed - 1),
             (char)GfxRndSeed2,8,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed - 1,GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,3,0x1,1,(char)(GfxRndSeed - 1),
             (char)GfxRndSeed2,3,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed - 5,GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,10,0x1,1,(char)(GfxRndSeed - 1),
             (char)GfxRndSeed2,10,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed - 5,GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,1,0x1,1,(char)(GfxRndSeed - 1),
             (char)GfxRndSeed2,1,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed - 5,GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,0,0x1,1,(char)(GfxRndSeed - 1),
             (char)GfxRndSeed2,0,1);
  GfxRndSeed = GfxRndSeed - 0x10;
  _fmemset((void *)(ulong)unaff_SS,0x300,unaff_DI);
  ovr_vgaSetPalette8bit(&palette);
  ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,0x3f,199,0,0);
  ovr_fmFree();
  ovr_play_sfx(137,0,0);
  bVar1 = 0x10;
  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)l9Cut4Seg;
  gfx.ofs = l9Cut4Ofs;
  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)l9Cut4Seg >> 8);
  ovr_ovc43_playArchiveFli(gfx,(uint16_t)&palette,(char)&palette);
  if (bVar1 < 2) {
    pcVar2 = ovc42_textProvidesMoreHousing(0x48);
    if ((byte)pcVar2 < 2) {
      uVar5 = (undefined1)unaff_SS;
      uVar9 = (undefined1)(unaff_SS >> 8);
      (*(uint8_t *)((uint8_t *)&(palette_00.seg))) = uVar5;
      palette_00.ofs = (uint16_t)&palette;
      (*(uint8_t *)((uint8_t *)&(palette_00.seg) + 1)) = uVar9;
      ovr_ovc40_usesVgaSetPalette8bit(palette_00);
      (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)ssilogoCut1Seg;
      handle.ofs = ssilogoCut1Ofs;
      (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)ssilogoCut1Seg >> 8);
      psStack_c = ovr_stshLoadGfx(handle);
      uStack_a = uVar6;
      memcpy((char *)CONCAT13(uVar9,CONCAT12(uVar5,&palette)),
             (char *)CONCAT13((char)(uVar6 >> 8),CONCAT12((char)uVar6,psStack_c)),0x300);
      ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,0x3f,199,0,0);
      (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = (char)ssilogoCut2Seg;
      gfx_01.ofs = ssilogoCut2Ofs;
      (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = (char)((uint)ssilogoCut2Seg >> 8);
      ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa0000000)),0);
      (*(uint8_t *)((uint8_t *)&(palette_01.seg))) = uVar5;
      palette_01.ofs = (uint16_t)&palette;
      (*(uint8_t *)((uint8_t *)&(palette_01.seg) + 1)) = uVar9;
      ovr_setSeasonPalette(palette_01);
      pcVar2 = ovc42_textProvidesMoreHousing(0x48);
      if ((byte)pcVar2 < 2) {
        (*(uint8_t *)((uint8_t *)&(palette_02.seg))) = uVar5;
        palette_02.ofs = (uint16_t)&palette;
        (*(uint8_t *)((uint8_t *)&(palette_02.seg) + 1)) = uVar9;
        ovr_ovc40_usesVgaSetPalette8bit(palette_02);
        ovr_fmFree();
        ovr_play_sfx(46,3,3);
        GameRunning = true;
        ovr_init_usesBlitGfxRect();
        (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)Lbm_nwpanel1.seg;
        handle_00.ofs = Lbm_nwpanel1.ofs;
        (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)(Lbm_nwpanel1.seg >> 8);
        psStack_c = ovr_stshLoadGfx(handle_00);
        uStack_a = uVar6;
        ovr_calcSeasonPalette(psStack_c->cmap,uVar6,&palette,(char)uVar6,(char)&palette);
        ovc42_copy1((char *)CONCAT13(uVar9,CONCAT12(uVar5,&palette)));
        ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,0x3f,199,0,0);
        bVar1 = ovr_ovc43_playFli(0x184,(uint16_t)&palette,(char)&palette);
        if (bVar1 < 2) {
          pcVar2 = ovc42_textProvidesMoreHousing(0x10);
          if ((byte)pcVar2 < 2) {
            (*(uint8_t *)((uint8_t *)&(palette_03.seg))) = uVar5;
            palette_03.ofs = (uint16_t)&palette;
            (*(uint8_t *)((uint8_t *)&(palette_03.seg) + 1)) = uVar9;
            ovr_ovc40_usesVgaSetPalette8bit(palette_03);
            ovr_init_usesBlitGfxRect();
            ovr_ovc28_textHalflingCastle();
            AgntFlag1 = false;
            ovr_ovc41_usesAgnt_clear('\0');
            ovc42_usesAgntCount();
            ovc42_drawTextRow("A new land lies before you. Choose carefully",0);
            ovc42_drawTextRow("where you settle.",1);
            ovr_ovc40_usesCalcSeasonPalette('\x01');
            ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
            uVar3 = ovc42_usesMiceBlitRect(0x32);
            if ((byte)uVar3 < 2) {
              ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
              GfxRndSeed = GfxRndSeed + 4;
              AgntFlag1 = false;
              ovr_ovc41_usesAgnt_clear('\0');
              ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
              uVar3 = ovc42_usesMiceBlitRect(0x32);
              if ((byte)uVar3 < 2) {
                ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                GfxRndSeed = GfxRndSeed + 4;
                AgntFlag1 = false;
                ovr_ovc41_usesAgnt_clear('\0');
                ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                uVar3 = ovc42_usesMiceBlitRect(0x32);
                if ((byte)uVar3 < 2) {
                  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                  GfxRndSeed = GfxRndSeed + 4;
                  AgntFlag1 = false;
                  ovr_ovc41_usesAgnt_clear('\0');
                  ovc42_drawTextRow("Your goal: Create a thriving community.",0);
                  ovc42_drawTextRow("Balance building, money, and food production",1);
                  ovc42_drawTextRow("to keep your people happy.",2);
                  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                  uVar3 = ovc42_usesMiceBlitRect(0x32);
                  if ((byte)uVar3 < 2) {
                    ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                    GfxRndSeed = GfxRndSeed + 4;
                    AgntFlag1 = false;
                    ovr_ovc41_usesAgnt_clear('\0');
                    ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                    uVar3 = ovc42_usesMiceBlitRect(0x4b);
                    if ((byte)uVar3 < 2) {
                      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                      ovr_ovc40_usesCalcSeasonPalette('\0');
                      ovc42_drawTextRow("Your world will be filled with a full range",0);
                      ovc42_drawTextRow("of official D&D@ game characters.",1);
                      (*(uint8_t *)((uint8_t *)&(cmap.seg))) = uVar5;
                      cmap.ofs = (uint16_t)&palette;
                      (*(uint8_t *)((uint8_t *)&(cmap.seg) + 1)) = uVar9;
                      ovc42_showAgentStats(0,bStack_4,'\0',cmap,0);
                      ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                      MiceUnkState = 0;
                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
                      uVar6 = ovr_inputUpdate(0x3c);
                      if ((byte)uVar6 < 2) {
                        ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                        (*(uint8_t *)((uint8_t *)&(palette_04.seg))) = uVar5;
                        palette_04.ofs = (uint16_t)&palette;
                        (*(uint8_t *)((uint8_t *)&(palette_04.seg) + 1)) = uVar9;
                        ovr_ovc40_usesVgaSetPalette8bit(palette_04);
                        (*(uint8_t *)((uint8_t *)&(cmap_00.seg))) = uVar5;
                        cmap_00.ofs = (uint16_t)&palette;
                        (*(uint8_t *)((uint8_t *)&(cmap_00.seg) + 1)) = uVar9;
                        ovc42_showAgentStats(3,bStack_5,'\x01',cmap_00,0);
                        ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                        (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                        (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
                        uVar6 = ovr_inputUpdate(0x32);
                        if ((byte)uVar6 < 2) {
                          ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                          (*(uint8_t *)((uint8_t *)&(palette_05.seg))) = uVar5;
                          palette_05.ofs = (uint16_t)&palette;
                          (*(uint8_t *)((uint8_t *)&(palette_05.seg) + 1)) = uVar9;
                          ovr_ovc40_usesVgaSetPalette8bit(palette_05);
                          (*(uint8_t *)((uint8_t *)&(cmap_01.seg))) = uVar5;
                          cmap_01.ofs = (uint16_t)&palette;
                          (*(uint8_t *)((uint8_t *)&(cmap_01.seg) + 1)) = uVar9;
                          ovc42_showAgentStats(8,bStack_6,'\x01',cmap_01,0);
                          ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                          (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                          (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
                          uVar6 = ovr_inputUpdate(0x32);
                          if ((byte)uVar6 < 2) {
                            ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                            (*(uint8_t *)((uint8_t *)&(palette_06.seg))) = uVar5;
                            palette_06.ofs = (uint16_t)&palette;
                            (*(uint8_t *)((uint8_t *)&(palette_06.seg) + 1)) = uVar9;
                            ovr_ovc40_usesVgaSetPalette8bit(palette_06);
                            (*(uint8_t *)((uint8_t *)&(cmap_02.seg))) = uVar5;
                            cmap_02.ofs = (uint16_t)&palette;
                            (*(uint8_t *)((uint8_t *)&(cmap_02.seg) + 1)) = uVar9;
                            ovc42_showAgentStats(1,bStack_6,'\0',cmap_02,0xc);
                            ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                            (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                            (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
                            uVar6 = ovr_inputUpdate(0x32);
                            if ((byte)uVar6 < 2) {
                              ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                              (*(uint8_t *)((uint8_t *)&(palette_07.seg))) = uVar5;
                              palette_07.ofs = (uint16_t)&palette;
                              (*(uint8_t *)((uint8_t *)&(palette_07.seg) + 1)) = uVar9;
                              ovr_ovc40_usesVgaSetPalette8bit(palette_07);
                              ovc42_drawTextRow("You are not alone in this pristine land.",0);
                              ovc42_drawTextRow("Official D&D@ game monsters will fight to",1);
                              ovc42_drawTextRow("destroy your city.",2);
                              (*(uint8_t *)((uint8_t *)&(cmap_03.seg))) = uVar5;
                              cmap_03.ofs = (uint16_t)&palette;
                              (*(uint8_t *)((uint8_t *)&(cmap_03.seg) + 1)) = uVar9;
                              ovc42_showAgentStats(0x15,bStack_3,'\x01',cmap_03,0);
                              ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                              (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                              (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
                              uVar6 = ovr_inputUpdate(0x32);
                              if ((byte)uVar6 < 2) {
                                ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                (*(uint8_t *)((uint8_t *)&(palette_08.seg))) = uVar5;
                                palette_08.ofs = (uint16_t)&palette;
                                (*(uint8_t *)((uint8_t *)&(palette_08.seg) + 1)) = uVar9;
                                ovr_ovc40_usesVgaSetPalette8bit(palette_08);
                                (*(uint8_t *)((uint8_t *)&(cmap_04.seg))) = uVar5;
                                cmap_04.ofs = (uint16_t)&palette;
                                (*(uint8_t *)((uint8_t *)&(cmap_04.seg) + 1)) = uVar9;
                                ovc42_showAgentStats(0x24,bStack_3,'\x01',cmap_04,0);
                                ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                                (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
                                uVar6 = ovr_inputUpdate(0x32);
                                if ((byte)uVar6 < 2) {
                                  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                  (*(uint8_t *)((uint8_t *)&(palette_09.seg))) = uVar5;
                                  palette_09.ofs = (uint16_t)&palette;
                                  (*(uint8_t *)((uint8_t *)&(palette_09.seg) + 1)) = uVar9;
                                  ovr_ovc40_usesVgaSetPalette8bit(palette_09);
                                  (*(uint8_t *)((uint8_t *)&(cmap_05.seg))) = uVar5;
                                  cmap_05.ofs = (uint16_t)&palette;
                                  (*(uint8_t *)((uint8_t *)&(cmap_05.seg) + 1)) = uVar9;
                                  ovc42_showAgentStats(0xe,bStack_3,'\x01',cmap_05,0);
                                  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                       *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
                                  uVar6 = ovr_inputUpdate(0x32);
                                  if ((byte)uVar6 < 2) {
                                    ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                    (*(uint8_t *)((uint8_t *)&(palette_10.seg))) = uVar5;
                                    palette_10.ofs = (uint16_t)&palette;
                                    (*(uint8_t *)((uint8_t *)&(palette_10.seg) + 1)) = uVar9;
                                    ovr_ovc40_usesVgaSetPalette8bit(palette_10);
                                    ovr_ovc28_textHalflingCastle();
                                    GfxRndSeed = 0x68;
                                    GfxRndSeed2 = 0x10;
                                    ovr_ovc18_usesRandBelow(0x68,0x10,0,0xff,0x10,0);
                                    ovr_ovc18_usesRandBelow
                                              (GfxRndSeed - 1,GfxRndSeed2,0x86,0xff,
                                               (char)GfxRndSeed2,0x86);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed - 2,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,0xd
                                               ,0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,0xd,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed - 2,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,
                                               0x21,0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,0x21,1)
                                    ;
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed - 2,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,
                                               0x16,0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,0x16,1)
                                    ;
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed - 2,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,7,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,7,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,1,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,1,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,1,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,1,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,0,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,0,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,0,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,0,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,3,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,3,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,5,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,5,1);
                                    AgntFlag1 = false;
                                    ovr_ovc41_usesAgnt_clear('\0');
                                    ovc42_drawTextRow("Force and fury meet magic spells as battles",
                                                      0);
                                    ovc42_drawTextRow(
                                                  "play out in the courtyards of mighty castles.",1)
                                    ;
                                    ovr_ovc40_usesCalcSeasonPalette('\x01');
                                    uVar3 = ovc42_usesMiceBlitRect(0xa0);
                                    if ((byte)uVar3 < 2) {
                                      ovr_ovc40_usesCalcSeasonPalette('\0');
                                      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                      ovc42_usesEntityCount();
                                      GfxRndSeed = 0x58;
                                      GfxRndSeed2 = 0x24;
                                      AgntFlag1 = false;
                                      ovr_ovc41_usesAgnt_clear('\0');
                                      ovc42_drawTextRow("Your people will fight bravely and work",0)
                                      ;
                                      ovc42_drawTextRow("hard. Your city will grow...",1);
                                      ovr_ovc40_usesCalcSeasonPalette('\x01');
                                      ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                      uVar3 = ovc42_usesMiceBlitRect(0x32);
                                      if ((byte)uVar3 < 2) {
                                        ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                        ovc42_usesGfxRndSeed();
                                        ovc42_drawTextRow("and grow...",2);
                                        AgntFlag1 = false;
                                        ovr_ovc41_usesAgnt_clear('\0');
                                        ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                        uVar3 = ovc42_usesMiceBlitRect(0x32);
                                        if ((byte)uVar3 < 2) {
                                          ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                          ovc42_usesGfxRndSeed();
                                          ovc42_drawTextRow("                     and grow...",2);
                                          AgntFlag1 = false;
                                          ovr_ovc41_usesAgnt_clear('\0');
                                          ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                          uVar3 = ovc42_usesMiceBlitRect(100);
                                          if ((byte)uVar3 < 2) {
                                            ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                            ovr_ovc40_usesCalcSeasonPalette('\0');
                                            ovc42_drawTextRow("But beware the evil Mindark, whose",0
                                                             );
                                            ovc42_drawTextRow(
                                                  "hordes destroyed your homeland long ago.",1);
                                            (*(uint8_t *)((uint8_t *)&(cmap_06.seg))) = uVar5;
                                            cmap_06.ofs = (uint16_t)&palette;
                                            (*(uint8_t *)((uint8_t *)&(cmap_06.seg) + 1)) = uVar9;
                                            ovc42_showAgentStats(0x29,bStack_3,'\x01',cmap_06,0);
                                            ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                            MiceUnkState = 0;
                                            uVar6 = ovr_inputUpdate(0x78);
                                            if ((byte)uVar6 < 2) {
                                              ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                              (*(uint8_t *)((uint8_t *)&(palette_11.seg))) = uVar5;
                                              palette_11.ofs = (uint16_t)&palette;
                                              (*(uint8_t *)((uint8_t *)&(palette_11.seg) + 1)) = uVar9;
                                              ovr_ovc40_usesVgaSetPalette8bit(palette_11);
                                              bVar1 = ovr_ovc40_usesAlignToSeg
                                                                ('\x04',(char *)0x7174,0x2410,
                                                                 (char *)0x7174,
                                                                 0x2410,2,0x74,0x10,0x74,0x10);
                                              if (bVar1 < 2) {
                                                ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10)
                                                ;
                                                demoCenterX = 0x58;
                                                demoCenterY = 0x1e;
                                                bStack_7 = ovr_ovc30_textDivideError
                                                                     (0xb,1,'\x02',100,1,2);
                                                GfxRndSeed = demoCenterX;
                                                GfxRndSeed2 = demoCenterY + 2;
                                                ovc42_populateArea(bStack_4);
                                                ovr_ovc18_usesRandBelow
                                                          (GfxRndSeed - 1,GfxRndSeed2 - 2,0,bStack_7
                                                           ,(char)(GfxRndSeed2 - 2),0);
                                                ovr_ovc18_usesRandBelow
                                                          (GfxRndSeed,GfxRndSeed2 - 2,0,bStack_7,
                                                           (char)(GfxRndSeed2 - 2),0);
                                                ovr_ovc18_usesRandBelow
                                                          (GfxRndSeed + 1,GfxRndSeed2 - 2,0,bStack_7
                                                           ,(char)(GfxRndSeed2 - 2),0);
                                                ovr_ovc18_usesRandBelow
                                                          (GfxRndSeed - 2,GfxRndSeed2 - 2,0x8b,
                                                           bStack_7,(char)(GfxRndSeed2 - 2),0x8b);
                                                AgntFlag1 = false;
                                                ovr_ovc41_usesAgnt_clear('\0');
                                                ovr_ovc40_usesCalcSeasonPalette('\x01');
                                                ovc42_drawTextRow(
                                                  "If you lead with wisdom and cunning...",0);
                                                ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                                uVar3 = ovc42_usesMiceBlitRect(0x3c);
                                                if ((byte)uVar3 < 2) {
                                                  GfxRndSeed2 = GfxRndSeed2 - 1;
                                                  AgntFlag1 = false;
                                                  ovr_ovc41_usesAgnt_clear('\0');
                                                  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),
                                                                      0x10);
                                                  ovc42_drawTextRow(
                                                  "If you fight with valor and guile...",1);
                                                  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                                  uVar3 = ovc42_usesMiceBlitRect(0x3c);
                                                  if ((byte)uVar3 < 2) {
                                                    GfxRndSeed2 = GfxRndSeed2 - 1;
                                                    AgntFlag1 = false;
                                                    ovr_ovc41_usesAgnt_clear('\0');
                                                    ovr_miceRestoreArea((brect_t *)(BlitRects + 1),
                                                                        0x10);
                                                    ovc42_drawTextRow(
                                                  "You will truly be master of your...",2);
                                                  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                                  uVar3 = ovc42_usesMiceBlitRect(0x3c);
                                                  if ((byte)uVar3 < 2) {
                                                    ovr_miceRestoreArea((brect_t *)(BlitRects + 1),
                                                                        0x10);
                                                    ovr_ovc40_usesCalcSeasonPalette('\0');
                                                    ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,
                                                                        0x3f,199,0,0);
                                                    ovr_freeLeaderData();
                                                    bVar1 = 0x10;
                                                    (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)sky06FliSeg;
                                                    gfx_00.ofs = sky06FliOfs;
                                                    (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) =
                                                         (char)((uint)sky06FliSeg >> 8);
                                                    ovr_ovc43_playArchiveFli
                                                              (gfx_00,(uint16_t)&palette,
                                                               (char)&palette);
                                                    if (bVar1 < 2) {
                                                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                           *(undefined2 *)
                                                            (BDA_DailyTimeCounter.ofs + 2);
                                                      uVar3 = *(undefined2 *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
                                                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = uVar3;
                                                      pcVar2 = ovc42_textProvidesMoreHousing(0x30);
                                                      if ((byte)pcVar2 < 2) {
                                                        (*(uint8_t *)((uint8_t *)&(palette_12.seg))) = uVar5;
                                                        palette_12.ofs = (uint16_t)&palette;
                                                        (*(uint8_t *)((uint8_t *)&(palette_12.seg) + 1)) = uVar9;
                                                        ovr_ovc40_usesVgaSetPalette8bit(palette_12);
                                                        (*(uint8_t *)((uint8_t *)&(handle_01.seg))) = (char)cred01Cut1Seg;
                                                        handle_01.ofs = cred01Cut1Ofs;
                                                        (*(uint8_t *)((uint8_t *)&(handle_01.seg) + 1)) =
                                                             (char)((uint)cred01Cut1Seg >> 8);
                                                        psStack_c = ovr_stshLoadGfx(handle_01);
                                                        uStack_a = uVar3;
                                                        memcpy((char *)CONCAT13(uVar9,CONCAT12(uVar5
                                                  ,&palette)),
                                                  (char *)CONCAT13((char)((uint)uVar3 >> 8),
                                                                   CONCAT12((char)uVar3,psStack_c)),
                                                  0x300);
                                                  ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,
                                                                      0x3f,199,0,0);
                                                  (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)cred01Cut2Seg;
                                                  gfx_02.ofs = cred01Cut2Ofs;
                                                  (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) =
                                                       (char)((uint)cred01Cut2Seg >> 8);
                                                  ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)(0xa0000000)),0);
                                                  (*(uint8_t *)((uint8_t *)&(palette_13.seg))) = uVar5;
                                                  palette_13.ofs = (uint16_t)&palette;
                                                  (*(uint8_t *)((uint8_t *)&(palette_13.seg) + 1)) = uVar9;
                                                  ovr_setSeasonPalette(palette_13);
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                       *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2)
                                                  ;
                                                  uVar3 = *(undefined2 *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = uVar3;
                                                  uVar6 = ovr_inputUpdate(0xb4);
                                                  if ((byte)uVar6 < 2) {
                                                    (*(uint8_t *)((uint8_t *)&(palette_14.seg))) = uVar5;
                                                    palette_14.ofs = (uint16_t)&palette;
                                                    (*(uint8_t *)((uint8_t *)&(palette_14.seg) + 1)) = uVar9;
                                                    ovr_ovc40_usesVgaSetPalette8bit(palette_14);
                                                    (*(uint8_t *)((uint8_t *)&(handle_02.seg))) = (char)cred02Cut1Seg;
                                                    handle_02.ofs = cred02Cut1Ofs;
                                                    (*(uint8_t *)((uint8_t *)&(handle_02.seg) + 1)) =
                                                         (char)((uint)cred02Cut1Seg >> 8);
                                                    psStack_c = ovr_stshLoadGfx(handle_02);
                                                    uStack_a = uVar3;
                                                    memcpy((char *)CONCAT13(uVar9,CONCAT12(uVar5,&
                                                  palette)),
                                                  (char *)CONCAT13((char)((uint)uVar3 >> 8),
                                                                   CONCAT12((char)uVar3,psStack_c)),
                                                  0x300);
                                                  ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,
                                                                      0x3f,199,0,0);
                                                  (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = (char)cred02Cut2Seg;
                                                  gfx_03.ofs = cred02Cut2Ofs;
                                                  (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) =
                                                       (char)((uint)cred02Cut2Seg >> 8);
                                                  ovr_blitLoadRleGfx(gfx_03,far_from_u32((uint32_t)(0xa0000000)),0);
                                                  (*(uint8_t *)((uint8_t *)&(palette_15.seg))) = uVar5;
                                                  palette_15.ofs = (uint16_t)&palette;
                                                  (*(uint8_t *)((uint8_t *)&(palette_15.seg) + 1)) = uVar9;
                                                  ovr_setSeasonPalette(palette_15);
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                       *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2)
                                                  ;
                                                  uVar3 = *(undefined2 *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = uVar3;
                                                  uVar6 = ovr_inputUpdate(0xb4);
                                                  if ((byte)uVar6 < 2) {
                                                    (*(uint8_t *)((uint8_t *)&(palette_16.seg))) = uVar5;
                                                    palette_16.ofs = (uint16_t)&palette;
                                                    (*(uint8_t *)((uint8_t *)&(palette_16.seg) + 1)) = uVar9;
                                                    ovr_ovc40_usesVgaSetPalette8bit(palette_16);
                                                    (*(uint8_t *)((uint8_t *)&(handle_03.seg))) = (char)cred03Cut1Seg;
                                                    handle_03.ofs = cred03Cut1Ofs;
                                                    (*(uint8_t *)((uint8_t *)&(handle_03.seg) + 1)) =
                                                         (char)((uint)cred03Cut1Seg >> 8);
                                                    psStack_c = ovr_stshLoadGfx(handle_03);
                                                    uStack_a = uVar3;
                                                    memcpy((char *)CONCAT13(uVar9,CONCAT12(uVar5,&
                                                  palette)),
                                                  (char *)CONCAT13((char)((uint)uVar3 >> 8),
                                                                   CONCAT12((char)uVar3,psStack_c)),
                                                  0x300);
                                                  ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,
                                                                      0x3f,199,0,0);
                                                  (*(uint8_t *)((uint8_t *)&(gfx_04.seg))) = (char)cred03Cut2Seg;
                                                  gfx_04.ofs = cred03Cut2Ofs;
                                                  (*(uint8_t *)((uint8_t *)&(gfx_04.seg) + 1)) =
                                                       (char)((uint)cred03Cut2Seg >> 8);
                                                  ovr_blitLoadRleGfx(gfx_04,far_from_u32((uint32_t)(0xa0000000)),0);
                                                  (*(uint8_t *)((uint8_t *)&(palette_17.seg))) = uVar5;
                                                  palette_17.ofs = (uint16_t)&palette;
                                                  (*(uint8_t *)((uint8_t *)&(palette_17.seg) + 1)) = uVar9;
                                                  ovr_setSeasonPalette(palette_17);
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                       *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2)
                                                  ;
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) =
                                                       *(undefined2 *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
                                                  uVar6 = ovr_inputUpdate(0xb4);
                                                  if ((byte)uVar6 < 2) {
                                                    ovc42_endDemo('\0',(int)&palette,unaff_SS);
                                                    GameRunning = false;
                                                    CurMusicType = 0xff;
                                                    CurSfxType3 = 0xff;
                                                    uVar3 = 0x2400;
                                                  }
                                                  else {
                                                    puVar4 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    puVar4 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    puVar4 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    puVar4 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    puVar4 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    ovc42_endDemo('\x01',0,0);
                                                    uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    ovc42_endDemo('\x01',0,0);
                                                    uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                                  }
                                                }
                                                else {
                                                  ovc42_endDemo('\x01',0,0);
                                                  uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                                }
                                              }
                                              else {
                                                uVar5 = extraout_AH;
                                                ovc42_endDemo('\x02',0,0);
                                                uVar3 = CONCAT11(uVar5,1);
                                              }
                                            }
                                            else {
                                              puVar4 = &palette;
                                              ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                                              uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                            }
                                          }
                                          else {
                                            ovc42_endDemo('\x01',0,0);
                                            uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                          }
                                        }
                                        else {
                                          ovc42_endDemo('\x01',0,0);
                                          uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                        }
                                      }
                                      else {
                                        ovc42_endDemo('\x01',0,0);
                                        uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                      }
                                    }
                                    else {
                                      ovc42_endDemo('\x01',0,0);
                                      uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                    }
                                  }
                                  else {
                                    puVar4 = &palette;
                                    ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                                    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                  }
                                }
                                else {
                                  puVar4 = &palette;
                                  ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                                  uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                }
                              }
                              else {
                                puVar4 = &palette;
                                ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                                uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                              }
                            }
                            else {
                              puVar4 = &palette;
                              ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                              uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                            }
                          }
                          else {
                            puVar4 = &palette;
                            ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                            uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                          }
                        }
                        else {
                          puVar4 = &palette;
                          ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                          uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                        }
                      }
                      else {
                        puVar4 = &palette;
                        ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                        uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                      }
                    }
                    else {
                      ovc42_endDemo('\x01',0,0);
                      uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                    }
                  }
                  else {
                    ovc42_endDemo('\x01',0,0);
                    uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                  }
                }
                else {
                  ovc42_endDemo('\x01',0,0);
                  uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                }
              }
              else {
                ovc42_endDemo('\x01',0,0);
                uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
              }
            }
            else {
              ovc42_endDemo('\x01',0,0);
              uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
            }
          }
          else {
            puVar4 = &palette;
            ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
            uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
          }
        }
        else {
          puVar4 = &palette;
          ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
          uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
        }
      }
      else {
        puVar4 = &palette;
        ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
        uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
      }
    }
    else {
      puVar4 = &palette;
      ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
      uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
    }
  }
  else {
    puVar4 = &palette;
    ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
  }
  return uVar3;
}
