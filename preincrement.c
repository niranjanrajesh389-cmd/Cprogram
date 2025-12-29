#include<stdio.h>
void main()
{
    int a,prein,postin;
    a=100;
    printf("The value of a is %d\n",a);
    prein=++a;
    printf("Pre increment value of a %d\n",prein);
    postin=a++;
    printf("Post increment value of a %d\n",postin);
    printf("Final value of a is %d\n",a); 
}