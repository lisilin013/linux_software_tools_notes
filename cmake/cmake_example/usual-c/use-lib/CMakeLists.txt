cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(NEWHELLO)


# ADD_SUBDIRECTORY(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
add_subdirectory(src)

message(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "This is SOURCE dir "${PROJECT_SOURCE_DIR})
message(STATUS "install prefix dir ${CMAKE_INSTALL_PREFIX}")

