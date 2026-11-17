// Dump a function's stack variables. Args: addr
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class StackVars extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address ad = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionContaining(ad);
        if (f == null) { println("no function"); return; }
        println("FUNC " + f.getName());
        for (Variable v : f.getLocalVariables()) {
            println(String.format("LOCAL %-16s %-12s %s storage=%s src=%s",
                    v.getName(), v.getDataType().getName(),
                    v.getVariableStorage(), v.getSource()));
        }
        for (Variable v : f.getParameters()) {
            println(String.format("PARAM %-16s %-12s %s src=%s",
                    v.getName(), v.getDataType().getName(),
                    v.getVariableStorage(), v.getSource()));
        }
        println("RET " + f.getReturnType().getName() + " "
                + f.getReturn().getVariableStorage());
    }
}
