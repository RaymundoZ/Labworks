#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class SelfOrganizingList
{
    private:
    Node<T>* head;

    void moveToHead(Node<T>* node);
    void deleteFromHead();
    void deleteAfterNode(Node<T>* node);

    public:
    SelfOrganizingList();
    ~SelfOrganizingList();

    bool isEmpty();
    void add(T val);
    void remove(int index);
    T* get(int index);
    int getPosition(T val);
    void print();
    void clear();
};