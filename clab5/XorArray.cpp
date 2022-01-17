#include "XorArray.h"

XorArray::XorArray(int size) : Array(size)
{

}

XorArray::XorArray(int* array, int size) : Array(array, size)
{

}

Array* XorArray::sum(Array* value)
{
    int length = size + value->getSize();
    int* result = new int[length];
    int counter = 0;
    bool checker = true;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < value->getSize(); j++)
        {
            if (array[i] == value->getArray()[j])
            {
                checker = false;
                break;
            }
        }
        if (checker)
        {
            result[counter] = array[i];
            counter++;
        }
        checker = true;
    }

    for (int i = 0; i < value->getSize(); i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[j] == value->getArray()[i])
            {
                checker = false;
                break;
            }
        }
        if (checker)
        {
            result[counter] = value->getArray()[i];
            counter++;
        }
        checker = true;
    }
    return new XorArray(result, counter);
}

Array* XorArray::foreach()
{
    int* a = copyArr();
    for (int i = 0; i < size; i++)
    {
        a[i] = sqrt(a[i]);
    }
    return new XorArray(a, size);
}