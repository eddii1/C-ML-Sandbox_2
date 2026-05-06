cmake_minimum_required(VERSION 4.1)
project(MLSANDBOX)

set(CMAKE_CXX_STANDARD 20)

if (EXISTS "/opt/homebrew")
    list(PREPEND CMAKE_PREFIX_PATH "/opt/homebrew")
endif()

if (EXISTS "/usr/local")
    list(PREPEND CMAKE_PREFIX_PATH "/usr/local")
endif()

find_package(Armadillo REQUIRED)
find_path(MLPACK_INCLUDE_DIR
        NAMES mlpack.hpp
        HINTS /opt/homebrew/include /usr/local/include
        REQUIRED)

set(MLSANDBOX_CORE_SOURCES
        Interfata.cpp
        Interfata.h
        Sample.cpp
        Sample.h
        Dataset.cpp
        Dataset.h
        DatasetLoader.cpp
        DatasetLoader.h
        Model.cpp
        Model.h
        LinearRegression.cpp
        LinearRegression.h
        KNN.cpp
        KNN.h
)

add_executable(MLSANDBOX main.cpp
        ${MLSANDBOX_CORE_SOURCES})

add_executable(linear_regression_demo
        examples/linear_regression_demo.cpp
        ${MLSANDBOX_CORE_SOURCES})

foreach(target MLSANDBOX linear_regression_demo)
    target_include_directories(${target} PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}
            ${ARMADILLO_INCLUDE_DIRS}
            ${MLPACK_INCLUDE_DIR}
    )
    target_link_libraries(${target} PRIVATE ${ARMADILLO_LIBRARIES})
endforeach()
