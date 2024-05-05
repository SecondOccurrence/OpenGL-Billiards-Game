cmake_minimum_required(VERSION 3.29)

set(HEADERS
    camera.h
)
target_sources(output PRIVATE ${SOURCES} ${HEADERS})
