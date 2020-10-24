/** @file*/
//
// Created by bart on 17.10.2020.
//

#ifndef MAKAO_SIM_LINKEDLIST_H
#define MAKAO_SIM_LINKEDLIST_H

#include "LinkedListEl.h"
#include <iostream>

/** Template Linked List with extra functions and parameters
 *
 * @tparam T Type of the elements
 */
template<typename T>
class LinkedList {

public:
    LinkedListEl <T> * head = nullptr;  ///< Head of the list
    LinkedListEl <T> * tail = nullptr;  ///< Tail of the list
    int length = 0;                     ///< Length of the list

    LinkedList() = default;
    ~LinkedList();

    /** Pushes one element to the front of the list
     *
     * @param element
     */
    void pushFront(const T& element);

    /**
     * Pushes one element to the back of the list
     * @param element
     */
    void pushBack(const T& element);

    /** Removes matching elements in the list
     *
     * @param element element to compare
     * @return number of deleted elements
     */
    int removeMatching(const T& element);

    /** Removes all matching elements in the list
     *
     * @param list list of the elements to compare
     * @return number of deleted elements
     */
    int removeMatching(const LinkedList& list);

    /** Removes top element if exists
     *
     */
    void popHead();

    /** Returns top element if exists
     *
     * @return top element
     */
    T getTop();

    /** Returns last element if exists
     *
     * @return the last element
     */
    T getTail();

    /** Checks if an element is present in the list
     *
     * @param element element to check if present
     * @return the last element
     */
    bool isIn(const T& element);

    /** List length getter
     *
     * @return list length
     */
    int getLength();


    /** Class custom iterator
     *
     */
    class Iterator {
    private:
        LinkedListEl<T> * currentNode;
        friend LinkedList;
    public:
        explicit Iterator(const LinkedList <T>& l){
            std::cout<<"l.head"<<l.head;
            currentNode = l.head;
        };
        explicit Iterator(LinkedListEl <T> * head): currentNode(head){};


        bool finished(){
            std::cout<<"Testing element ";
            return currentNode == nullptr;
        }

        Iterator & operator ++(){
            std::cout<<"OBJ:"<<currentNode->getValue();
            if (currentNode)
                currentNode = currentNode -> getNext();
            return *this;
        }

        Iterator operator ++(int){
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

    friend LinkedList::Iterator;
};

#endif //MAKAO_SIM_LINKEDLIST_H
#include "LinkedList.tpp"

