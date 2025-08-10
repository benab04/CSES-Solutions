@echo off
setlocal enabledelayedexpansion

rem Handle the case where no argument is provided
if [%1]==[] (
    echo Error: Please provide a C++ file to compile
    echo Usage: build "filename.cpp"
    echo Example: build "Removing Digits.cpp"
    exit /b 1
)

rem Remove quotes from the argument if they exist
set "inputfile=%~1"

rem Check if file exists
if not exist "!inputfile!" (
    echo Error: File "!inputfile!" does not exist
    exit /b 1
)

rem Get filename without extension and path
for %%F in ("!inputfile!") do set "filename=%%~nF"

echo Compiling "!inputfile!"...
g++ "!inputfile!" -o "!filename!"
if %errorlevel% neq 0 (
    echo ❌ Compilation failed
    exit /b 1
)

echo ✅ Successfully compiled "!inputfile!" to "!filename!.exe"
echo.
echo Running "!filename!.exe"...
echo ================================
"!filename!.exe"
echo ================================
echo Program finished with exit code: %errorlevel%