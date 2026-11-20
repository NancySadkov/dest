/*
 * ovc15.c - recovered from STRONG.EXE
 * memory block: OVC15
 * range: 4207:0000 - 4207:320f
 * functions: 29
 */
#include "recovered.h"


/* 4207:0000 */

spr_t * __cdecl16far stshRleAnims(uint8_t *src,anm_t *anms,uint16_t nanims)

{
  uint uVar1;
  uint16_t anim_height;
  uint16_t row;
  uint16_t panms;
  int *piVar2;
  uint16_t i;
  uint16_t unaff_DI;
  uint16_t count;
  far_t dst;
  frm_t *frm;
  int in_stack_0000000a;
  uint in_stack_0000000c;
  uint16_t pdst;
  uint16_t sdst;
  uint32_t prev_next;
  frm_t *pfStack_20;
  uint16_t frm_seg;
  uint16_t xx;
  uint16_t exx;
  uint16_t sxx;
  uint16_t j;
  uint32_t p_ow;
  uint16_t ey;
  uint16_t ex;
  uint16_t sy;
  uint16_t sx;
  uint8_t index;
  
  if (0x4e < StshSprIndex) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x36);
  }
  dst.seg = (uint16_t)((spr_t *)StshSprites + StshSprIndex);
  StshSprIndex = StshSprIndex + 1;
  dst.ofs = (uint16_t)ovr_mkp((uint32_t *)dst.seg,(*(uint16_t *)((uint8_t *)&(StshSprites) + 2)),unaff_DI);
  _fsetmem((void *)dst.ofs,dst.seg,0xb0);
  i = 0;
  while ((i < in_stack_0000000c && (*(char *)(nanims + i * 0x1e + 0x1b) != '\0'))) {
    uVar1 = (uint)*(byte *)(nanims + i * 0x1e);
    prev_next = CONCAT22(dst.seg,dst.ofs + uVar1 * 4 + 0x58);
    piVar2 = (int *)(dst.ofs + uVar1 * 4);
    piVar2[1] = in_stack_0000000a;
    *piVar2 = nanims + i * 0x1e;
    sx = *(uint16_t *)(nanims + i * 0x1e + 1);
    sy = *(uint16_t *)(nanims + i * 0x1e + 3);
    ex = *(uint16_t *)(nanims + i * 0x1e + 5);
    ey = *(uint16_t *)(nanims + i * 0x1e + 7);
    anim_height = ey - sy;
    if ((int)anim_height < 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x33);
    }
    p_ow = 0;
    j = 0;
    while( true ) {
      (*(uint16_t *)((uint8_t *)&(frm) + 2)) = (undefined2)((ulong)((long)(int)i * 0x1e) >> 0x10);
      if (*(byte *)(nanims + (int)((long)(int)i * 0x1e) + 0x1b) <= j) break;
      (*(uint16_t *)((uint8_t *)&(frm))) = (frm_t *)ovr_stshRleSub((far_t *)src,&anms->frmid,sx,sy,ex,ey,21);
      pfStack_20 = (frm_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(frm) + 2)),(frm_t *)frm);
      ((frm_t *)frm)->type2 = 2;
      ((frm_t *)frm)->x = *(int16_t *)(nanims + i * 0x1e + 0xb);
      ((frm_t *)frm)->y = *(int16_t *)(nanims + i * 0x1e + 0xd);
      *(undefined2 *)((int)prev_next + 2) = (*(uint16_t *)((uint8_t *)&(frm) + 2));
      *(frm_t **)prev_next = (frm_t *)frm;
      prev_next = CONCAT22((*(uint16_t *)((uint8_t *)&(frm) + 2)),&((frm_t *)frm)->next);
      if ((*(byte *)(nanims + i * 0x1e + 0x1c) & 1) == 0) {
        ((frm_t *)frm)->ow = *(uint8_t *)(nanims + i * 0x1e + 0xf);
      }
      else {
        row = ey * 0x140 + 0x140;
        if (j == 0) {
          count = 0;
          xx = sx;
          while (count < 2) {
            if (ex + row < xx) {
                    /* WARNING: Subroutine does not return */
              ovr_stExit(9);
            }
            if (src[xx + row] == 0xfe) {
              if (count == 0) {
                sxx = xx;
              }
              else {
                exx = xx;
              }
              count = count + 1;
            }
            xx = xx + 1;
          }
          p_ow = CONCAT22((*(uint16_t *)((uint8_t *)&(frm) + 2)),&((frm_t *)frm)->ow);
        }
        else {
          xx = sx;
          while (src[xx + row] != 0xfe) {
            if (ex + row < xx) {
                    /* WARNING: Subroutine does not return */
              ovr_stExit(9);
            }
            xx = xx + 1;
          }
          ((frm_t *)frm)->ow = (char)exx - (char)xx;
          exx = xx;
        }
      }
      pfStack_20->type4 = 4;
      *(undefined2 *)((int)&((frm_t *)frm)->next + 2) = 0;
      *(undefined2 *)&((frm_t *)frm)->next = 0;
      sy = sy + *(byte *)(nanims + i * 0x1e + 10);
      ey = ey + *(byte *)(nanims + i * 0x1e + 10);
      if (199 < ey) {
        sy = *(int *)(nanims + i * 0x1e + 3) % (int)(uint)*(byte *)(nanims + i * 0x1e + 10);
        ey = sy + anim_height;
        sx = sx + *(byte *)(nanims + i * 0x1e + 9);
        ex = ex + *(byte *)(nanims + i * 0x1e + 9);
        sxx = sxx + *(byte *)(nanims + i * 0x1e + 9);
        exx = exx + *(byte *)(nanims + i * 0x1e + 9);
      }
      j = j + 1;
    }
    if ((int)p_ow != 0 || (*(uint16_t *)((uint8_t *)&(p_ow) + 2)) != 0) {
      *(char *)p_ow = (char)exx - (char)sxx;
    }
    i = i + 1;
  }
  return (spr_t *)dst.ofs;
}



/* 4207:03ac */

far_t * __cdecl16far
stshSprite(far_t *__return_storage_ptr__,int16_t file_id,anm_t *anms,uint16_t nanims,bool grab)

{
  far_t handle;
  uint16_t ofs;
  uint16_t seg;
  spr_t *spr;
  stg_tmp_t *fVar6;
  far_t pixels;
  far_t handle_00;
  
  if (grab) {
    (*(uint16_t *)((uint8_t *)&(fVar6))) = ovr_grabLbm((int16_t)__return_storage_ptr__,0,0);
    pixels.seg = (((stg_tmp_t *)fVar6)->aptr).seg;
    pixels.ofs = (&((stg_tmp_t *)fVar6)->aptr)->ofs;
    seg = (*(uint16_t *)((uint8_t *)&(fVar6) + 2));
    ovr_grabRemap(pixels,0xff,0x0);
    ofs = (uint16_t)
          stshRleAnims((uint8_t *)(&((stg_tmp_t *)fVar6)->aptr)->ofs,
                       (anm_t *)(((stg_tmp_t *)fVar6)->aptr).seg,file_id);
    handle_00.seg = (((stg_tmp_t *)fVar6)->bptr).seg;
    handle_00.ofs = (&((stg_tmp_t *)fVar6)->bptr)->ofs;
    ovr_stshFree(handle_00);
    handle.seg = (*(uint16_t *)((uint8_t *)&(fVar6) + 2));
    handle.ofs = (uint16_t)(stg_tmp_t *)fVar6;
    ovr_stshFree(handle);
    stshStoreSprite((spr_t *)ofs,(anm_t *)seg,file_id);
    (*(uint16_t *)((uint8_t *)&(spr))) = (spr_t *)ofs;
  }
  else {
    (*(uint16_t *)((uint8_t *)&(spr))) = ovr_stshSpriteStub((anm_t *)file_id,(uint16_t)anms);
  }
  return (far_t *)(spr_t *)spr;
}



/* 4207:0462 */

void __cdecl16far allocSprSeqs(void)

{
  undefined2 in_DX;
  
  (*(uint16_t *)((uint8_t *)&(StshSprites))) = ovr_stshAlloc(0x3650);
  (*(uint16_t *)((uint8_t *)&(StshSprites) + 2)) = in_DX;
  return;
}



/* 4207:047b */

void __cdecl16far stshInitSprites(bool grab)

{
  far_t *pfVar1;
  int iVar2;
  int iVar3;
  stg_tmp_t *gfx;
  cte_t *pcVar4;
  uint32_t *puVar5;
  uint16_t in_DX;
  undefined2 uVar6;
  uint8_t *data;
  uint8_t *puVar7;
  undefined2 uVar8;
  uint16_t i;
  far_t *unaff_DI;
  int iVar9;
  uint16_t j;
  far_t pixels;
  
  StshSprIndex = 0;
  SprProjectiles.ofs =
       (uint16_t)
       stshSprite((far_t *)((byte *)__C0_ASM_CopyRight + 0x21),0,(anm_t *)&AgntAnms[0x88].missileDy,
                  9,grab);
  SprProjectiles.seg = in_DX;
  for (i = 0; (int)i < 0x2a; i = i + 1) {
    uVar6 = 0x195d;
    pfVar1 = stshSprite((far_t *)*(undefined2 *)((int)AgntGs[0].sprfls + i * 0x95),
                        *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                        (anm_t *)*(undefined2 *)((int)&AgntGs[0].anms + 2 + i * 0x95),
                        (uint)*(byte *)((int)&AgntGs[0].nanims + i * 0x95),grab);
    *(undefined2 *)((int)AgntGs[0].sprs + 2 + i * 0x95) = uVar6;
    *(undefined2 *)((int)AgntGs[0].sprs + i * 0x95) = pfVar1;
    if (*(int *)((int)AgntGs[0].sprfls + 2 + i * 0x95) == 0) {
      uVar6 = *(undefined2 *)((int)AgntGs[0].sprs + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 6 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].sprs + 2 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 4 + i * 0x95) = uVar6;
    }
    else {
      uVar6 = 0x195d;
      pfVar1 = stshSprite((far_t *)*(undefined2 *)((int)AgntGs[0].sprfls + 2 + i * 0x95),
                          *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                          (anm_t *)*(undefined2 *)((int)&AgntGs[0].anms + 2 + i * 0x95),
                          (uint)*(byte *)((int)&AgntGs[0].nanims + i * 0x95),grab);
      *(undefined2 *)((int)AgntGs[0].sprs + 6 + i * 0x95) = uVar6;
      *(undefined2 *)((int)AgntGs[0].sprs + 4 + i * 0x95) = pfVar1;
    }
    if (*(int *)((int)AgntGs[0].sprfls + 4 + i * 0x95) == 0) {
      uVar6 = *(undefined2 *)((int)AgntGs[0].sprs + 4 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 10 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].sprs + 6 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 8 + i * 0x95) = uVar6;
    }
    else {
      uVar6 = 0x195d;
      pfVar1 = stshSprite((far_t *)*(undefined2 *)((int)AgntGs[0].sprfls + 4 + i * 0x95),
                          *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                          (anm_t *)*(undefined2 *)((int)&AgntGs[0].anms + 2 + i * 0x95),
                          (uint)*(byte *)((int)&AgntGs[0].nanims + i * 0x95),grab);
      *(undefined2 *)((int)AgntGs[0].sprs + 10 + i * 0x95) = uVar6;
      *(undefined2 *)((int)AgntGs[0].sprs + 8 + i * 0x95) = pfVar1;
    }
    for (iVar9 = 0; iVar9 < 3; iVar9 = iVar9 + 1) {
      if (*(int *)((int)AgntGs[0].sprfls + 6 + i * 0x95 + iVar9 * 2) == 0) {
        iVar2 = i * 0x95 + iVar9 * 4;
        uVar6 = *(undefined2 *)((int)AgntGs[0].sprs + iVar2);
        iVar3 = i * 0x95 + iVar9 * 4;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar3) =
             *(undefined2 *)((int)AgntGs[0].sprs + 2 + iVar2);
        *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar3) = uVar6;
      }
      else {
        uVar6 = 0x195d;
        pfVar1 = stshSprite((far_t *)*(undefined2 *)
                                      ((int)AgntGs[0].sprfls + 6 + i * 0x95 + iVar9 * 2),
                            *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                            (anm_t *)*(undefined2 *)((int)&AgntGs[0].anms + 2 + i * 0x95),
                            (uint)*(byte *)((int)&AgntGs[0].nanims + i * 0x95),grab);
        iVar2 = i * 0x95 + iVar9 * 4;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar2) = uVar6;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar2) = pfVar1;
      }
    }
    for (j = 0; (int)j < 6; j = j + 1) {
      uVar6 = 0x195d;
      if (*(int *)((int)AgntGs[0].prtfls + i * 0x95 + j * 2) != 0) {
        if (grab) {
          data = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
          gfx = ovr_grabLbm(*(int16_t *)((int)AgntGs[0].prtfls + i * 0x95 + j * 2),0,0);
          puVar7 = data;
          ovr_stshUniqueColorsRemap(gfx);
          pixels.seg = 0;
          pixels.ofs = (gfx->aptr).seg;
          pfVar1 = ovr_stshRleType2((far_t *)(&gfx->aptr)->ofs,pixels,0,114,103,0,0,
                                    (int16_t)unaff_DI);
          pcVar4 = ovr_stshStoreFile((uint8_t *)pfVar1);
          iVar9 = i * 0x95 + j * 4;
          uVar6 = 0x195d;
          *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar9) = puVar7;
          *(undefined2 *)((int)AgntGs[0].prts + iVar9) = pcVar4;
          puVar5 = ovr_stshWrite((uint32_t *)gfx,data,0x300);
          iVar9 = i * 0x95 + j * 4;
          *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar9) = uVar6;
          *(undefined2 *)((int)AgntGs[0].prtpals + iVar9) = puVar5;
          ovr_stgFreeTmp(gfx);
        }
        else {
          pfVar1 = ovr_stshAllocStub(unaff_DI);
          iVar9 = i * 0x95 + j * 4;
          uVar8 = 0x195d;
          *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar9) = uVar6;
          *(undefined2 *)((int)AgntGs[0].prts + iVar9) = pfVar1;
          pfVar1 = ovr_stshAllocStub(unaff_DI);
          iVar9 = i * 0x95 + j * 4;
          *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar9) = uVar8;
          *(undefined2 *)((int)AgntGs[0].prtpals + iVar9) = pfVar1;
        }
      }
    }
    if ((*(int *)((int)AgntGs[0].prts + 4 + i * 0x95) == 0 &&
         *(int *)((int)AgntGs[0].prts + 6 + i * 0x95) == 0) &&
       (*(int *)((int)AgntGs[0].prts + i * 0x95) != 0 ||
        *(int *)((int)AgntGs[0].prts + 2 + i * 0x95) != 0)) {
      uVar6 = *(undefined2 *)((int)AgntGs[0].prts + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prts + 6 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].prts + 2 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prts + 4 + i * 0x95) = uVar6;
      uVar6 = *(undefined2 *)((int)AgntGs[0].prtpals + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prtpals + 6 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].prtpals + 2 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prtpals + 4 + i * 0x95) = uVar6;
    }
    for (iVar9 = 2; iVar9 < 6; iVar9 = iVar9 + 2) {
      iVar2 = i * 0x95 + iVar9 * 4;
      if ((*(int *)((int)AgntGs[0].prts + 4 + iVar2) == 0 &&
           *(int *)((int)AgntGs[0].prts + 6 + iVar2) == 0) &&
         (iVar2 = i * 0x95 + iVar9 * 4,
         *(int *)((int)AgntGs[0].prtfls + 8 + iVar2) != 0 ||
         *(int *)((int)AgntGs[0].prtfls + 10 + iVar2) != 0)) {
        iVar2 = i * 0x95 + iVar9 * 4;
        uVar6 = *(undefined2 *)((int)AgntGs[0].prtfls + 8 + iVar2);
        iVar3 = i * 0x95 + iVar9 * 4;
        *(undefined2 *)((int)AgntGs[0].prts + 6 + iVar3) =
             *(undefined2 *)((int)AgntGs[0].prtfls + 10 + iVar2);
        *(undefined2 *)((int)AgntGs[0].prts + 4 + iVar3) = uVar6;
        iVar2 = i * 0x95 + iVar9 * 4;
        uVar6 = *(undefined2 *)((int)AgntGs[0].prts + 0x14 + iVar2);
        iVar3 = i * 0x95 + iVar9 * 4;
        *(undefined2 *)((int)AgntGs[0].prtpals + 6 + iVar3) =
             *(undefined2 *)((int)AgntGs[0].prts + 0x16 + iVar2);
        *(undefined2 *)((int)AgntGs[0].prtpals + 4 + iVar3) = uVar6;
      }
      iVar2 = i * 0x95 + iVar9 * 4;
      if ((*(int *)((int)AgntGs[0].prts + iVar2) == 0 &&
           *(int *)((int)AgntGs[0].prts + 2 + iVar2) == 0) &&
         (iVar2 = i * 0x95 + iVar9 * 4,
         *(int *)((int)AgntGs[0].prtfls + 4 + iVar2) != 0 ||
         *(int *)((int)AgntGs[0].prtfls + 6 + iVar2) != 0)) {
        iVar2 = i * 0x95 + iVar9 * 4;
        uVar6 = *(undefined2 *)((int)AgntGs[0].prtfls + 4 + iVar2);
        iVar3 = i * 0x95 + iVar9 * 4;
        *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar3) =
             *(undefined2 *)((int)AgntGs[0].prtfls + 6 + iVar2);
        *(undefined2 *)((int)AgntGs[0].prts + iVar3) = uVar6;
        iVar2 = i * 0x95 + iVar9 * 4;
        uVar6 = *(undefined2 *)((int)AgntGs[0].prts + 0x10 + iVar2);
        iVar3 = i * 0x95 + iVar9 * 4;
        *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar3) =
             *(undefined2 *)((int)AgntGs[0].prts + 0x12 + iVar2);
        *(undefined2 *)((int)AgntGs[0].prtpals + iVar3) = uVar6;
      }
    }
  }
  return;
}



/* 4207:0b05 */

void __cdecl16far agnt_clear(void)

{
  if (!AgntFlag1) {
    AgntCount = 0;
    _fsetmem((char *)"You cannot attract units to this location." + 4,0x1726,0x41a);
    _fsetmem((undefined1 *)&MiceUnkState,0x1726,0x41a);
  }
  AgntFlag2 = true;
  return;
}



/* 4207:0b55 */

/* Fills all ten rows of one column of the agent grid at Agnts+0x8fa with 0xff. */

void __cdecl16far ovc15_fillGridColumn(uint vramOfs)

{
  uint uVar1;
  
  if (vramOfs >> 1 < 0x69) {
    for (uVar1 = 0; uVar1 < 10; uVar1 = uVar1 + 1) {
      *(undefined1 *)(uVar1 * 0x69 + (vramOfs >> 1) + 0x8fa) = 0xff;
    }
  }
  return;
}



/* 4207:0b88 */

/* Clears the visited byte (agnt_t+0x2d) on every agent. */

void __cdecl16far ovc15_clearVisited(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    *(undefined1 *)(iVar1 * 0x34 + 0x2d) = 0;
  }
  return;
}



/* 4207:0bb7 */

/* [R6] touches agntIndex, EntityCount */

void __cdecl16far ovc15_usesAgntIndex(void)

{
  uint agntIndex;
  entity_t *peVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  uint8_t agentIndices;
  uint uStack_a;
  uint uStack_8;
  int iStack_6;
  uint uStack_4;
  
  ovc15_clearVisited();
  iStack_6 = 0;
  for (uStack_4 = 0; uStack_4 < EntityCount; uStack_4 = uStack_4 + 1) {
    uVar4 = (undefined2)((ulong)Entities >> 0x10);
    peVar1 = (entity_t *)Entities;
    if (((GfxRndSeed - 2U <= ((peVar1 + uStack_4)->base).x) &&
        (((peVar1 + uStack_4)->base).x <= GfxRndSeed + 1U)) &&
       (peVar1[uStack_4].base.y == GfxRndSeed2)) {
      *(uint *)(&agentIndices + iStack_6 * 2) = uStack_4;
      iStack_6 = iStack_6 + 1;
    }
  }
  iVar3 = 0;
  iVar2 = 0;
  while ((iVar2 < iStack_6 || (iVar3 < iStack_6))) {
    while( true ) {
      peVar1 = (entity_t *)Entities;
      uVar4 = (undefined2)((ulong)Entities >> 0x10);
      if ((iStack_6 <= iVar3) ||
         (*(char *)((int)(char **)GMenuStrings +
                   (uint)peVar1[*(int *)(&agentIndices + iVar3 * 2)].base.gindex * 0x95 + 0x1f) ==
          '\x01')) break;
      iVar3 = iVar3 + 1;
    }
    while ((iVar2 < iStack_6 &&
           (*(char *)((int)(char **)GMenuStrings +
                     (uint)peVar1[*(int *)(&agentIndices + iVar2 * 2)].base.gindex * 0x95 + 0x1f) !=
            '\0'))) {
      iVar2 = iVar2 + 1;
    }
    if (iVar3 < iStack_6) {
      uStack_8 = (peVar1[*(int *)(&agentIndices + iVar3 * 2)].base.animFrame + 0xf) / 0x10;
    }
    else {
      uStack_8 = 0;
    }
    if (iVar2 < iStack_6) {
      uStack_a = (peVar1[*(int *)(&agentIndices + iVar2 * 2)].base.animFrame + 0xf) / 0x10;
    }
    else {
      uStack_a = 0;
    }
    while ((uStack_8 != 0 || (uStack_a != 0))) {
      if (uStack_8 != 0) {
        ovc15_textArena(*(int *)(&agentIndices + iVar3 * 2));
        uStack_8 = uStack_8 - 1;
      }
      if (uStack_a != 0) {
        ovc15_textArena(*(int *)(&agentIndices + iVar2 * 2));
        uStack_a = uStack_a - 1;
      }
    }
    if (iVar3 < iStack_6) {
      iVar3 = iVar3 + 1;
    }
    if (iVar2 < iStack_6) {
      iVar2 = iVar2 + 1;
    }
  }
  for (uStack_4 = 0; agntIndex = uStack_4, (int)uStack_4 < (int)(uint)AgntCount;
      uStack_4 = uStack_4 + 1) {
    if (*(char *)(uStack_4 * 0x34 + 0x2d) == '\0') {
      uStack_4 = uStack_4 - 1;
      ovr_ovc41_removeAgent(agntIndex,0);
    }
  }
  AgntFlag1 = true;
  return;
}



/* 4207:0e17 */

/* Removes an entity record: kills its agents when AgntFlag1 is set, compacts the Entities array,
   fixes every agent's owner index/entity pointer, and decrements EntityCount. */

void __cdecl16far ovc15_removeEntity(uint entityIndex)

{
  int *piVar1;
  char cVar2;
  char partyIndex;
  uint16_t x;
  uint16_t y;
  word count;
  entity_t *peVar3;
  uint uVar4;
  uint unaff_DI;
  undefined2 uVar5;
  ulong uVar6;
  
  uVar6 = (ulong)unaff_DI << 0x10;
  if (AgntFlag1) {
    for (uVar4 = 0; uVar4 < AgntCount; uVar4 = uVar4 + 1) {
      if ((*(uint *)(uVar4 * 0x34 + 0x1b) == entityIndex) &&
         (*(char *)(uVar4 * 0x34 + 0x24) != '\x02')) {
        *(undefined1 *)(uVar4 * 0x34 + 0x24) = 2;
        *(undefined2 *)(uVar4 * 0x34 + 6) = 0;
      }
    }
  }
  uVar5 = (undefined2)((ulong)Entities >> 0x10);
  peVar3 = (entity_t *)Entities;
  x = peVar3[entityIndex].base.destX;
  y = peVar3[entityIndex].base.destY;
  cVar2 = *(char *)((int)(char **)GMenuStrings + (uint)peVar3[entityIndex].base.gindex * 0x95 + 0x1f
                   );
  partyIndex = *(char *)((int)&peVar3[entityIndex].base.entity + 3);
  if (entityIndex < EntityCount - 1U) {
    count = ((EntityCount + -1) - entityIndex) * 0x37;
    uVar6 = CONCAT22(unaff_DI,count);
    _fmemmove((char *)CONCAT22(uVar5,peVar3 + entityIndex),
              (char *)CONCAT22(uVar5,peVar3 + entityIndex + 1),count);
  }
  if (AgntFlag1 != false) {
    for (uVar4 = 0; uVar4 < AgntCount; uVar4 = uVar4 + 1) {
      if (entityIndex < *(uint *)(uVar4 * 0x34 + 0x1b)) {
        piVar1 = (int *)(uVar4 * 0x34 + 0x1b);
        *piVar1 = *piVar1 + -1;
        peVar3 = (entity_t *)Entities + *(int *)(uVar4 * 0x34 + 0x1b);
        uVar6 = CONCAT22((int)(uVar6 >> 0x10),(*(uint16_t *)((uint8_t *)&(Entities) + 2)));
        *(undefined2 *)(uVar4 * 0x34 + 0x19) = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
        *(undefined2 *)(uVar4 * 0x34 + 0x17) = peVar3;
      }
    }
  }
  EntityCount = EntityCount + -1;
  if ((cVar2 == '\0') && ((x != 0 || (y != 0)))) {
    ovr_attact_usesAlignUp4(x,y,partyIndex,uVar6 & 0xffff0000);
  }
  ovr_attact_usesGMapFlags3();
  return;
}



/* 4207:0ff0 */

/* [R4] calls ovr_alignUp4 */

uint __cdecl16far ovc15_usesAlignUp4(uint16_t x,uint16_t y)

{
  undefined4 uVar1;
  uint uVar2;
  uint16_t uVar3;
  entity_t *peVar4;
  uint uVar5;
  undefined2 uVar6;
  
  uVar2 = ovr_alignUp4(x);
  uVar5 = 0;
  uVar3 = uVar2;
  do {
    if (EntityCount <= uVar5) {
      return uVar3 & 0xff00;
    }
    uVar3 = uVar5 * 0x37;
    uVar6 = (undefined2)((ulong)Entities >> 0x10);
    peVar4 = (entity_t *)Entities;
    if ((((*(byte *)((int)&peVar4[uVar5].base.flags32 + 1) & 2) != 0) &&
        (uVar3 = peVar4[uVar5].base.targetY, uVar3 == y)) &&
       (uVar3 = ovr_alignUp4(peVar4[uVar5].base.targetX), uVar3 == uVar2)) {
      uVar3 = uVar5 * 0x37;
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      if ((*(char *)((int)&((entity_t *)Entities)[uVar5].base.entity + 3) != -1) &&
         (uVar1 = *(undefined4 *)
                   ((uint)*(byte *)((int)&((entity_t *)Entities)[uVar5].base.entity + 3) << 2),
         uVar3 = (uint16_t)*(byte *)((int)uVar1 + 0x3f), uVar3 == 0)) {
        return 1;
      }
    }
    uVar5 = uVar5 + 1;
  } while( true );
}



/* 4207:10a3 */

/* [R4] calls LDIV_at_ */

entity_t * __cdecl16far
ovc15_usesLDIV_at_(uint16_t x,uint16_t y,uint16_t destX,uint16_t destY,byte gindex,uint8_t animFrame
                  ,byte partyIndex)

{
  uint8_t *puVar1;
  uint *puVar2;
  undefined2 uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  entity_t *peVar7;
  undefined2 uVar8;
  long lVar9;
  int iStack_6;
  
  if (EntityCount < 0x259) {
    mapDirty = 1;
    if (PlayerIndex < 2) {
      if (0x21b < EntityCount) {
        uVar5 = ovc15_usesRandBelow2();
        ovc15_removeEntity(uVar5);
        EntityCount = EntityCount - 1;
      }
    }
    else if (599 < EntityCount) {
      uVar5 = ovc15_usesRandBelow2();
      ovc15_removeEntity(uVar5);
      EntityCount = EntityCount - 1;
    }
    _fsetmem((entity_t *)Entities + EntityCount,(uint16_t)((ulong)Entities >> 0x10),0x37);
    ((entity_t *)Entities)[EntityCount].base.targetX = destX;
    ((entity_t *)Entities)[EntityCount].base.targetY = destY;
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    if ((destX == x) && (destY == y)) {
      ((entity_t *)Entities)[EntityCount].base.destX = 0;
      ((entity_t *)Entities)[EntityCount].base.destY = 0;
    }
    else {
      ((entity_t *)Entities)[EntityCount].base.destX = destX;
      ((entity_t *)Entities)[EntityCount].base.destY = destY;
    }
    (((entity_t *)Entities + EntityCount)->base).x = x;
    ((entity_t *)Entities)[EntityCount].base.y = y;
    ((entity_t *)Entities)[EntityCount].base.target = 0xff;
    ((entity_t *)Entities)[EntityCount].base.gindex = gindex;
    uVar5 = EntityCount;
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    peVar7 = (entity_t *)Entities;
    puVar1 = &peVar7[EntityCount].base.frameIndex;
    puVar1[0] = 0x0;
    puVar1[1] = 0x0;
    puVar1 = &peVar7[uVar5].base.health;
    puVar1[0] = 0x64;
    puVar1[1] = 0x0;
    *(undefined2 *)((int)&((entity_t *)Entities)[EntityCount].base.frames + 1) = 0;
    ((entity_t *)Entities)[EntityCount].base.animFrame = animFrame;
    *(byte *)((int)&((entity_t *)Entities)[EntityCount].base.entity + 3) = partyIndex;
    *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
    *(undefined1 *)&((entity_t *)Entities)[EntityCount].base.flags32 =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
    if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x2f) != -1) {
      uVar5 = (uint)*(byte *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
      uVar8 = ovr_agnt_abilityModifier(partyIndex,4);
      iStack_6 = uVar5 + (int)(char)uVar8;
      if (iStack_6 < 1) {
        iStack_6 = 1;
      }
      *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
           (undefined1)iStack_6;
      *(undefined1 *)&((entity_t *)Entities)[EntityCount].base.flags32 = (undefined1)iStack_6;
    }
    if (*(char *)((int)(char **)GMenuStrings + (uint)gindex * 0x95 + 0x1f) == '\0') {
      uVar5 = ovc15_usesAlignUp4(destX,destY);
      if ((uVar5 & 0xff) == 0) {
        *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.flags32 + 1) = 2;
      }
    }
    else if ((destX == x) && (destY == y)) {
      *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.flags32 + 1) = 2;
    }
    if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)gindex * 0x95) & 0x1000) == 0) {
      if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)gindex * 0x95) & 0x2000) == 0) {
        lVar9 = 0x8000;
        uVar5 = rand();
        lVar9 = LDIV_at_(CONCAT22(((int)uVar5 >> 0xf) << 1 | (uint)((int)uVar5 < 0),uVar5 << 1),
                         lVar9);
        if ((int)lVar9 == 0) {
          puVar2 = (uint *)((int)&((entity_t *)Entities)[EntityCount].base.frames + 3);
          *puVar2 = *puVar2 | 1;
        }
      }
      else {
        puVar2 = (uint *)((int)&((entity_t *)Entities)[EntityCount].base.frames + 3);
        *puVar2 = *puVar2 | 1;
      }
    }
    ((entity_t *)Entities)[EntityCount].base.level =
         *(uint8_t *)((int)&worldMenuLabels[8].seg + (uint)gindex * 0x95);
    if ((((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 0x10) != 0) &&
        (*(byte *)((int)&worldMenuLabels[8].seg + (uint)gindex * 0x95) < 5)) &&
       (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)gindex * 0x95) != -1)) {
      while (((entity_t *)Entities)[EntityCount].base.level < 5) {
        cVar4 = ovc15_textView();
        uVar8 = (undefined2)((ulong)Entities >> 0x10);
        *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
             *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) + cVar4;
        uVar8 = (undefined2)((ulong)Entities >> 0x10);
        *(char *)&((entity_t *)Entities)[EntityCount].base.flags32 =
             (char)((entity_t *)Entities)[EntityCount].base.flags32 + cVar4;
        puVar1 = &((entity_t *)Entities)[EntityCount].base.level;
        *puVar1 = *puVar1 + 0x1;
      }
    }
    uVar5 = EntityCount;
    peVar7 = (entity_t *)Entities;
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)gindex * 0x95) == -1) {
      iVar6 = (uint)peVar7[EntityCount].base.level * 4;
      uVar3 = *(undefined2 *)(iVar6 + -4);
      *(undefined2 *)&peVar7[EntityCount].base.frameIndex = *(undefined2 *)(iVar6 + -2);
      *(undefined2 *)&peVar7[uVar5].base.health = uVar3;
    }
    else {
      iVar6 = (uint)*(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)gindex * 0x95) * 0x94 +
              (uint)peVar7[EntityCount].base.level * 4;
      uVar3 = *(undefined2 *)(iVar6 + -4);
      *(undefined2 *)&peVar7[EntityCount].base.frameIndex = *(undefined2 *)(iVar6 + -2);
      *(undefined2 *)&peVar7[uVar5].base.health = uVar3;
    }
    uVar5 = EntityCount;
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    peVar7 = (entity_t *)Entities;
    if (*(int *)&peVar7[EntityCount].base.health == 0 &&
        *(int *)&peVar7[EntityCount].base.frameIndex == 0) {
      puVar1 = &peVar7[EntityCount].base.frameIndex;
      puVar1[0] = 0x0;
      puVar1[1] = 0x0;
      puVar1 = &peVar7[uVar5].base.health;
      puVar1[0] = 0x64;
      puVar1[1] = 0x0;
    }
    uVar5 = EntityCount;
    EntityCount = EntityCount + 1;
    ovr_attact_usesGMapFlags3();
    if (AgntFlag1 != false) {
      uVar8 = (undefined2)((ulong)Entities >> 0x10);
      peVar7 = (entity_t *)Entities;
      if (((GfxRndSeed - 2U <= ((peVar7 + uVar5)->base).x) &&
          (((peVar7 + uVar5)->base).x <= GfxRndSeed + 1U)) && (peVar7[uVar5].base.y == GfxRndSeed2))
      {
        ovc15_textArena(uVar5);
      }
    }
    peVar7 = (entity_t *)Entities + uVar5;
    return peVar7;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x26);
}



/* 4207:16a5 */

/* [R4] calls LDIV_at_ */

void __cdecl16far ovc15_usesLDIV_at_2(int entityIndex,byte gindex,char partySlot)

{
  uint8_t *puVar1;
  uint *puVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  entity_t *peVar6;
  uint uVar7;
  uint16_t uVar8;
  entity_t *peVar9;
  int iVar10;
  int iVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  bool bVar14;
  long lVar15;
  
  if (partySlot != -1) {
    mapDirty = 1;
    peVar6 = (entity_t *)Entities;
    uVar5 = (undefined2)((ulong)Entities >> 0x10);
    ((entity_t *)Entities)[entityIndex].base.target = 0xff;
    peVar6[entityIndex].base.gindex = gindex;
    peVar6[entityIndex].base.level =
         *(uint8_t *)((int)&worldMenuLabels[8].seg + (uint)gindex * 0x95);
    puVar1 = &peVar6[entityIndex].base.frameIndex;
    puVar1[0] = 0x0;
    puVar1[1] = 0x0;
    puVar1 = &peVar6[entityIndex].base.health;
    puVar1[0] = 0x64;
    puVar1[1] = 0x0;
    *(undefined2 *)((int)&peVar6[entityIndex].base.frames + 1) = 0;
    *(undefined2 *)((int)&peVar6[entityIndex].base.frames + 3) = 0;
    *(char *)((int)&peVar6[entityIndex].base.entity + 3) = partySlot;
    *(undefined1 *)((int)&peVar6[entityIndex].base.state + 1) =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
    *(undefined1 *)&peVar6[entityIndex].base.flags32 =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
    lVar15 = 0x8000;
    uVar7 = rand();
    lVar15 = LDIV_at_(CONCAT22(((int)uVar7 >> 0xf) << 1 | (uint)((int)uVar7 < 0),uVar7 << 1),lVar15)
    ;
    if ((int)lVar15 == 0) {
      puVar2 = (uint *)((int)&peVar6[entityIndex].base.frames + 3);
      *puVar2 = *puVar2 | 1;
    }
    ovr_attact_usesGMapFlags3();
    if (AgntFlag1 != false) {
      uVar12 = (undefined2)((ulong)Entities >> 0x10);
      peVar9 = (entity_t *)Entities;
      if (((GfxRndSeed - 2U <= ((peVar9 + entityIndex)->base).x) &&
          (((peVar9 + entityIndex)->base).x <= GfxRndSeed + 1U)) &&
         (peVar9[entityIndex].base.y == GfxRndSeed2)) {
        for (iVar11 = 0; iVar11 < (int)(uint)AgntCount; iVar11 = iVar11 + 1) {
          if (*(int *)(iVar11 * 0x34 + 0x1b) == entityIndex) {
            *(undefined1 *)(iVar11 * 0x34 + 0xc) = 0xff;
            bVar3 = peVar6[entityIndex].base.gindex;
            *(undefined2 *)(iVar11 * 0x34 + 0x1f) = 0x195d;
            *(int *)(iVar11 * 0x34 + 0x1d) = (uint)bVar3 * 0x95 + 0x26d6;
            *(undefined1 *)(iVar11 * 0x34 + 0x21) =
                 *(undefined1 *)((int)&peVar6[entityIndex].base.state + 1);
            *(undefined1 *)(iVar11 * 0x34 + 0x22) = (char)peVar6[entityIndex].base.flags32;
            bVar14 = (*(uint *)((int)&peVar6[entityIndex].base.frames + 3) & 1) != 0;
            if (peVar6[entityIndex].base.level < 10) {
              if (peVar6[entityIndex].base.level < 4) {
                uVar4 = *(undefined4 *)(iVar11 * 0x34 + 0x1d);
                uVar13 = (undefined2)((ulong)uVar4 >> 0x10);
                iVar10 = (int)uVar4 + (uint)bVar14 * 0xc;
                uVar12 = *(undefined2 *)(iVar10 + 3);
                *(undefined2 *)(iVar11 * 0x34 + 0x15) = *(undefined2 *)(iVar10 + 5);
                *(undefined2 *)(iVar11 * 0x34 + 0x13) = uVar12;
              }
              else {
                uVar4 = *(undefined4 *)(iVar11 * 0x34 + 0x1d);
                uVar13 = (undefined2)((ulong)uVar4 >> 0x10);
                iVar10 = (int)uVar4 + (uint)bVar14 * 0xc;
                uVar12 = *(undefined2 *)(iVar10 + 7);
                *(undefined2 *)(iVar11 * 0x34 + 0x15) = *(undefined2 *)(iVar10 + 9);
                *(undefined2 *)(iVar11 * 0x34 + 0x13) = uVar12;
              }
            }
            else {
              uVar4 = *(undefined4 *)(iVar11 * 0x34 + 0x1d);
              uVar13 = (undefined2)((ulong)uVar4 >> 0x10);
              iVar10 = (int)uVar4 + (uint)bVar14 * 0xc;
              uVar12 = *(undefined2 *)(iVar10 + 0xb);
              *(undefined2 *)(iVar11 * 0x34 + 0x15) = *(undefined2 *)(iVar10 + 0xd);
              *(undefined2 *)(iVar11 * 0x34 + 0x13) = uVar12;
            }
            *(undefined1 *)(iVar11 * 0x34 + 0xe) = 0xff;
            *(undefined1 *)(iVar11 * 0x34 + 0x2f) =
                 *(undefined1 *)*(undefined4 *)(iVar11 * 0x34 + 0x1d);
            uVar4 = *(undefined4 *)(iVar11 * 0x34 + 0x13);
            uVar12 = (undefined2)((ulong)uVar4 >> 0x10);
            iVar10 = (int)uVar4;
            if ((*(int *)(iVar10 + 0x68) == 0 && *(int *)(iVar10 + 0x6a) == 0) ||
               (uVar4 = *(undefined4 *)(iVar11 * 0x34 + 0x13),
               uVar12 = (undefined2)((ulong)uVar4 >> 0x10), iVar10 = (int)uVar4,
               *(int *)(iVar10 + 0x58) == 0 && *(int *)(iVar10 + 0x5a) == 0)) {
              uVar4 = *(undefined4 *)(iVar11 * 0x34 + 0x13);
              uVar12 = (undefined2)((ulong)uVar4 >> 0x10);
              iVar10 = (int)uVar4;
              if (*(int *)(iVar10 + 0x68) == 0 && *(int *)(iVar10 + 0x6a) == 0) {
                *(undefined1 *)(iVar11 * 0x34 + 0x11) = 0;
              }
              else {
                *(undefined1 *)(iVar11 * 0x34 + 0x11) = 1;
              }
            }
            else {
              uVar8 = ovr_randBelow(2);
              *(undefined1 *)(iVar11 * 0x34 + 0x11) = (char)uVar8;
            }
            uVar8 = ovr_audio_panFromX((agnt_t *)CONCAT22(0x1726,(agnt_t *)(iVar11 * 0x34)));
            ovr_play_sfxU(0x1b,0,uVar8);
          }
        }
      }
    }
  }
  return;
}



/* 4207:1aae */

/* [R4] calls ovr_stExit */

void __cdecl16far ovc15_usesStExit(int entityIndex)

{
  uint8_t *puVar1;
  uint uVar2;
  entity_t *peVar3;
  int iVar4;
  uint uVar5;
  undefined2 uVar6;
  char cStack_5;
  
  if (EntityCount < 0x259) {
    if (EntityCount != 600) {
      memcpy((char *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),(entity_t *)Entities + EntityCount),
             (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),(entity_t *)Entities + entityIndex),0x37);
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      ((entity_t *)Entities)[EntityCount].base.animFrame =
           (uint8_t)((int)(uint)((entity_t *)Entities)[entityIndex].base.animFrame >> 1);
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      puVar1 = &((entity_t *)Entities)[entityIndex].base.animFrame;
      *puVar1 = *puVar1 - ((entity_t *)Entities)[EntityCount].base.animFrame;
      uVar2 = EntityCount;
      uVar5 = (uint)((entity_t *)Entities)[EntityCount].base.animFrame;
      EntityCount = EntityCount + 1;
      ovr_attact_usesGMapFlags3();
      if (AgntFlag1 != false) {
        cStack_5 = '\0';
        iVar4 = 0;
        while ((iVar4 < (int)(uint)AgntCount && (uVar5 != 0))) {
          if (*(int *)(iVar4 * 0x34 + 0x1b) == entityIndex) {
            if (cStack_5 == '\0') {
              *(uint *)(iVar4 * 0x34 + 0x1b) = uVar2;
              peVar3 = (entity_t *)Entities + uVar2;
              *(undefined2 *)(iVar4 * 0x34 + 0x19) = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
              *(undefined2 *)(iVar4 * 0x34 + 0x17) = peVar3;
              uVar5 = uVar5 - 1;
            }
            cStack_5 = '\x01' - (cStack_5 != '\0');
          }
          iVar4 = iVar4 + 1;
        }
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x26);
}



/* 4207:1c16 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_stshRealloc */

uint8_t * __cdecl16far ovc15_usesStshRealloc(char *text)

{
  uint8_t uVar1;
  size_t sVar2;
  uint8_t *puVar3;
  char *in_DX;
  
  sVar2 = strlen((char *)text);
  puVar3 = ovr_stshRealloc((uint32_t)_upperTextOfs,(ulong)(sVar2 + 1));
  _upperTextOfs = (uint8_t *)CONCAT22(in_DX,puVar3);
  strcpy((char *)puVar3,in_DX);
  uVar1 = toupper(*_upperTextOfs);
  *_upperTextOfs = uVar1;
  puVar3 = upperTextOfs;
  return puVar3;
}



/* 4207:1c79 */

/* Copies a string and capitalises its first character. */

char * __cdecl16far ovc15_capitalize(char *text)

{
  char cVar1;
  
  strcpy((char *)text,(*(uint16_t *)((uint8_t *)&(text) + 2)));
  cVar1 = toupper(*text);
  *text = cVar1;
  return (char *)text;
}



/* 4207:1cae */

void __cdecl16far stshStoreSprite(spr_t *spr,anm_t *anms,int16_t nanims)

{
  uint16_t uVar1;
  uint16_t uVar2;
  bool bVar3;
  uint16_t index;
  uint16_t pofs;
  uint16_t o;
  uint16_t i;
  uint16_t pseg;
  uint32_t cte;
  undefined2 in_stack_0000000a;
  int in_stack_0000000c;
  far_t pframe;
  uint8_t frmid;
  uint8_t first_frame;
  uint16_t next_ofs;
  uint16_t next_seg;
  
  for (i = 0; (int)i < in_stack_0000000c; i = i + 1) {
    index = (uint16_t)*(byte *)(nanims + i * 0x1e);
    if ((spr->frames + index + 0x15)->ofs != 0 || spr->frames[index + 0x15].seg != 0) {
      pframe.seg = spr->frames[index + 0x15].seg;
      pframe.ofs = (spr->frames + index + 0x15)->ofs;
      bVar3 = true;
      while( true ) {
        if (pframe.ofs == 0 && pframe.seg == 0) break;
        uVar1 = *(uint16_t *)(pframe.ofs + 3);
        uVar2 = *(uint16_t *)(pframe.ofs + 1);
        *(undefined2 *)(pframe.ofs + 3) = 0;
        *(undefined2 *)(pframe.ofs + 1) = 0;
        if (bVar3) {
          (*(uint16_t *)((uint8_t *)&(cte) + 2)) = uVar2;
          (*(uint16_t *)((uint8_t *)&(cte))) = ovr_stshStoreFile((uint8_t *)pframe.ofs);
          spr->frames[index + 0x15].seg = (*(uint16_t *)((uint8_t *)&(cte) + 2));
          (spr->frames + index + 0x15)->ofs = (uint16_t)(cte_t *)cte;
        }
        else {
          ovr_stshStoreFile((uint8_t *)pframe.ofs);
        }
        bVar3 = false;
        pframe.seg = uVar1;
        pframe.ofs = uVar2;
      }
    }
  }
  return;
}



/* 4207:1d87 */

/* [R4] calls ovr_stExit */

undefined2 __cdecl16far ovc15_usesStExit2(byte agntIndex)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uStack_12;
  int iStack_6;
  int iStack_4;
  
  piVar1 = (int *)((uint)agntIndex * 0x34);
  uStack_12 = (int *)CONCAT22(0x1726,piVar1);
  if ((((piVar1[1] < 0x14) || (*(char *)((int)piVar1 + 0x25) == '\x01')) && (*uStack_12 < 0xd3)) &&
     (-1 < *uStack_12)) {
    piVar4 = (int *)(*(int *)((int)piVar1 + 0x13) + (uint)*(byte *)(piVar1 + 9) * 4);
    iVar3 = piVar4[1];
    iVar5 = *piVar4;
    iStack_4 = piVar1[1] >> 1;
    if (iStack_4 < 0) {
      iStack_4 = 0;
    }
    if (8 < iStack_4) {
      iStack_4 = 8;
    }
    iStack_6 = *piVar1 - *(int *)(iVar5 + 0x17) >> 1;
    iVar3 = *piVar1 + *(int *)(iVar5 + 0x17) >> 1;
    if (iStack_6 < 0) {
      iStack_6 = 0;
    }
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    if (0x68 < iStack_6) {
      iStack_6 = 0x68;
    }
    if (0x68 < iVar3) {
      iVar3 = 0x68;
    }
    if (iVar3 < iStack_6) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x25);
    }
    iVar5 = iStack_6;
    if (*(char *)((int)piVar1 + 0x11) == '\0') {
      for (; iVar5 <= iVar3; iVar5 = iVar5 + 1) {
        if (agntIndex + 1 != (uint)*(byte *)(iStack_4 * 0x69 + iVar5 + 0x8fa)) {
          return 0;
        }
      }
      for (; iStack_6 <= iVar3; iStack_6 = iStack_6 + 1) {
        if (agntIndex + 1 != (uint)*(byte *)(iStack_4 * 0x69 + iStack_6 + 0x963)) {
          return 0;
        }
      }
    }
    else {
      for (; iVar5 <= iVar3; iVar5 = iVar5 + 1) {
        if (agntIndex + 1 != (uint)*(byte *)(iStack_4 * 0x69 + iVar5 + 0x4e0)) {
          return 0;
        }
      }
      for (; iStack_6 <= iVar3; iStack_6 = iStack_6 + 1) {
        if (agntIndex + 1 != (uint)*(byte *)(iStack_4 * 0x69 + iStack_6 + 0x549)) {
          return 0;
        }
      }
    }
    uVar2 = 1;
  }
  else {
    uVar2 = CONCAT11((char)((uint)piVar1 >> 8),1);
  }
  return uVar2;
}



/* 4207:1f5b */

/* [R7] body shape: compute */

undefined2 __cdecl16far ovc15_compute1(uint16_t *agnt)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 in_stack_00000006;
  undefined1 uStack_c;
  undefined4 uStack_6;
  
  uVar1 = *(undefined2 *)((int)agnt + 0x15);
  piVar2 = (int *)*(int *)((int)agnt + 0x13);
  uStack_6 = (int *)CONCAT22(uVar1,piVar2);
  if (*(char *)((int)agnt + 0x11) == '\0') {
    iVar5 = piVar2[1];
    iVar3 = *uStack_6;
    iVar4 = ovr_agnt_clampX(*_agnt);
    iVar5 = (*(int *)(iVar3 + 0xd) - *(int *)(iVar4 * 2 + 0x34c)) + 0x93;
    uStack_c = (undefined1)iVar5;
  }
  else {
    iVar5 = piVar2[9];
    iVar3 = piVar2[8];
    iVar4 = ovr_agnt_clampX(*_agnt);
    iVar5 = (*(int *)(iVar3 + 0xd) - *(int *)(iVar4 * 2 + 0x34c)) + 0xac;
    uStack_c = (undefined1)iVar5;
  }
  return CONCAT11((char)((uint)iVar5 >> 8),uStack_c);
}



/* 4207:1ffe */

/* [R4] calls ovr_randBelow */

int __cdecl16far ovc15_usesRandBelow(agnt_t *agnt,int xSide,char keepPos,char randomY)

{
  char *pcVar1;
  far_t dst;
  uint16_t uVar2;
  uint16_t uVar3;
  uint uVar4;
  byte bVar6;
  int iVar5;
  agnt_t *agnt_00;
  undefined2 uVar7;
  uint16_t unaff_SS;
  uint16_t xOffsets [4];
  int iStack_6;
  int iStack_4;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)xOffsets;
  F_SCOPY(far_from_u32((uint32_t)(0x24101d09)),dst);
  agnt_00 = (agnt_t *)agnt;
  uVar7 = (undefined2)((ulong)agnt >> 0x10);
  if (keepPos == '\0') {
    if (xSide < 0) {
      agnt->x = 0;
      uVar2 = ovr_randBelow(0x14);
      agnt_00->y = uVar2 & 0xff;
    }
    else if (xSide < 1) {
      iVar5 = ((agnt_00->entity->base).x - GfxRndSeed) + 2;
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      if (3 < iVar5) {
        iVar5 = 3;
      }
      agnt->x = xOffsets[iVar5];
      if (randomY == '\0') {
        agnt_00->y = 0x20;
      }
      else {
        uVar2 = ovr_randBelow(0x14);
        agnt_00->y = uVar2 & 0xff;
      }
    }
    else {
      agnt->x = 0xd2;
      uVar2 = ovr_randBelow(0x14);
      agnt_00->y = uVar2 & 0xff;
    }
  }
  uVar2 = agnt->x;
  if ((int)uVar2 < 0x6a) {
    iStack_6 = 1;
  }
  else {
    iStack_6 = -1;
  }
  ovr_ovc49_body1(agnt);
  do {
    if (agnt_00->animVariant == 0x0) {
      uVar4 = ovr_ovc49_compute1(agnt->x);
      bVar6 = (byte)(uVar4 >> 8);
      if ((char)uVar4 == '\0') goto L_OVC15_4207_1ffe_2193;
    }
    else {
L_OVC15_4207_1ffe_2193:
      iVar5 = ovr_ovc49_usesStExit(agnt_00);
      bVar6 = (byte)((uint)iVar5 >> 8);
      if ((char)iVar5 == '\0') {
        if (agnt_00->y == 0x20) {
          uVar4 = ovc15_compute1(&agnt_00->x);
          agnt_00->y = uVar4 & 0xff;
        }
        iStack_4 = 0;
        while ((iStack_4 < (int)(uint)AgntCount && (*(int *)(iStack_4 * 0x34 + 2) < (int)agnt_00->y)
               )) {
          iStack_4 = iStack_4 + 1;
        }
        if (iStack_4 < (int)(uint)AgntCount) {
          _fmemmove((char *)CONCAT22(0x1726,(char *)(iStack_4 * 0x34 + 0x34)),
                    (char *)CONCAT22(0x1726,(char *)(iStack_4 * 0x34)),
                    ((uint)AgntCount - iStack_4) * 0x34);
        }
        agnt_00->visited = 0x1;
        memcpy((char *)CONCAT22(0x1726,(char *)(iStack_4 * 0x34)),(char *)agnt,0x34);
        ovr_agnt_usesAgntCount5(iStack_4 + 1);
        ovr_ovc49_fillGridCells((char)iStack_4 + 1,(agnt_t *)(iStack_4 * 0x34));
        AgntCount = AgntCount + 1;
        for (iVar5 = 0; iVar5 < (int)(uint)AgntCount; iVar5 = iVar5 + 1) {
          if ((*(char *)(iVar5 * 0x34 + 0xc) != -1) &&
             (iStack_4 <= (int)(uint)*(byte *)(iVar5 * 0x34 + 0xc))) {
            pcVar1 = (char *)(iVar5 * 0x34 + 0xc);
            *pcVar1 = *pcVar1 + '\x01';
          }
        }
        return 1;
      }
    }
    if (iStack_6 < 0) {
      if (agnt->x == 0) {
        agnt->x = 0xd2;
      }
      else {
        agnt->x = agnt->x - 1;
      }
    }
    else if (agnt->x == 0xd2) {
      agnt->x = 0;
    }
    else {
      agnt->x = agnt->x + 1;
    }
    if (agnt->x == uVar2) {
      return (uint)bVar6 << 8;
    }
    if ((xSide == 0) && (randomY == '\0')) {
      agnt_00->y = 0x20;
    }
    else {
      uVar3 = ovr_randBelow(0x14);
      agnt_00->y = uVar3 & 0xff;
    }
    ovr_ovc49_body1(agnt);
  } while( true );
}



/* 4207:2301 */

/* [R2] string "arena" */

char * __cdecl16far ovc15_textArena(int owner)

{
  bool bVar1;
  uint uVar2;
  uint16_t uVar3;
  char *pcVar4;
  entity_t *peVar5;
  agntG_t *paVar6;
  far_t *pfVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  uint16_t unaff_SS;
  int in_stack_00000006;
  char in_stack_00000008;
  agnt_t agntCopy;
  uint uStack_8;
  
  uVar9 = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
  if (AgntFlag1) {
    for (uStack_8 = 0; (int)uStack_8 < (int)(uint)AgntCount; uStack_8 = uStack_8 + 1) {
      if (((*(char *)(uStack_8 * 0x34 + 0x2d) == '\0') &&
          (*(int *)(uStack_8 * 0x34 + 0x1b) == owner)) &&
         ((*(uint *)(uStack_8 * 0x34 + 0x2b) & 0xae4) == 0)) {
        *(undefined1 *)(uStack_8 * 0x34 + 0x2d) = 1;
        if ((*(char *)(uStack_8 * 0x34 + 0x11) != '\0') ||
           (uVar2 = ovr_ovc49_compute1(*(int *)(uStack_8 * 0x34)), (char)uVar2 == '\0')) {
          uVar2 = ovc15_usesStExit2((byte)uStack_8);
          if ((uVar2 & 0xff) != 0) {
            return (char *)((int)(undefined4 *)&_DATA + 1);
          }
        }
        _fmemmove((char *)CONCAT22(unaff_SS,&agntCopy),
                  (char *)CONCAT22(0x1726,(char *)(uStack_8 * 0x34)),0x34);
        agntCopy.target = 0xff;
        ovr_ovc41_removeAgent(uStack_8,0);
        pcVar4 = (char *)ovc15_usesRandBelow((agnt_t *)CONCAT22(unaff_SS,&agntCopy),
                                             in_stack_00000006,'\x01',in_stack_00000008);
        return pcVar4;
      }
    }
  }
  if (AgntCount < 0x18) {
    peVar5 = (entity_t *)Entities + owner;
    _fmemset(&agntCopy,unaff_SS,0);
    agntCopy.target = 0xff;
    (*(uint16_t *)((uint8_t *)&(agntCopy.entity) + 2)) = uVar9;
    agntCopy.owner = owner;
    agntCopy.gdata =
         (agntG_t *)
         CONCAT22(0x195d,(agntG_t *)
                         ((int)(char **)GMenuStrings + (uint)(peVar5->base).gindex * 0x95 + 0x1f));
    (*(uint16_t *)((uint8_t *)&(agntCopy.entity))) = peVar5;
    bVar1 = ovc15_usesAlignUp42();
    if (!bVar1) {
      *(undefined1 *)((int)&(peVar5->base).state + 1) = (char)(peVar5->base).flags32;
    }
    agntCopy.strengthMax = (uint8_t)(peVar5->base).flags32;
    agntCopy.strength = *(uint8_t *)((int)&(peVar5->base).state + 1);
    bVar1 = (*(uint *)((int)&(peVar5->base).frames + 3) & 1) != 0;
    paVar6 = (agntG_t *)agntCopy.gdata;
    uVar8 = (undefined2)((ulong)agntCopy.gdata >> 0x10);
    if ((peVar5->base).level < 10) {
      if ((peVar5->base).level < 4) {
        agntCopy.frames =
             (far_t *)CONCAT22(*(undefined2 *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 2),
                               *(far_t **)(paVar6->sprs + (uint)bVar1 * 3));
      }
      else {
        agntCopy.frames =
             (far_t *)CONCAT22(*(undefined2 *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 6),
                               *(far_t **)(paVar6->sprs + (uint)bVar1 * 3 + 1));
      }
    }
    else {
      agntCopy.frames =
           (far_t *)CONCAT22(*(undefined2 *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 10),
                             *(far_t **)(paVar6->sprs + (uint)bVar1 * 3 + 2));
    }
    agntCopy.animFrame = 0xff;
    agntCopy.faction = (agntCopy.gdata)->ai;
    uVar9 = (undefined2)((ulong)agntCopy.frames >> 0x10);
    pfVar7 = (far_t *)agntCopy.frames;
    if (((pfVar7 + 0x1a)->ofs == 0 && pfVar7[0x1a].seg == 0) ||
       ((pfVar7 + 0x16)->ofs == 0 && pfVar7[0x16].seg == 0)) {
      if ((pfVar7 + 0x1a)->ofs != 0 || pfVar7[0x1a].seg != 0) {
        agntCopy.animVariant = 0x1;
      }
    }
    else {
      uVar3 = ovr_randBelow(2);
      agntCopy.animVariant = (uint8_t)uVar3;
    }
    uVar3 = ovr_randBelow(2);
    (*(uint8_t *)((uint8_t *)&(agntCopy.targetX))) = (char)uVar3 * '\x02' + -1;
    if ((char)agntCopy.targetX < '\x01') {
      if ((char)agntCopy.targetX < '\0') {
        agntCopy.level = 0x1;
      }
      else {
        uVar3 = ovr_randBelow(2);
        agntCopy.level = (uint8_t)uVar3;
      }
    }
    else {
      agntCopy.level = 0x0;
    }
    pcVar4 = (char *)ovc15_usesRandBelow((agnt_t *)CONCAT22(unaff_SS,&agntCopy),in_stack_00000006,
                                         '\0',in_stack_00000008);
  }
  else {
    pcVar4 = (char *)"arena" + 4;
  }
  return pcVar4;
}



/* 4207:25dd */

/* WARNING: Control flow encountered bad instruction data */
/* [R2] string "View %s." */

entity_t * __cdecl16far
ovc15_textView(undefined4 param_1,int *param_2,int *param_3,undefined2 param_4,undefined2 param_5,
              int *param_6,int *param_7,int *param_8,int *param_9)

{
  uint8_t *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char cVar4;
  byte bVar5;
  far_t *pfVar6;
  int iVar7;
  stg_tmp_t *gfx;
  cte_t *pcVar8;
  uint32_t *puVar9;
  uint uVar10;
  undefined2 uVar11;
  long *plVar12;
  undefined2 uVar13;
  entity_t *peVar14;
  uint uVar15;
  int iVar16;
  undefined2 unaff_BP;
  int unaff_SI;
  uint unaff_DI;
  int iVar17;
  uint16_t unaff_SS;
  bool bVar18;
  uint8_t in_stack_00000000;
  far_t pixels;
  undefined4 in_stack_0000ffee;
  far_t handle;
  far_t handle_00;
  far_t *in_stack_0000fff8;
  undefined1 uStack_6;
  byte bStack_5;
  undefined1 uVar19;
  byte in_stack_0000fffc;
  undefined1 uVar20;
  undefined1 in_stack_0000fffd;
  
  iVar17 = (int)((ulong)param_1 >> 0x10);
  uVar15 = (uint)param_1;
  bStack_5 = *(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)*(byte *)(uVar15 + 0xd) * 0x95);
  if (bStack_5 == 0xff) {
    bStack_5 = 0;
  }
  uVar10 = bStack_5 - 1;
  if (5 < uVar10) {
    if (*(byte *)(uVar15 + 0xf) < 10) {
      bVar5 = ovr_manage_rollDice('\x01','\b');
      uVar10 = (uint)bVar5;
      uVar11 = ovr_agnt_abilityModifier(*(byte *)(uVar15 + 0x1a),4);
      iVar17 = uVar10 + (int)(char)uVar11;
    }
    else {
      iVar17 = 2;
    }
    bVar5 = (byte)iVar17;
    if (iVar17 < 1) {
      bVar5 = 1;
    }
    return (entity_t *)(uint)bVar5;
  }
  iVar16 = uVar10 * 2;
  bVar18 = iVar16 == 0;
  switch(uVar10) {
  case 1:
    *(undefined2 *)((int)AgntGs[0].sprs + 10 + iVar16) = 0x195d;
    do {
      *(uint *)((int)AgntGs[0].sprs + 8 + iVar16) = uVar10;
      while( true ) {
        for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
          if (*(int *)((int)AgntGs[0].sprfls + 6 + unaff_SI * 0x95 + iVar17 * 2) == 0) {
            iVar16 = unaff_SI * 0x95 + iVar17 * 4;
            uVar11 = *(undefined2 *)((int)AgntGs[0].sprs + iVar16);
            iVar7 = unaff_SI * 0x95 + iVar17 * 4;
            *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar7) =
                 *(undefined2 *)((int)AgntGs[0].sprs + 2 + iVar16);
            *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar7) = uVar11;
          }
          else {
            uVar11 = 0x195d;
            pfVar6 = stshSprite((far_t *)*(undefined2 *)
                                          ((int)AgntGs[0].sprfls + 6 + unaff_SI * 0x95 + iVar17 * 2)
                                ,*(int16_t *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                                (anm_t *)*(undefined2 *)((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95)
                                ,(uint)*(byte *)((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                                (*(uint8_t *)((uint8_t *)&(param_1))));
            iVar16 = unaff_SI * 0x95 + iVar17 * 4;
            *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar16) = uVar11;
            *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar16) = pfVar6;
          }
        }
        for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
          uVar11 = 0x195d;
          if (*(int *)((int)AgntGs[0].prtfls + unaff_SI * 0x95 + iVar17 * 2) != 0) {
            if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
              pfVar6 = ovr_stshAllocStub(in_stack_0000fff8);
              iVar16 = unaff_SI * 0x95 + iVar17 * 4;
              uVar13 = 0x195d;
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar16) = uVar11;
              *(undefined2 *)((int)AgntGs[0].prts + iVar16) = pfVar6;
              pfVar6 = ovr_stshAllocStub(in_stack_0000fff8);
              iVar16 = unaff_SI * 0x95 + iVar17 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar16) = uVar13;
              *(undefined2 *)((int)AgntGs[0].prtpals + iVar16) = pfVar6;
            }
            else {
              uVar11 = 0x195d;
              gfx = ovr_grabLbm(*(int16_t *)((int)AgntGs[0].prtfls + unaff_SI * 0x95 + iVar17 * 2),0
                                ,0);
              uVar19 = (undefined1)uVar11;
              uVar20 = (undefined1)((uint)uVar11 >> 8);
              uStack_6 = SUB21(gfx,0);
              bStack_5 = (byte)((uint)gfx >> 8);
              ovr_stshUniqueColorsRemap(gfx);
              iVar16 = CONCAT11(bStack_5,uStack_6);
              uVar13 = (undefined2)(CONCAT13(uVar20,CONCAT12(uVar19,iVar16)) >> 0x10);
              pixels.seg = 0;
              pixels.ofs = *(uint *)(iVar16 + 0x302);
              pfVar6 = ovr_stshRleType2((far_t *)*(undefined2 *)(iVar16 + 0x300),pixels,0,114,103,0,
                                        0,(int16_t)in_stack_0000fff8);
              pcVar8 = ovr_stshStoreFile((uint8_t *)pfVar6);
              iVar16 = unaff_SI * 0x95 + iVar17 * 4;
              uVar13 = 0x195d;
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar16) = uVar11;
              *(undefined2 *)((int)AgntGs[0].prts + iVar16) = pcVar8;
              puVar9 = ovr_stshWrite((uint32_t *)CONCAT11(bStack_5,uStack_6),
                                     (uint8_t *)CONCAT11(uVar20,uVar19),0x300);
              iVar16 = unaff_SI * 0x95 + iVar17 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar16) = uVar13;
              *(undefined2 *)((int)AgntGs[0].prtpals + iVar16) = puVar9;
              ovr_stgFreeTmp((stg_tmp_t *)CONCAT11(bStack_5,uStack_6));
            }
          }
        }
        peVar14 = (entity_t *)
                  (*(uint *)((int)AgntGs[0].prts + 4 + unaff_SI * 0x95) |
                  *(uint *)((int)AgntGs[0].prts + 6 + unaff_SI * 0x95));
        if ((peVar14 == (entity_t *)0x0) &&
           (peVar14 = (entity_t *)0x0,
           *(int *)((int)AgntGs[0].prts + unaff_SI * 0x95) != 0 ||
           *(int *)((int)AgntGs[0].prts + 2 + unaff_SI * 0x95) != 0)) {
          uVar11 = *(undefined2 *)((int)AgntGs[0].prts + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].prts + 6 + unaff_SI * 0x95) =
               *(undefined2 *)((int)AgntGs[0].prts + 2 + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].prts + 4 + unaff_SI * 0x95) = uVar11;
          peVar14 = (entity_t *)*(uint *)((int)AgntGs[0].prtpals + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].prtpals + 6 + unaff_SI * 0x95) =
               *(undefined2 *)((int)AgntGs[0].prtpals + 2 + unaff_SI * 0x95);
          *(uint *)((int)AgntGs[0].prtpals + 4 + unaff_SI * 0x95) = (uint)peVar14;
        }
        for (iVar17 = 2; iVar17 < 6; iVar17 = iVar17 + 2) {
          iVar16 = unaff_SI * 0x95 + iVar17 * 4;
          if ((*(int *)((int)AgntGs[0].prts + 4 + iVar16) == 0 &&
               *(int *)((int)AgntGs[0].prts + 6 + iVar16) == 0) &&
             (iVar16 = unaff_SI * 0x95 + iVar17 * 4,
             *(int *)((int)AgntGs[0].prtfls + 8 + iVar16) != 0 ||
             *(int *)((int)AgntGs[0].prtfls + 10 + iVar16) != 0)) {
            iVar16 = unaff_SI * 0x95 + iVar17 * 4;
            uVar11 = *(undefined2 *)((int)AgntGs[0].prtfls + 8 + iVar16);
            iVar7 = unaff_SI * 0x95 + iVar17 * 4;
            *(undefined2 *)((int)AgntGs[0].prts + 6 + iVar7) =
                 *(undefined2 *)((int)AgntGs[0].prtfls + 10 + iVar16);
            *(undefined2 *)((int)AgntGs[0].prts + 4 + iVar7) = uVar11;
            iVar16 = unaff_SI * 0x95 + iVar17 * 4;
            uVar11 = *(undefined2 *)((int)AgntGs[0].prts + 0x14 + iVar16);
            iVar7 = unaff_SI * 0x95 + iVar17 * 4;
            *(undefined2 *)((int)AgntGs[0].prtpals + 6 + iVar7) =
                 *(undefined2 *)((int)AgntGs[0].prts + 0x16 + iVar16);
            *(undefined2 *)((int)AgntGs[0].prtpals + 4 + iVar7) = uVar11;
          }
          iVar16 = unaff_SI * 0x95 + iVar17 * 4;
          peVar14 = (entity_t *)
                    (*(uint *)((int)AgntGs[0].prts + iVar16) |
                    *(uint *)((int)AgntGs[0].prts + 2 + iVar16));
          if (peVar14 == (entity_t *)0x0) {
            iVar16 = unaff_SI * 0x95 + iVar17 * 4;
            if (*(int *)((int)AgntGs[0].prtfls + 4 + iVar16) == 0 &&
                *(int *)((int)AgntGs[0].prtfls + 6 + iVar16) == 0) {
              peVar14 = (entity_t *)0x0;
            }
            else {
              iVar16 = unaff_SI * 0x95 + iVar17 * 4;
              uVar11 = *(undefined2 *)((int)AgntGs[0].prtfls + 4 + iVar16);
              iVar7 = unaff_SI * 0x95 + iVar17 * 4;
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar7) =
                   *(undefined2 *)((int)AgntGs[0].prtfls + 6 + iVar16);
              *(undefined2 *)((int)AgntGs[0].prts + iVar7) = uVar11;
              iVar16 = unaff_SI * 0x95 + iVar17 * 4;
              peVar14 = (entity_t *)*(uint *)((int)AgntGs[0].prts + 0x10 + iVar16);
              iVar7 = unaff_SI * 0x95 + iVar17 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar7) =
                   *(undefined2 *)((int)AgntGs[0].prts + 0x12 + iVar16);
              *(uint *)((int)AgntGs[0].prtpals + iVar7) = (uint)peVar14;
            }
          }
        }
        unaff_SI = unaff_SI + 1;
        if (0x29 < unaff_SI) {
          return peVar14;
        }
        uVar11 = 0x195d;
        pfVar6 = stshSprite((far_t *)*(undefined2 *)((int)AgntGs[0].sprfls + unaff_SI * 0x95),
                            *(int16_t *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                            (anm_t *)*(undefined2 *)((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95),
                            (uint)*(byte *)((int)&AgntGs[0].nanims + unaff_SI * 0x95),(*(uint8_t *)((uint8_t *)&(param_1))))
        ;
        *(undefined2 *)((int)AgntGs[0].sprs + 2 + unaff_SI * 0x95) = uVar11;
        *(undefined2 *)((int)AgntGs[0].sprs + unaff_SI * 0x95) = pfVar6;
        if (*(int *)((int)AgntGs[0].sprfls + 2 + unaff_SI * 0x95) == 0) {
          uVar11 = *(undefined2 *)((int)AgntGs[0].sprs + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95) =
               *(undefined2 *)((int)AgntGs[0].sprs + 2 + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95) = uVar11;
        }
        else {
          uVar11 = 0x195d;
          pfVar6 = stshSprite((far_t *)*(undefined2 *)((int)AgntGs[0].sprfls + 2 + unaff_SI * 0x95),
                              *(int16_t *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                              (anm_t *)*(undefined2 *)((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95),
                              (uint)*(byte *)((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                              (*(uint8_t *)((uint8_t *)&(param_1))));
          *(undefined2 *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95) = uVar11;
          *(undefined2 *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95) = pfVar6;
        }
        if (*(int *)((int)AgntGs[0].sprfls + 4 + unaff_SI * 0x95) == 0) break;
        uVar11 = 0x195d;
        pfVar6 = stshSprite((far_t *)*(undefined2 *)((int)AgntGs[0].sprfls + 4 + unaff_SI * 0x95),
                            *(int16_t *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                            (anm_t *)*(undefined2 *)((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95),
                            (uint)*(byte *)((int)&AgntGs[0].nanims + unaff_SI * 0x95),(*(uint8_t *)((uint8_t *)&(param_1))))
        ;
        *(undefined2 *)((int)AgntGs[0].sprs + 10 + unaff_SI * 0x95) = uVar11;
        *(undefined2 *)((int)AgntGs[0].sprs + 8 + unaff_SI * 0x95) = pfVar6;
      }
      uVar10 = *(uint *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95);
      iVar16 = unaff_SI * 0x95;
      *(undefined2 *)((int)AgntGs[0].sprs + 10 + iVar16) =
           *(undefined2 *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95);
    } while( true );
  case 2:
    do {
      cVar4 = ovc15_textView();
      bStack_5 = 0;
      uVar11 = (undefined2)((ulong)Entities >> 0x10);
      *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
           *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) + cVar4;
      uVar11 = (undefined2)((ulong)Entities >> 0x10);
      *(char *)&((entity_t *)Entities)[EntityCount].base.flags32 =
           (char)((entity_t *)Entities)[EntityCount].base.flags32 + cVar4;
      puVar1 = &((entity_t *)Entities)[EntityCount].base.level;
      *puVar1 = *puVar1 + 0x1;
      iVar17 = EntityCount;
      uVar11 = (undefined2)((ulong)Entities >> 0x10);
      peVar14 = (entity_t *)Entities;
    } while (peVar14[EntityCount].base.level < 5);
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)param_3 * 0x95) == -1) {
      iVar16 = (uint)peVar14[EntityCount].base.level * 4;
      uVar13 = *(undefined2 *)(iVar16 + -4);
      *(undefined2 *)&peVar14[EntityCount].base.frameIndex = *(undefined2 *)(iVar16 + -2);
      *(undefined2 *)&peVar14[iVar17].base.health = uVar13;
    }
    else {
      iVar16 = (uint)*(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)param_3 * 0x95) * 0x94
               + (uint)peVar14[EntityCount].base.level * 4;
      uVar13 = *(undefined2 *)(iVar16 + -4);
      *(undefined2 *)&peVar14[EntityCount].base.frameIndex = *(undefined2 *)(iVar16 + -2);
      *(undefined2 *)&peVar14[iVar17].base.health = uVar13;
    }
    iVar17 = EntityCount;
    uVar11 = (undefined2)((ulong)Entities >> 0x10);
    peVar14 = (entity_t *)Entities;
    if (*(int *)&peVar14[EntityCount].base.health == 0 &&
        *(int *)&peVar14[EntityCount].base.frameIndex == 0) {
      puVar1 = &peVar14[EntityCount].base.frameIndex;
      puVar1[0] = 0x0;
      puVar1[1] = 0x0;
      puVar1 = &peVar14[iVar17].base.health;
      puVar1[0] = 0x64;
      puVar1[1] = 0x0;
    }
    bVar5 = (byte)EntityCount;
    uVar19 = (undefined1)((uint)EntityCount >> 8);
    EntityCount = EntityCount + 1;
    ovr_attact_usesGMapFlags3();
    if (AgntFlag1 != false) {
      uVar11 = (undefined2)((ulong)Entities >> 0x10);
      peVar14 = (entity_t *)Entities;
      if (((GfxRndSeed - 2 <= ((peVar14 + CONCAT11(uVar19,bVar5))->base).x) &&
          (((peVar14 + CONCAT11(uVar19,bVar5))->base).x <= GfxRndSeed + 1)) &&
         (peVar14[CONCAT11(uVar19,bVar5)].base.y == GfxRndSeed2)) {
        ovc15_textArena(CONCAT11(uVar19,bVar5));
      }
    }
    peVar14 = (entity_t *)Entities + bVar5;
    return peVar14;
  case 3:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 4:
    uVar2 = *(undefined4 *)((uint)PartyCount * 4 + -4);
    ovr_createConstructionRecordFar
              (*(byte *)((int)(far_t *)(worldMenuLabels + 0xb) +
                        (uint)*(byte *)((int)uVar2 + 0x3e) * 0x95),GfxRndSeed - 1,GfxRndSeed2,
               &bStack_5,(byte)unaff_SS,(char)in_stack_0000fff8);
    ovc18_textTypeLen(PartyCount - 1,GfxRndSeed,GfxRndSeed2,0x0);
    if (2 < Difficulty) {
      ovr_ovc22_usesRandBelow2(PartyCount - 1,(uint16_t)&bStack_5,unaff_SS);
    }
    ovr_ovc22_textRingProt(PartyCount - 1);
    PartyCount = 0;
    ovr_manage_mapPartySlots();
    ovr_stats_openCastlePanel();
    ovr_unit_usesAlignUp4();
    ovr_say((char *)"View %s." + 8);
    peVar14 = (entity_t *)(uint)PlayerIndex;
    if (peVar14 == (entity_t *)0x0) {
      ovr_ovc30_nextWave(2);
    }
    return peVar14;
  case 5:
    do {
      if (bVar18) {
        *param_9 = *param_9 + 1;
      }
      while( true ) {
        while( true ) {
          do {
            do {
              unaff_DI = unaff_DI + 1;
              if (GRecordCount <= unaff_DI) {
                iVar17 = *param_8;
                iVar16 = *param_9;
                *param_2 = *param_2 - *param_8;
                *param_3 = *param_3 - *param_9;
                return (entity_t *)((uint)in_stack_0000fffc - (iVar17 + iVar16) & 0xff);
              }
            } while ((bool)*(char *)(unaff_DI * 0x12 + 9) != (*(uint8_t *)((uint8_t *)&(param_1))));
            bVar5 = *(byte *)(unaff_DI * 0x12 + 8);
          } while (*(char *)((uint)bVar5 * 0x27 + 0x133) != (*(uint8_t *)((uint8_t *)&(param_1) + 2)));
          *param_6 = *param_6 + 1;
          if (*(char *)((uint)bVar5 * 0x27 + 0x131) != '\x01') break;
          *param_7 = *param_7 + 1;
        }
        if (*(char *)((uint)bVar5 * 0x27 + 0x131) != '\x02') break;
        *param_8 = *param_8 + 1;
      }
      bVar18 = *(char *)((uint)bVar5 * 0x27 + 0x131) == '\x03';
    } while( true );
  }
  if (((byte)uVar10 & (&stack0x02c2)[unaff_DI]) == 0) {
    iVar17 = iVar17 + (uint)(0xffec < uVar15);
    plVar12 = LXRSH_at_((long *)in_stack_0000fff8,
                        CONCAT22(unaff_BP,CONCAT11(in_stack_0000fffd,in_stack_0000fffc)),
                        in_stack_00000000);
    uVar10 = (int)plVar12 + HeapPtr;
    iVar17 = iVar17 + (uint)CARRY2((uint)plVar12,HeapPtr);
    uVar15 = uVar10;
    if (iVar17 != 0) {
      uVar15 = 0xffff;
    }
    if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar17 != 0 || (MUSHandle.seg < uVar10))))
       || ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 && ((iVar17 != 0 || (MUSHandle.seg < uVar10))))
          )) {
      ovr_fmFreeAudio(1);
    }
    HeapPtr = 0xffff;
    uVar10 = 0xffff;
    bVar18 = false;
    uVar19 = (undefined1)StshCtPtr2.seg;
    uVar20 = (undefined1)(StshCtPtr2.seg >> 8);
    uStack_6 = (undefined1)StshCtPtr2.ofs;
    bStack_5 = (byte)(StshCtPtr2.ofs >> 8);
    while (iVar17 = (int)in_stack_0000ffee,
          CONCAT11(bStack_5,uStack_6) != 0 || CONCAT11(uVar20,uVar19) != 0) {
      iVar16 = CONCAT11(bStack_5,uStack_6);
      uVar11 = (undefined2)(CONCAT13(uVar20,CONCAT12(uVar19,iVar16)) >> 0x10);
      if (*(int *)(iVar16 + 0x11) != 0 || *(int *)(iVar16 + 0x13) != 0) {
        if (*(uint *)(CONCAT11(bStack_5,uStack_6) + 0x13) < uVar15) {
          iVar16 = CONCAT11(bStack_5,uStack_6);
          uVar11 = (undefined2)(CONCAT13(uVar20,CONCAT12(uVar19,iVar16)) >> 0x10);
          handle.seg = *(uint16_t *)(iVar16 + 0x13);
          handle.ofs = *(uint16_t *)(iVar16 + 0x11);
          in_stack_0000ffee = CONCAT22(0x887f,iVar17);
          stshFree(handle);
          iVar17 = CONCAT11(bStack_5,uStack_6);
          uVar11 = (undefined2)(CONCAT13(uVar20,CONCAT12(uVar19,iVar17)) >> 0x10);
          *(undefined2 *)(iVar17 + 0x13) = 0;
          *(undefined2 *)(iVar17 + 0x11) = 0;
          bVar18 = true;
        }
        else {
          if (*(uint *)(CONCAT11(bStack_5,uStack_6) + 0x13) < uVar10) {
            uVar10 = *(uint *)(CONCAT11(bStack_5,uStack_6) + 0x13);
            in_stack_0000ffee = CONCAT22(CONCAT11(uVar20,uVar19),CONCAT11(bStack_5,uStack_6));
          }
          if (*(uint *)(CONCAT11(bStack_5,uStack_6) + 0x13) < HeapPtr) {
            HeapPtr = *(uint *)(CONCAT11(bStack_5,uStack_6) + 0x13);
          }
        }
      }
      iVar17 = CONCAT11(bStack_5,uStack_6);
      uVar11 = (undefined2)(CONCAT13(uVar20,CONCAT12(uVar19,iVar17)) >> 0x10);
      uVar19 = (undefined1)*(undefined2 *)(iVar17 + 0xb);
      uVar20 = (undefined1)((uint)*(undefined2 *)(iVar17 + 0xb) >> 8);
      uStack_6 = (undefined1)*(undefined2 *)(iVar17 + 9);
      bStack_5 = (byte)((uint)*(undefined2 *)(iVar17 + 9) >> 8);
    }
    if (!bVar18) {
      if (uVar10 == 0xffff) {
        bVar18 = ovr_fmFreeAudio(1);
        if (bVar18) {
          return (entity_t *)((int)(undefined4 *)&_DATA + 1);
        }
        if (audioBusy != '\0') {
          return (entity_t *)0x0;
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x14);
      }
      uVar11 = (undefined2)((ulong)in_stack_0000ffee >> 0x10);
      handle_00.seg = *(uint16_t *)(iVar17 + 0x13);
      handle_00.ofs = *(uint16_t *)(iVar17 + 0x11);
      uVar11 = 0x8939;
      stshFree(handle_00);
      *(undefined2 *)(iVar17 + 0x13) = 0;
      *(undefined2 *)(iVar17 + 0x11) = 0;
      HeapPtr = handle_00.seg;
    }
    puVar3 = (undefined4 *)&_DATA;
  }
  else {
    puVar3 = (undefined4 *)&_DATA;
  }
  return (entity_t *)((int)puVar3 + 1);
}



/* 4207:26bc */

/* WARNING: Instruction at (ram,0x0005ff51) overlaps instruction at (ram,0x0005ff50)
    */
/* WARNING: Type propagation algorithm not settling */
/* [R2] string "Error 4 %d \r" */

agnt_t * __cdecl16far ovc15_textError(undefined4 param_1,agnt_t *param_2)

{
  uint *puVar1;
  uint16_t *puVar2;
  uint8_t *puVar3;
  undefined4 uVar4;
  far_t entries;
  far_t pixels;
  far_t handle;
  far_t handle_00;
  undefined4 *puVar5;
  char cVar6;
  byte bVar7;
  char cVar8;
  bool bVar9;
  undefined1 uVar21;
  undefined1 uVar22;
  undefined1 uVar23;
  far_t *pfVar10;
  cte_t *pcVar11;
  undefined2 *puVar12;
  long *plVar13;
  uint uVar14;
  uint8_t *puVar15;
  agnt_t *paVar16;
  uint32_t *puVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  entity_t *in_CX;
  stg_tmp_t *gfx;
  uint16_t uVar24;
  uint16_t uVar25;
  uint uVar26;
  undefined1 *puVar27;
  entity_t *peVar28;
  uint8_t unaff_BP;
  anm_t *unaff_SI;
  char *pcVar29;
  uint uVar30;
  char *unaff_DI;
  undefined2 uVar31;
  uint32_t *puVar32;
  undefined2 uVar33;
  undefined2 uVar34;
  uint8_t *unaff_SS;
  bool bVar35;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  ulong uVar36;
  char acStackY_1b6 [120];
  char acStackY_13e [36];
  uint16_t auStackY_11a [66];
  uint16_t auStackY_96 [24];
  entity_t eStackY_66;
  undefined2 uStackY_2c;
  undefined2 uStackY_2a;
  entity_t *in_stack_0000ffe2;
  undefined2 in_stack_0000ffe4;
  uint8_t uVar37;
  uint8_t uVar38;
  uint8_t uVar39;
  undefined1 uVar40;
  undefined1 uVar41;
  undefined1 uVar42;
  undefined1 uVar43;
  undefined1 uVar44;
  undefined1 uVar45;
  undefined1 in_stack_0000ffee;
  undefined1 uVar46;
  undefined1 in_stack_0000ffef;
  undefined1 uVar47;
  undefined1 in_stack_0000fff0;
  undefined1 in_stack_0000fff1;
  uint8_t in_stack_0000fff2;
  undefined1 in_stack_0000fff3;
  byte in_stack_0000fff4;
  byte in_stack_0000fff5;
  uint uVar48;
  byte bVar49;
  undefined1 in_stack_0000fffc;
  byte bVar50;
  undefined1 uVar51;
  
  iVar18 = CONCAT11(in_stack_0000fff1,in_stack_0000fff0);
  puVar32 = (uint32_t *)((ulong)param_1 >> 0x10);
  uVar26 = (uint)param_1;
  puVar12 = (undefined2 *)((uint)*(byte *)(uVar26 + 0x1a) * 4);
  uVar31 = puVar12[1];
  uVar33 = *puVar12;
  uVar47 = (undefined1)uVar31;
  uVar40 = (undefined1)((uint)uVar31 >> 8);
  bVar49 = (byte)uVar33;
  uVar46 = (undefined1)((uint)uVar33 >> 8);
  uVar24 = 0x195d;
  uVar33 = 0x195d;
  bVar50 = *(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)*(byte *)(uVar26 + 0xd) * 0x95);
  if (bVar50 == 0xff) {
    bVar50 = 0;
  }
  pcVar29 = (char *)0x0;
  uVar25 = (uint16_t)bVar50;
  if (6 < uVar25) {
    if ((agnt_t *)param_2 != (agnt_t *)0x0 || (*(uint16_t *)((uint8_t *)&(param_2) + 2)) != 0) {
      uVar40 = 0;
      uVar23 = 0;
      uVar37 = 0x64;
      uVar47 = 0;
      plVar13 = LXMUL_at_((long *)((int)&GSTARTX_SavedVectors[2].ofs + 1),
                          CONCAT13(uVar46,CONCAT12(bVar49,unaff_SI)),
                          CONCAT13(bVar50,CONCAT12(in_stack_0000fffc,uVar31)));
      uVar36 = LDIV_at_(CONCAT13((char)((uint)(*(uint16_t *)((uint8_t *)&(param_2) + 2)) >> 8),
                                 CONCAT12((char)(*(uint16_t *)((uint8_t *)&(param_2) + 2)),plVar13)),
                        CONCAT13(uVar23,CONCAT12(uVar40,CONCAT11(uVar47,uVar37))));
      param_2 = (agnt_t *)(uVar36 & 0xffff);
    }
    return (agnt_t *)param_2;
  }
  puVar27 = (undefined1 *)(uVar25 * 2);
  uVar34 = 0x4000;
  switch(uVar25) {
  case 0:
    if ((bVar50 & (&stack0x02c2)[(int)unaff_DI]) == 0) {
      iVar18 = (int)puVar32 + (uint)(0xffec < uVar26);
      uVar33 = 0x1000;
      plVar13 = LXRSH_at_((long *)unaff_SI,CONCAT13(bVar50,CONCAT12(in_stack_0000fffc,uVar31)),
                          unaff_BP);
      uVar14 = (int)plVar13 + HeapPtr;
      iVar18 = iVar18 + (uint)CARRY2((uint)plVar13,HeapPtr);
      uVar26 = uVar14;
      if (iVar18 != 0) {
        uVar26 = 0xffff;
      }
      if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar18 != 0 || (MUSHandle.seg < uVar14)))
          ) || ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 &&
                ((iVar18 != 0 || (MUSHandle.seg < uVar14)))))) {
        uVar33 = 0x22f8;
        in_stack_0000fff0 = 0x28;
        in_stack_0000fff1 = 0x88;
        ovr_fmFreeAudio(1);
      }
      uVar48 = 0xffff;
      HeapPtr = 0xffff;
      bVar35 = false;
      uVar40 = (undefined1)StshCtPtr2.seg;
      uVar23 = (undefined1)(StshCtPtr2.seg >> 8);
      uVar46 = (undefined1)StshCtPtr2.ofs;
      uVar47 = (undefined1)(StshCtPtr2.ofs >> 8);
      uVar14 = 0xffff;
      while( true ) {
        uVar44 = (undefined1)uVar33;
        uVar22 = (undefined1)((uint)uVar33 >> 8);
        if (CONCAT11(uVar47,uVar46) == 0 && CONCAT11(uVar23,uVar40) == 0) break;
        iVar18 = CONCAT11(uVar47,uVar46);
        uVar31 = (undefined2)(CONCAT13(uVar23,CONCAT12(uVar40,iVar18)) >> 0x10);
        uVar30 = uVar14;
        if (*(int *)(iVar18 + 0x11) != 0 || *(int *)(iVar18 + 0x13) != 0) {
          if (*(uint *)(CONCAT11(uVar47,uVar46) + 0x13) < uVar26) {
            iVar18 = CONCAT11(uVar47,uVar46);
            uVar31 = (undefined2)(CONCAT13(uVar23,CONCAT12(uVar40,iVar18)) >> 0x10);
            in_stack_0000ffee = 0x7f;
            in_stack_0000ffef = 0x88;
            (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)*(undefined2 *)(iVar18 + 0x13);
            handle.ofs = *(undefined2 *)(iVar18 + 0x11);
            (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)*(undefined2 *)(iVar18 + 0x13) >> 8);
            stshFree(handle);
            iVar18 = CONCAT11(uVar47,uVar46);
            uVar31 = (undefined2)(CONCAT13(uVar23,CONCAT12(uVar40,iVar18)) >> 0x10);
            *(undefined2 *)(iVar18 + 0x13) = 0;
            *(undefined2 *)(iVar18 + 0x11) = 0;
            bVar35 = true;
            in_stack_0000fff0 = uVar44;
            in_stack_0000fff1 = uVar22;
          }
          else {
            if (*(uint *)(CONCAT11(uVar47,uVar46) + 0x13) < uVar14) {
              uVar30 = *(uint *)(CONCAT11(uVar47,uVar46) + 0x13);
              in_stack_0000ffee = uVar46;
              in_stack_0000ffef = uVar47;
              in_stack_0000fff0 = uVar40;
              in_stack_0000fff1 = uVar23;
              uVar48 = uVar14;
            }
            if (*(uint *)(CONCAT11(uVar47,uVar46) + 0x13) < HeapPtr) {
              HeapPtr = *(uint *)(CONCAT11(uVar47,uVar46) + 0x13);
            }
          }
        }
        iVar18 = CONCAT11(uVar47,uVar46);
        uVar31 = (undefined2)(CONCAT13(uVar23,CONCAT12(uVar40,iVar18)) >> 0x10);
        uVar40 = (undefined1)*(undefined2 *)(iVar18 + 0xb);
        uVar23 = (undefined1)((uint)*(undefined2 *)(iVar18 + 0xb) >> 8);
        uVar46 = (undefined1)*(undefined2 *)(iVar18 + 9);
        uVar47 = (undefined1)((uint)*(undefined2 *)(iVar18 + 9) >> 8);
        uVar14 = uVar30;
      }
      if (!bVar35) {
        if (uVar14 == 0xffff) {
          bVar35 = ovr_fmFreeAudio(1);
          if (bVar35) {
            return (agnt_t *)((int)(undefined4 *)&_DATA + 1);
          }
          if (audioBusy != '\0') {
            return (agnt_t *)0x0;
          }
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x14);
        }
        iVar18 = CONCAT11(in_stack_0000ffef,in_stack_0000ffee);
        uVar31 = (undefined2)
                 (CONCAT13(in_stack_0000fff1,CONCAT12(in_stack_0000fff0,iVar18)) >> 0x10);
        uVar46 = 0x39;
        uVar47 = 0x89;
        (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)*(undefined2 *)(iVar18 + 0x13);
        handle_00.ofs = *(undefined2 *)(iVar18 + 0x11);
        (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)((uint)*(undefined2 *)(iVar18 + 0x13) >> 8);
        stshFree(handle_00);
        HeapPtr = uVar48;
        iVar18 = CONCAT11(uVar47,uVar46);
        uVar31 = (undefined2)(CONCAT13(uVar22,CONCAT12(uVar44,iVar18)) >> 0x10);
        *(undefined2 *)(iVar18 + 0x13) = 0;
        *(undefined2 *)(iVar18 + 0x11) = 0;
      }
      puVar5 = (undefined4 *)&_DATA;
    }
    else {
      puVar5 = (undefined4 *)&_DATA;
    }
    return (agnt_t *)((int)puVar5 + 1);
  case 1:
    *puVar27 = *puVar27;
    do {
      uVar31 = 0x195d;
      pfVar10 = stshSprite((far_t *)*(undefined2 *)
                                     ((int)AgntGs[0].sprfls + 6 +
                                     (int)pcVar29 * 0x95 + (int)unaff_DI * 2),
                           *(int16_t *)(puVar27 + 0x26fe),unaff_SI,CONCAT11(uVar46,bVar49),
                           (bool)uVar47);
      iVar18 = (int)pcVar29 * 0x95 + (int)unaff_DI * 4;
      *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar18) = uVar31;
      *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar18) = pfVar10;
      while( true ) {
        unaff_DI = unaff_DI + 1;
        while (2 < (int)unaff_DI) {
          for (iVar18 = 0; iVar18 < 6; iVar18 = iVar18 + 1) {
            uVar31 = 0x195d;
            if (*(int *)((int)AgntGs[0].prtfls + (int)pcVar29 * 0x95 + iVar18 * 2) != 0) {
              if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
                pfVar10 = ovr_stshAllocStub((far_t *)CONCAT11(bVar50,in_stack_0000fffc));
                iVar19 = (int)pcVar29 * 0x95 + iVar18 * 4;
                uVar33 = 0x195d;
                *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar19) = uVar31;
                *(undefined2 *)((int)AgntGs[0].prts + iVar19) = pfVar10;
                pfVar10 = ovr_stshAllocStub((far_t *)CONCAT11(bVar50,in_stack_0000fffc));
                iVar19 = (int)pcVar29 * 0x95 + iVar18 * 4;
                *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar19) = uVar33;
                *(undefined2 *)((int)AgntGs[0].prtpals + iVar19) = pfVar10;
              }
              else {
                gfx = (stg_tmp_t *)((int)&BuildingTypes[0x9f].income + 1);
                ovr_grabLbm(*(int16_t *)((int)AgntGs[0].prtfls + (int)pcVar29 * 0x95 + iVar18 * 2),0
                            ,0);
                in_stack_0000fffc = SUB21(gfx,0);
                bVar50 = (byte)((uint)gfx >> 8);
                ovr_stshUniqueColorsRemap(gfx);
                pixels.seg = 0;
                pixels.ofs = ((DW *)&IdFORM)->lo;
                pfVar10 = ovr_stshRleType2(*(far_t **)((char *)"Error 4 %d \r" + 0xb),pixels,0,114,
                                           103,0,0,CONCAT11(bVar50,in_stack_0000fffc));
                pcVar11 = ovr_stshStoreFile((uint8_t *)pfVar10);
                iVar19 = (int)pcVar29 * 0x95 + iVar18 * 4;
                uVar31 = 0x195d;
                *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar19) = gfx;
                *(undefined2 *)((int)AgntGs[0].prts + iVar19) = pcVar11;
                puVar32 = ovr_stshWrite((uint32_t *)0x0,
                                        (uint8_t *)CONCAT11(bVar50,in_stack_0000fffc),0x300);
                iVar19 = (int)pcVar29 * 0x95 + iVar18 * 4;
                *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar19) = uVar31;
                *(undefined2 *)((int)AgntGs[0].prtpals + iVar19) = puVar32;
                ovr_stgFreeTmp((stg_tmp_t *)CONCAT11(bVar50,in_stack_0000fffc));
              }
            }
          }
          paVar16 = (agnt_t *)
                    (*(uint *)((int)AgntGs[0].prts + 4 + (int)pcVar29 * 0x95) |
                    *(uint *)((int)AgntGs[0].prts + 6 + (int)pcVar29 * 0x95));
          if ((paVar16 == (agnt_t *)0x0) &&
             (paVar16 = (agnt_t *)0x0,
             *(int *)((int)AgntGs[0].prts + (int)pcVar29 * 0x95) != 0 ||
             *(int *)((int)AgntGs[0].prts + 2 + (int)pcVar29 * 0x95) != 0)) {
            uVar31 = *(undefined2 *)((int)AgntGs[0].prts + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].prts + 6 + (int)pcVar29 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].prts + 2 + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].prts + 4 + (int)pcVar29 * 0x95) = uVar31;
            paVar16 = (agnt_t *)*(uint *)((int)AgntGs[0].prtpals + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].prtpals + 6 + (int)pcVar29 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].prtpals + 2 + (int)pcVar29 * 0x95);
            *(uint *)((int)AgntGs[0].prtpals + 4 + (int)pcVar29 * 0x95) = (uint)paVar16;
          }
          for (iVar18 = 2; iVar18 < 6; iVar18 = iVar18 + 2) {
            iVar19 = (int)pcVar29 * 0x95 + iVar18 * 4;
            if ((*(int *)((int)AgntGs[0].prts + 4 + iVar19) == 0 &&
                 *(int *)((int)AgntGs[0].prts + 6 + iVar19) == 0) &&
               (iVar19 = (int)pcVar29 * 0x95 + iVar18 * 4,
               *(int *)((int)AgntGs[0].prtfls + 8 + iVar19) != 0 ||
               *(int *)((int)AgntGs[0].prtfls + 10 + iVar19) != 0)) {
              iVar19 = (int)pcVar29 * 0x95 + iVar18 * 4;
              uVar31 = *(undefined2 *)((int)AgntGs[0].prtfls + 8 + iVar19);
              iVar20 = (int)pcVar29 * 0x95 + iVar18 * 4;
              *(undefined2 *)((int)AgntGs[0].prts + 6 + iVar20) =
                   *(undefined2 *)((int)AgntGs[0].prtfls + 10 + iVar19);
              *(undefined2 *)((int)AgntGs[0].prts + 4 + iVar20) = uVar31;
              iVar19 = (int)pcVar29 * 0x95 + iVar18 * 4;
              uVar31 = *(undefined2 *)((int)AgntGs[0].prts + 0x14 + iVar19);
              iVar20 = (int)pcVar29 * 0x95 + iVar18 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 6 + iVar20) =
                   *(undefined2 *)((int)AgntGs[0].prts + 0x16 + iVar19);
              *(undefined2 *)((int)AgntGs[0].prtpals + 4 + iVar20) = uVar31;
            }
            iVar19 = (int)pcVar29 * 0x95 + iVar18 * 4;
            paVar16 = (agnt_t *)
                      (*(uint *)((int)AgntGs[0].prts + iVar19) |
                      *(uint *)((int)AgntGs[0].prts + 2 + iVar19));
            if (paVar16 == (agnt_t *)0x0) {
              iVar19 = (int)pcVar29 * 0x95 + iVar18 * 4;
              if (*(int *)((int)AgntGs[0].prtfls + 4 + iVar19) == 0 &&
                  *(int *)((int)AgntGs[0].prtfls + 6 + iVar19) == 0) {
                paVar16 = (agnt_t *)0x0;
              }
              else {
                iVar19 = (int)pcVar29 * 0x95 + iVar18 * 4;
                uVar31 = *(undefined2 *)((int)AgntGs[0].prtfls + 4 + iVar19);
                iVar20 = (int)pcVar29 * 0x95 + iVar18 * 4;
                *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar20) =
                     *(undefined2 *)((int)AgntGs[0].prtfls + 6 + iVar19);
                *(undefined2 *)((int)AgntGs[0].prts + iVar20) = uVar31;
                iVar19 = (int)pcVar29 * 0x95 + iVar18 * 4;
                paVar16 = (agnt_t *)*(uint *)((int)AgntGs[0].prts + 0x10 + iVar19);
                iVar20 = (int)pcVar29 * 0x95 + iVar18 * 4;
                *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar20) =
                     *(undefined2 *)((int)AgntGs[0].prts + 0x12 + iVar19);
                *(uint *)((int)AgntGs[0].prtpals + iVar20) = (uint)paVar16;
              }
            }
          }
          pcVar29 = pcVar29 + 1;
          if (0x29 < (int)pcVar29) {
            return paVar16;
          }
          uVar31 = 0x195d;
          pfVar10 = stshSprite((far_t *)*(undefined2 *)((int)AgntGs[0].sprfls + (int)pcVar29 * 0x95)
                               ,*(int16_t *)((int)&AgntGs[0].anms + (int)pcVar29 * 0x95),
                               (anm_t *)*(undefined2 *)
                                         ((int)&AgntGs[0].anms + 2 + (int)pcVar29 * 0x95),
                               (uint)*(byte *)((int)&AgntGs[0].nanims + (int)pcVar29 * 0x95),
                               (*(uint8_t *)((uint8_t *)&(param_1))));
          *(undefined2 *)((int)AgntGs[0].sprs + 2 + (int)pcVar29 * 0x95) = uVar31;
          *(undefined2 *)((int)AgntGs[0].sprs + (int)pcVar29 * 0x95) = pfVar10;
          if (*(int *)((int)AgntGs[0].sprfls + 2 + (int)pcVar29 * 0x95) == 0) {
            uVar31 = *(undefined2 *)((int)AgntGs[0].sprs + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 6 + (int)pcVar29 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].sprs + 2 + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 4 + (int)pcVar29 * 0x95) = uVar31;
          }
          else {
            uVar31 = 0x195d;
            pfVar10 = stshSprite((far_t *)*(undefined2 *)
                                           ((int)AgntGs[0].sprfls + 2 + (int)pcVar29 * 0x95),
                                 *(int16_t *)((int)&AgntGs[0].anms + (int)pcVar29 * 0x95),
                                 (anm_t *)*(undefined2 *)
                                           ((int)&AgntGs[0].anms + 2 + (int)pcVar29 * 0x95),
                                 (uint)*(byte *)((int)&AgntGs[0].nanims + (int)pcVar29 * 0x95),
                                 (*(uint8_t *)((uint8_t *)&(param_1))));
            *(undefined2 *)((int)AgntGs[0].sprs + 6 + (int)pcVar29 * 0x95) = uVar31;
            *(undefined2 *)((int)AgntGs[0].sprs + 4 + (int)pcVar29 * 0x95) = pfVar10;
          }
          if (*(int *)((int)AgntGs[0].sprfls + 4 + (int)pcVar29 * 0x95) == 0) {
            uVar31 = *(undefined2 *)((int)AgntGs[0].sprs + 4 + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 10 + (int)pcVar29 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].sprs + 6 + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 8 + (int)pcVar29 * 0x95) = uVar31;
          }
          else {
            uVar31 = 0x195d;
            pfVar10 = stshSprite((far_t *)*(undefined2 *)
                                           ((int)AgntGs[0].sprfls + 4 + (int)pcVar29 * 0x95),
                                 *(int16_t *)((int)&AgntGs[0].anms + (int)pcVar29 * 0x95),
                                 (anm_t *)*(undefined2 *)
                                           ((int)&AgntGs[0].anms + 2 + (int)pcVar29 * 0x95),
                                 (uint)*(byte *)((int)&AgntGs[0].nanims + (int)pcVar29 * 0x95),
                                 (*(uint8_t *)((uint8_t *)&(param_1))));
            *(undefined2 *)((int)AgntGs[0].sprs + 10 + (int)pcVar29 * 0x95) = uVar31;
            *(undefined2 *)((int)AgntGs[0].sprs + 8 + (int)pcVar29 * 0x95) = pfVar10;
          }
          unaff_DI = (char *)0x0;
        }
        if (*(int *)((int)AgntGs[0].sprfls + 6 + (int)pcVar29 * 0x95 + (int)unaff_DI * 2) != 0)
        break;
        iVar18 = (int)pcVar29 * 0x95 + (int)unaff_DI * 4;
        uVar31 = *(undefined2 *)((int)AgntGs[0].sprs + iVar18);
        iVar19 = (int)pcVar29 * 0x95 + (int)unaff_DI * 4;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar19) =
             *(undefined2 *)((int)AgntGs[0].sprs + 2 + iVar18);
        *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar19) = uVar31;
      }
      bVar49 = *(byte *)((int)&AgntGs[0].nanims + (int)pcVar29 * 0x95);
      uVar46 = 0;
      puVar27 = (undefined1 *)((int)pcVar29 * 0x95);
      unaff_SI = *(anm_t **)(puVar27 + 0x2700);
      uVar47 = (*(uint8_t *)((uint8_t *)&(param_1)));
    } while( true );
  case 2:
    return (agnt_t *)(uVar25 & 0xff8e);
  case 3:
switchD_4000_4790_caseD_3:
    uVar31 = (undefined2)((ulong)Entities >> 0x10);
    cVar6 = *(char *)((int)&(((entity_t *)Entities)->base).flags32 + uVar25);
    cVar8 = (char)(uVar25 >> 8);
    *(char *)((int)&((entity_t *)Entities)[(int)pcVar29].base.state + 1) = cVar6;
    if (pcVar29 + 1 < EntityCount) {
      paVar16 = (agnt_t *)((char *)"thief" + 5);
      ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.");
      return paVar16;
    }
    if ((cVar6 != '\0') || (cVar8 != '\0')) {
      if (bVar50 == 0) {
        ovr_stop_audio();
        CurSfxType3 = 0xff;
        ovr_play_sfx(90,0);
      }
      else if (cVar8 == '\0') {
        if (cVar6 != '\0') {
          ovr_play_sfx(37,0);
        }
      }
      else {
        ovr_play_sfx(35,0);
      }
    }
    GGameState = 0x3d;
    paVar16 = (agnt_t *)((char *)"puppetmaker" + 3);
    if (DebugVerbose != false) {
      paVar16 = (agnt_t *)((char *)"puppetmaker" + 3);
      printf("%d \r");
    }
    ovr_OVC23_55fe_29a2_entry();
    return paVar16;
  case 4:
    in_CX = (entity_t *)CONCAT11((char)((uint)in_CX >> 8),(char)in_CX + unaff_DI[-0x63b2]);
    do {
      peVar28 = (entity_t *)(puVar27 + (int)in_CX);
      (peVar28->base).y = uVar25;
      (peVar28->base).x = uVar24;
      while( true ) {
        unaff_DI = unaff_DI + 1;
        pcVar29 = pcVar29 + 1;
L_manage_4d05_2d79_2EE8:
        if ((int)(uint)in_stack_0000fff5 <= (int)pcVar29) {
          cVar6 = '@';
          manage_openTalkWindow();
          if (cVar6 != '\x02') goto L_attact_3f0b_1082_11EA;
          if (ScreenMode == '\0') {
            manage_openTalkWindow();
          }
          TextBlitY = 0xc;
          TextBlitX = 0x11;
          uVar37 = (uint8_t)Font02.seg;
          uVar46 = (undefined1)Font02.ofs;
          uVar23 = (undefined1)(Font02.ofs >> 8);
          if ((*(uint8_t *)((uint8_t *)&(param_1))) != true) {
            ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,acStackY_1b6),
                               (char *)CONCAT22(0xde,Font02.seg),
                               (char *)CONCAT13((char)(Font02.seg >> 8),CONCAT12(uVar37,Font02.ofs))
                               ,0x4b,'\x03');
            func_0x0005d3f4();
            puVar15 = (uint8_t *)((char *)"puppetmaker" + 3);
            uStackY_2a = 0x23f1;
            uStackY_2c = 0x44;
            pcVar29 = ovr_stsprintf(acStackY_13e,(char *)unaff_SS,
                                    (char *)"%s population, loyal to %s%s");
            ovr_blitLabel(pcVar29,puVar15,CONCAT11(uVar23,uVar46),uVar37);
            TextBlitY = TextBlitY + 0xc;
            iVar18 = ovr_font_textWidth("UNITS",(char *)CONCAT13((char)(Font02.seg >> 8),
                                                                 CONCAT12((uint8_t)Font02.seg,
                                                                          Font02.ofs)));
            TextBlitX = 0x89 - iVar18;
            ovr_blitLabel((char *)"UNITS",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                          (uint8_t)Font02.seg);
            iVar18 = ovr_font_textWidth("POPULATION",
                                        (char *)CONCAT13((char)(Font02.seg >> 8),
                                                         CONCAT12((uint8_t)Font02.seg,Font02.ofs)));
            uVar24 = 0xd4 - iVar18;
            TextBlitX = uVar24;
            ovr_blitLabel((char *)"POPULATION",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                          (uint8_t)Font02.seg);
            iVar18 = 0;
            while( true ) {
              TextBlitY = TextBlitY + 0xc;
              cVar6 = (char)in_CX;
              uVar46 = SUB21(unaff_SS,0);
              uVar23 = (undefined1)((uint)unaff_SS >> 8);
              if ((int)(uint)in_stack_0000fff5 <= iVar18) break;
              TextBlitX = 0x11;
              if ((iVar18 < 5) || (in_stack_0000fff4 == 0)) {
                ovr_blitLabel((char *)auStackY_96[iVar18 * 2],(uint8_t *)auStackY_96[iVar18 * 2 + 1]
                              ,Font02.ofs,(uint8_t)Font02.seg);
              }
              else {
                uVar26 = (uint)*(byte *)((int)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(param_1))) << 2) + 0x2f);
                ovr_blitLabel((char *)auStackY_11a[iVar18 * 2 + uVar26 * 8],
                              (uint8_t *)auStackY_11a[iVar18 * 2 + uVar26 * 8 + 1],Font02.ofs,
                              (uint8_t)Font02.seg);
              }
              func_0x0005f303();
              ovr_stsprintf(acStackY_13e,(char *)unaff_SS,(char *)"%d");
              iVar19 = ovr_font_textWidth((char *)CONCAT13(uVar23,CONCAT12(uVar46,acStackY_13e)),
                                          (char *)CONCAT13((char)(Font02.seg >> 8),
                                                           CONCAT12((uint8_t)Font02.seg,Font02.ofs))
                                         );
              TextBlitX = 0x89 - iVar19;
              ovr_blitLabel(acStackY_13e,unaff_SS,Font02.ofs,(uint8_t)Font02.seg);
              ovr_stsprintf(acStackY_13e,(char *)unaff_SS,(char *)"%d");
              iVar19 = ovr_font_textWidth((char *)CONCAT13(uVar23,CONCAT12(uVar46,acStackY_13e)),
                                          (char *)CONCAT13((char)(Font02.seg >> 8),
                                                           CONCAT12((uint8_t)Font02.seg,Font02.ofs))
                                         );
              uVar24 = 0xd4 - iVar19;
              TextBlitX = uVar24;
              ovr_blitLabel(acStackY_13e,unaff_SS,Font02.ofs,(uint8_t)Font02.seg);
              iVar18 = iVar18 + 1;
            }
            CurSfxType3 = 0x3c;
            (*(uint8_t *)((uint8_t *)&(entries.seg))) = uVar46;
            entries.ofs = (uint16_t)&eStackY_66;
            (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar23;
            uVar31 = ovr_ovc28_usesUiInputText
                               (entries,(uint16_t)unaff_DI,far_from_u32((uint32_t)(0x0)),&stack0xfff2,
                                (uint16_t)unaff_SS);
            cVar8 = (char)uVar31;
            keyboardInputMode = 0;
            if (((cVar8 != '\0') && (cVar8 != '\x01')) && (cVar8 != -2)) {
              (&stack0xbac4)[(int)unaff_DI] = (&stack0xbac4)[(int)unaff_DI] + cVar6;
              iVar19 = 0x2410;
              do {
                iVar20 = iVar19 * uVar24;
                iVar19 = iVar18;
                if (*(byte *)(iVar18 * 0x34 + 0x22) < *(byte *)(iVar20 + 0x21)) {
                  *(undefined1 *)(iVar18 * 0x34 + 0x21) = *(undefined1 *)(iVar18 * 0x34 + 0x22);
                }
                do {
                  iVar19 = iVar19 + 1;
                  if ((int)(uint)AgntCount <= iVar19) {
                    uVar24 = ovr_audio_panFromX(param_2);
                    ovr_play_sfxU(0x1c,0,uVar24);
                    return (agnt_t *)((int)(undefined4 *)&_DATA + 1);
                  }
                } while (*(uint16_t *)(iVar19 * 0x34 + 0x1b) != ((agnt_t *)param_2)->owner);
                if (*(byte *)(CONCAT11(uVar40,uVar47) + 0x32) < *(byte *)(iVar19 * 0x34 + 0x22)) {
                  *(undefined1 *)(iVar19 * 0x34 + 0x22) =
                       *(undefined1 *)(CONCAT11(uVar40,uVar47) + 0x32);
                }
                uVar24 = 0x34;
                iVar18 = iVar19;
              } while( true );
            }
            if (cVar8 == -2) {
              Cancelled = 1;
            }
            return (agnt_t *)((char *)"puppetmaker" + 3);
          }
          uVar26 = ovr_blitLabel((char *)"Total population.",(uint8_t *)((char *)"puppetmaker" + 3),
                                 Font02.ofs,uVar37);
          *pcVar29 = *pcVar29 + (char)(uVar26 >> 8) + ((undefined1 *)0xfff3 < &stack0xffe8);
          *(undefined1 *)((int)&(((entity_t *)*(entity_t **)&Entities)->base).entity + uVar26 + 1) =
               0;
          uVar25 = (int)pcVar29 * 0x37;
          goto switchD_4000_4790_caseD_3;
        }
        if ((4 < (int)pcVar29) && (in_stack_0000fff4 != 0)) break;
        uVar24 = auStackY_96[(int)pcVar29 * 2];
        in_CX = &eStackY_66;
        peVar28 = (entity_t *)(&(in_CX->base).x + (int)unaff_DI * 2);
        (&eStackY_66.base.y)[(int)unaff_DI * 2] = auStackY_96[(int)pcVar29 * 2 + 1];
        (peVar28->base).x = uVar24;
      }
      uVar33 = (undefined2)((ulong)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(param_1))) << 2) >> 0x10);
      uVar26 = (uint)*(byte *)((int)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(param_1))) << 2) + 0x2f);
      uVar25 = auStackY_11a[(int)pcVar29 * 2 + uVar26 * 8 + 1];
      uVar24 = auStackY_11a[(int)pcVar29 * 2 + uVar26 * 8];
      puVar27 = (undefined1 *)((int)unaff_DI << 2);
      in_CX = &eStackY_66;
    } while( true );
  case 5:
    puVar1 = (uint *)(&stack0xc1dd + (int)unaff_DI);
    uVar26 = *puVar1;
    *puVar1 = *puVar1 - 1;
    if (in_CX == (entity_t *)0x0) {
      in_stack_0000fff5 =
           (in_NT & 1) * '@' | SBORROW2(uVar26,1) * '\b' | (in_IF & 1) * '\x02' | in_TF & 1;
      in_stack_0000fff4 =
           ((int)*puVar1 < 0) * -0x80 | (*puVar1 == 0) * '@' |
           (9 < (bVar50 & 0xf) | in_AF & 1) * '\x10' |
           ((POPCOUNT(*puVar1 & 0xff) & 1U) == 0) * '\x04';
    }
    (&eStackY_66.base.y)[uVar25] = (uint16_t)((char *)"puppetmaker" + 3);
    *(char **)(puVar27 + (int)&eStackY_66) = (char *)"Done";
    (&eStackY_66.base.y)[(int)(unaff_DI + 1) * 2] = (uint16_t)((char *)"puppetmaker" + 3);
    (&eStackY_66.base.x)[(int)(unaff_DI + 1) * 2] = (uint16_t)(char *)"Summary";
    peVar28 = (entity_t *)(&eStackY_66.base.x + (int)(unaff_DI + 2) * 2);
    (&eStackY_66.base.y)[(int)(unaff_DI + 2) * 2] = (uint16_t)((char *)"puppetmaker" + 3);
    (peVar28->base).x = (uint16_t)(char *)"All levels";
    unaff_DI = unaff_DI + 3;
    pcVar29 = (char *)0x0;
    goto L_manage_4d05_2d79_2EE8;
  }
  if ((uVar25 != 0) || ((uint)(*(uint16_t *)((uint8_t *)&(BuildingTypes[0x76]) + 24)) < 0x195d)) {
    uVar14 = (((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
              (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (int)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
             (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
    if ((uVar14 < CONCAT11(in_stack_0000fff3,in_stack_0000fff2)) ||
       ((uVar14 <= CONCAT11(in_stack_0000fff3,in_stack_0000fff2) &&
        (((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0] <=
         CONCAT11(in_stack_0000fff1,in_stack_0000fff0))))) {
      unaff_SI = (anm_t *)((((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                            (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) -
                           (int)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                          (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]));
    }
    else {
      unaff_SI = (anm_t *)CONCAT11(in_stack_0000fff3,in_stack_0000fff2);
    }
    uVar38 = (uint8_t)unaff_SI;
    uVar23 = (undefined1)((uint)unaff_SI >> 8);
    uVar25 = (uint)StshPtrs[0] - (uint)FMXmsHandle;
    puVar15 = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) +
              (-(uint)((uint)StshPtrs[0] < (uint)FMXmsHandle) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)));
    uVar37 = uVar38;
    uVar46 = uVar23;
    uVar24 = uVar25;
    puVar17 = ovr_mkp(puVar32,(uint16_t)(agnt_t *)param_2,uVar25);
    ems_memmove1((uint16_t)puVar17,uVar25,uVar24,(uint16_t)puVar15,CONCAT11(uVar23,uVar38),
                 CONCAT11(uVar46,uVar37));
    bVar35 = CARRY2((uint)StshPtrs[0],CONCAT11(uVar46,uVar37));
    (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + CONCAT11(uVar46,uVar37);
    (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = &unaff_SI->frmid + (int)((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + bVar35);
    iVar18 = (int)puVar15 - CONCAT11(uVar46,uVar37);
    bVar7 = 0;
    uVar34 = 0x1000;
    in_stack_0000fff2 = 0xcb;
    in_stack_0000fff3 = 0x77;
    puVar17 = LXURSH_at_((uint32_t *)unaff_SI,
                         CONCAT13(bVar50,CONCAT12(in_stack_0000fffc,CONCAT11(uVar40,uVar47))),
                         unaff_BP);
    param_2 = (agnt_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(param_2) + 2)),(agnt_t *)((int)puVar17 + (int)(agnt_t *)param_2));
    param_1 = CONCAT22((int)puVar32 + (bVar7 & 0xf),uVar26);
  }
  puVar27 = (undefined1 *)
            ((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
            (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle));
  if ((puVar27 <= (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) &&
     ((puVar27 != (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) || ((uint)FMXmsHandle + (uint)FMEmsHandle <= (uint)StshPtrs[0]))
     )) {
    in_stack_0000fff2 = (uint8_t)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2));
    in_stack_0000fff3 = (undefined1)((uint)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) >> 8);
    uVar46 = (undefined1)(uint)StshPtrs[0];
    uVar47 = (undefined1)((uint)StshPtrs[0] >> 8);
    uVar34 = 0x1000;
    lseek(StshHandles[0],ZEXT24((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))),(int)unaff_SI);
    iVar18 = CONCAT11(uVar47,uVar46);
  }
  puVar32 = (uint32_t *)CONCAT11(in_stack_0000fff3,in_stack_0000fff2);
  if (iVar18 == 0 && puVar32 == (uint32_t *)0x0) {
    paVar16 = (agnt_t *)((uint)bVar49 - (*(uint16_t *)((uint8_t *)&(param_2) + 2)));
  }
  else {
    uVar44 = SUB41(param_2,0);
    uVar22 = (undefined1)((ulong)param_2 >> 8);
    uVar40 = (undefined1)((ulong)param_1 >> 0x10);
    uVar23 = (undefined1)((ulong)param_1 >> 0x18);
    uVar46 = (char)StshHandles[0];
    uVar47 = (char)((uint)StshHandles[0] >> 8);
    while( true ) {
      if ((puVar32 == (uint32_t *)0x0) && (iVar18 == 0)) goto next_iteration;
      uVar43 = (undefined1)uVar34;
      uVar45 = (undefined1)((uint)uVar34 >> 8);
      uVar41 = 0x88;
      uVar42 = 0x78;
      uVar21 = uVar46;
      uVar51 = uVar47;
      uVar26 = read(CONCAT11(uVar47,uVar46),(void *)CONCAT11(uVar23,uVar40),CONCAT11(uVar22,uVar44))
      ;
      if (uVar26 != CONCAT11(uVar47,uVar46)) break;
      puVar32 = (uint32_t *)(CONCAT11(uVar42,uVar41) + uVar26);
      uVar46 = 0;
      uVar47 = 0x10;
      uVar34 = 0x22a6;
      puVar17 = ovr_mkp(puVar32,CONCAT11(uVar45,uVar43),(uint16_t)unaff_SI);
      iVar18 = CONCAT11(uVar47,uVar46);
      uVar44 = (undefined1)(*(uint16_t *)((uint8_t *)&(param_1) + 2));
      uVar22 = (undefined1)((uint)(*(uint16_t *)((uint8_t *)&(param_1) + 2)) >> 8);
      uVar40 = SUB21(puVar17,0);
      uVar23 = (undefined1)((uint)puVar17 >> 8);
      bVar35 = CARRY2((uint)StshPtrs[0],uVar26);
      (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + uVar26;
      (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + bVar35;
      uVar46 = uVar21;
      uVar47 = uVar51;
    }
    printf((char *)((long)&BldInstances[0x49].seg + 1));
    ovr_biosReadKey();
next_iteration:
    paVar16 = (agnt_t *)((uint)bVar49 - (*(uint16_t *)((uint8_t *)&(param_2) + 2)));
  }
  return paVar16;
L_attact_3f0b_1082_11EA:
  (in_stack_0000ffe2->base).target =
       (byte)((int)(uint)*(byte *)((int)&(in_stack_0000ffe2->base).owner +
                                  ((int)(uint)(peVar28->base).faction >> 2)) >>
             (((in_stack_0000ffe2->base).faction & 3) << 1)) & 3;
  cVar6 = func_0x0004f32d();
  if (cVar6 == '\0') {
    (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x =
         (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x +
         (int)*(char *)((in_stack_0000ffe2->base).target + 0x885);
    puVar2 = &(in_stack_0000ffe2->base).y;
    *puVar2 = *puVar2 + (int)*(char *)((in_stack_0000ffe2->base).target + 0x889);
    puVar3 = &(in_stack_0000ffe2->base).faction;
    *puVar3 = *puVar3 + 0x1;
  }
  else {
    (in_stack_0000ffe2->base).faction = 0x0;
    *(undefined1 *)&(in_stack_0000ffe2->base).state = 0;
  }
L_attact_3f0b_1082_1477:
  do {
    uVar37 = 0x1;
    uVar26 = ovr_alignUp4((in_stack_0000ffe2->base).destX);
    uVar38 = (uint8_t)uVar26;
    uVar23 = (undefined1)(uVar26 >> 8);
    uVar26 = ovr_alignUp4((((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x);
    if ((CONCAT11(uVar23,uVar38) == uVar26) &&
       ((in_stack_0000ffe2->base).destY == (in_stack_0000ffe2->base).y)) {
      (in_stack_0000ffe2->base).destX = 0;
      (in_stack_0000ffe2->base).destY = 0;
      if (*(char *)((int)&(in_stack_0000ffe2->base).entity + 3) == -1) {
        bVar50 = 0xff;
      }
      else {
        uVar4 = *(undefined4 *)((uint)*(byte *)((int)&(in_stack_0000ffe2->base).entity + 3) << 2);
        bVar50 = *(byte *)((int)uVar4 + 0x89);
      }
      if (bVar50 != 0xff) {
        for (uVar26 = 0; uVar26 < SquareRecCount; uVar26 = uVar26 + 1) {
          uVar14 = ovr_alignUp4(*(int *)(uVar26 * 0x13));
          uVar38 = (uint8_t)uVar14;
          uVar23 = (undefined1)(uVar14 >> 8);
          uVar14 = ovr_alignUp4((((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).
                                x);
          if ((CONCAT11(uVar23,uVar38) == uVar14) &&
             (*(uint16_t *)(uVar26 * 0x13 + 2) == (in_stack_0000ffe2->base).y)) {
            func_0x0004f930();
            if (*(uint16_t *)(uVar26 * 0x13 + 2) == GfxRndSeed2) {
              uVar26 = ovr_alignUp4(*(int *)(uVar26 * 0x13));
              uVar38 = (uint8_t)uVar26;
              uVar23 = (undefined1)(uVar26 >> 8);
              uVar26 = ovr_alignUp4(GfxRndSeed);
              if (CONCAT11(uVar23,uVar38) == uVar26) {
                (&stack0xfff2)[bVar50] = 1;
              }
            }
            break;
          }
        }
      }
    }
    uVar38 = 0x23;
    if (AgntFlag1 != false) {
      if ((((((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x < GfxRndSeed - 2U)
          || (GfxRndSeed + 1U <
              (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x)) ||
         ((in_stack_0000ffe2->base).y != GfxRndSeed2)) {
        bVar35 = false;
      }
      else {
        bVar35 = true;
      }
      if (((CONCAT11(uVar40,uVar47) < GfxRndSeed - 2U) ||
          (GfxRndSeed + 1U < CONCAT11(uVar40,uVar47))) || (GfxRndSeed2 != CONCAT11(uVar46,bVar49)))
      {
        bVar9 = false;
      }
      else {
        bVar9 = true;
      }
      if (bVar9 || bVar35) {
        if (bVar9) {
          if (bVar35) {
            for (cVar6 = func_0x0004f944(); uVar38 = 0x23, cVar6 != '\0'; cVar6 = cVar6 + -1) {
              uVar38 = 0x23;
              pcVar29 = ovr_ovc15_textArena((int)unaff_DI);
              if (((uint)pcVar29 & 0xff) == 0) break;
            }
          }
          else {
            cVar6 = (char)((ulong)((in_stack_0000ffe2->base).animFrame + 0xf) / 0x10);
            while (cVar8 = cVar6 + -1, cVar6 != '\0') {
              uVar38 = 0x22;
              ovr_agnt_usesAgntCount6
                        ((entity_t *)
                         CONCAT13((char)((ulong)Entities >> 0x18),
                                  CONCAT12((uint8_t)((ulong)Entities >> 0x10),
                                           (entity_t *)Entities + (int)unaff_DI)));
              cVar6 = cVar8;
            }
          }
        }
        else {
          ovr_ovc15_clearVisited();
          cVar6 = (char)((ulong)((in_stack_0000ffe2->base).animFrame + 0xf) / 0x10);
          while( true ) {
            uVar38 = 0x23;
            cVar8 = cVar6 + -1;
            if (cVar6 == '\0') break;
            ovr_ovc15_textArena((int)unaff_DI);
            cVar6 = cVar8;
          }
        }
      }
    }
    do {
      unaff_DI = unaff_DI + 1;
      if (EntityCount <= unaff_DI) {
        GGameState = 0x3c;
        uVar39 = uVar38;
        if (DebugVerbose != false) {
          uVar39 = 0x10;
          printf("%d %d %d  \r");
          uVar37 = uVar38;
        }
        func_0x0004fcda();
        GGameState = 0x3d;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
          uVar37 = uVar39;
        }
        ovr_OVC23_55fe_29a2_entry();
        GGameState = 0xc;
        if (DebugVerbose != false) {
          uVar37 = 0x23;
          printf("%d %d %d  \r");
        }
        ovr_ovc24_removeOtherEntities(&stack0xffe9);
        GGameState = 0x1f;
        if (uVar37 != 0x0) {
          ovr_constr_usesBlitRect();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (uVar26 = 0; (int)uVar26 < 5; uVar26 = uVar26 + 1) {
          if ((&stack0xfff2)[uVar26] != '\0') {
            ovr_ovc41_usesMiceBlitRect(uVar26);
          }
        }
        GGameState = 0xd;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        ovr_ovc24_checkStrongholds();
        GGameState = 0xe;
        mapDirty = 1;
        return (agnt_t *)((char *)"puppetmaker" + 3);
      }
      peVar28 = (entity_t *)Entities + (int)unaff_DI;
      uVar33 = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
      uVar26 = ovr_alignUp4((peVar28->base).destX);
      uVar39 = (uint8_t)uVar26;
      uVar46 = (undefined1)(uVar26 >> 8);
      uVar38 = 0x23;
      uVar26 = ovr_alignUp4((((entity_t *)CONCAT22(uVar33,peVar28))->base).x);
      if ((CONCAT11(uVar46,uVar39) == uVar26) && ((peVar28->base).destY == (peVar28->base).y)) {
        uVar37 = 0x23;
        func_0x0004fb8e();
      }
    } while (((peVar28->base).destX == 0 && (peVar28->base).destY == 0) ||
            (*(char *)((int)&(peVar28->base).entity + 1) != '\0'));
    uVar24 = (((entity_t *)CONCAT22(uVar33,peVar28))->base).x;
    uVar47 = (undefined1)uVar24;
    uVar40 = (undefined1)(uVar24 >> 8);
    uVar24 = (peVar28->base).y;
    bVar50 = (byte)uVar24;
    uVar23 = (undefined1)(uVar24 >> 8);
    in_stack_0000ffe2 = peVar28;
    in_stack_0000ffe4 = uVar33;
    bVar49 = bVar50;
    uVar46 = uVar23;
    if ((peVar28->base).faction < (byte)(peVar28->base).state) goto L_attact_3f0b_1082_11EA;
    ovr_ovc07_signum((peVar28->base).destX - (((entity_t *)CONCAT22(uVar33,peVar28))->base).x);
    cVar6 = 'g';
    uVar22 = 3;
    uVar24 = ovr_ovc07_signum((peVar28->base).destY - (peVar28->base).y);
    bVar7 = (byte)uVar24;
    uVar44 = (undefined1)(uVar24 >> 8);
    in_stack_0000ffe2 = peVar28;
    in_stack_0000ffe4 = uVar33;
    if (CONCAT11(uVar22,cVar6) != 0) {
      cVar6 = 'z';
      uVar22 = 3;
      uVar24 = ovr_randBelow(2);
      uVar21 = (undefined1)(uVar24 >> 8);
      in_stack_0000ffe2 = peVar28;
      in_stack_0000ffe4 = uVar33;
      if ((char)uVar24 != '\0') {
        cVar6 = '\x02' - cVar6;
        bVar49 = bVar50;
        uVar46 = uVar23;
        bVar7 = func_0x0004f412();
        uVar24 = (uint16_t)bVar7;
        in_stack_0000ffe2 = peVar28;
        in_stack_0000ffe4 = uVar33;
        bVar7 = bVar50;
        uVar44 = uVar23;
        uVar22 = uVar21;
        bVar50 = bVar49;
        uVar23 = uVar46;
        if (uVar24 == 0) {
          (((entity_t *)CONCAT22(uVar33,peVar28))->base).x =
               (((entity_t *)CONCAT22(uVar33,peVar28))->base).x + CONCAT11(uVar21,cVar6);
          (peVar28->base).target = 0x2 - cVar6;
          goto L_attact_3f0b_1082_1477;
        }
      }
    }
    bVar49 = bVar50;
    uVar46 = uVar23;
    if (CONCAT11(uVar44,bVar7) == 0) {
L_attact_3f0b_1082_134A:
      if (CONCAT11(uVar22,cVar6) != 0) {
        uVar23 = (undefined1)(uVar24 >> 8);
        cVar6 = '\x02' - cVar6;
        cVar8 = func_0x0004f412();
        if (cVar8 == '\0') {
          (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x =
               (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x +
               CONCAT11(uVar23,cVar6);
          (in_stack_0000ffe2->base).target = 0x2 - cVar6;
          goto L_attact_3f0b_1082_1477;
        }
      }
      uVar26 = ovr_ovc26_usesStExit((int)unaff_DI);
      if ((char)uVar26 == '\0') {
        uVar26 = ovr_ovc26_usesRandBelow
                           ((int)unaff_DI,(uint16_t)&stack0xffe9,(uint16_t)unaff_SS,
                            (uint16_t)&stack0xfff2,(uint16_t)unaff_SS);
        if (((uVar26 & 0xff) == 0) &&
           (*(char *)((int)(char **)GMenuStrings +
                     (uint)(in_stack_0000ffe2->base).gindex * 0x95 + 0x1f) == '\0')) {
          func_0x0004fb8e();
        }
      }
      else {
        (in_stack_0000ffe2->base).target =
             (byte)((int)(uint)*(byte *)((int)&(in_stack_0000ffe2->base).owner +
                                        ((int)(uint)(in_stack_0000ffe2->base).faction >> 2)) >>
                   (((in_stack_0000ffe2->base).faction & 3) << 1)) & 3;
        cVar6 = func_0x0004f32d();
        if (cVar6 == '\0') {
          (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x =
               (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x +
               (int)*(char *)((in_stack_0000ffe2->base).target + 0x885);
          puVar2 = &(in_stack_0000ffe2->base).y;
          *puVar2 = *puVar2 + (int)*(char *)((in_stack_0000ffe2->base).target + 0x889);
          puVar3 = &(in_stack_0000ffe2->base).faction;
          *puVar3 = *puVar3 + 0x1;
        }
      }
      goto L_attact_3f0b_1082_1477;
    }
    uVar22 = (undefined1)(uVar24 >> 8);
    cVar6 = bVar7 + 1;
    bVar7 = func_0x0004f412();
    uVar24 = (uint16_t)bVar7;
    if (uVar24 != 0) goto L_attact_3f0b_1082_134A;
    puVar2 = &(in_stack_0000ffe2->base).y;
    *puVar2 = *puVar2 + CONCAT11(uVar23,bVar50);
    (in_stack_0000ffe2->base).target = bVar50 + 1;
  } while( true );
}



/* 4207:288b */

/* [R4] calls ovr_alignUp4 */

bool __cdecl16far ovc15_usesAlignUp42(void)

{
  uint uVar1;
  uint uVar2;
  byte bStack_3;
  
  uVar2 = 0;
  uVar1 = ovr_alignUp4(GfxRndSeed);
  for (bStack_3 = 0; bStack_3 < 4; bStack_3 = bStack_3 + 1) {
    uVar2 = uVar2 | ((short (*) [60] [148])GMapFlags)[-1][GfxRndSeed2 + 0x3b]
                    [uVar1 + bStack_3 + 0x92] & 0x3000U;
  }
  return uVar2 == 0x3000;
}



/* 4207:28fa */

/* Sets CrossBlitX/CrossBlitY to the selected agent's screen position (y - 0x10). */

void __cdecl16far ovc15_positionCrosshair(void)

{
  if (SelectedAgent < AgntCount) {
    CrossBlitX = *(undefined2 *)((uint)SelectedAgent * 0x34 + 0x26);
    CrossBlitY = *(int *)((uint)SelectedAgent * 0x34 + 0x28) + -0x10;
  }
  return;
}



/* 4207:2961 */

/* Selects the agent with the smallest screen position and stores it in SelectedAgent. */

char * __cdecl16far ovc15_selectLeftmostAgent(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cStack_3;
  
  cStack_3 = -1;
  uVar3 = 0x7fff;
  uVar4 = 0x7fff;
  for (iVar2 = 0; iVar2 < (int)(uint)AgntCount; iVar2 = iVar2 + 1) {
    if ((*(uint *)(iVar2 * 0x34 + 0x26) < uVar3) ||
       ((*(uint *)(iVar2 * 0x34 + 0x26) == uVar3 && (*(uint *)(iVar2 * 0x34 + 0x28) < uVar4)))) {
      cStack_3 = (char)iVar2;
      uVar3 = *(uint *)(iVar2 * 0x34 + 0x26);
      uVar4 = *(uint *)(iVar2 * 0x34 + 0x28);
    }
  }
  if (cStack_3 == -1) {
    pcVar1 = (char *)0x0;
  }
  else {
    SelectedAgent = cStack_3;
    pcVar1 = (char *)"arena" + 5;
  }
  return pcVar1;
}



/* 4207:2a0e */

/* Selects the agent with the largest screen position and stores it in SelectedAgent. */

char * __cdecl16far ovc15_selectRightmostAgent(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cStack_3;
  
  cStack_3 = -1;
  uVar3 = 0;
  uVar4 = 0;
  for (iVar2 = 0; iVar2 < (int)(uint)AgntCount; iVar2 = iVar2 + 1) {
    if ((uVar3 < *(uint *)(iVar2 * 0x34 + 0x26)) ||
       ((*(uint *)(iVar2 * 0x34 + 0x26) == uVar3 && (uVar4 < *(uint *)(iVar2 * 0x34 + 0x28))))) {
      cStack_3 = (char)iVar2;
      uVar3 = *(uint *)(iVar2 * 0x34 + 0x26);
      uVar4 = *(uint *)(iVar2 * 0x34 + 0x28);
    }
  }
  if (cStack_3 == -1) {
    pcVar1 = (char *)0x0;
  }
  else {
    SelectedAgent = cStack_3;
    pcVar1 = (char *)"arena" + 5;
  }
  return pcVar1;
}



/* 4207:2ab9 */

/* [R2] string "arena" */

char * __cdecl16far ovc15_textArena4(void)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bStack_3;
  
  bStack_3 = 0xff;
  uVar3 = 0x7fff;
  uVar4 = 0x7fff;
  for (uVar2 = 0; (int)uVar2 < (int)(uint)AgntCount; uVar2 = uVar2 + 1) {
    if (((SelectedAgent != uVar2) &&
        ((*(uint *)((uint)SelectedAgent * 0x34 + 0x26) < *(uint *)(uVar2 * 0x34 + 0x26) ||
         ((*(int *)((uint)SelectedAgent * 0x34 + 0x26) == *(int *)(uVar2 * 0x34 + 0x26) &&
          (*(uint *)((uint)SelectedAgent * 0x34 + 0x28) < *(uint *)(uVar2 * 0x34 + 0x28))))))) &&
       ((*(uint *)(uVar2 * 0x34 + 0x26) < uVar3 ||
        ((*(uint *)(uVar2 * 0x34 + 0x26) == uVar3 && (*(uint *)(uVar2 * 0x34 + 0x28) < uVar4)))))) {
      bStack_3 = (byte)uVar2;
      uVar3 = *(uint *)(uVar2 * 0x34 + 0x26);
      uVar4 = *(uint *)(uVar2 * 0x34 + 0x28);
    }
  }
  if (bStack_3 == 0xff) {
    pcVar1 = (char *)0x0;
  }
  else {
    SelectedAgent = bStack_3;
    pcVar1 = (char *)"arena" + 5;
  }
  return pcVar1;
}



/* 4207:2c18 */

/* [R2] string "arena" */

char * __cdecl16far ovc15_textArena5(void)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bStack_3;
  
  bStack_3 = 0xff;
  uVar3 = 0;
  uVar4 = 0;
  for (uVar2 = 0; (int)uVar2 < (int)(uint)AgntCount; uVar2 = uVar2 + 1) {
    if (((SelectedAgent != uVar2) &&
        ((*(uint *)(uVar2 * 0x34 + 0x26) < *(uint *)((uint)SelectedAgent * 0x34 + 0x26) ||
         ((*(int *)((uint)SelectedAgent * 0x34 + 0x26) == *(int *)(uVar2 * 0x34 + 0x26) &&
          (*(uint *)(uVar2 * 0x34 + 0x28) < *(uint *)((uint)SelectedAgent * 0x34 + 0x28))))))) &&
       ((uVar3 < *(uint *)(uVar2 * 0x34 + 0x26) ||
        ((*(uint *)(uVar2 * 0x34 + 0x26) == uVar3 && (uVar4 < *(uint *)(uVar2 * 0x34 + 0x28))))))) {
      bStack_3 = (byte)uVar2;
      uVar3 = *(uint *)(uVar2 * 0x34 + 0x26);
      uVar4 = *(uint *)(uVar2 * 0x34 + 0x28);
    }
  }
  if (bStack_3 == 0xff) {
    pcVar1 = (char *)0x0;
  }
  else {
    SelectedAgent = bStack_3;
    pcVar1 = (char *)"arena" + 5;
  }
  return pcVar1;
}



/* 4207:2d75 */

/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc15_usesRandBelow2(void)

{
  uint16_t uVar1;
  uint uVar2;
  entity_t *peVar3;
  uint uVar4;
  undefined2 uVar5;
  byte bStack_9;
  byte bStack_8;
  byte bStack_7;
  uint uStack_6;
  uint uStack_4;
  
  uStack_4 = 0;
  bStack_8 = 0xff;
  uStack_6 = 0;
  bStack_9 = 0xff;
  for (bStack_7 = 0; bStack_7 < GLeaderCount; bStack_7 = bStack_7 + 1) {
    if ((*(char *)((int)*(undefined4 *)((uint)bStack_7 << 2) + 0x3f) == '\0') &&
       (uStack_4 < *(uint *)((int)*(undefined4 *)((uint)bStack_7 << 2) + 0x45))) {
      bStack_8 = bStack_7;
      uStack_4 = *(uint *)((int)*(undefined4 *)((uint)bStack_7 << 2) + 0x45);
    }
    if ((*(char *)((int)*(undefined4 *)((uint)bStack_7 << 2) + 0x3f) != '\0') &&
       (uStack_6 < *(uint *)((int)*(undefined4 *)((uint)bStack_7 << 2) + 0x45))) {
      bStack_9 = bStack_7;
      uStack_6 = *(uint *)((int)*(undefined4 *)((uint)bStack_7 << 2) + 0x45);
    }
  }
  if ((bStack_9 != 0xff) && (0xe < uStack_6)) {
    uVar1 = ovr_randBelow(EntityCount);
    uVar4 = uVar1 & 0xff;
    do {
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      peVar3 = (entity_t *)Entities;
      if ((*(byte *)((int)&peVar3[uVar4].base.entity + 3) == bStack_9) &&
         (uVar2 = ovr_ovc23_isCursorAt(((peVar3 + uVar4)->base).x,peVar3[uVar4].base.y),
         (uVar2 & 0xff) == 0)) {
        return uVar4;
      }
      uVar4 = uVar4 + 1;
      if (EntityCount <= uVar4) {
        uVar4 = 0;
      }
    } while (uVar4 != (uVar1 & 0xff));
  }
  if ((bStack_8 != 0xff) && (0x1d < uStack_4)) {
    uVar1 = ovr_randBelow(EntityCount);
    uVar4 = uVar1 & 0xff;
    do {
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      peVar3 = (entity_t *)Entities;
      if (((*(byte *)((int)&peVar3[uVar4].base.entity + 3) == bStack_8) &&
          (uVar2 = ovr_ovc23_isCursorAt(((peVar3 + uVar4)->base).x,peVar3[uVar4].base.y),
          (uVar2 & 0xff) == 0)) &&
         ((*(byte *)((int)&((entity_t *)Entities)[uVar4].base.flags32 + 1) & 3) == 0)) {
        return uVar4;
      }
      uVar4 = uVar4 + 1;
      if (EntityCount <= uVar4) {
        uVar4 = 0;
      }
    } while (uVar4 != (uVar1 & 0xff));
  }
  uVar1 = ovr_randBelow(EntityCount);
  return uVar1 & 0xff;
}


