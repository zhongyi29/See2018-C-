//
//  main.c
//  Hanoi
//
//  Created by Admin on 2018/11/15.
//  Copyright © 2018 Qianwen Zhong. All rights reserved.
//
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

#define OK 1
#define ERROR 0

#define MAXSIZE 40

typedef int Status;
typedef char String[MAXSIZE+1];

Status StrAssign(String T,char *chars)
{
    int i;
    if(strlen(chars)>MAXSIZE)
        return ERROR;
    else
    {
        T[0]=strlen(chars);
        for(i=1;i<T[0];i++)
            T[i]=*(chars+i-1);
        return OK;
        
    }
}

void StrPrint(String T)
{
    int i ;
    for (i=1; i<=T[0]; i++)
    {
        printf("%c",T[i]);
    }
}

static int step =0;

void transfer(int n,String srcPole,String destPole)
{
    printf("将碟片(%d)从",n);
    StrPrint(srcPole);
    printf("移动到");
    StrPrint(destPole);
    printf("\n");
    step++;
}

void Hanoi(int n,String srcPole,String temPole,String destPole)
{
    if (n<1)
        ;
    
    else if (n==1)
        transfer(1, srcPole, destPole);
    else{
        Hanoi(n-1,srcPole,destPole,temPole);
        transfer(n, srcPole, destPole);
        Hanoi(n-1, temPole,srcPole, destPole);
    }
    
    
}

int main()
{
    int n;
    String poleFanTian,polePiShiNu,poleShiPo;
    
    StrAssign(poleFanTian, "Brahma");
    StrAssign(polePiShiNu, "Vishnou");
    StrAssign(poleShiPo, "shiva");
    
    printf("输入层数n:");
    scanf("%d",&n);
    
    Hanoi(n, poleFanTian, polePiShiNu, polePiShiNu);
    printf("移完%d层汉诺塔所用总步数为%d\n",n,step);
    
    return 0;
}

