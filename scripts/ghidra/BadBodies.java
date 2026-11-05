// List functions with non-contiguous bodies (often a sign of bad analysis).
// Args: [outfile]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class BadBodies extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter w = a.length > 0 ? new PrintWriter(new FileWriter(a[0])) : new PrintWriter(System.out);
        int n = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            AddressSetView b = f.getBody();
            int nr = b.getNumAddressRanges();
            if (nr <= 1) continue;
            n++;
            w.println(f.getEntryPoint() + " " + f.getName() + " ranges=" + nr);
            for (AddressRange r : b)
                w.println("    " + r.getMinAddress() + " - " + r.getMaxAddress()
                          + " (" + r.getLength() + ")");
        }
        w.println("TOTAL " + n);
        if (a.length > 0) w.close();
        println("non-contiguous bodies: " + n);
    }
}
