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
  uint unaff_SI;
  uint16_t i;
  uint32_t p;
  ulong nbytes;
  
  nbytes = (ulong)unaff_SI << 0x10;
  for (i = 0; (int)i < 3; i = i + 1) {
    nbytes = nbytes & 0xffff0000;
    (*(uint16_t *)((uint8_t *)&(p))) = ovr_stshAlloc(nbytes,(uint)((uint8_t *)AnimSeqCounts)[i] << 2);
    *(undefined2 *)((int)&AnimSeqPtr[0].seg + i * 4) = (*(uint16_t *)((uint8_t *)&(p) + 2));
    ((far_t *)AnimSeqPtr + i)->ofs = (uint16_t)(void *)p;
  }
  return;
}



/* 6190:0039 */

void __cdecl16far animAdvance(uint16_t play_id,byte gfx_id,uint16_t x,uint16_t y,far_t dst,...)

{
  int iVar1;
  undefined2 *puVar2;
  bool unaff_SI;
  undefined2 uVar3;
  int in_stack_00000004;
  far_t gfx;
  uint8_t step;
  
  iVar1 = in_stack_00000004;
  step = ((undefined *)&GfxPlaySteps)[in_stack_00000004];
  if ((byte)((undefined *)&GfxFrameCounts)[play_id & 0xff] <= step) {
    step = 0x0;
  }
  uVar3 = (undefined2)
          ((ulong)*(undefined4 *)((undefined *)&GfxFramePtrs + (play_id & 0xff) * 4) >> 0x10);
  puVar2 = (undefined2 *)
           ((int)*(undefined4 *)((undefined *)&GfxFramePtrs + (play_id & 0xff) * 4) + (uint)step * 4
           );
  gfx.seg = _gfx_id;
  gfx.ofs = puVar2[1];
  ovr_blitGfxRect(gfx,x,y,(brect_t *)CONCAT22(0x10,dst.ofs),0x0,unaff_SI,*puVar2);
  ((undefined *)&GfxPlaySteps)[iVar1] = step + 0x1;
  GAnimPlaying = 1;
  return;
}


