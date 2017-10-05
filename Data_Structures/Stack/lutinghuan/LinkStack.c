#include <stdio.h>
#include <malloc.h>
#include "LinkStack.h"

#define NULL ((void *)0)

PLinkStack createEmptyStack(void)
{
    PLinkStack stack=(PLinkStack)malloc(sizeof(struct LinkStack));
    if (stack == NULL)
        printf("存储分配失败，请重新建栈！\n");
    else
        stack ->top = NULL;
    return stack;
}

int isEmptyStack(PLinkStack stack)
{
    return (stack -> top == NULL);
}

int push(PLinkStack stack, DataType x)
{
    PNode p =(PNode)malloc(sizeof(struct Node));
    if(p == NULL)
    {
        printf("新结点分配内存失败，进栈失败，请重试！\n");
        return 0;
    }
    else
    {
        p -> info = x;
        p -> link = stack -> top;
        stack -> top = p;
        return 1;
    }
}

int pop(PLinkStack stack)
{
    if(isEmptyStack(stack))
    {
        printf("栈为空！\n");
        return 0;
    }
    else
    {
        PNode p;
        p=stack -> top;
        stack -> top = stack -> top -> link;
        free(p);
        return 1;
    }
}

DataType getTop(PLinkStack stack)
{
    if(isEmptyStack(stack))
    {
        printf("栈为空！取栈顶元素失败！\n");
        return NULL;//NULL

    }
    return (stack -> top -> info);
}

void showStack(PLinkStack stack)
{
    if(isEmptyStack(stack))
        printf("当前栈为空！无内容可显示。\n");
    else
    {
        PNode p;
        p=stack -> top;
        printf("顶-->");
        while(p -> link !=NULL)
        {
            printf("%d ",p -> info);
            p=p -> link;
        }
        printf("%d ",p -> info);
        printf("-->底\n");
    }
}


void setEmpty(PLinkStack stack)
{
    stack -> top = NULL;
}

void destroyStack(PLinkStack stack)
{
    if(stack)
    {
        stack -> top = NULL;
        free(stack);
    }
}
