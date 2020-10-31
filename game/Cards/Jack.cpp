//
// Created by bart on 29.10.2020.
//

#include "Jack.h"

void Jack::selfRestore() {
    matchingSymbols.clearList();
    matchingSymbols.pushFront(symbol);
}

void Jack::setRequest(Symbol requestedSymbol) {
    matchingSymbols.pushFront(requestedSymbol);
}
