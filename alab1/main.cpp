#include <iostream>
#include <fstream>
#include <math.h>
#include "list.h"
using namespace std;

void fillList(TList &head, int lineNumber) 
{
    ifstream stream("C:\\Vscode projects\\labs\\file.txt");
    string line;
    for(int i = 0; i < lineNumber; i++)
        getline(stream, line);
    for(int i = 0; i < line.length(); i += 3)
    {
        TList list = head;
        bool checker = true;
        while(list != nullptr)
        {
            if (list->data->endColumn == 'z' && list->data->endLine == (int)'z')
            {
                if ((line[i] - list->data->startColumn == 1 && line[i + 1] - '0' == list->data->startLine) || (line[i + 1] - '0' - list->data->startLine == 1 && line[i] == list->data->startColumn))
                {
                    list->data->endColumn = line[i];
                    list->data->endLine = line[i + 1] - '0';
                    checker = false;
                }
            } 
            else
            {
                if ((line[i] - list->data->endColumn == 1 && line[i + 1] - '0' == list->data->endLine) || (line[i + 1] - '0' - list->data->endLine == 1 && line[i] == list->data->endColumn))
                {
                    list->data->endColumn = line[i];
                    list->data->endLine = line[i + 1] - '0';
                    checker = false;
                }
            }
            
            list = list->next;
        }
        if(checker)
        {
            Ship ship = new Data;
            ship->startColumn = line[i];
            ship->endColumn = 'z';
            ship->startLine = line[i + 1] - '0';
            ship->endLine = (int)'z';
            addToHead(head, ship);
        }
    }
    stream.close();
}

bool isCoordInSequence(char column, int line, char startColumn, char endColumn, int startLine, int endLine)
{
    if(startColumn == endColumn || endColumn == 'z')
    {
        if(endColumn == 'z' && column == startColumn) return true;
        if(column != startColumn) return false;
        for(int i = startLine; i <= endLine; i++)
            if(line == i) return true;
    }
    else if(startLine == endLine || endLine == (int)'z')
    {
        if(endLine == (int)'z' && line == startLine) return true;
        if(line != startLine) return false;
        for(char i = startColumn; i <= endColumn; i++)
            if(column == i) return true;
    }
    return false;
}

void shoot(TList &head, char column, int line)
{
    TList result = new Node;
    init(result);
    TList list = head;
    while(list != nullptr)
    {
        if(!isCoordInSequence(column, line, list->data->startColumn, list->data->endColumn, list->data->startLine, list->data->endLine))
            addToHead(result, list->data);
        list = list->next;
    }
    head = result;
}

int main()
{
    TList headOne = new Node;
    TList headTwo = new Node;
    init(headOne);
    init(headTwo);
    fillList(headOne, 1);
    fillList(headTwo, 2);
    cout << "Player one ships:\n" << endl;
    print(headOne);
    cout << "Player two ships:\n" << endl;
    print(headTwo);
    while(true)
    {
        if(isEmpty(headOne))
        {
            cout << "Player two wins\n" << endl;
            break;
        }
        if (isEmpty(headTwo))
        {
            cout << "Player one wins\n" << endl;
            break;
        }
        cout << "Player one turn: choose coordinate\n" << endl;
        string coordinate;
        getline(cin, coordinate);
        shoot(headTwo, coordinate[0], coordinate[1] - '0');
        cout << "\nPlayer two ships:\n" << endl;
        print(headTwo);
        cout << "Player two turn: choose coordinate\n" << endl;
        getline(cin, coordinate);
        shoot(headOne, coordinate[0], coordinate[1] - '0');
        cout << "\nPlayer one ships:\n" << endl;
        print(headOne);
    }
    clear(headOne);
    clear(headTwo);
    system("pause");
    return 0;
}