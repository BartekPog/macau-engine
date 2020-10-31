//
// Created by bart on 25.10.2020.
//

#include "Player.h"

bool Player::didWin() {
    return (hand.length == 0);
}

bool Player::canStack(const Card &first, const Card &second) {
    return first.symbol == second.symbol;
}

bool Player::doesMatch(const Card &laying, const Card &putting) {
    if (pulls > 0 && delays > 0){
        if(putting.symbol == queen && putting.suit == spades)
            return true;
    }

    else if (delays > 0){
        if (putting.symbol == Symbol::four)
            if((putting.symbol == laying.symbol) || (putting.suit == laying.suit))
                return true;
        if(putting.symbol == queen && putting.suit == spades)
            return true;
    }

    else if (pulls > 0){
        if(putting.symbol == queen && putting.suit == spades)
            return true;
        if((putting.symbol == laying.symbol) || (putting.suit == laying.suit))
            switch (putting.symbol){
                //TODO
        }
    }

    return false;
}

