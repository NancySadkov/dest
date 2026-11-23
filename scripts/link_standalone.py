"""Attempt a first link of the recovered tree and report what is missing.

Runs TLINK in DOSBox over every staged .obj with Turbo C's large-model startup
(c0l) and libraries, then prints the linker's error list.  This is the step that
turns "58/58 modules compile" into a concrete list of what still separates us
from a runnable REBUILT.EXE.
"""
import os
import re
import struct
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
BUILDSRC = os.path.join(ROOT, "tmp", "buildsrc")
TC = os.path.join(ROOT, "tools", "BC30")   # TLINK + libs from BC++ 3.0


def add_missing_relocations(exe, mapf):
    """Relocate far transfers whose segment word TLINK left unrelocated.

    With -V (VROOMM) TLINK encodes cross-segment calls as VROOMM fixups and
    omits the DOS relocation, expecting the overlay manager to patch them at
    startup.  Our startup never initialises it, so those calls jump to segment 0
    (the interrupt vector table) and the program hangs.  This appends the missing
    (offset, 0) entries so the DOS loader adds the load segment.

    Returns the number of entries added.
    """
    import struct
    b = bytearray(open(exe, "rb").read())
    img = struct.unpack("<H", b[8:10])[0] * 16
    nrel = struct.unpack("<H", b[6:8])[0]
    relofs = struct.unpack("<H", b[0x18:0x1a])[0]
    # Existing relocations, as the linear address of the word they patch.  TLINK
    # emits (offset-within-segment, segment-paragraph) pairs, so the raw offset
    # field is NOT the image offset: comparing raw offsets made this pass add a
    # second entry for words TLINK had already relocated, and DOS then added the
    # load base twice - every such far call landed at 2*loadbase+seg and hung.
    rel = set()
    for i in range(nrel):
        o, s = struct.unpack("<HH", b[relofs + 4 * i: relofs + 4 * i + 4])
        rel.add(s * 16 + o)

    # segment table: paragraph -> (start, length, class)
    segs = {}
    for line in open(mapf, encoding="latin-1", errors="replace"):
        m = re.match(r"^\s*([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+(\S+)\s+(\S+)", line)
        if m:
            start, length = int(m.group(1), 16), int(m.group(3), 16)
            segs[start >> 4] = (start, length, m.group(5))

    code = list(segs.items())
    ranges = [(s, s + l) for p, (s, l, c) in code if c == "CODE" and l]

    # instruction starts, when a disassembler is available
    starts = None
    try:
        import capstone
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)
        starts = set()
        for s, l, c in segs.values():
            if c != "CODE" or not l:
                continue
            for ins in md.disasm(bytes(b[img + s:img + s + l]), s):
                starts.add(ins.address)
    except Exception:
        starts = None

    hits = []
    body = b[img:]
    for i in range(len(body) - 5):
        if body[i] not in (0x9A, 0xEA):
            continue
        if starts is not None and i not in starts:
            continue
        off, seg = struct.unpack("<HH", body[i + 1:i + 5])
        if seg not in segs:
            continue
        tstart, tlen, tclass = segs[seg]
        # Overlay call thunks jump into STUBSEG segments (O01_SEG, O09_SEG, ...);
        # those targets need the same relocation as resident CODE ones.
        if tclass not in ("CODE", "STUBSEG") or off >= tlen:
            continue
        if not any(s <= i < e for s, e in ranges):
            continue
        if (i + 3) in rel:
            continue
        rel.add(i + 3)
        hits.append(i + 3)
    if not hits:
        return 0

    # e_cp/e_cblp describe the *resident load image*, not the file size: the
    # tail of the file holds the overlay segments.  Only the header growth is
    # added to the load image.
    need = 4 * len(hits)
    spare = img - (relofs + 4 * nrel)
    grow = 0 if need <= spare else ((need - spare + 15) // 16) * 16
    old_load = (struct.unpack("<H", b[4:6])[0] - 1) * 512 + struct.unpack("<H", b[2:4])[0]
    head = bytearray(b[:relofs])
    table = b[relofs:relofs + 4 * nrel]
    table += b"".join(struct.pack("<HH", o, 0) for o in hits)
    table += b"\0" * (grow + spare - need)
    image = bytes(b[img:])
    new_img = relofs + len(table)
    new_img = (new_img + 15) // 16 * 16
    table += b"\0" * (new_img - (relofs + len(table)))
    out = bytearray(head + table + image)
    struct.pack_into("<H", out, 6, nrel + len(hits))          # e_crlc
    struct.pack_into("<H", out, 8, new_img // 16)             # e_cparhdr
    load = old_load + (new_img - img)                         # resident image
    struct.pack_into("<H", out, 4, (load + 511) // 512)       # e_cp
    struct.pack_into("<H", out, 2, load - ((load - 1) // 512) * 512)  # e_cblp
    open(exe, "wb").write(out)
    return len(hits)


def main():
    skip = set(a.upper() for a in sys.argv[1:] if a.startswith("--skip=") is False)
    objs = sorted(n for n in os.listdir(BUILDSRC) if n.lower().endswith(".obj"))
    # EXCLUDE_OBJS=OVL.OBJ,OVR.OBJ lets the overlay experiments drop modules
    # compiler machinery is provided by the toolchain, not by our recovery
    DEFAULT_EXCLUDE = "OVL.OBJ"
    _excl = [x.strip().upper() for x in
             (os.environ.get("EXCLUDE_OBJS", DEFAULT_EXCLUDE)).split(",")
             if x.strip()]
    if _excl:
        objs = [o for o in objs if o.upper() not in _excl]
        print("excluding:", ", ".join(_excl))
    # Our tree contains a recovered CRT (crtl.c).  Linking Turbo C's C0L startup
    # and CL.LIB as well duplicates it, so the first link excludes the recovered
    # CRT object and lets the library provide those symbols.
    # The recovered CRT (crtl.c) is the program's own runtime, so it is linked by
    # default; --without-crtl reproduces the older, startup-only link.
    if "--without-crtl" in sys.argv:
        objs = [o for o in objs if o.upper() != "CRTL.OBJ"]
    print("objects:", len(objs), "(crtl excluded)" if "--without-crtl" in sys.argv else "")
    bat = ["@echo off", "set PATH=D:\\BIN", "set LIB=D:\\LIB"]
    # TLINK syntax: <objs>,<exe>,<map>,<libs>  -- the comma after the last object
    # is what separates inputs from outputs
    # printf("%f") pulls in the floating-point printer, which needs the emulator
    # library; without it TLINK reports a fixup overflow on __REALCVT.
    # C0M is the medium-model startup and must match -mm on the objects
    # (C0L is the large-model one).
    # Resident: the startup, the recovered CRT, the drivers, the globals and the
    # overlay thunks.  Everything else (the recovered game modules O01..O50) becomes
    # an overlay - TLINK's /o applies to the modules that follow it.
    RESIDENT = ("CRTL.OBJ", "MAIN.OBJ", "MOUSE.OBJ", "VIDEO.OBJ", "OVL.OBJ",
                "STUBS.OBJ", "INTRINS.OBJ", "OVR.OBJ")
    def is_resident(n):
        u = n.upper()
        return u in RESIDENT or u.startswith("GLOB")

    res = [o for o in objs if is_resident(o)]
    ovl = [o for o in objs if not is_resident(o)]
    # C0M.OBJ supplies the startup's data symbols (_psp, errno, _StartTime, the
    # heap variables, _terminate) that CM.LIB and OVERLAY.LIB expect.  The
    # original's entry is startx (CRTL), not C0's _startup, so the linked EXE's
    # entry is moved to _STARTX below.
    rsp = ("D:\\LIB\\C0M.OBJ " + " ".join(res) + " /o " + " ".join(ovl) +
           " /m /s" + ",REBUILT.EXE,REBUILT.MAP,D:\\LIB\\OVERLAY.LIB D:\\LIB\\CM.LIB")
    if os.environ.get("NO_OVERLAY"):
        # Ordinary (non-VROOMM) link: TLINK emits normal relocations for every
        # far call and the game modules become resident segments.  VROOMM's
        # runtime cannot bootstrap in this rebuild (doc/step6_entry.md), so the
        # overlay machinery is dropped entirely.
        rsp = ("D:\\LIB\\C0M.OBJ " + " ".join(res) + " " + " ".join(ovl) +
               " /m /s" + ",REBUILT.EXE,REBUILT.MAP,D:\\LIB\\CM.LIB")
    with open(os.path.join(BUILDSRC, "LINK.RSP"), "w", encoding="ascii",
              newline="\r\n") as f:
        f.write(rsp + "\n")
    bat.append("D:\\BIN\\TLINK.EXE @LINK.RSP > LINK.LOG")
    if os.path.exists(os.path.join(BUILDSRC, "LINK.LOG")):
        os.remove(os.path.join(BUILDSRC, "LINK.LOG"))
    for name in ("REBUILT.EXE", "REBUILT.MAP", "DONE.FLG"):
        p = os.path.join(BUILDSRC, name)
        if os.path.exists(p):
            os.remove(p)
    bat.append("echo done > DONE.FLG")
    with open(os.path.join(BUILDSRC, "LINK.BAT"), "w", encoding="ascii",
              newline="\r\n") as f:
        f.write("\n".join(bat) + "\n")

    conf = [
        "[sdl]", "output = surface",
        "[dosbox]", "machine = svga_s3", "memsize = 16",
        "[cpu]", "core = normal", "cputype = 386", "cycles = max",
        "[mixer]", "nosound = true",
        "[autoexec]",
        "mount c " + BUILDSRC,
        "mount d " + TC,
        "mount e " + os.path.join(ROOT, "tools", "BC30"),
        "c:",
        "call LINK.BAT",
        "exit",
    ]
    path = os.path.join(ROOT, "tmp", "link.conf")
    with open(path, "w", encoding="ascii", newline="\r\n") as f:
        f.write("\n".join(conf) + "\n")

    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", path, "--until",
                    os.path.join(BUILDSRC, "DONE.FLG"), "--wait", "180"],
                   check=False)

    log = os.path.join(BUILDSRC, "LINK.LOG")
    if os.path.exists(log):
        text = open(log, encoding="ascii", errors="replace").read()
        errors = [l for l in text.splitlines() if "rror" in l or "ndefined" in l]
        print("--- LINK.LOG:", len(errors), "error/undefined lines")
        for line in errors[:20]:
            print("   ", line.strip()[:110])
        for line in text.splitlines()[-6:]:
            print("   ", line.strip()[:110])
    exe = os.path.join(BUILDSRC, "REBUILT.EXE")
    mapf = os.path.join(BUILDSRC, "REBUILT.MAP")
    if os.path.exists(exe) and os.path.exists(mapf):
        n = 0 if os.environ.get("NO_RELOC_FIX") else add_missing_relocations(exe, mapf)
        print("relocations added for cross-segment far transfers:", n)
        m = re.search(r"^\s*([0-9A-F]{4}):([0-9A-F]{4})\s+(?:idle\s+)?_STARTX\s*$",
                      open(mapf, encoding="latin-1", errors="replace").read(), re.M)
        if m:
            cs, ip = int(m.group(1), 16), int(m.group(2), 16)
            with open(exe, "r+b") as f:
                f.seek(0x14)
                f.write(struct.pack("<HH", ip, cs))
            print("entry patched to _STARTX %04X:%04X" % (cs, ip))
        else:
            print("WARNING: _STARTX not found in the map; entry left at C0's _startup")
    print("REBUILT.EXE exists:", os.path.exists(exe),
          os.path.getsize(exe) if os.path.exists(exe) else "")


main()
