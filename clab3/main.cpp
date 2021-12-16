#include <iostream>
#include "Triangle.h"
using namespace std;

int main() 
{
    int choice;
    Triangle *triangle = nullptr;
    cout << "1. Initialize object;\n2. Square;\n3. Perimeter;\n4. Heights;\n5. Type;\n0. Close program;";
    while(true)
    {
        cout << "\nEnter a number: ";
        cin >> choice;
        cout << '\n';
        switch(choice)
        {
            case 0:
            {
                delete triangle;
                system("pause");
                return 0;
            }
            case 1:
            {
                double x1;
                double y1;
                double x2;
                double y2;
                double x3;
                double y3;

                cout << "Enter x of point1" << endl;
                cin >> x1;
                cout << "Enter y of point1" << endl;
                cin >> y1;
                cout << "Enter x of point2" << endl;
                cin >> x2;
                cout << "Enter y of point2" << endl;
                cin >> y2;
                cout << "Enter x of point3" << endl;
                cin >> x3;
                cout << "Enter y of point3" << endl;
                cin >> y3;

                triangle = new Triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
                cout << "Object was created" << endl;
                break;
            }
            case 2:
            {
                cout << "The square is " << triangle->getSquare() << endl;
                break;
            }
            case 3:
            {
                cout << "The perimeter is " << triangle->getPerimeter() << endl;
                break;
            }
            case 4:
            {
                double h1;
                double h2;
                double h3;
                triangle->getHeights(h1, h2, h3);
                cout << "The heights are:" << endl;
                cout << "1) " << h1 << endl;
                cout << "2) " << h2 << endl;
                cout << "3) " << h3 << endl;
                break;
            }
            case 5:
            {
                cout << "The type is " << toString(triangle->getType()) << endl;
                break;
            }
            default:
            {
                cout << "Wrong input" << endl;
                break;
            }
        }
    }
}