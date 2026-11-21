void __cdecl16far __EXITEXT(void)

{
  undefined2 uVar1;
  
  uVar1 = (uint)startx;   /* hand fix: startx is a function */
  if (((char *)"Abnormal program termination\r\n")[5] != '\0') {
    if (*(int *)((char *)"Abnormal program termination\r\n" + 10) == 0) {
      if (iRam00000066 == 0x2272) {
        uRam00000064 = _BootHandlerCode;
        iRam00000066 = Int19Seg;
        ((char *)"Abnormal program termination\r\n")[5] = '\0';
      }
    }
    else {
      (**(code **)((char *)"Abnormal program termination\r\n" + 6))(0x1000,0x2410);
      (**(code **)((char *)"Abnormal program termination\r\n" + 6))(0x1000);
    }
  }
  return;
}
