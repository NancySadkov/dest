uint16_t __cdecl16far draw_usesGameProcessKey(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  undefined1 extraout_AH;
  int iStack_a;
  int iStack_8;
  
  iStack_8 = -1;
  iStack_a = -1;
  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x2410);
  iVar3 = MouseY;
  iVar2 = MouseX;
  bVar1 = false;
  MouseMoved = 0;
  while( true ) {
    if ((*(int *)(BDA_DailyTimeCounter.ofs + 2) != iStack_8) ||
       (*(int *)BDA_DailyTimeCounter != iStack_a)) {
      iStack_8 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
      iStack_a = *(int *)BDA_DailyTimeCounter;
      draw_usesPrintf();
      if (GGameInProgress != '\0') {
        ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
        draw_usesResetTextBlitCycle();
        return 0;
      }
    }
    uVar5 = ovr_biosKeyAvail();
    if ((char)uVar5 != '\0') break;
    bVar4 = ovr_init2_usesCFGMice((uint16_t *)&MouseX,(uint16_t *)0xe62410,0x2410);
    if (CONCAT11(extraout_AH,bVar4) == 0) {
      bVar1 = true;
    }
    else if (((bVar1) || (iVar2 != MouseX)) || (iVar3 != MouseY)) {
      if (!bVar1) {
        MouseMoved = 1;
      }
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
      MouseBkgPixel = *(undefined1 *)(MouseY * 0x140 + MouseX);
      draw_usesResetTextBlitCycle();
      GGameState = 0x36;
      if (DebugVerbose != false) {
        printf("%d \r");
      }
      return 0xffff;
    }
  }
  GGameState = 0x3b;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
  draw_usesResetTextBlitCycle();
  uVar5 = gameProcessKey();
  while (uVar6 = ovr_biosKeyAvail(), (char)uVar6 != '\0') {
    uVar5 = gameProcessKey();
  }
  GGameState = 0x35;
  if (DebugVerbose == false) {
    GGameState = 0x35;
    return uVar5;
  }
  printf("%d \r");
  return uVar5;
}
