#include <stdio.h>

int main()
{
    int a = 100;
    int *p;

    p = &a;

    printf("Value of a = %d\n", a);
    printf("Address of a = %p\n", &a);
    printf("Value stored in pointer p (address of a) = %p\n", p);
    printf("Address of pointer p = %p\n", &p);

    return 0;
}