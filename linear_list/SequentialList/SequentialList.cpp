#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100 //���Ա���ռ�ĳ�ʼ������
#define LISTINCREMENT 10 //���Ա�ķ�����
typedef int ElemType;
typedef struct {
    ElemType *elem;  // ����ռ�Ļ���ַ
    int length;  //��ǰ���Ա�ĳ���
    int listsize; //��ǰ����Ĵ�������
}SqList;

//�������Ա�
int InitList (SqList &L) {
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) {
        return -1;  //�ռ����ʧ��
    }

    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 0;
}

//����Ԫ��
int LocateElem (SqList L, ElemType x) {
    int pos = -1;
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == x) {
            pos = i;
        }    
    }
    return pos;
}

//����Ԫ��
//ʱ�临�Ӷ�O(L.length)����O(n)
int ListInsert (SqList &L, int i, ElemType e) {
    //�жϲ���λ�õĺϷ���
    if (i < 1 || i > L.length + 1)
        return -1;
    //�жϴ���ռ��Ƿ���
    if (L.length >= L.listsize) {
        ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
        if (!newbase)
            return -1;  //����ռ����ʧ��
        L.elem = newbase; //�»�ַ
        L.listsize += LISTINCREMENT; //���Ӵ�������
    }
    //�������
    ElemType *q, *p; //��������ָ�����
    q = &(L.elem[i-1]); //qΪ����λ��(�β�i����ţ���Ŵ�1��ʼ�����±��0��ʼ���������ת�����±����i-1)
    //��ai��an-1���κ��ƣ�ע����Ʋ�����forѭ���ǴӺ���ǰ����
    for (p = &(L.elem[L.length - 1]); p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = e;
    ++L.length; //��+1
    return 0;
}

//ɾ��Ԫ��
//ʱ�临�Ӷ�O(L.length)����O(n)
int ListDelete (SqList &L, int i, ElemType &e) {
    //�ж�ɾ��λ�õĺϷ��ԡ�
    if (i < 1 || i > L.length)
        return -1;
    //ɾ������
    ElemType *q, *p; //����2��ָ�����
    p = &(L.elem[i-1]); //pΪ��ɾ��Ԫ�ص�λ��
    e = *p; //��ɾ��Ԫ�ظ�ֵ��e
    q = L.elem + L.length -1; //qָ���β���һ��Ԫ�أ�q�����һ��Ԫ�صĵ�ַ��
    //��p����һ��Ԫ�ؿ�ʼ����ǰ��
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    --L.length; //��-1
    return 0;
}

//���Դ���
int main()
{
    SqList list;
    InitList(list);
    int n = 30;
    //���10�����ָ����Ա�list
    for (int i = 0; i < 10; i++) {
        ListInsert(list, i + 1, i + 1);
    }
    //ɾ����5��
    ElemType e;
    ListDelete(list, 5, e);
    printf("ɾ����Ԫ���ǣ�%d\n",e);

    //�ڵ�2��λ�ò���һ��Ԫ��-1
    ListInsert(list, 2, -1);

    //������Ա�
    printf ("����������Ա�Ϊ��");
    for (int i = 0; i < 10; i++) {
        printf ("%d ", list.elem[i]);
    }
    //����Ľ���ǣ�1 -1 2 3 4 6 7 8 9 10
    getchar(); //��ͣ

    return 0;
}