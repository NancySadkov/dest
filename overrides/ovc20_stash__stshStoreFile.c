cte_t * __cdecl16far stshStoreFile(uint8_t *data,...)

{
  far_t buf;
  uint16_t uVar1;
  uint16_t uVar2;
  cte_t *psVar4;
  undefined2 unaff_BP;
  bool bVar3;
  far_t fVar4;
  uint16_t in_stack_00000006;
  DW sz_00;
  far_t handle;
  DW DStack_c;
  DW sz;
  uint16_t uStack_6;
  undefined2 in_stack_0000fffc;
  uint16_t ofs_lo;
  uint16_t ofs;
  
  if (5 < *data) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x18);
  }
                    /* WARNING: Switch is manually overridden */
  switch((undefined4)*(undefined2 *)((uint)*data * 2 + 0xb69)) {
  case 0x4ba94:
    return (cte_t *)data;
  case 0x4ba9d:
    sz.lo = *(uint *)(data + 1) + 9;
    sz.hi = *(int *)(data + 3) + (uint)(0xfff6 < *(uint *)(data + 1));
    break;
  case 0x4bab6:
    sz.lo = *(uint *)(data + 6) + 0xe;
    sz.hi = *(int *)(data + 8) + (uint)(0xfff1 < *(uint *)(data + 6));
    break;
  case 0x4bacf:
    sz.lo = *(int *)(data + 5) + 0xd;
    sz.hi = 0;
    break;
  case 0x4bae3:
    sz.lo = *(uint *)(data + 0xc) + 0x14;
    sz.hi = *(int *)(data + 0xe) + (uint)(0xffeb < *(uint *)(data + 0xc));
  }
  uVar2 = sz.lo;
  if (StshCount < 0xd93) {
    StshCount = StshCount + 1;
    LXMUL_at_((long *)sz.lo,CONCAT22(uStack_6,sz.hi),CONCAT22(unaff_BP,in_stack_0000fffc));
    DStack_c.lo = 0x1000;
    fVar4.seg = uStack_6;
    fVar4.ofs = sz.hi;
    fVar4 = PADD_at_(far_from_u32(CONCAT22(DStack_c.hi, DStack_c.lo)),fVar4);
    ofs = fVar4.seg;
    psVar4 = (cte_t *)ovr_mkp((uint32_t *)fVar4.ofs,ofs,0x1000);
    (psVar4->sz).hi = sz.hi;
    (&psVar4->sz)->lo = uVar2;
    ((cte_t *)CONCAT22(ofs,psVar4))->state = 0x0;
    uVar1 = StshCtOfs.lo;
    (psVar4->ofs).hi = StshCtOfs.hi;
    (&psVar4->ofs)->lo = uVar1;
    (psVar4->info + 10)[0] = 0x0;
    (psVar4->info + 10)[1] = 0x0;
    (psVar4->info + 8)[0] = 0x0;
    (psVar4->info + 8)[1] = 0x0;
    bVar3 = CARRY2(StshCtOfs.lo,uVar2);
    StshCtOfs.lo = StshCtOfs.lo + uVar2;
    StshCtOfs.hi = StshCtOfs.hi + sz.hi + (uint)bVar3;
    (psVar4->info + 2)[0] = 0x0;
    (psVar4->info + 2)[1] = 0x0;
    psVar4->info[0] = 0x0;
    psVar4->info[1] = 0x0;
    (psVar4->info + 6)[0] = 0x0;
    (psVar4->info + 6)[1] = 0x0;
    (psVar4->info + 4)[0] = 0x0;
    (psVar4->info + 4)[1] = 0x0;
    if (DebugVerbose != false) {
      printf("type %d len %ld \r");
      ovr_biosReadKey();
    }
    sz_00.hi = sz.hi;
    sz_00.lo = uVar2;
    buf.seg = in_stack_00000006;
    buf.ofs = (uint16_t)data;
    stshWriteFile(StshFile,buf,sz_00);
    handle.seg = in_stack_00000006;
    handle.ofs = (uint16_t)data;
    ovr_stshFree(handle);
    return psVar4;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x24);
}
