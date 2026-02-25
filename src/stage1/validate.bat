@echo off

for /f %%a in ('echo prompt $E ^| cmd') do set "ESC=%%a"

set "GREEN=%ESC%[32m"
set "RED=%ESC%[31m"
set "YELLOW=%ESC%[33m"
set "RESET=%ESC%[0m"

cmake --build ../../build >nul 2>&1
ctest --test-dir ../../build -R "^Stage1_" --output-on-failure
echo %errorlevel%
pause
if %errorlevel% == 0(
	echo %GREEN%You succefully passed the Stage 1. You can move to the Stage 2%RESET%
) else (
	echo %RED%Some tests failed. Check the errors above.%RESET%
)
