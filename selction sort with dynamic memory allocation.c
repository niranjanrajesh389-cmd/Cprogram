#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, min, temp;
    int *a;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    if (a == NULL)
        return 0;

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    free(a);
}
