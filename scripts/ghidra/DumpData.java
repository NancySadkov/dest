// Dump bytes for a list of address/count pairs (TSV: address<TAB>count).
// Args: tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class DumpData extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        for (String line : lines) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            String[] f = line.split("\t", -1);
            Address addr = currentProgram.getAddressFactory().getAddress(f[0]);
            int n = f.length > 1 ? Integer.decode(f[1]) : 16;
            if (addr == null) { println(f[0] + " BADADDR"); continue; }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                try {
                    byte b = currentProgram.getMemory().getByte(addr.add(i));
                    sb.append(String.format("%02X ", b & 0xff));
                } catch (Exception e) {
                    sb.append("?? ");
                }
            }
            StringBuilder words = new StringBuilder();
            for (int i = 0; i + 1 < n; i += 2) {
                try {
                    short w = currentProgram.getMemory().getShort(addr.add(i));
                    words.append(String.format("%04X ", w & 0xffff));
                } catch (Exception e) {
                    words.append("???? ");
                }
            }
            println(f[0] + " [" + n + "] " + sb.toString().trim() + "   || words: " + words.toString().trim());
        }
    }
}
