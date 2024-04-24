cmake_minimum_required(VERSION 3.29)

set(SOURCES
    drawing.c
    drawing_utilities.c
)

set(HEADERS
    drawing.h
    drawing_utilities.h
)

target_sources(output PRIVATE ${SOURCES} ${HEADERS})
