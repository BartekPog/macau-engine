/** @file */
//
// Created by bart on 01.11.2020.
//

#ifndef MAKAO_SIM_PLAYERPLACEHOLDER_H
#define MAKAO_SIM_PLAYERPLACEHOLDER_H

#include "../Player.h"
/** Basic algorithm placeholder */
class PlayerPlaceholder : public Player {
public:
    PlayerPlaceholder(){
        name = "placeholder";
    };

    LinkedList<Card *> * choose(LinkedList<Card *> *cardsStack, int playersNumber, int *playersHandsLengths) override;
};


#endif //MAKAO_SIM_PLAYERPLACEHOLDER_H
