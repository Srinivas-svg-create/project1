#include<stdio.h>
int main()
{/*============
    x | y | ^
    1 | 1 | 0
    0 | 1 | 1
    1 | 0 | 1
    0 | 0 | 0
=================*/
    int x,y;
    scanf("%d/n%d",&x,&y);
    int z= x^y;
    printf("XOR of x^Y= %d",z);
    ////////
}