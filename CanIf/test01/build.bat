@echo on
setlocal enabledelayedexpansion

REM Initialize an empty string for the include directories
set "Base_Dir=..\..\..\OpenSAR"
set "INCLUDE_FLAGS=-I%Base_Dir%\include -I%Base_Dir%\include\arm -I%Base_Dir%\arch\arm\arm_cr4\kernel\ -I%Base_Dir%\app\config -I%Base_Dir%\app\config\GEN"


:: Source Files to compile
set "CanIf_Source=%Base_Dir%\communication\CanIf\CanIf.c"
set "Main_Source=main.c"
set "Stubs_Source=stubs.c"


REM Now you can use INCLUDE_DIRS in your gcc command
tiarmclang -c -flto -mcpu=cortex-m4 %INCLUDE_FLAGS% %Stubs_Source% 
tiarmclang -c -flto -mcpu=cortex-m4 %INCLUDE_FLAGS% %CanIf_Source%  
tiarmclang -c -flto -mcpu=cortex-m4 %INCLUDE_FLAGS% %Main_Source%   

tiarmclang -mcpu=cortex-m4 %INCLUDE_FLAGS% CanIf.o stubs.o main.o -o output.hex -Wl,Linkscript_ti.cmd

tiarmnm output.hex

clean.bat

