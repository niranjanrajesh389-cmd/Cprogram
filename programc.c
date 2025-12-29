 #include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, i, n = 9;

    p = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        p[i] = 0;

    for (i = 0; i < n; i++)
        printf("%d ", p[i]);

    free(p);
    return 0;
}