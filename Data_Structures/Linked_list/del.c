/* 
========================== 
 功能：删除指定节点 
  (此例中是删除指定学号的节点) 
 返回：指向链表表头的指针 
========================== 
*/ 

struct student *Del (struct student *head, int num)  
{  
    struct student *p1;     //p1保存当前需要检查的节点的地址  
    struct student *p2;     //p2保存当前检查过的节点的地址  
    if (head == NULL)       //是空链表（结合图3理解）  
    {  
        printf ("\nList is null!\n");  
        return head;  
    }  
  
    //定位要删除的节点  
    p1 = head;  
    while (p1->num != num && p1->next != NULL)
    //p1指向的节点不是所要查找的，并且它不是最后一个节点，就继续往下找  
    {  
        p2 = p1;            //保存当前节点的地址  
        p1 = p1->next;      //后移一个节点  
    }  
  
    if(p1->num==num)        //找到了。（结合图4、5理解）  
    {  
        if (p1 == head)     //如果要删除的节点是第一个节点  
        {  
            head = p1->next; //头指针指向第一个节点的后一个节点，也就是第二个节点。这样第一个节点就不在链表中，即删除  
        }  
        else            //如果是其它节点，则让原来指向当前节点的指针，指向它的下一个节点，完成删除  
        {  
            p2->next = p1->next;  
        }  
  
        free (p1);      //释放当前节点  
        p1 = NULL;  
        printf ("\ndelete %ld success!\n", num);  
        n -= 1;         //节点总数减1个  
    }  
    else                //没有找到  
    {  
        printf ("\n%ld not been found!\n", num);  
    }  
  
    return head;  
}  
