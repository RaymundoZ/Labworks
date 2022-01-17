#include "Array.h"

Array::Array(int size)
{
    array = new int[size];
    this->size = size;
}

Array::Array(int* array, int size)
{
    this->array = array;
    this->size = size;
}

Array::~Array()
{
    delete array;
}

int* Array::getArray()
{
    return array;
}

int Array::getSize()
{
    return size;
}

void Array::print()
{
    for(int i = 0; i < size; i++)
        cout << array[i] << ", ";
}

int* Array::copyArr()
{
    int* arr = new int[size];
    for(int i = 0; i < size; i++)
        arr[i] = array[i];
    return arr;
}