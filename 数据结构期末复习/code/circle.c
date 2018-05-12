#include<stdio.h>
#include<malloc.h>

typedef int ElemType;
typedef struct LNode 
{	ElemType data;
  struct LNode  *next;
}LNode, *LinkList;

void InsertAtTail(LinkList &L,int m,ElemType b[])
//β�巨����������m��Ԫ�ص�ֵ��������ͷ���ĵ�����Lb
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
//ͷ�巨����������n��Ԫ�ص�ֵ��������ͷ���ĵ�����La
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
//�ϲ�La��Lb,�õ�Lc
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

//��ʾ��������Ԫ��
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

//������͵�����
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
//ɾ��������ֵΪ����������Ԫ��
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

	/*printf("\n������La��Ԫ�ظ���n:");
	scanf("%d",&n);
	printf("\n������%d����������:",n);
	a=(ElemType *)malloc(n*sizeof(ElemType));
	if(!a)
		exit(0);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);*/
	printf("ͷ�巨������������La...\n");
	InsertAtHead(La,n,a);
	printf("�����ʾ������La:\n");
	PrintList(La);

/*	printf("\n������Lb��Ԫ�ظ���m:");
	scanf("%d",&m);
	printf("\n������%d����������:",m);
	b=(ElemType *)malloc(m*sizeof(ElemType));
	if(!b)
		exit(0);
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);*/
	printf("β�巨������������Lb...\n");
	InsertAtTail(Lb,m,b);
	printf("�����ʾ������Lb:\n");
	PrintList(Lb);

	printf("��������La�͵�����...\n");
	ReverseList(La);
	printf("�����ʾ������La:\n");
	PrintList(La);

	printf("�ϲ���������La��Lb,�õ�Lc...\n");
	MergeList(La,Lb,Lc);
	printf("�����ʾ������Lc:\n");
	PrintList(Lc);

	printf("ɾ����������Lc��������ֵΪ����������Ԫ��...\n");
	DelOdd(Lc);
	printf("�����ʾ������Lc:\n");
	PrintList(Lc);

    getchar();
}