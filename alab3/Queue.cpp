#include "Queue.h"

Queue::Queue()
{
    front = rear = nullptr;
}

Queue::~Queue()
{
    while (!isEmpty())
        dequeue();
}

bool Queue::isEmpty()
{
    return front == nullptr;
}

void Queue::enqueue(char val)
{
    TQueue p = new Node;
    p->data = val;
    p->next = nullptr;
    if (!isEmpty())
    {
        rear->next = p;
        rear = p;
    }
    else
        front = rear = p;
}

void Queue::dequeue()
{
    if (!isEmpty())
    {
        TQueue p = front;
        front = front->next;
        delete p;
        p = nullptr;
    }
}

char Queue::getFront()
{
    return front->data;
}