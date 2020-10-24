cmake_minimum_required(VERSION 3.17)
project(makao_sim)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES
        *.h
        *.cpp
        */*.h
        */*.cpp
)


include_directories("${PROJECT_SOURCE_DIR}" )
add_executable(makao_sim main.cpp ${SOURCES})