#include "type.h"
#include <iostream>

void printType(Type type)
{
    if(type == Type::INCOME)
        std::cout << "income ";
    else
        std::cout << "outcome ";
}