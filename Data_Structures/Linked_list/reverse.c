/* 
========================== 
 功能：反序节点 
  (链表的头变成链表的尾，链表的尾变成头) 
 返回：指向链表表头的指针 
========================== 
*/  
  
struct student *Reverse (struct student *head)  
{  
    struct student *p;      //临时存储  
    struct student *p1;     //存储返回结果  
    struct student *p2;     //源结果节点一个一个取  
  
    p1 = NULL;          //开始颠倒时，已颠倒的部分为空  
    p2 = head;          //p2指向链表的头节点  
    while(p2 != NULL)  
    {  
        p = p2->next;  
        p2->next = p1;  
        p1 = p2;  
        p2 = p;  
    }  
    head = p1;  
    return head;  
}  
