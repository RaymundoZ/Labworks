#include "date.h"

bool operator==(Date a, Date b)
{
    return a.day == b.day && a.month == b.month && a.year == b.year;
}

std::string getChar(std::string str, int pos)
{
    return std::to_string(str[pos] - '0');
}

Date initDate(std::string str)
{
    // Создание переменных для инициализации Date
    int num = str[0] - '0';
    
    int day = stoi(getChar(str, 2) + getChar(str, 3));
    int month = stoi(getChar(str, 5) + getChar(str, 6));
    int year = stoi(getChar(str, 8) + getChar(str, 9) + getChar(str, 10) + getChar(str, 11));

    // Создание и инициализация Date
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

Date initDate(int day, int month, int year)
{
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

void printDate(Date date)
{
    std::cout << date.day << "." << date.month << "." << date.year << " ";
}
