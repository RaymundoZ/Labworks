#include "Triangle.h"

Triangle::Triangle(Point p1, Point p2, Point p3)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

Triangle::Triangle()
{
    p1 = Point();
    p2 = Point();
    p3 = Point();
}

Point Triangle::getP1()
{
    return p1;
}

void Triangle::setP1(Point p)
{
    p1 = p;
}

Point Triangle::getP2()
{
    return p2;
}

void Triangle::setP2(Point p)
{
    p2 = p;
}

Point Triangle::getP3()
{
     return p3;
}

void Triangle::setP3(Point p)
{
    p3 = p;
}

double Triangle::getSquare()
{
    double lenght1 = p1.findTwoPointsDistant(p2);
    double lenght2 = p2.findTwoPointsDistant(p3);
    double lenght3 = p1.findTwoPointsDistant(p3);
    double semiPerimeter = getPerimeter() / 2;
    return sqrt(semiPerimeter * (semiPerimeter - lenght1) * (semiPerimeter - lenght2) * (semiPerimeter - lenght3));
}

double Triangle::getPerimeter()
{
    double lenght1 = p1.findTwoPointsDistant(p2);
    double lenght2 = p2.findTwoPointsDistant(p3);
    double lenght3 = p1.findTwoPointsDistant(p3);
    return lenght1 + lenght2 + lenght3;
}

void Triangle::getHeights(double &h1, double &h2, double &h3)
{
    double lenght1 = p1.findTwoPointsDistant(p2);
    double lenght2 = p2.findTwoPointsDistant(p3);
    double lenght3 = p1.findTwoPointsDistant(p3);
    double semiPerimeter = getPerimeter() / 2;
    h1 = 2 * getSquare() / lenght1;
    h2 = 2 * getSquare() / lenght2;
    h3 = 2 * getSquare() / lenght3;
}

TriangleType Triangle::getType()
{
    double lenght1 = p1.findTwoPointsDistant(p2);
    double lenght2 = p2.findTwoPointsDistant(p3);
    double lenght3 = p1.findTwoPointsDistant(p3);

    if(lenght1 == lenght2 == lenght3)
        return TriangleType::EQUILATERAL;
    else if(lenght1 == lenght2 || lenght2 == lenght3 || lenght1 == lenght3)
        return TriangleType::ISOSCELES;
    else if (pow(lenght1, 2) + pow(lenght2, 2) == pow(lenght3, 2) ||
             pow(lenght2, 2) + pow(lenght3, 2) == pow(lenght1, 2) ||
             pow(lenght1, 2) + pow(lenght3, 2) == pow(lenght2, 2))
        return TriangleType::RIGHT;
    else
        return TriangleType::NONE;
}