//
// Created by bart on 28.10.2020.
//

#ifndef MAKAO_SIM_BASICCARD_H
#define MAKAO_SIM_BASICCARD_H

#include "Card.h"

class BasicCard : public Card {
public:
    BasicCard(Suit _suit, Symbol _symbol)
    : Card(_suit, _symbol){};

    Punishments execute(Punishments p) override {return p;};
    void selfRestore() override {};
};


#endif //MAKAO_SIM_BASICCARD_H
