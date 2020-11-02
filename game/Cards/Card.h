/** @file */
//
// Created by bart on 25.10.2020.
//


#ifndef MAKAO_SIM_CARD_H
#define MAKAO_SIM_CARD_H


#include "../../utilities/LinkedList.h"
//#include "../../players/Player.h"
#include "../Punishments.h"

enum Symbol {
    ace,
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
    const int delay;
    const int pull;

    Card(Suit _suit, Symbol _symbol): suit(_suit), symbol(_symbol), delay(0), pull(0){
        matchingSuits.pushFront(suit);
        matchingSymbols.pushFront(symbol);
    };

    Card(Suit _suit, Symbol _symbol, int _delay, int _pull): suit(_suit), symbol(_symbol), delay(_delay), pull(_pull){
        matchingSuits.pushFront(suit);
        matchingSymbols.pushFront(symbol);
    };

    virtual void selfRestore() =0;          ///< Method restoring the card to basic state
    virtual Punishments execute(Punishments)=0;    ///< Method executing the extra card actions
    virtual ~Card()=default;
};


#endif //MAKAO_SIM_CARD_H
