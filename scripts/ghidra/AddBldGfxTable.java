// Create the 12-byte building-graphics record table at DGROUP:0x8ed0.
//
// Evidence (see doc/): the code reads a far pointer at +4 (ofs) and +6 (seg) from
// records selected by `i * 0xc` at ES:[0x8ed0], with ES = 0x2410 (DGROUP), and the
// index is the same one used for BuildingTypes[i] (248 entries).
// So the record is { byte[4]; far_t gfx; byte[4]; } and the table has 248 entries.
//
// The name is a GUESS: no symbol exists at 2410:8ed0 in the program.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class AddBldGfxTable extends GhidraScript {
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType far_t = dtm.getDataType("/x86.h/far_t");
        if (far_t == null) far_t = dtm.getDataType("/st.h/far_t");
        if (far_t == null) { println("NO far_t"); return; }
        DataType byteT = dtm.getDataType("/byte");
        if (byteT == null) byteT = dtm.getDataType("/undefined1");

        int tx = currentProgram.startTransaction("add bldgfx table");
        try {
            StructureDataType st = new StructureDataType("bldgfx_inst_t", 0, dtm);
            st.add(new ArrayDataType(byteT, 4, 1), "unknown0",
                    "GUESS: four bytes before the graphics pointer; readers/writers not identified");
            st.add(far_t, "gfx", "far pointer: ofs at +4, seg at +6");
            st.add(new ArrayDataType(byteT, 4, 1), "unknown1",
                    "GUESS: four bytes after the graphics pointer");
            DataType resolved = dtm.addDataType(st, DataTypeConflictHandler.REPLACE_HANDLER);
            println("struct " + resolved.getPathName() + " size=" + resolved.getLength());

            Address base = currentProgram.getAddressFactory().getAddress("2410:8ed0");
            ArrayDataType arr = new ArrayDataType(resolved, 248, resolved.getLength());
            clearListing(base, base.add(arr.getLength() - 1));
            createData(base, arr);
            Symbol s = currentProgram.getSymbolTable().getPrimarySymbol(base);
            if (s == null)
                s = currentProgram.getSymbolTable().createLabel(base, "GBldGfxInstances",
                        SourceType.USER_DEFINED);
            else
                s.setName("GBldGfxInstances", SourceType.USER_DEFINED);
            currentProgram.getListing().setComment(base, CommentType.EOL,
                    "GUESS: unnamed 12-byte building-graphics table; indexed with the same "
                    + "value as BuildingTypes (248 entries), gfx far pointer at +4/+6");
            println("array at " + base + " len=" + arr.getLength());
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
