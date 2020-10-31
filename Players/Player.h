//
// Created by bart on 25.10.2020.
//

#ifndef MAKAO_SIM_PLAYER_H
#define MAKAO_SIM_PLAYER_H

#include <iostream>
#include "../utilities/LinkedList.h"
#include "../game/Cards/Card.h"

class Card;

/** Base virtual player/algorithm class
 *
 */
class Player {
private:
    const std::string name;
    int delays = 0;
    int pulls = 0;
    LinkedList<Card*> hand;
public:
    bool didWin();
    virtual LinkedList<Card>*choose(LinkedList<Card*> cards, int playersNumber, int playersHandsLengths[])=0;//TODO Argumenty
    bool doesMatch(const Card & laying, const Card & putting);
    static bool doesMatchBasic(const Card & laying, const Card & putting);
    bool canStack(const Card & first, const Card & second);
    void pullCards(); //TODO Po implementacji Decka
    void addPull(int);
    void setPull(int);
    int getPull() const;
    void addDelay(int);
    void setDelay(int);
    void executeDelay();
    int getDelay() const;
    ~Player();
};


#endif //MAKAO_SIM_PLAYER_H
