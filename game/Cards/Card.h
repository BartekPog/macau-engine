/** @file */
//
// Created by bart on 25.10.2020.
//

#ifndef MAKAO_SIM_CARD_H
#define MAKAO_SIM_CARD_H

#include "../../utilities/LinkedList.h"
#include "../../Players/Player.h"

class Player;

enum Symbol {
    ace,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king
};

enum Suit {
    clubs,
    hearts,
    spades,
    diamonds
};
/** Card virtual base class
 *
 */
class Card {
public:
    const Suit suit;                        ///< Suit or color of the card
    const Symbol symbol;                    ///< Symbol, value of the card
    LinkedList<Symbol> matchingSymbols;     ///< List of matching symbols
    LinkedList<Suit> matchingSuits;         ///< List of matching suits

    Card(Suit _suit, Symbol _symbol): suit(_suit), symbol(_symbol){
        matchingSuits.pushFront(suit);
        matchingSymbols.pushFront(symbol);
    };

    virtual void selfRestore() =0;          ///< Method restoring the card to basic state
    virtual void execute(Player* prev, Player* current, Player* next)=0;               ///< Method executing the extra card actions
};


#endif //MAKAO_SIM_CARD_H
