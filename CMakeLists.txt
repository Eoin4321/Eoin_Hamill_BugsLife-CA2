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

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(Eoin_Hamill_BugsLife_CA2 sfml-system sfml-window sfml-graphics sfml-audio)

