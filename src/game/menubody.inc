void __cdecl16far uiMainMenuLoop(void)

{
  far_t gfx;
  far_t items;
  far_t items_00;
  far_t items_01;
  far_t items_02;
  far_t handle;
  far_t handle_00;
  char *menu[8];
  char *yesno[2];
  uint8_t result;
  uint8_t selected;
  uint8_t extraout_AH;
  char *pcVar4;
  uint16_t uVar3;
  uint16_t uVar5;
  void *pvVar6;
  uint16_t *puVar7;
  undefined2 *puVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint16_t uVar12;
  uint16_t uVar13;
  int iVar14;
  far_t savearea;
  uint8_t bVar2;
  char cVar1;
  char exit_flag;
  char yes_picked;
  
  F_SCOPY(menu,(uint8_t *)GMenuStrings,0x20);
  F_SCOPY(yesno,(uint8_t *)GYesNo,8);
  ovr_say("Stronghold V 1.00");
  gfx.seg = GMenuGfxSeg;
  gfx.ofs = GMenuGfxOfs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)0xa00009af));
  ovr_stats_6386_00f8();
  saveui_4528_0533();
  savearea = ovr_stshAlloc(400);
  extraout_AH = 0;
  _fsetmem((void *)MK_FP(savearea.seg, savearea.ofs),400,0);
  uVar10 = 0;
  exit_flag = '\0';
  do {
    menu[1] = (SaveAuto == '\0') ? 0 : s_Save_Game_2410_27f4;
    menu[7] = ((GGameInProgress == '\0') && (SaveAuto != '\0'))
                ? s_Begin_Play_2410_283f : 0;
    items.seg = FP_SEG(menu);
    items.ofs = FP_OFF(menu);
    result = (uint8_t)uiMenu("Select an option:",items,8);
    ovr_say("");
    if (result < 9) {
                    /* WARNING: Switch is manually overridden */
      switch(result) {
      case 1:
        saveui_4528_0533();
        yes_picked = '\0';
        if ((SaveAuto == '\0') || (GWantsExit2 == '\0')) {
          yes_picked = '\x01';
        }
        else {
          items_00.seg = FP_SEG(yesno);
          items_00.ofs = FP_OFF(yesno);
          if ((uint8_t)uiMenu("Game not saved: Are you sure?",items_00,2) == 1) {
            yes_picked = '\x01';
          }
        }
        saveui_4528_0533();
        if (yes_picked != '\0') {
          ovr_copyProtectionCheck();
          saveui_4528_1ae8();
        }
        break;
      case 2:
        saveui_4528_0533();
        saveui_4528_1288(savearea.ofs,savearea.seg,uVar10);
        uVar10 = saveui_4528_1175(savearea.ofs,savearea.seg);
        uVar11 = 0;
        while( true ) {
          uVar13 = GSPEmpty.ofs;
          pvVar6 = (void *)savearea.ofs;
          uVar12 = savearea.seg;
          if (uVar10 <= uVar11) break;
          piVar9 = (int *)((int)pvVar6 + uVar11 * 4);
          if (*piVar9 == 0 && piVar9[1] == 0) {
            puVar7 = (uint16_t *)((int)pvVar6 + uVar11 * 4);
            puVar7[1] = GSPEmpty.seg;
            *puVar7 = uVar13;
            uVar5 = uVar13;
          }
          uVar11 = uVar11 + 1;
        }
        if (uVar10 < 100) {
          puVar7 = (uint16_t *)((int)pvVar6 + uVar10 * 4);
          puVar7[1] = GSPEmpty.seg;
          *puVar7 = uVar13;
          uVar5 = uVar13;
        }
        uVar10 = uVar10 + 1;
        bVar2 = saveui_4528_1470();
        uiMenu("Save Game:",savearea,uVar10);
        selected = bVar2;
        saveui_4528_144e();
        if (selected != 0) {
          iVar14 = strcmp((char *)*(undefined2 *)(savearea.ofs + (uint)selected * 4 + -4),
                          (char *)GSPEmpty.ofs);
          if (iVar14 == 0) {
            saveui_4528_0533();
            saveui_4528_1470();
            uVar3 = uiReadString(0x289e,0x2410,0,0,0);
            *(uint16_t *)(savearea.ofs + (uint)selected * 4 + -2) = uVar5;
            *(undefined2 *)(savearea.ofs + (uint)selected * 4 + -4) = uVar3;
            saveui_4528_144e();
          }
          else {
            saveui_4528_0533();
            saveui_4528_1470();
            uVar3 = uiReadString(0x28bf,0x2410,0,
                                 *(undefined2 *)(savearea.ofs + (uint)selected * 4 + -4),
                                 *(undefined2 *)(savearea.ofs + (uint)selected * 4 + -2));
            *(uint16_t *)(savearea.ofs + (uint)selected * 4 + -2) = uVar5;
            *(undefined2 *)(savearea.ofs + (uint)selected * 4 + -4) = uVar3;
            saveui_4528_144e();
          }
          if ((*(int *)(savearea.ofs + (uint)selected * 4 + -4) != 0 ||
               *(int *)(savearea.ofs + (uint)selected * 4 + -2) != 0) &&
             (iVar14 = strcmp((char *)*(undefined2 *)(savearea.ofs + (uint)selected * 4 + -4),
                              (char *)GSPEmpty.ofs), iVar14 == 0)) {
            handle.seg = *(uint16_t *)(savearea.ofs + (uint)selected * 4 + -2);
            handle.ofs = *(uint16_t *)(savearea.ofs + (uint)selected * 4 + -4);
            ovr_stshFree(handle);
            *(undefined2 *)(savearea.ofs + (uint)selected * 4 + -2) = 0;
            *(undefined2 *)(savearea.ofs + (uint)selected * 4 + -4) = 0;
          }
          uVar11 = *(uint *)(savearea.ofs + (uint)selected * 4 + -4) |
                   *(uint *)(savearea.ofs + (uint)selected * 4 + -2);
          if (uVar11 != 0) {
            cVar1 = ovr_stSave(CONCAT11((char)(uVar11 >> 8),selected));
            if (cVar1 == '\0') {
              *(undefined2 *)(savearea.ofs + (uint)selected * 4 + -2) = 0;
              *(undefined2 *)(savearea.ofs + (uint)selected * 4 + -4) = 0;
            }
            else {
              GWantsExit2 = '\0';
            }
            uVar11 = 0;
            while( true ) {
              if (uVar10 <= uVar11) break;
              iVar14 = strcmp((char *)*(undefined2 *)(savearea.ofs + uVar11 * 4),
                              (char *)GSPEmpty.ofs);
              if (iVar14 == 0) {
                puVar8 = (undefined2 *)((int)savearea.ofs + uVar11 * 4);
                puVar8[1] = 0;
                *puVar8 = 0;
              }
              uVar11 = uVar11 + 1;
            }
            while ((uVar10 != 0 &&
                   (piVar9 = (int *)(savearea.ofs + (uVar10 - 1) * 4),
                   *piVar9 == 0 && piVar9[1] == 0))) {
              uVar10 = uVar10 - 1;
            }
            saveui_4528_120d(savearea.ofs,savearea.seg,uVar10);
          }
        }
        saveui_4528_0533();
        break;
      case 3:
        saveui_4528_0533();
        saveui_4528_1288(savearea.ofs,savearea.seg,uVar10);
        uVar10 = saveui_4528_1175(savearea.ofs,savearea.seg);
        bVar2 = saveui_4528_1470();
        uiMenu("Load Game:",savearea,uVar10);
        selected = bVar2;
        saveui_4528_144e();
        if (selected != 0) {
          yes_picked = '\0';
          if ((SaveAuto == '\0') || (GWantsExit2 == '\0')) {
            yes_picked = '\x01';
          }
          else {
            saveui_4528_0533();
            items_01.seg = FP_SEG(yesno);
            items_01.ofs = FP_OFF(yesno);
            if ((uint8_t)uiMenu("Game not saved: Are you sure?",items_01,2) == 1) {
              yes_picked = '\x01';
            }
          }
          saveui_4528_0533();
          if (yes_picked != '\0') {
            ovr_save_49fd_081e(CONCAT11(extraout_AH,selected));
            GWantsExit2 = '\0';
          }
        }
        saveui_4528_0533();
        break;
      case 4:
        saveui_4528_0533();
        saveui_4528_1288(savearea.ofs,savearea.seg,uVar10);
        uVar10 = saveui_4528_1175(savearea.ofs,savearea.seg);
        bVar2 = saveui_4528_1470();
        uiMenu("Delete Game:",savearea,uVar10);
        selected = bVar2;
        saveui_4528_144e();
        if (selected != 0) {
          saveui_4528_0533();
          iVar14 = 2;
          pcVar4 = ovr_fmVsprintf((char *)"Delete %s: Are you sure?",
                                  (char *)*(undefined2 *)(savearea.ofs + (uint)selected * 4 + -4));
          items_02.seg = FP_SEG(yesno);
          items_02.ofs = FP_OFF(yesno);
          if ((uint8_t)uiMenu(pcVar4,items_02,2) == 1) {
            ovr_save_49fd_0f26(selected);
            handle_00.seg = *(uint16_t *)(savearea.ofs + (uint)selected * 4 + -2);
            handle_00.ofs = *(uint16_t *)(savearea.ofs + (uint)selected * 4 + -4);
            ovr_stshFree(handle_00);
            *(undefined2 *)(savearea.ofs + (uint)selected * 4 + -2) = 0;
            *(undefined2 *)(savearea.ofs + (uint)selected * 4 + -4) = 0;
            while ((uVar10 != 0 &&
                   (piVar9 = (int *)(savearea.ofs + (uVar10 - 1) * 4),
                   *piVar9 == 0 && piVar9[1] == 0))) {
              uVar10 = uVar10 - 1;
            }
          }
        }
        saveui_4528_120d(savearea.ofs,savearea.seg,uVar10);
        saveui_4528_0533();
        break;
      case 5:
        saveui_4528_0533();
        if (SaveAuto != '\0') {
          ovr_stSave(0);
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0);
      case 6:
        saveui_4528_1303();
        saveui_4528_0533();
        break;
      case 7:
        ovr_OVC38_68ac_0148();
        break;
      case 0:
      case 8:
        if ((GGameInProgress == '\0') && (SaveAuto != '\0')) {
          exit_flag = '\x01';
        }
      }
    }
  } while ((SaveAuto == '\0') || (exit_flag == '\0'));
  saveui_4528_1288(savearea.ofs,savearea.seg,uVar10);
  ovr_stshFree(savearea);
  ovr_OVC28_6018_0251();
  return;
}


