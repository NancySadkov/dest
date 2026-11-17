// Revert entity_t.base to agnt_t: the split was based on a misreading.
//
// agnt_3b1d_0c9f, re-decompiled after the split, shows
//   uVar1 = *(undefined4 *)((int)&ent->base.flags16 + 1);   /* 0x17, a far pointer */
// so the entity record does use 0x17..0x1a as a four-byte pointer, exactly as
// the 0x1726 array does.  The word at 0x16 and the pointer at 0x17 overlap
// inside one record, so two structures cannot fix it.
//
// Args: none
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;

public class RevertEntityBase extends GhidraScript {
    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType agnt = dtm.getDataType("/st.h/agnt_t");
        DataType ent = dtm.getDataType("/entity_t");
        if (!(ent instanceof Structure) || agnt == null) { println("missing"); return; }
        Structure s = (Structure) ent;
        int tx = currentProgram.startTransaction("revert entity base");
        try {
            while (s.getNumComponents() > 0) s.deleteAtOffset(s.getComponent(0).getOffset());
            s.add(agnt, "base", "same record as the 0x1726 array; 0x16/0x17 overlap");
            s.add(ByteDataType.dataType, "field_0x34", null);
            s.add(ByteDataType.dataType, "field_0x35", null);
            s.add(ByteDataType.dataType, "dir", "sprite direction, reduced mod 6");
            println("entity_t length=" + s.getLength());
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
