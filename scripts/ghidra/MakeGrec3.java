// Finish the grec_t creation: rename the stored .conflict type to grec_t and apply it at 21f2:0000.
// Args: none
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class MakeGrec3 extends GhidraScript {
    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        Address base = currentProgram.getAddressFactory().getAddress("21f2:0000");
        int tx = currentProgram.startTransaction("finish grec_t");
        try {
            DataType dt = dtm.getDataType("/st.h/grec_t.conflict");
            if (dt == null) dt = dtm.getDataType("/st.h/grec_t");
            if (!(dt instanceof Structure)) { println("NOSTRUCT"); return; }
            dt.setName("grec_t");
            Structure s = (Structure) dt;
            println("type=" + s.getPathName() + " len=" + s.getLength() + " comps=" + s.getNumComponents());
            clearListing(base, base.add(s.getLength() - 1));
            Data d = createData(base, s);
            println("data=" + (d == null ? "null" : d.getDataType().getPathName() + " len=" + d.getLength()));
            Symbol sym = currentProgram.getSymbolTable().getPrimarySymbol(base);
            if (sym == null) currentProgram.getSymbolTable().createLabel(base, "GRecords", SourceType.USER_DEFINED);
            else sym.setName("GRecords", SourceType.USER_DEFINED);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
