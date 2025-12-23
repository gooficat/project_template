cmake_minimum_required(VERSION 3.15)

project(project_template LANGUAGES C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.c")

add_executable(project_template
    ${SOURCES}
)

if(MSVC)
    target_compile_options(project_template PRIVATE /W4)
else()
    target_compile_options(project_template PRIVATE -Wall -Wextra -Wpedantic)
endif()

set(CMAKE_BUILD_TYPE Debug)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(project_template PRIVATE DEBUG)
    if(not MSVC)
        target_compile_options(project_template PRIVATE -g -O0)
    endif()
endif()

enable_testing()