// swapping two numbers using a third variable 

#include<stdio.h>
int main()
{
    // a=10 , b=20 
    // a=20 , b=10 

    int a,b,temp;
    printf("enter two numbers:");
    scanf("%d%d" ,&a,&b);

    temp=a;
    a=b;
    b=temp;
    printf("%d %d" ,a,b);
    return 0;
}