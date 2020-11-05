/** @file */
//
// Created by bart on 29.10.2020.
//

#ifndef MAKAO_SIM_ACE_H
#define MAKAO_SIM_ACE_H

#include "Card.h"

/** Class representing the ace card - able to make card requests*/
class Ace: public Card {
public:
    explicit Ace(Suit _suit): Card(_suit, ace){};

    /** Card execution placeholder
     *
     * @param p punishments
     * @return unchanged punishments
     */
    Punishments execute(Punishments p) override {return p;};

    /** Restores the card to the basic state
     *  Removes the requests
     *
     */
    void selfRestore() override;

    /** Sets the card request
     *
     * @param requestedSuit suit requested by the card placer
     */
    void setRequest(Suit requestedSuit);
};


#endif //MAKAO_SIM_ACE_H
