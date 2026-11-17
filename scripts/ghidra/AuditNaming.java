// Audit how much of the step-1 refinement is actually done: struct fields,
// function arguments/locals/return types, and global names.
// Args: outdir
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;
import java.util.regex.*;

public class AuditNaming extends GhidraScript {
    static final Pattern AUTO_PARAM = Pattern.compile(
        "^(param_\\d+|in_stack_\\w+|in_[A-Z]{2,3}_\\w+|arg_\\d+|local_\\w+|extraout_\\w+)$");
    static final Pattern AUTO_LOCAL = Pattern.compile(
        "^(local_\\w+|uVar\\d+|iVar\\d+|bVar\\d+|cVar\\d+|pVar\\d+|pvVar\\d+|ppuVar\\d+|"
        + "uStack_\\w+|iStack_\\w+|bStack_\\w+|cStack_\\w+|pStack_\\w+|"
        + "in_stack_\\w+|in_[A-Z]{2,3}_\\w+|unaff_\\w+|extraout_\\w+)$");
    static final Pattern WEAK_TYPE = Pattern.compile(
        "^(undefined|undefined\\d|byte|word|dword|uint|int|char|void|bool)$");
    static final Pattern AUTO_GLOBAL = Pattern.compile(
        "^(byte|word|dword|data|unk|DAT|LAB|UNK|FUN|SUB)_[0-9a-fA-F_]+(_string)?$|"
        + "^(byte|word|dword|data)_\\w+_\\w+_\\w+$|"
        + "^.*_DATA_[A-Za-z0-9._]+_[0-9A-F]{4,8}(_string)?$");
    static final Pattern AUTO_FIELD = Pattern.compile(
        "^(field_0x[0-9a-f]+|unnamed\\w*|pad_\\d+|unk\\w*|FUN_\\w+|DAT_\\w+)$");

    int fnTotal, fnNoProto, fnWeakRet, fnStructArg, paramTotal, paramAuto,
        localTotal, localAuto, structTotal, structFieldTotal, structFieldAuto,
        structTypedTotal, globalTotal, globalAuto;

    boolean hasStructParam(Function f) {
        for (Variable v : f.getParameters()) {
            DataType t = v.getDataType();
            if (t instanceof Pointer && ((Pointer) t).getDataType() instanceof Structure)
                return true;
            if (t instanceof Structure) return true;
        }
        return false;
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        String outdir = a.length > 0 ? a[0] : "audit";
        new File(outdir).mkdirs();

        PrintWriter fw = new PrintWriter(new FileWriter(new File(outdir, "naming_functions.tsv")));
        fw.println("address\tname\tparams\tauto_params\tlocals\tauto_locals\treturn\tstruct_arg");
        FunctionManager fm = currentProgram.getFunctionManager();
        for (Function f : fm.getFunctions(true)) {
            if (f.isThunk()) continue;
            fnTotal++;
            int na = 0, la = 0;
            Variable[] ps = f.getParameters();
            for (Variable v : ps) if (AUTO_PARAM.matcher(v.getName()).matches()) na++;
            Variable[] ls = f.getLocalVariables();
            for (Variable v : ls) if (AUTO_LOCAL.matcher(v.getName()).matches()) la++;
            String ret = f.getReturnType().getName();
            boolean weak = WEAK_TYPE.matcher(ret).matches();
            boolean st = hasStructParam(f);
            if (weak) fnWeakRet++;
            if (st) fnStructArg++;
            if (f.getSignatureSource() == SourceType.DEFAULT) fnNoProto++;
            paramTotal += ps.length; paramAuto += na;
            localTotal += ls.length; localAuto += la;
            if (na > 0 || la > 0 || weak)
                fw.println(f.getEntryPoint() + "\t" + f.getName() + "\t" + ps.length
                    + "\t" + na + "\t" + ls.length + "\t" + la + "\t" + ret + "\t" + st);
        }
        fw.close();

        PrintWriter sw = new PrintWriter(new FileWriter(new File(outdir, "naming_structs.tsv")));
        sw.println("struct\tfields\tauto_fields\tmembers\tauto_members");
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        Iterator<DataType> dtit = dtm.getAllDataTypes();
        while (dtit.hasNext()) {
            DataType dt = dtit.next();
            if (!(dt instanceof Structure)) continue;
            Structure s = (Structure) dt;
            structTotal++;
            int auto = 0;
            for (int i = 0; i < s.getNumComponents(); i++) {
                DataTypeComponent c = s.getComponent(i);
                structFieldTotal++;
                if (c.getFieldName() == null || AUTO_FIELD.matcher(c.getFieldName()).matches())
                    auto++;
            }
            structFieldAuto += auto;
            sw.println(s.getName() + "\t" + s.getNumComponents() + "\t" + auto);
        }
        sw.close();

        PrintWriter gw = new PrintWriter(new FileWriter(new File(outdir, "naming_globals.tsv")));
        gw.println("address\tname\ttype");
        SymbolTable st = currentProgram.getSymbolTable();
        for (Symbol s : st.getAllSymbols(true)) {
            if (!s.isGlobal()) continue;
            if (!(s.getSymbolType() == SymbolType.LABEL || s.getSymbolType() == SymbolType.FUNCTION))
                continue;
            if (s.getSymbolType() == SymbolType.FUNCTION) continue;
            Address ad = s.getAddress();
            if (ad == null) continue;
            Data d = currentProgram.getListing().getDataAt(ad);
            if (d == null) continue;
            globalTotal++;
            if (AUTO_GLOBAL.matcher(s.getName()).matches()) {
                globalAuto++;
                gw.println(ad + "\t" + s.getName() + "\t" + d.getDataType().getName());
            }
        }
        gw.close();

        PrintWriter rw = new PrintWriter(new FileWriter(new File(outdir, "naming_summary.txt")));
        rw.println("functions                 " + fnTotal);
        rw.println("  no prototype (default)  " + fnNoProto);
        rw.println("  weak return type        " + fnWeakRet);
        rw.println("  has struct arg          " + fnStructArg);
        rw.println("parameters                " + paramTotal + "  auto " + paramAuto
                    + "  (" + pct(paramAuto, paramTotal) + "%)");
        rw.println("locals                    " + localTotal + "  auto " + localAuto
                    + "  (" + pct(localAuto, localTotal) + "%)");
        rw.println("structs                   " + structTotal);
        rw.println("  struct fields           " + structFieldTotal + "  auto-name "
                    + structFieldAuto + "  (" + pct(structFieldAuto, structFieldTotal) + "%)");
        rw.println("globals                   " + globalTotal + "  auto-name " + globalAuto
                    + "  (" + pct(globalAuto, globalTotal) + "%)");
        rw.close();
        println("naming audit written to " + outdir);
    }

    static String pct(int a, int b) { return b == 0 ? "0.0" : String.format("%.1f", 100.0 * a / b); }
}
