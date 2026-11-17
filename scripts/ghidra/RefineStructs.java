// Refine recovered structures: give every component a name, replace
// decompiler `undefined` types with sized integers, and apply the curated
// field names recovered so far.
//
// Args: [--dry-run]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.util.*;

public class RefineStructs extends GhidraScript {
    private boolean dry;

    // structure name -> offset -> field name
    private static final Map<String, Map<Integer, String>> NAMES = new HashMap<>();
    static {
        Map<Integer, String> m = new HashMap<>();
        m.put(0, "type");     // structure kind (matched against the filter mode)
        m.put(1, "pad");
        m.put(2, "name");     // far pointer to the displayed name
        NAMES.put("unk01_t", m);
    }

    private DataType sized(DataType dt, int len) {
        String n = dt.getName().toLowerCase();
        if (!n.startsWith("undefined") && !n.equals("byte") &&
            !n.equals("word") && !n.equals("dword") && !n.isEmpty())
            return dt;
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        switch (len) {
            case 1: return dtm.getDataType("/byte");
            case 2: return dtm.getDataType("/word");
            case 4: return dtm.getDataType("/dword");
            default: return dt;
        }
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        dry = a.length > 0 && a[0].equals("--dry-run");
        int structs = 0, renamed = 0, retyped = 0;
        Iterator<DataType> it = currentProgram.getDataTypeManager().getAllDataTypes();
        List<Structure> todo = new ArrayList<>();
        while (it.hasNext()) {
            DataType d = it.next();
            if (d instanceof Structure) todo.add((Structure) d);
        }
        for (Structure s : todo) {
            String base = s.getName();
            Map<Integer, String> names = NAMES.get(base);
            if (names == null) names = new HashMap<>();
            boolean changed = false;
            for (int i = 0; i < s.getNumComponents(); i++) {
                DataTypeComponent c = s.getComponent(i);
                int off = c.getOffset();
                int len = c.getLength();
                String name = c.getFieldName();
                String want = names.get(off);
                if (want == null && (name == null || name.isEmpty())) {
                    want = "field_0x" + Integer.toHexString(off);
                }
                DataType dt = sized(c.getDataType(), len);
                boolean fixType = dt != c.getDataType();
                if (want != null && !want.equals(name)) {
                    renamed++;
                    changed = true;
                    if (!dry)
                        s.replace(i, fixType ? dt : c.getDataType(), len, want, c.getComment());
                } else if (fixType) {
                    retyped++;
                    changed = true;
                    if (!dry)
                        s.replace(i, dt, len, name, c.getComment());
                }
            }
            if (changed) structs++;
        }
        println((dry ? "would refine " : "refined ") + structs +
                " structures, " + renamed + " renamed, " + retyped + " retyped");
    }
}
