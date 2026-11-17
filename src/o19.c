#include "st.h"

/* ovc19_save: 8 function(s) */

/* 49fd:0000 */
undefined2 __cdecl16far save_49fd_0000(int param_1,void *param_2,undefined2 param_3,uint param_4)
{
    undefined2 r;

    return r;
}

/* 49fd:0035 */
void __cdecl16far save_49fd_0035(void)
{
}

/* 49fd:01da */
undefined2 __cdecl16far save_49fd_01da(int param_1)
{
    undefined2 r;

    return r;
}

/* 49fd:081e */
undefined1 __cdecl16far save_49fd_081e(byte slot)
{
    char *filename;
    int handle;
    undefined1 result;

    filename = fmVsprintf("%ssave.%03d",GWorkDir,slot);
    handle = open_wait_unlock_and_disk(filename);
    result = save_49fd_01da(handle);
    close(handle);
    return result;
}

/* 49fd:0863 */
undefined1 __cdecl16far save_49fd_0863(void)
{
    undefined1 r;

    return r;
}

/* 49fd:08da */
undefined2 __cdecl16far save_49fd_08da(int param_1,void *param_2,undefined2 param_3,uint16_t param_4)
{
    undefined2 r;

    return r;
}

/* 49fd:090f */
undefined2 __cdecl16far stSave(void)
{
    undefined2 r;

    return r;
}

/* 49fd:0f26 */
void __cdecl16far save_49fd_0f26(void)
{
}

