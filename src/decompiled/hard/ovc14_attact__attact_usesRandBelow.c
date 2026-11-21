void __cdecl16far attact_usesRandBelow(agnt_t *agnt,byte dir,...)

{
  uint16_t uVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined1 uStack0007;
  byte in_stack_00000008;
  uint16_t agntX;   /* hand fix: [BP-6] is a WORD copy of agnt->x (3f0b:246f) */
  uint16_t uStack_6;
  int iStack_4;
  
  agnt = (int *)CONCAT13(uStack0007,CONCAT12(dir,agnt));
  uVar4 = (undefined2)((ulong)agnt >> 0x10);
  if (in_stack_00000008 == 0xff) {
    uVar1 = ovr_randBelow(4,*(undefined1 *)
                             ((int)(char **)GMenuStrings + (uint)agnt->gindex * 0x95 + 0x1f));
    in_stack_00000008 = (byte)uVar1;
    do {
      agntX = agnt->x;
      uVar2 = attact_usesAlignUp44((int *)CONCAT22(unaff_SS,&agntX),agnt->y,in_stack_00000008);
      if ((uVar2 & 0xff) == 0) goto L_attact_3f0b_2430_24BF;
      in_stack_00000008 = in_stack_00000008 + 1 & 3;
    } while (in_stack_00000008 != (byte)uVar1);
  }
  else {
    agntX = agnt->x;
    in_stack_00000008 = in_stack_00000008 ^ 2;
L_attact_3f0b_2430_24BF:
    iStack_4 = agnt->x;
    uStack_6 = agnt->y;
    agnt->y = agnt->y + (int)*(char *)(in_stack_00000008 + 0x889);
    iVar3 = ovr_ovc23_compute2(agntX + *(char *)(in_stack_00000008 + 0x885),agnt->y);
    agnt->x = iVar3;
    func_0x0004fcda(0x236f);
    constructionDirty = 1;
  }
  return;
}
