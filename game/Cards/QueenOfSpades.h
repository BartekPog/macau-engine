/** @file */
//
// Created by bart on 30.10.2020.
//

#ifndef MAKAO_SIM_QUEENOFSPADES_H
#define MAKAO_SIM_QUEENOFSPADES_H

#include "Card.h"

/** Class representing the queen of spades card */
class QueenOfSpades: public Card {
public:
    QueenOfSpades(): Card(spades, queen){};

    /** Executes the card function
     *  Frees the card placer of any pulls or delays
     *
     * @return new punishments
     */
    Punishments execute(Punishments) override;

    /** Changes the card to its base state
     *  In this case does nothing
     *
     */
    void selfRestore() override {};
};


#endif //MAKAO_SIM_QUEENOFSPADES_H
