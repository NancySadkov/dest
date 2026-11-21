void __cdecl16far copyProtectionCheck(void)

{
  uint16_t uVar1;
  char *pcVar2;
  byte *in_DX;
  char *unaff_SS;
  uint16_t uVar3;
  uint8_t uVar4;
  far_t handle;
  uint8_t msg;
  uint16_t input;
  byte *pbStack_a;
  char *uStack_8;   /* hand fix: *uStack_8 deref */
  uint8_t attempts;
  uint8_t codes;
  
  if (CopyProtectionDone == '\0') {
    uVar1 = ovr_randBelow(0x19);
    codes = (uint8_t)uVar1;
    attempts = 0x0;
    while( true ) {
      if (3 < attempts) {
        if (SaveAuto != '\0') {
          ovr_stSave();
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0);
      }
      ovr_saveui_blitPanel();
      TextBlitX = 0x16;
      TextBlitY = 0xc;
      ovr_blitText((char *)"Stronghold copy protection.",
                   (byte *)CONCAT22(Font03.ofs,(char *)0x26510),Font03.seg,0xde);
      TextBlitX = 0x16;
      TextBlitY = 0x2f;
      uVar4 = 0xde;
      uVar1 = Font03.ofs;
      uVar3 = Font03.seg;
      pcVar2 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6cd,unaff_SS),
                             (char *)(ulong)CONCAT12(*(undefined1 *)(codes + 0x51a),0x2410));
      ovr_blitText(pcVar2,(byte *)CONCAT22(uVar1,in_DX),uVar3,uVar4);
      TextBlitX = 0x16;
      TextBlitY = 0x43;
      uVar4 = 0xde;
      uVar1 = Font03.ofs;
      uVar3 = Font03.seg;
      pcVar2 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6ed,unaff_SS),
                             (char *)(ulong)CONCAT12(*(undefined1 *)(codes + 0x533),0x2410));
      ovr_blitText(pcVar2,(byte *)CONCAT22(uVar1,in_DX),uVar3,uVar4);
      TextBlitX = 0x16;
      TextBlitY = 0x57;
      ovr_blitText((char *)"Enter the first word.",
                   (byte *)CONCAT22(Font03.ofs,(char *)0x26510),Font03.seg,0xde);
      pbStack_a = (byte *)0x0;
      input = 0;
      pcVar2 = ovr_stshAlloc(2);
      uStack_8 = (char *)CONCAT22(in_DX,pcVar2);
      *uStack_8 = *(char *)*(undefined4 *)((uint)codes * 4 + 0x54c);
      pcVar2[1] = '\0';
      input = (uint16_t)ovr_uiReadString((char *)0x0,0,6,pcVar2,(uint16_t)in_DX);
      pbStack_a = in_DX;
      init_normalizeName((uint32_t)CONCAT22(in_DX,input));
      if (UserWantsExit != '\0') {
        if (SaveAuto != '\0') {
          ovr_stSave();
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0);
      }
      if (input != 0 || pbStack_a != (byte *)0x0) break;
      attempts = attempts + 0x1;
    }
    _fstricmp((char *)CONCAT22(pbStack_a,input),
              (char *)CONCAT22(*(undefined2 *)((uint)codes * 4 + 0x54e),
                               (char *)*(undefined2 *)((uint)codes * 4 + 0x54c)));
    handle.seg = (uint16_t)pbStack_a;
    handle.ofs = input;
    ovr_stshFree(handle);
    ovr_saveui_blitPanel();
    CopyProtectionDone = '\x01';
  }
  return;
}
