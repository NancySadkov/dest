"""Classify the DGROUP symbols that compare_state.py reports as undeclared.

For each one, decide whether it is
  * startup-owned  - C0/CRT data (__C0argc, _psp, errno, _streams, GSTARTX...),
                     provided by the toolchain's startup, not by our tree;
  * renamed        - the tree has a declaration with the same bytes under a
                     different name (so it is recovered, just renamed);
  * missing        - neither: genuinely absent from the recovered source.

Output: scripts/model/dgroup_undeclared.tsv
"""
import csv
import glob
import io
import re
import struct

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


# our declarations: name -> bytes
ours = {}
for path in sorted(glob.glob("src/decompiled/st_globals*.c")):
    t = io.open(path, encoding="latin-1").read()
    for m in re.finditer(r'^char ([_0-9A-Za-z]+)\[(\d*)\] = "((?:[^"\\]|\\.)*)";', t, re.M):
        size = int(m.group(2)) if m.group(2) else None
        data = decode_c(m.group(3)) + b"\0"
        if size is None:
            size = len(data)
        data = data[:size] + b"\0" * max(0, size - len(data))
        ours[m.group(1)] = data
    for m in re.finditer(r"^uint8_t ([_0-9A-Za-z]+)\[(\d+)\] = \{ ([^}]*) \};", t, re.M):
        size = int(m.group(2))
        vals = [int(x, 16) for x in re.findall(r"0x([0-9A-Fa-f]{1,2})", m.group(3))]
        ours[m.group(1)] = bytes(vals)[:size] + b"\0" * max(0, size - len(vals))
    for m in re.finditer(r"^char ([_0-9A-Za-z]+)\[(\d+)\] = \{ ([^}]*) \};", t, re.M):
        size = int(m.group(2))
        vals = [0x20] * size
        ours[m.group(1)] = bytes(vals)

by_bytes = {}
for name, data in ours.items():
    by_bytes.setdefault(data, name)

STARTUP = re.compile(
    r"^(_DATA|__C0|__c0|_psp|_env|errno|DosVersion|__brklvl|_brklvl|_heapbase|"
    r"_heaptop|_StartTime|GSTARTX|__DOSERROR|_streams|_ctype|_fmode|_nfile|"
    r"_openfd|_exitbuf|_exitfopen|_exitopen|_atexit|_realcvt|_video|_doserrno|"
    r"__Init|__CleanUp|CtrlBreak|_osmajor|_osminor|_version|__argc|__argv|"
    r"GEnviron|GStart|__stklen|__brkbuf|__sizetab|__dynend|__heap)", re.I)

rows = []
for row in csv.DictReader(io.open("audit/dgroup_data.csv", encoding="utf-8", errors="replace")):
    off = int(row["offset"], 16)
    name = row["name"]
    length = int(row["length"])
    rows.append((off, name, length))

# names in our tree (for the "declared at all" test)
declared_names = set(ours)
for path in sorted(glob.glob("src/decompiled/st_globals*.c")):
    t = io.open(path, encoding="latin-1").read()
    declared_names.update(re.findall(r"^(?:char|uint8_t|uint16_t|int16_t|uint32_t|"
                                     r"int|undefined1|undefined2|undefined|bool|byte|"
                                     r"far_t|DW|\w+_t|\w+) ([_0-9A-Za-z]+)\s*(?:\[|=|;)",
                                     t, re.M))

counts = {"startup": 0, "renamed": 0, "missing": 0, "declared": 0}
out = []
for off, name, length in rows:
    if off < 0 or off >= len(IMG):
        continue
    want = IMG[off:off + length]
    if name in declared_names or re.search(r"_2410_%04x$" % off, " ".join(declared_names), re.I):
        counts["declared"] += 1
        continue
    if STARTUP.match(name):
        cls = "startup"
    elif want in by_bytes:
        cls = "renamed"
    else:
        # a one-byte slice of a longer declaration still counts as renamed
        cls = "missing"
        for data in ours.values():
            if want and want in data:
                cls = "renamed"
                break
    counts[cls] += 1
    out.append((off, name, length, cls, by_bytes.get(want, "")))

path = "scripts/model/dgroup_undeclared.tsv"
lines = ["# DGROUP symbols with no declaration of their own in the recovered tree.",
         "# offset\tname\tlength\tclass\ttwin declaration (for 'renamed')",
         "# class: startup = C0/CRT data; renamed = bytes exist under another name;",
         "#        missing = genuinely absent from the source."]
for off, name, length, cls, twin in out:
    lines.append("%04X\t%s\t%d\t%s\t%s" % (off, name, length, cls, twin))
io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(lines) + "\n")

print("symbols with a declaration:      %d" % counts["declared"])
print("undeclared, startup-owned:       %d" % counts["startup"])
print("undeclared, recovered as rename: %d" % counts["renamed"])
print("undeclared, genuinely missing:   %d" % counts["missing"])
print("wrote", path)
