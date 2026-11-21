far_t * __cdecl16far _realloc(undefined2 param_1,uint16_t param_2,far_t *param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  far_t *pfVar3;
  uint unaff_DI;
  far_t *pfVar4;
  far_t fVar5;
  
  __farmalloc_data_seg = 0x2410;
  malloc_save_hi = 0;
  malloc_save_lo = (uint16_t)param_3;   /* hand fix: 2-byte slot */
  if (param_2 == 0) {
    pfVar3 = farmalloc(param_3,(ulong)unaff_DI << 0x10);
  }
  else if (param_3 == (far_t *)0x0) {
    farfree(0,param_2);
    pfVar3 = (far_t *)0x0;
  }
  else {
    puVar1 = (undefined1 *)((int)&param_3[4].seg + 1);
    uVar2 = CONCAT11((byte)((uint)puVar1 >> 0xc) | ((far_t *)init_textFilename < param_3) << 4,
                     (char)((uint)puVar1 >> 4));
    if (*(uint *)0x0 < uVar2) {
      fVar5 = malloc_ExpandBlock();
      pfVar3 = (far_t *)fVar5.ofs;
    }
    else if (*(uint *)0x0 == uVar2) {
      pfVar3 = (far_t *)__C0_ASM_CopyRight;
    }
    else {
      pfVar4 = (far_t *)malloc_ShrinkBlock();
      pfVar3 = (far_t *)pfVar4;
    }
  }
  return pfVar3;
}
