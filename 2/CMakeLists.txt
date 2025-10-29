cmake_minimum_required(VERSION 3.16)
project(OceanariumProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_subdirectory(third_party/unittest-cpp)

file(GLOB TEST_SOURCES tests/*.cc)

add_executable(run_tests ${TEST_SOURCES})

include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

target_include_directories(run_tests PRIVATE src)
target_link_libraries(run_tests PRIVATE unittest++ oceanarium_lib)

enable_testing()
add_test(NAME AllTests COMMAND run_tests)