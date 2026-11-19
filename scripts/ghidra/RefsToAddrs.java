// For each address in a TSV (first column = address), list all references in the program.
// Prints: address <TAB> refcount <TAB> fromAddress(functionName) ...
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class RefsToAddrs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        ReferenceManager rm = currentProgram.getReferenceManager();
        FunctionManager fm = currentProgram.getFunctionManager();
        for (String line : lines) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#") || line.startsWith("address\t")) continue;
            String[] f = line.split("\t");
            Address ad = currentProgram.getAddressFactory().getAddress(f[0]);
            if (ad == null) { println("BADADDR " + f[0]); continue; }
            StringBuilder sb = new StringBuilder();
            int n = 0;
            for (Reference r : rm.getReferencesTo(ad)) {
                n++;
                if (n <= 8) {
                    Address from = r.getFromAddress();
                    Function fn = fm.getFunctionContaining(from);
                    sb.append(" ").append(from).append("(")
                      .append(fn == null ? "-" : fn.getName()).append(")");
                }
            }
            println(f[0] + "\t" + f[1] + "\t" + n + "\t" + sb.toString().trim());
        }
    }
}
