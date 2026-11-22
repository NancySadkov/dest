far_t far * __cdecl16far
stshRleType2(far_t far *__return_storage_ptr__,far_t pixels,int16_t sx,int16_t sy,int16_t ex,int16_t ey,
            int16_t ox,int16_t oy,...)

{
  far_t far *pfVar1;
  undefined2 in_DX;
  far_t far *uStack_6;   /* hand fix: assigned a far_t pointer and used as uStack_6->ofs */
  
  pfVar1 = stshRleSub(__return_storage_ptr__,(uint8_t *)pixels.ofs,pixels.seg,sx,sy,ex,15);
  uStack_6 = (far_t far *)CONCAT22(in_DX,pfVar1);
  *(int16_t *)((int)&pfVar1->ofs + 1) = ey;
  *(int16_t *)((int)&pfVar1->seg + 1) = ox;
  *(undefined1 *)&uStack_6->ofs = 2;
  return pfVar1;
}
