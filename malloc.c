#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a, *b, i, n = 4;

    a = (int *)malloc(n * sizeof(int));
    b = (int *)calloc(n, sizeof(int));

    printf("malloc values:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\ncalloc values:\n");
    for (i = 0; i < n; i++)
        printf("%d ", b[i]);

    free(a);
    free(b);

    return 0;
}