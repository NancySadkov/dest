// Inspect/repair a function whose decompilation fails with a forced-merge
// intersection. Args: address mode(out|clear|clearlocals|clearparams|decompile)
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class RepairFunction extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address addr = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(addr);
        if (f == null) { println("no function at " + a[0]); return; }
        String mode = a.length > 1 ? a[1] : "out";
        int tx = currentProgram.startTransaction("repair function");
        try {
            if (mode.equals("clear") || mode.equals("clearlocals")) {
                Variable[] vars = f.getLocalVariables();
                println("locals before: " + vars.length);
                for (Variable v : vars) {
                    try { f.removeVariable(v); } catch (Throwable t) { println("cannot remove " + v.getName()); }
                }
            }
            if (mode.equals("clear") || mode.equals("clearparams")) {
                Variable[] params = f.getParameters();
                println("params before: " + params.length);
                for (Variable v : params) {
                    try { f.removeVariable(v); } catch (Throwable t) { println("cannot remove param " + v.getName()); }
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        if (mode.equals("out")) {
            println("name=" + f.getName() + " entry=" + f.getEntryPoint()
                    + " stack=" + f.getStackFrame().getFrameSize()
                    + " body=" + f.getBody().getNumAddresses());
            for (Variable v : f.getLocalVariables())
                println("  local " + v.getName() + " : " + v.getDataType().getName()
                        + " @" + v.getVariableStorage());
            for (Variable v : f.getParameters())
                println("  param " + v.getName() + " : " + v.getDataType().getName()
                        + " @" + v.getVariableStorage());
            return;
        }
        DecompileOptions opts = new DecompileOptions();
        opts.setProtoEvalModel("__cdecl16far");
        opts.setMaxPayloadMBytes(256);
        opts.setMaxInstructions(2000000);
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        ifc.setOptions(opts);
        DecompileResults res = ifc.decompileFunction(f, 600, monitor);
        if (res != null && res.decompileCompleted()) {
            println(res.getDecompiledFunction().getC());
        } else {
            println("FAILED: " + (res == null ? "null" : res.getErrorMessage()));
        }
    }
}
