#include<stdio.h>
#include<malloc.h>

typedef int ElemType;
typedef struct LNode 
{	ElemType data;
  struct LNode  *next;
}LNode, *LinkList;

void InsertAtTail(LinkList &L,int m,ElemType b[])
//尾插法：升序输入m个元素的值，建立带头结点的单链表Lb
{	LNode *p,*rear;  
	int i;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    rear=L;
	for(i=0;i<m;i++)
	{	
        p=(LinkList)malloc(sizeof(LNode));
        p->data=b[i];
        rear->next=p;
        rear=p;
    }
	rear->next=NULL;
}

void InsertAtHead(LinkList &L,int n,ElemType a[])
//头插法：升序输入n个元素的值，建立带头结点的单链表La
{ LNode *p;
	int i;
	L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    for(i=0;i<n;i++)
    {	
        p=(LinkList)malloc(sizeof(LNode));
        p->data=a[i];
        p->next=L->next;
        L->next=p;
    }
}
//合并La和Lb,得到Lc
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc) 
{	LNode *pa,*pb,*pc;
    pa = La->next;
	pb = Lb->next;
    Lc = pc =La;
    while ( pa && pb) 
    {	
        if (pa->data <= pb->data)  
		{	pc->next = pa; pc = pa; pa = pa->next;   }
		else
		{   pc->next = pb; pc = pb; pb = pb->next;   }
    }
    pc->next = pa?pa:pb;
    free(Lb);
}

//显示单链表中元素
void PrintList(LinkList L) 
{	LNode * p;	
	p=L->next;
	printf("H");
	while(p)
	{	printf("->%d",p->data);
		p=p->next;
	}	
	printf("\n\n");
}

//单链表就地逆置
void ReverseList(LinkList &L)
{	LNode *p, *q;
  p=L->next;
  L->next=NULL;
  while (p != NULL)
  {  
		q=p->next;
    p->next=L->next;
    L->next=p;
    p=q;
   }
}
//删除数据域值为奇数的所有元素
void DelOdd(LinkList &L)
{	
    LNode *p,*pre;
	pre=L;
	p=L->next;
	while(p)
	{	if(p->data%2==1)
		{	pre->next=p->next;
			free(p);
			p=pre->next;
		}
		else
		{	pre=p;
			p=p->next;
		}
	}
}

int main()
{
	LinkList La,Lb,Lc;
	//int n,m,i,*a,*b;
	int n=4,m=5,a[ ]={2,5,7,8},b[ ]={1,3,6,8,10};

	/*printf("\n请输入La表元素个数n:");
	scanf("%d",&n);
	printf("\n请输入%d个升序整数:",n);
	a=(ElemType *)malloc(n*sizeof(ElemType));
	if(!a)
		exit(0);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);*/
	printf("头插法建立有序单链表La...\n");
	InsertAtHead(La,n,a);
	printf("输出显示单链表La:\n");
	PrintList(La);

/*	printf("\n请输入Lb表元素个数m:");
	scanf("%d",&m);
	printf("\n请输入%d个升序整数:",m);
	b=(ElemType *)malloc(m*sizeof(ElemType));
	if(!b)
		exit(0);
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);*/
	printf("尾插法建立有序单链表Lb...\n");
	InsertAtTail(Lb,m,b);
	printf("输出显示单链表Lb:\n");
	PrintList(Lb);

	printf("有序单链表La就地逆置...\n");
	ReverseList(La);
	printf("输出显示单链表La:\n");
	PrintList(La);

	printf("合并有序单链表La和Lb,得到Lc...\n");
	MergeList(La,Lb,Lc);
	printf("输出显示单链表Lc:\n");
	PrintList(Lc);

	printf("删除有序单链表Lc中数据域值为奇数的所有元素...\n");
	DelOdd(Lc);
	printf("输出显示单链表Lc:\n");
	PrintList(Lc);

    getchar();
}