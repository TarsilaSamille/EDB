#  Student: Társila Samille Santos da Silveira

The answer is in the file 'algoritimos.cpp' with the answer below the relative comment. The question 8 and 14 for example refers to the same algorithm.


## Compiling

This project may be compiled with [CMake](https://cmake.org). CMake is an open-source, cross-platform family of tools designed to build, test and package software. Basically, cmake reads a script (`CMakeLists.txt`) with meta-information on the project and **creates a Makefile automatically**, tailored to your system configuration.
After that, you may run the `make` command, as usual.

To compile this project with [cmake](https://cmake.org) follow these steps:

1. `cd lista1`: enters into the main project directory.
2. `cmake -S . -Bbuild`:  asks cmake to create the build directory and generate the Unix Makefile based on the script found in `CMakeLists.txt`, on the current level.
3. `cd build`: enter the build folder.
5. `cmake --build .` or `make`: triggers the compiling process.

The executables are created inside the `build` directory.

## Running

From the project's root folder, run as usual (assuming `$` is the terminal prompt):

```
$ ./build/lista1
```

&copy;  2020.
