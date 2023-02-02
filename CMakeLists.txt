cmake_minimum_required(VERSION 3.16)

## project
project(cache-ci-template VERSION 0.0.1)

find_package(Catch2 3 QUIET) # conda dependency
find_package(Eigen3 REQUIRED) # conda dependency
find_package(manif REQUIRED) # source dependency

include(CTest)

# Defines the CMAKE_INSTALL_LIBDIR, CMAKE_INSTALL_BINDIR and many other useful macros.
# See https://cmake.org/cmake/help/latest/module/GNUInstallDirs.html
include(GNUInstallDirs)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")

# Create simple test
set(targetname "cache-ci-template-test")
add_executable(${targetname} test/SimpleTest.cpp)
target_link_libraries(${targetname} PRIVATE Catch2::Catch2WithMain 
                                            Eigen3::Eigen
                                            MANIF::manif)
      target_compile_definitions(${targetname} PRIVATE CATCH_CONFIG_FAST_COMPILE CATCH_CONFIG_DISABLE_MATCHERS)
      target_compile_features(${targetname} PUBLIC cxx_std_17)

add_test(NAME ${targetname} COMMAND ${targetname})
