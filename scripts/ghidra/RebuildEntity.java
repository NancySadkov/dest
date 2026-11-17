// Rebuild entity_t as agnt_t plus its three tail bytes.
//
// Evidence:
//   Entities is stshAlloc(33000) and holds 600 records, so sizeof == 55.
//   The struct is the agent record plus three bytes (agnt_t is 52).
//   Byte 0x36 is reduced modulo 6 into -3..3 to pick a sprite direction
//   (agnt_3b1d_0c9f), so it is a direction, not reserved.
//   0x34 is shifted left in ovc22 (a bit field); 0x35 has no reader yet.
//
// Args: none
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;

public class RebuildEntity extends GhidraScript {
    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType dt = dtm.getDataType("/entity_t");
        DataType agnt = dtm.getDataType("/st.h/agnt_t");
        if (!(dt instanceof Structure) || agnt == null) {
            println("missing entity_t or agnt_t");
            return;
        }
        Structure s = (Structure) dt;
        int tx = currentProgram.startTransaction("rebuild entity_t");
        try {
            while (s.getNumComponents() > 0) {
                s.deleteAtOffset(s.getComponent(0).getOffset());
            }
            s.add(agnt, "base", "the agent record");
            s.add(ByteDataType.dataType, "field_0x34", "shifted left in ovc22");
            s.add(ByteDataType.dataType, "field_0x35", null);
            s.add(ByteDataType.dataType, "dir", "sprite direction, reduced mod 6");
            println("entity_t length=" + s.getLength());
            for (int i = 0; i < s.getNumComponents(); i++) {
                DataTypeComponent c = s.getComponent(i);
                println("  +" + c.getOffset() + " " + c.getFieldName()
                        + " : " + c.getDataType().getName() + " [" + c.getLength() + "]");
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
