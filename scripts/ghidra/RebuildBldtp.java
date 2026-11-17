// Rebuild /st.h/bldtp_t from the accesses at BuildingTypes[idx] + offset.
//
// BuildingTypes is at 195d:010e and the code indexes it as
// `*(T *)(idx * 0x27 + 0x10e + off)`, so every offset below is observed:
//
//   0x00/0x02  name pointer halves      0x04/0x06  description halves
//   0x08/0x0a  action halves            0x0c  byte compared with 2
//   0x0d       byte compared with 2, 3  0x0e  byte compared with a value
//   0x0f       byte                     0x10  byte, bits 0 and 1 tested
//   0x11       type (1 << n mask)       0x12  expinc
//   0x13       word masked with 0x20 / 0x800
//   0x15       income (signed compare)  0x17  cost
//   0x19       housing (accumulated)    0x1c  storage
//   0x20       sight                    0x22  durability (100 - x)
//   0x23       tier (compared with 1,2,3)
//   0x24, 0x25, 0x26  bytes
//
// The record is 39 bytes; element 12 sits at 195d:0300, which is
// 0x010e + 12*0x27 + 0x1e, so the base and stride are confirmed.
//
// Args: none
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;

public class RebuildBldtp extends GhidraScript {
    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType dt = dtm.getDataType("/st.h/bldtp_t");
        if (!(dt instanceof Structure)) { println("missing bldtp_t"); return; }
        Structure s = (Structure) dt;
        Pointer charPtr = new PointerDataType(new CharDataType(), 4, dtm);

        int tx = currentProgram.startTransaction("rebuild bldtp_t");
        try {
            while (s.getNumComponents() > 0) {
                s.deleteAtOffset(s.getComponent(0).getOffset());
            }
            s.add(charPtr, "name", null);
            s.add(charPtr, "description", null);
            s.add(charPtr, "action", null);
            s.add(ByteDataType.dataType, null, null);          /* 0x0c == 2 */
            s.add(ByteDataType.dataType, null, null);          /* 0x0d < 2, < 3 */
            s.add(ByteDataType.dataType, null, null);          /* 0x0e */
            s.add(ByteDataType.dataType, null, null);          /* 0x0f */
            s.add(ByteDataType.dataType, "flags", "bits 0 and 1 tested");  /* 0x10 */
            s.add(SignedByteDataType.dataType, "type", "used as a 1 << n mask");
            s.add(SignedByteDataType.dataType, "expinc", null);
            s.add(WordDataType.dataType, "flags2", "masked with 0x20 and 0x800");
            s.add(ShortDataType.dataType, "income", "compared as signed");
            s.add(WordDataType.dataType, "cost", null);
            s.add(ByteDataType.dataType, "housing", "accumulated into a sum");
            s.add(ByteDataType.dataType, null, null);          /* 0x1a */
            s.add(ByteDataType.dataType, null, null);          /* 0x1b */
            s.add(WordDataType.dataType, "storage", null);
            s.add(ByteDataType.dataType, null, null);          /* 0x1e */
            s.add(ByteDataType.dataType, null, null);          /* 0x1f */
            s.add(WordDataType.dataType, "sight", null);
            s.add(ByteDataType.dataType, "durability", "100 - x");
            s.add(SignedByteDataType.dataType, "tier", "compared with 1, 2, 3");
            s.add(ByteDataType.dataType, null, null);          /* 0x24 */
            s.add(ByteDataType.dataType, null, null);          /* 0x25 */
            s.add(ByteDataType.dataType, null, null);          /* 0x26 */
            println("bldtp_t length=" + s.getLength());
            for (int i = 0; i < s.getNumComponents(); i++) {
                DataTypeComponent c = s.getComponent(i);
                println("  +" + c.getOffset() + " " + c.getFieldName()
                        + " : " + c.getDataType().getName());
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
