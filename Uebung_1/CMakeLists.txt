cmake_minimum_required(VERSION 3.27)
project(Uebung_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Uebung_1 main.cpp
        Spielfeld.cpp
        Spielfeld.h
        Charakter.cpp
        Charakter.h
        Player.cpp
        Player.h
        Player.h
        Enemy.cpp
        Enemy.h
        Spielablauf.cpp
        Spielablauf.h)
