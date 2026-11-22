stshSprite(far_t *__return_storage_ptr__,int16_t file_id,anm_t *anms,uint16_t nanims,bool grab)

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
    (*(uint16_t *)((uint8_t *)&(fVar6))) = ovr_grabLbm((int16_t)__return_storage_ptr__,0,0);
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
