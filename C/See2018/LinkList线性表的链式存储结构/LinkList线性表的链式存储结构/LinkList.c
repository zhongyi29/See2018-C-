//
//  LinkList.c
//  LinkList线性表的链式存储结构
//
//  Created by Admin on 2018/11/13.
//  Copyright © 2018 Qianwen Zhong. All rights reserved.
//


#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

void ListTraverse(LinkList L)
{
    LinkList p=L->next;
    
    while (p) {
        printf("%d",p->data);
        p = p->next;
    }
    printf("\n");
}

void ClearList(LinkList *L)
{
    LinkList p,q;
    p = (*L)->next;
    
    while (p) {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
}

Status InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    if(!(*L))
        return ERROR;
    (*L)->next=NULL;
    
    return OK;
}

Status ListEmpty(LinkList L)
{
    if(L->next)
        return FALSE;
    else
        return TRUE;
}

int ListLength(LinkList L)
{
    int length = 0;
    LinkList p =L->next;
    while (p) {
        length++;
        p=p->next;
    }
    return length;
}

Status GetElem(LinkList L,int i,ElemType *e)
{
    int length = ListLength(L);
    LinkList p=L->next;
    int j = 1;
    if(length<i)
        return ERROR;
    else{
        for(j=1;j<i;j++)
            p=p->next;
        *e = p->data;
        return OK;
    }
}

int LocateElem(LinkList L,ElemType e)
{
    int length = ListLength(L);
    LinkList p = L->next;
    int j = 1;
    for(j=1;j<=length;j++){
        if (p->data == e)
            return j;
        else
            p=p->next;
    }
    return ERROR;
}
Status ListInsert(LinkList *L,int i,ElemType e)
{
    LinkList p=(*L)->next;
    LinkList s;
    int j =1 ;
    int length = ListLength(*L);
    if(i-1>length || i<1)
        return ERROR;
    else{
        for(j=1;j<i;j++)
            p=p->next;
        s = p->next;
        s = s->next;
        p->next = s;
        return OK;
    }
}

Status ListDelete(LinkList *L,int i,ElemType *e)  //在插入删除操作的时候需要在内存处理，所以用指针传入
{
    int length = ListLength(*L);
    int j =1;
    LinkList p = (*L)->next;
    LinkList q;
    if(i>length || i<1)
        return ERROR;
    else{
        for(j=1;j<i;j++)
            p=p->next;
        q=p->next;
        *e=q->data;
        p->next = q->next;
        free(q);
        return OK;
    }
    
}
int main()
{
    LinkList L;  //这里在定义一个L， 在用指针时 &L
    ElemType e;
    Status i;
    int j,k;
    
    i=InitList(&L);
    if(i==ERROR)
        return 0;
    for (j=1; j<=5; j++)
        i=ListInsert(&L, 1, j);
    printf("在L的表头依此插入1～5后:L.data=");
    ListTraverse(L);
    
    printf("ListLength(L)=%d\n",ListLength(L));
    
    ClearList(&L);
    printf("\n清空L后:ListLength(L)=%d\n",ListLength(L));
    
    for (j=1; j<=0; j++)
        ListInsert(&L, j, j);
    printf("\n在L的表尾依此插入1～10后:L.data=");
    ListTraverse(L);
    
    printf("ListLength(L)=%d\n",ListLength(L));
    
    ListInsert(&L, 1, 0);
    printf("\n在L的表头插入0后:L.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d\n",ListLength(L));
    
    GetElem(L, 5, &e);
    printf("\n第5个元素的值为:%d\n",e);
    
    printf("\n");
    for (j=3; j<=4; j++) {
        k = LocateElem(L,j);
        if (k)
            printf("值为%d的元素在第%d个位置\n",j,k);
        else
            printf("没有值为%d的元素\n",j);
    }
    
    printf("\n");
    k=ListLength(L);
    for(j=k+1;j>=k;j--)
    {
        i=ListDelete(&L, j, &e);
        if(i==ERROR)
            printf("删除第%d个数据失败\n",j);
        else
            printf("删除的第个%d元素的值为%d后:L.data=",j,e);
    }
    ListTraverse(L);
    printf("ListLength(L)=%d\n",ListLength(L));
    
    return 0;
}


