//
// Created by bart on 25.10.2020.
//

#include "Player.h"

bool Player::didWin() {
    return (hand.length == 0);
}

bool Player::canStack(const Card *first, const Card *second) {
    return first->symbol == second->symbol;
}


bool Player::doesMatchBasic(const Card *laying, const Card *putting) {
    return ((laying->matchingSymbols.isIn(putting->symbol)) || (laying->matchingSuits.isIn(putting->suit)));
}

bool Player::doesMatch(const Card *laying, const Card *putting) const {
    if (pulls > 0 || delays > 0){
        if(putting->symbol == queen && putting->suit == spades)
            return true;
    }

    else if (delays > 0){
        if ((putting->delay > 0) && doesMatchBasic(laying, putting))
            return true;
    }

    else if (pulls > 0){
        if((putting->delay > 0) && doesMatchBasic(laying, putting)){
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

void
Player::makeMove(LinkedList<Card *>* cardsStack, int playersNumber, int *playersHandsLengths, Player *previousPlayer,
                 Player *nextPlayer, Deck& deck) {

    LinkedList<Card *> *chosenListPtr = choose(cardsStack, playersNumber, playersHandsLengths);

    // Check if is valid
    bool valid = true;
    if (chosenListPtr->length > 0) {
        for (LinkedList<Card *>::Iterator it(*chosenListPtr); !it.finished(); ++it) {
            if (!hand.isIn(*it)) {
                std::cerr << "ERROR: SELECTING CARD NOT PRESENT IN HAND IN " << name << std::endl;
                valid = false;
                break;
            }
        }

        if ((!doesMatch(cardsStack->getHead(), chosenListPtr->getHead()))) {
            valid = false;
            std::cerr << "ERROR: CARD IN HAND DOES NOT MATCH TOP CARD IN " << name << std::endl;
        }

        LinkedList<Card *>::Iterator next(*chosenListPtr);
        ++next;
        LinkedList<Card *>::Iterator current(*chosenListPtr);

        while ((!next.finished()) && (!current.finished())) {
            if (!canStack(*current, *next)) {
                valid = false;
                std::cerr << "ERROR: CARDS NOT MATCHING IN " << name << std::endl;
                break;
            }
            ++next;
            ++current;
        }
    }

    if ((!valid) || (chosenListPtr->length == 0)) {
        if (delays > 0) {
            nextPlayer->setPull(nextPlayer->getPull() + pulls);
            pulls = 0;
            delays--;
        } else if (pulls > 0) {
            while (pulls > 0) {
                pullCard(deck);
                pulls--;
            }
        } else {
            pullCard(deck);
        }
    } else { //Active move

        // Initialize punishments
        Punishments punishments{};
        punishments.prevDelays = previousPlayer->getDelay();
        punishments.prevPulls = previousPlayer->getPull();
        punishments.currentDelays = getDelay();
        punishments.currentPulls = getPull();
        punishments.nextDelays = nextPlayer->getDelay();
        punishments.nextPulls = nextPlayer->getPull();

        for (LinkedList<Card *>::Iterator it(*chosenListPtr); !it.finished(); ++it) {
            punishments = (*it)->execute(punishments);
            cardsStack->pushFront(*it);
            hand.removeMatching(*it);
            deck.shuffleIn(*it);
        }

        previousPlayer->setDelay(punishments.prevDelays);
        previousPlayer->setPull(punishments.prevPulls);
        setDelay(punishments.currentDelays);
        setPull(punishments.currentPulls);
        nextPlayer->setDelay(punishments.nextDelays);
        nextPlayer->setPull(punishments.nextPulls);
    }

    delete chosenListPtr;
}