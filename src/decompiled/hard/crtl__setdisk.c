int __cdecl16far setdisk(int drive)

{
  extern undefined1 _driveCount;   /* hand fix: no symbol exists for it; the value is used as a segment */
  uint *unaff_SS;
  uint8_t driveCount;
  uint *puStack_6;
  
  puStack_6 = (uint *)CONCAT22(_driveCount,unaff_SS);
  _dos_setdrive(drive + 1,puStack_6);
  return _driveCount;
}
