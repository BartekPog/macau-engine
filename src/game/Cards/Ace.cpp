//
// Created by bart on 29.10.2020.
//

#include "Ace.h"

void Ace::selfRestore() {
    matchingSuits.clearList();
    matchingSuits.pushFront(suit);
}

void Ace::setRequest(Suit requestedSuit) {
    matchingSuits.clearList();
    matchingSuits.pushFront(requestedSuit);
}


