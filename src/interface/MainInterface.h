/** @file */
//
// Created by bart on 25.10.2020.
//

#ifndef MAKAO_SIM_MAININTERFACE_H
#define MAKAO_SIM_MAININTERFACE_H

#include "../utilities/LinkedList.h"
#include "../players/algorithms/PlayerPlaceholder.h"
#include "../players/algorithms/AdvancedPlaceholder.h"
#include "../game/Game.h"
#include <sstream>
#include <string>

/** Game wrapper responsible for human interactions and simulation running */
class MainInterface {
private:
    int gamesToPlay = 0;                        ///< Number of games to play
    LinkedList<std::string> playersNames;       ///< List of the available algorithms
    LinkedList<std::string> possibleNames;      ///< List of the chosen algorithms

    /// Progress bar settings
    const int totalProgressBarSize = 100;       ///< Number of characters in the progress bar
    std::string barSign = "▓";                  ///< Progress bar sign - has to be string instead of char to enable more advanced progress bars
    const int maxGameMoves = 300;               ///< Masimum number of moves to be played in a single game

    /** Handles a menu for selecting the number of iterations */
    void initIterations();

    /** Handles a menu for selecting the algorithms */
    void initPlayersNames();

public:

    /** Main interface constructor
     *  Handles all the input and prepares for the simulation run
     *
     */
    MainInterface();

    /** Runs the simulation and prints the results  */
    void runSimulation();
};


#endif //MAKAO_SIM_MAININTERFACE_H
