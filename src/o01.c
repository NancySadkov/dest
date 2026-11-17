#include "st.h"

/* ovc01_driver: 60 function(s) */

/* 2d63:0000 */
uint32_t __cdecl16far mkp(uint16_t ofs,uint16_t seg)
{
    uint32_t r;

    return r;
}

/* 2d63:0016 */
uint16_t __cdecl16far biosVideoCall(uint8_t operation,uint8_t argument)
{
    uint16_t r;

    return r;
}

/* 2d63:0030 */
uint16_t __cdecl16far biosReadKey(void)
{
    uint16_t r;

    return r;
}

/* 2d63:0039 */
uint16_t __cdecl16far biosKeyAvail(void)
{
    uint16_t r;

    return r;
}

/* 2d63:004a */
uint16_t __cdecl16far miceButtonsStates(void)
{
    uint16_t r;

    return r;
}

/* 2d63:005d */
void __cdecl16far blitRaw(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint16_t src,uint16_t dst)
{
}

/* 2d63:00aa */
void __cdecl16far lbm_combine_bitplanes(far_t src,far_t dst,uint16_t npixels,uint8_t nplanes,uint16_t plane_sz)
{
}

/* 2d63:00eb */
uint32_t __cdecl16far be4(uint32_t be)
{
    uint32_t r;

    return r;
}

/* 2d63:00fc */
uint16_t __cdecl16far be2(uint16_t w)
{
    uint16_t r;

    return r;
}

/* 2d63:0107 */
char __cdecl16far driver_2d63_0107(char param_1,byte param_2,char param_3)
{
    char r;

    return r;
}

/* 2d63:014b */
char __cdecl16far driver_2d63_014b(char param_1,byte param_2,char param_3)
{
    char r;

    return r;
}

/* 2d63:017a */
void __cdecl16far miceDisableHandler(void)
{
}

/* 2d63:0190 */
uint16_t __cdecl16far miceButton0PressStates(void)
{
    uint16_t r;

    return r;
}

/* 2d63:01a7 */
void __cdecl16far miceSetPosition(uint16_t col,uint16_t row)
{
}

/* 2d63:01bf */
undefined1 __cdecl16far vgaSetPalette(undefined1 *param_1,undefined1 param_2,int param_3)
{
    undefined1 r;

    return r;
}

/* 2d63:01df */
undefined1 __cdecl16far vgaSetPalette8bit(undefined1 *param_1)
{
    undefined1 r;

    return r;
}

/* 2d63:0203 */
int __cdecl16far unrle(far_t src,far_t dst,uint16_t len)
{
    int r;

    return r;
}

/* 2d63:0241 */
int __cdecl16far rle_blit_decode(byte *src,byte *dst,uint16_t sz)
{
    int r;

    return r;
}

/* 2d63:0292 */
void __cdecl16far grabRemap(far_t pixels,uint8_t scolor,uint8_t dcolor)
{
}

/* 2d63:02b5 */
void __cdecl16far masked_memcpy(char *dst,char *src,int skip,int src_sz,int dst_sz,uint mask)
{
}

/* 2d63:02fe */
int __cdecl16far driver_2d63_02fe(char *param_1,uint param_2,uint param_3)
{
    int r;

    return r;
}

/* 2d63:032d */
int __cdecl16far rle_line(uint8_t *src,uint8_t *dst,uint16_t npixels)
{
    int r;

    return r;
}

/* 2d63:03b6 */
int __cdecl16far unrle_mirror(byte *src,byte *dst,int len)
{
    int r;

    return r;
}

/* 2d63:03fc */
int __cdecl16far drawLine2(byte *param_1,byte *param_2,int param_3)
{
    int r;

    return r;
}

/* 2d63:044e */
void __cdecl16far driver_2d63_044e(char *param_1,int param_2,char param_3,byte param_4,undefined4 param_5,uint param_6)
{
}

/* 2d63:04b7 */
void __cdecl16far vga_2d63_04b7(undefined1 *param_1,int param_2,undefined1 *param_3,int param_4,undefined1 param_5)
{
}

/* 2d63:0599 */
undefined2 __cdecl16near driver_2d63_0599(void)
{
    undefined2 r;

    return r;
}

/* 2d63:05a9 */
void __cdecl16far driver_2d63_05a9(uint param_1,uint param_2,undefined2 param_3,undefined1 param_4,undefined2 param_5)
{
}

/* 2d63:05e5 */
undefined2 __cdecl16far driver_2d63_05e5(uint param_1,uint param_2,uint param_3,uint param_4,undefined1 param_5,undefined2 param_6)
{
    undefined2 r;

    return r;
}

/* 2d63:0652 */
void __cdecl16far driver_2d63_0652(int param_1,byte param_2,undefined1 param_3,undefined1 param_4,undefined2 param_5)
{
}

/* 2d63:0687 */
void __cdecl16far driver_2d63_0687(int param_1,byte param_2,undefined1 param_3,undefined1 param_4,undefined2 param_5)
{
}

/* 2d63:06bf */
bool __cdecl16far digSoundPlaying(void)
{
    bool r;

    return r;
}

/* 2d63:06d1 */
void __cdecl16far digPlayPreformatedSound(void)
{
}

/* 2d63:06e6 */
void __cdecl16far digPlayPreformatedData(void)
{
}

/* 2d63:06fb */
void __cdecl16far digStopCurrentSound(void)
{
}

/* 2d63:070d */
void __cdecl16far digPreformatSound(void)
{
}

/* 2d63:071e */
bool __cdecl16far digIsInstalled(void)
{
    bool r;

    return r;
}

/* 2d63:075f */
void __cdecl16far midPlaySequence(uint16_t param_1)
{
}

/* 2d63:0774 */
void __cdecl16far midSegueSequence(void)
{
}

/* 2d63:078c */
void __cdecl16far midRegisterXMIDI(void)
{
}

/* 2d63:07aa */
void __cdecl16far midMidiStop(void)
{
}

/* 2d63:07bc */
void __cdecl16far midGetSequenceStatus(void)
{
}

/* 2d63:07ce */
bool __cdecl16far midIsLoaded(void)
{
    bool r;

    return r;
}

/* 2d63:07fb */
void __cdecl16far midLoadDriver(void)
{
}

/* 2d63:0819 */
void __cdecl16far digSetSterioPanning(void)
{
}

/* 2d63:082e */
void __cdecl16far midSetRelativeValue(void)
{
}

/* 2d63:0846 */
void __cdecl16far driver_2d63_0846(undefined2 param_1,byte param_2,undefined2 param_3,byte param_4,undefined2 param_5,byte param_6)
{
}

/* 2d63:098a */
void __cdecl16near driver_2d63_098a(void)
{
}

/* 2d63:09c9 */
void __cdecl16far driver_2d63_09c9(int param_1,int param_2,byte param_3,undefined1 param_4,int *param_5)
{
}

/* 2d63:0a18 */
uint8_t __cdecl16far vda_query(void)
{
    uint8_t r;

    return r;
}

/* 2d63:0a24 */
void __cdecl16far driver_2d63_0a24(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)
{
}

/* 2d63:0a67 */
void __cdecl16far driver_2d63_0a67(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)
{
}

/* 2d63:0aac */
void __cdecl16far driver_2d63_0aac(byte *param_1,byte *param_2)
{
}

/* 2d63:0af7 */
void __cdecl16far driver_2d63_0af7(int *param_1,undefined4 param_2)
{
}

/* 2d63:0b4d */
int __cdecl16far vgaDoSomethingWithPalette(int *param_1)
{
    int r;

    return r;
}

/* 2d63:0b8b */
uint8_t __cdecl16far vgaWaitVerticalRetrace(void)
{
    uint8_t r;

    return r;
}

/* 2d63:0b94 */
uint __cdecl16far driver_2d63_0b94(uint param_1)
{
    uint r;

    return r;
}

/* 2d63:0bad */
void __cdecl16far driver_2d63_0bad(undefined2 *param_1,undefined2 *param_2,int param_3)
{
}

/* 2d63:0bc8 */
void __cdecl16far driver_2d63_0bc8(undefined2 *param_1,int param_2)
{
}

/* 2d63:0bde */
void __cdecl16far driver_2d63_0bde(int *param_1,char *param_2)
{
}

