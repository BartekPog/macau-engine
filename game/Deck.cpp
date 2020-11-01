//
// Created by bart on 31.10.2020.
//

#include "Deck.h"

Deck::Deck(int seed) {
    rand_engine = std::mt19937(seed);

    // Basic cards
    for (auto suit : {clubs, hearts, spades, diamonds})
        for (auto symbol : {five, six, seven, eight, nine, ten})
            shuffleIn(new BasicCard(suit, symbol));

    // pasive kings
    for (auto suit : {clubs, diamonds})
        shuffleIn(new BasicCard(suit, king));

    // passive queens
    for (auto suit : {hearts, clubs, diamonds})
        shuffleIn(new BasicCard(suit, queen));

    // Agro Cards
    for (auto suit : {clubs, hearts, spades, diamonds}){
        shuffleIn(new AgroCard(suit, two, 0,2));
        shuffleIn(new AgroCard(suit, three, 0,3));
        shuffleIn(new AgroCard(suit, four, 1,0));
    }

    // agro kings
    shuffleIn(new AgroCard(hearts, king, 0,5,true));
    shuffleIn(new AgroCard(spades, king, 0,5,false));

    // Jacks
    for (auto suit : {clubs, hearts, spades, diamonds})
        shuffleIn(new Jack(suit));

    // Aces
    for (auto suit : {clubs, hearts, spades, diamonds})
        shuffleIn(new Ace(suit));

    // Queen
    shuffleIn(new QueenOfSpades());

    assert(cards.length == 52);
}

Deck::~Deck() {
    for (LinkedList<Card *>::Iterator it(cards); !it.finished(); ++it)
        delete (*it);
}

void Deck::shuffleIn(Card * cardPointer) {
    std::uniform_int_distribution<int> distribution (0, cards.getLength());
    int index = distribution(rand_engine);
    cards.insert(cardPointer, index);
}

Card *Deck::PullOne() {
    if (cards.length <= 0)
        return nullptr;

    Card * pulled = cards.getHead();
    cards.popHead();
    return pulled;
}
