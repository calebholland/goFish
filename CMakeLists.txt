cmake_minimum_required(VERSION 3.13)
project(goFish)

set(CMAKE_CXX_STANDARD 11)

add_executable(goFish go_fish.cpp card.cpp card.h player.cpp player.h deck.cpp deck.h)