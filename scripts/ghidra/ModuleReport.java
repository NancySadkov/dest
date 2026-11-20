// Report every memory block and the functions it contains, plus the externals
// those functions reference, so a translation-unit topic can be chosen from
// evidence rather than guessed.
// Args: out.tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ModuleReport extends GhidraScript {
    @Override
    public void run() throws Exception {
        String out = getScriptArgs().length > 0 ? getScriptArgs()[0] : "modules.tsv";
        PrintWriter w = new PrintWriter(out, StandardCharsets.UTF_8.name());
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            int nf = 0;
            for (Function f : currentProgram.getFunctionManager().getFunctions(b.getStart(), true)) {
                if (!b.contains(f.getEntryPoint())) break;
                nf++;
            }
            w.println("BLOCK\t" + b.getName() + "\t" + b.getStart() + "\t" + b.getSize()
                    + "\t" + nf);
            for (Function f : currentProgram.getFunctionManager().getFunctions(b.getStart(), true)) {
                if (!b.contains(f.getEntryPoint())) break;
                Set<String> ext = new TreeSet<>();
                for (Function c : f.getCalledFunctions(monitor))
                    if (!b.getAddressRange().contains(c.getEntryPoint())) ext.add(c.getName());
                StringBuilder e = new StringBuilder();
                int i = 0;
                for (String s : ext) { if (i++ > 8) break; e.append(s).append(" "); }
                w.println("FUNC\t" + f.getEntryPoint() + "\t" + f.getBody().getNumAddresses()
                        + "\t" + f.getName() + "\t" + e.toString().trim());
            }
        }
        w.close();
        println("wrote " + out);
    }
}
