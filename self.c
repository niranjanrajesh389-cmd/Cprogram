 #include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *n1, *n2;

    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));

    n1->data = 100;
    n1->next = n2;

    n2->data = 2000;
    n2->next = NULL;

    printf("%d %d", n1->data, n1->next->data);

    return 0;
}