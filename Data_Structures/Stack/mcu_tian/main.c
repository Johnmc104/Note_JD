#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
struct TreeNode
{
    int node_num;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode*  NodePtr;
typedef struct TreeNode Node;
*/

//数组实现栈
struct IntStack
{
  int capacity;
  int top;
  int *stackArray;
};

typedef struct IntStack *stack;

stack CreateStack(unsigned int stackNum)
{
    stack s;
    s = (stack)malloc(sizeof(struct IntStack));
    if(s == NULL)
    {
        printf("stack malloc failed\n");
        return NULL;
    }
    s->stackArray = (int*)malloc(stackNum*sizeof(int));
    if(s->stackArray == NULL )
    {
        printf("stack array failed\n");
        return NULL;
    }
    s->capacity = stackNum;
    s->top = -1;
    return  s;
}

void DisposeStack(stack *s)
{
    if(*s != NULL)
    {
        free((*s)->stackArray);
        free(*s);
        *s = NULL;
    }
}

int IsStackEmpty(stack s)
{
    return s->top == -1;
}

int ResetStack(stack s)
{
    if(s != NULL)
    {
        s->top = -1;
        return 1;
    }
    else
    {
        return -1;
    }
}

int IsStackFull(stack s)
{
    return s->top == s->capacity-1;
}

int StackPush(stack s,int *element)
{
    if(IsStackFull(s))
    {
        return -1; //can't push
    }
    else
    {
        ++s->top;
        s->stackArray[s->top] = *element;
        return 1; //ok
    }
}
int StackPop(stack s)
{
    if(IsStackEmpty(s)||(s == NULL))
    {
        return -1;
    }
    else
    {
        --s->top;
        return 1;//ok
    }
}
int StackTop(stack s,int *element)
{
     if(!IsStackEmpty(s))
     {
         *element = s->stackArray[s->top];
         return 1; //Ok
     }
     else
     {
         printf("Empty stack\n");
         return -1;
     }
}

void ArrayStackTest(void)//数组栈测试函数
{
    stack s;
    int i;
    int tmp;
    s = CreateStack(20);
    printf(" stack capacity:%d   top:%d\n",s->capacity,s->top);

    for(i = 0;i < 20;i++)
    {
        StackPush(s,&i);
    }

    while(!IsStackEmpty(s))
    {
        StackTop(s,&tmp);
        StackPop(s);
        printf("%d  ",tmp);
    }

    DisposeStack(&s);
    if(s == NULL)
    {
        printf("\nDispose stack successfully\n");
    }
}
//使用栈，中缀的表达式转换为后缀的表达式
void InfixToPosfixDemo(void)//中缀表达式到前缀表达式的转换
{
    stack  s;
    char expStr[100];
    int strLen;
    int i = 0;

   s = CreateStack(100);
   printf(" stack capacity:%d   top:%d\n",s->capacity,s->top);

   scanf("%s",expStr);
   strLen = strlen(expStr);

   while(strLen)
   {
       int stmp;
       stmp = expStr[i];
       switch ((char)stmp) {
       case '+':
            {
                while(!IsStackEmpty(s))//当低优先级的时候，将栈中的高于该优先级的操作符压栈
                {
                    int tmp;
                    StackTop(s,&tmp);
                    if((char)tmp!='(')
                    {
                        StackPop(s);
                        printf("%c",tmp);
                    }
                    else
                    {
                        break;
                    }
                }
                StackPush(s,&stmp);
            }

            break;

       case '*':
            {
                StackPush(s,&stmp);
            }
           break;

       case '(':
           {
                StackPush(s,&stmp);
           }
           break;

       case ')':
           {
                int tmp;
                StackTop(s,&tmp);
                while((char)tmp!='(')
                {
                    StackPop(s);
                    printf("%c",tmp);
                    StackTop(s,&tmp);
                }
                StackPop(s);
            }
           break;

       default:
           printf("%c",expStr[i]);
           break;
       }
       ++i;
       --strLen;
   }

   while(!IsStackEmpty(s))
   {
       int tmp;
       StackTop(s,&tmp);
       StackPop(s);
       printf("%c",tmp);
   }

   DisposeStack(&s);
   if(s == NULL)
   {

       printf("\nDispose stack successfully\n");
   }

}

//链表实现栈
struct StackIntNode //元素节点
{
    struct StackIntNode *pre;
    struct StackIntNode *next;
    int num;
};

typedef struct StackIntNode *StackNodePtr;
typedef struct StackIntNode StackNode;

struct ListIntStack//栈结构体
{
    StackNodePtr topPtr;
    StackNodePtr freeNodePtr;
    int lenght;
};
typedef struct ListIntStack *ListStack;

ListStack CreateListStack(int num) //创建链表栈
{
    StackNodePtr tmpPtr;
    ListStack s;
    s = (ListStack)malloc(sizeof(struct ListIntStack));
    if(s == NULL)
    {
        printf("creat list stact falied");
        return NULL;
    }
    s->topPtr = NULL;
    s->freeNodePtr = NULL;
    s->lenght = 0;
    /*
     不能用连续的数组快，否则到时候释放的时候会出问题
     也可以在结构体中加两个指针，一个专门用来管理初始化的指针指向的连续内存块
     一个用来后来分配的节点，这样在释放的时候才不会重复释放
    if(num > 0)//此处可以优化,可以根据num分配>num的空闲节点
    {
        int i;

        tmpPtr = (StackNodePtr)malloc(num*sizeof(StackNode));
        s->freeNodePtr = &tmpPtr[0];
        tmpPtr[0].pre = NULL;
        for(i = 0;i < num-1;++i)
        {
            tmpPtr[i].next = &tmpPtr[i+1];
            tmpPtr[i+1].pre = &tmpPtr[i];
            tmpPtr[i].num = i;
        }
        tmpPtr[num-1].next = NULL;
        tmpPtr[num-1].num = num-1;

    }
    */
    return s;
}

void DisposeListStack(ListStack *ls)
{
    StackNodePtr tmpPtr;
    int count_num = 0; //计算一共有多少个节点被释放

    tmpPtr = (*ls)->topPtr;
    while(tmpPtr != NULL)  //释放栈链表
    {
        (*ls)->topPtr = (*ls)->topPtr->pre;
        free(tmpPtr);
        tmpPtr = (*ls)->topPtr;
        ++count_num;
    }

    tmpPtr = (*ls)->freeNodePtr;//释放free链表
    while(tmpPtr != NULL)
    {
        (*ls)->freeNodePtr = (*ls)->freeNodePtr->next;

        free(tmpPtr);

        tmpPtr = (*ls)->freeNodePtr;
        ++count_num;
    }

    free(*ls);
    (*ls) = NULL;
    printf("dispose count_num is %d\n",count_num);
}

int IsListStackEmpty(ListStack ls)
{
     return ls->topPtr == NULL;
}

int ListStackPush(ListStack ls,int *element)//成功返回1，否则为-1,element 指向的为入栈的数据
{
    StackNodePtr tmp;
    if(ls->freeNodePtr != NULL)
    {
        tmp = ls->freeNodePtr;
        ls->freeNodePtr = ls->freeNodePtr->next;

        if(ls->freeNodePtr != NULL)
        {
            ls->freeNodePtr->pre = NULL;
        }
        tmp->num = *element;
        if(IsListStackEmpty(ls))
        {
            ls->topPtr = tmp;
            tmp->next = tmp->pre = NULL;
        }
        else
        {
            ls->topPtr->next = tmp;
            tmp->pre = ls->topPtr;
            ls->topPtr=ls->topPtr->next;
            tmp->next = NULL;
        }
    }
        else
        {

            tmp = malloc(sizeof(StackNode));
            if(tmp == NULL)
            {
                printf("malloc failed\n");
                return -1;
            }
            tmp->num = *element;
            if(ls->topPtr == NULL)
            {
                ls->topPtr = tmp;
                tmp->next = NULL;
                tmp->pre = NULL;
                return 1;
            }
            ls->topPtr->next = tmp;
            tmp->pre = ls->topPtr;
            tmp->next = NULL;

            ls->topPtr = ls->topPtr->next;

        }
    ++ls->lenght;
    return 1;
}
int ListstackPop(ListStack ls)
{
    StackNodePtr tmpPtr;
    if(IsListStackEmpty(ls))
    {
        printf("list stack pop failed\n");
        return -1;
    }

    tmpPtr = ls->topPtr;
    ls->topPtr = ls->topPtr->pre;

    if(ls->topPtr != NULL)
    {
        ls->topPtr->next = NULL;
    }

    tmpPtr->pre = NULL;
    if(ls->freeNodePtr == NULL)
    {
        ls->freeNodePtr = tmpPtr;
    }
    else
    {
        ls->freeNodePtr->pre = tmpPtr;
        tmpPtr->next = ls->freeNodePtr;
        ls->freeNodePtr = ls->freeNodePtr->pre;
    }
      --ls->lenght;
    return 1;
}

int ListStackReset(ListStack ls)
{
    while(!IsListStackEmpty(ls))
    {
        if(ListstackPop(ls) != 1)
        {
            return -1;
        }
    }
    return 1;
}

int ListStackTop(ListStack ls,int *element)
{
    if(IsListStackEmpty(ls))
    {
        printf("Top is NULL\n");
        return -1;
    }
    *element = ls->topPtr->num;
    return 1;
}

void ListStackTest(void)  //链表栈测试函数
{
    ListStack ls;
    int i = 0;
    int tmp;
    ls = CreateListStack(0);
    ListstackPop(ls); //弹出空栈
    if(IsListStackEmpty(ls))
    {
        printf("stack is empty\n");
    }
    for(i = 0;i < 10;++i) //压栈
    {
        ListStackPush(ls,&i);
    }
    if(ls->freeNodePtr == NULL)  //判断是否有free node
    {
        printf("no free node\n");
    }
    for(i = 0;i < 5;++i)//弹出
    {
        ListstackPop(ls);
    }
    if(ls->freeNodePtr != NULL)  //判断是否有free node
    {
        printf("some free node\n");
    }
    for(i = 0;i < 5;++i)//弹出
    {
        ListstackPop(ls);
    }
    if(IsListStackEmpty(ls))
    {
        printf("stack is empty\n");

        ListStackTop(ls,&tmp);//读取栈顶元素
        printf("%d\n",tmp);
        ListStackReset(ls);//重置栈
        ListStackTop(ls,&tmp);//读取栈顶元素
        DisposeListStack(&ls);//释放栈

        if(ls == NULL)
        {
            printf("list stack is free\n");
        }
    }
 }

int main(void)
{
    //ArrayStackTest();
    //InfixToPosfixDemo();
    ListStackTest();
    return 0;
}
