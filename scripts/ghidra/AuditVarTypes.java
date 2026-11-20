// Audit the declared types of every parameter and local variable.
// Reports counts plus every variable whose type is still an unresolved "undefined" form.
// Args: <out.tsv> [includeThunks]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class AuditVarTypes extends GhidraScript {
    private static boolean unresolved(DataType dt) {
        String n = dt.getName();
        if (n == null) return true;
        if (n.equals("undefined") || n.matches("undefined[1-9]")) return true;
        if (n.endsWith(" *") || n.endsWith(" *32")) {
            DataType b = dt;
            while (b instanceof Pointer) b = ((Pointer) b).getDataType();
            if (b != null && (b.getName().equals("undefined") || b.getName().matches("undefined[1-9]")))
                return true;
        }
        if (dt instanceof Array) {
            DataType b = dt;
            while (b instanceof Array) b = ((Array) b).getDataType();
            if (b != null && (b.getName().equals("undefined") || b.getName().matches("undefined[1-9]")))
                return true;
        }
        return false;
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter w = new PrintWriter(new FileWriter(a[0]));
        boolean thunks = a.length > 1 && a[1].equalsIgnoreCase("thunks");
        w.println("function\tkind\tname\ttype\tlength");
        int params = 0, pUn = 0, locals = 0, lUn = 0;
        int namedButUnresolved = 0;
        for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) {
            if (!thunks && fn.getName().startsWith("ovr_")) continue;
            for (Variable v : fn.getParameters()) {
                params++;
                if (unresolved(v.getDataType())) {
                    pUn++;
                    w.println(fn.getName() + "\tparam\t" + v.getName() + "\t"
                            + v.getDataType().getName() + "\t" + v.getLength());
                    if (!v.getName().matches("^(param_\\d+|in_stack_\\w+|arg_\\d+|extraout_\\w+)$"))
                        namedButUnresolved++;
                }
            }
            for (Variable v : fn.getLocalVariables()) {
                locals++;
                if (unresolved(v.getDataType())) {
                    lUn++;
                    w.println(fn.getName() + "\tlocal\t" + v.getName() + "\t"
                            + v.getDataType().getName() + "\t" + v.getLength());
                    if (!v.getName().matches("^(local_\\w+|in_stack_\\w+|uStack_\\w+|iStack_\\w+)$"))
                        namedButUnresolved++;
                }
            }
        }
        w.close();
        println("params=" + params + " unresolved=" + pUn
                + " locals=" + locals + " unresolved=" + lUn
                + " namedButUnresolved=" + namedButUnresolved);
    }
}
