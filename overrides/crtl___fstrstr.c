char * __cdecl16far _fstrstr(char *haystack,char *needle)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  uint16_t uVar7;
  uint16_t uVar8;
  bool bVar9;
  
  if (*needle != '\0') {
    uVar7 = (uint16_t)((ulong)haystack >> 0x10);
    uVar2 = 0xffff;
    pcVar5 = (char *)haystack;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar1 != '\0');
    uVar2 = ~uVar2;
    uVar8 = (uint16_t)((ulong)needle >> 0x10);
    iVar3 = -1;
    pcVar5 = (char *)needle;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar1 != '\0');
    bVar9 = iVar3 + 1U == 0;
    uVar4 = ~(iVar3 + 1U);
    do {
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar1 = (char *)haystack;
        (*(uint16_t *)((uint8_t *)&(haystack))) = (uint16_t)(char *)haystack + 1;
        bVar9 = *needle == *pcVar1;
      } while (!bVar9);
      if ((!bVar9) || (uVar2 < uVar4)) {
        (*(uint16_t *)((uint8_t *)&(haystack))) = (uint16_t)(char *)((int)(uint32_t *)&_DATA + 1);
        break;
      }
      if (uVar4 == 0) break;
      iVar3 = uVar4 - 1;
      bVar9 = iVar3 == 0;
      pcVar6 = (char *)haystack;
      pcVar5 = (char *)needle;
      do {
        pcVar5 = pcVar5 + 1;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar1 = pcVar6;
        pcVar6 = pcVar6 + 1;
        bVar9 = *pcVar5 == *pcVar1;
      } while (bVar9);
    } while (!bVar9);
    (*(uint16_t *)((uint8_t *)&(haystack))) = (uint16_t)(char *)haystack + -1;
  }
  return (char *)haystack;
}
