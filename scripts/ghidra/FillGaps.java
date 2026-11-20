// Disassemble pre-validated gaps without following flow (no function creation side effects).
// Args: tsv with start<TAB>end (inclusive)
//@category DeSt
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class FillGaps extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        int tx = currentProgram.startTransaction("fill gaps");
        int ok = 0, fail = 0;
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t");
                Address s = currentProgram.getAddressFactory().getAddress(f[0]);
                Address e = currentProgram.getAddressFactory().getAddress(f[1]);
                if (s == null || e == null) { fail++; continue; }
                clearListing(s, e);
                DisassembleCommand cmd = new DisassembleCommand(new AddressSet(s, e), null, false);
                cmd.applyTo(currentProgram, monitor);
                ok++;
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("filled=" + ok + " failed=" + fail);
    }
}
