// Bisect a function by inserting a RET at increasing offsets until the
// decompiler stops failing. Args: functionAddress outfile off1,off2,...
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class ProbeCuts extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address start = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(start);
        if (f == null) { println("no function"); return; }
        Memory mem = currentProgram.getMemory();
        PrintWriter w = new PrintWriter(new FileWriter(a[1]));
        for (String s : a[2].split(",")) {
            int off = Integer.parseInt(s.trim(), 16);
            Address at = start.add(off);
            byte orig = mem.getByte(at);
            int tx = currentProgram.startTransaction("probe cut");
            try {
                clearListing(at, at);
                mem.setByte(at, (byte)0xC3);
            } finally { currentProgram.endTransaction(tx, true); }
            DecompileOptions o = new DecompileOptions();
            o.setProtoEvalModel("__cdecl16far");
            o.setMaxPayloadMBytes(256);
            DecompInterface ifc = new DecompInterface();
            ifc.openProgram(currentProgram);
            ifc.setOptions(o);
            String status;
            try {
                DecompileResults res = ifc.decompileFunction(f, 120, monitor);
                if (res != null && res.decompileCompleted()) {
                    status = "OK";
                    w.println("/* ===== cut at +" + s + " ===== */");
                    w.println(res.getDecompiledFunction().getC());
                } else status = "fail " + (res == null ? "null" : res.getErrorMessage());
            } catch (Throwable t) { status = "exc " + t; }
            try { ifc.dispose(); } catch (Throwable t) {}
            int tx2 = currentProgram.startTransaction("restore cut");
            try { mem.setByte(at, orig); } finally { currentProgram.endTransaction(tx2, true); }
            println("cut +" + s + " -> " + status);
            if (status.equals("OK")) break;
        }
        w.close();
    }
}
