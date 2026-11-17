/* stshRead: read bytes from the stash file into a far buffer.
 * Recovered with the reset-vars workaround (Ghidra forced-merge bug).
 */
char __cdecl16far stshRead(uint16_t file_id, far_t buf, uint32_t nbytes)

{
  uint16_t nb_lo = (uint16_t)nbytes;
  uint16_t nb_hi = (uint16_t)(nbytes >> 16);

  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  uint32_t uVar10;
  void *pvVar11;
  uint uVar12;
  uint uVar13;
  void *pvStack_16;
  uint16_t uStack_14;
  uint uStack_10;
  uint uStack_e;
  uint uStack_c;
  uint uStack_a;
  
  uVar3 = nb_lo;
  uVar5 = *(uint *)((int)(long *)StshPtrs + file_id * 4 + 2);
  uVar7 = *(uint *)(file_id * 4 + 0xaa2);
  cVar6 = (char)nb_hi;
  if ((uVar5 < uVar7) ||
     ((uVar5 == uVar7 &&
      (*(uint *)((long *)StshPtrs + file_id) < *(uint *)(file_id * 4 + 0xaa0))))
     ) {
    uVar7 = nb_hi + *(int *)((int)(long *)StshPtrs + file_id * 4 + 2) +
            (uint)CARRY2(nb_lo,*(uint *)((long *)StshPtrs + file_id));
    uVar5 = *(uint *)(file_id * 4 + 0xaa2);
    if ((uVar5 <= uVar7) &&
       ((uVar5 < uVar7 ||
        (*(uint *)(file_id * 4 + 0xaa0) <
         nb_lo + *(uint *)((long *)StshPtrs + file_id))))) {
      uVar5 = *(uint *)(file_id * 4 + 0xaa0);
      puVar1 = (uint *)((int)&AgntAnms[0x53].y + 1 + file_id * 4);
      nb_lo = uVar5 - *puVar1;
      nb_hi =
           (*(int *)(file_id * 4 + 0xaa2) -
           *(int *)((int)&AgntAnms[0x53].field_0x10 + file_id * 4)) -
           (uint)(uVar5 < *puVar1);
    }
    uStack_e = nb_hi;
    uStack_10 = nb_lo;
    if (file_id == 0) {
      if ((StshPtrs[0]._2_2_ <= FMXmsHandle._2_2_) &&
         ((StshPtrs[0]._2_2_ < FMXmsHandle._2_2_ || ((uint)StshPtrs[0] < (uint)FMXmsHandle)))) {
        uVar5 = (FMXmsHandle._2_2_ - StshPtrs[0]._2_2_) -
                (uint)((uint)FMXmsHandle < (uint)StshPtrs[0]);
        if ((uVar5 < nb_hi) ||
           ((uVar5 <= nb_hi &&
            ((uint)FMXmsHandle - (uint)StshPtrs[0] <= nb_lo)))) {
          uStack_c = (uint)FMXmsHandle - (uint)StshPtrs[0];
          uStack_a = (FMXmsHandle._2_2_ - StshPtrs[0]._2_2_) -
                     (uint)((uint)FMXmsHandle < (uint)StshPtrs[0]);
        }
        else {
          uStack_a = nb_hi;
          uStack_c = nb_lo;
        }
        uVar5 = (uint)StshPtrs[0];
        uVar7 = StshPtrs[0]._2_2_;
        uVar12 = uStack_c;
        uVar13 = uStack_a;
        uVar10 = ovr_mkp((uint16_t)buf.ofs,buf.seg);
        xms_1000_032f(uVar10,uVar5,uVar7,uVar12,uVar13);
        bVar9 = CARRY2((uint)StshPtrs[0],uStack_c);
        StshPtrs[0]._0_2_ = (uint)StshPtrs[0] + uStack_c;
        StshPtrs[0]._2_2_ = StshPtrs[0]._2_2_ + uStack_a + (uint)bVar9;
        uStack_10 = nb_lo - uStack_c;
        uStack_e = (nb_hi - uStack_a) - (uint)(nb_lo < uStack_c);
        uVar10 = LXURSH_at_(CONCAT22(uStack_a,uStack_c),0x4);
        buf.seg = (int)uVar10 + buf.seg;
        buf.ofs = (void *)((int)buf.ofs + (uStack_c & 0xf));
      }
      if (uStack_10 != 0 || uStack_e != 0) {
        uVar5 = FMXmsHandle._2_2_ + FMEmsHandle._2_2_ +
                (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle);
        if ((StshPtrs[0]._2_2_ <= uVar5) &&
           ((StshPtrs[0]._2_2_ < uVar5 ||
            ((uint)StshPtrs[0] < (uint)FMXmsHandle + (uint)FMEmsHandle)))) {
          uVar5 = ((FMXmsHandle._2_2_ + FMEmsHandle._2_2_ +
                   (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - StshPtrs[0]._2_2_) -
                  (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
          if ((uVar5 < uStack_e) ||
             ((uVar5 <= uStack_e &&
              (((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0] <= uStack_10)))) {
            uStack_c = ((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0];
            uStack_a = ((FMXmsHandle._2_2_ + FMEmsHandle._2_2_ +
                        (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - StshPtrs[0]._2_2_) -
                       (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
          }
          else {
            uStack_a = uStack_e;
            uStack_c = uStack_10;
          }
          iVar8 = (uint)StshPtrs[0] - (uint)FMXmsHandle;
          iVar4 = (StshPtrs[0]._2_2_ - FMXmsHandle._2_2_) -
                  (uint)((uint)StshPtrs[0] < (uint)FMXmsHandle);
          uVar5 = uStack_c;
          uVar7 = uStack_a;
          uVar10 = ovr_mkp((uint16_t)buf.ofs,buf.seg);
          ems_memmove1(uVar10,iVar8,iVar4,uVar5,uVar7);
          bVar9 = CARRY2((uint)StshPtrs[0],uStack_c);
          StshPtrs[0]._0_2_ = (uint)StshPtrs[0] + uStack_c;
          StshPtrs[0]._2_2_ = StshPtrs[0]._2_2_ + uStack_a + (uint)bVar9;
          bVar9 = uStack_10 < uStack_c;
          uStack_10 = uStack_10 - uStack_c;
          uStack_e = (uStack_e - uStack_a) - (uint)bVar9;
          uVar10 = LXURSH_at_(CONCAT22(uStack_a,uStack_c),0x4);
          buf.seg = (int)uVar10 + buf.seg;
          buf.ofs = (void *)((int)buf.ofs + (uStack_c & 0xf));
        }
      }
      uVar5 = FMXmsHandle._2_2_ + FMEmsHandle._2_2_ +
              (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle);
      if ((uVar5 <= StshPtrs[0]._2_2_) &&
         ((uVar5 != StshPtrs[0]._2_2_ ||
          ((uint)FMXmsHandle + (uint)FMEmsHandle <= (uint)StshPtrs[0])))) {
        lseek(StshHandles[0],CONCAT22(StshPtrs[0]._2_2_,(uint)StshPtrs[0]),0);
      }
      if (uStack_10 == 0 && uStack_e == 0) {
        return (cVar6 - (char)nb_hi) - (uVar3 < nb_lo);
      }
    }
    iVar4 = *(int *)((char *)"toymaker" + 7 + file_id * 2);
    pvVar11 = (void *)CONCAT22(buf.seg,buf.ofs);
    while( true ) {
      uStack_14 = (uint16_t)((ulong)pvVar11 >> 0x10);
      pvStack_16 = (void *)pvVar11;
      if ((uStack_e == 0) && (uStack_10 == 0)) goto next_iteration;
      if ((uStack_e != 0) || (uVar5 = uStack_10, 0xc000 < uStack_10)) {
        uVar5 = 0xc000;
      }
      uVar7 = read(iVar4,pvStack_16,uVar5);
      if (uVar7 != uVar5) break;
      bVar9 = uStack_10 < uVar7;
      uStack_10 = uStack_10 - uVar7;
      uStack_e = uStack_e - bVar9;
      pvVar11 = (void *)ovr_mkp((int)pvStack_16 + uVar7,uStack_14);
      puVar1 = (uint *)((int)&AgntAnms[0x53].y + 1 + file_id * 4);
      uVar5 = *puVar1;
      *puVar1 = *puVar1 + uVar7;
      piVar2 = (int *)((int)&AgntAnms[0x53].field_0x10 + file_id * 4);
      *piVar2 = *piVar2 + (uint)CARRY2(uVar5,uVar7);
    }
    printf("File read error %s \r",*(undefined2 *)(file_id * 4));
    ovr_biosReadKey();
next_iteration:
    cVar6 = (cVar6 - (char)nb_hi) - (uVar3 < nb_lo);
  }
  return cVar6;
}


