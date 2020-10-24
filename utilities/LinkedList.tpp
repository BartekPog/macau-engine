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

    LinkedListEl<T> * tmp = head;
    while(tmp)
    {
        std::cout<<tmp->getValue()<<" ";
        tmp = tmp->getNext();
    }
    std::cout<<std::endl;
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

    for (LinkedList<T>::Iterator it(this->head); !it.finished(); ++it)
    {
        removeMatching(*it);
    }

    return 0;
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
T LinkedList<T>::getTop() {
    if(head)
        return head->getValue();
    std::cerr<<"ERROR: Accessing head of an empty list"<<std::endl;
    return T();
}

template<typename T>
bool LinkedList<T>::isIn(const T &element) {
    for (LinkedList<T>::Iterator it(this->head); !it.finished(); it++)
    {
        if( *it == element)
            return true;
        std::cout<<"Testing element: "<<*it<<std::endl;
    }

    return false;
}

template<typename T>
int LinkedList<T>::getLength() {
    return length;
}

#endif