// Retype one-byte parameters that the body reads as a whole word.
//
// A `char` parameter occupies a full word on the stack, because C promotes it at
// the call.  If the callee really only wants a byte it reads `byte ptr [BP+d]`,
// and Ghidra's one-byte model is right.  If it reads `word ptr [BP+d]` the
// parameter is a 16-bit value, and leaving it typed as a byte makes Ghidra
// create an overlapping high variable that it prints with a leading underscore
// and never declares (`_count`, `_shade1`, `_uStack0004`).
//
// Evidence per change is the instruction that performs the word access.
// The stack slot of a one-byte parameter is already two bytes (slotSize treats
// 1 and 2 alike), so retyping does not move any following parameter.
//
// Args: [apply]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.util.*;
import java.util.regex.*;

public class FixByteParams extends GhidraScript {
    static int slotSize(DataType t) {
        int len = t.getLength();
        if (len <= 0) return 2;
        return len <= 2 ? 2 : 4;
    }

    @Override
    public void run() throws Exception {
        boolean apply = getScriptArgs().length > 0 && getScriptArgs()[0].equals("apply");
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType wide = dtm.getDataType("/int");
        if (wide == null) { println("NOTYPE /int"); return; }
        int changed = 0;
        int tx = currentProgram.startTransaction("widen byte parameters");
        try {
            for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) {
                if (fn.isThunk()) continue;
                Variable[] ps = fn.getParameters();
                if (ps.length == 0) continue;
                String cc = fn.getCallingConventionName();
                boolean farcc = cc != null && cc.toLowerCase().contains("far");
                int cur = farcc ? 6 : 4;
                List<Instruction> insns = new ArrayList<>();
                for (Instruction ins : currentProgram.getListing().getInstructions(fn.getBody(), true))
                    insns.add(ins);
                for (int k = 0; k < ps.length; k++) {
                    DataType t = ps[k].getDataType();
                    int size = slotSize(t);
                    String nm = ps[k].getName();
                    if (t.getLength() == 1 && !(t instanceof Pointer)
                            && !nm.startsWith("__return_storage_ptr__")) {
                        Pattern p = Pattern.compile(
                                "word ptr (?:ss:)?\\[BP \\+ 0x" + Integer.toHexString(cur) + "\\]");
                        String witness = null;
                        for (Instruction ins : insns) {
                            if (p.matcher(ins.toString()).find()) {
                                witness = ins.getAddress() + " " + ins.toString();
                                break;
                            }
                        }
                        if (witness != null) {
                            println((apply ? "WIDEN " : "WOULD WIDEN ") + fn.getEntryPoint() + " "
                                    + fn.getName() + " #" + k + " " + nm + " : " + t.getName()
                                    + " -> int   [" + witness + "]");
                            if (apply) {
                                ps[k].setDataType(wide, SourceType.USER_DEFINED);
                                ps[k].setComment("16-bit parameter: the body reads the whole word ("
                                        + witness + ")");
                            }
                            changed++;
                        }
                    }
                    cur += size;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println((apply ? "widened=" : "would-widen=") + changed);
    }
}
