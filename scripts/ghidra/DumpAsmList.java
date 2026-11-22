// Dump disassembly of several functions in one headless run.
// Args: addr outfile [addr outfile ...]
// Call/jump targets are annotated with their symbol names, like DumpAsmNamed.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class DumpAsmList extends GhidraScript {
    private String nameAt(Address a) {
        if (a == null) return null;
        Function f = currentProgram.getFunctionManager().getFunctionAt(a);
        if (f == null) f = currentProgram.getFunctionManager().getFunctionContaining(a);
        if (f != null) return f.getName();
        Symbol s = currentProgram.getSymbolTable().getPrimarySymbol(a);
        return s == null ? null : s.getName();
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        for (int k = 0; k + 1 < args.length; k += 2) {
            String addr = args[k];
            String out = args[k + 1];
            Address start = currentProgram.getAddressFactory().getAddress(addr);
            Function f = currentProgram.getFunctionManager().getFunctionAt(start);
            if (f == null) { println("no function at " + addr); continue; }
            PrintWriter w = new PrintWriter(new FileWriter(out));
            Listing lst = currentProgram.getListing();
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction ins = it.next();
                StringBuilder b = new StringBuilder();
                b.append(ins.getAddress()).append("  ");
                b.append(ins.toString());
                String mn = ins.getMnemonicString().toUpperCase();
                if (mn.equals("CALLF") || mn.startsWith("J") || mn.equals("CALL")) {
                    for (int i = 0; i < ins.getNumOperands(); i++) {
                        for (Object o : ins.getOpObjects(i)) {
                            if (o instanceof Address) {
                                String n = nameAt((Address) o);
                                if (n != null) b.append("   ; ").append(n);
                            }
                        }
                    }
                }
                w.println(b.toString());
            }
            w.close();
            println("wrote " + out + " for " + f.getName());
        }
    }
}
