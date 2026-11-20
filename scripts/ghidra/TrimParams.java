// Remove trailing parameters from a function whose call sites prove how many arguments are pushed.
// Args: tsv with address<TAB>keepCount
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class TrimParams extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        int ok = 0, failed = 0;
        int tx = currentProgram.startTransaction("trim parameters");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t");
                Address addr = currentProgram.getAddressFactory().getAddress(f[0]);
                Function fn = addr == null ? null : currentProgram.getFunctionManager().getFunctionAt(addr);
                if (fn == null) { println("NOFUNC " + f[0]); failed++; continue; }
                int keep = Integer.parseInt(f[1].trim());
                int before = fn.getParameterCount();
                while (fn.getParameterCount() > keep) {
                    fn.removeParameter(fn.getParameterCount() - 1);
                }
                fn.setSignatureSource(SourceType.USER_DEFINED);
                ok++;
                println("trimmed " + fn.getName() + " " + before + " -> " + fn.getParameterCount());
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("trimmed=" + ok + " failed=" + failed);
    }
}
