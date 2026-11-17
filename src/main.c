/*
 * main.c - recovered from STRONG.EXE
 * memory block: 1301_TEXT_main.c
 * range: 1301:000c - 1301:08d1
 */
#include "st.h"

/* 1301:000c */
int main(int argc, char **argv, char **envp)
{
    char demo;
    byte keylo;
    byte mi;
    uint16_t key;

    GGameExe = argv[0];
    if (argc < 2) {
        GExeArg = "puppetmaker";
    }
    else {
        GExeArg = argv[1];
    }
    init_game();
    do {
        demo = run_demo();
    } while (demo == '\0');
    byte_2410_DATA_DGROUP_4757 = 1;
    save_49fd_081e(0);
    byte_2410_DATA_DGROUP_4757 = 0;
    GOngoingBattle = '\0';
    byte_2000_BSS_0067 = 0;
    GMenuItem = 5;
    byte_2000_BSS_003B = '\x01';
    byte_2000_BSS_0046 = 1;
    uiMainMenu();
    play_sfx(7, 0);
    do {
        /* Process Events */
        MiceUnkState = 1;
        key = draw_2e25_0d35();
        TextBlitDstSeg = 0xa000;
        GGameState = 0x21;
        if (DebugVerbose) {
            printf("%d \r", 0x21);
        }
        if (key == 0xffff) {
            draw_2e25_17b3();
        }
        GGameState = 0x16;
        if (DebugVerbose) {
            printf("%d \r", 0x16);
        }
        if (key == 0x2f56) {
L_main_051D:
            OVC41_6a8f_1847();
        }
        else if (key < 0x2f57) {
            if (key == 0x1454) {
L_main_0702:
                if (GMenuItem < 5) {
                    draw_2e25_10c7();
                    OVC41_6a8f_04c0(CONCAT11(0x24, GMenuItem));
                    byte_2000_BSS_003B = '\x01';
                }
            }
            else if (key < 0x1455) {
                if (key == 0xd2b) {
L_main_081F:
                    if (GMenuItem < 5) {
                        byte_2000_BSS_003B = '\x02';
                        draw_2e25_0098();
                        attact_3f0b_18fe();
                        draw_2e25_025a();
                    }
                }
                else if (key < 0xd2c) {
                    if (key == 0x433) {
L_main_0532:
                        keylo = (byte)key;
                        mi = (keylo & 0xf) - 1;
                        if (((undefined1 *)&byte_2000_BSS_07AA)[mi] != -1) {
                            if ((GMenuItem == mi) &&
                                (byte_2000_BSS_003B == '\x01')) {
                                byte_2000_BSS_003B = '\x02';
                            }
                            else {
                                byte_2000_BSS_003B = '\x01';
                            }
                            GMenuItem = mi;
                            if (byte_2000_BSS_003B == '\x02') {
                                attact_3f0b_18fe();
                            }
                            draw_2e25_130a();
                            draw_2e25_025a();
                            if (byte_2000_BSS_003B == '\x01') {
                                OVC41_6a8f_04c0(CONCAT11(0x24, GMenuItem));
                            }
                        }
                    }
                    else if (key < 0x434) {
                        if (key == 0x11b)
                            goto L_main_0525;
                        if ((key == 0x231) || (key == 0x332))
                            goto L_main_0532;
                    }
                    else {
                        if ((key == 0x534) || (key == 0x635))
                            goto L_main_0532;
                        if (key == 0xc2d)
                            goto L_main_07BF;
                    }
                }
                else if (key == 0xf09) {
L_main_0382:
                    do {
                        if (GMenuItem == 0) {
                            GMenuItem = 5;
                        }
                        else {
                            GMenuItem = GMenuItem - 1;
                        }
                    } while ((GMenuItem != 5) &&
                             (((undefined1 *)&byte_2000_BSS_07AA)[GMenuItem] == -1));
                    byte_2000_BSS_003B = '\0';
                    draw_2e25_130a();
                    draw_2e25_025a();
                }
                else if (key < 0xf0a) {
                    if ((key == 0xd3b) || (key == 0xd3d))
                        goto L_main_081F;
                    if (key == 0xf00)
                        goto L_main_0382;
                }
                else if ((key == 0x1352) || (key == 0x1372)) {
L_main_0741:
                    if (GMenuItem < 5) {
                        draw_2e25_10c7();
                        OVC41_6a8f_04c0(CONCAT11(0x24, GMenuItem));
                        byte_2000_BSS_003B = '\x01';
                    }
                }
            }
            else if (key == 0x1e61) {
L_main_066C:
                if (GMenuItem < 5) {
                    if (GOngoingBattle == '\0') {
                        OVC41_6a8f_1847();
                    }
                    ui_unit_order_6616_0689(CONCAT11(0x24, GMenuItem));
                }
            }
            else if (key < 0x1e62) {
                if (key == 0x1950) {
L_main_0515:
                    toggle_pause();
                }
                else if (key < 0x1951) {
                    if (key == 0x1474)
                        goto L_main_0702;
                    if (((key == 0x184f) || (key == 0x186f)) &&
                        (byte_2000_BSS_077A != '\0')) {
                        manage_4d05_1835();
                    }
                }
                else {
                    if (key == 0x1970)
                        goto L_main_0515;
                    if (key == 0x1c0d) {
                        do {
                            GMenuItem = GMenuItem + 1;
                            if (5 < GMenuItem) {
                                GMenuItem = 0;
                            }
                        } while ((GMenuItem != 5) &&
                                 (((undefined1 *)&byte_2000_BSS_07AA)[GMenuItem] == -1));
                        byte_2000_BSS_003B = '\0';
                        draw_2e25_130a();
                        draw_2e25_025a();
                    }
                    else if (key == 0x1e41)
                        goto L_main_066C;
                }
            }
            else if (key == 0x266c) {
L_main_0780:
                if (GMenuItem < 5) {
                    draw_2e25_10c7();
                    OVC41_6a8f_04c0(CONCAT11(0x24, GMenuItem));
                    byte_2000_BSS_003B = '\x01';
                }
            }
            else if (key < 0x266d) {
                if ((key == 0x2247) || (key == 0x2267)) {
                    GMenuItem = 5;
                    byte_2000_BSS_003B = '\x01';
                    draw_2e25_130a();
                    draw_2e25_025a();
                }
                else if (key == 0x2646)
                    goto L_main_0780;
            }
            else if (((key == 0x2e43) || (key == 0x2e63)) &&
                     (GMenuItem < 5)) {
                draw_2e25_10c7();
                OVC41_6a8f_04c0(CONCAT11(0x24, GMenuItem));
                byte_2000_BSS_003B = '\x01';
            }
        }
        else if (key == 0x4800) {
            OVC41_6a8f_15a0();
        }
        else if (key < 0x4801) {
            if (key == 0x3920) {
                if ((GOngoingBattle == '\0') &&
                    (demo = OVC15_4207_288b(), demo != '\0')) {
                    drawTextAt("Sorry, you may not pass time during a battle.",
                               0xa000);
                }
                else {
                    byte_2410_DATA_DGROUP_0161 = 1;
                    drawTextAt("Time passes...", 0xa000);
                    if (GPaused != '\0') {
                        GPaused = 0;
                        update_pause_button();
                        OVC28_6018_0000(3);
                        GPaused = '\x01';
                        update_pause_button();
                    }
                }
            }
            else if (key < 0x3921) {
                if (key == 0x332c)
                    goto L_main_0702;
                if (key < 0x332d) {
                    if (key == 0x2f76)
                        goto L_main_051D;
                    if ((key == 0x3042) || (key == 0x3062))
                        goto L_main_0780;
                }
                else if (key == 0x333c) {
L_main_07BF:
                    if (GMenuItem < 5) {
                        byte_2000_BSS_003B = '\x02';
                        draw_2e25_0098();
                        attact_3f0b_18fe();
                        draw_2e25_025a();
                    }
                }
                else {
                    if (key == 0x342e)
                        goto L_main_0741;
                    if (key == 0x343e)
                        goto L_main_081F;
                }
            }
            else if (key == 0x4100) {
                land_info(2);
            }
            else if (key < 0x4101) {
                if (key == 0x3b00) {
L_main_0525:
                    attact_3f0b_0685();
                    uiMainMenu();
                }
                else if (key == 0x3f00) {
                    land_info(0);
                }
                else if (key == 0x4000) {
                    land_info(1);
                }
            }
            else if (key == 0x4200) {
                land_info(3);
            }
            else if (key == 0x4700) {
                OVC41_6a8f_15a0();
            }
        }
        else {
            if (key == 0x4e2b)
                goto L_main_081F;
            if (key < 0x4e2c) {
                if (key == 0x4b00) {
                    OVC41_6a8f_15a0();
                }
                else if (key < 0x4b01) {
                    if (key == 0x4900) {
                        OVC41_6a8f_15a0();
                    }
                    else if ((key == 0x492d) || (key == 0x4a2d))
                        goto L_main_07BF;
                }
                else {
                    if ((key == 0x4b34) || (key == 0x4c35))
                        goto L_main_0532;
                    if (key == 0x4d00) {
                        OVC41_6a8f_15a0();
                    }
                }
            }
            else {
                if (key == 0x5032)
                    goto L_main_0532;
                if (key < 0x5033) {
                    if (key == 0x4f00) {
                        OVC41_6a8f_15a0();
                    }
                    else {
                        if (key == 0x4f31)
                            goto L_main_0532;
                        if (key == 0x5000) {
                            OVC41_6a8f_15a0();
                        }
                    }
                }
                else if (key == 0x5100) {
                    OVC41_6a8f_15a0();
                }
                else if (key == 0x5133)
                    goto L_main_0532;
            }
        }
        if (GGameInProgress != '\0') {
            uiMainMenu();
        }
        GGameState = 0x17;
        if (DebugVerbose) {
            printf("%d \r", 0x17);
        }
    } while (1);
}
