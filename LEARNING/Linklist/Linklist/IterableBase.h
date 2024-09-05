#pragma once

#include "IteratorBase.h"

template<typename T>
class Node
{
public:
    Node() = default;
    Node(T value) : value(value) {}

    ~Node() = default;

    void setNext(Node<T>* next) {
        this->next = next;
    }
    
    Node<T>* getNext() const {
        return next;
    }

    void setPrev(Node<T>* prev) {
        this->prev = prev;
    }
    Node<T>* getPrev() const {
        return prev;
    }

    void setValue(T value) {
        this->value = value;
    }
    T getValue() const {
        return value;
    }

private:
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
    T value;
};

template<typename T>
class IterableBase
{
public:
	virtual IteratorBase<T>* createIterator() = 0;
	virtual int size() = 0;
	virtual Node<T>* get(int pos) = 0;
};