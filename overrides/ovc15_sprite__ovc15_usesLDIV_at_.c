ovc15_usesLDIV_at_(uint16_t x,uint16_t y,uint16_t destX,uint16_t destY,byte gindex,uint8_t animFrame
                  ,byte partyIndex,...)

{
  uint8_t *puVar1;
  uint *puVar2;
  uint16_t uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  entity_t *peVar7;
  uint16_t uVar8;
  long lVar9;
  int iStack_6;
  
  if (EntityCount < 0x259) {
    mapDirty = 1;
    if (PlayerIndex < 2) {
      if (0x21b < EntityCount) {
        uVar5 = ovc15_usesRandBelow2();
        ovc15_removeEntity(uVar5);
        EntityCount = EntityCount - 1;
      }
    }
    else if (599 < EntityCount) {
      uVar5 = ovc15_usesRandBelow2();
      ovc15_removeEntity(uVar5);
      EntityCount = EntityCount - 1;
    }
    _fsetmem((entity_t *)CONCAT22((int)((ulong)Entities >> 0x10),Entities + EntityCount),0x37,0);
    ((entity_t *)Entities)[EntityCount].base.targetX = destX;
    ((entity_t *)Entities)[EntityCount].base.targetY = destY;
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    if ((destX == x) && (destY == y)) {
      ((entity_t *)Entities)[EntityCount].base.destX = 0;
      ((entity_t *)Entities)[EntityCount].base.destY = 0;
    }
    else {
      ((entity_t *)Entities)[EntityCount].base.destX = destX;
      ((entity_t *)Entities)[EntityCount].base.destY = destY;
    }
    (((entity_t *)Entities + EntityCount)->base).x = x;
    ((entity_t *)Entities)[EntityCount].base.y = y;
    ((entity_t *)Entities)[EntityCount].base.target = 0xff;
    ((entity_t *)Entities)[EntityCount].base.gindex = gindex;
    uVar5 = EntityCount;
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    peVar7 = (entity_t *)Entities;
    puVar1 = &peVar7[EntityCount].base.frameIndex;
    puVar1[0] = 0x0;
    puVar1[1] = 0x0;
    puVar1 = &peVar7[uVar5].base.health;
    puVar1[0] = 0x64;
    puVar1[1] = 0x0;
    *(uint16_t *)((int)&((entity_t *)Entities)[EntityCount].base.frames + 1) = 0;
    ((entity_t *)Entities)[EntityCount].base.animFrame = animFrame;
    *(byte *)((int)&((entity_t *)Entities)[EntityCount].base.entity + 3) = partyIndex;
    *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
    *(undefined1 *)&((entity_t *)Entities)[EntityCount].base.flags32 =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
    if (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x2f) != -1) {
      uVar5 = (uint)*(byte *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
      uVar8 = ovr_agnt_abilityModifier(partyIndex,4);
      iStack_6 = uVar5 + (int)(char)uVar8;
      if (iStack_6 < 1) {
        iStack_6 = 1;
      }
      *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
           (undefined1)iStack_6;
      *(undefined1 *)&((entity_t *)Entities)[EntityCount].base.flags32 = (undefined1)iStack_6;
    }
    if (*(char *)((int)(char **)GMenuStrings + (uint)gindex * 0x95 + 0x1f) == '\0') {
      uVar5 = ovc15_usesAlignUp4(destX,destY);
      if ((uVar5 & 0xff) == 0) {
        *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.flags32 + 1) = 2;
      }
    }
    else if ((destX == x) && (destY == y)) {
      *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.flags32 + 1) = 2;
    }
    if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)gindex * 0x95) & 0x1000) == 0) {
      if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)gindex * 0x95) & 0x2000) == 0) {
        lVar9 = 0x8000;
        uVar5 = rand();
        lVar9 = LDIV_at_(CONCAT22(((int)uVar5 >> 0xf) << 1 | (uint)((int)uVar5 < 0),uVar5 << 1),
                         lVar9);
        if ((int)lVar9 == 0) {
          puVar2 = (uint *)((int)&((entity_t *)Entities)[EntityCount].base.frames + 3);
          *puVar2 = *puVar2 | 1;
        }
      }
      else {
        puVar2 = (uint *)((int)&((entity_t *)Entities)[EntityCount].base.frames + 3);
        *puVar2 = *puVar2 | 1;
      }
    }
    ((entity_t *)Entities)[EntityCount].base.level =
         *(uint8_t *)((int)&worldMenuLabels[8].seg + (uint)gindex * 0x95);
    if ((((((char_sheet_t *)(((uint)partyIndex << 2)))->flags5d & 0x10) != 0) &&
        (*(byte *)((int)&worldMenuLabels[8].seg + (uint)gindex * 0x95) < 5)) &&
       (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)gindex * 0x95) != -1)) {
      while (((entity_t *)Entities)[EntityCount].base.level < 5) {
        cVar4 =(uint16_t)( ovr_ovc15_textView()   /* hand fix: args lost by the decompiler */);
        uVar8 = (uint16_t)((ulong)Entities >> 0x10);
        *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
             *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) + cVar4;
        uVar8 = (uint16_t)((ulong)Entities >> 0x10);
        *(char *)&((entity_t *)Entities)[EntityCount].base.flags32 =
             (char)((entity_t *)Entities)[EntityCount].base.flags32 + cVar4;
        puVar1 = &((entity_t *)Entities)[EntityCount].base.level;
        *puVar1 = *puVar1 + 0x1;
      }
    }
    uVar5 = EntityCount;
    peVar7 = (entity_t *)Entities;
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)gindex * 0x95) == -1) {
      iVar6 = (uint)peVar7[EntityCount].base.level * 4;
      uVar3 = *(uint16_t *)(iVar6 + -4);
      *(uint16_t *)&peVar7[EntityCount].base.frameIndex = *(uint16_t *)(iVar6 + -2);
      *(uint16_t *)&peVar7[uVar5].base.health = uVar3;
    }
    else {
      iVar6 = (uint)*(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)gindex * 0x95) * 0x94 +
              (uint)peVar7[EntityCount].base.level * 4;
      uVar3 = *(uint16_t *)(iVar6 + -4);
      *(uint16_t *)&peVar7[EntityCount].base.frameIndex = *(uint16_t *)(iVar6 + -2);
      *(uint16_t *)&peVar7[uVar5].base.health = uVar3;
    }
    uVar5 = EntityCount;
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    peVar7 = (entity_t *)Entities;
    if (*(int *)&peVar7[EntityCount].base.health == 0 &&
        *(int *)&peVar7[EntityCount].base.frameIndex == 0) {
      puVar1 = &peVar7[EntityCount].base.frameIndex;
      puVar1[0] = 0x0;
      puVar1[1] = 0x0;
      puVar1 = &peVar7[uVar5].base.health;
      puVar1[0] = 0x64;
      puVar1[1] = 0x0;
    }
    uVar5 = EntityCount;
    EntityCount = EntityCount + 1;
    ovr_attact_usesGMapFlags3();
    if (AgntFlag1 != false) {
      uVar8 = (uint16_t)((ulong)Entities >> 0x10);
      peVar7 = (entity_t *)Entities;
      if (((GfxRndSeed - 2U <= ((peVar7 + uVar5)->base).x) &&
          (((peVar7 + uVar5)->base).x <= GfxRndSeed + 1U)) && (peVar7[uVar5].base.y == GfxRndSeed2))
      {
        ovc15_textArena(uVar5);
      }
    }
    peVar7 = Entities + uVar5;
    return peVar7;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x26);
}
