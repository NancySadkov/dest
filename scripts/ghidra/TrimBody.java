// Trim a function body to the memory block containing its entry point, then
// decompile it. Cross-segment body fragments are caused by bad control-flow
// following across overlay segments.
// Args: address outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class TrimBody extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address addr = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(addr);
        if (f == null) { println("no function"); return; }
        Memory memory = currentProgram.getMemory();
        MemoryBlock entryBlock = memory.getBlock(addr);
        AddressSet body = new AddressSet(f.getBody());
        int removed = 0;
        java.util.List<AddressRange> ranges = new java.util.ArrayList<AddressRange>();
        for (AddressRange rr : body) ranges.add(rr);
        for (AddressRange r : ranges) {
            MemoryBlock b = memory.getBlock(r.getMinAddress());
            if (b != entryBlock) {
                println("remove range " + r);
                body.delete(r);
                removed++;
            }
        }
        int tx = currentProgram.startTransaction("trim body");
        try {
            AddressRange keep = null;
            for (AddressRange rr : body) if (rr.contains(addr)) keep = rr;
            if (keep != null) body = new AddressSet(keep);
            f.setBody(body);
        } finally { currentProgram.endTransaction(tx, true); }
        println("removed ranges=" + removed + " new ranges=" + f.getBody().getNumAddressRanges());
        DecompileOptions o = new DecompileOptions();
        o.setProtoEvalModel("__cdecl16far");
        o.setMaxPayloadMBytes(256);
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        ifc.setOptions(o);
        DecompileResults res = ifc.decompileFunction(f, 600, monitor);
        PrintWriter w = new PrintWriter(new FileWriter(a[1]));
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
