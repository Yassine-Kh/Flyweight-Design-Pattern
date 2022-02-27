cmake_minimum_required(VERSION 3.21)
project(Flyweight)

set(CMAKE_CXX_STANDARD 14)

add_executable(Flyweight main.cpp TreeFactory.cpp TreeFactory.h Forest.cpp Forest.h Tree.cpp Tree.h NoFlyweightForest.cpp NoFlyweightForest.h NoFlyweightTree.cpp NoFlyweightTree.h)
