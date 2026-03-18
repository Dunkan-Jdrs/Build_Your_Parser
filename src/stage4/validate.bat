@echo off

for /f %%a in ('echo prompt $E ^| cmd') do set "ESC=%%a"

set "GREEN=%ESC%[32m"
set "RED=%ESC%[31m"
set "YELLOW=%ESC%[33m"
set "RESET=%ESC%[0m"

echo %YELLOW%Building...%RESET%
cmake --build ../../build >nul 2>&1
ctest --test-dir ../../build -R "^Stage4_" --output-on-failure > "%TEMP%\byp_output.txt" 2>&1
set RESULT=%errorlevel%

type "%TEMP%\byp_output.txt"

if %RESULT% == 0 (
	echo %GREEN%You successfully passed Stage 4. You can move to Stage 5!%RESET%
) else (
	echo.
	echo %YELLOW%==============================%RESET%
	echo %YELLOW%  Reasons :%RESET%
	echo %YELLOW%==============================%RESET%
	findstr /C:"exception with description" /C:": Failure" "%TEMP%\byp_output.txt"
	echo.
	echo %YELLOW%==============================%RESET%
	echo %YELLOW%  Failed tests :%RESET%
	echo %YELLOW%==============================%RESET%
	findstr /C:"[  FAILED  ]" "%TEMP%\byp_output.txt" | findstr "ms)"
	echo %YELLOW%==============================%RESET%
	echo %RED%Some tests failed. Fix them and run validate.bat again.%RESET%
)

pause
