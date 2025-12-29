 #include <stdio.h>
#include <stdlib.h>

struct node
{
    int row, col, val;
    struct node *next;
};

struct node *head = NULL;

void insert(int r, int c, int v)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->row = r;
    newnode->col = c;
    newnode->val = v;
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void display()
{
    struct node *temp = head;
    printf("Non-zero elements:\n");
    while (temp != NULL)
    {
        printf("%d->%d->%d\t",temp->row,temp->col,temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int i, j, r = 3, c = 3, val;

    printf("Enter elements of %dx%d matrix:\n", r, c);
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &val);
            if (val != 0)
                insert(i, j, val);
        }
    }

    display();
    return 0;
}