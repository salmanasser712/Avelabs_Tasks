@echo on
setlocal enabledelayedexpansion

set "Base_Dir=..\..\..\gsl-2.7.1_Misra"
set "INCLUDE_FLAGS=-I%Base_Dir%\err -I%Base_Dir%\combination -I%Base_Dir%\block -I%Base_Dir%\cblas -I%Base_Dir%\"

set "Comb_Source=combination.c"
set "Main_Source=main.c"
set "Stubs_Source=stubs.c"


set COMPILAR_INC="-IC:\Program Files\ti-cgt-arm_20.2.7.LTS\include"
set COMPILAR_LIB="-IC:\Program Files\ti-cgt-arm_20.2.7.LTS\lib"

armcl --c99 --check_misra %COMPILAR_INC% %INCLUDE_FLAGS% %Main_Source% 1>Main_Misra.txt 2>&1
armcl --c99 --check_misra %COMPILAR_INC% %INCLUDE_FLAGS% %Comb_Source% 1>comb_Misra.txt 2>&1
armcl --c99 --check_misra %COMPILAR_INC% %INCLUDE_FLAGS% %Stubs_Source% 1>stubs_result.txt 2>&1

armcl --run_linker %COMPILAR_LIB% %INCLUDE_FLAGS% %COMPILAR_INC% main.obj stubs.obj combination.obj --output_file=output.out Linkscript_ti.cmd     


clean.bat
