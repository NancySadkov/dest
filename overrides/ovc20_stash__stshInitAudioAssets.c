void __cdecl16far stshInitAudioAssets(char grab,...)

{
  char *pcVar1;
  long *plVar2;
  uint16_t freq;
  uint32_t *puVar3;
  int iVar4;
  void *pvVar5;
  uint16_t file_id;
  cte_t *pcVar6;
  far_t *pfVar7;
  uint uVar8;
  uint uVar9;
  int in_DX;
  int iVar10;
  undefined2 *puVar11;
  uint uVar12;
  undefined2 unaff_SI;
  uint16_t i;
  far_t *unaff_DI;
  undefined2 uVar13;
  bool bVar14;
  uint8_t uVar15;
  undefined1 uVar16;
  voc_t voc;
  uint uStack_a;
  uint uStack_8;
  uint32_t sz;
  
  AudioAssetsReady1 = 1;
  AudioAssetsReady2 = 1;
  uStack_8 = 0;
  uStack_a = 0;
  i = 0;
  do {
                    /* ;0x90 = total .xmi and .voc files */
    if (0x89 < (int)i) {
      return;
    }
    puVar11 = (undefined2 *)(*(int *)(i * 2) * 4);
    pcVar1 = _fstrstr((char *)CONCAT22(puVar11[1],(char *)*puVar11),".xmi");
    if (pcVar1 == (char *)0x0 && in_DX == 0) {
      *(undefined2 *)(&AudioHandles[i]) = 1;
    }
    else {
      *(undefined2 *)(&AudioHandles[i]) = 0;
    }
    if (grab == '\0') {
      pfVar7 = ovr_stshAllocStub(unaff_DI);
      ((undefined2 *)(i * 4))[1] = in_DX;
      *(undefined2 *)(i * 4) =(uint16_t)( pfVar7);
      iVar10 = in_DX;
    }
    else {
      if (*(int *)(&AudioHandles[i]) == 0) {
        puVar3 = ovr_stshFilesize((uint32_t *)*(undefined2 *)(i * 2),(uint16_t)unaff_DI);
        iVar10 = (int)puVar3 + 0xd;
        iVar4 = in_DX + (uint)((uint32_t *)0xfff2 < puVar3);
        pvVar5 = ovr_stshAlloc(CONCAT13((char)((uint)iVar4 >> 8),CONCAT12((char)iVar4,iVar10)));
        ((undefined2 *)(i * 4))[1] = iVar10;
        *(undefined2 *)(i * 4) =(uint16_t)( pvVar5);
        *(undefined1 *)*(undefined4 *)(i << 2) = 3;
        uVar13 = (undefined2)((ulong)*(undefined4 *)(i << 2) >> 0x10);
        iVar4 = (int)*(undefined4 *)(i << 2);
        *(undefined2 *)(iVar4 + 3) = 0;
        *(undefined2 *)(iVar4 + 1) = 0;
        *(undefined2 *)((int)*(undefined4 *)(i << 2) + 5) =(uint16_t)( puVar3);
        file_id = ovr_stshOpen(*(uint16_t *)(i * 2));
        iVar4 = ovr_stshRead();
        if (iVar4 != 0 || iVar10 != 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x20);
        }
        *(undefined2 *)((int)*(undefined4 *)(i << 2) + 0xb) = 0;
      }
      else {
        file_id = ovr_stshOpen(*(uint16_t *)(i * 2));
        iVar10 = ovr_stshRead();
        if (iVar10 != 0 || in_DX != 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x20);
        }
        uVar16 = 0;
        iVar4 = 0;
        iVar10 = 0;
        uVar15 = voc.blksz[0];
        plVar2 = LXLSH_at_((long *)0x0,CONCAT22(unaff_DI,(uint)voc.blksz[0]),(byte)unaff_SI);
        uVar8 = CONCAT11(uVar16,uVar15) + (int)plVar2;
        uVar9 = uVar8 - 2;
        uVar12 = (iVar4 + iVar10 + (uint)CARRY2(CONCAT11(uVar16,uVar15),(uint)plVar2) +
                 (uint)voc.blksz[2]) - (uint)(uVar8 < 2);
        iVar4 = uVar8 + 0xb;
        iVar10 = uVar12 + (0xfff2 < uVar9);
        pvVar5 = ovr_stshAlloc(CONCAT13((char)((uint)iVar10 >> 8),CONCAT12((char)iVar10,iVar4)));
        ((undefined2 *)(i * 4))[1] = iVar4;
        *(undefined2 *)(i * 4) =(uint16_t)( pvVar5);
        *(undefined1 *)*(undefined4 *)(i << 2) = 3;
        uVar13 = (undefined2)((ulong)*(undefined4 *)(i << 2) >> 0x10);
        iVar10 = (int)*(undefined4 *)(i << 2);
        *(undefined2 *)(iVar10 + 3) = 0;
        *(undefined2 *)(iVar10 + 1) = 0;
        *(uint *)((int)*(undefined4 *)(i << 2) + 5) = uVar9;
        if ((uStack_8 <= uVar12) && ((uVar12 != uStack_8 || (uStack_a <= uVar9)))) {
          bVar14 = 0xfff2 < uVar9;
          uVar9 = uVar8 + 0xb;
          uStack_8 = uVar12 + bVar14;
          uStack_a = uVar9;
        }
        iVar10 = ovr_stshRead();
        if (iVar10 != 0 || uVar9 != 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x20);
        }
        freq = stshDecVocSampleRate(voc.freq);
        iVar10 = 0x1703;
        *(uint16_t *)((int)*(undefined4 *)(i << 2) + 0xb) = freq;
      }
      ovr_stshClose(file_id);
      pcVar6 = stshStoreFile((uint8_t *)*(undefined2 *)(i * 4),(char)((undefined2 *)(i * 4))[1]);
      ((undefined2 *)(i * 4))[1] = iVar10;
      *(undefined2 *)(i * 4) =(uint16_t)( pcVar6);
    }
    i = i + 1;
    in_DX = iVar10;
  } while( true );
}
