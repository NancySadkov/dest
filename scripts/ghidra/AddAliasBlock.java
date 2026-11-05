// Create a byte-mapped alias for a segmented block, so that Ghidra's
// canonical segment form (e.g. 5000:6034 for 55fe:0054) resolves to bytes.
// Args: sourceBlockName aliasSeg:aliasOffset outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class AddAliasBlock extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Memory mem = currentProgram.getMemory();
        MemoryBlock src = mem.getBlock(a[0]);
        if (src == null) { println("no source block " + a[0]); return; }
        Address aliasStart = currentProgram.getAddressFactory().getAddress(a[1]);
        long len = src.getSize();
        println("src=" + src.getName() + " " + src.getStart() + " len=" + len
                + " aliasStart=" + aliasStart);
        int tx = currentProgram.startTransaction("add alias block");
        MemoryBlock alias = null;
        try {
            alias = mem.getBlock(aliasStart);
            println("existing block at alias: " + alias);
            if (alias == null) {
                alias = mem.createByteMappedBlock("alias_" + a[0], aliasStart,
                        src.getStart(), len, false);
                alias.setRead(true); alias.setWrite(true); alias.setExecute(true);
                println("created alias " + alias.getName() + " " + alias.getStart()
                        + " -> " + src.getStart() + " len=" + len);
            }
        } catch (Throwable t) {
            println("alias creation failed: " + t);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        Address probe = currentProgram.getAddressFactory().getAddress("5000:6034");
        println("probe " + probe + " block=" + mem.getBlock(probe));
        Address fn = currentProgram.getAddressFactory().getAddress("55fe:0000");
        Function f = currentProgram.getFunctionManager().getFunctionAt(fn);
        if (f == null) { println("no function"); return; }
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
            println("ok " + f.getName());
        } else {
            w.println("/* FAILED: " + (res == null ? "null" : res.getErrorMessage()) + " */");
            println("fail " + (res == null ? "null" : res.getErrorMessage()));
        }
        w.close();
    }
}
