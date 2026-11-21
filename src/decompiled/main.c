/*
 * main.c - recovered from STRONG.EXE
 * memory block: 1301_TEXT_main.c
 * range: 1301:000c - 1301:08d1
 * functions: 1
 */
#include "recovered.h"


/* 1301:000c */

int main(int argc,str_t *argv,str_t *envp)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint16_t uVar4;
  str_t *psVar5;
  undefined2 uVar6;
  byte bStack_6;
  
  uVar6 = (undefined2)((ulong)envp >> 0x10);
  psVar5 = (str_t *)envp;
  GGameExe.seg = psVar5->seg;
  GGameExe.ofs = (uint16_t)envp->ptr;
  if ((int)argv < 2) {
    GExeArg.seg = 0x2410;
    GExeArg.ofs = 0x94;
  }
  else {
    GExeArg.seg = psVar5[1].seg;
    GExeArg.ofs = (uint16_t)(psVar5 + 1)->ptr;
  }
  ovr_init_game();
  do {
    uVar3 = ovr_run_demo();
  } while ((uVar3 & 0xff) == 0);
  suppressLoadError = 1;
  ovr_save_loadGameFile();
  suppressLoadError = 0;
  GOngoingBattle = '\0';
  GBattleMode = 0;
  GMenuItem = 5;
  MenuMode = '\x01';
  menuEnteredFlag = 0x1;
  ovr_uiMainMenu();
  ovr_play_sfx(7,0);
  do {
                    /* Process Events */
    MiceUnkState = 1;
    uVar4 = ovr_draw_usesGameProcessKey();
    TextBlitDstSeg = 0xa000;
    GGameState = 0x21;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    if (uVar4 == 0xffff) {
      ovr_draw_usesToggle_pause();
    }
    GGameState = 0x16;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    if (uVar4 == 0x2f56) {
L_main_051D:
      ovr_ovc41_cannotSeeTerrainNotice();
    }
    else if (uVar4 < 0x2f57) {
      if (uVar4 == 0x1454) {
L_main_0702:
        if (GMenuItem < 5) {
          ovr_draw_menuCursor(0,0x1c);
          ovr_ovc41_unitStatusText(GMenuItem);
          MenuMode = '\x01';
        }
      }
      else if (uVar4 < 0x1455) {
        if (uVar4 == 0xd2b) {
L_main_081F:
          if (GMenuItem < 5) {
            MenuMode = '\x02';
            ovr_draw_usesFillRect2(((uint8_t *)menuItemRow)[GMenuItem] + 1,-0x6000);
            ovr_attact_updateAttractEntry((uint)GMenuItem,1);
            ovr_draw_textTalkwin9Lbm();
          }
        }
        else if (uVar4 < 0xd2c) {
          if (uVar4 == 0x433) {
L_main_0532:
            bStack_6 = (byte)uVar4;
            bVar1 = (bStack_6 & 0xf) - 1;
            if (((uint8_t *)MenuItemEnabled)[bVar1] != 0xff) {
              if ((GMenuItem == bVar1) && (MenuMode == '\x01')) {
                MenuMode = '\x02';
              }
              else {
                MenuMode = '\x01';
              }
              GMenuItem = bVar1;
              if (MenuMode == '\x02') {
                ovr_attact_updateAttractEntry((uint)bVar1,1);
              }
              ovr_draw_toolbarLabels();
              ovr_draw_textTalkwin9Lbm();
              if (MenuMode == '\x01') {
                ovr_ovc41_unitStatusText(GMenuItem);
              }
            }
          }
          else if (uVar4 < 0x434) {
            if (uVar4 == 0x11b) goto L_main_0525;
            if ((uVar4 == 0x231) || (uVar4 == 0x332)) goto L_main_0532;
          }
          else {
            if ((uVar4 == 0x534) || (uVar4 == 0x635)) goto L_main_0532;
            if (uVar4 == 0xc2d) goto L_main_07BF;
          }
        }
        else if (uVar4 == 0xf09) {
L_main_0382:
          do {
            if (GMenuItem == 0) {
              GMenuItem = 5;
            }
            else {
              GMenuItem = GMenuItem - 1;
            }
          } while ((GMenuItem != 5) && (((uint8_t *)MenuItemEnabled)[GMenuItem] == 0xff));
          MenuMode = '\0';
          ovr_draw_toolbarLabels();
          ovr_draw_textTalkwin9Lbm();
        }
        else if (uVar4 < 0xf0a) {
          if ((uVar4 == 0xd3b) || (uVar4 == 0xd3d)) goto L_main_081F;
          if (uVar4 == 0xf00) goto L_main_0382;
        }
        else if ((uVar4 == 0x1352) || (uVar4 == 0x1372)) {
L_main_0741:
          if (GMenuItem < 5) {
            ovr_draw_menuCursor(0x38,0x1c);
            ovr_ovc41_unitStatusText(GMenuItem);
            MenuMode = '\x01';
          }
        }
      }
      else if (uVar4 == 0x1e61) {
L_main_066C:
        if (GMenuItem < 5) {
          if (GOngoingBattle == '\0') {
            ovr_ovc41_cannotSeeTerrainNotice();
          }
          ovr_ui_textDefineRegionCommand(GMenuItem);
        }
      }
      else if (uVar4 < 0x1e62) {
        if (uVar4 == 0x1950) {
L_main_0515:
          ovr_toggle_pause();
        }
        else if (uVar4 < 0x1951) {
          if (uVar4 == 0x1474) goto L_main_0702;
          if (((uVar4 == 0x184f) || (uVar4 == 0x186f)) && (trianglesShown != '\0')) {
            ovr_manage_textHalflingCastle();
          }
        }
        else {
          if (uVar4 == 0x1970) goto L_main_0515;
          if (uVar4 == 0x1c0d) {
            do {
              GMenuItem = GMenuItem + 1;
              if (5 < GMenuItem) {
                GMenuItem = 0;
              }
            } while ((GMenuItem != 5) && (((uint8_t *)MenuItemEnabled)[GMenuItem] == 0xff));
            MenuMode = '\0';
            ovr_draw_toolbarLabels();
            ovr_draw_textTalkwin9Lbm();
          }
          else if (uVar4 == 0x1e41) goto L_main_066C;
        }
      }
      else if (uVar4 == 0x266c) {
L_main_0780:
        if (GMenuItem < 5) {
          ovr_draw_menuCursor(0x1c,0);
          ovr_ovc41_unitStatusText(GMenuItem);
          MenuMode = '\x01';
        }
      }
      else if (uVar4 < 0x266d) {
        if ((uVar4 == 0x2247) || (uVar4 == 0x2267)) {
          GMenuItem = 5;
          MenuMode = '\x01';
          ovr_draw_toolbarLabels();
          ovr_draw_textTalkwin9Lbm();
        }
        else if (uVar4 == 0x2646) goto L_main_0780;
      }
      else if (((uVar4 == 0x2e43) || (uVar4 == 0x2e63)) && (GMenuItem < 5)) {
        ovr_draw_menuCursor(0x1c,0xe);
        ovr_ovc41_unitStatusText(GMenuItem);
        MenuMode = '\x01';
      }
    }
    else if (uVar4 == 0x4800) {
      ovr_ovc41_usesBiosKeyAvail('\0',0);
    }
    else if (uVar4 < 0x4801) {
      if (uVar4 == 0x3920) {
        if ((GOngoingBattle == '\0') && (bVar2 = ovr_ovc15_usesAlignUp42(), bVar2)) {
          ovr_drawTextAt((char *)"Sorry, you may not pass time during a battle.",0x2410,0xa000);
        }
        else {
          timePassing = 1;
          ovr_drawTextAt((char *)"Time passes...",0x2410,0xa000);
          if (GPaused != '\0') {
            GPaused = 0;
            ovr_update_pause_button();
            ovr_ovc28_usesBDADailyTimeCounter(3);
            GPaused = '\x01';
            ovr_update_pause_button();
          }
        }
      }
      else if (uVar4 < 0x3921) {
        if (uVar4 == 0x332c) goto L_main_0702;
        if (uVar4 < 0x332d) {
          if (uVar4 == 0x2f76) goto L_main_051D;
          if ((uVar4 == 0x3042) || (uVar4 == 0x3062)) goto L_main_0780;
        }
        else if (uVar4 == 0x333c) {
L_main_07BF:
          if (GMenuItem < 5) {
            MenuMode = '\x02';
            ovr_draw_usesFillRect2(((uint8_t *)menuItemRow)[GMenuItem] - 1,-0x6000);
            ovr_attact_updateAttractEntry((uint)GMenuItem,1);
            ovr_draw_textTalkwin9Lbm();
          }
        }
        else {
          if (uVar4 == 0x342e) goto L_main_0741;
          if (uVar4 == 0x343e) goto L_main_081F;
        }
      }
      else if (uVar4 == 0x4100) {
        ovr_land_info(2);
      }
      else if (uVar4 < 0x4101) {
        if (uVar4 == 0x3b00) {
L_main_0525:
          ovr_attact_usesAgntFlag1();
          ovr_uiMainMenu();
        }
        else if (uVar4 == 0x3f00) {
          ovr_land_info(0);
        }
        else if (uVar4 == 0x4000) {
          ovr_land_info(1);
        }
      }
      else if (uVar4 == 0x4200) {
        ovr_land_info(3);
      }
      else if (uVar4 == 0x4700) {
        ovr_ovc41_usesBiosKeyAvail('\x03',1);
      }
    }
    else {
      if (uVar4 == 0x4e2b) goto L_main_081F;
      if (uVar4 < 0x4e2c) {
        if (uVar4 == 0x4b00) {
          ovr_ovc41_usesBiosKeyAvail('\x03',0);
        }
        else if (uVar4 < 0x4b01) {
          if (uVar4 == 0x4900) {
            ovr_ovc41_usesBiosKeyAvail('\0',1);
          }
          else if ((uVar4 == 0x492d) || (uVar4 == 0x4a2d)) goto L_main_07BF;
        }
        else {
          if ((uVar4 == 0x4b34) || (uVar4 == 0x4c35)) goto L_main_0532;
          if (uVar4 == 0x4d00) {
            ovr_ovc41_usesBiosKeyAvail('\x01',0);
          }
        }
      }
      else {
        if (uVar4 == 0x5032) goto L_main_0532;
        if (uVar4 < 0x5033) {
          if (uVar4 == 0x4f00) {
            ovr_ovc41_usesBiosKeyAvail('\x01',1);
          }
          else {
            if (uVar4 == 0x4f31) goto L_main_0532;
            if (uVar4 == 0x5000) {
              ovr_ovc41_usesBiosKeyAvail('\x02',0);
            }
          }
        }
        else if (uVar4 == 0x5100) {
          ovr_ovc41_usesBiosKeyAvail('\x02',1);
        }
        else if (uVar4 == 0x5133) goto L_main_0532;
      }
    }
    if (GGameInProgress != '\0') {
      ovr_uiMainMenu();
    }
    GGameState = 0x17;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
  } while( true );
}


