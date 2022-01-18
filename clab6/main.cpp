#include "SelfOrganizingList.h"
#include "SelfOrganizingList.inl"

int main()
{
    int choice;
    cout << "1. Initialize object;\n2. Add;\n3. Remove;\n4. Get;\n5. Get Position;\n6. Print;\n0. Close program;";
    char type;
    SelfOrganizingList<int>* iList;
    SelfOrganizingList<char>* cList;
    while (true)
    {
        cout << "\nEnter a number: ";
        cin >> choice;
        cout << '\n';
        switch (choice)
        {
            case 0:
            {
                if(type == 'i')
                    delete iList;
                else if(type == 'c')
                    delete cList;
                system("pause");
                return 0;
            }
            case 1:
            {
                cout << "Enter a list type (i - int / c - char)" << endl;
                while(true)
                {
                    cin >> type;
                    if(type == 'i')
                    {
                        iList = new SelfOrganizingList<int>();
                        cout << "Object was created" << endl;
                        break;
                    }
                    else if(type == 'c')
                    {
                        cList = new SelfOrganizingList<char>();
                        cout << "Object was created" << endl;
                        break;
                    }
                    else
                        cout << "Wrong input" << endl;
                }
                break;
            }
            case 2:
            {
                int amount;
                cout << "Enter amount of elements" << endl;
                cin >> amount;
                if(type == 'i')
                {
                    for(int i = 0; i < amount; i++)
                    {
                        int element;
                        cout << "Enter " << i << " element" << endl;
                        cin >> element;
                        iList->add(element);
                    }
                }
                else if(type == 'c')
                {
                    for(int i = 0; i < amount; i++)
                    {
                        char element;
                        cout << "Enter " << i << " element" << endl;
                        cin >> element;
                        cList->add(element);
                    }
                }
                break;
            }
            case 3:
            {
                int index;
                cout << "Enter an element index to remove" << endl;
                cin >> index;
                if(type == 'i')
                    iList->remove(index);
                else if(type == 'c')
                    cList->remove(index);
                break;
            }
            case 4:
            {
                int index;
                cout << "Enter an element index to get" << endl;
                cin >> index;
                if (type == 'i')
                {
                    int* value = iList->get(index);
                    if (value == nullptr)
                        cout << "There is no such an element" << endl;
                    else
                        cout << "The element is " << *value << endl;
                }
                else if (type == 'c')
                {
                    char* value = cList->get(index);
                    if (value == nullptr)
                        cout << "There is no such an element" << endl;
                    else
                        cout << "The element is " << *value << endl;
                }
                break;
            }
            case 5:
            {
                if(type == 'i')
                {
                    int value;
                    int position;
                    cout << "Enter value to find" << endl;
                    cin >> value;
                    position = iList->getPosition(value);
                    if(position == -1)
                        cout << "There is no such an element" << endl;
                    else
                        cout << "The position of value is " << position << endl;
                }
                else if(type == 'c')
                {
                    char value;
                    int position;
                    cout << "Enter value to find" << endl;
                    cin >> value;
                    position = cList->getPosition(value);
                    if (position == -1)
                        cout << "There is no such an element" << endl;
                    else
                        cout << "The position of value is " << position << endl;
                }
                break;
            }
            case 6:
            {
                if(type == 'i')
                {
                    cout << "The list is:" << endl;
                    iList->print();
                    cout << endl;
                }
                else if(type == 'c')
                {
                    cout << "The list is:" << endl;
                    cList->print();
                    cout << endl;
                }
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
    return 0;
}
