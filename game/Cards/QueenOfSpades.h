//
// Created by bart on 30.10.2020.
//

#ifndef MAKAO_SIM_QUEENOFSPADES_H
#define MAKAO_SIM_QUEENOFSPADES_H

#include "Card.h"

class QueenOfSpades: public Card {
public:
    QueenOfSpades(): Card(spades, queen){};

    Punishments execute(Punishments) override;
    void selfRestore() override {};
};


#endif //MAKAO_SIM_QUEENOFSPADES_H
