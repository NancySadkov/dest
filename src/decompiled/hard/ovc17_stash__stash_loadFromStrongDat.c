undefined1 * __cdecl16far stash_loadFromStrongDat(far_t entry,...)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  far_t *pfVar4;
  far_t *pfVar5;
  uint16_t in_DX;
  uint16_t uVar6;
  uint16_t uVar7;
  undefined1 in_stack_0000fff0;
  undefined1 in_stack_0000fff1;
  
  entry.ofs = (uint16_t)ovr_mkp((uint32_t *)entry.ofs,entry.seg);
  entry.seg = in_DX;
  pfVar4 = (far_t *)entry.ofs;
  if (*(char *)MK_FP(entry.seg, entry.ofs) == '\0') {
    uVar6 = in_DX;
    pfVar4 = fmMalloc((far_t *)*(undefined2 *)((int)&((far_t *)(entry.ofs + 4))->ofs + 1),
                      CONCAT13(in_stack_0000fff1,
                               CONCAT12(in_stack_0000fff0,
                                        *(undefined2 *)((int)&((far_t *)(entry.ofs + 4))->seg + 1)))
                     );
    if (pfVar4 == (far_t *)0x0 && uVar6 == 0) {
      pfVar4 = (far_t *)0x0;
    }
    else {
      if (*(int *)((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1) == 0 &&
          *(int *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1) == 0) {
        uVar7 = uVar6;
        stshSeek(StshStrongDatHnd,
                 CONCAT22(*(undefined2 *)((int)&((far_t *)entry.ofs)->seg + 1),
                          *(undefined2 *)((int)&((far_t *)entry.ofs)->ofs + 1)));
        stshRead();
        pfVar5 = ovr_heapMalloc((far_t *)*(undefined2 *)((int)&((far_t *)(entry.ofs + 4))->ofs + 1),
                                CONCAT13(in_stack_0000fff1,
                                         CONCAT12(in_stack_0000fff0,
                                                  *(undefined2 *)
                                                   ((int)&((far_t *)(entry.ofs + 4))->seg + 1))));
        *(uint16_t *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1) = uVar7;
        *(undefined2 *)((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1) =(uint16_t) pfVar5;
        if (*(int *)((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1) == 0 &&
            *(int *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1) == 0) {
          bVar3 = false;
        }
        else {
          memcpy((char *)CONCAT22(*(undefined2 *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1),
                                  (char *)*(undefined2 *)
                                           ((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1)),
                 (char *)CONCAT22(uVar6,pfVar4),*(word *)((int)&((far_t *)(entry.ofs + 4))->ofs + 1)
                );
          bVar3 = true;
        }
      }
      else {
        memcpy((char *)CONCAT22(uVar6,pfVar4),
               (char *)CONCAT22(*(undefined2 *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1),
                                (char *)*(undefined2 *)
                                         ((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1)),
               *(word *)((int)&((far_t *)(entry.ofs + 4))->ofs + 1));
        bVar3 = true;
        uVar7 = uVar6;
      }
      if (bVar3) {
        pfVar5 = (far_t *)ovr_mkp((uint32_t *)Stsh_2410_47f6.ofs,Stsh_2410_47f6.seg);
        if ((uVar7 != in_DX) || (pfVar5 != (far_t *)entry.ofs)) {
          iVar1 = *(int *)((int)&((far_t *)(entry.ofs + 0xc))->seg + 1);
          iVar2 = *(int *)((int)&((far_t *)(entry.ofs + 0xc))->ofs + 1);
          uVar6 = *(uint16_t *)((int)&((far_t *)(entry.ofs + 8))->seg + 1);
          uVar7 = *(uint16_t *)((int)&((far_t *)(entry.ofs + 8))->ofs + 1);
          if (uVar7 != 0 || uVar6 != 0) {
            *(int *)(uVar7 + 0xf) = iVar1;
            *(int *)(uVar7 + 0xd) = iVar2;
          }
          if (iVar2 != 0 || iVar1 != 0) {
            *(uint16_t *)(iVar2 + 0xb) = uVar6;
            *(uint16_t *)(iVar2 + 9) = uVar7;
            uVar7 = StshCtPtr2.ofs;
            uVar6 = StshCtPtr2.seg;
          }
          StshCtPtr2.seg = uVar6;
          StshCtPtr2.ofs = uVar7;
          uVar6 = Stsh_2410_47f6.ofs;
          *(uint16_t *)((int)&((far_t *)(entry.ofs + 0xc))->seg + 1) = Stsh_2410_47f6.seg;
          *(uint16_t *)((int)&((far_t *)(entry.ofs + 0xc))->ofs + 1) = uVar6;
          *(undefined2 *)((int)&((far_t *)(entry.ofs + 8))->seg + 1) = 0;
          *(undefined2 *)((int)&((far_t *)(entry.ofs + 8))->ofs + 1) = 0;
          *(uint16_t far *)((uint8_t far *)MK_FP(Stsh_2410_47f6.seg, Stsh_2410_47f6.ofs) +  0xb) = in_DX;
          *(undefined2 far *)((uint8_t far *)MK_FP(Stsh_2410_47f6.seg, Stsh_2410_47f6.ofs) +  9) = entry.ofs;
          Stsh_2410_47f6.seg = in_DX;
          Stsh_2410_47f6.ofs = entry.ofs;
        }
      }
    }
  }
  return (undefined1 *)pfVar4;
}
