#  VECTOR
## 1. Introduction
###  Student: Társila Samille Santos da Silveira

This project contains the implementation of a generic static vector class, an array with dinamic alocation called `sc::vector`.
This is an example code developed in EDB1 classes to illustrate a possible implementation for a **Data Structure**, based on the _Abstract Data Type_ (ADT) **sequence container** or simply **list**.

## Compiling

This project may be compiled with [CMake](https://cmake.org). CMake is an open-source, cross-platform family of tools designed to build, test and package software. Basically, cmake reads a script (`CMakeLists.txt`) with meta-information on the project and **creates a Makefile automatically**, tailored to your system configuration.
After that, you may run the `make` command, as usual.
Alternatively, the same script might be used to create Xcode projects, Ninja, or Microsoft Visual Studio projects, for instance.

CMake supports **out-of-source** build. This means the _source code_ is stored in **one** folder and the _generated executable files_ should be stored in **another** folder: project should never mix-up the source three with the build tree.

In particular, this project creates two **targets** (executable):
1. a simple driver (simulating a client using the `sc::vector`), called `run_drive` (driver vector), and
2. the tests, called `run_tests`.

But don't worry, they are already set up in the `CMakeLists.txt` script.

To compile this project with [cmake](https://cmake.org) follow these steps (from the root folder):

1. `cmake -S source -Bbuild`:  asks cmake to create the build directory and generate the Unix Makefile based on the script found in `CMakeLists.txt`, on the current level.
2. `cmake --build build`: triggers the compiling process that creates both targets (executable).D inside `build`.

The executables are created inside the `build` directory.

For further details, please refer to the [cmake documentation website](https://cmake.org/cmake/help/v3.14/manual/cmake.1.html).

## Running

From the project's root folder, run as usual (assuming `$` is the terminal prompt):

```
$ ./build/run_drive
```

```
$ ./build/run_tests
```
## Doxygen Documentation

```
$ ./html/index.html
```

&copy; DIMAp/UFRN 2020.
