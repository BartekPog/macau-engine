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

class Deck {
private:
    LinkedList<Card*> cards;
public:
    Deck();
    Card * PullOne();
    void shuffleIn(Card*);

};


#endif //MAKAO_SIM_DECK_H
