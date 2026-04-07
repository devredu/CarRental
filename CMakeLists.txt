cmake_minimum_required(VERSION 4.0)
project(CarRental C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
add_executable(CarRental
        main.c
        structs.h
        structs.c
        gui.h
        gui.c
)
