//
// Created by bart on 01.11.2020.
//

#ifndef MAKAO_SIM_GAME_H
#define MAKAO_SIM_GAME_H

#include "../players/Player.h"
#include "../players/algorithms/PlayerPlaceholder.h"
#include "../utilities/LinkedList.h"
/// ALGORITHMS


class Game {
private:
    const int maxGameLength;
    Player **players;           ///< Array of players
    int playersNumber;
    Deck deck;
    LinkedList<Card*>*cardsStack;

    [[nodiscard]] int toPlayerIndex(int moveNumber) const;

public:
    Game(int randomSeed, int maxGameLength, LinkedList<std::string>& playerNames);
    int play();
    ~Game();
};


#endif //MAKAO_SIM_GAME_H