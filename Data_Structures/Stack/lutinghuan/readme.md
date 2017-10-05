From:http://blog.csdn.net/lutinghuan/article/details/7475026

要点：
    链表栈

-------------------------------
   LinkSatck.c 中还有问题
-------------------------------
    对于
    return NULL;
    
    报：
    warning: return makes integer from pointer without a cast [-Wint-conversion]

    ------------------------------------
    
    按检索到的资料，开头定义空指针
    #define NULL ((void *)0)

    报：
    LinkStack.c:5:14: warning: return makes integer from pointer without a cast [-Wint-conversion]
     #define NULL ((void *)0)
                   ^
    LinkStack.c:61:16: note: in expansion of macro 'NULL'
     return NULL;//NULL

    ------------------------------------

    若改为：
    #define NULL 0

    .\LinkStack.c:6:0: warning: "NULL" redefined
     #define NULL 0

     In file included from c:\mingw\include\stdlib.h:55:0,
                      from c:\mingw\include\malloc.h:20,
                      from .\LinkStack.c:2:
    c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h:406:0: note: this is the location of the previous definition
     #define NULL ((void *)0)

-------------------------------
   main.c 中也有问题
-------------------------------

    .\main.c: In function 'main':
    .\main.c:38:20: warning: implicit declaration of function 'isEmptyStack' [-Wimplicit-function-declaration]
    if(isEmptyStack(stack))

    应该是LinkStack.c里NULL问题引起的

-------------------------------
    不过按道理，NULL定义，在stdio.h里有啊
    才疏学浅，暂时没辙，滚去啃基础了。
