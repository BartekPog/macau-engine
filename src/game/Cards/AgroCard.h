/** @file */
//
// Created by bart on 25.10.2020.
//

#ifndef MAKAO_SIM_AGROCARD_H
#define MAKAO_SIM_AGROCARD_H

#include "Card.h"

/** Class representing the aggressive cards those setting the pull or delay on players */
class AgroCard: public Card {
private:
    bool forward = true;
public:
    AgroCard(Suit _suit, Symbol _symbol, int _delay, int _pull, bool _forward=true)
        : Card(_suit, _symbol, _delay, _pull), forward(_forward){};

    /** Executes the pull/delay
     *
     * @return new set of punshments
     */
    Punishments execute(Punishments) override;

    void selfRestore() override {};
};


#endif //MAKAO_SIM_AGROCARD_H
