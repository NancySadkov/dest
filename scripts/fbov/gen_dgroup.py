#!/usr/bin/env python3
"""Generate the canonical DGROUP data source from the validated candidate map.

Outputs:
  src/recovered/dgroup.c
  src/recovered/dgroup.h
  doc/dgroup_map.csv

Every byte of DGROUP (0x2410:0000..0x9499) is defined exactly once.  Known
symbols keep their recovered names/types/initialisers; gaps become byte arrays
with the original bytes.
"""
import csv
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
EXE = os.path.join(ROOT, "game", "STRONG.EXE")
CAND = os.path.join(ROOT, "doc", "dgroup_candidate.csv")
OUT_C = os.path.join(ROOT, "src", "recovered", "dgroup.c")
OUT_H = os.path.join(ROOT, "src", "recovered", "dgroup.h")
OUT_MAP = os.path.join(ROOT, "doc", "dgroup_map.csv")

FILE_OFF = 0x15F00
SIZE = 0x949A
data_global = b""


def c_bytes(data, off, n):
    return "{ " + ", ".join("0x%02X" % data[off + i] for i in range(n)) + " }"


def escape_c_string(s):
    # s includes the surrounding quotes.
    if not (s.startswith('"') and s.endswith('"')):
        return s
    inner = s[1:-1]
    # escape quotes that are not already escaped
    inner = re.sub(r'(?<!\\)"', r'\\"', inner)
    return '"' + inner + '"'


def shorten_items(items):
    used = set()
    out = []
    for off, ln, name, decl, init in items:
        new = name
        if len(new) > 31:
            m = re.search(r"(_(?:2410|2000)_[0-9a-fA-F]{4})$", new)
            suffix = m.group(1) if m else new[-8:]
            prefix = new[:len(new) - len(suffix)]
            room = 31 - len(suffix)
            cand = prefix[:room] + suffix
            k = 0
            while cand in used:
                k += 1
                tail = "_%d" % k
                cand = prefix[:room - len(tail)] + tail + suffix
            new = cand
            decl = decl.replace(name, new, 1)
        used.add(new)
        out.append((off, ln, new, decl, init))
    return out


def c_lit_len(s):
    if not (s.startswith('"') and s.endswith('"')):
        return 0
    inner = s[1:-1]
    n = 0
    i = 0
    while i < len(inner):
        if inner[i] == "\\" and i + 1 < len(inner):
            i += 2
        else:
            i += 1
        n += 1
    return n + 1  # terminating NUL


def raw_init(decl, off, ln):
    """Exact initializer from the original bytes for scalar/simple arrays."""
    m = re.match(r"^(.*?)\s*([A-Za-z_]\w*)\s*(\[[^\]]*\])?$", decl)
    if not m:
        return None
    typ = m.group(1).strip()
    is_array = "[" in decl
    b = data_global[off:off + ln]
    if typ in ("char", "undefined", "uint8_t", "byte"):
        if b and 0 in b:
            head = b.split(b"\0")[0]
            if head and all(32 <= x < 127 or x in (9, 10, 13) for x in head):
                s = head.decode("latin1")
                s = (s.replace("\\", "\\\\").replace('"', '\\"')
                      .replace("\r", "\\r").replace("\n", "\\n"))
                return '"' + s + '"'
        return "{ " + ", ".join("0x%02X" % x for x in b) + " }"
    if typ in ("undefined2", "uint16_t", "int16_t", "short", "int", "uint", "word"):
        vals = [int.from_bytes(b[i:i + 2], "little") for i in range(0, len(b) - 1, 2)]
        if not is_array:
            return "0x%04X" % vals[0] if vals else "0"
        return "{ " + ", ".join("0x%04X" % v for v in vals) + " }"
    if typ in ("undefined4", "uint32_t", "long", "dword", "ulong"):
        vals = [int.from_bytes(b[i:i + 4], "little") for i in range(0, len(b) - 3, 4)]
        if not is_array:
            return "0x%08X" % vals[0] if vals else "0"
        return "{ " + ", ".join("0x%08X" % v for v in vals) + " }"
    if typ in ("far_t", "DW"):
        vals = [(int.from_bytes(b[i:i + 2], "little"),
                 int.from_bytes(b[i + 2:i + 4], "little"))
                for i in range(0, len(b) - 3, 4)]
        if not is_array:
            return "{ 0x%04X, 0x%04X }" % vals[0] if vals else "{ 0, 0 }"
        return "{ " + ", ".join("{ 0x%04X, 0x%04X }" % v for v in vals) + " }"
    if typ in ("unk01_t", "boinit_t"):
        vals = []
        for i in range(0, len(b) - 5, 6):
            vals.append("{ 0x%02X, 0x%02X, { 0x%04X, 0x%04X } }" % (
                b[i], b[i + 1],
                int.from_bytes(b[i + 2:i + 4], "little"),
                int.from_bytes(b[i + 4:i + 6], "little")))
        if not is_array:
            return vals[0] if vals else "{ 0, 0, { 0, 0 } }"
        return "{ " + ", ".join(vals) + " }"
    if typ.endswith("*"):
        vals = []
        for i in range(0, len(b) - 3, 4):
            ofs = int.from_bytes(b[i:i + 2], "little")
            seg = int.from_bytes(b[i + 2:i + 4], "little")
            vals.append("(%s)(0x%04X0000UL + 0x%04XUL)" % (typ, seg, ofs))
        if not is_array:
            return vals[0] if vals else "0"
        return "{ " + ", ".join(vals) + " }"
    return None


def extern_of(decl):
    return "extern " + decl + ";"


def main():
    data = open(EXE, "rb").read()[FILE_OFF:FILE_OFF + SIZE]
    if len(data) != SIZE:
        raise SystemExit("DGROUP bytes truncated")
    global data_global
    data_global = data

    rows = list(csv.DictReader(open(CAND)))
    # A name must refer to exactly one address.  If the candidate map has
    # aliases with different addresses, keep the longest definition.
    best_by_name = {}
    for r in rows:
        if not r["length"]:
            continue
        name = r["name"]
        ln = int(r["length"])
        prev = best_by_name.get(name)
        if prev is None or ln > int(prev["length"]):
            best_by_name[name] = r
    rows = list(best_by_name.values())

    chosen = {}
    skipped = 0
    for r in rows:
        if not r["length"]:
            continue
        off = int(r["offset"], 16)
        ln = int(r["length"])
        if ln <= 0 or off < 0 or off >= SIZE:
            skipped += 1
            continue
        if off + ln > SIZE:
            skipped += 1
            continue
        name = r["name"]
        decl = r["decl"]
        init = r["init"]
        # Prefer the longest definition at a given offset.
        prev = chosen.get(off)
        if prev is not None and prev[1] >= ln:
            continue
        chosen[off] = (name, ln, decl, init)

    # Sort and drop overlapping symbols.  Keep the first (lowest address,
    # longest at that address), which is the enclosing object.
    items = []
    covered_end = -1
    for off in sorted(chosen):
        name, ln, decl, init = chosen[off]
        if off < covered_end:
            skipped += 1
            continue
        items.append((off, ln, name, decl, init))
        covered_end = off + ln

    items = shorten_items(items)

    defs = []
    externs = []
    covered = []
    for off, ln, name, decl, init in items:
        ri = raw_init(decl, off, ln)
        if ri is not None:
            init = ri
            if ri.startswith('"'):
                decl = "char %s[%d]" % (name, ln)
            elif decl.endswith("[]"):
                base = decl.rsplit(" ", 1)[0]
                if base in ("undefined", "char", "uint8_t", "byte"):
                    decl = decl[:-2] + "[%d]" % ln
        elif not init:
            decl = "uint8_t %s[%d]" % (name, ln)
            init = c_bytes(data, off, ln)
        elif init.startswith('"'):
            if c_lit_len(init) <= ln:
                decl = "char %s[%d]" % (name, ln)
            else:
                decl = "char %s[]" % name
            init = escape_c_string(init)
        else:
            # Keep the exact object size: an inferred array size can be
            # shorter than the original when the initializer omits trailing
            # padding.  Explicit sizes from the exporter are authoritative.
            if decl.endswith("[]"):
                base = decl.rsplit(" ", 1)[0]
                if base in ("undefined", "char", "uint8_t", "byte"):
                    decl = decl[:-2] + "[%d]" % ln
        # VIDEOREC gained an explicit pad byte at 0x0b; the recovered
        # initializer was written without it.
        if decl.startswith("VIDEOREC ") and init.startswith("{"):
            idx = init.rfind("{")
            if idx > 0:
                init = init[:idx] + "0x0, " + init[idx:]
        defs.append((off, "%s = %s;" % (decl, init)))
        externs.append(extern_of(decl))
        covered.append((off, off + ln))

    # Gaps: every byte not covered by a symbol.
    gap_defs = []
    gap_externs = []
    pos = 0
    gaps = 0
    for s, e in covered + [(SIZE, SIZE)]:
        if pos < s:
            n = s - pos
            name = "gap_2410_%04X" % pos
            decl = "uint8_t %s[%d]" % (name, n)
            init = c_bytes(data, pos, n)
            gap_defs.append((pos, "%s = %s;" % (decl, init)))
            gap_externs.append(extern_of(decl))
            gaps += 1
        if e > pos:
            pos = e

    with open(OUT_C, "w", encoding="ascii") as f:
        f.write("/* DGROUP 0x2410:0000..0x9499, exact original bytes.\n")
        f.write(" * Known symbols keep recovered names/types/initialisers;\n")
        f.write(" * uncovered ranges are byte arrays. */\n")
        f.write('#include "dgroup.h"\n\n')
        for off, d in sorted(defs + gap_defs, key=lambda x: x[0]):
            f.write(d + "\n")

    with open(OUT_H, "w", encoding="ascii") as f:
        f.write("/* DGROUP 0x2410 declarations. */\n")
        f.write("#ifndef ST_DGROUP_H\n#define ST_DGROUP_H\n")
        f.write('#include "st_compat.h"\n#include "st_types.h"\n')
        f.write("\n")
        f.write("#define DGROUP_SEG 0x2410\n#define DGROUP_SIZE 0x949A\n\n")
        for e in externs:
            f.write(e + "\n")
        for e in gap_externs:
            f.write(e + "\n")
        f.write("\n#endif\n")

    with open(OUT_MAP, "w", newline="", encoding="ascii") as f:
        w = csv.writer(f)
        w.writerow(["offset", "name", "length", "decl"])
        for off, ln, name, decl, init in items:
            w.writerow(["%04X" % off, name, ln, decl])
        for s, e in covered:
            pass

    print("symbols:", len(items), "gaps:", gaps, "skipped:", skipped)
    print("bytes covered:", sum(e - s for s, e in covered) + SIZE -
          sum(e - s for s, e in covered))
    print("wrote", OUT_C, OUT_H, OUT_MAP)


if __name__ == "__main__":
    main()
