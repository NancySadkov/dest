// Give the agent helpers their record type.
//
// Evidence: these functions read/write a record held in the agent segment at
// stride 0x34 (agnt_t, 52 bytes).  The ones that touch +0x36 need the wider
// entity_t (55 bytes = agnt_t plus 3 bytes).
//
// Args: none
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.util.*;

public class TypeAgentParams extends GhidraScript {
    static final String[][] AGNT = {
        // address      parameter name
        {"3b1d:0a53", "agnt"},   // clears 0xc,0xd,0xe,0x10,0x2b,0x2e of a record
        {"3b1d:0a8d", "agnt"},   // clears 0x10
        {"3b1d:0a9f", "agnt"},   // reads 0x1d, tests a flag of the referenced record
        {"3b1d:0ac0", "agnt"},   // reads 0x26 / 0x28 / 0xd of a record
        {"3b1d:0d1c", "agnt"},   // reads 0xe and 0x10
        {"3b1d:0d82", "agnt"},
    };
    static final String[][] ENT = {
        {"3b1d:0c7c", "ent"},    // reads +0x36 and reduces it mod 6
        {"3b1d:0c9f", "ent"},    // same, through the pointer at 0x17
        {"3b1d:0cc6", "ent"},
        {"3b1d:0cef", "ent"},
    };

    void retype(String[][] list, String typeName, DataType type) {
        FunctionManager fm = currentProgram.getFunctionManager();
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        Pointer ptr = new PointerDataType(type, 4, dtm);
        for (String[] e : list) {
            Address ad = currentProgram.getAddressFactory().getAddress(e[0]);
            Function f = fm.getFunctionAt(ad);
            if (f == null) { println("MISS " + e[0]); continue; }
            Variable[] ps = f.getParameters();
            if (ps.length < 1) { println("NOPARAM " + e[0]); continue; }
            try {
                ps[0].setDataType(ptr, SourceType.USER_DEFINED);
                ps[0].setName(e[1], SourceType.USER_DEFINED);
                println("typed " + e[0] + " p1 -> " + typeName + " * as " + e[1]);
            } catch (Throwable t) {
                println("FAIL " + e[0] + " : " + t);
            }
        }
    }

    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType agnt = dtm.getDataType("/st.h/agnt_t");
        DataType ent = dtm.getDataType("/entity_t");
        if (agnt == null || ent == null) {
            println("missing: agnt=" + agnt + " entity=" + ent);
            return;
        }
        int tx = currentProgram.startTransaction("type agent params");
        try {
            retype(AGNT, "agnt_t", agnt);
            retype(ENT, "entity_t", ent);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
