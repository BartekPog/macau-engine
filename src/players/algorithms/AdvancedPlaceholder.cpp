//
// Created by bart on 05.11.2020.
//

#include "AdvancedPlaceholder.h"

LinkedList<Card *> *
AdvancedPlaceholder::choose(LinkedList<Card *> *cardsStack, int playersNumber, int *playersHandsLengths) {
    auto chosen = new LinkedList<Card *>;

    Card * topCard = cardsStack->getHead();

    Card * first = nullptr;

    for (LinkedList<Card*>::Iterator it(hand); !it.finished(); ++it) {
        if (doesMatch(topCard, *it)){
            first = *it;
            chosen->pushFront(first);
            break;
        }
    }

    if (first){
        for (LinkedList<Card*>::Iterator it(hand); !it.finished(); ++it) {
            if(*it == first)
                continue;

            if(canStack(chosen->getTail(), *it))
                chosen->pushBack(*it);
        }
    }

    return chosen;
}
