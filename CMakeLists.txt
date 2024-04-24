cmake_minimum_required(VERSION 3.29)

project(output
    DESCRIPTION "ICT289 Assignment 2"
    LANGUAGES C)

add_executable(output)

set_target_properties(output PROPERTIES 
    WORKING_DIRECTORY ${CMAKE_CURRENT_COURSE_DIR}/
)

target_compile_options(output PRIVATE
    # GCC for linux.
    # Also should work for Code::Blocks projects. Have not tested.
    $<$<C_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
    # Visual C++ compiler. Used when using say VSCode or Visual Studio.
    $<$<C_COMPILER_ID:MSVC>:/W4>
)

add_subdirectory(lib)
add_subdirectory(src)


