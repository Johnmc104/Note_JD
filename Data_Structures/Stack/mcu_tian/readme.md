From:http://blog.csdn.net/mcu_tian/article/details/51493081

要点提示：
    链表栈
    
    通过实现一个空闲节点链表，将pop之后的链表节点不释放，而是放入空闲链表freeNodePtr中
    当栈进行push操作的时候，先从空闲节点链表中中取出空闲节点加入栈链表中，若是空闲链表中，没有节点，则调用malloc，申请内存节点。
    栈是否空栈只要判断指向栈顶指针是否为空。

    实现的操作有pop、push、reset、isempty、create、dispose等基本函数，实现了链表节点 stacknode，以及栈的结构体ListIntStack等。

