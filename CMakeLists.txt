cmake_minimum_required(VERSION 4.1)
project(MLSANDBOX)

set(CMAKE_CXX_STANDARD 20)

add_executable(MLSANDBOX main.cpp
        Interfata.cpp
        Interfata.h
        Sample.cpp
        Sample.h
        Dataset.cpp
        Dataset.h
        DatasetLoader.cpp
        DatasetLoader.h
)
