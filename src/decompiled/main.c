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
  uint16_t dst;
  str_t *psVar4;
  undefined2 uVar5;
  int16_t in_stack_0000fffa;
  
  uVar5 = (undefined2)((ulong)envp >> 0x10);
  psVar4 = (str_t *)envp;
  GGameExe.seg = psVar4->seg;
  GGameExe.ofs = (uint16_t)envp->ptr;
  if ((int)argv < 2) {
    GExeArg.seg = 0x2410;
    GExeArg.ofs = 0x94;
  }
  else {
    GExeArg.seg = psVar4[1].seg;
    GExeArg.ofs = (uint16_t)(psVar4 + 1)->ptr;
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
  ovr_play_sfx(0,in_stack_0000fffa,7);
  do {
                    /* Process Events */
    MiceUnkState = 1;
    dst = ovr_draw_usesGameProcessKey();
    TextBlitDstSeg = 0xa000;
    GGameState = 0x21;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    if (dst == 0xffff) {
      ovr_draw_usesToggle_pause();
    }
    GGameState = 0x16;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    if (dst == 0x2f56) {
L_main_051D:
      ovr_ovc41_cannotSeeTerrainNotice();
    }
    else if (dst < 0x2f57) {
      if (dst == 0x1454) {
L_main_0702:
        if (GMenuItem < 5) {
          ovr_draw_menuCursor(0x1c,dst,0);
          ovr_ovc41_unitStatusText((byte)dst,GMenuItem);
          MenuMode = '\x01';
        }
      }
      else if (dst < 0x1455) {
        if (dst == 0xd2b) {
L_main_081F:
          if (GMenuItem < 5) {
            MenuMode = '\x02';
            ovr_draw_usesFillRect2(0xa000,dst,((uint8_t *)menuItemRow)[GMenuItem] + 1);
            ovr_attact_updateAttractEntry(1,dst,(uint)GMenuItem);
            ovr_draw_textTalkwin9Lbm();
          }
        }
        else if (dst < 0xd2c) {
          if (dst == 0x433) {
L_main_0532:
            bVar1 = ((byte)dst & 0xf) - 1;
            if (((uint8_t *)MenuItemEnabled)[bVar1] != 0xff) {
              if ((GMenuItem == bVar1) && (MenuMode == '\x01')) {
                MenuMode = '\x02';
              }
              else {
                MenuMode = '\x01';
              }
              GMenuItem = bVar1;
              if (MenuMode == '\x02') {
                ovr_attact_updateAttractEntry(1,dst,(uint)bVar1);
              }
              bVar1 = (byte)dst;
              ovr_draw_toolbarLabels();
              ovr_draw_textTalkwin9Lbm();
              if (MenuMode == '\x01') {
                ovr_ovc41_unitStatusText(bVar1,GMenuItem);
              }
            }
          }
          else if (dst < 0x434) {
            if (dst == 0x11b) goto L_main_0525;
            if ((dst == 0x231) || (dst == 0x332)) goto L_main_0532;
          }
          else {
            if ((dst == 0x534) || (dst == 0x635)) goto L_main_0532;
            if (dst == 0xc2d) goto L_main_07BF;
          }
        }
        else if (dst == 0xf09) {
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
        else if (dst < 0xf0a) {
          if ((dst == 0xd3b) || (dst == 0xd3d)) goto L_main_081F;
          if (dst == 0xf00) goto L_main_0382;
        }
        else if ((dst == 0x1352) || (dst == 0x1372)) {
L_main_0741:
          if (GMenuItem < 5) {
            ovr_draw_menuCursor(0x1c,dst,0x38);
            ovr_ovc41_unitStatusText((byte)dst,GMenuItem);
            MenuMode = '\x01';
          }
        }
      }
      else if (dst == 0x1e61) {
L_main_066C:
        if (GMenuItem < 5) {
          if (GOngoingBattle == '\0') {
            ovr_ovc41_cannotSeeTerrainNotice();
          }
          ovr_ui_textDefineRegionCommand((byte)dst,GMenuItem);
        }
      }
      else if (dst < 0x1e62) {
        if (dst == 0x1950) {
L_main_0515:
          ovr_toggle_pause();
        }
        else if (dst < 0x1951) {
          if (dst == 0x1474) goto L_main_0702;
          if (((dst == 0x184f) || (dst == 0x186f)) && (trianglesShown != '\0')) {
            ovr_manage_textHalflingCastle();
          }
        }
        else {
          if (dst == 0x1970) goto L_main_0515;
          if (dst == 0x1c0d) {
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
          else if (dst == 0x1e41) goto L_main_066C;
        }
      }
      else if (dst == 0x266c) {
L_main_0780:
        if (GMenuItem < 5) {
          ovr_draw_menuCursor(0,dst,0x1c);
          ovr_ovc41_unitStatusText((byte)dst,GMenuItem);
          MenuMode = '\x01';
        }
      }
      else if (dst < 0x266d) {
        if ((dst == 0x2247) || (dst == 0x2267)) {
          GMenuItem = 5;
          MenuMode = '\x01';
          ovr_draw_toolbarLabels();
          ovr_draw_textTalkwin9Lbm();
        }
        else if (dst == 0x2646) goto L_main_0780;
      }
      else if (((dst == 0x2e43) || (dst == 0x2e63)) && (GMenuItem < 5)) {
        ovr_draw_menuCursor(0xe,dst,0x1c);
        ovr_ovc41_unitStatusText((byte)dst,GMenuItem);
        MenuMode = '\x01';
      }
    }
    else if (dst == 0x4800) {
      ovr_ovc41_usesBiosKeyAvail('\0',0);
    }
    else if (dst < 0x4801) {
      if (dst == 0x3920) {
        if ((GOngoingBattle == '\0') && (bVar2 = ovr_ovc15_usesAlignUp42(), bVar2)) {
          ovr_drawTextAt((char *)0xa0002410,dst,0x9a);
        }
        else {
          timePassing = 1;
          ovr_drawTextAt((char *)0xa0002410,dst,200);
          if (GPaused != '\0') {
            GPaused = 0;
            ovr_update_pause_button();
            ovr_ovc28_usesBDADailyTimeCounter(dst,3);
            GPaused = '\x01';
            ovr_update_pause_button();
          }
        }
      }
      else if (dst < 0x3921) {
        if (dst == 0x332c) goto L_main_0702;
        if (dst < 0x332d) {
          if (dst == 0x2f76) goto L_main_051D;
          if ((dst == 0x3042) || (dst == 0x3062)) goto L_main_0780;
        }
        else if (dst == 0x333c) {
L_main_07BF:
          if (GMenuItem < 5) {
            MenuMode = '\x02';
            ovr_draw_usesFillRect2(0xa000,dst,((uint8_t *)menuItemRow)[GMenuItem] - 1);
            ovr_attact_updateAttractEntry(1,dst,(uint)GMenuItem);
            ovr_draw_textTalkwin9Lbm();
          }
        }
        else {
          if (dst == 0x342e) goto L_main_0741;
          if (dst == 0x343e) goto L_main_081F;
        }
      }
      else if (dst == 0x4100) {
        ovr_land_info(0,2);
      }
      else if (dst < 0x4101) {
        if (dst == 0x3b00) {
L_main_0525:
          ovr_attact_usesAgntFlag1();
          ovr_uiMainMenu();
        }
        else if (dst == 0x3f00) {
          ovr_land_info(0,0);
        }
        else if (dst == 0x4000) {
          ovr_land_info(0,1);
        }
      }
      else if (dst == 0x4200) {
        ovr_land_info(0,3);
      }
      else if (dst == 0x4700) {
        ovr_ovc41_usesBiosKeyAvail('\x01',3);
      }
    }
    else {
      if (dst == 0x4e2b) goto L_main_081F;
      if (dst < 0x4e2c) {
        if (dst == 0x4b00) {
          ovr_ovc41_usesBiosKeyAvail('\0',3);
        }
        else if (dst < 0x4b01) {
          if (dst == 0x4900) {
            ovr_ovc41_usesBiosKeyAvail('\x01',0);
          }
          else if ((dst == 0x492d) || (dst == 0x4a2d)) goto L_main_07BF;
        }
        else {
          if ((dst == 0x4b34) || (dst == 0x4c35)) goto L_main_0532;
          if (dst == 0x4d00) {
            ovr_ovc41_usesBiosKeyAvail('\0',1);
          }
        }
      }
      else {
        if (dst == 0x5032) goto L_main_0532;
        if (dst < 0x5033) {
          if (dst == 0x4f00) {
            ovr_ovc41_usesBiosKeyAvail('\x01',1);
          }
          else {
            if (dst == 0x4f31) goto L_main_0532;
            if (dst == 0x5000) {
              ovr_ovc41_usesBiosKeyAvail('\0',2);
            }
          }
        }
        else if (dst == 0x5100) {
          ovr_ovc41_usesBiosKeyAvail('\x01',2);
        }
        else if (dst == 0x5133) goto L_main_0532;
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


