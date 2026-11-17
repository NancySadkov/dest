// Apply global renames from a TSV (address<TAB>newName[<TAB>comment]).
// The old name is looked up at the address; only label symbols are renamed.
//
// Args: renames.tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class Rename extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        if (a.length < 1) { println("usage: Rename <tsv>"); return; }
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        SymbolTable st = currentProgram.getSymbolTable();
        int ok = 0, missing = 0, failed = 0;
        int tx = currentProgram.startTransaction("rename globals");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t");
                if (f.length < 2) continue;
                Address ad = currentProgram.getAddressFactory().getAddress(f[0]);
                if (ad == null) { missing++; continue; }
                Symbol s = st.getPrimarySymbol(ad);
                if (s == null) { missing++; continue; }
                try {
                    s.setName(f[1], SourceType.USER_DEFINED);
                    ok++;
                } catch (Exception e) {
                    println("FAIL " + f[0] + " " + s.getName() + " -> " + f[1] + " : " + e);
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("renamed=" + ok + " missing=" + missing + " failed=" + failed);
    }
}
