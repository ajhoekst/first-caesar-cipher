cmake_minimum_required(VERSION 2.8)

include_directories(${caesar_SOURCE_DIR}/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../external/ahio/utils/file-mmap/inc)

file(GLOB SRCS ${caesar_SOURCE_DIR}/src/*.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${caesar_SOURCE_DIR}/build/bin)

add_library(caesar STATIC caesar.cpp)

add_executable(run main.cpp)
target_link_libraries(run filemmap caesar)
