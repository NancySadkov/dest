// Restrict a function body to the segment of its entry point, then decompile.
// Bad control flow that follows a jump into another overlay segment merges unrelated code into the
// function (ovc49_body1 at 8699:18c4 absorbs the 8000:xxxx asset loader, which is why it is huge and
// times out).  Keeping only the entry segment leaves the real body.
// Args: address outfile [timeoutSeconds]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class TrimSeg extends GhidraScript {

    private static String segOf(Address a) {
        String s = a.toString();
        int c = s.indexOf(':');
        return c < 0 ? "" : s.substring(0, c);
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address entry = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(entry);
        if (f == null) { println("no function"); return; }
        int timeout = a.length > 2 ? Integer.parseInt(a[2]) : 300;
        String want = segOf(entry);

        AddressSet original = new AddressSet(f.getBody());
        AddressSet keep = new AddressSet();
        Address runStart = null, prev = null;
        for (Address cur : original.getAddresses(true)) {
            if (segOf(cur).equals(want)) {
                if (runStart == null) runStart = cur;
                prev = cur;
            } else if (runStart != null) {
                keep.add(runStart, prev);
                runStart = null;
            }
        }
        if (runStart != null) keep.add(runStart, prev);
        if (keep.isEmpty()) { println("nothing kept"); return; }

        int tx = currentProgram.startTransaction("trim segment");
        try { f.setBody(keep); }
        finally { currentProgram.endTransaction(tx, true); }

        DecompileOptions o = new DecompileOptions();
        o.setProtoEvalModel("__cdecl16far");
        o.setMaxPayloadMBytes(256);
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        ifc.setOptions(o);
        DecompileResults res = ifc.decompileFunction(f, timeout, monitor);
        PrintWriter w = new PrintWriter(new FileWriter(a[1]));
        if (res != null && res.decompileCompleted()) {
            w.println(res.getDecompiledFunction().getC());
            println("ok seg=" + want + " ranges=" + keep.getNumAddressRanges()
                    + " bytes=" + keep.getNumAddresses());
        } else {
            String msg = res == null ? "null" : res.getErrorMessage();
            w.println("/* FAILED: " + msg + " */");
            println("fail " + msg);
        }
        w.close();
        try { ifc.dispose(); } catch (Throwable t) {}

        int tx2 = currentProgram.startTransaction("restore body");
        try { f.setBody(original); }
        finally { currentProgram.endTransaction(tx2, true); }
    }
}
