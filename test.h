/** @file*/
//
// Created by bart on 24.10.2020.
//

#include <cassert>
#include <iostream>
#include "utilities/LinkedList.h"
#include "game/Deck.h"
#include "game/Game.h"
#include <vector>

/** Ensures Linked List works correctly
 *
 */
void testLinkedList() {
    LinkedList<int> list;

    for (const auto &s : {1,2,3,4})
        list.pushFront(s);

    int i = 4;
    for (LinkedList<int>::Iterator it(list); !it.finished(); ++it){
        assert(i == *it);
        i--;
    }
    assert(list.isIn(4));

    list.insert(7, 3);
    assert(list.isIn(7));

    LinkedList<std::string> l;

    for (const auto &s : {"raz", "dwa", "trzy", "cztery"})
        l.pushFront(s);

    assert(l.getLength()==4);
    assert(l.isIn("dwa"));
    assert(l.isIn("trzy"));
    assert(!l.isIn("osiem"));

    LinkedList<std::string> l2;
    for (const auto &s : {"raz", "cztery"})
        l2.pushBack(s);

    assert( l.removeMatching(l2) == 2);
    assert(l.getLength()==2);
    assert(l.isIn("dwa"));
    assert(l.isIn("trzy"));
    assert(!l.isIn("raz"));
    assert(!l.isIn("cztery"));
}

/** Ensure Deck builds with no issues
 *
 */
void buildDeck(){
    Deck(42);
}

/** Ensure Game builds with no issues and terminates due to limit
 *
 */
void buildGame(){
    LinkedList<std::string> a;
    for(auto s: {"placeholder", "placeholder"})
        a.pushFront(s);
    Game game(42,100, a);
    assert(game.play() == -1);
}

/** Ensures all functions work correctly
 *
 */
void unitTest() {
    testLinkedList();
    buildDeck();
    buildGame();
}