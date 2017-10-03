/* 
========================== 
 功能：直接插入排序(由小到大) 
 返回：指向链表表头的指针 
========================== 
*/  
struct student *InsertSort (struct student *head)  
{  
    struct student *first;    //为原链表剩下用于直接插入排序的节点头指针  
    struct student *t;        //临时指针变量：插入节点  
    struct student *p,*q;     //临时指针变量  
  
    first = head->next;      //原链表剩下用于直接插入排序的节点链表：可根据图12来理解  
    head->next = NULL;       //只含有一个节点的链表的有序链表：可根据图11来理解  
  
    while(first != NULL)        //遍历剩下无序的链表  
    {  
        //注意：这里for语句就是体现直接插入排序思想的地方  
        for (t = first, q = head; ((q != NULL) && (q->num < t->num)); p = q, q = q->next);  //无序节点在有序链表中找插入的位置  
  
        //退出for循环，就是找到了插入的位置，应该将t节点插入到p节点之后，q节点之前  
        //注意：按道理来说，这句话可以放到下面注释了的那个位置也应该对的，但是就是不能。原因：你若理解了上面的第3条，就知道了  
        //下面的插入就是将t节点即是first节点插入到p节点之后，已经改变了first节点，所以first节点应该在被修改之前往后移动，不能放到下面注释的位置上去  
        first = first->next; //无序链表中的节点离开，以便它插入到有序链表中  
  
        if (q == head)      //插在第一个节点之前  
        {  
            head = t;  
        }  
        else            //p是q的前驱  
        {  
            p->next = t;  
        }  
        t->next = q;     //完成插入动作  
        //first = first->next;   
    }  
    return head;  
}  
