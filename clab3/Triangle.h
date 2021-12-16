#pragma once
#include "Point.h"
#include "TriangleType.h"
#include <math.h>

class Triangle
{
    Point p1;
    Point p2;
    Point p3;

    public:
    Triangle(Point, Point, Point);
    Triangle();

    Point getP1();
    void setP1(Point);

    Point getP2();
    void setP2(Point);

    Point getP3();
    void setP3(Point);

    double getSquare();

    double getPerimeter();

    void getHeights(double&, double&, double&);

    TriangleType getType();

};