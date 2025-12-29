#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_middle()
{
    struct node *newnode, *temp;
    int x, pos, i;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    printf("Enter position: ");
    scanf("%d", &pos);

    newnode->data = x;

    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\n");
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delete_middle()
{
    struct node *temp, *prev;
    int pos, i;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    temp = head;
    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
    }
    else
    {
        prev->next = temp->next;
        free(temp);
    }
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int ch;
    do
    {
        printf("\n1.Insert Middle\n2.Delete Middle\n3.Display\n4.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: insert_middle(); break;
        case 2: delete_middle(); break;
        case 3: display(); break;
        case 4: break;
        default: printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}