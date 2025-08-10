# Function to get all solution files recursively
function Get-Solutions {
    # Get all directories except .git, .vscode, and other common non-solution folders
    $excludedFolders = @(".git", ".vscode", "node_modules", ".vs", "bin", "obj")
    $categories = Get-ChildItem -Directory | Where-Object { $excludedFolders -notcontains $_.Name }
    $solutions = [ordered]@{}
    
    foreach ($category in $categories) {
        $files = Get-ChildItem $category.FullName -Filter "*.cpp" -Recurse
        if ($files.Count -gt 0) {
            $solutions[$category.Name] = ($files | ForEach-Object { $_.BaseName } | Sort-Object)
        }
    }
    return $solutions
}

# Update README.md with current solutions
function Update-Readme {
    $solutions = Get-Solutions
    
    # Check if there are any solutions
    if ($solutions.Count -eq 0) {
        Write-Host "No C++ solution files found in any directories."
        return
    }
    
    $readmeContent = @"
# CSES Problem Set Solutions

This repository contains my solutions to the CSES Problem Set implemented in C++. I'm actively working on solving more problems and will keep adding solutions as I progress.

## Current Progress

Solutions are organized by problem categories:

"@

    # Sort categories alphabetically and add their solutions
    foreach ($category in ($solutions.Keys | Sort-Object)) {
        $readmeContent += "`n- **$category**`n`n"
        foreach ($solution in $solutions[$category]) {
            $readmeContent += "  - $solution`n"
        }
    }

    $readmeContent += @"

## Usage

Each solution is written in C++ and can be compiled using a C++ compiler.

### Quick Git Push

I've included a `gitpush.bat` script for quick commits. Use it like this:

```
gitpush <Your commit message without quotes>
```

This single command will add all changes, commit with your message, and push to the main branch.

### Build and Run a .cpp file using a single command line

Running a CPP file in VSCode was giving a hell lot of issues, so th build.bat is a temporary workaround to quickly build and get the file running. Use it in the same directory as the file like this:

```
./build FileName.cpp
```

This will build an executable named FileName.exe and run it instantly.
"@

    # Write the content to README.md
    try {
        $readmeContent | Out-File "README.md" -Encoding UTF8
        Write-Host "README.md updated successfully!"
        
        # Display what was found for debugging
        Write-Host "`nFound solutions in the following categories:"
        foreach ($category in ($solutions.Keys | Sort-Object)) {
            Write-Host "- $category ($($solutions[$category].Count) files)"
        }
    }
    catch {
        Write-Error "Failed to update README.md: $_"
        exit 1
    }
}

# Run the update
Update-Readme