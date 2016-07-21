cmake_minimum_required(VERSION 3.3)
project(dockersup)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.c ClientTCP.h ClientTCP.c ServerTCP.c ServerTCP.h Getinfo.c Getinfo.h Felix.c Felix.h Alex.c Alex.h)

add_executable(Projet_C ${SOURCE_FILES})
