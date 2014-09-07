cmake_minimum_required(VERSION 2.8)
project(libutil)

################################
# Compiler setup
################################

add_definitions(-Wall)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

################################
# Locate source
################################
file(GLOB_RECURSE INCLUDES include/*.h)
file(GLOB_RECURSE SRC src/*.cpp)

include_directories(include)
include_directories(include/util)

################################
# Build targets
################################

add_library(util SHARED
    ${SRC}
    ${INCLUDES})
