void __cdecl16far ovc41_usesGMenuItem(void)

{
  ovr_draw_usesBlitLoadRleGfx2();
  GMenuItem = savedMenuItem;
  MenuMode = MenuModeSaved;
  ovc41_usesAgnt_clear('\0');
  if (5 < GMenuItem) {
    GMenuItem = 5;
  }
  while ((GMenuItem != 5 && (((uint8_t *)MenuItemEnabled)[GMenuItem] == 0xff))) {
    if (GMenuItem == 0) {
      GMenuItem = 5;
    }
    else {
      GMenuItem = GMenuItem - 1;
    }
  }
  if (GameRunning == false) {
    ovr_draw_toolbarLabels();
  }
  ovr_draw_textTalkwin9Lbm();
  (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter))) = *(undefined2 *)BDA_DailyTimeCounter.ofs;
  return;
}
