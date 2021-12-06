#include "account.h"

bool operator<(Account a, Account b)
{
    int firstDays = a.date.year * 365 + a.date.month * 30 + a.date.day;
    int secondDays = b.date.year * 365 + b.date.month * 30 + b.date.day;
    return firstDays < secondDays;
}

void fillName(std::string &name, std::string line, int &i)
{
    for (; i < line.length(); i++)
    {
        if (line[i] == ' ')
            break;
        name.push_back(line[i]);
    }
}

void fillType(Type &type, std::string line, int &i)
{
    i++;
    if (line.substr(i, 7) == "income ")
        type = Type::INCOME;
    else if (line.substr(i, 7) == "outcome")
        type = Type::OUTCOME;
}

void fillSum(int &sum, std::string line, int i)
{
    std::string strSum = "";
    for (int j = i + 7; j < line.length(); j++)
        strSum.push_back(line[j]);
    sum = stoi(strSum);
}

Account initAccount(std::string str)
{
    // Создание переменных для инициализации Account
    int num = str[0] - '0';
    
    std::string name = "";
    int i = 13;
    fillName(name, str, i);

    Type type;
    fillType(type, str, i);

    int sum = 0;
    fillSum(sum, str, i);

    // Создание и инициализация Date
    Date date = initDate(str);

    // Создание и инициализация Account
    Account account;
    account.num = num;
    account.clientName = name;
    account.type = type;
    account.sum = sum;
    account.date = date;
    return account;
}

void printAccount(Account acc)
{
    std::cout << acc.num << " ";
    printDate(acc.date);
    std::cout << acc.clientName << " ";
    printType(acc.type);
    std::cout << acc.sum << std::endl;
}