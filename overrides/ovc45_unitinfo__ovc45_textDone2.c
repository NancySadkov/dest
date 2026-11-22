ovc45_textDone2(char foundFlag,byte bldType,int entityIndex,uint16_t x,uint16_t outFlag,
               uint16_t outFlagSeg,...)

{
  uint *puVar1;
  int *piVar2;
  uint8_t partyIndex;
  byte bVar3;
  far_t entries;
  far_t hint;
  uint16_t agnt;
  char *pcVar4;
  uint16_t *puVar5;
  int iVar6;
  uint8_t *puVar7;
  uint16_t uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint16_t unaff_DI;
  uint16_t uVar13;
  char *unaff_SS;
  undefined1 uVar14;
  undefined1 uVar15;
  uint8_t menuLabels;
  uint16_t auStack_290 [19];
  uint8_t msg;
  uint8_t text;
  uint uStack_1a;
  uint uStack_18;
  char *pcStack_16;
  uint uStack_14;
  byte bStack_11;
  byte bStack_10;
  char cStack_f;
  char cStack_e;
  uint8_t menuActions;
  undefined1 auStack_c [10];
  
  agnt = x;
  uStack_1a = *(uint *)((uint)bldType * 0x27 + 0x125) / 10;
  auStack_290[0] = 0x2410;
  menuLabels = 0x77f0;
  auStack_c[0] = 1;
  if (*(int *)((uint)bldType * 0x27 + 0x116) == 0 && *(int *)((uint)bldType * 0x27 + 0x118) == 0) {
    auStack_290[2] = 0x2410;
    auStack_290[1] = 0x77f6;
  }
  else {
    auStack_290[2] = *(uint16_t *)((uint)bldType * 0x27 + 0x118);
    auStack_290[1] = *(uint16_t *)((uint)bldType * 0x27 + 0x116);
  }
  auStack_c[1] = 2;
  iVar12 = 2;
  if (foundFlag != '\0') {
    auStack_290[4] = 0x2410;
    auStack_290[3] = 0x7716;
    auStack_c[2] = 3;
    iVar12 = 3;
  }
  auStack_290[iVar12 * 2] = 0x2410;   /* hand fix: segment-half array, same value as the sibling stores in this function */
  *(char **)(&menuLabels + iVar12 * 4) = (char *)"Done";
  auStack_c[iVar12] = 4;
  cStack_e = '\0';
  do {
    uVar14 = 0x10;
    pcVar4 = ovr_ovc22_className(*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a));
    puVar5 = (uint16_t *)((uint)*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a) * 4);
    uVar15 = 0x7a;
    uVar8 = puVar5[1];
    iVar6 = ovc45_compute9((char *)&text,(char *)CONCAT22(*puVar5,unaff_SS),
                           (char *)CONCAT13((char)(Font03.ofs >> 8),CONCAT12((char)Font03.ofs,uVar8)
                                           ),Font03.seg,'U',(char)uVar8,(char)Font03.ofs,0x55,3,
                           pcVar4,uVar14);
    uVar8 = 0x195d;
    puVar7 = ovr_ovc15_usesStshRealloc
                       ((char *)*(uint16_t *)((uint)bldType * 0x27 + 0x10e),
                        (char)*(uint16_t *)((uint)bldType * 0x27 + 0x110),uStack_1a,(char)iVar6,
                        uVar15);
    pcVar4 = ovr_fmVsprintf("%s: Claim this tree? Harvest value is %d gold. Active party is %s the %s."
                            ,(char *)CONCAT13((char)((uint)uVar8 >> 8),CONCAT12((char)uVar8,puVar7))
                           );
    uVar14 = SUB21(unaff_SS,0);
    uVar15 = (undefined1)((uint)unaff_SS >> 8);
    strcpy((char *)CONCAT13(uVar15,CONCAT12(uVar14,&msg)),
           (char *)CONCAT13((char)((uint)uVar8 >> 8),CONCAT12((char)uVar8,pcVar4)));
    goldPartyIndex = *(undefined1 *)((int)Entities + entityIndex * 0x37 + 0x1a);
    puVar7 = &menuLabels;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = uVar14;
    entries.ofs = (uint16_t)puVar7;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar15;
    (*(uint8_t *)((uint8_t *)&(hint.seg))) = uVar14;
    hint.ofs = (uint16_t)&msg;
    (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = uVar15;
    ovr_ovc28_compute2(entries,iVar12 + 1U,hint,(char)(iVar12 + 1U));
    menuActions = (uint8_t)puVar7;
    goldPartyIndex = 0xff;
    if ((uint8_t)puVar7 != 0x0) {
      menuActions = auStack_c[((uint)puVar7 & 0xff) - 1];
    }
    if (menuActions == 0x1) {
      ovr_play_sfx(86,0,0);
      if (*(char *)((uint)bldType * 0x27 + 0x131) == '\0') {
        if (*(char *)((int)&worldMenuLabels[9].ofs + 1 +
                     (uint)((entity_t *)Entities)[entityIndex].base.gindex * 0x95) == '\x05') {
          bStack_11 = bldType + 0x18;
        }
        else {
          bStack_11 = bldType + 6;
        }
      }
      else {
        bStack_11 = bldType;
      }
      uStack_14 = (uint)*(byte *)((uint)bStack_11 * 0x27 + 0x120);
      *(undefined1 *)((uint)bStack_11 * 0x27 + 0x120) = 1;
      ovr_createConstructionRecord
                (bStack_11,agnt,GfxRndSeed2,(uint8_t *)outFlag,(char)outFlagSeg,(char)agnt,
                 (char)outFlag,(char)outFlagSeg,
                 CONCAT11((char)((uint)(entityIndex * 0x37) >> 8),
                          *(undefined1 *)((int)Entities + entityIndex * 0x37 + 0x1a)),0);
      *(undefined1 *)((uint)bStack_11 * 0x27 + 0x120) = (undefined1)uStack_14;
      bVar3 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
      pcStack_16 = ovr_ovc22_textPOPULATION(bStack_11,bVar3,(agnt_t *)agnt,bVar3,(char)GfxRndSeed2);
      uVar14 = 0x10;
      partyIndex = *(uint8_t *)((int)Entities + entityIndex * 0x37 + 0x1a);
      uStack_18 = ovr_ovc22_seasonalIncome(bStack_11,partyIndex,partyIndex,agnt,(char)GfxRndSeed2);
      ovc45_compute6((uint16_t)pcStack_16);
      pcVar4 = ovr_fmVsprintf("Forest claimed. This forest creates %d gold of income and feeds %d %s."
                              ,(char *)CONCAT13((char)((uint)pcStack_16 >> 8),
                                                CONCAT12((char)pcStack_16,uStack_18)));
      ovr_say(pcVar4,uVar14);
      ovr_inputUpdate((ulong)MessageDelay << 1);
      cStack_e = '\x01';
    }
    else if (menuActions == 0x2) {
      ovr_play_sfx(48,0,0);
      bVar3 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
      ovr_createConstructionRecordFar
                (0,agnt,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar3,(char)unaff_DI,
                 (char)GfxRndSeed2,(char)outFlag,bVar3);
      cStack_e = '\x01';
      bStack_10 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
      uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
      iVar6 = (int)*(uint32_t *)((uint)bStack_10 << 2);
      puVar1 = (uint *)(iVar6 + 0x56);
      uVar9 = *puVar1;
      *puVar1 = *puVar1 + uStack_1a;
      piVar2 = (int *)(iVar6 + 0x58);
      *piVar2 = *piVar2 + (uint)CARRY2(uVar9,uStack_1a);
      uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
      iVar10 = (int)*(uint32_t *)((uint)bStack_10 << 2);
      iVar6 = *(int *)(iVar10 + 0x58);
      uVar9 = *(uint *)(iVar10 + 0x56);
      uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
      iVar11 = (int)*(uint32_t *)((uint)bStack_10 << 2);
      iVar10 = *(int *)(iVar11 + 0x8c);
      if ((iVar10 <= iVar6) && ((iVar10 < iVar6 || (*(uint *)(iVar11 + 0x8a) < uVar9)))) {
        uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
        iVar6 = (int)*(uint32_t *)((uint)bStack_10 << 2);
        uVar9 = *(uint *)(iVar6 + 0x8a);
        uVar13 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
        iVar10 = (int)*(uint32_t *)((uint)bStack_10 << 2);
        *(uint16_t *)(iVar10 + 0x58) = *(uint16_t *)(iVar6 + 0x8c);
        *(uint *)(iVar10 + 0x56) = uVar9;
      }
      uVar14 = (undefined1)uVar9;
      pcVar4 = ovr_stsprintf((char *)&text);
      ovr_say(pcVar4,uVar14);
      ovr_inputUpdate((ulong)MessageDelay << 1);
    }
    else if (menuActions == 0x3) {
      uVar8 = ovc45_textChoosePartyBuild(agnt,GfxRndSeed2,&entityIndex,(char)GfxRndSeed2);
      cStack_f = (char)uVar8;
      if (cStack_f == -1) {
        cStack_e = '\x01';
      }
    }
    else if ((menuActions == 0x4) || (menuActions == 0x0)) {
      cStack_e = '\x01';
    }
  } while (cStack_e == '\0');
  return;
}
