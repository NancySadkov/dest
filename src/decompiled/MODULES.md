# Recovered module map

`src/decompiled/` mirrors the original Borland overlay segments. Each `OVCnn`
segment is a separate code segment from the original link. Where the segment's
source name was already known it is kept; the rest are numbered and described
by the functions/strings they contain.

| segment | recovered as | evidence / contents |
|---|---|---|
| `1000` | `crtl.c` | statically linked Borland C++ 3.0 runtime (FID-matched) |
| `1301` | `main.c` | `main()` |
| `138e` | `mouse.c`, `video.c` | mouse + video primitives |
| `1403` | `ovl.c` | Borland VROOMM overlay manager |
| `OVC01` | `ovc01_driver.c` | low-level VGA driver, blitting, palettes |
| `OVC02` | `ovc02_draw.c` | map/sprite draw pipeline, key processing |
| `OVC03` | `ovc03_font.c` | font/text rendering |
| `OVC04` | `ovc04.c` | LBM decoder: `lbm_decode_body`, `grabLbm`, `alignToSeg` |
| `OVC05` | `ovc05_error.c` | error handling |
| `OVC06` | `ovc06_blit.c` | blitting/RLE |
| `OVC07` | `ovc07.c` | unidentified (5 funcs, coordinate debug output) |
| `OVC08` | `ovc08_init2.c` | init helpers |
| `OVC09` | `ovc09_init.c` | init: paths, cfg, buffers, palettes, copy protection |
| `OVC10` | `ovc10_constr.c` | construction helpers |
| `OVC11` | `ovc11_audio.c` | sound effects / audio drivers |
| `OVC12` | `ovc12_agnt.c` | agents/entities |
| `OVC13` | `ovc13.c` | unidentified (20 funcs) |
| `OVC14` | `ovc14_attact.c` | attack/combat |
| `OVC15` | `ovc15.c` | sprite stash: `stshInitSprites`, `stshStoreSprite`, `stshRleAnims` |
| `OVC16` | `ovc16_saveui.c` | save/load UI |
| `OVC17` | `ovc17_stash.c` | stash container: `stshRead`, `initStshTables` |
| `OVC18` | `ovc18.c` | placement/build-mode UI (`View %s`, `Place %s`) |
| `OVC19` | `ovc19_save.c` | save/load |
| `OVC20` | `ovc20.c` | stash files, graphics and audio assets: `stshReadFile`, `stshWriteFile`, `grabBldLbm`, `stshInitAudioAssets` |
| `OVC21` | `ovc21_manage.c` | management/screens |
| `OVC22` | `ovc22.c` | unit update loop (`upd_units_...`) |
| `OVC23` | `ovc23.c` | character creation (`puppetmaker`, reroll scores) |
| `OVC24` | `ovc24.c` | intelligence/event reports |
| `OVC25` | `ovc25.c` | intelligence/spy reports |
| `OVC26` | `ovc26.c` | unidentified (3 funcs) |
| `OVC27` | `ovc27.c` | spells, turning undead, combat text |
| `OVC28` | `ovc28.c` | pause/menu and text input (`toggle_pause`, `uiInputText`) |
| `OVC29` | `ovc29_anim.c` | animation sequence init |
| `OVC30` | `ovc30.c` | battle waves / enemy progression |
| `OVC31` | `ovc31.c` | base init/config: `init_base`, `init_check_mem`, `input_folder_name` |
| `OVC32` | `ovc32_heap.c` | heap |
| `OVC33` | `ovc33_stats.c` | statistics/screens |
| `OVC34` | `ovc34_unit.c` | unit data |
| `OVC35` | `ovc35_bldng.c` | buildings |
| `OVC36` | `ovc36.c` | unidentified (1 func) |
| `OVC37` | `ovc37_season.c` | seasons |
| `OVC38` | `ovc38.c` | high scores / achievements (`high.txt`, "Great Achievements") |
| `OVC39` | `ovc39.c` | character/party creation (lord/lady) |
| `OVC40` | `ovc40.c` | season palettes (`setSeasonPalette`) |
| `OVC41` | `ovc41.c` | main menu, debug hotkeys, UI actions (`uiMainMenu`) |
| `OVC42` | `ovc42.c` | demo/attract loop (`run_demo`) |
| `OVC43` | `ovc43.c` | building data |
| `OVC44` | `ovc44_strong_dat.c` | `init_assets`, stash bootstrap, STRONG.DAT |
| `OVC45` | `ovc45.c` | placement/build UI |
| `OVC46` | `ovc46.c` | asset init part 1 (`init_assets1`, 15 KB function) |
| `OVC47` | `ovc47_constrct.c` | construction |
| `OVC48` | `ovc48.c` | asset init part 2 (`init_assets2`, `stshInitTxtFiles`, `grabBldLbm2`) |
| `OVC49` | `ovc49.c` | unit actions, demolish, endgame |
| `OVC50` | `ovc50.c` | unidentified (3 small funcs) |
| `OVR01`..`OVR50` | `ovr_stubs.c` | Borland VROOMM `INT 3Fh` thunks (460 total) |

The asset-init chain is now fully represented:
`ovc44_strong_dat.c:init_assets` → `ovc46.c:init_assets1` →
`ovc48.c:init_assets2`, with the stash layer in `ovc17`/`ovc20`/`ovc15`
and LBM decoding in `ovc04`.
