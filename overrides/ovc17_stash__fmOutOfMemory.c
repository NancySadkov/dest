/* fmOutOfMemory - first asks the audio layer to free something
   (ovr_fmFreeAudio(0)), computes the block count needed from
   (nbytes + 0x13) >> 4 plus HeapPtr, then walks the StshCtPtr2 list:
   too-small blocks are freed, otherwise the smallest suitable node is
   remembered (bestOfs/bestSegLo/bestSegHi, bestSize).  Locals named from
   those assignments; register-only values keep their decompiler forms. */
uint16_t __cdecl16far fmOutOfMemory(uint32_t nbytes)

{
  uint16_t *nextSegPtr;
  bool freed;
  undefined1 extraout_AH;
  long *plVar3;
  uint uVar4;
  undefined1 uVar5;
  byte extraout_AH_00;
  int iVar6;
  uint16_t unaff_SI;
  uint uVar7;
  long *unaff_DI;
  uint uVar8;
  uint16_t uVar9;
  far_t block;
  far_t bestBlock;
  uint16_t bestOfs;
  uint8_t bestSegLo;
  undefined1 bestSegHi;
  uint bestSize;
  uint16_t nodeOfs;
  uint16_t nodeSeg;
  
  freed = ovr_fmFreeAudio(0);
  uVar5 = extraout_AH;
  if (!freed) {
    iVar6 = (*(uint16_t *)((uint8_t *)&(nbytes) + 2)) + (uint)(0xffec < (uint)nbytes);
    plVar3 = LXRSH_at_(unaff_DI,CONCAT22(bestOfs,unaff_SI),bestSegLo);
    uVar4 = (int)plVar3 + HeapPtr;
    iVar6 = iVar6 + (uint)CARRY2((uint)plVar3,HeapPtr);
    uVar8 = uVar4;
    if (iVar6 != 0) {
      uVar8 = 0xffff;
    }
    if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar6 != 0 || (MUSHandle.seg < uVar4)))) ||
       ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 && ((iVar6 != 0 || (MUSHandle.seg < uVar4)))))) {
      ovr_fmFreeAudio(1);
    }
    bestSize = 0xffff;
    HeapPtr = 0xffff;
    freed = false;
    nodeSeg = StshCtPtr2.seg;
    nodeOfs = StshCtPtr2.ofs;
    uVar4 = 0xffff;
    while (nodeOfs != 0 || nodeSeg != 0) {
      uVar7 = uVar4;
      if (*(int *)(nodeOfs + 0x11) != 0 || *(int *)(nodeOfs + 0x13) != 0) {
        if (*(uint *)(nodeOfs + 0x13) < uVar8) {
          block.seg = *(uint16_t *)(nodeOfs + 0x13);
          block.ofs = *(uint16_t *)(nodeOfs + 0x11);
          stshFree(block);
          *(uint16_t *)(nodeOfs + 0x13) = 0;
          *(uint16_t *)(nodeOfs + 0x11) = 0;
          freed = true;
        }
        else {
          if (*(uint *)(nodeOfs + 0x13) < uVar4) {
            uVar7 = *(uint *)(nodeOfs + 0x13);
            bestSegLo = (uint8_t)nodeSeg;
            bestSegHi = (undefined1)(nodeSeg >> 8);
            bestOfs = nodeOfs;
            bestSize = uVar4;
          }
          if (*(uint *)(nodeOfs + 0x13) < HeapPtr) {
            HeapPtr = *(uint *)(nodeOfs + 0x13);
          }
        }
      }
      nextSegPtr = (uint16_t *)(nodeOfs + 0xb);
      nodeOfs = *(uint16_t *)(nodeOfs + 9);
      uVar4 = uVar7;
      nodeSeg = *nextSegPtr;
    }
    uVar5 = 0;
    if (!freed) {
      if (uVar4 == 0xffff) {
        freed = ovr_fmFreeAudio(1);
        if (freed) {
          return CONCAT11(extraout_AH_00,1);
        }
        if (audioBusy == '\0') {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x14);
        }
        return (uint)extraout_AH_00 << 8;
      }
      uVar9 = (uint16_t)(CONCAT13(bestSegHi,CONCAT12(bestSegLo,bestOfs)) >> 0x10)
      ;
      bestBlock.seg = *(uint16_t *)(bestOfs + 0x13);
      bestBlock.ofs = *(uint16_t *)(bestOfs + 0x11);
      stshFree(bestBlock);
      uVar9 = (uint16_t)(CONCAT13(bestSegHi,CONCAT12(bestSegLo,bestOfs)) >> 0x10)
      ;
      *(uint16_t *)(bestOfs + 0x13) = 0;
      *(uint16_t *)(bestOfs + 0x11) = 0;
      uVar5 = 0x24;
      HeapPtr = bestSize;
    }
  }
  return CONCAT11(uVar5,1);
}
