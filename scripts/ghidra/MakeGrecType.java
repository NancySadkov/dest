// Create grec_t (the 0x12-stride record used by the construction/GRecords table) and apply it to
// 21f2:0000 as the table base label GRecords.
//
// Field evidence (all offsets are from the six readers of the table):
//   +0x00 word   compared with 20000 and reset to 3 in ovc23_placeBuilding
//   +0x02 word   x0: ovc23_findRecordAt / ovc23_tickRecordsAt test x0 <= x <= x0+width-1
//   +0x04 word   y: compared with GfxRndSeed2
//   +0x07 byte   width: x span length
//   +0x09 byte   party: used as *(undefined4 *)(party*4) to reach the sheet
//   +0x0b byte   countdown: decremented by ovc23_tickRecordsAt
//   +0x0d byte   kind: tested with & 3 (==1 is a construction)
//   +0x0e byte   done: set to 1 when the countdown reaches 0
//   +0x0f word   tick: assigned GameTick
//   +0x06,+0x08,+0x0a,+0x0c,+0x11 have no reader and no writer in the recovered code.
//
// Args: none
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class MakeGrecType extends GhidraScript {
    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        Address base = currentProgram.getAddressFactory().getAddress("21f2:0000");
        int tx = currentProgram.startTransaction("make grec_t");
        try {
            DataType existing = dtm.getDataType("/st.h/grec_t");
            Structure s;
            if (existing instanceof Structure) {
                s = (Structure) existing;
                while (s.getNumComponents() > 0) s.deleteAtOffset(s.getComponent(0).getOffset());
            } else {
                s = new StructureDataType(new CategoryPath("/st.h"), "grec_t", 0, dtm);
                dtm.addDataType(s, DataTypeConflictHandler.DEFAULT_HANDLER);
            }
            s.add(new WordDataType(), 2, "buildTimer", "Compared with 20000 and reset to 3 (ovc23_placeBuilding).");
            s.add(new WordDataType(), 2, "x", "Left column of the record's span.");
            s.add(new WordDataType(), 2, "y", "Row of the record (compared with GfxRndSeed2).");
            s.add(new ByteDataType(), 1, "reserved06", "No reader or writer in the recovered code.");
            s.add(new ByteDataType(), 1, "width", "Span width: x0 <= x <= x0+width-1.");
            s.add(new ByteDataType(), 1, "reserved08", "No reader or writer in the recovered code.");
            s.add(new ByteDataType(), 1, "party", "Party sheet index (*(undefined4 *)(party*4)).");
            s.add(new ByteDataType(), 1, "reserved0a", "No reader or writer in the recovered code.");
            s.add(new ByteDataType(), 1, "countdown", "Decremented by ovc23_tickRecordsAt.");
            s.add(new ByteDataType(), 1, "reserved0c", "No reader or writer in the recovered code.");
            s.add(new ByteDataType(), 1, "kind", "Tested with & 3; 1 is a construction record.");
            s.add(new ByteDataType(), 1, "done", "Set when the countdown reaches zero.");
            s.add(new WordDataType(), 2, "tick", "Assigned GameTick by ovc23_tickRecordsAt.");
            s.add(new ByteDataType(), 1, "reserved11", "No reader or writer in the recovered code.");

            clearListing(base, base.add(s.getLength() - 1));
            createData(base, s);
            Symbol sym = currentProgram.getSymbolTable().getPrimarySymbol(base);
            if (sym == null) {
                currentProgram.getSymbolTable().createLabel(base, "GRecords", SourceType.USER_DEFINED);
            } else {
                sym.setName("GRecords", SourceType.USER_DEFINED);
            }
            println("ok grec_t len=" + s.getLength() + " at " + base
                    + " fields=" + s.getNumComponents());
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
