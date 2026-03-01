cmake_minimum_required(VERSION 3.15)
project(vortex)

add_library(Vortex INTERFACE)

target_include_directories(Vortex INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(DIRECTORY include/Vortex
    DESTINATION include
)
