cmake_minimum_required(VERSION 3.29)

set(SOURCES
    keyboard_utils.c
    user_input.c
)

set(HEADERS
    keyboard_utils.h
    user_input.h
)

target_sources(output PRIVATE ${SOURCES} ${HEADERS})
