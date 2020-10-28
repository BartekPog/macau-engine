//
// Created by bart on 25.10.2020.
//

#ifndef MAKAO_SIM_AGROCARD_H
#define MAKAO_SIM_AGROCARD_H

#include "Card.h"

class AgroCard: public Card {
private:
    int delay;
    int pull;
    bool forward = true;
public:
    AgroCard(Suit _suit, Symbol _symbol, int _delay, int _pull, bool _forward=true)
        : Card(_suit, _symbol), delay{_delay}, pull(_pull), forward(_forward){};

    void execute(Player *prev, Player *current, Player *next) override;
    void selfRestore() override {};
};


#endif //MAKAO_SIM_AGROCARD_H
