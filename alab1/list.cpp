#include "list.h"
#include <iostream>

void init(TList &head)
{
    head = nullptr;
}

void print(TList head)
{
    TList list = head;
    while (list != nullptr)
    {
        char startColumn = list->data->startColumn;
        char endColumn = list->data->endColumn;
        int startLine = list->data->startLine;
        int endLine = list->data->endLine;
        if(endLine != (int)'z' && endColumn != 'z')
        {
            std::cout << startColumn << startLine << "..." << endColumn << endLine << " -> ";
        }
        else
            std::cout << startColumn << startLine << " -> ";
        list = list->next;
    }
    std::cout << "\n\n";
}

void clear(TList &head)
{
    while (!isEmpty(head))
    {
        deleteFromHead(head);
    }
}

bool isEmpty(TList head)
{
    return head == nullptr;
}

void addToHead(TList &head, Ship value)
{
    TList list = new Node;
    list->data = value;
    list->next = head;
    head = list;
}

void deleteFromHead(TList &head)
{
    TList list = head;
    head = head->next;
    list->next = nullptr;
    delete list;
    list = nullptr;
}
