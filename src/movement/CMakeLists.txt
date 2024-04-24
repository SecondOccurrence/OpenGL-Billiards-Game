cmake_minimum_required(VERSION 3.29)

set(SOURCES
    keyboard_utils.c
)

set(HEADERS
    keyboard_utils.h
)

target_sources(output PRIVATE ${SOURCES} ${HEADERS})
