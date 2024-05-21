echo on

REM Initialize string for the include directories
set "INCLUDE_FLAGS=-I..\..\..\include -I..\..\..\include\arm -I..\..\..\arch\arm\arm_cr4\kernel\ -I..\..\..\include\arm -I..\..\..\app\config -I..\..\..\app\config\GEN"


:: Source Files to compile
set "CanIf_Source=..\..\..\communication\CanIf\CanIf.c"
set "Main_Source=main.c"
set "Stubs_Source=stubs.c"

::cppcheck --suppress=missingIncludeSystem --force  --check-level=exhaustive %INCLUDE_FLAGS% %CanIf_Source% %Main_Source% 

cppcheck  --addon=misra.json  --enable=all --suppress=missingIncludeSystem --force  --check-level=exhaustive %INCLUDE_FLAGS% %CanIf_Source% %Main_Source% %Stubs_Source%  1>cppcheck_result.txt 2>&1
