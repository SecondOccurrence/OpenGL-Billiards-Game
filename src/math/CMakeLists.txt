cmake_minimum_required(VERSION 3.29)

set(SOURCES
    vector_operations.c
    collision.c
)

set(HEADERS
    vector_operations.h
    collision.h
)

target_sources(output PRIVATE ${SOURCES} ${HEADERS})
