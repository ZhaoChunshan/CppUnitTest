# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

add_subdirectory(googletest)
include(GoogleTest)
# Set the project name
project (CppUnitTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
#    run_boost.cpp
#        run_catch2.cpp
        run_gtest.cpp
        )
# Add an executable with the above sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(${PROJECT_NAME}
        PUBLIC
        "${PROJECT_SOURCE_DIR}"

        )
target_link_libraries(${PROJECT_NAME}
        GTest::gtest_main
        )
