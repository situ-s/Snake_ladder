cmake_minimum_required(VERSION 3.24)
project(Snake_ladder)

set(CMAKE_CXX_STANDARD 20)

add_executable(Snake_ladder main.cpp Snake.h Ladder.h Player.h Board.h DiceService.h Game.h Game.cpp)
