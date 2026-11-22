void __cdecl16far
ovc45_textDone(char foundFlag,byte bldType,int entityIndex,uint16_t x,uint16_t outFlag,
              uint16_t outFlagSeg,...)

{
  byte bVar1;
  far_t entries;
  far_t entries_00;
  far_t hint;
  far_t hint_00;
  uint16_t x_00;
  char *pcVar2;
  uint16_t *puVar3;
  int iVar4;
  uint8_t *puVar5;
  uint uVar6;
  uint16_t uVar7;
  uint16_t uVar8;
  uint16_t uVar9;
  int iVar10;
  uint16_t unaff_DI;
  char *unaff_SS;
  undefined1 uVar11;
  undefined1 uVar12;
  uint8_t menuItems;
  uint16_t auStack_28e [19];
  uint8_t msg;
  uint8_t text;
  char cStack_17;
  char cStack_16;
  char cStack_15;
  uint8_t menuLabel;
  uint16_t uStack_12;
  uint16_t uStack_10;
  char cStack_e;
  char acStack_d [11];
  
  x_00 = x;
  auStack_28e[0] = 0x2410;
  menuItems = 0x7706;
  acStack_d[1] = 1;
  if (*(int *)((uint)bldType * 0x27 + 0x116) == 0 && *(int *)((uint)bldType * 0x27 + 0x118) == 0) {
    auStack_28e[2] = 0x2410;
    auStack_28e[1] = 0x770f;
  }
  else {
    auStack_28e[2] = *(uint16_t *)((uint)bldType * 0x27 + 0x118);
    auStack_28e[1] = *(uint16_t *)((uint)bldType * 0x27 + 0x116);
  }
  acStack_d[2] = 2;
  iVar10 = 2;
  if (foundFlag != '\0') {
    auStack_28e[4] = 0x2410;
    auStack_28e[3] = 0x7716;
    acStack_d[3] = 3;
    iVar10 = 3;
  }
  auStack_28e[iVar10 * 2] = 0x2410;   /* hand fix: segment-half array; this function already stores 0x2410 in auStack_28e[0],[2],[4] */
  *(char **)(&menuItems + iVar10 * 4) = (char *)"Done";
  acStack_d[iVar10 + 1] = '\x04';
  cStack_16 = '\0';
  do {
    uVar11 = 0x10;
    pcVar2 = ovr_ovc22_className(*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a));
    puVar3 = (uint16_t *)((uint)*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a) * 4);
    uVar8 = 0x217a;
    iVar4 = ovc45_compute9((char *)&text,(char *)CONCAT22(*puVar3,unaff_SS),
                           (char *)CONCAT13((char)(Font03.ofs >> 8),
                                            CONCAT12((char)Font03.ofs,puVar3[1])),Font03.seg,'U',
                           (char)Font03.ofs,0x55,3,pcVar2,uVar11);
    uVar9 = 0x195d;
    puVar5 = ovr_ovc15_usesStshRealloc
                       ((char *)*(uint16_t *)((uint)bldType * 0x27 + 0x10e),
                        *(uint16_t *)((uint)bldType * 0x27 + 0x110),(char)iVar4,uVar8);
    pcVar2 = ovr_fmVsprintf("%s: Search this location for minerals?  Active party is %s the %s.",
                            (char *)CONCAT22(uVar9,puVar5));
    strcpy((char *)CONCAT22(unaff_SS,&msg),
           (char *)CONCAT13((char)((uint)uVar9 >> 8),CONCAT12((char)uVar9,pcVar2)));
    goldPartyIndex = *(undefined1 *)((int)Entities + entityIndex * 0x37 + 0x1a);
    uVar11 = SUB21(unaff_SS,0);
    uVar12 = (undefined1)((uint)unaff_SS >> 8);
    puVar5 = &menuItems;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = uVar11;
    entries.ofs = (uint16_t)puVar5;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar12;
    (*(uint8_t *)((uint8_t *)&(hint.seg))) = uVar11;
    hint.ofs = (uint16_t)&msg;
    (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = uVar12;
    ovr_ovc28_compute2(entries,iVar10 + 1,hint);
    cStack_15 = (char)puVar5;
    goldPartyIndex = 0xff;
    if (cStack_15 != '\0') {
      cStack_15 = acStack_d[(uint)puVar5 & 0xff];
    }
    if (cStack_15 == '\x01') {
      uVar6 = ovc45_usesRandBelow(entityIndex);
      if ((uVar6 & 0xff) == 0) {
        ovr_play_sfx(47,0,0);
        ovr_say((char *)"No minerals were found.",0x10);
        bVar1 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
        ovr_createConstructionRecordFar
                  (0,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,(char)unaff_DI,
                   (char)GfxRndSeed2,bVar1);
      }
      else {
        uVar7 = ovr_randBelow(0x10);
        if ((uVar7 & 0xff) == 0) {
          ovr_play_sfx(42,0,0);
          ovr_say((char *)"Gems discovered.",0x10);
          bVar1 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
          ovr_createConstructionRecordFar
                    (0x72,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,
                     (char)unaff_DI,(char)GfxRndSeed2,bVar1);
        }
        else {
          uVar7 = ovr_randBelow(4);
          if ((char)uVar7 == '\0') {
            ovr_play_sfx(43,0,0);
            ovr_say((char *)"Gold discovered.",0x10);
            bVar1 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
            ovr_createConstructionRecordFar
                      (0x71,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,
                       (char)unaff_DI,(char)GfxRndSeed2,bVar1);
          }
          else {
            ovr_play_sfx(42,0,0);
            ovr_say((char *)"Iron deposits discovered.",0x10);
            bVar1 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
            ovr_createConstructionRecordFar
                      (0x70,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,
                       (char)unaff_DI,(char)GfxRndSeed2,bVar1);
          }
        }
      }
      ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x12));
      cStack_16 = '\x01';
    }
    else if (cStack_15 == '\x02') {
      uStack_12 = 0x2410;
      menuLabel = 0x770f;
      cStack_e = '\x10';
      acStack_d[0] = '$';
      uStack_10 = 0x77ba;
      uVar9 = 0x195d;
      uVar8 = *(uint16_t *)((uint)bldType * 0x27 + 0x110);
      pcVar2 = ovr_fmVsprintf("Remove %s permanently. Are you sure?",
                              (char *)CONCAT13((char)((uint)uVar8 >> 8),
                                               CONCAT12((char)uVar8,
                                                        *(uint16_t *)
                                                         ((uint)bldType * 0x27 + 0x10e))));
      puVar5 = &menuLabel;
      (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = uVar11;
      entries_00.ofs = (uint16_t)puVar5;
      (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = uVar12;
      (*(uint8_t *)((uint8_t *)&(hint_00.seg))) = (char)uVar9;
      hint_00.ofs = (uint16_t)pcVar2;
      (*(uint8_t *)((uint8_t *)&(hint_00.seg) + 1)) = (char)((uint)uVar9 >> 8);
      ovr_ovc28_compute2(entries_00,2,hint_00);
      cStack_15 = (char)puVar5;
      if (cStack_15 == '\x01') {
        bVar1 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
        ovr_createConstructionRecordFar
                  (0,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,(char)unaff_DI,
                   (char)GfxRndSeed2,bVar1);
      }
      cStack_16 = '\x01';
    }
    else if (cStack_15 == '\x03') {
      uVar8 = ovc45_textChoosePartyBuild(x_00,GfxRndSeed2,&entityIndex);
      cStack_17 = (char)uVar8;
      if (cStack_17 == -1) {
        cStack_16 = '\x01';
      }
    }
    else if ((cStack_15 == '\x04') || (cStack_15 == '\0')) {
      cStack_16 = '\x01';
    }
  } while (cStack_16 == '\0');
  return;
}
