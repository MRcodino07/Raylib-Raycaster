cmake_minimum_required(VERSION 3.21)
project(raylib_raycaster)

set(CMAKE_CXX_STANDARD 14)
set(BUILD_EXAMPLES OFF)

add_subdirectory(lib/raylib)

add_executable(raylib_raycaster src/main.cpp
        src/core/Renderer.cpp
        src/core/Renderer.hpp
        src/core/World.cpp
        src/core/World.hpp
        src/core/Common.hpp
        src/core/Player.cpp
        src/core/Player.hpp
)

target_link_libraries(raylib_raycaster raylib)

# Librerie specifiche per MacOS
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()