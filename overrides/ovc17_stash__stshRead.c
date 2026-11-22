/* stshRead - reads a chunk of the stash file into the game's buffer, doing
   the 32-bit offset/length arithmetic over StshPtrs/StshSizes and routing
   through FMXMSHandle/LXURSH_at_.  Stack locals named from those
   assignments: srcPtr, chunkLo/chunkHi, leftLo/leftHi.  The function's own
   arguments still arrive via in_stack_0000000x because the exported
   prototype is void - a separate fix. */
uint __cdecl16far stshRead(void)

{
  uint *puVar1;
  int *piVar2;
  int fd;
  uint uVar3;
  uint16_t srcEmsOfsHi;
  uint32_t *puVar4;
  uint uVar5;
  uint16_t rdsz;
  uint16_t readed;
  uint uVar6;
  uint16_t seg;
  uint16_t unaff_SI;
  uint32_t *unaff_DI;
  bool bVar7;
  int in_stack_00000004;
  uint32_t *in_stack_00000006;
  uint32_t *in_stack_00000008;
  uint in_stack_0000000a;
  uint in_stack_0000000c;
  uint srcHi;
  uint countLo;
  uint16_t uVar8;
  uint16_t lenHi;
  uint32_t srcPtr;
  uint16_t pbuf;
  uint8_t in_stack_0000ffec;
  uint leftLo;
  uint leftHi;
  uint chunkLo;
  uint16_t chunkHi;
  uint32_t snbytes;
  
  uVar3 = in_stack_0000000a;
  srcPtr = CONCAT22(pbuf,unaff_SI);
  uVar5 = *(uint *)((int)(long *)StshPtrs + in_stack_00000004 * 4 + 2);
  uVar6 = *(uint *)((uint8_t *)&StshSizes[in_stack_00000004] + 2);
  if ((uVar5 < uVar6) ||
     ((uVar5 == uVar6 &&
      (*(uint *)((long *)StshPtrs + in_stack_00000004) < *(uint *)(&StshSizes[in_stack_00000004]))))
     ) {
    uVar6 = in_stack_0000000c + *(int *)((int)(long *)StshPtrs + in_stack_00000004 * 4 + 2) +
            (uint)CARRY2(in_stack_0000000a,*(uint *)((long *)StshPtrs + in_stack_00000004));
    uVar5 = *(uint *)((uint8_t *)&StshSizes[in_stack_00000004] + 2);
    if ((uVar5 <= uVar6) &&
       ((uVar5 < uVar6 ||
        (*(uint *)(&StshSizes[in_stack_00000004]) <
         in_stack_0000000a + *(uint *)((long *)StshPtrs + in_stack_00000004))))) {
      uVar5 = *(uint *)(&StshSizes[in_stack_00000004]);
      puVar1 = (uint *)((int)&AgntAnms[0x53].y + 1 + in_stack_00000004 * 4);
      in_stack_0000000a = uVar5 - *puVar1;
      in_stack_0000000c =
           (*(int *)((uint8_t *)&StshSizes[in_stack_00000004] + 2) -
           *(int *)((int)&AgntAnms[0x53].maxDx + 1 + in_stack_00000004 * 4)) -
           (uint)(uVar5 < *puVar1);
    }
    leftHi = in_stack_0000000c;
    leftLo = in_stack_0000000a;
    if (in_stack_00000004 == 0) {
      if (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) <= (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) &&
         (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) < (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) || ((uint)StshPtrs[0] < (uint)FMXmsHandle)))) {
        uVar5 = ((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                (uint)((uint)FMXmsHandle < (uint)StshPtrs[0]);
        if ((uVar5 < in_stack_0000000c) ||
           ((uVar5 <= in_stack_0000000c &&
            ((uint)FMXmsHandle - (uint)StshPtrs[0] <= in_stack_0000000a)))) {
          chunkLo = (uint)FMXmsHandle - (uint)StshPtrs[0];
          uVar5 = ((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                  (uint)((uint)FMXmsHandle < (uint)StshPtrs[0]);
          chunkHi = uVar5;
        }
        else {
          chunkHi = in_stack_0000000c;
          chunkLo = in_stack_0000000a;
          uVar5 = in_stack_0000000a;
        }
        uVar6 = (uint)StshPtrs[0];
        srcHi = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2));
        countLo = chunkLo;
        uVar8 = chunkHi;
        puVar4 = ovr_mkp(in_stack_00000006,(uint16_t)in_stack_00000008,(uint)StshPtrs[0]);
        xms_usesXmsHandle((int)puVar4,uVar5,uVar6,srcHi,countLo,uVar8);
        bVar7 = CARRY2((uint)StshPtrs[0],chunkLo);
        (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + chunkLo;
        (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + chunkHi + (uint)bVar7;
        leftLo = in_stack_0000000a - chunkLo;
        leftHi = (in_stack_0000000c - chunkHi) - (uint)(in_stack_0000000a < chunkLo);
        puVar4 = LXURSH_at_(unaff_DI,srcPtr,in_stack_0000ffec);
        in_stack_00000008 = (uint32_t *)((int)puVar4 + (int)in_stack_00000008);
        in_stack_00000006 = (uint32_t *)((int)in_stack_00000006 + (chunkLo & 0xf));
      }
      if (leftLo != 0 || leftHi != 0) {
        uVar5 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle);
        if (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) <= uVar5) &&
           (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) < uVar5 ||
            ((uint)StshPtrs[0] < (uint)FMXmsHandle + (uint)FMEmsHandle)))) {
          uVar5 = (((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                   (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                  (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
          if ((uVar5 < leftHi) ||
             ((uVar5 <= leftHi &&
              (((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0] <= leftLo)))) {
            chunkLo = ((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0];
            chunkHi = (((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                        (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                       (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
          }
          else {
            chunkHi = leftHi;
            chunkLo = leftLo;
          }
          seg = (uint)StshPtrs[0] - (uint)FMXmsHandle;
          srcEmsOfsHi = ((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) -
                        (uint)((uint)StshPtrs[0] < (uint)FMXmsHandle);
          uVar8 = seg;
          uVar5 = chunkLo;
          lenHi = chunkHi;
          puVar4 = ovr_mkp(in_stack_00000006,(uint16_t)in_stack_00000008,seg);
          ems_memmove1((uint16_t)puVar4,seg,uVar8,srcEmsOfsHi,uVar5,lenHi);
          bVar7 = CARRY2((uint)StshPtrs[0],chunkLo);
          (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + chunkLo;
          (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + chunkHi + (uint)bVar7;
          bVar7 = leftLo < chunkLo;
          leftLo = leftLo - chunkLo;
          leftHi = (leftHi - chunkHi) - (uint)bVar7;
          puVar4 = LXURSH_at_(unaff_DI,srcPtr,in_stack_0000ffec);
          in_stack_00000008 = (uint32_t *)((int)puVar4 + (int)in_stack_00000008);
          in_stack_00000006 = (uint32_t *)((int)in_stack_00000006 + (chunkLo & 0xf));
        }
      }
      uVar5 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
              (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle);
      if ((uVar5 <= (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) &&
         ((uVar5 != (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) ||
          ((uint)FMXmsHandle + (uint)FMEmsHandle <= (uint)StshPtrs[0])))) {
        lseek(StshHandles[0],(ulong)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)),(int)unaff_DI);
      }
      if (leftLo == 0 && leftHi == 0) {
        return uVar3 - in_stack_0000000a;
      }
    }
    fd = *(int *)((char *)0x2420 + in_stack_00000004 * 2);
    pbuf = (uint16_t)in_stack_00000006;
    while( true ) {
      if ((leftHi == 0) && (leftLo == 0)) goto next_iteration;
      if ((leftHi != 0) || (rdsz = leftLo, 0xc000 < leftLo)) {
        rdsz = 0xc000;
      }
      readed = read(fd,(uint32_t *)CONCAT22(rdsz,in_stack_00000008),(uint)unaff_DI);
      if (readed != rdsz) break;
      bVar7 = leftLo < readed;
      leftLo = leftLo - readed;
      leftHi = leftHi - bVar7;
      pbuf = (uint16_t)
             ovr_mkp((uint32_t *)(pbuf + readed),(uint16_t)in_stack_00000008,(uint16_t)unaff_DI);
      puVar1 = (uint *)((int)&AgntAnms[0x53].y + 1 + in_stack_00000004 * 4);
      uVar5 = *puVar1;
      *puVar1 = *puVar1 + readed;
      piVar2 = (int *)((int)&AgntAnms[0x53].maxDx + 1 + in_stack_00000004 * 4);
      *piVar2 = *piVar2 + (uint)CARRY2(uVar5,readed);
      in_stack_00000008 = in_stack_00000006;
    }
    printf((char *)((long)&BldInstances[0x49].seg + 1));
    ovr_biosReadKey();
next_iteration:
    in_stack_0000000a = uVar3 - in_stack_0000000a;
  }
  return in_stack_0000000a;
}
