/* 
=========================== 
 功能：输出节点 
 返回： void 
=========================== 
*/  
void Print(struct student *head)  
{  
    struct student *p;  
    printf ("\nNow , These %d records are:\n", n);  
    p = head;  
    if(head != NULL)        //只要不是空链表，就输出链表中所有节点  
    {  
        printf("head is %o\n", head);    //输出头指针指向的地址  
        do  
        {  
            /* 
            输出相应的值：当前节点地址、各字段值、当前节点的下一节点地址。 
            这样输出便于读者形象看到一个单向链表在计算机中的存储结构，和我们 
            设计的图示是一模一样的。 
            */  
            printf ("%o   %d   %5.1f   %o\n", p, p->num, p->score, p->next);  
            p = p->next;     //移到下一个节点  
        }  
        while (p != NULL);  
    }  
}  
