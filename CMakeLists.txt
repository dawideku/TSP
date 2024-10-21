cmake_minimum_required(VERSION 3.28)
project(TSP)

set(CMAKE_CXX_STANDARD 17)

add_executable(TSP main.cpp
        TSPBrute.cpp
        TSPBrute.h
        MatrixGenerator.cpp
        MatrixGenerator.h
        TSPNearestNeighbor.cpp
        TSPNearestNeighbor.h
        TSPRandom.cpp
        TSPRandom.h
)
