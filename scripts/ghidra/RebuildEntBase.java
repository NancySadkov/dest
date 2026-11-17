// Split the entity base from the 0x1726 agent-array element.
//
// Widths, from disassembly:
//   Entities[].base : OR word [BX+0x16],1 ; CMP byte [BX+0x18],0 ; byte 0x1a
//   0x1726 element  : CMP word [BX+0x17] ; CMP word [BX+0x19]   (agnt_t, unchanged)
//
// So entBase_t has a word at 0x14, a word at 0x16 (0x16..0x17) and bytes at
// 0x18/0x19/0x1a, while agnt_t keeps its four-byte value at 0x17.
//
// Args: none
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;

public class RebuildEntBase extends GhidraScript {
    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType agntG = dtm.getDataType("/st.h/agntG_t");
        if (agntG == null) { println("missing agntG_t"); return; }
        StructureDataType b = new StructureDataType(new CategoryPath("/st.h"), "entBase_t", 0);
        DataType u8 = ByteDataType.dataType;
        DataType u16 = WordDataType.dataType;
        Pointer gptr = new PointerDataType(agntG, 4, dtm);

        b.add(u16, "x", null);
        b.add(u16, "y", null);
        b.add(u16, "targetX", null);
        b.add(u16, "targetY", null);
        b.add(u16, "destX", null);
        b.add(u16, "destY", null);
        b.add(u8, "target", null);
        b.add(u8, "gindex", null);
        b.add(u8, "animFrame", null);
        b.add(u8, "level", null);
        b.add(u8, "health", null);
        b.add(u8, null, null);          /* 0x11 */
        b.add(u8, null, null);          /* 0x12 */
        b.add(u8, null, null);          /* 0x13 */
        b.add(u16, "flags14", "word tested with & 1 (field_0x13.lo + 1)");
        b.add(u16, "flags16", "word OR-ed with 1 in the constructor");
        b.add(u8, null, null);          /* 0x18 */
        b.add(u8, null, null);          /* 0x19 */
        b.add(u8, null, null);          /* 0x1a */
        b.add(u16, "owner", null);
        b.add(gptr, "gdata", null);
        b.add(u8, "strength", null);
        b.add(u8, null, null);          /* 0x22 */
        b.add(u8, null, null);          /* 0x23 */
        b.add(u8, null, null);          /* 0x24 */
        b.add(u8, null, null);          /* 0x25 */
        b.add(u16, "screenX", null);
        b.add(u16, "screenY", null);
        b.add(u8, null, null);          /* 0x2a */
        b.add(u16, "flags", null);
        b.add(u8, null, null);          /* 0x2d */
        b.add(u8, "variant", null);
        b.add(u8, "faction", null);
        b.add(u8, null, null);          /* 0x30 */
        b.add(u8, null, null);          /* 0x31 */
        b.add(u8, null, null);          /* 0x32 */
        b.add(u8, null, null);          /* 0x33 */
        println("entBase_t length=" + b.getLength());
        DataType made = dtm.addDataType(b, null);
        println("added " + made.getPathName());

        DataType ent = dtm.getDataType("/entity_t");
        if (ent instanceof Structure) {
            Structure s = (Structure) ent;
            while (s.getNumComponents() > 0) s.deleteAtOffset(s.getComponent(0).getOffset());
            s.add(made, "base", null);
            s.add(u8, "field_0x34", null);
            s.add(u8, "field_0x35", null);
            s.add(u8, "dir", null);
            println("entity_t length=" + s.getLength());
        }
    }
}
