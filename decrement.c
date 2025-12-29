#include<stdio.h>
void main()
{
    int a,pre,post;
    a=999;
    printf("The value of a is %d\n",a);
    pre=--a;
    printf("Pre decrement value of a %d\n",pre);
    post=a--;
    printf("Post decrement value of a %d\n",post);
    printf("Final value of a is %d\n",a); 
}