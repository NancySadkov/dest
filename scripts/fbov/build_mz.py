#!/usr/bin/env python3
"""Generate the MZ header and relocation table from committed metadata."""
import csv
import json
import os
import struct

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC = os.path.join(ROOT, "src")


def main():
    meta = json.load(open(os.path.join(SRC, "mz_header.json")))
    f = meta["fields"]
    size = meta["size"]
    out = bytearray(size)
    struct.pack_into(
        "<14H", out, 0,
        f["magic"], f["cblp"], f["cp"], f["crlc"], f["cparhdr"],
        f["minalloc"], f["maxalloc"], f["ss"], f["sp"], f["csum"],
        f["ip"], f["cs"], f["lfarlc"], f["ovno"])
    extra = bytes.fromhex(meta["extra"])
    out[0x1C:0x1C + len(extra)] = extra
    i = 0
    for r in csv.DictReader(open(os.path.join(ROOT, "doc", "fbov_relocs.csv"))):
        struct.pack_into("<HH", out, f["lfarlc"] + 4 * i,
                         int(r["ofs"], 16), int(r["seg"], 16))
        i += 1
    if i != f["crlc"]:
        raise SystemExit("relocation count %d != %d" % (i, f["crlc"]))
    path = os.path.join(ROOT, "tmp", "mz_header.bin")
    open(path, "wb").write(out)
    print("wrote", path, size, "bytes")
    ref = os.path.join(SRC, "mz_header.bin")
    if os.path.exists(ref):
        if open(ref, "rb").read() != bytes(out):
            raise SystemExit("generated MZ header differs from reference")
        print("matches src/mz_header.bin")


if __name__ == "__main__":
    main()
