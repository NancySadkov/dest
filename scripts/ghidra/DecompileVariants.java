// Try several decompiler option sets/repairs for a stubborn function.
// Args: address outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class DecompileVariants extends GhidraScript {
    Function f;

    private String attempt(String name, DecompileOptions opts) {
        try {
            DecompInterface ifc = new DecompInterface();
            ifc.openProgram(currentProgram);
            ifc.setOptions(opts);
            DecompileResults res = ifc.decompileFunction(f, 600, monitor);
            if (res != null && res.decompileCompleted()) return res.getDecompiledFunction().getC();
            println(name + " -> " + (res == null ? "null" : res.getErrorMessage()));
            ifc.dispose();
            return null;
        } catch (Throwable t) {
            println(name + " -> exception " + t);
            return null;
        }
    }

    private DecompileOptions base() {
        DecompileOptions o = new DecompileOptions();
        o.setMaxPayloadMBytes(256);
        o.setMaxInstructions(2000000);
        return o;
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address addr = currentProgram.getAddressFactory().getAddress(a[0]);
        f = currentProgram.getFunctionManager().getFunctionAt(addr);
        if (f == null) { println("no function"); return; }
        String body = null; String how = null;

        String[] protocols = { "", "__cdecl16far", "__cdecl16near", "__stdcall16far", "__stdcall16near" };
        for (String p : protocols) {
            DecompileOptions o = base(); o.setProtoEvalModel(p);
            body = attempt("proto='" + p + "'", o); if (body != null) { how = "proto=" + p; break; }
        }
        if (body == null) {
            DecompileOptions o = base(); o.setEliminateUnreachable(false);
            body = attempt("no-unreachable", o); if (body != null) how = "no-unreachable";
        }
        if (body == null) {
            DecompileOptions o = base(); o.setRespectReadOnly(false);
            body = attempt("no-readonly", o); if (body != null) how = "no-readonly";
        }
        if (body == null) {
            DecompileOptions o = base(); o.setMaxJumpTableEntries(0);
            body = attempt("no-jumptable", o); if (body != null) how = "no-jumptable";
        }
        if (body == null) {
            DecompileOptions o = base(); o.setAliasBlock(DecompileOptions.AliasBlockEnum.None);
            body = attempt("alias-none", o); if (body != null) how = "alias-none";
        }
        if (body == null) {
            DecompileOptions o = base(); o.setSplitStructures(false); o.setSplitArrays(false);
            o.setSplitPointers(false); o.setAnalyzeForLoops(false); o.setInferConstantPointers(false);
            body = attempt("no-splits", o); if (body != null) how = "no-splits";
        }
        if (body == null) {
            int tx = currentProgram.startTransaction("reset params");
            try {
                for (Variable v : f.getParameters()) { try { f.removeVariable(v); } catch (Throwable t) {} }
                for (Variable v : f.getLocalVariables()) { try { f.removeVariable(v); } catch (Throwable t) {} }
                try { f.setReturnType(Undefined1DataType.dataType, SourceType.USER_DEFINED); } catch (Throwable t) {}
                try { f.setCallingConvention("__cdecl"); } catch (Throwable t) {}
            } finally { currentProgram.endTransaction(tx, true); }
            body = attempt("reset-vars", base()); if (body != null) how = "reset-vars";
        }
        if (body == null) {
            DecompileOptions o = base();
            o.setEliminateUnreachable(false); o.setRespectReadOnly(false);
            o.setMaxJumpTableEntries(0);
            o.setAliasBlock(DecompileOptions.AliasBlockEnum.None);
            o.setSplitStructures(false); o.setSplitArrays(false); o.setSplitPointers(false);
            o.setAnalyzeForLoops(false); o.setInferConstantPointers(false);
            body = attempt("kitchen-sink", o); if (body != null) how = "kitchen-sink";
        }
        PrintWriter w = new PrintWriter(new FileWriter(a[1]));
        if (body != null) {
            w.println("/* variant: " + how + " */");
            w.println(body);
            println("OK variant " + how);
        } else {
            w.println("/* ALL VARIANTS FAILED */");
            println("ALL VARIANTS FAILED");
        }
        w.close();
    }
}
