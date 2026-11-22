/* Ghidra intrinsic implementations (generated). */
#include "recovered.h"
extern unsigned char inp(unsigned int port);
extern void outp(unsigned int port, unsigned char value);

/* Port I/O: the decompiler emits in(port) / out(port,value). */
int in(unsigned int port)
{
  return inp(port);
}

void out(unsigned int port, unsigned char value)
{
  outp(port, value);
}

/* far_from_u32 packs {offset,segment}: segment is the high word, the same
   layout MK_FP(seg,ofs) produces. */
far_t far_from_u32(uint32_t v)
{
  far_t r;
  r.ofs = (uint16_t)v;
  r.seg = (uint16_t)(v >> 16);
  return r;
}

unsigned long far_to_u32(far_t v)
{
  return ((unsigned long)v.seg << 16) | v.ofs;
}
