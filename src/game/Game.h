/** @file */
//
// Created by bart on 01.11.2020.
//

#ifndef MAKAO_SIM_GAME_H
#define MAKAO_SIM_GAME_H

#include "../players/Player.h"
#include "../utilities/LinkedList.h"

/// ALGORITHMS
#include "../players/algorithms/PlayerPlaceholder.h"
#include "../players/algorithms/AdvancedPlaceholder.h"

/** Class responsible for simulating one game
 *
 */
class Game {
private:
    const int maxGameLength;        ///< Maximum number of turns to be played in this game
    Player **players;               ///< Array of players
    int playersNumber;              ///< Number of players
    Deck deck;                      ///< Deck of cards belonging to the game
    LinkedList<Card*>*cardsStack;   ///< Cards stack (Usually lays  between the players)

    /** Private method for transforming the current move number to player ID
     *
     * @param moveNumber move numver
     * @return player ID
     */
    [[nodiscard]] int toPlayerIndex(int moveNumber) const;

public:

    /** Game constructor
     *
     * @param randomSeed Random number - has to be different throughout the games to enure results variability
     * @param maxGameLength Max rounds to be played
     * @param playerNames List of algorithm names
     */
    Game(int randomSeed, int maxGameLength, LinkedList<std::string>& playerNames);

    /** Runs the game simulation
     *
     * @return ID of the winning player or -1 if the game was terminated due to timeout
     */
    int play();

    /**  Game destructor   */
    ~Game();
};


#endif //MAKAO_SIM_GAME_H
