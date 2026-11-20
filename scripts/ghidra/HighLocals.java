// Dump the decompiler's own local symbols (name, type, storage) for a function.
// Args: address
//@category DeSt
import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.HighSymbol;
import java.util.Iterator;

public class HighLocals extends GhidraScript {
    @Override
    public void run() throws Exception {
        Address ad = currentProgram.getAddressFactory().getAddress(getScriptArgs()[0]);
        Function fn = currentProgram.getFunctionManager().getFunctionAt(ad);
        if (fn == null) { println("NOFUNC"); return; }
        DecompInterface d = new DecompInterface();
        d.toggleCCode(false);
        d.toggleSyntaxTree(false);
        if (!d.openProgram(currentProgram)) { println("OPENFAIL"); return; }
        DecompileResults res = d.decompileFunction(fn, 60, monitor);
        if (res == null || !res.decompileCompleted()) { println("DECOMPFAIL " + (res == null ? "" : res.getErrorMessage())); return; }
        HighFunction hf = res.getHighFunction();
        println("FUNC " + fn.getName() + " locals:");
        Iterator<HighSymbol> it = hf.getLocalSymbolMap().getSymbols();
        while (it.hasNext()) {
            HighSymbol s = it.next();
            println(String.format("  %-24s %-16s %-10s storage=%s pcadr=%s",
                    s.getName(), s.getDataType().getName(),
                    s.isParameter() ? "param" : "local",
                    s.getStorage(), s.getPCAddress()));
        }
        d.dispose();
    }
}
