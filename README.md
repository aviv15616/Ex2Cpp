# SquareMat Project

## Overview
This project implements a `SquareMat` class inside the `matrix` namespace.  
The class represents a dynamic **square matrix** of `double` elements and supports a wide range of operations, including:

- Constructors (from 2D array, scalar value, and copy constructor)
- Element access (`operator[]`)
- Full arithmetic support: `+`, `-`, `*`, `/`, `%`, `^` (as defined in the assignment)
- Unary operations: `-`, `~`, `++`, `--` (as defined in the assignment)
- Comparison operators: `==`, `!=`, `<`, `>`, `<=`, `>=` (as defined in the assignment)
- Determinant calculation: `!`
- Compound assignment operations: `+=`, `-=`, `*=`, `/=`, `%=`  (as defined in the assignment)
- Pretty printing with `operator<<`
- Full exception handling for invalid operations
- Code tested using **doctest** unit tests

---

## Project Structure

| File                  | Description                                  |
|------------------------|----------------------------------------------|
| `SquareMat.hpp`        | Header file: class declaration               |
| `SquareMat.cpp`        | Source file: class implementation            |
| `main.cpp`             | Demonstrates usage of all class functions    |
| `test_SquareMat.cpp`   | Unit tests using doctest                     |
| `Makefile`             | Automates build, run, test, and clean tasks   |

---

## Build & Run

### Requirements
- C++17 or newer
- `g++` compiler
- `make`

### Common Commands

| Command            | Description                                                 |
|--------------------|-------------------------------------------------------------|
| `make`             | Builds and runs both the main program and the tests         |
| `make Main`        | Runs the main program (`main.cpp`)                          |
| `make test`        | Runs the unit tests (`test_SquareMat.cpp`) using doctest     |
| `make valgrind`    | Runs both executables (`main` and `test_runner`) under Valgrind for memory checking |
| `make clean`       | Removes compiled executables and object files               |

---

## How to Run

### To compile and run the main program:
```bash
make Main
```

### To run unit tests:
```bash
make test
```

### To check for memory issues using Valgrind:
```bash
make valgrind
```

### To clean compiled files:
```bash
make clean
```

---

## Running Unit Tests

This project uses [doctest](https://github.com/doctest/doctest), a lightweight C++ testing framework.

You can compile and run the tests with:

```bash
make test
```

You will see a detailed report of all passed or failed tests.

---

## Notes

- Exception safety is enforced for invalid inputs.
- Deep copies are properly handled.
- Code is organized clearly with section headers.
- Full functionality is tested individually.
- The matrix output format is readable.

---

**Author:**  
Aviv Neeman  
April 2025
