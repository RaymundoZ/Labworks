#include "Node.h"

class Queue
{
    private:
    TQueue front;
    TQueue rear;

    public:
    Queue();

    ~Queue();

    bool isEmpty();

    void enqueue(char val);

    void dequeue();

    char getFront();
};