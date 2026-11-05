// Clear and re-disassemble a function range from a single seed, then decompile.
// Useful when bad references created overlapping instructions.
// Args: startAddress endAddress outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class RedisassembleFunction extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address start = currentProgram.getAddressFactory().getAddress(a[0]);
        Address end = currentProgram.getAddressFactory().getAddress(a[1]);
        int tx = currentProgram.startTransaction("redisassemble function");
        try {
            Function old = currentProgram.getFunctionManager().getFunctionAt(start);
            if (old != null) removeFunction(old);
            clearListing(start, end);
            AddressSet seeds = new AddressSet(start, start);
            DisassembleCommand cmd = new DisassembleCommand(seeds, null, true);
            cmd.applyTo(currentProgram, monitor);
            Function f = createFunction(start, null);
            if (f == null) { println("createFunction failed"); return; }
            DecompileOptions o = new DecompileOptions();
            o.setProtoEvalModel("__cdecl16far");
            o.setMaxPayloadMBytes(256);
            DecompInterface ifc = new DecompInterface();
            ifc.openProgram(currentProgram);
            ifc.setOptions(o);
            DecompileResults res = ifc.decompileFunction(f, 600, monitor);
            PrintWriter w = new PrintWriter(new FileWriter(a[2]));
            if (res != null && res.decompileCompleted()) {
                w.println(res.getDecompiledFunction().getC());
                println("ok " + f.getName() + " ranges=" + f.getBody().getNumAddressRanges());
            } else {
                w.println("/* FAILED: " + (res == null ? "null" : res.getErrorMessage()) + " */");
                println("fail " + (res == null ? "null" : res.getErrorMessage()));
            }
            w.close();
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
