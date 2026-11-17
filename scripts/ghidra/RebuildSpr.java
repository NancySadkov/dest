// Recover spr_t from the code that uses it.
//
// Evidence (ovc15 stshRleAnims / stshStoreSprite):
//   _fsetmem(spr, 0xb0, 0)                  -> sizeof(spr_t) == 176
//   spr->frames[i].seg / .ofs               -> frames is an array of far_t
//   176 - sizeof(far anm_t *) = 172, 172 / 4 = 43 frames
//
// The old definition had one pointer and 172 one-byte `undefined` members
// because the decompiler could not see the array.  The struct is rebuilt in
// place so existing references keep pointing at /st.h/spr_t.
//
// Args: none
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;

public class RebuildSpr extends GhidraScript {
    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType anm = dtm.getDataType("/st.h/anm_t");
        DataType far = dtm.getDataType("/x86.h/far_t");
        DataType dt = dtm.getDataType("/st.h/spr_t");
        if (anm == null || far == null || !(dt instanceof Structure)) {
            println("missing types: anm=" + anm + " far=" + far + " dt=" + dt);
            return;
        }
        Structure s = (Structure) dt;
        // A far pointer in this 16-bit program is four bytes; the default
        // pointer size is two, so it must be spelled out.
        Pointer anmFar = new PointerDataType(anm, 4, dtm);

        int tx = currentProgram.startTransaction("rebuild spr_t");
        try {
            while (s.getNumComponents() > 0) {
                s.deleteAtOffset(s.getComponent(0).getOffset());
            }
            s.add(anmFar, "anm", "animation table for this sprite");
            s.add(new ArrayDataType(far, 43, 4), "frames",
                  "far pointers to the 43 frame records");
            println("spr_t length=" + s.getLength());
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
