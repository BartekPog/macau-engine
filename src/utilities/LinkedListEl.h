/** @file*/
//
// Created by bart on 17.10.2020.
//

#ifndef MAKAO_SIM_LINKEDLISTEL_H
#define MAKAO_SIM_LINKEDLISTEL_H

#include <iostream>

/* Template element of the linked list class */
template <typename T>
class LinkedListEl {
private:
    T *value = nullptr;                ///< Pointer to the value of the element
    LinkedListEl<T> * next = nullptr;    ///< Pointer to the next element
public:
    LinkedListEl() = delete;
    LinkedListEl(const LinkedListEl<T>& el){
        if(el.value)
            value = new T(el.getValue());
        else
            value = nullptr;

        next = el.next;
    }

    LinkedListEl(const T val, LinkedListEl<T>* pNext): next(pNext){ //value(new T(val))
        value = new T(val);
    };

    T getValue() const {
        if(value)
            return *value;
        std::cerr<<"ERROR: WRONG ELEMENT ACCESS";
        return {};
    }

    void setValue(T newValue) {
        value = new T(newValue);
    }

    LinkedListEl <T>* getNext()const {
        return next;
    }

    void setNext(LinkedListEl<T> *newNext) {
        next = newNext;
    }

    ~LinkedListEl(){
        delete value;
    }
};


#endif //MAKAO_SIM_LINKEDLISTEL_H
