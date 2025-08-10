@echo off
if "%*"=="" (
    echo Error: Please provide a commit message
    echo Usage: gitpush "Your commit message"
    exit /b 1
)

echo Updating README.md...
powershell -ExecutionPolicy Bypass -File "update_readme.ps1"
if %errorlevel% neq 0 (
    echo Failed to update README
    exit /b 1
)

echo Adding all files...
git add .
if %errorlevel% neq 0 (
    echo Failed to add files
    exit /b 1
)

echo Committing with message: %*
git commit -m "%*"
if %errorlevel% neq 0 (
    echo Failed to commit
    exit /b 1
)

echo Pushing to origin main...
git push origin main
if %errorlevel% neq 0 (
    echo Failed to push
    exit /b 1
)

echo ✅ Successfully pushed to origin/main!