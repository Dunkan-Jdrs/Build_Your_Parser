@echo off
setlocal EnableExtensions EnableDelayedExpansion
for /f %%a in ('echo prompt $E ^| cmd') do set "ESC=%%a"

set "GREEN=%ESC%[32m"
set "RED=%ESC%[31m"
set "YELLOW=%ESC%[33m"
set "RESET=%ESC%[0m"

echo === Build your own Parser ! -- Setup -- ===

cmake --version >nul
if %errorlevel% neq 0 (
    echo %RED%CMake not found.%RESET%
    set /p answer="Do you want to install it automatically via winget? (y/n):"
    if /i "!answer!"=="y" (
        winget install --id Kitware.CMake -e
        echo.
        echo CMake installed. Please restart this script to continue.
		pause
        exit /b 0
    ) else (
        echo Please install CMake manually at https://cmake.org/download/
        pause
        exit /b 1
    )
)

echo %GREEN%CMake found.%RESET%

echo Configuring project...
cmake -S . -B build >nul 2>&1
if %errorlevel% neq 0 (
    echo %RED%Configuration failed.%RESET%
    pause
    exit /b 1
)

echo %GREEN%Configuration successful.%RESET%

echo Building project...
cmake --build build >nul 2>&1
if %errorlevel% neq 0 (
    echo %RED%Build failed.%RESET%
    pause
    exit /b 1
)

echo %GREEN%Build successfully.%RESET%

echo.
echo Setup complete. You can now start working on Stage 1.
echo Run scripts/stage1.bat to validate your implementation.
pause