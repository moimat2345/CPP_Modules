# 42 SCHOOL – C++ RULES (CPP MODULES)

This file defines the **official constraints** for C++ projects at 42 School.
These rules must be strictly respected.

---

## 1. Language & Compilation

- Language: **C++**
- Standard: **C++98 only**
- Compilation flags: c++ -Wall -Wextra -Werror -std=c++98
No C++11 or newer features are allowed.

---

## 2. Forbidden Functions

The following functions are **strictly forbidden**:

### C-style I/O
- `printf`, `fprintf`, `sprintf`, `snprintf`
- `scanf`, `sscanf`
- `write`, `read`

### C-style Memory Management
- `malloc`, `calloc`, `realloc`, `free`
- Any `*alloc` function

Using any forbidden function results in **grade 0**.

---

## 3. Allowed I/O

- `std::cout`
- `std::cin`
- `std::cerr`

Use C++ streams instead of C functions.

---

## 4. STL Restrictions

- **STL is forbidden until Module 08**

### Forbidden before CPP08:
- Containers: `vector`, `list`, `map`, `set`, etc.
- Algorithms: anything from `<algorithm>`

Only basic C++ features are allowed.

---

## 5. Namespaces

- `using namespace std;` is **forbidden**
- Always use `std::`

---

## 6. File & Naming Rules

- One class per file (unless specified otherwise)
- File names must match class names

Example: ClassName.hpp
ClassName.cpp

- Class names: **UpperCamelCase**

---

## 7. Headers Rules

- Headers contain **only declarations**
- No function implementation in headers
- Headers must:
  - Include required dependencies
  - Use include guards

---

## 8. Memory Management

- If `new` is used, `delete` must be used
- No memory leaks allowed
- If dynamic allocation is forbidden by the subject, do not use it

---

## 9. Output Rules

- Output must match the subject **exactly**
- Every output ends with a newline `\n`
- No extra or debug output

---

## 10. Makefile Rules

- Mandatory rules:
  - `NAME`
  - `all`
  - `clean`
  - `fclean`
  - `re`
- Must not relink unnecessarily
- Must use `c++` as compiler

---

## 11. Scope of the Project

- Follow the **subject PDF strictly**
- Do not add extra features
- If a feature is not required, it must not be implemented

---

## 12. Priority

When in doubt, follow this order:
1. Subject PDF
2. 42 Evaluation Rules
3. This file
