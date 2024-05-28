cmake_minimum_required(VERSION 3.29)

set(HEADERS
    objects.h
    camera.h
    flags.h
    general.h
)
target_sources(output PRIVATE ${SOURCES} ${HEADERS})
