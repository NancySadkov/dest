agnt_t * __cdecl16far ovc15_textError(undefined4 param_1,agnt_t *param_2)

{
  uint *puVar1;
  uint16_t *puVar2;
  uint8_t *puVar3;
  undefined4 uVar4;
  far_t handle;
  far_t handle_00;
  uint8_t uVar5;
  char cVar6;
  byte bVar7;
  char cVar8;
  bool bVar9;
  undefined1 uVar10;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  uint16_t uVar11;
  far_t far *pfVar12;
  cte_t *pcVar13;
  undefined2 *puVar14;
  long *plVar15;
  uint uVar16;
  uint16_t uVar17;
  uint32_t *puVar18;
  agnt_t *paVar19;
  int iVar20;
  int iVar21;
  entity_t *in_CX;
  stg_tmp_t *gfx;
  uint16_t uVar25;
  uint16_t dstSeg;
  entity_t *peVar26;
  uint uVar27;
  undefined1 *puVar28;
  entity_t *peVar29;
  uint32_t *unaff_SI;
  char *pcVar30;
  uint uVar31;
  char *unaff_DI;
  undefined2 uVar32;
  uint32_t *puVar33;
  undefined2 uVar34;
  uint8_t uVar35;
  char *unaff_SS;
  bool bVar36;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  ulong uVar37;
  char acStackY_1b6 [120];
  char acStackY_13e [36];
  uint16_t auStackY_11a [66];
  uint16_t auStackY_96 [24];
  entity_t eStackY_66;
  undefined2 uStackY_2c;
  undefined2 uStackY_2a;
  entity_t *in_stack_0000ffe2;
  uint8_t uVar38;
  far_t entries;
  int iVar39;
  undefined1 uVar40;
  undefined1 in_stack_0000ffee;
  undefined1 in_stack_0000ffef;
  undefined1 in_stack_0000fff0;
  undefined1 in_stack_0000fff1;
  undefined1 uVar41;
  undefined1 in_stack_0000fff2;
  undefined1 in_stack_0000fff3;
  byte in_stack_0000fff4;
  byte in_stack_0000fff5;
  uint uVar42;
  byte bVar43;
  uint8_t in_stack_0000fffc;
  byte bVar44;
  
  uVar16 = CONCAT11(in_stack_0000fff1,in_stack_0000fff0);
  puVar33 = (uint32_t *)((ulong)param_1 >> 0x10);
  uVar27 = (uint)param_1;
  puVar14 = (undefined2 *)((uint)*(byte *)(uVar27 + 0x1a) * 4);
  uVar11 = puVar14[1];
  uVar32 = *puVar14;
  bVar43 = (byte)uVar32;
  uVar10 = (undefined1)((uint)uVar32 >> 8);
  uVar25 = 0x195d;
  uVar34 = 0x195d;
  bVar44 = *(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)*(byte *)(uVar27 + 0xd) * 0x95);
  if (bVar44 == 0xff) {
    bVar44 = 0;
  }
  pcVar30 = (char *)0x0;
  uVar17 = (uint16_t)bVar44;
  if (6 < uVar17) {
    if ((agnt_t *)param_2 != (agnt_t *)0x0 || (*(uint16_t *)((uint8_t *)&(param_2) + 2)) != 0) {
      uVar40 = 0;
      uVar23 = 0;
      uVar10 = 100;
      uVar24 = 0;
      plVar15 = LXMUL_at_((long *)((int)&GSTARTX_SavedVectors[2].ofs + 1),ZEXT24(unaff_SI) << 0x10,
                          CONCAT22(uVar11,uVar32));
      uVar37 = LDIV_at_(CONCAT13((char)((uint)(*(uint16_t *)((uint8_t *)&(param_2) + 2)) >> 8),
                                 CONCAT12((char)(*(uint16_t *)((uint8_t *)&(param_2) + 2)),plVar15)),
                        CONCAT13(uVar23,CONCAT12(uVar40,CONCAT11(uVar24,uVar10))));
      param_2 = (agnt_t *)(uVar37 & 0xffff);
    }
    return (agnt_t *)param_2;
  }
  puVar28 = (undefined1 *)(uVar17 * 2);
  switch(uVar17) {
  case 0:
    if ((bVar44 & (&stack0x02c2)[(int)unaff_DI]) == 0) {
      iVar39 = (int)puVar33 + (uint)(0xffec < uVar27);
      uVar34 = 0x1000;
      plVar15 = LXRSH_at_((long *)unaff_SI,CONCAT22(uVar11,uVar32),in_stack_0000fffc);
      uVar27 = (int)plVar15 + HeapPtr;
      iVar39 = iVar39 + (uint)CARRY2((uint)plVar15,HeapPtr);
      uVar16 = uVar27;
      if (iVar39 != 0) {
        uVar16 = 0xffff;
      }
      if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar39 != 0 || (MUSHandle.seg < uVar27)))
          ) || ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 &&
                ((iVar39 != 0 || (MUSHandle.seg < uVar27)))))) {
        uVar34 = 0x22f8;
        in_stack_0000fff0 = 0x28;
        in_stack_0000fff1 = 0x88;
        ovr_fmFreeAudio(1);
      }
      uVar42 = 0xffff;
      HeapPtr = 0xffff;
      bVar36 = false;
      uVar10 = (undefined1)StshCtPtr2.seg;
      uVar24 = (undefined1)(StshCtPtr2.seg >> 8);
      uVar27 = 0xffff;
      uVar11 = StshCtPtr2.ofs;
      while( true ) {
        uVar40 = (undefined1)uVar34;
        uVar23 = (undefined1)((uint)uVar34 >> 8);
        if (uVar11 == 0 && CONCAT11(uVar24,uVar10) == 0) break;
        uVar32 = (undefined2)(CONCAT13(uVar24,CONCAT12(uVar10,uVar11)) >> 0x10);
        uVar31 = uVar27;
        if (*(int *)(uVar11 + 0x11) != 0 || *(int *)(uVar11 + 0x13) != 0) {
          if (*(uint *)(uVar11 + 0x13) < uVar16) {
            uVar32 = (undefined2)(CONCAT13(uVar24,CONCAT12(uVar10,uVar11)) >> 0x10);
            in_stack_0000ffee = 0x7f;
            in_stack_0000ffef = 0x88;
            (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)*(undefined2 *)(uVar11 + 0x13);
            handle.ofs = *(undefined2 *)(uVar11 + 0x11);
            (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)*(undefined2 *)(uVar11 + 0x13) >> 8);
            stshFree(handle);
            uVar32 = (undefined2)(CONCAT13(uVar24,CONCAT12(uVar10,uVar11)) >> 0x10);
            *(undefined2 *)(uVar11 + 0x13) = 0;
            *(undefined2 *)(uVar11 + 0x11) = 0;
            bVar36 = true;
            in_stack_0000fff0 = uVar40;
            in_stack_0000fff1 = uVar23;
          }
          else {
            if (*(uint *)(uVar11 + 0x13) < uVar27) {
              uVar31 = *(uint *)(uVar11 + 0x13);
              in_stack_0000ffee = (undefined1)uVar11;
              in_stack_0000ffef = (undefined1)(uVar11 >> 8);
              in_stack_0000fff0 = uVar10;
              in_stack_0000fff1 = uVar24;
              uVar42 = uVar27;
            }
            if (*(uint *)(uVar11 + 0x13) < HeapPtr) {
              HeapPtr = *(uint *)(uVar11 + 0x13);
            }
          }
        }
        uVar32 = (undefined2)(CONCAT13(uVar24,CONCAT12(uVar10,uVar11)) >> 0x10);
        puVar14 = (undefined2 *)(uVar11 + 0xb);
        uVar11 = *(uint16_t *)(uVar11 + 9);
        uVar10 = (undefined1)*puVar14;
        uVar24 = (undefined1)((uint)*puVar14 >> 8);
        uVar27 = uVar31;
      }
      if (!bVar36) {
        if (uVar27 == 0xffff) {
          bVar36 = ovr_fmFreeAudio(1);
          if (bVar36) {
            return (agnt_t *)0x1;
          }
          if (audioBusy == '\0') {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(0x14);
          }
          return (agnt_t *)0x0;
        }
        iVar39 = CONCAT11(in_stack_0000ffef,in_stack_0000ffee);
        uVar32 = (undefined2)
                 (CONCAT13(in_stack_0000fff1,CONCAT12(in_stack_0000fff0,iVar39)) >> 0x10);
        uVar10 = 0x39;
        uVar24 = 0x89;
        (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)*(undefined2 *)(iVar39 + 0x13);
        handle_00.ofs = *(undefined2 *)(iVar39 + 0x11);
        (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)((uint)*(undefined2 *)(iVar39 + 0x13) >> 8);
        stshFree(handle_00);
        HeapPtr = uVar42;
        iVar39 = CONCAT11(uVar24,uVar10);
        uVar32 = (undefined2)(CONCAT13(uVar23,CONCAT12(uVar40,iVar39)) >> 0x10);
        *(undefined2 *)(iVar39 + 0x13) = 0;
        *(undefined2 *)(iVar39 + 0x11) = 0;
      }
    }
    return (agnt_t *)0x1;
  case 1:
    *puVar28 = *puVar28;
    do {
      uVar32 = 0x195d;
      pfVar12 = stshSprite((far_t far *)*(undefined2 *)
                                     ((int)AgntGs[0].sprfls + 6 +
                                     (int)pcVar30 * 0x95 + (int)unaff_DI * 2),
                           *(int16_t *)(puVar28 + 0x26fe),
                           (anm_t *)CONCAT13(uVar10,CONCAT12(bVar43,unaff_SI)),uVar11,
                           (bool)in_stack_0000fffc);
      iVar39 = (int)pcVar30 * 0x95 + (int)unaff_DI * 4;
      *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar39) = uVar32;
      *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar39) =(uint16_t)( pfVar12);
      while( true ) {
        unaff_DI = unaff_DI + 1;
        while (2 < (int)unaff_DI) {
          for (iVar39 = 0; iVar39 < 6; iVar39 = iVar39 + 1) {
            uVar32 = 0x195d;
            if (*(int *)((int)AgntGs[0].prtfls + (int)pcVar30 * 0x95 + iVar39 * 2) != 0) {
              if ((byte)param_1 == 0) {
                pfVar12 = ovr_stshAllocStub((far_t far *)CONCAT11(bVar44,in_stack_0000fffc));
                iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
                uVar34 = 0x195d;
                *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar20) = uVar32;
                *(undefined2 *)((int)AgntGs[0].prts + iVar20) =(uint16_t)( pfVar12);
                pfVar12 = ovr_stshAllocStub((far_t far *)CONCAT11(bVar44,in_stack_0000fffc));
                iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
                *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar20) = uVar34;
                *(undefined2 *)((int)AgntGs[0].prtpals + iVar20) =(uint16_t)( pfVar12);
              }
              else {
                gfx = (stg_tmp_t *)((int)&BuildingTypes[0x9f].income + 1);
                ovr_grabLbm(*(int16_t *)((int)AgntGs[0].prtfls + (int)pcVar30 * 0x95 + iVar39 * 2));
                in_stack_0000fffc = (uint8_t)gfx;
                bVar44 = (byte)((uint)gfx >> 8);
                ovr_stshUniqueColorsRemap(gfx);
                pfVar12 = ovr_stshRleType2(*(far_t far **)((char *)0x300));
                pcVar13 = ovr_stshStoreFile((uint8_t *)pfVar12);
                iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
                uVar32 = 0x195d;
                *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar20) =(uint16_t)( gfx);
                *(undefined2 *)((int)AgntGs[0].prts + iVar20) =(uint16_t)( pcVar13);
                puVar33 = ovr_stshWrite((uint32_t *)0x0,
                                        (uint8_t *)
                                        CONCAT13(3,(uint3)CONCAT11(bVar44,in_stack_0000fffc)));
                iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
                *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar20) = uVar32;
                *(undefined2 *)((int)AgntGs[0].prtpals + iVar20) =(uint16_t)( puVar33);
                ovr_stgFreeTmp((stg_tmp_t *)CONCAT11(bVar44,in_stack_0000fffc));
              }
            }
          }
          paVar19 = (agnt_t *)
                    (*(uint *)((int)AgntGs[0].prts + 4 + (int)pcVar30 * 0x95) |
                    *(uint *)((int)AgntGs[0].prts + 6 + (int)pcVar30 * 0x95));
          if ((paVar19 == (agnt_t *)0x0) &&
             (paVar19 = (agnt_t *)0x0,
             *(int *)((int)AgntGs[0].prts + (int)pcVar30 * 0x95) != 0 ||
             *(int *)((int)AgntGs[0].prts + 2 + (int)pcVar30 * 0x95) != 0)) {
            uVar32 = *(undefined2 *)((int)AgntGs[0].prts + (int)pcVar30 * 0x95);
            *(undefined2 *)((int)AgntGs[0].prts + 6 + (int)pcVar30 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].prts + 2 + (int)pcVar30 * 0x95);
            *(undefined2 *)((int)AgntGs[0].prts + 4 + (int)pcVar30 * 0x95) = uVar32;
            paVar19 = (agnt_t *)*(uint *)((int)AgntGs[0].prtpals + (int)pcVar30 * 0x95);
            *(undefined2 *)((int)AgntGs[0].prtpals + 6 + (int)pcVar30 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].prtpals + 2 + (int)pcVar30 * 0x95);
            *(uint *)((int)AgntGs[0].prtpals + 4 + (int)pcVar30 * 0x95) = (uint)paVar19;
          }
          for (iVar39 = 2; iVar39 < 6; iVar39 = iVar39 + 2) {
            iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
            if ((*(int *)((int)AgntGs[0].prts + 4 + iVar20) == 0 &&
                 *(int *)((int)AgntGs[0].prts + 6 + iVar20) == 0) &&
               (iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4,
               *(int *)((int)AgntGs[0].prtfls + 8 + iVar20) != 0 ||
               *(int *)((int)AgntGs[0].prtfls + 10 + iVar20) != 0)) {
              iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
              uVar32 = *(undefined2 *)((int)AgntGs[0].prtfls + 8 + iVar20);
              iVar21 = (int)pcVar30 * 0x95 + iVar39 * 4;
              *(undefined2 *)((int)AgntGs[0].prts + 6 + iVar21) =
                   *(undefined2 *)((int)AgntGs[0].prtfls + 10 + iVar20);
              *(undefined2 *)((int)AgntGs[0].prts + 4 + iVar21) = uVar32;
              iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
              uVar32 = *(undefined2 *)((int)AgntGs[0].prts + 0x14 + iVar20);
              iVar21 = (int)pcVar30 * 0x95 + iVar39 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 6 + iVar21) =
                   *(undefined2 *)((int)AgntGs[0].prts + 0x16 + iVar20);
              *(undefined2 *)((int)AgntGs[0].prtpals + 4 + iVar21) = uVar32;
            }
            iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
            paVar19 = (agnt_t *)
                      (*(uint *)((int)AgntGs[0].prts + iVar20) |
                      *(uint *)((int)AgntGs[0].prts + 2 + iVar20));
            if (paVar19 == (agnt_t *)0x0) {
              iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
              if (*(int *)((int)AgntGs[0].prtfls + 4 + iVar20) == 0 &&
                  *(int *)((int)AgntGs[0].prtfls + 6 + iVar20) == 0) {
                paVar19 = (agnt_t *)0x0;
              }
              else {
                iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
                uVar32 = *(undefined2 *)((int)AgntGs[0].prtfls + 4 + iVar20);
                iVar21 = (int)pcVar30 * 0x95 + iVar39 * 4;
                *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar21) =
                     *(undefined2 *)((int)AgntGs[0].prtfls + 6 + iVar20);
                *(undefined2 *)((int)AgntGs[0].prts + iVar21) = uVar32;
                iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
                paVar19 = (agnt_t *)*(uint *)((int)AgntGs[0].prts + 0x10 + iVar20);
                iVar21 = (int)pcVar30 * 0x95 + iVar39 * 4;
                *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar21) =
                     *(undefined2 *)((int)AgntGs[0].prts + 0x12 + iVar20);
                *(uint *)((int)AgntGs[0].prtpals + iVar21) = (uint)paVar19;
              }
            }
          }
          pcVar30 = pcVar30 + 1;
          if (0x29 < (int)pcVar30) {
            return paVar19;
          }
          uVar32 = 0x195d;
          pfVar12 = stshSprite((far_t far *)*(undefined2 *)((int)AgntGs[0].sprfls + (int)pcVar30 * 0x95)
                               ,*(int16_t *)((int)&AgntGs[0].anms + (int)pcVar30 * 0x95),
                               (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                         ((int)&AgntGs[0].nanims +
                                                         (int)pcVar30 * 0x95),
                                                        *(undefined2 *)
                                                         ((int)&AgntGs[0].anms + 2 +
                                                         (int)pcVar30 * 0x95)),
                               CONCAT11((char)((uint)paVar19 >> 8),(byte)param_1),
                               (bool)in_stack_0000fffc);
          *(undefined2 *)((int)AgntGs[0].sprs + 2 + (int)pcVar30 * 0x95) = uVar32;
          *(undefined2 *)((int)AgntGs[0].sprs + (int)pcVar30 * 0x95) =(uint16_t)( pfVar12);
          if (*(int *)((int)AgntGs[0].sprfls + 2 + (int)pcVar30 * 0x95) == 0) {
            uVar32 = *(undefined2 *)((int)AgntGs[0].sprs + (int)pcVar30 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 6 + (int)pcVar30 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].sprs + 2 + (int)pcVar30 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 4 + (int)pcVar30 * 0x95) = uVar32;
          }
          else {
            uVar32 = 0x195d;
            pfVar12 = stshSprite((far_t far *)*(undefined2 *)
                                           ((int)AgntGs[0].sprfls + 2 + (int)pcVar30 * 0x95),
                                 *(int16_t *)((int)&AgntGs[0].anms + (int)pcVar30 * 0x95),
                                 (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                           ((int)&AgntGs[0].nanims +
                                                           (int)pcVar30 * 0x95),
                                                          *(undefined2 *)
                                                           ((int)&AgntGs[0].anms + 2 +
                                                           (int)pcVar30 * 0x95)),
                                 CONCAT11((char)((uint)((int)pcVar30 * 0x95) >> 8),(byte)param_1),
                                 (bool)in_stack_0000fffc);
            *(undefined2 *)((int)AgntGs[0].sprs + 6 + (int)pcVar30 * 0x95) = uVar32;
            *(undefined2 *)((int)AgntGs[0].sprs + 4 + (int)pcVar30 * 0x95) =(uint16_t)( pfVar12);
          }
          if (*(int *)((int)AgntGs[0].sprfls + 4 + (int)pcVar30 * 0x95) == 0) {
            uVar32 = *(undefined2 *)((int)AgntGs[0].sprs + 4 + (int)pcVar30 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 10 + (int)pcVar30 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].sprs + 6 + (int)pcVar30 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 8 + (int)pcVar30 * 0x95) = uVar32;
          }
          else {
            uVar32 = 0x195d;
            pfVar12 = stshSprite((far_t far *)*(undefined2 *)
                                           ((int)AgntGs[0].sprfls + 4 + (int)pcVar30 * 0x95),
                                 *(int16_t *)((int)&AgntGs[0].anms + (int)pcVar30 * 0x95),
                                 (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                           ((int)&AgntGs[0].nanims +
                                                           (int)pcVar30 * 0x95),
                                                          *(undefined2 *)
                                                           ((int)&AgntGs[0].anms + 2 +
                                                           (int)pcVar30 * 0x95)),
                                 CONCAT11((char)((uint)((int)pcVar30 * 0x95) >> 8),(byte)param_1),
                                 (bool)in_stack_0000fffc);
            *(undefined2 *)((int)AgntGs[0].sprs + 10 + (int)pcVar30 * 0x95) = uVar32;
            *(undefined2 *)((int)AgntGs[0].sprs + 8 + (int)pcVar30 * 0x95) =(uint16_t)( pfVar12);
          }
          unaff_DI = (char *)0x0;
        }
        iVar39 = (int)pcVar30 * 0x95 + (int)unaff_DI * 2;
        if (*(int *)((int)AgntGs[0].sprfls + 6 + iVar39) != 0) break;
        iVar39 = (int)pcVar30 * 0x95 + (int)unaff_DI * 4;
        uVar32 = *(undefined2 *)((int)AgntGs[0].sprs + iVar39);
        iVar20 = (int)pcVar30 * 0x95 + (int)unaff_DI * 4;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar20) =
             *(undefined2 *)((int)AgntGs[0].sprs + 2 + iVar39);
        *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar20) = uVar32;
      }
      uVar11 = CONCAT11((char)((uint)iVar39 >> 8),(byte)param_1);
      bVar43 = *(byte *)((int)&AgntGs[0].nanims + (int)pcVar30 * 0x95);
      uVar10 = 0;
      puVar28 = (undefined1 *)((int)pcVar30 * 0x95);
      unaff_SI = *(uint32_t **)(puVar28 + 0x2700);
    } while( true );
  case 2:
    return (agnt_t *)(uVar17 & 0xff8e);
  case 3:
switchD_4000_4790_caseD_3:
    uVar32 = (undefined2)((ulong)Entities >> 0x10);
    cVar6 = *(char *)((int)&(((entity_t *)Entities)->base).flags32 + uVar17);
    cVar8 = (char)(uVar17 >> 8);
    *(char *)((int)&((entity_t *)Entities)[(int)pcVar30].base.state + 1) = cVar6;
    if (EntityCount <= pcVar30 + 1) {
      if ((cVar6 != '\0') || (cVar8 != '\0')) {
        if (bVar44 == 0) {
          ovr_stop_audio();
          CurSfxType3 = 0xff;
          ovr_play_sfx(90);
        }
        else if (cVar8 == '\0') {
          if (cVar6 != '\0') {
            ovr_play_sfx(37);
          }
        }
        else {
          ovr_play_sfx(35);
        }
      }
      GGameState = 0x3d;
      paVar19 = (agnt_t *)0x2410;
      if (DebugVerbose != false) {
        paVar19 = (agnt_t *)0x2410;
        printf("%d \r");
      }
      ovr_OVC23_55fe_29a2_entry();
      return paVar19;
    }
    paVar19 = (agnt_t *)0x24ff;
    ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.");
    return paVar19;
  case 4:
    in_CX = (entity_t *)CONCAT11((char)((uint)in_CX >> 8),(char)in_CX + unaff_DI[-0x63b2]);
    do {
      peVar29 = (entity_t *)(puVar28 + (int)in_CX);
      (peVar29->base).y = uVar17;
      (peVar29->base).x = uVar25;
      while( true ) {
        unaff_DI = unaff_DI + 1;
        pcVar30 = pcVar30 + 1;
L_manage_4d05_2d79_2EE8:
        if ((int)(uint)in_stack_0000fff5 <= (int)pcVar30) {
          cVar6 = '@';
          manage_openTalkWindow();
          if (cVar6 != '\x02') goto L_attact_3f0b_1082_11EA;
          if (ScreenMode == '\0') {
            manage_openTalkWindow();
          }
          TextBlitY = 0xc;
          TextBlitX = 0x11;
          uVar40 = (undefined1)Font02.seg;
          uVar23 = (undefined1)(Font02.seg >> 8);
          uVar10 = (undefined1)Font02.ofs;
          uVar24 = (undefined1)(Font02.ofs >> 8);
          if ((byte)param_1 != 0xff) {
            uVar22 = 0xde;
            uVar41 = 0;
            ovr_ovc45_compute9(acStackY_1b6,(char *)CONCAT22(Font02.seg,unaff_SS),
                               (char *)CONCAT22(Font02.ofs,(char *)0xde),Font02.seg,'K');
            func_0x0005d3f4();
            uVar32 = 0x2410;
            uStackY_2a = 0x23f1;
            uStackY_2c = 0x44;
            pcVar30 = ovr_stsprintf(acStackY_13e,(char *)CONCAT22(0x550a,unaff_SS),
                                    (char *)CONCAT22(*(undefined2 *)
                                                      ((uint)*(byte *)(CONCAT11(uVar23,uVar40) +
                                                                      0x2f) * 4 + 0xeb),
                                                     (char *)0x2410));
            ovr_blitLabel(pcVar30,(uint8_t *)CONCAT13(uVar24,CONCAT12(uVar10,uVar32)));
            TextBlitY = TextBlitY + 0xc;
            iVar39 = ovr_font_textWidth((char *)"UNITS");
            TextBlitX = 0x89 - iVar39;
            ovr_blitLabel((char *)"UNITS",
                          (uint8_t *)
                          CONCAT13((char)(Font02.ofs >> 8),CONCAT12((char)Font02.ofs,0x2410)));
            iVar39 = ovr_font_textWidth((char *)"POPULATION");
            uVar25 = 0xd4 - iVar39;
            TextBlitX = uVar25;
            ovr_blitLabel((char *)"POPULATION",
                          (uint8_t *)
                          CONCAT13((char)(Font02.ofs >> 8),CONCAT12((char)Font02.ofs,0x2410)));
            iVar39 = 0;
            while( true ) {
              TextBlitY = TextBlitY + 0xc;
              cVar6 = (char)in_CX;
              if ((int)(uint)in_stack_0000fff5 <= iVar39) break;
              TextBlitX = 0x11;
              uVar10 = (undefined1)(Font02.ofs >> 8);
              if ((iVar39 < 5) || (in_stack_0000fff4 == 0)) {
                ovr_blitLabel((char *)auStackY_96[iVar39 * 2],
                              (uint8_t *)
                              CONCAT13(uVar10,CONCAT12((char)Font02.ofs,auStackY_96[iVar39 * 2 + 1])
                                      ));
              }
              else {
                uVar16 = (uint)*(byte *)((int)*(undefined4 *)((uint)(byte)param_1 << 2) + 0x2f);
                ovr_blitLabel((char *)auStackY_11a[iVar39 * 2 + uVar16 * 8],
                              (uint8_t *)
                              CONCAT13(uVar10,CONCAT12((char)Font02.ofs,
                                                       auStackY_11a[iVar39 * 2 + uVar16 * 8 + 1])));
              }
              func_0x0005f303();
              ovr_stsprintf(acStackY_13e);
              iVar20 = ovr_font_textWidth(acStackY_13e);
              TextBlitX = 0x89 - iVar20;
              ovr_blitLabel(acStackY_13e,
                            (uint8_t *)
                            CONCAT13((char)(Font02.ofs >> 8),CONCAT12((char)Font02.ofs,unaff_SS)));
              ovr_stsprintf(acStackY_13e);
              iVar20 = ovr_font_textWidth(acStackY_13e);
              uVar25 = 0xd4 - iVar20;
              TextBlitX = uVar25;
              ovr_blitLabel(acStackY_13e,
                            (uint8_t *)
                            CONCAT13((char)(Font02.ofs >> 8),CONCAT12((char)Font02.ofs,unaff_SS)));
              iVar39 = iVar39 + 1;
            }
            CurSfxType3 = 0x3c;
            entries.seg = (uint16_t)unaff_SS;
            entries.ofs = (uint16_t)&eStackY_66;
            uVar32 = ovr_ovc28_usesUiInputText(entries,(uint16_t)unaff_DI);
            cVar8 = (char)uVar32;
            keyboardInputMode = 0;
            if (((cVar8 != '\0') && (cVar8 != '\x01')) && (cVar8 != -2)) {
              (&stack0xbac4)[(int)unaff_DI] = (&stack0xbac4)[(int)unaff_DI] + cVar6;
              iVar20 = 0x2410;
              do {
                iVar21 = iVar20 * uVar25;
                iVar20 = iVar39;
                if (*(byte *)(iVar39 * 0x34 + 0x22) < *(byte *)(iVar21 + 0x21)) {
                  *(undefined1 *)(iVar39 * 0x34 + 0x21) = *(undefined1 *)(iVar39 * 0x34 + 0x22);
                }
                do {
                  iVar20 = iVar20 + 1;
                  if ((int)(uint)AgntCount <= iVar20) {
                    ovr_audio_panFromX((agnt_t *)param_2);
                    ovr_play_sfxU(0x1c);
                    return (agnt_t *)0x1;
                  }
                } while (*(uint16_t *)(iVar20 * 0x34 + 0x1b) != ((agnt_t *)param_2)->owner);
                if (*(byte *)(uVar11 + 0x32) < *(byte *)(iVar20 * 0x34 + 0x22)) {
                  *(undefined1 *)(iVar20 * 0x34 + 0x22) = *(undefined1 *)(uVar11 + 0x32);
                }
                uVar25 = 0x34;
                iVar39 = iVar20;
              } while( true );
            }
            if (cVar8 == -2) {
              Cancelled = 1;
            }
            return (agnt_t *)0x2410;
          }
          uVar16 = ovr_blitLabel((char *)"Total population.",
                                 (uint8_t *)CONCAT13(uVar24,CONCAT12(uVar10,0x2410)));
          *pcVar30 = *pcVar30 + (char)(uVar16 >> 8) + ((undefined1 *)0xfff3 < &stack0xffe8);
          *(undefined1 *)((int)*(undefined4 *)(entity_t **)&Entities + uVar16 + 0x18) = 0;
          uVar17 = (int)pcVar30 * 0x37;
          goto switchD_4000_4790_caseD_3;
        }
        if ((4 < (int)pcVar30) && (in_stack_0000fff4 != 0)) break;
        uVar25 = auStackY_96[(int)pcVar30 * 2];
        in_CX = &eStackY_66;
        peVar29 = (entity_t *)(&(in_CX->base).x + (int)unaff_DI * 2);
        (&eStackY_66.base.y)[(int)unaff_DI * 2] = auStackY_96[(int)pcVar30 * 2 + 1];
        (peVar29->base).x = uVar25;
      }
      uVar34 = (undefined2)((ulong)*(undefined4 *)((uint)(byte)param_1 << 2) >> 0x10);
      uVar16 = (uint)*(byte *)((int)*(undefined4 *)((uint)(byte)param_1 << 2) + 0x2f);
      uVar17 = auStackY_11a[(int)pcVar30 * 2 + uVar16 * 8 + 1];
      uVar25 = auStackY_11a[(int)pcVar30 * 2 + uVar16 * 8];
      puVar28 = (undefined1 *)((int)unaff_DI << 2);
      in_CX = &eStackY_66;
    } while( true );
  case 5:
    puVar1 = (uint *)(&stack0xc1dd + (int)unaff_DI);
    uVar16 = *puVar1;
    *puVar1 = *puVar1 - 1;
    if (in_CX == (entity_t *)0x0) {
      in_stack_0000fff5 =
           (in_NT & 1) * '@' | SBORROW2(uVar16,1) * '\b' | (in_IF & 1) * '\x02' | in_TF & 1;
      in_stack_0000fff4 =
           ((int)*puVar1 < 0) * -0x80 | (*puVar1 == 0) * '@' |
           (9 < (bVar44 & 0xf) | in_AF & 1) * '\x10' |
           ((POPCOUNT(*puVar1 & 0xff) & 1U) == 0) * '\x04';
    }
    (&eStackY_66.base.y)[uVar17] = (uint16_t)((char *)0x2410);
    *(char **)(puVar28 + (int)&eStackY_66) = (char *)"Done";
    (&eStackY_66.base.y)[(int)(unaff_DI + 1) * 2] = (uint16_t)((char *)0x2410);
    (&eStackY_66.base.x)[(int)(unaff_DI + 1) * 2] = (uint16_t)(char *)"Summary";
    peVar29 = (entity_t *)(&eStackY_66.base.x + (int)(unaff_DI + 2) * 2);
    (&eStackY_66.base.y)[(int)(unaff_DI + 2) * 2] = (uint16_t)((char *)0x2410);
    (peVar29->base).x = (uint16_t)(char *)"All levels";
    unaff_DI = unaff_DI + 3;
    pcVar30 = (char *)0x0;
    goto L_manage_4d05_2d79_2EE8;
  }
  if ((uVar17 != 0) || ((uint)(*(uint16_t *)((uint8_t *)&(BuildingTypes[0x76]) + 24)) < 0x195d)) {
    uVar16 = (((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
              (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
             (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
    if ((uVar16 < CONCAT11(in_stack_0000fff3,in_stack_0000fff2)) ||
       ((uVar16 <= CONCAT11(in_stack_0000fff3,in_stack_0000fff2) &&
        (((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0] <=
         CONCAT11(in_stack_0000fff1,in_stack_0000fff0))))) {
      unaff_SI = (uint32_t *)
                 ((((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                   (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                 (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]));
    }
    else {
      unaff_SI = (uint32_t *)CONCAT11(in_stack_0000fff3,in_stack_0000fff2);
    }
    uVar23 = SUB21(unaff_SI,0);
    uVar22 = (undefined1)((uint)unaff_SI >> 8);
    dstSeg = (uint)StshPtrs[0] - (uint)FMXmsHandle;
    uVar17 = ((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) - (uint)((uint)StshPtrs[0] < (uint)FMXmsHandle)
    ;
    uVar24 = uVar23;
    uVar40 = uVar22;
    uVar25 = dstSeg;
    puVar18 = ovr_mkp(puVar33);
    ems_memmove1((uint16_t)puVar18,dstSeg,uVar25,uVar17,CONCAT11(uVar22,uVar23),
                 CONCAT11(uVar40,uVar24));
    bVar36 = CARRY2((uint)StshPtrs[0],CONCAT11(uVar40,uVar24));
    (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + CONCAT11(uVar40,uVar24);
    (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (int)unaff_SI + bVar36 + (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2));
    uVar16 = uVar17 - CONCAT11(uVar40,uVar24);
    bVar44 = 0;
    in_stack_0000fff2 = 0xcb;
    in_stack_0000fff3 = 0x77;
    puVar18 = LXURSH_at_(unaff_SI,CONCAT22(uVar11,CONCAT11(uVar10,bVar43)),in_stack_0000fffc);
    param_2 = (agnt_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(param_2) + 2)),(agnt_t *)((int)puVar18 + (int)(agnt_t *)param_2));
    param_1 = CONCAT22((int)puVar33 + (bVar44 & 0xf),uVar27);
  }
  uVar27 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) + (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)
  ;
  if ((uVar27 <= (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) &&
     ((uVar27 != (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) || ((uint)FMXmsHandle + (uint)FMEmsHandle <= (uint)StshPtrs[0])))
     ) {
    in_stack_0000fff2 = (undefined1)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2));
    in_stack_0000fff3 = (undefined1)((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) >> 8);
    uVar10 = (undefined1)(uint)StshPtrs[0];
    uVar24 = (undefined1)((uint)StshPtrs[0] >> 8);
    lseek(StshHandles[0],(ulong)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)),(int)unaff_SI);
    uVar16 = CONCAT11(uVar24,uVar10);
  }
  puVar33 = (uint32_t *)CONCAT11(in_stack_0000fff3,in_stack_0000fff2);
  if (uVar16 == 0 && puVar33 == (uint32_t *)0x0) {
    paVar19 = (agnt_t *)((uint)bVar43 - (*(uint16_t *)((uint8_t *)&(param_2) + 2)));
  }
  else {
    uVar40 = SUB41(param_2,0);
    uVar23 = (undefined1)((ulong)param_2 >> 8);
    uVar10 = (char)StshHandles[0];
    uVar24 = (char)((uint)StshHandles[0] >> 8);
    while( true ) {
      if ((puVar33 == (uint32_t *)0x0) && (uVar16 == 0)) goto next_iteration;
      if ((puVar33 != (uint32_t *)0x0) || (0xc000 < uVar16)) {
        uVar16 = 0xc000;
      }
      iVar39 = 0x7888;
      uVar22 = uVar10;
      uVar41 = uVar24;
      uVar27 = read(CONCAT11(uVar24,uVar10),
                    (void *)CONCAT13((char)(uVar16 >> 8),
                                     CONCAT12((char)uVar16,CONCAT11(uVar23,uVar40))),(uint)unaff_SI)
      ;
      if (uVar27 != CONCAT11(uVar24,uVar10)) break;
      puVar33 = (uint32_t *)(iVar39 + uVar27);
      uVar10 = 0;
      uVar24 = 0x10;
      ovr_mkp(puVar33);
      uVar16 = CONCAT11(uVar24,uVar10);
      uVar40 = (undefined1)(*(uint16_t *)((uint8_t *)&(param_1) + 2));
      uVar23 = (undefined1)((uint)(*(uint16_t *)((uint8_t *)&(param_1) + 2)) >> 8);
      bVar36 = CARRY2((uint)StshPtrs[0],uVar27);
      (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + uVar27;
      (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + bVar36;
      uVar10 = uVar22;
      uVar24 = uVar41;
    }
    printf((char *)((long)&BldInstances[0x49].seg + 1));
    ovr_biosReadKey();
next_iteration:
    paVar19 = (agnt_t *)((uint)bVar43 - (*(uint16_t *)((uint8_t *)&(param_2) + 2)));
  }
  return paVar19;
L_attact_3f0b_1082_11EA:
  uVar32 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
  peVar26 = (entity_t *)in_stack_0000ffe2;
  (peVar26->base).target =
       (byte)((int)(uint)*(byte *)((int)&(peVar26->base).owner +
                                  ((int)(uint)(peVar29->base).faction >> 2)) >>
             (((peVar26->base).faction & 3) << 1)) & 3;
  cVar6 = func_0x0004f32d();
  peVar29 = (entity_t *)in_stack_0000ffe2;
  uVar32 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
  if (cVar6 == '\0') {
    (in_stack_0000ffe2->base).x =
         (in_stack_0000ffe2->base).x + (int)*(char *)((peVar29->base).target + 0x885);
    puVar2 = &(peVar29->base).y;
    *puVar2 = *puVar2 + (int)*(char *)((peVar29->base).target + 0x889);
    puVar3 = &(peVar29->base).faction;
    *puVar3 = *puVar3 + 0x1;
  }
  else {
    (peVar29->base).faction = 0x0;
    *(undefined1 *)&(peVar29->base).state = 0;
  }
L_attact_3f0b_1082_1477:
  do {
    uVar37 = 0x1000000;
    uVar16 = ovr_alignUp4((((entity_t *)in_stack_0000ffe2)->base).destX);
    uVar24 = (undefined1)uVar16;
    uVar40 = (undefined1)(uVar16 >> 8);
    uVar16 = ovr_alignUp4((in_stack_0000ffe2->base).x);
    if (CONCAT11(uVar40,uVar24) == uVar16) {
      uVar32 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      peVar29 = (entity_t *)in_stack_0000ffe2;
      if ((peVar29->base).destY == (peVar29->base).y) {
        (peVar29->base).destX = 0;
        (peVar29->base).destY = 0;
        if (*(char *)((int)&(peVar29->base).entity + 3) == -1) {
          bVar44 = 0xff;
        }
        else {
          uVar4 = *(undefined4 *)((uint)*(byte *)((int)&(peVar29->base).entity + 3) << 2);
          bVar44 = *(byte *)((int)uVar4 + 0x89);
        }
        if (bVar44 != 0xff) {
          for (uVar16 = 0; uVar16 < SquareRecCount; uVar16 = uVar16 + 1) {
            uVar27 = ovr_alignUp4(*(int *)(uVar16 * 0x13));
            uVar24 = (undefined1)uVar27;
            uVar40 = (undefined1)(uVar27 >> 8);
            uVar27 = ovr_alignUp4((in_stack_0000ffe2->base).x);
            if ((CONCAT11(uVar40,uVar24) == uVar27) &&
               (*(uint16_t *)((uint8_t *)&SquareRecs[uVar16] + 2) == (((entity_t *)in_stack_0000ffe2)->base).y)) {
              func_0x0004f930();
              if (*(uint16_t *)((uint8_t *)&SquareRecs[uVar16] + 2) == GfxRndSeed2) {
                uVar16 = ovr_alignUp4(*(int *)(uVar16 * 0x13));
                uVar24 = (undefined1)uVar16;
                uVar40 = (undefined1)(uVar16 >> 8);
                uVar16 = ovr_alignUp4(GfxRndSeed);
                if (CONCAT11(uVar40,uVar24) == uVar16) {
                  (&stack0xfff2)[bVar44] = 1;
                }
              }
              break;
            }
          }
        }
      }
    }
    uVar5 = 0x23;
    if (AgntFlag1 != false) {
      uVar32 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      if ((((in_stack_0000ffe2->base).x < GfxRndSeed - 2U) ||
          (GfxRndSeed + 1U < (in_stack_0000ffe2->base).x)) ||
         ((((entity_t *)in_stack_0000ffe2)->base).y != GfxRndSeed2)) {
        bVar36 = false;
      }
      else {
        bVar36 = true;
      }
      if (((uVar11 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uVar11)) ||
         (GfxRndSeed2 != CONCAT11(uVar10,bVar43))) {
        bVar9 = false;
      }
      else {
        bVar9 = true;
      }
      uVar37 = uVar37 & 0xff000000;
      if (bVar9 || bVar36) {
        if (bVar9) {
          if (bVar36) {
            uVar10 = func_0x0004f944();
            for (uVar37 = CONCAT31((int3)(uVar37 >> 8),uVar10); uVar5 = 0x23, (char)uVar37 != '\0';
                uVar37 = CONCAT31((int3)(uVar37 >> 8),(char)uVar37 + -1)) {
              uVar5 = 0x23;
              pcVar30 = ovr_ovc15_textArena((int)unaff_DI);
              if (((uint)pcVar30 & 0xff) == 0) break;
            }
          }
          else {
            uVar37 = CONCAT31((int3)(uVar37 >> 8),
                              (char)((ulong)((((entity_t *)in_stack_0000ffe2)->base).animFrame + 0xf
                                            ) / 0x10));
            while (cVar6 = (char)uVar37, uVar37 = CONCAT31((int3)(uVar37 >> 8),cVar6 + -1),
                  cVar6 != '\0') {
              uVar5 = 0x22;
              ovr_agnt_usesAgntCount6(Entities + (int)unaff_DI);
            }
          }
        }
        else {
          ovr_ovc15_clearVisited();
          uVar37 = CONCAT31((int3)(uVar37 >> 8),
                            (char)((ulong)((((entity_t *)in_stack_0000ffe2)->base).animFrame + 0xf)
                                  / 0x10));
          while( true ) {
            uVar5 = 0x23;
            cVar6 = (char)uVar37;
            uVar37 = CONCAT31((int3)(uVar37 >> 8),cVar6 + -1);
            if (cVar6 == '\0') break;
            ovr_ovc15_textArena((int)unaff_DI);
          }
        }
      }
    }
    do {
      uVar38 = (uint8_t)(uVar37 >> 0x18);
      unaff_DI = unaff_DI + 1;
      if (EntityCount <= unaff_DI) {
        GGameState = 0x3c;
        uVar35 = uVar5;
        if (DebugVerbose != false) {
          uVar35 = 0x10;
          uVar38 = uVar5;
          printf("%d %d %d  \r");
        }
        func_0x0004fcda();
        GGameState = 0x3d;
        if (DebugVerbose != false) {
          uVar38 = uVar35;
          printf("%d %d %d  \r");
        }
        ovr_OVC23_55fe_29a2_entry();
        GGameState = 0xc;
        if (DebugVerbose != false) {
          uVar38 = 0x23;
          printf("%d %d %d  \r");
        }
        ovr_ovc24_removeOtherEntities(&stack0xffe9);
        GGameState = 0x1f;
        if (uVar38 != 0x0) {
          ovr_constr_usesBlitRect();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (uVar16 = 0; (int)uVar16 < 5; uVar16 = uVar16 + 1) {
          if ((&stack0xfff2)[uVar16] != '\0') {
            ovr_ovc41_usesMiceBlitRect(uVar16);
          }
        }
        GGameState = 0xd;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        ovr_ovc24_checkStrongholds();
        GGameState = 0xe;
        mapDirty = 1;
        return (agnt_t *)0x2410;
      }
      uVar32 = (undefined2)((ulong)Entities >> 0x10);
      in_stack_0000ffe2 = (entity_t *)CONCAT22(uVar32,Entities + (int)unaff_DI);
      uVar16 = ovr_alignUp4(Entities[(int)unaff_DI].base.destX);
      uVar10 = (undefined1)uVar16;
      uVar24 = (undefined1)(uVar16 >> 8);
      uVar5 = 0x23;
      uVar16 = ovr_alignUp4((in_stack_0000ffe2->base).x);
      if ((CONCAT11(uVar24,uVar10) == uVar16) &&
         (uVar32 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10),
         (((entity_t *)in_stack_0000ffe2)->base).destY == (((entity_t *)in_stack_0000ffe2)->base).y)
         ) {
        uVar37 = 0x23790204;
        func_0x0004fb8e();
      }
      uVar34 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      peVar29 = (entity_t *)in_stack_0000ffe2;
    } while (((peVar29->base).destX == 0 && (peVar29->base).destY == 0) ||
            (*(char *)((int)&(peVar29->base).entity + 1) != '\0'));
    uVar11 = (in_stack_0000ffe2->base).x;
    uVar25 = (peVar29->base).y;
    bVar44 = (byte)uVar25;
    uVar24 = (undefined1)(uVar25 >> 8);
    bVar43 = bVar44;
    uVar10 = uVar24;
    if ((peVar29->base).faction < (byte)(peVar29->base).state) goto L_attact_3f0b_1082_11EA;
    ovr_ovc07_signum((peVar29->base).destX - (in_stack_0000ffe2->base).x);
    uVar32 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
    cVar6 = 'g';
    uVar23 = 3;
    uVar25 = ovr_ovc07_signum((((entity_t *)in_stack_0000ffe2)->base).destY -
                              (((entity_t *)in_stack_0000ffe2)->base).y);
    bVar7 = (byte)uVar25;
    uVar40 = (undefined1)(uVar25 >> 8);
    if (CONCAT11(uVar23,cVar6) == 0) {
L_attact_3f0b_1082_130A:
      bVar43 = bVar44;
      uVar10 = uVar24;
      if (CONCAT11(uVar40,bVar7) != 0) {
        uVar23 = (undefined1)(uVar25 >> 8);
        cVar6 = bVar7 + 1;
        bVar7 = func_0x0004f412();
        uVar25 = (uint16_t)bVar7;
        if (uVar25 == 0) {
          uVar32 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
          puVar2 = &(((entity_t *)in_stack_0000ffe2)->base).y;
          *puVar2 = *puVar2 + CONCAT11(uVar24,bVar44);
          (((entity_t *)in_stack_0000ffe2)->base).target = bVar44 + 1;
          goto L_attact_3f0b_1082_1477;
        }
      }
      if (CONCAT11(uVar23,cVar6) != 0) {
        uVar24 = (undefined1)(uVar25 >> 8);
        cVar6 = '\x02' - cVar6;
        cVar8 = func_0x0004f412();
        if (cVar8 == '\0') {
          (in_stack_0000ffe2->base).x = (in_stack_0000ffe2->base).x + CONCAT11(uVar24,cVar6);
          (((entity_t *)in_stack_0000ffe2)->base).target = 0x2 - cVar6;
          goto L_attact_3f0b_1082_1477;
        }
      }
      uVar16 = ovr_ovc26_usesStExit((int)unaff_DI);
      if ((char)uVar16 == '\0') {
        uVar16 = ovr_ovc26_usesRandBelow((int)unaff_DI);
        if (((uVar16 & 0xff) == 0) &&
           (*(char *)((int)(char **)GMenuStrings +
                     (uint)(((entity_t *)in_stack_0000ffe2)->base).gindex * 0x95 + 0x1f) == '\0')) {
          func_0x0004fb8e();
        }
      }
      else {
        uVar32 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
        peVar29 = (entity_t *)in_stack_0000ffe2;
        (peVar29->base).target =
             (byte)((int)(uint)*(byte *)((int)&(peVar29->base).owner +
                                        ((int)(uint)(peVar29->base).faction >> 2)) >>
                   (((peVar29->base).faction & 3) << 1)) & 3;
        cVar6 = func_0x0004f32d();
        if (cVar6 == '\0') {
          uVar32 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
          peVar29 = (entity_t *)in_stack_0000ffe2;
          (in_stack_0000ffe2->base).x =
               (in_stack_0000ffe2->base).x + (int)*(char *)((peVar29->base).target + 0x885);
          puVar2 = &(peVar29->base).y;
          *puVar2 = *puVar2 + (int)*(char *)((peVar29->base).target + 0x889);
          puVar3 = &(peVar29->base).faction;
          *puVar3 = *puVar3 + 0x1;
        }
      }
      goto L_attact_3f0b_1082_1477;
    }
    cVar6 = 'z';
    uVar23 = 3;
    uVar25 = ovr_randBelow(2);
    uVar22 = (undefined1)(uVar25 >> 8);
    if ((char)uVar25 == '\0') goto L_attact_3f0b_1082_130A;
    cVar6 = '\x02' - cVar6;
    bVar43 = bVar44;
    uVar10 = uVar24;
    bVar7 = func_0x0004f412();
    uVar25 = (uint16_t)bVar7;
    bVar7 = bVar44;
    uVar40 = uVar24;
    uVar23 = uVar22;
    bVar44 = bVar43;
    uVar24 = uVar10;
    if (uVar25 != 0) goto L_attact_3f0b_1082_130A;
    (in_stack_0000ffe2->base).x = (in_stack_0000ffe2->base).x + CONCAT11(uVar22,cVar6);
    (((entity_t *)in_stack_0000ffe2)->base).target = 0x2 - cVar6;
  } while( true );
}
