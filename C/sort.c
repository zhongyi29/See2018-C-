//
//  sort.c
//  See2018
//
//  Created by Admin on 2018/11/13.
//  Copyright © 2018 钟倩文zhongqianwen. All rights reserved.
//

#include "stdio.h"
#include "string.h"

#define OUTPUT_INTERMEDIATE_RESULT
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10000

typedef int Status; //把Status定义为int类型。在后续程序中使用Status类型，便于后期修改Status的类型。
typedef struct
{
    int r[MAXSIZE+1];
    int length;
}SqList; //定义了一个结构体名字叫SqList。它包含两个属性，r【】和length ，都是intx类型。

void swap(SqList *L,int i,int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
    
}

void print(SqList L)
{
    int i;
    for (i=1;i<(L.length);i++)
        printf("%d,",L.r[i]);
    printf("%d,",L.r[i]);
    printf("\n");
}

void Sort0 (SqList *L);
void Sort1 (SqList *L);
void Sort2 (SqList *L);
//void Sort3 (SqList *);
//void Sort4 (SqList *);
//void Sort5 (SqList *);

void Sort0 (SqList *L)
{
    int i,j;
    for(i=1 ;i<L->length ;i++){
        for(j=i+1 ;j<L->length ;j++){
            if(L->r[i] > L->r[j]){
                swap(L,i,j);
            }
        }
#ifdef OUTPUT_INTERMEDIATE_RESULT
        printf("\n第%d次排序后的结果:\n",i);
        print(*L);
#endif
    }
}

void Sort1 (SqList *L)
{
    int i,j;
    for(i=1;i<L->length;i++)
    {
        for(j=L->length-1;j>=i;j--) {
            if (L->r[j] > L->r[j + 1]) {
                swap(L, j, j+1);
            }
            
        }
        
#ifdef OUTPUT_INTERMEDIATE_RESULT
        printf("\n第%d次排序后的结果:\n",i);
        print( *L);
#endif
    }
}

void Sort2 (SqList *L)
{
    int i,j;
    Status flag=TRUE;
    for(i=1;i<L->length && flag;i++)
    {
        flag = FALSE;
        for(j=L->length;j>=i;j--)
        {
            if(L->r[j]>L->r[j+1])
            {
                swap(L,j,j+1);
                flag = TRUE;
            }
        }
    }
}
int main(){
    int i,j,N;
    SqList list;
    
    while (1)
    {
        printf("\n\n请输入乱序数串的长度\n");
        scanf("%d",&N);
        for ( i = 0; i < N; i++)
        {
            printf("请输入乱序数串中第%d个数\n",i+1);
            scanf("%d",&list.r[i+1]);
            
        }
        list.length=N;
        
        if(N>0)
        {
            printf("\n\n排序前：\n");
            print(list);
            
            printf("\n\n请选择排序算法\n");
            printf("0为基本排序\n");
            printf("1为冒泡排序\n");
            printf("2为带判停条件的冒泡排序\n");
//            printf("3为选择排序\n");
//            printf("4为希尔排序\n");
//            printf("5为快速排序\n");
            printf("其他，退出\n");
            scanf("%d",&j);
            
            switch (j)
            {
                case 0:
                    Sort0(&list);
                    printf("基本排序：\n");
                    print(list);
                    break;
                case 1:
                    Sort1(&list);
                    printf("冒泡排序：\n");
                    print(list);
                    break;
                case 2:
                    Sort2(&list);
                    printf("带判停条件的冒泡排序\n");
                    print(list);
                    break;
//                case 3:
//                    Sort3(&list);
//                    printf("选择排序\n");
//                    print(list);
//                    break;
//                case 4:
//                    Sort4(&list);
//                    printf("希尔排序\n");
//                    print(list);
//                    break;
//                case 5:
//                    Sort5(&list);
//                    printf("快速排序\n");
//                    print(list);
//                    break;
                default:
                    printf("无此类排序算法\n");
                    return 0;
            }
        }
        else
        {
            printf("乱序数串长度为0\n");
        }
    }
}

