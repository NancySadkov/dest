int __cdecl16near __EXTCOPY(void)

{
  code *pcVar1;
  undefined2 uVar2;
  uint in_AX;
  int iVar3;
  uint in_CX;
  uint16_t uVar4;
  uint in_DX;
  uint uVar5;
  uint in_BX;
  uint unaff_SI;
  int unaff_DI;
  bool bVar6;
  byte bVar7;
  
  uVar2 = (uint)startx;   /* hand fix: startx is a function */
  if (*(int *)((char *)0x47) == 0) {
    bVar7 = false;
    ((far_t *)(GSTARTX_SavedVectors + 1))->ofs = in_AX;
    *(byte *)&GSTARTX_SavedVectors[1].seg = (byte)in_DX;
    ((far_t *)(GSTARTX_SavedVectors + 3))->ofs = in_BX;
    *(byte *)&GSTARTX_SavedVectors[3].seg = (byte)in_CX;
    pcVar1 = (code *)swi(0x15);
    (*pcVar1)(0x2410);
    if (!(bool)bVar7) {
      return 0;
    }
  }
  else {
    *(uint *)((char *)0x4d) = unaff_SI + 1 & 0xfffe;
    *(uint *)((char *)0x4f) =
         unaff_DI + (uint)(0xfffe < unaff_SI);
    if ((byte)in_DX < 0x10) {
      ((char *)0x51)[0] = '\0';
      ((char *)0x51)[1] = '\0';
      uVar5 = in_DX >> 4 | in_DX << 0xc;
    }
    else {
      *(undefined2 *)((char *)0x51) =
           *(undefined2 *)((char *)0x47);
      bVar6 = in_AX < *(uint *)((char *)0x49);
      in_AX = in_AX - *(uint *)((char *)0x49);
      uVar5 = (in_DX - *(int *)((char *)0x4b)) - (uint)bVar6;
    }
    *(uint *)((char *)0x53) = in_AX;
    *(uint *)((char *)0x55) = uVar5;
    if ((byte)in_CX < 0x10) {
      ((char *)0x57)[0] = '\0';
      ((char *)0x57)[1] = '\0';
      uVar4 = in_CX >> 4 | in_CX << 0xc;
    }
    else {
      *(undefined2 *)((char *)0x57) =
           *(undefined2 *)((char *)0x47);
      bVar6 = in_BX < *(uint *)((char *)0x49);
      in_BX = in_BX - *(uint *)((char *)0x49);
      uVar4 = (in_CX - *(int *)((char *)0x4b)) - (uint)bVar6;
    }
    *(uint *)((char *)0x59) = in_BX;
    ((far_t *)GSTARTX_SavedVectors)->ofs = uVar4;
    iVar3 = (**(code **)((char *)0x43))(0x1000);
    if (iVar3 != 0) {
      return 0;
    }
    bVar7 = 1;
  }
  return -(uint)bVar7;
}
