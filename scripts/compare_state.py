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


# ---- our declarations: name -> (bytes, declared_size) -----------------------
ours = {}
for path in sorted(glob.glob("src/decompiled/st_globals*.c")):
    t = io.open(path, encoding="latin-1").read()
    for m in re.finditer(r'^char ([_0-9A-Za-z]+)\[(\d*)\] = "((?:[^"\\]|\\.)*)";', t, re.M):
        size = int(m.group(2)) if m.group(2) else None
        data = decode_c(m.group(3)) + b"\0"
        if size is None:
            size = len(data)
        data = data[:size] + b"\0" * max(0, size - len(data))
        ours[m.group(1)] = (data, size)
    for m in re.finditer(r"^uint8_t ([_0-9A-Za-z]+)\[(\d+)\] = \{ ([^}]*) \};", t, re.M):
        vals = [int(x, 16) for x in re.findall(r"0x([0-9A-Fa-f]{1,2})", m.group(3))]
        size = int(m.group(2))
        data = bytes(vals)[:size] + b"\0" * max(0, size - len(vals))
        ours[m.group(1)] = (data, size)
    # char arrays written as element lists (non-terminated items: all spaces)
    for m in re.finditer(r"^char ([_0-9A-Za-z]+)\[(\d+)\] = \{ ([^}]*) \};", t, re.M):
        size = int(m.group(2))
        items = re.findall(r"'(\\?.)'|(0x[0-9A-Fa-f]{1,2})|(\d+)", m.group(3))
        vals = []
        for ch, hx, dec in items:
            if hx:
                vals.append(int(hx, 16))
            elif dec:
                vals.append(int(dec))
            elif ch:
                esc = {"n": 10, "r": 13, "t": 9, "0": 0, "\\": 92, "'": 39}
                vals.append(esc.get(ch, ord(ch)))
        data = bytes(vals)[:size] + b"\0" * max(0, size - len(vals))
        ours[m.group(1)] = (data, size)
    for m in re.finditer(r"^(\w[\w \*]*?) ([_0-9A-Za-z]+) = (0x[0-9A-Fa-f]+|\d+);", t, re.M):
        ours.setdefault(m.group(2), (None, None))   # scalar, handled below

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
diffs = []
missing_list = []
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
    if decl is None or decl[0] is None:
        missing += 1
        missing_list.append((off, name, length))
        continue
    got = decl[0]
    if got == want or got[:len(want)] == want:
        same += 1
    else:
        differ += 1
        diffs.append((off, decl_name, length, want, got))

print("original symbols:   %d" % len(rows))
print("identical state:    %d" % same)
print("DIFFERENT state:    %d" % differ)
print("not declared:       %d" % missing)
print("\nstate differences (first %d):" % MAX)
for off, name, length, want, got in diffs[:MAX]:
    print("  %04x %-34s len=%-3d want=%-20s got=%s"
          % (off, name, length, want.hex()[:40], got.hex()[:40]))
print("\nnot declared (first %d):" % MAX)
for off, name, length in missing_list[:MAX]:
    print("  %04x %-34s len=%d" % (off, name, length))
