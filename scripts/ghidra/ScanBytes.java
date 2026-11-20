// Search every memory block for raw byte patterns (finds accesses even in undecoded bytes).
// Args: tsv with  label<TAB>hexbytes (e.g. "mov al,[0x897a]<TAB>A07A89")
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ScanBytes extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        Memory mem = currentProgram.getMemory();
        for (String line : lines) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            String[] f = line.split("\t");
            if (f.length < 2) continue;
            String hex = f[1].replace(" ", "");
            byte[] pat = new byte[hex.length() / 2];
            for (int i = 0; i < pat.length; i++)
                pat[i] = (byte) Integer.parseInt(hex.substring(i * 2, i * 2 + 2), 16);
            int hits = 0;
            StringBuilder sb = new StringBuilder();
            for (MemoryBlock b : mem.getBlocks()) {
                if (!b.isInitialized() || !b.isLoaded()) continue;
                Address start = b.getStart(), end = b.getEnd();
                // walk byte by byte inside the block
                for (Address ad = start; ad != null && ad.compareTo(end) <= 0; ad = ad.next()) {
                    boolean ok = true;
                    for (int i = 0; i < pat.length; i++) {
                        Address x = ad.add(i);
                        if (x == null || x.compareTo(end) > 0) { ok = false; break; }
                        if (mem.getByte(x) != pat[i]) { ok = false; break; }
                    }
                    if (ok) {
                        hits++;
                        if (hits <= 6) sb.append(" ").append(ad);
                    }
                }
            }
            println(f[0] + "\tpattern=" + hex + "\thits=" + hits + sb);
        }
    }
}
