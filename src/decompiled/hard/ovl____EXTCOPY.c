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
  if (*(int *)((char *)"Abnormal program termination\r\n" + 10) == 0) {
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
    *(uint *)((char *)"Abnormal program termination\r\n" + 0x10) = unaff_SI + 1 & 0xfffe;
    *(uint *)((char *)"Abnormal program termination\r\n" + 0x12) =
         unaff_DI + (uint)(0xfffe < unaff_SI);
    if ((byte)in_DX < 0x10) {
      ((char *)"Abnormal program termination\r\n" + 0x14)[0] = '\0';
      ((char *)"Abnormal program termination\r\n" + 0x14)[1] = '\0';
      uVar5 = in_DX >> 4 | in_DX << 0xc;
    }
    else {
      *(undefined2 *)((char *)"Abnormal program termination\r\n" + 0x14) =
           *(undefined2 *)((char *)"Abnormal program termination\r\n" + 10);
      bVar6 = in_AX < *(uint *)((char *)"Abnormal program termination\r\n" + 0xc);
      in_AX = in_AX - *(uint *)((char *)"Abnormal program termination\r\n" + 0xc);
      uVar5 = (in_DX - *(int *)((char *)"Abnormal program termination\r\n" + 0xe)) - (uint)bVar6;
    }
    *(uint *)((char *)"Abnormal program termination\r\n" + 0x16) = in_AX;
    *(uint *)((char *)"Abnormal program termination\r\n" + 0x18) = uVar5;
    if ((byte)in_CX < 0x10) {
      ((char *)"Abnormal program termination\r\n" + 0x1a)[0] = '\0';
      ((char *)"Abnormal program termination\r\n" + 0x1a)[1] = '\0';
      uVar4 = in_CX >> 4 | in_CX << 0xc;
    }
    else {
      *(undefined2 *)((char *)"Abnormal program termination\r\n" + 0x1a) =
           *(undefined2 *)((char *)"Abnormal program termination\r\n" + 10);
      bVar6 = in_BX < *(uint *)((char *)"Abnormal program termination\r\n" + 0xc);
      in_BX = in_BX - *(uint *)((char *)"Abnormal program termination\r\n" + 0xc);
      uVar4 = (in_CX - *(int *)((char *)"Abnormal program termination\r\n" + 0xe)) - (uint)bVar6;
    }
    *(uint *)((char *)"Abnormal program termination\r\n" + 0x1c) = in_BX;
    ((far_t *)GSTARTX_SavedVectors)->ofs = uVar4;
    iVar3 = (**(code **)((char *)"Abnormal program termination\r\n" + 6))(0x1000);
    if (iVar3 != 0) {
      return 0;
    }
    bVar7 = 1;
  }
  return -(uint)bVar7;
}
