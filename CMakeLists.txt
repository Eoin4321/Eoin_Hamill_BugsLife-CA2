cmake_minimum_required(VERSION 3.27)
project(Eoin_Hamill_BugsLife_CA2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Eoin_Hamill_BugsLife_CA2 main.cpp
        main.h
        Bug.cpp
        Bug.h
        Crawler.cpp
        Crawler.h
        Hopper.cpp
        Hopper.h
        Board.cpp
        Board.h
        Spider.cpp
        Spider.h)
