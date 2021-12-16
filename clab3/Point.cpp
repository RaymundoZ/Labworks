#include "Point.h"

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

Point::Point()
{
    x = 0;
    y = 0;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

void Point::move(double x, double y)
{
    this->x += x;
    this->y += y;
}

double Point::findOriginDistant()
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

double Point::findTwoPointsDistant(Point p)
{
    Point vector(p.x - x, p.y - y);
    double lenght = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
    return lenght;
}

void Point::toPolar(double &r, double &q)
{
    r = sqrt(pow(x, 2) + pow(y, 2));
    q = atan(y / x);
}

bool Point::operator==(Point p)
{
    return x == p.x && y == p.y;
}

bool Point::operator!=(Point p)
{
    return x != p.x || y != p.y;
}