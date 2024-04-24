cmake_minimum_required(VERSION 3.29)

set(SOURCES
    object_transformations.c
)

set(HEADERS
    object_transformations.h
)

target_sources(output PRIVATE ${SOURCES} ${HEADERS})
