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
    "short": 2, "ushort": 2, "unsigned": 2, "signed": 2, "sbyte": 1,
    "uchar": 1, "uint16": 2, "int32_t": 4, "uint32": 4, "float": 4,
    "uint32_t": 4, "int32_t": 4, "long": 4, "ulong": 4,
    "far_t": 4, "brect_t": 10, "dosver_t": 2,
}

STRUCTS = {}


def _field_layout(ty):
    ty = ty.strip()
    if "*" in ty:
        return 4 if "far" in ty else 2
    base = ty.split()[-1]
    if base in WIDTH:
        return WIDTH[base]
    if base in STRUCTS:
        return list(STRUCTS[base])
    return None


def depth_of(layout):
    if isinstance(layout, list):
        return sum(depth_of(x) for x in layout)
    return layout


def load_structs(path="src/decompiled/st_types.h"):
    """Resolve every struct in dependency order.

    A struct can embed another one defined later in the header, so a single pass
    leaves those unresolved (that is why anm_t and bld_inst_t were invisible).
    Iterate to a fixpoint instead.
    """
    text = io.open(path, encoding="latin-1").read()
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    defs = [(m.group(1), m.group(2))
            for m in re.finditer(r"struct (\w+) \{(.*?)\};", text, re.S)]
    STRUCTS["far_t"] = [2, 2]
    progress = True
    while progress:
        progress = False
        for name, body in defs:
            if name in STRUCTS:
                continue
            fields = []
            ok = True
            for fm in re.finditer(r"([\w \*]+?)\s+(\w+)\s*(?:\[(\d+)\])?\s*;", body):
                lay = _field_layout(fm.group(1))
                if lay is None:
                    ok = False
                    break
                n = int(fm.group(3)) if fm.group(3) else 1
                fields.extend([lay] * n)
            if ok and fields:
                STRUCTS[name] = fields
                progress = True


load_structs()
if "brect_t" not in STRUCTS:
    STRUCTS["brect_t"] = [2, 2, 2, 2, 2]


def _tokens(text):
    """Brace-aware token list: numbers/strings and '{' / '}' markers."""
    out = []
    i = 0
    while i < len(text):
        c = text[i]
        if c in "{}":
            out.append(c)
            i += 1
            continue
        if c == '"':
            j = i + 1
            while j < len(text) and (text[j] != '"' or text[j - 1] == "\\"):
                j += 1
            out.append(text[i:j + 1])
            i = j + 1
            continue
        m = re.match(r"-?(?:0x[0-9A-Fa-f]+|\d+)", text[i:])
        if m:
            out.append(m.group(0))
            i += len(m.group(0))
            continue
        i += 1
    return out


def _pack(tok, width):
    if tok.startswith('"'):
        data = decode_c(tok[1:-1]) + b"\0"
        return data[:width].ljust(width, b"\0")
    v = int(tok, 0)
    if width == 1:
        return bytes([v & 0xFF])
    if width == 2:
        return struct.pack("<H", v & 0xFFFF)
    return struct.pack("<I", v & 0xFFFFFFFF)


def _walk(tokens, pos, layout):
    """Consume one brace group into bytes, following the nested layout."""
    out = bytearray()
    i = pos
    if i < len(tokens) and tokens[i] == "{":
        i += 1
    for field in layout:
        if i >= len(tokens):
            out += b"\0" * depth_of(field)
            continue
        if isinstance(field, list):
            if tokens[i] == "{":
                sub = _walk(tokens, i, field)
                out += sub
                depth = 0
                while i < len(tokens):
                    if tokens[i] == "{":
                        depth += 1
                    elif tokens[i] == "}":
                        depth -= 1
                        if depth == 0:
                            i += 1
                            break
                    i += 1
            else:
                out += b"\0" * depth_of(field)
            continue
        if tokens[i] == "}":
            out += b"\0" * field
            continue
        out += _pack(tokens[i], field)
        i += 1
    return bytes(out)


DECL = re.compile(r"^([A-Za-z_][\w ]*?\*?)\s*([A-Za-z_]\w*)\s*(?:\[(\d*)\])?\s*=\s*([^;]*);",
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
        try:
            v = num(init)
        except ValueError:
            nums = re.findall(r"0x[0-9A-Fa-f]+|\d+", init)
            if not nums:
                return b""
            v = sum(int(x, 0) for x in nums)
        if th == "far_ptr":
            return struct.pack("<HH", v & 0xFFFF, (v >> 16) & 0xFFFF)
        if th == "near_ptr":
            return struct.pack("<H", v & 0xFFFF)
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
    if th in STRUCTS and items and items[0].strip().startswith("{"):
        # Flattening the braces is exact whenever a nested group covers a run of
        # consecutive fields - which holds for embedded far_t and for byte
        # arrays like bld_inst_t.data[8].
        out = bytearray()
        widths = []
        stack = [STRUCTS[th]]
        while stack:
            lay = stack.pop(0)
            for f in lay:
                if isinstance(f, list):
                    stack.insert(0, f)
                else:
                    widths.append(f)
        for it in items:
            toks = _tokens(it)
            if toks and toks[0] == "{":
                toks = toks[1:]
            if toks and toks[-1] == "}":
                toks = toks[:-1]
            i = 0
            wi = 0
            while i < len(toks) and wi < len(widths):
                w = widths[wi]
                if toks[i] == "{":
                    j = i + 1
                    grp = []
                    while j < len(toks) and toks[j] != "}":
                        if toks[j] != "{":
                            grp.append(toks[j])
                        j += 1
                    i = j + 1
                    if w == 4 and len(grp) == 2:
                        v = int(grp[0], 0) | (int(grp[1], 0) << 16)
                        out += struct.pack("<I", v & 0xFFFFFFFF)
                        wi += 1
                    else:
                        for g in grp:
                            out += _pack(g, w)
                            wi += 1
                    continue
                if toks[i] == "}":
                    i += 1
                    continue
                out += _pack(toks[i], w)
                i += 1
                wi += 1
        if size:
            out = out[:size] + b"\0" * max(0, size - len(out))
        return bytes(out)
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
            m2 = re.search(r"0x[0-9A-Fa-f]+|\d+", it)
            if not m2:
                continue
            total = sum(int(x, 0) for x in re.findall(r"0x[0-9A-Fa-f]+|\d+", it))
            v = total if th == "far_ptr" else total & 0xFFFF
        w = WIDTH.get(th, 1)
        if th == "far_ptr":
            out += struct.pack("<HH", v & 0xFFFF, (v >> 16) & 0xFFFF)
            continue
        if th == "near_ptr":
            out += struct.pack("<H", v & 0xFFFF)
            continue
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
        if th in WIDTH:
            w = WIDTH[th]
        elif th in STRUCTS:
            w = sum(STRUCTS[th])
        elif "*" in m.group(1):
            if "far" in m.group(1):
                w, th = 4, "far_ptr"
            else:
                w, th = 2, "near_ptr"
        else:
            continue
        size = int(count) * w if count else None
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
    r"__stklen|__brkbuf|_video|VIDEOREC)", re.I)
for row in rows:
    off = int(row["offset"], 16)
    name = row["name"]
    length = int(row["length"])
    want = IMG[off:off + length]
    if STARTUP.match(name):
        startup += 1
        continue
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
        if len(want) >= 4 and any(len(d) >= len(want) and d[:len(want)] == want
                                  for d in by_bytes):
            renamed += 1
            same += 1
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
if "--bytes" in sys.argv:
    for off, name, length, want, got in diffs:
        print("\n%04x %s len=%d (ours %d)" % (off, name, length, len(got)))
        n = min(length, len(got), 64)
        for i in range(n):
            if want[i] != got[i]:
                print("  first diff at +%d: want %02x got %02x" % (i, want[i], got[i]))
                break
        print("  want %s" % want[:32].hex())
        print("  got  %s" % got[:32].hex())

print("\nstate differences (first %d):" % MAX)
for off, name, length, want, got in diffs[:MAX]:
    print("  %04x %-34s len=%-3d want=%-20s got=%s"
          % (off, name, length, want.hex()[:40], got.hex()[:40]))
print("\nnot declared (first %d):" % MAX)
for off, name, length in missing_list[:MAX]:
    print("  %04x %-34s len=%d" % (off, name, length))
