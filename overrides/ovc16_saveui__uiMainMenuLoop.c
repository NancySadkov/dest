void __cdecl16far uiMainMenuLoop(void)

{
  far_t gfx;
  far_t items;
  far_t items_00;
  far_t items_01;
  far_t items_02;
  far_t items_03;
  far_t items_04;
  far_t items_05;
  far_t entries;
  far_t entries_00;
  far_t entries_01;
  far_t entries_02;
  far_t entries_03;
  far_t entries_04;
  far_t dst;
  far_t dst_00;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  bool bVar1;
  bool bVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  byte bVar5;
  char cVar6;
  void *entries_05;
  uint16_t pmenu;
  uint16_t uVar7;
  int iVar8;
  char *pcVar9;
  char *title;
  uint16_t in_DX;
  uint16_t uVar10;
  uint *puVar11;
  uint16_t *puVar12;
  uint16_t *puVar13;
  int *piVar14;
  uint uVar15;
  uint uVar16;
  uint16_t unaff_SS;
  uint16_t uVar17;
  uint32_t menu;
  uint16_t uStack_30;
  uint16_t uStack_2e;
  uint16_t uStack_18;
  uint16_t uStack_16;
  byte bStack_13;
  char yesno [9];
  uint8_t yes_picked;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&menu;
  F_SCOPY(far_from_u32((uint32_t)(0x241026b7)),dst);
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)yesno;
  F_SCOPY(far_from_u32((uint32_t)(0x241026d7)),dst_00);
  ovr_say((char *)"Stronghold V 1.00",0x2410);
  gfx.seg = GMenuGfxSeg;
  gfx.ofs = GMenuGfxOfs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa00009af)));
  ovr_stats_drawStatsPanel();
  saveui_blitPanel();
  entries_05 = ovr_stshAlloc(400);
  uVar10 = in_DX;
  _fsetmem((void *)CONCAT22(in_DX,entries_05),400,0);
  uVar15 = 0;
  bVar2 = false;
  do {
    if (SaveAuto == '\0') {
      uStack_2e = 0;
      uStack_30 = 0;
    }
    else {
      uStack_2e = 0x2410;
      uStack_30 = 0x27f4;
    }
    if ((GGameInProgress == '\0') && (SaveAuto != '\0')) {
      uStack_16 = 0x2410;
      uStack_18 = 0x283f;
    }
    else {
      uStack_16 = 0;
      uStack_18 = 0;
    }
    pmenu = (uint16_t)&menu;
    items.seg = pmenu;
    items.ofs = 0x2410;
    uiMenu((char *)"Select an option:",items,unaff_SS,8);
    bStack_13 = (byte)pmenu;
    ovr_say((char *)0x26832,0x2410);
    if (bStack_13 < 9) {
                    /* WARNING: Switch is manually overridden */
      switch((uint32_t)
             *(uint16_t *)((char *)0x25bd6 + (uint)bStack_13 * 2)) {
      case 288826:
        saveui_blitPanel();
        bVar1 = false;
        if ((SaveAuto == '\0') || (GWantsExit2 == '\0')) {
          bVar1 = true;
        }
        else {
          pcVar9 = yesno;
          items_00.seg = (uint16_t)pcVar9;
          items_00.ofs = 0x2410;
          uiMenu((char *)"Game not saved: Are you sure?",items_00,unaff_SS,2);
          if ((char)pcVar9 == '\x01') {
            bVar1 = true;
          }
        }
        saveui_blitPanel();
        if (bVar1) {
          ovr_copyProtectionCheck();
          saveui_configureNewWorld();
        }
        break;
      case 288917:
        saveui_blitPanel();
        entries.seg = in_DX;
        entries.ofs = (uint16_t)entries_05;
        saveui_freeLines(entries,uVar15);
        uVar15 = saveui_readSavesList((int)entries_05,in_DX);
        uVar7 = uVar15;
        for (uVar16 = 0; uVar4 = GSPEmpty.seg, uVar3 = GSPEmpty.ofs, uVar16 < uVar15;
            uVar16 = uVar16 + 1) {
          puVar11 = (uint *)((int)entries_05 + uVar16 * 4);
          uVar7 = *puVar11 | puVar11[1];
          if (uVar7 == 0) {
            puVar12 = (uint16_t *)((int)entries_05 + uVar16 * 4);
            puVar12[1] = GSPEmpty.seg;
            *puVar12 = uVar3;
            uVar7 = uVar4;
            uVar10 = uVar3;
          }
        }
        if (uVar15 < 100) {
          puVar12 = (uint16_t *)((int)entries_05 + uVar15 * 4);
          puVar12[1] = GSPEmpty.seg;
          *puVar12 = uVar3;
          uVar7 = uVar4;
          uVar10 = uVar3;
        }
        bVar5 = (byte)uVar7;
        uVar15 = uVar15 + 1;
        saveui_drawCancel();
        items_01.seg = (uint16_t)entries_05;
        items_01.ofs = 0x2410;
        uiMenu((char *)"Save Game:",items_01,in_DX,uVar15);
        saveui_usesBlitLoadRleGfx4();
        if (bVar5 != 0) {
          iVar8 = strcmp((char *)CONCAT22(*(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -2),
                                          (char *)*(uint16_t *)
                                                   ((int)entries_05 + (uint)bVar5 * 4 + -4)),
                         (char *)CONCAT22(GSPEmpty.seg,GSPEmpty.ofs));
          if (iVar8 == 0) {
            saveui_blitPanel();
            saveui_drawCancel();
            pcVar9 = uiReadString((char *)"Name this save:  (Esc to cancel)",0x2410,0,(char *)0x0,0)
            ;
            *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -2) = uVar10;
            *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -4) =(uint16_t)( pcVar9);
            saveui_usesBlitLoadRleGfx4();
          }
          else {
            saveui_blitPanel();
            saveui_drawCancel();
            pcVar9 = uiReadString((char *)"Name for this save:  (Esc to cancel)",0x2410,0,
                                  (char *)*(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -4),
                                  *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -2));
            *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -2) = uVar10;
            *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -4) =(uint16_t)( pcVar9);
            saveui_usesBlitLoadRleGfx4();
          }
          if ((*(int *)((int)entries_05 + (uint)bVar5 * 4 + -4) != 0 ||
               *(int *)((int)entries_05 + (uint)bVar5 * 4 + -2) != 0) &&
             (iVar8 = strcmp((char *)CONCAT22(*(uint16_t *)
                                               ((int)entries_05 + (uint)bVar5 * 4 + -2),
                                              (char *)*(uint16_t *)
                                                       ((int)entries_05 + (uint)bVar5 * 4 + -4)),
                             (char *)CONCAT22(GSPEmpty.seg,GSPEmpty.ofs)), iVar8 == 0)) {
            handle.seg = *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -2);
            handle.ofs = *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -4);
            ovr_stshFree(handle);
            *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -2) = 0;
            *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -4) = 0;
          }
          if (*(int *)((int)entries_05 + (uint)bVar5 * 4 + -4) != 0 ||
              *(int *)((int)entries_05 + (uint)bVar5 * 4 + -2) != 0) {
            uVar17 = ovr_stSave();
            if ((char)uVar17 == '\0') {
              *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -2) = 0;
              *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -4) = 0;
            }
            else {
              GWantsExit2 = '\0';
            }
            for (uVar16 = 0; uVar16 < uVar15; uVar16 = uVar16 + 1) {
              puVar13 = (uint16_t *)((int)entries_05 + uVar16 * 4);
              iVar8 = strcmp((char *)CONCAT22(puVar13[1],(char *)*puVar13),
                             (char *)CONCAT22(GSPEmpty.seg,GSPEmpty.ofs));
              if (iVar8 == 0) {
                puVar13 = (uint16_t *)((int)entries_05 + uVar16 * 4);
                puVar13[1] = 0;
                *puVar13 = 0;
              }
            }
            while ((uVar15 != 0 &&
                   (piVar14 = (int *)((int)entries_05 + (uVar15 - 1) * 4),
                   *piVar14 == 0 && piVar14[1] == 0))) {
              uVar15 = uVar15 - 1;
            }
            entries_00.seg = in_DX;
            entries_00.ofs = (uint16_t)entries_05;
            saveui_writeSavesList(entries_00,uVar15);
          }
        }
        saveui_blitPanel();
        break;
      case 289563:
        saveui_blitPanel();
        entries_01.seg = in_DX;
        entries_01.ofs = (uint16_t)entries_05;
        saveui_freeLines(entries_01,uVar15);
        uVar15 = saveui_readSavesList((int)entries_05,in_DX);
        uVar16 = uVar15;
        saveui_drawCancel();
        cVar6 = (char)uVar16;
        items_02.seg = (uint16_t)entries_05;
        items_02.ofs = 0x2410;
        uiMenu((char *)"Load Game:",items_02,in_DX,uVar15);
        saveui_usesBlitLoadRleGfx4();
        if (cVar6 != '\0') {
          bVar1 = false;
          if ((SaveAuto == '\0') || (GWantsExit2 == '\0')) {
            bVar1 = true;
          }
          else {
            saveui_blitPanel();
            pcVar9 = yesno;
            items_03.seg = (uint16_t)pcVar9;
            items_03.ofs = 0x2410;
            uiMenu((char *)"Game not saved: Are you sure?",items_03,unaff_SS,2);
            if ((char)pcVar9 == '\x01') {
              bVar1 = true;
            }
          }
          saveui_blitPanel();
          if (bVar1) {
            ovr_save_loadGameFile();
            GWantsExit2 = '\0';
          }
        }
        saveui_blitPanel();
        break;
      case 289727:
        saveui_blitPanel();
        entries_02.seg = in_DX;
        entries_02.ofs = (uint16_t)entries_05;
        saveui_freeLines(entries_02,uVar15);
        uVar15 = saveui_readSavesList((int)entries_05,in_DX);
        uVar16 = uVar15;
        saveui_drawCancel();
        bVar5 = (byte)uVar16;
        items_04.seg = (uint16_t)entries_05;
        items_04.ofs = 0x2410;
        uiMenu((char *)"Delete Game:",items_04,in_DX,uVar15);
        saveui_usesBlitLoadRleGfx4();
        if (bVar5 != 0) {
          saveui_blitPanel();
          uVar17 = 2;
          pcVar9 = yesno;
          uVar7 = unaff_SS;
          title = ovr_fmVsprintf("Delete %s: Are you sure?",
                                 (char *)CONCAT22(*(uint16_t *)
                                                   ((int)entries_05 + (uint)bVar5 * 4 + -2),
                                                  (char *)*(uint16_t *)
                                                           ((int)entries_05 + (uint)bVar5 * 4 + -4))
                                );
          items_05.seg = (uint16_t)pcVar9;
          items_05.ofs = uVar10;
          uiMenu(title,items_05,uVar7,uVar17);
          if ((char)title == '\x01') {
            ovr_save_deleteGameFile();
            handle_00.seg = *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -2);
            handle_00.ofs = *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -4);
            ovr_stshFree(handle_00);
            *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -2) = 0;
            *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -4) = 0;
            while ((uVar15 != 0 &&
                   (piVar14 = (int *)((int)entries_05 + (uVar15 - 1) * 4),
                   *piVar14 == 0 && piVar14[1] == 0))) {
              uVar15 = uVar15 - 1;
            }
          }
        }
        entries_03.seg = in_DX;
        entries_03.ofs = (uint16_t)entries_05;
        saveui_writeSavesList(entries_03,uVar15);
        saveui_blitPanel();
        break;
      case 289977:
        saveui_blitPanel();
        if (SaveAuto != '\0') {
          ovr_stSave();
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0);
      case 290016:
        saveui_configureMessageDelay();
        saveui_blitPanel();
        break;
      case 290026:
        ovr_ovc38_showAchievements();
        break;
      case 290033:
        if ((GGameInProgress == '\0') && (SaveAuto != '\0')) {
          bVar2 = true;
        }
      }
    }
  } while ((SaveAuto == '\0') || (!bVar2));
  entries_04.seg = in_DX;
  entries_04.ofs = (uint16_t)entries_05;
  saveui_freeLines(entries_04,uVar15);
  handle_01.seg = in_DX;
  handle_01.ofs = (uint16_t)entries_05;
  ovr_stshFree(handle_01);
  ovr_ovc28_textHalflingCastle();
  return;
}
