#pragma once
#include "Array.h"

class SortArray: public Array
{
    public:
    SortArray(int size);
    SortArray(int* array, int size);

    Array* sum(Array* value) override;
    Array* foreach() override;
};