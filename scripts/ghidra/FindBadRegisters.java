// Inspect registers and context values, looking for registers whose address
// space is NO ADDRESS (which breaks DecompileCallback.encodeTrackSet).
// Args: address [outfile]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.lang.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.math.BigInteger;

public class FindBadRegisters extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address at = currentProgram.getAddressFactory().getAddress(a[0]);
        ProgramContext ctx = currentProgram.getProgramContext();
        PrintWriter w = a.length > 1 ? new PrintWriter(new FileWriter(a[1])) : new PrintWriter(System.out);
        int n = 0;
        for (Register r : ctx.getRegisters()) {
            AddressSpace sp = r.getAddressSpace();
            String sn = sp == null ? "null" : sp.getName();
            if (sn == null || sn.toUpperCase().contains("NO ADDRESS") || sn.toUpperCase().contains("BAD ADDRESS")) {
                w.println("BADREG " + r.getName() + " space=" + sn + " off=" + r.getOffset()
                        + " size=" + r.getMinimumByteSize() + " procctx=" + r.isProcessorContext());
                n++;
            }
            BigInteger v = ctx.getValue(r, at, false);
            if (v != null && (sn == null || sn.toUpperCase().contains("NO ADDRESS"))) {
                w.println("  value at " + at + " = " + v.toString(16));
            }
        }
        w.println("badregs=" + n + " total=" + ctx.getRegisters().size());
        if (a.length > 1) w.close();
    }
}
