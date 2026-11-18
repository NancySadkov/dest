// Rebuild entity_t: agnt_t plus a 16-bit tick stamp and the direction byte.
//
// Evidence:
//   Entities is stshAlloc(33000) and holds 600 records, so sizeof == 55 (0x37).
//   The struct is the agent record (agnt_t, 52 bytes) plus three bytes.
//   +0x34 is a 16-bit GameTick timestamp - the machine code at 5d45:035e/04c0 is
//     SUB AX,word ptr ES:[BX + 0x34]
//     MOV word ptr ES:[BX + 0x34],AX
//   and the surrounding code tests `GameTick - tick < 0x19` before re-running a
//   periodic update.  The decompiler printed a 32-bit lvalue for the store, but the
//   instruction is a word, so the two 1-byte components become one uint16_t.
//   +0x36 is reduced modulo 6 into -3..3 to pick a sprite direction
//   (agnt_3b1d_0c9f), so it is a direction, not reserved.
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
        DataType word = dtm.getDataType("/stdint.h/uint16_t");
        if (!(dt instanceof Structure) || agnt == null || word == null) {
            println("missing entity_t, agnt_t or uint16_t");
            return;
        }
        Structure s = (Structure) dt;
        int tx = currentProgram.startTransaction("rebuild entity_t");
        try {
            while (s.getNumComponents() > 0) {
                s.deleteAtOffset(s.getComponent(0).getOffset());
            }
            s.add(agnt, "base", "the agent record");
            s.add(word, "tick", "last GameTick this entity was updated (word at 0x34)");
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
