cmake_minimum_required(VERSION 3.5)
project(ordenationAlgorithms VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall  -O3" )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

### [1] Application target
# set the include path
include_directories( include )

# define the sources for the project
add_executable( driver_ordenation
                src/app_ordenation.cpp # This has the application main().
                src/ordenation.cpp ) # This has the ordenation functions implementation.

# define C++11 standard
set_property(TARGET driver_ordenation PROPERTY CXX_STANDARD 11)

### [2] The timing example app
# define the sources for the project
add_executable( timing_ordenation
                src/ordenation.cpp
                src/timing_template.cpp ) # This is the runtime measuring code. 

# define C++11 standard
set_property(TARGET timing_ordenation PROPERTY CXX_STANDARD 11)


# The end