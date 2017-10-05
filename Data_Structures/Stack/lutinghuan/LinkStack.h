#include <stdio.h>

typedef int DataType;

struct Node;
typedef struct Node *PNode;

typedef struct Node
{
    DataType info;
    PNode link;
}Node;

typedef struct LinkStack
{
    PNode top;
}LinkStack;

typedef struct LinkStack * PLinkStack;

PLinkStack createEmptyStack(void);

int push (PLinkStack stack,DataType x);

int pop (PLinkStack stack);

DataType getTop(PLinkStack stack);

void showStack(PLinkStack stack);

void setEmpty(PLinkStack stack);

void destroyStack(PLinkStack stack);
