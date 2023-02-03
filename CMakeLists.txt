# CMakeList.txt : CMake project for Simplex Method Calculator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

project ("Simplex Method Calculator")

include(FetchContent)

# Add source to this project's executable.
add_executable (CMakeTarget main.cpp s_vars.h SimplexCalc.h)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master)
FETCHCONTENT_MAKEAVAILABLE(fmt)

include_directories(include)

# TODO: Add tests and install targets if needed.
