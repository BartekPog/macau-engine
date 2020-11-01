//
// Created by bart on 25.10.2020.
//

#ifndef MAKAO_SIM_PLAYER_H
#define MAKAO_SIM_PLAYER_H


#include "../utilities/LinkedList.h"
//#include "../game/Cards/Card.h"
#include "../game/Deck.h"

#include <iostream>

class Card;
class Deck;

/** Base virtual player/algorithm class
 *
 */
class Player {
protected:
    std::string name;
    int delays = 0;
    int pulls = 0;
    LinkedList<Card*> hand = LinkedList<Card*>();
public:
    bool didWin();
    void makeMove(LinkedList<Card*>* cardsStack, int playersNumber, int playersHandsLengths[], Player * previousPlayer, Player * nextPlayer, Deck& deck);

    /** Overridable method for choosing the cards. Cards shold be layed out in such order that the first card touching the card stack
     * should lay at the head of the list. The card in the tail will lay at the top of the card stack after move. Also remember to allocate
     * the memory for the cards stack. If making empty move return pointer to the allocated, but empty list
     *
     * @param cardsStack Stack of cards - the top card is in the head
     * @param playersNumber number of players
     * @param playersHandsLengths array of players lengths - at position 0 is the current player
     * @return list of chosen cards
     */
    virtual LinkedList<Card*>*choose(LinkedList<Card*>* cardsStack, int playersNumber, int playersHandsLengths[])=0;

    bool doesMatch(const Card * laying, const Card * putting) const;
    static bool doesMatchBasic(const Card * laying, const Card * putting);
    bool canStack(const Card * first, const Card * second);
    void pullCard(Deck& deck);
    void addPull(int);
    void setPull(int);
    [[nodiscard]] int getPull() const;
    void addDelay(int);
    void setDelay(int);
    void executeDelay();
    [[nodiscard]] int getDelay() const;
    [[nodiscard]] std::string getName() const;
    ~Player();

};


#endif //MAKAO_SIM_PLAYER_H
