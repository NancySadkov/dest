void __cdecl16far __EXITEXT(void)

{
  uint16_t uVar1;
  
  uVar1 = (uint)startx;   /* hand fix: startx is a function */
  if (((char *)"Abnormal program termination\r\n")[5] != '\0') {
    if (*(int *)((char *)0x47) == 0) {
      if (iRam00000066 == 0x2272) {
        uRam00000064 = _BootHandlerCode;
        iRam00000066 = Int19Seg;
        ((char *)"Abnormal program termination\r\n")[5] = '\0';
      }
    }
    else {
      (**(code **)((char *)0x43))(0x1000,0x2410);
      (**(code **)((char *)0x43))(0x1000);
    }
  }
  return;
}
