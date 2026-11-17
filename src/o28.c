#include "st.h"

/* ovc28: 16 function(s) */

/* 6018:0000 */
void __cdecl16far OVC28_6018_0000(int param_1)
{
}

/* 6018:0048 */
void __cdecl16far OVC28_6018_0048(void)
{
}

/* 6018:007e */
void __cdecl16far update_pause_button(void)
{
    bool busy;
    far_t gfx;

    TextBlitDstSeg = 0xa000;
    if ((GPaused != '\0') &&
        ((busy = OVC15_4207_288b(), busy == '\0' || (GOngoingBattle != '\0')))) {
        gfx.seg = word_2000_BSS_093E;
        gfx.ofs = word_2000_BSS_093C;
        blitGfxRect(gfx,235,116,BlitRects + 1,0x10,false);
        TextBlitY = 0x76;
        TextBlitX = 0xf1;
        blitLabel("Resume",(uint8_t *)CONCAT22(FontMain.seg,FontMain.ofs),319,0xe0);
        return;
    }
    gfx.seg = word_2000_BSS_093A;
    gfx.ofs = word_2000_BSS_0938;
    blitGfxRect(gfx,235,116,BlitRects + 1,0x10,false);
    TextBlitY = 0x76;
    TextBlitX = 0xf0;
    blitLabel("Pause",(uint8_t *)CONCAT22(Font01.seg,Font01.ofs),319,0xe0);
}

/* 6018:0176 */
void __cdecl16far OVC28_6018_0176(void)
{
}

/* 6018:01af */
void __cdecl16far OVC28_6018_01af(void)
{
}

/* 6018:0251 */
void __cdecl16far OVC28_6018_0251(void)
{
}

/* 6018:03d3 */
void __cdecl16far toggle_pause(void)
{
    bool busy;

    busy = OVC15_4207_288b();
    if ((busy == '\0') || (GOngoingBattle != '\0')) {
        GPaused = !GPaused;
        if (GPaused == '\0') {
            drawTextAt("Resume. Game events will now occur normally.",0xa000);
        }
        else {
            drawTextAt("Pause. Select 'Resume' to enable game events. Press SPACE for a single game event."
                       ,0xa000);
        }
        update_pause_button();
    }
    else {
        drawTextAt("Sorry, you may not pause during a battle.",0xa000);
        GPaused = '\0';
    }
}

/* 6018:0456 */
void __cdecl16far OVC28_6018_0456(undefined4 param_1,int param_2)
{
}

/* 6018:0634 */
void __cdecl16far OVC28_6018_0634(byte param_1)
{
}

/* 6018:0813 */
void __cdecl16far OVC28_6018_0813(int param_1,int param_2,char *param_3)
{
}

/* 6018:0aac */
void __cdecl16far OVC28_6018_0aac(undefined4 param_1,int param_2)
{
}

/* 6018:0aef */
void __cdecl16far OVC28_6018_0aef(void)
{
}

/* 6018:0c76 */
undefined2 __cdecl16far OVC28_6018_0c76(undefined4 param_1,uint param_2)
{
    undefined2 r;

    return r;
}

/* 6018:0f29 */
char * __cdecl16far uiInputText(far_t *entries,short count,byte *hint,byte flags)
{
    char * r;

    return r;
}

/* 6018:1398 */
undefined2 __cdecl16far OVC28_6018_1398(far_t *param_1,int param_2,byte *param_3,undefined2 param_4,byte *param_5)
{
    undefined2 r;

    return r;
}

/* 6018:1527 */
void __cdecl16far OVC28_6018_1527(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5)
{
}

