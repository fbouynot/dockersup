cmake_minimum_required(VERSION 3.3)
project(Projet_C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.c ClientTCP.h.h ClientTCP.h ClientTCP.c ClientTCP.h ServerTCP.c ServerTCP.h)

add_executable(Projet_C ${SOURCE_FILES})