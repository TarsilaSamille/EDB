# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/tarsila/Área de Trabalho/EBD/lista1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tarsila/Área de Trabalho/EBD/lista1/build"

# Include any dependencies generated for this target.
include CMakeFiles/driver_search.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/driver_search.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/driver_search.dir/flags.make

CMakeFiles/driver_search.dir/src/app_search.cpp.o: CMakeFiles/driver_search.dir/flags.make
CMakeFiles/driver_search.dir/src/app_search.cpp.o: ../src/app_search.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tarsila/Área de Trabalho/EBD/lista1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/driver_search.dir/src/app_search.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/driver_search.dir/src/app_search.cpp.o -c "/home/tarsila/Área de Trabalho/EBD/lista1/src/app_search.cpp"

CMakeFiles/driver_search.dir/src/app_search.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/driver_search.dir/src/app_search.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tarsila/Área de Trabalho/EBD/lista1/src/app_search.cpp" > CMakeFiles/driver_search.dir/src/app_search.cpp.i

CMakeFiles/driver_search.dir/src/app_search.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/driver_search.dir/src/app_search.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tarsila/Área de Trabalho/EBD/lista1/src/app_search.cpp" -o CMakeFiles/driver_search.dir/src/app_search.cpp.s

CMakeFiles/driver_search.dir/src/searching.cpp.o: CMakeFiles/driver_search.dir/flags.make
CMakeFiles/driver_search.dir/src/searching.cpp.o: ../src/searching.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tarsila/Área de Trabalho/EBD/lista1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/driver_search.dir/src/searching.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/driver_search.dir/src/searching.cpp.o -c "/home/tarsila/Área de Trabalho/EBD/lista1/src/searching.cpp"

CMakeFiles/driver_search.dir/src/searching.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/driver_search.dir/src/searching.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tarsila/Área de Trabalho/EBD/lista1/src/searching.cpp" > CMakeFiles/driver_search.dir/src/searching.cpp.i

CMakeFiles/driver_search.dir/src/searching.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/driver_search.dir/src/searching.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tarsila/Área de Trabalho/EBD/lista1/src/searching.cpp" -o CMakeFiles/driver_search.dir/src/searching.cpp.s

# Object files for target driver_search
driver_search_OBJECTS = \
"CMakeFiles/driver_search.dir/src/app_search.cpp.o" \
"CMakeFiles/driver_search.dir/src/searching.cpp.o"

# External object files for target driver_search
driver_search_EXTERNAL_OBJECTS =

driver_search: CMakeFiles/driver_search.dir/src/app_search.cpp.o
driver_search: CMakeFiles/driver_search.dir/src/searching.cpp.o
driver_search: CMakeFiles/driver_search.dir/build.make
driver_search: CMakeFiles/driver_search.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tarsila/Área de Trabalho/EBD/lista1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable driver_search"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/driver_search.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/driver_search.dir/build: driver_search

.PHONY : CMakeFiles/driver_search.dir/build

CMakeFiles/driver_search.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/driver_search.dir/cmake_clean.cmake
.PHONY : CMakeFiles/driver_search.dir/clean

CMakeFiles/driver_search.dir/depend:
	cd "/home/tarsila/Área de Trabalho/EBD/lista1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tarsila/Área de Trabalho/EBD/lista1" "/home/tarsila/Área de Trabalho/EBD/lista1" "/home/tarsila/Área de Trabalho/EBD/lista1/build" "/home/tarsila/Área de Trabalho/EBD/lista1/build" "/home/tarsila/Área de Trabalho/EBD/lista1/build/CMakeFiles/driver_search.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/driver_search.dir/depend

