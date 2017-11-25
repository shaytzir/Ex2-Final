cmake_minimum_required(VERSION 3.8)
project(Ex2)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Board.cpp Board.h GeneralPlayer.h ReversiRules.cpp ReversiRules.h HumanP.cpp HumanP.h GameFlow.cpp GameFlow.h Visualization.h Console.cpp Console.h Cell.h Point.h AIPlayer.cpp AIPlayer.h)
add_executable(Ex2 ${SOURCE_FILES} Board.cpp Board.h GeneralPlayer.h ReversiRules.cpp ReversiRules.h HumanP.cpp HumanP.h GameFlow.cpp GameFlow.h Visualization.h Console.cpp Console.h Cell.h Point.h)