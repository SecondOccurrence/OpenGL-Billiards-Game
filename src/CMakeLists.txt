cmake_minimum_required(VERSION 3.29)
# only main.c should be in this directory
target_sources(output PRIVATE 
    main.c 
    main_functions.c 
    main_functions.h 
    DataStructures.h
)

add_subdirectory(modeling)
add_subdirectory(rendering)
add_subdirectory(movement)
add_subdirectory(math)
add_subdirectory(transformations)
