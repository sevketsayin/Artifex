cmake_minimum_required(VERSION 3.8)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Source Files
set(SOURCES
        src/Engine.cpp

        # Core
        src/core/Log.cpp

        src/core/window.cpp
        src/core/Load.cpp
        src/core/renderer.cpp
        src/core/UI.cpp
        src/core/Mix.cpp

        src/types/shader.cpp
        src/types/module.cpp

        src/GL/glad.c
        src/ui/modifier.cpp
        src/ui/layout.cpp
)

# Libraries
set(LIBRARIES
        SDL2
        SDL2_mixer
)

# Project
project(Artifex VERSION 0.1.0 LANGUAGES C CXX)

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC "include")

add_subdirectory(examples)
