// Rename functions from a TSV: address-or-name<TAB>newName[<TAB>comment].
//
// The first column is normally a function address; if AddressFactory cannot resolve it to a
// function (overlay segments live in another address space), it is treated as a function name
// and must match exactly one function.
//
// When the renamed function is a thunk target, every thunk whose name is "ovr_<oldName>" is
// renamed to "ovr_<newName>", so the overlay call gates keep tracking their targets.
//
// Args: renames.tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class RenameFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        FunctionManager fm = currentProgram.getFunctionManager();
        int ok = 0, missing = 0, failed = 0, thunks = 0;
        int tx = currentProgram.startTransaction("rename functions");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 2) continue;
                String ref = f[0];
                String newName = f[1].trim();
                Function fn = null;
                Address ad = currentProgram.getAddressFactory().getAddress(ref);
                if (ad != null) fn = fm.getFunctionAt(ad);
                if (fn == null) {
                    List<Function> found = new ArrayList<>();
                    for (Function cand : fm.getFunctions(true))
                        if (cand.getName().equals(ref.trim())) found.add(cand);
                    if (found.size() == 1) {
                        fn = found.get(0);
                        println("BYNAME " + ref + " -> " + fn.getEntryPoint());
                    } else if (found.size() > 1) {
                        println("AMBIG " + ref + " (" + found.size() + ")");
                    }
                }
                if (fn == null) { println("NOFUNC " + ref); missing++; continue; }
                String oldName = fn.getName();
                try {
                    fn.setName(newName, SourceType.USER_DEFINED);
                    if (f.length > 2 && !f[2].isEmpty())
                        fn.setComment(f[2].trim());
                    ok++;
                    // keep "ovr_<target>" thunks in sync with their target
                    String thunkName = "ovr_" + oldName;
                    for (Function cand : fm.getFunctions(true)) {
                        if (cand.getName().equals(thunkName)) {
                            cand.setName("ovr_" + newName, SourceType.USER_DEFINED);
                            thunks++;
                        }
                    }
                } catch (Throwable t) {
                    println("FAIL " + ref + " " + oldName + " -> " + newName + " : " + t);
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("renamed=" + ok + " thunks=" + thunks + " missing=" + missing + " failed=" + failed);
    }
}
