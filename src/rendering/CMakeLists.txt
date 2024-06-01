cmake_minimum_required(VERSION 3.29)

set(SOURCES
    display_functions.c
    text.c
)

set(HEADERS
    display_functions.h
    text.h
)

target_sources(output PRIVATE ${SOURCES} ${HEADERS})

add_subdirectory(animation)
