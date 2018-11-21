//
//  main.c
//  learning_c
//
//  Created by Admin on 2018/11/20.
//  Copyright © 2018 Qianwen Zhong. All rights reserved.
//

#include <stdio.h>

int main() {
    int z=10;
    int a[10];
    int *p=a;
    int *q=&a[5];
    int *h=&z;
    printf("p=%c\n,q=%c\n",p,q);
    printf("z=%c\n",z);
    return 0;
}
