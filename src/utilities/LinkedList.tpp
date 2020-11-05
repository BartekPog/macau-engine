//
// Created by bart on 17.10.2020.
//

#ifndef LL_TPP
#define LL_TPP
#include "utilities/LinkedList.h"

template <typename T>
void LinkedList<T>::pushFront(const T &element) {
    head = new LinkedListEl<T>(element,head);
    if (!length)
        tail = head;
    length++;
}

template <typename T>
void LinkedList<T>::pushBack(const T & element){
    if(!length)
        pushFront(element);
    else{
        tail->setNext(new LinkedListEl<T>(element, nullptr));
        tail = tail->getNext();
        length++;
    }
}

template<typename T>
void LinkedList<T>::insert(const T &element, int position) {
    position = std::min(length, position);

    if (position == 0)
        pushFront(element);
    else if (position == length)
        pushBack(element);
    else{
        LinkedListEl<T> *runner = head;
        for (int i=0; i< position - 1; i++)
            runner=runner->getNext();

        runner->setNext(new LinkedListEl<T>(element, runner->getNext()));
        length++;
    }
}

template<typename T>
int  LinkedList<T>::removeMatching(const T &element) {
    if (!head)
        return 0;

    int deleted =0;

    if (element == head->getValue()){
        length--;
        deleted++;
        LinkedListEl<T> *tmp = head->getNext();
        delete head;
        head = tmp;
        if (!head)
            return 1;
    }

    for(LinkedList<T>::Iterator it(*this); it.currentNode && it.currentNode->getNext() != nullptr; it++)
    {
        LinkedListEl<T> *currNode =it.currentNode;
        if (element ==  currNode->getNext()->getValue()){
            LinkedListEl<T> *tmp = currNode->getNext()->getNext();
            delete currNode->getNext();
            currNode->setNext(tmp);
            length--;
            deleted++;
        }
    }
    return deleted;
}

template<typename T>
int LinkedList<T>::removeMatching(const LinkedList& list) {

    int deleted = 0;
    for (LinkedList<T>::Iterator it(list); !it.finished(); ++it)
        deleted += this->removeMatching(*it);

    return deleted;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (head){
        LinkedListEl<T>* tmp = head->getNext();
        delete head;
        head=tmp;
    }
}

template<typename T>
void LinkedList<T>::popHead() {
    if (head){
        LinkedListEl<T>* tmp = head->getNext();
        delete head;
        head=tmp;
        length--;
    }
}

template<typename T>
T LinkedList<T>::getTail() {
    if(tail)
        return tail->getValue();
    std::cerr<<"ERROR: Accessing tail of an empty list"<<std::endl;
    return T();
}

template<typename T>
T LinkedList<T>::getHead() {
    if(head)
        return head->getValue();
    std::cerr<<"ERROR: Accessing head of an empty list"<<std::endl;
    return T();
}

template<typename T>
bool LinkedList<T>::isIn(const T &element) const {
    for (LinkedList<T>::Iterator it(*this); !it.finished(); it++)
    {
        if( *it == element)
            return true;
    }

    return false;
}

template<typename T>
int LinkedList<T>::getLength() {
    return length;
}

template<typename T>
int LinkedList<T>::clearList() {
    while (head){
        LinkedListEl<T>* tmp = head->getNext();
        delete head;
        head=tmp;
    }

    tail = nullptr;
    int tempLen = length;
    length = 0;
    return tempLen;
}


#endif