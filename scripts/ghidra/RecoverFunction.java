// Recover a stubborn function by repairing references/locals between attempts.
// Args: address outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class RecoverFunction extends GhidraScript {
    private DecompInterface ifc;

    private boolean tryDecompile(Function f, String[] out, String[] err) {
        DecompileResults res = ifc.decompileFunction(f, 600, monitor);
        if (res != null && res.decompileCompleted()) {
            out[0] = res.getDecompiledFunction().getC();
            return true;
        }
        err[0] = res == null ? "null" : res.getErrorMessage();
        return false;
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address addr = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(addr);
        if (f == null) { println("no function"); return; }
        DecompileOptions opts = new DecompileOptions();
        opts.setProtoEvalModel("__cdecl16far");
        opts.setMaxPayloadMBytes(256);
        opts.setMaxInstructions(2000000);
        ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        ifc.setOptions(opts);

        String[] body = new String[1], err = new String[1];
        String how = "direct";
        if (!tryDecompile(f, body, err)) {
            println("direct failed: " + err[0]);
            int tx = currentProgram.startTransaction("clear bad refs");
            int removed = 0;
            try {
                ReferenceManager rm = currentProgram.getReferenceManager();
                AddressIterator it = f.getBody().getAddresses(true);
                while (it.hasNext()) {
                    Address ad = it.next();
                    for (Reference r : rm.getReferencesFrom(ad)) {
                        Address to = r.getToAddress();
                        if (to == null || to.equals(Address.NO_ADDRESS)
                                || (!to.isMemoryAddress() && !to.isStackAddress()
                                    && !to.isRegisterAddress() && !to.isExternalAddress()
                                    && !to.isConstantAddress())) {
                            rm.delete(r);
                            removed++;
                        }
                    }
                }
            } finally {
                currentProgram.endTransaction(tx, true);
            }
            println("bad refs removed=" + removed);
            how = "badrefs";
            if (!tryDecompile(f, body, err)) {
                println("after badrefs failed: " + err[0]);
                int tx2 = currentProgram.startTransaction("clear locals");
                try {
                    for (Variable v : f.getLocalVariables()) {
                        try { f.removeVariable(v); } catch (Throwable t) {}
                    }
                } finally {
                    currentProgram.endTransaction(tx2, true);
                }
                how = "nolocals";
                if (!tryDecompile(f, body, err)) {
                    println("after nolocals failed: " + err[0]);
                    PrintWriter w = new PrintWriter(new FileWriter(a[1]));
                    w.println("/* FAILED: " + err[0] + " */");
                    w.close();
                    return;
                }
            }
        }
        PrintWriter w = new PrintWriter(new FileWriter(a[1]));
        w.println("/* repaired (" + how + ") */");
        w.println(body[0]);
        w.close();
        println("ok (" + how + ") " + f.getName());
    }
}
