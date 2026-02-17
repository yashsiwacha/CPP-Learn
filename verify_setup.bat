@echo off
echo ==========================================
echo CLion C++ Setup Verification Script
echo ==========================================
echo.

echo [1/4] Checking if g++ is installed...
g++ --version >nul 2>&1
if %errorlevel% == 0 (
    echo [OK] g++ is installed
    g++ --version | findstr "g++"
) else (
    echo [ERROR] g++ is NOT installed
    echo Please install MinGW-w64 and add it to PATH
    echo Download from: https://winlibs.com/
    goto :error
)
echo.

echo [2/4] Checking if gcc is installed...
gcc --version >nul 2>&1
if %errorlevel% == 0 (
    echo [OK] gcc is installed
    gcc --version | findstr "gcc"
) else (
    echo [ERROR] gcc is NOT installed
    goto :error
)
echo.

echo [3/4] Checking if CMake is available...
cmake --version >nul 2>&1
if %errorlevel% == 0 (
    echo [OK] CMake is installed
    cmake --version | findstr "cmake"
) else (
    echo [WARNING] CMake not found in PATH
    echo CLion has its own bundled CMake, so this is OK
)
echo.

echo [4/4] Checking project structure...
if exist "CMakeLists.txt" (
    echo [OK] CMakeLists.txt found
) else (
    echo [ERROR] CMakeLists.txt NOT found
    goto :error
)

if exist "Module1\" (
    echo [OK] Module1 directory found
) else (
    echo [ERROR] Module1 directory NOT found
    goto :error
)

if exist "Module2\" (
    echo [OK] Module2 directory found
) else (
    echo [ERROR] Module2 directory NOT found
    goto :error
)
echo.

echo ==========================================
echo [SUCCESS] Your setup is ready!
echo ==========================================
echo.
echo Next steps:
echo 1. Open this folder in CLion
echo 2. Wait for CMake to load (bottom-right status)
echo 3. Select a program from the dropdown (top-right)
echo 4. Click the green Run button or press Shift+F10
echo.
echo See CLION_SETUP_GUIDE.md for detailed instructions
echo.
pause
exit /b 0

:error
echo.
echo ==========================================
echo [ERROR] Setup incomplete
echo ==========================================
echo Please follow the instructions in CLION_SETUP_GUIDE.md
echo.
pause
exit /b 1
