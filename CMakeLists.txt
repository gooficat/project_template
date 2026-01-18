cmake_minimum_required(VERSION 4.0)

# set(CMAKE_TOOLCHAIN_FILE
# "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/vcpkg/scripts/buildsystems/vcpkg.cmake"
# CACHE STRING "Vcpkg toolchain file"
# )
project(poem LANGUAGES CXX)

# Set CXX standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find vcpkg packages if available
find_package(PkgConfig QUIET)

# Include directories
include_directories(include)

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*)

# Add executable
add_executable(${PROJECT_NAME}
    ${SRCS}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

set(ABS_BIN_DIR ${CMAKE_SOURCE_DIR}/out/build/bin)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${ABS_BIN_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${ABS_BIN_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${ABS_BIN_DIR}
)

# Compiler-specific options
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Debug-only flags (safe for all generators)
target_compile_definitions(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
)

if(NOT MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:-g -O0>
    )
endif()

# Enable testing
enable_testing()

# Install target
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
