// Remove every symbol at an address and undefine the byte there.
// Args: tsv with address[<TAB>anything]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class UndefineAt extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        SymbolTable st = currentProgram.getSymbolTable();
        int ok = 0;
        int tx = currentProgram.startTransaction("undefine");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                Address ad = currentProgram.getAddressFactory().getAddress(line.split("\t")[0]);
                if (ad == null) continue;
                Symbol[] syms = st.getSymbols(ad);
                for (Symbol s : syms) st.removeSymbolSpecial(s);
                clearListing(ad, ad);
                ok++;
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("undefined=" + ok);
    }
}
