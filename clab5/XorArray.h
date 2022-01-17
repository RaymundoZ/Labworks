#pragma once
#include "math.h"
#include "Array.h"

class XorArray : public Array
{
public:
    XorArray(int size);
    XorArray(int* array, int size);

    Array* sum(Array* value) override;
    Array* foreach() override;
};