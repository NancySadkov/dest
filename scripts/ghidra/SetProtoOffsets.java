// Set a function prototype with explicit per-parameter stack offsets and optional return storage.
// Args: tsv with  addr <TAB> retType[@REG[:REG]] <TAB> cc <TAB> name:type:offset [<TAB> ...]
// retType "-" keeps the current return type; "@DX:AX" sets an explicit register return storage;
// cc "-" keeps the current calling convention.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class SetProtoOffsets extends GhidraScript {
    private DataTypeManager dtmgr;

    private AddressSpace stackSpace(Function fn) {
        for (Variable v : fn.getParameters()) {
            Address a = v.getVariableStorage().getMinAddress();
            if (a != null) return a.getAddressSpace();
        }
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            for (Variable v : f.getParameters()) {
                Address a = v.getVariableStorage().getMinAddress();
                if (a != null) return a.getAddressSpace();
            }
        }
        return null;
    }

    private DataType resolve(String spec) {
        if (spec.endsWith(" *32")) {
            DataType b = dtmgr.getDataType(spec.substring(0, spec.length() - 4).trim());
            return b == null ? null : new PointerDataType(b, 4, dtmgr);
        }
        if (spec.endsWith(" *")) {
            DataType b = dtmgr.getDataType(spec.substring(0, spec.length() - 2).trim());
            return b == null ? null : new PointerDataType(b, 2, dtmgr);
        }
        return dtmgr.getDataType(spec);
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        dtmgr = currentProgram.getDataTypeManager();
        AddressSpace sp = null;
        int tx = currentProgram.startTransaction("set prototype offsets");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 4) { println("BADLINE " + line); continue; }
                Function fn = getFunctionAt(toAddr(f[0]));
                if (fn == null) { println("NOFUNC " + f[0]); continue; }
                if (sp == null) sp = stackSpace(fn);
                if (sp == null) { println("NO_STACK_SPACE"); return; }
                for (int i = fn.getParameters().length - 1; i >= 0; i--)
                    fn.removeParameter(i);
                fn.setCustomVariableStorage(true);
                if (!f[1].trim().equals("-")) {
                    String rtspec = f[1].trim();
                    VariableStorage rstore = fn.getReturn().getVariableStorage();
                    int at = rtspec.indexOf('@');
                    if (at >= 0) {
                        String[] regs = rtspec.substring(at + 1).split(":");
                        java.util.List<Register> rlist = new java.util.ArrayList<>();
                        boolean ok = true;
                        for (String rn : regs) {
                            Register rg = currentProgram.getRegister(rn.trim());
                            if (rg == null) { println("NOREG " + rn); ok = false; break; }
                            rlist.add(rg);
                        }
                        if (!ok) continue;
                        rstore = new VariableStorage(currentProgram, rlist.toArray(new Register[0]));
                        rtspec = rtspec.substring(0, at);
                    }
                    DataType rt = resolve(rtspec);
                    if (rt == null) { println("NOTYPE_RET " + rtspec); continue; }
                    fn.setReturn(rt, rstore, SourceType.USER_DEFINED);
                }
                if (!f[2].trim().equals("-")) {
                    try { fn.setCallingConvention(f[2].trim()); }
                    catch (Exception e) { println("BADCC " + f[2] + " " + e.getMessage()); }
                }
                for (int i = 3; i < f.length; i++) {
                    String[] q = f[i].trim().split(":");
                    if (q.length != 3) { println("BADPARAM " + f[i]); continue; }
                    DataType dt = resolve(q[1].trim());
                    if (dt == null) { println("NOTYPE " + q[1]); continue; }
                    int off;
                    try { off = Integer.decode(q[2].trim()); }
                    catch (Exception e) { println("BADOFF " + q[2]); continue; }
                    VariableStorage vs = new VariableStorage(currentProgram, sp.getAddress(off),
                            dt.getLength());
                    fn.addParameter(new ParameterImpl(q[0].trim(), dt, vs, currentProgram),
                            SourceType.USER_DEFINED);
                }
                println("set " + fn.getName() + " : " + fn.getPrototypeString(false, false));
                for (Variable v : fn.getParameters())
                    println("  param " + v.getName() + " " + v.getDataType().getName()
                            + " @ " + v.getVariableStorage());
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
