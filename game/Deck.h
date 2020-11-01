//
// Created by bart on 31.10.2020.
//

#ifndef MAKAO_SIM_DECK_H
#define MAKAO_SIM_DECK_H

#include "Cards/Ace.h"
#include "Cards/AgroCard.h"
#include "Cards/BasicCard.h"
#include "Cards/Jack.h"
#include "Cards/QueenOfSpades.h"

#include <ctime>
#include <random>
#include <cassert>


/** Class representing the deck of cards in a game
 *
 */
class Deck {
private:
    LinkedList<Card*> cards;
    std::mt19937 rand_engine;
public:
    /** Deck main construrctor
     *
     * @param seed shuffling randomness seed
     */
    explicit Deck(int seed);

    /** Pulls one card from card
     *
     * @return card pointer
     */
    Card * PullOne();

    /** Shuffles one card into the deck
     *
     * @param card pointer
     */
    void shuffleIn(Card*);

    /** Deck destructor
     * Destructs only the elements which currently belong to the deck - other have to be destroyed by the players
     */
    ~Deck();
};


#endif //MAKAO_SIM_DECK_H
