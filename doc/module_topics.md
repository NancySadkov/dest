# Translation-unit topics for the 27 modules that had none

These overlay code segments carried no name in the executable: the block names were the bare
overlay numbers (`OVC24`), so `ExportRecovered.moduleName()` could only produce `ovc24`.
Each topic below is **inferred from the functions the module contains** and is a label for
navigation, not recovered evidence.  The functions listed are the actual basis.

| block was | block now | module | basis (functions in that module) |
|---|---|---|---|
| `OVC04` | `OVC04_lbm.c` | `ovc04_lbm` | alignToSeg, lbm_decode_body, grabLbm |
| `OVC07` | `OVC07_gfxutil.c` | `ovc07_gfxutil` | swapWords, signum, fillRect, drawLine, biosReadKey |
| `OVC13` | `OVC13_panel.c` | `ovc13_panel` | blitAnimFrame, drawPanelCell/Entities/Leaders/Highlight, drawWindowEntities |
| `OVC15` | `OVC15_sprite.c` | `ovc15_sprite` | stshRleAnims, stshSprite, allocSprSeqs, stshInitSprites, stshStoreSprite |
| `OVC18` | `OVC18_leaderview.c` | `ovc18_leaderview` | showLeaderView, blitPanelIfNotRunning, spawnClassAgent, checkFortressPlacement |
| `OVC20` | `OVC20_stash.c` | `ovc20_stash` | stshReadFile, stshWriteFile, stshStoreFile, stshLoadAudioDrivers, grabLbmTR |
| `OVC22` | `OVC22_classes.c` | `ovc22_classes` | className, applyRankBonus, seasonalIncome, buildingTypeAt, spawnForLeaders |
| `OVC23` | `OVC23_bldrec.c` | `ovc23_bldrec` | placeBuilding, createConstructionRecord, findRecordAt, abandonConstruction |
| `OVC24` | `OVC24_entities.c` | `ovc24_entities` | textKill, removeOtherEntities, unitAtLeader, checkStrongholds, intelUnitReport |
| `OVC25` | `OVC25_intel.c` | `ovc25_intel` | spyReportNotice, intelAttackingNotice, attackingNotice, tickCountdown, hasBuildingNear |
| `OVC26` | `OVC26_fillgrid.c` | `ovc26_fillgrid` | usesFillGrid is the only named routine; the module fills the unit grid |
| `OVC27` | `OVC27_combat.c` | `ovc27_combat` | spellNotice, spellHalfDamage, breathHalfDamage, rollToHitEntity, rollToHitAgent |
| `OVC28` | `OVC28_ui.c` | `ovc28_ui` | drawGold, drawButton, blitButton, toggle_pause, uiInputText |
| `OVC30` | `OVC30_waves.c` | `ovc30_waves` | difficultyFactor, nextWave, createLeader |
| `OVC31` | `OVC31_config.c` | `ovc31_config` | write_game_cfg, read_cfg, init_base, init_strong_sav, fileExists |
| `OVC36` | `OVC36_math.c` | `ovc36_math` | single helper built on LXMUL_at_/LDIV_at_; scales and caps at 200 |
| `OVC38` | `OVC38_scores.c` | `ovc38_scores` | loadHighScores, saveHighScores, showAchievements |
| `OVC39` | `OVC39_archive.c` | `ovc39_archive` | loadArchiveEntry, findBuildingAt, lordOrLady, textHalflingCastle |
| `OVC40` | `OVC40_palette.c` | `ovc40_palette` | setSeasonPalette, vgaSetPalette8bit, calcSeasonPalette, flushInput |
| `OVC41` | `OVC41_main.c` | `ovc41_main` | uiMainMenu, enterLeaderView, settleAgentCombat, specialAttack |
| `OVC42` | `OVC42_demo.c` | `ovc42_demo` | run_demo, endDemo, showAgentStats, populateArea, drawTextRow |
| `OVC43` | `OVC43_fli.c` | `ovc43_fli` | playFli, playFliFrames, playArchiveFli |
| `OVC45` | `OVC45_unitinfo.c` | `ovc45_unitinfo` | getUnitType, getUnitIndex, findEntityAt, showLandInfo, costOrIncomeLabel |
| `OVC46` | `OVC46_assets.c` | `ovc46_assets` | init_assets1 |
| `OVC48` | `OVC48_assets2.c` | `ovc48_assets2` | stshInitTxtFiles, init_assets2, grabBldLbm2 |
| `OVC49` | `OVC49_agents.c` | `ovc49_agents` | agentIsActive, fillGridCells, drawAgents, textLongerParalyzed |
| `OVC50` | `OVC50_textui.c` | `ovc50_textui` | usesBlitText, usesStshLoadGfx, usesUiInputText |

Renaming the memory block, rather than post-processing the export, is what makes
`moduleName()` produce the topic; no exporter change is involved.
