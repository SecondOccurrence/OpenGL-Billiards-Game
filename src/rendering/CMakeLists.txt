cmake_minimum_required(VERSION 3.29)

set(SOURCES
    display_functions.c
)

set(HEADERS
    display_functions.h
)

target_sources(output PRIVATE ${SOURCES} ${HEADERS})
