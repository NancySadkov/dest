// Rebuild /st.h/agntG_t from the accesses through agnt_t->gdata.
//
// The record is 149 bytes at segment 195d, offset 0x26d6 + gindex * 0x95.
// Every offset below was observed at least once (search for `0x1d) + 0xNN` on
// a typed agent record):
//
//   0x1b..0x23  three (left, right, height) triples used by three draw paths:
//               (g->0x1b + x) >> 1, (g->0x1c - g->0x1b) >> 1, (g->0x1d) >> 1
//               and the same with 0x1e/0x1f/0x20 and 0x21/0x22/0x23
//   0x3c, 0x3e, 0x40   16-bit values (0x3c and 0x40 are only ever masked)
//   0x42, 0x46, 0x50, 0x51, 0x53   state bytes compared with small constants
//
// The old structure had these as one-byte `undefined` members, which made the
// three 16-bit fields impossible to type.
//
// Args: none
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;

public class RebuildAgntG extends GhidraScript {
    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType dt = dtm.getDataType("/st.h/agntG_t");
        DataType spr = dtm.getDataType("/st.h/spr_t");
        DataType anm = dtm.getDataType("/st.h/anm_t");
        DataType far = dtm.getDataType("/x86.h/far_t");
        DataType i8 = SignedByteDataType.dataType;
        if (!(dt instanceof Structure) || spr == null || anm == null || far == null) {
            println("missing types");
            return;
        }
        Structure s = (Structure) dt;
        Pointer sprPtr = new PointerDataType(spr, 4, dtm);
        Pointer anmPtr = new PointerDataType(anm, 4, dtm);
        Pointer charPtr = new PointerDataType(new CharDataType(), 4, dtm);
        Array extents = new ArrayDataType(new ArrayDataType(i8, 3, -1), 3, -1);

        int tx = currentProgram.startTransaction("rebuild agntG_t");
        try {
            while (s.getNumComponents() > 0) {
                s.deleteAtOffset(s.getComponent(0).getOffset());
            }
            s.add(ByteDataType.dataType, "ai", "0 = player controlled, 1 = computer");
            s.add(ByteDataType.dataType, "type", null);
            s.add(i8, "nanims", null);
            s.add(new ArrayDataType(sprPtr, 6, 4), "sprs", "sprite stash handles");
            s.add(extents, "extents",
                  "three (left,right,height) triples, one per draw path");
            s.add(charPtr, "name", null);
            s.add(anmPtr, "anms", "animation definitions");
            s.add(new ArrayDataType(ShortDataType.dataType, 6, 2), "sprfls",
                  "sprite file ids");
            s.add(ByteDataType.dataType, null, null);          /* 0x38 */
            s.add(ByteDataType.dataType, null, null);          /* 0x39 */
            s.add(ByteDataType.dataType, null, null);          /* 0x3a */
            s.add(ByteDataType.dataType, null, null);          /* 0x3b */
            s.add(WordDataType.dataType, "flags", "only ever masked");   /* 0x3c */
            s.add(WordDataType.dataType, null, null);          /* 0x3e */
            s.add(WordDataType.dataType, null, null);          /* 0x40 */
            s.add(ByteDataType.dataType, null, null);          /* 0x42 state */
            s.add(new ArrayDataType(ByteDataType.dataType, 3, 1), "reserved_43",
                  "no reader found in the export");
            s.add(ByteDataType.dataType, null, null);          /* 0x46 state */
            s.add(new ArrayDataType(ByteDataType.dataType, 9, 1), "reserved_47",
                  "no reader found in the export");
            s.add(ByteDataType.dataType, null, null);          /* 0x50 state */
            s.add(ByteDataType.dataType, null, null);          /* 0x51 -1 sentinel */
            s.add(ByteDataType.dataType, null, null);          /* 0x52 */
            s.add(ByteDataType.dataType, null, null);          /* 0x53 */
            s.add(new ArrayDataType(ShortDataType.dataType, 6, 2), "prtfls",
                  "portrait file ids");
            s.add(new ArrayDataType(far, 6, 4), "prts", "portrait stash handles");
            s.add(new ArrayDataType(far, 6, 4), "prtpals", "portrait palettes");
            s.add(charPtr, "wpn_name", null);
            s.add(ByteDataType.dataType, null, null);          /* 0x94 */
            println("agntG_t length=" + s.getLength());
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
