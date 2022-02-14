#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    string str;
    cout << "Enter a string" << endl;
    getline(cin, str);
    Queue* vowels = new Queue();
    Queue* consonants = new Queue();
    for(char c: str)
    {
        if(c % 2 == 0)
            consonants->enqueue(c);
        else
            vowels->enqueue(c);
    }
    while(true)
    {
        if(!vowels->isEmpty())
        {
            cout << vowels->getFront();
            vowels->dequeue();
        }
        if(!consonants->isEmpty())
        {
            cout << consonants->getFront();
            consonants->dequeue();
        }
        if(vowels->isEmpty() && consonants->isEmpty())
            break;
    }
    delete vowels;
    delete consonants;
    system("pause");
    return 0;
}