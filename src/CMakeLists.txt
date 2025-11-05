cmake_minimum_required(VERSION 3.14)
project(DSA_Experiments_src LANGUAGES CXX)

# Enable testing
include(FetchContent)

# Fetch GoogleTest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Sources used by tests
set(DSA_SRCS
    data_structures/LL_node.cpp
    data_structures/LinkedList.cpp
    algorithms/LinkedList_algos.cpp
    utils/mem_usage.cpp
)

add_executable(tests
    tests/test_linkedlist.cpp
    ${DSA_SRCS}
)

target_include_directories(tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/data_structures
    ${CMAKE_SOURCE_DIR}/src/utils
)

target_link_libraries(tests PRIVATE gtest_main)

include(GoogleTest)

gtest_discover_tests(tests)
