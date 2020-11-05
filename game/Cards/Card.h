/** @file */
//
// Created by bart on 25.10.2020.
//


#ifndef MAKAO_SIM_CARD_H
#define MAKAO_SIM_CARD_H


#include "../../utilities/LinkedList.h"
//#include "../../players/Player.h"
#include "../Punishments.h"

/** All the Symbols avaliable in the simulator */
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

/** All the suits available in the game */
enum Suit {
    clubs,
    hearts,
    spades,
    diamonds
};


/** Card virtual base class */
class Card {
public:
    const Suit suit;                        ///< Suit or color of the card
    const Symbol symbol;                    ///< Symbol, value of the card
    LinkedList<Symbol> matchingSymbols;     ///< List of matching symbols
    LinkedList<Suit> matchingSuits;         ///< List of matching suits
    const int delay;                        ///< Delay given by card
    const int pull;                         ///< Pull request given by card

    /** Main card constructor for non aggresive cards
     *
     * @param _suit Card suit
     * @param _symbol Card symbol
     */
    Card(Suit _suit, Symbol _symbol): suit(_suit), symbol(_symbol), delay(0), pull(0){
        matchingSuits.pushFront(suit);
        matchingSymbols.pushFront(symbol);
    };

    /** Card constructor for aggresive cards
     *
     * @param _suit Card suit
     * @param _symbol Card symbol
     * @param _delay Delay given by the card
     * @param _pull Pulls given by the card
     */
    Card(Suit _suit, Symbol _symbol, int _delay, int _pull): suit(_suit), symbol(_symbol), delay(_delay), pull(_pull){
        matchingSuits.pushFront(suit);
        matchingSymbols.pushFront(symbol);
    };

    virtual void selfRestore() =0;                 ///< Method restoring the card to basic state
    virtual Punishments execute(Punishments)=0;    ///< Method executing the extra card actions
    virtual ~Card()=default;                       ///< Default card destructor
};


#endif //MAKAO_SIM_CARD_H
