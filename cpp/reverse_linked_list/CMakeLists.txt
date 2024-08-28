cmake_minimum_required(VERSION 3.14)
project(lc_cpp_template)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include FetchContent module
include(FetchContent)

# Try to find Google Test
find_package(GTest QUIET)

# If Google Test is not found, download it
if(NOT GTest_FOUND)
    message(STATUS "Google Test not found. Downloading...")
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG release-1.12.1  # Specify a version/tag here
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add the solution library
add_library(solution
        src/solution.cpp
        include/solution.h
)
target_include_directories(solution PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Enable testing
enable_testing()

# Add the test executable
add_executable(test_solution
        test/test_solution.cpp
)

# Link the test executable with Google Test and the solution library
if(GTest_FOUND)
    target_link_libraries(test_solution PRIVATE GTest::gtest GTest::gtest_main solution)
else()
    target_link_libraries(test_solution PRIVATE gtest gtest_main solution)
endif()

# Add the test
add_test(NAME SolutionTest COMMAND test_solution)

# CTest integration
include(GoogleTest)
gtest_discover_tests(test_solution)