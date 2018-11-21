//
//  Stack.c
//  Stack
//
//  Created by Admin on 2018/11/20.
//  Copyright © 2018 Qianwen Zhong. All rights reserved.
//

#include "stdio.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int SElemType;

typedef struct
{
    SElemType data[MAXSIZE];
    int top;
}SqStack;

void StackTraverse(SqStack S)
{
    int i;
    i = 0;
    while (i<S.top) {
        printf("%d",S.data[i++]);
    }
    printf("\n");
}

void ClearStack(SqStack *S)
{
    S->top = -1;
}

Status StackEmpty(SqStack S)
{
    if(S.top==-1)
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack S)
{
    return S.top+1;
}


Status GetTop(SqStack S,SElemType *e)
{
    if(S.top == -1)
        return ERROR;
    else{
        *e=S.data[S.top];
        return OK;
    }
}

Status Push(SqStack *S,SElemType e)
{
    if(S->top == MAXSIZE)
        return ERROR;
    else{
        S->top++;
        S->data[S->top]=e;
        return OK;
    }
}

Status Pop(SqStack *S,SElemType *e)
{
    if(S->top == -1)
        return ERROR;
    else{
        *e=S->data[S->top];
        S->top--;
        return OK;
    }
}

Status CalculatingRPN(char* rpn, int* result)
{
    int i ,length;
    length = int(strlen(rpn));
    for(i=0;i<length;i++){
        if(char[i]==)
    }
}


int main(int argc, const char * argv[])
{
    
    return 0;
}

