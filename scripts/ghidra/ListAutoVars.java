// List all auto-named parameters and locals (same patterns as AuditNaming) with their functions.
// Args: outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.data.*;
import java.io.*;
import java.util.regex.*;

public class ListAutoVars extends GhidraScript {
    static final Pattern AUTO_PARAM = Pattern.compile(
        "^(param_\\d+|in_stack_\\w+|in_[A-Z]{2,3}_\\w+|arg_\\d+|local_\\w+|extraout_\\w+)$");
    static final Pattern AUTO_LOCAL = Pattern.compile(
        "^(local_\\w+|uVar\\d+|iVar\\d+|bVar\\d+|cVar\\d+|pVar\\d+|pvVar\\d+|ppuVar\\d+|"
        + "uStack_\\w+|iStack_\\w+|bStack_\\w+|cStack_\\w+|pStack_\\w+|"
        + "in_stack_\\w+|in_[A-Z]{2,3}_\\w+|unaff_\\w+|extraout_\\w+)$");

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter w = new PrintWriter(new FileWriter(a[0]));
        w.println("address\tfunction\tkind\tname\ttype\tsize");
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            Variable[] ps = f.getParameters();
            for (int i = 0; i < ps.length; i++) {
                if (AUTO_PARAM.matcher(ps[i].getName()).matches()) {
                    DataType t = ps[i].getDataType();
                    w.println(f.getEntryPoint() + "\t" + f.getName() + "\tparam" + i + "\t"
                            + ps[i].getName() + "\t" + t.getName() + "\t" + t.getLength());
                }
            }
            for (Variable v : f.getLocalVariables()) {
                if (AUTO_LOCAL.matcher(v.getName()).matches()) {
                    DataType t = v.getDataType();
                    w.println(f.getEntryPoint() + "\t" + f.getName() + "\tlocal\t"
                            + v.getName() + "\t" + t.getName() + "\t" + t.getLength());
                }
            }
        }
        w.close();
        println("wrote " + a[0]);
    }
}
