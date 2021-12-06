#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include "list.h"
using namespace std;

void fillList(TList &head)
{
    greateByOrder(head, "C:\\Vscode projects\\labs\\alab2\\file.txt");
}

void findBalance(TList head)
{
    // Получение даты
    int day;
    int month;
    int year;
    cout << "Enter the day" << endl;
    cin >> day;
    cout << "Enter the month" << endl;
    cin >> month;
    cout << "Enter the year" << endl;
    cin >> year;

    Date date = initDate(day, month, year);

    int income = 0;
    int outcome = 0;

    // Поиск Account с подходящей датой
    while(head != nullptr)
    {
        if(head->data.date == date)
        {
            if(head->data.type == Type::INCOME)
                income += head->data.sum;
            else
                outcome += head->data.sum;
        }
        head = head->next;
    }

    cout << "The balance is: " << abs(income - outcome) << endl;
}

int main()
{
    TList list = new List;
    init(list);
    fillList(list);
    findBalance(list);
    printList(list);
    system("pause");
    return 0;
}