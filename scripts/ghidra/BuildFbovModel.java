// Build the original Borland FBOV memory model in a fresh Ghidra program.
//
// Usage (headless, after importing a tiny placeholder binary):
//   -postScript BuildFbovModel.java <STRONG.EXE> <doc_dir>
//
// The manifest CSVs are produced by scripts/fbov/model.py.
//
// This script creates the segment blocks from the original file, applies the
// FBOV fixups with the correct STATIC segment (the 0x1000 base that mzap
// omitted), untraps the overlay trampolines, creates MZ relocation
// references, and sets DS/ES/SS to the original static data/stack segments.
//
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.lang.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.math.BigInteger;
import java.nio.file.*;
import java.util.*;

public class BuildFbovModel extends GhidraScript {

    static final int STATIC_BASE = 0x1000;
    static final int DGROUP_SEG = 0x2410;
    static final int OVRDATA_SEG = 0x225D;
    static final int STACK_SEG = 0x2D5A;

    private static class SegRow {
        int seg, staticSeg, min, max, flags;
        String cls;
    }

    private static class OvRow {
        int headerSeg, headerStatic, codeSeg, codeDisp, fileOffset, codesz, jmpcnt;
    }

    private static class FixRow {
        int headerStatic, codeSeg, siteOfs, flags, targetSeg, tramp;
        boolean funref;
    }

    private static class RelRow {
        int seg, ofs, target;
    }

    private static class BlockRow {
        String name, kind, cls;
        int staticSeg, start, size, fileOffset, initialized, initSize;
    }

    private String[] split(String line) {
        return line.split(",", -1);
    }

    private int hex(String s) {
        s = s.trim();
        if (s.isEmpty()) return 0;
        if (s.startsWith("0x") || s.startsWith("0X")) s = s.substring(2);
        return Integer.parseInt(s, 16);
    }

    private List<String> readLines(String path) throws IOException {
        List<String> out = new ArrayList<>();
        BufferedReader r = Files.newBufferedReader(Paths.get(path));
        String ln;
        while ((ln = r.readLine()) != null) {
            if (ln.trim().isEmpty()) continue;
            out.add(ln);
        }
        r.close();
        return out;
    }

    private Address addr(int seg, int ofs) {
        return currentProgram.getAddressFactory().getAddress(
                String.format("%04X:%04X", seg & 0xFFFF, ofs & 0xFFFF));
    }

    private void put16(Address a, int v) throws Exception {
        byte[] b = { (byte) (v & 0xFF), (byte) ((v >> 8) & 0xFF) };
        currentProgram.getMemory().setBytes(a, b);
    }

    private int get16(Address a) throws Exception {
        byte[] b = new byte[2];
        currentProgram.getMemory().getBytes(a, b);
        return (b[0] & 0xFF) | ((b[1] & 0xFF) << 8);
    }

    private void createBlock(String name, Address start, byte[] file, int fileOff,
                             int size, boolean exec, boolean write) throws Exception {
        if (size <= 0) return;
        if (start == null) return;
        Memory mem = currentProgram.getMemory();
        if (mem.getBlock(start) != null) {
            println("SKIP overlapping block " + name + " at " + start);
            return;
        }
        if (fileOff < 0 || fileOff + size > file.length) {
            println("SKIP out-of-file block " + name + " off=0x"
                    + Integer.toHexString(fileOff) + " size=0x"
                    + Integer.toHexString(size));
            return;
        }
        ByteArrayInputStream bis = new ByteArrayInputStream(file, fileOff, size);
        MemoryBlock b = mem.createInitializedBlock(name, start, bis, size,
                monitor, false);
        b.setRead(true);
        b.setWrite(write);
        b.setExecute(exec);
        try { createLabel(start, name, true); } catch (Exception e) { }
    }

    private void createUninitBlock(String name, Address start, int size,
                                   boolean write) throws Exception {
        if (size <= 0) return;
        Memory mem = currentProgram.getMemory();
        if (mem.getBlock(start) != null) {
            println("SKIP overlapping uninit block " + name + " at " + start);
            return;
        }
        MemoryBlock b = mem.createUninitializedBlock(name, start, size, false);
        b.setRead(true);
        b.setWrite(write);
        b.setExecute(false);
        try { createLabel(start, name, true); } catch (Exception e) { }
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("usage: BuildFbovModel.java <STRONG.EXE> <doc_dir>");
            return;
        }
        byte[] file = Files.readAllBytes(Paths.get(args[0]));
        String doc = args[1];

        int cparhdr = (file[8] & 0xFF) | ((file[9] & 0xFF) << 8);
        int startOfs = cparhdr * 16;

        // ---- read manifest -------------------------------------------------
        List<SegRow> segs = new ArrayList<>();
        for (String ln : readLines(Paths.get(doc, "fbov_segments.csv").toString())) {
            if (ln.startsWith("index")) continue;
            String[] c = split(ln);
            SegRow s = new SegRow();
            s.seg = hex(c[1]);
            s.staticSeg = hex(c[2]);
            s.min = hex(c[3]);
            s.max = hex(c[4]);
            s.flags = Integer.parseInt(c[5].trim());
            s.cls = c[6].trim();
            segs.add(s);
        }

        List<OvRow> ovs = new ArrayList<>();
        for (String ln : readLines(Paths.get(doc, "fbov_overlays.csv").toString())) {
            if (ln.startsWith("header_seg")) continue;
            String[] c = split(ln);
            OvRow o = new OvRow();
            o.headerSeg = hex(c[0]);
            o.headerStatic = hex(c[1]);
            o.codeSeg = hex(c[2]);
            o.codeDisp = hex(c[4]);
            o.fileOffset = hex(c[5]);
            o.codesz = hex(c[6]);
            o.jmpcnt = Integer.parseInt(c[8].trim());
            ovs.add(o);
        }

        List<FixRow> fixes = new ArrayList<>();
        for (String ln : readLines(Paths.get(doc, "fbov_fixups.csv").toString())) {
            if (ln.startsWith("header_seg")) continue;
            String[] c = split(ln);
            FixRow f = new FixRow();
            f.headerStatic = hex(c[1]);
            f.codeSeg = hex(c[2]);
            f.siteOfs = hex(c[3]);
            f.flags = Integer.parseInt(c[4].trim());
            f.targetSeg = hex(c[6]);
            f.funref = c[8].trim().equals("1");
            f.tramp = c.length > 9 && !c[9].trim().isEmpty() ? hex(c[9]) : -1;
            fixes.add(f);
        }

        List<BlockRow> blocks = new ArrayList<>();
        for (String ln : readLines(Paths.get(doc, "fbov_blocks.csv").toString())) {
            if (ln.startsWith("name")) continue;
            String[] c = split(ln);
            BlockRow b = new BlockRow();
            b.name = c[0];
            b.kind = c[1];
            b.staticSeg = hex(c[2]);
            b.start = hex(c[3]);
            b.size = hex(c[4]);
            b.fileOffset = hex(c[5]);
            b.initialized = Integer.parseInt(c[6].trim());
            b.initSize = hex(c[7]);
            b.cls = c[8];
            blocks.add(b);
        }

        List<RelRow> rels = new ArrayList<>();
        for (String ln : readLines(Paths.get(doc, "fbov_relocs.csv").toString())) {
            if (ln.startsWith("index")) continue;
            String[] c = split(ln);
            if (c.length < 6 || c[5].trim().isEmpty()) continue;
            RelRow r = new RelRow();
            r.seg = hex(c[1]);
            r.ofs = hex(c[2]);
            r.target = hex(c[5]); // static target
            rels.add(r);
        }

        int tx = currentProgram.startTransaction("Build FBOV model");
        try {
            Map<Integer, Integer> segStart = new TreeMap<>();
            int nblocks = 0;
            int ncode = 0;
            for (BlockRow b : blocks) {
                if (b.size <= 0) continue;
                boolean exec = b.cls.equals("CODE") || b.cls.equals("OVR");
                boolean write = b.cls.equals("DATA") || b.cls.equals("BSS");
                if (b.initialized == 0) {
                    createUninitBlock(b.name, addr(b.staticSeg, b.start),
                            b.size, write);
                    nblocks++;
                } else {
                    createBlock(b.name, addr(b.staticSeg, b.start), file,
                            b.fileOffset, b.initSize, exec, write);
                    nblocks++;
                    if (b.size > b.initSize) {
                        int rem = b.size - b.initSize;
                        Address ba = addr(b.staticSeg, b.start + b.initSize);
                        createUninitBlock(b.name + "_BSS", ba, rem, write);
                    }
                }
                if (!segStart.containsKey(b.staticSeg)
                        || b.start < segStart.get(b.staticSeg))
                    segStart.put(b.staticSeg, b.start);
                if (b.kind.equals("overlay_code")) ncode++;
            }

            // ---- overlay trampolines -------------------------------------
            // __OvrUntrapJmps: botrp_t -> EA <ofs+cdisp> <code_seg>
            int ntramp = 0;
            for (OvRow o : ovs) {
                boolean ok = true;
                for (int j = 0; j < o.jmpcnt; j++) {
                    Address t = addr(o.headerStatic, 0x20 + j * 5);
                    if (currentProgram.getMemory().getBlock(t) == null) { ok = false; break; }
                }
                if (!ok) continue;
                for (int j = 0; j < o.jmpcnt; j++) {
                    Address t = addr(o.headerStatic, 0x20 + j * 5);
                    int ofs = get16(t.add(2));
                    byte[] b = { (byte) 0xEA,
                                 (byte) ((ofs + o.codeDisp) & 0xFF),
                                 (byte) (((ofs + o.codeDisp) >> 8) & 0xFF),
                                 (byte) (o.codeSeg & 0xFF),
                                 (byte) ((o.codeSeg >> 8) & 0xFF) };
                    currentProgram.getMemory().setBytes(t, b);
                    ntramp++;
                }
            }

            // ---- FBOV fixups ---------------------------------------------
            // Replace the encoded sf with the true STATIC segment.
            int nfix = 0;
            for (FixRow f : fixes) {
                Address site = addr(f.codeSeg, f.siteOfs);
                if (currentProgram.getMemory().getBlock(site) == null) continue;
                if (f.targetSeg == 0) continue;
                put16(site, f.targetSeg);
                if (f.funref && f.tramp >= 0) put16(site.add(4), f.tramp);
                nfix++;
            }

            // ---- MZ relocation references --------------------------------
            // The file stores load-module-relative segments (0x1410 for
            // DGROUP); rewrite them to the static segment (0x2410) and add
            // the corresponding reference.
            int nrel = 0;
            int nskip = 0;
            ReferenceManager rm = currentProgram.getReferenceManager();
            for (RelRow r : rels) {
                Address site = addr(STATIC_BASE + r.seg, r.ofs);
                if (currentProgram.getMemory().getBlock(site) == null) {
                    nskip++;
                    continue;
                }
                if (r.target == 0) {
                    nskip++;
                    continue;
                }
                put16(site, r.target);
                int tmin = segStart.getOrDefault(r.target, 0);
                Address target = addr(r.target, tmin);
                if (currentProgram.getMemory().getBlock(target) == null) {
                    nskip++;
                    continue;
                }
                try {
                    rm.addMemoryReference(site, target, RefType.DATA,
                            SourceType.USER_DEFINED, 0);
                    nrel++;
                } catch (Exception e) { }
            }

            // ---- segment registers --------------------------------------
            ProgramContext ctx = currentProgram.getProgramContext();
            Register ds = ctx.getRegister("DS");
            Register es = ctx.getRegister("ES");
            Register ss = ctx.getRegister("SS");
            Address min = currentProgram.getMemory().getMinAddress();
            Address max = currentProgram.getMemory().getMaxAddress();
            if (ds != null) ctx.setRegisterValue(min, max,
                    new RegisterValue(ds, BigInteger.valueOf(DGROUP_SEG)));
            if (es != null) ctx.setRegisterValue(min, max,
                    new RegisterValue(es, BigInteger.valueOf(DGROUP_SEG)));
            if (ss != null) ctx.setRegisterValue(min, max,
                    new RegisterValue(ss, BigInteger.valueOf(STACK_SEG)));

            println("BLOCKS segments=" + nblocks + " overlay_code=" + ncode);
            println("TRAMPOLINES untrapped=" + ntramp);
            println("FIXUPS applied=" + nfix + " of " + fixes.size());
            println("MZ reloc references=" + nrel + " of " + rels.size()
                    + " skipped=" + nskip);
            println("CONTEXT DS=ES=0x2410 SS=0x2D5A");
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
