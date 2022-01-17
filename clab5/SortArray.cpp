#include "SortArray.h"

SortArray::SortArray(int size) : Array(size)
{
    
}

SortArray::SortArray(int* array, int size) : Array(array, size)
{
   
}

Array* SortArray::sum(Array* value)
{
    int length = size + value->getSize();
    int* result = new int[length];
    int counter = 0;
    bool checker = true;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < value->getSize(); j++)
        {
            if(array[i] == value->getArray()[j])
            {
                checker = false;
                break;   
            }
        }
        if(checker)
        {
            result[counter] = array[i];
            counter++;
        }
        checker = true;
    }

    for(int i = 0; i < value->getSize(); i++)
    {
        result[counter] = value->getArray()[i];
        counter++;
    }
    return new SortArray(result, counter);
}

Array* SortArray::foreach()
{
    int* a = copyArr();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[i])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return new SortArray(a, size);
}