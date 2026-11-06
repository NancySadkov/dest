// Decompile the function at an address in the fresh model. Args: address outfile
//@category DeSt
import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class DecompileAt extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address at = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(at);
        if (f == null) f = currentProgram.getFunctionManager().getFunctionContaining(at);
        if (f == null) { println("no function at " + a[0]); return; }
        DecompileOptions o = new DecompileOptions();
        o.setProtoEvalModel("__cdecl16far");
        o.setMaxPayloadMBytes(256);
        o.setInferConstantPointers(false);
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        ifc.setOptions(o);
        DecompileResults res = ifc.decompileFunction(f, 600, monitor);
        PrintWriter w = new PrintWriter(new FileWriter(a[1]));
        if (res != null && res.decompileCompleted()) {
            w.println(res.getDecompiledFunction().getC());
            println("ok " + f.getName() + " " + f.getEntryPoint());
        } else {
            w.println("/* FAILED: " + (res == null ? "null" : res.getErrorMessage()) + " */");
            println("fail " + (res == null ? "null" : res.getErrorMessage()));
        }
        w.close();
        try { ifc.dispose(); } catch (Throwable t) {}
    }
}
