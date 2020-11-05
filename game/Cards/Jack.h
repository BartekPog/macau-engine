/** @file */
//
// Created by bart on 29.10.2020.
//

#ifndef MAKAO_SIM_JACK_H
#define MAKAO_SIM_JACK_H

#include "Card.h"

/** Class representing Jack card */
class Jack:public Card {
public:
    /** Jack class constructor
     *
     * @param _suit Jack's suit
     */
    explicit Jack(Suit _suit): Card(_suit, jack){};

    /** Execute placeholder
     *
     * @param p current punishments
     * @return unchanged punishments
     */
    Punishments execute(Punishments p) override {return p;};

    /** Restores the card to its base state
     *
     */
    void selfRestore() override;

    /** Sets the symbol request
     *
     * @param requestedSymbol Requested symbol
     */
    void setRequest(Symbol requestedSymbol);
};


#endif //MAKAO_SIM_JACK_H
