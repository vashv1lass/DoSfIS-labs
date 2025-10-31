cmake_minimum_required(VERSION 3.16)
project(lab2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)
set(UNITTEST_DIR ${CMAKE_SOURCE_DIR}/third-party/unittest-cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -O0 -g")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

include_directories(${SRC_DIR})
include_directories(${UNITTEST_DIR})

file(GLOB_RECURSE ALL_SRC
    "${SRC_DIR}/*.cc"
)

list(FILTER ALL_SRC EXCLUDE REGEX ".*/main\\.(cc|cpp)$")

add_library(project_lib STATIC ${ALL_SRC})
target_include_directories(project_lib PUBLIC ${SRC_DIR})

if(EXISTS "${UNITTEST_DIR}/CMakeLists.txt")
    add_subdirectory(${UNITTEST_DIR} ${CMAKE_BINARY_DIR}/unittest_build)
else()
    message(FATAL_ERROR "UnitTest++ CMakeLists not found in ${UNITTEST_DIR}")
endif()

file(GLOB TEST_SOURCES "${TEST_DIR}/*.cpp" "${TEST_DIR}/*.cc")

add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests PRIVATE project_lib UnitTest++)

enable_testing()
add_test(NAME run_all_tests COMMAND runTests)

find_program(GCOVR_PATH gcovr)

if(GCOVR_PATH)
    message(STATUS "gcovr found: ${GCOVR_PATH}")

    add_custom_target(coverage
        COMMAND ${CMAKE_CTEST_COMMAND} --verbose
        COMMAND ${GCOVR_PATH}
            --root ${CMAKE_SOURCE_DIR}/src
            --object-directory ${CMAKE_BINARY_DIR}
            --exclude ${UNITTEST_DIR}
            --exclude ${TEST_DIR}
            --filter ${SRC_DIR}
            --branches
            --sort-percentage
            --txt
            --print-summary
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running code coverage with gcovr..."
        USES_TERMINAL
    )
endif()