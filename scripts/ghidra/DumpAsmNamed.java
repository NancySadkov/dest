// Dump disassembly of a function with call/jump targets resolved to names.
// Args: address outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class DumpAsmNamed extends GhidraScript {
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
        String[] a = getScriptArgs();
        Address start = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(start);
        if (f == null) { println("no function"); return; }
        PrintWriter w = new PrintWriter(new FileWriter(a[1]));
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
        println("wrote " + a[1]);
    }
}
