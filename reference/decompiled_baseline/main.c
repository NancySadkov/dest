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
  char *pcVar1;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  undefined2 in_stack_00000008;
  byte bStack_6;
  
  GGameExe.seg = argv->seg;
  GGameExe.ofs = (uint16_t)_argv->ptr;
  if (argc < 2) {
    GExeArg.seg = (int)(char *)"puppetmaker" + 3;
    GExeArg.ofs = 0x94;
  }
  else {
    GExeArg.seg = argv[1].seg;
    GExeArg.ofs = (uint16_t)(argv + 1)->ptr;
  }
  ovr_init_game();
  do {
    cVar2 = ovr_run_demo();
  } while (cVar2 == '\0');
  DAT_2410_4757 = 1;
  ovr_save_49fd_081e(0);
  DAT_2410_4757 = 0;
  GOngoingBattle = '\0';
  DAT_2000_ca9b = 0;
  GMenuItem = 5;
  DAT_2000_ca6f = '\x01';
  DAT_2000_ca7a = 1;
  ovr_uiMainMenu();
  ovr_play_sfx(7,0);
  do {
                    /* Process Events */
    MiceUnkState = 1;
    pcVar4 = (char *)ovr_draw_2e25_0d35();
    TextBlitDstSeg = 0xa000;
    GGameState = 0x21;
    if (DebugVerbose != false) {
      printf("%d \r",0x21);
    }
    if (pcVar4 == (char *)0xffff) {
      ovr_draw_2e25_17b3();
    }
    GGameState = 0x16;
    if (DebugVerbose != false) {
      printf("%d \r",0x16);
    }
    if (pcVar4 == (char *)"sword4.voc" + 8) {
LAB_1301_0529:
      ovr_OVC41_6a8f_1847();
    }
    else if (pcVar4 < (char *)"sword4.voc" + 9) {
      if (pcVar4 == (char *)0x1454) {
LAB_1301_070e:
        if (GMenuItem < 5) {
          ovr_draw_2e25_10c7();
          ovr_OVC41_6a8f_04c0(CONCAT11(0x24,GMenuItem));
          DAT_2000_ca6f = '\x01';
        }
      }
      else if (pcVar4 < (char *)0x1455) {
        if (pcVar4 == (char *)0xd2b) {
LAB_1301_082b:
          if (GMenuItem < 5) {
            DAT_2000_ca6f = '\x02';
            ovr_draw_2e25_0098();
            ovr_attact_3f0b_18fe();
            ovr_draw_2e25_025a();
          }
        }
        else if (pcVar4 < (char *)0xd2c) {
          if (pcVar4 == (char *)0x433) {
LAB_1301_053e:
            bStack_6 = (byte)pcVar4;
            bVar3 = (bStack_6 & 0xf) - 1;
            if (((undefined1 *)&DAT_2000_d1de)[bVar3] != -1) {
              if ((GMenuItem == bVar3) && (DAT_2000_ca6f == '\x01')) {
                DAT_2000_ca6f = '\x02';
              }
              else {
                DAT_2000_ca6f = '\x01';
              }
              GMenuItem = bVar3;
              if (DAT_2000_ca6f == '\x02') {
                ovr_attact_3f0b_18fe();
              }
              ovr_draw_2e25_130a();
              ovr_draw_2e25_025a();
              if (DAT_2000_ca6f == '\x01') {
                ovr_OVC41_6a8f_04c0(CONCAT11(0x24,GMenuItem));
              }
            }
          }
          else if (pcVar4 < (char *)0x434) {
            if (pcVar4 == (char *)0x11b) goto LAB_1301_0531;
            if ((pcVar4 == "nit") || (pcVar4 == "e %d %s  \r")) goto LAB_1301_053e;
          }
          else {
            if ((pcVar4 == (char *)0x534) || (pcVar4 == "pair")) goto LAB_1301_053e;
            if (pcVar4 == (char *)0xc2d) goto LAB_1301_07cb;
          }
        }
        else if (pcVar4 == (char *)0xf09) {
LAB_1301_038e:
          do {
            if (GMenuItem == 0) {
              GMenuItem = 5;
            }
            else {
              GMenuItem = GMenuItem - 1;
            }
          } while ((GMenuItem != 5) && (((undefined1 *)&DAT_2000_d1de)[GMenuItem] == -1));
          DAT_2000_ca6f = '\0';
          ovr_draw_2e25_130a();
          ovr_draw_2e25_025a();
        }
        else if (pcVar4 < (char *)0xf0a) {
          if ((pcVar4 == (char *)0xd3b) || (pcVar4 == (char *)0xd3d)) goto LAB_1301_082b;
          if (pcVar4 == (char *)0xf00) goto LAB_1301_038e;
        }
        else if ((pcVar4 == (char *)0x1352) || (pcVar4 == (char *)0x1372)) {
LAB_1301_074d:
          if (GMenuItem < 5) {
            ovr_draw_2e25_10c7();
            ovr_OVC41_6a8f_04c0(CONCAT11(0x24,GMenuItem));
            DAT_2000_ca6f = '\x01';
          }
        }
      }
      else if (pcVar4 == (char *)"mage university" + 9) {
LAB_1301_0678:
        if (GMenuItem < 5) {
          if (GOngoingBattle == '\0') {
            ovr_OVC41_6a8f_1847();
          }
          ovr_ui_unit_order_6616_0689(CONCAT11(0x24,GMenuItem));
        }
      }
      else if ((char *)"mage university" + 9 < pcVar4) {
        if (pcVar4 == (char *)"fire giant" + 7) {
LAB_1301_078c:
          if (GMenuItem < 5) {
            ovr_draw_2e25_10c7();
            ovr_OVC41_6a8f_04c0(CONCAT11(0x24,GMenuItem));
            DAT_2000_ca6f = '\x01';
          }
        }
        else if ((char *)"fire giant" + 7 < pcVar4) {
          if (((pcVar4 == (char *)"toads.lbm" + 7) || (pcVar4 == (char *)"harpy01.lbm" + 7)) &&
             (GMenuItem < 5)) {
            ovr_draw_2e25_10c7();
            ovr_OVC41_6a8f_04c0(CONCAT11(0x24,GMenuItem));
            DAT_2000_ca6f = '\x01';
          }
        }
        else if ((pcVar4 == (char *)"sturdy n/s gate" + 7) ||
                (pcVar4 == (char *)"manned n/s gate" + 7)) {
          GMenuItem = 5;
          DAT_2000_ca6f = '\x01';
          ovr_draw_2e25_130a();
          ovr_draw_2e25_025a();
        }
        else {
          pcVar1 = (char *)"purple worm" + 7;
joined_r0x00013272:
          if (pcVar4 == pcVar1) goto LAB_1301_078c;
        }
      }
      else if (pcVar4 == (char *)0x1950) {
LAB_1301_0521:
        ovr_toggle_pause();
      }
      else if (pcVar4 < (char *)0x1951) {
        if (pcVar4 == (char *)0x1474) goto LAB_1301_070e;
        if (((pcVar4 == (char *)0x184f) || (pcVar4 == (char *)0x186f)) && (DAT_2000_d1ae != '\0')) {
          ovr_manage_4d05_1835();
        }
      }
      else {
        if (pcVar4 == (char *)0x1970) goto LAB_1301_0521;
        if (pcVar4 == (char *)"%s: provides housing and income." + 8) {
          do {
            GMenuItem = GMenuItem + 1;
            if (5 < GMenuItem) {
              GMenuItem = 0;
            }
          } while ((GMenuItem != 5) && (((undefined1 *)&DAT_2000_d1de)[GMenuItem] == -1));
          DAT_2000_ca6f = '\0';
          ovr_draw_2e25_130a();
          ovr_draw_2e25_025a();
        }
        else if (pcVar4 == (char *)"mage school" + 2) goto LAB_1301_0678;
      }
    }
    else if (pcVar4 == (char *)0x4800) {
      ovr_OVC41_6a8f_15a0();
    }
    else if (pcVar4 < (char *)0x4801) {
      if (pcVar4 == (char *)"outdoor3.voc" + 0xc) {
        if ((GOngoingBattle == '\0') && (cVar2 = ovr_OVC15_4207_288b(), cVar2 != '\0')) {
          ovr_drawTextAt("Sorry, you may not pass time during a battle.",0xa000);
        }
        else {
          DAT_2410_0161 = 1;
          ovr_drawTextAt("Time passes...",0xa000);
          if (GPaused != '\0') {
            GPaused = 0;
            ovr_update_pause_button();
            ovr_OVC28_6018_0000(3);
            GPaused = '\x01';
            ovr_update_pause_button();
          }
        }
      }
      else if ((char *)"outdoor3.voc" + 0xc < pcVar4) {
        if (pcVar4 == (char *)"build\\thfgls02.lbm" + 8) {
          ovr_land_info(2);
        }
        else if ((char *)"build\\thfgls02.lbm" + 8 < pcVar4) {
          if (pcVar4 == (char *)"build\\elfarro1.lbm" + 0x11) {
            ovr_land_info(3);
          }
          else if (pcVar4 == (char *)"This location is unsuitable for a main stronghold.  %s" + 0x24
                  ) {
            ovr_OVC41_6a8f_15a0();
          }
        }
        else if (pcVar4 == (char *)"anim\\2phoen0.lbm" + 9) {
LAB_1301_0531:
          ovr_attact_3f0b_0685();
          ovr_uiMainMenu();
        }
        else if (pcVar4 == "uild\\elfres02.lbm") {
          ovr_land_info(0);
        }
        else if (pcVar4 == "") {
          ovr_land_info(1);
        }
      }
      else {
        if (pcVar4 == (char *)"anim\\1th1m.lbm" + 5) goto LAB_1301_070e;
        if (pcVar4 < (char *)"anim\\1th1m.lbm" + 6) {
          if (pcVar4 != (char *)"crash1.voc" + 9) {
            if (pcVar4 != (char *)"panel01.lbm") {
              pcVar1 = (char *)"mouse03.lbm" + 8;
              goto joined_r0x00013272;
            }
            goto LAB_1301_078c;
          }
          goto LAB_1301_0529;
        }
        if (pcVar4 == (char *)"anim\\1th1f.lbm" + 6) {
LAB_1301_07cb:
          if (GMenuItem < 5) {
            DAT_2000_ca6f = '\x02';
            ovr_draw_2e25_0098();
            ovr_attact_3f0b_18fe();
            ovr_draw_2e25_025a();
          }
        }
        else {
          if (pcVar4 == (char *)"anim\\1dw1f.lbm" + 8) goto LAB_1301_074d;
          if (pcVar4 == (char *)"anim\\1dw2m.lbm" + 9) goto LAB_1301_082b;
        }
      }
    }
    else {
      if (pcVar4 == (char *)"Select ability to adjust downwards by two points." + 0x23)
      goto LAB_1301_082b;
      if ((char *)"Select ability to adjust downwards by two points." + 0x23 < pcVar4) {
        if (pcVar4 == (char *)"Please type your character\'s name. Esc go back." + 8)
        goto LAB_1301_053e;
        if ((char *)"Please type your character\'s name. Esc go back." + 8 < pcVar4) {
          if (pcVar4 == (char *)"%s will now build homes automatically.") {
            ovr_OVC41_6a8f_15a0();
          }
          else if (pcVar4 == (char *)"%s will no longer build houses automatically." + 0xc)
          goto LAB_1301_053e;
        }
        else if (pcVar4 == (char *)"has achieved the rank of EMPEROR.  Congratulations!" + 0x17) {
          ovr_OVC41_6a8f_15a0();
        }
        else {
          if (pcVar4 == (char *)
                        "has destroyed all enemies and has achieved EMPEROR. Congratulations!" +
                        0x14) goto LAB_1301_053e;
          if (pcVar4 == (char *)"Reroll ability scores, or select the character\'s class." + 0x2b) {
            ovr_OVC41_6a8f_15a0();
          }
        }
      }
      else if (pcVar4 == (char *)0x4b00) {
        ovr_OVC41_6a8f_15a0();
      }
      else if (pcVar4 < (char *)0x4b01) {
        if (pcVar4 == (char *)"pasopl.adv" + 7) {
          ovr_OVC41_6a8f_15a0();
        }
        else if ((pcVar4 == (char *)0x492d) || (pcVar4 == (char *)0x4a2d)) goto LAB_1301_07cb;
      }
      else {
        if ((pcVar4 == (char *)0x4b34) || (pcVar4 == (char *)"Princess " + 5)) goto LAB_1301_053e;
        if (pcVar4 == (char *)"Food stored" + 8) {
          ovr_OVC41_6a8f_15a0();
        }
      }
    }
    if (DAT_2000_ca90 != '\0') {
      ovr_uiMainMenu();
    }
    GGameState = 0x17;
    if (DebugVerbose != false) {
      printf("%d \r",0x17);
    }
  } while( true );
}


