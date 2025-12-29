#include <stdio.h>
#include <stdlib.h>

struct node
{
    int r, c, v;
    struct node *next;
};

int main()
{
    int a[3][3], i, j;
    struct node *head = NULL, *temp, *newnode;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
            {
                newnode = (struct node *)malloc(sizeof(struct node));
                newnode->r = i;
                newnode->c = j;
                newnode->v = a[i][j];
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
        }
    }

    temp = head;
    printf("Row Col Value\n");
    while (temp != NULL)
    {
        printf("%d   %d   %d\n", temp->r, temp->c, temp->v);
        temp = temp->next;
    }

    return 0;
}