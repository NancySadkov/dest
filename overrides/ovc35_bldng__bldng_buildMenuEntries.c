  bldng_buildMenuEntries
            ((uint32_t)CONCAT22(unaff_SS,&buildTypes),entries_00,count,in_stack_00000004);
  uVar2 = bldng_usesGStrangeTable
                    (((char_sheet_t *)(((uint)in_stack_00000004 << 2)))->buildType[0]);
  iVar4 = (uVar2 & 0xff) * 0x27;
  uVar7 = 0x195d;
  uVar3 = *(uint16_t *)(iVar4 + 0x10e);
  uVar8 = (undefined1)uVar3;
  pcVar5 = ovr_stsprintf(acStack_ce,(char *)CONCAT22(0x690b,unaff_SS),
                         (char *)CONCAT13((char)((uint)uVar3 >> 8),CONCAT12(uVar8,0x2410)),uVar8,
                         (char)*(uint16_t *)(iVar4 + 0x110));
  puVar6 = &menuEntries;
  entries.seg = (uint16_t)unaff_SS;
  entries.ofs = (uint16_t)puVar6;
  (*(uint8_t *)((uint8_t *)&(hint.seg))) = (char)uVar7;
  hint.ofs = (uint16_t)pcVar5;
  (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = (char)((uint)uVar7 >> 8);
  ovr_ovc28_compute2(entries,count,hint,(char)pcVar5);
  cStack_4 = (char)puVar6;
  if ((char)puVar6 != '\0') {
    ((char_sheet_t *)(((uint)in_stack_00000004 << 2)))->buildType[0] =
         (&stk_fe0a)[((uint)puVar6 & 0xff) * 2];
  }
