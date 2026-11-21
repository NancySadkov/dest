int __cdecl16far _OvrInitExt(uint32_t startAddress,uint32_t length)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  uint sizeLo;
  int in_DX;
  uint sizeHi;
  
  uVar2 = (uint)startx;   /* hand fix: startx is a function */
  if ((*(byte *)&OvrFlags & 2) == 0) {
    bVar1 = false;
    iVar3 = __INITEXT();
    if (iVar3 == 0 && in_DX == 0) {
L__OvrInitExt_0AD7:
      iVar3 = -1;
    }
    else {
      while( true ) {
        if (((*(uint16_t *)((uint8_t *)&(startAddress) + 2)) < *(uint *)0x3c) ||
           (((*(uint16_t *)((uint8_t *)&(startAddress) + 2)) == *(uint *)0x3c &&
            ((uint)startAddress < *(uint *)&__ExtStartAddress)))) {
          (*(uint16_t *)((uint8_t *)&(startAddress) + 2)) = *(uint *)0x3c;
          (*(uint16_t *)((uint8_t *)&(startAddress))) = *(uint *)&__ExtStartAddress;
        }
        if ((*(uint *)0x40 < (*(uint16_t *)((uint8_t *)&(startAddress) + 2))) ||
           ((*(uint *)0x40 <= (*(uint16_t *)((uint8_t *)&(startAddress) + 2)) && (*(uint *)&__ExtEndAddress < (uint)startAddress)
            ))) goto L__OvrInitExt_0AD7;
        sizeLo = *(uint *)&__ExtEndAddress - (uint)startAddress;
        sizeHi = (*(int *)0x40 - (*(uint16_t *)((uint8_t *)&(startAddress) + 2))) -
                 (uint)(*(uint *)&__ExtEndAddress < (uint)startAddress);
        if (((uint)length != 0 || (*(uint16_t *)((uint8_t *)&(length) + 2)) != 0) &&
           (((*(uint16_t *)((uint8_t *)&(length) + 2)) <= sizeHi &&
            (((*(uint16_t *)((uint8_t *)&(length) + 2)) < sizeHi || (*(uint *)&__ExtEndAddress < sizeLo)))))) {
          sizeLo = (uint)length;
          sizeHi = (*(uint16_t *)((uint8_t *)&(length) + 2));
        }
        if ((*(uint *)((char *)"Your may continue playing, but your score will not be recorded." + 9
                      ) <= sizeHi) &&
           ((*(uint *)((char *)"Your may continue playing, but your score will not be recorded." + 9
                      ) < sizeHi ||
            (*(uint *)((char *)"Your may continue playing, but your score will not be recorded." + 7
                      ) < sizeLo)))) {
          sizeHi = *(uint *)((char *)
                             "Your may continue playing, but your score will not be recorded." + 9);
          sizeLo = *(uint *)((char *)
                             "Your may continue playing, but your score will not be recorded." + 7);
        }
        length = CONCAT22(sizeHi,sizeLo);
        if ((sizeHi == 0) && (sizeLo >> 4 < *(uint *)&__OvrMinHeapSize)) goto L__OvrInitExt_0AD7;
        *(uint *)&__EmsRec = (uint)startAddress;
        *(uint *)0x132 = (*(uint16_t *)((uint8_t *)&(startAddress) + 2));
        *(int *)0x134 = sizeLo + (uint)startAddress;
        *(int *)0x136 = sizeHi + (*(uint16_t *)((uint8_t *)&(startAddress) + 2)) + (uint)CARRY2(sizeLo,(uint)startAddress);
        *(uint *)0x138 = (uint)startAddress;
        *(uint *)0x13a = (*(uint16_t *)((uint8_t *)&(startAddress) + 2));
        iVar3 = __INITEXTMEM(sizeLo,sizeHi,(uint)startAddress,(*(uint16_t *)((uint8_t *)&(startAddress) + 2)));
        if (iVar3 != 0) {
          return iVar3;
        }
        if (bVar1) break;
        bVar1 = true;
      }
      *(undefined2 *)0x13c = 0xbfb;
      *(undefined2 *)0x13e = 0;
      *(undefined2 *)0x112 = 1;
      *(byte *)&OvrFlags = *(byte *)&OvrFlags | 1;
      *(undefined2 *)&__CALLEXTEXIT = 0x1152;
      *(undefined2 *)&__CALLEXTEMSSWAP = 0xd0e;
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}
