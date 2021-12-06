#pragma once
#include <iostream>
#include <fstream>
#include "date.h"
#include "account.h"
#include "type.h"

struct List {
    Account data;
    List *next;
};

typedef List *TList;

void init(TList &);
void printList(TList);
void clear(TList &);

bool isEmpty(TList);

void addToHead(TList &, Account);

void deleteFromHead(TList &);

void greateByOrder(TList&, std::string);

TList findPlace(TList, Account);