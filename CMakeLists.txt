cmake_minimum_required(VERSION 3.21)
project(raylib_template_portable_windows)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
add_executable(raylib_template_portable_windows src/main.cpp
        src/core/Renderer.cpp
        src/core/Renderer.hpp
        src/core/World.cpp
        src/core/World.hpp
        src/core/Common.hpp

)

find_library(RAYLIBRARY raylib lib)

target_link_libraries(raylib_template_portable_windows LINK_PUBLIC ${RAYLIBRARY} winmm)