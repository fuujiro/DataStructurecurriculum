#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; //������
    struct Node *next; //ָ����
};

/*
Create
*�������ܣ���������.
*���룺���ڵ��data
*����ֵ��ָ��head
*/
Node *Create () {
    Node *p, *pl, * head;  
    head = p = (Node *)malloc(sizeof(Node));  
    scanf("%d", &p->data);/*ͷ�������ݳ�Ա*/  
    /*����0��������,�˳�ѭ��*/  
    while(p->data != 0) {    
        pl = p;  
        p = (Node *)malloc(sizeof(Node));  
        scanf("%d", &p->data);/*�м������ݳ�Ա*/  
        pl->next = p;/*�м����ָ���Աֵ*/  
    }  
    p-> next = NULL;/*β����ָ���Աֵ*/  
    return head;
}

/*
insert
*�������ܣ��������в���Ԫ��.
*���룺head����ͷָ�룬p��Ԫ�ز���λ�ã�x��Ԫ���е�����������
*����ֵ����
*/
void insert (Node *head, int p, int x) {
    Node *tmp = head; 
    //forѭ����Ϊ�˷�ֹ����λ�ó������ض�����
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
*�������ܣ�ɾ�������е�Ԫ��
*���룺head����ͷָ�룬p��ɾ��Ԫ��λ��
*����ֵ����ɾ��Ԫ���е�������.���ɾ��ʧ�ܷ���-1
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
    int ret = tmp->next->data; //���汻ɾ��Ԫ�ص�ֵ
    s = tmp->next;
    tmp->next = tmp->next->next;
    free(s);
    return ret;
}

/*
print
*�������ܣ���ӡ
*���룺head����ͷָ��
*����ֵ����
*/
void print (Node *head) { 
    while (head->next != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//������
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

//��������  
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
  
//�������  
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

//���Ժ���
int main () 
{
    Node *p = Create ();
    int a, b, c;
    printf("�����ڵڣ�����λ�ã��������֣�����");
    scanf("%d%d", &a, &b);
    insert(p, a, b);
    printf("\n");
    printf("����ɾ���ڣ�����λ�õ�Ԫ�أ�");
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

