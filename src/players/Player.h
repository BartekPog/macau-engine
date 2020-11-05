/** @file */
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

/** Base virtual player/algorithm class */
class Player {
protected:
    std::string name;                               ///< Name of the algorithm
    int delays = 0;                                 ///< Current number of delays
    int pulls = 0;                                  ///< Current number of pulls
    LinkedList<Card*> hand = LinkedList<Card*>();   ///< Cards on hand
public:

    /** Checks if player won
     *
     * @return true if player won
     */
    [[nodiscard]] bool didWin() const;

    /** Handles full player move - from choice to execution
     *
     * @param cardsStack                ///< Cards stacked on the table
     * @param playersNumber             ///< Number of players in the game
     * @param playersHandsLengths       ///< Players hands lengths - at position 0 is the current player
     * @param previousPlayer            ///< Pointer to the previous player
     * @param nextPlayer                ///< Pointer to the next player
     * @param deck                      ///< Reference to the deck on the table
     */
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

    /** Checks if a card can be placed on a card stack
     *  It takes into consideration the user state
     *
     * @param laying Card laying on the top of the stack
     * @param putting Card willing to be put on the stack
     * @return true if card can be placed
     */
    bool doesMatch(const Card * laying, const Card * putting) const;

    /** Checks if a card could be put on the table if no punishments were put on the player
     *
     * @param laying Card laying on the table
     * @param putting Card which is tested
     * @return true if card can be placed
     */
    static bool doesMatchBasic(const Card * laying, const Card * putting);

    /** Returns true if two cards can be stacked together
     *
     * @param first First card to be stacked
     * @param second Second card to be stacked
     * @return
     */
    bool canStack(const Card * first, const Card * second);

    /** Pulls one card from deck
     *
     * @param deck reference to the deck
     */
    void pullCard(Deck& deck);

    /** Adds given number of pull requests to player
     * @param additional pull
     */
    void addPull(int);

    /** Sets pull to given
     * @param pull to be set
     */
    void setPull(int);

    /** Pull value getter*/
    [[nodiscard]] int getPull() const;

    /** Adds given number of delays to player
     * @param additional delay
     */
    void addDelay(int);

    /** Sets the delays to given
     * @param delay
     */
    void setDelay(int);

    /** Executes one delay */
    void executeDelay();

    /** Delay number getter */
    [[nodiscard]] int getDelay() const;

    /** Gets the length of a hand */
    [[nodiscard]] int getHandLength() const;

    /** Gets the algorithm name */
    [[nodiscard]] std::string getName() const;

    /** Player Destructor */
    ~Player();
};


#endif //MAKAO_SIM_PLAYER_H
