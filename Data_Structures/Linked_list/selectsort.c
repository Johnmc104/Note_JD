/* 
========================== 
 功能：选择排序(由小到大) 
 返回：指向链表表头的指针 
========================== 
*/  
struct student *SelectSort (struct student *head)  
{  
    struct student *first;     //排列后有序链的表头指针  
    struct student *tail;      //排列后有序链的表尾指针  
    struct student *p_min;     //保留键值更小的节点的前驱节点的指针  
    struct student *min;       //存储最小节点  
    struct student *p;         //当前比较的节点  
  
    first = NULL;  
    while(head != NULL)       //在链表中找键值最小的节点  
    {  
        //注意：这里for语句就是体现选择排序思想的地方  
        for (p = head, min = head; p->next != NULL; p = p->next)  //循环遍历链表中的节点，找出此时最小的节点  
        {  
            if (p->next->num < min->num)     //找到一个比当前min小的节点  
            {  
                p_min = p;        //保存找到节点的前驱节点：显然p->next的前驱节点是p  
                min = p->next;     //保存键值更小的节点  
            }  
        }  
  
        //上面for语句结束后，就要做两件事；一是把它放入有序链表中；二是根据相应的条件判断，安排它离开原来的链表  
  
        //第一件事  
        if (first == NULL)     //如果有序链表目前还是一个空链表  
        {  
            first = min;        //第一次找到键值最小的节点  
            tail = min;        //注意：尾指针让它指向最后的一个节点  
        }  
        else              //有序链表中已经有节点  
        {  
            tail->next = min;    //把刚找到的最小节点放到最后，即让尾指针的next指向它  
            tail = min;           //尾指针也要指向它  
        }  
  
        //第二件事  
        if (min == head)            //如果找到的最小节点就是第一个节点  
        {  
            head = head->next;      //显然让head指向原head->next,即第二个节点，就OK  
        }  
        else            //如果不是第一个节点  
        {  
            p_min->next = min->next;  //前次最小节点的next指向当前min的next,这样就让min离开了原链表  
        }  
    }  
  
    if (first != NULL)      //循环结束得到有序链表first  
    {  
        tail->next = NULL;   //单向链表的最后一个节点的next应该指向NULL  
    }  
    head = first;  
    return head;  
}  
