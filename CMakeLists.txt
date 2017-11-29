cmake_minimum_required(VERSION 3.8)
project(Ex2)

set(CMAKE_CXX_STANDARD 98)


add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


set(SOURCE_FILES src/main.cpp src/Board.cpp src/Board.h src/GeneralPlayer.h src/ReversiRules.cpp src/ReversiRules.h src/HumanP.cpp src/HumanP.h src/GameFlow.cpp src/GameFlow.h src/Visualization.h src/Console.cpp src/Console.h src/Cell.h src/Point.h Tests/gtest_main.cpp Tests/Test_Board.cpp Tests/Test_ReversiRules.cpp src/AIPlayer.cpp src/AIPlayer.h Tests/Test_HumanP.cpp Tests/Test_AIPlayer.cpp)
add_executable(Ex2 ${SOURCE_FILES} src/Board.cpp src/Board.h src/GeneralPlayer.h src/ReversiRules.cpp src/ReversiRules.h src/HumanP.cpp src/HumanP.h src/GameFlow.cpp src/GameFlow.h src/Visualization.h src/Console.cpp src/Console.h src/Cell.h src/Point.h Tests/gtest_main.cpp Tests/Test_Board.cpp Tests/Test_ReversiRules.cpp src/AIPlayer.cpp src/AIPlayer.h Tests/Test_HumanP.cpp Tests/Test_AIPlayer.cpp)

target_link_libraries(Ex2 gtest gtest_main)

