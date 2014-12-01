cmake_minimum_required(VERSION 2.8)
project(libutil)

set(UTIL_VERSION "0.0.1")

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

################################
# Export library
################################

export_project(
    NAME libutil
    INCLUDES ${CMAKE_CURRENT_LIST_DIR}/include
    LIBS util
    VERSION ${UTIL_VERSION}
)

