cmake_minimum_required(VERSION 3.29)

set(SOURCES
    matrix_operations.c
    vector_operations.c
    collision.c
)

set(HEADERS
    matrix_operations.h
    vector_operations.h
    collision.h
)

target_sources(output PRIVATE ${SOURCES} ${HEADERS})
