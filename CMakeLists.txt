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
add_executable(makao_sim main.cpp ${SOURCES} interface/MainInterface.cpp interface/MainInterface.h players/Player.cpp players/Player.h game/Cards/Card.cpp game/Cards/Card.h game/Cards/AgroCard.cpp game/Cards/AgroCard.h game/Cards/BasicCard.h game/Cards/Jack.cpp game/Cards/Jack.h game/Cards/Ace.cpp game/Cards/Ace.h game/Cards/QueenOfSpades.cpp game/Cards/QueenOfSpades.h game/Deck.cpp game/Deck.h game/Punishments.h game/Game.cpp game/Game.h players/algorithms/PlayerPlaceholder.cpp players/algorithms/PlayerPlaceholder.h)