#include "TriangleType.h"

string toString(TriangleType type)
{
    if(type == TriangleType::EQUILATERAL)
        return "equilateral";
    else if(type == TriangleType::ISOSCELES)
        return "isosceles";
    else if(type == TriangleType::RIGHT)
        return "right";
    else
        return "none";
}