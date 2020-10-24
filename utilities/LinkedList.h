//
// Created by bart on 17.10.2020.
//

#ifndef MAKAO_SIM_LINKEDLIST_H
#define MAKAO_SIM_LINKEDLIST_H

#include "LinkedListEl.h"

template<typename T>
class LinkedList {
    LinkedListEl <T> * head = nullptr;
    LinkedListEl <T> * tail = nullptr;
    int length = 0;

private:

public:
    LinkedList() = default;
    void pushFront(const T& element){
        head = new LinkedListEl<T>(element,head);
        if (!length)
            tail = head;
        length++;
    }

//    void pushBack()



    class Iterator {
    private:
        LinkedListEl<T> * currentNode;
    public:
        Iterator(LinkedListEl <T> * head): currentNode(head){};
        Iterator & operator ++(){
            if (currentNode)
                currentNode = currentNode -> getNext();
            return *this;
        }

        Iterator & operator ++(int){
            Iterator iter(currentNode);
            ++(*this);
            return iter;
        }

        bool operator == (const Iterator & iter){
            return currentNode == iter.currentNode;
        }

        bool operator != (const Iterator & iter){
            return currentNode != iter.currentNode;
        }

        T operator *(){
            return currentNode->getValue();
        }

        ~Iterator() = default;
    };
};


#endif //MAKAO_SIM_LINKEDLIST_H
