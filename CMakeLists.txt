cmake_minimum_required(VERSION 2.8)
project(zephyr)

set(ZEPHYR_VERSION "0.0.1")

################################
# Locate source
################################
file(GLOB_RECURSE INCLUDES include/*.h)
file(GLOB_RECURSE SRC src/*.cpp)

include_directories(include)

################################
# Build targets
################################

add_library(zephyr
    ${SRC}
    ${INCLUDES})

################################
# Export library
################################

export_project(
    NAME zephyr
    INCLUDES ${CMAKE_CURRENT_LIST_DIR}/include
    LIBS zephyr
    VERSION ${ZEPHYR_VERSION}
)

