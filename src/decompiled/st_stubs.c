/* GUESS: stubs for the symbols the recovery could not resolve.
 *
 * Each one is listed in scripts/model/unresolved.tsv with the reason.  They
 * return 0 (or are zero-initialised), so the image links and can be run; they
 * are placeholders, not recovered code. */
#include "recovered.h"

/* GUESS: target address is data or a fragment in the original */
int func_0x00010264()
{
  return 0;
}

/* GUESS: target address is data or a fragment in the original */
int func_0x00010268()
{
  return 0;
}

/* GUESS: target address is data or a fragment in the original */
int func_0x000318f5()
{
  return 0;
}

/* GUESS: target address is data or a fragment in the original */
int func_0x0004f29c()
{
  return 0;
}

/* GUESS: target address is data or a fragment in the original */
int func_0x0004f32d()
{
  return 0;
}

/* GUESS: target address is data or a fragment in the original */
int func_0x0004f68f()
{
  return 0;
}

/* GUESS: target address is data or a fragment in the original */
int func_0x0004f735()
{
  return 0;
}

/* GUESS: target address is data or a fragment in the original */
int func_0x0004f930()
{
  return 0;
}

/* GUESS: target address is data or a fragment in the original */
int func_0x0004fcda()
{
  return 0;
}

/* GUESS: target address is data or a fragment in the original */
int func_0x0007164e()
{
  return 0;
}

/* Original: push cs; call 0 inside the overlay - a far call to offset 0 of the
   module segment (stshAllocStub).  The 0x6ffe argument is Ghidra naming the
   segment; no argument is actually passed. */
int func_0x0007ffe0()
{
  return 0;
}

/* GUESS: body not recovered */
int EXT_FUN_8000_f2fa()
{
  return 0;
}

/* GUESS: body not recovered */
int halt_baddata()
{
  return 0;
}

/* GUESS: body not recovered */
int smm_restore_state()
{
  return 0;
}

/* GUESS: body not recovered */
int ovr_season_usesGPromotable_e11a()
{
  return 0;
}

/* Ghidra renders an inline `INT n` as `pc = swi(n); (*pc)();`.

   Verified against the original: the interrupt is executed *here*, inside swi(),
   and the pointer returned only has to be callable - so every `(*pc)()` is a
   no-op but the DOS call has already happened.  What remains unrecovered is the
   *register interface*: call sites read the register outputs as though the
   interrupt returned them, which Ghidra modelled as
   unattached variables.  Recovering those means rewriting each call site with
   explicit inline asm (as was done for ioErrorHndlrInstall/Uninstall).  It is a
   FAR function: taking its address with a near cast baked the link-time segment
   in as an immediate (absolute memory once DOS loads). */

/* The returned pointer only has to be callable; it must be FAR so the compiler
   emits a normal relocation instead of a near cast that bakes in the link-time
   segment. */
static void far st_swi_target(void)
{
}

code *swi(int vector)
{
  if (vector == 0x1a) {
    asm int 1ah;
  }
  else {
    asm int 21h;
  }
  return (code *)st_swi_target;
}

/* GUESS: Borland floating-point runtime data */
int _emu = 0;

/* GUESS: Borland floating-point runtime data */
int _fperror = 0;


/* GUESS: VROOMM initialisers, no-ops in the non-overlay link (NO_OVERLAY) */
int _OVRINITEMS(void)
{
  return 0;
}

int _OVRINITEXT(void)
{
  return 0;
}
