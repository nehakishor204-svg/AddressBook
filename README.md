# Address Book Management System in C

A modular, menu-driven **Address Book Management System** developed using the C programming language. This project demonstrates structured programming, modular code organization, and file handling for managing contact information.

## Overview

The Address Book allows users to manage contact records through a menu-driven interface. Contact details are organized using structures, while file handling supports storing and retrieving contact information.

## Features

- **Add Contacts** — Create new contact records.
- **List Contacts** — Display saved contacts.
- **Search Contacts** — Find a contact using the available search criteria.
- **Edit Contacts** — Update existing contact information.
- **Delete Contacts** — Remove unwanted contact records.
- **Sort Contacts** — Organize contacts alphabetically.
- **File Handling** — Save and load contact information for persistent storage.
- **Modular Design** — Separate source and header files for better code organization.

## Technologies Used

- **Language:** C
- **Compiler:** GCC
- **Development Environment:** Linux / VS Code
- **Concepts:** Structures, functions, arrays, strings, pointers, file handling, modular programming, and sorting.

## Project Structure

```text
AddressBook/
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── populate.c
├── populate.h
├── contacts.txt
├── .gitignore
└── README.md
```

### File Description

| File | Responsibility |
|---|---|
| `main.c` | Program entry point and menu interface |
| `contact.c` | Contact management operations |
| `contact.h` | Contact-related declarations |
| `file.c` | File storage and retrieval operations |
| `file.h` | File-handling declarations |
| `populate.c` | Sample contact initialization |
| `populate.h` | Sample-data function declarations |
| `contacts.txt` | Text-file storage for contacts |

## How to Compile and Run

### 1. Clone the repository

```bash
git clone https://github.com/nehakishor204-svg/AddressBook.git
```

### 2. Navigate to the project directory

```bash
cd AddressBook
```

### 3. Compile the source files

```bash
gcc *.c -o addressbook
```

### 4. Run the program

```bash
./addressbook
```

**Note:** These commands assume GCC is installed and that the source files can be compiled together. Run the program from the project directory so relative file paths work as intended.

## Concepts Demonstrated

- Structures for representing contact records
- Functions and modular program design
- Arrays and string manipulation
- Pointers and passing structures to functions
- File operations for persistent data
- Sorting and searching
- Input handling and validation

## Learning Outcomes

This project strengthened my understanding of C programming, multi-file project organization, data management using structures, and persistent storage through file operations.

## Future Improvements

- Add more robust input validation.
- Improve duplicate-contact detection.
- Introduce a more flexible search interface.
- Add automated test cases.
- Improve error handling for file operations.

## Author

**Neha Kishor**

GitHub: [@nehakishor204-svg](https://github.com/nehakishor204-svg)

---

*Developed as a C programming project to practice modular programming and file handling.*
