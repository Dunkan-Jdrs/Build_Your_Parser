@echo off

for /f %%a in ('echo prompt $E ^| cmd') do set "ESC=%%a"

set "GREEN=%ESC%[32m"
set "RED=%ESC%[31m"
set "YELLOW=%ESC%[33m"
set "RESET=%ESC%[0m"

cmake --build ../../build >nul 2>&1
ctest --test-dir ../../build -R "^Stage2_" --output-on-failure
set RESULT=%errorlevel%

if %RESULT% == 0 (
    echo %GREEN%You successfully passed Stage 2. You can move to Stage 3!%RESET%
) else (
    echo %RED%Some tests failed. Check the errors above.%RESET%
)

pause
