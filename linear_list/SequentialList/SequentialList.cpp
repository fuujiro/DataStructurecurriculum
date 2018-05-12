#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100 //线性表储存空间的初始分配量
#define LISTINCREMENT 10 //线性表的分配量
typedef int ElemType;
typedef struct {
    ElemType *elem;  // 储存空间的基地址
    int length;  //当前线性表的长度
    int listsize; //当前分配的储存容量
}SqList;

//创建线性表
int InitList (SqList &L) {
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) {
        return -1;  //空间分配失败
    }

    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 0;
}

//查找元素
int LocateElem (SqList L, ElemType x) {
    int pos = -1;
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == x) {
            pos = i;
        }    
    }
    return pos;
}

//插入元素
//时间复杂度O(L.length)，即O(n)
int ListInsert (SqList &L, int i, ElemType e) {
    //判断插入位置的合法性
    if (i < 1 || i > L.length + 1)
        return -1;
    //判断储存空间是否够用
    if (L.length >= L.listsize) {
        ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
        if (!newbase)
            return -1;  //储存空间分配失败
        L.elem = newbase; //新基址
        L.listsize += LISTINCREMENT; //增加储存容量
    }
    //插入操作
    ElemType *q, *p; //定义两个指针变量
    q = &(L.elem[i-1]); //q为插入位置(形参i是序号，序号从1开始，而下标从0开始，因此这里转换成下标后是i-1)
    //从ai到an-1依次后移，注意后移操作的for循环是从后往前进行
    for (p = &(L.elem[L.length - 1]); p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = e;
    ++L.length; //表长+1
    return 0;
}

//删除元素
//时间复杂度O(L.length)，即O(n)
int ListDelete (SqList &L, int i, ElemType &e) {
    //判断删除位置的合法性‘
    if (i < 1 || i > L.length)
        return -1;
    //删除操作
    ElemType *q, *p; //定义2个指针变量
    p = &(L.elem[i-1]); //p为被删除元素的位置
    e = *p; //被删除元素赋值给e
    q = L.elem + L.length -1; //q指向表尾最后一个元素（q是最后一个元素的地址）
    //从p的下一个元素开始依次前移
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    --L.length; //表长-1
    return 0;
}

//测试代码
int main()
{
    SqList list;
    InitList(list);
    int n = 30;
    //添加10个数字给线性表list
    for (int i = 0; i < 10; i++) {
        ListInsert(list, i + 1, i + 1);
    }
    //删除第5个
    ElemType e;
    ListDelete(list, 5, e);
    printf("删除的元素是：%d\n",e);

    //在第2个位置插入一个元素-1
    ListInsert(list, 2, -1);

    //输出线性表
    printf ("输出最后的线性表为：");
    for (int i = 0; i < 10; i++) {
        printf ("%d ", list.elem[i]);
    }
    //输出的结果是：1 -1 2 3 4 6 7 8 9 10
    getchar(); //暂停

    return 0;
}