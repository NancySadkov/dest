stg_tmp_t * __cdecl16far init_textFilename(void)

{
  uint16_t uVar1;
  far_t gfx;
  far_t gfx_00;
  far_t src;
  far_t src_00;
  far_t handle;
  far_t handle_00;
  ulong uVar2;
  char cVar3;
  byte bVar4;
  uint32_t *puVar5;
  undefined1 extraout_AH;
  undefined1 uVar10;
  uint32_t *puVar6;
  uint16_t uVar7;
  uint uVar8;
  stg_tmp_t *psVar9;
  undefined1 extraout_AH_00;
  int in_CX;
  uint extraout_DX;
  uint uVar11;
  uint uVar12;
  byte (*paabVar13) [59] [148];
  short (*paasVar14) [148] [60];
  uint16_t unaff_SI;
  int iVar15;
  int iVar16;
  byte unaff_DI;
  uint uVar17;
  uint32_t *__return_storage_ptr__;
  undefined2 uVar18;
  undefined2 unaff_SS;
  bool bVar19;
  longdouble in_ST0;
  undefined4 in_stack_00000004;
  int16_t in_stack_00000008;
  byte abStackY_348 [488];
  undefined1 auStackY_160 [158];
  undefined2 uStackY_c2;
  undefined2 uStackY_c0;
  undefined2 uStackY_be;
  char acStack_a4 [92];
  uint16_t uStack_48;
  uint16_t uStack_46;
  int8_t iStack_40;
  uint8_t uStack_3f;
  lbm_type_t lStack_3e;
  uint16_t uStack_34;
  uint16_t uStack_32;
  far_t fStack_30;
  char cStack_2c;
  byte bStack_2b;
  uint32_t *puStack_2a;
  uint uStack_28;
  uint32_t *puStack_26;
  uint uStack_24;
  uint uStack_22;
  uint uStack_20;
  void *pvStack_1e;
  uint32_t *puStack_1c;
  byte *pbStack_18;
  uint uStack_16;
  uint uStack_14;
  uint uStack_12;
  undefined2 uStack_10;
  uint16_t uStack_e;
  uint uStack_c;
  uint uStack_a;
  uint uStack_8;
  int iStack_6;
  byte bStack_3;
  
  uStack_10 = (uint)(byte)uStack_10;
  for (iVar15 = 0; iVar15 < 0x94; iVar15 = iVar15 + 1) {
    uVar7 = ovr_randBelow(10);
    if ((uVar7 & 0xff) == 0) {
      uVar7 = ovr_randBelow(2);
      cVar3 = (char)uVar7 * '\x02' + (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) + -1;
      uStack_10 = CONCAT11(cVar3,(byte)uStack_10);
      if (cVar3 < -1) {
        uStack_10 = CONCAT11(0xff,(byte)uStack_10);
      }
      if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
        uStack_10 = CONCAT11(1,(byte)uStack_10);
      }
    }
    if ((iVar15 == 0) || (iVar15 == 0x93)) {
      uStack_10 = uStack_10 & 0xff;
    }
    acStack_a4[iVar15] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
  }
  uStack_c = 0;
  uStack_a = 0;
  _fsetmem(GUnitGrid,0x4560,0);
  psVar9 = (stg_tmp_t *)((char *)0x26510);
  _fsetmem(GMapFlags,0x4560,0);
  for (uVar17 = 0; (int)uVar17 < 0x3c; uVar17 = uVar17 + 1) {
    if ((uVar17 & 1) == 0) {
      for (iVar15 = 0; iVar15 < 0x94; iVar15 = iVar15 + 1) {
        uStack_c = 0;
        if (iVar15 != 0) {
          uStack_c = (int)(char)((byte (*) [59] [148])GMapCells)[-1][uVar17 + 0x3a][iVar15 + 0x93];
        }
        if (uVar17 != 0) {
          uStack_c = uStack_c +
                     (int)(char)((byte (*) [59] [148])GMapCells)[-1][uVar17 + 0x3a]
                                [acStack_a4[iVar15] + iVar15];
        }
        uStack_c = (int)uStack_c >> 1;
        if ((iVar15 != 0) && (acStack_a4[iVar15 + -1] != acStack_a4[iVar15])) {
          uVar7 = ovr_randBelow(8);
          uStack_8 = uVar7 & 0xff;
          if (uStack_8 == 1) {
            acStack_a4[iVar15] = acStack_a4[iVar15 + -1];
          }
          else if (uStack_8 == 2) {
            acStack_a4[iVar15 + -1] = acStack_a4[iVar15];
          }
        }
        uVar7 = ovr_randBelow(0x10);
        if ((uVar7 & 0xff) == 0) {
          if (iVar15 != 0) {
            (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) = acStack_a4[iVar15 + -1];
            uVar7 = ovr_randBelow(2);
            cVar3 = (char)uVar7 * '\x02' + (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) + -1;
            uStack_10 = CONCAT11(cVar3,(byte)uStack_10);
            if (cVar3 < -1) {
              uStack_10 = CONCAT11(0xff,(byte)uStack_10);
            }
            if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
              uStack_10 = CONCAT11(1,(byte)uStack_10);
            }
            acStack_a4[iVar15] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
          }
          if ((int)uStack_c < 0x56) {
            if ((int)uStack_c < 0x41) {
              if ((int)uStack_c < 0x2b) {
                if ((int)uStack_c < 0x16) {
                  if ((int)uStack_c < 1) {
                    uVar7 = ovr_randBelow(9);
                    uStack_a = (uVar7 & 0xff) - 2;
                  }
                  else {
                    uVar7 = ovr_randBelow(8);
                    uStack_a = (uVar7 & 0xff) - 5;
                  }
                }
                else {
                  uVar7 = ovr_randBelow(0x10);
                  uStack_a = (uVar7 & 0xff) - 8;
                }
              }
              else {
                uVar7 = ovr_randBelow(0xb);
                uStack_a = (uVar7 & 0xff) - 5;
              }
            }
            else {
              uVar7 = ovr_randBelow(8);
              uStack_a = (uVar7 & 0xff) - 4;
            }
          }
          else {
            uVar7 = ovr_randBelow(0x11);
            uStack_a = (uVar7 & 0xff) - 8;
          }
        }
        if ((int)uStack_c < 0x56) {
          if ((int)uStack_c < 0x41) {
            if ((int)uStack_c < 0x2b) {
              if ((int)uStack_c < 0x16) {
                if ((int)uStack_c < 1) {
                  uStack_e = 0xb;
                }
                else {
                  uStack_e = 5;
                }
              }
              else {
                uStack_e = 0xf;
              }
            }
            else {
              uStack_e = 5;
            }
          }
          else {
            uStack_e = 0x13;
          }
        }
        else {
          uStack_e = 9;
        }
        uVar7 = ovr_randBelow(uStack_e);
        uStack_c = uStack_c + ((uVar7 & 0xff) - ((int)uStack_e >> 1)) + uStack_a + 1;
        if ((int)uStack_c < -0x23) {
          uStack_c = 0xffdd;
          uStack_a = (uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf);
        }
        if (0x7f < (int)uStack_c) {
          uStack_c = 0x7f;
          uStack_a = -((uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf));
        }
        psVar9 = (stg_tmp_t *)CONCAT11((char)(uVar17 * 0x94 >> 8),(byte)uStack_c);
        (*(byte (*) [59] [148])GMapCells)[uVar17][iVar15] = (byte)uStack_c;
      }
    }
    else {
      for (iVar15 = 0x93; -1 < iVar15; iVar15 = iVar15 + -1) {
        uStack_c = 0;
        if (iVar15 != 0x93) {
          uStack_c = (int)(char)(*(byte (*) [59] [148])GMapCells)[uVar17][iVar15 + 1];
        }
        if (uVar17 != 0) {
          uStack_c = uStack_c +
                     (int)(char)((byte (*) [59] [148])GMapCells)[-1][uVar17 + 0x3a]
                                [acStack_a4[iVar15] + iVar15];
        }
        uStack_c = (int)uStack_c >> 1;
        if ((iVar15 != 0x93) && (acStack_a4[iVar15 + 1] != acStack_a4[iVar15])) {
          uVar7 = ovr_randBelow(0x10);
          uStack_8 = uVar7 & 0xff;
          if (uStack_8 == 1) {
            acStack_a4[iVar15] = acStack_a4[iVar15 + 1];
          }
          else if (uStack_8 == 2) {
            acStack_a4[iVar15 + 1] = acStack_a4[iVar15];
          }
        }
        uVar7 = ovr_randBelow(0x10);
        if ((uVar7 & 0xff) == 0) {
          if (iVar15 != 0x93) {
            (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) = acStack_a4[iVar15 + 1];
            uVar7 = ovr_randBelow(2);
            cVar3 = (char)uVar7 * '\x02' + (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) + -1;
            uStack_10 = CONCAT11(cVar3,(byte)uStack_10);
            if (cVar3 < -1) {
              uStack_10 = CONCAT11(0xff,(byte)uStack_10);
            }
            if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
              uStack_10 = CONCAT11(1,(byte)uStack_10);
            }
            acStack_a4[iVar15] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
          }
          if ((int)uStack_c < 0x56) {
            if ((int)uStack_c < 0x41) {
              if ((int)uStack_c < 0x2b) {
                if ((int)uStack_c < 0x16) {
                  if ((int)uStack_c < 1) {
                    uVar7 = ovr_randBelow(9);
                    uStack_a = (uVar7 & 0xff) - 2;
                  }
                  else {
                    uVar7 = ovr_randBelow(8);
                    uStack_a = (uVar7 & 0xff) - 5;
                  }
                }
                else {
                  uVar7 = ovr_randBelow(0x10);
                  uStack_a = (uVar7 & 0xff) - 8;
                }
              }
              else {
                uVar7 = ovr_randBelow(0xb);
                uStack_a = (uVar7 & 0xff) - 5;
              }
            }
            else {
              uVar7 = ovr_randBelow(8);
              uStack_a = (uVar7 & 0xff) - 4;
            }
          }
          else {
            uVar7 = ovr_randBelow(0x11);
            uStack_a = (uVar7 & 0xff) - 8;
          }
        }
        if ((int)uStack_c < 0x56) {
          if ((int)uStack_c < 0x41) {
            if ((int)uStack_c < 0x2b) {
              if ((int)uStack_c < 0x16) {
                if ((int)uStack_c < 1) {
                  uStack_e = 0xb;
                }
                else {
                  uStack_e = 5;
                }
              }
              else {
                uStack_e = 0xf;
              }
            }
            else {
              uStack_e = 5;
            }
          }
          else {
            uStack_e = 0x13;
          }
        }
        else {
          uStack_e = 9;
        }
        uVar7 = ovr_randBelow(uStack_e);
        uStack_c = uStack_c + ((uVar7 & 0xff) - ((int)uStack_e >> 1)) + uStack_a + 1;
        if ((int)uStack_c < -0x7f) {
          uStack_c = 0xff81;
          uStack_a = (uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf);
        }
        if (0x7f < (int)uStack_c) {
          uStack_c = 0x7f;
          uStack_a = -((uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf));
        }
        psVar9 = (stg_tmp_t *)CONCAT11((char)(uVar17 * 0x94 >> 8),(byte)uStack_c);
        (*(byte (*) [59] [148])GMapCells)[uVar17][iVar15] = (byte)uStack_c;
      }
    }
  }
  for (iVar15 = 0; iVar15 < 0x3c; iVar15 = iVar15 + 1) {
    for (iVar16 = 0; iVar16 < 0x94; iVar16 = iVar16 + 1) {
      uVar18 = (undefined2)((ulong)GMapCells >> 0x10);
      if ((char)(*(byte (*) [59] [148])GMapCells)[iVar15][iVar16] < '\0') {
        (*(byte (*) [59] [148])GMapCells)[iVar15][iVar16] = 0;
      }
      psVar9 = (stg_tmp_t *)(iVar15 * 0x94);
      if ((iVar16 != 0x93) && (iVar15 != 0x3c)) {
        uVar18 = (undefined2)((ulong)GMapCells >> 0x10);
        paabVar13 = (byte (*) [59] [148])GMapCells;
        uVar17 = (int)(char)(*paabVar13)[iVar15 + 1][iVar16] -
                 (int)(char)(*paabVar13)[iVar15][iVar16 + 1];
        uVar11 = (int)uVar17 >> 0xf;
        uVar8 = (int)(char)(*paabVar13)[iVar15][iVar16] -
                (int)(char)(*paabVar13)[iVar15 + 1][iVar16 + 1];
        uVar12 = (int)uVar8 >> 0xf;
        psVar9 = (stg_tmp_t *)((uVar8 ^ uVar12) - uVar12);
        if ((int)((uVar17 ^ uVar11) - uVar11) < (int)psVar9) {
          psVar9 = (stg_tmp_t *)(iVar16 * 2);
          *(uint *)(psVar9->cmap + (int)(*(short (*) [60] [148])GMapFlags + iVar15)) =
               *(uint *)(psVar9->cmap + (int)(*(short (*) [60] [148])GMapFlags + iVar15)) | 4;
        }
      }
    }
  }
  init_rebuildMapFlags();
  init_usesRandBelow2();
  init_rebuildMapFlags();
  __return_storage_ptr__ = (uint32_t *)0x0;
  do {
    if (0x3a < (int)__return_storage_ptr__) {
      for (iVar15 = 1; iVar15 < 0x3a; iVar15 = iVar15 + 1) {
        for (iVar16 = 1; iVar16 < 0x92; iVar16 = iVar16 + 1) {
          uVar7 = ovr_randBelow(2);
          psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
          if (psVar9 == (stg_tmp_t *)0x0) {
            psVar9 = (stg_tmp_t *)(iVar15 * 0x94);
            uVar18 = (undefined2)((ulong)GMapCells >> 0x10);
            paabVar13 = (byte (*) [59] [148])GMapCells;
            if ((((((psVar9->cmap[(int)(*paabVar13 + -1) + 0x93 + iVar16] != 0) &&
                   (psVar9 = (stg_tmp_t *)(*paabVar13 + iVar15), psVar9->cmap[iVar16 + 0x93] != 0))
                  && (psVar9 = (stg_tmp_t *)(iVar15 * 0x94),
                     psVar9->cmap[(int)((*paabVar13)[0] + iVar16)] != 0)) &&
                 ((psVar9 = (stg_tmp_t *)(*paabVar13 + iVar15), psVar9->cmap[iVar16 + 0x94] != 0 &&
                  (psVar9 = (stg_tmp_t *)(iVar15 * 0x94),
                  psVar9->cmap[(int)((*paabVar13)[0] + iVar16 + 1)] != 0)))) &&
                (psVar9 = (stg_tmp_t *)(*paabVar13 + iVar15), psVar9->cmap[iVar16 + 0x95] != 0)) &&
               (((bVar4 = (*paabVar13)[iVar15][iVar16],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar15 * 0x94) >> 8),bVar4),
                 (char)bVar4 <= (char)(*paabVar13)[iVar15][iVar16 + 1] &&
                 (bVar4 = (*paabVar13)[iVar15][iVar16],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar15 * 0x94) >> 8),bVar4),
                 (char)bVar4 <= (char)paabVar13[-1][iVar15 + 0x3a][iVar16 + 0x93])) &&
                ((bVar4 = (*paabVar13)[iVar15][iVar16],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar15 * 0x94) >> 8),bVar4),
                 (char)bVar4 <= (char)paabVar13[-1][iVar15 + 0x3a][iVar16] &&
                 (((bVar4 = (*paabVar13)[iVar15][iVar16 + 1],
                   psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar15 * 0x94) >> 8),bVar4),
                   (char)bVar4 <= (char)paabVar13[-1][iVar15 + 0x3a][iVar16 + 1] &&
                   (bVar4 = (*paabVar13)[iVar15][iVar16],
                   psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar15 * 0x94) >> 8),bVar4),
                   (char)bVar4 <= (char)(*paabVar13)[iVar15 + 1][iVar16])) &&
                  (bVar4 = (*paabVar13)[iVar15][iVar16 + 1],
                  psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar15 * 0x94) >> 8),bVar4),
                  (char)bVar4 <= (char)(*paabVar13)[iVar15 + 1][iVar16 + 1])))))))) {
              uVar17 = ovr_init_getMapFlags(iVar16);
              psVar9 = (stg_tmp_t *)(uVar17 & 0xff);
              if (psVar9 == (stg_tmp_t *)0x0) {
                uVar17 = ovr_init_getMapFlags(iVar16 + -1);
                psVar9 = (stg_tmp_t *)(uVar17 & 0xff);
                if ((psVar9 == (stg_tmp_t *)0x0) &&
                   (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags2(iVar16), (char)psVar9 == '\x02')
                   ) {
                  iStack_6 = ((short (*) [148] [60])GUnitGrid)[-1][iVar16 + 0x92][iVar15];
                  bStack_3 = ((unit_t *)GUnits + iStack_6)->bldType;
                  psVar9 = (stg_tmp_t *)((uint)bStack_3 * 0x27);
                  if ((psVar9->cmap[0x11b] < 2) &&
                     (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags2(iVar16), (byte)psVar9 < 3)) {
                    uVar7 = ovr_randBelow(5);
                    ((short (*) [148] [60])GUnitGrid)[-1][iVar16 + 0x93][iVar15] =
                         (uVar7 & 0xff) + 0x92;
                    uVar2 = (ulong)GUnitGrid >> 0x10;
                    paasVar14 = (short (*) [148] [60])GUnitGrid;
                    psVar9 = (stg_tmp_t *)(iVar15 * 2);
                    (psVar9->cmap + (int)(*paasVar14 + iVar16))[0] = 0;
                    (psVar9->cmap + (int)(*paasVar14 + iVar16))[1] = 0;
                  }
                }
              }
            }
          }
        }
      }
      init_rebuildAllDirectionFlags();
      return psVar9;
    }
    for (iVar15 = 0; iVar15 < 0x93; iVar15 = iVar15 + 1) {
      psVar9 = (stg_tmp_t *)((int)__return_storage_ptr__ * 0x94);
      uVar18 = (undefined2)((ulong)GMapCells >> 0x10);
      paabVar13 = (byte (*) [59] [148])GMapCells;
      if (((psVar9->cmap[(int)((*paabVar13)[0] + iVar15)] != 0) &&
          (psVar9 = (stg_tmp_t *)((int)__return_storage_ptr__ * 0x94),
          psVar9->cmap[(int)((*paabVar13)[0] + iVar15 + 1)] != 0)) &&
         ((psVar9 = (stg_tmp_t *)(*paabVar13 + (int)__return_storage_ptr__),
          psVar9->cmap[iVar15 + 0x94] != 0 &&
          (psVar9 = (stg_tmp_t *)(*paabVar13 + (int)__return_storage_ptr__),
          psVar9->cmap[iVar15 + 0x94] != 0)))) {
        uVar17 = ovr_init_getMapFlags(iVar15);
        psVar9 = (stg_tmp_t *)(uVar17 & 0xff);
        if (psVar9 == (stg_tmp_t *)0x0) {
          uStack_c = (uint)(char)(*(byte (*) [59] [148])GMapCells)[(int)__return_storage_ptr__]
                                 [iVar15];
          if ((int)uStack_c < 0x6b) {
            if ((int)uStack_c < 0x56) {
              if ((int)uStack_c < 0x40) {
                if ((int)uStack_c < 0x2b) {
                  if ((int)uStack_c < 0x16) {
                    uVar7 = ovr_randBelow(4);
                    psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                    if (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 2)) {
                      uVar7 = ovr_randBelow(6);
                      psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x3d);
                      (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                           (short)psVar9;
                    }
                    else if ((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                            (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar15),
                            (char)psVar9 != '\0')) {
                      uVar7 = ovr_randBelow(2);
                      psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                      if (psVar9 == (stg_tmp_t *)0x0) {
                        uVar7 = ovr_randBelow(9);
                        psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                        (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                             (short)psVar9;
                      }
                    }
                  }
                  else {
                    uVar7 = ovr_randBelow(4);
                    psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                    switch((uint16_t)psVar9)   /* hand fix: case values are ints */ {
                    case (uint16_t)0x0:
                      func_0x000318f5();
                      bStack_2b = 0;
                      uVar17 = extraout_DX;
                      goto L_grabLbm_0445;
                    case (uint16_t)0x1:
                      while( true ) {
                        pbStack_18 = psVar9->cmap + (int)pbStack_18;
                        psVar9 = (stg_tmp_t *)(iVar15 + (int)__return_storage_ptr__);
                        if ((int)puStack_1c <= (int)psVar9) {
                          psVar9 = memcpy((char *)CONCAT13((char)(uStack_12 >> 8),
                                                           CONCAT12((char)uStack_12,uStack_14)),
                                          (char *)CONCAT13((char)((uint)unaff_SS >> 8),
                                                           CONCAT12((char)unaff_SS,
                                                                    auStackY_160 + uStack_c)),
                                          uStack_e);
                          uStack_14 = uStack_14 + 0x140;
                        }
                        iVar15 = iVar15 + 1;
                        if (((int)uStack_10 <= iVar15) ||
                           (psVar9 = (stg_tmp_t *)(iVar15 + (int)__return_storage_ptr__),
                           (int)uStack_20 < (int)psVar9)) break;
                        (*(uint8_t *)((uint8_t *)&(src_00.seg))) = (char)uStack_16;
                        src_00.ofs = (uint16_t)pbStack_18;
                        (*(uint8_t *)((uint8_t *)&(src_00.seg) + 1)) = (char)(uStack_16 >> 8);
                        psVar9 = (stg_tmp_t *)ovr_unrle(src_00);
                      }
                      return psVar9;
                    case (uint16_t)0x2:
                      *__return_storage_ptr__ = (long)in_ST0;
                    /* WARNING: Bad instruction - Truncating control flow here */
                      halt_baddata();
                    case (uint16_t)0x3:
                      goto switchD_3000_4a6e_caseD_3;
                    }
                  }
                }
                else {
                  uVar7 = ovr_randBelow(4);
                  psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                  if (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 1)) {
                    uVar7 = ovr_randBelow(6);
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x3d);
                    (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                         (short)psVar9;
                  }
                  else if ((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                          (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar15),
                          (char)psVar9 != '\0')) {
                    uVar7 = ovr_randBelow(9);
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                    (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                         (short)psVar9;
                  }
                }
              }
              else {
                uVar7 = ovr_randBelow(4);
                psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                if (((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                    (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar15), (char)psVar9 != '\0'))
                   && (psVar9 = (stg_tmp_t *)ovr_randBelow(2), (char)psVar9 != '\0')) {
                  uVar7 = ovr_randBelow(9);
                  psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                  (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                       (short)psVar9;
                }
              }
            }
            else {
              uVar7 = ovr_randBelow(4);
              psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
              if (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 1)) {
                psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar15);
                if ((char)psVar9 != '\0') {
                  uVar7 = ovr_randBelow(2);
                  if ((uVar7 & 0xff) == 0) {
                    uVar7 = ovr_randBelow(6);
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x3d);
                    (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                         (short)psVar9;
                  }
                  else {
                    uVar7 = ovr_randBelow(9);
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                    (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                         (short)psVar9;
                  }
                }
              }
              else if ((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                      (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar15), (char)psVar9 != '\0')
                      ) {
                uVar7 = ovr_randBelow(9);
                psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                     (short)psVar9;
              }
            }
          }
          else {
            uVar7 = ovr_randBelow(4);
            psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
            if (((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 2)) ||
                (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3))) &&
               (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar15), (char)psVar9 != '\0')) {
              uVar7 = ovr_randBelow(9);
              psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
              (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                   (short)psVar9;
            }
          }
        }
      }
    }
    __return_storage_ptr__ = (uint32_t *)((int)__return_storage_ptr__ + 1);
  } while( true );
switchD_3000_4a6e_caseD_3:
  do {
    *(int *)(&stack0xd744 + iVar15) = *(int *)(&stack0xd744 + iVar15) + in_CX;
    uStack_28 = constr_compute2((uint8_t)uStack_20,(uint8_t)uStack_22,(uint8_t)puStack_1c,
                                (byte)psVar9,unaff_DI);
    uStack_28 = uStack_28 & 0xff;
    ovr_ovc07_usesBiosReadKey(((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__]);
    uVar17 = constr_compute2((uint8_t)puStack_1c,(uint8_t)pvStack_1e,(uint8_t)uStack_22,bStack_2b,2)
    ;
    puStack_2a = (uint32_t *)(uVar17 & 0xff);
    ovr_ovc07_usesBiosReadKey(((uint16_t *)SquareRightX)[(int)__return_storage_ptr__]);
    while( true ) {
      uVar17 = ovr_constr_usesGMapFlags(uStack_24 + GfxRndSeed);
      if ((char)uVar17 != '\0') {
        ovr_ovc07_usesLDIV_at_
                  (((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__],RowScreenY[0] - uStack_10)
        ;
      }
      do {
        __return_storage_ptr__ = (uint32_t *)((int)__return_storage_ptr__ + 1);
        uVar7 = rowBandSquareFirst[0];
        if ((int)rowBandSquareEnd[0] <= (int)__return_storage_ptr__) {
          for (; (int)uVar7 < (int)rowBandSquareEnd[0]; uVar7 = uVar7 + 1) {
            uStack_24 = ((uint16_t *)squareColumn)[uVar7];
            bVar4 = ovr_constr_setHighlightAtOffset(uStack_24);
            uStack_e = CONCAT11(extraout_AH_00,bVar4);
            if ((*(byte *)((uint8_t *)&BuildingTypes[uStack_e] + 16) & 2) != 0) {
              iVar15 = ovr_constr_usesSmoothPrev(uStack_24);
              uStack_10 = iVar15 / 3;
              (*(uint8_t *)((uint8_t *)&(gfx.seg))) =
                   (char)*(undefined2 *)
                          ((char *)0x28ed6 + uStack_e * 0xc);
              gfx.ofs = *(undefined2 *)
                         ((char *)0x28ed4 + uStack_e * 0xc);
              (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) =
                   (char)((uint)*(undefined2 *)
                                 ((char *)0x28ed6 + uStack_e * 0xc) >> 8);
              ovr_blit_usesBlitGfxN
                        (gfx,((uint16_t *)SquareLeftX)[uVar7],rowBandOrigin[0] - uStack_10,6);
            }
            if ((*(byte *)((uint8_t *)&BuildingTypes[uStack_e] + 16) & 1) != 0) {
              gfx_00.seg = *(uint16_t *)
                            ((char *)0x28eda + uStack_e * 0xc);
              gfx_00.ofs = *(uint16_t *)
                            ((char *)0x28ed8 + uStack_e * 0xc);
              ovr_blitGfxRect(gfx_00,((uint16_t *)SquareLeftX)[uVar7]);
            }
          }
          return (stg_tmp_t *)((char *)0x26510);
        }
      } while (((int)((uint16_t *)SquareRightX)[(int)__return_storage_ptr__] < 0xef) ||
              (0x134 < (int)((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__]));
      uStack_24 = ((uint16_t *)squareColumn)[(int)__return_storage_ptr__];
      puStack_1c = (uint32_t *)constr_getCellAtOffset(uStack_24,-2);
      pvStack_1e = (void *)constr_getCellAtOffset(uStack_24 + 1,-2);
      iVar16 = ovr_constr_usesSmoothPrev(uStack_24);
      uStack_10 = iVar16 / 3;
      iVar16 = ovr_constr_usesSmoothPrev(uStack_24 + 1);
      uStack_12 = iVar16 / 3;
      psVar9 = (stg_tmp_t *)constr_getFlagsAtOffset(uStack_24,-1);
      bStack_2b = (byte)psVar9;
      if (((uint)psVar9 & 4) != 0) break;
      uStack_28 = constr_compute2((uint8_t)uStack_20,(uint8_t)uStack_22,(uint8_t)pvStack_1e,
                                  (byte)psVar9,2);
      uStack_28 = uStack_28 & 0xff;
      ovr_ovc07_usesBiosReadKey(((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__]);
      uVar17 = constr_compute2((uint8_t)puStack_1c,(uint8_t)pvStack_1e,(uint8_t)uStack_20,bStack_2b,
                               1);
      puStack_2a = (uint32_t *)(uVar17 & 0xff);
      ovr_ovc07_usesBiosReadKey(((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__]);
    }
    unaff_DI = 1;
  } while( true );
L_grabLbm_0445:
  iVar15 = ovr_stshRead();
  if (iVar15 != 0 || uVar17 != 0) {
bad_lbm:
    uVar7 = fStack_30.seg;
    psVar9 = (stg_tmp_t *)fStack_30.ofs;
    if ((&psVar9->bptr)->ofs != 0 || (psVar9->bptr).seg != 0) {
      uVar1 = (psVar9->bptr).seg;
      (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)uVar1;
      handle_00.ofs = (&psVar9->bptr)->ofs;
      (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)(uVar1 >> 8);
      ovr_stshFree(handle_00);
    }
    ovr_stshClose((uint16_t)__return_storage_ptr__);
    ovr_stshFree(fStack_30);
    printf("Filename %d %s  \r");
    ovr_biosReadKey();
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0xd);
  }
  if ((uStack_20 == uStack_c) && (uStack_22 == uStack_e)) {
    cStack_2c = '\x01';
    uVar17 = uStack_22;
    iVar15 = ovr_stshRead();
    if ((((iVar15 != 0 || uVar17 != 0) ||
         (puStack_2a = ovr_be4(puStack_2a), uStack_28 = uVar17, uVar17 != 0)) ||
        (puStack_2a != (uint32_t *)((byte *)__C0_ASM_CopyRight + 0x10))) ||
       (iVar15 = ovr_stshRead(), iVar15 != 0 || uVar17 != 0)) goto bad_lbm;
    uStack_32 = ovr_be2(uStack_48);
    uStack_34 = ovr_be2(uStack_46);
    goto L_grabLbm_0445;
  }
  if ((uStack_20 == uStack_14) && (uStack_22 == uStack_16)) {
    uVar17 = uStack_22;
    ovr_stshRead();
    puStack_2a = ovr_be4(puStack_2a);
    uStack_28 = uVar17;
    uStack_24 = uVar17;
    puStack_26 = puStack_2a;
    if (((uint)puStack_2a & 1) != 0) {
      puStack_26 = (uint32_t *)((int)puStack_2a + 1);
      uStack_24 = uVar17 + ((uint32_t *)0xfffe < puStack_2a);
    }
    if (((int)uStack_24 < 0) || ((uStack_24 == 0 && (puStack_26 < (char *)0x24400))))
    {
      if ((-1 < (int)uStack_24) && ((0 < (int)uStack_24 || (puStack_26 != (uint32_t *)0x0)))) {
        ovr_stshRead();
      }
    }
    else {
      ovr_stshRead();
      if ((-1 < (int)uStack_24) &&
         ((0 < (int)uStack_24 || ((char *)0x24400 < puStack_26)))) {
        ovr_stshTell(__return_storage_ptr__,unaff_SI);
        ovr_stshSeek((uint16_t)__return_storage_ptr__);
      }
    }
    puVar6 = (uint32_t *)0x0;
    while( true ) {
      if ((0 < (int)uStack_28) ||
         ((puVar5 = puStack_2a, uVar17 = uStack_28, uStack_28 == 0 &&
          ((char *)0x24400 < puStack_2a)))) {
        puVar5 = (uint32_t *)((char *)0x24400);
        uVar17 = 0;
      }
      if (((int)uVar17 < 1) && ((uVar17 != 0 || (puVar5 <= puVar6)))) break;
      ((stg_tmp_t *)fStack_30.ofs)->cmap[(int)puVar6] =
           (uint8_t)((int)(uint)abStackY_348[(int)puVar6] >> 2);
      puVar6 = (uint32_t *)((int)puVar6 + 1);
    }
  }
  else {
    if ((uStack_20 == uStack_10) && (uStack_22 == uStack_12)) {
      if (cStack_2c != '\0') {
        ovr_stshRead();
        puStack_1c = ovr_be4(puStack_2a);
        puStack_26 = puStack_1c;
        uStack_24 = uStack_22;
        if (((uint)puStack_1c & 1) != 0) {
          puStack_26 = (uint32_t *)((int)puStack_1c + 1);
          uStack_24 = uStack_22 + ((uint32_t *)0xfffe < puStack_1c);
        }
        puStack_2a = puStack_1c;
        pvStack_1e = ovr_stshAlloc(CONCAT13((char)(uStack_24 >> 8),
                                            CONCAT12((char)uStack_24,puStack_26)));
        ovr_stshRead();
        uVar10 = extraout_AH;
        ovr_stshClose((uint16_t)__return_storage_ptr__);
        uStackY_be = CONCAT11(uVar10,bStack_2b);
        uStackY_c0 = 0x2337;
        uStackY_c2 = 0x152a;
        src.seg = fStack_30.ofs;
        src.ofs = (uint16_t)puStack_1c;
        lbm_decode_body(lStack_3e,iStack_40,uStack_3f,(uint8_t)pvStack_1e,src,
                        (stg_tmp_t *)
                        CONCAT13((char)((ulong)in_stack_00000004 >> 0x18),
                                 CONCAT12((char)((ulong)in_stack_00000004 >> 0x10),fStack_30.seg)),
                        in_stack_00000008,uStack_32,uStack_34,unaff_SI);
        (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)puStack_1c;
        handle.ofs = (uint16_t)pvStack_1e;
        (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)puStack_1c >> 8);
        ovr_stshFree(handle);
        return (stg_tmp_t *)fStack_30.ofs;
      }
      goto bad_lbm;
    }
    uVar17 = uStack_22;
    ovr_stshRead();
    puStack_26 = ovr_be4(puStack_26);
    uStack_24 = uVar17;
    if (((uint)puStack_26 & 1) != 0) {
      bVar19 = (uint32_t *)0xfffe < puStack_26;
      puStack_26 = (uint32_t *)((int)puStack_26 + 1);
      uStack_24 = uVar17 + bVar19;
    }
    puVar6 = ovr_stshTell(__return_storage_ptr__,unaff_SI);
    uVar17 = ((int)puVar6 >> 0xf) + uStack_24 + (uint)CARRY2((uint)puVar6,(uint)puStack_26);
    ovr_stshSeek((uint16_t)__return_storage_ptr__);
  }
  goto L_grabLbm_0445;
}
