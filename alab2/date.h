#pragma once
#include <string>
#include <iostream>

struct Date
{
    int day;
    int month;
    int year;
};

bool operator==(Date, Date);

Date initDate(std::string);

Date initDate(int day, int month, int year);

void printDate(Date);
