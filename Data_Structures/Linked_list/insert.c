/* 
========================== 
 功能：插入指定节点的后面 
  (此例中是指定学号的节点) 
 返回：指向链表表头的指针 
========================== 
*/  
struct student *Insert (struct student *head, int num, struct student *node)  
{  
    struct student *p1;     //p1保存当前需要检查的节点的地址  
    if (head == NULL)       //（结合图示7理解）  
    {  
        head = node;  
        node->next = NULL;  
        n += 1;  
        return head;  
    }  
  
    p1 = head;  
    while(p1->num != num && p1->next != NULL)
   //p1指向的节点不是所要查找的，并且它不是最后一个节点，继续往下找  
    {  
        p1 = p1->next;       //后移一个节点  
    }  
  
    if (p1->num==num)        //找到了（结合图示8理解）  
    {  
        node->next = p1->next;	//显然node的下一节点是原p1的next  
        p1->next = node;	//插入后，原p1的下一节点就是要插入的node  
        n += 1;			//节点总数增加1个  
    }  
    else  
    {  
        printf ("\n%ld not been found!\n", num);  
    }  
    return head;  
}  
