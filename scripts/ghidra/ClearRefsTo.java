// Remove every reference TO an address and all its symbols.
// Args: tsv with address
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ClearRefsTo extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        ReferenceManager rm = currentProgram.getReferenceManager();
        SymbolTable st = currentProgram.getSymbolTable();
        int refs = 0, syms = 0;
        int tx = currentProgram.startTransaction("clear refs to");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                Address ad = currentProgram.getAddressFactory().getAddress(line.split("\t")[0]);
                if (ad == null) continue;
                for (Reference r : rm.getReferencesTo(ad)) { rm.delete(r); refs++; }
                for (Symbol s : st.getSymbols(ad)) { st.removeSymbolSpecial(s); syms++; }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("refsRemoved=" + refs + " symsRemoved=" + syms);
    }
}
