/** @file*/
//
// Created by bart on 24.10.2020.
//

#include <cassert>
#include <iostream>
#include "utilities/LinkedList.h"


void unitTest() {
    LinkedList<int> list;

    for (const auto &s : {1,2,3,4})
        list.pushFront(s);

    int i = 4;
    for (LinkedList<int>::Iterator it(list); !it.finished(); ++it){
        assert(i == *it);
        i--;
    }

    assert(list.isIn(4));

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

    assert( l.removeMatching(l2)== 2);
    assert(l.getLength()==2);
    assert(l.isIn("dwa"));
    assert(l.isIn("trzy"));
    assert(!l.isIn("raz"));
    assert(!l.isIn("cztery"));

};