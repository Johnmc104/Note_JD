#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "LinkStack.h"

int main()
{
    char input;
    DataType data;
    PLinkStack stack;
    do
    {
        printf("---------------------------------------------\n");
        printf("---------------------------------------------\n");
        printf("----       输入对应字符执行以下操作      ----\n");
        printf("----                                     ----\n");
        printf("----         \"0\"：创建一个空栈           ----\n");
        printf("----         \"1\"：检查栈是否为空         ----\n");
        printf("----         \"3\"：执行入栈操作           ----\n");
        printf("----         \"4\"：执行出栈操作           ----\n");
        printf("----         \"5\"：打印栈顶元素           ----\n");
        printf("----         \"6\"：打印栈内所有元素       ----\n");
        printf("----         \"7\"：把栈清空               ----\n");
        printf("----         \"8\"：把栈销毁               ----\n");
        printf("----         \"q\"：退出程序               ----\n");
        printf("---------------------------------------------\n");
        printf("---------------------------------------------\n");
        printf("选择操作:");
        scanf("%c",&input);

        switch(input)
        {
            case '0':
                stack=createEmptyStack();
                printf("成功创建链表栈。\n");
                break;

            case '1':
                if(isEmptyStack(stack))
                    printf("该栈当前为空栈！\n");
                else
                    printf("该栈当前为非空栈！\n");
                break;

            case '3':
                fflush(stdin);
                printf("请输入要入栈的值：");
                scanf("%d",&data);
                if(push(stack,data))
                {
                    printf("入栈成功，栈当前内容:");
                    showStack(stack);
                }
                else
                {
                    printf("入栈失败，请检查！\n");
                }
                break;

            case '4':
                if(pop(stack))
                {
                    printf("出栈成功，栈当前内容为：");
                    showStack(stack);
                }
                else
                {
                    printf("出栈失败，请检查！\n");
                }
                break;

            case '5':
                data=getTop(stack);
                printf("栈顶值为：%d\n",data);
                break;

            case '6':
                printf("栈当前内容：");
                showStack(stack);
                break;

            case '7':
                setEmpty(stack);
                printf("栈当前内容：");
                showStack(stack);
                break;

            case '8':
                destroyStack(stack);
                printf("成功将栈销毁！\n");
                break;

            defauly:
                break;
        }
        printf("\n");
        fflush(stdin);
    }
    while(input!='q');
    return 0;
}
