#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; //数据域
    struct Node *next; //指针域
};

/*
Create
*函数功能：创建链表.
*输入：各节点的data
*返回值：指针head
*/
Node *Create () {
    Node *p, *pl, * head;  
    head = p = (Node *)malloc(sizeof(Node));  
    scanf("%d", &p->data);/*头结点的数据成员*/  
    /*给出0结束条件,退出循环*/  
    while(p->data != 0) {    
        pl = p;  
        p = (Node *)malloc(sizeof(Node));  
        scanf("%d", &p->data);/*中间结点数据成员*/  
        pl->next = p;/*中间结点的指针成员值*/  
    }  
    p-> next = NULL;/*尾结点的指针成员值*/  
    return head;
}

/*
insert
*函数功能：在链表中插入元素.
*输入：head链表头指针，p新元素插入位置，x新元素中的数据域内容
*返回值：无
*/
void insert (Node *head, int p, int x) {
    Node *tmp = head; 
    //for循环是为了防止插入位置超出了特定长度
    for (int i = 0; i < p; i++) {
        if (tmp == NULL) {
            return ;
        } 
        if (i < p - 1) {
            tmp = tmp->next;
        }
    }
    Node *tmp2;
    tmp2 = (Node *)malloc(sizeof(Node));
    tmp2->data = x;
    tmp2->next = tmp->next;
    tmp->next = tmp2;
}

/*
del
*函数功能：删除链表中的元素
*输入：head链表头指针，p被删除元素位置
*返回值：被删除元素中的数据域.如果删除失败返回-1
*/
int del (Node *head, int p) {
    Node *s;
    Node *tmp = head;
    for (int i = 0; i < p; i++) {
        if (tmp == NULL)
            return -1; //p so far
        if (i < p - 1) {
            tmp = tmp->next;
        }
    }
    int ret = tmp->next->data; //储存被删除元素的值
    s = tmp->next;
    tmp->next = tmp->next->next;
    free(s);
    return ret;
}

/*
print
*函数功能：打印
*输入：head链表头指针
*返回值：无
*/
void print (Node *head) { 
    while (head->next != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//链表倒置
Node *reverse(Node *head) {
    int flag = 0;
    Node* pReversedHead = NULL;
    Node* pNode = head;
    Node* pPrev = NULL;
    Node* pNext = NULL;
    while(pNode != NULL)
    {
        pNext = pNode->next;
        if(pNext == NULL)
            pReversedHead = pNode;

        pNode->next = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}

//销毁链表  
int DestroyList(Node *head)  
{  
    Node *p;  
    if(head==NULL)  
        return 0;  
    while(head)  
    {  
        p=head->next;  
        free(head);  
        head=p;  
    }  
    return 1;  
}  
  
//清空链表  
int ClearList(Node *head)  
{  
    Node *p,*q;  
    if(head==NULL)  
        return 0;  
    p=head->next;  
    while(p!=NULL)  
    {  
        q=p->next;  
        free(p);  
        p=q;  
    }  
    head->next=NULL;  
    return 1;  
}  

//测试函数
int main () 
{
    Node *p = Create ();
    int a, b, c;
    printf("你想在第（）个位置，插入数字（）：");
    scanf("%d%d", &a, &b);
    insert(p, a, b);
    printf("\n");
    printf("你想删除第（）个位置的元素：");
    scanf("%d", &c);
    del(p, c);
    printf("\n");
    print(p);
    system("pause");
    printf("\n");
    p = reverse(p);
    print(p);
    system("pause");

    DestroyList(p);
    return 0;
}

