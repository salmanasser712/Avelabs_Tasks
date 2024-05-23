echo on

REM Initialize an empty string for the include directories
set "Base_Dir=..\..\..\OpenSAR"
set "INCLUDE_FLAGS=-I%Base_Dir%\include -I%Base_Dir%\include\arm -I%Base_Dir%\arch\arm\arm_cr4\kernel\ -I%Base_Dir%\app\config -I%Base_Dir%\app\config\GEN"


:: Source Files to compile
set "CanIf_Source=%Base_Dir%\communication\CanIf\CanIf.c"
set "Main_Source=main.c"
set "Stubs_Source=stubs.c"

cppcheck  --addon=misra.json  --enable=all --suppress=missingIncludeSystem --force  --check-level=exhaustive %INCLUDE_FLAGS% %CanIf_Source% %Main_Source% %Stubs_Source%  1>cppcheck_result.txt 2>&1
