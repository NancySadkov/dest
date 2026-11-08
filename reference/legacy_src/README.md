# Legacy source (quarantined)

These files are from the early 2024 partial rewrite attempt (commits
`8c64a2e`, `b99cea9`, `e813561`).  They are not built and not used as a
source of truth.

The active recovered source tree now lives directly in `src/`:

- `src/main.c`, `src/ov_<seg>.c` — recovered code per original module
- `src/dgroup.c`, `src/dgroup.h` — recovered DGROUP
- `src/chunks/<seg>/` — chunked sources for large overlays
- `src/st_types.h`, `src/st_compat.h` — recovered types and shims

Keeping the old files here only preserves them for historical reference.
