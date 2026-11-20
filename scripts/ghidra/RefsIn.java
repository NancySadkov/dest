// List all references TO an address, with reference type and containing function.
// Args: tsv with address<TAB>label
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.List;

public class RefsIn extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        ReferenceManager rm = currentProgram.getReferenceManager();
        FunctionManager fm = currentProgram.getFunctionManager();
        for (String line : lines) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            String[] f = line.split("\t");
            Address at = currentProgram.getAddressFactory().getAddress(f[0]);
            if (at == null) { println("BADADDR " + f[0]); continue; }
            int n = 0;
            StringBuilder sb = new StringBuilder();
            for (Reference r : rm.getReferencesTo(at)) {
                Address from = r.getFromAddress();
                Function host = fm.getFunctionContaining(from);
                sb.append(" [").append(from).append(" ")
                  .append(r.getReferenceType()).append(" ")
                  .append(host == null ? "-" : host.getName()).append("]");
                n++;
            }
            println(f[0] + "\t" + (f.length > 1 ? f[1] : "") + "\trefs=" + n + sb);
        }
    }
}
