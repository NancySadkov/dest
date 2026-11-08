#!/usr/bin/env python3
"""Assemble a standalone STRONG.EXE from committed source.

The static load module and the FBOV/overlay metadata are committed as base
blobs; every overlay code region is rebuilt from src/ by build_overlays.py.
No step reads game/STRONG.EXE.

Usage:
  python scripts/fbov/build_standalone.py [--skip-overlays] [--out PATH]
"""
import argparse
import csv
import hashlib
import json
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC = os.path.join(ROOT, "src")
OVCODE = os.path.join(ROOT, "tmp", "ovcode")
EXPECTED = "aebde62f1546aa19f0a188f5aa7224145f4575749c1cb08c2f25801ac98ec8cd"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--skip-overlays", action="store_true",
                    help="use the existing tmp/ovcode build")
    ap.add_argument("--skip-static", action="store_true",
                    help="use the existing tmp/static_load.bin")
    ap.add_argument("--out", default=os.path.join(ROOT, "out", "STRONG.EXE"))
    ap.add_argument("--wait", type=int, default=150)
    a = ap.parse_args()

    if not a.skip_static:
        subprocess.run([sys.executable,
                        os.path.join(ROOT, "scripts", "fbov",
                                     "build_static.py")], check=True)
    if not a.skip_overlays:
        subprocess.run([sys.executable,
                        os.path.join(ROOT, "scripts", "fbov",
                                     "build_overlays.py"),
                        "--wait", str(a.wait)], check=True)

    mz = open(os.path.join(SRC, "mz_header.bin"), "rb").read()
    load = open(os.path.join(ROOT, "tmp", "static_load.bin"), "rb").read()
    static = mz + load
    fbov = bytearray(open(os.path.join(SRC, "base_fbov.bin"), "rb").read())
    fbov_off = len(static)

    index = json.load(open(os.path.join(OVCODE, "index.json")))
    for ent in index:
        data = open(os.path.join(OVCODE, ent["file"]), "rb").read()
        if len(data) != ent["size"]:
            raise SystemExit("%s size %d != %d"
                             % (ent["file"], len(data), ent["size"]))
        row = None
        for r in csv.DictReader(open(os.path.join(ROOT, "doc",
                                                  "fbov_overlays.csv"))):
            if int(r["code_seg"], 16) == int(ent["seg"], 16):
                row = r
                break
        if row is None:
            raise SystemExit("overlay %s missing from table" % ent["seg"])
        off = int(row["code_file_offset"], 0) - fbov_off
        fbov[off:off + len(data)] = data

    out = static + bytes(fbov)
    os.makedirs(os.path.dirname(a.out), exist_ok=True)
    open(a.out, "wb").write(out)
    digest = hashlib.sha256(out).hexdigest()
    print("wrote %s (%d bytes)" % (a.out, len(out)))
    print("sha256", digest)
    if digest != EXPECTED:
        raise SystemExit("hash mismatch; expected " + EXPECTED)
    print("byte-identical to original")


if __name__ == "__main__":
    main()
