char * __cdecl16far ovc15_textArena(int owner,...)

{
  bool bVar1;
  uint uVar2;
  uint16_t uVar3;
  char *pcVar4;
  entity_t *peVar5;
  agntG_t *paVar6;
  far_t far *pfVar7;
  uint16_t unaff_DI;
  uint16_t uVar8;
  uint16_t uVar9;
  uint unaff_SS;
  int in_stack_00000006;
  char in_stack_00000008;
  agnt_t agntCopy;
  uint uStack_8;
  
  uVar9 = DAT_2000_d190;
  if (AgntFlag1) {
    for (uStack_8 = 0; (int)uStack_8 < (int)(uint)AgntCount; uStack_8 = uStack_8 + 1) {
      if (((*(char *)(uStack_8 * 0x34 + 0x2d) == '\0') &&
          (*(int *)(uStack_8 * 0x34 + 0x1b) == owner)) &&
         ((*(uint *)(uStack_8 * 0x34 + 0x2b) & 0xae4) == 0)) {
        *(undefined1 *)(uStack_8 * 0x34 + 0x2d) = 1;
        if ((*(char *)(uStack_8 * 0x34 + 0x11) != '\0') ||
           (uVar2 = ovr_ovc49_compute1(*(int *)(uStack_8 * 0x34)), (char)uVar2 == '\0')) {
          uVar2 = ovc15_usesStExit2((byte)uStack_8);
          if ((uVar2 & 0xff) != 0) {
            return (char *)((int)(uint32_t *)&_DATA + 1);
          }
        }
        _fmemmove((char *)CONCAT22(unaff_SS,&agntCopy),
                  (char *)CONCAT22(0x1726,(char *)(uStack_8 * 0x34)),0x34);
        agntCopy.target = 0xff;
        ovr_ovc41_removeAgent(uStack_8,0);
        pcVar4 = (char *)ovc15_usesRandBelow((agnt_t *)CONCAT22(unaff_SS,&agntCopy),
                                             in_stack_00000006,'\x01',in_stack_00000008);
        return pcVar4;
      }
    }
  }
  if (AgntCount < 0x18) {
    peVar5 = Entities + owner;
    _fmemset((void *)(ulong)unaff_SS,0x34,unaff_DI);
    agntCopy.target = 0xff;
    (*(uint16_t *)((uint8_t *)&(agntCopy.entity) + 2)) = uVar9;
    agntCopy.owner = owner;
    agntCopy.gdata =
         (agntG_t *)
         CONCAT22(0x195d,(agntG_t *)
                         ((int)(char **)GMenuStrings + (uint)(peVar5->base).gindex * 0x95 + 0x1f));
    (*(uint16_t *)((uint8_t *)&(agntCopy.entity))) =(uint16_t)( peVar5);
    bVar1 = ovc15_usesAlignUp42();
    if (!bVar1) {
      *(undefined1 *)((int)&(peVar5->base).state + 1) = (char)(peVar5->base).flags32;
    }
    agntCopy.strengthMax = (uint8_t)(peVar5->base).flags32;
    agntCopy.strength = *(uint8_t *)((int)&(peVar5->base).state + 1);
    bVar1 = (*(uint *)((int)&(peVar5->base).frames + 3) & 1) != 0;
    paVar6 = (agntG_t *)agntCopy.gdata;
    uVar8 = (uint16_t)((ulong)agntCopy.gdata >> 0x10);
    if ((peVar5->base).level < 10) {
      if ((peVar5->base).level < 4) {
        agntCopy.frames =
             (far_t far *)CONCAT22(*(uint16_t *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 2),
                               *(far_t far **)(paVar6->sprs + (uint)bVar1 * 3));
      }
      else {
        agntCopy.frames =
             (far_t far *)CONCAT22(*(uint16_t *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 6),
                               *(far_t far **)(paVar6->sprs + (uint)bVar1 * 3 + 1));
      }
    }
    else {
      agntCopy.frames =
           (far_t far *)CONCAT22(*(uint16_t *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 10),
                             *(far_t far **)(paVar6->sprs + (uint)bVar1 * 3 + 2));
    }
    agntCopy.animFrame = 0xff;
    agntCopy.faction = (agntCopy.gdata)->ai;
    uVar9 = (uint16_t)((ulong)agntCopy.frames >> 0x10);
    pfVar7 = (far_t far *)agntCopy.frames;
    if (((pfVar7 + 0x1a)->ofs == 0 && pfVar7[0x1a].seg == 0) ||
       ((pfVar7 + 0x16)->ofs == 0 && pfVar7[0x16].seg == 0)) {
      if ((pfVar7 + 0x1a)->ofs != 0 || pfVar7[0x1a].seg != 0) {
        agntCopy.animVariant = 0x1;
      }
    }
    else {
      uVar3 = ovr_randBelow(2);
      agntCopy.animVariant = (uint8_t)uVar3;
    }
    uVar3 = ovr_randBelow(2);
    (*(uint8_t *)((uint8_t *)&(agntCopy.targetX))) = (char)uVar3 * '\x02' + -1;
    if ((char)agntCopy.targetX < '\x01') {
      if ((char)agntCopy.targetX < '\0') {
        agntCopy.level = 0x1;
      }
      else {
        uVar3 = ovr_randBelow(2);
        agntCopy.level = (uint8_t)uVar3;
      }
    }
    else {
      agntCopy.level = 0x0;
    }
    pcVar4 = (char *)ovc15_usesRandBelow((agnt_t *)CONCAT22(unaff_SS,&agntCopy),in_stack_00000006,
                                         '\0',in_stack_00000008);
  }
  else {
    pcVar4 = (char *)0x2400;
  }
  return pcVar4;
}
