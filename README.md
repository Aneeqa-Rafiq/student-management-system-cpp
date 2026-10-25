# Student Management System (C++)

A beginner-friendly console application I built to practise C++ functions, structures, loops, input validation, and file handling.

## Features

- Add a student with a roll number, name, and marks
- View saved student records
- Search for a student by roll number
- Store records in a local text file so they remain available after the program closes
- Handle some invalid numeric input

## Built with

- C++
- Standard library: `iostream`, `fstream`, `string`, and `limits`

## How to run

### Dev-C++

1. Download or clone this repository.
2. Open `main.cpp` in Dev-C++.
3. Select **Execute → Compile & Run** (shortcut may vary by version).
4. Follow the menu in the console.

### Terminal with a C++ compiler

```bash
g++ main.cpp -o student-management
./student-management
```

On Windows, run `student-management.exe` after compiling.

## Data storage

The program creates `students.txt` in its working directory when a record is added. Keep this file if you want to keep the sample records.

## What I practised

- Organising work into functions
- Using a `struct` to group student information
- Reading and writing text files
- Searching records with a loop
- Checking whether file opening and numeric input succeeded

## Current limitations

This is an early learning project. It does not yet edit or delete records, prevent duplicate roll numbers, or store data in a database.

## Planned improvements

- Add edit and delete options
- Prevent duplicate roll numbers
- Validate marks against a chosen range
- Later, practise the same project using classes and objects
