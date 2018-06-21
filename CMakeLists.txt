cmake_minimum_required(VERSION 2.8)
project(course_work)

set(CMAKE_CXX_STANDARD 11)

set(
    CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_HOME_DIRECTORY}/bin
    )

set(
    CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_HOME_DIRECTORY}/lib
    )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include(headers/Config.cmake)
include(sources/Config.cmake)

add_definitions(-DSERVER_URL="http://${SERVER_URL}/cgi-bin/drmServer.py")

add_library(course_lib STATIC
        ${HEADERS}
        headers/MainFunctions.h
        headers/PayloadMaker.h
        rapidjson/document.h
        ${SHARED_SOURCES}
        ${SOURCES}
        sources/MainFunctions.cpp
        sources/PayloadMaker.cpp)
target_link_libraries(course_lib -lcurl)

add_executable(course_work
        ${HEADERS}
        headers/MainFunctions.h
        main.cpp
        )
target_link_libraries(course_work course_lib)
