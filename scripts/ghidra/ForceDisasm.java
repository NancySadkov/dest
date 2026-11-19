// Clear a data range and disassemble it as code.
// Args: TSV with start<TAB>end (end exclusive); multiple rows allowed.
// Prints the decoded instructions and any byte not covered by an instruction.
//@category DeSt
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ForceDisasm extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        int tx = currentProgram.startTransaction("force disasm");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t");
                Address start = currentProgram.getAddressFactory().getAddress(f[0]);
                Address end = currentProgram.getAddressFactory().getAddress(f[1]);
                if (start == null || end == null) { println("BAD " + line); continue; }
                Address last = end.subtract(1);
                clearListing(start, last);
                DisassembleCommand cmd = new DisassembleCommand(new AddressSet(start, last), null, true);
                cmd.applyTo(currentProgram, monitor);
                Listing lst = currentProgram.getListing();
                Address cur = start;
                int n = 0, holes = 0;
                StringBuilder sb = new StringBuilder();
                while (cur.compareTo(end) < 0) {
                    Instruction ins = lst.getInstructionAt(cur);
                    if (ins == null) { holes++; sb.append(" HOLE@").append(cur); cur = cur.add(1); continue; }
                    if (n < 12) sb.append("  ").append(ins.getAddress()).append(" ").append(ins);
                    n++;
                    cur = ins.getMaxAddress().add(1);
                }
                println("range " + start + "-" + end + " instr=" + n + " holes=" + holes + sb);
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
