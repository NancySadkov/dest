// Decompile a huge function in slices by restricting its body to one address range at a time.
//
// Some overlay functions (e.g. 8699:18c4 ovc49_body1) are large enough that the decompiler's
// whole-body analysis times out.  Restricting the body to a byte range keeps the analysis local:
// the decompiler decodes only that range, treats calls outside it as external, and returns quickly
// enough to be useful.  The original body is restored after every slice.
//
// Args: address startOff endOff outfile [timeoutSeconds]
//   startOff/endOff are hex offsets from the function entry.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class SliceDecompile extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        if (a.length < 4) { println("usage: address startOff endOff outfile [timeout]"); return; }
        Address start = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(start);
        if (f == null) { println("no function at " + a[0]); return; }
        long s = Long.parseLong(a[1], 16);
        long e = Long.parseLong(a[2], 16);
        int timeout = a.length > 4 ? Integer.parseInt(a[4]) : 300;

        AddressSet original = new AddressSet(f.getBody());
        AddressSet slice = new AddressSet(start.add(s), start.add(e - 1));
        int tx = currentProgram.startTransaction("slice body");
        try { f.setBody(slice); }
        finally { currentProgram.endTransaction(tx, true); }

        DecompileOptions o = new DecompileOptions();
        o.setProtoEvalModel("__cdecl16far");
        o.setMaxPayloadMBytes(256);
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        ifc.setOptions(o);
        PrintWriter w = new PrintWriter(new FileWriter(a[3]));
        String status;
        try {
            DecompileResults res = ifc.decompileFunction(f, timeout, monitor);
            if (res != null && res.decompileCompleted()) {
                w.println(res.getDecompiledFunction().getC());
                status = "OK";
            } else {
                status = "fail " + (res == null ? "null" : res.getErrorMessage());
                w.println("/* FAILED: " + status + " */");
            }
        } catch (Throwable t) {
            status = "exception " + t;
            w.println("/* FAILED: " + status + " */");
        }
        w.close();
        try { ifc.dispose(); } catch (Throwable t) {}

        int tx2 = currentProgram.startTransaction("restore body");
        try { f.setBody(original); }
        finally { currentProgram.endTransaction(tx2, true); }
        println("slice " + a[1] + ".." + a[2] + " -> " + status);
    }
}
