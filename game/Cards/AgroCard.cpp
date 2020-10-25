//
// Created by bart on 25.10.2020.
//

#include "AgroCard.h"

void AgroCard::execute(Player *prev,Player *current,Player *next) {
    Player* actedUpon = (forward ? next : prev);

    actedUpon->addPull(current->getPull());
    current->setPull(0);

    actedUpon->addDelay(current->getDelay());
    current->setDelay(0);
}
