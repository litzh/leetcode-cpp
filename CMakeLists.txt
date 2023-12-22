cmake_minimum_required(VERSION 3.25)
project(leetcode)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE CPP_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

Include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.5.0 # or a later release
)
FetchContent_MakeAvailable(Catch2)

add_executable(tests ${CPP_FILES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
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
