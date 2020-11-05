/** @file */
//
// Created by bart on 05.11.2020.
//

#ifndef MAKAO_SIM_ADVANCEDPLACEHOLDER_H
#define MAKAO_SIM_ADVANCEDPLACEHOLDER_H

#include "../Player.h"

/** Advanced algorithm placeholder */
class AdvancedPlaceholder: public Player {
public:
    AdvancedPlaceholder(){
        name = "adv-placeholder";
    };

    LinkedList<Card *> * choose(LinkedList<Card *> *cardsStack, int playersNumber, int *playersHandsLengths) override;
};


#endif //MAKAO_SIM_ADVANCEDPLACEHOLDER_H
