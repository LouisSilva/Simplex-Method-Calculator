cmake_minimum_required(VERSION 3.14)
project(SimplexMethodCalculator)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

add_executable(SimplexMethodCalculator main.cpp SimplexCalc.h s_vars.h)

FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master)

FetchContent_MakeAvailable(fmt)
target_link_libraries(SimplexMethodCalculator fmt::fmt)

include_directories(include)