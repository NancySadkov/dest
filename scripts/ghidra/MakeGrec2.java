// Recreate grec_t in the data type manager and apply it at 21f2:0000 (GRecords base).
// Args: none
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class MakeGrec2 extends GhidraScript {
    private void add(Structure s, DataType t, String name, String comment) {
        s.add(t, t.getLength(), name, comment);
    }

    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        Address base = currentProgram.getAddressFactory().getAddress("21f2:0000");
        int tx = currentProgram.startTransaction("make grec_t v2");
        try {
            DataType dt = dtm.getDataType("/st.h/grec_t");
            if (dt != null) dtm.remove(dt, monitor);
            Structure s = new StructureDataType(new CategoryPath("/st.h"), "grec_t", 0, dtm);
            add(s, new WordDataType(), "buildTimer", "Compared with 20000 and reset to 3 (ovc23_placeBuilding).");
            add(s, new WordDataType(), "x", "Left column of the record's span.");
            add(s, new WordDataType(), "y", "Row of the record (compared with GfxRndSeed2).");
            add(s, new ByteDataType(), "reserved06", "No reader or writer in the recovered code.");
            add(s, new ByteDataType(), "width", "Span width: x0 <= x <= x0+width-1.");
            add(s, new ByteDataType(), "reserved08", "No reader or writer in the recovered code.");
            add(s, new ByteDataType(), "party", "Party sheet index (*(undefined4 *)(party*4)).");
            add(s, new ByteDataType(), "reserved0a", "No reader or writer in the recovered code.");
            add(s, new ByteDataType(), "countdown", "Decremented by ovc23_tickRecordsAt.");
            add(s, new ByteDataType(), "reserved0c", "No reader or writer in the recovered code.");
            add(s, new ByteDataType(), "kind", "Tested with & 3; 1 is a construction record.");
            add(s, new ByteDataType(), "done", "Set when the countdown reaches zero.");
            add(s, new WordDataType(), "tick", "Assigned GameTick by ovc23_tickRecordsAt.");
            add(s, new ByteDataType(), "reserved11", "No reader or writer in the recovered code.");
            DataType stored = dtm.addDataType(s, DataTypeConflictHandler.REPLACE_HANDLER);
            println("type stored=" + stored.getPathName() + " len=" + stored.getLength()
                    + " comps=" + ((Structure) stored).getNumComponents());

            clearListing(base, base.add(stored.getLength() - 1));
            Data d = createData(base, stored);
            println("data=" + (d == null ? "null" : d.getDataType().getPathName() + " len=" + d.getLength()));
            Symbol sym = currentProgram.getSymbolTable().getPrimarySymbol(base);
            if (sym == null) currentProgram.getSymbolTable().createLabel(base, "GRecords", SourceType.USER_DEFINED);
            else sym.setName("GRecords", SourceType.USER_DEFINED);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
