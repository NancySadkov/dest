// Widen LES/LDS-loaded parameters and lay the prototype out with explicit stack
// offsets, so widening never displaces a following parameter.
//
// Ghidra does not reflow stack parameters after a type change: a two-byte
// pointer grown to four collides with whatever followed it.  This script
// therefore rebuilds the whole parameter list at computed offsets instead of
// relying on setDataType.
//
// A parameter whose name ends in "Seg" and which sits in the segment half of a
// widened pointer is the segment, not an argument, and is dropped.
//
// Args: [apply]   (anything else = report only)
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.util.*;
import java.util.regex.*;

public class FixFarParamOffsets extends GhidraScript {
    static int slotSize(DataType t) {
        int len = t.getLength();
        if (len <= 0) return 2;
        return len <= 2 ? 2 : 4;
    }

    static boolean isNearPtr(DataType t) {
        return t instanceof Pointer && t.getLength() == 2;
    }

    static boolean isSeg(String n) {
        return n.endsWith("Seg") || n.endsWith("seg");
    }

    @Override
    public void run() throws Exception {
        boolean apply = getScriptArgs().length > 0 && getScriptArgs()[0].equals("apply");
        Pattern lesLds = Pattern.compile("^(LES|LDS) ");
        Pattern bpPlus = Pattern.compile("BP \\+ 0x([0-9a-fA-F]+)");
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        AddressSpace sp = null;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            for (Variable v : f.getParameters()) {
                Address a = v.getVariableStorage().getMinAddress();
                if (a != null) { sp = a.getAddressSpace(); break; }
            }
            if (sp != null) break;
        }
        if (sp == null) { println("NO_STACK_SPACE"); return; }

        int changed = 0, dropped = 0;
        int tx = currentProgram.startTransaction("far param offsets");
        try {
            for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) {
                if (fn.isThunk()) continue;
                Variable[] ps = fn.getParameters();
                if (ps.length == 0) continue;
                Set<Integer> les = new TreeSet<>();
                List<Instruction> insns = new ArrayList<>();
                for (Instruction ins : currentProgram.getListing().getInstructions(fn.getBody(), true))
                    insns.add(ins);
                for (Instruction ins : insns) {
                    String s = ins.toString();
                    if (!lesLds.matcher(s).find()) continue;
                    Matcher m = bpPlus.matcher(s);
                    while (m.find()) les.add(Integer.parseInt(m.group(1), 16));
                }
                // `PUSH [BP+d+2] ; PUSH [BP+d]` is how cdecl16far passes one far
                // pointer on to another function: the two words are one argument.
                Matcher pushM = Pattern.compile("PUSH word ptr \\[BP \\+ 0x([0-9a-fA-F]+)\\]")
                        .matcher("");
                for (int i = 0; i + 1 < insns.size(); i++) {
                    pushM.reset(insns.get(i).toString());
                    if (!pushM.matches()) continue;
                    int hi = Integer.parseInt(pushM.group(1), 16);
                    pushM.reset(insns.get(i + 1).toString());
                    if (pushM.matches() && Integer.parseInt(pushM.group(1), 16) == hi - 2)
                        les.add(hi - 2);
                }
                if (les.isEmpty()) continue;

                String cc = fn.getCallingConventionName();
                boolean farcc = cc != null && cc.toLowerCase().contains("far");
                int base = farcc ? 6 : 4;

                // pass 1: decide types and offsets
                List<String> names = new ArrayList<>();
                List<DataType> types = new ArrayList<>();
                List<Integer> offs = new ArrayList<>();
                int cur = base;
                boolean touches = false;
                for (int k = 0; k < ps.length; k++) {
                    String nm = ps[k].getName();
                    DataType t = ps[k].getDataType();
                    if (nm.startsWith("__return_storage_ptr__")) {
                        names.add(nm); types.add(t); offs.add(cur); cur += slotSize(t); continue;
                    }
                    if (isSeg(nm) && k > 0 && isNearPtr(ps[k - 1].getDataType())
                            && offs.get(k - 1) + 2 == cur && types.get(k - 1).getLength() == 4) {
                        dropped++;      // segment half of the pointer just widened
                        continue;
                    }
                    if (les.contains(cur) && isNearPtr(t)) {
                        t = new PointerDataType(((Pointer) t).getDataType(), 4, dtm);
                        touches = true;
                    }
                    names.add(nm); types.add(t); offs.add(cur); cur += slotSize(t);
                }
                if (!touches) continue;

                StringBuilder b = new StringBuilder(fn.getName() + " -> ");
                for (int i = 0; i < names.size(); i++)
                    b.append(names.get(i)).append(':').append(types.get(i).getName())
                     .append("@").append(offs.get(i)).append("  ");
                println((apply ? "" : "WOULD ") + b);
                changed++;

                if (apply) {
                    for (int i = ps.length - 1; i >= 0; i--) fn.removeParameter(i);
                    fn.setCustomVariableStorage(true);
                    for (int i = 0; i < names.size(); i++) {
                        DataType t = types.get(i);
                        VariableStorage vs = new VariableStorage(currentProgram,
                                sp.getAddress(offs.get(i)), t.getLength());
                        fn.addParameter(new ParameterImpl(names.get(i), t, vs, currentProgram),
                                SourceType.USER_DEFINED);
                    }
                    println("   set " + fn.getPrototypeString(false, false));
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println((apply ? "changed=" : "would-change=") + changed + " dropped-seg=" + dropped);
    }
}
