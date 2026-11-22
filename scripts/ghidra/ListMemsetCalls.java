// List every call to _fmemset with its containing function and the preceding
// instructions (the pushed arguments).
// Args: outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class ListMemsetCalls extends GhidraScript {
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
        PrintWriter w = new PrintWriter(new FileWriter(a[0]));
        Listing lst = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();
        int n = 0;
        for (Function f : fm.getFunctions(true)) {
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction ins = it.next();
                String mn = ins.getMnemonicString().toUpperCase();
                if (!mn.equals("CALLF") && !mn.equals("CALL")) continue;
                boolean hit = false;
                for (int i = 0; i < ins.getNumOperands() && !hit; i++) {
                    for (Object o : ins.getOpObjects(i)) {
                        if (!(o instanceof Address)) continue;
                        String nm = nameAt((Address) o);
                        if (nm != null && nm.toLowerCase().contains("fmemset")) hit = true;
                    }
                }
                if (!hit) continue;
                w.println("FUNC " + f.getName() + " @ " + f.getEntryPoint());
                w.println("  CALL " + ins.getAddress() + "  " + ins.toString());
                Instruction p = ins.getPrevious();
                for (int i = 0; i < 10 && p != null; i++) {
                    w.println("    " + p.getAddress() + "  " + p.toString());
                    p = p.getPrevious();
                }
                n++;
            }
        }
        w.println("TOTAL " + n);
        w.close();
    }
}
