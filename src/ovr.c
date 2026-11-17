#include "st.h"

/* Overlay entry stubs: 453 forwarder(s). */

/* 1000:1ce9 -> _FakRealCvt */
void __cdecl16far ovr__FakRealCvt(void)
{
    _FakRealCvt();
}

/* 22a6:0020 -> miceButtonsStates */
uint16_t __cdecl16far ovr_miceButtonsStates(void)
{
    return miceButtonsStates();
}

/* 22a6:0025 -> mkp */
uint32_t __cdecl16far ovr_mkp(uint16_t ofs,uint16_t seg)
{
    return mkp(ofs, seg);
}

/* 22a6:002a -> miceButton0PressStates */
uint16_t __cdecl16far ovr_miceButton0PressStates(void)
{
    return miceButton0PressStates();
}

/* 22a6:002f -> biosVideoCall */
uint16_t __cdecl16far ovr_biosVideoCall(uint8_t operation,uint8_t argument)
{
    return biosVideoCall(operation, argument);
}

/* 22a6:0034 -> miceDisableHandler */
void __cdecl16far ovr_miceDisableHandler(void)
{
    miceDisableHandler();
}

/* 22a6:0039 -> driver_2d63_014b */
char __cdecl16far ovr_driver_2d63_014b(char param_1,byte param_2,char param_3)
{
    return driver_2d63_014b(param_1, param_2, param_3);
}

/* 22a6:003e -> driver_2d63_0107 */
char __cdecl16far ovr_driver_2d63_0107(char param_1,byte param_2,char param_3)
{
    return driver_2d63_0107(param_1, param_2, param_3);
}

/* 22a6:0043 -> blitRaw */
void __cdecl16far ovr_blitRaw(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint16_t src,uint16_t dst)
{
    blitRaw(x, y, w, h, src, dst);
}

/* 22a6:0048 -> miceSetPosition */
void __cdecl16far ovr_miceSetPosition(uint16_t col,uint16_t row)
{
    miceSetPosition(col, row);
}

/* 22a6:004d -> be2 */
uint16_t __cdecl16far ovr_be2(uint16_t w)
{
    return be2(w);
}

/* 22a6:0052 -> be4 */
uint32_t __cdecl16far ovr_be4(uint32_t be)
{
    return be4(be);
}

/* 22a6:0057 -> biosReadKey */
uint16_t __cdecl16far ovr_biosReadKey(void)
{
    return biosReadKey();
}

/* 22a6:005c -> lbm_combine_bitplanes */
void __cdecl16far ovr_lbm_combine_bitplanes(far_t src,far_t dst,uint16_t npixels,uint8_t nplanes,uint16_t plane_sz)
{
    lbm_combine_bitplanes(src, dst, npixels, nplanes, plane_sz);
}

/* 22a6:0061 -> biosKeyAvail */
uint16_t __cdecl16far ovr_biosKeyAvail(void)
{
    return biosKeyAvail();
}

/* 22a6:006b -> driver_2d63_0b94 */
uint __cdecl16far ovr_driver_2d63_0b94(uint param_1)
{
    return driver_2d63_0b94(param_1);
}

/* 22a6:008e -> driver_2d63_0a24 */
void __cdecl16far ovr_driver_2d63_0a24(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)
{
    driver_2d63_0a24(param_1, param_2, param_3, param_4, param_5, param_6);
}

/* 22a6:0093 -> driver_2d63_0a67 */
void __cdecl16far ovr_driver_2d63_0a67(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)
{
    driver_2d63_0a67(param_1, param_2, param_3, param_4, param_5, param_6);
}

/* 22a6:0098 -> vda_query */
uint8_t __cdecl16far ovr_vda_query(void)
{
    return vda_query();
}

/* 22a6:009d -> driver_2d63_09c9 */
void __cdecl16far ovr_driver_2d63_09c9(int param_1,int param_2,byte param_3,undefined1 param_4,int *param_5)
{
    driver_2d63_09c9(param_1, param_2, param_3, param_4, param_5);
}

/* 22a6:00a2 -> driver_2d63_0846 */
void __cdecl16far ovr_driver_2d63_0846(undefined2 param_1,byte param_2,undefined2 param_3,byte param_4,undefined2 param_5,byte param_6)
{
    driver_2d63_0846(param_1, param_2, param_3, param_4, param_5, param_6);
}

/* 22a6:00a7 -> midRegisterXMIDI */
void __cdecl16far ovr_midRegisterXMIDI(void)
{
    midRegisterXMIDI();
}

/* 22a6:00ac -> midSetRelativeValue */
void __cdecl16far ovr_midSetRelativeValue(void)
{
    midSetRelativeValue();
}

/* 22a6:00b1 -> midGetSequenceStatus */
void __cdecl16far ovr_midGetSequenceStatus(void)
{
    midGetSequenceStatus();
}

/* 22a6:00b6 -> midIsLoaded */
bool __cdecl16far ovr_midIsLoaded(void)
{
    return midIsLoaded();
}

/* 22a6:00bb -> digSoundPlaying */
bool __cdecl16far ovr_digSoundPlaying(void)
{
    return digSoundPlaying();
}

/* 22a6:00c5 -> midPlaySequence */
void __cdecl16far ovr_midPlaySequence(uint16_t param_1)
{
    midPlaySequence(param_1);
}

/* 22a6:00ca -> midLoadDriver */
void __cdecl16far ovr_midLoadDriver(void)
{
    midLoadDriver();
}

/* 22a6:00cf -> digIsInstalled */
bool __cdecl16far ovr_digIsInstalled(void)
{
    return digIsInstalled();
}

/* 22a6:00d4 -> digPreformatSound */
void __cdecl16far ovr_digPreformatSound(void)
{
    digPreformatSound();
}

/* 22a6:00d9 -> digPlayPreformatedSound */
void __cdecl16far ovr_digPlayPreformatedSound(void)
{
    digPlayPreformatedSound();
}

/* 22a6:00de -> midMidiStop */
void __cdecl16far ovr_midMidiStop(void)
{
    midMidiStop();
}

/* 22a6:00e3 -> digStopCurrentSound */
void __cdecl16far ovr_digStopCurrentSound(void)
{
    digStopCurrentSound();
}

/* 22a6:00ed -> digSetSterioPanning */
void __cdecl16far ovr_digSetSterioPanning(void)
{
    digSetSterioPanning();
}

/* 22a6:00f2 -> driver_2d63_05e5 */
undefined2 __cdecl16far ovr_driver_2d63_05e5(uint param_1,uint param_2,uint param_3,uint param_4,undefined1 param_5,undefined2 param_6)
{
    return driver_2d63_05e5(param_1, param_2, param_3, param_4, param_5, param_6);
}

/* 22a6:00f7 -> driver_2d63_0687 */
void __cdecl16far ovr_driver_2d63_0687(int param_1,byte param_2,undefined1 param_3,undefined1 param_4,undefined2 param_5)
{
    driver_2d63_0687(param_1, param_2, param_3, param_4, param_5);
}

/* 22a6:00fc -> driver_2d63_0652 */
void __cdecl16far ovr_driver_2d63_0652(int param_1,byte param_2,undefined1 param_3,undefined1 param_4,undefined2 param_5)
{
    driver_2d63_0652(param_1, param_2, param_3, param_4, param_5);
}

/* 22a6:0101 -> vga_2d63_04b7 */
void __cdecl16far ovr_vga_2d63_04b7(undefined1 *param_1,int param_2,undefined1 *param_3,int param_4,undefined1 param_5)
{
    vga_2d63_04b7(param_1, param_2, param_3, param_4, param_5);
}

/* 22a6:010b -> grabRemap */
void __cdecl16far ovr_grabRemap(far_t pixels,uint8_t scolor,uint8_t dcolor)
{
    grabRemap(pixels, scolor, dcolor);
}

/* 22a6:0110 -> drawLine2 */
int __cdecl16far ovr_drawLine2(byte *param_1,byte *param_2,int param_3)
{
    return drawLine2(param_1, param_2, param_3);
}

/* 22a6:0115 -> rle_line */
int __cdecl16far ovr_rle_line(uint8_t *src,uint8_t *dst,uint16_t npixels)
{
    return rle_line(src, dst, npixels);
}

/* 22a6:011a -> vgaSetPalette */
undefined1 __cdecl16far ovr_vgaSetPalette(undefined1 *param_1,undefined1 param_2,int param_3)
{
    return vgaSetPalette(param_1, param_2, param_3);
}

/* 22a6:011f -> vgaSetPalette8bit */
undefined1 __cdecl16far ovr_vgaSetPalette8bit(undefined1 *param_1)
{
    return vgaSetPalette8bit(param_1);
}

/* 22a6:0129 -> unrle_mirror */
int __cdecl16far ovr_unrle_mirror(byte *src,byte *dst,int len)
{
    return unrle_mirror(src, dst, len);
}

/* 22a6:012e -> rle_blit_decode */
int __cdecl16far ovr_rle_blit_decode(byte *src,byte *dst,uint16_t sz)
{
    return rle_blit_decode(src, dst, sz);
}

/* 22a6:0133 -> unrle */
int __cdecl16far ovr_unrle(far_t src,far_t dst,uint16_t len)
{
    return unrle(src, dst, len);
}

/* 22a6:0138 -> driver_2d63_044e */
void __cdecl16far ovr_driver_2d63_044e(char *param_1,int param_2,char param_3,byte param_4,undefined4 param_5,uint param_6)
{
    driver_2d63_044e(param_1, param_2, param_3, param_4, param_5, param_6);
}

/* 22a6:013d -> masked_memcpy */
void __cdecl16far ovr_masked_memcpy(char *dst,char *src,int skip,int src_sz,int dst_sz,uint mask)
{
    masked_memcpy(dst, src, skip, src_sz, dst_sz, mask);
}

/* 22bb:0020 -> draw_2e25_046b */
void __cdecl16far ovr_draw_2e25_046b(void)
{
    draw_2e25_046b();
}

/* 22bb:0025 -> draw_2e25_0573 */
void __cdecl16far ovr_draw_2e25_0573(void)
{
    draw_2e25_0573();
}

/* 22bb:002a -> draw_2e25_0245 */
uint __cdecl16far ovr_draw_2e25_0245(int param_1)
{
    return draw_2e25_0245(param_1);
}

/* 22bb:002f -> draw_2e25_15d6 */
char * __cdecl16far ovr_draw_2e25_15d6(void)
{
    return draw_2e25_15d6();
}

/* 22bb:0034 -> draw_2e25_1d7c */
char * __cdecl16far ovr_draw_2e25_1d7c(void)
{
    return draw_2e25_1d7c();
}

/* 22bb:0039 -> draw_2e25_1662 */
void __cdecl16far ovr_draw_2e25_1662(void)
{
    draw_2e25_1662();
}

/* 22bb:003e -> draw_2e25_0938 */
void __cdecl16far ovr_draw_2e25_0938(void)
{
    draw_2e25_0938();
}

/* 22bb:0043 -> draw_2e25_0098 */
void __cdecl16far ovr_draw_2e25_0098(uint param_1,int param_2)
{
    draw_2e25_0098(param_1, param_2);
}

/* 22bb:0048 -> draw_2e25_0000 */
void __cdecl16far ovr_draw_2e25_0000(int param_1,undefined2 param_2)
{
    draw_2e25_0000(param_1, param_2);
}

/* 22bb:0052 -> draw_2e25_0d35 */
uint16_t __cdecl16far ovr_draw_2e25_0d35(void)
{
    return draw_2e25_0d35();
}

/* 22bb:0057 -> draw_2e25_17b3 */
void __cdecl16far ovr_draw_2e25_17b3(void)
{
    draw_2e25_17b3();
}

/* 22bb:005c -> draw_2e25_130a */
void __cdecl16far ovr_draw_2e25_130a(void)
{
    draw_2e25_130a();
}

/* 22bb:0061 -> draw_2e25_025a */
void __cdecl16far ovr_draw_2e25_025a(void)
{
    draw_2e25_025a();
}

/* 22bb:007a -> gameProcessKey */
uint16_t __cdecl16far ovr_gameProcessKey(void)
{
    return gameProcessKey();
}

/* 22bb:007f -> draw_2e25_0efd */
void __cdecl16far ovr_draw_2e25_0efd(int param_1)
{
    draw_2e25_0efd(param_1);
}

/* 22bb:0084 -> draw_2e25_10c7 */
void __cdecl16far ovr_draw_2e25_10c7(int param_1,int param_2)
{
    draw_2e25_10c7(param_1, param_2);
}

/* 22c4:0025 -> stshProcessFontSub */
far_t __cdecl16far ovr_stshProcessFontSub(far_t hndl)
{
    return stshProcessFontSub(hndl);
}

/* 22c4:002a -> blitLetter */
void __cdecl16far ovr_blitLetter(char ch,byte *widths,uint8_t term)
{
    blitLetter(ch, widths, term);
}

/* 22c4:002f -> blitText */
int __cdecl16far ovr_blitText(char *text,byte *widths,uint16_t seg,uint8_t term)
{
    return blitText(text, widths, seg, term);
}

/* 22c4:0034 -> font_302d_06ea */
int __cdecl16far ovr_font_302d_06ea(undefined4 param_1,undefined4 param_2)
{
    return font_302d_06ea(param_1, param_2);
}

/* 22c4:0039 -> uiNotify */
void __cdecl16far ovr_uiNotify(char *msg,uint16_t dst)
{
    uiNotify(msg, dst);
}

/* 22c4:003e -> say */
void __cdecl16far ovr_say(char *msg)
{
    say(msg);
}

/* 22c4:0048 -> font_302d_0a30 */
void __cdecl16far ovr_font_302d_0a30(void)
{
    font_302d_0a30();
}

/* 22c4:004d -> inputUpdate */
uint16_t __cdecl16far ovr_inputUpdate(ulong msg_delay)
{
    return inputUpdate(msg_delay);
}

/* 22c4:0052 -> font_302d_080b */
uint __cdecl16far ovr_font_302d_080b(byte param_1)
{
    return font_302d_080b(param_1);
}

/* 22c4:0057 -> blitLabel */
uint __cdecl16far ovr_blitLabel(char *text,uint8_t *widths,int16_t max_width,uint8_t term)
{
    return blitLabel(text, widths, max_width, term);
}

/* 22c4:005c -> drawTextAt */
void __cdecl16far ovr_drawTextAt(char *txt,uint16_t dst)
{
    drawTextAt(txt, dst);
}

/* 22cb:0020 -> grabLbm */
stg_tmp_t * __cdecl16far ovr_grabLbm(int16_t file_id,int16_t x,int16_t y)
{
    return grabLbm(file_id, x, y);
}

/* 22cb:0025 -> alignToSeg */
far_t __cdecl16far ovr_alignToSeg(far_t ptr)
{
    return alignToSeg(ptr);
}

/* 22ce:0020 -> stExit */
void __cdecl16far ovr_stExit(int n)
{
    stExit(n);
}

/* 22d3:0020 -> stshRleCut */
far_t __cdecl16far ovr_stshRleCut(far_t src,int16_t sx,int16_t sy,int16_t ex,int16_t ey)
{
    return stshRleCut(src, sx, sy, ex, ey);
}

/* 22d3:0025 -> stshRleType2 */
far_t __cdecl16far ovr_stshRleType2(far_t pixels,int16_t sx,int16_t sy,int16_t ex,int16_t ey,int16_t ox,int16_t oy)
{
    return stshRleType2(pixels, sx, sy, ex, ey, ox, oy);
}

/* 22d3:002a -> blitLoadRleGfx */
void __cdecl16far ovr_blitLoadRleGfx(far_t gfx,far_t dst)
{
    blitLoadRleGfx(gfx, dst);
}

/* 22d3:002f -> blitGfx10 */
void __cdecl16far ovr_blitGfx10(far_t gfx,uint16_t x,uint16_t y,brect_t *dst,bool type)
{
    blitGfx10(gfx, x, y, dst, type);
}

/* 22d3:0034 -> blitGfxRect */
void __cdecl16far ovr_blitGfxRect(far_t gfx,int16_t x,int16_t y,brect_t *dst,uint8_t type,bool mirror)
{
    blitGfxRect(gfx, x, y, dst, type, mirror);
}

/* 22d3:0039 -> stshRleSub */
far_t __cdecl16far ovr_stshRleSub(uint8_t *src,uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,int16_t hdrsz)
{
    return stshRleSub(src, sx, sy, ex, ey, hdrsz);
}

/* 22d3:003e -> gfxRlePrepare */
void __cdecl16far ovr_gfxRlePrepare(far_t gfx,int param_2,int param_3,int *param_4,byte param_5,char param_6,char param_7)
{
    gfxRlePrepare(gfx, param_2, param_3, param_4, param_5, param_6, param_7);
}

/* 22d3:0043 -> blit_317e_0db7 */
void __cdecl16far ovr_blit_317e_0db7(uint16_t param_1,uint16_t param_2,int16_t param_3,int param_4,byte param_5,int param_6,byte param_7,brect_t *param_8,undefined2 param_9)
{
    blit_317e_0db7(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}

/* 22d3:0048 -> blit_317e_0f7d */
void __cdecl16far ovr_blit_317e_0f7d(far_t param_1,int param_2,int param_3,byte param_4,int param_5,int param_6,byte param_7,int *param_8,char param_9)
{
    blit_317e_0f7d(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}

/* 22d3:004d -> gfxInitRand */
void __cdecl16far ovr_gfxInitRand(void)
{
    gfxInitRand();
}

/* 22d3:0052 -> blit_317e_1240 */
void __cdecl16far ovr_blit_317e_1240(uint16_t param_1,uint16_t param_2,uint16_t param_3,uint16_t param_4,int param_5,int param_6,byte param_7,int param_8,int param_9,byte param_10,brect_t *param_11,undefined2 param_12,byte param_13)
{
    blit_317e_1240(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}

/* 22d3:0061 -> blitGfxN */
void __cdecl16far ovr_blitGfxN(far_t gfx,int16_t x,int16_t y,brect_t *dst,uint8_t type,bool mirror)
{
    blitGfxN(gfx, x, y, dst, type, mirror);
}

/* 22da:0020 -> OVC07_32c9_0044 */
void __cdecl16far ovr_OVC07_32c9_0044(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,undefined2 param_7,int *param_8)
{
    OVC07_32c9_0044(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}

/* 22da:0025 -> OVC07_32c9_03c4 */
void __cdecl16far ovr_OVC07_32c9_03c4(int param_1,int param_2,int param_3,int param_4,undefined2 param_5,int *param_6)
{
    OVC07_32c9_03c4(param_1, param_2, param_3, param_4, param_5, param_6);
}

/* 22da:002a -> OVC07_32c9_0466 */
void __cdecl16far ovr_OVC07_32c9_0466(int param_1,int param_2,int param_3,int param_4,undefined1 param_5,int *param_6)
{
    OVC07_32c9_0466(param_1, param_2, param_3, param_4, param_5, param_6);
}

/* 22da:002f -> OVC07_32c9_0026 */
undefined2 __cdecl16far ovr_OVC07_32c9_0026(int param_1)
{
    return OVC07_32c9_0026(param_1);
}

/* 22de:0020 -> miceRestoreArea */
void __cdecl16far ovr_miceRestoreArea(brect_t *br)
{
    miceRestoreArea(br);
}

/* 22de:0025 -> miceBlitRect */
void __cdecl16far ovr_miceBlitRect(brect_t *br)
{
    miceBlitRect(br);
}

/* 22de:002a -> miceInit */
void __cdecl16far ovr_miceInit(void)
{
    miceInit();
}

/* 22de:002f -> init2_3338_0388 */
byte __cdecl16far ovr_init2_3338_0388(uint16_t *param_1,uint16_t *param_2)
{
    return init2_3338_0388(param_1, param_2);
}

/* 22de:0034 -> init2_3338_0401 */
void __cdecl16far ovr_init2_3338_0401(void)
{
    init2_3338_0401();
}

/* 22de:0039 -> init2_3338_043e */
void __cdecl16far ovr_init2_3338_043e(void)
{
    init2_3338_043e();
}

/* 22de:003e -> init2_3338_0415 */
uint __cdecl16far ovr_init2_3338_0415(void)
{
    return init2_3338_0415();
}

/* 22de:0043 -> miceUpdate */
void __cdecl16far ovr_miceUpdate(void)
{
    miceUpdate();
}

/* 22de:0048 -> miceSaveArea */
void __cdecl16far ovr_miceSaveArea(uint x,uint y,brect_t *br)
{
    miceSaveArea(x, y, br);
}

/* 22e3:0025 -> init_game */
void __cdecl16far ovr_init_game(void)
{
    init_game();
}

/* 22e3:002a -> init_3381_08dc */
stg_tmp_t * __cdecl16far ovr_init_3381_08dc(undefined4 param_1,int16_t param_2)
{
    return init_3381_08dc(param_1, param_2);
}

/* 22e3:002f -> init_3381_2101 */
void __cdecl16far ovr_init_3381_2101(void)
{
    init_3381_2101();
}

/* 22e3:0034 -> init_3381_20ee */
void __cdecl16far ovr_init_3381_20ee(void)
{
    init_3381_20ee();
}

/* 22e3:0039 -> chpath */
void __cdecl16far ovr_chpath(char *path)
{
    chpath(path);
}

/* 22e3:0043 -> init_3381_0000 */
void __cdecl16far ovr_init_3381_0000(void)
{
    init_3381_0000();
}

/* 22e3:0048 -> path_strip_tail_slash */
char * __cdecl16far ovr_path_strip_tail_slash(char *s)
{
    return path_strip_tail_slash(s);
}

/* 22e3:004d -> init_3381_1fba */
void __cdecl16far ovr_init_3381_1fba(void)
{
    init_3381_1fba();
}

/* 22e3:0052 -> copyProtectionCheck */
void __cdecl16far ovr_copyProtectionCheck(void)
{
    copyProtectionCheck();
}

/* 22e3:0057 -> init_grayscale_palette */
void __cdecl16far ovr_init_grayscale_palette(void)
{
    init_grayscale_palette();
}

/* 22e3:005c -> init_3381_17e8 */
void __cdecl16far ovr_init_3381_17e8(void)
{
    init_3381_17e8();
}

/* 22e3:0061 -> init_3381_2883 */
void __cdecl16far ovr_init_3381_2883(void)
{
    init_3381_2883();
}

/* 22e3:0066 -> init_3381_23b5 */
uint __cdecl16far ovr_init_3381_23b5(int param_1,int param_2)
{
    return init_3381_23b5(param_1, param_2);
}

/* 22e3:006b -> init_3381_2d36 */
void __cdecl16far ovr_init_3381_2d36(void)
{
    init_3381_2d36();
}

/* 22e3:0070 -> ensure_tail_slash */
char * __cdecl16far ovr_ensure_tail_slash(char *s)
{
    return ensure_tail_slash(s);
}

/* 22e3:0075 -> init_paths */
void __cdecl16far ovr_init_paths(void)
{
    init_paths();
}

/* 22e3:007a -> init_cfg_mice */
void __cdecl16far ovr_init_cfg_mice(void)
{
    init_cfg_mice();
}

/* 22e3:007f -> init_cfg */
void __cdecl16far ovr_init_cfg(void)
{
    init_cfg();
}

/* 22e3:0084 -> init_3381_0693 */
void __cdecl16far ovr_init_3381_0693(void)
{
    init_3381_0693();
}

/* 22e3:0089 -> init_3381_1697 */
void __cdecl16far ovr_init_3381_1697(void)
{
    init_3381_1697();
}

/* 22e3:008e -> init_3381_1f1d */
uint __cdecl16far ovr_init_3381_1f1d(int param_1,int param_2)
{
    return init_3381_1f1d(param_1, param_2);
}

/* 22e3:0093 -> init_3381_1fa9 */
void __cdecl16far ovr_init_3381_1fa9(void)
{
    init_3381_1fa9();
}

/* 22e3:0098 -> init_3381_233e */
uint __cdecl16far ovr_init_3381_233e(int param_1,int param_2)
{
    return init_3381_233e(param_1, param_2);
}

/* 22e3:009d -> init_3381_237a */
void __cdecl16far ovr_init_3381_237a(int param_1,int param_2,byte param_3)
{
    init_3381_237a(param_1, param_2, param_3);
}

/* 22e3:00ac -> init_3381_24c3 */
undefined2 __cdecl16far ovr_init_3381_24c3(int param_1,int param_2,char param_3,byte *param_4,byte *param_5)
{
    return init_3381_24c3(param_1, param_2, param_3, param_4, param_5);
}

/* 22ef:002a -> constr_36ce_306b */
uint __cdecl16far ovr_constr_36ce_306b(int param_1,int param_2)
{
    return constr_36ce_306b(param_1, param_2);
}

/* 22ef:0034 -> constr_36ce_03a6 */
void __cdecl16far ovr_constr_36ce_03a6(void)
{
    constr_36ce_03a6();
}

/* 22ef:0039 -> constr_36ce_1db4 */
void __cdecl16far ovr_constr_36ce_1db4(void)
{
    constr_36ce_1db4();
}

/* 22ef:003e -> blitRect */
void __cdecl16far ovr_blitRect(brect_t *br)
{
    blitRect(br);
}

/* 22ef:0048 -> constr_36ce_1efc */
void __cdecl16far ovr_constr_36ce_1efc(void)
{
    constr_36ce_1efc();
}

/* 22ef:004d -> constr_36ce_04e9 */
void __cdecl16far ovr_constr_36ce_04e9(undefined2 param_1,undefined2 param_2)
{
    constr_36ce_04e9(param_1, param_2);
}

/* 22ef:0057 -> constr_36ce_049f */
undefined2 __cdecl16far ovr_constr_36ce_049f(undefined1 param_1,undefined1 param_2,undefined1 param_3,byte param_4,byte param_5)
{
    return constr_36ce_049f(param_1, param_2, param_3, param_4, param_5);
}

/* 22ef:005c -> constr_36ce_08ee */
void __cdecl16far ovr_constr_36ce_08ee(brect_t *param_1,undefined2 param_2)
{
    constr_36ce_08ee(param_1, param_2);
}

/* 22ef:0061 -> constr_36ce_3172 */
undefined2 __cdecl16far ovr_constr_36ce_3172(int param_1,int param_2)
{
    return constr_36ce_3172(param_1, param_2);
}

/* 22ef:0070 -> constr_36ce_0101 */
int __cdecl16far ovr_constr_36ce_0101(undefined2 param_1,int param_2,int *param_3)
{
    return constr_36ce_0101(param_1, param_2, param_3);
}

/* 22ef:0075 -> constr_36ce_0159 */
byte __cdecl16far ovr_constr_36ce_0159(int param_1,int param_2)
{
    return constr_36ce_0159(param_1, param_2);
}

/* 22f8:0020 -> play_sfx */
void __cdecl16far ovr_play_sfx(int16_t track,int16_t type)
{
    play_sfx(track, type);
}

/* 22f8:0025 -> sfxInit */
void __cdecl16far ovr_sfxInit(void)
{
    sfxInit();
}

/* 22f8:002a -> stop_audio */
void __cdecl16far ovr_stop_audio(void)
{
    stop_audio();
}

/* 22f8:002f -> play_sfxU */
void __cdecl16far ovr_play_sfxU(byte fid,int type,uint16_t unk)
{
    play_sfxU(fid, type, unk);
}

/* 22f8:0034 -> audio_3a5b_034e */
undefined2 __cdecl16far ovr_audio_3a5b_034e(void)
{
    return audio_3a5b_034e();
}

/* 22f8:0039 -> fmFreeAudio */
bool __cdecl16far ovr_fmFreeAudio(uint16_t force)
{
    return fmFreeAudio(force);
}

/* 22f8:003e -> audio_3a5b_0000 */
void __cdecl16far ovr_audio_3a5b_0000(void)
{
    audio_3a5b_0000();
}

/* 22f8:0043 -> audio_3a5b_037e */
uint __cdecl16far ovr_audio_3a5b_037e(void)
{
    return audio_3a5b_037e();
}

/* 22f8:0048 -> audio_3a5b_0afd */
int __cdecl16far ovr_audio_3a5b_0afd(int *param_1)
{
    return audio_3a5b_0afd(param_1);
}

/* 22f8:005c -> musInit */
void __cdecl16far ovr_musInit(void)
{
    musInit();
}

/* 22ff:0020 -> agnt_3b1d_1ad8 */
void __cdecl16far ovr_agnt_3b1d_1ad8(void)
{
    agnt_3b1d_1ad8();
}

/* 22ff:0025 -> agnt_3b1d_19e0 */
void __cdecl16far ovr_agnt_3b1d_19e0(void)
{
    agnt_3b1d_19e0();
}

/* 22ff:002a -> agnt_3b1d_196b */
void __cdecl16far ovr_agnt_3b1d_196b(far_t ptr)
{
    agnt_3b1d_196b(ptr);
}

/* 22ff:002f -> agnt_3b1d_0ac0 */
char * __cdecl16far ovr_agnt_3b1d_0ac0(undefined4 param_1,char *param_2)
{
    return agnt_3b1d_0ac0(param_1, param_2);
}

/* 22ff:0034 -> agnt_3b1d_0a53 */
void __cdecl16far ovr_agnt_3b1d_0a53(undefined4 param_1)
{
    agnt_3b1d_0a53(param_1);
}

/* 22ff:0039 -> agnt_3b1d_005e */
int __cdecl16far ovr_agnt_3b1d_005e(int param_1)
{
    return agnt_3b1d_005e(param_1);
}

/* 22ff:003e -> agnt_3b1d_0c1e */
undefined2 __cdecl16far ovr_agnt_3b1d_0c1e(byte param_1,byte param_2)
{
    return agnt_3b1d_0c1e(param_1, param_2);
}

/* 22ff:0043 -> agnt_3b1d_0c9f */
byte __cdecl16far ovr_agnt_3b1d_0c9f(undefined4 param_1)
{
    return agnt_3b1d_0c9f(param_1);
}

/* 22ff:0048 -> agnt_3b1d_0c7c */
byte __cdecl16far ovr_agnt_3b1d_0c7c(undefined4 param_1)
{
    return agnt_3b1d_0c7c(param_1);
}

/* 22ff:004d -> agnt_3b1d_1bc1 */
byte __cdecl16far ovr_agnt_3b1d_1bc1(byte param_1)
{
    return agnt_3b1d_1bc1(param_1);
}

/* 22ff:0052 -> agnt_3b1d_0cef */
byte __cdecl16far ovr_agnt_3b1d_0cef(undefined4 param_1)
{
    return agnt_3b1d_0cef(param_1);
}

/* 22ff:0057 -> agnt_3b1d_0cc6 */
byte __cdecl16far ovr_agnt_3b1d_0cc6(undefined4 param_1)
{
    return agnt_3b1d_0cc6(param_1);
}

/* 22ff:0061 -> agnt_3b1d_1c26 */
undefined2 __cdecl16far ovr_agnt_3b1d_1c26(undefined4 param_1,char *param_2)
{
    return agnt_3b1d_1c26(param_1, param_2);
}

/* 22ff:0066 -> agnt_3b1d_11c1 */
void __cdecl16far ovr_agnt_3b1d_11c1(undefined4 param_1)
{
    agnt_3b1d_11c1(param_1);
}

/* 22ff:006b -> agnt_3b1d_1da5 */
undefined1 __cdecl16far ovr_agnt_3b1d_1da5(undefined4 param_1,undefined4 param_2)
{
    return agnt_3b1d_1da5(param_1, param_2);
}

/* 22ff:0070 -> agnt_3b1d_0426 */
undefined1 __cdecl16far ovr_agnt_3b1d_0426(int *param_1,byte *param_2,char param_3)
{
    return agnt_3b1d_0426(param_1, param_2, param_3);
}

/* 22ff:0075 -> agnt_3b1d_00ce */
undefined1 __cdecl16far ovr_agnt_3b1d_00ce(int *param_1,undefined1 *param_2)
{
    return agnt_3b1d_00ce(param_1, param_2);
}

/* 22ff:007a -> agnt_3b1d_00b7 */
bool __cdecl16far ovr_agnt_3b1d_00b7(char *param_1)
{
    return agnt_3b1d_00b7(param_1);
}

/* 22ff:0089 -> agnt_3b1d_177f */
undefined2 __cdecl16far ovr_agnt_3b1d_177f(int param_1)
{
    return agnt_3b1d_177f(param_1);
}

/* 22ff:0093 -> agnt_3b1d_093e */
bool __cdecl16far ovr_agnt_3b1d_093e(int *param_1,undefined2 *param_2,undefined2 *param_3,uint *param_4)
{
    return agnt_3b1d_093e(param_1, param_2, param_3, param_4);
}

/* 22ff:009d -> agnt_3b1d_0a9f */
void __cdecl16far ovr_agnt_3b1d_0a9f(undefined4 param_1)
{
    agnt_3b1d_0a9f(param_1);
}

/* 22ff:00a2 -> agnt_3b1d_0d1c */
undefined1 __cdecl16far ovr_agnt_3b1d_0d1c(undefined4 param_1)
{
    return agnt_3b1d_0d1c(param_1);
}

/* 22ff:00a7 -> agnt_3b1d_0d4d */
uint __cdecl16far ovr_agnt_3b1d_0d4d(uint *param_1,int *param_2)
{
    return agnt_3b1d_0d4d(param_1, param_2);
}

/* 22ff:00ac -> agnt_3b1d_0d82 */
void __cdecl16far ovr_agnt_3b1d_0d82(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
    agnt_3b1d_0d82(param_1, param_2, param_3);
}

/* 22ff:00b1 -> agnt_3b1d_1035 */
void __cdecl16far ovr_agnt_3b1d_1035(byte param_1,brect_t *param_2,undefined2 param_3)
{
    agnt_3b1d_1035(param_1, param_2, param_3);
}

/* 22ff:00bb -> agnt_3b1d_15bd */
void __cdecl16far ovr_agnt_3b1d_15bd(uint param_1)
{
    agnt_3b1d_15bd(param_1);
}

/* 22ff:00c5 -> agnt_3b1d_16cd */
void __cdecl16far ovr_agnt_3b1d_16cd(int param_1)
{
    agnt_3b1d_16cd(param_1);
}

/* 230c:0020 -> OVC13_3d16_1558 */
void __cdecl16far ovr_OVC13_3d16_1558(void)
{
    OVC13_3d16_1558();
}

/* 230c:0025 -> OVC13_3d16_08ee */
void __cdecl16far ovr_OVC13_3d16_08ee(void)
{
    OVC13_3d16_08ee();
}

/* 230c:002a -> OVC13_3d16_1945 */
void __cdecl16far ovr_OVC13_3d16_1945(int param_1,int param_2,char param_3)
{
    OVC13_3d16_1945(param_1, param_2, param_3);
}

/* 230c:002f -> OVC13_3d16_1a01 */
void __cdecl16far ovr_OVC13_3d16_1a01(int param_1,int param_2,char param_3)
{
    OVC13_3d16_1a01(param_1, param_2, param_3);
}

/* 230c:0034 -> OVC13_3d16_1abd */
void __cdecl16far ovr_OVC13_3d16_1abd(void)
{
    OVC13_3d16_1abd();
}

/* 230c:0039 -> OVC13_3d16_0000 */
void __cdecl16far ovr_OVC13_3d16_0000(void)
{
    OVC13_3d16_0000();
}

/* 230c:004d -> OVC13_3d16_005b */
void __cdecl16far ovr_OVC13_3d16_005b(void)
{
    OVC13_3d16_005b();
}

/* 2315:0020 -> attact_3f0b_0685 */
void __cdecl16far ovr_attact_3f0b_0685(void)
{
    attact_3f0b_0685();
}

/* 2315:0025 -> attact_3f0b_05df */
void __cdecl16far ovr_attact_3f0b_05df(void)
{
    attact_3f0b_05df();
}

/* 2315:002a -> attact_3f0b_057a */
void __cdecl16far ovr_attact_3f0b_057a(void)
{
    attact_3f0b_057a();
}

/* 2315:002f -> attact_3f0b_251d */
void __cdecl16far ovr_attact_3f0b_251d(void)
{
    attact_3f0b_251d();
}

/* 2315:0034 -> attact_3f0b_082f */
ulong __cdecl16far ovr_attact_3f0b_082f(ulong param_1)
{
    return attact_3f0b_082f(param_1);
}

/* 2315:0039 -> attact_3f0b_18fe */
void __cdecl16far ovr_attact_3f0b_18fe(int param_1,int param_2)
{
    attact_3f0b_18fe(param_1, param_2);
}

/* 2315:003e -> attact_3f0b_21ef */
undefined2 __cdecl16far ovr_attact_3f0b_21ef(byte param_1)
{
    return attact_3f0b_21ef(param_1);
}

/* 2315:0043 -> attact_3f0b_0540 */
undefined2 __cdecl16far ovr_attact_3f0b_0540(int param_1)
{
    return attact_3f0b_0540(param_1);
}

/* 2315:0048 -> attact_3f0b_0451 */
int __cdecl16far ovr_attact_3f0b_0451(byte param_1)
{
    return attact_3f0b_0451(param_1);
}

/* 2315:004d -> attact_3f0b_2252 */
void __cdecl16far ovr_attact_3f0b_2252(byte param_1,byte *param_2,char *param_3,char *param_4)
{
    attact_3f0b_2252(param_1, param_2, param_3, param_4);
}

/* 2315:0052 -> attact_3f0b_2303 */
void __cdecl16far ovr_attact_3f0b_2303(undefined4 param_1,byte param_2,byte *param_3,char *param_4,char *param_5)
{
    attact_3f0b_2303(param_1, param_2, param_3, param_4, param_5);
}

/* 2315:0057 -> attact_3f0b_2430 */
void __cdecl16far ovr_attact_3f0b_2430(int *param_1,byte param_2)
{
    attact_3f0b_2430(param_1, param_2);
}

/* 2315:005c -> attact_3f0b_0585 */
int __cdecl16far ovr_attact_3f0b_0585(int param_1,int param_2)
{
    return attact_3f0b_0585(param_1, param_2);
}

/* 2315:0061 -> attact_3f0b_0000 */
uint __cdecl16far ovr_attact_3f0b_0000(uint param_1,int param_2)
{
    return attact_3f0b_0000(param_1, param_2);
}

/* 2315:006b -> attact_3f0b_01ec */
undefined2 __cdecl16far ovr_attact_3f0b_01ec(int param_1,int param_2)
{
    return attact_3f0b_01ec(param_1, param_2);
}

/* 2315:0070 -> attact_3f0b_26bd */
void __cdecl16far ovr_attact_3f0b_26bd(void)
{
    attact_3f0b_26bd();
}

/* 2315:0075 -> attact_3f0b_2a09 */
void __cdecl16far ovr_attact_3f0b_2a09(void)
{
    attact_3f0b_2a09();
}

/* 2315:007a -> attact_3f0b_0ade */
void __cdecl16far ovr_attact_3f0b_0ade(int param_1,uint16_t param_2,uint16_t param_3,undefined2 param_4,undefined2 param_5)
{
    attact_3f0b_0ade(param_1, param_2, param_3, param_4, param_5);
}

/* 2315:007f -> attact_3f0b_0c2a */
void __stdcall16far ovr_attact_3f0b_0c2a(void)
{
    attact_3f0b_0c2a();
}

/* 2315:0084 -> attact_3f0b_027d */
uint __cdecl16far ovr_attact_3f0b_027d(int param_1,int param_2,byte param_3,char param_4)
{
    return attact_3f0b_027d(param_1, param_2, param_3, param_4);
}

/* 2315:00a2 -> attact_3f0b_0941 */
void __cdecl16far ovr_attact_3f0b_0941(undefined2 param_1,uint16_t param_2,char param_3,undefined4 param_4)
{
    attact_3f0b_0941(param_1, param_2, param_3, param_4);
}

/* 2322:0020 -> OVC15_4207_10a3 */
entity_t * __cdecl16far ovr_OVC15_4207_10a3(uint16_t param_1,uint16_t param_2,uint16_t param_3,uint16_t param_4,byte param_5,uint8_t param_6,byte param_7)
{
    return OVC15_4207_10a3(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

/* 2322:0025 -> OVC15_4207_1c16 */
uint8_t * __cdecl16far ovr_OVC15_4207_1c16(char *param_1)
{
    return OVC15_4207_1c16(param_1);
}

/* 2322:002a -> OVC15_4207_1c79 */
char * __cdecl16far ovr_OVC15_4207_1c79(char *param_1,char *param_2)
{
    return OVC15_4207_1c79(param_1, param_2);
}

/* 2322:002f -> stshInitSprites */
void __cdecl16far ovr_stshInitSprites(bool grab)
{
    stshInitSprites(grab);
}

/* 2322:0034 -> OVC15_4207_0e17 */
void __cdecl16far ovr_OVC15_4207_0e17(uint param_1)
{
    OVC15_4207_0e17(param_1);
}

/* 2322:0039 -> OVC15_4207_0b55 */
void __cdecl16far ovr_OVC15_4207_0b55(uint param_1)
{
    OVC15_4207_0b55(param_1);
}

/* 2322:003e -> OVC15_4207_2301 */
char * __cdecl16far ovr_OVC15_4207_2301(int param_1)
{
    return OVC15_4207_2301(param_1);
}

/* 2322:0043 -> OVC15_4207_0b88 */
void __cdecl16far ovr_OVC15_4207_0b88(void)
{
    OVC15_4207_0b88();
}

/* 2322:0048 -> allocSprSeqs */
void __cdecl16far ovr_allocSprSeqs(void)
{
    allocSprSeqs();
}

/* 2322:004d -> OVC15_4207_25dd */
entity_t * __cdecl16far ovr_OVC15_4207_25dd(code *param_1,int *param_2,int *param_3,undefined2 param_4,undefined2 param_5,int *param_6,int *param_7,int *param_8,int *param_9)
{
    return OVC15_4207_25dd(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}

/* 2322:0052 -> OVC15_4207_26bc */
char * __cdecl16far ovr_OVC15_4207_26bc(code *param_1,char *param_2)
{
    return OVC15_4207_26bc(param_1, param_2);
}

/* 2322:0057 -> OVC15_4207_288b */
bool __cdecl16far ovr_OVC15_4207_288b(void)
{
    return OVC15_4207_288b();
}

/* 2322:0075 -> OVC15_4207_1aae */
void __cdecl16far ovr_OVC15_4207_1aae(int param_1)
{
    OVC15_4207_1aae(param_1);
}

/* 2322:007a -> OVC15_4207_16a5 */
void __cdecl16far ovr_OVC15_4207_16a5(int param_1,byte param_2,char param_3)
{
    OVC15_4207_16a5(param_1, param_2, param_3);
}

/* 2322:0093 -> agnt_clear */
void __cdecl16far ovr_agnt_clear(void)
{
    agnt_clear();
}

/* 2322:0098 -> OVC15_4207_0bb7 */
void __cdecl16far ovr_OVC15_4207_0bb7(void)
{
    OVC15_4207_0bb7();
}

/* 232e:0020 -> uiMainMenuLoop */
void __cdecl16far ovr_uiMainMenuLoop(void)
{
    uiMainMenuLoop();
}

/* 232e:0025 -> saveui_4528_0533 */
void __cdecl16far ovr_saveui_4528_0533(void)
{
    saveui_4528_0533();
}

/* 232e:002a -> uiMenu */
void __cdecl16far ovr_uiMenu(char *title,far_t items,int nitems)
{
    uiMenu(title, items, nitems);
}

/* 232e:002f -> uiReadString */
undefined2 __cdecl16far ovr_uiReadString(char *param_1,int param_2,int param_3,char *param_4,uint16_t param_5)
{
    return uiReadString(param_1, param_2, param_3, param_4, param_5);
}

/* 232e:0034 -> saveui_4528_1104 */
undefined2 __cdecl16far ovr_saveui_4528_1104(int param_1)
{
    return saveui_4528_1104(param_1);
}

/* 232e:0039 -> saveui_4528_10c5 */
void __cdecl16far ovr_saveui_4528_10c5(int param_1,char *param_2,int param_3)
{
    saveui_4528_10c5(param_1, param_2, param_3);
}

/* 232e:0043 -> uiReadKey2 */
uint16_t __cdecl16far ovr_uiReadKey2(void)
{
    return uiReadKey2();
}

/* 2337:0020 -> stshLoadGfx */
stg_tmp_t * __cdecl16far ovr_stshLoadGfx(far_t handle)
{
    return stshLoadGfx(handle);
}

/* 2337:0025 -> stash_474a_10ac */
stg_tmp_t * __cdecl16far ovr_stash_474a_10ac(stg_tmp_t *param_1,byte param_2)
{
    return stash_474a_10ac(param_1, param_2);
}

/* 2337:002a -> stshOpen */
uint16_t __cdecl16far ovr_stshOpen(uint16_t file_id)
{
    return stshOpen(file_id);
}

/* 2337:002f -> stshClose */
void __cdecl16far ovr_stshClose(uint16_t file_id)
{
    stshClose(file_id);
}

/* 2337:0034 -> stshInit */
void __cdecl16far ovr_stshInit(void)
{
    stshInit();
}

/* 2337:003e -> stshSeek */
void __cdecl16far ovr_stshSeek(uint16_t fid,long ofs)
{
    stshSeek(fid, ofs);
}

/* 2337:0048 -> stshRealloc */
uint8_t * __cdecl16far ovr_stshRealloc(uint32_t oldblock,uint32_t nbytes)
{
    return stshRealloc(oldblock, nbytes);
}

/* 2337:004d -> fmVsprintf */
char * __cdecl16far ovr_fmVsprintf(char *fmt,char *arg)
{
    return fmVsprintf(fmt, arg);
}

/* 2337:0052 -> initStshTables */
void __cdecl16far ovr_initStshTables(void)
{
    initStshTables();
}

/* 2337:0057 -> stshFilesize */
uint32_t __cdecl16far ovr_stshFilesize(uint16_t file_id)
{
    return stshFilesize(file_id);
}

/* 2337:005c -> randBelow */
uint16_t __cdecl16far ovr_randBelow(uint16_t n)
{
    return randBelow(n);
}

/* 2337:0061 -> creat_wait_unlock_and_disk */
int __cdecl16far ovr_creat_wait_unlock_and_disk(char *path)
{
    return creat_wait_unlock_and_disk(path);
}

/* 2337:0066 -> open_wait_unlock_and_disk */
int __cdecl16far ovr_open_wait_unlock_and_disk(char *filename)
{
    return open_wait_unlock_and_disk(filename);
}

/* 2337:006b -> clean_ring_buffer */
void __cdecl16far ovr_clean_ring_buffer(void)
{
    clean_ring_buffer();
}

/* 2337:0070 -> stshFree */
void __cdecl16far ovr_stshFree(far_t handle)
{
    stshFree(handle);
}

/* 2337:007a -> stsprintf */
char * __cdecl16far ovr_stsprintf(char *buf,char *fmt,char *arg1)
{
    return stsprintf(buf, fmt, arg1);
}

/* 2337:007f -> stash_474a_0e9b */
uint8_t * __cdecl16far ovr_stash_474a_0e9b(undefined4 param_1)
{
    return stash_474a_0e9b(param_1);
}

/* 2337:008e -> fmFree */
void __cdecl16far ovr_fmFree(void)
{
    fmFree();
}

/* 2337:0093 -> fmReadIntoHimem */
void __cdecl16far ovr_fmReadIntoHimem(char *param_1,undefined2 param_2,int param_3,int param_4,char param_5,undefined2 param_6,undefined2 param_7)
{
    fmReadIntoHimem(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

/* 2337:0098 -> stshTell */
uint32_t __cdecl16far ovr_stshTell(uint16_t file_id)
{
    return stshTell(file_id);
}

/* 2337:009d -> fmRewindHeapPtr */
void __cdecl16far ovr_fmRewindHeapPtr(void)
{
    fmRewindHeapPtr();
}

/* 2342:0020 -> OVC18_48ac_0051 */
void __cdecl16far ovr_OVC18_48ac_0051(void)
{
    OVC18_48ac_0051();
}

/* 2342:0025 -> OVC18_48ac_05f2 */
void __cdecl16far ovr_OVC18_48ac_05f2(char param_1)
{
    OVC18_48ac_05f2(param_1);
}

/* 2342:002a -> OVC18_48ac_0382 */
char * __cdecl16far ovr_OVC18_48ac_0382(far_t param_1,int *param_2,int *param_3,undefined2 param_4,undefined2 param_5,int *param_6,int *param_7,int *param_8,int *param_9)
{
    return OVC18_48ac_0382(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}

/* 2342:002f -> OVC18_48ac_1022 */
char * __cdecl16far ovr_OVC18_48ac_1022(undefined2 param_1,uint16_t param_2)
{
    return OVC18_48ac_1022(param_1, param_2);
}

/* 2342:0034 -> OVC18_48ac_0bf4 */
uint __cdecl16far ovr_OVC18_48ac_0bf4(int param_1,int param_2,byte param_3,byte param_4)
{
    return OVC18_48ac_0bf4(param_1, param_2, param_3, param_4);
}

/* 2342:0043 -> OVC18_48ac_0027 */
void __cdecl16far ovr_OVC18_48ac_0027(void)
{
    OVC18_48ac_0027();
}

/* 2347:0020 -> save_49fd_081e */
undefined1 __cdecl16far ovr_save_49fd_081e(void)
{
    return save_49fd_081e();
}

/* 2347:0025 -> stSave */
undefined2 __cdecl16far ovr_stSave(void)
{
    return stSave();
}

/* 2347:002a -> save_49fd_0f26 */
void __cdecl16far ovr_save_49fd_0f26(void)
{
    save_49fd_0f26();
}

/* 2347:002f -> save_49fd_0863 */
undefined1 __cdecl16far ovr_save_49fd_0863(void)
{
    return save_49fd_0863();
}

/* 234c:0020 -> OVC20_4b0a_010c */
void __cdecl16far ovr_OVC20_4b0a_010c(void)
{
    OVC20_4b0a_010c();
}

/* 234c:002a -> OVC20_4b0a_112d */
void __cdecl16far ovr_OVC20_4b0a_112d(int param_1,undefined2 param_2)
{
    OVC20_4b0a_112d(param_1, param_2);
}

/* 234c:0034 -> stshWrite */
uint32_t __cdecl16far ovr_stshWrite(uint8_t *data,long sz)
{
    return stshWrite(data, sz);
}

/* 234c:0043 -> stshInitAudioAssets */
void __cdecl16far ovr_stshInitAudioAssets(char grab)
{
    stshInitAudioAssets(grab);
}

/* 234c:0048 -> stshLoadAudioDrivers */
void __cdecl16far ovr_stshLoadAudioDrivers(bool grab)
{
    stshLoadAudioDrivers(grab);
}

/* 234c:004d -> stshWriteFile */
void __cdecl16far ovr_stshWriteFile(int fhandle,far_t buf,DW sz)
{
    stshWriteFile(fhandle, buf, sz);
}

/* 234c:0052 -> stshReadFile */
void __cdecl16far ovr_stshReadFile(int handle,far_t dst,DW nbytes)
{
    stshReadFile(handle, dst, nbytes);
}

/* 234c:0057 -> grabBldLbm */
void __cdecl16far ovr_grabBldLbm(int16_t file_normal,int16_t file_ruin,uint16_t index)
{
    grabBldLbm(file_normal, file_ruin, index);
}

/* 234c:005c -> grabLbmTR */
stg_tmp_t * __cdecl16far ovr_grabLbmTR(int16_t file_id)
{
    return grabLbmTR(file_id);
}

/* 234c:0061 -> stshUniqueColorsRemap */
void __cdecl16far ovr_stshUniqueColorsRemap(stg_tmp_t *gfx)
{
    stshUniqueColorsRemap(gfx);
}

/* 234c:0066 -> stgFreeTmp */
void __cdecl16far ovr_stgFreeTmp(stg_tmp_t *tg)
{
    stgFreeTmp(tg);
}

/* 234c:006b -> stubyBufSrcToDst */
void __cdecl16far ovr_stubyBufSrcToDst(int src,int dst)
{
    stubyBufSrcToDst(src, dst);
}

/* 234c:0070 -> stshStubifyFromSrc */
void __cdecl16far ovr_stshStubifyFromSrc(int src,int dst)
{
    stshStubifyFromSrc(src, dst);
}

/* 234c:0075 -> stshStubifyCopy1to0 */
void __cdecl16far ovr_stshStubifyCopy1to0(int index)
{
    stshStubifyCopy1to0(index);
}

/* 234c:0084 -> init_ui_gfxes */
void __cdecl16far ovr_init_ui_gfxes(void)
{
    init_ui_gfxes();
}

/* 234c:0089 -> StubifyCopy1to0_alt */
void __cdecl16far ovr_StubifyCopy1to0_alt(int index)
{
    StubifyCopy1to0_alt(index);
}

/* 234c:008e -> stshSpriteStub */
spr_t * __cdecl16far ovr_stshSpriteStub(anm_t *anms,uint16_t nanims)
{
    return stshSpriteStub(anms, nanims);
}

/* 2356:0020 -> manage_4d05_1835 */
void __cdecl16far ovr_manage_4d05_1835(void)
{
    manage_4d05_1835();
}

/* 2356:0025 -> manage_4d05_01d4 */
void __cdecl16far ovr_manage_4d05_01d4(char_sheet_t *sheet)
{
    manage_4d05_01d4(sheet);
}

/* 2356:002a -> manage_4d05_023a */
char * __cdecl16far ovr_manage_4d05_023a(int param_1)
{
    return manage_4d05_023a(param_1);
}

/* 2356:0034 -> manage_4d05_1b1d */
byte __cdecl16far ovr_manage_4d05_1b1d(void)
{
    return manage_4d05_1b1d();
}

/* 2356:0039 -> manage_4d05_03a4 */
void * __cdecl16far ovr_manage_4d05_03a4(char_sheet_t *sheet)
{
    return manage_4d05_03a4(sheet);
}

/* 2356:003e -> manage_4d05_044e */
uint __cdecl16far ovr_manage_4d05_044e(void)
{
    return manage_4d05_044e();
}

/* 2356:0043 -> litoa10 */
char * __cdecl16far ovr_litoa10(char *buf,long n)
{
    return litoa10(buf, n);
}

/* 2356:0048 -> manage_4d05_0081 */
void __cdecl16far ovr_manage_4d05_0081(void)
{
    manage_4d05_0081();
}

/* 2356:004d -> manage_4d05_0000 */
void __cdecl16far ovr_manage_4d05_0000(void)
{
    manage_4d05_0000();
}

/* 2356:0052 -> manage_4d05_17c7 */
void __cdecl16far ovr_manage_4d05_17c7(undefined1 param_1)
{
    manage_4d05_17c7(param_1);
}

/* 2356:0057 -> manage_4d05_01a3 */
char __cdecl16far ovr_manage_4d05_01a3(char param_1,byte param_2)
{
    return manage_4d05_01a3(param_1, param_2);
}

/* 2356:005c -> manage_4d05_118b */
undefined1 __cdecl16far ovr_manage_4d05_118b(byte param_1)
{
    return manage_4d05_118b(param_1);
}

/* 2363:0020 -> OVC22_5087_4dd9 */
void __cdecl16far ovr_OVC22_5087_4dd9(void)
{
    OVC22_5087_4dd9();
}

/* 2363:0025 -> OVC22_5087_503d */
undefined2 __cdecl16far ovr_OVC22_5087_503d(byte param_1,byte param_2)
{
    return OVC22_5087_503d(param_1, param_2);
}

/* 2363:002a -> upd_units_5087_1d7d */
void __cdecl16far ovr_upd_units_5087_1d7d(void)
{
    upd_units_5087_1d7d();
}

/* 2363:002f -> OVC22_5087_056e */
far_t * __cdecl16far ovr_OVC22_5087_056e(byte param_1,far_t *param_2,undefined2 param_3,undefined1 *param_4,undefined2 param_5,undefined1 param_6,char param_7)
{
    return OVC22_5087_056e(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

/* 2363:0034 -> OVC22_5087_197d */
char __cdecl16far ovr_OVC22_5087_197d(char param_1)
{
    return OVC22_5087_197d(param_1);
}

/* 2363:0039 -> OVC22_5087_4975 */
void __cdecl16far ovr_OVC22_5087_4975(byte param_1,undefined2 param_2,undefined2 param_3)
{
    OVC22_5087_4975(param_1, param_2, param_3);
}

/* 2363:003e -> OVC22_5087_0119 */
char * __cdecl16far ovr_OVC22_5087_0119(byte param_1)
{
    return OVC22_5087_0119(param_1);
}

/* 2363:0057 -> OVC22_5087_0234 */
char * __cdecl16far ovr_OVC22_5087_0234(byte param_1,byte param_2,undefined4 param_3)
{
    return OVC22_5087_0234(param_1, param_2, param_3);
}

/* 2363:005c -> OVC22_5087_0411 */
uint __cdecl16far ovr_OVC22_5087_0411(byte param_1,undefined1 param_2)
{
    return OVC22_5087_0411(param_1, param_2);
}

/* 236f:0020 -> OVC23_55fe_0863 */
void __cdecl16far ovr_OVC23_55fe_0863(uint16_t param_1,uint16_t param_2)
{
    OVC23_55fe_0863(param_1, param_2);
}

/* 236f:0025 -> OVC23_55fe_0000 */
byte * __cdecl16far ovr_OVC23_55fe_0000(uint param_1,undefined2 param_2,undefined4 param_3)
{
    return OVC23_55fe_0000(param_1, param_2, param_3);
}

/* 236f:002a -> OVC23_55fe_1e87 */
void __cdecl16far ovr_OVC23_55fe_1e87(undefined1 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,undefined1 param_6)
{
    OVC23_55fe_1e87(param_1, param_2, param_3, param_4, param_5, param_6);
}

/* 236f:002f -> OVC23_55fe_1803 */
void __cdecl16far ovr_OVC23_55fe_1803(int param_1)
{
    OVC23_55fe_1803(param_1);
}

/* 236f:0034 -> OVC23_55fe_05db */
undefined2 __cdecl16far ovr_OVC23_55fe_05db(undefined2 param_1,int param_2)
{
    return OVC23_55fe_05db(param_1, param_2);
}

/* 236f:0039 -> OVC23_55fe_2937 */
uint __cdecl16far ovr_OVC23_55fe_2937(int param_1,int param_2)
{
    return OVC23_55fe_2937(param_1, param_2);
}

/* 236f:003e -> OVC23_55fe_184e */
void __cdecl16far ovr_OVC23_55fe_184e(byte param_1,int param_2,int param_3,undefined1 *param_4,byte param_5,char param_6)
{
    OVC23_55fe_184e(param_1, param_2, param_3, param_4, param_5, param_6);
}

/* 236f:0043 -> OVC23_55fe_0f39 */
void __cdecl16far ovr_OVC23_55fe_0f39(int param_1,int param_2)
{
    OVC23_55fe_0f39(param_1, param_2);
}

/* 236f:0048 -> OVC23_55fe_0af5 */
uint * __cdecl16far ovr_OVC23_55fe_0af5(int param_1,uint *param_2,byte param_3)
{
    return OVC23_55fe_0af5(param_1, param_2, param_3);
}

/* 236f:004d -> OVC23_55fe_2b82 */
void __cdecl16far ovr_OVC23_55fe_2b82(void)
{
    OVC23_55fe_2b82();
}

/* 236f:0052 -> OVC23_55fe_1005 */
void __cdecl16far ovr_OVC23_55fe_1005(int param_1,int param_2,byte param_3,undefined1 param_4)
{
    OVC23_55fe_1005(param_1, param_2, param_3, param_4);
}

/* 236f:0057 -> OVC23_55fe_2b9e */
undefined2 __cdecl16far ovr_OVC23_55fe_2b9e(int param_1,int param_2,byte param_3,undefined1 param_4)
{
    return OVC23_55fe_2b9e(param_1, param_2, param_3, param_4);
}

/* 236f:005c -> OVC23_55fe_0487 */
undefined1 __cdecl16far ovr_OVC23_55fe_0487(undefined2 param_1,int param_2,char param_3)
{
    return OVC23_55fe_0487(param_1, param_2, param_3);
}

/* 236f:0061 -> OVC23_55fe_2da3 */
int __cdecl16far ovr_OVC23_55fe_2da3(int param_1,int param_2)
{
    return OVC23_55fe_2da3(param_1, param_2);
}

/* 236f:0066 -> OVC23_55fe_2e2b */
int __cdecl16far ovr_OVC23_55fe_2e2b(int param_1,undefined2 param_2)
{
    return OVC23_55fe_2e2b(param_1, param_2);
}

/* 2379:0020 -> OVC24_5943_000e */
void __cdecl16far ovr_OVC24_5943_000e(void)
{
    OVC24_5943_000e();
}

/* 2379:0025 -> OVC24_5943_0d5a */
void __cdecl16far ovr_OVC24_5943_0d5a(undefined1 *param_1)
{
    OVC24_5943_0d5a(param_1);
}

/* 2379:002a -> OVC24_5943_112e */
void __cdecl16far ovr_OVC24_5943_112e(void)
{
    OVC24_5943_112e();
}

/* 2379:002f -> OVC24_5943_1eeb */
char * __cdecl16far ovr_OVC24_5943_1eeb(undefined2 param_1,uint param_2,char param_3)
{
    return OVC24_5943_1eeb(param_1, param_2, param_3);
}

/* 2379:0043 -> OVC23_55fe_3450 */
uint __cdecl16far ovr_OVC23_55fe_3450(int param_1)
{
    return OVC23_55fe_3450(param_1);
}

/* 237f:0020 -> OVC25_5b66_0530 */
void __cdecl16far ovr_OVC25_5b66_0530(char param_1,byte param_2,uint16_t param_3,uint16_t param_4)
{
    OVC25_5b66_0530(param_1, param_2, param_3, param_4);
}

/* 237f:0025 -> OVC25_5b66_085d */
void __cdecl16far ovr_OVC25_5b66_085d(void)
{
    OVC25_5b66_085d();
}

/* 237f:002a -> OVC25_5b66_173b */
void __cdecl16far ovr_OVC25_5b66_173b(byte param_1)
{
    OVC25_5b66_173b(param_1);
}

/* 237f:002f -> OVC25_5b66_1b48 */
void __cdecl16far ovr_OVC25_5b66_1b48(int param_1)
{
    OVC25_5b66_1b48(param_1);
}

/* 237f:0034 -> OVC25_5b66_18cc */
int __cdecl16far ovr_OVC25_5b66_18cc(byte param_1)
{
    return OVC25_5b66_18cc(param_1);
}

/* 2386:0020 -> OVC26_5d45_031f */
uint __cdecl16far ovr_OVC26_5d45_031f(int param_1)
{
    return OVC26_5d45_031f(param_1);
}

/* 2386:0025 -> OVC26_5d45_06f0 */
undefined2 __cdecl16far ovr_OVC26_5d45_06f0(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5)
{
    return OVC26_5d45_06f0(param_1, param_2, param_3, param_4, param_5);
}

/* 2389:0020 -> OVC27_5ded_0a05 */
undefined2 __cdecl16far ovr_OVC27_5ded_0a05(int param_1)
{
    return OVC27_5ded_0a05(param_1);
}

/* 2389:0025 -> OVC27_5ded_0cc2 */
void __cdecl16far ovr_OVC27_5ded_0cc2(int param_1,brect_t *param_2,undefined2 param_3)
{
    OVC27_5ded_0cc2(param_1, param_2, param_3);
}

/* 2389:002a -> OVC27_5ded_10ea */
void __cdecl16far ovr_OVC27_5ded_10ea(undefined4 param_1,int param_2)
{
    OVC27_5ded_10ea(param_1, param_2);
}

/* 2389:002f -> OVC27_5ded_0404 */
uint __cdecl16far ovr_OVC27_5ded_0404(undefined4 param_1,int param_2)
{
    return OVC27_5ded_0404(param_1, param_2);
}

/* 2389:0034 -> OVC27_5ded_07d0 */
uint __cdecl16far ovr_OVC27_5ded_07d0(undefined4 param_1,int param_2)
{
    return OVC27_5ded_07d0(param_1, param_2);
}

/* 2389:0039 -> OVC27_5ded_04cd */
int __cdecl16far ovr_OVC27_5ded_04cd(undefined4 param_1,byte param_2)
{
    return OVC27_5ded_04cd(param_1, param_2);
}

/* 2389:003e -> OVC27_5ded_1c94 */
int __cdecl16far ovr_OVC27_5ded_1c94(undefined4 param_1,byte param_2)
{
    return OVC27_5ded_1c94(param_1, param_2);
}

/* 2389:0043 -> OVC27_5ded_1d8e */
int __cdecl16far ovr_OVC27_5ded_1d8e(undefined4 param_1,byte param_2)
{
    return OVC27_5ded_1d8e(param_1, param_2);
}

/* 2389:0048 -> OVC27_5ded_1fe1 */
undefined2 __cdecl16far ovr_OVC27_5ded_1fe1(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined1 param_4)
{
    return OVC27_5ded_1fe1(param_1, param_2, param_3, param_4);
}

/* 2389:004d -> OVC27_5ded_105e */
undefined2 __cdecl16far ovr_OVC27_5ded_105e(undefined4 param_1)
{
    return OVC27_5ded_105e(param_1);
}

/* 2389:0052 -> OVC27_5ded_1eb7 */
undefined2 __cdecl16far ovr_OVC27_5ded_1eb7(undefined4 param_1,char param_2)
{
    return OVC27_5ded_1eb7(param_1, param_2);
}

/* 2391:0020 -> uiInputText */
char * __cdecl16far ovr_uiInputText(far_t *entries,short count,byte *hint,byte flags)
{
    return uiInputText(entries, count, hint, flags);
}

/* 2391:0025 -> OVC28_6018_1527 */
void __cdecl16far ovr_OVC28_6018_1527(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5)
{
    OVC28_6018_1527(param_1, param_2, param_3, param_4, param_5);
}

/* 2391:002f -> toggle_pause */
void __cdecl16far ovr_toggle_pause(void)
{
    toggle_pause();
}

/* 2391:0034 -> OVC28_6018_01af */
void __cdecl16far ovr_OVC28_6018_01af(void)
{
    OVC28_6018_01af();
}

/* 2391:0039 -> OVC28_6018_0176 */
void __cdecl16far ovr_OVC28_6018_0176(void)
{
    OVC28_6018_0176();
}

/* 2391:003e -> OVC28_6018_1398 */
undefined2 __cdecl16far ovr_OVC28_6018_1398(far_t *param_1,int param_2,byte *param_3,undefined2 param_4,byte *param_5)
{
    return OVC28_6018_1398(param_1, param_2, param_3, param_4, param_5);
}

/* 2391:0048 -> OVC28_6018_0000 */
void __cdecl16far ovr_OVC28_6018_0000(int param_1)
{
    OVC28_6018_0000(param_1);
}

/* 2391:0052 -> update_pause_button */
void __cdecl16far ovr_update_pause_button(void)
{
    update_pause_button();
}

/* 2391:0057 -> OVC28_6018_0251 */
void __cdecl16far ovr_OVC28_6018_0251(void)
{
    OVC28_6018_0251();
}

/* 2398:0020 -> animInitSeqs */
void __cdecl16far ovr_animInitSeqs(void)
{
    animInitSeqs();
}

/* 2398:0025 -> animAdvance */
void __cdecl16far ovr_animAdvance(uint16_t play_id,byte gfx_id,uint16_t x,uint16_t y,far_t dst)
{
    animAdvance(play_id, gfx_id, x, y, dst);
}

/* 239b:0020 -> OVC30_619c_004e */
void __cdecl16far ovr_OVC30_619c_004e(byte param_1)
{
    OVC30_619c_004e(param_1);
}

/* 239b:0025 -> OVC30_619c_031d */
undefined1 __cdecl16far ovr_OVC30_619c_031d(byte param_1)
{
    return OVC30_619c_031d(param_1);
}

/* 239b:002a -> OVC30_619c_05a5 */
byte __cdecl16far ovr_OVC30_619c_05a5(byte param_1,int param_2,char param_3,byte param_4)
{
    return OVC30_619c_05a5(param_1, param_2, param_3, param_4);
}

/* 239b:0034 -> OVC30_619c_0a5e */
void __cdecl16far ovr_OVC30_619c_0a5e(int param_1,int param_2)
{
    OVC30_619c_0a5e(param_1, param_2);
}

/* 23a0:0020 -> init_base */
void __cdecl16far ovr_init_base(void)
{
    init_base();
}

/* 23a0:0025 -> read_cfg */
char __cdecl16far ovr_read_cfg(int handle)
{
    return read_cfg(handle);
}

/* 23a0:004d -> init_strong_sav */
byte __cdecl16far ovr_init_strong_sav(void)
{
    return init_strong_sav();
}

/* 23a6:0020 -> heapInit */
void __cdecl16far ovr_heapInit(void)
{
    heapInit();
}

/* 23a6:0025 -> heapAlloc */
uint32_t __cdecl16far ovr_heapAlloc(uint32_t nbytes)
{
    return heapAlloc(nbytes);
}

/* 23a6:002a -> heapMalloc */
far_t __cdecl16far ovr_heapMalloc(uint32_t nbytes)
{
    return heapMalloc(nbytes);
}

/* 23a6:002f -> heapRealloc */
long __cdecl16far ovr_heapRealloc(long block,long nbytes)
{
    return heapRealloc(block, nbytes);
}

/* 23a6:0034 -> heapValidateAll */
void __cdecl16far ovr_heapValidateAll(void)
{
    heapValidateAll();
}

/* 23a6:0039 -> heapFree */
void __cdecl16far ovr_heapFree(far_t ptr)
{
    heapFree(ptr);
}

/* 23a6:0043 -> heapMemmove */
void __cdecl16far ovr_heapMemmove(uint8_t *param_1,uint16_t param_2,uint8_t *param_3,uint16_t param_4,uint param_5,int param_6)
{
    heapMemmove(param_1, param_2, param_3, param_4, param_5, param_6);
}

/* 23ac:0020 -> stats_6386_22fd */
bool __cdecl16far ovr_stats_6386_22fd(undefined2 param_1,undefined2 param_2)
{
    return stats_6386_22fd(param_1, param_2);
}

/* 23ac:0025 -> drawAgntStats */
void __cdecl16far ovr_drawAgntStats(int32_t agnt,far_t cmap)
{
    drawAgntStats(agnt, cmap);
}

/* 23ac:002f -> drawString */
void __cdecl16far ovr_drawString(char *param_1,undefined2 param_2)
{
    drawString(param_1, param_2);
}

/* 23ac:0034 -> stats_6386_00f8 */
void __cdecl16far ovr_stats_6386_00f8(void)
{
    stats_6386_00f8();
}

/* 23ac:003e -> stats_6386_232d */
void __cdecl16far ovr_stats_6386_232d(void)
{
    stats_6386_232d();
}

/* 23ac:0048 -> stats_6386_05d3 */
char __cdecl16far ovr_stats_6386_05d3(undefined4 param_1)
{
    return stats_6386_05d3(param_1);
}

/* 23b6:0020 -> unit_6616_00d8 */
void __cdecl16far ovr_unit_6616_00d8(void)
{
    unit_6616_00d8();
}

/* 23b6:0025 -> ui_unit_order_6616_0689 */
void __cdecl16far ovr_ui_unit_order_6616_0689(byte param_1)
{
    ui_unit_order_6616_0689(param_1);
}

/* 23b6:002a -> unit_6616_0000 */
int __cdecl16far ovr_unit_6616_0000(int param_1)
{
    return unit_6616_0000(param_1);
}

/* 23ba:0025 -> bldng_676c_05ac */
undefined2 __cdecl16far ovr_bldng_676c_05ac(byte param_1)
{
    return bldng_676c_05ac(param_1);
}

/* 23ba:002a -> bldng_676c_05c3 */
undefined2 __cdecl16far ovr_bldng_676c_05c3(byte param_1)
{
    return bldng_676c_05c3(param_1);
}

/* 23ba:002f -> bldng_676c_0000 */
int __cdecl16far ovr_bldng_676c_0000(byte param_1)
{
    return bldng_676c_0000(param_1);
}

/* 23ba:0034 -> bldng_676c_003d */
char * __cdecl16far ovr_bldng_676c_003d(byte param_1,char param_2)
{
    return bldng_676c_003d(param_1, param_2);
}

/* 23bf:0020 -> OVC36_67d1_0000 */
uint __cdecl16far ovr_OVC36_67d1_0000(byte param_1)
{
    return OVC36_67d1_0000(param_1);
}

/* 23c2:0020 -> season_67e7_026a */
undefined2 __cdecl16far ovr_season_67e7_026a(byte param_1)
{
    return season_67e7_026a(param_1);
}

/* 23c2:0025 -> season_67e7_004d */
uint __cdecl16far ovr_season_67e7_004d(undefined1 param_1)
{
    return season_67e7_004d(param_1);
}

/* 23c2:002a -> season_67e7_048f */
int __cdecl16far ovr_season_67e7_048f(void)
{
    return season_67e7_048f();
}

/* 23c2:002f -> calcSeasonPalette */
uint16_t __cdecl16far ovr_calcSeasonPalette(uint8_t *param_1,undefined2 param_2,uint8_t *param_3,undefined2 param_4)
{
    return calcSeasonPalette(param_1, param_2, param_3, param_4);
}

/* 23c2:0034 -> season_67e7_030a */
void __cdecl16far ovr_season_67e7_030a(void)
{
    season_67e7_030a();
}

/* 23c2:0039 -> season_67e7_04e5 */
char __cdecl16far ovr_season_67e7_04e5(void)
{
    return season_67e7_04e5();
}

/* 23c2:0048 -> season_67e7_042b */
void __cdecl16far ovr_season_67e7_042b(void)
{
    season_67e7_042b();
}

/* 23c2:004d -> updSeason */
void __cdecl16far ovr_updSeason(void)
{
    updSeason();
}

/* 23c8:0020 -> OVC38_68ac_03fc */
void __cdecl16far ovr_OVC38_68ac_03fc(void)
{
    OVC38_68ac_03fc();
}

/* 23c8:0025 -> OVC38_68ac_0148 */
void __cdecl16far ovr_OVC38_68ac_0148(void)
{
    OVC38_68ac_0148();
}

/* 23cc:0020 -> OVC39_690b_0180 */
void __cdecl16far ovr_OVC39_690b_0180(byte param_1)
{
    OVC39_690b_0180(param_1);
}

/* 23d0:0020 -> OVC40_69c8_04c6 */
char __cdecl16far ovr_OVC40_69c8_04c6(char param_1,char *param_2,undefined2 param_3,char *param_4,undefined2 param_5,byte param_6)
{
    return OVC40_69c8_04c6(param_1, param_2, param_3, param_4, param_5, param_6);
}

/* 23d0:0025 -> setSeasonPalette */
void __cdecl16far ovr_setSeasonPalette(undefined4 param_1)
{
    setSeasonPalette(param_1);
}

/* 23d0:002a -> OVC40_69c8_011e */
void __cdecl16far ovr_OVC40_69c8_011e(undefined4 param_1)
{
    OVC40_69c8_011e(param_1);
}

/* 23d0:002f -> OVC40_69c8_0317 */
void __cdecl16far ovr_OVC40_69c8_0317(char param_1)
{
    OVC40_69c8_0317(param_1);
}

/* 23d0:0034 -> OVC40_69c8_047f */
void __cdecl16far ovr_OVC40_69c8_047f(void)
{
    OVC40_69c8_047f();
}

/* 23d5:0020 -> OVC41_6a8f_076f */
void __cdecl16far ovr_OVC41_6a8f_076f(void)
{
    OVC41_6a8f_076f();
}

/* 23d5:0025 -> OVC41_6a8f_0807 */
void __cdecl16far ovr_OVC41_6a8f_0807(int param_1)
{
    OVC41_6a8f_0807(param_1);
}

/* 23d5:002a -> OVC41_6a8f_08c2 */
void __cdecl16far ovr_OVC41_6a8f_08c2(int param_1)
{
    OVC41_6a8f_08c2(param_1);
}

/* 23d5:002f -> OVC41_6a8f_1be0 */
void __cdecl16far ovr_OVC41_6a8f_1be0(uint param_1)
{
    OVC41_6a8f_1be0(param_1);
}

/* 23d5:0034 -> OVC41_6a8f_002e */
void __cdecl16far ovr_OVC41_6a8f_002e(undefined4 param_1)
{
    OVC41_6a8f_002e(param_1);
}

/* 23d5:0039 -> OVC41_6a8f_0000 */
undefined2 __cdecl16far ovr_OVC41_6a8f_0000(int param_1)
{
    return OVC41_6a8f_0000(param_1);
}

/* 23d5:0043 -> OVC41_6a8f_016b */
void __cdecl16far ovr_OVC41_6a8f_016b(undefined2 param_1,undefined2 param_2,byte param_3,undefined4 param_4)
{
    OVC41_6a8f_016b(param_1, param_2, param_3, param_4);
}

/* 23d5:004d -> OVC41_6a8f_0256 */
void __cdecl16far ovr_OVC41_6a8f_0256(uint param_1,int param_2)
{
    OVC41_6a8f_0256(param_1, param_2);
}

/* 23d5:005c -> OVC41_6a8f_04c0 */
void __cdecl16far ovr_OVC41_6a8f_04c0(byte param_1)
{
    OVC41_6a8f_04c0(param_1);
}

/* 23d5:0061 -> OVC41_6a8f_05ad */
void __cdecl16far ovr_OVC41_6a8f_05ad(void)
{
    OVC41_6a8f_05ad();
}

/* 23d5:0066 -> OVC41_6a8f_063f */
undefined2 __cdecl16far ovr_OVC41_6a8f_063f(undefined4 param_1,undefined4 param_2)
{
    return OVC41_6a8f_063f(param_1, param_2);
}

/* 23d5:0070 -> dbgPromoteEnemy */
void __cdecl16far ovr_dbgPromoteEnemy(void)
{
    dbgPromoteEnemy();
}

/* 23d5:0075 -> OVC41_6a8f_11d2 */
void __cdecl16far ovr_OVC41_6a8f_11d2(char param_1)
{
    OVC41_6a8f_11d2(param_1);
}

/* 23d5:007a -> OVC41_6a8f_1520 */
void __cdecl16far ovr_OVC41_6a8f_1520(void)
{
    OVC41_6a8f_1520();
}

/* 23d5:007f -> OVC41_6a8f_15a0 */
char * __cdecl16far ovr_OVC41_6a8f_15a0(char param_1)
{
    return OVC41_6a8f_15a0(param_1);
}

/* 23d5:0084 -> OVC41_6a8f_1847 */
void __cdecl16far ovr_OVC41_6a8f_1847(void)
{
    OVC41_6a8f_1847();
}

/* 23d5:0089 -> OVC41_6a8f_18c6 */
void __cdecl16far ovr_OVC41_6a8f_18c6(void)
{
    OVC41_6a8f_18c6();
}

/* 23d5:008e -> uiMainMenu */
void __cdecl16far ovr_uiMainMenu(void)
{
    uiMainMenu();
}

/* 23d5:0093 -> OVC41_6a8f_0fc1 */
void __cdecl16far ovr_OVC41_6a8f_0fc1(char param_1)
{
    OVC41_6a8f_0fc1(param_1);
}

/* 23d5:00a2 -> OVC41_6a8f_1c74 */
undefined1 __cdecl16far ovr_OVC41_6a8f_1c74(undefined4 param_1,undefined4 param_2,uint param_3)
{
    return OVC41_6a8f_1c74(param_1, param_2, param_3);
}

/* 23d5:00a7 -> OVC41_6a8f_297d */
void __cdecl16far ovr_OVC41_6a8f_297d(undefined2 param_1,undefined2 param_2,undefined2 param_3)
{
    OVC41_6a8f_297d(param_1, param_2, param_3);
}

/* 23d5:00ac -> OVC41_6a8f_22cb */
void __cdecl16far ovr_OVC41_6a8f_22cb(undefined4 param_1,int param_2)
{
    OVC41_6a8f_22cb(param_1, param_2);
}

/* 23d5:00c0 -> OVC41_6a8f_29a0 */
void __cdecl16far ovr_OVC41_6a8f_29a0(void)
{
    OVC41_6a8f_29a0();
}

/* 23d5:00c5 -> OVC41_6a8f_0229 */
void __cdecl16far ovr_OVC41_6a8f_0229(undefined4 param_1)
{
    OVC41_6a8f_0229(param_1);
}

/* 23d5:00ca -> OVC41_6a8f_29ea */
int __cdecl16far ovr_OVC41_6a8f_29ea(undefined4 param_1)
{
    return OVC41_6a8f_29ea(param_1);
}

/* 23d5:00cf -> OVC41_6a8f_0246 */
void __cdecl16far ovr_OVC41_6a8f_0246(undefined4 param_1)
{
    OVC41_6a8f_0246(param_1);
}

/* 23e3:0020 -> run_demo */
undefined2 __cdecl16far ovr_run_demo(void)
{
    return run_demo();
}

/* 23e3:0025 -> OVC42_6d7a_0850 */
void __cdecl16far ovr_OVC42_6d7a_0850(char *param_1,undefined2 param_2,byte param_3)
{
    OVC42_6d7a_0850(param_1, param_2, param_3);
}

/* 23e9:0020 -> OVC43_6fbe_0322 */
void __cdecl16far ovr_OVC43_6fbe_0322(undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined1 param_4)
{
    OVC43_6fbe_0322(param_1, param_2, param_3, param_4);
}

/* 23e9:0025 -> OVC43_6fbe_035f */
undefined1 __cdecl16far ovr_OVC43_6fbe_035f(uint16_t param_1,undefined2 param_2,undefined2 param_3)
{
    return OVC43_6fbe_035f(param_1, param_2, param_3);
}

/* 23ed:0020 -> stshAllocStub */
far_t __cdecl16far ovr_stshAllocStub(void)
{
    return stshAllocStub();
}

/* 23ed:002a -> stshStubifyBld */
void __cdecl16far ovr_stshStubifyBld(uint16_t index)
{
    stshStubifyBld(index);
}

/* 23f1:0020 -> OVC45_77eb_0179 */
short __cdecl16far ovr_OVC45_77eb_0179(int param_1,int param_2)
{
    return OVC45_77eb_0179(param_1, param_2);
}

/* 23f1:0025 -> OVC45_77eb_0121 */
byte __cdecl16far ovr_OVC45_77eb_0121(int param_1,int param_2)
{
    return OVC45_77eb_0121(param_1, param_2);
}

/* 23f1:002a -> OVC45_77eb_21f1 */
bool __cdecl16far ovr_OVC45_77eb_21f1(int param_1,undefined2 param_2)
{
    return OVC45_77eb_21f1(param_1, param_2);
}

/* 23f1:002f -> OVC45_77eb_09c1 */
int __cdecl16far ovr_OVC45_77eb_09c1(byte param_1)
{
    return OVC45_77eb_09c1(param_1);
}

/* 23f1:0034 -> OVC45_77eb_0904 */
undefined2 __cdecl16far ovr_OVC45_77eb_0904(byte param_1)
{
    return OVC45_77eb_0904(param_1);
}

/* 23f1:0039 -> OVC45_77eb_226e */
int __cdecl16far ovr_OVC45_77eb_226e(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,char param_5)
{
    return OVC45_77eb_226e(param_1, param_2, param_3, param_4, param_5);
}

/* 23f1:0048 -> OVC45_77eb_02c1 */
char * __cdecl16far ovr_OVC45_77eb_02c1(undefined2 param_1,uint16_t param_2,uint *param_3,undefined1 *param_4,char param_5)
{
    return OVC45_77eb_02c1(param_1, param_2, param_3, param_4, param_5);
}

/* 23f1:004d -> OVC45_77eb_04d8 */
undefined2 __cdecl16far ovr_OVC45_77eb_04d8(undefined2 param_1,undefined2 param_2,int *param_3)
{
    return OVC45_77eb_04d8(param_1, param_2, param_3);
}

/* 23f1:0061 -> OVC45_77eb_0976 */
int __cdecl16far ovr_OVC45_77eb_0976(byte param_1)
{
    return OVC45_77eb_0976(param_1);
}

/* 23f1:0066 -> OVC45_77eb_0a02 */
void __cdecl16far ovr_OVC45_77eb_0a02(byte param_1,uint param_2,int param_3)
{
    OVC45_77eb_0a02(param_1, param_2, param_3);
}

/* 23f1:006b -> OVC45_77eb_0aea */
uint __cdecl16far ovr_OVC45_77eb_0aea(int param_1,undefined2 param_2)
{
    return OVC45_77eb_0aea(param_1, param_2);
}

/* 23f1:007f -> OVC45_77eb_1754 */
void __cdecl16far ovr_OVC45_77eb_1754(char param_1,byte param_2,int param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6)
{
    OVC45_77eb_1754(param_1, param_2, param_3, param_4, param_5, param_6);
}

/* 23f1:0084 -> OVC45_77eb_1ba2 */
bool __cdecl16far ovr_OVC45_77eb_1ba2(int param_1)
{
    return OVC45_77eb_1ba2(param_1);
}

/* 23f1:0089 -> OVC45_77eb_1bb3 */
void __cdecl16far ovr_OVC45_77eb_1bb3(char param_1,byte param_2,int param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6)
{
    OVC45_77eb_1bb3(param_1, param_2, param_3, param_4, param_5, param_6);
}

/* 23f1:008e -> OVC45_77eb_20e8 */
uint __cdecl16far ovr_OVC45_77eb_20e8(int *param_1)
{
    return OVC45_77eb_20e8(param_1);
}

/* 23f1:0093 -> OVC45_77eb_215a */
undefined2 __cdecl16far ovr_OVC45_77eb_215a(int param_1,int param_2)
{
    return OVC45_77eb_215a(param_1, param_2);
}

/* 23f1:0098 -> OVC45_77eb_21d3 */
undefined2 __cdecl16far ovr_OVC45_77eb_21d3(byte param_1,byte param_2)
{
    return OVC45_77eb_21d3(param_1, param_2);
}

/* 23f1:009d -> OVC45_77eb_2226 */
uint __cdecl16far ovr_OVC45_77eb_2226(byte param_1)
{
    return OVC45_77eb_2226(param_1);
}

/* 23f1:00a2 -> OVC45_77eb_2257 */
char * __cdecl16far ovr_OVC45_77eb_2257(int param_1)
{
    return OVC45_77eb_2257(param_1);
}

/* 23fd:0020 -> init_assets1 */
void __cdecl16far ovr_init_assets1(bool grab)
{
    init_assets1(grab);
}

/* 2400:0020 -> land_info */
void __cdecl16far ovr_land_info(byte param_1)
{
    land_info(param_1);
}

/* 2400:0025 -> constrct_7e7c_0000 */
void __cdecl16far ovr_constrct_7e7c_0000(void)
{
    constrct_7e7c_0000();
}

/* 2404:0020 -> init_assets2 */
void __cdecl16far ovr_init_assets2(bool grab)
{
    init_assets2(grab);
}

/* 2404:0025 -> grabBldLbm2 */
void __cdecl16far ovr_grabBldLbm2(int16_t index,int16_t normal,int16_t ruin)
{
    grabBldLbm2(index, normal, ruin);
}

/* 2404:002a -> stshAllocBldStubs2 */
void __cdecl16far ovr_stshAllocBldStubs2(int16_t index)
{
    stshAllocBldStubs2(index);
}

/* 2404:002f -> stshInitTxtFiles */
void __cdecl16far ovr_stshInitTxtFiles(char grab)
{
    stshInitTxtFiles(grab);
}

/* 2408:0020 -> OVC49_8699_1753 */
void * __cdecl16far ovr_OVC49_8699_1753(byte param_1,int *param_2)
{
    return OVC49_8699_1753(param_1, param_2);
}

/* 2408:0025 -> OVC49_8699_18c4 */
uint __cdecl16far ovr_OVC49_8699_18c4(int *param_1,byte *param_2,undefined2 param_3,undefined2 param_4,char param_5)
{
    return OVC49_8699_18c4(param_1, param_2, param_3, param_4, param_5);
}

/* 2408:002a -> OVC49_8699_06dc */
int __cdecl16far ovr_OVC49_8699_06dc(int *param_1)
{
    return OVC49_8699_06dc(param_1);
}

/* 2408:002f -> OVC49_8699_0849 */
uint __cdecl16far ovr_OVC49_8699_0849(int param_1)
{
    return OVC49_8699_0849(param_1);
}

/* 2408:0039 -> OVC49_8699_1e09 */
void __cdecl16far ovr_OVC49_8699_1e09(void)
{
    OVC49_8699_1e09();
}

/* 240d:0020 -> OVC50_8adb_00f1 */
void __cdecl16far ovr_OVC50_8adb_00f1(void)
{
    OVC50_8adb_00f1();
}

