byte * __cdecl16far uiMainMenuLoop(long param_1,byte *param_2,uint param_3,uint param_4)

{
  far_t items;
  char cVar1;
  uint16_t uVar2;
  uint8_t *pmenu;
  byte *pbVar3;
  undefined2 uVar4;
  byte *pbVar5;
  int *piVar6;
  byte *pbVar7;
  uint uVar8;
  int unaff_DI = 0;
  static undefined2 stack0x02c2[64];
  union { unsigned u; byte *p; } cv;
  uint16_t unaff_SS;
  bool bVar9;
  void *pvVar10;
  far_t fVar11;
  uint8_t menu [4];
  char *pcStack_30;
  char *pcStack_2e;
  byte *pbStack_28;
  char *pcStack_18;
  char *pcStack_16;
  byte bStack_13;
  uint8_t yesno [4];
  char cStack_e;
  char cStack_d;
  far_t fStack_8;
  undefined2 uStack_4;
  
  pbVar3 = (byte *)unaff_DI;
  F_SCOPY(menu,(uint8_t *)(char **)GMenuStrings,0x20);
  uVar4 = 8;
  F_SCOPY(yesno,(uint8_t *)(char **)GYesNo,8);
  ovr_say("Stronghold V 1.00");
  fVar11.seg = DAT_2000_d1a1;
  fVar11.ofs = DAT_2000_d19f;
  ovr_blitLoadRleGfx(fVar11,far_from_u32((uint32_t)(0xa00009af)));
  ovr_stats_6386_00f8();
  saveui_4528_0533();
  fStack_8 = ovr_stshAlloc(400);
  _fsetmem((void *)MK_FP(fStack_8.seg, fStack_8.ofs),400,0);
  pbVar7 = (byte *)0x0;
  uStack_4 = 0;
  while( true ) {
    if (SaveAuto == '\0') {
      pcStack_2e = (char *)0x0;
      pcStack_30 = (char *)0x0;
    }
    else {
      pcStack_2e = (char *)"puppetmaker" + 3;
      pcStack_30 = (char *)"Save Game";
    }
    if ((DAT_2000_ca90 == '\0') && (SaveAuto != '\0')) {
      pcStack_16 = (char *)"puppetmaker" + 3;
      pcStack_18 = (char *)"Begin Play";
    }
    else {
      pcStack_16 = (char *)0x0;
      pcStack_18 = (char *)0x0;
    }
    pmenu = menu;
    items.seg = unaff_SS;
    items.ofs = (uint16_t)pmenu;
    uiMenu("Select an option:",items,8);
    bStack_13 = (byte)pmenu;
    ovr_say("");
    uVar8 = (uint)bStack_13;
    if (uVar8 < 9) break;
    if ((SaveAuto != '\0') && ((char)uStack_4 != '\0')) {
      saveui_4528_1288();
      ovr_stshFree(fStack_8);
      pbVar3 = (byte *)ovr_OVC28_6018_0251();
      return pbVar3;
    }
  }
  pbVar5 = (byte *)(uVar8 * 2);
  switch(uVar8) {
  case 0:
    halt_baddata();
    break;
  case 1:
    uStack_4 = (bStack_13 & (byte)stack0x02c2[unaff_DI]) + 0xf8;
    pbVar3 = (byte *)uStack_4;
    break;
  case 2:
    while( true ) {
      (pbVar5 + (int)unaff_DI)[-0x1ba] = (pbVar5 + (int)unaff_DI)[-0x1ba] + (char)uVar4;
      piVar6 = (int *)(fStack_8.ofs + (int)uStack_4 * 4);
      piVar6[1] = (*(uint16_t *)((uint8_t *)&(param_1) + 2));
      *piVar6 = (int)param_1 + (int)unaff_DI * 0x1e;
      for (uVar8 = 0; uVar8 < *(byte *)((int)param_1 + (int)unaff_DI * 0x1e + 0x1b);
          uVar8 = uVar8 + 1) {
        if (uVar8 == 0) {
          fVar11 = ovr_stshAllocStub();
          *(uint16_t *)(fStack_8.ofs + (int)uStack_4 * 4 + 0x5a) = fVar11.seg;
          *(uint16_t *)(fStack_8.ofs + (int)uStack_4 * 4 + 0x58) = fVar11.ofs;
        }
        else {
          ovr_stshAllocStub();
        }
      }
      unaff_DI = unaff_DI + 1;
      if ((param_2 <= unaff_DI) || (*(char *)((int)param_1 + (int)unaff_DI * 0x1e + 0x1b) == '\0'))
      break;
      pbVar5 = (byte *)((int)param_1 + (int)unaff_DI * 0x1e);
      uStack_4 = *pbVar5;
    }
    return (byte *)fStack_8.ofs;
  case 3:
  case 5:
    if (*(char *)((int)(char **)GMenuStrings +
                 (uint)*(byte *)(Entities.ofs + uVar8 + 0xd) * 0x95 + 0x1f) == '\0') {
      ovr_play_sfx(38,0);
    }
    else {
      ovr_play_sfx(36,0);
    }
    *(undefined1 *)(Entities.ofs + 0x18) = 0;
    *(undefined1 *)(Entities.ofs + 0x31) = *(undefined1 *)(Entities.ofs + 0x32);
    if ((byte *)((int)(undefined4 *)&_DATA + 1) < EntityCount) {
      pbVar7 = (byte *)((char *)"thief" + 5);
      ovr_say((char *)CONCAT22(pbVar3,(char *)
                                      "The damaged structures belonging to all leaders are highlighted in red."
                              ));
      return pbVar7;
    }
    if ((cStack_e != '\0') || (cStack_d != '\0')) {
      if ((*(uint8_t *)((uint8_t *)&(uStack_4) + 1)) == '\0') {
        ovr_stop_audio();
        CurSfxType3 = 0xff;
        ovr_play_sfx(90,0);
      }
      else if (cStack_d == '\0') {
        if (cStack_e != '\0') {
          ovr_play_sfx(37,0);
        }
      }
      else {
        ovr_play_sfx(35,0);
      }
    }
    GGameState = 0x3d;
    if (DebugVerbose != false) {
      printf("%d \r",0x3d);
    }
    pbVar3 = (byte *)ovr_OVC23_55fe_2b82();
    return pbVar3;
  case 4:
    do {
      cVar1 = ovr_OVC23_55fe_05db();
      if ((cVar1 == '\0') && ((*(byte *)(Entities.ofs + (int)pbVar7 * 0x37 + 0x33) & 3) == 0)) {
        return pbVar7;
      }
      do {
        pbVar7 = pbVar7 + 1;
        if (EntityCount <= pbVar7) {
          pbVar7 = (byte *)0x0;
        }
        if (pbVar7 == unaff_DI) {
          uVar2 = ovr_randBelow((uint16_t)EntityCount);
          return (byte *)(uVar2 & 0xff);
        }
      } while (*(char *)(Entities.ofs + (int)pbVar7 * 0x37 + 0x1a) != (char)fStack_8.ofs);
    } while( true );
  case 6:
    pbVar3 = (byte *)(uint)(bStack_13 | 0xb);
    bVar9 = false;
    while (!bVar9) {
      if ((0 < (int)param_4) || ((uVar8 = param_3, -1 < (int)param_4 && (0xbfff < param_3)))) {
        uVar8 = 0xc000;
      }
      pvVar10 = (void *)ovr_mkp((*(uint16_t *)((uint8_t *)&(param_1) + 2)),(uint16_t)param_2);
      param_2 = (byte *)((ulong)pvVar10 >> 0x10);
      write((int)unaff_DI,(void *)pvVar10,uVar8);
      param_1 = (ulong)((int)(void *)pvVar10 + uVar8) << 0x10;
      bVar9 = param_3 < uVar8;
      param_3 = param_3 - uVar8;
      param_4 = param_4 - bVar9;
      pbVar3 = (byte *)(param_3 | param_4);
      bVar9 = pbVar3 == (byte *)0x0;
    }
    return pbVar3;
  case 7:
    return pbStack_28;
  case 8:
                    /* WARNING: Subroutine does not return */
    ovr_stExit((int)pbVar3);
  }
  do {
    if ((((*(uint *)((int)pbVar3 * 0x27 + 0x121) & 0xa0) != 0) ||
        (*(char *)((int)pbVar3 * 0x27 + 0x133) == '\0')) ||
       (*(char *)((int)pbVar3 * 0x27 + 0x133) == '\a')) break;
    pbVar3 = pbVar3 + 1;
    if ((char *)"y1 %d yn %d y3 %d yx %d " + 0x11 < pbVar3) {
      pbVar3 = (byte *)((int)&GUnitDescriptions[3].ofs + 1);
    }
  } while (uStack_4 != pbVar3);
  for (fStack_8.seg = 0; fStack_8.seg < 0x94; fStack_8.seg = fStack_8.seg + 1) {
    for (uVar8 = 0; uVar8 < 0x3c; uVar8 = uVar8 + 1) {
      uVar4 = (undefined2)((ulong)DAT_2000_cb0d >> 0x10);
      if ((byte *)*(int *)((int)DAT_2000_cb0d + fStack_8.seg * 0x78 + uVar8 * 2) == pbVar3) {
        *(undefined2 *)((int)DAT_2000_cb0d + fStack_8.seg * 0x78 + uVar8 * 2) = 0;
      }
    }
  }
  *(undefined1 *)((int)DAT_2000_ca95 + (int)pbVar3 * 9) = (*(uint8_t *)((uint8_t *)&(param_2)));
  *(undefined1 *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 1) = 8;
  *(undefined1 *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 2) = (undefined1)param_3;
  *(int *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 4) = (int)param_1;
  *(int *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 6) = (*(uint16_t *)((uint8_t *)&(param_1) + 2));
  *(undefined2 *)((int)DAT_2000_cb0d + (int)param_1 * 0x78 + (*(uint16_t *)((uint8_t *)&(param_1) + 2)) * 2) = (undefined2)(uint)pbVar3;
  uVar4 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
  *(uint *)((int)DAT_2000_cb09 + (*(uint16_t *)((uint8_t *)&(param_1) + 2)) * 0x128 + (int)param_1 * 2) =
       *(uint *)((int)DAT_2000_cb09 + (*(uint16_t *)((uint8_t *)&(param_1) + 2)) * 0x128 + (int)param_1 * 2) & 0x3fff |
       (uint)*(byte *)(((uint)param_2 & 0xff) * 0x27 + 0x11e) << 0xe;
  if ((*(uint *)(((uint)param_2 & 0xff) * 0x27 + 0x121) & 0x40) == 0) {
    *(undefined1 *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 8) = 0;
  }
  else {
    cVar1 = ovr_constr_36ce_3172();
    if (cVar1 == '\x03') {
      uVar2 = ovr_randBelow(0x28);
      *(char *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 8) = (char)uVar2 + '\x1e';
    }
    else if (cVar1 == '\x04') {
      uVar2 = ovr_randBelow(0x50);
      *(char *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 8) = (char)uVar2 + '<';
    }
    else {
      uVar2 = ovr_randBelow(0x14);
      *(char *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 8) = (char)uVar2 + '\x0f';
    }
  }
  return pbVar3;
}
