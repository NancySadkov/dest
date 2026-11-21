// Widen parameters that the body loads with LES/LDS from their own stack slot.
//
// `LES BX,[BP+6]` reads four bytes as one segment:offset pair, so the parameter
// occupying BP+6 is a four-byte pointer.  When the model types it as a two-byte
// near pointer, Ghidra uses only the offset word for the "pointer" and the
// segment word (0x2410, the DGROUP segment) leaks into an adjacent parameter.
// That is what produces expressions such as (char *)"puppetmaker" + 3.
//
// The loop repeats because widening one parameter moves those after it.
//
// Args: [apply]   - anything else means report only.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.util.*;
import java.util.regex.*;

public class FixFarParams extends GhidraScript {
    static int slotSize(DataType t) {
        int len = t.getLength();
        if (len <= 0) return 2;
        return len <= 2 ? 2 : 4;
    }

    static boolean isNearPtr(DataType t) {
        return t instanceof Pointer && t.getLength() == 2;
    }

    @Override
    public void run() throws Exception {
        boolean apply = getScriptArgs().length > 0 && getScriptArgs()[0].equals("apply");
        Pattern lesLds = Pattern.compile("^(LES|LDS) ");
        Pattern bpPlus = Pattern.compile("BP \\+ 0x([0-9a-fA-F]+)");
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        int widened = 0, mergeNeeded = 0, absorbedParams = 0, blockedCount = 0;
        Set<String> mergeFns = new TreeSet<>();
        int tx = currentProgram.startTransaction("widen far parameters");
        try {
            for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) {
                if (fn.isThunk()) continue;
                boolean changed = true;
                int guard = 0;
                Set<Integer> done = new TreeSet<>();
                while (changed && guard++ < 12) {
                    changed = false;
                    Variable[] ps = fn.getParameters();
                    if (ps.length == 0) break;
                    String cc = fn.getCallingConventionName();
                    boolean farcc = cc != null && cc.toLowerCase().contains("far");
                    int cur = farcc ? 4 : 2;   // Stack[n] = BP+n+2
                    Map<Integer, Integer> at = new HashMap<>();
                    Map<Integer, Integer> startOf = new HashMap<>();
                    for (int k = 0; k < ps.length; k++) {
                        at.put(cur, k);
                        startOf.put(k, cur);
                        cur += slotSize(ps[k].getDataType());
                    }
                    Set<Integer> disps = new TreeSet<>();
                    for (Instruction ins : currentProgram.getListing()
                            .getInstructions(fn.getBody(), true)) {
                        String s = ins.toString();
                        if (!lesLds.matcher(s).find()) continue;
                        Matcher m = bpPlus.matcher(s);
                        while (m.find()) disps.add(Integer.parseInt(m.group(1), 16));
                    }
                    for (int d : disps) {
                        Integer k = at.get(d);
                        if (k == null) {
                            if (!done.add(-d)) continue;
                            printf("MERGE %s %s BP+0x%x : no parameter starts there\n",
                                    fn.getEntryPoint(), fn.getName(), d);
                            mergeNeeded++;
                            mergeFns.add(fn.getName());
                            continue;
                        }
                        if (!apply && !done.add(d)) continue;
                        DataType t = ps[k].getDataType();
                        if (!isNearPtr(t)) continue;
                        String pname = ps[k].getName();
                        if (pname.startsWith("__return_storage_ptr__")) continue;
                        // The next parameter may start at d+2.  It is only the segment
                        // half of this pointer if it is named as one ("...Seg"); any
                        // other parameter is a real argument that must be kept, and
                        // widening here would need its offset moved by hand.
                        String absorbed = null;
                        boolean blocked = false;
                        if (k + 1 < ps.length && startOf.get(k + 1) == d + 2) {
                            String nxt = ps[k + 1].getName();
                            if (nxt.endsWith("Seg") || nxt.endsWith("seg")) absorbed = nxt;
                            else blocked = true;
                        }
                        if (blocked) {
                            println("NEEDS-OFFSET " + fn.getEntryPoint() + " " + fn.getName() + " #"
                                    + k + " " + pname + " : " + t.getName()
                                    + " is followed by real parameter '" + ps[k + 1].getName() + "'");
                            blockedCount++;
                            continue;
                        }
                        DataType base = ((Pointer) t).getDataType();
                        DataType wide = new PointerDataType(base, 4, dtm);
                        println((apply ? "WIDEN " : "WOULD WIDEN ") + fn.getEntryPoint() + " "
                                + fn.getName() + " #" + k + " " + ps[k].getName() + " : "
                                + t.getName() + " -> " + wide.getName()
                                + (absorbed == null ? "" : "  (absorbs segment half '" + absorbed + "')"));
                        if (apply) {
                            if (absorbed != null) fn.removeParameter(k + 1);
                            Variable target = fn.getParameter(k);
                            target.setDataType(wide, SourceType.USER_DEFINED);
                            target.setComment("four-byte pointer: the body loads it with LES/LDS"
                                    + (absorbed == null ? ""
                                       : "; absorbs the former parameter '" + absorbed
                                         + "', which was the segment half"));
                            absorbedParams++;
                        }
                        widened++;
                        changed = true;
                        break;   // offsets are stale after a change; recompute
                    }
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println((apply ? "widened=" : "would-widen=") + widened + " merge-needed=" + mergeNeeded
                + " merge-functions=" + mergeFns.size() + " absorbed-params=" + absorbedParams
                + " needs-offset=" + blockedCount);
        for (String s : mergeFns) println("  merge-fn " + s);
    }
}
