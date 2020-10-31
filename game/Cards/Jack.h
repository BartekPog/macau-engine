//
// Created by bart on 29.10.2020.
//

#ifndef MAKAO_SIM_JACK_H
#define MAKAO_SIM_JACK_H

#include "Card.h"

class Jack:public Card {
public:
    explicit Jack(Suit _suit): Card(_suit, jack){};
    void execute(Player *prev, Player *current, Player *next) override {};
    void selfRestore() override;

    void setRequest(Symbol requestedSymbol);
};


#endif //MAKAO_SIM_JACK_H
