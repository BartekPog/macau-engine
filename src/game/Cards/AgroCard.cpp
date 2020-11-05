//
// Created by bart on 25.10.2020.
//

#include "AgroCard.h"

Punishments AgroCard::execute(Punishments punishments) {//TODO
    if(forward){
        punishments.nextDelays+=punishments.currentDelays;
        punishments.nextPulls+=punishments.currentPulls;
    }
    else{
        punishments.prevDelays+=punishments.currentDelays;
        punishments.prevPulls+=punishments.currentPulls;
    }

    punishments.currentPulls = 0;
    punishments.currentDelays = 0;
    return punishments;
}
