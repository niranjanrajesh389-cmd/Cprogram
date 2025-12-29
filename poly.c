#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int pow;
    struct node *next;
};

struct node *head = NULL;

void insert(int c, int p)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = c;
    newnode->pow = p;
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->pow);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int n, c, p, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &c, &p);
        insert(c, p);
    }

    display();
    return 0;
}