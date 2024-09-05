#pragma once

#include <iostream>
#include <memory>

#include "IterableBase.h"
#include "Iterator.h"

template<typename T>
class Node;
template<typename T>
class Iterator;
template<typename T>
class Linklist;
template<typename T>
class DLIterator;
template<typename T>
class DoubleLinklist;

template<typename T>
class Iterator : public IteratorBase<T>
{
public:
    Iterator(IterableBase<T>* list) : m_list(list), m_index(0), m_revertIndex(list->size() - 1) {}
    ~Iterator() {}

    bool hasNext() {
        return m_index < m_list->size();
    }

    bool hasPrev() {
        return m_revertIndex >= 0;
    }

    T next() {
        auto res = m_list->get(m_index)->getValue();
        m_index++;
        return res;
    }

    T prev() {
        auto res = m_list->get(m_revertIndex)->getValue();
        m_revertIndex--;
        return res;
    }

private:
    IterableBase<T>* m_list;
    int m_index;
    int m_revertIndex;
};

template<typename T>
class Linklist: public IterableBase<T>
{
public:
    Linklist() = default;
    ~Linklist() {};

    virtual IteratorBase<T>* createIterator() override {
        return new Iterator<T>(this);
    }

    Node<T>* front() {
        return m_head;
    }

    void push_back(T val) {
        m_size++;
        if (!m_head) {
            m_head = new Node<T>(val);
            return;
        }

        push_back(m_head, val);
    }
    Node<T>* pop_back() {
        if (!m_size) {
            return nullptr;
        }
        if (!m_head->getNext()) {
            Node<T>* res = m_head;
            delete m_head;
            m_head = nullptr;
            return res;
        }

        pop_back(m_head);
    }

    Node<T>* get(int pos) {
        if (!pos) {
            return m_head;
        }
        if (pos >= this->m_size) {
            return nullptr;
        }

        return get(m_head->getNext(), --pos);
    }
    int size() {
        return m_size;
    }
    bool isEmpty() {
        return !m_head;
    }

private:
    void push_back(Node<T>* node, T val) {
        if (!node->getNext()) {
            node->setNext(new Node<T>(val));
            return;
        }

        push_back(node->getNext(), val);
    }
    Node<T>* pop_back(Node<T>* node) {
        if (!node->getNext()->getNext()) {
            auto res = node->getNext();
            delete node->getNext();
            node->setNext(nullptr);
            return res;
        }

        pop_back(node->getNext());
    }
    
    Node<T>* get(Node<T>* node, int val) {
        if (!node) {
            return nullptr;
        }
        if (!val) {
            return node;
        }

        get(node->getNext(), --val);
    }
    
    //property
    Node<T>* m_head = nullptr;
    int m_size = 0;
};

template<typename T>
class DoubleLinklist : public IterableBase<T>
{
public:
    DoubleLinklist() = default;
    ~DoubleLinklist() {};

    virtual IteratorBase<T>* createIterator() override {
        return new Iterator<T>(this);
    }

    void push_back(T val) {
        m_size++;
        if (!m_head) {
            m_head = new Node<T>(val);
            m_tail = m_head;
            return;
        }

        push_back(m_tail, val);
    }
    Node<T>* pop_back() {
        if (!m_size) {
            return nullptr;
        }
        if (!m_head->getNext()) {
            Node<T>* res = m_head;
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
            return res;
        }

        Node<T>* res = m_tail;
        m_tail->getPrev() = m_tail->getPrev()->getPrev();
        m_tail = m_tail->getPrev();
        m_size--;
        return res;
    }

    void push_front(T val) {
        m_size++;
        if (!m_head) {
            m_head = new Node<T>(val);
            m_tail = m_head;
            return;
        }

        push_front(m_head, val);
    }
    Node<T>* pop_front() {
        if (!m_size) {
            return nullptr;
        }
        if (!m_head->getNext()) {
            Node<T>* res = m_head;
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
            m_size--;
            return res;
        }

        Node<T>* res = m_head;
        m_head->getNext() = m_head->getNext()->getNext();
        m_head = m_head->getNext();
        m_size--;
        return res;
    }

    Node<T>* front() {
        return m_head;
    }
    Node<T>* back() {
        return m_tail;
    }

    int size() {
        return m_size;
    }

    bool isEmpty() {
        return !m_size;
    }
    Node<T>* get(int pos) {
        if (!pos) {
            return m_head;
        }
        if (pos >= this->m_size) {
            return nullptr;
        }

        return get(m_head->getNext(), --pos);
    }

private:
    void push_back(Node<T>* node, T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->setNext(nullptr);
        newNode->setPrev(node);
        node->setNext(newNode);
        m_tail = newNode;
    }
    void push_front(Node<T>* node, T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->setprev(nullptr);
        newNode->setnext(node);
        node->setPrev(newNode);
        m_head = newNode;
    }

    Node<T>* get(Node<T>* node, int val) {
        if (!node) {
            return nullptr;
        }
        if (!val) {
            return node;
        }

        get(node->getNext(), --val);
    }

    //property
    Node<T>* m_head = nullptr;
    Node<T>* m_tail = nullptr;
    int m_size = 0;
};
