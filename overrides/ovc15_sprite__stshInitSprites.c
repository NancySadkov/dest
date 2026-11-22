void __cdecl16far stshInitSprites(bool grab,...)

{
  undefined2 in_AX;
  far_t far *pfVar1;
  int iVar2;
  int iVar3;
  stg_tmp_t *gfx;
  cte_t *pcVar4;
  uint32_t *puVar5;
  uint16_t in_DX;
  undefined2 uVar6;
  uint8_t *puVar7;
  uint8_t *puVar8;
  undefined2 uVar9;
  uint16_t i;
  far_t far *unaff_DI;
  int iVar10;
  uint16_t j;
  far_t pixels;
  long sz;
  
  StshSprIndex = 0;
  pfVar1 = stshSprite((far_t *)((byte *)__C0_ASM_CopyRight + 0x21),0,(anm_t *)0x9195d,
                      CONCAT11((char)((uint)in_AX >> 8),grab),SUB21(unaff_DI,0));
  SprProjectiles.ofs = (uint16_t)pfVar1;
  SprProjectiles.seg = in_DX;
  for (i = 0; (int)i < 0x2a; i = i + 1) {
    uVar6 = 0x195d;
    pfVar1 = stshSprite((far_t *)*(undefined2 *)((int)AgntGs[0].sprfls + i * 0x95),
                        *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                        (anm_t *)(ulong)CONCAT12(*(undefined1 *)((int)&AgntGs[0].nanims + i * 0x95),
                                                 *(undefined2 *)
                                                  ((int)&AgntGs[0].anms + 2 + i * 0x95)),
                        CONCAT11((char)((uint)pfVar1 >> 8),grab),SUB21(unaff_DI,0));
    *(undefined2 *)((int)AgntGs[0].sprs + 2 + i * 0x95) = uVar6;
    *(undefined2 *)((int)AgntGs[0].sprs + i * 0x95) =(uint16_t)( pfVar1);
    if (*(int *)((int)AgntGs[0].sprfls + 2 + i * 0x95) == 0) {
      uVar6 = *(undefined2 *)((int)AgntGs[0].sprs + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 6 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].sprs + 2 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 4 + i * 0x95) = uVar6;
    }
    else {
      uVar6 = 0x195d;
      pfVar1 = stshSprite((far_t *)*(undefined2 *)((int)AgntGs[0].sprfls + 2 + i * 0x95),
                          *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                          (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                    ((int)&AgntGs[0].nanims + i * 0x95),
                                                   *(undefined2 *)
                                                    ((int)&AgntGs[0].anms + 2 + i * 0x95)),
                          CONCAT11((char)(i * 0x95 >> 8),grab),SUB21(unaff_DI,0));
      *(undefined2 *)((int)AgntGs[0].sprs + 6 + i * 0x95) = uVar6;
      *(undefined2 *)((int)AgntGs[0].sprs + 4 + i * 0x95) =(uint16_t)( pfVar1);
    }
    if (*(int *)((int)AgntGs[0].sprfls + 4 + i * 0x95) == 0) {
      uVar6 = *(undefined2 *)((int)AgntGs[0].sprs + 4 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 10 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].sprs + 6 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 8 + i * 0x95) = uVar6;
    }
    else {
      uVar6 = 0x195d;
      pfVar1 = stshSprite((far_t *)*(undefined2 *)((int)AgntGs[0].sprfls + 4 + i * 0x95),
                          *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                          (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                    ((int)&AgntGs[0].nanims + i * 0x95),
                                                   *(undefined2 *)
                                                    ((int)&AgntGs[0].anms + 2 + i * 0x95)),
                          CONCAT11((char)(i * 0x95 >> 8),grab),SUB21(unaff_DI,0));
      *(undefined2 *)((int)AgntGs[0].sprs + 10 + i * 0x95) = uVar6;
      *(undefined2 *)((int)AgntGs[0].sprs + 8 + i * 0x95) =(uint16_t)( pfVar1);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      iVar2 = i * 0x95 + iVar10 * 2;
      if (*(int *)((int)AgntGs[0].sprfls + 6 + iVar2) == 0) {
        iVar2 = i * 0x95 + iVar10 * 4;
        uVar6 = *(undefined2 *)((int)AgntGs[0].sprs + iVar2);
        iVar3 = i * 0x95 + iVar10 * 4;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar3) =
             *(undefined2 *)((int)AgntGs[0].sprs + 2 + iVar2);
        *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar3) = uVar6;
      }
      else {
        uVar6 = 0x195d;
        pfVar1 = stshSprite((far_t *)*(undefined2 *)
                                      ((int)AgntGs[0].sprfls + 6 + i * 0x95 + iVar10 * 2),
                            *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                            (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                      ((int)&AgntGs[0].nanims + i * 0x95),
                                                     *(undefined2 *)
                                                      ((int)&AgntGs[0].anms + 2 + i * 0x95)),
                            CONCAT11((char)((uint)iVar2 >> 8),grab),SUB21(unaff_DI,0));
        iVar2 = i * 0x95 + iVar10 * 4;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar2) = uVar6;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar2) =(uint16_t)( pfVar1);
      }
    }
    for (j = 0; (int)j < 6; j = j + 1) {
      uVar6 = 0x195d;
      if (*(int *)((int)AgntGs[0].prtfls + i * 0x95 + j * 2) != 0) {
        if (grab) {
          puVar7 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
          gfx = ovr_grabLbm(*(int16_t *)((int)AgntGs[0].prtfls + i * 0x95 + j * 2),0,0);
          puVar8 = puVar7;
          ovr_stshUniqueColorsRemap(gfx,puVar7);
          pixels.seg = 0;
          pixels.ofs = (gfx->aptr).seg;
          pfVar1 = ovr_stshRleType2((far_t far *)(&gfx->aptr)->ofs,pixels,0,114,103,0,0,
                                    (int16_t)unaff_DI);
          pcVar4 = ovr_stshStoreFile((uint8_t *)pfVar1,puVar8);
          iVar10 = i * 0x95 + j * 4;
          uVar6 = 0x195d;
          *(int *)((int)AgntGs[0].prts + 2 + iVar10) = (int)puVar8;
          *(undefined2 *)((int)AgntGs[0].prts + iVar10) =(uint16_t)( pcVar4);
          sz = ZEXT24(unaff_DI) << 0x10;
          puVar5 = ovr_stshWrite((uint32_t *)gfx,(uint8_t *)CONCAT22(0x300,puVar7),sz);
          unaff_DI = (far_t far *)((ulong)sz >> 0x10);
          iVar10 = i * 0x95 + j * 4;
          *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar10) = uVar6;
          *(undefined2 *)((int)AgntGs[0].prtpals + iVar10) =(uint16_t)( puVar5);
          ovr_stgFreeTmp(gfx,puVar7);
        }
        else {
          pfVar1 = ovr_stshAllocStub(unaff_DI);
          iVar10 = i * 0x95 + j * 4;
          uVar9 = 0x195d;
          *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar10) = uVar6;
          *(undefined2 *)((int)AgntGs[0].prts + iVar10) =(uint16_t)( pfVar1);
          pfVar1 = ovr_stshAllocStub(unaff_DI);
          iVar10 = i * 0x95 + j * 4;
          *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar10) = uVar9;
          *(undefined2 *)((int)AgntGs[0].prtpals + iVar10) =(uint16_t)( pfVar1);
        }
      }
    }
    pfVar1 = (far_t far *)(*(uint *)((int)AgntGs[0].prts + 4 + i * 0x95) |
                      *(uint *)((int)AgntGs[0].prts + 6 + i * 0x95));
    if ((pfVar1 == (far_t far *)0x0) &&
       (pfVar1 = (far_t far *)0x0,
       *(int *)((int)AgntGs[0].prts + i * 0x95) != 0 ||
       *(int *)((int)AgntGs[0].prts + 2 + i * 0x95) != 0)) {
      uVar6 = *(undefined2 *)((int)AgntGs[0].prts + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prts + 6 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].prts + 2 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prts + 4 + i * 0x95) = uVar6;
      pfVar1 = (far_t far *)*(undefined2 *)((int)AgntGs[0].prtpals + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prtpals + 6 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].prtpals + 2 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prtpals + 4 + i * 0x95) =(uint16_t)( pfVar1);
    }
    for (iVar10 = 2; iVar10 < 6; iVar10 = iVar10 + 2) {
      iVar2 = i * 0x95 + iVar10 * 4;
      if ((*(int *)((int)AgntGs[0].prts + 4 + iVar2) == 0 &&
           *(int *)((int)AgntGs[0].prts + 6 + iVar2) == 0) &&
         (iVar2 = i * 0x95 + iVar10 * 4,
         *(int *)((int)AgntGs[0].prtfls + 8 + iVar2) != 0 ||
         *(int *)((int)AgntGs[0].prtfls + 10 + iVar2) != 0)) {
        iVar2 = i * 0x95 + iVar10 * 4;
        uVar6 = *(undefined2 *)((int)AgntGs[0].prtfls + 8 + iVar2);
        iVar3 = i * 0x95 + iVar10 * 4;
        *(undefined2 *)((int)AgntGs[0].prts + 6 + iVar3) =
             *(undefined2 *)((int)AgntGs[0].prtfls + 10 + iVar2);
        *(undefined2 *)((int)AgntGs[0].prts + 4 + iVar3) = uVar6;
        iVar2 = i * 0x95 + iVar10 * 4;
        uVar6 = *(undefined2 *)((int)AgntGs[0].prts + 0x14 + iVar2);
        iVar3 = i * 0x95 + iVar10 * 4;
        *(undefined2 *)((int)AgntGs[0].prtpals + 6 + iVar3) =
             *(undefined2 *)((int)AgntGs[0].prts + 0x16 + iVar2);
        *(undefined2 *)((int)AgntGs[0].prtpals + 4 + iVar3) = uVar6;
      }
      iVar2 = i * 0x95 + iVar10 * 4;
      pfVar1 = (far_t far *)(*(uint *)((int)AgntGs[0].prts + iVar2) |
                        *(uint *)((int)AgntGs[0].prts + 2 + iVar2));
      if (pfVar1 == (far_t far *)0x0) {
        iVar2 = i * 0x95 + iVar10 * 4;
        if (*(int *)((int)AgntGs[0].prtfls + 4 + iVar2) == 0 &&
            *(int *)((int)AgntGs[0].prtfls + 6 + iVar2) == 0) {
          pfVar1 = (far_t far *)0x0;
        }
        else {
          iVar2 = i * 0x95 + iVar10 * 4;
          uVar6 = *(undefined2 *)((int)AgntGs[0].prtfls + 4 + iVar2);
          iVar3 = i * 0x95 + iVar10 * 4;
          *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar3) =
               *(undefined2 *)((int)AgntGs[0].prtfls + 6 + iVar2);
          *(undefined2 *)((int)AgntGs[0].prts + iVar3) = uVar6;
          iVar2 = i * 0x95 + iVar10 * 4;
          pfVar1 = (far_t far *)*(undefined2 *)((int)AgntGs[0].prts + 0x10 + iVar2);
          iVar3 = i * 0x95 + iVar10 * 4;
          *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar3) =
               *(undefined2 *)((int)AgntGs[0].prts + 0x12 + iVar2);
          *(undefined2 *)((int)AgntGs[0].prtpals + iVar3) =(uint16_t)( pfVar1);
        }
      }
    }
  }
  return;
}
