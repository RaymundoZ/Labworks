#include <iostream>
#include "SortArray.h"
#include "XorArray.h"
using namespace std;

int main()
{
    int choice;
    Array* first = nullptr;
    Array* second = nullptr;
    cout << "1. Initialize objects;\n2. Sum;\n3. Foreach;\n0. Close program;";
    while (true)
    {
        cout << "\nEnter a number: ";
        cin >> choice;
        cout << '\n';
        switch (choice)
        {
            case 0:
            {
                delete first;
                delete second;
                system("pause");
                return 0;
            }
            case 1:
            {
                int size1;
                int size2;
                int* arr1;
                int* arr2;
    
                cout << "Enter size1" << endl;
                cin >> size1;
    
                arr1 = new int[size1];
                for(int i = 0; i < size1; i++)
                {
                    cout << "Enter " << i << " element" << endl;
                    cin >> arr1[i];
                }
    
                cout << "Enter size2" << endl;
                cin >> size2;
    
                arr2 = new int[size2];
                for (int i = 0; i < size2; i++)
                {
                    cout << "Enter " << i << " element" << endl;
                    cin >> arr2[i];
                }
    
                cout << "SortArray or XorArray? (s/x)" << endl;
                char c;
                while(true)
                {
                    cin >> c;
                    if(c == 's')
                    {
                        first = new SortArray(arr1, size1);
                        second = new SortArray(arr2, size2);
                        break;
                    }
                    else if(c == 'x')
                    {
                        first = new XorArray(arr1, size1);
                        second = new XorArray(arr2, size2);
                        break;
                    }
                    else
                    {
                        cout << "Wrong input" << endl;
                    }
                }
    
                cout << "Object were created" << endl;
                cout << "Fisrt array is:" << endl;
                first->print();
                cout << endl << "Second array is:" << endl;
                second->print();
                cout << endl;
                break;
            }
            case 2:
            {
                if (first == nullptr || second == nullptr)
                {
                    cout << "Initialize objects first" << endl;
                    continue;
                }

                Array* res = first->sum(second);
                cout << "The sum is:" << endl;
                res->print();
                cout << endl;
                break;
            }
            case 3:
            {
                if (first == nullptr || second == nullptr)
                {
                    cout << "Initialize objects first" << endl;
                    continue;
                }

                Array* res1 = first->foreach();
                Array* res2 = second->foreach();
                cout << "Foreach for first is:" << endl;
                res1->print();
                cout << endl << "Foreach for second is:" << endl;
                res2->print();
                cout << endl;
                break;
            }
            default:
            {
                cout << "Wrong input" << endl;
                break;
            }
        }
    }
    system("pause");
}