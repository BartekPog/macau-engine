//
// Created by bart on 29.10.2020.
//

#ifndef MAKAO_SIM_ACE_H
#define MAKAO_SIM_ACE_H

#include "Card.h"

class Ace: public Card {
public:
    explicit Ace(Suit _suit): Card(_suit, ace){};
    void execute(Player *prev, Player *current, Player *next) override {};

    void selfRestore() override;
    void setRequest(Suit requestedSuit);

};


#endif //MAKAO_SIM_ACE_H
