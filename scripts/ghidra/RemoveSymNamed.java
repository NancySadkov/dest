// Remove a symbol with a given name at an address (primary or secondary).
// Args: address<TAB>name  (one per line, TSV)
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class RemoveSymNamed extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        SymbolTable st = currentProgram.getSymbolTable();
        int ok = 0, missing = 0;
        int tx = currentProgram.startTransaction("remove named symbols");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t");
                Address ad = currentProgram.getAddressFactory().getAddress(f[0]);
                if (ad == null) { println("BADADDR " + f[0]); missing++; continue; }
                boolean found = false;
                for (Symbol s : st.getSymbols(ad)) {
                    if (s.getName().equals(f[1])) {
                        st.removeSymbolSpecial(s);
                        found = true; ok++;
                    }
                }
                if (!found) { println("NOSYM " + f[0] + " " + f[1]); missing++; }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("removed=" + ok + " missing=" + missing);
    }
}
