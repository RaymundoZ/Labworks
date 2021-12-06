struct Data
{
    char startColumn;
    int startLine;
    char endColumn;
    int endLine;
};

struct Node
{
    Data *data;
    Node *next;
};

typedef Node *TList;
typedef Data *Ship;

void init(TList &);
void print(TList);
void clear(TList &);

bool isEmpty(TList);

void addToHead(TList &, Ship);
void addAfterNode(TList, Ship);

void deleteFromHead(TList &);
void deleteAfterNode(TList);