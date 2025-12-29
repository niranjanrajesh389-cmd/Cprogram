#include <stdio.h>

int tree[50];

int main()
{
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter tree elements:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &tree[i]);

    printf("Tree elements are:\n");
    for (i = 1; i <= n; i++)
        printf("%d ", tree[i]);
}