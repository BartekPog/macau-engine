//
// Created by bart on 17.10.2020.
//

#ifndef MAKAO_SIM_LINKEDLISTEL_H
#define MAKAO_SIM_LINKEDLISTEL_H

template <typename T>
class LinkedListEl {
private:
    T value;
    LinkedListEl * next;
public:
    LinkedListEl() = default;
    LinkedListEl(T val, LinkedListEl* pNext): value(val), next(pNext){};
    LinkedListEl(T val): value(val), next(nullptr){};
    const T getValue() const {
        return value;
    }
    void setValue(T newValue) {
        value = newValue;
    }
    LinkedListEl * getNext()const {
        return next;
    }
    void setNext(const LinkedListEl *newNext) {
        next = newNext;
    }
};


#endif //MAKAO_SIM_LINKEDLISTEL_H
