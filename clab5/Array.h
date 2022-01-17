#pragma once
#include <iostream>
using namespace std;

class Array
{
    protected:
    int* array;
    int size;

    public:
    Array(int size);
    Array(int* array, int size);
    ~Array();

    int* getArray();
    int getSize();
    void print();
    int* copyArr();

    virtual Array* sum(Array* value) = 0;
    virtual Array* foreach() = 0;
};