/* 
========================== 
 功能：插入有序链表的某个节点的后面(从小到大) 
 返回：指向链表表头的指针 
========================== 
*/  
  
struct student *SortInsert (struct student *head, struct student *node)  
{  
    struct student *p;      //p保存当前需要检查的节点的地址  
    struct student *t;      //临时指针变量  
  
    if (head == NULL)       //处理空的有序链表  
    {  
        head = node;  
        node->next = NULL;  
        n += 1;         //插入完毕，节点总数加  
        return head;  
    }  
  
    p = head;             //有序链表不为空  
    while(p->num < node->num && p != NULL)    //p指向的节点的学号比插入节点的学号小，并且它不等于NULL  
    {  
        t = p;            //保存当前节点的前驱，以便后面判断后处理  
        p = p->next;     //后移一个节点  
    }  
  
    if (p == head)      //刚好插入第一个节点之前  
    {  
        node->next = p;  
        head = node;  
    }  
    else                 //插入其它节点之后  
    {  
        t->next = node;      //把node节点加进去  
        node->next = p;  
    }  
    n += 1;         //插入完毕，节点总数加1  
  
    return head;  
}  
