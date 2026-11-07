# Resident code function map

The resident code is the Borland C++ 3.0 runtime, the C0 startup, and the
VROOMM overlay manager. It is linked from `C0L.OBJ`, `CL.LIB`, `MATHL.LIB`,
and `OVERLAY.LIB`; it is not game-specific code. Function offsets below are
relative to static segment `0x1000`.

| Offset | Library symbol | Module |
|---|---|---|
| 2747 | `_printf` | PRINTF |
| 2D31 | `_strcpy` | STRCPY |
| 094F | `SCOPY@` | F_SCOPY |
| 2666 | `_memset` | MEMSET |
| 26D7 | `_memmove` | MOVMEM |
| 261E | `_memcpy` | MEMCPY |
| 0938 | `LXMUL@` | F_LXMUL |
| 09C4 | `LDIV@` | H_LDIV |
| 2D9B | `_strlen` | STRLEN |
| 2FA8 | `__write` | WRITEA |
| 2642 | `_setmem` | MEMSET |
| 2CC2 | `_strcat` | STRCAT |
| 08FD | `_exit` | EXIT |
| 0AD4 | `F_PADD@` | H_PADD |
| 0D07 | `__read` | READA |
| 2D01 | `_strcmp` | STRCMP |
| 0C57 | `_lseek` | LSEEK |
| 0E30 | `_tolower` | TOLOWER |
| 25F6 | `_memcmp` | MEMCMP |
| 1842 | `_farfree` | FARHEAP |
| 238B | `_filelength` | FLENGTH |
| 0A93 | `LXRSH@` | H_LRSH |
| 0A72 | `LXLSH@` | H_LLSH |
| 0E5C | `_remove` | REMOVE |
| 2568 | `_getcwd` | GETCWD |
| 0AB3 | `LXURSH@` | H_LURSH |
| 26F8 | `__open` | OPENA |
| 2270 | `__creat` | CREATA |
| 09D3 | `F_LMOD@` | H_LDIV |
| 09CB | `F_LUDIV@` | H_LDIV |
| 0C80 | `_mkdir` | MKDIR |
| 0865 | `_chdir` | CHDIR |
| 2D5A | `_stricmp` | STRICMP |
| 219F | `_atol` | ATOL |
| 2DEB | `_strstr` | STRSTR |
| 2DBA | `_strncpy` | STRNCPY |

Remaining offsets are C0/VROOMM internals or library functions whose first
bytes contain relocations (`0x2225`, `0x13E9`, `0x0730`, `0x0CE1`, `0x07E7`,
`0x0776`, `0x0295`, `0x026C`, `0x2C7F`, `0x06C4`, `0x2CA1`, `0x069F`,
`0x044F`, `0x09A2`, `0x05C5`, `0x032F`, `0x172E`, `0x0472`, `0x04B3`,
`0x02C9`, `0x06F8`, `0x19A6`, `0x03C2`, `0x0632`). They are resolved by
linking the original libraries; they are not game code.
