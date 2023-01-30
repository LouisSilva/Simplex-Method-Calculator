# CMakeList.txt : CMake project for Simplex Method Calculator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

project ("Simplex Method Calculator")
add_subdirectory(fmt)

# Add source to this project's executable.
add_executable (CMakeTarget main.cpp s_vars.h SimplexCalc.h)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(CMakeTarget fmt::fmt)

# TODO: Add tests and install targets if needed.
