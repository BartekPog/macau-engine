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


bool Player::doesMatchBasic(const Card &laying, const Card &putting) {
    return ((laying.matchingSymbols.isIn(putting.symbol)) || (laying.matchingSuits.isIn(putting.suit)));
}

bool Player::doesMatch(const Card &laying, const Card &putting) {
    if (pulls > 0 || delays > 0){
        if(putting.symbol == queen && putting.suit == spades)
            return true;
    }

    else if (delays > 0){
        if ((putting.delay > 0) && doesMatchBasic(laying, putting))
            return true;
    }

    else if (pulls > 0){
        if((putting.delay > 0) && doesMatchBasic(laying, putting)){
            return true;
        }
    }

    return doesMatchBasic(laying, putting);
}

void Player::addPull(int additional) {
    pulls += additional;
}

void Player::setPull(int newPulls) {
    pulls = newPulls;
}

int Player::getPull() const {
    return pulls;
}

void Player::addDelay(int additional) {
    delays += additional;
}

void Player::setDelay(int newDelays) {
    delays = newDelays;
}

void Player::executeDelay() {
    delays--;
}

int Player::getDelay() const {
    return delays;
}

Player::~Player() {
    for (LinkedList<Card *>::Iterator it(hand); !it.finished(); ++it)
        delete (*it);
}

void Player::pullCard(Deck & deck) {
    Card * tmp = deck.PullOne();
    if (tmp)
        hand.pushFront(tmp);
}



