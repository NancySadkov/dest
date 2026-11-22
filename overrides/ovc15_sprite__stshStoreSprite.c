void __cdecl16far stshStoreSprite(spr_t *spr,anm_t *anms,int16_t nanims)

{
  uint16_t uVar1;
  uint16_t uVar2;
  bool bVar3;
  uint16_t index;
  uint16_t pofs;
  uint16_t o;
  int iVar4;
  uint16_t i;
  uint16_t pseg;
  uint32_t cte;
  int in_stack_00000004;
  far_t pframe;
  uint8_t frmid;
  uint8_t first_frame;
  uint16_t next_ofs;
  uint16_t next_seg;
  
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
        uVar1 = *(uint16_t *)(pframe.ofs + 3);
        uVar2 = *(uint16_t *)(pframe.ofs + 1);
        *(uint16_t *)(pframe.ofs + 3) = 0;
        *(uint16_t *)(pframe.ofs + 1) = 0;
        if (bVar3) {
          (*(uint16_t *)((uint8_t *)&(cte) + 2)) = uVar2;
          (*(uint16_t *)((uint8_t *)&(cte))) = ovr_stshStoreFile((uint8_t *)pframe.ofs,pframe.seg);
          iVar4 = in_stack_00000004 + index * 4;
          *(uint16_t *)(iVar4 + 0x5a) = (*(uint16_t *)((uint8_t *)&(cte) + 2));
          *(uint16_t *)(iVar4 + 0x58) =(uint16_t)( (cte_t *)cte);
        }
        else {
          ovr_stshStoreFile((uint8_t *)pframe.ofs,pframe.seg);
        }
        bVar3 = false;
        pframe.seg = uVar1;
        pframe.ofs = uVar2;
      }
    }
    i = i + 1;
  }
  return;
}
