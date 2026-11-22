/* setdisk - recovered from STRONG.EXE (1000:09a4).

   The decompiled body was

       uint *unaff_SS;
       uint8_t driveCount;
       uint *puStack_6;

       puStack_6 = (uint *)CONCAT22(_driveCount,unaff_SS);
       _dos_setdrive(drive + 1,puStack_6);
       return _driveCount;

   which is a far pointer built out of two pseudo-variables.  _dos_setdrive takes a
   *near* `uint *` as its out parameter (see the recovered prototype), the function
   already declares the local `driveCount`, and the "global" `_driveCount` is only
   ever written through that pointer and then returned.  So it is the count
   variable itself: Borland's setdisk returns the number of drives. */
int __cdecl16far setdisk(int drive)

{
  uint driveCount;

  _dos_setdrive(drive + 1,&driveCount);
  return driveCount;
}
