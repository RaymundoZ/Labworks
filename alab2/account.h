#pragma once
#include "date.h"
#include "type.h"
#include <iostream>

struct Account
{
    int num;
    Date date;
    std::string clientName;
    Type type;
    int sum;
};

bool operator<(Account, Account);

Account initAccount(std::string);

void printAccount(Account);
