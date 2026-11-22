uint __cdecl16far saveui_readSavesList(int entries,uint16_t entriesSeg)

{
  char *pcVar1;
  int fd;
  uint16_t uVar2;
  uint16_t in_DX;
  uint16_t uVar3;
  uint16_t *puVar4;
  uint uVar5;
  far_t handle;
  uint16_t uStack_4;
  
  uStack_4 = 0;
  pcVar1 = ovr_fmVsprintf("%ssaves.txt",&GWorkDir);
  fd = ovr_open_wait_unlock_and_disk(pcVar1);
  if (-1 < fd) {
    pcVar1 = (char *)saveui_readLine(fd);
    uVar3 = in_DX;
    uStack_4 = _atol((char *)CONCAT22(in_DX,pcVar1));
    handle.seg = in_DX;
    handle.ofs = (uint16_t)pcVar1;
    ovr_stshFree(handle);
    for (uVar5 = 0; uVar5 < uStack_4; uVar5 = uVar5 + 1) {
      uVar2 =(uint16_t)( saveui_readLine(fd));
      puVar4 = (uint16_t *)(entries + uVar5 * 4);
      puVar4[1] = uVar3;
      *puVar4 = uVar2;
    }
    close(fd);
  }
  return uStack_4;
}
