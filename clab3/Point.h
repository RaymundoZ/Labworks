#pragma once
#include <math.h>

class Point
{
    double x;
    double y;

    public:
    Point(double, double);
    Point();

    double getX();

    double getY();

    void move(double, double);

    double findOriginDistant();

    double findTwoPointsDistant(Point);

    void toPolar(double&, double&);

    bool operator==(Point);

    bool operator!=(Point);

};