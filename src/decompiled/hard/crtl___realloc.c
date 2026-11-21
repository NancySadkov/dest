void __cdecl16far ems_realloc(uint32_t handle)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x67);
  (*pcVar1)();
  return;
}
