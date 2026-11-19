// Create squarerec_t and apply it as SquareRecs[300] at 17f8:0000 in one transaction.
// Record layout: +0 x word, +2 y word, +4..+0x12 15 opaque bytes (copied wholesale, never
// individually read).  SquareRecCount is capped at 299, so 300 records; 300 * 0x13 = 5700.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class MakeSquareRecs extends GhidraScript {
    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        Address base = currentProgram.getAddressFactory().getAddress("17f8:0000");
        int tx = currentProgram.startTransaction("make squarerec_t + SquareRecs");
        try {
            DataType existing = dtm.getDataType("/st.h/squarerec_t");
            Structure s;
            if (existing instanceof Structure) {
                s = (Structure) existing;
                while (s.getNumComponents() > 0) s.deleteAtOffset(s.getComponent(0).getOffset());
            } else {
                s = new StructureDataType(new CategoryPath("/st.h"), "squarerec_t", 0, dtm);
                dtm.addDataType(s, DataTypeConflictHandler.DEFAULT_HANDLER);
            }
            s.add(new WordDataType(), 2, "x", "Square x, compared with the requested x in attact_usesSquareRecCount / unit_usesAlignUp42.");
            s.add(new WordDataType(), 2, "y", "Square y, compared with the requested y in the same readers.");
            s.add(new ArrayDataType(ByteDataType.dataType, 15, 1), 15, "reserved",
                    "Copied with the whole 0x13-byte record (memcpy/fmemmove) but no individual reader in the recovered code.");
            println("struct size=" + s.getLength() + " fields=" + s.getNumComponents());

            ArrayDataType arr = new ArrayDataType(s, 300, s.getLength());
            clearListing(base, base.add(arr.getLength() - 1));
            createData(base, arr);
            Symbol sym = currentProgram.getSymbolTable().getPrimarySymbol(base);
            if (sym != null) sym.setName("SquareRecs", SourceType.USER_DEFINED);
            else currentProgram.getSymbolTable().createLabel(base, "SquareRecs", SourceType.USER_DEFINED);
            currentProgram.getListing().setComment(base, CodeUnit.EOL_COMMENT,
                    "300 square records of 0x13 bytes (SquareRecCount max 299); x at +0, y at +2, 15 opaque bytes. game4State/game4InitState were record 0/1 x; ExitStart/ExitEnd have zero refs and are spurious.");
            println("array size=" + arr.getLength() + " count=" + arr.getNumElements());
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
