// Map a region from the merged executable file into the program, then
// decompile a function. Args: startAddr fileOffset length outfile [fnAddr]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;
import java.nio.file.*;

public class MapRegion extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address start = currentProgram.getAddressFactory().getAddress(a[0]);
        long fileOff = Long.decode(a[1]);
        int len = Integer.decode(a[2]);
        String out = a[3];
        Address fnAddr = currentProgram.getAddressFactory().getAddress(
                a.length > 4 ? a[4] : a[0]);
        byte[] all = Files.readAllBytes(Paths.get("C:\\Users\\nangl\\d\\code\\dest\\unfbov\\st.exe"));
        byte[] bytes = new byte[len];
        System.arraycopy(all, (int)fileOff, bytes, 0, len);
        Memory mem = currentProgram.getMemory();
        int tx = currentProgram.startTransaction("map region");
        MemoryBlock b = null;
        try {
            b = mem.getBlock(start);
            if (b == null) {
                b = mem.createInitializedBlock("mapped_" + a[0].replace(':','_'), start,
                        new ByteArrayInputStream(bytes), len, monitor, false);
                b.setRead(true); b.setWrite(false); b.setExecute(true);
                println("mapped " + b.getName() + " " + b.getStart() + " len=" + len);
            } else {
                println("existing block " + b.getName());
            }
        } catch (Throwable t) {
            println("map failed: " + t);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        Function f = currentProgram.getFunctionManager().getFunctionAt(fnAddr);
        if (f == null) { println("no function"); return; }
        DecompileOptions o = new DecompileOptions();
        o.setProtoEvalModel("__cdecl16far");
        o.setMaxPayloadMBytes(256);
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        ifc.setOptions(o);
        try { ifc.enableDebug(new File(out + ".debug.xml")); } catch (Throwable t) { println("debug enable failed: " + t); }
        PrintWriter w = new PrintWriter(new FileWriter(out));
        String status;
        try {
            DecompileResults res = ifc.decompileFunction(f, 300, monitor);
            if (res != null && res.decompileCompleted()) {
                w.println(res.getDecompiledFunction().getC());
                status = "ok";
            } else status = "fail " + (res == null ? "null" : res.getErrorMessage());
        } catch (Throwable t) { status = "exception " + t; }
        w.close();
        try { ifc.dispose(); } catch (Throwable t) {}
        println(status + " " + f.getName());
    }
}
