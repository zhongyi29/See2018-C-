//
// Created by Admin on 2018/11/13.
//
#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /*存储空间初始分配量*/

typedef int Status;
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

void ListTraverse(SqList L)
{
    int i=0;
    for ( i = 0; i < L.length; i++) {
        printf("%d",L.data[i]);
    printf("\n");
    }
}

void ClearList(SqList *L)
{
    L->length=0;
}

int ListLength(SqList L)
{
    return L.length;
}

Status ListEmpty(SqList L)
{
    if(L.length==0)
        return TRUE;
    else
        return FALSE;
}

Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length-1<i || i<0)
        return ERROR;
    else
    {
        *e=L.data[i];
        return OK;
    }
}

int LocateElem(SqList L,ElemType e)
{
    int i =0;
    for(i=0;i<L.length;i++)
    {
        if(L.data[i]==e)
            return i;
    }
    return ERROR;
}

Status ListInsert(SqList *L,int i,ElemType e)
{
    int j=0 ;
    if(i>L->length || i<0 || L->length==MAXSIZE)
        return ERROR;
    else
    {
        for(j=L->length-1;j>=i;j--)
            L->data[j+1] = L->data[j];
        L->data[i] = e;
        return OK;
    }
}

Status ListDelete(SqList *L,int i,ElemType *e)
{
    int j=0;
    if(i>L->length-1 || i<0)
        return ERROR;
    else
    {
        *e=L->data[i];
        for(j=i+1;j<L->length-1;j++)
            L->data[j-1] = L->data[j];
        L->length = L->length-1;
        return OK;
    }
}

int main()
{
    SqList L;
    ElemType e;
    Status i;
    int j;
    
    L.length = 0;
    for(j=1;j<=5;j++)
    {
        i = ListInsert(&L, 1, j);
    }
    printf("在L的表头依此插入1～5后，L.data=");
    ListTraverse(L);
    printf("L.length=%d\n",L.length);
    
    ClearList(&L);
    printf("清空L后：L.length=%d\n",L.length);
    
    for(j=1;j<=10;j++)
    {
        ListInsert(&L, 1, j);
    }
    printf("在L的表头依此插入1～10后，L.data=");
    ListTraverse(L);
    printf("L.length=%d\n",L.length);
    
    ListInsert(&L, 1, 0);
    printf("在L的表头依此插入0后，L.data=");
    ListTraverse(L);
    printf("L.length=%d\n",L.length);
    
    GetElem(L, 5, &e);
    printf("第5个元素的值为：%d\n",e);
    
    j=5;
    ListDelete(&L, j, &e);
    printf("删除L的第5个元素后：L.data=");
    ListTraverse(L);
    
    return 0;
}
