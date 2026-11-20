// Delete a function at an address (used to remove false interior entries that split a body).
// Args: tsv with address<TAB>name  (name is only for the log)
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.List;

public class DeleteFunc extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        int ok = 0, missing = 0;
        FunctionManager fm = currentProgram.getFunctionManager();
        int tx = currentProgram.startTransaction("delete functions");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t");
                Address at = currentProgram.getAddressFactory().getAddress(f[0]);
                Function fn = at == null ? null : fm.getFunctionAt(at);
                if (fn == null) { println("NOFUNC " + f[0]); missing++; continue; }
                String nm = fn.getName();
                fm.removeFunction(at);
                println("deleted " + nm + " @ " + f[0]);
                ok++;
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("deleted=" + ok + " missing=" + missing);
    }
}
