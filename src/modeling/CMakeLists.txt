cmake_minimum_required(VERSION 3.29)

set(SOURCES
    drawing.c
    object_loading.c
)

set(HEADERS
    drawing.h
    object_loading.h
)

target_sources(output PRIVATE ${SOURCES} ${HEADERS})
