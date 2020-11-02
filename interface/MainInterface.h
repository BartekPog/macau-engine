//
// Created by bart on 25.10.2020.
//

#ifndef MAKAO_SIM_MAININTERFACE_H
#define MAKAO_SIM_MAININTERFACE_H

#include "../utilities/LinkedList.h"
#include "../players/algorithms/PlayerPlaceholder.h"
#include "../game/Game.h"
#include <sstream>
#include <string>

class MainInterface {
private:
    int gamesToPlay = 0;

    LinkedList<std::string> playersNames;
    LinkedList<std::string> possibleNames;

    const int totalProgressBarSize = 100;
    char barSign = '|';
    const int maxGameMoves = 300;

    void initIterations();
    void initPlayersNames();

public:
    MainInterface();
    void runSimulation();
};


#endif //MAKAO_SIM_MAININTERFACE_H
