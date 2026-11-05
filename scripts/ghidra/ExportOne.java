// Decompile a single function with relaxed limits. Args: address outfile [timeoutSecs]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class ExportOne extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address addr = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(addr);
        if (f == null) { println("no function at " + a[0]); return; }
        int timeout = a.length > 2 ? Integer.parseInt(a[2]) : 1800;
        DecompileOptions opts = new DecompileOptions();
        opts.setProtoEvalModel("__cdecl16far");
        opts.setDefaultTimeout(timeout);
        opts.setMaxPayloadMBytes(256);
        opts.setMaxInstructions(2000000);
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        ifc.setOptions(opts);
        DecompileResults res = ifc.decompileFunction(f, timeout, monitor);
        PrintWriter w = new PrintWriter(new FileWriter(a[1]));
        w.println("/* " + f.getName() + " @ " + f.getEntryPoint() + " */");
        if (res != null && res.decompileCompleted()) {
            w.println(res.getDecompiledFunction().getC());
            println("ok " + f.getName());
        } else {
            w.println("/* FAILED: " + (res == null ? "null" : res.getErrorMessage()) + " */");
            println("fail " + (res == null ? "null" : res.getErrorMessage()));
        }
        w.close();
    }
}
