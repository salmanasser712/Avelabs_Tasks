@echo on
setlocal enabledelayedexpansion

set "Base_Dir=..\..\..\gsl-2.7.1_Misra"
set "INCLUDE_FLAGS=-I%Base_Dir%\err -I%Base_Dir%\combination -I%Base_Dir%\block -I%Base_Dir%\cblas -I%Base_Dir%\"

set "Comb_Source=combination.c"
set "Main_Source=main.c"
set "Stubs_Source=stubs.c"

gcc %INCLUDE_FLAGS% %Main_Source%  -c
gcc %INCLUDE_FLAGS% %Comb_Source%  -c
gcc %INCLUDE_FLAGS% %Stubs_Source%  -c

gcc %INCLUDE_FLAGS% -ansi -pedantic main.o stubs.o combination.o -o output

output.exe

clean.bat
