char * __cdecl16far ovc42_textProvidesMoreHousing(uint32_t timeoutTicks)

{
  undefined2 uVar1;
  ulong *__return_storage_ptr__;
  uint16_t uVar2;
  uint uVar3;
  ulong *puVar4;
  ulong *puVar5;
  uint unaff_SI;
  undefined2 uVar6;
  ulong prevTick;
  
  prevTick = (ulong)unaff_SI << 0x10;
  uVar1 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  __return_storage_ptr__ = *(ulong **)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
  MiceNeedsUpdate = 1;
  puVar5 = __return_storage_ptr__;
  do {
    uVar6 = (undefined2)(prevTick >> 0x10);
    uVar2 = ovr_biosKeyAvail();
    if ((char)uVar2 != '\0') {
      uVar2 = ovr_gameProcessKey();
      if (uVar2 == 0x11b) {
        return (char *)((int)&GUnitDescriptions[5].seg + 1);
      }
      if (uVar2 == 0x1c0d) {
        return (char *)"%s: provides more housing." + 0x17;
      }
    }
    uVar3 = ovr_init2_updateMouseButtons();
    if ((uVar3 != 0) || (rightButtonLatch != '\0')) {
      if (rightButtonLatch != '\0') {
        return (char *)"woodcarver";
      }
      return (char *)"arena" + 5;
    }
    prevTick = CONCAT22(uVar6,uVar1);
    puVar4 = ovr_attact_usesBDADailyTimeCounter(__return_storage_ptr__,prevTick);
  } while ((puVar5 < (*(uint16_t *)((uint8_t *)&(timeoutTicks) + 2))) ||
          ((puVar5 == (*(uint16_t *)((uint8_t *)&(timeoutTicks) + 2)) && (puVar4 < (ulong *)timeoutTicks))));
  return (char *)((uint)puVar4 & 0xff00);
}
