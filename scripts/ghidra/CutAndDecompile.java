// Clear one instruction, replace it with RET, decompile the function, restore.
// Args: functionAddress cutOffset outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class CutAndDecompile extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address start = currentProgram.getAddressFactory().getAddress(a[0]);
        int off = Integer.parseInt(a[1], 16);
        Address at = start.add(off);
        Function f = currentProgram.getFunctionManager().getFunctionAt(start);
        if (f == null) { println("no function"); return; }
        Memory mem = currentProgram.getMemory();
        byte orig = mem.getByte(at);
        int tx = currentProgram.startTransaction("cut");
        try { clearListing(at, at); mem.setByte(at, (byte)0xC3); }
        finally { currentProgram.endTransaction(tx, true); }

        DecompileOptions o = new DecompileOptions();
        o.setProtoEvalModel("__cdecl16far");
        o.setMaxPayloadMBytes(256);
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        ifc.setOptions(o);
        PrintWriter w = new PrintWriter(new FileWriter(a[2]));
        String status;
        try {
            DecompileResults res = ifc.decompileFunction(f, 180, monitor);
            if (res != null && res.decompileCompleted()) {
                w.println(res.getDecompiledFunction().getC());
                status = "OK";
            } else status = "fail " + (res == null ? "null" : res.getErrorMessage());
        } catch (Throwable t) { status = "exception " + t; }
        w.close();
        try { ifc.dispose(); } catch (Throwable t) {}
        int tx2 = currentProgram.startTransaction("restore");
        try { mem.setByte(at, orig); } finally { currentProgram.endTransaction(tx2, true); }
        println("cut +" + a[1] + " -> " + status);
    }
}
