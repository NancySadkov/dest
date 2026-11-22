// Undo AddBldGfxTable: clear the array at 2410:8ed0 and delete the struct type.
// The 248-entry guess covered 2976 bytes and swallowed neighbouring symbols
// (globals dropped from 1762 to 1432), so the change is reverted.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class RemoveBldGfxTable extends GhidraScript {
    public void run() throws Exception {
        int tx = currentProgram.startTransaction("remove bldgfx table");
        try {
            Address base = currentProgram.getAddressFactory().getAddress("2410:8ed0");
            Data d = currentProgram.getListing().getDataAt(base);
            int len = (d != null) ? d.getLength() : 2976;
            clearListing(base, base.add(len - 1));
            Symbol s = currentProgram.getSymbolTable().getPrimarySymbol(base);
            if (s != null) s.delete();
            println("cleared " + len + " bytes at " + base);
            DataTypeManager dtm = currentProgram.getDataTypeManager();
            DataType t = dtm.getDataType("/bldgfx_inst_t");
            if (t != null) {
                dtm.remove(t, monitor);
                println("removed struct /bldgfx_inst_t");
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
