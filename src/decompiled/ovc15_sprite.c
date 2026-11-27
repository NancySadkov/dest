/*
 * ovc15_sprite.c - recovered from STRONG.EXE
 * memory block: OVC15_sprite.c
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
  int *piVar2;
  uint16_t i;
  uint16_t unaff_DI;
  uint16_t count;
  far_t dst;
  frm_t *frm;
  far_t far *in_stack_00000004;
  uint32_t prev_next;
  frm_t *pfStack_20;
  uint16_t xx;
  uint16_t exx;
  uint16_t sxx;
  uint16_t j;
  uint32_t p_ow;
  uint16_t ey;
  uint16_t ex;
  uint16_t sy;
  uint16_t sx;
  
  if (0x4e < StshSprIndex) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x36);
  }
  dst.seg = (uint16_t)((spr_t far *)StshSprites + StshSprIndex);
  StshSprIndex = StshSprIndex + 1;
  dst.ofs = (uint16_t)ovr_mkp((uint32_t *)dst.seg,(*(uint16_t *)((uint8_t *)&(StshSprites) + 2)),unaff_DI);
  _fsetmem(MK_FP(dst.seg,dst.ofs),0xb0,0);
  i = 0;
  while ((i < (*(uint16_t *)((uint8_t *)&(anms) + 2)) && (*(char *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0x1b) != '\0'))) {
    uVar1 = (uint)*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e);
    prev_next = CONCAT22(dst.seg,dst.ofs + uVar1 * 4 + 0x58);
    piVar2 = (int *)(dst.ofs + uVar1 * 4);
    piVar2[1] = (int)(anm_t *)anms;
    *piVar2 = (*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e;
    sx = *(uint16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 1);
    sy = *(uint16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 3);
    ex = *(uint16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 5);
    ey = *(uint16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 7);
    anim_height = ey - sy;
    if ((int)anim_height < 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x33);
    }
    p_ow = 0;
    j = 0;
    while( true ) {
      (*(uint16_t *)((uint8_t *)&(frm) + 2)) = (uint16_t)((ulong)((long)(int)i * 0x1e) >> 0x10);
      if (*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + (int)((long)(int)i * 0x1e) + 0x1b) <= j) break;
      (*(uint16_t *)((uint8_t *)&(frm))) =(uint16_t)( (frm_t *)ovr_stshRleSub(in_stack_00000004,(uint8_t *)src,sx,sy,ex,ey,21));
      pfStack_20 = (frm_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(frm) + 2)),(frm_t *)frm);
      ((frm_t *)frm)->type2 = 2;
      ((frm_t *)frm)->x = *(int16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0xb);
      ((frm_t *)frm)->y = *(int16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0xd);
      *(uint16_t *)((int)prev_next + 2) = (*(uint16_t *)((uint8_t *)&(frm) + 2));
      *(frm_t **)prev_next = (frm_t *)frm;
      prev_next = CONCAT22((*(uint16_t *)((uint8_t *)&(frm) + 2)),&((frm_t *)frm)->next);
      if ((*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0x1c) & 1) == 0) {
        ((frm_t *)frm)->ow = *(uint8_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0xf);
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
            if (*(char *)((int)&in_stack_00000004[ey * 0x50 + 0x50].ofs + xx) == -2) {
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
          for (xx = sx; *(char *)((int)&in_stack_00000004[ey * 0x50 + 0x50].ofs + xx) != -2;
              xx = xx + 1) {
            if (ex + row < xx) {
                    /* WARNING: Subroutine does not return */
              ovr_stExit(9);
            }
          }
          ((frm_t *)frm)->ow = (char)exx - (char)xx;
          exx = xx;
        }
      }
      pfStack_20->type4 = 4;
      *(uint16_t *)((int)&((frm_t *)frm)->next + 2) = 0;
      *(uint16_t *)&((frm_t *)frm)->next = 0;
      sy = sy + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 10);
      ey = ey + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 10);
      if (199 < ey) {
        sy = *(int *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 3) % (int)(uint)*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 10);
        ey = sy + anim_height;
        sx = sx + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 9);
        ex = ex + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 9);
        sxx = sxx + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 9);
        exx = exx + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 9);
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
stshSprite(far_t *retStorage,int16_t file_id,anm_t *anms,uint16_t nanims,bool grab)

{
  far_t handle;
  uint16_t ofs;
  uint16_t seg;
  uint16_t unaff_SI;
  spr_t *spr;
  stg_tmp_t *fVar6;
  far_t pixels;
  far_t handle_00;
  
  if ((char)nanims == '\0') {
    (*(uint16_t *)((uint8_t *)&(spr))) = ovr_stshSpriteStub((anm_t *)file_id,(uint16_t)(anm_t *)anms);
  }
  else {
    (*(uint16_t *)((uint8_t *)&(fVar6))) = ovr_grabLbm((int16_t)retStorage,0,0);
    pixels.seg = (((stg_tmp_t *)fVar6)->aptr).seg;
    pixels.ofs = (&((stg_tmp_t *)fVar6)->aptr)->ofs;
    seg = (*(uint16_t *)((uint8_t *)&(fVar6) + 2));
    ovr_grabRemap(pixels,0xff,0x0);
    ofs = (uint16_t)
          stshRleAnims((uint8_t *)CONCAT22(file_id,(uint8_t *)(((stg_tmp_t *)fVar6)->aptr).seg),anms
                       ,unaff_SI);
    handle_00.seg = (((stg_tmp_t *)fVar6)->bptr).seg;
    handle_00.ofs = (&((stg_tmp_t *)fVar6)->bptr)->ofs;
    ovr_stshFree(handle_00);
    handle.seg = (*(uint16_t *)((uint8_t *)&(fVar6) + 2));
    handle.ofs = (uint16_t)(stg_tmp_t *)fVar6;
    ovr_stshFree(handle);
    stshStoreSprite((spr_t *)CONCAT22(file_id,seg),anms,unaff_SI);
    (*(uint16_t *)((uint8_t *)&(spr))) =(uint16_t)( (spr_t *)ofs);
  }
  return (far_t far *)(spr_t *)spr;
}


/* 4207:0462 */

void __cdecl16far allocSprSeqs(void)

{
  
  StshSprites = ovr_stshAlloc(0x3650);
  return;
}



/* 4207:047b */
void __cdecl16far stshInitSprites(bool grab)

{
  uint16_t in_AX;
  far_t far *pfVar1;
  int labelOfs;
  int prtOfs;
  stg_tmp_t *gfx;
  cte_t *pcVar4;
  uint32_t *puVar5;
  uint16_t in_DX;
  uint16_t uVar6;
  uint8_t *puVar7;
  uint8_t *puVar8;
  uint16_t uVar9;
  uint16_t i;
  far_t far *unaff_DI;
  int iVar10;
  uint16_t j;
  far_t pixels;
  long sz;
  
  StshSprIndex = 0;
  pfVar1 = stshSprite((far_t *)((byte *)__C0_ASM_CopyRight + 0x21),0,(anm_t *)0x9195d,
                      CONCAT11((char)((uint)in_AX >> 8),grab),SUB21(unaff_DI,0));
  SprProjectiles.ofs = (uint16_t)pfVar1;
  SprProjectiles.seg = in_DX;
  for (i = 0; (int)i < 0x2a; i = i + 1) {
    pfVar1 = stshSprite((far_t *)*(uint16_t *)((int)AgntGs[0].sprfls + i * 0x95),
                        *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                        (anm_t *)(ulong)CONCAT12(*(undefined1 *)((int)&AgntGs[0].nanims + i * 0x95),
                                                 *(uint16_t *)
                                                  ((int)&AgntGs[0].anms + 2 + i * 0x95)),
                        CONCAT11((char)((uint)pfVar1 >> 8),grab),SUB21(unaff_DI,0));
    asm { mov uVar6,dx };
    *(uint16_t *)((int)AgntGs[0].sprs + 2 + i * 0x95) = uVar6;
    *(uint16_t *)((int)AgntGs[0].sprs + i * 0x95) =(uint16_t)( pfVar1);
    if (*(int *)((int)AgntGs[0].sprfls + 2 + i * 0x95) == 0) {
      uVar6 = *(uint16_t *)((int)AgntGs[0].sprs + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].sprs + 6 + i * 0x95) =
           *(uint16_t *)((int)AgntGs[0].sprs + 2 + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].sprs + 4 + i * 0x95) = uVar6;
    }
    else {
      pfVar1 = stshSprite((far_t *)*(uint16_t *)((int)AgntGs[0].sprfls + 2 + i * 0x95),
                          *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                          (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                    ((int)&AgntGs[0].nanims + i * 0x95),
                                                   *(uint16_t *)
                                                    ((int)&AgntGs[0].anms + 2 + i * 0x95)),
                          CONCAT11((char)(i * 0x95 >> 8),grab),SUB21(unaff_DI,0));
      asm { mov uVar6,dx };
      *(uint16_t *)((int)AgntGs[0].sprs + 6 + i * 0x95) = uVar6;
      *(uint16_t *)((int)AgntGs[0].sprs + 4 + i * 0x95) =(uint16_t)( pfVar1);
    }
    if (*(int *)((int)AgntGs[0].sprfls + 4 + i * 0x95) == 0) {
      uVar6 = *(uint16_t *)((int)AgntGs[0].sprs + 4 + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].sprs + 10 + i * 0x95) =
           *(uint16_t *)((int)AgntGs[0].sprs + 6 + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].sprs + 8 + i * 0x95) = uVar6;
    }
    else {
      pfVar1 = stshSprite((far_t *)*(uint16_t *)((int)AgntGs[0].sprfls + 4 + i * 0x95),
                          *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                          (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                    ((int)&AgntGs[0].nanims + i * 0x95),
                                                   *(uint16_t *)
                                                    ((int)&AgntGs[0].anms + 2 + i * 0x95)),
                          CONCAT11((char)(i * 0x95 >> 8),grab),SUB21(unaff_DI,0));
      asm { mov uVar6,dx };
      *(uint16_t *)((int)AgntGs[0].sprs + 10 + i * 0x95) = uVar6;
      *(uint16_t *)((int)AgntGs[0].sprs + 8 + i * 0x95) =(uint16_t)( pfVar1);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      labelOfs = i * 0x95 + iVar10 * 2;
      if (*(int *)((int)AgntGs[0].sprfls + 6 + labelOfs) == 0) {
        labelOfs = i * 0x95 + iVar10 * 4;
        uVar6 = *(uint16_t *)((int)AgntGs[0].sprs + labelOfs);
        prtOfs = i * 0x95 + iVar10 * 4;
        *(uint16_t *)((int)AgntGs[0].sprs + 0xe + prtOfs) =
             *(uint16_t *)((int)AgntGs[0].sprs + 2 + labelOfs);
        *(uint16_t *)((int)AgntGs[0].sprs + 0xc + prtOfs) = uVar6;
      }
      else {
        pfVar1 = stshSprite((far_t *)*(uint16_t *)
                                      ((int)AgntGs[0].sprfls + 6 + i * 0x95 + iVar10 * 2),
                            *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                            (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                      ((int)&AgntGs[0].nanims + i * 0x95),
                                                     *(uint16_t *)
                                                      ((int)&AgntGs[0].anms + 2 + i * 0x95)),
                            CONCAT11((char)((uint)labelOfs >> 8),grab),SUB21(unaff_DI,0));
        asm { mov uVar6,dx };
        labelOfs = i * 0x95 + iVar10 * 4;
        *(uint16_t *)((int)AgntGs[0].sprs + 0xe + labelOfs) = uVar6;
        *(uint16_t *)((int)AgntGs[0].sprs + 0xc + labelOfs) =(uint16_t)( pfVar1);
      }
    }
    for (j = 0; (int)j < 6; j = j + 1) {
      if (*(int *)((int)AgntGs[0].prtfls + i * 0x95 + j * 2) != 0) {
        if (grab) {
          puVar7 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
          gfx = ovr_grabLbm(*(int16_t *)((int)AgntGs[0].prtfls + i * 0x95 + j * 2),0,0);
          puVar8 = puVar7;
          ovr_stshUniqueColorsRemap(gfx,puVar7);
          pixels.seg = 0;
          pixels.ofs = (gfx->aptr).seg;
          pfVar1 = ovr_stshRleType2((far_t far *)(&gfx->aptr)->ofs,pixels,0,114,103,0,0,(int16_t)unaff_DI,0,0);
          pcVar4 = (char *)stsh_store((uint8_t *)pfVar1, (uint16_t)puVar8, &uVar6);
          iVar10 = i * 0x95 + j * 4;

          *(int *)((int)AgntGs[0].prts + 2 + iVar10) = (int)puVar8;
          *(uint16_t *)((int)AgntGs[0].prts + iVar10) =(uint16_t)( pcVar4);
          sz = ZEXT24(unaff_DI) << 0x10;
          puVar5 = ovr_stshWrite((uint32_t *)gfx,(uint8_t *)CONCAT22(0x300,puVar7),sz,0);
          unaff_DI = (far_t far *)((ulong)sz >> 0x10);
          iVar10 = i * 0x95 + j * 4;
          *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar10) = uVar6;
          *(uint16_t *)((int)AgntGs[0].prtpals + iVar10) =(uint16_t)( puVar5);
          ovr_stgFreeTmp(gfx,puVar7);
        }
        else {
          pfVar1 = ovr_stshAllocStub(unaff_DI);
          iVar10 = i * 0x95 + j * 4;
          asm { mov uVar6,dx };
          *(uint16_t *)((int)AgntGs[0].prts + 2 + iVar10) = uVar6;
          *(uint16_t *)((int)AgntGs[0].prts + iVar10) =(uint16_t)( pfVar1);
          pfVar1 = ovr_stshAllocStub(unaff_DI);
          asm { mov uVar9,dx };
          iVar10 = i * 0x95 + j * 4;
          *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar10) = uVar9;
          *(uint16_t *)((int)AgntGs[0].prtpals + iVar10) =(uint16_t)( pfVar1);
        }
      }
    }
    pfVar1 = (far_t far *)(*(uint *)((int)AgntGs[0].prts + 4 + i * 0x95) |
                      *(uint *)((int)AgntGs[0].prts + 6 + i * 0x95));
    if ((pfVar1 == (far_t far *)0x0) &&
       (pfVar1 = (far_t far *)0x0,
       *(int *)((int)AgntGs[0].prts + i * 0x95) != 0 ||
       *(int *)((int)AgntGs[0].prts + 2 + i * 0x95) != 0)) {
      uVar6 = *(uint16_t *)((int)AgntGs[0].prts + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].prts + 6 + i * 0x95) =
           *(uint16_t *)((int)AgntGs[0].prts + 2 + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].prts + 4 + i * 0x95) = uVar6;
      pfVar1 = (far_t far *)*(uint16_t *)((int)AgntGs[0].prtpals + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].prtpals + 6 + i * 0x95) =
           *(uint16_t *)((int)AgntGs[0].prtpals + 2 + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].prtpals + 4 + i * 0x95) =(uint16_t)( pfVar1);
    }
    for (iVar10 = 2; iVar10 < 6; iVar10 = iVar10 + 2) {
      labelOfs = i * 0x95 + iVar10 * 4;
      if ((*(int *)((int)AgntGs[0].prts + 4 + labelOfs) == 0 &&
           *(int *)((int)AgntGs[0].prts + 6 + labelOfs) == 0) &&
         (labelOfs = i * 0x95 + iVar10 * 4,
         *(int *)((int)AgntGs[0].prtfls + 8 + labelOfs) != 0 ||
         *(int *)((int)AgntGs[0].prtfls + 10 + labelOfs) != 0)) {
        labelOfs = i * 0x95 + iVar10 * 4;
        uVar6 = *(uint16_t *)((int)AgntGs[0].prtfls + 8 + labelOfs);
        prtOfs = i * 0x95 + iVar10 * 4;
        *(uint16_t *)((int)AgntGs[0].prts + 6 + prtOfs) =
             *(uint16_t *)((int)AgntGs[0].prtfls + 10 + labelOfs);
        *(uint16_t *)((int)AgntGs[0].prts + 4 + prtOfs) = uVar6;
        labelOfs = i * 0x95 + iVar10 * 4;
        uVar6 = *(uint16_t *)((int)AgntGs[0].prts + 0x14 + labelOfs);
        prtOfs = i * 0x95 + iVar10 * 4;
        *(uint16_t *)((int)AgntGs[0].prtpals + 6 + prtOfs) =
             *(uint16_t *)((int)AgntGs[0].prts + 0x16 + labelOfs);
        *(uint16_t *)((int)AgntGs[0].prtpals + 4 + prtOfs) = uVar6;
      }
      labelOfs = i * 0x95 + iVar10 * 4;
      pfVar1 = (far_t far *)(*(uint *)((int)AgntGs[0].prts + labelOfs) |
                        *(uint *)((int)AgntGs[0].prts + 2 + labelOfs));
      if (pfVar1 == (far_t far *)0x0) {
        labelOfs = i * 0x95 + iVar10 * 4;
        if (*(int *)((int)AgntGs[0].prtfls + 4 + labelOfs) == 0 &&
            *(int *)((int)AgntGs[0].prtfls + 6 + labelOfs) == 0) {
          pfVar1 = (far_t far *)0x0;
        }
        else {
          labelOfs = i * 0x95 + iVar10 * 4;
          uVar6 = *(uint16_t *)((int)AgntGs[0].prtfls + 4 + labelOfs);
          prtOfs = i * 0x95 + iVar10 * 4;
          *(uint16_t *)((int)AgntGs[0].prts + 2 + prtOfs) =
               *(uint16_t *)((int)AgntGs[0].prtfls + 6 + labelOfs);
          *(uint16_t *)((int)AgntGs[0].prts + prtOfs) = uVar6;
          labelOfs = i * 0x95 + iVar10 * 4;
          pfVar1 = (far_t far *)*(uint16_t *)((int)AgntGs[0].prts + 0x10 + labelOfs);
          prtOfs = i * 0x95 + iVar10 * 4;
          *(uint16_t *)((int)AgntGs[0].prtpals + 2 + prtOfs) =
               *(uint16_t *)((int)AgntGs[0].prts + 0x12 + labelOfs);
          *(uint16_t *)((int)AgntGs[0].prtpals + prtOfs) =(uint16_t)( pfVar1);
        }
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
    _fsetmem(AgntArrayA,0x41a,0);
    _fsetmem(AgntArrayB,0x41a,0);
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
      AgntArrayA[uVar1][(vramOfs >> 1)] = 0xff;
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
    Agnts[iVar1].visited = 0;
  }
  return;
}



/* 4207:0bb7 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches agntIndex, EntityCount */

void __cdecl16far ovc15_usesAgntIndex(void)

{
  uint agntIndex;
  int entitiesOfs;
  int bottomIdx;
  int topIdx;
  uint16_t entitiesSeg;
  uint8_t agentIndices;
  uint linesBottom;
  uint linesTop;
  int count;
  uint i;
  
  ovc15_clearVisited();
  count = 0;
  for (i = 0; i < EntityCount; i = i + 1) {
    entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
    if (((GfxRndSeed - 2U <= *(uint *)((entity_t far *)Entities + i)) &&
        (*(uint *)((entity_t far *)Entities + i) <= GfxRndSeed + 1U)) &&
       (((entity_t far *)Entities)[i].base.y == GfxRndSeed2)) {
      *(uint *)(&agentIndices + count * 2) = i;
      count = count + 1;
    }
  }
  topIdx = 0;
  bottomIdx = 0;
  while ((bottomIdx < count || (topIdx < count))) {
    while( true ) {
      entitiesOfs = (int)Entities;
      entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
      if ((count <= topIdx) ||
         (AgntGs[(uint)*(byte *)(entitiesOfs + *(int *)(&agentIndices + topIdx * 2) * 0x37 + 0xd)].ai == '\x01')) break;
      topIdx = topIdx + 1;
    }
    while ((bottomIdx < count &&
           (AgntGs[(uint)*(byte *)(entitiesOfs + *(int *)(&agentIndices + bottomIdx * 2) * 0x37 + 0xd)].ai != '\0'))) {
      bottomIdx = bottomIdx + 1;
    }
    if (topIdx < count) {
      linesTop = (*(byte *)(entitiesOfs + *(int *)(&agentIndices + topIdx * 2) * 0x37 + 0xe) + 0xf) / 0x10;
    }
    else {
      linesTop = 0;
    }
    if (bottomIdx < count) {
      linesBottom = (*(byte *)(entitiesOfs + *(int *)(&agentIndices + bottomIdx * 2) * 0x37 + 0xe) + 0xf) / 0x10;
    }
    else {
      linesBottom = 0;
    }
    while ((linesTop != 0 || (linesBottom != 0))) {
      if (linesTop != 0) {
        ovc15_textArena(*(int *)(&agentIndices + topIdx * 2),0,(uint)(AgntFlag1 == false));
        linesTop = linesTop - 1;
      }
      if (linesBottom != 0) {
        ovc15_textArena(*(int *)(&agentIndices + bottomIdx * 2),0,(uint)(AgntFlag1 == false));
        linesBottom = linesBottom - 1;
      }
    }
    if (topIdx < count) {
      topIdx = topIdx + 1;
    }
    if (bottomIdx < count) {
      bottomIdx = bottomIdx + 1;
    }
  }
  for (i = 0; agntIndex = i, (int)i < (int)(uint)AgntCount;
      i = i + 1) {
    if (Agnts[i].visited == '\0') {
      i = i - 1;
      ovr_ovc41_removeAgent(agntIndex,0,0);
    }
  }
  AgntFlag1 = true;
  return;
}



/* 4207:0e17 */
void __cdecl16far ovc15_removeEntity(uint entityIndex)

{
  int *ownerPtr;
  char aiValue;
  char partyIndex;
  uint16_t x;
  uint16_t y;
  entity_t far *entities;
  uint agntIdx;
  
  if (AgntFlag1) {
    for (agntIdx = 0; agntIdx < AgntCount; agntIdx = agntIdx + 1) {
      if ((Agnts[agntIdx].owner == entityIndex) &&
         (Agnts[agntIdx].combatState != '\x02')) {
        Agnts[agntIdx].combatState = 2;
        Agnts[agntIdx].targetY = 0;
      }
    }
  }
  entities = Entities;
  x = entities[entityIndex].base.destX;
  y = entities[entityIndex].base.destY;
  aiValue = AgntGs[(uint)entities[entityIndex].base.gindex].ai;
  partyIndex = *((char far *)&entities[entityIndex].base.entity + 3);
  if (entityIndex < EntityCount - 1U) {
    _fmemmove((char far *)(entities + entityIndex),
              (char far *)(entities + entityIndex + 1),
              ((EntityCount + -1) - entityIndex) * 0x37);
  }
  if (AgntFlag1 != false) {
    for (agntIdx = 0; agntIdx < AgntCount; agntIdx = agntIdx + 1) {
      if (entityIndex < Agnts[agntIdx].owner) {
        ownerPtr = (int *)&Agnts[agntIdx].owner;
        *ownerPtr = *ownerPtr + -1;
        entities = Entities + Agnts[agntIdx].owner;
        AGNT_WORD(&Agnts[agntIdx], entity, 2) = DAT_2000_d190;
        AGNT_WORD(&Agnts[agntIdx], entity, 0) =far_ofs_u32(entities);
      }
    }
  }
  EntityCount = EntityCount + -1;
  if ((aiValue == '\0') && ((x != 0 || (y != 0)))) {
    ovr_attact_usesAlignUp4(x,y,partyIndex,0,partyIndex);
  }
  ovr_attact_usesGMapFlags3();
  return;
}


/* 4207:0ff0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

uint __cdecl16far ovc15_usesAlignUp4(uint16_t x,uint16_t y)

{
  /* Re-derived: the first entity whose target cell is alignUp4(x)/y with flags byte bit 1
     set (+0x33), whose +0x1a byte is not -1, and whose leader sheet's +0x3f byte is zero. */
  uint32_t sheetRef;
  uint alignedX;
  uint entOfs;
  int entitiesOfs;
  uint i;
  uint16_t targetY;
  uint targetAlignedX;
  uint sheetFlag;

  alignedX = ovr_alignUp4(x,0,0);
  i = 0;
  do {
    if (EntityCount <= i) {
      return 0;
    }
    entOfs = i * 0x37;
    if ((((*(byte *)(entitiesOfs + entOfs + 0x33) & 2) != 0) &&
        (targetY = ((entity_t far *)Entities)[i].base.targetY, targetY == y)) &&
       (targetAlignedX = ovr_alignUp4(((entity_t far *)Entities)[i].base.targetX,0,0),
        targetAlignedX == alignedX)) {
      entOfs = i * 0x37;
      if ((*(char *)((int)Entities + entOfs + 0x1a) != -1) &&
         (sheetRef = *(uint32_t *)
                     ((uint)AGNT_FIELD(&(Entities)[i], base.entity, 3) << 2),
         sheetFlag = (uint)*(byte *)((int)sheetRef + 0x3f), sheetFlag == 0)) {
        return 1;
      }
    }
    i = i + 1;
  } while( true );
}



/* 4207:10a3 */
entity_t * __cdecl16far
ovc15_usesLDIV_at_(uint16_t x,uint16_t y,uint16_t destX,uint16_t destY,byte gindex,uint8_t animFrame,byte partyIndex,uint16_t arg8,uint16_t arg9,uint16_t arg10,uint16_t arg11)

{
  uint8_t *puVar1;
  uint *puVar2;
  uint16_t uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  entity_t *peVar7;
  uint16_t uVar8;
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
    _fsetmem(MK_FP((int)((ulong)Entities >> 0x10),Entities + EntityCount),0x37,0);
    (Entities)[EntityCount].base.targetX = destX;
    (Entities)[EntityCount].base.targetY = destY;
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    if ((destX == x) && (destY == y)) {
      (Entities)[EntityCount].base.destX = 0;
      (Entities)[EntityCount].base.destY = 0;
    }
    else {
      (Entities)[EntityCount].base.destX = destX;
      (Entities)[EntityCount].base.destY = destY;
    }
    ((Entities + EntityCount)->base).x = x;
    (Entities)[EntityCount].base.y = y;
    (Entities)[EntityCount].base.target = 0xff;
    (Entities)[EntityCount].base.gindex = gindex;
    uVar5 = EntityCount;
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    peVar7 = Entities;
    puVar1 = &peVar7[EntityCount].base.frameIndex;
    puVar1[0] = 0x0;
    puVar1[1] = 0x0;
    puVar1 = &peVar7[uVar5].base.health;
    puVar1[0] = 0x64;
    puVar1[1] = 0x0;
    *(uint16_t *)((int)&(Entities)[EntityCount].base.frames + 1) = 0;
    (Entities)[EntityCount].base.animFrame = animFrame;
    *(byte *)((int)&(Entities)[EntityCount].base.entity + 3) = partyIndex;
    *(undefined1 *)((int)&(Entities)[EntityCount].base.state + 1) =
         AgntGs[(uint)gindex].strength;
    *(undefined1 *)&(Entities)[EntityCount].base.flags32 =
         AgntGs[(uint)gindex].strength;
    if (*((char far *)GLeaderSheets[partyIndex] + 0x2f) != -1) {
      uVar5 = (uint)AgntGs[(uint)gindex].strength;
      uVar8 = ovr_agnt_abilityModifier(partyIndex,4);
      iStack_6 = uVar5 + (int)(char)uVar8;
      if (iStack_6 < 1) {
        iStack_6 = 1;
      }
      *(undefined1 *)((int)&(Entities)[EntityCount].base.state + 1) =
           (undefined1)iStack_6;
      *(undefined1 *)&(Entities)[EntityCount].base.flags32 = (undefined1)iStack_6;
    }
    if (AgntGs[(uint)gindex].ai == '\0') {
      uVar5 = ovc15_usesAlignUp4(destX,destY);
      if ((uVar5 & 0xff) == 0) {
        *(undefined1 *)((int)&(Entities)[EntityCount].base.flags32 + 1) = 2;
      }
    }
    else if ((destX == x) && (destY == y)) {
      *(undefined1 *)((int)&(Entities)[EntityCount].base.flags32 + 1) = 2;
    }
    if ((AgntGs[(uint)gindex].flags2 & 0x1000) == 0) {
      if ((AgntGs[(uint)gindex].flags2 & 0x2000) == 0) {
        lVar9 = 0x8000;
        uVar5 = rand();
        lVar9 = LDIV_at_(CONCAT22(((int)uVar5 >> 0xf) << 1 | (uint)((int)uVar5 < 0),uVar5 << 1),
                         lVar9);
        if ((int)lVar9 == 0) {
          puVar2 = (uint *)((int)&(Entities)[EntityCount].base.frames + 3);
          *puVar2 = *puVar2 | 1;
        }
      }
      else {
        puVar2 = (uint *)((int)&(Entities)[EntityCount].base.frames + 3);
        *puVar2 = *puVar2 | 1;
      }
    }
    (Entities)[EntityCount].base.level =
         AgntGs[(uint)gindex].shortName[0];
    if (((((GLeaderSheets[partyIndex])->flags5d & 0x10) != 0) &&
        (AgntGs[(uint)gindex].shortName[0] < 5)) &&
       (AgntGs[(uint)gindex].shortName[3] != -1)) {
      while ((Entities)[EntityCount].base.level < 5) {
        cVar4 =(uint16_t)( ovr_ovc15_textView()   /* hand fix: args lost by the decompiler */);
        uVar8 = (uint16_t)((ulong)Entities >> 0x10);
        *(char *)((int)&(Entities)[EntityCount].base.state + 1) =
             *(char *)((int)&(Entities)[EntityCount].base.state + 1) + cVar4;
        uVar8 = (uint16_t)((ulong)Entities >> 0x10);
        *(char *)&(Entities)[EntityCount].base.flags32 =
             (char)(Entities)[EntityCount].base.flags32 + cVar4;
        puVar1 = &(Entities)[EntityCount].base.level;
        *puVar1 = *puVar1 + 0x1;
      }
    }
    uVar5 = EntityCount;
    peVar7 = Entities;
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    if (AgntGs[(uint)gindex].shortName[3] == -1) {
      iVar6 = (uint)peVar7[EntityCount].base.level * 4;
      uVar3 = *(uint16_t *)(iVar6 + -4);
      *(uint16_t *)&peVar7[EntityCount].base.frameIndex = *(uint16_t *)(iVar6 + -2);
      *(uint16_t *)&peVar7[uVar5].base.health = uVar3;
    }
    else {
      iVar6 = (uint)AgntGs[(uint)gindex].shortName[3] * 0x94 +
              (uint)peVar7[EntityCount].base.level * 4;
      uVar3 = *(uint16_t *)(iVar6 + -4);
      *(uint16_t *)&peVar7[EntityCount].base.frameIndex = *(uint16_t *)(iVar6 + -2);
      *(uint16_t *)&peVar7[uVar5].base.health = uVar3;
    }
    uVar5 = EntityCount;
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    peVar7 = Entities;
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
      uVar8 = (uint16_t)((ulong)Entities >> 0x10);
      peVar7 = Entities;
      if (((GfxRndSeed - 2U <= ((peVar7 + uVar5)->base).x) &&
          (((peVar7 + uVar5)->base).x <= GfxRndSeed + 1U)) && (peVar7[uVar5].base.y == GfxRndSeed2))
      {
        ovc15_textArena(uVar5,0,0);
      }
    }
    peVar7 = Entities + uVar5;
    return peVar7;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x26);
}


/* 4207:16a5 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls LDIV_at_ */

void __cdecl16far ovc15_usesLDIV_at_2(int entityIndex,byte gindex,char partySlot)

{
  uint8_t *frameBytes;
  uint8_t *healthBytes;
  uint *fieldFlags;
  byte gindexCopy;
  entity_t *peVar6;
  uint randVal;
  uint16_t animRand;
  uint16_t panVal;
  entity_t *peVar9;
  far_t far *frameTab;
  int agnt;
  bool frameFlag;
  long lVar15;
  
  if (partySlot != -1) {
    mapDirty = 1;
    peVar6 = Entities;
    Entities[entityIndex].base.target = 0xff;
    peVar6[entityIndex].base.gindex = gindex;
    peVar6[entityIndex].base.level =
         AgntGs[(uint)gindex].shortName[0];
    frameBytes = &peVar6[entityIndex].base.frameIndex;
    frameBytes[0] = 0x0;
    frameBytes[1] = 0x0;
    healthBytes = &peVar6[entityIndex].base.health;
    healthBytes[0] = 0x64;
    healthBytes[1] = 0x0;
    *(uint16_t *)((int)&peVar6[entityIndex].base.frames + 1) = 0;
    *(uint16_t *)((int)&peVar6[entityIndex].base.frames + 3) = 0;
    *(char *)((int)&peVar6[entityIndex].base.entity + 3) = partySlot;
    *(undefined1 *)((int)&peVar6[entityIndex].base.state + 1) =
         AgntGs[(uint)gindex].strength;
    *(undefined1 *)&peVar6[entityIndex].base.flags32 =
         AgntGs[(uint)gindex].strength;
    lVar15 = 0x8000;
    randVal = rand();
    lVar15 = LDIV_at_(CONCAT22(((int)randVal >> 0xf) << 1 | (uint)((int)randVal < 0),randVal << 1),lVar15)
    ;
    if ((int)lVar15 == 0) {
      fieldFlags = (uint *)((int)&peVar6[entityIndex].base.frames + 3);
      *fieldFlags = *fieldFlags | 1;
    }
    ovr_attact_usesGMapFlags3();
    if (AgntFlag1 != false) {
      peVar9 = Entities;
      if (((GfxRndSeed - 2U <= ((peVar9 + entityIndex)->base).x) &&
          (((peVar9 + entityIndex)->base).x <= GfxRndSeed + 1U)) &&
         (peVar9[entityIndex].base.y == GfxRndSeed2)) {
        for (agnt = 0; agnt < (int)(uint)AgntCount; agnt = agnt + 1) {
          if (Agnts[agnt].owner == entityIndex) {
            Agnts[agnt].target = 0xff;
            gindexCopy = peVar6[entityIndex].base.gindex;
            AGNT_WORD(&Agnts[agnt], gdata, 2) = SEG_OF(AgntGs);
            AGNT_WORD(&Agnts[agnt], gdata, 0) = (uint)&AgntGs[gindexCopy];
            Agnts[agnt].strength =
                 *(undefined1 *)((int)&peVar6[entityIndex].base.state + 1);
            Agnts[agnt].strengthMax = (char)peVar6[entityIndex].base.flags32;
            frameFlag = (*(uint *)((int)&peVar6[entityIndex].base.frames + 3) & 1) != 0;
            /* The sprite-stash pick is a chained far read in the original:
                 0229  les bx, ptr es:[bx + 0x1d]   ; Agnts[agnt].gdata
                 022E  add bx, ax                   ; + frameFlag * 0xc
                 0231  mov ax, word ptr es:[bx + 0xd]   ; sprs[k].seg
                 0235  mov dx, word ptr es:[bx + 0xb]   ; sprs[k].ofs
               with the byte offsets 3 / 7 / 0xb (and +0xc when frameFlag is set), i.e. the three
               entries gdata->sprs[frameFlag * 3 + band] for the level bands <4, 4..9, >=10.  The
               export copied `gdata` into a uint32_t, cast it to (int) and dereferenced DS-relative,
               which drops the segment - fatal, because AgntGs has its own. */
            if (peVar6[entityIndex].base.level < 10) {
              if (peVar6[entityIndex].base.level < 4) {
                Agnts[agnt].frames =
                     (far_t far *)Agnts[agnt].gdata->sprs[frameFlag * 3];
              }
              else {
                Agnts[agnt].frames =
                     (far_t far *)Agnts[agnt].gdata->sprs[frameFlag * 3 + 1];
              }
            }
            else {
              Agnts[agnt].frames =
                   (far_t far *)Agnts[agnt].gdata->sprs[frameFlag * 3 + 2];
            }
            Agnts[agnt].animFrame = 0xff;
            /* 0310  les bx, ptr es:[bx + 0x1d]  ; gdata, then `mov al, es:[bx]` = agntG_t.ai */
            Agnts[agnt].faction = Agnts[agnt].gdata->ai;
            /* 033B  les bx, ptr es:[bx + 0x13]  ; Agnts[agnt].frames, then es:[bx + 0x68]/[0x6a]
               and es:[bx + 0x58]/[0x5a] - frames[26] and frames[22] tested as null far_t pairs. */
            frameTab = Agnts[agnt].frames;
            if ((frameTab[26].ofs == 0 && frameTab[26].seg == 0) ||
               (frameTab[22].ofs == 0 && frameTab[22].seg == 0)) {
              if (frameTab[26].ofs == 0 && frameTab[26].seg == 0) {
                Agnts[agnt].animVariant = 0;
              }
              else {
                Agnts[agnt].animVariant = 1;
              }
            }
            else {
              animRand = ovr_randBelow(2,0);
              Agnts[agnt].animVariant = (char)animRand;
            }
            panVal = ovr_audio_panFromX((agnt_t far *)&Agnts[agnt].x,0);
            ovr_play_sfxU(0x1b,0,panVal,0,0);
          }
        }
      }
    }
  }
  return;
}



/* 4207:1aae */
void __cdecl16far ovc15_usesStExit(int entityIndex)

{
  uint8_t *animFramePtr;
  uint newIndex;
  entity_t *newEntity;
  int agntIdx;
  uint remaining;
  char toggle;
  
  if (EntityCount < 0x259) {
    if (EntityCount != 600) {
      _fmemmove((char far *)MK_FP(DAT_2000_d190,Entities + EntityCount),
             (char far *)MK_FP(DAT_2000_d190,Entities + entityIndex),0x37);
      (Entities)[EntityCount].base.animFrame =
           (uint8_t)((int)(uint)(Entities)[entityIndex].base.animFrame >> 1);
      animFramePtr = &(Entities)[entityIndex].base.animFrame;
      *animFramePtr = *animFramePtr - (Entities)[EntityCount].base.animFrame;
      newIndex = EntityCount;
      remaining = (uint)(Entities)[EntityCount].base.animFrame;
      EntityCount = EntityCount + 1;
      ovr_attact_usesGMapFlags3();
      if (AgntFlag1 != false) {
        toggle = '\0';
        agntIdx = 0;
        while ((agntIdx < (int)(uint)AgntCount && (remaining != 0))) {
          if (Agnts[agntIdx].owner == entityIndex) {
            if (toggle == '\0') {
              Agnts[agntIdx].owner = newIndex;
              newEntity = Entities + newIndex;
              AGNT_WORD(&Agnts[agntIdx], entity, 2) = DAT_2000_d190;
              AGNT_WORD(&Agnts[agntIdx], entity, 0) =(uint16_t)( newEntity);
              remaining = remaining - 1;
            }
            toggle = '\x01' - (toggle != '\0');
          }
          agntIdx = agntIdx + 1;
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

uint8_t * __cdecl16far ovc15_usesStshRealloc(char *text,uint16_t arg2,uint16_t arg3,uint16_t arg4,uint16_t arg5,uint16_t arg6,uint16_t arg7,uint16_t arg8)

{
  byte bVar1;
  size_t sVar2;
  byte *pbVar3;
  uint16_t in_DX;
  uint16_t in_stack_00000006;
  
  sVar2 = strlen((char *)CONCAT22(in_stack_00000006,text));
  pbVar3 = ovr_stshRealloc((uint32_t)upperTextOfs,(ulong)(sVar2 + 1));
  upperTextOfs = (byte *)CONCAT22(in_DX,pbVar3);
  strcpy((char *)CONCAT22(in_DX,pbVar3),(char *)CONCAT22(in_stack_00000006,text));
  bVar1 = toupper((int)(char)*upperTextOfs);
  *upperTextOfs = bVar1;
  pbVar3 = upperTextOfs;
  return pbVar3;
}



/* 4207:1c79 */

/* Copies a string and capitalises its first character. */

char * __cdecl16far ovc15_capitalize(char *text)

{
  char cVar1;
  uint16_t in_stack_00000006;
  char *in_stack_00000008;
  uint16_t in_stack_0000000a;
  
  strcpy((char *)CONCAT22(in_stack_00000006,text),
         (char *)CONCAT22(in_stack_0000000a,in_stack_00000008));
  cVar1 = toupper((int)*text);
  *text = cVar1;
  return text;
}



/* 4207:1cae */
void __cdecl16far stshStoreSprite(spr_t *spr,anm_t *anms,int16_t nanims)

{
  uint16_t frameWord3;
  uint16_t frameWord1;
  bool bVar3;
  uint16_t index;
  uint16_t o;
  int iVar4;
  uint16_t i;
  uint32_t cte;
  int in_stack_00000004;
  far_t pframe;
  
  i = 0;
  while( true ) {
    if ((*(uint16_t *)((uint8_t *)&(anms) + 2)) <= (int)i) break;
    index = (uint16_t)*(byte *)((*(uint16_t *)((uint8_t *)&(spr) + 2)) + i * 0x1e);
    o = in_stack_00000004 + index * 4;
    if (*(int *)(o + 0x58) != 0 || *(int *)(o + 0x5a) != 0) {
      iVar4 = in_stack_00000004 + index * 4;
      pframe.seg = *(uint16_t *)(iVar4 + 0x5a);
      pframe.ofs = *(uint16_t *)(iVar4 + 0x58);
      bVar3 = true;
      while( true ) {
        if (pframe.ofs == 0 && pframe.seg == 0) break;
        frameWord3 = *(uint16_t *)(pframe.ofs + 3);
        frameWord1 = *(uint16_t *)(pframe.ofs + 1);
        *(uint16_t *)(pframe.ofs + 3) = 0;
        *(uint16_t *)(pframe.ofs + 1) = 0;
        if (bVar3) {
          (*(uint16_t *)((uint8_t *)&(cte) + 2)) = frameWord1;
          (*(uint16_t *)((uint8_t *)&(cte))) = ovr_stshStoreFile((uint8_t *)pframe.ofs,pframe.seg);
          iVar4 = in_stack_00000004 + index * 4;
          *(uint16_t *)(iVar4 + 0x5a) = (*(uint16_t *)((uint8_t *)&(cte) + 2));
          *(uint16_t *)(iVar4 + 0x58) =(uint16_t)( (cte_t *)cte);
        }
        else {
          ovr_stshStoreFile((uint8_t *)pframe.ofs,pframe.seg);
        }
        bVar3 = false;
        pframe.seg = frameWord3;
        pframe.ofs = frameWord1;
      }
    }
    i = i + 1;
  }
  return;
}


/* 4207:1d87 */

/* [R4] calls ovr_stExit */

uint16_t __cdecl16far ovc15_usesStExit2(byte agntIndex)

{
  /* Re-derived: 1 when a whole horizontal run of the agent-index grid (AgntArrayA or B
     according to byte +0x11) belongs to this agent, 0 on the first foreign entry.  The
     export's iVar5 carries two roles (frame offset, then the column cursor) and iVar3's first
     assignment (framePtr[1]) is dead; the stale-AH success return is simply 1. */
  int *agntBase;
  uint16_t result;
  int frameOfs;
  int *framePtr;
  int colIdx;
  int colStart;
  int colEnd;
  int rowBand;
  int *agntRec;

  agntBase = (int *)&Agnts[agntIndex].x;
  agntRec = (int *)CONCAT22(SEG_OF(Agnts),agntBase);
  if ((((agntBase[1] < 0x14) || (*(char *)((int)agntBase + 0x25) == '\x01')) &&
      (*agntRec < 0xd3)) && (-1 < *agntRec)) {
    framePtr = (int *)(*(int *)((int)agntBase + 0x13) + (uint)*(byte *)(agntBase + 9) * 4);
    frameOfs = *framePtr;
    rowBand = agntBase[1] >> 1;
    if (rowBand < 0) {
      rowBand = 0;
    }
    if (8 < rowBand) {
      rowBand = 8;
    }
    colStart = *agntBase - *(int *)(frameOfs + 0x17) >> 1;
    colEnd = *agntBase + *(int *)(frameOfs + 0x17) >> 1;
    if (colStart < 0) {
      colStart = 0;
    }
    if (colEnd < 0) {
      colEnd = 0;
    }
    if (0x68 < colStart) {
      colStart = 0x68;
    }
    if (0x68 < colEnd) {
      colEnd = 0x68;
    }
    if (colEnd < colStart) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x25);
    }
    colIdx = colStart;
    if (*(char *)((int)agntBase + 0x11) == '\0') {
      for (; colIdx <= colEnd; colIdx = colIdx + 1) {
        if (agntIndex + 1 != (uint)AgntArrayA[rowBand][colIdx]) {
          return 0;
        }
      }
      for (; colStart <= colEnd; colStart = colStart + 1) {
        if (agntIndex + 1 != (uint)*(byte *)(rowBand * 0x69 + colStart + 0x963)) {
          return 0;
        }
      }
    }
    else {
      for (; colIdx <= colEnd; colIdx = colIdx + 1) {
        if (agntIndex + 1 != (uint)AgntArrayB[rowBand][colIdx]) {
          return 0;
        }
      }
      for (; colStart <= colEnd; colStart = colStart + 1) {
        if (agntIndex + 1 != (uint)*(byte *)(rowBand * 0x69 + colStart + 0x549)) {
          return 0;
        }
      }
    }
    result = 1;
  }
  else {
    result = 1;
  }
  return result;
}



/* 4207:1f5b */

/* [R7] body shape: compute */

uint16_t __cdecl16far ovc15_compute1(uint16_t *agnt)

{
  /* Re-derived: the sprite's y position relative to its screen column, offset by 0x93
     normally or 0xac when agnt[0x11] is set.  The exported
     CONCAT11((char)((uint)iVar5 >> 8), uStack_c) only reassembles iVar5 from its own bytes
     (uStack_c = (undefined1)iVar5), so it is returned directly; the reads assigned to
     iVar5 before the real computation (piVar2[1], piVar2[9]) are dead. */
  uint16_t agntSeg;
  int *frameOfs;
  int frameWord;
  int yValue;
  int clampedX;
  uint16_t *agntWord;
  int *frameBase;

  agntWord = (uint16_t *)agnt;
  agntSeg = *(uint16_t *)((int)agntWord + 0x15);
  frameOfs = (int *)*(int *)((int)agntWord + 0x13);
  frameBase = (int *)CONCAT22(agntSeg,frameOfs);
  if (*(char *)((int)agntWord + 0x11) == '\0') {
    frameWord = *frameBase;
    clampedX = ovr_agnt_clampX(*agnt);
    yValue = (*(int *)(frameWord + 0xd) - *(int *)(&columnScreenY[clampedX])) + 0x93;
  }
  else {
    frameWord = frameOfs[8];
    clampedX = ovr_agnt_clampX(*agnt);
    yValue = (*(int *)(frameWord + 0xd) - *(int *)(&columnScreenY[clampedX])) + 0xac;
  }
  return yValue;
}



/* 4207:1ffe */

/* [R4] calls ovr_randBelow */

int __cdecl16far ovc15_usesRandBelow(agnt_t far *agnt,int xSide,char keepPos,char randomY)

{
  char *pcVar1;
  far_t dst;
  uint16_t randY;
  uint16_t prevX;
  uint16_t randY2;
  uint computeRes;
  byte retHi;
  int xIndex;
  int exitRes;
  int agntLoop;
  agnt_t far *agnt_00;
  uint16_t agntSeg;
  uint16_t xOffsets [4];
  int dirSign;
  int agntIndex;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)xOffsets;
  F_SCOPY(far_from_u32((uint32_t)(0x24101d09)),dst,8);
  agnt_00 = (agnt_t far *)agnt;
  agntSeg = (uint16_t)((ulong)agnt >> 0x10);
  if (keepPos == '\0') {
    if (xSide < 0) {
      agnt->x = 0;
      randY = ovr_randBelow(0x14,0);
      agnt_00->y = randY & 0xff;
    }
    else if (xSide < 1) {
      xIndex = ((agnt_00->entity->base).x - GfxRndSeed) + 2;
      if (xIndex < 0) {
        xIndex = 0;
      }
      if (3 < xIndex) {
        xIndex = 3;
      }
      agnt->x = xOffsets[xIndex];
      if (randomY == '\0') {
        agnt_00->y = 0x20;
      }
      else {
        randY = ovr_randBelow(0x14,0);
        agnt_00->y = randY & 0xff;
      }
    }
    else {
      agnt->x = 0xd2;
      randY = ovr_randBelow(0x14,0);
      agnt_00->y = randY & 0xff;
    }
  }
  prevX = agnt->x;
  if ((int)prevX < 0x6a) {
    dirSign = 1;
  }
  else {
    dirSign = -1;
  }
  ovr_ovc49_body1(agnt_00,agntSeg);
  do {
    if (agnt_00->animVariant == 0x0) {
      computeRes = ovr_ovc49_compute1(agnt->x);
      retHi = (byte)(computeRes >> 8);
      if ((char)computeRes == '\0') goto L_OVC15_4207_1ffe_2193;
    }
    else {
L_OVC15_4207_1ffe_2193:
      exitRes = ovr_ovc49_usesStExit(agnt_00,agntSeg);
      retHi = (byte)((uint)exitRes >> 8);
      if ((char)exitRes == '\0') {
        if (agnt_00->y == 0x20) {
          computeRes = ovc15_compute1(&agnt->x);
          agnt_00->y = computeRes & 0xff;
        }
        agntIndex = 0;
        while ((agntIndex < (int)(uint)AgntCount && (Agnts[agntIndex].y < (int)agnt_00->y)
               )) {
          agntIndex = agntIndex + 1;
        }
        if (agntIndex < (int)(uint)AgntCount) {
          _fmemmove((char far *)MK_FP(SEG_OF(Agnts),(char *)&Agnts[agntIndex + 1].x),
                    (char far *)MK_FP(SEG_OF(Agnts),(char *)&Agnts[agntIndex].x),
                    ((uint)AgntCount - agntIndex) * 0x34);
        }
        agnt_00->visited = 0x1;
        _fmemmove((char far *)MK_FP(SEG_OF(Agnts),(char *)&Agnts[agntIndex].x),(char *)agnt,0x34);
        ovr_agnt_usesAgntCount5(agntIndex + 1);
        ovr_ovc49_fillGridCells((char)agntIndex + 1,(agnt_t far *)&Agnts[agntIndex].x,SEG_OF(Agnts),0);
        AgntCount = AgntCount + 1;
        for (agntLoop = 0; agntLoop < (int)(uint)AgntCount; agntLoop = agntLoop + 1) {
          if ((Agnts[agntLoop].target != -1) &&
             (agntIndex <= (int)(uint)Agnts[agntLoop].target)) {
            pcVar1 = (char *)&Agnts[agntLoop].target;
            *pcVar1 = *pcVar1 + '\x01';
          }
        }
        return 1;
      }
    }
    if (dirSign < 0) {
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
    if (agnt->x == prevX) {
      return (uint)retHi << 8;
    }
    if ((xSide == 0) && (randomY == '\0')) {
      agnt_00->y = 0x20;
    }
    else {
      randY2 = ovr_randBelow(0x14,0);
      agnt_00->y = randY2 & 0xff;
    }
    ovr_ovc49_body1(agnt_00,agntSeg);
  } while( true );
}



/* 4207:2301 */
char * __cdecl16far ovc15_textArena(int owner,uint16_t arg2,uint16_t arg3)

{
  bool bVar1;
  uint uVar2;
  uint16_t randPick;
  char *pcVar4;
  entity_t *peVar5;
  agntG_t far *paVar6;
  far_t far *pfVar7;
  uint16_t uVar8;
  uint16_t uVar9;
  int in_stack_00000006;
  char in_stack_00000008;
  agnt_t agntCopy;
  uint uStack_8;
  
  uVar9 = DAT_2000_d190;
  if (AgntFlag1) {
    for (uStack_8 = 0; (int)uStack_8 < (int)(uint)AgntCount; uStack_8 = uStack_8 + 1) {
      if (((Agnts[uStack_8].visited == '\0') &&
          (Agnts[uStack_8].owner == owner)) &&
         ((Agnts[uStack_8].flags & 0xae4) == 0)) {
        Agnts[uStack_8].visited = 1;
        if ((Agnts[uStack_8].animVariant != '\0') ||
           (uVar2 = ovr_ovc49_compute1(Agnts[uStack_8].x), (char)uVar2 == '\0')) {
          uVar2 = ovc15_usesStExit2((byte)uStack_8);
          if ((uVar2 & 0xff) != 0) {
            return (char *)((int)(uint32_t *)&_DATA + 1);
          }
        }
        _fmemmove((char far *)MK_FP(_SS,&agntCopy),
                  (char far *)MK_FP(SEG_OF(Agnts),(char *)&Agnts[uStack_8].x),0x34);
        agntCopy.target = 0xff;
        ovr_ovc41_removeAgent(uStack_8,0,0);
        pcVar4 = (char *)ovc15_usesRandBelow((agnt_t far *)MK_FP(_SS,&agntCopy),
                                             in_stack_00000006,'\x01',in_stack_00000008);
        return pcVar4;
      }
    }
  }
  if (AgntCount < 0x18) {
    peVar5 = Entities + owner;
    _fmemset(MK_FP(_SS, &agntCopy), 0, 0x34);
    agntCopy.target = 0xff;
    (*(uint16_t *)((uint8_t *)&(agntCopy.entity) + 2)) = uVar9;
    agntCopy.owner = owner;
    agntCopy.gdata =
         (agntG_t far *)MK_FP(SEG_OF(AgntGs),(agntG_t *)
                         &AgntGs[(uint)(peVar5->base).gindex]);
    (*(uint16_t *)((uint8_t *)&(agntCopy.entity))) =(uint16_t)( peVar5);
    bVar1 = ovc15_usesAlignUp42();
    if (!bVar1) {
      *(undefined1 *)((int)&(peVar5->base).state + 1) = (char)(peVar5->base).flags32;
    }
    agntCopy.strengthMax = (uint8_t)(peVar5->base).flags32;
    agntCopy.strength = *(uint8_t *)((int)&(peVar5->base).state + 1);
    bVar1 = (*(uint *)((int)&(peVar5->base).frames + 3) & 1) != 0;
    paVar6 = (agntG_t far *)agntCopy.gdata;
    uVar8 = (uint16_t)((ulong)agntCopy.gdata >> 0x10);
    if ((peVar5->base).level < 10) {
      if ((peVar5->base).level < 4) {
        agntCopy.frames =
             (far_t far *)CONCAT22(*(uint16_t *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 2),
                               *(far_t far **)(paVar6->sprs + (uint)bVar1 * 3));
      }
      else {
        agntCopy.frames =
             (far_t far *)CONCAT22(*(uint16_t *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 6),
                               *(far_t far **)(paVar6->sprs + (uint)bVar1 * 3 + 1));
      }
    }
    else {
      agntCopy.frames =
           (far_t far *)CONCAT22(*(uint16_t *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 10),
                             *(far_t far **)(paVar6->sprs + (uint)bVar1 * 3 + 2));
    }
    agntCopy.animFrame = 0xff;
    agntCopy.faction = (agntCopy.gdata)->ai;
    uVar9 = (uint16_t)((ulong)agntCopy.frames >> 0x10);
    pfVar7 = (far_t far *)agntCopy.frames;
    if (((pfVar7 + 0x1a)->ofs == 0 && pfVar7[0x1a].seg == 0) ||
       ((pfVar7 + 0x16)->ofs == 0 && pfVar7[0x16].seg == 0)) {
      if ((pfVar7 + 0x1a)->ofs != 0 || pfVar7[0x1a].seg != 0) {
        agntCopy.animVariant = 0x1;
      }
    }
    else {
      randPick = ovr_randBelow(2,0);
      agntCopy.animVariant = (uint8_t)randPick;
    }
    randPick = ovr_randBelow(2,0);
    (*(uint8_t *)((uint8_t *)&(agntCopy.targetX))) = (char)randPick * '\x02' + -1;
    if ((char)agntCopy.targetX < '\x01') {
      if ((char)agntCopy.targetX < '\0') {
        agntCopy.level = 0x1;
      }
      else {
        randPick = ovr_randBelow(2,0);
        agntCopy.level = (uint8_t)randPick;
      }
    }
    else {
      agntCopy.level = 0x0;
    }
    pcVar4 = (char *)ovc15_usesRandBelow((agnt_t far *)MK_FP(_SS,&agntCopy),in_stack_00000006,
                                         '\0',in_stack_00000008);
  }
  else {
    pcVar4 = (char *)0x2400;
  }
  return pcVar4;
}


/* 4207:25dd */

/* View height for an agent: one of six width/height pairs chosen by the class's animation-set
   selector, plus a die roll and an ability modifier unless the agent is above level 9.
   Re-derived from the image; the former body belonged to another function. */

uint8_t __cdecl16far ovc15_textView(agnt_t far *agnt)

{
  uint8_t sel;
  uint8_t w;
  uint8_t h;
  uint16_t height;

  sel = AgntGs[(uint)agnt->gindex].shortName[3];
  if (sel == 0xff) {
    sel = 0;
  }
  switch ((uint16_t)(sel - 1)) {
  case 0:
    w = 4;
    h = 1;
    break;
  case 1:
    w = 6;
    h = 1;
    break;
  case 2:
    w = 4;
    h = 2;
    break;
  case 3:
    w = 8;
    h = 3;
    break;
  case 4:
    w = 6;
    h = 1;
    break;
  case 5:
    w = 6;
    h = 1;
    break;
  default:
    w = 8;
    h = 2;
    break;
  }
  if (agnt->level > 9) {
    height = h;
  }
  else {
    height = (uint16_t)((ovr_manage_rollDice(1,w) & 0xff) +
                        (int16_t)ovr_agnt_abilityModifier
                                   (*(uint8_t far *)((uint8_t far *)agnt + 0x1a),4));
  }
  if ((int)height < 1) {
    height = 1;
  }
  return (uint8_t)height;
}


/* 4207:26bc */
long __cdecl16far ovc15_textError(agnt_t far *agnt,long value)

{
  /* Re-derived from 4207:26bc (449 bytes; retf at 0x287c, 7-entry jump table at 0x287d).
     Scores the agent 0/5/0xa from its leader sheet's ability bytes and scales `value` by
     (score+100)/100 - the original's lcall 0:0x938 (long multiply) then 0:0x9c4 (long divide).
     The selector is agnt->gdata + 0x46 with 0xff normalised to 0; the sheet is
     GLeaderSheets[agnt->entity[3]]. */
  char_sheet_t far *sheet;
  byte selector;
  int score;

  sheet = GLeaderSheets[AGNT_FIELD(agnt, entity, 3)];
  selector = *(byte *)((int)agnt->gdata + 0x46);
  if (selector == 0xff) {
    selector = 0;
  }
  score = 0;
  switch(selector) {
  case 0:
  case 4:
    if (*(byte *)((uint8_t *)sheet + 0x29) >= 0x10) {
      score = 0xa;
    }
    else if (*(byte *)((uint8_t *)sheet + 0x29) >= 0xd) {
      score = 5;
    }
    break;
  case 1:
    if (*(byte *)((uint8_t *)sheet + 0x2a) >= 0x10) {
      score = 0xa;
    }
    else if (*(byte *)((uint8_t *)sheet + 0x2a) >= 0xd) {
      score = 5;
    }
    break;
  case 2:
    if (*(byte *)((uint8_t *)sheet + 0x2b) >= 0x10) {
      score = 0xa;
    }
    else if (*(byte *)((uint8_t *)sheet + 0x2b) >= 0xd) {
      score = 5;
    }
    break;
  case 3:
    if (*(byte *)((uint8_t *)sheet + 0x2c) >= 0x10) {
      score = 0xa;
    }
    else if (*(byte *)((uint8_t *)sheet + 0x2c) >= 0xd) {
      score = 5;
    }
    break;
  case 5:
    if ((*(byte *)((uint8_t *)sheet + 0x29) >= 0xd) && (*(byte *)((uint8_t *)sheet + 0x2a) >= 0x10)) {
      score = 0xa;
    }
    else if ((*(byte *)((uint8_t *)sheet + 0x29) >= 0xd) && (*(byte *)((uint8_t *)sheet + 0x2a) >= 0xd)) {
      score = 5;
    }
    break;
  case 6:
    if ((*(byte *)((uint8_t *)sheet + 0x29) >= 0xd) && (*(byte *)((uint8_t *)sheet + 0x2c) >= 0xd)) {
      score = 0xa;
    }
    else if ((*(byte *)((uint8_t *)sheet + 0x29) >= 0xd) || (*(byte *)((uint8_t *)sheet + 0x2c) >= 0xd)) {
      score = 5;
    }
    break;
  }
  if (value != 0) {
    value = ((long)(score + 100) * value) / 100;
  }
  return value;
}


/* 4207:288b */

/* [R4] calls ovr_alignUp4 */

bool __cdecl16far ovc15_usesAlignUp42(void)

{
  uint uVar1;
  uint uVar2;
  byte bStack_3;
  
  uVar2 = 0;
  uVar1 = ovr_alignUp4(GfxRndSeed,0,0);
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
    CrossBlitX = Agnts[SelectedAgent].screenX;
    CrossBlitY = Agnts[SelectedAgent].screenY + -0x10;
  }
  return;
}



/* 4207:2961 */

/* Selects the agent with the smallest screen position and stores it in SelectedAgent. */

bool __cdecl16far ovc15_selectLeftmostAgent(void)

{
  /* Re-derived: the mirror of ovc15_selectRightmostAgent - smallest screenX, screenY
     breaking ties, starting from 0x7fff.  bestIdx is a char so -1 can mean "none". */
  int i;
  uint bestX;
  uint bestY;
  char bestIdx;

  bestIdx = -1;
  bestX = 0x7fff;
  bestY = 0x7fff;
  for (i = 0; i < (int)(uint)AgntCount; i = i + 1) {
    if ((Agnts[i].screenX < bestX) ||
       ((Agnts[i].screenX == bestX && (Agnts[i].screenY < bestY)))) {
      bestIdx = (char)i;
      bestX = Agnts[i].screenX;
      bestY = Agnts[i].screenY;
    }
  }
  if (bestIdx != -1) {
    SelectedAgent = bestIdx;
  }
  return bestIdx != -1;
}



/* 4207:2a0e */

/* Selects the agent with the largest screen position and stores it in SelectedAgent. */

bool __cdecl16far ovc15_selectRightmostAgent(void)

{
  /* Re-derived: the agent with the greatest screenX, screenY breaking ties; the index
     is stored into SelectedAgent and reported.  bestIdx is a char so -1 can mean
     "none". */
  int i;
  uint bestX;
  uint bestY;
  char bestIdx;

  bestIdx = -1;
  bestX = 0;
  bestY = 0;
  for (i = 0; i < (int)(uint)AgntCount; i = i + 1) {
    if ((bestX < Agnts[i].screenX) ||
       ((Agnts[i].screenX == bestX && (bestY < Agnts[i].screenY)))) {
      bestIdx = (char)i;
      bestX = Agnts[i].screenX;
      bestY = Agnts[i].screenY;
    }
  }
  if (bestIdx != -1) {
    SelectedAgent = bestIdx;
  }
  return bestIdx != -1;
}



/* 4207:2ab9 */

/* [R2] string "arena" */

bool __cdecl16far ovc15_textArena4(void)

{
  uint agentIdx;
  uint bestX;
  uint bestY;
  byte bestAgent;
  
  bestAgent = 0xff;
  bestX = 0x7fff;
  bestY = 0x7fff;
  for (agentIdx = 0; (int)agentIdx < (int)(uint)AgntCount; agentIdx = agentIdx + 1) {
    if (((SelectedAgent != agentIdx) &&
        ((Agnts[SelectedAgent].screenX < Agnts[agentIdx].screenX ||
         ((Agnts[SelectedAgent].screenX == Agnts[agentIdx].screenX &&
          (Agnts[SelectedAgent].screenY < Agnts[agentIdx].screenY)))))) &&
       ((Agnts[agentIdx].screenX < bestX ||
        ((Agnts[agentIdx].screenX == bestX && (Agnts[agentIdx].screenY < bestY)))))) {
      bestAgent = (byte)agentIdx;
      bestX = Agnts[agentIdx].screenX;
      bestY = Agnts[agentIdx].screenY;
    }
  }
  if (bestAgent != 0xff) {
    SelectedAgent = bestAgent;
  }
  return bestAgent != 0xff;
}



/* 4207:2c18 */

/* [R2] string "arena" */

bool __cdecl16far ovc15_textArena5(void)

{
  uint agentIdx;
  uint bestX;
  uint bestY;
  byte bestAgent;
  
  bestAgent = 0xff;
  bestX = 0;
  bestY = 0;
  for (agentIdx = 0; (int)agentIdx < (int)(uint)AgntCount; agentIdx = agentIdx + 1) {
    if (((SelectedAgent != agentIdx) &&
        ((Agnts[agentIdx].screenX < Agnts[SelectedAgent].screenX ||
         ((Agnts[SelectedAgent].screenX == Agnts[agentIdx].screenX &&
          (Agnts[agentIdx].screenY < Agnts[SelectedAgent].screenY)))))) &&
       ((bestX < Agnts[agentIdx].screenX ||
        ((Agnts[agentIdx].screenX == bestX && (bestY < Agnts[agentIdx].screenY)))))) {
      bestAgent = (byte)agentIdx;
      bestX = Agnts[agentIdx].screenX;
      bestY = Agnts[agentIdx].screenY;
    }
  }
  if (bestAgent != 0xff) {
    SelectedAgent = bestAgent;
  }
  return bestAgent != 0xff;
}



/* 4207:2d75 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc15_usesRandBelow2(void)

{
  /* Re-derived: pick a random entity belonging to the leader with the most units.  One
     pass over GLeaderCount tracks two candidates - the best leader whose sheet +0x3f is
     clear (own) and the best one where it is set.  If that candidate has more than 0xe
     units (0x1d for the own leader) a random start index is walked forward until an entity
     of that leader is found that is not under the cursor (and, for the own leader, whose
     flags32 high byte has bits 0-1 clear).  Falls back to a plain random index. */
  uint16_t randPick;
  uint cursorFree;
  uint entIdx;
  byte activeLeader;
  byte ownLeader;
  byte leaderIdx;
  uint bestActiveCount;
  uint bestOwnCount;

  bestOwnCount = 0;
  ownLeader = 0xff;
  bestActiveCount = 0;
  activeLeader = 0xff;
  for (leaderIdx = 0; leaderIdx < GLeaderCount; leaderIdx = leaderIdx + 1) {
    if ((*((char far *)GLeaderSheets[leaderIdx] + 0x3f) == '\0') &&
       (bestOwnCount < (GLeaderSheets[leaderIdx])->unitCount)) {
      ownLeader = leaderIdx;
      bestOwnCount = (GLeaderSheets[leaderIdx])->unitCount;
    }
    if ((*((char far *)GLeaderSheets[leaderIdx] + 0x3f) != '\0') &&
       (bestActiveCount < (GLeaderSheets[leaderIdx])->unitCount)) {
      activeLeader = leaderIdx;
      bestActiveCount = (GLeaderSheets[leaderIdx])->unitCount;
    }
  }
  if ((activeLeader != 0xff) && (0xe < bestActiveCount)) {
    randPick = ovr_randBelow(EntityCount,0);
    entIdx = randPick & 0xff;
    do {
      if ((AGNT_FIELD(&(Entities)[entIdx], base.entity, 3) == activeLeader) &&
         (cursorFree = ovr_ovc23_isCursorAt
                         (*(uint16_t *)((entity_t far *)Entities + entIdx),
                          ((entity_t far *)Entities)[entIdx].base.y),
          (cursorFree & 0xff) == 0)) {
        return entIdx;
      }
      entIdx = entIdx + 1;
      if (EntityCount <= entIdx) {
        entIdx = 0;
      }
    } while (entIdx != (randPick & 0xff));
  }
  if ((ownLeader != 0xff) && (0x1d < bestOwnCount)) {
    randPick = ovr_randBelow(EntityCount,0);
    entIdx = randPick & 0xff;
    do {
      if (((AGNT_FIELD(&(Entities)[entIdx], base.entity, 3) == ownLeader) &&
          (cursorFree = ovr_ovc23_isCursorAt
                          (*(uint16_t *)((entity_t far *)Entities + entIdx),
                           ((entity_t far *)Entities)[entIdx].base.y),
           (cursorFree & 0xff) == 0)) &&
         ((*((uint8_t far *)&(Entities)[entIdx].base.flags32 + 1) & 3) == 0)) {
        return entIdx;
      }
      entIdx = entIdx + 1;
      if (EntityCount <= entIdx) {
        entIdx = 0;
      }
    } while (entIdx != (randPick & 0xff));
  }
  randPick = ovr_randBelow(EntityCount,0);
  return randPick & 0xff;
}


