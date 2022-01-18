#include "SelfOrganizingList.h"

template <typename T>
SelfOrganizingList<T>::SelfOrganizingList()
{
    head = nullptr;
}

template <typename T>
SelfOrganizingList<T>::~SelfOrganizingList()
{
    clear();
}

template <typename T>
void SelfOrganizingList<T>::moveToHead(Node<T>* node)
{
    if (node->next)
    {
        Node<T>* p = node->next;
        node->next = p->next;
        p->next = head;
        head = p;
    }
}

template <typename T>
void SelfOrganizingList<T>::deleteFromHead()
{
    if (head)
    {
        Node<T>* p = head;
        head = head->next;
        delete p;
        p = nullptr;
    }
}

template <typename T>
void SelfOrganizingList<T>::deleteAfterNode(Node<T>* node)
{
    if (node->next)
    {
        Node<T>* p = node->next;
        node->next = p->next;
        delete p;
        p = nullptr;
    }
}

template <typename T>
bool SelfOrganizingList<T>::isEmpty()
{
    return head == nullptr;
}

template <typename T>
void SelfOrganizingList<T>::add(T val)
{
    Node<T>* p = new Node<T>;
    p->data = val;
    p->next = head;
    head = p;
}

template <typename T>
void SelfOrganizingList<T>::remove(int index)
{
    Node<T>* tmp = head;
    if(index == 0)
        deleteFromHead();
    else
    {
        for(int i = 0; i < index - 1 && tmp->next; i++)
            tmp = tmp->next;
        deleteAfterNode(tmp);
    }
}

template <typename T>
T* SelfOrganizingList<T>::get(int index)
{
    Node<T>* tmp = head;
    for(int i = 0; i < index; i++)
    {
        if(!tmp)
            return nullptr;
        tmp = tmp->next;
    }
    return &(tmp->data);
}

template <typename T>
int SelfOrganizingList<T>::getPosition(T val)
{
    if (head)
    {
        if (head->data == val)
            return 0;
        int counter = 1;
        Node<T>* tmp = head;
        while (tmp && tmp->next)
        {
            if (tmp->next->data == val)
            {
                moveToHead(tmp);
                return counter;
            }
            counter++;
            tmp = tmp->next;
        }
    }
    return -1;
}

template <typename T>
void SelfOrganizingList<T>::print()
{
    Node<T>* tmp = head;
    while(tmp)
    {
        cout << tmp->data << ", ";
        tmp = tmp->next;
    }
}

template <typename T>
void SelfOrganizingList<T>::clear()
{
    while (head)
    {
        deleteFromHead();
    }
}