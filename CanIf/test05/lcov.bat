@echo on
:: Full dirname of current executable
set idir=%~dp0
set perl=D:\MinGw\msys\1.0\bin\perl.exe

md "%CD%\gcov"
echo Creating gcov\lcov.info ...
%perl% %idir%lcov.perl -b . -d . -c -o gcov/lcov.info
:: echo Cleaning up ...
:: %perl% %idir%lcov.perl --remove gcov/lcov.info "*_unneeded_*" -o gcov/lcov.info

echo Fixing back slashes ...
::type "gcov\lcov.info"|%~dp0repl.bat "\\" "/" >"gcov\lcov.info.tmp"
::move /y "gcov\lcov.info.tmp" "gcov\lcov.info" >nul

echo Generating html ...
%perl% %idir%genhtml.perl -o gcov/html/ gcov/lcov.info -p "%CD%"
