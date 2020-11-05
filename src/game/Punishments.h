/** @file */
//
// Created by bart on 01.11.2020.
//

#ifndef MAKAO_SIM_PUNISHMENTS_H
#define MAKAO_SIM_PUNISHMENTS_H

/**Structure representing the punishments of players */
struct Punishments {
    int prevDelays;         ///< delays of the previous player
    int prevPulls;          ///< pulls of the previous player
    int currentDelays;      ///< delays of the current player
    int currentPulls;       ///< pulls of the current player
    int nextDelays;         ///< delays of the next player
    int nextPulls;          ///< pulls of the next player
};


#endif //MAKAO_SIM_PUNISHMENTS_H
