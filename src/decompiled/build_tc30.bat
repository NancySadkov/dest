@echo off
rem TC30 build template for the staged recovered tree.
rem Mount tmp/buildsrc as C: and tools\TC30 as D:, then run this batch.
set TCC=D:\BIN\TCC.EXE
set INC=-ID:\INCLUDE -IC:\
set LIB=-LD:\LIB
set OUT=build.log
if exist %OUT% del %OUT%
echo === TC30 recovered-tree compile === > %OUT%

%TCC% -ml %INC% %LIB% -w- -c o04.c >> %OUT% 2>&1
if exist O04.OBJ echo OK   o04.c >> %OUT%
if not exist O04.OBJ echo FAIL o04.c >> %OUT%

%TCC% -ml %INC% %LIB% -w- -c o17.c >> %OUT% 2>&1
if exist O17.OBJ echo OK   o17.c >> %OUT%
if not exist O17.OBJ echo FAIL o17.c >> %OUT%

%TCC% -ml %INC% %LIB% -w- -c o20.c >> %OUT% 2>&1
if exist O20.OBJ echo OK   o20.c >> %OUT%
if not exist O20.OBJ echo FAIL o20.c >> %OUT%

%TCC% -ml %INC% %LIB% -w- -c o29.c >> %OUT% 2>&1
if exist O29.OBJ echo OK   o29.c >> %OUT%
if not exist O29.OBJ echo FAIL o29.c >> %OUT%

%TCC% -ml %INC% %LIB% -w- -c o44.c >> %OUT% 2>&1
if exist O44.OBJ echo OK   o44.c >> %OUT%
if not exist O44.OBJ echo FAIL o44.c >> %OUT%

%TCC% -ml %INC% %LIB% -w- -c o46.c >> %OUT% 2>&1
if exist O46.OBJ echo OK   o46.c >> %OUT%
if not exist O46.OBJ echo FAIL o46.c >> %OUT%

%TCC% -ml %INC% %LIB% -w- -c o48.c >> %OUT% 2>&1
if exist O48.OBJ echo OK   o48.c >> %OUT%
if not exist O48.OBJ echo FAIL o48.c >> %OUT%

echo === done === >> %OUT%
type %OUT%
