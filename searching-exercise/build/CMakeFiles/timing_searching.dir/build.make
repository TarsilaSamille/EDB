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
CMAKE_SOURCE_DIR = "/home/tarsila/Área de Trabalho/EBD/searching-exercise"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tarsila/Área de Trabalho/EBD/searching-exercise/build"

# Include any dependencies generated for this target.
include CMakeFiles/timing_searching.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/timing_searching.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/timing_searching.dir/flags.make

CMakeFiles/timing_searching.dir/src/searching.cpp.o: CMakeFiles/timing_searching.dir/flags.make
CMakeFiles/timing_searching.dir/src/searching.cpp.o: ../src/searching.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tarsila/Área de Trabalho/EBD/searching-exercise/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/timing_searching.dir/src/searching.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timing_searching.dir/src/searching.cpp.o -c "/home/tarsila/Área de Trabalho/EBD/searching-exercise/src/searching.cpp"

CMakeFiles/timing_searching.dir/src/searching.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timing_searching.dir/src/searching.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tarsila/Área de Trabalho/EBD/searching-exercise/src/searching.cpp" > CMakeFiles/timing_searching.dir/src/searching.cpp.i

CMakeFiles/timing_searching.dir/src/searching.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timing_searching.dir/src/searching.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tarsila/Área de Trabalho/EBD/searching-exercise/src/searching.cpp" -o CMakeFiles/timing_searching.dir/src/searching.cpp.s

CMakeFiles/timing_searching.dir/src/timing_template.cpp.o: CMakeFiles/timing_searching.dir/flags.make
CMakeFiles/timing_searching.dir/src/timing_template.cpp.o: ../src/timing_template.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tarsila/Área de Trabalho/EBD/searching-exercise/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/timing_searching.dir/src/timing_template.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timing_searching.dir/src/timing_template.cpp.o -c "/home/tarsila/Área de Trabalho/EBD/searching-exercise/src/timing_template.cpp"

CMakeFiles/timing_searching.dir/src/timing_template.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timing_searching.dir/src/timing_template.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tarsila/Área de Trabalho/EBD/searching-exercise/src/timing_template.cpp" > CMakeFiles/timing_searching.dir/src/timing_template.cpp.i

CMakeFiles/timing_searching.dir/src/timing_template.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timing_searching.dir/src/timing_template.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tarsila/Área de Trabalho/EBD/searching-exercise/src/timing_template.cpp" -o CMakeFiles/timing_searching.dir/src/timing_template.cpp.s

# Object files for target timing_searching
timing_searching_OBJECTS = \
"CMakeFiles/timing_searching.dir/src/searching.cpp.o" \
"CMakeFiles/timing_searching.dir/src/timing_template.cpp.o"

# External object files for target timing_searching
timing_searching_EXTERNAL_OBJECTS =

timing_searching: CMakeFiles/timing_searching.dir/src/searching.cpp.o
timing_searching: CMakeFiles/timing_searching.dir/src/timing_template.cpp.o
timing_searching: CMakeFiles/timing_searching.dir/build.make
timing_searching: CMakeFiles/timing_searching.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tarsila/Área de Trabalho/EBD/searching-exercise/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable timing_searching"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/timing_searching.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/timing_searching.dir/build: timing_searching

.PHONY : CMakeFiles/timing_searching.dir/build

CMakeFiles/timing_searching.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/timing_searching.dir/cmake_clean.cmake
.PHONY : CMakeFiles/timing_searching.dir/clean

CMakeFiles/timing_searching.dir/depend:
	cd "/home/tarsila/Área de Trabalho/EBD/searching-exercise/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tarsila/Área de Trabalho/EBD/searching-exercise" "/home/tarsila/Área de Trabalho/EBD/searching-exercise" "/home/tarsila/Área de Trabalho/EBD/searching-exercise/build" "/home/tarsila/Área de Trabalho/EBD/searching-exercise/build" "/home/tarsila/Área de Trabalho/EBD/searching-exercise/build/CMakeFiles/timing_searching.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/timing_searching.dir/depend

