"""Per-variable DGROUP state comparison against the original image.

The criterion (user): functional parity holds when every variable in our DGROUP
has the same state as in the original.  Representation is irrelevant.

Inputs
  audit/dgroup_2410.bin   the original DGROUP image (Ghidra DumpDgroupBytes.java)
  audit/dgroup_data.csv   per-symbol offset, name, length, C decl, initialiser
  src/decompiled/st_globals*.c   our declarations

For every original symbol this resolves our declaration (address-suffixed name
first, then the unique name) and compares its initialiser bytes with the image
bytes for that symbol.

usage: python scripts/compare_state.py [--max N]
"""
import csv
import glob
import io
import re
import struct
import sys

MAX = 20
if "--max" in sys.argv:
    MAX = int(sys.argv[sys.argv.index("--max") + 1])

IMG = open("audit/dgroup_2410.bin", "rb").read()

ESC = {"n": 10, "r": 13, "t": 9, "0": 0, "\\": 92, '"': 34, "'": 39,
       "a": 7, "b": 8, "f": 12, "v": 11}


def decode_c(s):
    out = bytearray()
    i = 0
    while i < len(s):
        c = s[i]
        if c != "\\":
            out.append(ord(c) & 0xFF)
            i += 1
            continue
        i += 1
        if i >= len(s):
            break
        e = s[i]
        if e == "x":
            j = i + 1
            h = ""
            while j < len(s) and len(h) < 2 and s[j] in "0123456789abcdefABCDEF":
                h += s[j]
                j += 1
            out.append(int(h, 16))
            i = j
            continue
        out.append(ESC.get(e, ord(e)))
        i += 1
    return bytes(out)


# ---- our declarations: name -> bytes ---------------------------------------
WIDTH = {
    "char": 1, "byte": 1, "undefined": 1, "undefined1": 1, "uint8_t": 1,
    "int8_t": 1, "bool": 1,
    "uint16_t": 2, "int16_t": 2, "DW": 2, "word": 2, "uint": 2, "int": 2,
    "uint32_t": 4, "int32_t": 4, "long": 4, "ulong": 4,
    "far_t": 4, "brect_t": 10, "dosver_t": 2,
}

DECL = re.compile(r"^([A-Za-z_][\w ]*?)\s+([A-Za-z_]\w*)\s*(?:\[(\d*)\])?\s*=\s*([^;]*);",
                  re.M | re.S)


def num(tok):
    tok = tok.strip()
    return int(tok, 0)


def bytes_from(th, init, size):
    """Initialiser text -> bytes for a declaration of type `th`."""
    init = init.strip()
    if init.startswith('"') or init.startswith('L"'):
        chunks = re.findall(r'"((?:[^"\\]|\\.)*)"', init)
        data = b"".join(decode_c(c) for c in chunks) + b"\0"
        size = size if size else len(data)
        return data[:size] + b"\0" * max(0, size - len(data))
    if not init.startswith("{"):
        v = num(init)
        w = WIDTH.get(th, 2)
        return struct.pack("<I", v & 0xFFFFFFFF)[:w] if w <= 4 else b""
    body = init.strip()[1:-1].strip()
    items = []
    depth = 0
    cur = ""
    for ch in body:
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
        if ch == "," and depth == 0:
            items.append(cur)
            cur = ""
        else:
            cur += ch
    if cur.strip():
        items.append(cur)
    out = bytearray()
    for it in items:
        it = it.strip()
        if not it:
            continue
        if it.startswith("{"):
            for v in re.findall(r"0x[0-9A-Fa-f]+|\d+", it):
                out += struct.pack("<H", int(v, 0) & 0xFFFF)
            continue
        if it.startswith('"'):
            out += decode_c(it[1:-1]) + b"\0"
            continue
        if it.startswith("'"):
            ch = it[1:-1]
            esc = {"n": 10, "r": 13, "t": 9, "0": 0, "\\": 92, "'": 39}
            out += bytes([esc.get(ch, ord(ch) if ch else 0)])
            continue
        try:
            v = num(it)
        except ValueError:
            continue
        w = WIDTH.get(th, 1)
        if th == "far_t":
            out += struct.pack("<H", v & 0xFFFF)
        elif w == 1:
            out += bytes([v & 0xFF])
        elif w == 2:
            out += struct.pack("<H", v & 0xFFFF)
        else:
            out += struct.pack("<I", v & 0xFFFFFFFF)
    if size:
        out = out[:size] + b"\0" * max(0, size - len(out))
    return bytes(out)


ours = {}
for path in sorted(glob.glob("src/decompiled/st_globals*.c")):
    t = io.open(path, encoding="latin-1").read()
    for m in DECL.finditer(t):
        th = m.group(1).strip().split()[-1]
        name = m.group(2)
        count = m.group(3)
        init = m.group(4).strip()
        if th not in WIDTH:
            continue
        w = WIDTH[th]
        size = int(count) * w if count else None
        if init.startswith("{") and th in ("far_t", "brect_t") and count:
            size = int(count) * w
        data = bytes_from(th, init, size)
        if data:
            ours[name] = data

scalars = {}

# every declaration per name, in source order (duplicate symbols share a name)
occ = {}
for _p in sorted(glob.glob("src/decompiled/st_globals*.c")):
    for _m in re.finditer(r'^char ([_0-9A-Za-z]+)\[(\d*)\] = "',
                          io.open(_p, encoding="latin-1").read(), re.M):
        occ.setdefault(_m.group(1), []).append(_m.group(1))

by_addr = {}
for name in ours:
    m = re.search(r"_2410_([0-9a-f]{4})$", name, re.I)
    if m:
        by_addr[int(m.group(1), 16)] = name

# scalar values separately (need the type to know the width)
scalars = {}
for path in sorted(glob.glob("src/decompiled/st_globals*.c")):
    t = io.open(path, encoding="latin-1").read()
    for m in re.finditer(r"^(\w[\w \*]*?) ([_0-9A-Za-z]+) = (0x[0-9A-Fa-f]+|\d+);", t, re.M):
        scalars[m.group(2)] = int(m.group(3), 0)

# ---- original symbols -------------------------------------------------------
rows = list(csv.DictReader(io.open("audit/dgroup_data.csv", encoding="utf-8",
                                   errors="replace")))

seen = {}
same = differ = missing = 0
renamed = 0
startup = 0
diffs = []
missing_list = []

by_bytes = {}
for _n, _d in ours.items():
    by_bytes.setdefault(_d, _n)

STARTUP = re.compile(
    r"^(_DATA|__C0|__c0|_psp|_env|errno|DosVersion|__brklvl|_brklvl|_heapbase|"
    r"_heaptop|_StartTime|GSTARTX|__DOSERROR|_streams|_ctype|_fmode|_nfile|"
    r"_openfd|_exitbuf|_exitfopen|_exitopen|_atexit|_realcvt|_video|_doserrno|"
    r"__Init|__CleanUp|CtrlBreak|_osmajor|_osminor|_version|__argc|__argv|"
    r"__stklen|__brkbuf)", re.I)
for row in rows:
    off = int(row["offset"], 16)
    name = row["name"]
    length = int(row["length"])
    want = IMG[off:off + length]
    decl = None
    an = by_addr.get(off)
    if an:
        decl = ours.get(an)
        decl_name = an
    else:
        decl = ours.get(name)
        decl_name = name
        # duplicate symbols share a name: bind the k-th original occurrence to
        # the k-th declaration of that name (declarations are in address order)
        k = seen.get(name, 0)
        seen[name] = k + 1
        if len(occ.get(name, [])) > 1 and k < len(occ[name]):
            cand = occ[name][k]
            if cand in ours:
                decl, decl_name = ours[cand], cand
    if decl is None and name in scalars:
        v = scalars[name]
        if length == 1:
            got = struct.pack("<B", v & 0xFF)
        elif length == 2:
            got = struct.pack("<H", v & 0xFFFF)
        elif length == 4:
            got = struct.pack("<I", v & 0xFFFFFFFF)
        else:
            missing += 1
            missing_list.append((off, name, length))
            continue
        if got == want or got[:len(want)] == want:
            same += 1
        else:
            differ += 1
            diffs.append((off, name, length, want, got))
        continue
    if decl is None:
        if want in by_bytes:
            renamed += 1
            same += 1
            continue
        if STARTUP.match(name):
            startup += 1
            continue
        missing += 1
        missing_list.append((off, name, length))
        continue
    got = decl
    if got == want or got[:len(want)] == want:
        same += 1
    else:
        differ += 1
        diffs.append((off, decl_name, length, want, got))

print("original symbols:   %d" % len(rows))
print("identical state:    %d" % same)
print("DIFFERENT state:    %d" % differ)
print("recovered (renamed):%d" % renamed)
print("startup-owned:      %d" % startup)
print("genuinely missing:  %d" % missing)
print("\nstate differences (first %d):" % MAX)
for off, name, length, want, got in diffs[:MAX]:
    print("  %04x %-34s len=%-3d want=%-20s got=%s"
          % (off, name, length, want.hex()[:40], got.hex()[:40]))
print("\nnot declared (first %d):" % MAX)
for off, name, length in missing_list[:MAX]:
    print("  %04x %-34s len=%d" % (off, name, length))
