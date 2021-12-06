#include "list.h"

void init(TList &head)
{
    head = nullptr;
}

void printList(TList head)
{
    TList list = head;
    while (list != nullptr)
    {
        printAccount(list->data);
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

void addToHead(TList &head, Account data)
{
    TList list = new List;
    list->data = data;
    list->next = head;
    head = list;
}

void addAfterNode(TList node, Account data)
{
    TList p = new List;
    p->data = std::move(data);
    p->next = node->next;
    node->next = p;
}

void deleteFromHead(TList &head)
{
    TList list = head;
    head = head->next;
    list->next = nullptr;
    delete list;
    list = nullptr;
}

void greateByOrder(TList &head, std::string filePath)
{
    init(head);
    std::ifstream input(filePath);
    std::string tmp;
    Account account;
    while (!input.eof())
    {
        getline(input, tmp);
        account = initAccount(tmp);
        if (isEmpty(head) || (account < head->data))
        {
            addToHead(head, account);
        }
        else
        {
            TList p = findPlace(head, account);
            addAfterNode(p, account);
        }
    }
    input.close();
}

TList findPlace(TList head, Account account)
{
    TList p = head;
    while (p->next != nullptr && (p->next->data < account))
        p = p->next;
    return p;
}