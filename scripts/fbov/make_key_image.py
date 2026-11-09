#!/usr/bin/env python3
"""Build the relocatable image of the recovered gameProcessKey.

The C function is compiled with TCC, linked against the recovered DGROUP object
so every data reference resolves to its true offset, then its 22 far calls are
rewritten with the original overlay operands (the segment word doubles as the
FBOV fixup descriptor).  The result fits the original 0x25C-byte slot at
2E25:0ADF.
"""
import os
import re
import shutil
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
WORK = os.path.join(ROOT, "tmp", "keyimage")
OV_SEG = 0x2E25
OV_OFS = 0x0ADF
OV_SIZE = 0x25C


def compile_and_link():
    shutil.rmtree(WORK, ignore_errors=True)
    os.makedirs(WORK)
    for src, dst in (("src/st_compat.h", "compat.h"),
                     ("src/st_types.h", "types.h"),
                     ("src/dgroup.c", "dgroup.c"),
                     ("src/game/key.c", "key.c"),
                     ("src/game/keybody.inc", "keybody.inc")):
        shutil.copyfile(os.path.join(ROOT, src), os.path.join(WORK, dst))
    h = open(os.path.join(ROOT, "src", "dgroup.h"), encoding="ascii").read()
    h = h.replace('#include "st_compat.h"', '#include "compat.h"')
    h = h.replace('#include "st_types.h"', '#include "types.h"')
    open(os.path.join(WORK, "dgroup.h"), "w", encoding="ascii",
         newline="").write(h)

    sys.path.insert(0, os.path.join(ROOT, "scripts", "fbov"))
    import build_game
    ext = build_game.extdef(os.path.join(ROOT, "tmp", "gamebuild_src",
                                         "KEY.OBJ"))
    funcs = sorted(n for n in ext if n.startswith("_f_"))
    lines = ["GAMESTUB SEGMENT PARA PUBLIC 'CODE'"]
    for n in funcs:
        lines += ["PUBLIC " + n, n + ":", "  ret"]
    lines += ["GAMESTUB ENDS", "END", ""]
    open(os.path.join(WORK, "gstub.asm"), "w", newline="").write(
        "\r\n".join(lines))
    open(os.path.join(WORK, "link.rsp"), "w", newline="").write(
        "KEY.OBJ DGROUP.OBJ GSTUB.OBJ,CHK.EXE,CHK.MAP\r\n")
    open(os.path.join(WORK, "b.bat"), "w", newline="").write(
        "@echo off\r\nmode con lines=50\r\n"
        "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c dgroup.c > build.log\r\n"
        "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c key.c >> build.log\r\n"
        "E:\\BIN\\TASM.EXE gstub.asm >> build.log\r\n"
        "D:\\BIN\\TLINK.EXE /m @link.rsp >> build.log\r\n"
        "echo LINKERR=%errorlevel% >> build.log\r\n"
        "pause\r\n")
    conf = (
        "[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n"
        "[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + WORK.replace("\\", "\\\\") + "\n"
        "mount d " + os.path.join(ROOT, "tools", "TC30").replace("\\", "\\\\") +
        "\nmount e " + os.path.join(ROOT, "tools", "BC30").replace("\\", "\\\\") +
        "\nc:\ncall b.bat\n")
    cp = os.path.join(ROOT, "tmp", "keyimage.conf")
    open(cp, "w").write(conf)
    subprocess.run(["powershell", "-NoProfile", "-Command",
                    "Get-Process | Where-Object {$_.ProcessName -match 'dosbox'} | "
                    "Stop-Process -Force -ErrorAction SilentlyContinue"],
                   capture_output=True)
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", cp, "--wait", "30"], check=True)
    if not os.path.exists(os.path.join(WORK, "CHK.EXE")):
        raise SystemExit("key link failed; see " + os.path.join(WORK, "build.log"))


def map_symbols():
    text = open(os.path.join(WORK, "CHK.MAP"), encoding="ascii",
                errors="replace").read()
    syms = {}
    for m in re.finditer(r"^\s*([0-9A-Fa-f]{4}):([0-9A-Fa-f]{4})\s+(\S+)",
                         text, re.M):
        seg, ofs, name = int(m.group(1), 16), int(m.group(2), 16), m.group(3)
        syms.setdefault(name.lower(), []).append((seg, ofs))
    return syms


def main():
    keyobj = os.path.join(ROOT, "tmp", "gamebuild_src", "KEY.OBJ")
    if not os.path.exists(keyobj):
        subprocess.run([sys.executable,
                        os.path.join(ROOT, "scripts", "fbov",
                                     "build_game.py")], check=True)
    compile_and_link()
    sys.path.insert(0, os.path.join(ROOT, "scripts", "fbov"))
    import capstone
    import csv

    syms = map_symbols()
    linked_w = syms["_s_w_2410_0251"][0][1]
    prefix = linked_w - 0x0251
    print("link prefix", hex(prefix))

    true_syms = [0x163, 0x164, 0x165, 0x166, 0x167, 0x438, 0x43a, 0x44a,
                 0x7aa, 0x7ab, 0x26df, 0x26e1, 0x899d, 0x899f, 0x251, 0x27a]
    conv = {t + prefix: t for t in true_syms}

    exe = open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()
    import json
    man = json.load(open(os.path.join(ROOT, "doc", "fbov_manifest.json")))
    ov = [x for x in man["overlays"] if x["code_seg"] == OV_SEG][0]
    orig = exe[ov["code_file_offset"]:ov["code_file_offset"] + ov["codesz"]]

    chex = open(os.path.join(WORK, "CHK.EXE"), "rb").read()
    cpar = struct.unpack_from("<H", chex, 8)[0]
    code = bytearray(chex[cpar * 16:cpar * 16 + 0x400])
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)
    md.detail = True
    end = None
    for ins in md.disasm(bytes(code), 0):
        if ins.mnemonic in ("retf", "ret"):
            end = ins.address + ins.size
            break
    if end is None or end > OV_SIZE:
        raise SystemExit("compiled key function does not fit the slot")
    code = code[:end] + b"\x90" * (OV_SIZE - end)

    n = 0
    for ins in md.disasm(bytes(code), 0):
        for op in ins.operands:
            val = None
            off = None
            if op.type == capstone.x86.X86_OP_IMM:
                v = op.imm & 0xFFFF
                if v in conv:
                    val = conv[v]
                    off = ins.encoding.imm_offset
            elif op.type == capstone.x86.X86_OP_MEM:
                v = op.mem.disp & 0xFFFF
                if v in conv:
                    val = conv[v]
                    off = ins.encoding.disp_offset
            if val is not None:
                struct.pack_into("<H", code, ins.address + off, val)
                n += 1
    print("data references patched", n)

    md2 = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)
    ccalls = [x for x in md2.disasm(bytes(code), 0) if x.mnemonic == "lcall"]
    ocalls = [x for x in md2.disasm(orig[OV_OFS:OV_OFS + OV_SIZE], OV_OFS)
              if x.mnemonic == "lcall"]
    if len(ccalls) != len(ocalls):
        raise SystemExit("call count mismatch: %d/%d" %
                         (len(ccalls), len(ocalls)))
    for c, o in zip(ccalls, ocalls):
        code[c.address + 1:c.address + 5] = o.bytes[1:5]
    print("far calls patched", len(ccalls))

    out = os.path.join(ROOT, "tmp", "key_patched.bin")
    open(out, "wb").write(bytes(code))
    print("wrote", out, len(code), "bytes")


if __name__ == "__main__":
    main()
