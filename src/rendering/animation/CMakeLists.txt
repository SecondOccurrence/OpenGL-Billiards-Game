cmake_minimum_required(VERSION 3.29)

set(SOURCES
    animation.c
)

set(HEADERS
    animation.h
)

target_sources(output PRIVATE ${SOURCES} ${HEADERS})
