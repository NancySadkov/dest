// Set prototypes with parameters laid out sequentially from the first stack slot.
//
// Args: tsv of  addr <TAB> retSpec <TAB> cc <TAB> name:typeSpec [<TAB> ...]
//   retSpec / cc may be "-" to keep the current value.
//   typeSpec is "Name", "Name *" (two-byte near pointer) or "Name *32" (four-byte).
//   Names are resolved by path first, then by short name.
// Parameters named __return_storage_ptr__ are skipped: Ghidra owns them.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.exception.DuplicateNameException;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.*;

public class SetProtoSeq extends GhidraScript {
    private DataTypeManager dtm;

    private DataType byName(String n) {
        DataType d = dtm.getDataType(n);
        if (d != null) return d;
        DataType best = null;
        for (Iterator<DataType> it = dtm.getAllDataTypes(); it.hasNext();) {
            DataType t = it.next();
            if (t instanceof Array || t instanceof Pointer) continue;
            if (!t.getName().equals(n)) continue;
            if (best == null || t.getPathName().length() < best.getPathName().length()) best = t;
        }
        return best;
    }

    private DataType resolve(String spec) {
        spec = spec.trim();
        if (spec.endsWith(" *32")) {
            DataType b = byName(spec.substring(0, spec.length() - 4).trim());
            return b == null ? null : new PointerDataType(b, 4, dtm);
        }
        if (spec.endsWith(" *")) {
            DataType b = byName(spec.substring(0, spec.length() - 2).trim());
            return b == null ? null : new PointerDataType(b, 2, dtm);
        }
        return byName(spec);
    }

    static int slotSize(DataType t) {
        int len = t.getLength();
        if (len <= 0) return 2;
        return len <= 2 ? 2 : 4;
    }

    @Override
    public void run() throws Exception {
        dtm = currentProgram.getDataTypeManager();
        AddressSpace sp = null;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            for (Variable v : f.getParameters()) {
                Address a = v.getVariableStorage().getMinAddress();
                if (a != null) { sp = a.getAddressSpace(); break; }
            }
            if (sp != null) break;
        }
        if (sp == null) { println("NO_STACK_SPACE"); return; }
        int ok = 0, skipped = 0, failed = 0;
        int tx = currentProgram.startTransaction("set proto seq");
        try {
            for (String line : Files.readAllLines(Paths.get(getScriptArgs()[0]),
                    StandardCharsets.UTF_8)) {
                if (line.trim().isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 3) continue;
                Function fn = getFunctionAt(toAddr(f[0]));
                if (fn == null) { println("NOFUNC " + f[0]); failed++; continue; }
                List<String> names = new ArrayList<>();
                List<DataType> types = new ArrayList<>();
                boolean bad = false;
                for (int i = 3; i < f.length; i++) {
                    String[] q = f[i].trim().split(":");
                    if (q.length != 2) { println("BADPARAM " + f[0] + " " + f[i]); bad = true; break; }
                    DataType dt = resolve(q[1]);
                    if (dt == null) { println("NOTYPE " + f[0] + " " + q[1]); bad = true; break; }
                    names.add(q[0]);
                    types.add(dt);
                }
                if (bad) { failed++; continue; }
                try {
                    for (int i = fn.getParameters().length - 1; i >= 0; i--) fn.removeParameter(i);
                    fn.setCustomVariableStorage(true);
                    if (!f[1].trim().equals("-")) {
                        DataType rt = resolve(f[1]);
                        if (rt != null) fn.setReturnType(rt, SourceType.USER_DEFINED);
                    }
                    String cc = fn.getCallingConventionName();
                    boolean farcc = cc != null && cc.toLowerCase().contains("far");
                    int cur = farcc ? 4 : 2;   // Stack[n] = BP+n+2, so the first far parameter is Stack[4]
                    for (int i = 0; i < names.size(); i++) {
                        DataType dt = types.get(i);
                        VariableStorage vs = new VariableStorage(currentProgram,
                                sp.getAddress(cur), dt.getLength());
                        try {
                            fn.addParameter(new ParameterImpl(names.get(i), dt, vs, currentProgram),
                                    SourceType.USER_DEFINED);
                        } catch (DuplicateNameException dup) {
                            // Ghidra regenerates the hidden return-storage parameter from
                            // the return type as soon as it is removed, so it is already
                            // there and must not be added twice.
                            println("KEEP-AUTO " + f[0] + " " + names.get(i));
                        }
                        cur += slotSize(dt);
                    }
                    ok++;
                } catch (Exception e) {
                    println("FAIL " + f[0] + " " + e.getClass().getSimpleName() + ": " + e.getMessage());
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("ok=" + ok + " skipped=" + skipped + " failed=" + failed);
    }
}
