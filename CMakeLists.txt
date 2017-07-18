cmake_minimum_required(VERSION 3.3)
project(dockersup)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES
        main.c ClientTCP.h ClientTCP.c ServerTCP.c ServerTCP.h Getinfo.c Getinfo.h Query.c Query.h Menu.c Menu.h SetServerIp.c SetServerIp.h)

add_executable(Projet_C ${SOURCE_FILES})
