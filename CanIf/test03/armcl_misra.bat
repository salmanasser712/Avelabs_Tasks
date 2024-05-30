@echo on
setlocal enabledelayedexpansion

REM Initialize an empty string for the include directories
set "Base_Dir=..\..\..\OpenSAR"
set "INCLUDE_FLAGS=-I%Base_Dir%\include -I%Base_Dir%\include\arm -I%Base_Dir%\arch\arm\arm_cr4\kernel\ -I%Base_Dir%\app\config -I%Base_Dir%\app\config\GEN"

set COMPILAR_INC="-ID:\Ti_Compilers\ti-cgt-arm_20.2.7.LTS\include"
set COMPILAR_LIB="-ID:\Ti_Compilers\ti-cgt-arm_20.2.7.LTS\lib"

:: Source Files to compile
set "CanIf_Source=%Base_Dir%\communication\CanIf\CanIf.c"
set "Main_Source=main.c"
set "Stubs_Source=stubs.c"

armcl --c99 --check_misra %COMPILAR_INC% %INCLUDE_FLAGS%  %CanIf_Source%  1>comb_Misra.txt 2>&1
armcl --c99 --check_misra %COMPILAR_INC% %INCLUDE_FLAGS%  %Main_Source%   1>Main_Misra.txt 2>&1
armcl --c99 --check_misra %COMPILAR_INC% %INCLUDE_FLAGS%  %Stubs_Source%  1>stubs_result.txt 2>&1

armcl --run_linker %COMPILAR_LIB% %INCLUDE_FLAGS% %COMPILAR_INC% main.obj stubs.obj CanIf.obj --output_file=output.out Linkscript_ti.cmd


clean.bat