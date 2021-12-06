#include <iostream>
#include "LongLong.h"
using namespace std;

int main()
{
    int choice;
    LongLong *obj1 = nullptr;
    LongLong *obj2 = nullptr;
    cout << "1. Initialize objects;\n2. Sum;\n3. Dif;\n4. Mult;\n5. Div;\n6. Compare objects;\n0. Close program;";
    while (true)
    {
        cout << "\nEnter a number: ";
        cin >> choice;
        cout << '\n';
        switch (choice)
        {
        case 0:
        {
            system("pause");
            return 0;
        }
        case 1:
        {
            long bP1 = 0;
            unsigned long sP1 = 0;
            long bP2 = 0;
            unsigned long sP2 = 0;
            cout << "Enter bigPart of obj1" << endl;
            cin >> bP1;
            cout << "Enter smallPart of obj1" << endl;
            cin >> sP1;
            cout << "Enter bigPart of obj2" << endl;
            cin >> bP2;
            cout << "Enter smallPart of obj2" << endl;
            cin >> sP2;
            obj1 = new LongLong(bP1, sP1);
            obj2 = new LongLong(bP2, sP2);
            cout << "Objects were created" << endl;
            break;
        }
        case 2:
        {
            cout << "The sum is: " << (*obj1 + *obj2).toString() << endl;
            break;
        }
        case 3:
        {
            cout << "The dif is: " << (*obj1 - *obj2).toString() << endl;
            break;
        }
        case 4:
        {
            cout << "The mult is: " << (*obj1 * *obj2).toString() << endl;
            break;
        }
        case 5:
        {
            cout << "The div is: " << (*obj1 / *obj2).toString() << endl;
            break;
        }
        case 6:
        {
            if(*obj1 == *obj2)
                cout << "Objects are equal" << endl;
            else
                cout << "Objects are not equal" << endl;
            if(*obj1 > *obj2)
                cout << "Obj1 > Obj2" << endl;
            if(*obj1 < *obj2)
                cout << "Obj1 < Obj2" << endl;
            break;
        }

        default:
            cout << "Неправильный ввод, попробуй снова\n";
            break;
        }
    }
    system("pause");
    return 0;
}