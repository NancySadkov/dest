/*
 * ovc29_anim.c - recovered from STRONG.EXE
 * memory block: OVC29_anim.c
 * range: 6190:0000 - 6190:00bf
 * functions: 2
 */
#include "recovered.h"


/* 6190:0000 */

void __cdecl16far animInitSeqs(void)

{
  uint16_t i;
  uint32_t p;
  
  for (i = 0; (int)i < 3; i = i + 1) {
    (*(uint16_t *)((uint8_t *)&(p))) = ovr_stshAlloc((ulong)((uint8_t *)AnimSeqCounts)[i] << 2);
    *(undefined2 *)((int)&AnimSeqPtr[0].seg + i * 4) = (*(uint16_t *)((uint8_t *)&(p) + 2));
    ((far_t *)AnimSeqPtr + i)->ofs = (uint16_t)(void *)p;
  }
  return;
}



/* 6190:0039 */

void __cdecl16far animAdvance(uint16_t play_id,byte gfx_id,uint16_t x,uint16_t y,far_t dst,...)

{
  uint16_t *puVar1;
  undefined2 uVar2;
  far_t gfx;
  uint8_t step;
  
  step = ((undefined *)&GfxPlaySteps)[play_id];
  if ((byte)((undefined *)&GfxFrameCounts)[gfx_id] <= step) {
    step = 0x0;
  }
  uVar2 = (undefined2)
          ((ulong)*(undefined4 *)((undefined *)&GfxFramePtrs + (uint)gfx_id * 4) >> 0x10);
  puVar1 = (uint16_t *)
           ((int)*(undefined4 *)((undefined *)&GfxFramePtrs + (uint)gfx_id * 4) + (uint)step * 4);
  gfx.seg = puVar1[1];
  gfx.ofs = *puVar1;
  ovr_blitGfxRect(gfx,x,y,(brect_t *)dst.ofs,(uint8_t)dst.seg,true,0);
  ((undefined *)&GfxPlaySteps)[play_id] = step + 0x1;
  GAnimPlaying = 1;
  return;
}


