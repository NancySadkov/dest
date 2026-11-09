void __cdecl16far upd_units_5087_1d7d(void)

{
  byte *pbVar1;
  char *pcVar2;
  uint *puVar3;
  int *piVar4;
  byte bVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  char cVar11;
  char cVar12;
  uint16_t uVar13;
  uint uVar14;
  char *pcVar15;
  char *pcVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  undefined2 unaff_DI;
  uint uVar21;
  undefined2 uVar22;
  undefined2 uVar23;
  uint16_t uVar24;
  undefined2 uVar25;
  bool bVar26;
  ulong uVar27;
  uint16_t dst;
  uint uStack_2e;
  int iStack_2c;
  int iStack_2a;
  byte local_20;
  byte local_1f;
  byte local_1e;
  char cStack_1d;
  char local_1c;
  byte bStack_1b;
  int iStack_1a;
  int iStack_18;
  uint uStack_16;
  uint uStack_14;
  uint uStack_12;
  uint uStack_10;
  int iStack_e;
  int iStack_c;
  uint uStack_a;
  uint16_t uStack_8;
  byte bStack_6;
  byte bStack_5;
  uint uStack_4;
  
  if (!GameRunning) {
    cStack_1d = '\0';
    local_1c = '\0';
    for (uStack_16 = 0xf8; uStack_16 < GUnitCount; uStack_16 = uStack_16 + 1) {
      pbVar1 = (byte *)((int)GUnits + uStack_16 * 9 + 3);
      *pbVar1 = *pbVar1 & 0xfc;
    }
    for (uStack_16 = 0; (int)uStack_16 < (int)(uint)GLeaderCount; uStack_16 = uStack_16 + 1) {
      if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3d) != '\0') {
        OVC22_5087_056e(CONCAT11(0x21,(undefined1)uStack_16));
      }
    }
    GGameState = 0x3e;
    if (DebugVerbose != false) {
      printf("%d \r",0x3e);
    }
    for (uVar21 = 0xf8; uVar21 < GUnitCount; uVar21 = uVar21 + 1) {
      uVar22 = (undefined2)((ulong)GUnits >> 0x10);
      iVar17 = (int)GUnits;
      if ((*(byte *)(iVar17 + uVar21 * 9 + 3) & 3) == 0) {
        bVar5 = *(byte *)(iVar17 + uVar21 * 9 + 2);
        if ((bVar5 == 0xff) ||
           (uVar8 = *(undefined4 *)((uint)bVar5 << 2), *(char *)((int)uVar8 + 0x3f) == '\0')) {
          uStack_8 = 0x96;
        }
        else {
          uStack_8 = 0x5dc;
        }
        if (*(char *)(iVar17 + uVar21 * 9 + 1) != '\0') {
          uVar13 = ovr_randBelow(uStack_8);
          uVar22 = (undefined2)((ulong)GUnits >> 0x10);
          iVar17 = (int)GUnits;
          if ((int)(uVar13 & 0xff) <
              (int)(100 - (uint)*(byte *)((uint)*(byte *)(iVar17 + uVar21 * 9) * 0x27 + 0x130))) {
            local_20 = *(byte *)(iVar17 + uVar21 * 9);
            pcVar2 = (char *)(iVar17 + uVar21 * 9 + 1);
            *pcVar2 = *pcVar2 + -1;
            iVar17 = (int)GUnits;
            uVar22 = (undefined2)((ulong)GUnits >> 0x10);
            if (((*(uint *)((uint)local_20 * 0x27 + 0x121) & 4) == 0) &&
               ((*(char *)(iVar17 + uVar21 * 9 + 1) == '\0' ||
                ((*(uint *)((uint)local_20 * 0x27 + 0x121) & 0x200) != 0)))) {
              OVC22_5087_1674(uVar21,&local_1c);
            }
            else if (((*(int16_t *)(BLD_RECORDS + (uint)local_20 * 0xc) != 0 ||
                       *(int16_t *)(BLD_RECORDS + 2 + (uint)local_20 * 0xc) != 0) ||
                     (*(char *)((uint)local_20 * 0x27 + 0x11e) == '\x10')) &&
                    (cVar11 = OVC22_5087_510e(CONCAT11((char)(uVar21 * 9 >> 8),
                                                       *(undefined1 *)(iVar17 + uVar21 * 9 + 4)),
                                              CONCAT11((char)(uVar21 * 9 >> 8),
                                                       *(undefined1 *)(iVar17 + uVar21 * 9 + 6))),
                    cVar11 != '\0')) {
              local_1c = '\x01';
            }
          }
        }
      }
    }
    GGameState = 0x43;
    if (DebugVerbose != false) {
      printf("%d \r",0x43);
    }
    for (uStack_16 = 0; (int)uStack_16 < (int)(uint)GLeaderCount; uStack_16 = uStack_16 + 1) {
      if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3d) != '\0') {
        *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa2) = 0;
        cVar11 = *(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3f);
        if ((cVar11 == '\0') &&
           (*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f) <
            *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d) >> 1)) {
          bVar9 = true;
        }
        else {
          bVar9 = false;
        }
        uVar21 = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54);
        uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar17 = *(int *)(iVar17 + 0x58) + ((int)uVar21 >> 0xf) +
                 (uint)CARRY2(*(uint *)(iVar17 + 0x56),uVar21);
        if ((iVar17 < 1) && (iVar17 < 0)) {
          for (uVar21 = 0xf8; uVar21 < GUnitCount; uVar21 = uVar21 + 1) {
            uVar22 = (undefined2)((ulong)GUnits >> 0x10);
            iVar17 = (int)GUnits;
            local_20 = *(byte *)(iVar17 + uVar21 * 9);
            if ((*(byte *)(iVar17 + uVar21 * 9 + 2) == uStack_16) &&
               (*(int *)((uint)local_20 * 0x27 + 0x123) < 0)) {
              uVar14 = *(uint *)((uint)local_20 * 0x27 + 0x123);
              uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
              iVar20 = *(int *)(iVar20 + 0x58) + ((int)uVar14 >> 0xf) +
                       (uint)CARRY2(*(uint *)(iVar20 + 0x56),uVar14);
              if ((iVar20 < 1) && (iVar20 < 0)) {
                if ((cVar11 == '\0') && (*(char *)(iVar17 + uVar21 * 9 + 1) != '\0')) {
                  uVar13 = ovr_randBelow(100);
                  uVar22 = (undefined2)((ulong)GUnits >> 0x10);
                  iVar17 = (int)GUnits;
                  if (*(byte *)((uint)*(byte *)(iVar17 + uVar21 * 9) * 0x27 + 0x130) <= (byte)uVar13
                     ) {
                    if (*(char *)(iVar17 + uVar21 * 9 + 1) != '\0') {
                      pcVar2 = (char *)(iVar17 + uVar21 * 9 + 1);
                      *pcVar2 = *pcVar2 + -1;
                    }
                    iVar17 = (int)GUnits;
                    uVar22 = (undefined2)((ulong)GUnits >> 0x10);
                    if (((*(uint *)((uint)local_20 * 0x27 + 0x121) & 4) == 0) &&
                       ((*(char *)(iVar17 + uVar21 * 9 + 1) == '\0' ||
                        ((*(uint *)((uint)local_20 * 0x27 + 0x121) & 0x200) != 0)))) {
                      OVC22_5087_1674(uVar21,&local_1c);
                    }
                    else if (((*(int16_t *)(BLD_RECORDS + (uint)local_20 * 0xc)
                               != 0 || *(int16_t *)(BLD_RECORDS + 2 +
                                               (uint)local_20 * 0xc) != 0) ||
                             (*(char *)((uint)local_20 * 0x27 + 0x11e) == '\x10')) &&
                            (cVar12 = OVC22_5087_510e(CONCAT11((char)(uVar21 * 9 >> 8),
                                                               *(undefined1 *)
                                                                (iVar17 + uVar21 * 9 + 4)),
                                                      CONCAT11((char)(uVar21 * 9 >> 8),
                                                               *(undefined1 *)
                                                                (iVar17 + uVar21 * 9 + 6))),
                            cVar12 != '\0')) {
                      local_1c = '\x01';
                    }
                  }
                }
              }
              else {
                uVar7 = *(uint *)((uint)local_20 * 0x27 + 0x123);
                uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
                iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
                puVar3 = (uint *)(iVar17 + 0x56);
                uVar14 = *puVar3;
                *puVar3 = *puVar3 + uVar7;
                piVar4 = (int *)(iVar17 + 0x58);
                *piVar4 = *piVar4 + ((int)uVar7 >> 0xf) + (uint)CARRY2(uVar14,uVar7);
              }
            }
          }
          uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar17 + 0x58) = 0;
          *(undefined2 *)(iVar17 + 0x56) = 0;
        }
        else {
          if ((cVar11 == '\0') && (0 < *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54))) {
            uStack_10 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54) / 10;
          }
          else {
            uStack_10 = 0;
          }
          bVar26 = CARRY2(GPopulationLo,uStack_10);
          GPopulationLo = GPopulationLo + uStack_10;
          GPopulationHi = GPopulationHi + ((int)uStack_10 >> 0xf) + (uint)bVar26;
          uVar14 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54) - uStack_10;
          uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          puVar3 = (uint *)(iVar17 + 0x56);
          uVar21 = *puVar3;
          *puVar3 = *puVar3 + uVar14;
          piVar4 = (int *)(iVar17 + 0x58);
          *piVar4 = *piVar4 + ((int)uVar14 >> 0xf) + (uint)CARRY2(uVar21,uVar14);
        }
        if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3e) * 0x95) & 0x100)
            == 0) {
          if (*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f) <
              *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d)) {
            uStack_12 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d) -
                        *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f);
            uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
            iVar17 = *(int *)(iVar20 + 0x62);
            if ((-1 < iVar17) && ((0 < iVar17 || (*(int *)(iVar20 + 0x60) != 0)))) {
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar21 = *(uint *)(iVar17 + 0x62);
              if ((0x7fff < uVar21) ||
                 ((uStack_14 = uStack_12, (int)uVar21 < 1 && (*(uint *)(iVar17 + 0x60) <= uStack_12)
                  ))) {
                uStack_14 = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x60);
              }
              uStack_12 = uStack_12 - uStack_14;
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar3 = (uint *)(iVar17 + 0x60);
              uVar21 = *puVar3;
              *puVar3 = *puVar3 - uStack_14;
              piVar4 = (int *)(iVar17 + 0x62);
              *piVar4 = *piVar4 - (uint)(uVar21 < uStack_14);
            }
            if (uStack_12 != 0) {
              uStack_a = uStack_12;
              if (*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0) < uStack_12) {
                uStack_a = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0);
              }
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar21 = *(uint *)(iVar17 + 0x58);
              if (((int)uVar21 < 1) && ((0x7fff < uVar21 || (*(uint *)(iVar17 + 0x56) < uStack_a))))
              {
                uStack_a = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x56);
              }
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar3 = (uint *)(iVar17 + 0x56);
              uVar21 = *puVar3;
              *puVar3 = *puVar3 - uStack_a;
              piVar4 = (int *)(iVar17 + 0x58);
              *piVar4 = *piVar4 - (uint)(uVar21 < uStack_a);
              uStack_12 = uStack_12 - uStack_a;
              *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa2) = uStack_a;
            }
            if (cVar11 == '\0') {
              for (iVar17 = 0; (uStack_12 != 0 && (iVar17 < (int)(uint)GLeaderCount));
                  iVar17 = iVar17 + 1) {
                if ((*(char *)((int)*(undefined4 *)(iVar17 << 2) + 0x3d) != '\0') &&
                   ((*(char *)((int)*(undefined4 *)(iVar17 << 2) + 0x3f) == '\0' &&
                    (uVar22 = (undefined2)((ulong)*(undefined4 *)(iVar17 << 2) >> 0x10),
                    iVar20 = (int)*(undefined4 *)(iVar17 << 2),
                    *(int *)(iVar20 + 0x60) != 0 || *(int *)(iVar20 + 0x62) != 0)))) {
                  uVar22 = (undefined2)((ulong)*(undefined4 *)(iVar17 << 2) >> 0x10);
                  iVar20 = (int)*(undefined4 *)(iVar17 << 2);
                  uVar21 = *(uint *)(iVar20 + 0x62);
                  if ((uVar21 < 0x8000) &&
                     ((0 < (int)uVar21 || (uStack_12 < *(uint *)(iVar20 + 0x60))))) {
                    uStack_14 = uStack_12;
                  }
                  else {
                    uStack_14 = *(uint *)((int)*(undefined4 *)(iVar17 << 2) + 0x60);
                  }
                  uStack_12 = uStack_12 - uStack_14;
                  uVar22 = (undefined2)((ulong)*(undefined4 *)(iVar17 << 2) >> 0x10);
                  iVar20 = (int)*(undefined4 *)(iVar17 << 2);
                  puVar3 = (uint *)(iVar20 + 0x60);
                  uVar21 = *puVar3;
                  *puVar3 = *puVar3 - uStack_14;
                  piVar4 = (int *)(iVar20 + 0x62);
                  *piVar4 = *piVar4 - (uint)(uVar21 < uStack_14);
                }
              }
            }
            uVar21 = 0;
            while ((uVar21 < EntityCount && (uStack_12 != 0))) {
              uVar24 = Entities.seg;
              uVar13 = Entities.ofs;
              if (((*(char *)(uVar13 + uVar21 * 0x37 + 0x18) == '\0') &&
                  (*(byte *)(uVar13 + uVar21 * 0x37 + 0x1a) == uStack_16)) &&
                 ((bVar9 || (1 < *(byte *)(uVar13 + uVar21 * 0x37 + 0xe))))) {
                if (*(char *)(uVar13 + uVar21 * 0x37 + 0xe) != '\0') {
                  if (DebugVerbose != false) {
                    printf("kill 3\r",unaff_DI);
                  }
                  pcVar2 = (char *)(Entities.ofs + uVar21 * 0x37 + 0xe);
                  *pcVar2 = *pcVar2 + -1;
                  if (*(char *)(Entities.ofs + uVar21 * 0x37 + 0xe) == '\0') {
                    cStack_1d = '\x01';
                  }
                }
                uStack_12 = uStack_12 - 1;
              }
              uVar21 = uVar21 + 1;
            }
          }
          else {
            uVar14 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f) -
                     *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d);
            uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
            puVar3 = (uint *)(iVar17 + 0x60);
            uVar21 = *puVar3;
            *puVar3 = *puVar3 + uVar14;
            piVar4 = (int *)(iVar17 + 0x62);
            *piVar4 = *piVar4 + (uint)CARRY2(uVar21,uVar14);
          }
        }
        uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar17 = *(int *)(iVar18 + 0x62);
        uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar20 = *(int *)(iVar19 + 0x80);
        if ((iVar20 <= iVar17) &&
           ((iVar20 < iVar17 || (*(uint *)(iVar19 + 0x7e) < *(uint *)(iVar18 + 0x60))))) {
          uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          uVar21 = *(uint *)(iVar17 + 0x60);
          uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
          puVar3 = (uint *)(iVar20 + 0x7e);
          uVar14 = (uint)(uVar21 < *puVar3);
          uVar7 = *(int *)(iVar17 + 0x62) - *(int *)(iVar20 + 0x80);
          if (((int)(uVar7 - uVar14) < 0) ||
             ((uVar7 == uVar14 &&
              (uVar21 - *puVar3 <= *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0))))) {
            uStack_a = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x60) -
                       *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7e);
          }
          else {
            uStack_a = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0);
          }
          *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa2) = -uStack_a;
          uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          puVar3 = (uint *)(iVar17 + 0x56);
          uVar21 = *puVar3;
          *puVar3 = *puVar3 + uStack_a;
          piVar4 = (int *)(iVar17 + 0x58);
          *piVar4 = *piVar4 + (uint)CARRY2(uVar21,uStack_a);
          uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          uVar22 = *(undefined2 *)(iVar17 + 0x7e);
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar20 + 0x62) = *(undefined2 *)(iVar17 + 0x80);
          *(undefined2 *)(iVar20 + 0x60) = uVar22;
        }
        if ((*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x5b) <
             *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d)) &&
           ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3e) * 0x95) & 0x80)
            == 0)) {
          uStack_12 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d) -
                      *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x5b);
          uVar21 = 0;
          while ((uVar21 < EntityCount && (uStack_12 != 0))) {
            uVar24 = Entities.seg;
            uVar13 = Entities.ofs;
            if ((*(byte *)(uVar13 + uVar21 * 0x37 + 0x1a) == uStack_16) &&
               ((((*(char *)(uVar13 + uVar21 * 0x37 + 0x18) == '\0' &&
                  (*(int *)(uVar13 + uVar21 * 0x37 + 8) == 0)) &&
                 (*(int *)(uVar13 + uVar21 * 0x37 + 10) == 0)) &&
                (3 < *(byte *)(uVar13 + uVar21 * 0x37 + 0xe))))) {
              if (DebugVerbose != false) {
                printf("kill 2 \r",unaff_DI);
              }
              pcVar2 = (char *)(Entities.ofs + uVar21 * 0x37 + 0xe);
              *pcVar2 = *pcVar2 + -1;
              uStack_12 = uStack_12 - 1;
            }
            uVar21 = uVar21 + 1;
          }
        }
        ovr_OVC25_5b66_1b48(uStack_16);
        _fmemset((void *)CONCAT22(((int *)(uStack_16 * 4))[1],
                                  (void *)(*(int *)(uStack_16 * 4) + 0x6a)),0,6);
        _fmemset((void *)CONCAT22(((int *)(uStack_16 * 4))[1],
                                  (void *)(*(int *)(uStack_16 * 4) + 0x76)),0,6);
        uVar13 = ovr_randBelow(100);
        if ((byte)uVar13 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6c) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 100);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6a) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 100);
        }
        uVar13 = ovr_randBelow(100);
        if ((byte)uVar13 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6e) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x66);
        }
        else {
          piVar4 = (int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6c);
          *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x66);
        }
        piVar4 = (int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6e);
        *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x68);
        uVar13 = ovr_randBelow(100);
        if ((byte)uVar13 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x78) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x70);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x76) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x70);
        }
        uVar13 = ovr_randBelow(100);
        if ((byte)uVar13 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7a) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x72);
        }
        else {
          piVar4 = (int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x78);
          *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x72);
        }
        uVar13 = ovr_randBelow(100);
        if ((byte)uVar13 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7c) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x74);
        }
        else {
          piVar4 = (int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7a);
          *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x74);
        }
        *(undefined1 *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa7) =
             *(undefined1 *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa6);
        if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3f) != '\0') {
          uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
          iVar17 = *(int *)(iVar20 + 0x58);
          if ((iVar17 < 1) && ((iVar17 != 0 || (*(int *)(iVar20 + 0x56) == 0)))) {
            uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
            *(undefined2 *)(iVar17 + 0x58) = 0;
            *(undefined2 *)(iVar17 + 0x56) = 0x32;
          }
        }
        if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0xaa) != '\0') {
          uStack_4 = (uint)*(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xaa);
          for (uVar21 = 0; (int)uVar21 < (int)(uint)GLeaderCount; uVar21 = uVar21 + 1) {
            uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
            iVar17 = *(int *)(iVar18 + 0x58);
            uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
            iVar20 = *(int *)(iVar19 + 0x8c);
            if ((iVar20 <= iVar17) &&
               ((iVar17 != iVar20 || (*(uint *)(iVar19 + 0x8a) <= *(uint *)(iVar18 + 0x56)))))
            break;
            if ((*(char *)((int)*(undefined4 *)(uVar21 << 2) + 0x3d) != '\0') &&
               (((0 < *(int *)((int)*(undefined4 *)(uVar21 << 2) + 0x54) &&
                 (*(char *)((int)*(undefined4 *)(uVar21 << 2) + 0x3f) == '\0')) &&
                (uVar21 != uStack_16)))) {
              uStack_2e = (uint)(((long)*(int *)((int)*(undefined4 *)(uVar21 << 2) + 0x54) *
                                  (long)(int)uStack_4 & 0xffffU) / 100);
              iStack_2c = 0;
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar14 = *(uint *)(iVar17 + 0x8a);
              uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar3 = (uint *)(iVar20 + 0x56);
              iVar17 = (*(int *)(iVar17 + 0x8c) - *(int *)(iVar20 + 0x58)) -
                       (uint)(uVar14 < *puVar3);
              if ((iVar17 < 1) && ((iVar17 < 0 || (uVar14 - *puVar3 < uStack_2e)))) {
                uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
                iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
                uVar14 = *(uint *)(iVar17 + 0x8a);
                uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
                iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
                puVar3 = (uint *)(iVar20 + 0x56);
                uStack_2e = uVar14 - *puVar3;
                iStack_2c = (*(int *)(iVar17 + 0x8c) - *(int *)(iVar20 + 0x58)) -
                            (uint)(uVar14 < *puVar3);
              }
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uVar21 << 2) >> 0x10);
              iVar20 = (int)*(undefined4 *)(uVar21 << 2);
              iVar17 = *(int *)(iVar20 + 0x58);
              if ((iVar17 <= iStack_2c) &&
                 ((iVar17 < iStack_2c || (*(uint *)(iVar20 + 0x56) < uStack_2e)))) {
                uVar22 = (undefined2)((ulong)*(undefined4 *)(uVar21 << 2) >> 0x10);
                iVar17 = (int)*(undefined4 *)(uVar21 << 2);
                iStack_2c = *(int *)(iVar17 + 0x58);
                uStack_2e = *(uint *)(iVar17 + 0x56);
              }
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar3 = (uint *)(iVar17 + 0x56);
              uVar14 = *puVar3;
              *puVar3 = *puVar3 + uStack_2e;
              piVar4 = (int *)(iVar17 + 0x58);
              *piVar4 = *piVar4 + iStack_2c + (uint)CARRY2(uVar14,uStack_2e);
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uVar21 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uVar21 << 2);
              puVar3 = (uint *)(iVar17 + 0x56);
              uVar14 = *puVar3;
              *puVar3 = *puVar3 - uStack_2e;
              piVar4 = (int *)(iVar17 + 0x58);
              *piVar4 = (*piVar4 - iStack_2c) - (uint)(uVar14 < uStack_2e);
            }
          }
        }
        iVar17 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x58);
        if ((iVar17 < 1) && (iVar17 < 0)) {
          uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar17 + 0x58) = 0;
          *(undefined2 *)(iVar17 + 0x56) = 0;
        }
        uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar17 = *(int *)(iVar18 + 0x58);
        uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar20 = *(int *)(iVar19 + 0x8c);
        if ((iVar20 <= iVar17) &&
           ((iVar20 < iVar17 || (*(uint *)(iVar19 + 0x8a) < *(uint *)(iVar18 + 0x56))))) {
          uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          uVar22 = *(undefined2 *)(iVar17 + 0x8a);
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar20 + 0x58) = *(undefined2 *)(iVar17 + 0x8c);
          *(undefined2 *)(iVar20 + 0x56) = uVar22;
        }
      }
    }
    GGameState = 0x40;
    if (DebugVerbose != false) {
      printf("%d \r",0x40);
    }
    for (uVar21 = 0xf8; uVar21 < GUnitCount; uVar21 = uVar21 + 1) {
      uVar22 = (undefined2)((ulong)GUnits >> 0x10);
      iVar17 = (int)GUnits;
      if ((*(uint *)((uint)*(byte *)(iVar17 + uVar21 * 9) * 0x27 + 0x121) & 0x40) != 0) {
        if (*(char *)(iVar17 + uVar21 * 9 + 8) != '\0') {
          pcVar2 = (char *)(iVar17 + uVar21 * 9 + 8);
          *pcVar2 = *pcVar2 + -1;
        }
        uVar22 = (undefined2)((ulong)GUnits >> 0x10);
        if (*(char *)((int)GUnits + uVar21 * 9 + 8) == '\0') {
          uVar8 = *(undefined4 *)((uint)*(byte *)((int)GUnits + uVar21 * 9 + 2) << 2);
          if (*(char *)((int)uVar8 + 0x3f) == '\0') {
            ovr_play_sfx(81,0);
            uVar22 = (undefined2)((ulong)GUnits >> 0x10);
            pcVar15 = (char *)ovr_OVC23_55fe_3450(*(undefined2 *)
                                                   ((int)GUnits + uVar21 * 9 + 4),
                                                  *(undefined2 *)
                                                   ((int)GUnits + uVar21 * 9 + 6));
            pcVar15 = ovr_fmVsprintf((char *)"Mine exhausted at (%d, %d).",pcVar15);
            ovr_say(pcVar15);
            ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
          }
          OVC22_5087_1674(uVar21,&local_1c);
        }
      }
    }
    GGameState = 0x42;
    if (DebugVerbose != false) {
      printf("%d \r",0x42);
    }
    ovr_driver_2d63_0a67((undefined2)GMapFlags,(*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),0,0,0x93,0x3b,0xfff7);
    for (uStack_16 = 0; uStack_16 < DAT_2410_0881; uStack_16 = uStack_16 + 1) {
      puVar3 = (uint *)((int)GMapFlags + *(int *)(uStack_16 * 0x13 + 2) * 0x128 +
                       *(int *)(uStack_16 * 0x13) * 2);
      *puVar3 = *puVar3 | 8;
    }
    if (EntityCount <= DAT_2410_55d6) {
      DAT_2410_55d6 = 0;
      for (uStack_16 = 0; (int)uStack_16 < (int)(uint)GLeaderCount; uStack_16 = uStack_16 + 1) {
        if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3d) != '\0') {
          memcpy((uint8_t *)(*(int *)(uStack_16 * 4) + 0x8e),
                 (uint8_t *)(*(int *)(uStack_16 * 4) + 0x94),3);
        }
      }
    }
    iStack_e = 0;
    bStack_5 = ovr_manage_4d05_1b1d();
    if ((bStack_5 == 0xff) || (GCanPromote == '\0')) {
      iStack_c = 0;
    }
    else if (*(byte *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x86) < 5) {
      iStack_c = 0x28;
    }
    else {
      iStack_c = (uint)*(byte *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x86) * 4 + 0x14;
    }
    for (uStack_16 = DAT_2410_55d6; uStack_16 < EntityCount; uStack_16 = uStack_16 + 1) {
      uVar24 = Entities.seg;
      uVar13 = Entities.ofs;
      if (((*(char *)(uVar13 + uStack_16 * 0x37 + 0x18) == '\0') &&
          (*(int *)(uVar13 + uStack_16 * 0x37 + 8) == 0)) &&
         (*(int *)(uVar13 + uStack_16 * 0x37 + 10) == 0)) {
        bStack_6 = *(byte *)(uVar13 + uStack_16 * 0x37 + 0xd);
        uVar6 = *(undefined1 *)((int)(char **)GMenuStrings + (uint)bStack_6 * 0x95 + 0x1f);
        bVar5 = *(byte *)(uVar13 + uStack_16 * 0x37 + 0x1a);
        bVar26 = false;
        bVar10 = false;
        bVar9 = false;
        if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bStack_6 * 0x95) == -1) {
          bVar26 = true;
        }
        else {
          bStack_1b = *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x89);
          if (bStack_1b < 5) {
            iStack_1a = *(int *)(uVar13 + uStack_16 * 0x37 + 2);
            iStack_18 = ovr_OVC23_55fe_3450(*(undefined2 *)(uVar13 + uStack_16 * 0x37));
            pcVar15 = (char *)"puppetmaker" + 3;
            if ((*(uint *)((int)GMapFlags + iStack_1a * 0x128 + iStack_18 * 2) & 8) == 0) {
              local_1e = 0x22;
              local_1f = 0x21;
              local_20 = 0x22;
            }
            else {
              uVar22 = ovr_attact_3f0b_0585
                                 (iStack_18,iStack_1a,
                                  CONCAT11((char)((uint)&local_20 >> 8),bStack_1b),&local_20);
              ovr_attact_3f0b_2303(uVar22,pcVar15);
            }
          }
          else {
            local_1e = 0x22;
            local_1f = 0x21;
            local_20 = 0x22;
          }
          uVar13 = ovr_randBelow(100);
          if ((byte)uVar13 < local_1e) {
            bVar26 = true;
          }
          else if ((uVar13 & 0xff) < (uint)local_1f + (uint)local_1e) {
            bVar10 = true;
          }
          else {
            bVar9 = true;
          }
        }
        if ((bVar9) &&
           (cVar11 = ovr_OVC23_55fe_0487(*(undefined2 *)(Entities.ofs + uStack_16 * 0x37),
                                         *(undefined2 *)(Entities.ofs + uStack_16 * 0x37 + 2),uVar6)
           , cVar11 == '\0')) {
          if ((local_1f == 0) && (local_1e == 0)) {
            uVar13 = ovr_randBelow(2);
            if ((uVar13 & 0xff) == 0) {
              bVar26 = true;
            }
            else {
              bVar10 = true;
            }
          }
          else {
            uVar13 = ovr_randBelow((uint)local_1f + (uint)local_1e);
            if ((byte)uVar13 < local_1e) {
              bVar26 = true;
            }
            else {
              bVar10 = true;
            }
          }
        }
        if ((bVar26) && (cVar11 = OVC22_5087_1532(uStack_16), cVar11 == '\0')) {
          bVar10 = true;
        }
        if (bVar10) {
          if ((*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bStack_6 * 0x95) != -1) &&
             (bVar5 != 0xff)) {
            if ((*(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x3f) != '\0') ||
               (*(byte *)(Entities.ofs + uStack_16 * 0x37 + 0xf) <
                *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x53))) {
              iVar17 = Entities.ofs + uStack_16 * 0x37;
              uVar22 = OVC22_5087_18b6(iVar17,Entities.seg,iStack_c);
              uVar27 = LXMUL_at_(3,CONCAT22(iVar17,uVar22));
              iVar17 = Entities.ofs + uStack_16 * 0x37;
              uVar22 = (uint)ovr_OVC15_4207_26bc(iVar17,Entities.seg,
                                           (int)(((ulong)((uVar27 & 0x10000) != 0) << 0x10 |
                                                 uVar27 & 0xffff) >> 1),(int)((long)uVar27 >> 0x11))
              ;
              uVar14 = OVC22_5087_1d4a(uVar22,iVar17);
              uVar13 = Entities.seg;
              iVar20 = Entities.ofs + uStack_16 * 0x37;
              uVar21 = *(uint *)(iVar20 + 0x10);
              iVar18 = Entities.ofs + uStack_16 * 0x37;
              *(int *)(iVar18 + 0x12) =
                   *(int *)(iVar20 + 0x12) + iVar17 + (uint)CARRY2(uVar21,uVar14);
              *(int *)(iVar18 + 0x10) = uVar21 + uVar14;
              ovr_OVC41_6a8f_002e(Entities.ofs + uStack_16 * 0x37,Entities.seg);
            }
          }
          OVC22_5087_1991(uStack_16);
          OVC22_5087_1ac1(uStack_16);
          OVC22_5087_1ca4(uStack_16);
        }
        iStack_2a = (uint)*(byte *)(Entities.ofs + uStack_16 * 0x37 + 0xe) -
                    (uint)*(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4);
        if (0 < iStack_2a) {
          if (3 < iStack_2a) {
            iStack_2a = 3;
          }
          if (iStack_2a == 3) {
            if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x92) == 0) {
              iStack_2a = 2;
            }
            else {
              piVar4 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x92);
              *piVar4 = *piVar4 + -1;
            }
          }
          if (iStack_2a == 2) {
            if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x90) == 0) {
              iStack_2a = 1;
            }
            else {
              piVar4 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x90);
              *piVar4 = *piVar4 + -1;
            }
          }
          if (iStack_2a == 1) {
            if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x8e) == 0) {
              iStack_2a = 0;
            }
            else {
              piVar4 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x8e);
              *piVar4 = *piVar4 + -1;
            }
          }
          *(char *)(Entities.ofs + uStack_16 * 0x37 + 0xe) =
               *(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4) + (char)iStack_2a;
        }
        iStack_e = iStack_e + 1;
        if (199 < iStack_e) break;
      }
    }
    DAT_2410_55d6 = uStack_16;
    DAT_2410_648e = 1;
    ovr_unit_6616_00d8();
    GGameState = 0x44;
    if (DebugVerbose != false) {
      printf("%d \r",0x44);
    }
    uVar21 = EntityCount;
    if (cStack_1d != '\0') {
      while (uStack_16 = uVar21 - 1, -1 < (int)uStack_16) {
        uVar24 = Entities.seg;
        uVar13 = Entities.ofs;
        uVar21 = uStack_16;
        if (*(char *)(uVar13 + uStack_16 * 0x37 + 0xe) == '\0') {
          if (*(char *)((int)(char **)GMenuStrings +
                       (uint)*(byte *)(uVar13 + uStack_16 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0') {
            dst = 0xa000;
            ovr_OVC23_55fe_3450(*(undefined2 *)(uVar13 + uStack_16 * 0x37),
                                *(undefined2 *)(uVar13 + uStack_16 * 0x37 + 2));
            uVar22 = 0x195d;
            pcVar15 = ovr_fmVsprintf((char *)
                                     "Intelligence reports %s unit died of starvation. (%d, %d)",
                                     (char *)*(undefined2 *)
                                              ((int)&far_t_ARRAY_2410_26f7[0].seg + 1 +
                                              (uint)*(byte *)(Entities.ofs + uStack_16 * 0x37 + 0xd)
                                              * 0x95));
            ovr_uiNotify((char *)CONCAT22(uVar22,pcVar15),dst);
          }
          ovr_OVC15_4207_0e17(uStack_16);
          uVar21 = uStack_16;
        }
      }
    }
    if (local_1c != '\0') {
      ovr_constr_36ce_1db4();
    }
  }
  return;
}
