void __cdecl16far ovc38_showAchievements(void)

{
  far_t entries;
  uint16_t in_DX;
  int *piVar1;
  int iVar2;
  uint16_t unaff_DI;
  int iVar3;
  uint16_t uVar4;
  byte *unaff_SS;
  uint8_t menuState;
  uint16_t uStack_66;
  uint16_t uStack_64;
  uint8_t text;
  far_t fStack_a;
  undefined1 *uStack_6;   /* hand fix: dereferenced as *uStack_6 */
  
  fStack_a.ofs = (uint16_t)ovr_stshAlloc(0x18);
  fStack_a.seg = in_DX;
  entries.seg = in_DX;
  entries.ofs = fStack_a.ofs;
  ovc38_loadHighScores(entries);
  ovr_saveui_blitPanel();
  TextBlitX = 0x16;
  TextBlitY = 0xb;
  ovr_blitText((char *)"Great Achievements",(byte *)CONCAT22(Font03.ofs,(char *)0x2410),
               Font03.seg,0xde,0xde,7);
  TextBlitX = 0x16;
  TextBlitY = 0x1a;
  ovr_blitText((char *)"Name",(byte *)CONCAT22(Font03.ofs,(char *)0x2410),Font03.seg,0xde
               ,0xde,7);
  TextBlitX = 0xae;
  ovr_blitText((char *)"Enemies",(byte *)CONCAT22(Font03.ofs,(char *)0x2410),Font03.seg,
               0xde,0xde,7);
  for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
    TextBlitX = 0x16;
    TextBlitY = iVar3 * 0xf + 0x2a;
    uVar4 = fStack_a.seg;
    piVar1 = (int *)((int)fStack_a.ofs + iVar3 * 4);
    if (*piVar1 != 0 || piVar1[1] != 0) {
      piVar1 = (int *)((int)fStack_a.ofs + iVar3 * 4);
      iVar2 = 0;
      uStack_6 = (uint8_t *)CONCAT22(piVar1[1],(uint8_t *)(*piVar1 + 1));
      while (((iVar2 < 0x4f && (*uStack_6 != 0x40)) && (*uStack_6 != 0x0))) {
        (&text)[iVar2] = *uStack_6;
        iVar2 = iVar2 + 1;
        uStack_6 = (uint8_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(uint8_t *)uStack_6 + 1);
      }
      (&text)[iVar2] = 0x0;
      ovr_blitText((char *)&text,(byte *)CONCAT22(Font03.ofs,unaff_SS),Font03.seg,0xde,0xde,8);
      TextBlitX = 0xc2;
      if (*uStack_6 == 0x40) {
        uStack_6 = (uint8_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(uint8_t *)uStack_6 + 1);
      }
      ovr_blitText((char *)(uint8_t *)uStack_6,(byte *)CONCAT22(Font03.ofs,(*(uint16_t *)((uint8_t *)&(uStack_6) + 2))),
                   Font03.seg,0xde,0xde,8);
    }
  }
  _fmemset((void *)ZEXT24(unaff_SS),0x28,unaff_DI);
  uStack_64 = 0x2410;
  uStack_66 = 0x6ab4;
  ovr_uiMenu((char *)0x0,far_from_u32((uint32_t)(ZEXT24(&menuState) << 0x10)));
  ovc38_usesStshFree(fStack_a);
  ovr_saveui_blitPanel();
  return;
}
