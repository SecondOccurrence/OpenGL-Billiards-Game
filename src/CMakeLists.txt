cmake_minimum_required(VERSION 3.29)
# only main.c should be in this directory
target_sources(output PRIVATE 
    main.c 
    initialisation.c 
    initialisation.h 
    gl_callback.c
    gl_callback.h
)

add_subdirectory(data_structures)
add_subdirectory(globals)
add_subdirectory(input)
add_subdirectory(math)
add_subdirectory(modeling)
add_subdirectory(rendering)
