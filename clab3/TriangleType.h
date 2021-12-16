#pragma once
#include <string>
using namespace std;

enum TriangleType
{
    EQUILATERAL,
    ISOSCELES,
    RIGHT,
    NONE
};

string toString(TriangleType);