#  Dispersion Table
## 1. Introduction
###  Student: Társila Samille Santos da Silveira
This project consists of the implementation of a data structure of the dispersion table in C ++.
This is an example code developed in EDB1 classes.

## Compiling

This project may be compiled with [CMake](https://cmake.org). CMake is an open-source, cross-platform family of tools designed to build, test and package software. Basically, cmake reads a script (`CMakeLists.txt`) with meta-information on the project and **creates a Makefile automatically**, tailored to your system configuration.

If you have already installed it, open a terminal in the project's root folder.

Create the "build" directory and enter it: `` `$ cd build` ``

Now generate the files for compilation with: `` `$ cmake -G" Unix Makefiles "..` ``

Now compile the project with: `` $ make ``

CMake supports **out-of-source** build. This means the _source code_ is stored in **one** folder and the _generated executable files_ should be stored in **another** folder: project should never mix-up the source three with the build tree.

In particular, this project creates two **targets** (executable):
1. a simple driver , called `driver_hash` (driver hash table), and
2. the tests, called `run_tests`.

But don't worry, they are already set up in the `CMakeLists.txt` script.
The executables are created inside the `build` directory.

For further details, please refer to the [cmake documentation website](https://cmake.org/cmake/help/v3.14/manual/cmake.1.html).

## Running

From the project's root folder, run as usual (assuming `$` is the terminal prompt):

```
$ ./build/driver_hash
```

```
$ ./build/run_tests
```
## Doxygen Documentation

```
$ ./html/index.html
```

## Report

```
$ ./hash_relatório.pdf
```

&copy; UFRN 2020.
