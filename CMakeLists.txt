cmake_minimum_required(VERSION 3.25)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE CPP_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE TEST_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

Include(FetchContent)
FetchContent_Declare(
    Catch2 GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.5.0 # or a later release
)
FetchContent_MakeAvailable(Catch2)

add_executable(tests ${CPP_FILES} ${TEST_FILES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
set_property(TARGET tests PROPERTY CXX_STANDARD 17)
target_compile_options(tests PRIVATE 
    -Wall 
    -Wextra 
    -pedantic 
    -Werror 
    -Wno-unused-parameter 
    -Wno-unused-variable 
    -Wno-unused-but-set-variable 
    -Wno-unused-function 
    -Wno-unused-but-set-parameter 
    -Wno-unused-result 
    -Wno-unused-value 
    -Wno-unused-local-typedefs 
    -ftrapv)

include(CTest)
include(Catch)
catch_discover_tests(tests)

find_program(CLANG_TIDY_EXE NAMES "clang-tidy" REQUIRED)
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "--format-style=llvm")
set_target_properties(tests PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
