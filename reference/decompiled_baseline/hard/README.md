# Relaxed-limit decompiler retries

These functions defeat `ExportRecovered.java`'s normal decompiler timeout or
trigger a low-level decompiler error. They were recovered separately with
`ExportOne.java` (larger timeout, 256 MB payload, 2M-instruction limit) or with
`RecoverFunction.java` (clearing bad references / locals first).

The exporter notices a file here named `<module>__<function>.c` and uses it in
place of the failed stub, so a normal re-export remains complete.

| file | original address | note |
|---|---|---|
| `ovc44_strong_dat__init_assets.c` | `6ffe:02f7` | 28 KB asset-init function |
| `ovc21_manage__manage_4d05_1bee.c` | `4d05:1bee` | response-buffer limit |
| `ovc45__OVC45_77eb_0d61.c` | `77eb:0d61` | response-buffer limit |
| `ovc17_stash__stshRead.c` | `474a:008f` | forced-merge intersection |
| `ovc23__OVC23_55fe_0000.c` | `55fe:0000` | invalid `NO ADDRESS` reference |
| `ovc47_constrct__constrct_7e7c_0b9c.c` | `7e7c:0b9c` | decompiler timeout |
