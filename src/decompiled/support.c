/* Small helpers for MCGA/TC30 builds of the recovered tree. */
#include "st.h"

far_t far_from_u32(uint32_t v) {
    far_t f;
    f.ofs = (uint16_t)v;
    f.seg = (uint16_t)(v >> 16);
    return f;
}

uint32_t far_to_u32(far_t f) {
    return ((uint32_t)f.seg << 16) | f.ofs;
}

DW dw_from_u32(uint32_t v) {
    DW d;
    d.lo = (uint16_t)v;
    d.hi = (uint16_t)(v >> 16);
    return d;
}

uint32_t dw_to_u32(DW d) {
    return ((uint32_t)d.hi << 16) | d.lo;
}
