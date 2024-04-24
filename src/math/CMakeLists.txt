cmake_minimum_required(VERSION 3.29)

set(SOURCES
    matrix_operations.c
    vector_operations.c
)

set(HEADERS
    matrix_operations.h
    vector_operations.h
    geometry.h
)

target_sources(output PRIVATE ${SOURCES} ${HEADERS})
