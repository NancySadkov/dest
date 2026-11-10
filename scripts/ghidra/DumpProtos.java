// Dump function prototypes for a list of addresses.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class DumpProtos extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String a : getScriptArgs()) {
            Address ad = toAddr(a);
            Function f = currentProgram.getFunctionManager().getFunctionAt(ad);
            if (f == null) f = currentProgram.getFunctionManager().getFunctionContaining(ad);
            if (f == null) { println(a + " -> no function"); continue; }
            println(a + " " + f.getName() + " :: " + f.getSignature().getPrototypeString()
                    + "  cc=" + f.getCallingConventionName()
                    + " ret=" + f.getReturnType().getName());
            if (f.getReturn() != null) println("   return " + f.getReturn().getVariableStorage());
            for (Variable v : f.getParameters()) {
                println("   param " + v.getName() + " : " + v.getDataType().getName()
                        + " @ " + v.getVariableStorage());
            }
        }
    }
}
