// List the instructions of the function containing an address. Args: address [maxCount]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class ListInsn extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address addr = currentProgram.getAddressFactory().getAddress(a[0]);
        if (addr == null) { println("BADADDR " + a[0]); return; }
        FunctionManager fm = currentProgram.getFunctionManager();
        Function fn = fm.getFunctionContaining(addr);
        if (fn == null) { println("NOFUNC " + a[0]); return; }
        int max = a.length > 1 ? Integer.parseInt(a[1]) : 400;
        println("FUNC " + fn.getName() + " @ " + fn.getEntryPoint() + " body=" + fn.getBody().getNumAddresses());
        Listing lst = currentProgram.getListing();
        InstructionIterator it = lst.getInstructions(fn.getBody(), true);
        int n = 0;
        while (it.hasNext() && n < max) {
            Instruction ins = it.next();
            String comment = "";
            ghidra.program.model.symbol.Reference[] refs = ins.getReferencesFrom();
            for (ghidra.program.model.symbol.Reference r : refs) {
                if (r.getReferenceType().isData() || r.getReferenceType().isRead()
                        || r.getReferenceType().isWrite()) {
                    Symbol s = currentProgram.getSymbolTable().getPrimarySymbol(r.getToAddress());
                    if (s != null) comment = "  ; " + s.getName();
                }
            }
            println(ins.getAddress() + "  " + ins.toString() + comment);
            n++;
        }
        println("INSTRUCTIONS " + n);
    }
}
