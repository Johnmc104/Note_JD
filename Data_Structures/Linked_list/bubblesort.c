/* 
========================== 
 功能：冒泡排序(由小到大) 
 返回：指向链表表头的指针 
========================== 
*/  
struct student *BubbleSort (struct student *head)  
{  
    struct student *endpt;    //控制循环比较  
    struct student *p;        //临时指针变量  
    struct student *p1,*p2;  
  
    p1 = (struct student *) malloc (LEN);  
    p1->next = head;        
    //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址  
    head = p1;                 
    //让head指向p1节点，排序完成后，我们再把p1节点释放掉  
  
    for (endpt = NULL; endpt != head; endpt = p)    //结合第6点理解  
    {  
        for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)  
        {  
            if (p1->next->num > p1->next->next->num)  
	    //如果前面的节点键值比后面节点的键值大，则交换  
            {  
                p2 = p1->next->next;   //结合第1点理解  
                p1->next->next = p2->next;   //结合第2点理解  
                p2->next = p1->next;   //结合第3点理解  
                p1->next = p2;         //结合第4点理解  
                p = p1->next->next;    //结合第6点理解  
            }  
        }  
    }  
  
    p1 = head;         //把p1的信息去掉  
    head = head->next; //让head指向排序后的第一个节点  
    free (p1);         //释放p1  
    p1 = NULL;         //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量  
  
    return head;  
}  
