cmake_minimum_required(VERSION 3.8)
project(Ex2)

set(CMAKE_CXX_STANDARD 98)


add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


set(SOURCE_FILES main.cpp Board.cpp Board.h GeneralPlayer.h ReversiRules.cpp ReversiRules.h HumanP.cpp HumanP.h GameFlow.cpp GameFlow.h Visualization.h Console.cpp Console.h Cell.h Point.h Tests/gtest_main.cpp Tests/Test_Board.cpp Tests/Test_ReversiRules.cpp AIPlayer.cpp AIPlayer.h Tests/Test_HumanP.cpp Tests/Test_AIPlayer.cpp Client.cpp Client.h)
add_executable(Ex2 ${SOURCE_FILES} Board.cpp Board.h GeneralPlayer.h ReversiRules.cpp ReversiRules.h HumanP.cpp HumanP.h GameFlow.cpp GameFlow.h Visualization.h Console.cpp Console.h Cell.h Point.h Tests/gtest_main.cpp Tests/Test_Board.cpp Tests/Test_ReversiRules.cpp AIPlayer.cpp AIPlayer.h Tests/Test_HumanP.cpp Tests/Test_AIPlayer.cpp Client.cpp Client.h)

target_link_libraries(Ex2 gtest gtest_main)

