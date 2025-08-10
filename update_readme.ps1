# Function to get all solution files recursively
function Get-Solutions {
    $categories = Get-ChildItem -Directory | Where-Object { $_.Name -ne ".git" }
    $solutions = @{}
    
    foreach ($category in $categories) {
        $files = Get-ChildItem $category.FullName -Filter "*.cpp"
        if ($files.Count -gt 0) {
            $solutions[$category.Name] = $files.BaseName
        }
    }
    return $solutions
}

# Update README.md with current solutions
function Update-Readme {
    $solutions = Get-Solutions
    $readmeContent = @"
# CSES Problem Set Solutions

This repository contains my solutions to the CSES Problem Set implemented in C++. I'm actively working on solving more problems and will keep adding solutions as I progress.

## Current Progress

Solutions are organized by problem categories:

"@

    foreach ($category in $solutions.Keys | Sort-Object) {
        $readmeContent += "`n- **$category**`n`n"
        foreach ($solution in $solutions[$category] | Sort-Object) {
            $readmeContent += "  - $solution`n"
        }
    }

    $readmeContent += @"

## Usage

Each solution is written in C++ and can be compiled using a C++ compiler.

### Quick Git Push

I've included a `gitpush.bat` script for quick commits. Use it like this:

```bash
./gitpush "Your commit message"
```

This single command will add all changes, commit with your message, and push to the main branch.

## Work in Progress

This is an ongoing project. I'll continue to add more solutions as I solve them. Feel free to check back for updates.
"@

    $readmeContent | Set-Content "README.md"
}