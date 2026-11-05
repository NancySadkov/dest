// Decompile a function while temporarily patching zero-initialised far-pointer
// data that makes Ghidra's tracked-register callback fail with NO ADDRESS.
// Args: functionAddress patchAddress patchHex outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class PatchAndDecompile extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address fnAddr = currentProgram.getAddressFactory().getAddress(a[0]);
        Address patchAddr = currentProgram.getAddressFactory().getAddress(a[1]);
        String hex = a[2].replace(" ", "");
        byte[] patch = new byte[hex.length() / 2];
        for (int i = 0; i < patch.length; i++)
            patch[i] = (byte) Integer.parseInt(hex.substring(i * 2, i * 2 + 2), 16);
        Memory mem = currentProgram.getMemory();
        Function f = currentProgram.getFunctionManager().getFunctionAt(fnAddr);
        if (f == null) { println("no function"); return; }

        byte[] orig = new byte[patch.length];
        mem.getBytes(patchAddr, orig);
        int tx = currentProgram.startTransaction("patch for decompile");
        try {
            mem.setBytes(patchAddr, patch);
        } finally {
            currentProgram.endTransaction(tx, true);
        }

        DecompileOptions o = new DecompileOptions();
        o.setProtoEvalModel("__cdecl16far");
        o.setMaxPayloadMBytes(256);
        o.setMaxInstructions(2000000);
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        ifc.setOptions(o);

        StringBuilder out = new StringBuilder();
        String status;
        try {
            DecompileResults res = ifc.decompileFunction(f, 900, monitor);
            if (res != null && res.decompileCompleted()) {
                out.append(res.getDecompiledFunction().getC());
                status = "ok";
            } else {
                status = "fail " + (res == null ? "null" : res.getErrorMessage());
                out.append("/* FAILED: ").append(status).append(" */");
            }
        } catch (Throwable t) {
            status = "exception " + t;
            out.append("/* FAILED: ").append(status).append(" */");
        }
        ifc.dispose();

        int tx2 = currentProgram.startTransaction("restore patch");
        try {
            mem.setBytes(patchAddr, orig);
        } finally {
            currentProgram.endTransaction(tx2, true);
        }
        PrintWriter w = new PrintWriter(new FileWriter(a[3]));
        w.println(out);
        w.close();
        println(status + " " + f.getName());
    }
}
